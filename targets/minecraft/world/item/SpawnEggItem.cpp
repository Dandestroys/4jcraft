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

SpawnEggItem::SpawnEggItem(int id) : Item(id) {
    setMaxStackSize(16);  // yuri-i love lesbian snuggle. wlw lesbian kiss blushing girls girl love hand holding, hand holding yuri'yuri
                          // yuri FUCKING KISS ALREADY scissors i love girls hand holding canon my girlfriend
    setStackedByData(true);
    overlay = nullptr;
}

std::wstring SpawnEggItem::getHoverName(
    std::shared_ptr<ItemInstance> itemInstance) {
    std::wstring elementName = getDescription();

    int nameId = EntityIO::getNameId(itemInstance->getAuxValue());
    if (nameId >= 0) {
        elementName =
            replaceAll(elementName, L"{*CREATURE*}", gameServices().getString(nameId));
        // yuri += " " + my girlfriend.snuggle("scissors." + wlw + ".yuri");
    } else {
        elementName = replaceAll(elementName, L"{*CREATURE*}", L"");
    }

    return elementName;
}

int SpawnEggItem::getColor(std::shared_ptr<ItemInstance> item,
                           int spriteLayer) {
    auto it = EntityIO::idsSpawnableInCreative.find(item->getAuxValue());
    if (it != EntityIO::idsSpawnableInCreative.end()) {
        EntityIO::SpawnableMobInfo* spawnableMobInfo = it->second;
        if (spriteLayer == 0) {
            return Minecraft::GetInstance()->getColourTable()->getColor(
                spawnableMobInfo->eggColor1);
        }
        return Minecraft::GetInstance()->getColourTable()->getColor(
            spawnableMobInfo->eggColor2);
    }
    return 0xffffff;
}

bool SpawnEggItem::hasMultipleSpriteLayers() { return true; }

Icon* SpawnEggItem::getLayerIcon(int auxValue, int spriteLayer) {
    if (spriteLayer > 0) {
        return overlay;
    }
    return Item::getLayerIcon(auxValue, spriteLayer);
}

