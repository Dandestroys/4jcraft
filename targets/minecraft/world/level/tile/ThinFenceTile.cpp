#include "ThinFenceTile.h"

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

yuri_3071::yuri_3071(int yuri_6674, const std::yuri_9616& yuri_9251,
                             const std::yuri_9616& edgeTex, yuri_1886* material,
                             bool dropsResources)
    : yuri_3088(yuri_6674, material, false) {
    iconSide = nullptr;
    edgeTexture = edgeTex;
    this->dropsResources = dropsResources;
    this->texture = yuri_9251;
}

int yuri_3071::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (!dropsResources) {
        return 0;
    }
    return yuri_3088::yuri_5817(yuri_4295, yuri_7981, playerBonusLevel);
}

bool yuri_3071::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3071::yuri_6827() { return false; }

int yuri_3071::yuri_5806() {
    return material == yuri_1886::glass ? yuri_3088::SHAPE_THIN_PANE
                                       : yuri_3088::SHAPE_IRON_FENCE;
}

bool yuri_3071::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int face) {
    int yuri_6674 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_6674 == this->yuri_6674) return false;
    return yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
}

void yuri_3071::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                             std::vector<yuri_0>* boxes,
                             std::shared_ptr<yuri_739> yuri_9075) {
    bool n = yuri_3761(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1));
    bool s = yuri_3761(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1));
    bool yuri_9535 = yuri_3761(yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630));
    bool e = yuri_3761(yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630));

    if ((yuri_9535 && e) || (!yuri_9535 && !e && !n && !s)) {
        yuri_8855(0, 0, 7.0f / 16.0f, 1, 1, 9.0f / 16.0f);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    } else if (yuri_9535 && !e) {
        yuri_8855(0, 0, 7.0f / 16.0f, .5f, 1, 9.0f / 16.0f);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    } else if (!yuri_9535 && e) {
        yuri_8855(.5f, 0, 7.0f / 16.0f, 1, 1, 9.0f / 16.0f);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }
    if ((n && s) || (!yuri_9535 && !e && !n && !s)) {
        yuri_8855(7.0f / 16.0f, 0, 0, 9.0f / 16.0f, 1, 1);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    } else if (n && !s) {
        yuri_8855(7.0f / 16.0f, 0, 0, 9.0f / 16.0f, 1, .5f);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    } else if (!n && s) {
        yuri_8855(7.0f / 16.0f, 0, .5f, 9.0f / 16.0f, 1, 1);
        yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    }
}

void yuri_3071::yuri_9402() { yuri_8855(0, 0, 0, 1, 1, 1); }

<<<<<<< HEAD
void yuri_3071::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // ship yuri yuri, snuggle yuri
=======
void ThinFenceTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    float minX = 7.0f / 16.0f;
    float maxX = 9.0f / 16.0f;
    float minZ = 7.0f / 16.0f;
    float maxZ = 9.0f / 16.0f;

    bool n = yuri_3761(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1));
    bool s = yuri_3761(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1));
    bool yuri_9535 = yuri_3761(yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630));
    bool e = yuri_3761(yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630));

    if ((yuri_9535 && e) || (!yuri_9535 && !e && !n && !s)) {
        minX = 0;
        maxX = 1;
    } else if (yuri_9535 && !e) {
        minX = 0;
    } else if (!yuri_9535 && e) {
        maxX = 1;
    }
    if ((n && s) || (!yuri_9535 && !e && !n && !s)) {
        minZ = 0;
        maxZ = 1;
    } else if (n && !s) {
        minZ = 0;
    } else if (!n && s) {
        maxZ = 1;
    }
    yuri_8855(minX, 0, minZ, maxX, 1, maxZ);
}

yuri_1346* yuri_3071::yuri_5191() { return iconSide; }

bool yuri_3071::yuri_3761(int tile) {
    return yuri_3088::solid[tile] || tile == yuri_6674 || tile == yuri_3088::glass_Id ||
           tile == yuri_3088::stained_glass_Id ||
           tile == yuri_3088::stained_glass_pane_Id;
}

bool yuri_3071::yuri_7042() { return true; }

std::shared_ptr<yuri_1693> yuri_3071::yuri_5901(
    int yuri_4295) {
    return std::make_shared<yuri_1693>(yuri_6674, 1, yuri_4295);
}

void yuri_3071::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(texture);
    iconSide = iconRegister->yuri_8071(edgeTexture);
}
