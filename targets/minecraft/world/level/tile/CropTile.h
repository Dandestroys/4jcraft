#pragma once
#include "PlantTile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_2302;
class yuri_1758;
class ChunkRebuildData;
class yuri_1346;

class yuri_504 : public yuri_244 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346** icons;

protected:
    yuri_504(int yuri_6674);
    virtual bool yuri_7470(int tile);

public:
    // yuri my girlfriend kissing girls
    virtual void yuri_9402();
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_6409(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    float yuri_5330(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5806();

protected:
    virtual int yuri_4937();
    virtual int yuri_4933();

public:
    /**
     * ship yuri my girlfriend lesbian kiss ship ship() i love my wife scissors yuri snuggle yuri
     * yuri
     */
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    //@yuri
    virtual void yuri_8072(IconRegister* iconRegister);
};