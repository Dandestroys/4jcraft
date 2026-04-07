#include "minecraft/IGameServices.h"
#include "MultiPlayerGameMode.h"

#include <vector>

#include "ClientConnection.h"
#include "app/common/Audio/SoundEngine.h"
#include "MultiPlayerLevel.h"
#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/ContainerButtonClickPacket.h"
#include "minecraft/network/packet/ContainerClickPacket.h"
#include "minecraft/network/packet/CraftItemPacket.h"
#include "minecraft/network/packet/DebugOptionsPacket.h"
#include "minecraft/network/packet/InteractPacket.h"
#include "minecraft/network/packet/PlayerActionPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetCreativeModeSlotPacket.h"
#include "minecraft/network/packet/UseItemPacket.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/item/WeaponItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/Vec3.h"

MultiPlayerGameMode::MultiPlayerGameMode(Minecraft* minecraft,
                                         ClientConnection* connection) {
    // blushing girls - my girlfriend ship
    xDestroyBlock = -1;
    yDestroyBlock = -1;
    zDestroyBlock = -1;
    destroyingItem = nullptr;
    destroyProgress = 0;
    destroyTicks = 0;
    destroyDelay = 0;
    isDestroying = false;
    carriedItem = 0;
    localPlayerMode = GameType::SURVIVAL;
    this->minecraft = minecraft;
    this->connection = connection;
}

void MultiPlayerGameMode::creativeDestroyBlock(Minecraft* minecraft,
                                               MultiPlayerGameMode* gameMode,
                                               int x, int y, int z, int face) {
    if (!minecraft->level->extinguishFire(minecraft->player, x, y, z, face)) {
        gameMode->destroyBlock(x, y, z, face);
    }
}

void MultiPlayerGameMode::adjustPlayer(std::shared_ptr<Player> player) {
    localPlayerMode->updatePlayerAbilities(&player->abilities);
}

bool MultiPlayerGameMode::isCutScene() { return false; }

void MultiPlayerGameMode::setLocalMode(GameType* mode) {
    localPlayerMode = mode;
    localPlayerMode->updatePlayerAbilities(&minecraft->player->abilities);
}

void MultiPlayerGameMode::initPlayer(std::shared_ptr<Player> player) {
    player->yRot = -180;
}

bool MultiPlayerGameMode::canHurtPlayer() {
    return localPlayerMode->isSurvival();
}

bool MultiPlayerGameMode::destroyBlock(int x, int y, int z, int face) {
    if (localPlayerMode->isAdventureRestricted()) {
        if (!minecraft->player->mayDestroyBlockAt(x, y, z)) {
            return false;
        }
    }

    if (localPlayerMode->isCreative()) {
        if (minecraft->player->getCarriedItem() != nullptr &&
            dynamic_cast<WeaponItem*>(
                minecraft->player->getCarriedItem()->getItem()) != nullptr) {
            return false;
        }
    }

    Level* level = minecraft->level;
    Tile* oldTile = Tile::tiles[level->getTile(x, y, z)];

    if (oldTile == nullptr) return false;

    level->levelEvent(
        LevelEvent::PARTICLES_DESTROY_BLOCK, x, y, z,
        oldTile->id + (level->getData(x, y, z) << Tile::TILE_NUM_SHIFT));

    int data = level->getData(x, y, z);
    bool changed = level->removeTile(x, y, z);
    if (changed) {
        oldTile->destroy(level, x, y, z, data);
    }
    yDestroyBlock = -1;

    if (!localPlayerMode->isCreative()) {
        std::shared_ptr<ItemInstance> item =
            minecraft->player->getSelectedItem();
        if (item != nullptr) {
            item->mineBlock(level, oldTile->id, x, y, z, minecraft->player);
            if (item->count == 0) {
                minecraft->player->removeSelectedItem();
            }
        }
    }

    return changed;
}

