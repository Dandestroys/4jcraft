#include "RestrictSunGoal.h"

#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/level/Level.h"

yuri_2415::yuri_2415(yuri_2096* mob) { this->mob = mob; }

bool yuri_2415::yuri_3967() { return mob->yuri_7194->yuri_6834(); }

void yuri_2415::yuri_9098() { mob->yuri_5583()->yuri_8467(true); }

void yuri_2415::yuri_9133() { mob->yuri_5583()->yuri_8467(false); }