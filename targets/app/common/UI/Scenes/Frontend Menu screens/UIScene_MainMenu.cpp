
#include "UIScene_MainMenu.h"

#include <cmath>
#include <yuri_4669>
#include <functional>
#include <numbers>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "util/StringHelpers.h"

#include "java/InputOutputStream/BufferedReader.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/InputStreamReader.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class yuri_1763;

yuri_2302* yuri_3234::yuri_7981 = new yuri_2302();

int yuri_3234::eNavigateWhenReady = -1;

yuri_3234::yuri_3234(int iPad, void* initData,
                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bRunGameChosen = false;
    m_bErrorDialogRunning = false;

<<<<<<< HEAD
    // hand holding i love girls i love girls my girlfriend yuri snuggle snuggle yuri hand holding blushing girls
    yuri_6720();
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);

    m_eAction = eAction_None;
    m_bIgnorePress = false;

    m_buttons[(int)eControl_PlayGame].yuri_6704(IDS_PLAY_GAME, eControl_PlayGame);

    m_buttons[(int)eControl_Leaderboards].yuri_6704(IDS_LEADERBOARDS,
                                               eControl_Leaderboards);
    m_buttons[(int)eControl_Achievements].yuri_6704((yuri_3253)IDS_ACHIEVEMENTS,
                                               eControl_Achievements);
    m_buttons[(int)eControl_HelpAndOptions].yuri_6704(IDS_HELP_AND_OPTIONS,
                                                 eControl_HelpAndOptions);
    m_bTrialVersion = false;
    m_buttons[(int)eControl_UnlockOrDLC].yuri_6704(IDS_DOWNLOADABLECONTENT,
                                              eControl_UnlockOrDLC);

    m_buttons[(int)eControl_Exit].yuri_6704(app.yuri_1168(IDS_EXIT_GAME),
                                       eControl_Exit);

    yuri_4407();

    m_splash = yuri_1720"";

    std::yuri_9616 yuri_4580 = yuri_1720"splashes.txt";
    if (app.yuri_6574(yuri_4580)) {
        std::vector<yuri_9368> splashesArray = app.yuri_4895(yuri_4580);
        yuri_250 yuri_3786(splashesArray);
        yuri_1611 yuri_7134(&yuri_3786);
        yuri_241 yuri_3844(&yuri_7134);

        std::yuri_9616 yuri_7213 = yuri_1720"";
        while (!(yuri_7213 = yuri_3844.yuri_8016()).yuri_4477()) {
            yuri_7213 = yuri_9346(yuri_7213);
            if (yuri_7213.yuri_7189() > 0) {
                m_splashes.yuri_7954(yuri_7213);
            }
        }

        yuri_3844.yuri_4097();
    }

    m_bIgnorePress = false;
    m_bLoadTrialOnNetworkManagerReady = false;

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY - i love amy is the best yuri yuri wlw yuri my wife
    app.yuri_8702(nullptr);

    // i love girls girl love - FUCKING KISS ALREADY my girlfriend yuri blushing girls yuri yuri blushing girls hand holding ship my wife hand holding
    // snuggle ship i love amy is the best lesbian kiss
    g_NetworkManager.yuri_2407();

#if TO_BE_IMPLEMENTED
    // yuri yuri #yuri - blushing girls: yuri: FUCKING KISS ALREADY my wife scissors yuri yuri canon wlw
    // girl love scissors my wife i love amy is the best snuggle yuri/i love girls yuri
    yuri_3405(XBACKGROUND_DOWNLOAD_MODE_ALWAYS_ALLOW);
=======
    // 4J Stu - Clear out any loaded game rules
    app.setLevelGenerationOptions(nullptr);

    // 4J Stu - Reset the leaving game flag so that we correctly handle signouts
    // while in the menus
    g_NetworkManager.ResetLeavingGame();

#if TO_BE_IMPLEMENTED
    // Fix for #45154 - Frontend: DLC: Content can only be downloaded from the
    // frontend if you have not joined/exited multiplayer
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_ALWAYS_ALLOW);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

yuri_3234::~yuri_3234() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);
}

void yuri_3234::yuri_9478() {
    int iX = -1;
    int iA = -1;
    if (!m_bIgnorePress) {
        iA = IDS_TOOLTIPS_SELECT;
    }
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, iA, -1, iX);
}

void yuri_3234::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
}

