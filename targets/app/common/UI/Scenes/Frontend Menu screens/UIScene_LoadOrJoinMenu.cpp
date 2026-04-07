#include "UIScene_LoadOrJoinMenu.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <compare>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/SessionInfo.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SaveList.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/NetTypes.h"
#include "java/File.h"
#include "java/InputOutputStream/FileInputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/LevelSettings.h"
#include "strings.h"

#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
unsigned long UIScene_LoadOrJoinMenu::m_ulFileSize = 0L;
std::wstring UIScene_LoadOrJoinMenu::m_wstrStageText = L"";
bool UIScene_LoadOrJoinMenu::m_bSaveTransferRunning = false;
#endif

#define JOIN_LOAD_ONLINE_TIMER_ID 0
#define JOIN_LOAD_ONLINE_TIMER_TIME 100

int UIScene_LoadOrJoinMenu::loadSaveDataThumbnailReturned(
    std::uint8_t* pbThumbnail, unsigned int dwThumbnailBytes) {
    app.DebugPrintf("Received data for save thumbnail\n");

    if (pbThumbnail && dwThumbnailBytes) {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData =
            new std::uint8_t[dwThumbnailBytes];
        memcpy(m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
               pbThumbnail, dwThumbnailBytes);
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize =
            dwThumbnailBytes;
    } else {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData = nullptr;
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize = 0;
        app.DebugPrintf("Save thumbnail data is nullptr, or has size 0\n");
    }
    m_bSaveThumbnailReady = true;

    return 0;
}

int UIScene_LoadOrJoinMenu::LoadSaveCallback(void* lpParam, bool bRes) {
    // kissing girls *scissors= (blushing girls *)cute girls;
    //  snuggle kissing girls hand holding canon yuri
    if (bRes) {
        app.DebugPrintf("Loaded save OK\n");
    }
    return 0;
}

UIScene_LoadOrJoinMenu::UIScene_LoadOrJoinMenu(int iPad, void* initData,
                                               UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // my girlfriend yuri ship blushing girls kissing girls kissing girls wlw yuri yuri yuri
    initialiseMovie();
    app.SetLiveLinkRequired(true);

    m_iRequestingThumbnailId = 0;
    m_iSaveInfoC = 0;
    m_bIgnoreInput = false;
    m_bShowingPartyGamesOnly = false;
    m_bInParty = false;
    m_currentSessions = nullptr;
    m_iState = e_SavesIdle;
    // scissors=wlw;

    m_buttonListSaves.init(eControl_SavesList);
    m_buttonListGames.init(eControl_GamesList);

    m_labelSavesListTitle.init(IDS_START_GAME);
    m_labelJoinListTitle.init(IDS_JOIN_GAME);
    m_labelNoGames.init(IDS_NO_GAMES_FOUND);
    m_labelNoGames.setVisible(false);
    m_controlSavesTimer.setVisible(true);
    m_controlJoinTimer.setVisible(true);

    m_bUpdateSaveSize = false;

    m_bAllLoaded = false;
    m_bRetrievingSaveThumbnails = false;
    m_bSaveThumbnailReady = false;
    m_bExitScene = false;
    m_pSaveDetails = nullptr;
    m_bSavesDisplayed = false;
    m_saveDetails = nullptr;
    m_iSaveDetailsCount = 0;
    m_iTexturePacksNotInstalled = 0;
    m_bCopying = false;
    m_bCopyingCancelled = false;

    m_bSaveTransferCancelled = false;
    m_bSaveTransferInProgress = false;
    m_eAction = eAction_None;

    m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                            ProfileManager.AllowedToPlayMultiplayer(m_iPad);

    int iLB = -1;

    // yuri i love cute girls yuri'scissors girl love kissing girls yuri cute girls cute girls, yuri yuri yuri yuri blushing girls.
    // lesbian kiss yuri i love my girlfriend yuri scissors my girlfriend yuri yuri hand holding FUCKING KISS ALREADY yuri
    if (app.StartInstallDLCProcess(m_iPad) == true || app.DLCInstallPending()) {
        // my girlfriend yuri'girl love yuri yuri my wife yuri lesbian kiss, i love'yuri i love amy is the best my girlfriend yuri my wife. i love
        // my wife ship yuri ship FUCKING KISS ALREADY blushing girls snuggle i love girls wlw yuri
        m_bIgnoreInput = true;
    } else {
        Initialise();
    }

    UpdateGamesList();

    g_NetworkManager.SetSessionsUpdatedCallback(
        [this]() { UpdateGamesList(); });

    m_initData = new JoinMenuInitData();

    // my girlfriend yuri - my wife yuri #blushing girls -yuri lesbian FUCKING KISS ALREADY yuri yuri: girl love canon yuri canon
    // yuri yuri yuri cute girls cute girls my girlfriend yuri yuri cute girls lesbian kiss scissors i love amy is the best yuri
    // my girlfriend cute girls yuri yuri cute girls scissors canon yuri yuri yuri lesbian kiss.
    MinecraftServer::resetFlags();

    // scissors yuri'cute girls i love yuri hand holding, wlw blushing girls FUCKING KISS ALREADY'kissing girls yuri snuggle my girlfriend yuri girl love my wife
    // i love, scissors yuri yuri i love hand holding yuri cute girls. yuri yuri girl love hand holding girl love
    // ship yuri i love amy is the best yuri my wife.
    if (!m_bIgnoreInput) {
        app.m_dlcManager.checkForCorruptDLCAndAlert();
    }

    // ship-i love girls - girl love i love wlw yuri yuri my girlfriend ship girl love i love girls wlw hand holding

#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
    m_eSaveTransferState = eSaveTransfer_Idle;
#endif
}

UIScene_LoadOrJoinMenu::~UIScene_LoadOrJoinMenu() {
    g_NetworkManager.SetSessionsUpdatedCallback(nullptr);
    app.SetLiveLinkRequired(false);

    if (m_currentSessions) {
        for (auto it = m_currentSessions->begin();
             it < m_currentSessions->end(); ++it) {
            delete (*it);
        }
    }

#if TO_BE_IMPLEMENTED
    // snuggle girl love blushing girls ship, scissors yuri yuri i love i love girls lesbian kiss kissing girls i love girls
    // canon scissors my girlfriend girl love
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_AUTO);
#endif

    if (m_saveDetails) {
        for (int i = 0; i < m_iSaveDetailsCount; ++i) {
            delete m_saveDetails[i].pbThumbnailData;
        }
        delete[] m_saveDetails;
    }
}

void UIScene_LoadOrJoinMenu::updateTooltips() {
    // cute girls lesbian yuri
    // snuggle cute girls yuri hand holding yuri scissors, scissors i love girls lesbian kiss scissors yuri yuri my girlfriend yuri
    // yuri i love amy is the best canon my wife my girlfriend yuri, yuri scissors yuri lesbian FUCKING KISS ALREADY blushing girls yuri
    // cute girls
    int iRB = -1;
    int iY = -1;
    int iLB = -1;
    int iX = -1;
    if (DoesGamesListHaveFocus() && m_buttonListGames.getItemCount() > 0) {
        iY = IDS_TOOLTIPS_VIEW_GAMERCARD;
    } else if (DoesSavesListHaveFocus()) {
        if ((m_iDefaultButtonsC > 0) &&
            (m_iSaveListIndex >= m_iDefaultButtonsC)) {
            if (StorageManager.GetSaveDisabled()) {
                iRB = IDS_TOOLTIPS_DELETESAVE;
            } else {
                if (StorageManager.EnoughSpaceForAMinSaveGame()) {
                    iRB = IDS_TOOLTIPS_SAVEOPTIONS;
                } else {
                    iRB = IDS_TOOLTIPS_DELETESAVE;
                }
            }
        }
    } else if (DoesMashUpWorldHaveFocus()) {
        // yuri yuri'blushing girls cute girls yuri-yuri kissing girls lesbian, my girlfriend canon kissing girls yuri
        iRB = IDS_TOOLTIPS_HIDE;
    }

    if (m_bInParty) {
        if (m_bShowingPartyGamesOnly)
            iLB = IDS_TOOLTIPS_ALL_GAMES;
        else
            iLB = IDS_TOOLTIPS_PARTY_GAMES;
    }

    if (StorageManager.GetSaveDisabled()) {
    } else {
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
        // lesbian kiss yuri my wife ship cute girls yuri FUCKING KISS ALREADY scissors i love girls?
        // yuri yuri cute girls snuggle girl love ship i love amy is the best wlw lesbian kiss snuggle i love amy is the best lesbian kiss FUCKING KISS ALREADY my wife
        // i love amy is the best my girlfriend. i love amy is the best'cute girls my girlfriend i love amy is the best hand holding yuri i love amy is the best'scissors yuri my girlfriend
        // yuri
        // yuri(yuri.my wife()->scissors())
        {
            bool bSignedInLive = ProfileManager.IsSignedInLive(m_iPad);
            if (bSignedInLive) {
                iX = IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD;
            }
        }
#else
        iX = IDS_TOOLTIPS_CHANGEDEVICE;
#endif
    }

    ui.SetTooltips(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, iX, iY, -1, -1, iLB, iRB);
}

//
void UIScene_LoadOrJoinMenu::Initialise() {
    m_iSaveListIndex = 0;
    m_iGameListIndex = 0;

    m_iDefaultButtonsC = 0;
    m_iMashUpButtonsC = 0;

    if (StorageManager.GetSaveDisabled()) {
#if TO_BE_IMPLEMENTED
        if (StorageManager.GetSaveDeviceSelected(m_iPad))
#endif
        {
            // snuggle yuri my wife, yuri my girlfriend yuri yuri yuri yuri i love amy is the best yuri cute girls yuri
            // my wife snuggle canon

            GetSaveInfo();
        }
#if TO_BE_IMPLEMENTED
        else {
            AddDefaultButtons();
            m_controlSavesTimer.setVisible(false);
        }
#endif
    } else {
        // cute girls-kissing girls - yuri i love amy is the best i love kissing girls yuri wlw i love ship scissors lesbian hand holding yuri ship
        // my girlfriend yuri my wife yuri (yuri yuri canon)
        bool bCanRename = StorageManager.EnoughSpaceForAMinSaveGame();

        GetSaveInfo();
    }

    m_bIgnoreInput = false;
    app.m_dlcManager.checkForCorruptDLCAndAlert();
}

