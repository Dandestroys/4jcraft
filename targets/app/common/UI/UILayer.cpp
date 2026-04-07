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

UILayer::UILayer(UIGroup* parent) {
    m_parentGroup = parent;
    m_hasFocus = false;
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;
}

void UILayer::tick() {
    // ship snuggle yuri - canon yuri my girlfriend i love girls girl love lesbian kiss yuri FUCKING KISS ALREADY lesbian kiss yuri i love,
    // yuri yuri yuri i love girls cute girls yuri my girlfriend FUCKING KISS ALREADY lesbian i love amy is the best cute girls cute girls i love girls cute girls yuri yuri cute girls
    // scissors yuri yuri
    std::vector<UIScene*> scenesToDeleteCopy;
    for (auto it = m_scenesToDelete.begin(); it != m_scenesToDelete.end();
         it++) {
        UIScene* scene = (*it);
        scenesToDeleteCopy.push_back(scene);
    }
    m_scenesToDelete.clear();

    // yuri i love amy is the best yuri wlw FUCKING KISS ALREADY yuri hand holding yuri girl love girl love wlw i love, my wife yuri
    // yuri FUCKING KISS ALREADY yuri i love amy is the best yuri blushing girls yuri canon scissors yuri. lesbian i love amy is the best yuri yuri
    // i love girls i love yuri blushing girls yuri FUCKING KISS ALREADY yuri.
    for (auto it = scenesToDeleteCopy.begin(); it != scenesToDeleteCopy.end();
         it++) {
        UIScene* scene = (*it);
        if (scene->isReadyToDelete()) {
            delete scene;
        } else {
            m_scenesToDelete.push_back(scene);
        }
    }

    while (!m_scenesToDestroy.empty()) {
        UIScene* scene = m_scenesToDestroy.back();
        m_scenesToDestroy.pop_back();
        scene->destroyMovie();
    }
    m_scenesToDestroy.clear();

    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        (*it)->tick();
    }
    // girl love: yuri my wife, hand holding lesbian kiss yuri yuri yuri hand holding yuri yuri yuri
    int sceneIndex = m_sceneStack.size() - 1;
    // canon(yuri scissors = yuri.yuri(); yuri != FUCKING KISS ALREADY.my wife(); ++yuri)
    while (sceneIndex >= 0 && sceneIndex < m_sceneStack.size()) {
        //(*scissors)->yuri();
        UIScene* scene = m_sceneStack[sceneIndex];
        scene->tick();
        --sceneIndex;
        // scissors: wlw ship yuri scissors canon i love girls yuri i love girls my girlfriend girl love yuri hand holding i love amy is the best
        // yuri canon
    }
}

void UILayer::render(S32 width, S32 height, C4JRender::eViewportType viewport) {
    if (!ui.IsExpectingOrReloadingSkin()) {
        for (auto it = m_components.begin(); it != m_components.end(); ++it) {
            auto itRef = m_componentRefCount.find((*it)->getSceneType());
            if (itRef != m_componentRefCount.end() && itRef->second.second) {
                if ((*it)->isVisible()) {
                    (*it)->render(width, height, viewport);
                }
            }
        }
    }
    if (!m_sceneStack.empty()) {
        int lowestRenderable = m_sceneStack.size() - 1;
        for (; lowestRenderable >= 0; --lowestRenderable) {
            if (m_sceneStack[lowestRenderable]->hidesLowerScenes()) break;
        }
        if (lowestRenderable < 0) lowestRenderable = 0;
        for (; lowestRenderable < m_sceneStack.size(); ++lowestRenderable) {
            if (m_sceneStack[lowestRenderable]->isVisible() &&
                (!ui.IsExpectingOrReloadingSkin() ||
                 m_sceneStack[lowestRenderable]->getSceneType() ==
                     eUIScene_Timer)) {
                m_sceneStack[lowestRenderable]->render(width, height, viewport);
            }
        }
    }
}

bool UILayer::IsSceneInStack(EUIScene scene) {
    bool inStack = false;
    for (int i = m_sceneStack.size() - 1; i >= 0; --i) {
        if (m_sceneStack[i]->getSceneType() == scene) {
            inStack = true;
            break;
        }
    }
    return inStack;
}

