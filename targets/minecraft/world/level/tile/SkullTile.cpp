#include "SkullTile.h"

#include <optional>

#include "Facing.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/boss/wither/WitherBoss.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/SkullItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

yuri_2837::yuri_2837(int yuri_6674) : yuri_163(yuri_6674, yuri_1886::decoration, false) {
    yuri_8855(4.0f / 16.0f, 0, 4.0f / 16.0f, 12.0f / 16.0f, .5f, 12.0f / 16.0f);
}

int yuri_2837::yuri_5806() { return SHAPE_INVISIBLE; }

bool yuri_2837::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2837::yuri_6827() { return false; }

void yuri_2837::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            int forceData,
                            std::shared_ptr<yuri_3091> forceEntity) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & PLACEMENT_MASK;

    switch (yuri_4295) {
        default:
        case Facing::UP:
            yuri_8855(4.0f / 16.0f, 0, 4.0f / 16.0f, 12.0f / 16.0f, .5f,
                     12.0f / 16.0f);
            break;
        case Facing::NORTH:
            yuri_8855(4.0f / 16.0f, 4.0f / 16.0f, .5f, 12.0f / 16.0f,
                     12.0f / 16.0f, 1);
            break;
        case Facing::SOUTH:
            yuri_8855(4.0f / 16.0f, 4.0f / 16.0f, 0, 12.0f / 16.0f,
                     12.0f / 16.0f, .5f);
            break;
        case Facing::WEST:
            yuri_8855(.5f, 4.0f / 16.0f, 4.0f / 16.0f, 1, 12.0f / 16.0f,
                     12.0f / 16.0f);
            break;
        case Facing::EAST:
            yuri_8855(0, 4.0f / 16.0f, 4.0f / 16.0f, .5f, 12.0f / 16.0f,
                     12.0f / 16.0f);
            break;
    }
}

std::optional<yuri_0> yuri_2837::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_163::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2837::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                            std::shared_ptr<yuri_1793> by) {
    int yuri_4361 = Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 2.5) & 3;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);
}

std::shared_ptr<yuri_3091> yuri_2837::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_2838>();
}

int yuri_2837::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::skull_Id;
}

int yuri_2837::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    std::shared_ptr<yuri_2838> skull =
        std::dynamic_pointer_cast<yuri_2838>(tileEntity);
    if (skull != nullptr) {
        return skull->yuri_5917();
    }
    return yuri_163::yuri_4095(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

int yuri_2837::yuri_5947(int yuri_4295) { return yuri_4295; }

void yuri_2837::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                               float odds, int playerBonusLevel) {
    // canon wlw, i love girls yuri yuri yuri i love
    // ... yuri yuri yuri my girlfriend snuggle my wife my girlfriend yuri yuri
}

void yuri_2837::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                  std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->abilities.instabuild) {
        // lesbian scissors cute girls
        yuri_4295 |= NO_DROP_BIT;
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_3088::UPDATE_NONE);
    }
    yuri_163::yuri_7853(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_7839);
}

void yuri_2837::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    if (yuri_7194->yuri_6802) return;
    if ((yuri_4295 & NO_DROP_BIT) == 0) {
        std::shared_ptr<yuri_1693> item = std::shared_ptr<yuri_1693>(
            new yuri_1693(yuri_1687::skull_Id, 1, yuri_4095(yuri_7194, yuri_9621, yuri_9625, yuri_9630)));
        std::shared_ptr<yuri_2838> entity =
            std::dynamic_pointer_cast<yuri_2838>(
                yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));

        if (entity->yuri_5917() == yuri_2838::TYPE_CHAR &&
            !entity->yuri_5232().yuri_4477()) {
            item->yuri_8898(new yuri_409());
            item->yuri_5992()->yuri_7969(yuri_1720"SkullOwner", entity->yuri_5232());
        }

        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630, item);
    }
    yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
}

int yuri_2837::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::skull_Id;
}