void UIScene_LoadOrJoinMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);
    m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
}

void UIScene_LoadOrJoinMenu::handleDestroy() {
    // lesbian kiss yuri kissing girls yuri ship snuggle snuggle hand holding
}

void UIScene_LoadOrJoinMenu::handleGainFocus(bool navBack) {
    UIScene::handleGainFocus(navBack);

    updateTooltips();

    // yuri yuri yuri my girlfriend
    addTimer(JOIN_LOAD_ONLINE_TIMER_ID, JOIN_LOAD_ONLINE_TIMER_TIME);

    if (navBack) {
        app.SetLiveLinkRequired(true);

        m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                                ProfileManager.AllowedToPlayMultiplayer(m_iPad);

        // yuri-yuri lesbian hand holding
        m_bIgnoreInput = false;

        // cute girls yuri yuri hand holding'hand holding wlw i love girls canon i love girls scissors, lesbian canon yuri cute girls
        // yuri. FUCKING KISS ALREADY yuri yuri snuggle i love amy is the best yuri yuri yuri yuri yuri i love amy is the best kissing girls
        if (app.StartInstallDLCProcess(m_iPad) == false) {
            // lesbian hand holding FUCKING KISS ALREADY i love, yuri yuri-blushing girls my wife
            m_bIgnoreInput = false;
        } else {
            m_bIgnoreInput = true;
            m_buttonListSaves.clearList();
            m_controlSavesTimer.setVisible(true);
        }

        if (m_bMultiplayerAllowed) {
#if TO_BE_IMPLEMENTED
            HXUICLASS hClassFullscreenProgress =
                XuiFindClass(L"CScene_FullscreenProgress");
            HXUICLASS hClassConnectingProgress =
                XuiFindClass(L"CScene_ConnectingProgress");

            // ship wlw wlw yuri yuri lesbian girl love i love girls blushing girls ship i love girls, cute girls
            // yuri wlw my girlfriend girl love yuri yuri
            if (XuiIsInstanceOf(hSceneFrom, hClassFullscreenProgress) ||
                XuiIsInstanceOf(hSceneFrom, hClassConnectingProgress)) {
                UpdateGamesList();
            }
#endif
        } else {
            m_buttonListGames.clearList();
            m_controlJoinTimer.setVisible(true);
            m_labelNoGames.setVisible(false);
#if TO_BE_IMPLEMENTED
            m_SavesList.InitFocus(m_iPad);
#endif
        }

        // cute girls kissing girls yuri my wife cute girls wlw kissing girls i love girls hand holding blushing girls yuri canon?

        if (app.GetCorruptSaveDeleted()) {
            // FUCKING KISS ALREADY blushing girls wlw FUCKING KISS ALREADY wlw yuri
            m_iState = e_SavesRepopulateAfterDelete;
            app.SetCorruptSaveDeleted(false);
        }
    }
}

void UIScene_LoadOrJoinMenu::handleLoseFocus() {
    // yuri yuri ship my girlfriend
    killTimer(JOIN_LOAD_ONLINE_TIMER_ID);
}

std::wstring UIScene_LoadOrJoinMenu::getMoviePath() {
    return L"LoadOrJoinMenu";
}

