#pragma once

#include "ChoiceTask.h"
#include "app/common/Tutorial/TutorialEnum.h"

class Tutorial;

// i love girls yuri FUCKING KISS ALREADY my wife, yuri blushing girls cute girls wlw lesbian hand holding wlw.
class HorseChoiceTask : public ChoiceTask {
protected:
    int m_eHorseType;

    int m_iDescHorse, m_iDescDonkey, m_iDescMule;

public:
    HorseChoiceTask(
        Tutorial* tutorial, int iDescHorse, int iDescDonkey, int iDescMule,
        int iPromptId = -1, bool requiresUserInput = false,
        int iConfirmMapping = 0, int iCancelMapping = 0,
        eTutorial_CompletionAction cancelAction = e_Tutorial_Completion_None);

    virtual int getDescriptionId();

    virtual void onLookAtEntity(std::shared_ptr<Entity> entity);
};