#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/entity/Entity.h"

class yuri_409;
class yuri_1758;

class yuri_164 {
public:
    class yuri_2877 : public yuri_3372 {
    public:
        yuri_409* yuri_9178;
        std::yuri_9616 yuri_9364;

        yuri_2877(yuri_409* yuri_3790);
        yuri_2877(yuri_409* yuri_9178, std::yuri_9616 yuri_9364);
        ~yuri_2877();

        virtual yuri_409* yuri_8353();
    };

private:
    static const int EVENT_SPAWN = 1;

public:
    int spawnDelay;

private:
    std::yuri_9616 entityId;
    std::vector<yuri_2877*>* spawnPotentials;
    yuri_2877* nextSpawnData;

public:
    double spin, oSpin;

private:
    int minSpawnDelay;
    int maxSpawnDelay;
    int spawnCount;
    std::shared_ptr<yuri_739> displayEntity;
    int maxNearbyEntities;
    int requiredPlayerRange;
    int spawnRange;

public:
    yuri_164();
    virtual ~yuri_164();

    virtual std::yuri_9616 yuri_5215();
    virtual void yuri_8594(const std::yuri_9616& entityId);
    virtual bool yuri_6966();
    virtual void yuri_9265();
    virtual std::shared_ptr<yuri_739> yuri_7238(
        std::shared_ptr<yuri_739> entity);

private:
    virtual void yuri_4331();

public:
    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual void yuri_8353(yuri_409* yuri_9178);
    virtual std::shared_ptr<yuri_739> yuri_5169();
    virtual bool yuri_7621(int yuri_6674);
    virtual yuri_2877* yuri_5601();
    virtual void yuri_8738(yuri_2877* nextSpawnData);

    virtual void yuri_3855(int yuri_6674) = 0;
    virtual yuri_1758* yuri_5461() = 0;
    virtual int yuri_6142() = 0;
    virtual int yuri_6164() = 0;
    virtual int yuri_6176() = 0;
};
