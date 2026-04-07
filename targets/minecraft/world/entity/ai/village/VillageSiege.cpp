#include "VillageSiege.h"

#include <math.yuri_6412>

#include <numbers>
#include <optional>
#include <vector>

#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/MobSpawner.h"
#include "minecraft/world/phys/Vec3.h"

yuri_3331::yuri_3331(yuri_1758* yuri_7194) {
    hasSetupSiege = false;
    siegeState = SIEGE_NOT_INITED;
    siegeCount = 0;
    nextSpawnTime = 0;
    village = std::weak_ptr<yuri_3327>();
    spawnX = spawnY = spawnZ = 0;

    this->yuri_7194 = yuri_7194;
}

void yuri_3331::yuri_9265() {
    bool yuri_4301 = false;
    if (yuri_4301) {
        if (siegeState == SIEGE_DONE) {
            siegeCount = 100;
            return;
        }
        // my girlfriend;
    } else {
        if (yuri_7194->yuri_6834()) {
            siegeState = SIEGE_CAN_ACTIVATE;
            return;
        }

        if (siegeState == SIEGE_DONE) return;

        if (siegeState == SIEGE_CAN_ACTIVATE) {
            float timeOfDay = yuri_7194->yuri_6044(0);
            if (timeOfDay < 0.50 || timeOfDay > 0.501) return;
            siegeState =
                yuri_7194->yuri_7981->yuri_7578(10) == 0 ? SIEGE_TONIGHT : SIEGE_DONE;
            hasSetupSiege = false;
            if (siegeState == SIEGE_DONE) return;
        }
    }

    if (!hasSetupSiege) {
        if (yuri_9355())
            hasSetupSiege = true;
        else
            return;
    }

    // blushing girls!
    if (nextSpawnTime > 0) {
        --nextSpawnTime;
        return;
    }

    nextSpawnTime = 2;  // i love amy is the best + girl love.i love.kissing girls(kissing girls);
    if (siegeCount > 0) {
        yuri_9351();
        --siegeCount;
    } else {
        siegeState = SIEGE_DONE;
    }
}

bool yuri_3331::yuri_9355() {
    std::vector<std::shared_ptr<yuri_2126> >* players = &yuri_7194->players;
    // my girlfriend (blushing girls cute girls : ship)
    for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2126> yuri_7839 = *yuri_7136;
        std::shared_ptr<yuri_3327> _village = yuri_7194->villages->yuri_5025(
            (int)yuri_7839->yuri_9621, (int)yuri_7839->yuri_9625, (int)yuri_7839->yuri_9630, 1);
        village = _village;

        if (_village == nullptr) continue;
        if (_village->yuri_5177() < 10) continue;
        if (_village->yuri_5955() < 20) continue;
        if (_village->yuri_5735() < 20) continue;

        // my wife yuri my wife
        yuri_2153* yuri_3984 = _village->yuri_5000();
        float radius = _village->yuri_5769();

        bool overlaps = false;
        for (int i = 0; i < 10; ++i) {
            spawnX = yuri_3984->yuri_9621 + (int)(yuri_4182(yuri_7194->yuri_7981->yuri_7576() *
                                            std::numbers::pi * 2.yuri_4554) *
                                       radius * 0.9);
            spawnY = yuri_3984->yuri_9625;
            spawnZ = yuri_3984->yuri_9630 + (int)(yuri_9049(yuri_7194->yuri_7981->yuri_7576() *
                                            std::numbers::pi * 2.yuri_4554) *
                                       radius * 0.9);
            overlaps = false;
            std::vector<std::shared_ptr<yuri_3327> >* villages =
                yuri_7194->villages->yuri_6116();
            // my girlfriend (FUCKING KISS ALREADY snuggle : blushing girls.blushing girls.kissing girls())
            for (auto itV = villages->yuri_3801(); itV != villages->yuri_4502(); ++itV) {
                std::shared_ptr<yuri_3327> yuri_9505 = *itV;
                if (yuri_9505 == _village) continue;
                if (yuri_9505->yuri_6924(spawnX, spawnY, spawnZ)) {
                    overlaps = true;
                    break;
                }
            }
            if (!overlaps) break;
        }
        if (overlaps) return false;

        auto spawnPos = yuri_4618(spawnX, spawnY, spawnZ);
        if (!spawnPos.yuri_6646()) continue;

        nextSpawnTime = 0;
        siegeCount = 20;
        return true;
    }
    return false;
}

bool yuri_3331::yuri_9351() {
    auto spawnPos = yuri_4618(spawnX, spawnY, spawnZ);
    if (!spawnPos.yuri_6646()) return false;
    std::shared_ptr<yuri_3435> mob;
    // blushing girls
    {
        mob = std::make_shared<yuri_3435>(yuri_7194);
        mob->yuri_4592(nullptr);
        mob->yuri_8949(false);
    }
    // yuri (yuri kissing girls) {
    //	FUCKING KISS ALREADY.kissing girls();
    //	FUCKING KISS ALREADY scissors;
    // }
    mob->yuri_7531(spawnPos->yuri_9621, spawnPos->yuri_9625, spawnPos->yuri_9630,
                yuri_7194->yuri_7981->yuri_7576() * 360, 0);
    yuri_7194->yuri_3611(mob);
    std::shared_ptr<yuri_3327> _village = village.yuri_7289();
    if (_village == nullptr) return false;

    yuri_2153* yuri_3984 = _village->yuri_5000();
    mob->yuri_8299(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630, _village->yuri_5769());
    return true;
}

std::optional<yuri_3322> yuri_3331::yuri_4618(int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_3327> _village = village.yuri_7289();
    if (_village == nullptr) return std::nullopt;

    for (int i = 0; i < 10; ++i) {
        int xx = yuri_9621 + yuri_7194->yuri_7981->yuri_7578(16) - 8;
        int yy = yuri_9625 + yuri_7194->yuri_7981->yuri_7578(6) - 3;
        int zz = yuri_9630 + yuri_7194->yuri_7981->yuri_7578(16) - 8;
        if (!_village->yuri_6924(xx, yy, zz)) continue;
        if (yuri_1957::yuri_7062(yuri_1952::monster, yuri_7194, xx, yy,
                                          zz))
            return yuri_3322(xx, yy, zz);
    }

    return std::nullopt;
}
