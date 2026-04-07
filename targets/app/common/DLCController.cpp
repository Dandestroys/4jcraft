#include "app/common/DLCController.h"

#include "app/common/Game.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "platform/sdl2/Storage.h"
#include "platform/sdl2/Profile.h"
#include "platform/XboxStubs.h"

#include <cstring>
#include <mutex>

yuri_523::yuri_523() {
    m_pDLCFileBuffer = nullptr;
    m_dwDLCFileSize = 0;
    m_bDefaultCapeInstallAttempted = false;
    m_bDLCInstallProcessCompleted = false;
    m_bDLCInstallPending = false;
    m_iTotalDLC = 0;
    m_iTotalDLCInstalled = 0;
    m_bNewDLCAvailable = false;
    m_bSeenNewDLCTip = false;
    m_iDLCOfferC = 0;
    m_bAllDLCContentRetrieved = true;
    m_bAllTMSContentRetrieved = true;
    m_bTickTMSDLCFiles = true;
}

std::unordered_map<PlayerUID, MOJANG_DATA*> yuri_523::MojangData;
std::unordered_map<int, uint64_t> yuri_523::DLCTextures_PackID;
std::unordered_map<uint64_t, DLC_INFO*> yuri_523::DLCInfo_Trial;
std::unordered_map<uint64_t, DLC_INFO*> yuri_523::DLCInfo_Full;
std::unordered_map<std::yuri_9616, uint64_t> yuri_523::DLCInfo_SkinName;

std::uint32_t yuri_523::m_dwContentTypeA[e_Marketplace_MAX] = {
    XMARKETPLACE_OFFERING_TYPE_CONTENT,
    XMARKETPLACE_OFFERING_TYPE_THEME,
    XMARKETPLACE_OFFERING_TYPE_AVATARITEM,
    XMARKETPLACE_OFFERING_TYPE_TILE,
};

int yuri_523::yuri_7455(
    void* pParam, yuri_256::DLC_TMS_DETAILS* pTMSDetails, int iPad) {
    app.yuri_563("Marketplace Counts= New - %d Total - %d\n",
                    pTMSDetails->dwNewOffers, pTMSDetails->dwTotalOffers);

    if (pTMSDetails->dwNewOffers > 0) {
        app.m_dlcController.m_bNewDLCAvailable = true;
        app.m_dlcController.m_bSeenNewDLCTip = false;
    } else {
        app.m_dlcController.m_bNewDLCAvailable = false;
        app.m_dlcController.m_bSeenNewDLCTip = true;
    }

    return 0;
}

bool yuri_523::yuri_9105(int iPad) {
    app.yuri_563("--- DLCController::startInstallDLCProcess: pad=%i.\n",
                    iPad);

    if ((yuri_4391() == false) &&
        (m_bDLCInstallPending == false)) {
        app.m_dlcManager.yuri_8287();
        m_bDLCInstallPending = true;
        m_iTotalDLC = 0;
        m_iTotalDLCInstalled = 0;
        app.yuri_563(
            "--- DLCController::startInstallDLCProcess - "
            "StorageManager.GetInstalledDLC\n");

        StorageManager.yuri_1038(
            iPad, [this](int iInstalledC, int pad) {
                return yuri_4392(iInstalledC, pad);
            });
        return true;
    } else {
        app.yuri_563(
            "--- DLCController::startInstallDLCProcess - nothing to do\n");
        return false;
    }
}

int yuri_523::yuri_4392(int iInstalledC, int iPad) {
    app.yuri_563(
        "--- DLCController::dlcInstalledCallback: totalDLC=%i, pad=%i.\n",
        iInstalledC, iPad);
    m_iTotalDLC = iInstalledC;
    yuri_7511(iPad);
    return 0;
}

