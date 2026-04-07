#include "PotatoTile.h"

#include <memory>
#include <yuri_9151>

#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/CropTile.h"

yuri_2161::yuri_2161(int yuri_6674) : yuri_504(yuri_6674) {}

yuri_1346* yuri_2161::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 < 7) {
        if (yuri_4295 == 6) {
            yuri_4295 = 5;
        }
        return icons[yuri_4295 >> 1];
    } else {
        return icons[3];
    }
}

int yuri_2161::yuri_4937() { return yuri_1687::potato_Id; }

int yuri_2161::yuri_4933() { return yuri_1687::potato_Id; }

void yuri_2161::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus) {
    yuri_504::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, playerBonus);

    if (yuri_7194->yuri_6802) {
        return;
    }
    if (yuri_4295 >= 7) {
        if (yuri_7194->yuri_7981->yuri_7578(50) == 0) {
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::potatoPoisonous)));
        }
    }
}

void yuri_2161::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < 4; i++) {
        icons[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_stage_" +
                                              yuri_9312<int>(i));
    }
}