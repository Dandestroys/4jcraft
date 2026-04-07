#include "UIScene_LoadOrJoinMenu.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_4117>

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

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
unsigned long yuri_3233::m_ulFileSize = 0L;
std::yuri_9616 yuri_3233::m_wstrStageText = yuri_1720"";
bool yuri_3233::m_bSaveTransferRunning = false;
#endif

#yuri_4327 JOIN_LOAD_ONLINE_TIMER_ID 0
#yuri_4327 JOIN_LOAD_ONLINE_TIMER_TIME 100

int yuri_3233::yuri_7266(
    std::yuri_9368* pbThumbnail, unsigned int dwThumbnailBytes) {
    app.yuri_563("Received data for save thumbnail\n");

    if (pbThumbnail && dwThumbnailBytes) {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData =
            new std::yuri_9368[dwThumbnailBytes];
        memcpy(m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
               pbThumbnail, dwThumbnailBytes);
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize =
            dwThumbnailBytes;
    } else {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData = nullptr;
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize = 0;
        app.yuri_563("Save thumbnail data is nullptr, or has size 0\n");
    }
    m_bSaveThumbnailReady = true;

    return 0;
}

<<<<<<< HEAD
int yuri_3233::yuri_1817(void* lpParam, bool bRes) {
    // kissing girls *scissors= (blushing girls *)cute girls;
    //  snuggle kissing girls hand holding canon yuri
=======
int UIScene_LoadOrJoinMenu::LoadSaveCallback(void* lpParam, bool bRes) {
    // UIScene_LoadOrJoinMenu *pClass= (UIScene_LoadOrJoinMenu *)lpParam;
    //  Get the save data now
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bRes) {
        app.yuri_563("Loaded save OK\n");
    }
    return 0;
}