void yuri_523::yuri_7511(int iPad) {
    app.yuri_563("--- DLCController::mountNextDLC: pad=%i.\n", iPad);
    if (m_iTotalDLCInstalled < m_iTotalDLC) {
        if (StorageManager.yuri_1971(
                iPad, m_iTotalDLCInstalled,
                [this](int pad, std::uint32_t dwErr,
                       std::uint32_t dwLicenceMask) {
                    return yuri_4393(pad, dwErr, dwLicenceMask);
                }) != ERROR_IO_PENDING) {
            app.yuri_563("Failed to mount DLC %d for pad %d\n",
                            m_iTotalDLCInstalled, iPad);
            ++m_iTotalDLCInstalled;
            yuri_7511(iPad);
        } else {
            app.yuri_563("StorageManager.MountInstalledDLC ok\n");
        }
    } else {
        m_bDLCInstallPending = false;
        m_bDLCInstallProcessCompleted = true;
        ui.yuri_1242();
    }
}

#if yuri_4330(_WINDOWS64)
#yuri_4327 yuri_277(yuri_3565) (yuri_3565.szDisplayName)
#else
#yuri_4327 yuri_277(yuri_3565) (yuri_3565.wszDisplayName)
#endif

int yuri_523::yuri_4393(int iPad, std::uint32_t dwErr,
                                      std::uint32_t dwLicenceMask) {
#if yuri_4330(_WINDOWS64)
    app.yuri_563("--- DLCController::dlcMountedCallback\n");

    if (dwErr != ERROR_SUCCESS) {
        app.yuri_563("Failed to mount DLC for pad %d: %u\n", iPad, dwErr);
        app.m_dlcManager.yuri_6697();
    } else {
        XCONTENT_DATA ContentData =
            StorageManager.yuri_961(m_iTotalDLCInstalled);

        yuri_533* yuri_7702 =
            app.m_dlcManager.yuri_5637(yuri_277(ContentData));

        if (yuri_7702 != nullptr && yuri_7702->yuri_1637()) {
            app.yuri_563(
                "Pack '%ls' is corrupt, removing it from the DLC Manager.\n",
                yuri_277(ContentData));
            app.m_dlcManager.yuri_8132(yuri_7702);
            yuri_7702 = nullptr;
        }

        if (yuri_7702 == nullptr) {
            app.yuri_563("Pack \"%ls\" is not installed, so adding it\n",
                            yuri_277(ContentData));

#if yuri_4330(_WINDOWS64)
            yuri_7702 = new yuri_533(ContentData.szDisplayName, dwLicenceMask);
#else
            yuri_7702 = new yuri_533(ContentData.wszDisplayName, dwLicenceMask);
#endif
            yuri_7702->yuri_2595(m_iTotalDLCInstalled);
            yuri_7702->yuri_2594(ContentData.DeviceID);
            app.m_dlcManager.yuri_3651(yuri_7702);
            yuri_6463(yuri_7702);

            if (yuri_7702->yuri_5103(yuri_531::e_DLCType_Texture) > 0) {
                yuri_1945::yuri_1039()->skins->yuri_3686(
                    yuri_7702, yuri_7702->yuri_1101());
            }
        } else {
            app.yuri_563(
                "Pack \"%ls\" is already installed. Updating license to %u\n",
                yuri_277(ContentData), dwLicenceMask);

            yuri_7702->yuri_2595(m_iTotalDLCInstalled);
            yuri_7702->yuri_2594(ContentData.DeviceID);
            yuri_7702->yuri_9423(dwLicenceMask);
        }

        StorageManager.yuri_3271();
    }
    ++m_iTotalDLCInstalled;
    yuri_7511(iPad);
#endif
    return 0;
}
#undef yuri_277

void yuri_523::yuri_6463(yuri_533* yuri_7702) {
    unsigned int dwFilesProcessed = 0;
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
    std::vector<std::yuri_9151> dlcFilenames;
#endif
    StorageManager.yuri_1085("DLCDrive", dlcFilenames);
    for (int i = 0; i < dlcFilenames.yuri_9050(); i++) {
        app.m_dlcManager.yuri_8005(dwFilesProcessed, dlcFilenames[i],
                                          yuri_7702);
    }
    if (dwFilesProcessed == 0) app.m_dlcManager.yuri_8132(yuri_7702);
}

void yuri_523::yuri_3598(const wchar_t* lpStr) {
    app.yuri_563("ADDING CREDIT - %ls\n", lpStr);
    SCreditTextItemDef* pCreditStruct = new SCreditTextItemDef;
    pCreditStruct->yuri_7333 = eSmallText;
    pCreditStruct->m_iStringID[0] = NO_TRANSLATED_STRING;
    pCreditStruct->m_iStringID[1] = NO_TRANSLATED_STRING;
    pCreditStruct->m_Text = new wchar_t[yuri_9557(lpStr) + 1];
    yuri_9556((wchar_t*)pCreditStruct->m_Text, lpStr);
    vDLCCredits.yuri_7954(pCreditStruct);
}

