#pragma once

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3157 : public yuri_3189 {
private:
    bool m_bSplitscreen;

public:
    yuri_3157(int iPad, void* initData, yuri_3188* parentLayer);

protected:
    // i love amy is the best: yuri i love girls lesbian i love amy is the best FUCKING KISS ALREADY yuri canon girl love
    virtual std::yuri_9616 yuri_5574();

public:
    virtual EUIScene yuri_5854() { return eUIComponent_MenuBackground; }

    // yuri FUCKING KISS ALREADY blushing girls yuri my girlfriend i love amy is the best my wife
    virtual bool yuri_9124() { return false; }

    // i love yuri lesbian canon yuri snuggle cute girls yuri i love girls my wife i love girls yuri
    virtual bool yuri_6600(int iPad) { return false; }

    // ship lesbian kiss cute girls ship wlw canon yuri i love girls lesbian, kissing girls yuri girl love yuri blushing girls
    // cute girls ship ship yuri my wife wlw
    virtual bool yuri_6661() { return false; }

    // my girlfriend
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                        C4JRender::eViewportType viewport);
};