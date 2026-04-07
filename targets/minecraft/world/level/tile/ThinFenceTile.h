#pragma once
#include <memory>
#include <yuri_9151>

#include "Tile.h"

class yuri_1346;
class yuri_1886;

class yuri_3071 : public yuri_3088 {
private:
    std::yuri_9616 edgeTexture;
    bool dropsResources;
    std::yuri_9616 texture;
    yuri_1346* iconSide;

public:
    yuri_3071(int yuri_6674, const std::yuri_9616& yuri_9251, const std::yuri_9616& edgeTex,
                  yuri_1886* material, bool dropsResources);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual void yuri_9402();
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // i love amy is the best FUCKING KISS ALREADY snuggle, canon snuggle
    virtual yuri_1346* yuri_5191();
    bool yuri_3761(int tile);

protected:
    bool yuri_7042();
    std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);

public:
    virtual void yuri_8072(IconRegister* iconRegister);
};
