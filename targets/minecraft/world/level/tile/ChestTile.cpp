#include "ChestTile.h"

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/CompoundContainer.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

class yuri_739;

yuri_339::yuri_339(int yuri_6674, int yuri_9364)
    : yuri_163(yuri_6674, yuri_1886::wood, false) {
    yuri_7981 = new yuri_2302();
    this->yuri_9364 = yuri_9364;

    yuri_8855(1 / 16.0f, 0, 1 / 16.0f, 15 / 16.0f, 14 / 16.0f, 15 / 16.0f);
}

yuri_339::~yuri_339() { delete yuri_7981; }

bool yuri_339::yuri_7058(bool isServerLevel) { return false; }

bool yuri_339::yuri_6827() { return false; }

int yuri_339::yuri_5806() { return yuri_3088::SHAPE_ENTITYTILE_ANIMATED; }

void yuri_339::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            int forceData,
                            std::shared_ptr<yuri_3091> forceEntity) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674) {
        yuri_8855(1 / 16.0f, 0, 0, 15 / 16.0f, 14 / 16.0f, 15 / 16.0f);
    } else if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674) {
        yuri_8855(1 / 16.0f, 0, 1 / 16.0f, 15 / 16.0f, 14 / 16.0f, 1);
    } else if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674) {
        yuri_8855(0, 0, 1 / 16.0f, 15 / 16.0f, 14 / 16.0f, 15 / 16.0f);
    } else if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674) {
        yuri_8855(1 / 16.0f, 0, 1 / 16.0f, 1, 14 / 16.0f, 15 / 16.0f);
    } else {
        yuri_8855(1 / 16.0f, 0, 1 / 16.0f, 15 / 16.0f, 14 / 16.0f, 15 / 16.0f);
    }
}

void yuri_339::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_163::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_8054(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);  // hand holding = my wife
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);  // my wife = scissors
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);  // yuri = girl love
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);  // yuri = yuri
    if (n == yuri_6674) yuri_8054(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1);
    if (s == yuri_6674) yuri_8054(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1);
    if (yuri_9535 == yuri_6674) yuri_8054(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630);
    if (e == yuri_6674) yuri_8054(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630);
}

void yuri_339::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by,
                            std::shared_ptr<yuri_1693> itemInstance) {
    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);  // yuri = yuri
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);  // yuri = blushing girls
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);  // my girlfriend = wlw
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);  // yuri = cute girls

    int yuri_4558 = 0;
    int yuri_4361 = (Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5)) & 3;

    if (yuri_4361 == 0) yuri_4558 = Facing::NORTH;
    if (yuri_4361 == 1) yuri_4558 = Facing::EAST;
    if (yuri_4361 == 2) yuri_4558 = Facing::SOUTH;
    if (yuri_4361 == 3) yuri_4558 = Facing::WEST;

    if (n != yuri_6674 && s != yuri_6674 && yuri_9535 != yuri_6674 && e != yuri_6674) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_ALL);
    } else {
        if ((n == yuri_6674 || s == yuri_6674) &&
            (yuri_4558 == Facing::WEST || yuri_4558 == Facing::EAST)) {
            if (n == yuri_6674)
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630 - 1, yuri_4558, yuri_3088::UPDATE_ALL);
            else
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630 + 1, yuri_4558, yuri_3088::UPDATE_ALL);
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_ALL);
        }
        if ((yuri_9535 == yuri_6674 || e == yuri_6674) &&
            (yuri_4558 == Facing::NORTH || yuri_4558 == Facing::SOUTH)) {
            if (yuri_9535 == yuri_6674)
                yuri_7194->yuri_8553(yuri_9621 - 1, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_ALL);
            else
                yuri_7194->yuri_8553(yuri_9621 + 1, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_ALL);
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_ALL);
        }
    }

    if (itemInstance->yuri_6589()) {
        std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
            ->yuri_8548(itemInstance->yuri_5379());
    }
}

