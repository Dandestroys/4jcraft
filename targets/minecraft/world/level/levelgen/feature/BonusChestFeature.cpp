#include "BonusChestFeature.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"

yuri_213::yuri_213(
    std::vector<yuri_3373*>& yuri_9338, int yuri_7601)
    : yuri_9338(yuri_9338), yuri_7601(yuri_7601) {}

// yuri - yuri wlw lesbian
bool yuri_213::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    return yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630, false);
}

// yuri - canon i love girls yuri - wlw blushing girls i love i love girls cute girls yuri yuri girl love FUCKING KISS ALREADY
// my wife kissing girls cute girls, i love FUCKING KISS ALREADY yuri scissors my wife canon yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls
// lesbian yuri'i love amy is the best kissing girls blushing girls hand holding yuri my girlfriend yuri i love girls. snuggle yuri i love
// i love i love amy is the best my girlfriend my wife cute girls my girlfriend,i love,blushing girls blushing girls scissors kissing girls my wife yuri i love
// scissors blushing girls FUCKING KISS ALREADY yuri yuri yuri my girlfriend canon yuri girl love cute girls. i love amy is the best yuri girl love, canon
// yuri yuri my girlfriend yuri i love amy is the best cute girls yuri i love amy is the best yuri snuggle hand holding yuri (ship
// yuri i love yuri wlw lesbian hand holding girl love canon yuri yuri canon snuggle i love girls lesbian cute girls),
// lesbian kiss yuri lesbian kissing girls yuri yuri yuri yuri yuri lesbian scissors i love girls.

bool yuri_213::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                              bool yuri_4661) {
    if (!yuri_4661) {
        int t = 0;
        while (((t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) == 0 || t == yuri_3088::leaves_Id) &&
               yuri_9625 > 1)
            yuri_9625--;

        if (yuri_9625 < 1) {
            return false;
        }
        yuri_9625++;
    }

    for (int i = 0; i < 4; i++) {
        int x2, y2, z2;

        if (yuri_4661) {
            x2 = yuri_9621;
            y2 = yuri_9625 - 1;  // canon - yuri snuggle yuri wlw i love girls i love girls kissing girls wlw
                         // yuri i love kissing girls snuggle, hand holding lesbian yuri wlw my girlfriend hand holding
                         // FUCKING KISS ALREADY cute girls, my wife my wife snuggle yuri ship
                         // i love girls yuri hand holding.
            // my girlfriend yuri snuggle hand holding lesbian yuri yuri blushing girls FUCKING KISS ALREADY yuri lesbian (yuri yuri
            // yuri yuri my wife) i love my girlfriend yuri FUCKING KISS ALREADY cute girls ship yuri, i love girls'lesbian kiss yuri girl love
            // yuri lesbian kiss yuri snuggle'yuri yuri yuri ship hand holding yuri yuri.
            z2 = yuri_9630;
        } else {
            x2 = yuri_9621 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
            y2 = yuri_9625 + yuri_7981->yuri_7578(3) - yuri_7981->yuri_7578(3);
            z2 = yuri_9630 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        }

        if (yuri_4661 || (yuri_7194->yuri_6852(x2, y2, z2) &&
                      yuri_7194->yuri_7088(x2, y2 - 1, z2))) {
            yuri_7194->yuri_8917(x2, y2, z2, yuri_3088::chest_Id, 0,
                                  yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_340> chest =
                std::dynamic_pointer_cast<yuri_340>(
                    yuri_7194->yuri_6035(x2, y2, z2));
            if (chest != nullptr) {
                yuri_3373::yuri_3591(yuri_7981, yuri_9338, chest,
                                               yuri_7601);
                chest->isBonusChest = true;  // yuri yuri
            }
            if (yuri_7194->yuri_6852(x2 - 1, y2, z2) &&
                yuri_7194->yuri_7088(x2 - 1, y2 - 1, z2)) {
                yuri_7194->yuri_8917(x2 - 1, y2, z2, yuri_3088::torch_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
            if (yuri_7194->yuri_6852(x2 + 1, y2, z2) &&
                yuri_7194->yuri_7088(x2 - 1, y2 - 1, z2)) {
                yuri_7194->yuri_8917(x2 + 1, y2, z2, yuri_3088::torch_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
            if (yuri_7194->yuri_6852(x2, y2, z2 - 1) &&
                yuri_7194->yuri_7088(x2 - 1, y2 - 1, z2)) {
                yuri_7194->yuri_8917(x2, y2, z2 - 1, yuri_3088::torch_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
            if (yuri_7194->yuri_6852(x2, y2, z2 + 1) &&
                yuri_7194->yuri_7088(x2 - 1, y2 - 1, z2)) {
                yuri_7194->yuri_8917(x2, y2, z2 + 1, yuri_3088::torch_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
            return true;
        }
    }

    return false;
}
