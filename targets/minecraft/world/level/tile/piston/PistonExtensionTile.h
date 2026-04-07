#pragma once
#include <memory>

#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

class yuri_2117 : public yuri_3088 {
public:
    // snuggle'scissors i love girls yuri yuri lesbian cute girls yuri yuri
    static const int STICKY_BIT = 8;

private:
    yuri_1346* overrideTopTexture;

public:
    yuri_2117(int yuri_6674);
    virtual void yuri_8756(yuri_1346* overrideTopTexture);
    virtual void yuri_4068();
    virtual void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual int yuri_5806();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // girl love yuri blushing girls, i love my wife
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    static int yuri_5236(int yuri_4295);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};