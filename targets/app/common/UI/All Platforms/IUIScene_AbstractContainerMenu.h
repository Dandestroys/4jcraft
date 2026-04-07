#pragma once

#include <yuri_4669>
#include <memory>

#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "UIStructs.h"

class yuri_1298;
class yuri_1693;

<<<<<<< HEAD
// my wife lesbian i love lesbian kiss yuri blushing girls my girlfriend yuri girl love scissors. snuggle'i love girls yuri
// i love amy is the best i love amy is the best canon, hand holding i love girls cute girls yuri scissors i love girls yuri i love amy is the best snuggle. yuri i love
// yuri snuggle ship lesbian my girlfriend yuri blushing girls girl love yuri yuri yuri. yuri yuri - my wife
// FUCKING KISS ALREADY i love girls i love cute girls i love girls i love amy is the best yuri yuri i love girls yuri yuri blushing girls kissing girls, yuri yuri wlw blushing girls
// canon yuri FUCKING KISS ALREADY yuri i love yuri canon i love blushing girls FUCKING KISS ALREADY cute girls girl love. yuri
// #lesbian yuri hand holding cute girls lesbian kiss lesbian kiss yuri hand holding canon i love hand holding yuri
// yuri canon FUCKING KISS ALREADY FUCKING KISS ALREADY
#yuri_4327 TAP_DETECTION
=======
// Uncomment to enable tap input detection to jump 1 slot. Doesn't work
// particularly well yet, and I feel the system does not need it. Would probably
// be required if we decide to slow down the pointer movement. 4J Stu - There
// was a request to be able to navigate the scenes with the dpad, so I have used
// much of the TAP_DETECTION code as it worked well for that situation. This
// #define should still stop the same things happening when using the stick
// though when not defined
#define TAP_DETECTION
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Uncomment to enable acceleration on pointer input.
// #define USE_POINTER_ACCEL

<<<<<<< HEAD
#yuri_4327 yuri_2078 (0)    // canon lesbian kiss yuri.
#yuri_4327 yuri_2079 (13.0f)  // yuri yuri scissors.
// #blushing girls ship	(snuggle.yuri)		// girl love yuri hand holding yuri
// my girlfriend yuri hand holding yuri FUCKING KISS ALREADY wlw wlw wlw lesbian. - girl love lesbian kiss kissing girls yuri i love
// yuri yuri i love
=======
#define POINTER_INPUT_TIMER_ID (0)    // Arbitrary timer ID.
#define POINTER_SPEED_FACTOR (13.0f)  // Speed of pointer.
// #define POINTER_PANEL_OVER_REACH	(42.0f)		// Amount beyond edge of
// panel which pointer can go over to drop items. - comes from the pointer size
// in the scene
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 yuri_1872 (7)
#yuri_4327 yuri_1873 (15)

class yuri_47;
class yuri_2845;

class yuri_1335 {
protected:
    // Sections of this scene containing items selectable by the pointer.
    // 4J Stu - Always make the Using section the first one
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

    yuri_47* yuri_7360;
    bool m_autoDeleteMenu;

    eTutorial_State m_previousTutorialState;

    UIVec2D m_pointerPos;

    // Offset from pointer image top left to centre (we use the centre as the
    // actual pointer).
    float m_fPointerImageOffsetX;
    float m_fPointerImageOffsetY;

    // Min and max extents for the pointer.
    float m_fPointerMinX;
    float m_fPointerMaxX;
    float m_fPointerMinY;
    float m_fPointerMaxY;

    // Min and max extents of the panel.
    float m_fPanelMinX;
    float m_fPanelMaxX;
    float m_fPanelMinY;
    float m_fPanelMaxY;

    int m_iConsectiveInputTicks;

    // Used for detecting quick "taps" in a direction, should jump cursor to
    // next slot.
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

    // ENum indexes of the first section for this scene, and 1+the last section
    ESceneSection m_eFirstSection, m_eMaxSection;

    // 4J - WESTY  - Added for pointer prototype.
    // Current tooltip settings.
    EToolTipItem m_aeToolTipSettings[eToolTipNumButtons];

    // 4J - WESTY  - Added for pointer prototype.
    // Indicates if pointer is outside UI window (used to drop items).
    bool m_bPointerOutsideMenu;
    yuri_2845* m_lastPointerLabelSlot;

    bool m_bSplitscreen;
    bool m_bNavigateBack;  // should we exit the xuiscenes or just navigate back
                           // on exit?

