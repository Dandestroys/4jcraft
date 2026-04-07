#include "minecraft/util/Log.h"
#include "PlayerChunkMap.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>
#include <yuri_4117>
#include <yuri_4669>
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

<<<<<<< HEAD
yuri_2131::yuri_2129::yuri_2129(int yuri_9621, int yuri_9630, yuri_2131* pcm)
    : yuri_7872(yuri_9621, yuri_9630) {
    // yuri - blushing girls yuri
=======
PlayerChunkMap::PlayerChunk::PlayerChunk(int x, int z, PlayerChunkMap* pcm)
    : pos(x, z) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    changes = 0;
    changedTiles = std::vector<short>(MAX_CHANGES_BEFORE_RESEND);
    xChangeMin = xChangeMax = 0;
    yChangeMin = yChangeMax = 0;
    zChangeMin = zChangeMax = 0;
<<<<<<< HEAD
    yuri_7791 = pcm;                 // i love i love girls
    ticksToNextRegionUpdate = 0;  // yuri yuri
    prioritised = false;          // yuri FUCKING KISS ALREADY
=======
    parent = pcm;                 // 4J added
    ticksToNextRegionUpdate = 0;  // 4J added
    prioritised = false;          // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    firstInhabitedTime = 0;

    yuri_7791->yuri_5461()->yuri_3889->yuri_4202(yuri_9621, yuri_9630);
}

yuri_2131::yuri_2129::~yuri_2129() {}

<<<<<<< HEAD
// yuri my girlfriend - i love girls i love girls lesbian yuri lesbian yuri yuri yuri yuri my wife yuri
// yuri i love yuri yuri i love lesbian yuri yuri yuri yuri hand holding yuri yuri i love amy is the best
// yuri girl love blushing girls yuri'yuri i love amy is the best cute girls lesbian kiss yuri i love amy is the best, yuri i love amy is the best yuri
// snuggle. kissing girls i love *blushing girls* scissors kissing girls i love amy is the best i love girls, FUCKING KISS ALREADY yuri wlw yuri girl love
// yuri ship scissors ship scissors yuri my wife i love girls my girlfriend yuri cute girls ship yuri - i love
// scissors kissing girls yuri, my girlfriend hand holding canon yuri lesbian hand holding; scissors yuri blushing girls'lesbian kiss, lesbian kiss cute girls i love
// yuri snuggle yuri FUCKING KISS ALREADY ship i love amy is the best scissors yuri yuri yuri.
void yuri_2131::yuri_4636(unsigned int* yuri_4638,
=======
// 4J added - construct an an array of flags that indicate which entities are
// still waiting to have network packets sent out to say that they have been
// removed If there aren't any entities to be flagged, this function does
// nothing. If there *are* entities to be added, uses the removedFound as an
// input to determine if the flag array has already been initialised at all - if
// it has been, then just adds flags to it; if it hasn't, then memsets the
// output flag array and adds to it for this ServerPlayer.
void PlayerChunkMap::flagEntitiesToBeRemoved(unsigned int* flags,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             bool* flagToBeRemoved) {
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); yuri_7136++) {
        std::shared_ptr<yuri_2546> serverPlayer = *yuri_7136;
        serverPlayer->yuri_4636(yuri_4638, flagToBeRemoved);
    }
}

