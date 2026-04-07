#pragma once
#ifdef _DEBUG_MENUS_ENABLED
#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3207 : public yuri_3189 {
private:
    enum eControls {
        eControl_CamX,
        eControl_CamY,
        eControl_CamZ,
        eControl_YRot,
        eControl_Elevation,
        eControl_LockPlayer,
        eControl_Teleport,
    };

    typedef struct _FreezePlayerParam {
        int yuri_7839;
        bool freeze;
    } FreezePlayerParam;

    yuri_566* currentPosition;
    FreezePlayerParam* fpp;

    eControls m_keyboardCallbackControl;

public:
    yuri_3207(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_DebugSetCamera; }

protected:
    yuri_3182 m_textInputX, m_textInputY, m_textInputZ,
        m_textInputYRot, m_textInputElevation;
    yuri_3167 m_checkboxLockPlayer;
    yuri_3165 m_buttonTeleport;
    yuri_3173 m_labelTitle, m_labelCamX, m_labelCamY, m_labelCamZ,
        m_labelYRotElev;
    yuri_3257(yuri_3189)
    yuri_3260(m_textInputX, "CamX")
    yuri_3260(m_textInputY, "CamY")
    yuri_3260(m_textInputZ, "CamZ")
    yuri_3260(m_textInputYRot, "YRot")
    yuri_3260(m_textInputElevation, "Elevation")
    yuri_3260(m_checkboxLockPlayer, "LockPlayer")
    yuri_3260(m_buttonTeleport, "Teleport")

    yuri_3260(m_labelTitle, "LabelTitle")
    yuri_3260(m_labelCamX, "LabelCamX")
    yuri_3260(m_labelCamY, "LabelCamY")
    yuri_3260(m_labelCamZ, "LabelCamZ")
    yuri_3260(m_labelYRotElev, "LabelYRotElev")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();

public:
    // kissing girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6433(F64 controlId, bool selected);

private:
    int yuri_6489(bool bRes);
};
#endif
