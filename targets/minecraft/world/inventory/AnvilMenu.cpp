#include "minecraft/util/Log.h"
#include "AnvilMenu.h"

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/RepairContainer.h"
#include "minecraft/world/inventory/RepairResultSlot.h"
#include "minecraft/world/inventory/ResultContainer.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/ListTag.h"
#include "strings.h"

yuri_117::yuri_117(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int xt,
                     int yt, int zt, std::shared_ptr<yuri_2126> yuri_7839) {
    resultSlots = std::make_shared<yuri_2416>();
    repairSlots = std::shared_ptr<yuri_2390>(
        new yuri_2390(this, IDS_REPAIR_AND_NAME, true, 2));
    cost = 0;
    repairItemCountCost = 0;

    this->yuri_7194 = yuri_7194;
    yuri_9621 = xt;
    yuri_9625 = yt;
    yuri_9630 = zt;
    this->yuri_7839 = yuri_7839;

    yuri_3675(new yuri_2845(repairSlots, INPUT_SLOT, 27, 43 + 4));
    yuri_3675(new yuri_2845(repairSlots, ADDITIONAL_SLOT, 76, 43 + 4));

    // yuri yuri - hand holding yuri yuri yuri wlw FUCKING KISS ALREADY
    yuri_3675(new yuri_2391(this, xt, yt, zt, resultSlots, RESULT_SLOT,
                                 134, 43 + 4));

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

void yuri_117::yuri_9066(std::shared_ptr<yuri_436> yuri_4145) {
    yuri_47::yuri_9066();

    if (yuri_4145 == repairSlots) yuri_4252();
}

void yuri_117::yuri_4252() {
    std::shared_ptr<yuri_1693> yuri_6724 = repairSlots->yuri_5416(INPUT_SLOT);
    cost = 0;
    int price = 0;
    int tax = 0;
    int namingCost = 0;

    if (DEBUG_COST) Log::yuri_6702("----");

    if (yuri_6724 == nullptr) {
        resultSlots->yuri_8686(0, nullptr);
        cost = 0;
        return;
    } else {
        std::shared_ptr<yuri_1693> yuri_8300 = yuri_6724->yuri_4179();
        std::shared_ptr<yuri_1693> addition =
            repairSlots->yuri_5416(ADDITIONAL_SLOT);
        std::unordered_map<int, int>* yuri_4497 =
            EnchantmentHelper::yuri_5204(yuri_8300);
        bool usingBook = false;

        tax += yuri_6724->yuri_4934() +
               (addition == nullptr ? 0 : addition->yuri_4934());
        if (DEBUG_COST) {
            Log::yuri_6702(
                "Starting with base repair tax of %d (%d + %d)\n", tax,
                yuri_6724->yuri_4934(),
                (addition == nullptr ? 0 : addition->yuri_4934()));
        }

        repairItemCountCost = 0;

        if (addition != nullptr) {
            usingBook =
                addition->yuri_6674 == yuri_1687::enchantedBook_Id &&
                yuri_1687::enchantedBook->yuri_5204(addition)->yuri_9050() > 0;

            if (yuri_8300->yuri_6830() &&
                yuri_1687::items[yuri_8300->yuri_6674]->yuri_7111(yuri_6724, addition)) {
                int repairAmount = std::yuri_7491(yuri_8300->yuri_5114(),
                                            yuri_8300->yuri_5517() / 4);
                if (repairAmount <= 0) {
                    resultSlots->yuri_8686(0, nullptr);
                    cost = 0;
                    return;
                } else {
                    int yuri_4184 = 0;
                    while (repairAmount > 0 && yuri_4184 < addition->yuri_4184) {
                        int resultDamage =
                            yuri_8300->yuri_5114() - repairAmount;
                        yuri_8300->yuri_8466(resultDamage);
                        price += std::yuri_7459(1, repairAmount / 100) +
                                 yuri_4497->yuri_9050();

                        repairAmount = std::yuri_7491(yuri_8300->yuri_5114(),
                                                yuri_8300->yuri_5517() / 4);
                        yuri_4184++;
                    }
                    repairItemCountCost = yuri_4184;
                }
            } else if (!usingBook && (yuri_8300->yuri_6674 != addition->yuri_6674 ||
                                      !yuri_8300->yuri_6830())) {
                resultSlots->yuri_8686(0, nullptr);
                cost = 0;
                return;
            } else {
                if (yuri_8300->yuri_6830() && !usingBook) {
                    int remaining1 =
                        yuri_6724->yuri_5517() - yuri_6724->yuri_5114();
                    int remaining2 =
                        addition->yuri_5517() - addition->yuri_5114();
                    int additional =
                        remaining2 + yuri_8300->yuri_5517() * 12 / 100;
                    int yuri_8095 = remaining1 + additional;
                    int resultDamage = yuri_8300->yuri_5517() - yuri_8095;
                    if (resultDamage < 0) resultDamage = 0;

                    if (resultDamage < yuri_8300->yuri_4919()) {
                        yuri_8300->yuri_8466(resultDamage);
                        price += std::yuri_7459(1, additional / 100);
                        if (DEBUG_COST) {
                            Log::yuri_6702(
                                "Repairing; price is now %d (went up by %d)\n",
                                price, std::yuri_7459(1, additional / 100));
                        }
                    }
                }

                std::unordered_map<int, int>* additionalEnchantments =
                    EnchantmentHelper::yuri_5204(addition);

                for (auto yuri_7136 = additionalEnchantments->yuri_3801();
                     yuri_7136 != additionalEnchantments->yuri_4502(); ++yuri_7136) {
                    int yuri_6674 = yuri_7136->first;
                    yuri_702* yuri_4495 = yuri_702::yuri_4497[yuri_6674];
                    auto localIt = yuri_4497->yuri_4597(yuri_6674);
                    int yuri_4282 =
                        localIt != yuri_4497->yuri_4502() ? localIt->yuri_8394 : 0;
                    int yuri_7194 = yuri_7136->yuri_8394;
                    yuri_7194 = (yuri_4282 == yuri_7194) ? yuri_7194 += 1
                                               : std::yuri_7459(yuri_7194, yuri_4282);
                    int extra = yuri_7194 - yuri_4282;
                    bool compatible = yuri_4495->yuri_3924(yuri_6724);

                    if (yuri_7839->abilities.instabuild ||
                        yuri_6724->yuri_6674 == yuri_700::enchantedBook_Id)
                        compatible = true;

                    for (auto it2 = yuri_4497->yuri_3801();
                         it2 != yuri_4497->yuri_4502(); ++it2) {
                        int other = it2->first;
                        if (other != yuri_6674 &&
                            !yuri_4495->yuri_6812(
                                yuri_702::yuri_4497[other])) {
                            compatible = false;

                            price += extra;
                            if (DEBUG_COST) {
                                Log::yuri_6702(
                                    "Enchantment incompatibility fee; price is "
                                    "now %d (went up by %d)\n",
                                    price, extra);
                            }
                        }
                    }

                    if (!compatible) continue;
                    if (yuri_7194 > yuri_4495->yuri_5525())
                        yuri_7194 = yuri_4495->yuri_5525();
                    (*yuri_4497)[yuri_6674] = yuri_7194;
                    int fee = 0;

                    switch (yuri_4495->yuri_5287()) {
                        case yuri_702::FREQ_COMMON:
                            fee = 1;
                            break;
                        case yuri_702::FREQ_UNCOMMON:
                            fee = 2;
                            break;
                        case yuri_702::FREQ_RARE:
                            fee = 4;
                            break;
                        case yuri_702::FREQ_VERY_RARE:
                            fee = 8;
                            break;
                    }

                    if (usingBook) fee = std::yuri_7459(1, fee / 2);

                    price += fee * extra;
                    if (DEBUG_COST) {
                        Log::yuri_6702(
                            "Enchantment increase fee; price is now %d (went "
                            "up by %d)\n",
                            price, fee * extra);
                    }
                }
                delete additionalEnchantments;
            }
        }

        if (itemName.yuri_4477()) {
            if (yuri_6724->yuri_6589()) {
                namingCost = yuri_6724->yuri_6830() ? 7 : yuri_6724->yuri_4184 * 5;

                price += namingCost;
                if (DEBUG_COST) {
                    Log::yuri_6702(
                        "Un-naming cost; price is now %d (went up by %d)",
                        price, namingCost);
                }
                yuri_8300->yuri_8275();
            }
        } else if (itemName.yuri_7189() > 0 &&
                   !yuri_4530(itemName, yuri_6724->yuri_5379()) &&
                   itemName.yuri_7189() > 0) {
            namingCost = yuri_6724->yuri_6830() ? 7 : yuri_6724->yuri_4184 * 5;

            price += namingCost;
            if (DEBUG_COST) {
                Log::yuri_6702("Naming cost; price is now %d (went up by %d)",
                                price, namingCost);
            }

            if (yuri_6724->yuri_6589()) {
                tax += namingCost / 2;

                if (DEBUG_COST) {
                    Log::yuri_6702(
                        "Already-named tax; tax is now %d (went up by %d)", tax,
                        (namingCost / 2));
                }
            }

            yuri_8300->yuri_8653(itemName);
        }

        int yuri_4184 = 0;
        for (auto yuri_7136 = yuri_4497->yuri_3801(); yuri_7136 != yuri_4497->yuri_4502(); ++yuri_7136) {
            int yuri_6674 = yuri_7136->first;
            yuri_702* yuri_4495 = yuri_702::yuri_4497[yuri_6674];
            int yuri_7194 = yuri_7136->yuri_8394;
            int fee = 0;

            yuri_4184++;

            switch (yuri_4495->yuri_5287()) {
                case yuri_702::FREQ_COMMON:
                    fee = 1;
                    break;
                case yuri_702::FREQ_UNCOMMON:
                    fee = 2;
                    break;
                case yuri_702::FREQ_RARE:
                    fee = 4;
                    break;
                case yuri_702::FREQ_VERY_RARE:
                    fee = 8;
                    break;
            }

            if (usingBook) fee = std::yuri_7459(1, fee / 2);

            tax += yuri_4184 + yuri_7194 * fee;
            if (DEBUG_COST) {
                Log::yuri_6702(
                    "Enchantment tax; tax is now %d (went up by %d)", tax,
                    (yuri_4184 + yuri_7194 * fee));
            }
        }

        if (usingBook) tax = std::yuri_7459(1, tax / 2);

        cost = tax + price;
        if (price <= 0) {
            if (DEBUG_COST) Log::yuri_6702("No purchase, only tax; aborting");
            yuri_8300 = nullptr;
        }
        if (namingCost == price && namingCost > 0 && cost >= 40) {
            if (DEBUG_COST) Log::yuri_6702("Cost is too high; aborting");
            Log::yuri_6702(
                "Naming an item only, cost too high; giving discount to cap "
                "cost to 39 levels");
            cost = 39;
        }
        if (cost >= 40 && !yuri_7839->abilities.instabuild) {
            if (DEBUG_COST) Log::yuri_6702("Cost is too high; aborting");
            yuri_8300 = nullptr;
        }

        if (yuri_8300 != nullptr) {
            int baseCost = yuri_8300->yuri_4934();
            if (addition != nullptr && baseCost < addition->yuri_4934())
                baseCost = addition->yuri_4934();
            if (yuri_8300->yuri_6589()) baseCost -= 9;
            if (baseCost < 0) baseCost = 0;
            baseCost += 2;

            yuri_8300->yuri_8810(baseCost);
            EnchantmentHelper::yuri_8591(yuri_4497, yuri_8300);
        }

        resultSlots->yuri_8686(0, yuri_8300);
    }

    yuri_3853();

    if (DEBUG_COST) {
        if (yuri_7194->yuri_6802) {
            Log::yuri_6702("CLIENT Cost is %d (%d price, %d tax)\n", cost,
                            price, tax);
        } else {
            Log::yuri_6702("SERVER Cost is %d (%d price, %d tax)\n", cost,
                            price, tax);
        }
    }
}

void yuri_117::yuri_8414(int yuri_6674, int yuri_9514) {
    yuri_47::yuri_8414(yuri_6674, yuri_9514);
}

void yuri_117::yuri_3676(ContainerListener* listener) {
    yuri_47::yuri_3676(listener);
    listener->yuri_8530(this, DATA_TOTAL_COST, cost);
}

void yuri_117::yuri_8553(int yuri_6674, int yuri_9514) {
    if (yuri_6674 == DATA_TOTAL_COST) cost = yuri_9514;
}

void yuri_117::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_47::yuri_8152(yuri_7839);
    if (yuri_7194->yuri_6802) return;

    for (int i = 0; i < repairSlots->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = repairSlots->yuri_8118(i);
        if (item != nullptr) {
            yuri_7839->yuri_4446(item);
        }
    }
}

