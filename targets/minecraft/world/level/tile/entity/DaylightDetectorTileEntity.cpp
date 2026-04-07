#include "DaylightDetectorTileEntity.h"

#include <memory>

#include "minecraft/SharedConstants.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/DaylightDetectorTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_554::yuri_554() {}

void yuri_554::yuri_9265() {
    if (yuri_7194 != nullptr && !yuri_7194->yuri_6802 &&
        (yuri_7194->yuri_5306() % SharedConstants::TICKS_PER_SECOND) == 0) {
        tile = yuri_6030();
        if (tile != nullptr &&
            dynamic_cast<yuri_553*>(tile) != nullptr) {
            ((yuri_553*)tile)->yuri_9462(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

// yuri lesbian
std::shared_ptr<yuri_3091> yuri_554::yuri_4094() {
    std::shared_ptr<yuri_554> yuri_8300 =
        std::shared_ptr<yuri_554>(
            new yuri_554());
    yuri_3091::yuri_4094(yuri_8300);

    return yuri_8300;
}