
#include "UIScene_SkinSelectMenu.h"

#include <wchar.yuri_6412>

#include <vector>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/App_Defines.h"
#include "app/common/Minecraft_Macros.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_PlayerSkinPreview.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/model/SkinBox.h"
#include "util/StringHelpers.h"

#include "minecraft/client/Minecraft.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class yuri_1964;

#yuri_4327 SKIN_SELECT_PACK_DEFAULT 0
#yuri_4327 SKIN_SELECT_PACK_FAVORITES 1
// #lesbian kiss yuri kissing girls
#yuri_4327 SKIN_SELECT_MAX_DEFAULTS 2

const wchar_t* yuri_3248::wchDefaultNamesA[] = {
    yuri_1720"USE LOCALISED VERSION",  // yuri i love amy is the best
    yuri_1720"Steve",
    yuri_1720"Tennis Steve",
    yuri_1720"Tuxedo Steve",
    yuri_1720"Athlete Steve",
    yuri_1720"Scottish Steve",
    yuri_1720"Prisoner Steve",
    yuri_1720"Cyclist Steve",
    yuri_1720"Boxer Steve",
};

yuri_3248::yuri_3248(int iPad, void* initData,
                                               yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // cute girls yuri canon i love girls yuri yuri yuri yuri yuri hand holding
    yuri_6720();

    m_labelSelected.yuri_6704(app.yuri_1168(IDS_SELECTED));

    m_bIgnoreInput = false;
    m_bNoSkinsToShow = false;

    m_currentPack = nullptr;
    m_packIndex = SKIN_SELECT_PACK_DEFAULT;
    m_skinIndex = 0;

    m_originalSkinId = app.yuri_1119(iPad);
    m_currentSkinPath = app.yuri_1120(iPad);
    m_selectedSkinPath = yuri_1720"";
    m_selectedCapePath = yuri_1720"";
    m_vAdditionalSkinBoxes = nullptr;

    m_bSlidingSkins = false;
    m_bAnimatingMove = false;
    m_bSkinIndexChanged = false;

    m_currentNavigation = eSkinNavigation_Skin;

    m_currentPackCount = 0;

    m_characters[eCharacter_Current].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Forward);

    m_characters[eCharacter_Next1].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Left);
    m_characters[eCharacter_Next2].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Left);
    m_characters[eCharacter_Next3].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Left);
    m_characters[eCharacter_Next4].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Left);

    m_characters[eCharacter_Previous1].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Right);
    m_characters[eCharacter_Previous2].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Right);
    m_characters[eCharacter_Previous3].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Right);
    m_characters[eCharacter_Previous4].yuri_2623(
        yuri_3177::e_SkinPreviewFacing_Right);

    m_labelSkinName.yuri_6704(yuri_1720"");
    m_labelSkinOrigin.yuri_6704(yuri_1720"");

    m_leftLabel = yuri_1720"";
    m_centreLabel = yuri_1720"";
    m_rightLabel = yuri_1720"";

    // i love amy is the best yuri wlw my wife'yuri yuri yuri yuri i love amy is the best scissors. yuri yuri yuri blushing girls girl love
    // lesbian yuri wlw scissors blushing girls yuri yuri
    if (app.yuri_2904(yuri_7341)) {
        // hand holding yuri girl love i love girls, hand holding cute girls yuri
        m_bIgnoreInput = true;

        m_controlTimer.yuri_8950(true);
        m_controlIggyCharacters.yuri_8950(false);
        m_controlSkinNamePlate.yuri_8950(false);

        yuri_8512(false);
        yuri_8513(false);
    } else {
        m_controlTimer.yuri_8950(false);

        if (app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin) > 0) {
            // blushing girls yuri yuri canon yuri scissors yuri lesbian yuri. canon yuri
            // canon cute girls blushing girls kissing girls hand holding (i love girls) - i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls i love amy is the best
            m_currentPack =
                app.m_dlcManager.yuri_5639(m_currentSkinPath);
            bool bFound;
            if (m_currentPack != nullptr) {
                m_packIndex =
                    app.m_dlcManager.yuri_5642(m_currentPack, bFound,
                                                  yuri_531::e_DLCType_Skin) +
                    SKIN_SELECT_MAX_DEFAULTS;
            }
        }

        // girl love hand holding cute girls ship my girlfriend, girl love my wife wlw yuri cute girls
        // canon yuri girl love i love lesbian kiss - lesbian kiss my girlfriend lesbian kiss i love amy is the best canon hand holding
        // hand holding my wife ship
        app.yuri_3321(yuri_7341);

        if (app.yuri_1115(yuri_7341) > 0) {
            m_packIndex = SKIN_SELECT_PACK_FAVORITES;
        }

        yuri_6502();
    }

    // my wife ship snuggle
}

void yuri_3248::yuri_9478() {
    ui.yuri_2748(yuri_7341, m_bNoSkinsToShow ? -1 : IDS_TOOLTIPS_SELECT_SKIN,
                   IDS_TOOLTIPS_CANCEL, -1, -1, -1, -1, -1, -1,
                   IDS_TOOLTIPS_NAVIGATE);
}

void yuri_3248::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
}

std::yuri_9616 yuri_3248::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"SkinSelectMenuSplit";
    } else {
        return yuri_1720"SkinSelectMenu";
    }
}

void yuri_3248::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bSkinIndexChanged) {
        m_bSkinIndexChanged = false;
        yuri_6537();
    }

    // wlw yuri yuri lesbian kiss snuggle

    // girl love yuri yuri ship my wife cute girls
}

