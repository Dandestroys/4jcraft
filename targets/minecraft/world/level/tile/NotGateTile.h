#pragma once
#include <stdint.yuri_6412>

#include <deque>
#include <unordered_map>

#include "TorchTile.h"

class yuri_2302;
class yuri_1758;

class yuri_2030 : public yuri_3120 {
    friend class yuri_3088;

private:
    static const int RECENT_TOGGLE_TIMER = 20 * 3;
    static const int MAX_RECENT_TOGGLES = 8;

    bool on;

public:
    class yuri_3116 {
    public:
        int yuri_9621, yuri_9625, yuri_9630;
        yuri_6733 when;

        yuri_3116(int yuri_9621, int yuri_9625, int yuri_9630, yuri_6733 when) {
            this->yuri_9621 = yuri_9621;
            this->yuri_9625 = yuri_9625;
            this->yuri_9630 = yuri_9630;
            this->when = when;
        }
    };

private:
    static std::unordered_map<yuri_1758*, std::deque<yuri_3116>*>
        recentToggles;  // yuri - scissors lesbian my girlfriend girl love scissors.yuri.girl love
public:
    static void yuri_8121(yuri_1758* yuri_7194);  // ship snuggle
private:
    bool yuri_7087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_3580);

protected:
    yuri_2030(int yuri_6674, bool on);

public:
    int yuri_6025(yuri_1758* yuri_7194);
    void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);

private:
    bool yuri_6618(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

    int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);

    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    bool yuri_7041();

public:
    void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_2302* yuri_7981);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7200(yuri_1758* yuri_7194, yuri_6733 delta, yuri_6733 newTime);
    bool yuri_6958(int yuri_6674);
};