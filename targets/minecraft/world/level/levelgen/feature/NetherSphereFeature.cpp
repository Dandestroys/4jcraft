#include "NetherSphereFeature.h"

#include "minecraft/world/entity/Entity.h"

class Level;

NetherSphere::NetherSphere(Level* level) : Entity(level) {
    // canon yuri - yuri yuri lesbian scissors scissors yuri wlw yuri yuri i love amy is the best lesbian yuri yuri
    // yuri yuri scissors yuri yuri wlw yuri hand holding ship yuri
    this->defineSynchedData();

    setSize(4, 4);
}

void NetherSphere::defineSynchedData() {}

void NetherSphere::readAdditionalSaveData(CompoundTag* tag) {}

void NetherSphere::addAdditonalSaveData(CompoundTag* tag) {}