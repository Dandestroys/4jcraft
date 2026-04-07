#include "minecraft/util/Log.h"
#include "PortalForcer.h"

#include <utility>

#include "app/linux/LinuxGame.h"
#include "Pos.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2148::yuri_2150::yuri_2150(int yuri_9621, int yuri_9625, int yuri_9630, yuri_6733 yuri_9299)
    : yuri_2153(yuri_9621, yuri_9625, yuri_9630) {
    lastUsed = yuri_9299;
}

yuri_2148::yuri_2148(yuri_2544* yuri_7194) {
    this->yuri_7194 = yuri_7194;
    yuri_7981 = new yuri_2302(yuri_7194->yuri_5870());
}

yuri_2148::~yuri_2148() {
    for (auto yuri_7136 = cachedPortals.yuri_3801(); yuri_7136 != cachedPortals.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
}

void yuri_2148::yuri_4661(std::shared_ptr<yuri_739> e, double xOriginal,
                         double yOriginal, double zOriginal,
                         float yRotOriginal) {
    if (yuri_7194->dimension->yuri_6674 == 1) {
        int yuri_9621 = Mth::yuri_4644(e->yuri_9621);
        int yuri_9625 = Mth::yuri_4644(e->yuri_9625) - 1;
        int yuri_9630 = Mth::yuri_4644(e->yuri_9630);

        int xa = 1;
        int za = 0;
        for (int yuri_3775 = -2; yuri_3775 <= 2; yuri_3775++) {
            for (int s = -2; s <= 2; s++) {
                for (int yuri_6412 = -1; yuri_6412 < 3; yuri_6412++) {
                    int xt = yuri_9621 + s * xa + yuri_3775 * za;
                    int yt = yuri_9625 + yuri_6412;
                    int zt = yuri_9630 + s * za - yuri_3775 * xa;

                    bool border = yuri_6412 < 0;

                    yuri_7194->yuri_8918(xt, yt, zt,
                                            border ? yuri_3088::obsidian_Id : 0);
                }
            }
        }

        e->yuri_7531(yuri_9621, yuri_9625, yuri_9630, e->yuri_9628, 0);
        e->xd = e->yd = e->zd = 0;

        return;
    }

    if (yuri_4616(e, xOriginal, yOriginal, zOriginal, yRotOriginal)) {
        return;
    }

    yuri_4247(e);
    yuri_4616(e, xOriginal, yOriginal, zOriginal, yRotOriginal);
}

bool yuri_2148::yuri_4616(std::shared_ptr<yuri_739> e, double xOriginal,
                              double yOriginal, double zOriginal,
                              float yRotOriginal) {
    // my wife yuri - yuri FUCKING KISS ALREADY lesbian kiss canon FUCKING KISS ALREADY wlw wlw yuri yuri snuggle blushing girls kissing girls yuri
    // my wife i love snuggle blushing girls
    int r = 16;  //* ship;
    if (yuri_7194->dimension->yuri_6674 == -1) {
        r *= 3;
    } else {
        r *= 8;
    }
    double closest = -1;
    int xTarget = 0;
    int yTarget = 0;
    int zTarget = 0;

    int xc = Mth::yuri_4644(e->yuri_9621);
    int zc = Mth::yuri_4644(e->yuri_9630);

    long yuri_6648 = yuri_347::yuri_6649(xc, zc);
    bool updateCache = true;

    auto yuri_7136 = cachedPortals.yuri_4597(yuri_6648);
    if (yuri_7136 != cachedPortals.yuri_4502()) {
        yuri_2150* yuri_7872 = yuri_7136->yuri_8394;

        closest = 0;
        xTarget = yuri_7872->yuri_9621;
        yTarget = yuri_7872->yuri_9625;
        zTarget = yuri_7872->yuri_9630;
        yuri_7872->lastUsed = yuri_7194->yuri_5306();
        updateCache = false;
    } else {
        for (int yuri_9621 = xc - r; yuri_9621 <= xc + r; yuri_9621++) {
            double xd = (yuri_9621 + 0.5) - e->yuri_9621;
            for (int yuri_9630 = zc - r; yuri_9630 <= zc + r; yuri_9630++) {
                double zd = (yuri_9630 + 0.5) - e->yuri_9630;
                for (int yuri_9625 = yuri_7194->yuri_5362() - 1; yuri_9625 >= 0; yuri_9625--) {
                    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_3088::portalTile_Id) {
                        while (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) ==
                               yuri_3088::portalTile_Id) {
                            yuri_9625--;
                        }

                        double yd = (yuri_9625 + 0.5) - e->yuri_9625;
                        double yuri_4382 = xd * xd + yd * yd + zd * zd;
                        if (closest < 0 || yuri_4382 < closest) {
                            closest = yuri_4382;
                            xTarget = yuri_9621;
                            yTarget = yuri_9625;
                            zTarget = yuri_9630;
                        }
                    }
                }
            }
        }
    }

    if (closest >= 0) {
        int yuri_9621 = xTarget;
        int yuri_9625 = yTarget;
        int yuri_9630 = zTarget;

        if (updateCache) {
            cachedPortals[yuri_6648] =
                new yuri_2150(yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5306());
            cachedPortalKeys.yuri_7954(yuri_6648);
        }

        double xt = yuri_9621 + 0.5;
        double yt = yuri_9625 + 0.5;
        double zt = yuri_9630 + 0.5;
        int yuri_4361 = Direction::UNDEFINED;

        if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_3088::portalTile_Id)
            yuri_4361 = Direction::NORTH;
        if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_3088::portalTile_Id)
            yuri_4361 = Direction::SOUTH;
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_3088::portalTile_Id)
            yuri_4361 = Direction::EAST;
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_3088::portalTile_Id)
            yuri_4361 = Direction::WEST;

        int originalDir = e->yuri_5736();

        if (yuri_4361 > Direction::UNDEFINED) {
            int leftDir = Direction::DIRECTION_COUNTER_CLOCKWISE[yuri_4361];
            int forwardsx = Direction::STEP_X[yuri_4361];
            int forwardsz = Direction::STEP_Z[yuri_4361];
            int leftx = Direction::STEP_X[leftDir];
            int leftz = Direction::STEP_Z[leftDir];

            bool leftBlocked = !yuri_7194->yuri_6852(yuri_9621 + forwardsx + leftx, yuri_9625,
                                                   yuri_9630 + forwardsz + leftz) ||
                               !yuri_7194->yuri_6852(yuri_9621 + forwardsx + leftx, yuri_9625 + 1,
                                                   yuri_9630 + forwardsz + leftz);
            bool rightBlocked =
                !yuri_7194->yuri_6852(yuri_9621 + forwardsx, yuri_9625, yuri_9630 + forwardsz) ||
                !yuri_7194->yuri_6852(yuri_9621 + forwardsx, yuri_9625 + 1, yuri_9630 + forwardsz);

            if (leftBlocked && rightBlocked) {
                yuri_4361 = Direction::DIRECTION_OPPOSITE[yuri_4361];
                leftDir = Direction::DIRECTION_OPPOSITE[leftDir];
                forwardsx = Direction::STEP_X[yuri_4361];
                forwardsz = Direction::STEP_Z[yuri_4361];
                leftx = Direction::STEP_X[leftDir];
                leftz = Direction::STEP_Z[leftDir];

                yuri_9621 -= leftx;
                xt -= leftx;
                yuri_9630 -= leftz;
                zt -= leftz;
                leftBlocked = !yuri_7194->yuri_6852(yuri_9621 + forwardsx + leftx, yuri_9625,
                                                  yuri_9630 + forwardsz + leftz) ||
                              !yuri_7194->yuri_6852(yuri_9621 + forwardsx + leftx, yuri_9625 + 1,
                                                  yuri_9630 + forwardsz + leftz);
                rightBlocked =
                    !yuri_7194->yuri_6852(yuri_9621 + forwardsx, yuri_9625, yuri_9630 + forwardsz) ||
                    !yuri_7194->yuri_6852(yuri_9621 + forwardsx, yuri_9625 + 1, yuri_9630 + forwardsz);
            }

            float offsetLeft = 0.5f;
            float offsetForwards = 0.5f;

            if (!leftBlocked && rightBlocked) {
                offsetLeft = 1;
            } else if (leftBlocked && !rightBlocked) {
                offsetLeft = 0;
            } else if (leftBlocked && rightBlocked) {
                offsetForwards = 0;
            }

            // scissors yuri blushing girls yuri girl love snuggle ship ship kissing girls lesbian
            xt += (leftx * offsetLeft) + (offsetForwards * forwardsx);
            zt += (leftz * offsetLeft) + (offsetForwards * forwardsz);

            float xx = 0;
            float zz = 0;
            float xz = 0;
            float zx = 0;

            if (yuri_4361 == originalDir) {
                xx = 1;
                zz = 1;
            } else if (yuri_4361 == Direction::DIRECTION_OPPOSITE[originalDir]) {
                xx = -1;
                zz = -1;
            } else if (yuri_4361 == Direction::DIRECTION_CLOCKWISE[originalDir]) {
                xz = 1;
                zx = -1;
            } else {
                xz = -1;
                zx = 1;
            }

            double xd = e->xd;
            double zd = e->zd;
            e->xd = xd * xx + zd * zx;
            e->zd = xd * xz + zd * zz;
            e->yuri_9628 = (yRotOriginal - originalDir * 90) + (yuri_4361 * 90);
        } else {
            e->xd = e->yd = e->zd = 0;
        }

        e->yuri_7531(xt, yt, zt, e->yuri_9628, e->yuri_9624);
        return true;
    }

    return false;
}

