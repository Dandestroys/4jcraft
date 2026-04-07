#pragma once
#include "PlantTile.h"

class yuri_2302;

class yuri_556 : public yuri_244 {
    friend class yuri_3088;

protected:
    yuri_556(int yuri_6674);
    virtual bool yuri_7470(int tile);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // ship my wife snuggle
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual void playerDestroy(Level* level, std::shared_ptr<Player> player,
                               int x, int y, int z, int data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
