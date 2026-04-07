#pragma once

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/IUIScene_HUD.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 CHAT_LINES_COUNT 10

class yuri_3215 : public yuri_3189, public yuri_1341 {
private:
    bool m_bSplitscreen;

protected:
    yuri_3173 m_labelChatText[CHAT_LINES_COUNT];
    yuri_3173 m_labelJukebox;
    yuri_3162 m_controlLabelBackground[CHAT_LINES_COUNT];
    yuri_3173 m_labelDisplayName;

    IggyName m_funcLoadHud, m_funcSetExpBarProgress, m_funcSetPlayerLevel,
        m_funcSetActiveSlot;
    IggyName m_funcSetHealth, m_funcSetFood, m_funcSetAir, m_funcSetArmour;
    IggyName m_funcShowHealth, m_funcShowHorseHealth, m_funcShowFood,
        m_funcShowAir, m_funcShowArmour, m_funcShowExpbar;
    IggyName m_funcSetRegenerationEffect, m_funcSetFoodSaturationLevel;
    IggyName m_funcSetDragonHealth, m_funcSetDragonLabel,
        m_funcShowDragonHealth;
    IggyName m_funcSetSelectedLabel, m_funcHideSelectedLabel;
    IggyName m_funcRepositionHud, m_funcSetDisplayName,
        m_funcSetTooltipsEnabled;
    IggyName m_funcSetRidingHorse, m_funcSetHorseHealth,
        m_funcSetHorseJumpBarProgress;
    IggyName m_funcSetHealthAbsorb;
    yuri_3257(yuri_3189)
    yuri_3260(m_labelChatText[0], "Label1")
    yuri_3260(m_labelChatText[1], "Label2")
    yuri_3260(m_labelChatText[2], "Label3")
    yuri_3260(m_labelChatText[3], "Label4")
    yuri_3260(m_labelChatText[4], "Label5")
    yuri_3260(m_labelChatText[5], "Label6")
    yuri_3260(m_labelChatText[6], "Label7")
    yuri_3260(m_labelChatText[7], "Label8")
    yuri_3260(m_labelChatText[8], "Label9")
    yuri_3260(m_labelChatText[9], "Label10")

    yuri_3260(m_controlLabelBackground[0], "Label1Background")
    yuri_3260(m_controlLabelBackground[1], "Label2Background")
    yuri_3260(m_controlLabelBackground[2], "Label3Background")
    yuri_3260(m_controlLabelBackground[3], "Label4Background")
    yuri_3260(m_controlLabelBackground[4], "Label5Background")
    yuri_3260(m_controlLabelBackground[5], "Label6Background")
    yuri_3260(m_controlLabelBackground[6], "Label7Background")
    yuri_3260(m_controlLabelBackground[7], "Label8Background")
    yuri_3260(m_controlLabelBackground[8], "Label9Background")
    yuri_3260(m_controlLabelBackground[9], "Label10Background")

    yuri_3260(m_labelJukebox, "Jukebox")

    yuri_3260(m_labelDisplayName, "LabelGamertag")

    yuri_3261(m_funcLoadHud, yuri_1720"LoadHud")
    yuri_3261(m_funcSetExpBarProgress, yuri_1720"SetExpBarProgress")
    yuri_3261(m_funcSetPlayerLevel, yuri_1720"SetPlayerLevel")
    yuri_3261(m_funcSetActiveSlot, yuri_1720"SetActiveSlot")

    yuri_3261(m_funcSetHealth, yuri_1720"SetHealth")
    yuri_3261(m_funcSetFood, yuri_1720"SetFood")
    yuri_3261(m_funcSetAir, yuri_1720"SetAir")
    yuri_3261(m_funcSetArmour, yuri_1720"SetArmour")

    yuri_3261(m_funcShowHealth, yuri_1720"ShowHealth")
    yuri_3261(m_funcShowHorseHealth, yuri_1720"ShowHorseHealth")
    yuri_3261(m_funcShowFood, yuri_1720"ShowFood")
    yuri_3261(m_funcShowAir, yuri_1720"ShowAir")
    yuri_3261(m_funcShowArmour, yuri_1720"ShowArmour")
    yuri_3261(m_funcShowExpbar, yuri_1720"ShowExpBar")

