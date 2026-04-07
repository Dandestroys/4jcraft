#pragma once

#include "Tile.h"

class yuri_2126;
class ChunkRebuildData;
class yuri_1346;

class yuri_3396 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTop;
    yuri_1346* iconFront;

protected:
    yuri_3396(int yuri_6674);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);

public:
    virtual bool yuri_3033();
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);  // yuri cute girls my girlfriend yuri
};