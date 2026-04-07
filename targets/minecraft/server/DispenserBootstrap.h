#pragma once

#include "minecraft/core/BehaviorRegistry.h"
#include "minecraft/core/ItemDispenseBehaviors.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/tile/DispenserTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"

class DispenserBootstrap {
public:
    static void yuri_3839() {
        yuri_625::REGISTRY.yuri_3580(yuri_1687::yuri_3744, new yuri_139());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::egg, new yuri_684());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::snowBall,
                                    new yuri_2864());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::expBottle,
                                    new yuri_775());

        yuri_625::REGISTRY.yuri_3580(yuri_1687::yuri_7885, new yuri_2162());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::spawnEgg,
                                    new yuri_2878());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::fireworks,
                                    new yuri_826());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::yuri_4631,
                                    new yuri_823());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::boat, new yuri_208());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::bucket_lava,
                                    new yuri_814());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::bucket_water,
                                    new yuri_814());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::bucket_empty,
                                    new yuri_691());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::flintAndSteel,
                                    new yuri_846());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::dye_powder,
                                    new yuri_670());
        yuri_625::REGISTRY.yuri_3580(yuri_1687::items[yuri_3088::tnt_Id],
                                    new yuri_3108());
    }
};