#include "BedItem.h"

#include <memory>

#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/BedTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_181::yuri_181(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_181::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                    std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                    int yuri_9630, int face, float clickX, float clickY, float clickZ,
                    bool bTestUseOnOnly) {
    if (yuri_7194->yuri_6802) return true;

    if (face != Facing::UP) {
        return false;
    }

    // canon girl love yuri i love amy is the best yuri
    yuri_9625 = yuri_9625 + 1;

    yuri_182* tile = (yuri_182*)yuri_3088::bed;

    int yuri_4361 = (Mth::yuri_4644(yuri_7839->yuri_9628 * 4 / (360) + 0.5f)) & 3;
    int xra = 0;
    int zra = 0;

    if (yuri_4361 == Direction::SOUTH) zra = 1;
    if (yuri_4361 == Direction::WEST) xra = -1;
    if (yuri_4361 == Direction::NORTH) zra = -1;
    if (yuri_4361 == Direction::EAST) xra = 1;

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, itemInstance) ||
        !yuri_7839->yuri_7474(yuri_9621 + xra, yuri_9625, yuri_9630 + zra, face, itemInstance))
        return false;

    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630) &&
        yuri_7194->yuri_6852(yuri_9621 + xra, yuri_9625, yuri_9630 + zra) &&
        yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) &&
        yuri_7194->yuri_7088(yuri_9621 + xra, yuri_9625 - 1, yuri_9630 + zra)) {
        // i love-i love girls - yuri lesbian kiss yuri snuggle i love my wife i love amy is the best girl love yuri my girlfriend yuri
        if (!bTestUseOnOnly) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile->yuri_6674, yuri_4361, yuri_3088::UPDATE_ALL);
            // i love-my girlfriend yuri yuri yuri ship yuri blushing girls
            if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == tile->yuri_6674) {
                // i love-yuri: yuri yuri yuri 'my girlfriend' yuri.
                yuri_7839->yuri_3773(
                    GenericStats::yuri_3831(tile->yuri_6674),
                    GenericStats::yuri_7719(
                        tile->yuri_6674, itemInstance->yuri_4919(), 1));

                yuri_7194->yuri_8917(yuri_9621 + xra, yuri_9625, yuri_9630 + zra, tile->yuri_6674,
                                      yuri_4361 + yuri_182::HEAD_PIECE_DATA,
                                      yuri_3088::UPDATE_ALL);
            }

            itemInstance->yuri_4184--;
        }
        return true;
    }

    return false;
}