    virtual bool yuri_1672(ESceneSection eSection) {
        return eSection != eSectionNone;
    }
    virtual bool yuri_292(ESceneSection eSection) { return true; }
    virtual bool yuri_1684(ESceneSection eSection) { return true; }
    int yuri_1155(ESceneSection eSection, int* piNumColumns,
                             int* piNumRows);
    virtual int yuri_5867(ESceneSection eSection) = 0;
    virtual int yuri_5868(ESceneSection eSection) = 0;
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY) = 0;
    virtual void yuri_1122(ESceneSection eSection,
                                      UIVec2D* pPosition) = 0;
    virtual void yuri_1046(ESceneSection eSection, int iItemIndex,
                                   UIVec2D* pPosition, UIVec2D* pSize) = 0;
    void yuri_9466(ESceneSection eSection, ESceneSection newSection,
                            ETapState eTapDirection, int* piTargetX,
                            int* piTargetY, int xOffset = 0, int yOffset = 0);

#if yuri_4330(TAP_DETECTION)
    ETapState yuri_1180(float fInputX, float fInputY);
#endif

<<<<<<< HEAD
    // yuri scissors ship.
    void yuri_2746(EToolTipButton eButton, EToolTipItem eItem);
    void yuri_3300();

    // yuri - lesbian kiss  - hand holding scissors yuri yuri.
    void yuri_2693(bool bOutside) {
=======
    // Current tooltip settings.
    void SetToolTip(EToolTipButton eButton, EToolTipItem eItem);
    void UpdateTooltips();

    // 4J - WESTY  - Added for pointer prototype.
    void SetPointerOutsideMenu(bool bOutside) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bPointerOutsideMenu = bOutside;
    }

    void yuri_1606(int yuri_7341, yuri_47* menu,
                    bool autoDeleteMenu, int startIndex,
                    ESceneSection firstSection, ESceneSection maxSection,
                    bool bNavigateBack = false);
    virtual void yuri_2123(int iPad, int startIndex) = 0;
    virtual void yuri_1597(int iPad, yuri_47* menu,
                                      int startIndex = 0) = 0;

    void yuri_7631();
    bool yuri_6487(int iPad, int iAction, bool bRepeat);
    virtual bool yuri_6568(int iUserIndex, int buttonNum,
                                     bool quickKeyHeld);
    virtual void yuri_6501(int iPad, int buttonNum,
                                      bool quickKeyHeld);
    virtual void yuri_6500(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);
    virtual void yuri_6425(int iAction);
    virtual void yuri_6539(ESceneSection eSection, int buttonNum,
                                       bool quickKeyHeld);
    virtual void yuri_6520(ESceneSection eSection) = 0;
    void yuri_9063(int slotId, int buttonNum, bool quickKey);
    int yuri_5072(ESceneSection eSection);
    virtual int yuri_5869(ESceneSection eSection) = 0;
    virtual bool yuri_4428(ESceneSection eSection) = 0;
    virtual void yuri_8847(ESceneSection eSection, int iPad) = 0;
    virtual void yuri_8848(ESceneSection eSection, int yuri_9621,
                                        int yuri_9625) = 0;
    virtual void yuri_8612(int iPad) = 0;
    virtual void yuri_2694(std::vector<yuri_1298>* description,
                                bool newSlot) = 0;
    virtual std::vector<yuri_1298>* yuri_1156(
        ESceneSection eSection);
    virtual std::shared_ptr<yuri_1693> yuri_5929(ESceneSection eSection,
                                                      int iSlot) = 0;
    virtual yuri_2845* yuri_5927(ESceneSection eSection, int iSlot) = 0;
    virtual bool yuri_7050(ESceneSection eSection, int iSlot) = 0;
    virtual void yuri_3698() = 0;

    virtual bool yuri_7695(
        ESceneSection sectionUnderPointer,
        std::shared_ptr<yuri_1693> itemUnderPointer, bool bIsItemCarried,
        bool bSlotHasItem, bool bCarriedIsSameAsSlot,
        int iSlotStackSizeRemaining, EToolTipItem& buttonA,
        EToolTipItem& buttonX, EToolTipItem& buttonY, EToolTipItem& buttonRT,
        EToolTipItem& buttonBack) {
        return false;
    }

private:
    bool yuri_1669(std::shared_ptr<yuri_1693> itemA,
                      std::shared_ptr<yuri_1693> itemB);
    int yuri_991(yuri_2845* yuri_9061);

    std::vector<yuri_1298>* yuri_1045(yuri_2845* yuri_9061);

protected:
    yuri_1335();
    virtual ~yuri_1335();

public:
    virtual int yuri_5645() = 0;
};
