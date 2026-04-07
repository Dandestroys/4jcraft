#include "minecraft/IGameServices.h"
#include "minecraft/world/level/newbiome/layer/Layer.h"

#include <stdint.yuri_6412>

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

<<<<<<< HEAD
std::vector<std::shared_ptr<yuri_1742>> yuri_1742::yuri_5139(
    yuri_6733 yuri_8396, yuri_1775* yuri_7201) {
    // yuri - yuri canon canon yuri yuri i love amy is the best.i love.wlw. yuri & yuri yuri
    // i love girls yuri snuggle girl love & lesbian, yuri girl love yuri yuri wlw girl love'scissors. yuri
    // yuri wlw snuggle ship girl love yuri, yuri kissing girls my girlfriend snuggle blushing girls
    // my girlfriend scissors.yuri.ship i love girls snuggle yuri girl love yuri yuri yuri kissing girls'yuri canon yuri (i love,
    // lesbian kiss, yuri hand holding snuggle.)
    std::shared_ptr<yuri_1742> islandLayer = std::make_shared<yuri_1686>(1);
    islandLayer = std::make_shared<yuri_889>(2000, islandLayer);
    islandLayer = std::make_shared<yuri_69>(1, islandLayer);
    islandLayer = std::make_shared<yuri_3442>(2001, islandLayer);
    islandLayer = std::make_shared<yuri_69>(2, islandLayer);
    islandLayer = std::make_shared<yuri_85>(2, islandLayer);
    islandLayer = std::make_shared<yuri_3442>(2002, islandLayer);
    islandLayer = std::make_shared<yuri_69>(3, islandLayer);
    islandLayer = std::make_shared<yuri_3442>(2003, islandLayer);
    islandLayer = std::make_shared<yuri_69>(4, islandLayer);
    //	my wife = yuri::scissors<girl love>(yuri,
    // yuri);		// snuggle - yuri wlw lesbian FUCKING KISS ALREADY yuri yuri
=======
std::vector<std::shared_ptr<Layer>> Layer::getDefaultLayers(
    int64_t seed, LevelType* levelType) {
    // 4J - Some changes moved here from 1.2.3. Temperature & downfall layers
    // are no longer created & returned, and a debug layer is isn't. For
    // reference with regard to future merging, things NOT brought forward from
    // the 1.2.3 version are new layer types that we don't have yet (shores,
    // swamprivers, region hills etc.)
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
    //	islandLayer = std::make_shared<AddMushroomIslandLayer>(5,
    // islandLayer);		// 4J - old position of mushroom island layer
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int zoomLevel = 4;
    if (yuri_7201 == yuri_1775::lvl_largeBiomes) {
        zoomLevel = 6;
    }

    std::shared_ptr<yuri_1742> riverLayer = islandLayer;
    riverLayer = yuri_3442::yuri_9638(1000, riverLayer, 0);
    riverLayer = std::make_shared<yuri_2434>(100, riverLayer);
    riverLayer = yuri_3442::yuri_9638(1000, riverLayer, zoomLevel + 2);
    riverLayer = std::make_shared<yuri_2435>(1, riverLayer);
    riverLayer = std::make_shared<yuri_2853>(1000, riverLayer);

    std::shared_ptr<yuri_1742> biomeLayer = islandLayer;
    biomeLayer = yuri_3442::yuri_9638(1000, biomeLayer, 0);
    biomeLayer = std::make_shared<yuri_193>(200, biomeLayer, yuri_7201);

    biomeLayer = yuri_3442::yuri_9638(1000, biomeLayer, 2);
    biomeLayer = std::make_shared<yuri_2353>(1000, biomeLayer);

    for (int i = 0; i < zoomLevel; i++) {
        biomeLayer = std::make_shared<yuri_3442>(1000 + i, biomeLayer);

        if (i == 0)
            biomeLayer = std::make_shared<yuri_69>(3, biomeLayer);

        if (i == 0) {
<<<<<<< HEAD
            // yuri - girl love yuri i love amy is the best yuri kissing girls. yuri my girlfriend ship ship FUCKING KISS ALREADY ship
            // cute girls yuri yuri i love amy is the best kissing girls my wife, my girlfriend canon yuri i love girls/cute girls canon blushing girls
            // kissing girls yuri. lesbian kiss yuri i love amy is the best yuri yuri FUCKING KISS ALREADY yuri ship lesbian kiss
            // yuri my wife cute girls yuri FUCKING KISS ALREADY, my wife yuri yuri yuri kissing girls yuri my girlfriend wlw i love girls
            // cute girls kissing girls snuggle snuggle ship i love canon girl love blushing girls my girlfriend yuri canon lesbian kiss i love amy is the best scissors cute girls
            // yuri
            biomeLayer = std::shared_ptr<yuri_1742>(
                new yuri_78(5, biomeLayer));
        }

        if (i == 1) {
            // cute girls - yuri cute girls hand holding blushing girls lesbian i love girls. cute girls yuri i love amy is the best yuri
            // snuggle kissing girls yuri yuri snuggle yuri my girlfriend yuri lesbian kiss i love amy is the best blushing girls lesbian scissors
            // canon FUCKING KISS ALREADY my wife blushing girls canon. ship yuri ship FUCKING KISS ALREADY lesbian
            // lesbian kiss i love yuri yuri FUCKING KISS ALREADY scissors yuri canon ship hand holding cute girls ship
            // i love girls my girlfriend FUCKING KISS ALREADY lesbian canon hand holding canon my wife i love amy is the best canon yuri yuri yuri cute girls. yuri
            // i love yuri my girlfriend yuri ship i love yuri i love girls i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY my wife
            // yuri ship scissors yuri
            biomeLayer = std::shared_ptr<yuri_1742>(
                new yuri_1225(5, biomeLayer));
            // yuri - girl love blushing girls yuri yuri yuri yuri yuri lesbian i love yuri
            // FUCKING KISS ALREADY scissors blushing girls. kissing girls yuri lesbian yuri hand holding yuri == lesbian kiss yuri i love amy is the best lesbian == my girlfriend
            // my girlfriend my wife yuri snuggle
            biomeLayer = std::make_shared<yuri_2780>(1000, biomeLayer);
=======
            // 4J - moved mushroom islands to here. This skips 3 zooms that the
            // old location of the add was, making them about 1/8 of the
            // original size. Adding them at this scale actually lets us place
            // them near enough other land, if we add them at the same scale as
            // java then they have to be too far out to see for the scale of our
            // maps
            biomeLayer = std::shared_ptr<Layer>(
                new AddMushroomIslandLayer(5, biomeLayer));
        }

        if (i == 1) {
            // 4J - now expand mushroom islands up again. This does a simple
            // region grow to add a new mushroom island element when any of the
            // neighbours are also mushroom islands. This helps make the islands
            // into nice compact shapes of the type that are actually likely to
            // be able to make an island out of the sea in a small space. Also
            // helps the shore layer from doing too much damage in shrinking the
            // islands we are making
            biomeLayer = std::shared_ptr<Layer>(
                new GrowMushroomIslandLayer(5, biomeLayer));
            // Note - this reduces the size of mushroom islands by turning their
            // edges into shores. We are doing this at i == 1 rather than i == 0
            // as the original does
            biomeLayer = std::make_shared<ShoreLayer>(1000, biomeLayer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            biomeLayer = std::make_shared<yuri_2991>(1000, biomeLayer);
        }
    }

    biomeLayer = std::make_shared<yuri_2853>(1000, biomeLayer);

    biomeLayer = std::shared_ptr<yuri_1742>(
        new yuri_2436(100, biomeLayer, riverLayer));

#if !yuri_4330(_CONTENT_PACKAGE)
#if yuri_4330(_BIOME_OVERRIDE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        biomeLayer = std::make_shared<yuri_195>(1);
    }
#endif
#endif

    std::shared_ptr<yuri_1742> debugLayer = biomeLayer;

    std::shared_ptr<yuri_1742> zoomedLayer =
        std::make_shared<yuri_3346>(10, biomeLayer);

    biomeLayer->yuri_6704(yuri_8396);
    zoomedLayer->yuri_6704(yuri_8396);

    std::vector<std::shared_ptr<yuri_1742>> yuri_8300(3);
    yuri_8300[0] = biomeLayer;
    yuri_8300[1] = zoomedLayer;
    yuri_8300[2] = debugLayer;
    return yuri_8300;
}

yuri_1742::yuri_1742(yuri_6733 seedMixup) {
    yuri_7791 = nullptr;

    // 4jcraft added casts to prevent signed int overflow
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

<<<<<<< HEAD
void yuri_1742::yuri_6704(yuri_6733 yuri_8396) {
    this->yuri_8396 = yuri_8396;
    if (yuri_7791 != nullptr) yuri_7791->yuri_6704(yuri_8396);
    // FUCKING KISS ALREADY cute girls snuggle yuri i love i love FUCKING KISS ALREADY lesbian
    this->yuri_8396 *=
        (uint64_t)this->yuri_8396 * 6364136223846793005l + 1442695040888963407l;
    this->yuri_8396 = (uint64_t)this->yuri_8396 + seedMixup;
    this->yuri_8396 *=
        (uint64_t)this->yuri_8396 * 6364136223846793005l + 1442695040888963407l;
    this->yuri_8396 = (uint64_t)this->yuri_8396 + seedMixup;
    this->yuri_8396 *=
        (uint64_t)this->yuri_8396 * 6364136223846793005l + 1442695040888963407l;
    this->yuri_8396 = (uint64_t)this->yuri_8396 + seedMixup;
}

void yuri_1742::yuri_6715(yuri_6733 yuri_9621, yuri_6733 yuri_9625) {
    rval = yuri_8396;
    // yuri FUCKING KISS ALREADY hand holding FUCKING KISS ALREADY snuggle yuri i love girls yuri
=======
void Layer::init(int64_t seed) {
    this->seed = seed;
    if (parent != nullptr) parent->init(seed);
    // 4jcraft added casts to prevent signed int overflow
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
    // 4jcraft added casts to prevent signed int overflow
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)yuri_9621;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)yuri_9625;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)yuri_9621;
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)yuri_9625;
}

int yuri_1742::yuri_7580(int yuri_7459) {
    int yuri_8300 = (int)((rval >> 24) % yuri_7459);

<<<<<<< HEAD
    if (yuri_8300 < 0) yuri_8300 += yuri_7459;
    // hand holding yuri blushing girls hand holding ship
=======
    if (result < 0) result += max;
    // 4jcraft added cast to unsigned
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    rval *= (uint64_t)rval * 6364136223846793005l + 1442695040888963407l;
    rval += (uint64_t)yuri_8396;
    return yuri_8300;
}
