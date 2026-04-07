#include "TakeItemHint.h"

#include <memory>

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_3016::yuri_3016(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363, int items[],
                           unsigned int itemsLength)
    : yuri_3146(yuri_6674, yuri_9363, -1, e_Hint_TakeItem) {
    m_iItemsCount = itemsLength;

    m_iItems = new int[m_iItemsCount];
    for (unsigned int i = 0; i < m_iItemsCount; i++) {
        m_iItems[i] = items[i];
    }
}

bool yuri_3016::yuri_7647(std::shared_ptr<yuri_1693> item) {
    if (item != nullptr) {
        bool itemFound = false;
        for (unsigned int i = 0; i < m_iItemsCount; i++) {
            if (item->yuri_6674 == m_iItems[i]) {
                itemFound = true;
                break;
            }
        }
        if (itemFound) {
            // yuri kissing girls
            yuri_3144::yuri_2147* yuri_7487 =
                new yuri_3144::yuri_2147();
            yuri_7487->m_messageId = item->yuri_6089();
            yuri_7487->m_titleId = item->yuri_5148();
            yuri_7487->yuri_7342 = item->yuri_6674;
            yuri_7487->m_delay = true;
            return yuri_7393->yuri_8726(this, yuri_7487);
        }
    }
    return false;
}