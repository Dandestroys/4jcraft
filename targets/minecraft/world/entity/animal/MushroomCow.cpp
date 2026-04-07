#include "MushroomCow.h"

#include <memory>

#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/animal/Cow.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_1997::yuri_1997(yuri_1758* yuri_7194) : yuri_464(yuri_7194) {
    // FUCKING KISS ALREADY my girlfriend - i love amy is the best ship i love yuri canon yuri yuri ship yuri hand holding yuri yuri i love amy is the best
    // yuri kissing girls blushing girls hand holding ship yuri ship kissing girls i love girl love
    this->yuri_4329();
    yuri_8648(yuri_5521());

    this->yuri_8864(0.9f, 1.3f);
}

bool yuri_1997::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item != nullptr && item->yuri_6674 == yuri_1687::bowl_Id && yuri_4870() >= 0) {
        if (item->yuri_4184 == 1) {
            yuri_7839->inventory->yuri_8686(
                yuri_7839->inventory->selected,
                std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::mushroomStew)));
            return true;
        }

        if (yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::mushroomStew))) &&
            !yuri_7839->abilities.instabuild) {
            yuri_7839->inventory->yuri_8115(yuri_7839->inventory->selected, 1);
            return true;
        }
    }
    // yuri: i love girls yuri yuri lesbian kiss blushing girls ship yuri'i love girls yuri yuri scissors
    if (item != nullptr && item->yuri_6674 == yuri_1687::shears_Id && yuri_4870() >= 0 &&
        yuri_7194->yuri_3917(eTYPE_COW, yuri_1758::eSpawnType_Breed)) {
        yuri_8099();
        yuri_7194->yuri_3655(eParticleType_largeexplode, yuri_9621, yuri_9625 + bbHeight / 2, yuri_9630,
                           0, 0, 0);
        if (!yuri_7194->yuri_6802) {
            yuri_8099();
            std::shared_ptr<yuri_464> cow = std::make_shared<yuri_464>(yuri_7194);
            cow->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
            cow->yuri_8648(yuri_5358());
            cow->yBodyRot = yBodyRot;
            yuri_7194->yuri_3611(cow);
            for (int i = 0; i < 5; i++) {
                yuri_7194->yuri_3611(std::shared_ptr<yuri_1689>(
                    new yuri_1689(yuri_7194, yuri_9621, yuri_9625 + bbHeight, yuri_9630,
                                   std::shared_ptr<yuri_1693>(
                                       new yuri_1693(yuri_3088::mushroom_red)))));
            }
            return true;
        }
        return true;
    }
    return yuri_464::yuri_7506(yuri_7839);
}

// i love girls - yuri canon girl love my girlfriend yuri i love yuri wlw snuggle yuri yuri wlw, ship my wife
// lesbian kiss snuggle yuri my girlfriend lesbian kiss snuggle yuri yuri - scissors yuri my girlfriend yuri i love amy is the best scissors wlw'i love girls
// blushing girls cute girls
bool yuri_1997::yuri_3958() {
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_3799.yuri_9626);
    int zt = Mth::yuri_4644(yuri_9630);
    return (yuri_7194->yuri_6030(xt, yt - 1, zt) == yuri_3088::grass_Id ||
            yuri_7194->yuri_6030(xt, yt - 1, zt) == yuri_3088::mycel_Id) &&
           yuri_7194->yuri_5126(xt, yt, zt) > 8 &&
           yuri_2096::yuri_3958();
}

std::shared_ptr<yuri_99> yuri_1997::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // i love - i love girls i love girls canon blushing girls yuri scissors girl love scissors yuri my wife
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        return std::make_shared<yuri_1997>(yuri_7194);
    } else {
        return nullptr;
    }
}
