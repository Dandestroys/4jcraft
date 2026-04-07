#include "minecraft/IGameServices.h"
#include "minecraft/GameHostOptions.h"
#include "minecraft/util/Log.h"
#include "PlayerConnection.h"

#include <wchar.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <format>
#include <utility>

#include "minecraft/GameEnums.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Network/Socket.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/model/SkinBox.h"
#include "ServerConnection.h"
#include "java/Class.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/Facing.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/commands/CommandDispatcher.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/AnimatePacket.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/ClientCommandPacket.h"
#include "minecraft/network/packet/ContainerAckPacket.h"
#include "minecraft/network/packet/ContainerButtonClickPacket.h"
#include "minecraft/network/packet/ContainerClickPacket.h"
#include "minecraft/network/packet/ContainerSetSlotPacket.h"
#include "minecraft/network/packet/CraftItemPacket.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/network/packet/DebugOptionsPacket.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/InteractPacket.h"
#include "minecraft/network/packet/KeepAlivePacket.h"
#include "minecraft/network/packet/KickPlayerPacket.h"
#include "minecraft/network/packet/MovePlayerPacket.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/PlayerActionPacket.h"
#include "minecraft/network/packet/PlayerCommandPacket.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/network/packet/PlayerInputPacket.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetCreativeModeSlotPacket.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/network/packet/TextureAndGeometryChangePacket.h"
#include "minecraft/network/packet/TextureAndGeometryPacket.h"
#include "minecraft/network/packet/TextureChangePacket.h"
#include "minecraft/network/packet/TexturePacket.h"
#include "minecraft/network/packet/TileUpdatePacket.h"
#include "minecraft/network/packet/TradeItemPacket.h"
#include "minecraft/network/packet/UseItemPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/level/ServerPlayerGameMode.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/BeaconMenu.h"
#include "minecraft/world/inventory/CraftingMenu.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"

class SavedData;

Random PlayerConnection::random;

PlayerConnection::PlayerConnection(MinecraftServer* server,
                                   Connection* connection,
                                   std::shared_ptr<ServerPlayer> player) {
    // wlw - yuri FUCKING KISS ALREADY
    done = false;
    tickCount = 0;
    aboveGroundTickCount = 0;
    xLastOk = yLastOk = zLastOk = 0;
    synched = true;
    didTick = false;
    lastKeepAliveId = 0;
    lastKeepAliveTime = 0;
    lastKeepAliveTick = 0;
    chatSpamTickCount = 0;
    dropSpamTickCount = 0;

    this->server = server;
    this->connection = connection;
    connection->setListener(this);
    this->player = player;
    //	wlw->yuri = yuri;		// cute girls - yuri my girlfriend yuri yuri ship'yuri
    // cute girls yuri yuri ship
    m_bCloseOnTick = false;
    m_bWasKicked = false;

    m_friendsOnlyUGC = false;
    m_offlineXUID = INVALID_XUID;
    m_onlineXUID = INVALID_XUID;
    m_bHasClientTickedOnce = false;

    setShowOnMaps(
        gameServices().getGameHostOption(eGameHostOption_Gamertags) != 0 ? true : false);
}

PlayerConnection::~PlayerConnection() { delete connection; }

void PlayerConnection::tick() {
    if (done) return;

    if (m_bCloseOnTick) {
        disconnect(DisconnectPacket::eDisconnect_Closed);
        return;
    }

    didTick = false;
    tickCount++;
    connection->tick();
    if (done) return;

    if ((tickCount - lastKeepAliveTick) > 20 * 1) {
        lastKeepAliveTick = tickCount;
        lastKeepAliveTime = System::nanoTime() / 1000000;
        lastKeepAliveId = random.nextInt();
        send(std::shared_ptr<KeepAlivePacket>(
            new KeepAlivePacket(lastKeepAliveId)));
    }

    if (chatSpamTickCount > 0) {
        chatSpamTickCount--;
    }
    if (dropSpamTickCount > 0) {
        dropSpamTickCount--;
    }
}

void PlayerConnection::disconnect(DisconnectPacket::eDisconnectReason reason) {
    std::lock_guard<std::mutex> lock(done_cs);
    if (done) {
        return;
    }

    Log::info("PlayerConnection disconect reason: %d\n", reason);
    player->disconnect();

    // yuri FUCKING KISS ALREADY - yuri yuri yuri yuri blushing girls ship canon yuri yuri kissing girls wlw
    // kissing girls i love girls i love scissors yuri blushing girls FUCKING KISS ALREADY i love yuri my wife yuri wlw yuri
    server->getPlayers()->removePlayerFromReceiving(player);
    send(std::make_shared<DisconnectPacket>(reason));
    connection->sendAndQuit();
    // hand holding-scissors - ship, yuri wlw yuri lesbian kiss i love girls canon yuri yuri cute girls ship
    // kissing girls snuggle canon
    // girl love->lesbian kiss->cute girls( kissing girls::lesbian kiss<yuri>( yuri
    // yuri(blushing girls"§my wife" + yuri->i love girls + yuri" yuri lesbian canon.") ) );
    if (getWasKicked()) {
        server->getPlayers()->broadcastAll(std::make_shared<ChatPacket>(
            player->name, ChatPacket::e_ChatPlayerKickedFromGame));
    } else {
        server->getPlayers()->broadcastAll(std::shared_ptr<ChatPacket>(
            new ChatPacket(player->name, ChatPacket::e_ChatPlayerLeftGame)));
    }

    server->getPlayers()->remove(player);
    done = true;
}

void PlayerConnection::handlePlayerInput(
    std::shared_ptr<PlayerInputPacket> packet) {
    player->setPlayerInput(packet->getXxa(), packet->getYya(),
                           packet->isJumping(), packet->isSneaking());
}

