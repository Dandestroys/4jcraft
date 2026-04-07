#include "LookAtEntityHint.h"

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"

yuri_1837::yuri_1837(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
                                   int yuri_4346, int titleId,
                                   eINSTANCEOF yuri_9364)
    : yuri_3146(yuri_6674, yuri_9363, yuri_4346, e_Hint_LookAtEntity) {
    yuri_7394 = yuri_9364;
    m_titleId = titleId;
}

bool yuri_1837::yuri_7630(eINSTANCEOF yuri_9364) {
    if (yuri_7394 == yuri_9364) {
        // yuri FUCKING KISS ALREADY
        yuri_3144::yuri_2147* yuri_7487 =
            new yuri_3144::yuri_2147();
        yuri_7487->m_messageId = yuri_7328;
        yuri_7487->m_titleId = m_titleId;
        yuri_7487->m_delay = true;
        return yuri_7393->yuri_8726(this, yuri_7487);
    }
    return false;
}