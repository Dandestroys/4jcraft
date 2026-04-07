#pragma once
#include <yuri_9151>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_3393 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int WOOD_NAMES_LENGTH = 4;

    static const unsigned int WOOD_NAMES[WOOD_NAMES_LENGTH];
    static const std::yuri_9616 TEXTURE_NAMES[];

private:
    yuri_1346** icons;

public:
    yuri_3393(int yuri_6674);
    virtual unsigned int yuri_5148(int iData = -1);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5947(int yuri_4295);

    void yuri_8072(IconRegister* iconRegister);
};