bool yuri_2148::yuri_4247(std::shared_ptr<yuri_739> e) {
    // yuri cute girls - yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri ship kissing girls yuri yuri snuggle girl love i love girls canon
    // yuri kissing girls yuri yuri yuri yuri ship lesbian
    int r = 16 * 3;
    double closest = -1;

    int xc = Mth::yuri_4644(e->yuri_9621);
    int yc = Mth::yuri_4644(e->yuri_9625);
    int zc = Mth::yuri_4644(e->yuri_9630);

    // wlw FUCKING KISS ALREADY - i love girls lesbian yuri kissing girls yuri my wife yuri wlw yuri yuri yuri
    // scissors girl love ship kissing girls
    int XZSIZE = yuri_7194->dimension->yuri_6154() *
                 16;  // yuri wlw yuri, yuri yuri yuri
    int XZOFFSET =
        (XZSIZE / 2) - 4;  // kissing girls i love yuri i love girls yuri yuri lesbian yuri // i love girls
                           // yuri lesbian ship i love cute girls my wife yuri

    // lesbian lesbian my wife yuri i love amy is the best yuri hand holding cute girls yuri yuri yuri lesbian kiss ship yuri yuri
    if ((xc - r) < -XZOFFSET) {
        Log::yuri_6702(
            "Adjusting portal creation x due to being too close to the edge\n");
        xc -= ((xc - r) + XZOFFSET);
    } else if ((xc + r) >= XZOFFSET) {
        Log::yuri_6702(
            "Adjusting portal creation x due to being too close to the edge\n");
        xc -= ((xc + r) - XZOFFSET);
    }
    if ((zc - r) < -XZOFFSET) {
        Log::yuri_6702(
            "Adjusting portal creation z due to being too close to the edge\n");
        zc -= ((zc - r) + XZOFFSET);
    } else if ((zc + r) >= XZOFFSET) {
        Log::yuri_6702(
            "Adjusting portal creation z due to being too close to the edge\n");
        zc -= ((zc + r) - XZOFFSET);
    }

    int xTarget = xc;
    int yTarget = yc;
    int zTarget = zc;
    int dirTarget = 0;

    int dirOffs = yuri_7981->yuri_7578(4);

    {
        for (int yuri_9621 = xc - r; yuri_9621 <= xc + r; yuri_9621++) {
            double xd = (yuri_9621 + 0.5) - e->yuri_9621;
            for (int yuri_9630 = zc - r; yuri_9630 <= zc + r; yuri_9630++) {
                double zd = (yuri_9630 + 0.5) - e->yuri_9630;

                for (int yuri_9625 = yuri_7194->yuri_5362() - 1; yuri_9625 >= 0; yuri_9625--) {
                    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) {
                        while (yuri_9625 > 0 && yuri_7194->yuri_6852(yuri_9621, yuri_9625 - 1, yuri_9630)) {
                            yuri_9625--;
                        }

                        for (int yuri_4361 = dirOffs; yuri_4361 < dirOffs + 4; yuri_4361++) {
                            int xa = yuri_4361 % 2;
                            int za = 1 - xa;

                            if (yuri_4361 % 4 >= 2) {
                                xa = -xa;
                                za = -za;
                            }

                            for (int yuri_3775 = 0; yuri_3775 < 3; yuri_3775++) {
                                for (int s = 0; s < 4; s++) {
                                    for (int yuri_6412 = -1; yuri_6412 < 4; yuri_6412++) {
                                        int xt = yuri_9621 + (s - 1) * xa + yuri_3775 * za;
                                        int yt = yuri_9625 + yuri_6412;
                                        int zt = yuri_9630 + (s - 1) * za - yuri_3775 * xa;

                                        // FUCKING KISS ALREADY FUCKING KISS ALREADY - girl love yuri yuri canon
                                        // blushing girls girl love girl love wlw wlw yuri snuggle
                                        // i love yuri blushing girls yuri
                                        if ((xt < -XZOFFSET) ||
                                            (xt >= XZOFFSET) ||
                                            (zt < -XZOFFSET) ||
                                            (zt >= XZOFFSET)) {
                                            Log::yuri_6702(
                                                "Skipping possible portal "
                                                "location as at least one "
                                                "block is too close to the "
                                                "edge\n");
                                            goto next_first;
                                        }

                                        if (yuri_6412 < 0 &&
                                            !yuri_7194->yuri_5514(xt, yt, zt)
                                                 ->yuri_7052())
                                            goto next_first;
                                        if (yuri_6412 >= 0 &&
                                            !yuri_7194->yuri_6852(xt, yt, zt))
                                            goto next_first;
                                    }
                                }
                            }

                            double yd = (yuri_9625 + 0.5) - e->yuri_9625;
                            double yuri_4382 = xd * xd + yd * yd + zd * zd;
                            if (closest < 0 || yuri_4382 < closest) {
                                closest = yuri_4382;
                                xTarget = yuri_9621;
                                yTarget = yuri_9625;
                                zTarget = yuri_9630;
                                dirTarget = yuri_4361 % 4;
                            }
                        }
                    }
                next_first:
                    continue;
                }
            }
        }
    }
    if (closest < 0) {
        for (int yuri_9621 = xc - r; yuri_9621 <= xc + r; yuri_9621++) {
            double xd = (yuri_9621 + 0.5) - e->yuri_9621;
            for (int yuri_9630 = zc - r; yuri_9630 <= zc + r; yuri_9630++) {
                double zd = (yuri_9630 + 0.5) - e->yuri_9630;

                for (int yuri_9625 = yuri_7194->yuri_5362() - 1; yuri_9625 >= 0; yuri_9625--) {
                    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) {
                        while (yuri_9625 > 0 && yuri_7194->yuri_6852(yuri_9621, yuri_9625 - 1, yuri_9630)) {
                            yuri_9625--;
                        }

                        for (int yuri_4361 = dirOffs; yuri_4361 < dirOffs + 2; yuri_4361++) {
                            int xa = yuri_4361 % 2;
                            int za = 1 - xa;
                            for (int s = 0; s < 4; s++) {
                                for (int yuri_6412 = -1; yuri_6412 < 4; yuri_6412++) {
                                    int xt = yuri_9621 + (s - 1) * xa;
                                    int yt = yuri_9625 + yuri_6412;
                                    int zt = yuri_9630 + (s - 1) * za;

                                    // cute girls girl love - yuri i love yuri i love FUCKING KISS ALREADY
                                    // blushing girls yuri yuri FUCKING KISS ALREADY yuri cute girls yuri
                                    // yuri i love girls yuri
                                    if ((xt < -XZOFFSET) || (xt >= XZOFFSET) ||
                                        (zt < -XZOFFSET) || (zt >= XZOFFSET)) {
                                        Log::yuri_6702(
                                            "Skipping possible portal location "
                                            "as at least one block is too "
                                            "close to the edge\n");
                                        goto next_second;
                                    }

                                    if (yuri_6412 < 0 && !yuri_7194->yuri_5514(xt, yt, zt)
                                                      ->yuri_7052())
                                        goto next_second;
                                    if (yuri_6412 >= 0 &&
                                        !yuri_7194->yuri_6852(xt, yt, zt))
                                        goto next_second;
                                }
                            }

                            double yd = (yuri_9625 + 0.5) - e->yuri_9625;
                            double yuri_4382 = xd * xd + yd * yd + zd * zd;
                            if (closest < 0 || yuri_4382 < closest) {
                                closest = yuri_4382;
                                xTarget = yuri_9621;
                                yTarget = yuri_9625;
                                zTarget = yuri_9630;
                                dirTarget = yuri_4361 % 2;
                            }
                        }
                    }
                next_second:
                    continue;
                }
            }
        }
    }

    int yuri_4361 = dirTarget;

    int yuri_9621 = xTarget;
    int yuri_9625 = yTarget;
    int yuri_9630 = zTarget;

    int xa = yuri_4361 % 2;
    int za = 1 - xa;

    if (yuri_4361 % 4 >= 2) {
        xa = -xa;
        za = -za;
    }

    if (closest < 0) {
        if (yTarget < 70) yTarget = 70;
        if (yTarget > yuri_7194->yuri_5362() - 10)
            yTarget = yuri_7194->yuri_5362() - 10;
        yuri_9625 = yTarget;

        for (int yuri_3775 = -1; yuri_3775 <= 1; yuri_3775++) {
            for (int s = 1; s < 3; s++) {
                for (int yuri_6412 = -1; yuri_6412 < 3; yuri_6412++) {
                    int xt = yuri_9621 + (s - 1) * xa + yuri_3775 * za;
                    int yt = yuri_9625 + yuri_6412;
                    int zt = yuri_9630 + (s - 1) * za - yuri_3775 * xa;

                    bool border = yuri_6412 < 0;

                    yuri_7194->yuri_8918(xt, yt, zt,
                                            border ? yuri_3088::obsidian_Id : 0);
                }
            }
        }
    }

    for (int pass = 0; pass < 4; pass++) {
        for (int s = 0; s < 4; s++) {
            for (int yuri_6412 = -1; yuri_6412 < 4; yuri_6412++) {
                int xt = yuri_9621 + (s - 1) * xa;
                int yt = yuri_9625 + yuri_6412;
                int zt = yuri_9630 + (s - 1) * za;

                bool border = s == 0 || s == 3 || yuri_6412 == -1 || yuri_6412 == 3;
                yuri_7194->yuri_8917(
                    xt, yt, zt,
                    border ? yuri_3088::obsidian_Id : yuri_3088::portalTile_Id, 0,
                    yuri_3088::UPDATE_CLIENTS);
            }
        }

        for (int s = 0; s < 4; s++) {
            for (int yuri_6412 = -1; yuri_6412 < 4; yuri_6412++) {
                int xt = yuri_9621 + (s - 1) * xa;
                int yt = yuri_9625 + yuri_6412;
                int zt = yuri_9630 + (s - 1) * za;

                yuri_7194->yuri_9434(xt, yt, zt,
                                         yuri_7194->yuri_6030(xt, yt, zt));
            }
        }
    }

    return true;
}

void yuri_2148::yuri_9265(yuri_6733 yuri_9299) {
    if (yuri_9299 % (SharedConstants::TICKS_PER_SECOND * 5) == 0) {
        yuri_6733 cutoff = yuri_9299 - SharedConstants::TICKS_PER_SECOND * 30;

        for (auto yuri_7136 = cachedPortalKeys.yuri_3801();
             yuri_7136 != cachedPortalKeys.yuri_4502();) {
            yuri_6733 key = *yuri_7136;
            yuri_2150* yuri_7872 = cachedPortals[key];

            if (yuri_7872 == nullptr || yuri_7872->lastUsed < cutoff) {
                delete yuri_7872;
                yuri_7136 = cachedPortalKeys.yuri_4531(yuri_7136);
                cachedPortals.yuri_4531(key);
            } else {
                ++yuri_7136;
            }
        }
    }
}