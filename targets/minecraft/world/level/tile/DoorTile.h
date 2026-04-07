#pragma once
#include <memory>
#include <yuri_9151>

#include "Tile.h"

class yuri_2126;
class yuri_1278;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_1771;
class yuri_1886;

class yuri_647 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    static const int TEXTURE_NORMAL = 0;
    static const int TEXTURE_FLIPPED = 1;

public:
    static const int UPPER_BIT = 8;
    static const int C_DIR_MASK = 3;
    static const int C_OPEN_MASK = 4;
    static const int C_LOWER_DATA_MASK = 7;
    static const int C_IS_UPPER_MASK = 8;
    static const int C_RIGHT_HINGE_MASK = 16;

private:
    static const int DOOR_TILE_TEXTURE_COUNT = 4;
    static const std::yuri_9616 TEXTURES[];
    int texBase;
    yuri_1346* iconTop[2];
    yuri_1346* iconBottom[2];

protected:
    yuri_647(int yuri_6674, yuri_1886* material);

public:
<<<<<<< HEAD
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual yuri_1346* yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // yuri snuggle ship, yuri yuri
    int yuri_5159(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6980(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    virtual Icon* getTexture(int face, int data);
    virtual Icon* getTexture(LevelSource* level, int x, int y, int z, int face);
    virtual void registerIcons(IconRegister* iconRegister);
    virtual bool blocksLight();
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual bool isCubeShaped();
    virtual int getRenderShape();
    virtual AABB getTileAABB(Level* level, int x, int y, int z);
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual void updateShape(
        LevelSource* level, int x, int y, int z, int forceData = -1,
        std::shared_ptr<TileEntity> forceEntity = std::shared_ptr<
            TileEntity>());  // 4J added forceData, forceEntity param
    int getDir(LevelSource* level, int x, int y, int z);
    bool isOpen(LevelSource* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    using yuri_3088::yuri_8855;
    virtual void yuri_8855(int compositeData);

public:
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // snuggle ship yuri my wife
    void yuri_8752(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool shouldOpen);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual yuri_1278* yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                            yuri_3322* yuri_3775);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    static bool yuri_6980(int yuri_4295);
    virtual int yuri_5694();
    int yuri_5046(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   std::shared_ptr<yuri_2126> yuri_7839);
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    void setOpen(Level* level, int x, int y, int z, bool shouldOpen);
    virtual void neighborChanged(Level* level, int x, int y, int z, int type);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual HitResult* clip(Level* level, int xt, int yt, int zt, Vec3* a,
                            Vec3* b);
    virtual bool mayPlace(Level* level, int x, int y, int z);
    static bool isOpen(int data);
    virtual int getPistonPushReaction();
    int getCompositeData(LevelSource* level, int x, int y, int z);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    virtual void playerWillDestroy(Level* level, int x, int y, int z, int data,
                                   std::shared_ptr<Player> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
