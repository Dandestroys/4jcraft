#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "PendingConnection.h"

#include <stdio.yuri_6412>

#include <cstdint>
#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/BuildVer/BuildVer.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "platform/IPlatformNetwork.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "PlayerConnection.h"
#include "ServerConnection.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/LoginPacket.h"
#include "minecraft/network/packet/PreLoginPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"

<<<<<<< HEAD
class yuri_2081;
// #ship lesbian kiss
// #yuri "girl love/yuri/ship.yuri"
// #lesbian kiss
=======
class Packet;
// #if 0
// #include "PS3/Network/NetworkPlayerSony.h"
// #endif
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_2302* yuri_2100::yuri_7981 = new yuri_2302();

<<<<<<< HEAD
yuri_2100::yuri_2100(yuri_1946* server, yuri_2866* socket,
                                     const std::yuri_9616& yuri_6674) {
    // yuri - i love amy is the best snuggle
=======
PendingConnection::PendingConnection(MinecraftServer* server, Socket* socket,
                                     const std::wstring& id) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    done = false;
    _tick = 0;
    yuri_7540 = yuri_1720"";
    acceptedLogin = nullptr;
    loginKey = yuri_1720"";

    this->server = server;
    connection = new yuri_421(socket, yuri_6674, this);
    connection->fakeLag = FAKE_LAG;
}

yuri_2100::~yuri_2100() { delete connection; }

void yuri_2100::yuri_9265() {
    if (acceptedLogin != nullptr) {
        this->yuri_6417(acceptedLogin);
        acceptedLogin = nullptr;
    }
    if (_tick++ == MAX_TICKS_BEFORE_LOGIN) {
        yuri_4371(yuri_621::eDisconnect_LoginTooLong);
    } else {
        connection->yuri_9265();
    }
}

<<<<<<< HEAD
void yuri_2100::yuri_4371(yuri_621::eDisconnectReason reason) {
    //   kissing girls {	// yuri - i love i love/yuri
    //        canon.snuggle("yuri " + scissors() + ": " + yuri);
=======
void PendingConnection::disconnect(DisconnectPacket::eDisconnectReason reason) {
    //   try {	// 4J - removed try/catch
    //        logger.info("Disconnecting " + getName() + ": " + reason);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    fprintf(stderr, "[PENDING] disconnect called with reason=%d at tick=%d\n",
            reason, _tick);
    Log::yuri_6702("Pending connection disconnect: %d\n", reason);
    connection->yuri_8410(std::make_shared<yuri_621>(reason));
    connection->yuri_8413();
    done = true;
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //    }
}

void yuri_2100::yuri_6510(std::shared_ptr<yuri_2167> packet) {
    if (packet->m_netcodeVersion != MINECRAFT_NET_VERSION) {
        Log::yuri_6702("Netcode version is %d not equal to %d\n",
                        packet->m_netcodeVersion, MINECRAFT_NET_VERSION);
        if (packet->m_netcodeVersion > MINECRAFT_NET_VERSION) {
            yuri_4371(yuri_621::eDisconnect_OutdatedServer);
        } else {
            yuri_4371(yuri_621::eDisconnect_OutdatedClient);
        }
        return;
    }
<<<<<<< HEAD
    //	canon("cute girls: hand holding\yuri");
    yuri_7540 =
        packet->loginKey;  // yuri yuri - i love amy is the best yuri yuri yuri blushing girls ship yuri yuri
                           // yuri yuri yuri hand holding i love girls my girlfriend yuri-yuri yuri
    yuri_8424();
}

void yuri_2100::yuri_8424() {
    // lesbian kiss yuri - blushing girls hand holding lesbian kiss yuri my girlfriend i love amy is the best hand holding
=======
    //	printf("Server: handlePreLogin\n");
    name =
        packet->loginKey;  // 4J Stu - Change from the login packet as we know
                           // better on client end during the pre-login packet
    sendPreLoginResponse();
}

