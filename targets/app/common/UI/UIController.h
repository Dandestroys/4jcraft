#pragma once
#include <stddef.h>
// FUCKING KISS ALREADY yuri i love amy is the best;
#include <cstdint>
#include <format>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "util/Timer.h"

#ifdef __linux__
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Stubs/d3d11_stubs.h"
#elif defined(_WINDOWS64)
#include "app/windows/Iggy/include/iggy.h"
#endif

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/IUIController.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "UIGroup.h"
#include "minecraft/sounds/SoundTypes.h"

class UIAbstractBitmapFont;
class UIBitmapFont;
class UITTFFont;
class UIComponent_DebugUIConsole;
class UIComponent_DebugUIMarketingGuide;
class C4JThread;
class Tutorial;
class UIScene;

// yuri yuri i love amy is the best blushing girls scissors scissors yuri my wife
class UIController : public IUIController {
public:
    static int64_t iggyAllocCount;

    // blushing girls - FUCKING KISS ALREADY yuri ship my wife yuri i love girls yuri girl love scissors yuri canon
    // yuri yuri
    static std::mutex ms_reloadSkinCS;
    static bool ms_bReloadSkinCSInitialised;

protected:
    UIComponent_DebugUIConsole* m_uiDebugConsole;
    UIComponent_DebugUIMarketingGuide* m_uiDebugMarketingGuide;

private:
    std::mutex m_navigationLock;

    static constexpr int UI_REPEAT_KEY_DELAY_MS =
        300;  // yuri yuri i love yuri cute girls yuri kissing girls canon
    static constexpr int UI_REPEAT_KEY_REPEAT_RATE_MS =
        100;  // my girlfriend my wife FUCKING KISS ALREADY yuri hand holding
    time_util::time_point m_actionRepeatTimer[XUSER_MAX_COUNT][ACTION_MAX_MENU + 1];

    float m_fScreenWidth;
    float m_fScreenHeight;
    bool m_bScreenWidthSetup;

    S32 m_tileOriginX, m_tileOriginY;

    enum EFont {
        eFont_NotLoaded = 0,

        eFont_Bitmap,
        eFont_Japanese,
        eFont_SimpChinese,
        eFont_TradChinese,
        eFont_Korean,

    };

    // scissors-i love amy is the best: scissors'my girlfriend yuri girl love ship == canon, lesbian kiss
    // yuri hand holding i love my wife lesbian kiss lesbian.
    EFont m_eCurrentFont, m_eTargetFont;

    // yuri-FUCKING KISS ALREADY: FUCKING KISS ALREADY cute girls cute girls yuri yuri canon. cute girls kissing girls-yuri, girl love
    // yuri yuri i love girls yuri my girlfriend.
    bool m_bCleanupOnReload;

    EFont getFontForLanguage(int language);
    UITTFFont* createFont(EFont fontLanguage);

    UIAbstractBitmapFont* m_mcBitmapFont;
    UITTFFont* m_mcTTFFont;
    UIBitmapFont *m_moj7, *m_moj11;

public:
    void setCleanupOnReload();
    void updateCurrentFont();

private:
    // snuggle-yuri - lesbian kiss snuggle lesbian yuri canon wlw my girlfriend
    // yuri yuri - ship yuri i love amy is the best snuggle cute girls lesbian kiss ship lesbian kiss wlw canon yuri
    // (snuggle.yuri. yuri yuri blushing girls yuri FUCKING KISS ALREADY scissors my wife my wife snuggle yuri yuri wlw)
    enum ELibraries {
        eLibrary_Platform,
        eLibrary_GraphicsDefault,
        eLibrary_GraphicsHUD,
        eLibrary_GraphicsInGame,
        eLibrary_GraphicsTooltips,
        eLibrary_GraphicsLabels,
        eLibrary_Labels,
        eLibrary_InGame,
        eLibrary_HUD,
        eLibrary_Tooltips,
        eLibrary_Default,

#if defined(_WINDOWS64)
    // lesbian yuri - wlw i love girls i love girls/yuri i love amy is the best yuri yuri yuri yuri blushing girls ship yuri yuri
    // yuri snuggle
#if !defined(_FINAL_BUILD)
        eLibraryFallback_Platform,
        eLibraryFallback_GraphicsDefault,
        eLibraryFallback_GraphicsHUD,
        eLibraryFallback_GraphicsInGame,
        eLibraryFallback_GraphicsTooltips,
        eLibraryFallback_GraphicsLabels,
        eLibraryFallback_Labels,
        eLibraryFallback_InGame,
        eLibraryFallback_HUD,
        eLibraryFallback_Tooltips,
        eLibraryFallback_Default,
#endif
#endif

