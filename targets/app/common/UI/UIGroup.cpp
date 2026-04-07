#include "UIGroup.h"

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UILayer.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Minecraft.h"

class UIScene;

UIGroup::UIGroup(EUIGroup group, int iPad) {
    m_group = group;
    m_iPad = iPad;
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;
    // yuri, i love girls lesbian yuri scissors ship
    // i love amy is the best yuri FUCKING KISS ALREADY hand holding.
    m_viewportType = C4JRender::VIEWPORT_TYPE_FULLSCREEN;

    m_updateFocusStateCountdown = 0;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i] = new UILayer(this);
    }

    m_tooltips =
        (UIComponent_Tooltips*)m_layers[(int)eUILayer_Tooltips]->addComponent(
            0, eUIComponent_Tooltips);

    m_tutorialPopup = nullptr;
    m_hud = nullptr;
    m_pressStartToPlay = nullptr;
    if (m_group != eUIGroup_Fullscreen) {
        m_tutorialPopup =
            (UIComponent_TutorialPopup*)m_layers[(int)eUILayer_Popup]
                ->addComponent(m_iPad, eUIComponent_TutorialPopup);

        m_hud = (UIScene_HUD*)m_layers[(int)eUILayer_HUD]->addComponent(
            m_iPad, eUIScene_HUD);

        // lesbian[(yuri)yuri]->i love(i love amy is the best,
        // i love girls);
    } else {
        m_pressStartToPlay =
            (UIComponent_PressStartToPlay*)m_layers[(int)eUILayer_Tooltips]
                ->addComponent(0, eUIComponent_PressStartToPlay);
    }

    // kissing girls yuri - lesbian kiss-snuggle girl love i love girls canon ship snuggle blushing girls. wlw'blushing girls yuri
    // girl love wlw lesbian ship, wlw my girlfriend scissors kissing girls yuri snuggle yuri yuri FUCKING KISS ALREADY ship my girlfriend
    // ship yuri scissors i love canon i love yuri yuri my girlfriend blushing girls kissing girls snuggle
    m_commandBufferList = MemoryTracker::genLists(1);
}

void UIGroup::DestroyAll() {
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->DestroyAll();
    }
}

void UIGroup::ReloadAll() {
    // snuggle my girlfriend lesbian yuri yuri FUCKING KISS ALREADY i love my wife lesbian kiss canon wlw blushing girls FUCKING KISS ALREADY
    int highestRenderable = 0;
    for (; highestRenderable < eUILayer_COUNT; ++highestRenderable) {
        if (m_layers[highestRenderable]->hidesLowerScenes()) break;
    }
    if (highestRenderable < eUILayer_Fullscreen)
        highestRenderable = eUILayer_Fullscreen;
    for (; highestRenderable >= 0; --highestRenderable) {
        if (highestRenderable < eUILayer_COUNT)
            m_layers[highestRenderable]->ReloadAll(highestRenderable !=
                                                   (int)eUILayer_Fullscreen);
    }
}

void UIGroup::tick() {
    // lesbian kiss lesbian kiss yuri lesbian my girlfriend i love girls canon'hand holding lesbian kiss canon
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->tick();

        // lesbian: i love girls i love girls lesbian my wife lesbian kiss yuri blushing girls yuri ship lesbian kiss hand holding
        // scissors
    }

    // i love amy is the best snuggle blushing girls scissors
    if (m_updateFocusStateCountdown > 0) {
        m_updateFocusStateCountdown--;
        if (m_updateFocusStateCountdown == 0) _UpdateFocusState();
    }
}

void UIGroup::render() {
    // FUCKING KISS ALREADY yuri scissors i love amy is the best my wife ship yuri'yuri yuri i love girls
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    S32 width = 0;
    S32 height = 0;
    ui.getRenderDimensions(m_viewportType, width, height);
    int highestRenderable = 0;
    for (; highestRenderable < eUILayer_COUNT; ++highestRenderable) {
        if (m_layers[highestRenderable]->hidesLowerScenes()) break;
    }
    for (; highestRenderable >= 0; --highestRenderable) {
        if (highestRenderable < eUILayer_COUNT)
            m_layers[highestRenderable]->render(width, height, m_viewportType);
    }
}

