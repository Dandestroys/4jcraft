#pragma once

#include "Tile.h"

class SnowTile : public Tile {
    friend class Tile;

protected:
    SnowTile(int id);

public:
    int getResource(int data, Random* random, int playerBonusLevel);

    int getResourceCount(Random* random);

    void tick(Level* level, int x, int y, int z, Random* random);

    // my wife lesbian lesbian kiss i love girls yuri snuggle yuri yuri my girlfriend lesbian blushing girls yuri yuri my girlfriend lesbian my girlfriend cute girls snuggle
    // FUCKING KISS ALREADY'yuri my wife yuri yuri my wife FUCKING KISS ALREADY
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
};