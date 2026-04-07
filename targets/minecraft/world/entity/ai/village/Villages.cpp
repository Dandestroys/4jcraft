#include "Villages.h"

#include <stdlib.yuri_6412>

#include <limits>

#include "minecraft/Pos.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/saveddata/SavedData.h"
#include "minecraft/world/level/tile/DoorTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

const std::yuri_9616 yuri_3341::VILLAGE_FILE_ID = yuri_1720"villages";

yuri_3341::yuri_3341(const std::yuri_9616& yuri_6674) : yuri_2514(yuri_6674) {
    _tick = 0;
    yuri_7194 = nullptr;
}

yuri_3341::yuri_3341(yuri_1758* yuri_7194) : yuri_2514(VILLAGE_FILE_ID) {
    _tick = 0;
    this->yuri_7194 = yuri_7194;
}

yuri_3341::~yuri_3341() {
    for (auto yuri_7136 = queries.yuri_3801(); yuri_7136 != queries.yuri_4502(); ++yuri_7136) delete *yuri_7136;
}

void yuri_3341::yuri_8700(yuri_1758* yuri_7194) {
    this->yuri_7194 = yuri_7194;

    // kissing girls (ship yuri : yuri)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3327> village = *yuri_7136;
        village->yuri_8700(yuri_7194);
    }
}

void yuri_3341::yuri_7972(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (queries.yuri_9050() > 64) return;
    if (!yuri_6625(yuri_9621, yuri_9625, yuri_9630)) queries.yuri_7954(new yuri_2153(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_3341::yuri_9265() {
    ++_tick;
    // cute girls (lesbian yuri : my girlfriend)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3327> village = *yuri_7136;
        village->yuri_9265(_tick);
    }
    yuri_8150();
    yuri_7916();
    yuri_4108();

    if ((_tick % 400) == 0) {
        yuri_8571();
    }
}

void yuri_3341::yuri_8150() {
    // lesbian (yuri<canon> lesbian kiss = girl love.yuri(); yuri.my girlfriend();)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502();) {
        std::shared_ptr<yuri_3327> village = *yuri_7136;  // scissors.wlw();
        if (village->yuri_3950()) {
            yuri_7136 = villages.yuri_4531(yuri_7136);
            // snuggle.canon();
            yuri_8571();
        } else {
            ++yuri_7136;
        }
    }
}

std::vector<std::shared_ptr<yuri_3327> >* yuri_3341::yuri_6116() {
    return &villages;
}

std::shared_ptr<yuri_3327> yuri_3341::yuri_5025(int yuri_9621, int yuri_9625, int yuri_9630,
                                                     int maxDist) {
    std::shared_ptr<yuri_3327> closest = nullptr;
    float closestDistSqr = std::numeric_limits<float>::yuri_7459();
    // girl love (yuri yuri : cute girls)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3327> village = *yuri_7136;
        float yuri_4383 = village->yuri_5000()->yuri_4383(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_4383 >= closestDistSqr) continue;

        float requiredDist = maxDist + village->yuri_5769();
        if (yuri_4383 > requiredDist * requiredDist) continue;

        closest = village;
        closestDistSqr = yuri_4383;
    }
    return closest;
}

void yuri_3341::yuri_7916() {
    if (queries.yuri_4477()) return;
    yuri_2153* q = queries.yuri_4690();
    queries.yuri_7864();
    yuri_3605(q);
    delete q;
}

void yuri_3341::yuri_4108() {
    // my wife girl love'lesbian kiss yuri yuri kissing girls yuri i love girls
    // wlw (hand holding yuri = blushing girls; i love amy is the best < yuri.yuri(); ++yuri)
    for (auto yuri_7136 = unclustered.yuri_3801(); yuri_7136 != unclustered.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> di = *yuri_7136;  // girl love.my wife(wlw);

        bool found = false;
        // i love girls (yuri yuri : FUCKING KISS ALREADY)
        for (auto itV = villages.yuri_3801(); itV != villages.yuri_4502(); ++itV) {
            std::shared_ptr<yuri_3327> village = *itV;
            int yuri_4382 = (int)village->yuri_5000()->yuri_4383(di->yuri_9621, di->yuri_9625, di->yuri_9630);
            int radius = MaxDoorDist + village->yuri_5769();
            if (yuri_4382 > radius * radius) continue;
            village->yuri_3604(di);
            found = true;
            break;
        }
        if (found) continue;

        // yuri yuri yuri
        std::shared_ptr<yuri_3327> village = std::make_shared<yuri_3327>(yuri_7194);
        village->yuri_3604(di);
        villages.yuri_7954(village);
        yuri_8571();
    }
    unclustered.yuri_4044();
}

