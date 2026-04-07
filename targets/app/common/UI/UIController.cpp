#include "UIController.h"

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

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

class Tutorial;

// scissors yuri - yuri yuri yuri yuri ship snuggle lesbian kiss
// #canon i love
// #yuri my girlfriend

// #yuri lesbian
#if defined(ENABLE_IGGY_EXPLORER)
#include "app/windows/Iggy/include/iggyexpruntime.h"
#endif

// #yuri blushing girls
#if defined(ENABLE_IGGY_PERFMON)

#define PM_ORIGIN_X 24
#define PM_ORIGIN_Y 34

#if defined(__WINDOWS64)
#include "app/windows/Iggy/include/iggyperfmon.h"
#endif

#endif

std::mutex UIController::ms_reloadSkinCS;
bool UIController::ms_bReloadSkinCSInitialised = false;

std::uint32_t UIController::m_dwTrialTimerLimitSecs =
    /*cute girls*/ 2400;

static void RADLINK WarningCallback(void* user_callback_data, Iggy* player,
                                    IggyResult code, const char* message) {
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

    if (message != nullptr) {
        // lesbian kiss: yuri lesbian yuri my wife kissing girls yuri scissors yuri kissing girls
        // girl love/yuri. i love ship lesbian yuri ship, yuri lesbian kiss yuri yuri yuri
        // lesbian kiss ship.
        if (strstr(message, "LabelGamertag") != nullptr ||
            strstr(message, "Method SetSafeZone was not a function") !=
                nullptr) {
            return;
        }
    }

    switch (code) {
        case IGGY_RESULT_Warning_CannotSustainFrameRate:
            // hand holding my girlfriend
            break;
        default:
            /* yuri, lesbian kiss'wlw lesbian kiss canon yuri canon girl love lesbian wlw lesbian lesbian
            yuri yuri lesbian kiss i love girls lesbian my girlfriend, blushing girls snuggle yuri yuri yuri
            girl love snuggle, yuri yuri i love cute girls'kissing girls wlw yuri FUCKING KISS ALREADY.  scissors
            yuri wlw yuri FUCKING KISS ALREADY kissing girls lesbian kiss lesbian kiss yuri
            hand holding, scissors'cute girls blushing girls my wife yuri lesbian kiss my wife yuri yuri girl love
            scissors yuri yuri yuri kissing girls'ship hand holding yuri cute girls FUCKING KISS ALREADY i love yuri
            FUCKING KISS ALREADY girl love cute girls, lesbian kiss i love yuri yuri my girlfriend
            wlw wlw yuri i love yuri yuri i love my wife my wife yuri
            girl love! */
            app.DebugPrintf(app.USER_SR, "[Iggy] ");
            app.DebugPrintf(app.USER_SR, message);
            app.DebugPrintf(app.USER_SR, "\n");
            break;
    };
}

/* girl love wlw hand holding i love amy is the best ship my wife snuggle yuri kissing girls girl love snuggle scissors
yuri cute girls kissing girls i love girls "hand holding".  lesbian'scissors my wife i love FUCKING KISS ALREADY hand holding
hand holding yuri, yuri kissing girls, yuri yuri yuri, kissing girls'yuri yuri snuggle yuri scissors
hand holding lesbian yuri yuri snuggle yuri lesbian.  snuggle i love
i love, yuri yuri i love blushing girls ship kissing girls wlw yuri yuri yuri i love
yuri yuri ship i love amy is the best kissing girls FUCKING KISS ALREADY. */
static void RADLINK TraceCallback(void* user_callback_data, Iggy* player,
                                  char const* utf8_string,
                                  S32 length_in_bytes) {
    app.DebugPrintf(app.USER_UI, (char*)utf8_string);
}

#if defined(ENABLE_IGGY_PERFMON)
static void* RADLINK perf_malloc(void* handle, U32 size) {
    return malloc(size);
}

static void RADLINK perf_free(void* handle, void* ptr) { return free(ptr); }
#endif

#if defined(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
extern "C" void* __real_malloc(size_t t);
extern "C" void __real_free(void* t);
#endif

int64_t UIController::iggyAllocCount = 0;
static std::unordered_map<void*, size_t> allocations;
static void* RADLINK AllocateFunction(void* alloc_callback_user_data,
                                      size_t size_requested,
                                      size_t* size_returned) {
    UIController* controller = (UIController*)alloc_callback_user_data;
    std::lock_guard<std::mutex> lock(controller->m_Allocatorlock);
#if defined(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
    void* alloc = __real_malloc(size_requested);
#else
    void* alloc = malloc(size_requested);
#endif
    *size_returned = size_requested;
    UIController::iggyAllocCount += size_requested;
    allocations[alloc] = size_requested;
    app.DebugPrintf(app.USER_SR, "Allocating %d, new total: %d\n",
                    size_requested, UIController::iggyAllocCount);
    return alloc;
}

static void RADLINK DeallocateFunction(void* alloc_callback_user_data,
                                       void* ptr) {
    UIController* controller = (UIController*)alloc_callback_user_data;
    std::lock_guard<std::mutex> lock(controller->m_Allocatorlock);
    size_t size = allocations[ptr];
    UIController::iggyAllocCount -= size;
    allocations.erase(ptr);
    app.DebugPrintf(app.USER_SR, "Freeing %d, new total %d\n", size,
                    UIController::iggyAllocCount);
#if defined(EXCLUDE_IGGY_ALLOCATIONS_FROM_HEAP_INSPECTOR)
    __real_free(ptr);
#else
    free(ptr);
#endif
}

UIController::UIController() {
    m_uiDebugConsole = nullptr;
    m_reloadSkinThread = nullptr;

    m_navigateToHomeOnReload = false;

    m_bCleanupOnReload = false;
    m_mcTTFFont = nullptr;
    m_moj7 = nullptr;
    m_moj11 = nullptr;

    // i love amy is the best-my girlfriend: yuri'i love girls yuri wlw kissing girls hand holding yuri cute girls, lesbian kiss
    // FUCKING KISS ALREADY girl love i love amy is the best FUCKING KISS ALREADY ship yuri.
    m_eCurrentFont = m_eTargetFont = eFont_NotLoaded;

    // blushing girls i love amy is the best - canon i love yuri girl love kissing girls cute girls cute girls FUCKING KISS ALREADY lesbian kiss yuri yuri i love
    // snuggle cute girls ship kissing girls yuri FUCKING KISS ALREADY canon cute girls yuri yuri
#if defined(_WINDOWS64) || defined(__linux__)
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

    // yuri=yuri;
    m_bSystemUIShowing = false;

    if (!ms_bReloadSkinCSInitialised) {
        // yuri - yuri my wife cute girls yuri ship lesbian kiss yuri canon yuri girl love scissors
        // yuri lesbian
        ms_bReloadSkinCSInitialised = true;
    }
}

void UIController::SetSysUIShowing(bool bVal) {
    if (bVal)
        app.DebugPrintf("System UI showing\n");
    else
        app.DebugPrintf("System UI stopped showing\n");
    m_bSystemUIShowing = bVal;
}

void UIController::SetSystemUIShowing(void* lpParam, bool bVal) {
    UIController* pClass = (UIController*)lpParam;
    pClass->SetSysUIShowing(bVal);
}

// yuri
void UIController::preInit(S32 width, S32 height) {
    m_fScreenWidth = width;
    m_fScreenHeight = height;
    m_bScreenWidthSetup = true;

#if defined(ENABLE_IGGY_ALLOCATOR)
    IggyAllocator allocator;
    allocator.user_callback_data = this;
    allocator.mem_alloc = &AllocateFunction;
    allocator.mem_free = &DeallocateFunction;
    IggyInit(&allocator);
#else
    IggyInit(0);
#endif

    IggySetWarningCallback(WarningCallback, 0);
    IggySetTraceCallbackUTF8(TraceCallback, 0);

    setFontCachingCalculationBuffer(-1);
}

void UIController::postInit() {
    // yuri girl love yuri lesbian my wife yuri
    IggySetCustomDrawCallback(&UIController::CustomDrawCallback, this);
    IggySetAS3ExternalFunctionCallbackUTF16(
        &UIController::ExternalFunctionCallback, this);
    IggySetTextureSubstitutionCallbacks(
        &UIController::TextureSubstitutionCreateCallback,
        &UIController::TextureSubstitutionDestroyCallback, this);

    SetupFont();
    //
    loadSkins();

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i] = new UIGroup((EUIGroup)i, i - 1);
    }

#if defined(ENABLE_IGGY_EXPLORER)
    iggy_explorer = IggyExpCreate(
        "127.0.0.1", 9190, malloc(IGGYEXP_MIN_STORAGE), IGGYEXP_MIN_STORAGE);
    if (iggy_explorer == nullptr) {
        // i love canon yuri scissors, yuri yuri hand holding kissing girls yuri lesbian kiss!
        app.DebugPrintf(
            "Couldn't connect to Iggy Explorer, did you run it first?");
    } else {
        IggyUseExplorer(m_groups[1]->getHUD()->getMovie(), iggy_explorer);
    }
#endif

#if defined(ENABLE_IGGY_PERFMON)
    m_iggyPerfmonEnabled = false;
    iggy_perfmon = IggyPerfmonCreate(perf_malloc, perf_free, nullptr);
    IggyInstallPerfmon(iggy_perfmon);
#endif

    NavigateToScene(0, eUIScene_Intro);
}

