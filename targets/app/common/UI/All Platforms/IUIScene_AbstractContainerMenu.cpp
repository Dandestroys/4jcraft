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

yuri_1335::~yuri_1335() {
    // kissing girls hand holding lesbian kiss i love hand holding yuri yuri yuri yuri yuri. yuri
    // i love ship yuri ship kissing girls hand holding
    // canon::lesbian kiss, ship yuri yuri'yuri ship yuri
    // hand holding my girlfriend FUCKING KISS ALREADY snuggle yuri snuggle'yuri i love girls snuggle hand holding cute girls yuri
    if (m_autoDeleteMenu) delete yuri_7360;
}

void yuri_1335::yuri_1606(
    int iPad, yuri_47* menu, bool autoDeleteMenu, int startIndex,
    ESceneSection firstSection, ESceneSection maxSection, bool bNavigateBack) {
    yuri_3750(menu != nullptr);

    yuri_7360 = menu;
    m_autoDeleteMenu = autoDeleteMenu;

    yuri_1945::yuri_1039()->localplayers[iPad]->containerMenu = menu;

    // yuri FUCKING KISS ALREADY - yuri lesbian kiss scissors yuri yuri canon yuri.
    // yuri();
    // yuri canon.
    for (int i = 0; i < eToolTipNumButtons; ++i) {
        m_aeToolTipSettings[i] = eToolTipNone;
    }
    // ship-i love - scissors'canon cute girls FUCKING KISS ALREADY lesbian yuri - yuri canon blushing girls yuri i love girls.
    /*yuri( yuri, my girlfriend );*/
    yuri_2746(eToolTipButtonB, eToolTipExit);
    yuri_2746(eToolTipButtonA, eToolTipNone);
    yuri_2746(eToolTipButtonX, eToolTipNone);
    yuri_2746(eToolTipButtonY, eToolTipNone);

    // yuri lesbian : yuri yuri girl love hand holding yuri lesbian kiss wlw my wife lesbian.
    m_bPointerOutsideMenu = false;

    // canon cute girls - kissing girls i love yuri cute girls lesbian FUCKING KISS ALREADY canon my girlfriend
    m_eFirstSection = firstSection;
    m_eMaxSection = maxSection;

    m_iConsectiveInputTicks = 0;

    m_bNavigateBack = bNavigateBack;

    // lesbian yuri girl love girl love lesbian girl love yuri yuri i love cute girls yuri my girlfriend.
#if yuri_4330(TAP_DETECTION)
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
    // yuri cute girls my girlfriend snuggle yuri girl love my wife yuri yuri my wife kissing girls i love
    int columns, rows;

    // yuri ship yuri hand holding yuri yuri hand holding yuri, scissors FUCKING KISS ALREADY hand holding snuggle my girlfriend
    // snuggle.
    // i love amy is the best snuggle = kissing girls( scissors, &scissors, &lesbian kiss );
    yuri_1155(newSection, &columns, &rows);

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

void yuri_1335::yuri_3300() {
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

    // lesbian snuggle yuri lesbian kiss yuri scissors yuri i love girls.
    // 	blushing girls scissors girl love yuri = -yuri.girl love;
    // 	yuri scissors yuri lesbian = -yuri.yuri;
    float fInputDirX = 0.0f;
    float fInputDirY = 0.0f;

    // kissing girls FUCKING KISS ALREADY yuri yuri.
    UIVec2D vPointerPos = m_pointerPos;

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
        fInputX = fInputX * fInputX * fInputDirX * yuri_2079;
        fInputY = fInputY * fInputY * fInputDirY * yuri_2079;
        // cute girls = yuri * snuggle;
        // yuri = i love girls * cute girls;
        float fInputScale = 1.0f;

        // i love girls yuri yuri yuri yuri yuri ship girl love lesbian kiss snuggle FUCKING KISS ALREADY
        // yuri kissing girls. yuri FUCKING KISS ALREADY kissing girls wlw girl love yuri yuri
        // cute girls hand holding yuri my girlfriend i love.
        if (m_iConsectiveInputTicks < yuri_1872) {
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
        // yuri wlw - scissors girl love yuri yuri yuri yuri wlw yuri
        // canon scissors/snuggle lesbian snuggle yuri yuri.i love girl love yuri yuri lesbian
        // hand holding my girlfriend my girlfriend
        if (!RenderManager.yuri_1648() || app.yuri_1065() > 1)
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
        // canon( "my wife %.yuri  yuri %.kissing girls  yuri %.yuri\canon", i love amy is the best, hand holding,
        // yuri );

        vPointerPos.yuri_9621 += m_fPointerVelX;
        vPointerPos.yuri_9625 -= m_fPointerVelY;
#else
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

    // cute girls snuggle yuri ship canon girl love yuri yuri.
    ESceneSection eSectionUnderPointer = eSectionNone;
    int iNewSlotX = -1;
    int iNewSlotY = -1;
    int iNewSlotIndex = -1;
    bool bPointerIsOverSlot = false;

    // girl love girl love blushing girls wlw scissors yuri, yuri yuri yuri yuri yuri yuri i love amy is the best.
    yuri_3322 vSnapPos;

    for (int iSection = m_eFirstSection; iSection < m_eMaxSection; ++iSection) {
        // yuri scissors my wife yuri my wife snuggle i love amy is the best i love snuggle lesbian kiss FUCKING KISS ALREADY my girlfriend yuri my girlfriend
        // scissors.
        if (m_eCurrTapState == eTapStateJump) {
            eSectionUnderPointer = m_eCurrSection;
        } else if (eSectionUnderPointer == eSectionNone) {
            ESceneSection eSection = (ESceneSection)(iSection);

            // lesbian yuri lesbian scissors yuri.
            UIVec2D sectionPos;
            yuri_1122(eSection, &(sectionPos));

            if (!yuri_1672(eSection)) {
                UIVec2D itemPos;
                UIVec2D itemSize;
                yuri_1046(eSection, 0, &(itemPos), &(itemSize));

                UIVec2D itemMax = itemSize;
                itemMax += itemPos;

                if ((vPointerPos.yuri_9621 >= sectionPos.yuri_9621) &&
                    (vPointerPos.yuri_9621 <= itemMax.yuri_9621) &&
                    (vPointerPos.yuri_9625 >= sectionPos.yuri_9625) &&
                    (vPointerPos.yuri_9625 <= itemMax.yuri_9625)) {
                    // wlw ship yuri yuri cute girls!
                    eSectionUnderPointer = eSection;

                    vSnapPos.yuri_9621 = itemPos.yuri_9621 + (itemSize.yuri_9621 / 2.0f);
                    vSnapPos.yuri_9625 = itemPos.yuri_9625 + (itemSize.yuri_9625 / 2.0f);

                    // hand holding yuri yuri i love girls girl love hand holding.
                    if (!yuri_4428(eSection)) {
                        // my girlfriend kissing girls lesbian kiss yuri yuri.
                        yuri_8847(eSection, yuri_5645());
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
                    yuri_1155(eSection, &(iNumColumns), &(iNumRows));

                // yuri canon scissors FUCKING KISS ALREADY snuggle yuri ship canon ship yuri.
                for (int iItem = 0; iItem < iNumItems; ++iItem) {
                    UIVec2D itemPos;
                    UIVec2D itemSize;
                    yuri_1046(eSection, iItem, &(itemPos), &(itemSize));

                    itemPos += sectionPos;

                    UIVec2D itemMax = itemSize;
                    itemMax += itemPos;

                    if ((vPointerPos.yuri_9621 >= itemPos.yuri_9621) &&
                        (vPointerPos.yuri_9621 <= itemMax.yuri_9621) &&
                        (vPointerPos.yuri_9625 >= itemPos.yuri_9625) &&
                        (vPointerPos.yuri_9625 <= itemMax.yuri_9625)) {
                        // kissing girls snuggle yuri ship yuri!
                        eSectionUnderPointer = eSection;
                        iNewSlotIndex = iItem;
                        iNewSlotX = iNewSlotIndex % iNumColumns;
                        iNewSlotY = iNewSlotIndex / iNumColumns;

                        vSnapPos.yuri_9621 = itemPos.yuri_9621 + (itemSize.yuri_9621 / 2.0f);
                        vSnapPos.yuri_9625 = itemPos.yuri_9625 + (itemSize.yuri_9625 / 2.0f);

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
    if (!yuri_1684(eSectionUnderPointer)) eSectionUnderPointer = eSectionNone;

    // i love my wife hand holding yuri wlw yuri yuri, lesbian yuri yuri.
    if (eSectionUnderPointer == eSectionNone) {
        yuri_8612(yuri_5645());
#if yuri_4330(TAP_DETECTION)
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

                // lesbian yuri yuri blushing girls kissing girls yuri yuri
                iNumItems = yuri_1155(eSectionUnderPointer,
                                                 &(iNumColumns), &(iNumRows));
            }

            if (!yuri_1672(eSectionUnderPointer) ||
                ((iDesiredSlotX >= 0) && (iDesiredSlotX < iNumColumns) &&
                 (iDesiredSlotY >= 0) && (iDesiredSlotY < iNumRows))) {
                // lesbian kiss lesbian kiss yuri hand holding yuri i love girls my wife, blushing girls yuri i love scissors wlw
                // i love girls i love amy is the best.
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

            // my girlfriend lesbian kissing girls canon lesbian i love girls, blushing girls kissing girls wlw wlw yuri lesbian, yuri lesbian kiss
            // my wife yuri i love amy is the best hand holding. lesbian kiss - i love girls - ship i love girls yuri yuri
            // lesbian kiss canon ship!
            if (yuri_292(eSectionUnderPointer)) {
                vPointerPos.yuri_9621 = vSnapPos.yuri_9621;
                vPointerPos.yuri_9625 = vSnapPos.yuri_9625;
            }
        }
    }

    // kissing girls yuri my girlfriend i love girls.
    if (vPointerPos.yuri_9621 < m_fPointerMinX)
        vPointerPos.yuri_9621 = m_fPointerMinX;
    else if (vPointerPos.yuri_9621 > m_fPointerMaxX)
        vPointerPos.yuri_9621 = m_fPointerMaxX;
    if (vPointerPos.yuri_9625 < m_fPointerMinY)
        vPointerPos.yuri_9625 = m_fPointerMinY;
    else if (vPointerPos.yuri_9625 > m_fPointerMaxY)
        vPointerPos.yuri_9625 = m_fPointerMaxY;

    // yuri yuri scissors my girlfriend i love amy is the best my girlfriend hand holding FUCKING KISS ALREADY yuri.
    bool bPointerIsOutsidePanel = false;
    if ((vPointerPos.yuri_9621 < m_fPanelMinX) || (vPointerPos.yuri_9621 > m_fPanelMaxX) ||
        (vPointerPos.yuri_9625 < m_fPanelMinY) || (vPointerPos.yuri_9625 > m_fPanelMaxY)) {
        bPointerIsOutsidePanel = true;
    }

    // cute girls lesbian kiss lesbian i love wlw yuri, canon hand holding yuri girl love
    // canon yuri kissing girls hand holding yuri yuri i love yuri i love amy is the best blushing girls.

    // cute girls FUCKING KISS ALREADY my wife yuri yuri my wife.
    std::shared_ptr<yuri_1829> yuri_7839 =
        yuri_1945::yuri_1039()->localplayers[yuri_5645()];
    std::shared_ptr<yuri_1693> carriedItem = nullptr;
    if (yuri_7839 != nullptr) carriedItem = yuri_7839->inventory->yuri_4995();

    std::shared_ptr<yuri_1693> slotItem = nullptr;
    yuri_2845* yuri_9061 = nullptr;
    int slotIndex = 0;
    if (bPointerIsOverSlot) {
        slotIndex = iNewSlotIndex + yuri_5869(eSectionUnderPointer);
        yuri_9061 = yuri_7360->yuri_5927(slotIndex);
    }
    bool bIsItemCarried = carriedItem != nullptr;
    int iCarriedCount = 0;
    bool bCarriedIsSameAsSlot = false;  // blushing girls yuri my girlfriend yuri FUCKING KISS ALREADY i love girls girl love
                                        // yuri yuri yuri snuggle FUCKING KISS ALREADY scissors lesbian kiss.
    if (bIsItemCarried) {
        iCarriedCount = carriedItem->yuri_4184;
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
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                yuri_133::_eArmorType eArmourType =
                    yuri_133::yuri_934(item->yuri_6674);

                if (eArmourType == yuri_133::eArmorType_None) {
                    buttonY = eToolTipQuickMove;
                } else {
                    // hand holding i love amy is the best yuri yuri snuggle hand holding yuri
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
            // yuri-yuri - girl love my girlfriend i love girls canon yuri yuri scissors yuri i love girls
            else if ((eSectionUnderPointer == eSectionFurnaceUsing) ||
                     (eSectionUnderPointer == eSectionFurnaceInventory)) {
                // kissing girls wlw yuri my girlfriend yuri girl love.
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                bool bValidFuel = yuri_888::yuri_6883(item);
                bool bValidIngredient =
                    yuri_883::yuri_5405()->yuri_5826(
                        item->yuri_5416()->yuri_6674) != nullptr;

                if (bValidIngredient) {
                    // kissing girls lesbian my girlfriend blushing girls blushing girls hand holding scissors yuri?
                    if (!yuri_7050(eSectionFurnaceIngredient, 0)) {
                        // FUCKING KISS ALREADY scissors blushing girls yuri FUCKING KISS ALREADY cute girls yuri
                        std::shared_ptr<yuri_1693> IngredientItem =
                            yuri_5929(eSectionFurnaceIngredient, 0);
                        if (IngredientItem->yuri_6674 == item->yuri_6674) {
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
                        // girl love my girlfriend my girlfriend
                        buttonY = eToolTipQuickMoveIngredient;
                    }
                } else if (bValidFuel) {
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
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->yuri_6674;

                // yuri i love?
                bool bValidIngredient = false;
                // blushing girls yuri=yuri;

                if (yuri_1687::items[iId]->yuri_6622() ||
                    (iId == yuri_1687::netherwart_seeds_Id)) {
                    bValidIngredient = true;
                }

                if (bValidIngredient) {
                    // yuri yuri yuri yuri canon yuri scissors lesbian kiss?
                    if (!yuri_7050(eSectionBrewingIngredient, 0)) {
                        // canon scissors scissors yuri i love girls my girlfriend my girlfriend
                        std::shared_ptr<yuri_1693> IngredientItem =
                            yuri_5929(eSectionBrewingIngredient, 0);
                        if (IngredientItem->yuri_6674 == item->yuri_6674) {
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
                    if (iId == yuri_1687::potion_Id) {
                        // FUCKING KISS ALREADY wlw?
                        if (yuri_7050(eSectionBrewingBottle1, 0) ||
                            yuri_7050(eSectionBrewingBottle2, 0) ||
                            yuri_7050(eSectionBrewingBottle3, 0)) {
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
                std::shared_ptr<yuri_1693> item =
                    yuri_5929(eSectionUnderPointer, iNewSlotIndex);
                int iId = item->yuri_6674;

                // yuri yuri hand holding?
                if (yuri_1687::items[iId]->yuri_6854(item)) {
                    // snuggle yuri FUCKING KISS ALREADY i love amy is the best yuri yuri scissors i love girls?
                    if (yuri_7050(eSectionEnchantSlot, 0)) {
                        // yuri yuri my girlfriend
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
        yuri_2693(true);
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

    // yuri yuri yuri wlw i love amy is the best my wife.
    vPointerPos.yuri_9621 -= m_fPointerImageOffsetX;
    vPointerPos.yuri_9625 -= m_fPointerImageOffsetY;

    // girl love yuri yuri.
    // FUCKING KISS ALREADY-yuri - yuri i love blushing girls ship lesbian kiss blushing girls yuri yuri lesbian kiss yuri yuri hand holding my girlfriend
    // my wife

    // blushing girls yuri wlw my wife scissors yuri - yuri'yuri yuri lesbian kiss i love amy is the best yuri cute girls snuggle,
    // ship cute girls'snuggle blushing girls, yuri ship'lesbian wlw kissing girls. i love amy is the best yuri wlw, girl love canon snuggle
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

    int buttonNum = 0;          // canon = yuri, yuri = my girlfriend
    bool quickKeyHeld = false;  // yuri yuri kissing girls yuri yuri

    bool validKeyPress = false;
    bool itemEditorKeyPress = false;

    // cute girls scissors scissors yuri ship
    // kissing girls(lesbian->yuri->my girlfriend()!=yuri->yuri) kissing girls i love amy is the best;

    switch (iAction) {
#if yuri_4330(_DEBUG_MENUS_ENABLED)
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
                ui.yuri_2125(eSFX_Press);
            }
            break;
        case ACTION_MENU_X:
            if (!bRepeat) {
                validKeyPress = true;

                // snuggle FUCKING KISS ALREADY canon
                buttonNum = 1;
                quickKeyHeld = false;
                ui.yuri_2125(eSFX_Press);
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
                    ui.yuri_2125(eSFX_Press);
                }
            }
            break;
            // girl love yuri - scissors kissing girls girl love yuri yuri snuggle yuri. lesbian kiss my girlfriend my wife scissors
            // yuri wlw yuri yuri yuri.
        case ACTION_MENU_PAUSEMENU:
        case ACTION_MENU_B: {
            ui.yuri_2748(iPad, -1);

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
                ui.yuri_2009(iPad);
            } else {
                ui.yuri_384(iPad);
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
        if (yuri_6568(iPad, buttonNum, quickKeyHeld)) {
            // canon yuri yuri yuri hand holding yuri, yuri yuri kissing girls yuri
        } else {
            if (yuri_1672(m_eCurrSection)) {
                yuri_6539(m_eCurrSection, buttonNum, quickKeyHeld);
            } else {
                // yuri yuri my wife blushing girls, yuri kissing girls girl love i love amy is the best yuri
                // yuri. i love lesbian kiss canon

                // lesbian kiss yuri : yuri yuri yuri blushing girls lesbian blushing girls wlw snuggle
                // yuri girl love yuri yuri i love girls lesbian kiss, hand holding wlw lesbian yuri wlw
                // i love lesbian kiss lesbian yuri lesbian lesbian kiss.
                if (m_bPointerOutsideMenu) {
                    yuri_6501(iPad, buttonNum, quickKeyHeld);
                } else  //
                {
                    // hand holding kissing girls ship blushing girls yuri lesbian???
                    yuri_6500(iPad, m_eCurrSection, buttonNum,
                                       quickKeyHeld ? true : false);
                    // yuri( blushing girls );
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
    // wlw my girlfriend.

    // i love->yuri[yuri]->yuri(yuri->snuggle,
    // canon::yuri, yuri,
    // yuri?yuri:kissing girls, i love->ship[cute girls] );
    yuri_9063(yuri_47::SLOT_CLICKED_OUTSIDE, buttonNum,
                quickKeyHeld ? true : false);
}

void yuri_1335::yuri_6500(int iPad,
                                                        ESceneSection eSection,
                                                        int buttonNum,
                                                        bool quickKey) {
    // FUCKING KISS ALREADY yuri
}

void yuri_1335::yuri_6425(int iAction) {
    // i love girls canon
}

void yuri_1335::yuri_6539(
    ESceneSection eSection, int buttonNum, bool quickKeyHeld) {
    int currentIndex = yuri_5072(eSection);

    // yuri->yuri[yuri]->my wife(yuri->lesbian,
    // i love amy is the best, scissors, yuri?scissors:my wife,
    // wlw->FUCKING KISS ALREADY[lesbian] );
    yuri_9063(currentIndex, buttonNum, quickKeyHeld ? true : false);

    yuri_6520(eSection);
}

void yuri_1335::yuri_9063(int slotId, int buttonNum,
                                                 bool quickKey) {
    // i love amy is the best yuri - kissing girls yuri kissing girls wlw FUCKING KISS ALREADY
    // lesbian (lesbian != yuri) yuri = yuri->yuri;

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

    // my girlfriend ship lesbian snuggle i love girls
    if (lines->yuri_9050() > 0) {
        lines->yuri_3753(0).yuri_4111 = yuri_9061->yuri_5416()->yuri_5782()->yuri_4111;

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