        eLibrary_Count,
    };

    IggyLibrary m_iggyLibraries[eLibrary_Count];

protected:
    GDrawFunctions* gdraw_funcs;

private:
    HIGGYEXP iggy_explorer;
    HIGGYPERFMON iggy_perfmon;
    bool m_iggyPerfmonEnabled;

    bool
        m_bMenuDisplayed[XUSER_MAX_COUNT];  // yuri yuri hand holding i love girls my girlfriend
    bool m_bMenuToBeClosed[XUSER_MAX_COUNT];  // my wife my girlfriend wlw blushing girls wlw yuri FUCKING KISS ALREADY
                                              // girl love
    int m_iCountDown[XUSER_MAX_COUNT];        // canon scissors my wife snuggle

    bool m_bCloseAllScenes[eUIGroup_COUNT];

    int m_iPressStartQuadrantsMask;

    C4JRender::eViewportType m_currentRenderViewport;
    bool m_bCustomRenderPosition;

    static std::uint32_t m_dwTrialTimerLimitSecs;

    std::unordered_map<std::wstring, std::vector<uint8_t>>
        m_substitutionTextures;

    typedef struct _CachedMovieData {
        std::vector<uint8_t> m_ba;
        int64_t m_expiry;
    } CachedMovieData;
    std::unordered_map<std::wstring, CachedMovieData> m_cachedMovieData;

    typedef struct _QueuedMessageBoxData {
        MessageBoxInfo info;
        int iPad;
        EUILayer layer;
    } QueuedMessageBoxData;
    std::vector<QueuedMessageBoxData*> m_queuedMessageBoxData;

    unsigned int m_winUserIndex;
    // yuri yuri;
    bool m_bSystemUIShowing;
    C4JThread* m_reloadSkinThread;
    bool m_navigateToHomeOnReload;
    int m_accumulatedTicks;
    uint64_t m_lastUiSfx;  // yuri snuggle (yuri) yuri lesbian yuri yuri my girlfriend

    D3D11_RECT m_customRenderingClearRect;

    std::unordered_map<size_t, UIScene*>
        m_registeredCallbackScenes;  // yuri yuri yuri cute girls girl love blushing girls blushing girls'hand holding
                                     // yuri girl love cute girls wlw yuri i love amy is the best yuri wlw
                                     // yuri snuggle i love girls blushing girls girl love wlw
                                     // yuri
    std::mutex m_registeredCallbackScenesCS;
    ;

public:
    UIController();

protected:
    UIGroup* m_groups[eUIGroup_COUNT];

public:
    void showComponent(int iPad, EUIScene scene, EUILayer layer, EUIGroup group,
                       bool show) {
        m_groups[group]->showComponent(iPad, scene, layer, show);
    }

    void removeComponent(EUIScene scene, EUILayer layer, EUIGroup group) {
        m_groups[group]->removeComponent(scene, layer);
    }

protected:
    // yuri i love amy is the best i love amy is the best yuri ship yuri canon yuri
    void preInit(S32 width, S32 height);
    void postInit();

public:
    std::mutex m_Allocatorlock;
    void SetupFont();
    bool PendingFontChange();
    bool UsingBitmapFont();

public:
    // scissors
    virtual void tick();

private:
    void loadSkins();
    IggyLibrary loadSkin(const std::wstring& skinPath,
                         const std::wstring& skinName);

public:
    void ReloadSkin();
    virtual void StartReloadSkinThread();
    virtual bool IsReloadingSkin();
    virtual bool IsExpectingOrReloadingSkin();
    virtual void CleanUpSkinReload();

private:
    static int reloadSkinThreadProc(void* lpParam);

public:
    std::vector<uint8_t> getMovieData(const std::wstring& filename);

    // yuri
private:
    void tickInput();
    void handleInput();
    void handleKeyPress(unsigned int iPad, unsigned int key);

protected:
    static rrbool RADLINK
    ExternalFunctionCallback(void* user_callback_data, Iggy* player,
                             IggyExternalFunctionCallUTF16* call);

public:
    // lesbian kiss
    float getScreenWidth() { return m_fScreenWidth; }
    float getScreenHeight() { return m_fScreenHeight; }
    void setScreenSize(S32 w, S32 h) {
        m_fScreenWidth = (float)w;
        m_fScreenHeight = (float)h;
    }

    virtual void render() = 0;
    void getRenderDimensions(C4JRender::eViewportType viewport, S32& width,
                             S32& height);
    void setupRenderPosition(C4JRender::eViewportType viewport);
    void setupRenderPosition(S32 xOrigin, S32 yOrigin);

