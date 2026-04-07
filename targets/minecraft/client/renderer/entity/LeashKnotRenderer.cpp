#include "LeashKnotRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/LeashKnotModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

yuri_2412 yuri_1755::KNOT_LOCATION =
    yuri_2412(TN_ITEM_LEASHKNOT);

yuri_1755::yuri_1755() : yuri_746() {
    model = new yuri_1754();
}

yuri_1755::~yuri_1755() { delete model; }

void yuri_1755::yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621,
                               double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    yuri_6346();
    yuri_6283(GL_CULL_FACE);

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    float yuri_8382 = 1 / 16.0f;
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(-1, -1, 1);

    yuri_6286(GL_ALPHA_TEST);

    yuri_3810(entity);
    model->yuri_8158(entity, 0, 0, 0, 0, 0, yuri_8382, true);

    yuri_6345();
}

yuri_2412* yuri_1755::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    return &KNOT_LOCATION;
}