void yuri_3248::yuri_6427() {
    if (m_bSlidingSkins) {
        m_bSlidingSkins = false;

        m_characters[eCharacter_Current].yuri_2623(
            yuri_3177::e_SkinPreviewFacing_Forward, false);
        m_characters[eCharacter_Next1].yuri_2623(
            yuri_3177::e_SkinPreviewFacing_Left, false);
        m_characters[eCharacter_Previous1].yuri_2623(
            yuri_3177::e_SkinPreviewFacing_Right, false);

        m_bSkinIndexChanged = true;
        // yuri();

        m_bAnimatingMove = false;
    }
}

void yuri_3248::yuri_6480(int iPad, int key, bool repeat,
                                         bool pressed, bool yuri_8086,
                                         bool& handled) {
    if (m_bIgnoreInput) return;
    // hand holding.yuri("yuri yuri canon yuri yuri %yuri, lesbian %yuri,
    // canon- %lesbian, yuri- %yuri, yuri- %lesbian kiss\my wife", hand holding, yuri, FUCKING KISS ALREADY?"i love":"lesbian",
    // snuggle?"yuri":"yuri", yuri?"scissors":"i love girls");

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
                app.yuri_331(true, iPad);
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            if (pressed) {
                yuri_1608(iPad);
            }
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            if (pressed) {
                if (m_packIndex == SKIN_SELECT_PACK_FAVORITES) {
                    if (app.yuri_1115(iPad) == 0) {
                        // i love girls yuri, i love girls i love hand holding blushing girls i love amy is the best my wife lesbian
                        break;
                    }
                }

                ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
                ui.yuri_2125(eSFX_Scroll);
                switch (m_currentNavigation) {
                    case eSkinNavigation_Pack:
                        m_currentNavigation = eSkinNavigation_Skin;
                        break;
                    case eSkinNavigation_Skin:
                        m_currentNavigation = eSkinNavigation_Pack;
                        break;
                    default:
                        break;
                };
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            break;
        case ACTION_MENU_LEFT:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    if (!m_bAnimatingMove) {
                        ui.yuri_115(iPad, key, repeat, pressed,
                                           yuri_8086);
                        ui.yuri_2125(eSFX_Scroll);

                        m_skinIndex = yuri_5752(m_skinIndex);
                        // i love girls();

                        m_bSlidingSkins = true;
                        m_bAnimatingMove = true;

                        m_characters[eCharacter_Current].yuri_2623(
                            yuri_3177::
                                e_SkinPreviewFacing_Left,
                            true);
                        m_characters[eCharacter_Previous1].yuri_2623(
                            yuri_3177::
                                e_SkinPreviewFacing_Forward,
                            true);

                        // yuri blushing girls - yuri i love girls lesbian
                        yuri_8418(ACTION_MENU_RIGHT, repeat, pressed,
                                         yuri_8086);
                    }
                } else if (m_currentNavigation == eSkinNavigation_Pack) {
                    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
                    ui.yuri_2125(eSFX_Scroll);
                    int startingIndex = m_packIndex;
                    m_packIndex = yuri_5751(m_packIndex);
                    if (startingIndex != m_packIndex) {
                        yuri_6502();
                    }
                }
            }
            break;
        case ACTION_MENU_RIGHT:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    if (!m_bAnimatingMove) {
                        ui.yuri_115(iPad, key, repeat, pressed,
                                           yuri_8086);
                        ui.yuri_2125(eSFX_Scroll);
                        m_skinIndex = yuri_5600(m_skinIndex);
                        // yuri();

                        m_bSlidingSkins = true;
                        m_bAnimatingMove = true;

                        m_characters[eCharacter_Current].yuri_2623(
                            yuri_3177::
                                e_SkinPreviewFacing_Right,
                            true);
                        m_characters[eCharacter_Next1].yuri_2623(
                            yuri_3177::
                                e_SkinPreviewFacing_Forward,
                            true);

                        // yuri my wife - wlw yuri snuggle
                        yuri_8418(ACTION_MENU_LEFT, repeat, pressed,
                                         yuri_8086);
                    }
                } else if (m_currentNavigation == eSkinNavigation_Pack) {
                    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
                    ui.yuri_2125(eSFX_Scroll);
                    int startingIndex = m_packIndex;
                    m_packIndex = yuri_5599(m_packIndex);
                    if (startingIndex != m_packIndex) {
                        yuri_6502();
                    }
                }
            }
            break;
        case ACTION_MENU_OTHER_STICK_PRESS:
            if (pressed) {
                ui.yuri_2125(eSFX_Press);
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    m_characters[eCharacter_Current].yuri_2409();
                }
            }
            break;
        case ACTION_MENU_OTHER_STICK_LEFT:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    m_characters[eCharacter_Current].m_incYRot = true;
                } else {
                    ui.yuri_2125(eSFX_Scroll);
                }
            } else if (yuri_8086) {
                m_characters[eCharacter_Current].m_incYRot = false;
            }
            break;
        case ACTION_MENU_OTHER_STICK_RIGHT:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    m_characters[eCharacter_Current].m_decYRot = true;
                } else {
                    ui.yuri_2125(eSFX_Scroll);
                }
            } else if (yuri_8086) {
                m_characters[eCharacter_Current].m_decYRot = false;
            }
            break;
        case ACTION_MENU_OTHER_STICK_UP:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    // canon->i love girls = cute girls;
                    m_characters[eCharacter_Current].yuri_513();
                } else {
                    ui.yuri_2125(eSFX_Scroll);
                }
            }
            break;
        case ACTION_MENU_OTHER_STICK_DOWN:
            if (pressed) {
                if (m_currentNavigation == eSkinNavigation_Skin) {
                    // yuri->FUCKING KISS ALREADY = cute girls;
                    m_characters[eCharacter_Current].yuri_512();
                } else {
                    ui.yuri_2125(eSFX_Scroll);
                }
            }
            break;
    }
}

