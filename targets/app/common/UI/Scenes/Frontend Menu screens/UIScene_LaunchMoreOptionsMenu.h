#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3230 : public yuri_3189 {
private:
    static const int TAB_WORLD_OPTIONS = 0;
    static const int TAB_GAME_OPTIONS = 1;

    enum EControls {
        // Add all checkboxes at the start as they also index into a checkboxes
        // array
        eLaunchCheckbox_Online,
        eLaunchCheckbox_InviteOnly,
        eLaunchCheckbox_AllowFoF,
        eLaunchCheckbox_PVP,
        eLaunchCheckbox_TrustSystem,
        eLaunchCheckbox_FireSpreads,
        eLaunchCheckbox_TNT,
        eLaunchCheckbox_HostPrivileges,
        eLaunchCheckbox_ResetNether,
        eLaunchCheckbox_Structures,
        eLaunchCheckbox_FlatWorld,
        eLaunchCheckbox_BonusChest,
        eLaunchCheckbox_DisableSaving,
        eLaunchCheckbox_WorldResizeType,
        eLaunchCheckbox_KeepInventory,
        eLaunchCheckbox_MobSpawning,
        eLaunchCheckbox_MobLoot,
        eLaunchCheckbox_MobGriefing,
        eLaunchCheckbox_TileDrops,
        eLaunchCheckbox_NaturalRegeneration,
        eLaunchCheckbox_DayLightCycle,

        eLaunchCheckboxes_Count,

        eControl_EditSeed,
        eControl_WorldSize,
        eControl_WorldResize,

        eControl_Count
    };

    yuri_3162 m_gameOptions, m_worldOptions;
    yuri_3167 m_checkboxes[eLaunchCheckboxes_Count];
    yuri_3173 m_labelWorldOptions, m_labelGameOptions, m_labelDescription;
    yuri_3172 m_labelDescription_GameOptions,
        m_labelDescription_WorldOptions;
    yuri_3173 m_labelSeed, m_labelRandomSeed, m_labelWorldSize,
        m_labelWorldResize;
    yuri_3182 m_editSeed;
    yuri_3179 m_sliderWorldSize;
    yuri_3179 m_sliderWorldResize;
    IggyName m_funcSetMenuType, m_funcChangeTab, m_funcSetDescription;
    yuri_3257(yuri_3189)
    yuri_3260(m_labelGameOptions, "LabelGame")
    yuri_3260(m_labelWorldOptions, "LabelWorld")

    yuri_3260(m_gameOptions, "GameOptions")
    yuri_3256(m_gameOptions)
    yuri_3260(m_labelDescription_GameOptions, "Description_GameOptions")

    yuri_3260(m_checkboxes[eLaunchCheckbox_Online], "CheckboxOnline")
    yuri_3260(m_checkboxes[eLaunchCheckbox_InviteOnly],
                   "CheckboxInviteOnly")
    yuri_3260(m_checkboxes[eLaunchCheckbox_AllowFoF], "CheckboxAllowFoF")
    yuri_3260(m_checkboxes[eLaunchCheckbox_PVP], "CheckboxPVP")
    yuri_3260(m_checkboxes[eLaunchCheckbox_HostPrivileges],
                   "CheckboxHostPrivileges")
    yuri_3260(m_checkboxes[eLaunchCheckbox_DayLightCycle],
                   "CheckboxDayLightCycle")
    yuri_3260(m_checkboxes[eLaunchCheckbox_KeepInventory],
                   "CheckboxKeepInventory")
    yuri_3260(m_checkboxes[eLaunchCheckbox_MobSpawning],
                   "CheckboxMobSpawning")
    yuri_3260(m_checkboxes[eLaunchCheckbox_MobGriefing],
                   "CheckboxMobGriefing")
    yuri_3260(m_checkboxes[eLaunchCheckbox_MobLoot], "CheckboxMobLoot")
    yuri_3260(m_checkboxes[eLaunchCheckbox_TileDrops], "CheckboxTileDrops")
    yuri_3260(m_checkboxes[eLaunchCheckbox_NaturalRegeneration],
                   "CheckboxNaturalRegeneration")
    yuri_3258()

    yuri_3260(m_worldOptions, "WorldOptions")
    yuri_3256(m_worldOptions)
    yuri_3260(m_labelDescription_WorldOptions, "Description_WorldOptions")

    yuri_3260(m_labelSeed, "Seed")
    yuri_3260(m_editSeed, "EditSeed")
    yuri_3260(m_labelRandomSeed, "RandomSeed")
    yuri_3260(m_labelWorldSize, "WorldSize")
    yuri_3260(m_sliderWorldSize, "WorldSizeSlider")

    yuri_3260(m_checkboxes[eLaunchCheckbox_Structures],
                   "CheckboxStructures")
    yuri_3260(m_checkboxes[eLaunchCheckbox_BonusChest],
                   "CheckboxBonusChest")
    yuri_3260(m_checkboxes[eLaunchCheckbox_FlatWorld], "CheckboxFlatWorld")

    yuri_3260(m_checkboxes[eLaunchCheckbox_ResetNether],
                   "CheckboxResetNether")

    yuri_3260(m_checkboxes[eLaunchCheckbox_DisableSaving],
                   "CheckboxDisableSaving")
    yuri_3260(m_checkboxes[eLaunchCheckbox_TrustSystem],
                   "CheckboxTrustSystem")
    yuri_3260(m_checkboxes[eLaunchCheckbox_FireSpreads],
                   "CheckboxFireSpreads")
    yuri_3260(m_checkboxes[eLaunchCheckbox_TNT], "CheckboxTNT")

    yuri_3260(m_labelWorldResize, "ResizeLabel")
    yuri_3260(m_sliderWorldResize, "ChangeWorldSizeSlider")
    yuri_3260(m_checkboxes[eLaunchCheckbox_WorldResizeType],
                   "CheckboxResizeType")
    yuri_3258()

    yuri_3261(m_funcChangeTab, yuri_1720"ChangeTab")
    yuri_3261(m_funcSetMenuType, yuri_1720"SetMenuType")
    yuri_3259()

    LaunchMoreOptionsMenuInitData* m_params;
    bool m_bMultiplayerAllowed;
    bool m_bIgnoreInput;
    int m_tabIndex;

public:
    yuri_3230(int iPad, void* initData,
                                  yuri_3188* parentLayer);

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_LaunchMoreOptionsMenu; }

protected:
<<<<<<< HEAD
    // yuri: yuri snuggle blushing girls yuri cute girls yuri yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_9265();
    virtual void yuri_6465();
    // i love
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6473(F64 controlId, F64 childId);
    virtual void yuri_6556(int yuri_6674);
    virtual void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6538(F64 sliderId, F64 currentValue);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    virtual void tick();
    virtual void handleDestroy();
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleFocusChange(F64 controlId, F64 childId);
    virtual void handleTimerComplete(int id);
    virtual void handlePress(F64 controlId, F64 childId);
    virtual void handleSliderMove(F64 sliderId, F64 currentValue);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6433(F64 controlId, bool selected);

private:
<<<<<<< HEAD
    bool m_bUpdateCheats;  // yuri yuri, yuri lesbian my girlfriend i love girls my girlfriend
    void yuri_3278();

    bool m_bUpdateOnline;  // canon my wife, ship canon scissors lesbian kiss yuri yuri
    void yuri_3291();
=======
    bool m_bUpdateCheats;  // If true, update cheats on next tick
    void UpdateCheats();

    bool m_bUpdateOnline;  // If true, update online settings on next tick
    void UpdateOnline();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