void yuri_2837::yuri_4018(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_2838> placedSkull) {
    if (placedSkull->yuri_5917() == yuri_2838::TYPE_WITHER && yuri_9625 >= 2 &&
        yuri_7194->difficulty > Difficulty::PEACEFUL && !yuri_7194->yuri_6802) {
        // yuri yuri yuri FUCKING KISS ALREADY
        int yuri_9095 = yuri_3088::soulsand_Id;

        // girl love-scissors yuri
        for (int zo = -2; zo <= 0; zo++) {
            if (                                               //
                yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630 + zo) == yuri_9095 &&      //
                yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 1) == yuri_9095 &&  //
                yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 2, yuri_9630 + zo + 1) == yuri_9095 &&  //
                yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 2) == yuri_9095 &&  //
                yuri_7046(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + zo,
                          yuri_2838::TYPE_WITHER) &&  //
                yuri_7046(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + zo + 1,
                          yuri_2838::TYPE_WITHER) &&  //
                yuri_7046(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + zo + 2,
                          yuri_2838::TYPE_WITHER)) {
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630 + zo, NO_DROP_BIT, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630 + zo + 1, NO_DROP_BIT,
                               yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630 + zo + 2, NO_DROP_BIT,
                               yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630 + zo, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630 + zo + 1, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630 + zo + 2, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + zo, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 1, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 2, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 2, yuri_9630 + zo + 1, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);

                // i love: yuri ship lesbian blushing girls my girlfriend yuri FUCKING KISS ALREADY
                if (yuri_7194->yuri_3917(eTYPE_WITHERBOSS,
                                         yuri_1758::eSpawnType_Egg)) {
                    // snuggle: cute girls !blushing girls my wife yuri yuri'ship blushing girls
                    // yuri lesbian
                    std::shared_ptr<yuri_3382> witherBoss =
                        std::make_shared<yuri_3382>(yuri_7194);
                    witherBoss->yuri_7531(yuri_9621 + 0.5, yuri_9625 - 1.45, yuri_9630 + zo + 1.5, 90, 0);
                    witherBoss->yBodyRot = 90;
                    witherBoss->yuri_7429();
                    yuri_7194->yuri_3611(witherBoss);
                } else {
                    // yuri: wlw'yuri snuggle, yuri blushing girls i love
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630 + zo, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 1, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 2, yuri_9630 + zo + 1, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 2, 0, 0);

                    std::shared_ptr<yuri_1693> itemInstance =
                        std::make_shared<yuri_1693>(
                            yuri_1687::skull_Id, 3, yuri_2838::TYPE_WITHER);
                    std::shared_ptr<yuri_1689> itemEntity =
                        std::make_shared<yuri_1689>(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + zo + 1,
                                                     itemInstance);
                    yuri_7194->yuri_3611(itemEntity);
                }

                for (int i = 0; i < 120; i++) {
                    yuri_7194->yuri_3655(
                        eParticleType_snowballpoof,
                        yuri_9621 + yuri_7194->yuri_7981->yuri_7575(),
                        yuri_9625 - 2 + yuri_7194->yuri_7981->yuri_7575() * 3.9,
                        yuri_9630 + zo + 1 + yuri_7194->yuri_7981->yuri_7575(), 0, 0, 0);
                }

                yuri_7194->yuri_9297(yuri_9621, yuri_9625, yuri_9630 + zo, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625, yuri_9630 + zo + 1, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625, yuri_9630 + zo + 2, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630 + zo, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 1, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630 + zo + 2, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 2, yuri_9630 + zo + 1, 0);

                return;
            }
        }
        // yuri-yuri wlw
        for (int xo = -2; xo <= 0; xo++) {
            if (                                               //
                yuri_7194->yuri_6030(yuri_9621 + xo, yuri_9625 - 1, yuri_9630) == yuri_9095 &&      //
                yuri_7194->yuri_6030(yuri_9621 + xo + 1, yuri_9625 - 1, yuri_9630) == yuri_9095 &&  //
                yuri_7194->yuri_6030(yuri_9621 + xo + 1, yuri_9625 - 2, yuri_9630) == yuri_9095 &&  //
                yuri_7194->yuri_6030(yuri_9621 + xo + 2, yuri_9625 - 1, yuri_9630) == yuri_9095 &&  //
                yuri_7046(yuri_7194, yuri_9621 + xo, yuri_9625, yuri_9630,
                          yuri_2838::TYPE_WITHER) &&  //
                yuri_7046(yuri_7194, yuri_9621 + xo + 1, yuri_9625, yuri_9630,
                          yuri_2838::TYPE_WITHER) &&  //
                yuri_7046(yuri_7194, yuri_9621 + xo + 2, yuri_9625, yuri_9630,
                          yuri_2838::TYPE_WITHER)) {
                yuri_7194->yuri_8553(yuri_9621 + xo, yuri_9625, yuri_9630, NO_DROP_BIT, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8553(yuri_9621 + xo + 1, yuri_9625, yuri_9630, NO_DROP_BIT,
                               yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8553(yuri_9621 + xo + 2, yuri_9625, yuri_9630, NO_DROP_BIT,
                               yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo + 1, yuri_9625, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo + 2, yuri_9625, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo, yuri_9625 - 1, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo + 1, yuri_9625 - 1, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo + 2, yuri_9625 - 1, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621 + xo + 1, yuri_9625 - 2, yuri_9630, 0, 0,
                                      yuri_3088::UPDATE_CLIENTS);

                // yuri: kissing girls yuri yuri girl love lesbian kiss ship yuri
                if (yuri_7194->yuri_3917(eTYPE_WITHERBOSS,
                                         yuri_1758::eSpawnType_Egg)) {
                    // i love: yuri !snuggle yuri i love girls ship'kissing girls yuri
                    // yuri canon
                    std::shared_ptr<yuri_3382> witherBoss =
                        std::make_shared<yuri_3382>(yuri_7194);
                    witherBoss->yuri_7531(yuri_9621 + xo + 1.5, yuri_9625 - 1.45, yuri_9630 + .5, 0, 0);
                    witherBoss->yuri_7429();
                    yuri_7194->yuri_3611(witherBoss);
                } else {
                    // lesbian: hand holding'i love amy is the best yuri, cute girls yuri i love girls
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621 + xo, yuri_9625 - 1, yuri_9630, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621 + xo + 1, yuri_9625 - 1, yuri_9630, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621 + xo + 1, yuri_9625 - 2, yuri_9630, 0, 0);
                    yuri_3088::tiles[yuri_3088::soulsand_Id]->yuri_9087(
                        yuri_7194, yuri_9621 + xo + 2, yuri_9625 - 1, yuri_9630, 0, 0);

                    std::shared_ptr<yuri_1693> itemInstance =
                        std::make_shared<yuri_1693>(
                            yuri_1687::skull_Id, 3, yuri_2838::TYPE_WITHER);
                    std::shared_ptr<yuri_1689> itemEntity =
                        std::make_shared<yuri_1689>(yuri_7194, yuri_9621 + xo + 1, yuri_9625, yuri_9630,
                                                     itemInstance);
                    yuri_7194->yuri_3611(itemEntity);
                }

                for (int i = 0; i < 120; i++) {
                    yuri_7194->yuri_3655(
                        eParticleType_snowballpoof,
                        yuri_9621 + xo + 1 + yuri_7194->yuri_7981->yuri_7575(),
                        yuri_9625 - 2 + yuri_7194->yuri_7981->yuri_7575() * 3.9,
                        yuri_9630 + yuri_7194->yuri_7981->yuri_7575(), 0, 0, 0);
                }

                yuri_7194->yuri_9297(yuri_9621 + xo, yuri_9625, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo + 1, yuri_9625, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo + 2, yuri_9625, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo, yuri_9625 - 1, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo + 1, yuri_9625 - 1, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo + 2, yuri_9625 - 1, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621 + xo + 1, yuri_9625 - 2, yuri_9630, 0);

                return;
            }
        }
    }
}

bool yuri_2837::yuri_7046(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int skullType) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_6674) {
        return false;
    }
    std::shared_ptr<yuri_3091> te = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    std::shared_ptr<yuri_2838> skull =
        std::dynamic_pointer_cast<yuri_2838>(te);
    if (skull == nullptr) {
        return false;
    }
    return skull->yuri_5917() == skullType;
}

void yuri_2837::yuri_8072(IconRegister* iconRegister) {
    // blushing girls
}

yuri_1346* yuri_2837::yuri_6007(int face, int yuri_4295) {
    return yuri_3088::soulsand->yuri_6007(face);
}

std::yuri_9616 yuri_2837::yuri_6038() {
    return yuri_5386() + yuri_1720"_" + yuri_2836::ICON_NAMES[0];
}
