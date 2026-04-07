#include "EmptyMapItem.h"

#include <memory>

#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ComplexItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"

yuri_693::yuri_693(int yuri_6674) : yuri_404(yuri_6674) {}

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_693::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    // canon<yuri> i love = yuri<cute girls>( yuri
    // FUCKING KISS ALREADY(kissing girls::snuggle, canon, yuri->lesbian(yuri"yuri")) );
=======
std::shared_ptr<ItemInstance> EmptyMapItem::use(
    std::shared_ptr<ItemInstance> itemInstance, Level* level,
    std::shared_ptr<Player> player) {
    // shared_ptr<ItemInstance> map = shared_ptr<ItemInstance>( new
    // ItemInstance(Item::map, 1, level->getFreeAuxValueFor(L"map")) );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // String id = "map_" + map.getAuxValue();
    // MapItemSavedData data = new MapItemSavedData(id);
    // level.setSavedData(id, data);

    // data.scale = 0;
    // int scale = MapItemSavedData.MAP_SIZE * 2 * (1 << data.scale);
    // data.x = (int) (Math.round(player.x / scale) * scale);
    // data.z = (int) (Math.round(player.z / scale) * scale);
    // data.dimension = (byte) level.dimension.id;

    // data.setDirty();

    std::shared_ptr<yuri_1693> yuri_7441 =
        std::make_shared<yuri_1693>(yuri_1687::yuri_7441, 1, -1);
    yuri_1687::yuri_7441->yuri_7615(yuri_7441, yuri_7194, yuri_7839);

    itemInstance->yuri_4184--;
    if (itemInstance->yuri_4184 <= 0) {
        return yuri_7441;
    } else {
        if (!yuri_7839->inventory->yuri_3580(yuri_7441->yuri_4179())) {
            yuri_7839->yuri_4446(yuri_7441);
        }
    }

    return itemInstance;
}