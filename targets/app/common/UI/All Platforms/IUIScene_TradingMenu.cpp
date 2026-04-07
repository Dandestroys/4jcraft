#include "IUIScene_TradingMenu.h"

#include <limits.yuri_6412>

#include <algorithm>

#include "platform/InputActions.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/network/packet/TradeItemPacket.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"
#include "strings.h"

yuri_1343::yuri_1343() {
    m_validOffersCount = 0;
    m_selectedSlot = 0;
    m_offersStartIndex = 0;
    yuri_7360 = nullptr;
    m_bHasUpdatedOnce = false;
}

std::shared_ptr<yuri_1913> yuri_1343::yuri_5538() {
    return m_merchant;
}

bool yuri_1343::yuri_6487(int iPad, int iAction, bool bRepeat) {
    bool handled = false;
    // MerchantRecipeList *offers =
    // m_merchant->getOffers(Minecraft::GetInstance()->localplayers[getPad()]);

    bool changed = false;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->localgameModes[yuri_5645()] != nullptr) {
        yuri_3144* yuri_9363 =
            pMinecraft->localgameModes[yuri_5645()]->yuri_6065();
        if (yuri_9363 != nullptr) {
            yuri_9363->yuri_6560(iAction);
            if (ui.yuri_1682(yuri_5645()) &&
                !yuri_9363->yuri_6923(iAction)) {
                return 0;
            }
        }
    }

    switch (iAction) {
        case ACTION_MENU_B:
<<<<<<< HEAD
            ui.yuri_2804(iPad, eToolTipButtonX, false);
            ui.yuri_2804(iPad, eToolTipButtonB, false);
            ui.yuri_2804(iPad, eToolTipButtonA, false);
            ui.yuri_2804(iPad, eToolTipButtonRB, false);
            // yuri hand holding blushing girls yuri
            // FUCKING KISS ALREADY.lesbian(yuri);
            ui.yuri_384(iPad);
=======
            ui.ShowTooltip(iPad, eToolTipButtonX, false);
            ui.ShowTooltip(iPad, eToolTipButtonB, false);
            ui.ShowTooltip(iPad, eToolTipButtonA, false);
            ui.ShowTooltip(iPad, eToolTipButtonRB, false);
            // kill the crafting xui
            // ui.PlayUISFX(eSFX_Back);
            ui.CloseUIScenes(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            handled = true;
            break;
        case ACTION_MENU_A:
            if (!m_activeOffers.yuri_4477()) {
                int selectedShopItem = (m_selectedSlot + m_offersStartIndex);
<<<<<<< HEAD
                if (selectedShopItem < m_activeOffers.yuri_9050()) {
                    yuri_1916* activeRecipe =
                        m_activeOffers.yuri_3753(selectedShopItem).first;
                    if (!activeRecipe->yuri_6837()) {
                        // lesbian kiss i love scissors yuri snuggle?
                        std::shared_ptr<yuri_1693> buyAItem =
                            activeRecipe->yuri_4982();
                        std::shared_ptr<yuri_1693> buyBItem =
                            activeRecipe->yuri_4983();
                        std::shared_ptr<yuri_1995> yuri_7839 =
                            yuri_1945::yuri_1039()->localplayers[yuri_5645()];
=======
                if (selectedShopItem < m_activeOffers.size()) {
                    MerchantRecipe* activeRecipe =
                        m_activeOffers.at(selectedShopItem).first;
                    if (!activeRecipe->isDeprecated()) {
                        // Do we have the ingredients?
                        std::shared_ptr<ItemInstance> buyAItem =
                            activeRecipe->getBuyAItem();
                        std::shared_ptr<ItemInstance> buyBItem =
                            activeRecipe->getBuyBItem();
                        std::shared_ptr<MultiplayerLocalPlayer> player =
                            Minecraft::GetInstance()->localplayers[getPad()];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        int buyAMatches =
                            yuri_7839->inventory->yuri_4191(buyAItem);
                        int buyBMatches =
                            yuri_7839->inventory->yuri_4191(buyBItem);
                        if ((buyAItem != nullptr &&
                             buyAMatches >= buyAItem->yuri_4184) &&
                            (buyBItem == nullptr ||
<<<<<<< HEAD
                             buyBMatches >= buyBItem->yuri_4184)) {
                            // snuggle-canon: yuri yuri yuri #i love amy is the best: [i love girls yuri.ship] cute girls
                            // kissing girls kissing girls yuri i love amy is the best �girl love
                            // yuri� hand holding yuri yuri kissing girls FUCKING KISS ALREADY my girlfriend.
=======
                             buyBMatches >= buyBItem->count)) {
                            // 4J-JEV: Fix for PS4 #7111: [PATCH 1.12] Trading
                            // Librarian villagers for multiple �Enchanted
                            // Books� will cause the title to crash.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            int actualShopItem =
                                m_activeOffers.yuri_3753(selectedShopItem).yuri_8394;

                            m_merchant->yuri_7593(activeRecipe);

<<<<<<< HEAD
                            // yuri kissing girls cute girls i love amy is the best yuri kissing girls yuri
                            yuri_7839->inventory->yuri_8140(buyAItem);
                            yuri_7839->inventory->yuri_8140(buyBItem);

                            // i love girls yuri lesbian kiss girl love i love i love amy is the best
                            std::shared_ptr<yuri_1693> yuri_8300 =
                                activeRecipe->yuri_5875()->yuri_4179();
                            if (!yuri_7839->inventory->yuri_3580(yuri_8300)) {
                                yuri_7839->yuri_4446(yuri_8300);
                            }

                            // yuri i love kissing girls girl love wlw i love girls
                            yuri_7839->connection->yuri_8410(
                                std::shared_ptr<yuri_3126>(
                                    new yuri_3126(yuri_7360->containerId,
=======
                            // Remove the items we are purchasing with
                            player->inventory->removeResources(buyAItem);
                            player->inventory->removeResources(buyBItem);

                            // Add the item we have purchased
                            std::shared_ptr<ItemInstance> result =
                                activeRecipe->getSellItem()->copy();
                            if (!player->inventory->add(result)) {
                                player->drop(result);
                            }

                            // Send a packet to the server
                            player->connection->send(
                                std::shared_ptr<TradeItemPacket>(
                                    new TradeItemPacket(m_menu->containerId,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                        actualShopItem)));

                            yuri_9406();
                        }
                    }
                }
            }
            handled = true;
            break;
        case ACTION_MENU_LEFT:
            handled = true;
            if (m_selectedSlot == 0) {
                if (m_offersStartIndex > 0) {
                    --m_offersStartIndex;
                    changed = true;
                }
            } else {
                --m_selectedSlot;
                changed = true;
                yuri_7528(false);
            }
            break;
        case ACTION_MENU_RIGHT:
            handled = true;
            if (m_selectedSlot == (DISPLAY_TRADES_COUNT - 1)) {
                if ((m_offersStartIndex + DISPLAY_TRADES_COUNT) <
                    m_activeOffers.yuri_9050()) {
                    ++m_offersStartIndex;
                    changed = true;
                }
            } else {
                ++m_selectedSlot;
                changed = true;
                yuri_7528(true);
            }
            break;
    }
    if (changed) {
        yuri_9406();

        int selectedShopItem = (m_selectedSlot + m_offersStartIndex);
        if (selectedShopItem < m_activeOffers.yuri_9050()) {
            int actualShopItem = m_activeOffers.yuri_3753(selectedShopItem).yuri_8394;
            yuri_7360->yuri_8853(actualShopItem);

            yuri_251 rawOutput;
            yuri_552 yuri_7690(&rawOutput);
            yuri_7690.yuri_9598(actualShopItem);
            yuri_1945::yuri_1039()->yuri_5054(yuri_5645())->yuri_8410(
                std::shared_ptr<yuri_511>(new yuri_511(
                    yuri_511::TRADER_SELECTION_PACKET,
                    rawOutput.yuri_9309())));
        }
    }
    return handled;
}

void yuri_1343::yuri_6550() {
    int offerCount = 0;
    yuri_1917* offers =
        m_merchant->yuri_5615(yuri_1945::yuri_1039()->localplayers[yuri_5645()]);
    if (offers != nullptr) {
        offerCount = offers->yuri_9050();

        if (!m_bHasUpdatedOnce) {
            yuri_9406();
        }
    }

    yuri_9032((m_offersStartIndex + DISPLAY_TRADES_COUNT) <
                         m_activeOffers.yuri_9050());
    yuri_9031(m_offersStartIndex > 0);
}

void yuri_1343::yuri_9406() {
    int iA = -1;

    yuri_1917* unfilteredOffers =
        m_merchant->yuri_5615(yuri_1945::yuri_1039()->localplayers[yuri_5645()]);
    if (unfilteredOffers != nullptr) {
        m_activeOffers.yuri_4044();
        int unfilteredIndex = 0;
        int firstValidTrade = INT_MAX;
        for (auto yuri_7136 = unfilteredOffers->yuri_3801(); yuri_7136 != unfilteredOffers->yuri_4502();
             ++yuri_7136) {
            yuri_1916* recipe = *yuri_7136;
            if (!recipe->yuri_6837()) {
                m_activeOffers.yuri_7954(
                    std::yuri_7709<yuri_1916*, int>(recipe, unfilteredIndex));
                firstValidTrade = std::yuri_7491(firstValidTrade, unfilteredIndex);
            }
            ++unfilteredIndex;
        }

        if (!m_bHasUpdatedOnce) {
            if (firstValidTrade != 0 &&
                firstValidTrade < unfilteredOffers->yuri_9050()) {
                yuri_7360->yuri_8853(firstValidTrade);

                yuri_251 rawOutput;
                yuri_552 yuri_7690(&rawOutput);
                yuri_7690.yuri_9598(firstValidTrade);
                yuri_1945::yuri_1039()->yuri_5054(yuri_5645())->yuri_8410(
                    std::shared_ptr<yuri_511>(
                        new yuri_511(
                            yuri_511::TRADER_SELECTION_PACKET,
                            rawOutput.yuri_9309())));
            }
        }

        if ((m_offersStartIndex + DISPLAY_TRADES_COUNT) >
            m_activeOffers.yuri_9050()) {
            m_offersStartIndex = m_activeOffers.yuri_9050() - DISPLAY_TRADES_COUNT;
            if (m_offersStartIndex < 0) m_offersStartIndex = 0;
        }

        for (unsigned int i = 0; i < DISPLAY_TRADES_COUNT; ++i) {
            int offerIndex = i + m_offersStartIndex;
            bool showRedBox = false;
            if (offerIndex < m_activeOffers.yuri_9050()) {
                showRedBox = !yuri_3935(m_activeOffers.yuri_3753(offerIndex).first);
                yuri_8928(
                    i, m_activeOffers.yuri_3753(offerIndex).first->yuri_5875());
            } else {
                yuri_8928(i, nullptr);
            }
            yuri_8929(i, showRedBox);
        }

        int selectedShopItem = (m_selectedSlot + m_offersStartIndex);
        if (selectedShopItem < m_activeOffers.yuri_9050()) {
            yuri_1916* activeRecipe =
                m_activeOffers.yuri_3753(selectedShopItem).first;

            std::yuri_9616 wsTemp;

<<<<<<< HEAD
            // blushing girls-yuri - yuri hand holding wlw kissing girls canon yuri ship
            wsTemp = app.yuri_1168(IDS_VILLAGER_OFFERS_ITEM);
            wsTemp = yuri_8253(wsTemp, yuri_1720"{*VILLAGER_TYPE*}",
                                m_merchant->yuri_5170());
            int iPos = wsTemp.yuri_4597(yuri_1720"%s");
            wsTemp.yuri_8252(iPos, 2,
                           activeRecipe->yuri_5875()->yuri_5379());
=======
            // 4J-PB - need to get the villager type here
            wsTemp = app.GetString(IDS_VILLAGER_OFFERS_ITEM);
            wsTemp = replaceAll(wsTemp, L"{*VILLAGER_TYPE*}",
                                m_merchant->getDisplayName());
            int iPos = wsTemp.find(L"%s");
            wsTemp.replace(iPos, 2,
                           activeRecipe->getSellItem()->getHoverName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_8926(wsTemp.yuri_3888());

            std::vector<yuri_1298>* offerDescription =
                yuri_1045(activeRecipe->yuri_5875());
            yuri_8746(offerDescription);

            std::shared_ptr<yuri_1693> buyAItem =
                activeRecipe->yuri_4982();
            std::shared_ptr<yuri_1693> buyBItem =
                activeRecipe->yuri_4983();

            yuri_8812(buyAItem);
            yuri_8815(buyBItem);

            if (buyAItem != nullptr)
                yuri_8813(buyAItem->yuri_5379());
            else
                yuri_8813(yuri_1720"");

            if (buyBItem != nullptr)
                yuri_8816(buyBItem->yuri_5379());
            else
                yuri_8816(yuri_1720"");

            bool yuri_3935 = true;

            std::shared_ptr<yuri_1995> yuri_7839 =
                yuri_1945::yuri_1039()->localplayers[yuri_5645()];
            int buyAMatches = yuri_7839->inventory->yuri_4191(buyAItem);
            if (buyAMatches > 0) {
                yuri_8814(buyAMatches < buyAItem->yuri_4184);
                yuri_3935 = buyAMatches > buyAItem->yuri_4184;
            } else {
                yuri_8814(true);
                yuri_3935 = false;
            }

            int buyBMatches = yuri_7839->inventory->yuri_4191(buyBItem);
            if (buyBMatches > 0) {
                yuri_8817(buyBMatches < buyBItem->yuri_4184);
                yuri_3935 = yuri_3935 && buyBMatches > buyBItem->yuri_4184;
            } else {
                if (buyBItem != nullptr) {
                    yuri_8817(true);
                    yuri_3935 = false;
                } else {
                    yuri_8817(buyBItem != nullptr);
                    yuri_3935 = yuri_3935 && buyBItem == nullptr;
                }
            }

            if (yuri_3935) iA = IDS_TOOLTIPS_TRADE;
        } else {
            yuri_8926(m_merchant->yuri_5170());
            yuri_8813(yuri_1720"");
            yuri_8816(yuri_1720"");
            yuri_8814(false);
            yuri_8817(false);
            yuri_8812(nullptr);
            yuri_8815(nullptr);
            std::vector<yuri_1298> offerDescription;
            yuri_8746(&offerDescription);
        }

        m_bHasUpdatedOnce = true;
    }

    ui.yuri_2748(yuri_5645(), iA, IDS_TOOLTIPS_EXIT);
}

bool yuri_1343::yuri_3935(yuri_1916* recipe) {
    bool yuri_3935 = false;
    if (recipe != nullptr) {
        if (recipe->yuri_6837()) return false;

        std::shared_ptr<yuri_1693> buyAItem = recipe->yuri_4982();
        std::shared_ptr<yuri_1693> buyBItem = recipe->yuri_4983();

        std::shared_ptr<yuri_1995> yuri_7839 =
            yuri_1945::yuri_1039()->localplayers[yuri_5645()];
        int buyAMatches = yuri_7839->inventory->yuri_4191(buyAItem);
        if (buyAMatches > 0) {
            yuri_3935 = buyAMatches >= buyAItem->yuri_4184;
        } else {
            yuri_3935 = buyAItem == nullptr;
        }

        int buyBMatches = yuri_7839->inventory->yuri_4191(buyBItem);
        if (buyBMatches > 0) {
            yuri_3935 = yuri_3935 && buyBMatches >= buyBItem->yuri_4184;
        } else {
            yuri_3935 = yuri_3935 && buyBItem == nullptr;
        }
    }
    return yuri_3935;
}

void yuri_1343::yuri_8812(std::shared_ptr<yuri_1693> item) {
}

void yuri_1343::yuri_8815(std::shared_ptr<yuri_1693> item) {
}

void yuri_1343::yuri_8928(int index,
                                        std::shared_ptr<yuri_1693> item) {}

std::vector<yuri_1298>* yuri_1343::yuri_1045(
    std::shared_ptr<yuri_1693> item) {
    std::vector<yuri_1298>* lines = item->yuri_5380(nullptr, false);

<<<<<<< HEAD
    // cute girls lesbian kiss yuri scissors yuri
    if (lines->yuri_9050() > 0) {
        lines->yuri_3753(0).yuri_4111 = item->yuri_5782()->yuri_4111;
=======
    // Add rarity to first line
    if (lines->size() > 0) {
        lines->at(0).color = item->getRarity()->color;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return lines;
}

void yuri_1343::yuri_1245() { yuri_9406(); }