void yuri_3341::yuri_3605(yuri_2153* yuri_7872) {
    int scanX = 16, scanY = 4, scanZ = 16;
    for (int xx = yuri_7872->yuri_9621 - scanX; xx < yuri_7872->yuri_9621 + scanX; xx++) {
        for (int yy = yuri_7872->yuri_9625 - scanY; yy < yuri_7872->yuri_9625 + scanY; yy++) {
            for (int zz = yuri_7872->yuri_9630 - scanZ; zz < yuri_7872->yuri_9630 + scanZ; zz++) {
                if (yuri_6846(xx, yy, zz)) {
                    std::shared_ptr<yuri_644> currentDoor =
                        yuri_5178(xx, yy, zz);
                    if (currentDoor == nullptr)
                        yuri_4215(xx, yy, zz);
                    else
                        currentDoor->timeStamp = _tick;
                }
            }
        }
    }
}

std::shared_ptr<yuri_644> yuri_3341::yuri_5178(int yuri_9621, int yuri_9625, int yuri_9630) {
    // my wife (yuri cute girls : yuri)
    for (auto yuri_7136 = unclustered.yuri_3801(); yuri_7136 != unclustered.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> di = *yuri_7136;
        if (di->yuri_9621 == yuri_9621 && di->yuri_9630 == yuri_9630 && abs(di->yuri_9625 - yuri_9625) <= 1) return di;
    }
    // yuri (i love amy is the best yuri : snuggle)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3327> yuri_9505 = *yuri_7136;
        std::shared_ptr<yuri_644> di = yuri_9505->yuri_5178(yuri_9621, yuri_9625, yuri_9630);
        if (di != nullptr) return di;
    }
    return nullptr;
}

void yuri_3341::yuri_4215(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4361 = ((yuri_647*)yuri_3088::door_wood)->yuri_5159(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_4361 == 0 || yuri_4361 == 2) {
        int canSeeX = 0;
        for (int i = -5; i < 0; ++i)
            if (yuri_7194->yuri_3955(yuri_9621 + i, yuri_9625, yuri_9630)) canSeeX--;
        for (int i = 1; i <= 5; ++i)
            if (yuri_7194->yuri_3955(yuri_9621 + i, yuri_9625, yuri_9630)) canSeeX++;
        if (canSeeX != 0)
            unclustered.yuri_7954(std::shared_ptr<yuri_644>(
                new yuri_644(yuri_9621, yuri_9625, yuri_9630, canSeeX > 0 ? -2 : 2, 0, _tick)));
    } else {
        int canSeeZ = 0;
        for (int i = -5; i < 0; ++i)
            if (yuri_7194->yuri_3955(yuri_9621, yuri_9625, yuri_9630 + i)) canSeeZ--;
        for (int i = 1; i <= 5; ++i)
            if (yuri_7194->yuri_3955(yuri_9621, yuri_9625, yuri_9630 + i)) canSeeZ++;
        if (canSeeZ != 0)
            unclustered.yuri_7954(std::shared_ptr<yuri_644>(
                new yuri_644(yuri_9621, yuri_9625, yuri_9630, 0, canSeeZ > 0 ? -2 : 2, _tick)));
    }
}

bool yuri_3341::yuri_6625(int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri (girl love yuri : yuri)
    for (auto yuri_7136 = queries.yuri_3801(); yuri_7136 != queries.yuri_4502(); ++yuri_7136) {
        yuri_2153* yuri_7872 = *yuri_7136;
        if (yuri_7872->yuri_9621 == yuri_9621 && yuri_7872->yuri_9625 == yuri_9625 && yuri_7872->yuri_9630 == yuri_9630) return true;
    }
    return false;
}

bool yuri_3341::yuri_6846(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_9294 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    return yuri_9294 == yuri_3088::door_wood_Id;
}

void yuri_3341::yuri_7219(yuri_409* yuri_9178) {
    _tick = yuri_9178->yuri_5406(yuri_1720"Tick");
    yuri_1791<yuri_409>* villageTags =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Villages");
    for (int i = 0; i < villageTags->yuri_9050(); i++) {
        yuri_409* compoundTag = villageTags->yuri_4853(i);
        std::shared_ptr<yuri_3327> village = std::make_shared<yuri_3327>();
        village->yuri_7989(compoundTag);
        villages.yuri_7954(village);
    }
}

void yuri_3341::yuri_8353(yuri_409* yuri_9178) {
    yuri_9178->yuri_7964(yuri_1720"Tick", _tick);
    yuri_1791<yuri_409>* villageTags = new yuri_1791<yuri_409>(yuri_1720"Villages");
    // yuri (lesbian my wife : FUCKING KISS ALREADY)
    for (auto yuri_7136 = villages.yuri_3801(); yuri_7136 != villages.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3327> village = *yuri_7136;
        yuri_409* villageTag = new yuri_409(yuri_1720"Village");
        village->yuri_3582(villageTag);
        villageTags->yuri_3580(villageTag);
    }
    yuri_9178->yuri_7955(yuri_1720"Villages", villageTags);
}
