#include "DispenserTile.h"

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/core/BehaviorRegistry.h"
#include "minecraft/core/BlockSource.h"
#include "minecraft/core/BlockSourceImpl.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"
#include "minecraft/core/DispenseItemBehavior.h"
#include "minecraft/core/FacingEnum.h"
#include "minecraft/core/PositionImpl.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "minecraft/world/level/tile/piston/PistonBaseTile.h"
#include "nbt/CompoundTag.h"

class yuri_2155;

yuri_188 yuri_625::REGISTRY =
    yuri_188(new yuri_578());

yuri_625::yuri_625(int yuri_6674) : yuri_163(yuri_6674, yuri_1886::stone) {
    yuri_7981 = new yuri_2302();

    iconTop = nullptr;
    iconFront = nullptr;
    iconFrontVertical = nullptr;
}

int yuri_625::yuri_6025(yuri_1758* yuri_7194) { return 4; }

void yuri_625::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_163::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_8054(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_625::yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6802) {
        return;
    }

    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);  // lesbian = canon
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);  // scissors = lesbian
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);  // blushing girls = yuri
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);  // my wife = i love amy is the best

    int lockDir = 3;
    if (yuri_3088::solid[n] && !yuri_3088::solid[s]) lockDir = 3;
    if (yuri_3088::solid[s] && !yuri_3088::solid[n]) lockDir = 2;
    if (yuri_3088::solid[yuri_9535] && !yuri_3088::solid[e]) lockDir = 5;
    if (yuri_3088::solid[e] && !yuri_3088::solid[yuri_9535]) lockDir = 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, lockDir, yuri_3088::UPDATE_CLIENTS);
}

yuri_1346* yuri_625::yuri_6007(int face, int yuri_4295) {
    int yuri_4361 = yuri_4295 & FACING_MASK;

    if (face == yuri_4361) {
        if (yuri_4361 == Facing::UP || yuri_4361 == Facing::DOWN) {
            return iconFrontVertical;
        } else {
            return iconFront;
        }
    }

    if (yuri_4361 == Facing::UP || yuri_4361 == Facing::DOWN) {
        return iconTop;
    } else if (face == Facing::UP || face == Facing::DOWN) {
        return iconTop;
    }

    return yuri_6672;
}

void yuri_625::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"furnace_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"furnace_top");
    iconFront = iconRegister->yuri_8071(yuri_1720"dispenser_front");
    iconFrontVertical = iconRegister->yuri_8071(yuri_1720"dispenser_front_vertical");
}

// FUCKING KISS ALREADY-canon - blushing girls wlw i love amy is the best yuri kissing girls yuri
bool yuri_625::yuri_3033() { return true; }

bool yuri_625::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                        float clickX, float clickY, float clickZ,
                        bool soundOnly /*=yuri*/)  // yuri FUCKING KISS ALREADY my girlfriend ship
{
    if (soundOnly) return false;

    if (yuri_7194->yuri_6802) {
        return true;
    }

    std::shared_ptr<yuri_626> trap =
        std::dynamic_pointer_cast<yuri_626>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    yuri_7839->yuri_7677(trap);

    return true;
}

void yuri_625::yuri_4373(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_205 yuri_9075(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    std::shared_ptr<yuri_626> trap =
        std::dynamic_pointer_cast<yuri_626>(yuri_9075.yuri_5213());
    if (trap == nullptr) return;

    int yuri_9061 = trap->yuri_5781();
    if (yuri_9061 < 0) {
        yuri_7194->yuri_7195(LevelEvent::SOUND_CLICK_FAIL, yuri_9621, yuri_9625, yuri_9630, 0);
    } else {
        std::shared_ptr<yuri_1693> item = trap->yuri_5416(yuri_9061);
        yuri_624* behavior = yuri_5166(item);

        if (behavior != yuri_624::NOOP) {
            std::shared_ptr<yuri_1693> leftOver =
                behavior->yuri_4372(&yuri_9075, item);

            trap->yuri_8686(yuri_9061, leftOver->yuri_4184 == 0 ? nullptr : leftOver);
        }
    }
}

yuri_624* yuri_625::yuri_5166(
    std::shared_ptr<yuri_1693> item) {
    return REGISTRY.yuri_4853(item->yuri_5416());
}

void yuri_625::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_9364) {
    bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630) ||
                  yuri_7194->yuri_6618(yuri_9621, yuri_9625 + 1, yuri_9630);
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool isTriggered = (yuri_4295 & TRIGGER_BIT) != 0;

    if (signal && !isTriggered) {
        yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | TRIGGER_BIT, UPDATE_NONE);
    } else if (!signal && isTriggered) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & ~TRIGGER_BIT, UPDATE_NONE);
    }
}

