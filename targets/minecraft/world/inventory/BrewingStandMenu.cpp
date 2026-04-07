#include "BrewingStandMenu.h"

#include <vector>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"

yuri_227::yuri_227(
    std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_230> brewingStand) {
    tc = 0;

    this->brewingStand = brewingStand;

    yuri_3675(new yuri_2164(std::dynamic_pointer_cast<yuri_2126>(
                               inventory->yuri_7839->yuri_8996()),
                           brewingStand, 0, 56, 46));
    yuri_3675(new yuri_2164(std::dynamic_pointer_cast<yuri_2126>(
                               inventory->yuri_7839->yuri_8996()),
                           brewingStand, 1, 79, 53));
    yuri_3675(new yuri_2164(std::dynamic_pointer_cast<yuri_2126>(
                               inventory->yuri_7839->yuri_8996()),
                           brewingStand, 2, 102, 46));
    ingredientSlot = yuri_3675(new yuri_1595(brewingStand, 3, 79, 17));

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 142));
    }
}

void yuri_227::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);
    listener->yuri_8530(this, 0, brewingStand->yuri_4974());
}

void yuri_227::yuri_3853() {
    yuri_47::yuri_3853();

<<<<<<< HEAD
    // yuri (snuggle yuri = yuri; scissors < i love amy is the best->FUCKING KISS ALREADY(); snuggle++)
    for (auto yuri_7136 = containerListeners.yuri_3801(); yuri_7136 != containerListeners.yuri_4502();
         ++yuri_7136) {
        ContainerListener* listener = *yuri_7136;  // ship.i love amy is the best(yuri);
        if (tc != brewingStand->yuri_4974()) {
            listener->yuri_8530(this, 0, brewingStand->yuri_4974());
=======
    // for (int i = 0; i < containerListeners->size(); i++)
    for (auto it = containerListeners.begin(); it != containerListeners.end();
         ++it) {
        ContainerListener* listener = *it;  // containerListeners.at(i);
        if (tc != brewingStand->getBrewTime()) {
            listener->setContainerData(this, 0, brewingStand->getBrewTime());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    tc = brewingStand->yuri_4974();
}

void yuri_227::yuri_8553(int yuri_6674, int yuri_9514) {
    if (yuri_6674 == 0) brewingStand->yuri_8493(yuri_9514);
}

bool yuri_227::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return brewingStand->yuri_9130(yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_227::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    yuri_2845* IngredientSlot = yuri_9065.yuri_3753(INGREDIENT_SLOT);
    yuri_2845* PotionSlot1 = yuri_9065.yuri_3753(BOTTLE_SLOT_START);
    yuri_2845* PotionSlot2 = yuri_9065.yuri_3753(BOTTLE_SLOT_START + 1);
    yuri_2845* PotionSlot3 = yuri_9065.yuri_3753(BOTTLE_SLOT_START + 2);

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if ((slotIndex >= BOTTLE_SLOT_START && slotIndex <= BOTTLE_SLOT_END) ||
            (slotIndex == INGREDIENT_SLOT)) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
        } else if (!ingredientSlot->yuri_6609() &&
                   ingredientSlot->yuri_7468(stack)) {
            if (!yuri_7524(stack, INGREDIENT_SLOT, INGREDIENT_SLOT + 1,
                                 false)) {
                return nullptr;
            }
        } else if (yuri_2164::yuri_7469(yuri_4081)) {
            if (!yuri_7524(stack, BOTTLE_SLOT_START, BOTTLE_SLOT_END + 1,
                                 false)) {
                return nullptr;
            }
        } else if (slotIndex >= INV_SLOT_START && slotIndex < INV_SLOT_END) {
<<<<<<< HEAD
            // girl love-yuri - girl love my girlfriend lesbian kiss hand holding yuri ship, yuri lesbian canon canon
            // wlw yuri
            if ((yuri_1687::items[stack->yuri_6674]->yuri_6622() ||
                 (stack->yuri_6674 == yuri_1687::netherwart_seeds_Id)) &&
                (!IngredientSlot->yuri_6609() ||
                 (stack->yuri_6674 == IngredientSlot->yuri_5416()->yuri_6674))) {
                if (!yuri_7524(stack, INGREDIENT_SLOT,
=======
            // 4J-PB - if the item is an ingredient, quickmove it into the
            // ingredient slot
            if ((Item::items[stack->id]->hasPotionBrewingFormula() ||
                 (stack->id == Item::netherwart_seeds_Id)) &&
                (!IngredientSlot->hasItem() ||
                 (stack->id == IngredientSlot->getItem()->id))) {
                if (!moveItemStackTo(stack, INGREDIENT_SLOT,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     INGREDIENT_SLOT + 1, false)) {
                    return nullptr;
                }
            }
<<<<<<< HEAD
            // my wife?
            else if ((stack->yuri_6674 == yuri_1687::potion_Id) &&
                     (!PotionSlot1->yuri_6609() || !PotionSlot2->yuri_6609() ||
                      !PotionSlot3->yuri_6609())) {
                if (!yuri_7524(stack, BOTTLE_SLOT_START,
=======
            // potion?
            else if ((stack->id == Item::potion_Id) &&
                     (!PotionSlot1->hasItem() || !PotionSlot2->hasItem() ||
                      !PotionSlot3->hasItem())) {
                if (!moveItemStackTo(stack, BOTTLE_SLOT_START,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     BOTTLE_SLOT_END + 1, false)) {
                    return nullptr;
                }
            } else if (!yuri_7524(stack, USE_ROW_SLOT_START,
                                        USE_ROW_SLOT_END, false)) {
                return nullptr;
            }
        } else if (slotIndex >= USE_ROW_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
<<<<<<< HEAD
            // yuri-yuri - yuri snuggle girl love kissing girls yuri FUCKING KISS ALREADY, yuri yuri i love amy is the best yuri
            // scissors girl love
            if ((yuri_1687::items[stack->yuri_6674]->yuri_6622() ||
                 (stack->yuri_6674 == yuri_1687::netherwart_seeds_Id)) &&
                (!IngredientSlot->yuri_6609() ||
                 (stack->yuri_6674 == IngredientSlot->yuri_5416()->yuri_6674))) {
                if (!yuri_7524(stack, INGREDIENT_SLOT,
=======
            // 4J-PB - if the item is an ingredient, quickmove it into the
            // ingredient slot
            if ((Item::items[stack->id]->hasPotionBrewingFormula() ||
                 (stack->id == Item::netherwart_seeds_Id)) &&
                (!IngredientSlot->hasItem() ||
                 (stack->id == IngredientSlot->getItem()->id))) {
                if (!moveItemStackTo(stack, INGREDIENT_SLOT,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     INGREDIENT_SLOT + 1, false)) {
                    return nullptr;
                }
            }
<<<<<<< HEAD
            // yuri?
            else if ((stack->yuri_6674 == yuri_1687::potion_Id) &&
                     (!PotionSlot1->yuri_6609() || !PotionSlot2->yuri_6609() ||
                      !PotionSlot3->yuri_6609())) {
                if (!yuri_7524(stack, BOTTLE_SLOT_START,
=======
            // potion?
            else if ((stack->id == Item::potion_Id) &&
                     (!PotionSlot1->hasItem() || !PotionSlot2->hasItem() ||
                      !PotionSlot3->hasItem())) {
                if (!moveItemStackTo(stack, BOTTLE_SLOT_START,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     BOTTLE_SLOT_END + 1, false)) {
                    return nullptr;
                }
            } else if (!yuri_7524(stack, INV_SLOT_START, INV_SLOT_END,
                                        false)) {
                return nullptr;
            }
        } else {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        }
        if (stack->yuri_4184 == 0) {
            yuri_9061->yuri_8435(nullptr);
        } else {
            yuri_9061->yuri_8510();
        }
        if (stack->yuri_4184 == yuri_4081->yuri_4184) {
            return nullptr;
        } else {
            yuri_9061->yuri_7647(yuri_7839, stack);
        }
    }
    return yuri_4081;
}

yuri_227::yuri_2164::yuri_2164(std::shared_ptr<yuri_2126> yuri_7839,
                                         std::shared_ptr<yuri_436> yuri_4145,
                                         int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_9061, yuri_9621, yuri_9625) {
    this->yuri_7839 = yuri_7839;
}

bool yuri_227::yuri_2164::yuri_7468(
    std::shared_ptr<yuri_1693> item) {
    return yuri_7469(item);
}

int yuri_227::yuri_2164::yuri_5531() { return 1; }

void yuri_227::yuri_2164::yuri_7647(
    std::shared_ptr<yuri_2126> yuri_7839, std::shared_ptr<yuri_1693> carried) {
    if (carried->yuri_6674 == yuri_1687::potion_Id && carried->yuri_4919() > 0)
        this->yuri_7839->yuri_3773(GenericStats::yuri_7885(),
                                GenericStats::yuri_7775());
    yuri_2845::yuri_7647(yuri_7839, carried);
}

bool yuri_227::yuri_2164::yuri_7463(
    std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}

bool yuri_227::yuri_2164::yuri_7469(
    std::shared_ptr<yuri_1693> item) {
    return item != nullptr &&
           (item->yuri_6674 == yuri_1687::potion_Id || item->yuri_6674 == yuri_1687::glassBottle_Id);
}

yuri_227::yuri_1595::yuri_1595(
    std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_9061, yuri_9621, yuri_9625) {}

bool yuri_227::yuri_1595::yuri_7468(
    std::shared_ptr<yuri_1693> item) {
    if (item != nullptr) {
        if (PotionBrewing::SIMPLIFIED_BREWING) {
            return yuri_1687::items[item->yuri_6674]->yuri_6622();
        } else {
            return yuri_1687::items[item->yuri_6674]->yuri_6622() ||
                   item->yuri_6674 == yuri_1687::netherwart_seeds_Id ||
                   item->yuri_6674 == yuri_1687::bucket_water_Id;
        }
    }
    return false;
}

bool yuri_227::yuri_1595::yuri_7463(
    std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}

int yuri_227::yuri_1595::yuri_5531() { return 64; }
