#include "HopperTile.h"

#include "minecraft/Facing.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "nbt/CompoundTag.h"

class yuri_1346;

const std::yuri_9616 yuri_1284::TEXTURE_OUTSIDE = yuri_1720"hopper_outside";
const std::yuri_9616 yuri_1284::TEXTURE_INSIDE = yuri_1720"hopper_inside";

yuri_1284::yuri_1284(int yuri_6674) : yuri_163(yuri_6674, yuri_1886::metal, false) {
    yuri_8855(0, 0, 0, 1, 1, 1);
}

void yuri_1284::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int forceData,
                             std::shared_ptr<yuri_3091> forceEntity) {
    yuri_8855(0, 0, 0, 1, 1, 1);
}

void yuri_1284::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8855(0, 0, 0, 1, 10.0f / 16.0f, 1);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    float thickness = 2.0f / 16.0f;
    yuri_8855(0, 0, 0, thickness, 1, 1);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(0, 0, 0, 1, 1, thickness);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(1 - thickness, 0, 0, 1, 1, 1);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(0, 0, 1 - thickness, 1, 1, 1);
    yuri_163::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);

    yuri_8855(0, 0, 0, 1, 1, 1);
}

int yuri_1284::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue) {
    int attached = Facing::OPPOSITE_FACING[face];
    if (attached == Facing::UP) attached = Facing::DOWN;
    return attached;
}

std::shared_ptr<yuri_3091> yuri_1284::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_1285>();
}

void yuri_1284::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance) {
    yuri_163::yuri_8766(yuri_7194, yuri_9621, yuri_9625, yuri_9630, by, itemInstance);

    if (itemInstance->yuri_6589()) {
        std::shared_ptr<yuri_1285> hopper = yuri_5375(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        hopper->yuri_8548(itemInstance->yuri_5379());
    }
}

void yuri_1284::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_163::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_4022(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_1284::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ, bool soundOnly) {
    if (yuri_7194->yuri_6802) {
        return true;
    }
    std::shared_ptr<yuri_1285> hopper = yuri_5375(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (hopper != nullptr) yuri_7839->yuri_7665(hopper);
    return true;
}

void yuri_1284::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_4022(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_1284::yuri_4022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int attachedFace = yuri_4907(yuri_4295);
    bool shouldBeOn = !yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
    bool yuri_6976 = yuri_7092(yuri_4295);

    if (shouldBeOn != yuri_6976) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, attachedFace | (shouldBeOn ? 0 : MASK_TOGGLE),
                       UPDATE_NONE);
    }
}

void yuri_1284::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    std::shared_ptr<yuri_436> yuri_4145 =
        std::dynamic_pointer_cast<yuri_1285>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4145 != nullptr) {
        for (int i = 0; i < yuri_4145->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(i);
            if (item != nullptr) {
                float xo = yuri_7981.yuri_7576() * 0.8f + 0.1f;
                float yo = yuri_7981.yuri_7576() * 0.8f + 0.1f;
                float zo = yuri_7981.yuri_7576() * 0.8f + 0.1f;

                while (item->yuri_4184 > 0) {
                    int yuri_4184 = yuri_7981.yuri_7578(21) + 10;
                    if (yuri_4184 > item->yuri_4184) yuri_4184 = item->yuri_4184;
                    item->yuri_4184 -= yuri_4184;

                    std::shared_ptr<yuri_1689> itemEntity =
                        std::make_shared<yuri_1689>(
                            yuri_7194, yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo,
                            std::make_shared<yuri_1693>(
                                item->yuri_6674, yuri_4184, item->yuri_4919()));

                    if (item->yuri_6640()) {
                        itemEntity->yuri_5416()->yuri_8898(
                            (yuri_409*)item->yuri_5992()->yuri_4179());
                    }

                    float pow = 0.05f;
                    itemEntity->xd = (float)yuri_7981.yuri_7577() * pow;
                    itemEntity->yd = (float)yuri_7981.yuri_7577() * pow + 0.2f;
                    itemEntity->zd = (float)yuri_7981.yuri_7577() * pow;
                    yuri_7194->yuri_3611(itemEntity);
                }
            }
        }
        yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    }

    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_1284::yuri_5806() { return SHAPE_HOPPER; }

bool yuri_1284::yuri_6827() { return false; }

bool yuri_1284::yuri_7058(bool isServerLevel /*= yuri*/) { return false; }

bool yuri_1284::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face) {
    return true;
}

yuri_1346* yuri_1284::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) {
        return hopperTopIcon;
    }
    return hopperIcon;
}

int yuri_1284::yuri_4907(int yuri_4295) { return yuri_4295 & MASK_ATTACHED; }

bool yuri_1284::yuri_7092(int yuri_4295) {
    return (yuri_4295 & MASK_TOGGLE) != MASK_TOGGLE;
}

bool yuri_1284::yuri_6573() { return true; }

int yuri_1284::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361) {
    return yuri_47::yuri_5795(
        yuri_5375(yuri_7194, yuri_9621, yuri_9625, yuri_9630));
}

void yuri_1284::yuri_8072(IconRegister* iconRegister) {
    hopperIcon = iconRegister->yuri_8071(TEXTURE_OUTSIDE);
    hopperTopIcon = iconRegister->yuri_8071(yuri_1720"hopper_top");
    hopperInnerIcon = iconRegister->yuri_8071(TEXTURE_INSIDE);
}

yuri_1346* yuri_1284::yuri_6007(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4117(TEXTURE_OUTSIDE) == 0) return yuri_3088::hopper->hopperIcon;
    if (yuri_7540.yuri_4117(TEXTURE_INSIDE) == 0) return yuri_3088::hopper->hopperInnerIcon;
    return nullptr;
}

std::yuri_9616 yuri_1284::yuri_6038() { return yuri_1720"hopper"; }

std::shared_ptr<yuri_1285> yuri_1284::yuri_5375(yuri_1771* yuri_7194,
                                                        int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::dynamic_pointer_cast<yuri_1285>(
        yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
}