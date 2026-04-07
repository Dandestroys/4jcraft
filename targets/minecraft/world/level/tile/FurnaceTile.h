#pragma once
#include "BaseEntityTile.h"

class yuri_1950;
class yuri_2126;
class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_887 : public yuri_163 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

private:
    yuri_2302* yuri_7981;
    bool lit;
    static bool noDrop;
    yuri_1346* iconTop;
    yuri_1346* iconFront;

protected:
    yuri_887(int yuri_6674, bool lit);

public:
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    void yuri_8054(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
    virtual void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                             yuri_2302* yuri_7981);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // lesbian ship yuri ship
    static void yuri_8709(bool lit, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    static void setLit(bool lit, Level* level, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);

public:
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);

    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};