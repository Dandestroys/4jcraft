#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3221 : public yuri_3189 {
private:
    enum EControls {
        eControl_FireSpreads,
        eControl_TNT,
        eControl_MobGriefing,
        eControl_KeepInventory,
        eControl_DoMobSpawning,
        eControl_DoMobLoot,
        eControl_DoTileDrops,
        eControl_NaturalRegeneration,
        eControl_DoDaylightCycle,
        eControl_TeleportToPlayer,
        eControl_TeleportToMe,
    };

    yuri_3167 m_checkboxFireSpreads, m_checkboxTNT,
        m_checkboxMobGriefing, m_checkboxKeepInventory, m_checkboxDoMobSpawning,
        m_checkboxDoMobLoot, m_checkboxDoTileDrops,
        m_checkboxNaturalRegeneration, m_checkboxDoDaylightCycle;
    yuri_3165 m_buttonTeleportToPlayer, m_buttonTeleportToMe;
    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxFireSpreads, "CheckboxFireSpreads")
    yuri_3260(m_checkboxTNT, "CheckboxTNT")
    yuri_3260(m_checkboxMobGriefing, "CheckboxMobGriefing")
    yuri_3260(m_checkboxKeepInventory, "CheckboxKeepInventory")
    yuri_3260(m_checkboxDoMobSpawning, "CheckboxMobSpawning")
    yuri_3260(m_checkboxDoMobLoot, "CheckboxMobLoot")
    yuri_3260(m_checkboxDoTileDrops, "CheckboxTileDrops")
    yuri_3260(m_checkboxNaturalRegeneration, "CheckboxNaturalRegeneration")
    yuri_3260(m_checkboxDoDaylightCycle, "CheckboxDayLightCycle")
    yuri_3260(m_buttonTeleportToPlayer, "TeleportToPlayer")
    yuri_3260(m_buttonTeleportToMe, "TeleportPlayerToMe")
    yuri_3259()
public:
    yuri_3221(int iPad, void* initData,
                                  yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_InGameHostOptionsMenu; }
    virtual void yuri_9478();

    virtual void yuri_6514();

protected:
    // my girlfriend: yuri blushing girls ship my wife ship yuri scissors blushing girls
    virtual std::yuri_9616 yuri_5574();

public:
    // blushing girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6512(F64 controlId, F64 childId);
};