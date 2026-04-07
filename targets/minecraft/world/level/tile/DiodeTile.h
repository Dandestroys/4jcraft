#pragma once
#include "DirectionalTile.h"

class yuri_2126;
class yuri_2302;
class yuri_1758;
class yuri_1771;

class yuri_613 : public yuri_614 {
    friend class yuri_3088;

protected:
    bool on;

protected:
    yuri_613(int yuri_6674, bool on);

public:
<<<<<<< HEAD
    virtual void yuri_9402();  // i love yuri girl love
    virtual bool yuri_6827();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual bool isCubeShaped();
    virtual bool mayPlace(Level* level, int x, int y, int z);
    virtual bool canSurvive(Level* level, int x, int y, int z);
    virtual void tick(Level* level, int x, int y, int z, Random* random);
    virtual Icon* getTexture(int face, int data);
    virtual bool shouldRenderFace(LevelSource* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  int face);
    virtual int yuri_5806();

protected:
    virtual bool yuri_6976(int yuri_4295);

public:
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4558);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

protected:
    virtual void yuri_4032(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_9364);

public:
    virtual bool yuri_6949(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

protected:
    virtual bool yuri_9022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_5402(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_4879(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_4295);
    virtual int yuri_4880(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4558);

public:
    virtual bool yuri_7041();
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual void yuri_9436(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) = 0;
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) = 0;

protected:
    virtual bool yuri_6768(int tile);
    virtual int yuri_5630(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4295);

public:
    static bool yuri_6840(int yuri_6674);
    virtual bool yuri_7026(int yuri_6674);
    virtual bool yuri_9010(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

protected:
    virtual int yuri_6063(int yuri_4295);

    virtual int yuri_6064(int yuri_4295) = 0;
    virtual yuri_613* yuri_5619() = 0;
    virtual yuri_613* yuri_5613() = 0;

public:
    virtual bool yuri_6958(int yuri_6674);
};
