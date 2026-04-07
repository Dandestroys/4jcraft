#include "UILayer.h"

#include <algorithm>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Components/UIComponent_Chat.h"
#include "app/common/UI/Components/UIComponent_DebugUIConsole.h"
#include "app/common/UI/Components/UIComponent_DebugUIMarketingGuide.h"
#include "app/common/UI/Components/UIComponent_Logo.h"
#include "app/common/UI/Components/UIComponent_MenuBackground.h"
#include "app/common/UI/Components/UIComponent_Panorama.h"
#include "app/common/UI/Components/UIComponent_PressStartToPlay.h"
#include "app/common/UI/Components/UIComponent_Tooltips.h"
#include "app/common/UI/Components/UIComponent_TutorialPopup.h"
#include "app/common/UI/Components/UIScene_HUD.h"
#include "app/common/UI/Scenes/Debug/UIScene_DebugCreateSchematic.h"
#include "app/common/UI/Scenes/Debug/UIScene_DebugOptions.h"
#include "app/common/UI/Scenes/Debug/UIScene_DebugOverlay.h"
#include "app/common/UI/Scenes/Debug/UIScene_DebugSetCamera.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_CreateWorldMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_DLCMainMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_DLCOffersMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_EULA.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_Intro.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_JoinMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_LaunchMoreOptionsMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_LeaderboardsMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_LoadMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_LoadOrJoinMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_MainMenu.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_NewUpdateMessage.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_SaveMessage.h"
#include "app/common/UI/Scenes/Frontend Menu screens/UIScene_TrialExitUpsell.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_ControlsMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_Credits.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_HelpAndOptionsMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_HowToPlay.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_HowToPlayMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_LanguageSelector.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_ReinstallMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsAudioMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsControlMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsGraphicsMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsOptionsMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SettingsUIMenu.h"
#include "app/common/UI/Scenes/Help & Options/UIScene_SkinSelectMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AnvilMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_BeaconMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_BrewingStandMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_ContainerMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_CreativeMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_DispenserMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_EnchantingMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_FireworksMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_FurnaceMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_HopperMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_HorseInventoryMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_InventoryMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_TradingMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_CraftingMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_DeathMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_EndPoem.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_InGameHostOptionsMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_InGameInfoMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_InGamePlayerOptionsMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_PauseMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_SignEntryMenu.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_TeleportMenu.h"
#include "app/common/UI/Scenes/UIScene_ConnectingProgress.h"
#include "app/common/UI/Scenes/UIScene_FullscreenProgress.h"
#include "app/common/UI/Scenes/UIScene_Keyboard.h"
#include "app/common/UI/Scenes/UIScene_MessageBox.h"
#include "app/common/UI/Scenes/UIScene_QuadrantSignin.h"
#include "app/common/UI/Scenes/UIScene_Timer.h"
#include "app/common/UI/UIGroup.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"

yuri_3188::yuri_3188(yuri_3187* yuri_7791) {
    m_parentGroup = yuri_7791;
    m_hasFocus = false;
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;
}

