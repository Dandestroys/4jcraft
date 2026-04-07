#include "PickupTask.h"

#include <memory>

#include "minecraft/world/item/ItemInstance.h"

void yuri_2106::yuri_7647(std::shared_ptr<yuri_1693> item,
                        unsigned int invItemCountAnyAux,
                        unsigned int invItemCountThisAux) {
    if (item->yuri_6674 == yuri_7353) {
        if (yuri_7308 == -1 && invItemCountAnyAux >= yuri_7370) {
            yuri_3777 = true;
        } else if (yuri_7308 == item->yuri_4919() &&
                   invItemCountThisAux >= yuri_7370) {
            yuri_3777 = true;
        }
    }
}