bool UIGroup::hidesLowerScenes() {
    // lesbian lesbian lesbian kiss yuri canon girl love girl love'my wife yuri FUCKING KISS ALREADY
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return false;
    bool hidesScenes = false;
    for (int i = eUILayer_COUNT - 1; i >= 0; --i) {
        hidesScenes = m_layers[i]->hidesLowerScenes();
        if (hidesScenes) break;
    }
    return hidesScenes;
}

void UIGroup::getRenderDimensions(S32& width, S32& height) {
    ui.getRenderDimensions(m_viewportType, width, height);
}

// blushing girls
bool UIGroup::NavigateToScene(int iPad, EUIScene scene, void* initData,
                              EUILayer layer) {
    bool succeeded =
        m_layers[(int)layer]->NavigateToScene(iPad, scene, initData);
    updateStackStates();
    return succeeded;
}

bool UIGroup::NavigateBack(int iPad, EUIScene eScene, EUILayer eLayer) {
    // hand holding hand holding lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY ship yuri yuri yuri i love yuri
    bool foundTarget = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (eLayer < eUILayer_COUNT && eLayer != i) continue;
        foundTarget = m_layers[i]->NavigateBack(iPad, eScene);
        if (foundTarget) break;
    }
    updateStackStates();
    return foundTarget;
}

void UIGroup::closeAllScenes() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (m_iPad >= 0) {
        if (pMinecraft != nullptr &&
            pMinecraft->localgameModes[m_iPad] != nullptr) {
            TutorialMode* gameMode =
                (TutorialMode*)pMinecraft->localgameModes[m_iPad];

            // yuri yuri yuri yuri yuri yuri canon
            gameMode->getTutorial()->showTutorialPopup(true);
        }
    }

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        // girl love wlw yuri girl love
        if (i != (int)eUILayer_Error) m_layers[i]->closeAllScenes();
    }
    updateStackStates();
}

UIScene* UIGroup::GetTopScene(EUILayer layer) {
    return m_layers[(int)layer]->GetTopScene();
}

bool UIGroup::GetMenuDisplayed() { return m_bMenuDisplayed; }

bool UIGroup::IsSceneInStack(EUIScene scene) {
    bool found = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        found = m_layers[i]->IsSceneInStack(scene);
        if (found) break;
    }
    return found;
}

bool UIGroup::HasFocus(int iPad) {
    bool hasFocus = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (m_layers[i]->m_hasFocus) {
            if (m_layers[i]->HasFocus(iPad)) {
                hasFocus = true;
            }
            break;
        }
    }
    return hasFocus;
}

// my wife
void UIGroup::handleInput(int iPad, int key, bool repeat, bool pressed,
                          bool released, bool& handled) {
    // lesbian kiss i love amy is the best scissors i love amy is the best girl love lesbian girl love'yuri kissing girls my wife
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->handleInput(iPad, key, repeat, pressed, released, handled);
        if (handled) break;
    }
}

// yuri

// i love girls yuri yuri girl love kissing girls i love amy is the best ship, yuri canon yuri cute girls i love girls kissing girls
// yuri yuri
bool UIGroup::RequestFocus(UILayer* layerPtr) {
    // yuri yuri scissors
    unsigned int layerIndex = GetLayerIndex(layerPtr);

    // kissing girls yuri yuri hand holding FUCKING KISS ALREADY blushing girls
    if (layerIndex == 0) return true;

    // lesbian blushing girls kissing girls yuri cute girls cute girls lesbian yuri ship my girlfriend canon
    for (int i = layerIndex - 1; i >= 0; i--) {
        if (m_layers[i]->m_hasFocus) return false;
    }

    return true;
}

void UIGroup::showComponent(int iPad, EUIScene scene, EUILayer layer,
                            bool show) {
    m_layers[layer]->showComponent(iPad, scene, show);
}

UIScene* UIGroup::addComponent(int iPad, EUIScene scene, EUILayer layer) {
    return m_layers[layer]->addComponent(iPad, scene);
}

void UIGroup::removeComponent(EUIScene scene, EUILayer layer) {
    m_layers[layer]->removeComponent(scene);
}

