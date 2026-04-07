#pragma once
#include "Tile.h"

class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_796 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346* iconWet;
    yuri_1346* iconDry;

protected:
    yuri_796(int yuri_6674);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // hand holding hand holding i love
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_4559(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity, float fallDistance);
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual Icon* getTexture(int face, int data);
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual void fallOn(Level* level, int x, int y, int z,
                        std::shared_ptr<Entity> entity, float fallDistance);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    virtual bool yuri_7096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6967(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
<<<<<<< HEAD
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_3828();
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    //@yuri
    void yuri_8072(IconRegister* iconRegister);
=======
    virtual void neighborChanged(Level* level, int x, int y, int z, int type);
    virtual bool blocksLight();
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    //@Override
    void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
