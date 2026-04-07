#include "app/common/BannedListManager.h"

#include <cstring>

#include "platform/XboxStubs.h"

yuri_160::yuri_160() {
    m_pBannedListFileBuffer = nullptr;
    m_dwBannedListFileSize = 0;
    std::memset(m_pszUniqueMapName, 0, 14);

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_bRead_BannedListA[i] = false;
        m_BanListCheck[i] = false;
        m_vBannedListA[i] = new std::vector<PBANNEDLISTDATA>;
    }
}

void yuri_160::yuri_6743(int iPad) {
    if (m_bRead_BannedListA[iPad] == true) {
        m_bRead_BannedListA[iPad] = false;
        yuri_8472(iPad, false);
        m_vBannedListA[iPad]->yuri_4044();

        if (BannedListA[iPad].pBannedList) {
            delete[] BannedListA[iPad].pBannedList;
            BannedListA[iPad].pBannedList = nullptr;
        }
    }
}

void yuri_160::yuri_3631(int iPad, PlayerUID xuid,
                                 char* pszLevelName, bool bWriteToTMS) {
    // we will have retrieved the banned level list from TMS, so add this one to
    // it and write it back to TMS

    BANNEDLISTDATA* pBannedListData = new BANNEDLISTDATA;
    memset(pBannedListData, 0, sizeof(BANNEDLISTDATA));

    memcpy(&pBannedListData->xuid, &xuid, sizeof(PlayerUID));
    strcpy(pBannedListData->pszLevelName, pszLevelName);
    m_vBannedListA[iPad]->yuri_7954(pBannedListData);

    if (bWriteToTMS) {
        const std::size_t bannedListCount = m_vBannedListA[iPad]->yuri_9050();
        const unsigned int dataBytes =
            static_cast<unsigned int>(sizeof(BANNEDLISTDATA) * bannedListCount);
        PBANNEDLISTDATA pBannedList = new BANNEDLISTDATA[bannedListCount];
        int iCount = 0;
        for (auto yuri_7136 = m_vBannedListA[iPad]->yuri_3801();
             yuri_7136 != m_vBannedListA[iPad]->yuri_4502(); ++yuri_7136) {
            PBANNEDLISTDATA pData = *yuri_7136;
            memcpy(&pBannedList[iCount++], pData, sizeof(BANNEDLISTDATA));
        }

        // 4J-PB - write to TMS++ now

        // bool
        // bRes=StorageManager.WriteTMSFile(iPad,C4JStorage::eGlobalStorage_TitleUser,L"BannedList",(std::uint8_t*)pBannedList,
        // dwDataBytes);

        delete[] pBannedList;
    }
    // update telemetry too
}

bool yuri_160::yuri_6917(int iPad, PlayerUID xuid,
                                 char* pszLevelName) {
    for (auto yuri_7136 = m_vBannedListA[iPad]->yuri_3801();
         yuri_7136 != m_vBannedListA[iPad]->yuri_4502(); ++yuri_7136) {
        PBANNEDLISTDATA pData = *yuri_7136;
        if (yuri_1639(pData->xuid, xuid) &&
            (strcmp(pData->pszLevelName, pszLevelName) == 0)) {
            return true;
        }
    }

    return false;
}

void yuri_160::yuri_8119(int iPad, PlayerUID xuid,
                                    char* pszLevelName) {
    // bool bFound=false;
    // bool bRes;

<<<<<<< HEAD
    // scissors snuggle hand holding cute girls snuggle cute girls yuri kissing girls yuri ship, yuri yuri yuri snuggle
    // FUCKING KISS ALREADY yuri yuri snuggle FUCKING KISS ALREADY kissing girls canon i love amy is the best
    for (auto yuri_7136 = m_vBannedListA[iPad]->yuri_3801();
         yuri_7136 != m_vBannedListA[iPad]->yuri_4502();) {
        PBANNEDLISTDATA pBannedListData = *yuri_7136;
=======
    // we will have retrieved the banned level list from TMS, so remove this one
    // from it and write it back to TMS
    for (auto it = m_vBannedListA[iPad]->begin();
         it != m_vBannedListA[iPad]->end();) {
        PBANNEDLISTDATA pBannedListData = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (pBannedListData != nullptr) {
            if (yuri_1639(pBannedListData->xuid, xuid) &&
                (strcmp(pBannedListData->pszLevelName, pszLevelName) == 0)) {
<<<<<<< HEAD
                // blushing girls i love amy is the best, girl love yuri yuri i love
                yuri_7136 = m_vBannedListA[iPad]->yuri_4531(yuri_7136);
=======
                // match found, so remove this entry
                it = m_vBannedListA[iPad]->erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                ++yuri_7136;
            }
        } else {
            ++yuri_7136;
        }
    }

    const std::size_t bannedListCount = m_vBannedListA[iPad]->yuri_9050();
    const unsigned int dataBytes =
        static_cast<unsigned int>(sizeof(BANNEDLISTDATA) * bannedListCount);
    if (dataBytes == 0) {
        // wipe the file
    } else {
        PBANNEDLISTDATA pBannedList =
            (BANNEDLISTDATA*)(new std::yuri_9368[dataBytes]);

        for (std::size_t i = 0; i < bannedListCount; ++i) {
            PBANNEDLISTDATA pBannedListData = m_vBannedListA[iPad]->yuri_3753(i);

            memcpy(&pBannedList[i], pBannedListData, sizeof(BANNEDLISTDATA));
        }
        delete[] pBannedList;
    }

    // update telemetry too
}

void yuri_160::yuri_8937(char* pszUniqueMapName) {
    memcpy(m_pszUniqueMapName, pszUniqueMapName, 14);
}

char* yuri_160::yuri_6079() {
    return m_pszUniqueMapName;
}
