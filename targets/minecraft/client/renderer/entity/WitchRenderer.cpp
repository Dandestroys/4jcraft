#include "WitchRenderer.h"

#include <memory>
#include <vector>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/WitchModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2412 yuri_3381::WITCH_LOCATION = yuri_2412(TN_MOB_WITCH);

yuri_3381::yuri_3381() : yuri_1955(new yuri_3380(0), 0.5f) {
    witchModel = dynamic_cast<yuri_3380*>(model);
}

void yuri_3381::yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                           double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(entity);

    std::shared_ptr<yuri_1693> item = mob->yuri_4996();

    witchModel->holdingItem = item != nullptr;
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_3381::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    return &WITCH_LOCATION;
}

void yuri_3381::yuri_3695(std::shared_ptr<yuri_1793> entity,
                                        float yuri_3565) {
    std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(entity);

    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1 : mob->yuri_4976(yuri_3565);
    yuri_6263(brightness, brightness, brightness);

    yuri_1955::yuri_3695(mob, yuri_3565);

    std::shared_ptr<yuri_1693> item = mob->yuri_4996();

    if (item != nullptr) {
        yuri_6346();

        if (model->young) {
            float s = 0.5f;
            yuri_6377(0 / 16.0f, 10 / 16.0f, 0 / 16.0f);
            yuri_6349(-20, -1, 0, 0);
            yuri_6351(s, s, s);
        }

        witchModel->nose->yuri_9333(1 / 16.0f);
        yuri_6377(-1 / 16.0f, 8.5f / 16.0f, 3.5f / 16.0f);

        if (item->yuri_6674 < 256 &&
            yuri_3101::yuri_3951(yuri_3088::tiles[item->yuri_6674]->yuri_5806())) {
            float s = 8 / 16.0f;
            yuri_6377(-0 / 16.0f, 3 / 16.0f, -5 / 16.0f);
            s *= 0.75f;
            yuri_6349(20, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
            yuri_6351(s, -s, s);
        } else if (item->yuri_6674 == yuri_1687::bow->yuri_6674) {
            float s = 10 / 16.0f;
            yuri_6377(0 / 16.0f, 2 / 16.0f, 5 / 16.0f);
            yuri_6349(-20, 0, 1, 0);
            yuri_6351(s, -s, s);
            yuri_6349(-100, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
        } else if (yuri_1687::items[item->yuri_6674]->yuri_6894()) {
            float s = 10 / 16.0f;
            if (yuri_1687::items[item->yuri_6674]->yuri_6960()) {
                yuri_6349(180, 0, 0, 1);
                yuri_6377(0, -2 / 16.0f, 0);
            }
            yuri_9335();
            yuri_6351(s, -s, s);
            yuri_6349(-100, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
        } else {
            float s = 6 / 16.0f;
            yuri_6377(+4 / 16.0f, +3 / 16.0f, -3 / 16.0f);
            yuri_6351(s, s, s);
            yuri_6349(60, 0, 0, 1);
            yuri_6349(-90, 1, 0, 0);
            yuri_6349(20, 0, 0, 1);
        }

        yuri_6349(-15, 1, 0, 0);
        yuri_6349(40, 0, 0, 1);

        entityRenderDispatcher->itemInHandRenderer->yuri_8200(mob, item, 0);
        if (item->yuri_5416()->yuri_6616()) {
            entityRenderDispatcher->itemInHandRenderer->yuri_8200(mob, item,
                                                                   1);
        }
        yuri_6345();
    }
}

void yuri_3381::yuri_9335() { yuri_6377(0, 3 / 16.0f, 0); }

void yuri_3381::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    float s = 15 / 16.0f;
    yuri_6351(s, s, s);
}