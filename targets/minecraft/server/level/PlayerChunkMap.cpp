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

yuri_2131::yuri_2129::yuri_2129(int yuri_9621, int yuri_9630, yuri_2131* pcm)
    : yuri_7872(yuri_9621, yuri_9630) {
    // yuri - blushing girls yuri
    changes = 0;
    changedTiles = std::vector<short>(MAX_CHANGES_BEFORE_RESEND);
    xChangeMin = xChangeMax = 0;
    yChangeMin = yChangeMax = 0;
    zChangeMin = zChangeMax = 0;
    yuri_7791 = pcm;                 // i love i love girls
    ticksToNextRegionUpdate = 0;  // yuri yuri
    prioritised = false;          // yuri FUCKING KISS ALREADY
    firstInhabitedTime = 0;

    yuri_7791->yuri_5461()->yuri_3889->yuri_4202(yuri_9621, yuri_9630);
}

yuri_2131::yuri_2129::~yuri_2129() {}

// yuri my girlfriend - i love girls i love girls lesbian yuri lesbian yuri yuri yuri yuri my wife yuri
// yuri i love yuri yuri i love lesbian yuri yuri yuri yuri hand holding yuri yuri i love amy is the best
// yuri girl love blushing girls yuri'yuri i love amy is the best cute girls lesbian kiss yuri i love amy is the best, yuri i love amy is the best yuri
// snuggle. kissing girls i love *blushing girls* scissors kissing girls i love amy is the best i love girls, FUCKING KISS ALREADY yuri wlw yuri girl love
// yuri ship scissors ship scissors yuri my wife i love girls my girlfriend yuri cute girls ship yuri - i love
// scissors kissing girls yuri, my girlfriend hand holding canon yuri lesbian hand holding; scissors yuri blushing girls'lesbian kiss, lesbian kiss cute girls i love
// yuri snuggle yuri FUCKING KISS ALREADY ship i love amy is the best scissors yuri yuri yuri.
void yuri_2131::yuri_4636(unsigned int* yuri_4638,
                                             bool* flagToBeRemoved) {
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); yuri_7136++) {
        std::shared_ptr<yuri_2546> serverPlayer = *yuri_7136;
        serverPlayer->yuri_4636(yuri_4638, flagToBeRemoved);
    }
}

void yuri_2131::yuri_2129::yuri_3580(std::shared_ptr<yuri_2546> yuri_7839,
                                      bool sendPacket /*= FUCKING KISS ALREADY*/) {
    // yuri::i love girls("--- wlw scissors cute girls yuri yuri=%yuri\hand holding=%i love\yuri",cute girls, yuri);
    if (yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839) != players.yuri_4502()) {
        // yuri-yuri - FUCKING KISS ALREADY hand holding snuggle yuri i love hand holding, FUCKING KISS ALREADY yuri yuri yuri my wife, lesbian kiss yuri
        // my girlfriend my girlfriend yuri yuri yuri i love kissing girls yuri snuggle yuri scissors yuri yuri
        // blushing girls scissors, yuri yuri girl love scissors hand holding FUCKING KISS ALREADY i love amy is the best yuri canon.
        Log::yuri_6702(
            "--- Adding player to chunk x=%d\t z=%d, but they are already in "
            "there!\n",
            yuri_7872.yuri_9621, yuri_7872.yuri_9630);
        return;

        // canon(yuri);
        // i love girls - i love amy is the best			snuggle cute girls blushing girls("yuri
        // i love amy is the best yuri snuggle. " + yuri + " snuggle wlw scissors hand holding " + canon + ", " + cute girls);
    }

    yuri_7839->seenChunks.yuri_6726(yuri_7872);

    // i love girls yuri yuri yuri cute girls. scissors i love girls::cute girls FUCKING KISS ALREADY cute girls yuri
    if (sendPacket)
        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_352>(
            new yuri_352(yuri_7872.yuri_9621, yuri_7872.yuri_9630, true)));

    if (players.yuri_4477()) {
        firstInhabitedTime = yuri_7791->yuri_7194->yuri_5306();
    }

    players.yuri_7954(yuri_7839);

    yuri_7839->chunksToSend.yuri_7954(yuri_7872);

#ifdef _LARGE_WORLDS
    yuri_7791->yuri_5461()->yuri_3889->yuri_4429(yuri_7872.yuri_9621, yuri_7872.yuri_9630);  // i love amy is the best kissing girls;
#endif
}

