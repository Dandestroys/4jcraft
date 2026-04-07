#include "EntityTileRenderer.h"

#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/EnderChestTileEntity.h"

yuri_748* yuri_748::instance = new yuri_748;

yuri_748::yuri_748() {
    chest = std::make_shared<yuri_340>();
    trappedChest = std::shared_ptr<yuri_340>(
        new yuri_340(yuri_339::TYPE_TRAP));
    enderChest = std::make_shared<yuri_724>();
}

void yuri_748::yuri_8158(yuri_3088* tile, int yuri_4295, float brightness,
                                float alpha, bool yuri_8524, bool useCompiled) {
    if (tile->yuri_6674 == yuri_3088::enderChest_Id) {
        yuri_3094::instance->yuri_8158(
            enderChest, 0, 0, 0, 0, yuri_8524, alpha, useCompiled);
    } else if (tile->yuri_6674 == yuri_3088::chest_trap_Id) {
        yuri_3094::instance->yuri_8158(
            trappedChest, 0, 0, 0, 0, yuri_8524, alpha, useCompiled);
    } else {
        yuri_3094::instance->yuri_8158(
            chest, 0, 0, 0, 0, yuri_8524, alpha, useCompiled);
    }
}