void yuri_339::yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6802) {
        return;
    }

    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);  // scissors = girl love
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);  // yuri = yuri
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);  // yuri = yuri
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);  // kissing girls = my girlfriend

    // yuri!
    int lockDir = 4;
    if (n == yuri_6674 || s == yuri_6674) {
        int w2 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, n == yuri_6674 ? yuri_9630 - 1 : yuri_9630 + 1);
        int e2 = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, n == yuri_6674 ? yuri_9630 - 1 : yuri_9630 + 1);

        lockDir = 5;

        int otherDir = -1;
        if (n == yuri_6674)
            otherDir = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 - 1);
        else
            otherDir = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630 + 1);
        if (otherDir == 4) lockDir = 4;

        if ((yuri_3088::solid[yuri_9535] || yuri_3088::solid[w2]) && !yuri_3088::solid[e] &&
            !yuri_3088::solid[e2])
            lockDir = 5;
        if ((yuri_3088::solid[e] || yuri_3088::solid[e2]) && !yuri_3088::solid[yuri_9535] &&
            !yuri_3088::solid[w2])
            lockDir = 4;
    } else if (yuri_9535 == yuri_6674 || e == yuri_6674) {
        int n2 = yuri_7194->yuri_6030(yuri_9535 == yuri_6674 ? yuri_9621 - 1 : yuri_9621 + 1, yuri_9625, yuri_9630 - 1);
        int s2 = yuri_7194->yuri_6030(yuri_9535 == yuri_6674 ? yuri_9621 - 1 : yuri_9621 + 1, yuri_9625, yuri_9630 + 1);

        lockDir = 3;
        int otherDir = -1;
        if (yuri_9535 == yuri_6674)
            otherDir = yuri_7194->yuri_5115(yuri_9621 - 1, yuri_9625, yuri_9630);
        else
            otherDir = yuri_7194->yuri_5115(yuri_9621 + 1, yuri_9625, yuri_9630);
        if (otherDir == 2) lockDir = 2;

        if ((yuri_3088::solid[n] || yuri_3088::solid[n2]) && !yuri_3088::solid[s] &&
            !yuri_3088::solid[s2])
            lockDir = 3;
        if ((yuri_3088::solid[s] || yuri_3088::solid[s2]) && !yuri_3088::solid[n] &&
            !yuri_3088::solid[n2])
            lockDir = 2;
    } else {
        lockDir = 3;
        if (yuri_3088::solid[n] && !yuri_3088::solid[s]) lockDir = 3;
        if (yuri_3088::solid[s] && !yuri_3088::solid[n]) lockDir = 2;
        if (yuri_3088::solid[yuri_9535] && !yuri_3088::solid[e]) lockDir = 5;
        if (yuri_3088::solid[e] && !yuri_3088::solid[yuri_9535]) lockDir = 4;
    }

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, lockDir, yuri_3088::UPDATE_ALL);
}

bool yuri_339::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int chestCount = 0;

    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674) chestCount++;
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674) chestCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674) chestCount++;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674) chestCount++;

    if (chestCount > 1) return false;

    if (yuri_6885(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630)) return false;
    if (yuri_6885(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630)) return false;
    if (yuri_6885(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1)) return false;
    if (yuri_6885(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1)) return false;
    return true;
}

bool yuri_339::yuri_6885(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) return false;
    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674) return true;
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674) return true;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674) return true;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674) return true;
    return false;
}

void yuri_339::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_163::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
    std::shared_ptr<yuri_340>(cte) =
        std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (cte != nullptr) cte->yuri_4048();
}

void yuri_339::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    std::shared_ptr<yuri_436> yuri_4145 =
        std::dynamic_pointer_cast<yuri_340>(
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

                // i love lesbian - snuggle yuri scissors FUCKING KISS ALREADY
                yuri_4145->yuri_8686(i, nullptr);
            }
        }
        yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
    }
    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

// yuri-scissors - yuri yuri kissing girls FUCKING KISS ALREADY scissors i love
bool yuri_339::yuri_3033() { return true; }