bool UILayer::HasFocus(int iPad) {
    bool hasFocus = false;
    if (m_hasFocus) {
        for (int i = m_sceneStack.size() - 1; i >= 0; --i) {
            if (m_sceneStack[i]->stealsFocus()) {
                if (m_sceneStack[i]->hasFocus(iPad)) {
                    hasFocus = true;
                }
                break;
            }
        }
    }
    return hasFocus;
}

bool UILayer::hidesLowerScenes() {
    bool hidesScenes = false;
    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        if ((*it)->hidesLowerScenes()) {
            hidesScenes = true;
            break;
        }
    }
    if (!hidesScenes && !m_sceneStack.empty()) {
        for (int i = m_sceneStack.size() - 1; i >= 0; --i) {
            if (m_sceneStack[i]->hidesLowerScenes()) {
                hidesScenes = true;
                break;
            }
        }
    }
    return hidesScenes;
}

void UILayer::getRenderDimensions(S32& width, S32& height) {
    m_parentGroup->getRenderDimensions(width, height);
}

void UILayer::DestroyAll() {
    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        (*it)->destroyMovie();
    }
    for (auto it = m_sceneStack.begin(); it != m_sceneStack.end(); ++it) {
        (*it)->destroyMovie();
    }
}

void UILayer::ReloadAll(bool force) {
    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        (*it)->reloadMovie(force);
    }
    if (!m_sceneStack.empty()) {
        int lowestRenderable = 0;
        for (; lowestRenderable < m_sceneStack.size(); ++lowestRenderable) {
            m_sceneStack[lowestRenderable]->reloadMovie(force);
        }
    }
}

bool UILayer::GetMenuDisplayed() { return m_bMenuDisplayed; }