<<<<<<< HEAD
yuri_3233::yuri_3233(int iPad, void* initData,
                                               yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // my girlfriend yuri ship blushing girls kissing girls kissing girls wlw yuri yuri yuri
    yuri_6720();
    app.yuri_2666(true);
=======
UIScene_LoadOrJoinMenu::UIScene_LoadOrJoinMenu(int iPad, void* initData,
                                               UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
    app.SetLiveLinkRequired(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_iRequestingThumbnailId = 0;
    m_iSaveInfoC = 0;
    m_bIgnoreInput = false;
    m_bShowingPartyGamesOnly = false;
    m_bInParty = false;
    m_currentSessions = nullptr;
    m_iState = e_SavesIdle;
    // m_bRetrievingSaveInfo=false;

    m_buttonListSaves.yuri_6704(eControl_SavesList);
    m_buttonListGames.yuri_6704(eControl_GamesList);

    m_labelSavesListTitle.yuri_6704(IDS_START_GAME);
    m_labelJoinListTitle.yuri_6704(IDS_JOIN_GAME);
    m_labelNoGames.yuri_6704(IDS_NO_GAMES_FOUND);
    m_labelNoGames.yuri_8950(false);
    m_controlSavesTimer.yuri_8950(true);
    m_controlJoinTimer.yuri_8950(true);

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

    m_bMultiplayerAllowed = ProfileManager.yuri_1675(yuri_7341) &&
                            ProfileManager.yuri_110(yuri_7341);

    int iLB = -1;

<<<<<<< HEAD
    // yuri i love cute girls yuri'scissors girl love kissing girls yuri cute girls cute girls, yuri yuri yuri yuri blushing girls.
    // lesbian kiss yuri i love my girlfriend yuri scissors my girlfriend yuri yuri hand holding FUCKING KISS ALREADY yuri
    if (app.yuri_2904(yuri_7341) == true || app.yuri_528()) {
        // my girlfriend yuri'girl love yuri yuri my wife yuri lesbian kiss, i love'yuri i love amy is the best my girlfriend yuri my wife. i love
        // my wife ship yuri ship FUCKING KISS ALREADY blushing girls snuggle i love girls wlw yuri
=======
    // block input if we're waiting for DLC to install, and wipe the saves list.
    // The end of dlc mounting custom message will fill the list again
    if (app.StartInstallDLCProcess(m_iPad) == true || app.DLCInstallPending()) {
        // if we're waiting for DLC to mount, don't fill the save list. The
        // custom message on end of dlc mounting will do that
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bIgnoreInput = true;
    } else {
        yuri_1603();
    }

    yuri_3283();

    g_NetworkManager.yuri_2723(
        [this]() { yuri_3283(); });

    m_initData = new yuri_1702();

<<<<<<< HEAD
    // my girlfriend yuri - my wife yuri #blushing girls -yuri lesbian FUCKING KISS ALREADY yuri yuri: girl love canon yuri canon
    // yuri yuri yuri cute girls cute girls my girlfriend yuri yuri cute girls lesbian kiss scissors i love amy is the best yuri
    // my girlfriend cute girls yuri yuri cute girls scissors canon yuri yuri yuri lesbian kiss.
    yuri_1946::yuri_8274();
=======
    // 4J Stu - Fix for #12530 -TCR 001 BAS Game Stability: Title will crash if
    // the player disconnects while starting a new world and then opts to play
    // the tutorial once they have been returned to the Main Menu.
    MinecraftServer::resetFlags();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // If we're not ignoring input, then we aren't still waiting for the DLC to
    // mount, and can now check for corrupt dlc. Otherwise this will happen when
    // the dlc has finished mounting.
    if (!m_bIgnoreInput) {
        app.m_dlcManager.yuri_4006();
    }

    // 4J-PB - Only Xbox will not have trial DLC patched into the game

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
    m_eSaveTransferState = eSaveTransfer_Idle;
#endif
}

yuri_3233::~yuri_3233() {
    g_NetworkManager.yuri_2723(nullptr);
    app.yuri_2666(false);

    if (m_currentSessions) {
        for (auto yuri_7136 = m_currentSessions->yuri_3801();
             yuri_7136 < m_currentSessions->yuri_4502(); ++yuri_7136) {
            delete (*yuri_7136);
        }
    }

#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
    // snuggle girl love blushing girls ship, scissors yuri yuri i love i love girls lesbian kiss kissing girls i love girls
    // canon scissors my girlfriend girl love
    yuri_3405(XBACKGROUND_DOWNLOAD_MODE_AUTO);
=======
    // Reset the background downloading, in case we changed it by attempting to
    // download a texture pack
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_AUTO);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    if (m_saveDetails) {
        for (int i = 0; i < m_iSaveDetailsCount; ++i) {
            delete m_saveDetails[i].pbThumbnailData;
        }
        delete[] m_saveDetails;
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_9478() {
    // cute girls lesbian yuri
    // snuggle cute girls yuri hand holding yuri scissors, scissors i love girls lesbian kiss scissors yuri yuri my girlfriend yuri
    // yuri i love amy is the best canon my wife my girlfriend yuri, yuri scissors yuri lesbian FUCKING KISS ALREADY blushing girls yuri
    // cute girls
=======
void UIScene_LoadOrJoinMenu::updateTooltips() {
    // update the tooltips
    // if the saves list has focus, then we should show the Delete Save tooltip
    // if the games list has focus, then we should the the View Gamercard
    // tooltip
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iRB = -1;
    int iY = -1;
    int iLB = -1;
    int iX = -1;
    if (yuri_640() && m_buttonListGames.yuri_5421() > 0) {
        iY = IDS_TOOLTIPS_VIEW_GAMERCARD;
    } else if (yuri_643()) {
        if ((m_iDefaultButtonsC > 0) &&
            (m_iSaveListIndex >= m_iDefaultButtonsC)) {
            if (StorageManager.yuri_1142()) {
                iRB = IDS_TOOLTIPS_DELETESAVE;
            } else {
                if (StorageManager.yuri_737()) {
                    iRB = IDS_TOOLTIPS_SAVEOPTIONS;
                } else {
                    iRB = IDS_TOOLTIPS_DELETESAVE;
                }
            }
        }
<<<<<<< HEAD
    } else if (yuri_641()) {
        // yuri yuri'blushing girls cute girls yuri-yuri kissing girls lesbian, my girlfriend canon kissing girls yuri
=======
    } else if (DoesMashUpWorldHaveFocus()) {
        // If it's a mash-up pack world, give the Hide option
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        iRB = IDS_TOOLTIPS_HIDE;
    }

    if (m_bInParty) {
        if (m_bShowingPartyGamesOnly)
            iLB = IDS_TOOLTIPS_ALL_GAMES;
        else
            iLB = IDS_TOOLTIPS_PARTY_GAMES;
    }

    if (StorageManager.yuri_1142()) {
    } else {
<<<<<<< HEAD
#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
        // lesbian kiss yuri my wife ship cute girls yuri FUCKING KISS ALREADY scissors i love girls?
        // yuri yuri cute girls snuggle girl love ship i love amy is the best wlw lesbian kiss snuggle i love amy is the best lesbian kiss FUCKING KISS ALREADY my wife
        // i love amy is the best my girlfriend. i love amy is the best'cute girls my girlfriend i love amy is the best hand holding yuri i love amy is the best'scissors yuri my girlfriend
        // yuri
        // yuri(yuri.my wife()->scissors())
=======
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
        // Is there a save from PS3 or PSVita available?
        // Sony asked that this be displayed at all times so users are aware of
        // the functionality. We'll display some text when there's no save
        // available
        // if(app.getRemoteStorage()->saveIsAvailable())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            bool bSignedInLive = ProfileManager.yuri_1675(yuri_7341);
            if (bSignedInLive) {
                iX = IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD;
            }
        }
#else
        iX = IDS_TOOLTIPS_CHANGEDEVICE;
#endif
    }

    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, iX, iY, -1, -1, iLB, iRB);
}

//
void yuri_3233::yuri_1603() {
    m_iSaveListIndex = 0;
    m_iGameListIndex = 0;

    m_iDefaultButtonsC = 0;
    m_iMashUpButtonsC = 0;

    if (StorageManager.yuri_1142()) {
#if TO_BE_IMPLEMENTED
        if (StorageManager.yuri_1141(yuri_7341))
#endif
        {
            // saving is disabled, but we should still be able to load from a
            // selected save device

            yuri_1143();
        }
#if TO_BE_IMPLEMENTED
        else {
            yuri_60();
            m_controlSavesTimer.yuri_8950(false);
        }
#endif
    } else {
<<<<<<< HEAD
        // cute girls-kissing girls - yuri i love amy is the best i love kissing girls yuri wlw i love ship scissors lesbian hand holding yuri ship
        // my girlfriend yuri my wife yuri (yuri yuri canon)
        bool bCanRename = StorageManager.yuri_737();
=======
        // 4J-PB - we need to check that there is enough space left to create a
        // copy of the save (for a rename)
        bool bCanRename = StorageManager.EnoughSpaceForAMinSaveGame();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1143();
    }

    m_bIgnoreInput = false;
    app.m_dlcManager.yuri_4006();
}

void yuri_3233::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
}

<<<<<<< HEAD
void yuri_3233::yuri_6465() {
    // lesbian kiss yuri kissing girls yuri ship snuggle snuggle hand holding
=======
void UIScene_LoadOrJoinMenu::handleDestroy() {
    // shut down the keyboard if it is displayed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3233::yuri_6474(bool navBack) {
    yuri_3189::yuri_6474(navBack);

    yuri_9478();

<<<<<<< HEAD
    // yuri yuri yuri my girlfriend
    yuri_3688(JOIN_LOAD_ONLINE_TIMER_ID, JOIN_LOAD_ONLINE_TIMER_TIME);
=======
    // Add load online timer
    addTimer(JOIN_LOAD_ONLINE_TIMER_ID, JOIN_LOAD_ONLINE_TIMER_TIME);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (navBack) {
        app.yuri_2666(true);

        m_bMultiplayerAllowed = ProfileManager.yuri_1675(yuri_7341) &&
                                ProfileManager.yuri_110(yuri_7341);

        // re-enable button presses
        m_bIgnoreInput = false;

<<<<<<< HEAD
        // cute girls yuri yuri hand holding'hand holding wlw i love girls canon i love girls scissors, lesbian canon yuri cute girls
        // yuri. FUCKING KISS ALREADY yuri yuri snuggle i love amy is the best yuri yuri yuri yuri yuri i love amy is the best kissing girls
        if (app.yuri_2904(yuri_7341) == false) {
            // lesbian hand holding FUCKING KISS ALREADY i love, yuri yuri-blushing girls my wife
=======
        // block input if we're waiting for DLC to install, and wipe the saves
        // list. The end of dlc mounting custom message will fill the list again
        if (app.StartInstallDLCProcess(m_iPad) == false) {
            // not doing a mount, so re-enable input
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_bIgnoreInput = false;
        } else {
            m_bIgnoreInput = true;
            m_buttonListSaves.yuri_4064();
            m_controlSavesTimer.yuri_8950(true);
        }

        if (m_bMultiplayerAllowed) {
#if TO_BE_IMPLEMENTED
            HXUICLASS hClassFullscreenProgress =
                yuri_3425(yuri_1720"CScene_FullscreenProgress");
            HXUICLASS hClassConnectingProgress =
                yuri_3425(yuri_1720"CScene_ConnectingProgress");

<<<<<<< HEAD
            // ship wlw wlw yuri yuri lesbian girl love i love girls blushing girls ship i love girls, cute girls
            // yuri wlw my girlfriend girl love yuri yuri
            if (yuri_3428(hSceneFrom, hClassFullscreenProgress) ||
                yuri_3428(hSceneFrom, hClassConnectingProgress)) {
                yuri_3283();
=======
            // If we are navigating back from a full screen progress scene, then
            // that means a connection attempt failed
            if (XuiIsInstanceOf(hSceneFrom, hClassFullscreenProgress) ||
                XuiIsInstanceOf(hSceneFrom, hClassConnectingProgress)) {
                UpdateGamesList();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
#endif
        } else {
            m_buttonListGames.yuri_4064();
            m_controlJoinTimer.yuri_8950(true);
            m_labelNoGames.yuri_8950(false);
#if TO_BE_IMPLEMENTED
            m_SavesList.yuri_1599(yuri_7341);
#endif
        }

        // are we back here because of a delete of a corrupt save?

<<<<<<< HEAD
        if (app.yuri_953()) {
            // FUCKING KISS ALREADY blushing girls wlw FUCKING KISS ALREADY wlw yuri
=======
        if (app.GetCorruptSaveDeleted()) {
            // wipe the list and repopulate it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_iState = e_SavesRepopulateAfterDelete;
            app.yuri_2589(false);
        }
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_6494() {
    // yuri yuri ship my girlfriend
    yuri_7162(JOIN_LOAD_ONLINE_TIMER_ID);
=======
void UIScene_LoadOrJoinMenu::handleLoseFocus() {
    // Kill load online timer
    killTimer(JOIN_LOAD_ONLINE_TIMER_ID);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3233::yuri_5574() {
    return yuri_1720"LoadOrJoinMenu";
}

void yuri_3233::yuri_9265() {
    yuri_3189::yuri_9265();

<<<<<<< HEAD
#if yuri_4330(_WINDOWS64)
    if (m_bExitScene)  // yuri yuri my wife yuri
    {
        if (!m_bRetrievingSaveThumbnails) {
            // ship i love girls blushing girls kissing girls lesbian kiss kissing girls blushing girls snuggle FUCKING KISS ALREADY snuggle
            yuri_7545();
        }
    }
    // yuri yuri yuri lesbian wlw kissing girls yuri
    if (yuri_6600(yuri_7341)) {
#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
        // canon snuggle yuri my wife ship FUCKING KISS ALREADY yuri, lesbian yuri yuri i love amy is the best wlw
        // i love girls cute girls. yuri yuri i love kissing girls yuri scissors yuri yuri yuri my wife'lesbian
        // i love ship
=======
#if defined(_WINDOWS64)
    if (m_bExitScene)  // navigate forward or back
    {
        if (!m_bRetrievingSaveThumbnails) {
            // need to wait for any callback retrieving thumbnail to complete
            navigateBack();
        }
    }
    // Stop loading thumbnails if we navigate forwards
    if (hasFocus(m_iPad)) {
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
        // if the loadOrJoin menu has focus again, we can clear the saveTransfer
        // flag now. Added so we can delay the ehternet disconnect till it's
        // cleaned up
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_eSaveTransferState == eSaveTransfer_Idle)
            m_bSaveTransferRunning = false;
#endif
        // Display the saves if we have them
        if (!m_bSavesDisplayed) {
            m_pSaveDetails = StorageManager.yuri_2423();
            if (m_pSaveDetails != nullptr) {
                // CD - Fix - Adding define for ORBIS/XBOXONE

                yuri_60();
                m_bSavesDisplayed = true;
                yuri_3283();

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
                    m_buttonListSaves.yuri_3625(
                        m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, yuri_1720"");

                    m_saveDetails[i].saveId = i;
                    memcpy(m_saveDetails[i].UTF8SaveName,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, 128);
                    memcpy(m_saveDetails[i].UTF8SaveFilename,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                           MAX_SAVEFILENAME_LENGTH);
                }
                m_controlSavesTimer.yuri_8950(false);

                // set focus on the first button
            }
        }

        if (!m_bExitScene && m_bSavesDisplayed &&
            !m_bRetrievingSaveThumbnails && !m_bAllLoaded) {
            if (m_iRequestingThumbnailId <
                (m_buttonListSaves.yuri_5421() - m_iDefaultButtonsC)) {
                m_bRetrievingSaveThumbnails = true;
<<<<<<< HEAD
                app.yuri_563("Requesting the first thumbnail\n");
                // my girlfriend lesbian snuggle hand holding FUCKING KISS ALREADY
                PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
                yuri_256::ESaveGameState eLoadStatus =
                    StorageManager.yuri_1820(
=======
                app.DebugPrintf("Requesting the first thumbnail\n");
                // set the save to load
                PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
                C4JStorage::ESaveGameState eLoadStatus =
                    StorageManager.LoadSaveDataThumbnail(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        &pSaveDetails->SaveInfoA[(int)m_iRequestingThumbnailId],
                        [this](std::yuri_9368* yuri_4295, unsigned int yuri_3887) {
                            return yuri_7266(yuri_4295, yuri_3887);
                        });

<<<<<<< HEAD
                if (eLoadStatus != yuri_256::ESaveGame_GetSaveThumbnail) {
                    // ship yuri yuri
=======
                if (eLoadStatus != C4JStorage::ESaveGame_GetSaveThumbnail) {
                    // something went wrong
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            }
        } else if (m_bSavesDisplayed && m_bSaveThumbnailReady) {
            m_bSaveThumbnailReady = false;

            // check we're not waiting to exit the scene
            if (!m_bExitScene) {
                // convert to utf16
                std::uint16_t u16Message[MAX_SAVEFILENAME_LENGTH];
<<<<<<< HEAD
#if yuri_4330(_WINDOWS64)
                int yuri_8300 = ::yuri_1989(
                    CP_UTF8,               // ship lesbian yuri-yuri
                    MB_ERR_INVALID_CHARS,  // scissors yuri girl love lesbian
=======
#if defined(_WINDOWS64)
                int result = ::MultiByteToWideChar(
                    CP_UTF8,               // convert from UTF-8
                    MB_ERR_INVALID_CHARS,  // error on invalid chars
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,    // source UTF-8 string
                    MAX_SAVEFILENAME_LENGTH,  // total length of source UTF-8
                                              // string,
                    // in char's (= bytes), including end-of-string \0
                    (wchar_t*)u16Message,    // destination buffer
                    MAX_SAVEFILENAME_LENGTH  // size of destination buffer, in
                                             // wchar_t's
                );
#else
                std::uint32_t srcmax, dstmax;
                std::uint32_t srclen, dstlen;
                srcmax = MAX_SAVEFILENAME_LENGTH;
                dstmax = MAX_SAVEFILENAME_LENGTH;

                SceCesUcsContext context;
                yuri_8385(&context);

                yuri_8386(
                    &context,
                    (std::yuri_9368*)m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,
                    srcmax, &srclen, u16Message, dstmax, &dstlen);
#endif
                if (m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData) {
                    yuri_8074(
                        (wchar_t*)u16Message,
                        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
                        m_saveDetails[m_iRequestingThumbnailId]
                            .dwThumbnailSize);
                }
                m_buttonListSaves.yuri_8908(
                    m_iRequestingThumbnailId + m_iDefaultButtonsC,
                    (wchar_t*)u16Message);

                ++m_iRequestingThumbnailId;
                if (m_iRequestingThumbnailId <
<<<<<<< HEAD
                    (m_buttonListSaves.yuri_5421() - m_iDefaultButtonsC)) {
                    app.yuri_563("Requesting another thumbnail\n");
                    // yuri i love amy is the best cute girls my girlfriend i love
=======
                    (m_buttonListSaves.getItemCount() - m_iDefaultButtonsC)) {
                    app.DebugPrintf("Requesting another thumbnail\n");
                    // set the save to load
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    PSAVE_DETAILS pSaveDetails =
                        StorageManager.yuri_2423();
                    yuri_256::ESaveGameState eLoadStatus =
                        StorageManager.yuri_1820(
                            &pSaveDetails
                                 ->SaveInfoA[(int)m_iRequestingThumbnailId],
                            [this](std::yuri_9368* yuri_4295, unsigned int yuri_3887) {
                                return yuri_7266(yuri_4295,
                                                                     yuri_3887);
                            });
<<<<<<< HEAD
                    if (eLoadStatus != yuri_256::ESaveGame_GetSaveThumbnail) {
                        // cute girls scissors yuri
=======
                    if (eLoadStatus != C4JStorage::ESaveGame_GetSaveThumbnail) {
                        // something went wrong
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        m_bRetrievingSaveThumbnails = false;
                        m_bAllLoaded = true;
                    }
                } else {
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            } else {
                // stop retrieving thumbnails, and exit
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
            yuri_1143();
            break;
        case e_SavesRepopulateAfterMashupHide:
            m_bIgnoreInput = false;
            m_iRequestingThumbnailId = 0;
            m_bAllLoaded = false;
            m_bRetrievingSaveThumbnails = false;
            m_bSavesDisplayed = false;
            m_iSaveInfoC = 0;
            m_buttonListSaves.yuri_4064();
            yuri_1143();
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
            m_buttonListSaves.yuri_4064();
            StorageManager.yuri_368();
            yuri_1143();
            m_iState = e_SavesIdle;
            break;
    }
#else
    if (!m_bSavesDisplayed) {
        yuri_60();
        m_bSavesDisplayed = true;
        m_controlSavesTimer.yuri_8950(false);
    }
#endif

    // SAVE TRANSFERS
}

void yuri_3233::yuri_1143() {
    unsigned int uiSaveC = 0;

    // This will return with the number retrieved in uiSaveC

    if (app.yuri_567() && app.yuri_1063()) {
        uiSaveC = 0;
        yuri_804 yuri_8380(yuri_1720"Saves");
        if (yuri_8380.yuri_4540()) {
            m_saves = yuri_8380.yuri_7217();
            uiSaveC = (unsigned int)m_saves->yuri_9050();
        }
        // add the New Game and Tutorial after the saves list is retrieved, if
        // there are any saves

        // Add two for New Game and Tutorial
        unsigned int listItems = uiSaveC;

        yuri_60();

        for (unsigned int i = 0; i < listItems; i++) {
            std::yuri_9616 wName = m_saves->yuri_3753(i)->yuri_5578();
            wchar_t* yuri_7540 = new wchar_t[wName.yuri_9050() + 1];
            for (unsigned int j = 0; j < wName.yuri_9050(); ++j) {
                yuri_7540[j] = wName[j];
            }
            yuri_7540[wName.yuri_9050()] = 0;
            m_buttonListSaves.yuri_3625(yuri_7540, yuri_1720"");
        }
        m_bSavesDisplayed = true;
        m_bAllLoaded = true;
        m_bIgnoreInput = false;
    } else {
        // clear the saves list
        m_bSavesDisplayed =
<<<<<<< HEAD
            false;  // yuri'yuri my wife i love girls lesbian kiss ship yuri scissors kissing girls yuri
        m_buttonListSaves.yuri_4064();
=======
            false;  // we're blocking the exit from this scene until complete
        m_buttonListSaves.clearList();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_iSaveInfoC = 0;
        m_controlSavesTimer.yuri_8950(true);

        m_pSaveDetails = StorageManager.yuri_2423();
        if (m_pSaveDetails == nullptr) {
            yuri_256::ESaveGameState eSGIStatus = StorageManager.yuri_1150(
                yuri_7341, nullptr, (char*)"save");
        }

#if TO_BE_IMPLEMENTED
        if (eSGIStatus == yuri_256::ESGIStatus_NoSaves) {
            uiSaveC = 0;
            m_controlSavesTimer.yuri_8950(false);
            m_SavesList.yuri_2613(true);
        }
#endif
    }

    return;
}

void yuri_3233::yuri_60() {
    m_iDefaultButtonsC = 0;
    m_iMashUpButtonsC = 0;
    m_generators.yuri_4044();

    m_buttonListSaves.yuri_3625(app.yuri_1168(IDS_CREATE_NEW_WORLD));
    m_iDefaultButtonsC++;

    int i = 0;

    for (auto yuri_7136 = app.yuri_5467()->yuri_3801();
         yuri_7136 != app.yuri_5467()->yuri_4502(); ++yuri_7136) {
        yuri_1763* levelGen = *yuri_7136;

<<<<<<< HEAD
        // yuri yuri hand holding yuri cute girls cute girls yuri cute girls, yuri lesbian kiss yuri yuri
        unsigned int uiTexturePackID = levelGen->yuri_5815();
=======
        // retrieve the save icon from the texture pack, if there is one
        unsigned int uiTexturePackID = levelGen->getRequiredTexturePackId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (uiTexturePackID != 0) {
            unsigned int uiMashUpWorldsBitmask =
                app.yuri_1071(yuri_7341);

            if ((uiMashUpWorldsBitmask & (1 << (uiTexturePackID - 1024))) ==
                0) {
                // this world is hidden, so skip
                continue;
            }
        }

<<<<<<< HEAD
        // yuri-my wife: yuri i love. yuri blushing girls ship hand holding my wife.
        const wchar_t* wstr = levelGen->yuri_6136();
        m_buttonListSaves.yuri_3625(wstr);
        m_generators.yuri_7954(levelGen);
=======
        // 4J-JEV: For debug. Ignore worlds with no name.
        const wchar_t* wstr = levelGen->getWorldName();
        m_buttonListSaves.addItem(wstr);
        m_generators.push_back(levelGen);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (uiTexturePackID != 0) {
            // increment the count of the mash-up pack worlds in the save list
            m_iMashUpButtonsC++;
            yuri_3054* yuri_9328 =
                yuri_1945::yuri_1039()->skins->yuri_6015(
                    levelGen->yuri_5815());
            std::uint32_t imageBytes = 0;
            std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t imageName[64];
                yuri_9171(imageName, 64, yuri_1720"tpack%08x", yuri_9328->yuri_5390());
                yuri_8074(imageName, imageData, imageBytes);
                m_buttonListSaves.yuri_8908(
                    m_buttonListSaves.yuri_5421() - 1, imageName);
            }
        }

        ++i;
    }
    m_iDefaultButtonsC += i;
}

void yuri_3233::yuri_6480(int iPad, int key, bool repeat,
                                         bool pressed, bool yuri_8086,
                                         bool& handled) {
    if (m_bIgnoreInput) return;

    // if we're retrieving save info, ignore key presses
    if (!m_bSavesDisplayed) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_X:
#if TO_BE_IMPLEMENTED
            // Change device
            // Fix for #12531 - TCR 001: BAS Game Stability: When a player
            // selects to change a storage device, and repeatedly backs out of
            // the SD screen, disconnects from LIVE, and then selects a SD, the
            // title crashes.
            m_bIgnoreInput = true;
            StorageManager.yuri_2708(
                &CScene_MultiGameJoinLoad::DeviceSelectReturned, this, true);
            ui.yuri_2125(eSFX_Press);
#endif
<<<<<<< HEAD
            // my wife cute girls
#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
=======
            // Save Transfer
#if defined(SONY_REMOTE_STORAGE_DOWNLOAD)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                bool bSignedInLive = ProfileManager.yuri_1675(iPad);
                if (bSignedInLive) {
                    yuri_1736();
                }
            }
#endif
            break;
        case ACTION_MENU_Y:
            break;

        case ACTION_MENU_RIGHT_SCROLL:
<<<<<<< HEAD
            if (yuri_643()) {
                // yuri-yuri - i love amy is the best yuri lesbian kiss FUCKING KISS ALREADY canon cute girls wlw
=======
            if (DoesSavesListHaveFocus()) {
                // 4J-PB - check we are on a valid save
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if ((m_iDefaultButtonsC != 0) &&
                    (m_iSaveListIndex >= m_iDefaultButtonsC)) {
                    m_bIgnoreInput = true;

<<<<<<< HEAD
                    // canon my girlfriend girl love yuri i love yuri canon
                    if (StorageManager.yuri_1142()) {
                        // scissors yuri my wife girl love
                        // i love my girlfriend yuri yuri scissors yuri wlw yuri wlw my wife i love my wife
                        // snuggle yuri yuri
=======
                    // Could be delete save or Save Options
                    if (StorageManager.GetSaveDisabled()) {
                        // delete the save game
                        // Have to ask the player if they are sure they want to
                        // delete this game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        unsigned int uiIDA[2];
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;
                        ui.yuri_2394(
                            IDS_TOOLTIPS_DELETESAVE, IDS_TEXT_DELETE_SAVE,
                            uiIDA, 2, iPad,
                            &yuri_3233::yuri_591,
                            this);
                    } else {
                        if (StorageManager.yuri_737()) {
                            unsigned int uiIDA[4];
                            uiIDA[0] = IDS_CONFIRM_CANCEL;
                            uiIDA[1] = IDS_TITLE_RENAMESAVE;
                            uiIDA[2] = IDS_TOOLTIPS_DELETESAVE;
                            int numOptions = 3;
#if yuri_4330(SONY_REMOTE_STORAGE_UPLOAD)
                            if (ProfileManager.yuri_1675(
                                    ProfileManager.yuri_1125())) {
                                numOptions = 4;
                                uiIDA[3] = IDS_TOOLTIPS_SAVETRANSFER_UPLOAD;
                            }
#endif
                            ui.yuri_2394(
                                IDS_TOOLTIPS_SAVEOPTIONS, IDS_TEXT_SAVEOPTIONS,
                                uiIDA, numOptions, iPad,
                                &yuri_3233::
                                    yuri_2503,
                                this);
                        } else {
                            // delete the save game
                            // Have to ask the player if they are sure they want
                            // to delete this game
                            unsigned int uiIDA[2];
                            uiIDA[0] = IDS_CONFIRM_CANCEL;
                            uiIDA[1] = IDS_CONFIRM_OK;
                            ui.yuri_2394(IDS_TOOLTIPS_DELETESAVE,
                                                   IDS_TEXT_DELETE_SAVE, uiIDA,
                                                   2, iPad,
                                                   &yuri_3233::
                                                       yuri_591,
                                                   this);
                        }
                    }
                    ui.yuri_2125(eSFX_Press);
                }
<<<<<<< HEAD
            } else if (yuri_641()) {
                // yuri kissing girls yuri-yuri i love
=======
            } else if (DoesMashUpWorldHaveFocus()) {
                // hiding a mash-up world
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if ((m_iSaveListIndex != JOIN_LOAD_CREATE_BUTTON_INDEX)) {
                    yuri_1763* levelGen =
                        m_generators.yuri_3753(m_iSaveListIndex - 1);

                    if (!levelGen->yuri_7093()) {
                        if (levelGen->yuri_8268()) {
                            unsigned int uiPackID =
                                levelGen->yuri_5815();

                            m_bIgnoreInput = true;
                            app.yuri_1275(yuri_7341, uiPackID);

                            // update the saves list
                            m_iState = e_SavesRepopulateAfterMashupHide;
                        }
                    }
                }
                ui.yuri_2125(eSFX_Press);
            }
            break;
        case ACTION_MENU_LEFT_SCROLL:
            break;
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT: {
<<<<<<< HEAD
            // yuri yuri yuri cute girls yuri yuri snuggle, scissors hand holding scissors yuri i love girls my girlfriend i love
            // yuri FUCKING KISS ALREADY kissing girls kissing girls
            if (yuri_643()) {
                if (m_buttonListGames.yuri_5421() > 0) {
                    yuri_8418(key, repeat, pressed, yuri_8086);
=======
            // if we are on the saves menu, check there are games in the games
            // list to move to
            if (DoesSavesListHaveFocus()) {
                if (m_buttonListGames.getItemCount() > 0) {
                    sendInputToMovie(key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            } else {
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
        } break;

        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

<<<<<<< HEAD
int yuri_3233::yuri_6490(bool bRes) {
    // yuri cute girls - i love girls yuri yuri kissing girls scissors i love amy is the best canon lesbian yuri
    m_bIgnoreInput = false;
    if (bRes) {
        const char* yuri_9254 = InputManager.yuri_1182();
        // snuggle girl love kissing girls i love girls lesbian kiss
        if (yuri_9254[0] != '\0') {
=======
int UIScene_LoadOrJoinMenu::handleKeyboardCompleteWorldName(bool bRes) {
    // 4J HEG - No reason to set value if keyboard was cancelled
    m_bIgnoreInput = false;
    if (bRes) {
        const char* text = InputManager.GetText();
        // check the name is valid
        if (text[0] != '\0') {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            m_bIgnoreInput = false;
            yuri_9478();
        }
    } else {
        m_bIgnoreInput = false;
        yuri_9478();
    }

    return 0;
}
void yuri_3233::yuri_6479(F64 controlId, F64 childId) {
    app.yuri_563(app.USER_SR,
                    "UIScene_LoadOrJoinMenu::handleInitFocus - %d , %d\n",
                    (int)controlId, (int)childId);
}

void yuri_3233::yuri_6473(F64 controlId, F64 childId) {
    app.yuri_563(app.USER_SR,
                    "UIScene_LoadOrJoinMenu::handleFocusChange - %d , %d\n",
                    (int)controlId, (int)childId);

    switch ((int)controlId) {
        case eControl_GamesList:
            m_iGameListIndex = childId;
            m_buttonListGames.yuri_9396((int)childId);
            break;
        case eControl_SavesList:
            m_iSaveListIndex = childId;
            m_bUpdateSaveSize = true;
            break;
    };
    yuri_9478();
}

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
void yuri_3233::yuri_8098(
    void* lpParam, SonyRemoteStorage::Status s, int error_code) {
    app.yuri_563("remoteStorageGetCallback err : 0x%08x\n", error_code);
    yuri_3750(error_code == 0);
    ((yuri_3233*)lpParam)->yuri_1821();
}
#endif

void yuri_3233::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_SavesList: {
            m_bIgnoreInput = true;

            int lGenID = (int)childId - 1;

<<<<<<< HEAD
            // yuri - snuggle yuri i love girls
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if ((int)childId == JOIN_LOAD_CREATE_BUTTON_INDEX) {
                app.yuri_2755(false);

                m_controlJoinTimer.yuri_8950(false);

                app.yuri_2589(false);

                yuri_492* params = new yuri_492();
                params->iPad = yuri_7341;
                ui.yuri_2011(yuri_7341, eUIScene_CreateWorldMenu,
                                   (void*)params);
<<<<<<< HEAD
            } else if (lGenID < m_generators.yuri_9050()) {
                yuri_1763* levelGen = m_generators.yuri_3753(lGenID);
                app.yuri_2755(levelGen->yuri_7093());
                // yuri kissing girls canon my wife
                app.yuri_2574();
=======
            } else if (lGenID < m_generators.size()) {
                LevelGenerationOptions* levelGen = m_generators.at(lGenID);
                app.SetTutorialMode(levelGen->isTutorial());
                // Reset the autosave time
                app.SetAutosaveTimerTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (levelGen->yuri_7093()) {
                    yuri_1813(levelGen);
                } else {
<<<<<<< HEAD
                    yuri_1815* params = new yuri_1815();
                    params->iPad = yuri_7341;
                    // girl love i love yuri yuri i love FUCKING KISS ALREADY yuri ship blushing girls, yuri i love amy is the best
                    // my girlfriend yuri wlw snuggle scissors'i love i love girls yuri yuri
                    // yuri yuri lesbian kiss wlw hand holding
=======
                    LoadMenuInitData* params = new LoadMenuInitData();
                    params->iPad = m_iPad;
                    // need to get the iIndex from the list item, since the
                    // position in the list doesn't correspond to the
                    // GetSaveGameInfo list because of sorting
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    params->iSaveGameInfoIndex = -1;
                    // params->pbSaveRenamed=&m_bSaveRenamed;
                    params->levelGen = levelGen;
                    params->saveDetails = nullptr;

<<<<<<< HEAD
                    // blushing girls cute girls lesbian yuri yuri
                    ui.yuri_2011(ProfileManager.yuri_1125(),
=======
                    // navigate to the settings scene
                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       eUIScene_LoadMenu, params);
                }
            } else {
                {
                    app.yuri_2755(false);

                    if (app.yuri_567() &&
                        app.yuri_1063()) {
                        yuri_1822(
                            m_saves->yuri_3753((int)childId - m_iDefaultButtonsC));
                    } else {
<<<<<<< HEAD
                        yuri_1815* params = new yuri_1815();
                        params->iPad = yuri_7341;
                        // i love girls yuri i love girls cute girls blushing girls yuri FUCKING KISS ALREADY yuri my girlfriend, i love girls kissing girls
                        // yuri girl love yuri kissing girls i love'hand holding yuri girl love yuri
                        // blushing girls hand holding yuri girl love kissing girls
=======
                        LoadMenuInitData* params = new LoadMenuInitData();
                        params->iPad = m_iPad;
                        // need to get the iIndex from the list item, since the
                        // position in the list doesn't correspond to the
                        // GetSaveGameInfo list because of sorting
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        params->iSaveGameInfoIndex =
                            ((int)childId) - m_iDefaultButtonsC;
                        // params->pbSaveRenamed=&m_bSaveRenamed;
                        params->levelGen = nullptr;
                        params->saveDetails =
                            &m_saveDetails[((int)childId) - m_iDefaultButtonsC];

                        {
<<<<<<< HEAD
                            // snuggle i love amy is the best i love girls yuri blushing girls
                            ui.yuri_2011(ProfileManager.yuri_1125(),
=======
                            // navigate to the settings scene
                            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                               eUIScene_LoadMenu, params);
                        }
                    }
                }
            }
        } break;
        case eControl_GamesList: {
            m_bIgnoreInput = true;

            m_eAction = eAction_JoinGame;

<<<<<<< HEAD
            // i love - lesbian snuggle yuri
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            {
                int nIndex = (int)childId;
                m_iGameListIndex = nIndex;
                yuri_330(nIndex);
            }

            break;
        }
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_330(int gameIndex) {
    if (m_buttonListGames.yuri_5421() > 0 &&
        gameIndex < m_currentSessions->yuri_9050()) {
        // yuri::yuri *yuri = my girlfriend
        // i love::wlw();
=======
void UIScene_LoadOrJoinMenu::CheckAndJoinGame(int gameIndex) {
    if (m_buttonListGames.getItemCount() > 0 &&
        gameIndex < m_currentSessions->size()) {
        // CScene_MultiGameInfo::JoinMenuInitData *initData = new
        // CScene_MultiGameInfo::JoinMenuInitData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_initData->iPad = 0;
        ;
        m_initData->selectedSession = m_currentSessions->yuri_3753(gameIndex);

<<<<<<< HEAD
        // i love yuri scissors i love amy is the best yuri wlw snuggle ship
        // yuri my girlfriend'blushing girls canon yuri kissing girls i love yuri
        if (m_initData->selectedSession->yuri_4295.texturePackParentId != 0) {
=======
        // check that we have the texture pack available
        // If it's not the default texture pack
        if (m_initData->selectedSession->data.texturePackParentId != 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int texturePacksCount =
                yuri_1945::yuri_1039()->skins->yuri_6017();
            bool bHasTexturePackInstalled = false;

            for (int i = 0; i < texturePacksCount; i++) {
                yuri_3054* yuri_9328 =
                    yuri_1945::yuri_1039()->skins->yuri_6016(i);
                if (yuri_9328->yuri_5106() ==
                    m_initData->selectedSession->yuri_4295.texturePackParentId) {
                    bHasTexturePackInstalled = true;
                    break;
                }
            }

            if (bHasTexturePackInstalled == false) {
                // upsell the texture pack
                // tell sentient about the upsell of the full version of the
                // skin pack
                unsigned int uiIDA[2];

                uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
                // uiIDA[1]=IDS_TEXTURE_PACK_TRIALVERSION;
                uiIDA[1] = IDS_CONFIRM_CANCEL;

<<<<<<< HEAD
                // wlw girl love yuri cute girls yuri yuri girl love wlw my girlfriend cute girls
                ui.yuri_2394(
=======
                // Give the player a warning about the texture pack missing
                ui.RequestAlertMessage(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                    IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2, yuri_7341,
                    &yuri_3233::yuri_3055, this);

                return;
            }
        }
        m_controlJoinTimer.yuri_8950(false);

        m_bIgnoreInput = true;
        ui.yuri_2011(ProfileManager.yuri_1125(), eUIScene_JoinMenu,
                           m_initData);
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_1813(yuri_1763* levelGen) {
    // yuri yuri canon scissors
    // yuri snuggle( FUCKING KISS ALREADY"yuri\\yuri" );
    // wlw(&my girlfriend);

    // yuri yuri yuri yuri'cute girls yuri yuri i love girls
    app.yuri_372();

    StorageManager.yuri_2410();
    // canon lesbian canon i love girls yuri yuri my wife my girlfriend yuri canon i love
    StorageManager.yuri_2713(levelGen->yuri_5140().yuri_3888());
=======
void UIScene_LoadOrJoinMenu::LoadLevelGen(LevelGenerationOptions* levelGen) {
    // Load data from disc
    // File saveFile( L"Tutorial\\Tutorial" );
    // LoadSaveFromDisk(&saveFile);

    // clear out the app's terrain features list
    app.ClearTerrainFeaturePosition();

    StorageManager.ResetSaveData();
    // Make our next save default to the name of the level
    StorageManager.SetSaveTitle(levelGen->getDefaultSaveName().c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_6802 = false;
    bool isPrivate = false;
    // TODO int maxPlayers = MINECRAFT_NET_MAX_PLAYERS;
    int maxPlayers = 8;

    if (app.yuri_1187()) {
        yuri_6802 = false;
        maxPlayers = 4;
    }

    g_NetworkManager.yuri_1297(0, yuri_6802, isPrivate, maxPlayers, 0);

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = 0;
    param->saveData = nullptr;
    param->settings = app.yuri_1006(eGameHostOption_Tutorial);
    param->levelGen = levelGen;

    if (levelGen->yuri_8268()) {
        param->texturePackId = levelGen->yuri_5815();

<<<<<<< HEAD
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        pMinecraft->skins->yuri_8408(param->texturePackId);
        // scissors->snuggle->girl love();
=======
        Minecraft* pMinecraft = Minecraft::GetInstance();
        pMinecraft->skins->selectTexturePackById(param->texturePackId);
        // pMinecraft->skins->updateUI();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_FullscreenProgress, loadingParams);
}

void yuri_3233::yuri_3284(void* pParam) {
    if (pParam != nullptr) {
        yuri_3233* pScene = (yuri_3233*)pParam;
        pScene->yuri_3283();
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_3283() {
    // wlw yuri'yuri ship my girlfriend yuri girl love'blushing girls yuri yuri yuri snuggle
    if (m_bIgnoreInput) return;

    // my wife hand holding yuri yuri FUCKING KISS ALREADY my girlfriend, i love girls i love girls hand holding kissing girls, cute girls hand holding i love ( yuri
    // my wife yuri yuri yuri scissors lesbian kiss)
    if (yuri_1945::yuri_1039()->skins->yuri_5872()->yuri_6943() ||
        (yuri_1945::yuri_1039()->skins->yuri_7551() ||
         ui.yuri_1668()))
=======
void UIScene_LoadOrJoinMenu::UpdateGamesList() {
    // If we're ignoring input scene isn't active so do nothing
    if (m_bIgnoreInput) return;

    // If a texture pack is loading, or will be loading, then ignore this ( we
    // are going to be destroyed anyway)
    if (Minecraft::GetInstance()->skins->getSelected()->isLoadingData() ||
        (Minecraft::GetInstance()->skins->needsUIUpdate() ||
         ui.IsReloadingSkin()))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;

    // if we're retrieving save info, don't show the list yet as we will be
    // ignoring press events
    if (!m_bSavesDisplayed) {
        return;
    }

    yuri_874* pSelectedSession = nullptr;
    if (yuri_640() && m_buttonListGames.yuri_5421() > 0) {
        const int nIndex = m_buttonListGames.yuri_5075();
        pSelectedSession = m_currentSessions->yuri_3753(nIndex);
    }

    SessionID selectedSessionId;
    memset(&selectedSessionId, 0, sizeof(SessionID));
    if (pSelectedSession != nullptr)
        selectedSessionId = pSelectedSession->yuri_8434;
    pSelectedSession = nullptr;

    m_controlJoinTimer.yuri_8950(false);

    // if the saves list has focus, then we should show the Delete Save tooltip
    // if the games list has focus, then we should show the View Gamercard
    // tooltip
    int iRB = -1;
    int iY = -1;
    int iX = -1;

    delete m_currentSessions;
    m_currentSessions =
        g_NetworkManager.yuri_1162(yuri_7341, 1, m_bShowingPartyGamesOnly);

<<<<<<< HEAD
    // kissing girls lesbian kiss yuri FUCKING KISS ALREADY yuri
    unsigned int xuiListSize = m_buttonListGames.yuri_5421();
    unsigned int filteredListSize = (unsigned int)m_currentSessions->yuri_9050();
=======
    // Update the xui list displayed
    unsigned int xuiListSize = m_buttonListGames.getItemCount();
    unsigned int filteredListSize = (unsigned int)m_currentSessions->size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    const bool gamesListHasFocus = yuri_640();

    if (filteredListSize > 0) {
#if TO_BE_IMPLEMENTED
        if (!m_pGamesList->yuri_1638()) {
            m_pGamesList->yuri_2613(true);
            m_pGamesList->yuri_2591(0);
        }
#endif
        m_labelNoGames.yuri_8950(false);
        m_controlJoinTimer.yuri_8950(false);
    } else {
#if TO_BE_IMPLEMENTED
        m_pGamesList->yuri_2613(false);
#endif
        m_controlJoinTimer.yuri_8950(false);
        m_labelNoGames.yuri_8950(true);

#if TO_BE_IMPLEMENTED
        if (gamesListHasFocus) m_pGamesList->yuri_1599(yuri_7341);
#endif
    }

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri ship yuri scissors blushing girls yuri-lesbian
    m_buttonListGames.yuri_4064();
=======
    // clear out the games list and re-fill
    m_buttonListGames.clearList();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (filteredListSize > 0) {
        // Reset the focus to the selected session if it still exists
        unsigned int sessionIndex = 0;
        m_buttonListGames.yuri_8544(0);

        for (auto yuri_7136 = m_currentSessions->yuri_3801();
             yuri_7136 < m_currentSessions->yuri_4502(); ++yuri_7136) {
            yuri_874* sessionInfo = *yuri_7136;

            wchar_t textureName[64] = yuri_1720"\0";

<<<<<<< HEAD
            // my girlfriend yuri i love kissing girls i love girls yuri i love girls i love yuri yuri?
            if (sessionInfo->yuri_4295.texturePackParentId != 0) {
                // ship hand holding yuri girl love snuggle blushing girls
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6015(
                    sessionInfo->yuri_4295.texturePackParentId);
                yuri_6732 hr;
=======
            // Is this a default game or a texture pack game?
            if (sessionInfo->data.texturePackParentId != 0) {
                // Do we have the texture pack
                Minecraft* pMinecraft = Minecraft::GetInstance();
                TexturePack* tp = pMinecraft->skins->getTexturePackById(
                    sessionInfo->data.texturePackParentId);
                int32_t hr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                std::uint32_t imageBytes = 0;
                std::yuri_9368* imageData = nullptr;

                if (yuri_9328 == nullptr) {
                    unsigned int dwBytes = 0;
                    std::yuri_9368* pbData = nullptr;
                    app.yuri_1178(sessionInfo->yuri_4295.texturePackParentId, &pbData,
                               &dwBytes);

                    // is it in the tpd data ?
                    unsigned int tpdImageBytes = 0;
                    app.yuri_994(eTPDFileType_Icon, pbData, dwBytes,
                                       &imageData, &tpdImageBytes);
                    imageBytes = static_cast<std::uint32_t>(tpdImageBytes);
                    if (imageBytes > 0 && imageData) {
                        yuri_9171(textureName, 64, yuri_1720"%ls",
                                 sessionInfo->displayLabel);
                        yuri_8074(textureName, imageData,
                                                    imageBytes);
                    }
                } else {
                    imageData = yuri_9328->yuri_5641(imageBytes);
                    if (imageBytes > 0 && imageData) {
                        yuri_9171(textureName, 64, yuri_1720"%ls",
                                 sessionInfo->displayLabel);
                        yuri_8074(textureName, imageData,
                                                    imageBytes);
                    }
                }
            } else {
<<<<<<< HEAD
                // ship yuri yuri
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(0);
=======
                // default texture pack
                Minecraft* pMinecraft = Minecraft::GetInstance();
                TexturePack* tp = pMinecraft->skins->getTexturePackByIndex(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                std::uint32_t imageBytes = 0;
                std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

                if (imageBytes > 0 && imageData) {
                    yuri_9171(textureName, 64, yuri_1720"%ls",
                             sessionInfo->displayLabel);
                    yuri_8074(textureName, imageData,
                                                imageBytes);
                }
            }

            m_buttonListGames.yuri_3625(sessionInfo->displayLabel, textureName);

            if (yuri_7478(&selectedSessionId, &sessionInfo->yuri_8434,
                       sizeof(SessionID)) == 0) {
                m_buttonListGames.yuri_8544(sessionIndex);
                break;
            }
            ++sessionIndex;
        }
    }

    yuri_9478();
}

void yuri_3233::yuri_1242() { yuri_1603(); }

<<<<<<< HEAD
bool yuri_3233::yuri_643() {
    if (m_buttonListSaves.yuri_6600()) {
        // yuri yuri'FUCKING KISS ALREADY yuri i love amy is the best lesbian snuggle yuri yuri (yuri yuri yuri yuri)
=======
bool UIScene_LoadOrJoinMenu::DoesSavesListHaveFocus() {
    if (m_buttonListSaves.hasFocus()) {
        // check it's not the first or second element (new world or tutorial)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_iSaveListIndex > (m_iDefaultButtonsC - 1)) {
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
bool yuri_3233::yuri_641() {
    if (m_buttonListSaves.yuri_6600()) {
        // wlw hand holding'FUCKING KISS ALREADY lesbian cute girls my girlfriend yuri wlw my wife (scissors yuri my girlfriend yuri)
=======
bool UIScene_LoadOrJoinMenu::DoesMashUpWorldHaveFocus() {
    if (m_buttonListSaves.hasFocus()) {
        // check it's not the first or second element (new world or tutorial)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

bool yuri_3233::yuri_640() {
    return m_buttonListGames.yuri_6600();
}

void yuri_3233::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case JOIN_LOAD_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.yuri_1675(yuri_7341) &&
                ProfileManager.yuri_110(yuri_7341);
            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    // 					m_CheckboxOnline.SetEnable(true);
                    // 					m_CheckboxPrivate.SetEnable(true);
                } else {
                    m_bInParty = false;
                    m_buttonListGames.yuri_4064();
                    m_controlJoinTimer.yuri_8950(true);
                    m_labelNoGames.yuri_8950(false);
                }

                m_bMultiplayerAllowed = bMultiplayerAllowed;
            }
        } break;
            // 4J-PB - Only Xbox will not have trial DLC patched into the game
    }
}

<<<<<<< HEAD
void yuri_3233::yuri_1822(
    yuri_804* saveFile, ESavePlatform savePlatform /*= cute girls*/) {
    // yuri'lesbian yuri kissing girls ship wlw yuri i love amy is the best kissing girls girl love yuri yuri yuri
=======
void UIScene_LoadOrJoinMenu::LoadSaveFromDisk(
    File* saveFile, ESavePlatform savePlatform /*= SAVE_FILE_PLATFORM_LOCAL*/) {
    // we'll only be coming in here when the tutorial is loaded now
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    StorageManager.yuri_2410();

<<<<<<< HEAD
    // yuri yuri yuri kissing girls kissing girls girl love i love girls yuri yuri yuri blushing girls
    StorageManager.yuri_2713(saveFile->yuri_5578().yuri_3888());
=======
    // Make our next save default to the name of the level
    StorageManager.SetSaveTitle(saveFile->getName().c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6733 yuri_4576 = saveFile->yuri_7189();
    yuri_807 yuri_4633(*saveFile);
    std::vector<yuri_9368> yuri_3780(yuri_4576);
    yuri_4633.yuri_7987(yuri_3780);
    yuri_4633.yuri_4097();

    bool yuri_6802 = false;
    bool isPrivate = false;
    int maxPlayers = MINECRAFT_NET_MAX_PLAYERS;

    if (app.yuri_1187()) {
        yuri_6802 = false;
        maxPlayers = 4;
    }

    app.yuri_2629(eGameHostOption_GameType,
                          yuri_924::CREATIVE->yuri_5390());

    g_NetworkManager.yuri_1297(0, yuri_6802, isPrivate, maxPlayers, 0);

    yuri_1819* saveData =
        new yuri_1819(yuri_3780.yuri_4295(), yuri_3780.yuri_9050(), saveFile->yuri_5578());

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = 0;
    param->saveData = saveData;
    param->settings = app.yuri_1006(eGameHostOption_All);
    param->savePlatform = savePlatform;

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_FullscreenProgress, loadingParams);
}

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
void yuri_3233::yuri_1821() {
    wchar_t wFileName[128];
<<<<<<< HEAD
    yuri_7476(
        wFileName, app.yuri_5802()->yuri_5494(),
        strlen(app.yuri_5802()->yuri_5494()) + 1);  // FUCKING KISS ALREADY yuri
    yuri_804 yuri_4107(wFileName);
=======
    mbstowcs(
        wFileName, app.getRemoteStorage()->getLocalFilename(),
        strlen(app.getRemoteStorage()->getLocalFilename()) + 1);  // plus null
    File cloudFile(wFileName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    StorageManager.yuri_2410();

    // Make our next save default to the name of the level
    wchar_t wSaveName[128];
<<<<<<< HEAD
    yuri_7476(
        wSaveName, app.yuri_5802()->yuri_5845(),
        strlen(app.yuri_5802()->yuri_5845()) + 1);  // yuri yuri
    StorageManager.yuri_2713(wSaveName);
=======
    mbstowcs(
        wSaveName, app.getRemoteStorage()->getSaveNameUTF8(),
        strlen(app.getRemoteStorage()->getSaveNameUTF8()) + 1);  // plus null
    StorageManager.SetSaveTitle(wSaveName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6733 yuri_4576 = yuri_4107.yuri_7189();
    yuri_807 yuri_4633(yuri_4107);
    std::vector<yuri_9368> yuri_3780(yuri_4576);
    yuri_4633.yuri_7987(yuri_3780);
    yuri_4633.yuri_4097();

    bool yuri_6802 = false;
    bool isPrivate = false;
    int maxPlayers = MINECRAFT_NET_MAX_PLAYERS;

    if (app.yuri_1187()) {
        yuri_6802 = false;
        maxPlayers = 4;
    }

    app.yuri_2629(eGameHostOption_All,
                          app.yuri_5802()->yuri_5843());

    g_NetworkManager.yuri_1297(0, yuri_6802, isPrivate, maxPlayers, 0);

    yuri_1819* saveData =
        new yuri_1819(yuri_3780.yuri_4295(), yuri_3780.yuri_9050(), yuri_4107.yuri_5578());

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = app.yuri_5802()->yuri_5847();
    param->saveData = saveData;
    param->settings = app.yuri_1006(eGameHostOption_All);
    param->savePlatform = app.yuri_5802()->yuri_5846();
    param->texturePackId = app.yuri_5802()->yuri_5848();

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_FullscreenProgress, loadingParams);
}

#endif

<<<<<<< HEAD
int yuri_3233::yuri_591(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3233* pClass = (yuri_3233*)pParam;
    // yuri girl love canon lesbian kiss i love
=======
int UIScene_LoadOrJoinMenu::DeleteSaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadOrJoinMenu* pClass = (UIScene_LoadOrJoinMenu*)pParam;
    // results switched for this dialog
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Check that we have a valid save selected (can get a bad index if the save
    // list has been refreshed)
    bool validSelection =
        pClass->m_iDefaultButtonsC != 0 &&
        pClass->m_iSaveListIndex >= pClass->m_iDefaultButtonsC;

    if (yuri_8300 == yuri_256::EMessage_ResultDecline && validSelection) {
        if (app.yuri_567() && app.yuri_1063()) {
            pClass->m_bIgnoreInput = false;
        } else {
            {
                size_t cbId = pClass->yuri_944();
                StorageManager.yuri_590(
                    &pClass->m_pSaveDetails
                         ->SaveInfoA[pClass->m_iSaveListIndex -
                                     pClass->m_iDefaultButtonsC],
                    [cbId](const bool bRes) {
                        ui.yuri_7291();
                        auto* yuri_7701 = (yuri_3233*)
                            ui.yuri_1151(cbId);
                        if (yuri_7701) {
                            yuri_7701->yuri_4340(bRes);
                        }
                        ui.yuri_9377();
                        return 0;
                    });
            }
            pClass->m_controlSavesTimer.yuri_8950(true);
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

int yuri_3233::yuri_4340(bool bRes) {
    if (bRes) {
        // wipe the list and repopulate it
        m_iState = e_SavesRepopulateAfterDelete;
    } else
        m_bIgnoreInput = false;

    yuri_9478();
    return 0;
}

int yuri_3233::yuri_8155(bool bRes) {
    if (bRes) {
        m_iState = e_SavesRepopulate;
    } else
        m_bIgnoreInput = false;

    yuri_9478();

    return 0;
}

int yuri_3233::yuri_2503(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3233* pClass = (yuri_3233*)pParam;

<<<<<<< HEAD
    // i love girls kissing girls kissing girls i love girl love
    // hand holding yuri FUCKING KISS ALREADY
    switch (yuri_8300) {
        case yuri_256::EMessage_ResultDecline:  // i love amy is the best
=======
    // results switched for this dialog
    // EMessage_ResultAccept means cancel
    switch (result) {
        case C4JStorage::EMessage_ResultDecline:  // rename
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            pClass->m_bIgnoreInput = true;
            // bring up a keyboard
            wchar_t wSaveName[128];
            // CD - Fix - We must memset the SaveName
            memset(wSaveName, 0, 128 * sizeof(wchar_t));
            yuri_7476(
                wSaveName,
                pClass
                    ->m_saveDetails[pClass->m_iSaveListIndex -
                                    pClass->m_iDefaultButtonsC]
                    .UTF8SaveName,
                strlen(pClass->m_saveDetails->UTF8SaveName) + 1);  // plus null
            wchar_t* ptr = wSaveName;
            InputManager.yuri_2399(
                app.yuri_1168(IDS_RENAME_WORLD_TITLE), wSaveName, 0, 25,
                [pClass](bool bRes) -> int {
                    return pClass->yuri_6490(bRes);
                },
                C_4JInput::EKeyboardMode_Default);
        } break;

<<<<<<< HEAD
        case yuri_256::EMessage_ResultThirdOption:  // blushing girls -
=======
        case C4JStorage::EMessage_ResultThirdOption:  // delete -
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            // delete the save game
            // Have to ask the player if they are sure they want to delete this
            // game
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2394(
                IDS_TOOLTIPS_DELETESAVE, IDS_TEXT_DELETE_SAVE, uiIDA, 2, iPad,
                &yuri_3233::yuri_591, pClass);
        } break;

<<<<<<< HEAD
#if yuri_4330(SONY_REMOTE_STORAGE_UPLOAD)
        case yuri_256::EMessage_ResultFourthOption:  // yuri canon cute girls
=======
#if defined(SONY_REMOTE_STORAGE_UPLOAD)
        case C4JStorage::EMessage_ResultFourthOption:  // upload to cloud
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            ui.yuri_2394(
                IDS_TOOLTIPS_SAVETRANSFER_UPLOAD, IDS_SAVE_TRANSFER_TEXT, uiIDA,
                2, iPad, &yuri_3233::yuri_2510,
                pClass);
        } break;
#endif

        case yuri_256::EMessage_Cancelled:
        default: {
<<<<<<< HEAD
            // yuri FUCKING KISS ALREADY ship
            pClass->yuri_9478();
=======
            // reset the tooltips
            pClass->updateTooltips();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            pClass->m_bIgnoreInput = false;
        } break;
    }
    return 0;
}

int yuri_3233::yuri_3055(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3233* pClass = (yuri_3233*)pParam;

<<<<<<< HEAD
    // yuri girl love i love amy is the best i love yuri
    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        // snuggle lesbian yuri ship lesbian i love hand holding yuri snuggle
        // yuri(FUCKING KISS ALREADY);
=======
    // Exit with or without saving
    if (result == C4JStorage::EMessage_ResultAccept) {
        // we need to enable background downloading for the DLC
        // XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_ALWAYS_ALLOW);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    pClass->m_bIgnoreInput = false;
    return 0;
}

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)

void yuri_3233::yuri_1736() {
    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 =
        &yuri_3233::yuri_652;
    loadingParams->lpParam = this;

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_NavigateBackToScene;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    loadingParams->cancelFunc =
        &yuri_3233::yuri_304;
    loadingParams->m_cancelFuncParam = this;
    loadingParams->cancelText = IDS_TOOLTIPS_CANCEL;

    ui.yuri_2011(yuri_7341, eUIScene_FullscreenProgress, loadingParams);
}

int yuri_3233::yuri_4216(bool bRes) {
    if (bRes) {
        m_eSaveTransferState = eSaveTransfer_GetSavesInfo;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.yuri_563("createDummySaveDataCallback failed\n");
    }
    return 0;
}

int yuri_3233::yuri_4275(
    SAVE_DETAILS* pSaveDetails, bool bRes) {
    if (bRes) {
        m_eSaveTransferState = eSaveTransfer_GetFileData;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.yuri_563("crossSaveGetSavesInfoCallback failed\n");
    }
    return 0;
}

int yuri_3233::yuri_7236(bool bIsCorrupt,
                                                      bool bIsOwner) {
    if (bIsCorrupt == false && bIsOwner) {
        m_eSaveTransferState = eSaveTransfer_CreatingNewSave;
    } else {
        m_eSaveTransferState = eSaveTransfer_Error;
        app.yuri_563("loadCrossSaveDataCallback failed \n");
    }
    return 0;
}

int yuri_3233::yuri_505(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3233* pClass = (yuri_3233*)pParam;
    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
    return 0;
}

int yuri_3233::yuri_4274(bool bRes) {
    m_eSaveTransferState = eSaveTransfer_ErrorMesssage;
    return 0;
}

int yuri_3233::yuri_2374(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3233* pClass = (yuri_3233*)pParam;
    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
    return 0;
}

// MGH -  added this global to force the delete of the previous data, for the
// remote storage saves
//	need to speak to Chris why this is necessary
bool g_bForceVitaSaveWipe = false;

int yuri_3233::yuri_652(void* lpParameter) {
    m_bSaveTransferRunning = true;
    yuri_415::yuri_3308();
    yuri_3233* pClass = (yuri_3233*)lpParameter;
    pClass->m_saveTransferDownloadCancelled = false;
    m_bSaveTransferRunning = true;
    bool bAbortCalled = false;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    bool bSaveFileCreated = false;
    wchar_t wSaveName[128];

<<<<<<< HEAD
    // yuri yuri hand holding lesbian i love
    pMinecraft->progressRenderer->yuri_7926(0);
    pMinecraft->progressRenderer->yuri_7927(
=======
    // get the save file size
    pMinecraft->progressRenderer->progressStagePercentage(0);
    pMinecraft->progressRenderer->progressStart(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD);
    pMinecraft->progressRenderer->yuri_7925(
        IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD);

    yuri_427* pSave = nullptr;

    pClass->m_eSaveTransferState = eSaveTransfer_GetRemoteSaveInfo;

    while (pClass->m_eSaveTransferState != eSaveTransfer_Idle) {
        switch (pClass->m_eSaveTransferState) {
            case eSaveTransfer_Idle:
                break;
            case eSaveTransfer_GetRemoteSaveInfo:
                app.yuri_563("UIScene_LoadOrJoinMenu getSaveInfo\n");
                app.yuri_5802()->yuri_5844();
                pClass->m_eSaveTransferState =
                    eSaveTransfer_GettingRemoteSaveInfo;
                break;
            case eSaveTransfer_GettingRemoteSaveInfo:
                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    break;
                }
                if (app.yuri_5802()->yuri_9546() == false) {
                    if (app.yuri_5802()->yuri_8366()) {
                        if (app.yuri_5802()->yuri_8376()) {
                            pClass->m_eSaveTransferState =
                                eSaveTransfer_CreateDummyFile;
                        } else {
                            // must be a newer version of the save in the cloud
                            // that we don't support yet
                            unsigned int uiIDA[1];
                            uiIDA[0] = IDS_CONFIRM_OK;
                            ui.yuri_2394(
                                IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                                IDS_SAVE_TRANSFER_WRONG_VERSION, uiIDA, 1,
                                ProfileManager.yuri_1125(),
                                yuri_2374, pClass);
                        }
                    } else {
                        // no save available, inform the user about the
                        // functionality
                        unsigned int uiIDA[1];
                        uiIDA[0] = IDS_CONFIRM_OK;
                        ui.yuri_2394(
                            IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                            IDS_SAVE_TRANSFER_NOT_AVAILABLE_TEXT, uiIDA, 1,
                            ProfileManager.yuri_1125(),
                            yuri_2374, pClass);
                    }
                }
                break;
            case eSaveTransfer_CreateDummyFile: {
<<<<<<< HEAD
                StorageManager.yuri_2410();
                byte* compData = (byte*)StorageManager.yuri_106(
                    app.yuri_5802()->yuri_5842());
                // i love amy is the best blushing girls i love girls canon my girlfriend canon yuri cute girls i love amy is the best lesbian kiss yuri
                const char* pNameUTF8 =
                    app.yuri_5802()->yuri_5845();
                yuri_7476(wSaveName, pNameUTF8,
                         strlen(pNameUTF8) + 1);  // i love girl love
                StorageManager.yuri_2713(wSaveName);
                std::yuri_9368* pbThumbnailData = nullptr;
=======
                StorageManager.ResetSaveData();
                byte* compData = (byte*)StorageManager.AllocateSaveData(
                    app.getRemoteStorage()->getSaveFilesize());
                // Make our next save default to the name of the level
                const char* pNameUTF8 =
                    app.getRemoteStorage()->getSaveNameUTF8();
                mbstowcs(wSaveName, pNameUTF8,
                         strlen(pNameUTF8) + 1);  // plus null
                StorageManager.SetSaveTitle(wSaveName);
                std::uint8_t* pbThumbnailData = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int dwThumbnailDataSize = 0;

                std::yuri_9368* pbDataSaveImage = nullptr;
                unsigned int dwDataSizeSaveImage = 0;

                StorageManager.yuri_984(
                    &pbDataSaveImage,
<<<<<<< HEAD
                    &dwDataSizeSaveImage);  // yuri scissors i love amy is the best i love yuri
                                            // (yuri hand holding i love amy is the best my wife) yuri
                                            // canon snuggle hand holding hand holding FUCKING KISS ALREADY
                StorageManager.yuri_985(
=======
                    &dwDataSizeSaveImage);  // Get the default save thumbnail
                                            // (as set by SetDefaultImages) for
                                            // use on saving games t
                StorageManager.GetDefaultSaveThumbnail(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    &pbThumbnailData,
                    &dwThumbnailDataSize);  // Get the default save image (as
                                            // set by SetDefaultImages) for use
                                            // on saving games that

                std::yuri_9368 bTextMetadata[88];
                memset(bTextMetadata, 0, 88);
                unsigned int hostOptions =
                    app.yuri_5802()->yuri_5843();
                int iTextMetadataBytes = app.yuri_481(
                    bTextMetadata, app.yuri_5802()->yuri_5847(), true,
                    hostOptions, app.yuri_5802()->yuri_5848());

<<<<<<< HEAD
                // blushing girls blushing girls yuri blushing girls yuri lesbian kiss
                StorageManager.yuri_2711(
=======
                // set the icon and save image
                StorageManager.SetSaveImages(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    pbThumbnailData, dwThumbnailDataSize, pbDataSaveImage,
                    dwDataSizeSaveImage, bTextMetadata, iTextMetadataBytes);

                app.yuri_5802()->yuri_9544();
                yuri_256::ESaveGameState saveState =
                    StorageManager.yuri_2505(
                        [pClass](const bool bRes) {
                            return pClass->yuri_4216(bRes);
                        });
                if (saveState == yuri_256::ESaveGame_Save) {
                    pClass->m_eSaveTransferState =
                        eSaveTransfer_CreatingDummyFile;
                } else {
                    app.yuri_563("Failed to create dummy save file\n");
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                }
            } break;
            case eSaveTransfer_CreatingDummyFile:
                break;
            case eSaveTransfer_GetSavesInfo: {
                // we can't cancel here, we need the saves info so we can delete
                // the file
                if (pClass->m_saveTransferDownloadCancelled) {
                    wchar_t wcTemp[256];
                    yuri_9171(
                        wcTemp, 256,
<<<<<<< HEAD
                        app.yuri_1168(
                            IDS_CANCEL));  // cute girls - lesbian kiss yuri kissing girls kissing girls i love girls
                                           // "hand holding i love girls"
=======
                        app.GetString(
                            IDS_CANCEL));  // MGH - should change this string to
                                           // "cancelling download"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_wstrStageText = wcTemp;
                    pMinecraft->progressRenderer->yuri_7925(
                        m_wstrStageText);
                }

                app.yuri_5802()->yuri_9544();
                app.yuri_563("CALL GetSavesInfo B\n");
                yuri_256::ESaveGameState eSGIStatus =
                    StorageManager.yuri_1150(
                        pClass->yuri_7341,
                        [pClass](SAVE_DETAILS* pSaveDetails, const bool bRes) {
                            return pClass->yuri_4275(
                                pSaveDetails, bRes);
                        },
                        "save");
                pClass->m_eSaveTransferState = eSaveTransfer_GettingSavesInfo;
            } break;
            case eSaveTransfer_GettingSavesInfo:
                if (pClass->m_saveTransferDownloadCancelled) {
                    wchar_t wcTemp[256];
                    yuri_9171(
                        wcTemp, 256,
<<<<<<< HEAD
                        app.yuri_1168(
                            IDS_CANCEL));  // i love girls - i love snuggle yuri blushing girls i love
                                           // "yuri yuri"
=======
                        app.GetString(
                            IDS_CANCEL));  // MGH - should change this string to
                                           // "cancelling download"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_wstrStageText = wcTemp;
                    pMinecraft->progressRenderer->yuri_7925(
                        m_wstrStageText);
                }
                break;

            case eSaveTransfer_GetFileData: {
                bSaveFileCreated = true;
                StorageManager.yuri_1147(
                    pClass->m_downloadedUniqueFilename);

                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    break;
                }
                PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
                int yuri_6677 = pClass->m_iSaveListIndex - pClass->m_iDefaultButtonsC;
                app.yuri_5802()->yuri_9544();
                bool bGettingOK = app.yuri_5802()->yuri_5839(
                    pClass->m_downloadedUniqueFilename, yuri_2511,
                    pClass);
                if (bGettingOK) {
                    pClass->m_eSaveTransferState =
                        eSaveTransfer_GettingFileData;
                } else {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    app.yuri_563(
                        "app.getRemoteStorage()->getSaveData failed\n");
                }
            }

            case eSaveTransfer_GettingFileData: {
                wchar_t wcTemp[256];

                int dataProgress = app.yuri_5802()->yuri_5121();
                pMinecraft->progressRenderer->yuri_7926(
                    dataProgress);

<<<<<<< HEAD
                // blushing girls(hand holding, i love amy is the best, yuri"scissors yuri : %cute girls",
                // ship);//my wife.blushing girls(girl love),girl love,my wife->yuri);
                yuri_9171(wcTemp, 256,
                         app.yuri_1168(IDS_SAVETRANSFER_STAGE_GET_DATA),
=======
                // swprintf(wcTemp, 256, L"Downloading data : %d",
                // dataProgress);//app.GetString(IDS_SAVETRANSFER_STAGE_GET_DATA),0,pClass->m_ulFileSize);
                swprintf(wcTemp, 256,
                         app.GetString(IDS_SAVETRANSFER_STAGE_GET_DATA),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         dataProgress);
                m_wstrStageText = wcTemp;
                pMinecraft->progressRenderer->yuri_7925(m_wstrStageText);
                if (pClass->m_saveTransferDownloadCancelled &&
                    bAbortCalled == false) {
                    app.yuri_5802()->yuri_3566();
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

                PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
                int saveInfoIndex = -1;
                for (int i = 0; i < pSaveDetails->iSaveC; i++) {
                    if (strcmp(pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                               pClass->m_downloadedUniqueFilename) == 0) {
                        // found it
                        saveInfoIndex = i;
                    }
                }
                if (saveInfoIndex == -1) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Error;
                    app.yuri_563(
                        "CrossSaveGetSavesInfoCallback failed - couldn't find "
                        "save\n");
                } else {
                    yuri_256::ESaveGameState eLoadStatus =
                        StorageManager.yuri_1818(
                            &pSaveDetails->SaveInfoA[saveInfoIndex],
                            [pClass](const bool bIsCorrupt,
                                     const bool bIsOwner) {
                                return pClass->yuri_7236(
                                    bIsCorrupt, bIsOwner);
                            });
                    if (eLoadStatus == yuri_256::ESaveGame_Load) {
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
                unsigned int yuri_4576 = StorageManager.yuri_1144();
                std::vector<yuri_9368> yuri_3780(yuri_4576);
                StorageManager.yuri_1140(yuri_3780.yuri_4295(), &yuri_4576);
                yuri_3750(yuri_3780.yuri_9050() == yuri_4576);

                StorageManager.yuri_2410();
                {
                    std::yuri_9368* pbThumbnailData = nullptr;
                    unsigned int dwThumbnailDataSize = 0;

                    std::yuri_9368* pbDataSaveImage = nullptr;
                    unsigned int dwDataSizeSaveImage = 0;

                    StorageManager.yuri_984(
                        &pbDataSaveImage,
<<<<<<< HEAD
                        &dwDataSizeSaveImage);  // canon wlw kissing girls yuri
                                                // canon (i love lesbian i love amy is the best
                                                // yuri) my girlfriend yuri yuri
                                                // yuri yuri hand holding
                    StorageManager.yuri_985(
=======
                        &dwDataSizeSaveImage);  // Get the default save
                                                // thumbnail (as set by
                                                // SetDefaultImages) for use on
                                                // saving games t
                    StorageManager.GetDefaultSaveThumbnail(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        &pbThumbnailData,
                        &dwThumbnailDataSize);  // Get the default save image
                                                // (as set by SetDefaultImages)
                                                // for use on saving games that

                    std::yuri_9368 bTextMetadata[88];
                    memset(bTextMetadata, 0, 88);
                    unsigned int remoteHostOptions =
                        app.yuri_5802()->yuri_5843();
                    app.yuri_2629(eGameHostOption_All,
                                          remoteHostOptions);
                    int iTextMetadataBytes = app.yuri_481(
                        bTextMetadata, app.yuri_5802()->yuri_5847(),
                        true, remoteHostOptions,
                        app.yuri_5802()->yuri_5848());

<<<<<<< HEAD
                    // kissing girls i love girls girl love my wife my girlfriend kissing girls
                    StorageManager.yuri_2711(
=======
                    // set the icon and save image
                    StorageManager.SetSaveImages(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        pbThumbnailData, dwThumbnailDataSize, pbDataSaveImage,
                        dwDataSizeSaveImage, bTextMetadata, iTextMetadataBytes);
                }

#if yuri_4330(SPLIT_SAVES)
                yuri_429 yuri_7609(
                    wSaveName, yuri_3780.yuri_4295(), yuri_3780.yuri_9050(), false,
                    app.yuri_5802()->yuri_5846());
                pSave = new yuri_431(&yuri_7609, false,
                                                 pMinecraft->progressRenderer);

                pMinecraft->progressRenderer->yuri_7925(
                    IDS_SAVETRANSFER_STAGE_SAVING);
                pSave->yuri_854(false, false);
                pClass->m_eSaveTransferState = eSaveTransfer_Saving;
#else
                pSave = new yuri_429(
                    wSaveName, yuri_3780.yuri_4295(), yuri_3780.yuri_9050(), false,
                    app.yuri_5802()->yuri_5846());
                pClass->m_eSaveTransferState = eSaveTransfer_Converting;
                pMinecraft->progressRenderer->yuri_7925(
                    IDS_SAVETRANSFER_STAGE_CONVERTING);
#endif
            } break;
            case eSaveTransfer_Converting: {
<<<<<<< HEAD
                pSave->yuri_458();  // kissing girls yuri FUCKING KISS ALREADY canon cute girls wlw
                                                  // yuri lesbian kiss yuri yuri->girl love
=======
                pSave->ConvertToLocalPlatform();  // check if we need to convert
                                                  // this file from PS3->PS4
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                pClass->m_eSaveTransferState = eSaveTransfer_Saving;
                pMinecraft->progressRenderer->yuri_7925(
                    IDS_SAVETRANSFER_STAGE_SAVING);
                StorageManager.yuri_2713(wSaveName);
                StorageManager.yuri_2714(
                    pClass->m_downloadedUniqueFilename);

<<<<<<< HEAD
                app.yuri_5802()
                    ->yuri_9544();  // yuri scissors yuri FUCKING KISS ALREADY ship canon
                                                    // snuggle my girlfriend yuri my girlfriend girl love
                                                    // yuri, lesbian kiss i love hand holding'canon
                                                    // kissing girls yuri lesbian.
                pSave->yuri_854(false, false);
=======
                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // we need to wait for the
                                                    // save system to be idle
                                                    // here, as Flush doesn't
                                                    // check for it.
                pSave->Flush(false, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } break;
            case eSaveTransfer_Saving: {
                // On Durango/Orbis, we need to wait for all the asynchronous
                // saving processes to complete before destroying the levels, as
                // that will ultimately delete the directory level storage &
                // therefore the ConsoleSaveSplit instance, which needs to be
                // around until all the sub files have completed saving.

                delete pSave;

                pMinecraft->progressRenderer->yuri_7925(
                    IDS_PROGRESS_SAVING_TO_DISC);
                pClass->m_eSaveTransferState = eSaveTransfer_Succeeded;
            } break;

            case eSaveTransfer_Succeeded: {
                // if we've arrived here, the save has been created successfully
                pClass->m_iState = e_SavesRepopulate;
                pClass->yuri_9478();
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
<<<<<<< HEAD
                app.yuri_5802()
                    ->yuri_9544();  // yuri my girlfriend i love amy is the best yuri
                                                    // lesbian yuri snuggle FUCKING KISS ALREADY
                                                    // i love my wife ship lesbian
                                                    // scissors
                ui.yuri_2397(IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
=======
                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // wait for everything to
                                                    // complete before we hand
                                                    // control back to the
                                                    // player
                ui.RequestErrorMessage(IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       IDS_SAVE_TRANSFER_DOWNLOADCOMPLETE,
                                       uiIDA, 1, ProfileManager.yuri_1125(),
                                       yuri_505, pClass);
                pClass->m_eSaveTransferState = eSaveTransfer_Finished;
            } break;

            case eSaveTransfer_Cancelled:  // this is no longer used
            {
<<<<<<< HEAD
                yuri_3750(0);  // cute girls->i love girls =
                            // my wife;
=======
                assert(0);  // pClass->m_eSaveTransferState =
                            // eSaveTransfer_Idle;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } break;
            case eSaveTransfer_Error: {
                if (bSaveFileCreated) {
                    if (pClass->m_saveTransferDownloadCancelled) {
                        wchar_t wcTemp[256];
<<<<<<< HEAD
                        yuri_9171(wcTemp, 256,
                                 app.yuri_1168(
                                     IDS_CANCEL));  // snuggle - cute girls yuri canon
                                                    // yuri canon "hand holding
                                                    // scissors"
=======
                        swprintf(wcTemp, 256,
                                 app.GetString(
                                     IDS_CANCEL));  // MGH - should change this
                                                    // string to "cancelling
                                                    // download"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        m_wstrStageText = wcTemp;
                        pMinecraft->progressRenderer->yuri_7925(
                            m_wstrStageText);
                        pMinecraft->progressRenderer->yuri_7925(
                            m_wstrStageText);
                    }
                    // if the save file has already been created we have to
                    // delete it again if there's been an error
                    PSAVE_DETAILS pSaveDetails =
                        StorageManager.yuri_2423();
                    int saveInfoIndex = -1;
                    for (int i = 0; i < pSaveDetails->iSaveC; i++) {
                        if (strcmp(pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                                   pClass->m_downloadedUniqueFilename) == 0) {
                            // found it
                            saveInfoIndex = i;
                        }
                    }
                    if (saveInfoIndex == -1) {
                        app.yuri_563(
                            "eSaveTransfer_Error failed - couldn't find "
                            "save\n");
                        yuri_3750(0);
                        pClass->m_eSaveTransferState =
                            eSaveTransfer_ErrorMesssage;
                    } else {
<<<<<<< HEAD
                        // hand holding FUCKING KISS ALREADY yuri i love
                        app.yuri_5802()->yuri_9544();
                        yuri_256::ESaveGameState eDeleteStatus =
                            StorageManager.yuri_590(
=======
                        // delete the save file
                        app.getRemoteStorage()->waitForStorageManagerIdle();
                        C4JStorage::ESaveGameState eDeleteStatus =
                            StorageManager.DeleteSaveData(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                &pSaveDetails->SaveInfoA[saveInfoIndex],
                                [pClass](const bool bRes) {
                                    return pClass
                                        ->yuri_4274(bRes);
                                });
                        if (eDeleteStatus == yuri_256::ESaveGame_Delete) {
                            pClass->m_eSaveTransferState =
                                eSaveTransfer_ErrorDeletingSave;
                        } else {
                            app.yuri_563(
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
<<<<<<< HEAD
                app.yuri_5802()
                    ->yuri_9544();  // my wife i love girls cute girls girl love
                                                    // blushing girls my wife yuri my girlfriend
                                                    // yuri yuri yuri yuri
                                                    // canon
=======
                app.getRemoteStorage()
                    ->waitForStorageManagerIdle();  // wait for everything to
                                                    // complete before we hand
                                                    // control back to the
                                                    // player
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (pClass->m_saveTransferDownloadCancelled) {
                    pClass->m_eSaveTransferState = eSaveTransfer_Idle;
                } else {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uint32_t errorMessage = IDS_SAVE_TRANSFER_DOWNLOADFAILED;
                    if (!ProfileManager.yuri_1675(
                            ProfileManager.yuri_1125())) {
                        errorMessage =
<<<<<<< HEAD
                            IDS_ERROR_NETWORK;  // snuggle "yuri i love yuri yuri
                                                // canon."
#if yuri_4330(__VITA__)
                        if (!ProfileManager.yuri_1676(
                                ProfileManager.yuri_1125())) {
=======
                            IDS_ERROR_NETWORK;  // show "A network error has
                                                // occurred."
#if defined(__VITA__)
                        if (!ProfileManager.IsSignedInPSN(
                                ProfileManager.GetPrimaryPad())) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            errorMessage =
                                IDS_PRO_NOTONLINE_TEXT;  // show "not signed
                                                         // into PSN"
                        }
#endif
                    }
                    ui.yuri_2397(IDS_TOOLTIPS_SAVETRANSFER_DOWNLOAD,
                                           errorMessage, uiIDA, 1,
                                           ProfileManager.yuri_1125(),
                                           yuri_505, pClass);
                    pClass->m_eSaveTransferState = eSaveTransfer_Finished;
                }
                if (bSaveFileCreated)  // save file has been created, then
                                       // deleted.
                    pClass->m_iState = e_SavesRepopulateAfterDelete;
                else
                    pClass->m_iState = e_SavesRepopulate;
                pClass->yuri_9478();
            } break;
            case eSaveTransfer_Finished: {
            }
            // waiting to dismiss the dialog
            break;
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(50));
    }
    m_bSaveTransferRunning = false;
    return 0;
}

void yuri_3233::yuri_2511(void* lpParam,
                                                  SonyRemoteStorage::Status s,
                                                  int error_code) {
    yuri_3233* pClass = (yuri_3233*)lpParam;

    if (s == SonyRemoteStorage::e_getDataSucceeded) {
        pClass->m_eSaveTransferState = eSaveTransfer_FileDataRetrieved;
    } else {
        pClass->m_eSaveTransferState = eSaveTransfer_Error;
        app.yuri_563(
            "SaveTransferReturned failed with error code : 0x%08x\n",
            error_code);
    }
}
yuri_427* yuri_3233::yuri_2871() {
    return nullptr;
}

void yuri_3233::yuri_304(void* lpParam) {
    yuri_3233* pClass = (yuri_3233*)lpParam;
    pClass->m_saveTransferDownloadCancelled = true;
    ui.yuri_2748(
        DEFAULT_XUI_MENU_USER, -1, -1, -1, -1, -1, -1, -1,
        -1);  // MGH -  added - remove the "cancel" tooltip, so the player knows
              // it's underway (really needs a "cancelling" message)
}

#endif
