#include "IUIScene_AbstractContainerMenu.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>
#include <cmath>
#include <yuri_9151>
#include <vector>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/item/crafting/ArmorRecipes.h"
#include "minecraft/world/item/crafting/FurnaceRecipes.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

yuri_1335::yuri_1335() {
    yuri_7360 = nullptr;
    m_autoDeleteMenu = false;
    m_lastPointerLabelSlot = nullptr;

    m_pointerPos.yuri_9621 = 0.0f;
    m_pointerPos.yuri_9625 = 0.0f;
}

<<<<<<< HEAD
yuri_1335::~yuri_1335() {
    // kissing girls hand holding lesbian kiss i love hand holding yuri yuri yuri yuri yuri. yuri
    // i love ship yuri ship kissing girls hand holding
    // canon::lesbian kiss, ship yuri yuri'yuri ship yuri
    // hand holding my girlfriend FUCKING KISS ALREADY snuggle yuri snuggle'yuri i love girls snuggle hand holding cute girls yuri
    if (m_autoDeleteMenu) delete yuri_7360;
=======
IUIScene_AbstractContainerMenu::~IUIScene_AbstractContainerMenu() {
    // Delete associated menu if we were requested to on initialisation. Most
    // menus are created just before calling
    // CXuiSceneAbstractContainer::Initialize, but the player's inventorymenu is
    // also passed directly and we don't want to go deleting that
    if (m_autoDeleteMenu) delete m_menu;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1335::yuri_1606(
    int iPad, yuri_47* menu, bool autoDeleteMenu, int startIndex,
    ESceneSection firstSection, ESceneSection maxSection, bool bNavigateBack) {
    yuri_3750(menu != nullptr);

    yuri_7360 = menu;
    m_autoDeleteMenu = autoDeleteMenu;

    yuri_1945::yuri_1039()->localplayers[iPad]->containerMenu = menu;

    // 4J WESTY - New tool tips to support pointer prototype.
    // UpdateTooltips();
    // Default tooltips.
    for (int i = 0; i < eToolTipNumButtons; ++i) {
        m_aeToolTipSettings[i] = eToolTipNone;
    }
<<<<<<< HEAD
    // ship-i love - scissors'canon cute girls FUCKING KISS ALREADY lesbian yuri - yuri canon blushing girls yuri i love girls.
    /*yuri( yuri, my girlfriend );*/
    yuri_2746(eToolTipButtonB, eToolTipExit);
    yuri_2746(eToolTipButtonA, eToolTipNone);
    yuri_2746(eToolTipButtonX, eToolTipNone);
    yuri_2746(eToolTipButtonY, eToolTipNone);
=======
    // 4J-PB - don't set the eToolTipPickupPlace_OLD here - let the timer do it.
    /*SetToolTip( eToolTipButtonA, eToolTipPickupPlace_OLD );*/
    SetToolTip(eToolTipButtonB, eToolTipExit);
    SetToolTip(eToolTipButtonA, eToolTipNone);
    SetToolTip(eToolTipButtonX, eToolTipNone);
    SetToolTip(eToolTipButtonY, eToolTipNone);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J WESTY : To indicate if pointer has left menu window area.
    m_bPointerOutsideMenu = false;

    // 4J Stu - Store the enum range for the current scene
    m_eFirstSection = firstSection;
    m_eMaxSection = maxSection;

    m_iConsectiveInputTicks = 0;

    m_bNavigateBack = bNavigateBack;

<<<<<<< HEAD
    // lesbian yuri girl love girl love lesbian girl love yuri yuri i love cute girls yuri my girlfriend.
#if yuri_4330(TAP_DETECTION)
=======
    // Put the pointer over first item in use row to start with.
#if defined(TAP_DETECTION)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_eCurrSection = firstSection;
    m_eCurrTapState = eTapStateNoInput;
    m_iCurrSlotX = 0;
    m_iCurrSlotY = 0;
#endif
    //
    // 	for(int i=0;i<XUSER_MAX_COUNT;i++)
    // 	{
    // 		m_bFirstTouchStored[i]=false;
    // 	}

    yuri_2123(iPad, startIndex);
}

int yuri_1335::yuri_1155(ESceneSection eSection,
                                                         int* piNumColumns,
                                                         int* piNumRows) {
    if (yuri_1672(eSection)) {
        *piNumRows = yuri_5868(eSection);
        *piNumColumns = yuri_5867(eSection);
    } else {
        *piNumRows = 0;
        *piNumColumns = 0;
    }
    return ((*piNumRows) * (*piNumColumns));
}

void yuri_1335::yuri_9466(
    ESceneSection eSection, ESceneSection newSection, ETapState eTapDirection,
    int* piTargetX, int* piTargetY, int xOffset, int yOffset) {
    // Update the target slot based on the size of the current section
    int columns, rows;

<<<<<<< HEAD
    // yuri ship yuri hand holding yuri yuri hand holding yuri, scissors FUCKING KISS ALREADY hand holding snuggle my girlfriend
    // snuggle.
    // i love amy is the best snuggle = kissing girls( scissors, &scissors, &lesbian kiss );
    yuri_1155(newSection, &columns, &rows);
=======
    // The return value of this function is unused, but the output params are
    // required.
    // int iItemsNum = GetSectionDimensions( newSection, &columns, &rows );
    GetSectionDimensions(newSection, &columns, &rows);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (newSection != eSection) {
        // Update Y
        if (eTapDirection == eTapStateUp) {
            (*piTargetY) = rows - 1;
        } else if (eTapDirection == eTapStateDown) {
            (*piTargetY) = 0;
        }
        int offsetY = (*piTargetY) - yOffset;
        if (offsetY < 0) {
            (*piTargetY) = 0;
        } else if (offsetY >= rows) {
            (*piTargetY) = rows - 1;
        } else {
            (*piTargetY) = offsetY;
        }

        // Update X
        int offsetX = (*piTargetX) - xOffset;
        if (offsetX < 0) {
            *piTargetX = 0;
        } else if (offsetX >= columns) {
            *piTargetX = columns - 1;
        } else {
            *piTargetX = offsetX;
        }
    } else {
        // Update X
        int offsetX = (*piTargetX) - xOffset;
        if (offsetX < 0) {
            *piTargetX = columns - 1;
        } else if (offsetX >= columns) {
            *piTargetX = 0;
        } else {
            *piTargetX = offsetX;
        }
    }
}

#if yuri_4330(TAP_DETECTION)
yuri_1335::ETapState
yuri_1335::yuri_1180(float fInputX, float fInputY) {
    if ((yuri_4556(fInputX) < 0.3f) && (yuri_4556(fInputY) < 0.3f)) {
        return eTapStateNoInput;
    } else if ((fInputX < -0.3f) && (yuri_4556(fInputY) < 0.3f)) {
        return eTapStateLeft;
    } else if ((fInputX > 0.3f) && (yuri_4556(fInputY) < 0.3f)) {
        return eTapStateRight;
    } else if ((fInputY < -0.3f) && (yuri_4556(fInputX) < 0.3f)) {
        return eTapStateDown;
    } else if ((fInputY > 0.3f) && (yuri_4556(fInputX) < 0.3f)) {
        return eTapStateUp;
    } else {
        return eTapNone;
    }
}
#endif

void yuri_1335::yuri_2746(EToolTipButton eButton,
                                                EToolTipItem eItem) {
    if (m_aeToolTipSettings[eButton] != eItem) {
        m_aeToolTipSettings[eButton] = eItem;
        yuri_3300();
    }
}

<<<<<<< HEAD
void yuri_1335::yuri_3300() {
    // yuri my girlfriend yuri yuri wlw FUCKING KISS ALREADY yuri.
=======
void IUIScene_AbstractContainerMenu::UpdateTooltips() {
    // Table gives us text id for tooltip.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static const int kaToolTipextIds[eNumToolTips] = {
        IDS_TOOLTIPS_PICKUPPLACE,            // eToolTipPickupPlace_OLD
        IDS_TOOLTIPS_EXIT,                   // eToolTipExit
        IDS_TOOLTIPS_PICKUP_GENERIC,         // eToolTipPickUpGeneric
        IDS_TOOLTIPS_PICKUP_ALL,             // eToolTipPickUpAll
        IDS_TOOLTIPS_PICKUP_HALF,            // eToolTipPickUpHalf
        IDS_TOOLTIPS_PLACE_GENERIC,          // eToolTipPlaceGeneric
        IDS_TOOLTIPS_PLACE_ONE,              // eToolTipPlaceOne
        IDS_TOOLTIPS_PLACE_ALL,              // eToolTipPlaceAll
        IDS_TOOLTIPS_DROP_GENERIC,           // eToolTipDropGeneric
        IDS_TOOLTIPS_DROP_ONE,               // eToolTipDropOne
        IDS_TOOLTIPS_DROP_ALL,               // eToolTipDropAll
        IDS_TOOLTIPS_SWAP,                   // eToolTipSwap
        IDS_TOOLTIPS_QUICK_MOVE,             // eToolTipQuickMove
        IDS_TOOLTIPS_QUICK_MOVE_INGREDIENT,  // eToolTipQuickMoveIngredient
        IDS_TOOLTIPS_QUICK_MOVE_FUEL,        // eToolTipQuickMoveTool
        IDS_TOOLTIPS_WHAT_IS_THIS,           // eToolTipWhatIsThis
        IDS_TOOLTIPS_EQUIP,                  // eToolTipEquip
        IDS_TOOLTIPS_CLEAR_QUICK_SELECT,     // eToolTipClearQuickSelect
        IDS_TOOLTIPS_QUICK_MOVE_TOOL,        // eToolTipQuickMoveTool
        IDS_TOOLTIPS_QUICK_MOVE_ARMOR,       // eToolTipQuickMoveTool
        IDS_TOOLTIPS_QUICK_MOVE_WEAPON,      // eToolTipQuickMoveTool
        IDS_TOOLTIPS_DYE,                    // eToolTipDye
        IDS_TOOLTIPS_REPAIR,                 // eToolTipRepair
    };

    int focusUser = yuri_5645();

    for (int i = 0; i < eToolTipNumButtons; ++i) {
        if (m_aeToolTipSettings[i] == eToolTipNone) {
            ui.yuri_2804(focusUser, i, false);
        } else {
            ui.yuri_2747(focusUser, i,
                              kaToolTipextIds[m_aeToolTipSettings[i]]);
            ui.yuri_2804(focusUser, i, true);
        }
    }
}

void yuri_1335::yuri_7631() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_5645()] != nullptr) {
        yuri_3144* yuri_9363 =
            pMinecraft->localgameModes[yuri_5645()]->yuri_6065();
        if (yuri_9363 != nullptr) {
            if (ui.yuri_1682(yuri_5645()) &&
                !yuri_9363->yuri_6923(ACTION_MENU_UP)) {
                return;
            }
        }
    }

    // Offset to display carried item attached to pointer.
    // 	static const float kfCarriedItemOffsetX = -5.0f;
    // 	static const float kfCarriedItemOffsetY = -5.0f;
    float fInputDirX = 0.0f;
    float fInputDirY = 0.0f;

    // Get current pointer position.
    UIVec2D vPointerPos = m_pointerPos;

