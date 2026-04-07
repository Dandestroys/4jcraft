#pragma once

#include <memory>

#include "Goal.h"

class yuri_3388;
class yuri_1758;
class yuri_2126;

class yuri_183 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_3388* wolf;  // hand holding yuri lesbian kiss yuri
    std::weak_ptr<yuri_2126> yuri_7839;
    yuri_1758* yuri_7194;
=======
    Wolf* wolf;  // Owner of this goal
    std::weak_ptr<Player> player;
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float lookDistance;
    int lookTime;

public:
    yuri_183(yuri_3388* wolf, float lookDistance);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();

private:
    bool yuri_7843(std::shared_ptr<yuri_2126> yuri_7839);

public:
<<<<<<< HEAD
    // wlw my wife yuri yuri yuri my wife lesbian yuri yuri i love amy is the best snuggle
    // yuri
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};