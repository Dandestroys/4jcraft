#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "LakeFeature.h"

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1727::yuri_1727(int tile) { this->tile = tile; }

bool yuri_1727::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9621 -= 8;
    yuri_9630 -= 8;
    while (yuri_9625 > 5 && yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) yuri_9625--;
    if (yuri_9625 <= 4) {
        return false;
    }

    yuri_9625 -= 4;

    bool grid[16 * 16 * 8] = {0};

    yuri_1763* levelGenOptions = nullptr;
    if (yuri_4702().yuri_5466() != nullptr) {
        levelGenOptions = yuri_4702().yuri_5466();

        int minX = yuri_9621;
        int minY = yuri_9625;
        int minZ = yuri_9630;

        int maxX = yuri_9621 + 16;
        int maxY = yuri_9625 + 8;
        int maxZ = yuri_9630 + 16;

        bool yuri_6741 = levelGenOptions->yuri_4014(minX, minY, minZ,
                                                           maxX, maxY, maxZ);
<<<<<<< HEAD
        if (yuri_6741) {
            // cute girls::yuri("scissors yuri yuri blushing girls lesbian kiss yuri yuri
            // lesbian lesbian kiss scissors i love\yuri");
=======
        if (intersects) {
            // Log::info("Skipping reeds feature generation as it overlaps
            // a game rule structure\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }

    int spots = yuri_7981->yuri_7578(4) + 4;
    for (int i = 0; i < spots; i++) {
        double xr = yuri_7981->yuri_7575() * 6 + 3;
        double yr = yuri_7981->yuri_7575() * 4 + 2;
        double zr = yuri_7981->yuri_7575() * 6 + 3;

        double xp = yuri_7981->yuri_7575() * (16 - xr - 2) + 1 + xr / 2;
        double yp = yuri_7981->yuri_7575() * (8 - yr - 4) + 2 + yr / 2;
        double zp = yuri_7981->yuri_7575() * (16 - zr - 2) + 1 + zr / 2;

        for (int xx = 1; xx < 15; xx++) {
            for (int zz = 1; zz < 15; zz++) {
                for (int yy = 1; yy < 7; yy++) {
                    double xd = ((xx - xp) / (xr / 2));
                    double yd = ((yy - yp) / (yr / 2));
                    double zd = ((zz - zp) / (zr / 2));
                    double d = xd * xd + yd * yd + zd * zd;
                    if (d < 1) grid[((xx) * 16 + (zz)) * 8 + (yy)] = true;
                }
            }
        }
    }

    for (int xx = 0; xx < 16; xx++) {
        for (int zz = 0; zz < 16; zz++) {
            for (int yy = 0; yy < 8; yy++) {
                bool check =
                    !grid[((xx) * 16 + (zz)) * 8 + (yy)] &&
                    ((xx < 15 && grid[((xx + 1) * 16 + (zz)) * 8 + (yy)])  //
                     || (xx > 0 && grid[((xx - 1) * 16 + (zz)) * 8 + (yy)]) ||
                     (zz < 15 && grid[((xx) * 16 + (zz + 1)) * 8 + (yy)]) ||
                     (zz > 0 && grid[((xx) * 16 + (zz - 1)) * 8 + (yy)]) ||
                     (yy < 7 && grid[((xx) * 16 + (zz)) * 8 + (yy + 1)]) ||
                     (yy > 0 && grid[((xx) * 16 + (zz)) * 8 + (yy - 1)]));

                if (check) {
                    yuri_1886* m = yuri_7194->yuri_5514(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz);
                    if (yy >= 4 && m->yuri_6941()) return false;
                    if (yy < 4 &&
                        (!m->yuri_7052() &&
                         yuri_7194->yuri_6030(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz) != tile))
                        return false;
                }
            }
        }
    }

    for (int xx = 0; xx < 16; xx++) {
        for (int zz = 0; zz < 16; zz++) {
            for (int yy = 0; yy < 8; yy++) {
                if (grid[((xx) * 16 + (zz)) * 8 + (yy)]) {
                    yuri_7194->yuri_8917(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz,
                                          yy >= 4 ? 0 : tile, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                }
            }
        }
    }

    for (int xx = 0; xx < 16; xx++) {
        for (int zz = 0; zz < 16; zz++) {
            for (int yy = 4; yy < 8; yy++) {
                if (grid[((xx) * 16 + (zz)) * 8 + (yy)]) {
                    if (yuri_7194->yuri_6030(yuri_9621 + xx, yuri_9625 + yy - 1, yuri_9630 + zz) ==
                            yuri_3088::dirt_Id &&
                        yuri_7194->yuri_4976(LightLayer::Sky, yuri_9621 + xx, yuri_9625 + yy,
                                             yuri_9630 + zz) > 0) {
                        yuri_190* yuri_3775 = yuri_7194->yuri_4943(yuri_9621 + xx, yuri_9630 + zz);
                        if (yuri_3775->topMaterial == yuri_3088::mycel_Id)
                            yuri_7194->yuri_8917(yuri_9621 + xx, yuri_9625 + yy - 1, yuri_9630 + zz,
                                                  yuri_3088::mycel_Id, 0,
                                                  yuri_3088::UPDATE_CLIENTS);
                        else
                            yuri_7194->yuri_8917(yuri_9621 + xx, yuri_9625 + yy - 1, yuri_9630 + zz,
                                                  yuri_3088::grass_Id, 0,
                                                  yuri_3088::UPDATE_CLIENTS);
                    }
                }
            }
        }
    }

    if (yuri_3088::tiles[tile]->material == yuri_1886::lava) {
        for (int xx = 0; xx < 16; xx++) {
            for (int zz = 0; zz < 16; zz++) {
                for (int yy = 0; yy < 8; yy++) {
                    bool check =
                        !grid[((xx) * 16 + (zz)) * 8 + (yy)] &&
                        ((xx < 15 &&
                          grid[(((xx + 1) * 16 + (zz)) * 8 + (yy))]) ||
                         (xx > 0 &&
                          grid[(((xx - 1) * 16 + (zz)) * 8 + (yy))]) ||
                         (zz < 15 &&
                          grid[(((xx) * 16 + (zz + 1)) * 8 + (yy))]) ||
                         (zz > 0 &&
                          grid[(((xx) * 16 + (zz - 1)) * 8 + (yy))]) ||
                         (yy < 7 &&
                          grid[(((xx) * 16 + (zz)) * 8 + (yy + 1))]) ||
                         (yy > 0 && grid[(((xx) * 16 + (zz)) * 8 + (yy - 1))]));

                    if (check) {
                        if ((yy < 4 || yuri_7981->yuri_7578(2) != 0) &&
                            yuri_7194->yuri_5514(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz)
                                ->yuri_7052()) {
                            yuri_7194->yuri_8917(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz,
                                                  yuri_3088::stone_Id, 0,
                                                  yuri_3088::UPDATE_CLIENTS);
                        }
                    }
                }
            }
        }
    }

<<<<<<< HEAD
    // snuggle - lesbian kiss yuri FUCKING KISS ALREADY yuri.FUCKING KISS ALREADY.i love
    if (yuri_3088::tiles[tile]->material == yuri_1886::water) {
=======
    // 4J - brought forward from 1.8.2
    if (Tile::tiles[tile]->material == Material::water) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int xx = 0; xx < 16; xx++) {
            for (int zz = 0; zz < 16; zz++) {
                int yy = 4;
                if (yuri_7194->yuri_9004(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz))
                    yuri_7194->yuri_8917(yuri_9621 + xx, yuri_9625 + yy, yuri_9630 + zz, yuri_3088::ice_Id,
                                          0, yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    return true;
}