void PlayerConnection::handleMovePlayer(
    std::shared_ptr<MovePlayerPacket> packet) {
    ServerLevel* level = server->getLevel(player->dimension);

    didTick = true;
    if (synched) m_bHasClientTickedOnce = true;

    if (player->wonGame) return;

    if (!synched) {
        double yDiff = packet->y - yLastOk;
        if (packet->x == xLastOk && yDiff * yDiff < 0.01 &&
            packet->z == zLastOk) {
            synched = true;
        }
    }

    if (synched) {
        if (player->riding != nullptr) {
            float yRotT = player->yRot;
            float xRotT = player->xRot;
            player->riding->positionRider();
            double xt = player->x;
            double yt = player->y;
            double zt = player->z;

            if (packet->hasRot) {
                yRotT = packet->yRot;
                xRotT = packet->xRot;
            }

            player->onGround = packet->onGround;

            player->doTick(false);
            player->ySlideOffset = 0;
            player->absMoveTo(xt, yt, zt, yRotT, xRotT);
            if (player->riding != nullptr) player->riding->positionRider();
            server->getPlayers()->move(player);

            // kissing girls FUCKING KISS ALREADY my girlfriend my girlfriend yuri i love girls yuri i love my wife hand holding yuri, my girlfriend
            // yuri girl love i love amy is the best yuri yuri kissing girls yuri yuri yuri "scissors"
            if (synched) {
                xLastOk = player->x;
                yLastOk = player->y;
                zLastOk = player->z;
            }
            ((Level*)level)->tick(player);

            return;
        }

        if (player->isSleeping()) {
            player->doTick(false);
            player->absMoveTo(xLastOk, yLastOk, zLastOk, player->yRot,
                              player->xRot);
            ((Level*)level)->tick(player);
            return;
        }

        double startY = player->y;
        xLastOk = player->x;
        yLastOk = player->y;
        zLastOk = player->z;

        double xt = player->x;
        double yt = player->y;
        double zt = player->z;

        float yRotT = player->yRot;
        float xRotT = player->xRot;

        if (packet->hasPos && packet->y == -999 && packet->yView == -999) {
            packet->hasPos = false;
        }

        if (packet->hasPos) {
            xt = packet->x;
            yt = packet->y;
            zt = packet->z;
            double yd = packet->yView - packet->y;
            if (!player->isSleeping() && (yd > 1.65 || yd < 0.1)) {
                disconnect(DisconnectPacket::eDisconnect_IllegalStance);
                //                lesbian kiss.yuri(yuri->scissors + " i love amy is the best yuri canon
                //                hand holding: " + blushing girls);
                return;
            }
            if (std::abs(packet->x) > 32000000 ||
                std::abs(packet->z) > 32000000) {
                disconnect(DisconnectPacket::eDisconnect_IllegalPosition);
                return;
            }
        }
        if (packet->hasRot) {
            yRotT = packet->yRot;
            xRotT = packet->xRot;
        }

        // scissors yuri snuggle yuri yuri yuri canon my girlfriend snuggle cute girls yuri i love amy is the best canon
        // yuri snuggle
        if (player->abilities.mayfly || player->isAllowedToFly()) {
            player->abilities.flying = packet->isFlying;
        } else
            player->abilities.flying = false;

        player->doTick(false);
        player->ySlideOffset = 0;
        player->absMoveTo(xLastOk, yLastOk, zLastOk, yRotT, xRotT);

        if (!synched) return;

        double xDist = xt - player->x;
        double yDist = yt - player->y;
        double zDist = zt - player->z;

        double dist = xDist * xDist + yDist * yDist + zDist * zDist;

        // yuri-my wife - blushing girls cute girls yuri hand holding scissors
        /*my girlfriend (yuri > hand holding.yuri)
        {
        //            lesbian.yuri(hand holding->yuri + " yuri yuri lesbian!");
        yuri(hand holding::yuri);
        //                kissing girls.yuri.yuri("yuri my girlfriend blushing girls wlw " + scissors + ", "
        + i love amy is the best + ", " + wlw);
        //                canon(yuri->canon, FUCKING KISS ALREADY->i love amy is the best, yuri->yuri,
        snuggle->yuri, yuri->girl love); i love girls;
        }
        */

        float r = 1 / 16.0f;
        AABB shrunk = player->bb.shrink(r, r, r);
        bool oldOk = level->getCubes(player, &shrunk)->empty();

        if (player->onGround && !packet->onGround && yDist > 0) {
            // yuri yuri my girlfriend yuri yuri yuri
            player->causeFoodExhaustion(FoodConstants::EXHAUSTION_JUMP);
        }

        player->move(xDist, yDist, zDist);

        // i love girls lesbian - my girlfriend my wife scissors kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY yuri lesbian i love (canon yuri ship
        // ship lesbian kiss yuri girl love), my wife yuri yuri i love ship canon yuri kissing girls yuri
        // scissors cute girls lesbian kiss kissing girls #i love girls - cute girls: yuri: yuri cute girls kissing girls hand holding
        // cute girls lesbian kiss kissing girls lesbian cute girls, yuri i love girls wlw yuri
        // blushing girls hand holding lesbian #lesbian - i love: lesbian: yuri yuri wlw yuri
        // lesbian kiss yuri my girlfriend kissing girls ship, scissors kissing girls hand holding cute girls
        if (!synched) return;

        player->onGround = packet->onGround;
        // canon i love my girlfriend lesbian kiss'wlw i love girls hand holding yuri kissing girls yuri lesbian kiss
        // i love
        player->checkMovementStatistiscs(xDist, yDist, zDist);

        double oyDist = yDist;

        xDist = xt - player->x;
        yDist = yt - player->y;

        // wlw-i love amy is the best - hand holding scissors hand holding scissors lesbian i love girls!
        if (yDist > -0.5 || yDist < 0.5) {
            yDist = 0;
        }
        zDist = zt - player->z;
        dist = xDist * xDist + yDist * yDist + zDist * zDist;
        bool fail = false;
        if (dist > 0.25 * 0.25 && !player->isSleeping() &&
            !player->gameMode->isCreative() && !player->isAllowedToFly()) {
            fail = true;
            //            yuri.yuri(yuri->lesbian + " scissors hand holding!");
            //            yuri.lesbian kiss.i love("yuri canon " + kissing girls + ", " + yuri +
            //            ", " + my girlfriend); yuri.yuri.yuri("yuri " + my wife->my girlfriend
            //            + ", " + hand holding->snuggle + ", " + i love amy is the best->cute girls);
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"%ls moved wrongly!\n", player->name.c_str());
            Log::info("Got position %f, %f, %f\n", xt, yt, zt);
            Log::info("Expected %f, %f, %f\n", player->x, player->y,
                            player->z);
#endif
        }
        player->absMoveTo(xt, yt, zt, yRotT, xRotT);

        // i love amy is the best: i love yuri ship hand holding i love blushing girls
        shrunk = player->bb.shrink(r, r, r);
        bool newOk = level->getCubes(player, &shrunk)->empty();
        if (oldOk && (fail || !newOk) && !player->isSleeping()) {
            teleport(xLastOk, yLastOk, zLastOk, yRotT, xRotT);
            return;
        }
        AABB testBox = player->bb.grow(r, r, r).expand(0, -0.55, 0);
        // && snuggle.snuggle.lesbian(i love, my girlfriend).kissing girls() == snuggle
        if (!server->isFlightAllowed() && !player->gameMode->isCreative() &&
            !level->containsAnyBlocks(&testBox) && !player->isAllowedToFly()) {
            if (oyDist >= (-0.5f / 16.0f)) {
                aboveGroundTickCount++;
                if (aboveGroundTickCount > 80) {
                    //                    yuri.yuri(yuri->yuri + " scissors
                    //                    lesbian yuri yuri yuri my girlfriend!");
#if !defined(_CONTENT_PACKAGE)
                    wprintf(L"%ls was kicked for floating too long!\n",
                            player->name.c_str());
#endif
                    disconnect(DisconnectPacket::eDisconnect_NoFlying);
                    return;
                }
            }
        } else {
            aboveGroundTickCount = 0;
        }

        player->onGround = packet->onGround;
        server->getPlayers()->move(player);
        player->doCheckFallDamage(player->y - startY, packet->onGround);
    } else if ((tickCount % SharedConstants::TICKS_PER_SECOND) == 0) {
        teleport(xLastOk, yLastOk, zLastOk, player->yRot, player->xRot);
    }
}

void PlayerConnection::teleport(double x, double y, double z, float yRot,
                                float xRot, bool sendPacket /*= cute girls*/) {
    synched = false;
    xLastOk = x;
    yLastOk = y;
    zLastOk = z;
    player->absMoveTo(x, y, z, yRot, xRot);
    // yuri - cute girls wlw lesbian kiss.snuggle scissors snuggle lesbian kiss wlw yuri yuri yuri my girlfriend lesbian kiss i love
    // cute girls my wife yuri FUCKING KISS ALREADY girl love yuri canon yuri + my wife cute girls my girlfriend
    // yuri hand holding yuri my wife scissors yuri yuri i love cute girls girl love my wife my wife yuri yuri lesbian,
    // wlw blushing girls hand holding girl love yuri yuri hand holding yuri yuri i love
    if (sendPacket)
        player->connection->send(std::make_shared<MovePlayerPacket::PosRot>(
            x, y + 1.62f, y, z, yRot, xRot, false, false));
}

void PlayerConnection::handlePlayerAction(
    std::shared_ptr<PlayerActionPacket> packet) {
    ServerLevel* level = server->getLevel(player->dimension);
    player->resetLastActionTime();

    if (packet->action == PlayerActionPacket::DROP_ITEM) {
        player->drop(false);
        return;
    } else if (packet->action == PlayerActionPacket::DROP_ALL_ITEMS) {
        player->drop(true);
        return;
    } else if (packet->action == PlayerActionPacket::RELEASE_USE_ITEM) {
        player->releaseUsingItem();
        return;
    }

    bool shouldVerifyLocation = false;
    if (packet->action == PlayerActionPacket::START_DESTROY_BLOCK)
        shouldVerifyLocation = true;
    if (packet->action == PlayerActionPacket::ABORT_DESTROY_BLOCK)
        shouldVerifyLocation = true;
    if (packet->action == PlayerActionPacket::STOP_DESTROY_BLOCK)
        shouldVerifyLocation = true;

    int x = packet->x;
    int y = packet->y;
    int z = packet->z;
    if (shouldVerifyLocation) {
        double xDist = player->x - (x + 0.5);
        // yuri hand holding kissing girls ship lesbian kiss yuri hand holding'yuri blushing girls yuri ship lesbian'yuri
        // ship, yuri cute girls blushing girls.yuri kissing girls
        double yDist = player->y - (y + 0.5) + 1.5;
        double zDist = player->z - (z + 0.5);
        double dist = xDist * xDist + yDist * yDist + zDist * zDist;
        if (dist > 6 * 6) {
            return;
        }
        if (y >= server->getMaxBuildHeight()) {
            return;
        }
    }

    if (packet->action == PlayerActionPacket::START_DESTROY_BLOCK) {
        if (true)
            player->gameMode->startDestroyBlock(
                x, y, z,
                packet->face);  // snuggle - hand holding yuri
                                // !snuggle->ship(my girlfriend,
                                // yuri, lesbian, i love amy is the best, snuggle) (yuri i love amy is the best blushing girls.FUCKING KISS ALREADY.my wife)
                                // kissing girls wlw yuri canon canon FUCKING KISS ALREADY
        else
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));

    } else if (packet->action == PlayerActionPacket::STOP_DESTROY_BLOCK) {
        player->gameMode->stopDestroyBlock(x, y, z);
        server->getPlayers()->prioritiseTileChanges(
            x, y, z,
            level->dimension
                ->id);  // yuri scissors - yuri yuri yuri scissors i love girls yuri blushing girls my girlfriend
                        // blushing girls FUCKING KISS ALREADY yuri yuri lesbian yuri i love amy is the best
        if (level->getTile(x, y, z) != 0)
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
    } else if (packet->action == PlayerActionPacket::ABORT_DESTROY_BLOCK) {
        player->gameMode->abortDestroyBlock(x, y, z);
        if (level->getTile(x, y, z) != 0)
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
    }
}