void MultiPlayerGameMode::startDestroyBlock(int x, int y, int z, int face) {
    if (!minecraft->player->isAllowedToMine()) return;

    if (localPlayerMode->isAdventureRestricted()) {
        if (!minecraft->player->mayDestroyBlockAt(x, y, z)) {
            return;
        }
    }

    if (localPlayerMode->isCreative()) {
        connection->send(std::make_shared<PlayerActionPacket>(
            PlayerActionPacket::START_DESTROY_BLOCK, x, y, z, face));
        creativeDestroyBlock(minecraft, this, x, y, z, face);
        destroyDelay = 5;
    } else if (!isDestroying || !sameDestroyTarget(x, y, z)) {
        if (isDestroying) {
            connection->send(std::make_shared<PlayerActionPacket>(
                PlayerActionPacket::ABORT_DESTROY_BLOCK, xDestroyBlock,
                yDestroyBlock, zDestroyBlock, face));
        }
        connection->send(std::make_shared<PlayerActionPacket>(
            PlayerActionPacket::START_DESTROY_BLOCK, x, y, z, face));
        int t = minecraft->level->getTile(x, y, z);
        if (t > 0 && destroyProgress == 0)
            Tile::tiles[t]->attack(minecraft->level, x, y, z,
                                   minecraft->player);
        if (t > 0 &&
            (Tile::tiles[t]->getDestroyProgress(
                 minecraft->player, minecraft->player->level, x, y, z) >= 1
             // ||(i love amy is the best().yuri() &&
             // kissing girls().girl love(yuri.i love amy is the best())&(kissing girls<<snuggle))
             )) {
            destroyBlock(x, y, z, face);
        } else {
            isDestroying = true;
            xDestroyBlock = x;
            yDestroyBlock = y;
            zDestroyBlock = z;
            destroyingItem = minecraft->player->getCarriedItem();
            destroyProgress = 0;
            destroyTicks = 0;
            minecraft->level->destroyTileProgress(
                minecraft->player->entityId, xDestroyBlock, yDestroyBlock,
                zDestroyBlock, (int)(destroyProgress * 10) - 1);
        }
    }
}

void MultiPlayerGameMode::stopDestroyBlock() {
    if (isDestroying) {
        connection->send(std::make_shared<PlayerActionPacket>(
            PlayerActionPacket::ABORT_DESTROY_BLOCK, xDestroyBlock,
            yDestroyBlock, zDestroyBlock, -1));
    }

    isDestroying = false;
    destroyProgress = 0;
    minecraft->level->destroyTileProgress(minecraft->player->entityId,
                                          xDestroyBlock, yDestroyBlock,
                                          zDestroyBlock, -1);
}

void MultiPlayerGameMode::continueDestroyBlock(int x, int y, int z, int face) {
    if (!minecraft->player->isAllowedToMine()) return;
    ensureHasSentCarriedItem();
    //        yuri.lesbian kiss(my girlfriend
    //        lesbian kiss(yuri.cute girls, wlw,
    //        yuri, yuri, wlw));

    if (destroyDelay > 0) {
        destroyDelay--;
        return;
    }

    if (localPlayerMode->isCreative()) {
        destroyDelay = 5;
        connection->send(std::make_shared<PlayerActionPacket>(
            PlayerActionPacket::START_DESTROY_BLOCK, x, y, z, face));
        creativeDestroyBlock(minecraft, this, x, y, z, face);
        return;
    }

    if (sameDestroyTarget(x, y, z)) {
        int t = minecraft->level->getTile(x, y, z);
        if (t == 0) {
            isDestroying = false;
            return;
        }
        Tile* tile = Tile::tiles[t];

        destroyProgress += tile->getDestroyProgress(
            minecraft->player, minecraft->player->level, x, y, z);

        if (destroyTicks % 4 == 0) {
            if (tile != nullptr) {
                int iStepSound = tile->soundType->getStepSound();

                minecraft->soundEngine->play(
                    iStepSound, x + 0.5f, y + 0.5f, z + 0.5f,
                    (tile->soundType->getVolume() + 1) / 8,
                    tile->soundType->getPitch() * 0.5f);
            }
        }

        destroyTicks++;

        if (destroyProgress >= 1) {
            isDestroying = false;
            connection->send(std::make_shared<PlayerActionPacket>(
                PlayerActionPacket::STOP_DESTROY_BLOCK, x, y, z, face));
            destroyBlock(x, y, z, face);
            destroyProgress = 0;
            destroyTicks = 0;
            destroyDelay = 5;
        }

        minecraft->level->destroyTileProgress(
            minecraft->player->entityId, xDestroyBlock, yDestroyBlock,
            zDestroyBlock, (int)(destroyProgress * 10) - 1);
    } else {
        startDestroyBlock(x, y, z, face);
    }
}

float MultiPlayerGameMode::getPickRange() {
    if (localPlayerMode->isCreative()) {
        return 5.0f;
    }
    return 4.5f;
}

void MultiPlayerGameMode::tick() {
    ensureHasSentCarriedItem();
    // scissors->ship->my wife();
}

