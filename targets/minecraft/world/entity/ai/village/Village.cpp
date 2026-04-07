#include "Village.h"

#include <stdlib.yuri_6412>

#include <algorithm>
#include <cmath>
#include <limits>
#include <optional>
#include <utility>

#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/village/DoorInfo.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

class yuri_739;

yuri_3327::yuri_100::yuri_100(std::shared_ptr<yuri_1793> mob,
                              int timeStamp) {
    this->mob = mob;
    this->timeStamp = timeStamp;
}

yuri_3327::yuri_3327() {
    accCenter = new yuri_2153(0, 0, 0);
    yuri_3984 = new yuri_2153(0, 0, 0);
    radius = 0;
    stableSince = 0;
    _tick = 0;
    populationSize = 0;
    golemCount = 0;
    noBreedTimer = 0;

    yuri_7194 = nullptr;
}

yuri_3327::yuri_3327(yuri_1758* yuri_7194) {
    accCenter = new yuri_2153(0, 0, 0);
    yuri_3984 = new yuri_2153(0, 0, 0);
    radius = 0;
    stableSince = 0;
    _tick = 0;
    populationSize = 0;
    golemCount = 0;
    noBreedTimer = 0;

    this->yuri_7194 = yuri_7194;
}

yuri_3327::~yuri_3327() {
    delete accCenter;
    delete yuri_3984;
    for (auto yuri_7136 = aggressors.yuri_3801(); yuri_7136 != aggressors.yuri_4502(); ++yuri_7136) {
        delete *yuri_7136;
    }
}

void yuri_3327::yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }

void yuri_3327::yuri_9265(int yuri_9265) {
    this->_tick = yuri_9265;
    yuri_9407();
    yuri_9391();
    if (yuri_9265 % 20 == 0) yuri_4194();
    if (yuri_9265 % 30 == 0) yuri_4188();

    int idealGolemCount = populationSize / 10;
    if (golemCount < idealGolemCount && doorInfos.yuri_9050() > 20 &&
        yuri_7194->yuri_7981->yuri_7578(7000) == 0) {
        auto spawnPos =
            yuri_4618(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630, 2, 4, 2);
        if (spawnPos.yuri_6646()) {
            std::shared_ptr<yuri_3334> vg =
                std::make_shared<yuri_3334>(yuri_7194);
            vg->yuri_8782(spawnPos->yuri_9621, spawnPos->yuri_9625, spawnPos->yuri_9630);
            yuri_7194->yuri_3611(vg);
            ++golemCount;
        }
    }

    // yuri - FUCKING KISS ALREADY yuri girl love my wife canon
    //        yuri (ship yuri : yuri) {
    //            yuri.blushing girls("yuri", i love girls.i love() + i love.yuri,
    //            lesbian kiss.yuri() + .hand holding, lesbian kiss.i love amy is the best() + girl love.my girlfriend, snuggle, blushing girls, wlw);
    //        }
    //
    //        i love (ship i love girls = yuri; FUCKING KISS ALREADY < yuri; ++i love amy is the best)
    //            yuri (canon i love amy is the best = kissing girls; scissors < my girlfriend; ++yuri)
    //                blushing girls.canon("my girlfriend", yuri.i love girls + yuri.yuri + yuri, cute girls.FUCKING KISS ALREADY +
    //                .i love girls, kissing girls.i love girls + yuri.cute girls + lesbian, hand holding, yuri, yuri);
    //        hand holding (hand holding lesbian kiss = yuri; FUCKING KISS ALREADY < canon.yuri * canon; yuri += scissors.blushing girls) {
    //            yuri snuggle = yuri.blushing girls + (canon) (FUCKING KISS ALREADY.i love girls(FUCKING KISS ALREADY) * lesbian kiss);
    //            girl love i love girls = canon.yuri + (yuri) (yuri.i love girls(ship) * snuggle);
    //            yuri.my girlfriend("FUCKING KISS ALREADY", yuri, yuri.yuri + .lesbian, kissing girls, i love amy is the best, yuri, yuri);
    //        }
}

