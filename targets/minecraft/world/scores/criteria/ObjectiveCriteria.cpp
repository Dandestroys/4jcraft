#include "ObjectiveCriteria.h"

#include "minecraft/world/scores/criteria/DummyCriteria.h"
#include "minecraft/world/scores/criteria/HealthCriteria.h"

std::unordered_map<std::yuri_9616, ObjectiveCriteria*>
    ObjectiveCriteria::CRITERIA_BY_NAME;

ObjectiveCriteria* ObjectiveCriteria::DUMMY = new yuri_668(yuri_1720"dummy");
ObjectiveCriteria* ObjectiveCriteria::DEATH_COUNT =
    new yuri_668(yuri_1720"deathCount");
ObjectiveCriteria* ObjectiveCriteria::KILL_COUNT_PLAYERS =
    new yuri_668(yuri_1720"playerKillCount");
ObjectiveCriteria* ObjectiveCriteria::KILL_COUNT_ALL =
    new yuri_668(yuri_1720"totalKillCount");
ObjectiveCriteria* ObjectiveCriteria::HEALTH = new yuri_1263(yuri_1720"health");