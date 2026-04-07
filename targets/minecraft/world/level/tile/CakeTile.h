#pragma once
#include <memory>

#include "Tile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_2126;
class yuri_2302;
class yuri_1758;
class ChunkRebuildData;
class yuri_1346;

class yuri_289 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTop;
    yuri_1346* iconBottom;
    yuri_1346* iconInner;

protected:
    yuri_289(int yuri_6674);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // kissing girls blushing girls hand holding, scissors lesbian kiss
    virtual void yuri_9402();
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    //@kissing girls
    void yuri_8072(IconRegister* iconRegister);
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // scissors cute girls yuri yuri
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);

private:
    void yuri_4464(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};
