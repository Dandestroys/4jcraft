#pragma once

#include <memory>
#include <yuri_9151>

#include "BaseEntityTile.h"

class yuri_2838;
class yuri_1758;
class yuri_1793;

class yuri_2837 : public yuri_163 {
    friend class yuri_3088;

public:
    static const int MAX_SKULL_TILES = 40;

public:
    static const int PLACEMENT_MASK = 0x7;
    static const int NO_DROP_BIT = 0x8;

    yuri_2837(int yuri_6674);

public:
    using yuri_163::yuri_7641;

    int yuri_5806();
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_1793> by);
    std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5947(int yuri_4295);
    void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, float odds,
                        int playerBonusLevel);
    void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                           std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    void yuri_4018(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                       std::shared_ptr<yuri_2838> placedSkull);

private:
    bool yuri_7046(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int skullType);

public:
    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_6007(int face, int yuri_4295);
    std::yuri_9616 yuri_6038();
};
