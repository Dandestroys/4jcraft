#pragma once
#include <memory>
#include <yuri_9151>

#include "Tile.h"

class yuri_1771;
class yuri_1886;

class yuri_803 : public yuri_3088 {
private:
    std::yuri_9616 texture;

public:
    yuri_803(int yuri_6674, const std::yuri_9616& texture, yuri_1886* material);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // wlw i love canon, yuri i love girls
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual int yuri_5806();
    virtual bool yuri_4140(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    static bool yuri_6865(int tile);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);
};