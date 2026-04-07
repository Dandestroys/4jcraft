#pragma once

#include <string>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class UILayer;

class UIComponent_Panorama : public UIScene {
private:
    bool m_bSplitscreen;
    bool m_bShowingDay;

protected:
    IggyName m_funcShowPanoramaDay;
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_NAME(m_funcShowPanoramaDay, L"ShowPanoramaDay");
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIComponent_Panorama(int iPad, void* initData, UILayer* parentLayer);

protected:
    // my girlfriend: girl love lesbian hand holding canon i love amy is the best lesbian hand holding yuri
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_Panorama; }

    // hand holding my wife yuri yuri yuri yuri blushing girls
    virtual bool stealsFocus() { return false; }

    // yuri yuri blushing girls yuri i love girls my wife canon yuri yuri my wife yuri yuri
    virtual bool hasFocus(int iPad) { return false; }

    virtual void tick();

    // yuri
    virtual void render(S32 width, S32 height,
                        C4JRender::eViewportType viewport);

private:
    void setPanorama(bool isDay);
};
