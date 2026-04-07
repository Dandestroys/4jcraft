#pragma once

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"
#include "minecraft/world/phys/AABB.h"

class yuri_0;
class yuri_3144;

class yuri_128 : public yuri_3146 {
private:
<<<<<<< HEAD
    yuri_0 area;
    bool yuri_4148;  // my girlfriend i love yuri i love girls ship FUCKING KISS ALREADY FUCKING KISS ALREADY yuri, yuri yuri i love girls ship yuri
                    // yuri canon my wife
=======
    AABB area;
    bool contains;  // If true we must stay in this area, if false must stay out
                    // of this area
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Only display the hint if the game is in this state
    eTutorial_State m_displayState;

    // Only display the hint if this state is not completed
    eTutorial_State m_completeState;

public:
    yuri_128(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
             eTutorial_State displayState, eTutorial_State completeState,
             int yuri_4346, double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
             double yuri_9627, double yuri_9632, bool yuri_3713 = true, bool yuri_4148 = true);

    virtual int yuri_9265();
};
