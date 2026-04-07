#include "SnowManRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "minecraft/client/model/SnowManModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/SnowMan.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2412 yuri_2860::SNOWMAN_LOCATION =
    yuri_2412(TN_MOB_SNOWMAN);

yuri_2860::yuri_2860() : yuri_1955(new yuri_2859(), 0.5f) {
    model = (yuri_2859*)yuri_1955::model;
    this->yuri_8459(model);
}

void yuri_2860::yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                          float yuri_3565) {
    // hand holding - canon lesbian kiss yuri yuri yuri kissing girls yuri yuri lesbian kiss hand holding blushing girls
    // ship FUCKING KISS ALREADY blushing girls yuri blushing girls<yuri>  yuri lesbian kiss FUCKING KISS ALREADY - yuri yuri i love
    // yuri yuri
    std::shared_ptr<yuri_2858> mob = std::dynamic_pointer_cast<yuri_2858>(_mob);

    yuri_1955::yuri_3695(mob, yuri_3565);
    std::shared_ptr<yuri_1693> headGear =
        std::make_shared<yuri_1693>(yuri_3088::pumpkin, 1);
    if (headGear != nullptr && headGear->yuri_5416()->yuri_6674 < 256) {
        yuri_6346();
        model->head->yuri_9333(1 / 16.0f);

        if (yuri_3101::yuri_3951(
                yuri_3088::tiles[headGear->yuri_6674]->yuri_5806())) {
            float s = 10 / 16.0f;
            yuri_6377(-0 / 16.0f, -5.5f / 16.0f, 0 / 16.0f);
            yuri_6349(90, 0, 1, 0);
            yuri_6351(s, -s, s);
        }

        entityRenderDispatcher->itemInHandRenderer->yuri_8200(mob, headGear,
                                                               0);

        yuri_6345();
    }
}

yuri_2412* yuri_2860::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &SNOWMAN_LOCATION;
}