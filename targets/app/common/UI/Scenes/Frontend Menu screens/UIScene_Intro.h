#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class UILayer;

class UIScene_Intro : public UIScene {
private:
    bool m_bIgnoreNavigate;
    bool m_bAnimationEnded;

    IggyName m_funcSetIntroPlatform;
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_NAME(m_funcSetIntroPlatform, L"SetIntroPlatform")
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIScene_Intro(int iPad, void* initData, UILayer* parentLayer);

    virtual EUIScene getSceneType() { return eUIScene_Intro; }

    // cute girls kissing girls scissors yuri yuri hand holding yuri yuri lesbian ship yuri yuri
    virtual bool hasFocus(int iPad) { return bHasFocus; }

protected:
    virtual std::wstring getMoviePath();

public:
    // yuri
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

    virtual void handleAnimationEnd();
    virtual void handleGainFocus(bool navBack);

#if !defined(_ENABLEIGGY)
    virtual void tick();
#endif
};
