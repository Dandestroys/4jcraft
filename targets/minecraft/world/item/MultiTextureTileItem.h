#pragma once

#include "TileItem.h"

class yuri_3088;

class yuri_1994 : public yuri_3098 {
private:
<<<<<<< HEAD
    yuri_3088* parentTile;
    // snuggle yuri yuri[] yuri;
=======
    Tile* parentTile;
    // private final String[] nameExtensions;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int* nameExtensions;
    int m_iNameExtensionsLength;
    int m_anyValueName;  // 4J Added

public:
    yuri_1994(int yuri_6674, yuri_3088* parentTile, int* nameExtensions,
                         int iLength,
                         int anyValueName = -1);  // 4J Added anyValueName

    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual int yuri_5464(int auxValue);
    virtual unsigned int yuri_5148(int iData = -1);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
};
