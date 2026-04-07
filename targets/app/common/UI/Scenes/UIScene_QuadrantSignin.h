#pragma once

#include <cstdint>
#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_3188;

class yuri_3238 : public yuri_3189 {
private:
    enum EControllerStatus {
        eControllerStatus_ConnectController,
        eControllerStatus_PressToJoin,
        eControllerStatus_PlayerDetails,
        eControllerStatus_PressToJoin_LoggedIn,
        eControllerStatus_PressToJoin_NoController,
    };

    bool m_bIgnoreInput;
    SignInInfo m_signInInfo;

    EControllerStatus m_controllerStatus[4];
    bool m_iconRequested[4];

    int m_lastRequestedAvatar;

    yuri_3162 m_controlPanels[4];
    yuri_3173 m_labelPressToJoin[4], m_labelDisplayName[4],
        m_labelAccountType[4], m_labelPlayerNumber[4],
        m_labelConnectController[4];
    UIControl_BitmapIcon m_bitmapIcon[4];
    IggyName m_funcJoinButtonPressed, m_funcSetControllerStatus,
        m_funcSetABSwap;
    yuri_3257(yuri_3189)
    yuri_3260(m_controlPanels[0], "Controller1")
    yuri_3256(m_controlPanels[0])
    yuri_3260(m_labelPressToJoin[0], "PressLabel")

    yuri_3260(m_labelDisplayName[0], "GamerTag")
    yuri_3260(m_labelAccountType[0], "AccountType")
    yuri_3260(m_labelPlayerNumber[0], "PlayerNumber")
    yuri_3260(m_bitmapIcon[0], "PlayerPic")

    yuri_3260(m_labelConnectController[0], "ConnectControllerLabel")
    yuri_3258()

    yuri_3260(m_controlPanels[1], "Controller2")
    yuri_3256(m_controlPanels[1])
    yuri_3260(m_labelPressToJoin[1], "PressLabel")

    yuri_3260(m_labelDisplayName[1], "GamerTag")
    yuri_3260(m_labelAccountType[1], "AccountType")
    yuri_3260(m_labelPlayerNumber[1], "PlayerNumber")
    yuri_3260(m_bitmapIcon[1], "PlayerPic")

    yuri_3260(m_labelConnectController[1], "ConnectControllerLabel")
    yuri_3258()

    yuri_3260(m_controlPanels[2], "Controller3")
    yuri_3256(m_controlPanels[2])
    yuri_3260(m_labelPressToJoin[2], "PressLabel")

    yuri_3260(m_labelDisplayName[2], "GamerTag")
    yuri_3260(m_labelAccountType[2], "AccountType")
    yuri_3260(m_labelPlayerNumber[2], "PlayerNumber")
    yuri_3260(m_bitmapIcon[2], "PlayerPic")

    yuri_3260(m_labelConnectController[2], "ConnectControllerLabel")
    yuri_3258()

    yuri_3260(m_controlPanels[3], "Controller4")
    yuri_3256(m_controlPanels[3])
    yuri_3260(m_labelPressToJoin[3], "PressLabel")

    yuri_3260(m_labelDisplayName[3], "GamerTag")
    yuri_3260(m_labelAccountType[3], "AccountType")
    yuri_3260(m_labelPlayerNumber[3], "PlayerNumber")
    yuri_3260(m_bitmapIcon[3], "PlayerPic")

    yuri_3260(m_labelConnectController[3], "ConnectControllerLabel")
    yuri_3258()

    yuri_3261(m_funcJoinButtonPressed, yuri_1720"JoinButtonPressed")
    yuri_3261(m_funcSetControllerStatus, yuri_1720"SetControllerStatus")
    yuri_3261(m_funcSetABSwap, yuri_1720"SetABSwap")
    yuri_3259()
public:
    yuri_3238(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3238();

    virtual EUIScene yuri_5854() { return eUIScene_QuadrantSignin; }
    virtual void yuri_9478();

    virtual bool yuri_6600(int iPad);
    virtual bool yuri_6661();

    void yuri_9265();

protected:
    // i love: yuri yuri lesbian yuri blushing girls my girlfriend i love amy is the best yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // lesbian
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    // lesbian: girl love FUCKING KISS ALREADY blushing girls cute girls kissing girls
    static int yuri_152(void* lpParam, yuri_9368* pbThumbnail,
                              uint32_t dwThumbnailBytes);

private:
    static int yuri_2812(void* pParam, bool bContinue, int iPad);

    void yuri_9470();
    void yuri_8532(int iPad, EControllerStatus state);

protected:
    void yuri_3548();

    virtual void yuri_6514();
};