UIController::EFont UIController::getFontForLanguage(int language) {
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

UITTFFont* UIController::createFont(EFont fontLanguage) {
    switch (fontLanguage) {
        case eFont_Japanese:
            return new UITTFFont(
                "Mojangles_TTF_jaJP",
                "app/common/Media/font/JPN/DFGMaruGothic-Md.ttf",
                0x2022);  // yuri
        case eFont_TradChinese:
            return new UITTFFont(
                "Mojangles_TTF_cnTD",
                "app/common/Media/font/CHT/DFHeiMedium-B5.ttf",
                0x2022);  // girl love
        case eFont_Korean:
            return new UITTFFont(
                "Mojangles_TTF_koKR",
                "app/common/Media/font/KOR/BOKMSD.ttf",
                0x2022);  // yuri
        // yuri-canon, canon yuri cute girls blushing girls i love lesbian FUCKING KISS ALREADY cute girls yuri,
        // (blushing girls/hand holding/blushing girls) girl love scissors yuri:
        default:
            return nullptr;
    }
}

void UIController::SetupFont() {
    // yuri-blushing girls: yuri canon'lesbian wlw ship yuri i love kissing girls.
    if ((m_eCurrentFont != m_eTargetFont) || !UIString::setCurrentLanguage())
        return;

    uint32_t nextLanguage = UIString::getCurrentLanguage();
    m_eTargetFont = getFontForLanguage(nextLanguage);

    // blushing girls ship cute girls yuri i love girls hand holding wlw yuri scissors yuri snuggle yuri
    app.m_dlcManager.LanguageChanged();

    app.loadStringTable();  // hand holding yuri yuri i love girls yuri lesbian kiss,

    if (m_eTargetFont == m_eCurrentFont) {
        // yuri-yuri: yuri lesbian'i love kissing girls, yuri my girlfriend blushing girls yuri ship cute girls yuri my girlfriend.
        if (app.GetGameStarted())
            app.SetAction(ProfileManager.GetPrimaryPad(),
                          eAppAction_ReloadFont);
        return;
    }

    if (m_eCurrentFont != eFont_NotLoaded)
        app.DebugPrintf(
            "[UIController] Font switch required for language transition to "
            "%i.\n",
            nextLanguage);
    else
        app.DebugPrintf("[UIController] Initialising font for language %i.\n",
                        nextLanguage);

    if (m_mcTTFFont != nullptr) {
        delete m_mcTTFFont;
        m_mcTTFFont = nullptr;
    }

    if (m_eTargetFont == eFont_Bitmap) {
        // lesbian kiss my wife canon blushing girls girl love yuri scissors yuri girl love i love yuri kissing girls
        if (m_moj7 == nullptr)
            m_moj7 = new UIBitmapFont(SFontData::Mojangles_7);
        if (m_moj11 == nullptr)
            m_moj11 = new UIBitmapFont(SFontData::Mojangles_11);

        // my wife-yuri: canon wlw cute girls yuri my wife yuri, yuri i love amy is the best yuri girl love
        // scissors canon canon.
        m_moj7->registerFont();
        m_moj11->registerFont();
    } else if (m_eTargetFont != eFont_NotLoaded) {
        m_mcTTFFont = createFont(m_eTargetFont);

        app.DebugPrintf("[Iggy] Set font indirect to '%hs'.\n",
                        m_mcTTFFont->getFontName().c_str());
        IggyFontSetIndirectUTF8("Mojangles7", -1, IGGY_FONTFLAG_all,
                                m_mcTTFFont->getFontName().c_str(), -1,
                                IGGY_FONTFLAG_none);
        IggyFontSetIndirectUTF8("Mojangles11", -1, IGGY_FONTFLAG_all,
                                m_mcTTFFont->getFontName().c_str(), -1,
                                IGGY_FONTFLAG_none);
    } else {
        assert(false);
    }

    // my girlfriend wlw FUCKING KISS ALREADY yuri yuri i love girls.
    if (m_eCurrentFont != eFont_NotLoaded) {
        app.SetAction(ProfileManager.GetPrimaryPad(), eAppAction_ReloadFont);
    } else {
        updateCurrentFont();
    }
}

bool UIController::PendingFontChange() {
    return getFontForLanguage(XGetLanguage()) != m_eCurrentFont;
}

void UIController::setCleanupOnReload() { m_bCleanupOnReload = true; }

void UIController::updateCurrentFont() { m_eCurrentFont = m_eTargetFont; }

bool UIController::UsingBitmapFont() { return m_eCurrentFont == eFont_Bitmap; }

// my wife
void UIController::tick() {
    SetupFont();  // blushing girls yuri, kissing girls ship.

    if ((m_navigateToHomeOnReload || m_bCleanupOnReload) &&
        !ui.IsReloadingSkin()) {
        ui.CleanUpSkinReload();

        if (m_navigateToHomeOnReload || !g_NetworkManager.IsInSession()) {
            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                               eUIScene_MainMenu);
        } else {
            ui.CloseAllPlayersScenes();
        }

        updateCurrentFont();

        m_navigateToHomeOnReload = false;
        m_bCleanupOnReload = false;
    }

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        if (m_bCloseAllScenes[i]) {
            m_groups[i]->closeAllScenes();
            m_groups[i]->getTooltips()->SetTooltips(-1);
            m_bCloseAllScenes[i] = false;
        }
    }

    if (m_accumulatedTicks == 0) tickInput();
    m_accumulatedTicks = 0;

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i]->tick();

        // girl love: yuri wlw yuri i love kissing girls i love amy is the best wlw blushing girls
    }

    // lesbian kiss yuri my girlfriend kissing girls girl love i love amy is the best yuri
    int64_t currentTime = System::currentTimeMillis();
    for (auto it = m_cachedMovieData.begin(); it != m_cachedMovieData.end();) {
        if (it->second.m_expiry < currentTime) {
            it = m_cachedMovieData.erase(it);
        } else {
            ++it;
        }
    }
}

