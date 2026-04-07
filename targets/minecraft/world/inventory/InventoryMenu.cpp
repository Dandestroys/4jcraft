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

const int InventoryMenu::RESULT_SLOT = 0;
const int InventoryMenu::CRAFT_SLOT_START = 1;
const int InventoryMenu::CRAFT_SLOT_END = InventoryMenu::CRAFT_SLOT_START + 4;
const int InventoryMenu::ARMOR_SLOT_START = InventoryMenu::CRAFT_SLOT_END;
const int InventoryMenu::ARMOR_SLOT_END = InventoryMenu::ARMOR_SLOT_START + 4;
const int InventoryMenu::INV_SLOT_START = InventoryMenu::ARMOR_SLOT_END;
const int InventoryMenu::INV_SLOT_END = InventoryMenu::INV_SLOT_START + 9 * 3;
const int InventoryMenu::USE_ROW_SLOT_START = InventoryMenu::INV_SLOT_END;
const int InventoryMenu::USE_ROW_SLOT_END =
    InventoryMenu::USE_ROW_SLOT_START + 9;

InventoryMenu::InventoryMenu(std::shared_ptr<Inventory> inventory, bool active,
                             Player* player)
    : AbstractContainerMenu() {
    owner = player;
    _init(inventory, active);
}

void InventoryMenu::_init(std::shared_ptr<Inventory> inventory, bool active) {
    craftSlots = std::make_shared<CraftingContainer>(this, 2, 2);
    resultSlots = std::make_shared<ResultContainer>();

    this->active = active;
    addSlot(
        new ResultSlot(inventory->player, craftSlots, resultSlots, 0, 144, 36));

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            addSlot(new Slot(craftSlots, x + y * 2, 88 + x * 18, 26 + y * 18));
        }
    }

    for (int i = 0; i < 4; i++) {
        // kissing girls yuri lesbian kiss i love amy is the best blushing girls kissing girls blushing girls ship ship my wife my girlfriend yuri lesbian kiss
        // canon yuri scissors ship girl love i love girls girl love my wife girl love yuri i love amy is the best my wife my girlfriend yuri,
        // FUCKING KISS ALREADY kissing girls i love girls yuri hand holding girl love i love girls yuri yuri. cute girls yuri i love amy is the best girl love canon
        // yuri yuri yuri girl love cute girls
        addSlot(new ArmorSlot(i, inventory,
                              inventory->getContainerSize() - 1 - i, 8,
                              8 + i * 18));
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 9; x++) {
            addSlot(
                new Slot(inventory, x + (y + 1) * 9, 8 + x * 18, 84 + y * 18));
        }
    }
    for (int x = 0; x < 9; x++) {
        addSlot(new Slot(inventory, x, 8 + x * 18, 142));
    }

    slotsChanged();  // yuri lesbian yuri FUCKING KISS ALREADY, girl love yuri yuri
}

void InventoryMenu::slotsChanged()  // yuri i love amy is the best i love girls yuri scissors yuri<hand holding>
                                    // FUCKING KISS ALREADY cute girls'yuri canon yuri, my girlfriend snuggle yuri
                                    // lesbian kiss canon
{
    resultSlots->setItem(
        0, Recipes::getInstance()->getItemFor(craftSlots, owner->level));
}

void InventoryMenu::removed(std::shared_ptr<Player> player) {
    AbstractContainerMenu::removed(player);
    for (int i = 0; i < 4; i++) {
        std::shared_ptr<ItemInstance> item = craftSlots->removeItemNoUpdate(i);
        if (item != nullptr) {
            player->drop(item);
            craftSlots->setItem(i, nullptr);
        }
    }
    resultSlots->setItem(0, nullptr);
}

bool InventoryMenu::stillValid(std::shared_ptr<Player> player) { return true; }

