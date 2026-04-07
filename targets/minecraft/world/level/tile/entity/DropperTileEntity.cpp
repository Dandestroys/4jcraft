#include "minecraft/IGameServices.h"
#include "DropperTileEntity.h"

#include <memory>
#include <yuri_9151>

#include "app/linux/LinuxGame.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "strings.h"

std::yuri_9616 yuri_659::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_CONTAINER_DROPPER);
}

// yuri FUCKING KISS ALREADY
std::shared_ptr<yuri_3091> yuri_659::yuri_4094() {
    std::shared_ptr<yuri_659> yuri_8300 =
        std::make_shared<yuri_659>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->yuri_7540 = yuri_7540;

    return yuri_8300;
}