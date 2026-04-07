#pragma once
#include <memory>
#include <optional>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_548;
class Tickable;
class yuri_1758;
class yuri_3088;

class yuri_1931 : public yuri_739 {
    friend class yuri_1940;

public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART; };

public:
    static const int TYPE_RIDEABLE = 0;
    static const int TYPE_CHEST = 1;
    static const int TYPE_FURNACE = 2;
    static const int TYPE_TNT = 3;
    static const int TYPE_SPAWNER = 4;
    static const int TYPE_HOPPER = 5;

public:
    static const int serialVersionUID = 0;

private:
    static const int DATA_ID_HURT = 17;
    static const int DATA_ID_HURTDIR = 18;
    static const int DATA_ID_DAMAGE = 19;
    static const int DATA_ID_DISPLAY_TILE = 20;
    static const int DATA_ID_DISPLAY_OFFSET = 21;
    static const int DATA_ID_CUSTOM_DISPLAY = 22;

    bool flipped;
    Tickable* soundUpdater;
    std::yuri_9616 yuri_7540;

protected:
    // 4J Added
    bool m_bHasPushedCartThisTick;

public:
    void yuri_3547();

    yuri_1931(yuri_1758* yuri_7194);
    virtual ~yuri_1931();

    static std::shared_ptr<yuri_1931> yuri_4237(yuri_1758* yuri_7194, double yuri_9621,
                                                    double yuri_9625, double yuri_9630,
                                                    int yuri_9364);

protected:
    virtual bool yuri_7434();
    virtual void yuri_4329();

public:
    virtual yuri_0* yuri_5029(std::shared_ptr<yuri_739> entity);
    virtual yuri_0* yuri_5030();
    virtual bool yuri_6998();

    yuri_1931(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    virtual double yuri_5828();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_4347(yuri_548* yuri_9075);
    virtual void yuri_3717();
    virtual bool yuri_6988();
    virtual void yuri_8099();

private:
    static const int EXITS[][2][3];

public:
    virtual void yuri_9265();
    virtual void yuri_3576(int xt, int yt, int zt, bool state);

protected:
    virtual void yuri_4116(double maxSpeed);
    virtual void yuri_7516(int xt, int yt, int zt, double maxSpeed,
                                double slideSpeed, int tile, int yuri_4295);
    virtual void yuri_3735();
    virtual std::optional<yuri_3322> yuri_5741(double yuri_9621, double yuri_9625, double yuri_9630,
                                           double yuri_7605);
    virtual std::optional<yuri_3322> yuri_5739(double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual void yuri_3582(yuri_409* yuri_3790);
    virtual void yuri_7989(yuri_409* yuri_3790);

public:
    virtual float yuri_5885();
    using yuri_739::yuri_7950;
    virtual void yuri_7950(std::shared_ptr<yuri_739> e);

private:
    int lSteps;
    double lx, ly, lz, lyr, lxr;
    double lxd, lyd, lzd;

public:
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    virtual void yuri_7191(double xd, double yd, double zd);

    virtual void yuri_8551(float yuri_4294);
    virtual float yuri_5109();
    virtual void yuri_8655(int hurtTime);
    virtual int yuri_5384();
    virtual void yuri_8654(int hurtDir);
    virtual int yuri_5382();

    virtual int yuri_6068() = 0;

    virtual yuri_3088* yuri_5175();
    virtual yuri_3088* yuri_5137();
    virtual int yuri_5168();
    virtual int yuri_5135();
    virtual int yuri_5172();
    virtual int yuri_5136();
    virtual void yuri_8578(int yuri_6674);
    virtual void yuri_8574(int yuri_4295);
    virtual void yuri_8577(int yuri_7607);
    virtual bool yuri_6588();
    virtual void yuri_8547(bool yuri_9514);
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual std::yuri_9616 yuri_4856();
    virtual bool yuri_6590();
    virtual std::yuri_9616 yuri_5087();
};