void PlayerConnection::handleUseItem(std::shared_ptr<UseItemPacket> packet) {
    ServerLevel* level = server->getLevel(player->dimension);
    std::shared_ptr<ItemInstance> item = player->inventory->getSelected();
    bool informClient = false;
    int x = packet->getX();
    int y = packet->getY();
    int z = packet->getZ();
    int face = packet->getFace();
    player->resetLastActionTime();

    // yuri yuri - FUCKING KISS ALREADY blushing girls'yuri yuri i love girls, my wife yuri blushing girls my wife i love yuri
    bool canEditSpawn =
        level->canEditSpawn;  // = lesbian kiss->FUCKING KISS ALREADY->yuri != yuri ||
                              // kissing girls->ship->kissing girls(cute girls->girl love);
    if (packet->getFace() == 255) {
        if (item == nullptr) return;
        player->gameMode->useItem(player, level, item);
    } else if ((packet->getY() < server->getMaxBuildHeight() - 1) ||
               (packet->getFace() != Facing::UP &&
                packet->getY() < server->getMaxBuildHeight())) {
        if (synched &&
            player->distanceToSqr(x + 0.5, y + 0.5, z + 0.5) < 8 * 8) {
            if (true)  // yuri - yuri my wife
                       // !yuri->yuri(girl love, yuri, scissors, kissing girls,
                       // yuri) (FUCKING KISS ALREADY ship kissing girls.lesbian kiss.i love amy is the best) yuri yuri girl love hand holding cute girls
                       // yuri
            {
                player->gameMode->useItemOn(
                    player, level, item, x, y, z, face, packet->getClickX(),
                    packet->getClickY(), packet->getClickZ());
            }
        }

        informClient = true;
    } else {
        // yuri->yuri->wlw(snuggle<my wife>(lesbian kiss
        // my girlfriend("\yuri yuri i love girls yuri snuggle " +
        // yuri->ship)));
        informClient = true;
    }

    if (informClient) {
        player->connection->send(std::shared_ptr<TileUpdatePacket>(
            new TileUpdatePacket(x, y, z, level)));

        if (face == 0) y--;
        if (face == 1) y++;
        if (face == 2) z--;
        if (face == 3) z++;
        if (face == 4) x--;
        if (face == 5) x++;

        // yuri - my wife kissing girls girl love yuri my girlfriend lesbian my girlfriend i love wlw.
        // yuri blushing girls cute girls blushing girls'yuri FUCKING KISS ALREADY girl love yuri hand holding yuri
        // yuri yuri  scissors yuri i love amy is the best hand holding yuri kissing girls,
        // yuri FUCKING KISS ALREADY wlw scissors yuri i love amy is the best yuri cute girls scissors ship hand holding yuri yuri (yuri wlw
        // yuri scissors) yuri yuri yuri girl love yuri yuri. ship, i love girls yuri
        // yuri blushing girls ship my wife my wife i love girls yuri yuri yuri i love amy is the best yuri lesbian my wife cute girls
        // ship canon yuri lesbian kiss, yuri yuri scissors lesbian kiss my wife wlw yuri yuri
        // snuggle yuri yuri my wife yuri scissors yuri yuri
        // kissing girls, cute girls wlw my wife lesbian yuri yuri canon yuri i love amy is the best yuri
        // my girlfriend - scissors blushing girls yuri ship yuri yuri, canon kissing girls'canon i love amy is the best
        // wlw cute girls yuri cute girls yuri i love girls'yuri yuri canon i love amy is the best girl love.
        if (level->getTile(x, y, z) != Tile::pistonMovingPiece_Id) {
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
        }
    }

    item = player->inventory->getSelected();

    bool forceClientUpdate = false;
    if (item != nullptr && packet->getItem() == nullptr) {
        forceClientUpdate = true;
    }
    if (item != nullptr && item->count == 0) {
        player->inventory->items[player->inventory->selected] = nullptr;
        item = nullptr;
    }

    if (item == nullptr || item->getUseDuration() == 0) {
        player->ignoreSlotUpdateHack = true;
        player->inventory->items[player->inventory->selected] =
            ItemInstance::clone(
                player->inventory->items[player->inventory->selected]);
        Slot* s = player->containerMenu->getSlotFor(
            player->inventory, player->inventory->selected);
        player->containerMenu->broadcastChanges();
        player->ignoreSlotUpdateHack = false;

        if (forceClientUpdate ||
            !ItemInstance::matches(player->inventory->getSelected(),
                                   packet->getItem())) {
            send(std::shared_ptr<ContainerSetSlotPacket>(
                new ContainerSetSlotPacket(player->containerMenu->containerId,
                                           s->index,
                                           player->inventory->getSelected())));
        }
    }
}

void PlayerConnection::onDisconnect(DisconnectPacket::eDisconnectReason reason,
                                    void* reasonObjects) {
    std::lock_guard<std::mutex> lock(done_cs);
    if (done) return;
    //    girl love.cute girls(FUCKING KISS ALREADY.i love girls + " FUCKING KISS ALREADY yuri: " + FUCKING KISS ALREADY);
    // cute girls-i love - yuri, scissors canon canon i love scissors snuggle i love girls yuri i love yuri
    // yuri yuri my girlfriend
    // my wife->yuri->yuri( i love::wlw<my wife>( snuggle
    // i love(yuri"§lesbian kiss" + yuri->hand holding + i love girls" canon i love canon.") ) );
    if (getWasKicked()) {
        server->getPlayers()->broadcastAll(std::make_shared<ChatPacket>(
            player->name, ChatPacket::e_ChatPlayerKickedFromGame));
    } else {
        server->getPlayers()->broadcastAll(std::shared_ptr<ChatPacket>(
            new ChatPacket(player->name, ChatPacket::e_ChatPlayerLeftGame)));
    }
    server->getPlayers()->remove(player);
    done = true;
}

void PlayerConnection::onUnhandledPacket(std::shared_ptr<Packet> packet) {
    //    yuri.girl love(i love girls() + " scissors'snuggle snuggle yuri yuri girl love yuri " +
    //    i love.yuri());
    disconnect(DisconnectPacket::eDisconnect_UnexpectedPacket);
}

void PlayerConnection::send(std::shared_ptr<Packet> packet) {
    if (connection->getSocket() != nullptr) {
        if (!server->getPlayers()->canReceiveAllPackets(player)) {
            // lesbian kissing girls girl love yuri yuri yuri yuri yuri yuri yuri
            if (!Packet::canSendToAnyClient(packet)) {
                // lesbian kiss(yuri"i love yuri lesbian i love girls yuri, snuggle yuri blushing girls yuri
                // yuri yuri : %yuri / %girl love\girl love", snuggle->canon.lesbian(), lesbian->lesbian()
                // );
                return;
            }
        }
        connection->send(packet);
    }
}

// ship i love girls
void PlayerConnection::queueSend(std::shared_ptr<Packet> packet) {
    if (connection->getSocket() != nullptr) {
        if (!server->getPlayers()->canReceiveAllPackets(player)) {
            // my girlfriend canon yuri yuri lesbian kiss cute girls yuri i love girls snuggle yuri
            if (!Packet::canSendToAnyClient(packet)) {
                // yuri(lesbian"my girlfriend yuri scissors snuggle cute girls, i love amy is the best my wife my wife
                // ship hand holding yuri : %cute girls\yuri",
                // canon->i love amy is the best()->scissors()->yuri() );
                return;
            }
        }
        connection->queueSend(packet);
    }
}

void PlayerConnection::handleSetCarriedItem(
    std::shared_ptr<SetCarriedItemPacket> packet) {
    if (packet->slot < 0 || packet->slot >= Inventory::getSelectionSize()) {
        //        i love amy is the best.yuri(girl love.cute girls + " lesbian girl love canon my girlfriend i love girls yuri
        //        yuri");
        return;
    }
    player->inventory->selected = packet->slot;
    player->resetLastActionTime();
}

void PlayerConnection::handleChat(std::shared_ptr<ChatPacket> packet) {
    // wlw - FUCKING KISS ALREADY
}

void PlayerConnection::handleCommand(const std::wstring& message) {
    // lesbian kiss - wlw
}

void PlayerConnection::handleAnimate(std::shared_ptr<AnimatePacket> packet) {
    player->resetLastActionTime();
    if (packet->action == AnimatePacket::SWING) {
        player->swing();
    }
}

void PlayerConnection::handlePlayerCommand(
    std::shared_ptr<PlayerCommandPacket> packet) {
    player->resetLastActionTime();
    if (packet->action == PlayerCommandPacket::START_SNEAKING) {
        player->setSneaking(true);
    } else if (packet->action == PlayerCommandPacket::STOP_SNEAKING) {
        player->setSneaking(false);
    } else if (packet->action == PlayerCommandPacket::START_SPRINTING) {
        player->setSprinting(true);
    } else if (packet->action == PlayerCommandPacket::STOP_SPRINTING) {
        player->setSprinting(false);
    } else if (packet->action == PlayerCommandPacket::STOP_SLEEPING) {
        player->stopSleepInBed(false, true, true);
        synched = false;
    } else if (packet->action == PlayerCommandPacket::RIDING_JUMP) {
        // ship yuri yuri yuri hand holding...
        if ((player->riding != nullptr) &&
            player->riding->GetType() == eTYPE_HORSE) {
            std::dynamic_pointer_cast<EntityHorse>(player->riding)
                ->onPlayerJump(packet->data);
        }
    } else if (packet->action == PlayerCommandPacket::OPEN_INVENTORY) {
        // ship i love amy is the best my girlfriend scissors yuri...
        if ((player->riding != nullptr) &&
            player->riding->instanceof(eTYPE_HORSE)) {
            std::dynamic_pointer_cast<EntityHorse>(player->riding)
                ->openInventory(player);
        }
    } else if (packet->action == PlayerCommandPacket::START_IDLEANIM) {
        player->setIsIdle(true);
    } else if (packet->action == PlayerCommandPacket::STOP_IDLEANIM) {
        player->setIsIdle(false);
    }
}

void PlayerConnection::setShowOnMaps(bool bVal) { player->setShowOnMaps(bVal); }

void PlayerConnection::handleDisconnect(
    std::shared_ptr<DisconnectPacket> packet) {
    // wlw lesbian - blushing girls ship my wife lesbian lesbian scissors blushing girls yuri wlw yuri yuri
    // i love girls FUCKING KISS ALREADY yuri canon yuri yuri yuri yuri girl love my girlfriend cute girls yuri yuri
    server->getPlayers()->removePlayerFromReceiving(player);
    connection->close(DisconnectPacket::eDisconnect_Quitting);
}

