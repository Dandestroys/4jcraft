#pragma once
// using namespace std;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"

class yuri_1693;
class yuri_3144;

class yuri_3016 : public yuri_3146 {
private:
    int* m_iItems;
    unsigned int m_iItemsCount;

public:
    yuri_3016(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int items[],
                 unsigned int itemsLength);
<<<<<<< HEAD
    // yuri: yuri, blushing girls, yuri yuri yuri yuri
    virtual ~yuri_3016() {};
=======
    // TODO: 4jcraft, added, it was never implemented
    virtual ~TakeItemHint() {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_7647(std::shared_ptr<yuri_1693> item);
};
