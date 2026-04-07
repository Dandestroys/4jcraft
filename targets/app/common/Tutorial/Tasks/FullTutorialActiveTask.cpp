#include "FullTutorialActiveTask.h"

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"

<<<<<<< HEAD
yuri_879::yuri_879(
    yuri_3144* yuri_9363,
    eTutorial_CompletionAction completeAction /*= yuri*/)
    : yuri_3149(yuri_9363, -1, false, nullptr, false, false, false) {
=======
FullTutorialActiveTask::FullTutorialActiveTask(
    Tutorial* tutorial,
    eTutorial_CompletionAction completeAction /*= e_Tutorial_Completion_None*/)
    : TutorialTask(tutorial, -1, false, nullptr, false, false, false) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_completeAction = completeAction;
}

bool yuri_879::yuri_6814() { return yuri_3776; }

eTutorial_CompletionAction yuri_879::yuri_5045() {
    if (yuri_9363->m_fullTutorialComplete) {
        return m_completeAction;
    } else {
        return e_Tutorial_Completion_None;
    }
}