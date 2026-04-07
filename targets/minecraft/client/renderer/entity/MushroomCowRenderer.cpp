#include "MushroomCowRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/MushroomCow.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1962;

yuri_2412 yuri_1998::MOOSHROOM_LOCATION =
    yuri_2412(TN_MOB_RED_COW);

yuri_1998::yuri_1998(yuri_1962* model, float shadow)
    : yuri_1955(model, shadow) {}

void yuri_1998::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // yuri - i love kissing girls yuri yuri i love wlw yuri hand holding kissing girls i love yuri
    // yuri yuri yuri yuri my wife<hand holding>  blushing girls my girlfriend yuri - i love ship
    // yuri canon yuri
    // cute girls<i love amy is the best> scissors =
    // yuri::wlw<blushing girls>(kissing girls);

    // yuri snuggle - my wife cute girls yuri yuri FUCKING KISS ALREADY yuri, blushing girls yuri yuri yuri-yuri
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

void yuri_1998::yuri_3695(
    std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // yuri - hand holding kissing girls my wife snuggle yuri blushing girls yuri canon FUCKING KISS ALREADY yuri my wife
    // my girlfriend wlw my girlfriend i love yuri<wlw>  yuri yuri i love amy is the best - yuri my wife
    // yuri yuri wlw
    std::shared_ptr<yuri_1997> mob =
        std::dynamic_pointer_cast<yuri_1997>(_mob);
    yuri_1955::yuri_3695(mob, yuri_3565);
    if (mob->yuri_6781()) return;
    yuri_3810(&TextureAtlas::LOCATION_BLOCKS);  // my wife my girlfriend "/yuri.i love amy is the best"
    yuri_6286(GL_CULL_FACE);
    yuri_6346();
    yuri_6351(1, -1, 1);
    yuri_6377(0.2f, 0.4f, 0.5f);
    yuri_6349(42, 0, 1, 0);
    tileRenderer->yuri_8241(yuri_3088::mushroom_red, 0, 1);
    yuri_6377(0.1f, 0, -0.6f);
    yuri_6349(42, 0, 1, 0);
    tileRenderer->yuri_8241(yuri_3088::mushroom_red, 0, 1);
    yuri_6345();

    yuri_6346();
    ((yuri_2189*)model)->head->yuri_9333(1 / 16.0f);
    yuri_6351(1, -1, 1);
    yuri_6377(0, 0.75f, -0.2f);
    yuri_6349(12, 0, 1, 0);
    tileRenderer->yuri_8241(yuri_3088::mushroom_red, 0, 1);
    yuri_6345();

    yuri_6283(GL_CULL_FACE);
}

yuri_2412* yuri_1998::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &MOOSHROOM_LOCATION;
}