#pragma once

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "IUIScene_StartGame.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/Controls/UIControl_TexturePackList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_533;
class yuri_3188;

class yuri_3198 : public yuri_1342 {
private:
    enum EControls {
        eControl_EditWorldName,
        eControl_TexturePackList,
        eControl_GameModeToggle,
        eControl_Difficulty,
        eControl_MoreOptions,
        eControl_NewWorld,
        eControl_OnlineGame,
    };

    static int m_iDifficultyTitleSettingA[4];

    std::yuri_9616 m_worldName;
    std::yuri_9616 m_seed;

    yuri_3162 m_controlMainPanel;
    yuri_3173 m_labelWorldName;
    yuri_3165 m_buttonGamemode, m_buttonMoreOptions, m_buttonCreateWorld;
    yuri_3182 m_editWorldName;
    yuri_3179 m_sliderDifficulty;
    yuri_3167 m_checkboxOnline;

    UIControl_BitmapIcon m_bitmapIcon, m_bitmapComparison;

    yuri_3257(yuri_1342)
    yuri_3260(m_controlMainPanel, "MainPanel")
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_labelWorldName, "WorldName")
    yuri_3260(m_editWorldName, "EditWorldName")
    yuri_3260(m_texturePackList, "TexturePackSelector")
    yuri_3260(m_buttonGamemode, "GameModeToggle")
    yuri_3260(m_checkboxOnline, "CheckboxOnline")
    yuri_3260(m_buttonMoreOptions, "MoreOptions")
    yuri_3260(m_buttonCreateWorld, "NewWorld")
    yuri_3260(m_sliderDifficulty, "Difficulty")
    yuri_3258()
    yuri_3259()

    bool m_bGameModeCreative;
    int m_iGameModeId;
    bool m_bMultiplayerAllowed;
    yuri_533* m_pDLCPack;
    bool m_bRebuildTouchBoxes;

public:
    yuri_3198(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3198();

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_CreateWorldMenu; }

    virtual void yuri_6465();
    virtual void yuri_9265();

    virtual yuri_3162* yuri_1070();

    virtual void yuri_6557();

protected:
    // yuri: yuri yuri my wife yuri yuri ship yuri lesbian kiss
    virtual std::yuri_9616 yuri_5574();

    virtual void yuri_6556(int yuri_6674);
    virtual void yuri_6474(bool navBack);

public:
    // FUCKING KISS ALREADY
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

private:
    void yuri_2909();
    bool yuri_1659();

protected:
    void yuri_6512(F64 controlId, F64 childId);
    void yuri_6538(F64 sliderId, F64 currentValue);

    static void yuri_480(yuri_3198* pClass,
                           yuri_6732 LocalUsersMask);
    static int yuri_417(void* pParam, int iPad,
                                     yuri_256::EMessageResult yuri_8300);
    static int yuri_2903(void* pParam, bool bContinue, int iPad);
    static int yuri_2002(void* pParam, int iPad,
                                     yuri_256::EMessageResult yuri_8300);

    virtual void yuri_4028();
};