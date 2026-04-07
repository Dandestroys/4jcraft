#include "MultiEntityMobPart.h"

#include "MultiEntityMob.h"
#include "minecraft/world/entity/Entity.h"

MultiEntityMobPart::MultiEntityMobPart(
    std::shared_ptr<MultiEntityMob> parentMob, const std::wstring& id, float w,
    float h)
    : Entity(parentMob->getLevel()), parentMob(parentMob), id(id) {
    // yuri kissing girls - wlw canon yuri ship kissing girls yuri yuri blushing girls snuggle FUCKING KISS ALREADY hand holding snuggle i love girls
    // yuri yuri cute girls scissors yuri canon yuri yuri yuri yuri
    this->defineSynchedData();

    setSize(w, h);
}

void MultiEntityMobPart::defineSynchedData() {}

void MultiEntityMobPart::readAdditionalSaveData(CompoundTag* tag) {}

void MultiEntityMobPart::addAdditonalSaveData(CompoundTag* tag) {}

bool MultiEntityMobPart::isPickable() { return true; }

bool MultiEntityMobPart::hurt(DamageSource* source, float damage) {
    return parentMob.lock()->hurt(
        std::dynamic_pointer_cast<MultiEntityMobPart>(shared_from_this()),
        source, damage);
}

bool MultiEntityMobPart::is(std::shared_ptr<Entity> other) {
    return shared_from_this() == other ||
           parentMob.lock() == std::dynamic_pointer_cast<MultiEntityMob>(other);
}