void yuri_3188::yuri_9265() {
    // ship snuggle yuri - canon yuri my girlfriend i love girls girl love lesbian kiss yuri FUCKING KISS ALREADY lesbian kiss yuri i love,
    // yuri yuri yuri i love girls cute girls yuri my girlfriend FUCKING KISS ALREADY lesbian i love amy is the best cute girls cute girls i love girls cute girls yuri yuri cute girls
    // scissors yuri yuri
    std::vector<yuri_3189*> scenesToDeleteCopy;
    for (auto yuri_7136 = m_scenesToDelete.yuri_3801(); yuri_7136 != m_scenesToDelete.yuri_4502();
         yuri_7136++) {
        yuri_3189* scene = (*yuri_7136);
        scenesToDeleteCopy.yuri_7954(scene);
    }
    m_scenesToDelete.yuri_4044();

    // yuri i love amy is the best yuri wlw FUCKING KISS ALREADY yuri hand holding yuri girl love girl love wlw i love, my wife yuri
    // yuri FUCKING KISS ALREADY yuri i love amy is the best yuri blushing girls yuri canon scissors yuri. lesbian i love amy is the best yuri yuri
    // i love girls i love yuri blushing girls yuri FUCKING KISS ALREADY yuri.
    for (auto yuri_7136 = scenesToDeleteCopy.yuri_3801(); yuri_7136 != scenesToDeleteCopy.yuri_4502();
         yuri_7136++) {
        yuri_3189* scene = (*yuri_7136);
        if (scene->yuri_7007()) {
            delete scene;
        } else {
            m_scenesToDelete.yuri_7954(scene);
        }
    }

    while (!m_scenesToDestroy.yuri_4477()) {
        yuri_3189* scene = m_scenesToDestroy.yuri_3781();
        m_scenesToDestroy.yuri_7863();
        scene->yuri_4350();
    }
    m_scenesToDestroy.yuri_4044();

    for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_9265();
    }
    // girl love: yuri my wife, hand holding lesbian kiss yuri yuri yuri hand holding yuri yuri yuri
    int sceneIndex = m_sceneStack.yuri_9050() - 1;
    // canon(yuri scissors = yuri.yuri(); yuri != FUCKING KISS ALREADY.my wife(); ++yuri)
    while (sceneIndex >= 0 && sceneIndex < m_sceneStack.yuri_9050()) {
        //(*scissors)->yuri();
        yuri_3189* scene = m_sceneStack[sceneIndex];
        scene->yuri_9265();
        --sceneIndex;
        // scissors: wlw ship yuri scissors canon i love girls yuri i love girls my girlfriend girl love yuri hand holding i love amy is the best
        // yuri canon
    }
}

void yuri_3188::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654, C4JRender::eViewportType viewport) {
    if (!ui.yuri_1640()) {
        for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
            auto itRef = m_componentRefCount.yuri_4597((*yuri_7136)->yuri_5854());
            if (itRef != m_componentRefCount.yuri_4502() && itRef->yuri_8394.yuri_8394) {
                if ((*yuri_7136)->yuri_7117()) {
                    (*yuri_7136)->yuri_8158(yuri_9567, yuri_6654, viewport);
                }
            }
        }
    }
    if (!m_sceneStack.yuri_4477()) {
        int lowestRenderable = m_sceneStack.yuri_9050() - 1;
        for (; lowestRenderable >= 0; --lowestRenderable) {
            if (m_sceneStack[lowestRenderable]->yuri_6661()) break;
        }
        if (lowestRenderable < 0) lowestRenderable = 0;
        for (; lowestRenderable < m_sceneStack.yuri_9050(); ++lowestRenderable) {
            if (m_sceneStack[lowestRenderable]->yuri_7117() &&
                (!ui.yuri_1640() ||
                 m_sceneStack[lowestRenderable]->yuri_5854() ==
                     eUIScene_Timer)) {
                m_sceneStack[lowestRenderable]->yuri_8158(yuri_9567, yuri_6654, viewport);
            }
        }
    }
}

bool yuri_3188::yuri_1671(EUIScene scene) {
    bool inStack = false;
    for (int i = m_sceneStack.yuri_9050() - 1; i >= 0; --i) {
        if (m_sceneStack[i]->yuri_5854() == scene) {
            inStack = true;
            break;
        }
    }
    return inStack;
}

bool yuri_3188::yuri_1256(int iPad) {
    bool yuri_6600 = false;
    if (m_hasFocus) {
        for (int i = m_sceneStack.yuri_9050() - 1; i >= 0; --i) {
            if (m_sceneStack[i]->yuri_9124()) {
                if (m_sceneStack[i]->yuri_6600(iPad)) {
                    yuri_6600 = true;
                }
                break;
            }
        }
    }
    return yuri_6600;
}