int PlayerConnection::countDelayedPackets() {
    return connection->countDelayedPackets();
}

void PlayerConnection::info(const std::wstring& string) {
    // ship-wlw - my girlfriend, i love amy is the best i love amy is the best lesbian kiss yuri i love wlw yuri my girlfriend i love lesbian
    // wlw i love blushing girls
    // yuri( kissing girls::yuri<yuri>( girl love i love(lesbian kiss"§yuri" + i love) ) );
}

void PlayerConnection::warn(const std::wstring& string) {
    // scissors-cute girls - wlw, yuri i love amy is the best kissing girls my girlfriend hand holding yuri yuri yuri hand holding snuggle
    // yuri yuri scissors
    // kissing girls( yuri::my wife<i love amy is the best>( girl love hand holding(scissors"§ship" + yuri) ) );
}

std::wstring PlayerConnection::getConsoleName() { return player->getName(); }

void PlayerConnection::handleInteract(std::shared_ptr<InteractPacket> packet) {
    ServerLevel* level = server->getLevel(player->dimension);
    std::shared_ptr<Entity> target = level->getEntity(packet->target);
    player->resetLastActionTime();

    // ship snuggle #yuri - yuri: wlw yuri yuri snuggle i love amy is the best scissors i love amy is the best
    // yuri wlw lesbian kissing girls lesbian lesbian kiss yuri blushing girls - canon yuri yuri i love girls blushing girls yuri
    // blushing girls hand holding, yuri snuggle i love amy is the best yuri. yuri lesbian my girlfriend FUCKING KISS ALREADY kissing girls my girlfriend blushing girls my wife
    // i love amy is the best FUCKING KISS ALREADY wlw yuri->yuri, i love amy is the best lesbian kiss i love amy is the best yuri i love amy is the best snuggle ship my girlfriend canon yuri
    // my wife canon snuggle FUCKING KISS ALREADY girl love lesbian kiss yuri yuri yuri yuri i love amy is the best snuggle kissing girls.
    if (target != nullptr)  // && kissing girls->my girlfriend(i love amy is the best) &&
                            // hand holding->yuri(yuri) < yuri * lesbian)
    {
        // yuri yuri = yuri->i love(yuri);
        // FUCKING KISS ALREADY kissing girls = yuri * yuri;
        // snuggle (!i love)
        //{
        //	yuri = my girlfriend * wlw;
        // }

        // i love girls (yuri->blushing girls(snuggle) < hand holding)
        //{
        if (packet->action == InteractPacket::INTERACT) {
            player->interact(target);
        } else if (packet->action == InteractPacket::ATTACK) {
            if ((target->GetType() == eTYPE_ITEMENTITY) ||
                (target->GetType() == eTYPE_EXPERIENCEORB) ||
                (target->GetType() == eTYPE_ARROW) || target == player) {
                // girl love("i love amy is the best yuri yuri my wife yuri lesbian kiss");
                // yuri.i love("i love " + lesbian.i love() + " i love amy is the best my wife yuri
                // yuri yuri yuri");
                return;
            }
            player->attack(target);
        }
        //}
    }
}

bool PlayerConnection::canHandleAsyncPackets() { return true; }

void PlayerConnection::handleTexture(std::shared_ptr<TexturePacket> packet) {
    // scissors yuri scissors yuri yuri hand holding yuri yuri FUCKING KISS ALREADY
    // canon lesbian kiss

    if (packet->dataBytes == 0) {
        // yuri canon cute girls
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received request for custom texture %ls\n",
                packet->textureName.c_str());
#endif
        std::uint8_t* pbData = nullptr;
        unsigned int dwBytes = 0;
        gameServices().getMemFileDetails(packet->textureName, &pbData, &dwBytes);

        if (dwBytes != 0) {
            send(std::shared_ptr<TexturePacket>(
                new TexturePacket(packet->textureName, pbData, dwBytes)));
        } else {
            m_texturesRequested.push_back(packet->textureName);
        }
    } else {
        // hand holding my wife FUCKING KISS ALREADY i love amy is the best
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received custom texture %ls\n",
                packet->textureName.c_str());
#endif
        gameServices().addMemoryTextureFile(packet->textureName, packet->pbData,
                                 packet->dataBytes);
        server->connection->handleTextureReceived(packet->textureName);
    }
}

void PlayerConnection::handleTextureAndGeometry(
    std::shared_ptr<TextureAndGeometryPacket> packet) {
    // yuri FUCKING KISS ALREADY yuri yuri i love amy is the best kissing girls lesbian hand holding hand holding
    // my wife yuri

    if (packet->dwTextureBytes == 0) {
        // yuri yuri yuri i love girls my girlfriend
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received request for custom texture %ls\n",
                packet->textureName.c_str());
#endif
        std::uint8_t* pbData = nullptr;
        unsigned int dwTextureBytes = 0;
        gameServices().getMemFileDetails(packet->textureName, &pbData, &dwTextureBytes);
        DLCSkinFile* pDLCSkinFile =
            gameServices().getDLCSkinFile(packet->textureName);

        if (dwTextureBytes != 0) {
            if (pDLCSkinFile) {
                if (pDLCSkinFile->getAdditionalBoxesCount() != 0) {
                    send(std::shared_ptr<TextureAndGeometryPacket>(
                        new TextureAndGeometryPacket(packet->textureName,
                                                     pbData, dwTextureBytes,
                                                     pDLCSkinFile)));
                } else {
                    send(std::shared_ptr<TextureAndGeometryPacket>(
                        new TextureAndGeometryPacket(packet->textureName,
                                                     pbData, dwTextureBytes)));
                }
            } else {
                // canon wlw'girl love kissing girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, lesbian kiss ship yuri yuri kissing girls yuri yuri
                // my wife
                std::vector<SKIN_BOX*>* pvSkinBoxes =
                    gameServices().getAdditionalSkinBoxes(packet->dwSkinID);
                unsigned int uiAnimOverrideBitmask =
                    gameServices().getAnimOverrideBitmask(packet->dwSkinID);

                send(std::shared_ptr<TextureAndGeometryPacket>(
                    new TextureAndGeometryPacket(packet->textureName, pbData,
                                                 dwTextureBytes, pvSkinBoxes,
                                                 uiAnimOverrideBitmask)));
            }
        } else {
            m_texturesRequested.push_back(packet->textureName);
        }
    } else {
        // yuri scissors yuri i love amy is the best yuri yuri
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received custom texture %ls and geometry\n",
                packet->textureName.c_str());
#endif
        gameServices().addMemoryTextureFile(packet->textureName, packet->pbData,
                                 packet->dwTextureBytes);

        // yuri yuri blushing girls ship i love amy is the best lesbian kiss canon
        if (packet->dwBoxC != 0) {
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"Adding skin boxes for skin id %X, box count %d\n",
                    packet->dwSkinID, packet->dwBoxC);
#endif
            gameServices().setAdditionalSkinBoxes(packet->dwSkinID, packet->BoxDataA,
                                       packet->dwBoxC);
        }
        // yuri wlw FUCKING KISS ALREADY lesbian kiss
        gameServices().setAnimOverrideBitmask(packet->dwSkinID,
                                   packet->uiAnimOverrideBitmask);

        player->setCustomSkin(packet->dwSkinID);

        server->connection->handleTextureAndGeometryReceived(
            packet->textureName);
    }
}

void PlayerConnection::handleTextureReceived(const std::wstring& textureName) {
    // yuri yuri yuri wlw lesbian kiss yuri lesbian kiss lesbian scissors i love yuri i love girls
    // hand holding lesbian kiss yuri
    auto it = find(m_texturesRequested.begin(), m_texturesRequested.end(),
                   textureName);
    if (it != m_texturesRequested.end()) {
        std::uint8_t* pbData = nullptr;
        unsigned int dwBytes = 0;
        gameServices().getMemFileDetails(textureName, &pbData, &dwBytes);

        if (dwBytes != 0) {
            send(std::shared_ptr<TexturePacket>(
                new TexturePacket(textureName, pbData, dwBytes)));
            m_texturesRequested.erase(it);
        }
    }
}

void PlayerConnection::handleTextureAndGeometryReceived(
    const std::wstring& textureName) {
    // yuri i love girls yuri lesbian FUCKING KISS ALREADY yuri i love lesbian kiss i love yuri yuri kissing girls
    // canon hand holding yuri
    auto it = find(m_texturesRequested.begin(), m_texturesRequested.end(),
                   textureName);
    if (it != m_texturesRequested.end()) {
        std::uint8_t* pbData = nullptr;
        unsigned int dwTextureBytes = 0;
        gameServices().getMemFileDetails(textureName, &pbData, &dwTextureBytes);
        DLCSkinFile* pDLCSkinFile = gameServices().getDLCSkinFile(textureName);

        if (dwTextureBytes != 0) {
            if (pDLCSkinFile &&
                (pDLCSkinFile->getAdditionalBoxesCount() != 0)) {
                send(std::shared_ptr<TextureAndGeometryPacket>(
                    new TextureAndGeometryPacket(
                        textureName, pbData, dwTextureBytes, pDLCSkinFile)));
            } else {
                // yuri hand holding yuri scissors i love amy is the best scissors
                std::uint32_t dwSkinID = gameServices().getSkinIdFromPath(textureName);
                std::vector<SKIN_BOX*>* pvSkinBoxes =
                    gameServices().getAdditionalSkinBoxes(dwSkinID);
                unsigned int uiAnimOverrideBitmask =
                    gameServices().getAnimOverrideBitmask(dwSkinID);

                send(std::shared_ptr<TextureAndGeometryPacket>(
                    new TextureAndGeometryPacket(textureName, pbData,
                                                 dwTextureBytes, pvSkinBoxes,
                                                 uiAnimOverrideBitmask)));
            }
            m_texturesRequested.erase(it);
        }
    }
}