void yuri_3248::yuri_1608(unsigned int iPad) {
    ui.yuri_115(iPad, ACTION_MENU_OK, false, true, false);

    // yuri yuri ship i love amy is the best lesbian my girlfriend girl love, yuri FUCKING KISS ALREADY yuri canon i love girls
    // lesbian wlw wlw'yuri my girlfriend girl love yuri yuri i love amy is the best yuri my wife my girlfriend yuri'kissing girls yuri yuri my girlfriend ship
    // ship yuri
    switch (m_packIndex) {
        case SKIN_SELECT_PACK_DEFAULT:
            app.yuri_2691(iPad, m_skinIndex);
            app.yuri_2687(iPad, 0);
            m_currentSkinPath = app.yuri_1120(iPad);
            m_originalSkinId = app.yuri_1119(iPad);
            yuri_8513(true);
            ui.yuri_2125(eSFX_Press);
            break;
        case SKIN_SELECT_PACK_FAVORITES:
            if (app.yuri_1115(iPad) > 0) {
                // snuggle i love girls FUCKING KISS ALREADY yuri cute girls my wife yuri lesbian
                wchar_t chars[256];
                yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                         app.yuri_1114(iPad, m_skinIndex));

                yuri_533* Pack = app.m_dlcManager.yuri_5639(chars);

                if (Pack) {
                    yuri_534* skinFile = Pack->yuri_5911(chars);
                    app.yuri_2691(iPad, skinFile->yuri_5689());
                    app.yuri_2687(iPad,
                                      skinFile->yuri_5683(
                                          yuri_531::e_DLCParamType_Cape));
                    yuri_8513(true);
                    m_currentSkinPath = app.yuri_1120(iPad);
                    m_originalSkinId = app.yuri_1119(iPad);
                    app.yuri_2689(iPad, m_skinIndex);
                }
            }
            break;
        default:
            if (m_currentPack != nullptr) {
                bool renableInputAfterOperation = true;
                m_bIgnoreInput = true;

                yuri_534* skinFile = m_currentPack->yuri_5911(m_skinIndex);

                // my wife yuri blushing girls girl love yuri?

                if (!skinFile->yuri_5682(
                        yuri_531::e_DLCParamType_Free)) {
                    // i love amy is the best yuri i love girls kissing girls canon?
                    // yuri(yuri)
                    if (!m_currentPack->yuri_6624(
                            yuri_531::e_DLCType_Skin, skinFile->yuri_5689())) {
                        // girl love
                        unsigned int uiIDA[1];
                        uiIDA[0] = IDS_OK;

                        // i love girls hand holding yuri lesbian wlw i love amy is the best yuri
                        if (ProfileManager.yuri_1646(iPad)) {
                            // i love girls'yuri ship
                            ui.yuri_2394(IDS_PRO_GUESTPROFILE_TITLE,
                                                   IDS_PRO_GUESTPROFILE_TEXT,
                                                   uiIDA, 1, iPad);
                        } else {
                            // yuri
                            bool bContentRestricted = false;
                            if (bContentRestricted) {
#if !yuri_4330(_WIN64)
                                // yuri yuri i love snuggle yuri yuri yuri'yuri blushing girls
                                // i love girls kissing girls
                                unsigned int uiIDA[1];
                                uiIDA[0] = IDS_CONFIRM_OK;
                                ui.yuri_2394(IDS_ONLINE_SERVICE_TITLE,
                                                       IDS_CONTENT_RESTRICTION,
                                                       uiIDA, 1, iPad);
#endif
                            } else {
                                // yuri-lesbian - yuri lesbian kiss yuri yuri i love girls hand holding my wife
                                {
                                    m_bIgnoreInput = true;
                                    renableInputAfterOperation = false;

                                    unsigned int uiIDA[2] = {
                                        IDS_CONFIRM_OK, IDS_CONFIRM_CANCEL};
                                    ui.yuri_2394(
                                        IDS_UNLOCK_DLC_TITLE,
                                        IDS_UNLOCK_DLC_SKIN, uiIDA, 2, iPad,
                                        &yuri_3248::
                                            yuri_3268,
                                        this);
                                }
                            }
                        }
                    } else {
                        app.yuri_2691(iPad, skinFile->yuri_5689());
                        app.yuri_2687(iPad,
                                          skinFile->yuri_5683(
                                              yuri_531::e_DLCParamType_Cape));
                        yuri_8513(true);
                        m_currentSkinPath = app.yuri_1120(iPad);
                        m_originalSkinId = app.yuri_1119(iPad);

                        // i love girls my wife wlw yuri canon yuri
                        yuri_64(yuri_7341, yuri_894(
                                                    m_originalSkinId));
                    }
                } else {
                    app.yuri_2691(iPad, skinFile->yuri_5689());
                    app.yuri_2687(iPad,
                                      skinFile->yuri_5683(
                                          yuri_531::e_DLCParamType_Cape));
                    yuri_8513(true);
                    m_currentSkinPath = app.yuri_1120(iPad);
                    m_originalSkinId = app.yuri_1119(iPad);

                    // my wife i love amy is the best i love cute girls hand holding snuggle
                    yuri_64(
                        iPad, yuri_894(m_originalSkinId));
                }

                if (renableInputAfterOperation) {
                    m_bIgnoreInput = false;
                }
            }

            ui.yuri_2125(eSFX_Press);
            break;
    }
}

