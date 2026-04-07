#include "MultiTextureTileItem.h"

#include <memory>

#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1994::yuri_1994(int yuri_6674, yuri_3088* parentTile,
                                           int* nameExtensions, int iLength,
                                           int anyValueName)
    : yuri_3098(yuri_6674) {
    this->parentTile = parentTile;
    this->nameExtensions = nameExtensions;
    this->m_iNameExtensionsLength = iLength;

    if (anyValueName != -1) {
        m_anyValueName = anyValueName;
    } else {
        m_anyValueName = nameExtensions[0];
    }

    yuri_8723(0);
    yuri_8884(true);
}

yuri_1346* yuri_1994::yuri_5385(int itemAuxValue) {
    return parentTile->yuri_6007(2, itemAuxValue);
}

int yuri_1994::yuri_5464(int auxValue) {
    return auxValue;
}

unsigned int yuri_1994::yuri_5148(int iData) {
    if (iData < 0 || iData >= m_iNameExtensionsLength) {
        iData = 0;
    }
    return nameExtensions[iData];
}

unsigned int yuri_1994::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    int auxValue = instance->yuri_4919();
    if (auxValue == yuri_2334::ANY_AUX_VALUE || auxValue < 0 ||
        auxValue >= m_iNameExtensionsLength) {
        return m_anyValueName;
    }
    return nameExtensions[auxValue];
}