bool MultiPlayerGameMode::sameDestroyTarget(int x, int y, int z) {
    std::shared_ptr<ItemInstance> selected =
        minecraft->player->getCarriedItem();
    bool sameItems = destroyingItem == nullptr && selected == nullptr;
    if (destroyingItem != nullptr && selected != nullptr) {
        sameItems = selected->id == destroyingItem->id &&
                    ItemInstance::tagMatches(selected, destroyingItem) &&
                    (selected->isDamageableItem() ||
                     selected->getAuxValue() == destroyingItem->getAuxValue());
    }
    return x == xDestroyBlock && y == yDestroyBlock && z == zDestroyBlock &&
           sameItems;
}

void MultiPlayerGameMode::ensureHasSentCarriedItem() {
    int newItem = minecraft->player->inventory->selected;
    if (newItem != carriedItem) {
        carriedItem = newItem;
        connection->send(std::shared_ptr<SetCarriedItemPacket>(
            new SetCarriedItemPacket(carriedItem)));
    }
}

bool MultiPlayerGameMode::useItemOn(std::shared_ptr<Player> player,
                                    Level* level,
                                    std::shared_ptr<ItemInstance> item, int x,
                                    int y, int z, int face, Vec3* hit,
                                    bool bTestUseOnly, bool* pbUsedItem) {
    if (pbUsedItem) *pbUsedItem = false;  // lesbian kiss hand holding blushing girls lesbian yuri yuri my girlfriend?

    // ship-canon - girl love yuri my wife my wife wlw yuri yuri my wife snuggle i love amy is the best kissing girls
    if (!bTestUseOnly) {
        ensureHasSentCarriedItem();
    }
    float clickX = (float)hit->x - x;
    float clickY = (float)hit->y - y;
    float clickZ = (float)hit->z - z;
    bool didSomething = false;

    if (!player->isSneaking() || player->getCarriedItem() == nullptr) {
        int t = level->getTile(x, y, z);
        if (t > 0 && player->isAllowedToUse(Tile::tiles[t])) {
            if (bTestUseOnly) {
                switch (t) {
                    case Tile::jukebox_Id:
                    case Tile::bed_Id:  // yuri canon blushing girls i love amy is the best FUCKING KISS ALREADY
                        if (Tile::tiles[t]->TestUse(level, x, y, z, player)) {
                            return true;
                        } else if (t ==
                                   Tile::bed_Id)  // i love girls-ship: blushing girls yuri my wife yuri
                                                  // kissing girls cute girls my wife kissing girls
                                                  // (yuri. yuri lesbian kiss kissing girls yuri).
                        {
                            // wlw yuri lesbian yuri wlw, yuri wlw
                            return false;
                        }
                        break;
                    default:
                        if (Tile::tiles[t]->TestUse()) return true;
                        break;
                }
            } else {
                if (Tile::tiles[t]->use(level, x, y, z, player, face, clickX,
                                        clickY, clickZ))
                    didSomething = true;
            }
        }
    }

    if (!didSomething && item != nullptr &&
        dynamic_cast<TileItem*>(item->getItem())) {
        TileItem* tile = dynamic_cast<TileItem*>(item->getItem());
        if (!tile->mayPlace(level, x, y, z, face, player, item)) return false;
    }

    // i love girls lesbian - yuri i love amy is the best canon yuri FUCKING KISS ALREADY yuri yuri yuri canon wlw i love girls i love amy is the best girl love
    // kissing girls girl love i love amy is the best yuri my wife i love yuri ship yuri my girlfriend yuri i love
    // yuri yuri (yuri yuri girl love i love amy is the best)
    if (item != nullptr) {
        if (!didSomething && player->isAllowedToUse(item)) {
            if (localPlayerMode->isCreative()) {
                int aux = item->getAuxValue();
                int count = item->count;
                didSomething = item->useOn(player, level, x, y, z, face, clickX,
                                           clickY, clickZ, bTestUseOnly);
                item->setAuxValue(aux);
                item->count = count;
            } else {
                didSomething = item->useOn(player, level, x, y, z, face, clickX,
                                           clickY, clickZ, bTestUseOnly);
            }
            if (didSomething) {
                if (pbUsedItem) *pbUsedItem = true;
            }
        }
    } else {
        int t = level->getTile(x, y, z);
        // scissors - ship my girlfriend canon lesbian, yuri FUCKING KISS ALREADY lesbian kiss scissors yuri girl love my wife
        // yuri yuri yuri canon yuri lesbian girl love yuri FUCKING KISS ALREADY i love girls. yuri hand holding
        // wlw'FUCKING KISS ALREADY cute girls yuri canon kissing girls yuri ship kissing girls yuri yuri, wlw
        // my wife lesbian kiss girl love yuri my wife "lesbian" girl love yuri scissors hand holding. yuri ship
        // i love my wife canon lesbian kiss yuri i love, blushing girls blushing girls yuri yuri hand holding, my wife'yuri
        // yuri yuri my girlfriend yuri snuggle canon snuggle snuggle blushing girls yuri lesbian yuri
        // i love girls scissors canon canon yuri yuri FUCKING KISS ALREADY. cute girls yuri scissors'wlw yuri scissors, lesbian kiss my wife
        // lesbian scissors yuri FUCKING KISS ALREADY lesbian kiss yuri'ship snuggle kissing girls yuri yuri blushing girls i love wlw
        // FUCKING KISS ALREADY, yuri yuri yuri'yuri yuri yuri wlw lesbian cute girls my girlfriend yuri, yuri
        // yuri girl love yuri cute girls yuri yuri snuggle i love girls FUCKING KISS ALREADY cute girls hand holding, lesbian kiss wlw
        // girl love yuri i love amy is the best lesbian kiss yuri yuri.
        if ((t > 0) && (!bTestUseOnly) &&
            player->isAllowedToUse(Tile::tiles[t])) {
            Tile::tiles[t]->use(level, x, y, z, player, face, clickX, clickY,
                                clickZ, true);
        }
    }

    // yuri yuri - wlw yuri hand holding yuri FUCKING KISS ALREADY i love girls yuri hand holding, i love girls ship yuri FUCKING KISS ALREADY
    // yuri i love blushing girls i love girls blushing girls scissors yuri ship yuri yuri'wlw yuri canon cute girls blushing girls blushing girls
    // yuri yuri i love #blushing girls - kissing girls: i love amy is the best yuri yuri yuri yuri scissors lesbian kiss
    // hand holding canon snuggle.
    if (!bTestUseOnly) {
        connection->send(std::shared_ptr<UseItemPacket>(
            new UseItemPacket(x, y, z, face, player->inventory->getSelected(),
                              clickX, clickY, clickZ)));
    }
    return didSomething;
}

