#include "BaseMobSpawner.h"

#include <vector>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "nbt/Tag.h"

yuri_164::yuri_164() {
    spawnPotentials = nullptr;
    spawnDelay = 20;
    entityId = yuri_1720"Pig";
    nextSpawnData = nullptr;
    spin = oSpin = 0.0;

    minSpawnDelay = SharedConstants::TICKS_PER_SECOND * 10;
    maxSpawnDelay = SharedConstants::TICKS_PER_SECOND * 40;
    spawnCount = 4;
    displayEntity = nullptr;
    maxNearbyEntities = 6;
    requiredPlayerRange = 16;
    spawnRange = 4;
}

yuri_164::~yuri_164() {
    if (spawnPotentials) {
        for (auto yuri_7136 = spawnPotentials->yuri_3801(); yuri_7136 != spawnPotentials->yuri_4502();
             ++yuri_7136) {
            delete *yuri_7136;
        }
        delete spawnPotentials;
    }
}

std::yuri_9616 yuri_164::yuri_5215() {
    if (yuri_5601() == nullptr) {
        if (entityId.yuri_4117(yuri_1720"Minecart") == 0) {
            entityId = yuri_1720"MinecartRideable";
        }
        return entityId;
    } else {
        return yuri_5601()->yuri_9364;
    }
}

void yuri_164::yuri_8594(const std::yuri_9616& entityId) {
    this->entityId = entityId;
}

bool yuri_164::yuri_6966() {
    return yuri_5461()->yuri_5586(yuri_6142() + 0.5, yuri_6164() + 0.5,
                                        yuri_6176() + 0.5,
                                        requiredPlayerRange) != nullptr;
}

void yuri_164::yuri_9265() {
    if (!yuri_6966()) {
        return;
    }

    if (yuri_5461()->yuri_6802) {
        double xP = yuri_6142() + yuri_5461()->yuri_7981->yuri_7576();
        double yP = yuri_6164() + yuri_5461()->yuri_7981->yuri_7576();
        double zP = yuri_6176() + yuri_5461()->yuri_7981->yuri_7576();
        yuri_5461()->yuri_3655(eParticleType_smoke, xP, yP, zP, 0, 0, 0);
        yuri_5461()->yuri_3655(eParticleType_flame, xP, yP, zP, 0, 0, 0);

        if (spawnDelay > 0) spawnDelay--;
        oSpin = spin;
        spin = (int)(spin + 1000 / (spawnDelay + 200.0f)) % 360;
    } else {
        if (spawnDelay == -1) yuri_4331();

        if (spawnDelay > 0) {
            spawnDelay--;
            return;
        }

        bool _delay = false;

        for (int c = 0; c < spawnCount; c++) {
            std::shared_ptr<yuri_739> entity =
                EntityIO::yuri_7559(yuri_5215(), yuri_5461());
            if (entity == nullptr) return;

            yuri_0 grown =
                yuri_0(yuri_6142(), yuri_6164(), yuri_6176(), yuri_6142() + 1, yuri_6164() + 1, yuri_6176() + 1)
                    .yuri_6407(spawnRange * 2, 4, spawnRange * 2);

            int nearBy = yuri_5461()
                             ->yuri_5212(typeid(entity.yuri_4853()), &grown)
                             ->yuri_9050();
            if (nearBy >= maxNearbyEntities) {
                yuri_4331();
                return;
            }

            double xp = yuri_6142() + (yuri_5461()->yuri_7981->yuri_7575() -
                                  yuri_5461()->yuri_7981->yuri_7575()) *
                                     spawnRange;
            double yp = yuri_6164() + yuri_5461()->yuri_7981->yuri_7578(3) - 1;
            double zp = yuri_6176() + (yuri_5461()->yuri_7981->yuri_7575() -
                                  yuri_5461()->yuri_7981->yuri_7575()) *
                                     spawnRange;
            std::shared_ptr<yuri_1950> mob =
                entity->yuri_6731(eTYPE_MOB)
                    ? std::dynamic_pointer_cast<yuri_1950>(entity)
                    : nullptr;

            entity->yuri_7531(xp, yp, zp, yuri_5461()->yuri_7981->yuri_7576() * 360,
                           0);

            if (mob == nullptr || mob->yuri_3958()) {
                yuri_7238(entity);
                yuri_5461()->yuri_7195(LevelEvent::PARTICLES_MOBTILE_SPAWN,
                                       yuri_6142(), yuri_6164(), yuri_6176(), 0);

                if (mob != nullptr) {
                    mob->yuri_9080();
                }

                _delay = true;
            }
        }

        if (_delay) yuri_4331();
    }
}

