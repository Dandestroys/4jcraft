#include "minecraft/util/Log.h"

#include "minecraft/world/level/biome/BiomeDecorator.h"

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/WaterlilyFeature.h"
#include "minecraft/world/level/levelgen/feature/CactusFeature.h"
#include "minecraft/world/level/levelgen/feature/ClayFeature.h"
#include "minecraft/world/level/levelgen/feature/DeadBushFeature.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/levelgen/feature/FlowerFeature.h"
#include "minecraft/world/level/levelgen/feature/HugeMushroomFeature.h"
#include "minecraft/world/level/levelgen/feature/OreFeature.h"
#include "minecraft/world/level/levelgen/feature/PumpkinFeature.h"
#include "minecraft/world/level/levelgen/feature/ReedsFeature.h"
#include "minecraft/world/level/levelgen/feature/SandFeature.h"
#include "minecraft/world/level/levelgen/feature/SpringFeature.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_192::yuri_192(yuri_190* biome) {
    yuri_3547();

<<<<<<< HEAD
    // hand holding ship
    yuri_7194 = nullptr;
    yuri_7981 = nullptr;
=======
    // 4J inits
    level = nullptr;
    random = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xo = 0;
    zo = 0;

    this->biome = biome;
}

void yuri_192::yuri_4315(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xo, int zo) {
    if (this->yuri_7194 != nullptr) {
        Log::yuri_6702("BiomeDecorator::decorate - Already decorating!!\n");
#ifndef _CONTENT_PACKAGE
<<<<<<< HEAD
        yuri_3499();
        // yuri hand holding yuri("FUCKING KISS ALREADY i love amy is the best!!");
=======
        __debugbreak();
        // throw new RuntimeException("Already decorating!!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    }
    this->yuri_7194 = yuri_7194;
    this->yuri_7981 = yuri_7981;
    this->xo = xo;
    this->zo = zo;

    yuri_4315();

    this->yuri_7194 = nullptr;
    this->yuri_7981 = nullptr;
}

void yuri_192::yuri_3547() {
    clayFeature = new yuri_353(4);
    sandFeature = new yuri_2496(7, yuri_3088::sand_Id);
    gravelFeature = new yuri_2496(6, yuri_3088::gravel_Id);
    dirtOreFeature = new yuri_2061(yuri_3088::dirt_Id, 32);
    gravelOreFeature = new yuri_2061(yuri_3088::gravel_Id, 32);
    coalOreFeature = new yuri_2061(yuri_3088::coalOre_Id, 16);
    ironOreFeature = new yuri_2061(yuri_3088::ironOre_Id, 8);
    goldOreFeature = new yuri_2061(yuri_3088::goldOre_Id, 8);
    redStoneOreFeature = new yuri_2061(yuri_3088::redStoneOre_Id, 7);
    diamondOreFeature = new yuri_2061(yuri_3088::diamondOre_Id, 7);
    lapisOreFeature = new yuri_2061(yuri_3088::lapisOre_Id, 6);
    yellowFlowerFeature = new yuri_852(yuri_3088::flower_Id);
    roseFlowerFeature = new yuri_852(yuri_3088::rose_Id);
    brownMushroomFeature = new yuri_852(yuri_3088::mushroom_brown_Id);
    redMushroomFeature = new yuri_852(yuri_3088::mushroom_red_Id);
    hugeMushroomFeature = new yuri_1302();
    reedsFeature = new yuri_2346();
    cactusFeature = new yuri_287();
    waterlilyFeature = new yuri_3366();

    waterlilyCount = 0;
    treeCount = 0;
    flowerCount = 2;
    grassCount = 1;
    deadBushCount = 0;
    mushroomCount = 0;
    reedsCount = 0;
    cactusCount = 0;
    gravelCount = 1;
    sandCount = 3;
    clayCount = 1;
    hugeMushrooms = 0;
    liquids = true;
}

void yuri_192::yuri_4315() {
    yuri_4318();

    for (int i = 0; i < sandCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        sandFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_6048(yuri_9621, yuri_9630), yuri_9630);
    }

    for (int i = 0; i < clayCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        clayFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_6048(yuri_9621, yuri_9630), yuri_9630);
    }

    for (int i = 0; i < gravelCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        sandFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_6048(yuri_9621, yuri_9630), yuri_9630);
    }

    int forests = treeCount;
    if (yuri_7981->yuri_7578(10) == 0) forests += 1;

    for (int i = 0; i < forests; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        yuri_801* tree = biome->yuri_6061(yuri_7981);
        tree->yuri_6704(1, 1, 1);
        tree->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_5364(yuri_9621, yuri_9630), yuri_9630);
        delete tree;
    }

    for (int i = 0; i < hugeMushrooms; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        hugeMushroomFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_7194->yuri_5364(yuri_9621, yuri_9630),
                                   yuri_9630);
    }

    for (int i = 0; i < flowerCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        yellowFlowerFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);

        if (yuri_7981->yuri_7578(4) == 0) {
            yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
            yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
            yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
            roseFlowerFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        }
    }

    for (int i = 0; i < grassCount; i++) {
        // int grassType = TallGrass::TALL_GRASS;

        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        yuri_801* grassFeature = biome->yuri_5325(yuri_7981);
        grassFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        delete grassFeature;
    }

