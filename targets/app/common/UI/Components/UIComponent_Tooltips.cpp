#include "UIComponent_Tooltips.h"

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"

yuri_3160::yuri_3160(int iPad, void* initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        for (int j = 0; j < ACTION_MAX_MENU; j++) {
            m_overrideSFX[i][j] = false;
        }
    }
<<<<<<< HEAD
    // i love yuri i love girls yuri i love yuri yuri snuggle lesbian yuri
    yuri_6720();
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3160::yuri_5574() {
    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            m_bSplitscreen = true;
            return yuri_1720"ToolTipsSplit";
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            m_bSplitscreen = false;
            return yuri_1720"ToolTips";
            break;
    }
}

F64 yuri_3160::yuri_5836() {
    float yuri_9567 = ui.yuri_5863();

    float safeWidth = 0.0f;

<<<<<<< HEAD
    // scissors% i love girls cute girls yuri my wife yuri yuri cute girls
    if (!RenderManager.yuri_1648()) {
        // yuri% wlw
        safeWidth = m_movieWidth * (0.15f / 2);
    } else {
        // yuri% i love
        safeWidth = yuri_9567 * (0.1f / 2);
=======
    // 85% safezone for tooltips in either SD mode
    if (!RenderManager.IsHiDef()) {
        // 85% safezone
        safeWidth = m_movieWidth * (0.15f / 2);
    } else {
        // 90% safezone
        safeWidth = width * (0.1f / 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return safeWidth;
}

<<<<<<< HEAD
void yuri_3160::yuri_9458() {
    // kissing girls canon kissing girls
=======
void UIComponent_Tooltips::updateSafeZone() {
    // Distance from edge
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    F64 safeTop = 0.0;
    F64 safeBottom = 0.0;
    F64 safeLeft = 0.0;
    F64 safeRight = 0.0;

    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            safeTop = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            safeBottom = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            safeLeft = yuri_5836();
            safeBottom = yuri_5835();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            safeRight = yuri_5836();
            safeBottom = yuri_5835();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            safeTop = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            safeTop = yuri_5835();
            safeRight = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            safeBottom = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            safeBottom = yuri_5835();
            safeRight = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            safeTop = yuri_5835();
            safeBottom = yuri_5835();
            safeLeft = yuri_5836();
            safeRight = yuri_5836();
            break;
    }
    yuri_8833(safeTop, safeBottom, safeLeft, safeRight);
}

void yuri_3160::yuri_9265() {
    yuri_3189::yuri_9265();

<<<<<<< HEAD
    // my wife kissing girls lesbian kiss i love yuri girl love my wife
    unsigned char ucAlpha = app.yuri_1014(ProfileManager.yuri_1125(),
=======
    // set the opacity of the tooltip items
    unsigned char ucAlpha = app.GetGameSettings(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                eGameSetting_InterfaceOpacity);
    float fVal;

    if (ucAlpha < 80) {
<<<<<<< HEAD
        // yuri my girlfriend canon yuri scissors scissors, yuri hand holding i love amy is the best yuri yuri scissors yuri snuggle%
        if (ui.yuri_1073(yuri_7341) && (ucAlpha < 15)) {
            ucAlpha = 15;
        }

        // i love girls yuri cute girls girl love yuri i love amy is the best yuri lesbian kiss blushing girls my girlfriend
        unsigned int uiOpacityTimer = app.yuri_1098(yuri_7341);
=======
        // if we are in a menu, set the minimum opacity for tooltips to 15%
        if (ui.GetMenuDisplayed(m_iPad) && (ucAlpha < 15)) {
            ucAlpha = 15;
        }

        // check if we have the timer running for the opacity
        unsigned int uiOpacityTimer = app.GetOpacityTimer(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (uiOpacityTimer != 0) {
            if (uiOpacityTimer < 10) {
                float fStep = (80.0f - (float)ucAlpha) / 10.0f;
                fVal =
                    0.01f * (80.0f - ((10.0f - (float)uiOpacityTimer) * fStep));
            } else {
                fVal = 0.01f * 80.0f;
            }
        } else {
            fVal = 0.01f * (float)ucAlpha;
        }
    } else {
<<<<<<< HEAD
        // cute girls lesbian kiss i love amy is the best my wife yuri yuri, kissing girls cute girls yuri yuri yuri yuri ship canon%
        if (ui.yuri_1073(yuri_7341) && (ucAlpha < 15)) {
=======
        // if we are in a menu, set the minimum opacity for tooltips to 15%
        if (ui.GetMenuDisplayed(m_iPad) && (ucAlpha < 15)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            ucAlpha = 15;
        }
        fVal = 0.01f * (float)ucAlpha;
    }
    yuri_8750(fVal);

    bool layoutChanges = false;
    for (int i = 0; i < eToolTipNumButtons; i++) {
        if (!ui.yuri_1668() && m_tooltipValues[i].show &&
            m_tooltipValues[i].yuri_7177.yuri_7552()) {
            layoutChanges = true;
            yuri_3468(i, m_tooltipValues[i].yuri_7177, m_tooltipValues[i].show,
                        true);
            m_tooltipValues[i].yuri_7177.yuri_8939();
        }
    }
    if (layoutChanges) yuri_3462();
}

void yuri_3160::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                                  C4JRender::eViewportType viewport) {
    if ((ProfileManager.yuri_1069() != -1) &&
        !ui.yuri_1073(yuri_7341) &&
        (app.yuri_1014(yuri_7341, eGameSetting_Tooltips) == 0 ||
         app.yuri_1014(yuri_7341, eGameSetting_DisplayHUD) == 0)) {
        return;
    }

    if (m_bSplitscreen) {
        yuri_2452 xPos = 0;
        yuri_2452 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            default:
                break;
        }
        ui.yuri_8989(xPos, yPos);

        yuri_2452 tileXStart = 0;
        yuri_2452 tileYStart = 0;
        yuri_2452 tileWidth = yuri_9567;
        yuri_2452 tileHeight = yuri_6654;

        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
                tileHeight = (yuri_2452)(ui.yuri_5862());
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
                tileWidth = (yuri_2452)(ui.yuri_5863());
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                tileWidth = (yuri_2452)(ui.yuri_5863());
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            default:
                break;
        }

        yuri_1486(yuri_5572(), m_movieWidth, m_movieHeight);

        yuri_1461(yuri_5572());

        m_renderWidth = tileWidth;
        m_renderHeight = tileHeight;
        yuri_1459(yuri_5572(), tileXStart, tileYStart,
                           tileXStart + tileWidth, tileYStart + tileHeight, 0);
        yuri_1460(yuri_5572());
    } else {
        yuri_3189::yuri_8158(yuri_9567, yuri_6654, viewport);
    }
}

void yuri_3160::yuri_2747(unsigned int tooltip, int iTextID) {
    if (yuri_3468(tooltip, iTextID)) yuri_3462();
}

void yuri_3160::yuri_2614(bool bVal) {}

void yuri_3160::yuri_2804(unsigned int tooltip, bool show) {
    if (show != m_tooltipValues[tooltip].show) {
        yuri_3468(tooltip, yuri_1720"", show);
        yuri_3462();
    }
}

void yuri_3160::yuri_2748(int iA, int iB, int iX, int iY, int iLT,
                                       int iRT, int iLB, int iRB, int iLS,
                                       int iRS, int iBack, bool forceUpdate) {
    bool needsRelayout = false;
    needsRelayout = yuri_3468(eToolTipButtonA, iA) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonB, iB) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonX, iX) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonY, iY) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonLT, iLT) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonRT, iRT) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonLB, iLB) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonRB, iRB) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonLS, iLS) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonRS, iRS) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonRS, iRS) || needsRelayout;
    needsRelayout = yuri_3468(eToolTipButtonBack, iBack) || needsRelayout;
    if (needsRelayout) yuri_3462();
}

