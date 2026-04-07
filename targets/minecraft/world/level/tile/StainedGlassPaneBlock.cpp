#include "StainedGlassPaneBlock.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/ThinFenceTile.h"

class yuri_1346;

yuri_1346* yuri_2895::ICONS[yuri_2895::ICONS_COUNT];
yuri_1346* yuri_2895::EDGE_ICONS[yuri_2895::ICONS_COUNT];

yuri_2895::yuri_2895(int yuri_6674)
    : yuri_3071(yuri_6674, yuri_1720"glass", yuri_1720"glass_pane_top", yuri_1886::glass, false) {}

yuri_1346* yuri_2895::yuri_5388(int face, int yuri_4295) {
    return ICONS[yuri_4295 % ICONS_COUNT];
}

yuri_1346* yuri_2895::yuri_5191(int yuri_4295) {
    return EDGE_ICONS[~yuri_4295 & 0xF];
}

yuri_1346* yuri_2895::yuri_6007(int face, int yuri_4295) {
    return yuri_5388(face, ~yuri_4295 & 0xf);
}

int yuri_2895::yuri_5947(int yuri_4295) { return yuri_4295; }

int yuri_2895::yuri_5419(int yuri_4295) {
    return (yuri_4295 & 0xf);
}

int yuri_2895::yuri_5805() { return 1; }

void yuri_2895::yuri_8072(IconRegister* iconRegister) {
    yuri_3071::yuri_8072(iconRegister);
    for (int i = 0; i < ICONS_COUNT; i++) {
        ICONS[i] = iconRegister->yuri_8071(
            yuri_5386() + yuri_1720"_" +
            yuri_671::COLOR_TEXTURES[yuri_5419(i)]);
        EDGE_ICONS[i] = iconRegister->yuri_8071(
            yuri_5386() + yuri_1720"_pane_top_" +
            yuri_671::COLOR_TEXTURES[yuri_5419(i)]);
    }
}