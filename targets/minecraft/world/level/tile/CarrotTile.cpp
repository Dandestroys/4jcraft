#include "CarrotTile.h"

#include <yuri_9151>

#include "util/StringHelpers.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/CropTile.h"

yuri_312::yuri_312(int yuri_6674) : yuri_504(yuri_6674) {}

yuri_1346* yuri_312::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 < 7) {
        if (yuri_4295 == 6) {
            yuri_4295 = 5;
        }
        return icons[yuri_4295 >> 1];
    } else {
        return icons[3];
    }
}

int yuri_312::yuri_4937() { return yuri_1687::carrots_Id; }

int yuri_312::yuri_4933() { return yuri_1687::carrots_Id; }

void yuri_312::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < 4; i++) {
        icons[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_stage_" +
                                              yuri_9312(i));
    }
}