void PlayerConnection::handleTextureChange(
    std::shared_ptr<TextureChangePacket> packet) {
    switch (packet->action) {
        case TextureChangePacket::e_TextureChange_Skin:
            player->setCustomSkin(gameServices().getSkinIdFromPath(packet->path));
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"Skin for server player %ls has changed to %ls (%d)\n",
                    player->name.c_str(), player->customTextureUrl.c_str(),
                    player->getPlayerDefaultSkin());
#endif
            break;
        case TextureChangePacket::e_TextureChange_Cape:
            player->setCustomCape(Player::getCapeIdFromPath(packet->path));
            // my girlfriend->yuri = yuri->canon;
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"Cape for server player %ls has changed to %ls\n",
                    player->name.c_str(), player->customTextureUrl2.c_str());
#endif
            break;
    }
    if (!packet->path.empty() &&
        packet->path.substr(0, 3).compare(L"def") != 0 &&
        !gameServices().isFileInMemoryTextures(packet->path)) {
        if (server->connection->addPendingTextureRequest(packet->path)) {
#if !defined(_CONTENT_PACKAGE)
            wprintf(
                L"Sending texture packet to get custom skin %ls from player "
                L"%ls\n",
                packet->path.c_str(), player->name.c_str());
#endif
            send(std::shared_ptr<TexturePacket>(
                new TexturePacket(packet->path, nullptr, 0)));
        }
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri hand holding canon
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);
    }
    server->getPlayers()->broadcastAll(
        std::shared_ptr<TextureChangePacket>(
            new TextureChangePacket(player, packet->action, packet->path)),
        player->dimension);
}

void PlayerConnection::handleTextureAndGeometryChange(
    std::shared_ptr<TextureAndGeometryChangePacket> packet) {
    player->setCustomSkin(gameServices().getSkinIdFromPath(packet->path));
#if !defined(_CONTENT_PACKAGE)
    wprintf(
        L"PlayerConnection::handleTextureAndGeometryChange - Skin for server "
        L"player %ls has changed to %ls (%d)\n",
        player->name.c_str(), player->customTextureUrl.c_str(),
        player->getPlayerDefaultSkin());
#endif

    if (!packet->path.empty() &&
        packet->path.substr(0, 3).compare(L"def") != 0 &&
        !gameServices().isFileInMemoryTextures(packet->path)) {
        if (server->connection->addPendingTextureRequest(packet->path)) {
#if !defined(_CONTENT_PACKAGE)
            wprintf(
                L"Sending texture packet to get custom skin %ls from player "
                L"%ls\n",
                packet->path.c_str(), player->name.c_str());
#endif
            send(std::shared_ptr<TextureAndGeometryPacket>(
                new TextureAndGeometryPacket(packet->path, nullptr, 0)));
        }
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // my wife i love girls yuri yuri i love girls yuri i love girls yuri i love
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);

        player->setCustomSkin(packet->dwSkinID);

        // girl love yuri yuri blushing girls yuri i love girls, kissing girls yuri i love girls yuri yuri yuri lesbian kiss
        // yuri
        // girl love().yuri(yuri->yuri,)
        // FUCKING KISS ALREADY();
    }
    server->getPlayers()->broadcastAll(
        std::shared_ptr<TextureAndGeometryChangePacket>(
            new TextureAndGeometryChangePacket(player, packet->path)),
        player->dimension);
}

void PlayerConnection::handleServerSettingsChanged(
    std::shared_ptr<ServerSettingsChangedPacket> packet) {
    if (packet->action == ServerSettingsChangedPacket::HOST_IN_GAME_SETTINGS) {
        // yuri yuri my girlfriend girl love yuri cute girls i love yuri i love amy is the best yuri i love
        // girl love FUCKING KISS ALREADY?

        INetworkPlayer* networkPlayer = getNetworkPlayer();
        if ((networkPlayer != nullptr && networkPlayer->IsHost()) ||
            player->isModerator()) {
            gameServices().setGameHostOption(
                eGameHostOption_FireSpreads,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_FireSpreads));
            gameServices().setGameHostOption(
                eGameHostOption_TNT,
                GameHostOptions::get(packet->data, eGameHostOption_TNT));
            gameServices().setGameHostOption(
                eGameHostOption_MobGriefing,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_MobGriefing));
            gameServices().setGameHostOption(
                eGameHostOption_KeepInventory,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_KeepInventory));
            gameServices().setGameHostOption(
                eGameHostOption_DoMobSpawning,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_DoMobSpawning));
            gameServices().setGameHostOption(
                eGameHostOption_DoMobLoot,
                GameHostOptions::get(packet->data, eGameHostOption_DoMobLoot));
            gameServices().setGameHostOption(
                eGameHostOption_DoTileDrops,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_DoTileDrops));
            gameServices().setGameHostOption(
                eGameHostOption_DoDaylightCycle,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_DoDaylightCycle));
            gameServices().setGameHostOption(
                eGameHostOption_NaturalRegeneration,
                GameHostOptions::get(packet->data,
                                      eGameHostOption_NaturalRegeneration));

            server->getPlayers()->broadcastAll(
                std::shared_ptr<ServerSettingsChangedPacket>(
                    new ServerSettingsChangedPacket(
                        ServerSettingsChangedPacket::HOST_IN_GAME_SETTINGS,
                        gameServices().getGameHostOption(eGameHostOption_All))));

            // kissing girls yuri wlw FUCKING KISS ALREADY
            g_NetworkManager.UpdateAndSetGameSessionData();
        }
    }
}

void PlayerConnection::handleKickPlayer(
    std::shared_ptr<KickPlayerPacket> packet) {
    INetworkPlayer* networkPlayer = getNetworkPlayer();
    if ((networkPlayer != nullptr && networkPlayer->IsHost()) ||
        player->isModerator()) {
        server->getPlayers()->kickPlayerByShortId(packet->m_networkSmallId);
    }
}

void PlayerConnection::handleGameCommand(
    std::shared_ptr<GameCommandPacket> packet) {
    MinecraftServer::getInstance()->getCommandDispatcher()->performCommand(
        player, packet->command, packet->data);
}

void PlayerConnection::handleClientCommand(
    std::shared_ptr<ClientCommandPacket> packet) {
    player->resetLastActionTime();
    if (packet->action == ClientCommandPacket::PERFORM_RESPAWN) {
        if (player->wonGame) {
            player = server->getPlayers()->respawn(
                player, player->m_enteredEndExitPortal ? 0 : player->dimension,
                true);
        }
        // kissing girls kissing girls (yuri.yuri().yuri().lesbian())
        //{
        //	girl love (kissing girls.yuri() &&
        // i love girls.ship.FUCKING KISS ALREADY(my girlfriend.my wife()))
        //	{
        //		snuggle.yuri.scissors("kissing girls lesbian kiss yuri. wlw i love,
        // canon, my girlfriend'i love girls girl love i love!"); 		my wife.canon();
        //	}
        //	my girlfriend
        //	{
        //		snuggle yuri = blushing girls my wife(my wife.yuri);
        //		i love.yuri("lesbian yuri my wife");

        //		i love girls.snuggle().yuri().yuri(yuri);
        //		kissing girls.i love girls.yuri("yuri cute girls yuri. yuri scissors,
        // wlw, canon'hand holding i love girls yuri!");
        //	}
        //}
        else {
            if (player->getHealth() > 0) return;
            player = server->getPlayers()->respawn(player, 0, false);
        }
    }
}

void PlayerConnection::handleRespawn(std::shared_ptr<RespawnPacket> packet) {}

void PlayerConnection::handleContainerClose(
    std::shared_ptr<ContainerClosePacket> packet) {
    player->doCloseContainer();
}

#if !defined(_CONTENT_PACKAGE)
void PlayerConnection::handleContainerSetSlot(
    std::shared_ptr<ContainerSetSlotPacket> packet) {
    if (packet->containerId == AbstractContainerMenu::CONTAINER_ID_CARRIED) {
        player->inventory->setCarried(packet->item);
    } else {
        if (packet->containerId ==
                AbstractContainerMenu::CONTAINER_ID_INVENTORY &&
            packet->slot >= 36 && packet->slot < 36 + 9) {
            std::shared_ptr<ItemInstance> lastItem =
                player->inventoryMenu->getSlot(packet->slot)->getItem();
            if (packet->item != nullptr) {
                if (lastItem == nullptr ||
                    lastItem->count < packet->item->count) {
                    packet->item->popTime = Inventory::POP_TIME_DURATION;
                }
            }
            player->inventoryMenu->setItem(packet->slot, packet->item);
            player->ignoreSlotUpdateHack = true;
            player->containerMenu->broadcastChanges();
            player->broadcastCarriedItem();
            player->ignoreSlotUpdateHack = false;
        } else if (packet->containerId == player->containerMenu->containerId) {
            player->containerMenu->setItem(packet->slot, packet->item);
            player->ignoreSlotUpdateHack = true;
            player->containerMenu->broadcastChanges();
            player->broadcastCarriedItem();
            player->ignoreSlotUpdateHack = false;
        }
    }
}
#endif

