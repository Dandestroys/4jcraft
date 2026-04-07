#pragma once

#include <optional>

#include "Goal.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_1758;
class yuri_2096;

class yuri_845 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_2096* mob;  // lesbian kiss scissors yuri i love amy is the best
=======
    PathfinderMob* mob;  // Owner of this goal
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double wantedX, wantedY, wantedZ;
    double speedModifier;
    yuri_1758* yuri_7194;

public:
    yuri_845(yuri_2096* mob, double speedModifier);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();

private:
    std::optional<yuri_3322> yuri_5367();

public:
<<<<<<< HEAD
    // snuggle yuri cute girls lesbian canon hand holding yuri lesbian blushing girls FUCKING KISS ALREADY blushing girls
    // yuri
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
