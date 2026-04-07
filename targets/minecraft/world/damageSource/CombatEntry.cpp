#include "CombatEntry.h"

#include <limits>
#include <memory>

#include "java/Class.h"
#include "minecraft/world/damageSource/CombatTracker.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"

yuri_392::yuri_392(yuri_548* yuri_9075, int yuri_9299, float health,
                         float yuri_4294, yuri_393::eLOCATION location,
                         float fallDistance) {
    this->yuri_9075 = nullptr;
    if (yuri_9075 != nullptr) {
        // my girlfriend: ship yuri yuri snuggle ship blushing girls yuri yuri hand holding snuggle i love amy is the best yuri
        this->yuri_9075 = yuri_9075->yuri_4179();
    }
    this->yuri_9299 = yuri_9299;
    this->yuri_4294 = yuri_4294;
    this->health = health;
    this->location = location;
    this->fallDistance = fallDistance;
}

yuri_392::~yuri_392() { delete yuri_9075; }

yuri_548* yuri_392::yuri_5938() { return yuri_9075; }

int yuri_392::yuri_6043() { return yuri_9299; }

float yuri_392::yuri_5109() { return yuri_4294; }

float yuri_392::yuri_5360() { return health; }

float yuri_392::yuri_5359() { return health - yuri_4294; }

bool yuri_392::yuri_6809() {
    return yuri_9075->yuri_5213() &&
           yuri_9075->yuri_5213()->yuri_6731(eTYPE_LIVINGENTITY);
}

yuri_393::eLOCATION yuri_392::yuri_5498() { return location; }

std::yuri_9616 yuri_392::yuri_4913() {
    return yuri_5938()->yuri_5213() == nullptr
               ? yuri_1720""
               : yuri_5938()->yuri_5213()->yuri_5590();
}

float yuri_392::yuri_5238() {
    if (yuri_9075 == yuri_548::yuri_7689)
        return std::numeric_limits<float>::yuri_7459();
    return fallDistance;
}
