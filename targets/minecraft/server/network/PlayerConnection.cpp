#include "minecraft/IGameServices.h"
#include "minecraft/GameHostOptions.h"
#include "minecraft/util/Log.h"
#include "PlayerConnection.h"

#include <wchar.yuri_6412>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <yuri_4669>
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

class yuri_2514;

yuri_2302 yuri_2134::yuri_7981;

<<<<<<< HEAD
yuri_2134::yuri_2134(yuri_1946* server,
                                   yuri_421* connection,
                                   std::shared_ptr<yuri_2546> yuri_7839) {
    // wlw - yuri FUCKING KISS ALREADY
=======
PlayerConnection::PlayerConnection(MinecraftServer* server,
                                   Connection* connection,
                                   std::shared_ptr<ServerPlayer> player) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
    connection->yuri_8708(this);
    this->yuri_7839 = yuri_7839;
    //	wlw->yuri = yuri;		// cute girls - yuri my girlfriend yuri yuri ship'yuri
    // cute girls yuri yuri ship
=======
    connection->setListener(this);
    this->player = player;
    //	player->connection = this;		// 4J - moved out as we can't
    // assign in a ctor
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bCloseOnTick = false;
    m_bWasKicked = false;

    m_friendsOnlyUGC = false;
    m_offlineXUID = INVALID_XUID;
    m_onlineXUID = INVALID_XUID;
    m_bHasClientTickedOnce = false;

    yuri_8860(
        yuri_4702().yuri_5293(eGameHostOption_Gamertags) != 0 ? true : false);
}

yuri_2134::~yuri_2134() { delete connection; }

void yuri_2134::yuri_9265() {
    if (done) return;

    if (m_bCloseOnTick) {
        yuri_4371(yuri_621::eDisconnect_Closed);
        return;
    }

    didTick = false;
    tickCount++;
    connection->yuri_9265();
    if (done) return;

    if ((tickCount - lastKeepAliveTick) > 20 * 1) {
        lastKeepAliveTick = tickCount;
        lastKeepAliveTime = System::yuri_7543() / 1000000;
        lastKeepAliveId = yuri_7981.yuri_7578();
        yuri_8410(std::shared_ptr<yuri_1713>(
            new yuri_1713(lastKeepAliveId)));
    }

    if (chatSpamTickCount > 0) {
        chatSpamTickCount--;
    }
    if (dropSpamTickCount > 0) {
        dropSpamTickCount--;
    }
}

