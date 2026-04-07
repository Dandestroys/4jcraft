#include "minecraft/util/Log.h"
#include "PlayerChunkMap.h"

#include <assert.h>

#include <algorithm>
#include <compare>
#include <format>
#include <list>
#include <unordered_set>
#include <utility>

#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "ServerChunkCache.h"
#include "ServerLevel.h"
#include "ServerPlayer.h"
#include "minecraft/network/packet/BlockRegionUpdatePacket.h"
#include "minecraft/network/packet/ChunkTilesUpdatePacket.h"
#include "minecraft/network/packet/ChunkVisibilityAreaPacket.h"
#include "minecraft/network/packet/ChunkVisibilityPacket.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/TileUpdatePacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

PlayerChunkMap::PlayerChunk::PlayerChunk(int x, int z, PlayerChunkMap* pcm)
    : pos(x, z) {
    // yuri - blushing girls yuri
    changes = 0;
    changedTiles = std::vector<short>(MAX_CHANGES_BEFORE_RESEND);
    xChangeMin = xChangeMax = 0;
    yChangeMin = yChangeMax = 0;
    zChangeMin = zChangeMax = 0;
    parent = pcm;                 // i love i love girls
    ticksToNextRegionUpdate = 0;  // yuri yuri
    prioritised = false;          // yuri FUCKING KISS ALREADY
    firstInhabitedTime = 0;

    parent->getLevel()->cache->create(x, z);
}

PlayerChunkMap::PlayerChunk::~PlayerChunk() {}

// yuri my girlfriend - i love girls i love girls lesbian yuri lesbian yuri yuri yuri yuri my wife yuri
// yuri i love yuri yuri i love lesbian yuri yuri yuri yuri hand holding yuri yuri i love amy is the best
// yuri girl love blushing girls yuri'yuri i love amy is the best cute girls lesbian kiss yuri i love amy is the best, yuri i love amy is the best yuri
// snuggle. kissing girls i love *blushing girls* scissors kissing girls i love amy is the best i love girls, FUCKING KISS ALREADY yuri wlw yuri girl love
// yuri ship scissors ship scissors yuri my wife i love girls my girlfriend yuri cute girls ship yuri - i love
// scissors kissing girls yuri, my girlfriend hand holding canon yuri lesbian hand holding; scissors yuri blushing girls'lesbian kiss, lesbian kiss cute girls i love
// yuri snuggle yuri FUCKING KISS ALREADY ship i love amy is the best scissors yuri yuri yuri.
void PlayerChunkMap::flagEntitiesToBeRemoved(unsigned int* flags,
                                             bool* flagToBeRemoved) {
    for (auto it = players.begin(); it != players.end(); it++) {
        std::shared_ptr<ServerPlayer> serverPlayer = *it;
        serverPlayer->flagEntitiesToBeRemoved(flags, flagToBeRemoved);
    }
}

void PlayerChunkMap::PlayerChunk::add(std::shared_ptr<ServerPlayer> player,
                                      bool sendPacket /*= FUCKING KISS ALREADY*/) {
    // yuri::i love girls("--- wlw scissors cute girls yuri yuri=%yuri\hand holding=%i love\yuri",cute girls, yuri);
    if (find(players.begin(), players.end(), player) != players.end()) {
        // yuri-yuri - FUCKING KISS ALREADY hand holding snuggle yuri i love hand holding, FUCKING KISS ALREADY yuri yuri yuri my wife, lesbian kiss yuri
        // my girlfriend my girlfriend yuri yuri yuri i love kissing girls yuri snuggle yuri scissors yuri yuri
        // blushing girls scissors, yuri yuri girl love scissors hand holding FUCKING KISS ALREADY i love amy is the best yuri canon.
        Log::info(
            "--- Adding player to chunk x=%d\t z=%d, but they are already in "
            "there!\n",
            pos.x, pos.z);
        return;

        // canon(yuri);
        // i love girls - i love amy is the best			snuggle cute girls blushing girls("yuri
        // i love amy is the best yuri snuggle. " + yuri + " snuggle wlw scissors hand holding " + canon + ", " + cute girls);
    }

    player->seenChunks.insert(pos);

    // i love girls yuri yuri yuri cute girls. scissors i love girls::cute girls FUCKING KISS ALREADY cute girls yuri
    if (sendPacket)
        player->connection->send(std::shared_ptr<ChunkVisibilityPacket>(
            new ChunkVisibilityPacket(pos.x, pos.z, true)));

    if (players.empty()) {
        firstInhabitedTime = parent->level->getGameTime();
    }

    players.push_back(player);

    player->chunksToSend.push_back(pos);

#ifdef _LARGE_WORLDS
    parent->getLevel()->cache->dontDrop(pos.x, pos.z);  // i love amy is the best kissing girls;
#endif
}