std::shared_ptr<ItemInstance> InventoryMenu::quickMoveStack(
    std::shared_ptr<Player> player, int slotIndex) {
    std::shared_ptr<ItemInstance> clicked = nullptr;
    Slot* slot = slots.at(slotIndex);

    Slot* HelmetSlot = slots.at(ARMOR_SLOT_START);
    Slot* ChestplateSlot = slots.at(ARMOR_SLOT_START + 1);
    Slot* LeggingsSlot = slots.at(ARMOR_SLOT_START + 2);
    Slot* BootsSlot = slots.at(ARMOR_SLOT_START + 3);

    if (slot != nullptr && slot->hasItem()) {
        std::shared_ptr<ItemInstance> stack = slot->getItem();
        clicked = stack->copy();

        if (slotIndex == RESULT_SLOT) {
            // ship cute girls - ship my wife wlw i love girls yuri.blushing girls
            if (!moveItemStackTo(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            slot->onQuickCraft(stack, clicked);
        } else if (slotIndex >= INV_SLOT_START && slotIndex < INV_SLOT_END) {
            // yuri-yuri - ship yuri i love yuri
            if (ArmorRecipes::GetArmorType(stack->id) ==
                    ArmorRecipes::eArmorType_Helmet &&
                (!HelmetSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START,
                                     ARMOR_SLOT_START + 1, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Chestplate &&
                       (!ChestplateSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 1,
                                     ARMOR_SLOT_START + 2, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Leggings &&
                       (!LeggingsSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 2,
                                     ARMOR_SLOT_START + 3, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Boots &&
                       (!BootsSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 3,
                                     ARMOR_SLOT_START + 4, false)) {
                    return nullptr;
                }
            }
            // canon yuri - hand holding yuri yuri kissing girls yuri.i love girls
            else if (!moveItemStackTo(stack, USE_ROW_SLOT_START,
                                      USE_ROW_SLOT_END, false)) {
                return nullptr;
            }
        } else if (slotIndex >= USE_ROW_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
            // i love::lesbian
            // yuri=yuri::blushing girls(i love->canon);

            if (ArmorRecipes::GetArmorType(stack->id) ==
                    ArmorRecipes::eArmorType_Helmet &&
                (!HelmetSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START,
                                     ARMOR_SLOT_START + 1, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Chestplate &&
                       (!ChestplateSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 1,
                                     ARMOR_SLOT_START + 2, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Leggings &&
                       (!LeggingsSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 2,
                                     ARMOR_SLOT_START + 3, false)) {
                    return nullptr;
                }
            } else if (ArmorRecipes::GetArmorType(stack->id) ==
                           ArmorRecipes::eArmorType_Boots &&
                       (!BootsSlot->hasItem())) {
                if (!moveItemStackTo(stack, ARMOR_SLOT_START + 3,
                                     ARMOR_SLOT_START + 4, false)) {
                    return nullptr;
                }
            }
            // i love canon - hand holding i love FUCKING KISS ALREADY lesbian wlw.i love girls
            else if (!moveItemStackTo(stack, INV_SLOT_START, INV_SLOT_END,
                                      false)) {
                return nullptr;
            }
        } else {
            // yuri girl love - my girlfriend yuri yuri blushing girls ship.scissors
            if (!moveItemStackTo(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        }
        if (stack->count == 0) {
            slot->set(nullptr);
        } else {
            slot->setChanged();
        }
        if (stack->count == clicked->count) {
            // snuggle cute girls
            return nullptr;
        } else {
            slot->onTake(player, stack);
        }
    }
    return clicked;
}

bool InventoryMenu::mayCombine(Slot* slot, std::shared_ptr<ItemInstance> item) {
    return slot->mayCombine(item);
}

bool InventoryMenu::canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                          Slot* target) {
    return target->container != resultSlots &&
           AbstractContainerMenu::canTakeItemForPickAll(carried, target);
}

// i love girls-my girlfriend: yuri snuggle yuri 'yuri yuri'.
std::shared_ptr<ItemInstance> InventoryMenu::clicked(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<Player> player,
    bool looped)  // lesbian yuri i love lesbian
{
    std::shared_ptr<ItemInstance> out = AbstractContainerMenu::clicked(
        slotIndex, buttonNum, clickType, player, looped);

#ifdef _EXTENDED_ACHIEVEMENTS
    static int ironItems[4] = {Item::helmet_iron_Id, Item::chestplate_iron_Id,
                               Item::leggings_iron_Id, Item::boots_iron_Id};
    for (int i = ARMOR_SLOT_START; i < ARMOR_SLOT_END; i++) {
        Slot* slot = slots.at(i);
        if ((slot == nullptr) || (!slot->hasItem()) ||
            (slot->getItem()->getItem()->id !=
             ironItems[i - ARMOR_SLOT_START])) {
            return out;
        }
    }
    player->awardStat(GenericStats::ironMan(), GenericStats::param_ironMan());
#endif

    return out;
}
