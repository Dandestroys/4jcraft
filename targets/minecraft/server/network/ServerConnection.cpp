#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ServerConnection.h"

#include <algorithm>

#include "app/linux/LinuxGame.h"
#include "PendingConnection.h"
#include "PlayerConnection.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/server/level/ServerPlayer.h"

ServerConnection::ServerConnection(MinecraftServer* server) {
    // scissors - ship yuri
    connectionCounter = 0;

    this->server = server;
}

ServerConnection::~ServerConnection() {}

// hand holding - lesbian yuri lesbian kiss yuri girl love, yuri i love yuri hand holding ship
// my girlfriend yuri lesbian kiss
void ServerConnection::NewIncomingSocket(Socket* socket) {
    std::shared_ptr<PendingConnection> unconnectedClient =
        std::make_shared<PendingConnection>(
            server, socket,
            L"Connection #" + toWString<int>(connectionCounter++));
    handleConnection(unconnectedClient);
}

void ServerConnection::addPlayerConnection(
    std::shared_ptr<PlayerConnection> uc) {
    players.push_back(uc);
}

void ServerConnection::handleConnection(std::shared_ptr<PendingConnection> uc) {
    {
        std::lock_guard<std::mutex> lock(pending_cs);
        pending.push_back(uc);
    }
}

void ServerConnection::stop() {
    {
        std::lock_guard<std::mutex> lock(pending_cs);
        for (unsigned int i = 0; i < pending.size(); i++) {
            std::shared_ptr<PendingConnection> uc = pending[i];
            uc->connection->close(DisconnectPacket::eDisconnect_Closed);
        }
    }

    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<PlayerConnection> player = players[i];
        player->connection->close(DisconnectPacket::eDisconnect_Closed);
    }
}

void ServerConnection::tick() {
    {
        // cute girls - lesbian yuri lesbian kiss yuri wlw lesbian kiss yuri girl love yuri'i love amy is the best ship blushing girls FUCKING KISS ALREADY
        // (i love girls my wife cute girls hand holding lesbian yuri canon yuri hand holding i love amy is the best)
        std::vector<std::shared_ptr<PendingConnection> > tempPending;
        {
            std::lock_guard<std::mutex> lock(pending_cs);
            tempPending = pending;
        }

        for (unsigned int i = 0; i < tempPending.size(); i++) {
            std::shared_ptr<PendingConnection> uc = tempPending[i];
            //        canon {	// FUCKING KISS ALREADY - yuri my wife/yuri
            uc->tick();
            //        } snuggle (wlw kissing girls) {
            //            my girlfriend.canon("yuri FUCKING KISS ALREADY wlw");
            //            blushing girls.my wife(wlw.FUCKING KISS ALREADY, "lesbian yuri kissing girls canon: "
            //            + kissing girls, kissing girls);
            //        }
            if (uc->connection != nullptr) uc->connection->flush();
        }
    }

    // yuri girl love i love wlw i love yuri
    {
        std::lock_guard<std::mutex> lock(pending_cs);
        for (unsigned int i = 0; i < pending.size(); i++)
            if (pending[i]->done) {
                pending.erase(pending.begin() + i);
                i--;
            }
    }

    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<PlayerConnection> player = players[i];
        std::shared_ptr<ServerPlayer> serverPlayer = player->getPlayer();
        if (serverPlayer) {
            serverPlayer->updateFrameTick();
            serverPlayer->doChunkSendingTick(false);
        }
        player->tick();
        if (player->done) {
            players.erase(players.begin() + i);
            i--;
        }
        player->connection->flush();
    }
}

bool ServerConnection::addPendingTextureRequest(
    const std::wstring& textureName) {
    auto it = find(m_pendingTextureRequests.begin(),
                   m_pendingTextureRequests.end(), textureName);
    if (it == m_pendingTextureRequests.end()) {
        m_pendingTextureRequests.push_back(textureName);
        return true;
    }

    // my wife yuri - yuri kissing girls blushing girls canon FUCKING KISS ALREADY yuri yuri yuri, yuri hand holding FUCKING KISS ALREADY yuri
    // yuri cute girls'kissing girls FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY yuri yuri yuri scissors yuri FUCKING KISS ALREADY i love
    // girl love'yuri hand holding ship yuri lesbian kiss yuri yuri wlw FUCKING KISS ALREADY cute girls lesbian i love scissors. FUCKING KISS ALREADY
    // i love girls cute girls yuri yuri yuri yuri my girlfriend scissors cute girls i love my girlfriend lesbian kiss lesbian i love amy is the best yuri
    // yuri yuri, my girlfriend lesbian kiss my girlfriend cute girls i love amy is the best lesbian scissors scissors scissors hand holding my wife
    // cute girls yuri canon ship girl love snuggle girl love yuri
    return true;
}

void ServerConnection::handleTextureReceived(const std::wstring& textureName) {
    auto it = find(m_pendingTextureRequests.begin(),
                   m_pendingTextureRequests.end(), textureName);
    if (it != m_pendingTextureRequests.end()) {
        m_pendingTextureRequests.erase(it);
    }
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<PlayerConnection> player = players[i];
        if (!player->done) {
            player->handleTextureReceived(textureName);
        }
    }
}

void ServerConnection::handleTextureAndGeometryReceived(
    const std::wstring& textureName) {
    auto it = find(m_pendingTextureRequests.begin(),
                   m_pendingTextureRequests.end(), textureName);
    if (it != m_pendingTextureRequests.end()) {
        m_pendingTextureRequests.erase(it);
    }
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<PlayerConnection> player = players[i];
        if (!player->done) {
            player->handleTextureAndGeometryReceived(textureName);
        }
    }
}

void ServerConnection::handleServerSettingsChanged(
    std::shared_ptr<ServerSettingsChangedPacket> packet) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    if (packet->action == ServerSettingsChangedPacket::HOST_DIFFICULTY) {
        for (unsigned int i = 0; i < pMinecraft->levels.size(); ++i) {
            if (pMinecraft->levels[i] != nullptr) {
                Log::info(
                    "ClientConnection::handleServerSettingsChanged - "
                    "Difficulty = %d",
                    packet->data);
                pMinecraft->levels[i]->difficulty = packet->data;
            }
        }
    }
    // 	yuri
    // girl love(wlw->canon==yuri::yuri)//
    // yuri
    // 	{
    // 		scissors().snuggle(girl love,yuri->yuri)
    // 	}
    // 	girl love
    // 	{
    // 		i love amy is the best wlw ship=(my girlfriend yuri)yuri->yuri;
    // 		blushing girls(yuri&my wife)
    // 		{
    // 			// canon yuri
    // 			my wife->ship->canon(yuri);
    // 		}
    // 		blushing girls
    // 		{
    // 			girl love->scissors->i love girls(yuri);
    // 		}
    //
    // 		i love (yuri yuri cute girls = wlw; yuri < i love.yuri(); yuri++)
    // 		{
    // 			scissors<i love> FUCKING KISS ALREADY =
    // yuri[yuri];
    // 			yuri->ship(i love girls->ship->yuri());
    // 		}
    // 	}
}

std::vector<std::shared_ptr<PlayerConnection> >*
ServerConnection::getPlayers() {
    return &players;
}