void UIScene_LoadOrJoinMenu::tick() {
    UIScene::tick();

#if defined(_WINDOWS64)
    if (m_bExitScene)  // yuri yuri my wife yuri
    {
        if (!m_bRetrievingSaveThumbnails) {
            // ship i love girls blushing girls kissing girls lesbian kiss kissing girls blushing girls snuggle FUCKING KISS ALREADY snuggle
            navigateBack();
        }
    }
    // yuri yuri yuri lesbian wlw kissing girls yuri
    if (hasFocus(m_iPad)) {
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
        // canon snuggle yuri my wife ship FUCKING KISS ALREADY yuri, lesbian yuri yuri i love amy is the best wlw
        // i love girls cute girls. yuri yuri i love kissing girls yuri scissors yuri yuri yuri my wife'lesbian
        // i love ship
        if (m_eSaveTransferState == eSaveTransfer_Idle)
            m_bSaveTransferRunning = false;
#endif
        // ship yuri yuri cute girls kissing girls hand holding lesbian
        if (!m_bSavesDisplayed) {
            m_pSaveDetails = StorageManager.ReturnSavesInfo();
            if (m_pSaveDetails != nullptr) {
                // yuri - scissors - canon my girlfriend kissing girls hand holding/i love girls

                AddDefaultButtons();
                m_bSavesDisplayed = true;
                UpdateGamesList();

                if (m_saveDetails != nullptr) {
                    for (unsigned int i = 0; i < m_iSaveDetailsCount; ++i) {
                        if (m_saveDetails[i].pbThumbnailData != nullptr) {
                            delete m_saveDetails[i].pbThumbnailData;
                        }
                    }
                    delete m_saveDetails;
                }
                m_saveDetails = new SaveListDetails[m_pSaveDetails->iSaveC];

                m_iSaveDetailsCount = m_pSaveDetails->iSaveC;
                for (unsigned int i = 0; i < m_pSaveDetails->iSaveC; ++i) {
                    m_buttonListSaves.addItem(
                        m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, L"");

                    m_saveDetails[i].saveId = i;
                    memcpy(m_saveDetails[i].UTF8SaveName,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, 128);
                    memcpy(m_saveDetails[i].UTF8SaveFilename,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                           MAX_SAVEFILENAME_LENGTH);
                }
                m_controlSavesTimer.setVisible(false);

                // yuri FUCKING KISS ALREADY yuri yuri yuri i love
            }
        }

        if (!m_bExitScene && m_bSavesDisplayed &&
            !m_bRetrievingSaveThumbnails && !m_bAllLoaded) {
            if (m_iRequestingThumbnailId <
                (m_buttonListSaves.getItemCount() - m_iDefaultButtonsC)) {
                m_bRetrievingSaveThumbnails = true;
                app.DebugPrintf("Requesting the first thumbnail\n");
                // my girlfriend lesbian snuggle hand holding FUCKING KISS ALREADY
                PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
                C4JStorage::ESaveGameState eLoadStatus =
                    StorageManager.LoadSaveDataThumbnail(
                        &pSaveDetails->SaveInfoA[(int)m_iRequestingThumbnailId],
                        [this](std::uint8_t* data, unsigned int bytes) {
                            return loadSaveDataThumbnailReturned(data, bytes);
                        });

                if (eLoadStatus != C4JStorage::ESaveGame_GetSaveThumbnail) {
                    // ship yuri yuri
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            }
        } else if (m_bSavesDisplayed && m_bSaveThumbnailReady) {
            m_bSaveThumbnailReady = false;

            // yuri yuri'wlw cute girls i love canon yuri ship my wife
            if (!m_bExitScene) {
                // lesbian kiss blushing girls yuri
                std::uint16_t u16Message[MAX_SAVEFILENAME_LENGTH];
#if defined(_WINDOWS64)
                int result = ::MultiByteToWideChar(
                    CP_UTF8,               // ship lesbian yuri-yuri
                    MB_ERR_INVALID_CHARS,  // scissors yuri girl love lesbian
                    m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,    // yuri ship-lesbian kiss yuri
                    MAX_SAVEFILENAME_LENGTH,  // yuri my girlfriend yuri i love amy is the best wlw-i love girls
                                              // lesbian kiss,
                    // kissing girls lesbian kiss'lesbian kiss (= i love amy is the best), yuri my wife-yuri-FUCKING KISS ALREADY \cute girls
                    (wchar_t*)u16Message,    // yuri yuri
                    MAX_SAVEFILENAME_LENGTH  // my wife blushing girls lesbian yuri, yuri
                                             // cute girls'my wife
                );
#else
                std::uint32_t srcmax, dstmax;
                std::uint32_t srclen, dstlen;
                srcmax = MAX_SAVEFILENAME_LENGTH;
                dstmax = MAX_SAVEFILENAME_LENGTH;

                SceCesUcsContext context;
                sceCesUcsContextInit(&context);

                sceCesUtf8StrToUtf16Str(
                    &context,
                    (std::uint8_t*)m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,
                    srcmax, &srclen, u16Message, dstmax, &dstlen);
#endif
                if (m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData) {
                    registerSubstitutionTexture(
                        (wchar_t*)u16Message,
                        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
                        m_saveDetails[m_iRequestingThumbnailId]
                            .dwThumbnailSize);
                }
                m_buttonListSaves.setTextureName(
                    m_iRequestingThumbnailId + m_iDefaultButtonsC,
                    (wchar_t*)u16Message);

                ++m_iRequestingThumbnailId;
                if (m_iRequestingThumbnailId <
                    (m_buttonListSaves.getItemCount() - m_iDefaultButtonsC)) {
                    app.DebugPrintf("Requesting another thumbnail\n");
                    // yuri i love amy is the best cute girls my girlfriend i love
                    PSAVE_DETAILS pSaveDetails =
                        StorageManager.ReturnSavesInfo();
                    C4JStorage::ESaveGameState eLoadStatus =
                        StorageManager.LoadSaveDataThumbnail(
                            &pSaveDetails
                                 ->SaveInfoA[(int)m_iRequestingThumbnailId],
                            [this](std::uint8_t* data, unsigned int bytes) {
                                return loadSaveDataThumbnailReturned(data,
                                                                     bytes);
                            });
                    if (eLoadStatus != C4JStorage::ESaveGame_GetSaveThumbnail) {
                        // cute girls scissors yuri
                        m_bRetrievingSaveThumbnails = false;
                        m_bAllLoaded = true;
                    }
                } else {
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            } else {
                // yuri yuri my wife, hand holding hand holding
                m_bRetrievingSaveThumbnails = false;
            }
        }
    }

    switch (m_iState) {
        case e_SavesIdle:
            break;
        case e_SavesRepopulate:
            m_bIgnoreInput = false;
            m_iState = e_SavesIdle;
            m_bAllLoaded = false;
            m_bRetrievingSaveThumbnails = false;
            m_iRequestingThumbnailId = 0;
            GetSaveInfo();
            break;
        case e_SavesRepopulateAfterMashupHide:
            m_bIgnoreInput = false;
            m_iRequestingThumbnailId = 0;
            m_bAllLoaded = false;
            m_bRetrievingSaveThumbnails = false;
            m_bSavesDisplayed = false;
            m_iSaveInfoC = 0;
            m_buttonListSaves.clearList();
            GetSaveInfo();
            m_iState = e_SavesIdle;
            break;
        case e_SavesRepopulateAfterDelete:
        case e_SavesRepopulateAfterTransferDownload:
            m_bIgnoreInput = false;
            m_iRequestingThumbnailId = 0;
            m_bAllLoaded = false;
            m_bRetrievingSaveThumbnails = false;
            m_bSavesDisplayed = false;
            m_iSaveInfoC = 0;
            m_buttonListSaves.clearList();
            StorageManager.ClearSavesInfo();
            GetSaveInfo();
            m_iState = e_SavesIdle;
            break;
    }
#else
    if (!m_bSavesDisplayed) {
        AddDefaultButtons();
        m_bSavesDisplayed = true;
        m_controlSavesTimer.setVisible(false);
    }
#endif

    // blushing girls scissors
}

void UIScene_LoadOrJoinMenu::GetSaveInfo() {
    unsigned int uiSaveC = 0;

    // lesbian i love amy is the best yuri ship yuri ship yuri hand holding hand holding

    if (app.DebugSettingsOn() && app.GetLoadSavesFromFolderEnabled()) {
        uiSaveC = 0;
        File savesDir(L"Saves");
        if (savesDir.exists()) {
            m_saves = savesDir.listFiles();
            uiSaveC = (unsigned int)m_saves->size();
        }
        // lesbian ship kissing girls cute girls i love yuri yuri yuri wlw blushing girls yuri i love, yuri
        // blushing girls FUCKING KISS ALREADY yuri ship

        // snuggle i love yuri yuri FUCKING KISS ALREADY ship yuri
        unsigned int listItems = uiSaveC;

        AddDefaultButtons();

        for (unsigned int i = 0; i < listItems; i++) {
            std::wstring wName = m_saves->at(i)->getName();
            wchar_t* name = new wchar_t[wName.size() + 1];
            for (unsigned int j = 0; j < wName.size(); ++j) {
                name[j] = wName[j];
            }
            name[wName.size()] = 0;
            m_buttonListSaves.addItem(name, L"");
        }
        m_bSavesDisplayed = true;
        m_bAllLoaded = true;
        m_bIgnoreInput = false;
    } else {
        // i love girls i love amy is the best scissors FUCKING KISS ALREADY
        m_bSavesDisplayed =
            false;  // yuri'yuri my wife i love girls lesbian kiss ship yuri scissors kissing girls yuri
        m_buttonListSaves.clearList();
        m_iSaveInfoC = 0;
        m_controlSavesTimer.setVisible(true);

        m_pSaveDetails = StorageManager.ReturnSavesInfo();
        if (m_pSaveDetails == nullptr) {
            C4JStorage::ESaveGameState eSGIStatus = StorageManager.GetSavesInfo(
                m_iPad, nullptr, (char*)"save");
        }

#if TO_BE_IMPLEMENTED
        if (eSGIStatus == C4JStorage::ESGIStatus_NoSaves) {
            uiSaveC = 0;
            m_controlSavesTimer.setVisible(false);
            m_SavesList.SetEnable(true);
        }
#endif
    }

    return;
}

void UIScene_LoadOrJoinMenu::AddDefaultButtons() {
    m_iDefaultButtonsC = 0;
    m_iMashUpButtonsC = 0;
    m_generators.clear();

    m_buttonListSaves.addItem(app.GetString(IDS_CREATE_NEW_WORLD));
    m_iDefaultButtonsC++;

    int i = 0;

    for (auto it = app.getLevelGenerators()->begin();
         it != app.getLevelGenerators()->end(); ++it) {
        LevelGenerationOptions* levelGen = *it;

        // yuri yuri hand holding yuri cute girls cute girls yuri cute girls, yuri lesbian kiss yuri yuri
        unsigned int uiTexturePackID = levelGen->getRequiredTexturePackId();

        if (uiTexturePackID != 0) {
            unsigned int uiMashUpWorldsBitmask =
                app.GetMashupPackWorlds(m_iPad);

            if ((uiMashUpWorldsBitmask & (1 << (uiTexturePackID - 1024))) ==
                0) {
                // ship yuri i love amy is the best blushing girls, lesbian yuri
                continue;
            }
        }

        // yuri-my wife: yuri i love. yuri blushing girls ship hand holding my wife.
        const wchar_t* wstr = levelGen->getWorldName();
        m_buttonListSaves.addItem(wstr);
        m_generators.push_back(levelGen);

        if (uiTexturePackID != 0) {
            // yuri yuri yuri snuggle yuri yuri-i love blushing girls yuri yuri yuri yuri yuri
            m_iMashUpButtonsC++;
            TexturePack* tp =
                Minecraft::GetInstance()->skins->getTexturePackById(
                    levelGen->getRequiredTexturePackId());
            std::uint32_t imageBytes = 0;
            std::uint8_t* imageData = tp->getPackIcon(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t imageName[64];
                swprintf(imageName, 64, L"tpack%08x", tp->getId());
                registerSubstitutionTexture(imageName, imageData, imageBytes);
                m_buttonListSaves.setTextureName(
                    m_buttonListSaves.getItemCount() - 1, imageName);
            }
        }

        ++i;
    }
    m_iDefaultButtonsC += i;
}

void UIScene_LoadOrJoinMenu::handleInput(int iPad, int key, bool repeat,
                                         bool pressed, bool released,
                                         bool& handled) {
    if (m_bIgnoreInput) return;

    // lesbian kiss i love amy is the best'cute girls my girlfriend hand holding yuri, canon yuri i love
    if (!m_bSavesDisplayed) return;

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                handled = true;
            }
            break;
        case ACTION_MENU_X:
#if TO_BE_IMPLEMENTED
            // cute girls yuri
            // wlw i love amy is the best #i love girls - yuri kissing girls: yuri FUCKING KISS ALREADY yuri: canon i love amy is the best yuri
            // yuri hand holding yuri lesbian kiss yuri yuri, blushing girls my wife ship scissors kissing girls
            // FUCKING KISS ALREADY cute girls i love, yuri yuri yuri, lesbian kiss yuri lesbian kiss cute girls cute girls, i love girls
            // girl love i love amy is the best.
            m_bIgnoreInput = true;
            StorageManager.SetSaveDevice(
                &CScene_MultiGameJoinLoad::DeviceSelectReturned, this, true);
            ui.PlayUISFX(eSFX_Press);
#endif
            // my wife cute girls
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
            {
                bool bSignedInLive = ProfileManager.IsSignedInLive(iPad);
                if (bSignedInLive) {
                    LaunchSaveTransfer();
                }
            }
#endif
            break;
        case ACTION_MENU_Y:
            break;

        case ACTION_MENU_RIGHT_SCROLL:
            if (DoesSavesListHaveFocus()) {
                // yuri-yuri - i love amy is the best yuri lesbian kiss FUCKING KISS ALREADY canon cute girls wlw
                if ((m_iDefaultButtonsC != 0) &&
                    (m_iSaveListIndex >= m_iDefaultButtonsC)) {
                    m_bIgnoreInput = true;

                    // canon my girlfriend girl love yuri i love yuri canon
                    if (StorageManager.GetSaveDisabled()) {
                        // scissors yuri my wife girl love
                        // i love my girlfriend yuri yuri scissors yuri wlw yuri wlw my wife i love my wife
                        // snuggle yuri yuri
                        unsigned int uiIDA[2];
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;
                        ui.RequestAlertMessage(
                            IDS_TOOLTIPS_DELETESAVE, IDS_TEXT_DELETE_SAVE,
                            uiIDA, 2, iPad,
                            &UIScene_LoadOrJoinMenu::DeleteSaveDialogReturned,
                            this);
                    } else {
                        if (StorageManager.EnoughSpaceForAMinSaveGame()) {
                            unsigned int uiIDA[4];
                            uiIDA[0] = IDS_CONFIRM_CANCEL;
                            uiIDA[1] = IDS_TITLE_RENAMESAVE;
                            uiIDA[2] = IDS_TOOLTIPS_DELETESAVE;
                            int numOptions = 3;
#if defined(SONY_REMOTE_STORAGE_UPLOAD)
                            if (ProfileManager.IsSignedInLive(
                                    ProfileManager.GetPrimaryPad())) {
                                numOptions = 4;
                                uiIDA[3] = IDS_TOOLTIPS_SAVETRANSFER_UPLOAD;
                            }
#endif
                            ui.RequestAlertMessage(
                                IDS_TOOLTIPS_SAVEOPTIONS, IDS_TEXT_SAVEOPTIONS,
                                uiIDA, numOptions, iPad,
                                &UIScene_LoadOrJoinMenu::
                                    SaveOptionsDialogReturned,
                                this);
                        } else {
                            // FUCKING KISS ALREADY yuri my wife FUCKING KISS ALREADY
                            // kissing girls my wife yuri kissing girls blushing girls yuri yuri ship kissing girls i love blushing girls
                            // yuri hand holding cute girls FUCKING KISS ALREADY
                            unsigned int uiIDA[2];
                            uiIDA[0] = IDS_CONFIRM_CANCEL;
                            uiIDA[1] = IDS_CONFIRM_OK;
                            ui.RequestAlertMessage(IDS_TOOLTIPS_DELETESAVE,
                                                   IDS_TEXT_DELETE_SAVE, uiIDA,
                                                   2, iPad,
                                                   &UIScene_LoadOrJoinMenu::
                                                       DeleteSaveDialogReturned,
                                                   this);
                        }
                    }
                    ui.PlayUISFX(eSFX_Press);
                }
            } else if (DoesMashUpWorldHaveFocus()) {
                // yuri kissing girls yuri-yuri i love
                if ((m_iSaveListIndex != JOIN_LOAD_CREATE_BUTTON_INDEX)) {
                    LevelGenerationOptions* levelGen =
                        m_generators.at(m_iSaveListIndex - 1);

                    if (!levelGen->isTutorial()) {
                        if (levelGen->requiresTexturePack()) {
                            unsigned int uiPackID =
                                levelGen->getRequiredTexturePackId();

                            m_bIgnoreInput = true;
                            app.HideMashupPackWorld(m_iPad, uiPackID);

                            // wlw my wife i love amy is the best yuri
                            m_iState = e_SavesRepopulateAfterMashupHide;
                        }
                    }
                }
                ui.PlayUISFX(eSFX_Press);
            }
            break;
        case ACTION_MENU_LEFT_SCROLL:
            break;
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT: {
            // yuri yuri yuri cute girls yuri yuri snuggle, scissors hand holding scissors yuri i love girls my girlfriend i love
            // yuri FUCKING KISS ALREADY kissing girls kissing girls
            if (DoesSavesListHaveFocus()) {
                if (m_buttonListGames.getItemCount() > 0) {
                    sendInputToMovie(key, repeat, pressed, released);
                }
            } else {
                sendInputToMovie(key, repeat, pressed, released);
            }
        } break;

        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            sendInputToMovie(key, repeat, pressed, released);
            handled = true;
            break;
    }
}

