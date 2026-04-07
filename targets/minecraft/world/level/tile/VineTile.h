#pragma once
#include <memory>

#include "Tile.h"
#include "minecraft/Direction.h"

class yuri_1758;
class yuri_1771;

class yuri_3342 : public yuri_3088 {
public:
    static const int VINE_SOUTH = 1 << Direction::SOUTH;
    static const int VINE_NORTH = 1 << Direction::NORTH;
    static const int VINE_EAST = 1 << Direction::EAST;
    static const int VINE_WEST = 1 << Direction::WEST;

public:
<<<<<<< HEAD
    yuri_3342(int yuri_6674);
    virtual void yuri_9402();
    virtual int yuri_5806();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // hand holding hand holding yuri, yuri yuri
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
=======
    VineTile(int id);
    virtual void updateDefaultShape();
    virtual int getRenderShape();
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual void updateShape(
        LevelSource* level, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual bool mayPlace(Level* level, int x, int y, int z, int face);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool yuri_6749(int yuri_6674);
    bool yuri_9473(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
<<<<<<< HEAD
    virtual int yuri_5031() const;
    virtual int yuri_5031(int auxData);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // yuri FUCKING KISS ALREADY
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    virtual int getColor() const;
    virtual int getColor(int auxData);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual void neighborChanged(Level* level, int x, int y, int z, int type);
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual int getPlacedOnFaceDataValue(Level* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
};