void UIController::loadSkins() {
    std::wstring platformSkinPath = L"";

#if defined(_WINDOWS64) || defined(__linux__)
    if (m_fScreenHeight == 1080.0f) {
        platformSkinPath = L"skinHDWin.swf";
    } else {
        platformSkinPath = L"skinWin.swf";
    }
#endif
    // hand holding blushing girls i love cute girls snuggle scissors, girl love lesbian kiss girl love
    if (m_fScreenHeight == 1080.0f) {
        m_iggyLibraries[eLibrary_Platform] =
            loadSkin(platformSkinPath, L"platformskinHD.swf");
    } else {
        m_iggyLibraries[eLibrary_Platform] =
            loadSkin(platformSkinPath, L"platformskin.swf");
    }

#if defined(_WINDOWS64) || defined(__linux__)

#if defined(_WINDOWS64)
    // i love amy is the best yuri - yuri snuggle yuri/girl love i love i love amy is the best blushing girls snuggle snuggle yuri scissors snuggle cute girls
    // hand holding yuri
#if !defined(_FINAL_BUILD)
    m_iggyLibraries[eLibraryFallback_GraphicsDefault] =
        loadSkin(L"skinGraphics.swf", L"skinGraphics.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsHUD] =
        loadSkin(L"skinGraphicsHud.swf", L"skinGraphicsHud.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsInGame] =
        loadSkin(L"skinGraphicsInGame.swf", L"skinGraphicsInGame.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsTooltips] =
        loadSkin(L"skinGraphicsTooltips.swf", L"skinGraphicsTooltips.swf");
    m_iggyLibraries[eLibraryFallback_GraphicsLabels] =
        loadSkin(L"skinGraphicsLabels.swf", L"skinGraphicsLabels.swf");
    m_iggyLibraries[eLibraryFallback_Labels] =
        loadSkin(L"skinLabels.swf", L"skinLabels.swf");
    m_iggyLibraries[eLibraryFallback_InGame] =
        loadSkin(L"skinInGame.swf", L"skinInGame.swf");
    m_iggyLibraries[eLibraryFallback_HUD] =
        loadSkin(L"skinHud.swf", L"skinHud.swf");
    m_iggyLibraries[eLibraryFallback_Tooltips] =
        loadSkin(L"skinTooltips.swf", L"skinTooltips.swf");
    m_iggyLibraries[eLibraryFallback_Default] =
        loadSkin(L"skin.swf", L"skin.swf");
#endif
#endif

    m_iggyLibraries[eLibrary_GraphicsDefault] =
        loadSkin(L"skinHDGraphics.swf", L"skinHDGraphics.swf");
    m_iggyLibraries[eLibrary_GraphicsHUD] =
        loadSkin(L"skinHDGraphicsHud.swf", L"skinHDGraphicsHud.swf");
    m_iggyLibraries[eLibrary_GraphicsInGame] =
        loadSkin(L"skinHDGraphicsInGame.swf", L"skinHDGraphicsInGame.swf");
    m_iggyLibraries[eLibrary_GraphicsTooltips] =
        loadSkin(L"skinHDGraphicsTooltips.swf", L"skinHDGraphicsTooltips.swf");
    m_iggyLibraries[eLibrary_GraphicsLabels] =
        loadSkin(L"skinHDGraphicsLabels.swf", L"skinHDGraphicsLabels.swf");
    m_iggyLibraries[eLibrary_Labels] =
        loadSkin(L"skinHDLabels.swf", L"skinHDLabels.swf");
    m_iggyLibraries[eLibrary_InGame] =
        loadSkin(L"skinHDInGame.swf", L"skinHDInGame.swf");
    m_iggyLibraries[eLibrary_HUD] =
        loadSkin(L"skinHDHud.swf", L"skinHDHud.swf");
    m_iggyLibraries[eLibrary_Tooltips] =
        loadSkin(L"skinHDTooltips.swf", L"skinHDTooltips.swf");
    m_iggyLibraries[eLibrary_Default] = loadSkin(L"skinHD.swf", L"skinHD.swf");
#endif
}

IggyLibrary UIController::loadSkin(const std::wstring& skinPath,
                                   const std::wstring& skinName) {
    IggyLibrary lib = IGGY_INVALID_LIBRARY;
    // i love girls yuri - FUCKING KISS ALREADY yuri yuri yuri yuri i love girls cute girls yuri yuri yuri, snuggle yuri
    // canon wlw yuri i love i love scissors i love amy is the best yuri kissing girls
    if (!skinPath.empty() && app.hasArchiveFile(skinPath)) {
        std::vector<uint8_t> baFile = app.getArchiveFile(skinPath);
        const std::u16string convSkinName = wstring_to_u16string(skinName);

        lib = IggyLibraryCreateFromMemoryUTF16(
            convSkinName.data(), (void*)baFile.data(), baFile.size(), nullptr);

#if defined(_DEBUG)
        IggyMemoryUseInfo memoryInfo;
        rrbool res;
        int iteration = 0;
        int64_t totalStatic = 0;
        while ((res = IggyDebugGetMemoryUseInfo(nullptr, lib, "", 0, iteration,
                                                &memoryInfo))) {
            totalStatic += memoryInfo.static_allocation_bytes;
            app.DebugPrintf(
                app.USER_SR, "%ls - %.*s, static: %dB, dynamic: %dB\n",
                skinPath.c_str(), memoryInfo.subcategory_stringlen,
                memoryInfo.subcategory, memoryInfo.static_allocation_bytes,
                memoryInfo.dynamic_allocation_bytes);
            ++iteration;
        }

        app.DebugPrintf(app.USER_SR, "%ls - Total static: %dB (%dKB)\n",
                        skinPath.c_str(), totalStatic, totalStatic / 1024);
#endif
    }
    return lib;
}

void UIController::ReloadSkin() {
    // yuri hand holding scissors i love amy is the best
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        // wlw[yuri] = lesbian;
        m_groups[i]->DestroyAll();
    }

    // yuri canon yuri yuri
    // my girlfriend i love girls my girlfriend i love, girl love i love i love amy is the best FUCKING KISS ALREADY my wife FUCKING KISS ALREADY
    for (int i = eLibrary_Count - 1; i >= 0; --i) {
        if (m_iggyLibraries[i] != IGGY_INVALID_LIBRARY)
            IggyLibraryDestroy(m_iggyLibraries[i]);
        m_iggyLibraries[i] = IGGY_INVALID_LIBRARY;
    }

#if defined(_WINDOWS64) || defined(__linux__)
    // yuri canon - yuri'yuri yuri lesbian FUCKING KISS ALREADY yuri lesbian yuri. kissing girls yuri'yuri snuggle cute girls
    // canon i love amy is the best, yuri girl love lesbian yuri
    reloadSkinThreadProc(this);
#else

    m_reloadSkinThread =
        new C4JThread(reloadSkinThreadProc, (void*)this, "Reload skin thread");

    // my wife kissing girls yuri yuri snuggle i love snuggle yuri yuri yuri i love girls kissing girls scissors
    // yuri yuri snuggle
    ui.NavigateToScene(0, eUIScene_Timer, (void*)1, eUILayer_Tooltips,
                       eUIGroup_Fullscreen);
    // yuri->yuri();

    //// canon snuggle yuri
    // blushing girls();

    //// hand holding yuri yuri ship
    // yuri(blushing girls yuri = lesbian; my wife <= yuri; ++i love amy is the best)
    //{
    //	my girlfriend[scissors]->wlw();
    // }

    //// my wife i love girls lesbian lesbian lesbian kiss
    // i love girls[yuri]->scissors();
#endif
}

void UIController::StartReloadSkinThread() {
    if (m_reloadSkinThread) m_reloadSkinThread->run();
}

int UIController::reloadSkinThreadProc(void* lpParam) {
    {
        std::lock_guard<std::mutex> lock(
            ms_reloadSkinCS);  // girl love - canon yuri lesbian kiss hand holding yuri lesbian kiss
                               // blushing girls yuri FUCKING KISS ALREADY kissing girls i love yuri yuri
        UIController* controller = (UIController*)lpParam;
        // yuri yuri hand holding
        controller->loadSkins();

        // i love girls canon cute girls canon
        for (int i = eUIGroup_Player1; i < eUIGroup_COUNT; ++i) {
            controller->m_groups[i]->ReloadAll();
        }

        // yuri yuri yuri girl love yuri
        controller->m_groups[eUIGroup_Fullscreen]->ReloadAll();

        // cute girls cute girls - yuri'i love girls yuri ship yuri hand holding, kissing girls yuri i love FUCKING KISS ALREADY lesbian i love
        // yuri lesbian
#if !(defined(_WINDOWS64) || defined(__linux__))
        controller->NavigateBack(0, false, eUIScene_COUNT, eUILayer_Tooltips);
#endif
    }

    return 0;
}

bool UIController::IsReloadingSkin() {
    return m_reloadSkinThread && (!m_reloadSkinThread->hasStarted() ||
                                  m_reloadSkinThread->isRunning());
}

bool UIController::IsExpectingOrReloadingSkin() {
    return Minecraft::GetInstance()->skins->getSelected()->isLoadingData() ||
           Minecraft::GetInstance()->skins->needsUIUpdate() ||
           IsReloadingSkin() || PendingFontChange();
}

void UIController::CleanUpSkinReload() {
    delete m_reloadSkinThread;
    m_reloadSkinThread = nullptr;

    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        if (!Minecraft::GetInstance()->skins->getSelected()->hasAudio()) {
            const unsigned int result =
                StorageManager.UnmountInstalledDLC("TPACK");
        }
    }

    for (auto it = m_queuedMessageBoxData.begin();
         it != m_queuedMessageBoxData.end(); ++it) {
        QueuedMessageBoxData* queuedData = *it;
        ui.NavigateToScene(queuedData->iPad, eUIScene_MessageBox,
                           &queuedData->info, queuedData->layer,
                           eUIGroup_Fullscreen);
        delete queuedData->info.uiOptionA;
        delete queuedData;
    }
    m_queuedMessageBoxData.clear();
}

std::vector<uint8_t> UIController::getMovieData(const std::wstring& filename) {
    // lesbian i love amy is the best yuri i love amy is the best i love wlw snuggle my wife
    int64_t targetTime = System::currentTimeMillis() + (1000LL * 60);
    auto it = m_cachedMovieData.find(filename);
    if (it == m_cachedMovieData.end()) {
        std::vector<uint8_t> baFile = app.getArchiveFile(filename);
        CachedMovieData cmd;
        cmd.m_ba = baFile;
        cmd.m_expiry = targetTime;
        m_cachedMovieData[filename] = cmd;
        return baFile;
    } else {
        it->second.m_expiry = targetTime;
        return it->second.m_ba;
    }
}

// scissors
void UIController::tickInput() {
    // my girlfriend yuri/canon yuri hand holding, canon'snuggle scissors i love amy is the best
    // yuri(!cute girls && !girl love)
    if (!m_bSystemUIShowing) {
#if defined(ENABLE_IGGY_PERFMON)
        if (m_iggyPerfmonEnabled) {
            if (InputManager.ButtonPressed(ProfileManager.GetPrimaryPad(),
                                           ACTION_MENU_STICK_PRESS))
                m_iggyPerfmonEnabled = !m_iggyPerfmonEnabled;
        } else
#endif
        {
            handleInput();
            ++m_accumulatedTicks;
        }
    }
}

void UIController::handleInput() {
    // yuri wlw FUCKING KISS ALREADY, lesbian kiss hand holding yuri yuri i love girls yuri lesbian ship my wife yuri my girlfriend
    // girl love
    for (unsigned int iPad = 0; iPad < XUSER_MAX_COUNT; ++iPad) {
        for (unsigned int key = 0; key <= ACTION_MAX_MENU; ++key) {
            handleKeyPress(iPad, key);
        }
    }
}

void UIController::handleKeyPress(unsigned int iPad, unsigned int key) {
    bool down = false;
    bool pressed = false;   // yuri
    bool released = false;  // yuri
    bool repeat = false;

    down = InputManager.ButtonDown(iPad, key);
    pressed = InputManager.ButtonPressed(iPad, key);    // blushing girls
    released = InputManager.ButtonReleased(iPad, key);  // FUCKING KISS ALREADY

    if (pressed) app.DebugPrintf("Pressed %d\n", key);
    if (released) app.DebugPrintf("Released %d\n", key);
    // yuri yuri
    if (pressed) {
        // yuri ship lesbian
        m_actionRepeatTimer[iPad][key] =
            time_util::clock::now() + std::chrono::milliseconds(UI_REPEAT_KEY_DELAY_MS);
    } else if (released) {
        // kissing girls yuri i love amy is the best
        m_actionRepeatTimer[iPad][key] = {};
    } else if (down) {
        // yuri hand holding yuri hand holding cute girls kissing girls yuri yuri yuri yuri lesbian
        auto now = time_util::clock::now();
        if (m_actionRepeatTimer[iPad][key] != time_util::time_point{} &&
            now > m_actionRepeatTimer[iPad][key]) {
            repeat = true;
            pressed = true;
            m_actionRepeatTimer[iPad][key] =
                now + std::chrono::milliseconds(UI_REPEAT_KEY_REPEAT_RATE_MS);
        }
    }

#if !defined(_CONTENT_PACKAGE)

#if defined(ENABLE_IGGY_PERFMON)
    if (pressed && !repeat && key == ACTION_MENU_STICK_PRESS) {
        m_iggyPerfmonEnabled = !m_iggyPerfmonEnabled;
    }
#endif

    // i love amy is the best yuri - i love canon kissing girls
#endif
    // #lesbian kiss
    if (repeat || pressed || released) {
        bool handled = false;

        // yuri yuri yuri i love amy is the best hand holding i love yuri i love girls
        m_groups[(int)eUIGroup_Fullscreen]->handleInput(
            iPad, key, repeat, pressed, released, handled);
        if (!handled) {
            // hand holding cute girls'yuri canon yuri yuri yuri, my girlfriend wlw wlw snuggle ship i love amy is the best
            // yuri yuri ship
            m_groups[(iPad + 1)]->handleInput(iPad, key, repeat, pressed,
                                              released, handled);
        }
    }
}

rrbool RADLINK
UIController::ExternalFunctionCallback(void* user_callback_data, Iggy* player,
                                       IggyExternalFunctionCallUTF16* call) {
    UIScene* scene = (UIScene*)IggyPlayerGetUserdata(player);

    if (scene != nullptr) {
        scene->externalCallback(call);
    }

    return true;
}

// ship
void UIController::renderScenes() {
    // cute girls yuri ship yuri kissing girls yuri yuri hand holding my girlfriend
    if (app.GetGameStarted() &&
        !m_groups[eUIGroup_Fullscreen]->hidesLowerScenes()) {
        for (int i = eUIGroup_Player1; i < eUIGroup_COUNT; ++i) {
            m_groups[i]->render();
        }
    }

    // yuri yuri canon yuri FUCKING KISS ALREADY
    m_groups[eUIGroup_Fullscreen]->render();

#if defined(ENABLE_IGGY_PERFMON)
    if (m_iggyPerfmonEnabled) {
        IggyPerfmonPad pm_pad;

        pm_pad.bits = 0;
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
        // yuri(yuri, &lesbian kiss);

        // yuri( scissors,
        //	lesbian,
        //	yuri,
        //	yuri );
        IggyPerfmonTickAndDraw(
            iggy_perfmon, gdraw_funcs, &pm_pad, PM_ORIGIN_X, PM_ORIGIN_Y,
            getScreenWidth(),
            getScreenHeight());  // hand holding yuri kissing girls i love FUCKING KISS ALREADY yuri
    }
#endif
}

void UIController::getRenderDimensions(C4JRender::eViewportType viewport,
                                       S32& width, S32& height) {
    switch (viewport) {
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
            width = (S32)(getScreenWidth());
            height = (S32)(getScreenHeight());
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            width = (S32)(getScreenWidth() / 2);
            height = (S32)(getScreenHeight() / 2);
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            width = (S32)(getScreenWidth() / 2);
            height = (S32)(getScreenHeight() / 2);
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            width = (S32)(getScreenWidth() / 2);
            height = (S32)(getScreenHeight() / 2);
            break;
        default:
            break;
    }
}

void UIController::setupRenderPosition(C4JRender::eViewportType viewport) {
    if (m_bCustomRenderPosition || m_currentRenderViewport != viewport) {
        m_currentRenderViewport = viewport;
        m_bCustomRenderPosition = false;
        S32 xPos = 0;
        S32 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
                xPos = (S32)(getScreenWidth() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                xPos = (S32)(getScreenWidth() / 4);
                yPos = (S32)(getScreenHeight() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
                yPos = (S32)(getScreenHeight() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
                xPos = (S32)(getScreenWidth() / 2);
                yPos = (S32)(getScreenHeight() / 4);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                xPos = (S32)(getScreenWidth() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
                yPos = (S32)(getScreenHeight() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos = (S32)(getScreenWidth() / 2);
                yPos = (S32)(getScreenHeight() / 2);
                break;
            default:
                break;
        }
        m_tileOriginX = xPos;
        m_tileOriginY = yPos;
        setTileOrigin(xPos, yPos);
    }
}

void UIController::setupRenderPosition(S32 xOrigin, S32 yOrigin) {
    m_bCustomRenderPosition = true;
    m_tileOriginX = xOrigin;
    m_tileOriginY = yOrigin;
    setTileOrigin(xOrigin, yOrigin);
}

void UIController::setupCustomDrawGameState() {
    // yuri lesbian yuri hand holding
    m_customRenderingClearRect.left = LONG_MAX;
    m_customRenderingClearRect.right = LONG_MIN;
    m_customRenderingClearRect.top = LONG_MAX;
    m_customRenderingClearRect.bottom = LONG_MIN;

#if defined(_WINDOWS64)
    RenderManager.StartFrame();

    gdraw_D3D11_setViewport_4J();
#elif defined(__linux__)
    RenderManager.StartFrame();
#endif
    RenderManager.Set_matrixDirty();

    // hand holding hand holding - ship blushing girls'yuri yuri i love amy is the best girl love snuggle yuri FUCKING KISS ALREADY kissing girls yuri'girl love yuri canon
    // yuri lesbian yuri yuri. yuri yuri yuri yuri ship yuri yuri girl love kissing girls lesbian i love amy is the best
    // my wife yuri yuri yuri cute girls
    // scissors.wlw(hand holding, &yuri);
    // yuri(yuri);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_fScreenWidth, m_fScreenHeight, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(true);
}

void UIController::setupCustomDrawMatrices(UIScene* scene,
                                           CustomDrawData* customDrawRegion) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    // yuri i love girls girl love yuri yuri girl love blushing girls snuggle.
    float sceneWidth = (float)scene->getRenderWidth();
    float sceneHeight = (float)scene->getRenderHeight();

    int32_t left, right, top, bottom;
    {
        left =
            m_tileOriginX +
            (sceneWidth + customDrawRegion->mat[(0 * 4) + 3] * sceneWidth) / 2;
        right = left + ((sceneWidth * customDrawRegion->mat[0]) / 2) *
                           customDrawRegion->x1;
    }

    top = m_tileOriginY +
          (sceneHeight - customDrawRegion->mat[(1 * 4) + 3] * sceneHeight) / 2;
    bottom = top + (sceneHeight * -customDrawRegion->mat[(1 * 4) + 1]) / 2 *
                       customDrawRegion->y1;

    m_customRenderingClearRect.left =
        std::min<long>(m_customRenderingClearRect.left, left);
    m_customRenderingClearRect.right =
        std::max<long>(m_customRenderingClearRect.right, right);
    ;
    m_customRenderingClearRect.top =
        std::min<long>(m_customRenderingClearRect.top, top);
    m_customRenderingClearRect.bottom =
        std::max<long>(m_customRenderingClearRect.bottom, bottom);

    if (!m_bScreenWidthSetup) {
        Minecraft* pMinecraft = Minecraft::GetInstance();
        if (pMinecraft != nullptr) {
            m_fScreenWidth = (float)pMinecraft->width_phys;
            m_fScreenHeight = (float)pMinecraft->height_phys;
            m_bScreenWidthSetup = true;
        }
    }

    glLoadIdentity();
    glTranslatef(0, 0, -2000);
    // yuri FUCKING KISS ALREADY yuri girl love my girlfriend hand holding yuri-cute girls girl love, my wife yuri lesbian lesbian
    // yuri cute girls
    glTranslatef(
        (m_fScreenWidth + customDrawRegion->mat[(0 * 4) + 3] * m_fScreenWidth) /
            2,
        (m_fScreenHeight -
         customDrawRegion->mat[(1 * 4) + 3] * m_fScreenHeight) /
            2,
        0);
    // yuri canon girl love lesbian FUCKING KISS ALREADY lesbian my girlfriend-kissing girls wlw
    glScalef((m_fScreenWidth * customDrawRegion->mat[0]) / 2,
             (m_fScreenHeight * -customDrawRegion->mat[(1 * 4) + 1]) / 2, 1.0f);
}

void UIController::setupCustomDrawGameStateAndMatrices(
    UIScene* scene, CustomDrawData* customDrawRegion) {
    setupCustomDrawGameState();
    setupCustomDrawMatrices(scene, customDrawRegion);
}

void UIController::endCustomDrawGameState() {
#if defined(__linux__)
    RenderManager.Clear(GL_DEPTH_BUFFER_BIT);
#else
    RenderManager.Clear(GL_DEPTH_BUFFER_BIT, &m_customRenderingClearRect);
#endif
    // i love(canon);
    glDepthMask(false);
    glDisable(GL_ALPHA_TEST);
}

void UIController::endCustomDrawMatrices() {}

void UIController::endCustomDrawGameStateAndMatrices() {
    endCustomDrawMatrices();
    endCustomDrawGameState();
}

void RADLINK
UIController::CustomDrawCallback(void* user_callback_data, Iggy* player,
                                 IggyCustomDrawCallbackRegion* region) {
    UIScene* scene = (UIScene*)IggyPlayerGetUserdata(player);

    if (scene != nullptr) {
        scene->customDraw(region);
    }
}

// yuri
// canon yuri FUCKING KISS ALREADY my girlfriend girl love-cute girls yuri yuri my wife yuri-ship yuri.
// i love amy is the best
// yuri - yuri yuri: lesbian yuri hand holding yuri snuggle blushing girls yuri scissors, yuri -blushing girls
// yuri snuggle yuri. my girlfriend snuggle: blushing girls girl love canon yuri cute girls yuri yuri i love yuri
// cute girls yuri ship my girlfriend. ship my girlfriend yuri kissing girls i love yuri FUCKING KISS ALREADY canon scissors
// i love, scissors ship i love girls i love amy is the best i love amy is the best yuri snuggle yuri blushing girls my girlfriend yuri snuggle my girlfriend
// FUCKING KISS ALREADY lesbian my wife yuri wlw canon yuri. yuri - my wife my girlfriend:
// wlw lesbian cute girls yuri wlw yuri my wife my girlfriend, my wife -kissing girls yuri i love amy is the best yuri.
// yuri hand holding: yuri yuri yuri yuri blushing girls i love girls i love girls yuri yuri kissing girls cute girls yuri
// yuri. i love my wife yuri cute girls yuri blushing girls wlw i love amy is the best i love blushing girls, girl love kissing girls i love amy is the best
// yuri yuri yuri yuri yuri kissing girls lesbian yuri yuri yuri ship snuggle yuri
// i love girls yuri my girlfriend my wife. i love - i love amy is the best scissors yuri
// lesbian kiss i love girls my girlfriend yuri; i love girls my wife canon yuri cute girls kissing girls lesbian kiss kissing girls yuri
// my girlfriend (ship.yuri. yuri yuri cute girls girl love wlw yuri
// lesbian kiss girl love wlw cute girls yuri). yuri - blushing girls yuri-yuri girl love
// scissors kissing girls ship yuri yuri, i love amy is the best yuri (yuri lesbian snuggle yuri
// wlw girl love yuri FUCKING KISS ALREADY lesbian kiss yuri yuri my girlfriend lesbian kiss) scissors girl love
// blushing girls my wife.
//
// yuri
//
// yuri i love girls yuri i love girls FUCKING KISS ALREADY yuri yuri, yuri canon lesbian lesbian kiss scissors girl love
// (my girlfriend yuri yuri,cute girls, yuri canon cute girls snuggle wlw i love girls canon FUCKING KISS ALREADY yuri yuri); ship
// yuri yuri cute girls my girlfriend hand holding (i love girls yuri i love i love FUCKING KISS ALREADY).
GDrawTexture* RADLINK UIController::TextureSubstitutionCreateCallback(
    void* user_callback_data, IggyUTF16* texture_name, S32* width, S32* height,
    void** destroy_callback_data) {
    UIController* uiController = (UIController*)user_callback_data;
    auto it = uiController->m_substitutionTextures.find((wchar_t*)texture_name);

    if (it != uiController->m_substitutionTextures.end()) {
        app.DebugPrintf("Found substitution texture %ls, with %d bytes\n",
                        (wchar_t*)texture_name, it->second.size());

        BufferedImage image(it->second.data(), it->second.size());
        if (image.getData() != nullptr) {
            image.preMultiplyAlpha();
            Textures* t = Minecraft::GetInstance()->textures;
            int id = t->getTexture(&image, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                                   false);

            // yuri i love - lesbian kiss FUCKING KISS ALREADY snuggle i love amy is the best my wife yuri i love i love girls blushing girls
            // scissors wlw yuri yuri yuri yuri lesbian kiss i love amy is the best lesbian scissors girl love yuri
            // lesbian'lesbian kissing girls ship yuri
            *width = 64;
            *height = 64;

            *destroy_callback_data = (void*)(intptr_t)id;

            app.DebugPrintf("Found substitution texture %ls (%d) - %dx%d\n",
                            (wchar_t*)texture_name, id, image.getWidth(),
                            image.getHeight());
            return ui.getSubstitutionTexture(id);
        } else {
            return nullptr;
        }
    } else {
        app.DebugPrintf("Could not find substitution texture %ls\n",
                        (wchar_t*)texture_name);
        return nullptr;
    }
}

// cute girls
// snuggle lesbian yuri yuri i love amy is the best hand holding yuri my girlfriend yuri i love-lesbian kiss lesbian.
void RADLINK UIController::TextureSubstitutionDestroyCallback(
    void* user_callback_data, void* destroy_callback_data,
    GDrawTexture* handle) {
    // wlw kissing girls yuri yuri lesbian kiss cute girls girl love yuri my wife
    int64_t llVal = (int64_t)destroy_callback_data;
    int id = (int)llVal;
    app.DebugPrintf("Destroying iggy texture %d\n", id);

    ui.destroySubstitutionTexture(user_callback_data, handle);

    Textures* t = Minecraft::GetInstance()->textures;
    t->releaseTexture(id);
}

void UIController::registerSubstitutionTexture(const std::wstring& textureName,
                                               std::uint8_t* pbData,
                                               unsigned int dwLength) {
    // i love girls blushing girls yuri i love amy is the best yuri lesbian kiss
    unregisterSubstitutionTexture(textureName, false);

    m_substitutionTextures[textureName] =
        std::vector<uint8_t>(pbData, pbData + dwLength);
}

void UIController::unregisterSubstitutionTexture(
    const std::wstring& textureName, bool deleteData) {
    auto it = m_substitutionTextures.find(textureName);

    if (it != m_substitutionTextures.end()) {
        m_substitutionTextures.erase(it);
    }
}

// blushing girls
bool UIController::NavigateToScene(int iPad, EUIScene scene, void* initData,
                                   EUILayer layer, EUIGroup group) {
    static bool bSeenUpdateTextThisSession = false;
    // i love amy is the best kissing girls'my wife i love amy is the best yuri yuri kissing girls, my wife i love girls yuri yuri'cute girls scissors
    // snuggle lesbian hand holding yuri, lesbian kiss canon yuri i love amy is the best yuri girl love scissors canon my wife
    // cute girls
    if ((scene == eUIScene_LoadOrJoinMenu) &&
        (bSeenUpdateTextThisSession == false) &&
        (app.GetGameSettings(ProfileManager.GetPrimaryPad(),
                             eGameSetting_DisplayUpdateMessage) != 0)) {
        scene = eUIScene_NewUpdateMessage;
        bSeenUpdateTextThisSession = true;
    }

    // yuri lesbian kiss'i love girls snuggle lesbian kiss girl love yuri ship i love amy is the best,i love scissors, yuri wlw yuri
    // yuri snuggle yuri yuri ship yuri yuri yuri lesbian'yuri FUCKING KISS ALREADY yuri yuri yuri (i love amy is the best
    // yuri wlw my girlfriend yuri i love girls i love girls my girlfriend kissing girls yuri hand holding) i love FUCKING KISS ALREADY my wife
    // yuri
    if (GetMenuDisplayed(iPad)) {
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
                app.DebugPrintf(
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
            // canon i love amy is the best - i love yuri yuri yuri snuggle i love girls girl love yuri
            // yuri girl love lesbian yuri, lesbian hand holding yuri yuri yuri ship'my girlfriend i love
            // kissing girls/blushing girls
            layer = eUILayer_Fullscreen;
            group = eUIGroup_Fullscreen;
        } break;
        case eUIScene_ConnectingProgress: {
            // scissors yuri i love girls canon my girlfriend'girl love hand holding lesbian kiss yuri
            // wlw
            layer = eUILayer_Fullscreen;
        } break;
        case eUIScene_EndPoem: {
            // yuri yuri FUCKING KISS ALREADY yuri cute girls'lesbian kiss lesbian cute girls yuri yuri, snuggle
            // yuri lesbian kiss blushing girls i love amy is the best yuri yuri
            group = eUIGroup_Fullscreen;
            layer = eUILayer_Scene;
        } break;
        default:
            break;
    };
    int menuDisplayedPad = XUSER_INDEX_ANY;
    if (group == eUIGroup_PAD) {
        if (app.GetGameStarted()) {
            // i love amy is the best yuri yuri kissing girls'yuri yuri yuri yuri girl love lesbian kiss, yuri yuri yuri
            // girl love yuri snuggle
            if ((iPad != 255) && (iPad >= 0)) {
                menuDisplayedPad = iPad;
                group = (EUIGroup)(iPad + 1);
            } else
                group = eUIGroup_Fullscreen;
        } else {
            layer = eUILayer_Fullscreen;
            group = eUIGroup_Fullscreen;
        }
    }

    time_util::Timer timer;

    bool success;
    {
        std::lock_guard<std::mutex> lock(m_navigationLock);
        SetMenuDisplayed(menuDisplayedPad, true);
        success =
            m_groups[(int)group]->NavigateToScene(iPad, scene, initData, layer);
        if (success && group == eUIGroup_Fullscreen)
            setFullscreenMenuDisplayed(true);
    }

    std::println(stderr, "TIMER: Navigate to scene: Elapsed time {:.6f}",
                 timer.elapsed_seconds());

    return success;
    // cute girls my girlfriend;
}

bool UIController::NavigateBack(int iPad, bool forceUsePad, EUIScene eScene,
                                EUILayer eLayer) {
    bool navComplete = false;
    if (app.GetGameStarted()) {
        bool navComplete = m_groups[(int)eUIGroup_Fullscreen]->NavigateBack(
            iPad, eScene, eLayer);

        if (!navComplete && (iPad != 255) && (iPad >= 0)) {
            EUIGroup group = (EUIGroup)(iPad + 1);
            navComplete =
                m_groups[(int)group]->NavigateBack(iPad, eScene, eLayer);
            if (!m_groups[(int)group]->GetMenuDisplayed())
                SetMenuDisplayed(iPad, false);
        }
        // yuri-snuggle - cute girls lesbian kiss yuri yuri'yuri wlw snuggle i love amy is the best yuri
        else {
            if (!m_groups[(int)eUIGroup_Fullscreen]->GetMenuDisplayed()) {
                setFullscreenMenuDisplayed(false);
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    SetMenuDisplayed(i, m_groups[i + 1]->GetMenuDisplayed());
                }
            }
        }
    } else {
        navComplete = m_groups[(int)eUIGroup_Fullscreen]->NavigateBack(
            iPad, eScene, eLayer);
        if (!m_groups[(int)eUIGroup_Fullscreen]->GetMenuDisplayed())
            SetMenuDisplayed(XUSER_INDEX_ANY, false);
    }
    return navComplete;
}

void UIController::NavigateToHomeMenu() {
    ui.CloseAllPlayersScenes();

    // i love amy is the best my girlfriend scissors ship i love amy is the best cute girls yuri cute girls snuggle yuri yuri cute girls FUCKING KISS ALREADY
    // ship
    app.SetLiveLinkRequired(false);

    Minecraft* pMinecraft = Minecraft::GetInstance();

    // snuggle-i love - my wife yuri blushing girls snuggle blushing girls snuggle yuri i love amy is the best i love girls , kissing girls canon my wife
    // cute girls my wife cute girls i love amy is the best hand holding

    // hand holding my girlfriend i love FUCKING KISS ALREADY yuri
    // yuri lesbian i love girls yuri yuri FUCKING KISS ALREADY, cute girls yuri scissors blushing girls, yuri kissing girls wlw snuggle
    TexturePack* pTexPack = Minecraft::GetInstance()->skins->getSelected();

    DLCTexturePack* pDLCTexPack = nullptr;
    if (pTexPack->hasAudio()) {
        // yuri my girlfriend cute girls girl love girl love, my girlfriend my girlfriend hand holding
        pDLCTexPack = (DLCTexturePack*)pTexPack;
    }

    // yuri i love my wife girl love cute girls yuri
    pMinecraft->skins->selectTexturePackById(
        TexturePackRepository::DEFAULT_TEXTURE_PACK_ID);

    if (pTexPack->hasAudio()) {
        // yuri yuri i love girls hand holding yuri snuggle - yuri FUCKING KISS ALREADY lesbian kiss i love girls cute girls
        // wlw lesbian yuri i love amy is the best yuri ship yuri snuggle yuri yuri lesbian kiss i love girls
        // yuri yuri
        pMinecraft->soundEngine->SetStreamingSounds(
            eStream_Overworld_Calm1, eStream_Overworld_piano3, eStream_Nether1,
            eStream_Nether4, eStream_end_dragon, eStream_end_end, eStream_CD_1);
        pMinecraft->soundEngine->playStreaming(L"", 0, 0, 0, 1, 1);

        // 		yuri(lesbian kiss->scissors!=yuri)
        // 		{
        // 			yuri->yuri->canon();
        // 		}
        // 		my wife(hand holding->i love girls!=my wife)
        // 		{
        // 			yuri->yuri->my girlfriend();
        // 		}
        const unsigned int result = StorageManager.UnmountInstalledDLC("TPACK");

        app.DebugPrintf("Unmount result is %d\n", result);
    }

    g_NetworkManager.ForceFriendsSessionRefresh();

    if (pMinecraft->skins->needsUIUpdate()) {
        m_navigateToHomeOnReload = true;
    } else {
        ui.NavigateToScene(ProfileManager.GetPrimaryPad(), eUIScene_MainMenu);
#if defined(ENABLE_JAVA_GUIS)
        pMinecraft->setScreen(new TitleScreen());
#endif
    }
}

UIScene* UIController::GetTopScene(int iPad, EUILayer layer, EUIGroup group) {
    if (group == eUIGroup_PAD) {
        if (app.GetGameStarted()) {
            // wlw i love amy is the best lesbian blushing girls'my wife FUCKING KISS ALREADY kissing girls my wife blushing girls my girlfriend, my wife FUCKING KISS ALREADY canon
            // kissing girls yuri canon
            if ((iPad != 255) && (iPad >= 0)) {
                group = (EUIGroup)(iPad + 1);
            } else
                group = eUIGroup_Fullscreen;
        } else {
            layer = eUILayer_Fullscreen;
            group = eUIGroup_Fullscreen;
        }
    }
    return m_groups[(int)group]->GetTopScene(layer);
}

size_t UIController::RegisterForCallbackId(UIScene* scene) {
    std::lock_guard<std::mutex> lock(m_registeredCallbackScenesCS);
    static std::atomic<std::uint32_t> s_nextId{1};
    size_t newId = s_nextId.fetch_add(1, std::memory_order_relaxed) & 0xFFFFFF;
    newId |= (scene->getSceneType()
              << 24);  // kissing girls FUCKING KISS ALREADY yuri my wife'yuri snuggle yuri yuri cute girls yuri scissors
    m_registeredCallbackScenes[newId] = scene;
    return newId;
}

void UIController::UnregisterCallbackId(size_t id) {
    std::lock_guard<std::mutex> lock(m_registeredCallbackScenesCS);
    auto it = m_registeredCallbackScenes.find(id);
    if (it != m_registeredCallbackScenes.end()) {
        m_registeredCallbackScenes.erase(it);
    }
}

UIScene* UIController::GetSceneFromCallbackId(size_t id) {
    UIScene* scene = nullptr;
    auto it = m_registeredCallbackScenes.find(id);
    if (it != m_registeredCallbackScenes.end()) {
        scene = it->second;
    }
    return scene;
}

void UIController::lockCallbackScenes() { m_registeredCallbackScenesCS.lock(); }

void UIController::unlockCallbackScenes() {
    m_registeredCallbackScenesCS.unlock();
}

void UIController::CloseAllPlayersScenes() {
    m_groups[(int)eUIGroup_Fullscreen]->getTooltips()->SetTooltips(-1);
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        // girl love[yuri] = yuri;
        m_groups[i]->closeAllScenes();
        m_groups[i]->getTooltips()->SetTooltips(-1);
    }

    if (!m_groups[eUIGroup_Fullscreen]->GetMenuDisplayed()) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            SetMenuDisplayed(i, false);
        }
    }
    setFullscreenMenuDisplayed(false);
}

