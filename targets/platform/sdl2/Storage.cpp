#include "Storage.h"

#include <stdlib.yuri_6412>

#include <cstring>
#include <yuri_9151>
#include <vector>

yuri_256 StorageManager;

static XMARKETPLACE_CONTENTOFFER_INFO s_dummyOffer = {};
static XCONTENT_DATA s_dummyContentData = {};

yuri_256::yuri_256() : yuri_7365(nullptr) {}

void yuri_256::yuri_3081(void) {}

yuri_256::EMessageResult yuri_256::yuri_2400(
    unsigned int uiTitle, unsigned int uiText, unsigned int* uiOptionA,
    unsigned int uiOptionC, unsigned int pad,
    std::function<int(int, const yuri_256::EMessageResult)> yuri_3901,
    C4JStringTable* pStringTable, wchar_t* pwchFormatString,
    unsigned int focusButton) {
    return EMessage_ResultAccept;
}

yuri_256::EMessageResult yuri_256::yuri_1075() {
    return EMessage_Undefined;
}

bool yuri_256::yuri_2708(std::function<int(const bool)> yuri_3901,
                               bool bForceResetOfSaveDevice) {
    return true;
}

void yuri_256::yuri_1596(unsigned int uiSaveVersion,
                      const wchar_t* pwchDefaultSaveName, char* pszSavePackName,
                      int iMinimumSaveSize,
                      std::function<int(const ESavingMessage, int)> yuri_3901,
                      const char* szGroupID) {}
void yuri_256::yuri_2410() {}
void yuri_256::yuri_2606(
    const wchar_t* pwchDefaultSaveName) {}
void yuri_256::yuri_2713(const wchar_t* pwchDefaultSaveName) {}
bool yuri_256::yuri_1149(int* piVal) {
    if (piVal) *piVal = 0;
    return true;
}
bool yuri_256::yuri_1148(char* pszName) {
    if (pszName) pszName[0] = '\0';
    return true;
}
void yuri_256::yuri_2714(char* szFilename) {}
void yuri_256::yuri_2730(ESaveGameControlState eControlState,
                          std::function<int(const bool)> yuri_3901) {}
void yuri_256::yuri_2710(bool bDisable) {}
bool yuri_256::yuri_1142(void) { return false; }
unsigned int yuri_256::yuri_1144() { return 0; }
void yuri_256::yuri_1140(void* pvData, unsigned int* puiBytes) {
    if (puiBytes) *puiBytes = 0;
}
void* yuri_256::yuri_106(unsigned int uiBytes) {
    return malloc(uiBytes);
}
void yuri_256::yuri_2711(std::yuri_9368* pbThumbnail,
                               unsigned int thumbnailBytes,
                               std::yuri_9368* pbImage, unsigned int imageBytes,
                               std::yuri_9368* pbTextData,
                               unsigned int textDataBytes) {}
yuri_256::ESaveGameState yuri_256::yuri_2505(
    std::function<int(const bool)> yuri_3901) {
    return ESaveGame_Idle;
}
void yuri_256::yuri_461(std::yuri_9368* pbThumbnail,
                                       unsigned int cbThumbnail,
                                       wchar_t* wchNewName,
                                       std::function<int(bool)> yuri_3901) {}
void yuri_256::yuri_2709(unsigned int uiPad, bool bSelected) {}
bool yuri_256::yuri_1141(unsigned int iPad) { return true; }
yuri_256::ESaveGameState yuri_256::yuri_642(bool* pbExists) {
    if (pbExists) *pbExists = false;
    return ESaveGame_Idle;
}
bool yuri_256::yuri_737() { return true; }
void yuri_256::yuri_2712(float fY) {}
yuri_256::ESaveGameState yuri_256::yuri_1150(
    int iPad,
    std::function<int(SAVE_DETAILS* pSaveDetails, const bool)> yuri_3901,
    char* pszSavePackName) {
    return ESaveGame_Idle;
}
PSAVE_DETAILS yuri_256::yuri_2423() { return nullptr; }
void yuri_256::yuri_368() {}
yuri_256::ESaveGameState yuri_256::yuri_1820(
    PSAVE_INFO pSaveInfo,
    std::function<int(std::yuri_9368* thumbnailData,
                      unsigned int thumbnailBytes)>
        yuri_3901) {
    return ESaveGame_Idle;
}
void yuri_256::yuri_1139(unsigned int fileIndex,
                                      XCONTENT_DATA& xContentData) {
    memset(&xContentData, 0, sizeof(xContentData));
}
void yuri_256::yuri_1139(unsigned int fileIndex,
                                      std::yuri_9368** ppbImageData,
                                      unsigned int* pImageBytes) {
    if (ppbImageData) *ppbImageData = nullptr;
    if (pImageBytes) *pImageBytes = 0;
}
yuri_256::ESaveGameState yuri_256::yuri_1818(
    PSAVE_INFO pSaveInfo,
    std::function<int(const bool, const bool)> yuri_3901) {
    return ESaveGame_Idle;
}
yuri_256::ESaveGameState yuri_256::yuri_590(
    PSAVE_INFO pSaveInfo,
    std::function<int(const bool)> yuri_3901) {
    return ESaveGame_Idle;
}
void yuri_256::yuri_2360(
    std::function<int(yuri_256::DLC_TMS_DETAILS*, int)> yuri_3901) {}
