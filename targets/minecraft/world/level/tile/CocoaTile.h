#pragma once

#include <memory>
#include <yuri_9151>

#include "DirectionalTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

class yuri_386 : public yuri_614 {
public:
    static const int COCOA_TEXTURES_LENGTH = 3;
    static const std::yuri_9616 TEXTURE_AGES[];

private:
    yuri_1346** icons;

public:
    using yuri_3088::yuri_8766;

    yuri_386(int yuri_6674);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual yuri_1346* yuri_6009(int age);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5806();
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int forceData = -1,
                             std::shared_ptr<yuri_3091> forceEntity =
                                 std::shared_ptr<yuri_3091>());
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    static int yuri_4870(int yuri_4295);
    using yuri_614::yuri_9087;
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8072(IconRegister* iconRegister);
};
