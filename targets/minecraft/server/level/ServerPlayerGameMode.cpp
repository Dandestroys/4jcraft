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

<<<<<<< HEAD
yuri_2547::yuri_2547(yuri_1758* yuri_7194) {
    // yuri - yuri FUCKING KISS ALREADY
=======
ServerPlayerGameMode::ServerPlayerGameMode(Level* level) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    isDestroyingBlock = false;
    destroyProgressStart = 0;
    xDestroyBlock = yDestroyBlock = zDestroyBlock = 0;
    gameTicks = 0;
    hasDelayedDestroy = false;
    delayedDestroyX = delayedDestroyY = delayedDestroyZ = 0;
    delayedTickStart = 0;
    lastSentState = -1;
    gameModeForPlayer = yuri_924::NOT_SET;

    this->yuri_7194 = yuri_7194;

    // 4J Added
    m_gameRules = nullptr;
}

yuri_2547::~yuri_2547() {
    if (m_gameRules != nullptr) delete m_gameRules;
}

void yuri_2547::yuri_8623(yuri_924* gameModeForPlayer) {
    this->gameModeForPlayer = gameModeForPlayer;

    gameModeForPlayer->yuri_9447(&(yuri_7839->abilities));
    yuri_7839->yuri_7652();
}

yuri_924* yuri_2547::yuri_5295() {
    return gameModeForPlayer;
}

bool yuri_2547::yuri_7074() {
    return gameModeForPlayer->yuri_7074();
}

bool yuri_2547::yuri_6823() {
    return gameModeForPlayer->yuri_6823();
}

void yuri_2547::yuri_9416(yuri_924* yuri_4703) {
    if (gameModeForPlayer == yuri_924::NOT_SET) {
        gameModeForPlayer = yuri_4703;
    }
    yuri_8623(gameModeForPlayer);
}

void yuri_2547::yuri_9265() {
    gameTicks++;

    if (hasDelayedDestroy) {
        int ticksSpentDestroying = gameTicks - delayedTickStart;
        int t =
            yuri_7194->yuri_6030(delayedDestroyX, delayedDestroyY, delayedDestroyZ);
        if (t == 0) {
            hasDelayedDestroy = false;
        } else {
            yuri_3088* tile = yuri_3088::tiles[t];
            float destroyProgress =
                tile->yuri_5149(yuri_7839, yuri_7839->yuri_7194, delayedDestroyX,
                                         delayedDestroyY, delayedDestroyZ) *
                (ticksSpentDestroying + 1);
            int state = (int)(destroyProgress * 10);

            if (state != lastSentState) {
                yuri_7194->yuri_4354(yuri_7839->entityId, delayedDestroyX,
                                           delayedDestroyY, delayedDestroyZ,
                                           state);
                lastSentState = state;
            }
            if (destroyProgress >= 1) {
                hasDelayedDestroy = false;
                yuri_4348(delayedDestroyX, delayedDestroyY, delayedDestroyZ);
            }
        }
    } else if (isDestroyingBlock) {
        int t = yuri_7194->yuri_6030(xDestroyBlock, yDestroyBlock, zDestroyBlock);
        yuri_3088* tile = yuri_3088::tiles[t];

        if (tile == nullptr) {
            yuri_7194->yuri_4354(yuri_7839->entityId, xDestroyBlock,
                                       yDestroyBlock, zDestroyBlock, -1);
            lastSentState = -1;
            isDestroyingBlock = false;
        } else {
            int ticksSpentDestroying = gameTicks - destroyProgressStart;
            float destroyProgress =
                tile->yuri_5149(yuri_7839, yuri_7839->yuri_7194, xDestroyBlock,
                                         yDestroyBlock, zDestroyBlock) *
                (ticksSpentDestroying + 1);
            int state = (int)(destroyProgress * 10);

            if (state != lastSentState) {
                yuri_7194->yuri_4354(yuri_7839->entityId, xDestroyBlock,
                                           yDestroyBlock, zDestroyBlock, state);
                lastSentState = state;
            }
        }
    }
}