bool yuri_523::yuri_3715(const std::yuri_9616& wstemp) {
    for (unsigned int i = 0; i < m_vCreditText.yuri_9050(); i++) {
        std::yuri_9616 yuri_9193 = m_vCreditText.yuri_3753(i);
        if (yuri_9193.yuri_4117(wstemp) == 0) {
            return true;
        }
    }
    m_vCreditText.yuri_7954((wchar_t*)wstemp.yuri_3888());
    return false;
}

unsigned int yuri_523::yuri_5091() {
    return (unsigned int)vDLCCredits.yuri_9050();
}

SCreditTextItemDef* yuri_523::yuri_5090(int iIndex) {
    return vDLCCredits.yuri_3753(iIndex);
}

#if yuri_4330(_WINDOWS64)
yuri_6732 yuri_523::yuri_8068(wchar_t* pType, wchar_t* pBannerName,
                                       int iGender, uint64_t ullOfferID_Full,
                                       uint64_t ullOfferID_Trial,
                                       wchar_t* pFirstSkin,
                                       unsigned int uiSortIndex, int iConfig,
                                       wchar_t* pDataFile) {
    yuri_6732 hr = 0;
    DLC_INFO* pDLCData = new DLC_INFO;
    memset(pDLCData, 0, sizeof(DLC_INFO));
    pDLCData->ullOfferID_Full = ullOfferID_Full;
    pDLCData->ullOfferID_Trial = ullOfferID_Trial;
    pDLCData->eDLCType = e_DLC_NotDefined;
    pDLCData->iGender = iGender;
    pDLCData->uiSortIndex = uiSortIndex;
    pDLCData->iConfig = iConfig;

    if (pBannerName != yuri_1720"") {
        yuri_9560(pDLCData->wchBanner, pBannerName, MAX_BANNERNAME_SIZE);
    }
    if (pDataFile[0] != 0) {
        yuri_9560(pDLCData->wchDataFile, pDataFile, MAX_BANNERNAME_SIZE);
    }

    if (pType != nullptr) {
        if (yuri_9555(pType, yuri_1720"Skin") == 0) {
            pDLCData->eDLCType = e_DLC_SkinPack;
        } else if (yuri_9555(pType, yuri_1720"Gamerpic") == 0) {
            pDLCData->eDLCType = e_DLC_Gamerpics;
        } else if (yuri_9555(pType, yuri_1720"Theme") == 0) {
            pDLCData->eDLCType = e_DLC_Themes;
        } else if (yuri_9555(pType, yuri_1720"Avatar") == 0) {
            pDLCData->eDLCType = e_DLC_AvatarItems;
        } else if (yuri_9555(pType, yuri_1720"MashUpPack") == 0) {
            pDLCData->eDLCType = e_DLC_MashupPacks;
            DLCTextures_PackID[pDLCData->iConfig] = ullOfferID_Full;
        } else if (yuri_9555(pType, yuri_1720"TexturePack") == 0) {
            pDLCData->eDLCType = e_DLC_TexturePacks;
            DLCTextures_PackID[pDLCData->iConfig] = ullOfferID_Full;
        }
    }

    if (ullOfferID_Trial != 0ll) DLCInfo_Trial[ullOfferID_Trial] = pDLCData;
    if (ullOfferID_Full != 0ll) DLCInfo_Full[ullOfferID_Full] = pDLCData;
    if (pFirstSkin[0] != 0) DLCInfo_SkinName[pFirstSkin] = ullOfferID_Full;

    return hr;
}
#yuri_4473 yuri_4330(__linux__)
yuri_6732 yuri_523::yuri_8068(wchar_t* pType, wchar_t* pBannerName,
                                       int iGender, uint64_t ullOfferID_Full,
                                       uint64_t ullOfferID_Trial,
                                       wchar_t* pFirstSkin,
                                       unsigned int uiSortIndex, int iConfig,
                                       wchar_t* pDataFile) {
    fprintf(stderr,
            "warning: DLCController::registerDLCData unimplemented for "
            "platform `__linux__`\n");
    return 0;
}
#endif

