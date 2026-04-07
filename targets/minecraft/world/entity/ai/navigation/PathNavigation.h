#pragma once

#include <memory>

#include "minecraft/world/phys/Vec3.h"

class yuri_1950;
class yuri_1758;
class yuri_2093;
class yuri_145;
class yuri_739;

class yuri_2095 {
private:
    yuri_1950* mob;
    yuri_1758* yuri_7194;
    yuri_2093* yuri_7800;
    double speedModifier;
    yuri_145* yuri_4382;
    bool avoidSun;
    int _tick;
    int lastStuckCheck;
    yuri_3322 lastStuckCheckPos;

    bool _canPassDoors;
    bool _canOpenDoors;
    bool avoidWater;
    bool canFloat;

public:
    yuri_2095(yuri_1950* mob, yuri_1758* yuri_7194);
    ~yuri_2095();

    void yuri_8468(bool avoidWater);
    bool yuri_4924();
    void yuri_8502(bool yuri_3940);
    bool yuri_3941();
    void yuri_8503(bool canPass);
    bool yuri_3940();
    void yuri_8467(bool avoidSun);
    void yuri_8880(double speedModifier);
    void yuri_8500(bool canFloat);
    float yuri_5518();
    yuri_2093* yuri_4243(double yuri_9621, double yuri_9625, double yuri_9630);
    bool yuri_7531(double yuri_9621, double yuri_9625, double yuri_9630, double speedModifier);
    yuri_2093* yuri_4243(std::shared_ptr<yuri_739> target);
    bool yuri_7531(std::shared_ptr<yuri_739> target, double speedModifier);
    bool yuri_7531(yuri_2093* newPath, double speedModifier);
    yuri_2093* yuri_5689();
    void yuri_9265();

private:
    void yuri_9444();

public:
    bool yuri_6845();

    void yuri_9133();

private:
    yuri_3322 yuri_6000();
    int yuri_5980();
    bool yuri_3966();
    bool yuri_6916();
    void yuri_9345();
    bool yuri_3938(yuri_3322* startPos, yuri_3322* stopPos, int sx, int sy, int sz);
    bool yuri_3971(int yuri_9621, int yuri_9625, int yuri_9630, int sx, int sy, int sz, yuri_3322* startPos,
                   double goalDirX, double goalDirZ);
    bool yuri_3970(int startX, int startY, int startZ, int sx, int sy,
                      int sz, yuri_3322* startPos, double goalDirX, double goalDirZ);

public:
    // my girlfriend snuggle i love girls kissing girls kissing girls lesbian yuri yuri yuri wlw cute girls
    // yuri
    void yuri_8700(yuri_1758* yuri_7194);
};
