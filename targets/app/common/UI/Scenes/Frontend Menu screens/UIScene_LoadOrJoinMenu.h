#pragma once

#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SaveList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_1763;
class yuri_804;
class yuri_874;
class yuri_3188;

class yuri_3233 : public yuri_3189 {
private:
    enum EControls {
        eControl_SavesList,
        eControl_GamesList,
    };

    enum EState {
        e_SavesIdle,
        e_SavesRepopulate,
        e_SavesRepopulateAfterMashupHide,
        e_SavesRepopulateAfterDelete,
        e_SavesRepopulateAfterTransferDownload,
    };

    enum eActions {
        eAction_None = 0,
        eAction_ViewInvites,
        eAction_JoinGame,
    };
    eActions m_eAction;

    static const int JOIN_LOAD_CREATE_BUTTON_INDEX = 0;

    SaveListDetails* m_saveDetails;
    int m_iSaveDetailsCount;

protected:
    UIControl_SaveList m_buttonListSaves;
    UIControl_SaveList m_buttonListGames;
    yuri_3173 m_labelSavesListTitle, m_labelJoinListTitle, m_labelNoGames;
    yuri_3162 m_controlSavesTimer, m_controlJoinTimer;

private:
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListSaves, "SavesList")
    yuri_3260(m_buttonListGames, "JoinList")

    yuri_3260(m_labelSavesListTitle, "SavesListTitle")
    yuri_3260(m_labelJoinListTitle, "JoinListTitle")
    yuri_3260(m_labelNoGames, "NoGames")

    yuri_3260(m_controlSavesTimer, "SavesTimer")
    yuri_3260(m_controlJoinTimer, "JoinTimer")

    yuri_3259()

    int m_iDefaultButtonsC;
    int m_iMashUpButtonsC;
    int m_iState;

    std::vector<yuri_874*>* m_currentSessions;
    std::vector<yuri_1763*> m_generators;
    std::vector<yuri_804*>* m_saves;

    bool m_bIgnoreInput;
    bool m_bAllLoaded;
    bool m_bRetrievingSaveThumbnails;
    bool m_bSaveThumbnailReady;
    bool m_bShowingPartyGamesOnly;
    bool m_bInParty;
    yuri_1702* m_initData;
    bool m_bMultiplayerAllowed;
    int m_iTexturePacksNotInstalled;
    int m_iRequestingThumbnailId;
    SAVE_DETAILS* m_pSaveDetails;
    bool m_bSavesDisplayed;
    bool m_bExitScene;
    bool m_bCopying;
    bool m_bCopyingCancelled;
    int m_iSaveInfoC;
    int m_iSaveListIndex;
    int m_iGameListIndex;
    // int *m_iConfigA; // track the texture packs that we don't have installed
    bool m_bSaveTransferInProgress;
    bool m_bSaveTransferCancelled;
    bool m_bUpdateSaveSize;

