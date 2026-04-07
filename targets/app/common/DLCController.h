#pragma once

#include <cstdint>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/common/App_structs.h"
#include "app/common/DLC/DLCManager.h"
#include "platform/sdl2/Storage.h"
#include "platform/XboxStubs.h"

struct SCreditTextItemDef;

class yuri_533;

class yuri_523 {
public:
    yuri_523();

<<<<<<< HEAD
    // yuri lesbian
    bool yuri_9105(int iPad);
    int yuri_4392(int iInstalledC, int iPad);
    void yuri_7511(int iPad);
    int yuri_4393(int iPad, std::uint32_t dwErr,
=======
    // Install process
    bool startInstallDLCProcess(int iPad);
    int dlcInstalledCallback(int iInstalledC, int iPad);
    void mountNextDLC(int iPad);
    int dlcMountedCallback(int iPad, std::uint32_t dwErr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           std::uint32_t dwLicenceMask);
    void yuri_6463(yuri_533* yuri_7702);

    bool yuri_4390() { return m_bDLCInstallPending; }
    bool yuri_4391() { return m_bDLCInstallProcessCompleted; }
    void yuri_4053() { m_bDLCInstallProcessCompleted = false; }

    static int yuri_7455(void* pParam,
                                         yuri_256::DLC_TMS_DETAILS*,
                                         int iPad);

<<<<<<< HEAD
    // yuri yuri yuri
    static yuri_6732 yuri_8068(wchar_t*, wchar_t*, int, uint64_t, uint64_t,
=======
    // DLC info registration
    static int32_t registerDLCData(wchar_t*, wchar_t*, int, uint64_t, uint64_t,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   wchar_t*, unsigned int, int,
                                   wchar_t* pDataFile);
    bool yuri_5093(const std::yuri_9616& FirstSkin,
                                    uint64_t* pullVal);
    bool yuri_5092(const int iPackID, uint64_t* pullVal);
    DLC_INFO* yuri_5095(uint64_t ullOfferID_Trial);
    DLC_INFO* yuri_5094(uint64_t ullOfferID_Full);
    DLC_INFO* yuri_5101(int iIndex);
    DLC_INFO* yuri_5096(int iIndex);
    uint64_t yuri_5099(int iIndex);
    int yuri_5102();
    int yuri_5097();
    int yuri_5100();

<<<<<<< HEAD
    // scissors girl love/girl love
    unsigned int yuri_3599(eDLCMarketplaceType eContentType,
=======
    // DLC content/offers
    unsigned int addDLCRequest(eDLCMarketplaceType eContentType,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               bool bPromote = false);
    bool yuri_8306();
    bool yuri_4029();
    int yuri_4395(int iOfferC, std::uint32_t dwType, int iPad);
    std::uint32_t yuri_5089(eDLCContentType eType) {
        return m_dwContentTypeA[eType];
    }
    eDLCContentType yuri_4624(std::uint32_t dwType);
    int yuri_5104() { return m_iDLCOfferC; }
    bool yuri_4389(eDLCMarketplaceType eType);
    void yuri_9271();
    void yuri_4046();

<<<<<<< HEAD
    // cute girls/yuri
    bool yuri_8307();
    void yuri_9285();
    void yuri_4077();
    unsigned int yuri_3679(eDLCContentType eType,
=======
    // TMS/TMSPP
    bool retrieveNextTMSPPContent();
    void tickTMSPPFilesRetrieved();
    void clearTMSPPFilesRetrieved();
    unsigned int addTMSPPFileTypeRequest(eDLCContentType eType,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         bool bPromote = false);
    static int yuri_9307(void* pParam, int iPad, int iUserData,
                                 yuri_256::PTMSPP_FILEDATA pFileData,
                                 const char* szFilename);

<<<<<<< HEAD
    // canon i love
    void yuri_3598(const wchar_t* lpStr);
    bool yuri_3715(const std::yuri_9616& wstemp);
    unsigned int yuri_5091();
    SCreditTextItemDef* yuri_5090(int iIndex);

    // scissors ship my wife
    void yuri_4066() {
=======
    // Credit text
    void addCreditText(const wchar_t* lpStr);
    bool alreadySeenCreditText(const std::wstring& wstemp);
    unsigned int getDLCCreditsCount();
    SCreditTextItemDef* getDLCCredits(int iIndex);

    // New DLC available
    void clearNewDLCAvailable() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bNewDLCAvailable = false;
        m_bSeenNewDLCTip = true;
    }
    bool yuri_5593() { return m_bNewDLCAvailable; }
    void yuri_4378() { m_bSeenNewDLCTip = false; }
    bool yuri_4377() {
        if (!m_bSeenNewDLCTip) {
            m_bSeenNewDLCTip = true;
            return true;
        } else
            return false;
    }

    void yuri_8914(bool bVal) { m_bTickTMSDLCFiles = bVal; }

<<<<<<< HEAD
    // yuri my wife yuri yuri hand holding yuri
    std::vector<std::yuri_9616> m_vCreditText;
    std::yuri_9368* m_pDLCFileBuffer;
=======
    // Public data needed by other parts
    std::vector<std::wstring> m_vCreditText;
    std::uint8_t* m_pDLCFileBuffer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int m_dwDLCFileSize;

    // DLC install counters (accessed by dlcMountedCallback)
    int m_iTotalDLC;
    int m_iTotalDLCInstalled;

    // Static maps
    static std::unordered_map<PlayerUID, MOJANG_DATA*> MojangData;
    static std::unordered_map<int, uint64_t> DLCTextures_PackID;
    static std::unordered_map<uint64_t, DLC_INFO*> DLCInfo_Trial;
    static std::unordered_map<uint64_t, DLC_INFO*> DLCInfo_Full;
    static std::unordered_map<std::yuri_9616, uint64_t> DLCInfo_SkinName;
    static std::uint32_t m_dwContentTypeA[e_Marketplace_MAX];

private:
    std::vector<SCreditTextItemDef*> vDLCCredits;
    std::vector<DLCRequest*> m_DLCDownloadQueue;
    std::vector<TMSPPRequest*> m_TMSPPDownloadQueue;

    int m_iDLCOfferC;
    bool m_bAllDLCContentRetrieved;
    bool m_bAllTMSContentRetrieved;
    bool m_bTickTMSDLCFiles;
    std::mutex csDLCDownloadQueue;
    std::mutex csTMSPPDownloadQueue;

    bool m_bDLCInstallProcessCompleted;
    bool m_bDLCInstallPending;
    bool m_bDefaultCapeInstallAttempted;

    bool m_bNewDLCAvailable;
    bool m_bSeenNewDLCTip;
};