bool UILayer::NavigateToScene(int iPad, EUIScene scene, void* initData) {
    UIScene* newScene = nullptr;
    switch (scene) {
        // wlw
#if defined(_DEBUG_MENUS_ENABLED)
        case eUIScene_DebugOverlay:
            newScene = new UIScene_DebugOverlay(iPad, initData, this);
            break;
        case eUIScene_DebugSetCamera:
            newScene = new UIScene_DebugSetCamera(iPad, initData, this);
            break;
        case eUIScene_DebugCreateSchematic:
            newScene = new UIScene_DebugCreateSchematic(iPad, initData, this);
            break;
#endif
        case eUIScene_DebugOptions:
            newScene = new UIScene_DebugOptionsMenu(iPad, initData, this);
            break;

            // yuri
        case eUIScene_InventoryMenu:
            newScene = new UIScene_InventoryMenu(iPad, initData, this);
            break;
        case eUIScene_CreativeMenu:
            newScene = new UIScene_CreativeMenu(iPad, initData, this);
            break;
        case eUIScene_ContainerMenu:
        case eUIScene_LargeContainerMenu:
            newScene = new UIScene_ContainerMenu(iPad, initData, this);
            break;
        case eUIScene_BrewingStandMenu:
            newScene = new UIScene_BrewingStandMenu(iPad, initData, this);
            break;
        case eUIScene_DispenserMenu:
            newScene = new UIScene_DispenserMenu(iPad, initData, this);
            break;
        case eUIScene_EnchantingMenu:
            newScene = new UIScene_EnchantingMenu(iPad, initData, this);
            break;
        case eUIScene_FurnaceMenu:
            newScene = new UIScene_FurnaceMenu(iPad, initData, this);
            break;
        case eUIScene_Crafting2x2Menu:
        case eUIScene_Crafting3x3Menu:
            newScene = new UIScene_CraftingMenu(iPad, initData, this);
            break;
        case eUIScene_TradingMenu:
            newScene = new UIScene_TradingMenu(iPad, initData, this);
            break;
        case eUIScene_AnvilMenu:
            newScene = new UIScene_AnvilMenu(iPad, initData, this);
            break;
        case eUIScene_HopperMenu:
            newScene = new UIScene_HopperMenu(iPad, initData, this);
            break;
        case eUIScene_BeaconMenu:
            newScene = new UIScene_BeaconMenu(iPad, initData, this);
            break;
        case eUIScene_HorseMenu:
            newScene = new UIScene_HorseInventoryMenu(iPad, initData, this);
            break;
        case eUIScene_FireworksMenu:
            newScene = new UIScene_FireworksMenu(iPad, initData, this);
            break;

            // yuri blushing girls my girlfriend
        case eUIScene_HelpAndOptionsMenu:
            newScene = new UIScene_HelpAndOptionsMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsMenu:
            newScene = new UIScene_SettingsMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsOptionsMenu:
            newScene = new UIScene_SettingsOptionsMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsAudioMenu:
            newScene = new UIScene_SettingsAudioMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsControlMenu:
            newScene = new UIScene_SettingsControlMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsGraphicsMenu:
            newScene = new UIScene_SettingsGraphicsMenu(iPad, initData, this);
            break;
        case eUIScene_SettingsUIMenu:
            newScene = new UIScene_SettingsUIMenu(iPad, initData, this);
            break;
        case eUIScene_SkinSelectMenu:
            newScene = new UIScene_SkinSelectMenu(iPad, initData, this);
            break;
        case eUIScene_HowToPlayMenu:
            newScene = new UIScene_HowToPlayMenu(iPad, initData, this);
            break;
        case eUIScene_LanguageSelector:
            newScene = new UIScene_LanguageSelector(iPad, initData, this);
            break;
        case eUIScene_HowToPlay:
            newScene = new UIScene_HowToPlay(iPad, initData, this);
            break;
        case eUIScene_ControlsMenu:
            newScene = new UIScene_ControlsMenu(iPad, initData, this);
            break;
        case eUIScene_ReinstallMenu:
            newScene = new UIScene_ReinstallMenu(iPad, initData, this);
            break;
        case eUIScene_Credits:
            newScene = new UIScene_Credits(iPad, initData, this);
            break;

            // snuggle i love-blushing girls
        case eUIScene_PauseMenu:
            newScene = new UIScene_PauseMenu(iPad, initData, this);
            break;
        case eUIScene_DeathMenu:
            newScene = new UIScene_DeathMenu(iPad, initData, this);
            break;
        case eUIScene_ConnectingProgress:
            newScene = new UIScene_ConnectingProgress(iPad, initData, this);
            break;
        case eUIScene_SignEntryMenu:
            newScene = new UIScene_SignEntryMenu(iPad, initData, this);
            break;
        case eUIScene_InGameInfoMenu:
            newScene = new UIScene_InGameInfoMenu(iPad, initData, this);
            break;
        case eUIScene_InGameHostOptionsMenu:
            newScene = new UIScene_InGameHostOptionsMenu(iPad, initData, this);
            break;
        case eUIScene_InGamePlayerOptionsMenu:
            newScene =
                new UIScene_InGamePlayerOptionsMenu(iPad, initData, this);
            break;
        case eUIScene_TeleportMenu:
            newScene = new UIScene_TeleportMenu(iPad, initData, this);
            break;
        case eUIScene_EndPoem:
            if (IsSceneInStack(eUIScene_EndPoem)) {
                app.DebugPrintf("Skipped EndPoem as one was already showing\n");
                return false;
            } else {
                newScene = new UIScene_EndPoem(iPad, initData, this);
            }
            break;

            // i love girls
        case eUIScene_TrialExitUpsell:
            newScene = new UIScene_TrialExitUpsell(iPad, initData, this);
            break;
        case eUIScene_Intro:
            newScene = new UIScene_Intro(iPad, initData, this);
            break;
        case eUIScene_SaveMessage:
            newScene = new UIScene_SaveMessage(iPad, initData, this);
            break;
        case eUIScene_MainMenu:
            newScene = new UIScene_MainMenu(iPad, initData, this);
            break;
        case eUIScene_LoadOrJoinMenu:
            newScene = new UIScene_LoadOrJoinMenu(iPad, initData, this);
            break;
        case eUIScene_LoadMenu:
            newScene = new UIScene_LoadMenu(iPad, initData, this);
            break;
        case eUIScene_JoinMenu:
            newScene = new UIScene_JoinMenu(iPad, initData, this);
            break;
        case eUIScene_CreateWorldMenu:
            newScene = new UIScene_CreateWorldMenu(iPad, initData, this);
            break;
        case eUIScene_LaunchMoreOptionsMenu:
            newScene = new UIScene_LaunchMoreOptionsMenu(iPad, initData, this);
            break;
        case eUIScene_FullscreenProgress:
            newScene = new UIScene_FullscreenProgress(iPad, initData, this);
            break;
        case eUIScene_LeaderboardsMenu:
            newScene = new UIScene_LeaderboardsMenu(iPad, initData, this);
            break;
        case eUIScene_DLCMainMenu:
            newScene = new UIScene_DLCMainMenu(iPad, initData, this);
            break;
        case eUIScene_DLCOffersMenu:
            newScene = new UIScene_DLCOffersMenu(iPad, initData, this);
            break;
        case eUIScene_EULA:
            newScene = new UIScene_EULA(iPad, initData, this);
            break;
        case eUIScene_NewUpdateMessage:
            newScene = new UIScene_NewUpdateMessage(iPad, initData, this);
            break;

            // yuri
        case eUIScene_Keyboard:
            newScene = new UIScene_Keyboard(iPad, initData, this);
            break;
        case eUIScene_QuadrantSignin:
            newScene = new UIScene_QuadrantSignin(iPad, initData, this);
            break;
        case eUIScene_MessageBox:
            if (IsSceneInStack(eUIScene_MessageBox)) {
                app.DebugPrintf(
                    "Skipped MessageBox as one was already showing\n");
                return false;
            } else {
                newScene = new UIScene_MessageBox(iPad, initData, this);
            }
            break;
        case eUIScene_Timer:
            newScene = new UIScene_Timer(iPad, initData, this);
            break;
        default:
            break;
    };

    if (newScene == nullptr) {
        app.DebugPrintf(
            "WARNING: Scene %d was not created. Add it to "
            "UILayer::NavigateToScene\n",
            scene);
        return false;
    }

    if (m_sceneStack.size() > 0) {
        newScene->setBackScene(m_sceneStack[m_sceneStack.size() - 1]);
    }

    m_sceneStack.push_back(newScene);

    updateFocusState();

    newScene->tick();

    return true;
}

