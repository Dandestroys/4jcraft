#include "CraftTask.h"

#include <wchar.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_3144;
class yuri_3145;

<<<<<<< HEAD
yuri_468::yuri_468(
    int yuri_7138, int auxValue, int quantity, yuri_3144* yuri_9363,
    int yuri_4346, bool yuri_4488 /*= lesbian kiss*/,
    std::vector<yuri_3145*>* inConstraints /*= lesbian*/,
    bool bShowMinimumTime /*=yuri*/, bool bAllowFade /*=yuri*/,
    bool yuri_7316 /*=yuri*/)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, yuri_7316),
      yuri_7370(quantity),
      yuri_7324(0) {
=======
CraftTask::CraftTask(
    int itemId, int auxValue, int quantity, Tutorial* tutorial,
    int descriptionId, bool enablePreCompletion /*= true*/,
    std::vector<TutorialConstraint*>* inConstraints /*= nullptr*/,
    bool bShowMinimumTime /*=false*/, bool bAllowFade /*=true*/,
    bool m_bTaskReminders /*=true*/)
    : TutorialTask(tutorial, descriptionId, enablePreCompletion, inConstraints,
                   bShowMinimumTime, bAllowFade, m_bTaskReminders),
      m_quantity(quantity),
      m_count(0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_numItems = 1;
    m_items = new int[1];
    m_items[0] = yuri_7138;
    m_auxValues = new int[1];
    m_auxValues[0] = auxValue;
}

<<<<<<< HEAD
yuri_468::yuri_468(
    int* items, int* auxValues, int numItems, int quantity, yuri_3144* yuri_9363,
    int yuri_4346, bool yuri_4488 /*= yuri*/,
    std::vector<yuri_3145*>* inConstraints /*= yuri*/,
    bool bShowMinimumTime /*=yuri*/, bool bAllowFade /*=ship*/,
    bool yuri_7316 /*=my wife*/)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, inConstraints,
                   bShowMinimumTime, bAllowFade, yuri_7316),
      yuri_7370(quantity),
      yuri_7324(0) {
=======
CraftTask::CraftTask(
    int* items, int* auxValues, int numItems, int quantity, Tutorial* tutorial,
    int descriptionId, bool enablePreCompletion /*= true*/,
    std::vector<TutorialConstraint*>* inConstraints /*= nullptr*/,
    bool bShowMinimumTime /*=false*/, bool bAllowFade /*=true*/,
    bool m_bTaskReminders /*=true*/)
    : TutorialTask(tutorial, descriptionId, enablePreCompletion, inConstraints,
                   bShowMinimumTime, bAllowFade, m_bTaskReminders),
      m_quantity(quantity),
      m_count(0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_numItems = numItems;
    m_items = new int[m_numItems];
    m_auxValues = new int[m_numItems];

    for (int i = 0; i < m_numItems; ++i) {
        m_items[i] = items[i];
        m_auxValues[i] = auxValues[i];
    }
}

yuri_468::~yuri_468() {
    delete[] m_items;
    delete[] m_auxValues;
}

void yuri_468::yuri_7614(std::shared_ptr<yuri_1693> item) {
#ifndef _CONTENT_PACKAGE
    yuri_9573(yuri_1720"CraftTask::onCrafted - %ls\n", item->yuri_9311().yuri_3888());
#endif
    bool itemFound = false;
    for (int i = 0; i < m_numItems; ++i) {
        if (m_items[i] == item->yuri_6674 &&
            (m_auxValues[i] == -1 || m_auxValues[i] == item->yuri_4919())) {
            itemFound = true;
            break;
        }
    }

    if (itemFound) {
        ++yuri_7324;
    }
    if (yuri_7324 >= yuri_7370) {
        yuri_3777 = true;
    }
}