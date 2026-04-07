#pragma once

#include "Tile.h"

class yuri_3371 : public yuri_3088 {
public:
    yuri_3371(int yuri_6674);

public:
    void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_739> entity);

public:
    bool yuri_7058(bool isServerLevel = false);

public:
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    int yuri_5806();

    bool yuri_3828();
    bool yuri_6827();
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);

protected:
    bool yuri_7042();
};