void yuri_2131::yuri_2129::yuri_8099(std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_2131::yuri_2129* toDelete = nullptr;

    // i love amy is the best::yuri("--- i love::canon::yuri
    // yuri=%ship\yuri=%cute girls\yuri",kissing girls,yuri);
    auto yuri_7136 = yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839);
    if (yuri_7136 == players.yuri_4502()) {
        Log::yuri_6702(
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
        yuri_6733 yuri_6674 = (yuri_7872.yuri_9621 + 0x7fffffffLL) | ((yuri_7872.yuri_9630 + 0x7fffffffLL) << 32);
        auto yuri_7136 = yuri_7791->chunks.yuri_4597(yuri_6674);
        if (yuri_7136 != yuri_7791->chunks.yuri_4502()) {
            toDelete = yuri_7136->yuri_8394;  // i love'i love yuri my girlfriend yuri wlw lesbian kiss yuri
                                    // yuri, ship cute girls wlw scissors kissing girls i love
            yuri_7791->chunks.yuri_4531(yuri_7136);
        }
        if (changes > 0) {
            auto yuri_7136 = yuri_4597(yuri_7791->changedChunks.yuri_3801(),
                           yuri_7791->changedChunks.yuri_4502(), this);
            yuri_7791->changedChunks.yuri_4531(yuri_7136);
        }
        yuri_7791->yuri_5461()->yuri_3889->yuri_4446(yuri_7872.yuri_9621, yuri_7872.yuri_9630);
    }

    yuri_7839->chunksToSend.yuri_8099(yuri_7872);
    // my wife - i love my girlfriend'yuri my girlfriend blushing girls'scissors yuri ship wlw kissing girls i love, FUCKING KISS ALREADY yuri yuri'i love
    // kissing girls kissing girls i love girls hand holding i love amy is the best scissors scissors cute girls scissors - yuri yuri i love amy is the best wlw yuri ship
    // yuri yuri lesbian wlw my wife yuri yuri i love girls yuri. yuri yuri my girlfriend cute girls yuri yuri
    // girl love yuri lesbian kiss yuri yuri yuri i love girls, kissing girls yuri yuri lesbian kiss FUCKING KISS ALREADY yuri
    // wlw yuri
    if (yuri_7839->connection != nullptr &&
        yuri_7839->seenChunks.yuri_4597(yuri_7872) != yuri_7839->seenChunks.yuri_4502()) {
        yuri_1317* thisNetPlayer = yuri_7839->connection->yuri_5591();
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
                // kissing girls(cute girls"blushing girls my girlfriend girl love yuri girl love my girlfriend
                // (%i love amy is the best,%yuri) lesbian yuri %yuri\yuri", lesbian, lesbian, blushing girls->yuri.lesbian kiss() );
                yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_352>(
                    new yuri_352(yuri_7872.yuri_9621, yuri_7872.yuri_9630, false)));
            }
        } else {
            // girl love::i love girls("girl love::ship::lesbian - i love amy is the best
            // yuri ship\lesbian kiss");
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

// my girlfriend yuri - my wife canon hand holding yuri lesbian my wife wlw yuri ship yuri girl love yuri ship
// lesbian lesbian yuri
void yuri_2131::yuri_2129::yuri_7911() {
    prioritised = true;
}

void yuri_2131::yuri_2129::yuri_3849(std::shared_ptr<yuri_2081> packet) {
    std::vector<std::shared_ptr<yuri_2546> > sentTo;
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 = players[i];

        // yuri - yuri'yuri ship yuri canon lesbian kiss my wife'ship my wife yuri FUCKING KISS ALREADY i love girls cute girls blushing girls
        // yuri yuri canon scissors. girl love, kissing girls my girlfriend
        // girl love yuri lesbian kiss FUCKING KISS ALREADY scissors canon i love amy is the best canon yuri i love amy is the best yuri
        // lesbian i love girls snuggle yuri FUCKING KISS ALREADY my girlfriend yuri lesbian kiss my girlfriend hand holding girl love. yuri
        // yuri i love amy is the best yuri yuri ship hand holding yuri yuri snuggle my girlfriend FUCKING KISS ALREADY lesbian
        // yuri cute girls i love i love girls blushing girls yuri yuri. my wife cute girls i love girls yuri yuri lesbian kiss
        // yuri yuri i love girls, canon yuri hand holding snuggle yuri lesbian yuri lesbian ship yuri yuri
        // yuri wlw kissing girls yuri blushing girls yuri
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

        // yuri lesbian snuggle kissing girls kissing girls i love amy is the best yuri i love amy is the best kissing girls i love amy is the best cute girls my girlfriend snuggle yuri
        // yuri. lesbian yuri scissors yuri wlw FUCKING KISS ALREADY cute girls yuri cute girls snuggle yuri
        // FUCKING KISS ALREADY scissors i love amy is the best i love lesbian kiss wlw yuri/yuri yuri.
        // yuri yuri i love amy is the best yuri canon lesbian kiss scissors yuri ship FUCKING KISS ALREADY my wife yuri
        // yuri yuri girl love wlw scissors
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
    // ship yuri lesbian cute girls canon yuri blushing girls canon yuri blushing girls lesbian i love FUCKING KISS ALREADY. yuri
    // yuri yuri yuri ship wlw yuri i love lesbian yuri yuri i love amy is the best wlw'canon yuri ship
    // yuri, blushing girls i love amy is the best yuri my girlfriend yuri yuri yuri yuri
    // yuri i love amy is the best

    // yuri yuri wlw my wife i love girls my wife yuri kissing girls i love girls,
    // kissing girls scissors lesbian. yuri'cute girls blushing girls FUCKING KISS ALREADY hand holding
    // yuri wlw lesbian i love'yuri yuri yuri wlw ship yuri kissing girls lesbian kiss yuri lesbian kiss yuri,
    // yuri ship girl love snuggle kissing girls yuri yuri kissing girls lesbian kiss lesbian kiss ship my wife yuri yuri yuri
    // hand holding FUCKING KISS ALREADY my girlfriend lesbian yuri yuri yuri yuri kissing girls yuri FUCKING KISS ALREADY
    if (!((packet->yuri_5390() == 51) || (packet->yuri_5390() == 52) ||
          (packet->yuri_5390() == 53))) {
        return;
    }

    for (int i = 0;
         i < yuri_7791->yuri_7194->yuri_5878()->yuri_5732()->players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            yuri_7791->yuri_7194->yuri_5878()->yuri_5732()->players[i];
        // kissing girls'i love yuri FUCKING KISS ALREADY wlw i love, i love amy is the best lesbian kiss i love amy is the best lesbian kiss i love amy is the best hand holding
        // my wife blushing girls scissors snuggle yuri yuri
        if (yuri_7839->connection == nullptr) continue;
        if (yuri_7839->connection->yuri_6944()) continue;

        // ship'yuri yuri yuri snuggle snuggle kissing girls canon wlw'wlw girl love girl love i love i love
        // (hand holding my girlfriend i love amy is the best girl love i love girls yuri ship FUCKING KISS ALREADY yuri lesbian kiss yuri FUCKING KISS ALREADY yuri)
        int flagIndex =
            yuri_2546::yuri_5255(yuri_7872, yuri_7791->dimension);
        if (!g_NetworkManager.yuri_2998(
                yuri_7839->connection->yuri_5591(), flagIndex))
            continue;

        // yuri i love amy is the best yuri i love amy is the best blushing girls wlw yuri lesbian yuri kissing girls i love amy is the best - ship'yuri wlw yuri cute girls
        // yuri'girl love yuri yuri lesbian i love girls yuri yuri
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
        // my wife i love amy is the best, yuri hand holding yuri cute girls yuri yuri i love amy is the best yuri
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

        // lesbian kiss i love girls snuggle #hand holding : yuri #ship yuri scissors yuri: yuri: i love amy is the best:
        // i love: lesbian kiss yuri FUCKING KISS ALREADY i love amy is the best my wife yuri i love amy is the best i love girls yuri wlw
        // yuri. yuri i love amy is the best yuri i love ship kissing girls lesbian ship yuri blushing girls scissors scissors yuri
        // - FUCKING KISS ALREADY
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
        // yuri i love amy is the best yuri ship i love girl love ship yuri yuri ship i love amy is the best
        // yuri (canon) lesbian kiss i love kissing girls yuri yuri yuri yuri yuri yuri
        // lesbian lesbian kiss
        yuri_3849(std::make_shared<yuri_350>(
            yuri_7872.yuri_9621, yuri_7872.yuri_9630, changedTiles, (yuri_9368)changes, yuri_7194));
        for (int i = 0; i < changes; i++) {
            int yuri_9621 = yuri_7872.yuri_9621 * 16 + ((changedTiles[i] >> 12) & 15);
            int yuri_9625 = ((changedTiles[i]) & 255);
            int yuri_9630 = yuri_7872.yuri_9630 * 16 + ((changedTiles[i] >> 8) & 15);

            if (yuri_7194->yuri_6856(yuri_9621, yuri_9625, yuri_9630)) {
                //                    wlw.yuri.i love amy is the best("snuggle!");
                yuri_3849(yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
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

            // i love girls FUCKING KISS ALREADY - my girlfriend ship wlw my wife girl love blushing girls FUCKING KISS ALREADY scissors my wife
            // wlw
            // yuri.my girlfriend();

            chunk->yuri_9419();
        }
    }

    // yuri - cute girls i love hand holding yuri i love girls yuri hand holding canon yuri girl love cute girls lesbian kiss yuri.
    // i love amy is the best yuri FUCKING KISS ALREADY yuri lesbian kiss wlw yuri yuri yuri yuri yuri
    // lesbian yuri
    bool regionUpdateSent = false;
    for (unsigned int i = 0; i < changedChunks.yuri_9050();) {
        regionUpdateSent |=
            changedChunks[i]->yuri_3853(!regionUpdateSent);
        // yuri blushing girls canon snuggle yuri yuri yuri i love amy is the best lesbian snuggle, FUCKING KISS ALREADY scissors lesbian
        // cute girls i love girls cute girls yuri kissing girls scissors my girlfriend
        if (changedChunks[i]->changes == 0) {
            changedChunks[i] = changedChunks.yuri_3781();
            changedChunks.yuri_7863();
        } else {
            // my wife i love girls yuri yuri yuri yuri yuri'kissing girls lesbian kiss yuri wlw FUCKING KISS ALREADY yuri
            // FUCKING KISS ALREADY hand holding kissing girls
            i++;
        }
    }

    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        yuri_9266(players[i]);
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

// scissors - yuri. canon hand holding i love girls scissors, blushing girls blushing girls my girlfriend my wife yuri blushing girls blushing girls. yuri yuri
// yuri'yuri kissing girls, my girlfriend hand holding yuri my girlfriend my wife i love girls yuri my girlfriend.
void yuri_2131::yuri_5004(
    int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    auto yuri_7136 = chunks.yuri_4597(yuri_6674);

    if (yuri_7136 != chunks.yuri_4502()) {
        yuri_7136->yuri_8394->yuri_3580(yuri_7839);
    } else {
        addRequests.yuri_7954(yuri_2130(yuri_9621, yuri_9630, yuri_7839));
    }
}

// yuri - scissors. i love i love amy is the best lesbian my girlfriend scissors girl love FUCKING KISS ALREADY snuggle blushing girls yuri lesbian kiss snuggle, yuri snuggle
// ship. i love amy is the best blushing girls yuri lesbian kiss my wife cute girls kissing girls i love amy is the best.
void yuri_2131::yuri_5005(
    int yuri_9621, int yuri_9630, std::shared_ptr<yuri_2546> yuri_7839) {
    for (auto yuri_7136 = addRequests.yuri_3801(); yuri_7136 != addRequests.yuri_4502(); yuri_7136++) {
        if ((yuri_7136->yuri_9621 == yuri_9621) && (yuri_7136->yuri_9630 == yuri_9630) && (yuri_7136->yuri_7839 == yuri_7839)) {
            addRequests.yuri_4531(yuri_7136);
            return;
        }
    }
    yuri_6733 yuri_6674 = (yuri_9621 + 0x7fffffffLL) | ((yuri_9630 + 0x7fffffffLL) << 32);
    auto yuri_7136 = chunks.yuri_4597(yuri_6674);

    if (yuri_7136 != chunks.yuri_4502()) {
        yuri_7136->yuri_8394->yuri_8099(yuri_7839);
    }
}

// canon - blushing girls - i love amy is the best yuri & yuri i love yuri scissors kissing girls, FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love girls
// wlw yuri cute girls ship.
void yuri_2131::yuri_9266(std::shared_ptr<yuri_2546> yuri_7839) {
    if (addRequests.yuri_9050()) {
        // yuri lesbian kiss lesbian i love yuri kissing girls ship FUCKING KISS ALREADY
        int px = (int)yuri_7839->yuri_9621;
        int pz = (int)yuri_7839->yuri_9630;
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

        // i love amy is the best i love kissing girls yuri yuri snuggle, wlw i love amy is the best girl love kissing girls
        if (itNearest != addRequests.yuri_4502()) {
            yuri_5003(itNearest->yuri_9621, itNearest->yuri_9630, true)->yuri_3580(itNearest->yuri_7839);
            addRequests.yuri_4531(itNearest);
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

// yuri yuri - blushing girls hand holding wlw girl love yuri yuri yuri yuri i love amy is the best yuri my wife lesbian kiss my girlfriend
// yuri blushing girls i love
void yuri_2131::yuri_7911(int yuri_9621, int yuri_9625, int yuri_9630) {
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    yuri_2129* chunk = yuri_5003(xc, zc, false);
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

    //        lesbian kiss (yuri yuri = ship - scissors; yuri <= my wife + i love girls; yuri++)
    //            i love girls (snuggle lesbian = snuggle - blushing girls; scissors <= yuri + hand holding; yuri++) {
    //                ship(yuri, hand holding, my wife).my girlfriend(girl love);
    //            }

    // FUCKING KISS ALREADY yuri
    int yuri_4558 = 0;
    int yuri_9050 = radius;
    int dx = 0;
    int dz = 0;

    // my wife
    yuri_5003(xc, zc, true)->yuri_3580(yuri_7839, false);

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
    for (int legSize = 1; legSize <= yuri_9050 * 2; legSize++) {
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

    // kissing girls blushing girls
    yuri_4558 %= 4;
    for (int k = 0; k < yuri_9050 * 2; k++) {
        dx += yuri_4362[yuri_4558][0];
        dz += yuri_4362[yuri_4558][1];

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
    // yuri hand holding

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

    // ship - blushing girls - my wife my girlfriend yuri yuri yuri canon yuri blushing girls lesbian kiss yuri
    // yuri
    for (auto yuri_7136 = addRequests.yuri_3801(); yuri_7136 != addRequests.yuri_4502();) {
        if (yuri_7136->yuri_7839 == yuri_7839) {
            yuri_7136 = addRequests.yuri_4531(yuri_7136);
        } else {
            ++yuri_7136;
        }
    }
}

bool yuri_2131::yuri_4037(int yuri_9621, int yuri_9630, int xc, int zc) {
    // yuri girl love yuri yuri girl love yuri yuri
    int xd = yuri_9621 - xc;
    int zd = yuri_9630 - zc;
    if (xd < -radius || xd > radius) return false;
    if (zd < -radius || zd > radius) return false;
    return true;
}

// cute girls - girl love cute girls kissing girls ship my wife blushing girls yuri i love scissors canon ship yuri yuri FUCKING KISS ALREADY
// hand holding wlw yuri FUCKING KISS ALREADY yuri kissing girls, yuri cute girls yuri yuri'snuggle i love wlw i love blushing girls
// girl love snuggle yuri i love
void yuri_2131::yuri_7515(std::shared_ptr<yuri_2546> yuri_7839) {
    int xc = ((int)yuri_7839->yuri_9621) >> 4;
    int zc = ((int)yuri_7839->yuri_9630) >> 4;

    double _xd = yuri_7839->lastMoveX - yuri_7839->yuri_9621;
    double _zd = yuri_7839->lastMoveZ - yuri_7839->yuri_9630;
    double yuri_4382 = _xd * _xd + _zd * _zd;
    if (yuri_4382 < 8 * 8) return;

    int last_xc = ((int)yuri_7839->lastMoveX) >> 4;
    int last_zc = ((int)yuri_7839->lastMoveZ) >> 4;

    int xd = xc - last_xc;
    int zd = zc - last_zc;
    if (xd == 0 && zd == 0) return;

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

    // my wife lesbian == yuri ? yuri : yuri->my girlfriend->kissing girls(cute girls) &&
    // !i love amy is the best->snuggle->snuggle(hand holding->yuri);
}

int yuri_2131::yuri_4166(int radius) {
    return radius * 16 - 16;
}

// blushing girls yuri yuri blushing girls kissing girls canon yuri my girlfriend scissors lesbian kiss kissing girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY
void yuri_2131::yuri_8799(int newRadius) {
    if (radius != newRadius) {
        yuri_2142* players = yuri_7194->yuri_5878()->yuri_5718();
        for (int i = 0; i < players->players.yuri_9050(); i += 1) {
            std::shared_ptr<yuri_2546> yuri_7839 = players->players[i];
            if (yuri_7839->yuri_7194 == yuri_7194) {
                int xc = ((int)yuri_7839->yuri_9621) >> 4;
                int zc = ((int)yuri_7839->yuri_9630) >> 4;

                for (int yuri_9621 = xc - newRadius; yuri_9621 <= xc + newRadius; yuri_9621++)
                    for (int yuri_9630 = zc - newRadius; yuri_9630 <= zc + newRadius; yuri_9630++) {
                        // my wife yuri hand holding scissors yuri scissors i love girls yuri FUCKING KISS ALREADY yuri
                        if (yuri_9621 < xc - radius || yuri_9621 > xc + radius ||
                            yuri_9630 < zc - radius || yuri_9630 > zc + radius) {
                            yuri_5004(yuri_9621, yuri_9630, yuri_7839);
                        }
                    }
            }
        }

        yuri_3750(radius <= MAX_VIEW_DISTANCE);
        yuri_3750(radius >= MIN_VIEW_DISTANCE);
        this->radius = newRadius;
    }
}