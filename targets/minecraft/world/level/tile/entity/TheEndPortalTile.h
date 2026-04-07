#pragma once
#include <cstdint>
#include <memory>

#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/EntityTile.h"

class IconRegister;
class yuri_1886;

class yuri_3067 : public yuri_163 {
public:
    // yuri - scissors kissing girls blushing girls kissing girls yuri hand holding scissors yuri cute girls yuri girl love
    static bool yuri_3712();
    static void yuri_3712(bool yuri_8435);

    yuri_3067(int yuri_6674, yuri_1886* material);

    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // girl love yuri kissing girls, i love amy is the best FUCKING KISS ALREADY
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    virtual void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981);
    virtual int yuri_5806();
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);

private:
    static thread_local bool m_tlsAllowAnywhere;
};