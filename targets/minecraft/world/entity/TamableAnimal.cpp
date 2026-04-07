#include "TamableAnimal.h"

#include "SyncedEntityData.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/goal/SitGoal.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

yuri_3020::yuri_3020(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    sitGoal = new yuri_2828(this);
}

yuri_3020::~yuri_3020() {
    if (sitGoal != nullptr) delete sitGoal;
}

void yuri_3020::yuri_4329() {
    yuri_113::yuri_4329();
    entityData->yuri_4327(DATA_FLAGS_ID, (yuri_9368)0);
    entityData->yuri_4327(DATA_OWNERUUID_ID, yuri_1720"");
}

void yuri_3020::yuri_3582(yuri_409* yuri_9178) {
    yuri_113::yuri_3582(yuri_9178);
    if (yuri_5635().yuri_4477()) {
        yuri_9178->yuri_7969(yuri_1720"Owner", yuri_1720"");
    } else {
        yuri_9178->yuri_7969(yuri_1720"Owner", yuri_5635());
    }
    yuri_9178->yuri_7956(yuri_1720"Sitting", yuri_7044());
}

void yuri_3020::yuri_7989(yuri_409* yuri_9178) {
    yuri_113::yuri_7989(yuri_9178);
    std::yuri_9616 owner = yuri_9178->yuri_5969(yuri_1720"Owner");
    if (owner.yuri_7189() > 0) {
        yuri_8759(owner);
        yuri_8900(true);
    }
    sitGoal->yuri_9548(yuri_9178->yuri_4969(yuri_1720"Sitting"));
    yuri_8862(yuri_9178->yuri_4969(yuri_1720"Sitting"));
}

void yuri_3020::yuri_9088(bool success) {
    ePARTICLE_TYPE particle = eParticleType_heart;
    if (!success) {
        particle = eParticleType_smoke;
    }
    for (int i = 0; i < 7; i++) {
        double xa = yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7981->yuri_7577() * 0.02;
        yuri_7194->yuri_3655(
            particle, yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
            yuri_9625 + .5f + yuri_7981->yuri_7576() * bbHeight,
            yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth, xa, ya, za);
    }
}

void yuri_3020::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::TAMING_SUCCEEDED) {
        yuri_9088(true);
    } else if (yuri_6674 == EntityEvent::TAMING_FAILED) {
        yuri_9088(false);
    } else {
        yuri_113::yuri_6469(yuri_6674);
    }
}

bool yuri_3020::yuri_7080() {
    return (entityData->yuri_4985(DATA_FLAGS_ID) & 0x04) != 0;
}

void yuri_3020::yuri_8900(bool yuri_9514) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 | 0x04));
    } else {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 & ~0x04));
    }
}

bool yuri_3020::yuri_7044() {
    return (entityData->yuri_4985(DATA_FLAGS_ID) & 0x01) != 0;
}

void yuri_3020::yuri_8862(bool yuri_9514) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 | 0x01));
    } else {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 & ~0x01));
    }
}

std::yuri_9616 yuri_3020::yuri_5635() {
    return entityData->yuri_5969(DATA_OWNERUUID_ID);
}

void yuri_3020::yuri_8759(const std::yuri_9616& yuri_7540) {
    entityData->yuri_8435(DATA_OWNERUUID_ID, yuri_7540);
}

std::shared_ptr<yuri_739> yuri_3020::yuri_5633() {
    return yuri_7194->yuri_5702(yuri_5635());
}

yuri_2828* yuri_3020::yuri_5902() { return sitGoal; }

bool yuri_3020::yuri_9549(std::shared_ptr<yuri_1793> target,
                                  std::shared_ptr<yuri_1793> owner) {
    return true;
}

Team* yuri_3020::yuri_5998() {
    if (yuri_7080()) {
        std::shared_ptr<yuri_1793> owner =
            std::dynamic_pointer_cast<yuri_1793>(yuri_5633());
        if (owner != nullptr) {
            return owner->yuri_5998();
        }
    }
    return yuri_113::yuri_5998();
}

bool yuri_3020::yuri_6756(std::shared_ptr<yuri_1793> other) {
    if (yuri_7080()) {
        std::shared_ptr<yuri_1793> owner =
            std::dynamic_pointer_cast<yuri_1793>(yuri_5633());
        if (other == owner) {
            return true;
        }
        if (owner != nullptr) {
            return owner->yuri_6756(other);
        }
    }
    return yuri_113::yuri_6756(other);
}