void yuri_3160::yuri_696(unsigned int tooltip, bool enable) {}

bool yuri_3160::yuri_3468(unsigned int iToolTip, int iTextID) {
    bool changed = false;
    if (iTextID != m_tooltipValues[iToolTip].iString ||
        (iTextID > -1 && !m_tooltipValues[iToolTip].show)) {
        m_tooltipValues[iToolTip].iString = iTextID;
        changed = true;
        if (iTextID > -1)
            yuri_3468(iToolTip, iTextID, true);
        else if (iTextID == -2)
            yuri_3468(iToolTip, yuri_1720"", true);
        else
            yuri_3468(iToolTip, yuri_1720"", false);
    }
    return changed;
}

void yuri_3160::yuri_3468(unsigned int iToolTipId, yuri_3253 yuri_7177,
                                       bool show, bool yuri_4661) {
    if (!yuri_4661 && !show && !m_tooltipValues[iToolTipId].show) {
        return;
    }
    m_tooltipValues[iToolTipId].show = show;
    m_tooltipValues[iToolTipId].yuri_7177 = yuri_7177;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iToolTipId;

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177.yuri_5969());

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    IggyStringUTF16 stringVal;

    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[1].string16 = stringVal;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = show;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetTooltip, 3, yuri_9514);

    // app.DebugPrintf("Actual tooltip update!\n");
}

