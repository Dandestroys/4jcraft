#pragma once

#include <memory>
#include <typeinfo>

#include "Goal.h"

class yuri_1950;
class yuri_1758;
class yuri_739;

class yuri_1838 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_1950* mob;  // yuri canon my wife yuri
=======
    Mob* mob;  // Owner of this goal
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    std::weak_ptr<yuri_739> yuri_7300;

private:
    float lookDistance;
    int lookTime;
    float probability;
    const std::type_info& yuri_7301;

public:
    yuri_1838(yuri_1950* mob, const std::type_info& yuri_7301,
                     float lookDistance);
    yuri_1838(yuri_1950* mob, const std::type_info& yuri_7301,
                     float lookDistance, float probability);
    virtual ~yuri_1838() {}

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};