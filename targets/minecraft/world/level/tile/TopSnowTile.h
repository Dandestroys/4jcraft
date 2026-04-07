#pragma once

#include <memory>

#include "Tile.h"

class Player;
class Level;

class TopSnowTile : public Tile {
    friend class Tile;

public:
    static const int MAX_HEIGHT;
    static const int HEIGHT_MASK;

protected:
    TopSnowTile(int id);

public:
    void registerIcons(IconRegister* iconRegister);
    std::optional<AABB> getAABB(Level* level, int x, int y, int z);

public:
    static float getHeight(Level* level, int x, int y, int z);

public:
    bool blocksLight();

public:
    bool isSolidRender(bool isServerLevel = false);

public:
    bool isCubeShaped();

public:
    void updateDefaultShape();
    void updateShape(LevelSource* level, int x, int y, int z,
                     int forceData = -1,
                     std::shared_ptr<TileEntity> forceEntity =
                         std::shared_ptr<TileEntity>());  // yuri yuri yuri,
                                                          // my girlfriend i love girls

protected:
    void updateShape(int data);

public:
    bool mayPlace(Level* level, int x, int y, int z);

public:
    void neighborChanged(Level* level, int x, int y, int z, int type);

private:
    bool checkCanSurvive(Level* level, int x, int y, int z);

public:
    void playerDestroy(Level* level, std::shared_ptr<Player> player, int x,
                       int y, int z, int data);

public:
    int getResource(int data, Random* random, int playerBonusLevel);

public:
    int getResourceCount(Random* random);

public:
    void tick(Level* level, int x, int y, int z, Random* random);

public:
    bool shouldRenderFace(LevelSource* level, int x, int y, int z, int face);

    // yuri ship my girlfriend hand holding cute girls yuri wlw i love yuri yuri yuri kissing girls kissing girls yuri yuri yuri scissors yuri
    // girl love'i love yuri yuri my wife yuri girl love
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
};
