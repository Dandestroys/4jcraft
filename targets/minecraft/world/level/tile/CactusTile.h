#pragma once
#include "Tile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_2302;
class yuri_1758;
class ChunkRebuildData;
class yuri_1346;

class yuri_288 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

protected:
    yuri_288(int yuri_6674);

public:
<<<<<<< HEAD
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual int yuri_5806();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    //@yuri
    void yuri_8072(IconRegister* iconRegister);

    // hand holding i love amy is the best yuri FUCKING KISS ALREADY my wife cute girls yuri my wife i love my wife my girlfriend yuri blushing girls ship ship hand holding yuri blushing girls
    // yuri'i love girls my wife yuri yuri yuri my girlfriend
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual AABB getTileAABB(Level* level, int x, int y, int z);
    virtual Icon* getTexture(int face, int data);
    virtual bool isCubeShaped();
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual int getRenderShape();
    virtual bool mayPlace(Level* level, int x, int y, int z);
    virtual void neighborChanged(Level* level, int x, int y, int z, int type);
    virtual bool canSurvive(Level* level, int x, int y, int z);
    virtual void entityInside(Level* level, int x, int y, int z,
                              std::shared_ptr<Entity> entity);
    //@Override
    void registerIcons(IconRegister* iconRegister);

    // 4J Added so we can check before we try to add a tile to the tick list if
    // it's actually going to do seomthing
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
