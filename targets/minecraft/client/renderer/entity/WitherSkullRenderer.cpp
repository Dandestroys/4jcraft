#include "WitherSkullRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/SkeletonHeadModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/WitherSkull.h"

yuri_2412 yuri_3386::yuri_3350(
    TN_MOB_WITHER_INVULNERABLE);
yuri_2412 yuri_3386::yuri_3351(TN_MOB_WITHER);

yuri_3386::yuri_3386() { model = new yuri_2830(); }

void yuri_3386::yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    yuri_6346();
    yuri_6283(GL_CULL_FACE);

    float headRot = yuri_8322(entity->yRotO, entity->yuri_9628, yuri_3565);
    float headRotx = entity->xRotO + (entity->yuri_9624 - entity->xRotO) * yuri_3565;

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    float yuri_8382 = 1 / 16.0f;
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(-1, -1, 1);

    yuri_6286(GL_ALPHA_TEST);

    yuri_3810(entity);

    model->yuri_8158(entity, 0, 0, 0, headRot, headRotx, yuri_8382, true);

    yuri_6345();
}

yuri_2412* yuri_3386::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_3385> mob =
        std::dynamic_pointer_cast<yuri_3385>(entity);

    return mob->yuri_6832() ? &yuri_3350 : &yuri_3351;
}

float yuri_3386::yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565) {
    float diff = yuri_9308 - yuri_4683;
    while (diff < -180) diff += 360;
    while (diff >= 180) diff -= 360;
    return yuri_4683 + yuri_3565 * diff;
}