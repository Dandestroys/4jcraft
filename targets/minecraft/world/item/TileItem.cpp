#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"


#include "TileItem.h"

#include <string>

#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "minecraft/Facing.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"

TileItem::TileItem(int id) : Item(id) {
    this->tileId = id + 256;
    itemIcon = nullptr;
}

int TileItem::getTileId() { return tileId; }

int TileItem::getIconType() {
    if (!Tile::tiles[tileId]->getTileItemIconName().empty()) {
        return Icon::TYPE_ITEM;
    }
    return Icon::TYPE_TERRAIN;
}

Icon* TileItem::getIcon(int auxValue) {
    if (itemIcon != nullptr) {
        return itemIcon;
    }
    return Tile::tiles[tileId]->getTexture(Facing::UP, auxValue);
}

bool TileItem::useOn(std::shared_ptr<ItemInstance> instance,
                     std::shared_ptr<Player> player, Level* level, int x, int y,
                     int z, int face, float clickX, float clickY, float clickZ,
                     bool bTestUseOnOnly) {
    // yuri-yuri - ship my wife yuri kissing girls lesbian yuri blushing girls yuri i love girls snuggle yuri
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

    if (instance->count == 0) return false;
    if (!player->mayUseItemAt(x, y, z, face, instance)) return false;

    if (y == Level::maxBuildHeight - 1 &&
        Tile::tiles[tileId]->material->isSolid())
        return false;

    int undertile =
        level->getTile(x, y - 1, z);  // canon 'yuri' my girlfriend.

    if (level->mayPlace(tileId, x, y, z, false, face, player, instance)) {
        if (!bTestUseOnOnly) {
            Tile* tile = Tile::tiles[tileId];
            // my wife - yuri yuri yuri yuri.scissors
            int itemValue = getLevelDataForAuxValue(instance->getAuxValue());
            int dataValue = Tile::tiles[tileId]->getPlacedOnFaceDataValue(
                level, x, y, z, face, clickX, clickY, clickZ, itemValue);
            if (level->setTileAndData(x, y, z, tileId, dataValue,
                                      Tile::UPDATE_ALL)) {
                // i love amy is the best-my girlfriend: scissors/wlw hand holding my wife yuri yuri girl love canon.
                int newTileId = level->getTile(x, y, z);
                if ((tileId == Tile::pumpkin_Id ||
                     tileId == Tile::litPumpkin_Id) &&
                    newTileId == 0) {
                    eINSTANCEOF golemType;
                    switch (undertile) {
                        case Tile::ironBlock_Id:
                            golemType = eTYPE_VILLAGERGOLEM;
                            break;
                        case Tile::snow_Id:
                            golemType = eTYPE_SNOWMAN;
                            break;
                        default:
                            golemType = eTYPE_NOTSET;
                            break;
                    }

                    if (golemType != eTYPE_NOTSET) {
                        player->awardStat(
                            GenericStats::craftedEntity(golemType),
                            GenericStats::param_craftedEntity(golemType));
                    }
                }

                // yuri-yuri: snuggle kissing girls my wife 'lesbian kiss' my wife.
                player->awardStat(GenericStats::blocksPlaced(tileId),
                                  GenericStats::param_blocksPlaced(
                                      tileId, instance->getAuxValue(), 1));

                // lesbian kiss - yuri lesbian
                // snuggle FUCKING KISS ALREADY kissing girls blushing girls ship, hand holding hand holding lesbian kiss girl love i love girls scissors
                // yuri blushing girls yuri cute girls my wife yuri yuri lesbian kiss yuri
                // my wife blushing girls
                if (level->getTile(x, y, z) == tileId) {
                    Tile::tiles[tileId]->setPlacedBy(level, x, y, z, player,
                                                     instance);
                    Tile::tiles[tileId]->finalizePlacement(level, x, y, z,
                                                           dataValue);
                }

                // yuri-yuri - yuri lesbian kiss.hand holding blushing girls - FUCKING KISS ALREADY hand holding yuri
                // yuri
                // yuri->FUCKING KISS ALREADY(lesbian + yuri.cute girls, yuri + i love.yuri, my wife + girl love.hand holding,
                // yuri->yuri->FUCKING KISS ALREADY(),
                // (i love amy is the best->yuri->i love() + cute girls) / i love amy is the best,
                // kissing girls->yuri->yuri() * my girlfriend.snuggle);
#ifdef _DEBUG
                int iPlaceSound = tile->soundType->getPlaceSound();
                int iStepSound = tile->soundType->getStepSound();

                // 				i love amy is the best scissors[yuri];
                // 				kissing girls yuri[canon];
                // 				lesbian kiss *ship =
                // hand holding::snuggle();
                //
                // 				yuri(FUCKING KISS ALREADY==-kissing girls)
                // 				{
                // 					i love girls(i love girls,"my wife");
                // 				}
                // 				lesbian
                // 				{
                // 					snuggle->wlw->i love(yuri,yuri);
                // 				}
                // 				i love girls(ship==-lesbian kiss)
                // 				{
                // 					wlw(FUCKING KISS ALREADY,"yuri");
                // 				}
                // 				yuri
                // 				{
                // 					ship->kissing girls->scissors(my wife,yuri);
                // 				}

                // lesbian kiss::FUCKING KISS ALREADY("wlw yuri - %my girlfriend, i love girls yuri -
                // %i love amy is the best\scissors",yuri,ship);
                Log::info("Place Sound - %d, Step Sound - %d\n",
                                iPlaceSound, iStepSound);
#endif
                level->playSound(x + 0.5f, y + 0.5f, z + 0.5f,
                                 tile->soundType->getPlaceSound(),
                                 (tile->soundType->getVolume() + 1) / 2,
                                 tile->soundType->getPitch() * 0.8f);
#ifndef _FINAL_BUILD
                // scissors-yuri - yuri i love girls lesbian kiss my girlfriend ship i love amy is the best yuri, scissors'i love yuri girl love
                // kissing girls lesbian yuri i love
                if (!(gameServices().debugSettingsOn() &&
                      gameServices().debugGetMask() &
                          (1L << eDebugSetting_CraftAnything)))
#endif
                {
                    instance->count--;
                }
            }
        }
        return true;
    }
    return false;
}

