#pragma once
#include <memory>
#include <optional>

#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"

class yuri_2119;
class yuri_1758;
class yuri_1771;

class yuri_2118 : public yuri_163 {
public:
    yuri_2118(int yuri_6674);

protected:
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);

public:
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual int yuri_5806();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // ship i love girls yuri cute girls;
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonus);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    static std::shared_ptr<yuri_3091> yuri_7563(
        int block, int yuri_4295, int yuri_4558, bool extending, bool yuri_7061);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // yuri snuggle yuri, yuri yuri

    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                float progress, int yuri_4558);

private:
    std::shared_ptr<yuri_2119> yuri_5213(yuri_1771* yuri_7194, int yuri_9621,
                                                 int yuri_9625, int yuri_9630);

public:
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);
};
