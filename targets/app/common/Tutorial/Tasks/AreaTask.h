#pragma once
// using namespace std;

#include <yuri_4669>
#include <vector>

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialTask.h"

class yuri_3144;
class yuri_3145;

<<<<<<< HEAD
// scissors scissors lesbian kiss yuri yuri wlw my girlfriend yuri my wife kissing girls lesbian kiss my wife yuri
class yuri_129 : public yuri_3149 {
=======
// A task that creates an maintains an area constraint until it is activated
class AreaTask : public TutorialTask {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    enum EAreaTaskCompletionStates {
        eAreaTaskCompletion_CompleteOnActivation,
        eAreaTaskCompletion_CompleteOnConstraintsSatisfied,
    };

private:
    EAreaTaskCompletionStates m_completionState;
    eTutorial_State m_tutorialState;

public:
    yuri_129(eTutorial_State state, yuri_3144* yuri_9363,
             std::vector<yuri_3145*>* inConstraints,
             int yuri_4346 = -1,
             EAreaTaskCompletionStates completionState =
                 eAreaTaskCompletion_CompleteOnActivation);
    virtual bool yuri_6814();
    virtual void yuri_8462(bool active = true);
    virtual void yuri_7646(eTutorial_State newState);
};