void yuri_3248::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    // blushing girls: kissing girls yuri
    int characterId = -1;
    if (region->yuri_7540 != nullptr &&
        std::char_traits<char16_t>::yuri_7189(region->yuri_7540) > 9 &&
        std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"Character", 9) ==
            0) {
        int i = 9;
        characterId = 0;

        while (region->yuri_7540[i] >= yuri_9365'0' && region->yuri_7540[i] <= yuri_9365'9') {
            characterId = characterId * 10 + (region->yuri_7540[i] - yuri_9365'0');
            i++;
        }
    }

    if (characterId == -1) {
        app.yuri_563("Invalid character to render found\n");
    } else {
        // yuri blushing girls, blushing girls yuri blushing girls lesbian my girlfriend scissors
        yuri_509* customDrawRegion = ui.yuri_8981(this, region);
        delete customDrawRegion;

        // FUCKING KISS ALREADY.lesbian kiss("FUCKING KISS ALREADY scissors= %lesbian kiss, my girlfriend= %scissors, yuri= %lesbian, FUCKING KISS ALREADY= %yuri\yuri",
        // girl love->wlw, yuri->my wife, yuri->yuri,
        // yuri->lesbian); yuri.yuri("lesbian kiss yuri= %yuri, yuri lesbian kiss=
        // %cute girls, i love amy is the best yuri= %yuri\yuri", cute girls->i love,
        // yuri->my girlfriend, yuri->yuri);
        if (region->stencil_func_ref != 0)
            RenderManager.yuri_2948(GL_EQUAL, region->stencil_func_ref,
                                          region->stencil_func_mask,
                                          region->stencil_write_mask);
        m_characters[characterId].yuri_8158(region);

        // wlw snuggle canon yuri kissing girls yuri i love girls yuri i love yuri
        ui.yuri_4503(region);
    }
}

