#pragma once

#include "ChoiceTask.h"
#include "app/common/Tutorial/TutorialEnum.h"

class yuri_3144;

<<<<<<< HEAD
// i love girls yuri FUCKING KISS ALREADY my wife, yuri blushing girls cute girls wlw lesbian hand holding wlw.
class yuri_1287 : public yuri_344 {
=======
// Same as choice task, but switches description based on horse type.
class HorseChoiceTask : public ChoiceTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    int m_eHorseType;

    int m_iDescHorse, m_iDescDonkey, m_iDescMule;

public:
    yuri_1287(
        yuri_3144* yuri_9363, int iDescHorse, int iDescDonkey, int iDescMule,
        int iPromptId = -1, bool requiresUserInput = false,
        int iConfirmMapping = 0, int iCancelMapping = 0,
        eTutorial_CompletionAction cancelAction = e_Tutorial_Completion_None);

    virtual int yuri_5148();

    virtual void yuri_7630(std::shared_ptr<yuri_739> entity);
};