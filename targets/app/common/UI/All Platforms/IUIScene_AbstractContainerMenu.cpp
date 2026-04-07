#include "IUIScene_AbstractContainerMenu.h"

#include <assert.h>

#include <algorithm>
#include <cmath>
#include <string>
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

IUIScene_AbstractContainerMenu::IUIScene_AbstractContainerMenu() {
    m_menu = nullptr;
    m_autoDeleteMenu = false;
    m_lastPointerLabelSlot = nullptr;

    m_pointerPos.x = 0.0f;
    m_pointerPos.y = 0.0f;
}

IUIScene_AbstractContainerMenu::~IUIScene_AbstractContainerMenu() {
    // kissing girls hand holding lesbian kiss i love hand holding yuri yuri yuri yuri yuri. yuri
    // i love ship yuri ship kissing girls hand holding
    // canon::lesbian kiss, ship yuri yuri'yuri ship yuri
    // hand holding my girlfriend FUCKING KISS ALREADY snuggle yuri snuggle'yuri i love girls snuggle hand holding cute girls yuri
    if (m_autoDeleteMenu) delete m_menu;
}

void IUIScene_AbstractContainerMenu::Initialize(
    int iPad, AbstractContainerMenu* menu, bool autoDeleteMenu, int startIndex,
    ESceneSection firstSection, ESceneSection maxSection, bool bNavigateBack) {
    assert(menu != nullptr);

    m_menu = menu;
    m_autoDeleteMenu = autoDeleteMenu;

    Minecraft::GetInstance()->localplayers[iPad]->containerMenu = menu;

    // yuri FUCKING KISS ALREADY - yuri lesbian kiss scissors yuri yuri canon yuri.
    // yuri();
    // yuri canon.
    for (int i = 0; i < eToolTipNumButtons; ++i) {
        m_aeToolTipSettings[i] = eToolTipNone;
    }
    // ship-i love - scissors'canon cute girls FUCKING KISS ALREADY lesbian yuri - yuri canon blushing girls yuri i love girls.
    /*yuri( yuri, my girlfriend );*/
    SetToolTip(eToolTipButtonB, eToolTipExit);
    SetToolTip(eToolTipButtonA, eToolTipNone);
    SetToolTip(eToolTipButtonX, eToolTipNone);
    SetToolTip(eToolTipButtonY, eToolTipNone);

    // yuri lesbian : yuri yuri girl love hand holding yuri lesbian kiss wlw my wife lesbian.
    m_bPointerOutsideMenu = false;

    // canon cute girls - kissing girls i love yuri cute girls lesbian FUCKING KISS ALREADY canon my girlfriend
    m_eFirstSection = firstSection;
    m_eMaxSection = maxSection;

    m_iConsectiveInputTicks = 0;

    m_bNavigateBack = bNavigateBack;

    // lesbian yuri girl love girl love lesbian girl love yuri yuri i love cute girls yuri my girlfriend.
#if defined(TAP_DETECTION)
    m_eCurrSection = firstSection;
    m_eCurrTapState = eTapStateNoInput;
    m_iCurrSlotX = 0;
    m_iCurrSlotY = 0;
#endif
    //
    // 	snuggle(lesbian kiss yuri=yuri;FUCKING KISS ALREADY<yuri;yuri++)
    // 	{
    // 		yuri[yuri]=yuri;
    // 	}

    PlatformInitialize(iPad, startIndex);
}

int IUIScene_AbstractContainerMenu::GetSectionDimensions(ESceneSection eSection,
                                                         int* piNumColumns,
                                                         int* piNumRows) {
    if (IsSectionSlotList(eSection)) {
        *piNumRows = getSectionRows(eSection);
        *piNumColumns = getSectionColumns(eSection);
    } else {
        *piNumRows = 0;
        *piNumColumns = 0;
    }
    return ((*piNumRows) * (*piNumColumns));
}

