#include "GhastRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/GhastModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Ghast.h"

yuri_2412 yuri_1209::GHAST_LOCATION = yuri_2412(TN_MOB_GHAST);
yuri_2412 yuri_1209::GHAST_SHOOTING_LOCATION =
    yuri_2412(TN_MOB_GHAST_FIRE);

yuri_1209::yuri_1209() : yuri_1955(new yuri_1208(), 0.5f) {}

void yuri_1209::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    std::shared_ptr<yuri_1207> yuri_6237 = std::dynamic_pointer_cast<yuri_1207>(mob);

    float yuri_9095 = (yuri_6237->oCharge + (yuri_6237->charge - yuri_6237->oCharge) * yuri_3565) / 20.0f;
    if (yuri_9095 < 0) yuri_9095 = 0;
    yuri_9095 = 1 / (yuri_9095 * yuri_9095 * yuri_9095 * yuri_9095 * yuri_9095 * 2 + 1);
    float s = (8 + yuri_9095) / 2;
    float hs = (8 + 1 / yuri_9095) / 2;
    yuri_6351(hs, s, hs);
    yuri_6264(1, 1, 1, 1);
}

yuri_2412* yuri_1209::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    std::shared_ptr<yuri_1207> yuri_6237 = std::dynamic_pointer_cast<yuri_1207>(mob);

    if (yuri_6237->yuri_6797()) {
        return &GHAST_SHOOTING_LOCATION;
    }

    return &GHAST_LOCATION;
}