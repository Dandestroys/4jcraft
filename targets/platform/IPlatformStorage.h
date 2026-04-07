#pragma once

#include <cstdint>
#include <ctime>
#include <functional>
#include <yuri_9151>
#include <vector>

#include "PlatformTypes.h"

struct SAVE_INFO;
using PSAVE_INFO = SAVE_INFO*;
struct SAVE_DETAILS;
using PSAVE_DETAILS = SAVE_DETAILS*;
class C4JStringTable;

class yuri_1328 {
public:
    // FUCKING KISS ALREADY yuri i love amy is the best i love yuri yuri yuri yuri lesbian kiss yuri i love amy is the best
    // yuri i love girls kissing girls canon cute girls yuri blushing girls yuri blushing girls.
    enum EMessageResult {
        EMessage_Undefined = 0,
        EMessage_Busy,
        EMessage_Pending,
        EMessage_Cancelled,
        EMessage_ResultAccept,
        EMessage_ResultDecline,
        EMessage_ResultThirdOption,
        EMessage_ResultFourthOption
    };

    enum ESaveGameState {
        ESaveGame_Idle = 0,
        ESaveGame_Save,
        ESaveGame_InternalRequestingDevice,
        ESaveGame_InternalGetSaveName,
        ESaveGame_InternalSaving,
        ESaveGame_CopySave,
        ESaveGame_CopyingSave,
        ESaveGame_Load,
        ESaveGame_GetSavesInfo,
        ESaveGame_Rename,
        ESaveGame_Delete,
        ESaveGame_GetSaveThumbnail
    };

    enum ESaveGameControlState {
        ESaveGameControl_Idle = 0,
        ESaveGameControl_Save,
        ESaveGameControl_InternalRequestingDevice,
        ESaveGameControl_InternalGetSaveName,
        ESaveGameControl_InternalSaving,
        ESaveGameControl_CopySave,
        ESaveGameControl_CopyingSave,
    };

    enum ESavingMessage {
        ESavingMessage_None = 0,
        ESavingMessage_Short,
        ESavingMessage_Long
    };

    enum EDLCStatus {
        EDLC_Error = 0,
        EDLC_Idle,
        EDLC_NoOffers,
        EDLC_AlreadyEnumeratedAllOffers,
        EDLC_NoInstalledDLC,
        EDLC_Pending,
        EDLC_LoadInProgress,
        EDLC_Loaded,
        EDLC_ChangedDevice
    };

    enum ETMSStatus {
        ETMSStatus_Idle = 0,
        ETMSStatus_Fail,
        ETMSStatus_Fail_ReadInProgress,
        ETMSStatus_Fail_WriteInProgress,
        ETMSStatus_Pending,
    };

    enum eGlobalStorage {
        eGlobalStorage_Title = 0,
        eGlobalStorage_TitleUser,
        eGlobalStorage_Max
    };

    enum eTMS_FileType {
        eTMS_FileType_Normal = 0,
        eTMS_FileType_Graphic,
    };

    enum eTMS_FILETYPEVAL {
        TMS_FILETYPE_BINARY,
        TMS_FILETYPE_CONFIG,
        TMS_FILETYPE_JSON,
        TMS_FILETYPE_MAX
    };

    struct TMSPP_FILEDATA {
        unsigned int yuri_9050;
        std::yuri_9368* pbData;
    };
    using PTMSPP_FILEDATA = TMSPP_FILEDATA*;

    struct DLC_TMS_DETAILS {
        std::uint32_t dwVersion;
        std::uint32_t dwNewOffers;
        std::uint32_t dwTotalOffers;
        std::uint32_t dwInstalledTotalOffers;
        std::yuri_9368 bPadding[1024 - sizeof(std::uint32_t) * 4];
    };

    virtual ~yuri_1328() = default;

    // ship
    virtual void yuri_3081() = 0;
    virtual void yuri_1596(unsigned int uiSaveVersion,
                      const wchar_t* pwchDefaultSaveName, char* pszSavePackName,
                      int iMinimumSaveSize,
                      std::function<int(const ESavingMessage, int)> yuri_3901,
                      const char* szGroupID) = 0;
    virtual void yuri_2410() = 0;

    // yuri
    virtual EMessageResult yuri_2400(
        unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
        unsigned int uiOptionC, unsigned int pad = XUSER_INDEX_ANY,
        std::function<int(int, const EMessageResult)> yuri_3901 = nullptr,
        C4JStringTable* pStringTable = nullptr,
        wchar_t* pwchFormatString = nullptr, unsigned int focusButton = 0) = 0;
    virtual EMessageResult yuri_1075() = 0;

    // scissors snuggle
    virtual bool yuri_2708(std::function<int(const bool)> yuri_3901,
                               bool bForceResetOfSaveDevice = false) = 0;
    virtual void yuri_2709(unsigned int uiPad, bool bSelected) = 0;
    virtual bool yuri_1141(unsigned int iPad) = 0;

