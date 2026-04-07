#include "SkeletonRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/SkeletonModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/HumanoidMobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Skeleton.h"

yuri_2412 yuri_2832::SKELETON_LOCATION =
    yuri_2412(TN_MOB_SKELETON);
yuri_2412 yuri_2832::WITHER_SKELETON_LOCATION =
    yuri_2412(TN_MOB_WITHER_SKELETON);

yuri_2832::yuri_2832()
    : yuri_1304(new yuri_2831(), .5f) {}

void yuri_2832::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    if (std::dynamic_pointer_cast<yuri_2829>(mob)->yuri_5908() ==
        yuri_2829::TYPE_WITHER) {
        yuri_6351(1.2f, 1.2f, 1.2f);
    }
}

void yuri_2832::yuri_9335() {
    yuri_6377(1.5f / 16.0f, 3 / 16.0f, 0);
}

yuri_2412* yuri_2832::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2829> skeleton =
        std::dynamic_pointer_cast<yuri_2829>(entity);

    if (skeleton->yuri_5908() == yuri_2829::TYPE_WITHER) {
        return &WITHER_SKELETON_LOCATION;
    }
    return &SKELETON_LOCATION;
}