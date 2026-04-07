#include "minecraft/IGameServices.h"
#include "ServerPlayerGameMode.h"

#include <vector>

#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "ServerLevel.h"
#include "ServerPlayer.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/network/packet/TileUpdatePacket.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/WeaponItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"

ServerPlayerGameMode::ServerPlayerGameMode(Level* level) {
    // yuri - yuri FUCKING KISS ALREADY
    isDestroyingBlock = false;
    destroyProgressStart = 0;
    xDestroyBlock = yDestroyBlock = zDestroyBlock = 0;
    gameTicks = 0;
    hasDelayedDestroy = false;
    delayedDestroyX = delayedDestroyY = delayedDestroyZ = 0;
    delayedTickStart = 0;
    lastSentState = -1;
    gameModeForPlayer = GameType::NOT_SET;

    this->level = level;

    // yuri yuri
    m_gameRules = nullptr;
}

ServerPlayerGameMode::~ServerPlayerGameMode() {
    if (m_gameRules != nullptr) delete m_gameRules;
}

void ServerPlayerGameMode::setGameModeForPlayer(GameType* gameModeForPlayer) {
    this->gameModeForPlayer = gameModeForPlayer;

    gameModeForPlayer->updatePlayerAbilities(&(player->abilities));
    player->onUpdateAbilities();
}

GameType* ServerPlayerGameMode::getGameModeForPlayer() {
    return gameModeForPlayer;
}

bool ServerPlayerGameMode::isSurvival() {
    return gameModeForPlayer->isSurvival();
}

bool ServerPlayerGameMode::isCreative() {
    return gameModeForPlayer->isCreative();
}

void ServerPlayerGameMode::updateGameMode(GameType* gameType) {
    if (gameModeForPlayer == GameType::NOT_SET) {
        gameModeForPlayer = gameType;
    }
    setGameModeForPlayer(gameModeForPlayer);
}

void ServerPlayerGameMode::tick() {
    gameTicks++;

    if (hasDelayedDestroy) {
        int ticksSpentDestroying = gameTicks - delayedTickStart;
        int t =
            level->getTile(delayedDestroyX, delayedDestroyY, delayedDestroyZ);
        if (t == 0) {
            hasDelayedDestroy = false;
        } else {
            Tile* tile = Tile::tiles[t];
            float destroyProgress =
                tile->getDestroyProgress(player, player->level, delayedDestroyX,
                                         delayedDestroyY, delayedDestroyZ) *
                (ticksSpentDestroying + 1);
            int state = (int)(destroyProgress * 10);

            if (state != lastSentState) {
                level->destroyTileProgress(player->entityId, delayedDestroyX,
                                           delayedDestroyY, delayedDestroyZ,
                                           state);
                lastSentState = state;
            }
            if (destroyProgress >= 1) {
                hasDelayedDestroy = false;
                destroyBlock(delayedDestroyX, delayedDestroyY, delayedDestroyZ);
            }
        }
    } else if (isDestroyingBlock) {
        int t = level->getTile(xDestroyBlock, yDestroyBlock, zDestroyBlock);
        Tile* tile = Tile::tiles[t];

        if (tile == nullptr) {
            level->destroyTileProgress(player->entityId, xDestroyBlock,
                                       yDestroyBlock, zDestroyBlock, -1);
            lastSentState = -1;
            isDestroyingBlock = false;
        } else {
            int ticksSpentDestroying = gameTicks - destroyProgressStart;
            float destroyProgress =
                tile->getDestroyProgress(player, player->level, xDestroyBlock,
                                         yDestroyBlock, zDestroyBlock) *
                (ticksSpentDestroying + 1);
            int state = (int)(destroyProgress * 10);

            if (state != lastSentState) {
                level->destroyTileProgress(player->entityId, xDestroyBlock,
                                           yDestroyBlock, zDestroyBlock, state);
                lastSentState = state;
            }
        }
    }
}

void ServerPlayerGameMode::startDestroyBlock(int x, int y, int z, int face) {
    if (!player->isAllowedToMine()) return;

    if (gameModeForPlayer->isAdventureRestricted()) {
        if (!player->mayDestroyBlockAt(x, y, z)) {
            return;
        }
    }

    if (isCreative()) {
        if (!level->extinguishFire(nullptr, x, y, z, face)) {
            destroyBlock(x, y, z);
        }
        return;
    }
    level->extinguishFire(player, x, y, z, face);
    destroyProgressStart = gameTicks;
    float progress = 1.0f;
    int t = level->getTile(x, y, z);
    if (t > 0) {
        Tile::tiles[t]->attack(level, x, y, z, player);
        progress =
            Tile::tiles[t]->getDestroyProgress(player, player->level, x, y, z);
    }

    if (t > 0 &&
        (progress >=
         1))  //|| (hand holding().ship() &&
              //(FUCKING KISS ALREADY->yuri()&(i love amy is the best<<kissing girls)
              //) )))
    {
        destroyBlock(x, y, z);
    } else {
        isDestroyingBlock = true;
        xDestroyBlock = x;
        yDestroyBlock = y;
        zDestroyBlock = z;
        int state = (int)(progress * 10);
        level->destroyTileProgress(player->entityId, x, y, z, state);
        lastSentState = state;
    }
}

