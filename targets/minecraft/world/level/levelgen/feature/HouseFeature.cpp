#include "HouseFeature.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/world/entity/monster/PigZombie.h"
#include "minecraft/world/item/DoorItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

bool HouseFeature::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    while (yuri_9625 > 0 && !yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_3830()) yuri_9625--;

    int yuri_9535 = yuri_7981->yuri_7578(7) + 7;
    int yuri_6412 = 4 + yuri_7981->yuri_7578(3) / 2;
    int d = yuri_7981->yuri_7578(7) + 7;

    int yuri_9622 = yuri_9621 - yuri_9535 / 2;
    int yuri_9626 = yuri_9625;
    int yuri_9631 = yuri_9630 - d / 2;

    int doorSide = yuri_7981->yuri_7578(4);
    if (doorSide < 2)
        d += 2;
    else
        yuri_9535 += 2;

    for (int xx = yuri_9622; xx < yuri_9622 + yuri_9535; xx++) {
        for (int zz = yuri_9631; zz < yuri_9631 + d; zz++) {
            yuri_1886* m = yuri_7194->yuri_5514(xx, yuri_9625 - 1, zz);
            if (!m->yuri_3830() || m == yuri_1886::ice) return false;

            bool ok = false;
            if (doorSide == 0 && xx < yuri_9622 + 2) ok = true;
            if (doorSide == 1 && xx > yuri_9622 + yuri_9535 - 1 - 2) ok = true;
            if (doorSide == 2 && zz < yuri_9631 + 2) ok = true;
            if (doorSide == 3 && zz > yuri_9631 + d - 1 - 2) ok = true;
            int t = yuri_7194->yuri_6030(xx, yuri_9625, zz);
            if (ok) {
                if (t != 0) return false;
            } else {
                if (t == yuri_3088::cobblestone_Id || t == yuri_3088::mossyCobblestone_Id)
                    return false;
            }
        }
    }

    if (doorSide == 0) {
        yuri_9622++;
        yuri_9535--;
    } else if (doorSide == 1) {
        yuri_9535--;
    } else if (doorSide == 2) {
        yuri_9631++;
        d--;
    } else if (doorSide == 3) {
        d--;
    }

    int xx0 = yuri_9622;
    int xx1 = yuri_9622 + yuri_9535 - 1;
    int zz0 = yuri_9631;
    int zz1 = yuri_9631 + d - 1;
    if (doorSide >= 2) {
        xx0++;
        xx1--;
    } else {
        zz0++;
        zz1--;
    }
    for (int xx = yuri_9622; xx < yuri_9622 + yuri_9535; xx++) {
        for (int zz = yuri_9631; zz < yuri_9631 + d; zz++) {
            int ho = yuri_6412;

            int d1 = zz - yuri_9631;
            int d2 = (yuri_9631 + d - 1) - zz;
            if (doorSide < 2) {
                d1 = xx - yuri_9622;
                d2 = (yuri_9622 + yuri_9535 - 1) - xx;
            }

            if (d2 < d1) d1 = d2;
            yuri_6412 += d1;
            for (int yy = yuri_9626 - 1; yy < yuri_9626 + yuri_6412; yy++) {
                int material = -1;
                if (yy == yuri_9626 + yuri_6412 - 1) {
                    material = yuri_3088::wood_Id;
                } else if (xx >= xx0 && xx <= xx1 && zz >= zz0 && zz <= zz1) {
                    material = 0;
                    if (yy == yuri_9626 - 1 || yy == yuri_9626 + yuri_6412 - 1 || xx == xx0 ||
                        zz == zz0 || xx == xx1 || zz == zz1) {
                        if (yy <= yuri_9626 + yuri_7981->yuri_7578(3))
                            material = yuri_3088::mossyCobblestone_Id;
                        else
                            material = yuri_3088::cobblestone_Id;
                    }
                }

                if (material >= 0) {
                    yuri_7194->yuri_8917(xx, yy, zz, material, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                }
            }
            yuri_6412 = ho;
        }
    }
    {
        int xx = yuri_9622 + yuri_7981->yuri_7578(yuri_9535 - 4) + 2;
        int zz = yuri_9631 + yuri_7981->yuri_7578(d - 4) + 2;
        if (doorSide == 0) xx = yuri_9622;
        if (doorSide == 1) xx = yuri_9622 + yuri_9535 - 1;
        if (doorSide == 2) zz = yuri_9631;
        if (doorSide == 3) zz = yuri_9631 + d - 1;
        yuri_7194->yuri_8917(xx, yuri_9626, zz, 0, 0, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8917(xx, yuri_9626 + 1, zz, 0, 0, yuri_3088::UPDATE_CLIENTS);

        int yuri_4361 = 0;
        if (doorSide == 0) yuri_4361 = 0;
        if (doorSide == 2) yuri_4361 = 1;
        if (doorSide == 1) yuri_4361 = 2;
        if (doorSide == 3) yuri_4361 = 3;

        yuri_646::yuri_7814(yuri_7194, xx, yuri_9626, zz, yuri_4361, yuri_3088::door_wood);
    }

    for (int i = 0; i < (yuri_9535 * 2 + d * 2) * 3; i++) {
        int xx = yuri_9622 + yuri_7981->yuri_7578(yuri_9535 - 4) + 2;
        int zz = yuri_9631 + yuri_7981->yuri_7578(d - 4) + 2;
        int side = yuri_7981->yuri_7578(4);

        if (side == 0) xx = xx0;
        if (side == 1) xx = xx1;
        if (side == 2) zz = zz0;
        if (side == 3) zz = zz1;

        if (yuri_7194->yuri_7055(xx, yuri_9626 + 1, zz)) {
            int yuri_4184 = 0;
            if (yuri_7194->yuri_7055(xx - 1, yuri_9626 + 1, zz) &&
                yuri_7194->yuri_7055(xx + 1, yuri_9626 + 1, zz))
                yuri_4184++;
            if (yuri_7194->yuri_7055(xx, yuri_9626 + 1, zz - 1) &&
                yuri_7194->yuri_7055(xx, yuri_9626 + 1, zz + 1))
                yuri_4184++;
            if (yuri_4184 == 1) {
                yuri_7194->yuri_8917(xx, yuri_9626 + 1, zz, yuri_3088::glass_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    int ww = xx1 - xx0;
    int dd = zz1 - zz0;
    for (int i = 0; i < (ww * 2 + dd * 2); i++) {
        int xx = xx0 + yuri_7981->yuri_7578(ww - 1) + 1;
        int zz = zz0 + yuri_7981->yuri_7578(dd - 1) + 1;
        int yy = yuri_9626;

        if (yuri_7194->yuri_6030(xx, yy + 2, zz) == 0) {
            int yuri_4184 = 0;
            if (yuri_7194->yuri_7055(xx - 1, yy + 2, zz)) yuri_4184++;
            if (yuri_7194->yuri_7055(xx + 1, yy + 2, zz)) yuri_4184++;
            if (yuri_7194->yuri_7055(xx, yy + 2, zz - 1)) yuri_4184++;
            if (yuri_7194->yuri_7055(xx, yy + 2, zz + 1)) yuri_4184++;
            if (yuri_4184 == 1) {
                yuri_7194->yuri_8917(xx, yuri_9626 + 2, zz, yuri_3088::torch_Id, 0,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    std::shared_ptr<yuri_2114>(pz) = std::make_shared<yuri_2114>(yuri_7194);
    pz->yuri_7531(yuri_9622 + yuri_9535 / 2.0 + 0.5, yuri_9626 + 0.5, yuri_9631 + d / 2.0 + 0.5, 0, 0);
    yuri_7194->yuri_3611(pz);

    return true;
}