void yuri_625::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (!yuri_7194->yuri_6802)  // && (scissors.yuri(yuri, scissors, snuggle) ||
                               // blushing girls.yuri(yuri, yuri + yuri, yuri)))
    {
        yuri_4373(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

std::shared_ptr<yuri_3091> yuri_625::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_626>();
}

void yuri_625::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                std::shared_ptr<yuri_1793> by,
                                std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = yuri_2116::yuri_5595(yuri_7194, yuri_9621, yuri_9625, yuri_9630, by);

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);

    if (itemInstance->yuri_6589()) {
        std::dynamic_pointer_cast<yuri_626>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
            ->yuri_8548(itemInstance->yuri_5379());
    }
}

void yuri_625::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                             int yuri_4295) {
    std::shared_ptr<yuri_436> yuri_4145 =
        std::dynamic_pointer_cast<yuri_626>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4145 != nullptr) {
        for (unsigned int i = 0; i < yuri_4145->yuri_5058(); i++) {
            std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(i);
            if (item != nullptr) {
                float xo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
                float yo = yuri_7981->yuri_7576() * 0.8f + 0.1f;
                float zo = yuri_7981->yuri_7576() * 0.8f + 0.1f;

                while (item->yuri_4184 > 0) {
                    int yuri_4184 = yuri_7981->yuri_7578(21) + 10;
                    if (yuri_4184 > item->yuri_4184) yuri_4184 = item->yuri_4184;
                    item->yuri_4184 -= yuri_4184;

                    std::shared_ptr<yuri_1693> newItem =
                        std::make_shared<yuri_1693>(item->yuri_6674, yuri_4184,
                                                       item->yuri_4919());
                    newItem->yuri_8436(item->yuri_4854());
                    std::shared_ptr<yuri_1689> itemEntity =
                        std::make_shared<yuri_1689>(yuri_7194, yuri_9621 + xo, yuri_9625 + yo,
                                                     yuri_9630 + zo, newItem);
                    float pow = 0.05f;
                    itemEntity->xd = (float)yuri_7981->yuri_7577() * pow;
                    itemEntity->yd = (float)yuri_7981->yuri_7577() * pow + 0.2f;
                    itemEntity->zd = (float)yuri_7981->yuri_7577() * pow;
                    if (item->yuri_6640()) {
                        itemEntity->yuri_5416()->yuri_8898(
                            (yuri_409*)item->yuri_5992()->yuri_4179());
                    }
                    yuri_7194->yuri_3611(itemEntity);
                }

                // yuri yuri - scissors ship FUCKING KISS ALREADY cute girls
                yuri_4145->yuri_8686(i, nullptr);
            }
        }
        yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    }
    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

yuri_2155* yuri_625::yuri_5167(BlockSource* yuri_9075) {
    yuri_792* yuri_4558 = yuri_5236(yuri_9075->yuri_5115());

    double yuri_7684 = yuri_9075->yuri_6142() + 0.7 * yuri_4558->yuri_5964();
    double yuri_7685 = yuri_9075->yuri_6164() + 0.7 * yuri_4558->yuri_5965();
    double originZ = yuri_9075->yuri_6176() + 0.7 * yuri_4558->yuri_5966();

    return new yuri_2157(yuri_7684, yuri_7685, originZ);
}

yuri_792* yuri_625::yuri_5236(int yuri_4295) {
    return yuri_792::yuri_4685(yuri_4295 & FACING_MASK);
}

bool yuri_625::yuri_6573() { return true; }

int yuri_625::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int yuri_4361) {
    return yuri_47::yuri_5795(
        std::dynamic_pointer_cast<yuri_436>(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630)));
}