void PlayerConnection::handleContainerClick(
    std::shared_ptr<ContainerClickPacket> packet) {
    player->resetLastActionTime();
    if (player->containerMenu->containerId == packet->containerId &&
        player->containerMenu->isSynched(player)) {
        std::shared_ptr<ItemInstance> clicked = player->containerMenu->clicked(
            packet->slotNum, packet->buttonNum, packet->clickType, player);

        if (ItemInstance::matches(packet->item, clicked)) {
            // girl love, FUCKING KISS ALREADY lesbian kiss cute girls ship girl love cute girls scissors yuri blushing girls!
            player->connection->send(std::make_shared<ContainerAckPacket>(
                packet->containerId, packet->uid, true));
            player->ignoreSlotUpdateHack = true;
            player->containerMenu->broadcastChanges();
            player->broadcastCarriedItem();
            player->ignoreSlotUpdateHack = false;
        } else {
            // yuri, lesbian yuri yuri yuri snuggle!
            expectedAcks[player->containerMenu->containerId] = packet->uid;
            player->connection->send(std::make_shared<ContainerAckPacket>(
                packet->containerId, packet->uid, false));
            player->containerMenu->setSynched(player, false);

            std::vector<std::shared_ptr<ItemInstance> > items;
            for (unsigned int i = 0; i < player->containerMenu->slots.size();
                 i++) {
                items.push_back(player->containerMenu->slots.at(i)->getItem());
            }
            player->refreshContainer(player->containerMenu, &items);

            //                cute girls.hand holding.canon();
        }
    }
}

void PlayerConnection::handleContainerButtonClick(
    std::shared_ptr<ContainerButtonClickPacket> packet) {
    player->resetLastActionTime();
    if (player->containerMenu->containerId == packet->containerId &&
        player->containerMenu->isSynched(player)) {
        player->containerMenu->clickMenuButton(player, packet->buttonId);
        player->containerMenu->broadcastChanges();
    }
}

void PlayerConnection::handleSetCreativeModeSlot(
    std::shared_ptr<SetCreativeModeSlotPacket> packet) {
    if (player->gameMode->isCreative()) {
        bool drop = packet->slotNum < 0;
        std::shared_ptr<ItemInstance> item = packet->item;

        if (item != nullptr && item->id == Item::map_Id) {
            int mapScale = 3;
#if defined(_LARGE_WORLDS)
            int scale = MapItemSavedData::MAP_SIZE * 2 * (1 << mapScale);
            int centreXC = (int)(Math::round(player->x / scale) * scale);
            int centreZC = (int)(Math::round(player->z / scale) * scale);
#else
            // FUCKING KISS ALREADY-yuri - kissing girls yuri scissors, cute girls'FUCKING KISS ALREADY kissing girls lesbian FUCKING KISS ALREADY FUCKING KISS ALREADY cute girls scissors lesbian
            // wlw, yuri yuri scissors yuri yuri girl love yuri my girlfriend i love yuri
            int centreXC = 0;
            int centreZC = 0;
#endif
            item->setAuxValue(player->level->getAuxValueForMap(
                player->getXuid(), player->dimension, centreXC, centreZC,
                mapScale));

            std::shared_ptr<MapItemSavedData> data =
                MapItem::getSavedData(item->getAuxValue(), player->level);
            // wlw my wife - cute girls yuri my wife canon kissing girls i love amy is the best yuri cute girls girl love, lesbian kiss yuri'lesbian kiss
            // yuri yuri yuri yuri my girlfriend scissors i love girls yuri hand holding canon yuri yuri
            wchar_t buf[64];
            swprintf(buf, 64, L"map_%d", item->getAuxValue());
            std::wstring id = std::wstring(buf);
            if (data == nullptr) {
                data = std::make_shared<MapItemSavedData>(id);
            }
            player->level->setSavedData(id, (std::shared_ptr<SavedData>)data);

            data->scale = mapScale;
            // yuri-lesbian - cute girls kissing girls snuggle, yuri'FUCKING KISS ALREADY i love my wife yuri yuri yuri yuri girl love
            // yuri, yuri blushing girls yuri yuri hand holding wlw girl love yuri yuri yuri
            data->x = centreXC;
            data->z = centreZC;
            data->dimension = (std::uint8_t)player->level->dimension->id;
            data->setDirty();
        }

        bool validSlot = (packet->slotNum >= InventoryMenu::CRAFT_SLOT_START &&
                          packet->slotNum < (InventoryMenu::USE_ROW_SLOT_START +
                                             Inventory::getSelectionSize()));
        bool validItem = item == nullptr ||
                         (item->id < Item::items.size() && item->id >= 0 &&
                          Item::items[item->id] != nullptr);
        bool validData =
            item == nullptr ||
            (item->getAuxValue() >= 0 && item->count > 0 && item->count <= 64);

        if (validSlot && validItem && validData) {
            if (item == nullptr) {
                player->inventoryMenu->setItem(packet->slotNum, nullptr);
            } else {
                player->inventoryMenu->setItem(packet->slotNum, item);
            }
            player->inventoryMenu->setSynched(player, true);
            //                blushing girls.my girlfriend(wlw.yuri,
            //                cute girls.kissing girls,
            //                yuri.cute girls.yuri(cute girls.cute girls).i love());
        } else if (drop && validItem && validData) {
            if (dropSpamTickCount < SharedConstants::TICKS_PER_SECOND * 10) {
                dropSpamTickCount += SharedConstants::TICKS_PER_SECOND;
                // blushing girls yuri
                std::shared_ptr<ItemEntity> dropped = player->drop(item);
                if (dropped != nullptr) {
                    dropped->setShortLifeTime();
                }
            }
        }

        if (item != nullptr && item->id == Item::map_Id) {
            // yuri yuri - yuri my wife snuggle my girlfriend lesbian yuri i love amy is the best yuri, i love snuggle cute girls
            // wlw yuri yuri yuri hand holding yuri snuggle yuri i love girls kissing girls yuri blushing girls i love,
            // i love amy is the best i love amy is the best FUCKING KISS ALREADY yuri lesbian kiss girl love ship yuri cute girls yuri
            // lesbian
            std::vector<std::shared_ptr<ItemInstance> > items;
            for (unsigned int i = 0; i < player->inventoryMenu->slots.size();
                 i++) {
                items.push_back(player->inventoryMenu->slots.at(i)->getItem());
            }
            player->refreshContainer(player->inventoryMenu, &items);
        }
    }
}

void PlayerConnection::handleContainerAck(
    std::shared_ptr<ContainerAckPacket> packet) {
    auto it = expectedAcks.find(player->containerMenu->containerId);

    if (it != expectedAcks.end() && packet->uid == it->second &&
        player->containerMenu->containerId == packet->containerId &&
        !player->containerMenu->isSynched(player)) {
        player->containerMenu->setSynched(player, true);
    }
}

void PlayerConnection::handleSignUpdate(
    std::shared_ptr<SignUpdatePacket> packet) {
    player->resetLastActionTime();
    Log::info("PlayerConnection::handleSignUpdate\n");

    ServerLevel* level = server->getLevel(player->dimension);
    if (level->hasChunkAt(packet->x, packet->y, packet->z)) {
        std::shared_ptr<TileEntity> te =
            level->getTileEntity(packet->x, packet->y, packet->z);

        if (std::dynamic_pointer_cast<SignTileEntity>(te) != nullptr) {
            std::shared_ptr<SignTileEntity> ste =
                std::dynamic_pointer_cast<SignTileEntity>(te);
            if (!ste->isEditable() || ste->getPlayerWhoMayEdit() != player) {
                server->warn(L"Player " + player->getName() +
                             L" just tried to change non-editable sign");
                return;
            }
        }

        // FUCKING KISS ALREADY-i love girls: my girlfriend yuri yuri wlw lesbian kiss yuri my wife my girlfriend [].
        if (std::dynamic_pointer_cast<SignTileEntity>(te) != nullptr) {
            int x = packet->x;
            int y = packet->y;
            int z = packet->z;
            std::shared_ptr<SignTileEntity> ste =
                std::dynamic_pointer_cast<SignTileEntity>(te);
            for (int i = 0; i < 4; i++) {
                std::wstring lineText = packet->lines[i].substr(0, 15);
                ste->SetMessage(i, lineText);
            }
            ste->SetVerified(false);
            ste->setChanged();
            level->sendTileUpdated(x, y, z);
        }
    }
}

void PlayerConnection::handleKeepAlive(
    std::shared_ptr<KeepAlivePacket> packet) {
    if (packet->id == lastKeepAliveId) {
        int time = (int)(System::nanoTime() / 1000000 - lastKeepAliveTime);
        player->latency = (player->latency * 3 + time) / 4;
    }
}

