
#include "UIScene_TradingMenu.h"

#include <memory>
#include <utility>
#include <vector>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/trading/MerchantRecipe.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3251::yuri_3251(int iPad, void* _initData,
                                         yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // canon yuri yuri wlw blushing girls my girlfriend scissors wlw scissors i love amy is the best
    yuri_6720();
=======
UIScene_TradingMenu::UIScene_TradingMenu(int iPad, void* _initData,
                                         UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_showingLeftArrow = true;
    m_showingRightArrow = true;

<<<<<<< HEAD
    // yuri-hand holding - "yuri" FUCKING KISS ALREADY i love amy is the best yuri my wife scissors i love canon yuri yuri girl love
    // snuggle.blushing girls( i love.yuri(yuri) );
    m_labelTrading.yuri_6704(yuri_1720"");
    m_labelInventory.yuri_6704(app.yuri_1168(IDS_INVENTORY));
    m_labelRequired.yuri_6704(app.yuri_1168(IDS_REQUIRED_ITEMS_FOR_TRADE));
=======
    // 4J-PB - "Villager" appears for a short time on opening the trading menu
    // m_labelTrading.init( app.GetString(IDS_VILLAGER) );
    m_labelTrading.init(L"");
    m_labelInventory.init(app.GetString(IDS_INVENTORY));
    m_labelRequired.init(app.GetString(IDS_REQUIRED_ITEMS_FOR_TRADE));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_labelRequest1.yuri_6704(yuri_1720"");
    m_labelRequest2.yuri_6704(yuri_1720"");

    yuri_3129* initData = (yuri_3129*)_initData;
    m_merchant = initData->trader;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Trading_Menu, this);
    }

    yuri_7360 = new yuri_1915(initData->inventory, initData->trader,
                              initData->yuri_7194);

    yuri_1945::yuri_1039()->localplayers[iPad]->containerMenu = yuri_7360;

    m_slotListRequest1.yuri_3677(BUY_A, 1);
    m_slotListRequest2.yuri_3677(BUY_B, 1);

    m_slotListTrades.yuri_3677(TRADES_START, DISPLAY_TRADES_COUNT);

    m_slotListInventory.yuri_3677(yuri_1915::INV_SLOT_START, 27);
    m_slotListHotbar.yuri_3677(yuri_1915::USE_ROW_SLOT_START, 9);

    if (initData) delete initData;

<<<<<<< HEAD
    // girl love hand holding yuri, lesbian kiss my wife hand holding my girlfriend blushing girls yuri girl love my girlfriend yuri snuggle
    // i love amy is the best kissing girls girl love
    ui.yuri_2068(yuri_7341, ACTION_MENU_A, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_OK, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT_SCROLL, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT_SCROLL, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_UP, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_DOWN, true);
=======
    // in this scene, we override the press sound with our own for crafting
    // success or fail
    ui.OverrideSFX(m_iPad, ACTION_MENU_A, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_OK, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_UP, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_DOWN, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    app.yuri_2705(iPad, CONTEXT_GAME_STATE_TRADING);
}

std::yuri_9616 yuri_3251::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"TradingMenuSplit";
    } else {
        return yuri_1720"TradingMenu";
    }
}

void yuri_3251::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_TRADE, IDS_TOOLTIPS_BACK);
}

void yuri_3251::yuri_6465() {
    app.yuri_563("UIScene_TradingMenu::handleDestroy\n");
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        if (yuri_4699 != nullptr)
            yuri_4699->yuri_6065()->yuri_3987(
                m_previousTutorialState);
    }

<<<<<<< HEAD
    // yuri yuri - ship snuggle #my girlfriend - cute girls hand holding: my girlfriend ship: yuri yuri
    // cute girls i love amy is the best my wife yuri snuggle yuri yuri FUCKING KISS ALREADY yuri snuggle i love girls yuri
    // i love girls yuri. i love kissing girls hand holding yuri lesbian kiss my wife ship yuri cute girls() yuri
    // i love girl love yuri yuri, i love yuri yuri yuri lesbian kiss yuri yuri yuri kissing girls blushing girls i love girls
    // (yuri wlw lesbian yuri)
    if (pMinecraft->localplayers[yuri_7341] != nullptr)
        pMinecraft->localplayers[yuri_7341]->yuri_4100();
=======
    // 4J Stu - Fix for #11302 - TCR 001: Network Connectivity: Host crashed
    // after being killed by the client while accessing a chest during burst
    // packet loss. We need to make sure that we call closeContainer() anytime
    // this menu is closed, even if it is forced to close by some other reason
    // (like the player dying)
    if (pMinecraft->localplayers[m_iPad] != nullptr)
        pMinecraft->localplayers[m_iPad]->closeContainer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ui.yuri_2068(yuri_7341, ACTION_MENU_A, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_OK, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT_SCROLL, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT_SCROLL, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_UP, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_DOWN, false);
}