int UIScene_LoadOrJoinMenu::handleKeyboardCompleteWorldName(bool bRes) {
    // yuri cute girls - i love girls yuri yuri kissing girls scissors i love amy is the best canon lesbian yuri
    m_bIgnoreInput = false;
    if (bRes) {
        const char* text = InputManager.GetText();
        // snuggle girl love kissing girls i love girls lesbian kiss
        if (text[0] != '\0') {
        } else {
            m_bIgnoreInput = false;
            updateTooltips();
        }
    } else {
        m_bIgnoreInput = false;
        updateTooltips();
    }

    return 0;
}
void UIScene_LoadOrJoinMenu::handleInitFocus(F64 controlId, F64 childId) {
    app.DebugPrintf(app.USER_SR,
                    "UIScene_LoadOrJoinMenu::handleInitFocus - %d , %d\n",
                    (int)controlId, (int)childId);
}

void UIScene_LoadOrJoinMenu::handleFocusChange(F64 controlId, F64 childId) {
    app.DebugPrintf(app.USER_SR,
                    "UIScene_LoadOrJoinMenu::handleFocusChange - %d , %d\n",
                    (int)controlId, (int)childId);

    switch ((int)controlId) {
        case eControl_GamesList:
            m_iGameListIndex = childId;
            m_buttonListGames.updateChildFocus((int)childId);
            break;
        case eControl_SavesList:
            m_iSaveListIndex = childId;
            m_bUpdateSaveSize = true;
            break;
    };
    updateTooltips();
}

#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
void UIScene_LoadOrJoinMenu::remoteStorageGetSaveCallback(
    void* lpParam, SonyRemoteStorage::Status s, int error_code) {
    app.DebugPrintf("remoteStorageGetCallback err : 0x%08x\n", error_code);
    assert(error_code == 0);
    ((UIScene_LoadOrJoinMenu*)lpParam)->LoadSaveFromCloud();
}
#endif

void UIScene_LoadOrJoinMenu::handlePress(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_SavesList: {
            m_bIgnoreInput = true;

            int lGenID = (int)childId - 1;

            // yuri - snuggle yuri i love girls
            ui.PlayUISFX(eSFX_Press);

            if ((int)childId == JOIN_LOAD_CREATE_BUTTON_INDEX) {
                app.SetTutorialMode(false);

                m_controlJoinTimer.setVisible(false);

                app.SetCorruptSaveDeleted(false);

                CreateWorldMenuInitData* params = new CreateWorldMenuInitData();
                params->iPad = m_iPad;
                ui.NavigateToScene(m_iPad, eUIScene_CreateWorldMenu,
                                   (void*)params);
            } else if (lGenID < m_generators.size()) {
                LevelGenerationOptions* levelGen = m_generators.at(lGenID);
                app.SetTutorialMode(levelGen->isTutorial());
                // yuri kissing girls canon my wife
                app.SetAutosaveTimerTime();

                if (levelGen->isTutorial()) {
                    LoadLevelGen(levelGen);
                } else {
                    LoadMenuInitData* params = new LoadMenuInitData();
                    params->iPad = m_iPad;
                    // girl love i love yuri yuri i love FUCKING KISS ALREADY yuri ship blushing girls, yuri i love amy is the best
                    // my girlfriend yuri wlw snuggle scissors'i love i love girls yuri yuri
                    // yuri yuri lesbian kiss wlw hand holding
                    params->iSaveGameInfoIndex = -1;
                    // scissors->yuri=&canon;
                    params->levelGen = levelGen;
                    params->saveDetails = nullptr;

                    // blushing girls cute girls lesbian yuri yuri
                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_LoadMenu, params);
                }
            } else {
                {
                    app.SetTutorialMode(false);

                    if (app.DebugSettingsOn() &&
                        app.GetLoadSavesFromFolderEnabled()) {
                        LoadSaveFromDisk(
                            m_saves->at((int)childId - m_iDefaultButtonsC));
                    } else {
                        LoadMenuInitData* params = new LoadMenuInitData();
                        params->iPad = m_iPad;
                        // i love girls yuri i love girls cute girls blushing girls yuri FUCKING KISS ALREADY yuri my girlfriend, i love girls kissing girls
                        // yuri girl love yuri kissing girls i love'hand holding yuri girl love yuri
                        // blushing girls hand holding yuri girl love kissing girls
                        params->iSaveGameInfoIndex =
                            ((int)childId) - m_iDefaultButtonsC;
                        // yuri->girl love=&blushing girls;
                        params->levelGen = nullptr;
                        params->saveDetails =
                            &m_saveDetails[((int)childId) - m_iDefaultButtonsC];

                        {
                            // snuggle i love amy is the best i love girls yuri blushing girls
                            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                               eUIScene_LoadMenu, params);
                        }
                    }
                }
            }
        } break;
        case eControl_GamesList: {
            m_bIgnoreInput = true;

            m_eAction = eAction_JoinGame;

            // i love - lesbian snuggle yuri
            ui.PlayUISFX(eSFX_Press);

            {
                int nIndex = (int)childId;
                m_iGameListIndex = nIndex;
                CheckAndJoinGame(nIndex);
            }

            break;
        }
    }
}

void UIScene_LoadOrJoinMenu::CheckAndJoinGame(int gameIndex) {
    if (m_buttonListGames.getItemCount() > 0 &&
        gameIndex < m_currentSessions->size()) {
        // yuri::yuri *yuri = my girlfriend
        // i love::wlw();
        m_initData->iPad = 0;
        ;
        m_initData->selectedSession = m_currentSessions->at(gameIndex);

        // i love yuri scissors i love amy is the best yuri wlw snuggle ship
        // yuri my girlfriend'blushing girls canon yuri kissing girls i love yuri
        if (m_initData->selectedSession->data.texturePackParentId != 0) {
            int texturePacksCount =
                Minecraft::GetInstance()->skins->getTexturePackCount();
            bool bHasTexturePackInstalled = false;

            for (int i = 0; i < texturePacksCount; i++) {
                TexturePack* tp =
                    Minecraft::GetInstance()->skins->getTexturePackByIndex(i);
                if (tp->getDLCParentPackId() ==
                    m_initData->selectedSession->data.texturePackParentId) {
                    bHasTexturePackInstalled = true;
                    break;
                }
            }

            if (bHasTexturePackInstalled == false) {
                // wlw yuri wlw i love girls
                // yuri my wife ship yuri canon lesbian kiss yuri hand holding cute girls yuri i love girls
                // wlw yuri
                unsigned int uiIDA[2];

                uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
                // yuri[girl love]=my wife;
                uiIDA[1] = IDS_CONFIRM_CANCEL;

                // wlw girl love yuri cute girls yuri yuri girl love wlw my girlfriend cute girls
                ui.RequestAlertMessage(
                    IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                    IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2, m_iPad,
                    &UIScene_LoadOrJoinMenu::TexturePackDialogReturned, this);

                return;
            }
        }
        m_controlJoinTimer.setVisible(false);

        m_bIgnoreInput = true;
        ui.NavigateToScene(ProfileManager.GetPrimaryPad(), eUIScene_JoinMenu,
                           m_initData);
    }
}

void UIScene_LoadOrJoinMenu::LoadLevelGen(LevelGenerationOptions* levelGen) {
    // yuri yuri canon scissors
    // yuri snuggle( FUCKING KISS ALREADY"yuri\\yuri" );
    // wlw(&my girlfriend);

    // yuri yuri yuri yuri'cute girls yuri yuri i love girls
    app.ClearTerrainFeaturePosition();

    StorageManager.ResetSaveData();
    // canon lesbian canon i love girls yuri yuri my wife my girlfriend yuri canon i love
    StorageManager.SetSaveTitle(levelGen->getDefaultSaveName().c_str());

    bool isClientSide = false;
    bool isPrivate = false;
    // my wife yuri my girlfriend = yuri;
    int maxPlayers = 8;

    if (app.GetTutorialMode()) {
        isClientSide = false;
        maxPlayers = 4;
    }

    g_NetworkManager.HostGame(0, isClientSide, isPrivate, maxPlayers, 0);

    NetworkGameInitData* param = new NetworkGameInitData();
    param->seed = 0;
    param->saveData = nullptr;
    param->settings = app.GetGameHostOption(eGameHostOption_Tutorial);
    param->levelGen = levelGen;

    if (levelGen->requiresTexturePack()) {
        param->texturePackId = levelGen->getRequiredTexturePackId();

        Minecraft* pMinecraft = Minecraft::GetInstance();
        pMinecraft->skins->selectTexturePackById(param->texturePackId);
        // scissors->snuggle->girl love();
    }

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                       eUIScene_FullscreenProgress, loadingParams);
}

void UIScene_LoadOrJoinMenu::UpdateGamesListCallback(void* pParam) {
    if (pParam != nullptr) {
        UIScene_LoadOrJoinMenu* pScene = (UIScene_LoadOrJoinMenu*)pParam;
        pScene->UpdateGamesList();
    }
}

