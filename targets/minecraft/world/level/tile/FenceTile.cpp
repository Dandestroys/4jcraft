#include "FenceTile.h"

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/LeashItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_803::yuri_803(int yuri_6674, const std::yuri_9616& texture, yuri_1886* material)
    : yuri_3088(yuri_6674, material, false) {
    this->texture = texture;
}

void yuri_803::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                         std::vector<yuri_0>* boxes,
                         std::shared_ptr<yuri_739> yuri_9075) {
    bool n = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1);
    bool s = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1);
    bool yuri_9535 = yuri_4140(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630);
    bool e = yuri_4140(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630);

    float yuri_9565 = 6.0f / 16.0f;
    float yuri_4463 = 10.0f / 16.0f;
    float yuri_7588 = 6.0f / 16.0f;
    float yuri_9079 = 10.0f / 16.0f;

    if (n) {
        yuri_7588 = 0;
    }
    if (s) {
        yuri_9079 = 1;
    }
    if (n || s) {
        yuri_8855(yuri_9565, 0, yuri_7588, yuri_4463, 1.5f, yuri_9079);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }
    yuri_7588 = 6.0f / 16.0f;
    yuri_9079 = 10.0f / 16.0f;
    if (yuri_9535) {
        yuri_9565 = 0;
    }
    if (e) {
        yuri_4463 = 1;
    }
    if (yuri_9535 || e || (!n && !s)) {
        yuri_8855(yuri_9565, 0, yuri_7588, yuri_4463, 1.5f, yuri_9079);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }

    if (n) {
        yuri_7588 = 0;
    }
    if (s) {
        yuri_9079 = 1;
    }

    yuri_8855(yuri_9565, 0, yuri_7588, yuri_4463, 1.0f, yuri_9079);
}

void yuri_803::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // hand holding girl love ship, cute girls i love
{
    bool n = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1);
    bool s = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1);
    bool yuri_9535 = yuri_4140(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630);
    bool e = yuri_4140(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630);

    float yuri_9565 = 6.0f / 16.0f;
    float yuri_4463 = 10.0f / 16.0f;
    float yuri_7588 = 6.0f / 16.0f;
    float yuri_9079 = 10.0f / 16.0f;

    if (n) {
        yuri_7588 = 0;
    }
    if (s) {
        yuri_9079 = 1;
    }
    if (yuri_9535) {
        yuri_9565 = 0;
    }
    if (e) {
        yuri_4463 = 1;
    }

    yuri_8855(yuri_9565, 0, yuri_7588, yuri_4463, 1.0f, yuri_9079);
}

bool yuri_803::yuri_7058(bool isServerLevel) { return false; }

bool yuri_803::yuri_6827() { return false; }

bool yuri_803::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return false;
}

int yuri_803::yuri_5806() { return yuri_3088::SHAPE_FENCE; }

bool yuri_803::yuri_4140(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == yuri_6674 || tile == yuri_3088::fenceGate_Id) {
        return true;
    }
    yuri_3088* tileInstance = yuri_3088::tiles[tile];
    if (tileInstance != nullptr) {
        if (tileInstance->material->yuri_7054() &&
            tileInstance->yuri_6827()) {
            return tileInstance->material != yuri_1886::vegetable;
        }
    }
    return false;
}

bool yuri_803::yuri_6865(int tile) {
    return tile == yuri_3088::fence_Id || tile == yuri_3088::netherFence_Id;
}

void yuri_803::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(texture);
}

bool yuri_803::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 int face) {
    return true;
}

bool yuri_803::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                    std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                    float clickX, float clickY, float clickZ, bool soundOnly) {
    if (yuri_7194->yuri_6802) return true;
    if (yuri_1753::yuri_3807(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        return true;
    }
    return false;
}