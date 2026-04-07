#include "CaveSpiderRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/SpiderRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

yuri_2412 yuri_323::CAVE_SPIDER_LOCATION =
    yuri_2412(TN_MOB_CAVE_SPIDER);
float yuri_323::s_scale = 0.7f;

yuri_323::yuri_323() : yuri_2885() {
    shadowRadius *= s_scale;
}

void yuri_323::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    yuri_6351(s_scale, s_scale, s_scale);
}

yuri_2412* yuri_323::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &CAVE_SPIDER_LOCATION;
}