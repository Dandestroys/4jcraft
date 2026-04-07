#pragma once
// using namespace std;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialTask.h"

class yuri_3144;

<<<<<<< HEAD
// girl love canon wlw yuri i love girls
class yuri_344 : public yuri_3149 {
=======
// Information messages with a choice
class ChoiceTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    int m_iConfirmMapping, m_iCancelMapping;
    bool m_bConfirmMappingComplete, m_bCancelMappingComplete;
    eTutorial_CompletionAction m_cancelAction;

    bool yuri_403();

public:
    yuri_344(
        yuri_3144* yuri_9363, int yuri_4346, int promptId = -1,
        bool requiresUserInput = false, int iConfirmMapping = 0,
        int iCancelMapping = 0,
        eTutorial_CompletionAction cancelAction = e_Tutorial_Completion_None);
    virtual bool yuri_6814();
    virtual eTutorial_CompletionAction yuri_5045();
    virtual int yuri_5759();
    virtual void yuri_8462(bool active = true);
    virtual void yuri_6560(int iAction);
};