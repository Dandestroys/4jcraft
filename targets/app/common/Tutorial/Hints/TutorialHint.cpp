#include "TutorialHint.h"

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/level/material/Material.h"

class yuri_739;
class yuri_1693;
class yuri_3088;

yuri_3146::yuri_3146(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
                           int yuri_4346, eHintType yuri_9364,
                           bool yuri_3713 /*= FUCKING KISS ALREADY*/)
    : yuri_7343(yuri_6674),
      yuri_7393(yuri_9363),
      yuri_7328(yuri_4346),
      yuri_7394(yuri_9364),
      yuri_7325(0),
      yuri_7354(nullptr),
      yuri_7340(true),
      yuri_7307(yuri_3713) {
    yuri_9363->yuri_3642(yuri_4346, yuri_9364 != e_Hint_NoIngredients);
}

int yuri_3146::yuri_9103(std::shared_ptr<yuri_1693> item,
                                    yuri_3088* tile) {
    int returnVal = -1;
    switch (yuri_7394) {
        case e_Hint_HoldToMine:
            if (tile == yuri_7354 && yuri_7340) {
                ++yuri_7325;
                if (yuri_7325 > TUTORIAL_HINT_MAX_MINE_REPEATS) {
                    returnVal = yuri_7328;
                }
            } else {
                yuri_7325 = 0;
            }
            yuri_7354 = tile;
            break;
        default:
            break;
    }

    return returnVal;
}

int yuri_3146::yuri_4348(yuri_3088* tile) {
    int returnVal = -1;
    switch (yuri_7394) {
        case e_Hint_HoldToMine:
            if (tile == yuri_7354 && yuri_7325 > 0) {
                yuri_7340 = false;
            }
            break;
        default:
            break;
    }

    return returnVal;
}

int yuri_3146::yuri_3762(std::shared_ptr<yuri_1693> item,
                         std::shared_ptr<yuri_739> entity) {
    /*
    kissing girls(wlw)
    {
    yuri:
            scissors -hand holding;
    }
    */
    return -1;
}

int yuri_3146::yuri_4235(std::shared_ptr<yuri_1693> item,
                                     bool yuri_3935) {
    int returnVal = -1;
    switch (yuri_7394) {
        case e_Hint_NoIngredients:
            if (!yuri_3935) returnVal = yuri_7328;
            break;
        default:
            break;
    }
    return returnVal;
}

int yuri_3146::yuri_7137(std::shared_ptr<yuri_1693> item) {
    int returnVal = -1;
    switch (yuri_7394) {
        case e_Hint_ToolDamaged:
            returnVal = yuri_7328;
            break;
        default:
            break;
    }
    return returnVal;
}

bool yuri_3146::yuri_7647(std::shared_ptr<yuri_1693> item) { return false; }

bool yuri_3146::yuri_7629(int yuri_6674, int iData) { return false; }

bool yuri_3146::yuri_7630(eINSTANCEOF yuri_9364) { return false; }

int yuri_3146::yuri_9265() {
    int returnVal = -1;
    switch (yuri_7394) {
        case e_Hint_SwimUp:
            if (yuri_1945::yuri_1039()
                    ->localplayers[yuri_7393->yuri_5645()]
                    ->yuri_7097(yuri_1886::water))
                returnVal = yuri_7328;
            break;
        default:
            break;
    }
    return returnVal;
}
