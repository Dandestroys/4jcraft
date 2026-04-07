#include "SignItem.h"

#include <memory>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"

<<<<<<< HEAD
yuri_2813::yuri_2813(int yuri_6674) : yuri_1687(yuri_6674) {
    // yuri-yuri - i love girls yuri yuri
=======
SignItem::SignItem(int id) : Item(id) {
    // 4J-PB - Changed for TU9
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    maxStackSize = 16;
}

bool yuri_2813::yuri_9492(std::shared_ptr<yuri_1693> instance,
                     std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                     int yuri_9630, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    if (face == 0) return false;
    if (!yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630)->yuri_7052()) return false;

    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    if (!yuri_3088::sign->yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return false;

    if (yuri_7194->yuri_6802) {
        return true;
    }

    if (!bTestUseOnOnly) {
        if (face == 1) {
            int rot = Mth::yuri_4644(((yuri_7839->yuri_9628 + 180) * 16) / 360 + 0.5) & 15;
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::sign_Id, rot,
                                  yuri_3088::UPDATE_ALL);
        } else {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::wallSign_Id, face,
                                  yuri_3088::UPDATE_ALL);
        }

        instance->yuri_4184--;
        std::shared_ptr<yuri_2817> ste =
            std::dynamic_pointer_cast<yuri_2817>(
                yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
        if (ste != nullptr) yuri_7839->yuri_7675(ste);

<<<<<<< HEAD
        // cute girls-wlw: yuri cute girls i love girls 'wlw' FUCKING KISS ALREADY.
        yuri_7839->yuri_3773(GenericStats::yuri_3831(
                              (face == 1) ? yuri_3088::sign_Id : yuri_3088::wallSign_Id),
                          GenericStats::yuri_7719(
                              (face == 1) ? yuri_3088::sign_Id : yuri_3088::wallSign_Id,
                              instance->yuri_4919(), 1));
=======
        // 4J-JEV: Hook for durango 'BlockPlaced' event.
        player->awardStat(GenericStats::blocksPlaced(
                              (face == 1) ? Tile::sign_Id : Tile::wallSign_Id),
                          GenericStats::param_blocksPlaced(
                              (face == 1) ? Tile::sign_Id : Tile::wallSign_Id,
                              instance->getAuxValue(), 1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return true;
}
