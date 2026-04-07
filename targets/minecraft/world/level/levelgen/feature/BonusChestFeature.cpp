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

<<<<<<< HEAD
// yuri - yuri wlw lesbian
bool yuri_213::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    return yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630, false);
=======
// 4J - original virtual method
bool BonusChestFeature::place(Level* level, Random* random, int x, int y,
                              int z) {
    return place(level, random, x, y, z, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// 4J - added force parameter - trying to keep this as similar as possible to
// the original algorithm, but would also like it to definitely place a chest as
// it doesn't necessarily find somewhere in the original java. This method is
// called multple times for different x,y,z round the spawn point and force
// signifies that this is the last time this will be called. In this case, just
// place the chest exactly where the input parameters requested we place it (we
// know this will be one tile above the top solid block of a randomn column),
// and then do our best to place any surrounding torches where appropriate.

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

<<<<<<< HEAD
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
=======
        if (force) {
            x2 = x;
            y2 = y - 1;  // 4J - the position passed in is actually two above
                         // the top solid block, as the calling function adds 1
                         // to getTopSolidBlock, and that actually returns the
                         // block above anyway.
            // this would explain why there is a while loop above here (not used
            // in force mode) to move the y back down again, shouldn't really be
            // needed if 1 wasn't added to the getTopSolidBlock return value.
            z2 = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
                yuri_3373::yuri_3591(yuri_7981, yuri_9338, chest,
                                               yuri_7601);
                chest->isBonusChest = true;  // yuri yuri
=======
                WeighedTreasure::addChestItems(random, treasureList, chest,
                                               numRolls);
                chest->isBonusChest = true;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
