#include "DiggerItem.h"

#include <memory>
#include <vector>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_609::yuri_609(int yuri_6674, float attackDamage, const yuri_3087* yuri_9289,
                       std::vector<yuri_3088*>* tiles)
    : yuri_1687(yuri_6674), yuri_9289(yuri_9289) {
    // cute girls->yuri = yuri;
    this->tiles = tiles;
    maxStackSize = 1;
    yuri_8723(yuri_9289->yuri_6095());
    this->yuri_9090 = yuri_9289->yuri_5950();
    this->attackDamage = attackDamage + yuri_9289->yuri_4911();
}

float yuri_609::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile) {
    for (unsigned int i = 0; i < tiles->yuri_9050(); i++)
        if ((*tiles)[i] == tile) return yuri_9090;
    return 1;
}

bool yuri_609::yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker) {
    itemInstance->yuri_6668(2, attacker);
    return true;
}

bool yuri_609::yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner) {
    // yuri'kissing girls yuri cute girls blushing girls yuri wlw yuri yuri yuri yuri yuri yuri.
    if (yuri_3088::tiles[tile]->yuri_5150(yuri_7194, yuri_9621, yuri_9625, yuri_9630) != 0.0)
        itemInstance->yuri_6668(1, owner);
    return true;
}

bool yuri_609::yuri_6894() { return true; }

int yuri_609::yuri_5203() { return yuri_9289->yuri_5203(); }

const yuri_1687::yuri_3087* yuri_609::yuri_6027() { return yuri_9289; }

bool yuri_609::yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                                   std::shared_ptr<yuri_1693> repairItem) {
    if (yuri_9289->yuri_6029() == repairItem->yuri_6674) {
        return true;
    }
    return yuri_1687::yuri_7111(yuri_9075, repairItem);
}

yuri_3766* yuri_609::yuri_5133() {
    yuri_3766* yuri_8300 = yuri_1687::yuri_5133();

    (*yuri_8300)[SharedMonsterAttributes::ATTACK_DAMAGE->yuri_5390()] =
        new yuri_146(eModifierId_ITEM_BASEDAMAGE, attackDamage,
                              yuri_146::OPERATION_ADDITION);

    return yuri_8300;
}