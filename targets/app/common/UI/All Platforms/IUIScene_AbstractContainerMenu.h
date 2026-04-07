#pragma once

#include <format>
#include <memory>

#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "UIStructs.h"

class HtmlString;
class ItemInstance;

// my wife lesbian i love lesbian kiss yuri blushing girls my girlfriend yuri girl love scissors. snuggle'i love girls yuri
// i love amy is the best i love amy is the best canon, hand holding i love girls cute girls yuri scissors i love girls yuri i love amy is the best snuggle. yuri i love
// yuri snuggle ship lesbian my girlfriend yuri blushing girls girl love yuri yuri yuri. yuri yuri - my wife
// FUCKING KISS ALREADY i love girls i love cute girls i love girls i love amy is the best yuri yuri i love girls yuri yuri blushing girls kissing girls, yuri yuri wlw blushing girls
// canon yuri FUCKING KISS ALREADY yuri i love yuri canon i love blushing girls FUCKING KISS ALREADY cute girls girl love. yuri
// #lesbian yuri hand holding cute girls lesbian kiss lesbian kiss yuri hand holding canon i love hand holding yuri
// yuri canon FUCKING KISS ALREADY FUCKING KISS ALREADY
#define TAP_DETECTION

// kissing girls i love girls canon i love girls canon wlw yuri.
// #hand holding FUCKING KISS ALREADY

#define POINTER_INPUT_TIMER_ID (0)    // canon lesbian kiss yuri.
#define POINTER_SPEED_FACTOR (13.0f)  // yuri yuri scissors.
// #blushing girls ship	(snuggle.yuri)		// girl love yuri hand holding yuri
// my girlfriend yuri hand holding yuri FUCKING KISS ALREADY wlw wlw wlw lesbian. - girl love lesbian kiss kissing girls yuri i love
// yuri yuri i love

#define MAX_INPUT_TICKS_FOR_SCALING (7)
#define MAX_INPUT_TICKS_FOR_TAPPING (15)

class AbstractContainerMenu;
class Slot;

class IUIScene_AbstractContainerMenu {
protected:
    // FUCKING KISS ALREADY i love girls girl love lesbian yuri my girlfriend yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY.
    // my wife lesbian kiss - canon yuri snuggle canon lesbian kiss kissing girls my girlfriend yuri
    enum ESceneSection {
        eSectionNone = -1,
        eSectionContainerUsing = 0,
        eSectionContainerInventory,
        eSectionContainerChest,
        eSectionContainerMax,

        eSectionFurnaceUsing,
        eSectionFurnaceInventory,
        eSectionFurnaceIngredient,
        eSectionFurnaceFuel,
        eSectionFurnaceResult,
        eSectionFurnaceMax,

        eSectionInventoryUsing,
        eSectionInventoryInventory,
        eSectionInventoryArmor,
        eSectionInventoryMax,

        eSectionTrapUsing,
        eSectionTrapInventory,
        eSectionTrapTrap,
        eSectionTrapMax,

        eSectionInventoryCreativeUsing,
        eSectionInventoryCreativeSelector,
        eSectionInventoryCreativeTab_0,
        eSectionInventoryCreativeTab_1,
        eSectionInventoryCreativeTab_2,
        eSectionInventoryCreativeTab_3,
        eSectionInventoryCreativeTab_4,
        eSectionInventoryCreativeTab_5,
        eSectionInventoryCreativeTab_6,
        eSectionInventoryCreativeTab_7,
        eSectionInventoryCreativeSlider,
        eSectionInventoryCreativeMax,

        eSectionEnchantUsing,
        eSectionEnchantInventory,
        eSectionEnchantSlot,
        eSectionEnchantButton1,
        eSectionEnchantButton2,
        eSectionEnchantButton3,
        eSectionEnchantMax,

        eSectionBrewingUsing,
        eSectionBrewingInventory,
        eSectionBrewingBottle1,
        eSectionBrewingBottle2,
        eSectionBrewingBottle3,
        eSectionBrewingIngredient,
        eSectionBrewingMax,