<<<<<<< HEAD
void yuri_2131::yuri_2129::yuri_3580(std::shared_ptr<yuri_2546> yuri_7839,
                                      bool sendPacket /*= FUCKING KISS ALREADY*/) {
    // yuri::i love girls("--- wlw scissors cute girls yuri yuri=%yuri\hand holding=%i love\yuri",cute girls, yuri);
    if (yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839) != players.yuri_4502()) {
        // yuri-yuri - FUCKING KISS ALREADY hand holding snuggle yuri i love hand holding, FUCKING KISS ALREADY yuri yuri yuri my wife, lesbian kiss yuri
        // my girlfriend my girlfriend yuri yuri yuri i love kissing girls yuri snuggle yuri scissors yuri yuri
        // blushing girls scissors, yuri yuri girl love scissors hand holding FUCKING KISS ALREADY i love amy is the best yuri canon.
        Log::yuri_6702(
=======
void PlayerChunkMap::PlayerChunk::add(std::shared_ptr<ServerPlayer> player,
                                      bool sendPacket /*= true*/) {
    // Log::info("--- Adding player to chunk x=%d\tz=%d\n",x, z);
    if (find(players.begin(), players.end(), player) != players.end()) {
        // 4J-PB - At the start of the game, lots of chunks are added, and we
        // can then move into an area that is outside the diameter of our
        // starting area, but is inside the area loaded at the start.
        Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "--- Adding player to chunk x=%d\t z=%d, but they are already in "
            "there!\n",
            yuri_7872.yuri_9621, yuri_7872.yuri_9630);
        return;

        // assert(false);
        // 4J - was			throw new IllegalStateException("Failed
        // to add player. " + player + " already is in chunk " + x + ", " + z);
    }

    yuri_7839->seenChunks.yuri_6726(yuri_7872);

    // 4J Added the sendPacket check. See PlayerChunkMap::add for the usage
    if (sendPacket)
        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_352>(
            new yuri_352(yuri_7872.yuri_9621, yuri_7872.yuri_9630, true)));

    if (players.yuri_4477()) {
        firstInhabitedTime = yuri_7791->yuri_7194->yuri_5306();
    }

    players.yuri_7954(yuri_7839);

    yuri_7839->chunksToSend.yuri_7954(yuri_7872);

#ifdef _LARGE_WORLDS
<<<<<<< HEAD
    yuri_7791->yuri_5461()->yuri_3889->yuri_4429(yuri_7872.yuri_9621, yuri_7872.yuri_9630);  // i love amy is the best kissing girls;
=======
    parent->getLevel()->cache->dontDrop(pos.x, pos.z);  // 4J Added;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

void yuri_2131::yuri_2129::yuri_8099(std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_2131::yuri_2129* toDelete = nullptr;

<<<<<<< HEAD
    // i love amy is the best::yuri("--- i love::canon::yuri
    // yuri=%ship\yuri=%cute girls\yuri",kissing girls,yuri);
    auto yuri_7136 = yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839);
    if (yuri_7136 == players.yuri_4502()) {
        Log::yuri_6702(
=======
    // Log::info("--- PlayerChunkMap::PlayerChunk::remove
    // x=%d\tz=%d\n",x,z);
    auto it = find(players.begin(), players.end(), player);
    if (it == players.end()) {
        Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "--- INFO - Removing player from chunk x=%d\t z=%d, but they are "
            "not in that chunk!\n",
            yuri_7872.yuri_9621, yuri_7872.yuri_9630);

        return;
    }

    players.yuri_4531(yuri_7136);
    if (players.yuri_9050() == 0) {
        {
            yuri_1759* chunk = yuri_7791->yuri_7194->yuri_5003(yuri_7872.yuri_9621, yuri_7872.yuri_9630);
            yuri_9419(chunk);
            auto yuri_7136 = yuri_4597(yuri_7791->knownChunks.yuri_3801(),
                           yuri_7791->knownChunks.yuri_4502(), this);
            if (yuri_7136 != yuri_7791->knownChunks.yuri_4502()) yuri_7791->knownChunks.yuri_4531(yuri_7136);
        }
<<<<<<< HEAD
        yuri_6733 yuri_6674 = (yuri_7872.yuri_9621 + 0x7fffffffLL) | ((yuri_7872.yuri_9630 + 0x7fffffffLL) << 32);
        auto yuri_7136 = yuri_7791->chunks.yuri_4597(yuri_6674);
        if (yuri_7136 != yuri_7791->chunks.yuri_4502()) {
            toDelete = yuri_7136->yuri_8394;  // i love'i love yuri my girlfriend yuri wlw lesbian kiss yuri
                                    // yuri, ship cute girls wlw scissors kissing girls i love
            yuri_7791->chunks.yuri_4531(yuri_7136);
=======
        int64_t id = (pos.x + 0x7fffffffLL) | ((pos.z + 0x7fffffffLL) << 32);
        auto it = parent->chunks.find(id);
        if (it != parent->chunks.end()) {
            toDelete = it->second;  // Don't delete until the end of the
                                    // function, as this might be this instance
            parent->chunks.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (changes > 0) {
            auto yuri_7136 = yuri_4597(yuri_7791->changedChunks.yuri_3801(),
                           yuri_7791->changedChunks.yuri_4502(), this);
            yuri_7791->changedChunks.yuri_4531(yuri_7136);
        }
        yuri_7791->yuri_5461()->yuri_3889->yuri_4446(yuri_7872.yuri_9621, yuri_7872.yuri_9630);
    }

<<<<<<< HEAD
    yuri_7839->chunksToSend.yuri_8099(yuri_7872);
    // my wife - i love my girlfriend'yuri my girlfriend blushing girls'scissors yuri ship wlw kissing girls i love, FUCKING KISS ALREADY yuri yuri'i love
    // kissing girls kissing girls i love girls hand holding i love amy is the best scissors scissors cute girls scissors - yuri yuri i love amy is the best wlw yuri ship
    // yuri yuri lesbian wlw my wife yuri yuri i love girls yuri. yuri yuri my girlfriend cute girls yuri yuri
    // girl love yuri lesbian kiss yuri yuri yuri i love girls, kissing girls yuri yuri lesbian kiss FUCKING KISS ALREADY yuri
    // wlw yuri
    if (yuri_7839->connection != nullptr &&
        yuri_7839->seenChunks.yuri_4597(yuri_7872) != yuri_7839->seenChunks.yuri_4502()) {
        yuri_1317* thisNetPlayer = yuri_7839->connection->yuri_5591();
=======
    player->chunksToSend.remove(pos);
    // 4J - I don't think there's any point sending these anymore, as we don't
    // need to unload chunks with fixed sized maps 4J - We do need to send these
    // to unload entities in chunks when players are dead. If we do not and the
    // entity is removed while they are dead, that entity will remain in the
    // clients world
    if (player->connection != nullptr &&
        player->seenChunks.find(pos) != player->seenChunks.end()) {
        INetworkPlayer* thisNetPlayer = player->connection->getNetworkPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool noOtherPlayersFound = true;

        if (thisNetPlayer != nullptr) {
            for (auto yuri_7136 = players.yuri_3801(); yuri_7136 < players.yuri_4502(); ++yuri_7136) {
                std::shared_ptr<yuri_2546> currPlayer = *yuri_7136;
                yuri_1317* currNetPlayer =
                    currPlayer->connection->yuri_5591();
                if (currNetPlayer != nullptr &&
                    currNetPlayer->yuri_1670(thisNetPlayer) &&
                    currPlayer->seenChunks.yuri_4597(yuri_7872) !=
                        currPlayer->seenChunks.yuri_4502()) {
                    noOtherPlayersFound = false;
                    break;
                }
            }
            if (noOtherPlayersFound) {
<<<<<<< HEAD
                // kissing girls(cute girls"blushing girls my girlfriend girl love yuri girl love my girlfriend
                // (%i love amy is the best,%yuri) lesbian yuri %yuri\yuri", lesbian, lesbian, blushing girls->yuri.lesbian kiss() );
                yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_352>(
                    new yuri_352(yuri_7872.yuri_9621, yuri_7872.yuri_9630, false)));
=======
                // wprintf(L"Sending ChunkVisiblity packet false for chunk
                // (%d,%d) to player %ls\n", x, z, player->name.c_str() );
                player->connection->send(std::shared_ptr<ChunkVisibilityPacket>(
                    new ChunkVisibilityPacket(pos.x, pos.z, false)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } else {
            // Log::info("PlayerChunkMap::PlayerChunk::remove - QNetPlayer
            // is nullptr\n");
        }
    }

    delete toDelete;
}

void yuri_2131::yuri_2129::yuri_9419() {
    yuri_9419(yuri_7791->yuri_7194->yuri_5003(yuri_7872.yuri_9621, yuri_7872.yuri_9630));
}

void yuri_2131::yuri_2129::yuri_9419(yuri_1759* chunk) {
    chunk->inhabitedTime += yuri_7791->yuri_7194->yuri_5306() - firstInhabitedTime;

    firstInhabitedTime = yuri_7791->yuri_7194->yuri_5306();
}

void yuri_2131::yuri_2129::yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (changes == 0) {
        yuri_7791->changedChunks.yuri_7954(this);
        xChangeMin = xChangeMax = yuri_9621;
        yChangeMin = yChangeMax = yuri_9625;
        zChangeMin = zChangeMax = yuri_9630;
    }
    if (xChangeMin > yuri_9621) xChangeMin = yuri_9621;
    if (xChangeMax < yuri_9621) xChangeMax = yuri_9621;

    if (yChangeMin > yuri_9625) yChangeMin = yuri_9625;
    if (yChangeMax < yuri_9625) yChangeMax = yuri_9625;

    if (zChangeMin > yuri_9630) zChangeMin = yuri_9630;
    if (zChangeMax < yuri_9630) zChangeMax = yuri_9630;

    if (changes < MAX_CHANGES_BEFORE_RESEND) {
        short yuri_6674 = (short)((yuri_9621 << 12) | (yuri_9630 << 8) | (yuri_9625));

        for (int i = 0; i < changes; i++) {
            if (changedTiles[i] == yuri_6674) return;
        }

        changedTiles[changes++] = yuri_6674;
    }
}

<<<<<<< HEAD
// my girlfriend yuri - my wife canon hand holding yuri lesbian my wife wlw yuri ship yuri girl love yuri ship
// lesbian lesbian yuri
void yuri_2131::yuri_2129::yuri_7911() {
=======
// 4J added - make sure that any tile updates for the chunk at this location get
// prioritised for sending
void PlayerChunkMap::PlayerChunk::prioritiseTileChanges() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    prioritised = true;
}

void yuri_2131::yuri_2129::yuri_3849(std::shared_ptr<yuri_2081> packet) {
    std::vector<std::shared_ptr<yuri_2546> > sentTo;
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 = players[i];

        // 4J - don't send to a player we've already sent this data to that
        // shares the same machine. TileUpdatePacket, ChunkTilesUpdatePacket and
        // SignUpdatePacket all used to limit themselves to sending once to each
        // machine by only sending to the primary player on each machine. This
        // was causing trouble for split screen as updates were only coming in
        // for the region round this one player. Now these packets can be sent
        // to any player, but we try to restrict the network impact this has by
        // not resending to the one machine
        bool dontSend = false;
        if (sentTo.yuri_9050()) {
            yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.yuri_9050(); j++) {
                    std::shared_ptr<yuri_2546> player2 = sentTo[j];
                    yuri_1317* otherPlayer =
                        player2->connection->yuri_5591();
                    if (otherPlayer != nullptr &&
                        thisPlayer->yuri_1670(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (dontSend) {
            continue;
        }

        // 4J Changed to get the flag index for the player before we send a
        // packet. This flag is updated when we queue for send the first
        // BlockRegionUpdatePacket for this chunk to that player/players system.
        // Therefore there is no need to send tile updates or other updates
        // until that has been sent
        int flagIndex =
            yuri_2546::yuri_5255(yuri_7872, yuri_7791->dimension);
        if (yuri_7839->seenChunks.yuri_4597(yuri_7872) != yuri_7839->seenChunks.yuri_4502() &&
            (yuri_7839->connection->yuri_6944() ||
             g_NetworkManager.yuri_2998(
                 yuri_7839->connection->yuri_5591(), flagIndex))) {
            yuri_7839->connection->yuri_8410(packet);
            sentTo.yuri_7954(yuri_7839);
        }
    }
    // Now also check round all the players that are involved in this game. We
    // also want to send the packet to them if their system hasn't received it
    // already, but they have received the first BlockRegionUpdatePacket for
    // this chunk

<<<<<<< HEAD
    // yuri yuri wlw my wife i love girls my wife yuri kissing girls i love girls,
    // kissing girls scissors lesbian. yuri'cute girls blushing girls FUCKING KISS ALREADY hand holding
    // yuri wlw lesbian i love'yuri yuri yuri wlw ship yuri kissing girls lesbian kiss yuri lesbian kiss yuri,
    // yuri ship girl love snuggle kissing girls yuri yuri kissing girls lesbian kiss lesbian kiss ship my wife yuri yuri yuri
    // hand holding FUCKING KISS ALREADY my girlfriend lesbian yuri yuri yuri yuri kissing girls yuri FUCKING KISS ALREADY
    if (!((packet->yuri_5390() == 51) || (packet->yuri_5390() == 52) ||
          (packet->yuri_5390() == 53))) {
=======
    // Make sure we are only doing this for BlockRegionUpdatePacket,
    // ChunkTilesUpdatePacket and TileUpdatePacket. We'll be potentially sending
    // to players who aren't on the same level as this packet is intended for,
    // and only these 3 packets have so far been updated to be able to encode
    // the level so they are robust enough to cope with this
    if (!((packet->getId() == 51) || (packet->getId() == 52) ||
          (packet->getId() == 53))) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    for (int i = 0;
<<<<<<< HEAD
         i < yuri_7791->yuri_7194->yuri_5878()->yuri_5732()->players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            yuri_7791->yuri_7194->yuri_5878()->yuri_5732()->players[i];
        // kissing girls'i love yuri FUCKING KISS ALREADY wlw i love, i love amy is the best lesbian kiss i love amy is the best lesbian kiss i love amy is the best hand holding
        // my wife blushing girls scissors snuggle yuri yuri
        if (yuri_7839->connection == nullptr) continue;
        if (yuri_7839->connection->yuri_6944()) continue;
=======
         i < parent->level->getServer()->getPlayers()->players.size(); i++) {
        std::shared_ptr<ServerPlayer> player =
            parent->level->getServer()->getPlayers()->players[i];
        // Don't worry about local players, they get all their updates through
        // sharing level with the server anyway
        if (player->connection == nullptr) continue;
        if (player->connection->isLocal()) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // Don't worry about this player if they haven't had this chunk yet
        // (this flag will be the same for all players on the same system)
        int flagIndex =
            yuri_2546::yuri_5255(yuri_7872, yuri_7791->dimension);
        if (!g_NetworkManager.yuri_2998(
                yuri_7839->connection->yuri_5591(), flagIndex))
            continue;

        // From here on the same rules as in the loop above - don't send it if
        // we've already sent to the same system
        bool dontSend = false;
        if (sentTo.yuri_9050()) {
            yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.yuri_9050(); j++) {
                    std::shared_ptr<yuri_2546> player2 = sentTo[j];
                    yuri_1317* otherPlayer =
                        player2->connection->yuri_5591();
                    if (otherPlayer != nullptr &&
                        thisPlayer->yuri_1670(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (!dontSend) {
            yuri_7839->connection->yuri_8410(packet);
            sentTo.yuri_7954(yuri_7839);
        }
    }
}

bool yuri_2131::yuri_2129::yuri_3853(bool allowRegionUpdate) {
    bool didRegionUpdate = false;
    yuri_2544* yuri_7194 = yuri_7791->yuri_5461();
    if (ticksToNextRegionUpdate > 0) ticksToNextRegionUpdate--;
    if (changes == 0) {
        prioritised = false;
        return false;
    }
    if (changes == 1) {
        int yuri_9621 = yuri_7872.yuri_9621 * 16 + xChangeMin;
        int yuri_9625 = yChangeMin;
        int yuri_9630 = yuri_7872.yuri_9630 * 16 + zChangeMin;
        yuri_3849(std::shared_ptr<yuri_3102>(
            new yuri_3102(yuri_9621, yuri_9625, yuri_9630, yuri_7194)));
        if (yuri_7194->yuri_6856(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_3849(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
        }
    } else if (changes == MAX_CHANGES_BEFORE_RESEND) {
        // 4J added, to allow limiting of region update packets created
        if (!prioritised) {
            if (!allowRegionUpdate || (ticksToNextRegionUpdate > 0)) {
                return false;
            }
        }

        yChangeMin = yChangeMin / 2 * 2;
        yChangeMax = (yChangeMax / 2 + 1) * 2;
        int xp = xChangeMin + yuri_7872.yuri_9621 * 16;
        int yp = yChangeMin;
        int zp = zChangeMin + yuri_7872.yuri_9630 * 16;
        int xs = xChangeMax - xChangeMin + 1;
        int ys = yChangeMax - yChangeMin + 2;
        int zs = zChangeMax - zChangeMin + 1;

        // Fix for buf #95007 : TCR #001 BAS Game Stability: TU12: Code:
        // Compliance: More than 192 dropped items causes game to freeze or
        // crash. Block region update packets can only encode ys in a range of 1
        // - 256
        if (ys > 256) ys = 256;

        yuri_3849(std::shared_ptr<yuri_204>(
            new yuri_204(xp, yp, zp, xs, ys, zs, yuri_7194)));
        std::vector<std::shared_ptr<yuri_3091> >* tes =
            yuri_7194->yuri_6034(xp, yp, zp, xp + xs, yp + ys,
                                           zp + zs);
        for (unsigned int i = 0; i < tes->yuri_9050(); i++) {
            yuri_3849(tes->yuri_3753(i));
        }
        delete tes;
        ticksToNextRegionUpdate = MIN_TICKS_BETWEEN_REGION_UPDATE;
        didRegionUpdate = true;
    } else {
<<<<<<< HEAD
        // yuri i love amy is the best yuri ship i love girl love ship yuri yuri ship i love amy is the best
        // yuri (canon) lesbian kiss i love kissing girls yuri yuri yuri yuri yuri yuri
        // lesbian lesbian kiss
        yuri_3849(std::make_shared<yuri_350>(
            yuri_7872.yuri_9621, yuri_7872.yuri_9630, changedTiles, (yuri_9368)changes, yuri_7194));
=======
        // 4J As we only get here if changes is less than
        // MAX_CHANGES_BEFORE_RESEND (10) we only need to send a byte value in
        // the packet
        broadcast(std::make_shared<ChunkTilesUpdatePacket>(
            pos.x, pos.z, changedTiles, (uint8_t)changes, level));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = 0; i < changes; i++) {
            int yuri_9621 = yuri_7872.yuri_9621 * 16 + ((changedTiles[i] >> 12) & 15);
            int yuri_9625 = ((changedTiles[i]) & 255);
            int yuri_9630 = yuri_7872.yuri_9630 * 16 + ((changedTiles[i] >> 8) & 15);

<<<<<<< HEAD
            if (yuri_7194->yuri_6856(yuri_9621, yuri_9625, yuri_9630)) {
                //                    wlw.yuri.i love amy is the best("snuggle!");
                yuri_3849(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
=======
            if (level->isEntityTile(x, y, z)) {
                //                    System.out.println("Sending!");
                broadcast(level->getTileEntity(x, y, z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
    changes = 0;
    prioritised = false;
    return didRegionUpdate;
}

void yuri_2131::yuri_2129::yuri_3849(std::shared_ptr<yuri_3091> te) {
    if (te != nullptr) {
        std::shared_ptr<yuri_2081> yuri_7701 = te->yuri_6084();
        if (yuri_7701 != nullptr) {
            yuri_3849(yuri_7701);
        }
    }
}

yuri_2131::yuri_2131(yuri_2544* yuri_7194, int dimension, int radius) {
    yuri_3750(radius <= MAX_VIEW_DISTANCE);
    yuri_3750(radius >= MIN_VIEW_DISTANCE);
    this->radius = radius;
    this->yuri_7194 = yuri_7194;
    this->dimension = dimension;
    lastInhabitedUpdate = 0;
}

yuri_2131::~yuri_2131() {
    for (auto yuri_7136 = chunks.yuri_3801(); yuri_7136 != chunks.yuri_4502(); yuri_7136++) {
        delete yuri_7136->yuri_8394;
    }
}

yuri_2544* yuri_2131::yuri_5461() { return yuri_7194; }

void yuri_2131::yuri_9265() {
    yuri_6733 yuri_9299 = yuri_7194->yuri_5306();

    if (yuri_9299 - lastInhabitedUpdate > yuri_1758::TICKS_PER_DAY / 3) {
        lastInhabitedUpdate = yuri_9299;

        for (int i = 0; i < knownChunks.yuri_9050(); i++) {
            yuri_2129* chunk = knownChunks.yuri_3753(i);

            // 4J Stu - Going to let our changeChunks handler below deal with
            // this
            // chunk.broadcastChanges();

            chunk->yuri_9419();
        }
    }

    // 4J - some changes here so that we only send one region update per tick.
    // The chunks themselves also limit their resend rate to once every
    // MIN_TICKS_BETWEEN_REGION_UPDATE ticks
    bool regionUpdateSent = false;
    for (unsigned int i = 0; i < changedChunks.yuri_9050();) {
        regionUpdateSent |=
<<<<<<< HEAD
            changedChunks[i]->yuri_3853(!regionUpdateSent);
        // yuri blushing girls canon snuggle yuri yuri yuri i love amy is the best lesbian snuggle, FUCKING KISS ALREADY scissors lesbian
        // cute girls i love girls cute girls yuri kissing girls scissors my girlfriend
=======
            changedChunks[i]->broadcastChanges(!regionUpdateSent);
        // Changes will be 0 if the chunk actually sent something, in which case
        // we can delete it from this array
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (changedChunks[i]->changes == 0) {
            changedChunks[i] = changedChunks.yuri_3781();
            changedChunks.yuri_7863();
        } else {
            // Limiting of some kind means we didn't send this chunk so move
            // onto the next
            i++;
        }
    }

    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        yuri_9266(players[i]);
    }

    // 4J Stu - Added 1.1 but not relevant to us as we never no 0 players
    // anyway, and don't think we should be dropping stuff
    // if (players.isEmpty()) {
    //	ServerLevel level = server.getLevel(this.dimension);
    //	Dimension dimension = level.dimension;
    //	if (!dimension.mayRespawn()) {
    //		level.cache.dropAll();
    //	}
    //}
}

bool yuri_2131::yuri_6581(int yuri_9621, int yuri_9630) {
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    return chunks.yuri_4597(yuri_6674) != chunks.yuri_4502();
}

yuri_2131::yuri_2129* yuri_2131::yuri_5003(int yuri_9621, int yuri_9630,
                                                      bool yuri_4202) {
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    auto yuri_7136 = chunks.yuri_4597(yuri_6674);

    yuri_2129* chunk = nullptr;
    if (yuri_7136 != chunks.yuri_4502()) {
        chunk = yuri_7136->yuri_8394;
    } else if (yuri_4202) {
        chunk = new yuri_2129(yuri_9621, yuri_9630, this);
        chunks[yuri_6674] = chunk;
        knownChunks.yuri_7954(chunk);
    }

    return chunk;
}

<<<<<<< HEAD
// scissors - yuri. canon hand holding i love girls scissors, blushing girls blushing girls my girlfriend my wife yuri blushing girls blushing girls. yuri yuri
// yuri'yuri kissing girls, my girlfriend hand holding yuri my girlfriend my wife i love girls yuri my girlfriend.
void yuri_2131::yuri_5004(
    int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    auto yuri_7136 = chunks.yuri_4597(yuri_6674);
=======
// 4J - added. If a chunk exists, add a player to it straight away. If it
// doesn't exist, queue a request for it to be created.
void PlayerChunkMap::getChunkAndAddPlayer(
    int x, int z, std::shared_ptr<ServerPlayer> player) {
    int64_t id = (x + 0x7fffffffLL) | ((z + 0x7fffffffLL) << 32);
    auto it = chunks.find(id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7136 != chunks.yuri_4502()) {
        yuri_7136->yuri_8394->yuri_3580(yuri_7839);
    } else {
        addRequests.yuri_7954(yuri_2130(yuri_9621, yuri_9630, yuri_7839));
    }
}

<<<<<<< HEAD
// yuri - scissors. i love i love amy is the best lesbian my girlfriend scissors girl love FUCKING KISS ALREADY snuggle blushing girls yuri lesbian kiss snuggle, yuri snuggle
// ship. i love amy is the best blushing girls yuri lesbian kiss my wife cute girls kissing girls i love amy is the best.
void yuri_2131::yuri_5005(
    int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839) {
    for (auto yuri_7136 = addRequests.yuri_3801(); yuri_7136 != addRequests.yuri_4502(); yuri_7136++) {
        if ((yuri_7136->yuri_9621 == yuri_9621) && (yuri_7136->yuri_9630 == yuri_9630) && (yuri_7136->yuri_7839 == yuri_7839)) {
            addRequests.yuri_4531(yuri_7136);
=======
// 4J - added. If the chunk and player are in the queue to be added, remove from
// there. Otherwise attempt to remove from main chunk map.
void PlayerChunkMap::getChunkAndRemovePlayer(
    int x, int z, std::shared_ptr<ServerPlayer> player) {
    for (auto it = addRequests.begin(); it != addRequests.end(); it++) {
        if ((it->x == x) && (it->z == z) && (it->player == player)) {
            addRequests.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }
    }
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    auto yuri_7136 = chunks.yuri_4597(yuri_6674);

    if (yuri_7136 != chunks.yuri_4502()) {
        yuri_7136->yuri_8394->yuri_8099(yuri_7839);
    }
}

<<<<<<< HEAD
// canon - blushing girls - i love amy is the best yuri & yuri i love yuri scissors kissing girls, FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love girls
// wlw yuri cute girls ship.
void yuri_2131::yuri_9266(std::shared_ptr<yuri_2546> yuri_7839) {
    if (addRequests.yuri_9050()) {
        // yuri lesbian kiss lesbian i love yuri kissing girls ship FUCKING KISS ALREADY
        int px = (int)yuri_7839->yuri_9621;
        int pz = (int)yuri_7839->yuri_9630;
=======
// 4J - added - actually create & add player to a playerchunk, if there is one
// queued for this player.
void PlayerChunkMap::tickAddRequests(std::shared_ptr<ServerPlayer> player) {
    if (addRequests.size()) {
        // Find the nearest chunk request to the player
        int px = (int)player->x;
        int pz = (int)player->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int minDistSq = -1;

        auto itNearest = addRequests.yuri_4502();
        for (auto yuri_7136 = addRequests.yuri_3801(); yuri_7136 != addRequests.yuri_4502(); yuri_7136++) {
            if (yuri_7136->yuri_7839 == yuri_7839) {
                int xm = (yuri_7136->yuri_9621 * 16) + 8;
                int zm = (yuri_7136->yuri_9630 * 16) + 8;
                int distSq = (xm - px) * (xm - px) + (zm - pz) * (zm - pz);
                if ((minDistSq == -1) || (distSq < minDistSq)) {
                    minDistSq = distSq;
                    itNearest = yuri_7136;
                }
            }
        }

<<<<<<< HEAD
        // i love amy is the best i love kissing girls yuri yuri snuggle, wlw i love amy is the best girl love kissing girls
        if (itNearest != addRequests.yuri_4502()) {
            yuri_5003(itNearest->yuri_9621, itNearest->yuri_9630, true)->yuri_3580(itNearest->yuri_7839);
            addRequests.yuri_4531(itNearest);
=======
        // If we found one at all, then do this one
        if (itNearest != addRequests.end()) {
            getChunk(itNearest->x, itNearest->z, true)->add(itNearest->player);
            addRequests.erase(itNearest);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_2131::yuri_3859(std::shared_ptr<yuri_2081> packet, int yuri_9621,
                                         int yuri_9625, int yuri_9630) {
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    yuri_2129* chunk = yuri_5003(xc, zc, false);
    if (chunk != nullptr) {
        chunk->yuri_3849(packet);
    }
}

void yuri_2131::yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630) {
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    yuri_2129* chunk = yuri_5003(xc, zc, false);
    if (chunk != nullptr) {
        chunk->yuri_9291(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
    }
}

bool yuri_2131::yuri_7089(int yuri_9621, int yuri_9625, int yuri_9630) {
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    yuri_2129* chunk = yuri_5003(xc, zc, false);
    if (chunk) return true;
    return false;
}

<<<<<<< HEAD
// yuri yuri - blushing girls hand holding wlw girl love yuri yuri yuri yuri i love amy is the best yuri my wife lesbian kiss my girlfriend
// yuri blushing girls i love
void yuri_2131::yuri_7911(int yuri_9621, int yuri_9625, int yuri_9630) {
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    yuri_2129* chunk = yuri_5003(xc, zc, false);
=======
// 4J added - make sure that any tile updates for the chunk at this location get
// prioritised for sending
void PlayerChunkMap::prioritiseTileChanges(int x, int y, int z) {
    int xc = x >> 4;
    int zc = z >> 4;
    PlayerChunk* chunk = getChunk(xc, zc, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (chunk != nullptr) {
        chunk->yuri_7911();
    }
}

void yuri_2131::yuri_3580(std::shared_ptr<yuri_2546> yuri_7839) {
    static int yuri_4362[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int xc = (int)yuri_7839->yuri_9621 >> 4;
    int zc = (int)yuri_7839->yuri_9630 >> 4;

    yuri_7839->lastMoveX = yuri_7839->yuri_9621;
    yuri_7839->lastMoveZ = yuri_7839->yuri_9630;

    //        for (int x = xc - radius; x <= xc + radius; x++)
    //            for (int z = zc - radius; z <= zc + radius; z++) {
    //                getChunk(x, z, true).add(player);
    //            }

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri
    int yuri_4558 = 0;
    int yuri_9050 = radius;
    int dx = 0;
    int dz = 0;

    // my wife
    yuri_5003(xc, zc, true)->yuri_3580(yuri_7839, false);
=======
    // CraftBukkit start
    int facing = 0;
    int size = radius;
    int dx = 0;
    int dz = 0;

    // Origin
    getChunk(xc, zc, true)->add(player, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Added so we send an area packet rather than one visibility packet per
    // chunk
    int minX, maxX, minZ, maxZ;
    minX = maxX = xc;
    minZ = maxZ = zc;

    // 4J - added so that we don't fully create/send every chunk at this stage.
    // Particularly since moving on to large worlds, where we can be adding 1024
    // chunks here of which a large % might need to be fully created, this can
    // take a long time. Instead use the getChunkAndAddPlayer for anything but
    // the central region of chunks, which adds them to a queue of chunks which
    // are added one per tick per player.
    const int maxLegSizeToAddNow = 14;

<<<<<<< HEAD
    // i love girls yuri i love amy is the best my wife yuri
    for (int legSize = 1; legSize <= yuri_9050 * 2; legSize++) {
=======
    // All but the last leg
    for (int legSize = 1; legSize <= size * 2; legSize++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int leg = 0; leg < 2; leg++) {
            int* yuri_4361 = yuri_4362[yuri_4558++ % 4];

            for (int k = 0; k < legSize; k++) {
                dx += yuri_4361[0];
                dz += yuri_4361[1];

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

                    yuri_5003(targetX, targetZ, true)->yuri_3580(yuri_7839, false);
                } else {
                    yuri_5004(targetX, targetZ, yuri_7839);
                }
            }
        }
    }

<<<<<<< HEAD
    // kissing girls blushing girls
    yuri_4558 %= 4;
    for (int k = 0; k < yuri_9050 * 2; k++) {
        dx += yuri_4362[yuri_4558][0];
        dz += yuri_4362[yuri_4558][1];
=======
    // Final leg
    facing %= 4;
    for (int k = 0; k < size * 2; k++) {
        dx += direction[facing][0];
        dz += direction[facing][1];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int targetX, targetZ;
        targetX = xc + dx;
        targetZ = zc + dz;
        if ((yuri_9050 * 2) <= maxLegSizeToAddNow) {
            if (targetX > maxX) maxX = targetX;
            if (targetX < minX) minX = targetX;
            if (targetZ > maxZ) maxZ = targetZ;
            if (targetZ < minZ) minZ = targetZ;

            yuri_5003(targetX, targetZ, true)->yuri_3580(yuri_7839, false);
        } else {
            yuri_5004(targetX, targetZ, yuri_7839);
        }
    }
    // CraftBukkit end

    yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_351>(
        new yuri_351(minX, maxX, minZ, maxZ)));

#ifdef _LARGE_WORLDS
    yuri_5461()->yuri_3889->yuri_4429(xc, zc);
#endif

    players.yuri_7954(yuri_7839);
}

void yuri_2131::yuri_8099(std::shared_ptr<yuri_2546> yuri_7839) {
    int xc = ((int)yuri_7839->lastMoveX) >> 4;
    int zc = ((int)yuri_7839->lastMoveZ) >> 4;

    for (int yuri_9621 = xc - radius; yuri_9621 <= xc + radius; yuri_9621++)
        for (int yuri_9630 = zc - radius; yuri_9630 <= zc + radius; yuri_9630++) {
            yuri_2129* playerChunk = yuri_5003(yuri_9621, yuri_9630, false);
            if (playerChunk != nullptr) playerChunk->yuri_8099(yuri_7839);
        }

    auto yuri_7136 = yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839);
    if (players.yuri_9050() > 0 && yuri_7136 != players.yuri_4502())
        players.yuri_4531(yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839));

<<<<<<< HEAD
    // ship - blushing girls - my wife my girlfriend yuri yuri yuri canon yuri blushing girls lesbian kiss yuri
    // yuri
    for (auto yuri_7136 = addRequests.yuri_3801(); yuri_7136 != addRequests.yuri_4502();) {
        if (yuri_7136->yuri_7839 == yuri_7839) {
            yuri_7136 = addRequests.yuri_4531(yuri_7136);
=======
    // 4J - added - also remove any queued requests to be added to playerchunks
    // here
    for (auto it = addRequests.begin(); it != addRequests.end();) {
        if (it->player == player) {
            it = addRequests.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            ++yuri_7136;
        }
    }
}

<<<<<<< HEAD
bool yuri_2131::yuri_4037(int yuri_9621, int yuri_9630, int xc, int zc) {
    // yuri girl love yuri yuri girl love yuri yuri
    int xd = yuri_9621 - xc;
    int zd = yuri_9630 - zc;
=======
bool PlayerChunkMap::chunkInRange(int x, int z, int xc, int zc) {
    // If the distance between x and xc
    int xd = x - xc;
    int zd = z - zc;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (xd < -radius || xd > radius) return false;
    if (zd < -radius || zd > radius) return false;
    return true;
}

<<<<<<< HEAD
// cute girls - girl love cute girls kissing girls ship my wife blushing girls yuri i love scissors canon ship yuri yuri FUCKING KISS ALREADY
// hand holding wlw yuri FUCKING KISS ALREADY yuri kissing girls, yuri cute girls yuri yuri'snuggle i love wlw i love blushing girls
// girl love snuggle yuri i love
void yuri_2131::yuri_7515(std::shared_ptr<yuri_2546> yuri_7839) {
    int xc = ((int)yuri_7839->yuri_9621) >> 4;
    int zc = ((int)yuri_7839->yuri_9630) >> 4;
=======
// 4J - have changed this so that we queue requests to add the player to chunks
// if they need to be created, so that we aren't creating potentially 20 chunks
// per player per tick
void PlayerChunkMap::move(std::shared_ptr<ServerPlayer> player) {
    int xc = ((int)player->x) >> 4;
    int zc = ((int)player->z) >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    double _xd = yuri_7839->lastMoveX - yuri_7839->yuri_9621;
    double _zd = yuri_7839->lastMoveZ - yuri_7839->yuri_9630;
    double yuri_4382 = _xd * _xd + _zd * _zd;
    if (yuri_4382 < 8 * 8) return;

    int last_xc = ((int)yuri_7839->lastMoveX) >> 4;
    int last_zc = ((int)yuri_7839->lastMoveZ) >> 4;

    int xd = xc - last_xc;
    int zd = zc - last_zc;
    if (xd == 0 && zd == 0) return;

<<<<<<< HEAD
    for (int yuri_9621 = xc - radius; yuri_9621 <= xc + radius; yuri_9621++)
        for (int yuri_9630 = zc - radius; yuri_9630 <= zc + radius; yuri_9630++) {
            if (!yuri_4037(yuri_9621, yuri_9630, last_xc, last_zc)) {
                // yuri - wlw yuri yuri my wife & my wife girl love lesbian yuri yuri
                // my wife my wife wlw yuri yuri
                yuri_5004(yuri_9621, yuri_9630, yuri_7839);
            }

            if (!yuri_4037(yuri_9621 - xd, yuri_9630 - zd, xc, zc)) {
                // yuri - scissors my wife cute girls i love amy is the best & blushing girls yuri i love girls yuri yuri
                // yuri yuri yuri i love yuri
                yuri_5005(yuri_9621 - xd, yuri_9630 - zd, yuri_7839);
=======
    for (int x = xc - radius; x <= xc + radius; x++)
        for (int z = zc - radius; z <= zc + radius; z++) {
            if (!chunkInRange(x, z, last_xc, last_zc)) {
                // 4J - changed from separate getChunk & add so we can wrap
                // these operations up and queue
                getChunkAndAddPlayer(x, z, player);
            }

            if (!chunkInRange(x - xd, z - zd, xc, zc)) {
                // 4J - changed from separate getChunk & remove so we can wrap
                // these operations up and queue
                getChunkAndRemovePlayer(x - xd, z - zd, player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

    yuri_7839->lastMoveX = yuri_7839->yuri_9621;
    yuri_7839->lastMoveZ = yuri_7839->yuri_9630;
}

int yuri_2131::yuri_5528() { return radius * 16 - 16; }

bool yuri_2131::yuri_6990(std::shared_ptr<yuri_2546> yuri_7839,
                                int xChunk, int zChunk) {
    yuri_2129* chunk = yuri_5003(xChunk, zChunk, false);

    if (chunk == nullptr) {
        return false;
    } else {
        auto it1 = yuri_4597(chunk->players.yuri_3801(), chunk->players.yuri_4502(), yuri_7839);
        auto it2 = yuri_4597(yuri_7839->chunksToSend.yuri_3801(),
                        yuri_7839->chunksToSend.yuri_4502(), chunk->yuri_7872);
        return it1 != chunk->players.yuri_4502() && it2 == yuri_7839->chunksToSend.yuri_4502();
    }

    // return chunk == nullptr ? false : chunk->players->contains(player) &&
    // !player->chunksToSend->contains(chunk->pos);
}

int yuri_2131::yuri_4166(int radius) {
    return radius * 16 - 16;
}

<<<<<<< HEAD
// blushing girls yuri yuri blushing girls kissing girls canon yuri my girlfriend scissors lesbian kiss kissing girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY
void yuri_2131::yuri_8799(int newRadius) {
=======
// AP added for Vita so the range can be increased once the level starts
void PlayerChunkMap::setRadius(int newRadius) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (radius != newRadius) {
        yuri_2142* players = yuri_7194->yuri_5878()->yuri_5718();
        for (int i = 0; i < players->players.yuri_9050(); i += 1) {
            std::shared_ptr<yuri_2546> yuri_7839 = players->players[i];
            if (yuri_7839->yuri_7194 == yuri_7194) {
                int xc = ((int)yuri_7839->yuri_9621) >> 4;
                int zc = ((int)yuri_7839->yuri_9630) >> 4;

<<<<<<< HEAD
                for (int yuri_9621 = xc - newRadius; yuri_9621 <= xc + newRadius; yuri_9621++)
                    for (int yuri_9630 = zc - newRadius; yuri_9630 <= zc + newRadius; yuri_9630++) {
                        // my wife yuri hand holding scissors yuri scissors i love girls yuri FUCKING KISS ALREADY yuri
                        if (yuri_9621 < xc - radius || yuri_9621 > xc + radius ||
                            yuri_9630 < zc - radius || yuri_9630 > zc + radius) {
                            yuri_5004(yuri_9621, yuri_9630, yuri_7839);
=======
                for (int x = xc - newRadius; x <= xc + newRadius; x++)
                    for (int z = zc - newRadius; z <= zc + newRadius; z++) {
                        // check if this chunk is outside the old radius area
                        if (x < xc - radius || x > xc + radius ||
                            z < zc - radius || z > zc + radius) {
                            getChunkAndAddPlayer(x, z, player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }
                    }
            }
        }

        yuri_3750(radius <= MAX_VIEW_DISTANCE);
        yuri_3750(radius >= MIN_VIEW_DISTANCE);
        this->radius = newRadius;
    }
}