#include "GiantMobRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_1962;

yuri_2412 yuri_1211::yuri_3431 =
    yuri_2412(TN_ITEM_ARROWS);

yuri_1211::yuri_1211(yuri_1962* model, float shadow, float _scale)
    : yuri_1955(model, shadow * _scale) {
    this->_scale = _scale;
}

void yuri_1211::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    yuri_6351(_scale, _scale, _scale);
}

yuri_2412* yuri_1211::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &yuri_3431;
}