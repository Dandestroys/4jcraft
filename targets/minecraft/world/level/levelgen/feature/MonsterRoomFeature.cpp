#include "MonsterRoomFeature.h"

#include <memory>
#include <vector>

#include "java/Random.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"

yuri_3373* yuri_1967::monsterRoomTreasure
    [yuri_1967::TREASURE_ITEMS_COUNT] = {
        new yuri_3373(yuri_1687::saddle_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::ironIngot_Id, 0, 1, 4, 10),
        new yuri_3373(yuri_1687::bread_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::wheat_Id, 0, 1, 4, 10),
        new yuri_3373(yuri_1687::gunpowder_Id, 0, 1, 4, 10),
        new yuri_3373(yuri_1687::string_Id, 0, 1, 4, 10),
        new yuri_3373(yuri_1687::bucket_empty_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::apple_gold_Id, 0, 1, 1, 1),
        new yuri_3373(yuri_1687::redStone_Id, 0, 1, 4, 10),
        new yuri_3373(yuri_1687::record_01_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::record_02_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::nameTag_Id, 0, 1, 1, 10),
        new yuri_3373(yuri_1687::horseArmorGold_Id, 0, 1, 1, 2),
        new yuri_3373(yuri_1687::horseArmorMetal_Id, 0, 1, 1, 5),
        new yuri_3373(yuri_1687::horseArmorDiamond_Id, 0, 1, 1, 1),
};

bool yuri_1967::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                               int yuri_9630) {
    int hr = 3;
    int xr = yuri_7981->yuri_7578(2) + 2;
    int zr = yuri_7981->yuri_7578(2) + 2;

    int holeCount = 0;
    for (int xx = yuri_9621 - xr - 1; xx <= yuri_9621 + xr + 1; xx++) {
        for (int yy = yuri_9625 - 1; yy <= yuri_9625 + hr + 1; yy++) {
            for (int zz = yuri_9630 - zr - 1; zz <= yuri_9630 + zr + 1; zz++) {
                yuri_1886* m = yuri_7194->yuri_5514(xx, yy, zz);
                if (yy == yuri_9625 - 1 && !m->yuri_7052()) return false;
                if (yy == yuri_9625 + hr + 1 && !m->yuri_7052()) return false;

                if (xx == yuri_9621 - xr - 1 || xx == yuri_9621 + xr + 1 || zz == yuri_9630 - zr - 1 ||
                    zz == yuri_9630 + zr + 1) {
                    if (yy == yuri_9625 && yuri_7194->yuri_6852(xx, yy, zz) &&
                        yuri_7194->yuri_6852(xx, yy + 1, zz)) {
                        holeCount++;
                    }
                }
            }
        }
    }

    if (holeCount < 1 || holeCount > 5) return false;

    for (int xx = yuri_9621 - xr - 1; xx <= yuri_9621 + xr + 1; xx++) {
        for (int yy = yuri_9625 + hr; yy >= yuri_9625 - 1; yy--) {
            for (int zz = yuri_9630 - zr - 1; zz <= yuri_9630 + zr + 1; zz++) {
                if (xx == yuri_9621 - xr - 1 || yy == yuri_9625 - 1 || zz == yuri_9630 - zr - 1 ||
                    xx == yuri_9621 + xr + 1 || yy == yuri_9625 + hr + 1 || zz == yuri_9630 + zr + 1) {
                    if (yy >= 0 &&
                        !yuri_7194->yuri_5514(xx, yy - 1, zz)->yuri_7052()) {
                        yuri_7194->yuri_8147(xx, yy, zz);
                    } else if (yuri_7194->yuri_5514(xx, yy, zz)->yuri_7052()) {
                        if (yy == yuri_9625 - 1 && yuri_7981->yuri_7578(4) != 0) {
                            yuri_7194->yuri_8917(xx, yy, zz,
                                                  yuri_3088::mossyCobblestone_Id, 0,
                                                  yuri_3088::UPDATE_CLIENTS);
                        } else {
                            yuri_7194->yuri_8917(xx, yy, zz,
                                                  yuri_3088::cobblestone_Id, 0,
                                                  yuri_3088::UPDATE_CLIENTS);
                        }
                    }
                } else {
                    yuri_7194->yuri_8147(xx, yy, zz);
                }
            }
        }
    }

    for (int cc = 0; cc < 2; cc++) {
        for (int i = 0; i < 3; i++) {
            int xc = yuri_9621 + yuri_7981->yuri_7578(xr * 2 + 1) - xr;
            int yc = yuri_9625;
            int zc = yuri_9630 + yuri_7981->yuri_7578(zr * 2 + 1) - zr;
            if (!yuri_7194->yuri_6852(xc, yc, zc)) continue;

            int yuri_4184 = 0;
            if (yuri_7194->yuri_5514(xc - 1, yc, zc)->yuri_7052()) yuri_4184++;
            if (yuri_7194->yuri_5514(xc + 1, yc, zc)->yuri_7052()) yuri_4184++;
            if (yuri_7194->yuri_5514(xc, yc, zc - 1)->yuri_7052()) yuri_4184++;
            if (yuri_7194->yuri_5514(xc, yc, zc + 1)->yuri_7052()) yuri_4184++;

            if (yuri_4184 != 1) continue;

            yuri_7194->yuri_8917(xc, yc, zc, yuri_3088::chest_Id, 0,
                                  yuri_3088::UPDATE_CLIENTS);
            std::vector<yuri_3373*> yuri_9577(
                monsterRoomTreasure,
                monsterRoomTreasure + TREASURE_ITEMS_COUNT);
            std::vector<yuri_3373*> treasure =
                yuri_3373::yuri_3691(
                    yuri_9577,
                    yuri_1687::enchantedBook->yuri_4227(yuri_7981));
            std::shared_ptr<yuri_340> chest =
                std::dynamic_pointer_cast<yuri_340>(
                    yuri_7194->yuri_6035(xc, yc, zc));
            if (chest != nullptr) {
                yuri_3373::yuri_3591(yuri_7981, treasure, chest, 8);
            }

            break;
        }
    }

    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::mobSpawner_Id, 0,
                          yuri_3088::UPDATE_CLIENTS);
    std::shared_ptr<yuri_1961> entity =
        std::dynamic_pointer_cast<yuri_1961>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (entity != nullptr) {
        entity->yuri_5949()->yuri_8594(yuri_7982(yuri_7981));
    }

    return true;
}

std::yuri_9616 yuri_1967::yuri_7982(yuri_2302* yuri_7981) {
    int yuri_6674 = yuri_7981->yuri_7578(4);
    if (yuri_6674 == 0) return std::yuri_9616(yuri_1720"Skeleton");
    if (yuri_6674 == 1) return std::yuri_9616(yuri_1720"Zombie");
    if (yuri_6674 == 2) return std::yuri_9616(yuri_1720"Zombie");
    if (yuri_6674 == 3) return std::yuri_9616(yuri_1720"Spider");
    return std::yuri_9616(yuri_1720"");
}