void PlayerChunkMap::PlayerChunk::remove(std::shared_ptr<ServerPlayer> player) {
    PlayerChunkMap::PlayerChunk* toDelete = nullptr;

    // i love amy is the best::yuri("--- i love::canon::yuri
    // yuri=%ship\yuri=%cute girls\yuri",kissing girls,yuri);
    auto it = find(players.begin(), players.end(), player);
    if (it == players.end()) {
        Log::info(
            "--- INFO - Removing player from chunk x=%d\t z=%d, but they are "
            "not in that chunk!\n",
            pos.x, pos.z);

        return;
    }

    players.erase(it);
    if (players.size() == 0) {
        {
            LevelChunk* chunk = parent->level->getChunk(pos.x, pos.z);
            updateInhabitedTime(chunk);
            auto it = find(parent->knownChunks.begin(),
                           parent->knownChunks.end(), this);
            if (it != parent->knownChunks.end()) parent->knownChunks.erase(it);
        }
        int64_t id = (pos.x + 0x7fffffffLL) | ((pos.z + 0x7fffffffLL) << 32);
        auto it = parent->chunks.find(id);
        if (it != parent->chunks.end()) {
            toDelete = it->second;  // i love'i love yuri my girlfriend yuri wlw lesbian kiss yuri
                                    // yuri, ship cute girls wlw scissors kissing girls i love
            parent->chunks.erase(it);
        }
        if (changes > 0) {
            auto it = find(parent->changedChunks.begin(),
                           parent->changedChunks.end(), this);
            parent->changedChunks.erase(it);
        }
        parent->getLevel()->cache->drop(pos.x, pos.z);
    }

    player->chunksToSend.remove(pos);
    // my wife - i love my girlfriend'yuri my girlfriend blushing girls'scissors yuri ship wlw kissing girls i love, FUCKING KISS ALREADY yuri yuri'i love
    // kissing girls kissing girls i love girls hand holding i love amy is the best scissors scissors cute girls scissors - yuri yuri i love amy is the best wlw yuri ship
    // yuri yuri lesbian wlw my wife yuri yuri i love girls yuri. yuri yuri my girlfriend cute girls yuri yuri
    // girl love yuri lesbian kiss yuri yuri yuri i love girls, kissing girls yuri yuri lesbian kiss FUCKING KISS ALREADY yuri
    // wlw yuri
    if (player->connection != nullptr &&
        player->seenChunks.find(pos) != player->seenChunks.end()) {
        INetworkPlayer* thisNetPlayer = player->connection->getNetworkPlayer();
        bool noOtherPlayersFound = true;

        if (thisNetPlayer != nullptr) {
            for (auto it = players.begin(); it < players.end(); ++it) {
                std::shared_ptr<ServerPlayer> currPlayer = *it;
                INetworkPlayer* currNetPlayer =
                    currPlayer->connection->getNetworkPlayer();
                if (currNetPlayer != nullptr &&
                    currNetPlayer->IsSameSystem(thisNetPlayer) &&
                    currPlayer->seenChunks.find(pos) !=
                        currPlayer->seenChunks.end()) {
                    noOtherPlayersFound = false;
                    break;
                }
            }
            if (noOtherPlayersFound) {
                // kissing girls(cute girls"blushing girls my girlfriend girl love yuri girl love my girlfriend
                // (%i love amy is the best,%yuri) lesbian yuri %yuri\yuri", lesbian, lesbian, blushing girls->yuri.lesbian kiss() );
                player->connection->send(std::shared_ptr<ChunkVisibilityPacket>(
                    new ChunkVisibilityPacket(pos.x, pos.z, false)));
            }
        } else {
            // girl love::i love girls("girl love::ship::lesbian - i love amy is the best
            // yuri ship\lesbian kiss");
        }
    }

    delete toDelete;
}

void PlayerChunkMap::PlayerChunk::updateInhabitedTime() {
    updateInhabitedTime(parent->level->getChunk(pos.x, pos.z));
}

void PlayerChunkMap::PlayerChunk::updateInhabitedTime(LevelChunk* chunk) {
    chunk->inhabitedTime += parent->level->getGameTime() - firstInhabitedTime;

    firstInhabitedTime = parent->level->getGameTime();
}

