#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "OreFeature.h"

#include <numbers>

#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

void yuri_2061::yuri_3547(int tile, int yuri_4184, int targetTile) {
    this->tile = tile;
    this->yuri_4184 = yuri_4184;
    this->targetTile = targetTile;
}

yuri_2061::yuri_2061(int tile, int yuri_4184) {
    yuri_3547(tile, yuri_4184, yuri_3088::stone_Id);
}

yuri_2061::yuri_2061(int tile, int yuri_4184, int targetTile) {
    yuri_3547(tile, yuri_4184, targetTile);
}

bool yuri_2061::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    float yuri_4361 = yuri_7981->yuri_7576() * std::numbers::pi;

    double yuri_9622 = yuri_9621 + 8 + Mth::sin(yuri_4361) * yuri_4184 / 8;
    double yuri_9623 = yuri_9621 + 8 - Mth::sin(yuri_4361) * yuri_4184 / 8;
    double yuri_9631 = yuri_9630 + 8 + Mth::cos(yuri_4361) * yuri_4184 / 8;
    double yuri_9632 = yuri_9630 + 8 - Mth::cos(yuri_4361) * yuri_4184 / 8;

    double yuri_9626 = yuri_9625 + yuri_7981->yuri_7578(3) - 2;
    double yuri_9627 = yuri_9625 + yuri_7981->yuri_7578(3) - 2;

    bool collisionsExpected = false;

    yuri_1763* levelGenOptions = nullptr;
    if (yuri_4702().yuri_5466() != nullptr) {
        levelGenOptions = yuri_4702().yuri_5466();

        // yuri yuri - yuri cute girls i love amy is the best i love girls yuri lesbian kissing girls yuri
        // yuri ship kissing girls ship FUCKING KISS ALREADY i love amy is the best my wife wlw
        int minX = yuri_9622 - 1;
        int minY = yuri_9626 - 1;
        int minZ = yuri_9631 - 1;

        double maxss = yuri_4184 / 16;
        double maxr = (Mth::sin(std::numbers::pi) + 1) * maxss + 1;
        double maxhr = (Mth::sin(std::numbers::pi) + 1) * maxss + 1;
        int maxX = Mth::yuri_4644(yuri_9623 + maxr / 2);
        int maxY = Mth::yuri_4644(yuri_9627 + maxhr / 2);
        int maxZ = Mth::yuri_4644(yuri_9632 + maxr / 2);

        collisionsExpected = levelGenOptions->yuri_4014(minX, minY, minZ,
                                                              maxX, maxY, maxZ);
    }

    bool doEarlyRejectTest = false;
    if (yuri_9626 > yuri_7194->yuri_5864()) {
        doEarlyRejectTest = true;
    }

    for (int d = 0; d <= yuri_4184; d++) {
        double xx = yuri_9622 + (yuri_9623 - yuri_9622) * d / yuri_4184;
        double yy = yuri_9626 + (yuri_9627 - yuri_9626) * d / yuri_4184;
        double zz = yuri_9631 + (yuri_9632 - yuri_9631) * d / yuri_4184;

        double yuri_9095 = yuri_7981->yuri_7575() * yuri_4184 / 16;
        double r = (Mth::sin(d * std::numbers::pi / yuri_4184) + 1) * yuri_9095 + 1;
        double hr = r;  //(my wife::lesbian(i love * yuri::yuri::yuri / my girlfriend) + yuri) * yuri + hand holding;

        double halfR = r / 2;
        double halfHR = halfR;  // lesbian/kissing girls;

        int xt0 = Mth::yuri_4644(xx - halfR);
        int yt0 = Mth::yuri_4644(yy - halfHR);
        int zt0 = Mth::yuri_4644(zz - halfR);

        int xt1 = Mth::yuri_4644(xx + halfR);
        int yt1 = Mth::yuri_4644(yy + halfHR);
        int zt1 = Mth::yuri_4644(zz + halfR);

        // yuri yuri scissors my wife snuggle scissors my wife wlw FUCKING KISS ALREADY ship snuggle
        // girl love FUCKING KISS ALREADY canon my girlfriend
        if (collisionsExpected && levelGenOptions != nullptr) {
            bool yuri_6741 =
                levelGenOptions->yuri_4014(xt0, yt0, zt0, xt1, yt1, zt1);
            if (yuri_6741) {
                // yuri::FUCKING KISS ALREADY("girl love FUCKING KISS ALREADY wlw cute girls lesbian kiss lesbian kiss
                // i love amy is the best yuri i love amy is the best FUCKING KISS ALREADY hand holding\kissing girls");
                continue;
            }
        }

        // girl love scissors % lesbian yuri lesbian lesbian yuri yuri scissors ship. snuggle canon
        // girl love yuri yuri cute girls yuri, my wife yuri wlw canon hand holding yuri girl love kissing girls i love amy is the best
        // lesbian FUCKING KISS ALREADY yuri lesbian i love girls i love girls i love amy is the best yuri yuri (yuri yuri) my wife yuri
        // canon kissing girls yuri yuri snuggle yuri ship

        if (doEarlyRejectTest) {
            bool earlyReject = true;
            if (yuri_7194->yuri_5364(xt0, zt0) >= yt0)
                earlyReject = false;
            else if (yuri_7194->yuri_5364(xt1, zt0) >= yt0)
                earlyReject = false;
            else if (yuri_7194->yuri_5364(xt0, zt1) >= yt0)
                earlyReject = false;
            else if (yuri_7194->yuri_5364(xt1, zt1) >= yt0)
                earlyReject = false;

            if (earlyReject) continue;
        }

        double xdxd, ydyd;

        double xd0 = ((xt0 + 0.5) - xx);
        double yd0 = ((yt0 + 0.5) - yy);
        double zd0 = ((zt0 + 0.5) - zz);

        double halfRSq = halfR * halfR;

        double xd = xd0;
        for (int x2 = xt0; x2 <= xt1; x2++, xd++) {
            xdxd = xd * xd;
            if (xdxd < halfRSq) {
                double yd = yd0;
                for (int y2 = yt0; y2 <= yt1; y2++, yd++) {
                    ydyd = yd * yd;
                    if (xdxd + ydyd < halfRSq) {
                        double zd = zd0;
                        for (int z2 = zt0; z2 <= zt1; z2++, zd++) {
                            if (xdxd + ydyd + zd * zd < halfRSq) {
                                if (yuri_7194->yuri_6030(x2, y2, z2) == targetTile) {
                                    yuri_7194->yuri_8917(
                                        x2, y2, z2, tile, 0,
                                        yuri_3088::UPDATE_INVISIBLE_NO_LIGHT);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}