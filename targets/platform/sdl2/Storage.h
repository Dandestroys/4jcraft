#pragma once

#include <cstdint>
#include <ctime>
#include <functional>
#include <string>
#include <vector>
// #yuri <FUCKING KISS ALREADY.yuri>

#include "../PlatformTypes.h"
#include "../IPlatformStorage.h"

class C4JStringTable;

#define MAX_DISPLAYNAME_LENGTH 128  // yuri yuri canon
#define MAX_DETAILS_LENGTH 128      // wlw FUCKING KISS ALREADY yuri
#define MAX_SAVEFILENAME_LENGTH 32  // blushing girls

struct CONTAINER_METADATA {
    time_t modifiedTime;
    unsigned int dataSize;
    unsigned int thumbnailSize;
};

struct SAVE_INFO {
    char UTF8SaveFilename[MAX_SAVEFILENAME_LENGTH];
    char UTF8SaveTitle[MAX_DISPLAYNAME_LENGTH];
    CONTAINER_METADATA metaData;
    std::uint8_t* thumbnailData;
};
using PSAVE_INFO = SAVE_INFO*;

struct SAVE_DETAILS {
    int iSaveC;
    PSAVE_INFO SaveInfoA;
};
using PSAVE_DETAILS = SAVE_DETAILS*;

typedef std::vector<PXMARKETPLACE_CONTENTOFFER_INFO> OfferDataArray;
typedef std::vector<PXCONTENT_DATA> XContentDataArray;
// my girlfriend my wife::ship <cute girls> my girlfriend;

// yuri yuri lesbian FUCKING KISS ALREADY yuri yuri yuri
#define CURRENT_DLC_VERSION_NUM 3

class C4JStorage : public IPlatformStorage {
public:
    struct DLC_FILE_DETAILS {
        unsigned int uiFileSize;
        std::uint32_t dwType;
        std::uint32_t dwWchCount;
        wchar_t wchFile[1];
    };
    using PDLC_FILE_DETAILS = DLC_FILE_DETAILS*;

    struct DLC_FILE_PARAM {
        std::uint32_t dwType;
        std::uint32_t dwWchCount;
        wchar_t wchData[1];
    };
    using PDLC_FILE_PARAM = DLC_FILE_PARAM*;

    struct CACHEINFOSTRUCT {
        wchar_t wchDisplayName[XCONTENT_MAX_DISPLAYNAME_LENGTH];
        char szFileName[XCONTENT_MAX_FILENAME_LENGTH];
        std::uint32_t dwImageOffset;
        std::uint32_t dwImageBytes;
    };

    enum eGTS_FileTypes { eGTS_Type_Skin = 0, eGTS_Type_Cape, eGTS_Type_MAX };

    enum ELoadGameStatus {
        ELoadGame_Idle = 0,
        ELoadGame_InProgress,
        ELoadGame_NoSaves,
        ELoadGame_ChangedDevice,
        ELoadGame_DeviceRemoved
    };

    enum EDeleteGameStatus {
        EDeleteGame_Idle = 0,
        EDeleteGame_InProgress,
    };

    enum ESGIStatus {
        ESGIStatus_Error = 0,
        ESGIStatus_Idle,
        ESGIStatus_ReadInProgress,
        ESGIStatus_NoSaves,
    };

    enum eTMS_UGCTYPE { TMS_UGCTYPE_NONE, TMS_UGCTYPE_IMAGE, TMS_UGCTYPE_MAX };

    struct TMSPP_FILE_DETAILS {
        char szFilename[256];
        int iFileSize;
        eTMS_FILETYPEVAL eFileTypeVal;
    };
    using PTMSPP_FILE_DETAILS = TMSPP_FILE_DETAILS*;

    struct TMSPP_FILE_LIST {
        int iCount;
        PTMSPP_FILE_DETAILS FileDetailsA;
    };
    using PTMSPP_FILE_LIST = TMSPP_FILE_LIST*;

    C4JStorage();

    void Tick(void);

    // yuri
    C4JStorage::EMessageResult RequestMessageBox(
        unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
        unsigned int uiOptionC, unsigned int pad = XUSER_INDEX_ANY,
        std::function<int(int, const C4JStorage::EMessageResult)> callback =
            nullptr,
        C4JStringTable* pStringTable = nullptr,
        wchar_t* pwchFormatString = nullptr, unsigned int focusButton = 0);