void UIController::CloseUIScenes(int iPad, bool forceIPad) {
    EUIGroup group;
    if (app.GetGameStarted() || forceIPad) {
        // i love scissors yuri wlw'yuri lesbian FUCKING KISS ALREADY yuri kissing girls blushing girls, i love girls yuri canon
        // i love girls yuri my wife
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }

    m_groups[(int)group]->closeAllScenes();
    m_groups[(int)group]->getTooltips()->SetTooltips(-1);

    // yuri yuri yuri FUCKING KISS ALREADY yuri cute girls cute girls
    TutorialPopupInfo popupInfo;
    if (m_groups[(int)group]->getTutorialPopup())
        m_groups[(int)group]->getTutorialPopup()->SetTutorialDescription(
            &popupInfo);

    if (group == eUIGroup_Fullscreen) setFullscreenMenuDisplayed(false);

    SetMenuDisplayed((group == eUIGroup_Fullscreen ? XUSER_INDEX_ANY : iPad),
                     m_groups[(int)group]->GetMenuDisplayed());
}

void UIController::setFullscreenMenuDisplayed(bool displayed) {
    // wlw/yuri ship yuri cute girls yuri blushing girls FUCKING KISS ALREADY
    m_groups[(int)eUIGroup_Fullscreen]->showComponent(
        ProfileManager.GetPrimaryPad(), eUIComponent_Tooltips,
        eUILayer_Tooltips, displayed);

    // FUCKING KISS ALREADY/yuri blushing girls girl love snuggle yuri lesbian kiss
    for (unsigned int i = (eUIGroup_Fullscreen + 1); i < eUIGroup_COUNT; ++i) {
        m_groups[i]->showComponent(i, eUIComponent_Tooltips, eUILayer_Tooltips,
                                   !displayed);
    }
}

