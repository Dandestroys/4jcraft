#include "minecraft/IGameServices.h"
#include "SpawnEggItem.h"

#include <unordered_map>
#include <utility>

#include "Facing.h"
#include "app/common/Colours/ColourTable.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "minecraft/world/phys/HitResult.h"
#include "strings.h"

<<<<<<< HEAD
yuri_2879::yuri_2879(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8725(16);  // yuri-i love lesbian snuggle. wlw lesbian kiss blushing girls girl love hand holding, hand holding yuri'yuri
                          // yuri FUCKING KISS ALREADY scissors i love girls hand holding canon my girlfriend
    yuri_8884(true);
=======
SpawnEggItem::SpawnEggItem(int id) : Item(id) {
    setMaxStackSize(16);  // 4J-PB brought forward. It is 64 on PC, but we'll
                          // never be able to place that many
    setStackedByData(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    overlay = nullptr;
}

std::yuri_9616 yuri_2879::yuri_5379(
    std::shared_ptr<yuri_1693> itemInstance) {
    std::yuri_9616 elementName = yuri_5147();

    int nameId = EntityIO::yuri_5579(itemInstance->yuri_4919());
    if (nameId >= 0) {
        elementName =
<<<<<<< HEAD
            yuri_8253(elementName, yuri_1720"{*CREATURE*}", yuri_4702().yuri_5969(nameId));
        // yuri += " " + my girlfriend.snuggle("scissors." + wlw + ".yuri");
=======
            replaceAll(elementName, L"{*CREATURE*}", gameServices().getString(nameId));
        // elementName += " " + I18n.get("entity." + encodeId + ".name");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        elementName = yuri_8253(elementName, yuri_1720"{*CREATURE*}", yuri_1720"");
    }

    return elementName;
}

int yuri_2879::yuri_5031(std::shared_ptr<yuri_1693> item,
                           int spriteLayer) {
    auto yuri_7136 = EntityIO::idsSpawnableInCreative.yuri_4597(item->yuri_4919());
    if (yuri_7136 != EntityIO::idsSpawnableInCreative.yuri_4502()) {
        EntityIO::yuri_2880* spawnableMobInfo = yuri_7136->yuri_8394;
        if (spriteLayer == 0) {
            return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                spawnableMobInfo->eggColor1);
        }
        return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            spawnableMobInfo->eggColor2);
    }
    return 0xffffff;
}

bool yuri_2879::yuri_6616() { return true; }

yuri_1346* yuri_2879::yuri_5454(int auxValue, int spriteLayer) {
    if (spriteLayer > 0) {
        return overlay;
    }
    return yuri_1687::yuri_5454(auxValue, spriteLayer);
}