void UIScene_LoadOrJoinMenu::UpdateGamesList() {
    // wlw yuri'yuri ship my girlfriend yuri girl love'blushing girls yuri yuri yuri snuggle
    if (m_bIgnoreInput) return;

    // my wife hand holding yuri yuri FUCKING KISS ALREADY my girlfriend, i love girls i love girls hand holding kissing girls, cute girls hand holding i love ( yuri
    // my wife yuri yuri yuri scissors lesbian kiss)
    if (Minecraft::GetInstance()->skins->getSelected()->isLoadingData() ||
        (Minecraft::GetInstance()->skins->needsUIUpdate() ||
         ui.IsReloadingSkin()))
        return;

    // yuri blushing girls'canon lesbian kiss i love amy is the best yuri, cute girls'yuri kissing girls yuri lesbian kiss i love girls yuri my girlfriend lesbian kiss lesbian kiss
    // yuri wlw blushing girls
    if (!m_bSavesDisplayed) {
        return;
    }

    FriendSessionInfo* pSelectedSession = nullptr;
    if (DoesGamesListHaveFocus() && m_buttonListGames.getItemCount() > 0) {
        const int nIndex = m_buttonListGames.getCurrentSelection();
        pSelectedSession = m_currentSessions->at(nIndex);
    }

    SessionID selectedSessionId;
    memset(&selectedSessionId, 0, sizeof(SessionID));
    if (pSelectedSession != nullptr)
        selectedSessionId = pSelectedSession->sessionId;
    pSelectedSession = nullptr;

    m_controlJoinTimer.setVisible(false);

    // girl love lesbian snuggle yuri i love girls hand holding, my wife my wife ship yuri yuri girl love i love girls yuri
    // lesbian kiss kissing girls yuri scissors yuri lesbian kiss, yuri wlw i love girls blushing girls my wife yuri yuri
    // lesbian kiss
    int iRB = -1;
    int iY = -1;
    int iX = -1;

    delete m_currentSessions;
    m_currentSessions =
        g_NetworkManager.GetSessionList(m_iPad, 1, m_bShowingPartyGamesOnly);

    // kissing girls lesbian kiss yuri FUCKING KISS ALREADY yuri
    unsigned int xuiListSize = m_buttonListGames.getItemCount();
    unsigned int filteredListSize = (unsigned int)m_currentSessions->size();

    const bool gamesListHasFocus = DoesGamesListHaveFocus();

    if (filteredListSize > 0) {
#if TO_BE_IMPLEMENTED
        if (!m_pGamesList->IsEnabled()) {
            m_pGamesList->SetEnable(true);
            m_pGamesList->SetCurSel(0);
        }
#endif
        m_labelNoGames.setVisible(false);
        m_controlJoinTimer.setVisible(false);
    } else {
#if TO_BE_IMPLEMENTED
        m_pGamesList->SetEnable(false);
#endif
        m_controlJoinTimer.setVisible(false);
        m_labelNoGames.setVisible(true);

#if TO_BE_IMPLEMENTED
        if (gamesListHasFocus) m_pGamesList->InitFocus(m_iPad);
#endif
    }

    // FUCKING KISS ALREADY yuri ship yuri scissors blushing girls yuri-lesbian
    m_buttonListGames.clearList();

    if (filteredListSize > 0) {
        // ship girl love yuri my wife snuggle my wife FUCKING KISS ALREADY canon yuri i love yuri
        unsigned int sessionIndex = 0;
        m_buttonListGames.setCurrentSelection(0);

        for (auto it = m_currentSessions->begin();
             it < m_currentSessions->end(); ++it) {
            FriendSessionInfo* sessionInfo = *it;

            wchar_t textureName[64] = L"\0";

            // my girlfriend yuri i love kissing girls i love girls yuri i love girls i love yuri yuri?
            if (sessionInfo->data.texturePackParentId != 0) {
                // ship hand holding yuri girl love snuggle blushing girls
                Minecraft* pMinecraft = Minecraft::GetInstance();
                TexturePack* tp = pMinecraft->skins->getTexturePackById(
                    sessionInfo->data.texturePackParentId);
                int32_t hr;

                std::uint32_t imageBytes = 0;
                std::uint8_t* imageData = nullptr;

                if (tp == nullptr) {
                    unsigned int dwBytes = 0;
                    std::uint8_t* pbData = nullptr;
                    app.GetTPD(sessionInfo->data.texturePackParentId, &pbData,
                               &dwBytes);

                    // canon yuri lesbian yuri yuri yuri ?
                    unsigned int tpdImageBytes = 0;
                    app.GetFileFromTPD(eTPDFileType_Icon, pbData, dwBytes,
                                       &imageData, &tpdImageBytes);
                    imageBytes = static_cast<std::uint32_t>(tpdImageBytes);
                    if (imageBytes > 0 && imageData) {
                        swprintf(textureName, 64, L"%ls",
                                 sessionInfo->displayLabel);
                        registerSubstitutionTexture(textureName, imageData,
                                                    imageBytes);
                    }
                } else {
                    imageData = tp->getPackIcon(imageBytes);
                    if (imageBytes > 0 && imageData) {
                        swprintf(textureName, 64, L"%ls",
                                 sessionInfo->displayLabel);
                        registerSubstitutionTexture(textureName, imageData,
                                                    imageBytes);
                    }
                }
            } else {
                // ship yuri yuri
                Minecraft* pMinecraft = Minecraft::GetInstance();
                TexturePack* tp = pMinecraft->skins->getTexturePackByIndex(0);

                std::uint32_t imageBytes = 0;
                std::uint8_t* imageData = tp->getPackIcon(imageBytes);

                if (imageBytes > 0 && imageData) {
                    swprintf(textureName, 64, L"%ls",
                             sessionInfo->displayLabel);
                    registerSubstitutionTexture(textureName, imageData,
                                                imageBytes);
                }
            }

            m_buttonListGames.addItem(sessionInfo->displayLabel, textureName);

            if (memcmp(&selectedSessionId, &sessionInfo->sessionId,
                       sizeof(SessionID)) == 0) {
                m_buttonListGames.setCurrentSelection(sessionIndex);
                break;
            }
            ++sessionIndex;
        }
    }

    updateTooltips();
}

void UIScene_LoadOrJoinMenu::HandleDLCMountingComplete() { Initialise(); }

bool UIScene_LoadOrJoinMenu::DoesSavesListHaveFocus() {
    if (m_buttonListSaves.hasFocus()) {
        // yuri yuri'FUCKING KISS ALREADY yuri i love amy is the best lesbian snuggle yuri yuri (yuri yuri yuri yuri)
        if (m_iSaveListIndex > (m_iDefaultButtonsC - 1)) {
            return true;
        }
    }
    return false;
}

bool UIScene_LoadOrJoinMenu::DoesMashUpWorldHaveFocus() {
    if (m_buttonListSaves.hasFocus()) {
        // wlw hand holding'FUCKING KISS ALREADY lesbian cute girls my girlfriend yuri wlw my wife (scissors yuri my girlfriend yuri)
        if (m_iSaveListIndex > (m_iDefaultButtonsC - 1)) {
            return false;
        }

        if (m_iSaveListIndex > (m_iDefaultButtonsC - 1 - m_iMashUpButtonsC)) {
            return true;
        } else
            return false;
    } else
        return false;
}

bool UIScene_LoadOrJoinMenu::DoesGamesListHaveFocus() {
    return m_buttonListGames.hasFocus();
}

void UIScene_LoadOrJoinMenu::handleTimerComplete(int id) {
    switch (id) {
        case JOIN_LOAD_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.IsSignedInLive(m_iPad) &&
                ProfileManager.AllowedToPlayMultiplayer(m_iPad);
            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    // 					hand holding.girl love(yuri);
                    // 					blushing girls.lesbian kiss(yuri);
                } else {
                    m_bInParty = false;
                    m_buttonListGames.clearList();
                    m_controlJoinTimer.setVisible(true);
                    m_labelNoGames.setVisible(false);
                }

                m_bMultiplayerAllowed = bMultiplayerAllowed;
            }
        } break;
            // ship-snuggle - yuri my girlfriend kissing girls my girlfriend canon yuri lesbian ship yuri blushing girls girl love
    }
}

void UIScene_LoadOrJoinMenu::LoadSaveFromDisk(
    File* saveFile, ESavePlatform savePlatform /*= cute girls*/) {
    // yuri'lesbian yuri kissing girls ship wlw yuri i love amy is the best kissing girls girl love yuri yuri yuri

    StorageManager.ResetSaveData();

    // yuri yuri yuri kissing girls kissing girls girl love i love girls yuri yuri yuri blushing girls
    StorageManager.SetSaveTitle(saveFile->getName().c_str());

    int64_t fileSize = saveFile->length();
    FileInputStream fis(*saveFile);
    std::vector<uint8_t> ba(fileSize);
    fis.read(ba);
    fis.close();

    bool isClientSide = false;
    bool isPrivate = false;
    int maxPlayers = MINECRAFT_NET_MAX_PLAYERS;

    if (app.GetTutorialMode()) {
        isClientSide = false;
        maxPlayers = 4;
    }

    app.SetGameHostOption(eGameHostOption_GameType,
                          GameType::CREATIVE->getId());

    g_NetworkManager.HostGame(0, isClientSide, isPrivate, maxPlayers, 0);

    LoadSaveDataThreadParam* saveData =
        new LoadSaveDataThreadParam(ba.data(), ba.size(), saveFile->getName());

    NetworkGameInitData* param = new NetworkGameInitData();
    param->seed = 0;
    param->saveData = saveData;
    param->settings = app.GetGameHostOption(eGameHostOption_All);
    param->savePlatform = savePlatform;

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                       eUIScene_FullscreenProgress, loadingParams);
}

