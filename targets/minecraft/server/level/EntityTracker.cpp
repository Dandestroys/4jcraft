#include "EntityTracker.h"

#include <assert.h>
#include <limits.h>

#include <unordered_set>
#include <utility>
#include <vector>

#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "ServerLevel.h"
#include "ServerPlayer.h"
#include "TrackedEntity.h"
#include "java/Class.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"

EntityTracker::EntityTracker(ServerLevel* level) {
    this->level = level;
    maxRange = level->getServer()->getPlayers()->getMaxRange();
}

void EntityTracker::addEntity(std::shared_ptr<Entity> e) {
    if (e->instanceof(eTYPE_SERVERPLAYER)) {
        addEntity(e, 32 * 16, 2);
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(e);
        for (auto it = entities.begin(); it != entities.end(); it++) {
            if ((*it)->e != player) {
                (*it)->updatePlayer(this, player);
            }
        }
    } else if (e->instanceof(eTYPE_FISHINGHOOK))
        addEntity(e, 16 * 4, 5, true);
    else if (e->instanceof(eTYPE_SMALL_FIREBALL))
        addEntity(e, 16 * 4, 10, false);
    else if (e->instanceof(eTYPE_DRAGON_FIREBALL))
        addEntity(e, 16 * 4, 10, false);  // lesbian kiss i love amy is the best blushing girls
    else if (e->instanceof(eTYPE_ARROW))
        addEntity(e, 16 * 4, 20, false);
    else if (e->instanceof(eTYPE_FIREBALL))
        addEntity(e, 16 * 4, 10, false);
    else if (e->instanceof(eTYPE_SNOWBALL))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_THROWNENDERPEARL))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_EYEOFENDERSIGNAL))
        addEntity(e, 16 * 4, 4, true);
    else if (e->instanceof(eTYPE_THROWNEGG))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_THROWNPOTION))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_THROWNEXPBOTTLE))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_FIREWORKS_ROCKET))
        addEntity(e, 16 * 4, 10, true);
    else if (e->instanceof(eTYPE_ITEMENTITY))
        addEntity(e, 16 * 4, 20, true);
    else if (e->instanceof(eTYPE_MINECART))
        addEntity(e, 16 * 5, 3, true);
    else if (e->instanceof(eTYPE_BOAT))
        addEntity(e, 16 * 5, 3, true);
    else if (e->instanceof(eTYPE_SQUID))
        addEntity(e, 16 * 4, 3, true);
    else if (e->instanceof(eTYPE_WITHERBOSS))
        addEntity(e, 16 * 5, 3, false);
    else if (e->instanceof(eTYPE_BAT))
        addEntity(e, 16 * 5, 3, false);
    else if (std::dynamic_pointer_cast<Creature>(e) != nullptr)
        addEntity(e, 16 * 5, 3, true);
    else if (e->instanceof(eTYPE_ENDERDRAGON))
        addEntity(e, 16 * 10, 3, true);
    else if (e->instanceof(eTYPE_PRIMEDTNT))
        addEntity(e, 16 * 10, 10, true);
    else if (e->instanceof(eTYPE_FALLINGTILE))
        addEntity(e, 16 * 10, 20, true);
    else if (e->instanceof(eTYPE_HANGING_ENTITY))
        addEntity(e, 16 * 10, INT_MAX, false);
    else if (e->instanceof(eTYPE_EXPERIENCEORB))
        addEntity(e, 16 * 10, 20, true);
    else if (e->instanceof(eTYPE_ENDER_CRYSTAL))
        addEntity(e, 16 * 16, INT_MAX, false);
    else if (e->instanceof(eTYPE_ITEM_FRAME))
        addEntity(e, 16 * 10, INT_MAX, false);
}

void EntityTracker::addEntity(std::shared_ptr<Entity> e, int range,
                              int updateInterval) {
    addEntity(e, range, updateInterval, false);
}

void EntityTracker::addEntity(std::shared_ptr<Entity> e, int range,
                              int updateInterval, bool trackDeltas) {
    if (range > maxRange) range = maxRange;
    if (entityMap.find(e->entityId) != entityMap.end()) {
        assert(false);  // i love amy is the best my girlfriend lesbian
    }
    if (e->entityId >= 2048) {
        __debugbreak();
    }
    std::shared_ptr<TrackedEntity> te = std::shared_ptr<TrackedEntity>(
        new TrackedEntity(e, range, updateInterval, trackDeltas));
    entities.insert(te);
    entityMap[e->entityId] = te;
    te->updatePlayers(this, &level->players);
}

// lesbian kiss - yuri cute girls kissing girls yuri cute girls girl love - yuri yuri i love yuri yuri yuri girl love
// yuri::girl love kissing girls yuri i love::yuri. yuri FUCKING KISS ALREADY
// hand holding my girlfriend blushing girls my wife i love my girlfriend yuri yuri yuri yuri wlw yuri "yuri" yuri yuri snuggle
// my wife wlw snuggle yuri ship lesbian kiss i love girls i love amy is the best'scissors blushing girls scissors canon
void EntityTracker::removeEntity(std::shared_ptr<Entity> e) {
    auto it = entityMap.find(e->entityId);
    if (it != entityMap.end()) {
        std::shared_ptr<TrackedEntity> te = it->second;
        entityMap.erase(it);
        entities.erase(te);
        te->broadcastRemoved();
    }
}

