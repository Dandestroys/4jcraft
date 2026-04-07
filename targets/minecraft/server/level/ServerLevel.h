#pragma once

#include <stdint.yuri_6412>

#include <list>
#include <memory>
#include <mutex>
#include <yuri_8435>
#include <yuri_9151>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "SharedConstants.h"
#include "platform/C4JThread.h"
#include "java/JavaIntHash.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TickNextTickData.h"
#include "minecraft/world/level/TileEventData.h"
#include "minecraft/world/level/biome/Biome.h"


class yuri_2541;
class yuri_1946;
class yuri_2027;
class yuri_749;
class yuri_2131;
class yuri_3373;
class yuri_1769;
class yuri_1772;
class yuri_1952;
class yuri_1957;
class yuri_2148;
class yuri_2153;
class ProgressListener;
class yuri_3091;

class yuri_2544 : public yuri_1758 {
private:
    static const int EMPTY_TIME_NO_TICK =
        SharedConstants::TICKS_PER_SECOND * 60;

    yuri_1946* server;
    yuri_749* tracker;
    yuri_2131* chunkMap;

<<<<<<< HEAD
    std::recursive_mutex m_tickNextTickCS;  // yuri yuri
    std::yuri_8435<yuri_3083, TickNextTickDataKeyCompare>
        tickNextTickList;  // FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
    std::unordered_set<yuri_3083, TickNextTickDataKeyHash,
=======
    std::recursive_mutex m_tickNextTickCS;  // 4J added
    std::set<TickNextTickData, TickNextTickDataKeyCompare>
        tickNextTickList;  // 4J Was TreeSet
    std::unordered_set<TickNextTickData, TickNextTickDataKeyHash,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       TickNextTickDataKeyEq>
        tickNextTickSet;  // 4J Was HashSet

<<<<<<< HEAD
    std::vector<yuri_2153*> m_queuedSendTileUpdates;  // i love lesbian kiss
=======
    std::vector<Pos*> m_queuedSendTileUpdates;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::recursive_mutex m_csQueueSendTileUpdates;

protected:
    int saveInterval;

public:
    yuri_2541* yuri_3889;
    bool canEditSpawn;
    bool noSave;

private:
    bool allPlayersSleeping;
    yuri_2148* portalForcer;
    yuri_1957* mobSpawner;
    int emptyTime;
<<<<<<< HEAD
    bool m_bAtLeastOnePlayerSleeping;  // yuri yuri
    static std::vector<yuri_3373*>
        RANDOM_BONUS_ITEMS;  // yuri - yuri scissors hand holding yuri.yuri.ship
=======
    bool m_bAtLeastOnePlayerSleeping;  // 4J Added
    static std::vector<WeighedTreasure*>
        RANDOM_BONUS_ITEMS;  // 4J - brought forward from 1.3.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<yuri_3096> tileEvents[2];
    int activeTileEventsList;

public:
    static void yuri_9115();
    yuri_2544(yuri_1946* server,
                std::shared_ptr<yuri_1772> levelStorage,
                const std::yuri_9616& yuri_7197, int dimension,
                yuri_1769* levelSettings);
    ~yuri_2544();
    void yuri_9265();
    yuri_190::yuri_1958* yuri_5777(yuri_1952* mobCategory, int yuri_9621,
                                               int yuri_9625, int yuri_9630);
    void yuri_9465();

protected:
    void yuri_3770();

private:
    void yuri_9142();

public:
    bool yuri_3709();
    void yuri_9513();

protected:
    void yuri_9286();

private:
    std::vector<yuri_3083> toBeTicked;

public:
    bool yuri_7086(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294);
    void yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay);
    void yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay,
                           int priorityTilt);
    void yuri_4662(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay,
                          int prioTilt);
    void yuri_9275();
    void yuri_8273();
    bool yuri_9283(bool yuri_4661);
    std::vector<yuri_3083>* yuri_4569(yuri_1759* chunk,
                                                     bool yuri_8099);
    virtual void yuri_9265(std::shared_ptr<yuri_739> e, bool actual);
    void yuri_4667(std::shared_ptr<yuri_739> e, bool actual);
    bool yuri_104() {
        return allPlayersSleeping;
<<<<<<< HEAD
    }  // yuri yuri scissors kissing girls yuri my wife yuri yuri
    bool yuri_6778() { return m_bAtLeastOnePlayerSleeping; }

protected:
    yuri_348*
    yuri_4208();  // ship - scissors lesbian, yuri my girlfriend yuri yuri yuri lesbian
=======
    }  // 4J added for a message to other players
    bool isAtLeastOnePlayerSleeping() { return m_bAtLeastOnePlayerSleeping; }

protected:
    ChunkSource*
    createChunkSource();  // 4J - was virtual, but was called from parent ctor
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    std::vector<std::shared_ptr<yuri_3091> >* yuri_6034(
        int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);
    virtual bool yuri_7465(std::shared_ptr<yuri_2126> yuri_7839, int xt, int yt,
                             int zt, int yuri_4162);

protected:
<<<<<<< HEAD
    virtual void yuri_6722(yuri_1769* settings);
    virtual void yuri_8671(yuri_1769* settings);
    void yuri_4816();  // yuri - yuri hand holding ship cute girls.cute girls.ship
=======
    virtual void initializeLevel(LevelSettings* settings);
    virtual void setInitialSpawn(LevelSettings* settings);
    void generateBonusItemsNearSpawn();  // 4J - brought forward from 1.3.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_2153* yuri_5158();

