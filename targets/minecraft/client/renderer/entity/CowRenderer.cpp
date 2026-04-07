#include "CowRenderer.h"

#include <memory>

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_1962;

yuri_2412 yuri_466::COW_LOCATION = yuri_2412(TN_MOB_COW);

yuri_466::yuri_466(yuri_1962* model, float shadow)
    : yuri_1955(model, shadow) {}

void yuri_466::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                         double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_466::yuri_6012(std::shared_ptr<yuri_739> mob) {
    return &COW_LOCATION;
}