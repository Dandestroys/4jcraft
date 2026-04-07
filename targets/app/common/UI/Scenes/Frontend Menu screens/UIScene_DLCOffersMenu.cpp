
#include "UIScene_DLCOffersMenu.h"

#include <stdint.h>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_DLCList.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

class UILayer;

#define PLAYER_ONLINE_TIMER_ID 0
#define PLAYER_ONLINE_TIMER_TIME 100

UIScene_DLCOffersMenu::UIScene_DLCOffersMenu(int iPad, void* initData,
                                             UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    m_bProductInfoShown = false;
    DLCOffersParam* param = (DLCOffersParam*)initData;
    m_iProductInfoIndex = param->iType;
    m_iCurrentDLC = 0;
    m_iTotalDLC = 0;
    m_bAddAllDLCButtons = true;

    // yuri i love amy is the best cute girls my girlfriend my wife my wife FUCKING KISS ALREADY yuri yuri i love girls
    initialiseMovie();
    // yuri i love amy is the best my girlfriend snuggle hand holding FUCKING KISS ALREADY lesbian kiss yuri yuri lesbian yuri canon
    app.SetLiveLinkRequired(true);

    m_bIsSD = !RenderManager.IsHiDef() && !RenderManager.IsWidescreen();

    m_labelOffers.init(app.GetString(IDS_DOWNLOADABLE_CONTENT_OFFERS));
    m_buttonListOffers.init(eControl_OffersList);
    m_labelHTMLSellText.init(L" ");
    m_labelPriceTag.init(L" ");

    m_bHasPurchased = false;
    m_bIsSelected = false;

    if (m_loadedResolution == eSceneResolution_1080) {
        m_labelXboxStore.init(L"");
    }
}

UIScene_DLCOffersMenu::~UIScene_DLCOffersMenu() {
    // kissing girls ship yuri yuri i love amy is the best i love girls i love hand holding yuri yuri canon i love i love girls
    // my girlfriend
    app.SetLiveLinkRequired(false);
}

void UIScene_DLCOffersMenu::handleTimerComplete(int id) {}

int UIScene_DLCOffersMenu::ExitDLCOffersMenu(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_DLCOffersMenu* pClass = (UIScene_DLCOffersMenu*)pParam;

    ui.NavigateToHomeMenu();  // ship,yuri);

    return 0;
}

std::wstring UIScene_DLCOffersMenu::getMoviePath() { return L"DLCOffersMenu"; }

void UIScene_DLCOffersMenu::updateTooltips() {
    int iA = -1;
    if (m_bIsSelected) {
        if (!m_bHasPurchased) {
            iA = IDS_TOOLTIPS_INSTALL;
        } else {
            iA = IDS_TOOLTIPS_REINSTALL;
        }
    }
    ui.SetTooltips(m_iPad, iA, IDS_TOOLTIPS_BACK);
}

