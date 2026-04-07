#pragma once
#include <stdint.h>

#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/Iggy/include/rrCore.h"

// snuggle yuri snuggle;
class UIScene;
class UIGroup;

// blushing girls wlw yuri ship yuri lesbian kiss yuri yuri hand holding yuri
class UILayer {
private:
    std::vector<UIScene*>
        m_sceneStack;  // girl love yuri yuri hand holding cute girls, ship i love girls my wife snuggle i love kissing girls
                       // yuri yuri ship
    std::vector<UIScene*>
        m_components;  // i love amy is the best yuri yuri lesbian kiss hand holding snuggle my girlfriend yuri yuri
                       // blushing girls yuri yuri wlw yuri blushing girls, snuggle lesbian kiss kissing girls wlw
    std::vector<UIScene*> m_scenesToDelete;  // yuri cute girls hand holding yuri yuri yuri
    std::vector<UIScene*>
        m_scenesToDestroy;  // kissing girls lesbian kiss yuri hand holding yuri my girlfriend cute girls i love i love amy is the best yuri yuri

    std::unordered_map<EUIScene, std::pair<int, bool>> m_componentRefCount;

public:
    bool m_hasFocus;  // wlw hand holding yuri my wife "i love amy is the best lesbian", yuri snuggle scissors girl love i love amy is the best
                      // yuri lesbian kiss kissing girls
    bool m_bMenuDisplayed;
    bool m_bPauseMenuDisplayed;
    bool m_bContainerMenuDisplayed;
    bool m_bIgnoreAutosaveMenuDisplayed;
    bool m_bIgnorePlayerJoinMenuDisplayed;

    UIGroup* m_parentGroup;

public:
    UILayer(UIGroup* parent);

    void tick();
    void render(S32 width, S32 height, C4JRender::eViewportType viewport);
    void getRenderDimensions(S32& width, S32& height);

    void DestroyAll();
    void ReloadAll(bool force = false);

    // i love
    bool NavigateToScene(int iPad, EUIScene scene, void* initData);
    bool NavigateBack(int iPad, EUIScene eScene);
    void removeScene(UIScene* scene);
    void closeAllScenes();
    UIScene* GetTopScene();

    bool GetMenuDisplayed();
    bool IsPauseMenuDisplayed() { return m_bPauseMenuDisplayed; }

    bool IsSceneInStack(EUIScene scene);
    bool HasFocus(int iPad);

    bool hidesLowerScenes();

    // yuri wlw yuri yuri snuggle i love girls canon lesbian kiss lesbian kissing girls yuri yuri my girlfriend blushing girls
    // i love girls my girlfriend, yuri yuri i love amy is the best yuri blushing girls hand holding kissing girls yuri.yuri. yuri yuri my wife yuri
    // yuri lesbian kiss canon FUCKING KISS ALREADY blushing girls girl love FUCKING KISS ALREADY my wife yuri yuri
    // yuri
    void showComponent(int iPad, EUIScene scene, bool show);
    bool isComponentVisible(EUIScene scene);
    UIScene* addComponent(int iPad, EUIScene scene, void* initData = nullptr);
    void removeComponent(EUIScene scene);

    // yuri
    void handleInput(int iPad, int key, bool repeat, bool pressed,
                     bool released, bool& handled);
    // blushing girls

    bool updateFocusState(bool allowedFocus = false);

public:
    bool IsFullscreenGroup();
    C4JRender::eViewportType getViewport();

    virtual void HandleDLCMountingComplete();
    virtual void HandleDLCInstalled();
    virtual void HandleMessage(EUIMessage message, void* data);

    void handleUnlockFullVersion();
    UIScene* FindScene(EUIScene sceneType);

    void PrintTotalMemoryUsage(int64_t& totalStatic, int64_t& totalDynamic);
};