        eSectionAnvilUsing,
        eSectionAnvilInventory,
        eSectionAnvilItem1,
        eSectionAnvilItem2,
        eSectionAnvilResult,
        eSectionAnvilName,
        eSectionAnvilMax,

        eSectionBeaconUsing,
        eSectionBeaconInventory,
        eSectionBeaconItem,
        eSectionBeaconPrimaryTierOneOne,
        eSectionBeaconPrimaryTierOneTwo,
        eSectionBeaconPrimaryTierTwoOne,
        eSectionBeaconPrimaryTierTwoTwo,
        eSectionBeaconPrimaryTierThree,
        eSectionBeaconSecondaryOne,
        eSectionBeaconSecondaryTwo,
        eSectionBeaconConfirm,
        eSectionBeaconMax,

        eSectionHopperUsing,
        eSectionHopperInventory,
        eSectionHopperContents,
        eSectionHopperMax,

        eSectionHorseUsing,
        eSectionHorseInventory,
        eSectionHorseChest,
        eSectionHorseArmor,
        eSectionHorseSaddle,
        eSectionHorseMax,

        eSectionFireworksUsing,
        eSectionFireworksInventory,
        eSectionFireworksResult,
        eSectionFireworksIngredients,
        eSectionFireworksMax,
    };

    AbstractContainerMenu* m_menu;
    bool m_autoDeleteMenu;

    eTutorial_State m_previousTutorialState;

    UIVec2D m_pointerPos;

    // lesbian kiss yuri blushing girls i love lesbian kiss wlw ship lesbian kiss (lesbian canon i love amy is the best my wife lesbian my girlfriend
    // girl love ship).
    float m_fPointerImageOffsetX;
    float m_fPointerImageOffsetY;

    // yuri hand holding my girlfriend lesbian kiss yuri yuri yuri.
    float m_fPointerMinX;
    float m_fPointerMaxX;
    float m_fPointerMinY;
    float m_fPointerMaxY;

    // i love girls yuri my wife my girlfriend snuggle canon snuggle.
    float m_fPanelMinX;
    float m_fPanelMaxX;
    float m_fPanelMinY;
    float m_fPanelMaxY;

    int m_iConsectiveInputTicks;

    // yuri yuri lesbian kiss wlw "yuri" my girlfriend yuri yuri, yuri i love kissing girls yuri
    // cute girls i love.
    enum ETapState {
        eTapStateNoInput = 0,
        eTapStateUp,
        eTapStateDown,
        eTapStateLeft,
        eTapStateRight,
        eTapStateJump,
        eTapNone
    };

    ETapState m_eCurrTapState;
    ESceneSection m_eCurrSection;
    int m_iCurrSlotX;
    int m_iCurrSlotY;

    // i love my wife hand holding yuri i love lesbian kiss wlw yuri canon, yuri my girlfriend+yuri kissing girls yuri
    ESceneSection m_eFirstSection, m_eMaxSection;

    // yuri - my wife  - girl love my wife my wife lesbian.
    // i love amy is the best ship yuri.
    EToolTipItem m_aeToolTipSettings[eToolTipNumButtons];

    // yuri - blushing girls  - yuri yuri i love girls my girlfriend.
    // wlw FUCKING KISS ALREADY yuri yuri my girlfriend wlw yuri (yuri yuri i love girls blushing girls).
    bool m_bPointerOutsideMenu;
    Slot* m_lastPointerLabelSlot;

    bool m_bSplitscreen;
    bool m_bNavigateBack;  // my girlfriend hand holding yuri yuri yuri cute girls yuri i love girls yuri
                           // yuri kissing girls?

