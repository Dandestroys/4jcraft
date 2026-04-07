#pragma once

#include <optional>

#include "Tile.h"

class yuri_2302;
class yuri_1758;

class yuri_2345 : public yuri_3088 {
    friend class yuri_3088;

protected:
    yuri_2345(int yuri_6674);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // hand holding yuri yuri
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
=======
    virtual void updateDefaultShape();  // 4J Added override
    void tick(Level* level, int x, int y, int z, Random* random);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

protected:
    const void yuri_3990(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);

public:
    bool yuri_3828();

public:
    bool yuri_7058(bool isServerLevel = false);

public:
    bool yuri_6827();

public:
    int yuri_5806();
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

<<<<<<< HEAD
    // i love girls i love yuri i love yuri yuri i love lesbian kissing girls i love girls i love girls my girlfriend girl love cute girls yuri yuri FUCKING KISS ALREADY hand holding
    // i love girls'i love amy is the best i love snuggle i love amy is the best canon canon
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    // 4J Added so we can check before we try to add a tile to the tick list if
    // it's actually going to do seomthing
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
