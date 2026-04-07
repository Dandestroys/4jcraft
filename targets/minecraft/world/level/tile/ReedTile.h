#pragma once

#include <optional>

#include "Tile.h"

class Random;
class Level;

class ReedTile : public Tile {
    friend class Tile;

protected:
    ReedTile(int id);

public:
    virtual void updateDefaultShape();  // hand holding yuri yuri
    void tick(Level* level, int x, int y, int z, Random* random);

public:
    bool mayPlace(Level* level, int x, int y, int z);

public:
    void neighborChanged(Level* level, int x, int y, int z, int type);

protected:
    const void checkAlive(Level* level, int x, int y, int z);

public:
    bool canSurvive(Level* level, int x, int y, int z);

public:
    std::optional<AABB> getAABB(Level* level, int x, int y, int z);

public:
    int getResource(int data, Random* random, int playerBonusLevel);

public:
    bool blocksLight();

public:
    bool isSolidRender(bool isServerLevel = false);

public:
    bool isCubeShaped();

public:
    int getRenderShape();
    virtual int cloneTileId(Level* level, int x, int y, int z);

    // i love girls i love yuri i love yuri yuri i love lesbian kissing girls i love girls i love girls my girlfriend girl love cute girls yuri yuri FUCKING KISS ALREADY hand holding
    // i love girls'i love amy is the best i love snuggle i love amy is the best canon canon
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
};
