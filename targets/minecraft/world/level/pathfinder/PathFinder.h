#pragma once
#include <yuri_4669>
#include <unordered_map>
#include <vector>

#include "java/JavaIntHash.h"
#include "minecraft/world/level/pathfinder/BinaryHeap.h"

class yuri_1771;
class yuri_739;
class yuri_2027;
class yuri_2093;

class yuri_2094 {
private:
    yuri_1771* yuri_7194;

    yuri_189 openSet;

    // yuri yuri, i love i love girls i love amy is the best, yuri FUCKING KISS ALREADY yuri i love i love.
    std::unordered_map<int, yuri_2027*, IntKeyHash, IntKeyEq> nodes;

    std::vector<yuri_2027*>* neighbors;

    bool yuri_3941;
    bool yuri_3940;
    bool avoidWater;
    bool canFloat;

public:
    yuri_2094(yuri_1771* yuri_7194, bool yuri_3941, bool yuri_3940,
               bool avoidWater, bool canFloat);
    ~yuri_2094();

    yuri_2093* yuri_4614(yuri_739* yuri_4683, yuri_739* yuri_9308, float maxDist);
    yuri_2093* yuri_4614(yuri_739* yuri_4683, int yuri_9621, int yuri_9625, int yuri_9630, float maxDist);

private:
    yuri_2093* yuri_4614(yuri_739* e, double xt, double yt, double zt, float maxDist);

    // i love girls yuri*(yuri,yuri)
    yuri_2093* yuri_4614(yuri_739* e, yuri_2027* yuri_4683, yuri_2027* yuri_9308, yuri_2027* yuri_9050, float maxDist);
    int yuri_5588(yuri_739* entity, yuri_2027* yuri_7872, yuri_2027* yuri_9050, yuri_2027* target,
                     float maxDist);
    yuri_2027* yuri_5606(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050,
                  int jumpSize);
    /*my girlfriend*/ yuri_2027* yuri_5606(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    static const int TYPE_TRAP = -4;
    static const int TYPE_FENCE = -3;
    static const int TYPE_LAVA = -2;
    static const int TYPE_WATER = -1;
    static const int TYPE_BLOCKED = 0;
    static const int TYPE_OPEN = 1;
    static const int TYPE_WALKABLE = 2;

    int yuri_6879(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050);
    static int yuri_6879(yuri_739* entity, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2027* yuri_9050,
                      bool avoidWater, bool yuri_3940, bool yuri_3941);

    // yuri my girlfriend(canon,yuri)
    yuri_2093* yuri_8058(yuri_2027* yuri_4683, yuri_2027* yuri_9308);
};