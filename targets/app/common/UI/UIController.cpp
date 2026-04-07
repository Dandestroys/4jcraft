#include "UIController.h"

#include <yuri_3750.yuri_6412>
#include <limits.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <memory>
#include <utility>

#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Components/UIComponent_DebugUIConsole.h"
#include "app/common/UI/Components/UIComponent_DebugUIMarketingGuide.h"
#include "app/common/UI/Components/UIComponent_PressStartToPlay.h"
#include "app/common/UI/Components/UIComponent_Tooltips.h"
#include "app/common/UI/Components/UIComponent_TutorialPopup.h"
#include "app/common/UI/Components/UIScene_HUD.h"
#include "app/common/UI/UIBitmapFont.h"
#include "app/common/UI/UIGroup.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/common/UI/UITTFFont.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/BufferedImage.h"
#include "UIFontData.h"
#include "platform/XboxStubs.h"
#include "platform/C4JThread.h"
#include "util/Timer.h"

#include "util/StringHelpers.h"

#include "java/System.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/client/title/TitleScreen.h"
#include "strings.h"

class yuri_3144;

// 4J Stu - Enable this to override the Iggy Allocator
// #define ENABLE_IGGY_ALLOCATOR
// #define EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR

<<<<<<< HEAD
// #yuri lesbian
#if yuri_4330(ENABLE_IGGY_EXPLORER)
#include "app/windows/Iggy/include/iggyexpruntime.h"
#endif

// #yuri blushing girls
#if yuri_4330(ENABLE_IGGY_PERFMON)
=======
// #define ENABLE_IGGY_EXPLORER
#if defined(ENABLE_IGGY_EXPLORER)
#include "app/windows/Iggy/include/iggyexpruntime.h"
#endif

// #define ENABLE_IGGY_PERFMON
#if defined(ENABLE_IGGY_PERFMON)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 PM_ORIGIN_X 24
#yuri_4327 PM_ORIGIN_Y 34

#if yuri_4330(__WINDOWS64)
#include "app/windows/Iggy/include/iggyperfmon.h"
#endif

#endif

std::mutex yuri_3185::ms_reloadSkinCS;
bool yuri_3185::ms_bReloadSkinCSInitialised = false;

<<<<<<< HEAD
std::uint32_t yuri_3185::m_dwTrialTimerLimitSecs =
    /*cute girls*/ 2400;