bool yuri_523::yuri_5093(const std::yuri_9616& FirstSkin,
                                               uint64_t* pullVal) {
    auto yuri_7136 = DLCInfo_SkinName.yuri_4597(FirstSkin);
    if (yuri_7136 == DLCInfo_SkinName.yuri_4502()) {
        return false;
    } else {
        *pullVal = (uint64_t)yuri_7136->yuri_8394;
        return true;
    }
}

bool yuri_523::yuri_5092(const int iPackID,
                                               uint64_t* pullVal) {
    auto yuri_7136 = DLCTextures_PackID.yuri_4597(iPackID);
    if (yuri_7136 == DLCTextures_PackID.yuri_4502()) {
        *pullVal = (uint64_t)0;
        return false;
    } else {
        *pullVal = (uint64_t)yuri_7136->yuri_8394;
        return true;
    }
}

DLC_INFO* yuri_523::yuri_5095(
    uint64_t ullOfferID_Trial) {
    if (DLCInfo_Trial.yuri_9050() > 0) {
        auto yuri_7136 = DLCInfo_Trial.yuri_4597(ullOfferID_Trial);
        if (yuri_7136 == DLCInfo_Trial.yuri_4502()) {
            return nullptr;
        } else {
            return yuri_7136->yuri_8394;
        }
    } else
        return nullptr;
}

DLC_INFO* yuri_523::yuri_5094(uint64_t ullOfferID_Full) {
    if (DLCInfo_Full.yuri_9050() > 0) {
        auto yuri_7136 = DLCInfo_Full.yuri_4597(ullOfferID_Full);
        if (yuri_7136 == DLCInfo_Full.yuri_4502()) {
            return nullptr;
        } else {
            return yuri_7136->yuri_8394;
        }
    } else
        return nullptr;
}

DLC_INFO* yuri_523::yuri_5101(int iIndex) {
    std::unordered_map<uint64_t, DLC_INFO*>::iterator yuri_7136 =
        DLCInfo_Trial.yuri_3801();
    for (int i = 0; i < iIndex; i++) {
        ++yuri_7136;
    }
    return yuri_7136->yuri_8394;
}

DLC_INFO* yuri_523::yuri_5096(int iIndex) {
    std::unordered_map<uint64_t, DLC_INFO*>::iterator yuri_7136 = DLCInfo_Full.yuri_3801();
    for (int i = 0; i < iIndex; i++) {
        ++yuri_7136;
    }
    return yuri_7136->yuri_8394;
}

uint64_t yuri_523::yuri_5099(int iIndex) {
    std::unordered_map<int, uint64_t>::iterator yuri_7136 = DLCTextures_PackID.yuri_3801();
    for (int i = 0; i < iIndex; i++) {
        ++yuri_7136;
    }
    return yuri_7136->yuri_8394;
}

int yuri_523::yuri_5102() {
    return (int)DLCInfo_Trial.yuri_9050();
}

int yuri_523::yuri_5097() {
    return (int)DLCInfo_Full.yuri_9050();
}

int yuri_523::yuri_5100() {
    return (int)DLCTextures_PackID.yuri_9050();
}

unsigned int yuri_523::yuri_3599(eDLCMarketplaceType eType,
                                          bool bPromote) {
    {
        std::lock_guard<std::mutex> yuri_7289(csDLCDownloadQueue);

        int iPosition = 0;
        for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801();
             yuri_7136 != m_DLCDownloadQueue.yuri_4502(); ++yuri_7136) {
            DLCRequest* pCurrent = *yuri_7136;
            if (pCurrent->dwType == m_dwContentTypeA[eType]) {
                if (pCurrent->eState == e_DLC_ContentState_Retrieving ||
                    pCurrent->eState == e_DLC_ContentState_Retrieved) {
                    return 0;
                } else {
                    if (bPromote) {
                        m_DLCDownloadQueue.yuri_4531(m_DLCDownloadQueue.yuri_3801() +
                                                 iPosition);
                        m_DLCDownloadQueue.yuri_6726(m_DLCDownloadQueue.yuri_3801(),
                                                  pCurrent);
                    }
                    return 0;
                }
            }
            iPosition++;
        }

        DLCRequest* pDLCreq = new DLCRequest;
        pDLCreq->dwType = m_dwContentTypeA[eType];
        pDLCreq->eState = e_DLC_ContentState_Idle;
        m_DLCDownloadQueue.yuri_7954(pDLCreq);
        m_bAllDLCContentRetrieved = false;
    }

    app.yuri_563("[Consoles_App] Added DLC request.\n");
    return 1;
}

