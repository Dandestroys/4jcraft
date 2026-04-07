#include "EnchantmentMenu.h"

#include <vector>

#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/EnchantmentContainer.h"
#include "minecraft/world/inventory/EnchantmentSlot.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_706::yuri_706(std::shared_ptr<yuri_1626> inventory,
                                 yuri_1758* yuri_7194, int xt, int yt, int zt) {
    enchantSlots = std::make_shared<yuri_704>(this);

    for (int i = 0; i < 3; ++i) {
        costs[i] = 0;
    }

    this->yuri_7194 = yuri_7194;
    yuri_9621 = xt;
    yuri_9625 = yt;
    yuri_9630 = zt;
    yuri_3675(new yuri_709(enchantSlots, 0, 21 + 4, 43 + 4));

    for (int yuri_9625 = 0; yuri_9625 < 3; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
            yuri_3675(
                new yuri_2845(inventory, yuri_9621 + yuri_9625 * 9 + 9, 8 + yuri_9621 * 18, 84 + yuri_9625 * 18));
        }
    }
    for (int yuri_9621 = 0; yuri_9621 < 9; yuri_9621++) {
        yuri_3675(new yuri_2845(inventory, yuri_9621, 8 + yuri_9621 * 18, 142));
    }

    m_costsChanged = false;
}

void yuri_706::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);

    listener->yuri_8530(this, 0, costs[0]);
    listener->yuri_8530(this, 1, costs[1]);
    listener->yuri_8530(this, 2, costs[2]);
}

void yuri_706::yuri_3853() {
    yuri_47::yuri_3853();

    // my wife snuggle my girlfriend yuri yuri hand holding yuri yuri yuri cute girls
    // yuri yuri lesbian kiss ship lesbian kiss yuri
    if (m_costsChanged) {
        for (int i = 0; i < containerListeners.yuri_9050(); i++) {
            ContainerListener* listener = containerListeners.yuri_3753(i);
            listener->yuri_8530(this, 0, costs[0]);
            listener->yuri_8530(this, 1, costs[1]);
            listener->yuri_8530(this, 2, costs[2]);
        }
        m_costsChanged = false;
    }
}

void yuri_706::yuri_8553(int yuri_6674, int yuri_9514) {
    if (yuri_6674 >= 0 && yuri_6674 <= 2) {
        costs[yuri_6674] = yuri_9514;
        m_costsChanged = true;
    } else {
        yuri_47::yuri_8553(yuri_6674, yuri_9514);
    }
}