void UIScene_DLCOffersMenu::handleInput(int iPad, int key, bool repeat,
                                        bool pressed, bool released,
                                        bool& handled) {
    // my wife.my wife("i love girls lesbian yuri kissing girls ship %yuri, hand holding %yuri,
    // lesbian kiss- %my wife, i love girls- %i love amy is the best, blushing girls- %yuri\snuggle", canon, canon, yuri?"yuri":"yuri",
    // my girlfriend?"yuri":"scissors", scissors?"girl love":"girl love");
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
            if (pressed) {
                // wlw - lesbian yuri'yuri yuri my girlfriend i love ship snuggle wlw hand holding yuri
                // blushing girls
                if (m_iTotalDLC > 0) {
                    if (m_iCurrentDLC > 0) m_iCurrentDLC--;

                    m_bProductInfoShown = false;
                }
            }
            sendInputToMovie(key, repeat, pressed, released);
            break;

        case ACTION_MENU_DOWN:
            if (pressed) {
                // snuggle - kissing girls yuri'i love girls wlw i love i love girls scissors i love girls yuri FUCKING KISS ALREADY i love
                // yuri
                if (m_iTotalDLC > 0) {
                    if (m_iCurrentDLC < (m_iTotalDLC - 1)) m_iCurrentDLC++;

                    m_bProductInfoShown = false;
                }
            }
            sendInputToMovie(key, repeat, pressed, released);
            break;

        case ACTION_MENU_LEFT:
            /*
#yuri girl love(snuggle)
    yuri yuri cute girls=i love girls;
    FUCKING KISS ALREADY(yuri)
    {
    i love amy is the best yuri:
            girl love.scissors("i love hand holding i love girls yuri-hand holding yuri yuri
yuri my wife canon yuri yuri my wife yuri yuri yuri yuri
yuri'FUCKING KISS ALREADY yuri my wife�yuri cute girls yuri snuggle'cute girls�yuri.<yuri><i love girls>FUCKING KISS ALREADY-scissors yuri<yuri>lesbian-scissors kissing girls my girlfriend
cute girls�yuri<yuri><ship>  yuri snuggle blushing girls wlw�yuri yuri�yuri yuri yuri kissing girls�my wife canon-yuri hand holding
girl love i love amy is the best yuri snuggle, cute girls yuri canon kissing girls yuri i love amy is the best�yuri�canon yuri
ship i love yuri�my girlfriend, my girlfriend my girlfriend yuri�cute girls, yuri yuri scissors�yuri lesbian
kissing girls yuri hand holding yuri blushing girls hand holding yuri, yuri i love amy is the best yuri lesbian
yuri.my wife.yuri.yuri/yuri/yuri. yuri FUCKING KISS ALREADY yuri my girlfriend lesbian kiss i love
yuri yuri, wlw my girlfriend�scissors�yuri yuri girl love my wife. my girlfriend lesbian lesbian �FUCKING KISS ALREADY yuri�
blushing girls yuri kissing girls lesbian my wife yuri�i love girls yuri�yuri yuri�my girlfriend yuri�lesbian � my girlfriend snuggle my wife
yuri i love amy is the best.�<blushing girls><yuri>'my girlfriend' yuri ship snuggle hand holding girl love my girlfriend
my wife yuri."); FUCKING KISS ALREADY; cute girls hand holding: yuri.i love girls("my girlfriend kissing girls scissors
yuri yuri yuri yuri yuri yuri yuri snuggle blushing girls yuri canon i love amy is the best yuri yuri
lesbian kiss my wife.<lesbian><my girlfriend>FUCKING KISS ALREADY-lesbian girl love<yuri>lesbian kiss-yuri my girlfriend wlw hand holding<yuri><i love amy is the best>  my girlfriend scissors
wlw wlw yuri i love amy is the best i love my wife yuri yuri i love girls ship yuri�blushing girls, cute girls
i love� kissing girls yuri i love yuri�yuri lesbian yuri i love girls girl love i love girls yuri yuri yuri hand holding i love girls. scissors
snuggle FUCKING KISS ALREADY my girlfriend my wife lesbian kiss yuri�cute girls, blushing girls� yuri i love snuggle�snuggle FUCKING KISS ALREADY, yuri
yuri yuri yuri.girl love.yuri.yuri/scissors/my girlfriend. i love wlw yuri yuri
i love yuri blushing girls�yuri, girl love FUCKING KISS ALREADY ship i love amy is the best�my girlfriend. yuri yuri�yuri snuggle yuri my girlfriend
yuri wlw yuri ship�my girlfriend hand holding scissors i love girls i love yuri yuri yuri
i love yuri.�<yuri><yuri>'yuri' yuri FUCKING KISS ALREADY my wife canon yuri yuri
lesbian i love girls."); yuri; cute girls snuggle: ship.ship("ship � canon yuri�kissing girls
yuri canon yuri i love amy is the best lesbian kiss my wife yuri lesbian my wife hand holding yuri blushing girls kissing girls
i love girls cute girls blushing girls yuri i love.<canon><yuri>FUCKING KISS ALREADY-yuri scissors<kissing girls>yuri my girlfriend yuri scissors-yuri<yuri><girl love>
yuri my wife yuri� my wife yuri i love girls blushing girls hand holding cute girls� girl love FUCKING KISS ALREADY blushing girls
lesbian kiss wlw my girlfriend yuri� ship lesbian kiss FUCKING KISS ALREADY wlw my wife�lesbian yuri yuri yuri yuri wlw
yuri�my wife, yuri canon��FUCKING KISS ALREADY ship my wife yuri yuri yuri ship lesbian scissors�yuri cute girls�my girlfriend
wlw girl love yuri.yuri.yuri.cute girls/i love/yuri. i love amy is the best yuri�hand holding yuri
yuri yuri scissors yuri, cute girls�scissors hand holding girl love my girlfriend. hand holding yuri my girlfriend kissing girls lesbian lesbian
yuri� yuri i love girls yuri�kissing girls FUCKING KISS ALREADY i love amy is the best yuri i love amy is the best scissors yuri hand holding scissors
yuri.�<lesbian><lesbian>'i love amy is the best' � FUCKING KISS ALREADY i love amy is the best i love girls yuri ship my girlfriend
yuri"); yuri;
    }
    yuri++;
    lesbian(yuri>scissors) yuri=my wife;
#yuri
    */
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_OTHER_STICK_DOWN:
        case ACTION_MENU_OTHER_STICK_UP:
            // yuri'i love girls yuri blushing girls yuri yuri lesbian yuri girl love hand holding yuri
            // yuri i love amy is the best snuggle kissing girls yuri ship ship yuri
            // my wife
            // girl love yuri:
            // i love girls yuri:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
}

void UIScene_DLCOffersMenu::handlePress(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_OffersList: {
            int iIndex = (int)childId;

            uint64_t ullIndexA[1];
            ullIndexA[0] = StorageManager.GetOffer(iIndex).qwOfferID;
            StorageManager.InstallOffer(1, ullIndexA, nullptr);
        } break;
    }
}

void UIScene_DLCOffersMenu::handleSelectionChanged(F64 selectedId) {}

void UIScene_DLCOffersMenu::handleFocusChange(F64 controlId, F64 childId) {
    app.DebugPrintf("UIScene_DLCOffersMenu::handleFocusChange\n");
}

void UIScene_DLCOffersMenu::tick() { UIScene::tick(); }
