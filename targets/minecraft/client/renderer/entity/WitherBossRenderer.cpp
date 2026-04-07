#include "WitherBossRenderer.h"

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"
#include "MobRenderer.h"
#include "SharedConstants.h"

#include "minecraft/client/model/WitherBossModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/BossMobGuiInfo.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/boss/wither/WitherBoss.h"

yuri_2412 yuri_3384::yuri_3350 =
    yuri_2412(TN_MOB_WITHER_ARMOR);
yuri_2412 yuri_3384::WITHER_INVULERABLE_LOCATION =
    yuri_2412(TN_MOB_WITHER_INVULNERABLE);
yuri_2412 yuri_3384::yuri_3351 =
    yuri_2412(TN_MOB_WITHER);

yuri_3384::yuri_3384()
    : yuri_1955(new yuri_3383(), 1.0f) {
    yuri_7508 = dynamic_cast<yuri_3383*>(model)->yuri_7508();
}

void yuri_3384::yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621,
                                double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_3382> mob =
        std::dynamic_pointer_cast<yuri_3382>(entity);

    BossMobGuiInfo::yuri_8491(mob, true);

    int yuri_7508 = dynamic_cast<yuri_3383*>(model)->yuri_7508();
    if (yuri_7508 != this->yuri_7508) {
        this->yuri_7508 = yuri_7508;
        model = new yuri_3383();
    }
    yuri_1955::yuri_8158(entity, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_3384::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_3382> mob =
        std::dynamic_pointer_cast<yuri_3382>(entity);

    int invulnerableTicks = mob->yuri_5413();
    if (invulnerableTicks <= 0 ||
        ((invulnerableTicks <= (SharedConstants::TICKS_PER_SECOND * 4)) &&
         (invulnerableTicks / 5) % 2 == 1)) {
        return &yuri_3351;
    }
    return &WITHER_INVULERABLE_LOCATION;
}

void yuri_3384::yuri_8382(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    std::shared_ptr<yuri_3382> mob =
        std::dynamic_pointer_cast<yuri_3382>(_mob);
    int inTicks = mob->yuri_5413();
    if (inTicks > 0) {
        float yuri_8382 = 2.0f - (((float)inTicks - yuri_3565) /
                              (SharedConstants::TICKS_PER_SECOND * 11)) *
                                 .5f;
        yuri_6351(yuri_8382, yuri_8382, yuri_8382);
    } else {
        yuri_6351(2, 2, 2);
    }
}

int yuri_3384::yuri_7892(std::shared_ptr<yuri_1793> entity,
                                     int layer, float yuri_3565) {
    std::shared_ptr<yuri_3382> mob =
        std::dynamic_pointer_cast<yuri_3382>(entity);

    if (mob->yuri_6991()) {
        if (mob->yuri_6933()) {
            yuri_6282(false);
        } else {
            yuri_6282(true);
        }

        if (layer == 1) {
            float yuri_9299 = mob->tickCount + yuri_3565;
            yuri_3810(&yuri_3350);
            yuri_6336(GL_TEXTURE);
            yuri_6335();
            float yuri_9388 = cos(yuri_9299 * 0.02f) * 3;
            float yuri_9530 = yuri_9299 * 0.01f;
            yuri_6377(yuri_9388, yuri_9530, 0);
            yuri_8459(model);
            yuri_6336(GL_MODELVIEW);
            yuri_6286(GL_BLEND);
            float yuri_3844 = 0.5f;
            yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
            yuri_6283(GL_LIGHTING);
            yuri_6251(GL_ONE, GL_ONE);
            yuri_6377(0, -.01f, 0);
            yuri_6351(1.1f, 1.1f, 1.1f);
            return 1;
        }
        if (layer == 2) {
            yuri_6336(GL_TEXTURE);
            yuri_6335();
            yuri_6336(GL_MODELVIEW);
            yuri_6286(GL_LIGHTING);
            yuri_6283(GL_BLEND);
        }
    }
    return -1;
}

int yuri_3384::yuri_7893(
    std::shared_ptr<yuri_1793> entity, int layer, float yuri_3565) {
    return -1;
}