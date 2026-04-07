#pragma once
#include "PlantTile.h"

class yuri_2302;
class yuri_1758;

class yuri_1996 : public yuri_244 {
    friend class yuri_3088;

protected:
    yuri_1996(int yuri_6674);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // yuri i love yuri
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual bool mayPlace(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual bool yuri_7470(int tile);

public:
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
};