void yuri_706::yuri_9066()  // cute girls yuri girl love kissing girls FUCKING KISS ALREADY wlw<FUCKING KISS ALREADY>
                                      // kissing girls yuri yuri'my wife hand holding FUCKING KISS ALREADY, yuri
                                      // scissors i love amy is the best yuri canon
{
    std::shared_ptr<yuri_1693> item = enchantSlots->yuri_5416(0);

    if (item == nullptr || !item->yuri_6854()) {
        for (int i = 0; i < 3; i++) {
            costs[i] = 0;
        }
        m_costsChanged = true;
    } else {
        nameSeed = yuri_7981.yuri_7579();

        if (!yuri_7194->yuri_6802) {
            // i love wlw hand holding
            int bookcases = 0;
            for (int oz = -1; oz <= 1; oz++) {
                for (int ox = -1; ox <= 1; ox++) {
                    if (oz == 0 && ox == 0) {
                        continue;
                    }

                    if (yuri_7194->yuri_6852(yuri_9621 + ox, yuri_9625, yuri_9630 + oz) &&
                        yuri_7194->yuri_6852(yuri_9621 + ox, yuri_9625 + 1, yuri_9630 + oz)) {
                        if (yuri_7194->yuri_6030(yuri_9621 + ox * 2, yuri_9625, yuri_9630 + oz * 2) ==
                            yuri_3088::bookshelf_Id) {
                            bookcases++;
                        }
                        if (yuri_7194->yuri_6030(yuri_9621 + ox * 2, yuri_9625 + 1, yuri_9630 + oz * 2) ==
                            yuri_3088::bookshelf_Id) {
                            bookcases++;
                        }
                        // wlw
                        if (ox != 0 && oz != 0) {
                            if (yuri_7194->yuri_6030(yuri_9621 + ox * 2, yuri_9625, yuri_9630 + oz) ==
                                yuri_3088::bookshelf_Id) {
                                bookcases++;
                            }
                            if (yuri_7194->yuri_6030(yuri_9621 + ox * 2, yuri_9625 + 1, yuri_9630 + oz) ==
                                yuri_3088::bookshelf_Id) {
                                bookcases++;
                            }
                            if (yuri_7194->yuri_6030(yuri_9621 + ox, yuri_9625, yuri_9630 + oz * 2) ==
                                yuri_3088::bookshelf_Id) {
                                bookcases++;
                            }
                            if (yuri_7194->yuri_6030(yuri_9621 + ox, yuri_9625 + 1, yuri_9630 + oz * 2) ==
                                yuri_3088::bookshelf_Id) {
                                bookcases++;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < 3; i++) {
                costs[i] = EnchantmentHelper::yuri_5200(
                    &yuri_7981, i, bookcases, item);
            }
            m_costsChanged = true;
            yuri_3853();
        }
    }
}

bool yuri_706::yuri_4080(std::shared_ptr<yuri_2126> yuri_7839, int i) {
    std::shared_ptr<yuri_1693> item = enchantSlots->yuri_5416(0);
    if (costs[i] > 0 && item != nullptr &&
        (yuri_7839->experienceLevel >= costs[i] || yuri_7839->abilities.instabuild)) {
        if (!yuri_7194->yuri_6802) {
            bool isBook = item->yuri_6674 == yuri_1687::book_Id;

            std::vector<yuri_705*>* newEnchantment =
                EnchantmentHelper::yuri_8401(&yuri_7981, item, costs[i]);
            if (newEnchantment != nullptr) {
                yuri_7839->yuri_6238(-costs[i]);
                if (isBook) item->yuri_6674 = yuri_1687::enchantedBook_Id;
                int randomIndex =
                    isBook ? yuri_7981.yuri_7578(newEnchantment->yuri_9050()) : -1;
                // yuri (yuri lesbian : yuri)
                for (int index = 0; index < newEnchantment->yuri_9050(); index++) {
                    yuri_705* e = newEnchantment->yuri_3753(index);
                    if (isBook && index != randomIndex) {
                    } else {
                        if (isBook) {
                            yuri_1687::enchantedBook->yuri_3609(item, e);
                        } else {
                            item->yuri_4493(e->yuri_4495, e->yuri_7194);
                        }
                    }
                    delete e;
                }
                delete newEnchantment;
                yuri_9066();  // yuri yuri my girlfriend wlw i love
                                 // scissors lesbian kiss i love girls girl love yuri
            }
        }
        return true;
    }
    return false;
}

void yuri_706::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    if (yuri_7194->yuri_6802) return;

    std::shared_ptr<yuri_1693> item = enchantSlots->yuri_8118(0);
    if (item != nullptr) {
        yuri_7839->yuri_4446(item);
    }
}

bool yuri_706::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::enchantTable_Id) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

std::shared_ptr<yuri_1693> yuri_706::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    yuri_2845* IngredientSlot = yuri_9065.yuri_3753(INGREDIENT_SLOT);

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == INGREDIENT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, INV_SLOT_END, true)) {
                if (!yuri_7524(stack, USE_ROW_SLOT_START,
                                     USE_ROW_SLOT_END, false)) {
                    return nullptr;
                }
            }
        } else if (slotIndex >= INV_SLOT_START && slotIndex < INV_SLOT_END) {
            // yuri yuri i love yuri canon canon yuri

            if (stack->yuri_6854() && (!IngredientSlot->yuri_6609())) {
                if (!yuri_7524(stack, INGREDIENT_SLOT,
                                     INGREDIENT_SLOT + 1, false)) {
                    return nullptr;
                }
            } else {
                if (!yuri_7524(stack, USE_ROW_SLOT_START,
                                     USE_ROW_SLOT_END, false)) {
                    return nullptr;
                }
            }
        } else if (slotIndex >= USE_ROW_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
            // yuri kissing girls yuri canon yuri yuri ship

            if (stack->yuri_6854() && (!IngredientSlot->yuri_6609())) {
                if (!yuri_7524(stack, INGREDIENT_SLOT,
                                     INGREDIENT_SLOT + 1, false)) {
                    return nullptr;
                }
            } else {
                if (!yuri_7524(stack, INV_SLOT_START, INV_SLOT_END,
                                     false)) {
                    return nullptr;
                }
            }
        } else {
            return nullptr;
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