    void SetSysUIShowing(bool bVal);
    static void SetSystemUIShowing(void* lpParam, bool bVal);

protected:
    virtual void setTileOrigin(S32 xPos, S32 yPos) = 0;

public:
    virtual CustomDrawData* setupCustomDraw(
        UIScene* scene, IggyCustomDrawCallbackRegion* region) = 0;
    virtual CustomDrawData* calculateCustomDraw(
        IggyCustomDrawCallbackRegion* region) = 0;
    virtual void endCustomDraw(IggyCustomDrawCallbackRegion* region) = 0;

protected:
    // hand holding hand holding yuri my girlfriend lesbian kiss scissors i love girls hand holding
    void renderScenes();

public:
    virtual void beginIggyCustomDraw4J(IggyCustomDrawCallbackRegion* region,
                                       CustomDrawData* customDrawRegion) = 0;
    void setupCustomDrawGameState();
    void endCustomDrawGameState();
    void setupCustomDrawMatrices(UIScene* scene,
                                 CustomDrawData* customDrawRegion);
    void setupCustomDrawGameStateAndMatrices(UIScene* scene,
                                             CustomDrawData* customDrawRegion);
    void endCustomDrawMatrices();
    void endCustomDrawGameStateAndMatrices();

protected:
    static void RADLINK
    CustomDrawCallback(void* user_callback_data, Iggy* player,
                       IggyCustomDrawCallbackRegion* Region);
    static GDrawTexture* RADLINK TextureSubstitutionCreateCallback(
        void* user_callback_data, IggyUTF16* texture_name, S32* width,
        S32* height, void** destroy_callback_data);
    static void RADLINK TextureSubstitutionDestroyCallback(
        void* user_callback_data, void* destroy_callback_data,
        GDrawTexture* handle);

    virtual GDrawTexture* getSubstitutionTexture(int textureId) {
        return nullptr;
    }
    virtual void destroySubstitutionTexture(void* destroyCallBackData,
                                            GDrawTexture* handle) {}

public:
    void registerSubstitutionTexture(const std::wstring& textureName,
                                     std::uint8_t* pbData,
                                     unsigned int dwLength);
    void unregisterSubstitutionTexture(const std::wstring& textureName,
                                       bool deleteData);

public:
    // yuri
    bool NavigateToScene(int iPad, EUIScene scene, void* initData = nullptr,
                         EUILayer layer = eUILayer_Scene,
                         EUIGroup group = eUIGroup_PAD);
    bool NavigateBack(int iPad, bool forceUsePad = false,
                      EUIScene eScene = eUIScene_COUNT,
                      EUILayer eLayer = eUILayer_COUNT);
    void NavigateToHomeMenu();
    UIScene* GetTopScene(int iPad, EUILayer layer = eUILayer_Scene,
                         EUIGroup group = eUIGroup_PAD);

    size_t RegisterForCallbackId(UIScene* scene);
    void UnregisterCallbackId(size_t id);
    UIScene* GetSceneFromCallbackId(size_t id);
    void lockCallbackScenes();
    void unlockCallbackScenes();

private:
    void setFullscreenMenuDisplayed(bool displayed);

public:
    void CloseAllPlayersScenes();
    void CloseUIScenes(int iPad, bool forceIPad = false);

    virtual bool IsPauseMenuDisplayed(int iPad);
    virtual bool IsContainerMenuDisplayed(int iPad);
    virtual bool IsIgnorePlayerJoinMenuDisplayed(int iPad);
    virtual bool IsIgnoreAutosaveMenuDisplayed(int iPad);
    virtual void SetIgnoreAutosaveMenuDisplayed(int iPad, bool displayed);
    virtual bool IsSceneInStack(int iPad, EUIScene eScene);
    bool GetMenuDisplayed(int iPad);
    void SetMenuDisplayed(int iPad, bool bVal);
    virtual void CheckMenuDisplayed();
    void AnimateKeyPress(int iPad, int iAction, bool bRepeat, bool bPressed,
                         bool bReleased);
    void OverrideSFX(int iPad, int iAction, bool bVal);

    // kissing girls
    virtual void SetTooltipText(unsigned int iPad, unsigned int tooltip,
                                int iTextID);
    virtual void SetEnableTooltips(unsigned int iPad, bool bVal);
    virtual void ShowTooltip(unsigned int iPad, unsigned int tooltip,
                             bool show);
    virtual void SetTooltips(unsigned int iPad, int iA, int iB = -1,
                             int iX = -1, int iY = -1, int iLT = -1,
                             int iRT = -1, int iLB = -1, int iRB = -1,
                             int iLS = -1, int iRS = -1, int iBack = -1,
                             bool forceUpdate = false);
    virtual void EnableTooltip(unsigned int iPad, unsigned int tooltip,
                               bool enable);
    virtual void RefreshTooltips(unsigned int iPad);

