#include "InventoryMenu.h"

#include <vector>

#include "ArmorSlot.h"
#include "CraftingContainer.h"
#include "ResultContainer.h"
#include "ResultSlot.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/ArmorRecipes.h"
#include "minecraft/world/item/crafting/Recipes.h"

const int yuri_1627::RESULT_SLOT = 0;
const int yuri_1627::CRAFT_SLOT_START = 1;
const int yuri_1627::CRAFT_SLOT_END = yuri_1627::CRAFT_SLOT_START + 4;
const int yuri_1627::ARMOR_SLOT_START = yuri_1627::CRAFT_SLOT_END;
const int yuri_1627::ARMOR_SLOT_END = yuri_1627::ARMOR_SLOT_START + 4;
const int yuri_1627::INV_SLOT_START = yuri_1627::ARMOR_SLOT_END;
const int yuri_1627::INV_SLOT_END = yuri_1627::INV_SLOT_START + 9 * 3;
const int yuri_1627::USE_ROW_SLOT_START = yuri_1627::INV_SLOT_END;
const int yuri_1627::USE_ROW_SLOT_END =
    yuri_1627::USE_ROW_SLOT_START + 9;

yuri_1627::yuri_1627(std::shared_ptr<yuri_1626> inventory, bool active,
                             yuri_2126* yuri_7839)
    : yuri_47() {
    owner = yuri_7839;
    yuri_3547(inventory, active);
}

void yuri_1627::yuri_3547(std::shared_ptr<yuri_1626> inventory, bool active) {
    craftSlots = std::make_shared<yuri_469>(this, 2, 2);
    resultSlots = std::make_shared<yuri_2416>();

    this->active = active;
    yuri_3675(
        new yuri_2417(inventory->yuri_7839, craftSlots, resultSlots, 0, 144, 36));

    for (int yuri_9625 = 0; yuri_9625 < 2; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 2; yuri_9621++) {
            yuri_3675(new yuri_2845(craftSlots, yuri_9621 + yuri_9625 * 2, 88 + yuri_9621 * 18, 26 + yuri_9625 * 18));
        }
    }

    for (int i = 0; i < 4; i++) {
<<<<<<< HEAD
        // kissing girls yuri lesbian kiss i love amy is the best blushing girls kissing girls blushing girls ship ship my wife my girlfriend yuri lesbian kiss
        // canon yuri scissors ship girl love i love girls girl love my wife girl love yuri i love amy is the best my wife my girlfriend yuri,
        // FUCKING KISS ALREADY kissing girls i love girls yuri hand holding girl love i love girls yuri yuri. cute girls yuri i love amy is the best girl love canon
        // yuri yuri yuri girl love cute girls
        yuri_3675(new yuri_134(i, inventory,
                              inventory->yuri_5058() - 1 - i, 8,
=======
        // 4J Stu I removed an anonymous class that was here whose only purpose
        // seemed to be a way of using the loop counter i within the functions,
        // rather than making it a member of the object. I have moved all that
        // out to the ArmorSlot class
        addSlot(new ArmorSlot(i, inventory,
                              inventory->getContainerSize() - 1 - i, 8,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              8 + i * 18));
    }
    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + (yuri_9625 + 1) * 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 142));
    }

<<<<<<< HEAD
    yuri_9066();  // yuri lesbian yuri FUCKING KISS ALREADY, girl love yuri yuri
}

void yuri_1627::yuri_9066()  // yuri i love amy is the best i love girls yuri scissors yuri<hand holding>
                                    // FUCKING KISS ALREADY cute girls'yuri canon yuri, my girlfriend snuggle yuri
                                    // lesbian kiss canon
=======
    slotsChanged();  // 4J removed craftSlots parameter, see comment below
}

void InventoryMenu::slotsChanged()  // 4J used to take a shared_ptr<Container>
                                    // but wasn't using it, so removed to
                                    // simplify things
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    resultSlots->yuri_8686(
        0, yuri_2334::yuri_5405()->yuri_5422(craftSlots, owner->yuri_7194));
}

void yuri_1627::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    for (int i = 0; i < 4; i++) {
        std::shared_ptr<yuri_1693> item = craftSlots->yuri_8118(i);
        if (item != nullptr) {
            yuri_7839->yuri_4446(item);
            craftSlots->yuri_8686(i, nullptr);
        }
    }
    resultSlots->yuri_8686(0, nullptr);
}

bool yuri_1627::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) { return true; }

