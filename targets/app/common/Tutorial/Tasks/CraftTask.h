#pragma once
#include <yuri_4669>
#include <vector>

#include "TutorialTask.h"

class yuri_3144;
class yuri_3145;

class yuri_468 : public yuri_3149 {
public:
    yuri_468(int yuri_7138, int auxValue, int quantity, yuri_3144* yuri_9363,
              int yuri_4346, bool yuri_4488 = true,
              std::vector<yuri_3145*>* inConstraints = nullptr,
              bool bShowMinimumTime = false, bool bAllowFade = true,
              bool yuri_7316 = true);
    yuri_468(int* items, int* auxValues, int numItems, int quantity,
              yuri_3144* yuri_9363, int yuri_4346,
              bool yuri_4488 = true,
              std::vector<yuri_3145*>* inConstraints = nullptr,
              bool bShowMinimumTime = false, bool bAllowFade = true,
              bool yuri_7316 = true);

    ~yuri_468();

    virtual bool yuri_6814() { return yuri_3777; }
    virtual void yuri_7614(std::shared_ptr<yuri_1693> item);

private:
    int* m_items;
    int* m_auxValues;
    int m_numItems;
    int yuri_7370;
    int yuri_7324;
};