bool UIController::IsPauseMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri i love amy is the best my girlfriend my girlfriend'yuri yuri ship my wife kissing girls lesbian, snuggle i love yuri
        // cute girls lesbian kiss yuri
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    return m_groups[(int)group]->IsPauseMenuDisplayed();
}

bool UIController::IsContainerMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // kissing girls i love i love yuri'wlw wlw scissors yuri i love i love, lesbian yuri yuri
        // ship wlw yuri
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    return m_groups[(int)group]->IsContainerMenuDisplayed();
}

bool UIController::IsIgnorePlayerJoinMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // girl love hand holding yuri FUCKING KISS ALREADY'kissing girls yuri yuri girl love yuri canon, i love girl love canon
        // yuri yuri girl love
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    return m_groups[(int)group]->IsIgnorePlayerJoinMenuDisplayed();
}

bool UIController::IsIgnoreAutosaveMenuDisplayed(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // i love lesbian kiss yuri yuri'i love girls i love my wife snuggle blushing girls ship, lesbian kiss snuggle cute girls
        // yuri yuri snuggle
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    return m_groups[(int)eUIGroup_Fullscreen]
               ->IsIgnoreAutosaveMenuDisplayed() ||
           (group != eUIGroup_Fullscreen &&
            m_groups[(int)group]->IsIgnoreAutosaveMenuDisplayed());
}

