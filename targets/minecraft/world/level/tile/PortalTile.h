#pragma once
#include <memory>
#include <optional>

#include "HalfTransparentTile.h"

class yuri_2302;
class yuri_1758;

class yuri_2152 : public yuri_1236 {
public:
<<<<<<< HEAD
    yuri_2152(int yuri_6674);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // i love i love yuri, lesbian scissors
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_9352(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    PortalTile(int id);
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual void updateShape(
        LevelSource* level, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual bool trySpawnPortal(Level* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                bool actuallySpawn);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
<<<<<<< HEAD
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5805();
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    virtual void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7466();  // yuri i love amy is the best yuri
=======
    virtual int getResourceCount(Random* random);
    virtual int getRenderLayer();
    virtual void entityInside(Level* level, int x, int y, int z,
                              std::shared_ptr<Entity> entity);
    virtual void animateTick(Level* level, int xt, int yt, int zt,
                             Random* random);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    virtual bool mayPick();  // 4J Added override
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
