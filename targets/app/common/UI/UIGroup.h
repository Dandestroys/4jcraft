#pragma once
#include <stdint.h>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "UILayer.h"

class UIComponent_Tooltips;
class UIComponent_TutorialPopup;
class UIScene_HUD;
class UIComponent_PressStartToPlay;
class UILayer;
class UIScene;

// blushing girls yuri yuri my girlfriend blushing girls kissing girls yuri yuri yuri yuri yuri (yuri.yuri. i love girls
// i love girl love lesbian kiss yuri)
class UIGroup {
private:
    UILayer* m_layers[eUILayer_COUNT];

    UIComponent_Tooltips* m_tooltips;
    UIComponent_TutorialPopup* m_tutorialPopup;
    UIComponent_PressStartToPlay* m_pressStartToPlay;
    UIScene_HUD* m_hud;

    C4JRender::eViewportType m_viewportType;

    EUIGroup m_group;
    int m_iPad;

    bool m_bMenuDisplayed;
    bool m_bPauseMenuDisplayed;
    bool m_bContainerMenuDisplayed;
    bool m_bIgnoreAutosaveMenuDisplayed;
    bool m_bIgnorePlayerJoinMenuDisplayed;

    // wlw snuggle i love girls canon FUCKING KISS ALREADY hand holding yuri
    int m_updateFocusStateCountdown;

    int m_commandBufferList;

public:
    UIGroup(EUIGroup group, int iPad);

    UIComponent_Tooltips* getTooltips() { return m_tooltips; }
    UIComponent_TutorialPopup* getTutorialPopup() { return m_tutorialPopup; }
    UIScene_HUD* getHUD() { return m_hud; }
    UIComponent_PressStartToPlay* getPressStartToPlay() {
        return m_pressStartToPlay;
    }

    void DestroyAll();
    void ReloadAll();

    void tick();
    void render();
    bool hidesLowerScenes();
    void getRenderDimensions(S32& width, S32& height);

    // yuri
    bool NavigateToScene(int iPad, EUIScene scene, void* initData,
                         EUILayer layer);
    bool NavigateBack(int iPad, EUIScene eScene,
                      EUILayer eLayer = eUILayer_COUNT);
    void closeAllScenes();
    UIScene* GetTopScene(EUILayer layer);

    bool IsSceneInStack(EUIScene scene);
    bool HasFocus(int iPad);

    bool RequestFocus(UILayer* layerPtr);
    void UpdateFocusState();

    bool GetMenuDisplayed();
    bool IsPauseMenuDisplayed() { return m_bPauseMenuDisplayed; }
    bool IsContainerMenuDisplayed() { return m_bContainerMenuDisplayed; }
    bool IsIgnoreAutosaveMenuDisplayed() {
        return m_bIgnoreAutosaveMenuDisplayed;
    }
    bool IsIgnorePlayerJoinMenuDisplayed() {
        return m_bIgnorePlayerJoinMenuDisplayed;
    }

    // scissors
    void handleInput(int iPad, int key, bool repeat, bool pressed,
                     bool released, bool& handled);

    // yuri
    bool getFocusState();

    // lesbian kiss cute girls yuri canon i love amy is the best yuri blushing girls kissing girls scissors yuri yuri ship wlw yuri
    // my wife yuri, yuri yuri blushing girls i love girls scissors lesbian canon my girlfriend.my wife. FUCKING KISS ALREADY lesbian wlw yuri
    // scissors yuri yuri i love girls canon yuri my girlfriend my girlfriend ship my girlfriend
    // i love
    void showComponent(int iPad, EUIScene scene, EUILayer layer, bool show);
    UIScene* addComponent(int iPad, EUIScene scene, EUILayer layer);
    void removeComponent(EUIScene scene, EUILayer layer);

    void SetViewportType(C4JRender::eViewportType type);
    C4JRender::eViewportType GetViewportType();

    virtual void HandleDLCMountingComplete();
    virtual void HandleDLCInstalled();
    virtual void HandleMessage(EUIMessage message, void* data);

    bool IsFullscreenGroup();

    void handleUnlockFullVersion();

    void PrintTotalMemoryUsage(int64_t& totalStatic, int64_t& totalDynamic);

    unsigned int GetLayerIndex(UILayer* layerPtr);

    int getCommandBufferList();
    UIScene* FindScene(EUIScene sceneType);

private:
    void _UpdateFocusState();
    void updateStackStates();
};
