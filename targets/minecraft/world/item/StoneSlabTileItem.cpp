#include "StoneSlabTileItem.h"

#include <optional>

#include "minecraft/Facing.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2965::yuri_2965(int yuri_6674, yuri_1235* halfTile,
                                     yuri_1235* fullTile, bool full)
    : yuri_3098(yuri_6674) {
    this->halfTile = halfTile;
    this->fullTile = fullTile;

    isFull = full;
    yuri_8723(0);
    yuri_8884(true);
}

yuri_1346* yuri_2965::yuri_5385(int itemAuxValue) {
    return yuri_3088::tiles[yuri_6674]->yuri_6007(2, itemAuxValue);
}

int yuri_2965::yuri_5464(int auxValue) {
    return auxValue;
}

unsigned int yuri_2965::yuri_5148(
    std::shared_ptr<yuri_1693> instance) {
    return halfTile->yuri_4918(instance->yuri_4919());
}

bool yuri_2965::yuri_9492(std::shared_ptr<yuri_1693> instance,
                              std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                              int yuri_9621, int yuri_9625, int yuri_9630, int face, float clickX,
                              float clickY, float clickZ, bool bTestUseOnOnly) {
    if (isFull) {
        return yuri_3098::yuri_9492(instance, yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX,
                               clickY, clickZ, bTestUseOnOnly);
    }

    if (instance->yuri_4184 == 0) return false;
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int slabType = currentData & yuri_1235::TYPE_MASK;
    bool isUpper = (currentData & yuri_1235::TOP_SLOT_BIT) != 0;

    if (((face == Facing::UP && !isUpper) ||
         (face == Facing::DOWN && isUpper)) &&
        currentTile == halfTile->yuri_6674 && slabType == instance->yuri_4919()) {
        if (bTestUseOnOnly) {
            return true;
        }

        auto tile_bb = fullTile->yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        if (yuri_7194->yuri_7100(tile_bb.yuri_6646() ? &*tile_bb : nullptr) &&
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, fullTile->yuri_6674, slabType,
                                  yuri_3088::UPDATE_ALL)) {
            yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                             fullTile->soundType->yuri_5696(),
                             (fullTile->soundType->yuri_6119() + 1) / 2,
                             fullTile->soundType->yuri_5695() * 0.8f);
            instance->yuri_4184--;
        }
        return true;
    } else if (yuri_9348(instance, yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face,
                                    bTestUseOnOnly)) {
        return true;
    } else {
        return yuri_3098::yuri_9492(instance, yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX,
                               clickY, clickZ, bTestUseOnOnly);
    }
}

bool yuri_2965::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::shared_ptr<yuri_1693> item) {
    int ox = yuri_9621, oy = yuri_9625, oz = yuri_9630;

    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int slabType = currentData & yuri_1235::TYPE_MASK;
    bool isUpper = (currentData & yuri_1235::TOP_SLOT_BIT) != 0;

    if (((face == Facing::UP && !isUpper) ||
         (face == Facing::DOWN && isUpper)) &&
        currentTile == halfTile->yuri_6674 && slabType == item->yuri_4919()) {
        return true;
    }

    if (face == 0) yuri_9625--;
    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

    currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    slabType = currentData & yuri_1235::TYPE_MASK;
    isUpper = (currentData & yuri_1235::TOP_SLOT_BIT) != 0;

    if (currentTile == halfTile->yuri_6674 && slabType == item->yuri_4919()) {
        return true;
    }

    return yuri_3098::yuri_7468(yuri_7194, ox, oy, oz, face, yuri_7839, item);
}

bool yuri_2965::yuri_9348(
    std::shared_ptr<yuri_1693> instance, std::shared_ptr<yuri_2126> yuri_7839,
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face, bool bTestUseOnOnly) {
    if (face == 0) yuri_9625--;
    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int slabType = currentData & yuri_1235::TYPE_MASK;

    if (currentTile == halfTile->yuri_6674 && slabType == instance->yuri_4919()) {
        if (bTestUseOnOnly) {
            return true;
        }
        auto tile_bb = fullTile->yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        if (yuri_7194->yuri_7100(tile_bb.yuri_6646() ? &*tile_bb : nullptr) &&
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, fullTile->yuri_6674, slabType,
                                  yuri_3088::UPDATE_ALL)) {
            yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                             fullTile->soundType->yuri_5696(),
                             (fullTile->soundType->yuri_6119() + 1) / 2,
                             fullTile->soundType->yuri_5695() * 0.8f);
            instance->yuri_4184--;
        }
        return true;
    }

    return false;
}
