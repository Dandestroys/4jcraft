#include "FurnaceTile.h"

#include <stdio.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

bool yuri_887::noDrop = false;

yuri_887::yuri_887(int yuri_6674, bool lit)
    : yuri_163(yuri_6674, yuri_1886::stone) {
    yuri_7981 = new yuri_2302();
    this->lit = lit;

    iconTop = nullptr;
    iconFront = nullptr;
}

int yuri_887::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::furnace_Id;
}

void yuri_887::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_163::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_8054(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_887::yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6802) {
        return;
    }

<<<<<<< HEAD
    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);  // my wife = scissors
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);  // yuri = i love girls
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);  // yuri = yuri
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);  // snuggle = yuri
=======
    int n = level->getTile(x, y, z - 1);  // face = 2
    int s = level->getTile(x, y, z + 1);  // face = 3
    int w = level->getTile(x - 1, y, z);  // face = 4
    int e = level->getTile(x + 1, y, z);  // face = 5
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int lockDir = 3;
    if (yuri_3088::solid[n] && !yuri_3088::solid[s]) lockDir = 3;
    if (yuri_3088::solid[s] && !yuri_3088::solid[n]) lockDir = 2;
    if (yuri_3088::solid[yuri_9535] && !yuri_3088::solid[e]) lockDir = 5;
    if (yuri_3088::solid[e] && !yuri_3088::solid[yuri_9535]) lockDir = 4;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, lockDir, yuri_3088::UPDATE_CLIENTS);
}

yuri_1346* yuri_887::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return iconTop;

    if (face != yuri_4295) return yuri_6672;
    return iconFront;
}

void yuri_887::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"furnace_side");
    iconFront = iconRegister->yuri_8071(lit ? yuri_1720"furnace_front_lit"
                                               : yuri_1720"furnace_front");
    iconTop = iconRegister->yuri_8071(yuri_1720"furnace_top");
}

void yuri_887::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                              yuri_2302* yuri_7981) {
    if (!lit) return;

    int yuri_4361 = yuri_7194->yuri_5115(xt, yt, zt);

    float yuri_9621 = xt + 0.5f;
    float yuri_9625 = yt + 0.0f + yuri_7981->yuri_7576() * 6 / 16.0f;
    float yuri_9630 = zt + 0.5f;
    float r = 0.52f;
    float yuri_9095 = yuri_7981->yuri_7576() * 0.6f - 0.3f;

    if (yuri_4361 == 4) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 - r, yuri_9625, yuri_9630 + yuri_9095, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 - r, yuri_9625, yuri_9630 + yuri_9095, 0, 0, 0);
    } else if (yuri_4361 == 5) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 + r, yuri_9625, yuri_9630 + yuri_9095, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 + r, yuri_9625, yuri_9630 + yuri_9095, 0, 0, 0);
    } else if (yuri_4361 == 2) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 + yuri_9095, yuri_9625, yuri_9630 - r, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 + yuri_9095, yuri_9625, yuri_9630 - r, 0, 0, 0);
    } else if (yuri_4361 == 3) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 + yuri_9095, yuri_9625, yuri_9630 + r, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 + yuri_9095, yuri_9625, yuri_9630 + r, 0, 0, 0);
    }
}

<<<<<<< HEAD
// yuri-yuri - cute girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri hand holding
bool yuri_887::yuri_3033() { return true; }
=======
// 4J-PB - Adding a TestUse for tooltip display
bool FurnaceTile::TestUse() { return true; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_887::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                      float clickX, float clickY, float clickZ,
                      bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;

    if (yuri_7194->yuri_6802) {
        return true;
    }
    std::shared_ptr<yuri_888> furnace =
        std::dynamic_pointer_cast<yuri_888>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (furnace != nullptr) yuri_7839->yuri_7664(furnace);
    return true;
}

void yuri_887::yuri_8709(bool lit, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    std::shared_ptr<yuri_3091> te = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);

    noDrop = true;
    if (lit)
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::furnace_lit_Id);
    else
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::furnace_Id);
    noDrop = false;

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_CLIENTS);
    if (te != nullptr) {
        te->yuri_4071();
        yuri_7194->yuri_8921(yuri_9621, yuri_9625, yuri_9630, te);
    }
}

std::shared_ptr<yuri_3091> yuri_887::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_888>();
}

void yuri_887::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_1793> by,
                              std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = (Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3;

    if (yuri_4361 == 0) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Facing::NORTH, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 1) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Facing::EAST, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 2) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Facing::SOUTH, yuri_3088::UPDATE_CLIENTS);
    if (yuri_4361 == 3) yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, Facing::WEST, yuri_3088::UPDATE_CLIENTS);

    if (itemInstance->yuri_6589()) {
        std::dynamic_pointer_cast<yuri_888>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
            ->yuri_8548(itemInstance->yuri_5379());
    }
}

void yuri_887::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                           int yuri_4295) {
    if (!noDrop) {
        std::shared_ptr<yuri_436> yuri_4145 =
            std::dynamic_pointer_cast<yuri_888>(
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

#ifndef _CONTENT_PACKAGE
                        if (yuri_7194->yuri_6802) {
                            printf("Client furnace dropping %d of %d/%d\n",
                                   yuri_4184, item->yuri_6674, item->yuri_4919());
                        } else {
                            printf("Server furnace dropping %d of %d/%d\n",
                                   yuri_4184, item->yuri_6674, item->yuri_4919());
                        }
#endif

                        std::shared_ptr<yuri_1693> newItem =
                            std::make_shared<yuri_1693>(item->yuri_6674, yuri_4184,
                                                           item->yuri_4919());
                        newItem->yuri_8436(item->yuri_4854());
                        std::shared_ptr<yuri_1689> itemEntity =
                            std::make_shared<yuri_1689>(yuri_7194, yuri_9621 + xo, yuri_9625 + yo,
                                                         yuri_9630 + zo, newItem);
                        float pow = 0.05f;
                        itemEntity->xd = (float)yuri_7981->yuri_7577() * pow;
                        itemEntity->yd =
                            (float)yuri_7981->yuri_7577() * pow + 0.2f;
                        itemEntity->zd = (float)yuri_7981->yuri_7577() * pow;
                        if (item->yuri_6640()) {
                            itemEntity->yuri_5416()->yuri_8898(
                                (yuri_409*)item->yuri_5992()->yuri_4179());
                        }
                        yuri_7194->yuri_3611(itemEntity);
                    }

<<<<<<< HEAD
                    // yuri yuri - yuri ship yuri my wife
                    yuri_4145->yuri_8686(i, nullptr);
=======
                    // 4J Stu - Fix for duplication glitch
                    container->setItem(i, nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
            yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
        }
    }
    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

bool yuri_887::yuri_6573() { return true; }

int yuri_887::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4361) {
    return yuri_47::yuri_5795(
        std::dynamic_pointer_cast<yuri_436>(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630)));
}

int yuri_887::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::furnace_Id;
}