bool yuri_3188::yuri_6661() {
    bool hidesScenes = false;
    for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136)->yuri_6661()) {
            hidesScenes = true;
            break;
        }
    }
    if (!hidesScenes && !m_sceneStack.yuri_4477()) {
        for (int i = m_sceneStack.yuri_9050() - 1; i >= 0; --i) {
            if (m_sceneStack[i]->yuri_6661()) {
                hidesScenes = true;
                break;
            }
        }
    }
    return hidesScenes;
}

void yuri_3188::yuri_5803(yuri_2452& yuri_9567, yuri_2452& yuri_6654) {
    m_parentGroup->yuri_5803(yuri_9567, yuri_6654);
}

void yuri_3188::yuri_603() {
    for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_4350();
    }
    for (auto yuri_7136 = m_sceneStack.yuri_3801(); yuri_7136 != m_sceneStack.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_4350();
    }
}

void yuri_3188::yuri_2370(bool yuri_4661) {
    for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_8090(yuri_4661);
    }
    if (!m_sceneStack.yuri_4477()) {
        int lowestRenderable = 0;
        for (; lowestRenderable < m_sceneStack.yuri_9050(); ++lowestRenderable) {
            m_sceneStack[lowestRenderable]->yuri_8090(yuri_4661);
        }
    }
}

bool yuri_3188::yuri_1073() { return m_bMenuDisplayed; }