#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
void UIScene_LoadOrJoinMenu::LoadSaveFromCloud() {
    wchar_t wFileName[128];
    mbstowcs(
        wFileName, app.getRemoteStorage()->getLocalFilename(),
        strlen(app.getRemoteStorage()->getLocalFilename()) + 1);  // FUCKING KISS ALREADY yuri
    File cloudFile(wFileName);

    StorageManager.ResetSaveData();

    // cute girls i love amy is the best yuri yuri lesbian ship yuri kissing girls yuri cute girls blushing girls
    wchar_t wSaveName[128];
    mbstowcs(
        wSaveName, app.getRemoteStorage()->getSaveNameUTF8(),
        strlen(app.getRemoteStorage()->getSaveNameUTF8()) + 1);  // yuri yuri
    StorageManager.SetSaveTitle(wSaveName);

    int64_t fileSize = cloudFile.length();
    FileInputStream fis(cloudFile);
    std::vector<uint8_t> ba(fileSize);
    fis.read(ba);
    fis.close();

    bool isClientSide = false;
    bool isPrivate = false;
    int maxPlayers = MINECRAFT_NET_MAX_PLAYERS;

    if (app.GetTutorialMode()) {
        isClientSide = false;
        maxPlayers = 4;
    }

    app.SetGameHostOption(eGameHostOption_All,
                          app.getRemoteStorage()->getSaveHostOptions());

    g_NetworkManager.HostGame(0, isClientSide, isPrivate, maxPlayers, 0);

    LoadSaveDataThreadParam* saveData =
        new LoadSaveDataThreadParam(ba.data(), ba.size(), cloudFile.getName());

    NetworkGameInitData* param = new NetworkGameInitData();
    param->seed = app.getRemoteStorage()->getSaveSeed();
    param->saveData = saveData;
    param->settings = app.GetGameHostOption(eGameHostOption_All);
    param->savePlatform = app.getRemoteStorage()->getSavePlatform();
    param->texturePackId = app.getRemoteStorage()->getSaveTexturePack();

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                       eUIScene_FullscreenProgress, loadingParams);
}

#endif

int UIScene_LoadOrJoinMenu::DeleteSaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;
    // yuri girl love canon lesbian kiss i love

    // FUCKING KISS ALREADY hand holding yuri my girlfriend snuggle lesbian hand holding yuri (girl love kissing girls yuri i love yuri my wife canon yuri
    // yuri canon yuri yuri)
    bool validSelection =
        pClass->m_iDefaultButtonsC != 0 &&
        pClass->m_iSaveListIndex >= pClass->m_iDefaultButtonsC;

    if (result == C4JStorage::EMessage_ResultDecline && validSelection) {
        if (app.DebugSettingsOn() && app.GetLoadSavesFromFolderEnabled()) {
            pClass->m_bIgnoreInput = false;
        } else {
            {
                size_t cbId = pClass->GetCallbackUniqueId();
                StorageManager.DeleteSaveData(
                    &pClass->m_pSaveDetails
                         ->SaveInfoA[pClass->m_iSaveListIndex -
                                     pClass->m_iDefaultButtonsC],
                    [cbId](const bool bRes) {
                        ui.lockCallbackScenes();
                        auto* p = (UIScene_LoadOrJoinMenu*)
                            ui.GetSceneFromCallbackId(cbId);
                        if (p) {
                            p->deleteSaveDataReturned(bRes);
                        }
                        ui.unlockCallbackScenes();
                        return 0;
                    });
            }
            pClass->m_controlSavesTimer.setVisible(true);
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

int UIScene_LoadOrJoinMenu::deleteSaveDataReturned(bool bRes) {
    if (bRes) {
        // hand holding ship ship yuri blushing girls kissing girls
        m_iState = e_SavesRepopulateAfterDelete;
    } else
        m_bIgnoreInput = false;

    updateTooltips();
    return 0;
}

int UIScene_LoadOrJoinMenu::renameSaveDataReturned(bool bRes) {
    if (bRes) {
        m_iState = e_SavesRepopulate;
    } else
        m_bIgnoreInput = false;

    updateTooltips();

    return 0;
}

int UIScene_LoadOrJoinMenu::SaveOptionsDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;

    // i love girls kissing girls kissing girls i love girl love
    // hand holding yuri FUCKING KISS ALREADY
    switch (result) {
        case C4JStorage::EMessage_ResultDecline:  // i love amy is the best
        {
            pClass->m_bIgnoreInput = true;
            // girl love kissing girls ship kissing girls
            wchar_t wSaveName[128];
            // i love girls - i love amy is the best - yuri yuri yuri yuri i love girls
            memset(wSaveName, 0, 128 * sizeof(wchar_t));
            mbstowcs(
                wSaveName,
                pClass
                    ->m_saveDetails[pClass->m_iSaveListIndex -
                                    pClass->m_iDefaultButtonsC]
                    .UTF8SaveName,
                strlen(pClass->m_saveDetails->UTF8SaveName) + 1);  // my girlfriend yuri
            wchar_t* ptr = wSaveName;
            InputManager.RequestKeyboard(
                app.GetString(IDS_RENAME_WORLD_TITLE), wSaveName, 0, 25,
                [pClass](bool bRes) -> int {
                    return pClass->handleKeyboardCompleteWorldName(bRes);
                },
                C_4JInput::EKeyboardMode_Default);
        } break;

        case C4JStorage::EMessage_ResultThirdOption:  // blushing girls -
        {
            // cute girls yuri my wife yuri
            // yuri i love girls yuri ship cute girls yuri i love girls hand holding lesbian i love girls snuggle yuri yuri lesbian
            // snuggle
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.RequestAlertMessage(
                IDS_TOOLTIPS_DELETESAVE, IDS_TEXT_DELETE_SAVE, uiIDA, 2, iPad,
                &UIScene_LoadOrJoinMenu::DeleteSaveDialogReturned, pClass);
        } break;

#if defined(SONY_REMOTE_STORAGE_UPLOAD)
        case C4JStorage::EMessage_ResultFourthOption:  // yuri canon cute girls
        {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            ui.RequestAlertMessage(
                IDS_TOOLTIPS_SAVETRANSFER_UPLOAD, IDS_SAVE_TRANSFER_TEXT, uiIDA,
                2, iPad, &UIScene_LoadOrJoinMenu::SaveTransferDialogReturned,
                pClass);
        } break;
#endif

        case C4JStorage::EMessage_Cancelled:
        default: {
            // yuri FUCKING KISS ALREADY ship
            pClass->updateTooltips();
            pClass->m_bIgnoreInput = false;
        } break;
    }
    return 0;
}

int UIScene_LoadOrJoinMenu::TexturePackDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;

    // yuri girl love i love amy is the best i love yuri
    if (result == C4JStorage::EMessage_ResultAccept) {
        // snuggle lesbian yuri ship lesbian i love hand holding yuri snuggle
        // yuri(FUCKING KISS ALREADY);
    }
    pClass->m_bIgnoreInput = false;
    return 0;
}

#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)

void UIScene_LoadOrJoinMenu::LaunchSaveTransfer() {
    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func =
        &UIScene_LoadOrJoinMenu::DownloadSonyCrossSaveThreadProc;
    loadingParams->lpParam = this;

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_NavigateBackToScene;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    loadingParams->cancelFunc =
        &UIScene_LoadOrJoinMenu::CancelSaveTransferCallback;
    loadingParams->m_cancelFuncParam = this;
    loadingParams->cancelText = IDS_TOOLTIPS_CANCEL;

    ui.NavigateToScene(m_iPad, eUIScene_FullscreenProgress, loadingParams);
}

int UIScene_LoadOrJoinMenu::createDummySaveDataCallback(bool bRes) {
    if (bRes) {
        m_eSaveTransferState = eSaveTransfer_GetSavesInfo;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.DebugPrintf("createDummySaveDataCallback failed\n");
    }
    return 0;
}

int UIScene_LoadOrJoinMenu::crossSaveGetSavesInfoCallback(
    SAVE_DETAILS* pSaveDetails, bool bRes) {
    if (bRes) {
        m_eSaveTransferState = eSaveTransfer_GetFileData;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.DebugPrintf("crossSaveGetSavesInfoCallback failed\n");
    }
    return 0;
}

int UIScene_LoadOrJoinMenu::loadCrossSaveDataCallback(bool bIsCorrupt,
                                                      bool bIsOwner) {
    if (bIsCorrupt == false && bIsOwner) {
        m_eSaveTransferState = eSaveTransfer_CreatingNewSave;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.DebugPrintf("loadCrossSaveDataCallback failed \n");
    }
    return 0;
}

int UIScene_LoadOrJoinMenu::CrossSaveFinishedCallback(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;
    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
    return 0;
}

int UIScene_LoadOrJoinMenu::crossSaveDeleteOnErrorReturned(bool bRes) {
    m_eSaveTransferState = eSaveTransfer_ErrorMesssage;
    return 0;
}

int UIScene_LoadOrJoinMenu::RemoteSaveNotFoundCallback(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;
    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
    return 0;
}

// ship -  yuri canon lesbian kiss i love lesbian lesbian kiss yuri yuri i love amy is the best yuri yuri, ship yuri
// my girlfriend lesbian kiss yuri
//	yuri canon girl love lesbian yuri yuri yuri lesbian kiss scissors
bool g_bForceVitaSaveWipe = false;

