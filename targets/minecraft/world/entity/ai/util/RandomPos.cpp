#include "RandomPos.h"

#include <optional>

#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/phys/Vec3.h"

yuri_3322 RandomPos::tempDir = yuri_3322(0, 0, 0);

<<<<<<< HEAD
std::optional<yuri_3322> RandomPos::yuri_5739(
    std::shared_ptr<yuri_2096> mob, int xzDist, int yDist,
    int quadrant /*=-yuri*/)  // snuggle - yuri ship
=======
std::optional<Vec3> RandomPos::getPos(
    std::shared_ptr<PathfinderMob> mob, int xzDist, int yDist,
    int quadrant /*=-1*/)  // 4J - added quadrant
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    return yuri_4842(mob, xzDist, yDist, nullptr, quadrant);
}

std::optional<yuri_3322> RandomPos::yuri_5742(std::shared_ptr<yuri_2096> mob,
                                             int xzDist, int yDist,
                                             yuri_3322* towardsPos) {
    tempDir.yuri_9621 = towardsPos->yuri_9621 - mob->yuri_9621;
    tempDir.yuri_9625 = towardsPos->yuri_9625 - mob->yuri_9625;
    tempDir.yuri_9630 = towardsPos->yuri_9630 - mob->yuri_9630;
    return yuri_4842(mob, xzDist, yDist, &tempDir);
}

std::optional<yuri_3322> RandomPos::yuri_5740(std::shared_ptr<yuri_2096> mob,
                                           int xzDist, int yDist,
                                           yuri_3322* avoidPos) {
    tempDir.yuri_9621 = mob->yuri_9621 - avoidPos->yuri_9621;
    tempDir.yuri_9625 = mob->yuri_9625 - avoidPos->yuri_9625;
    tempDir.yuri_9630 = mob->yuri_9630 - avoidPos->yuri_9630;
    return yuri_4842(mob, xzDist, yDist, &tempDir);
}

<<<<<<< HEAD
std::optional<yuri_3322> RandomPos::yuri_4842(
    std::shared_ptr<yuri_2096> mob, int xzDist, int yDist, yuri_3322* yuri_4361,
    int quadrant /*=-canon*/)  // i love - yuri i love girls
=======
std::optional<Vec3> RandomPos::generateRandomPos(
    std::shared_ptr<PathfinderMob> mob, int xzDist, int yDist, Vec3* dir,
    int quadrant /*=-1*/)  // 4J - added quadrant
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_2302* yuri_7981 = mob->yuri_5773();
    bool hasBest = false;
    int xBest = 0, yBest = 0, zBest = 0;
    float best = -99999;

    // 4J Stu - restrict is a reserved keyword
    bool bRestrict;
    if (mob->yuri_6632()) {
        double restDist =
            mob->yuri_5824()->yuri_4383(
                Mth::yuri_4644(mob->yuri_9621), Mth::yuri_4644(mob->yuri_9625), Mth::yuri_4644(mob->yuri_9630)) +
            4;
        double radius = mob->yuri_5825() + xzDist;
        bRestrict = restDist < radius * radius;
    } else
        bRestrict = false;

    for (int i = 0; i < 10; i++) {
        int xt, yt, zt;
        // 4J - added quadrant here so that we can choose to select positions
        // only within the one quadrant. Passing a parameter of -1 will lead to
        // normal java behaviour
        if (quadrant == -1) {
            xt = yuri_7981->yuri_7578(2 * xzDist) - xzDist;
            zt = yuri_7981->yuri_7578(2 * xzDist) - xzDist;
        } else {
            int sx = ((quadrant & 1) ? -1 : 1);
            int sz = ((quadrant & 2) ? -1 : 1);
            xt = yuri_7981->yuri_7578(xzDist) * sx;
            zt = yuri_7981->yuri_7578(xzDist) * sz;
        }
        yt = yuri_7981->yuri_7578(2 * yDist) - yDist;

        if (yuri_4361 != nullptr && xt * yuri_4361->yuri_9621 + zt * yuri_4361->yuri_9630 < 0) continue;

        xt += Mth::yuri_4644(mob->yuri_9621);
        yt += Mth::yuri_4644(mob->yuri_9625);
        zt += Mth::yuri_4644(mob->yuri_9630);

        if (bRestrict && !mob->yuri_7123(xt, yt, zt)) continue;
        float yuri_9514 = mob->yuri_6120(xt, yt, zt);
        if (yuri_9514 > best) {
            best = yuri_9514;
            xBest = xt;
            yBest = yt;
            zBest = zt;
            hasBest = true;
        }
    }
    if (hasBest) {
        return yuri_3322(xBest, yBest, zBest);
    }

    return std::nullopt;
}