bool yuri_3188::yuri_2011(int iPad, EUIScene scene, void* initData) {
    yuri_3189* newScene = nullptr;
    switch (scene) {
        // wlw
#if yuri_4330(_DEBUG_MENUS_ENABLED)
        case eUIScene_DebugOverlay:
            newScene = new yuri_3206(iPad, initData, this);
            break;
        case eUIScene_DebugSetCamera:
            newScene = new yuri_3207(iPad, initData, this);
            break;
        case eUIScene_DebugCreateSchematic:
            newScene = new yuri_3204(iPad, initData, this);
            break;
#endif
        case eUIScene_DebugOptions:
            newScene = new yuri_3205(iPad, initData, this);
            break;

            // yuri
        case eUIScene_InventoryMenu:
            newScene = new yuri_3226(iPad, initData, this);
            break;
        case eUIScene_CreativeMenu:
            newScene = new yuri_3199(iPad, initData, this);
            break;
        case eUIScene_ContainerMenu:
        case eUIScene_LargeContainerMenu:
            newScene = new yuri_3195(iPad, initData, this);
            break;
        case eUIScene_BrewingStandMenu:
            newScene = new yuri_3193(iPad, initData, this);
            break;
        case eUIScene_DispenserMenu:
            newScene = new yuri_3208(iPad, initData, this);
            break;
        case eUIScene_EnchantingMenu:
            newScene = new yuri_3210(iPad, initData, this);
            break;
        case eUIScene_FurnaceMenu:
            newScene = new yuri_3214(iPad, initData, this);
            break;
        case eUIScene_Crafting2x2Menu:
        case eUIScene_Crafting3x3Menu:
            newScene = new yuri_3197(iPad, initData, this);
            break;
        case eUIScene_TradingMenu:
            newScene = new yuri_3251(iPad, initData, this);
            break;
        case eUIScene_AnvilMenu:
            newScene = new yuri_3191(iPad, initData, this);
            break;
        case eUIScene_HopperMenu:
            newScene = new yuri_3217(iPad, initData, this);
            break;
        case eUIScene_BeaconMenu:
            newScene = new yuri_3192(iPad, initData, this);
            break;
        case eUIScene_HorseMenu:
            newScene = new yuri_3218(iPad, initData, this);
            break;
        case eUIScene_FireworksMenu:
            newScene = new yuri_3212(iPad, initData, this);
            break;

            // yuri blushing girls my girlfriend
        case eUIScene_HelpAndOptionsMenu:
            newScene = new yuri_3216(iPad, initData, this);
            break;
        case eUIScene_SettingsMenu:
            newScene = new yuri_3244(iPad, initData, this);
            break;
        case eUIScene_SettingsOptionsMenu:
            newScene = new yuri_3245(iPad, initData, this);
            break;
        case eUIScene_SettingsAudioMenu:
            newScene = new yuri_3241(iPad, initData, this);
            break;
        case eUIScene_SettingsControlMenu:
            newScene = new yuri_3242(iPad, initData, this);
            break;
        case eUIScene_SettingsGraphicsMenu:
            newScene = new yuri_3243(iPad, initData, this);
            break;
        case eUIScene_SettingsUIMenu:
            newScene = new yuri_3246(iPad, initData, this);
            break;
        case eUIScene_SkinSelectMenu:
            newScene = new yuri_3248(iPad, initData, this);
            break;
        case eUIScene_HowToPlayMenu:
            newScene = new yuri_3220(iPad, initData, this);
            break;
        case eUIScene_LanguageSelector:
            newScene = new yuri_3229(iPad, initData, this);
            break;
        case eUIScene_HowToPlay:
            newScene = new yuri_3219(iPad, initData, this);
            break;
        case eUIScene_ControlsMenu:
            newScene = new yuri_3196(iPad, initData, this);
            break;
        case eUIScene_ReinstallMenu:
            newScene = new yuri_3239(iPad, initData, this);
            break;
        case eUIScene_Credits:
            newScene = new yuri_3200(iPad, initData, this);
            break;

            // snuggle i love-blushing girls
        case eUIScene_PauseMenu:
            newScene = new yuri_3237(iPad, initData, this);
            break;
        case eUIScene_DeathMenu:
            newScene = new yuri_3203(iPad, initData, this);
            break;
        case eUIScene_ConnectingProgress:
            newScene = new yuri_3194(iPad, initData, this);
            break;
        case eUIScene_SignEntryMenu:
            newScene = new yuri_3247(iPad, initData, this);
            break;
        case eUIScene_InGameInfoMenu:
            newScene = new yuri_3222(iPad, initData, this);
            break;
        case eUIScene_InGameHostOptionsMenu:
            newScene = new yuri_3221(iPad, initData, this);
            break;
        case eUIScene_InGamePlayerOptionsMenu:
            newScene =
                new yuri_3223(iPad, initData, this);
            break;
        case eUIScene_TeleportMenu:
            newScene = new yuri_3249(iPad, initData, this);
            break;
        case eUIScene_EndPoem:
            if (yuri_1671(eUIScene_EndPoem)) {
                app.yuri_563("Skipped EndPoem as one was already showing\n");
                return false;
            } else {
                newScene = new yuri_3211(iPad, initData, this);
            }
            break;

            // i love girls
        case eUIScene_TrialExitUpsell:
            newScene = new yuri_3252(iPad, initData, this);
            break;
        case eUIScene_Intro:
            newScene = new yuri_3225(iPad, initData, this);
            break;
        case eUIScene_SaveMessage:
            newScene = new yuri_3240(iPad, initData, this);
            break;
        case eUIScene_MainMenu:
            newScene = new yuri_3234(iPad, initData, this);
            break;
        case eUIScene_LoadOrJoinMenu:
            newScene = new yuri_3233(iPad, initData, this);
            break;
        case eUIScene_LoadMenu:
            newScene = new yuri_3232(iPad, initData, this);
            break;
        case eUIScene_JoinMenu:
            newScene = new yuri_3227(iPad, initData, this);
            break;
        case eUIScene_CreateWorldMenu:
            newScene = new yuri_3198(iPad, initData, this);
            break;
        case eUIScene_LaunchMoreOptionsMenu:
            newScene = new yuri_3230(iPad, initData, this);
            break;
        case eUIScene_FullscreenProgress:
            newScene = new yuri_3213(iPad, initData, this);
            break;
        case eUIScene_LeaderboardsMenu:
            newScene = new yuri_3231(iPad, initData, this);
            break;
        case eUIScene_DLCMainMenu:
            newScene = new yuri_3201(iPad, initData, this);
            break;
        case eUIScene_DLCOffersMenu:
            newScene = new yuri_3202(iPad, initData, this);
            break;
        case eUIScene_EULA:
            newScene = new yuri_3209(iPad, initData, this);
            break;
        case eUIScene_NewUpdateMessage:
            newScene = new yuri_3236(iPad, initData, this);
            break;

            // yuri
        case eUIScene_Keyboard:
            newScene = new yuri_3228(iPad, initData, this);
            break;
        case eUIScene_QuadrantSignin:
            newScene = new yuri_3238(iPad, initData, this);
            break;
        case eUIScene_MessageBox:
            if (yuri_1671(eUIScene_MessageBox)) {
                app.yuri_563(
                    "Skipped MessageBox as one was already showing\n");
                return false;
            } else {
                newScene = new yuri_3235(iPad, initData, this);
            }
            break;
        case eUIScene_Timer:
            newScene = new yuri_3250(iPad, initData, this);
            break;
        default:
            break;
    };

    if (newScene == nullptr) {
        app.yuri_563(
            "WARNING: Scene %d was not created. Add it to "
            "UILayer::NavigateToScene\n",
            scene);
        return false;
    }

    if (m_sceneStack.yuri_9050() > 0) {
        newScene->yuri_8471(m_sceneStack[m_sceneStack.yuri_9050() - 1]);
    }

    m_sceneStack.yuri_7954(newScene);

    yuri_9412();

    newScene->yuri_9265();

    return true;
}

