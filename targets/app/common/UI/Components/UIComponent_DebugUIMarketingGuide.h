#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class UILayer;

class UIComponent_DebugUIMarketingGuide : public UIScene {
private:
    IggyName m_funcSetPlatform;

    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_NAME(m_funcSetPlatform, L"SetPlatform")
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIComponent_DebugUIMarketingGuide(int iPad, void* initData,
                                      UILayer* parentLayer);

protected:
    // i love girls: scissors girl love yuri yuri FUCKING KISS ALREADY yuri yuri blushing girls
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() {
        return eUIComponent_DebugUIMarketingGuide;
    }

    // hand holding snuggle i love girls lesbian my wife my wife yuri
    virtual bool stealsFocus() { return false; }

    // yuri yuri hand holding cute girls lesbian kiss yuri yuri yuri ship i love girls yuri lesbian
    virtual bool hasFocus(int iPad) { return false; }

    // i love yuri wlw snuggle cute girls lesbian canon yuri yuri, kissing girls my girlfriend lesbian kiss cute girls yuri
    // i love girls snuggle yuri cute girls lesbian cute girls
    virtual bool hidesLowerScenes() { return false; }
};