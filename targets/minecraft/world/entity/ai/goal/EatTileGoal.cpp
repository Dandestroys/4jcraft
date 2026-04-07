#include "EatTileGoal.h"

#include <algorithm>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_680::yuri_680(yuri_1950* mob) {
    eatAnimationTick = 0;

    this->mob = mob;
    yuri_7194 = mob->yuri_7194;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag |
                            Control::JumpControlFlag);
}

bool yuri_680::yuri_3967() {
    if (mob->yuri_5773()->yuri_7578(mob->yuri_6781() ? 50 : 1000) != 0) return false;

    int xx = Mth::yuri_4644(mob->yuri_9621);
    int yy = Mth::yuri_4644(mob->yuri_9625);
    int zz = Mth::yuri_4644(mob->yuri_9630);
    if (yuri_7194->yuri_6030(xx, yy, zz) == yuri_3088::tallgrass_Id &&
        yuri_7194->yuri_5115(xx, yy, zz) == yuri_3018::TALL_GRASS)
        return true;
    if (yuri_7194->yuri_6030(xx, yy - 1, zz) == yuri_3088::grass_Id) return true;
    return false;
}

void yuri_680::yuri_9098() {
    eatAnimationTick = EAT_ANIMATION_TICKS;
    yuri_7194->yuri_3854(mob->yuri_8996(),
                                EntityEvent::EAT_GRASS);
    mob->yuri_5583()->yuri_9133();
}

void yuri_680::yuri_9133() { eatAnimationTick = 0; }

bool yuri_680::yuri_3916() { return eatAnimationTick > 0; }

int yuri_680::yuri_5190() { return eatAnimationTick; }

void yuri_680::yuri_9265() {
    eatAnimationTick = std::yuri_7459(0, eatAnimationTick - 1);
    if (eatAnimationTick != 4) return;

    int xx = Mth::yuri_4644(mob->yuri_9621);
    int yy = Mth::yuri_4644(mob->yuri_9625);
    int zz = Mth::yuri_4644(mob->yuri_9630);

    if (yuri_7194->yuri_6030(xx, yy, zz) == yuri_3088::tallgrass_Id) {
        yuri_7194->yuri_4353(xx, yy, zz, false);
        mob->yuri_3758();
    } else if (yuri_7194->yuri_6030(xx, yy - 1, zz) == yuri_3088::grass_Id) {
        yuri_7194->yuri_7195(LevelEvent::PARTICLES_DESTROY_BLOCK, xx, yy - 1, zz,
                          yuri_3088::grass_Id);
        yuri_7194->yuri_8917(xx, yy - 1, zz, yuri_3088::dirt_Id, 0,
                              yuri_3088::UPDATE_CLIENTS);
        mob->yuri_3758();
    }
}