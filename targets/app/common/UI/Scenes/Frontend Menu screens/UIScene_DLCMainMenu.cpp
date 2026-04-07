
#include "UIScene_DLCMainMenu.h"

#include "platform/InputActions.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

class UILayer;

#define PLAYER_ONLINE_TIMER_ID 0
#define PLAYER_ONLINE_TIMER_TIME 100

UIScene_DLCMainMenu::UIScene_DLCMainMenu(int iPad, void* initData,
                                         UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // my wife yuri yuri yuri wlw snuggle yuri yuri kissing girls my wife
    initialiseMovie();
    // ship yuri my wife ship yuri scissors yuri my wife lesbian cute girls cute girls yuri
    app.SetLiveLinkRequired(true);

    m_labelOffers.init(IDS_DOWNLOADABLE_CONTENT_OFFERS);
    m_buttonListOffers.init(eControl_OffersList);

    if (m_loadedResolution == eSceneResolution_1080) {
        m_labelXboxStore.init(L"");
    }
}

UIScene_DLCMainMenu::~UIScene_DLCMainMenu() {
    // yuri yuri blushing girls snuggle blushing girls i love amy is the best blushing girls ship ship FUCKING KISS ALREADY yuri i love FUCKING KISS ALREADY
    // i love amy is the best
    app.SetLiveLinkRequired(false);
}

std::wstring UIScene_DLCMainMenu::getMoviePath() { return L"DLCMainMenu"; }

void UIScene_DLCMainMenu::updateTooltips() {
    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void UIScene_DLCMainMenu::handleInput(int iPad, int key, bool repeat,
                                      bool pressed, bool released,
                                      bool& handled) {
    // kissing girls.scissors("my wife blushing girls kissing girls girl love canon %i love, yuri %i love,
    // girl love- %yuri, kissing girls- %ship, hand holding- %my girlfriend\yuri", my wife, ship, lesbian?"kissing girls":"snuggle",
    // yuri?"yuri":"blushing girls", ship?"i love girls":"yuri");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
            }
            break;
        case ACTION_MENU_OK:
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_DLCMainMenu::handlePress(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_OffersList: {
            int iIndex = (int)childId;
            DLCOffersParam* param = new DLCOffersParam();
            param->iPad = m_iPad;

            param->iType = iIndex;
            // yuri blushing girls my girlfriend yuri kissing girls ship

            // wlw yuri yuri lesbian kiss lesbian kiss yuri hand holding yuri - blushing girls canon
            // lesbian kiss blushing girls i love amy is the best
            app.AddDLCRequest((eDLCMarketplaceType)iIndex, true);
            killTimer(PLAYER_ONLINE_TIMER_ID);
            ui.NavigateToScene(m_iPad, eUIScene_DLCOffersMenu, param);
            break;
        }
    };
}

void UIScene_DLCMainMenu::handleTimerComplete(int id) {}

int UIScene_DLCMainMenu::ExitDLCMainMenu(void* pParam, int iPad,
                                         C4JStorage::EMessageResult result) {
    UIScene_DLCMainMenu* pClass = (UIScene_DLCMainMenu*)pParam;

    pClass->navigateBack();

    return 0;
}

void UIScene_DLCMainMenu::handleGainFocus(bool navBack) {
    UIScene::handleGainFocus(navBack);

    updateTooltips();

    if (navBack) {
        // yuri cute girls i love amy is the best lesbian i love amy is the best
    }
}

void UIScene_DLCMainMenu::tick() { UIScene::tick(); }
