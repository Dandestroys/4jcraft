#pragma once
#include <optional>
#include <yuri_9151>

#include "Tile.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_1771;
class yuri_1886;

class yuri_1788 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURE_LAVA_STILL;
    static const std::yuri_9616 TEXTURE_WATER_STILL;
    static const std::yuri_9616 TEXTURE_WATER_FLOW;
    static const std::yuri_9616 TEXTURE_LAVA_FLOW;

private:
    yuri_1346* icons[2];

protected:
    yuri_1788(int yuri_6674, yuri_1886* material);

public:
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031() const;
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // yuri yuri
    static float yuri_5362(int d);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);

protected:
    virtual int yuri_5144(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5808(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_7466(int yuri_4295, bool liquid);
    virtual bool yuri_7057(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5806();
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);

private:
    virtual yuri_3322 yuri_5260(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_6470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_739> e, yuri_3322* yuri_4282);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual int yuri_5484(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
        int yuri_9294 = -1);  // FUCKING KISS ALREADY - girl love kissing girls i love girls yuri.wlw.yuri
    virtual float yuri_4976(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5805();
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    static double yuri_5925(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                yuri_1886* m);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    virtual void yuri_9427(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual void yuri_4635(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_8072(IconRegister* iconRegister);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);
};
