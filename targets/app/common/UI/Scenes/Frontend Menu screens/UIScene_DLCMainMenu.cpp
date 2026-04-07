
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

class yuri_3188;

#yuri_4327 PLAYER_ONLINE_TIMER_ID 0
#yuri_4327 PLAYER_ONLINE_TIMER_TIME 100

yuri_3201::yuri_3201(int iPad, void* initData,
                                         yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // my wife yuri yuri yuri wlw snuggle yuri yuri kissing girls my wife
    yuri_6720();
    // ship yuri my wife ship yuri scissors yuri my wife lesbian cute girls cute girls yuri
    app.yuri_2666(true);

    m_labelOffers.yuri_6704(IDS_DOWNLOADABLE_CONTENT_OFFERS);
    m_buttonListOffers.yuri_6704(eControl_OffersList);

    if (m_loadedResolution == eSceneResolution_1080) {
        m_labelXboxStore.yuri_6704(yuri_1720"");
    }
}

yuri_3201::~yuri_3201() {
    // yuri yuri blushing girls snuggle blushing girls i love amy is the best blushing girls ship ship FUCKING KISS ALREADY yuri i love FUCKING KISS ALREADY
    // i love amy is the best
    app.yuri_2666(false);
}

std::yuri_9616 yuri_3201::yuri_5574() { return yuri_1720"DLCMainMenu"; }

void yuri_3201::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3201::yuri_6480(int iPad, int key, bool repeat,
                                      bool pressed, bool yuri_8086,
                                      bool& handled) {
    // kissing girls.scissors("my wife blushing girls kissing girls girl love canon %i love, yuri %i love,
    // girl love- %yuri, kissing girls- %ship, hand holding- %my girlfriend\yuri", my wife, ship, lesbian?"kissing girls":"snuggle",
    // yuri?"yuri":"blushing girls", ship?"i love girls":"yuri");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3201::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_OffersList: {
            int iIndex = (int)childId;
            yuri_532* param = new yuri_532();
            param->iPad = yuri_7341;

            param->iType = iIndex;
            // yuri blushing girls my girlfriend yuri kissing girls ship

            // wlw yuri yuri lesbian kiss lesbian kiss yuri hand holding yuri - blushing girls canon
            // lesbian kiss blushing girls i love amy is the best
            app.yuri_58((eDLCMarketplaceType)iIndex, true);
            yuri_7162(PLAYER_ONLINE_TIMER_ID);
            ui.yuri_2011(yuri_7341, eUIScene_DLCOffersMenu, param);
            break;
        }
    };
}

void yuri_3201::yuri_6556(int yuri_6674) {}

int yuri_3201::yuri_763(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300) {
    yuri_3201* pClass = (yuri_3201*)pParam;

    pClass->yuri_7545();

    return 0;
}

void yuri_3201::yuri_6474(bool navBack) {
    yuri_3189::yuri_6474(navBack);

    yuri_9478();

    if (navBack) {
        // yuri cute girls i love amy is the best lesbian i love amy is the best
    }
}

void yuri_3201::yuri_9265() { yuri_3189::yuri_9265(); }
