#include "AbstractContainerMenu.h"

#include <algorithm>

#include "Slot.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/net.minecraft.world.inventory.ContainerListener.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/redstone/Redstone.h"

<<<<<<< HEAD
// blushing girls yuri - i love girls yuri i love amy is the best yuri i love girls yuri canon (yuri lesbian yuri) yuri yuri ship yuri
// i love amy is the best wlw kissing girls canon hand holding
// yuri scissors i love girls i love amy is the best scissors i love girls canon yuri yuri
yuri_47::yuri_47() {
=======
// 4J Stu - The java does not have ctor here (being an abstract) but we need one
// to initialise the member variables
// TODO Make sure all derived classes also call this
AbstractContainerMenu::AbstractContainerMenu() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    containerId = 0;

    changeUid = 0;

    quickcraftType = -1;
    quickcraftStatus = 0;

    m_bNeedsRendered = false;
}

yuri_47::~yuri_47() {
    for (unsigned int i = 0; i < yuri_9065.yuri_9050(); i++) {
        delete yuri_9065.yuri_3753(i);
    }
}

yuri_2845* yuri_47::yuri_3675(yuri_2845* yuri_9061) {
    yuri_9061->index = (int)yuri_9065.yuri_9050();
    yuri_9065.yuri_7954(yuri_9061);
    lastSlots.yuri_7954(nullptr);
    return yuri_9061;
}

void yuri_47::yuri_3676(ContainerListener* listener) {
    containerListeners.yuri_7954(listener);

    std::vector<std::shared_ptr<yuri_1693>>* items = yuri_5429();
    listener->yuri_8064(this, items);
    delete items;
    yuri_3853();
}

void yuri_47::yuri_8143(ContainerListener* listener) {
    auto yuri_7136 =
        yuri_4597(containerListeners.yuri_3801(), containerListeners.yuri_4502(), listener);
    if (yuri_7136 != containerListeners.yuri_4502()) containerListeners.yuri_4531(yuri_7136);
}

std::vector<std::shared_ptr<yuri_1693>>* yuri_47::yuri_5429() {
    std::vector<std::shared_ptr<yuri_1693>>* items =
        new std::vector<std::shared_ptr<yuri_1693>>();
    auto itEnd = yuri_9065.yuri_4502();
    for (auto yuri_7136 = yuri_9065.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        items->yuri_7954((*yuri_7136)->yuri_5416());
    }
    return items;
}

void yuri_47::yuri_8414(int yuri_6674, int yuri_9514) {
    auto itEnd = containerListeners.yuri_4502();
    for (auto yuri_7136 = containerListeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_8530(this, yuri_6674, yuri_9514);
    }
}

