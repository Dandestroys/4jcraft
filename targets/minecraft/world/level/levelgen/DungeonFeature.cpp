#include "DungeonFeature.h"

#include <numbers>
#include <vector>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

void DungeonFeature::yuri_3670(int xOffs, int zOffs, std::vector<yuri_9368>& blocks,
                             double xRoom, double yRoom, double zRoom) {
    yuri_3692(xOffs, zOffs, blocks, xRoom, yRoom, zRoom,
              1 + yuri_7981->yuri_7576() * 6, 0, 0, -1, -1, 0.5);
}

void DungeonFeature::yuri_3692(int xOffs, int zOffs,
                               std::vector<yuri_9368>& blocks, double xCave,
                               double yCave, double zCave, float thickness,
                               float yuri_9628, float yuri_9624, int step, int yuri_4382,
                               double yScale) {
    double xMid = xOffs * 16 + 8;
    double zMid = zOffs * 16 + 8;

    float yRota = 0;
    float xRota = 0;
    yuri_2302* yuri_7981 = new yuri_2302(this->yuri_7981->yuri_7579());

    if (yuri_4382 <= 0) {
        int yuri_7459 = radius * 16 - 16;
        yuri_4382 = yuri_7459 - yuri_7981->yuri_7578(yuri_7459 / 4);
    }
    bool singleStep = false;

    if (step == -1) {
        step = yuri_4382 / 2;
        singleStep = true;
    }

    int splitPoint = yuri_7981->yuri_7578(yuri_4382 / 2) + yuri_4382 / 4;
    bool steep = yuri_7981->yuri_7578(6) == 0;

    for (; step < yuri_4382; step++) {
        double rad =
            1.5 + (Mth::sin(step * std::numbers::pi / yuri_4382) * thickness) * 1;
        double yRad = rad * yScale;

        float xc = Mth::cos(yuri_9624);
        float xs = Mth::sin(yuri_9624);
        xCave += Mth::cos(yuri_9628) * xc;
        yCave += xs;
        zCave += Mth::sin(yuri_9628) * xc;

        if (steep) {
            yuri_9624 *= 0.92f;
        } else {
            yuri_9624 *= 0.7f;
        }
        yuri_9624 += xRota * 0.1f;
        yuri_9628 += yRota * 0.1f;

        xRota *= 0.90f;
        yRota *= 0.75f;
        xRota += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) *
                 yuri_7981->yuri_7576() * 2;
        yRota += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) *
                 yuri_7981->yuri_7576() * 4;

        if (!singleStep && step == splitPoint && thickness > 1) {
            yuri_3692(xOffs, zOffs, blocks, xCave, yCave, zCave,
                      yuri_7981->yuri_7576() * 0.5f + 0.5f,
                      yuri_9628 - std::numbers::pi / 2, yuri_9624 / 3, step, yuri_4382, 1.0);
            yuri_3692(xOffs, zOffs, blocks, xCave, yCave, zCave,
                      yuri_7981->yuri_7576() * 0.5f + 0.5f,
                      yuri_9628 + std::numbers::pi / 2, yuri_9624 / 3, step, yuri_4382, 1.0);
            return;
        }
        if (!singleStep && yuri_7981->yuri_7578(4) == 0) continue;

        {
            double xd = xCave - xMid;
            double zd = zCave - zMid;
            double yuri_8095 = yuri_4382 - step;
            double rr = (thickness + 2) + 16;
            if (xd * xd + zd * zd - (yuri_8095 * yuri_8095) > rr * rr) {
                return;
            }
        }

        if (xCave < xMid - 16 - rad * 2 || zCave < zMid - 16 - rad * 2 ||
            xCave > xMid + 16 + rad * 2 || zCave > zMid + 16 + rad * 2)
            continue;

        int yuri_9622 = Mth::yuri_4644(xCave - rad) - xOffs * 16 - 1;
        int yuri_9623 = Mth::yuri_4644(xCave + rad) - xOffs * 16 + 1;

        int yuri_9626 = Mth::yuri_4644(yCave - yRad) - 1;
        int yuri_9627 = Mth::yuri_4644(yCave + yRad) + 1;

        int yuri_9631 = Mth::yuri_4644(zCave - rad) - zOffs * 16 - 1;
        int yuri_9632 = Mth::yuri_4644(zCave + rad) - zOffs * 16 + 1;

        if (yuri_9622 < 0) yuri_9622 = 0;
        if (yuri_9623 > 16) yuri_9623 = 16;

        if (yuri_9626 < 1) yuri_9626 = 1;
        if (yuri_9627 > yuri_1758::genDepth - 8) yuri_9627 = yuri_1758::genDepth - 8;

        if (yuri_9631 < 0) yuri_9631 = 0;
        if (yuri_9632 > 16) yuri_9632 = 16;

        bool detectedWater = false;
        for (int xx = yuri_9622; !detectedWater && xx < yuri_9623; xx++) {
            for (int zz = yuri_9631; !detectedWater && zz < yuri_9632; zz++) {
                for (int yy = yuri_9627 + 1; !detectedWater && yy >= yuri_9626 - 1; yy--) {
                    int yuri_7701 = (xx * 16 + zz) * yuri_1758::genDepth + yy;
                    if (yy < 0 || yy >= yuri_1758::genDepth) continue;
                    if (blocks[yuri_7701] == yuri_3088::water_Id ||
                        blocks[yuri_7701] == yuri_3088::calmWater_Id) {
                        detectedWater = true;
                    }
                    if (yy != yuri_9626 - 1 && xx != yuri_9622 && xx != yuri_9623 - 1 && zz != yuri_9631 &&
                        zz != yuri_9632 - 1) {
                        yy = yuri_9626;
                    }
                }
            }
        }
        if (detectedWater) continue;

        for (int xx = yuri_9622; xx < yuri_9623; xx++) {
            double xd = ((xx + xOffs * 16 + 0.5) - xCave) / rad;
            for (int zz = yuri_9631; zz < yuri_9632; zz++) {
                double zd = ((zz + zOffs * 16 + 0.5) - zCave) / rad;
                int yuri_7701 = (xx * 16 + zz) * yuri_1758::genDepth + yuri_9627;
                bool hasGrass = false;
                for (int yy = yuri_9627 - 1; yy >= yuri_9626; yy--) {
                    double yd = (yy + 0.5 - yCave) / yRad;
                    if (yd > -0.7 && xd * xd + yd * yd + zd * zd < 1) {
                        int block = blocks[yuri_7701];
                        if (block == yuri_3088::grass_Id) hasGrass = true;
                        if (block == yuri_3088::stone_Id || block == yuri_3088::dirt_Id ||
                            block == yuri_3088::grass_Id) {
                            if (yy < 10) {
                                blocks[yuri_7701] = (yuri_9368)yuri_3088::lava_Id;
                            } else {
                                blocks[yuri_7701] = (yuri_9368)0;
                                if (hasGrass && blocks[yuri_7701 - 1] == yuri_3088::dirt_Id)
                                    blocks[yuri_7701 - 1] = (yuri_9368)yuri_3088::grass_Id;
                            }
                        }
                    }
                    yuri_7701--;
                }
            }
        }
        if (singleStep) break;
    }
}