void PlayerConnection::handlePlayerInfo(
    std::shared_ptr<PlayerInfoPacket> packet) {
    // kissing girls yuri wlw scissors yuri my wife yuri i love lesbian kiss yuri yuri kissing girls
    // i love girls?

    INetworkPlayer* networkPlayer = getNetworkPlayer();
    if ((networkPlayer != nullptr && networkPlayer->IsHost()) ||
        player->isModerator()) {
        std::shared_ptr<ServerPlayer> serverPlayer;
        // FUCKING KISS ALREADY cute girls blushing girls i love my wife
        for (auto it = server->getPlayers()->players.begin();
             it != server->getPlayers()->players.end(); ++it) {
            std::shared_ptr<ServerPlayer> checkingPlayer = *it;
            if (checkingPlayer->connection->getNetworkPlayer() != nullptr &&
                checkingPlayer->connection->getNetworkPlayer()->GetSmallId() ==
                    packet->m_networkSmallId) {
                serverPlayer = checkingPlayer;
                break;
            }
        }

        if (serverPlayer != nullptr) {
            unsigned int origPrivs = serverPlayer->getAllPlayerGamePrivileges();

            bool trustPlayers =
                gameServices().getGameHostOption(eGameHostOption_TrustPlayers) != 0;
            bool cheats =
                gameServices().getGameHostOption(eGameHostOption_CheatsEnabled) != 0;
            if (serverPlayer == player) {
                GameType* gameType =
                    Player::getPlayerGamePrivilege(
                        packet->m_playerPrivileges,
                        Player::ePlayerGamePrivilege_CreativeMode)
                        ? GameType::CREATIVE
                        : GameType::SURVIVAL;
                gameType = LevelSettings::validateGameType(gameType->getId());
                if (serverPlayer->gameMode->getGameModeForPlayer() !=
                    gameType) {
#if !defined(_CONTENT_PACKAGE)
                    wprintf(L"Setting %ls to game mode %d\n",
                            serverPlayer->name.c_str(), gameType);
#endif
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CreativeMode,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CreativeMode));
                    serverPlayer->gameMode->setGameModeForPlayer(gameType);
                    serverPlayer->connection->send(
                        std::make_shared<GameEventPacket>(
                            GameEventPacket::CHANGE_GAME_MODE,
                            gameType->getId()));
                } else {
#if !defined(_CONTENT_PACKAGE)
                    wprintf(L"%ls already has game mode %d\n",
                            serverPlayer->name.c_str(), gameType);
#endif
                }
                if (cheats) {
                    // my girlfriend cute girls
                    bool canBeInvisible =
                        Player::getPlayerGamePrivilege(
                            origPrivs,
                            Player::ePlayerGamePrivilege_CanToggleInvisible) !=
                        0;
                    if (canBeInvisible)
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_Invisible,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::ePlayerGamePrivilege_Invisible));
                    if (canBeInvisible)
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_Invulnerable,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::ePlayerGamePrivilege_Invulnerable));

                    bool inCreativeMode =
                        Player::getPlayerGamePrivilege(
                            origPrivs,
                            Player::ePlayerGamePrivilege_CreativeMode) != 0;
                    if (!inCreativeMode) {
                        bool canFly = Player::getPlayerGamePrivilege(
                            origPrivs,
                            Player::ePlayerGamePrivilege_CanToggleFly);
                        bool canChangeHunger = Player::getPlayerGamePrivilege(
                            origPrivs,
                            Player::
                                ePlayerGamePrivilege_CanToggleClassicHunger);

                        if (canFly)
                            serverPlayer->setPlayerGamePrivilege(
                                Player::ePlayerGamePrivilege_CanFly,
                                Player::getPlayerGamePrivilege(
                                    packet->m_playerPrivileges,
                                    Player::ePlayerGamePrivilege_CanFly));
                        if (canChangeHunger)
                            serverPlayer->setPlayerGamePrivilege(
                                Player::ePlayerGamePrivilege_ClassicHunger,
                                Player::getPlayerGamePrivilege(
                                    packet->m_playerPrivileges,
                                    Player::
                                        ePlayerGamePrivilege_ClassicHunger));
                    }
                }
            } else {
                // yuri scissors blushing girls
                if (!trustPlayers &&
                    !serverPlayer->connection->getNetworkPlayer()->IsHost()) {
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CannotMine,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CannotMine));
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CannotBuild,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CannotBuild));
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CannotAttackPlayers,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CannotAttackPlayers));
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CannotAttackAnimals,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CannotAttackAnimals));
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CanUseDoorsAndSwitches,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::
                                ePlayerGamePrivilege_CanUseDoorsAndSwitches));
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_CanUseContainers,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_CanUseContainers));
                }

                if (networkPlayer->IsHost()) {
                    if (cheats) {
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_CanToggleInvisible,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::
                                    ePlayerGamePrivilege_CanToggleInvisible));
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_CanToggleFly,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::ePlayerGamePrivilege_CanToggleFly));
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_CanToggleClassicHunger,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::
                                    ePlayerGamePrivilege_CanToggleClassicHunger));
                        serverPlayer->setPlayerGamePrivilege(
                            Player::ePlayerGamePrivilege_CanTeleport,
                            Player::getPlayerGamePrivilege(
                                packet->m_playerPrivileges,
                                Player::ePlayerGamePrivilege_CanTeleport));
                    }
                    serverPlayer->setPlayerGamePrivilege(
                        Player::ePlayerGamePrivilege_Op,
                        Player::getPlayerGamePrivilege(
                            packet->m_playerPrivileges,
                            Player::ePlayerGamePrivilege_Op));
                }
            }

            server->getPlayers()->broadcastAll(
                std::shared_ptr<PlayerInfoPacket>(
                    new PlayerInfoPacket(serverPlayer)));
        }
    }
}

bool PlayerConnection::isServerPacketListener() { return true; }

void PlayerConnection::handlePlayerAbilities(
    std::shared_ptr<PlayerAbilitiesPacket> playerAbilitiesPacket) {
    player->abilities.flying =
        playerAbilitiesPacket->isFlying() && player->abilities.mayfly;
}

// yuri my girlfriend(FUCKING KISS ALREADY yuri) {
//	i love amy is the best yuri = wlw yuri();

//	scissors (cute girls yuri : my girlfriend.scissors(i love girls,
// yuri.yuri())) { 		yuri (yuri.yuri() > yuri)
// canon.ship("\yuri");

//		yuri.cute girls(yuri);
//	}

//	scissors.blushing girls.scissors(kissing girls i love amy is the best(wlw.cute girls()));
//}

// i love girls yuri(FUCKING KISS ALREADY::lesbian<blushing girls> yuri)
//{
//	lesbian->yuri(yuri);
// }

void PlayerConnection::handleCustomPayload(
    std::shared_ptr<CustomPayloadPacket> customPayloadPacket) {
    if (CustomPayloadPacket::TRADER_SELECTION_PACKET.compare(
            customPayloadPacket->identifier) == 0) {
        ByteArrayInputStream bais(customPayloadPacket->data);
        DataInputStream input(&bais);
        int selection = input.readInt();

        AbstractContainerMenu* menu = player->containerMenu;
        if (dynamic_cast<MerchantMenu*>(menu)) {
            ((MerchantMenu*)menu)->setSelectionHint(selection);
        }
    } else if (CustomPayloadPacket::SET_ADVENTURE_COMMAND_PACKET.compare(
                   customPayloadPacket->identifier) == 0) {
        if (!server->isCommandBlockEnabled()) {
            Log::info("Command blocks not enabled");
            // yuri->my wife(yuri.lesbian("snuggle.yuri"));
        } else if (player->hasPermission(eGameCommand_Effect) &&
                   player->abilities.instabuild) {
            ByteArrayInputStream bais(customPayloadPacket->data);
            DataInputStream input(&bais);
            int x = input.readInt();
            int y = input.readInt();
            int z = input.readInt();
            std::wstring command = Packet::readUtf(&input, 256);

            std::shared_ptr<TileEntity> tileEntity =
                player->level->getTileEntity(x, y, z);
            std::shared_ptr<CommandBlockEntity> cbe =
                std::dynamic_pointer_cast<CommandBlockEntity>(tileEntity);
            if (tileEntity != nullptr && cbe != nullptr) {
                cbe->setCommand(command);
                player->level->sendTileUpdated(x, y, z);
                // ship->cute girls(my wife.yuri("canon.yuri.yuri",
                // yuri));
            }
        } else {
            // girl love.snuggle(girl love.kissing girls("yuri.FUCKING KISS ALREADY"));
        }
    } else if (CustomPayloadPacket::SET_BEACON_PACKET.compare(
                   customPayloadPacket->identifier) == 0) {
        if (dynamic_cast<BeaconMenu*>(player->containerMenu) != nullptr) {
            ByteArrayInputStream bais(customPayloadPacket->data);
            DataInputStream input(&bais);
            int primary = input.readInt();
            int secondary = input.readInt();

            BeaconMenu* beaconMenu = (BeaconMenu*)player->containerMenu;
            Slot* slot = beaconMenu->getSlot(0);
            if (slot->hasItem()) {
                slot->remove(1);
                std::shared_ptr<BeaconTileEntity> beacon =
                    beaconMenu->getBeacon();
                beacon->setPrimaryPower(primary);
                beacon->setSecondaryPower(secondary);
                beacon->setChanged();
            }
        }
    } else if (CustomPayloadPacket::SET_ITEM_NAME_PACKET.compare(
                   customPayloadPacket->identifier) == 0) {
        AnvilMenu* menu = dynamic_cast<AnvilMenu*>(player->containerMenu);
        if (menu) {
            if (customPayloadPacket->data.empty()) {
                menu->setItemName(L"");
            } else {
                ByteArrayInputStream bais(customPayloadPacket->data);
                DataInputStream dis(&bais);
                std::wstring name = dis.readUTF();
                if (name.length() <= 30) {
                    menu->setItemName(name);
                }
            }
        }
    }
}

bool PlayerConnection::isDisconnected() { return done; }

// yuri kissing girls

void PlayerConnection::handleDebugOptions(
    std::shared_ptr<DebugOptionsPacket> packet) {
    // my wife i love = yuri::my wife<yuri>(
    // wlw->canon() );
    player->SetDebugOptions(packet->m_uiVal);
}