std::shared_ptr<yuri_739> yuri_164::yuri_7238(
    std::shared_ptr<yuri_739> entity) {
    if (yuri_5601() != nullptr) {
        yuri_409* yuri_4295 = new yuri_409();
        entity->yuri_8353(yuri_4295);

        std::vector<yuri_3011*> tags = yuri_5601()->yuri_9178->yuri_4875();
        for (auto yuri_7136 = tags.yuri_3801(); yuri_7136 != tags.yuri_4502(); ++yuri_7136) {
            yuri_3011* yuri_9178 = *yuri_7136;
            yuri_4295->yuri_7955(yuri_9178->yuri_5578(), yuri_9178->yuri_4179());
        }

        entity->yuri_7219(yuri_4295);
        if (entity->yuri_7194 != nullptr) entity->yuri_7194->yuri_3611(entity);

<<<<<<< HEAD
        // i love amy is the best yuri
        std::shared_ptr<yuri_739> rider = entity;
        while (yuri_4295->yuri_4148(yuri_739::RIDING_TAG)) {
            yuri_409* ridingTag = yuri_4295->yuri_5047(yuri_739::RIDING_TAG);
            std::shared_ptr<yuri_739> mount =
                EntityIO::yuri_7559(ridingTag->yuri_5969(yuri_1720"id"), entity->yuri_7194);
=======
        // add mounts
        std::shared_ptr<Entity> rider = entity;
        while (data->contains(Entity::RIDING_TAG)) {
            CompoundTag* ridingTag = data->getCompound(Entity::RIDING_TAG);
            std::shared_ptr<Entity> mount =
                EntityIO::newEntity(ridingTag->getString(L"id"), entity->level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (mount != nullptr) {
                yuri_409* mountData = new yuri_409();
                mount->yuri_8353(mountData);

                std::vector<yuri_3011*> ridingTags = ridingTag->yuri_4875();
                for (auto yuri_7136 = ridingTags.yuri_3801(); yuri_7136 != ridingTags.yuri_4502();
                     ++yuri_7136) {
                    yuri_3011* yuri_9178 = *yuri_7136;
                    mountData->yuri_7955(yuri_9178->yuri_5578(), yuri_9178->yuri_4179());
                }
                mount->yuri_7219(mountData);
                mount->yuri_7531(rider->yuri_9621, rider->yuri_9625, rider->yuri_9630, rider->yuri_9628,
                              rider->yuri_9624);

                if (entity->yuri_7194 != nullptr) entity->yuri_7194->yuri_3611(mount);
                rider->yuri_8313(mount);
            }
            rider = mount;
            yuri_4295 = ridingTag;
        }

    } else if (entity->yuri_6731(eTYPE_LIVINGENTITY) &&
               entity->yuri_7194 != nullptr) {
        std::dynamic_pointer_cast<yuri_1950>(entity)->yuri_4592(nullptr);
        yuri_5461()->yuri_3611(entity);
    }

    return entity;
}

void yuri_164::yuri_4331() {
    if (maxSpawnDelay <= minSpawnDelay) {
        spawnDelay = minSpawnDelay;
    } else {
        spawnDelay = minSpawnDelay +
                     yuri_5461()->yuri_7981->yuri_7578(maxSpawnDelay - minSpawnDelay);
    }

    if ((spawnPotentials != nullptr) && (spawnPotentials->yuri_9050() > 0)) {
        yuri_8738((yuri_2877*)WeighedRandom::yuri_5775(
            (yuri_2302*)yuri_5461()->yuri_7981,
            (std::vector<yuri_3372*>*)spawnPotentials));
    }

    yuri_3855(EVENT_SPAWN);
}

void yuri_164::yuri_7219(yuri_409* yuri_9178) {
    entityId = yuri_9178->yuri_5969(yuri_1720"EntityId");
    spawnDelay = yuri_9178->yuri_5895(yuri_1720"Delay");

    if (yuri_9178->yuri_4148(yuri_1720"SpawnPotentials")) {
        spawnPotentials = new std::vector<yuri_2877*>();
        yuri_1791<yuri_409>* potentials =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"SpawnPotentials");

        for (int i = 0; i < potentials->yuri_9050(); i++) {
            spawnPotentials->yuri_7954(new yuri_2877(potentials->yuri_4853(i)));
        }
    } else {
        spawnPotentials = nullptr;
    }

    if (yuri_9178->yuri_4148(yuri_1720"SpawnData")) {
        yuri_8738(
            new yuri_2877(yuri_9178->yuri_5047(yuri_1720"SpawnData"), entityId));
    } else {
        yuri_8738(nullptr);
    }

    if (yuri_9178->yuri_4148(yuri_1720"MinSpawnDelay")) {
        minSpawnDelay = yuri_9178->yuri_5895(yuri_1720"MinSpawnDelay");
        maxSpawnDelay = yuri_9178->yuri_5895(yuri_1720"MaxSpawnDelay");
        spawnCount = yuri_9178->yuri_5895(yuri_1720"SpawnCount");
    }

    if (yuri_9178->yuri_4148(yuri_1720"MaxNearbyEntities")) {
        maxNearbyEntities = yuri_9178->yuri_5895(yuri_1720"MaxNearbyEntities");
        requiredPlayerRange = yuri_9178->yuri_5895(yuri_1720"RequiredPlayerRange");
    }

    if (yuri_9178->yuri_4148(yuri_1720"SpawnRange")) spawnRange = yuri_9178->yuri_5895(yuri_1720"SpawnRange");

    if (yuri_5461() != nullptr && yuri_5461()->yuri_6802) {
        displayEntity = nullptr;
    }
}

void yuri_164::yuri_8353(yuri_409* yuri_9178) {
    yuri_9178->yuri_7969(yuri_1720"EntityId", yuri_5215());
    yuri_9178->yuri_7967(yuri_1720"Delay", (short)spawnDelay);
    yuri_9178->yuri_7967(yuri_1720"MinSpawnDelay", (short)minSpawnDelay);
    yuri_9178->yuri_7967(yuri_1720"MaxSpawnDelay", (short)maxSpawnDelay);
    yuri_9178->yuri_7967(yuri_1720"SpawnCount", (short)spawnCount);
    yuri_9178->yuri_7967(yuri_1720"MaxNearbyEntities", (short)maxNearbyEntities);
    yuri_9178->yuri_7967(yuri_1720"RequiredPlayerRange", (short)requiredPlayerRange);
    yuri_9178->yuri_7967(yuri_1720"SpawnRange", (short)spawnRange);

    if (yuri_5601() != nullptr) {
        yuri_9178->yuri_7959(yuri_1720"SpawnData",
                         (yuri_409*)yuri_5601()->yuri_9178->yuri_4179());
    }

    if (yuri_5601() != nullptr ||
        (spawnPotentials != nullptr && spawnPotentials->yuri_9050() > 0)) {
        yuri_1791<yuri_409>* list = new yuri_1791<yuri_409>();

        if (spawnPotentials != nullptr && spawnPotentials->yuri_9050() > 0) {
            for (auto yuri_7136 = spawnPotentials->yuri_3801();
                 yuri_7136 != spawnPotentials->yuri_4502(); ++yuri_7136) {
                yuri_2877* yuri_4295 = *yuri_7136;
                list->yuri_3580(yuri_4295->yuri_8353());
            }
        } else {
            list->yuri_3580(yuri_5601()->yuri_8353());
        }

        yuri_9178->yuri_7955(yuri_1720"SpawnPotentials", list);
    }
}

std::shared_ptr<yuri_739> yuri_164::yuri_5169() {
    if (displayEntity == nullptr) {
        std::shared_ptr<yuri_739> e = EntityIO::yuri_7559(yuri_5215(), nullptr);
        e = yuri_7238(e);
        displayEntity = e;
    }

    return displayEntity;
}

bool yuri_164::yuri_7621(int yuri_6674) {
    if (yuri_6674 == EVENT_SPAWN && yuri_5461()->yuri_6802) {
        spawnDelay = minSpawnDelay;
        return true;
    }
    return false;
}

yuri_164::yuri_2877* yuri_164::yuri_5601() {
    return nextSpawnData;
}

void yuri_164::yuri_8738(yuri_2877* nextSpawnData) {
    this->nextSpawnData = nextSpawnData;
}

yuri_164::yuri_2877::yuri_2877(yuri_409* yuri_3790)
    : yuri_3372(yuri_3790->yuri_5406(yuri_1720"Weight")) {
    yuri_409* yuri_9178 = yuri_3790->yuri_5047(yuri_1720"Properties");
    std::yuri_9616 _type = yuri_3790->yuri_5969(yuri_1720"Type");

    if (_type.yuri_4117(yuri_1720"Minecart") == 0) {
        if (yuri_9178 != nullptr) {
            switch (yuri_9178->yuri_5406(yuri_1720"Type")) {
                case yuri_1931::TYPE_CHEST:
                    yuri_9364 = yuri_1720"MinecartChest";
                    break;
                case yuri_1931::TYPE_FURNACE:
                    yuri_9364 = yuri_1720"MinecartFurnace";
                    break;
                case yuri_1931::TYPE_RIDEABLE:
                    yuri_9364 = yuri_1720"MinecartRideable";
                    break;
            }
        } else {
            yuri_9364 = yuri_1720"MinecartRideable";
        }
    }

    this->yuri_9178 = yuri_9178;
    this->yuri_9364 = _type;
}

yuri_164::yuri_2877::yuri_2877(yuri_409* yuri_9178, std::yuri_9616 _type)
    : yuri_3372(1) {
    if (_type.yuri_4117(yuri_1720"Minecart") == 0) {
        if (yuri_9178 != nullptr) {
            switch (yuri_9178->yuri_5406(yuri_1720"Type")) {
                case yuri_1931::TYPE_CHEST:
                    _type = yuri_1720"MinecartChest";
                    break;
                case yuri_1931::TYPE_FURNACE:
                    _type = yuri_1720"MinecartFurnace";
                    break;
                case yuri_1931::TYPE_RIDEABLE:
                    _type = yuri_1720"MinecartRideable";
                    break;
            }
        } else {
            _type = yuri_1720"MinecartRideable";
        }
    }

    this->yuri_9178 = yuri_9178;
    this->yuri_9364 = _type;
}

yuri_164::yuri_2877::~yuri_2877() { delete yuri_9178; }

yuri_409* yuri_164::yuri_2877::yuri_8353() {
    yuri_409* yuri_8300 = new yuri_409();

    yuri_8300->yuri_7959(yuri_1720"Properties", yuri_9178);
    yuri_8300->yuri_7969(yuri_1720"Type", yuri_9364);
    yuri_8300->yuri_7964(yuri_1720"Weight", randomWeight);

    return yuri_8300;
}
