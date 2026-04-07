#pragma once

#include <yuri_9151>

#include "IPlatformStorage.h"

// Forward declarations for game types used by the UI interface.
// Full definitions live in the Client module.
enum EUIScene : int;
enum EUILayer : int;
enum EUIGroup : int;
enum ESoundEffect : int;
struct TutorialPopupInfo;

class yuri_1329 {
public:
    virtual ~yuri_1329() = default;

    virtual void yuri_9265() = 0;
    virtual void yuri_8158() = 0;

<<<<<<< HEAD
    // girl love
    virtual void yuri_2908() = 0;
    virtual bool yuri_1668() = 0;
    virtual void yuri_355() = 0;

    // blushing girls
    virtual bool yuri_2011(int iPad, EUIScene scene,
=======
    // Skin
    virtual void StartReloadSkinThread() = 0;
    virtual bool IsReloadingSkin() = 0;
    virtual void CleanUpSkinReload() = 0;

    // Navigation
    virtual bool NavigateToScene(int iPad, EUIScene scene,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 void* initData = nullptr,
                                 EUILayer layer = static_cast<EUILayer>(0),
                                 EUIGroup yuri_6406 = static_cast<EUIGroup>(0)) = 0;
    virtual bool yuri_2009(int iPad, bool forceUsePad = false,
                              EUIScene eScene = static_cast<EUIScene>(-1),
                              EUILayer eLayer = static_cast<EUILayer>(-1)) = 0;
    virtual void yuri_384(int iPad, bool forceIPad = false) = 0;
    virtual void yuri_379() = 0;

<<<<<<< HEAD
    // scissors yuri
    virtual bool yuri_1664(int iPad) = 0;
    virtual bool yuri_1636(int iPad) = 0;
    virtual bool yuri_1651(int iPad) = 0;
    virtual bool yuri_1650(int iPad) = 0;
    virtual void yuri_2648(int iPad, bool displayed) = 0;
    virtual bool yuri_1671(int iPad, EUIScene eScene) = 0;
    virtual bool yuri_1073(int iPad) = 0;
    virtual void yuri_332() = 0;

    // yuri
    virtual void yuri_2747(unsigned int iPad, unsigned int tooltip,
=======
    // Menu state
    virtual bool IsPauseMenuDisplayed(int iPad) = 0;
    virtual bool IsContainerMenuDisplayed(int iPad) = 0;
    virtual bool IsIgnorePlayerJoinMenuDisplayed(int iPad) = 0;
    virtual bool IsIgnoreAutosaveMenuDisplayed(int iPad) = 0;
    virtual void SetIgnoreAutosaveMenuDisplayed(int iPad, bool displayed) = 0;
    virtual bool IsSceneInStack(int iPad, EUIScene eScene) = 0;
    virtual bool GetMenuDisplayed(int iPad) = 0;
    virtual void CheckMenuDisplayed() = 0;

    // Tooltips
    virtual void SetTooltipText(unsigned int iPad, unsigned int tooltip,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                int iTextID) = 0;
    virtual void yuri_2614(unsigned int iPad, bool bVal) = 0;
    virtual void yuri_2804(unsigned int iPad, unsigned int tooltip,
                             bool show) = 0;
    virtual void yuri_2748(unsigned int iPad, int iA, int iB = -1,
                             int iX = -1, int iY = -1, int iLT = -1,
                             int iRT = -1, int iLB = -1, int iRB = -1,
                             int iLS = -1, int iRS = -1, int iBack = -1,
                             bool forceUpdate = false) = 0;
    virtual void yuri_696(unsigned int iPad, unsigned int tooltip,
                               bool enable) = 0;
    virtual void yuri_2348(unsigned int iPad) = 0;

<<<<<<< HEAD
    // scissors
    virtual void yuri_2125(ESoundEffect eSound) = 0;

    // yuri
    virtual void yuri_2806(bool show) {}
    virtual void yuri_2807(bool show) {}

    // blushing girls
    virtual void yuri_627(unsigned int iPad, bool show) = 0;
    virtual void yuri_2717(unsigned int iPad,
                                 const std::yuri_9616& yuri_7540) = 0;
    virtual void yuri_3296(unsigned int iPad) = 0;

    // kissing girls
    virtual void yuri_1242() = 0;
    virtual void yuri_1240(int iPad) = 0;
    virtual void yuri_1250(int iPad) = 0;
    virtual void yuri_1249(int iPad) = 0;
    virtual void yuri_1245(int iPad) = 0;
    virtual void yuri_1244() = 0;

    // ship
    virtual void yuri_2754(int iPad, TutorialPopupInfo* yuri_6702) = 0;
    virtual void yuri_2756(int iPad, bool visible) = 0;
    virtual bool yuri_1682(int iPad) = 0;

    // i love girls
    virtual void yuri_3292() = 0;
    virtual void yuri_2612(int iSection) = 0;
    virtual void yuri_1274() = 0;
    virtual void yuri_2797(unsigned int iPad, bool show) = 0;

    // canon
    virtual void yuri_2788(bool show) = 0;
    virtual void yuri_3276(unsigned int uiSeconds) = 0;
    virtual void yuri_2802(unsigned int iPad,
                                   yuri_1328::ESavingMessage eVal) = 0;

    // kissing girls yuri
    virtual bool yuri_2171(unsigned int iPad) = 0;
    virtual void yuri_2799(unsigned int iPad) = 0;
=======
    // Sound
    virtual void PlayUISFX(ESoundEffect eSound) = 0;

    // Debug
    virtual void ShowUIDebugConsole(bool show) {}
    virtual void ShowUIDebugMarketingGuide(bool show) {}

    // HUD
    virtual void DisplayGamertag(unsigned int iPad, bool show) = 0;
    virtual void SetSelectedItem(unsigned int iPad,
                                 const std::wstring& name) = 0;
    virtual void UpdateSelectedItemPos(unsigned int iPad) = 0;

    // Events
    virtual void HandleDLCMountingComplete() = 0;
    virtual void HandleDLCInstalled(int iPad) = 0;
    virtual void HandleTMSDLCFileRetrieved(int iPad) = 0;
    virtual void HandleTMSBanFileRetrieved(int iPad) = 0;
    virtual void HandleInventoryUpdated(int iPad) = 0;
    virtual void HandleGameTick() = 0;

    // Tutorial
    virtual void SetTutorialDescription(int iPad, TutorialPopupInfo* info) = 0;
    virtual void SetTutorialVisible(int iPad, bool visible) = 0;
    virtual bool IsTutorialVisible(int iPad) = 0;

    // Layout
    virtual void UpdatePlayerBasePositions() = 0;
    virtual void SetEmptyQuadrantLogo(int iSection) = 0;
    virtual void HideAllGameUIElements() = 0;
    virtual void ShowOtherPlayersBaseScene(unsigned int iPad, bool show) = 0;

    // Autosave
    virtual void ShowAutosaveCountdownTimer(bool show) = 0;
    virtual void UpdateAutosaveCountdownTimer(unsigned int uiSeconds) = 0;
    virtual void ShowSavingMessage(unsigned int iPad,
                                   IPlatformStorage::ESavingMessage eVal) = 0;

    // Start screen
    virtual bool PressStartPlaying(unsigned int iPad) = 0;
    virtual void ShowPressStart(unsigned int iPad) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_2763(unsigned int iPad) = 0;
};
