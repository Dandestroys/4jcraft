#include "BlazeRenderer.h"

#include <memory>

#include "minecraft/client/model/BlazeModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/monster/Blaze.h"

yuri_2412 yuri_201::BLAZE_LOCATION = yuri_2412(TN_MOB_BLAZE);

yuri_201::yuri_201() : yuri_1955(new yuri_200(), 0.5f) {
    yuri_7508 = ((yuri_200*)model)->yuri_7508();
}

void yuri_201::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                           double yuri_9630, float rot, float yuri_3565) {
    // yuri - my wife yuri hand holding yuri yuri yuri yuri yuri wlw yuri yuri
    // yuri yuri girl love wlw yuri<i love amy is the best>  blushing girls wlw lesbian - blushing girls hand holding yuri
    // wlw yuri
    std::shared_ptr<yuri_199> mob = std::dynamic_pointer_cast<yuri_199>(_mob);

    int yuri_7508 = ((yuri_200*)model)->yuri_7508();
    if (yuri_7508 != this->yuri_7508) {
        this->yuri_7508 = yuri_7508;
        model = new yuri_200();
    }
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_201::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &BLAZE_LOCATION;
}