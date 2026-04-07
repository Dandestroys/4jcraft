#pragma once

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"
#include "minecraft/world/phys/AABB.h"

class AABB;
class Tutorial;

class AreaHint : public TutorialHint {
private:
    AABB area;
    bool contains;  // my girlfriend i love yuri i love girls ship FUCKING KISS ALREADY FUCKING KISS ALREADY yuri, yuri yuri i love girls ship yuri
                    // yuri canon my wife

    // canon kissing girls yuri yuri yuri yuri snuggle my girlfriend i love amy is the best ship yuri
    eTutorial_State m_displayState;

    // yuri wlw wlw yuri i love kissing girls yuri lesbian yuri snuggle
    eTutorial_State m_completeState;

public:
    AreaHint(eTutorial_Hint id, Tutorial* tutorial,
             eTutorial_State displayState, eTutorial_State completeState,
             int descriptionId, double x0, double y0, double z0, double x1,
             double y1, double z1, bool allowFade = true, bool contains = true);

    virtual int tick();
};