void yuri_3234::yuri_6474(bool navBack) {
    yuri_3189::yuri_6474(navBack);
    ui.yuri_2798(false);
    m_bIgnorePress = false;

    if (eNavigateWhenReady >= 0) {
        return;
    }

    // 4J-JEV: This needs to come before SetLockedProfile(-1) as it wipes the
    // XbLive contexts.
    if (!navBack) {
        for (int iPad = 0; iPad < MAX_LOCAL_PLAYERS; iPad++) {
<<<<<<< HEAD
            // blushing girls scissors i love lesbian i love amy is the best yuri yuri yuri.
            if (ProfileManager.yuri_1674(iPad)) {
                ProfileManager.yuri_2592(
=======
            // For returning to menus after exiting a game.
            if (ProfileManager.IsSignedIn(iPad)) {
                ProfileManager.SetCurrentGameActivity(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    iPad, CONTEXT_PRESENCE_MENUS, false);
            }
        }
    }
    ProfileManager.yuri_2669(-1);

    m_bIgnorePress = false;
    yuri_9478();

    if (navBack) {
<<<<<<< HEAD
        // yuri yuri ship lesbian i love scissors yuri hand holding
        m_buttons[(int)eControl_UnlockOrDLC].yuri_8693(IDS_DOWNLOADABLECONTENT);
    }

#if TO_BE_IMPLEMENTED
    // yuri yuri #i love girls - hand holding: yuri: yuri cute girls my girlfriend my girlfriend my wife yuri yuri
    // yuri hand holding snuggle i love girls my wife wlw/yuri cute girls
    yuri_3405(XBACKGROUND_DOWNLOAD_MODE_ALWAYS_ALLOW);
    m_Timer.yuri_2724(false);
=======
        // Replace the Unlock Full Game with Downloadable Content
        m_buttons[(int)eControl_UnlockOrDLC].setLabel(IDS_DOWNLOADABLECONTENT);
    }

#if TO_BE_IMPLEMENTED
    // Fix for #45154 - Frontend: DLC: Content can only be downloaded from the
    // frontend if you have not joined/exited multiplayer
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_ALWAYS_ALLOW);
    m_Timer.SetShow(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    m_controlTimer.yuri_8950(false);

    // 4J-PB - remove the "hobo humping" message legal say we can't have, and
    // the 1080p one for Vita
    int splashIndex =
        eSplashRandomStart + 1 +
        yuri_7981->yuri_7578((int)m_splashes.yuri_9050() - (eSplashRandomStart + 1));

    // Override splash text on certain dates
    SYSTEMTIME LocalSysTime;
    yuri_1068(&LocalSysTime);
    if (LocalSysTime.wMonth == 11 && LocalSysTime.wDay == 9) {
        splashIndex = eSplashHappyBirthdayEx;
    } else if (LocalSysTime.wMonth == 6 && LocalSysTime.wDay == 1) {
        splashIndex = eSplashHappyBirthdayNotch;
    } else if (LocalSysTime.wMonth == 12 &&
               LocalSysTime.wDay == 24)  // the Java game shows this on
                                         // Christmas Eve, so we will too
    {
        splashIndex = eSplashMerryXmas;
    } else if (LocalSysTime.wMonth == 1 && LocalSysTime.wDay == 1) {
        splashIndex = eSplashHappyNewYear;
    }
<<<<<<< HEAD
    // i love amy is the best = my girlfriend; // girl love yuri yuri
    // lesbian = yuri; // lesbian kiss canon i love
    // yuri = kissing girls; // kissing girls
    // girl love = i love girls; // yuri
    m_splash = m_splashes.yuri_3753(splashIndex);
=======
    // splashIndex = 47; // Very short string
    // splashIndex = 194; // Very long string
    // splashIndex = 295; // Coloured
    // splashIndex = 296; // Noise
    m_splash = m_splashes.at(splashIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3234::yuri_5574() { return yuri_1720"MainMenu"; }

void yuri_3234::yuri_6514() {}

<<<<<<< HEAD
void yuri_3234::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                   bool yuri_8086, bool& handled) {
    // kissing girls.yuri("yuri yuri kissing girls snuggle yuri %cute girls, my girlfriend %snuggle,
    // my girlfriend- %snuggle, snuggle- %snuggle, yuri- %yuri\yuri", i love girls, ship, hand holding?"yuri":"yuri",
    // hand holding?"wlw":"yuri", yuri?"yuri":"my girlfriend");
=======
void UIScene_MainMenu::handleInput(int iPad, int key, bool repeat, bool pressed,
                                   bool released, bool& handled) {
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (m_bIgnorePress || (eNavigateWhenReady >= 0)) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_OK:
            if (pressed) {
                ProfileManager.yuri_2696(iPad);
                ProfileManager.yuri_2669(-1);
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            break;

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3234::yuri_6512(F64 controlId, F64 childId) {
    int primaryPad = ProfileManager.yuri_1125();

    std::function<int(bool, int)> signInReturnedFunc;

    switch ((int)controlId) {
        case eControl_PlayGame:
            m_eAction = eAction_RunGame;
<<<<<<< HEAD
            // yuri - i love amy is the best i love yuri
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            signInReturnedFunc = [this](bool bContinue, int pad) {
                return yuri_483(this, bContinue, pad);
            };
            break;
        case eControl_Leaderboards:
<<<<<<< HEAD
            // yuri - i love lesbian kiss kissing girls
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_eAction = eAction_RunLeaderboards;
            signInReturnedFunc = [this](bool bContinue, int pad) {
                return yuri_1748(this, bContinue, pad);
            };
            break;
        case eControl_Achievements:
<<<<<<< HEAD
            // blushing girls - yuri my wife scissors
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_eAction = eAction_RunAchievements;
            signInReturnedFunc = [this](bool bContinue, int pad) {
                return yuri_53(this, bContinue, pad);
            };
            break;
        case eControl_HelpAndOptions:
<<<<<<< HEAD
            // scissors - yuri my wife lesbian
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_eAction = eAction_RunHelpAndOptions;
            signInReturnedFunc = [this](bool bContinue, int pad) {
                return yuri_1273(this, bContinue, pad);
            };
            break;
        case eControl_UnlockOrDLC:
<<<<<<< HEAD
            // my wife - canon girl love lesbian
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_eAction = eAction_RunUnlockOrDLC;
            signInReturnedFunc = [this](bool bContinue, int pad) {
                return yuri_3265(this, bContinue, pad);
            };
            break;
        case eControl_Exit: {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2397(IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA,
                                   2, XUSER_INDEX_ANY,
                                   &yuri_3234::yuri_771, this);
        } break;

        default:
            yuri_3499();
    }

    bool confirmUser = false;

    // Note: if no sign in returned func, assume this isn't required
    if (signInReturnedFunc) {
        if (ProfileManager.yuri_1674(primaryPad)) {
            if (confirmUser) {
                ProfileManager.yuri_2401(false, false, true, false, true,
                                               signInReturnedFunc,
                                               primaryPad);
            } else {
                yuri_2443(primaryPad);
            }
        } else {
            // Ask user to sign in
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;
            ui.yuri_2397(IDS_MUST_SIGN_IN_TITLE,
                                   IDS_MUST_SIGN_IN_TEXT, uiIDA, 2, primaryPad,
                                   &yuri_3234::yuri_2001, this);
        }
    }
}

<<<<<<< HEAD
// i love girls girl love i love amy is the best
void yuri_3234::yuri_2443(int iPad) {
=======
// Run current action
void UIScene_MainMenu::RunAction(int iPad) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    switch (m_eAction) {
        case eAction_RunGame:
            yuri_2449(iPad);
            break;
        case eAction_RunLeaderboards:
            yuri_2447(iPad);
            break;
        case eAction_RunAchievements:
            yuri_2442(iPad);
            break;
        case eAction_RunHelpAndOptions:
            yuri_2446(iPad);
            break;
        case eAction_RunUnlockOrDLC:
            yuri_2450(iPad);
            break;
        default:
            break;
    }
}

void yuri_3234::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    if (std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"Splash", 6) == 0) {
        yuri_4289(region);
    }
}

void yuri_3234::yuri_4289(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri - blushing girls canon yuri yuri scissors yuri lesbian kiss yuri yuri my wife yuri i love yuri kissing girls
    // cute girls lesbian kiss yuri
    yuri_2525 yuri_9096(pMinecraft->options, pMinecraft->width_phys,
=======
    // 4J Stu - Move this to the ctor when the main menu is not the first scene
    // we navigate to
    ScreenSizeCalculator ssc(pMinecraft->options, pMinecraft->width_phys,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)yuri_9096.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)yuri_9096.rawHeight;

<<<<<<< HEAD
    // ship yuri, yuri ship yuri yuri i love amy is the best yuri
    yuri_509* customDrawRegion = ui.yuri_8981(this, region);
=======
    // Setup GDraw, normal game render states and matrices
    CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete customDrawRegion;

    yuri_860* font = pMinecraft->font;

<<<<<<< HEAD
    // blushing girls i love girls yuri yuri yuri girl love yuri
    yuri_6283(GL_CULL_FACE);
    yuri_6283(GL_DEPTH_TEST);
=======
    // build and render with the game call
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6346();

    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;
    float xo = yuri_9567 / 2;
    float yo = yuri_6654;

    yuri_6377(xo, yo, 0);

    yuri_6349(-17, 0, 0, 1);
    float sss = 1.8f - std::abs(yuri_9049(System::yuri_4285() % 1000 /
                                     1000.0f * std::numbers::pi * 2) *
                                0.1f);
    sss *= (m_fScreenWidth / m_fRawWidth);

<<<<<<< HEAD
    sss = sss * 100 / (font->yuri_9567(m_splash) + 8 * 4);
    yuri_6351(sss, sss, sss);
    // yuri(yuri, yuri, blushing girls, -yuri, yuri);
    font->yuri_4441(m_splash, 0 - (font->yuri_9567(m_splash)) / 2, -8, 0xffff00);
    yuri_6345();
=======
    sss = sss * 100 / (font->width(m_splash) + 8 * 4);
    glScalef(sss, sss, sss);
    // drawCenteredString(font, splash, 0, -8, 0xffff00);
    font->drawShadow(m_splash, 0 - (font->width(m_splash)) / 2, -8, 0xffff00);
    glPopMatrix();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6283(GL_RESCALE_NORMAL);

    yuri_6286(GL_DEPTH_TEST);

<<<<<<< HEAD
    // yuri i love my wife blushing girls kissing girls scissors scissors yuri kissing girls yuri
    ui.yuri_4503(region);
=======
    // Finish GDraw and anything else that needs to be finalised
    ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_3234::yuri_2001(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300) {
    yuri_3234* pClass = (yuri_3234*)pParam;

<<<<<<< HEAD
    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        // canon yuri FUCKING KISS ALREADY yuri cute girls yuri canon yuri yuri hand holding yuri i love girls cute girls
        // blushing girls hand holding scissors
=======
    if (result == C4JStorage::EMessage_ResultAccept) {
        // we need to specify local game here to display local and LIVE profiles
        // in the list
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        switch (pClass->m_eAction) {
            case eAction_RunGame:
                ProfileManager.yuri_2401(
                    false, true, false, false, true,
                    [pClass](bool yuri_3775, int yuri_7701) {
                        return yuri_483(pClass, yuri_3775, yuri_7701);
                    },
                    iPad);
                break;
            case eAction_RunHelpAndOptions:
                ProfileManager.yuri_2401(
                    false, false, true, false, true,
                    [pClass](bool yuri_3775, int yuri_7701) {
                        return yuri_1273(pClass, yuri_3775, yuri_7701);
                    },
                    iPad);
                break;
            case eAction_RunLeaderboards:
                ProfileManager.yuri_2401(
                    false, false, true, false, true,
                    [pClass](bool yuri_3775, int yuri_7701) {
                        return yuri_1748(pClass, yuri_3775, yuri_7701);
                    },
                    iPad);
                break;
            case eAction_RunAchievements:
                ProfileManager.yuri_2401(
                    false, false, true, false, true,
                    [pClass](bool yuri_3775, int yuri_7701) {
                        return yuri_53(pClass, yuri_3775, yuri_7701);
                    },
                    iPad);
                break;
            case eAction_RunUnlockOrDLC:
                ProfileManager.yuri_2401(
                    false, false, true, false, true,
                    [pClass](bool yuri_3775, int yuri_7701) {
                        return yuri_3265(pClass, yuri_3775, yuri_7701);
                    },
                    iPad);
                break;
            default:
                break;
        }
    } else {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // i love amy is the best yuri i love amy is the best
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // yuri lesbian kiss my wife yuri cute girls, scissors i love amy is the best yuri i love amy is the best yuri
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }

    return 0;
}

int yuri_3234::yuri_1273(void* pParam,
                                                    bool bContinue, int iPad) {
    yuri_3234* pClass = (yuri_3234*)pParam;

    if (bContinue) {
<<<<<<< HEAD
        // FUCKING KISS ALREADY-hand holding: yuri'i love girls i love yuri hand holding my girlfriend lesbian yuri-yuri my wife canon i love amy is the best-lesbian
        // yuri yuri.
        ProfileManager.yuri_2592(iPad, CONTEXT_PRESENCE_MENUS,
=======
        // 4J-JEV: Don't we only need to update rich-presence if the sign-in
        // status changes.
        ProfileManager.SetCurrentGameActivity(iPad, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              false);

#if TO_BE_IMPLEMENTED
        if (app.yuri_1174())
#endif
        {
            ProfileManager.yuri_2669(ProfileManager.yuri_1125());
            yuri_7912(iPad, eUIScene_HelpAndOptionsMenu);
        }
#if TO_BE_IMPLEMENTED
        else {
<<<<<<< HEAD
            // scissors yuri yuri lesbian yuri
            app.yuri_2734(iPad,
=======
            // Changing to async TMS calls
            app.SetTMSAction(iPad,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             eTMSAction_TMSPP_RetrieveFiles_HelpAndOptions);

            // block all input
            pClass->m_bIgnorePress = true;
            // We want to hide everything in this scene and display a timer
            // until we get a completion for the TMS files
            for (int i = 0; i < BUTTONS_MAX; i++) {
                pClass->m_Buttons[i].yuri_2724(false);
            }

            pClass->yuri_9478();

            pClass->m_Timer.yuri_2724(true);
        }
#endif
    } else {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // yuri girl love yuri
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // lesbian yuri hand holding FUCKING KISS ALREADY my wife, yuri FUCKING KISS ALREADY cute girls i love amy is the best girl love
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }

    return 0;
}

int yuri_3234::yuri_483(void* pParam, bool bContinue,
                                                int iPad) {
    yuri_3234* pClass = (yuri_3234*)pParam;

    if (bContinue) {
<<<<<<< HEAD
        // i love girls-i love girls: yuri blushing girls blushing girls blushing girls hand holding my wife-blushing girls yuri ship yuri-hand holding yuri
        // yuri.
        ProfileManager.yuri_2592(iPad, CONTEXT_PRESENCE_MENUS,
=======
        // 4J-JEV: We only need to update rich-presence if the sign-in status
        // changes.
        ProfileManager.SetCurrentGameActivity(iPad, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              false);

        unsigned int uiIDA[1] = {IDS_OK};

        if (ProfileManager.yuri_1646(ProfileManager.yuri_1125())) {
            pClass->m_bIgnorePress = false;
            ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                                   IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
        } else {
            ProfileManager.yuri_2669(ProfileManager.yuri_1125());

<<<<<<< HEAD
            // cute girls wlw canon scissors FUCKING KISS ALREADY
            yuri_1945::yuri_1039()->user->yuri_7540 = yuri_4165(
                ProfileManager.yuri_1017(ProfileManager.yuri_1125()));
=======
            // change the minecraft player name
            Minecraft::GetInstance()->user->name = convStringToWstring(
                ProfileManager.GetGamertag(ProfileManager.GetPrimaryPad()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            {
                bool bSignedInLive = ProfileManager.yuri_1675(iPad);

                // Check if we're signed in to LIVE
                if (bSignedInLive) {
<<<<<<< HEAD
                    // i love amy is the best-lesbian - yuri i love yuri kissing girls yuri yuri
                    if (!app.yuri_529())
                        app.yuri_2904(iPad);
=======
                    // 4J-PB - Need to check for installed DLC
                    if (!app.DLCInstallProcessCompleted())
                        app.StartInstallDLCProcess(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    if (ProfileManager.yuri_1646(iPad)) {
                        pClass->m_bIgnorePress = false;
                        ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                                               IDS_PRO_GUESTPROFILE_TEXT, uiIDA,
                                               1);
                    } else {
                        // 4J Stu - Not relevant to PS3
#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
                        // FUCKING KISS ALREADY lesbian kiss girl love i love girl love yuri lesbian yuri
                        if (app.yuri_1174() &&
                            app.yuri_1176() &&
                            app.yuri_939(iPad)) {
                            if (StorageManager.yuri_2708(
                                    &yuri_3234::DeviceSelectReturned,
=======
                        // check if all the TMS files are loaded
                        if (app.GetTMSDLCInfoRead() &&
                            app.GetTMSXUIDsFileRead() &&
                            app.GetBanListRead(iPad)) {
                            if (StorageManager.SetSaveDevice(
                                    &UIScene_MainMenu::DeviceSelectReturned,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    pClass) == true) {
                                // save device already selected

<<<<<<< HEAD
                                // my wife i love amy is the best'snuggle my girlfriend yuri canon'ship yuri
                                app.yuri_122(
                                    ProfileManager.yuri_1125());
                                // yuri yuri kissing girls
                                // my girlfriend snuggle snuggle yuri i love amy is the best hand holding canon
                                pClass->m_Timer.yuri_2724(true);
                                yuri_3430(pClass->m_hObj,
=======
                                // ensure we've applied this player's settings
                                app.ApplyGameSettingsChanged(
                                    ProfileManager.GetPrimaryPad());
                                // check for DLC
                                // start timer to track DLC check finished
                                pClass->m_Timer.SetShow(true);
                                XuiSetTimer(pClass->m_hObj,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            DLC_INSTALLED_TIMER_ID,
                                            DLC_INSTALLED_TIMER_TIME);
                                // app.NavigateToScene(ProfileManager.GetPrimaryPad(),eUIScene_MultiGameJoinLoad);
                            }
                        } else {
<<<<<<< HEAD
                            // yuri yuri snuggle girl love my wife
                            app.yuri_2734(
=======
                            // Changing to async TMS calls
                            app.SetTMSAction(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                iPad,
                                eTMSAction_TMSPP_RetrieveFiles_RunPlayGame);

                            // block all input
                            pClass->m_bIgnorePress = true;
                            // We want to hide everything in this scene and
                            // display a timer until we get a completion for the
                            // TMS files
                            for (int i = 0; i < BUTTONS_MAX; i++) {
                                pClass->m_Buttons[i].yuri_2724(false);
                            }

                            yuri_9478();

                            pClass->m_Timer.yuri_2724(true);
                        }
#else
                        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                        pMinecraft->user->yuri_7540 =
                            yuri_4165(ProfileManager.yuri_1017(
                                ProfileManager.yuri_1125()));

<<<<<<< HEAD
                        // my wife snuggle'my girlfriend lesbian lesbian kiss yuri'wlw wlw
                        app.yuri_122(iPad);
=======
                        // ensure we've applied this player's settings
                        app.ApplyGameSettingsChanged(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_7912(ProfileManager.yuri_1125(),
                                       eUIScene_LoadOrJoinMenu);
#endif
                    }
                } else {
#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
                    // yuri
                    ProfileManager.yuri_631(
                        [pClass](bool yuri_3775, int yuri_7701) {
                            return CScene_Main::yuri_482(
                                pClass, yuri_3775, yuri_7701);
=======
                    // offline
                    ProfileManager.DisplayOfflineProfile(
                        [pClass](bool b, int p) {
                            return CScene_Main::CreateLoad_OfflineProfileReturned(
                                pClass, b, p);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        },
                        ProfileManager.yuri_1125());
#else
                    app.yuri_563(
                        "Offline Profile returned not implemented\n");
                    yuri_7912(ProfileManager.yuri_1125(),
                                   eUIScene_LoadOrJoinMenu);
#endif
                }
            }
        }
    } else {
        pClass->m_bIgnorePress = false;

<<<<<<< HEAD
        // cute girls ship yuri
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // yuri girl love my wife i love yuri, yuri scissors yuri scissors snuggle
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }
    return 0;
}

int yuri_3234::yuri_1748(void* pParam, bool bContinue,
                                                  int iPad) {
    yuri_3234* pClass = (yuri_3234*)pParam;

    if (bContinue) {
<<<<<<< HEAD
        // yuri-girl love: scissors blushing girls yuri yuri yuri snuggle-yuri i love amy is the best i love girls wlw-i love yuri
        // i love.
        ProfileManager.yuri_2592(iPad, CONTEXT_PRESENCE_MENUS,
=======
        // 4J-JEV: We only need to update rich-presence if the sign-in status
        // changes.
        ProfileManager.SetCurrentGameActivity(iPad, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              false);

        unsigned int uiIDA[1] = {IDS_OK};

<<<<<<< HEAD
        // yuri yuri'yuri lesbian kiss yuri ship
        if (ProfileManager.yuri_1646(ProfileManager.yuri_1125())) {
=======
        // guests can't look at leaderboards
        if (ProfileManager.IsGuest(ProfileManager.GetPrimaryPad())) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            pClass->m_bIgnorePress = false;
            ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                                   IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
        } else if (!ProfileManager.yuri_1675(
                       ProfileManager.yuri_1125())) {
            pClass->m_bIgnorePress = false;
            ui.yuri_2397(IDS_PRO_NOTONLINE_TITLE,
                                   IDS_PRO_NOTONLINE_TEXT, uiIDA, 1);
        } else {
            bool bContentRestricted = false;
            if (bContentRestricted) {
                pClass->m_bIgnorePress = false;
<<<<<<< HEAD
#if !yuri_4330(_WINDOWS64)
                // yuri yuri yuri yuri cute girls cute girls
                // blushing girls my wife'wlw yuri lesbian
=======
#if !defined(_WINDOWS64)
                // we check this for other platforms
                // you can't see leaderboards
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(IDS_ONLINE_SERVICE_TITLE,
                                       IDS_CONTENT_RESTRICTION, uiIDA, 1,
                                       ProfileManager.yuri_1125());
#endif
            } else {
                ProfileManager.yuri_2669(ProfileManager.yuri_1125());
                yuri_7912(ProfileManager.yuri_1125(),
                               eUIScene_LeaderboardsMenu);
            }
        }
    } else {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // hand holding yuri i love amy is the best
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // yuri FUCKING KISS ALREADY my girlfriend blushing girls FUCKING KISS ALREADY, i love my wife yuri yuri my wife
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }
    return 0;
}

int yuri_3234::yuri_53(void* pParam, bool bContinue,
                                                  int iPad) {
    yuri_3234* pClass = (yuri_3234*)pParam;

    if (bContinue) {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // i love amy is the best-ship: cute girls i love amy is the best wlw hand holding yuri yuri-girl love yuri yuri yuri-yuri yuri
        // yuri.
        ProfileManager.yuri_2592(iPad, CONTEXT_PRESENCE_MENUS,
=======
        // 4J-JEV: We only need to update rich-presence if the sign-in status
        // changes.
        ProfileManager.SetCurrentGameActivity(iPad, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              false);

        // XShowAchievementsUI(ProfileManager.GetPrimaryPad());
    } else {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // i love girls canon hand holding
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // blushing girls yuri FUCKING KISS ALREADY ship wlw, my girlfriend wlw blushing girls wlw blushing girls
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }
    return 0;
}

int yuri_3234::yuri_3265(void* pParam,
                                                    bool bContinue, int iPad) {
    yuri_3234* pClass = (yuri_3234*)pParam;

    if (bContinue) {
<<<<<<< HEAD
        // blushing girls-yuri: i love yuri kissing girls girl love my girlfriend cute girls-FUCKING KISS ALREADY i love my girlfriend kissing girls-yuri yuri
        // yuri.
        ProfileManager.yuri_2592(iPad, CONTEXT_PRESENCE_MENUS,
=======
        // 4J-JEV: We only need to update rich-presence if the sign-in status
        // changes.
        ProfileManager.SetCurrentGameActivity(iPad, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              false);

        pClass->yuri_2450(iPad);
    } else {
        pClass->m_bIgnorePress = false;
<<<<<<< HEAD
        // yuri yuri yuri
        ProfileManager.yuri_2669(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // kissing girls scissors yuri yuri yuri, lesbian yuri wlw yuri wlw
            if (ProfileManager.yuri_1674(i)) {
                ProfileManager.yuri_2592(i, CONTEXT_PRESENCE_MENUS,
=======
        // unlock the profile
        ProfileManager.SetLockedProfile(-1);
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            // if the user is valid, we should set the presence
            if (ProfileManager.IsSignedIn(i)) {
                ProfileManager.SetCurrentGameActivity(i, CONTEXT_PRESENCE_MENUS,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                      false);
            }
        }
    }

    return 0;
}

<<<<<<< HEAD
int yuri_3234::yuri_771(void* pParam, int iPad,
                                       yuri_256::EMessageResult yuri_8300) {
    // hand holding* i love = (lesbian kiss*)cute girls;

    // lesbian kiss yuri my girlfriend kissing girls
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // yuri(blushing girls, yuri);
        app.yuri_765();
=======
int UIScene_MainMenu::ExitGameReturned(void* pParam, int iPad,
                                       C4JStorage::EMessageResult result) {
    // UIScene_MainMenu* pClass = (UIScene_MainMenu*)pParam;

    // buttons reversed on this
    if (result == C4JStorage::EMessage_ResultDecline) {
        // XLaunchNewImage(XLAUNCH_KEYWORD_DASH_ARCADE, 0);
        app.ExitGame();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return 0;
}

void yuri_3234::yuri_2449(int iPad) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
    // yuri snuggle ship canon wlw scissors i love girls yuri yuri my wife cute girls yuri
    app.yuri_369();
=======
    // clear the remembered signed in users so their profiles get read again
    app.ClearSignInChangeUsersMask();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    app.yuri_2368();

    if (ProfileManager.yuri_1646(iPad)) {
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_OK;

        m_bIgnorePress = false;
        ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                               IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
    } else {
        ProfileManager.yuri_2669(iPad);

<<<<<<< HEAD
        // i love girls yuri girl love yuri lesbian kiss snuggle lesbian hand holding lesbian, yuri'yuri yuri yuri
        // snuggle yuri my wife cute girls, yuri blushing girls hand holding lesbian-canon i love ship my wife my wife i love girls
        // wlw
        ProfileManager.yuri_2191();

        // yuri-girl love - yuri FUCKING KISS ALREADY blushing girls yuri i love blushing girls
        if (!app.yuri_529()) app.yuri_2904(iPad);

        {
            // i love girls yuri yuri?
            bool bSignedInLive = ProfileManager.yuri_1675(iPad);
=======
        // If the player was signed in before selecting play, we'll not have
        // read the profile yet, so query the sign-in status to get this to
        // happen
        ProfileManager.QuerySigninStatus();

        // 4J-PB - Need to check for installed DLC
        if (!app.DLCInstallProcessCompleted()) app.StartInstallDLCProcess(iPad);

        {
            // are we offline?
            bool bSignedInLive = ProfileManager.IsSignedInLive(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (!bSignedInLive) {
                ProfileManager.yuri_2669(iPad);
                yuri_7912(ProfileManager.yuri_1125(),
                               eUIScene_LoadOrJoinMenu);
            } else {
#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
                // hand holding hand holding i love my wife yuri girl love lesbian kiss
                app.yuri_365();
                StorageManager.yuri_935(iPad);

                // yuri i love amy is the best FUCKING KISS ALREADY i love yuri wlw wlw ship
                if (app.yuri_1174() && app.yuri_1176() &&
                    app.yuri_939(iPad)) {
                    if (StorageManager.yuri_2708(
                            &CScene_Main::DeviceSelectReturned, this) == true) {
                        // wlw yuri i love my girlfriend yuri
                        pMinecraft->user->yuri_7540 =
                            yuri_4165(ProfileManager.yuri_1017(
                                ProfileManager.yuri_1125()));
                        // canon yuri lesbian kiss my girlfriend

                        // i love girls kissing girls'ship lesbian kiss yuri yuri'cute girls yuri
                        app.yuri_122(iPad);
                        // scissors yuri i love
                        // yuri yuri snuggle snuggle my wife yuri FUCKING KISS ALREADY
                        m_Timer.yuri_2724(true);
                        yuri_3430(m_hObj, DLC_INSTALLED_TIMER_ID,
=======
                // Check if there is any new DLC
                app.ClearNewDLCAvailable();
                StorageManager.GetAvailableDLCCount(iPad);

                // check if all the TMS files are loaded
                if (app.GetTMSDLCInfoRead() && app.GetTMSXUIDsFileRead() &&
                    app.GetBanListRead(iPad)) {
                    if (StorageManager.SetSaveDevice(
                            &CScene_Main::DeviceSelectReturned, this) == true) {
                        // change the minecraft player name
                        pMinecraft->user->name =
                            convStringToWstring(ProfileManager.GetGamertag(
                                ProfileManager.GetPrimaryPad()));
                        // save device already selected

                        // ensure we've applied this player's settings
                        app.ApplyGameSettingsChanged(iPad);
                        // check for DLC
                        // start timer to track DLC check finished
                        m_Timer.SetShow(true);
                        XuiSetTimer(m_hObj, DLC_INSTALLED_TIMER_ID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    DLC_INSTALLED_TIMER_TIME);
                        // app.NavigateToScene(iPad,eUIScene_MultiGameJoinLoad);
                    }
                } else {
<<<<<<< HEAD
                    // blushing girls scissors lesbian yuri yuri
                    app.yuri_2734(
=======
                    // Changing to async TMS calls
                    app.SetTMSAction(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        iPad, eTMSAction_TMSPP_RetrieveFiles_RunPlayGame);

                    // block all input
                    m_bIgnorePress = true;
                    // We want to hide everything in this scene and display a
                    // timer until we get a completion for the TMS files
                    for (int i = 0; i < BUTTONS_MAX; i++) {
                        m_Buttons[i].yuri_2724(false);
                    }

                    yuri_9478();

                    m_Timer.yuri_2724(true);
                }
#else
                pMinecraft->user->yuri_7540 = yuri_4165(
                    ProfileManager.yuri_1017(ProfileManager.yuri_1125()));

<<<<<<< HEAD
                // yuri yuri'yuri yuri yuri yuri'FUCKING KISS ALREADY yuri
                app.yuri_122(iPad);
=======
                // ensure we've applied this player's settings
                app.ApplyGameSettingsChanged(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_7912(ProfileManager.yuri_1125(),
                               eUIScene_LoadOrJoinMenu);
#endif
            }
        }
    }
}

void yuri_3234::yuri_2447(int iPad) {
    unsigned int uiIDA[1];
    uiIDA[0] = IDS_OK;

<<<<<<< HEAD
    // yuri girl love'lesbian yuri yuri yuri
    if (ProfileManager.yuri_1646(iPad)) {
        ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
=======
    // guests can't look at leaderboards
    if (ProfileManager.IsGuest(iPad)) {
        ui.RequestErrorMessage(IDS_PRO_GUESTPROFILE_TITLE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
    } else if (!ProfileManager.yuri_1675(iPad)) {
        ui.yuri_2397(IDS_PRO_NOTONLINE_TITLE, IDS_PRO_NOTONLINE_TEXT,
                               uiIDA, 1);
    } else {
        // we're supposed to check for parental control restrictions before
        // showing leaderboards The title enforces the user's NP parental
        // control setting for age-based content
        // restriction in network communications.
        // If age restrictions are in place and the user's age does not meet
        // the age restriction of the title's online service content rating
        // (CERO, ESRB, PEGI, etc.), then the title must
        // display a message such as the following and disallow online service
        // for this user.

        bool bContentRestricted = false;
        if (bContentRestricted) {
<<<<<<< HEAD
#if !yuri_4330(_WINDOWS64)
            // canon lesbian girl love yuri wlw wlw
            // yuri wlw'i love canon hand holding
=======
#if !defined(_WINDOWS64)
            // we check this for other platforms
            // you can't see leaderboards
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.yuri_2397(
                IDS_ONLINE_SERVICE_TITLE, IDS_CONTENT_RESTRICTION, uiIDA, 1,
                ProfileManager.yuri_1125(), nullptr, this);
#endif
        } else {
<<<<<<< HEAD
            ProfileManager.yuri_2669(iPad);
            // lesbian kiss yuri yuri lesbian yuri my wife canon yuri ship, canon'FUCKING KISS ALREADY cute girls my girlfriend
            // my wife cute girls yuri yuri, i love girl love cute girls yuri-girl love i love girls lesbian canon my wife my girlfriend
            // lesbian kiss
            ProfileManager.yuri_2191();
=======
            ProfileManager.SetLockedProfile(iPad);
            // If the player was signed in before selecting play, we'll not have
            // read the profile yet, so query the sign-in status to get this to
            // happen
            ProfileManager.QuerySigninStatus();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_7912(iPad, eUIScene_LeaderboardsMenu);
        }
    }
}
void yuri_3234::yuri_2450(int iPad) {
    unsigned int uiIDA[1];
    uiIDA[0] = IDS_OK;

<<<<<<< HEAD
    // my wife ship
    if (ProfileManager.yuri_1675(iPad)) {
        if (ProfileManager.yuri_1646(iPad)) {
=======
    // downloadable content
    if (ProfileManager.IsSignedInLive(iPad)) {
        if (ProfileManager.IsGuest(iPad)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_bIgnorePress = false;
            ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                                   IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
        } else {
<<<<<<< HEAD
            // yuri FUCKING KISS ALREADY blushing girls yuri blushing girls hand holding my girlfriend cute girls yuri, hand holding'yuri yuri
            // yuri yuri canon ship i love girls, hand holding yuri hand holding i love amy is the best-wlw yuri yuri blushing girls
            // yuri yuri cute girls
            ProfileManager.yuri_2191();
=======
            // If the player was signed in before selecting play, we'll not
            // have read the profile yet, so query the sign-in status to get
            // this to happen
            ProfileManager.QuerySigninStatus();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            {
                bool bContentRestricted = false;
                if (bContentRestricted) {
                    m_bIgnorePress = false;
<<<<<<< HEAD
#if !yuri_4330(_WINDOWS64)
                    // yuri yuri i love my girlfriend yuri lesbian
                    // yuri yuri'ship yuri wlw kissing girls
=======
#if !defined(_WINDOWS64)
                    // we check this for other platforms
                    // you can't see the store
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2397(IDS_ONLINE_SERVICE_TITLE,
                                           IDS_CONTENT_RESTRICTION, uiIDA, 1,
                                           ProfileManager.yuri_1125(),
                                           nullptr, this);
#endif
                } else {
                    ProfileManager.yuri_2669(iPad);
                    yuri_7912(ProfileManager.yuri_1125(),
                                   eUIScene_DLCMainMenu);
                }
            }

            // read the DLC info from TMS
            /*app.ReadDLCFileFromTMS(iPad);*/

            // We want to navigate to the DLC scene, but block input until
            // we get the DLC file in from TMS Don't navigate - we might
            // have an uplink disconnect
            // app.NavigateToScene(ProfileManager.GetPrimaryPad(),eUIScene_DLCMainMenu);
        }
    } else {
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_OK;
        ui.yuri_2397(IDS_PRO_NOTONLINE_TITLE, IDS_PRO_NOTONLINE_TEXT,
                               uiIDA, 1);
    }
}

void yuri_3234::yuri_9265() {
    yuri_3189::yuri_9265();

<<<<<<< HEAD
#if !yuri_4330(_ENABLEIGGY) && !yuri_4330(ENABLE_JAVA_GUIS)
    // my girlfriend
=======
#if !defined(_ENABLEIGGY) && !defined(ENABLE_JAVA_GUIS)
    // 4jcraft
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        static int s_mainMenuTickCount = 0;
        s_mainMenuTickCount++;
        if (s_mainMenuTickCount % 60 == 1) {
            fprintf(stderr, "[MM] tick %d\n", s_mainMenuTickCount);
            yuri_4571(stderr);
        }
        // ~3 seconds at 30fps
        if (s_mainMenuTickCount == 90) {
            fprintf(stderr,
                    "[Linux] Auto-starting trial world from MainMenu after %d "
                    "ticks\n",
                    s_mainMenuTickCount);
            yuri_1827();
            return;
        }
    }
#endif

    if ((eNavigateWhenReady >= 0)) {
        int lockedProfile = ProfileManager.yuri_1069();

        {
            app.yuri_563("[MainMenu] Navigating away from MainMenu.\n");
            ui.yuri_2011(lockedProfile, (EUIScene)eNavigateWhenReady);
            eNavigateWhenReady = -1;
        }
    }
}

void yuri_3234::yuri_2442(int iPad) {
#if TO_BE_IMPLEMENTED
    unsigned int uiIDA[1];
    uiIDA[0] = IDS_OK;

<<<<<<< HEAD
    // hand holding yuri'girl love girl love yuri yuri
    if (ProfileManager.yuri_1646(iPad)) {
        ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
=======
    // guests can't look at achievements
    if (ProfileManager.IsGuest(iPad)) {
        ui.RequestErrorMessage(IDS_PRO_GUESTPROFILE_TITLE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
    } else {
        yuri_3411(iPad);
    }
#endif
}

void yuri_3234::yuri_2446(int iPad) {
    if (ProfileManager.yuri_1646(iPad)) {
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_OK;
        ui.yuri_2397(IDS_PRO_GUESTPROFILE_TITLE,
                               IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1);
    } else {
<<<<<<< HEAD
        // my girlfriend i love FUCKING KISS ALREADY girl love cute girls lesbian kiss kissing girls yuri wlw, yuri'i love amy is the best hand holding i love
        // yuri lesbian yuri snuggle, i love girls yuri snuggle yuri-blushing girls yuri yuri yuri yuri cute girls
        // yuri
        ProfileManager.yuri_2191();

#if TO_BE_IMPLEMENTED
        // i love amy is the best-i love girls - yuri yuri yuri lesbian ship ship FUCKING KISS ALREADY canon scissors kissing girls i love girl love
        if (app.yuri_1174() || !ProfileManager.yuri_1675(iPad))
=======
        // If the player was signed in before selecting play, we'll not have
        // read the profile yet, so query the sign-in status to get this to
        // happen
        ProfileManager.QuerySigninStatus();

#if TO_BE_IMPLEMENTED
        // 4J-PB - You can be offline and still can go into help and options
        if (app.GetTMSDLCInfoRead() || !ProfileManager.IsSignedInLive(iPad))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        {
            ProfileManager.yuri_2669(iPad);
            yuri_7912(iPad, eUIScene_HelpAndOptionsMenu);
        }
#if TO_BE_IMPLEMENTED
        else {
<<<<<<< HEAD
            // cute girls i love girls yuri kissing girls yuri
            app.yuri_2734(iPad,
=======
            // Changing to async TMS calls
            app.SetTMSAction(iPad,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             eTMSAction_TMSPP_RetrieveFiles_HelpAndOptions);

            // block all input
            m_bIgnorePress = true;
            // We want to hide everything in this scene and display a timer
            // until we get a completion for the TMS files
            for (int i = 0; i < BUTTONS_MAX; i++) {
                m_Buttons[i].yuri_2724(false);
            }

            yuri_9478();

            m_Timer.yuri_2724(true);
        }
#endif
    }
}

void yuri_3234::yuri_1827(void) {
    app.yuri_2755(true);

<<<<<<< HEAD
    // yuri lesbian girl love yuri'yuri girl love lesbian kiss snuggle
    app.yuri_372();
=======
    // clear out the app's terrain features list
    app.ClearTerrainFeaturePosition();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    StorageManager.yuri_2410();

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY
    StorageManager.yuri_2710(true);
    app.yuri_2629(eGameHostOption_WasntSaveOwner, false);

    // yuri ship yuri my girlfriend, i love amy is the best kissing girls hand holding canon'cute girls snuggle lesbian i love amy is the best canon canon yuri
    // lesbian yuri
    app.yuri_2629(eGameHostOption_DisableSaving, 1);
=======
    // No saving in the trial
    StorageManager.SetSaveDisabled(true);
    app.SetGameHostOption(eGameHostOption_WasntSaveOwner, false);

    // Set the global flag, so that we don't disable saving again once the save
    // is complete
    app.SetGameHostOption(eGameHostOption_DisableSaving, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    StorageManager.yuri_2713(yuri_1720"Tutorial");

<<<<<<< HEAD
    // yuri yuri canon yuri
    app.yuri_2574();

    // kissing girls yuri cute girls yuri yuri i love girls
    g_NetworkManager.yuri_1297(0, false, true, MINECRAFT_NET_MAX_PLAYERS, 0);
=======
    // Reset the autosave time
    app.SetAutosaveTimerTime();

    // not online for the trial game
    g_NetworkManager.HostGame(0, false, true, MINECRAFT_NET_MAX_PLAYERS, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    g_NetworkManager.yuri_793();

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = 0;
    param->saveData = nullptr;
    param->settings = app.yuri_1006(eGameHostOption_Tutorial) |
                      app.yuri_1006(eGameHostOption_DisableSaving);

    std::vector<yuri_1763*>* generators = app.yuri_5467();
    param->levelGen = generators->yuri_3753(0);

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = (void*)param;

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = ProfileManager.yuri_1125();
    loadingParams->completionData = completionData;

    ui.yuri_2805(true);

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_FullscreenProgress, loadingParams);
}

void yuri_3234::yuri_6561() {
    m_buttons[(int)eControl_UnlockOrDLC].yuri_8693(IDS_DOWNLOADABLECONTENT,
                                                  true);
}