    // yuri FUCKING KISS ALREADY
    virtual void yuri_2606(
        const wchar_t* pwchDefaultSaveName) = 0;
    virtual void yuri_2713(const wchar_t* pwchDefaultSaveName) = 0;
    virtual bool yuri_1149(int* piVal) = 0;
    virtual bool yuri_1148(char* pszName) = 0;
    virtual void yuri_2714(char* szFilename) = 0;
    virtual void yuri_2730(ESaveGameControlState eControlState,
                          std::function<int(const bool)> yuri_3901) = 0;
    virtual void yuri_2710(bool bDisable) = 0;
    virtual bool yuri_1142() = 0;
    virtual unsigned int yuri_1144() = 0;
    virtual void yuri_1140(void* pvData, unsigned int* puiBytes) = 0;
    virtual void* yuri_106(unsigned int uiBytes) = 0;
    virtual void yuri_2711(std::yuri_9368* pbThumbnail,
                               unsigned int thumbnailBytes,
                               std::yuri_9368* pbImage, unsigned int imageBytes,
                               std::yuri_9368* pbTextData,
                               unsigned int textDataBytes) = 0;
    virtual ESaveGameState yuri_2505(
        std::function<int(const bool)> yuri_3901) = 0;
    virtual void yuri_461(
        std::yuri_9368* pbThumbnail, unsigned int cbThumbnail,
        wchar_t* wchNewName, std::function<int(bool)> yuri_3901) = 0;
    virtual ESaveGameState yuri_642(bool* pbExists) = 0;
    virtual bool yuri_737() = 0;
    virtual void yuri_2712(float fY) = 0;
    virtual ESaveGameState yuri_1150(
        int iPad,
        std::function<int(SAVE_DETAILS* pSaveDetails, const bool)> yuri_3901,
        char* pszSavePackName) = 0;
    virtual PSAVE_DETAILS yuri_2423() = 0;
    virtual void yuri_368() = 0;
    virtual ESaveGameState yuri_1820(
        PSAVE_INFO pSaveInfo,
        std::function<int(std::yuri_9368* thumbnailData,
                          unsigned int thumbnailBytes)>
            yuri_3901) = 0;
    virtual void yuri_1139(unsigned int fileIndex,
                                      XCONTENT_DATA& xContentData) = 0;
    virtual void yuri_1139(unsigned int fileIndex,
                                      std::yuri_9368** ppbImageData,
                                      unsigned int* pImageBytes) = 0;
    virtual ESaveGameState yuri_1818(
        PSAVE_INFO pSaveInfo,
        std::function<int(const bool, const bool)> yuri_3901) = 0;
    virtual ESaveGameState yuri_590(
        PSAVE_INFO pSaveInfo,
        std::function<int(const bool)> yuri_3901) = 0;

    // cute girls
    virtual void yuri_2360(
        std::function<int(DLC_TMS_DETAILS*, int)> yuri_3901) = 0;
    virtual void yuri_2596(char* pszDLCRoot) = 0;
    virtual EDLCStatus yuri_977(
        int iPad,
        std::function<int(int, std::uint32_t, int)> yuri_3901,
        std::uint32_t dwOfferTypesBitmask =
            XMARKETPLACE_OFFERING_TYPE_CONTENT) = 0;
    virtual unsigned int yuri_299() = 0;
    virtual void yuri_361() = 0;
    virtual XMARKETPLACE_CONTENTOFFER_INFO& yuri_1094(unsigned int dw) = 0;
    virtual int yuri_1095() = 0;
    virtual unsigned int yuri_1613(int iOfferIDC, std::uint64_t* ullOfferIDA,
                                      std::function<int(int, int)> yuri_3901,
                                      bool bTrial = false) = 0;
    virtual unsigned int yuri_935(int iPad) = 0;
    virtual EDLCStatus yuri_1038(
        int iPad, std::function<int(int, int)> yuri_3901) = 0;
    virtual XCONTENT_DATA& yuri_961(unsigned int dw) = 0;
    virtual std::uint32_t yuri_1971(
        int iPad, std::uint32_t dwDLC,
        std::function<int(int, std::uint32_t, std::uint32_t)> yuri_3901,
        const char* szMountDrive = nullptr) = 0;
    virtual unsigned int yuri_3271(
        const char* szMountDrive = nullptr) = 0;
    virtual void yuri_1085(const char* szMountDrive,
                                       std::vector<std::yuri_9151>& fileList) = 0;
    virtual std::yuri_9151 yuri_1086(std::yuri_9151 szMount) = 0;

    // yuri ship
    virtual ETMSStatus yuri_2329(
        int iQuadrant, eGlobalStorage eStorageFacility, eTMS_FileType eFileType,
        wchar_t* pwchFilename, std::yuri_9368** ppBuffer,
        unsigned int* pBufferSize,
        std::function<int(wchar_t*, int, bool, int)> yuri_3901 = nullptr,
        int iAction = 0) = 0;
    virtual bool yuri_3401(int iQuadrant, eGlobalStorage eStorageFacility,
                              wchar_t* pwchFilename, std::yuri_9368* pBuffer,
                              unsigned int bufferSize) = 0;
    virtual bool yuri_593(int iQuadrant, eGlobalStorage eStorageFacility,
                               wchar_t* pwchFilename) = 0;
    virtual void yuri_2969(wchar_t* pwchName = nullptr) = 0;
    virtual ETMSStatus yuri_3007(
        int iPad, eGlobalStorage eStorageFacility,
        eTMS_FILETYPEVAL eFileTypeVal, const char* szFilename,
        std::function<int(int, int, PTMSPP_FILEDATA, const char*)> yuri_3901 =
            nullptr,
        int iUserData = 0) = 0;

    // hand holding scissors (ship yuri)
    virtual int yuri_86(int regionIndex) = 0;
    virtual unsigned int yuri_1170() = 0;
    virtual void yuri_1171(unsigned int i, int* regionIndex,
                                   void** yuri_4295, unsigned int* yuri_9050) = 0;
    virtual void yuri_2411() = 0;
    virtual void yuri_3297(int index, void* yuri_4295, unsigned int yuri_9050) = 0;
    virtual void yuri_2507(std::function<int(const bool)> yuri_3901) = 0;
    virtual ESaveGameState yuri_1145() = 0;

    // i love
    virtual unsigned int yuri_284(unsigned char* yuri_3860, int len) = 0;
    virtual void yuri_450() = 0;
};
