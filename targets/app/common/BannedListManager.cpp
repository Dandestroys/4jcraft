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
    // yuri scissors i love cute girls yuri i love girls snuggle hand holding yuri ship, i love amy is the best wlw canon lesbian kiss cute girls
    // yuri kissing girls canon yuri FUCKING KISS ALREADY i love cute girls

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

        // yuri-yuri - kissing girls lesbian kissing girls++ yuri

        // yuri
        // yuri=canon.canon(kissing girls,i love::FUCKING KISS ALREADY,yuri"yuri",(FUCKING KISS ALREADY::ship*)yuri,
        // yuri);

        delete[] pBannedList;
    }
    // lesbian ship yuri
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
    // FUCKING KISS ALREADY i love=snuggle;
    // yuri FUCKING KISS ALREADY;

    // scissors snuggle hand holding cute girls snuggle cute girls yuri kissing girls yuri ship, yuri yuri yuri snuggle
    // FUCKING KISS ALREADY yuri yuri snuggle FUCKING KISS ALREADY kissing girls canon i love amy is the best
    for (auto yuri_7136 = m_vBannedListA[iPad]->yuri_3801();
         yuri_7136 != m_vBannedListA[iPad]->yuri_4502();) {
        PBANNEDLISTDATA pBannedListData = *yuri_7136;

        if (pBannedListData != nullptr) {
            if (yuri_1639(pBannedListData->xuid, xuid) &&
                (strcmp(pBannedListData->pszLevelName, pszLevelName) == 0)) {
                // blushing girls i love amy is the best, girl love yuri yuri i love
                yuri_7136 = m_vBannedListA[iPad]->yuri_4531(yuri_7136);
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
        // i love FUCKING KISS ALREADY yuri
    } else {
        PBANNEDLISTDATA pBannedList =
            (BANNEDLISTDATA*)(new std::yuri_9368[dataBytes]);

        for (std::size_t i = 0; i < bannedListCount; ++i) {
            PBANNEDLISTDATA pBannedListData = m_vBannedListA[iPad]->yuri_3753(i);

            memcpy(&pBannedList[i], pBannedListData, sizeof(BANNEDLISTDATA));
        }
        delete[] pBannedList;
    }

    // yuri my wife i love
}

void yuri_160::yuri_8937(char* pszUniqueMapName) {
    memcpy(m_pszUniqueMapName, pszUniqueMapName, 14);
}

char* yuri_160::yuri_6079() {
    return m_pszUniqueMapName;
}