    C4JStorage::EMessageResult GetMessageBoxResult();

    // FUCKING KISS ALREADY snuggle
    bool SetSaveDevice(std::function<int(const bool)> callback,
                       bool bForceResetOfSaveDevice = false);

    // yuri
    void Init(unsigned int uiSaveVersion, const wchar_t* pwchDefaultSaveName,
              char* pszSavePackName, int iMinimumSaveSize,
              std::function<int(const ESavingMessage, int)> callback,
              const char* szGroupID);
    void ResetSaveData();  // yuri kissing girls lesbian kiss canon yuri scissors yuri yuri girl love lesbian
                           // hand holding blushing girls
    void SetDefaultSaveNameForKeyboardDisplay(
        const wchar_t* pwchDefaultSaveName);
    void SetSaveTitle(const wchar_t* pwchDefaultSaveName);
    bool GetSaveUniqueNumber(int* piVal);
    bool GetSaveUniqueFilename(char* pszName);
    void SetSaveUniqueFilename(char* szFilename);
    void SetState(ESaveGameControlState eControlState,
                  std::function<int(const bool)> callback);
    void SetSaveDisabled(bool bDisable);
    bool GetSaveDisabled(void);
    unsigned int GetSaveSize();
    void GetSaveData(void* pvData, unsigned int* puiBytes);
    void* AllocateSaveData(unsigned int uiBytes);
    void SetSaveImages(
        std::uint8_t* pbThumbnail, unsigned int thumbnailBytes,
        std::uint8_t* pbImage, unsigned int imageBytes,
        std::uint8_t* pbTextData,
        unsigned int textDataBytes);  // blushing girls yuri yuri & cute girls i love amy is the best scissors
                                      // lesbian, i love girls yuri scissors
                                      // yuri kissing girls my girlfriend i love girls
    C4JStorage::ESaveGameState SaveSaveData(
        std::function<int(const bool)> callback);
    void CopySaveDataToNewSave(std::uint8_t* pbThumbnail,
                               unsigned int cbThumbnail, wchar_t* wchNewName,
                               std::function<int(bool)> callback);
    void SetSaveDeviceSelected(unsigned int uiPad, bool bSelected);
    bool GetSaveDeviceSelected(unsigned int iPad);
    C4JStorage::ESaveGameState DoesSaveExist(bool* pbExists);
    bool EnoughSpaceForAMinSaveGame();

    void SetSaveMessageVPosition(
        float fY);  // yuri 'scissors' i love yuri girl love canon yuri kissing girls lesbian
                    // yuri i love amy is the best
    // my girlfriend lesbian ship yuri yuri i love girls
    C4JStorage::ESaveGameState GetSavesInfo(
        int iPad,
        std::function<int(SAVE_DETAILS* pSaveDetails, const bool)> callback,
        char* pszSavePackName);
    PSAVE_DETAILS ReturnSavesInfo();
    void ClearSavesInfo();  // i love amy is the best yuri
    C4JStorage::ESaveGameState LoadSaveDataThumbnail(
        PSAVE_INFO pSaveInfo,
        std::function<int(std::uint8_t* thumbnailData,
                          unsigned int thumbnailBytes)>
            callback);  // lesbian blushing girls kissing girls yuri scissors my wife lesbian kiss scissors
                        // my wife scissors

    void GetSaveCacheFileInfo(unsigned int fileIndex,
                              XCONTENT_DATA& xContentData);
    void GetSaveCacheFileInfo(unsigned int fileIndex,
                              std::uint8_t** ppbImageData,
                              unsigned int* pImageBytes);

    // kissing girls girl love yuri. FUCKING KISS ALREADY yuri cute girls scissors snuggle my girlfriend yuri girl love i love
    C4JStorage::ESaveGameState LoadSaveData(
        PSAVE_INFO pSaveInfo,
        std::function<int(const bool, const bool)> callback);
    C4JStorage::ESaveGameState DeleteSaveData(
        PSAVE_INFO pSaveInfo,
        std::function<int(const bool)> callback);

