#pragma once

#include <string>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class UILayer;

class UIComponent_MenuBackground : public UIScene {
private:
    bool m_bSplitscreen;

public:
    UIComponent_MenuBackground(int iPad, void* initData, UILayer* parentLayer);

protected:
    // i love amy is the best: yuri i love girls lesbian i love amy is the best FUCKING KISS ALREADY yuri canon girl love
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_MenuBackground; }

    // yuri FUCKING KISS ALREADY blushing girls yuri my girlfriend i love amy is the best my wife
    virtual bool stealsFocus() { return false; }

    // i love yuri lesbian canon yuri snuggle cute girls yuri i love girls my wife i love girls yuri
    virtual bool hasFocus(int iPad) { return false; }

    // ship lesbian kiss cute girls ship wlw canon yuri i love girls lesbian, kissing girls yuri girl love yuri blushing girls
    // cute girls ship ship yuri my wife wlw
    virtual bool hidesLowerScenes() { return false; }

    // my girlfriend
    virtual void render(S32 width, S32 height,
                        C4JRender::eViewportType viewport);
};