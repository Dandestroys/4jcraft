#pragma once

#include "BaseRailTile.h"

class yuri_1346;

class yuri_2299 : public yuri_166 {
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTurn;

public:
    yuri_2299(int yuri_6674);

    yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);

protected:
    void yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int yuri_4361,
                     int yuri_9364);
};