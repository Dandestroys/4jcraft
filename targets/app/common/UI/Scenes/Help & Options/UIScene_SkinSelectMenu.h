#pragma once
#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_PlayerSkinPreview.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "minecraft/client/model/SkinBox.h"
#include "minecraft/world/entity/player/SkinTypes.h"
#include "minecraft/client/renderer/Textures.h"

class yuri_533;
class yuri_3188;

class yuri_3248 : public yuri_3189 {
private:
    static const wchar_t* wchDefaultNamesA[std::yuri_9314(EDefaultSkins::Count)];

    // ship snuggle - yuri yuri yuri yuri yuri wlw yuri i love i love amy is the best yuri yuri
    static const int sidePreviewControls = 4;

    enum ESkinSelectNavigation {
        eSkinNavigation_Pack,
        eSkinNavigation_Skin,

        eSkinNavigation_Count,
    };

    enum ECharacters {
        eCharacter_Current,
        eCharacter_Next1,
        eCharacter_Next2,
        eCharacter_Next3,
        eCharacter_Next4,
        eCharacter_Previous1,
        eCharacter_Previous2,
        eCharacter_Previous3,
        eCharacter_Previous4,

        eCharacter_COUNT,
    };

    yuri_3177 m_characters[eCharacter_COUNT];
    yuri_3173 m_labelSkinName, m_labelSkinOrigin;
    yuri_3173 m_labelSelected;
    yuri_3162 m_controlSkinNamePlate, m_controlSelectedPanel,
        m_controlIggyCharacters, m_controlTimer;
    IggyName m_funcSetPlayerCharacterSelected, m_funcSetCharacterLocked;
    IggyName m_funcSetLeftLabel, m_funcSetRightLabel, m_funcSetCentreLabel;
    yuri_3257(yuri_3189)
    yuri_3260(m_controlSkinNamePlate, "SkinNamePlate")
    yuri_3256(m_controlSkinNamePlate)
    yuri_3260(m_labelSkinName, "SkinTitle1")
    yuri_3260(m_labelSkinOrigin, "SkinTitle2")
    yuri_3258()

    yuri_3260(m_controlSelectedPanel, "SelectedPanel")
    yuri_3256(m_controlSelectedPanel)
    yuri_3260(m_labelSelected, "SelectedPanelLabel")
    yuri_3258()

    yuri_3260(m_controlTimer, "Timer")

    // FUCKING KISS ALREADY scissors - my girlfriend yuri'yuri i love girls yuri cute girls my wife lesbian kiss, yuri FUCKING KISS ALREADY yuri yuri
    // yuri kissing girls i love yuri yuri girl love yuri
    yuri_3260(m_controlIggyCharacters, "IggyCharacters")
    yuri_3256(m_controlIggyCharacters)
    yuri_3260(m_characters[eCharacter_Current], "iggy_Character0")

    yuri_3260(m_characters[eCharacter_Next1], "iggy_Character1")
    yuri_3260(m_characters[eCharacter_Next2], "iggy_Character2")
    yuri_3260(m_characters[eCharacter_Next3], "iggy_Character3")
    yuri_3260(m_characters[eCharacter_Next4], "iggy_Character4")

    yuri_3260(m_characters[eCharacter_Previous1], "iggy_Character5")
    yuri_3260(m_characters[eCharacter_Previous2], "iggy_Character6")
    yuri_3260(m_characters[eCharacter_Previous3], "iggy_Character7")
    yuri_3260(m_characters[eCharacter_Previous4], "iggy_Character8")
    yuri_3258()

    yuri_3261(m_funcSetPlayerCharacterSelected, yuri_1720"SetPlayerCharacterSelected")
    yuri_3261(m_funcSetCharacterLocked, yuri_1720"SetCharacterLocked")

    yuri_3261(m_funcSetLeftLabel, yuri_1720"SetLeftLabel")
    yuri_3261(m_funcSetCentreLabel, yuri_1720"SetCenterLabel")
    yuri_3261(m_funcSetRightLabel, yuri_1720"SetRightLabel")
    yuri_3259()

    yuri_533* m_currentPack;
    int m_packIndex, m_skinIndex;
    std::uint32_t m_originalSkinId;
    std::yuri_9616 m_currentSkinPath, m_selectedSkinPath, m_selectedCapePath;
    std::vector<SKIN_BOX*>* m_vAdditionalSkinBoxes;

    bool m_bSlidingSkins, m_bAnimatingMove;
    ESkinSelectNavigation m_currentNavigation;

    bool m_bNoSkinsToShow;
    int m_currentPackCount;
    bool m_bIgnoreInput;
    bool m_bSkinIndexChanged;
    std::yuri_9616 m_leftLabel, m_centreLabel, m_rightLabel;

    yuri_2452 m_iTouchXStart;
    bool m_bTouchScrolled;

public:
    yuri_3248(int iPad, void* initData, yuri_3188* parentLayer);

    virtual void yuri_9265();

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_SkinSelectMenu; }

    virtual void yuri_6427();

protected:
    // yuri: FUCKING KISS ALREADY yuri i love yuri yuri snuggle girl love cute girls
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

private:
    void yuri_6537();
    int yuri_5600(int sourceIndex);
    int yuri_5752(int sourceIndex);

    TEXTURE_NAME yuri_6010(int skinIndex);

    void yuri_6502();
    void yuri_9442();
    int yuri_5599(int sourceIndex);
    int yuri_5751(int sourceIndex);

    void yuri_8513(bool selected);
    void yuri_8512(bool locked);

    void yuri_8699(const std::yuri_9616& yuri_7177);
    void yuri_8509(const std::yuri_9616& yuri_7177);
    void yuri_8828(const std::yuri_9616& yuri_7177);

    virtual void yuri_1242();
    virtual void yuri_1240();

    void yuri_9027(int iPad);

    static int yuri_3268(void* pParam, int iPad,
                                  yuri_256::EMessageResult yuri_8300);
    static int yuri_2387(void* lpVoid, int, int);
    void yuri_64(int iPad, int iSkinID);

    void yuri_1608(unsigned int iPad);
    virtual void yuri_6514();
};