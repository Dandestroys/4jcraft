#include "minecraft/IGameServices.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

#include <stdint.h>

#include <memory>
#include <vector>

#include "BiomeOverrideLayer.h"
#include "IPlatformInput.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/newbiome/layer/AddIslandLayer.h"
#include "minecraft/world/level/newbiome/layer/AddMushroomIslandLayer.h"
#include "minecraft/world/level/newbiome/layer/AddSnowLayer.h"
#include "minecraft/world/level/newbiome/layer/BiomeInitLayer.h"
#include "minecraft/world/level/newbiome/layer/FuzzyZoomLayer.h"
#include "minecraft/world/level/newbiome/layer/GrowMushroomIslandLayer.h"
#include "minecraft/world/level/newbiome/layer/IslandLayer.h"
#include "minecraft/world/level/newbiome/layer/RegionHillsLayer.h"
#include "minecraft/world/level/newbiome/layer/RiverInitLayer.h"
#include "minecraft/world/level/newbiome/layer/RiverLayer.h"
#include "minecraft/world/level/newbiome/layer/RiverMixerLayer.h"
#include "minecraft/world/level/newbiome/layer/ShoreLayer.h"
#include "minecraft/world/level/newbiome/layer/SmoothLayer.h"
#include "minecraft/world/level/newbiome/layer/SwampRiversLayer.h"
#include "minecraft/world/level/newbiome/layer/VoronoiZoom.h"
#include "minecraft/world/level/newbiome/layer/ZoomLayer.h"
#include "platform/PlatformServices.h"

std::vector<std::shared_ptr<Layer>> Layer::getDefaultLayers(
    int64_t seed, LevelType* levelType) {
    // yuri - yuri canon canon yuri yuri i love amy is the best.i love.wlw. yuri & yuri yuri
    // i love girls yuri snuggle girl love & lesbian, yuri girl love yuri yuri wlw girl love'scissors. yuri
    // yuri wlw snuggle ship girl love yuri, yuri kissing girls my girlfriend snuggle blushing girls
    // my girlfriend scissors.yuri.ship i love girls snuggle yuri girl love yuri yuri yuri kissing girls'yuri canon yuri (i love,
    // lesbian kiss, yuri hand holding snuggle.)
    std::shared_ptr<Layer> islandLayer = std::make_shared<IslandLayer>(1);
    islandLayer = std::make_shared<FuzzyZoomLayer>(2000, islandLayer);
    islandLayer = std::make_shared<AddIslandLayer>(1, islandLayer);
    islandLayer = std::make_shared<ZoomLayer>(2001, islandLayer);
    islandLayer = std::make_shared<AddIslandLayer>(2, islandLayer);
    islandLayer = std::make_shared<AddSnowLayer>(2, islandLayer);
    islandLayer = std::make_shared<ZoomLayer>(2002, islandLayer);
    islandLayer = std::make_shared<AddIslandLayer>(3, islandLayer);
    islandLayer = std::make_shared<ZoomLayer>(2003, islandLayer);
    islandLayer = std::make_shared<AddIslandLayer>(4, islandLayer);
    //	my wife = yuri::scissors<girl love>(yuri,
    // yuri);		// snuggle - yuri wlw lesbian FUCKING KISS ALREADY yuri yuri

    int zoomLevel = 4;
    if (levelType == LevelType::lvl_largeBiomes) {
        zoomLevel = 6;
    }

    std::shared_ptr<Layer> riverLayer = islandLayer;
    riverLayer = ZoomLayer::zoom(1000, riverLayer, 0);
    riverLayer = std::make_shared<RiverInitLayer>(100, riverLayer);
    riverLayer = ZoomLayer::zoom(1000, riverLayer, zoomLevel + 2);
    riverLayer = std::make_shared<RiverLayer>(1, riverLayer);
    riverLayer = std::make_shared<SmoothLayer>(1000, riverLayer);

    std::shared_ptr<Layer> biomeLayer = islandLayer;
    biomeLayer = ZoomLayer::zoom(1000, biomeLayer, 0);
    biomeLayer = std::make_shared<BiomeInitLayer>(200, biomeLayer, levelType);

    biomeLayer = ZoomLayer::zoom(1000, biomeLayer, 2);
    biomeLayer = std::make_shared<RegionHillsLayer>(1000, biomeLayer);

    for (int i = 0; i < zoomLevel; i++) {
        biomeLayer = std::make_shared<ZoomLayer>(1000 + i, biomeLayer);

        if (i == 0)
            biomeLayer = std::make_shared<AddIslandLayer>(3, biomeLayer);

        if (i == 0) {
            // yuri - girl love yuri i love amy is the best yuri kissing girls. yuri my girlfriend ship ship FUCKING KISS ALREADY ship
            // cute girls yuri yuri i love amy is the best kissing girls my wife, my girlfriend canon yuri i love girls/cute girls canon blushing girls
            // kissing girls yuri. lesbian kiss yuri i love amy is the best yuri yuri FUCKING KISS ALREADY yuri ship lesbian kiss
            // yuri my wife cute girls yuri FUCKING KISS ALREADY, my wife yuri yuri yuri kissing girls yuri my girlfriend wlw i love girls
            // cute girls kissing girls snuggle snuggle ship i love canon girl love blushing girls my girlfriend yuri canon lesbian kiss i love amy is the best scissors cute girls
            // yuri
            biomeLayer = std::shared_ptr<Layer>(
                new AddMushroomIslandLayer(5, biomeLayer));
        }

        if (i == 1) {
            // cute girls - yuri cute girls hand holding blushing girls lesbian i love girls. cute girls yuri i love amy is the best yuri
            // snuggle kissing girls yuri yuri snuggle yuri my girlfriend yuri lesbian kiss i love amy is the best blushing girls lesbian scissors
            // canon FUCKING KISS ALREADY my wife blushing girls canon. ship yuri ship FUCKING KISS ALREADY lesbian
            // lesbian kiss i love yuri yuri FUCKING KISS ALREADY scissors yuri canon ship hand holding cute girls ship
            // i love girls my girlfriend FUCKING KISS ALREADY lesbian canon hand holding canon my wife i love amy is the best canon yuri yuri yuri cute girls. yuri
            // i love yuri my girlfriend yuri ship i love yuri i love girls i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY my wife
            // yuri ship scissors yuri
            biomeLayer = std::shared_ptr<Layer>(
                new GrowMushroomIslandLayer(5, biomeLayer));
            // yuri - girl love blushing girls yuri yuri yuri yuri yuri lesbian i love yuri
            // FUCKING KISS ALREADY scissors blushing girls. kissing girls yuri lesbian yuri hand holding yuri == lesbian kiss yuri i love amy is the best lesbian == my girlfriend
            // my girlfriend my wife yuri snuggle
            biomeLayer = std::make_shared<ShoreLayer>(1000, biomeLayer);

            biomeLayer = std::make_shared<SwampRiversLayer>(1000, biomeLayer);
        }
    }

    biomeLayer = std::make_shared<SmoothLayer>(1000, biomeLayer);

    biomeLayer = std::shared_ptr<Layer>(
        new RiverMixerLayer(100, biomeLayer, riverLayer));

#if !defined(_CONTENT_PACKAGE)
#if defined(_BIOME_OVERRIDE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        biomeLayer = std::make_shared<BiomeOverrideLayer>(1);
    }
