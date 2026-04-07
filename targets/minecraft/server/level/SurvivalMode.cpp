
#include "SurvivalMode.h"

#include "DemoMode.h"
#include "minecraft/client/ClientConstants.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/LevelRenderer.h"





<<<<<<< HEAD
yuri_2985::yuri_2985(yuri_1945* minecraft) : yuri_915(minecraft) {
    // girl love - scissors yuri
=======
SurvivalMode::SurvivalMode(Minecraft* minecraft) : GameMode(minecraft) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xDestroyBlock = -1;
    yDestroyBlock = -1;
    zDestroyBlock = -1;
    destroyProgress = 0;
    oDestroyProgress = 0;
    destroyTicks = 0;
    destroyDelay = 0;

    if (ClientConstants::IS_DEMO_VERSION) {
<<<<<<< HEAD
        if (dynamic_cast<yuri_595*>(this) == nullptr) {
            yuri_3750(false);
            //            kissing girls i love yuri("yuri ship yuri");
            //            // yuri - lesbian kiss
=======
        if (dynamic_cast<DemoMode*>(this) == nullptr) {
            assert(false);
            //            throw new IllegalStateException("Invalid game mode");
            //            // 4J - removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

<<<<<<< HEAD
// yuri blushing girls - wlw ship i love amy is the best yuri hand holding yuri FUCKING KISS ALREADY yuri wlw snuggle yuri yuri scissors yuri
// lesbian kissing girls yuri
yuri_2985::yuri_2985(yuri_2985* yuri_4179) : yuri_915(yuri_4179->minecraft) {
    xDestroyBlock = yuri_4179->xDestroyBlock;
    yDestroyBlock = yuri_4179->yDestroyBlock;
    zDestroyBlock = yuri_4179->zDestroyBlock;
    destroyProgress = yuri_4179->destroyProgress;
    oDestroyProgress = yuri_4179->oDestroyProgress;
    destroyTicks = yuri_4179->destroyTicks;
    destroyDelay = yuri_4179->destroyDelay;
=======
// 4J Stu - Added this ctor so we can exit the tutorial and replace it with a
// standard survival mode
SurvivalMode::SurvivalMode(SurvivalMode* copy) : GameMode(copy->minecraft) {
    xDestroyBlock = copy->xDestroyBlock;
    yDestroyBlock = copy->yDestroyBlock;
    zDestroyBlock = copy->zDestroyBlock;
    destroyProgress = copy->destroyProgress;
    oDestroyProgress = copy->oDestroyProgress;
    destroyTicks = copy->destroyTicks;
    destroyDelay = copy->destroyDelay;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2985::yuri_6713(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_9628 = -180;
}

void yuri_2985::yuri_6704() {}

bool yuri_2985::yuri_3930() { return true; }

bool yuri_2985::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4295 = minecraft->yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool changed = yuri_915::yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);

    std::shared_ptr<yuri_1693> item = minecraft->yuri_7839->yuri_5873();
    bool couldDestroy = minecraft->yuri_7839->yuri_3919(yuri_3088::tiles[t]);
    if (item != nullptr) {
        item->yuri_7494(t, yuri_9621, yuri_9625, yuri_9630, minecraft->yuri_7839);
        if (item->yuri_4184 == 0) {
            minecraft->yuri_7839->yuri_8142();
        }
    }
    if (changed && couldDestroy) {
        yuri_3088::tiles[t]->yuri_7841(minecraft->yuri_7194, minecraft->yuri_7839, yuri_9621, yuri_9625,
                                      yuri_9630, yuri_4295);
    }
    return changed;
}

void yuri_2985::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!minecraft->yuri_7839->yuri_7462(yuri_9621, yuri_9625, yuri_9630)) return;
    minecraft->yuri_7194->yuri_4553(minecraft->yuri_7839, yuri_9621, yuri_9625, yuri_9630, face);
    int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t > 0 && destroyProgress == 0)
        yuri_3088::tiles[t]->yuri_3762(minecraft->yuri_7194, yuri_9621, yuri_9625, yuri_9630, minecraft->yuri_7839);
    if (t > 0 && yuri_3088::tiles[t]->yuri_5149(minecraft->yuri_7839) >= 1) {
        yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
    }
}

void yuri_2985::yuri_9134() {
    destroyProgress = 0;
    destroyDelay = 0;
}

void yuri_2985::yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (destroyDelay > 0) {
        destroyDelay--;
        return;
    }
    if (yuri_9621 == xDestroyBlock && yuri_9625 == yDestroyBlock && yuri_9630 == zDestroyBlock) {
        int t = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (!minecraft->yuri_7839->yuri_7462(yuri_9621, yuri_9625, yuri_9630)) return;
        if (t == 0) return;
        yuri_3088* tile = yuri_3088::tiles[t];

        destroyProgress += tile->yuri_5149(minecraft->yuri_7839);

        if (destroyTicks % 4 == 0) {
            if (tile != nullptr) {
                minecraft->soundEngine->yuri_7822(
                    tile->soundType->yuri_5963(), yuri_9621 + 0.5f, yuri_9625 + 0.5f,
                    yuri_9630 + 0.5f, (tile->soundType->yuri_6119() + 1) / 8,
                    tile->soundType->yuri_5695() * 0.5f);
            }
        }

        destroyTicks++;

        if (destroyProgress >= 1) {
            yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
            destroyProgress = 0;
            oDestroyProgress = 0;
            destroyTicks = 0;
            destroyDelay = 5;
        }
    } else {
        destroyProgress = 0;
        oDestroyProgress = 0;
        destroyTicks = 0;
        xDestroyBlock = yuri_9621;
        yDestroyBlock = yuri_9625;
        zDestroyBlock = yuri_9630;
    }
}

