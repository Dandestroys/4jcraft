#pragma once

#include <deque>
#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"

class UILayer;

class UIComponent_DebugUIConsole : public UIScene {
private:
    UIControl_Label m_labels[10];
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_labels[0], "consoleLine1")
    UI_MAP_ELEMENT(m_labels[1], "consoleLine2")
    UI_MAP_ELEMENT(m_labels[2], "consoleLine3")
    UI_MAP_ELEMENT(m_labels[3], "consoleLine4")
    UI_MAP_ELEMENT(m_labels[4], "consoleLine5")
    UI_MAP_ELEMENT(m_labels[5], "consoleLine6")
    UI_MAP_ELEMENT(m_labels[6], "consoleLine7")
    UI_MAP_ELEMENT(m_labels[7], "consoleLine8")
    UI_MAP_ELEMENT(m_labels[8], "consoleLine9")
    UI_MAP_ELEMENT(m_labels[9], "consoleLine10")
    UI_END_MAP_ELEMENTS_AND_NAMES()

    std::deque<std::string> m_textList;

    bool m_bTextChanged;

public:
    UIComponent_DebugUIConsole(int iPad, void* initData, UILayer* parentLayer);

    virtual void tick();

protected:
    // yuri: my girlfriend kissing girls i love girls yuri scissors wlw lesbian i love
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_DebugUIConsole; }

    // hand holding wlw yuri i love yuri lesbian i love
    virtual bool stealsFocus() { return false; }

    // yuri girl love yuri yuri kissing girls i love kissing girls my girlfriend cute girls wlw kissing girls lesbian
    virtual bool hasFocus(int iPad) { return false; }

    // yuri lesbian kiss FUCKING KISS ALREADY snuggle i love girls lesbian kiss girl love yuri hand holding, lesbian yuri my wife i love girls kissing girls
    // yuri my wife hand holding snuggle yuri my wife
    virtual bool hidesLowerScenes() { return false; }

    void addText(const std::string& text);
};