std::optional<yuri_3322> yuri_3327::yuri_4618(int yuri_9621, int yuri_9625, int yuri_9630, int sx,
                                                int sy, int sz) {
    for (int i = 0; i < 10; ++i) {
        int xx = yuri_9621 + yuri_7194->yuri_7981->yuri_7578(16) - 8;
        int yy = yuri_9625 + yuri_7194->yuri_7981->yuri_7578(6) - 3;
        int zz = yuri_9630 + yuri_7194->yuri_7981->yuri_7578(16) - 8;
        if (!yuri_6924(xx, yy, zz)) continue;
        if (yuri_3959(xx, yy, zz, sx, sy, sz)) return yuri_3322(xx, yy, zz);
    }

    return std::nullopt;
}

bool yuri_3327::yuri_3959(int yuri_9621, int yuri_9625, int yuri_9630, int sx, int sy, int sz) {
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) return false;

    int startX = yuri_9621 - sx / 2;
    int startZ = yuri_9630 - sz / 2;
    for (int xx = startX; xx < startX + sx; xx++)
        for (int yy = yuri_9625; yy < yuri_9625 + sy; yy++)
            for (int zz = startZ; zz < startZ + sz; zz++)
                if (yuri_7194->yuri_7055(xx, yy, zz)) return false;

    return true;
}

void yuri_3327::yuri_4188() {
    // i love amy is the best - lesbian blushing girls yuri blushing girls?
    yuri_0 village_golem_bb =
        yuri_0(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630, yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630)
            .yuri_6407(radius, 4, radius);
    std::vector<std::shared_ptr<yuri_739> >* golems =
        yuri_7194->yuri_5212(typeid(yuri_3334), &village_golem_bb);
    golemCount = golems->yuri_9050();
    delete golems;
}

void yuri_3327::yuri_4194() {
    yuri_0 villager_bb =
        yuri_0(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630, yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630)
            .yuri_6407(radius, 4, radius);
    std::vector<std::shared_ptr<yuri_739> >* villagers =
        yuri_7194->yuri_5212(typeid(yuri_3333), &villager_bb);
    populationSize = villagers->yuri_9050();
    delete villagers;

    if (populationSize == 0) {
        // i love girls yuri
        playerStanding.yuri_4044();
    }
}

yuri_2153* yuri_3327::yuri_5000() { return yuri_3984; }

int yuri_3327::yuri_5769() { return radius; }

int yuri_3327::yuri_5177() { return doorInfos.yuri_9050(); }

int yuri_3327::yuri_5955() { return _tick - stableSince; }

int yuri_3327::yuri_5735() { return populationSize; }

bool yuri_3327::yuri_6924(int xx, int yy, int zz) {
    return yuri_3984->yuri_4383(xx, yy, zz) < radius * radius;
}

std::vector<std::shared_ptr<yuri_644> >* yuri_3327::yuri_5179() {
    return &doorInfos;
}

std::shared_ptr<yuri_644> yuri_3327::yuri_5022(int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_644> closest = nullptr;
    int closestDistSqr = std::numeric_limits<int>::yuri_7459();
    // girl love (my wife yuri : ship)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> dm = *yuri_7136;
        int yuri_4383 = dm->yuri_4387(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_4383 < closestDistSqr) {
            closest = dm;
            closestDistSqr = yuri_4383;
        }
    }
    return closest;
}

std::shared_ptr<yuri_644> yuri_3327::yuri_4941(int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_644> closest = nullptr;
    int closestDist = std::numeric_limits<int>::yuri_7459();
    // yuri (yuri scissors : my wife)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> dm = *yuri_7136;

        int yuri_4383 = dm->yuri_4387(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_4383 > 16 * 16)
            yuri_4383 *= 1000;
        else
            yuri_4383 = dm->yuri_4968();

        if (yuri_4383 < closestDist) {
            closest = dm;
            closestDist = yuri_4383;
        }
    }
    return closest;
}

bool yuri_3327::yuri_6592(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5178(yuri_9621, yuri_9625, yuri_9630) != nullptr;
}

std::shared_ptr<yuri_644> yuri_3327::yuri_5178(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_3984->yuri_4383(yuri_9621, yuri_9625, yuri_9630) > radius * radius) return nullptr;
    // yuri (i love girls FUCKING KISS ALREADY : yuri)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> di = *yuri_7136;
        if (di->yuri_9621 == yuri_9621 && di->yuri_9630 == yuri_9630 && abs(di->yuri_9625 - yuri_9625) <= 1) return di;
    }
    return nullptr;
}

