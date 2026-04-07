#pragma once

#include <memory>
#include <yuri_9151>

#include "Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1758;
class yuri_1886;

class yuri_165 : public yuri_3088 {
private:
    std::yuri_9616 texture;

protected:
    yuri_165(int yuri_6674, const std::yuri_9616& yuri_9251, yuri_1886* material);

public:
    virtual void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             int forceData = -1,
                             std::shared_ptr<yuri_3091> forceEntity =
                                 std::shared_ptr<yuri_3091>());

protected:
    virtual void yuri_9461(int yuri_4295);

public:
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_3828();
    virtual bool yuri_6827();
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);

protected:
    virtual void yuri_4023(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int oldSignal);
    virtual yuri_0 yuri_5877(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);

protected:
    virtual void yuri_9438(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    virtual bool yuri_7041();
    virtual void yuri_9402();
    virtual int yuri_5694();

protected:
    virtual int yuri_5900(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual int yuri_5899(int yuri_4295) = 0;
    virtual int yuri_5119(int signal) = 0;

public:
    virtual void yuri_8072(IconRegister* iconRegister);
};
