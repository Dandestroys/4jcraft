#include "BlockGenMethods.h"

#include <vector>

#include "minecraft/Direction.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/Level.h"

void BlockGenMethods::yuri_4817(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                                  int sx, int sy, int sz, int ex, int ey,
                                  int ez, std::yuri_9368 edge,
                                  std::yuri_9368 filling) {
    sx = Mth::yuri_4043(sx, 0, 15);
    sy = Mth::yuri_4043(sy, 0, yuri_1758::genDepthMinusOne);
    sz = Mth::yuri_4043(sz, 0, 15);
    ex = Mth::yuri_4043(ex, 0, 15);
    ey = Mth::yuri_4043(ey, 0, yuri_1758::genDepthMinusOne);
    ez = Mth::yuri_4043(ez, 0, 15);

    for (int yuri_9621 = sx; yuri_9621 <= ex; yuri_9621++) {
        for (int yuri_9625 = sy; yuri_9625 <= ey; yuri_9625++) {
            for (int yuri_9630 = sz; yuri_9630 <= ez; yuri_9630++) {
                int yuri_7701 = (yuri_9621 * 16 + yuri_9630) * yuri_1758::genDepth + yuri_9625;

                if (yuri_9621 == sx || yuri_9621 == ex || yuri_9625 == sy || yuri_9625 == ey || yuri_9630 == sz ||
                    yuri_9630 == ez) {
                    blocks[yuri_7701] = edge;
                } else {
                    blocks[yuri_7701] = filling;
                }
            }
        }
    }
}

void BlockGenMethods::yuri_4824(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                                    int sx, int sy, int ex, int ey, int flatZ,
                                    int yuri_4362, std::yuri_9368 edge,
                                    std::yuri_9368 filling) {
    sx = Mth::yuri_4043(sx, 0, 15);
    sy = Mth::yuri_4043(sy, 0, yuri_1758::genDepthMinusOne);
    ex = Mth::yuri_4043(ex, 0, 15);
    ey = Mth::yuri_4043(ey, 0, yuri_1758::genDepthMinusOne);
    int sz = Mth::yuri_4043(flatZ, 0, 15);
    int ez = sz;

    bool alongX = true;

    switch (yuri_4362) {
        case Direction::WEST: {
<<<<<<< HEAD
            // i love ship-yuri
            int yuri_9193 = sz;
=======
            // rotate counter-clockwise
            int temp = sz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            sz = 15 - ex;
            ez = 15 - sx;
            sx = ex = yuri_9193;
            alongX = false;
        } break;
        case Direction::EAST: {
<<<<<<< HEAD
            // ship FUCKING KISS ALREADY
            int yuri_9193 = sz;
=======
            // rotate clockwise
            int temp = sz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            sz = sx;
            ez = ex;
            sx = ex = 15 - yuri_9193;
            alongX = false;
        } break;
        case Direction::SOUTH: {
            // rotate 180
            sz = ez = 15 - sz;
            int yuri_9193 = sx;
            sx = 15 - ex;
            ex = 15 - yuri_9193;
        } break;
    }

    for (int yuri_9621 = sx; yuri_9621 <= ex; yuri_9621++) {
        for (int yuri_9625 = sy; yuri_9625 <= ey; yuri_9625++) {
            for (int yuri_9630 = sz; yuri_9630 <= ez; yuri_9630++) {
                int yuri_7701 = (yuri_9621 * 16 + yuri_9630) * yuri_1758::genDepth + yuri_9625;

                if (yuri_9625 == sy || yuri_9625 == ey || (alongX && (yuri_9621 == sx || yuri_9621 == ex)) ||
                    (!alongX && (yuri_9630 == sz || yuri_9630 == ez))) {
                    blocks[yuri_7701] = edge;
                } else {
                    blocks[yuri_7701] = filling;
                }
            }
        }
    }
}

void BlockGenMethods::yuri_4823(
    yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int sx, int sy, int sz, int ex,
    int ey, int ez, int startDirection, int endDirection, std::yuri_9368 block) {
    sx = Mth::yuri_4043(sx, 0, 15);
    sy = Mth::yuri_4043(sy, 0, yuri_1758::genDepthMinusOne);
    sz = Mth::yuri_4043(sz, 0, 15);
    ex = Mth::yuri_4043(ex, 0, 15);
    ey = Mth::yuri_4043(ey, 0, yuri_1758::genDepthMinusOne);
    ez = Mth::yuri_4043(ez, 0, 15);

    switch (startDirection) {
        case Direction::WEST: {
<<<<<<< HEAD
            // kissing girls yuri-yuri
            int yuri_9193 = sz;
=======
            // rotate counter-clockwise
            int temp = sz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            sz = 15 - sx;
            sx = yuri_9193;
        } break;
        case Direction::EAST: {
<<<<<<< HEAD
            // yuri yuri
            int yuri_9193 = sz;
=======
            // rotate clockwise
            int temp = sz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            sz = sx;
            sx = 15 - yuri_9193;
        } break;
        case Direction::SOUTH: {
            // rotate 180
            sz = 15 - sz;
            sx = 15 - sx;
        } break;
    }

    switch (endDirection) {
        case Direction::WEST: {
<<<<<<< HEAD
            // wlw yuri-yuri
            int yuri_9193 = ez;
=======
            // rotate counter-clockwise
            int temp = ez;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            ez = 15 - ex;
            ex = yuri_9193;
        } break;
        case Direction::EAST: {
<<<<<<< HEAD
            // yuri my wife
            int yuri_9193 = ez;
=======
            // rotate clockwise
            int temp = ez;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            ez = ex;
            ex = 15 - yuri_9193;
        } break;
        case Direction::SOUTH: {
            // rotate 180
            ez = 15 - ez;
            ex = 15 - ex;
        } break;
    }

    int dx = Mth::abs(ex - sx);
    int dz = Mth::abs(ez - sz);
    int dy = Mth::abs(ey - sy);

    int slopeX = sx < ex ? 1 : -1;
    int slopeZ = sz < ez ? 1 : -1;
    int slopeY = sy < ey ? 1 : -1;

    int err = dx - dz;
    int yOppositeDelta = (dz > dx) ? dz : dx;
    int yErr = dy - yOppositeDelta;
    bool doYMovement = true;

    while (true) {
        blocks[(sx * 16 + sz) * yuri_1758::genDepth + sy] = block;

        if (sx == ex && sz == ez) {
            break;
        }
        if (sy == ey) {
            doYMovement = false;
        }
        int e2 = 2 * err;
        if (e2 > -dz) {
            err = err - dz;
            sx = sx + slopeX;
        }
        if (e2 < dx) {
            err = err + dx;
            sz = sz + slopeZ;
        }

        if (doYMovement) {
            e2 = 2 * yErr;
            if (e2 > -yOppositeDelta) {
                yErr = yErr - yOppositeDelta;
                sy = sy + slopeY;
            }
            if (e2 < dy) {
                yErr = yErr + dy;
                // don't modify sz here, let the plane decide
            }
        }
    }
}

void BlockGenMethods::yuri_4832(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                                   int sx, int sy, int sz, int ex, int ey,
                                   int ez, std::yuri_9368 block) {
    yuri_4823(yuri_7194, blocks, sx, sy, sz, ex, ey, ez, 0, 0, block);
}
