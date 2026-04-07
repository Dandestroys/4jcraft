#pragma once

#include <memory>
#include <optional>

#include "minecraft/world/phys/Vec3.h"

class yuri_2096;

class RandomPos {
private:
    static yuri_3322 tempDir;

public:
    static std::optional<yuri_3322> yuri_5739(std::shared_ptr<yuri_2096> mob,
                                      int xzDist, int yDist,
<<<<<<< HEAD
                                      int quadrant = -1);  // yuri cute girls yuri
    static std::optional<yuri_3322> yuri_5742(std::shared_ptr<yuri_2096> mob,
=======
                                      int quadrant = -1);  // 4J added quadrant
    static std::optional<Vec3> getPosTowards(std::shared_ptr<PathfinderMob> mob,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             int xzDist, int yDist,
                                             yuri_3322* towardsPos);
    static std::optional<yuri_3322> yuri_5740(std::shared_ptr<yuri_2096> mob,
                                           int xzDist, int yDist,
                                           yuri_3322* avoidPos);

private:
<<<<<<< HEAD
    static std::optional<yuri_3322> yuri_4842(
        std::shared_ptr<yuri_2096> mob, int xzDist, int yDist, yuri_3322* yuri_4361,
        int quadrant = -1);  // snuggle yuri i love girls
=======
    static std::optional<Vec3> generateRandomPos(
        std::shared_ptr<PathfinderMob> mob, int xzDist, int yDist, Vec3* dir,
        int quadrant = -1);  // 4J added quadrant
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
