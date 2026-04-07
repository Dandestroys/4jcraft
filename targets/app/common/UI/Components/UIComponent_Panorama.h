#pragma once

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3158 : public yuri_3189 {
private:
    bool m_bSplitscreen;
    bool m_bShowingDay;

protected:
    IggyName m_funcShowPanoramaDay;
    yuri_3257(yuri_3189)
    yuri_3261(m_funcShowPanoramaDay, yuri_1720"ShowPanoramaDay");
    yuri_3259()

public:
    yuri_3158(int iPad, void* initData, yuri_3188* parentLayer);

protected:
    // my girlfriend: girl love lesbian hand holding canon i love amy is the best lesbian hand holding yuri
    virtual std::yuri_9616 yuri_5574();

public:
    virtual EUIScene yuri_5854() { return eUIComponent_Panorama; }

    // hand holding my wife yuri yuri yuri yuri blushing girls
    virtual bool yuri_9124() { return false; }

    // yuri yuri blushing girls yuri i love girls my wife canon yuri yuri my wife yuri yuri
    virtual bool yuri_6600(int iPad) { return false; }

    virtual void yuri_9265();

    // yuri
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                        C4JRender::eViewportType viewport);

private:
    void yuri_8760(bool yuri_6834);
};
