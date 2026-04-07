#pragma once
#include <yuri_9151>

#include "Tile.h"

class IconRegister;
class yuri_1346;

class yuri_321 : public yuri_3088 {
public:
    static const std::yuri_9616 TEXTURE_INSIDE;
    static const std::yuri_9616 TEXTURE_BOTTOM;

private:
    yuri_1346* iconInner;
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

public:
<<<<<<< HEAD
    yuri_321(int yuri_6674);
    using yuri_3088::yuri_6007;
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    //@hand holding
    void yuri_8072(IconRegister* iconRegister);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual void yuri_9402();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual int yuri_5806();
    virtual bool yuri_6827();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // canon yuri i love my wife
    virtual void yuri_6513(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    static int yuri_5251(int yuri_4295);
=======
    CauldronTile(int id);
    using Tile::getTexture;
    virtual Icon* getTexture(int face, int data);
    //@Override
    void registerIcons(IconRegister* iconRegister);
    static Icon* getTexture(const std::wstring& name);
    virtual void addAABBs(Level* level, int x, int y, int z, AABB* box,
                          std::vector<AABB>* boxes,
                          std::shared_ptr<Entity> source);
    virtual void updateDefaultShape();
    virtual bool isSolidRender(bool isServerLevel = false);
    virtual int getRenderShape();
    virtual bool isCubeShaped();
    virtual bool use(Level* level, int x, int y, int z,
                     std::shared_ptr<Player> player, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void handleRain(Level* level, int x, int y, int z);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    virtual int cloneTileId(Level* level, int x, int y, int z);
    virtual bool hasAnalogOutputSignal();
    virtual int getAnalogOutputSignal(Level* level, int x, int y, int z,
                                      int dir);
    static int getFillLevel(int data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
