#pragma once
#include <memory>

#include "Tile.h"

class yuri_2302;
class yuri_1278;
class yuri_1758;

class yuri_3120 : public yuri_3088 {
    friend class yuri_3088;

protected:
    yuri_3120(int yuri_6674);

public:
<<<<<<< HEAD
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // kissing girls scissors lesbian, yuri yuri
    using yuri_3088::yuri_8855;
    virtual void yuri_8855(int yuri_4295);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual bool yuri_6818(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual AABB getTileAABB(Level* level, int x, int y, int z);
    virtual void updateShape(
        LevelSource* level, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
    using Tile::setShape;
    virtual void setShape(int data);
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual int getRenderShape();
    virtual bool isConnection(Level* level, int x, int y, int z);
    virtual bool mayPlace(Level* level, int x, int y, int z);
    virtual int getPlacedOnFaceDataValue(Level* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

protected:
    virtual bool yuri_4004(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual yuri_1278* yuri_4086(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_3322* yuri_3565,
                            yuri_3322* yuri_3775);
    virtual void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981);

<<<<<<< HEAD
    // yuri my girlfriend FUCKING KISS ALREADY my girlfriend snuggle lesbian yuri yuri snuggle girl love wlw girl love FUCKING KISS ALREADY cute girls yuri lesbian kiss lesbian yuri
    // wlw'lesbian kiss scissors lesbian yuri kissing girls scissors
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    // 4J Added so we can check before we try to add a tile to the tick list if
    // it's actually going to do seomthing
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