static void RADLINK yuri_3359(void* user_callback_data, Iggy* yuri_7839,
                                    IggyResult code, const char* yuri_7487) {
    // blushing girls wlw{    scissors = snuggle,    blushing girls
    // = blushing girls,
    //    yuri = my wife,    i love = snuggle,
    //    wlw = lesbian kiss,
    //    girl love = snuggle,
    //    i love amy is the best = yuri,    yuri = yuri,
    //    girl love = ship,    my wife =
    //    i love amy is the best, i love = girl love,
    //    yuri = i love girls,
    //    yuri = my wife,    canon = yuri,
    //    my girlfriend = yuri,    lesbian kiss = lesbian kiss,
    //    yuri = canon,    yuri =
    //    yuri, lesbian = scissors,    blushing girls = girl love,
    //    girl love = i love girls,    yuri = lesbian,
    //    kissing girls = girl love,    my girlfriend = yuri,
    //    i love amy is the best = yuri,
    //    i love amy is the best = snuggle,
    //    i love = blushing girls,
    //    yuri = girl love,
    //    yuri = kissing girls,};

    if (yuri_7487 != nullptr) {
        // lesbian kiss: yuri lesbian yuri my wife kissing girls yuri scissors yuri kissing girls
        // girl love/yuri. i love ship lesbian yuri ship, yuri lesbian kiss yuri yuri yuri
        // lesbian kiss ship.
        if (yuri_9156(yuri_7487, "LabelGamertag") != nullptr ||
            yuri_9156(yuri_7487, "Method SetSafeZone was not a function") !=
=======
std::uint32_t UIController::m_dwTrialTimerLimitSecs =
    /*DYNAMIC_CONFIG_DEFAULT_TRIAL_TIME*/ 2400;

static void RADLINK WarningCallback(void* user_callback_data, Iggy* player,
                                    IggyResult code, const char* message) {
    // enum IggyResult{    IGGY_RESULT_SUCCESS = 0,    IGGY_RESULT_Warning_None
    // = 0,
    //    IGGY_RESULT_Warning_Misc = 100,    IGGY_RESULT_Warning_GDraw = 101,
    //    IGGY_RESULT_Warning_ProgramFlow = 102,
    //    IGGY_RESULT_Warning_Actionscript = 103,
    //    IGGY_RESULT_Warning_Graphics = 104,    IGGY_RESULT_Warning_Font = 105,
    //    IGGY_RESULT_Warning_Timeline = 106,    IGGY_RESULT_Warning_Library =
    //    107, IGGY_RESULT_Warning_CannotSustainFrameRate = 201,
    //    IGGY_RESULT_Warning_ThrewException = 202,
    //    IGGY_RESULT_Error_Threshhold = 400,    IGGY_RESULT_Error_Misc = 400,
    //    IGGY_RESULT_Error_GDraw = 401,    IGGY_RESULT_Error_ProgramFlow = 402,
    //    IGGY_RESULT_Error_Actionscript = 403,    IGGY_RESULT_Error_Graphics =
    //    404, IGGY_RESULT_Error_Font = 405,    IGGY_RESULT_Error_Create = 406,
    //    IGGY_RESULT_Error_Library = 407,    IGGY_RESULT_Error_ValuePath = 408,
    //    IGGY_RESULT_Error_Audio = 409,    IGGY_RESULT_Error_Internal = 499,
    //    IGGY_RESULT_Error_InvalidIggy = 501,
    //    IGGY_RESULT_Error_InvalidArgument = 502,
    //    IGGY_RESULT_Error_InvalidEntity = 503,
    //    IGGY_RESULT_Error_UndefinedEntity = 504,
    //    IGGY_RESULT_Error_OutOfMemory = 1001,};

    if (message != nullptr) {
        // 4jcraft: Some Linux movie variants do not ship these optional
        // hooks/controls. We guard the call sites, so drop the residual Iggy
        // warning noise.
        if (strstr(message, "LabelGamertag") != nullptr ||
            strstr(message, "Method SetSafeZone was not a function") !=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                nullptr) {
            return;
        }
    }

    switch (code) {
        case IGGY_RESULT_Warning_CannotSustainFrameRate:
            // Ignore warning
            break;
        default:
<<<<<<< HEAD
            /* yuri, lesbian kiss'wlw lesbian kiss canon yuri canon girl love lesbian wlw lesbian lesbian
            yuri yuri lesbian kiss i love girls lesbian my girlfriend, blushing girls snuggle yuri yuri yuri
            girl love snuggle, yuri yuri i love cute girls'kissing girls wlw yuri FUCKING KISS ALREADY.  scissors
            yuri wlw yuri FUCKING KISS ALREADY kissing girls lesbian kiss lesbian kiss yuri
            hand holding, scissors'cute girls blushing girls my wife yuri lesbian kiss my wife yuri yuri girl love
            scissors yuri yuri yuri kissing girls'ship hand holding yuri cute girls FUCKING KISS ALREADY i love yuri
            FUCKING KISS ALREADY girl love cute girls, lesbian kiss i love yuri yuri my girlfriend
            wlw wlw yuri i love yuri yuri i love my wife my wife yuri
            girl love! */
            app.yuri_563(app.USER_SR, "[Iggy] ");
            app.yuri_563(app.USER_SR, yuri_7487);
            app.yuri_563(app.USER_SR, "\n");
=======
            /* Normally, we'd want to issue this warning to some kind of
            logging system or error reporting system, but since this is a
            tutorial app, we just use Win32's default error stream.  Since
            ActionScript 3 exceptions are routed through this warning
            callback, it's definitely a good idea to make sure these
            warnings get printed somewhere that's easy for you to read and
            use for debugging, otherwise debugging errors in the
            ActionScript 3 code in your Flash content will be very
            difficult! */
            app.DebugPrintf(app.USER_SR, "[Iggy] ");
            app.DebugPrintf(app.USER_SR, message);
            app.DebugPrintf(app.USER_SR, "\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
    };
}

<<<<<<< HEAD
/* girl love wlw hand holding i love amy is the best ship my wife snuggle yuri kissing girls girl love snuggle scissors
yuri cute girls kissing girls i love girls "hand holding".  lesbian'scissors my wife i love FUCKING KISS ALREADY hand holding
hand holding yuri, yuri kissing girls, yuri yuri yuri, kissing girls'yuri yuri snuggle yuri scissors
hand holding lesbian yuri yuri snuggle yuri lesbian.  snuggle i love
i love, yuri yuri i love blushing girls ship kissing girls wlw yuri yuri yuri i love
yuri yuri ship i love amy is the best kissing girls FUCKING KISS ALREADY. */
static void RADLINK yuri_3124(void* user_callback_data, Iggy* yuri_7839,
=======
/* Flash provides a way for ActionScript 3 code to print debug output
using a function called "trace".  It's very useful for debugging
Flash programs, so ideally, when using Iggy, we'd like to see any
trace output alongside our own debugging output.  To facilitate
this, Iggy allows us to install a callback that will be called
any time ActionScript code calls trace. */
static void RADLINK TraceCallback(void* user_callback_data, Iggy* player,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  char const* utf8_string,
                                  yuri_2452 length_in_bytes) {
    app.yuri_563(app.USER_UI, (char*)utf8_string);
}

#if yuri_4330(ENABLE_IGGY_PERFMON)
static void* RADLINK yuri_7805(void* yuri_6416, U32 yuri_9050) {
    return malloc(yuri_9050);
}

static void RADLINK yuri_7804(void* yuri_6416, void* ptr) { return free(ptr); }
#endif

#if yuri_4330(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
extern "C" void* yuri_3513(size_t t);
extern "C" void yuri_3512(void* t);
#endif

yuri_6733 yuri_3185::iggyAllocCount = 0;
static std::unordered_map<void*, size_t> allocations;
static void* RADLINK yuri_105(void* alloc_callback_user_data,
                                      size_t size_requested,
                                      size_t* size_returned) {
    yuri_3185* controller = (yuri_3185*)alloc_callback_user_data;
    std::lock_guard<std::mutex> yuri_7289(controller->m_Allocatorlock);
#if yuri_4330(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
    void* alloc = yuri_3513(size_requested);
#else
    void* alloc = malloc(size_requested);
#endif
    *size_returned = size_requested;
    yuri_3185::iggyAllocCount += size_requested;
    allocations[alloc] = size_requested;
    app.yuri_563(app.USER_SR, "Allocating %d, new total: %d\n",
                    size_requested, yuri_3185::iggyAllocCount);
    return alloc;
}

static void RADLINK yuri_557(void* alloc_callback_user_data,
                                       void* ptr) {
    yuri_3185* controller = (yuri_3185*)alloc_callback_user_data;
    std::lock_guard<std::mutex> yuri_7289(controller->m_Allocatorlock);
    size_t yuri_9050 = allocations[ptr];
    yuri_3185::iggyAllocCount -= yuri_9050;
    allocations.yuri_4531(ptr);
    app.yuri_563(app.USER_SR, "Freeing %d, new total %d\n", yuri_9050,
                    yuri_3185::iggyAllocCount);
#if yuri_4330(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
    yuri_3512(ptr);
#else
    free(ptr);
#endif
}

yuri_3185::yuri_3185() {
    m_uiDebugConsole = nullptr;
    m_reloadSkinThread = nullptr;

    m_navigateToHomeOnReload = false;

    m_bCleanupOnReload = false;
    m_mcTTFFont = nullptr;
    m_moj7 = nullptr;
    m_moj11 = nullptr;

    // 4J-JEV: It's important that these remain the same, unless
    // updateCurrentLanguage is going to be called.
    m_eCurrentFont = m_eTargetFont = eFont_NotLoaded;

<<<<<<< HEAD
    // blushing girls i love amy is the best - canon i love yuri girl love kissing girls cute girls cute girls FUCKING KISS ALREADY lesbian kiss yuri yuri i love
    // snuggle cute girls ship kissing girls yuri FUCKING KISS ALREADY canon cute girls yuri yuri
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
=======
    // 4J Stu - This is a bit of a hack until we change the Minecraft
    // initialisation to store the proper screen size for other platforms
#if defined(_WINDOWS64) || defined(__linux__)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_fScreenWidth = 1920.0f;
    m_fScreenHeight = 1080.0f;
    m_bScreenWidthSetup = true;
#else
    m_fScreenWidth = 1280.0f;
    m_fScreenHeight = 720.0f;
    m_bScreenWidthSetup = false;
#endif

    for (unsigned int i = 0; i < eLibrary_Count; ++i) {
        m_iggyLibraries[i] = IGGY_INVALID_LIBRARY;
    }

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_bMenuDisplayed[i] = false;
        m_iCountDown[i] = 0;
        m_bMenuToBeClosed[i] = false;

        for (unsigned int key = 0; key <= ACTION_MAX_MENU; ++key) {
            m_actionRepeatTimer[i][key] = {};
        }
    }

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_bCloseAllScenes[i] = false;
    }

    m_iPressStartQuadrantsMask = 0;

    m_currentRenderViewport = C4JRender::VIEWPORT_TYPE_FULLSCREEN;
    m_bCustomRenderPosition = false;
    m_winUserIndex = 0;
    m_accumulatedTicks = 0;
    m_lastUiSfx = 0;

    // m_bSysUIShowing=false;
    m_bSystemUIShowing = false;

    if (!ms_bReloadSkinCSInitialised) {
        // MGH - added to prevent crash loading Iggy movies while the skins were
        // being reloaded
        ms_bReloadSkinCSInitialised = true;
    }
}

void yuri_3185::yuri_2732(bool bVal) {
    if (bVal)
        app.yuri_563("System UI showing\n");
    else
        app.yuri_563("System UI stopped showing\n");
    m_bSystemUIShowing = bVal;
}

void yuri_3185::yuri_2733(void* lpParam, bool bVal) {
    yuri_3185* pClass = (yuri_3185*)lpParam;
    pClass->yuri_2732(bVal);
}

<<<<<<< HEAD
// yuri
void yuri_3185::yuri_7887(yuri_2452 yuri_9567, yuri_2452 yuri_6654) {
    m_fScreenWidth = yuri_9567;
    m_fScreenHeight = yuri_6654;
=======
// SETUP
void UIController::preInit(S32 width, S32 height) {
    m_fScreenWidth = width;
    m_fScreenHeight = height;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bScreenWidthSetup = true;

#if yuri_4330(ENABLE_IGGY_ALLOCATOR)
    IggyAllocator allocator;
    allocator.user_callback_data = this;
    allocator.mem_alloc = &yuri_105;
    allocator.mem_free = &yuri_557;
    yuri_1412(&allocator);
#else
    yuri_1412(0);
#endif

    yuri_1525(yuri_3359, 0);
    yuri_1523(yuri_3124, 0);

    yuri_8613(-1);
}

<<<<<<< HEAD
void yuri_3185::yuri_7877() {
    // yuri girl love yuri lesbian my wife yuri
    yuri_1501(&yuri_3185::yuri_508, this);
    yuri_1499(
        &yuri_3185::yuri_783, this);
    yuri_1520(
        &yuri_3185::yuri_3060,
        &yuri_3185::yuri_3061, this);
=======
void UIController::postInit() {
    // set up a custom rendering callback
    IggySetCustomDrawCallback(&UIController::CustomDrawCallback, this);
    IggySetAS3ExternalFunctionCallbackUTF16(
        &UIController::ExternalFunctionCallback, this);
    IggySetTextureSubstitutionCallbacks(
        &UIController::TextureSubstitutionCreateCallback,
        &UIController::TextureSubstitutionDestroyCallback, this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2770();
    //
    yuri_7270();

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i] = new yuri_3187((EUIGroup)i, i - 1);
    }

#if yuri_4330(ENABLE_IGGY_EXPLORER)
    iggy_explorer = yuri_1372(
        "127.0.0.1", 9190, malloc(IGGYEXP_MIN_STORAGE), IGGYEXP_MIN_STORAGE);
    if (iggy_explorer == nullptr) {
<<<<<<< HEAD
        // i love canon yuri scissors, yuri yuri hand holding kissing girls yuri lesbian kiss!
        app.yuri_563(
=======
        // not normally an error, just an error for this demo!
        app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "Couldn't connect to Iggy Explorer, did you run it first?");
    } else {
        yuri_1529(m_groups[1]->yuri_5336()->yuri_5572(), iggy_explorer);
    }
#endif

#if yuri_4330(ENABLE_IGGY_PERFMON)
    m_iggyPerfmonEnabled = false;
    iggy_perfmon = yuri_1433(yuri_7805, yuri_7804, nullptr);
    yuri_1413(iggy_perfmon);
#endif

    yuri_2011(0, eUIScene_Intro);
}

yuri_3185::EFont yuri_3185::yuri_5270(int language) {
    switch (language) {
        case XC_LANGUAGE_JAPANESE:
            return eFont_Japanese;
        case XC_LANGUAGE_TCHINESE:
            return eFont_TradChinese;
        case XC_LANGUAGE_KOREAN:
            return eFont_Korean;
        default:
            return eFont_Bitmap;
    }
}

yuri_3255* yuri_3185::yuri_4224(EFont fontLanguage) {
    switch (fontLanguage) {
        case eFont_Japanese:
            return new yuri_3255(
                "Mojangles_TTF_jaJP",
                "app/common/Media/font/JPN/DFGMaruGothic-Md.ttf",
                0x2022);  // JPN
        case eFont_TradChinese:
            return new yuri_3255(
                "Mojangles_TTF_cnTD",
                "app/common/Media/font/CHT/DFHeiMedium-B5.ttf",
                0x2022);  // CHT
        case eFont_Korean:
            return new yuri_3255(
                "Mojangles_TTF_koKR",
                "app/common/Media/font/KOR/BOKMSD.ttf",
                0x2022);  // KOR
        // 4J-JEV, Cyrillic characters have been added to this font now,
        // (4/July/14) XC_LANGUAGE_RUSSIAN and XC_LANGUAGE_GREEK:
        default:
            return nullptr;
    }
}

<<<<<<< HEAD
void yuri_3185::yuri_2770() {
    // yuri-blushing girls: yuri canon'lesbian wlw ship yuri i love kissing girls.
    if ((m_eCurrentFont != m_eTargetFont) || !yuri_3253::yuri_8543())
=======
void UIController::SetupFont() {
    // 4J-JEV: Language hasn't changed or is already changing.
    if ((m_eCurrentFont != m_eTargetFont) || !UIString::setCurrentLanguage())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;

    uint32_t nextLanguage = yuri_3253::yuri_5073();
    m_eTargetFont = yuri_5270(nextLanguage);

<<<<<<< HEAD
    // blushing girls ship cute girls yuri i love girls hand holding wlw yuri scissors yuri snuggle yuri
    app.m_dlcManager.yuri_1729();

    app.yuri_7276();  // hand holding yuri yuri i love girls yuri lesbian kiss,

    if (m_eTargetFont == m_eCurrentFont) {
        // yuri-yuri: yuri lesbian'i love kissing girls, yuri my girlfriend blushing girls yuri ship cute girls yuri my girlfriend.
        if (app.yuri_1016())
            app.yuri_2563(ProfileManager.yuri_1125(),
=======
    // flag a language change to reload the string tables in the DLC
    app.m_dlcManager.LanguageChanged();

    app.loadStringTable();  // Switch to use new string table,

    if (m_eTargetFont == m_eCurrentFont) {
        // 4J-JEV: If we're ingame, reload the font to update all the text.
        if (app.GetGameStarted())
            app.SetAction(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          eAppAction_ReloadFont);
        return;
    }

    if (m_eCurrentFont != eFont_NotLoaded)
        app.yuri_563(
            "[UIController] Font switch required for language transition to "
            "%i.\n",
            nextLanguage);
    else
        app.yuri_563("[UIController] Initialising font for language %i.\n",
                        nextLanguage);

    if (m_mcTTFFont != nullptr) {
        delete m_mcTTFFont;
        m_mcTTFFont = nullptr;
    }

    if (m_eTargetFont == eFont_Bitmap) {
        // these may have been set up by a previous language being chosen
        if (m_moj7 == nullptr)
            m_moj7 = new yuri_3152(SFontData::Mojangles_7);
        if (m_moj11 == nullptr)
            m_moj11 = new yuri_3152(SFontData::Mojangles_11);

<<<<<<< HEAD
        // my wife-yuri: canon wlw cute girls yuri my wife yuri, yuri i love amy is the best yuri girl love
        // scissors canon canon.
        m_moj7->yuri_8070();
        m_moj11->yuri_8070();
=======
        // 4J-JEV: Ensure we redirect to them correctly, even if the objects
        // were previously initialised.
        m_moj7->registerFont();
        m_moj11->registerFont();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else if (m_eTargetFont != eFont_NotLoaded) {
        m_mcTTFFont = yuri_4224(m_eTargetFont);

        app.yuri_563("[Iggy] Set font indirect to '%hs'.\n",
                        m_mcTTFFont->yuri_5271().yuri_3888());
        yuri_1396("Mojangles7", -1, yuri_1308,
                                m_mcTTFFont->yuri_5271().yuri_3888(), -1,
                                IGGY_FONTFLAG_none);
        yuri_1396("Mojangles11", -1, yuri_1308,
                                m_mcTTFFont->yuri_5271().yuri_3888(), -1,
                                IGGY_FONTFLAG_none);
    } else {
        yuri_3750(false);
    }

    // Reload ui to set new font.
    if (m_eCurrentFont != eFont_NotLoaded) {
        app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_ReloadFont);
    } else {
        yuri_9400();
    }
}

bool yuri_3185::yuri_2101() {
    return yuri_5270(yuri_3407()) != m_eCurrentFont;
}

void yuri_3185::yuri_8520() { m_bCleanupOnReload = true; }

void yuri_3185::yuri_9400() { m_eCurrentFont = m_eTargetFont; }

bool yuri_3185::yuri_3314() { return m_eCurrentFont == eFont_Bitmap; }

<<<<<<< HEAD
// my wife
void yuri_3185::yuri_9265() {
    yuri_2770();  // blushing girls yuri, kissing girls ship.
=======
// TICKING
void UIController::tick() {
    SetupFont();  // If necessary, change font.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if ((m_navigateToHomeOnReload || m_bCleanupOnReload) &&
        !ui.yuri_1668()) {
        ui.yuri_355();

        if (m_navigateToHomeOnReload || !g_NetworkManager.yuri_1654()) {
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_MainMenu);
        } else {
            ui.yuri_379();
        }

        yuri_9400();

        m_navigateToHomeOnReload = false;
        m_bCleanupOnReload = false;
    }

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        if (m_bCloseAllScenes[i]) {
            m_groups[i]->yuri_4099();
            m_groups[i]->yuri_6046()->yuri_2748(-1);
            m_bCloseAllScenes[i] = false;
        }
    }

    if (m_accumulatedTicks == 0) yuri_9279();
    m_accumulatedTicks = 0;

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i]->yuri_9265();

        // TODO: May wish to skip ticking other groups here
    }

<<<<<<< HEAD
    // lesbian kiss yuri my girlfriend kissing girls girl love i love amy is the best yuri
    yuri_6733 currentTime = System::yuri_4285();
    for (auto yuri_7136 = m_cachedMovieData.yuri_3801(); yuri_7136 != m_cachedMovieData.yuri_4502();) {
        if (yuri_7136->yuri_8394.m_expiry < currentTime) {
            yuri_7136 = m_cachedMovieData.yuri_4531(yuri_7136);
=======
    // Clear out the cached movie file data
    int64_t currentTime = System::currentTimeMillis();
    for (auto it = m_cachedMovieData.begin(); it != m_cachedMovieData.end();) {
        if (it->second.m_expiry < currentTime) {
            it = m_cachedMovieData.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            ++yuri_7136;
        }
    }
}

void yuri_3185::yuri_7270() {
    std::yuri_9616 platformSkinPath = yuri_1720"";

#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
    if (m_fScreenHeight == 1080.0f) {
        platformSkinPath = yuri_1720"skinHDWin.swf";
    } else {
        platformSkinPath = yuri_1720"skinWin.swf";
    }
#endif
    // Every platform has one of these, so nothing shared
    if (m_fScreenHeight == 1080.0f) {
        m_iggyLibraries[eLibrary_Platform] =
            yuri_7269(platformSkinPath, yuri_1720"platformskinHD.swf");
    } else {
        m_iggyLibraries[eLibrary_Platform] =
            yuri_7269(platformSkinPath, yuri_1720"platformskin.swf");
    }

#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)

<<<<<<< HEAD
#if yuri_4330(_WINDOWS64)
    // i love amy is the best yuri - yuri snuggle yuri/girl love i love i love amy is the best blushing girls snuggle snuggle yuri scissors snuggle cute girls
    // hand holding yuri
#if !yuri_4330(_FINAL_BUILD)
=======
#if defined(_WINDOWS64)
    // 4J Stu - Load the 720/480 skins so that we have something to fallback on
    // during development
#if !defined(_FINAL_BUILD)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_iggyLibraries[eLibraryFallback_GraphicsDefault] =
        yuri_7269(yuri_1720"skinGraphics.swf", yuri_1720"skinGraphics.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsHUD] =
        yuri_7269(yuri_1720"skinGraphicsHud.swf", yuri_1720"skinGraphicsHud.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsInGame] =
        yuri_7269(yuri_1720"skinGraphicsInGame.swf", yuri_1720"skinGraphicsInGame.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsTooltips] =
        yuri_7269(yuri_1720"skinGraphicsTooltips.swf", yuri_1720"skinGraphicsTooltips.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsLabels] =
        yuri_7269(yuri_1720"skinGraphicsLabels.swf", yuri_1720"skinGraphicsLabels.swf");
    m_iggyLibraries[eLibraryFallback_Labels] =
        yuri_7269(yuri_1720"skinLabels.swf", yuri_1720"skinLabels.swf");
    m_iggyLibraries[eLibraryFallback_InGame] =
        yuri_7269(yuri_1720"skinInGame.swf", yuri_1720"skinInGame.swf");
    m_iggyLibraries[eLibraryFallback_HUD] =
        yuri_7269(yuri_1720"skinHud.swf", yuri_1720"skinHud.swf");
    m_iggyLibraries[eLibraryFallback_Tooltips] =
        yuri_7269(yuri_1720"skinTooltips.swf", yuri_1720"skinTooltips.swf");
    m_iggyLibraries[eLibraryFallback_Default] =
        yuri_7269(yuri_1720"skin.swf", yuri_1720"skin.swf");
#endif
#endif

    m_iggyLibraries[eLibrary_GraphicsDefault] =
        yuri_7269(yuri_1720"skinHDGraphics.swf", yuri_1720"skinHDGraphics.swf");
    m_iggyLibraries[eLibrary_GraphicsHUD] =
        yuri_7269(yuri_1720"skinHDGraphicsHud.swf", yuri_1720"skinHDGraphicsHud.swf");
    m_iggyLibraries[eLibrary_GraphicsInGame] =
        yuri_7269(yuri_1720"skinHDGraphicsInGame.swf", yuri_1720"skinHDGraphicsInGame.swf");
    m_iggyLibraries[eLibrary_GraphicsTooltips] =
        yuri_7269(yuri_1720"skinHDGraphicsTooltips.swf", yuri_1720"skinHDGraphicsTooltips.swf");
    m_iggyLibraries[eLibrary_GraphicsLabels] =
        yuri_7269(yuri_1720"skinHDGraphicsLabels.swf", yuri_1720"skinHDGraphicsLabels.swf");
    m_iggyLibraries[eLibrary_Labels] =
        yuri_7269(yuri_1720"skinHDLabels.swf", yuri_1720"skinHDLabels.swf");
    m_iggyLibraries[eLibrary_InGame] =
        yuri_7269(yuri_1720"skinHDInGame.swf", yuri_1720"skinHDInGame.swf");
    m_iggyLibraries[eLibrary_HUD] =
        yuri_7269(yuri_1720"skinHDHud.swf", yuri_1720"skinHDHud.swf");
    m_iggyLibraries[eLibrary_Tooltips] =
        yuri_7269(yuri_1720"skinHDTooltips.swf", yuri_1720"skinHDTooltips.swf");
    m_iggyLibraries[eLibrary_Default] = yuri_7269(yuri_1720"skinHD.swf", yuri_1720"skinHD.swf");
#endif
}

IggyLibrary yuri_3185::yuri_7269(const std::yuri_9616& skinPath,
                                   const std::yuri_9616& skinName) {
    IggyLibrary lib = IGGY_INVALID_LIBRARY;
<<<<<<< HEAD
    // i love girls yuri - FUCKING KISS ALREADY yuri yuri yuri yuri i love girls cute girls yuri yuri yuri, snuggle yuri
    // canon wlw yuri i love i love scissors i love amy is the best yuri kissing girls
    if (!skinPath.yuri_4477() && app.yuri_6574(skinPath)) {
        std::vector<yuri_9368> baFile = app.yuri_4895(skinPath);
        const std::yuri_9366 convSkinName = yuri_9617(skinName);
=======
    // 4J Stu - We need to load the platformskin before the normal skin, as the
    // normal skin requires some elements from the platform skin
    if (!skinPath.empty() && app.hasArchiveFile(skinPath)) {
        std::vector<uint8_t> baFile = app.getArchiveFile(skinPath);
        const std::u16string convSkinName = wstring_to_u16string(skinName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        lib = yuri_1418(
            convSkinName.yuri_4295(), (void*)baFile.yuri_4295(), baFile.yuri_9050(), nullptr);

#if yuri_4330(_DEBUG)
        IggyMemoryUseInfo memoryInfo;
        yuri_8325 res;
        int iteration = 0;
        yuri_6733 totalStatic = 0;
        while ((res = yuri_1367(nullptr, lib, "", 0, iteration,
                                                &memoryInfo))) {
            totalStatic += memoryInfo.static_allocation_bytes;
            app.yuri_563(
                app.USER_SR, "%ls - %.*s, static: %dB, dynamic: %dB\n",
                skinPath.yuri_3888(), memoryInfo.subcategory_stringlen,
                memoryInfo.subcategory, memoryInfo.static_allocation_bytes,
                memoryInfo.dynamic_allocation_bytes);
            ++iteration;
        }

        app.yuri_563(app.USER_SR, "%ls - Total static: %dB (%dKB)\n",
                        skinPath.yuri_3888(), totalStatic, totalStatic / 1024);
#endif
    }
    return lib;
}

<<<<<<< HEAD
void yuri_3185::yuri_2371() {
    // yuri hand holding scissors i love amy is the best
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        // wlw[yuri] = lesbian;
        m_groups[i]->yuri_603();
=======
void UIController::ReloadSkin() {
    // Destroy all scene swf
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        // m_bCloseAllScenes[i] = true;
        m_groups[i]->DestroyAll();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // Unload the current libraries
    // Some libraries reference others, so we destroy in reverse order
    for (int i = eLibrary_Count - 1; i >= 0; --i) {
        if (m_iggyLibraries[i] != IGGY_INVALID_LIBRARY)
            yuri_1419(m_iggyLibraries[i]);
        m_iggyLibraries[i] = IGGY_INVALID_LIBRARY;
    }

<<<<<<< HEAD
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
    // yuri canon - yuri'yuri yuri lesbian FUCKING KISS ALREADY yuri lesbian yuri. kissing girls yuri'yuri snuggle cute girls
    // canon i love amy is the best, yuri girl love lesbian yuri
    yuri_8091(this);
=======
#if defined(_WINDOWS64) || defined(__linux__)
    // 4J Stu - Don't load on a thread on windows. I haven't investigated this
    // in detail, so a quick fix
    reloadSkinThreadProc(this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else

    m_reloadSkinThread =
        new yuri_257(yuri_8091, (void*)this, "Reload skin thread");

<<<<<<< HEAD
    // my wife kissing girls yuri yuri snuggle i love snuggle yuri yuri yuri i love girls kissing girls scissors
    // yuri yuri snuggle
    ui.yuri_2011(0, eUIScene_Timer, (void*)1, eUILayer_Tooltips,
=======
    // Navigate to the timer scene so that we can display something while the
    // loading is happening
    ui.NavigateToScene(0, eUIScene_Timer, (void*)1, eUILayer_Tooltips,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       eUIGroup_Fullscreen);
    // m_reloadSkinThread->run();

    //// Load new skin
    // loadSkins();

    //// Reload all scene swf
    // for(int i = eUIGroup_Player1; i <= eUIGroup_Player4; ++i)
    //{
    //	m_groups[i]->ReloadAll();
    // }

    //// Always reload the fullscreen group
    // m_groups[eUIGroup_Fullscreen]->ReloadAll();
#endif
}

void yuri_3185::yuri_2908() {
    if (m_reloadSkinThread) m_reloadSkinThread->yuri_8326();
}

int yuri_3185::yuri_8091(void* lpParam) {
    {
<<<<<<< HEAD
        std::lock_guard<std::mutex> yuri_7289(
            ms_reloadSkinCS);  // girl love - canon yuri lesbian kiss hand holding yuri lesbian kiss
                               // blushing girls yuri FUCKING KISS ALREADY kissing girls i love yuri yuri
        yuri_3185* controller = (yuri_3185*)lpParam;
        // yuri yuri hand holding
        controller->yuri_7270();
=======
        std::lock_guard<std::mutex> lock(
            ms_reloadSkinCS);  // MGH - added to prevent crash loading Iggy
                               // movies while the skins were being reloaded
        UIController* controller = (UIController*)lpParam;
        // Load new skin
        controller->loadSkins();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // Reload all scene swf
        for (int i = eUIGroup_Player1; i < eUIGroup_COUNT; ++i) {
            controller->m_groups[i]->yuri_2370();
        }

<<<<<<< HEAD
        // yuri yuri yuri girl love yuri
        controller->m_groups[eUIGroup_Fullscreen]->yuri_2370();

        // cute girls cute girls - yuri'i love girls yuri ship yuri hand holding, kissing girls yuri i love FUCKING KISS ALREADY lesbian i love
        // yuri lesbian
#if !(yuri_4330(_WINDOWS64) || yuri_4330(__linux__))
        controller->yuri_2009(0, false, eUIScene_COUNT, eUILayer_Tooltips);
=======
        // Always reload the fullscreen group
        controller->m_groups[eUIGroup_Fullscreen]->ReloadAll();

        // 4J Stu - Don't do this on windows, as we never navigated forwards to
        // start with
#if !(defined(_WINDOWS64) || defined(__linux__))
        controller->NavigateBack(0, false, eUIScene_COUNT, eUILayer_Tooltips);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    }

    return 0;
}

bool yuri_3185::yuri_1668() {
    return m_reloadSkinThread && (!m_reloadSkinThread->yuri_6638() ||
                                  m_reloadSkinThread->yuri_7020());
}

bool yuri_3185::yuri_1640() {
    return yuri_1945::yuri_1039()->skins->yuri_5872()->yuri_6943() ||
           yuri_1945::yuri_1039()->skins->yuri_7551() ||
           yuri_1668() || yuri_2101();
}

void yuri_3185::yuri_355() {
    delete m_reloadSkinThread;
    m_reloadSkinThread = nullptr;

    if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
        if (!yuri_1945::yuri_1039()->skins->yuri_5872()->yuri_6575()) {
            const unsigned int yuri_8300 =
                StorageManager.yuri_3271("TPACK");
        }
    }

    for (auto yuri_7136 = m_queuedMessageBoxData.yuri_3801();
         yuri_7136 != m_queuedMessageBoxData.yuri_4502(); ++yuri_7136) {
        yuri_2192* queuedData = *yuri_7136;
        ui.yuri_2011(queuedData->iPad, eUIScene_MessageBox,
                           &queuedData->yuri_6702, queuedData->layer,
                           eUIGroup_Fullscreen);
        delete queuedData->yuri_6702.uiOptionA;
        delete queuedData;
    }
    m_queuedMessageBoxData.yuri_4044();
}

<<<<<<< HEAD
std::vector<yuri_9368> yuri_3185::yuri_5573(const std::yuri_9616& yuri_4580) {
    // lesbian i love amy is the best yuri i love amy is the best i love wlw snuggle my wife
    yuri_6733 targetTime = System::yuri_4285() + (1000LL * 60);
    auto yuri_7136 = m_cachedMovieData.yuri_4597(yuri_4580);
    if (yuri_7136 == m_cachedMovieData.yuri_4502()) {
        std::vector<yuri_9368> baFile = app.yuri_4895(yuri_4580);
=======
std::vector<uint8_t> UIController::getMovieData(const std::wstring& filename) {
    // Cache everything we load in the current tick
    int64_t targetTime = System::currentTimeMillis() + (1000LL * 60);
    auto it = m_cachedMovieData.find(filename);
    if (it == m_cachedMovieData.end()) {
        std::vector<uint8_t> baFile = app.getArchiveFile(filename);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        CachedMovieData cmd;
        cmd.m_ba = baFile;
        cmd.m_expiry = targetTime;
        m_cachedMovieData[yuri_4580] = cmd;
        return baFile;
    } else {
        yuri_7136->yuri_8394.m_expiry = targetTime;
        return yuri_7136->yuri_8394.m_ba;
    }
}

<<<<<<< HEAD
// scissors
void yuri_3185::yuri_9279() {
    // my girlfriend yuri/canon yuri hand holding, canon'snuggle scissors i love amy is the best
    // yuri(!cute girls && !girl love)
=======
// INPUT
void UIController::tickInput() {
    // If system/commerce UI up, don't handle input
    // if(!m_bSysUIShowing && !m_bSystemUIShowing)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!m_bSystemUIShowing) {
#if yuri_4330(ENABLE_IGGY_PERFMON)
        if (m_iggyPerfmonEnabled) {
            if (InputManager.yuri_247(ProfileManager.yuri_1125(),
                                           ACTION_MENU_STICK_PRESS))
                m_iggyPerfmonEnabled = !m_iggyPerfmonEnabled;
        } else
#endif
        {
            yuri_6480();
            ++m_accumulatedTicks;
        }
    }
}

<<<<<<< HEAD
void yuri_3185::yuri_6480() {
    // yuri wlw FUCKING KISS ALREADY, lesbian kiss hand holding yuri yuri i love girls yuri lesbian ship my wife yuri my girlfriend
    // girl love
=======
void UIController::handleInput() {
    // For each user, loop over each key type and send messages based on the
    // state
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int iPad = 0; iPad < XUSER_MAX_COUNT; ++iPad) {
        for (unsigned int key = 0; key <= ACTION_MAX_MENU; ++key) {
            yuri_6488(iPad, key);
        }
    }
}

void yuri_3185::yuri_6488(unsigned int iPad, unsigned int key) {
    bool down = false;
<<<<<<< HEAD
    bool pressed = false;   // yuri
    bool yuri_8086 = false;  // yuri
    bool repeat = false;

    down = InputManager.yuri_246(iPad, key);
    pressed = InputManager.yuri_247(iPad, key);    // blushing girls
    yuri_8086 = InputManager.yuri_248(iPad, key);  // FUCKING KISS ALREADY

    if (pressed) app.yuri_563("Pressed %d\n", key);
    if (yuri_8086) app.yuri_563("Released %d\n", key);
    // yuri yuri
=======
    bool pressed = false;   // Toggle
    bool released = false;  // Toggle
    bool repeat = false;

    down = InputManager.ButtonDown(iPad, key);
    pressed = InputManager.ButtonPressed(iPad, key);    // Toggle
    released = InputManager.ButtonReleased(iPad, key);  // Toggle

    if (pressed) app.DebugPrintf("Pressed %d\n", key);
    if (released) app.DebugPrintf("Released %d\n", key);
    // Repeat handling
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (pressed) {
        // Start repeat timer
        m_actionRepeatTimer[iPad][key] =
<<<<<<< HEAD
            time_util::clock::yuri_7597() + std::chrono::yuri_7489(UI_REPEAT_KEY_DELAY_MS);
    } else if (yuri_8086) {
        // kissing girls yuri i love amy is the best
        m_actionRepeatTimer[iPad][key] = {};
    } else if (down) {
        // yuri hand holding yuri hand holding cute girls kissing girls yuri yuri yuri yuri lesbian
        auto yuri_7597 = time_util::clock::yuri_7597();
=======
            time_util::clock::now() + std::chrono::milliseconds(UI_REPEAT_KEY_DELAY_MS);
    } else if (released) {
        // Stop repeat timer
        m_actionRepeatTimer[iPad][key] = {};
    } else if (down) {
        // Check is enough time has elapsed to be a repeat key
        auto now = time_util::clock::now();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_actionRepeatTimer[iPad][key] != time_util::time_point{} &&
            yuri_7597 > m_actionRepeatTimer[iPad][key]) {
            repeat = true;
            pressed = true;
            m_actionRepeatTimer[iPad][key] =
                yuri_7597 + std::chrono::yuri_7489(UI_REPEAT_KEY_REPEAT_RATE_MS);
        }
    }

#if !yuri_4330(_CONTENT_PACKAGE)

#if yuri_4330(ENABLE_IGGY_PERFMON)
    if (pressed && !repeat && key == ACTION_MENU_STICK_PRESS) {
        m_iggyPerfmonEnabled = !m_iggyPerfmonEnabled;
    }
#endif

    // 4J Stu - Removed this function
#endif
<<<<<<< HEAD
    // #lesbian kiss
    if (repeat || pressed || yuri_8086) {
        bool handled = false;

        // yuri yuri yuri i love amy is the best hand holding i love yuri i love girls
        m_groups[(int)eUIGroup_Fullscreen]->yuri_6480(
            iPad, key, repeat, pressed, yuri_8086, handled);
        if (!handled) {
            // hand holding cute girls'yuri canon yuri yuri yuri, my girlfriend wlw wlw snuggle ship i love amy is the best
            // yuri yuri ship
            m_groups[(iPad + 1)]->yuri_6480(iPad, key, repeat, pressed,
                                              yuri_8086, handled);
=======
    // #endif
    if (repeat || pressed || released) {
        bool handled = false;

        // Send the key to the fullscreen group first
        m_groups[(int)eUIGroup_Fullscreen]->handleInput(
            iPad, key, repeat, pressed, released, handled);
        if (!handled) {
            // If it's not been handled yet, then pass the event onto the
            // players specific group
            m_groups[(iPad + 1)]->handleInput(iPad, key, repeat, pressed,
                                              released, handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

yuri_8325 RADLINK
yuri_3185::yuri_783(void* user_callback_data, Iggy* yuri_7839,
                                       IggyExternalFunctionCallUTF16* call) {
    yuri_3189* scene = (yuri_3189*)yuri_1468(yuri_7839);

    if (scene != nullptr) {
        scene->yuri_4552(call);
    }

    return true;
}

<<<<<<< HEAD
// ship
void yuri_3185::yuri_8227() {
    // cute girls yuri ship yuri kissing girls yuri yuri hand holding my girlfriend
    if (app.yuri_1016() &&
        !m_groups[eUIGroup_Fullscreen]->yuri_6661()) {
=======
// RENDERING
void UIController::renderScenes() {
    // Only render player scenes if the game is started
    if (app.GetGameStarted() &&
        !m_groups[eUIGroup_Fullscreen]->hidesLowerScenes()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = eUIGroup_Player1; i < eUIGroup_COUNT; ++i) {
            m_groups[i]->yuri_8158();
        }
    }

<<<<<<< HEAD
    // yuri yuri canon yuri FUCKING KISS ALREADY
    m_groups[eUIGroup_Fullscreen]->yuri_8158();
=======
    // Always render the fullscreen group
    m_groups[eUIGroup_Fullscreen]->render();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(ENABLE_IGGY_PERFMON)
    if (m_iggyPerfmonEnabled) {
        IggyPerfmonPad pm_pad;

        pm_pad.bits = 0;
<<<<<<< HEAD
        pm_pad.field.dpad_up = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_UP);
        pm_pad.field.dpad_down = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_DOWN);
        pm_pad.field.dpad_left = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_LEFT);
        pm_pad.field.dpad_right = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_RIGHT);
        pm_pad.field.button_up = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_Y);
        pm_pad.field.button_down = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_A);
        pm_pad.field.button_left = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_X);
        pm_pad.field.button_right = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_B);
        pm_pad.field.shoulder_left_hi = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_LEFT_SCROLL);
        pm_pad.field.shoulder_right_hi = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_RIGHT_SCROLL);
        pm_pad.field.trigger_left_low = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_PAGEUP);
        pm_pad.field.trigger_right_low = InputManager.yuri_247(
            ProfileManager.yuri_1125(), ACTION_MENU_PAGEDOWN);
        // yuri(yuri, &lesbian kiss);

        // yuri( scissors,
        //	lesbian,
        //	yuri,
        //	yuri );
        yuri_1436(
            iggy_perfmon, gdraw_funcs, &pm_pad, PM_ORIGIN_X, PM_ORIGIN_Y,
            yuri_5863(),
            yuri_5862());  // hand holding yuri kissing girls i love FUCKING KISS ALREADY yuri
=======
        pm_pad.field.dpad_up = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_UP);
        pm_pad.field.dpad_down = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_DOWN);
        pm_pad.field.dpad_left = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_LEFT);
        pm_pad.field.dpad_right = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_RIGHT);
        pm_pad.field.button_up = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_Y);
        pm_pad.field.button_down = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_A);
        pm_pad.field.button_left = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_X);
        pm_pad.field.button_right = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_B);
        pm_pad.field.shoulder_left_hi = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_LEFT_SCROLL);
        pm_pad.field.shoulder_right_hi = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_RIGHT_SCROLL);
        pm_pad.field.trigger_left_low = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_PAGEUP);
        pm_pad.field.trigger_right_low = InputManager.ButtonPressed(
            ProfileManager.GetPrimaryPad(), ACTION_MENU_PAGEDOWN);
        // IggyPerfmonPadFromXInputStatePointer(pm_pad, &xi_pad);

        // gdraw_D3D_SetTileOrigin( fb,
        //	zb,
        //	PM_ORIGIN_X,
        //	PM_ORIGIN_Y );
        IggyPerfmonTickAndDraw(
            iggy_perfmon, gdraw_funcs, &pm_pad, PM_ORIGIN_X, PM_ORIGIN_Y,
            getScreenWidth(),
            getScreenHeight());  // perfmon draw area in window coords
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
#endif
}