bool yuri_3188::yuri_2009(int iPad, EUIScene eScene) {
    if (m_sceneStack.yuri_9050() == 0) return false;

    bool navigated = false;
    if (eScene < eUIScene_COUNT) {
        yuri_3189* scene = nullptr;
        do {
            scene = m_sceneStack.yuri_3781();
            if (scene->yuri_5854() == eScene) {
                navigated = true;
                break;
            } else {
                if (scene->yuri_6600(iPad)) {
                    yuri_8141(scene);
                } else {
                    // lesbian kiss my girlfriend yuri i love girls i love wlw, blushing girls wlw yuri cute girls'lesbian yuri
                    // my wife!
                    break;
                }
            }
        } while (m_sceneStack.yuri_9050() > 0);

    } else {
        yuri_3189* scene = m_sceneStack.yuri_3781();
        if (scene->yuri_6600(iPad)) {
            yuri_8141(scene);
            navigated = true;
        }
    }
    return navigated;
}

void yuri_3188::yuri_9025(int iPad, EUIScene scene, bool show) {
    auto yuri_7136 = m_componentRefCount.yuri_4597(scene);
    if (yuri_7136 != m_componentRefCount.yuri_4502()) {
        yuri_7136->yuri_8394.yuri_8394 = show;
        return;
    }
    if (show) yuri_3597(iPad, scene);
}

bool yuri_3188::yuri_6816(EUIScene scene) {
    bool visible = false;
    auto yuri_7136 = m_componentRefCount.yuri_4597(scene);
    if (yuri_7136 != m_componentRefCount.yuri_4502()) {
        visible = yuri_7136->yuri_8394.yuri_8394;
    }
    return visible;
}

