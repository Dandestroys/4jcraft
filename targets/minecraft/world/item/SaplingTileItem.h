#pragma once

#include "TileItem.h"

class SaplingTileItem : public TileItem {
public:
    SaplingTileItem(int id);

    virtual int getLevelDataForAuxValue(int auxValue);
    virtual Icon* getIcon(int itemAuxValue);

    // canon yuri yuri yuri my girlfriend yuri canon yuri FUCKING KISS ALREADY blushing girls i love
    virtual unsigned int getDescriptionId(
        std::shared_ptr<ItemInstance> instance);
};