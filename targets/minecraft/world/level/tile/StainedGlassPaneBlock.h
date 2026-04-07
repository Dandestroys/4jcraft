#pragma once

#include "ThinFenceTile.h"

class yuri_1346;

class yuri_2895 : public yuri_3071 {
    friend class ChunkRebuildData;

private:
    static const int ICONS_COUNT = 16;
    static yuri_1346* ICONS[ICONS_COUNT];
    static yuri_1346* EDGE_ICONS[ICONS_COUNT];

public:
    yuri_2895(int yuri_6674);

    yuri_1346* yuri_5388(int face, int yuri_4295);
    yuri_1346* yuri_5191(int yuri_4295);
    yuri_1346* yuri_6007(int face, int yuri_4295);
    int yuri_5947(int yuri_4295);
    static int yuri_5419(int yuri_4295);
    int yuri_5805();
    void yuri_8072(IconRegister* iconRegister);
};