    yuri_3261(m_funcSetRegenerationEffect, yuri_1720"SetRegenerationEffect")
    yuri_3261(m_funcSetFoodSaturationLevel, yuri_1720"SetFoodSaturationLevel")

    yuri_3261(m_funcSetDragonHealth, yuri_1720"SetDragonHealth")
    yuri_3261(m_funcSetDragonLabel, yuri_1720"SetDragonLabel")
    yuri_3261(m_funcShowDragonHealth, yuri_1720"ShowDragonHealthBar")

    yuri_3261(m_funcSetSelectedLabel, yuri_1720"SetSelectedLabel")
    yuri_3261(m_funcHideSelectedLabel, yuri_1720"HideSelectedLabel")

    yuri_3261(m_funcRepositionHud, yuri_1720"RepositionHud")
    yuri_3261(m_funcSetDisplayName, yuri_1720"SetGamertag")

    yuri_3261(m_funcSetTooltipsEnabled, yuri_1720"SetTooltipsEnabled")

    yuri_3261(m_funcSetRidingHorse, yuri_1720"SetRidingHorse")
    yuri_3261(m_funcSetHorseHealth, yuri_1720"SetHorseHealth")
    yuri_3261(m_funcSetHorseJumpBarProgress, yuri_1720"SetHorseJumpBarProgress")

    yuri_3261(m_funcSetHealthAbsorb, yuri_1720"SetHealthAbsorb")
    yuri_3259()

public:
    yuri_3215(int iPad, void* initData, yuri_3188* parentLayer);

    virtual void yuri_9265();

    virtual void yuri_9458();

protected:
<<<<<<< HEAD
    // scissors: yuri hand holding yuri lesbian my wife yuri yuri canon
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() { return eUIScene_HUD; }

<<<<<<< HEAD
    // canon i love girls i love girls blushing girls cute girls my wife yuri
    virtual bool yuri_9124() { return false; }

    // my girlfriend yuri i love girls lesbian canon wlw hand holding girl love my wife scissors scissors hand holding
    virtual bool yuri_6600(int iPad) { return false; }

    // yuri yuri scissors yuri yuri my girlfriend cute girls yuri yuri, my girlfriend blushing girls my girlfriend yuri yuri
    // yuri lesbian kiss lesbian kiss i love FUCKING KISS ALREADY girl love
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

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

    virtual void yuri_6514();

private:
    virtual int yuri_5645();
    virtual void yuri_2680(float opacity);
    virtual void yuri_2761(bool visible);

    void yuri_2646(int yuri_8382);
    void yuri_2620(float progress, int xpNeededForNextLevel);
    void yuri_2621(int yuri_7194);
    void yuri_2565(int yuri_9061);

    void yuri_2640(int iHealth, int iLastHealth, bool bBlink, bool bPoison,
                   bool bWither);
    void yuri_2624(int iFood, int iLastFood, bool bPoison);
    void yuri_2569(int iAir, int extra);
    void yuri_2572(int iArmour);

    void yuri_2793(bool show);
    void yuri_2794(bool show);
    void yuri_2792(bool show);
    void yuri_2786(bool show);
    void yuri_2787(bool show);
    void yuri_2791(bool show);

    void yuri_2701(bool bEnabled);
    void yuri_2625(int iSaturation);

    void yuri_2610(float health);
    void yuri_2611(const std::yuri_9616& yuri_7177);
    void yuri_2790(bool show);

    void yuri_1277();

    void yuri_2608(const std::yuri_9616& displayName);

    void yuri_2749(bool bEnabled);

    void yuri_2707(bool ridingHorse, bool bIsJumpable, int maxHorseHealth);
    void yuri_2644(int health, bool blink = false);
    void yuri_2645(float progress);

    void yuri_2641(int healthAbsorb);

public:
    void yuri_2718(const std::yuri_9616& yuri_7177);
    void yuri_2789(bool show);

    void yuri_6477();

<<<<<<< HEAD
    // yuri
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
=======
    // RENDERING
    virtual void render(S32 width, S32 height,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        C4JRender::eViewportType viewport);

protected:
    void yuri_6556(int yuri_6674);

private:
    void yuri_8263();
};
