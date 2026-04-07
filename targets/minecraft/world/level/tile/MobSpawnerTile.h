#pragma once
#include "BaseEntityTile.h"

class yuri_2302;

class yuri_1960 : public yuri_163 {
    friend class yuri_3088;

protected:
    yuri_1960(int yuri_6674);

public:
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_3828();
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};