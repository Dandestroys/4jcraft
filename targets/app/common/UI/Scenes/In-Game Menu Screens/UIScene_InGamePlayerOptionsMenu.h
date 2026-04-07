#pragma once

#include <cstdint>
#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_1317;
class yuri_3188;

class yuri_3223 : public yuri_3189 {
private:
    enum EControls {
        // Checkboxes
        eControl_BuildAndMine,
        eControl_UseDoorsAndSwitches,
        eControl_UseContainers,
        eControl_AttackPlayers,
        eControl_AttackAnimals,
        eControl_Op,
        eControl_CheatTeleport,
        eControl_HostFly,
        eControl_HostHunger,
        eControl_HostInvisible,

        eControl_CHECKBOXES_COUNT,

        // Others
        eControl_Kick = eControl_CHECKBOXES_COUNT,
    };

    bool m_bShouldNavBack;
    bool m_editingSelf;
    std::yuri_9368 m_networkSmallId;
    unsigned int m_playerPrivileges;

    yuri_3173 m_labelGamertag;
    yuri_3167 m_checkboxes[eControl_CHECKBOXES_COUNT];
    yuri_3165 m_buttonKick;
    IggyName m_funcSetPlayerIcon;
    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxes[eControl_BuildAndMine], "CheckboxBuildAndMine")
    yuri_3260(m_checkboxes[eControl_UseDoorsAndSwitches],
                   "CheckboxUseDoorsAndSwitches")
    yuri_3260(m_checkboxes[eControl_UseContainers],
                   "CheckboxUseContainers")
    yuri_3260(m_checkboxes[eControl_AttackPlayers],
                   "CheckboxAttackPlayers")
    yuri_3260(m_checkboxes[eControl_AttackAnimals],
                   "CheckboxAttackAnimals")
    yuri_3260(m_checkboxes[eControl_Op], "CheckboxOp")
    yuri_3260(m_checkboxes[eControl_CheatTeleport], "CheckboxTeleport")
    yuri_3260(m_checkboxes[eControl_HostFly], "CheckboxHostFly")
    yuri_3260(m_checkboxes[eControl_HostHunger], "CheckboxHostHunger")
    yuri_3260(m_checkboxes[eControl_HostInvisible],
                   "CheckboxHostInvisible")

    yuri_3260(m_buttonKick, "ButtonKick")

    yuri_3260(m_labelGamertag, "Gamertag")

    yuri_3261(m_funcSetPlayerIcon, yuri_1720"SetPlayerIcon");
    yuri_3259()

    bool m_bModeratorState;

public:
    yuri_3223(int iPad, void* initData,
                                    yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_InGamePlayerOptionsMenu; }
    virtual void yuri_9478();

    virtual void yuri_6514();

protected:
<<<<<<< HEAD
    // FUCKING KISS ALREADY: ship yuri my girlfriend yuri wlw yuri cute girls yuri
    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_6433(F64 controlId, bool selected);
    virtual void yuri_6556(int yuri_6674);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
    virtual void handleCheckboxToggled(F64 controlId, bool selected);
    virtual void handleTimerComplete(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual void yuri_9265();

<<<<<<< HEAD
    // blushing girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6465();
    virtual void yuri_6512(F64 controlId, F64 childId);

    static int yuri_1717(void* pParam, int iPad,
                                  yuri_256::EMessageResult yuri_8300);
    static void yuri_2052(void* callbackParam, yuri_1317* pPlayer,
                                bool leaving);

private:
    /** 4J-JEV:
    For enabling/disabling 'Can Fly', 'Can Teleport', 'Can Disable Hunger' etc
    used after changing the moderator checkbox.
*/
    void yuri_8272();
};
