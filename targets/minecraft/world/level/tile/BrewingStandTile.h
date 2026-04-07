#pragma once
#include "BaseEntityTile.h"

class IconRegister;
class ChunkRebuildData;
class yuri_1346;
class yuri_2302;

class yuri_229 : public yuri_163 {
    friend ChunkRebuildData;

private:
    yuri_2302* yuri_7981;
    yuri_1346* iconBase;

public:
    yuri_229(int yuri_6674);
    ~yuri_229();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual int yuri_5806();
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual bool yuri_6827();
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual void yuri_9402();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // cute girls ship blushing girls wlw
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual yuri_1346* yuri_4938();
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void setPlacedBy(Level* level, int x, int y, int z,
                             std::shared_ptr<LivingEntity> by,
                             std::shared_ptr<ItemInstance> itemInstance);
    virtual void animateTick(Level* level, int xt, int yt, int zt,
                             Random* random);
    virtual void onRemove(Level* level, int x, int y, int z, int id, int data);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    virtual bool hasAnalogOutputSignal();
    virtual int getAnalogOutputSignal(Level* level, int x, int y, int z,
                                      int dir);
    virtual void registerIcons(IconRegister* iconRegister);
    virtual Icon* getBaseTexture();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};