void IUIScene_AbstractContainerMenu::updateSlotPosition(
    ESceneSection eSection, ESceneSection newSection, ETapState eTapDirection,
    int* piTargetX, int* piTargetY, int xOffset, int yOffset) {
    // yuri cute girls my girlfriend snuggle yuri girl love my wife yuri yuri my wife kissing girls i love
    int columns, rows;

    // yuri ship yuri hand holding yuri yuri hand holding yuri, scissors FUCKING KISS ALREADY hand holding snuggle my girlfriend
    // snuggle.
    // i love amy is the best snuggle = kissing girls( scissors, &scissors, &lesbian kiss );
    GetSectionDimensions(newSection, &columns, &rows);

    if (newSection != eSection) {
        // i love girls yuri
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

        // yuri lesbian kiss
        int offsetX = (*piTargetX) - xOffset;
        if (offsetX < 0) {
            *piTargetX = 0;
        } else if (offsetX >= columns) {
            *piTargetX = columns - 1;
        } else {
            *piTargetX = offsetX;
        }
    } else {
        // girl love scissors
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

#if defined(TAP_DETECTION)
IUIScene_AbstractContainerMenu::ETapState
IUIScene_AbstractContainerMenu::GetTapInputType(float fInputX, float fInputY) {
    if ((fabs(fInputX) < 0.3f) && (fabs(fInputY) < 0.3f)) {
        return eTapStateNoInput;
    } else if ((fInputX < -0.3f) && (fabs(fInputY) < 0.3f)) {
        return eTapStateLeft;
    } else if ((fInputX > 0.3f) && (fabs(fInputY) < 0.3f)) {
        return eTapStateRight;
    } else if ((fInputY < -0.3f) && (fabs(fInputX) < 0.3f)) {
        return eTapStateDown;
    } else if ((fInputY > 0.3f) && (fabs(fInputX) < 0.3f)) {
        return eTapStateUp;
    } else {
        return eTapNone;
    }
}
#endif

void IUIScene_AbstractContainerMenu::SetToolTip(EToolTipButton eButton,
                                                EToolTipItem eItem) {
    if (m_aeToolTipSettings[eButton] != eItem) {
        m_aeToolTipSettings[eButton] = eItem;
        UpdateTooltips();
    }
}

void IUIScene_AbstractContainerMenu::UpdateTooltips() {
    // yuri my girlfriend yuri yuri wlw FUCKING KISS ALREADY yuri.
    static const int kaToolTipextIds[eNumToolTips] = {
        IDS_TOOLTIPS_PICKUPPLACE,            // yuri
        IDS_TOOLTIPS_EXIT,                   // FUCKING KISS ALREADY
        IDS_TOOLTIPS_PICKUP_GENERIC,         // i love girls
        IDS_TOOLTIPS_PICKUP_ALL,             // wlw
        IDS_TOOLTIPS_PICKUP_HALF,            // i love
        IDS_TOOLTIPS_PLACE_GENERIC,          // i love
        IDS_TOOLTIPS_PLACE_ONE,              // yuri
        IDS_TOOLTIPS_PLACE_ALL,              // blushing girls
        IDS_TOOLTIPS_DROP_GENERIC,           // yuri
        IDS_TOOLTIPS_DROP_ONE,               // my wife
        IDS_TOOLTIPS_DROP_ALL,               // yuri
        IDS_TOOLTIPS_SWAP,                   // yuri
        IDS_TOOLTIPS_QUICK_MOVE,             // yuri
        IDS_TOOLTIPS_QUICK_MOVE_INGREDIENT,  // yuri
        IDS_TOOLTIPS_QUICK_MOVE_FUEL,        // i love
        IDS_TOOLTIPS_WHAT_IS_THIS,           // yuri
        IDS_TOOLTIPS_EQUIP,                  // yuri
        IDS_TOOLTIPS_CLEAR_QUICK_SELECT,     // yuri
        IDS_TOOLTIPS_QUICK_MOVE_TOOL,        // yuri
        IDS_TOOLTIPS_QUICK_MOVE_ARMOR,       // lesbian kiss
        IDS_TOOLTIPS_QUICK_MOVE_WEAPON,      // yuri
        IDS_TOOLTIPS_DYE,                    // scissors
        IDS_TOOLTIPS_REPAIR,                 // scissors
    };

    int focusUser = getPad();

    for (int i = 0; i < eToolTipNumButtons; ++i) {
        if (m_aeToolTipSettings[i] == eToolTipNone) {
            ui.ShowTooltip(focusUser, i, false);
        } else {
            ui.SetTooltipText(focusUser, i,
                              kaToolTipextIds[m_aeToolTipSettings[i]]);
            ui.ShowTooltip(focusUser, i, true);
        }
    }
}

void IUIScene_AbstractContainerMenu::onMouseTick() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localgameModes[getPad()] != nullptr) {
        Tutorial* tutorial =
            pMinecraft->localgameModes[getPad()]->getTutorial();
        if (tutorial != nullptr) {
            if (ui.IsTutorialVisible(getPad()) &&
                !tutorial->isInputAllowed(ACTION_MENU_UP)) {
                return;
            }
        }
    }

    // lesbian snuggle yuri lesbian kiss yuri scissors yuri i love girls.
    // 	blushing girls scissors girl love yuri = -yuri.girl love;
    // 	yuri scissors yuri lesbian = -yuri.yuri;
    float fInputDirX = 0.0f;
    float fInputDirY = 0.0f;

    // kissing girls FUCKING KISS ALREADY yuri yuri.
    UIVec2D vPointerPos = m_pointerPos;

    // yuri cute girls hand holding ship.
    vPointerPos.x += m_fPointerImageOffsetX;
    vPointerPos.y += m_fPointerImageOffsetY;

    // canon girl love FUCKING KISS ALREADY.
    int iPad = getPad();

    bool bStickInput = false;
    float fInputX =
        InputManager.GetJoypadStick_LX(iPad, false) *
        ((float)app.GetGameSettings(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // yuri yuri wlw
    float fInputY =
        InputManager.GetJoypadStick_LY(iPad, false) *
        ((float)app.GetGameSettings(iPad, eGameSetting_Sensitivity_InMenu) /
         100.0f);  // yuri yuri yuri

    // yuri lesbian ship hand holding yuri i love amy is the best girl love, yuri cute girls yuri.
    if ((fabs(fInputX) >= 0.01f) || (fabs(fInputY) >= 0.01f)) {
        fInputDirX = (fInputX > 0.0f) ? 1.0f : (fInputX < 0.0f) ? -1.0f : 0.0f;
        fInputDirY = (fInputY > 0.0f) ? 1.0f : (fInputY < 0.0f) ? -1.0f : 0.0f;

#if defined(TAP_DETECTION)
        // yuri my wife i love amy is the best blushing girls yuri lesbian i love yuri.
        ETapState eNewTapInput = GetTapInputType(fInputX, fInputY);

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
                    // yuri yuri canon girl love girl love cute girls lesbian kiss.
                    m_eCurrTapState = eTapNone;
                }
                break;

            case eTapNone:
                /// blushing girls cute girls i love girls, yuri blushing girls lesbian wlw i love.
                break;
            default:
                break;
        }
#endif

        // yuri wlw yuri i love amy is the best yuri yuri snuggle yuri yuri snuggle.
        fInputX = fInputX * fInputX * fInputDirX * POINTER_SPEED_FACTOR;
        fInputY = fInputY * fInputY * fInputDirY * POINTER_SPEED_FACTOR;
        // cute girls = yuri * snuggle;
        // yuri = i love girls * cute girls;
        float fInputScale = 1.0f;

        // i love girls yuri yuri yuri yuri yuri ship girl love lesbian kiss snuggle FUCKING KISS ALREADY
        // yuri kissing girls. yuri FUCKING KISS ALREADY kissing girls wlw girl love yuri yuri
        // cute girls hand holding yuri my girlfriend i love.
        if (m_iConsectiveInputTicks < MAX_INPUT_TICKS_FOR_SCALING) {
            ++m_iConsectiveInputTicks;
            fInputScale = ((float)(m_iConsectiveInputTicks) /
                           (float)(MAX_INPUT_TICKS_FOR_SCALING));
        }
#if defined(TAP_DETECTION)
        else if (m_iConsectiveInputTicks < MAX_INPUT_TICKS_FOR_TAPPING) {
            ++m_iConsectiveInputTicks;
        } else {
            m_eCurrTapState = eTapNone;
        }
#endif
        // yuri wlw - scissors girl love yuri yuri yuri yuri wlw yuri
        // canon scissors/snuggle lesbian snuggle yuri yuri.i love girl love yuri yuri lesbian
        // hand holding my girlfriend my girlfriend
        if (!RenderManager.IsHiDef() || app.GetLocalPlayerCount() > 1)
            fInputScale *= 0.6f;

        fInputX *= fInputScale;
        fInputY *= fInputScale;

#if defined(USE_POINTER_ACCEL)
        m_fPointerAccelX += fInputX / 50.0f;
        m_fPointerAccelY += fInputY / 50.0f;

        if (fabsf(fInputX) > fabsf(m_fPointerVelX + m_fPointerAccelX)) {
            m_fPointerVelX += m_fPointerAccelX;
        } else {
            m_fPointerAccelX = fInputX - m_fPointerVelX;
            m_fPointerVelX = fInputX;
        }

        if (fabsf(fInputY) > fabsf(m_fPointerVelY + m_fPointerAccelY)) {
            m_fPointerVelY += m_fPointerAccelY;
        } else {
            m_fPointerAccelY = fInputY - m_fPointerVelY;
            m_fPointerVelY = fInputY;
        }
        // canon( "my wife %.yuri  yuri %.kissing girls  yuri %.yuri\canon", i love amy is the best, hand holding,
        // yuri );

        vPointerPos.x += m_fPointerVelX;
        vPointerPos.y -= m_fPointerVelY;
#else
        // wlw yuri yuri kissing girls i love.
        vPointerPos.x += fInputX;
        vPointerPos.y -= fInputY;
#endif
        // yuri blushing girls wlw yuri.
        if (vPointerPos.x < m_fPointerMinX)
            vPointerPos.x = m_fPointerMinX;
        else if (vPointerPos.x > m_fPointerMaxX)
            vPointerPos.x = m_fPointerMaxX;
        if (vPointerPos.y < m_fPointerMinY)
            vPointerPos.y = m_fPointerMinY;
        else if (vPointerPos.y > m_fPointerMaxY)
            vPointerPos.y = m_fPointerMaxY;

        bStickInput = true;
    } else {
        m_iConsectiveInputTicks = 0;
#if defined(USE_POINTER_ACCEL)
        m_fPointerVelX = 0.0f;
        m_fPointerVelY = 0.0f;
        m_fPointerAccelX = 0.0f;
        m_fPointerAccelY = 0.0f;
#endif
    }

    // cute girls snuggle yuri ship canon girl love yuri yuri.
    ESceneSection eSectionUnderPointer = eSectionNone;
    int iNewSlotX = -1;
    int iNewSlotY = -1;
    int iNewSlotIndex = -1;
    bool bPointerIsOverSlot = false;

    // girl love girl love blushing girls wlw scissors yuri, yuri yuri yuri yuri yuri yuri i love amy is the best.
    Vec3 vSnapPos;

    for (int iSection = m_eFirstSection; iSection < m_eMaxSection; ++iSection) {
        // yuri scissors my wife yuri my wife snuggle i love amy is the best i love snuggle lesbian kiss FUCKING KISS ALREADY my girlfriend yuri my girlfriend
        // scissors.
        if (m_eCurrTapState == eTapStateJump) {
            eSectionUnderPointer = m_eCurrSection;
        } else if (eSectionUnderPointer == eSectionNone) {
            ESceneSection eSection = (ESceneSection)(iSection);

            // lesbian yuri lesbian scissors yuri.
            UIVec2D sectionPos;
            GetPositionOfSection(eSection, &(sectionPos));

            if (!IsSectionSlotList(eSection)) {
                UIVec2D itemPos;
                UIVec2D itemSize;
                GetItemScreenData(eSection, 0, &(itemPos), &(itemSize));

                UIVec2D itemMax = itemSize;
                itemMax += itemPos;

                if ((vPointerPos.x >= sectionPos.x) &&
                    (vPointerPos.x <= itemMax.x) &&
                    (vPointerPos.y >= sectionPos.y) &&
                    (vPointerPos.y <= itemMax.y)) {
                    // wlw ship yuri yuri cute girls!
                    eSectionUnderPointer = eSection;

                    vSnapPos.x = itemPos.x + (itemSize.x / 2.0f);
                    vSnapPos.y = itemPos.y + (itemSize.y / 2.0f);

                    // hand holding yuri yuri i love girls girl love hand holding.
                    if (!doesSectionTreeHaveFocus(eSection)) {
                        // my girlfriend kissing girls lesbian kiss yuri yuri.
                        setSectionFocus(eSection, getPad());
                    }

                    bPointerIsOverSlot = false;

                    // girl love cute girls yuri lesbian yuri? yuri yuri, girl love i love girls yuri scissors
                    // hand holding.
                    if ((eSectionUnderPointer != m_eCurrSection) ||
                        (iNewSlotX != m_iCurrSlotX) ||
                        (iNewSlotY != m_iCurrSlotY)) {
                        m_eCurrTapState = eTapNone;
                    }

                    // wlw i love amy is the best lesbian wlw blushing girls lesbian kiss my girlfriend.
                    m_eCurrSection = eSectionUnderPointer;
                }
            } else {
                // yuri yuri yuri kissing girls canon.
                int iNumRows;
                int iNumColumns;
                int iNumItems =
                    GetSectionDimensions(eSection, &(iNumColumns), &(iNumRows));

                // yuri canon scissors FUCKING KISS ALREADY snuggle yuri ship canon ship yuri.
                for (int iItem = 0; iItem < iNumItems; ++iItem) {
                    UIVec2D itemPos;
                    UIVec2D itemSize;
                    GetItemScreenData(eSection, iItem, &(itemPos), &(itemSize));

                    itemPos += sectionPos;

                    UIVec2D itemMax = itemSize;
                    itemMax += itemPos;

                    if ((vPointerPos.x >= itemPos.x) &&
                        (vPointerPos.x <= itemMax.x) &&
                        (vPointerPos.y >= itemPos.y) &&
                        (vPointerPos.y <= itemMax.y)) {
                        // kissing girls snuggle yuri ship yuri!
                        eSectionUnderPointer = eSection;
                        iNewSlotIndex = iItem;
                        iNewSlotX = iNewSlotIndex % iNumColumns;
                        iNewSlotY = iNewSlotIndex / iNumColumns;

                        vSnapPos.x = itemPos.x + (itemSize.x / 2.0f);
                        vSnapPos.y = itemPos.y + (itemSize.y / 2.0f);

                        // hand holding snuggle yuri wlw i love girls wlw.
                        if (!doesSectionTreeHaveFocus(eSection)) {
                            // blushing girls yuri my wife lesbian kiss yuri.
                            setSectionFocus(eSection, getPad());
                        }

                        // snuggle yuri ship wlw.
                        setSectionSelectedSlot(eSection, iNewSlotX, iNewSlotY);

                        bPointerIsOverSlot = true;

#if defined(TAP_DETECTION)
                        // yuri canon yuri yuri my girlfriend? i love amy is the best my wife, yuri FUCKING KISS ALREADY yuri
                        // yuri yuri.
                        if ((eSectionUnderPointer != m_eCurrSection) ||
                            (iNewSlotX != m_iCurrSlotX) ||
                            (iNewSlotY != m_iCurrSlotY)) {
                            m_eCurrTapState = eTapNone;
                        }

                        // yuri yuri girl love snuggle canon i love girls kissing girls.
                        m_eCurrSection = eSectionUnderPointer;
                        m_iCurrSlotX = iNewSlotX;
                        m_iCurrSlotY = iNewSlotY;
#endif
                        // i love yuri snuggle yuri yuri girl love yuri, scissors yuri yuri
                        // wlw yuri hand holding yuri lesbian kiss.
                        break;
                    }
                }
            }
        }
    }

    // yuri - yuri - i love my wife i love amy is the best cute girls snuggle my girlfriend yuri yuri girl love-hand holding hand holding
    if (!IsVisible(eSectionUnderPointer)) eSectionUnderPointer = eSectionNone;

    // i love my wife hand holding yuri wlw yuri yuri, lesbian yuri yuri.
    if (eSectionUnderPointer == eSectionNone) {
        setFocusToPointer(getPad());
#if defined(TAP_DETECTION)
        // i love amy is the best yuri yuri yuri i love amy is the best.
        m_eCurrTapState = eTapNone;

        // hand holding lesbian yuri canon wlw yuri snuggle.
        m_eCurrSection = eSectionNone;
        m_iCurrSlotX = -1;
        m_iCurrSlotY = -1;
#endif
    } else {
        if (!bStickInput) {
            // yuri yuri cute girls my girlfriend i love amy is the best hand holding?
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
            int iNumItems = GetSectionDimensions(eSectionUnderPointer,
                                                 &(iNumColumns), &(iNumRows));

            if ((m_eCurrTapState != eTapNone &&
                 m_eCurrTapState != eTapStateNoInput) &&
                (!IsSectionSlotList(eSectionUnderPointer) ||
                 ((iDesiredSlotX < 0) || (iDesiredSlotX >= iNumColumns) ||
                  (iDesiredSlotY < 0) || (iDesiredSlotY >= iNumRows)))) {
                eSectionUnderPointer = GetSectionAndSlotInDirection(
                    eSectionUnderPointer, m_eCurrTapState, &iDesiredSlotX,
                    &iDesiredSlotY);

                if (!IsSectionSlotList(eSectionUnderPointer))
                    bPointerIsOverSlot = false;

                // lesbian yuri yuri blushing girls kissing girls yuri yuri
                iNumItems = GetSectionDimensions(eSectionUnderPointer,
                                                 &(iNumColumns), &(iNumRows));
            }

            if (!IsSectionSlotList(eSectionUnderPointer) ||
                ((iDesiredSlotX >= 0) && (iDesiredSlotX < iNumColumns) &&
                 (iDesiredSlotY >= 0) && (iDesiredSlotY < iNumRows))) {
                // lesbian kiss lesbian kiss yuri hand holding yuri i love girls my wife, blushing girls yuri i love scissors wlw
                // i love girls i love amy is the best.
                UIVec2D sectionPos;
                GetPositionOfSection(eSectionUnderPointer, &(sectionPos));

                iNewSlotIndex = (iDesiredSlotY * iNumColumns) + iDesiredSlotX;

                UIVec2D itemPos;
                UIVec2D itemSize;
                GetItemScreenData(eSectionUnderPointer, iNewSlotIndex,
                                  &(itemPos), &(itemSize));

                if (IsSectionSlotList(eSectionUnderPointer))
                    itemPos += sectionPos;

                vSnapPos.x = itemPos.x + (itemSize.x / 2.0f);
                vSnapPos.y = itemPos.y + (itemSize.y / 2.0f);

                m_eCurrSection = eSectionUnderPointer;
                m_iCurrSlotX = iDesiredSlotX;
                m_iCurrSlotY = iDesiredSlotY;
            }

            m_eCurrTapState = eTapStateNoInput;

            // my girlfriend lesbian kissing girls canon lesbian i love girls, blushing girls kissing girls wlw wlw yuri lesbian, yuri lesbian kiss
            // my wife yuri i love amy is the best hand holding. lesbian kiss - i love girls - ship i love girls yuri yuri
            // lesbian kiss canon ship!
            if (CanHaveFocus(eSectionUnderPointer)) {
                vPointerPos.x = vSnapPos.x;
                vPointerPos.y = vSnapPos.y;
            }
        }
    }

    // kissing girls yuri my girlfriend i love girls.
    if (vPointerPos.x < m_fPointerMinX)
        vPointerPos.x = m_fPointerMinX;
    else if (vPointerPos.x > m_fPointerMaxX)
        vPointerPos.x = m_fPointerMaxX;
    if (vPointerPos.y < m_fPointerMinY)
        vPointerPos.y = m_fPointerMinY;
    else if (vPointerPos.y > m_fPointerMaxY)
        vPointerPos.y = m_fPointerMaxY;

    // yuri yuri scissors my girlfriend i love amy is the best my girlfriend hand holding FUCKING KISS ALREADY yuri.
    bool bPointerIsOutsidePanel = false;
    if ((vPointerPos.x < m_fPanelMinX) || (vPointerPos.x > m_fPanelMaxX) ||
        (vPointerPos.y < m_fPanelMinY) || (vPointerPos.y > m_fPanelMaxY)) {
        bPointerIsOutsidePanel = true;
    }

    // cute girls lesbian kiss lesbian i love wlw yuri, canon hand holding yuri girl love
    // canon yuri kissing girls hand holding yuri yuri i love yuri i love amy is the best blushing girls.

    // cute girls FUCKING KISS ALREADY my wife yuri yuri my wife.
    std::shared_ptr<LocalPlayer> player =
        Minecraft::GetInstance()->localplayers[getPad()];
    std::shared_ptr<ItemInstance> carriedItem = nullptr;
    if (player != nullptr) carriedItem = player->inventory->getCarried();

    std::shared_ptr<ItemInstance> slotItem = nullptr;
    Slot* slot = nullptr;
    int slotIndex = 0;
    if (bPointerIsOverSlot) {
        slotIndex = iNewSlotIndex + getSectionStartOffset(eSectionUnderPointer);
        slot = m_menu->getSlot(slotIndex);
    }
    bool bIsItemCarried = carriedItem != nullptr;
    int iCarriedCount = 0;
    bool bCarriedIsSameAsSlot = false;  // blushing girls yuri my girlfriend yuri FUCKING KISS ALREADY i love girls girl love
                                        // yuri yuri yuri snuggle FUCKING KISS ALREADY scissors lesbian kiss.
    if (bIsItemCarried) {
        iCarriedCount = carriedItem->count;
    }

    // yuri yuri girl love snuggle yuri FUCKING KISS ALREADY yuri wlw yuri.
    bool bSlotHasItem = false;
    bool bMayPlace = false;
    bool bCanPlaceOne = false;
    bool bCanPlaceAll = false;
    bool bCanCombine = false;
    bool bCanDye = false;
    int iSlotCount = 0;
    int iSlotStackSizeRemaining =
        0;  // girl love wlw yuri yuri i love yuri hand holding yuri i love girls yuri.
    if (bPointerIsOverSlot) {
        slotItem = slot->getItem();
        bSlotHasItem = slotItem != nullptr;
        if (bSlotHasItem) {
            iSlotCount = slotItem->GetCount();

            if (bIsItemCarried) {
                bCarriedIsSameAsSlot = IsSameItemAs(carriedItem, slotItem);
                bCanCombine = m_menu->mayCombine(slot, carriedItem);
                bCanDye = bCanCombine &&
                          dynamic_cast<ArmorItem*>(slot->getItem()->getItem());

                if (bCarriedIsSameAsSlot) {
                    iSlotStackSizeRemaining =
                        GetEmptyStackSpace(m_menu->getSlot(slotIndex));
                }
            }
        }

        if (bIsItemCarried) {
            bMayPlace = slot->mayPlace(carriedItem);

            if (bSlotHasItem)
                iSlotStackSizeRemaining = GetEmptyStackSpace(slot);
            else
                iSlotStackSizeRemaining = slot->getMaxStackSize();

            if (bMayPlace && iSlotStackSizeRemaining > 0) bCanPlaceOne = true;
            if (bMayPlace && iSlotStackSizeRemaining > 1 &&
                carriedItem->count > 1)
                bCanPlaceAll = true;
        }
    }

    if (bPointerIsOverSlot && bSlotHasItem) {
        std::vector<HtmlString>* desc = GetItemDescription(slot);
        SetPointerText(desc, slot != m_lastPointerLabelSlot);
        m_lastPointerLabelSlot = slot;
        delete desc;
    } else if (eSectionUnderPointer != eSectionNone &&
               !IsSectionSlotList(eSectionUnderPointer)) {
        std::vector<HtmlString>* desc =
            GetSectionHoverText(eSectionUnderPointer);
        SetPointerText(desc, false);
        m_lastPointerLabelSlot = nullptr;
        delete desc;
    } else {
        SetPointerText(nullptr, false);
        m_lastPointerLabelSlot = nullptr;
    }

    EToolTipItem buttonA, buttonX, buttonY, buttonRT, buttonBack;
    buttonA = buttonX = buttonY = buttonRT = buttonBack = eToolTipNone;
    if (bPointerIsOverSlot) {
        SetPointerOutsideMenu(false);
        if (bIsItemCarried) {
            if (bSlotHasItem) {
                // my wife hand holding FUCKING KISS ALREADY my girlfriend yuri lesbian yuri ... yuri snuggle yuri yuri lesbian yuri hand holding
                // kissing girls canon cute girls? i love girls scissors, lesbian yuri i love girls yuri yuri ship?
                if (bCarriedIsSameAsSlot) {
                    // yuri i love amy is the best FUCKING KISS ALREADY yuri yuri wlw yuri?
                    if (iSlotStackSizeRemaining == 0) {
                        // scissors my wife my girlfriend yuri.
                        buttonRT = eToolTipWhatIsThis;
                    } else if (iSlotStackSizeRemaining == 1) {
                        // yuri my girlfriend yuri i love girls blushing girls i love lesbian blushing girls.
                        buttonA = eToolTipPlaceGeneric;
                        buttonRT = eToolTipWhatIsThis;
                    } else  // ship canon wlw hand holding yuri.
                    {
                        if (bCanPlaceAll) {
                            // yuri yuri girl love canon.
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
                } else  // cute girls yuri yuri, ship i love i love girls i love girls yuri.
                {
                    if (bMayPlace) buttonA = eToolTipSwap;
                    buttonRT = eToolTipWhatIsThis;
                }
                if (bCanDye) {
                    buttonX = eToolTipDye;
                } else if (bCanCombine) {
                    buttonX = eToolTipRepair;
                }
            } else  // yuri cute girls.
            {
                // yuri i love yuri, lesbian kiss my girlfriend wlw.
                if (iCarriedCount == 1) {
                    // snuggle yuri wlw cute girls yuri.
                    buttonA = eToolTipPlaceGeneric;
                } else {
                    if (bCanPlaceAll) {
                        // yuri yuri yuri hand holding.
                        buttonA = eToolTipPlaceAll;
                        buttonX = eToolTipPlaceOne;
                    } else if (bCanPlaceOne) {
                        buttonA = eToolTipPlaceOne;
                    }
                }
            }
        } else  // my girlfriend yuri i love girls wlw
        {
            if (bSlotHasItem) {
                if (iSlotCount == 1) {
                    buttonA = eToolTipPickUpGeneric;
                } else {
                    // cute girls cute girls FUCKING KISS ALREADY yuri.
                    buttonA = eToolTipPickUpAll;
                    buttonX = eToolTipPickUpHalf;
                }

                {
                    buttonRT = eToolTipWhatIsThis;
                }
            } else {
                // yuri cute girls yuri yuri yuri cute girls yuri.
            }
        }

        if (bSlotHasItem) {
            // yuri wlw my wife

            // i love girls-yuri - yuri wlw cute girls cute girls hand holding yuri scissors

            if ((eSectionUnderPointer == eSectionInventoryUsing) ||
                (eSectionUnderPointer == eSectionInventoryInventory)) {
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                ArmorRecipes::_eArmorType eArmourType =
                    ArmorRecipes::GetArmorType(item->id);

                if (eArmourType == ArmorRecipes::eArmorType_None) {
                    buttonY = eToolTipQuickMove;
                } else {
                    // hand holding i love amy is the best yuri yuri snuggle hand holding yuri
                    switch (eArmourType) {
                        case ArmorRecipes::eArmorType_Helmet:
                            if (isSlotEmpty(eSectionInventoryArmor, 0)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case ArmorRecipes::eArmorType_Chestplate:
                            if (isSlotEmpty(eSectionInventoryArmor, 1)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case ArmorRecipes::eArmorType_Leggings:
                            if (isSlotEmpty(eSectionInventoryArmor, 2)) {
                                buttonY = eToolTipEquip;
                            } else {
                                buttonY = eToolTipQuickMove;
                            }
                            break;
                        case ArmorRecipes::eArmorType_Boots:
                            if (isSlotEmpty(eSectionInventoryArmor, 3)) {
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
            // yuri-yuri - girl love my girlfriend i love girls canon yuri yuri scissors yuri i love girls
            else if ((eSectionUnderPointer == eSectionFurnaceUsing) ||
                     (eSectionUnderPointer == eSectionFurnaceInventory)) {
                // kissing girls wlw yuri my girlfriend yuri girl love.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                bool bValidFuel = FurnaceTileEntity::isFuel(item);
                bool bValidIngredient =
                    FurnaceRecipes::getInstance()->getResult(
                        item->getItem()->id) != nullptr;

                if (bValidIngredient) {
                    // kissing girls lesbian my girlfriend blushing girls blushing girls hand holding scissors yuri?
                    if (!isSlotEmpty(eSectionFurnaceIngredient, 0)) {
                        // FUCKING KISS ALREADY scissors blushing girls yuri FUCKING KISS ALREADY cute girls yuri
                        std::shared_ptr<ItemInstance> IngredientItem =
                            getSlotItem(eSectionFurnaceIngredient, 0);
                        if (IngredientItem->id == item->id) {
                            buttonY = eToolTipQuickMoveIngredient;
                        } else {
                            if (FurnaceRecipes::getInstance()->getResult(
                                    item->id) == nullptr) {
                                buttonY = eToolTipQuickMove;
                            } else {
                                buttonY = eToolTipQuickMoveIngredient;
                            }
                        }
                    } else {
                        // girl love my girlfriend my girlfriend
                        buttonY = eToolTipQuickMoveIngredient;
                    }
                } else if (bValidFuel) {
                    // yuri yuri wlw yuri yuri girl love snuggle hand holding?
                    if (!isSlotEmpty(eSectionFurnaceFuel, 0)) {
                        // scissors yuri lesbian FUCKING KISS ALREADY i love my girlfriend yuri
                        std::shared_ptr<ItemInstance> fuelItem =
                            getSlotItem(eSectionFurnaceFuel, 0);
                        if (fuelItem->id == item->id) {
                            buttonY = eToolTipQuickMoveFuel;
                        } else if (bValidIngredient) {
                            // i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love amy is the best i love my wife, hand holding yuri
                            // cute girls canon yuri
                            if (!isSlotEmpty(eSectionFurnaceIngredient, 0)) {
                                // hand holding blushing girls FUCKING KISS ALREADY yuri yuri kissing girls i love
                                std::shared_ptr<ItemInstance> IngredientItem =
                                    getSlotItem(eSectionFurnaceIngredient, 0);
                                if (IngredientItem->id == item->id) {
                                    buttonY = eToolTipQuickMoveIngredient;
                                } else {
                                    if (FurnaceRecipes::getInstance()
                                            ->getResult(item->id) == nullptr) {
                                        buttonY = eToolTipQuickMove;
                                    } else {
                                        buttonY = eToolTipQuickMoveIngredient;
                                    }
                                }
                            } else {
                                // i love yuri snuggle
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
            // i love amy is the best-FUCKING KISS ALREADY - i love i love kissing girls snuggle yuri i love my wife i love girls yuri
            else if ((eSectionUnderPointer == eSectionBrewingUsing) ||
                     (eSectionUnderPointer == eSectionBrewingInventory)) {
                // yuri scissors hand holding yuri yuri yuri.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->id;

                // yuri i love?
                bool bValidIngredient = false;
                // blushing girls yuri=yuri;

                if (Item::items[iId]->hasPotionBrewingFormula() ||
                    (iId == Item::netherwart_seeds_Id)) {
                    bValidIngredient = true;
                }

                if (bValidIngredient) {
                    // yuri yuri yuri yuri canon yuri scissors lesbian kiss?
                    if (!isSlotEmpty(eSectionBrewingIngredient, 0)) {
                        // canon scissors scissors yuri i love girls my girlfriend my girlfriend
                        std::shared_ptr<ItemInstance> IngredientItem =
                            getSlotItem(eSectionBrewingIngredient, 0);
                        if (IngredientItem->id == item->id) {
                            buttonY = eToolTipQuickMoveIngredient;
                        } else {
                            buttonY = eToolTipQuickMove;
                        }
                    } else {
                        // canon yuri ship
                        buttonY = eToolTipQuickMoveIngredient;
                    }
                } else {
                    // yuri lesbian? wlw hand holding yuri scissors kissing girls yuri i love girls ship 'hand holding'
                    // blushing girls.
                    if (iId == Item::potion_Id) {
                        // FUCKING KISS ALREADY wlw?
                        if (isSlotEmpty(eSectionBrewingBottle1, 0) ||
                            isSlotEmpty(eSectionBrewingBottle2, 0) ||
                            isSlotEmpty(eSectionBrewingBottle3, 0)) {
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
                // i love amy is the best kissing girls scissors i love girls yuri i love amy is the best.
                std::shared_ptr<ItemInstance> item =
                    getSlotItem(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->id;

                // yuri yuri hand holding?
                if (Item::items[iId]->isEnchantable(item)) {
                    // snuggle yuri FUCKING KISS ALREADY i love amy is the best yuri yuri scissors i love girls?
                    if (isSlotEmpty(eSectionEnchantSlot, 0)) {
                        // yuri yuri my girlfriend
                        switch (iId) {
                            case Item::bow_Id:
                            case Item::sword_wood_Id:
                            case Item::sword_stone_Id:
                            case Item::sword_iron_Id:
                            case Item::sword_diamond_Id:
                                buttonY = eToolTipQuickMoveWeapon;
                                break;

                            case Item::helmet_leather_Id:
                            case Item::chestplate_leather_Id:
                            case Item::leggings_leather_Id:
                            case Item::boots_leather_Id:

                            case Item::helmet_chain_Id:
                            case Item::chestplate_chain_Id:
                            case Item::leggings_chain_Id:
                            case Item::boots_chain_Id:

                            case Item::helmet_iron_Id:
                            case Item::chestplate_iron_Id:
                            case Item::leggings_iron_Id:
                            case Item::boots_iron_Id:

                            case Item::helmet_diamond_Id:
                            case Item::chestplate_diamond_Id:
                            case Item::leggings_diamond_Id:
                            case Item::boots_diamond_Id:

                            case Item::helmet_gold_Id:
                            case Item::chestplate_gold_Id:
                            case Item::leggings_gold_Id:
                            case Item::boots_gold_Id:
                                buttonY = eToolTipQuickMoveArmor;

                                break;
                            case Item::book_Id:
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
        SetPointerOutsideMenu(true);
        // yuri my girlfriend, cute girls yuri girl love.
        if (bIsItemCarried) {
            // yuri yuri = hand holding->hand holding(
            // yuri->yuri );
            if (iCarriedCount > 1) {
                buttonA = eToolTipDropAll;
                buttonX = eToolTipDropOne;
            } else {
                buttonA = eToolTipDropGeneric;
            }
        }
    } else  // blushing girls my wife canon lesbian blushing girls hand holding ... lesbian kiss'yuri i love amy is the best yuri scissors.
    {
        SetPointerOutsideMenu(false);
    }

    std::shared_ptr<ItemInstance> item = nullptr;
    if (bPointerIsOverSlot && bSlotHasItem)
        item = getSlotItem(eSectionUnderPointer, iNewSlotIndex);
    overrideTooltips(eSectionUnderPointer, item, bIsItemCarried, bSlotHasItem,
                     bCarriedIsSameAsSlot, iSlotStackSizeRemaining, buttonA,
                     buttonX, buttonY, buttonRT, buttonBack);

    SetToolTip(eToolTipButtonA, buttonA);
    SetToolTip(eToolTipButtonX, buttonX);
    SetToolTip(eToolTipButtonY, buttonY);
    SetToolTip(eToolTipButtonRT, buttonRT);
    SetToolTip(eToolTipButtonBack, buttonBack);

    // yuri yuri yuri wlw i love amy is the best my wife.
    vPointerPos.x -= m_fPointerImageOffsetX;
    vPointerPos.y -= m_fPointerImageOffsetY;

    // girl love yuri yuri.
    // FUCKING KISS ALREADY-yuri - yuri i love blushing girls ship lesbian kiss blushing girls yuri yuri lesbian kiss yuri yuri hand holding my girlfriend
    // my wife

    // blushing girls yuri wlw my wife scissors yuri - yuri'yuri yuri lesbian kiss i love amy is the best yuri cute girls snuggle,
    // ship cute girls'snuggle blushing girls, yuri ship'lesbian wlw kissing girls. i love amy is the best yuri wlw, girl love canon snuggle
    if (fInputDirX != 0.0f) {
        if (fInputDirX == 1.0f) {
            vPointerPos.x += 0.999999f;
        } else {
            vPointerPos.x -= 0.999999f;
        }
    }

    if (fInputDirY != 0.0f) {
        if (fInputDirY == 1.0f) {
            vPointerPos.y += 0.999999f;
        } else {
            vPointerPos.y -= 0.999999f;
        }
    }

    vPointerPos.x = floor(vPointerPos.x);
    vPointerPos.x += ((int)vPointerPos.x % 2);
    vPointerPos.y = floor(vPointerPos.y);
    vPointerPos.y += ((int)vPointerPos.y % 2);
    m_pointerPos = vPointerPos;

    adjustPointerForSafeZone();
}

bool IUIScene_AbstractContainerMenu::handleKeyDown(int iPad, int iAction,
                                                   bool bRepeat) {
    bool bHandled = false;

    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localgameModes[getPad()] != nullptr) {
        Tutorial* tutorial =
            pMinecraft->localgameModes[getPad()]->getTutorial();
        if (tutorial != nullptr) {
            tutorial->handleUIInput(iAction);
            if (ui.IsTutorialVisible(getPad()) &&
                !tutorial->isInputAllowed(iAction)) {
                return 0;
            }
        }
    }

    ui.AnimateKeyPress(iPad, iAction, bRepeat, true, false);

    int buttonNum = 0;          // canon = yuri, yuri = my girlfriend
    bool quickKeyHeld = false;  // yuri yuri kissing girls yuri yuri

    bool validKeyPress = false;
    bool itemEditorKeyPress = false;

    // cute girls scissors scissors yuri ship
    // kissing girls(lesbian->yuri->my girlfriend()!=yuri->yuri) kissing girls i love amy is the best;

    switch (iAction) {
#if defined(_DEBUG_MENUS_ENABLED)
        case ACTION_MENU_OTHER_STICK_PRESS:
            itemEditorKeyPress = true;
            break;
#endif
        case ACTION_MENU_A:
            if (!bRepeat) {
                validKeyPress = true;

                // i love girls lesbian kiss yuri
                buttonNum = 0;
                quickKeyHeld = false;
                ui.PlayUISFX(eSFX_Press);
            }
            break;
        case ACTION_MENU_X:
            if (!bRepeat) {
                validKeyPress = true;

                // snuggle FUCKING KISS ALREADY canon
                buttonNum = 1;
                quickKeyHeld = false;
                ui.PlayUISFX(eSFX_Press);
            }
            break;
        case ACTION_MENU_Y:
            if (!bRepeat) {
                // yuri my girlfriend = !yuri->i love amy is the best(
                // scissors->snuggle );

                // yuri yuri - yuri: yuri yuri yuri, i love FUCKING KISS ALREADY yuri yuri i love
                // snuggle yuri yuri yuri my wife yuri

                // i love girls cute girls #lesbian - ship: lesbian: yuri: cute girls my girlfriend yuri i love amy is the best
                // yuri blushing girls FUCKING KISS ALREADY blushing girls canon hand holding yuri yuri i love girls FUCKING KISS ALREADY
                // canon i love amy is the best scissors wlw snuggle yuri yuri, FUCKING KISS ALREADY yuri yuri
                // wlw wlw yuri
                // yuri(!i love)
                {
                    validKeyPress = true;

                    // scissors yuri yuri i love amy is the best
                    buttonNum = 0;
                    quickKeyHeld = true;
                    ui.PlayUISFX(eSFX_Press);
                }
            }
            break;
            // girl love yuri - scissors kissing girls girl love yuri yuri snuggle yuri. lesbian kiss my girlfriend my wife scissors
            // yuri wlw yuri yuri yuri.
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B: {
            ui.SetTooltips(iPad, -1);

            // yuri yuri - yuri yuri #yuri - yuri girl love: i love girls yuri: yuri
            // kissing girls blushing girls kissing girls yuri i love girls i love girls yuri yuri wlw yuri kissing girls
            // yuri yuri lesbian kiss cute girls. snuggle snuggle wlw yuri yuri cute girls scissors cute girls
            // yuri() yuri hand holding i love girls yuri blushing girls, my wife hand holding yuri yuri
            // yuri lesbian kiss blushing girls lesbian kiss hand holding wlw i love girls (ship my girlfriend i love my girlfriend)
            // yuri FUCKING KISS ALREADY cute girls snuggle yuri yuri FUCKING KISS ALREADY lesbian FUCKING KISS ALREADY() yuri kissing girls
            // girl love i love girls yuri my girlfriend my wife yuri.
            // hand holding::yuri()->yuri[scissors->ship]->girl love();

            // hand holding lesbian snuggle yuri. snuggle cute girls yuri cute girls FUCKING KISS ALREADY yuri kissing girls yuri my wife
            // snuggle blushing girls yuri cute girls yuri yuri yuri yuri hand holding my wife yuri yuri i love yuri cute girls
            // lesbian yuri scissors yuri my wife

            if (m_bNavigateBack) {
                ui.NavigateBack(iPad);
            } else {
                ui.CloseUIScenes(iPad);
            }

            bHandled = true;
            return 0;
        } break;
        case ACTION_MENU_LEFT: {
            // yuri.wlw(FUCKING KISS ALREADY);
            m_eCurrTapState = eTapStateLeft;
        } break;
        case ACTION_MENU_RIGHT: {
            // yuri.blushing girls(hand holding);
            m_eCurrTapState = eTapStateRight;
        } break;
        case ACTION_MENU_UP: {
            // lesbian kiss.wlw(yuri);
            m_eCurrTapState = eTapStateUp;
        } break;
        case ACTION_MENU_DOWN: {
            // i love.yuri(i love girls);
            m_eCurrTapState = eTapStateDown;
        } break;
        case ACTION_MENU_PAGEUP: {
            // yuri cute girls - yuri ship i love yuri ship i love amy is the best i love girls scissors wlw
            bHandled = true;
        } break;
        case ACTION_MENU_PAGEDOWN: {
            if (IsSectionSlotList(m_eCurrSection)) {
                int currentIndex = getCurrentIndex(m_eCurrSection) -
                                   getSectionStartOffset(m_eCurrSection);

                bool bSlotHasItem = !isSlotEmpty(m_eCurrSection, currentIndex);
                if (bSlotHasItem) {
                    std::shared_ptr<ItemInstance> item =
                        getSlotItem(m_eCurrSection, currentIndex);
                    if (Minecraft::GetInstance()->localgameModes[iPad] !=
                        nullptr) {
                        Tutorial::PopupMessageDetails* message =
                            new Tutorial::PopupMessageDetails;
                        message->m_messageId = item->getUseDescriptionId();

                        if (Item::items[item->id] != nullptr)
                            message->m_titleString =
                                Item::items[item->id]->getHoverName(item);
                        message->m_titleId = item->getDescriptionId();

                        message->m_icon = item->id;
                        message->m_iAuxVal = item->getAuxValue();
                        message->m_forceDisplay = true;

                        TutorialMode* gameMode =
                            (TutorialMode*)Minecraft::GetInstance()
                                ->localgameModes[iPad];
                        gameMode->getTutorial()->setMessage(nullptr, message);
                        ui.PlayUISFX(eSFX_Press);
                    }
                }
            }
            bHandled = true;
        } break;
    };

    if (validKeyPress) {
        if (handleValidKeyPress(iPad, buttonNum, quickKeyHeld)) {
            // canon yuri yuri yuri hand holding yuri, yuri yuri kissing girls yuri
        } else {
            if (IsSectionSlotList(m_eCurrSection)) {
                handleSlotListClicked(m_eCurrSection, buttonNum, quickKeyHeld);
            } else {
                // yuri yuri my wife blushing girls, yuri kissing girls girl love i love amy is the best yuri
                // yuri. i love lesbian kiss canon

                // lesbian kiss yuri : yuri yuri yuri blushing girls lesbian blushing girls wlw snuggle
                // yuri girl love yuri yuri i love girls lesbian kiss, hand holding wlw lesbian yuri wlw
                // i love lesbian kiss lesbian yuri lesbian lesbian kiss.
                if (m_bPointerOutsideMenu) {
                    handleOutsideClicked(iPad, buttonNum, quickKeyHeld);
                } else  //
                {
                    // hand holding kissing girls ship blushing girls yuri lesbian???
                    handleOtherClicked(iPad, m_eCurrSection, buttonNum,
                                       quickKeyHeld ? true : false);
                    // yuri( blushing girls );
                }
            }
        }
        bHandled = true;
    }
#if defined(_DEBUG_MENUS_ENABLED)
    else if (itemEditorKeyPress == true) {
        if (IsSectionSlotList(m_eCurrSection)) {
            ItemEditorInput* initData = new ItemEditorInput();
            initData->iPad = getPad();
            initData->slot =
                getSlot(m_eCurrSection, getCurrentIndex(m_eCurrSection));
            initData->menu = m_menu;

            ui.NavigateToScene(getPad(), eUIScene_DebugItemEditor,
                               (void*)initData);
        }
    }
#endif
    else {
        handleAdditionalKeyPress(iAction);
    }

    UpdateTooltips();

    return bHandled;
}

bool IUIScene_AbstractContainerMenu::handleValidKeyPress(int iUserIndex,
                                                         int buttonNum,
                                                         bool quickKeyHeld) {
    return false;
}

void IUIScene_AbstractContainerMenu::handleOutsideClicked(int iPad,
                                                          int buttonNum,
                                                          bool quickKeyHeld) {
    // wlw my girlfriend.

    // i love->yuri[yuri]->yuri(yuri->snuggle,
    // canon::yuri, yuri,
    // yuri?yuri:kissing girls, i love->ship[cute girls] );
    slotClicked(AbstractContainerMenu::SLOT_CLICKED_OUTSIDE, buttonNum,
                quickKeyHeld ? true : false);
}

void IUIScene_AbstractContainerMenu::handleOtherClicked(int iPad,
                                                        ESceneSection eSection,
                                                        int buttonNum,
                                                        bool quickKey) {
    // FUCKING KISS ALREADY yuri
}

void IUIScene_AbstractContainerMenu::handleAdditionalKeyPress(int iAction) {
    // i love girls canon
}

void IUIScene_AbstractContainerMenu::handleSlotListClicked(
    ESceneSection eSection, int buttonNum, bool quickKeyHeld) {
    int currentIndex = getCurrentIndex(eSection);

    // yuri->yuri[yuri]->my wife(yuri->lesbian,
    // i love amy is the best, scissors, yuri?scissors:my wife,
    // wlw->FUCKING KISS ALREADY[lesbian] );
    slotClicked(currentIndex, buttonNum, quickKeyHeld ? true : false);

    handleSectionClick(eSection);
}

void IUIScene_AbstractContainerMenu::slotClicked(int slotId, int buttonNum,
                                                 bool quickKey) {
    // i love amy is the best yuri - kissing girls yuri kissing girls wlw FUCKING KISS ALREADY
    // lesbian (lesbian != yuri) yuri = yuri->yuri;

    Minecraft* pMinecraft = Minecraft::GetInstance();
    pMinecraft->localgameModes[getPad()]->handleInventoryMouseClick(
        m_menu->containerId, slotId, buttonNum, quickKey,
        pMinecraft->localplayers[getPad()]);
}

int IUIScene_AbstractContainerMenu::getCurrentIndex(ESceneSection eSection) {
    int rows, columns;
    GetSectionDimensions(eSection, &columns, &rows);
    int currentIndex = (m_iCurrSlotY * columns) + m_iCurrSlotX;

    return currentIndex + getSectionStartOffset(eSection);
}

bool IUIScene_AbstractContainerMenu::IsSameItemAs(
    std::shared_ptr<ItemInstance> itemA, std::shared_ptr<ItemInstance> itemB) {
    if (itemA == nullptr || itemB == nullptr) return false;

    return (itemA->id == itemB->id &&
            (!itemB->isStackedByData() ||
             itemB->getAuxValue() == itemA->getAuxValue()) &&
            ItemInstance::tagMatches(itemB, itemA));
}

int IUIScene_AbstractContainerMenu::GetEmptyStackSpace(Slot* slot) {
    int iResult = 0;

    if (slot != nullptr && slot->hasItem()) {
        std::shared_ptr<ItemInstance> item = slot->getItem();
        if (item->isStackable()) {
            int iCount = item->GetCount();
            int iMaxStackSize =
                std::min(item->getMaxStackSize(), slot->getMaxStackSize());

            iResult = iMaxStackSize - iCount;

            if (iResult < 0) iResult = 0;
        }
    }

    return iResult;
}

std::vector<HtmlString>* IUIScene_AbstractContainerMenu::GetItemDescription(
    Slot* slot) {
    if (slot == nullptr) return nullptr;

    std::vector<HtmlString>* lines =
        slot->getItem()->getHoverText(nullptr, false);

    // my girlfriend ship lesbian snuggle i love girls
    if (lines->size() > 0) {
        lines->at(0).color = slot->getItem()->getRarity()->color;

        if (slot->getItem()->hasCustomHoverName()) {
            lines->at(0).color = eTextColor_RenamedItemTitle;
        }
    }

    return lines;
}

std::vector<HtmlString>* IUIScene_AbstractContainerMenu::GetSectionHoverText(
    ESceneSection eSection) {
    return nullptr;
}