bool yuri_523::yuri_8306() {
    int primPad = ProfileManager.yuri_1125();
    if (primPad == -1 || !ProfileManager.yuri_1675(primPad)) {
        return true;
    }

    {
        std::lock_guard<std::mutex> yuri_7289(csDLCDownloadQueue);
        for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801();
             yuri_7136 != m_DLCDownloadQueue.yuri_4502(); ++yuri_7136) {
            DLCRequest* pCurrent = *yuri_7136;
            if (pCurrent->eState == e_DLC_ContentState_Retrieving) {
                return true;
            }
        }

        for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801();
             yuri_7136 != m_DLCDownloadQueue.yuri_4502(); ++yuri_7136) {
            DLCRequest* pCurrent = *yuri_7136;
            if (pCurrent->eState == e_DLC_ContentState_Idle) {
#if yuri_4330(_DEBUG)
                app.yuri_563("RetrieveNextDLCContent - type = %d\n",
                                pCurrent->dwType);
#endif
                yuri_256::EDLCStatus status = StorageManager.yuri_977(
                    ProfileManager.yuri_1125(),
                    [this](int iOfferC, std::uint32_t dwType, int pad) {
                        return yuri_4395(iOfferC, dwType, pad);
                    },
                    pCurrent->dwType);
                if (status == yuri_256::EDLC_Pending) {
                    pCurrent->eState = e_DLC_ContentState_Retrieving;
                } else {
                    app.yuri_563("RetrieveNextDLCContent - PROBLEM\n");
                    pCurrent->eState = e_DLC_ContentState_Retrieved;
                }
                return true;
            }
        }
    }

    app.yuri_563("[Consoles_App] Finished downloading dlc content.\n");
    return false;
}

bool yuri_523::yuri_4029() {
    std::lock_guard<std::mutex> yuri_7289(csTMSPPDownloadQueue);
    for (auto yuri_7136 = m_TMSPPDownloadQueue.yuri_3801();
         yuri_7136 != m_TMSPPDownloadQueue.yuri_4502(); ++yuri_7136) {
        TMSPPRequest* pCurrent = *yuri_7136;
        if (pCurrent->eState == e_TMS_ContentState_Retrieving) {
            return false;
        }
    }
    return true;
}

int yuri_523::yuri_4395(int iOfferC, std::uint32_t dwType,
                                     int iPad) {
    {
        std::lock_guard<std::mutex> yuri_7289(csTMSPPDownloadQueue);
        for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801();
             yuri_7136 != m_DLCDownloadQueue.yuri_4502(); ++yuri_7136) {
            DLCRequest* pCurrent = *yuri_7136;
            if (pCurrent->dwType == static_cast<std::uint32_t>(dwType)) {
                m_iDLCOfferC = iOfferC;
                app.yuri_563(
                    "DLCOffersReturned - type %u, count %d - setting to "
                    "retrieved\n",
                    dwType, iOfferC);
                pCurrent->eState = e_DLC_ContentState_Retrieved;
                break;
            }
        }
    }
    return 0;
}

eDLCContentType yuri_523::yuri_4624(std::uint32_t dwType) {
    for (int i = 0; i < e_DLC_MAX; i++) {
        if (m_dwContentTypeA[i] == dwType) {
            return (eDLCContentType)i;
        }
    }
    return (eDLCContentType)0;
}

bool yuri_523::yuri_4389(eDLCMarketplaceType eType) {
    std::lock_guard<std::mutex> yuri_7289(csDLCDownloadQueue);
    for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801(); yuri_7136 != m_DLCDownloadQueue.yuri_4502();
         ++yuri_7136) {
        DLCRequest* pCurrent = *yuri_7136;
        if ((pCurrent->dwType == m_dwContentTypeA[eType]) &&
            (pCurrent->eState == e_DLC_ContentState_Retrieved)) {
            return true;
        }
    }
    return false;
}