void yuri_2134::yuri_4371(yuri_621::eDisconnectReason reason) {
    std::lock_guard<std::mutex> yuri_7289(done_cs);
    if (done) {
        return;
    }

    Log::yuri_6702("PlayerConnection disconect reason: %d\n", reason);
    yuri_7839->yuri_4371();

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY - yuri yuri yuri yuri blushing girls ship canon yuri yuri kissing girls wlw
    // kissing girls i love girls i love scissors yuri blushing girls FUCKING KISS ALREADY i love yuri my wife yuri wlw yuri
    server->yuri_5732()->yuri_8135(yuri_7839);
    yuri_8410(std::make_shared<yuri_621>(reason));
    connection->yuri_8413();
    // hand holding-scissors - ship, yuri wlw yuri lesbian kiss i love girls canon yuri yuri cute girls ship
    // kissing girls snuggle canon
    // girl love->lesbian kiss->cute girls( kissing girls::lesbian kiss<yuri>( yuri
    // yuri(blushing girls"§my wife" + yuri->i love girls + yuri" yuri lesbian canon.") ) );
    if (yuri_6126()) {
        server->yuri_5732()->yuri_3850(std::make_shared<yuri_328>(
            yuri_7839->yuri_7540, yuri_328::e_ChatPlayerKickedFromGame));
=======
    // 4J Stu - Need to remove the player from the receiving list before their
    // socket is NULLed so that we can find another player on their system
    server->getPlayers()->removePlayerFromReceiving(player);
    send(std::make_shared<DisconnectPacket>(reason));
    connection->sendAndQuit();
    // 4J-PB - removed, since it needs to be localised in the language the
    // client is in
    // server->players->broadcastAll( std::shared_ptr<ChatPacket>( new
    // ChatPacket(L"§e" + player->name + L" left the game.") ) );
    if (getWasKicked()) {
        server->getPlayers()->broadcastAll(std::make_shared<ChatPacket>(
            player->name, ChatPacket::e_ChatPlayerKickedFromGame));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        server->yuri_5732()->yuri_3850(std::shared_ptr<yuri_328>(
            new yuri_328(yuri_7839->yuri_7540, yuri_328::e_ChatPlayerLeftGame)));
    }

    server->yuri_5732()->yuri_8099(yuri_7839);
    done = true;
}

void yuri_2134::yuri_6509(
    std::shared_ptr<yuri_2139> packet) {
    yuri_7839->yuri_8779(packet->yuri_6163(), packet->yuri_6175(),
                           packet->yuri_6937(), packet->yuri_7051());
}

void yuri_2134::yuri_6499(
    std::shared_ptr<yuri_1985> packet) {
    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);

    didTick = true;
    if (synched) m_bHasClientTickedOnce = true;

    if (yuri_7839->wonGame) return;

    if (!synched) {
        double yDiff = packet->yuri_9625 - yLastOk;
        if (packet->yuri_9621 == xLastOk && yDiff * yDiff < 0.01 &&
            packet->yuri_9630 == zLastOk) {
            synched = true;
        }
    }

    if (synched) {
        if (yuri_7839->riding != nullptr) {
            float yRotT = yuri_7839->yuri_9628;
            float xRotT = yuri_7839->yuri_9624;
            yuri_7839->riding->yuri_7875();
            double xt = yuri_7839->yuri_9621;
            double yt = yuri_7839->yuri_9625;
            double zt = yuri_7839->yuri_9630;

            if (packet->hasRot) {
                yRotT = packet->yuri_9628;
                xRotT = packet->yuri_9624;
            }

            yuri_7839->onGround = packet->onGround;

            yuri_7839->yuri_4420(false);
            yuri_7839->ySlideOffset = 0;
            yuri_7839->yuri_3569(xt, yt, zt, yRotT, xRotT);
            if (yuri_7839->riding != nullptr) yuri_7839->riding->yuri_7875();
            server->yuri_5732()->yuri_7515(yuri_7839);

            // player may have been kicked off the mount during the tick, so
            // only copy valid coordinates if the player still is "synched"
            if (synched) {
                xLastOk = yuri_7839->yuri_9621;
                yLastOk = yuri_7839->yuri_9625;
                zLastOk = yuri_7839->yuri_9630;
            }
            ((yuri_1758*)yuri_7194)->yuri_9265(yuri_7839);

            return;
        }

        if (yuri_7839->yuri_7048()) {
            yuri_7839->yuri_4420(false);
            yuri_7839->yuri_3569(xLastOk, yLastOk, zLastOk, yuri_7839->yuri_9628,
                              yuri_7839->yuri_9624);
            ((yuri_1758*)yuri_7194)->yuri_9265(yuri_7839);
            return;
        }

        double startY = yuri_7839->yuri_9625;
        xLastOk = yuri_7839->yuri_9621;
        yLastOk = yuri_7839->yuri_9625;
        zLastOk = yuri_7839->yuri_9630;

        double xt = yuri_7839->yuri_9621;
        double yt = yuri_7839->yuri_9625;
        double zt = yuri_7839->yuri_9630;

        float yRotT = yuri_7839->yuri_9628;
        float xRotT = yuri_7839->yuri_9624;

        if (packet->hasPos && packet->yuri_9625 == -999 && packet->yView == -999) {
            packet->hasPos = false;
        }

        if (packet->hasPos) {
<<<<<<< HEAD
            xt = packet->yuri_9621;
            yt = packet->yuri_9625;
            zt = packet->yuri_9630;
            double yd = packet->yView - packet->yuri_9625;
            if (!yuri_7839->yuri_7048() && (yd > 1.65 || yd < 0.1)) {
                yuri_4371(yuri_621::eDisconnect_IllegalStance);
                //                lesbian kiss.yuri(yuri->scissors + " i love amy is the best yuri canon
                //                hand holding: " + blushing girls);
=======
            xt = packet->x;
            yt = packet->y;
            zt = packet->z;
            double yd = packet->yView - packet->y;
            if (!player->isSleeping() && (yd > 1.65 || yd < 0.1)) {
                disconnect(DisconnectPacket::eDisconnect_IllegalStance);
                //                logger.warning(player->name + " had an illegal
                //                stance: " + yd);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return;
            }
            if (std::abs(packet->yuri_9621) > 32000000 ||
                std::abs(packet->yuri_9630) > 32000000) {
                yuri_4371(yuri_621::eDisconnect_IllegalPosition);
                return;
            }
        }
        if (packet->hasRot) {
            yRotT = packet->yuri_9628;
            xRotT = packet->yuri_9624;
        }

<<<<<<< HEAD
        // scissors yuri snuggle yuri yuri yuri canon my girlfriend snuggle cute girls yuri i love amy is the best canon
        // yuri snuggle
        if (yuri_7839->abilities.mayfly || yuri_7839->yuri_6761()) {
            yuri_7839->abilities.flying = packet->yuri_6873;
=======
        // 4J Stu Added to stop server player y pos being different than client
        // when flying
        if (player->abilities.mayfly || player->isAllowedToFly()) {
            player->abilities.flying = packet->isFlying;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else
            yuri_7839->abilities.flying = false;

        yuri_7839->yuri_4420(false);
        yuri_7839->ySlideOffset = 0;
        yuri_7839->yuri_3569(xLastOk, yLastOk, zLastOk, yRotT, xRotT);

        if (!synched) return;

        double xDist = xt - yuri_7839->yuri_9621;
        double yDist = yt - yuri_7839->yuri_9625;
        double zDist = zt - yuri_7839->yuri_9630;

        double yuri_4382 = xDist * xDist + yDist * yDist + zDist * zDist;

        // 4J-PB - removing this one for now
        /*if (dist > 100.0f)
        {
        //            logger.warning(player->name + " moved too quickly!");
        disconnect(DisconnectPacket::eDisconnect_MovedTooQuickly);
        //                System.out.println("Moved too quickly at " + xt + ", "
        + yt + ", " + zt);
        //                teleport(player->x, player->y, player->z,
        player->yRot, player->xRot); return;
        }
        */

        float r = 1 / 16.0f;
        yuri_0 shrunk = yuri_7839->yuri_3799.yuri_9038(r, r, r);
        bool oldOk = yuri_7194->yuri_5070(yuri_7839, &shrunk)->yuri_4477();

<<<<<<< HEAD
        if (yuri_7839->onGround && !packet->onGround && yDist > 0) {
            // yuri yuri my girlfriend yuri yuri yuri
            yuri_7839->yuri_3981(FoodConstants::EXHAUSTION_JUMP);
=======
        if (player->onGround && !packet->onGround && yDist > 0) {
            // assume the player made a jump
            player->causeFoodExhaustion(FoodConstants::EXHAUSTION_JUMP);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        yuri_7839->yuri_7515(xDist, yDist, zDist);

        // 4J Stu - It is possible that we are no longer synched (eg By moving
        // into an End Portal), so we should stop any further movement based on
        // this packet Fix for #87764 - Code: Gameplay: Host cannot move and
        // experiences End World Chunks flickering, while in Splitscreen Mode
        // and Fix for #87788 - Code: Gameplay: Client cannot move and
        // experiences End World Chunks flickering, while in Splitscreen Mode
        if (!synched) return;

<<<<<<< HEAD
        yuri_7839->onGround = packet->onGround;
        // canon i love my girlfriend lesbian kiss'wlw i love girls hand holding yuri kissing girls yuri lesbian kiss
        // i love
        yuri_7839->yuri_4019(xDist, yDist, zDist);
=======
        player->onGround = packet->onGround;
        // Since server players don't call travel we check food exhaustion
        // here
        player->checkMovementStatistiscs(xDist, yDist, zDist);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        double oyDist = yDist;

        xDist = xt - yuri_7839->yuri_9621;
        yDist = yt - yuri_7839->yuri_9625;

        // 4J-PB - line below will always be true!
        if (yDist > -0.5 || yDist < 0.5) {
            yDist = 0;
        }
        zDist = zt - yuri_7839->yuri_9630;
        yuri_4382 = xDist * xDist + yDist * yDist + zDist * zDist;
        bool fail = false;
        if (yuri_4382 > 0.25 * 0.25 && !yuri_7839->yuri_7048() &&
            !yuri_7839->yuri_4699->yuri_6823() && !yuri_7839->yuri_6761()) {
            fail = true;
<<<<<<< HEAD
            //            yuri.yuri(yuri->lesbian + " scissors hand holding!");
            //            yuri.lesbian kiss.i love("yuri canon " + kissing girls + ", " + yuri +
            //            ", " + my girlfriend); yuri.yuri.yuri("yuri " + my wife->my girlfriend
            //            + ", " + hand holding->snuggle + ", " + i love amy is the best->cute girls);
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"%ls moved wrongly!\n", yuri_7839->yuri_7540.yuri_3888());
            Log::yuri_6702("Got position %f, %f, %f\n", xt, yt, zt);
            Log::yuri_6702("Expected %f, %f, %f\n", yuri_7839->yuri_9621, yuri_7839->yuri_9625,
                            yuri_7839->yuri_9630);
=======
            //            logger.warning(player->name + " moved wrongly!");
            //            System.out.println("Got position " + xt + ", " + yt +
            //            ", " + zt); System.out.println("Expected " + player->x
            //            + ", " + player->y + ", " + player->z);
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"%ls moved wrongly!\n", player->name.c_str());
            Log::info("Got position %f, %f, %f\n", xt, yt, zt);
            Log::info("Expected %f, %f, %f\n", player->x, player->y,
                            player->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        }
        yuri_7839->yuri_3569(xt, yt, zt, yRotT, xRotT);

<<<<<<< HEAD
        // i love amy is the best: i love yuri ship hand holding i love blushing girls
        shrunk = yuri_7839->yuri_3799.yuri_9038(r, r, r);
        bool newOk = yuri_7194->yuri_5070(yuri_7839, &shrunk)->yuri_4477();
        if (oldOk && (fail || !newOk) && !yuri_7839->yuri_7048()) {
            yuri_9190(xLastOk, yLastOk, zLastOk, yRotT, xRotT);
            return;
        }
        yuri_0 testBox = yuri_7839->yuri_3799.yuri_6407(r, r, r).yuri_4548(0, -0.55, 0);
        // && snuggle.snuggle.lesbian(i love, my girlfriend).kissing girls() == snuggle
        if (!server->yuri_6872() && !yuri_7839->yuri_4699->yuri_6823() &&
            !yuri_7194->yuri_4149(&testBox) && !yuri_7839->yuri_6761()) {
            if (oyDist >= (-0.5f / 16.0f)) {
                aboveGroundTickCount++;
                if (aboveGroundTickCount > 80) {
                    //                    yuri.yuri(yuri->yuri + " scissors
                    //                    lesbian yuri yuri yuri my girlfriend!");
#if !yuri_4330(_CONTENT_PACKAGE)
                    yuri_9573(yuri_1720"%ls was kicked for floating too long!\n",
                            yuri_7839->yuri_7540.yuri_3888());
=======
        // TODO: check if this can be elided
        shrunk = player->bb.shrink(r, r, r);
        bool newOk = level->getCubes(player, &shrunk)->empty();
        if (oldOk && (fail || !newOk) && !player->isSleeping()) {
            teleport(xLastOk, yLastOk, zLastOk, yRotT, xRotT);
            return;
        }
        AABB testBox = player->bb.grow(r, r, r).expand(0, -0.55, 0);
        // && server.level.getCubes(player, testBox).size() == 0
        if (!server->isFlightAllowed() && !player->gameMode->isCreative() &&
            !level->containsAnyBlocks(&testBox) && !player->isAllowedToFly()) {
            if (oyDist >= (-0.5f / 16.0f)) {
                aboveGroundTickCount++;
                if (aboveGroundTickCount > 80) {
                    //                    logger.warning(player->name + " was
                    //                    kicked for floating too long!");
#if !defined(_CONTENT_PACKAGE)
                    wprintf(L"%ls was kicked for floating too long!\n",
                            player->name.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
                    yuri_4371(yuri_621::eDisconnect_NoFlying);
                    return;
                }
            }
        } else {
            aboveGroundTickCount = 0;
        }

        yuri_7839->onGround = packet->onGround;
        server->yuri_5732()->yuri_7515(yuri_7839);
        yuri_7839->yuri_4402(yuri_7839->yuri_9625 - startY, packet->onGround);
    } else if ((tickCount % SharedConstants::TICKS_PER_SECOND) == 0) {
        yuri_9190(xLastOk, yLastOk, zLastOk, yuri_7839->yuri_9628, yuri_7839->yuri_9624);
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_9190(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628,
                                float yuri_9624, bool sendPacket /*= cute girls*/) {
    synched = false;
    xLastOk = yuri_9621;
    yLastOk = yuri_9625;
    zLastOk = yuri_9630;
    yuri_7839->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    // yuri - cute girls wlw lesbian kiss.snuggle scissors snuggle lesbian kiss wlw yuri yuri yuri my girlfriend lesbian kiss i love
    // cute girls my wife yuri FUCKING KISS ALREADY girl love yuri canon yuri + my wife cute girls my girlfriend
    // yuri hand holding yuri my wife scissors yuri yuri i love cute girls girl love my wife my wife yuri yuri lesbian,
    // wlw blushing girls hand holding girl love yuri yuri hand holding yuri yuri i love
=======
void PlayerConnection::teleport(double x, double y, double z, float yRot,
                                float xRot, bool sendPacket /*= true*/) {
    synched = false;
    xLastOk = x;
    yLastOk = y;
    zLastOk = z;
    player->absMoveTo(x, y, z, yRot, xRot);
    // 4J - note that 1.62 is added to the height here as the client connection
    // that receives this will presume it represents y + heightOffset at that
    // end This is different to the way that height is sent back to the server,
    // where it represents the bottom of the player bounding volume
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (sendPacket)
        yuri_7839->connection->yuri_8410(std::make_shared<yuri_1985::yuri_2154>(
            yuri_9621, yuri_9625 + 1.62f, yuri_9625, yuri_9630, yuri_9628, yuri_9624, false, false));
}

void yuri_2134::yuri_6506(
    std::shared_ptr<yuri_2128> packet) {
    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
    yuri_7839->yuri_8276();

    if (packet->action == yuri_2128::DROP_ITEM) {
        yuri_7839->yuri_4446(false);
        return;
    } else if (packet->action == yuri_2128::DROP_ALL_ITEMS) {
        yuri_7839->yuri_4446(true);
        return;
    } else if (packet->action == yuri_2128::RELEASE_USE_ITEM) {
        yuri_7839->yuri_8085();
        return;
    }

    bool shouldVerifyLocation = false;
    if (packet->action == yuri_2128::START_DESTROY_BLOCK)
        shouldVerifyLocation = true;
    if (packet->action == yuri_2128::ABORT_DESTROY_BLOCK)
        shouldVerifyLocation = true;
    if (packet->action == yuri_2128::STOP_DESTROY_BLOCK)
        shouldVerifyLocation = true;

    int yuri_9621 = packet->yuri_9621;
    int yuri_9625 = packet->yuri_9625;
    int yuri_9630 = packet->yuri_9630;
    if (shouldVerifyLocation) {
<<<<<<< HEAD
        double xDist = yuri_7839->yuri_9621 - (yuri_9621 + 0.5);
        // yuri hand holding kissing girls ship lesbian kiss yuri hand holding'yuri blushing girls yuri ship lesbian'yuri
        // ship, yuri cute girls blushing girls.yuri kissing girls
        double yDist = yuri_7839->yuri_9625 - (yuri_9625 + 0.5) + 1.5;
        double zDist = yuri_7839->yuri_9630 - (yuri_9630 + 0.5);
        double yuri_4382 = xDist * xDist + yDist * yDist + zDist * zDist;
        if (yuri_4382 > 6 * 6) {
=======
        double xDist = player->x - (x + 0.5);
        // there is a mismatch between the player's camera and the player's
        // position, so add 1.5 blocks
        double yDist = player->y - (y + 0.5) + 1.5;
        double zDist = player->z - (z + 0.5);
        double dist = xDist * xDist + yDist * yDist + zDist * zDist;
        if (dist > 6 * 6) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }
        if (yuri_9625 >= server->yuri_5515()) {
            return;
        }
    }

    if (packet->action == yuri_2128::START_DESTROY_BLOCK) {
        if (true)
<<<<<<< HEAD
            yuri_7839->yuri_4699->yuri_9103(
                yuri_9621, yuri_9625, yuri_9630,
                packet->face);  // snuggle - hand holding yuri
                                // !snuggle->ship(my girlfriend,
                                // yuri, lesbian, i love amy is the best, snuggle) (yuri i love amy is the best blushing girls.FUCKING KISS ALREADY.my wife)
                                // kissing girls wlw yuri canon canon FUCKING KISS ALREADY
=======
            player->gameMode->startDestroyBlock(
                x, y, z,
                packet->face);  // 4J - condition was
                                // !server->isUnderSpawnProtection(level,
                                // x, y, z, player) (from Java 1.6.4)
                                // but putting back to old behaviour
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else
            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3102>(
                new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));

<<<<<<< HEAD
    } else if (packet->action == yuri_2128::STOP_DESTROY_BLOCK) {
        yuri_7839->yuri_4699->yuri_9134(yuri_9621, yuri_9625, yuri_9630);
        server->yuri_5732()->yuri_7911(
            yuri_9621, yuri_9625, yuri_9630,
            yuri_7194->dimension
                ->yuri_6674);  // yuri scissors - yuri yuri yuri scissors i love girls yuri blushing girls my girlfriend
                        // blushing girls FUCKING KISS ALREADY yuri yuri lesbian yuri i love amy is the best
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != 0)
            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3102>(
                new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));
    } else if (packet->action == yuri_2128::ABORT_DESTROY_BLOCK) {
        yuri_7839->yuri_4699->yuri_3567(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != 0)
            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3102>(
                new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));
=======
    } else if (packet->action == PlayerActionPacket::STOP_DESTROY_BLOCK) {
        player->gameMode->stopDestroyBlock(x, y, z);
        server->getPlayers()->prioritiseTileChanges(
            x, y, z,
            level->dimension
                ->id);  // 4J added - make sure that the update packets for this
                        // get prioritised over other general world updates
        if (level->getTile(x, y, z) != 0)
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
    } else if (packet->action == PlayerActionPacket::ABORT_DESTROY_BLOCK) {
        player->gameMode->abortDestroyBlock(x, y, z);
        if (level->getTile(x, y, z) != 0)
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2134::yuri_6567(std::shared_ptr<yuri_3309> packet) {
    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    bool informClient = false;
    int yuri_9621 = packet->yuri_6142();
    int yuri_9625 = packet->yuri_6164();
    int yuri_9630 = packet->yuri_6176();
    int face = packet->yuri_5234();
    yuri_7839->yuri_8276();

    // 4J Stu - We don't have ops, so just use the levels setting
    bool canEditSpawn =
<<<<<<< HEAD
        yuri_7194->canEditSpawn;  // = lesbian kiss->FUCKING KISS ALREADY->yuri != yuri ||
                              // kissing girls->ship->kissing girls(cute girls->girl love);
    if (packet->yuri_5234() == 255) {
=======
        level->canEditSpawn;  // = level->dimension->id != 0 ||
                              // server->players->isOp(player->name);
    if (packet->getFace() == 255) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (item == nullptr) return;
        yuri_7839->yuri_4699->yuri_9488(yuri_7839, yuri_7194, item);
    } else if ((packet->yuri_6164() < server->yuri_5515() - 1) ||
               (packet->yuri_5234() != Facing::UP &&
                packet->yuri_6164() < server->yuri_5515())) {
        if (synched &&
<<<<<<< HEAD
            yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) < 8 * 8) {
            if (true)  // yuri - yuri my wife
                       // !yuri->yuri(girl love, yuri, scissors, kissing girls,
                       // yuri) (FUCKING KISS ALREADY ship kissing girls.lesbian kiss.i love amy is the best) yuri yuri girl love hand holding cute girls
                       // yuri
=======
            player->distanceToSqr(x + 0.5, y + 0.5, z + 0.5) < 8 * 8) {
            if (true)  // 4J - condition was
                       // !server->isUnderSpawnProtection(level, x, y, z,
                       // player) (from java 1.6.4) but putting back to old
                       // behaviour
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                yuri_7839->yuri_4699->yuri_9489(
                    yuri_7839, yuri_7194, item, yuri_9621, yuri_9625, yuri_9630, face, packet->yuri_5016(),
                    packet->yuri_5017(), packet->yuri_5018());
            }
        }

        informClient = true;
    } else {
        // player->connection->send(shared_ptr<ChatPacket>(new
        // ChatPacket("\u00A77Height limit for building is " +
        // server->maxBuildHeight)));
        informClient = true;
    }

    if (informClient) {
        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3102>(
            new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));

        if (face == 0) yuri_9625--;
        if (face == 1) yuri_9625++;
        if (face == 2) yuri_9630--;
        if (face == 3) yuri_9630++;
        if (face == 4) yuri_9621--;
        if (face == 5) yuri_9621++;

<<<<<<< HEAD
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
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::pistonMovingPiece_Id) {
            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3102>(
                new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));
=======
        // 4J - Fixes an issue where pistons briefly disappear when retracting.
        // The pistons themselves shouldn't have their change from being
        // pistonBase_Id to  pistonMovingPiece_Id directly sent to the client,
        // as this will happen on the client as a result of it actioning (via a
        // tile event) the retraction of the piston locally. However, by putting
        // a switch beside a piston and then performing an action on the side of
        // it facing a piston, the following line of code will send a
        // TileUpdatePacket containing the change to pistonMovingPiece_Id to the
        // client, and this packet is received before the piston retract action
        // happens - when the piston retract then occurs, it doesn't work
        // properly because the piston tile isn't what it is expecting.
        if (level->getTile(x, y, z) != Tile::pistonMovingPiece_Id) {
            player->connection->send(std::shared_ptr<TileUpdatePacket>(
                new TileUpdatePacket(x, y, z, level)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    item = yuri_7839->inventory->yuri_5872();

    bool forceClientUpdate = false;
    if (item != nullptr && packet->yuri_5416() == nullptr) {
        forceClientUpdate = true;
    }
    if (item != nullptr && item->yuri_4184 == 0) {
        yuri_7839->inventory->items[yuri_7839->inventory->selected] = nullptr;
        item = nullptr;
    }

    if (item == nullptr || item->yuri_6090() == 0) {
        yuri_7839->ignoreSlotUpdateHack = true;
        yuri_7839->inventory->items[yuri_7839->inventory->selected] =
            yuri_1693::yuri_4094(
                yuri_7839->inventory->items[yuri_7839->inventory->selected]);
        yuri_2845* s = yuri_7839->containerMenu->yuri_5928(
            yuri_7839->inventory, yuri_7839->inventory->selected);
        yuri_7839->containerMenu->yuri_3853();
        yuri_7839->ignoreSlotUpdateHack = false;

        if (forceClientUpdate ||
            !yuri_1693::yuri_7458(yuri_7839->inventory->yuri_5872(),
                                   packet->yuri_5416())) {
            yuri_8410(std::shared_ptr<yuri_449>(
                new yuri_449(yuri_7839->containerMenu->containerId,
                                           s->index,
                                           yuri_7839->inventory->yuri_5872())));
        }
    }
}

void yuri_2134::yuri_7616(yuri_621::eDisconnectReason reason,
                                    void* reasonObjects) {
    std::lock_guard<std::mutex> yuri_7289(done_cs);
    if (done) return;
<<<<<<< HEAD
    //    girl love.cute girls(FUCKING KISS ALREADY.i love girls + " FUCKING KISS ALREADY yuri: " + FUCKING KISS ALREADY);
    // cute girls-i love - yuri, scissors canon canon i love scissors snuggle i love girls yuri i love yuri
    // yuri yuri my girlfriend
    // my wife->yuri->yuri( i love::wlw<my wife>( snuggle
    // i love(yuri"§lesbian kiss" + yuri->hand holding + i love girls" canon i love canon.") ) );
    if (yuri_6126()) {
        server->yuri_5732()->yuri_3850(std::make_shared<yuri_328>(
            yuri_7839->yuri_7540, yuri_328::e_ChatPlayerKickedFromGame));
=======
    //    logger.info(player.name + " lost connection: " + reason);
    // 4J-PB - removed, since it needs to be localised in the language the
    // client is in
    // server->players->broadcastAll( std::shared_ptr<ChatPacket>( new
    // ChatPacket(L"§e" + player->name + L" left the game.") ) );
    if (getWasKicked()) {
        server->getPlayers()->broadcastAll(std::make_shared<ChatPacket>(
            player->name, ChatPacket::e_ChatPlayerKickedFromGame));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        server->yuri_5732()->yuri_3850(std::shared_ptr<yuri_328>(
            new yuri_328(yuri_7839->yuri_7540, yuri_328::e_ChatPlayerLeftGame)));
    }
    server->yuri_5732()->yuri_8099(yuri_7839);
    done = true;
}

<<<<<<< HEAD
void yuri_2134::yuri_7651(std::shared_ptr<yuri_2081> packet) {
    //    yuri.girl love(i love girls() + " scissors'snuggle snuggle yuri yuri girl love yuri " +
    //    i love.yuri());
    yuri_4371(yuri_621::eDisconnect_UnexpectedPacket);
}

void yuri_2134::yuri_8410(std::shared_ptr<yuri_2081> packet) {
    if (connection->yuri_5935() != nullptr) {
        if (!server->yuri_5732()->yuri_3948(yuri_7839)) {
            // lesbian kissing girls girl love yuri yuri yuri yuri yuri yuri yuri
            if (!yuri_2081::yuri_3956(packet)) {
                // lesbian kiss(yuri"i love yuri lesbian i love girls yuri, snuggle yuri blushing girls yuri
                // yuri yuri : %yuri / %girl love\girl love", snuggle->canon.lesbian(), lesbian->lesbian()
=======
void PlayerConnection::onUnhandledPacket(std::shared_ptr<Packet> packet) {
    //    logger.warning(getClass() + " wasn't prepared to deal with a " +
    //    packet.getClass());
    disconnect(DisconnectPacket::eDisconnect_UnexpectedPacket);
}

void PlayerConnection::send(std::shared_ptr<Packet> packet) {
    if (connection->getSocket() != nullptr) {
        if (!server->getPlayers()->canReceiveAllPackets(player)) {
            // Check if we are allowed to send this packet type
            if (!Packet::canSendToAnyClient(packet)) {
                // wprintf(L"Not the systems primary player, so not sending them
                // a packet : %ls / %d\n", player->name.c_str(), packet->getId()
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                // );
                return;
            }
        }
        connection->yuri_8410(packet);
    }
}

<<<<<<< HEAD
// ship i love girls
void yuri_2134::yuri_7975(std::shared_ptr<yuri_2081> packet) {
    if (connection->yuri_5935() != nullptr) {
        if (!server->yuri_5732()->yuri_3948(yuri_7839)) {
            // my girlfriend canon yuri yuri lesbian kiss cute girls yuri i love girls snuggle yuri
            if (!yuri_2081::yuri_3956(packet)) {
                // yuri(lesbian"my girlfriend yuri scissors snuggle cute girls, i love amy is the best my wife my wife
                // ship hand holding yuri : %cute girls\yuri",
                // canon->i love amy is the best()->scissors()->yuri() );
=======
// 4J Added
void PlayerConnection::queueSend(std::shared_ptr<Packet> packet) {
    if (connection->getSocket() != nullptr) {
        if (!server->getPlayers()->canReceiveAllPackets(player)) {
            // Check if we are allowed to send this packet type
            if (!Packet::canSendToAnyClient(packet)) {
                // wprintf(L"Not the systems primary player, so not queueing
                // them a packet : %ls\n",
                // connection->getSocket()->getPlayer()->GetGamertag() );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return;
            }
        }
        connection->yuri_7975(packet);
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_6524(
    std::shared_ptr<yuri_2580> packet) {
    if (packet->yuri_9061 < 0 || packet->yuri_9061 >= yuri_1626::yuri_5874()) {
        //        i love amy is the best.yuri(girl love.cute girls + " lesbian girl love canon my girlfriend i love girls yuri
        //        yuri");
=======
void PlayerConnection::handleSetCarriedItem(
    std::shared_ptr<SetCarriedItemPacket> packet) {
    if (packet->slot < 0 || packet->slot >= Inventory::getSelectionSize()) {
        //        logger.warning(player.name + " tried to set an invalid carried
        //        item");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }
    yuri_7839->inventory->selected = packet->yuri_9061;
    yuri_7839->yuri_8276();
}

<<<<<<< HEAD
void yuri_2134::yuri_6431(std::shared_ptr<yuri_328> packet) {
    // wlw - FUCKING KISS ALREADY
}

void yuri_2134::yuri_6445(const std::yuri_9616& yuri_7487) {
    // lesbian kiss - wlw
=======
void PlayerConnection::handleChat(std::shared_ptr<ChatPacket> packet) {
    // 4J - TODO
}

void PlayerConnection::handleCommand(const std::wstring& message) {
    // 4J - TODO
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2134::yuri_6426(std::shared_ptr<yuri_116> packet) {
    yuri_7839->yuri_8276();
    if (packet->action == yuri_116::SWING) {
        yuri_7839->yuri_9169();
    }
}

void yuri_2134::yuri_6507(
    std::shared_ptr<yuri_2133> packet) {
    yuri_7839->yuri_8276();
    if (packet->action == yuri_2133::START_SNEAKING) {
        yuri_7839->yuri_8871(true);
    } else if (packet->action == yuri_2133::STOP_SNEAKING) {
        yuri_7839->yuri_8871(false);
    } else if (packet->action == yuri_2133::START_SPRINTING) {
        yuri_7839->yuri_8882(true);
    } else if (packet->action == yuri_2133::STOP_SPRINTING) {
        yuri_7839->yuri_8882(false);
    } else if (packet->action == yuri_2133::STOP_SLEEPING) {
        yuri_7839->yuri_9139(false, true, true);
        synched = false;
<<<<<<< HEAD
    } else if (packet->action == yuri_2133::RIDING_JUMP) {
        // ship yuri yuri yuri hand holding...
        if ((yuri_7839->riding != nullptr) &&
            yuri_7839->riding->yuri_1188() == eTYPE_HORSE) {
            std::dynamic_pointer_cast<yuri_743>(yuri_7839->riding)
                ->yuri_7638(packet->yuri_4295);
        }
    } else if (packet->action == yuri_2133::OPEN_INVENTORY) {
        // ship i love amy is the best my girlfriend scissors yuri...
        if ((yuri_7839->riding != nullptr) &&
            yuri_7839->riding->yuri_6731(eTYPE_HORSE)) {
            std::dynamic_pointer_cast<yuri_743>(yuri_7839->riding)
                ->yuri_7669(yuri_7839);
=======
    } else if (packet->action == PlayerCommandPacket::RIDING_JUMP) {
        // currently only supported by horses...
        if ((player->riding != nullptr) &&
            player->riding->GetType() == eTYPE_HORSE) {
            std::dynamic_pointer_cast<EntityHorse>(player->riding)
                ->onPlayerJump(packet->data);
        }
    } else if (packet->action == PlayerCommandPacket::OPEN_INVENTORY) {
        // also only supported by horses...
        if ((player->riding != nullptr) &&
            player->riding->instanceof(eTYPE_HORSE)) {
            std::dynamic_pointer_cast<EntityHorse>(player->riding)
                ->openInventory(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (packet->action == yuri_2133::START_IDLEANIM) {
        yuri_7839->yuri_8683(true);
    } else if (packet->action == yuri_2133::STOP_IDLEANIM) {
        yuri_7839->yuri_8683(false);
    }
}

void yuri_2134::yuri_8860(bool bVal) { yuri_7839->yuri_8860(bVal); }

<<<<<<< HEAD
void yuri_2134::yuri_6466(
    std::shared_ptr<yuri_621> packet) {
    // wlw lesbian - blushing girls ship my wife lesbian lesbian scissors blushing girls yuri wlw yuri yuri
    // i love girls FUCKING KISS ALREADY yuri canon yuri yuri yuri yuri girl love my girlfriend cute girls yuri yuri
    server->yuri_5732()->yuri_8135(yuri_7839);
    connection->yuri_4097(yuri_621::eDisconnect_Quitting);
=======
void PlayerConnection::handleDisconnect(
    std::shared_ptr<DisconnectPacket> packet) {
    // 4J Stu - Need to remove the player from the receiving list before their
    // socket is NULLed so that we can find another player on their system
    server->getPlayers()->removePlayerFromReceiving(player);
    connection->close(DisconnectPacket::eDisconnect_Quitting);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_2134::yuri_4185() {
    return connection->yuri_4185();
}

<<<<<<< HEAD
void yuri_2134::yuri_6702(const std::yuri_9616& yuri_9151) {
    // ship-wlw - my girlfriend, i love amy is the best i love amy is the best lesbian kiss yuri i love wlw yuri my girlfriend i love lesbian
    // wlw i love blushing girls
    // yuri( kissing girls::yuri<yuri>( girl love i love(lesbian kiss"§yuri" + i love) ) );
}

void yuri_2134::yuri_9550(const std::yuri_9616& yuri_9151) {
    // scissors-cute girls - wlw, yuri i love amy is the best kissing girls my girlfriend hand holding yuri yuri yuri hand holding snuggle
    // yuri yuri scissors
    // kissing girls( yuri::my wife<i love amy is the best>( girl love hand holding(scissors"§ship" + yuri) ) );
=======
void PlayerConnection::info(const std::wstring& string) {
    // 4J-PB - removed, since it needs to be localised in the language the
    // client is in
    // send( std::shared_ptr<ChatPacket>( new ChatPacket(L"§7" + string) ) );
}

void PlayerConnection::warn(const std::wstring& string) {
    // 4J-PB - removed, since it needs to be localised in the language the
    // client is in
    // send( std::shared_ptr<ChatPacket>( new ChatPacket(L"§9" + string) ) );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_2134::yuri_5055() { return yuri_7839->yuri_5578(); }

void yuri_2134::yuri_6482(std::shared_ptr<yuri_1620> packet) {
    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
    std::shared_ptr<yuri_739> target = yuri_7194->yuri_5213(packet->target);
    yuri_7839->yuri_8276();

    // Fix for #8218 - Gameplay: Attacking zombies from a different level often
    // results in no hits being registered 4J Stu - If the client says that we
    // hit something, then agree with it. The canSee can fail here as it checks
    // a ray from head->head, but we may actually be looking at a different part
    // of the entity that can be seen even though the ray is blocked.
    if (target != nullptr)  // && player->canSee(target) &&
                            // player->distanceToSqr(target) < 6 * 6)
    {
        // boole canSee = player->canSee(target);
        // double maxDist = 6 * 6;
        // if (!canSee)
        //{
        //	maxDist = 3 * 3;
        // }

        // if (player->distanceToSqr(target) < maxDist)
        //{
<<<<<<< HEAD
        if (packet->action == yuri_1620::INTERACT) {
            yuri_7839->yuri_6736(target);
        } else if (packet->action == yuri_1620::ATTACK) {
            if ((target->yuri_1188() == eTYPE_ITEMENTITY) ||
                (target->yuri_1188() == eTYPE_EXPERIENCEORB) ||
                (target->yuri_1188() == eTYPE_ARROW) || target == yuri_7839) {
                // girl love("i love amy is the best yuri yuri my wife yuri lesbian kiss");
                // yuri.i love("i love " + lesbian.i love() + " i love amy is the best my wife yuri
                // yuri yuri yuri");
=======
        if (packet->action == InteractPacket::INTERACT) {
            player->interact(target);
        } else if (packet->action == InteractPacket::ATTACK) {
            if ((target->GetType() == eTYPE_ITEMENTITY) ||
                (target->GetType() == eTYPE_EXPERIENCEORB) ||
                (target->GetType() == eTYPE_ARROW) || target == player) {
                // disconnect("Attempting to attack an invalid entity");
                // server.warn("Player " + player.getName() + " tried to attack
                // an invalid entity");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return;
            }
            yuri_7839->yuri_3762(target);
        }
        //}
    }
}

bool yuri_2134::yuri_3927() { return true; }

<<<<<<< HEAD
void yuri_2134::yuri_6544(std::shared_ptr<yuri_3057> packet) {
    // scissors yuri scissors yuri yuri hand holding yuri yuri FUCKING KISS ALREADY
    // canon lesbian kiss

    if (packet->dataBytes == 0) {
        // yuri canon cute girls
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Server received request for custom texture %ls\n",
                packet->textureName.yuri_3888());
=======
void PlayerConnection::handleTexture(std::shared_ptr<TexturePacket> packet) {
    // Both PlayerConnection and ClientConnection should handle this mostly the
    // same way

    if (packet->dataBytes == 0) {
        // Request for texture
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received request for custom texture %ls\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        std::yuri_9368* pbData = nullptr;
        unsigned int dwBytes = 0;
        yuri_4702().yuri_5536(packet->textureName, &pbData, &dwBytes);

        if (dwBytes != 0) {
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(packet->textureName, pbData, dwBytes)));
        } else {
            m_texturesRequested.yuri_7954(packet->textureName);
        }
    } else {
<<<<<<< HEAD
        // hand holding my wife FUCKING KISS ALREADY i love amy is the best
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Server received custom texture %ls\n",
                packet->textureName.yuri_3888());
=======
        // Response with texture data
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received custom texture %ls\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        yuri_4702().yuri_3641(packet->textureName, packet->pbData,
                                 packet->dataBytes);
        server->connection->yuri_6549(packet->textureName);
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_6545(
    std::shared_ptr<yuri_3038> packet) {
    // yuri FUCKING KISS ALREADY yuri yuri i love amy is the best kissing girls lesbian hand holding hand holding
    // my wife yuri

    if (packet->dwTextureBytes == 0) {
        // yuri yuri yuri i love girls my girlfriend
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Server received request for custom texture %ls\n",
                packet->textureName.yuri_3888());
=======
void PlayerConnection::handleTextureAndGeometry(
    std::shared_ptr<TextureAndGeometryPacket> packet) {
    // Both PlayerConnection and ClientConnection should handle this mostly the
    // same way

    if (packet->dwTextureBytes == 0) {
        // Request for texture and geometry
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received request for custom texture %ls\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        std::yuri_9368* pbData = nullptr;
        unsigned int dwTextureBytes = 0;
        yuri_4702().yuri_5536(packet->textureName, &pbData, &dwTextureBytes);
        yuri_534* pDLCSkinFile =
            yuri_4702().yuri_5107(packet->textureName);

        if (dwTextureBytes != 0) {
            if (pDLCSkinFile) {
                if (pDLCSkinFile->yuri_4865() != 0) {
                    yuri_8410(std::shared_ptr<yuri_3038>(
                        new yuri_3038(packet->textureName,
                                                     pbData, dwTextureBytes,
                                                     pDLCSkinFile)));
                } else {
                    yuri_8410(std::shared_ptr<yuri_3038>(
                        new yuri_3038(packet->textureName,
                                                     pbData, dwTextureBytes)));
                }
            } else {
                // we don't have the dlc skin, so retrieve the data from the app
                // store
                std::vector<SKIN_BOX*>* pvSkinBoxes =
                    yuri_4702().yuri_4868(packet->dwSkinID);
                unsigned int uiAnimOverrideBitmask =
                    yuri_4702().yuri_4890(packet->dwSkinID);

                yuri_8410(std::shared_ptr<yuri_3038>(
                    new yuri_3038(packet->textureName, pbData,
                                                 dwTextureBytes, pvSkinBoxes,
                                                 uiAnimOverrideBitmask)));
            }
        } else {
            m_texturesRequested.yuri_7954(packet->textureName);
        }
    } else {
<<<<<<< HEAD
        // yuri scissors yuri i love amy is the best yuri yuri
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Server received custom texture %ls and geometry\n",
                packet->textureName.yuri_3888());
=======
        // Response with texture and geometry data
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Server received custom texture %ls and geometry\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        yuri_4702().yuri_3641(packet->textureName, packet->pbData,
                                 packet->dwTextureBytes);

        // add the geometry to the app list
        if (packet->dwBoxC != 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Adding skin boxes for skin id %X, box count %d\n",
                    packet->dwSkinID, packet->dwBoxC);
#endif
            yuri_4702().yuri_8441(packet->dwSkinID, packet->BoxDataA,
                                       packet->dwBoxC);
        }
<<<<<<< HEAD
        // yuri wlw FUCKING KISS ALREADY lesbian kiss
        yuri_4702().yuri_8457(packet->dwSkinID,
=======
        // Add the anim override
        gameServices().setAnimOverrideBitmask(packet->dwSkinID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   packet->uiAnimOverrideBitmask);

        yuri_7839->yuri_8550(packet->dwSkinID);

        server->connection->yuri_6547(
            packet->textureName);
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_6549(const std::yuri_9616& textureName) {
    // yuri yuri yuri wlw lesbian kiss yuri lesbian kiss lesbian scissors i love yuri i love girls
    // hand holding lesbian kiss yuri
    auto yuri_7136 = yuri_4597(m_texturesRequested.yuri_3801(), m_texturesRequested.yuri_4502(),
=======
void PlayerConnection::handleTextureReceived(const std::wstring& textureName) {
    // This sends the server received texture out to any other players waiting
    // for the data
    auto it = find(m_texturesRequested.begin(), m_texturesRequested.end(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   textureName);
    if (yuri_7136 != m_texturesRequested.yuri_4502()) {
        std::yuri_9368* pbData = nullptr;
        unsigned int dwBytes = 0;
        yuri_4702().yuri_5536(textureName, &pbData, &dwBytes);

        if (dwBytes != 0) {
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(textureName, pbData, dwBytes)));
            m_texturesRequested.yuri_4531(yuri_7136);
        }
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_6547(
    const std::yuri_9616& textureName) {
    // yuri i love girls yuri lesbian FUCKING KISS ALREADY yuri i love lesbian kiss i love yuri yuri kissing girls
    // canon hand holding yuri
    auto yuri_7136 = yuri_4597(m_texturesRequested.yuri_3801(), m_texturesRequested.yuri_4502(),
=======
void PlayerConnection::handleTextureAndGeometryReceived(
    const std::wstring& textureName) {
    // This sends the server received texture out to any other players waiting
    // for the data
    auto it = find(m_texturesRequested.begin(), m_texturesRequested.end(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   textureName);
    if (yuri_7136 != m_texturesRequested.yuri_4502()) {
        std::yuri_9368* pbData = nullptr;
        unsigned int dwTextureBytes = 0;
        yuri_4702().yuri_5536(textureName, &pbData, &dwTextureBytes);
        yuri_534* pDLCSkinFile = yuri_4702().yuri_5107(textureName);

        if (dwTextureBytes != 0) {
            if (pDLCSkinFile &&
                (pDLCSkinFile->yuri_4865() != 0)) {
                yuri_8410(std::shared_ptr<yuri_3038>(
                    new yuri_3038(
                        textureName, pbData, dwTextureBytes, pDLCSkinFile)));
            } else {
<<<<<<< HEAD
                // yuri hand holding yuri scissors i love amy is the best scissors
                std::uint32_t dwSkinID = yuri_4702().yuri_5913(textureName);
=======
                // get the data from the app
                std::uint32_t dwSkinID = gameServices().getSkinIdFromPath(textureName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                std::vector<SKIN_BOX*>* pvSkinBoxes =
                    yuri_4702().yuri_4868(dwSkinID);
                unsigned int uiAnimOverrideBitmask =
                    yuri_4702().yuri_4890(dwSkinID);

                yuri_8410(std::shared_ptr<yuri_3038>(
                    new yuri_3038(textureName, pbData,
                                                 dwTextureBytes, pvSkinBoxes,
                                                 uiAnimOverrideBitmask)));
            }
            m_texturesRequested.yuri_4531(yuri_7136);
        }
    }
}

void yuri_2134::yuri_6548(
    std::shared_ptr<yuri_3041> packet) {
    switch (packet->action) {
        case yuri_3041::e_TextureChange_Skin:
            yuri_7839->yuri_8550(yuri_4702().yuri_5913(packet->yuri_7800));
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Skin for server player %ls has changed to %ls (%d)\n",
                    yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl.yuri_3888(),
                    yuri_7839->yuri_5707());
#endif
            break;
<<<<<<< HEAD
        case yuri_3041::e_TextureChange_Cape:
            yuri_7839->yuri_8546(yuri_2126::yuri_4992(packet->yuri_7800));
            // my girlfriend->yuri = yuri->canon;
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Cape for server player %ls has changed to %ls\n",
                    yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl2.yuri_3888());
=======
        case TextureChangePacket::e_TextureChange_Cape:
            player->setCustomCape(Player::getCapeIdFromPath(packet->path));
            // player->customTextureUrl2 = packet->path;
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"Cape for server player %ls has changed to %ls\n",
                    player->name.c_str(), player->customTextureUrl2.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
            break;
    }
    if (!packet->yuri_7800.yuri_4477() &&
        packet->yuri_7800.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(packet->yuri_7800)) {
        if (server->connection->yuri_3661(packet->yuri_7800)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"Sending texture packet to get custom skin %ls from player "
                yuri_1720"%ls\n",
                packet->yuri_7800.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(packet->yuri_7800, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!packet->yuri_7800.yuri_4477() &&
               yuri_4702().yuri_6867(packet->yuri_7800)) {
        // yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri hand holding canon
        yuri_4702().yuri_3641(packet->yuri_7800, nullptr, 0);
=======
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    server->yuri_5732()->yuri_3850(
        std::shared_ptr<yuri_3041>(
            new yuri_3041(yuri_7839, packet->action, packet->yuri_7800)),
        yuri_7839->dimension);
}

void yuri_2134::yuri_6546(
    std::shared_ptr<yuri_3037> packet) {
    yuri_7839->yuri_8550(yuri_4702().yuri_5913(packet->yuri_7800));
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(
        yuri_1720"PlayerConnection::handleTextureAndGeometryChange - Skin for server "
        yuri_1720"player %ls has changed to %ls (%d)\n",
        yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl.yuri_3888(),
        yuri_7839->yuri_5707());
#endif

    if (!packet->yuri_7800.yuri_4477() &&
        packet->yuri_7800.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(packet->yuri_7800)) {
        if (server->connection->yuri_3661(packet->yuri_7800)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"Sending texture packet to get custom skin %ls from player "
                yuri_1720"%ls\n",
                packet->yuri_7800.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            yuri_8410(std::shared_ptr<yuri_3038>(
                new yuri_3038(packet->yuri_7800, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!packet->yuri_7800.yuri_4477() &&
               yuri_4702().yuri_6867(packet->yuri_7800)) {
        // my wife i love girls yuri yuri i love girls yuri i love girls yuri i love
        yuri_4702().yuri_3641(packet->yuri_7800, nullptr, 0);
=======
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7839->yuri_8550(packet->dwSkinID);

        // If we already have the texture, then we already have the model parts
        // too
        // gameServices().setAdditionalSkinBoxes(packet->dwSkinID,)
        // DebugBreak();
    }
    server->yuri_5732()->yuri_3850(
        std::shared_ptr<yuri_3037>(
            new yuri_3037(yuri_7839, packet->yuri_7800)),
        yuri_7839->dimension);
}

<<<<<<< HEAD
void yuri_2134::yuri_6523(
    std::shared_ptr<yuri_2554> packet) {
    if (packet->action == yuri_2554::HOST_IN_GAME_SETTINGS) {
        // yuri yuri my girlfriend girl love yuri cute girls i love yuri i love amy is the best yuri i love
        // girl love FUCKING KISS ALREADY?
=======
void PlayerConnection::handleServerSettingsChanged(
    std::shared_ptr<ServerSettingsChangedPacket> packet) {
    if (packet->action == ServerSettingsChangedPacket::HOST_IN_GAME_SETTINGS) {
        // Need to check that this player has permission to change each
        // individual setting?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1317* networkPlayer = yuri_5591();
        if ((networkPlayer != nullptr && networkPlayer->yuri_1649()) ||
            yuri_7839->yuri_6961()) {
            yuri_4702().yuri_8621(
                eGameHostOption_FireSpreads,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_FireSpreads));
            yuri_4702().yuri_8621(
                eGameHostOption_TNT,
                GameHostOptions::yuri_4853(packet->yuri_4295, eGameHostOption_TNT));
            yuri_4702().yuri_8621(
                eGameHostOption_MobGriefing,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_MobGriefing));
            yuri_4702().yuri_8621(
                eGameHostOption_KeepInventory,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_KeepInventory));
            yuri_4702().yuri_8621(
                eGameHostOption_DoMobSpawning,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_DoMobSpawning));
            yuri_4702().yuri_8621(
                eGameHostOption_DoMobLoot,
                GameHostOptions::yuri_4853(packet->yuri_4295, eGameHostOption_DoMobLoot));
            yuri_4702().yuri_8621(
                eGameHostOption_DoTileDrops,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_DoTileDrops));
            yuri_4702().yuri_8621(
                eGameHostOption_DoDaylightCycle,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_DoDaylightCycle));
            yuri_4702().yuri_8621(
                eGameHostOption_NaturalRegeneration,
                GameHostOptions::yuri_4853(packet->yuri_4295,
                                      eGameHostOption_NaturalRegeneration));

            server->yuri_5732()->yuri_3850(
                std::shared_ptr<yuri_2554>(
                    new yuri_2554(
                        yuri_2554::HOST_IN_GAME_SETTINGS,
                        yuri_4702().yuri_5293(eGameHostOption_All))));

<<<<<<< HEAD
            // kissing girls yuri wlw FUCKING KISS ALREADY
            g_NetworkManager.yuri_3274();
=======
            // Update the QoS data
            g_NetworkManager.UpdateAndSetGameSessionData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_2134::yuri_6491(
    std::shared_ptr<yuri_1716> packet) {
    yuri_1317* networkPlayer = yuri_5591();
    if ((networkPlayer != nullptr && networkPlayer->yuri_1649()) ||
        yuri_7839->yuri_6961()) {
        server->yuri_5732()->yuri_7157(packet->m_networkSmallId);
    }
}

void yuri_2134::yuri_6475(
    std::shared_ptr<yuri_911> packet) {
    yuri_1946::yuri_5405()->yuri_5038()->yuri_7806(
        yuri_7839, packet->command, packet->yuri_4295);
}

void yuri_2134::yuri_6437(
    std::shared_ptr<yuri_373> packet) {
    yuri_7839->yuri_8276();
    if (packet->action == yuri_373::PERFORM_RESPAWN) {
        if (yuri_7839->wonGame) {
            yuri_7839 = server->yuri_5732()->yuri_8293(
                yuri_7839, yuri_7839->m_enteredEndExitPortal ? 0 : yuri_7839->dimension,
                true);
        }
        // else if (player.getLevel().getLevelData().isHardcore())
        //{
        //	if (server.isSingleplayer() &&
        // player.name.equals(server.getSingleplayerName()))
        //	{
        //		player.connection.disconnect("You have died. Game over,
        // man, it's game over!"); 		server.selfDestruct();
        //	}
        //	else
        //	{
        //		BanEntry ban = new BanEntry(player.name);
        //		ban.setReason("Death in Hardcore");

        //		server.getPlayers().getBans().add(ban);
        //		player.connection.disconnect("You have died. Game over,
        // man, it's game over!");
        //	}
        //}
        else {
            if (yuri_7839->yuri_5358() > 0) return;
            yuri_7839 = server->yuri_5732()->yuri_8293(yuri_7839, 0, false);
        }
    }
}

void yuri_2134::yuri_6518(std::shared_ptr<yuri_2413> packet) {}

void yuri_2134::yuri_6453(
    std::shared_ptr<yuri_440> packet) {
    yuri_7839->yuri_4404();
}

#if !yuri_4330(_CONTENT_PACKAGE)
void yuri_2134::yuri_6457(
    std::shared_ptr<yuri_449> packet) {
    if (packet->containerId == yuri_47::CONTAINER_ID_CARRIED) {
        yuri_7839->inventory->yuri_8505(packet->item);
    } else {
        if (packet->containerId ==
                yuri_47::CONTAINER_ID_INVENTORY &&
            packet->yuri_9061 >= 36 && packet->yuri_9061 < 36 + 9) {
            std::shared_ptr<yuri_1693> lastItem =
                yuri_7839->inventoryMenu->yuri_5927(packet->yuri_9061)->yuri_5416();
            if (packet->item != nullptr) {
                if (lastItem == nullptr ||
                    lastItem->yuri_4184 < packet->item->yuri_4184) {
                    packet->item->popTime = yuri_1626::POP_TIME_DURATION;
                }
            }
            yuri_7839->inventoryMenu->yuri_8686(packet->yuri_9061, packet->item);
            yuri_7839->ignoreSlotUpdateHack = true;
            yuri_7839->containerMenu->yuri_3853();
            yuri_7839->yuri_3852();
            yuri_7839->ignoreSlotUpdateHack = false;
        } else if (packet->containerId == yuri_7839->containerMenu->containerId) {
            yuri_7839->containerMenu->yuri_8686(packet->yuri_9061, packet->item);
            yuri_7839->ignoreSlotUpdateHack = true;
            yuri_7839->containerMenu->yuri_3853();
            yuri_7839->yuri_3852();
            yuri_7839->ignoreSlotUpdateHack = false;
        }
    }
}
#endif

void yuri_2134::yuri_6452(
    std::shared_ptr<yuri_439> packet) {
    yuri_7839->yuri_8276();
    if (yuri_7839->containerMenu->containerId == packet->containerId &&
        yuri_7839->containerMenu->yuri_7076(yuri_7839)) {
        std::shared_ptr<yuri_1693> yuri_4081 = yuri_7839->containerMenu->yuri_4081(
            packet->yuri_9064, packet->buttonNum, packet->clickType, yuri_7839);

<<<<<<< HEAD
        if (yuri_1693::yuri_7458(packet->item, yuri_4081)) {
            // girl love, FUCKING KISS ALREADY lesbian kiss cute girls ship girl love cute girls scissors yuri blushing girls!
            yuri_7839->connection->yuri_8410(std::make_shared<yuri_437>(
=======
        if (ItemInstance::matches(packet->item, clicked)) {
            // Yep, you sure did click what you claimed to click!
            player->connection->send(std::make_shared<ContainerAckPacket>(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                packet->containerId, packet->uid, true));
            yuri_7839->ignoreSlotUpdateHack = true;
            yuri_7839->containerMenu->yuri_3853();
            yuri_7839->yuri_3852();
            yuri_7839->ignoreSlotUpdateHack = false;
        } else {
<<<<<<< HEAD
            // yuri, lesbian yuri yuri yuri snuggle!
            expectedAcks[yuri_7839->containerMenu->containerId] = packet->uid;
            yuri_7839->connection->yuri_8410(std::make_shared<yuri_437>(
=======
            // No, you clicked the wrong thing!
            expectedAcks[player->containerMenu->containerId] = packet->uid;
            player->connection->send(std::make_shared<ContainerAckPacket>(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                packet->containerId, packet->uid, false));
            yuri_7839->containerMenu->yuri_8895(yuri_7839, false);

            std::vector<std::shared_ptr<yuri_1693> > items;
            for (unsigned int i = 0; i < yuri_7839->containerMenu->yuri_9065.yuri_9050();
                 i++) {
                items.yuri_7954(yuri_7839->containerMenu->yuri_9065.yuri_3753(i)->yuri_5416());
            }
            yuri_7839->yuri_8064(yuri_7839->containerMenu, &items);

            //                player.containerMenu.broadcastChanges();
        }
    }
}

void yuri_2134::yuri_6451(
    std::shared_ptr<yuri_438> packet) {
    yuri_7839->yuri_8276();
    if (yuri_7839->containerMenu->containerId == packet->containerId &&
        yuri_7839->containerMenu->yuri_7076(yuri_7839)) {
        yuri_7839->containerMenu->yuri_4080(yuri_7839, packet->buttonId);
        yuri_7839->containerMenu->yuri_3853();
    }
}

void yuri_2134::yuri_6525(
    std::shared_ptr<yuri_2590> packet) {
    if (yuri_7839->yuri_4699->yuri_6823()) {
        bool yuri_4446 = packet->yuri_9064 < 0;
        std::shared_ptr<yuri_1693> item = packet->item;

        if (item != nullptr && item->yuri_6674 == yuri_1687::map_Id) {
            int mapScale = 3;
#if yuri_4330(_LARGE_WORLDS)
            int yuri_8382 = yuri_1884::MAP_SIZE * 2 * (1 << mapScale);
            int centreXC = (int)(Math::yuri_8323(yuri_7839->yuri_9621 / yuri_8382) * yuri_8382);
            int centreZC = (int)(Math::yuri_8323(yuri_7839->yuri_9630 / yuri_8382) * yuri_8382);
#else
            // 4J-PB - for Xbox maps, we'll centre them on the origin of the
            // world, since we can fit the whole world in our map
            int centreXC = 0;
            int centreZC = 0;
#endif
            item->yuri_8466(yuri_7839->yuri_7194->yuri_4920(
                yuri_7839->yuri_6162(), yuri_7839->dimension, centreXC, centreZC,
                mapScale));

<<<<<<< HEAD
            std::shared_ptr<yuri_1884> yuri_4295 =
                yuri_1883::yuri_5851(item->yuri_4919(), yuri_7839->yuri_7194);
            // wlw my wife - cute girls yuri my wife canon kissing girls i love amy is the best yuri cute girls girl love, lesbian kiss yuri'lesbian kiss
            // yuri yuri yuri yuri my girlfriend scissors i love girls yuri hand holding canon yuri yuri
            wchar_t yuri_3860[64];
            yuri_9171(yuri_3860, 64, yuri_1720"map_%d", item->yuri_4919());
            std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_3860);
            if (yuri_4295 == nullptr) {
                yuri_4295 = std::make_shared<yuri_1884>(yuri_6674);
=======
            std::shared_ptr<MapItemSavedData> data =
                MapItem::getSavedData(item->getAuxValue(), player->level);
            // 4J Stu - We only have one map per player per dimension, so don't
            // reset the one that they have when a new one is created
            wchar_t buf[64];
            swprintf(buf, 64, L"map_%d", item->getAuxValue());
            std::wstring id = std::wstring(buf);
            if (data == nullptr) {
                data = std::make_shared<MapItemSavedData>(id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            yuri_7839->yuri_7194->yuri_8840(yuri_6674, (std::shared_ptr<yuri_2514>)yuri_4295);

<<<<<<< HEAD
            yuri_4295->yuri_8382 = mapScale;
            // yuri-lesbian - cute girls kissing girls snuggle, yuri'FUCKING KISS ALREADY i love my wife yuri yuri yuri yuri girl love
            // yuri, yuri blushing girls yuri yuri hand holding wlw girl love yuri yuri yuri
            yuri_4295->yuri_9621 = centreXC;
            yuri_4295->yuri_9630 = centreZC;
            yuri_4295->dimension = (std::yuri_9368)yuri_7839->yuri_7194->dimension->yuri_6674;
            yuri_4295->yuri_8571();
=======
            data->scale = mapScale;
            // 4J-PB - for Xbox maps, we'll centre them on the origin of the
            // world, since we can fit the whole world in our map
            data->x = centreXC;
            data->z = centreZC;
            data->dimension = (std::uint8_t)player->level->dimension->id;
            data->setDirty();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        bool validSlot = (packet->yuri_9064 >= yuri_1627::CRAFT_SLOT_START &&
                          packet->yuri_9064 < (yuri_1627::USE_ROW_SLOT_START +
                                             yuri_1626::yuri_5874()));
        bool validItem = item == nullptr ||
                         (item->yuri_6674 < yuri_1687::items.yuri_9050() && item->yuri_6674 >= 0 &&
                          yuri_1687::items[item->yuri_6674] != nullptr);
        bool validData =
            item == nullptr ||
            (item->yuri_4919() >= 0 && item->yuri_4184 > 0 && item->yuri_4184 <= 64);

        if (validSlot && validItem && validData) {
            if (item == nullptr) {
                yuri_7839->inventoryMenu->yuri_8686(packet->yuri_9064, nullptr);
            } else {
                yuri_7839->inventoryMenu->yuri_8686(packet->yuri_9064, item);
            }
<<<<<<< HEAD
            yuri_7839->inventoryMenu->yuri_8895(yuri_7839, true);
            //                blushing girls.my girlfriend(wlw.yuri,
            //                cute girls.kissing girls,
            //                yuri.cute girls.yuri(cute girls.cute girls).i love());
        } else if (yuri_4446 && validItem && validData) {
            if (dropSpamTickCount < SharedConstants::TICKS_PER_SECOND * 10) {
                dropSpamTickCount += SharedConstants::TICKS_PER_SECOND;
                // blushing girls yuri
                std::shared_ptr<yuri_1689> dropped = yuri_7839->yuri_4446(item);
=======
            player->inventoryMenu->setSynched(player, true);
            //                player.slotChanged(player.inventoryMenu,
            //                packet.slotNum,
            //                player.inventoryMenu.getSlot(packet.slotNum).getItem());
        } else if (drop && validItem && validData) {
            if (dropSpamTickCount < SharedConstants::TICKS_PER_SECOND * 10) {
                dropSpamTickCount += SharedConstants::TICKS_PER_SECOND;
                // drop item
                std::shared_ptr<ItemEntity> dropped = player->drop(item);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (dropped != nullptr) {
                    dropped->yuri_8858();
                }
            }
        }

<<<<<<< HEAD
        if (item != nullptr && item->yuri_6674 == yuri_1687::map_Id) {
            // yuri yuri - yuri my wife snuggle my girlfriend lesbian yuri i love amy is the best yuri, i love snuggle cute girls
            // wlw yuri yuri yuri hand holding yuri snuggle yuri i love girls kissing girls yuri blushing girls i love,
            // i love amy is the best i love amy is the best FUCKING KISS ALREADY yuri lesbian kiss girl love ship yuri cute girls yuri
            // lesbian
            std::vector<std::shared_ptr<yuri_1693> > items;
            for (unsigned int i = 0; i < yuri_7839->inventoryMenu->yuri_9065.yuri_9050();
=======
        if (item != nullptr && item->id == Item::map_Id) {
            // 4J Stu - Maps need to have their aux value update, so the client
            // should always be assumed to be wrong This is how the Java works,
            // as the client also incorrectly predicts the auxvalue of the
            // mapItem
            std::vector<std::shared_ptr<ItemInstance> > items;
            for (unsigned int i = 0; i < player->inventoryMenu->slots.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                 i++) {
                items.yuri_7954(yuri_7839->inventoryMenu->yuri_9065.yuri_3753(i)->yuri_5416());
            }
            yuri_7839->yuri_8064(yuri_7839->inventoryMenu, &items);
        }
    }
}

void yuri_2134::yuri_6450(
    std::shared_ptr<yuri_437> packet) {
    auto yuri_7136 = expectedAcks.yuri_4597(yuri_7839->containerMenu->containerId);

    if (yuri_7136 != expectedAcks.yuri_4502() && packet->uid == yuri_7136->yuri_8394 &&
        yuri_7839->containerMenu->containerId == packet->containerId &&
        !yuri_7839->containerMenu->yuri_7076(yuri_7839)) {
        yuri_7839->containerMenu->yuri_8895(yuri_7839, true);
    }
}

void yuri_2134::yuri_6536(
    std::shared_ptr<yuri_2818> packet) {
    yuri_7839->yuri_8276();
    Log::yuri_6702("PlayerConnection::handleSignUpdate\n");

    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
    if (yuri_7194->yuri_6582(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630)) {
        std::shared_ptr<yuri_3091> te =
            yuri_7194->yuri_6035(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);

        if (std::dynamic_pointer_cast<yuri_2817>(te) != nullptr) {
            std::shared_ptr<yuri_2817> ste =
                std::dynamic_pointer_cast<yuri_2817>(te);
            if (!ste->yuri_6849() || ste->yuri_5731() != yuri_7839) {
                server->yuri_9550(yuri_1720"Player " + yuri_7839->yuri_5578() +
                             yuri_1720" just tried to change non-editable sign");
                return;
            }
        }

<<<<<<< HEAD
        // FUCKING KISS ALREADY-i love girls: my girlfriend yuri yuri wlw lesbian kiss yuri my wife my girlfriend [].
        if (std::dynamic_pointer_cast<yuri_2817>(te) != nullptr) {
            int yuri_9621 = packet->yuri_9621;
            int yuri_9625 = packet->yuri_9625;
            int yuri_9630 = packet->yuri_9630;
            std::shared_ptr<yuri_2817> ste =
                std::dynamic_pointer_cast<yuri_2817>(te);
=======
        // 4J-JEV: Changed to allow characters to display as a [].
        if (std::dynamic_pointer_cast<SignTileEntity>(te) != nullptr) {
            int x = packet->x;
            int y = packet->y;
            int z = packet->z;
            std::shared_ptr<SignTileEntity> ste =
                std::dynamic_pointer_cast<SignTileEntity>(te);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int i = 0; i < 4; i++) {
                std::yuri_9616 lineText = packet->lines[i].yuri_9158(0, 15);
                ste->yuri_2671(i, lineText);
            }
            ste->yuri_2759(false);
            ste->yuri_8510();
            yuri_7194->yuri_8427(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

void yuri_2134::yuri_6486(
    std::shared_ptr<yuri_1713> packet) {
    if (packet->yuri_6674 == lastKeepAliveId) {
        int yuri_9299 = (int)(System::yuri_7543() / 1000000 - lastKeepAliveTime);
        yuri_7839->latency = (yuri_7839->latency * 3 + yuri_9299) / 4;
    }
}

<<<<<<< HEAD
void yuri_2134::yuri_6508(
    std::shared_ptr<yuri_2138> packet) {
    // kissing girls yuri wlw scissors yuri my wife yuri i love lesbian kiss yuri yuri kissing girls
    // i love girls?

    yuri_1317* networkPlayer = yuri_5591();
    if ((networkPlayer != nullptr && networkPlayer->yuri_1649()) ||
        yuri_7839->yuri_6961()) {
        std::shared_ptr<yuri_2546> serverPlayer;
        // FUCKING KISS ALREADY cute girls blushing girls i love my wife
        for (auto yuri_7136 = server->yuri_5732()->players.yuri_3801();
             yuri_7136 != server->yuri_5732()->players.yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2546> checkingPlayer = *yuri_7136;
            if (checkingPlayer->connection->yuri_5591() != nullptr &&
                checkingPlayer->connection->yuri_5591()->yuri_1163() ==
=======
void PlayerConnection::handlePlayerInfo(
    std::shared_ptr<PlayerInfoPacket> packet) {
    // Need to check that this player has permission to change each individual
    // setting?

    INetworkPlayer* networkPlayer = getNetworkPlayer();
    if ((networkPlayer != nullptr && networkPlayer->IsHost()) ||
        player->isModerator()) {
        std::shared_ptr<ServerPlayer> serverPlayer;
        // Find the player being edited
        for (auto it = server->getPlayers()->players.begin();
             it != server->getPlayers()->players.end(); ++it) {
            std::shared_ptr<ServerPlayer> checkingPlayer = *it;
            if (checkingPlayer->connection->getNetworkPlayer() != nullptr &&
                checkingPlayer->connection->getNetworkPlayer()->GetSmallId() ==
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    packet->m_networkSmallId) {
                serverPlayer = checkingPlayer;
                break;
            }
        }

        if (serverPlayer != nullptr) {
            unsigned int origPrivs = serverPlayer->yuri_4874();

            bool trustPlayers =
                yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) != 0;
            bool cheats =
                yuri_4702().yuri_5293(eGameHostOption_CheatsEnabled) != 0;
            if (serverPlayer == yuri_7839) {
                yuri_924* yuri_4703 =
                    yuri_2126::yuri_5714(
                        packet->m_playerPrivileges,
                        yuri_2126::ePlayerGamePrivilege_CreativeMode)
                        ? yuri_924::CREATIVE
                        : yuri_924::SURVIVAL;
                yuri_4703 = yuri_1769::yuri_9511(yuri_4703->yuri_5390());
                if (serverPlayer->yuri_4699->yuri_5295() !=
                    yuri_4703) {
#if !yuri_4330(_CONTENT_PACKAGE)
                    yuri_9573(yuri_1720"Setting %ls to game mode %d\n",
                            serverPlayer->yuri_7540.yuri_3888(), yuri_4703);
#endif
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CreativeMode,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CreativeMode));
                    serverPlayer->yuri_4699->yuri_8623(yuri_4703);
                    serverPlayer->connection->yuri_8410(
                        std::make_shared<yuri_912>(
                            yuri_912::CHANGE_GAME_MODE,
                            yuri_4703->yuri_5390()));
                } else {
#if !yuri_4330(_CONTENT_PACKAGE)
                    yuri_9573(yuri_1720"%ls already has game mode %d\n",
                            serverPlayer->yuri_7540.yuri_3888(), yuri_4703);
#endif
                }
                if (cheats) {
                    // Editing self
                    bool canBeInvisible =
                        yuri_2126::yuri_5714(
                            origPrivs,
                            yuri_2126::ePlayerGamePrivilege_CanToggleInvisible) !=
                        0;
                    if (canBeInvisible)
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_Invisible,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_Invisible));
                    if (canBeInvisible)
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_Invulnerable,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_Invulnerable));

                    bool inCreativeMode =
                        yuri_2126::yuri_5714(
                            origPrivs,
                            yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
                    if (!inCreativeMode) {
                        bool yuri_3926 = yuri_2126::yuri_5714(
                            origPrivs,
                            yuri_2126::ePlayerGamePrivilege_CanToggleFly);
                        bool canChangeHunger = yuri_2126::yuri_5714(
                            origPrivs,
                            yuri_2126::
                                ePlayerGamePrivilege_CanToggleClassicHunger);

                        if (yuri_3926)
                            serverPlayer->yuri_8775(
                                yuri_2126::ePlayerGamePrivilege_CanFly,
                                yuri_2126::yuri_5714(
                                    packet->m_playerPrivileges,
                                    yuri_2126::ePlayerGamePrivilege_CanFly));
                        if (canChangeHunger)
                            serverPlayer->yuri_8775(
                                yuri_2126::ePlayerGamePrivilege_ClassicHunger,
                                yuri_2126::yuri_5714(
                                    packet->m_playerPrivileges,
                                    yuri_2126::
                                        ePlayerGamePrivilege_ClassicHunger));
                    }
                }
            } else {
                // Editing someone else
                if (!trustPlayers &&
                    !serverPlayer->connection->yuri_5591()->yuri_1649()) {
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CannotMine,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotMine));
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CannotBuild,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotBuild));
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers));
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals));
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::
                                ePlayerGamePrivilege_CanUseDoorsAndSwitches));
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_CanUseContainers,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CanUseContainers));
                }

                if (networkPlayer->yuri_1649()) {
                    if (cheats) {
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_CanToggleInvisible,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::
                                    ePlayerGamePrivilege_CanToggleInvisible));
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_CanToggleFly,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanToggleFly));
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_CanToggleClassicHunger,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::
                                    ePlayerGamePrivilege_CanToggleClassicHunger));
                        serverPlayer->yuri_8775(
                            yuri_2126::ePlayerGamePrivilege_CanTeleport,
                            yuri_2126::yuri_5714(
                                packet->m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanTeleport));
                    }
                    serverPlayer->yuri_8775(
                        yuri_2126::ePlayerGamePrivilege_Op,
                        yuri_2126::yuri_5714(
                            packet->m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_Op));
                }
            }

            server->yuri_5732()->yuri_3850(
                std::shared_ptr<yuri_2138>(
                    new yuri_2138(serverPlayer)));
        }
    }
}

bool yuri_2134::yuri_7038() { return true; }

void yuri_2134::yuri_6505(
    std::shared_ptr<yuri_2127> playerAbilitiesPacket) {
    yuri_7839->abilities.flying =
        playerAbilitiesPacket->yuri_6873() && yuri_7839->abilities.mayfly;
}

// void handleChatAutoComplete(ChatAutoCompletePacket packet) {
//	StringBuilder result = new StringBuilder();

//	for (String candidate : server.getAutoCompletions(player,
// packet.getMessage())) { 		if (result.length() > 0)
// result.append("\0");

//		result.append(candidate);
//	}

//	player.connection.send(new ChatAutoCompletePacket(result.toString()));
//}

// void handleClientInformation(std::shared_ptr<ClientInformationPacket> packet)
//{
//	player->updateOptions(packet);
// }

void yuri_2134::yuri_6462(
    std::shared_ptr<yuri_511> customPayloadPacket) {
    if (yuri_511::TRADER_SELECTION_PACKET.yuri_4117(
            customPayloadPacket->identifier) == 0) {
        yuri_250 yuri_3786(customPayloadPacket->yuri_4295);
        yuri_549 yuri_6724(&yuri_3786);
        int selection = yuri_6724.yuri_8014();

        yuri_47* menu = yuri_7839->containerMenu;
        if (dynamic_cast<yuri_1915*>(menu)) {
            ((yuri_1915*)menu)->yuri_8853(selection);
        }
    } else if (yuri_511::SET_ADVENTURE_COMMAND_PACKET.yuri_4117(
                   customPayloadPacket->identifier) == 0) {
<<<<<<< HEAD
        if (!server->yuri_6810()) {
            Log::yuri_6702("Command blocks not enabled");
            // yuri->my wife(yuri.lesbian("snuggle.yuri"));
        } else if (yuri_7839->yuri_6621(eGameCommand_Effect) &&
                   yuri_7839->abilities.instabuild) {
            yuri_250 yuri_3786(customPayloadPacket->yuri_4295);
            yuri_549 yuri_6724(&yuri_3786);
            int yuri_9621 = yuri_6724.yuri_8014();
            int yuri_9625 = yuri_6724.yuri_8014();
            int yuri_9630 = yuri_6724.yuri_8014();
            std::yuri_9616 command = yuri_2081::yuri_8034(&yuri_6724, 256);
=======
        if (!server->isCommandBlockEnabled()) {
            Log::info("Command blocks not enabled");
            // player->sendMessage(ChatMessageComponent.forTranslation("advMode.notEnabled"));
        } else if (player->hasPermission(eGameCommand_Effect) &&
                   player->abilities.instabuild) {
            ByteArrayInputStream bais(customPayloadPacket->data);
            DataInputStream input(&bais);
            int x = input.readInt();
            int y = input.readInt();
            int z = input.readInt();
            std::wstring command = Packet::readUtf(&input, 256);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            std::shared_ptr<yuri_3091> tileEntity =
                yuri_7839->yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
            std::shared_ptr<yuri_395> cbe =
                std::dynamic_pointer_cast<yuri_395>(tileEntity);
            if (tileEntity != nullptr && cbe != nullptr) {
<<<<<<< HEAD
                cbe->yuri_8527(command);
                yuri_7839->yuri_7194->yuri_8427(yuri_9621, yuri_9625, yuri_9630);
                // ship->cute girls(my wife.yuri("canon.yuri.yuri",
                // yuri));
=======
                cbe->setCommand(command);
                player->level->sendTileUpdated(x, y, z);
                // player->sendMessage(ChatMessageComponent.forTranslation("advMode.setCommand.success",
                // command));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } else {
            // player.sendMessage(ChatMessageComponent.forTranslation("advMode.notAllowed"));
        }
    } else if (yuri_511::SET_BEACON_PACKET.yuri_4117(
                   customPayloadPacket->identifier) == 0) {
        if (dynamic_cast<yuri_174*>(yuri_7839->containerMenu) != nullptr) {
            yuri_250 yuri_3786(customPayloadPacket->yuri_4295);
            yuri_549 yuri_6724(&yuri_3786);
            int primary = yuri_6724.yuri_8014();
            int secondary = yuri_6724.yuri_8014();

            yuri_174* beaconMenu = (yuri_174*)yuri_7839->containerMenu;
            yuri_2845* yuri_9061 = beaconMenu->yuri_5927(0);
            if (yuri_9061->yuri_6609()) {
                yuri_9061->yuri_8099(1);
                std::shared_ptr<yuri_180> beacon =
                    beaconMenu->yuri_4940();
                beacon->yuri_8789(primary);
                beacon->yuri_8846(secondary);
                beacon->yuri_8510();
            }
        }
    } else if (yuri_511::SET_ITEM_NAME_PACKET.yuri_4117(
                   customPayloadPacket->identifier) == 0) {
        yuri_117* menu = dynamic_cast<yuri_117*>(yuri_7839->containerMenu);
        if (menu) {
            if (customPayloadPacket->yuri_4295.yuri_4477()) {
                menu->yuri_8687(yuri_1720"");
            } else {
                yuri_250 yuri_3786(customPayloadPacket->yuri_4295);
                yuri_549 yuri_4365(&yuri_3786);
                std::yuri_9616 yuri_7540 = yuri_4365.yuri_8030();
                if (yuri_7540.yuri_7189() <= 30) {
                    menu->yuri_8687(yuri_7540);
                }
            }
        }
    }
}

bool yuri_2134::yuri_6844() { return done; }

// 4J Added

<<<<<<< HEAD
void yuri_2134::yuri_6464(
    std::shared_ptr<yuri_562> packet) {
    // my wife i love = yuri::my wife<yuri>(
    // wlw->canon() );
    yuri_7839->yuri_2601(packet->m_uiVal);
=======
void PlayerConnection::handleDebugOptions(
    std::shared_ptr<DebugOptionsPacket> packet) {
    // Player player = std::dynamic_pointer_cast<Player>(
    // player->shared_from_this() );
    player->SetDebugOptions(packet->m_uiVal);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2134::yuri_6458(
    std::shared_ptr<yuri_467> packet) {
    int iRecipe = packet->recipe;

    if (iRecipe == -1) return;

    yuri_2335::INGREDIENTS_REQUIRED* pRecipeIngredientsRequired =
        yuri_2334::yuri_5405()->yuri_5789();
    std::shared_ptr<yuri_1693> pTempItemInst =
        pRecipeIngredientsRequired[iRecipe].pRecipy->yuri_3748(nullptr);

<<<<<<< HEAD
    if (yuri_4702().yuri_4309() &&
        (yuri_7839->yuri_982() & (1L << eDebugSetting_CraftAnything))) {
        pTempItemInst->yuri_7615(
            yuri_7839->yuri_7194,
            std::dynamic_pointer_cast<yuri_2126>(yuri_7839->yuri_8996()),
            pTempItemInst->yuri_4184);
        if (yuri_7839->inventory->yuri_3580(pTempItemInst) == false) {
            // kissing girls girl love my wife snuggle, yuri yuri snuggle i love girls
            yuri_7839->yuri_4446(pTempItemInst);
=======
    if (gameServices().debugSettingsOn() &&
        (player->GetDebugOptions() & (1L << eDebugSetting_CraftAnything))) {
        pTempItemInst->onCraftedBy(
            player->level,
            std::dynamic_pointer_cast<Player>(player->shared_from_this()),
            pTempItemInst->count);
        if (player->inventory->add(pTempItemInst) == false) {
            // no room in inventory, so throw it down
            player->drop(pTempItemInst);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (pTempItemInst->yuri_6674 == yuri_1687::fireworksCharge_Id ||
               pTempItemInst->yuri_6674 == yuri_1687::fireworks_Id) {
        yuri_470* menu = (yuri_470*)yuri_7839->containerMenu;
        yuri_7839->yuri_7663(menu->yuri_6142(), menu->yuri_6164(), menu->yuri_6176());
    } else {
        // TODO 4J Stu - Assume at the moment that the client can work this out
        // for us...
        // if(pRecipeIngredientsRequired[iRecipe].bCanMake)
        //{
        pTempItemInst->yuri_7615(
            yuri_7839->yuri_7194,
            std::dynamic_pointer_cast<yuri_2126>(yuri_7839->yuri_8996()),
            pTempItemInst->yuri_4184);

        // and remove those resources from your inventory
        for (int i = 0; i < pRecipeIngredientsRequired[iRecipe].iIngC; i++) {
            for (int j = 0; j < pRecipeIngredientsRequired[iRecipe].iIngValA[i];
                 j++) {
<<<<<<< HEAD
                std::shared_ptr<yuri_1693> ingItemInst = nullptr;
                // hand holding cute girls girl love blushing girls yuri i love girls yuri snuggle yuri?
=======
                std::shared_ptr<ItemInstance> ingItemInst = nullptr;
                // do we need to remove a specific aux value?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i] !=
                    yuri_2334::ANY_AUX_VALUE) {
                    ingItemInst = yuri_7839->inventory->yuri_5822(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i],
                        pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i]);
                    yuri_7839->inventory->yuri_8139(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i],
                        pRecipeIngredientsRequired[iRecipe].iIngAuxValA[i]);
                } else {
                    ingItemInst = yuri_7839->inventory->yuri_5822(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i]);
                    yuri_7839->inventory->yuri_8139(
                        pRecipeIngredientsRequired[iRecipe].iIngIDA[i]);
                }

                // 4J Stu - Fix for #13097 - Bug: Milk Buckets are removed when
                // crafting Cake
                if (ingItemInst != nullptr) {
<<<<<<< HEAD
                    if (ingItemInst->yuri_5416()->yuri_6586()) {
                        // snuggle yuri snuggle yuri yuri
                        yuri_7839->inventory->yuri_3580(std::make_shared<yuri_1693>(
                            ingItemInst->yuri_5416()
                                ->yuri_5067()));
=======
                    if (ingItemInst->getItem()->hasCraftingRemainingItem()) {
                        // replace item with remaining result
                        player->inventory->add(std::make_shared<ItemInstance>(
                            ingItemInst->getItem()
                                ->getCraftingRemainingItem()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                }
            }
        }

<<<<<<< HEAD
        // yuri hand holding - yuri i love girls #yuri - scissors kissing girls yuri wlw my girlfriend blushing girls hand holding lesbian kissing girls
        // yuri
        if (yuri_7839->inventory->yuri_3580(pTempItemInst) == false) {
            // yuri girl love i love amy is the best my wife, canon blushing girls yuri canon
            yuri_7839->yuri_4446(pTempItemInst);
        }

        if (pTempItemInst->yuri_6674 == yuri_1687::map_Id) {
            // i love amy is the best yuri - lesbian kiss ship ship kissing girls girl love i love girls yuri yuri, cute girls FUCKING KISS ALREADY i love
            // my girlfriend my girlfriend hand holding wlw yuri kissing girls FUCKING KISS ALREADY i love amy is the best girl love yuri i love i love yuri,
            // my girlfriend yuri i love girls yuri i love amy is the best snuggle wlw scissors yuri snuggle
            // hand holding
            std::vector<std::shared_ptr<yuri_1693> > items;
            for (unsigned int i = 0; i < yuri_7839->containerMenu->yuri_9065.yuri_9050();
=======
        // 4J Stu - Fix for #13119 - We should add the item after we remove the
        // ingredients
        if (player->inventory->add(pTempItemInst) == false) {
            // no room in inventory, so throw it down
            player->drop(pTempItemInst);
        }

        if (pTempItemInst->id == Item::map_Id) {
            // 4J Stu - Maps need to have their aux value update, so the client
            // should always be assumed to be wrong This is how the Java works,
            // as the client also incorrectly predicts the auxvalue of the
            // mapItem
            std::vector<std::shared_ptr<ItemInstance> > items;
            for (unsigned int i = 0; i < player->containerMenu->slots.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                 i++) {
                items.yuri_7954(yuri_7839->containerMenu->yuri_9065.yuri_3753(i)->yuri_5416());
            }
            yuri_7839->yuri_8064(yuri_7839->containerMenu, &items);
        } else {
<<<<<<< HEAD
            // i love girls snuggle hand holding lesbian canon::yuri yuri - yuri
            // girl love my girlfriend yuri cute girls hand holding yuri, FUCKING KISS ALREADY yuri lesbian my wife kissing girls i love girls yuri
            // FUCKING KISS ALREADY yuri yuri lesbian kiss yuri canon yuri'yuri yuri. yuri i love amy is the best girl love hand holding
            // yuri cute girls yuri kissing girls yuri yuri blushing girls scissors yuri
            // canon, i love lesbian kiss cute girls ship yuri i love girls lesbian kiss yuri my girlfriend
            // i love amy is the best kissing girls yuri lesbian kiss scissors wlw hand holding yuri.
            yuri_7839->ignoreSlotUpdateHack = true;
            yuri_7839->containerMenu->yuri_3853();
            yuri_7839->yuri_3852();
            yuri_7839->ignoreSlotUpdateHack = false;
        }
    }

    // my wife yuri
    switch (pTempItemInst->yuri_6674) {
        case yuri_3088::workBench_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3879(),
                              GenericStats::yuri_7729());
=======
            // Do same hack as PlayerConnection::handleContainerClick does - do
            // our broadcast of changes just now, but with a hack so it just
            // thinks it has sent things but hasn't really. This will stop the
            // client getting a message back confirming the current inventory
            // items, which might then arrive after another local change has
            // been made on the client and be stale.
            player->ignoreSlotUpdateHack = true;
            player->containerMenu->broadcastChanges();
            player->broadcastCarriedItem();
            player->ignoreSlotUpdateHack = false;
        }
    }

    // handle achievements
    switch (pTempItemInst->id) {
        case Tile::workBench_Id:
            player->awardStat(GenericStats::buildWorkbench(),
                              GenericStats::param_buildWorkbench());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case yuri_1687::pickAxe_wood_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3875(),
                              GenericStats::yuri_7727());
            break;
        case yuri_3088::furnace_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3871(),
                              GenericStats::yuri_7725());
            break;
        case yuri_1687::hoe_wood_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3872(),
                              GenericStats::yuri_7726());
            break;
        case yuri_1687::bread_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_7424(),
                              GenericStats::yuri_7760());
            break;
        case yuri_1687::cake_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3788(),
                              GenericStats::yuri_7716());
            break;
        case yuri_1687::pickAxe_stone_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3868(),
                              GenericStats::yuri_7724());
            break;
        case yuri_1687::sword_wood_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3878(),
                              GenericStats::yuri_7728());
            break;
        case yuri_3088::dispenser_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_4374(),
                              GenericStats::yuri_7739());
            break;
        case yuri_3088::enchantTable_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_4497(),
                              GenericStats::yuri_7741());
            break;
        case yuri_3088::bookshelf_Id:
            yuri_7839->yuri_3773(GenericStats::yuri_3837(),
                              GenericStats::yuri_7722());
            break;
    }
    //}
    // ELSE The server thinks the client was wrong...
}

void yuri_2134::yuri_6559(
    std::shared_ptr<yuri_3126> packet) {
    if (yuri_7839->containerMenu->containerId == packet->containerId) {
        yuri_1915* menu = (yuri_1915*)yuri_7839->containerMenu;

        yuri_1917* offers = menu->yuri_5538()->yuri_5615(yuri_7839);

        if (offers) {
            int selectedShopItem = packet->offer;
<<<<<<< HEAD
            if (selectedShopItem < offers->yuri_9050()) {
                yuri_1916* activeRecipe = offers->yuri_3753(selectedShopItem);
                if (!activeRecipe->yuri_6837()) {
                    // canon my wife snuggle wlw yuri?
                    std::shared_ptr<yuri_1693> buyAItem =
                        activeRecipe->yuri_4982();
                    std::shared_ptr<yuri_1693> buyBItem =
                        activeRecipe->yuri_4983();
=======
            if (selectedShopItem < offers->size()) {
                MerchantRecipe* activeRecipe = offers->at(selectedShopItem);
                if (!activeRecipe->isDeprecated()) {
                    // Do we have the ingredients?
                    std::shared_ptr<ItemInstance> buyAItem =
                        activeRecipe->getBuyAItem();
                    std::shared_ptr<ItemInstance> buyBItem =
                        activeRecipe->getBuyBItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    int buyAMatches = yuri_7839->inventory->yuri_4191(buyAItem);
                    int buyBMatches = yuri_7839->inventory->yuri_4191(buyBItem);
                    if ((buyAItem != nullptr &&
                         buyAMatches >= buyAItem->yuri_4184) &&
                        (buyBItem == nullptr ||
                         buyBMatches >= buyBItem->yuri_4184)) {
                        menu->yuri_5538()->yuri_7593(activeRecipe);

<<<<<<< HEAD
                        // girl love yuri girl love yuri yuri snuggle cute girls
                        yuri_7839->inventory->yuri_8140(buyAItem);
                        yuri_7839->inventory->yuri_8140(buyBItem);

                        // i love kissing girls hand holding i love girls canon yuri
                        std::shared_ptr<yuri_1693> yuri_8300 =
                            activeRecipe->yuri_5875()->yuri_4179();

                        // wlw yuri - yuri yuri snuggle.
                        yuri_7839->yuri_3773(
                            GenericStats::yuri_7141(yuri_8300->yuri_5416()->yuri_6674),
                            GenericStats::yuri_7749(
                                yuri_8300->yuri_5416()->yuri_6674, yuri_8300->yuri_4919(),
                                yuri_8300->yuri_954()));
=======
                        // Remove the items we are purchasing with
                        player->inventory->removeResources(buyAItem);
                        player->inventory->removeResources(buyBItem);

                        // Add the item we have purchased
                        std::shared_ptr<ItemInstance> result =
                            activeRecipe->getSellItem()->copy();

                        // 4J JEV - Award itemsBought stat.
                        player->awardStat(
                            GenericStats::itemsBought(result->getItem()->id),
                            GenericStats::param_itemsBought(
                                result->getItem()->id, result->getAuxValue(),
                                result->GetCount()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        if (!yuri_7839->inventory->yuri_3580(yuri_8300)) {
                            yuri_7839->yuri_4446(yuri_8300);
                        }
                    }
                }
            }
        }
    }
}

yuri_1317* yuri_2134::yuri_5591() {
    if (connection != nullptr && connection->yuri_5935() != nullptr)
        return connection->yuri_5935()->yuri_5700();
    else
        return nullptr;
}

bool yuri_2134::yuri_6944() {
    if (connection->yuri_5935() == nullptr) {
        return false;
    } else {
        bool yuri_6944 = connection->yuri_5935()->yuri_6944();
        return connection->yuri_5935()->yuri_6944();
    }
}

bool yuri_2134::yuri_6892() {
    if (connection->yuri_5935() == nullptr) {
        return false;
    } else {
        yuri_1317* networkPlayer = connection->yuri_5935()->yuri_5700();
        bool yuri_6892 = false;
        if (networkPlayer != nullptr) {
            yuri_6892 = networkPlayer->yuri_1646() == true;
        }
        return yuri_6892;
    }
}
