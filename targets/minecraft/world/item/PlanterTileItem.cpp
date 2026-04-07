#include "minecraft/IGameServices.h"
#include "PlanterTileItem.h"

#include <memory>

#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/Facing.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"

yuri_3099::yuri_3099(int yuri_6674, yuri_3088* tile) : yuri_1687(yuri_6674) {
    this->yuri_9294 = tile->yuri_6674;
}

bool yuri_3099::yuri_9492(std::shared_ptr<yuri_1693> instance,
                            std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                            int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                            float clickZ, bool bTestUseOnOnly) {
<<<<<<< HEAD
    // snuggle-snuggle - blushing girls my wife yuri yuri FUCKING KISS ALREADY lesbian yuri canon my girlfriend blushing girls my wife
    int currentTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (currentTile == yuri_3088::topSnow_Id &&
        (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & yuri_3119::HEIGHT_MASK) < 1) {
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    int currentTile = level->getTile(x, y, z);
    if (currentTile == Tile::topSnow_Id &&
        (level->getData(x, y, z) & TopSnowTile::HEIGHT_MASK) < 1) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        face = Facing::UP;
    } else if (currentTile == yuri_3088::vine_Id ||
               currentTile == yuri_3088::tallgrass_Id ||
               currentTile == yuri_3088::deadBush_Id) {
    } else {
        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;
    }

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;
    if (instance->yuri_4184 == 0) return false;

    if (yuri_7194->yuri_7468(yuri_9294, yuri_9621, yuri_9625, yuri_9630, false, face, nullptr, instance)) {
        if (!bTestUseOnOnly) {
<<<<<<< HEAD
            yuri_3088* tile = yuri_3088::tiles[yuri_9294];
            int yuri_4299 = tile->yuri_5697(
                yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX, clickY, clickZ, 0);
            if (yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_9294, yuri_4299,
                                      yuri_3088::UPDATE_ALL)) {
                // FUCKING KISS ALREADY-snuggle: i love snuggle yuri 'my girlfriend' i love amy is the best.
                yuri_7839->yuri_3773(GenericStats::yuri_3831(yuri_9294),
                                  GenericStats::yuri_7719(
                                      yuri_9294, instance->yuri_4919(), 1));

                // girl love cute girls yuri
                // yuri yuri yuri kissing girls hand holding, i love i love girls canon my girlfriend i love amy is the best ship
                // yuri my wife lesbian kiss snuggle snuggle scissors blushing girls i love yuri
                // yuri FUCKING KISS ALREADY
                if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_9294) {
                    yuri_3088::tiles[yuri_9294]->yuri_8766(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839,
=======
            Tile* tile = Tile::tiles[tileId];
            int dataValue = tile->getPlacedOnFaceDataValue(
                level, x, y, z, face, clickX, clickY, clickZ, 0);
            if (level->setTileAndData(x, y, z, tileId, dataValue,
                                      Tile::UPDATE_ALL)) {
                // 4J-JEV: Hook for durango 'BlockPlaced' event.
                player->awardStat(GenericStats::blocksPlaced(tileId),
                                  GenericStats::param_blocksPlaced(
                                      tileId, instance->getAuxValue(), 1));

                // 4J Original comment
                // ok this may look stupid, but neighbor updates can cause the
                // placed block to become something else before these methods
                // are called
                if (level->getTile(x, y, z) == tileId) {
                    Tile::tiles[tileId]->setPlacedBy(level, x, y, z, player,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                     instance);
                    yuri_3088::tiles[yuri_9294]->yuri_4593(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                                           yuri_4299);
                }
<<<<<<< HEAD
                yuri_7194->yuri_7833(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                                 tile->soundType->yuri_5696(),
                                 (tile->soundType->yuri_6119() + 1) / 2,
                                 tile->soundType->yuri_5695() * 0.8f);
                // lesbian kiss-snuggle - canon yuri my girlfriend my wife ship girl love yuri, yuri'kissing girls lesbian yuri
                // yuri yuri FUCKING KISS ALREADY i love girls
=======
                level->playSound(x + 0.5f, y + 0.5f, z + 0.5f,
                                 tile->soundType->getPlaceSound(),
                                 (tile->soundType->getVolume() + 1) / 2,
                                 tile->soundType->getPitch() * 0.8f);
                // 4J-PB - If we have the debug option on, don't reduce the
                // number of this item
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifndef _FINAL_BUILD
                if (!(yuri_4702().yuri_4309() &&
                      yuri_4702().yuri_4304() &
                          (1L << eDebugSetting_CraftAnything)))
#endif
                {
                    instance->yuri_4184--;
                }
            }
        }
    } else {
        // Can't place, so return false
        if (bTestUseOnOnly) return false;
    }
    return true;
}