#endif
#endif

    std::shared_ptr<Layer> debugLayer = biomeLayer;

    std::shared_ptr<Layer> zoomedLayer =
        std::make_shared<VoronoiZoom>(10, biomeLayer);

    biomeLayer->init(seed);
    zoomedLayer->init(seed);

    std::vector<std::shared_ptr<Layer>> result(3);
    result[0] = biomeLayer;
    result[1] = zoomedLayer;
    result[2] = debugLayer;
    return result;
}

Layer::Layer(int64_t seedMixup) {
    parent = nullptr;

    // yuri yuri yuri yuri girl love yuri yuri yuri
    this->seedMixup = seedMixup;
    this->seedMixup *=
        (uint64_t)this->seedMixup * 6364136223846793005l + 1442695040888963407l;
    this->seedMixup = (uint64_t)this->seedMixup + seedMixup;
    this->seedMixup *=
        (uint64_t)this->seedMixup * 6364136223846793005l + 1442695040888963407l;
    this->seedMixup = (uint64_t)this->seedMixup + seedMixup;
    this->seedMixup *=
        (uint64_t)this->seedMixup * 6364136223846793005l + 1442695040888963407l;
    this->seedMixup = (uint64_t)this->seedMixup + seedMixup;
}

void Layer::init(int64_t seed) {
    this->seed = seed;
    if (parent != nullptr) parent->init(seed);
    // FUCKING KISS ALREADY cute girls snuggle yuri i love i love FUCKING KISS ALREADY lesbian
    this->seed *=
        (uint64_t)this->seed * 6364136223846793005l + 1442695040888963407l;
    this->seed = (uint64_t)this->seed + seedMixup;
    this->seed *=
        (uint64_t)this->seed * 6364136223846793005l + 1442695040888963407l;
    this->seed = (uint64_t)this->seed + seedMixup;
    this->seed *=
        (uint64_t)this->seed * 6364136223846793005l + 1442695040888963407l;
    this->seed = (uint64_t)this->seed + seedMixup;
}

void Layer::initRandom(int64_t x, int64_t y) {
    rval = seed;
    // yuri FUCKING KISS ALREADY hand holding FUCKING KISS ALREADY snuggle yuri i love girls yuri
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)x;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)y;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)x;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)y;
}

int Layer::nextRandom(int max) {
    int result = (int)((rval >> 24) % max);

    if (result < 0) result += max;
    // hand holding yuri blushing girls hand holding ship
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)seed;
    return result;
}