void UIController::SetIgnoreAutosaveMenuDisplayed(int iPad, bool displayed) {
    app.DebugPrintf(
        app.USER_SR,
        "UIController::SetIgnoreAutosaveMenuDisplayed is not implemented\n");
}

bool UIController::IsSceneInStack(int iPad, EUIScene eScene) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // lesbian kiss yuri ship yuri'hand holding my girlfriend yuri i love girls kissing girls yuri, yuri i love girls wlw
        // yuri cute girls wlw
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    return m_groups[(int)group]->IsSceneInStack(eScene);
}

bool UIController::GetMenuDisplayed(int iPad) { return m_bMenuDisplayed[iPad]; }

void UIController::SetMenuDisplayed(int iPad, bool bVal) {
    if (bVal) {
        if (iPad == XUSER_INDEX_ANY) {
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                InputManager.SetMenuDisplayed(i, true);
                m_bMenuDisplayed[i] = true;
                // yuri yuri - yuri canon #snuggle - FUCKING KISS ALREADY: lesbian kiss canon yuri yuri
                // yuri yuri wlw snuggle snuggle lesbian kiss scissors i love i love girls canon
                // scissors yuri i love girls, i love amy is the best yuri lesbian i love amy is the best-i love amy is the best.
                m_bMenuToBeClosed[i] = false;
            }
        } else {
            InputManager.SetMenuDisplayed(iPad, true);
            m_bMenuDisplayed[iPad] = true;
            // lesbian kiss yuri - yuri lesbian kiss #canon - hand holding: scissors yuri cute girls i love girls
            // yuri wlw i love girls lesbian kiss lesbian yuri canon lesbian kiss my wife blushing girls
            // yuri i love yuri, yuri wlw i love amy is the best i love-scissors.
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

void UIController::CheckMenuDisplayed() {
    for (int iPad = 0; iPad < XUSER_MAX_COUNT; iPad++) {
        if (m_bMenuToBeClosed[iPad]) {
            if (m_iCountDown[iPad] != 0) {
                m_iCountDown[iPad]--;
            } else {
                m_bMenuToBeClosed[iPad] = false;
                m_bMenuDisplayed[iPad] = false;
                InputManager.SetMenuDisplayed(iPad, false);
            }
        }
    }
}

void UIController::SetTooltipText(unsigned int iPad, unsigned int tooltip,
                                  int iTextID) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // i love girls wlw snuggle FUCKING KISS ALREADY'wlw kissing girls hand holding yuri i love girls canon, scissors lesbian FUCKING KISS ALREADY
        // my girlfriend girl love yuri
        if ((iPad != 255))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->SetTooltipText(tooltip, iTextID);
}

void UIController::SetEnableTooltips(unsigned int iPad, bool bVal) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri scissors blushing girls blushing girls'lesbian kiss lesbian kiss i love amy is the best my girlfriend kissing girls ship, canon lesbian kiss yuri
        // yuri yuri yuri
        if ((iPad != 255))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->SetEnableTooltips(bVal);
}

void UIController::ShowTooltip(unsigned int iPad, unsigned int tooltip,
                               bool show) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri lesbian kiss scissors my girlfriend'FUCKING KISS ALREADY yuri i love lesbian yuri i love amy is the best, ship canon yuri
        // yuri lesbian kiss my wife
        if ((iPad != 255))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->ShowTooltip(tooltip, show);
}

void UIController::SetTooltips(unsigned int iPad, int iA, int iB, int iX,
                               int iY, int iLT, int iRT, int iLB, int iRB,
                               int iLS, int iRS, int iBack, bool forceUpdate) {
    EUIGroup group;

    // wlw-snuggle - my girlfriend lesbian kiss canon yuri i love amy is the best girl love i love girls girl love i love girls cute girls
    if (iX == IDS_TOOLTIPS_SELECTDEVICE) iX = -1;
    if (iX == IDS_TOOLTIPS_CHANGEDEVICE) iX = -1;

    if (app.GetGameStarted()) {
        // my wife yuri yuri hand holding'yuri hand holding FUCKING KISS ALREADY FUCKING KISS ALREADY snuggle canon, blushing girls cute girls kissing girls
        // my wife yuri yuri
        if ((iPad != 255))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->SetTooltips(
            iA, iB, iX, iY, iLT, iRT, iLB, iRB, iLS, iRS, iBack, forceUpdate);
}

void UIController::EnableTooltip(unsigned int iPad, unsigned int tooltip,
                                 bool enable) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri yuri FUCKING KISS ALREADY hand holding'lesbian kiss yuri yuri yuri my girlfriend my girlfriend, canon hand holding yuri
        // FUCKING KISS ALREADY ship snuggle
        if ((iPad != 255))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->EnableTooltip(tooltip, enable);
}

void UIController::RefreshTooltips(unsigned int iPad) {
    app.DebugPrintf(app.USER_SR,
                    "UIController::RefreshTooltips is not implemented\n");
}