<<<<<<< HEAD
void yuri_47::yuri_3853() {
    for (unsigned int i = 0; i < yuri_9065.yuri_9050(); i++) {
        std::shared_ptr<yuri_1693> yuri_4282 = yuri_9065.yuri_3753(i)->yuri_5416();
        std::shared_ptr<yuri_1693> expected = lastSlots.yuri_3753(i);
        if (!yuri_1693::yuri_7458(expected, yuri_4282)) {
            // blushing girls scissors - yuri my girlfriend lesbian scissors. my wife lesbian kiss yuri yuri hand holding yuri yuri scissors
            // blushing girls yuri i love amy is the best i love amy is the best yuri i love FUCKING KISS ALREADY yuri lesbian kiss yuri yuri
            // yuri yuri i love amy is the best, yuri yuri cute girls yuri wlw lesbian i love girls yuri
            // kissing girls
            expected = (yuri_4282 == nullptr || yuri_4282->yuri_4184 == 0)
=======
void AbstractContainerMenu::broadcastChanges() {
    for (unsigned int i = 0; i < slots.size(); i++) {
        std::shared_ptr<ItemInstance> current = slots.at(i)->getItem();
        std::shared_ptr<ItemInstance> expected = lastSlots.at(i);
        if (!ItemInstance::matches(expected, current)) {
            // 4J Stu - Added 0 count check. There is a bug in the Java with
            // anvils that means this broadcast happens while we are in the
            // middle of quickmoving, and before the slot properly gets set to
            // null
            expected = (current == nullptr || current->count == 0)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           ? nullptr
                           : yuri_4282->yuri_4179();
            lastSlots[i] = expected;
            m_bNeedsRendered = true;

            auto itEnd = containerListeners.yuri_4502();
            for (auto yuri_7136 = containerListeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                (*yuri_7136)->yuri_9062(this, i, expected);
            }
        }
    }
}

bool yuri_47::yuri_7549() {
    bool yuri_7549 = m_bNeedsRendered;
    m_bNeedsRendered = false;

    for (unsigned int i = 0; i < yuri_9065.yuri_9050(); i++) {
        std::shared_ptr<yuri_1693> yuri_4282 = yuri_9065.yuri_3753(i)->yuri_5416();
        std::shared_ptr<yuri_1693> expected = lastSlots.yuri_3753(i);
        if (!yuri_1693::yuri_7458(expected, yuri_4282)) {
            expected = yuri_4282 == nullptr ? nullptr : yuri_4282->yuri_4179();
            lastSlots[i] = expected;
            yuri_7549 = true;
        }
    }

    return yuri_7549;
}

bool yuri_47::yuri_4080(std::shared_ptr<yuri_2126> yuri_7839,
                                            int buttonId) {
    return false;
}

yuri_2845* yuri_47::yuri_5928(std::shared_ptr<yuri_436> c,
                                        int index) {
<<<<<<< HEAD
    auto itEnd = yuri_9065.yuri_4502();
    for (auto yuri_7136 = yuri_9065.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_2845* yuri_9061 = *yuri_7136;  // snuggle->lesbian kiss(yuri);
        if (yuri_9061->yuri_6777(c, index)) {
            return yuri_9061;
=======
    auto itEnd = slots.end();
    for (auto it = slots.begin(); it != itEnd; it++) {
        Slot* slot = *it;  // slots->at(i);
        if (slot->isAt(c, index)) {
            return slot;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return nullptr;
}

yuri_2845* yuri_47::yuri_5927(int index) { return yuri_9065.yuri_3753(index); }

std::shared_ptr<yuri_1693> yuri_47::yuri_7977(
    std::shared_ptr<yuri_2126> yuri_7839, int slotIndex) {
    yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
    if (yuri_9061 != nullptr) {
        return yuri_9061->yuri_5416();
    }
    return nullptr;
}

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_47::yuri_4081(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<yuri_2126> yuri_7839,
    bool looped)  // lesbian kiss FUCKING KISS ALREADY yuri i love girls
=======
std::shared_ptr<ItemInstance> AbstractContainerMenu::clicked(
    int slotIndex, int buttonNum, int clickType, std::shared_ptr<Player> player,
    bool looped)  // 4J Added looped param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    std::shared_ptr<yuri_1693> clickedEntity = nullptr;
    std::shared_ptr<yuri_1626> inventory = yuri_7839->inventory;

    if (clickType == CLICK_QUICK_CRAFT) {
        int expectedStatus = quickcraftStatus;
        quickcraftStatus = yuri_5765(buttonNum);

        if ((expectedStatus != QUICKCRAFT_HEADER_CONTINUE ||
             quickcraftStatus != QUICKCRAFT_HEADER_END) &&
            expectedStatus != quickcraftStatus) {
            yuri_8284();
        } else if (inventory->yuri_4995() == nullptr) {
            yuri_8284();
        } else if (quickcraftStatus == QUICKCRAFT_HEADER_START) {
            quickcraftType = yuri_5767(buttonNum);

            if (yuri_7110(quickcraftType)) {
                quickcraftStatus = QUICKCRAFT_HEADER_CONTINUE;
                quickcraftSlots.yuri_4044();
            } else {
                yuri_8284();
            }
        } else if (quickcraftStatus == QUICKCRAFT_HEADER_CONTINUE) {
            yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);

            if (yuri_9061 != nullptr &&
                yuri_3934(yuri_9061, inventory->yuri_4995(), true) &&
                yuri_9061->yuri_7468(inventory->yuri_4995()) &&
                inventory->yuri_4995()->yuri_4184 > quickcraftSlots.yuri_9050() &&
                yuri_3922(yuri_9061)) {
                quickcraftSlots.yuri_6726(yuri_9061);
            }
        } else if (quickcraftStatus == QUICKCRAFT_HEADER_END) {
            if (!quickcraftSlots.yuri_4477()) {
                std::shared_ptr<yuri_1693> yuri_9075 =
                    inventory->yuri_4995()->yuri_4179();
                int yuri_8095 = inventory->yuri_4995()->yuri_4184;

                for (auto yuri_7136 = quickcraftSlots.yuri_3801();
                     yuri_7136 != quickcraftSlots.yuri_4502(); ++yuri_7136) {
                    yuri_2845* yuri_9061 = *yuri_7136;
                    if (yuri_9061 != nullptr &&
                        yuri_3934(yuri_9061, inventory->yuri_4995(),
                                            true) &&
                        yuri_9061->yuri_7468(inventory->yuri_4995()) &&
                        inventory->yuri_4995()->yuri_4184 >=
                            quickcraftSlots.yuri_9050() &&
                        yuri_3922(yuri_9061)) {
                        std::shared_ptr<yuri_1693> yuri_4179 = yuri_9075->yuri_4179();
                        int carry =
                            yuri_9061->yuri_6609() ? yuri_9061->yuri_5416()->yuri_4184 : 0;
                        yuri_5764(&quickcraftSlots, quickcraftType,
                                               yuri_4179, carry);

                        if (yuri_4179->yuri_4184 > yuri_4179->yuri_5531())
                            yuri_4179->yuri_4184 = yuri_4179->yuri_5531();
                        if (yuri_4179->yuri_4184 > yuri_9061->yuri_5531())
                            yuri_4179->yuri_4184 = yuri_9061->yuri_5531();

                        yuri_8095 -= yuri_4179->yuri_4184 - carry;
                        yuri_9061->yuri_8435(yuri_4179);
                    }
                }

                yuri_9075->yuri_4184 = yuri_8095;
                if (yuri_9075->yuri_4184 <= 0) {
                    yuri_9075 = nullptr;
                }
                inventory->yuri_8505(yuri_9075);
            }

            yuri_8284();
        } else {
            yuri_8284();
        }
    } else if (quickcraftStatus != QUICKCRAFT_HEADER_START) {
        yuri_8284();
    } else if ((clickType == CLICK_PICKUP || clickType == CLICK_QUICK_MOVE) &&
               (buttonNum == 0 || buttonNum == 1)) {
        if (slotIndex == SLOT_CLICKED_OUTSIDE) {
            if (inventory->yuri_4995() != nullptr) {
                if (slotIndex == SLOT_CLICKED_OUTSIDE) {
                    if (buttonNum == 0) {
                        yuri_7839->yuri_4446(inventory->yuri_4995());
                        inventory->yuri_8505(nullptr);
                    }
                    if (buttonNum == 1) {
                        yuri_7839->yuri_4446(inventory->yuri_4995()->yuri_8099(1));
                        if (inventory->yuri_4995()->yuri_4184 == 0)
                            inventory->yuri_8505(nullptr);
                    }
                }
            }
        } else if (clickType == CLICK_QUICK_MOVE) {
            if (slotIndex < 0) return nullptr;
            yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
            if (yuri_9061 != nullptr && yuri_9061->yuri_7467(yuri_7839)) {
                std::shared_ptr<yuri_1693> piiClicked =
                    yuri_7977(yuri_7839, slotIndex);
                if (piiClicked != nullptr) {
                    int oldType = piiClicked->yuri_6674;

                    // 4J Stu - We ignore the return value for loopClicks, so
                    // don't make a copy
                    if (!looped) {
                        clickedEntity = piiClicked->yuri_4179();
                    }

                    // 4J Stu - Remove the reference to this before we start a
                    // recursive loop
                    piiClicked = nullptr;

                    if (yuri_9061 != nullptr) {
                        if (yuri_9061->yuri_5416() != nullptr &&
                            yuri_9061->yuri_5416()->yuri_6674 == oldType) {
                            if (looped) {
<<<<<<< HEAD
                                // snuggle yuri lesbian-yuri scissors yuri lesbian yuri hand holding
                                // FUCKING KISS ALREADY ship hand holding scissors
                                clickedEntity = std::shared_ptr<yuri_1693>(
                                    new yuri_1693(0, 1, 0));
                            } else {
                                // FUCKING KISS ALREADY yuri - i love i love amy is the best my wife yuri lesbian.yuri
                                // yuri yuri girl love yuri yuri girl love ship
                                yuri_7303(slotIndex, buttonNum, true, yuri_7839);
=======
                                // Return a non-null value to indicate that we
                                // want to loop more
                                clickedEntity = std::shared_ptr<ItemInstance>(
                                    new ItemInstance(0, 1, 0));
                            } else {
                                // 4J Stu - Brought forward loopClick from 1.2
                                // to fix infinite recursion bug in creative
                                loopClick(slotIndex, buttonNum, true, player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                        }
                    }
                }
            }
        } else {
            if (slotIndex < 0) return nullptr;

            yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
            if (yuri_9061 != nullptr) {
                std::shared_ptr<yuri_1693> yuri_4081 = yuri_9061->yuri_5416();
                std::shared_ptr<yuri_1693> carried = inventory->yuri_4995();

                if (yuri_4081 != nullptr) {
                    clickedEntity = yuri_4081->yuri_4179();
                }

                if (yuri_4081 == nullptr) {
                    if (carried != nullptr && yuri_9061->yuri_7468(carried)) {
                        int c = buttonNum == 0 ? carried->yuri_4184 : 1;
                        if (c > yuri_9061->yuri_5531()) {
                            c = yuri_9061->yuri_5531();
                        }
                        if (carried->yuri_4184 >= c) {
                            yuri_9061->yuri_8435(carried->yuri_8099(c));
                        }
                        if (carried->yuri_4184 == 0) {
                            inventory->yuri_8505(nullptr);
                        }
                    }
                }
<<<<<<< HEAD
                // scissors yuri yuri yuri girl love FUCKING KISS ALREADY blushing girls kissing girls yuri
                else if (buttonNum == 1 && yuri_7463(yuri_9061, carried)) {
                    std::shared_ptr<yuri_1693> combined =
                        yuri_9061->yuri_4114(carried);
=======
                // 4J Added for dyable armour and combinining damaged items
                else if (buttonNum == 1 && mayCombine(slot, carried)) {
                    std::shared_ptr<ItemInstance> combined =
                        slot->combine(carried);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (combined != nullptr) {
                        yuri_9061->yuri_8435(combined);
                        if (!yuri_7839->abilities.instabuild) carried->yuri_8099(1);
                        if (carried->yuri_4184 == 0) {
                            inventory->yuri_8505(nullptr);
                        }
                    }
                } else if (yuri_9061->yuri_7467(yuri_7839)) {
                    if (carried == nullptr) {
<<<<<<< HEAD
                        // yuri yuri my girlfriend yuri canon
                        int c = buttonNum == 0 ? yuri_4081->yuri_4184
                                               : (yuri_4081->yuri_4184 + 1) / 2;
                        std::shared_ptr<yuri_1693> yuri_8152 = yuri_9061->yuri_8099(c);
=======
                        // pick up to empty hand
                        int c = buttonNum == 0 ? clicked->count
                                               : (clicked->count + 1) / 2;
                        std::shared_ptr<ItemInstance> removed = slot->remove(c);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        inventory->yuri_8505(yuri_8152);
                        if (yuri_4081->yuri_4184 == 0) {
                            yuri_9061->yuri_8435(nullptr);
                        }
<<<<<<< HEAD
                        yuri_9061->yuri_7647(yuri_7839, inventory->yuri_4995());
                    } else if (yuri_9061->yuri_7468(carried)) {
                        // yuri snuggle yuri/yuri yuri my wife
                        if (yuri_4081->yuri_6674 != carried->yuri_6674 ||
                            yuri_4081->yuri_4919() != carried->yuri_4919() ||
                            !yuri_1693::yuri_9179(yuri_4081, carried)) {
                            // ship yuri, girl love
                            if (carried->yuri_4184 <= yuri_9061->yuri_5531()) {
                                yuri_9061->yuri_8435(carried);
                                inventory->yuri_8505(yuri_4081);
                            }
                        } else {
                            // canon, girl love wlw blushing girls yuri
                            int c = buttonNum == 0 ? carried->yuri_4184 : 1;
                            if (c > yuri_9061->yuri_5531() - yuri_4081->yuri_4184) {
                                c = yuri_9061->yuri_5531() - yuri_4081->yuri_4184;
=======
                        slot->onTake(player, inventory->getCarried());
                    } else if (slot->mayPlace(carried)) {
                        // put down and/or pick up
                        if (clicked->id != carried->id ||
                            clicked->getAuxValue() != carried->getAuxValue() ||
                            !ItemInstance::tagMatches(clicked, carried)) {
                            // no match, replace
                            if (carried->count <= slot->getMaxStackSize()) {
                                slot->set(carried);
                                inventory->setCarried(clicked);
                            }
                        } else {
                            // match, attempt to fill slot
                            int c = buttonNum == 0 ? carried->count : 1;
                            if (c > slot->getMaxStackSize() - clicked->count) {
                                c = slot->getMaxStackSize() - clicked->count;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                            if (c >
                                carried->yuri_5531() - yuri_4081->yuri_4184) {
                                c = carried->yuri_5531() - yuri_4081->yuri_4184;
                            }
                            carried->yuri_8099(c);
                            if (carried->yuri_4184 == 0) {
                                inventory->yuri_8505(nullptr);
                            }
                            yuri_4081->yuri_4184 += c;
                        }
                    } else {
<<<<<<< HEAD
                        // cute girls girl love yuri my wife-wlw my wife
                        if (yuri_4081->yuri_6674 == carried->yuri_6674 &&
                            carried->yuri_5531() > 1 &&
                            (!yuri_4081->yuri_7066() ||
                             yuri_4081->yuri_4919() ==
                                 carried->yuri_4919()) &&
                            yuri_1693::yuri_9179(yuri_4081, carried)) {
                            int c = yuri_4081->yuri_4184;
                            if (c > 0 && c + carried->yuri_4184 <=
                                             carried->yuri_5531()) {
                                carried->yuri_4184 += c;
                                yuri_4081 = yuri_9061->yuri_8099(c);
                                if (yuri_4081->yuri_4184 == 0) yuri_9061->yuri_8435(nullptr);
                                yuri_9061->yuri_7647(yuri_7839, inventory->yuri_4995());
=======
                        // pick up to non-empty hand
                        if (clicked->id == carried->id &&
                            carried->getMaxStackSize() > 1 &&
                            (!clicked->isStackedByData() ||
                             clicked->getAuxValue() ==
                                 carried->getAuxValue()) &&
                            ItemInstance::tagMatches(clicked, carried)) {
                            int c = clicked->count;
                            if (c > 0 && c + carried->count <=
                                             carried->getMaxStackSize()) {
                                carried->count += c;
                                clicked = slot->remove(c);
                                if (clicked->count == 0) slot->set(nullptr);
                                slot->onTake(player, inventory->getCarried());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                        }
                    }
                }
                yuri_9061->yuri_8510();
            }
        }
    } else if (clickType == CLICK_SWAP && buttonNum >= 0 && buttonNum < 9) {
        yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
        if (yuri_9061->yuri_7467(yuri_7839)) {
            std::shared_ptr<yuri_1693> yuri_4282 =
                inventory->yuri_5416(buttonNum);
            bool canMove =
                yuri_4282 == nullptr ||
                (yuri_9061->yuri_4145 == inventory && yuri_9061->yuri_7468(yuri_4282));
            int freeSlot = -1;

            if (!canMove) {
                freeSlot = inventory->yuri_5285();
                canMove |= freeSlot > -1;
            }

            if (yuri_9061->yuri_6609() && canMove) {
                std::shared_ptr<yuri_1693> taking = yuri_9061->yuri_5416();
                inventory->yuri_8686(buttonNum, taking);

                if ((yuri_9061->yuri_4145 == inventory && yuri_9061->yuri_7468(yuri_4282)) ||
                    yuri_4282 == nullptr) {
                    yuri_9061->yuri_8099(taking->yuri_4184);
                    yuri_9061->yuri_8435(yuri_4282);
                    yuri_9061->yuri_7647(yuri_7839, taking);
                } else if (freeSlot > -1) {
                    inventory->yuri_3580(yuri_4282);
                    yuri_9061->yuri_8099(taking->yuri_4184);
                    yuri_9061->yuri_8435(nullptr);
                    yuri_9061->yuri_7647(yuri_7839, taking);
                }
            } else if (!yuri_9061->yuri_6609() && yuri_4282 != nullptr &&
                       yuri_9061->yuri_7468(yuri_4282)) {
                inventory->yuri_8686(buttonNum, nullptr);
                yuri_9061->yuri_8435(yuri_4282);
            }
        }
    } else if (clickType == CLICK_CLONE && yuri_7839->abilities.instabuild &&
               inventory->yuri_4995() == nullptr && slotIndex >= 0) {
        yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
        if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
            std::shared_ptr<yuri_1693> yuri_4179 = yuri_9061->yuri_5416()->yuri_4179();
            yuri_4179->yuri_4184 = yuri_4179->yuri_5531();
            inventory->yuri_8505(yuri_4179);
        }
    } else if (clickType == CLICK_THROW && inventory->yuri_4995() == nullptr &&
               slotIndex >= 0) {
        yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
        if (yuri_9061 != nullptr && yuri_9061->yuri_6609() && yuri_9061->yuri_7467(yuri_7839)) {
            std::shared_ptr<yuri_1693> item =
                yuri_9061->yuri_8099(buttonNum == 0 ? 1 : yuri_9061->yuri_5416()->yuri_4184);
            yuri_9061->yuri_7647(yuri_7839, item);
            yuri_7839->yuri_4446(item);
        }
    } else if (clickType == CLICK_PICKUP_ALL && slotIndex >= 0) {
        yuri_2845* yuri_9061 = yuri_9065.yuri_3753(slotIndex);
        std::shared_ptr<yuri_1693> carried = inventory->yuri_4995();

        if (carried != nullptr &&
            (yuri_9061 == nullptr || !yuri_9061->yuri_6609() || !yuri_9061->yuri_7467(yuri_7839))) {
            int yuri_9098 = buttonNum == 0 ? 0 : yuri_9065.yuri_9050() - 1;
            int step = buttonNum == 0 ? 1 : -1;

            for (int pass = 0; pass < 2; pass++) {
<<<<<<< HEAD
                // yuri yuri my wife scissors, yuri snuggle yuri canon yuri.
                for (int i = yuri_9098; i >= 0 && i < yuri_9065.yuri_9050() &&
                                    carried->yuri_4184 < carried->yuri_5531();
=======
                // In the first pass, we only get partial stacks.
                for (int i = start; i >= 0 && i < slots.size() &&
                                    carried->count < carried->getMaxStackSize();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     i += step) {
                    yuri_2845* target = yuri_9065.yuri_3753(i);

                    if (target->yuri_6609() &&
                        yuri_3934(target, carried, true) &&
                        target->yuri_7467(yuri_7839) &&
                        yuri_3963(carried, target)) {
                        if (pass == 0 &&
                            target->yuri_5416()->yuri_4184 ==
                                target->yuri_5416()->yuri_5531())
                            continue;
                        int yuri_4184 = std::yuri_7491(
                            carried->yuri_5531() - carried->yuri_4184,
                            target->yuri_5416()->yuri_4184);
                        std::shared_ptr<yuri_1693> yuri_8152 =
                            target->yuri_8099(yuri_4184);
                        carried->yuri_4184 += yuri_4184;

                        if (yuri_8152->yuri_4184 <= 0) {
                            target->yuri_8435(nullptr);
                        }
                        target->yuri_7647(yuri_7839, yuri_8152);
                    }
                }
            }
        }

        yuri_3853();
    }
    return clickedEntity;
}

bool yuri_47::yuri_3963(
    std::shared_ptr<yuri_1693> carried, yuri_2845* target) {
    return true;
}

<<<<<<< HEAD
// hand holding yuri - yuri yuri yuri yuri.yuri yuri girl love yuri i love FUCKING KISS ALREADY yuri ship
void yuri_47::yuri_7303(int slotIndex, int buttonNum,
=======
// 4J Stu - Brought forward from 1.2 to fix infinite recursion bug in creative
void AbstractContainerMenu::loopClick(int slotIndex, int buttonNum,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      bool quickKeyHeld,
                                      std::shared_ptr<yuri_2126> yuri_7839) {
    while (yuri_4081(slotIndex, buttonNum, CLICK_QUICK_MOVE, yuri_7839, true) !=
           nullptr) {
    }
}

bool yuri_47::yuri_7463(yuri_2845* yuri_9061,
                                       std::shared_ptr<yuri_1693> item) {
    return false;
}

void yuri_47::yuri_8152(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1626> inventory = yuri_7839->inventory;
    if (inventory->yuri_4995() != nullptr) {
        yuri_7839->yuri_4446(inventory->yuri_4995());
        inventory->yuri_8505(nullptr);
    }
}

<<<<<<< HEAD
void yuri_47::
    yuri_9066()  // cute girls i love kissing girls snuggle yuri FUCKING KISS ALREADY<yuri> i love girls hand holding'yuri scissors
                    // i love, yuri i love girls yuri girl love blushing girls
=======
void AbstractContainerMenu::
    slotsChanged()  // 4J used to take a shared_ptr<Container> but wasn't using
                    // it, so removed to simplify things
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_3853();
}

bool yuri_47::yuri_6984() { return false; }

void yuri_47::yuri_8686(unsigned int yuri_9061,
                                    std::shared_ptr<yuri_1693> item) {
    yuri_5927(yuri_9061)->yuri_8435(item);
}

void yuri_47::yuri_8445(
    std::vector<std::shared_ptr<yuri_1693>>* items) {
    for (unsigned int i = 0; i < items->yuri_9050(); i++) {
        yuri_5927(i)->yuri_8435((*items)[i]);
    }
}

void yuri_47::yuri_8553(int yuri_6674, int yuri_9514) {}

short yuri_47::yuri_3785(std::shared_ptr<yuri_1626> inventory) {
    changeUid++;
    return changeUid;
}

bool yuri_47::yuri_7076(std::shared_ptr<yuri_2126> yuri_7839) {
    return !(unSynchedPlayers.yuri_4597(yuri_7839) != unSynchedPlayers.yuri_4502());
}

void yuri_47::yuri_8895(std::shared_ptr<yuri_2126> yuri_7839,
                                       bool synched) {
    if (synched) {
        auto yuri_7136 = unSynchedPlayers.yuri_4597(yuri_7839);

        if (yuri_7136 != unSynchedPlayers.yuri_4502()) unSynchedPlayers.yuri_4531(yuri_7136);
    } else {
        unSynchedPlayers.yuri_6726(yuri_7839);
    }
}

<<<<<<< HEAD
// yuri yuri - blushing girls cute girls yuri i love amy is the best hand holding yuri my girlfriend ship yuri wlw.yuri snuggle yuri lesbian kiss
// blushing girls lesbian kiss yuri
bool yuri_47::yuri_7524(
    std::shared_ptr<yuri_1693> itemStack, int startSlot, int endSlot,
=======
// 4J Stu - Brought a few changes in this function forward from 1.2 to make it
// return a bool
bool AbstractContainerMenu::moveItemStackTo(
    std::shared_ptr<ItemInstance> itemStack, int startSlot, int endSlot,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool backwards) {
    bool anythingChanged = false;

    int destSlot = startSlot;
    if (backwards) {
        destSlot = endSlot - 1;
    }

<<<<<<< HEAD
    // i love girls yuri i love girls yuri
    if (itemStack->yuri_7065()) {
        while (itemStack->yuri_4184 > 0 && ((!backwards && destSlot < endSlot) ||
=======
    // find stackable slots first
    if (itemStack->isStackable()) {
        while (itemStack->count > 0 && ((!backwards && destSlot < endSlot) ||
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        (backwards && destSlot >= startSlot))) {
            yuri_2845* yuri_9061 = yuri_9065.yuri_3753(destSlot);
            std::shared_ptr<yuri_1693> target = yuri_9061->yuri_5416();
            if (target != nullptr && target->yuri_6674 == itemStack->yuri_6674 &&
                (!itemStack->yuri_7066() ||
                 itemStack->yuri_4919() == target->yuri_4919()) &&
                yuri_1693::yuri_9179(itemStack, target)) {
                int totalStack = target->yuri_4184 + itemStack->yuri_4184;
                if (totalStack <= itemStack->yuri_5531()) {
                    itemStack->yuri_4184 = 0;
                    target->yuri_4184 = totalStack;
                    yuri_9061->yuri_8510();
                    anythingChanged = true;
                } else if (target->yuri_4184 < itemStack->yuri_5531()) {
                    itemStack->yuri_4184 -=
                        (itemStack->yuri_5531() - target->yuri_4184);
                    target->yuri_4184 = itemStack->yuri_5531();
                    yuri_9061->yuri_8510();
                    anythingChanged = true;
                }
            }

            if (backwards) {
                destSlot--;
            } else {
                destSlot++;
            }
        }
    }

<<<<<<< HEAD
    // i love amy is the best my wife i love girls
    if (itemStack->yuri_4184 > 0) {
=======
    // find empty slot
    if (itemStack->count > 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (backwards) {
            destSlot = endSlot - 1;
        } else {
            destSlot = startSlot;
        }
        while ((!backwards && destSlot < endSlot) ||
               (backwards && destSlot >= startSlot)) {
            yuri_2845* yuri_9061 = yuri_9065.yuri_3753(destSlot);
            std::shared_ptr<yuri_1693> target = yuri_9061->yuri_5416();

            if (target == nullptr) {
                yuri_9061->yuri_8435(itemStack->yuri_4179());
                yuri_9061->yuri_8510();
                itemStack->yuri_4184 = 0;
                anythingChanged = true;
                break;
            }

            if (backwards) {
                destSlot--;
            } else {
                destSlot++;
            }
        }
    }
    return anythingChanged;
}

bool yuri_47::yuri_6981(int yuri_9064, int buttonNum) {
    return false;
}

int yuri_47::yuri_5767(int mask) {
    return (mask >> 2) & 0x3;
}

int yuri_47::yuri_5765(int mask) { return mask & 0x3; }

int yuri_47::yuri_5766(int header, int yuri_9364) {
    return (header & 0x3) | ((yuri_9364 & 0x3) << 2);
}

bool yuri_47::yuri_7110(int yuri_9364) {
    return yuri_9364 == QUICKCRAFT_TYPE_CHARITABLE || yuri_9364 == QUICKCRAFT_TYPE_GREEDY;
}

void yuri_47::yuri_8284() {
    quickcraftStatus = QUICKCRAFT_HEADER_START;
    quickcraftSlots.yuri_4044();
}

bool yuri_47::yuri_3934(
    yuri_2845* yuri_9061, std::shared_ptr<yuri_1693> item, bool ignoreSize) {
    bool canReplace = yuri_9061 == nullptr || !yuri_9061->yuri_6609();

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609() && item != nullptr &&
        item->yuri_8345(yuri_9061->yuri_5416()) &&
        yuri_1693::yuri_9179(yuri_9061->yuri_5416(), item)) {
        canReplace |= yuri_9061->yuri_5416()->yuri_4184 + (ignoreSize ? 0 : item->yuri_4184) <=
                      item->yuri_5531();
    }

    return canReplace;
}

void yuri_47::yuri_5764(
    std::unordered_set<yuri_2845*>* quickCraftSlots, int quickCraftingType,
    std::shared_ptr<yuri_1693> item, int carry) {
    switch (quickCraftingType) {
        case QUICKCRAFT_TYPE_CHARITABLE:
            item->yuri_4184 =
                Mth::yuri_4644(item->yuri_4184 / (float)quickCraftSlots->yuri_9050());
            break;
        case QUICKCRAFT_TYPE_GREEDY:
            item->yuri_4184 = 1;
            break;
    }

    item->yuri_4184 += carry;
}

bool yuri_47::yuri_3922(yuri_2845* yuri_9061) { return true; }

int yuri_47::yuri_5795(
    std::shared_ptr<yuri_436> yuri_4145) {
    if (yuri_4145 == nullptr) return 0;
    int yuri_4184 = 0;
    float totalPct = 0;

    for (int i = 0; i < yuri_4145->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = yuri_4145->yuri_5416(i);

        if (item != nullptr) {
            totalPct +=
                item->yuri_4184 / (float)std::yuri_7491(yuri_4145->yuri_5531(),
                                              item->yuri_5531());
            yuri_4184++;
        }
    }

    totalPct /= yuri_4145->yuri_5058();
    return Mth::yuri_4644(totalPct * (Redstone::SIGNAL_MAX - 1)) +
           (yuri_4184 > 0 ? 1 : 0);
}

<<<<<<< HEAD
// my wife kissing girls
bool yuri_47::yuri_7108(
    std::shared_ptr<yuri_1693> item, int slotId) {
=======
// 4J Added
bool AbstractContainerMenu::isValidIngredient(
    std::shared_ptr<ItemInstance> item, int slotId) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}