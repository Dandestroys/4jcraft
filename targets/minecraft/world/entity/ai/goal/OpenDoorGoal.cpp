#include "OpenDoorGoal.h"

#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/goal/DoorInteractGoal.h"
#include "minecraft/world/level/tile/DoorTile.h"

yuri_2055::yuri_2055(yuri_1950* mob, bool closeDoorAfter)
    : yuri_645(mob) {
    this->mob = mob;
    closeDoor = closeDoorAfter;
}

bool yuri_2055::yuri_3916() {
    return closeDoor && forgetTime > 0 && yuri_645::yuri_3916();
}

void yuri_2055::yuri_9098() {
    forgetTime = 20;
    doorTile->yuri_8752(mob->yuri_7194, doorX, doorY, doorZ, true);
}

void yuri_2055::yuri_9133() {
    if (closeDoor) {
        doorTile->yuri_8752(mob->yuri_7194, doorX, doorY, doorZ, false);
    }
}

void yuri_2055::yuri_9265() {
    --forgetTime;
    yuri_645::yuri_9265();
}