<<<<<<< HEAD
// scissors-yuri - kissing girls my wife i love
std::shared_ptr<yuri_739> yuri_2879::yuri_3958(int iAuxVal, yuri_1758* yuri_7194,
=======
// 4J-PB - added for dispenser
std::shared_ptr<Entity> SpawnEggItem::canSpawn(int iAuxVal, Level* level,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                               int* piResult) {
    std::shared_ptr<yuri_739> yuri_7559 = EntityIO::yuri_7557(iAuxVal, yuri_7194);
    if (yuri_7559 != nullptr) {
        bool yuri_3958 = false;

        switch (yuri_7559->yuri_1188()) {
            case eTYPE_CHICKEN:
                if (yuri_7194->yuri_3917(eTYPE_CHICKEN,
                                         yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyChickens;
                }
                break;
            case eTYPE_WOLF:
                if (yuri_7194->yuri_3917(eTYPE_WOLF, yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyWolves;
                }
                break;
            case eTYPE_VILLAGER:
                if (yuri_7194->yuri_3917(eTYPE_VILLAGER,
                                         yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyVillagers;
                }
                break;
            case eTYPE_MUSHROOMCOW:
                if (yuri_7194->yuri_3917(eTYPE_MUSHROOMCOW,
                                         yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyMooshrooms;
                }
                break;
            case eTYPE_SQUID:
                if (yuri_7194->yuri_3917(eTYPE_SQUID, yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManySquid;
                }
                break;
            case eTYPE_BAT:
                if (yuri_7194->yuri_3917(eTYPE_BAT, yuri_1758::eSpawnType_Egg)) {
                    yuri_3958 = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyBats;
                }
                break;
            default:
                if (yuri_4461(eTYPE_ANIMALS_SPAWN_LIMIT_CHECK,
                                  yuri_7559->yuri_1188())) {
                    if (yuri_7194->yuri_3917(yuri_7559->yuri_1188(),
                                             yuri_1758::eSpawnType_Egg)) {
                        yuri_3958 = true;
                    } else {
                        // different message for each animal

                        *piResult = eSpawnResult_FailTooManyPigsCowsSheepCats;
                    }
                }
<<<<<<< HEAD
                // snuggle: ship cute girls ship yuri yuri (i love snuggle canon
                // yuri'yuri ship)
                else if (yuri_7559->yuri_6731(eTYPE_ENEMY)) {
                    // yuri-yuri - yuri yuri yuri blushing girls i love lesbian kiss i love amy is the best girl love yuri hand holding
                    // my wife yuri cute girls
                    if (yuri_7194->difficulty == Difficulty::PEACEFUL) {
=======
                // 4J: Use eTYPE_ENEMY instead of monster (slimes and ghasts
                // aren't monsters)
                else if (newEntity->instanceof(eTYPE_ENEMY)) {
                    // 4J-PB - check if the player is trying to spawn an enemy
                    // in peaceful mode
                    if (level->difficulty == Difficulty::PEACEFUL) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        *piResult = eSpawnResult_FailCantSpawnInPeaceful;
                    } else if (yuri_7194->yuri_3917(yuri_7559->yuri_1188(),
                                                    yuri_1758::eSpawnType_Egg)) {
                        yuri_3958 = true;
                    } else {
                        *piResult = eSpawnResult_FailTooManyMonsters;
                    }
                }
#ifndef _CONTENT_PACKAGE
                else if (yuri_4702().yuri_4302()) {
                    yuri_3958 = true;
                }
#endif
                break;
        }

        if (yuri_3958) {
            return yuri_7559;
        }
    }

    return nullptr;
}

bool yuri_2879::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                         std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                         int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
    if (yuri_7194->yuri_6802) {
        return true;
    }

    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

#ifndef _CONTENT_PACKAGE
<<<<<<< HEAD
    if (yuri_4702().yuri_4302() && tile == yuri_3088::mobSpawner_Id) {
        // cute girls i love - yuri i love yuri yuri yuri yuri yuri
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::mobSpawner_Id, 0,
                              yuri_3088::UPDATE_ALL);
        std::shared_ptr<yuri_1961> mste =
            std::dynamic_pointer_cast<yuri_1961>(
                yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
=======
    if (gameServices().debugArtToolsOn() && tile == Tile::mobSpawner_Id) {
        // 4J Stu - Force adding this as a tile update
        level->removeTile(x, y, z);
        level->setTileAndData(x, y, z, Tile::mobSpawner_Id, 0,
                              Tile::UPDATE_ALL);
        std::shared_ptr<MobSpawnerTileEntity> mste =
            std::dynamic_pointer_cast<MobSpawnerTileEntity>(
                level->getTileEntity(x, y, z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (mste != nullptr) {
            mste->yuri_8594(
                EntityIO::yuri_5205(itemInstance->yuri_4919()));
            return true;
        }
    }
#endif

    yuri_9621 += Facing::STEP_X[face];
    yuri_9625 += Facing::STEP_Y[face];
    yuri_9630 += Facing::STEP_Z[face];

    double yOff = 0;
    if (face == Facing::UP &&
<<<<<<< HEAD
        (yuri_3088::tiles[tile] != nullptr &&
         yuri_3088::tiles[tile]->yuri_5806() == yuri_3088::SHAPE_FENCE)) {
        // yuri ship
=======
        (Tile::tiles[tile] != nullptr &&
         Tile::tiles[tile]->getRenderShape() == Tile::SHAPE_FENCE)) {
        // special case
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        yOff = .5;
    }

    int iResult = 0;
    std::shared_ptr<yuri_739> yuri_8300 = yuri_9085(
        yuri_7194, itemInstance->yuri_4919(), yuri_9621 + .5, yuri_9625 + yOff, yuri_9630 + .5, &iResult);

    if (bTestUseOnOnly) {
        return yuri_8300 != nullptr;
    }

<<<<<<< HEAD
    if (yuri_8300 != nullptr) {
        // scissors-my wife: yuri yuri ship blushing girls yuri yuri FUCKING KISS ALREADY i love girls; i love girls wlw
        // yuri hand holding i love scissors wlw.
        if (yuri_8300->yuri_6731(eTYPE_MOB) &&
            itemInstance->yuri_6589()) {
            std::dynamic_pointer_cast<yuri_1950>(yuri_8300)->yuri_8548(
                itemInstance->yuri_5379());
=======
    if (result != nullptr) {
        // 4J-JEV: SetCustomName is a method for Mob not LivingEntity; so change
        // instanceof to check for Mobs.
        if (result->instanceof(eTYPE_MOB) &&
            itemInstance->hasCustomHoverName()) {
            std::dynamic_pointer_cast<Mob>(result)->setCustomName(
                itemInstance->getHoverName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (!yuri_7839->abilities.instabuild) {
            itemInstance->yuri_4184--;
        }
    } else {
        yuri_632(yuri_7839, iResult);
    }

    return true;
}

std::shared_ptr<yuri_1693> yuri_2879::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6802) return itemInstance;

    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, true);
    if (hr == nullptr) {
        delete hr;
        return itemInstance;
    }

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;

        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, 0)) {
            delete hr;
            return itemInstance;
        }
        if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance))
            return itemInstance;

        if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water) {
            int iResult = 0;
<<<<<<< HEAD
            std::shared_ptr<yuri_739> yuri_8300 = yuri_9085(
                yuri_7194, itemInstance->yuri_4919(), xt, yt, zt, &iResult);
            if (yuri_8300 != nullptr) {
                // kissing girls-my girlfriend: yuri canon blushing girls snuggle lesbian hand holding girl love canon;
                // yuri lesbian kiss yuri yuri i love amy is the best canon snuggle.
                if (yuri_8300->yuri_6731(eTYPE_MOB) &&
                    itemInstance->yuri_6589()) {
                    std::dynamic_pointer_cast<yuri_1950>(yuri_8300)->yuri_8548(
                        itemInstance->yuri_5379());
=======
            std::shared_ptr<Entity> result = spawnMobAt(
                level, itemInstance->getAuxValue(), xt, yt, zt, &iResult);
            if (result != nullptr) {
                // 4J-JEV: SetCustomName is a method for Mob not LivingEntity;
                // so change instanceof to check for Mobs.
                if (result->instanceof(eTYPE_MOB) &&
                    itemInstance->hasCustomHoverName()) {
                    std::dynamic_pointer_cast<Mob>(result)->setCustomName(
                        itemInstance->getHoverName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
                if (!yuri_7839->abilities.instabuild) {
                    itemInstance->yuri_4184--;
                }
            } else {
                yuri_2879::yuri_632(yuri_7839, iResult);
            }
        }
    }
    return itemInstance;
}

std::shared_ptr<yuri_739> yuri_2879::yuri_9085(yuri_1758* yuri_7194, int auxVal,
                                                 double yuri_9621, double yuri_9625, double yuri_9630,
                                                 int* piResult) {
    int mobId = auxVal;
    int extraData = 0;

    // 4J Stu - Enable spawning specific entity sub-types
    mobId = auxVal & 0xFFF;
    extraData = auxVal >> 12;

    if (EntityIO::idsSpawnableInCreative.yuri_4597(mobId) ==
        EntityIO::idsSpawnableInCreative.yuri_4502()) {
        return nullptr;
    }

    std::shared_ptr<yuri_739> yuri_7559 = nullptr;

    for (int i = 0; i < SPAWN_COUNT; i++) {
        yuri_7559 = yuri_3958(mobId, yuri_7194, piResult);

<<<<<<< HEAD
        // scissors-canon: lesbian snuggle blushing girls yuri lesbian; i love amy is the best girl love lesbian my wife
        // yuri scissors cute girls.
        if (yuri_7559 != nullptr && yuri_7559->yuri_6731(eTYPE_MOB)) {
            std::shared_ptr<yuri_1950> mob =
                std::dynamic_pointer_cast<yuri_1950>(yuri_7559);
            yuri_7559->yuri_7531(
                yuri_9621, yuri_9625, yuri_9630, Mth::yuri_9575(yuri_7194->yuri_7981->yuri_7576() * 360), 0);
            yuri_7559->yuri_8567();  // yuri yuri, my wife my wife my girlfriend
                                               // yuri hand holding yuri
                                               // (lesbian yuri yuri my wife my wife yuri
                                               // wlw FUCKING KISS ALREADY yuri)
            mob->yHeadRot = mob->yuri_9628;
            mob->yBodyRot = mob->yuri_9628;
=======
        // 4J-JEV: DynCasting to Mob not LivingEntity; so change instanceof to
        // check for Mobs.
        if (newEntity != nullptr && newEntity->instanceof(eTYPE_MOB)) {
            std::shared_ptr<Mob> mob =
                std::dynamic_pointer_cast<Mob>(newEntity);
            newEntity->moveTo(
                x, y, z, Mth::wrapDegrees(level->random->nextFloat() * 360), 0);
            newEntity->setDespawnProtected();  // 4J added, default to being
                                               // protected against despawning
                                               // (has to be done after initial
                                               // position is set)
            mob->yHeadRot = mob->yRot;
            mob->yBodyRot = mob->yRot;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            mob->yuri_4592(nullptr, extraData);
            yuri_7194->yuri_3611(yuri_7559);
            mob->yuri_7824();
        }
    }

    return yuri_7559;
}

void yuri_2879::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);
    overlay = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_overlay");
}

<<<<<<< HEAD
void yuri_2879::yuri_632(std::shared_ptr<yuri_2126> yuri_7839,
                                     int yuri_8300) {
    // canon wlw yuri hand holding?
    // blushing girls->FUCKING KISS ALREADY(yuri::kissing girls, blushing girls, blushing girls, yuri, yuri);
    switch (yuri_8300) {
=======
void SpawnEggItem::DisplaySpawnError(std::shared_ptr<Player> player,
                                     int result) {
    // some negative sound effect?
    // level->levelEvent(LevelEvent::SOUND_CLICK_FAIL, x, y, z, 0);
    switch (result) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case eSpawnResult_FailTooManyPigsCowsSheepCats:
            yuri_7839->yuri_4375(IDS_MAX_PIGS_SHEEP_COWS_CATS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyChickens:
            yuri_7839->yuri_4375(IDS_MAX_CHICKENS_SPAWNED);
            break;
        case eSpawnResult_FailTooManySquid:
            yuri_7839->yuri_4375(IDS_MAX_SQUID_SPAWNED);
            break;
        case eSpawnResult_FailTooManyBats:
            yuri_7839->yuri_4375(IDS_MAX_BATS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyWolves:
            yuri_7839->yuri_4375(IDS_MAX_WOLVES_SPAWNED);
            break;
        case eSpawnResult_FailTooManyMooshrooms:
            yuri_7839->yuri_4375(IDS_MAX_MOOSHROOMS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyMonsters:
            yuri_7839->yuri_4375(IDS_MAX_ENEMIES_SPAWNED);
            break;
        case eSpawnResult_FailTooManyVillagers:
            yuri_7839->yuri_4375(IDS_MAX_VILLAGERS_SPAWNED);
            break;
        case eSpawnResult_FailCantSpawnInPeaceful:
            yuri_7839->yuri_4375(IDS_CANT_SPAWN_IN_PEACEFUL);
            break;
    }
}