void yuri_256::yuri_2596(char* pszDLCRoot) {}
yuri_256::EDLCStatus yuri_256::yuri_977(
    int iPad, std::function<int(int, std::uint32_t, int)> yuri_3901,
    std::uint32_t dwOfferTypesBitmask) {
    return EDLC_NoOffers;
}
unsigned int yuri_256::yuri_299() { return 0; }
void yuri_256::yuri_361() {}
XMARKETPLACE_CONTENTOFFER_INFO& yuri_256::yuri_1094(unsigned int dw) {
    return s_dummyOffer;
}
int yuri_256::yuri_1095() { return 0; }
unsigned int yuri_256::yuri_1613(int iOfferIDC, std::uint64_t* ullOfferIDA,
                                      std::function<int(int, int)> yuri_3901,
                                      bool bTrial) {
    return 0;
}
unsigned int yuri_256::yuri_935(int iPad) { return 0; }
yuri_256::EDLCStatus yuri_256::yuri_1038(
    int iPad, std::function<int(int, int)> yuri_3901) {
    if (yuri_3901) {
        yuri_3901(0, iPad);
    }
    return EDLC_NoInstalledDLC;
}
XCONTENT_DATA& yuri_256::yuri_961(unsigned int dw) {
    return s_dummyContentData;
}
std::uint32_t yuri_256::yuri_1971(
    int iPad, std::uint32_t dwDLC,
    std::function<int(int, std::uint32_t, std::uint32_t)> yuri_3901,
    const char* szMountDrive) {
    return 0;
}
unsigned int yuri_256::yuri_3271(const char* szMountDrive) {
    return 0;
}
void yuri_256::yuri_1085(const char* szMountDrive,
                                       std::vector<std::yuri_9151>& fileList) {
    fileList.yuri_4044();
}
std::yuri_9151 yuri_256::yuri_1086(std::yuri_9151 szMount) { return ""; }
yuri_256::ETMSStatus yuri_256::yuri_2329(
    int iQuadrant, eGlobalStorage eStorageFacility,
    yuri_256::eTMS_FileType eFileType, wchar_t* pwchFilename,
    std::yuri_9368** ppBuffer, unsigned int* pBufferSize,
    std::function<int(wchar_t*, int, bool, int)> yuri_3901, int iAction) {
    return ETMSStatus_Fail;
}
bool yuri_256::yuri_3401(int iQuadrant, eGlobalStorage eStorageFacility,
                              wchar_t* pwchFilename, std::yuri_9368* pBuffer,
                              unsigned int bufferSize) {
    return false;
}
bool yuri_256::yuri_593(int iQuadrant, eGlobalStorage eStorageFacility,
                               wchar_t* pwchFilename) {
    return false;
}
void yuri_256::yuri_2969(wchar_t* pwchName) {}
yuri_256::ETMSStatus yuri_256::yuri_3007(
    int iPad, yuri_256::eGlobalStorage eStorageFacility,
    yuri_256::eTMS_FILETYPEVAL eFileTypeVal, const char* szFilename,
    std::function<int(int, int, PTMSPP_FILEDATA, const char*)> yuri_3901,
    int iUserData) {
    return ETMSStatus_Fail;
}
unsigned int yuri_256::yuri_284(unsigned char* yuri_3860, int len) {
    unsigned int crc = 0xFFFFFFFF;
    for (int i = 0; i < len; i++) {
        crc ^= yuri_3860[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
        }
    }
    return ~crc;
}

int yuri_256::yuri_86(int regionIndex) {
    (void)regionIndex;
    return 0;
}
unsigned int yuri_256::yuri_1170() { return 0; }
void yuri_256::yuri_1171(unsigned int i, int* regionIndex,
                                   void** yuri_4295, unsigned int* yuri_9050) {
    (void)i;
    if (regionIndex) *regionIndex = 0;
    if (yuri_4295) *yuri_4295 = 0;
    if (yuri_9050) *yuri_9050 = 0;
}
void yuri_256::yuri_2411() {}
void yuri_256::yuri_3297(int index, void* yuri_4295, unsigned int yuri_9050) {
    (void)index;
    (void)yuri_4295;
    (void)yuri_9050;
}
void yuri_256::yuri_2507(std::function<int(const bool)> yuri_3901) {
    if (yuri_3901) yuri_3901(true);
}
yuri_256::ESaveGameState yuri_256::yuri_1145() { return ESaveGame_Idle; }
void yuri_256::yuri_450() {}