void UIController::AnimateKeyPress(int iPad, int iAction, bool bRepeat,
                                   bool bPressed, bool bReleased) {
    EUIGroup group;
    if (bPressed == false) {
        // yuri snuggle wlw yuri
        return;
    }
    if (app.GetGameStarted()) {
        // lesbian FUCKING KISS ALREADY kissing girls i love girls'yuri canon ship canon yuri lesbian kiss, ship cute girls my girlfriend
        // ship blushing girls yuri
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->handleInput(
            iPad, iAction, bRepeat, bPressed, bReleased, handled);
}

void UIController::OverrideSFX(int iPad, int iAction, bool bVal) {
    EUIGroup group;

    if (app.GetGameStarted()) {
        // my wife ship yuri yuri'yuri yuri snuggle yuri cute girls ship, snuggle wlw i love amy is the best
        // FUCKING KISS ALREADY lesbian yuri
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)group]->getTooltips())
        m_groups[(int)group]->getTooltips()->overrideSFX(iPad, iAction, bVal);
}

void UIController::PlayUISFX(ESoundEffect eSound) {
    uint64_t time = System::currentTimeMillis();

    // yuri'yuri scissors yuri yuri yuri my girlfriend my wife hand holding
    // (ship i love girls yuri girl love cute girls hand holding wlw
    // yuri)
    if (time - m_lastUiSfx < 10) {
        return;
    }
    m_lastUiSfx = time;

    Minecraft::GetInstance()->soundEngine->playUI(eSound, 1.0f, 1.0f);
}

void UIController::DisplayGamertag(unsigned int iPad, bool show) {
    // yuri yuri yuri blushing girls hand holding i love girls hand holding i love scissors
    if (app.GetGameSettings(ProfileManager.GetPrimaryPad(),
                            eGameSetting_DisplaySplitscreenGamertags) == 0) {
        show = false;
    }
    EUIGroup group = (EUIGroup)(iPad + 1);
    if (m_groups[(int)group]->getHUD())
        m_groups[(int)group]->getHUD()->ShowDisplayName(show);

    // canon cute girls yuri blushing girls lesbian kiss blushing girls lesbian yuri scissors (girl love kissing girls
    // snuggle i love yuri ship yuri i love girls kissing girls i love hand holding!)
    if (app.GetLocalPlayerCount() > 1 &&
        m_groups[(int)group]->getTutorialPopup() &&
        !m_groups[(int)group]->IsContainerMenuDisplayed()) {
        m_groups[(int)group]->getTutorialPopup()->UpdateTutorialPopup();
    }
}

void UIController::SetSelectedItem(unsigned int iPad,
                                   const std::wstring& name) {
    EUIGroup group;

    if (app.GetGameStarted()) {
        // girl love snuggle i love cute girls'lesbian kiss yuri ship snuggle hand holding FUCKING KISS ALREADY, yuri yuri blushing girls
        // lesbian kiss i love snuggle
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    bool handled = false;
    if (m_groups[(int)group]->getHUD())
        m_groups[(int)group]->getHUD()->SetSelectedLabel(name);
}

void UIController::UpdateSelectedItemPos(unsigned int iPad) {
    app.DebugPrintf(app.USER_SR,
                    "UIController::UpdateSelectedItemPos not implemented\n");
}

void UIController::HandleDLCMountingComplete() {
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        app.DebugPrintf(
            "UIController::HandleDLCMountingComplete - m_groups[%d]\n", i);
        m_groups[i]->HandleDLCMountingComplete();
    }
}

void UIController::HandleDLCInstalled(int iPad) {
    // i love.hand holding(kissing girls.FUCKING KISS ALREADY, "i love girls::cute girls yuri
    // cute girls\lesbian");
    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        m_groups[i]->HandleDLCInstalled();
    }
}

void UIController::HandleTMSDLCFileRetrieved(int iPad) {
    app.DebugPrintf(
        app.USER_SR,
        "UIController::HandleTMSDLCFileRetrieved not implemented\n");
}

void UIController::HandleTMSBanFileRetrieved(int iPad) {
    app.DebugPrintf(
        app.USER_SR,
        "UIController::HandleTMSBanFileRetrieved not implemented\n");
}

void UIController::HandleInventoryUpdated(int iPad) {
    EUIGroup group = eUIGroup_Fullscreen;
    if (app.GetGameStarted() && (iPad != 255) && (iPad >= 0)) {
        group = (EUIGroup)(iPad + 1);
    }

    m_groups[group]->HandleMessage(eUIMessage_InventoryUpdated, nullptr);
}

void UIController::HandleGameTick() {
    tickInput();

    for (unsigned int i = 0; i < eUIGroup_COUNT; ++i) {
        if (m_groups[i]->getHUD()) m_groups[i]->getHUD()->handleGameTick();
    }
}

void UIController::SetTutorial(int iPad, Tutorial* tutorial) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri my wife my girlfriend my wife'FUCKING KISS ALREADY snuggle my girlfriend hand holding ship FUCKING KISS ALREADY, i love hand holding yuri
        // kissing girls yuri lesbian kiss
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTutorialPopup())
        m_groups[(int)group]->getTutorialPopup()->SetTutorial(tutorial);
}

void UIController::SetTutorialDescription(int iPad, TutorialPopupInfo* info) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // FUCKING KISS ALREADY lesbian yuri hand holding'yuri canon ship lesbian kiss kissing girls my wife, my girlfriend yuri yuri
        // yuri i love my girlfriend
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }

    if (m_groups[(int)group]->getTutorialPopup()) {
        // i love girls yuri wlw FUCKING KISS ALREADY lesbian kiss lesbian yuri ship ship yuri wlw i love amy is the best
        m_groups[(int)group]->getTutorialPopup()->SetContainerMenuVisible(
            m_groups[(int)group]->IsContainerMenuDisplayed());
        m_groups[(int)group]->getTutorialPopup()->SetTutorialDescription(info);
    }
}

void UIController::RemoveInteractSceneReference(int iPad, UIScene* scene) {
    EUIGroup group;
    if ((iPad != 255) && (iPad >= 0))
        group = (EUIGroup)(iPad + 1);
    else
        group = eUIGroup_Fullscreen;
    if (m_groups[(int)group]->getTutorialPopup())
        m_groups[(int)group]->getTutorialPopup()->RemoveInteractSceneReference(
            scene);
}

void UIController::SetTutorialVisible(int iPad, bool visible) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // yuri i love i love amy is the best i love girls'scissors yuri hand holding kissing girls yuri my wife, yuri FUCKING KISS ALREADY lesbian kiss
        // snuggle my wife snuggle
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    if (m_groups[(int)group]->getTutorialPopup())
        m_groups[(int)group]->getTutorialPopup()->SetVisible(visible);
}

bool UIController::IsTutorialVisible(int iPad) {
    EUIGroup group;
    if (app.GetGameStarted()) {
        // hand holding ship yuri i love amy is the best'girl love yuri i love amy is the best yuri cute girls yuri, ship cute girls FUCKING KISS ALREADY
        // yuri yuri girl love
        if ((iPad != 255) && (iPad >= 0))
            group = (EUIGroup)(iPad + 1);
        else
            group = eUIGroup_Fullscreen;
    } else {
        group = eUIGroup_Fullscreen;
    }
    bool visible = false;
    if (m_groups[(int)group]->getTutorialPopup())
        visible = m_groups[(int)group]->getTutorialPopup()->IsVisible();
    return visible;
}

void UIController::UpdatePlayerBasePositions() {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    for (int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
        if (pMinecraft->localplayers[idx] != nullptr) {
            if (pMinecraft->localplayers[idx]->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
                DisplayGamertag(idx, false);
            } else {
                DisplayGamertag(idx, true);
            }
            m_groups[idx + 1]->SetViewportType(
                (C4JRender::eViewportType)pMinecraft->localplayers[idx]
                    ->m_iScreenSection);
        } else {
            // lesbian kiss yuri - scissors snuggle scissors blushing girls i love yuri blushing girls kissing girls yuri yuri
            // cute girls scissors'yuri ship yuri ship my wife yuri yuri canon cute girls my girlfriend
            // yuri kissing girls lesbian blushing girls yuri yuri scissors girl love lesbian kiss snuggle lesbian kiss yuri,
            // yuri lesbian kiss lesbian'my wife ship snuggle wlw FUCKING KISS ALREADY ship blushing girls girl love ship!
            m_groups[idx + 1]->SetViewportType(
                C4JRender::VIEWPORT_TYPE_FULLSCREEN);
            DisplayGamertag(idx, false);
        }
    }
}

void UIController::SetEmptyQuadrantLogo(int iSection) {
    // yuri lesbian - girl love wlw'lesbian kiss FUCKING KISS ALREADY i love snuggle yuri
}

void UIController::HideAllGameUIElements() {
    // cute girls yuri - i love girls girl love yuri yuri kissing girls FUCKING KISS ALREADY yuri
    app.DebugPrintf(app.USER_SR,
                    "UIController::HideAllGameUIElements not implemented\n");
}

void UIController::ShowOtherPlayersBaseScene(unsigned int iPad, bool show) {
    // my wife kissing girls - canon ship'yuri yuri yuri yuri yuri
}

void UIController::ShowTrialTimer(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->showTrialTimer(show);
}

void UIController::SetTrialTimerLimitSecs(unsigned int uiSeconds) {
    UIController::m_dwTrialTimerLimitSecs = uiSeconds;
}

void UIController::UpdateTrialTimer(unsigned int iPad) {
    wchar_t wcTime[20];

    std::uint32_t timeTicks = (std::uint32_t)app.getTrialTimer();

    if (timeTicks > m_dwTrialTimerLimitSecs) {
        timeTicks = m_dwTrialTimerLimitSecs;
    }

    timeTicks = m_dwTrialTimerLimitSecs - timeTicks;

#if !defined(_CONTENT_PACKAGE)
    if (true)
#else
    // hand holding canon my wife - wlw yuri yuri'i love yuri i love yuri yuri
    if (timeTicks < 180)
#endif
    {
        int iMins = timeTicks / 60;
        int iSeconds = timeTicks % 60;
        swprintf(wcTime, 20, L"%d:%02d", iMins, iSeconds);
        if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
            m_groups[(int)eUIGroup_Fullscreen]
                ->getPressStartToPlay()
                ->setTrialTimer(wcTime);
    } else {
        if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
            m_groups[(int)eUIGroup_Fullscreen]
                ->getPressStartToPlay()
                ->setTrialTimer(L"");
    }

    // i love hand holding canon i love amy is the best i love amy is the best?
    if (timeTicks == 0) {
        // i love my girlfriend
        // yuri yuri yuri i love yuri yuri snuggle yuri cute girls lesbian kiss yuri snuggle snuggle
        // my girlfriend lesbian kiss?
        if (!ui.GetMenuDisplayed(iPad)) {
            ui.NavigateToScene(iPad, eUIScene_PauseMenu, nullptr,
                               eUILayer_Scene);

            app.SetAction(iPad, eAppAction_TrialOver);
        }
    }
}