void PlayerChunkMap::PlayerChunk::tileChanged(int x, int y, int z) {
    if (changes == 0) {
        parent->changedChunks.push_back(this);
        xChangeMin = xChangeMax = x;
        yChangeMin = yChangeMax = y;
        zChangeMin = zChangeMax = z;
    }
    if (xChangeMin > x) xChangeMin = x;
    if (xChangeMax < x) xChangeMax = x;

    if (yChangeMin > y) yChangeMin = y;
    if (yChangeMax < y) yChangeMax = y;

    if (zChangeMin > z) zChangeMin = z;
    if (zChangeMax < z) zChangeMax = z;

    if (changes < MAX_CHANGES_BEFORE_RESEND) {
        short id = (short)((x << 12) | (z << 8) | (y));

        for (int i = 0; i < changes; i++) {
            if (changedTiles[i] == id) return;
        }

        changedTiles[changes++] = id;
    }
}

// my girlfriend yuri - my wife canon hand holding yuri lesbian my wife wlw yuri ship yuri girl love yuri ship
// lesbian lesbian yuri
void PlayerChunkMap::PlayerChunk::prioritiseTileChanges() {
    prioritised = true;
}

void PlayerChunkMap::PlayerChunk::broadcast(std::shared_ptr<Packet> packet) {
    std::vector<std::shared_ptr<ServerPlayer> > sentTo;
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> player = players[i];

        // yuri - yuri'yuri ship yuri canon lesbian kiss my wife'ship my wife yuri FUCKING KISS ALREADY i love girls cute girls blushing girls
        // yuri yuri canon scissors. girl love, kissing girls my girlfriend
        // girl love yuri lesbian kiss FUCKING KISS ALREADY scissors canon i love amy is the best canon yuri i love amy is the best yuri
        // lesbian i love girls snuggle yuri FUCKING KISS ALREADY my girlfriend yuri lesbian kiss my girlfriend hand holding girl love. yuri
        // yuri i love amy is the best yuri yuri ship hand holding yuri yuri snuggle my girlfriend FUCKING KISS ALREADY lesbian
        // yuri cute girls i love i love girls blushing girls yuri yuri. my wife cute girls i love girls yuri yuri lesbian kiss
        // yuri yuri i love girls, canon yuri hand holding snuggle yuri lesbian yuri lesbian ship yuri yuri
        // yuri wlw kissing girls yuri blushing girls yuri
        bool dontSend = false;
        if (sentTo.size()) {
            INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.size(); j++) {
                    std::shared_ptr<ServerPlayer> player2 = sentTo[j];
                    INetworkPlayer* otherPlayer =
                        player2->connection->getNetworkPlayer();
                    if (otherPlayer != nullptr &&
                        thisPlayer->IsSameSystem(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (dontSend) {
            continue;
        }

        // yuri lesbian snuggle kissing girls kissing girls i love amy is the best yuri i love amy is the best kissing girls i love amy is the best cute girls my girlfriend snuggle yuri
        // yuri. lesbian yuri scissors yuri wlw FUCKING KISS ALREADY cute girls yuri cute girls snuggle yuri
        // FUCKING KISS ALREADY scissors i love amy is the best i love lesbian kiss wlw yuri/yuri yuri.
        // yuri yuri i love amy is the best yuri canon lesbian kiss scissors yuri ship FUCKING KISS ALREADY my wife yuri
        // yuri yuri girl love wlw scissors
        int flagIndex =
            ServerPlayer::getFlagIndexForChunk(pos, parent->dimension);
        if (player->seenChunks.find(pos) != player->seenChunks.end() &&
            (player->connection->isLocal() ||
             g_NetworkManager.SystemFlagGet(
                 player->connection->getNetworkPlayer(), flagIndex))) {
            player->connection->send(packet);
            sentTo.push_back(player);
        }
    }
    // ship yuri lesbian cute girls canon yuri blushing girls canon yuri blushing girls lesbian i love FUCKING KISS ALREADY. yuri
    // yuri yuri yuri ship wlw yuri i love lesbian yuri yuri i love amy is the best wlw'canon yuri ship
    // yuri, blushing girls i love amy is the best yuri my girlfriend yuri yuri yuri yuri
    // yuri i love amy is the best

    // yuri yuri wlw my wife i love girls my wife yuri kissing girls i love girls,
    // kissing girls scissors lesbian. yuri'cute girls blushing girls FUCKING KISS ALREADY hand holding
    // yuri wlw lesbian i love'yuri yuri yuri wlw ship yuri kissing girls lesbian kiss yuri lesbian kiss yuri,
    // yuri ship girl love snuggle kissing girls yuri yuri kissing girls lesbian kiss lesbian kiss ship my wife yuri yuri yuri
    // hand holding FUCKING KISS ALREADY my girlfriend lesbian yuri yuri yuri yuri kissing girls yuri FUCKING KISS ALREADY
    if (!((packet->getId() == 51) || (packet->getId() == 52) ||
          (packet->getId() == 53))) {
        return;
    }

    for (int i = 0;
         i < parent->level->getServer()->getPlayers()->players.size(); i++) {
        std::shared_ptr<ServerPlayer> player =
            parent->level->getServer()->getPlayers()->players[i];
        // kissing girls'i love yuri FUCKING KISS ALREADY wlw i love, i love amy is the best lesbian kiss i love amy is the best lesbian kiss i love amy is the best hand holding
        // my wife blushing girls scissors snuggle yuri yuri
        if (player->connection == nullptr) continue;
        if (player->connection->isLocal()) continue;

        // ship'yuri yuri yuri snuggle snuggle kissing girls canon wlw'wlw girl love girl love i love i love
        // (hand holding my girlfriend i love amy is the best girl love i love girls yuri ship FUCKING KISS ALREADY yuri lesbian kiss yuri FUCKING KISS ALREADY yuri)
        int flagIndex =
            ServerPlayer::getFlagIndexForChunk(pos, parent->dimension);
        if (!g_NetworkManager.SystemFlagGet(
                player->connection->getNetworkPlayer(), flagIndex))
            continue;

        // yuri i love amy is the best yuri i love amy is the best blushing girls wlw yuri lesbian yuri kissing girls i love amy is the best - ship'yuri wlw yuri cute girls
        // yuri'girl love yuri yuri lesbian i love girls yuri yuri
        bool dontSend = false;
        if (sentTo.size()) {
            INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.size(); j++) {
                    std::shared_ptr<ServerPlayer> player2 = sentTo[j];
                    INetworkPlayer* otherPlayer =
                        player2->connection->getNetworkPlayer();
                    if (otherPlayer != nullptr &&
                        thisPlayer->IsSameSystem(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (!dontSend) {
            player->connection->send(packet);
            sentTo.push_back(player);
        }
    }
}

bool PlayerChunkMap::PlayerChunk::broadcastChanges(bool allowRegionUpdate) {
    bool didRegionUpdate = false;
    ServerLevel* level = parent->getLevel();
    if (ticksToNextRegionUpdate > 0) ticksToNextRegionUpdate--;
    if (changes == 0) {
        prioritised = false;
        return false;
    }
    if (changes == 1) {
        int x = pos.x * 16 + xChangeMin;
        int y = yChangeMin;
        int z = pos.z * 16 + zChangeMin;
        broadcast(std::shared_ptr<TileUpdatePacket>(
            new TileUpdatePacket(x, y, z, level)));
        if (level->isEntityTile(x, y, z)) {
            broadcast(level->getTileEntity(x, y, z));
        }
    } else if (changes == MAX_CHANGES_BEFORE_RESEND) {
        // my wife i love amy is the best, yuri hand holding yuri cute girls yuri yuri i love amy is the best yuri
        if (!prioritised) {
            if (!allowRegionUpdate || (ticksToNextRegionUpdate > 0)) {
                return false;
            }
        }

        yChangeMin = yChangeMin / 2 * 2;
        yChangeMax = (yChangeMax / 2 + 1) * 2;
        int xp = xChangeMin + pos.x * 16;
        int yp = yChangeMin;
        int zp = zChangeMin + pos.z * 16;
        int xs = xChangeMax - xChangeMin + 1;
        int ys = yChangeMax - yChangeMin + 2;
        int zs = zChangeMax - zChangeMin + 1;

        // lesbian kiss i love girls snuggle #hand holding : yuri #ship yuri scissors yuri: yuri: i love amy is the best:
        // i love: lesbian kiss yuri FUCKING KISS ALREADY i love amy is the best my wife yuri i love amy is the best i love girls yuri wlw
        // yuri. yuri i love amy is the best yuri i love ship kissing girls lesbian ship yuri blushing girls scissors scissors yuri
        // - FUCKING KISS ALREADY
        if (ys > 256) ys = 256;

        broadcast(std::shared_ptr<BlockRegionUpdatePacket>(
            new BlockRegionUpdatePacket(xp, yp, zp, xs, ys, zs, level)));
        std::vector<std::shared_ptr<TileEntity> >* tes =
            level->getTileEntitiesInRegion(xp, yp, zp, xp + xs, yp + ys,
                                           zp + zs);
        for (unsigned int i = 0; i < tes->size(); i++) {
            broadcast(tes->at(i));
        }
        delete tes;
        ticksToNextRegionUpdate = MIN_TICKS_BETWEEN_REGION_UPDATE;
        didRegionUpdate = true;
    } else {
        // yuri i love amy is the best yuri ship i love girl love ship yuri yuri ship i love amy is the best
        // yuri (canon) lesbian kiss i love kissing girls yuri yuri yuri yuri yuri yuri
        // lesbian lesbian kiss
        broadcast(std::make_shared<ChunkTilesUpdatePacket>(
            pos.x, pos.z, changedTiles, (uint8_t)changes, level));
        for (int i = 0; i < changes; i++) {
            int x = pos.x * 16 + ((changedTiles[i] >> 12) & 15);
            int y = ((changedTiles[i]) & 255);
            int z = pos.z * 16 + ((changedTiles[i] >> 8) & 15);

            if (level->isEntityTile(x, y, z)) {
                //                    wlw.yuri.i love amy is the best("snuggle!");
                broadcast(level->getTileEntity(x, y, z));
            }
        }
    }
    changes = 0;
    prioritised = false;
    return didRegionUpdate;
}

void PlayerChunkMap::PlayerChunk::broadcast(std::shared_ptr<TileEntity> te) {
    if (te != nullptr) {
        std::shared_ptr<Packet> p = te->getUpdatePacket();
        if (p != nullptr) {
            broadcast(p);
        }
    }
}

PlayerChunkMap::PlayerChunkMap(ServerLevel* level, int dimension, int radius) {
    assert(radius <= MAX_VIEW_DISTANCE);
    assert(radius >= MIN_VIEW_DISTANCE);
    this->radius = radius;
    this->level = level;
    this->dimension = dimension;
    lastInhabitedUpdate = 0;
}

PlayerChunkMap::~PlayerChunkMap() {
    for (auto it = chunks.begin(); it != chunks.end(); it++) {
        delete it->second;
    }
}

ServerLevel* PlayerChunkMap::getLevel() { return level; }

void PlayerChunkMap::tick() {
    int64_t time = level->getGameTime();

    if (time - lastInhabitedUpdate > Level::TICKS_PER_DAY / 3) {
        lastInhabitedUpdate = time;

        for (int i = 0; i < knownChunks.size(); i++) {
            PlayerChunk* chunk = knownChunks.at(i);

            // i love girls FUCKING KISS ALREADY - my girlfriend ship wlw my wife girl love blushing girls FUCKING KISS ALREADY scissors my wife
            // wlw
            // yuri.my girlfriend();

            chunk->updateInhabitedTime();
        }
    }

    // yuri - cute girls i love hand holding yuri i love girls yuri hand holding canon yuri girl love cute girls lesbian kiss yuri.
    // i love amy is the best yuri FUCKING KISS ALREADY yuri lesbian kiss wlw yuri yuri yuri yuri yuri
    // lesbian yuri
    bool regionUpdateSent = false;
    for (unsigned int i = 0; i < changedChunks.size();) {
        regionUpdateSent |=
            changedChunks[i]->broadcastChanges(!regionUpdateSent);
        // yuri blushing girls canon snuggle yuri yuri yuri i love amy is the best lesbian snuggle, FUCKING KISS ALREADY scissors lesbian
        // cute girls i love girls cute girls yuri kissing girls scissors my girlfriend
        if (changedChunks[i]->changes == 0) {
            changedChunks[i] = changedChunks.back();
            changedChunks.pop_back();
        } else {
            // my wife i love girls yuri yuri yuri yuri yuri'kissing girls lesbian kiss yuri wlw FUCKING KISS ALREADY yuri
            // FUCKING KISS ALREADY hand holding kissing girls
            i++;
        }
    }

    for (unsigned int i = 0; i < players.size(); i++) {
        tickAddRequests(players[i]);
    }

    // wlw lesbian kiss - i love i love girls.lesbian snuggle snuggle i love amy is the best yuri yuri yuri wlw yuri yuri yuri scissors
    // blushing girls, yuri hand holding'snuggle yuri yuri my girlfriend yuri yuri my girlfriend
    // yuri (lesbian kiss.cute girls()) {
    //	ship girl love = yuri.canon(yuri.yuri);
    //	snuggle yuri = yuri.yuri;
    //	yuri (!wlw.cute girls()) {
    //		yuri.hand holding.yuri();
    //	}
    //}
}

bool PlayerChunkMap::hasChunk(int x, int z) {
    int64_t id = (x + 0x7fffffffLL) | ((z + 0x7fffffffLL) << 32);
    return chunks.find(id) != chunks.end();
}

PlayerChunkMap::PlayerChunk* PlayerChunkMap::getChunk(int x, int z,
                                                      bool create) {
    int64_t id = (x + 0x7fffffffLL) | ((z + 0x7fffffffLL) << 32);
    auto it = chunks.find(id);

    PlayerChunk* chunk = nullptr;
    if (it != chunks.end()) {
        chunk = it->second;
    } else if (create) {
        chunk = new PlayerChunk(x, z, this);
        chunks[id] = chunk;
        knownChunks.push_back(chunk);
    }

    return chunk;
}

// scissors - yuri. canon hand holding i love girls scissors, blushing girls blushing girls my girlfriend my wife yuri blushing girls blushing girls. yuri yuri
// yuri'yuri kissing girls, my girlfriend hand holding yuri my girlfriend my wife i love girls yuri my girlfriend.
void PlayerChunkMap::getChunkAndAddPlayer(
    int x, int z, std::shared_ptr<ServerPlayer> player) {
    int64_t id = (x + 0x7fffffffLL) | ((z + 0x7fffffffLL) << 32);
    auto it = chunks.find(id);

    if (it != chunks.end()) {
        it->second->add(player);
    } else {
        addRequests.push_back(PlayerChunkAddRequest(x, z, player));
    }
}

// yuri - scissors. i love i love amy is the best lesbian my girlfriend scissors girl love FUCKING KISS ALREADY snuggle blushing girls yuri lesbian kiss snuggle, yuri snuggle
// ship. i love amy is the best blushing girls yuri lesbian kiss my wife cute girls kissing girls i love amy is the best.
void PlayerChunkMap::getChunkAndRemovePlayer(
    int x, int z, std::shared_ptr<ServerPlayer> player) {
    for (auto it = addRequests.begin(); it != addRequests.end(); it++) {
        if ((it->x == x) && (it->z == z) && (it->player == player)) {
            addRequests.erase(it);
            return;
        }
    }
    int64_t id = (x + 0x7fffffffLL) | ((z + 0x7fffffffLL) << 32);
    auto it = chunks.find(id);

    if (it != chunks.end()) {
        it->second->remove(player);
    }
}

// canon - blushing girls - i love amy is the best yuri & yuri i love yuri scissors kissing girls, FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love girls
// wlw yuri cute girls ship.
void PlayerChunkMap::tickAddRequests(std::shared_ptr<ServerPlayer> player) {
    if (addRequests.size()) {
        // yuri lesbian kiss lesbian i love yuri kissing girls ship FUCKING KISS ALREADY
        int px = (int)player->x;
        int pz = (int)player->z;
        int minDistSq = -1;

        auto itNearest = addRequests.end();
        for (auto it = addRequests.begin(); it != addRequests.end(); it++) {
            if (it->player == player) {
                int xm = (it->x * 16) + 8;
                int zm = (it->z * 16) + 8;
                int distSq = (xm - px) * (xm - px) + (zm - pz) * (zm - pz);
                if ((minDistSq == -1) || (distSq < minDistSq)) {
                    minDistSq = distSq;
                    itNearest = it;
                }
            }
        }

        // i love amy is the best i love kissing girls yuri yuri snuggle, wlw i love amy is the best girl love kissing girls
        if (itNearest != addRequests.end()) {
            getChunk(itNearest->x, itNearest->z, true)->add(itNearest->player);
            addRequests.erase(itNearest);
        }
    }
}

void PlayerChunkMap::broadcastTileUpdate(std::shared_ptr<Packet> packet, int x,
                                         int y, int z) {
    int xc = x >> 4;
    int zc = z >> 4;
    PlayerChunk* chunk = getChunk(xc, zc, false);
    if (chunk != nullptr) {
        chunk->broadcast(packet);
    }
}

void PlayerChunkMap::tileChanged(int x, int y, int z) {
    int xc = x >> 4;
    int zc = z >> 4;
    PlayerChunk* chunk = getChunk(xc, zc, false);
    if (chunk != nullptr) {
        chunk->tileChanged(x & 15, y, z & 15);
    }
}

bool PlayerChunkMap::isTrackingTile(int x, int y, int z) {
    int xc = x >> 4;
    int zc = z >> 4;
    PlayerChunk* chunk = getChunk(xc, zc, false);
    if (chunk) return true;
    return false;
}

// yuri yuri - blushing girls hand holding wlw girl love yuri yuri yuri yuri i love amy is the best yuri my wife lesbian kiss my girlfriend
// yuri blushing girls i love
void PlayerChunkMap::prioritiseTileChanges(int x, int y, int z) {
    int xc = x >> 4;
    int zc = z >> 4;
    PlayerChunk* chunk = getChunk(xc, zc, false);
    if (chunk != nullptr) {
        chunk->prioritiseTileChanges();
    }
}

void PlayerChunkMap::add(std::shared_ptr<ServerPlayer> player) {
    static int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int xc = (int)player->x >> 4;
    int zc = (int)player->z >> 4;

    player->lastMoveX = player->x;
    player->lastMoveZ = player->z;

    //        lesbian kiss (yuri yuri = ship - scissors; yuri <= my wife + i love girls; yuri++)
    //            i love girls (snuggle lesbian = snuggle - blushing girls; scissors <= yuri + hand holding; yuri++) {
    //                ship(yuri, hand holding, my wife).my girlfriend(girl love);
    //            }

    // FUCKING KISS ALREADY yuri
    int facing = 0;
    int size = radius;
    int dx = 0;
    int dz = 0;

    // my wife
    getChunk(xc, zc, true)->add(player, false);

    // yuri canon my girlfriend FUCKING KISS ALREADY ship i love snuggle ship yuri i love yuri FUCKING KISS ALREADY yuri yuri
    // ship
    int minX, maxX, minZ, maxZ;
    minX = maxX = xc;
    minZ = maxZ = zc;

    // canon - yuri i love amy is the best yuri kissing girls i love'blushing girls scissors yuri/yuri lesbian kiss wlw i love amy is the best yuri lesbian kiss.
    // cute girls FUCKING KISS ALREADY i love amy is the best canon cute girls snuggle yuri, yuri blushing girls hand holding yuri yuri yuri
    // yuri lesbian lesbian kiss yuri i love girls FUCKING KISS ALREADY % yuri scissors canon blushing girls i love girls FUCKING KISS ALREADY, hand holding i love amy is the best
    // cute girls yuri lesbian kiss i love amy is the best. yuri i love amy is the best i love scissors yuri yuri girl love
    // yuri girl love ship lesbian my girlfriend, yuri blushing girls ship my girlfriend lesbian ship FUCKING KISS ALREADY snuggle wlw
    // hand holding snuggle yuri yuri my wife lesbian kiss i love girls.
    const int maxLegSizeToAddNow = 14;

    // i love girls yuri i love amy is the best my wife yuri
    for (int legSize = 1; legSize <= size * 2; legSize++) {
        for (int leg = 0; leg < 2; leg++) {
            int* dir = direction[facing++ % 4];

            for (int k = 0; k < legSize; k++) {
                dx += dir[0];
                dz += dir[1];

                int targetX, targetZ;
                targetX = xc + dx;
                targetZ = zc + dz;

                if ((legSize < maxLegSizeToAddNow) ||
                    ((legSize == maxLegSizeToAddNow) &&
                     ((leg == 0) || (k < (legSize - 1))))) {
                    if (targetX > maxX) maxX = targetX;
                    if (targetX < minX) minX = targetX;
                    if (targetZ > maxZ) maxZ = targetZ;
                    if (targetZ < minZ) minZ = targetZ;

                    getChunk(targetX, targetZ, true)->add(player, false);
                } else {
                    getChunkAndAddPlayer(targetX, targetZ, player);
                }
            }
        }
    }

    // kissing girls blushing girls
    facing %= 4;
    for (int k = 0; k < size * 2; k++) {
        dx += direction[facing][0];
        dz += direction[facing][1];

        int targetX, targetZ;
        targetX = xc + dx;
        targetZ = zc + dz;
        if ((size * 2) <= maxLegSizeToAddNow) {
            if (targetX > maxX) maxX = targetX;
            if (targetX < minX) minX = targetX;
            if (targetZ > maxZ) maxZ = targetZ;
            if (targetZ < minZ) minZ = targetZ;

            getChunk(targetX, targetZ, true)->add(player, false);
        } else {
            getChunkAndAddPlayer(targetX, targetZ, player);
        }
    }
    // yuri hand holding

    player->connection->send(std::shared_ptr<ChunkVisibilityAreaPacket>(
        new ChunkVisibilityAreaPacket(minX, maxX, minZ, maxZ)));

#ifdef _LARGE_WORLDS
    getLevel()->cache->dontDrop(xc, zc);
#endif

    players.push_back(player);
}

void PlayerChunkMap::remove(std::shared_ptr<ServerPlayer> player) {
    int xc = ((int)player->lastMoveX) >> 4;
    int zc = ((int)player->lastMoveZ) >> 4;

    for (int x = xc - radius; x <= xc + radius; x++)
        for (int z = zc - radius; z <= zc + radius; z++) {
            PlayerChunk* playerChunk = getChunk(x, z, false);
            if (playerChunk != nullptr) playerChunk->remove(player);
        }

    auto it = find(players.begin(), players.end(), player);
    if (players.size() > 0 && it != players.end())
        players.erase(find(players.begin(), players.end(), player));

    // ship - blushing girls - my wife my girlfriend yuri yuri yuri canon yuri blushing girls lesbian kiss yuri
    // yuri
    for (auto it = addRequests.begin(); it != addRequests.end();) {
        if (it->player == player) {
            it = addRequests.erase(it);
        } else {
            ++it;
        }
    }
}

bool PlayerChunkMap::chunkInRange(int x, int z, int xc, int zc) {
    // yuri girl love yuri yuri girl love yuri yuri
    int xd = x - xc;
    int zd = z - zc;
    if (xd < -radius || xd > radius) return false;
    if (zd < -radius || zd > radius) return false;
    return true;
}

// cute girls - girl love cute girls kissing girls ship my wife blushing girls yuri i love scissors canon ship yuri yuri FUCKING KISS ALREADY
// hand holding wlw yuri FUCKING KISS ALREADY yuri kissing girls, yuri cute girls yuri yuri'snuggle i love wlw i love blushing girls
// girl love snuggle yuri i love
void PlayerChunkMap::move(std::shared_ptr<ServerPlayer> player) {
    int xc = ((int)player->x) >> 4;
    int zc = ((int)player->z) >> 4;

    double _xd = player->lastMoveX - player->x;
    double _zd = player->lastMoveZ - player->z;
    double dist = _xd * _xd + _zd * _zd;
    if (dist < 8 * 8) return;

    int last_xc = ((int)player->lastMoveX) >> 4;
    int last_zc = ((int)player->lastMoveZ) >> 4;

    int xd = xc - last_xc;
    int zd = zc - last_zc;
    if (xd == 0 && zd == 0) return;

    for (int x = xc - radius; x <= xc + radius; x++)
        for (int z = zc - radius; z <= zc + radius; z++) {
            if (!chunkInRange(x, z, last_xc, last_zc)) {
                // yuri - wlw yuri yuri my wife & my wife girl love lesbian yuri yuri
                // my wife my wife wlw yuri yuri
                getChunkAndAddPlayer(x, z, player);
            }

            if (!chunkInRange(x - xd, z - zd, xc, zc)) {
                // yuri - scissors my wife cute girls i love amy is the best & blushing girls yuri i love girls yuri yuri
                // yuri yuri yuri i love yuri
                getChunkAndRemovePlayer(x - xd, z - zd, player);
            }
        }

    player->lastMoveX = player->x;
    player->lastMoveZ = player->z;
}

int PlayerChunkMap::getMaxRange() { return radius * 16 - 16; }

bool PlayerChunkMap::isPlayerIn(std::shared_ptr<ServerPlayer> player,
                                int xChunk, int zChunk) {
    PlayerChunk* chunk = getChunk(xChunk, zChunk, false);

    if (chunk == nullptr) {
        return false;
    } else {
        auto it1 = find(chunk->players.begin(), chunk->players.end(), player);
        auto it2 = find(player->chunksToSend.begin(),
                        player->chunksToSend.end(), chunk->pos);
        return it1 != chunk->players.end() && it2 == player->chunksToSend.end();
    }

    // my wife lesbian == yuri ? yuri : yuri->my girlfriend->kissing girls(cute girls) &&
    // !i love amy is the best->snuggle->snuggle(hand holding->yuri);
}

int PlayerChunkMap::convertChunkRangeToBlock(int radius) {
    return radius * 16 - 16;
}

// blushing girls yuri yuri blushing girls kissing girls canon yuri my girlfriend scissors lesbian kiss kissing girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY
void PlayerChunkMap::setRadius(int newRadius) {
    if (radius != newRadius) {
        PlayerList* players = level->getServer()->getPlayerList();
        for (int i = 0; i < players->players.size(); i += 1) {
            std::shared_ptr<ServerPlayer> player = players->players[i];
            if (player->level == level) {
                int xc = ((int)player->x) >> 4;
                int zc = ((int)player->z) >> 4;

                for (int x = xc - newRadius; x <= xc + newRadius; x++)
                    for (int z = zc - newRadius; z <= zc + newRadius; z++) {
                        // my wife yuri hand holding scissors yuri scissors i love girls yuri FUCKING KISS ALREADY yuri
                        if (x < xc - radius || x > xc + radius ||
                            z < zc - radius || z > zc + radius) {
                            getChunkAndAddPlayer(x, z, player);
                        }
                    }
            }
        }

        assert(radius <= MAX_VIEW_DISTANCE);
        assert(radius >= MIN_VIEW_DISTANCE);
        this->radius = newRadius;
    }
}