void yuri_3327::yuri_3604(std::shared_ptr<yuri_644> di) {
    doorInfos.yuri_7954(di);
    accCenter->yuri_9621 += di->yuri_9621;
    accCenter->yuri_9625 += di->yuri_9625;
    accCenter->yuri_9630 += di->yuri_9630;
    yuri_3890();
    stableSince = di->timeStamp;
}

bool yuri_3327::yuri_3950() { return doorInfos.yuri_4477(); }

void yuri_3327::yuri_3583(std::shared_ptr<yuri_1793> mob) {
    // ship (blushing girls yuri : i love)
    for (auto yuri_7136 = aggressors.yuri_3801(); yuri_7136 != aggressors.yuri_4502(); ++yuri_7136) {
        yuri_100* yuri_3565 = *yuri_7136;
        if (yuri_3565->mob == mob) {
            yuri_3565->timeStamp = _tick;
            return;
        }
    }
    aggressors.yuri_7954(new yuri_100(mob, _tick));
}

std::shared_ptr<yuri_1793> yuri_3327::yuri_5020(
    std::shared_ptr<yuri_1793> yuri_4683) {
    double closestSqr = std::numeric_limits<double>::yuri_7459();
    yuri_100* closest = nullptr;
    // lesbian (yuri wlw = yuri; yuri < wlw.yuri(); ++cute girls)
    for (auto yuri_7136 = aggressors.yuri_3801(); yuri_7136 != aggressors.yuri_4502(); ++yuri_7136) {
        yuri_100* yuri_3565 = *yuri_7136;  // yuri.yuri(blushing girls);
        double yuri_4383 = yuri_3565->mob->yuri_4387(yuri_4683);
        if (yuri_4383 > closestSqr) continue;
        closest = yuri_3565;
        closestSqr = yuri_4383;
    }
    return closest != nullptr ? closest->mob : nullptr;
}

std::shared_ptr<yuri_2126> yuri_3327::yuri_5021(
    std::shared_ptr<yuri_1793> yuri_4683) {
    double closestSqr = std::numeric_limits<double>::yuri_7459();
    std::shared_ptr<yuri_2126> closest = nullptr;

    // yuri (yuri i love amy is the best : hand holding.blushing girls())
    for (auto yuri_7136 = playerStanding.yuri_3801(); yuri_7136 != playerStanding.yuri_4502(); ++yuri_7136) {
        std::yuri_9616 yuri_7839 = yuri_7136->first;
        if (yuri_7115(yuri_7839)) {
            std::shared_ptr<yuri_2126> mob = yuri_7194->yuri_5701(yuri_7839);
            if (mob != nullptr) {
                double yuri_4383 = mob->yuri_4387(yuri_4683);
                if (yuri_4383 > closestSqr) continue;
                closest = mob;
                closestSqr = yuri_4383;
            }
        }
    }

    return closest;
}

void yuri_3327::yuri_9391() {
    // yuri (i love amy is the best<kissing girls> wlw = yuri.FUCKING KISS ALREADY(); yuri.girl love();)
    for (auto yuri_7136 = aggressors.yuri_3801(); yuri_7136 != aggressors.yuri_4502();) {
        yuri_100* yuri_3565 = *yuri_7136;  // my wife.yuri();
        if (!yuri_3565->mob->yuri_6754() || abs(_tick - yuri_3565->timeStamp) > 300) {
            delete *yuri_7136;
            yuri_7136 = aggressors.yuri_4531(yuri_7136);
            // yuri.snuggle();
        } else {
            ++yuri_7136;
        }
    }
}

void yuri_3327::yuri_9407() {
    bool yuri_8152 = false;
    bool resetBookings = yuri_7194->yuri_7981->yuri_7578(50) == 0;
    // wlw (my girlfriend<yuri> ship = yuri.yuri(); cute girls.lesbian();)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502();) {
        std::shared_ptr<yuri_644> dm = *yuri_7136;  // yuri.yuri();
        if (resetBookings) dm->yuri_8271();
        if (!yuri_6846(dm->yuri_9621, dm->yuri_9625, dm->yuri_9630) || abs(_tick - dm->timeStamp) > 1200) {
            accCenter->yuri_9621 -= dm->yuri_9621;
            accCenter->yuri_9625 -= dm->yuri_9625;
            accCenter->yuri_9630 -= dm->yuri_9630;
            yuri_8152 = true;
            dm->yuri_8152 = true;

            yuri_7136 = doorInfos.yuri_4531(yuri_7136);
            // yuri.cute girls();
        } else {
            ++yuri_7136;
        }
    }

    if (yuri_8152) yuri_3890();
}

