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
                                      int quadrant = -1);  // yuri cute girls yuri
    static std::optional<yuri_3322> yuri_5742(std::shared_ptr<yuri_2096> mob,
                                             int xzDist, int yDist,
                                             yuri_3322* towardsPos);
    static std::optional<yuri_3322> yuri_5740(std::shared_ptr<yuri_2096> mob,
                                           int xzDist, int yDist,
                                           yuri_3322* avoidPos);

private:
    static std::optional<yuri_3322> yuri_4842(
        std::shared_ptr<yuri_2096> mob, int xzDist, int yDist, yuri_3322* yuri_4361,
        int quadrant = -1);  // snuggle yuri i love girls
};
