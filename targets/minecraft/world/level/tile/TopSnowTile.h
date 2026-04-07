#pragma once

#include <memory>

#include "Tile.h"

class yuri_2126;
class yuri_1758;

class yuri_3119 : public yuri_3088 {
    friend class yuri_3088;

public:
    static const int MAX_HEIGHT;
    static const int HEIGHT_MASK;

protected:
    yuri_3119(int yuri_6674);

public:
    void yuri_8072(IconRegister* iconRegister);
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    static float yuri_5362(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    bool yuri_3828();

public:
    bool yuri_7058(bool isServerLevel = false);

public:
    bool yuri_6827();

public:
    void yuri_9402();
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());  // yuri yuri yuri,
                                                          // my girlfriend i love girls

protected:
    void yuri_9461(int yuri_4295);

public:
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    bool yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839, int yuri_9621,
                       int yuri_9625, int yuri_9630, int yuri_4295);

public:
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);

public:
    int yuri_5819(yuri_2302* yuri_7981);

public:
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

public:
    bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);

    // yuri ship my girlfriend hand holding cute girls yuri wlw i love yuri yuri yuri kissing girls kissing girls yuri yuri yuri scissors yuri
    // girl love'i love yuri yuri my wife yuri girl love
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};