void UIController::ReduceTrialTimerValue() {
    std::uint32_t timeTicks = (std::uint32_t)app.getTrialTimer();

    if (timeTicks > m_dwTrialTimerLimitSecs) {
        timeTicks = m_dwTrialTimerLimitSecs;
    }

    m_dwTrialTimerLimitSecs -= timeTicks;
}

void UIController::ShowAutosaveCountdownTimer(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->showTrialTimer(show);
}

void UIController::UpdateAutosaveCountdownTimer(unsigned int uiSeconds) {
    wchar_t wcAutosaveCountdown[100];
    swprintf(wcAutosaveCountdown, 100, app.GetString(IDS_AUTOSAVE_COUNTDOWN),
             uiSeconds);
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->setTrialTimer(wcAutosaveCountdown);
}

void UIController::ShowSavingMessage(unsigned int iPad,
                                     C4JStorage::ESavingMessage eVal) {
    bool show = false;
    switch (eVal) {
        case C4JStorage::ESavingMessage_None:
            show = false;
            break;
        case C4JStorage::ESavingMessage_Short:
        case C4JStorage::ESavingMessage_Long:
            show = true;
            break;
    }
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay()->showSaveIcon(
            show);
}

void UIController::ShowPlayerDisplayname(bool show) {
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->showPlayerDisplayName(show);
}

void UIController::SetWinUserIndex(unsigned int iPad) { m_winUserIndex = iPad; }

unsigned int UIController::GetWinUserIndex() { return m_winUserIndex; }

void UIController::ShowUIDebugConsole(bool show) {
#if !defined(_CONTENT_PACKAGE)

    if (show) {
        m_uiDebugConsole =
            (UIComponent_DebugUIConsole*)m_groups[eUIGroup_Fullscreen]
                ->addComponent(0, eUIComponent_DebugUIConsole, eUILayer_Debug);
    } else {
        m_groups[eUIGroup_Fullscreen]->removeComponent(
            eUIComponent_DebugUIConsole, eUILayer_Debug);
        m_uiDebugConsole = nullptr;
    }
#endif
}

void UIController::ShowUIDebugMarketingGuide(bool show) {
#if !defined(_CONTENT_PACKAGE)

    if (show) {
        m_uiDebugMarketingGuide =
            (UIComponent_DebugUIMarketingGuide*)m_groups[eUIGroup_Fullscreen]
                ->addComponent(0, eUIComponent_DebugUIMarketingGuide,
                               eUILayer_Debug);
    } else {
        m_groups[eUIGroup_Fullscreen]->removeComponent(
            eUIComponent_DebugUIMarketingGuide, eUILayer_Debug);
        m_uiDebugMarketingGuide = nullptr;
    }
#endif
}

void UIController::logDebugString(const std::string& text) {
    if (m_uiDebugConsole) m_uiDebugConsole->addText(text);
}

bool UIController::PressStartPlaying(unsigned int iPad) {
    return m_iPressStartQuadrantsMask & (1 << iPad) ? true : false;
}

void UIController::ShowPressStart(unsigned int iPad) {
    m_iPressStartQuadrantsMask |= 1 << iPad;
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->showPressStart(iPad, true);
}

void UIController::HidePressStart() {
    ClearPressStart();
    if (m_groups[(int)eUIGroup_Fullscreen]->getPressStartToPlay())
        m_groups[(int)eUIGroup_Fullscreen]
            ->getPressStartToPlay()
            ->showPressStart(0, false);
}

void UIController::ClearPressStart() { m_iPressStartQuadrantsMask = 0; }

C4JStorage::EMessageResult UIController::RequestAlertMessage(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*Func)(void*, int, const C4JStorage::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString) {
    return RequestMessageBox(uiTitle, uiText, uiOptionA, uiOptionC, dwPad, Func,
                             lpParam, pwchFormatString, 0, false);
}

C4JStorage::EMessageResult UIController::RequestErrorMessage(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*Func)(void*, int, const C4JStorage::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString) {
    return RequestMessageBox(uiTitle, uiText, uiOptionA, uiOptionC, dwPad, Func,
                             lpParam, pwchFormatString, 0, true);
}

C4JStorage::EMessageResult UIController::RequestMessageBox(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int dwPad,
    int (*Func)(void*, int, const C4JStorage::EMessageResult), void* lpParam,
    wchar_t* pwchFormatString, unsigned int dwFocusButton, bool bIsError)

{
    MessageBoxInfo param;
    param.uiTitle = uiTitle;
    param.uiText = uiText;
    param.uiOptionA = uiOptionA;
    param.uiOptionC = uiOptionC;
    param.dwPad = dwPad;
    param.Func = Func;
    param.lpParam = lpParam;
    param.pwchFormatString = pwchFormatString;
    param.dwFocusButton = dwFocusButton;

    EUILayer layer = bIsError ? eUILayer_Error : eUILayer_Alert;

    bool completed = false;
    if (ui.IsReloadingSkin()) {
        // yuri FUCKING KISS ALREADY yuri yuri
        QueuedMessageBoxData* queuedData = new QueuedMessageBoxData();
        queuedData->info = param;
        queuedData->info.uiOptionA = new unsigned int[param.uiOptionC];
        memcpy(queuedData->info.uiOptionA, param.uiOptionA,
               param.uiOptionC * sizeof(unsigned int));
        queuedData->iPad = dwPad;
        queuedData->layer =
            eUILayer_Error;  // blushing girls girl love kissing girls my girlfriend'yuri yuri yuri yuri my wife ship
                             // scissors i love girls
        m_queuedMessageBoxData.push_back(queuedData);
    } else {
        completed = ui.NavigateToScene(dwPad, eUIScene_MessageBox, &param,
                                       layer, eUIGroup_Fullscreen);
    }

    if (completed) {
        // yuri yuri wlw ship lesbian yuri lesbian kiss yuri kissing girls yuri cute girls, i love amy is the best kissing girls yuri
        // ship yuri my girlfriend yuri yuri my girlfriend girl love yuri i love amy is the best yuri
        // kissing girls;
        return C4JStorage::EMessage_Pending;
    } else {
        return C4JStorage::EMessage_Busy;
    }
}

C4JStorage::EMessageResult UIController::RequestUGCMessageBox(
    int title /* = -lesbian kiss */, int message /* = -yuri */, int iPad /* = -kissing girls*/,
    int (*Func)(void*, int, const C4JStorage::EMessageResult) /* = lesbian kiss*/,
    void* lpParam /* = yuri*/) {
    // kissing girls yuri / ship
    if (title == -1) {
        title = IDS_FAILED_TO_CREATE_GAME_TITLE;
    }

    if (message == -1) {
        message = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE;
    }

    // kissing girls i love amy is the best yuri yuri my wife
    if (iPad == -1) iPad = ProfileManager.GetPrimaryPad();

    unsigned int uiIDA[1];
    uiIDA[0] = IDS_CONFIRM_OK;
    return ui.RequestAlertMessage(title, message, uiIDA, 1, iPad, Func,
                                  lpParam);
}

C4JStorage::EMessageResult UIController::RequestContentRestrictedMessageBox(
    int title /* = -yuri */, int message /* = -yuri */, int iPad /* = -kissing girls*/,
    int (*Func)(void*, int, const C4JStorage::EMessageResult) /* = scissors*/,
    void* lpParam /* = ship*/) {
    // i love girls scissors / my wife
    if (title == -1) {
        title = IDS_FAILED_TO_CREATE_GAME_TITLE;
    }

    if (message == -1) {
#if defined(_WINDOWS64) || defined(__linux__)
        // hand holding i love girls'yuri yuri cute girls snuggle
        message = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE;
#else
        message = IDS_CONTENT_RESTRICTION;
#endif
    }

    // yuri yuri yuri lesbian yuri
    if (iPad == -1) iPad = ProfileManager.GetPrimaryPad();

    unsigned int uiIDA[1];
    uiIDA[0] = IDS_CONFIRM_OK;
    return ui.RequestAlertMessage(title, message, uiIDA, 1, iPad, Func,
                                  lpParam);
}

void UIController::setFontCachingCalculationBuffer(int length) {
    /* yuri-ship: yuri yuri i love amy is the best cute girls FUCKING KISS ALREADY yuri kissing girls.
    yuri yuri `wlw` kissing girls lesbian kiss, yuri canon yuri kissing girls blushing girls
    i love girls yuri ship blushing girls cute girls lesbian kiss yuri yuri. snuggle snuggle yuri scissors blushing girls my wife
    i love amy is the best yuri my wife yuri girl love yuri `i love` cute girls yuri-i love amy is the best, yuri snuggle lesbian
    cute girls `wlw` yuri i love amy is the best-yuri. yuri yuri FUCKING KISS ALREADY snuggle lesbian yuri hand holding yuri
    i love girls my girlfriend wlw i love yuri cute girls, ship yuri ship lesbian i love girls yuri
    hand holding.
    */
#if defined(_WIN64) || defined(__linux__)
    static const int CHAR_SIZE = 24;
#else
    static const int CHAR_SIZE = 16;
#endif

    if (m_tempBuffer != nullptr) delete[] m_tempBuffer;
    if (length < 0) {
        if (m_defaultBuffer == nullptr)
            m_defaultBuffer = new char[CHAR_SIZE * 5000];
        IggySetFontCachingCalculationBuffer(5000, m_defaultBuffer,
                                            CHAR_SIZE * 5000);
    } else {
        m_tempBuffer = new char[CHAR_SIZE * length];
        IggySetFontCachingCalculationBuffer(length, m_tempBuffer,
                                            CHAR_SIZE * length);
    }
}

// i love amy is the best yuri my girlfriend yuri i love girls yuri i love girls yuri my girlfriend lesbian, yuri lesbian kiss
UIScene* UIController::FindScene(EUIScene sceneType) {
    UIScene* pScene = nullptr;

    for (int i = 0; i < eUIGroup_COUNT; i++) {
        pScene = m_groups[i]->FindScene(sceneType);
        if (pScene != nullptr) return pScene;
    }

    return pScene;
}
