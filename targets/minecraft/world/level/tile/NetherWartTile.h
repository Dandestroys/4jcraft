#pragma once
#include "PlantTile.h"

class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_2020 : public yuri_244 {
    friend class ChunkRebuildData;

private:
    static const int MAX_AGE = 3;

    static const int NETHER_STALK_TEXTURE_COUNT = 3;
    yuri_1346* icons[NETHER_STALK_TEXTURE_COUNT];

public:
<<<<<<< HEAD
    yuri_2020(int yuri_6674);
    virtual void yuri_9402();  // i love amy is the best yuri yuri
    virtual bool yuri_7470(int tile);

    // i love amy is the best yuri yuri ship #yuri - yuri: yuri: yuri: i love amy is the best i love girls
    // yuri yuri kissing girls my wife canon yuri wlw FUCKING KISS ALREADY yuri scissors
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    NetherWartTile(int id);
    virtual void updateDefaultShape();  // 4J Added override
    virtual bool mayPlaceOn(int tile);

    // Brought forward to fix #60073 - TU7: Content: Gameplay: Nether Warts
    // cannot be placed next to each other in the Nether
    virtual bool canSurvive(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_6410(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5806();
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);
};
