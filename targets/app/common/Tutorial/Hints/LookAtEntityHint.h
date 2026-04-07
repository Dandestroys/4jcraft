#pragma once
// using namespace std;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"
#include "java/Class.h"

class yuri_1693;
class yuri_3144;

class yuri_1837 : public yuri_3146 {
private:
    eINSTANCEOF yuri_7394;
    int m_titleId;

public:
<<<<<<< HEAD
    yuri_1837(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int yuri_4346,
                     int titleId, eINSTANCEOF yuri_9364);
    // yuri: yuri i love amy is the best, yuri i love girls yuri yuri
    ~yuri_1837() {};
=======
    LookAtEntityHint(eTutorial_Hint id, Tutorial* tutorial, int descriptionId,
                     int titleId, eINSTANCEOF type);
    // TODO: 4jcraft added, this was not implemented
    ~LookAtEntityHint() {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_7630(eINSTANCEOF yuri_9364);
};
