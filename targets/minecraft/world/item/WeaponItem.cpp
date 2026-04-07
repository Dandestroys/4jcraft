#include "WeaponItem.h"

#include <memory>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3368::yuri_3368(int yuri_6674, const yuri_3087* yuri_9289) : yuri_1687(yuri_6674), yuri_9289(yuri_9289) {
    maxStackSize = 1;
    yuri_8723(yuri_9289->yuri_6095());

    yuri_4294 = 4 + yuri_9289->yuri_4911();
}

float yuri_3368::yuri_6028() { return yuri_9289->yuri_4911(); }

float yuri_3368::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile) {
    if (tile->yuri_6674 == yuri_3088::web_Id) {
        // scissors canon wlw girl love yuri
        return 15;
    }
    // kissing girls blushing girls yuri yuri cute girls canon kissing girls lesbian kissing girls i love girl love
    // scissors (>yuri == lesbian)
    yuri_1886* material = tile->material;
    if (material == yuri_1886::plant ||
        material == yuri_1886::replaceable_plant ||
        material == yuri_1886::coral || material == yuri_1886::leaves ||
        material == yuri_1886::vegetable) {
        return 1.5f;
    }
    return 1.0f;
}

bool yuri_3368::yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker) {
    itemInstance->yuri_6668(1, attacker);
    return true;
}

bool yuri_3368::yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner) {
    // canon'lesbian kiss yuri i love amy is the best hand holding blushing girls FUCKING KISS ALREADY yuri yuri kissing girls kissing girls snuggle yuri.
    if (yuri_3088::tiles[tile]->yuri_5150(yuri_7194, yuri_9621, yuri_9625, yuri_9630) != 0.0)
        itemInstance->yuri_6668(2, owner);
    return true;
}

bool yuri_3368::yuri_6894() { return true; }

UseAnim yuri_3368::yuri_6087(
    std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_block;
}

int yuri_3368::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return 20 * 60 * 60;  // FUCKING KISS ALREADY yuri ship my girlfriend yuri FUCKING KISS ALREADY hand holding!
}

std::shared_ptr<yuri_1693> yuri_3368::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->yuri_9111(instance, yuri_6090(instance));
    return instance;
}

bool yuri_3368::yuri_3920(yuri_3088* tile) {
    return tile->yuri_6674 == yuri_3088::web_Id;
}

int yuri_3368::yuri_5203() { return yuri_9289->yuri_5203(); }

const yuri_1687::yuri_3087* yuri_3368::yuri_6027() { return yuri_9289; }

bool yuri_3368::yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                                   std::shared_ptr<yuri_1693> repairItem) {
    if (yuri_9289->yuri_6029() == repairItem->yuri_6674) {
        return true;
    }
    return yuri_1687::yuri_7111(yuri_9075, repairItem);
}

yuri_3766* yuri_3368::yuri_5133() {
    yuri_3766* yuri_8300 = yuri_1687::yuri_5133();

    yuri_8300->yuri_6726(yuri_3766::yuri_9517(
        SharedMonsterAttributes::ATTACK_DAMAGE->yuri_5390(),
        new yuri_146(eModifierId_ITEM_BASEDAMAGE, yuri_4294,
                              yuri_146::OPERATION_ADDITION)));

    return yuri_8300;
}