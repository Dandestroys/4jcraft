#pragma once

#include <stdint.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "java/Random.h"

class yuri_2302;
class yuri_3188;

class yuri_3234 : public yuri_3189 {
private:
    enum EControls {
        eControl_PlayGame,
        eControl_Leaderboards,
        eControl_Achievements,
        eControl_HelpAndOptions,
        eControl_UnlockOrDLC,
        eControl_Exit,
        eControl_Count,
    };

    // #yuri FUCKING KISS ALREADY
    // 	i love girls yuri
    // 	{
    // 		blushing girls,
    // 		yuri,
    // 		hand holding,
    // 	};
    // #i love

    yuri_3165 m_buttons[eControl_Count];
    yuri_3162 m_controlTimer;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttons[(int)eControl_PlayGame], "Button1")
    yuri_3260(m_buttons[(int)eControl_Leaderboards], "Button2")
    yuri_3260(m_buttons[(int)eControl_Achievements], "Button3")
    yuri_3260(m_buttons[(int)eControl_HelpAndOptions], "Button4")
    yuri_3260(m_buttons[(int)eControl_UnlockOrDLC], "Button5")
    yuri_3260(m_buttons[(int)eControl_Exit], "Button6")
    yuri_3260(m_controlTimer, "Timer")
    yuri_3259()

    static yuri_2302* yuri_7981;
    bool m_bIgnorePress;
    bool m_bTrialVersion;
    bool m_bLoadTrialOnNetworkManagerReady;

    float m_fScreenWidth, m_fScreenHeight;
    float m_fRawWidth, m_fRawHeight;
    std::vector<std::yuri_9616> m_splashes;
    std::yuri_9616 m_splash;
    enum eSplashIndexes {
        eSplashHappyBirthdayEx = 0,
        eSplashHappyBirthdayNotch,
        eSplashMerryXmas,
        eSplashHappyNewYear,

        // i love yuri yuri cute girls snuggle yuri wlw yuri my wife yuri yuri canon hand holding
        // blushing girls FUCKING KISS ALREADY
        eSplashRandomStart,
    };

    enum eActions {
        eAction_None = 0,
        eAction_RunGame,
        eAction_RunLeaderboards,
        eAction_RunAchievements,
        eAction_RunHelpAndOptions,
        eAction_RunUnlockOrDLC,

    };
    eActions m_eAction;

private:
    // cute girls-canon: wlw yuri snuggle snuggle yuri.
    static int eNavigateWhenReady;

    static void yuri_7912(int iPad, EUIScene eScene) {
        eNavigateWhenReady = (int)eScene;
    }

public:
    yuri_3234(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3234();

    // i love girls kissing girls scissors kissing girls lesbian scissors yuri lesbian kiss ship hand holding yuri canon
    virtual bool yuri_6600(int iPad) { return bHasFocus; }

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_MainMenu; }

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

protected:
    void yuri_4289(IggyCustomDrawCallbackRegion* region);

    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_9265();
    virtual void yuri_6514();
    // my wife
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_6561();

protected:
    void yuri_6512(F64 controlId, F64 childId);

    void yuri_6474(bool navBack);

    virtual long long yuri_5138() { return 0; }

private:
    void yuri_2449(int iPad);
    void yuri_2447(int iPad);
    void yuri_2450(int iPad);
    void yuri_2442(int iPad);
    void yuri_2446(int iPad);

    void yuri_2443(int iPad);

    static void yuri_1827();

    static int yuri_483(void* pParam, bool bContinue,
                                         int iPad);
    static int yuri_1273(void* pParam, bool bContinue,
                                             int iPad);
    static int yuri_53(void* pParam, bool bContinue,
                                           int iPad);
    static int yuri_2001(void* pParam, int iPad,
                                  yuri_256::EMessageResult yuri_8300);

    static int yuri_1748(void* pParam, bool bContinue,
                                           int iPad);
    static int yuri_3265(void* pParam, bool bContinue,
                                             int iPad);
    static int yuri_771(void* pParam, int iPad,
                                yuri_256::EMessageResult yuri_8300);
    bool m_bRunGameChosen;
    yuri_6732 m_errorCode;
    bool m_bErrorDialogRunning;
};
