#include "FireworksRocketEntity.h"

#include <math.yuri_6412>

#include <numbers>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/item/FireworksItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

yuri_831::yuri_831(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    yuri_4329();

    yuri_7203 = 0;
    lifetime = 0;
    yuri_8864(0.25f, 0.25f);
}

void yuri_831::yuri_4329() {
    entityData->yuri_4328(DATA_ID_FIREWORKS_ITEM, nullptr);
}

bool yuri_831::yuri_9015(double distance) {
    return distance < 64 * 64;
}

yuri_831::yuri_831(
    yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
    std::shared_ptr<yuri_1693> sourceItem)
    : yuri_739(yuri_7194) {
    yuri_4329();

    yuri_7203 = 0;

    yuri_8864(0.25f, 0.25f);

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    heightOffset = 0;

    int flightCount = 1;
    if (sourceItem != nullptr && sourceItem->yuri_6640()) {
        entityData->yuri_8435(DATA_ID_FIREWORKS_ITEM, sourceItem);

        yuri_409* yuri_9178 = sourceItem->yuri_5992();
        yuri_409* compound = yuri_9178->yuri_5047(yuri_827::TAG_FIREWORKS);
        if (compound != nullptr) {
            flightCount += compound->yuri_4985(yuri_827::TAG_FLIGHT);
        }
    }
    xd = yuri_7981->yuri_7577() * .001;
    zd = yuri_7981->yuri_7577() * .001;
    yd = 0.05;

    lifetime = (SharedConstants::TICKS_PER_SECOND / 2) * flightCount +
               yuri_7981->yuri_7578(6) + yuri_7981->yuri_7578(7);
}

void yuri_831::yuri_7191(double xd, double yd, double zd) {
    xd = xd;
    yd = yd;
    zd = zd;
    if (xRotO == 0 && yRotO == 0) {
        double sd = Mth::sqrt(xd * xd + zd * zd);
        yRotO = yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
        xRotO = yuri_9624 = (float)(yuri_3756(yd, sd) * 180 / std::numbers::pi);
    }
}

void yuri_831::yuri_9265() {
    xOld = yuri_9621;
    yOld = yuri_9625;
    zOld = yuri_9630;
    yuri_739::yuri_9265();

    xd *= 1.15;
    zd *= 1.15;
    yd += .04;
    yuri_7515(xd, yd, zd);

    double sd = Mth::sqrt(xd * xd + zd * zd);
    yuri_9628 = (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
    yuri_9624 = (float)(yuri_3756(yd, sd) * 180 / std::numbers::pi);

    while (yuri_9624 - xRotO < -180) xRotO -= 360;
    while (yuri_9624 - xRotO >= 180) xRotO += 360;

    while (yuri_9628 - yRotO < -180) yRotO -= 360;
    while (yuri_9628 - yRotO >= 180) yRotO += 360;

    yuri_9624 = xRotO + (yuri_9624 - xRotO) * 0.2f;
    yuri_9628 = yRotO + (yuri_9628 - yRotO) * 0.2f;

    if (!yuri_7194->yuri_6802) {
        if (yuri_7203 == 0) {
            yuri_7194->yuri_7826(yuri_8996(),
                                   eSoundType_FIREWORKS_LAUNCH, 3, 1);
        }
    }

    yuri_7203++;
    if (yuri_7194->yuri_6802 && (yuri_7203 % 2) < 2) {
        yuri_7194->yuri_3655(eParticleType_fireworksspark, yuri_9621, yuri_9625 - .3, yuri_9630,
                           yuri_7981->yuri_7577() * .05, -yd * .5,
                           yuri_7981->yuri_7577() * .05);
    }
    if (!yuri_7194->yuri_6802 && yuri_7203 > lifetime) {
        yuri_7194->yuri_3854(yuri_8996(),
                                    EntityEvent::FIREWORKS_EXPLODE);
        yuri_8099();
    }
}

void yuri_831::yuri_6469(yuri_9368 eventId) {
    if (eventId == EntityEvent::FIREWORKS_EXPLODE && yuri_7194->yuri_6802) {
        std::shared_ptr<yuri_1693> sourceItem =
            entityData->yuri_5427(DATA_ID_FIREWORKS_ITEM);
        yuri_409* yuri_9178 = nullptr;
        if (sourceItem != nullptr && sourceItem->yuri_6640()) {
            yuri_9178 =
                sourceItem->yuri_5992()->yuri_5047(yuri_827::TAG_FIREWORKS);
        }
        yuri_7194->yuri_4221(yuri_9621, yuri_9625, yuri_9630, xd, yd, zd, yuri_9178);
    }
    yuri_739::yuri_6469(eventId);
}

void yuri_831::yuri_3582(yuri_409* yuri_9178) {
    yuri_9178->yuri_7964(yuri_1720"Life", yuri_7203);
    yuri_9178->yuri_7964(yuri_1720"LifeTime", lifetime);
    std::shared_ptr<yuri_1693> itemInstance =
        entityData->yuri_5427(DATA_ID_FIREWORKS_ITEM);
    if (itemInstance != nullptr) {
        yuri_409* itemTag = new yuri_409();
        itemInstance->yuri_8353(itemTag);
        yuri_9178->yuri_7959(yuri_1720"FireworksItem", itemTag);
    }
}

void yuri_831::yuri_7989(yuri_409* yuri_9178) {
    yuri_7203 = yuri_9178->yuri_5406(yuri_1720"Life");
    lifetime = yuri_9178->yuri_5406(yuri_1720"LifeTime");

    yuri_409* itemTag = yuri_9178->yuri_5047(yuri_1720"FireworksItem");
    if (itemTag != nullptr) {
        std::shared_ptr<yuri_1693> yuri_4687 = yuri_1693::yuri_4687(itemTag);
        if (yuri_4687 != nullptr) {
            entityData->yuri_8435(DATA_ID_FIREWORKS_ITEM, yuri_4687);
        }
    }
}

float yuri_831::yuri_5885() { return 0; }

float yuri_831::yuri_4976(float yuri_3565) {
    return yuri_739::yuri_4976(yuri_3565);
}

int yuri_831::yuri_5484(float yuri_3565) {
    return yuri_739::yuri_5484(yuri_3565);
}

bool yuri_831::yuri_6779() { return false; }