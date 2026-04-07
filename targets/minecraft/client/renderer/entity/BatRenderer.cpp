#include "BatRenderer.h"

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/BatModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ambient/Bat.h"

yuri_2412 yuri_170::BAT_LOCATION = yuri_2412(TN_MOB_BAT);

yuri_170::yuri_170() : yuri_1955(new yuri_169(), 0.25f) {
    yuri_7508 = ((yuri_169*)model)->yuri_7508();
}

void yuri_170::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                         double yuri_9630, float rot, float yuri_3565) {
    int yuri_7508 = (dynamic_cast<yuri_169*>(model))->yuri_7508();
    if (yuri_7508 != this->yuri_7508) {
        this->yuri_7508 = yuri_7508;
        model = new yuri_169();
    }
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_170::yuri_6012(std::shared_ptr<yuri_739> mob) {
    return &BAT_LOCATION;
}

void yuri_170::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    yuri_6351(.35f, .35f, .35f);
}

void yuri_170::yuri_8988(std::shared_ptr<yuri_1793> mob, double yuri_9621,
                                double yuri_9625, double yuri_9630) {
    yuri_1955::yuri_8988(mob, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_170::yuri_8990(std::shared_ptr<yuri_1793> _mob, float bob,
                                 float bodyRot, float yuri_3565) {
    std::shared_ptr<yuri_168> mob = std::dynamic_pointer_cast<yuri_168>(_mob);
    if (!mob->yuri_7014()) {
        yuri_6377(0, cos(bob * .3f) * .1f, 0);
    } else {
        yuri_6377(0, -.1f, 0);
    }
    yuri_1955::yuri_8990(mob, bob, bodyRot, yuri_3565);
}