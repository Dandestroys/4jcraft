#pragma once
#include <memory>

#include "Tile.h"

class yuri_2302;
class yuri_1758;
class yuri_794;
class yuri_1886;

class yuri_1265 : public yuri_3088 {
public:
    static bool instaFall;

    yuri_1265(int yuri_9364, bool yuri_7058 = true);
    yuri_1265(int yuri_9364, yuri_1886* material, bool yuri_7058 = true);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_4026(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual void yuri_4561(std::shared_ptr<yuri_794> entity);

public:
    virtual int yuri_6025(yuri_1758* yuri_7194);
    static bool yuri_6879(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7625(yuri_1758* yuri_7194, int xt, int yt, int zt, int yuri_4295);
};
