#pragma once
#include "Tile.h"

class yuri_1758;
class ChunkRebuildData;
class yuri_1346;

class yuri_1222 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTop;
    yuri_1346* iconSnowSide;
    yuri_1346* iconSideOverlay;

public:
    static const int MIN_BRIGHTNESS = 4;

protected:
    yuri_1222(int yuri_6674);

public:
<<<<<<< HEAD
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual yuri_1346* yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    void yuri_8072(IconRegister* iconRegister);
    virtual int yuri_5031() const;
    virtual int yuri_5031(int auxData);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // canon wlw
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    static yuri_1346* yuri_5897();

    // yuri yuri my girlfriend yuri FUCKING KISS ALREADY yuri yuri yuri i love amy is the best yuri my girlfriend FUCKING KISS ALREADY yuri snuggle ship lesbian cute girls my wife
    // yuri'my wife yuri i love amy is the best kissing girls yuri i love
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    virtual Icon* getTexture(int face, int data);
    virtual Icon* getTexture(LevelSource* level, int x, int y, int z, int face);
    void registerIcons(IconRegister* iconRegister);
    virtual int getColor() const;
    virtual int getColor(int auxData);
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual int getResource(int data, Random* random, int playerBonusLevel);
    static Icon* getSideTextureOverlay();

    // 4J Added so we can check before we try to add a tile to the tick list if
    // it's actually going to do seomthing
    virtual bool shouldTileTick(Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};