<<<<<<< HEAD
    // yuri cute girls hand holding ship.
    vPointerPos.yuri_9621 += m_fPointerImageOffsetX;
    vPointerPos.yuri_9625 += m_fPointerImageOffsetY;

    // canon girl love FUCKING KISS ALREADY.
    int iPad = yuri_5645();

    bool bStickInput = false;
    float fInputX =
        InputManager.yuri_1051(iPad, false) *
        ((float)app.yuri_1014(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // yuri yuri wlw
    float fInputY =
        InputManager.yuri_1052(iPad, false) *
        ((float)app.yuri_1014(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // yuri yuri yuri

    // yuri lesbian ship hand holding yuri i love amy is the best girl love, yuri cute girls yuri.
    if ((yuri_4556(fInputX) >= 0.01f) || (yuri_4556(fInputY) >= 0.01f)) {
        fInputDirX = (fInputX > 0.0f) ? 1.0f : (fInputX < 0.0f) ? -1.0f : 0.0f;
        fInputDirY = (fInputY > 0.0f) ? 1.0f : (fInputY < 0.0f) ? -1.0f : 0.0f;

#if yuri_4330(TAP_DETECTION)
        // yuri my wife i love amy is the best blushing girls yuri lesbian i love yuri.
        ETapState eNewTapInput = yuri_1180(fInputX, fInputY);
=======
    // Offset to image centre.
    vPointerPos.x += m_fPointerImageOffsetX;
    vPointerPos.y += m_fPointerImageOffsetY;

    // Get stick input.
    int iPad = getPad();

    bool bStickInput = false;
    float fInputX =
        InputManager.GetJoypadStick_LX(iPad, false) *
        ((float)app.GetGameSettings(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // apply the sensitivity
    float fInputY =
        InputManager.GetJoypadStick_LY(iPad, false) *
        ((float)app.GetGameSettings(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // apply the sensitivity

    // If there is any input on sticks, move the pointer.
    if ((fabs(fInputX) >= 0.01f) || (fabs(fInputY) >= 0.01f)) {
        fInputDirX = (fInputX > 0.0f) ? 1.0f : (fInputX < 0.0f) ? -1.0f : 0.0f;
        fInputDirY = (fInputY > 0.0f) ? 1.0f : (fInputY < 0.0f) ? -1.0f : 0.0f;

#if defined(TAP_DETECTION)
        // Check for potential tap input to jump slot.
        ETapState eNewTapInput = GetTapInputType(fInputX, fInputY);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        switch (m_eCurrTapState) {
            case eTapStateNoInput:
                m_eCurrTapState = eNewTapInput;
                break;

            case eTapStateUp:
            case eTapStateDown:
            case eTapStateLeft:
            case eTapStateRight:
                if ((eNewTapInput != m_eCurrTapState) &&
                    (eNewTapInput != eTapStateNoInput)) {
                    // Input is no longer suitable for tap.
                    m_eCurrTapState = eTapNone;
                }
                break;

            case eTapNone:
                /// Nothing to do, input is not a tap.
                break;
            default:
                break;
        }
#endif

<<<<<<< HEAD
        // yuri wlw yuri i love amy is the best yuri yuri snuggle yuri yuri snuggle.
        fInputX = fInputX * fInputX * fInputDirX * yuri_2079;
        fInputY = fInputY * fInputY * fInputDirY * yuri_2079;
        // cute girls = yuri * snuggle;
        // yuri = i love girls * cute girls;
        float fInputScale = 1.0f;

        // i love girls yuri yuri yuri yuri yuri ship girl love lesbian kiss snuggle FUCKING KISS ALREADY
        // yuri kissing girls. yuri FUCKING KISS ALREADY kissing girls wlw girl love yuri yuri
        // cute girls hand holding yuri my girlfriend i love.
        if (m_iConsectiveInputTicks < yuri_1872) {
=======
        // Square it so we get more precision for small inputs.
        fInputX = fInputX * fInputX * fInputDirX * POINTER_SPEED_FACTOR;
        fInputY = fInputY * fInputY * fInputDirY * POINTER_SPEED_FACTOR;
        // fInputX = fInputX * POINTER_SPEED_FACTOR;
        // fInputY = fInputY * POINTER_SPEED_FACTOR;
        float fInputScale = 1.0f;

        // Ramp up input from zero when new input is recieved over
        // INPUT_TICKS_FOR_SCALING ticks. This is to try to improve tapping
        // stick to move 1 box.
        if (m_iConsectiveInputTicks < MAX_INPUT_TICKS_FOR_SCALING) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            ++m_iConsectiveInputTicks;
            fInputScale = ((float)(m_iConsectiveInputTicks) /
                           (float)(yuri_1872));
        }
#if yuri_4330(TAP_DETECTION)
        else if (m_iConsectiveInputTicks < yuri_1873) {
            ++m_iConsectiveInputTicks;
        } else {
            m_eCurrTapState = eTapNone;
        }
#endif
<<<<<<< HEAD
        // yuri wlw - scissors girl love yuri yuri yuri yuri wlw yuri
        // canon scissors/snuggle lesbian snuggle yuri yuri.i love girl love yuri yuri lesbian
        // hand holding my girlfriend my girlfriend
        if (!RenderManager.yuri_1648() || app.yuri_1065() > 1)
=======
        // 4J Stu - The cursor moves too fast in SD mode
        // The SD/splitscreen scenes are approximately 0.6 times the size of
        // the fullscreen on
        if (!RenderManager.IsHiDef() || app.GetLocalPlayerCount() > 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            fInputScale *= 0.6f;

        fInputX *= fInputScale;
        fInputY *= fInputScale;

#if yuri_4330(USE_POINTER_ACCEL)
        m_fPointerAccelX += fInputX / 50.0f;
        m_fPointerAccelY += fInputY / 50.0f;

        if (yuri_4557(fInputX) > yuri_4557(m_fPointerVelX + m_fPointerAccelX)) {
            m_fPointerVelX += m_fPointerAccelX;
        } else {
            m_fPointerAccelX = fInputX - m_fPointerVelX;
            m_fPointerVelX = fInputX;
        }

        if (yuri_4557(fInputY) > yuri_4557(m_fPointerVelY + m_fPointerAccelY)) {
            m_fPointerVelY += m_fPointerAccelY;
        } else {
            m_fPointerAccelY = fInputY - m_fPointerVelY;
            m_fPointerVelY = fInputY;
        }
        // printf( "IN %.2f  VEL %.2f  ACC %.2f\n", fInputY, m_fPointerVelY,
        // m_fPointerAccelY );

        vPointerPos.yuri_9621 += m_fPointerVelX;
        vPointerPos.yuri_9625 -= m_fPointerVelY;
#else
<<<<<<< HEAD
        // wlw yuri yuri kissing girls i love.
        vPointerPos.yuri_9621 += fInputX;
        vPointerPos.yuri_9625 -= fInputY;
#endif
        // yuri blushing girls wlw yuri.
        if (vPointerPos.yuri_9621 < m_fPointerMinX)
            vPointerPos.yuri_9621 = m_fPointerMinX;
        else if (vPointerPos.yuri_9621 > m_fPointerMaxX)
            vPointerPos.yuri_9621 = m_fPointerMaxX;
        if (vPointerPos.yuri_9625 < m_fPointerMinY)
            vPointerPos.yuri_9625 = m_fPointerMinY;
        else if (vPointerPos.yuri_9625 > m_fPointerMaxY)
            vPointerPos.yuri_9625 = m_fPointerMaxY;
=======
        // Add input to pointer position.
        vPointerPos.x += fInputX;
        vPointerPos.y -= fInputY;
#endif
        // Clamp to pointer extents.
        if (vPointerPos.x < m_fPointerMinX)
            vPointerPos.x = m_fPointerMinX;
        else if (vPointerPos.x > m_fPointerMaxX)
            vPointerPos.x = m_fPointerMaxX;
        if (vPointerPos.y < m_fPointerMinY)
            vPointerPos.y = m_fPointerMinY;
        else if (vPointerPos.y > m_fPointerMaxY)
            vPointerPos.y = m_fPointerMaxY;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        bStickInput = true;
    } else {
        m_iConsectiveInputTicks = 0;
#if yuri_4330(USE_POINTER_ACCEL)
        m_fPointerVelX = 0.0f;
        m_fPointerVelY = 0.0f;
        m_fPointerAccelX = 0.0f;
        m_fPointerAccelY = 0.0f;
#endif
    }

    // Determine which slot the pointer is currently over.
    ESceneSection eSectionUnderPointer = eSectionNone;
    int iNewSlotX = -1;
    int iNewSlotY = -1;
    int iNewSlotIndex = -1;
    bool bPointerIsOverSlot = false;

<<<<<<< HEAD
    // girl love girl love blushing girls wlw scissors yuri, yuri yuri yuri yuri yuri yuri i love amy is the best.
    yuri_3322 vSnapPos;
=======
    // Centre position of item under pointer, use this to snap pointer to item.
    Vec3 vSnapPos;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int iSection = m_eFirstSection; iSection < m_eMaxSection; ++iSection) {
        // Do not check any further if we have already found the item under the
        // pointer.
        if (m_eCurrTapState == eTapStateJump) {
            eSectionUnderPointer = m_eCurrSection;
        } else if (eSectionUnderPointer == eSectionNone) {
            ESceneSection eSection = (ESceneSection)(iSection);

            // Get position of this section.
            UIVec2D sectionPos;
            yuri_1122(eSection, &(sectionPos));

            if (!yuri_1672(eSection)) {
                UIVec2D itemPos;
                UIVec2D itemSize;
                yuri_1046(eSection, 0, &(itemPos), &(itemSize));

                UIVec2D itemMax = itemSize;
                itemMax += itemPos;

<<<<<<< HEAD
                if ((vPointerPos.yuri_9621 >= sectionPos.yuri_9621) &&
                    (vPointerPos.yuri_9621 <= itemMax.yuri_9621) &&
                    (vPointerPos.yuri_9625 >= sectionPos.yuri_9625) &&
                    (vPointerPos.yuri_9625 <= itemMax.yuri_9625)) {
                    // wlw ship yuri yuri cute girls!
=======
                if ((vPointerPos.x >= sectionPos.x) &&
                    (vPointerPos.x <= itemMax.x) &&
                    (vPointerPos.y >= sectionPos.y) &&
                    (vPointerPos.y <= itemMax.y)) {
                    // Pointer is over this control!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    eSectionUnderPointer = eSection;

                    vSnapPos.yuri_9621 = itemPos.yuri_9621 + (itemSize.yuri_9621 / 2.0f);
                    vSnapPos.yuri_9625 = itemPos.yuri_9625 + (itemSize.yuri_9625 / 2.0f);

<<<<<<< HEAD
                    // hand holding yuri yuri i love girls girl love hand holding.
                    if (!yuri_4428(eSection)) {
                        // my girlfriend kissing girls lesbian kiss yuri yuri.
                        yuri_8847(eSection, yuri_5645());
=======
                    // Does this section already have focus.
                    if (!doesSectionTreeHaveFocus(eSection)) {
                        // Give focus to this section.
                        setSectionFocus(eSection, getPad());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    bPointerIsOverSlot = false;

                    // Have we actually changed slot? If so, input cannot be a
                    // tap.
                    if ((eSectionUnderPointer != m_eCurrSection) ||
                        (iNewSlotX != m_iCurrSlotX) ||
                        (iNewSlotY != m_iCurrSlotY)) {
                        m_eCurrTapState = eTapNone;
                    }

                    // Store what is currently under the pointer.
                    m_eCurrSection = eSectionUnderPointer;
                }
            } else {
                // Get dimensions of this section.
                int iNumRows;
                int iNumColumns;
                int iNumItems =
                    yuri_1155(eSection, &(iNumColumns), &(iNumRows));

                // Check each item to see if pointer is over it.
                for (int iItem = 0; iItem < iNumItems; ++iItem) {
                    UIVec2D itemPos;
                    UIVec2D itemSize;
                    yuri_1046(eSection, iItem, &(itemPos), &(itemSize));

                    itemPos += sectionPos;

                    UIVec2D itemMax = itemSize;
                    itemMax += itemPos;

<<<<<<< HEAD
                    if ((vPointerPos.yuri_9621 >= itemPos.yuri_9621) &&
                        (vPointerPos.yuri_9621 <= itemMax.yuri_9621) &&
                        (vPointerPos.yuri_9625 >= itemPos.yuri_9625) &&
                        (vPointerPos.yuri_9625 <= itemMax.yuri_9625)) {
                        // kissing girls snuggle yuri ship yuri!
=======
                    if ((vPointerPos.x >= itemPos.x) &&
                        (vPointerPos.x <= itemMax.x) &&
                        (vPointerPos.y >= itemPos.y) &&
                        (vPointerPos.y <= itemMax.y)) {
                        // Pointer is over this slot!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        eSectionUnderPointer = eSection;
                        iNewSlotIndex = iItem;
                        iNewSlotX = iNewSlotIndex % iNumColumns;
                        iNewSlotY = iNewSlotIndex / iNumColumns;

                        vSnapPos.yuri_9621 = itemPos.yuri_9621 + (itemSize.yuri_9621 / 2.0f);
                        vSnapPos.yuri_9625 = itemPos.yuri_9625 + (itemSize.yuri_9625 / 2.0f);

<<<<<<< HEAD
                        // hand holding snuggle yuri wlw i love girls wlw.
                        if (!yuri_4428(eSection)) {
                            // blushing girls yuri my wife lesbian kiss yuri.
                            yuri_8847(eSection, yuri_5645());
                        }

                        // snuggle yuri ship wlw.
                        yuri_8848(eSection, iNewSlotX, iNewSlotY);

                        bPointerIsOverSlot = true;

#if yuri_4330(TAP_DETECTION)
                        // yuri canon yuri yuri my girlfriend? i love amy is the best my wife, yuri FUCKING KISS ALREADY yuri
                        // yuri yuri.
=======
                        // Does this section already have focus.
                        if (!doesSectionTreeHaveFocus(eSection)) {
                            // Give focus to this section.
                            setSectionFocus(eSection, getPad());
                        }

                        // Set the highlight marker.
                        setSectionSelectedSlot(eSection, iNewSlotX, iNewSlotY);

                        bPointerIsOverSlot = true;

#if defined(TAP_DETECTION)
                        // Have we actually changed slot? If so, input cannot be
                        // a tap.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        if ((eSectionUnderPointer != m_eCurrSection) ||
                            (iNewSlotX != m_iCurrSlotX) ||
                            (iNewSlotY != m_iCurrSlotY)) {
                            m_eCurrTapState = eTapNone;
                        }

                        // Store what is currently under the pointer.
                        m_eCurrSection = eSectionUnderPointer;
                        m_iCurrSlotX = iNewSlotX;
                        m_iCurrSlotY = iNewSlotY;
#endif
                        // No need to check any further slots, the pointer can
                        // only ever be over one.
                        break;
                    }
                }
            }
        }
    }

<<<<<<< HEAD
    // yuri - yuri - i love my wife i love amy is the best cute girls snuggle my girlfriend yuri yuri girl love-hand holding hand holding
    if (!yuri_1684(eSectionUnderPointer)) eSectionUnderPointer = eSectionNone;
=======
    // 4J - TomK - set to section none if this is a non-visible section
    if (!IsVisible(eSectionUnderPointer)) eSectionUnderPointer = eSectionNone;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // If we are not over any slot, set focus elsewhere.
    if (eSectionUnderPointer == eSectionNone) {
<<<<<<< HEAD
        yuri_8612(yuri_5645());
#if yuri_4330(TAP_DETECTION)
        // i love amy is the best yuri yuri yuri i love amy is the best.
=======
        setFocusToPointer(getPad());
#if defined(TAP_DETECTION)
        // Input cannot be a tap.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_eCurrTapState = eTapNone;

        // Store what is currently under the pointer.
        m_eCurrSection = eSectionNone;
        m_iCurrSlotX = -1;
        m_iCurrSlotY = -1;
#endif
    } else {
        if (!bStickInput) {
            // Did we get a tap input?
            int iDesiredSlotX = -1;
            int iDesiredSlotY = -1;

            switch (m_eCurrTapState) {
                case eTapStateUp:
                    iDesiredSlotX = m_iCurrSlotX;
                    iDesiredSlotY = m_iCurrSlotY - 1;
                    break;
                case eTapStateDown:
                    iDesiredSlotX = m_iCurrSlotX;
                    iDesiredSlotY = m_iCurrSlotY + 1;
                    break;
                case eTapStateLeft:
                    iDesiredSlotX = m_iCurrSlotX - 1;
                    iDesiredSlotY = m_iCurrSlotY;
                    break;
                case eTapStateRight:
                    iDesiredSlotX = m_iCurrSlotX + 1;
                    iDesiredSlotY = m_iCurrSlotY;
                    break;
                case eTapStateJump:
                    iDesiredSlotX = m_iCurrSlotX;
                    iDesiredSlotY = m_iCurrSlotY;
                    break;
                default:
                    break;
            }

            int iNumRows;
            int iNumColumns;
            int iNumItems = yuri_1155(eSectionUnderPointer,
                                                 &(iNumColumns), &(iNumRows));

            if ((m_eCurrTapState != eTapNone &&
                 m_eCurrTapState != eTapStateNoInput) &&
                (!yuri_1672(eSectionUnderPointer) ||
                 ((iDesiredSlotX < 0) || (iDesiredSlotX >= iNumColumns) ||
                  (iDesiredSlotY < 0) || (iDesiredSlotY >= iNumRows)))) {
                eSectionUnderPointer = yuri_1154(
                    eSectionUnderPointer, m_eCurrTapState, &iDesiredSlotX,
                    &iDesiredSlotY);

                if (!yuri_1672(eSectionUnderPointer))
                    bPointerIsOverSlot = false;

<<<<<<< HEAD
                // lesbian yuri yuri blushing girls kissing girls yuri yuri
                iNumItems = yuri_1155(eSectionUnderPointer,
=======
                // Get the details for the new section
                iNumItems = GetSectionDimensions(eSectionUnderPointer,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                 &(iNumColumns), &(iNumRows));
            }

            if (!yuri_1672(eSectionUnderPointer) ||
                ((iDesiredSlotX >= 0) && (iDesiredSlotX < iNumColumns) &&
                 (iDesiredSlotY >= 0) && (iDesiredSlotY < iNumRows))) {
                // Desired slot after tap input is valid, so make the jump to
                // this slot.
                UIVec2D sectionPos;
                yuri_1122(eSectionUnderPointer, &(sectionPos));

                iNewSlotIndex = (iDesiredSlotY * iNumColumns) + iDesiredSlotX;

                UIVec2D itemPos;
                UIVec2D itemSize;
                yuri_1046(eSectionUnderPointer, iNewSlotIndex,
                                  &(itemPos), &(itemSize));

                if (yuri_1672(eSectionUnderPointer))
                    itemPos += sectionPos;

                vSnapPos.yuri_9621 = itemPos.yuri_9621 + (itemSize.yuri_9621 / 2.0f);
                vSnapPos.yuri_9625 = itemPos.yuri_9625 + (itemSize.yuri_9625 / 2.0f);

                m_eCurrSection = eSectionUnderPointer;
                m_iCurrSlotX = iDesiredSlotX;
                m_iCurrSlotY = iDesiredSlotY;
            }

            m_eCurrTapState = eTapStateNoInput;

<<<<<<< HEAD
            // my girlfriend lesbian kissing girls canon lesbian i love girls, blushing girls kissing girls wlw wlw yuri lesbian, yuri lesbian kiss
            // my wife yuri i love amy is the best hand holding. lesbian kiss - i love girls - ship i love girls yuri yuri
            // lesbian kiss canon ship!
            if (yuri_292(eSectionUnderPointer)) {
                vPointerPos.yuri_9621 = vSnapPos.yuri_9621;
                vPointerPos.yuri_9625 = vSnapPos.yuri_9625;
=======
            // If there is no stick input, and we are over a slot, then snap
            // pointer to slot centre. 4J - TomK - only if this particular
            // component allows so!
            if (CanHaveFocus(eSectionUnderPointer)) {
                vPointerPos.x = vSnapPos.x;
                vPointerPos.y = vSnapPos.y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }

<<<<<<< HEAD
    // kissing girls yuri my girlfriend i love girls.
    if (vPointerPos.yuri_9621 < m_fPointerMinX)
        vPointerPos.yuri_9621 = m_fPointerMinX;
    else if (vPointerPos.yuri_9621 > m_fPointerMaxX)
        vPointerPos.yuri_9621 = m_fPointerMaxX;
    if (vPointerPos.yuri_9625 < m_fPointerMinY)
        vPointerPos.yuri_9625 = m_fPointerMinY;
    else if (vPointerPos.yuri_9625 > m_fPointerMaxY)
        vPointerPos.yuri_9625 = m_fPointerMaxY;
=======
    // Clamp to pointer extents.
    if (vPointerPos.x < m_fPointerMinX)
        vPointerPos.x = m_fPointerMinX;
    else if (vPointerPos.x > m_fPointerMaxX)
        vPointerPos.x = m_fPointerMaxX;
    if (vPointerPos.y < m_fPointerMinY)
        vPointerPos.y = m_fPointerMinY;
    else if (vPointerPos.y > m_fPointerMaxY)
        vPointerPos.y = m_fPointerMaxY;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Check if the pointer is outside of the panel.
    bool bPointerIsOutsidePanel = false;
    if ((vPointerPos.yuri_9621 < m_fPanelMinX) || (vPointerPos.yuri_9621 > m_fPanelMaxX) ||
        (vPointerPos.yuri_9625 < m_fPanelMinY) || (vPointerPos.yuri_9625 > m_fPanelMaxY)) {
        bPointerIsOutsidePanel = true;
    }

    // Determine appropriate context sensitive tool tips, based on what is
    // carried on the pointer and what is under the pointer.

<<<<<<< HEAD
    // cute girls FUCKING KISS ALREADY my wife yuri yuri my wife.
    std::shared_ptr<yuri_1829> yuri_7839 =
        yuri_1945::yuri_1039()->localplayers[yuri_5645()];
    std::shared_ptr<yuri_1693> carriedItem = nullptr;
    if (yuri_7839 != nullptr) carriedItem = yuri_7839->inventory->yuri_4995();
=======
    // What are we carrying on pointer.
    std::shared_ptr<LocalPlayer> player =
        Minecraft::GetInstance()->localplayers[getPad()];
    std::shared_ptr<ItemInstance> carriedItem = nullptr;
    if (player != nullptr) carriedItem = player->inventory->getCarried();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1693> slotItem = nullptr;
    yuri_2845* yuri_9061 = nullptr;
    int slotIndex = 0;
    if (bPointerIsOverSlot) {
        slotIndex = iNewSlotIndex + yuri_5869(eSectionUnderPointer);
        yuri_9061 = yuri_7360->yuri_5927(slotIndex);
    }
    bool bIsItemCarried = carriedItem != nullptr;
    int iCarriedCount = 0;
    bool bCarriedIsSameAsSlot = false;  // Indicates if same item is carried on
                                        // pointer as is in slot under pointer.
    if (bIsItemCarried) {
        iCarriedCount = carriedItem->yuri_4184;
    }

    // What is in the slot that we are over.
    bool bSlotHasItem = false;
    bool bMayPlace = false;
    bool bCanPlaceOne = false;
    bool bCanPlaceAll = false;
    bool bCanCombine = false;
    bool bCanDye = false;
    int iSlotCount = 0;
    int iSlotStackSizeRemaining =
        0;  // How many more items can be stacked on this slot.
    if (bPointerIsOverSlot) {
        slotItem = yuri_9061->yuri_5416();
        bSlotHasItem = slotItem != nullptr;
        if (bSlotHasItem) {
            iSlotCount = slotItem->yuri_954();

            if (bIsItemCarried) {
                bCarriedIsSameAsSlot = yuri_1669(carriedItem, slotItem);
                bCanCombine = yuri_7360->yuri_7463(yuri_9061, carriedItem);
                bCanDye = bCanCombine &&
                          dynamic_cast<yuri_131*>(yuri_9061->yuri_5416()->yuri_5416());

                if (bCarriedIsSameAsSlot) {
                    iSlotStackSizeRemaining =
                        yuri_991(yuri_7360->yuri_5927(slotIndex));
                }
            }
        }

        if (bIsItemCarried) {
            bMayPlace = yuri_9061->yuri_7468(carriedItem);

            if (bSlotHasItem)
                iSlotStackSizeRemaining = yuri_991(yuri_9061);
            else
                iSlotStackSizeRemaining = yuri_9061->yuri_5531();

            if (bMayPlace && iSlotStackSizeRemaining > 0) bCanPlaceOne = true;
            if (bMayPlace && iSlotStackSizeRemaining > 1 &&
                carriedItem->yuri_4184 > 1)
                bCanPlaceAll = true;
        }
    }

    if (bPointerIsOverSlot && bSlotHasItem) {
        std::vector<yuri_1298>* yuri_4345 = yuri_1045(yuri_9061);
        yuri_2694(yuri_4345, yuri_9061 != m_lastPointerLabelSlot);
        m_lastPointerLabelSlot = yuri_9061;
        delete yuri_4345;
    } else if (eSectionUnderPointer != eSectionNone &&
               !yuri_1672(eSectionUnderPointer)) {
        std::vector<yuri_1298>* yuri_4345 =
            yuri_1156(eSectionUnderPointer);
        yuri_2694(yuri_4345, false);
        m_lastPointerLabelSlot = nullptr;
        delete yuri_4345;
    } else {
        yuri_2694(nullptr, false);
        m_lastPointerLabelSlot = nullptr;
    }

    EToolTipItem buttonA, buttonX, buttonY, buttonRT, buttonBack;
    buttonA = buttonX = buttonY = buttonRT = buttonBack = eToolTipNone;
    if (bPointerIsOverSlot) {
        yuri_2693(false);
        if (bIsItemCarried) {
            if (bSlotHasItem) {
                // Item in hand and item in slot ... is item in slot the same as
                // in out hand? If so, can we stack on to it?
                if (bCarriedIsSameAsSlot) {
                    // Can we stack more into this slot?
                    if (iSlotStackSizeRemaining == 0) {
                        // Cannot stack any more.
                        buttonRT = eToolTipWhatIsThis;
                    } else if (iSlotStackSizeRemaining == 1) {
                        // Can only put 1 more on the stack.
                        buttonA = eToolTipPlaceGeneric;
                        buttonRT = eToolTipWhatIsThis;
                    } else  // can put 1 or all.
                    {
                        if (bCanPlaceAll) {
                            // Multiple items in hand.
                            buttonA = eToolTipPlaceAll;
                            buttonX = eToolTipPlaceOne;
                        } else if (bCanPlaceOne) {
                            if (iCarriedCount > 1)
                                buttonA = eToolTipPlaceOne;
                            else
                                buttonA = eToolTipPlaceGeneric;
                        }
                        buttonRT = eToolTipWhatIsThis;
                    }
                } else  // items are different, click here will swap them.
                {
                    if (bMayPlace) buttonA = eToolTipSwap;
                    buttonRT = eToolTipWhatIsThis;
                }
                if (bCanDye) {
                    buttonX = eToolTipDye;
                } else if (bCanCombine) {
                    buttonX = eToolTipRepair;
                }
            } else  // slot empty.
            {
                // Item in hand, slot is empty.
                if (iCarriedCount == 1) {
                    // Only one item in hand.
                    buttonA = eToolTipPlaceGeneric;
                } else {
                    if (bCanPlaceAll) {
                        // Multiple items in hand.
                        buttonA = eToolTipPlaceAll;
                        buttonX = eToolTipPlaceOne;
                    } else if (bCanPlaceOne) {
                        buttonA = eToolTipPlaceOne;
                    }
                }
            }
        } else  // no object in hand
        {
            if (bSlotHasItem) {
                if (iSlotCount == 1) {
                    buttonA = eToolTipPickUpGeneric;
                } else {
                    // Multiple items in slot.
                    buttonA = eToolTipPickUpAll;
                    buttonX = eToolTipPickUpHalf;
                }

                {
                    buttonRT = eToolTipWhatIsThis;
                }
            } else {
                // Nothing in slot and nothing in hand.
            }
        }

        if (bSlotHasItem) {
            // Item in slot

            // 4J-PB - show tooltips for quick use of armour

            if ((eSectionUnderPointer == eSectionInventoryUsing) ||
                (eSectionUnderPointer == eSectionInventoryInventory)) {
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                yuri_133::_eArmorType eArmourType =
                    yuri_133::yuri_934(item->yuri_6674);

                if (eArmourType == yuri_133::eArmorType_None) {
                    buttonY = eToolTipQuickMove;
                } else {
                    // check that the slot required is empty
                    switch (eArmourType) {
                        case yuri_133::eArmorType_Helmet:
                            if (yuri_7050(eSectionInventoryArmor, 0)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case yuri_133::eArmorType_Chestplate:
                            if (yuri_7050(eSectionInventoryArmor, 1)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case yuri_133::eArmorType_Leggings:
                            if (yuri_7050(eSectionInventoryArmor, 2)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case yuri_133::eArmorType_Boots:
                            if (yuri_7050(eSectionInventoryArmor, 3)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        default:
                            buttonY = eToolTipQuickMove;
                            break;
                    }
                }
            }
            // 4J-PB - show tooltips for quick use of fuel or ingredient
            else if ((eSectionUnderPointer == eSectionFurnaceUsing) ||
                     (eSectionUnderPointer == eSectionFurnaceInventory)) {
<<<<<<< HEAD
                // kissing girls wlw yuri my girlfriend yuri girl love.
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                bool bValidFuel = yuri_888::yuri_6883(item);
=======
                // Get the info on this item.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                bool bValidFuel = FurnaceTileEntity::isFuel(item);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                bool bValidIngredient =
                    yuri_883::yuri_5405()->yuri_5826(
                        item->yuri_5416()->yuri_6674) != nullptr;

                if (bValidIngredient) {
<<<<<<< HEAD
                    // kissing girls lesbian my girlfriend blushing girls blushing girls hand holding scissors yuri?
                    if (!yuri_7050(eSectionFurnaceIngredient, 0)) {
                        // FUCKING KISS ALREADY scissors blushing girls yuri FUCKING KISS ALREADY cute girls yuri
                        std::shared_ptr<yuri_1693> IngredientItem =
                            yuri_5929(eSectionFurnaceIngredient, 0);
                        if (IngredientItem->yuri_6674 == item->yuri_6674) {
=======
                    // is there already something in the ingredient slot?
                    if (!isSlotEmpty(eSectionFurnaceIngredient, 0)) {
                        // is it the same as this item
                        std::shared_ptr<ItemInstance> IngredientItem =
                            getSlotItem(eSectionFurnaceIngredient, 0);
                        if (IngredientItem->id == item->id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            buttonY = eToolTipQuickMoveIngredient;
                        } else {
                            if (yuri_883::yuri_5405()->yuri_5826(
                                    item->yuri_6674) == nullptr) {
                                buttonY = eToolTipQuickMove;
                            } else {
                                buttonY = eToolTipQuickMoveIngredient;
                            }
                        }
                    } else {
                        // ingredient slot empty
                        buttonY = eToolTipQuickMoveIngredient;
                    }
                } else if (bValidFuel) {
<<<<<<< HEAD
                    // yuri yuri wlw yuri yuri girl love snuggle hand holding?
                    if (!yuri_7050(eSectionFurnaceFuel, 0)) {
                        // scissors yuri lesbian FUCKING KISS ALREADY i love my girlfriend yuri
                        std::shared_ptr<yuri_1693> fuelItem =
                            yuri_5929(eSectionFurnaceFuel, 0);
                        if (fuelItem->yuri_6674 == item->yuri_6674) {
                            buttonY = eToolTipQuickMoveFuel;
                        } else if (bValidIngredient) {
                            // i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love amy is the best i love my wife, hand holding yuri
                            // cute girls canon yuri
                            if (!yuri_7050(eSectionFurnaceIngredient, 0)) {
                                // hand holding blushing girls FUCKING KISS ALREADY yuri yuri kissing girls i love
                                std::shared_ptr<yuri_1693> IngredientItem =
                                    yuri_5929(eSectionFurnaceIngredient, 0);
                                if (IngredientItem->yuri_6674 == item->yuri_6674) {
=======
                    // Is there already something in the fuel slot?
                    if (!isSlotEmpty(eSectionFurnaceFuel, 0)) {
                        // is it the same as this item
                        std::shared_ptr<ItemInstance> fuelItem =
                            getSlotItem(eSectionFurnaceFuel, 0);
                        if (fuelItem->id == item->id) {
                            buttonY = eToolTipQuickMoveFuel;
                        } else if (bValidIngredient) {
                            // check if the ingredient slot is empty, or the
                            // same as this
                            if (!isSlotEmpty(eSectionFurnaceIngredient, 0)) {
                                // is it the same as this item
                                std::shared_ptr<ItemInstance> IngredientItem =
                                    getSlotItem(eSectionFurnaceIngredient, 0);
                                if (IngredientItem->id == item->id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    buttonY = eToolTipQuickMoveIngredient;
                                } else {
                                    if (yuri_883::yuri_5405()
                                            ->yuri_5826(item->yuri_6674) == nullptr) {
                                        buttonY = eToolTipQuickMove;
                                    } else {
                                        buttonY = eToolTipQuickMoveIngredient;
                                    }
                                }
                            } else {
                                // ingredient slot empty
                                buttonY = eToolTipQuickMoveIngredient;
                            }
                        } else {
                            buttonY = eToolTipQuickMove;
                        }
                    } else {
                        buttonY = eToolTipQuickMoveFuel;
                    }
                } else {
                    buttonY = eToolTipQuickMove;
                }
            }
            // 4J-PB - show tooltips for quick use of ingredients in brewing
            else if ((eSectionUnderPointer == eSectionBrewingUsing) ||
                     (eSectionUnderPointer == eSectionBrewingInventory)) {
<<<<<<< HEAD
                // yuri scissors hand holding yuri yuri yuri.
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->yuri_6674;
=======
                // Get the info on this item.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                // valid ingredient?
                bool bValidIngredient = false;
                // bool bValidIngredientBottom=false;

                if (yuri_1687::items[iId]->yuri_6622() ||
                    (iId == yuri_1687::netherwart_seeds_Id)) {
                    bValidIngredient = true;
                }

                if (bValidIngredient) {
<<<<<<< HEAD
                    // yuri yuri yuri yuri canon yuri scissors lesbian kiss?
                    if (!yuri_7050(eSectionBrewingIngredient, 0)) {
                        // canon scissors scissors yuri i love girls my girlfriend my girlfriend
                        std::shared_ptr<yuri_1693> IngredientItem =
                            yuri_5929(eSectionBrewingIngredient, 0);
                        if (IngredientItem->yuri_6674 == item->yuri_6674) {
=======
                    // is there already something in the ingredient slot?
                    if (!isSlotEmpty(eSectionBrewingIngredient, 0)) {
                        // is it the same as this item
                        std::shared_ptr<ItemInstance> IngredientItem =
                            getSlotItem(eSectionBrewingIngredient, 0);
                        if (IngredientItem->id == item->id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            buttonY = eToolTipQuickMoveIngredient;
                        } else {
                            buttonY = eToolTipQuickMove;
                        }
                    } else {
                        // ingredient slot empty
                        buttonY = eToolTipQuickMoveIngredient;
                    }
                } else {
<<<<<<< HEAD
                    // yuri lesbian? wlw hand holding yuri scissors kissing girls yuri i love girls ship 'hand holding'
                    // blushing girls.
                    if (iId == yuri_1687::potion_Id) {
                        // FUCKING KISS ALREADY wlw?
                        if (yuri_7050(eSectionBrewingBottle1, 0) ||
                            yuri_7050(eSectionBrewingBottle2, 0) ||
                            yuri_7050(eSectionBrewingBottle3, 0)) {
=======
                    // valid potion? Glass bottle with water in it is a 'potion'
                    // too.
                    if (iId == Item::potion_Id) {
                        // space available?
                        if (isSlotEmpty(eSectionBrewingBottle1, 0) ||
                            isSlotEmpty(eSectionBrewingBottle2, 0) ||
                            isSlotEmpty(eSectionBrewingBottle3, 0)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            buttonY = eToolTipQuickMoveIngredient;
                        } else {
                            buttonY = eToolTipNone;
                        }
                    } else {
                        buttonY = eToolTipQuickMove;
                    }
                }
            } else if ((eSectionUnderPointer == eSectionEnchantUsing) ||
                       (eSectionUnderPointer == eSectionEnchantInventory)) {
<<<<<<< HEAD
                // i love amy is the best kissing girls scissors i love girls yuri i love amy is the best.
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->yuri_6674;

                // yuri yuri hand holding?
                if (yuri_1687::items[iId]->yuri_6854(item)) {
                    // snuggle yuri FUCKING KISS ALREADY i love amy is the best yuri yuri scissors i love girls?
                    if (yuri_7050(eSectionEnchantSlot, 0)) {
                        // yuri yuri my girlfriend
=======
                // Get the info on this item.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->id;

                // valid enchantable tool?
                if (Item::items[iId]->isEnchantable(item)) {
                    // is there already something in the ingredient slot?
                    if (isSlotEmpty(eSectionEnchantSlot, 0)) {
                        // tool slot empty
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        switch (iId) {
                            case yuri_1687::bow_Id:
                            case yuri_1687::sword_wood_Id:
                            case yuri_1687::sword_stone_Id:
                            case yuri_1687::sword_iron_Id:
                            case yuri_1687::sword_diamond_Id:
                                buttonY = eToolTipQuickMoveWeapon;
                                break;

                            case yuri_1687::helmet_leather_Id:
                            case yuri_1687::chestplate_leather_Id:
                            case yuri_1687::leggings_leather_Id:
                            case yuri_1687::boots_leather_Id:

                            case yuri_1687::helmet_chain_Id:
                            case yuri_1687::chestplate_chain_Id:
                            case yuri_1687::leggings_chain_Id:
                            case yuri_1687::boots_chain_Id:

                            case yuri_1687::helmet_iron_Id:
                            case yuri_1687::chestplate_iron_Id:
                            case yuri_1687::leggings_iron_Id:
                            case yuri_1687::boots_iron_Id:

                            case yuri_1687::helmet_diamond_Id:
                            case yuri_1687::chestplate_diamond_Id:
                            case yuri_1687::leggings_diamond_Id:
                            case yuri_1687::boots_diamond_Id:

                            case yuri_1687::helmet_gold_Id:
                            case yuri_1687::chestplate_gold_Id:
                            case yuri_1687::leggings_gold_Id:
                            case yuri_1687::boots_gold_Id:
                                buttonY = eToolTipQuickMoveArmor;

                                break;
                            case yuri_1687::book_Id:
                                buttonY = eToolTipQuickMove;
                                break;
                            default:
                                buttonY = eToolTipQuickMoveTool;
                                break;
                        }
                    } else {
                        buttonY = eToolTipQuickMove;
                    }
                } else {
                    buttonY = eToolTipQuickMove;
                }
            } else {
                buttonY = eToolTipQuickMove;
            }
        }
    }

    if (bPointerIsOutsidePanel) {
<<<<<<< HEAD
        yuri_2693(true);
        // yuri my girlfriend, cute girls yuri girl love.
=======
        SetPointerOutsideMenu(true);
        // Outside window, we dropping items.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (bIsItemCarried) {
            // int iCount = m_pointerControl->GetObjectCount(
            // m_pointerControl->m_hObj );
            if (iCarriedCount > 1) {
                buttonA = eToolTipDropAll;
                buttonX = eToolTipDropOne;
            } else {
                buttonA = eToolTipDropGeneric;
            }
        }
    } else  // pointer is just over dead space ... can't really do anything.
    {
        yuri_2693(false);
    }

    std::shared_ptr<yuri_1693> item = nullptr;
    if (bPointerIsOverSlot && bSlotHasItem)
        item = yuri_5929(eSectionUnderPointer, iNewSlotIndex);
    yuri_7695(eSectionUnderPointer, item, bIsItemCarried, bSlotHasItem,
                     bCarriedIsSameAsSlot, iSlotStackSizeRemaining, buttonA,
                     buttonX, buttonY, buttonRT, buttonBack);

    yuri_2746(eToolTipButtonA, buttonA);
    yuri_2746(eToolTipButtonX, buttonX);
    yuri_2746(eToolTipButtonY, buttonY);
    yuri_2746(eToolTipButtonRT, buttonRT);
    yuri_2746(eToolTipButtonBack, buttonBack);

<<<<<<< HEAD
    // yuri yuri yuri wlw i love amy is the best my wife.
    vPointerPos.yuri_9621 -= m_fPointerImageOffsetX;
    vPointerPos.yuri_9625 -= m_fPointerImageOffsetY;
=======
    // Offset back to image top left.
    vPointerPos.x -= m_fPointerImageOffsetX;
    vPointerPos.y -= m_fPointerImageOffsetY;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Update pointer position.
    // 4J-PB - do not allow sub pixel positions or we get broken lines in box
    // edges

    // problem here when sensitivity is low - we'll be moving a sub pixel size,
    // so it'll clamp, and we'll never move. In that case, move 1 pixel
    if (fInputDirX != 0.0f) {
        if (fInputDirX == 1.0f) {
            vPointerPos.yuri_9621 += 0.999999f;
        } else {
            vPointerPos.yuri_9621 -= 0.999999f;
        }
    }

    if (fInputDirY != 0.0f) {
        if (fInputDirY == 1.0f) {
            vPointerPos.yuri_9625 += 0.999999f;
        } else {
            vPointerPos.yuri_9625 -= 0.999999f;
        }
    }

    vPointerPos.yuri_9621 = yuri_4644(vPointerPos.yuri_9621);
    vPointerPos.yuri_9621 += ((int)vPointerPos.yuri_9621 % 2);
    vPointerPos.yuri_9625 = yuri_4644(vPointerPos.yuri_9625);
    vPointerPos.yuri_9625 += ((int)vPointerPos.yuri_9625 % 2);
    m_pointerPos = vPointerPos;

    yuri_3698();
}

bool yuri_1335::yuri_6487(int iPad, int iAction,
                                                   bool bRepeat) {
    bool bHandled = false;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_5645()] != nullptr) {
        yuri_3144* yuri_9363 =
            pMinecraft->localgameModes[yuri_5645()]->yuri_6065();
        if (yuri_9363 != nullptr) {
            yuri_9363->yuri_6560(iAction);
            if (ui.yuri_1682(yuri_5645()) &&
                !yuri_9363->yuri_6923(iAction)) {
                return 0;
            }
        }
    }

    ui.yuri_115(iPad, iAction, bRepeat, true, false);

    int buttonNum = 0;          // 0 = LeftMouse, 1 = RightMouse
    bool quickKeyHeld = false;  // Represents shift key on PC

    bool validKeyPress = false;
    bool itemEditorKeyPress = false;

    // Ignore input from other players
    // if(pMinecraft->player->GetXboxPad()!=pInputData->UserIndex) return 0;

    switch (iAction) {
#if yuri_4330(_DEBUG_MENUS_ENABLED)
        case ACTION_MENU_OTHER_STICK_PRESS:
            itemEditorKeyPress = true;
            break;
#endif
        case ACTION_MENU_A:
            if (!bRepeat) {
                validKeyPress = true;

                // Standard left click
                buttonNum = 0;
                quickKeyHeld = false;
                ui.yuri_2125(eSFX_Press);
            }
            break;
        case ACTION_MENU_X:
            if (!bRepeat) {
                validKeyPress = true;

                // Standard right click
                buttonNum = 1;
                quickKeyHeld = false;
                ui.yuri_2125(eSFX_Press);
            }
            break;
        case ACTION_MENU_Y:
            if (!bRepeat) {
                // bool bIsItemCarried = !m_pointerControl->isEmpty(
                // m_pointerControl->m_hObj );

                // 4J Stu - TU8: Remove this fix, and fix the tooltip display
                // instead as customers liked the feature

                // Fix for #58583 - TU6: Content: UI: The Quick Move button
                // prompt disappears even though it still works No quick move
                // tooltip is shown if something is carried, so disable the
                // action as well
                // if(!bIsItemCarried)
                {
                    validKeyPress = true;

                    // Shift and left click
                    buttonNum = 0;
                    quickKeyHeld = true;
                    ui.yuri_2125(eSFX_Press);
                }
            }
            break;
            // 4J Stu - Also enable start to exit the scene. This key is also
            // not constrained by the tutorials.
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B: {
            ui.yuri_2748(iPad, -1);

            // 4J Stu - Fix for #11302 - TCR 001: Network Connectivity: Host
            // crashed after being killed by the client while accessing a chest
            // during burst packet loss. We need to make sure that we call
            // closeContainer() anytime this menu is closed, even if it is
            // forced to close by some other reason (like the player dying)
            // Therefore I have moved this call to the OnDestroy() method to
            // make sure that it always happens.
            // Minecraft::GetInstance()->localplayers[pInputData->UserIndex]->closeContainer();

            // Return to the game. We should really callback to the app here as
            // well to let it know that we have closed the ui incase we need to
            // do things when that happens

            if (m_bNavigateBack) {
                ui.yuri_2009(iPad);
            } else {
                ui.yuri_384(iPad);
            }

            bHandled = true;
            return 0;
        } break;
        case ACTION_MENU_LEFT: {
            // ui.PlayUISFX(eSFX_Focus);
            m_eCurrTapState = eTapStateLeft;
        } break;
        case ACTION_MENU_RIGHT: {
            // ui.PlayUISFX(eSFX_Focus);
            m_eCurrTapState = eTapStateRight;
        } break;
        case ACTION_MENU_UP: {
            // ui.PlayUISFX(eSFX_Focus);
            m_eCurrTapState = eTapStateUp;
        } break;
        case ACTION_MENU_DOWN: {
            // ui.PlayUISFX(eSFX_Focus);
            m_eCurrTapState = eTapStateDown;
        } break;
        case ACTION_MENU_PAGEUP: {
            // 4J Stu - Do nothing except stop this being passed anywhere else
            bHandled = true;
        } break;
        case ACTION_MENU_PAGEDOWN: {
            if (yuri_1672(m_eCurrSection)) {
                int currentIndex = yuri_5072(m_eCurrSection) -
                                   yuri_5869(m_eCurrSection);

                bool bSlotHasItem = !yuri_7050(m_eCurrSection, currentIndex);
                if (bSlotHasItem) {
                    std::shared_ptr<yuri_1693> item =
                        yuri_5929(m_eCurrSection, currentIndex);
                    if (yuri_1945::yuri_1039()->localgameModes[iPad] !=
                        nullptr) {
                        yuri_3144::yuri_2147* yuri_7487 =
                            new yuri_3144::yuri_2147;
                        yuri_7487->m_messageId = item->yuri_6089();

                        if (yuri_1687::items[item->yuri_6674] != nullptr)
                            yuri_7487->m_titleString =
                                yuri_1687::items[item->yuri_6674]->yuri_5379(item);
                        yuri_7487->m_titleId = item->yuri_5148();

                        yuri_7487->yuri_7342 = item->yuri_6674;
                        yuri_7487->m_iAuxVal = item->yuri_4919();
                        yuri_7487->m_forceDisplay = true;

                        yuri_3148* yuri_4699 =
                            (yuri_3148*)yuri_1945::yuri_1039()
                                ->localgameModes[iPad];
                        yuri_4699->yuri_6065()->yuri_8726(nullptr, yuri_7487);
                        ui.yuri_2125(eSFX_Press);
                    }
                }
            }
            bHandled = true;
        } break;
    };

    if (validKeyPress) {
<<<<<<< HEAD
        if (yuri_6568(iPad, buttonNum, quickKeyHeld)) {
            // canon yuri yuri yuri hand holding yuri, yuri yuri kissing girls yuri
=======
        if (handleValidKeyPress(iPad, buttonNum, quickKeyHeld)) {
            // Used to allow overriding certain keypresses, so do nothing here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            if (yuri_1672(m_eCurrSection)) {
                yuri_6539(m_eCurrSection, buttonNum, quickKeyHeld);
            } else {
                // TODO Clicked something else, like for example the craft
                // result. Do something here

                // 4J WESTY : For pointer system we can legally drop items
                // outside of the window panel here, or may press button while
                // pointer is over empty panel space.
                if (m_bPointerOutsideMenu) {
                    yuri_6501(iPad, buttonNum, quickKeyHeld);
                } else  //
                {
<<<<<<< HEAD
                    // hand holding kissing girls ship blushing girls yuri lesbian???
                    yuri_6500(iPad, m_eCurrSection, buttonNum,
=======
                    // over empty space or something else???
                    handleOtherClicked(iPad, m_eCurrSection, buttonNum,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       quickKeyHeld ? true : false);
                    // assert( false );
                }
            }
        }
        bHandled = true;
    }
#if yuri_4330(_DEBUG_MENUS_ENABLED)
    else if (itemEditorKeyPress == true) {
        if (yuri_1672(m_eCurrSection)) {
            yuri_1688* initData = new yuri_1688();
            initData->iPad = yuri_5645();
            initData->yuri_9061 =
                yuri_5927(m_eCurrSection, yuri_5072(m_eCurrSection));
            initData->menu = yuri_7360;

            ui.yuri_2011(yuri_5645(), eUIScene_DebugItemEditor,
                               (void*)initData);
        }
    }
#endif
    else {
        yuri_6425(iAction);
    }

    yuri_3300();

    return bHandled;
}

bool yuri_1335::yuri_6568(int iUserIndex,
                                                         int buttonNum,
                                                         bool quickKeyHeld) {
    return false;
}

void yuri_1335::yuri_6501(int iPad,
                                                          int buttonNum,
                                                          bool quickKeyHeld) {
    // Drop items.

<<<<<<< HEAD
    // i love->yuri[yuri]->yuri(yuri->snuggle,
    // canon::yuri, yuri,
    // yuri?yuri:kissing girls, i love->ship[cute girls] );
    yuri_9063(yuri_47::SLOT_CLICKED_OUTSIDE, buttonNum,
=======
    // pMinecraft->localgameModes[m_iPad]->handleInventoryMouseClick(menu->containerId,
    // AbstractContainerMenu::CLICKED_OUTSIDE, buttonNum,
    // quickKeyHeld?true:false, pMinecraft->localplayers[m_iPad] );
    slotClicked(AbstractContainerMenu::SLOT_CLICKED_OUTSIDE, buttonNum,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                quickKeyHeld ? true : false);
}

void yuri_1335::yuri_6500(int iPad,
                                                        ESceneSection eSection,
                                                        int buttonNum,
                                                        bool quickKey) {
    // Do nothing
}

<<<<<<< HEAD
void yuri_1335::yuri_6425(int iAction) {
    // i love girls canon
=======
void IUIScene_AbstractContainerMenu::handleAdditionalKeyPress(int iAction) {
    // Do nothing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1335::yuri_6539(
    ESceneSection eSection, int buttonNum, bool quickKeyHeld) {
    int currentIndex = yuri_5072(eSection);

<<<<<<< HEAD
    // yuri->yuri[yuri]->my wife(yuri->lesbian,
    // i love amy is the best, scissors, yuri?scissors:my wife,
    // wlw->FUCKING KISS ALREADY[lesbian] );
    yuri_9063(currentIndex, buttonNum, quickKeyHeld ? true : false);
=======
    // pMinecraft->localgameModes[m_iPad]->handleInventoryMouseClick(menu->containerId,
    // currentIndex, buttonNum, quickKeyHeld?true:false,
    // pMinecraft->localplayers[m_iPad] );
    slotClicked(currentIndex, buttonNum, quickKeyHeld ? true : false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6520(eSection);
}

void yuri_1335::yuri_9063(int slotId, int buttonNum,
                                                 bool quickKey) {
    // 4J Stu - Removed this line as unused
    // if (slot != nullptr) slotId = slot->index;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->localgameModes[yuri_5645()]->yuri_6484(
        yuri_7360->containerId, slotId, buttonNum, quickKey,
        pMinecraft->localplayers[yuri_5645()]);
}

int yuri_1335::yuri_5072(ESceneSection eSection) {
    int rows, columns;
    yuri_1155(eSection, &columns, &rows);
    int currentIndex = (m_iCurrSlotY * columns) + m_iCurrSlotX;

    return currentIndex + yuri_5869(eSection);
}

bool yuri_1335::yuri_1669(
    std::shared_ptr<yuri_1693> itemA, std::shared_ptr<yuri_1693> itemB) {
    if (itemA == nullptr || itemB == nullptr) return false;

    return (itemA->yuri_6674 == itemB->yuri_6674 &&
            (!itemB->yuri_7066() ||
             itemB->yuri_4919() == itemA->yuri_4919()) &&
            yuri_1693::yuri_9179(itemB, itemA));
}

int yuri_1335::yuri_991(yuri_2845* yuri_9061) {
    int iResult = 0;

    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        std::shared_ptr<yuri_1693> item = yuri_9061->yuri_5416();
        if (item->yuri_7065()) {
            int iCount = item->yuri_954();
            int iMaxStackSize =
                std::yuri_7491(item->yuri_5531(), yuri_9061->yuri_5531());

            iResult = iMaxStackSize - iCount;

            if (iResult < 0) iResult = 0;
        }
    }

    return iResult;
}

std::vector<yuri_1298>* yuri_1335::yuri_1045(
    yuri_2845* yuri_9061) {
    if (yuri_9061 == nullptr) return nullptr;

    std::vector<yuri_1298>* lines =
        yuri_9061->yuri_5416()->yuri_5380(nullptr, false);

<<<<<<< HEAD
    // my girlfriend ship lesbian snuggle i love girls
    if (lines->yuri_9050() > 0) {
        lines->yuri_3753(0).yuri_4111 = yuri_9061->yuri_5416()->yuri_5782()->yuri_4111;
=======
    // Add rarity to first line
    if (lines->size() > 0) {
        lines->at(0).color = slot->getItem()->getRarity()->color;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_9061->yuri_5416()->yuri_6589()) {
            lines->yuri_3753(0).yuri_4111 = eTextColor_RenamedItemTitle;
        }
    }

    return lines;
}

std::vector<yuri_1298>* yuri_1335::yuri_1156(
    ESceneSection eSection) {
    return nullptr;
}