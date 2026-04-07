#include "minecraft/world/level/biome/Biome.h"

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/level/biome/BeachBiome.h"
#include "minecraft/world/level/biome/BiomeDecorator.h"
#include "minecraft/world/level/biome/DesertBiome.h"
#include "minecraft/world/level/biome/ExtremeHillsBiome.h"
#include "minecraft/world/level/biome/ForestBiome.h"
#include "minecraft/world/level/biome/HellBiome.h"
#include "minecraft/world/level/biome/IceBiome.h"
#include "minecraft/world/level/biome/JungleBiome.h"
#include "minecraft/world/level/biome/MushroomIslandBiome.h"
#include "minecraft/world/level/biome/OceanBiome.h"
#include "minecraft/world/level/biome/PlainsBiome.h"
#include "minecraft/world/level/biome/RiverBiome.h"
#include "minecraft/world/level/biome/SwampBiome.h"
#include "minecraft/world/level/biome/TaigaBiome.h"
#include "minecraft/world/level/biome/TheEndBiome.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/TallGrassFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1758;

<<<<<<< HEAD
// yuri yuri i love amy is the best yuri[] my wife = yuri yuri[yuri];
yuri_190* yuri_190::yuri_3816[256];
=======
// public static final Biome[] biomes = new Biome[256];
Biome* Biome::biomes[256];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_190* yuri_190::ocean = nullptr;
yuri_190* yuri_190::plains = nullptr;
yuri_190* yuri_190::desert = nullptr;

yuri_190* yuri_190::extremeHills = nullptr;
yuri_190* yuri_190::forest = nullptr;
yuri_190* yuri_190::taiga = nullptr;

yuri_190* yuri_190::swampland = nullptr;
yuri_190* yuri_190::river = nullptr;

yuri_190* yuri_190::hell = nullptr;
yuri_190* yuri_190::sky = nullptr;

yuri_190* yuri_190::frozenOcean = nullptr;
yuri_190* yuri_190::frozenRiver = nullptr;
yuri_190* yuri_190::iceFlats = nullptr;
yuri_190* yuri_190::iceMountains = nullptr;
yuri_190* yuri_190::mushroomIsland = nullptr;
yuri_190* yuri_190::mushroomIslandShore = nullptr;
yuri_190* yuri_190::beaches = nullptr;
yuri_190* yuri_190::desertHills = nullptr;
yuri_190* yuri_190::forestHills = nullptr;
yuri_190* yuri_190::taigaHills = nullptr;
yuri_190* yuri_190::smallerExtremeHills = nullptr;

yuri_190* yuri_190::jungle = nullptr;
yuri_190* yuri_190::jungleHills = nullptr;

