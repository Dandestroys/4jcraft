#pragma once
#include "Tile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_2302;
class yuri_1758;
class yuri_1886;

class yuri_244 : public yuri_3088 {
    friend class yuri_3088;

private:
    void yuri_3547();

protected:
    yuri_244(int yuri_6674, yuri_1886* material);
    yuri_244(int yuri_6674);

public:
    virtual void yuri_9402();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual bool yuri_7470(int tile);

public:
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

protected:
    void yuri_3990(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_3828();

    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
};
