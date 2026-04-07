#include "CoalItem.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "strings.h"

yuri_385::yuri_385(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8884(true);
    yuri_8723(0);
}

unsigned int yuri_385::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    if (instance->yuri_4919() == CHAR_COAL) {
        return IDS_ITEM_CHARCOAL;
    }
    return IDS_ITEM_COAL;
}

yuri_1346* yuri_385::yuri_5385(int auxValue) {
    if (auxValue == CHAR_COAL) {
        return charcoalIcon;
    }
    return yuri_1687::yuri_5385(auxValue);
}

void yuri_385::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);

    charcoalIcon = iconRegister->yuri_8071(yuri_1720"charcoal");
}