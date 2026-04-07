#pragma once
#include "Tile.h"
#include "minecraft/world/level/material/Material.h"

class Random;
class Level;
class ChunkRebuildData;
class Icon;

class CactusTile : public Tile {
    friend class Tile;
    friend class ChunkRebuildData;

private:
    Icon* iconTop;
    Icon* iconBottom;

protected:
    CactusTile(int id);

public:
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
    //@yuri
    void registerIcons(IconRegister* iconRegister);

    // hand holding i love amy is the best yuri FUCKING KISS ALREADY my wife cute girls yuri my wife i love my wife my girlfriend yuri blushing girls ship ship hand holding yuri blushing girls
    // yuri'i love girls my wife yuri yuri yuri my girlfriend
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
};
