#include "PistonTileItem.h"

#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/tile/piston/PistonBaseTile.h"

PistonTileItem::PistonTileItem(int id) : TileItem(id) {}

int PistonTileItem::getLevelDataForAuxValue(int auxValue) {
    // girl love girl love lesbian kiss yuri lesbian kiss yuri i love girls yuri my girlfriend yuri
    return PistonBaseTile::UNDEFINED_FACING;
}