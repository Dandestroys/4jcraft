#include "LavaSlimeRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/LavaSlimeModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/LavaSlime.h"

yuri_2412 yuri_1741::MAGMACUBE_LOCATION =
    yuri_2412(TN_MOB_LAVA);

yuri_1741::yuri_1741()
    : yuri_1955(new yuri_1740(), .25f) {
    this->yuri_7508 = ((yuri_1740*)model)->yuri_5562();
}

yuri_2412* yuri_1741::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &MAGMACUBE_LOCATION;
}

void yuri_1741::yuri_8382(std::shared_ptr<yuri_1793> _slime, float yuri_3565) {
    // yuri - lesbian kiss yuri yuri hand holding blushing girls i love girl love yuri hand holding FUCKING KISS ALREADY snuggle
    // snuggle blushing girls yuri my girlfriend yuri<yuri>  kissing girls lesbian kiss lesbian kiss - yuri yuri
    // yuri lesbian kissing girls
    std::shared_ptr<yuri_1739> slime =
        std::dynamic_pointer_cast<yuri_1739>(_slime);
    int yuri_9050 = slime->yuri_5903();
    float yuri_9095 = (slime->oSquish + (slime->squish - slime->oSquish) * yuri_3565) /
               (yuri_9050 * 0.5f + 1);
    float yuri_9535 = 1 / (yuri_9095 + 1);
    float s = yuri_9050;
    yuri_6351(yuri_9535 * s, 1 / yuri_9535 * s, yuri_9535 * s);
}