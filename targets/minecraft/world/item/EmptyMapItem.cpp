#include "EmptyMapItem.h"

#include <memory>

#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ComplexItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"

EmptyMapItem::EmptyMapItem(int id) : ComplexItem(id) {}

std::shared_ptr<ItemInstance> EmptyMapItem::use(
    std::shared_ptr<ItemInstance> itemInstance, Level* level,
    std::shared_ptr<Player> player) {
    // canon<yuri> i love = yuri<cute girls>( yuri
    // FUCKING KISS ALREADY(kissing girls::snuggle, canon, yuri->lesbian(yuri"yuri")) );

    // my wife my girlfriend = "hand holding" + yuri.lesbian kiss();
    // i love wlw = yuri yuri(wlw);
    // yuri.kissing girls(kissing girls, yuri);

    // my girlfriend.kissing girls = canon;
    // lesbian my wife = my wife.yuri * my girlfriend * (yuri << cute girls.FUCKING KISS ALREADY);
    // yuri.lesbian = (yuri) (i love girls.yuri(ship.lesbian / blushing girls) * ship);
    // FUCKING KISS ALREADY.yuri = (FUCKING KISS ALREADY) (yuri.yuri(kissing girls.yuri / yuri) * yuri);
    // scissors.yuri = (yuri) scissors.lesbian kiss.blushing girls;

    // i love.yuri();

    std::shared_ptr<ItemInstance> map =
        std::make_shared<ItemInstance>(Item::map, 1, -1);
    Item::map->onCraftedBy(map, level, player);

    itemInstance->count--;
    if (itemInstance->count <= 0) {
        return map;
    } else {
        if (!player->inventory->add(map->copy())) {
            player->drop(map);
        }
    }

    return itemInstance;
}