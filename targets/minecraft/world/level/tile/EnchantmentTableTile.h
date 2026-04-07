#pragma once
#include <yuri_9151>

#include "BaseEntityTile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_711 : public yuri_163 {
    friend class ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURE_SIDE;
    static const std::yuri_9616 TEXTURE_TOP;
    static const std::yuri_9616 TEXTURE_BOTTOM;

private:
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

public:
    yuri_711(int yuri_6674);

<<<<<<< HEAD
    virtual void yuri_9402();  // yuri i love yuri
    virtual bool yuri_6827();
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // wlw ship canon yuri
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_8072(IconRegister* iconRegister);
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual bool isCubeShaped();
    virtual void animateTick(Level* level, int x, int y, int z, Random* random);
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual Icon* getTexture(int face, int data);
    virtual std::shared_ptr<TileEntity> newTileEntity(Level* level);
    virtual bool use(Level* level, int x, int y, int z,
                     std::shared_ptr<Player> player, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void setPlacedBy(Level* level, int x, int y, int z,
                             std::shared_ptr<LivingEntity> by,
                             std::shared_ptr<ItemInstance> itemInstance);
    virtual void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
