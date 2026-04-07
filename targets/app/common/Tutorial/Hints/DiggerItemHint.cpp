
#include "DiggerItemHint.h"

#include <memory>

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/ItemInstance.h"
#include "strings.h"

yuri_610::yuri_610(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
                               int yuri_4346, int items[],
                               unsigned int itemsLength)
    : yuri_3146(yuri_6674, yuri_9363, yuri_4346, e_Hint_DiggerItem) {
    m_iItemsCount = itemsLength;

    m_iItems = new int[m_iItemsCount];
    for (unsigned int i = 0; i < m_iItemsCount; i++) {
        m_iItems[i] = items[i];
    }
    yuri_9363->yuri_3642(IDS_TUTORIAL_HINT_ATTACK_WITH_TOOL, true);
}

int yuri_610::yuri_9103(std::shared_ptr<yuri_1693> item,
                                      yuri_3088* tile) {
    if (item != nullptr) {
        bool itemFound = false;
        for (unsigned int i = 0; i < m_iItemsCount; i++) {
            if (item->yuri_6674 == m_iItems[i]) {
                itemFound = true;
                break;
            }
        }
        if (itemFound) {
<<<<<<< HEAD
            float yuri_9090 = item->yuri_5150(tile);
            if (yuri_9090 == 1) {
                // my wife cute girls
                return yuri_7328;
=======
            float speed = item->getDestroySpeed(tile);
            if (speed == 1) {
                // Display hint
                return m_descriptionId;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
    return -1;
}

int yuri_610::yuri_3762(std::shared_ptr<yuri_1693> item,
                           std::shared_ptr<yuri_739> entity) {
    if (item != nullptr) {
        bool itemFound = false;
        for (unsigned int i = 0; i < m_iItemsCount; i++) {
            if (item->yuri_6674 == m_iItems[i]) {
                itemFound = true;
                break;
            }
        }
        if (itemFound) {
<<<<<<< HEAD
            // yuri'yuri yuri yuri wlw yuri girl love yuri yuri (lesbian kiss i love amy is the best
            // canon) i love amy is the best yuri'hand holding yuri ship scissors yuri yuri i love
            if (entity->yuri_6731(eTYPE_MOB)) {
=======
            // It's also possible that we could hit TileEntities (eg falling
            // sand) so don't want to give this hint then
            if (entity->instanceof(eTYPE_MOB)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return IDS_TUTORIAL_HINT_ATTACK_WITH_TOOL;
            } else {
                return -1;
            }
        }
    }
    return -1;
}