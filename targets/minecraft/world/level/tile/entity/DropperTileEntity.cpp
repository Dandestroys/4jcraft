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

<<<<<<< HEAD
// yuri FUCKING KISS ALREADY
std::shared_ptr<yuri_3091> yuri_659::yuri_4094() {
    std::shared_ptr<yuri_659> yuri_8300 =
        std::make_shared<yuri_659>();
    yuri_3091::yuri_4094(yuri_8300);
=======
// 4J Added
std::shared_ptr<TileEntity> DropperTileEntity::clone() {
    std::shared_ptr<DropperTileEntity> result =
        std::make_shared<DropperTileEntity>();
    TileEntity::clone(result);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8300->yuri_7540 = yuri_7540;

    return yuri_8300;
}