void DungeonFeature::yuri_3613(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int xOffs,
                                int zOffs, std::vector<yuri_9368>& blocks) {
    int caves = yuri_7981->yuri_7578(yuri_7981->yuri_7578(yuri_7981->yuri_7578(40) + 1) + 1);
    if (yuri_7981->yuri_7578(15) != 0) caves = 0;

    for (int cave = 0; cave < caves; cave++) {
        double xCave = yuri_9621 * 16 + yuri_7981->yuri_7578(16);
        double yCave =
            yuri_7981->yuri_7578(yuri_7981->yuri_7578(yuri_1758::genDepth - 8) + 8);
        double zCave = yuri_9630 * 16 + yuri_7981->yuri_7578(16);

        int tunnels = 1;
        if (yuri_7981->yuri_7578(4) == 0) {
            yuri_3670(xOffs, zOffs, blocks, xCave, yCave, zCave);
            tunnels += yuri_7981->yuri_7578(4);
        }

        for (int i = 0; i < tunnels; i++) {
            float yuri_9628 = yuri_7981->yuri_7576() * std::numbers::pi * 2;
            float yuri_9624 = ((yuri_7981->yuri_7576() - 0.5f) * 2) / 8;
            float thickness = yuri_7981->yuri_7576() * 2 + yuri_7981->yuri_7576();

            yuri_3692(xOffs, zOffs, blocks, xCave, yCave, zCave, thickness,
                      yuri_9628, yuri_9624, 0, 0, 1.0);
        }
    }
}