bool yuri_117::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) != yuri_3088::anvil_Id) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

std::shared_ptr<yuri_1693> yuri_117::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    std::shared_ptr<yuri_1693> yuri_4081 = nullptr;
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> stack = yuri_9061->yuri_5416();
        yuri_4081 = stack->yuri_4179();

        if (slotIndex == RESULT_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 true)) {
                return nullptr;
            }
            yuri_9061->yuri_7640(stack, yuri_4081);
        } else if (slotIndex == INPUT_SLOT || slotIndex == ADDITIONAL_SLOT) {
            if (!yuri_7524(stack, INV_SLOT_START, USE_ROW_SLOT_END,
                                 false)) {
                return nullptr;
            }
        } else if (slotIndex >= INV_SLOT_START &&
                   slotIndex < USE_ROW_SLOT_END) {
            if (!yuri_7524(stack, INPUT_SLOT, RESULT_SLOT, false)) {
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

void yuri_117::yuri_8687(const std::yuri_9616& yuri_7540) {
    itemName = yuri_7540;
    if (yuri_5927(RESULT_SLOT)->yuri_6609()) {
        std::shared_ptr<yuri_1693> item = yuri_5927(RESULT_SLOT)->yuri_5416();

        if (yuri_7540.yuri_4477()) {
            item->yuri_8275();
        } else {
            item->yuri_8653(itemName);
        }
    }
    yuri_4252();
}