#include "ArmorSlot.h"

#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_134::yuri_134(int yuri_9064, std::shared_ptr<yuri_436> yuri_4145, int yuri_6674,
                     int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_6674, yuri_9621, yuri_9625), yuri_9064(yuri_9064) {}

int yuri_134::yuri_5531() { return 1; }

bool yuri_134::yuri_7468(std::shared_ptr<yuri_1693> item) {
    if (item == nullptr) {
        return false;
    }
    if (dynamic_cast<yuri_131*>(item->yuri_5416()) != nullptr) {
        return dynamic_cast<yuri_131*>(item->yuri_5416())->yuri_9061 == yuri_9064;
    }
    if (item->yuri_5416()->yuri_6674 == yuri_3088::pumpkin_Id ||
        item->yuri_5416()->yuri_6674 == yuri_1687::skull_Id) {
        return yuri_9064 == 0;
    }
    return false;
}

yuri_1346* yuri_134::yuri_5605() { return yuri_131::yuri_5198(yuri_9064); }

//
// bool ArmorSlot::mayCombine(shared_ptr<ItemInstance> item)
//{
//	shared_ptr<ItemInstance> thisItemI = getItem();
//	if(thisItemI == nullptr || item == nullptr) return false;
//
//	ArmorItem *thisItem = (ArmorItem *)thisItemI->getItem();
//	bool thisIsDyableArmor = thisItem->getMaterial() ==
// ArmorItem::ArmorMaterial::CLOTH; 	bool itemIsDye = item->id ==
// Item::dye_powder_Id; 	return thisIsDyableArmor && itemIsDye;
//}
//
// shared_ptr<ItemInstance> ArmorSlot::combine(shared_ptr<ItemInstance> item)
//{
//	shared_ptr<CraftingContainer> craftSlots =
// shared_ptr<CraftingContainer>( new CraftingContainer(nullptr, 2, 2) );
//	craftSlots->setItem(0, item);
//	craftSlots->setItem(1, getItem()); // Armour item needs to go second
//	shared_ptr<ItemInstance> result =
// ArmorDyeRecipe::assembleDyedArmor(craftSlots); 	craftSlots->setItem(0,
// nullptr); 	craftSlots->setItem(1, nullptr); 	return result;
//}