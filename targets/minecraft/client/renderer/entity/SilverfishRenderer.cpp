#include "SilverfishRenderer.h"

#include <memory>

#include "minecraft/client/model/SilverfishModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

yuri_2412 yuri_2822::yuri_2491(TN_MOB_SILVERFISH);

yuri_2822::yuri_2822()
    : yuri_1955(new yuri_2821(), 0.3f) {}

float yuri_2822::yuri_5258(std::shared_ptr<yuri_1793> spider) {
    return 180;
}

void yuri_2822::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621,
                                double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_2822::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &yuri_2491;
}

int yuri_2822::yuri_7892(std::shared_ptr<yuri_1793> _silverfish,
                                     int layer, float yuri_3565) {
    return -1;
}