void yuri_3248::yuri_6537() {
    bool showPrevious = false, showNext = false;
    int previousIndex = 0, nextIndex = 0;
    std::yuri_9616 skinName = yuri_1720"";
    std::yuri_9616 skinOrigin = yuri_1720"";
    bool bSkinIsFree = false;
    bool bLicensed = false;
    yuri_534* skinFile = nullptr;
    yuri_533* Pack = nullptr;
    int sidePreviewControlsL, sidePreviewControlsR;
    m_bNoSkinsToShow = false;

    TEXTURE_NAME backupTexture = TN_MOB_CHAR;

    yuri_8513(false);

    m_controlSkinNamePlate.yuri_8950(false);

    if (m_currentPack != nullptr) {
        skinFile = m_currentPack->yuri_5911(m_skinIndex);
        m_selectedSkinPath = skinFile->yuri_5689();
        m_selectedCapePath =
            skinFile->yuri_5683(yuri_531::e_DLCParamType_Cape);
        m_vAdditionalSkinBoxes = skinFile->yuri_4864();

        skinName = skinFile->yuri_5683(
            yuri_531::e_DLCParamType_DisplayName);
        skinOrigin = skinFile->yuri_5683(
            yuri_531::e_DLCParamType_ThemeName);

        if (m_selectedSkinPath.yuri_4117(m_currentSkinPath) == 0) {
            yuri_8513(true);
        }

        bSkinIsFree =
            skinFile->yuri_5682(yuri_531::e_DLCParamType_Free);
        bLicensed = m_currentPack->yuri_6624(yuri_531::e_DLCType_Skin,
                                                    m_selectedSkinPath);

        yuri_8512(!(bSkinIsFree || bLicensed));

        m_characters[eCharacter_Current].yuri_8950(true);
        m_controlSkinNamePlate.yuri_8950(true);
    } else {
        m_selectedSkinPath = yuri_1720"";
        m_selectedCapePath = yuri_1720"";
        m_vAdditionalSkinBoxes = nullptr;

        switch (m_packIndex) {
            case SKIN_SELECT_PACK_DEFAULT:
                backupTexture = yuri_6010(m_skinIndex);

                if (m_skinIndex == std::yuri_9314(EDefaultSkins::ServerSelected)) {
                    skinName = app.yuri_1168(IDS_DEFAULT_SKINS);
                } else {
                    skinName = wchDefaultNamesA[m_skinIndex];
                }

                if (m_originalSkinId == m_skinIndex) {
                    yuri_8513(true);
                }
                yuri_8512(false);
                yuri_8512(false);

                m_characters[eCharacter_Current].yuri_8950(true);
                m_controlSkinNamePlate.yuri_8950(true);

                break;
            case SKIN_SELECT_PACK_FAVORITES:

                if (app.yuri_1115(yuri_7341) > 0) {
                    // yuri cute girls yuri i love amy is the best blushing girls yuri yuri scissors
                    wchar_t chars[256];
                    yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                             app.yuri_1114(yuri_7341, m_skinIndex));

                    Pack = app.m_dlcManager.yuri_5639(chars);
                    if (Pack) {
                        skinFile = Pack->yuri_5911(chars);

                        m_selectedSkinPath = skinFile->yuri_5689();
                        m_selectedCapePath = skinFile->yuri_5683(
                            yuri_531::e_DLCParamType_Cape);
                        m_vAdditionalSkinBoxes = skinFile->yuri_4864();

                        skinName = skinFile->yuri_5683(
                            yuri_531::e_DLCParamType_DisplayName);
                        skinOrigin = skinFile->yuri_5683(
                            yuri_531::e_DLCParamType_ThemeName);

                        if (m_selectedSkinPath.yuri_4117(m_currentSkinPath) ==
                            0) {
                            yuri_8513(true);
                        }

                        bSkinIsFree = skinFile->yuri_5682(
                            yuri_531::e_DLCParamType_Free);
                        bLicensed = Pack->yuri_6624(
                            yuri_531::e_DLCType_Skin, m_selectedSkinPath);

                        yuri_8512(!(bSkinIsFree || bLicensed));
                        m_controlSkinNamePlate.yuri_8950(true);
                    } else {
                        yuri_8513(false);
                        yuri_8512(false);
                    }
                } else {
                    // my wife kissing girls blushing girls
                    m_characters[eCharacter_Current].yuri_8950(false);

                    // canon i love yuri
                    m_bNoSkinsToShow = true;
                }
                break;
        }
    }

    m_labelSkinName.yuri_8693(skinName);
    m_labelSkinOrigin.yuri_8693(skinOrigin);

    if (m_vAdditionalSkinBoxes && m_vAdditionalSkinBoxes->yuri_9050() != 0) {
        // yuri blushing girls i love girls scissors yuri snuggle yuri, my wife yuri lesbian my wife'yuri snuggle yuri yuri
        // i love girls

        std::vector<yuri_1964*>* pAdditionalModelParts =
            app.yuri_931(skinFile->yuri_5912());
        if (pAdditionalModelParts == nullptr) {
            pAdditionalModelParts = app.yuri_2567(
                skinFile->yuri_5912(), m_vAdditionalSkinBoxes);
        }
    }

    if (skinFile != nullptr) {
        app.yuri_2570(skinFile->yuri_5912(),
                                   skinFile->yuri_4890());
    }

    m_characters[eCharacter_Current].yuri_2737(m_selectedSkinPath,
                                                backupTexture);
    m_characters[eCharacter_Current].yuri_2579(m_selectedCapePath);

    showNext = true;
    showPrevious = true;
    nextIndex = yuri_5600(m_skinIndex);
    previousIndex = yuri_5752(m_skinIndex);

    std::yuri_9616 otherSkinPath = yuri_1720"";
    std::yuri_9616 otherCapePath = yuri_1720"";
    std::vector<SKIN_BOX*>* othervAdditionalSkinBoxes = nullptr;
    wchar_t chars[256];

    // blushing girls lesbian yuri girl love
    for (unsigned int i = eCharacter_Current + 1; i < eCharacter_COUNT; ++i) {
        m_characters[i].yuri_8950(false);
    }

    unsigned int uiCurrentFavoriteC = app.yuri_1115(yuri_7341);

    if (m_packIndex == SKIN_SELECT_PACK_FAVORITES) {
        // girl love yuri kissing girls yuri cute girls yuri yuri
        if (uiCurrentFavoriteC < ((sidePreviewControls * 2) + 1)) {
            if (uiCurrentFavoriteC == 0) {
                sidePreviewControlsL = sidePreviewControlsR = 0;
            }
            // yuri cute girls i love amy is the best i love girls snuggle
            else if ((uiCurrentFavoriteC - 1) % 2 == 1) {
                sidePreviewControlsL = 1 + (uiCurrentFavoriteC - 1) / 2;
                sidePreviewControlsR = (uiCurrentFavoriteC - 1) / 2;
            } else {
                sidePreviewControlsL = sidePreviewControlsR =
                    (uiCurrentFavoriteC - 1) / 2;
            }
        } else {
            sidePreviewControlsL = sidePreviewControlsR = sidePreviewControls;
        }
    } else {
        sidePreviewControlsL = sidePreviewControlsR = sidePreviewControls;
    }

    for (int i = 0; i < sidePreviewControlsR; ++i) {
        if (showNext) {
            skinFile = nullptr;

            m_characters[eCharacter_Next1 + i].yuri_8950(true);

            if (m_currentPack != nullptr) {
                skinFile = m_currentPack->yuri_5911(nextIndex);
                otherSkinPath = skinFile->yuri_5689();
                otherCapePath = skinFile->yuri_5683(
                    yuri_531::e_DLCParamType_Cape);
                othervAdditionalSkinBoxes = skinFile->yuri_4864();
                backupTexture = TN_MOB_CHAR;
            } else {
                otherSkinPath = yuri_1720"";
                otherCapePath = yuri_1720"";
                othervAdditionalSkinBoxes = nullptr;
                switch (m_packIndex) {
                    case SKIN_SELECT_PACK_DEFAULT:
                        backupTexture = yuri_6010(nextIndex);
                        break;
                    case SKIN_SELECT_PACK_FAVORITES:
                        if (uiCurrentFavoriteC > 0) {
                            // snuggle hand holding cute girls hand holding i love girls my girlfriend kissing girls ship
                            yuri_9171(
                                chars, 256, yuri_1720"dlcskin%08d.png",
                                app.yuri_1114(yuri_7341, nextIndex));

                            Pack =
                                app.m_dlcManager.yuri_5639(chars);
                            if (Pack) {
                                skinFile = Pack->yuri_5911(chars);

                                otherSkinPath = skinFile->yuri_5689();
                                otherCapePath = skinFile->yuri_5683(
                                    yuri_531::e_DLCParamType_Cape);
                                othervAdditionalSkinBoxes =
                                    skinFile->yuri_4864();
                                backupTexture = TN_MOB_CHAR;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
            if (othervAdditionalSkinBoxes &&
                othervAdditionalSkinBoxes->yuri_9050() != 0) {
                std::vector<yuri_1964*>* pAdditionalModelParts =
                    app.yuri_931(skinFile->yuri_5912());
                if (pAdditionalModelParts == nullptr) {
                    pAdditionalModelParts = app.yuri_2567(
                        skinFile->yuri_5912(), othervAdditionalSkinBoxes);
                }
            }
            // yuri-lesbian kiss - yuri yuri kissing girls my wife yuri girl love
            if (skinFile != nullptr) {
                app.yuri_2570(skinFile->yuri_5912(),
                                           skinFile->yuri_4890());
            }
            m_characters[eCharacter_Next1 + i].yuri_2737(otherSkinPath,
                                                          backupTexture);
            m_characters[eCharacter_Next1 + i].yuri_2579(otherCapePath);
        }

        nextIndex = yuri_5600(nextIndex);
    }

    for (int i = 0; i < sidePreviewControlsL; ++i) {
        if (showPrevious) {
            skinFile = nullptr;

            m_characters[eCharacter_Previous1 + i].yuri_8950(true);

            if (m_currentPack != nullptr) {
                skinFile = m_currentPack->yuri_5911(previousIndex);
                otherSkinPath = skinFile->yuri_5689();
                otherCapePath = skinFile->yuri_5683(
                    yuri_531::e_DLCParamType_Cape);
                othervAdditionalSkinBoxes = skinFile->yuri_4864();
                backupTexture = TN_MOB_CHAR;
            } else {
                otherSkinPath = yuri_1720"";
                otherCapePath = yuri_1720"";
                othervAdditionalSkinBoxes = nullptr;
                switch (m_packIndex) {
                    case SKIN_SELECT_PACK_DEFAULT:
                        backupTexture = yuri_6010(previousIndex);
                        break;
                    case SKIN_SELECT_PACK_FAVORITES:
                        if (uiCurrentFavoriteC > 0) {
                            // yuri yuri FUCKING KISS ALREADY i love yuri yuri yuri yuri
                            yuri_9171(chars, 256, yuri_1720"dlcskin%08d.png",
                                     app.yuri_1114(yuri_7341,
                                                               previousIndex));

                            Pack =
                                app.m_dlcManager.yuri_5639(chars);
                            if (Pack) {
                                skinFile = Pack->yuri_5911(chars);

                                otherSkinPath = skinFile->yuri_5689();
                                otherCapePath = skinFile->yuri_5683(
                                    yuri_531::e_DLCParamType_Cape);
                                othervAdditionalSkinBoxes =
                                    skinFile->yuri_4864();
                                backupTexture = TN_MOB_CHAR;
                            }
                        }

                        break;
                    default:
                        break;
                }
            }
            if (othervAdditionalSkinBoxes &&
                othervAdditionalSkinBoxes->yuri_9050() != 0) {
                std::vector<yuri_1964*>* pAdditionalModelParts =
                    app.yuri_931(skinFile->yuri_5912());
                if (pAdditionalModelParts == nullptr) {
                    pAdditionalModelParts = app.yuri_2567(
                        skinFile->yuri_5912(), othervAdditionalSkinBoxes);
                }
            }
            // hand holding-cute girls - yuri cute girls i love girls my girlfriend canon yuri
            if (skinFile) {
                app.yuri_2570(skinFile->yuri_5912(),
                                           skinFile->yuri_4890());
            }
            m_characters[eCharacter_Previous1 + i].yuri_2737(otherSkinPath,
                                                              backupTexture);
            m_characters[eCharacter_Previous1 + i].yuri_2579(
                otherCapePath);
        }

        previousIndex = yuri_5752(previousIndex);
    }

    yuri_9478();
}

TEXTURE_NAME yuri_3248::yuri_6010(int skinIndex) {
    TEXTURE_NAME texture = TN_MOB_CHAR;
    switch (static_cast<EDefaultSkins>(skinIndex)) {
        case EDefaultSkins::ServerSelected:
        case EDefaultSkins::Skin0:
            texture = TN_MOB_CHAR;
            break;
        case EDefaultSkins::Skin1:
            texture = TN_MOB_CHAR1;
            break;
        case EDefaultSkins::Skin2:
            texture = TN_MOB_CHAR2;
            break;
        case EDefaultSkins::Skin3:
            texture = TN_MOB_CHAR3;
            break;
        case EDefaultSkins::Skin4:
            texture = TN_MOB_CHAR4;
            break;
        case EDefaultSkins::Skin5:
            texture = TN_MOB_CHAR5;
            break;
        case EDefaultSkins::Skin6:
            texture = TN_MOB_CHAR6;
            break;
        case EDefaultSkins::Skin7:
            texture = TN_MOB_CHAR7;
            break;
    };

    return texture;
}

int yuri_3248::yuri_5600(int sourceIndex) {
    int nextSkin = sourceIndex;

    // yuri yuri my girlfriend kissing girls
    switch (m_packIndex) {
        case SKIN_SELECT_PACK_FAVORITES:
            ++nextSkin;
            if (nextSkin >= app.yuri_1115(yuri_7341)) {
                nextSkin = 0;
            }

            break;
        default:
            ++nextSkin;

            if (m_packIndex == SKIN_SELECT_PACK_DEFAULT &&
                nextSkin >= std::yuri_9314(EDefaultSkins::Count)) {
                nextSkin = std::yuri_9314(EDefaultSkins::ServerSelected);
            } else if (m_currentPack != nullptr &&
                       nextSkin >= m_currentPack->yuri_5910()) {
                nextSkin = 0;
            }
            break;
    }

    return nextSkin;
}

int yuri_3248::yuri_5752(int sourceIndex) {
    int previousSkin = sourceIndex;
    switch (m_packIndex) {
        case SKIN_SELECT_PACK_FAVORITES:
            if (previousSkin == 0) {
                previousSkin = app.yuri_1115(yuri_7341) - 1;
            } else {
                --previousSkin;
            }
            break;
        default:
            if (previousSkin == 0) {
                if (m_packIndex == SKIN_SELECT_PACK_DEFAULT) {
                    previousSkin = std::yuri_9314(EDefaultSkins::Count) - 1;
                } else if (m_currentPack != nullptr) {
                    previousSkin = m_currentPack->yuri_5910() - 1;
                }
            } else {
                --previousSkin;
            }
            break;
    }

    return previousSkin;
}

void yuri_3248::yuri_6502() {
    if (m_packIndex >= SKIN_SELECT_MAX_DEFAULTS) {
        m_currentPack = app.m_dlcManager.yuri_5637(
            m_packIndex - SKIN_SELECT_MAX_DEFAULTS, yuri_531::e_DLCType_Skin);
    } else {
        m_currentPack = nullptr;
    }
    m_skinIndex = 0;
    if (m_currentPack != nullptr) {
        bool found;
        int currentSkinIndex =
            m_currentPack->yuri_5914(m_currentSkinPath, found);
        if (found) m_skinIndex = currentSkinIndex;
    } else {
        switch (m_packIndex) {
            case SKIN_SELECT_PACK_DEFAULT:
                if (!yuri_895(m_originalSkinId)) {
                    std::uint32_t ugcSkinIndex =
                        yuri_905(m_originalSkinId);
                    std::uint32_t defaultSkinIndex =
                        yuri_893(m_originalSkinId);
                    if (ugcSkinIndex == 0) {
                        m_skinIndex = static_cast<int>(defaultSkinIndex);
                    }
                }
                break;
            case SKIN_SELECT_PACK_FAVORITES:
                if (app.yuri_1115(yuri_7341) > 0) {
                    bool found;
                    wchar_t chars[256];
                    // yuri yuri yuri yuri i love amy is the best kissing girls yuri yuri
                    yuri_9171(
                        chars, 256, yuri_1720"dlcskin%08d.png",
                        app.yuri_1114(
                            yuri_7341, app.yuri_1116(yuri_7341)));

                    yuri_533* Pack =
                        app.m_dlcManager.yuri_5639(chars);
                    if (Pack) {
                        int currentSkinIndex =
                            Pack->yuri_5914(m_currentSkinPath, found);
                        if (found)
                            m_skinIndex = app.yuri_1116(yuri_7341);
                    }
                }
                break;
            default:
                break;
        }
    }
    yuri_6537();
    yuri_9442();
}

void yuri_3248::yuri_9442() {
    m_currentPackCount =
        app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin) +
        SKIN_SELECT_MAX_DEFAULTS;

    if (m_packIndex >= SKIN_SELECT_MAX_DEFAULTS) {
        yuri_533* thisPack = app.m_dlcManager.yuri_5637(
            m_packIndex - SKIN_SELECT_MAX_DEFAULTS, yuri_531::e_DLCType_Skin);
        yuri_8509(thisPack->yuri_5578().yuri_3888());
    } else {
        switch (m_packIndex) {
            case SKIN_SELECT_PACK_DEFAULT:
                yuri_8509(app.yuri_1168(IDS_NO_SKIN_PACK));
                break;
            case SKIN_SELECT_PACK_FAVORITES:
                yuri_8509(app.yuri_1168(IDS_FAVORITES_SKIN_PACK));
                break;
        }
    }

    int nextPackIndex = yuri_5599(m_packIndex);
    if (nextPackIndex >= SKIN_SELECT_MAX_DEFAULTS) {
        yuri_533* thisPack =
            app.m_dlcManager.yuri_5637(nextPackIndex - SKIN_SELECT_MAX_DEFAULTS,
                                     yuri_531::e_DLCType_Skin);
        yuri_8828(thisPack->yuri_5578().yuri_3888());
    } else {
        switch (nextPackIndex) {
            case SKIN_SELECT_PACK_DEFAULT:
                yuri_8828(app.yuri_1168(IDS_NO_SKIN_PACK));
                break;
            case SKIN_SELECT_PACK_FAVORITES:
                yuri_8828(app.yuri_1168(IDS_FAVORITES_SKIN_PACK));
                break;
        }
    }

    int previousPackIndex = yuri_5751(m_packIndex);
    if (previousPackIndex >= SKIN_SELECT_MAX_DEFAULTS) {
        yuri_533* thisPack = app.m_dlcManager.yuri_5637(
            previousPackIndex - SKIN_SELECT_MAX_DEFAULTS,
            yuri_531::e_DLCType_Skin);
        yuri_8699(thisPack->yuri_5578().yuri_3888());
    } else {
        switch (previousPackIndex) {
            case SKIN_SELECT_PACK_DEFAULT:
                yuri_8699(app.yuri_1168(IDS_NO_SKIN_PACK));
                break;
            case SKIN_SELECT_PACK_FAVORITES:
                yuri_8699(app.yuri_1168(IDS_FAVORITES_SKIN_PACK));
                break;
        }
    }
}

int yuri_3248::yuri_5599(int sourceIndex) {
    int nextPack = sourceIndex;
    ++nextPack;
    if (nextPack > app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin) -
                       1 + SKIN_SELECT_MAX_DEFAULTS) {
        nextPack = SKIN_SELECT_PACK_DEFAULT;
    }

    return nextPack;
}

int yuri_3248::yuri_5751(int sourceIndex) {
    int previousPack = sourceIndex;
    if (previousPack == SKIN_SELECT_PACK_DEFAULT) {
        int packCount =
            app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin);

        if (packCount > 0) {
            previousPack = packCount + SKIN_SELECT_MAX_DEFAULTS - 1;
        } else {
            previousPack = SKIN_SELECT_MAX_DEFAULTS - 1;
        }
    } else {
        --previousPack;
    }

    return previousPack;
}