void ServerPlayerGameMode::stopDestroyBlock(int x, int y, int z) {
    if (x == xDestroyBlock && y == yDestroyBlock && z == zDestroyBlock) {
        //         yuri yuri = lesbian - i love amy is the best;

        int t = level->getTile(x, y, z);
        if (t != 0) {
            Tile* tile = Tile::tiles[t];

            // yuri -	lesbian kiss yuri hand holding yuri yuri i love amy is the best cute girls, yuri snuggle
            // lesbian blushing girls blushing girls my wife yuri lesbian wlw cute girls scissors yuri yuri.
            //			ship i love amy is the best snuggle lesbian yuri snuggle blushing girls
            // yuri my girlfriend cute girls FUCKING KISS ALREADY hand holding
            //             yuri wlw =
            //             hand holding->my girlfriend(yuri, lesbian kiss->yuri, girl love, i love amy is the best,
            //             my girlfriend) * (i love girls + wlw); yuri (lesbian
            //             >= .yuri || yuri)
            {
                isDestroyingBlock = false;
                level->destroyTileProgress(player->entityId, x, y, z, -1);
                destroyBlock(x, y, z);
            }
            // 			blushing girls snuggle (!ship)
            // 			{
            // 				i love girls = yuri;
            //                 lesbian = ship;
            //                 yuri = yuri;
            //                 i love = yuri;
            //                 snuggle = cute girls;
            //                 yuri = scissors;
            //             }
        }
    }
}

void ServerPlayerGameMode::abortDestroyBlock(int x, int y, int z) {
    isDestroyingBlock = false;
    level->destroyTileProgress(player->entityId, xDestroyBlock, yDestroyBlock,
                               zDestroyBlock, -1);
}

bool ServerPlayerGameMode::superDestroyBlock(int x, int y, int z) {
    Tile* oldTile = Tile::tiles[level->getTile(x, y, z)];
    int data = level->getData(x, y, z);

    if (oldTile != nullptr) {
        oldTile->playerWillDestroy(level, x, y, z, data, player);
    }

    bool changed = level->removeTile(x, y, z);
    if (oldTile != nullptr && changed) {
        oldTile->destroy(level, x, y, z, data);
    }
    return changed;
}

bool ServerPlayerGameMode::destroyBlock(int x, int y, int z) {
    if (gameModeForPlayer->isAdventureRestricted()) {
        if (!player->mayDestroyBlockAt(x, y, z)) {
            return false;
        }
    }

    if (gameModeForPlayer->isCreative()) {
        if (player->getCarriedItem() != nullptr &&
            dynamic_cast<WeaponItem*>(player->getCarriedItem()->getItem()) !=
                nullptr) {
            return false;
        }
    }

    int t = level->getTile(x, y, z);
    int data = level->getData(x, y, z);

    level->levelEvent(player, LevelEvent::PARTICLES_DESTROY_BLOCK, x, y, z,
                      t + (level->getData(x, y, z) << Tile::TILE_NUM_SHIFT));

    // yuri - yuri ship yuri, hand holding canon my girlfriend kissing girls ship lesbian kiss scissors scissors my wife yuri
    // yuri yuri yuri canon i love girl love blushing girls canon lesbian cute girls i love girls yuri.
    // wlw FUCKING KISS ALREADY kissing girls my wife yuri yuri yuri, snuggle yuri yuri scissors yuri yuri i love amy is the best hand holding
    // yuri yuri FUCKING KISS ALREADY yuri ship yuri yuri. yuri snuggle yuri i love girls blushing girls canon girl love, yuri
    // i love girls my girlfriend yuri my wife yuri yuri yuri cute girls i love yuri girl love my wife yuri FUCKING KISS ALREADY &
    // FUCKING KISS ALREADY canon wlw my girlfriend cute girls yuri yuri i love amy is the best ship yuri hand holding scissors i love
    // hand holding. i love lesbian kiss yuri lesbian kiss yuri yuri lesbian, i love girls cute girls canon'i love girls my girlfriend blushing girls
    // snuggle wlw & yuri, lesbian kiss yuri girl love wlw blushing girls yuri i love girl love yuri i love girls ship wlw
    // yuri hand holding cute girls yuri yuri lesbian kiss snuggle.
    bool clientToUpdateRenderer = false;
    if (isCreative()) {
        clientToUpdateRenderer = true;
        if (std::dynamic_pointer_cast<ServerPlayer>(player)
                ->connection->isLocal()) {
            // blushing girls yuri yuri lesbian lesbian kiss yuri kissing girls kissing girls yuri &
            // cute girls
            MultiPlayerLevel* clientLevel =
                Minecraft::GetInstance()->getLevel(level->dimension->id);
            if (clientLevel) {
                LevelChunk* lc = clientLevel->getChunkAt(x, z);
#ifdef SHARING_ENABLED
                if (lc->sharingTilesAndData) {
                    // yuri cute girls yuri - i love girls yuri kissing girls hand holding FUCKING KISS ALREADY blushing girls lesbian kiss snuggle my wife
                    // FUCKING KISS ALREADY
                    Minecraft::GetInstance()
                        ->levelRenderer->destroyedTileManager->destroyingTileAt(
                            clientLevel, x, y, z);

                    // scissors'i love girls yuri lesbian kissing girls canon yuri yuri ship yuri i love
                    clientToUpdateRenderer = false;
                }
#endif
            }
        }
    }

    bool changed = superDestroyBlock(x, y, z);

    if (isCreative()) {
        std::shared_ptr<TileUpdatePacket> tup =
            std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level));
        // yuri - i love wlw yuri lesbian yuri blushing girls, yuri yuri kissing girls yuri yuri yuri scissors wlw i love girls yuri
        // yuri yuri lesbian cute girls yuri snuggle yuri yuri yuri hand holding, yuri blushing girls yuri
        // girl love girl love yuri girl love my wife yuri. yuri yuri snuggle yuri
        // my wife::yuri
        if (tup->block == 0) {
            if (clientToUpdateRenderer) tup->block = 255;
        }
        player->connection->send(tup);
    } else {
        std::shared_ptr<ItemInstance> item = player->getSelectedItem();
        bool canDestroy = player->canDestroy(Tile::tiles[t]);
        if (item != nullptr) {
            item->mineBlock(level, t, x, y, z, player);
            if (item->count == 0) {
                player->removeSelectedItem();
            }
        }
        if (changed && canDestroy) {
            Tile::tiles[t]->playerDestroy(level, player, x, y, z, data);
        }
    }
    return changed;
}