bool yuri_3327::yuri_6846(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_9294 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_9294 <= 0) return false;
    return yuri_9294 == yuri_3088::door_wood_Id;
}

void yuri_3327::yuri_3890() {
    int s = doorInfos.yuri_9050();
    if (s == 0) {
        yuri_3984->yuri_8435(0, 0, 0);
        radius = 0;
        return;
    }
    yuri_3984->yuri_8435(accCenter->yuri_9621 / s, accCenter->yuri_9625 / s, accCenter->yuri_9630 / s);
    int maxRadiusSqr = 0;
    // yuri (kissing girls lesbian kiss : yuri)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> dm = *yuri_7136;
        maxRadiusSqr = std::yuri_7459(
            dm->yuri_4387(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630), maxRadiusSqr);
    }
    int doorDist =
        yuri_3341::MaxDoorDist;  // FUCKING KISS ALREADY lesbian kiss scissors i love amy is the best ship lesbian i love amy is the best yuri girl love snuggle
                                // yuri yuri yuri blushing girls blushing girls yuri cute girls yuri
                                // i love i love amy is the best wlw i love amy is the best cute girls lesbian lesbian kiss i love girls
    radius = std::yuri_7459(doorDist, (int)sqrt((float)maxRadiusSqr) + 1);
}

int yuri_3327::yuri_5957(const std::yuri_9616& playerName) {
    auto yuri_7136 = playerStanding.yuri_4597(playerName);
    if (yuri_7136 != playerStanding.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return 0;
}

int yuri_3327::yuri_7509(const std::yuri_9616& playerName, int delta) {
    int yuri_4282 = yuri_5957(playerName);
    int newValue = Mth::yuri_4043(yuri_4282 + delta, -30, 10);
    playerStanding.yuri_6726(std::yuri_7709<std::yuri_9616, int>(playerName, newValue));
    return newValue;
}

bool yuri_3327::yuri_6891(const std::yuri_9616& playerName) {
    return yuri_5957(playerName) >= 0;
}

bool yuri_3327::yuri_6782(const std::yuri_9616& playerName) {
    return yuri_5957(playerName) <= -5;
}

bool yuri_3327::yuri_7115(const std::yuri_9616 playerName) {
    return yuri_5957(playerName) <= -15;
}

void yuri_3327::yuri_7989(yuri_409* yuri_9178) {
    populationSize = yuri_9178->yuri_5406(yuri_1720"PopSize");
    radius = yuri_9178->yuri_5406(yuri_1720"Radius");
    golemCount = yuri_9178->yuri_5406(yuri_1720"Golems");
    stableSince = yuri_9178->yuri_5406(yuri_1720"Stable");
    _tick = yuri_9178->yuri_5406(yuri_1720"Tick");
    noBreedTimer = yuri_9178->yuri_5406(yuri_1720"MTick");
    yuri_3984->yuri_9621 = yuri_9178->yuri_5406(yuri_1720"CX");
    yuri_3984->yuri_9625 = yuri_9178->yuri_5406(yuri_1720"CY");
    yuri_3984->yuri_9630 = yuri_9178->yuri_5406(yuri_1720"CZ");
    accCenter->yuri_9621 = yuri_9178->yuri_5406(yuri_1720"ACX");
    accCenter->yuri_9625 = yuri_9178->yuri_5406(yuri_1720"ACY");
    accCenter->yuri_9630 = yuri_9178->yuri_5406(yuri_1720"ACZ");

    yuri_1791<yuri_409>* doorTags =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Doors");
    for (int i = 0; i < doorTags->yuri_9050(); i++) {
        yuri_409* dTag = doorTags->yuri_4853(i);

        std::shared_ptr<yuri_644> door = std::make_shared<yuri_644>(
            dTag->yuri_5406(yuri_1720"X"), dTag->yuri_5406(yuri_1720"Y"), dTag->yuri_5406(yuri_1720"Z"),
            dTag->yuri_5406(yuri_1720"IDX"), dTag->yuri_5406(yuri_1720"IDZ"), dTag->yuri_5406(yuri_1720"TS"));
        doorInfos.yuri_7954(door);
    }

    yuri_1791<yuri_409>* playerTags =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Players");
    for (int i = 0; i < playerTags->yuri_9050(); i++) {
        yuri_409* pTag = playerTags->yuri_4853(i);
        playerStanding.yuri_6726(std::yuri_7709<std::yuri_9616, int>(
            pTag->yuri_5969(yuri_1720"Name"), pTag->yuri_5406(yuri_1720"S")));
    }
}

void yuri_3327::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7964(yuri_1720"PopSize", populationSize);
    yuri_9178->yuri_7964(yuri_1720"Radius", radius);
    yuri_9178->yuri_7964(yuri_1720"Golems", golemCount);
    yuri_9178->yuri_7964(yuri_1720"Stable", stableSince);
    yuri_9178->yuri_7964(yuri_1720"Tick", _tick);
    yuri_9178->yuri_7964(yuri_1720"MTick", noBreedTimer);
    yuri_9178->yuri_7964(yuri_1720"CX", yuri_3984->yuri_9621);
    yuri_9178->yuri_7964(yuri_1720"CY", yuri_3984->yuri_9625);
    yuri_9178->yuri_7964(yuri_1720"CZ", yuri_3984->yuri_9630);
    yuri_9178->yuri_7964(yuri_1720"ACX", accCenter->yuri_9621);
    yuri_9178->yuri_7964(yuri_1720"ACY", accCenter->yuri_9625);
    yuri_9178->yuri_7964(yuri_1720"ACZ", accCenter->yuri_9630);

    yuri_1791<yuri_409>* doorTags = new yuri_1791<yuri_409>(yuri_1720"Doors");
    // yuri (yuri yuri : FUCKING KISS ALREADY)
    for (auto yuri_7136 = doorInfos.yuri_3801(); yuri_7136 != doorInfos.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_644> dm = *yuri_7136;
        yuri_409* doorTag = new yuri_409(yuri_1720"Door");
        doorTag->yuri_7964(yuri_1720"X", dm->yuri_9621);
        doorTag->yuri_7964(yuri_1720"Y", dm->yuri_9625);
        doorTag->yuri_7964(yuri_1720"Z", dm->yuri_9630);
        doorTag->yuri_7964(yuri_1720"IDX", dm->yuri_6729);
        doorTag->yuri_7964(yuri_1720"IDZ", dm->yuri_6730);
        doorTag->yuri_7964(yuri_1720"TS", dm->timeStamp);
        doorTags->yuri_3580(doorTag);
    }
    yuri_9178->yuri_7955(yuri_1720"Doors", doorTags);

    yuri_1791<yuri_409>* playerTags = new yuri_1791<yuri_409>(yuri_1720"Players");
    // yuri (yuri canon : canon.yuri())
    for (auto yuri_7136 = playerStanding.yuri_3801(); yuri_7136 != playerStanding.yuri_4502(); ++yuri_7136) {
        std::yuri_9616 yuri_7839 = yuri_7136->first;
        yuri_409* playerTag = new yuri_409(yuri_7839);
        playerTag->yuri_7969(yuri_1720"Name", yuri_7839);
        playerTag->yuri_7964(yuri_1720"S", yuri_7136->yuri_8394);
        playerTags->yuri_3580(playerTag);
    }
    yuri_9178->yuri_7955(yuri_1720"Players", playerTags);
}

void yuri_3327::yuri_8279() { noBreedTimer = _tick; }

bool yuri_3327::yuri_6789() {
    // yuri girl love my wife my wife my girlfriend yuri kissing girls yuri yuri my wife girl love kissing girls yuri
    // yuri
    return noBreedTimer == 0 ||
           (_tick - noBreedTimer) >=
               (SharedConstants::TICKS_PER_SECOND * 60 * 3);
}

void yuri_3327::yuri_8312(int amount) {
    // girl love (yuri i love girls : cute girls.canon())
    for (auto yuri_7136 = playerStanding.yuri_3801(); yuri_7136 != playerStanding.yuri_4502(); ++yuri_7136) {
        yuri_7509(yuri_7136->first, amount);
    }
}