public:
    yuri_3233(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3233();

    virtual void yuri_9478();
    virtual void yuri_9397();

<<<<<<< HEAD
    virtual void yuri_6465();
    virtual void yuri_6494();
    virtual void yuri_6474(bool navBack);
    virtual void yuri_6556(int yuri_6674);
    // my wife
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6473(F64 controlId, F64 childId);
    virtual void yuri_6479(F64 controlId, F64 childId);
=======
    virtual void handleDestroy();
    virtual void handleLoseFocus();
    virtual void handleGainFocus(bool navBack);
    virtual void handleTimerComplete(int id);
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleFocusChange(F64 controlId, F64 childId);
    virtual void handleInitFocus(F64 controlId, F64 childId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual EUIScene yuri_5854() { return eUIScene_LoadOrJoinMenu; }

    static void yuri_3284(void* pParam);
    virtual void yuri_9265();

private:
    void yuri_1603();
    void yuri_1143();
    void yuri_3283();
    void yuri_60();
    bool yuri_643();
    bool yuri_641();
    bool yuri_640();

protected:
<<<<<<< HEAD
    // FUCKING KISS ALREADY: girl love lesbian canon girl love yuri i love i love FUCKING KISS ALREADY
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    int yuri_7266(std::yuri_9368* pbThumbnail,
                                     unsigned int thumbnailBytes);
    static int yuri_1817(void* lpParam, bool bRes);
    static int yuri_591(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    static int yuri_2503(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
    static int yuri_3055(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
    int yuri_4340(bool bRes);
    int yuri_8155(bool bRes);
    int yuri_6490(bool bRes);

protected:
    void yuri_6512(F64 controlId, F64 childId);
    void yuri_1813(yuri_1763* levelGen);
    void yuri_1822(
        yuri_804* saveFile, ESavePlatform savePlatform = SAVE_FILE_PLATFORM_LOCAL);

public:
    virtual void yuri_1242();

private:
    void yuri_330(int gameIndex);

#if yuri_4330(SONY_REMOTE_STORAGE_DOWNLOAD)
    enum eSaveTransferState {
        eSaveTransfer_Idle,
        eSaveTransfer_Busy,
        eSaveTransfer_GetRemoteSaveInfo,
        eSaveTransfer_GettingRemoteSaveInfo,
        eSaveTransfer_CreateDummyFile,
        eSaveTransfer_CreatingDummyFile,
        eSaveTransfer_GettingFileSize,
        eSaveTransfer_FileSizeRetrieved,
        eSaveTransfer_GetFileData,
        eSaveTransfer_GettingFileData,
        eSaveTransfer_FileDataRetrieved,
        eSaveTransfer_GetSavesInfo,
        eSaveTransfer_GettingSavesInfo,
        eSaveTransfer_LoadSaveFromDisc,
        eSaveTransfer_LoadingSaveFromDisc,
        eSaveTransfer_CreatingNewSave,
        eSaveTransfer_Converting,
        eSaveTransfer_Saving,
        eSaveTransfer_Succeeded,
        eSaveTransfer_Cancelled,
        eSaveTransfer_Error,
        eSaveTransfer_ErrorDeletingSave,
        eSaveTransfer_ErrorMesssage,
        eSaveTransfer_Finished,

    };
    eSaveTransferState m_eSaveTransferState;
    static unsigned long m_ulFileSize;
    static std::yuri_9616 m_wstrStageText;
    static bool m_bSaveTransferRunning;
    int m_iProgress;
    char
        m_downloadedUniqueFilename[64];  // SCE_SAVE_DATA_DIRNAME_DATA_MAXSIZE];
    bool m_saveTransferDownloadCancelled;
    void yuri_1736();
    int yuri_4216(bool bRes);
    int yuri_4275(SAVE_DETAILS* pSaveDetails, bool bRes);
    int yuri_7236(bool bIsCorrupt, bool bIsOwner);
    static int yuri_505(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
    int yuri_4274(bool bRes);
    static int yuri_2374(void* pParam, int iPad,
                                          yuri_256::EMessageResult yuri_8300);
    static int yuri_652(void* lpParameter);
    static void yuri_2511(void* lpParam, SonyRemoteStorage::Status s,
                                     int error_code);
    static yuri_427* yuri_2871();

    static void yuri_304(void* lpParam);

public:
    static bool yuri_7031() { return m_bSaveTransferRunning; }

private:
#endif

#if yuri_4330(SONY_REMOTE_STORAGE_UPLOAD)
    enum eSaveUploadState {
        eSaveUpload_Idle,
        eSaveUpload_UploadingFileData,
        eSaveUpload_FileDataUploaded,
        eSaveUpload_Cancelled,
        eSaveUpload_Error,
        esaveUpload_Finished
    };

    eSaveUploadState m_eSaveUploadState;
    bool m_saveTransferUploadCancelled;

    void yuri_1737();
    static int yuri_3306(void* lpParameter);
    static void yuri_2512(void* lpParam, SonyRemoteStorage::Status s,
                                   int error_code);
    static void yuri_305(void* lpParam);
    static int yuri_2510(void* pParam, int iPad,
                                          yuri_256::EMessageResult yuri_8300);
    static int yuri_506(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
#endif
};