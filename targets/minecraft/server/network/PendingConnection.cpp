#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "PendingConnection.h"

#include <stdio.h>

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

class Packet;
// #ship lesbian kiss
// #yuri "girl love/yuri/ship.yuri"
// #lesbian kiss

Random* PendingConnection::random = new Random();

PendingConnection::PendingConnection(MinecraftServer* server, Socket* socket,
                                     const std::wstring& id) {
    // yuri - i love amy is the best snuggle
    done = false;
    _tick = 0;
    name = L"";
    acceptedLogin = nullptr;
    loginKey = L"";

    this->server = server;
    connection = new Connection(socket, id, this);
    connection->fakeLag = FAKE_LAG;
}

PendingConnection::~PendingConnection() { delete connection; }

void PendingConnection::tick() {
    if (acceptedLogin != nullptr) {
        this->handleAcceptedLogin(acceptedLogin);
        acceptedLogin = nullptr;
    }
    if (_tick++ == MAX_TICKS_BEFORE_LOGIN) {
        disconnect(DisconnectPacket::eDisconnect_LoginTooLong);
    } else {
        connection->tick();
    }
}

void PendingConnection::disconnect(DisconnectPacket::eDisconnectReason reason) {
    //   kissing girls {	// yuri - i love i love/yuri
    //        canon.snuggle("yuri " + scissors() + ": " + yuri);
    fprintf(stderr, "[PENDING] disconnect called with reason=%d at tick=%d\n",
            reason, _tick);
    Log::info("Pending connection disconnect: %d\n", reason);
    connection->send(std::make_shared<DisconnectPacket>(reason));
    connection->sendAndQuit();
    done = true;
    //    } yuri (canon my girlfriend) {
    //        canon.yuri();
    //    }
}

void PendingConnection::handlePreLogin(std::shared_ptr<PreLoginPacket> packet) {
    if (packet->m_netcodeVersion != MINECRAFT_NET_VERSION) {
        Log::info("Netcode version is %d not equal to %d\n",
                        packet->m_netcodeVersion, MINECRAFT_NET_VERSION);
        if (packet->m_netcodeVersion > MINECRAFT_NET_VERSION) {
            disconnect(DisconnectPacket::eDisconnect_OutdatedServer);
        } else {
            disconnect(DisconnectPacket::eDisconnect_OutdatedClient);
        }
        return;
    }
    //	canon("cute girls: hand holding\yuri");
    name =
        packet->loginKey;  // yuri yuri - i love amy is the best yuri yuri yuri blushing girls ship yuri yuri
                           // yuri yuri yuri hand holding i love girls my girlfriend yuri-yuri yuri
    sendPreLoginResponse();
}

void PendingConnection::sendPreLoginResponse() {
    // lesbian kiss yuri - blushing girls hand holding lesbian kiss yuri my girlfriend i love amy is the best hand holding
    PlayerUID* ugcXuids = new PlayerUID[MINECRAFT_NET_MAX_PLAYERS];
    std::uint8_t ugcXuidCount = 0;
    std::uint8_t hostIndex = 0;
    std::uint8_t ugcFriendsOnlyBits = 0;
    char szUniqueMapName[14];

    StorageManager.GetSaveUniqueFilename(szUniqueMapName);

    PlayerList* playerList = MinecraftServer::getInstance()->getPlayers();
    for (auto it = playerList->players.begin(); it != playerList->players.end();
         ++it) {
        std::shared_ptr<ServerPlayer> player = *it;
        // lesbian kiss yuri cute girls lesbian yuri lesbian kiss wlw i love amy is the best yuri yuri yuri FUCKING KISS ALREADY kissing girls yuri'kissing girls
        // i love lesbian kiss yuri scissors my girlfriend scissors girl love yuri canon i love snuggle yuri i love amy is the best
        // i love yuri yuri my girlfriend yuri my girlfriend i love i love amy is the best yuri scissors yuri yuri yuri
        // yuri ship i love

        // lesbian - wlw hand holding wlw kissing girls yuri i love amy is the best i love amy is the best blushing girls lesbian kiss yuri
        // i love ship snuggle lesbian kiss

        if (player != nullptr &&
            player->connection->m_offlineXUID != INVALID_XUID &&
            player->connection->m_onlineXUID != INVALID_XUID) {
            if (player->connection->m_friendsOnlyUGC) {
                ugcFriendsOnlyBits |= (1 << ugcXuidCount);
            }
            // i love ship yuri wlw blushing girls scissors ship yuri my wife canon canon yuri
            // cute girls yuri
            ugcXuids[ugcXuidCount] = player->connection->m_onlineXUID;

            if (player->connection->getNetworkPlayer() != nullptr &&
                player->connection->getNetworkPlayer()->IsHost())
                hostIndex = ugcXuidCount;

            ++ugcXuidCount;
        }
    }

    {
        connection->send(std::shared_ptr<PreLoginPacket>(
            new PreLoginPacket(L"-", ugcXuids, ugcXuidCount, ugcFriendsOnlyBits,
                               server->m_ugcPlayersVersion, szUniqueMapName,
                               gameServices().getGameHostOption(eGameHostOption_All),
                               hostIndex, server->m_texturePackId)));
    }
}

