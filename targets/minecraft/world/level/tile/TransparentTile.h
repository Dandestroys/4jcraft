#pragma once
#include "Tile.h"

class yuri_1886;

class yuri_3131 : public yuri_3088 {
protected:
    bool allowSame;

protected:
    yuri_3131(int yuri_6674, yuri_1886* material, bool allowSame,
                    bool yuri_7058 = false);

public:
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual bool yuri_3828();
};