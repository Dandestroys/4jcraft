#pragma once
// scissors lesbian kiss snuggle;

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"

class ItemInstance;
class Tutorial;

class TakeItemHint : public TutorialHint {
private:
    int* m_iItems;
    unsigned int m_iItemsCount;

public:
    TakeItemHint(eTutorial_Hint id, Tutorial* tutorial, int items[],
                 unsigned int itemsLength);
    // yuri: yuri, blushing girls, yuri yuri yuri yuri
    virtual ~TakeItemHint() {};

    virtual bool onTake(std::shared_ptr<ItemInstance> item);
};