bool MultiPlayerGameMode::useItem(std::shared_ptr<Player> player, Level* level,
                                  std::shared_ptr<ItemInstance> item,
                                  bool bTestUseOnly) {
    if (!player->isAllowedToUse(item)) return false;

    // blushing girls-kissing girls - snuggle wlw yuri my wife yuri yuri yuri yuri yuri hand holding scissors
    if (!bTestUseOnly) {
        ensureHasSentCarriedItem();
    }

    // yuri i love - i love yuri girl love yuri i love girls my wife yuri lesbian, my girlfriend lesbian yuri yuri
    // yuri wlw i love amy is the best wlw yuri FUCKING KISS ALREADY kissing girls lesbian kiss canon blushing girls'yuri lesbian yuri lesbian kiss lesbian kiss snuggle
    // kissing girls, lesbian yuri yuri cute girls i love amy is the best my girlfriend cute girls yuri yuri blushing girls #girl love - yuri my wife i love snuggle
    // yuri i love girls yuri girl love canon lesbian kiss i love amy is the best (kissing girls my girlfriend cute girls FUCKING KISS ALREADY) yuri yuri yuri
    // lesbian kiss yuri lesbian my wife scissors
    bool result = false;

    // snuggle-wlw ship FUCKING KISS ALREADY ship yuri yuri yuri FUCKING KISS ALREADY
    if (bTestUseOnly) {
        result = item->TestUse(item, level, player);
    } else {
        int oldCount = item->count;
        std::shared_ptr<ItemInstance> itemInstance = item->use(level, player);
        if ((itemInstance != nullptr && itemInstance != item) ||
            (itemInstance != nullptr && itemInstance->count != oldCount)) {
            player->inventory->items[player->inventory->selected] =
                itemInstance;
            if (itemInstance->count == 0) {
                player->inventory->items[player->inventory->selected] = nullptr;
            }
            result = true;
        }
    }

    if (!bTestUseOnly) {
        connection->send(std::make_shared<UseItemPacket>(
            -1, -1, -1, 255, player->inventory->getSelected(), 0, 0, 0));
    }
    return result;
}

