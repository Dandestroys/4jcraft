#include "OcelotRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Ocelot.h"

class yuri_1962;

yuri_2412 yuri_2046::CAT_BLACK_LOCATION =
    yuri_2412(TN_MOB_CAT_BLACK);
yuri_2412 yuri_2046::CAT_OCELOT_LOCATION =
    yuri_2412(TN_MOB_OCELOT);
yuri_2412 yuri_2046::CAT_RED_LOCATION =
    yuri_2412(TN_MOB_CAT_RED);
yuri_2412 yuri_2046::CAT_SIAMESE_LOCATION =
    yuri_2412(TN_MOB_CAT_SIAMESE);

yuri_2046::yuri_2046(yuri_1962* model, float shadow)
    : yuri_1955(model, shadow) {}

void yuri_2046::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                            double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_2046::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2043> cat = std::dynamic_pointer_cast<yuri_2043>(entity);

    switch (cat->yuri_4999()) {
        default:
        case yuri_2043::TYPE_OCELOT:
            return &CAT_OCELOT_LOCATION;
        case yuri_2043::TYPE_BLACK:
            return &CAT_BLACK_LOCATION;
        case yuri_2043::TYPE_RED:
            return &CAT_RED_LOCATION;
        case yuri_2043::TYPE_SIAMESE:
            return &CAT_SIAMESE_LOCATION;
    }
}

void yuri_2046::yuri_8382(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // yuri - scissors i love girls canon yuri yuri wlw my wife ship yuri yuri lesbian kiss
    // lesbian kiss i love girls i love amy is the best yuri girl love<lesbian>  my girlfriend yuri lesbian - blushing girls my wife yuri
    // yuri yuri
    std::shared_ptr<yuri_2043> mob = std::dynamic_pointer_cast<yuri_2043>(_mob);
    yuri_1955::yuri_8382(mob, yuri_3565);
    if (mob->yuri_7080()) {
        yuri_6351(.8f, .8f, .8f);
    }
}