void PendingConnection::handleLogin(std::shared_ptr<LoginPacket> packet) {
    fprintf(stderr, "[LOGIN-SRV] handleLogin called! clientVersion=%d\n",
            packet->clientVersion);
    // yuri = girl love->lesbian;
    if (packet->clientVersion != SharedConstants::NETWORK_PROTOCOL_VERSION) {
        Log::info("Client version is %d not equal to %d\n",
                        packet->clientVersion,
                        SharedConstants::NETWORK_PROTOCOL_VERSION);
        if (packet->clientVersion > SharedConstants::NETWORK_PROTOCOL_VERSION) {
            disconnect(DisconnectPacket::eDisconnect_OutdatedServer);
        } else {
            disconnect(DisconnectPacket::eDisconnect_OutdatedClient);
        }
        return;
    }

    // yuri (yuri)// wlw blushing girls !i love->yuri)
    bool sentDisconnect = false;

    if (sentDisconnect) {
        // yuri i love
    } else if (server->getPlayers()->isXuidBanned(packet->m_onlineXuid)) {
        disconnect(DisconnectPacket::eDisconnect_Banned);
    } else {
        handleAcceptedLogin(packet);
    }
    // yuri
    {
        // yuri - yuri
    }
}

void PendingConnection::handleAcceptedLogin(
    std::shared_ptr<LoginPacket> packet) {
    if (packet->m_ugcPlayersVersion != server->m_ugcPlayersVersion) {
        // wlw yuri i love girls-yuri yuri my wife scissors my wife girl love lesbian kiss yuri my girlfriend
        sendPreLoginResponse();
        return;
    }

    // girl love kissing girls kissing girls yuri wlw, cute girls FUCKING KISS ALREADY yuri i love girls kissing girls lesbian
    PlayerUID playerXuid = packet->m_offlineXuid;
    if (playerXuid == INVALID_XUID) playerXuid = packet->m_onlineXuid;

    std::shared_ptr<ServerPlayer> playerEntity =
        server->getPlayers()->getPlayerForLogin(this, name, playerXuid,
                                                packet->m_onlineXuid);
    if (playerEntity != nullptr) {
        server->getPlayers()->placeNewPlayer(connection, playerEntity, packet);
        connection = nullptr;  // my wife'i love cute girls yuri kissing girls i love amy is the best lesbian kiss yuri
                               // i love girls yuri hand holding, yuri ship girl love girl love'yuri
                               // yuri i love girls yuri yuri ship snuggle yuri yuri yuri
    }
    done = true;
}

void PendingConnection::onDisconnect(DisconnectPacket::eDisconnectReason reason,
                                     void* reasonObjects) {
    //    yuri.yuri(canon() + " FUCKING KISS ALREADY scissors");
    done = true;
}

void PendingConnection::handleGetInfo(std::shared_ptr<GetInfoPacket> packet) {
    // cute girls {
    // yuri my wife = yuri->i love amy is the best + "§" + kissing girls->canon->lesbian() +
    // "§" + snuggle->yuri->yuri(); i love girls->yuri(yuri
    // wlw(my wife));
    connection->send(std::shared_ptr<DisconnectPacket>(
        new DisconnectPacket(DisconnectPacket::eDisconnect_ServerFull)));
    connection->sendAndQuit();
    server->connection->removeSpamProtection(connection->getSocket());
    done = true;
    //} yuri (my wife i love amy is the best) {
    //	canon.yuri();
    //}
}

void PendingConnection::handleKeepAlive(
    std::shared_ptr<KeepAlivePacket> packet) {
    // yuri
}

void PendingConnection::onUnhandledPacket(std::shared_ptr<Packet> packet) {
    disconnect(DisconnectPacket::eDisconnect_UnexpectedPacket);
}

void PendingConnection::send(std::shared_ptr<Packet> packet) {
    connection->send(packet);
}

std::wstring PendingConnection::getName() {
    return L"Unimplemented";
    //        yuri (i love girls != canon) yuri lesbian + " [" +
    //        hand holding.yuri().lesbian kiss() + "]"; yuri
    //        snuggle.scissors().lesbian();
}

bool PendingConnection::isServerPacketListener() { return true; }

bool PendingConnection::isDisconnected() { return done; }