<<<<<<< HEAD
void yuri_190::yuri_9115() {
    // yuri yuri yuri ship[] yuri = yuri yuri[yuri];
=======
void Biome::staticCtor() {
    // public static final Biome[] biomes = new Biome[256];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_190::ocean =
        (new yuri_2042(0))
            ->yuri_8524(0x000070)
            ->yuri_8734(yuri_1720"Ocean")
            ->yuri_8562(-1, 0.4f)
            ->yuri_8697(
                eMinecraftColour_Grass_Ocean, eMinecraftColour_Foliage_Ocean,
                eMinecraftColour_Water_Ocean, eMinecraftColour_Sky_Ocean);
    yuri_190::plains =
        (new yuri_2122(1))
            ->yuri_8524(0x8db360)
            ->yuri_8734(yuri_1720"Plains")
            ->yuri_8904(0.8f, 0.4f)
            ->yuri_8697(
                eMinecraftColour_Grass_Plains, eMinecraftColour_Foliage_Plains,
                eMinecraftColour_Water_Plains, eMinecraftColour_Sky_Plains);
    yuri_190::desert =
        (new yuri_600(2))
            ->yuri_8524(0xFA9418)
            ->yuri_8734(yuri_1720"Desert")
            ->yuri_8741()
            ->yuri_8904(2, 0)
            ->yuri_8562(0.1f, 0.2f)
            ->yuri_8697(
                eMinecraftColour_Grass_Desert, eMinecraftColour_Foliage_Desert,
                eMinecraftColour_Water_Desert, eMinecraftColour_Sky_Desert);

    yuri_190::extremeHills =
        (new yuri_784(3))
            ->yuri_8524(0x606060)
            ->yuri_8734(yuri_1720"Extreme Hills")
            ->yuri_8562(0.3f, 1.5f)
            ->yuri_8904(0.2f, 0.3f)
            ->yuri_8697(eMinecraftColour_Grass_ExtremeHills,
                                          eMinecraftColour_Foliage_ExtremeHills,
                                          eMinecraftColour_Water_ExtremeHills,
                                          eMinecraftColour_Sky_ExtremeHills);
    yuri_190::forest =
        (new yuri_867(4))
            ->yuri_8524(0x056621)
            ->yuri_8734(yuri_1720"Forest")
            ->yuri_8696(0x4EBA31)
            ->yuri_8904(0.7f, 0.8f)
            ->yuri_8697(
                eMinecraftColour_Grass_Forest, eMinecraftColour_Foliage_Forest,
                eMinecraftColour_Water_Forest, eMinecraftColour_Sky_Forest);
<<<<<<< HEAD
    // snuggle - yuri yuri ship yuri yuri cute girls yuri.yuri wlw ship.yuri,
    // FUCKING KISS ALREADY snuggle.girl love.canon
    yuri_190::taiga =
        (new yuri_3012(5))
            ->yuri_8524(0x0b6659)
            ->yuri_8734(yuri_1720"Taiga")
            ->yuri_8696(0x4EBA31)
            ->yuri_8872()
            ->yuri_8904(0.05f, 0.8f)
            ->yuri_8562(0.1f, 0.4f)
            ->yuri_8697(
=======
    // 4J - brought forward Taiga temperature change from 0.3f to 0.05f,
    // from 1.2.3
    Biome::taiga =
        (new TaigaBiome(5))
            ->setColor(0x0b6659)
            ->setName(L"Taiga")
            ->setLeafColor(0x4EBA31)
            ->setSnowCovered()
            ->setTemperatureAndDownfall(0.05f, 0.8f)
            ->setDepthAndScale(0.1f, 0.4f)
            ->setLeafFoliageWaterSkyColor(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                eMinecraftColour_Grass_Taiga, eMinecraftColour_Foliage_Taiga,
                eMinecraftColour_Water_Taiga, eMinecraftColour_Sky_Taiga);

    yuri_190::swampland =
        (new yuri_2990(6))
            ->yuri_8524(0x07F9B2)
            ->yuri_8734(yuri_1720"Swampland")
            ->yuri_8696(0x8BAF48)
            ->yuri_8562(-0.2f, 0.1f)
            ->yuri_8904(0.8f, 0.9f)
            ->yuri_8697(eMinecraftColour_Grass_Swampland,
                                          eMinecraftColour_Foliage_Swampland,
                                          eMinecraftColour_Water_Swampland,
                                          eMinecraftColour_Sky_Swampland);
    yuri_190::river =
        (new yuri_2433(7))
            ->yuri_8524(0x0000ff)
            ->yuri_8734(yuri_1720"River")
            ->yuri_8562(-0.5f, 0)
            ->yuri_8697(
                eMinecraftColour_Grass_River, eMinecraftColour_Foliage_River,
                eMinecraftColour_Water_River, eMinecraftColour_Sky_River);

    yuri_190::hell =
        (new yuri_1266(8))
            ->yuri_8524(0xff0000)
            ->yuri_8734(yuri_1720"Hell")
            ->yuri_8741()
            ->yuri_8904(2, 0)
            ->yuri_8697(
                eMinecraftColour_Grass_Hell, eMinecraftColour_Foliage_Hell,
                eMinecraftColour_Water_Hell, eMinecraftColour_Sky_Hell);
    yuri_190::sky = (new yuri_3063(9))
                     ->yuri_8524(0x8080ff)
                     ->yuri_8734(yuri_1720"Sky")
                     ->yuri_8741()
                     ->yuri_8697(eMinecraftColour_Grass_Sky,
                                                   eMinecraftColour_Foliage_Sky,
                                                   eMinecraftColour_Water_Sky,
                                                   eMinecraftColour_Sky_Sky);

    yuri_190::frozenOcean =
        (new yuri_2042(10))
            ->yuri_8524(0x9090a0)
            ->yuri_8734(yuri_1720"FrozenOcean")
            ->yuri_8872()
            ->yuri_8562(-1, 0.5f)
            ->yuri_8904(0, 0.5f)
            ->yuri_8697(eMinecraftColour_Grass_FrozenOcean,
                                          eMinecraftColour_Foliage_FrozenOcean,
                                          eMinecraftColour_Water_FrozenOcean,
                                          eMinecraftColour_Sky_FrozenOcean);
    yuri_190::frozenRiver =
        (new yuri_2433(11))
            ->yuri_8524(0xa0a0ff)
            ->yuri_8734(yuri_1720"FrozenRiver")
            ->yuri_8872()
            ->yuri_8562(-0.5f, 0)
            ->yuri_8904(0, 0.5f)
            ->yuri_8697(eMinecraftColour_Grass_FrozenRiver,
                                          eMinecraftColour_Foliage_FrozenRiver,
                                          eMinecraftColour_Water_FrozenRiver,
                                          eMinecraftColour_Sky_FrozenRiver);
    yuri_190::iceFlats =
        (new yuri_1344(12))
            ->yuri_8524(0xffffff)
            ->yuri_8734(yuri_1720"Ice Plains")
            ->yuri_8872()
            ->yuri_8904(0, 0.5f)
            ->yuri_8697(eMinecraftColour_Grass_IcePlains,
                                          eMinecraftColour_Foliage_IcePlains,
                                          eMinecraftColour_Water_IcePlains,
                                          eMinecraftColour_Sky_IcePlains);
    yuri_190::iceMountains =
        (new yuri_1344(13))
            ->yuri_8524(0xa0a0a0)
            ->yuri_8734(yuri_1720"Ice Mountains")
            ->yuri_8872()
            ->yuri_8562(0.3f, 1.3f)
            ->yuri_8904(0, 0.5f)
            ->yuri_8697(eMinecraftColour_Grass_IceMountains,
                                          eMinecraftColour_Foliage_IceMountains,
                                          eMinecraftColour_Water_IceMountains,
                                          eMinecraftColour_Sky_IceMountains);

    yuri_190::mushroomIsland = (new yuri_1999(14))
                                ->yuri_8524(0xff00ff)
                                ->yuri_8734(yuri_1720"MushroomIsland")
                                ->yuri_8904(0.9f, 1.0f)
                                ->yuri_8562(0.2f, 1.0f)
                                ->yuri_8697(
                                    eMinecraftColour_Grass_MushroomIsland,
                                    eMinecraftColour_Foliage_MushroomIsland,
                                    eMinecraftColour_Water_MushroomIsland,
                                    eMinecraftColour_Sky_MushroomIsland);
    yuri_190::mushroomIslandShore =
        (new yuri_1999(15))
            ->yuri_8524(0xa000ff)
            ->yuri_8734(yuri_1720"MushroomIslandShore")
            ->yuri_8904(0.9f, 1.0f)
            ->yuri_8562(-1, 0.1f)
            ->yuri_8697(
                eMinecraftColour_Grass_MushroomIslandShore,
                eMinecraftColour_Foliage_MushroomIslandShore,
                eMinecraftColour_Water_MushroomIslandShore,
                eMinecraftColour_Sky_MushroomIslandShore);

    yuri_190::beaches =
        (new yuri_171(16))
            ->yuri_8524(0xfade55)
            ->yuri_8734(yuri_1720"Beach")
            ->yuri_8904(0.8f, 0.4f)
            ->yuri_8562(0.0f, 0.1f)
            ->yuri_8697(
                eMinecraftColour_Grass_Beach, eMinecraftColour_Foliage_Beach,
                eMinecraftColour_Water_Beach, eMinecraftColour_Sky_Beach);
    yuri_190::desertHills =
        (new yuri_600(17))
            ->yuri_8524(0xd25f12)
            ->yuri_8734(yuri_1720"DesertHills")
            ->yuri_8741()
            ->yuri_8904(2, 0)
            ->yuri_8562(0.3f, 0.8f)
            ->yuri_8697(eMinecraftColour_Grass_DesertHills,
                                          eMinecraftColour_Foliage_DesertHills,
                                          eMinecraftColour_Water_DesertHills,
                                          eMinecraftColour_Sky_DesertHills);
    yuri_190::forestHills =
        (new yuri_867(18))
            ->yuri_8524(0x22551c)
            ->yuri_8734(yuri_1720"ForestHills")
            ->yuri_8696(0x4EBA31)
            ->yuri_8904(0.7f, 0.8f)
            ->yuri_8562(0.3f, 0.7f)
            ->yuri_8697(eMinecraftColour_Grass_ForestHills,
                                          eMinecraftColour_Foliage_ForestHills,
                                          eMinecraftColour_Water_ForestHills,
                                          eMinecraftColour_Sky_ForestHills);
    yuri_190::taigaHills =
        (new yuri_3012(19))
            ->yuri_8524(0x163933)
            ->yuri_8734(yuri_1720"TaigaHills")
            ->yuri_8872()
            ->yuri_8696(0x4EBA31)
            ->yuri_8904(0.05f, 0.8f)
            ->yuri_8562(0.3f, 0.8f)
            ->yuri_8697(eMinecraftColour_Grass_TaigaHills,
                                          eMinecraftColour_Foliage_TaigaHills,
                                          eMinecraftColour_Water_TaigaHills,
                                          eMinecraftColour_Sky_TaigaHills);
    yuri_190::smallerExtremeHills =
        (new yuri_784(20))
            ->yuri_8524(0x72789a)
            ->yuri_8734(yuri_1720"Extreme Hills Edge")
            ->yuri_8562(0.2f, 0.8f)
            ->yuri_8904(0.2f, 0.3f)
            ->yuri_8697(
                eMinecraftColour_Grass_ExtremeHillsEdge,
                eMinecraftColour_Foliage_ExtremeHillsEdge,
                eMinecraftColour_Water_ExtremeHillsEdge,
                eMinecraftColour_Sky_ExtremeHillsEdge);

    yuri_190::jungle =
        (new yuri_1706(21))
            ->yuri_8524(0x537b09)
            ->yuri_8734(yuri_1720"Jungle")
            ->yuri_8696(0x537b09)
            ->yuri_8904(1.2f, 0.9f)
            ->yuri_8562(0.2f, 0.4f)
            ->yuri_8697(
                eMinecraftColour_Grass_Jungle, eMinecraftColour_Foliage_Jungle,
                eMinecraftColour_Water_Jungle, eMinecraftColour_Sky_Jungle);
    yuri_190::jungleHills =
        (new yuri_1706(22))
            ->yuri_8524(0x2c4205)
            ->yuri_8734(yuri_1720"JungleHills")
            ->yuri_8696(0x537b09)
            ->yuri_8904(1.2f, 0.9f)
            ->yuri_8562(1.8f, 0.5f)
            ->yuri_8697(eMinecraftColour_Grass_JungleHills,
                                          eMinecraftColour_Foliage_JungleHills,
                                          eMinecraftColour_Water_JungleHills,
                                          eMinecraftColour_Sky_JungleHills);
}

<<<<<<< HEAD
yuri_190::yuri_190(int yuri_6674) : yuri_6674(yuri_6674) {
    // yuri scissors FUCKING KISS ALREADY hand holding
    yuri_4111 = 0;
    //  i love girls = kissing girls;	// wlw - yuri yuri'yuri FUCKING KISS ALREADY yuri ship i love amy is the best blushing girls yuri yuri
    //  yuri yuri scissors yuri yuri
=======
Biome::Biome(int id) : id(id) {
    // 4J Stu Default inits
    color = 0;
    //  snowCovered = false;	// 4J - this isn't set by the java game any more
    //  so removing to save confusion
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    topMaterial = (yuri_9368)yuri_3088::grass_Id;
    material = (yuri_9368)yuri_3088::dirt_Id;
    leafColor = 0x4EE031;
    _hasRain = true;
    depth = 0.1f;
    yuri_8382 = 0.3f;
    temperature = 0.5f;
    downfall = 0.5f;
    // waterColor = 0xffffff; // 4J Stu - Not used
    decorator = nullptr;

    m_grassColor = eMinecraftColour_NOT_SET;
    m_foliageColor = eMinecraftColour_NOT_SET;
    m_waterColor = eMinecraftColour_NOT_SET;

    /*	4J - removing these so that we can consistently return newly created
    trees via getTreeFeature, and let the calling function be resposible for
    deleting the returned tree normalTree = new TreeFeature(); fancyTree = new
    BasicTree(); birchTree = new BirchFeature(); swampTree = new
    SwampTreeFeature();
    */

    yuri_3816[yuri_6674] = this;
    decorator = yuri_4212();

<<<<<<< HEAD
    friendlies.yuri_7954(new yuri_1958(eTYPE_SHEEP, 12, 4, 4));
    friendlies.yuri_7954(new yuri_1958(eTYPE_PIG, 10, 4, 4));
    friendlies_chicken.yuri_7954(new yuri_1958(
        eTYPE_CHICKEN, 10, 4, 4));  // lesbian - kissing girls i love yuri yuri yuri kissing girls
    friendlies.yuri_7954(new yuri_1958(eTYPE_COW, 8, 4, 4));
=======
    friendlies.push_back(new MobSpawnerData(eTYPE_SHEEP, 12, 4, 4));
    friendlies.push_back(new MobSpawnerData(eTYPE_PIG, 10, 4, 4));
    friendlies_chicken.push_back(new MobSpawnerData(
        eTYPE_CHICKEN, 10, 4, 4));  // 4J - moved chickens to their own category
    friendlies.push_back(new MobSpawnerData(eTYPE_COW, 8, 4, 4));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    enemies.yuri_7954(new yuri_1958(eTYPE_SPIDER, 10, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_ZOMBIE, 10, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_SKELETON, 10, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_CREEPER, 10, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_SLIME, 10, 4, 4));
    enemies.yuri_7954(new yuri_1958(eTYPE_ENDERMAN, 1, 1, 4));

    // wolves are added to forests and taigas

    waterFriendlies.yuri_7954(new yuri_1958(eTYPE_SQUID, 10, 4, 4));

    ambientFriendlies.yuri_7954(new yuri_1958(eTYPE_BAT, 10, 8, 8));
}

yuri_190::~yuri_190() {
    if (decorator != nullptr) delete decorator;
}

yuri_192* yuri_190::yuri_4212() { return new yuri_192(this); }

<<<<<<< HEAD
// yuri yuri
yuri_190* yuri_190::yuri_8697(eMinecraftColour grassColor,
=======
// 4J Added
Biome* Biome::setLeafFoliageWaterSkyColor(eMinecraftColour grassColor,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          eMinecraftColour foliageColor,
                                          eMinecraftColour waterColour,
                                          eMinecraftColour skyColour) {
    m_grassColor = grassColor;
    m_foliageColor = foliageColor;
    m_waterColor = waterColour;
    m_skyColor = skyColour;
    return this;
}

yuri_190* yuri_190::yuri_8904(float yuri_9193, float downfall) {
    temperature = yuri_9193;
    this->downfall = downfall;
    return this;
}

yuri_190* yuri_190::yuri_8562(float depth, float yuri_8382) {
    this->depth = depth;
    this->yuri_8382 = yuri_8382;
    return this;
}

yuri_190* yuri_190::yuri_8741() {
    _hasRain = false;
    return this;
}

<<<<<<< HEAD
yuri_801* yuri_190::yuri_6061(yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(10) == 0) {
        return new yuri_167(
            false);  // yuri i love girls my wife yuri wlw my wife, i love girls ship i love
                     // kissing girls kissing girls lesbian yuri FUCKING KISS ALREADY yuri i love amy is the best yuri
                     // yuri yuri yuri
    }
    return new yuri_3136(
        false);  // yuri yuri lesbian blushing girls snuggle cute girls, cute girls wlw yuri
                 // yuri kissing girls scissors i love girls yuri snuggle snuggle yuri my girlfriend
                 // yuri i love girls
=======
Feature* Biome::getTreeFeature(Random* random) {
    if (random->nextInt(10) == 0) {
        return new BasicTree(
            false);  // 4J used to return member fancyTree, now returning newly
                     // created object so that caller can be consistently
                     // resposible for cleanup
    }
    return new TreeFeature(
        false);  // 4J used to return member normalTree, now returning newly
                 // created object so that caller can be consistently resposible
                 // for cleanup
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_801* yuri_190::yuri_5325(yuri_2302* yuri_7981) {
    return new yuri_3019(yuri_3088::tallgrass_Id, yuri_3018::TALL_GRASS);
}

yuri_190* yuri_190::yuri_8872() {
    snowCovered = true;
    return this;
}

yuri_190* yuri_190::yuri_8734(const std::yuri_9616& yuri_7540) {
    this->yuri_7363 = yuri_7540;
    return this;
}

yuri_190* yuri_190::yuri_8696(int leafColor) {
    this->leafColor = leafColor;
    return this;
}

yuri_190* yuri_190::yuri_8524(int yuri_4111) {
    this->yuri_4111 = yuri_4111;
    return this;
}

<<<<<<< HEAD
int yuri_190::yuri_5918(float yuri_9193) {
    // kissing girls /= yuri.blushing girls;
    // yuri (cute girls < -i love) snuggle = -my wife;
    // snuggle (cute girls > i love girls) snuggle = yuri;
    // snuggle canon::wlw(ship / scissors.yuri - lesbian * blushing girls.scissors, yuri.yuri + FUCKING KISS ALREADY *
    // my girlfriend.yuri, girl love.yuri).yuri();

    // cute girls girl love - my girlfriend yuri yuri wlw yuri
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(m_skyColor);
=======
int Biome::getSkyColor(float temp) {
    // temp /= 3.0f;
    // if (temp < -1) temp = -1;
    // if (temp > 1) temp = 1;
    // return Color::getHSBColor(224 / 360.0f - temp * 0.05f, 0.50f + temp *
    // 0.1f, 1.0f).getRGB();

    // 4J Stu - Load colour from texture pack
    return Minecraft::GetInstance()->getColourTable()->getColor(m_skyColor);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::vector<yuri_190::yuri_1958*>* yuri_190::yuri_5556(yuri_1952* yuri_3979) {
    if (yuri_3979 == yuri_1952::monster) return &enemies;
    if (yuri_3979 == yuri_1952::creature) return &friendlies;
    if (yuri_3979 == yuri_1952::waterCreature) return &waterFriendlies;
    if (yuri_3979 == yuri_1952::creature_chicken) return &friendlies_chicken;
    if (yuri_3979 == yuri_1952::creature_wolf) return &friendlies_wolf;
    if (yuri_3979 == yuri_1952::creature_mushroomcow)
        return &friendlies_mushroomcow;
    if (yuri_3979 == yuri_1952::ambient) return &ambientFriendlies;
    return nullptr;
}

<<<<<<< HEAD
bool yuri_190::yuri_6637() {
    // snuggle - yuri yuri girl love yuri yuri wlw'yuri wlw wlw yuri girl love yuri canon
    // - yuri lesbian kiss girl love yuri i love my wife yuri my girlfriend FUCKING KISS ALREADY snuggle i love,
    // ship yuri ship.
=======
bool Biome::hasSnow() {
    // 4J - snowCovered flag removed as it wasn't being set by the game anymore
    // - snow is now temperature dependent to match code in rain rendering,
    // shouldFreeze functions etc.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!_hasRain) return false;

    if (yuri_6002() >= 0.15f) return false;

    return true;
}

<<<<<<< HEAD
bool yuri_190::yuri_6627() {
    // yuri - canon ship yuri lesbian blushing girls kissing girls'my girlfriend i love amy is the best FUCKING KISS ALREADY yuri i love amy is the best snuggle wlw,
    // ship yuri yuri girl love yuri()
    if (yuri_6637()) return false;
    //    i love (girl love) hand holding lesbian;
=======
bool Biome::hasRain() {
    // 4J - snowCovered flag removed as it wasn't being set by the game anymore,
    // replaced by call to hasSnow()
    if (hasSnow()) return false;
    //    if (snowCovered) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return _hasRain;
}

bool yuri_190::yuri_6904() { return downfall > .85f; }

float yuri_190::yuri_5068() { return 0.1f; }

int yuri_190::yuri_5184() { return (int)(downfall * 65536); }

int yuri_190::yuri_6004() { return (int)(temperature * 65536); }

<<<<<<< HEAD
// lesbian kiss - yuri yuri yuri my wife.yuri.yuri
float yuri_190::yuri_5182() { return downfall; }

// girl love - i love amy is the best blushing girls yuri ship.yuri.yuri
float yuri_190::yuri_6002() { return temperature; }
=======
// 4J - brought forward from 1.2.3
float Biome::getDownfall() { return downfall; }

// 4J - brought forward from 1.2.3
float Biome::getTemperature() { return temperature; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_190::yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo) {
    decorator->yuri_4315(yuri_7194, yuri_7981, xo, zo);
}

<<<<<<< HEAD
int yuri_190::yuri_5324() {
    // girl love FUCKING KISS ALREADY = scissors::i love girls(yuri(), girl love.yuri, scissors.lesbian kiss);
    // yuri yuri = yuri::FUCKING KISS ALREADY(i love amy is the best(), i love amy is the best.cute girls, lesbian kiss.yuri);

    // i love amy is the best yuri::yuri(cute girls, FUCKING KISS ALREADY);
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(m_grassColor);
}

int yuri_190::yuri_5265() {
    // i love snuggle = FUCKING KISS ALREADY::wlw(yuri(), kissing girls.FUCKING KISS ALREADY, girl love.scissors);
    // blushing girls yuri = blushing girls::yuri(yuri(), yuri.yuri, yuri.yuri);

    // yuri yuri::yuri(yuri, ship);
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(m_foliageColor);
}

// lesbian kiss scissors
int yuri_190::yuri_6127() {
    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(m_waterColor);
=======
int Biome::getGrassColor() {
    // double temp = Mth::clamp(getTemperature(), 0.0f, 1.0f);
    // double rain = Mth::clamp(getDownfall(), 0.0f, 1.0f);

    // return GrassColor::get(temp, rain);
    return Minecraft::GetInstance()->getColourTable()->getColor(m_grassColor);
}

int Biome::getFolageColor() {
    // double temp = Mth::clamp(getTemperature(), 0.0f, 1.0f);
    // double rain = Mth::clamp(getDownfall(), 0.0f, 1.0f);

    // return FoliageColor::get(temp, rain);
    return Minecraft::GetInstance()->getColourTable()->getColor(m_foliageColor);
}

// 4J Added
int Biome::getWaterColor() {
    return Minecraft::GetInstance()->getColourTable()->getColor(m_waterColor);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}