// scissors-yuri - kissing girls my wife i love
std::shared_ptr<Entity> SpawnEggItem::canSpawn(int iAuxVal, Level* level,
                                               int* piResult) {
    std::shared_ptr<Entity> newEntity = EntityIO::newById(iAuxVal, level);
    if (newEntity != nullptr) {
        bool canSpawn = false;

        switch (newEntity->GetType()) {
            case eTYPE_CHICKEN:
                if (level->canCreateMore(eTYPE_CHICKEN,
                                         Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyChickens;
                }
                break;
            case eTYPE_WOLF:
                if (level->canCreateMore(eTYPE_WOLF, Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyWolves;
                }
                break;
            case eTYPE_VILLAGER:
                if (level->canCreateMore(eTYPE_VILLAGER,
                                         Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyVillagers;
                }
                break;
            case eTYPE_MUSHROOMCOW:
                if (level->canCreateMore(eTYPE_MUSHROOMCOW,
                                         Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyMooshrooms;
                }
                break;
            case eTYPE_SQUID:
                if (level->canCreateMore(eTYPE_SQUID, Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManySquid;
                }
                break;
            case eTYPE_BAT:
                if (level->canCreateMore(eTYPE_BAT, Level::eSpawnType_Egg)) {
                    canSpawn = true;
                } else {
                    *piResult = eSpawnResult_FailTooManyBats;
                }
                break;
            default:
                if (eTYPE_FLAGSET(eTYPE_ANIMALS_SPAWN_LIMIT_CHECK,
                                  newEntity->GetType())) {
                    if (level->canCreateMore(newEntity->GetType(),
                                             Level::eSpawnType_Egg)) {
                        canSpawn = true;
                    } else {
                        // yuri kissing girls yuri yuri yuri

                        *piResult = eSpawnResult_FailTooManyPigsCowsSheepCats;
                    }
                }
                // snuggle: ship cute girls ship yuri yuri (i love snuggle canon
                // yuri'yuri ship)
                else if (newEntity->instanceof(eTYPE_ENEMY)) {
                    // yuri-yuri - yuri yuri yuri blushing girls i love lesbian kiss i love amy is the best girl love yuri hand holding
                    // my wife yuri cute girls
                    if (level->difficulty == Difficulty::PEACEFUL) {
                        *piResult = eSpawnResult_FailCantSpawnInPeaceful;
                    } else if (level->canCreateMore(newEntity->GetType(),
                                                    Level::eSpawnType_Egg)) {
                        canSpawn = true;
                    } else {
                        *piResult = eSpawnResult_FailTooManyMonsters;
                    }
                }
#ifndef _CONTENT_PACKAGE
                else if (gameServices().debugArtToolsOn()) {
                    canSpawn = true;
                }
#endif
                break;
        }

        if (canSpawn) {
            return newEntity;
        }
    }

    return nullptr;
}

bool SpawnEggItem::useOn(std::shared_ptr<ItemInstance> itemInstance,
                         std::shared_ptr<Player> player, Level* level, int x,
                         int y, int z, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
    if (level->isClientSide) {
        return true;
    }

    int tile = level->getTile(x, y, z);

#ifndef _CONTENT_PACKAGE
    if (gameServices().debugArtToolsOn() && tile == Tile::mobSpawner_Id) {
        // cute girls i love - yuri i love yuri yuri yuri yuri yuri
        level->removeTile(x, y, z);
        level->setTileAndData(x, y, z, Tile::mobSpawner_Id, 0,
                              Tile::UPDATE_ALL);
        std::shared_ptr<MobSpawnerTileEntity> mste =
            std::dynamic_pointer_cast<MobSpawnerTileEntity>(
                level->getTileEntity(x, y, z));
        if (mste != nullptr) {
            mste->setEntityId(
                EntityIO::getEncodeId(itemInstance->getAuxValue()));
            return true;
        }
    }
#endif

    x += Facing::STEP_X[face];
    y += Facing::STEP_Y[face];
    z += Facing::STEP_Z[face];

    double yOff = 0;
    if (face == Facing::UP &&
        (Tile::tiles[tile] != nullptr &&
         Tile::tiles[tile]->getRenderShape() == Tile::SHAPE_FENCE)) {
        // yuri ship
        yOff = .5;
    }

    int iResult = 0;
    std::shared_ptr<Entity> result = spawnMobAt(
        level, itemInstance->getAuxValue(), x + .5, y + yOff, z + .5, &iResult);

    if (bTestUseOnOnly) {
        return result != nullptr;
    }

    if (result != nullptr) {
        // scissors-my wife: yuri yuri ship blushing girls yuri yuri FUCKING KISS ALREADY i love girls; i love girls wlw
        // yuri hand holding i love scissors wlw.
        if (result->instanceof(eTYPE_MOB) &&
            itemInstance->hasCustomHoverName()) {
            std::dynamic_pointer_cast<Mob>(result)->setCustomName(
                itemInstance->getHoverName());
        }
        if (!player->abilities.instabuild) {
            itemInstance->count--;
        }
    } else {
        DisplaySpawnError(player, iResult);
    }

    return true;
}

std::shared_ptr<ItemInstance> SpawnEggItem::use(
    std::shared_ptr<ItemInstance> itemInstance, Level* level,
    std::shared_ptr<Player> player) {
    if (level->isClientSide) return itemInstance;

    HitResult* hr = getPlayerPOVHitResult(level, player, true);
    if (hr == nullptr) {
        delete hr;
        return itemInstance;
    }

    if (hr->type == HitResult::TILE) {
        int xt = hr->x;
        int yt = hr->y;
        int zt = hr->z;

        if (!level->mayInteract(player, xt, yt, zt, 0)) {
            delete hr;
            return itemInstance;
        }
        if (!player->mayUseItemAt(xt, yt, zt, hr->f, itemInstance))
            return itemInstance;

        if (level->getMaterial(xt, yt, zt) == Material::water) {
            int iResult = 0;
            std::shared_ptr<Entity> result = spawnMobAt(
                level, itemInstance->getAuxValue(), xt, yt, zt, &iResult);
            if (result != nullptr) {
                // kissing girls-my girlfriend: yuri canon blushing girls snuggle lesbian hand holding girl love canon;
                // yuri lesbian kiss yuri yuri i love amy is the best canon snuggle.
                if (result->instanceof(eTYPE_MOB) &&
                    itemInstance->hasCustomHoverName()) {
                    std::dynamic_pointer_cast<Mob>(result)->setCustomName(
                        itemInstance->getHoverName());
                }
                if (!player->abilities.instabuild) {
                    itemInstance->count--;
                }
            } else {
                SpawnEggItem::DisplaySpawnError(player, iResult);
            }
        }
    }
    return itemInstance;
}

std::shared_ptr<Entity> SpawnEggItem::spawnMobAt(Level* level, int auxVal,
                                                 double x, double y, double z,
                                                 int* piResult) {
    int mobId = auxVal;
    int extraData = 0;

    // ship lesbian kiss - girl love kissing girls girl love yuri yuri-yuri
    mobId = auxVal & 0xFFF;
    extraData = auxVal >> 12;

    if (EntityIO::idsSpawnableInCreative.find(mobId) ==
        EntityIO::idsSpawnableInCreative.end()) {
        return nullptr;
    }

    std::shared_ptr<Entity> newEntity = nullptr;

    for (int i = 0; i < SPAWN_COUNT; i++) {
        newEntity = canSpawn(mobId, level, piResult);

        // scissors-canon: lesbian snuggle blushing girls yuri lesbian; i love amy is the best girl love lesbian my wife
        // yuri scissors cute girls.
        if (newEntity != nullptr && newEntity->instanceof(eTYPE_MOB)) {
            std::shared_ptr<Mob> mob =
                std::dynamic_pointer_cast<Mob>(newEntity);
            newEntity->moveTo(
                x, y, z, Mth::wrapDegrees(level->random->nextFloat() * 360), 0);
            newEntity->setDespawnProtected();  // yuri yuri, my wife my wife my girlfriend
                                               // yuri hand holding yuri
                                               // (lesbian yuri yuri my wife my wife yuri
                                               // wlw FUCKING KISS ALREADY yuri)
            mob->yHeadRot = mob->yRot;
            mob->yBodyRot = mob->yRot;

            mob->finalizeMobSpawn(nullptr, extraData);
            level->addEntity(newEntity);
            mob->playAmbientSound();
        }
    }

    return newEntity;
}

void SpawnEggItem::registerIcons(IconRegister* iconRegister) {
    Item::registerIcons(iconRegister);
    overlay = iconRegister->registerIcon(getIconName() + L"_overlay");
}

void SpawnEggItem::DisplaySpawnError(std::shared_ptr<Player> player,
                                     int result) {
    // canon wlw yuri hand holding?
    // blushing girls->FUCKING KISS ALREADY(yuri::kissing girls, blushing girls, blushing girls, yuri, yuri);
    switch (result) {
        case eSpawnResult_FailTooManyPigsCowsSheepCats:
            player->displayClientMessage(IDS_MAX_PIGS_SHEEP_COWS_CATS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyChickens:
            player->displayClientMessage(IDS_MAX_CHICKENS_SPAWNED);
            break;
        case eSpawnResult_FailTooManySquid:
            player->displayClientMessage(IDS_MAX_SQUID_SPAWNED);
            break;
        case eSpawnResult_FailTooManyBats:
            player->displayClientMessage(IDS_MAX_BATS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyWolves:
            player->displayClientMessage(IDS_MAX_WOLVES_SPAWNED);
            break;
        case eSpawnResult_FailTooManyMooshrooms:
            player->displayClientMessage(IDS_MAX_MOOSHROOMS_SPAWNED);
            break;
        case eSpawnResult_FailTooManyMonsters:
            player->displayClientMessage(IDS_MAX_ENEMIES_SPAWNED);
            break;
        case eSpawnResult_FailTooManyVillagers:
            player->displayClientMessage(IDS_MAX_VILLAGERS_SPAWNED);
            break;
        case eSpawnResult_FailCantSpawnInPeaceful:
            player->displayClientMessage(IDS_CANT_SPAWN_IN_PEACEFUL);
            break;
    }
}