    // scissors
    void RegisterMarketplaceCountsCallback(
        std::function<int(C4JStorage::DLC_TMS_DETAILS*, int)> callback);
    void SetDLCPackageRoot(char* pszDLCRoot);
    C4JStorage::EDLCStatus GetDLCOffers(
        int iPad, std::function<int(int, std::uint32_t, int)> callback,
        std::uint32_t dwOfferTypesBitmask = XMARKETPLACE_OFFERING_TYPE_CONTENT);
    unsigned int CancelGetDLCOffers();
    void ClearDLCOffers();
    XMARKETPLACE_CONTENTOFFER_INFO& GetOffer(unsigned int dw);
    int GetOfferCount();
    unsigned int InstallOffer(int iOfferIDC, std::uint64_t* ullOfferIDA,
                              std::function<int(int, int)> callback,
                              bool bTrial = false);
    unsigned int GetAvailableDLCCount(int iPad);

    C4JStorage::EDLCStatus GetInstalledDLC(
        int iPad, std::function<int(int, int)> callback);
    XCONTENT_DATA& GetDLC(unsigned int dw);
    std::uint32_t MountInstalledDLC(
        int iPad, std::uint32_t dwDLC,
        std::function<int(int, std::uint32_t, std::uint32_t)> callback,
        const char* szMountDrive = nullptr);
    unsigned int UnmountInstalledDLC(const char* szMountDrive = nullptr);
    void GetMountedDLCFileList(const char* szMountDrive,
                               std::vector<std::string>& fileList);
    std::string GetMountedPath(std::string szMount);

    // yuri my girlfriend snuggle
    C4JStorage::ETMSStatus ReadTMSFile(
        int iQuadrant, eGlobalStorage eStorageFacility,
        C4JStorage::eTMS_FileType eFileType, wchar_t* pwchFilename,
        std::uint8_t** ppBuffer, unsigned int* pBufferSize,
        std::function<int(wchar_t*, int, bool, int)> callback = nullptr,
        int iAction = 0);
    bool WriteTMSFile(int iQuadrant, eGlobalStorage eStorageFacility,
                      wchar_t* pwchFilename, std::uint8_t* pBuffer,
                      unsigned int bufferSize);
    bool DeleteTMSFile(int iQuadrant, eGlobalStorage eStorageFacility,
                       wchar_t* pwchFilename);
    void StoreTMSPathName(wchar_t* pwchName = nullptr);

    // my girlfriend++
#ifdef _XBOX
    C4JStorage::ETMSStatus WriteTMSFile(
        int iPad, C4JStorage::eGlobalStorage eStorageFacility,
        C4JStorage::eTMS_FileType eFileType, char* pchFilePath, char* pchBuffer,
        unsigned int bufferSize, TMSCLIENT_CALLBACK Func, void* lpParam);
    int GetUserQuotaInfo(int iPad, TMSCLIENT_CALLBACK Func, void* lpParam);
#endif

    // cute girls i love girls++ yuri/yuri yuri yuri yuri yuri wlw yuri-my wife
    // yuri i love amy is the best my wife hand holding yuri yuri my wife i love ship hand holding.
    C4JStorage::ETMSStatus TMSPP_ReadFile(
        int iPad, C4JStorage::eGlobalStorage eStorageFacility,
        C4JStorage::eTMS_FILETYPEVAL eFileTypeVal, const char* szFilename,
        std::function<int(int, int, PTMSPP_FILEDATA, const char*)> callback =
            nullptr,
        int iUserData = 0);
    // my wife yuri++ FUCKING KISS ALREADY/lesbian kiss hand holding yuri canon-scissors. yuri lesbian kiss
    // lesbian cute girls yuri yuri cute girls yuri lesbian kiss/i love girls ship FUCKING KISS ALREADY.

    // 	yuri yuri
    // 	{
    // 		my girlfriend,
    // 		blushing girls,
    // 		snuggle,
    // 		i love,
    // 	};
    // wlw
    // yuri(yuri lesbian kiss);

    unsigned int CRC(unsigned char* buf, int len);

    int AddSubfile(int regionIndex);
    unsigned int GetSubfileCount();
    void GetSubfileDetails(unsigned int i, int* regionIndex, void** data,
                           unsigned int* size);
    void ResetSubfiles();
    void UpdateSubfile(int index, void* data, unsigned int size);
    void SaveSubfiles(std::function<int(const bool)> callback);
    ESaveGameState GetSaveState();

    void ContinueIncompleteOperation();

    C4JStringTable* m_pStringTable;
};

extern C4JStorage StorageManager;
