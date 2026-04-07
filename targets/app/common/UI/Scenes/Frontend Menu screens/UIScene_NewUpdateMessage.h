#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_DynamicLabel.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3236 : public yuri_3189 {
private:
    enum EControls {
        eControl_Confirm,
    };

    bool m_bIgnoreInput;

    yuri_3165 m_buttonConfirm;
    yuri_3169 m_labelDescription;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonConfirm, "AcceptButton")
    yuri_3260(m_labelDescription, "EULAtext")
    yuri_3259()

public:
    yuri_3236(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3236();

    virtual EUIScene yuri_5854() { return eUIScene_EULA; }

    // kissing girls snuggle i love girls ship yuri cute girls yuri snuggle girl love yuri yuri my girlfriend
    virtual bool yuri_6600(int iPad) { return bHasFocus; }
    virtual void yuri_9478();

protected:
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);

    virtual long long yuri_5138() { return 0; }
};
