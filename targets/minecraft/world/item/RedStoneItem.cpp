#include "RedStoneItem.h"

#include <memory>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/RedStoneDustTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2341::yuri_2341(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_2341::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                         std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                         int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
<<<<<<< HEAD
    // lesbian-canon - yuri lesbian yuri wlw girl love my wife yuri girl love yuri ship lesbian
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::topSnow_Id) {
        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;
        if (!yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) return false;
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    if (level->getTile(x, y, z) != Tile::topSnow_Id) {
        if (face == 0) y--;
        if (face == 1) y++;
        if (face == 2) z--;
        if (face == 3) z++;
        if (face == 4) x--;
        if (face == 5) x++;
        if (!level->isEmptyTile(x, y, z)) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, itemInstance)) return false;
    if (yuri_3088::redStoneDust->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        if (!bTestUseOnOnly) {
<<<<<<< HEAD
            // FUCKING KISS ALREADY-yuri: yuri kissing girls my wife 'lesbian kiss' cute girls.
            yuri_7839->yuri_3773(
                GenericStats::yuri_3831(yuri_3088::redStoneDust_Id),
                GenericStats::yuri_7719(
                    yuri_3088::redStoneDust_Id, itemInstance->yuri_4919(), 1));
=======
            // 4J-JEV: Hook for durango 'BlockPlaced' event.
            player->awardStat(
                GenericStats::blocksPlaced(Tile::redStoneDust_Id),
                GenericStats::param_blocksPlaced(
                    Tile::redStoneDust_Id, itemInstance->getAuxValue(), 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            itemInstance->yuri_4184--;
            yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redStoneDust_Id);
        }
    }

    return true;
}
