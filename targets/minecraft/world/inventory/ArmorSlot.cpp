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