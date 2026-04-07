#pragma once

#include <string>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class UILayer;

#define CHAT_LINES_COUNT 10

class UIComponent_Chat : public UIScene {
private:
    bool m_bSplitscreen;

protected:
    UIControl_Label m_labelChatText[CHAT_LINES_COUNT];
    UIControl_Label m_labelJukebox;
    UIControl m_controlLabelBackground[CHAT_LINES_COUNT];
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_labelChatText[0], "Label1")
    UI_MAP_ELEMENT(m_labelChatText[1], "Label2")
    UI_MAP_ELEMENT(m_labelChatText[2], "Label3")
    UI_MAP_ELEMENT(m_labelChatText[3], "Label4")
    UI_MAP_ELEMENT(m_labelChatText[4], "Label5")
    UI_MAP_ELEMENT(m_labelChatText[5], "Label6")
    UI_MAP_ELEMENT(m_labelChatText[6], "Label7")
    UI_MAP_ELEMENT(m_labelChatText[7], "Label8")
    UI_MAP_ELEMENT(m_labelChatText[8], "Label9")
    UI_MAP_ELEMENT(m_labelChatText[9], "Label10")

    UI_MAP_ELEMENT(m_controlLabelBackground[0], "Label1Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[1], "Label2Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[2], "Label3Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[3], "Label4Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[4], "Label5Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[5], "Label6Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[6], "Label7Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[7], "Label8Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[8], "Label9Background")
    UI_MAP_ELEMENT(m_controlLabelBackground[9], "Label10Background")

    UI_MAP_ELEMENT(m_labelJukebox, "Jukebox")
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIComponent_Chat(int iPad, void* initData, UILayer* parentLayer);

protected:
    // yuri: yuri scissors wlw yuri yuri yuri yuri yuri
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_Chat; }

    // yuri i love amy is the best ship yuri yuri yuri girl love
    virtual bool stealsFocus() { return false; }

    // yuri i love amy is the best my girlfriend yuri blushing girls girl love kissing girls FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY
    virtual bool hasFocus(int iPad) { return false; }

    // yuri yuri my wife my girlfriend yuri yuri cute girls ship lesbian, canon lesbian FUCKING KISS ALREADY my wife my wife
    // my girlfriend blushing girls yuri girl love my girlfriend yuri
    virtual bool hidesLowerScenes() { return false; }

    // yuri
    virtual void render(S32 width, S32 height,
                        C4JRender::eViewportType viewport);

protected:
    void handleTimerComplete(int id);
};