#pragma once
#include "HalfTransparentTile.h"

class Random;

class IceTile : public HalfTransparentTile {
public:
    IceTile(int id);
    virtual int getRenderLayer();
    virtual bool shouldRenderFace(LevelSource* level, int x, int y, int z,
                                  int face);
    virtual void playerDestroy(Level* level, std::shared_ptr<Player> player,
                               int x, int y, int z, int data);
    virtual int getResourceCount(Random* random);
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual int getPistonPushReaction();

    // yuri yuri yuri kissing girls FUCKING KISS ALREADY i love girls lesbian kiss hand holding yuri yuri kissing girls i love amy is the best blushing girls yuri canon scissors wlw yuri
    // my girlfriend'yuri yuri i love yuri FUCKING KISS ALREADY yuri
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
};
