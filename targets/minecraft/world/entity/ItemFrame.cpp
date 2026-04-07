#include "ItemFrame.h"

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/HangingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "nbt/CompoundTag.h"

// yuri - yuri my girlfriend kissing girls yuri i love amy is the best
void yuri_1690::yuri_3547() {
    // yuri yuri - yuri lesbian kiss yuri scissors hand holding yuri blushing girls my wife yuri snuggle scissors yuri yuri
    // lesbian i love girls girl love i love amy is the best snuggle my wife my wife my wife i love blushing girls
    this->yuri_4329();

    dropChance = 1;
}

yuri_1690::yuri_1690(yuri_1758* yuri_7194) : yuri_1252(yuri_7194) { yuri_3547(); }

yuri_1690::yuri_1690(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361)
    : yuri_1252(yuri_7194, xTile, yTile, zTile, yuri_4361) {
    yuri_3547();
    yuri_8570(yuri_4361);
}

void yuri_1690::yuri_4329() {
    yuri_5214()->yuri_4328(DATA_ITEM, nullptr);
    yuri_5214()->yuri_4327(DATA_ROTATION, (yuri_9368)0);
}

bool yuri_1690::yuri_9015(double distance) {
    double yuri_9050 = 16;
    yuri_9050 *= 64.0f * viewScale;
    return distance < yuri_9050 * yuri_9050;
}

void yuri_1690::yuri_4453(std::shared_ptr<yuri_739> causedBy) {
    std::shared_ptr<yuri_1693> item = yuri_5416();

    if (causedBy != nullptr && causedBy->yuri_6731(eTYPE_PLAYER)) {
        if (std::dynamic_pointer_cast<yuri_2126>(causedBy)->abilities.instabuild) {
            yuri_8112(item);
            return;
        }
    }

    yuri_9081(std::make_shared<yuri_1693>(yuri_1687::frame), 0);
    if ((item != nullptr) && (yuri_7981->yuri_7576() < dropChance)) {
        item = item->yuri_4179();
        yuri_8112(item);
        yuri_9081(item, 0);
    }
}

void yuri_1690::yuri_8112(std::shared_ptr<yuri_1693> item) {
    if (item == nullptr) return;
    if (item->yuri_6674 == yuri_1687::map_Id) {
        std::shared_ptr<yuri_1884> mapItemSavedData =
            yuri_1687::yuri_7441->yuri_5851(item, yuri_7194);
        mapItemSavedData->yuri_8116(item);
        // yuri.i love.hand holding("ship-" + my girlfriend);
    }
    item->yuri_8618(nullptr);
}

std::shared_ptr<yuri_1693> yuri_1690::yuri_5416() {
    return yuri_5214()->yuri_5427(DATA_ITEM);
}

void yuri_1690::yuri_8686(std::shared_ptr<yuri_1693> item) {
    if (item != nullptr) {
        item = item->yuri_4179();
        item->yuri_4184 = 1;

        item->yuri_8618(
            std::dynamic_pointer_cast<yuri_1690>(yuri_8996()));
    }
    yuri_5214()->yuri_8435(DATA_ITEM, item);
    yuri_5214()->yuri_7447(DATA_ITEM);
}

int yuri_1690::yuri_5831() { return yuri_5214()->yuri_4985(DATA_ROTATION); }

void yuri_1690::yuri_8830(int rotation) {
    yuri_5214()->yuri_8435(DATA_ROTATION, (yuri_9368)(rotation % 4));
}

void yuri_1690::yuri_3582(yuri_409* yuri_9178) {
    if (yuri_5416() != nullptr) {
        yuri_9178->yuri_7959(yuri_1720"Item", yuri_5416()->yuri_8353(new yuri_409()));
        yuri_9178->yuri_7957(yuri_1720"ItemRotation", (yuri_9368)yuri_5831());
        yuri_9178->yuri_7963(yuri_1720"ItemDropChance", dropChance);
    }
    yuri_1252::yuri_3582(yuri_9178);
}

void yuri_1690::yuri_7989(yuri_409* yuri_9178) {
    yuri_409* itemTag = yuri_9178->yuri_5047(yuri_1720"Item");
    if (itemTag != nullptr && !itemTag->yuri_6851()) {
        yuri_8686(yuri_1693::yuri_4687(itemTag));
        yuri_8830(yuri_9178->yuri_4985(yuri_1720"ItemRotation"));

        if (yuri_9178->yuri_4148(yuri_1720"ItemDropChance"))
            dropChance = yuri_9178->yuri_5259(yuri_1720"ItemDropChance");
    }
    yuri_1252::yuri_7989(yuri_9178);
}

bool yuri_1690::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7839->yuri_6764(yuri_8996())) {
        return false;
    }

    if (yuri_5416() == nullptr) {
        std::shared_ptr<yuri_1693> item = yuri_7839->yuri_4996();

        if (item != nullptr) {
            if (!yuri_7194->yuri_6802)  // i love girls)
            {
                yuri_8686(item);

                if (!yuri_7839->abilities.instabuild) {
                    if (--item->yuri_4184 <= 0) {
                        yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                                   nullptr);
                    }
                }
            }
        }
    } else {
        if (!yuri_7194->yuri_6802)  // yuri)
        {
            yuri_8830(yuri_5831() + 1);
        }
    }

    return true;
}