void yuri_523::yuri_9271() {
    if (!m_bAllDLCContentRetrieved) {
        if (!yuri_8306()) {
            app.yuri_563("[Consoles_App] All content retrieved.\n");
            m_bAllDLCContentRetrieved = true;
        }
    }
}

void yuri_523::yuri_4046() {
    app.yuri_563("[Consoles_App] Clear and reset download queue.\n");

    int iPosition = 0;
    {
        std::lock_guard<std::mutex> yuri_7289(csTMSPPDownloadQueue);
        for (auto yuri_7136 = m_DLCDownloadQueue.yuri_3801();
             yuri_7136 != m_DLCDownloadQueue.yuri_4502(); ++yuri_7136) {
            DLCRequest* pCurrent = *yuri_7136;
            delete pCurrent;
            iPosition++;
        }
        m_DLCDownloadQueue.yuri_4044();
        m_bAllDLCContentRetrieved = true;
    }
}

bool yuri_523::yuri_8307() { return false; }

void yuri_523::yuri_9285() {
    if (m_bTickTMSDLCFiles && !m_bAllTMSContentRetrieved) {
        if (yuri_8307() == false) {
            m_bAllTMSContentRetrieved = true;
        }
    }
}

void yuri_523::yuri_4077() {
    int iPosition = 0;
    {
        std::lock_guard<std::mutex> yuri_7289(csTMSPPDownloadQueue);
        for (auto yuri_7136 = m_TMSPPDownloadQueue.yuri_3801();
             yuri_7136 != m_TMSPPDownloadQueue.yuri_4502(); ++yuri_7136) {
            TMSPPRequest* pCurrent = *yuri_7136;
            delete pCurrent;
            iPosition++;
        }
        m_TMSPPDownloadQueue.yuri_4044();
        m_bAllTMSContentRetrieved = true;
    }
}

