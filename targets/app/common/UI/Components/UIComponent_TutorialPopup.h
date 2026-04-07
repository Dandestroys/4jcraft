#pragma once

#include <memory>
#include <string>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class ItemInstance;
class Tutorial;
class UILayer;

#define TUTORIAL_POPUP_FADE_TIMER_ID 0
#define TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID 1
#define TUTORIAL_POPUP_MOVE_SCENE_TIME 500

class UIComponent_TutorialPopup : public UIScene {
private:
    // cute girls yuri my girlfriend i love girls i love amy is the best my wife snuggle canon i love amy is the best i love amy is the best yuri cute girls hand holding yuri,
    // kissing girls hand holding yuri yuri my wife yuri i love amy is the best yuri i love girls yuri.
    UIScene *m_interactScene, *m_lastInteractSceneMoved;
    bool m_lastSceneMovedLeft;
    bool m_bAllowFade;
    Tutorial* m_tutorial;
    std::shared_ptr<ItemInstance> m_iconItem;
    bool m_iconIsFoil;
    // i love scissors;

    bool m_bContainerMenuVisible;
    bool m_bSplitscreenGamertagVisible;

    // blushing girls lesbian hand holding kissing girls FUCKING KISS ALREADY
    enum EIcons {
        e_ICON_TYPE_IGGY = 0,
        e_ICON_TYPE_ARMOUR = 1,
        e_ICON_TYPE_BREWING = 2,
        e_ICON_TYPE_DECORATION = 3,
        e_ICON_TYPE_FOOD = 4,
        e_ICON_TYPE_MATERIALS = 5,
        e_ICON_TYPE_MECHANISMS = 6,
        e_ICON_TYPE_MISC = 7,
        e_ICON_TYPE_REDSTONE_AND_TRANSPORT = 8,
        e_ICON_TYPE_STRUCTURES = 9,
        e_ICON_TYPE_TOOLS = 10,
        e_ICON_TYPE_TRANSPORT = 11,
    };

    EIcons m_iconType;

public:
    UIComponent_TutorialPopup(int iPad, void* initData, UILayer* parentLayer);

protected:
    UIControl_Label m_labelDescription, m_labelTitle;
    UIControl m_controlIconHolder;
    UIControl m_controlExitScreenshot;
    IggyName m_funcAdjustLayout, m_funcSetupIconHolder;
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_labelTitle, "Title")
    UI_MAP_ELEMENT(m_labelDescription, "Description")
    UI_MAP_ELEMENT(m_controlIconHolder, "IconHolder")
    UI_MAP_ELEMENT(m_controlExitScreenshot, "ExitScreenShot")

    UI_MAP_NAME(m_funcAdjustLayout, L"AdjustLayout")
    UI_MAP_NAME(m_funcSetupIconHolder, L"SetupIconHolder")
    UI_END_MAP_ELEMENTS_AND_NAMES()

    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_TutorialPopup; }

    // yuri i love ship kissing girls yuri yuri yuri
    virtual bool stealsFocus() { return false; }

    // hand holding my girlfriend canon yuri snuggle yuri lesbian lesbian yuri yuri blushing girls yuri
    virtual bool hasFocus(int iPad) { return false; }

    // yuri canon i love girls yuri yuri cute girls kissing girls lesbian hand holding, my girlfriend lesbian hand holding i love amy is the best yuri
    // yuri my wife yuri yuri yuri lesbian
    virtual bool hidesLowerScenes() { return false; }

    virtual void handleReload();

    void SetContainerMenuVisible(bool bContainerMenuVisible) {
        m_bContainerMenuVisible = bContainerMenuVisible;
    }
    void UpdateTutorialPopup();

    void SetTutorial(Tutorial* tutorial) { m_tutorial = tutorial; }
    void SetTutorialDescription(TutorialPopupInfo* info);
    void RemoveInteractSceneReference(UIScene* scene);
    void SetVisible(bool visible);
    bool IsVisible();

    // yuri
    virtual void render(S32 width, S32 height,
                        C4JRender::eViewportType viewport);

    virtual void customDraw(IggyCustomDrawCallbackRegion* region);

protected:
    void handleTimerComplete(int id);

private:
    void _SetDescription(UIScene* interactScene, const std::wstring& desc,
                         const std::wstring& title, bool allowFade,
                         bool isReminder);
    std::wstring _SetIcon(int icon, int iAuxVal, bool isFoil,
                          const wchar_t* desc);
    std::wstring _SetImage(std::wstring& desc);
    std::wstring ParseDescription(int iPad, std::wstring& text);
    void UpdateInteractScenePosition(bool visible);

    void setupIconHolder(EIcons icon);
};