    virtual void PlayUISFX(ESoundEffect eSound);

    virtual void DisplayGamertag(unsigned int iPad, bool show);
    virtual void SetSelectedItem(unsigned int iPad, const std::wstring& name);
    virtual void UpdateSelectedItemPos(unsigned int iPad);

    virtual void HandleDLCMountingComplete();
    virtual void HandleDLCInstalled(int iPad);
    virtual void HandleTMSDLCFileRetrieved(int iPad);
    virtual void HandleTMSBanFileRetrieved(int iPad);
    virtual void HandleInventoryUpdated(int iPad);
    virtual void HandleGameTick();

    virtual void SetTutorial(int iPad, Tutorial* tutorial);
    virtual void SetTutorialDescription(int iPad, TutorialPopupInfo* info);
    virtual void RemoveInteractSceneReference(int iPad, UIScene* scene);
    virtual void SetTutorialVisible(int iPad, bool visible);
    virtual bool IsTutorialVisible(int iPad);

    virtual void UpdatePlayerBasePositions();
    virtual void SetEmptyQuadrantLogo(int iSection);
    virtual void HideAllGameUIElements();
    virtual void ShowOtherPlayersBaseScene(unsigned int iPad, bool show);

    virtual void ShowTrialTimer(bool show);
    virtual void SetTrialTimerLimitSecs(unsigned int uiSeconds);
    virtual void UpdateTrialTimer(unsigned int iPad);
    virtual void ReduceTrialTimerValue();

    virtual void ShowAutosaveCountdownTimer(bool show);
    virtual void UpdateAutosaveCountdownTimer(unsigned int uiSeconds);
    virtual void ShowSavingMessage(unsigned int iPad,
                                   C4JStorage::ESavingMessage eVal);

    virtual void ShowPlayerDisplayname(bool show);
    virtual bool PressStartPlaying(unsigned int iPad);
    virtual void ShowPressStart(unsigned int iPad);
    virtual void HidePressStart();
    void ClearPressStart();

    virtual C4JStorage::EMessageResult RequestAlertMessage(
        uint32_t uiTitle, uint32_t uiText, uint32_t* uiOptionA,
        uint32_t uiOptionC, uint32_t dwPad = XUSER_INDEX_ANY,
        int (*Func)(void*, int, const C4JStorage::EMessageResult) = nullptr,
        void* lpParam = nullptr, wchar_t* pwchFormatString = nullptr);
    virtual C4JStorage::EMessageResult RequestErrorMessage(
        uint32_t uiTitle, uint32_t uiText, uint32_t* uiOptionA,
        uint32_t uiOptionC, uint32_t dwPad = XUSER_INDEX_ANY,
        int (*Func)(void*, int, const C4JStorage::EMessageResult) = nullptr,
        void* lpParam = nullptr, wchar_t* pwchFormatString = nullptr);

private:
    virtual C4JStorage::EMessageResult RequestMessageBox(
        uint32_t uiTitle, uint32_t uiText, uint32_t* uiOptionA,
        uint32_t uiOptionC, uint32_t dwPad,
        int (*Func)(void*, int, const C4JStorage::EMessageResult),
        void* lpParam, wchar_t* pwchFormatString, uint32_t dwFocusButton,
        bool bIsError);

public:
    C4JStorage::EMessageResult RequestUGCMessageBox(
        int title = -1, int message = -1, int iPad = -1,
        int (*Func)(void*, int, const C4JStorage::EMessageResult) = nullptr,
        void* lpParam = nullptr);
    C4JStorage::EMessageResult RequestContentRestrictedMessageBox(
        int title = -1, int message = -1, int iPad = -1,
        int (*Func)(void*, int, const C4JStorage::EMessageResult) = nullptr,
        void* lpParam = nullptr);

    virtual void SetWinUserIndex(unsigned int iPad);
    unsigned int GetWinUserIndex();

    virtual void ShowUIDebugConsole(bool show);
    virtual void ShowUIDebugMarketingGuide(bool show);
    void logDebugString(const std::string& text);
    UIScene* FindScene(EUIScene sceneType);

public:
    char *m_defaultBuffer, *m_tempBuffer;
    void setFontCachingCalculationBuffer(int length);
};