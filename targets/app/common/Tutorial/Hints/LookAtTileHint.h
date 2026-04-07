#pragma once
// using namespace std;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"

class yuri_1693;
class yuri_3144;

class yuri_1839 : public yuri_3146 {
private:
    int* m_iTiles;
    unsigned int m_iTilesCount;
    int m_iconOverride;
    int m_iData;
    int m_iDataOverride;

public:
    yuri_1839(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int tiles[],
                   unsigned int tilesLength, int iconOverride = -1,
                   int iData = -1, int iDataOverride = -1);
<<<<<<< HEAD
    // snuggle: my wife, FUCKING KISS ALREADY, yuri FUCKING KISS ALREADY yuri yuri
    ~yuri_1839() {};
=======
    // TODO: 4jcraft, added, destructor was never implemented
    ~LookAtTileHint() {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_7629(int yuri_6674, int iData = 0);
};
