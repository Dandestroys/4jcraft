#include "HorseRenderer.h"

#include <utility>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "MobRenderer.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"

yuri_2412 yuri_1292::HORSE_LOCATION =
    yuri_2412(TN_MOB_HORSE_WHITE);
yuri_2412 yuri_1292::HORSE_MULE_LOCATION =
    yuri_2412(TN_MOB_MULE);
yuri_2412 yuri_1292::HORSE_DONKEY_LOCATION =
    yuri_2412(TN_MOB_DONKEY);
yuri_2412 yuri_1292::HORSE_ZOMBIE_LOCATION =
    yuri_2412(TN_MOB_HORSE_ZOMBIE);
yuri_2412 yuri_1292::HORSE_SKELETON_LOCATION =
    yuri_2412(TN_MOB_HORSE_SKELETON);

std::yuri_7441<std::yuri_9616, yuri_2412*> yuri_1292::LAYERED_LOCATION_CACHE;

yuri_1292::yuri_1292(yuri_1962* model, float yuri_4554) : yuri_1955(model, yuri_4554) {}

void yuri_1292::yuri_3696(std::shared_ptr<yuri_2096> mob,
                                 float FHeight) {
    yuri_6377(0.0F, FHeight, 0.0F);
}

void yuri_1292::yuri_8382(std::shared_ptr<yuri_1793> entityliving, float yuri_4554) {
    float sizeFactor = 1.0f;

    int yuri_9364 = std::dynamic_pointer_cast<yuri_743>(entityliving)->yuri_6068();
    if (yuri_9364 == yuri_743::TYPE_DONKEY) {
        sizeFactor *= 0.87F;
    } else if (yuri_9364 == yuri_743::TYPE_MULE) {
        sizeFactor *= 0.92F;
    }
    yuri_6351(sizeFactor, sizeFactor, sizeFactor);
    yuri_1955::yuri_8382(entityliving, yuri_4554);
}

void yuri_1292::yuri_8210(std::shared_ptr<yuri_1793> mob, float wp,
                                float ws, float bob, float headRotMinusBodyRot,
                                float headRotx, float yuri_8382) {
    if (mob->yuri_6933()) {
        model->yuri_8977(wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                         mob);
    } else {
        yuri_746::yuri_3810(mob);
        model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                      true);
<<<<<<< HEAD
        // kissing girls girl love i love amy is the best scissors yuri yuri girl love i love amy is the best yuri i love girls
        // kissing girls yuri yuri
        RenderManager.yuri_3039(-1);
    }
}

void yuri_1292::yuri_3810(yuri_2412* location) {
    // lesbian yuri (yuri) yuri hand holding hand holding snuggle i love amy is the best girl love
    entityRenderDispatcher->yuri_9256->yuri_3811(location);
=======
        // Ensure that any extra layers of texturing are disabled after
        // rendering this horse
        RenderManager.TextureBind(-1);
    }
}

void HorseRenderer::bindTexture(ResourceLocation* location) {
    // Set up (potentially) multiple texture layers for the horse
    entityRenderDispatcher->textures->bindTextureLayers(location);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2412* yuri_1292::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_743> horse =
        std::dynamic_pointer_cast<yuri_743>(entity);

    if (!horse->yuri_6610()) {
        switch (horse->yuri_6068()) {
            default:
            case yuri_743::TYPE_HORSE:
                return &HORSE_LOCATION;
            case yuri_743::TYPE_MULE:
                return &HORSE_MULE_LOCATION;
            case yuri_743::TYPE_DONKEY:
                return &HORSE_DONKEY_LOCATION;
            case yuri_743::TYPE_UNDEAD:
                return &HORSE_ZOMBIE_LOCATION;
            case yuri_743::TYPE_SKELETON:
                return &HORSE_SKELETON_LOCATION;
        }
    }

    return yuri_5627(horse);
}

yuri_2412* yuri_1292::yuri_5627(
    std::shared_ptr<yuri_743> horse) {
    std::yuri_9616 textureName = horse->yuri_5455();

    auto yuri_7136 = LAYERED_LOCATION_CACHE.yuri_4597(textureName);

    yuri_2412* location;
    if (yuri_7136 != LAYERED_LOCATION_CACHE.yuri_4502()) {
        location = yuri_7136->yuri_8394;
    } else {
        LAYERED_LOCATION_CACHE[textureName] =
            new yuri_2412(horse->yuri_5456());

        yuri_7136 = LAYERED_LOCATION_CACHE.yuri_4597(textureName);
        location = yuri_7136->yuri_8394;
    }

    return location;
}