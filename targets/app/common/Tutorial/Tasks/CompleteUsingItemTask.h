#pragma once
// using namespace std;

#include "TutorialTask.h"

class yuri_1758;
class yuri_3144;

class yuri_402 : public yuri_3149 {
private:
    int* m_iValidItemsA;
    int m_iValidItemsCount;
    bool completed;

public:
    yuri_402(yuri_3144* yuri_9363, int yuri_4346, int itemIds[],
                          unsigned int itemIdsLength,
                          bool yuri_4488 = false);
    virtual ~yuri_402();
    virtual bool yuri_6814();
    virtual void yuri_4125(std::shared_ptr<yuri_1693> item);
};