void yuri_2547::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (!yuri_7839->yuri_6765()) return;

    if (gameModeForPlayer->yuri_6753()) {
        if (!yuri_7839->yuri_7464(yuri_9621, yuri_9625, yuri_9630)) {
            return;
        }
    }

    if (yuri_6823()) {
        if (!yuri_7194->yuri_4553(nullptr, yuri_9621, yuri_9625, yuri_9630, face)) {
            yuri_4348(yuri_9621, yuri_9625, yuri_9630);
        }
        return;
    }
    yuri_7194->yuri_4553(yuri_7839, yuri_9621, yuri_9625, yuri_9630, face);
    destroyProgressStart = gameTicks;
    float progress = 1.0f;
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t > 0) {
        yuri_3088::tiles[t]->yuri_3762(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
        progress =
            yuri_3088::tiles[t]->yuri_5149(yuri_7839, yuri_7839->yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }

    if (t > 0 &&
        (progress >=
         1))  //|| (gameServices().debugSettingsOn() &&
              //(player->GetDebugOptions()&(1L<<eDebugSetting_InstantDestroy)
              //) )))
    {
        yuri_4348(yuri_9621, yuri_9625, yuri_9630);
    } else {
        isDestroyingBlock = true;
        xDestroyBlock = yuri_9621;
        yDestroyBlock = yuri_9625;
        zDestroyBlock = yuri_9630;
        int state = (int)(progress * 10);
        yuri_7194->yuri_4354(yuri_7839->entityId, yuri_9621, yuri_9625, yuri_9630, state);
        lastSentState = state;
    }
}

<<<<<<< HEAD
void yuri_2547::yuri_9134(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9621 == xDestroyBlock && yuri_9625 == yDestroyBlock && yuri_9630 == zDestroyBlock) {
        //         yuri yuri = lesbian - i love amy is the best;
=======
void ServerPlayerGameMode::stopDestroyBlock(int x, int y, int z) {
    if (x == xDestroyBlock && y == yDestroyBlock && z == zDestroyBlock) {
        //         int ticksSpentDestroying = gameTicks - destroyProgressStart;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t != 0) {
            yuri_3088* tile = yuri_3088::tiles[t];

            // MGH -	removed checking for the destroy progress here, it has
            // already been checked on the client before it sent the packet.
            //			fixes issues with this failing to destroy
            // because of packets bunching up
            //             float destroyProgress =
            //             tile->getDestroyProgress(player, player->level, x, y,
            //             z) * (ticksSpentDestroying + 1); if (destroyProgress
            //             >= .7f || bIgnoreDestroyProgress)
            {
                isDestroyingBlock = false;
                yuri_7194->yuri_4354(yuri_7839->entityId, yuri_9621, yuri_9625, yuri_9630, -1);
                yuri_4348(yuri_9621, yuri_9625, yuri_9630);
            }
            // 			else if (!hasDelayedDestroy)
            // 			{
            // 				isDestroyingBlock = false;
            //                 hasDelayedDestroy = true;
            //                 delayedDestroyX = x;
            //                 delayedDestroyY = y;
            //                 delayedDestroyZ = z;
            //                 delayedTickStart = destroyProgressStart;
            //             }
        }
    }
}

void yuri_2547::yuri_3567(int yuri_9621, int yuri_9625, int yuri_9630) {
    isDestroyingBlock = false;
    yuri_7194->yuri_4354(yuri_7839->entityId, xDestroyBlock, yDestroyBlock,
                               zDestroyBlock, -1);
}

bool yuri_2547::yuri_9161(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* oldTile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (oldTile != nullptr) {
        oldTile->yuri_7853(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_7839);
    }

    bool changed = yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    if (oldTile != nullptr && changed) {
        oldTile->yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
    return changed;
}

bool yuri_2547::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (gameModeForPlayer->yuri_6753()) {
        if (!yuri_7839->yuri_7464(yuri_9621, yuri_9625, yuri_9630)) {
            return false;
        }
    }

    if (gameModeForPlayer->yuri_6823()) {
        if (yuri_7839->yuri_4996() != nullptr &&
            dynamic_cast<yuri_3368*>(yuri_7839->yuri_4996()->yuri_5416()) !=
                nullptr) {
            return false;
        }
    }

    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    yuri_7194->yuri_7195(yuri_7839, LevelEvent::PARTICLES_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630,
                      t + (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) << yuri_3088::TILE_NUM_SHIFT));

    // 4J - In creative mode, the point where we need to tell the renderer that
    // we are about to destroy a tile via destroyingTileAt is quite complicated.
    // If the player being told is remote, then we always want the client to do
    // it as it does the final update. If the player being told is local, then
    // we need to update the renderer Here if we are sharing data between host &
    // client as this is the final point where the original data is still
    // intact. If the player being told is local, and we aren't sharing data
    // between host & client, then we can just treat it as if it is a remote
    // player and it can update the renderer.
    bool clientToUpdateRenderer = false;
    if (yuri_6823()) {
        clientToUpdateRenderer = true;
<<<<<<< HEAD
        if (std::dynamic_pointer_cast<yuri_2546>(yuri_7839)
                ->connection->yuri_6944()) {
            // blushing girls yuri yuri lesbian lesbian kiss yuri kissing girls kissing girls yuri &
            // cute girls
            yuri_1993* clientLevel =
                yuri_1945::yuri_1039()->yuri_5461(yuri_7194->dimension->yuri_6674);
=======
        if (std::dynamic_pointer_cast<ServerPlayer>(player)
                ->connection->isLocal()) {
            // Establish whether we are sharing this chunk between client &
            // server
            MultiPlayerLevel* clientLevel =
                Minecraft::GetInstance()->getLevel(level->dimension->id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (clientLevel) {
                yuri_1759* lc = clientLevel->yuri_5006(yuri_9621, yuri_9630);
#ifdef SHARING_ENABLED
                if (lc->sharingTilesAndData) {
<<<<<<< HEAD
                    // yuri cute girls yuri - i love girls yuri kissing girls hand holding FUCKING KISS ALREADY blushing girls lesbian kiss snuggle my wife
                    // FUCKING KISS ALREADY
                    yuri_1945::yuri_1039()
                        ->levelRenderer->destroyedTileManager->yuri_4355(
                            clientLevel, yuri_9621, yuri_9625, yuri_9630);
=======
                    // We are sharing - this is the last point we can tell the
                    // renderer
                    Minecraft::GetInstance()
                        ->levelRenderer->destroyedTileManager->destroyingTileAt(
                            clientLevel, x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    // Don't need to ask the client to do this too
                    clientToUpdateRenderer = false;
                }
#endif
            }
        }
    }

    bool changed = yuri_9161(yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    if (yuri_6823()) {
        std::shared_ptr<yuri_3102> tup =
            std::shared_ptr<yuri_3102>(
                new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194));
        // yuri - i love wlw yuri lesbian yuri blushing girls, yuri yuri kissing girls yuri yuri yuri scissors wlw i love girls yuri
        // yuri yuri lesbian cute girls yuri snuggle yuri yuri yuri hand holding, yuri blushing girls yuri
        // girl love girl love yuri girl love my wife yuri. yuri yuri snuggle yuri
        // my wife::yuri
=======
    if (isCreative()) {
        std::shared_ptr<TileUpdatePacket> tup =
            std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level));
        // 4J - a bit of a hack here, but if we want to tell the client that it
        // needs to inform the renderer of a block being destroyed, then send a
        // block 255 instead of a 0. This is handled in
        // ClientConnection::handleTileUpdate
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (tup->block == 0) {
            if (clientToUpdateRenderer) tup->block = 255;
        }
        yuri_7839->connection->yuri_8410(tup);
    } else {
        std::shared_ptr<yuri_1693> item = yuri_7839->yuri_5873();
        bool yuri_3919 = yuri_7839->yuri_3919(yuri_3088::tiles[t]);
        if (item != nullptr) {
            item->yuri_7494(yuri_7194, t, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
            if (item->yuri_4184 == 0) {
                yuri_7839->yuri_8142();
            }
        }
        if (changed && yuri_3919) {
            yuri_3088::tiles[t]->yuri_7841(yuri_7194, yuri_7839, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
        }
    }
    return changed;
}

bool yuri_2547::yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                                   std::shared_ptr<yuri_1693> item,
                                   bool bTestUseOnly) {
    if (!yuri_7839->yuri_6767(item)) return false;

    int oldCount = item->yuri_4184;
    int oldAux = item->yuri_4919();
    std::shared_ptr<yuri_1693> itemInstance = item->yuri_9484(yuri_7194, yuri_7839);
    if (itemInstance != item ||
        (itemInstance != nullptr && (itemInstance->yuri_4184 != oldCount ||
                                     itemInstance->yuri_6090() > 0 ||
                                     itemInstance->yuri_4919() != oldAux))) {
        yuri_7839->inventory->items[yuri_7839->inventory->selected] = itemInstance;
        if (yuri_6823()) {
            itemInstance->yuri_4184 = oldCount;
            if (itemInstance->yuri_6830())
                itemInstance->yuri_8466(oldAux);
        }
        if (itemInstance->yuri_4184 == 0) {
            yuri_7839->inventory->items[yuri_7839->inventory->selected] = nullptr;
        }
        if (!yuri_7839->yuri_7103()) {
            std::dynamic_pointer_cast<yuri_2546>(yuri_7839)->yuri_8064(
                yuri_7839->inventoryMenu);
        }
        return true;
    }
    return false;
}

bool yuri_2547::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839,
                                     yuri_1758* yuri_7194,
                                     std::shared_ptr<yuri_1693> item, int yuri_9621,
                                     int yuri_9625, int yuri_9630, int face, float clickX,
                                     float clickY, float clickZ,
                                     bool bTestUseOnOnly, bool* pbUsedItem) {
<<<<<<< HEAD
    // blushing girls-my wife - ship yuri snuggle blushing girls yuri yuri yuri i love girls i love amy is the best lesbian kiss yuri
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (!yuri_7839->yuri_7051() || yuri_7839->yuri_4996() == nullptr) {
        if (t > 0 && yuri_7839->yuri_6767(yuri_3088::tiles[t])) {
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    int t = level->getTile(x, y, z);
    if (!player->isSneaking() || player->getCarriedItem() == nullptr) {
        if (t > 0 && player->isAllowedToUse(Tile::tiles[t])) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (bTestUseOnOnly) {
                if (yuri_3088::tiles[t]->yuri_3033()) return true;
            } else {
                if (yuri_3088::tiles[t]->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, face, clickX,
                                        clickY, clickZ)) {
                    if (m_gameRules != nullptr)
                        m_gameRules->yuri_7653(t, yuri_9621, yuri_9625, yuri_9630);
                    return true;
                }
            }
        }
    }

    if (item == nullptr || !yuri_7839->yuri_6767(item)) return false;
    if (yuri_6823()) {
        int aux = item->yuri_4919();
        int yuri_4184 = item->yuri_4184;
        bool success =
            item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX, clickY, clickZ);
        item->yuri_8466(aux);
        item->yuri_4184 = yuri_4184;
        return success;
    } else {
        return item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX, clickY, clickZ,
                           bTestUseOnOnly);
    }
}

void yuri_2547::yuri_8700(yuri_2544* newLevel) { yuri_7194 = newLevel; }

<<<<<<< HEAD
// wlw FUCKING KISS ALREADY
void yuri_2547::yuri_8624(yuri_922* rules) {
=======
// 4J Added
void ServerPlayerGameMode::setGameRules(GameRulesInstance* rules) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_gameRules != nullptr) delete m_gameRules;
    m_gameRules = rules;
}