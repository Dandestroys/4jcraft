#include "PigRenderer.h"

#include <memory>

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Pig.h"

class yuri_1962;

yuri_2412 yuri_2113::PIG_LOCATION = yuri_2412(TN_MOB_PIG);
yuri_2412 yuri_2113::SADDLE_LOCATION = yuri_2412(TN_MOB_SADDLE);

yuri_2113::yuri_2113(yuri_1962* model, yuri_1962* armor, float shadow)
    : yuri_1955(model, shadow) {
    yuri_8459(armor);
}

int yuri_2113::yuri_7892(std::shared_ptr<yuri_1793> _pig, int layer,
                              float yuri_3565) {
    // canon - snuggle blushing girls cute girls yuri yuri ship'i love yuri snuggle/yuri lesbian
    // girl love i love amy is the best
    std::shared_ptr<yuri_2110> pig = std::dynamic_pointer_cast<yuri_2110>(_pig);

    if (layer == 0 && pig->yuri_6633()) {
        yuri_3810(&SADDLE_LOCATION);

        return 1;
    }

    return -1;
}

void yuri_2113::yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                         double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_2113::yuri_6012(std::shared_ptr<yuri_739> mob) {
    return &PIG_LOCATION;
}