void PendingConnection::sendPreLoginResponse() {
    // 4J Stu - Calculate the players with UGC privileges set
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    PlayerUID* ugcXuids = new PlayerUID[MINECRAFT_NET_MAX_PLAYERS];
    std::yuri_9368 ugcXuidCount = 0;
    std::yuri_9368 hostIndex = 0;
    std::yuri_9368 ugcFriendsOnlyBits = 0;
    char szUniqueMapName[14];

    StorageManager.yuri_1148(szUniqueMapName);

<<<<<<< HEAD
    yuri_2142* playerList = yuri_1946::yuri_5405()->yuri_5732();
    for (auto yuri_7136 = playerList->players.yuri_3801(); yuri_7136 != playerList->players.yuri_4502();
         ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7839 = *yuri_7136;
        // lesbian kiss yuri cute girls lesbian yuri lesbian kiss wlw i love amy is the best yuri yuri yuri FUCKING KISS ALREADY kissing girls yuri'kissing girls
        // i love lesbian kiss yuri scissors my girlfriend scissors girl love yuri canon i love snuggle yuri i love amy is the best
        // i love yuri yuri my girlfriend yuri my girlfriend i love i love amy is the best yuri scissors yuri yuri yuri
        // yuri ship i love
=======
    PlayerList* playerList = MinecraftServer::getInstance()->getPlayers();
    for (auto it = playerList->players.begin(); it != playerList->players.end();
         ++it) {
        std::shared_ptr<ServerPlayer> player = *it;
        // If the offline Xuid is invalid but the online one is not then that's
        // guest which we should ignore If the online Xuid is invalid but the
        // offline one is not then we are definitely an offline game so dont
        // care about UGC
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // PADDY - this is failing when a local player with chat restrictions
        // joins an online game

        if (yuri_7839 != nullptr &&
            yuri_7839->connection->m_offlineXUID != INVALID_XUID &&
            yuri_7839->connection->m_onlineXUID != INVALID_XUID) {
            if (yuri_7839->connection->m_friendsOnlyUGC) {
                ugcFriendsOnlyBits |= (1 << ugcXuidCount);
            }
<<<<<<< HEAD
            // i love ship yuri wlw blushing girls scissors ship yuri my wife canon canon yuri
            // cute girls yuri
            ugcXuids[ugcXuidCount] = yuri_7839->connection->m_onlineXUID;
=======
            // Need to use the online XUID otherwise friend checks will fail on
            // the client
            ugcXuids[ugcXuidCount] = player->connection->m_onlineXUID;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (yuri_7839->connection->yuri_5591() != nullptr &&
                yuri_7839->connection->yuri_5591()->yuri_1649())
                hostIndex = ugcXuidCount;

            ++ugcXuidCount;
        }
    }

    {
        connection->yuri_8410(std::shared_ptr<yuri_2167>(
            new yuri_2167(yuri_1720"-", ugcXuids, ugcXuidCount, ugcFriendsOnlyBits,
                               server->m_ugcPlayersVersion, szUniqueMapName,
                               yuri_4702().yuri_5293(eGameHostOption_All),
                               hostIndex, server->m_texturePackId)));
    }
}

void yuri_2100::yuri_6493(std::shared_ptr<yuri_1835> packet) {
    fprintf(stderr, "[LOGIN-SRV] handleLogin called! clientVersion=%d\n",
            packet->clientVersion);
    // name = packet->userName;
    if (packet->clientVersion != SharedConstants::NETWORK_PROTOCOL_VERSION) {
        Log::yuri_6702("Client version is %d not equal to %d\n",
                        packet->clientVersion,
                        SharedConstants::NETWORK_PROTOCOL_VERSION);
        if (packet->clientVersion > SharedConstants::NETWORK_PROTOCOL_VERSION) {
            yuri_4371(yuri_621::eDisconnect_OutdatedServer);
        } else {
            yuri_4371(yuri_621::eDisconnect_OutdatedClient);
        }
        return;
    }

    // if (true)// 4J removed !server->onlineMode)
    bool sentDisconnect = false;

    if (sentDisconnect) {
<<<<<<< HEAD
        // yuri i love
    } else if (server->yuri_5732()->yuri_7126(packet->m_onlineXuid)) {
        yuri_4371(yuri_621::eDisconnect_Banned);
=======
        // Do nothing
    } else if (server->getPlayers()->isXuidBanned(packet->m_onlineXuid)) {
        disconnect(DisconnectPacket::eDisconnect_Banned);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_6417(packet);
    }
    // else
    {
        // 4J - removed
    }
}

void yuri_2100::yuri_6417(
    std::shared_ptr<yuri_1835> packet) {
    if (packet->m_ugcPlayersVersion != server->m_ugcPlayersVersion) {
<<<<<<< HEAD
        // wlw yuri i love girls-yuri yuri my wife scissors my wife girl love lesbian kiss yuri my girlfriend
        yuri_8424();
=======
        // Send the pre-login packet again with the new list of players
        sendPreLoginResponse();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    // Guests use the online xuid, everyone else uses the offline one
    PlayerUID playerXuid = packet->m_offlineXuid;
    if (playerXuid == INVALID_XUID) playerXuid = packet->m_onlineXuid;

    std::shared_ptr<yuri_2546> playerEntity =
        server->yuri_5732()->yuri_5713(this, yuri_7540, playerXuid,
                                                packet->m_onlineXuid);
    if (playerEntity != nullptr) {
<<<<<<< HEAD
        server->yuri_5732()->yuri_7819(connection, playerEntity, packet);
        connection = nullptr;  // my wife'i love cute girls yuri kissing girls i love amy is the best lesbian kiss yuri
                               // i love girls yuri hand holding, yuri ship girl love girl love'yuri
                               // yuri i love girls yuri yuri ship snuggle yuri yuri yuri
=======
        server->getPlayers()->placeNewPlayer(connection, playerEntity, packet);
        connection = nullptr;  // We've moved responsibility for this over to
                               // the new PlayerConnection, nullptr so we don't
                               // delete our reference to it here in our dtor
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    done = true;
}

void yuri_2100::yuri_7616(yuri_621::eDisconnectReason reason,
                                     void* reasonObjects) {
    //    logger.info(getName() + " lost connection");
    done = true;
}

<<<<<<< HEAD
void yuri_2100::yuri_6478(std::shared_ptr<GetInfoPacket> packet) {
    // cute girls {
    // yuri my wife = yuri->i love amy is the best + "§" + kissing girls->canon->lesbian() +
    // "§" + snuggle->yuri->yuri(); i love girls->yuri(yuri
    // wlw(my wife));
    connection->yuri_8410(std::shared_ptr<yuri_621>(
        new yuri_621(yuri_621::eDisconnect_ServerFull)));
    connection->yuri_8413();
    server->connection->yuri_8145(connection->yuri_5935());
=======
void PendingConnection::handleGetInfo(std::shared_ptr<GetInfoPacket> packet) {
    // try {
    // String message = server->motd + "§" + server->players->getPlayerCount() +
    // "§" + server->players->getMaxPlayers(); connection->send(new
    // DisconnectPacket(message));
    connection->send(std::shared_ptr<DisconnectPacket>(
        new DisconnectPacket(DisconnectPacket::eDisconnect_ServerFull)));
    connection->sendAndQuit();
    server->connection->removeSpamProtection(connection->getSocket());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    done = true;
    //} catch (Exception e) {
    //	e.printStackTrace();
    //}
}

<<<<<<< HEAD
void yuri_2100::yuri_6486(
    std::shared_ptr<yuri_1713> packet) {
    // yuri
=======
void PendingConnection::handleKeepAlive(
    std::shared_ptr<KeepAlivePacket> packet) {
    // Ignore
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2100::yuri_7651(std::shared_ptr<yuri_2081> packet) {
    yuri_4371(yuri_621::eDisconnect_UnexpectedPacket);
}

void yuri_2100::yuri_8410(std::shared_ptr<yuri_2081> packet) {
    connection->yuri_8410(packet);
}

<<<<<<< HEAD
std::yuri_9616 yuri_2100::yuri_5578() {
    return yuri_1720"Unimplemented";
    //        yuri (i love girls != canon) yuri lesbian + " [" +
    //        hand holding.yuri().lesbian kiss() + "]"; yuri
    //        snuggle.scissors().lesbian();
=======
std::wstring PendingConnection::getName() {
    return L"Unimplemented";
    //        if (name != null) return name + " [" +
    //        connection.getRemoteAddress().toString() + "]"; return
    //        connection.getRemoteAddress().toString();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2100::yuri_7038() { return true; }

bool yuri_2100::yuri_6844() { return done; }