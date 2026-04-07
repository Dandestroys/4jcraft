#pragma once
#include <memory>

#include "EntityRenderer.h"

class yuri_1931;
class yuri_1962;
class yuri_2412;
class yuri_3088;
class yuri_3101;

class yuri_1940 : public yuri_746 {
private:
    static yuri_2412 yuri_1875;

protected:
    yuri_1962* model;
    yuri_3101* renderer;

public:
    yuri_1940();
    virtual void yuri_8158(std::shared_ptr<yuri_739> _cart, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);

protected:
    virtual void yuri_8209(std::shared_ptr<yuri_1931> cart, float yuri_3565,
                                        yuri_3088* tile, int tileData);
};