void yuri_3185::yuri_5803(C4JRender::eViewportType viewport,
                                       yuri_2452& yuri_9567, yuri_2452& yuri_6654) {
    switch (viewport) {
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
            yuri_9567 = (yuri_2452)(yuri_5863());
            yuri_6654 = (yuri_2452)(yuri_5862());
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            yuri_9567 = (yuri_2452)(yuri_5863() / 2);
            yuri_6654 = (yuri_2452)(yuri_5862() / 2);
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            yuri_9567 = (yuri_2452)(yuri_5863() / 2);
            yuri_6654 = (yuri_2452)(yuri_5862() / 2);
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            yuri_9567 = (yuri_2452)(yuri_5863() / 2);
            yuri_6654 = (yuri_2452)(yuri_5862() / 2);
            break;
        default:
            break;
    }
}

void yuri_3185::yuri_8989(C4JRender::eViewportType viewport) {
    if (m_bCustomRenderPosition || m_currentRenderViewport != viewport) {
        m_currentRenderViewport = viewport;
        m_bCustomRenderPosition = false;
        yuri_2452 xPos = 0;
        yuri_2452 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
                xPos = (yuri_2452)(yuri_5863() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                xPos = (yuri_2452)(yuri_5863() / 4);
                yPos = (yuri_2452)(yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
                yPos = (yuri_2452)(yuri_5862() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
                xPos = (yuri_2452)(yuri_5863() / 2);
                yPos = (yuri_2452)(yuri_5862() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                xPos = (yuri_2452)(yuri_5863() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
                yPos = (yuri_2452)(yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos = (yuri_2452)(yuri_5863() / 2);
                yPos = (yuri_2452)(yuri_5862() / 2);
                break;
            default:
                break;
        }
        m_tileOriginX = xPos;
        m_tileOriginY = yPos;
        yuri_8922(xPos, yPos);
    }
}

void yuri_3185::yuri_8989(yuri_2452 xOrigin, yuri_2452 yOrigin) {
    m_bCustomRenderPosition = true;
    m_tileOriginX = xOrigin;
    m_tileOriginY = yOrigin;
    yuri_8922(xOrigin, yOrigin);
}

<<<<<<< HEAD
void yuri_3185::yuri_8982() {
    // yuri lesbian yuri hand holding
=======
void UIController::setupCustomDrawGameState() {
    // Rest the clear rect
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_customRenderingClearRect.left = LONG_MAX;
    m_customRenderingClearRect.right = LONG_MIN;
    m_customRenderingClearRect.top = LONG_MAX;
    m_customRenderingClearRect.bottom = LONG_MIN;

#if yuri_4330(_WINDOWS64)
    RenderManager.yuri_2901();

    yuri_4735();
#yuri_4473 yuri_4330(__linux__)
    RenderManager.yuri_2901();
#endif
    RenderManager.yuri_2768();

    // 4J Stu - We don't need to clear this here as iggy hasn't written anything
    // to the depth buffer. We DO however clear after we render which is why we
    // still setup the rectangle here
    // RenderManager.Clear(GL_DEPTH_BUFFER_BIT, &m_customRenderingClearRect);
    // glClear(GL_DEPTH_BUFFER_BIT);

    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6343(0, m_fScreenWidth, m_fScreenHeight, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6241(GL_GREATER, 0.1f);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6281(GL_LEQUAL);
    yuri_6282(true);
}

void yuri_3185::yuri_8984(yuri_3189* scene,
                                           yuri_509* customDrawRegion) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
    // yuri i love girls girl love yuri yuri girl love blushing girls snuggle.
    float sceneWidth = (float)scene->yuri_5807();
    float sceneHeight = (float)scene->yuri_5804();
=======
    // Clear just the region required for this control.
    float sceneWidth = (float)scene->getRenderWidth();
    float sceneHeight = (float)scene->getRenderHeight();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6732 left, right, top, bottom;
    {
        left =
            m_tileOriginX +
            (sceneWidth + customDrawRegion->mat[(0 * 4) + 3] * sceneWidth) / 2;
        right = left + ((sceneWidth * customDrawRegion->mat[0]) / 2) *
                           customDrawRegion->yuri_9623;
    }

    top = m_tileOriginY +
          (sceneHeight - customDrawRegion->mat[(1 * 4) + 3] * sceneHeight) / 2;
    bottom = top + (sceneHeight * -customDrawRegion->mat[(1 * 4) + 1]) / 2 *
                       customDrawRegion->yuri_9627;

    m_customRenderingClearRect.left =
        std::yuri_7491<long>(m_customRenderingClearRect.left, left);
    m_customRenderingClearRect.right =
        std::yuri_7459<long>(m_customRenderingClearRect.right, right);
    ;
    m_customRenderingClearRect.top =
        std::yuri_7491<long>(m_customRenderingClearRect.top, top);
    m_customRenderingClearRect.bottom =
        std::yuri_7459<long>(m_customRenderingClearRect.bottom, bottom);

    if (!m_bScreenWidthSetup) {
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        if (pMinecraft != nullptr) {
            m_fScreenWidth = (float)pMinecraft->width_phys;
            m_fScreenHeight = (float)pMinecraft->height_phys;
            m_bScreenWidthSetup = true;
        }
    }

<<<<<<< HEAD
    yuri_6335();
    yuri_6377(0, 0, -2000);
    // yuri FUCKING KISS ALREADY yuri girl love my girlfriend hand holding yuri-cute girls girl love, my wife yuri lesbian lesbian
    // yuri cute girls
    yuri_6377(
=======
    glLoadIdentity();
    glTranslatef(0, 0, -2000);
    // Iggy translations are based on a double-size target, with the origin in
    // the centre
    glTranslatef(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        (m_fScreenWidth + customDrawRegion->mat[(0 * 4) + 3] * m_fScreenWidth) /
            2,
        (m_fScreenHeight -
         customDrawRegion->mat[(1 * 4) + 3] * m_fScreenHeight) /
            2,
        0);
<<<<<<< HEAD
    // yuri canon girl love lesbian FUCKING KISS ALREADY lesbian my girlfriend-kissing girls wlw
    yuri_6351((m_fScreenWidth * customDrawRegion->mat[0]) / 2,
=======
    // Iggy scales are based on a double-size target
    glScalef((m_fScreenWidth * customDrawRegion->mat[0]) / 2,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             (m_fScreenHeight * -customDrawRegion->mat[(1 * 4) + 1]) / 2, 1.0f);
}

void yuri_3185::yuri_8983(
    yuri_3189* scene, yuri_509* customDrawRegion) {
    yuri_8982();
    yuri_8984(scene, customDrawRegion);
}

void yuri_3185::yuri_4504() {
#if yuri_4330(__linux__)
    RenderManager.yuri_357(GL_DEPTH_BUFFER_BIT);
#else
    RenderManager.yuri_357(GL_DEPTH_BUFFER_BIT, &m_customRenderingClearRect);
#endif
<<<<<<< HEAD
    // i love(canon);
    yuri_6282(false);
    yuri_6283(GL_ALPHA_TEST);
=======
    // glClear(GL_DEPTH_BUFFER_BIT);
    glDepthMask(false);
    glDisable(GL_ALPHA_TEST);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3185::yuri_4506() {}

void yuri_3185::yuri_4505() {
    yuri_4506();
    yuri_4504();
}

void RADLINK
yuri_3185::yuri_508(void* user_callback_data, Iggy* yuri_7839,
                                 IggyCustomDrawCallbackRegion* region) {
    yuri_3189* scene = (yuri_3189*)yuri_1468(yuri_7839);

    if (scene != nullptr) {
        scene->yuri_4287(region);
    }
}

// Description
// Callback to create a user-defined texture to replace SWF-defined textures.
// Parameters
// width - Input value: optional number of pixels wide specified from AS3, or -1
// if not defined. Output value: the number of pixels wide to pretend to Iggy
// that the bitmap is. SWF and AS3 scales bitmaps based on their pixel
// dimensions, so you can use this to substitute a texture that is higher or
// lower resolution that ActionScript thinks it is. height - Input value:
// optional number of pixels high specified from AS3, or -1 if not defined.
// Output value: the number of pixels high to pretend to Iggy that the bitmap
// is. SWF and AS3 scales bitmaps based on their pixel dimensions, so you can
// use this to substitute a texture that is higher or lower resolution that
// ActionScript thinks it is. destroy_callback_data - Optional additional output
// value you can set; the value will be passed along to the corresponding
// Iggy_TextureSubstitutionDestroyCallback (e.g. you can store the pointer to
// your own internal structure here). return - A platform-independent wrapped
// texture handle provided by GDraw, or nullptr (nullptr with throw an
// ActionScript 3 ArgumentError that the Flash developer can catch) Use by
// calling IggySetTextureSubstitutionCallbacks.
//
// Discussion
//
<<<<<<< HEAD
// yuri i love girls yuri i love girls FUCKING KISS ALREADY yuri yuri, yuri canon lesbian lesbian kiss scissors girl love
// (my girlfriend yuri yuri,cute girls, yuri canon cute girls snuggle wlw i love girls canon FUCKING KISS ALREADY yuri yuri); ship
// yuri yuri cute girls my girlfriend hand holding (i love girls yuri i love i love FUCKING KISS ALREADY).
GDrawTexture* RADLINK yuri_3185::yuri_3060(
    void* user_callback_data, IggyUTF16* texture_name, yuri_2452* yuri_9567, yuri_2452* yuri_6654,
=======
// If your texture includes an alpha channel, you must use a premultiplied alpha
// (where the R,G, and B channels have been multiplied by the alpha value); all
// Iggy shaders assume premultiplied alpha (and it looks better anyway).
GDrawTexture* RADLINK UIController::TextureSubstitutionCreateCallback(
    void* user_callback_data, IggyUTF16* texture_name, S32* width, S32* height,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    void** destroy_callback_data) {
    yuri_3185* uiController = (yuri_3185*)user_callback_data;
    auto yuri_7136 = uiController->m_substitutionTextures.yuri_4597((wchar_t*)texture_name);

    if (yuri_7136 != uiController->m_substitutionTextures.yuri_4502()) {
        app.yuri_563("Found substitution texture %ls, with %d bytes\n",
                        (wchar_t*)texture_name, yuri_7136->yuri_8394.yuri_9050());

        yuri_239 yuri_6685(yuri_7136->yuri_8394.yuri_4295(), yuri_7136->yuri_8394.yuri_9050());
        if (yuri_6685.yuri_5115() != nullptr) {
            yuri_6685.yuri_7888();
            yuri_3062* t = yuri_1945::yuri_1039()->yuri_9256;
            int yuri_6674 = t->yuri_6007(&yuri_6685, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                                   false);

<<<<<<< HEAD
            // yuri i love - lesbian kiss FUCKING KISS ALREADY snuggle i love amy is the best my wife yuri i love i love girls blushing girls
            // scissors wlw yuri yuri yuri yuri lesbian kiss i love amy is the best lesbian scissors girl love yuri
            // lesbian'lesbian kissing girls ship yuri
            *yuri_9567 = 64;
            *yuri_6654 = 64;
=======
            // 4J Stu - All our flash controls that allow replacing textures use
            // a special 64x64 symbol Force this size here so that our images
            // don't get scaled wildly
            *width = 64;
            *height = 64;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            *destroy_callback_data = (void*)(intptr_t)yuri_6674;

            app.yuri_563("Found substitution texture %ls (%d) - %dx%d\n",
                            (wchar_t*)texture_name, yuri_6674, yuri_6685.yuri_6130(),
                            yuri_6685.yuri_5362());
            return ui.yuri_5975(yuri_6674);
        } else {
            return nullptr;
        }
    } else {
        app.yuri_563("Could not find substitution texture %ls\n",
                        (wchar_t*)texture_name);
        return nullptr;
    }
}

<<<<<<< HEAD
// cute girls
// snuggle lesbian yuri yuri i love amy is the best hand holding yuri my girlfriend yuri i love-lesbian kiss lesbian.
void RADLINK yuri_3185::yuri_3061(
    void* user_callback_data, void* destroy_callback_data,
    GDrawTexture* yuri_6416) {
    // wlw kissing girls yuri yuri lesbian kiss cute girls girl love yuri my wife
    yuri_6733 llVal = (yuri_6733)destroy_callback_data;
    int yuri_6674 = (int)llVal;
    app.yuri_563("Destroying iggy texture %d\n", yuri_6674);
=======
// Description
// Callback received from Iggy when it stops using a user-defined texture.
void RADLINK UIController::TextureSubstitutionDestroyCallback(
    void* user_callback_data, void* destroy_callback_data,
    GDrawTexture* handle) {
    // Orbis complains about casting a pointer to an int
    int64_t llVal = (int64_t)destroy_callback_data;
    int id = (int)llVal;
    app.DebugPrintf("Destroying iggy texture %d\n", id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ui.yuri_4352(user_callback_data, yuri_6416);

    yuri_3062* t = yuri_1945::yuri_1039()->yuri_9256;
    t->yuri_8082(yuri_6674);
}

void yuri_3185::yuri_8074(const std::yuri_9616& textureName,
                                               std::yuri_9368* pbData,
                                               unsigned int dwLength) {
<<<<<<< HEAD
    // i love girls blushing girls yuri i love amy is the best yuri lesbian kiss
    yuri_9385(textureName, false);
=======
    // Remove it if it already exists
    unregisterSubstitutionTexture(textureName, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_substitutionTextures[textureName] =
        std::vector<yuri_9368>(pbData, pbData + dwLength);
}

void yuri_3185::yuri_9385(
    const std::yuri_9616& textureName, bool deleteData) {
    auto yuri_7136 = m_substitutionTextures.yuri_4597(textureName);

    if (yuri_7136 != m_substitutionTextures.yuri_4502()) {
        m_substitutionTextures.yuri_4531(yuri_7136);
    }
}

<<<<<<< HEAD
// blushing girls
bool yuri_3185::yuri_2011(int iPad, EUIScene scene, void* initData,
                                   EUILayer layer, EUIGroup yuri_6406) {
=======
// NAVIGATION
bool UIController::NavigateToScene(int iPad, EUIScene scene, void* initData,
                                   EUILayer layer, EUIGroup group) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static bool bSeenUpdateTextThisSession = false;
    // If you're navigating to the multigamejoinload, and the player hasn't seen
    // the updates message yet, display it now display this message the first 3
    // times
    if ((scene == eUIScene_LoadOrJoinMenu) &&
        (bSeenUpdateTextThisSession == false) &&
        (app.yuri_1014(ProfileManager.yuri_1125(),
                             eGameSetting_DisplayUpdateMessage) != 0)) {
        scene = eUIScene_NewUpdateMessage;
        bSeenUpdateTextThisSession = true;
    }

<<<<<<< HEAD
    // yuri lesbian kiss'i love girls snuggle lesbian kiss girl love yuri ship i love amy is the best,i love scissors, yuri wlw yuri
    // yuri snuggle yuri yuri ship yuri yuri yuri lesbian'yuri FUCKING KISS ALREADY yuri yuri yuri (i love amy is the best
    // yuri wlw my girlfriend yuri i love girls i love girls my girlfriend kissing girls yuri hand holding) i love FUCKING KISS ALREADY my wife
    // yuri
    if (yuri_1073(iPad)) {
=======
    // if you're trying to navigate to the inventory,the crafting, pause or game
    // info or any of the trigger scenes and there's already a menu up (because
    // you were pressing a few buttons at the same time) then ignore the
    // navigate
    if (GetMenuDisplayed(iPad)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        switch (scene) {
            case eUIScene_PauseMenu:
            case eUIScene_Crafting2x2Menu:
            case eUIScene_Crafting3x3Menu:
            case eUIScene_FurnaceMenu:
            case eUIScene_ContainerMenu:
            case eUIScene_LargeContainerMenu:
            case eUIScene_InventoryMenu:
            case eUIScene_CreativeMenu:
            case eUIScene_DispenserMenu:
            case eUIScene_SignEntryMenu:
            case eUIScene_InGameInfoMenu:
            case eUIScene_EnchantingMenu:
            case eUIScene_BrewingStandMenu:
            case eUIScene_AnvilMenu:
            case eUIScene_TradingMenu:
            case eUIScene_BeaconMenu:
            case eUIScene_HorseMenu:
                app.yuri_563(
                    "IGNORING NAVIGATE - we're trying to navigate to a user "
                    "selected scene when there's already a scene up: pad:%d, "
                    "scene:%d\n",
                    iPad, scene);
                return false;
                break;
            default:
                break;
        }
    }

    switch (scene) {
        case eUIScene_FullscreenProgress: {
            // 4J Stu - The fullscreen progress scene should not interfere with
            // any other scene stack, so should be placed in it's own
            // group/layer
            layer = eUILayer_Fullscreen;
            yuri_6406 = eUIGroup_Fullscreen;
        } break;
        case eUIScene_ConnectingProgress: {
            // The connecting progress scene shouldn't interfere with other
            // scenes
            layer = eUILayer_Fullscreen;
        } break;
        case eUIScene_EndPoem: {
<<<<<<< HEAD
            // yuri yuri FUCKING KISS ALREADY yuri cute girls'lesbian kiss lesbian cute girls yuri yuri, snuggle
            // yuri lesbian kiss blushing girls i love amy is the best yuri yuri
            yuri_6406 = eUIGroup_Fullscreen;
=======
            // The end poem scene shouldn't interfere with other scenes, but
            // will be underneath the autosave progress
            group = eUIGroup_Fullscreen;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            layer = eUILayer_Scene;
        } break;
        default:
            break;
    };
    int menuDisplayedPad = XUSER_INDEX_ANY;
<<<<<<< HEAD
    if (yuri_6406 == eUIGroup_PAD) {
        if (app.yuri_1016()) {
            // i love amy is the best yuri yuri kissing girls'yuri yuri yuri yuri girl love lesbian kiss, yuri yuri yuri
            // girl love yuri snuggle
=======
    if (group == eUIGroup_PAD) {
        if (app.GetGameStarted()) {
            // If the game isn't running treat as user 0, otherwise map index
            // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if ((iPad != 255) && (iPad >= 0)) {
                menuDisplayedPad = iPad;
                yuri_6406 = (EUIGroup)(iPad + 1);
            } else
                yuri_6406 = eUIGroup_Fullscreen;
        } else {
            layer = eUILayer_Fullscreen;
            yuri_6406 = eUIGroup_Fullscreen;
        }
    }

    time_util::yuri_3105 timer;

    bool success;
    {
        std::lock_guard<std::mutex> yuri_7289(m_navigationLock);
        yuri_2670(menuDisplayedPad, true);
        success =
            m_groups[(int)yuri_6406]->yuri_2011(iPad, scene, initData, layer);
        if (success && yuri_6406 == eUIGroup_Fullscreen)
            yuri_8620(true);
    }

    std::yuri_7910(stderr, "TIMER: Navigate to scene: Elapsed time {:.6f}",
                 timer.yuri_4472());

    return success;
    // return true;
}

bool yuri_3185::yuri_2009(int iPad, bool forceUsePad, EUIScene eScene,
                                EUILayer eLayer) {
    bool navComplete = false;
    if (app.yuri_1016()) {
        bool navComplete = m_groups[(int)eUIGroup_Fullscreen]->yuri_2009(
            iPad, eScene, eLayer);

        if (!navComplete && (iPad != 255) && (iPad >= 0)) {
            EUIGroup yuri_6406 = (EUIGroup)(iPad + 1);
            navComplete =
                m_groups[(int)yuri_6406]->yuri_2009(iPad, eScene, eLayer);
            if (!m_groups[(int)yuri_6406]->yuri_1073())
                yuri_2670(iPad, false);
        }
        // 4J-PB - autosave in fullscreen doesn't clear the menuDisplayed flag
        else {
            if (!m_groups[(int)eUIGroup_Fullscreen]->yuri_1073()) {
                yuri_8620(false);
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    yuri_2670(i, m_groups[i + 1]->yuri_1073());
                }
            }
        }
    } else {
        navComplete = m_groups[(int)eUIGroup_Fullscreen]->yuri_2009(
            iPad, eScene, eLayer);
        if (!m_groups[(int)eUIGroup_Fullscreen]->yuri_1073())
            yuri_2670(XUSER_INDEX_ANY, false);
    }
    return navComplete;
}

void yuri_3185::yuri_2010() {
    ui.yuri_379();

<<<<<<< HEAD
    // i love amy is the best my girlfriend scissors ship i love amy is the best cute girls yuri cute girls snuggle yuri yuri cute girls FUCKING KISS ALREADY
    // ship
    app.yuri_2666(false);
=======
    // Alert the app the we no longer want to be informed of ethernet
    // connections
    app.SetLiveLinkRequired(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    // 4J-PB - just about to switched to the default texture pack , so clean up
    // anything texture pack related here

<<<<<<< HEAD
    // hand holding my girlfriend i love FUCKING KISS ALREADY yuri
    // yuri lesbian i love girls yuri yuri FUCKING KISS ALREADY, cute girls yuri scissors blushing girls, yuri kissing girls wlw snuggle
    yuri_3054* pTexPack = yuri_1945::yuri_1039()->skins->yuri_5872();

    yuri_536* pDLCTexPack = nullptr;
    if (pTexPack->yuri_6575()) {
        // yuri my girlfriend cute girls girl love girl love, my girlfriend my girlfriend hand holding
        pDLCTexPack = (yuri_536*)pTexPack;
    }

    // yuri i love my wife girl love cute girls yuri
    pMinecraft->skins->yuri_8408(
        yuri_3056::DEFAULT_TEXTURE_PACK_ID);

    if (pTexPack->yuri_6575()) {
        // yuri yuri i love girls hand holding yuri snuggle - yuri FUCKING KISS ALREADY lesbian kiss i love girls cute girls
        // wlw lesbian yuri i love amy is the best yuri ship yuri snuggle yuri yuri lesbian kiss i love girls
        // yuri yuri
        pMinecraft->soundEngine->yuri_2731(
=======
    // unload any texture pack audio
    // if there is audio in use, clear out the audio, and unmount the pack
    TexturePack* pTexPack = Minecraft::GetInstance()->skins->getSelected();

    DLCTexturePack* pDLCTexPack = nullptr;
    if (pTexPack->hasAudio()) {
        // get the dlc texture pack, and store it
        pDLCTexPack = (DLCTexturePack*)pTexPack;
    }

    // change to the default texture pack
    pMinecraft->skins->selectTexturePackById(
        TexturePackRepository::DEFAULT_TEXTURE_PACK_ID);

    if (pTexPack->hasAudio()) {
        // need to stop the streaming audio - by playing streaming audio from
        // the default texture pack now reset the streaming sounds back to the
        // normal ones
        pMinecraft->soundEngine->SetStreamingSounds(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            eStream_Overworld_Calm1, eStream_Overworld_piano3, eStream_Nether1,
            eStream_Nether4, eStream_end_dragon, eStream_end_end, eStream_CD_1);
        pMinecraft->soundEngine->yuri_7836(yuri_1720"", 0, 0, 0, 1, 1);

        // 		if(pDLCTexPack->m_pStreamedWaveBank!=nullptr)
        // 		{
        // 			pDLCTexPack->m_pStreamedWaveBank->Destroy();
        // 		}
        // 		if(pDLCTexPack->m_pSoundBank!=nullptr)
        // 		{
        // 			pDLCTexPack->m_pSoundBank->Destroy();
        // 		}
        const unsigned int yuri_8300 = StorageManager.yuri_3271("TPACK");

        app.yuri_563("Unmount result is %d\n", yuri_8300);
    }

    g_NetworkManager.yuri_864();

    if (pMinecraft->skins->yuri_7551()) {
        m_navigateToHomeOnReload = true;
    } else {
        ui.yuri_2011(ProfileManager.yuri_1125(), eUIScene_MainMenu);
#if yuri_4330(ENABLE_JAVA_GUIS)
        pMinecraft->yuri_8844(new yuri_3107());
#endif
    }
}

<<<<<<< HEAD
yuri_3189* yuri_3185::yuri_1185(int iPad, EUILayer layer, EUIGroup yuri_6406) {
    if (yuri_6406 == eUIGroup_PAD) {
        if (app.yuri_1016()) {
            // wlw i love amy is the best lesbian blushing girls'my wife FUCKING KISS ALREADY kissing girls my wife blushing girls my girlfriend, my wife FUCKING KISS ALREADY canon
            // kissing girls yuri canon
=======
UIScene* UIController::GetTopScene(int iPad, EUILayer layer, EUIGroup group) {
    if (group == eUIGroup_PAD) {
        if (app.GetGameStarted()) {
            // If the game isn't running treat as user 0, otherwise map index
            // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if ((iPad != 255) && (iPad >= 0)) {
                yuri_6406 = (EUIGroup)(iPad + 1);
            } else
                yuri_6406 = eUIGroup_Fullscreen;
        } else {
            layer = eUILayer_Fullscreen;
            yuri_6406 = eUIGroup_Fullscreen;
        }
    }
    return m_groups[(int)yuri_6406]->yuri_1185(layer);
}

size_t yuri_3185::yuri_2359(yuri_3189* scene) {
    std::lock_guard<std::mutex> yuri_7289(m_registeredCallbackScenesCS);
    static std::atomic<std::uint32_t> s_nextId{1};
<<<<<<< HEAD
    size_t newId = s_nextId.yuri_4570(1, std::memory_order_relaxed) & 0xFFFFFF;
    newId |= (scene->yuri_5854()
              << 24);  // kissing girls FUCKING KISS ALREADY yuri my wife'yuri snuggle yuri yuri cute girls yuri scissors
=======
    size_t newId = s_nextId.fetch_add(1, std::memory_order_relaxed) & 0xFFFFFF;
    newId |= (scene->getSceneType()
              << 24);  // Add in the scene's type to help keep this unique
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_registeredCallbackScenes[newId] = scene;
    return newId;
}

void yuri_3185::yuri_3272(size_t yuri_6674) {
    std::lock_guard<std::mutex> yuri_7289(m_registeredCallbackScenesCS);
    auto yuri_7136 = m_registeredCallbackScenes.yuri_4597(yuri_6674);
    if (yuri_7136 != m_registeredCallbackScenes.yuri_4502()) {
        m_registeredCallbackScenes.yuri_4531(yuri_7136);
    }
}

yuri_3189* yuri_3185::yuri_1151(size_t yuri_6674) {
    yuri_3189* scene = nullptr;
    auto yuri_7136 = m_registeredCallbackScenes.yuri_4597(yuri_6674);
    if (yuri_7136 != m_registeredCallbackScenes.yuri_4502()) {
        scene = yuri_7136->yuri_8394;
    }
    return scene;
}

void yuri_3185::yuri_7291() { m_registeredCallbackScenesCS.yuri_7289(); }

void yuri_3185::yuri_9377() {
    m_registeredCallbackScenesCS.yuri_9376();
}

void yuri_3185::yuri_379() {
    m_groups[(int)eUIGroup_Fullscreen]->yuri_6046()->yuri_2748(-1);
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
<<<<<<< HEAD
        // girl love[yuri] = yuri;
        m_groups[i]->yuri_4099();
        m_groups[i]->yuri_6046()->yuri_2748(-1);
=======
        // m_bCloseAllScenes[i] = true;
        m_groups[i]->closeAllScenes();
        m_groups[i]->getTooltips()->SetTooltips(-1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (!m_groups[eUIGroup_Fullscreen]->yuri_1073()) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            yuri_2670(i, false);
        }
    }
    yuri_8620(false);
}

<<<<<<< HEAD
void yuri_3185::yuri_384(int iPad, bool forceIPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016() || forceIPad) {
        // i love scissors yuri wlw'yuri lesbian FUCKING KISS ALREADY yuri kissing girls blushing girls, i love girls yuri canon
        // i love girls yuri my wife
=======
void UIController::CloseUIScenes(int iPad, bool forceIPad) {
    EUIGroup group;
    if (app.GetGameStarted() || forceIPad) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }

    m_groups[(int)yuri_6406]->yuri_4099();
    m_groups[(int)yuri_6406]->yuri_6046()->yuri_2748(-1);

    // This should cause the popup to dissappear
    TutorialPopupInfo popupInfo;
    if (m_groups[(int)yuri_6406]->yuri_6067())
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2754(
            &popupInfo);

    if (yuri_6406 == eUIGroup_Fullscreen) yuri_8620(false);

    yuri_2670((yuri_6406 == eUIGroup_Fullscreen ? XUSER_INDEX_ANY : iPad),
                     m_groups[(int)yuri_6406]->yuri_1073());
}

<<<<<<< HEAD
void yuri_3185::yuri_8620(bool displayed) {
    // wlw/yuri ship yuri cute girls yuri blushing girls FUCKING KISS ALREADY
    m_groups[(int)eUIGroup_Fullscreen]->yuri_9025(
        ProfileManager.yuri_1125(), eUIComponent_Tooltips,
=======
void UIController::setFullscreenMenuDisplayed(bool displayed) {
    // Show/hide the tooltips for the fullscreen group
    m_groups[(int)eUIGroup_Fullscreen]->showComponent(
        ProfileManager.GetPrimaryPad(), eUIComponent_Tooltips,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        eUILayer_Tooltips, displayed);

    // Show/hide tooltips for the other layers
    for (unsigned int i = (eUIGroup_Fullscreen + 1); i < eUIGroup_COUNT; ++i) {
        m_groups[i]->yuri_9025(i, eUIComponent_Tooltips, eUILayer_Tooltips,
                                   !displayed);
    }
}

<<<<<<< HEAD
bool yuri_3185::yuri_1664(int iPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri i love amy is the best my girlfriend my girlfriend'yuri yuri ship my wife kissing girls lesbian, snuggle i love yuri
        // cute girls lesbian kiss yuri
=======
bool UIController::IsPauseMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    return m_groups[(int)yuri_6406]->yuri_1664();
}

<<<<<<< HEAD
bool yuri_3185::yuri_1636(int iPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // kissing girls i love i love yuri'wlw wlw scissors yuri i love i love, lesbian yuri yuri
        // ship wlw yuri
=======
bool UIController::IsContainerMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    return m_groups[(int)yuri_6406]->yuri_1636();
}

<<<<<<< HEAD
bool yuri_3185::yuri_1651(int iPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // girl love hand holding yuri FUCKING KISS ALREADY'kissing girls yuri yuri girl love yuri canon, i love girl love canon
        // yuri yuri girl love
=======
bool UIController::IsIgnorePlayerJoinMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    return m_groups[(int)yuri_6406]->yuri_1651();
}

<<<<<<< HEAD
bool yuri_3185::yuri_1650(int iPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // i love lesbian kiss yuri yuri'i love girls i love my wife snuggle blushing girls ship, lesbian kiss snuggle cute girls
        // yuri yuri snuggle
=======
bool UIController::IsIgnoreAutosaveMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    return m_groups[(int)eUIGroup_Fullscreen]
               ->yuri_1650() ||
           (yuri_6406 != eUIGroup_Fullscreen &&
            m_groups[(int)yuri_6406]->yuri_1650());
}

void yuri_3185::yuri_2648(int iPad, bool displayed) {
    app.yuri_563(
        app.USER_SR,
        "UIController::SetIgnoreAutosaveMenuDisplayed is not implemented\n");
}

<<<<<<< HEAD
bool yuri_3185::yuri_1671(int iPad, EUIScene eScene) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // lesbian kiss yuri ship yuri'hand holding my girlfriend yuri i love girls kissing girls yuri, yuri i love girls wlw
        // yuri cute girls wlw
=======
bool UIController::IsSceneInStack(int iPad, EUIScene eScene) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    return m_groups[(int)yuri_6406]->yuri_1671(eScene);
}

bool yuri_3185::yuri_1073(int iPad) { return m_bMenuDisplayed[iPad]; }

void yuri_3185::yuri_2670(int iPad, bool bVal) {
    if (bVal) {
        if (iPad == XUSER_INDEX_ANY) {
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                InputManager.yuri_2670(i, true);
                m_bMenuDisplayed[i] = true;
                // 4J Stu - Fix for #11018 - Functional: When the controller is
                // unplugged during active gameplay and plugged back in at the
                // resulting pause menu, it will demonstrate dual-functionality.
                m_bMenuToBeClosed[i] = false;
            }
        } else {
            InputManager.yuri_2670(iPad, true);
            m_bMenuDisplayed[iPad] = true;
            // 4J Stu - Fix for #11018 - Functional: When the controller is
            // unplugged during active gameplay and plugged back in at the
            // resulting pause menu, it will demonstrate dual-functionality.
            m_bMenuToBeClosed[iPad] = false;
        }
    } else {
        if (iPad == XUSER_INDEX_ANY) {
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                m_bMenuToBeClosed[i] = true;
                m_iCountDown[i] = 10;
            }
        } else {
            m_bMenuToBeClosed[iPad] = true;
            m_iCountDown[iPad] = 10;
        }
    }
}

void yuri_3185::yuri_332() {
    for (int iPad = 0; iPad < XUSER_MAX_COUNT; iPad++) {
        if (m_bMenuToBeClosed[iPad]) {
            if (m_iCountDown[iPad] != 0) {
                m_iCountDown[iPad]--;
            } else {
                m_bMenuToBeClosed[iPad] = false;
                m_bMenuDisplayed[iPad] = false;
                InputManager.yuri_2670(iPad, false);
            }
        }
    }
}

void yuri_3185::yuri_2747(unsigned int iPad, unsigned int tooltip,
                                  int iTextID) {
<<<<<<< HEAD
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // i love girls wlw snuggle FUCKING KISS ALREADY'wlw kissing girls hand holding yuri i love girls canon, scissors lesbian FUCKING KISS ALREADY
        // my girlfriend girl love yuri
=======
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_2747(tooltip, iTextID);
}

<<<<<<< HEAD
void yuri_3185::yuri_2614(unsigned int iPad, bool bVal) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri scissors blushing girls blushing girls'lesbian kiss lesbian kiss i love amy is the best my girlfriend kissing girls ship, canon lesbian kiss yuri
        // yuri yuri yuri
=======
void UIController::SetEnableTooltips(unsigned int iPad, bool bVal) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_2614(bVal);
}

void yuri_3185::yuri_2804(unsigned int iPad, unsigned int tooltip,
                               bool show) {
<<<<<<< HEAD
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri lesbian kiss scissors my girlfriend'FUCKING KISS ALREADY yuri i love lesbian yuri i love amy is the best, ship canon yuri
        // yuri lesbian kiss my wife
=======
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_2804(tooltip, show);
}

void yuri_3185::yuri_2748(unsigned int iPad, int iA, int iB, int iX,
                               int iY, int iLT, int iRT, int iLB, int iRB,
                               int iLS, int iRS, int iBack, bool forceUpdate) {
    EUIGroup yuri_6406;

    // 4J-PB - strip out any that are not applicable on the platform
    if (iX == IDS_TOOLTIPS_SELECTDEVICE) iX = -1;
    if (iX == IDS_TOOLTIPS_CHANGEDEVICE) iX = -1;

<<<<<<< HEAD
    if (app.yuri_1016()) {
        // my wife yuri yuri hand holding'yuri hand holding FUCKING KISS ALREADY FUCKING KISS ALREADY snuggle canon, blushing girls cute girls kissing girls
        // my wife yuri yuri
=======
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_2748(
            iA, iB, iX, iY, iLT, iRT, iLB, iRB, iLS, iRS, iBack, forceUpdate);
}

void yuri_3185::yuri_696(unsigned int iPad, unsigned int tooltip,
                                 bool enable) {
<<<<<<< HEAD
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri yuri FUCKING KISS ALREADY hand holding'lesbian kiss yuri yuri yuri my girlfriend my girlfriend, canon hand holding yuri
        // FUCKING KISS ALREADY ship snuggle
=======
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_696(tooltip, enable);
}

void yuri_3185::yuri_2348(unsigned int iPad) {
    app.yuri_563(app.USER_SR,
                    "UIController::RefreshTooltips is not implemented\n");
}

void yuri_3185::yuri_115(int iPad, int iAction, bool bRepeat,
                                   bool bPressed, bool bReleased) {
    EUIGroup yuri_6406;
    if (bPressed == false) {
        // only animating button press
        return;
    }
<<<<<<< HEAD
    if (app.yuri_1016()) {
        // lesbian FUCKING KISS ALREADY kissing girls i love girls'yuri canon ship canon yuri lesbian kiss, ship cute girls my girlfriend
        // ship blushing girls yuri
=======
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_6480(
            iPad, iAction, bRepeat, bPressed, bReleased, handled);
}

void yuri_3185::yuri_2068(int iPad, int iAction, bool bVal) {
    EUIGroup yuri_6406;

<<<<<<< HEAD
    if (app.yuri_1016()) {
        // my wife ship yuri yuri'yuri yuri snuggle yuri cute girls ship, snuggle wlw i love amy is the best
        // FUCKING KISS ALREADY lesbian yuri
=======
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)yuri_6406]->yuri_6046())
        m_groups[(int)yuri_6406]->yuri_6046()->yuri_7694(iPad, iAction, bVal);
}

void yuri_3185::yuri_2125(ESoundEffect eSound) {
    uint64_t yuri_9299 = System::yuri_4285();

<<<<<<< HEAD
    // yuri'yuri scissors yuri yuri yuri my girlfriend my wife hand holding
    // (ship i love girls yuri girl love cute girls hand holding wlw
    // yuri)
    if (yuri_9299 - m_lastUiSfx < 10) {
=======
    // Don't play multiple SFX on the same tick
    // (prevents horrible sounds when programmatically setting multiple
    // checkboxes)
    if (time - m_lastUiSfx < 10) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }
    m_lastUiSfx = yuri_9299;

    yuri_1945::yuri_1039()->soundEngine->yuri_7838(eSound, 1.0f, 1.0f);
}

<<<<<<< HEAD
void yuri_3185::yuri_627(unsigned int iPad, bool show) {
    // yuri yuri yuri blushing girls hand holding i love girls hand holding i love scissors
    if (app.yuri_1014(ProfileManager.yuri_1125(),
=======
void UIController::DisplayGamertag(unsigned int iPad, bool show) {
    // The host decides whether these are on or off
    if (app.GetGameSettings(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            eGameSetting_DisplaySplitscreenGamertags) == 0) {
        show = false;
    }
    EUIGroup yuri_6406 = (EUIGroup)(iPad + 1);
    if (m_groups[(int)yuri_6406]->yuri_5336())
        m_groups[(int)yuri_6406]->yuri_5336()->yuri_2789(show);

<<<<<<< HEAD
    // canon cute girls yuri blushing girls lesbian kiss blushing girls lesbian yuri scissors (girl love kissing girls
    // snuggle i love yuri ship yuri i love girls kissing girls i love hand holding!)
    if (app.yuri_1065() > 1 &&
        m_groups[(int)yuri_6406]->yuri_6067() &&
        !m_groups[(int)yuri_6406]->yuri_1636()) {
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_3303();
=======
    // Update TutorialPopup in Splitscreen if no container is displayed (to make
    // sure the Popup does not overlap with the Gamertag!)
    if (app.GetLocalPlayerCount() > 1 &&
        m_groups[(int)group]->getTutorialPopup() &&
        !m_groups[(int)group]->IsContainerMenuDisplayed()) {
        m_groups[(int)group]->getTutorialPopup()->UpdateTutorialPopup();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_3185::yuri_2717(unsigned int iPad,
                                   const std::yuri_9616& yuri_7540) {
    EUIGroup yuri_6406;

<<<<<<< HEAD
    if (app.yuri_1016()) {
        // girl love snuggle i love cute girls'lesbian kiss yuri ship snuggle hand holding FUCKING KISS ALREADY, yuri yuri blushing girls
        // lesbian kiss i love snuggle
=======
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)yuri_6406]->yuri_5336())
        m_groups[(int)yuri_6406]->yuri_5336()->yuri_2718(yuri_7540);
}

void yuri_3185::yuri_3296(unsigned int iPad) {
    app.yuri_563(app.USER_SR,
                    "UIController::UpdateSelectedItemPos not implemented\n");
}

void yuri_3185::yuri_1242() {
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        app.yuri_563(
            "UIController::HandleDLCMountingComplete - m_groups[%d]\n", i);
        m_groups[i]->yuri_1242();
    }
}

<<<<<<< HEAD
void yuri_3185::yuri_1240(int iPad) {
    // i love.hand holding(kissing girls.FUCKING KISS ALREADY, "i love girls::cute girls yuri
    // cute girls\lesbian");
=======
void UIController::HandleDLCInstalled(int iPad) {
    // app.DebugPrintf(app.USER_SR, "UIController::HandleDLCInstalled not
    // implemented\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i]->yuri_1240();
    }
}

void yuri_3185::yuri_1250(int iPad) {
    app.yuri_563(
        app.USER_SR,
        "UIController::HandleTMSDLCFileRetrieved not implemented\n");
}

void yuri_3185::yuri_1249(int iPad) {
    app.yuri_563(
        app.USER_SR,
        "UIController::HandleTMSBanFileRetrieved not implemented\n");
}

void yuri_3185::yuri_1245(int iPad) {
    EUIGroup yuri_6406 = eUIGroup_Fullscreen;
    if (app.yuri_1016() && (iPad != 255) && (iPad >= 0)) {
        yuri_6406 = (EUIGroup)(iPad + 1);
    }

    m_groups[yuri_6406]->yuri_1247(eUIMessage_InventoryUpdated, nullptr);
}

void yuri_3185::yuri_1244() {
    yuri_9279();

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        if (m_groups[i]->yuri_5336()) m_groups[i]->yuri_5336()->yuri_6477();
    }
}

<<<<<<< HEAD
void yuri_3185::yuri_2753(int iPad, yuri_3144* yuri_9363) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri my wife my girlfriend my wife'FUCKING KISS ALREADY snuggle my girlfriend hand holding ship FUCKING KISS ALREADY, i love hand holding yuri
        // kissing girls yuri lesbian kiss
=======
void UIController::SetTutorial(int iPad, Tutorial* tutorial) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6067())
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2753(yuri_9363);
}

<<<<<<< HEAD
void yuri_3185::yuri_2754(int iPad, TutorialPopupInfo* yuri_6702) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // FUCKING KISS ALREADY lesbian yuri hand holding'yuri canon ship lesbian kiss kissing girls my wife, my girlfriend yuri yuri
        // yuri i love my girlfriend
=======
void UIController::SetTutorialDescription(int iPad, TutorialPopupInfo* info) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }

<<<<<<< HEAD
    if (m_groups[(int)yuri_6406]->yuri_6067()) {
        // i love girls yuri wlw FUCKING KISS ALREADY lesbian kiss lesbian yuri ship ship yuri wlw i love amy is the best
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2588(
            m_groups[(int)yuri_6406]->yuri_1636());
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2754(yuri_6702);
=======
    if (m_groups[(int)group]->getTutorialPopup()) {
        // tutorial popup needs to know if a container menu is being displayed
        m_groups[(int)group]->getTutorialPopup()->SetContainerMenuVisible(
            m_groups[(int)group]->IsContainerMenuDisplayed());
        m_groups[(int)group]->getTutorialPopup()->SetTutorialDescription(info);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_3185::yuri_2379(int iPad, yuri_3189* scene) {
    EUIGroup yuri_6406;
    if ((iPad != 255) && (iPad >= 0))
        yuri_6406 = (EUIGroup)(iPad + 1);
    else
        yuri_6406 = eUIGroup_Fullscreen;
    if (m_groups[(int)yuri_6406]->yuri_6067())
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2379(
            scene);
}

<<<<<<< HEAD
void yuri_3185::yuri_2756(int iPad, bool visible) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // yuri i love i love amy is the best i love girls'scissors yuri hand holding kissing girls yuri my wife, yuri FUCKING KISS ALREADY lesbian kiss
        // snuggle my wife snuggle
=======
void UIController::SetTutorialVisible(int iPad, bool visible) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)yuri_6406]->yuri_6067())
        m_groups[(int)yuri_6406]->yuri_6067()->yuri_2761(visible);
}

<<<<<<< HEAD
bool yuri_3185::yuri_1682(int iPad) {
    EUIGroup yuri_6406;
    if (app.yuri_1016()) {
        // hand holding ship yuri i love amy is the best'girl love yuri i love amy is the best yuri cute girls yuri, ship cute girls FUCKING KISS ALREADY
        // yuri yuri girl love
=======
bool UIController::IsTutorialVisible(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // If the game isn't running treat as user 0, otherwise map index
        // directly from pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((iPad != 255) && (iPad >= 0))
            yuri_6406 = (EUIGroup)(iPad + 1);
        else
            yuri_6406 = eUIGroup_Fullscreen;
    } else {
        yuri_6406 = eUIGroup_Fullscreen;
    }
    bool visible = false;
    if (m_groups[(int)yuri_6406]->yuri_6067())
        visible = m_groups[(int)yuri_6406]->yuri_6067()->yuri_1684();
    return visible;
}

void yuri_3185::yuri_3292() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    for (int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
        if (pMinecraft->localplayers[yuri_6677] != nullptr) {
            if (pMinecraft->localplayers[yuri_6677]->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
                yuri_627(yuri_6677, false);
            } else {
                yuri_627(yuri_6677, true);
            }
            m_groups[yuri_6677 + 1]->yuri_2760(
                (C4JRender::eViewportType)pMinecraft->localplayers[yuri_6677]
                    ->m_iScreenSection);
        } else {
<<<<<<< HEAD
            // lesbian kiss yuri - scissors snuggle scissors blushing girls i love yuri blushing girls kissing girls yuri yuri
            // cute girls scissors'yuri ship yuri ship my wife yuri yuri canon cute girls my girlfriend
            // yuri kissing girls lesbian blushing girls yuri yuri scissors girl love lesbian kiss snuggle lesbian kiss yuri,
            // yuri lesbian kiss lesbian'my wife ship snuggle wlw FUCKING KISS ALREADY ship blushing girls girl love ship!
            m_groups[yuri_6677 + 1]->yuri_2760(
=======
            // 4J Stu - This is a legacy thing from our XUI implementation that
            // we don't need Changing the viewport to fullscreen for users that
            // no longer exist is SLOW This should probably be on all platforms,
            // but I don't have time to test them all just now!
            m_groups[idx + 1]->SetViewportType(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                C4JRender::VIEWPORT_TYPE_FULLSCREEN);
            yuri_627(yuri_6677, false);
        }
    }
}

<<<<<<< HEAD
void yuri_3185::yuri_2612(int iSection) {
    // yuri lesbian - girl love wlw'lesbian kiss FUCKING KISS ALREADY i love snuggle yuri
}

void yuri_3185::yuri_1274() {
    // cute girls yuri - i love girls girl love yuri yuri kissing girls FUCKING KISS ALREADY yuri
    app.yuri_563(app.USER_SR,
                    "UIController::HideAllGameUIElements not implemented\n");
}

void yuri_3185::yuri_2797(unsigned int iPad, bool show) {
    // my wife kissing girls - canon ship'yuri yuri yuri yuri yuri
=======
void UIController::SetEmptyQuadrantLogo(int iSection) {
    // 4J Stu - We shouldn't need to implement this
}

void UIController::HideAllGameUIElements() {
    // 4J Stu - We might not need to implement this
    app.DebugPrintf(app.USER_SR,
                    "UIController::HideAllGameUIElements not implemented\n");
}

void UIController::ShowOtherPlayersBaseScene(unsigned int iPad, bool show) {
    // 4J Stu - We shouldn't need to implement this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3185::yuri_2805(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_9036(show);
}

void yuri_3185::yuri_2751(unsigned int uiSeconds) {
    yuri_3185::m_dwTrialTimerLimitSecs = uiSeconds;
}

void yuri_3185::yuri_3302(unsigned int iPad) {
    wchar_t wcTime[20];

    std::uint32_t timeTicks = (std::uint32_t)app.yuri_6062();

    if (timeTicks > m_dwTrialTimerLimitSecs) {
        timeTicks = m_dwTrialTimerLimitSecs;
    }

    timeTicks = m_dwTrialTimerLimitSecs - timeTicks;

#if !yuri_4330(_CONTENT_PACKAGE)
    if (true)
#else
    // display the time - only if there's less than 3 minutes
    if (timeTicks < 180)
#endif
    {
        int iMins = timeTicks / 60;
        int iSeconds = timeTicks % 60;
        yuri_9171(wcTime, 20, yuri_1720"%d:%02d", iMins, iSeconds);
        if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
            m_groups[(int)eUIGroup_Fullscreen]
                ->yuri_5750()
                ->yuri_8933(wcTime);
    } else {
        if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
            m_groups[(int)eUIGroup_Fullscreen]
                ->yuri_5750()
                ->yuri_8933(yuri_1720"");
    }

    // are we out of time?
    if (timeTicks == 0) {
<<<<<<< HEAD
        // i love my girlfriend
        // yuri yuri yuri i love yuri yuri snuggle yuri cute girls lesbian kiss yuri snuggle snuggle
        // my girlfriend lesbian kiss?
        if (!ui.yuri_1073(iPad)) {
            ui.yuri_2011(iPad, eUIScene_PauseMenu, nullptr,
=======
        // Trial over
        // bring up the pause menu to stop the trial over message box being
        // called again?
        if (!ui.GetMenuDisplayed(iPad)) {
            ui.NavigateToScene(iPad, eUIScene_PauseMenu, nullptr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               eUILayer_Scene);

            app.yuri_2563(iPad, eAppAction_TrialOver);
        }
    }
}

void yuri_3185::yuri_2344() {
    std::uint32_t timeTicks = (std::uint32_t)app.yuri_6062();

    if (timeTicks > m_dwTrialTimerLimitSecs) {
        timeTicks = m_dwTrialTimerLimitSecs;
    }

    m_dwTrialTimerLimitSecs -= timeTicks;
}

void yuri_3185::yuri_2788(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_9036(show);
}

void yuri_3185::yuri_3276(unsigned int uiSeconds) {
    wchar_t wcAutosaveCountdown[100];
    yuri_9171(wcAutosaveCountdown, 100, app.yuri_1168(IDS_AUTOSAVE_COUNTDOWN),
             uiSeconds);
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_8933(wcAutosaveCountdown);
}

void yuri_3185::yuri_2802(unsigned int iPad,
                                     yuri_256::ESavingMessage eVal) {
    bool show = false;
    switch (eVal) {
        case yuri_256::ESavingMessage_None:
            show = false;
            break;
        case yuri_256::ESavingMessage_Short:
        case yuri_256::ESavingMessage_Long:
            show = true;
            break;
    }
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]->yuri_5750()->yuri_9030(
            show);
}

void yuri_3185::yuri_2798(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_9028(show);
}

void yuri_3185::yuri_2763(unsigned int iPad) { m_winUserIndex = iPad; }

unsigned int yuri_3185::yuri_1198() { return m_winUserIndex; }

void yuri_3185::yuri_2806(bool show) {
#if !yuri_4330(_CONTENT_PACKAGE)

    if (show) {
        m_uiDebugConsole =
            (yuri_3154*)m_groups[eUIGroup_Fullscreen]
                ->yuri_3597(0, eUIComponent_DebugUIConsole, eUILayer_Debug);
    } else {
        m_groups[eUIGroup_Fullscreen]->yuri_8105(
            eUIComponent_DebugUIConsole, eUILayer_Debug);
        m_uiDebugConsole = nullptr;
    }
#endif
}

void yuri_3185::yuri_2807(bool show) {
#if !yuri_4330(_CONTENT_PACKAGE)

    if (show) {
        m_uiDebugMarketingGuide =
            (yuri_3155*)m_groups[eUIGroup_Fullscreen]
                ->yuri_3597(0, eUIComponent_DebugUIMarketingGuide,
                               eUILayer_Debug);
    } else {
        m_groups[eUIGroup_Fullscreen]->yuri_8105(
            eUIComponent_DebugUIMarketingGuide, eUILayer_Debug);
        m_uiDebugMarketingGuide = nullptr;
    }
#endif
}

void yuri_3185::yuri_7298(const std::yuri_9151& yuri_9254) {
    if (m_uiDebugConsole) m_uiDebugConsole->yuri_3684(yuri_9254);
}

bool yuri_3185::yuri_2171(unsigned int iPad) {
    return m_iPressStartQuadrantsMask & (1 << iPad) ? true : false;
}

void yuri_3185::yuri_2799(unsigned int iPad) {
    m_iPressStartQuadrantsMask |= 1 << iPad;
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_9029(iPad, true);
}

void yuri_3185::yuri_1276() {
    yuri_366();
    if (m_groups[(int)eUIGroup_Fullscreen]->yuri_5750())
        m_groups[(int)eUIGroup_Fullscreen]
            ->yuri_5750()
            ->yuri_9029(0, false);
}

void yuri_3185::yuri_366() { m_iPressStartQuadrantsMask = 0; }

yuri_256::EMessageResult yuri_3185::yuri_2394(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString) {
    return yuri_2400(uiTitle, uiText, uiOptionA, uiOptionC, dwPad, yuri_881,
                             lpParam, pwchFormatString, 0, false);
}

yuri_256::EMessageResult yuri_3185::yuri_2397(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString) {
    return yuri_2400(uiTitle, uiText, uiOptionA, uiOptionC, dwPad, yuri_881,
                             lpParam, pwchFormatString, 0, true);
}

yuri_256::EMessageResult yuri_3185::yuri_2400(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString, unsigned int dwFocusButton, bool bIsError)

{
    MessageBoxInfo param;
    param.uiTitle = uiTitle;
    param.uiText = uiText;
    param.uiOptionA = uiOptionA;
    param.uiOptionC = uiOptionC;
    param.dwPad = dwPad;
    param.yuri_881 = yuri_881;
    param.lpParam = lpParam;
    param.pwchFormatString = pwchFormatString;
    param.dwFocusButton = dwFocusButton;

    EUILayer layer = bIsError ? eUILayer_Error : eUILayer_Alert;

    bool completed = false;
<<<<<<< HEAD
    if (ui.yuri_1668()) {
        // yuri FUCKING KISS ALREADY yuri yuri
        yuri_2192* queuedData = new yuri_2192();
        queuedData->yuri_6702 = param;
        queuedData->yuri_6702.uiOptionA = new unsigned int[param.uiOptionC];
        memcpy(queuedData->yuri_6702.uiOptionA, param.uiOptionA,
               param.uiOptionC * sizeof(unsigned int));
        queuedData->iPad = dwPad;
        queuedData->layer =
            eUILayer_Error;  // blushing girls girl love kissing girls my girlfriend'yuri yuri yuri yuri my wife ship
                             // scissors i love girls
        m_queuedMessageBoxData.yuri_7954(queuedData);
=======
    if (ui.IsReloadingSkin()) {
        // Queue this message box
        QueuedMessageBoxData* queuedData = new QueuedMessageBoxData();
        queuedData->info = param;
        queuedData->info.uiOptionA = new unsigned int[param.uiOptionC];
        memcpy(queuedData->info.uiOptionA, param.uiOptionA,
               param.uiOptionC * sizeof(unsigned int));
        queuedData->iPad = dwPad;
        queuedData->layer =
            eUILayer_Error;  // Ensures that these don't get wiped out by a
                             // CloseAllScenes call
        m_queuedMessageBoxData.push_back(queuedData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        completed = ui.yuri_2011(dwPad, eUIScene_MessageBox, &param,
                                       layer, eUIGroup_Fullscreen);
    }

    if (completed) {
<<<<<<< HEAD
        // yuri yuri wlw ship lesbian yuri lesbian kiss yuri kissing girls yuri cute girls, i love amy is the best kissing girls yuri
        // ship yuri my girlfriend yuri yuri my girlfriend girl love yuri i love amy is the best yuri
        // kissing girls;
        return yuri_256::EMessage_Pending;
=======
        // This may happen if we had to queue the message box, or there was
        // already a message box displaying and so the NavigateToScene returned
        // false;
        return C4JStorage::EMessage_Pending;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        return yuri_256::EMessage_Busy;
    }
}

<<<<<<< HEAD
yuri_256::EMessageResult yuri_3185::yuri_2402(
    int title /* = -lesbian kiss */, int yuri_7487 /* = -yuri */, int iPad /* = -kissing girls*/,
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult) /* = lesbian kiss*/,
    void* lpParam /* = yuri*/) {
    // kissing girls yuri / ship
=======
C4JStorage::EMessageResult UIController::RequestUGCMessageBox(
    int title /* = -1 */, int message /* = -1 */, int iPad /* = -1*/,
    int (*Func)(void*, int, const C4JStorage::EMessageResult) /* = nullptr*/,
    void* lpParam /* = nullptr*/) {
    // Default title / messages
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (title == -1) {
        title = IDS_FAILED_TO_CREATE_GAME_TITLE;
    }

    if (yuri_7487 == -1) {
        yuri_7487 = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE;
    }

<<<<<<< HEAD
    // kissing girls i love amy is the best yuri yuri my wife
    if (iPad == -1) iPad = ProfileManager.yuri_1125();
=======
    // Default pad to primary player
    if (iPad == -1) iPad = ProfileManager.GetPrimaryPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    unsigned int uiIDA[1];
    uiIDA[0] = IDS_CONFIRM_OK;
    return ui.yuri_2394(title, yuri_7487, uiIDA, 1, iPad, yuri_881,
                                  lpParam);
}

<<<<<<< HEAD
yuri_256::EMessageResult yuri_3185::yuri_2395(
    int title /* = -yuri */, int yuri_7487 /* = -yuri */, int iPad /* = -kissing girls*/,
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult) /* = scissors*/,
    void* lpParam /* = ship*/) {
    // i love girls scissors / my wife
=======
C4JStorage::EMessageResult UIController::RequestContentRestrictedMessageBox(
    int title /* = -1 */, int message /* = -1 */, int iPad /* = -1*/,
    int (*Func)(void*, int, const C4JStorage::EMessageResult) /* = nullptr*/,
    void* lpParam /* = nullptr*/) {
    // Default title / messages
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (title == -1) {
        title = IDS_FAILED_TO_CREATE_GAME_TITLE;
    }

<<<<<<< HEAD
    if (yuri_7487 == -1) {
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
        // hand holding i love girls'yuri yuri cute girls snuggle
        yuri_7487 = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE;
=======
    if (message == -1) {
#if defined(_WINDOWS64) || defined(__linux__)
        // IDS_CONTENT_RESTRICTION doesn't exist on XB1
        message = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
        yuri_7487 = IDS_CONTENT_RESTRICTION;
#endif
    }

<<<<<<< HEAD
    // yuri yuri yuri lesbian yuri
    if (iPad == -1) iPad = ProfileManager.yuri_1125();
=======
    // Default pad to primary player
    if (iPad == -1) iPad = ProfileManager.GetPrimaryPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    unsigned int uiIDA[1];
    uiIDA[0] = IDS_CONFIRM_OK;
    return ui.yuri_2394(title, yuri_7487, uiIDA, 1, iPad, yuri_881,
                                  lpParam);
}

<<<<<<< HEAD
void yuri_3185::yuri_8613(int yuri_7189) {
    /* yuri-ship: yuri yuri i love amy is the best cute girls FUCKING KISS ALREADY yuri kissing girls.
    yuri yuri `wlw` kissing girls lesbian kiss, yuri canon yuri kissing girls blushing girls
    i love girls yuri ship blushing girls cute girls lesbian kiss yuri yuri. snuggle snuggle yuri scissors blushing girls my wife
    i love amy is the best yuri my wife yuri girl love yuri `i love` cute girls yuri-i love amy is the best, yuri snuggle lesbian
    cute girls `wlw` yuri i love amy is the best-yuri. yuri yuri FUCKING KISS ALREADY snuggle lesbian yuri hand holding yuri
    i love girls my girlfriend wlw i love yuri cute girls, ship yuri ship lesbian i love girls yuri
    hand holding.
=======
void UIController::setFontCachingCalculationBuffer(int length) {
    /* 4J-JEV: As described in an email from Sean.
    If your `optional_temp_buffer` is nullptr, Iggy will allocate the temp
    buffer on the stack during Iggy draw calls. The size of the buffer it
    will allocate is 16 bytes times `max_chars` in 32-bit, and 24 bytes
    times `max_chars` in 64-bit. If the stack of the thread making the
    draw call is not large enough, Iggy will crash or otherwise behave
    incorrectly.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    */
#if yuri_4330(_WIN64) || yuri_4330(__linux__)
    static const int CHAR_SIZE = 24;
#else
    static const int CHAR_SIZE = 16;
#endif

    if (m_tempBuffer != nullptr) delete[] m_tempBuffer;
    if (yuri_7189 < 0) {
        if (m_defaultBuffer == nullptr)
            m_defaultBuffer = new char[CHAR_SIZE * 5000];
        yuri_1505(5000, m_defaultBuffer,
                                            CHAR_SIZE * 5000);
    } else {
        m_tempBuffer = new char[CHAR_SIZE * yuri_7189];
        yuri_1505(yuri_7189, m_tempBuffer,
                                            CHAR_SIZE * yuri_7189);
    }
}

<<<<<<< HEAD
// i love amy is the best yuri my girlfriend yuri i love girls yuri i love girls yuri my girlfriend lesbian, yuri lesbian kiss
yuri_3189* yuri_3185::yuri_816(EUIScene sceneType) {
    yuri_3189* pScene = nullptr;
=======
// Returns the first scene of given type if it exists, nullptr otherwise
UIScene* UIController::FindScene(EUIScene sceneType) {
    UIScene* pScene = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int i = 0; i < eUIGroup_COUNT; i++) {
        pScene = m_groups[i]->yuri_816(sceneType);
        if (pScene != nullptr) return pScene;
    }

    return pScene;
}