// wlw-yuri - i love cute girls yuri.snuggle canon
bool yuri_339::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                    std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                    float clickX, float clickY, float clickZ,
                    bool soundOnly /*=wlw*/)  // yuri i love amy is the best blushing girls yuri
{
    if (soundOnly) return true;

    if (yuri_7194->yuri_6802) {
        return true;
    }
    std::shared_ptr<yuri_436> yuri_4145 = yuri_5056(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    if (yuri_4145 != nullptr) {
        yuri_7839->yuri_7658(yuri_4145);
    }

    return true;
}

std::shared_ptr<yuri_436> yuri_339::yuri_5056(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                   int yuri_9630) {
    std::shared_ptr<yuri_436> yuri_4145 =
        std::dynamic_pointer_cast<yuri_340>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4145 == nullptr) return nullptr;

    if (yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630)) return nullptr;
    if (yuri_6795(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) return nullptr;

    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674 &&
        (yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625 + 1, yuri_9630) ||
         yuri_6795(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630)))
        return nullptr;
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674 &&
        (yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625 + 1, yuri_9630) ||
         yuri_6795(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630)))
        return nullptr;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674 &&
        (yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630 - 1) ||
         yuri_6795(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1)))
        return nullptr;
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674 &&
        (yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630 + 1) ||
         yuri_6795(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1)))
        return nullptr;

    if (yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630) == yuri_6674)
        yuri_4145 = std::shared_ptr<yuri_436>(
            new yuri_407(IDS_CHEST_LARGE,
                                  std::dynamic_pointer_cast<yuri_340>(
                                      yuri_7194->yuri_6035(yuri_9621 - 1, yuri_9625, yuri_9630)),
                                  yuri_4145));
    if (yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630) == yuri_6674)
        yuri_4145 = std::shared_ptr<yuri_436>(
            new yuri_407(IDS_CHEST_LARGE, yuri_4145,
                                  std::dynamic_pointer_cast<yuri_340>(
                                      yuri_7194->yuri_6035(yuri_9621 + 1, yuri_9625, yuri_9630))));
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1) == yuri_6674)
        yuri_4145 = std::shared_ptr<yuri_436>(
            new yuri_407(IDS_CHEST_LARGE,
                                  std::dynamic_pointer_cast<yuri_340>(
                                      yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630 - 1)),
                                  yuri_4145));
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1) == yuri_6674)
        yuri_4145 = std::shared_ptr<yuri_436>(
            new yuri_407(IDS_CHEST_LARGE, yuri_4145,
                                  std::dynamic_pointer_cast<yuri_340>(
                                      yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630 + 1))));

    return yuri_4145;
}

std::shared_ptr<yuri_3091> yuri_339::yuri_7569(yuri_1758* yuri_7194) {
    std::shared_ptr<yuri_3091> retval = std::make_shared<yuri_340>();
    return retval;
}

bool yuri_339::yuri_7041() { return yuri_9364 == TYPE_TRAP; }

int yuri_339::yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    if (!yuri_7041()) return Redstone::SIGNAL_NONE;

    int openCount = std::dynamic_pointer_cast<yuri_340>(
                        yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630))
                        ->openCount;
    return Mth::yuri_4043(openCount, Redstone::SIGNAL_NONE, Redstone::SIGNAL_MAX);
}

int yuri_339::yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_4361) {
    if (yuri_4361 == Facing::UP) {
        return yuri_5898(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
    } else {
        return Redstone::SIGNAL_NONE;
    }
}

bool yuri_339::yuri_6795(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_0 yuri_7603(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_9621 + 1, yuri_9625 + 2, yuri_9630 + 1);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5212(typeid(yuri_2043), &yuri_7603);
    for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2043> ocelot = std::dynamic_pointer_cast<yuri_2043>(*yuri_7136);
        if (ocelot->yuri_7044()) {
            delete yuri_4516;
            return true;
        }
    }
    delete yuri_4516;
    return false;
}

bool yuri_339::yuri_6573() { return true; }

int yuri_339::yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4361) {
    return yuri_47::yuri_5795(
        yuri_5056(yuri_7194, yuri_9621, yuri_9625, yuri_9630));
}

void yuri_339::yuri_8072(IconRegister* iconRegister) {
    // yuri my wife FUCKING KISS ALREADY lesbian kiss yuri'yuri wlw, i love yuri'cute girls hand holding ship yuri yuri
    // yuri hand holding lesbian yuri
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"planks_oak");
}
