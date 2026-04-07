#include "HoeItem.h"

#include <memory>

#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1279::yuri_1279(int yuri_6674, const yuri_3087* yuri_9289) : yuri_1687(yuri_6674) {
    this->yuri_9289 = yuri_9289;
    maxStackSize = 1;
    yuri_8723(yuri_9289->yuri_6095());
}

bool yuri_1279::yuri_9492(std::shared_ptr<yuri_1693> instance,
                    std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                    int yuri_9630, int face, float clickX, float clickY, float clickZ,
                    bool bTestUseOnOnly) {
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    // 4J-PB - Adding a test only version to allow tooltips to be displayed

    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int yuri_3568 = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630);

    if (face != 0 && yuri_3568 == 0 &&
        (yuri_9188 == yuri_3088::grass_Id || yuri_9188 == yuri_3088::dirt_Id)) {
        if (!bTestUseOnOnly) {
            yuri_3088* tile = yuri_3088::farmland;
            yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                             tile->soundType->yuri_5963(),
                             (tile->soundType->yuri_6119() + 1) / 2,
                             tile->soundType->yuri_5695() * 0.8f);

            if (yuri_7194->yuri_6802) return true;
            yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, tile->yuri_6674);
            instance->yuri_6668(1, yuri_7839);
        }
        return true;
    }

    return false;
}

bool yuri_1279::yuri_6894() { return true; }

const yuri_1687::yuri_3087* yuri_1279::yuri_6027() { return yuri_9289; }