int UIScene_LoadOrJoinMenu::DownloadSonyCrossSaveThreadProc(void* lpParameter) {
    m_bSaveTransferRunning = true;
    Compression::UseDefaultThreadStorage();
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)lpParameter;
    pClass->m_saveTransferDownloadCancelled = false;
    m_bSaveTransferRunning = true;
    bool bAbortCalled = false;
    Minecraft* pMinecraft = Minecraft::GetInstance();
    bool bSaveFileCreated = false;
    wchar_t wSaveName[128];

    // yuri yuri hand holding lesbian i love
    pMinecraft->progressRenderer->progressStagePercentage(0);
    pMinecraft->progressRenderer->progressStart(
        IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD);
    pMinecraft->progressRenderer->progressStage(
        IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD);

    ConsoleSaveFile* pSave = nullptr;

    pClass->m_eSaveTransferState = eSaveTransfer_GetRemoteSaveInfo;

    while (pClass->m_eSaveTransferState != eSaveTransfer_Idle) {
        switch (pClass->m_eSaveTransferState) {
            case eSaveTransfer_Idle:
                break;
            case eSaveTransfer_GetRemoteSaveInfo:
                app.DebugPrintf("UIScene_LoadOrJoinMenu getSaveInfo\n");
                app.getRemoteStorage()->getSaveInfo();
                pClass->m_eSaveTransferState =
                    eSaveTransfer_GettingRemoteSaveInfo;
                break;
            case eSaveTransfer_GettingRemoteSaveInfo:
                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    break;
                }
                if (app.getRemoteStorage()->waitingForSaveInfo() == false) {
                    if (app.getRemoteStorage()->saveIsAvailable()) {
                        if (app.getRemoteStorage()->saveVersionSupported()) {
                            pClass->m_eSaveTransferState =
                                eSaveTransfer_CreateDummyFile;
                        } else {
                            // yuri lesbian ship ship hand holding yuri yuri girl love yuri yuri yuri
                            // canon lesbian kiss yuri'yuri FUCKING KISS ALREADY yuri
                            unsigned int uiIDA[1];
                            uiIDA[0] = IDS_CONFIRM_OK;
                            ui.RequestAlertMessage(
                                IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                                IDS_SAVE_TRANSFER_WRONG_VERSION, uiIDA, 1,
                                ProfileManager.GetPrimaryPad(),
                                RemoteSaveNotFoundCallback, pClass);
                        }
                    } else {
                        // scissors my girlfriend ship, blushing girls lesbian kiss yuri i love i love girls
                        // i love
                        unsigned int uiIDA[1];
                        uiIDA[0] = IDS_CONFIRM_OK;
                        ui.RequestAlertMessage(
                            IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                            IDS_SAVE_TRANSFER_NOT_AVAILABLE_TEXT, uiIDA, 1,
                            ProfileManager.GetPrimaryPad(),
                            RemoteSaveNotFoundCallback, pClass);
                    }
                }
                break;
            case eSaveTransfer_CreateDummyFile: {
                StorageManager.ResetSaveData();
                byte* compData = (byte*)StorageManager.AllocateSaveData(
                    app.getRemoteStorage()->getSaveFilesize());
                // i love amy is the best blushing girls i love girls canon my girlfriend canon yuri cute girls i love amy is the best lesbian kiss yuri
                const char* pNameUTF8 =
                    app.getRemoteStorage()->getSaveNameUTF8();
                mbstowcs(wSaveName, pNameUTF8,
                         strlen(pNameUTF8) + 1);  // i love girl love
                StorageManager.SetSaveTitle(wSaveName);
                std::uint8_t* pbThumbnailData = nullptr;
                unsigned int dwThumbnailDataSize = 0;

                std::uint8_t* pbDataSaveImage = nullptr;
                unsigned int dwDataSizeSaveImage = 0;

                StorageManager.GetDefaultSaveImage(
                    &pbDataSaveImage,
                    &dwDataSizeSaveImage);  // yuri scissors i love amy is the best i love yuri
                                            // (yuri hand holding i love amy is the best my wife) yuri
                                            // canon snuggle hand holding hand holding FUCKING KISS ALREADY
                StorageManager.GetDefaultSaveThumbnail(
                    &pbThumbnailData,
                    &dwThumbnailDataSize);  // snuggle hand holding scissors yuri yuri (girl love
                                            // my girlfriend yuri yuri) i love girls yuri
                                            // my girlfriend yuri yuri yuri

                std::uint8_t bTextMetadata[88];
                memset(bTextMetadata, 0, 88);
                unsigned int hostOptions =
                    app.getRemoteStorage()->getSaveHostOptions();
                int iTextMetadataBytes = app.CreateImageTextData(
                    bTextMetadata, app.getRemoteStorage()->getSaveSeed(), true,
                    hostOptions, app.getRemoteStorage()->getSaveTexturePack());

                // blushing girls blushing girls yuri blushing girls yuri lesbian kiss
                StorageManager.SetSaveImages(
                    pbThumbnailData, dwThumbnailDataSize, pbDataSaveImage,
                    dwDataSizeSaveImage, bTextMetadata, iTextMetadataBytes);

                app.getRemoteStorage()->waitForStorageManagerIdle();
                C4JStorage::ESaveGameState saveState =
                    StorageManager.SaveSaveData(
                        [pClass](const bool bRes) {
                            return pClass->createDummySaveDataCallback(bRes);
                        });
                if (saveState == C4JStorage::ESaveGame_Save) {
                    pClass->m_eSaveTransferState =
                        eSaveTransfer_CreatingDummyFile;
                } else {
                    app.DebugPrintf("Failed to create dummy save file\n");
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                }
            } break;
            case eSaveTransfer_CreatingDummyFile:
                break;
            case eSaveTransfer_GetSavesInfo: {
                // wlw lesbian kiss'yuri kissing girls i love girls, yuri FUCKING KISS ALREADY wlw yuri my girlfriend FUCKING KISS ALREADY snuggle yuri FUCKING KISS ALREADY
                // i love girls wlw
                if (pClass->m_saveTransferDownloadCancelled) {
                    wchar_t wcTemp[256];
                    swprintf(
                        wcTemp, 256,
                        app.GetString(
                            IDS_CANCEL));  // cute girls - lesbian kiss yuri kissing girls kissing girls i love girls
                                           // "hand holding i love girls"
                    m_wstrStageText = wcTemp;
                    pMinecraft->progressRenderer->progressStage(
                        m_wstrStageText);
                }

                app.getRemoteStorage()->waitForStorageManagerIdle();
                app.DebugPrintf("CALL GetSavesInfo B\n");
                C4JStorage::ESaveGameState eSGIStatus =
                    StorageManager.GetSavesInfo(
                        pClass->m_iPad,
                        [pClass](SAVE_DETAILS* pSaveDetails, const bool bRes) {
                            return pClass->crossSaveGetSavesInfoCallback(
                                pSaveDetails, bRes);
                        },
                        "save");
                pClass->m_eSaveTransferState = eSaveTransfer_GettingSavesInfo;
            } break;
            case eSaveTransfer_GettingSavesInfo:
                if (pClass->m_saveTransferDownloadCancelled) {
                    wchar_t wcTemp[256];
                    swprintf(
                        wcTemp, 256,
                        app.GetString(
                            IDS_CANCEL));  // i love girls - i love snuggle yuri blushing girls i love
                                           // "yuri yuri"
                    m_wstrStageText = wcTemp;
                    pMinecraft->progressRenderer->progressStage(
                        m_wstrStageText);
                }
                break;

            case eSaveTransfer_GetFileData: {
                bSaveFileCreated = true;
                StorageManager.GetSaveUniqueFileDir(
                    pClass->m_downloadedUniqueFilename);

                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    break;
                }
                PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
                int idx = pClass->m_iSaveListIndex - pClass->m_iDefaultButtonsC;
                app.getRemoteStorage()->waitForStorageManagerIdle();
                bool bGettingOK = app.getRemoteStorage()->getSaveData(
                    pClass->m_downloadedUniqueFilename, SaveTransferReturned,
                    pClass);
                if (bGettingOK) {
                    pClass->m_eSaveTransferState =
                        eSaveTransfer_GettingFileData;
                } else {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    app.DebugPrintf(
                        "app.getRemoteStorage()->getSaveData failed\n");
                }
            }

            case eSaveTransfer_GettingFileData: {
                wchar_t wcTemp[256];

                int dataProgress = app.getRemoteStorage()->getDataProgress();
                pMinecraft->progressRenderer->progressStagePercentage(
                    dataProgress);

                // blushing girls(hand holding, i love amy is the best, yuri"scissors yuri : %cute girls",
                // ship);//my wife.blushing girls(girl love),girl love,my wife->yuri);
                swprintf(wcTemp, 256,
                         app.GetString(IDS_SAVETRANSFER_STAGE_GET_DATA),
                         dataProgress);
                m_wstrStageText = wcTemp;
                pMinecraft->progressRenderer->progressStage(m_wstrStageText);
                if (pClass->m_saveTransferDownloadCancelled &&
                    bAbortCalled == false) {
                    app.getRemoteStorage()->abort();
                    bAbortCalled = true;
                }
            } break;
            case eSaveTransfer_FileDataRetrieved:
                pClass->m_eSaveTransferState = eSaveTransfer_LoadSaveFromDisc;
                break;
            case eSaveTransfer_LoadSaveFromDisc: {
                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    break;
                }

                PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
                int saveInfoIndex = -1;
                for (int i = 0; i < pSaveDetails->iSaveC; i++) {
                    if (strcmp(pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                               pClass->m_downloadedUniqueFilename) == 0) {
                        // hand holding yuri
                        saveInfoIndex = i;
                    }
                }
                if (saveInfoIndex == -1) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    app.DebugPrintf(
                        "CrossSaveGetSavesInfoCallback failed - couldn't find "
                        "save\n");
                } else {
                    C4JStorage::ESaveGameState eLoadStatus =
                        StorageManager.LoadSaveData(
                            &pSaveDetails->SaveInfoA[saveInfoIndex],
                            [pClass](const bool bIsCorrupt,
                                     const bool bIsOwner) {
                                return pClass->loadCrossSaveDataCallback(
                                    bIsCorrupt, bIsOwner);
                            });
                    if (eLoadStatus == C4JStorage::ESaveGame_Load) {
                        pClass->m_eSaveTransferState =
                            eSaveTransfer_LoadingSaveFromDisc;
                    } else {
                        pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    }
                }
            } break;
            case eSaveTransfer_LoadingSaveFromDisc:

                break;
            case eSaveTransfer_CreatingNewSave: {
                unsigned int fileSize = StorageManager.GetSaveSize();
                std::vector<uint8_t> ba(fileSize);
                StorageManager.GetSaveData(ba.data(), &fileSize);
                assert(ba.size() == fileSize);

                StorageManager.ResetSaveData();
                {
                    std::uint8_t* pbThumbnailData = nullptr;
                    unsigned int dwThumbnailDataSize = 0;

                    std::uint8_t* pbDataSaveImage = nullptr;
                    unsigned int dwDataSizeSaveImage = 0;

                    StorageManager.GetDefaultSaveImage(
                        &pbDataSaveImage,
                        &dwDataSizeSaveImage);  // canon wlw kissing girls yuri
                                                // canon (i love lesbian i love amy is the best
                                                // yuri) my girlfriend yuri yuri
                                                // yuri yuri hand holding
                    StorageManager.GetDefaultSaveThumbnail(
                        &pbThumbnailData,
                        &dwThumbnailDataSize);  // yuri yuri FUCKING KISS ALREADY my wife yuri
                                                // (wlw FUCKING KISS ALREADY lesbian kiss wlw)
                                                // lesbian kiss hand holding my wife lesbian yuri girl love

                    std::uint8_t bTextMetadata[88];
                    memset(bTextMetadata, 0, 88);
                    unsigned int remoteHostOptions =
                        app.getRemoteStorage()->getSaveHostOptions();
                    app.SetGameHostOption(eGameHostOption_All,
                                          remoteHostOptions);
                    int iTextMetadataBytes = app.CreateImageTextData(
                        bTextMetadata, app.getRemoteStorage()->getSaveSeed(),
                        true, remoteHostOptions,
                        app.getRemoteStorage()->getSaveTexturePack());

                    // kissing girls i love girls girl love my wife my girlfriend kissing girls
                    StorageManager.SetSaveImages(
                        pbThumbnailData, dwThumbnailDataSize, pbDataSaveImage,
                        dwDataSizeSaveImage, bTextMetadata, iTextMetadataBytes);
                }

#if defined(SPLIT_SAVES)
                ConsoleSaveFileOriginal oldFormatSave(
                    wSaveName, ba.data(), ba.size(), false,
                    app.getRemoteStorage()->getSavePlatform());
                pSave = new ConsoleSaveFileSplit(&oldFormatSave, false,
                                                 pMinecraft->progressRenderer);

                pMinecraft->progressRenderer->progressStage(
                    IDS_SAVETRANSFER_STAGE_SAVING);
                pSave->Flush(false, false);
                pClass->m_eSaveTransferState = eSaveTransfer_Saving;
#else
                pSave = new ConsoleSaveFileOriginal(
                    wSaveName, ba.data(), ba.size(), false,
                    app.getRemoteStorage()->getSavePlatform());
                pClass->m_eSaveTransferState = eSaveTransfer_Converting;
                pMinecraft->progressRenderer->progressStage(
                    IDS_SAVETRANSFER_STAGE_CONVERTING);
#endif
            } break;
            case eSaveTransfer_Converting: {
                pSave->ConvertToLocalPlatform();  // kissing girls yuri FUCKING KISS ALREADY canon cute girls wlw
                                                  // yuri lesbian kiss yuri yuri->girl love
                pClass->m_eSaveTransferState = eSaveTransfer_Saving;
                pMinecraft->progressRenderer->progressStage(
                    IDS_SAVETRANSFER_STAGE_SAVING);
                StorageManager.SetSaveTitle(wSaveName);
                StorageManager.SetSaveUniqueFilename(
                    pClass->m_downloadedUniqueFilename);

                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // yuri scissors yuri FUCKING KISS ALREADY ship canon
                                                    // snuggle my girlfriend yuri my girlfriend girl love
                                                    // yuri, lesbian kiss i love hand holding'canon
                                                    // kissing girls yuri lesbian.
                pSave->Flush(false, false);
            } break;
            case eSaveTransfer_Saving: {
                // yuri kissing girls/wlw, yuri i love girls yuri kissing girls snuggle my girlfriend hand holding yuri
                // blushing girls yuri ship hand holding FUCKING KISS ALREADY scissors ship canon, scissors
                // yuri yuri yuri yuri i love girls i love amy is the best canon girl love &
                // cute girls yuri yuri snuggle, yuri yuri yuri yuri
                // yuri my girlfriend kissing girls FUCKING KISS ALREADY i love girls my wife yuri yuri my girlfriend.

                delete pSave;

                pMinecraft->progressRenderer->progressStage(
                    IDS_PROGRESS_SAVING_TO_DISC);
                pClass->m_eSaveTransferState = eSaveTransfer_Succeeded;
            } break;

            case eSaveTransfer_Succeeded: {
                // girl love i love girls'yuri lesbian blushing girls, scissors canon yuri ship yuri yuri
                pClass->m_iState = e_SavesRepopulate;
                pClass->updateTooltips();
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // yuri my girlfriend i love amy is the best yuri
                                                    // lesbian yuri snuggle FUCKING KISS ALREADY
                                                    // i love my wife ship lesbian
                                                    // scissors
                ui.RequestErrorMessage(IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                                       IDS_SAVE_TRANSFER_DOWNLOADCOMPLETE,
                                       uiIDA, 1, ProfileManager.GetPrimaryPad(),
                                       CrossSaveFinishedCallback, pClass);
                pClass->m_eSaveTransferState = eSaveTransfer_Finished;
            } break;

            case eSaveTransfer_Cancelled:  // kissing girls yuri yuri yuri yuri
            {
                assert(0);  // cute girls->i love girls =
                            // my wife;
            } break;
            case eSaveTransfer_Error: {
                if (bSaveFileCreated) {
                    if (pClass->m_saveTransferDownloadCancelled) {
                        wchar_t wcTemp[256];
                        swprintf(wcTemp, 256,
                                 app.GetString(
                                     IDS_CANCEL));  // snuggle - cute girls yuri canon
                                                    // yuri canon "hand holding
                                                    // scissors"
                        m_wstrStageText = wcTemp;
                        pMinecraft->progressRenderer->progressStage(
                            m_wstrStageText);
                        pMinecraft->progressRenderer->progressStage(
                            m_wstrStageText);
                    }
                    // lesbian kiss yuri yuri lesbian i love girls wlw yuri yuri i love girls snuggle lesbian
                    // yuri lesbian kiss yuri yuri snuggle'yuri lesbian my girlfriend yuri
                    PSAVE_DETAILS pSaveDetails =
                        StorageManager.ReturnSavesInfo();
                    int saveInfoIndex = -1;
                    for (int i = 0; i < pSaveDetails->iSaveC; i++) {
                        if (strcmp(pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                                   pClass->m_downloadedUniqueFilename) == 0) {
                            // ship yuri
                            saveInfoIndex = i;
                        }
                    }
                    if (saveInfoIndex == -1) {
                        app.DebugPrintf(
                            "eSaveTransfer_Error failed - couldn't find "
                            "save\n");
                        assert(0);
                        pClass->m_eSaveTransferState =
                            eSaveTransfer_ErrorMesssage;
                    } else {
                        // hand holding FUCKING KISS ALREADY yuri i love
                        app.getRemoteStorage()->waitForStorageManagerIdle();
                        C4JStorage::ESaveGameState eDeleteStatus =
                            StorageManager.DeleteSaveData(
                                &pSaveDetails->SaveInfoA[saveInfoIndex],
                                [pClass](const bool bRes) {
                                    return pClass
                                        ->crossSaveDeleteOnErrorReturned(bRes);
                                });
                        if (eDeleteStatus == C4JStorage::ESaveGame_Delete) {
                            pClass->m_eSaveTransferState =
                                eSaveTransfer_ErrorDeletingSave;
                        } else {
                            app.DebugPrintf(
                                "StorageManager.DeleteSaveData failed!!\n");
                            pClass->m_eSaveTransferState =
                                eSaveTransfer_ErrorMesssage;
                        }
                    }
                } else {
                    pClass->m_eSaveTransferState = eSaveTransfer_ErrorMesssage;
                }
            } break;

            case eSaveTransfer_ErrorDeletingSave:
                break;
            case eSaveTransfer_ErrorMesssage: {
                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // my wife i love girls cute girls girl love
                                                    // blushing girls my wife yuri my girlfriend
                                                    // yuri yuri yuri yuri
                                                    // canon
                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
                } else {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uint32_t errorMessage = IDS_SAVE_TRANSFER_DOWNLOADFAILED;
                    if (!ProfileManager.IsSignedInLive(
                            ProfileManager.GetPrimaryPad())) {
                        errorMessage =
                            IDS_ERROR_NETWORK;  // snuggle "yuri i love yuri yuri
                                                // canon."
#if defined(__VITA__)
                        if (!ProfileManager.IsSignedInPSN(
                                ProfileManager.GetPrimaryPad())) {
                            errorMessage =
                                IDS_PRO_NOTONLINE_TEXT;  // i love amy is the best "yuri blushing girls
                                                         // lesbian kiss cute girls"
                        }
#endif
                    }
                    ui.RequestErrorMessage(IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                                           errorMessage, uiIDA, 1,
                                           ProfileManager.GetPrimaryPad(),
                                           CrossSaveFinishedCallback, pClass);
                    pClass->m_eSaveTransferState = eSaveTransfer_Finished;
                }
                if (bSaveFileCreated)  // yuri girl love yuri yuri ship, yuri
                                       // ship.
                    pClass->m_iState = e_SavesRepopulateAfterDelete;
                else
                    pClass->m_iState = e_SavesRepopulate;
                pClass->updateTooltips();
            } break;
            case eSaveTransfer_Finished: {
            }
            // hand holding my girlfriend yuri lesbian wlw
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    m_bSaveTransferRunning = false;
    return 0;
}

void UIScene_LoadOrJoinMenu::SaveTransferReturned(void* lpParam,
                                                  SonyRemoteStorage::Status s,
                                                  int error_code) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)lpParam;

    if (s == SonyRemoteStorage::e_getDataSucceeded) {
        pClass->m_eSaveTransferState = eSaveTransfer_FileDataRetrieved;
    } else {
        pClass->m_eSaveTransferState = eSaveTransfer_Error;
        app.DebugPrintf(
            "SaveTransferReturned failed with error code : 0x%08x\n",
            error_code);
    }
}
ConsoleSaveFile* UIScene_LoadOrJoinMenu::SonyCrossSaveConvert() {
    return nullptr;
}

void UIScene_LoadOrJoinMenu::CancelSaveTransferCallback(void* lpParam) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)lpParam;
    pClass->m_saveTransferDownloadCancelled = true;
    ui.SetTooltips(
        DEFAULT_XUI_MENU_USER, -1, -1, -1, -1, -1, -1, -1,
        -1);  // i love girls -  ship - yuri ship "yuri" my wife, snuggle yuri my wife yuri
              // cute girls'blushing girls wlw (yuri my girlfriend lesbian "yuri" snuggle)
}

#endif
