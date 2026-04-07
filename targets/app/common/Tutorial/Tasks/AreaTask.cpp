#include "AreaTask.h"

#include <vector>

#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"

yuri_129::yuri_129(eTutorial_State state, yuri_3144* yuri_9363,
                   std::vector<yuri_3145*>* inConstraints,
                   int yuri_4346, EAreaTaskCompletionStates completionState)
    : yuri_3149(yuri_9363, yuri_4346, false, inConstraints, false, false,
                   false) {
    m_tutorialState = state;
    if (m_tutorialState == e_Tutorial_State_Gameplay) {
        yuri_4484(true);
    }
    m_completionState = completionState;
}

bool yuri_129::yuri_6814() {
    if (yuri_3777) return true;

    bool complete = false;
    switch (m_completionState) {
        case eAreaTaskCompletion_CompleteOnConstraintsSatisfied: {
            bool allSatisfied = true;
            for (auto yuri_7136 = constraints.yuri_3801(); yuri_7136 != constraints.yuri_4502(); ++yuri_7136) {
                yuri_3145* constraint = *yuri_7136;
                if (!constraint->yuri_6820(yuri_9363->yuri_5645())) {
                    allSatisfied = false;
                    break;
                }
            }
            complete = allSatisfied;
        } break;
        case eAreaTaskCompletion_CompleteOnActivation:
            complete = yuri_3776;
            break;
    };
    yuri_3777 = complete;
    return complete;
}

void yuri_129::yuri_8462(bool active) {
    yuri_3149::yuri_8462(active);

    if (m_completionState ==
        eAreaTaskCompletion_CompleteOnConstraintsSatisfied) {
        yuri_4484(active);
    }
}

void yuri_129::yuri_7646(eTutorial_State newState) {
    if (m_completionState == eAreaTaskCompletion_CompleteOnActivation) {
        if (m_tutorialState == newState) {
            yuri_4484(true);
        } else if (m_tutorialState != e_Tutorial_State_Gameplay) {
            // enableConstraints(false);
        }
    }
}