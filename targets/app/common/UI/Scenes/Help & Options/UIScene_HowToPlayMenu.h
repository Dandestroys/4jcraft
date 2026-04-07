#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3220 : public yuri_3189 {
private:
    enum EControls {
        eControl_Buttons,
    };

    enum eHTPButton {
        eHTPButton_WhatsNew = 0,
        eHTPButton_Basics,
        eHTPButton_Multiplayer,
        eHTPButton_Hud,
        eHTPButton_Creative,
        eHTPButton_Inventory,
        eHTPButton_Chest,
        eHTPButton_Crafting,
        eHTPButton_Furnace,
        eHTPButton_Dispenser,
        eHTPButton_Brewing,
        eHTPButton_Enchantment,
        eHTPButton_Anvil,
        eHTPButton_FarmingAnimals,
        eHTPButton_Breeding,
        eHTPButton_Trading,
        eHTPButton_Horses,
        eHTPButton_Beacons,
        eHTPButton_Fireworks,
        eHTPButton_Hoppers,
        eHTPButton_Droppers,
        eHTPButton_NetherPortal,
        eHTPButton_TheEnd,
        eHTPButton_HostOptions,
        eHTPButton_Max,
    };

    static unsigned int m_uiHTPButtonNameA[eHTPButton_Max];
    static unsigned int m_uiHTPSceneA[eHTPButton_Max];

    yuri_3166 m_buttonListHowTo;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListHowTo, "HowToList")
    yuri_3259()

public:
    yuri_3220(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_HowToPlayMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual void yuri_6514();

protected:
<<<<<<< HEAD
    // yuri: girl love my wife i love girls kissing girls cute girls ship girl love FUCKING KISS ALREADY
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);
};