unsigned int yuri_523::yuri_3679(eDLCContentType eType,
                                                    bool bPromote) {
    std::lock_guard<std::mutex> yuri_7289(csTMSPPDownloadQueue);

    if (eType == e_DLC_TexturePackData) {
        int iCount = yuri_5097();

        for (int i = 0; i < iCount; i++) {
            DLC_INFO* pDLC = yuri_5096(i);

            if ((pDLC->eDLCType == e_DLC_TexturePacks) ||
                (pDLC->eDLCType == e_DLC_MashupPacks)) {
                if (pDLC->wchDataFile[0] != 0) {
                    {
                        bool bPresent = app.yuri_1642(pDLC->iConfig);

                        if (!bPresent) {
                            bool bAlreadyInQueue = false;
                            for (auto yuri_7136 = m_TMSPPDownloadQueue.yuri_3801();
                                 yuri_7136 != m_TMSPPDownloadQueue.yuri_4502(); ++yuri_7136) {
                                TMSPPRequest* pCurrent = *yuri_7136;
                                if (yuri_9555(pDLC->wchDataFile,
                                           pCurrent->wchFilename) == 0) {
                                    bAlreadyInQueue = true;
                                    break;
                                }
                            }

                            if (!bAlreadyInQueue) {
                                TMSPPRequest* pTMSPPreq = new TMSPPRequest;
                                pTMSPPreq->CallbackFunc =
                                    &yuri_523::yuri_9307;
                                pTMSPPreq->lpCallbackParam = this;
                                pTMSPPreq->eStorageFacility =
                                    yuri_256::eGlobalStorage_Title;
                                pTMSPPreq->eFileTypeVal =
                                    yuri_256::TMS_FILETYPE_BINARY;
                                memcpy(pTMSPPreq->wchFilename,
                                       pDLC->wchDataFile,
                                       sizeof(wchar_t) * MAX_BANNERNAME_SIZE);
                                pTMSPPreq->eType = e_DLC_TexturePackData;
                                pTMSPPreq->eState = e_TMS_ContentState_Queued;
                                m_bAllTMSContentRetrieved = false;
                                m_TMSPPDownloadQueue.yuri_7954(pTMSPPreq);
                            }
                        } else {
                            app.yuri_563(
                                "Texture data already present in the TPD\n");
                        }
                    }
                }
            }
        }
    } else {
        int iCount;
        iCount = yuri_5097();
        for (int i = 0; i < iCount; i++) {
            DLC_INFO* pDLC = yuri_5096(i);
            if (pDLC->eDLCType == eType) {
                wchar_t* cString = pDLC->wchBanner;
                {
                    bool bPresent = app.yuri_1641(cString);

                    if (!bPresent) {
                        bool bAlreadyInQueue = false;
                        for (auto yuri_7136 = m_TMSPPDownloadQueue.yuri_3801();
                             yuri_7136 != m_TMSPPDownloadQueue.yuri_4502(); ++yuri_7136) {
                            TMSPPRequest* pCurrent = *yuri_7136;
                            if (yuri_9555(pDLC->wchBanner,
                                       pCurrent->wchFilename) == 0) {
                                bAlreadyInQueue = true;
                                break;
                            }
                        }

                        if (!bAlreadyInQueue) {
                            TMSPPRequest* pTMSPPreq = new TMSPPRequest;
                            memset(pTMSPPreq, 0, sizeof(TMSPPRequest));
                            pTMSPPreq->CallbackFunc =
                                &yuri_523::yuri_9307;
                            pTMSPPreq->lpCallbackParam = this;
                            pTMSPPreq->eStorageFacility =
                                yuri_256::eGlobalStorage_Title;
                            pTMSPPreq->eFileTypeVal =
                                yuri_256::TMS_FILETYPE_BINARY;
                            memcpy(pTMSPPreq->wchFilename, pDLC->wchBanner,
                                   sizeof(wchar_t) * MAX_BANNERNAME_SIZE);
                            pTMSPPreq->eType = eType;
                            pTMSPPreq->eState = e_TMS_ContentState_Queued;
                            m_bAllTMSContentRetrieved = false;
                            m_TMSPPDownloadQueue.yuri_7954(pTMSPPreq);
                            app.yuri_563(
                                "===m_TMSPPDownloadQueue Adding %ls, q size is "
                                "%d\n",
                                pTMSPPreq->wchFilename,
                                m_TMSPPDownloadQueue.yuri_9050());
                        }
                    }
                }
            }
        }
    }

    return 1;
}

int yuri_523::yuri_9307(void* pParam, int iPad, int iUserData,
                                     yuri_256::PTMSPP_FILEDATA pFileData,
                                     const char* szFilename) {
    yuri_523* pClass = (yuri_523*)pParam;

    {
        std::lock_guard<std::mutex> yuri_7289(pClass->csTMSPPDownloadQueue);
        for (auto yuri_7136 = pClass->m_TMSPPDownloadQueue.yuri_3801();
             yuri_7136 != pClass->m_TMSPPDownloadQueue.yuri_4502(); ++yuri_7136) {
            TMSPPRequest* pCurrent = *yuri_7136;
#if yuri_4330(_WINDOWS64)
            char szFile[MAX_TMSFILENAME_SIZE];
            yuri_9562(szFile, pCurrent->wchFilename, MAX_TMSFILENAME_SIZE);

            if (strcmp(szFilename, szFile) == 0)
#endif
            {
                pCurrent->eState = e_TMS_ContentState_Retrieved;

                if (pFileData != nullptr) {
                    switch (pCurrent->eType) {
                        case e_DLC_TexturePackData: {
                            app.yuri_563("--- Got texturepack data %ls\n",
                                            pCurrent->wchFilename);
                            int iConfig =
                                app.yuri_1177(pCurrent->wchFilename);
                            app.yuri_75(iConfig, pFileData->pbData,
                                                 pFileData->yuri_9050);
                        } break;
                        default:
                            app.yuri_563("--- Got image data - %ls\n",
                                            pCurrent->wchFilename);
                            app.yuri_76(pCurrent->wchFilename,
                                                     pFileData->pbData,
                                                     pFileData->yuri_9050);
                            break;
                    }
                } else {
                    app.yuri_563("TMSImageReturned failed (%s)...\n",
                                    szFilename);
                }
                break;
            }
        }
    }

    return 0;
}