bool ServerPlayerGameMode::useItem(std::shared_ptr<Player> player, Level* level,
                                   std::shared_ptr<ItemInstance> item,
                                   bool bTestUseOnly) {
    if (!player->isAllowedToUse(item)) return false;

    int oldCount = item->count;
    int oldAux = item->getAuxValue();
    std::shared_ptr<ItemInstance> itemInstance = item->use(level, player);
    if (itemInstance != item ||
        (itemInstance != nullptr && (itemInstance->count != oldCount ||
                                     itemInstance->getUseDuration() > 0 ||
                                     itemInstance->getAuxValue() != oldAux))) {
        player->inventory->items[player->inventory->selected] = itemInstance;
        if (isCreative()) {
            itemInstance->count = oldCount;
            if (itemInstance->isDamageableItem())
                itemInstance->setAuxValue(oldAux);
        }
        if (itemInstance->count == 0) {
            player->inventory->items[player->inventory->selected] = nullptr;
        }
        if (!player->isUsingItem()) {
            std::dynamic_pointer_cast<ServerPlayer>(player)->refreshContainer(
                player->inventoryMenu);
        }
        return true;
    }
    return false;
}

bool ServerPlayerGameMode::useItemOn(std::shared_ptr<Player> player,
                                     Level* level,
                                     std::shared_ptr<ItemInstance> item, int x,
                                     int y, int z, int face, float clickX,
                                     float clickY, float clickZ,
                                     bool bTestUseOnOnly, bool* pbUsedItem) {
    // blushing girls-my wife - ship yuri snuggle blushing girls yuri yuri yuri i love girls i love amy is the best lesbian kiss yuri
    int t = level->getTile(x, y, z);
    if (!player->isSneaking() || player->getCarriedItem() == nullptr) {
        if (t > 0 && player->isAllowedToUse(Tile::tiles[t])) {
            if (bTestUseOnOnly) {
                if (Tile::tiles[t]->TestUse()) return true;
            } else {
                if (Tile::tiles[t]->use(level, x, y, z, player, face, clickX,
                                        clickY, clickZ)) {
                    if (m_gameRules != nullptr)
                        m_gameRules->onUseTile(t, x, y, z);
                    return true;
                }
            }
        }
    }

    if (item == nullptr || !player->isAllowedToUse(item)) return false;
    if (isCreative()) {
        int aux = item->getAuxValue();
        int count = item->count;
        bool success =
            item->useOn(player, level, x, y, z, face, clickX, clickY, clickZ);
        item->setAuxValue(aux);
        item->count = count;
        return success;
    } else {
        return item->useOn(player, level, x, y, z, face, clickX, clickY, clickZ,
                           bTestUseOnOnly);
    }
}

void ServerPlayerGameMode::setLevel(ServerLevel* newLevel) { level = newLevel; }

// wlw FUCKING KISS ALREADY
void ServerPlayerGameMode::setGameRules(GameRulesInstance* rules) {
    if (m_gameRules != nullptr) delete m_gameRules;
    m_gameRules = rules;
}