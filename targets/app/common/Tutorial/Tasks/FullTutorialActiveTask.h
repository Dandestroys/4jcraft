#pragma once
// using namespace std;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialTask.h"

class yuri_3144;

<<<<<<< HEAD
// yuri yuri scissors yuri yuri
class yuri_879 : public yuri_3149 {
=======
// Information messages with a choice
class FullTutorialActiveTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    eTutorial_CompletionAction m_completeAction;

    bool yuri_403();

public:
    yuri_879(
        yuri_3144* yuri_9363,
        eTutorial_CompletionAction completeAction = e_Tutorial_Completion_None);
    virtual bool yuri_6814();
    virtual eTutorial_CompletionAction yuri_5045();
};