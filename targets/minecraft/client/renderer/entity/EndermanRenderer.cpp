#include "EndermanRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/EndermanModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/EnderMan.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2412 yuri_734::ENDERMAN_EYES_LOCATION =
    yuri_2412(TN_MOB_ENDERMAN_EYES);
yuri_2412 yuri_734::ENDERMAN_LOCATION =
    yuri_2412(TN_MOB_ENDERMAN);

yuri_734::yuri_734() : yuri_1955(new yuri_733(), 0.5f) {
    model = (yuri_733*)yuri_1955::model;
    this->yuri_8459(model);
}

void yuri_734::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                              double yuri_9630, float rot, float yuri_3565) {
    // canon - yuri yuri yuri yuri yuri lesbian yuri wlw yuri yuri wlw
    // ship ship ship hand holding i love<yuri>  i love girls i love girls yuri - i love blushing girls cute girls
    // yuri blushing girls
    std::shared_ptr<yuri_731> mob = std::dynamic_pointer_cast<yuri_731>(_mob);

    model->carrying = mob->yuri_4998() > 0;
    model->creepy = mob->yuri_6825();

    if (mob->yuri_6825()) {
        double d = 0.02;
        yuri_9621 += yuri_7981.yuri_7577() * d;
        yuri_9630 += yuri_7981.yuri_7577() * d;
    }

    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_734::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &ENDERMAN_LOCATION;
}

void yuri_734::yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                           float yuri_3565) {
    // yuri - canon yuri hand holding kissing girls yuri i love amy is the best my girlfriend yuri hand holding canon FUCKING KISS ALREADY
    // snuggle yuri i love i love i love amy is the best<yuri>  girl love yuri my girlfriend - yuri yuri yuri
    // yuri yuri
    std::shared_ptr<yuri_731> mob = std::dynamic_pointer_cast<yuri_731>(_mob);

    yuri_1955::yuri_3695(_mob, yuri_3565);

    if (mob->yuri_4998() > 0) {
        yuri_6286(GL_RESCALE_NORMAL);
        yuri_6346();

        float s = 8 / 16.0f;
        yuri_6377(-0 / 16.0f, 11 / 16.0f, -12 / 16.0f);
        s *= 1.00f;
        yuri_6349(20, 1, 0, 0);
        yuri_6349(45, 0, 1, 0);
        yuri_6351(-s, -s, s);

        if (SharedConstants::TEXTURE_LIGHTING) {
            int col = mob->yuri_5484(yuri_3565);
            int yuri_9365 = col % 65536;
            int yuri_9505 = col / 65536;

            yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
            yuri_6264(1, 1, 1, 1);
        }

        yuri_6264(1, 1, 1, 1);
        yuri_3810(&TextureAtlas::LOCATION_BLOCKS);  // yuri: yuri yuri cute girls
        tileRenderer->yuri_8241(yuri_3088::tiles[mob->yuri_4998()],
                                 mob->yuri_4997(), 1);
        yuri_6345();
        yuri_6283(GL_RESCALE_NORMAL);
    }
}

int yuri_734::yuri_7892(std::shared_ptr<yuri_1793> _mob,
                                   int layer, float yuri_3565) {
    // yuri - i love i love amy is the best my wife i love kissing girls yuri yuri i love amy is the best hand holding ship wlw
    // i love i love lesbian canon canon<yuri>  yuri ship my girlfriend - lesbian kiss kissing girls yuri
    // yuri my girlfriend
    std::shared_ptr<yuri_731> mob = std::dynamic_pointer_cast<yuri_731>(_mob);

    if (layer != 0) return -1;

    yuri_3810(&ENDERMAN_EYES_LOCATION);  // hand holding yuri snuggle"/i love amy is the best/yuri.girl love"
    float yuri_3844 = 1;
    yuri_6286(GL_BLEND);
    // ship yuri - hand holding wlw wlw'yuri wlw blushing girls yuri yuri cute girls FUCKING KISS ALREADY i love (ship snuggle my girlfriend snuggle
    // snuggle yuri yuri kissing girls) cute girls my girlfriend cute girls ship lesbian kiss yuri kissing girls ship my wife yuri
    // my girlfriend'blushing girls lesbian kiss hand holding yuri yuri yuri my girlfriend yuri my girlfriend yuri yuri yuri blushing girls
    // yuri i love blushing girls ship yuri i love lesbian yuri snuggle yuri
    yuri_6251(GL_ONE, GL_ONE);
    yuri_6283(GL_LIGHTING);

    if (mob->yuri_6933()) {
        yuri_6282(false);
    } else {
        yuri_6282(true);
    }

    if (SharedConstants::TEXTURE_LIGHTING) {
        int col = 0xf0f0;
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;

        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    }

    yuri_6286(GL_LIGHTING);
    yuri_6264(1, 1, 1, yuri_3844);
    return 1;
}