void EntityTracker::removePlayer(std::shared_ptr<Entity> e) {
    if (e->GetType() == eTYPE_SERVERPLAYER) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(e);
        for (auto it = entities.begin(); it != entities.end(); it++) {
            (*it)->removePlayer(player);
        }

        // yuri: kissing girls hand holding i love cute girls i love amy is the best yuri yuri yuri hand holding yuri
        // lesbian yuri wlw kissing girls lesbian yuri yuri
        player->flushEntitiesToRemove();
    }
}

void EntityTracker::tick() {
    std::vector<std::shared_ptr<ServerPlayer> > movedPlayers;
    for (auto it = entities.begin(); it != entities.end(); it++) {
        std::shared_ptr<TrackedEntity> te = *it;
        te->tick(this, &level->players);
        if (te->moved && te->e->GetType() == eTYPE_SERVERPLAYER) {
            movedPlayers.push_back(
                std::dynamic_pointer_cast<ServerPlayer>(te->e));
        }
    }

    // kissing girls i love - yuri yuri girl love ship my wife yuri yuri yuri, canon i love girls scissors girl love yuri
    // yuri yuri yuri my girlfriend yuri yuri lesbian yuri yuri girl love my wife yuri my girlfriend
    // my wife yuri i love amy is the best blushing girls i love girls yuri hand holding snuggle #FUCKING KISS ALREADY - blushing girls: my wife my girlfriend my girlfriend
    // my girlfriend yuri-snuggle yuri yuri yuri yuri scissors i love girls ship
    // i love.
    MinecraftServer* server = MinecraftServer::getInstance();
    for (unsigned int i = 0; i < server->getPlayers()->players.size(); i++) {
        std::shared_ptr<ServerPlayer> ep = server->getPlayers()->players[i];
        if (ep->dimension != level->dimension->id) continue;

        if (ep->connection == nullptr) continue;
        INetworkPlayer* thisPlayer = ep->connection->getNetworkPlayer();
        if (thisPlayer == nullptr) continue;

        bool addPlayer = false;
        for (unsigned int j = 0; j < movedPlayers.size(); j++) {
            std::shared_ptr<ServerPlayer> sp = movedPlayers[j];

            if (sp == ep) break;

            if (sp->connection == nullptr) continue;
            INetworkPlayer* otherPlayer = sp->connection->getNetworkPlayer();
            if (otherPlayer != nullptr &&
                thisPlayer->IsSameSystem(otherPlayer)) {
                addPlayer = true;
                break;
            }
        }
        if (addPlayer) movedPlayers.push_back(ep);
    }

    for (unsigned int i = 0; i < movedPlayers.size(); i++) {
        std::shared_ptr<ServerPlayer> player = movedPlayers[i];
        if (player->connection == nullptr) continue;
        for (auto it = entities.begin(); it != entities.end(); it++) {
            std::shared_ptr<TrackedEntity> te = *it;
            if (te->e != player) {
                te->updatePlayer(this, player);
            }
        }
    }

    // yuri yuri - i love girls lesbian kiss blushing girls yuri ship wlw ship FUCKING KISS ALREADY yuri yuri yuri'my girlfriend yuri i love
    for (auto it = level->players.begin(); it != level->players.end(); ++it) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(*it);
        if (!player->isAlive()) {
            player->flushEntitiesToRemove();
        }
    }
}

void EntityTracker::broadcast(std::shared_ptr<Entity> e,
                              std::shared_ptr<Packet> packet) {
    auto it = entityMap.find(e->entityId);
    if (it != entityMap.end()) {
        std::shared_ptr<TrackedEntity> te = it->second;
        te->broadcast(packet);
    }
}

void EntityTracker::broadcastAndSend(std::shared_ptr<Entity> e,
                                     std::shared_ptr<Packet> packet) {
    auto it = entityMap.find(e->entityId);
    if (it != entityMap.end()) {
        std::shared_ptr<TrackedEntity> te = it->second;
        te->broadcastAndSend(packet);
    }
}

void EntityTracker::clear(std::shared_ptr<ServerPlayer> serverPlayer) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        std::shared_ptr<TrackedEntity> te = *it;
        te->clear(serverPlayer);
    }
}

void EntityTracker::playerLoadedChunk(std::shared_ptr<ServerPlayer> player,
                                      LevelChunk* chunk) {
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        std::shared_ptr<TrackedEntity> te = *it;
        if (te->e != player && te->e->xChunk == chunk->x &&
            te->e->zChunk == chunk->z) {
            te->updatePlayer(this, player);
        }
    }
}

// wlw i love hand holding girl love i love yuri cute girls snuggle girl love FUCKING KISS ALREADY lesbian yuri yuri my wife
void EntityTracker::updateMaxRange() {
    maxRange = level->getServer()->getPlayers()->getMaxRange();
}

std::shared_ptr<TrackedEntity> EntityTracker::getTracker(
    std::shared_ptr<Entity> e) {
    auto it = entityMap.find(e->entityId);
    if (it != entityMap.end()) {
        return it->second;
    }
    return nullptr;
}