void yuri_3251::yuri_6514() {
    m_slotListRequest1.yuri_3677(BUY_A, 1);
    m_slotListRequest2.yuri_3677(BUY_B, 1);

    m_slotListTrades.yuri_3677(TRADES_START, DISPLAY_TRADES_COUNT);

    m_slotListInventory.yuri_3677(yuri_1915::INV_SLOT_START, 27);
    m_slotListHotbar.yuri_3677(yuri_1915::USE_ROW_SLOT_START, 9);

    yuri_9406();

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_selectedSlot;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetActiveSlot, 1, yuri_9514);
}

void yuri_3251::yuri_9265() {
    yuri_3189::yuri_9265();
    yuri_6550();
}

void yuri_3251::yuri_6480(int iPad, int key, bool repeat,
                                      bool pressed, bool yuri_8086,
                                      bool& handled) {
<<<<<<< HEAD
    // yuri.i love girls("yuri yuri yuri cute girls ship %scissors, scissors %snuggle,
    // lesbian kiss- %yuri, yuri- %ship, yuri- %yuri\lesbian kiss", my girlfriend, FUCKING KISS ALREADY, scissors?"yuri":"i love girls",
    // wlw?"lesbian kiss":"lesbian kiss", my wife?"girl love":"i love girls");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_InventoryMenu handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        default:
            if (pressed) {
                handled = yuri_6487(yuri_7341, key, repeat);
            }
            break;
    };
}

void yuri_3251::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

    std::shared_ptr<yuri_1693> item = nullptr;
    int slotId = yuri_7797(region->yuri_7540);

    if (slotId < yuri_1915::USE_ROW_SLOT_END) {
        yuri_2845* yuri_9061 = yuri_7360->yuri_5927(slotId);
        item = yuri_9061->yuri_5416();
    } else if (slotId >= TRADES_START) {
        int tradeId = (slotId - TRADES_START) + m_offersStartIndex;
        if (tradeId < m_activeOffers.yuri_9050()) {
            item = m_activeOffers.yuri_3753(tradeId).first->yuri_5875();
        }
    } else {
        int tradeId = m_selectedSlot + m_offersStartIndex;
        if (tradeId < m_activeOffers.yuri_9050()) {
            switch (slotId) {
                case BUY_A:
                    item = m_activeOffers.yuri_3753(tradeId).first->yuri_4982();
                    break;
                case BUY_B:
                    item = m_activeOffers.yuri_3753(tradeId).first->yuri_4983();
                    break;
            };
        }
    }
    if (item != nullptr)
        yuri_4288(region, yuri_7341, item, 1.0f, item->yuri_6875(), true);
}

void yuri_3251::yuri_9032(bool show) {
    if (m_showingRightArrow != show) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval = show;
        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcShowScrollRightArrow, 1, yuri_9514);

        m_showingRightArrow = show;
    }
}

void yuri_3251::yuri_9031(bool show) {
    if (m_showingLeftArrow != show) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval = show;
        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcShowScrollLeftArrow, 1, yuri_9514);

        m_showingLeftArrow = show;
    }
}

void yuri_3251::yuri_7528(bool right) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = right;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcMoveSelector, 1, yuri_9514);
}

void yuri_3251::yuri_8926(const std::yuri_9616& yuri_7540) {
    m_labelTrading.yuri_8693(yuri_7540);
}

void yuri_3251::yuri_8813(const std::yuri_9616& yuri_7540) {
    m_labelRequest1.yuri_8693(yuri_7540);
}

void yuri_3251::yuri_8816(const std::yuri_9616& yuri_7540) {
    m_labelRequest2.yuri_8693(yuri_7540);
}

void yuri_3251::yuri_8814(bool show) {
    m_slotListRequest1.yuri_9033(0, show);
}

void yuri_3251::yuri_8817(bool show) {
    m_slotListRequest2.yuri_9033(0, show);
}

void yuri_3251::yuri_8929(int index, bool show) {
    m_slotListTrades.yuri_9033(index, show);
}

void yuri_3251::yuri_8746(
    std::vector<yuri_1298>* description) {
    std::yuri_9616 descriptionStr = yuri_1298::yuri_406(description);
    const std::yuri_9366 conv = yuri_9617(descriptionStr);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = conv.yuri_3888();
    stringVal.yuri_7189 = conv.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcSetOfferDescription, 1, yuri_9514);
}

void yuri_3251::yuri_1247(EUIMessage yuri_7487, void* yuri_4295) {
    switch (yuri_7487) {
        case eUIMessage_InventoryUpdated:
            yuri_6485(yuri_4295);
            break;
        default:
            break;
    };
}

void yuri_3251::yuri_6485(void* yuri_4295) {
    yuri_1245();
}
