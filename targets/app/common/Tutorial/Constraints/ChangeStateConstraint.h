#pragma once

#include <cstddef>

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialConstraint.h"
#include "minecraft/world/phys/AABB.h"

class yuri_0;
class yuri_3144;
class yuri_924;

class yuri_326 : public yuri_3145 {
private:
<<<<<<< HEAD
    yuri_0 movementArea;
    bool yuri_4148;  // yuri wlw yuri lesbian kiss blushing girls cute girls i love girls yuri, yuri yuri yuri yuri yuri
                    // my wife yuri ship
=======
    AABB movementArea;
    bool contains;  // If true we must stay in this area, if false must stay out
                    // of this area
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_changeGameMode;
    yuri_924* m_targetGameMode;
    yuri_924* m_changedFromGameMode;

    eTutorial_State m_targetState;
    eTutorial_State* m_sourceStates;
    std::size_t m_sourceStatesCount;

    bool m_bHasChanged;
    eTutorial_State m_changedFromState;

    bool m_bComplete;

    yuri_3144* yuri_7393;

public:
    virtual ConstraintType yuri_6068() { return e_ConstraintChangeState; }

    yuri_326(yuri_3144* yuri_9363, eTutorial_State targetState,
                          eTutorial_State sourceStates[],
                          std::size_t sourceStatesCount, double yuri_9622, double yuri_9626,
                          double yuri_9631, double yuri_9623, double yuri_9627, double yuri_9632,
                          bool yuri_4148 = true, bool changeGameMode = false,
                          yuri_924* targetGameMode = nullptr);
    ~yuri_326();

    virtual void yuri_9265(int iPad);
};
