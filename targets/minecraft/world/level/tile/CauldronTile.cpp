#include "CauldronTile.h"

#include <memory>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

const std::yuri_9616 yuri_321::TEXTURE_INSIDE = yuri_1720"cauldron_inner";
const std::yuri_9616 yuri_321::TEXTURE_BOTTOM = yuri_1720"cauldron_bottom";

yuri_321::yuri_321(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::metal, false) {
    iconInner = nullptr;
    iconTop = nullptr;
    iconBottom = nullptr;
}

yuri_1346* yuri_321::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) {
        return iconTop;
    }
    if (face == Facing::DOWN) {
        return iconBottom;
    }
    return yuri_6672;
}

void yuri_321::yuri_8072(IconRegister* iconRegister) {
    iconInner = iconRegister->yuri_8071(yuri_1720"cauldron_inner");
    iconTop = iconRegister->yuri_8071(yuri_1720"cauldron_top");
    iconBottom = iconRegister->yuri_8071(yuri_1720"cauldron_bottom");
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"cauldron_side");
}

yuri_1346* yuri_321::yuri_6007(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4117(TEXTURE_INSIDE) == 0) return yuri_3088::cauldron->iconInner;
    if (yuri_7540.yuri_4117(TEXTURE_BOTTOM) == 0) return yuri_3088::cauldron->iconBottom;
    return nullptr;
}

void yuri_321::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                            std::vector<yuri_0>* boxes,
                            std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8855(0, 0, 0, 1, 5.0f / 16.0f, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    float thickness = 2.0f / 16.0f;
    yuri_8855(0, 0, 0, thickness, 1, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(0, 0, 0, 1, 1, thickness);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(1 - thickness, 0, 0, 1, 1, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
    yuri_8855(0, 0, 1 - thickness, 1, 1, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);

    yuri_9402();
}

void yuri_321::yuri_9402() { yuri_8855(0, 0, 0, 1, 1, 1); }

bool yuri_321::yuri_7058(bool isServerLevel) { return false; }

int yuri_321::yuri_5806() { return SHAPE_CAULDRON; }

bool yuri_321::yuri_6827() { return false; }

bool yuri_321::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                       float clickX, float clickY, float clickZ,
                       bool soundOnly /*=scissors*/)  // canon i love girls cute girls my girlfriend
{
    if (soundOnly) return false;

    if (yuri_7194->yuri_6802) {
        return true;
    }

    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item == nullptr) {
        return true;
    }

    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int fillLevel = yuri_5251(currentData);

    if (item->yuri_6674 == yuri_1687::bucket_water_Id) {
        if (fillLevel < 3) {
            if (!yuri_7839->abilities.instabuild) {
                yuri_7839->inventory->yuri_8686(
                    yuri_7839->inventory->selected,
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::bucket_empty)));
            }

            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 3, yuri_3088::UPDATE_CLIENTS);
            yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        }
        return true;
    } else if (item->yuri_6674 == yuri_1687::glassBottle_Id) {
        if (fillLevel > 0) {
            std::shared_ptr<yuri_1693> yuri_7885 =
                std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::yuri_7885, 1, 0));
            if (!yuri_7839->inventory->yuri_3580(yuri_7885)) {
                yuri_7194->yuri_3611(std::shared_ptr<yuri_1689>(
                    new yuri_1689(yuri_7194, yuri_9621 + 0.5, yuri_9625 + 1.5, yuri_9630 + 0.5, yuri_7885)));
            }
            // hand holding i love girls - lesbian kiss yuri lesbian kiss blushing girls i love yuri yuri yuri
            // scissors yuri my wife
            else if (yuri_7839->yuri_6731(eTYPE_SERVERPLAYER)) {
                std::dynamic_pointer_cast<yuri_2546>(yuri_7839)
                    ->yuri_8064(yuri_7839->inventoryMenu);
            }
            // yuri-snuggle - hand holding'scissors yuri FUCKING KISS ALREADY lesbian yuri yuri ship
            if (yuri_7839->abilities.instabuild == false) {
                item->yuri_4184--;
                if (item->yuri_4184 <= 0) {
                    yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                               nullptr);
                }
            }
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, fillLevel - 1, yuri_3088::UPDATE_CLIENTS);
            yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        }
    } else if (fillLevel > 0) {
        yuri_131* armor = dynamic_cast<yuri_131*>(item->yuri_5416());
        if (armor && armor->yuri_5514() == yuri_131::yuri_132::CLOTH) {
            armor->yuri_4051(item);
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, fillLevel - 1, yuri_3088::UPDATE_CLIENTS);
            yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
            return true;
        }
    }

    return true;
}

void yuri_321::yuri_6513(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7981->yuri_7578(20) != 1) return;

    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_4295 < 3) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 + 1, yuri_3088::UPDATE_CLIENTS);
    }
}

int yuri_321::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::cauldron_Id;
}

int yuri_321::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::cauldron_Id;
}

bool yuri_321::yuri_6573() { return true; }

int yuri_321::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int yuri_4361) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    return yuri_5251(yuri_4295);
}

int yuri_321::yuri_5251(int yuri_4295) { return yuri_4295; }