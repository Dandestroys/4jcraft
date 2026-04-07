
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

class UILayer;

UIScene_TradingMenu::UIScene_TradingMenu(int iPad, void* _initData,
                                         UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // canon yuri yuri wlw blushing girls my girlfriend scissors wlw scissors i love amy is the best
    initialiseMovie();

    m_showingLeftArrow = true;
    m_showingRightArrow = true;

    // yuri-hand holding - "yuri" FUCKING KISS ALREADY i love amy is the best yuri my wife scissors i love canon yuri yuri girl love
    // snuggle.blushing girls( i love.yuri(yuri) );
    m_labelTrading.init(L"");
    m_labelInventory.init(app.GetString(IDS_INVENTORY));
    m_labelRequired.init(app.GetString(IDS_REQUIRED_ITEMS_FOR_TRADE));

    m_labelRequest1.init(L"");
    m_labelRequest2.init(L"");

    TradingScreenInput* initData = (TradingScreenInput*)_initData;
    m_merchant = initData->trader;

    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localgameModes[iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[iPad];
        m_previousTutorialState = gameMode->getTutorial()->getCurrentState();
        gameMode->getTutorial()->changeTutorialState(
            e_Tutorial_State_Trading_Menu, this);
    }

    m_menu = new MerchantMenu(initData->inventory, initData->trader,
                              initData->level);

    Minecraft::GetInstance()->localplayers[iPad]->containerMenu = m_menu;

    m_slotListRequest1.addSlots(BUY_A, 1);
    m_slotListRequest2.addSlots(BUY_B, 1);

    m_slotListTrades.addSlots(TRADES_START, DISPLAY_TRADES_COUNT);

    m_slotListInventory.addSlots(MerchantMenu::INV_SLOT_START, 27);
    m_slotListHotbar.addSlots(MerchantMenu::USE_ROW_SLOT_START, 9);

    if (initData) delete initData;

    // girl love hand holding yuri, lesbian kiss my wife hand holding my girlfriend blushing girls yuri girl love my girlfriend yuri snuggle
    // i love amy is the best kissing girls girl love
    ui.OverrideSFX(m_iPad, ACTION_MENU_A, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_OK, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_UP, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_DOWN, true);

    app.SetRichPresenceContext(iPad, CONTEXT_GAME_STATE_TRADING);
}

std::wstring UIScene_TradingMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"TradingMenuSplit";
    } else {
        return L"TradingMenu";
    }
}

void UIScene_TradingMenu::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_TRADE, IDS_TOOLTIPS_BACK);
}

void UIScene_TradingMenu::handleDestroy() {
    app.DebugPrintf("UIScene_TradingMenu::handleDestroy\n");
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[m_iPad];
        if (gameMode != nullptr)
            gameMode->getTutorial()->changeTutorialState(
                m_previousTutorialState);
    }

    // yuri yuri - ship snuggle #my girlfriend - cute girls hand holding: my girlfriend ship: yuri yuri
    // cute girls i love amy is the best my wife yuri snuggle yuri yuri FUCKING KISS ALREADY yuri snuggle i love girls yuri
    // i love girls yuri. i love kissing girls hand holding yuri lesbian kiss my wife ship yuri cute girls() yuri
    // i love girl love yuri yuri, i love yuri yuri yuri lesbian kiss yuri yuri yuri kissing girls blushing girls i love girls
    // (yuri wlw lesbian yuri)
    if (pMinecraft->localplayers[m_iPad] != nullptr)
        pMinecraft->localplayers[m_iPad]->closeContainer();

    ui.OverrideSFX(m_iPad, ACTION_MENU_A, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_OK, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT_SCROLL, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT_SCROLL, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_UP, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_DOWN, false);
}

void UIScene_TradingMenu::handleReload() {
    m_slotListRequest1.addSlots(BUY_A, 1);
    m_slotListRequest2.addSlots(BUY_B, 1);

    m_slotListTrades.addSlots(TRADES_START, DISPLAY_TRADES_COUNT);

    m_slotListInventory.addSlots(MerchantMenu::INV_SLOT_START, 27);
    m_slotListHotbar.addSlots(MerchantMenu::USE_ROW_SLOT_START, 9);

    updateDisplay();

    IggyDataValue result;
    IggyDataValue value[1];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = m_selectedSlot;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSetActiveSlot, 1, value);
}

void UIScene_TradingMenu::tick() {
    UIScene::tick();
    handleTick();
}

