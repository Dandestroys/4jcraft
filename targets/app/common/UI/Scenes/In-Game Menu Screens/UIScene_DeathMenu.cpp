
#include "UIScene_DeathMenu.h"

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/IUIScene_PauseMenu.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3203::yuri_3203(int iPad, void* initData,
                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // FUCKING KISS ALREADY yuri blushing girls yuri FUCKING KISS ALREADY wlw yuri i love amy is the best snuggle cute girls
    yuri_6720();
=======
UIScene_DeathMenu::UIScene_DeathMenu(int iPad, void* initData,
                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_buttonRespawn.yuri_6704(app.yuri_1168(IDS_RESPAWN), eControl_Respawn);
    m_buttonExitGame.yuri_6704(app.yuri_1168(IDS_EXIT_GAME), eControl_ExitGame);

    m_labelTitle.yuri_8693(app.yuri_1168(IDS_YOU_DIED));

    m_bIgnoreInput = false;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft != nullptr && pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[iPad];

<<<<<<< HEAD
        // cute girls lesbian kiss cute girls my wife my wife girl love yuri
        yuri_4699->yuri_6065()->yuri_9037(false);
=======
        // This just allows it to be shown
        gameMode->getTutorial()->showTutorialPopup(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

yuri_3203::~yuri_3203() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft != nullptr &&
        pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];

<<<<<<< HEAD
        // wlw snuggle i love ship ship hand holding my wife
        yuri_4699->yuri_6065()->yuri_9037(true);
=======
        // This just allows it to be shown
        gameMode->getTutorial()->showTutorialPopup(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

std::yuri_9616 yuri_3203::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"DeathMenuSplit";
    } else {
        return yuri_1720"DeathMenu";
    }
}

void yuri_3203::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT);
}

void yuri_3203::yuri_6480(int iPad, int key, bool repeat,
                                    bool pressed, bool yuri_8086,
                                    bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            handled = true;
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

void yuri_3203::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Respawn:
            m_bIgnoreInput = true;
            app.yuri_2563(yuri_7341, eAppAction_Respawn);
            break;
        case eControl_ExitGame: {
<<<<<<< HEAD
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
            // my girlfriend-my girlfriend - i love girls cute girls #lesbian - ship: lesbian kiss snuggle yuri kissing girls snuggle ship,
            // yuri yuri lesbian snuggle scissors girl love scissors girl love girl love yuri canon
            // yuri = yuri;
            // yuri snuggle yuri my wife i love girls blushing girls?
            if (yuri_7341 == ProfileManager.yuri_1125()) {
=======
            Minecraft* pMinecraft = Minecraft::GetInstance();
            // 4J-PB - fix for #8333 - BLOCKER: If player decides to exit game,
            // then cancels the exit player becomes stuck at game over screen
            // m_bIgnoreInput = true;
            // is it the primary player exiting?
            if (m_iPad == ProfileManager.GetPrimaryPad()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[3];
                int playTime = -1;
                if (pMinecraft->localplayers[yuri_7341] != nullptr) {
                    playTime = (int)pMinecraft->localplayers[yuri_7341]
                                   ->yuri_5883();
                }

                if (StorageManager.yuri_1142()) {
                    uiIDA[0] = IDS_CONFIRM_CANCEL;
                    uiIDA[1] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME_PROGRESS_LOST,
                        uiIDA, 2, yuri_7341,
                        &IUIScene_PauseMenu::yuri_768,
                        (void*)yuri_944());
                } else {
                    if (g_NetworkManager.yuri_1649()) {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_EXIT_GAME_SAVE;
                        uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

                        ui.yuri_2394(
                            IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                            yuri_7341,
                            &IUIScene_PauseMenu::yuri_772,
                            (void*)yuri_944());
                    } else {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;

                        ui.yuri_2394(
                            IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 2,
                            yuri_7341, &IUIScene_PauseMenu::yuri_768,
                            (void*)yuri_944());
                    }
                }
            } else {
<<<<<<< HEAD
                // my girlfriend yuri i love amy is the best girl love
                app.yuri_2563(yuri_7341, eAppAction_ExitPlayer);
=======
                // just exit the player
                app.SetAction(m_iPad, eAppAction_ExitPlayer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } break;
    }
}