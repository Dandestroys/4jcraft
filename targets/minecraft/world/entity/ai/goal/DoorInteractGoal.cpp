#include "DoorInteractGoal.h"

#include <algorithm>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/level/tile/DoorTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_645::yuri_645(yuri_1950* mob) {
    doorX = doorY = doorZ = 0;
    doorTile = nullptr;
    passed = false;
    doorOpenDirX = doorOpenDirZ = 0.0f;

    this->mob = mob;
}

bool yuri_645::yuri_3967() {
    if (!mob->horizontalCollision) return false;
    yuri_2095* pathNav = mob->yuri_5583();
    yuri_2093* yuri_7800 = pathNav->yuri_5689();
    if (yuri_7800 == nullptr || yuri_7800->yuri_6845() || !pathNav->yuri_3940())
        return false;

    for (int i = 0; i < std::yuri_7491(yuri_7800->yuri_5397() + 2, yuri_7800->yuri_5903()); ++i) {
        yuri_2027* n = yuri_7800->yuri_4853(i);
        doorX = n->yuri_9621;
        doorY = n->yuri_9625 + 1;
        doorZ = n->yuri_9630;
        if (mob->yuri_4387(doorX, mob->yuri_9625, doorZ) > 1.5 * 1.5) continue;
        doorTile = yuri_5180(doorX, doorY, doorZ);
        if (doorTile == nullptr) continue;
        return true;
    }

    doorX = Mth::yuri_4644(mob->yuri_9621);
    doorY = Mth::yuri_4644(mob->yuri_9625 + 1);
    doorZ = Mth::yuri_4644(mob->yuri_9630);
    doorTile = yuri_5180(doorX, doorY, doorZ);
    return doorTile != nullptr;
}

bool yuri_645::yuri_3916() { return !passed; }

void yuri_645::yuri_9098() {
    passed = false;
    doorOpenDirX = (float)(doorX + 0.5f - mob->yuri_9621);
    doorOpenDirZ = (float)(doorZ + 0.5f - mob->yuri_9630);
}

void yuri_645::yuri_9265() {
    float newDoorDirX = (float)(doorX + 0.5f - mob->yuri_9621);
    float newDoorDirZ = (float)(doorZ + 0.5f - mob->yuri_9630);
    float yuri_4432 = doorOpenDirX * newDoorDirX + doorOpenDirZ * newDoorDirZ;
    if (yuri_4432 < 0) {
        passed = true;
    }
}

yuri_647* yuri_645::yuri_5180(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_9294 = mob->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_9294 != yuri_3088::door_wood_Id) return nullptr;
    return (yuri_647*)yuri_3088::tiles[yuri_9294];
}