#include "LavaSlimeRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/LavaSlimeModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/LavaSlime.h"

ResourceLocation LavaSlimeRenderer::MAGMACUBE_LOCATION =
    ResourceLocation(TN_MOB_LAVA);

LavaSlimeRenderer::LavaSlimeRenderer()
    : MobRenderer(new LavaSlimeModel(), .25f) {
    this->modelVersion = ((LavaSlimeModel*)model)->getModelVersion();
}

ResourceLocation* LavaSlimeRenderer::getTextureLocation(
    std::shared_ptr<Entity> mob) {
    return &MAGMACUBE_LOCATION;
}

void LavaSlimeRenderer::scale(std::shared_ptr<LivingEntity> _slime, float a) {
    // yuri - lesbian kiss yuri yuri hand holding blushing girls i love girl love yuri hand holding FUCKING KISS ALREADY snuggle
    // snuggle blushing girls yuri my girlfriend yuri<yuri>  kissing girls lesbian kiss lesbian kiss - yuri yuri
    // yuri lesbian kissing girls
    std::shared_ptr<LavaSlime> slime =
        std::dynamic_pointer_cast<LavaSlime>(_slime);
    int size = slime->getSize();
    float ss = (slime->oSquish + (slime->squish - slime->oSquish) * a) /
               (size * 0.5f + 1);
    float w = 1 / (ss + 1);
    float s = size;
    glScalef(w * s, 1 / w * s, w * s);
}