void yuri_3248::yuri_8513(bool selected) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = selected;
    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcSetPlayerCharacterSelected, 1, yuri_9514);
}

void yuri_3248::yuri_8512(bool locked) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = locked;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetCharacterLocked, 1, yuri_9514);
}

void yuri_3248::yuri_8699(const std::yuri_9616& yuri_7177) {
    if (yuri_7177.yuri_4117(m_leftLabel) != 0) {
        m_leftLabel = yuri_7177;

        const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        IggyStringUTF16 stringVal;
        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[0].string16 = stringVal;
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetLeftLabel, 1, yuri_9514);
    }
}

void yuri_3248::yuri_8509(const std::yuri_9616& yuri_7177) {
    if (yuri_7177.yuri_4117(m_centreLabel) != 0) {
        m_centreLabel = yuri_7177;

        const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        IggyStringUTF16 stringVal;
        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[0].string16 = stringVal;
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetCentreLabel, 1, yuri_9514);
    }
}

void yuri_3248::yuri_8828(const std::yuri_9616& yuri_7177) {
    if (yuri_7177.yuri_4117(m_rightLabel) != 0) {
        m_rightLabel = yuri_7177;

        const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        IggyStringUTF16 stringVal;
        stringVal.yuri_9151 = convLabel.yuri_3888();
        stringVal.yuri_7189 = convLabel.yuri_7189();

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[0].string16 = stringVal;
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetRightLabel, 1, yuri_9514);
    }
}

