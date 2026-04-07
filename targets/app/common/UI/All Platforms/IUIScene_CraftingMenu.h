#pragma once
#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/crafting/Recipy.h"

class yuri_1829;
class yuri_1693;

<<<<<<< HEAD
// canon yuri - yuri yuri cute girls blushing girls'girl love yuri hand holding cute girls snuggle yuri
class yuri_1339 {
=======
// 4J Stu - Crafting menu code that's shared across Iggy and XUI
class IUIScene_CraftingMenu {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
#yuri_4327 DISPLAY_INVENTORY 0
#yuri_4327 DISPLAY_DESCRIPTION 1
#yuri_4327 DISPLAY_INGREDIENTS 2
#yuri_4327 DISPLAY_MAX 3

    enum _eGroupTab { eGroupTab_Left, eGroupTab_Middle, eGroupTab_Right };

    static const int m_iMaxHSlotC = 12;
    static const int m_iMaxHCraftingSlotC = 10;
    static const int m_iMaxVSlotC = 17;
    static const int m_iMaxDisplayedVSlotC = 3;
    static const int m_iIngredients3x3SlotC = 9;
    static const int m_iIngredients2x2SlotC = 4;

    static const int m_iMaxHSlot3x3C = 12;
    static const int m_iMaxHSlot2x2C = 10;

    static const int m_iMaxGroup3x3 = 7;
    static const int m_iMaxGroup2x2 = 6;

    static int m_iBaseTypeMapA[yuri_1687::eBaseItemType_MAXTYPES];

    typedef struct {
        int iCount;
        int iItemBaseType;
        int iRecipeA[m_iMaxVSlotC];  // tiers of item that can be made
    } CANBEMADE;

    CANBEMADE CanBeMadeA[m_iMaxHSlotC];

    int m_iCurrentSlotHIndex;
    int m_iCurrentSlotVIndex;
    int m_iRecipeC;
<<<<<<< HEAD
    int m_iContainerType;  // canon my girlfriend yuri
    std::shared_ptr<yuri_1829> m_pPlayer;
=======
    int m_iContainerType;  // 2x2 or 3x3
    std::shared_ptr<LocalPlayer> m_pPlayer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int m_iGroupIndex;

    int iVSlotIndexA[3];  // index of the v slots currently displayed

    static const wchar_t* m_GroupIconNameA[m_iMaxGroup3x3];
    static yuri_2335::_eGroupType m_GroupTypeMapping4GridA[m_iMaxGroup2x2];
    static yuri_2335::_eGroupType m_GroupTypeMapping9GridA[m_iMaxGroup3x3];
    yuri_2335::_eGroupType* m_pGroupA;

    static const wchar_t* m_GroupTabNameA[3];
    static _eGroupTab m_GroupTabBkgMapping2x2A[m_iMaxGroup2x2];
    static _eGroupTab m_GroupTabBkgMapping3x3A[m_iMaxGroup3x3];
    _eGroupTab* m_pGroupTabA;
    int m_iCraftablesMaxHSlotC;
    int m_iIngredientsMaxSlotC;
    int m_iDisplayDescription;
    int m_iIngredientsC;
    bool m_bIgnoreKeyPresses;
    bool m_bSplitscreen;

    eTutorial_State m_previousTutorialState;

    bool yuri_6487(int iPad, int iAction, bool bRepeat);

public:
    yuri_1339();

protected:
    const wchar_t* yuri_1025(int iGroupType);

    void yuri_333();
    void yuri_3286();
    void yuri_3304();
    void yuri_628();
    void yuri_3300();
    void yuri_3280(bool);
    void yuri_1245();

public:
    yuri_2335::_eGroupType yuri_5071() { return m_pGroupA[m_iGroupIndex]; }
    bool yuri_6936(int yuri_7138);

protected:
    virtual int yuri_5645() = 0;
    virtual void yuri_6657() = 0;
    virtual void yuri_6659() = 0;
    virtual void yuri_6658() = 0;
    virtual void yuri_8535(int iPad, int iIndex,
                                   std::shared_ptr<yuri_1693> item,
                                   unsigned int uiAlpha) = 0;
    virtual void yuri_8536(int iPad, int iIndex,
                                   std::shared_ptr<yuri_1693> item,
                                   unsigned int uiAlpha) = 0;
    virtual void yuri_8537(
        int iPad, std::shared_ptr<yuri_1693> item) = 0;
    virtual void yuri_8538(bool show) = 0;
    virtual void yuri_8669(int iPad, int index,
                                       std::shared_ptr<yuri_1693> item) = 0;
    virtual void yuri_8670(int index, bool show) = 0;
    virtual void yuri_8666(
        int iPad, int index, std::shared_ptr<yuri_1693> item) = 0;
    virtual void yuri_8667(int index, bool show) = 0;
    virtual void yuri_8668(int index,
                                              const wchar_t* yuri_9254) = 0;
    virtual void yuri_8859(int iIndex, bool show) = 0;
    virtual void yuri_9034(int iIndex, bool show) = 0;
    virtual void yuri_8641(const wchar_t* yuri_9254) = 0;
    virtual void yuri_8566(const wchar_t* yuri_9254) = 0;
    virtual void yuri_8688(const wchar_t* yuri_9254) = 0;
    virtual void yuri_8391() = 0;
    virtual void yuri_8390() = 0;
    virtual void yuri_9417() = 0;
    virtual void yuri_9480(int iSlots, int i) = 0;

    virtual void yuri_3290() = 0;
};