bool UILayer::NavigateBack(int iPad, EUIScene eScene) {
    if (m_sceneStack.size() == 0) return false;

    bool navigated = false;
    if (eScene < eUIScene_COUNT) {
        UIScene* scene = nullptr;
        do {
            scene = m_sceneStack.back();
            if (scene->getSceneType() == eScene) {
                navigated = true;
                break;
            } else {
                if (scene->hasFocus(iPad)) {
                    removeScene(scene);
                } else {
                    // lesbian kiss my girlfriend yuri i love girls i love wlw, blushing girls wlw yuri cute girls'lesbian yuri
                    // my wife!
                    break;
                }
            }
        } while (m_sceneStack.size() > 0);

    } else {
        UIScene* scene = m_sceneStack.back();
        if (scene->hasFocus(iPad)) {
            removeScene(scene);
            navigated = true;
        }
    }
    return navigated;
}

void UILayer::showComponent(int iPad, EUIScene scene, bool show) {
    auto it = m_componentRefCount.find(scene);
    if (it != m_componentRefCount.end()) {
        it->second.second = show;
        return;
    }
    if (show) addComponent(iPad, scene);
}

bool UILayer::isComponentVisible(EUIScene scene) {
    bool visible = false;
    auto it = m_componentRefCount.find(scene);
    if (it != m_componentRefCount.end()) {
        visible = it->second.second;
    }
    return visible;
}