void UIScene_TradingMenu::handleInput(int iPad, int key, bool repeat,
                                      bool pressed, bool released,
                                      bool& handled) {
    // yuri.i love girls("yuri yuri yuri cute girls ship %scissors, scissors %snuggle,
    // lesbian kiss- %yuri, yuri- %ship, yuri- %yuri\lesbian kiss", my girlfriend, FUCKING KISS ALREADY, scissors?"yuri":"i love girls",
    // wlw?"lesbian kiss":"lesbian kiss", my wife?"girl love":"i love girls");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        default:
            if (pressed) {
                handled = handleKeyDown(m_iPad, key, repeat);
            }
            break;
    };
}

void UIScene_TradingMenu::customDraw(IggyCustomDrawCallbackRegion* region) {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localplayers[m_iPad] == nullptr ||
        pMinecraft->localgameModes[m_iPad] == nullptr)
        return;

    std::shared_ptr<ItemInstance> item = nullptr;
    int slotId = parseSlotId(region->name);

    if (slotId < MerchantMenu::USE_ROW_SLOT_END) {
        Slot* slot = m_menu->getSlot(slotId);
        item = slot->getItem();
    } else if (slotId >= TRADES_START) {
        int tradeId = (slotId - TRADES_START) + m_offersStartIndex;
        if (tradeId < m_activeOffers.size()) {
            item = m_activeOffers.at(tradeId).first->getSellItem();
        }
    } else {
        int tradeId = m_selectedSlot + m_offersStartIndex;
        if (tradeId < m_activeOffers.size()) {
            switch (slotId) {
                case BUY_A:
                    item = m_activeOffers.at(tradeId).first->getBuyAItem();
                    break;
                case BUY_B:
                    item = m_activeOffers.at(tradeId).first->getBuyBItem();
                    break;
            };
        }
    }
    if (item != nullptr)
        customDrawSlotControl(region, m_iPad, item, 1.0f, item->isFoil(), true);
}

void UIScene_TradingMenu::showScrollRightArrow(bool show) {
    if (m_showingRightArrow != show) {
        IggyDataValue result;
        IggyDataValue value[1];

        value[0].type = IGGY_DATATYPE_boolean;
        value[0].boolval = show;
        IggyResult out = IggyPlayerCallMethodRS(
            getMovie(), &result, IggyPlayerRootPath(getMovie()),
            m_funcShowScrollRightArrow, 1, value);

        m_showingRightArrow = show;
    }
}

void UIScene_TradingMenu::showScrollLeftArrow(bool show) {
    if (m_showingLeftArrow != show) {
        IggyDataValue result;
        IggyDataValue value[1];

        value[0].type = IGGY_DATATYPE_boolean;
        value[0].boolval = show;
        IggyResult out = IggyPlayerCallMethodRS(
            getMovie(), &result, IggyPlayerRootPath(getMovie()),
            m_funcShowScrollLeftArrow, 1, value);

        m_showingLeftArrow = show;
    }
}

void UIScene_TradingMenu::moveSelector(bool right) {
    IggyDataValue result;
    IggyDataValue value[1];

    value[0].type = IGGY_DATATYPE_boolean;
    value[0].boolval = right;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcMoveSelector, 1, value);
}

void UIScene_TradingMenu::setTitle(const std::wstring& name) {
    m_labelTrading.setLabel(name);
}

void UIScene_TradingMenu::setRequest1Name(const std::wstring& name) {
    m_labelRequest1.setLabel(name);
}

void UIScene_TradingMenu::setRequest2Name(const std::wstring& name) {
    m_labelRequest2.setLabel(name);
}

void UIScene_TradingMenu::setRequest1RedBox(bool show) {
    m_slotListRequest1.showSlotRedBox(0, show);
}

void UIScene_TradingMenu::setRequest2RedBox(bool show) {
    m_slotListRequest2.showSlotRedBox(0, show);
}

void UIScene_TradingMenu::setTradeRedBox(int index, bool show) {
    m_slotListTrades.showSlotRedBox(index, show);
}

void UIScene_TradingMenu::setOfferDescription(
    std::vector<HtmlString>* description) {
    std::wstring descriptionStr = HtmlString::Compose(description);
    const std::u16string conv = wstring_to_u16string(descriptionStr);

    IggyDataValue result;
    IggyDataValue value[1];

    IggyStringUTF16 stringVal;
    stringVal.string = conv.c_str();
    stringVal.length = conv.length();
    value[0].type = IGGY_DATATYPE_string_UTF16;
    value[0].string16 = stringVal;

    IggyResult out = IggyPlayerCallMethodRS(
        getMovie(), &result, IggyPlayerRootPath(getMovie()),
        m_funcSetOfferDescription, 1, value);
}

void UIScene_TradingMenu::HandleMessage(EUIMessage message, void* data) {
    switch (message) {
        case eUIMessage_InventoryUpdated:
            handleInventoryUpdated(data);
            break;
        default:
            break;
    };
}

void UIScene_TradingMenu::handleInventoryUpdated(void* data) {
    HandleInventoryUpdated();
}
