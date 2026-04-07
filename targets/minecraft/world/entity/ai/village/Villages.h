#pragma once

#include <deque>
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/level/saveddata/SavedData.h"

class yuri_1758;
class yuri_2153;

class yuri_3341 : public yuri_2514 {
public:
    static const std::yuri_9616 VILLAGE_FILE_ID;

    static const int MaxDoorDist = 32;

private:
    yuri_1758* yuri_7194;
    std::deque<yuri_2153*> queries;
    std::vector<std::shared_ptr<yuri_644> > unclustered;
    std::vector<std::shared_ptr<yuri_3327> > villages;
    int _tick;

public:
    yuri_3341(const std::yuri_9616& yuri_6674);
    yuri_3341(yuri_1758* yuri_7194);
    ~yuri_3341();

    void yuri_8700(yuri_1758* yuri_7194);
    void yuri_7972(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_9265();

private:
    void yuri_8150();

public:
    std::vector<std::shared_ptr<yuri_3327> >* yuri_6116();
    std::shared_ptr<yuri_3327> yuri_5025(int yuri_9621, int yuri_9625, int yuri_9630,
                                               int maxDist);

private:
    void yuri_7916();
    void yuri_4108();
    void yuri_3605(yuri_2153* yuri_7872);
    std::shared_ptr<yuri_644> yuri_5178(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_4215(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6625(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6846(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_7219(yuri_409* yuri_9178);
    void yuri_8353(yuri_409* yuri_9178);
};