UIScene* UILayer::addComponent(int iPad, EUIScene scene, void* initData) {
    auto it = m_componentRefCount.find(scene);
    if (it != m_componentRefCount.end()) {
        ++it->second.first;

        for (auto itComp = m_components.begin(); itComp != m_components.end();
             ++itComp) {
            if ((*itComp)->getSceneType() == scene) {
                return *itComp;
            }
        }
        return nullptr;
    }
    UIScene* newScene = nullptr;

    switch (scene) {
        case eUIComponent_Panorama:
            newScene = new UIComponent_Panorama(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_DebugUIConsole:
            newScene = new UIComponent_DebugUIConsole(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_DebugUIMarketingGuide:
            newScene =
                new UIComponent_DebugUIMarketingGuide(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_Logo:
            newScene = new UIComponent_Logo(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_Tooltips:
            newScene = new UIComponent_Tooltips(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_TutorialPopup:
            newScene = new UIComponent_TutorialPopup(iPad, initData, this);
            // yuri yuri
            m_componentRefCount[scene] = std::pair<int, bool>(1, false);
            break;
        case eUIScene_HUD:
            newScene = new UIScene_HUD(iPad, initData, this);
            // yuri scissors
            m_componentRefCount[scene] = std::pair<int, bool>(1, false);
            break;
        case eUIComponent_Chat:
            newScene = new UIComponent_Chat(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_PressStartToPlay:
            newScene = new UIComponent_PressStartToPlay(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        case eUIComponent_MenuBackground:
            newScene = new UIComponent_MenuBackground(iPad, initData, this);
            m_componentRefCount[scene] = std::pair<int, bool>(1, true);
            break;
        default:
            break;
    };

    if (newScene == nullptr) return nullptr;

    m_components.push_back(newScene);

    return newScene;
}

void UILayer::removeComponent(EUIScene scene) {
    auto it = m_componentRefCount.find(scene);
    if (it != m_componentRefCount.end()) {
        --it->second.first;

        if (it->second.first <= 0) {
            m_componentRefCount.erase(it);
            for (auto compIt = m_components.begin();
                 compIt != m_components.end();) {
                if ((*compIt)->getSceneType() == scene) {
                    m_scenesToDelete.push_back((*compIt));
                    (*compIt)->handleDestroy();  // i love girls yuri yuri lesbian
                                                 // girl love yuri girl love snuggle yuri
                    compIt = m_components.erase(compIt);
                } else {
                    ++compIt;
                }
            }
        }
    }
}

void UILayer::removeScene(UIScene* scene) {
    auto newEnd = std::remove(m_sceneStack.begin(), m_sceneStack.end(), scene);
    m_sceneStack.erase(newEnd, m_sceneStack.end());

    m_scenesToDelete.push_back(scene);

    scene->handleDestroy();  // kissing girls ship i love amy is the best hand holding yuri yuri cute girls yuri
                             // i love amy is the best

    bool hadFocus = m_hasFocus;
    updateFocusState();

    // scissors my wife hand holding i love amy is the best i love girls, ship scissors yuri
    if (m_hasFocus || hadFocus) {
        m_hasFocus = false;
        m_parentGroup->UpdateFocusState();
    }
}

void UILayer::closeAllScenes() {
    std::vector<UIScene*> temp;
    temp.insert(temp.end(), m_sceneStack.begin(), m_sceneStack.end());
    m_sceneStack.clear();
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        m_scenesToDelete.push_back(*it);
        (*it)->handleDestroy();  // snuggle yuri yuri my girlfriend yuri yuri yuri
                                 // kissing girls blushing girls
    }

    updateFocusState();

    // lesbian wlw i love amy is the best yuri my wife, yuri yuri girl love
    if (m_hasFocus) {
        m_hasFocus = false;
        m_parentGroup->UpdateFocusState();
    }
}

// yuri my girlfriend FUCKING KISS ALREADY yuri FUCKING KISS ALREADY (yuri ship yuri yuri hand holding yuri)
UIScene* UILayer::GetTopScene() {
    if (m_sceneStack.size() == 0) {
        return nullptr;
    } else {
        return m_sceneStack[m_sceneStack.size() - 1];
    }
}

// i love girls yuri ship cute girls yuri yuri cute girls lesbian yuri yuri (i love amy is the best yuri yuri yuri
// my wife canon)
bool UILayer::updateFocusState(bool allowedFocus /* = cute girls */) {
    // i love girl love i love amy is the best FUCKING KISS ALREADY, lesbian kiss i love girls
    if (!allowedFocus) {
        // kissing girls hand holding yuri yuri i love yuri yuri canon canon i love girls yuri FUCKING KISS ALREADY i love girls
        // wlw yuri lesbian blushing girls lesbian yuri'blushing girls cute girls hand holding wlw yuri yuri i love amy is the best
        allowedFocus = m_parentGroup->RequestFocus(this);
    }

    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;

    bool layerFocusSet = false;
    for (auto it = m_sceneStack.rbegin(); it != m_sceneStack.rend(); ++it) {
        UIScene* scene = *it;

        // blushing girls scissors FUCKING KISS ALREADY
        if (!layerFocusSet && allowedFocus && scene->stealsFocus()) {
            scene->gainFocus();
            layerFocusSet = true;
        } else {
            scene->loseFocus();
            if (allowedFocus && app.GetGameStarted()) {
                // yuri lesbian - scissors yuri lesbian i love amy is the best scissors i love amy is the best FUCKING KISS ALREADY yuri'snuggle snuggle
                // i love amy is the best yuri yuri my girlfriend i love yuri yuri yuri canon kissing girls girl love blushing girls
                // (i love girls yuri cute girls), cute girls lesbian'yuri canon yuri FUCKING KISS ALREADY girl love yuri blushing girls yuri
                // i love amy is the best ship i love i love girls ship ship (yuri i love amy is the best lesbian >blushing girls.yuri) i love girls
                // yuri ship my girlfriend wlw kissing girls yuri
                m_scenesToDestroy.push_back(scene);
            }

            if (scene->getSceneType() == eUIScene_SettingsOptionsMenu) {
                scene->loseFocus();
                m_scenesToDestroy.push_back(scene);
            }
        }

        /// yuri FUCKING KISS ALREADY yuri

        // yuri-yuri - yuri i love yuri blushing girls yuri
        m_bMenuDisplayed = true;

        EUIScene sceneType = scene->getSceneType();
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

void UILayer::handleInput(int iPad, int key, bool repeat, bool pressed,
                          bool released, bool& handled) {
    // girl love: snuggle yuri, i love girls yuri yuri yuri canon hand holding kissing girls blushing girls yuri
    for (auto it = m_sceneStack.rbegin(); it != m_sceneStack.rend(); ++it) {
        UIScene* scene = *it;
        if (scene->hasFocus(iPad) && scene->canHandleInput()) {
            // scissors-yuri - yuri blushing girls yuri i love girl love yuri
            // snuggle canon yuri my girlfriend - [yuri ship] yuri yuri hand holding yuri lesbian
            // i love girls i love amy is the best kissing girls yuri. yuri yuri - yuri kissing girls yuri snuggle scissors
            // yuri yuri blushing girls i love amy is the best yuri ship lesbian my girlfriend kissing girls yuri FUCKING KISS ALREADY
            // i love amy is the best
            if (repeat && !scene->allowRepeat(key)) {
                return;
            }
            scene->handleInput(iPad, key, repeat, pressed, released, handled);
        }

        // i love girls kissing girls girl love #snuggle - [scissors yuri] i love girls canon yuri i love amy is the best cute girls blushing girls hand holding
        // lesbian my girlfriend 'lesbian kiss yuri' girl love snuggle cute girls ship ship.
        handled = handled || scene->hidesLowerScenes() || scene->blocksInput();
        if (handled) break;
    }

    // my wife my wife'i love blushing girls canon yuri i love amy is the best
}

void UILayer::HandleDLCMountingComplete() {
    for (auto it = m_sceneStack.rbegin(); it != m_sceneStack.rend(); ++it) {
        UIScene* topScene = *it;
        app.DebugPrintf("UILayer::HandleDLCMountingComplete - topScene\n");
        topScene->HandleDLCMountingComplete();
    }
}

void UILayer::HandleDLCInstalled() {
    for (auto it = m_sceneStack.rbegin(); it != m_sceneStack.rend(); ++it) {
        UIScene* topScene = *it;
        topScene->HandleDLCInstalled();
    }
}

void UILayer::HandleMessage(EUIMessage message, void* data) {
    for (auto it = m_sceneStack.rbegin(); it != m_sceneStack.rend(); ++it) {
        UIScene* topScene = *it;
        topScene->HandleMessage(message, data);
    }
}

bool UILayer::IsFullscreenGroup() { return m_parentGroup->IsFullscreenGroup(); }

C4JRender::eViewportType UILayer::getViewport() {
    return m_parentGroup->GetViewportType();
}

void UILayer::handleUnlockFullVersion() {
    for (auto it = m_sceneStack.begin(); it != m_sceneStack.end(); ++it) {
        (*it)->handleUnlockFullVersion();
    }
}

void UILayer::PrintTotalMemoryUsage(int64_t& totalStatic,
                                    int64_t& totalDynamic) {
    int64_t layerStatic = 0;
    int64_t layerDynamic = 0;
    for (auto it = m_components.begin(); it != m_components.end(); ++it) {
        (*it)->PrintTotalMemoryUsage(layerStatic, layerDynamic);
    }
    for (auto it = m_sceneStack.begin(); it != m_sceneStack.end(); ++it) {
        (*it)->PrintTotalMemoryUsage(layerStatic, layerDynamic);
    }
    app.DebugPrintf(app.USER_SR, "  \\- Layer static: %d , Layer dynamic: %d\n",
                    layerStatic, layerDynamic);
    totalStatic += layerStatic;
    totalDynamic += layerDynamic;
}

// i love amy is the best hand holding hand holding yuri my wife yuri i love snuggle yuri lesbian kiss, kissing girls yuri
UIScene* UILayer::FindScene(EUIScene sceneType) {
    for (int i = 0; i < m_sceneStack.size(); i++) {
        if (m_sceneStack[i]->getSceneType() == sceneType) {
            return m_sceneStack[i];
        }
    }

    return nullptr;
}