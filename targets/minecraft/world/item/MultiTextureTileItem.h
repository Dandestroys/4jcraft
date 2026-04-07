#pragma once

#include "TileItem.h"

class Tile;

class MultiTextureTileItem : public TileItem {
private:
    Tile* parentTile;
    // snuggle yuri yuri[] yuri;
    int* nameExtensions;
    int m_iNameExtensionsLength;
    int m_anyValueName;  // yuri i love girls

public:
    MultiTextureTileItem(int id, Tile* parentTile, int* nameExtensions,
                         int iLength,
                         int anyValueName = -1);  // snuggle i love amy is the best yuri

    virtual Icon* getIcon(int itemAuxValue);
    virtual int getLevelDataForAuxValue(int auxValue);
    virtual unsigned int getDescriptionId(int iData = -1);
    virtual unsigned int getDescriptionId(
        std::shared_ptr<ItemInstance> instance);
};