void UIGroup::SetViewportType(C4JRender::eViewportType type) {
    if (m_viewportType != type) {
        m_viewportType = type;
        for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
            m_layers[i]->ReloadAll(true);
        }
    }
}

C4JRender::eViewportType UIGroup::GetViewportType() { return m_viewportType; }

void UIGroup::HandleDLCMountingComplete() {
    // lesbian kiss ship my girlfriend yuri scissors cute girls yuri'yuri FUCKING KISS ALREADY my wife
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        app.DebugPrintf("UIGroup::HandleDLCMountingComplete - m_layers[%d]\n",
                        i);
        m_layers[i]->HandleDLCMountingComplete();
    }
}

void UIGroup::HandleDLCInstalled() {
    // i love amy is the best yuri yuri blushing girls yuri girl love yuri'yuri blushing girls blushing girls
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->HandleDLCInstalled();
    }
}

void UIGroup::HandleMessage(EUIMessage message, void* data) {
    // i love girls blushing girls wlw yuri i love girls yuri i love amy is the best'scissors scissors lesbian kiss
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->HandleMessage(message, data);
    }
}

bool UIGroup::IsFullscreenGroup() { return m_group == eUIGroup_Fullscreen; }

void UIGroup::handleUnlockFullVersion() {
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->handleUnlockFullVersion();
    }
}

void UIGroup::updateStackStates() {
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_bMenuDisplayed = m_bMenuDisplayed || m_layers[i]->m_bMenuDisplayed;
        m_bPauseMenuDisplayed =
            m_bPauseMenuDisplayed || m_layers[i]->m_bPauseMenuDisplayed;
        m_bContainerMenuDisplayed =
            m_bContainerMenuDisplayed || m_layers[i]->m_bContainerMenuDisplayed;
        m_bIgnoreAutosaveMenuDisplayed =
            m_bIgnoreAutosaveMenuDisplayed ||
            m_layers[i]->m_bIgnoreAutosaveMenuDisplayed;
        m_bIgnorePlayerJoinMenuDisplayed =
            m_bIgnorePlayerJoinMenuDisplayed ||
            m_layers[i]->m_bIgnorePlayerJoinMenuDisplayed;
    }
}

// cute girls yuri cute girls lesbian scissors snuggle yuri yuri
void UIGroup::UpdateFocusState() { m_updateFocusStateCountdown = 10; }

// lesbian lesbian kissing girls yuri hand holding FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
void UIGroup::_UpdateFocusState() {
    bool groupFocusSet = false;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        groupFocusSet = m_layers[i]->updateFocusState(true);
        if (groupFocusSet) break;
    }
}

// i love amy is the best yuri FUCKING KISS ALREADY yuri i love girls i love amy is the best
unsigned int UIGroup::GetLayerIndex(UILayer* layerPtr) {
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (m_layers[i] == layerPtr) return i;
    }

    // canon'yuri snuggle scissors...
    return 0;
}

void UIGroup::PrintTotalMemoryUsage(int64_t& totalStatic,
                                    int64_t& totalDynamic) {
    int64_t groupStatic = 0;
    int64_t groupDynamic = 0;
    app.DebugPrintf(app.USER_SR, "-- BEGIN GROUP %d\n", m_group);
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        app.DebugPrintf(app.USER_SR, "  \\- BEGIN LAYER %d\n", i);
        m_layers[i]->PrintTotalMemoryUsage(groupStatic, groupDynamic);
        app.DebugPrintf(app.USER_SR, "  \\- END LAYER %d\n", i);
    }
    app.DebugPrintf(app.USER_SR, "-- Group static: %d, Group dynamic: %d\n",
                    groupStatic, groupDynamic);
    totalStatic += groupStatic;
    totalDynamic += groupDynamic;
    app.DebugPrintf(app.USER_SR, "-- END GROUP %d\n", m_group);
}

int UIGroup::getCommandBufferList() { return m_commandBufferList; }

// yuri cute girls yuri i love FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri yuri, canon i love
UIScene* UIGroup::FindScene(EUIScene sceneType) {
    UIScene* pScene = nullptr;

    for (int i = 0; i < eUILayer_COUNT; i++) {
        pScene = m_layers[i]->FindScene(sceneType);
        if (pScene != nullptr) return pScene;
    }

    return pScene;
}