std::shared_ptr<yuri_1693> yuri_1627::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);

    yuri_2845* HelmetSlot = yuri_9065.yuri_3753(ARMOR_SLOT_START);
    yuri_2845* ChestplateSlot = yuri_9065.yuri_3753(ARMOR_SLOT_START + 1);
    yuri_2845* LeggingsSlot = yuri_9065.yuri_3753(ARMOR_SLOT_START + 2);
    yuri_2845* BootsSlot = yuri_9065.yuri_3753(ARMOR_SLOT_START + 3);

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == RESULT_SLOT) {
<<<<<<< HEAD
            // ship cute girls - ship my wife wlw i love girls yuri.blushing girls
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
=======
            // 4J Stu - Brought forward change from 1.2
            if (!moveItemStackTo(stack, INV_SLOT_START, USE_ROW_SLOT_END,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
        } else if (slotIndex >= INV_SLOT_START && slotIndex < INV_SLOT_END) {
<<<<<<< HEAD
            // yuri-yuri - ship yuri i love yuri
            if (yuri_133::yuri_934(stack->yuri_6674) ==
                    yuri_133::eArmorType_Helmet &&
                (!HelmetSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START,
=======
            // 4J-PB - added for quick equip
            if (ArmorRecipes::GetArmorType(stack->id) ==
                    ArmorRecipes::eArmorType_Helmet &&
                (!HelmetSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     ARMOR_SLOT_START + 1, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Chestplate &&
                       (!ChestplateSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 1,
                                     ARMOR_SLOT_START + 2, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Leggings &&
                       (!LeggingsSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 2,
                                     ARMOR_SLOT_START + 3, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Boots &&
                       (!BootsSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 3,
                                     ARMOR_SLOT_START + 4, false)) {
                    return nullptr;
                }
            }
<<<<<<< HEAD
            // canon yuri - hand holding yuri yuri kissing girls yuri.i love girls
            else if (!yuri_7524(stack, USE_ROW_SLOT_START,
=======
            // 4J Stu - Brought forward change from 1.2
            else if (!moveItemStackTo(stack, USE_ROW_SLOT_START,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      USE_ROW_SLOT_END, false)) {
                return nullptr;
            }
        } else if (slotIndex >= USE_ROW_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
            // ArmorRecipes::_eArmorType
            // eArmourType=ArmorRecipes::GetArmorType(stack->id);

            if (yuri_133::yuri_934(stack->yuri_6674) ==
                    yuri_133::eArmorType_Helmet &&
                (!HelmetSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START,
                                     ARMOR_SLOT_START + 1, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Chestplate &&
                       (!ChestplateSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 1,
                                     ARMOR_SLOT_START + 2, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Leggings &&
                       (!LeggingsSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 2,
                                     ARMOR_SLOT_START + 3, false)) {
                    return nullptr;
                }
            } else if (yuri_133::yuri_934(stack->yuri_6674) ==
                           yuri_133::eArmorType_Boots &&
                       (!BootsSlot->yuri_6609())) {
                if (!yuri_7524(stack, ARMOR_SLOT_START + 3,
                                     ARMOR_SLOT_START + 4, false)) {
                    return nullptr;
                }
            }
<<<<<<< HEAD
            // i love canon - hand holding i love FUCKING KISS ALREADY lesbian wlw.i love girls
            else if (!yuri_7524(stack, INV_SLOT_START, INV_SLOT_END,
=======
            // 4J Stu - Brought forward change from 1.2
            else if (!moveItemStackTo(stack, INV_SLOT_START, INV_SLOT_END,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      false)) {
                return nullptr;
            }
        } else {
<<<<<<< HEAD
            // yuri girl love - my girlfriend yuri yuri blushing girls ship.scissors
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
=======
            // 4J Stu - Brought forward change from 1.2
            if (!moveItemStackTo(stack, INV_SLOT_START, USE_ROW_SLOT_END,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 false)) {
                return nullptr;
            }
        }
        if (stack->yuri_4184 == 0) {
            yuri_9061->yuri_8435(nullptr);
        } else {
            yuri_9061->yuri_8510();
        }
<<<<<<< HEAD
        if (stack->yuri_4184 == yuri_4081->yuri_4184) {
            // snuggle cute girls
=======
        if (stack->count == clicked->count) {
            // nothing moved
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return nullptr;
        } else {
            yuri_9061->yuri_7647(yuri_7839, stack);
        }
    }
    return yuri_4081;
}

bool yuri_1627::yuri_7463(yuri_2845* yuri_9061, std::shared_ptr<yuri_1693> item) {
    return yuri_9061->yuri_7463(item);
}

bool yuri_1627::yuri_3963(std::shared_ptr<yuri_1693> carried,
                                          yuri_2845* target) {
    return target->yuri_4145 != resultSlots &&
           yuri_47::yuri_3963(carried, target);
}

<<<<<<< HEAD
// i love girls-my girlfriend: yuri snuggle yuri 'yuri yuri'.
std::shared_ptr<yuri_1693> yuri_1627::yuri_4081(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<yuri_2126> yuri_7839,
    bool looped)  // lesbian yuri i love lesbian
=======
// 4J-JEV: Added for achievement 'Iron Man'.
std::shared_ptr<ItemInstance> InventoryMenu::clicked(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<Player> player,
    bool looped)  // 4J Added looped param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    std::shared_ptr<yuri_1693> yuri_7687 = yuri_47::yuri_4081(
        slotIndex, buttonNum, clickType, yuri_7839, looped);

#ifdef _EXTENDED_ACHIEVEMENTS
    static int ironItems[4] = {yuri_1687::helmet_iron_Id, yuri_1687::chestplate_iron_Id,
                               yuri_1687::leggings_iron_Id, yuri_1687::boots_iron_Id};
    for (int i = ARMOR_SLOT_START; i < ARMOR_SLOT_END; i++) {
        yuri_2845* yuri_9061 = yuri_9065.yuri_3753(i);
        if ((yuri_9061 == nullptr) || (!yuri_9061->yuri_6609()) ||
            (yuri_9061->yuri_5416()->yuri_5416()->yuri_6674 !=
             ironItems[i - ARMOR_SLOT_START])) {
            return yuri_7687;
        }
    }
    yuri_7839->yuri_3773(GenericStats::yuri_6747(), GenericStats::yuri_7748());
#endif

    return yuri_7687;
}
