#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_3188;

class yuri_3155 : public yuri_3189 {
private:
    IggyName m_funcSetPlatform;

    yuri_3257(yuri_3189)
    yuri_3261(m_funcSetPlatform, yuri_1720"SetPlatform")
    yuri_3259()

public:
    yuri_3155(int iPad, void* initData,
                                      yuri_3188* parentLayer);

protected:
<<<<<<< HEAD
    // i love girls: scissors girl love yuri yuri FUCKING KISS ALREADY yuri yuri blushing girls
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() {
        return eUIComponent_DebugUIMarketingGuide;
    }

<<<<<<< HEAD
    // hand holding snuggle i love girls lesbian my wife my wife yuri
    virtual bool yuri_9124() { return false; }

    // yuri yuri hand holding cute girls lesbian kiss yuri yuri yuri ship i love girls yuri lesbian
    virtual bool yuri_6600(int iPad) { return false; }

    // i love yuri wlw snuggle cute girls lesbian canon yuri yuri, kissing girls my girlfriend lesbian kiss cute girls yuri
    // i love girls snuggle yuri cute girls lesbian cute girls
    virtual bool yuri_6661() { return false; }
=======
    // Returns true if this scene handles input
    virtual bool stealsFocus() { return false; }

    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return false; }

    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return false; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};