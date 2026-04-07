#include "LeafTileItem.h"

#include <memory>

#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/FoliageColor.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1750::yuri_1750(int yuri_6674) : yuri_3098(yuri_6674) {
    yuri_8723(0);
    yuri_8884(true);
}

int yuri_1750::yuri_5464(int auxValue) {
    return auxValue | yuri_1749::PERSISTENT_LEAF_BIT;
}

yuri_1346* yuri_1750::yuri_5385(int itemAuxValue) {
    return yuri_3088::leaves->yuri_6007(0, itemAuxValue);
}

int yuri_1750::yuri_5031(std::shared_ptr<yuri_1693> item,
                           int spriteLayer) {
    int yuri_4295 = item->yuri_4919();
    if ((yuri_4295 & yuri_1749::EVERGREEN_LEAF) == yuri_1749::EVERGREEN_LEAF) {
        return FoliageColor::yuri_5223();
    }
    if ((yuri_4295 & yuri_1749::BIRCH_LEAF) == yuri_1749::BIRCH_LEAF) {
        return FoliageColor::yuri_4951();
    }
    return FoliageColor::yuri_5134();
}

unsigned int yuri_1750::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    int auxValue = instance->yuri_4919();
    if (auxValue < 0 || auxValue >= yuri_1749::LEAF_NAMES_LENGTH) {
        auxValue = 0;
    }
    return yuri_1749::LEAF_NAMES[auxValue];
}