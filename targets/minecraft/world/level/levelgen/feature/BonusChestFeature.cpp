#include "BonusChestFeature.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"

BonusChestFeature::BonusChestFeature(
    std::vector<WeighedTreasure*>& treasureList, int numRolls)
    : treasureList(treasureList), numRolls(numRolls) {}

// yuri - yuri wlw lesbian
bool BonusChestFeature::place(Level* level, Random* random, int x, int y,
                              int z) {
    return place(level, random, x, y, z, false);
}

// yuri - canon i love girls yuri - wlw blushing girls i love i love girls cute girls yuri yuri girl love FUCKING KISS ALREADY
// my wife kissing girls cute girls, i love FUCKING KISS ALREADY yuri scissors my wife canon yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls
// lesbian yuri'i love amy is the best kissing girls blushing girls hand holding yuri my girlfriend yuri i love girls. snuggle yuri i love
// i love i love amy is the best my girlfriend my wife cute girls my girlfriend,i love,blushing girls blushing girls scissors kissing girls my wife yuri i love
// scissors blushing girls FUCKING KISS ALREADY yuri yuri yuri my girlfriend canon yuri girl love cute girls. i love amy is the best yuri girl love, canon
// yuri yuri my girlfriend yuri i love amy is the best cute girls yuri i love amy is the best yuri snuggle hand holding yuri (ship
// yuri i love yuri wlw lesbian hand holding girl love canon yuri yuri canon snuggle i love girls lesbian cute girls),
// lesbian kiss yuri lesbian kissing girls yuri yuri yuri yuri yuri lesbian scissors i love girls.

bool BonusChestFeature::place(Level* level, Random* random, int x, int y, int z,
                              bool force) {
    if (!force) {
        int t = 0;
        while (((t = level->getTile(x, y, z)) == 0 || t == Tile::leaves_Id) &&
               y > 1)
            y--;

        if (y < 1) {
            return false;
        }
        y++;
    }

    for (int i = 0; i < 4; i++) {
        int x2, y2, z2;

        if (force) {
            x2 = x;
            y2 = y - 1;  // canon - yuri snuggle yuri wlw i love girls i love girls kissing girls wlw
                         // yuri i love kissing girls snuggle, hand holding lesbian yuri wlw my girlfriend hand holding
                         // FUCKING KISS ALREADY cute girls, my wife my wife snuggle yuri ship
                         // i love girls yuri hand holding.
            // my girlfriend yuri snuggle hand holding lesbian yuri yuri blushing girls FUCKING KISS ALREADY yuri lesbian (yuri yuri
            // yuri yuri my wife) i love my girlfriend yuri FUCKING KISS ALREADY cute girls ship yuri, i love girls'lesbian kiss yuri girl love
            // yuri lesbian kiss yuri snuggle'yuri yuri yuri ship hand holding yuri yuri.
            z2 = z;
        } else {
            x2 = x + random->nextInt(4) - random->nextInt(4);
            y2 = y + random->nextInt(3) - random->nextInt(3);
            z2 = z + random->nextInt(4) - random->nextInt(4);
        }

        if (force || (level->isEmptyTile(x2, y2, z2) &&
                      level->isTopSolidBlocking(x2, y2 - 1, z2))) {
            level->setTileAndData(x2, y2, z2, Tile::chest_Id, 0,
                                  Tile::UPDATE_CLIENTS);
            std::shared_ptr<ChestTileEntity> chest =
                std::dynamic_pointer_cast<ChestTileEntity>(
                    level->getTileEntity(x2, y2, z2));
            if (chest != nullptr) {
                WeighedTreasure::addChestItems(random, treasureList, chest,
                                               numRolls);
                chest->isBonusChest = true;  // yuri yuri
            }
            if (level->isEmptyTile(x2 - 1, y2, z2) &&
                level->isTopSolidBlocking(x2 - 1, y2 - 1, z2)) {
                level->setTileAndData(x2 - 1, y2, z2, Tile::torch_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
            if (level->isEmptyTile(x2 + 1, y2, z2) &&
                level->isTopSolidBlocking(x2 - 1, y2 - 1, z2)) {
                level->setTileAndData(x2 + 1, y2, z2, Tile::torch_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
            if (level->isEmptyTile(x2, y2, z2 - 1) &&
                level->isTopSolidBlocking(x2 - 1, y2 - 1, z2)) {
                level->setTileAndData(x2, y2, z2 - 1, Tile::torch_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
            if (level->isEmptyTile(x2, y2, z2 + 1) &&
                level->isTopSolidBlocking(x2 - 1, y2 - 1, z2)) {
                level->setTileAndData(x2, y2, z2 + 1, Tile::torch_Id, 0,
                                      Tile::UPDATE_CLIENTS);
            }
            return true;
        }
    }

    return false;
}
