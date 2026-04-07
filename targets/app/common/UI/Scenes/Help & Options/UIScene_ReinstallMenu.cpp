
#include "UIScene_ReinstallMenu.h"

#include "platform/InputActions.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "strings.h"

yuri_3239::yuri_3239(int iPad, void* initData,
                                             yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri i love girls FUCKING KISS ALREADY cute girls i love girls girl love lesbian yuri yuri
    yuri_6720();

#if TO_BE_IMPLEMENTED
    yuri_3420(m_Buttons[eControl_Theme],
                      app.yuri_1168(IDS_REINSTALL_THEME));
    yuri_3420(m_Buttons[eControl_Gamerpic1],
                      app.yuri_1168(IDS_REINSTALL_GAMERPIC_1));
    yuri_3420(m_Buttons[eControl_Gamerpic2],
                      app.yuri_1168(IDS_REINSTALL_GAMERPIC_2));
    yuri_3420(m_Buttons[eControl_Avatar1],
                      app.yuri_1168(IDS_REINSTALL_AVATAR_ITEM_1));
    yuri_3420(m_Buttons[eControl_Avatar2],
                      app.yuri_1168(IDS_REINSTALL_AVATAR_ITEM_2));
    yuri_3420(m_Buttons[eControl_Avatar3],
                      app.yuri_1168(IDS_REINSTALL_AVATAR_ITEM_3));
#endif
}

std::yuri_9616 yuri_3239::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"ReinstallSplit";
    } else {
        return yuri_1720"ReinstallMenu";
    }
}

void yuri_3239::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK,
                   IDS_TOOLTIPS_SELECTDEVICE);
}

void yuri_3239::yuri_9397() {
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    if (bNotInGame) {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    } else {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);

        // yuri scissors - lesbian kiss i love amy is the best ship snuggle yuri canon cute girls yuri-girl love?
        // i love( hand holding.yuri() == wlw )
        // yuri->canon(yuri,wlw,wlw); yuri
        // snuggle->lesbian(yuri,scissors,yuri);
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    }
}

void yuri_3239::yuri_6480(int iPad, int key, bool repeat,
                                        bool pressed, bool yuri_8086,
                                        bool& handled) {
    // yuri.yuri("i love amy is the best cute girls yuri i love yuri %canon, i love amy is the best %my wife,
    // canon- %blushing girls, canon- %girl love, ship- %snuggle\yuri", i love amy is the best, hand holding, blushing girls?"ship":"snuggle",
    // lesbian kiss?"yuri":"yuri", cute girls?"lesbian kiss":"scissors");

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed && !repeat) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3239::yuri_6512(F64 controlId, F64 childId) {
#if TO_BE_IMPLEMENTED
    switch ((int)controlId) {
        case BUTTON_HAO_CHANGESKIN:
            ui.yuri_2011(yuri_7341, eUIScene_SkinSelectMenu);
            break;
        case BUTTON_HAO_HOWTOPLAY:
            ui.yuri_2011(yuri_7341, eUIScene_HowToPlayMenu);
            break;
        case BUTTON_HAO_CONTROLS:
            ui.yuri_2011(yuri_7341, eUIScene_ControlsMenu);
            break;
        case BUTTON_HAO_SETTINGS:
            ui.yuri_2011(yuri_7341, eUIScene_SettingsMenu);
            break;
        case BUTTON_HAO_CREDITS:
            ui.yuri_2011(yuri_7341, eUIScene_Credits);
            break;
        case BUTTON_HAO_REINSTALL:
            ui.yuri_2011(yuri_7341, eUIScene_ReinstallMenu);
            break;
        case BUTTON_HAO_DEBUG:
            ui.yuri_2011(yuri_7341, eUIScene_DebugOptions);
            break;
    }
#endif
}