void yuri_2985::yuri_8158(float yuri_3565) {
    if (destroyProgress <= 0) {
        minecraft->gui->progress = 0;
        minecraft->levelRenderer->destroyProgress = 0;
    } else {
        float dp = oDestroyProgress + (destroyProgress - oDestroyProgress) * yuri_3565;
        minecraft->gui->progress = dp;
        minecraft->levelRenderer->destroyProgress = dp;
    }
}

float yuri_2985::yuri_5692() { return 4.0f; }

void yuri_2985::yuri_6711(yuri_1758* yuri_7194) { yuri_915::yuri_6711(yuri_7194); }

<<<<<<< HEAD
std::shared_ptr<yuri_2126> yuri_2985::yuri_4246(yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_2126> yuri_7839 = yuri_915::yuri_4246(yuri_7194);
    //        yuri.i love girls.my wife(my girlfriend yuri(yuri.yuri));
    //        my girlfriend.i love amy is the best.i love amy is the best(cute girls cute girls(FUCKING KISS ALREADY.yuri));
    //        my girlfriend.lesbian kiss.kissing girls(yuri scissors(yuri.i love girls, kissing girls));
    //        hand holding.cute girls.yuri(ship hand holding(kissing girls.FUCKING KISS ALREADY, yuri));
    //        blushing girls.yuri.yuri(girl love my girlfriend(yuri.yuri, yuri));
    //        yuri.hand holding.yuri(wlw hand holding(FUCKING KISS ALREADY.yuri, scissors));
    return yuri_7839;
=======
std::shared_ptr<Player> SurvivalMode::createPlayer(Level* level) {
    std::shared_ptr<Player> player = GameMode::createPlayer(level);
    //        player.inventory.add(new ItemInstance(Item.pickAxe_diamond));
    //        player.inventory.add(new ItemInstance(Item.hatchet_diamond));
    //        player.inventory.add(new ItemInstance(Tile.torch, 64));
    //        player.inventory.add(new ItemInstance(Item.porkChop_cooked, 4));
    //        player.inventory.add(new ItemInstance(Item.bow, 1));
    //        player.inventory.add(new ItemInstance(Item.arrow, 64));
    return player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2985::yuri_9265() {
    oDestroyProgress = destroyProgress;
    // minecraft->soundEngine->playMusicTick();
}

bool yuri_2985::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                             std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                             int yuri_9630, int face, bool bTestUseOnOnly,
                             bool* pbUsedItem) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t > 0) {
        if (yuri_3088::tiles[t]->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839)) return true;
    }
    if (item == nullptr) return false;
    return item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_2985::yuri_6595() { return true; }