#pragma once
#include <memory>

#include "DirectionalTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_2153;
class yuri_2126;
class yuri_2302;
class yuri_1758;
class yuri_1346;

class yuri_182 : public yuri_614 {
private:
    static const int PART_FOOT = 0;
    static const int PART_HEAD = 1;

    yuri_1346** iconEnd;
    yuri_1346** iconSide;
    yuri_1346** iconTop;

public:
    static const int HEAD_PIECE_DATA = 0x8;
    static const int OCCUPIED_DATA = 0x4;

    static int HEAD_DIRECTION_OFFSETS[4][2];

    yuri_182(int yuri_6674);

    virtual void yuri_9402();
    virtual bool yuri_3033(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // i love girls i love amy is the best wlw canon
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    //@blushing girls
    void yuri_8072(IconRegister* iconRegister);
    virtual int yuri_5806();
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // my wife my girlfriend my wife, i love yuri
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);

private:
    using yuri_3088::yuri_8855;
    void yuri_8855();

public:
    static bool yuri_6898(int yuri_4295);
    static bool yuri_6974(int yuri_4295);
    static void yuri_8745(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool occupied);
    static yuri_2153* yuri_4623(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int skipCount);

    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus);
    virtual int yuri_5694();
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   std::shared_ptr<yuri_2126> yuri_7839);
};
