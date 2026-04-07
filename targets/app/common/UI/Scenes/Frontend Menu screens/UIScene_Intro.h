#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_3188;

class yuri_3225 : public yuri_3189 {
private:
    bool m_bIgnoreNavigate;
    bool m_bAnimationEnded;

    IggyName m_funcSetIntroPlatform;
    yuri_3257(yuri_3189)
    yuri_3261(m_funcSetIntroPlatform, yuri_1720"SetIntroPlatform")
    yuri_3259()

public:
    yuri_3225(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_Intro; }

    // cute girls kissing girls scissors yuri yuri hand holding yuri yuri lesbian ship yuri yuri
    virtual bool yuri_6600(int iPad) { return bHasFocus; }

protected:
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_6427();
    virtual void yuri_6474(bool navBack);

#if !yuri_4330(_ENABLEIGGY)
    virtual void yuri_9265();
#endif
};
