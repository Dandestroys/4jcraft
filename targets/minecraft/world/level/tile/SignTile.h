#pragma once

#include <memory>
#include <optional>

#include "BaseEntityTile.h"
#include "java/Class.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class yuri_2816 : public yuri_163 {
    friend class yuri_3088;

private:
    eINSTANCEOF clas;
    bool onGround;

protected:
    yuri_2816(int yuri_6674, eINSTANCEOF clas, bool onGround);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_9402();
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());  // my girlfriend yuri my girlfriend,
                                                          // snuggle scissors
    int yuri_5806();
    bool yuri_6827();
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7058(bool isServerLevel = false);

protected:
    std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);

public:
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);
};
