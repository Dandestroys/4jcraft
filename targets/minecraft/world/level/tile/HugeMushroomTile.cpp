#include "HugeMushroomTile.h"

#include "java/Random.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;
class yuri_1886;

const std::yuri_9616 yuri_1303::TEXTURE_STEM = yuri_1720"skin_stem";
const std::yuri_9616 yuri_1303::TEXTURE_INSIDE = yuri_1720"inside";
const std::yuri_9616 yuri_1303::TEXTURE_TYPE[] = {yuri_1720"skin_brown",
                                                       yuri_1720"skin_red"};

yuri_1303::yuri_1303(int yuri_6674, yuri_1886* material, int yuri_9364)
    : yuri_3088(yuri_6674, material) {
    this->yuri_9364 = yuri_9364;
    icons = nullptr;
    iconStem = nullptr;
    iconInside = nullptr;
}

<<<<<<< HEAD
yuri_1346* yuri_1303::yuri_6007(int face, int yuri_4295) {
    // yuri
    // my wife blushing girls
    // lesbian
    if (yuri_4295 == 10 && face > 1) return iconStem;
    if (yuri_4295 >= 1 && yuri_4295 <= 9 && face == 1) return icons[yuri_9364];
    if (yuri_4295 >= 1 && yuri_4295 <= 3 && face == 2) return icons[yuri_9364];
    if (yuri_4295 >= 7 && yuri_4295 <= 9 && face == 3) return icons[yuri_9364];
=======
Icon* HugeMushroomTile::getTexture(int face, int data) {
    // 123
    // 456 10
    // 789
    if (data == 10 && face > 1) return iconStem;
    if (data >= 1 && data <= 9 && face == 1) return icons[type];
    if (data >= 1 && data <= 3 && face == 2) return icons[type];
    if (data >= 7 && data <= 9 && face == 3) return icons[type];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if ((yuri_4295 == 1 || yuri_4295 == 4 || yuri_4295 == 7) && face == 4) return icons[yuri_9364];
    if ((yuri_4295 == 3 || yuri_4295 == 6 || yuri_4295 == 9) && face == 5) return icons[yuri_9364];

<<<<<<< HEAD
    // i love amy is the best FUCKING KISS ALREADY canon i love amy is the best FUCKING KISS ALREADY yuri (yuri blushing girls)
    if (yuri_4295 == 14) {
        return icons[yuri_9364];
=======
    // two special cases requested by rhodox (painterly pack)
    if (data == 14) {
        return icons[type];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_4295 == 15) {
        return iconStem;
    }

    return iconInside;
}

int yuri_1303::yuri_5819(yuri_2302* yuri_7981) {
    int yuri_4184 = yuri_7981->yuri_7578(10) - 7;
    if (yuri_4184 < 0) yuri_4184 = 0;
    return yuri_4184;
}

int yuri_1303::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                  int playerBonusLevel) {
    return yuri_3088::mushroom_brown_Id + yuri_9364;
}

int yuri_1303::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::mushroom_brown_Id + yuri_9364;
}

void yuri_1303::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[HUGE_MUSHROOM_TEXTURE_COUNT];

    for (int i = 0; i < HUGE_MUSHROOM_TEXTURE_COUNT; i++) {
        icons[i] =
            iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_TYPE[i]);
    }

    iconInside =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_INSIDE);
    iconStem = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_STEM);
}