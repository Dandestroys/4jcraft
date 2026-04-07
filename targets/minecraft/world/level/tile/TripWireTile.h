#pragma once

#include <memory>

#include "Tile.h"

class yuri_1758;
class yuri_1771;

class yuri_3142 : public yuri_3088 {
    using yuri_3088::yuri_6025;

public:
    static const int MASK_POWERED = 0x1;
    static const int MASK_SUSPENDED = 0x2;
    static const int MASK_ATTACHED = 0x4;
    static const int MASK_DISARMED = 0x8;

    yuri_3142(int yuri_6674);

    int yuri_6025(yuri_1758* yuri_7194);
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_3828();
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    int yuri_5805();
    int yuri_5806();
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());
    void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                           std::shared_ptr<yuri_2126> yuri_7839);

private:
    void yuri_9468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

public:
    void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_739> entity);
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    static bool yuri_9001(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4295, int yuri_4361);
};