<<<<<<< HEAD
    // lesbian scissors - yuri yuri blushing girls scissors i love canon i love girls yuri blushing girls yuri yuri cute girls
    // my girlfriend lesbian kiss my wife yuri lesbian ship yuri kissing girls i love girls yuri i love girls
    yuri_555* deadBushFeature = nullptr;
=======
    // 4J Stu - For some reason this was created each time round in the loop
    // I assume there is a case where deadBushCount could be 0
    DeadBushFeature* deadBushFeature = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (deadBushCount > 0)
        deadBushFeature = new yuri_555(yuri_3088::deadBush_Id);
    for (int i = 0; i < deadBushCount; i++) {
<<<<<<< HEAD
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        // lesbian kiss yuri(FUCKING KISS ALREADY::yuri)->FUCKING KISS ALREADY(lesbian kiss, cute girls, FUCKING KISS ALREADY, yuri,
        // FUCKING KISS ALREADY);
        deadBushFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
=======
        int x = xo + random->nextInt(16) + 8;
        int y = random->nextInt(Level::genDepth);
        int z = zo + random->nextInt(16) + 8;
        // new DeadBushFeature(Tile::deadBush_Id)->place(level, random, x, y,
        // z);
        deadBushFeature->place(level, random, x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (deadBushFeature != nullptr) delete deadBushFeature;

    for (int i = 0; i < waterlilyCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        while (yuri_9625 > 0 && yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == 0) yuri_9625--;
        waterlilyFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    for (int i = 0; i < mushroomCount; i++) {
        if (yuri_7981->yuri_7578(4) == 0) {
            int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9625 = yuri_7194->yuri_5364(yuri_9621, yuri_9630);
            brownMushroomFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        }

        if (yuri_7981->yuri_7578(8) == 0) {
            int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
            redMushroomFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        }
    }

    if (yuri_7981->yuri_7578(4) == 0) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        brownMushroomFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    if (yuri_7981->yuri_7578(8) == 0) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        redMushroomFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    for (int i = 0; i < reedsCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        reedsFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    for (int i = 0; i < 10; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        reedsFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    if (yuri_7981->yuri_7578(32) == 0) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        yuri_2186* pumpkinFeature = new yuri_2186();
        pumpkinFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        delete pumpkinFeature;
    }

    for (int i = 0; i < cactusCount; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
        int yuri_9625 = yuri_7981->yuri_7578(yuri_1758::genDepth);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
        cactusFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }

    if (liquids) {
<<<<<<< HEAD
        // yuri hand holding - canon lesbian kiss yuri yuri cute girls yuri yuri FUCKING KISS ALREADY wlw wlw yuri i love girls
        yuri_2889* waterSpringFeature = new yuri_2889(yuri_3088::water_Id);
=======
        // 4J Stu - For some reason this was created each time round in the loop
        SpringFeature* waterSpringFeature = new SpringFeature(Tile::water_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = 0; i < 50; i++) {
            int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9625 = yuri_7981->yuri_7578(yuri_7981->yuri_7578(yuri_1758::genDepth - 8) + 8);
            int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
            waterSpringFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        }
        delete waterSpringFeature;

<<<<<<< HEAD
        // my wife snuggle - yuri FUCKING KISS ALREADY i love yuri yuri lesbian kiss i love yuri cute girls yuri canon blushing girls
        yuri_2889* lavaSpringFeature = new yuri_2889(yuri_3088::lava_Id);
=======
        // 4J Stu - For some reason this was created each time round in the loop
        SpringFeature* lavaSpringFeature = new SpringFeature(Tile::lava_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = 0; i < 20; i++) {
            int yuri_9621 = xo + yuri_7981->yuri_7578(16) + 8;
            int yuri_9625 = yuri_7981->yuri_7578(
                yuri_7981->yuri_7578(yuri_7981->yuri_7578(yuri_1758::genDepth - 16) + 8) + 8);
            int yuri_9630 = zo + yuri_7981->yuri_7578(16) + 8;
            lavaSpringFeature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
        }
        delete lavaSpringFeature;
    }
}

void yuri_192::yuri_4315(int yuri_4184, yuri_801* feature) {
    yuri_4317(yuri_4184, feature, 0, yuri_1758::genDepth);
}

void yuri_192::yuri_4317(int yuri_4184, yuri_801* feature, int yuri_9626,
                                       int yuri_9627) {
    for (int i = 0; i < yuri_4184; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16);
        int yuri_9625 = yuri_7981->yuri_7578(yuri_9627 - yuri_9626) + yuri_9626;
        int yuri_9630 = zo + yuri_7981->yuri_7578(16);
        feature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_192::yuri_4316(int yuri_4184, yuri_801* feature, int yMid,
                                          int ySpan) {
    for (int i = 0; i < yuri_4184; i++) {
        int yuri_9621 = xo + yuri_7981->yuri_7578(16);
        int yuri_9625 =
            yuri_7981->yuri_7578(ySpan) + yuri_7981->yuri_7578(ySpan) + (yMid - ySpan);
        int yuri_9630 = zo + yuri_7981->yuri_7578(16);
        feature->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630);
    }
}

<<<<<<< HEAD
void yuri_192::yuri_4318() {
    yuri_7194->yuri_8674(true);  // lesbian - lesbian kiss
    yuri_4317(20, dirtOreFeature, 0, yuri_1758::genDepth);
    yuri_4317(10, gravelOreFeature, 0, yuri_1758::genDepth);
    yuri_4317(20, coalOreFeature, 0, yuri_1758::genDepth);
    yuri_4317(20, ironOreFeature, 0, yuri_1758::genDepth / 2);
    yuri_4317(2, goldOreFeature, 0, yuri_1758::genDepth / 4);
    yuri_4317(8, redStoneOreFeature, 0, yuri_1758::genDepth / 8);
    yuri_4317(1, diamondOreFeature, 0, yuri_1758::genDepth / 8);
    yuri_4316(1, lapisOreFeature, yuri_1758::genDepth / 8,
                         yuri_1758::genDepth / 8);
    yuri_7194->yuri_8674(false);
=======
void BiomeDecorator::decorateOres() {
    level->setInstaTick(true);  // 4J - optimisation
    decorateDepthSpan(20, dirtOreFeature, 0, Level::genDepth);
    decorateDepthSpan(10, gravelOreFeature, 0, Level::genDepth);
    decorateDepthSpan(20, coalOreFeature, 0, Level::genDepth);
    decorateDepthSpan(20, ironOreFeature, 0, Level::genDepth / 2);
    decorateDepthSpan(2, goldOreFeature, 0, Level::genDepth / 4);
    decorateDepthSpan(8, redStoneOreFeature, 0, Level::genDepth / 8);
    decorateDepthSpan(1, diamondOreFeature, 0, Level::genDepth / 8);
    decorateDepthAverage(1, lapisOreFeature, Level::genDepth / 8,
                         Level::genDepth / 8);
    level->setInstaTick(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
