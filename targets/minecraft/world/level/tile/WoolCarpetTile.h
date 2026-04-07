#pragma once

#include <memory>
#include <optional>

#include "Tile.h"

class yuri_1758;

class yuri_3394 : public yuri_3088 {
    friend class yuri_3088;

protected:
    yuri_3394(int yuri_6674);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_3828();
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    void yuri_9402();
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());

protected:
    void yuri_9461(int yuri_4295);

public:
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    bool yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    int yuri_5947(int yuri_4295);
    static int yuri_6033(int auxValue);
    static int yuri_5420(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
};