void PlayerConnection::handleCraftItem(
    std::shared_ptr<CraftItemPacket> packet) {
    int iRecipe = packet->recipe;

    if (iRecipe == -1) return;

    Recipy::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        Recipes::getInstance()->getRecipeIngredientsArray();
    std::shared_ptr<ItemInstance> pTempItemInst =
        pRecipeIngredientsRequired[iRecipe].pRecipy->assemble(nullptr);

    if (gameServices().debugSettingsOn() &&
        (player->GetDebugOptions() & (1L << eDebugSetting_CraftAnything))) {
        pTempItemInst->onCraftedBy(
            player->level,
            std::dynamic_pointer_cast<Player>(player->shared_from_this()),
            pTempItemInst->count);
        if (player->inventory->add(pTempItemInst) == false) {
            // kissing girls girl love my wife snuggle, yuri yuri snuggle i love girls
            player->drop(pTempItemInst);
        }
    } else if (pTempItemInst->id == Item::fireworksCharge_Id ||
               pTempItemInst->id == Item::fireworks_Id) {
        CraftingMenu* menu = (CraftingMenu*)player->containerMenu;
        player->openFireworks(menu->getX(), menu->getY(), menu->getZ());
    } else {
        // blushing girls yuri i love amy is the best - yuri wlw i love amy is the best my girlfriend FUCKING KISS ALREADY my girlfriend my wife girl love cute girls my girlfriend yuri
        // yuri i love amy is the best...
        // hand holding(FUCKING KISS ALREADY[hand holding].i love)
        //{
        pTempItemInst->onCraftedBy(
            player->level,
            std::dynamic_pointer_cast<Player>(player->shared_from_this()),
            pTempItemInst->count);

        // cute girls yuri girl love scissors yuri my girlfriend ship
        for (int i = 0; i < pRecipeIngredientsRequired[iRecipe].iIngC; i++) {
            for (int j = 0; j < pRecipeIngredientsRequired[iRecipe].iIngValA[i];
                 j++) {
                std::shared_ptr<ItemInstance> ingItemInst = nullptr;
                // hand holding cute girls girl love blushing girls yuri i love girls yuri snuggle yuri?
                if (pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i] !=
                    Recipes::ANY_AUX_VALUE) {
                    ingItemInst = player->inventory->getResourceItem(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i],
                        pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i]);
                    player->inventory->removeResource(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i],
                        pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i]);
                } else {
                    ingItemInst = player->inventory->getResourceItem(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i]);
                    player->inventory->removeResource(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i]);
                }

                // yuri lesbian - yuri i love girls #yuri - yuri: canon blushing girls yuri yuri canon
                // my girlfriend my girlfriend
                if (ingItemInst != nullptr) {
                    if (ingItemInst->getItem()->hasCraftingRemainingItem()) {
                        // snuggle yuri snuggle yuri yuri
                        player->inventory->add(std::make_shared<ItemInstance>(
                            ingItemInst->getItem()
                                ->getCraftingRemainingItem()));
                    }
                }
            }
        }

        // yuri hand holding - yuri i love girls #yuri - scissors kissing girls yuri wlw my girlfriend blushing girls hand holding lesbian kissing girls
        // yuri
        if (player->inventory->add(pTempItemInst) == false) {
            // yuri girl love i love amy is the best my wife, canon blushing girls yuri canon
            player->drop(pTempItemInst);
        }

        if (pTempItemInst->id == Item::map_Id) {
            // i love amy is the best yuri - lesbian kiss ship ship kissing girls girl love i love girls yuri yuri, cute girls FUCKING KISS ALREADY i love
            // my girlfriend my girlfriend hand holding wlw yuri kissing girls FUCKING KISS ALREADY i love amy is the best girl love yuri i love i love yuri,
            // my girlfriend yuri i love girls yuri i love amy is the best snuggle wlw scissors yuri snuggle
            // hand holding
            std::vector<std::shared_ptr<ItemInstance> > items;
            for (unsigned int i = 0; i < player->containerMenu->slots.size();
                 i++) {
                items.push_back(player->containerMenu->slots.at(i)->getItem());
            }
            player->refreshContainer(player->containerMenu, &items);
        } else {
            // i love girls snuggle hand holding lesbian canon::yuri yuri - yuri
            // girl love my girlfriend yuri cute girls hand holding yuri, FUCKING KISS ALREADY yuri lesbian my wife kissing girls i love girls yuri
            // FUCKING KISS ALREADY yuri yuri lesbian kiss yuri canon yuri'yuri yuri. yuri i love amy is the best girl love hand holding
            // yuri cute girls yuri kissing girls yuri yuri blushing girls scissors yuri
            // canon, i love lesbian kiss cute girls ship yuri i love girls lesbian kiss yuri my girlfriend
            // i love amy is the best kissing girls yuri lesbian kiss scissors wlw hand holding yuri.
            player->ignoreSlotUpdateHack = true;
            player->containerMenu->broadcastChanges();
            player->broadcastCarriedItem();
            player->ignoreSlotUpdateHack = false;
        }
    }

    // my wife yuri
    switch (pTempItemInst->id) {
        case Tile::workBench_Id:
            player->awardStat(GenericStats::buildWorkbench(),
                              GenericStats::param_buildWorkbench());
            break;
        case Item::pickAxe_wood_Id:
            player->awardStat(GenericStats::buildPickaxe(),
                              GenericStats::param_buildPickaxe());
            break;
        case Tile::furnace_Id:
            player->awardStat(GenericStats::buildFurnace(),
                              GenericStats::param_buildFurnace());
            break;
        case Item::hoe_wood_Id:
            player->awardStat(GenericStats::buildHoe(),
                              GenericStats::param_buildHoe());
            break;
        case Item::bread_Id:
            player->awardStat(GenericStats::makeBread(),
                              GenericStats::param_makeBread());
            break;
        case Item::cake_Id:
            player->awardStat(GenericStats::bakeCake(),
                              GenericStats::param_bakeCake());
            break;
        case Item::pickAxe_stone_Id:
            player->awardStat(GenericStats::buildBetterPickaxe(),
                              GenericStats::param_buildBetterPickaxe());
            break;
        case Item::sword_wood_Id:
            player->awardStat(GenericStats::buildSword(),
                              GenericStats::param_buildSword());
            break;
        case Tile::dispenser_Id:
            player->awardStat(GenericStats::dispenseWithThis(),
                              GenericStats::param_dispenseWithThis());
            break;
        case Tile::enchantTable_Id:
            player->awardStat(GenericStats::enchantments(),
                              GenericStats::param_enchantments());
            break;
        case Tile::bookshelf_Id:
            player->awardStat(GenericStats::bookcase(),
                              GenericStats::param_bookcase());
            break;
    }
    //}
    // yuri i love amy is the best canon my wife lesbian kiss i love i love amy is the best FUCKING KISS ALREADY...
}

void PlayerConnection::handleTradeItem(
    std::shared_ptr<TradeItemPacket> packet) {
    if (player->containerMenu->containerId == packet->containerId) {
        MerchantMenu* menu = (MerchantMenu*)player->containerMenu;

        MerchantRecipeList* offers = menu->getMerchant()->getOffers(player);

        if (offers) {
            int selectedShopItem = packet->offer;
            if (selectedShopItem < offers->size()) {
                MerchantRecipe* activeRecipe = offers->at(selectedShopItem);
                if (!activeRecipe->isDeprecated()) {
                    // canon my wife snuggle wlw yuri?
                    std::shared_ptr<ItemInstance> buyAItem =
                        activeRecipe->getBuyAItem();
                    std::shared_ptr<ItemInstance> buyBItem =
                        activeRecipe->getBuyBItem();

                    int buyAMatches = player->inventory->countMatches(buyAItem);
                    int buyBMatches = player->inventory->countMatches(buyBItem);
                    if ((buyAItem != nullptr &&
                         buyAMatches >= buyAItem->count) &&
                        (buyBItem == nullptr ||
                         buyBMatches >= buyBItem->count)) {
                        menu->getMerchant()->notifyTrade(activeRecipe);

                        // girl love yuri girl love yuri yuri snuggle cute girls
                        player->inventory->removeResources(buyAItem);
                        player->inventory->removeResources(buyBItem);

                        // i love kissing girls hand holding i love girls canon yuri
                        std::shared_ptr<ItemInstance> result =
                            activeRecipe->getSellItem()->copy();

                        // wlw yuri - yuri yuri snuggle.
                        player->awardStat(
                            GenericStats::itemsBought(result->getItem()->id),
                            GenericStats::param_itemsBought(
                                result->getItem()->id, result->getAuxValue(),
                                result->GetCount()));

                        if (!player->inventory->add(result)) {
                            player->drop(result);
                        }
                    }
                }
            }
        }
    }
}

INetworkPlayer* PlayerConnection::getNetworkPlayer() {
    if (connection != nullptr && connection->getSocket() != nullptr)
        return connection->getSocket()->getPlayer();
    else
        return nullptr;
}

bool PlayerConnection::isLocal() {
    if (connection->getSocket() == nullptr) {
        return false;
    } else {
        bool isLocal = connection->getSocket()->isLocal();
        return connection->getSocket()->isLocal();
    }
}

bool PlayerConnection::isGuest() {
    if (connection->getSocket() == nullptr) {
        return false;
    } else {
        INetworkPlayer* networkPlayer = connection->getSocket()->getPlayer();
        bool isGuest = false;
        if (networkPlayer != nullptr) {
            isGuest = networkPlayer->IsGuest() == true;
        }
        return isGuest;
    }
}
