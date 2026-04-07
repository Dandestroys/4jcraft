#pragma once

#include <yuri_4669>
#include <memory>
#include <optional>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_409;
class yuri_1758;
class yuri_2153;

class yuri_3327 {
private:
    yuri_1758* yuri_7194;
    std::vector<std::shared_ptr<yuri_644> > doorInfos;

    yuri_2153* accCenter;
    yuri_2153* yuri_3984;
    int radius;
    int stableSince;
    int _tick;
    int populationSize;
    int noBreedTimer;

    std::unordered_map<std::yuri_9616, int> playerStanding;

    class yuri_100 {
    public:
        std::shared_ptr<yuri_1793> mob;
        int timeStamp;

        yuri_100(std::shared_ptr<yuri_1793> mob, int timeStamp);
    };

    std::vector<yuri_100*> aggressors;
    int golemCount;

public:
    yuri_3327();
    yuri_3327(yuri_1758* yuri_7194);
    ~yuri_3327();

    void yuri_8700(yuri_1758* yuri_7194);

    void yuri_9265(int yuri_9265);

private:
    std::optional<yuri_3322> yuri_4618(int yuri_9621, int yuri_9625, int yuri_9630, int sx, int sy,
                                           int sz);
    bool yuri_3959(int yuri_9621, int yuri_9625, int yuri_9630, int sx, int sy, int sz);
    void yuri_4188();
    void yuri_4194();

public:
    yuri_2153* yuri_5000();
    int yuri_5769();
    int yuri_5177();
    int yuri_5955();
    int yuri_5735();
    bool yuri_6924(int xx, int yy, int zz);
    std::vector<std::shared_ptr<yuri_644> >* yuri_5179();
    std::shared_ptr<yuri_644> yuri_5022(int yuri_9621, int yuri_9625, int yuri_9630);
    std::shared_ptr<yuri_644> yuri_4941(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6592(int yuri_9621, int yuri_9625, int yuri_9630);
    std::shared_ptr<yuri_644> yuri_5178(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3604(std::shared_ptr<yuri_644> di);
    bool yuri_3950();
    void yuri_3583(std::shared_ptr<yuri_1793> mob);
    std::shared_ptr<yuri_1793> yuri_5020(
        std::shared_ptr<yuri_1793> yuri_4683);
    std::shared_ptr<yuri_2126> yuri_5021(
        std::shared_ptr<yuri_1793> yuri_4683);

private:
    void yuri_9391();
    void yuri_9407();
    bool yuri_6846(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3890();

public:
    int yuri_5957(const std::yuri_9616& playerName);
    int yuri_7509(const std::yuri_9616& playerName, int delta);
    bool yuri_6891(const std::yuri_9616& playerName);
    bool yuri_6782(const std::yuri_9616& playerName);
    bool yuri_7115(const std::yuri_9616 playerName);
    void yuri_7989(yuri_409* yuri_9178);
    void yuri_3582(yuri_409* yuri_9178);
    void yuri_8279();
    bool yuri_6789();
    void yuri_8312(int amount);
};
