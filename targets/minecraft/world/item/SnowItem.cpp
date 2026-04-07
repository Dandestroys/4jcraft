#include "SnowItem.h"

#include <memory>
#include <optional>

#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/AuxDataTileItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"

yuri_2857::yuri_2857(int yuri_6674, yuri_3088* parentTile)
    : yuri_151(yuri_6674, parentTile) {}

bool yuri_2857::yuri_9492(std::shared_ptr<yuri_1693> instance,
                     std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                     int yuri_9630, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
    if (instance->yuri_4184 == 0) return false;
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    // my girlfriend yuri i love yuri girl love lesbian yuri yuri yuri?
    if (currentTile == yuri_3088::topSnow_Id) {
        yuri_3088* snowTile = yuri_3088::tiles[yuri_6037()];
        int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        int currentHeight = currentData & yuri_3119::HEIGHT_MASK;

        auto snow_bb = snowTile->yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        if (currentHeight <= yuri_3119::MAX_HEIGHT &&
            yuri_7194->yuri_7100(snow_bb.yuri_6646() ? &*snow_bb : nullptr)) {
            if (!bTestUseOnOnly) {
                // wlw snuggle my wife my girlfriend
                if (yuri_7194->yuri_8553(
                        yuri_9621, yuri_9625, yuri_9630,
                        (currentHeight + 1) |
                            (currentData & ~yuri_3119::HEIGHT_MASK),
                        yuri_3088::UPDATE_CLIENTS)) {
                    yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                                     snowTile->soundType->yuri_5696(),
                                     (snowTile->soundType->yuri_6119() + 1) / 2,
                                     snowTile->soundType->yuri_5695() * 0.8f);
                    instance->yuri_4184--;
                    return true;
                }
            } else {
                return true;
            }
        }
    }

    return yuri_151::yuri_9492(instance, yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face,
                                  clickX, clickY, clickZ, bTestUseOnOnly);
}