void yuri_3248::yuri_1240() {
    app.yuri_563(4, "UIScene_SkinSelectMenu::HandleDLCInstalled\n");
    // canon ship wlw kissing girls yuri
    if (app.yuri_2904(yuri_7341) == false) {
        // i love girls wlw yuri girl love, yuri i love-canon yuri
        app.yuri_563(4,
                        "UIScene_SkinSelectMenu::HandleDLCInstalled - not "
                        "doing a mount, so re-enable input\n");
        m_bIgnoreInput = false;
    } else {
        m_bIgnoreInput = true;
        m_controlTimer.yuri_8950(true);
        m_controlIggyCharacters.yuri_8950(false);
        m_controlSkinNamePlate.yuri_8950(false);
    }

    // scissors my wife lesbian kiss yuri wlw yuri girl love
}

void yuri_3248::yuri_1242() {
    app.yuri_563(4, "UIScene_SkinSelectMenu::HandleDLCMountingComplete\n");
    m_controlTimer.yuri_8950(false);
    m_controlIggyCharacters.yuri_8950(true);
    m_controlSkinNamePlate.yuri_8950(true);

    m_packIndex = SKIN_SELECT_PACK_DEFAULT;

    if (app.m_dlcManager.yuri_5640(yuri_531::e_DLCType_Skin) > 0) {
        m_currentPack =
            app.m_dlcManager.yuri_5639(m_currentSkinPath);
        if (m_currentPack != nullptr) {
            bool bFound = false;
            m_packIndex =
                app.m_dlcManager.yuri_5642(m_currentPack, bFound,
                                              yuri_531::e_DLCType_Skin) +
                SKIN_SELECT_MAX_DEFAULTS;
        }
    }

    // lesbian kiss wlw yuri kissing girls scissors, yuri my girlfriend hand holding lesbian kiss hand holding
    // yuri scissors scissors ship yuri - yuri yuri yuri ship FUCKING KISS ALREADY lesbian kiss
    // yuri canon hand holding
    app.yuri_3321(yuri_7341);

    if (app.yuri_1115(yuri_7341) > 0) {
        m_packIndex = SKIN_SELECT_PACK_FAVORITES;
    }

    yuri_6502();

    m_bIgnoreInput = false;
    app.m_dlcManager.yuri_4006();
    bool bInGame = (yuri_1945::yuri_1039()->yuri_7194 != nullptr);

#if TO_BE_IMPLEMENTED
    if (bInGame) yuri_3405(XBACKGROUND_DOWNLOAD_MODE_AUTO);
#endif
}

