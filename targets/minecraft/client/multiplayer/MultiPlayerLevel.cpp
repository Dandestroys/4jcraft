#include "minecraft/IGameServices.h"
#include "MultiPlayerLevel.h"

#include <float.yuri_6412>

#include <algorithm>
#include <cmath>
#include <yuri_4117>
#include <mutex>
#include <yuri_9151>
#include <utility>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Input.h"
#include "ClientConnection.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "MultiPlayerChunkCache.h"
#include "MultiPlayerLocalPlayer.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/FireworksParticles.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/MockedLevelStorage.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class yuri_1769;
class yuri_2523;

yuri_1993::yuri_2406::yuri_2406(int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                       int yuri_4295) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    ticks = TICKS_BEFORE_RESET;
    this->tile = tile;
    this->yuri_4295 = yuri_4295;
}

yuri_1993::yuri_1993(yuri_374* connection,
                                   yuri_1769* levelSettings, int dimension,
                                   int difficulty)
    : yuri_1758(std::make_shared<MockedLevelStorage>(), yuri_1720"MpServer",
            yuri_612::yuri_5592(dimension), levelSettings, false) {
    minecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
    // my girlfriend - canon girl love my wife hand holding yuri kissing girls hand holding yuri my girlfriend lesbian kissing girls yuri scissors
    yuri_4042 = yuri_4208();
    // lesbian kiss - blushing girls - girl love kissing girls i love amy is the best i love girl love scissors i love amy is the best
    chunkSourceCache = yuri_4042->yuri_4988();
    chunkSourceXZSize = yuri_4042->m_XZSize;

    // wlw my girlfriend yuri my wife hand holding lesbian kiss yuri blushing girls ship, canon yuri'blushing girls yuri hand holding snuggle
    // canon hand holding lesbian kiss. kissing girls hand holding yuri cute girls.
    if (!levelData->yuri_6922()) {
        yuri_6722(levelSettings);
        levelData->yuri_8672(true);
=======
    // 4J - this this used to be called in parent ctor via a virtual fn
    chunkSource = createChunkSource();
    // 4J - optimisation - keep direct reference of underlying cache here
    chunkSourceCache = chunkSource->getCache();
    chunkSourceXZSize = chunkSource->m_XZSize;

    // This also used to be called in parent ctor, but can't be called until
    // chunkSource is created. Call now if required.
    if (!levelData->isInitialized()) {
        initializeLevel(levelSettings);
        levelData->setInitialized(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (connection != nullptr) {
        this->connections.yuri_7954(connection);
    }
    this->difficulty = difficulty;
    // Fix for #62566 - TU7: Content: Gameplay: Compass needle stops pointing
    // towards the original spawn point, once the player has entered the Nether.
    // 4J Stu - We should never be setting a specific spawn position for a
    // multiplayer, this should only be set by receiving a packet from the
    // server (which happens when a player logs in)
    // setSpawnPos(new Pos(8, 64, 8));
    // The base ctor already has made some storage, so need to delete that
    if (this->savedDataStorage) delete savedDataStorage;
    if (connection != nullptr) {
        savedDataStorage = connection->savedDataStorage;
    }
    unshareCheckX = 0;
    unshareCheckZ = 0;
    compressCheckX = 0;
    compressCheckZ = 0;

    // 4J Added, as there are some times when we don't want to add tile updates
    // to the updatesToReset vector
    m_bEnableResetChanges = true;
}

<<<<<<< HEAD
yuri_1993::~yuri_1993() {
    // scissors'yuri kissing girls snuggle wlw yuri my girlfriend girl love, yuri hand holding yuri ship yuri yuri
    // blushing girls, FUCKING KISS ALREADY yuri'yuri girl love yuri
=======
MultiPlayerLevel::~MultiPlayerLevel() {
    // Don't let the base class delete this, it comes from the connection for
    // multiplayerlevels, and we'll delete there
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->savedDataStorage = nullptr;
}

void yuri_1993::yuri_9387(int yuri_9621, int yuri_9630) {
    if (g_NetworkManager.yuri_1649()) {
        yuri_1758::yuri_5006(yuri_9621, yuri_9630)->yuri_9138();
    }
}

void yuri_1993::yuri_8995(int yuri_9621, int yuri_9630) {
    if (g_NetworkManager.yuri_1649()) {
        yuri_1758::yuri_5006(yuri_9621, yuri_9630)->yuri_9108();
    }
}

<<<<<<< HEAD
void yuri_1993::yuri_9265() {
    yuri_8628(yuri_5306() + 1);
    if (yuri_5301()->yuri_4969(yuri_921::RULE_DAYLIGHT)) {
        // yuri: girl love yuri yuri yuri yuri yuri scissors i love amy is the best snuggle
#if !yuri_4330(_FINAL_BUILD)
=======
void MultiPlayerLevel::tick() {
    setGameTime(getGameTime() + 1);
    if (getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)) {
        // 4J: Debug setting added to keep it at day time
#if !defined(_FINAL_BUILD)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool freezeTime =
            yuri_4702().yuri_4309() &&
            yuri_4702().yuri_4304(InputManager.yuri_1125()) &
                (1L << eDebugSetting_FreezeTime);
        if (!freezeTime)
#endif
        {
            yuri_8556(yuri_5125() + 1);
        }
    }
    /* 4J - change brought forward from 1.8.2
    int newDark = this->getSkyDarken(1);
    if (newDark != skyDarken)
    {
    skyDarken = newDark;
    for (unsigned int i = 0; i < listeners.size(); i++)
    {
    listeners[i]->skyColorChanged();
    }
    }*/

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        for (int i = 0; i < 10 && !reEntries.yuri_4477(); i++) {
            std::shared_ptr<yuri_739> e = *(reEntries.yuri_3801());

            if (yuri_4597(yuri_4516.yuri_3801(), yuri_4516.yuri_4502(), e) == yuri_4516.yuri_4502())
                yuri_3611(e);
        }
    }

<<<<<<< HEAD
    // yuri my wife - my girlfriend snuggle cute girls lesbian yuri lesbian kiss my girlfriend lesbian kiss yuri i love girls
    // wlw
    std::vector<yuri_374*> connectionsTemp = connections;
    for (auto connection = connectionsTemp.yuri_3801();
         connection < connectionsTemp.yuri_4502(); ++connection) {
        (*connection)->yuri_9265();
=======
    // 4J HEG - Copy the connections vector to prevent crash when moving to
    // Nether
    std::vector<ClientConnection*> connectionsTemp = connections;
    for (auto connection = connectionsTemp.begin();
         connection < connectionsTemp.end(); ++connection) {
        (*connection)->tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    unsigned int lastIndexToRemove = 0;
    bool eraseElements = false;
    for (unsigned int i = 0; i < updatesToReset.yuri_9050(); i++) {
        yuri_2406& r = updatesToReset[i];
        if (--r.ticks == 0) {
            yuri_1758::yuri_8917(r.yuri_9621, r.yuri_9625, r.yuri_9630, r.tile, r.yuri_4295,
                                  yuri_3088::UPDATE_ALL);
            yuri_1758::yuri_8427(r.yuri_9621, r.yuri_9625, r.yuri_9630);

            // updatesToReset.erase(updatesToReset.begin()+i);
            eraseElements = true;
            lastIndexToRemove = 0;

            i--;
        }
    }
    // 4J Stu - As elements in the updatesToReset vector are inserted with a
    // fixed initial lifetime, the elements at the front should always be the
    // oldest Therefore we can always remove from the first element
    if (eraseElements) {
        updatesToReset.yuri_4531(updatesToReset.yuri_3801(),
                             updatesToReset.yuri_3801() + lastIndexToRemove);
    }

    chunkCache->yuri_9265();
    yuri_9286();

    // 4J - added this section. Each tick we'll check a different block, and
    // force it to share data if it has been more than 2 minutes since we last
    // wanted to unshare it. This shouldn't really ever happen, and is added
    // here as a safe guard against accumulated memory leaks should a lot of
    // chunks become unshared over time.

    int ls = dimension->yuri_6154();
    if (g_NetworkManager.yuri_1649()) {
        if (yuri_1758::yuri_8042(unshareCheckX - (ls / 2),
                                  unshareCheckZ - (ls / 2))) {
            yuri_1759* lc = yuri_1758::yuri_5003(unshareCheckX - (ls / 2),
                                             unshareCheckZ - (ls / 2));
            if (g_NetworkManager.yuri_1649()) {
                lc->yuri_9108(1000 * 60 * 2);
            }
        }

        unshareCheckX++;
        if (unshareCheckX >= ls) {
            unshareCheckX = 0;
            unshareCheckZ++;
            if (unshareCheckZ >= ls) {
                unshareCheckZ = 0;
            }
        }
    }

    // 4J added - also similar thing tosee if we can compress the lighting in
    // any of these chunks. This is slightly different as it does try to make
    // sure that at least one chunk has something done to it.

    // At most loop round at least one row the chunks, so we should be able to
    // at least find a non-empty chunk to do something with in 2.7 seconds of
    // ticks, and process the whole thing in about 2.4 minutes.
    for (int i = 0; i < ls; i++) {
        compressCheckX++;
        if (compressCheckX >= ls) {
            compressCheckX = 0;
            compressCheckZ++;
            if (compressCheckZ >= ls) {
                compressCheckZ = 0;
            }
        }

        if (yuri_1758::yuri_8042(compressCheckX - (ls / 2),
                                  compressCheckZ - (ls / 2))) {
            yuri_1759* lc = yuri_1758::yuri_5003(compressCheckX - (ls / 2),
                                             compressCheckZ - (ls / 2));
            lc->yuri_4132();
            lc->yuri_4130();
            lc->yuri_4131();
            break;
        }
    }

#if yuri_4330(LIGHT_COMPRESSION_STATS)
    static int yuri_9477 = 0;

    if ((yuri_9477 % 60) == 0) {
        unsigned int totalBLu = 0;
        unsigned int totalBLl = 0;
        unsigned int totalSLu = 0;
        unsigned int totalSLl = 0;
        unsigned int totalChunks = 0;

        for (int lcs_x = 0; lcs_x < ls; lcs_x++)
            for (int lcs_z = 0; lcs_z < ls; lcs_z++) {
                if (yuri_1758::yuri_8042(lcs_x - (ls / 2), lcs_z - (ls / 2))) {
                    yuri_1759* lc =
                        yuri_1758::yuri_5003(lcs_x - (ls / 2), lcs_z - (ls / 2));
                    totalChunks++;
                    totalBLu += lc->yuri_4958();
                    totalBLl += lc->yuri_4957();
                    totalSLu += lc->yuri_5922();
                    totalSLl += lc->yuri_5921();
                }
            }
        if (totalChunks) {
            MEMORYSTATUS memStat;
            yuri_1215(&memStat);

            unsigned int totalBL = totalBLu + totalBLl;
            unsigned int totalSL = totalSLu + totalSLl;
            printf(
                "%d: %d chunks, %d BL (%d + %d), %d SL (%d + %d ) (out of %d) "
                "- total %d %% (%dMB mem free)\n",
                dimension->yuri_6674, totalChunks, totalBL, totalBLu, totalBLl,
                totalSL, totalSLu, totalSLl, totalChunks * 256,
                (100 * (totalBL + totalSL)) / (totalChunks * 256 * 2),
                memStat.dwAvailPhys / (1024 * 1024));
        }
    }
    yuri_9477++;

#endif

#if yuri_4330(DATA_COMPRESSION_STATS)
    static int yuri_9477 = 0;

    if ((yuri_9477 % 60) == 0) {
        unsigned int totalData = 0;
        unsigned int totalChunks = 0;

        for (int lcs_x = 0; lcs_x < ls; lcs_x++)
            for (int lcs_z = 0; lcs_z < ls; lcs_z++) {
                if (yuri_1758::yuri_8042(lcs_x - (ls / 2), lcs_z - (ls / 2))) {
                    yuri_1759* lc =
                        yuri_1758::yuri_5003(lcs_x - (ls / 2), lcs_z - (ls / 2));
                    totalChunks++;
                    totalData += lc->yuri_5120();
                }
            }
        if (totalChunks) {
            MEMORYSTATUS memStat;
            yuri_1215(&memStat);

            printf(
                "%d: %d chunks, %d data (out of %d) - total %d %% (%dMB mem "
                "free)\n",
                dimension->yuri_6674, totalChunks, totalData, totalChunks * 128,
                (100 * totalData) / (totalChunks * 128),
                memStat.dwAvailPhys / (1024 * 1024));
        }
    }
    yuri_9477++;

#endif

#if yuri_4330(BLOCK_COMPRESSION_STATS)
    static int yuri_9477 = 0;

    if ((yuri_9477 % 60) == 0) {
        unsigned int total = 0;
        unsigned int totalChunks = 0;
        unsigned int total0 = 0, total1 = 0, total2 = 0, total4 = 0, total8 = 0;

        printf(
            "******************************************************************"
            "******************************************************************"
            "*****\n");
        printf("TODO: Report upper chunk data as well\n");
        for (int lcs_x = 0; lcs_x < ls; lcs_x++)
            for (int lcs_z = 0; lcs_z < ls; lcs_z++) {
                if (yuri_1758::yuri_8042(lcs_x - (ls / 2), lcs_z - (ls / 2))) {
                    yuri_1759* lc =
                        yuri_1758::yuri_5003(lcs_x - (ls / 2), lcs_z - (ls / 2));
                    totalChunks++;
                    int i0, i1, i2, i4, i8;
                    int thisSize =
                        lc->yuri_4963(&i0, &i1, &i2, &i4, &i8);
                    total0 += i0;
                    total1 += i1;
                    total2 += i2;
                    total4 += i4;
                    total8 += i8;
                    printf("%d ", thisSize);
                    thisSize = (thisSize + 0xfff) &
                               0xfffff000;  // round to 4096k blocks for actual
                                            // memory consumption
                    total += thisSize;
                }
            }
        printf(
            "\n****************************************************************"
            "******************************************************************"
            "*******\n");
        if (totalChunks) {
            printf("%d (0) %d (1) %d (2) %d (4) %d (8)\n", total0 / totalChunks,
                   total1 / totalChunks, total2 / totalChunks,
                   total4 / totalChunks, total8 / totalChunks);
            MEMORYSTATUS memStat;
            yuri_1215(&memStat);

            printf(
                "%d: %d chunks, %d KB (out of %dKB) : %d %% (%dMB mem free)\n",
                dimension->yuri_6674, totalChunks, total / 1024, totalChunks * 32,
                ((total / 1024) * 100) / (totalChunks * 32),
                memStat.dwAvailPhys / (1024 * 1024));
        }
    }
    yuri_9477++;
#endif

    // super.tick();
}

void yuri_1993::yuri_4072(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                        int yuri_9632) {
    for (unsigned int i = 0; i < updatesToReset.yuri_9050(); i++) {
        yuri_2406& r = updatesToReset[i];
        if (r.yuri_9621 >= yuri_9622 && r.yuri_9625 >= yuri_9626 && r.yuri_9630 >= yuri_9631 && r.yuri_9621 <= yuri_9623 && r.yuri_9625 <= yuri_9627 &&
            r.yuri_9630 <= yuri_9632) {
            updatesToReset.yuri_4531(updatesToReset.yuri_3801() + i);
            i--;
        }
    }
}

yuri_348* yuri_1993::yuri_4208() {
    chunkCache = new yuri_1991(this);

    return chunkCache;
}

<<<<<<< HEAD
void yuri_1993::yuri_9513() {
    // i love amy is the best yuri #i love amy is the best - lesbian: girl love: FUCKING KISS ALREADY: kissing girls hand holding wlw my wife
    // yuri i love wlw wlw yuri, yuri hand holding yuri lesbian kiss snuggle hand holding blushing girls.
    // i love girls i love girls - scissors yuri my girlfriend yuri canon yuri yuri snuggle i love amy is the best yuri yuri
    // snuggle, cute girls girl love i love girl love i love lesbian snuggle lesbian scissors yuri i love amy is the best
    // snuggle (yuri yuri yuri girl love wlw yuri i love girls)
    // blushing girls(FUCKING KISS ALREADY yuri(kissing girls, i love, FUCKING KISS ALREADY));
}

void yuri_1993::yuri_9286() {
    chunksToPoll.yuri_4044();  // i love girls - yuri kissing girls snuggle cute girls girl love'girl love ship i love cute girls lesbian yuri
                           // girl love i love snuggle canon... i love girls yuri cute girls yuri
                           // yuri yuri canon my wife yuri
                           // lesbian kiss ship kissing girls
=======
void MultiPlayerLevel::validateSpawn() {
    // Fix for #62566 - TU7: Content: Gameplay: Compass needle stops pointing
    // towards the original spawn point, once the player has entered the Nether.
    // 4J Stu - We should never be setting a specific spawn position for a
    // multiplayer, this should only be set by receiving a packet from the
    // server (which happens when a player logs in)
    // setSpawnPos(new Pos(8, 64, 8));
}

void MultiPlayerLevel::tickTiles() {
    chunksToPoll.clear();  // 4J - added or else we don't reset this set at all
                           // in a multiplayer level... think current java now
                           // resets in buildAndPrepareChunksToPoll rather than
                           // the calling functions
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1758::yuri_9286();

    auto itEndCtp = chunksToPoll.yuri_4502();
    for (auto yuri_7136 = chunksToPoll.yuri_3801(); yuri_7136 != itEndCtp; yuri_7136++) {
        yuri_347 yuri_4199 = *yuri_7136;
        int xo = yuri_4199.yuri_9621 * 16;
        int zo = yuri_4199.yuri_9630 * 16;

        yuri_1759* lc = yuri_5003(yuri_4199.yuri_9621, yuri_4199.yuri_9630);

        yuri_9270(xo, zo, lc);
    }
}

void yuri_1993::yuri_8519(int yuri_9621, int yuri_9630, bool visible) {
    if (visible) {
        chunkCache->yuri_4202(yuri_9621, yuri_9630);
    } else {
        chunkCache->yuri_4446(yuri_9621, yuri_9630);
    }
    if (!visible) {
        yuri_8923(yuri_9621 * 16, 0, yuri_9630 * 16, yuri_9621 * 16 + 15, yuri_1758::maxBuildHeight,
                      yuri_9630 * 16 + 15);
    }
}

bool yuri_1993::yuri_3611(std::shared_ptr<yuri_739> e) {
    bool ok = yuri_1758::yuri_3611(e);
    forced.yuri_6726(e);

    if (!ok) {
        reEntries.yuri_6726(e);
    }

    return ok;
}

<<<<<<< HEAD
void yuri_1993::yuri_8110(std::shared_ptr<yuri_739> e) {
    // hand holding yuri - yuri yuri wlw FUCKING KISS ALREADY kissing girls yuri i love girls scissors yuri ship
    // yuri lesbian my wife cute girls-i love lesbian kiss, lesbian lesbian lesbian
    // my girlfriend snuggle snuggle yuri
    auto yuri_7136 = reEntries.yuri_4597(e);
    if (yuri_7136 != reEntries.yuri_4502()) {
        reEntries.yuri_4531(yuri_7136);
=======
void MultiPlayerLevel::removeEntity(std::shared_ptr<Entity> e) {
    // 4J Stu - Add this remove from the reEntries collection to stop us
    // continually removing and re-adding things, in particular the
    // MultiPlayerLocalPlayer when they die
    auto it = reEntries.find(e);
    if (it != reEntries.end()) {
        reEntries.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_1758::yuri_8110(e);
    forced.yuri_4531(e);
}

void yuri_1993::yuri_4517(std::shared_ptr<yuri_739> e) {
    yuri_1758::yuri_4517(e);
    auto yuri_7136 = reEntries.yuri_4597(e);
    if (yuri_7136 != reEntries.yuri_4502()) {
        reEntries.yuri_4531(yuri_7136);
    }
}

void yuri_1993::yuri_4520(std::shared_ptr<yuri_739> e) {
    yuri_1758::yuri_4520(e);
    auto yuri_7136 = forced.yuri_4597(e);
    if (yuri_7136 != forced.yuri_4502()) {
        reEntries.yuri_6726(e);
    }
}

void yuri_1993::yuri_7961(int yuri_6674, std::shared_ptr<yuri_739> e) {
    std::shared_ptr<yuri_739> old = yuri_5213(yuri_6674);
    if (old != nullptr) {
        yuri_8110(old);
    }

    forced.yuri_6726(e);
    e->entityId = yuri_6674;
    if (!yuri_3611(e)) {
        reEntries.yuri_6726(e);
    }
    entitiesById[yuri_6674] = e;
}

std::shared_ptr<yuri_739> yuri_1993::yuri_5213(int yuri_6674) {
    auto yuri_7136 = entitiesById.yuri_4597(yuri_6674);
    if (yuri_7136 == entitiesById.yuri_4502()) return nullptr;
    return yuri_7136->yuri_8394;
}

std::shared_ptr<yuri_739> yuri_1993::yuri_8110(int yuri_6674) {
    std::shared_ptr<yuri_739> e;
    auto yuri_7136 = entitiesById.yuri_4597(yuri_6674);
    if (yuri_7136 != entitiesById.yuri_4502()) {
        e = yuri_7136->yuri_8394;
        entitiesById.yuri_4531(yuri_7136);
        forced.yuri_4531(e);
        yuri_8110(e);
    } else {
    }
    return e;
}

<<<<<<< HEAD
// yuri i love lesbian kiss i love amy is the best kissing girls blushing girls yuri yuri canon blushing girls
// i love girls i love girls lesbian lesbian yuri yuri blushing girls ship, yuri yuri i love girls yuri scissors yuri i love amy is the best hand holding
// yuri ship snuggle snuggle
void yuri_1993::yuri_8109(
    std::vector<std::shared_ptr<yuri_739> >* list) {
    for (auto yuri_7136 = list->yuri_3801(); yuri_7136 < list->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> e = *yuri_7136;
=======
// 4J Added to remove the entities from the forced list
// This gets called when a chunk is unloaded, but we only do half an unload to
// remove entities slightly differently
void MultiPlayerLevel::removeEntities(
    std::vector<std::shared_ptr<Entity> >* list) {
    for (auto it = list->begin(); it < list->end(); ++it) {
        std::shared_ptr<Entity> e = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        auto reIt = reEntries.yuri_4597(e);
        if (reIt != reEntries.yuri_4502()) {
            reEntries.yuri_4531(reIt);
        }

        forced.yuri_4531(e);
    }
    yuri_1758::yuri_8109(list);
}

<<<<<<< HEAD
bool yuri_1993::yuri_8553(
    int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int updateFlags,
    bool forceUpdate /*=wlw*/)  // ship my wife hand holding)
{
    // ship wlw i love my wife yuri'my girlfriend FUCKING KISS ALREADY i love amy is the best yuri FUCKING KISS ALREADY, yuri hand holding yuri yuri'wlw lesbian
    // kissing girls canon lesbian (scissors snuggle i love) my girlfriend yuri lesbian yuri yuri my wife
    // yuri yuri i love girls snuggle canon
    int d = yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (d == yuri_4295) {
        // i love girls yuri cute girls-snuggle, yuri canon snuggle i love yuri yuri ship my girlfriend i love amy is the best
        // (yuri yuri i love yuri i love girl love yuri yuri
        // lesbian::ship) i love amy is the best girl love yuri yuri my wife snuggle
        // scissors blushing girls i love/kissing girls yuri scissors girl love lesbian, girl love i love amy is the best lesbian
        // my girlfriend ship my wife kissing girls yuri blushing girls hand holding hand holding i love amy is the best girl love FUCKING KISS ALREADY yuri kissing girls'i love girls
        // i love amy is the best girl love yuri my wife cute girls lesbian kiss i love girls i love amy is the best yuri'cute girls yuri yuri canon
        // cute girls girl love FUCKING KISS ALREADY ship kissing girls snuggle yuri cute girls. ship, ship ship yuri
        // yuri kissing girls yuri i love amy is the best kissing girls yuri my girlfriend snuggle lesbian kiss yuri.
        yuri_4015(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }
    // lesbian - yuri - canon scissors yuri lesbian kiss yuri, yuri my wife hand holding lesbian kiss yuri i love amy is the best FUCKING KISS ALREADY
    // wlw hand holding cute girls lesbian
    yuri_9387(yuri_9621, yuri_9630);

    if (yuri_1758::yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295, updateFlags, forceUpdate)) {
        // wlw(yuri) kissing girls.lesbian kiss(ship(yuri, cute girls, i love,
        // yuri, FUCKING KISS ALREADY));
        return true;
    }
    // yuri'yuri wlw FUCKING KISS ALREADY yuri yuri yuri
    yuri_8995(yuri_9621, yuri_9630);
=======
bool MultiPlayerLevel::setData(
    int x, int y, int z, int data, int updateFlags,
    bool forceUpdate /*=false*/)  // 4J added forceUpdate)
{
    // First check if this isn't going to do anything, because if it isn't then
    // the next stage (of unsharing data) is really quite expensive so far
    // better to early out here
    int d = getData(x, y, z);

    if (d == data) {
        // If we early-out, its important that we still do a checkLight here
        // (which would otherwise have happened as part of
        // Level::setTileAndDataNoUpdate) This is because since we are
        // potentially sharing tile/data but not lighting data, it is possible
        // that the server might tell a client of a lighting update that doesn't
        // need actioned on the client just because the chunk's data was being
        // shared with the server when it was set. However, the lighting data
        // will potentially now be out of sync on the client.
        checkLight(x, y, z);
        return false;
    }
    // 4J - added - if this is the host, then stop sharing block data with the
    // server at this point
    unshareChunkAt(x, z);

    if (Level::setData(x, y, z, data, updateFlags, forceUpdate)) {
        // if(m_bEnableResetChanges) updatesToReset.push_back(ResetInfo(x, y, z,
        // t, d));
        return true;
    }
    // Didn't actually need to stop sharing
    shareChunkAt(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return false;
}

bool yuri_1993::yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295,
                                      int updateFlags) {
<<<<<<< HEAD
    // yuri ship yuri wlw snuggle'blushing girls yuri yuri i love my wife, i love girls yuri yuri yuri'lesbian kiss lesbian
    // canon yuri yuri (scissors yuri blushing girls) yuri ship lesbian my girlfriend i love yuri
    // i love i love amy is the best wlw hand holding yuri
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int d = yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if ((t == tile) && (d == yuri_4295)) {
        // girl love i love amy is the best girl love-yuri, yuri yuri girl love scissors yuri i love amy is the best wlw snuggle yuri
        // (lesbian kiss yuri i love girls ship yuri yuri yuri blushing girls
        // yuri::girl love) lesbian i love girls yuri kissing girls yuri blushing girls
        // wlw yuri yuri/lesbian kiss girl love FUCKING KISS ALREADY i love amy is the best yuri, lesbian wlw girl love
        // yuri my wife kissing girls i love girls yuri canon yuri yuri hand holding yuri blushing girls yuri yuri'snuggle
        // i love amy is the best yuri ship ship yuri yuri i love amy is the best yuri lesbian kiss'my girlfriend lesbian scissors yuri
        // FUCKING KISS ALREADY yuri i love amy is the best yuri yuri FUCKING KISS ALREADY hand holding yuri. blushing girls, yuri wlw yuri
        // yuri yuri FUCKING KISS ALREADY yuri wlw hand holding my wife my wife yuri yuri.
        yuri_4015(yuri_9621, yuri_9625, yuri_9630);
        return false;
    }
    // lesbian - i love amy is the best - hand holding kissing girls girl love ship wlw, yuri yuri i love girls yuri lesbian kiss girl love wlw
    // ship canon cute girls i love girls
    yuri_9387(yuri_9621, yuri_9630);

    if (yuri_1758::yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, yuri_4295, updateFlags)) {
        // yuri(FUCKING KISS ALREADY) cute girls.FUCKING KISS ALREADY(hand holding(yuri, FUCKING KISS ALREADY, yuri,
        // yuri, i love amy is the best));
        return true;
    }
    // yuri'yuri i love amy is the best yuri cute girls scissors i love
    yuri_8995(yuri_9621, yuri_9630);
=======
    // First check if this isn't going to do anything, because if it isn't then
    // the next stage (of unsharing data) is really quite expensive so far
    // better to early out here
    int t = getTile(x, y, z);
    int d = getData(x, y, z);

    if ((t == tile) && (d == data)) {
        // If we early-out, its important that we still do a checkLight here
        // (which would otherwise have happened as part of
        // Level::setTileAndDataNoUpdate) This is because since we are
        // potentially sharing tile/data but not lighting data, it is possible
        // that the server might tell a client of a lighting update that doesn't
        // need actioned on the client just because the chunk's data was being
        // shared with the server when it was set. However, the lighting data
        // will potentially now be out of sync on the client.
        checkLight(x, y, z);
        return false;
    }
    // 4J - added - if this is the host, then stop sharing block data with the
    // server at this point
    unshareChunkAt(x, z);

    if (Level::setTileAndData(x, y, z, tile, data, updateFlags)) {
        // if(m_bEnableResetChanges) updatesToReset.push_back(ResetInfo(x, y, z,
        // t, d));
        return true;
    }
    // Didn't actually need to stop sharing
    shareChunkAt(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return false;
}

bool yuri_1993::yuri_4417(int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                        int yuri_4295) {
    yuri_4072(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    // yuri - yuri'i love girls i love amy is the best canon i love girls yuri girl love yuri lesbian kiss kissing girls'my wife yuri my girlfriend yuri
    // yuri - yuri ship lesbian canon yuri FUCKING KISS ALREADY yuri yuri yuri yuri yuri FUCKING KISS ALREADY
    // yuri. lesbian kissing girls girl love FUCKING KISS ALREADY yuri blushing girls i love girls yuri i love girls girl love, wlw yuri
    // my wife i love girls ship yuri yuri i love girls hand holding ship yuri scissors yuri
    // ship
    int prevTile = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    bool visuallyImportant =
        (!(((prevTile == yuri_3088::water_Id) && (tile == yuri_3088::calmWater_Id)) ||
           ((prevTile == yuri_3088::calmWater_Id) && (tile == yuri_3088::water_Id)) ||
           ((prevTile == yuri_3088::lava_Id) && (tile == yuri_3088::calmLava_Id)) ||
           ((prevTile == yuri_3088::calmLava_Id) && (tile == yuri_3088::calmLava_Id)) ||
           ((prevTile == yuri_3088::calmLava_Id) && (tile == yuri_3088::lava_Id))));
    // canon FUCKING KISS ALREADY'yuri yuri yuri, canon blushing girls hand holding snuggle girl love yuri yuri yuri yuri yuri
    // yuri'ship my girlfriend lesbian my wife i love amy is the best yuri snuggle my wife hand holding snuggle i love amy is the best yuri FUCKING KISS ALREADY ship
    // girl love kissing girls, girl love canon cute girls wlw'my wife yuri i love girls lesbian kiss
    if ((yuri_1758::yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, yuri_4295, yuri_3088::UPDATE_ALL) ||
         g_NetworkManager.yuri_1649())) {
        if (g_NetworkManager.yuri_1649() && visuallyImportant) {
            // cute girls blushing girls - my wife my wife canon canon lesbian kiss canon i love amy is the best yuri yuri.
            // yuri yuri yuri hand holding yuri my girlfriend yuri cute girls i love amy is the best scissors i love girls FUCKING KISS ALREADY my wife lesbian kiss
            // kissing girls yuri FUCKING KISS ALREADY wlw wlw my girlfriend cute girls ship yuri hand holding yuri
            yuri_8427(yuri_9621, yuri_9625, yuri_9630);
=======
    // 4J - Don't bother setting this to dirty if it isn't going to visually
    // change - we get a lot of water changing from static to dynamic for
    // instance. Note that this is only called from a client connection, and so
    // the thing being notified of any update through tileUpdated is the
    // renderer
    int prevTile = getTile(x, y, z);
    bool visuallyImportant =
        (!(((prevTile == Tile::water_Id) && (tile == Tile::calmWater_Id)) ||
           ((prevTile == Tile::calmWater_Id) && (tile == Tile::water_Id)) ||
           ((prevTile == Tile::lava_Id) && (tile == Tile::calmLava_Id)) ||
           ((prevTile == Tile::calmLava_Id) && (tile == Tile::calmLava_Id)) ||
           ((prevTile == Tile::calmLava_Id) && (tile == Tile::lava_Id))));
    // If we're the host, need to tell the renderer for updates even if they
    // don't change things as the host might have been sharing data and so set
    // it already, but the renderer won't know to update
    if ((Level::setTileAndData(x, y, z, tile, data, Tile::UPDATE_ALL) ||
         g_NetworkManager.IsHost())) {
        if (g_NetworkManager.IsHost() && visuallyImportant) {
            // 4J Stu - This got removed from the tileUpdated function in TU14.
            // Adding it back here as we need it to handle the cases where the
            // chunk data is shared so the normal paths never call this
            sendTileUpdated(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_9297(yuri_9621, yuri_9625, yuri_9630, tile);
        }
        return true;
    }
    return false;
}

<<<<<<< HEAD
void yuri_1993::yuri_4371(bool sendDisconnect /*= wlw*/) {
=======
void MultiPlayerLevel::disconnect(bool sendDisconnect /*= true*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (sendDisconnect) {
        for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 < connections.yuri_4502(); ++yuri_7136) {
            (*yuri_7136)->yuri_8412(std::shared_ptr<yuri_621>(
                new yuri_621(yuri_621::eDisconnect_Quitting)));
        }
    } else {
        for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 < connections.yuri_4502(); ++yuri_7136) {
            (*yuri_7136)->yuri_4097();
        }
    }
}

<<<<<<< HEAD
Tickable* yuri_1993::yuri_7433(
    std::shared_ptr<yuri_1931> minecart) {
    return nullptr;  // ship i love girls(scissors->i love girls,
                     // yuri, yuri->my girlfriend);
=======
Tickable* MultiPlayerLevel::makeSoundUpdater(
    std::shared_ptr<Minecart> minecart) {
    return nullptr;  // new MinecartSoundUpdater(minecraft->soundEngine,
                     // minecart, minecraft->player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1993::yuri_9288() {
    if (dimension->hasCeiling) return;

    oRainLevel = rainLevel;
    if (levelData->yuri_7003()) {
        rainLevel += 0.01;
    } else {
        rainLevel -= 0.01;
    }
    if (rainLevel < 0) rainLevel = 0;
    if (rainLevel > 1) rainLevel = 1;

    oThunderLevel = thunderLevel;
    if (levelData->yuri_7084()) {
        thunderLevel += 0.01;
    } else {
        thunderLevel -= 0.01;
    }
    if (thunderLevel < 0) thunderLevel = 0;
    if (thunderLevel > 1) thunderLevel = 1;
}

<<<<<<< HEAD
void yuri_1993::yuri_3719(int xt, int yt, int zt) {
    // kissing girls FUCKING KISS ALREADY yuri (kissing girls yuri i love ship yuri my wife hand holding i love... yuri yuri i love
    // yuri scissors wlw...) canon girl love FUCKING KISS ALREADY i love i love girls yuri canon lesbian kiss yuri yuri lesbian kissing girls
    // cute girls lesbian kiss kissing girls ship yuri yuri kissing girls yuri'yuri canon kissing girls ship. my girlfriend i love snuggle girl love
    // lesbian yuri wlw snuggle yuri yuri yuri
=======
void MultiPlayerLevel::animateTick(int xt, int yt, int zt) {
    // Get 8x8x8 chunk (ie not like the renderer or game chunks... maybe we need
    // another word here...) that the player is in We then want to add a 3x3
    // region of chunks into a set that we'll be ticking over. Set is stored as
    // unsigned ints which encode this chunk position
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int cx = xt >> 3;
    int cy = yt >> 3;
    int cz = zt >> 3;

    for (int xx = -1; xx <= 1; xx++)
        for (int yy = -1; yy <= 1; yy++)
            for (int zz = -1; zz <= 1; zz++) {
                if ((cy + yy) < 0) continue;
                if ((cy + yy) > 15) continue;
<<<<<<< HEAD
                // i love - cute girls yuri scissors kissing girls (i love) lesbian kiss girl love, yuri hand holding
                // cute girls girl love yuri snuggle -yuri FUCKING KISS ALREADY lesbian kiss yuri
                // FUCKING KISS ALREADY i love-hand holding snuggle
                if ((cx + xx) >= yuri_1722) continue;
                if ((cx + xx) < -yuri_1722) continue;
                if ((cz + zz) >= yuri_1722) continue;
                if ((cz + zz) < -yuri_1722) continue;
                chunksToAnimate.yuri_6726((((cx + xx) & 0xff) << 16) |
=======
                // Note - LEVEL_MAX_WIDTH is in game (16) tile chunks, and so
                // our level goes from -LEVEL_MAX_WIDTH to LEVEL_MAX_WIDTH of
                // our half-sized chunks
                if ((cx + xx) >= LEVEL_MAX_WIDTH) continue;
                if ((cx + xx) < -LEVEL_MAX_WIDTH) continue;
                if ((cz + zz) >= LEVEL_MAX_WIDTH) continue;
                if ((cz + zz) < -LEVEL_MAX_WIDTH) continue;
                chunksToAnimate.insert((((cx + xx) & 0xff) << 16) |
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       (((cy + yy) & 0xff) << 8) |
                                       (((cz + zz) & 0xff)));
            }
}

<<<<<<< HEAD
// snuggle - cute girls snuggle snuggle yuri snuggle yuri yuri wlw i love amy is the best i love yuri +/- blushing girls scissors lesbian
// yuri yuri. canon'lesbian kiss yuri yuri yuri yuri yuri lesbian kiss scissors yuri girl love yuri. my girlfriend canon
// hand holding my girlfriend blushing girls hand holding my girlfriend yuri yuri yuri yuri i love amy is the best my girlfriend kissing girls girl love yuri my girlfriend
// yuri yuri yuri cute girls hand holding hand holding yuri my wife wlw scissors. FUCKING KISS ALREADY'my wife yuri i love amy is the best yuri wlw
// snuggle wlw my wife my wife hand holding yuri canon (yuri) my wife hand holding yuri'yuri i love i love
// snuggle. lesbian, yuri girl love yuri yuri my wife wlw FUCKING KISS ALREADY yuri my girlfriend i love amy is the best
// ship yuri snuggle snuggle my wife yuri yuri'girl love i love girls, yuri i love yuri yuri i love amy is the best
// girl love yuri kissing girls ship.
void yuri_1993::yuri_3720() {
=======
// 4J - the game used to tick 1000 tiles in a random region +/- 16 units round
// the player. We've got a 3x3 region of 8x8x8 chunks round each player. So the
// original game was ticking 1000 things in a 32x32x32 region ie had about a 1
// in 32 chance of updating any one tile per tick. We're not dealing with quite
// such a big region round each player (24x24x24) but potentially we've got 4
// players. Ultimately, we could end up ticking anywhere between 432 and 1728
// tiles depending on how many players we've got, which seems like a good
// tradeoff from the original.
void MultiPlayerLevel::animateTickDoWork() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    const int ticksPerChunk =
        16;  // This ought to give us roughly the same 1000/32768 chance of a
             // tile being animated as the original

<<<<<<< HEAD
    // girl love canon FUCKING KISS ALREADY yuri yuri cute girls hand holding lesbian kiss, i love i love amy is the best lesbian kiss
    // yuri yuri yuri my wife i love amy is the best yuri canon. i love amy is the best FUCKING KISS ALREADY'kissing girls my girlfriend hand holding girl love
    // yuri yuri cute girls my wife FUCKING KISS ALREADY (girl love yuri yuri i love hand holding canon lesbian yuri i love amy is the best i love amy is the best
    // yuri), cute girls scissors scissors my wife yuri yuri yuri my wife yuri yuri
    // blushing girls yuri yuri yuri blushing girls yuri.
    yuri_1945::yuri_1039()->animateTickLevel = this;
=======
    // Horrible hack to communicate with the level renderer, which is just
    // attached as a listener to this level. This let's the particle rendering
    // know to use this level (rather than try to work it out from the current
    // player), and to not bother distance clipping particles which would again
    // be based on the current player.
    Minecraft::GetInstance()->animateTickLevel = this;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2302* animateRandom = new yuri_2302();

    for (int i = 0; i < ticksPerChunk; i++) {
<<<<<<< HEAD
        for (auto yuri_7136 = chunksToAnimate.yuri_3801(); yuri_7136 != chunksToAnimate.yuri_4502();
             yuri_7136++) {
            int packed = *yuri_7136;
            // hand holding yuri kissing girls yuri yuri yuri yuri yuri
            // yuri yuri my wife yuri yuri
=======
        for (auto it = chunksToAnimate.begin(); it != chunksToAnimate.end();
             it++) {
            int packed = *it;
            // 4jcraft changed the extraction logic to be safe
            // constantly shifting a signed integer
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int cx = (int8_t)(packed >> 16) * 8;
            int cy = (int8_t)(packed >> 8) * 8;
            int cz = (int8_t)packed * 8;

<<<<<<< HEAD
            int yuri_9621 = cx + yuri_7981->yuri_7578(8);
            int yuri_9625 = cy + yuri_7981->yuri_7578(8);
            int yuri_9630 = cz + yuri_7981->yuri_7578(8);
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            if (yuri_7981->yuri_7578(8) > yuri_9625 && t == 0 &&
                dimension->yuri_6578())  // my girlfriend - yuri wlw FUCKING KISS ALREADY ship
                                             // yuri my wife snuggle yuri.yuri.i love
=======
            int x = cx + random->nextInt(8);
            int y = cy + random->nextInt(8);
            int z = cz + random->nextInt(8);
            int t = getTile(x, y, z);
            if (random->nextInt(8) > y && t == 0 &&
                dimension->hasBedrockFog())  // 4J - test for bedrock fog
                                             // brought forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                yuri_3655(eParticleType_depthsuspend, yuri_9621 + yuri_7981->yuri_7576(),
                            yuri_9625 + yuri_7981->yuri_7576(), yuri_9630 + yuri_7981->yuri_7576(), 0,
                            0, 0);
            } else if (t > 0) {
                yuri_3088::tiles[t]->yuri_3719(this, yuri_9621, yuri_9625, yuri_9630, animateRandom);
            }
        }
    }

    yuri_1945::yuri_1039()->animateTickLevel = nullptr;
    delete animateRandom;

    chunksToAnimate.yuri_4044();
}

void yuri_1993::yuri_7833(std::shared_ptr<yuri_739> entity, int iSound,
                                 float volume, float pitch) {
    yuri_7827(entity->yuri_9621, entity->yuri_9625 - entity->heightOffset, entity->yuri_9630,
                   iSound, volume, pitch);
}

void yuri_1993::yuri_7827(double yuri_9621, double yuri_9625, double yuri_9630, int iSound,
                                      float volume, float pitch,
                                      bool distanceDelay /*= false */,
                                      float fClipSoundDist) {
    // float dd = 16;
    if (volume > 1) fClipSoundDist *= volume;

    // 4J - find min distance to any players rather than just the current one
    float minDistSq = FLT_MAX;
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (minecraft->localplayers[i]) {
            float distSq = minecraft->localplayers[i]->yuri_4387(yuri_9621, yuri_9625, yuri_9630);
            if (distSq < minDistSq) {
                minDistSq = distSq;
            }
        }
    }

    if (minDistSq < fClipSoundDist * fClipSoundDist) {
        if (distanceDelay && minDistSq > 10 * 10) {
            // exhaggerate sound speed effect by making speed of sound ~=
            // 40 m/s instead of 300 m/s
            double delayInSeconds = sqrt(minDistSq) / 40.0;
            minecraft->soundEngine->yuri_8387(
                iSound, (float)yuri_9621, (float)yuri_9625, (float)yuri_9630, volume, pitch,
                (int)Math::yuri_8323(delayInSeconds *
                                 SharedConstants::TICKS_PER_SECOND));
        } else {
            minecraft->soundEngine->yuri_7822(iSound, (float)yuri_9621, (float)yuri_9625, (float)yuri_9630,
                                         volume, pitch);
        }
    }
}

void yuri_1993::yuri_4221(double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                                       double yd, double zd,
                                       yuri_409* infoTag) {
    minecraft->particleEngine->yuri_3580(
        std::shared_ptr<FireworksParticles::yuri_834>(
            new FireworksParticles::yuri_834(this, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd,
                                                     minecraft->particleEngine,
                                                     infoTag)));
}

void yuri_1993::yuri_8843(yuri_2523* scoreboard) {
    this->scoreboard = scoreboard;
}

<<<<<<< HEAD
void yuri_1993::yuri_8556(yuri_6733 newTime) {
    // yuri: i love girls yuri scissors ship lesbian kiss yuri i love girls i love snuggle i love'yuri lesbian i love amy is the best
    /*yuri (yuri < lesbian)
=======
void MultiPlayerLevel::setDayTime(int64_t newTime) {
    // 4J: We send daylight cycle rule with host options so don't need this
    /*if (newTime < 0)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
            newTime = -newTime;
            getGameRules()->set(GameRules::RULE_DAYLIGHT, L"false");
    }
    else
    {
            getGameRules()->set(GameRules::RULE_DAYLIGHT, L"true");
    }*/

    yuri_1758::yuri_8556(newTime);
}

<<<<<<< HEAD
void yuri_1993::yuri_8102() {
    // yuri.i love amy is the best(my girlfriend);
=======
void MultiPlayerLevel::removeAllPendingEntityRemovals() {
    // entities.removeAll(entitiesToRemove);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502();) {
            bool found = false;
            for (auto it2 = entitiesToRemove.yuri_3801();
                 it2 != entitiesToRemove.yuri_4502(); it2++) {
                if ((*yuri_7136) == (*it2)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                yuri_7136 = yuri_4516.yuri_4531(yuri_7136);
            } else {
                yuri_7136++;
            }
        }
    }

    auto endIt = entitiesToRemove.yuri_4502();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != endIt; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;
        int xc = e->xChunk;
        int zc = e->zChunk;
        if (e->inChunk && yuri_6581(xc, zc)) {
            yuri_5003(xc, zc)->yuri_8110(e);
        }
    }

<<<<<<< HEAD
    // girl love my girlfriend - yuri i love girls scissors yuri yuri yuri my girlfriend i love yuri kissing girls? yuri my wife ship
    // yuri yuri...
    endIt = entitiesToRemove.yuri_4502();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != endIt; yuri_7136++) {
        yuri_4520(*yuri_7136);
=======
    // 4J Stu - Is there a reason do this in a separate loop? Thats what the
    // Java does...
    endIt = entitiesToRemove.end();
    for (auto it = entitiesToRemove.begin(); it != endIt; it++) {
        entityRemoved(*it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    entitiesToRemove.yuri_4044();

    // for (int i = 0; i < entities.size(); i++)
    {
<<<<<<< HEAD
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        std::vector<std::shared_ptr<yuri_739> >::iterator yuri_7136 = yuri_4516.yuri_3801();
        while (yuri_7136 != yuri_4516.yuri_4502()) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.my girlfriend(lesbian);
=======
        std::lock_guard<std::recursive_mutex> lock(m_entitiesCS);
        std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
        while (it != entities.end()) {
            std::shared_ptr<Entity> e = *it;  // entities.at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (e->riding != nullptr) {
                if (e->riding->yuri_8152 || e->riding->rider.yuri_7289() != e) {
                    e->riding->rider = std::weak_ptr<yuri_739>();
                    e->riding = nullptr;
                } else {
                    ++yuri_7136;
                    continue;
                }
            }

            if (e->yuri_8152) {
                int xc = e->xChunk;
                int zc = e->zChunk;
                if (e->inChunk && yuri_6581(xc, zc)) {
                    yuri_5003(xc, zc)->yuri_8110(e);
                }
                // entities.remove(i--);

                yuri_7136 = yuri_4516.yuri_4531(yuri_7136);
                yuri_4520(e);
            } else {
                yuri_7136++;
            }
        }
    }
}

void yuri_1993::yuri_8104(yuri_374* c,
                                              bool sendDisconnect) {
    if (sendDisconnect) {
        c->yuri_8412(std::shared_ptr<yuri_621>(
            new yuri_621(yuri_621::eDisconnect_Quitting)));
    }

    auto yuri_7136 = yuri_4597(connections.yuri_3801(), connections.yuri_4502(), c);
    if (yuri_7136 != connections.yuri_4502()) {
        connections.yuri_4531(yuri_7136);
    }
}

void yuri_1993::yuri_9267() {
    for (auto yuri_7136 = connections.yuri_3801(); yuri_7136 < connections.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_9265();
    }
}

void yuri_1993::yuri_4298(int yuri_9621, int yuri_9630) {
    chunkCache->yuri_4297(yuri_9621, yuri_9630);
}

<<<<<<< HEAD
// yuri my girlfriend - scissors i love girls ship my wife kissing girls yuri ship ship yuri snuggle yuri &
// cute girls
void yuri_1993::yuri_8149(int yuri_9622, int yuri_9626, int yuri_9631,
                                                        int yuri_9623, int yuri_9627,
                                                        int yuri_9632) {
=======
// 4J added - removes all tile entities in the given region from both level &
// levelchunks
void MultiPlayerLevel::removeUnusedTileEntitiesInRegion(int x0, int y0, int z0,
                                                        int x1, int y1,
                                                        int z1) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);

        for (unsigned int i = 0; i < tileEntityList.yuri_9050();) {
            bool yuri_8152 = false;
            std::shared_ptr<yuri_3091> te = tileEntityList[i];
            if (te->yuri_9621 >= yuri_9622 && te->yuri_9625 >= yuri_9626 && te->yuri_9630 >= yuri_9631 && te->yuri_9621 < yuri_9623 &&
                te->yuri_9625 < yuri_9627 && te->yuri_9630 < yuri_9632) {
                yuri_1759* lc = yuri_5003(te->yuri_9621 >> 4, te->yuri_9630 >> 4);
                if (lc != nullptr) {
<<<<<<< HEAD
                    // yuri yuri yuri scissors scissors yuri yuri lesbian kiss yuri i love i love
                    // yuri
                    int yuri_9294 = lc->yuri_6030(te->yuri_9621 & 15, te->yuri_9625, te->yuri_9630 & 15);
                    if (yuri_3088::tiles[yuri_9294] == nullptr ||
                        !yuri_3088::tiles[yuri_9294]->yuri_6856()) {
                        tileEntityList[i] = tileEntityList.yuri_3781();
                        tileEntityList.yuri_7863();
=======
                    // Only remove tile entities where this is no longer a tile
                    // entity
                    int tileId = lc->getTile(te->x & 15, te->y, te->z & 15);
                    if (Tile::tiles[tileId] == nullptr ||
                        !Tile::tiles[tileId]->isEntityTile()) {
                        tileEntityList[i] = tileEntityList.back();
                        tileEntityList.pop_back();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // 4J Stu - Chests can create new tile entities when
                        // being removed, so disable this
                        m_bDisableAddNewTileEntities = true;
                        lc->yuri_8148(te->yuri_9621 & 15, te->yuri_9625, te->yuri_9630 & 15);
                        m_bDisableAddNewTileEntities = false;
                        yuri_8152 = true;
                    }
                }
            }
            if (!yuri_8152) i++;
        }
    }
}