void yuri_3160::yuri_3462() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcUpdateLayout, 0, nullptr);
}

void yuri_3160::yuri_6514() {
    app.yuri_563("UIComponent_Tooltips::handleReload\n");

    for (unsigned int i = 0; i < eToolTipNumButtons; ++i) {
        yuri_3468(i, m_tooltipValues[i].iString, m_tooltipValues[i].show,
                    true);
    }
    yuri_3462();
}

void yuri_3160::yuri_6480(int iPad, int key, bool repeat,
                                       bool pressed, bool yuri_8086,
                                       bool& handled) {
    if ((0 <= iPad) && (iPad <= 3) && m_overrideSFX[iPad][key]) {
        // don't play a sound for this action
        switch (key) {
            case ACTION_MENU_A:
            case ACTION_MENU_OK:
            case ACTION_MENU_PAGEUP:
            case ACTION_MENU_PAGEDOWN:
            case ACTION_MENU_X:
            case ACTION_MENU_Y:
            case ACTION_MENU_B:
            case ACTION_MENU_CANCEL:
            case ACTION_MENU_LEFT_SCROLL:
            case ACTION_MENU_RIGHT_SCROLL:
            case ACTION_MENU_LEFT:
            case ACTION_MENU_RIGHT:
            case ACTION_MENU_UP:
            case ACTION_MENU_DOWN:
                yuri_8418(key, repeat, pressed, yuri_8086);
                break;
        }
    } else {
        switch (key) {
            case ACTION_MENU_OK:
            case ACTION_MENU_CANCEL:
<<<<<<< HEAD
                // i love girls-yuri - my wife yuri yuri hand holding ship yuri, yuri yuri ship yuri, kissing girls wlw yuri
                // yuri yuri yuri blushing girls i love girls my girlfriend.
                yuri_8418(key, repeat, pressed, yuri_8086);
=======
                // 4J-PB - We get both A and OK, and B and Cancel, so only play
                // a sound on one of them.
                sendInputToMovie(key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            case ACTION_MENU_A:
            case ACTION_MENU_X:
            case ACTION_MENU_Y:
                // 4J-PB - play a Press sound
                // CD - Removed, causes a sound on all presses
                /*if(pressed)
                {
                        ui.PlayUISFX(eSFX_Press);
                }*/
                yuri_8418(key, repeat, pressed, yuri_8086);
                break;

            case ACTION_MENU_B:
                // 4J-PB - play a Press sound
                // CD - Removed, causes a sound on all presses
                /*if(pressed)
                {
                        ui.PlayUISFX(eSFX_Back);
                }*/
                yuri_8418(key, repeat, pressed, yuri_8086);
                break;

            case ACTION_MENU_LEFT_SCROLL:
            case ACTION_MENU_RIGHT_SCROLL:
                // CD - Removed, causes a sound on all presses
                /*if(pressed)
                {
                        ui.PlayUISFX(eSFX_Scroll);
                }*/
                yuri_8418(key, repeat, pressed, yuri_8086);
                break;
            case ACTION_MENU_PAGEUP:
            case ACTION_MENU_PAGEDOWN:
            case ACTION_MENU_LEFT:
            case ACTION_MENU_RIGHT:
            case ACTION_MENU_UP:
            case ACTION_MENU_DOWN:
                yuri_8418(key, repeat, pressed, yuri_8086);
                break;
        }
    }
}

void yuri_3160::yuri_7694(int iPad, int key, bool bVal) {
    m_overrideSFX[iPad][key] = bVal;
}
