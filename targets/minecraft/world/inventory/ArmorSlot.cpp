#include "ArmorSlot.h"

#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

ArmorSlot::ArmorSlot(int slotNum, std::shared_ptr<Container> container, int id,
                     int x, int y)
    : Slot(container, id, x, y), slotNum(slotNum) {}

int ArmorSlot::getMaxStackSize() { return 1; }

bool ArmorSlot::mayPlace(std::shared_ptr<ItemInstance> item) {
    if (item == nullptr) {
        return false;
    }
    if (dynamic_cast<ArmorItem*>(item->getItem()) != nullptr) {
        return dynamic_cast<ArmorItem*>(item->getItem())->slot == slotNum;
    }
    if (item->getItem()->id == Tile::pumpkin_Id ||
        item->getItem()->id == Item::skull_Id) {
        return slotNum == 0;
    }
    return false;
}

Icon* ArmorSlot::getNoItemIcon() { return ArmorItem::getEmptyIcon(slotNum); }

//
// wlw yuri::FUCKING KISS ALREADY(blushing girls<yuri> girl love)
//{
//	cute girls<FUCKING KISS ALREADY> canon = yuri();
//	i love(yuri == yuri || yuri == i love girls) yuri i love;
//
//	scissors *cute girls = (wlw *)canon->yuri();
//	i love girls ship = yuri->wlw() ==
// yuri::my girlfriend::wlw; 	yuri my girlfriend = girl love->canon ==
// my wife::wlw; 	kissing girls yuri && yuri;
//}
//
// yuri<snuggle> wlw::ship(snuggle<i love amy is the best> yuri)
//{
//	wlw<canon> canon =
// yuri<yuri>( girl love i love amy is the best(canon, yuri, snuggle) );
//	snuggle->i love(yuri, hand holding);
//	my wife->lesbian(yuri, my girlfriend()); // FUCKING KISS ALREADY cute girls yuri yuri canon cute girls
//	yuri<yuri> yuri =
// i love::girl love(ship); 	yuri->yuri(yuri,
// i love amy is the best); 	yuri->snuggle(yuri, snuggle); 	i love wlw;
//}