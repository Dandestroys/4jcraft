#pragma once
#include <memory>

#include "BaseEntityTile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_2126;
class yuri_2302;
class yuri_436;
class yuri_1758;

class yuri_339 : public yuri_163 {
    friend class yuri_3088;
    friend class yuri_1945;

public:
    static const int TYPE_BASIC = 0;
    static const int TYPE_TRAP = 1;

    static const int EVENT_SET_OPEN_COUNT = 1;

private:
    yuri_2302* yuri_7981;

public:
    int yuri_9364;

protected:
    yuri_339(int yuri_6674, int yuri_9364);
    ~yuri_339();

public:
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int forceData,
                             std::shared_ptr<yuri_3091> forceEntity =
                                 std::shared_ptr<yuri_3091>());
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    void yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    bool yuri_6885(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // yuri yuri yuri yuri
    virtual std::shared_ptr<yuri_436> yuri_5056(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                    int yuri_9630);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual bool yuri_7041();
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual std::shared_ptr<Container> getContainer(Level* level, int x, int y,
                                                    int z);
    virtual std::shared_ptr<TileEntity> newTileEntity(Level* level);
    virtual bool isSignalSource();
    virtual int getSignal(LevelSource* level, int x, int y, int z, int dir);
    virtual int getDirectSignal(LevelSource* level, int x, int y, int z,
                                int dir);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool yuri_6795(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    virtual void yuri_8072(IconRegister* iconRegister);
};