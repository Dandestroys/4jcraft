#include "CompleteUsingItemTask.h"

#include <memory>

#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_3144;

yuri_402::yuri_402(yuri_3144* yuri_9363,
                                             int yuri_4346, int itemIds[],
                                             unsigned int itemIdsLength,
                                             bool yuri_4488)
    : yuri_3149(yuri_9363, yuri_4346, yuri_4488, nullptr) {
    m_iValidItemsA = new int[itemIdsLength];
    for (int i = 0; i < itemIdsLength; i++) {
        m_iValidItemsA[i] = itemIds[i];
    }
    m_iValidItemsCount = itemIdsLength;
}

yuri_402::~yuri_402() { delete[] m_iValidItemsA; }

bool yuri_402::yuri_6814() { return yuri_3777; }

void yuri_402::yuri_4125(
    std::shared_ptr<yuri_1693> item) {
    if (!yuri_6579() && !yuri_6992()) return;
    for (int i = 0; i < m_iValidItemsCount; i++) {
        if (item->yuri_6674 == m_iValidItemsA[i]) {
            yuri_3777 = true;
            break;
        }
    }
}