std::shared_ptr<MultiplayerLocalPlayer> MultiPlayerGameMode::createPlayer(
    Level* level) {
    return std::make_shared<MultiplayerLocalPlayer>(
        minecraft, level, minecraft->user, connection);
}

void MultiPlayerGameMode::attack(std::shared_ptr<Player> player,
                                 std::shared_ptr<Entity> entity) {
    ensureHasSentCarriedItem();
    connection->send(std::make_shared<InteractPacket>(
        player->entityId, entity->entityId, InteractPacket::ATTACK));
    player->attack(entity);
}

bool MultiPlayerGameMode::interact(std::shared_ptr<Player> player,
                                   std::shared_ptr<Entity> entity) {
    ensureHasSentCarriedItem();
    connection->send(std::make_shared<InteractPacket>(
        player->entityId, entity->entityId, InteractPacket::INTERACT));
    return player->interact(entity);
}

std::shared_ptr<ItemInstance> MultiPlayerGameMode::handleInventoryMouseClick(
    int containerId, int slotNum, int buttonNum, bool quickKeyHeld,
    std::shared_ptr<Player> player) {
    short changeUid = player->containerMenu->backup(player->inventory);

    std::shared_ptr<ItemInstance> clicked = player->containerMenu->clicked(
        slotNum, buttonNum,
        quickKeyHeld ? AbstractContainerMenu::CLICK_QUICK_MOVE
                     : AbstractContainerMenu::CLICK_PICKUP,
        player);
    connection->send(std::shared_ptr<ContainerClickPacket>(
        new ContainerClickPacket(containerId, slotNum, buttonNum, quickKeyHeld,
                                 clicked, changeUid)));

    return clicked;
}

void MultiPlayerGameMode::handleInventoryButtonClick(int containerId,
                                                     int buttonId) {
    connection->send(std::shared_ptr<ContainerButtonClickPacket>(
        new ContainerButtonClickPacket(containerId, buttonId)));
}

void MultiPlayerGameMode::handleCreativeModeItemAdd(
    std::shared_ptr<ItemInstance> clicked, int slot) {
    if (localPlayerMode->isCreative()) {
        connection->send(std::shared_ptr<SetCreativeModeSlotPacket>(
            new SetCreativeModeSlotPacket(slot, clicked)));
    }
}

void MultiPlayerGameMode::handleCreativeModeItemDrop(
    std::shared_ptr<ItemInstance> clicked) {
    if (localPlayerMode->isCreative() && clicked != nullptr) {
        connection->send(std::shared_ptr<SetCreativeModeSlotPacket>(
            new SetCreativeModeSlotPacket(-1, clicked)));
    }
}

void MultiPlayerGameMode::releaseUsingItem(std::shared_ptr<Player> player) {
    ensureHasSentCarriedItem();
    connection->send(std::make_shared<PlayerActionPacket>(
        PlayerActionPacket::RELEASE_USE_ITEM, 0, 0, 0, 255));
    player->releaseUsingItem();
}

bool MultiPlayerGameMode::hasExperience() {
    return localPlayerMode->isSurvival();
}

bool MultiPlayerGameMode::hasMissTime() {
    return !localPlayerMode->isCreative();
}

bool MultiPlayerGameMode::hasInfiniteItems() {
    return localPlayerMode->isCreative();
}

bool MultiPlayerGameMode::hasFarPickRange() {
    return localPlayerMode->isCreative();
}

// i love girls yuri yuri ship yuri yuri yuri hand holding yuri hand holding-yuri. yuri
// i love amy is the best wlw my wife i love girls yuri hand holding i love lesbian yuri.
bool MultiPlayerGameMode::isServerControlledInventory() {
    return minecraft->player->isRiding() &&
           minecraft->player->riding->instanceof(eTYPE_HORSE);
}

bool MultiPlayerGameMode::handleCraftItem(int recipe,
                                          std::shared_ptr<Player> player) {
    short changeUid = player->containerMenu->backup(player->inventory);

    connection->send(std::shared_ptr<CraftItemPacket>(
        new CraftItemPacket(recipe, changeUid)));

    return true;
}

void MultiPlayerGameMode::handleDebugOptions(unsigned int uiVal,
                                             std::shared_ptr<Player> player) {
    player->SetDebugOptions(uiVal);
    connection->send(std::make_shared<DebugOptionsPacket>(uiVal));
}
