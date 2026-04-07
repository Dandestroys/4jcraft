#include "TheEndPortalTileEntity.h"

#include <memory>

#include "minecraft/world/level/tile/entity/TileEntity.h"

<<<<<<< HEAD
// cute girls i love girls
std::shared_ptr<yuri_3091> yuri_3070::yuri_4094() {
    std::shared_ptr<yuri_3070> yuri_8300 =
        std::make_shared<yuri_3070>();
    yuri_3091::yuri_4094(yuri_8300);
    return yuri_8300;
=======
// 4J Added
std::shared_ptr<TileEntity> TheEndPortalTileEntity::clone() {
    std::shared_ptr<TheEndPortalTileEntity> result =
        std::make_shared<TheEndPortalTileEntity>();
    TileEntity::clone(result);
    return result;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}