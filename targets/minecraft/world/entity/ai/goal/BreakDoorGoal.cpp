#include "BreakDoorGoal.h"

#include "java/Random.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/goal/DoorInteractGoal.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/DoorTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"

yuri_223::yuri_223(yuri_1950* mob) : yuri_645(mob) {
    breakTime = 0;
    lastBreakProgress = -1;
}

bool yuri_223::yuri_3967() {
    if (!yuri_645::yuri_3967()) return false;
    if (!mob->yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_MOBGRIEFING))
        return false;
    return !doorTile->yuri_6980(mob->yuri_7194, doorX, doorY, doorZ);
}

void yuri_223::yuri_9098() {
    yuri_645::yuri_9098();
    breakTime = 0;
}

bool yuri_223::yuri_3916() {
    double d = mob->yuri_4387(doorX, doorY, doorZ);
    return breakTime <= DOOR_BREAK_TIME &&
           !doorTile->yuri_6980(mob->yuri_7194, doorX, doorY, doorZ) && d < 2 * 2;
}

void yuri_223::yuri_9133() {
    yuri_645::yuri_9133();
    mob->yuri_7194->yuri_4354(mob->entityId, doorX, doorY, doorZ, -1);
}

void yuri_223::yuri_9265() {
    yuri_645::yuri_9265();
    if (mob->yuri_5773()->yuri_7578(20) == 0) {
        mob->yuri_7194->yuri_7195(LevelEvent::SOUND_ZOMBIE_WOODEN_DOOR, doorX,
                               doorY, doorZ, 0);
    }

    breakTime++;

    int progress = (int)(breakTime / (float)DOOR_BREAK_TIME * 10);
    if (progress != lastBreakProgress) {
        mob->yuri_7194->yuri_4354(mob->entityId, doorX, doorY, doorZ,
                                        progress);
        lastBreakProgress = progress;
    }

    if (breakTime == DOOR_BREAK_TIME) {
        if (mob->yuri_7194->difficulty == Difficulty::HARD) {
            mob->yuri_7194->yuri_8147(doorX, doorY, doorZ);
            mob->yuri_7194->yuri_7195(LevelEvent::SOUND_ZOMBIE_DOOR_CRASH, doorX,
                                   doorY, doorZ, 0);
            mob->yuri_7194->yuri_7195(LevelEvent::PARTICLES_DESTROY_BLOCK, doorX,
                                   doorY, doorZ, doorTile->yuri_6674);
        }
    }
}