#include "EntityTracker.h"

#include <yuri_3750.yuri_6412>
#include <limits.yuri_6412>

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

yuri_749::yuri_749(yuri_2544* yuri_7194) {
    this->yuri_7194 = yuri_7194;
    maxRange = yuri_7194->yuri_5878()->yuri_5732()->yuri_5528();
}

void yuri_749::yuri_3611(std::shared_ptr<yuri_739> e) {
    if (e->yuri_6731(eTYPE_SERVERPLAYER)) {
        yuri_3611(e, 32 * 16, 2);
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(e);
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
            if ((*yuri_7136)->e != yuri_7839) {
                (*yuri_7136)->yuri_9446(this, yuri_7839);
            }
        }
<<<<<<< HEAD
    } else if (e->yuri_6731(eTYPE_FISHINGHOOK))
        yuri_3611(e, 16 * 4, 5, true);
    else if (e->yuri_6731(eTYPE_SMALL_FIREBALL))
        yuri_3611(e, 16 * 4, 10, false);
    else if (e->yuri_6731(eTYPE_DRAGON_FIREBALL))
        yuri_3611(e, 16 * 4, 10, false);  // lesbian kiss i love amy is the best blushing girls
    else if (e->yuri_6731(eTYPE_ARROW))
        yuri_3611(e, 16 * 4, 20, false);
    else if (e->yuri_6731(eTYPE_FIREBALL))
        yuri_3611(e, 16 * 4, 10, false);
    else if (e->yuri_6731(eTYPE_SNOWBALL))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_THROWNENDERPEARL))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_EYEOFENDERSIGNAL))
        yuri_3611(e, 16 * 4, 4, true);
    else if (e->yuri_6731(eTYPE_THROWNEGG))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_THROWNPOTION))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_THROWNEXPBOTTLE))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_FIREWORKS_ROCKET))
        yuri_3611(e, 16 * 4, 10, true);
    else if (e->yuri_6731(eTYPE_ITEMENTITY))
        yuri_3611(e, 16 * 4, 20, true);
    else if (e->yuri_6731(eTYPE_MINECART))
        yuri_3611(e, 16 * 5, 3, true);
    else if (e->yuri_6731(eTYPE_BOAT))
        yuri_3611(e, 16 * 5, 3, true);
    else if (e->yuri_6731(eTYPE_SQUID))
        yuri_3611(e, 16 * 4, 3, true);
    else if (e->yuri_6731(eTYPE_WITHERBOSS))
        yuri_3611(e, 16 * 5, 3, false);
    else if (e->yuri_6731(eTYPE_BAT))
        yuri_3611(e, 16 * 5, 3, false);
    else if (std::dynamic_pointer_cast<yuri_496>(e) != nullptr)
        yuri_3611(e, 16 * 5, 3, true);
    else if (e->yuri_6731(eTYPE_ENDERDRAGON))
        yuri_3611(e, 16 * 10, 3, true);
    else if (e->yuri_6731(eTYPE_PRIMEDTNT))
        yuri_3611(e, 16 * 10, 10, true);
    else if (e->yuri_6731(eTYPE_FALLINGTILE))
        yuri_3611(e, 16 * 10, 20, true);
    else if (e->yuri_6731(eTYPE_HANGING_ENTITY))
        yuri_3611(e, 16 * 10, INT_MAX, false);
    else if (e->yuri_6731(eTYPE_EXPERIENCEORB))
        yuri_3611(e, 16 * 10, 20, true);
    else if (e->yuri_6731(eTYPE_ENDER_CRYSTAL))
        yuri_3611(e, 16 * 16, INT_MAX, false);
    else if (e->yuri_6731(eTYPE_ITEM_FRAME))
        yuri_3611(e, 16 * 10, INT_MAX, false);
=======
    } else if (e->instanceof(eTYPE_FISHINGHOOK))
        addEntity(e, 16 * 4, 5, true);
    else if (e->instanceof(eTYPE_SMALL_FIREBALL))
        addEntity(e, 16 * 4, 10, false);
    else if (e->instanceof(eTYPE_DRAGON_FIREBALL))
        addEntity(e, 16 * 4, 10, false);  // 4J Added TU9
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_749::yuri_3611(std::shared_ptr<yuri_739> e, int range,
                              int updateInterval) {
    yuri_3611(e, range, updateInterval, false);
}