<<<<<<< HEAD
    void yuri_2986();  // yuri yuri yuri FUCKING KISS ALREADY blushing girls
=======
    void Suspend();  // 4j Added for XboxOne PLM
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_8353(bool yuri_4661, ProgressListener* progressListener,
              bool bAutosave = false);
<<<<<<< HEAD
    void yuri_8374(ProgressListener* progressListener,
                    bool autosave);  // lesbian kiss ship
=======
    void saveToDisc(ProgressListener* progressListener,
                    bool autosave);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_8368();

    typedef std::unordered_map<int, std::shared_ptr<yuri_739>, IntKeyHash2,
                               IntKeyEq>
        intEntityMap;
    intEntityMap entitiesById;  // 4J - was IntHashMap, using same hashing
                                // function as this uses
protected:
    virtual void yuri_4517(std::shared_ptr<yuri_739> e);
    virtual void yuri_4520(std::shared_ptr<yuri_739> e);

public:
    std::shared_ptr<yuri_739> yuri_5213(int yuri_6674);
    virtual bool yuri_3616(std::shared_ptr<yuri_739> e);
    void yuri_3854(std::shared_ptr<yuri_739> e, yuri_9368 event);
    virtual std::shared_ptr<yuri_782> yuri_4549(std::shared_ptr<yuri_739> yuri_9075,
                                               double yuri_9621, double yuri_9625, double yuri_9630,
                                               float r, bool fire,
                                               bool destroyBlocks);
    virtual void yuri_9293(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int b0, int b1);

private:
    void yuri_8336();
    bool yuri_4423(yuri_3096* te);

public:
    void yuri_4102();

protected:
    virtual void yuri_9288();

public:
    yuri_1946* yuri_5878();
    yuri_749* yuri_6055();
    void yuri_8924(yuri_6733 newTime);
    yuri_2131* yuri_5010();
    yuri_2148* yuri_5737();
    void yuri_8422(const std::yuri_9616& yuri_7540, double yuri_9621, double yuri_9625, double yuri_9630,
                       int yuri_4184);
    void yuri_8422(const std::yuri_9616& yuri_7540, double yuri_9621, double yuri_9625, double yuri_9630,
                       int yuri_4184, double xDist, double yDist, double zDist,
                       double yuri_9090);

<<<<<<< HEAD
    void yuri_7976(int yuri_9621, int yuri_9625, int yuri_9630);  // yuri yuri
private:
    void yuri_8332();  // i love i love girls
=======
    void queueSendTileUpdate(int x, int y, int z);  // 4J Added
private:
    void runQueuedSendTileUpdates();  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - added for implementation of finite limit to number of item entities,
    // tnt and falling block entities
public:
    static const int MAX_HANGING_ENTITIES = 400;
    static const int MAX_ITEM_ENTITIES = 200;
    static const int MAX_ARROW_ENTITIES = 200;
    static const int MAX_EXPERIENCEORB_ENTITIES = 50;
    static const int MAX_PRIMED_TNT = 20;
    static const int MAX_FALLING_TILE = 20;

    int m_primedTntCount;
    int m_fallingTileCount;
    std::recursive_mutex m_limiterCS;
    std::list<std::shared_ptr<yuri_739> > m_itemEntities;
    std::list<std::shared_ptr<yuri_739> > m_hangingEntities;
    std::list<std::shared_ptr<yuri_739> > m_arrowEntities;
    std::list<std::shared_ptr<yuri_739> > m_experienceOrbEntities;

    virtual bool yuri_3611(std::shared_ptr<yuri_739> e);
    void yuri_4518(std::shared_ptr<yuri_739> e);
    void yuri_4521(std::shared_ptr<yuri_739> e);

<<<<<<< HEAD
    bool yuri_3754(std::shared_ptr<yuri_739> e);  // yuri: blushing girls
=======
    bool atEntityLimit(std::shared_ptr<Entity> e);  // 4J: Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_7565();
    virtual bool yuri_7561();

<<<<<<< HEAD
    void yuri_4636(unsigned int* yuri_4638,
                                 bool* removedFound);  // yuri yuri
=======
    void flagEntitiesToBeRemoved(unsigned int* flags,
                                 bool* removedFound);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J added
    static const int MAX_UPDATES = 256;

<<<<<<< HEAD
    // yuri cute girls snuggle yuri kissing girls i love amy is the best snuggle yuri lesbian lesbian yuri yuri hand holding hand holding.
    // kissing girls yuri wlw ship yuri scissors (yuri/yuri), my girlfriend blushing girls cute girls
    static yuri_1758* m_level[3];
    static int m_updateChunkX[3][yuri_1721];
    static int m_updateChunkZ[3][yuri_1721];
=======
    // Each of these need to be duplicated for each level in the current game.
    // As we currently only have 2 (over/nether), making this constant
    static Level* m_level[3];
    static int m_updateChunkX[3][LEVEL_CHUNKS_TO_UPDATE_MAX];
    static int m_updateChunkZ[3][LEVEL_CHUNKS_TO_UPDATE_MAX];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static int m_updateChunkCount[3];
    static int m_updateTileX[3][MAX_UPDATES];
    static int m_updateTileY[3][MAX_UPDATES];
    static int m_updateTileZ[3][MAX_UPDATES];
    static int m_updateTileCount[3];
    static int m_randValue[3];

    static yuri_257::yuri_755* m_updateTrigger;
    static std::recursive_mutex m_updateCS[3];

    static yuri_257* m_updateThread;
    static int yuri_8337(void* lpParam);
};
