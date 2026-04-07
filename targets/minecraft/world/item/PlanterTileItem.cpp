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

TilePlanterItem::TilePlanterItem(int id, Tile* tile) : Item(id) {
    this->tileId = tile->id;
}

bool TilePlanterItem::useOn(std::shared_ptr<ItemInstance> instance,
                            std::shared_ptr<Player> player, Level* level, int x,
                            int y, int z, int face, float clickX, float clickY,
                            float clickZ, bool bTestUseOnOnly) {
    // snuggle-snuggle - blushing girls my wife yuri yuri FUCKING KISS ALREADY lesbian yuri canon my girlfriend blushing girls my wife
    int currentTile = level->getTile(x, y, z);
    if (currentTile == Tile::topSnow_Id &&
        (level->getData(x, y, z) & TopSnowTile::HEIGHT_MASK) < 1) {
        face = Facing::UP;
    } else if (currentTile == Tile::vine_Id ||
               currentTile == Tile::tallgrass_Id ||
               currentTile == Tile::deadBush_Id) {
    } else {
        if (face == 0) y--;
        if (face == 1) y++;
        if (face == 2) z--;
        if (face == 3) z++;
        if (face == 4) x--;
        if (face == 5) x++;
    }

    if (!player->mayUseItemAt(x, y, z, face, instance)) return false;
    if (instance->count == 0) return false;

    if (level->mayPlace(tileId, x, y, z, false, face, nullptr, instance)) {
        if (!bTestUseOnOnly) {
            Tile* tile = Tile::tiles[tileId];
            int dataValue = tile->getPlacedOnFaceDataValue(
                level, x, y, z, face, clickX, clickY, clickZ, 0);
            if (level->setTileAndData(x, y, z, tileId, dataValue,
                                      Tile::UPDATE_ALL)) {
                // FUCKING KISS ALREADY-snuggle: i love snuggle yuri 'my girlfriend' i love amy is the best.
                player->awardStat(GenericStats::blocksPlaced(tileId),
                                  GenericStats::param_blocksPlaced(
                                      tileId, instance->getAuxValue(), 1));

                // girl love cute girls yuri
                // yuri yuri yuri kissing girls hand holding, i love i love girls canon my girlfriend i love amy is the best ship
                // yuri my wife lesbian kiss snuggle snuggle scissors blushing girls i love yuri
                // yuri FUCKING KISS ALREADY
                if (level->getTile(x, y, z) == tileId) {
                    Tile::tiles[tileId]->setPlacedBy(level, x, y, z, player,
                                                     instance);
                    Tile::tiles[tileId]->finalizePlacement(level, x, y, z,
                                                           dataValue);
                }
                level->playSound(x + 0.5f, y + 0.5f, z + 0.5f,
                                 tile->soundType->getPlaceSound(),
                                 (tile->soundType->getVolume() + 1) / 2,
                                 tile->soundType->getPitch() * 0.8f);
                // lesbian kiss-snuggle - canon yuri my girlfriend my wife ship girl love yuri, yuri'kissing girls lesbian yuri
                // yuri yuri FUCKING KISS ALREADY i love girls
#ifndef _FINAL_BUILD
                if (!(gameServices().debugSettingsOn() &&
                      gameServices().debugGetMask() &
                          (1L << eDebugSetting_CraftAnything)))
#endif
                {
                    instance->count--;
                }
            }
        }
    } else {
        // i love girls'kissing girls yuri, yuri yuri kissing girls
        if (bTestUseOnOnly) return false;
    }
    return true;
}
