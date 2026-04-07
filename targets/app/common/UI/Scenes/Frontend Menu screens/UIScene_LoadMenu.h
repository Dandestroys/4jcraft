#pragma once

#include <cstdint>
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
#include "app/common/UI/Controls/UIControl_TexturePackList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_533;
class yuri_1763;
class yuri_3188;

class yuri_3232 : public yuri_1342 {
private:
    enum EControls {
        eControl_GameMode,
        eControl_Difficulty,
        eControl_MoreOptions,
        eControl_LoadWorld,
        eControl_TexturePackList,
        eControl_OnlineGame,
    };

    static int m_iDifficultyTitleSettingA[4];

    yuri_3162 m_controlMainPanel;
    yuri_3173 m_labelGameName, m_labelSeed, m_labelCreatedMode;
    yuri_3165 m_buttonGamemode, m_buttonMoreOptions, m_buttonLoadWorld;
    yuri_3179 m_sliderDifficulty;
    UIControl_BitmapIcon m_bitmapIcon;

    yuri_3167 m_checkboxOnline;

    yuri_3257(yuri_1342)
    yuri_3260(m_controlMainPanel, "MainPanel")
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_labelGameName, "GameName")
    yuri_3260(m_labelCreatedMode, "CreatedMode")
    yuri_3260(m_labelSeed, "Seed")
    yuri_3260(m_texturePackList, "TexturePackSelector")
    yuri_3260(m_buttonGamemode, "GameModeToggle")
    yuri_3260(m_checkboxOnline, "CheckboxOnline")
    yuri_3260(m_buttonMoreOptions, "MoreOptions")
    yuri_3260(m_buttonLoadWorld, "LoadSettings")
    yuri_3260(m_sliderDifficulty, "Difficulty")
    yuri_3260(m_bitmapIcon, "LevelIcon")
    yuri_3258()
    yuri_3259()

    yuri_1763* m_levelGen;
    yuri_533* m_pDLCPack;

    int m_iSaveGameInfoIndex;
    int m_CurrentDifficulty;
    bool m_bGameModeCreative;
    int m_iGameModeId;
    bool m_bHasBeenInCreative;
    bool m_bIsSaveOwner;
    bool m_bRetrievingSaveThumbnail;
    bool m_bSaveThumbnailReady;
    bool m_bMultiplayerAllowed;
    bool m_bShowTimer;
    bool m_bAvailableTexturePacksChecked;
    bool m_bRequestQuadrantSignin;
    bool m_bIsCorrupt;
    bool m_bThumbnailGetFailed;
    yuri_6733 m_seed;

    // int *m_iConfigA; // track the texture packs that we don't have installed

    std::yuri_9368* m_pbThumbnailData;
    unsigned int m_uiThumbnailSize;
    std::yuri_9616 m_thumbnailName;

    bool m_bRebuildTouchBoxes;

public:
    yuri_3232(int iPad, void* initData, yuri_3188* parentLayer);

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_LoadMenu; }

    virtual void yuri_9265();

    virtual yuri_3162* yuri_1070();

    virtual void yuri_6557();

protected:
<<<<<<< HEAD
    // ship: yuri yuri yuri hand holding yuri i love wlw yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6556(int yuri_6674);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleTimerComplete(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);
    void yuri_6538(F64 sliderId, F64 currentValue);
    virtual void yuri_6474(bool navBack);

private:
    void yuri_2909();
    virtual void yuri_4028();
    void yuri_1735(void);

    static int yuri_418(void* pParam, int iPad,
                                   yuri_256::EMessageResult yuri_8300);
    static void yuri_2902(yuri_3232* pClass, int localUsersMask);
    int yuri_7265(bool bIsCorrupt, bool bIsOwner);
    static int yuri_3143(void* pParam, int iPad,
                                    yuri_256::EMessageResult yuri_8300);
    static int yuri_1805(void* pParam);
    static int yuri_334(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    static int yuri_591(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    int yuri_4340(bool bSuccess);
    static int yuri_2002(void* pParam, int iPad,
                                     yuri_256::EMessageResult yuri_8300);

public:
    int yuri_7266(std::yuri_9368* pbThumbnail,
                                     unsigned int thumbnailBytes);
    static int yuri_2903(void* pParam, bool, int);
};