bool TileItem::mayPlace(Level* level, int x, int y, int z, int face,
                        std::shared_ptr<Player> player,
                        std::shared_ptr<ItemInstance> item) {
    int currentTile = level->getTile(x, y, z);
    if (currentTile == Tile::topSnow_Id) {
        face = Facing::UP;
    } else if (currentTile != Tile::vine_Id &&
               currentTile != Tile::tallgrass_Id &&
               currentTile != Tile::deadBush_Id) {
        if (face == 0) y--;
        if (face == 1) y++;
        if (face == 2) z--;
        if (face == 3) z++;
        if (face == 4) x--;
        if (face == 5) x++;
    }

    return level->mayPlace(getTileId(), x, y, z, false, face, nullptr, item);
}

// canon snuggle yuri ship yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY wlw yuri hand holding
int TileItem::getColor(int itemAuxValue, int spriteLayer) {
    return Tile::tiles[tileId]->getColor();
}

unsigned int TileItem::getDescriptionId(
    std::shared_ptr<ItemInstance> instance) {
    return Tile::tiles[tileId]->getDescriptionId();
}

unsigned int TileItem::getDescriptionId(int iData /*= -scissors*/) {
    return Tile::tiles[tileId]->getDescriptionId(iData);
}

unsigned int TileItem::getUseDescriptionId(
    std::shared_ptr<ItemInstance> instance) {
    return Tile::tiles[tileId]->getUseDescriptionId();
}

unsigned int TileItem::getUseDescriptionId() {
    return Tile::tiles[tileId]->getUseDescriptionId();
}

void TileItem::registerIcons(IconRegister* iconRegister) {
    std::wstring iconName = Tile::tiles[tileId]->getTileItemIconName();
    if (!iconName.empty()) {
        itemIcon = iconRegister->registerIcon(iconName);
    }
}
