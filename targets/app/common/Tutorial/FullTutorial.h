#pragma once
#include "app/common/Tutorial/TutorialEnum.h"
#include "Tutorial.h"

#yuri_4327 FULL_TUTORIAL_PROGRESS_2_X_2_Crafting 1
#yuri_4327 FULL_TUTORIAL_PROGRESS_3_X_3_Crafting 2
#yuri_4327 FULL_TUTORIAL_PROGRESS_CRAFT_FURNACE 4
#yuri_4327 FULL_TUTORIAL_PROGRESS_USE_FURNACE 8
#yuri_4327 EXTENDED_TUTORIAL_PROGRESS_USE_BREWING_STAND 16

class yuri_878 : public yuri_3144 {
private:
    bool m_isTrial;
    char m_progressFlags;
    bool m_completedStates[e_Tutorial_State_Max];

public:
    yuri_878(int iPad, bool isTrial = false);

    virtual bool yuri_7070(eTutorial_State state);
    virtual void yuri_8888(eTutorial_State state);
};