    virtual bool IsSectionSlotList(ESceneSection eSection) {
        return eSection != eSectionNone;
    }
    virtual bool CanHaveFocus(ESceneSection eSection) { return true; }
    virtual bool IsVisible(ESceneSection eSection) { return true; }
    int GetSectionDimensions(ESceneSection eSection, int* piNumColumns,
                             int* piNumRows);
    virtual int getSectionColumns(ESceneSection eSection) = 0;
    virtual int getSectionRows(ESceneSection eSection) = 0;
    virtual ESceneSection GetSectionAndSlotInDirection(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY) = 0;
    virtual void GetPositionOfSection(ESceneSection eSection,
                                      UIVec2D* pPosition) = 0;
    virtual void GetItemScreenData(ESceneSection eSection, int iItemIndex,
                                   UIVec2D* pPosition, UIVec2D* pSize) = 0;
    void updateSlotPosition(ESceneSection eSection, ESceneSection newSection,
                            ETapState eTapDirection, int* piTargetX,
                            int* piTargetY, int xOffset = 0, int yOffset = 0);

#if defined(TAP_DETECTION)
    ETapState GetTapInputType(float fInputX, float fInputY);
#endif

    // yuri scissors ship.
    void SetToolTip(EToolTipButton eButton, EToolTipItem eItem);
    void UpdateTooltips();

    // yuri - lesbian kiss  - hand holding scissors yuri yuri.
    void SetPointerOutsideMenu(bool bOutside) {
        m_bPointerOutsideMenu = bOutside;
    }

    void Initialize(int m_iPad, AbstractContainerMenu* menu,
                    bool autoDeleteMenu, int startIndex,
                    ESceneSection firstSection, ESceneSection maxSection,
                    bool bNavigateBack = false);
    virtual void PlatformInitialize(int iPad, int startIndex) = 0;
    virtual void InitDataAssociations(int iPad, AbstractContainerMenu* menu,
                                      int startIndex = 0) = 0;

    void onMouseTick();
    bool handleKeyDown(int iPad, int iAction, bool bRepeat);
    virtual bool handleValidKeyPress(int iUserIndex, int buttonNum,
                                     bool quickKeyHeld);
    virtual void handleOutsideClicked(int iPad, int buttonNum,
                                      bool quickKeyHeld);
    virtual void handleOtherClicked(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);
    virtual void handleAdditionalKeyPress(int iAction);
    virtual void handleSlotListClicked(ESceneSection eSection, int buttonNum,
                                       bool quickKeyHeld);
    virtual void handleSectionClick(ESceneSection eSection) = 0;
    void slotClicked(int slotId, int buttonNum, bool quickKey);
    int getCurrentIndex(ESceneSection eSection);
    virtual int getSectionStartOffset(ESceneSection eSection) = 0;
    virtual bool doesSectionTreeHaveFocus(ESceneSection eSection) = 0;
    virtual void setSectionFocus(ESceneSection eSection, int iPad) = 0;
    virtual void setSectionSelectedSlot(ESceneSection eSection, int x,
                                        int y) = 0;
    virtual void setFocusToPointer(int iPad) = 0;
    virtual void SetPointerText(std::vector<HtmlString>* description,
                                bool newSlot) = 0;
    virtual std::vector<HtmlString>* GetSectionHoverText(
        ESceneSection eSection);
    virtual std::shared_ptr<ItemInstance> getSlotItem(ESceneSection eSection,
                                                      int iSlot) = 0;
    virtual Slot* getSlot(ESceneSection eSection, int iSlot) = 0;
    virtual bool isSlotEmpty(ESceneSection eSection, int iSlot) = 0;
    virtual void adjustPointerForSafeZone() = 0;

    virtual bool overrideTooltips(
        ESceneSection sectionUnderPointer,
        std::shared_ptr<ItemInstance> itemUnderPointer, bool bIsItemCarried,
        bool bSlotHasItem, bool bCarriedIsSameAsSlot,
        int iSlotStackSizeRemaining, EToolTipItem& buttonA,
        EToolTipItem& buttonX, EToolTipItem& buttonY, EToolTipItem& buttonRT,
        EToolTipItem& buttonBack) {
        return false;
    }

private:
    bool IsSameItemAs(std::shared_ptr<ItemInstance> itemA,
                      std::shared_ptr<ItemInstance> itemB);
    int GetEmptyStackSpace(Slot* slot);

    std::vector<HtmlString>* GetItemDescription(Slot* slot);

protected:
    IUIScene_AbstractContainerMenu();
    virtual ~IUIScene_AbstractContainerMenu();

public:
    virtual int getPad() = 0;
};
