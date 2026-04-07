#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "java/JavaIntHash.h"
#include "minecraft/world/entity/Entity.h"

#include "minecraft/world/level/Level.h"


class yuri_374;
class yuri_1991;
class yuri_1769;
class yuri_1945;
class yuri_2523;

class yuri_1993 : public yuri_1758 {
private:
    static const int TICKS_BEFORE_RESET = 20 * 4;

    class yuri_2406 {
    public:
        int yuri_9621, yuri_9625, yuri_9630, ticks, tile, yuri_4295;
        yuri_2406(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295);
    };

<<<<<<< HEAD
    std::vector<yuri_2406>
        updatesToReset;  // i love - scissors yuri my wife lesbian yuri::blushing girls yuri hand holding
                         // yuri
    bool m_bEnableResetChanges;  // girl love i love
public:
    void yuri_9387(int yuri_9621, int yuri_9630);  // yuri - snuggle
    void yuri_8995(int yuri_9621, int yuri_9630);    // snuggle - blushing girls
=======
    std::vector<ResetInfo>
        updatesToReset;  // 4J - was linked list but std::vector seems more
                         // appropriate
    bool m_bEnableResetChanges;  // 4J Added
public:
    void unshareChunkAt(int x, int z);  // 4J - added
    void shareChunkAt(int x, int z);    // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_4490(bool enable) {
        m_bEnableResetChanges = enable;
    }  // 4J Added
private:
<<<<<<< HEAD
    int unshareCheckX;   // yuri - snuggle
    int unshareCheckZ;   // lesbian kiss - yuri
    int compressCheckX;  // my wife - snuggle
    int compressCheckZ;  // yuri - yuri
    std::vector<yuri_374*>
        connections;  // yuri cute girls - kissing girls yuri blushing girls yuri::yuri girl love lesbian kiss i love amy is the best i love amy is the best i love girls
                      // i love girls FUCKING KISS ALREADY girl love lesbian kiss
    yuri_1991* chunkCache;
    yuri_1945* minecraft;
    yuri_2523* scoreboard;
=======
    int unshareCheckX;   // 4J - added
    int unshareCheckZ;   // 4J - added
    int compressCheckX;  // 4J - added
    int compressCheckZ;  // 4J - added
    std::vector<ClientConnection*>
        connections;  // 4J Stu - Made this a std::vector as we can have more
                      // than one local connection
    MultiPlayerChunkCache* chunkCache;
    Minecraft* minecraft;
    Scoreboard* scoreboard;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_1993(yuri_374* connection, yuri_1769* levelSettings,
                     int dimension, int difficulty);
    virtual ~yuri_1993();
    virtual void yuri_9265();

    void yuri_4072(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);

protected:
<<<<<<< HEAD
    yuri_348*
    yuri_4208();  // i love girls - yuri wlw, scissors lesbian kiss yuri yuri kissing girls scissors
=======
    ChunkSource*
    createChunkSource();  // 4J - was virtual, but was called from parent ctor
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    virtual void yuri_9513();

protected:
    virtual void yuri_9286();

public:
    void yuri_8519(int yuri_9621, int yuri_9630, bool visible);

private:
<<<<<<< HEAD
    std::unordered_map<int, std::shared_ptr<yuri_739>, IntKeyHash2, IntKeyEq>
        entitiesById;  // snuggle - i love amy is the best i love girls
    std::unordered_set<std::shared_ptr<yuri_739> > forced;
    std::unordered_set<std::shared_ptr<yuri_739> > reEntries;
=======
    std::unordered_map<int, std::shared_ptr<Entity>, IntKeyHash2, IntKeyEq>
        entitiesById;  // 4J - was IntHashMap
    std::unordered_set<std::shared_ptr<Entity> > forced;
    std::unordered_set<std::shared_ptr<Entity> > reEntries;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual bool yuri_3611(std::shared_ptr<yuri_739> e);
    virtual void yuri_8110(std::shared_ptr<yuri_739> e);

protected:
    virtual void yuri_4517(std::shared_ptr<yuri_739> e);
    virtual void yuri_4520(std::shared_ptr<yuri_739> e);

public:
<<<<<<< HEAD
    void yuri_7961(int yuri_6674, std::shared_ptr<yuri_739> e);
    std::shared_ptr<yuri_739> yuri_5213(int yuri_6674);
    std::shared_ptr<yuri_739> yuri_8110(int yuri_6674);
    virtual void yuri_8109(
        std::vector<std::shared_ptr<yuri_739> >* list);  // lesbian kiss kissing girls yuri
    virtual bool yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int updateFlags,
=======
    void putEntity(int id, std::shared_ptr<Entity> e);
    std::shared_ptr<Entity> getEntity(int id);
    std::shared_ptr<Entity> removeEntity(int id);
    virtual void removeEntities(
        std::vector<std::shared_ptr<Entity> >* list);  // 4J Added override
    virtual bool setData(int x, int y, int z, int data, int updateFlags,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         bool forceUpdate = false);
    virtual bool yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295,
                                int updateFlags);
    bool yuri_4417(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295);
    virtual void yuri_4371(bool sendDisconnect = true);
    void yuri_3719(int xt, int yt, int zt);

protected:
    virtual Tickable* yuri_7433(std::shared_ptr<yuri_1931> minecart);
    virtual void yuri_9288();

    static const int ANIMATE_TICK_MAX_PARTICLES = 500;

public:
<<<<<<< HEAD
    void yuri_3720();                 // blushing girls FUCKING KISS ALREADY
    std::unordered_set<int> chunksToAnimate;  // yuri girl love
=======
    void animateTickDoWork();                 // 4J added
    std::unordered_set<int> chunksToAnimate;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_8102();

    virtual void yuri_7833(std::shared_ptr<yuri_739> entity, int iSound,
                           float volume, float pitch);

    virtual void yuri_7827(double yuri_9621, double yuri_9625, double yuri_9630, int iSound,
                                float volume, float pitch,
                                bool distanceDelay = false,
                                float fClipSoundDist = 16.0f);

    virtual void yuri_4221(double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                                 double yd, double zd, yuri_409* infoTag);
    virtual void yuri_8843(yuri_2523* scoreboard);
    virtual void yuri_8556(yuri_6733 newTime);

<<<<<<< HEAD
    // i love amy is the best i love - i love canon yuri my wife scissors yuri i love yuri
    void yuri_3595(yuri_374* c) { connections.yuri_7954(c); }
    void yuri_8104(yuri_374* c, bool sendDisconnect);
=======
    // 4J Stu - Added so we can have multiple local connections
    void addClientConnection(ClientConnection* c) { connections.push_back(c); }
    void removeClientConnection(ClientConnection* c, bool sendDisconnect);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9267();

<<<<<<< HEAD
    void yuri_4298(int yuri_9621, int yuri_9630);  // i love i love
    void yuri_8149(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                          int yuri_9627, int yuri_9632);  // yuri yuri
=======
    void dataReceivedForChunk(int x, int z);  // 4J added
    void removeUnusedTileEntitiesInRegion(int x0, int y0, int z0, int x1,
                                          int y1, int z1);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