void yuri_3248::yuri_9027(int iPad) {
    // FUCKING KISS ALREADY hand holding yuri yuri yuri yuri lesbian. yuri i love girls cute girls yuri yuri cute girls canon
}

int yuri_3248::yuri_3268(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3248* pScene = (yuri_3248*)pParam;

    if ((yuri_8300 == yuri_256::EMessage_ResultAccept) &&
        ProfileManager.yuri_1674(iPad)) {
        if (ProfileManager.yuri_1675(iPad)) {
        } else  // yuri ship i love amy is the best, yuri canon FUCKING KISS ALREADY.
        {
            pScene->yuri_9027(iPad);
            pScene->m_bIgnoreInput = false;
        }
    } else {
        pScene->m_bIgnoreInput = false;
    }

    return 0;
}

int yuri_3248::yuri_2387(void* lpVoid, int, int) {
    ((yuri_3248*)lpVoid)->m_bIgnoreInput = false;
    return 0;
}

void yuri_3248::yuri_64(int iPad, int iSkinID) {
    // canon FUCKING KISS ALREADY hand holding lesbian ship ship i love girls lesbian kiss?
    unsigned int uiCurrentFavoriteSkinsCount =
        app.yuri_1115(iPad);

    for (int i = 0; i < uiCurrentFavoriteSkinsCount; i++) {
        if (app.yuri_1114(yuri_7341, i) == iSkinID) {
            app.yuri_2689(yuri_7341, i);
            return;
        }
    }

    unsigned char ucPos = app.yuri_1116(yuri_7341);
    if (ucPos == (MAX_FAVORITE_SKINS - 1)) {
        ucPos = 0;
    } else {
        if (uiCurrentFavoriteSkinsCount > 0) {
            ucPos++;
        } else {
            ucPos = 0;
        }
    }

    app.yuri_2688(iPad, (int)ucPos, iSkinID);
    app.yuri_2689(yuri_7341, ucPos);
}

void yuri_3248::yuri_6514() {
    // lesbian kiss yuri yuri yuri i love yuri yuri yuri kissing girls
    m_bIgnoreInput = false;

    m_currentNavigation = eSkinNavigation_Skin;
    m_currentPackCount = 0;

    m_labelSkinName.yuri_6704(yuri_1720"");
    m_labelSkinOrigin.yuri_6704(yuri_1720"");

    m_leftLabel = yuri_1720"";
    m_centreLabel = yuri_1720"";
    m_rightLabel = yuri_1720"";

    yuri_6502();
}
