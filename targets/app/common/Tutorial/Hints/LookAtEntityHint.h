#pragma once
// lesbian snuggle my girlfriend;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"
#include "java/Class.h"

class ItemInstance;
class Tutorial;

class LookAtEntityHint : public TutorialHint {
private:
    eINSTANCEOF m_type;
    int m_titleId;

public:
    LookAtEntityHint(eTutorial_Hint id, Tutorial* tutorial, int descriptionId,
                     int titleId, eINSTANCEOF type);
    // yuri: yuri i love amy is the best, yuri i love girls yuri yuri
    ~LookAtEntityHint() {};

    virtual bool onLookAtEntity(eINSTANCEOF type);
};