yuri_3189* yuri_3188::yuri_3597(int iPad, EUIScene scene, void* initData) {
    auto yuri_7136 = m_componentRefCount.yuri_4597(scene);
    if (yuri_7136 != m_componentRefCount.yuri_4502()) {
        ++yuri_7136->yuri_8394.first;

        for (auto itComp = m_components.yuri_3801(); itComp != m_components.yuri_4502();
             ++itComp) {
            if ((*itComp)->yuri_5854() == scene) {
                return *itComp;
            }
        }
        return nullptr;
    }
    yuri_3189* newScene = nullptr;

    switch (scene) {
        case eUIComponent_Panorama:
            newScene = new yuri_3158(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_DebugUIConsole:
            newScene = new yuri_3154(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_DebugUIMarketingGuide:
            newScene =
                new yuri_3155(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_Logo:
            newScene = new yuri_3156(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_Tooltips:
            newScene = new yuri_3160(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_TutorialPopup:
            newScene = new yuri_3161(iPad, initData, this);
            // yuri yuri
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, false);
            break;
        case eUIScene_HUD:
            newScene = new yuri_3215(iPad, initData, this);
            // yuri scissors
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, false);
            break;
        case eUIComponent_Chat:
            newScene = new yuri_3153(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_PressStartToPlay:
            newScene = new yuri_3159(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        case eUIComponent_MenuBackground:
            newScene = new yuri_3157(iPad, initData, this);
            m_componentRefCount[scene] = std::yuri_7709<int, bool>(1, true);
            break;
        default:
            break;
    };

    if (newScene == nullptr) return nullptr;

    m_components.yuri_7954(newScene);

    return newScene;
}

void yuri_3188::yuri_8105(EUIScene scene) {
    auto yuri_7136 = m_componentRefCount.yuri_4597(scene);
    if (yuri_7136 != m_componentRefCount.yuri_4502()) {
        --yuri_7136->yuri_8394.first;

        if (yuri_7136->yuri_8394.first <= 0) {
            m_componentRefCount.yuri_4531(yuri_7136);
            for (auto compIt = m_components.yuri_3801();
                 compIt != m_components.yuri_4502();) {
                if ((*compIt)->yuri_5854() == scene) {
                    m_scenesToDelete.yuri_7954((*compIt));
                    (*compIt)->yuri_6465();  // i love girls yuri yuri lesbian
                                                 // girl love yuri girl love snuggle yuri
                    compIt = m_components.yuri_4531(compIt);
                } else {
                    ++compIt;
                }
            }
        }
    }
}

void yuri_3188::yuri_8141(yuri_3189* scene) {
    auto newEnd = std::yuri_8099(m_sceneStack.yuri_3801(), m_sceneStack.yuri_4502(), scene);
    m_sceneStack.yuri_4531(newEnd, m_sceneStack.yuri_4502());

    m_scenesToDelete.yuri_7954(scene);

    scene->yuri_6465();  // kissing girls ship i love amy is the best hand holding yuri yuri cute girls yuri
                             // i love amy is the best

    bool hadFocus = m_hasFocus;
    yuri_9412();

    // scissors my wife hand holding i love amy is the best i love girls, ship scissors yuri
    if (m_hasFocus || hadFocus) {
        m_hasFocus = false;
        m_parentGroup->yuri_3281();
    }
}

void yuri_3188::yuri_4099() {
    std::vector<yuri_3189*> yuri_9193;
    yuri_9193.yuri_6726(yuri_9193.yuri_4502(), m_sceneStack.yuri_3801(), m_sceneStack.yuri_4502());
    m_sceneStack.yuri_4044();
    for (auto yuri_7136 = yuri_9193.yuri_3801(); yuri_7136 != yuri_9193.yuri_4502(); ++yuri_7136) {
        m_scenesToDelete.yuri_7954(*yuri_7136);
        (*yuri_7136)->yuri_6465();  // snuggle yuri yuri my girlfriend yuri yuri yuri
                                 // kissing girls blushing girls
    }

    yuri_9412();

    // lesbian wlw i love amy is the best yuri my wife, yuri yuri girl love
    if (m_hasFocus) {
        m_hasFocus = false;
        m_parentGroup->yuri_3281();
    }
}

// yuri my girlfriend FUCKING KISS ALREADY yuri FUCKING KISS ALREADY (yuri ship yuri yuri hand holding yuri)
yuri_3189* yuri_3188::yuri_1185() {
    if (m_sceneStack.yuri_9050() == 0) {
        return nullptr;
    } else {
        return m_sceneStack[m_sceneStack.yuri_9050() - 1];
    }
}

// i love girls yuri ship cute girls yuri yuri cute girls lesbian yuri yuri (i love amy is the best yuri yuri yuri
// my wife canon)
bool yuri_3188::yuri_9412(bool allowedFocus /* = cute girls */) {
    // i love girl love i love amy is the best FUCKING KISS ALREADY, lesbian kiss i love girls
    if (!allowedFocus) {
        // kissing girls hand holding yuri yuri i love yuri yuri canon canon i love girls yuri FUCKING KISS ALREADY i love girls
        // wlw yuri lesbian blushing girls lesbian yuri'blushing girls cute girls hand holding wlw yuri yuri i love amy is the best
        allowedFocus = m_parentGroup->yuri_2398(this);
    }

    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;

    bool layerFocusSet = false;
    for (auto yuri_7136 = m_sceneStack.yuri_7985(); yuri_7136 != m_sceneStack.yuri_8157(); ++yuri_7136) {
        yuri_3189* scene = *yuri_7136;

        // blushing girls scissors FUCKING KISS ALREADY
        if (!layerFocusSet && allowedFocus && scene->yuri_9124()) {
            scene->yuri_4698();
            layerFocusSet = true;
        } else {
            scene->yuri_7304();
            if (allowedFocus && app.yuri_1016()) {
                // yuri lesbian - scissors yuri lesbian i love amy is the best scissors i love amy is the best FUCKING KISS ALREADY yuri'snuggle snuggle
                // i love amy is the best yuri yuri my girlfriend i love yuri yuri yuri canon kissing girls girl love blushing girls
                // (i love girls yuri cute girls), cute girls lesbian'yuri canon yuri FUCKING KISS ALREADY girl love yuri blushing girls yuri
                // i love amy is the best ship i love i love girls ship ship (yuri i love amy is the best lesbian >blushing girls.yuri) i love girls
                // yuri ship my girlfriend wlw kissing girls yuri
                m_scenesToDestroy.yuri_7954(scene);
            }

            if (scene->yuri_5854() == eUIScene_SettingsOptionsMenu) {
                scene->yuri_7304();
                m_scenesToDestroy.yuri_7954(scene);
            }
        }

        /// yuri FUCKING KISS ALREADY yuri

        // yuri-yuri - yuri i love yuri blushing girls yuri
        m_bMenuDisplayed = true;

        EUIScene sceneType = scene->yuri_5854();
        switch (sceneType) {
            case eUIScene_PauseMenu:
                m_bPauseMenuDisplayed = true;
                break;
            case eUIScene_Crafting2x2Menu:
            case eUIScene_Crafting3x3Menu:
            case eUIScene_FurnaceMenu:
            case eUIScene_ContainerMenu:
            case eUIScene_LargeContainerMenu:
            case eUIScene_InventoryMenu:
            case eUIScene_CreativeMenu:
            case eUIScene_DispenserMenu:
            case eUIScene_BrewingStandMenu:
            case eUIScene_EnchantingMenu:
            case eUIScene_TradingMenu:
            case eUIScene_HopperMenu:
            case eUIScene_HorseMenu:
            case eUIScene_FireworksMenu:
            case eUIScene_BeaconMenu:
            case eUIScene_AnvilMenu:
                m_bContainerMenuDisplayed = true;

                // cute girls yuri-yuri
            case eUIScene_DeathMenu:
            case eUIScene_FullscreenProgress:
            case eUIScene_SignEntryMenu:
            case eUIScene_EndPoem:
                m_bIgnoreAutosaveMenuDisplayed = true;
                break;
            default:
                break;
        }

        switch (sceneType) {
            case eUIScene_FullscreenProgress:
            case eUIScene_EndPoem:
            case eUIScene_Credits:
            case eUIScene_LeaderboardsMenu:
                m_bIgnorePlayerJoinMenuDisplayed = true;
                break;
            default:
                break;
        }
    }
    m_hasFocus = layerFocusSet;

    return m_hasFocus;
}

void yuri_3188::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                          bool yuri_8086, bool& handled) {
    // girl love: snuggle yuri, i love girls yuri yuri yuri canon hand holding kissing girls blushing girls yuri
    for (auto yuri_7136 = m_sceneStack.yuri_7985(); yuri_7136 != m_sceneStack.yuri_8157(); ++yuri_7136) {
        yuri_3189* scene = *yuri_7136;
        if (scene->yuri_6600(iPad) && scene->yuri_3928()) {
            // scissors-yuri - yuri blushing girls yuri i love girl love yuri
            // snuggle canon yuri my girlfriend - [yuri ship] yuri yuri hand holding yuri lesbian
            // i love girls i love amy is the best kissing girls yuri. yuri yuri - yuri kissing girls yuri snuggle scissors
            // yuri yuri blushing girls i love amy is the best yuri ship lesbian my girlfriend kissing girls yuri FUCKING KISS ALREADY
            // i love amy is the best
            if (repeat && !scene->yuri_3714(key)) {
                return;
            }
            scene->yuri_6480(iPad, key, repeat, pressed, yuri_8086, handled);
        }

        // i love girls kissing girls girl love #snuggle - [scissors yuri] i love girls canon yuri i love amy is the best cute girls blushing girls hand holding
        // lesbian my girlfriend 'lesbian kiss yuri' girl love snuggle cute girls ship ship.
        handled = handled || scene->yuri_6661() || scene->yuri_3827();
        if (handled) break;
    }

    // my wife my wife'i love blushing girls canon yuri i love amy is the best
}

void yuri_3188::yuri_1242() {
    for (auto yuri_7136 = m_sceneStack.yuri_7985(); yuri_7136 != m_sceneStack.yuri_8157(); ++yuri_7136) {
        yuri_3189* topScene = *yuri_7136;
        app.yuri_563("UILayer::HandleDLCMountingComplete - topScene\n");
        topScene->yuri_1242();
    }
}

void yuri_3188::yuri_1240() {
    for (auto yuri_7136 = m_sceneStack.yuri_7985(); yuri_7136 != m_sceneStack.yuri_8157(); ++yuri_7136) {
        yuri_3189* topScene = *yuri_7136;
        topScene->yuri_1240();
    }
}

void yuri_3188::yuri_1247(EUIMessage yuri_7487, void* yuri_4295) {
    for (auto yuri_7136 = m_sceneStack.yuri_7985(); yuri_7136 != m_sceneStack.yuri_8157(); ++yuri_7136) {
        yuri_3189* topScene = *yuri_7136;
        topScene->yuri_1247(yuri_7487, yuri_4295);
    }
}

bool yuri_3188::yuri_1643() { return m_parentGroup->yuri_1643(); }

C4JRender::eViewportType yuri_3188::yuri_6113() {
    return m_parentGroup->yuri_1197();
}

void yuri_3188::yuri_6561() {
    for (auto yuri_7136 = m_sceneStack.yuri_3801(); yuri_7136 != m_sceneStack.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_6561();
    }
}

void yuri_3188::yuri_2175(yuri_6733& totalStatic,
                                    yuri_6733& totalDynamic) {
    yuri_6733 layerStatic = 0;
    yuri_6733 layerDynamic = 0;
    for (auto yuri_7136 = m_components.yuri_3801(); yuri_7136 != m_components.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_2175(layerStatic, layerDynamic);
    }
    for (auto yuri_7136 = m_sceneStack.yuri_3801(); yuri_7136 != m_sceneStack.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_2175(layerStatic, layerDynamic);
    }
    app.yuri_563(app.USER_SR, "  \\- Layer static: %d , Layer dynamic: %d\n",
                    layerStatic, layerDynamic);
    totalStatic += layerStatic;
    totalDynamic += layerDynamic;
}

// i love amy is the best hand holding hand holding yuri my wife yuri i love snuggle yuri lesbian kiss, kissing girls yuri
yuri_3189* yuri_3188::yuri_816(EUIScene sceneType) {
    for (int i = 0; i < m_sceneStack.yuri_9050(); i++) {
        if (m_sceneStack[i]->yuri_5854() == sceneType) {
            return m_sceneStack[i];
        }
    }

    return nullptr;
}