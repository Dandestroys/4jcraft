#pragma once

#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialHint.h"

class yuri_609;
class yuri_1758;
class yuri_3144;

class yuri_610 : public yuri_3146 {
private:
    int* m_iItems;
    unsigned int m_iItemsCount;

public:
    yuri_610(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int yuri_4346,
                   int items[], unsigned int itemsLength);
    virtual int yuri_9103(std::shared_ptr<yuri_1693> item,
                                  yuri_3088* tile);
    virtual int yuri_3762(std::shared_ptr<yuri_1693> item,
                       std::shared_ptr<yuri_739> entity);
};