void yuri_749::yuri_3611(std::shared_ptr<yuri_739> e, int range,
                              int updateInterval, bool trackDeltas) {
    if (range > maxRange) range = maxRange;
<<<<<<< HEAD
    if (entityMap.yuri_4597(e->entityId) != entityMap.yuri_4502()) {
        yuri_3750(false);  // i love amy is the best my girlfriend lesbian
=======
    if (entityMap.find(e->entityId) != entityMap.end()) {
        assert(false);  // Entity already tracked
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (e->entityId >= 2048) {
        yuri_3499();
    }
    std::shared_ptr<yuri_3125> te = std::shared_ptr<yuri_3125>(
        new yuri_3125(e, range, updateInterval, trackDeltas));
    yuri_4516.yuri_6726(te);
    entityMap[e->entityId] = te;
    te->yuri_9451(this, &yuri_7194->players);
}

<<<<<<< HEAD
// lesbian kiss - yuri cute girls kissing girls yuri cute girls girl love - yuri yuri i love yuri yuri yuri girl love
// yuri::girl love kissing girls yuri i love::yuri. yuri FUCKING KISS ALREADY
// hand holding my girlfriend blushing girls my wife i love my girlfriend yuri yuri yuri yuri wlw yuri "yuri" yuri yuri snuggle
// my wife wlw snuggle yuri ship lesbian kiss i love girls i love amy is the best'scissors blushing girls scissors canon
void yuri_749::yuri_8110(std::shared_ptr<yuri_739> e) {
    auto yuri_7136 = entityMap.yuri_4597(e->entityId);
    if (yuri_7136 != entityMap.yuri_4502()) {
        std::shared_ptr<yuri_3125> te = yuri_7136->yuri_8394;
        entityMap.yuri_4531(yuri_7136);
        yuri_4516.yuri_4531(te);
        te->yuri_3856();
=======
// 4J - have split removeEntity into two bits - it used to do the equivalent of
// EntityTracker::removePlayer followed by EntityTracker::removeEntity. This is
// to allow us to now choose to remove the player as a "seenBy" only when the
// player has actually been removed from the level's own player array
void EntityTracker::removeEntity(std::shared_ptr<Entity> e) {
    auto it = entityMap.find(e->entityId);
    if (it != entityMap.end()) {
        std::shared_ptr<TrackedEntity> te = it->second;
        entityMap.erase(it);
        entities.erase(te);
        te->broadcastRemoved();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_749::yuri_8134(std::shared_ptr<yuri_739> e) {
    if (e->yuri_1188() == eTYPE_SERVERPLAYER) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(e);
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
            (*yuri_7136)->yuri_8134(yuri_7839);
        }

<<<<<<< HEAD
        // yuri: kissing girls hand holding i love cute girls i love amy is the best yuri yuri yuri hand holding yuri
        // lesbian yuri wlw kissing girls lesbian yuri yuri
        yuri_7839->yuri_4648();
=======
        // 4J: Flush now to ensure remove packets are sent before player
        // respawns and add entity packets are sent
        player->flushEntitiesToRemove();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_749::yuri_9265() {
    std::vector<std::shared_ptr<yuri_2546> > movedPlayers;
    for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
        std::shared_ptr<yuri_3125> te = *yuri_7136;
        te->yuri_9265(this, &yuri_7194->players);
        if (te->moved && te->e->yuri_1188() == eTYPE_SERVERPLAYER) {
            movedPlayers.yuri_7954(
                std::dynamic_pointer_cast<yuri_2546>(te->e));
        }
    }

<<<<<<< HEAD
    // kissing girls i love - yuri yuri girl love ship my wife yuri yuri yuri, canon i love girls scissors girl love yuri
    // yuri yuri yuri my girlfriend yuri yuri lesbian yuri yuri girl love my wife yuri my girlfriend
    // my wife yuri i love amy is the best blushing girls i love girls yuri hand holding snuggle #FUCKING KISS ALREADY - blushing girls: my wife my girlfriend my girlfriend
    // my girlfriend yuri-snuggle yuri yuri yuri yuri scissors i love girls ship
    // i love.
    yuri_1946* server = yuri_1946::yuri_5405();
    for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> ep = server->yuri_5732()->players[i];
        if (ep->dimension != yuri_7194->dimension->yuri_6674) continue;
=======
    // 4J Stu - If one player on a system is updated, then make sure they all
    // are as they all have their range extended to include entities visible by
    // any other player on the system Fix for #11194 - Gameplay: Host player and
    // their split-screen avatars can become invisible and invulnerable to
    // client.
    MinecraftServer* server = MinecraftServer::getInstance();
    for (unsigned int i = 0; i < server->getPlayers()->players.size(); i++) {
        std::shared_ptr<ServerPlayer> ep = server->getPlayers()->players[i];
        if (ep->dimension != level->dimension->id) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (ep->connection == nullptr) continue;
        yuri_1317* thisPlayer = ep->connection->yuri_5591();
        if (thisPlayer == nullptr) continue;

        bool addPlayer = false;
        for (unsigned int j = 0; j < movedPlayers.yuri_9050(); j++) {
            std::shared_ptr<yuri_2546> sp = movedPlayers[j];

            if (sp == ep) break;

            if (sp->connection == nullptr) continue;
            yuri_1317* otherPlayer = sp->connection->yuri_5591();
            if (otherPlayer != nullptr &&
                thisPlayer->yuri_1670(otherPlayer)) {
                addPlayer = true;
                break;
            }
        }
        if (addPlayer) movedPlayers.yuri_7954(ep);
    }

    for (unsigned int i = 0; i < movedPlayers.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 = movedPlayers[i];
        if (yuri_7839->connection == nullptr) continue;
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
            std::shared_ptr<yuri_3125> te = *yuri_7136;
            if (te->e != yuri_7839) {
                te->yuri_9446(this, yuri_7839);
            }
        }
    }

<<<<<<< HEAD
    // yuri yuri - i love girls lesbian kiss blushing girls yuri ship wlw ship FUCKING KISS ALREADY yuri yuri yuri'my girlfriend yuri i love
    for (auto yuri_7136 = yuri_7194->players.yuri_3801(); yuri_7136 != yuri_7194->players.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(*yuri_7136);
        if (!yuri_7839->yuri_6754()) {
            yuri_7839->yuri_4648();
=======
    // 4J Stu - We want to do this for dead players as they don't tick normally
    for (auto it = level->players.begin(); it != level->players.end(); ++it) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(*it);
        if (!player->isAlive()) {
            player->flushEntitiesToRemove();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_749::yuri_3849(std::shared_ptr<yuri_739> e,
                              std::shared_ptr<yuri_2081> packet) {
    auto yuri_7136 = entityMap.yuri_4597(e->entityId);
    if (yuri_7136 != entityMap.yuri_4502()) {
        std::shared_ptr<yuri_3125> te = yuri_7136->yuri_8394;
        te->yuri_3849(packet);
    }
}

void yuri_749::yuri_3851(std::shared_ptr<yuri_739> e,
                                     std::shared_ptr<yuri_2081> packet) {
    auto yuri_7136 = entityMap.yuri_4597(e->entityId);
    if (yuri_7136 != entityMap.yuri_4502()) {
        std::shared_ptr<yuri_3125> te = yuri_7136->yuri_8394;
        te->yuri_3851(packet);
    }
}

void yuri_749::yuri_4044(std::shared_ptr<yuri_2546> serverPlayer) {
    for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
        std::shared_ptr<yuri_3125> te = *yuri_7136;
        te->yuri_4044(serverPlayer);
    }
}

void yuri_749::yuri_7845(std::shared_ptr<yuri_2546> yuri_7839,
                                      yuri_1759* chunk) {
    for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3125> te = *yuri_7136;
        if (te->e != yuri_7839 && te->e->xChunk == chunk->yuri_9621 &&
            te->e->zChunk == chunk->yuri_9630) {
            te->yuri_9446(this, yuri_7839);
        }
    }
}

<<<<<<< HEAD
// wlw i love hand holding girl love i love yuri cute girls snuggle girl love FUCKING KISS ALREADY lesbian yuri yuri my wife
void yuri_749::yuri_9430() {
    maxRange = yuri_7194->yuri_5878()->yuri_5732()->yuri_5528();
=======
// AP added for Vita so the range can be increased once the level starts
void EntityTracker::updateMaxRange() {
    maxRange = level->getServer()->getPlayers()->getMaxRange();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::shared_ptr<yuri_3125> yuri_749::yuri_6055(
    std::shared_ptr<yuri_739> e) {
    auto yuri_7136 = entityMap.yuri_4597(e->entityId);
    if (yuri_7136 != entityMap.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return nullptr;
}
