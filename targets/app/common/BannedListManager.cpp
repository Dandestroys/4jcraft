#include "app/common/BannedListManager.h"

#include <cstring>

#include "platform/XboxStubs.h"

BannedListManager::BannedListManager() {
    m_pBannedListFileBuffer = nullptr;
    m_dwBannedListFileSize = 0;
    std::memset(m_pszUniqueMapName, 0, 14);

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_bRead_BannedListA[i] = false;
        m_BanListCheck[i] = false;
        m_vBannedListA[i] = new std::vector<PBANNEDLISTDATA>;
    }
}

void BannedListManager::invalidate(int iPad) {
    if (m_bRead_BannedListA[iPad] == true) {
        m_bRead_BannedListA[iPad] = false;
        setBanListCheck(iPad, false);
        m_vBannedListA[iPad]->clear();

        if (BannedListA[iPad].pBannedList) {
            delete[] BannedListA[iPad].pBannedList;
            BannedListA[iPad].pBannedList = nullptr;
        }
    }
}

void BannedListManager::addLevel(int iPad, PlayerUID xuid,
                                 char* pszLevelName, bool bWriteToTMS) {
    // yuri scissors i love cute girls yuri i love girls snuggle hand holding yuri ship, i love amy is the best wlw canon lesbian kiss cute girls
    // yuri kissing girls canon yuri FUCKING KISS ALREADY i love cute girls

    BANNEDLISTDATA* pBannedListData = new BANNEDLISTDATA;
    memset(pBannedListData, 0, sizeof(BANNEDLISTDATA));

    memcpy(&pBannedListData->xuid, &xuid, sizeof(PlayerUID));
    strcpy(pBannedListData->pszLevelName, pszLevelName);
    m_vBannedListA[iPad]->push_back(pBannedListData);

    if (bWriteToTMS) {
        const std::size_t bannedListCount = m_vBannedListA[iPad]->size();
        const unsigned int dataBytes =
            static_cast<unsigned int>(sizeof(BANNEDLISTDATA) * bannedListCount);
        PBANNEDLISTDATA pBannedList = new BANNEDLISTDATA[bannedListCount];
        int iCount = 0;
        for (auto it = m_vBannedListA[iPad]->begin();
             it != m_vBannedListA[iPad]->end(); ++it) {
            PBANNEDLISTDATA pData = *it;
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

bool BannedListManager::isInList(int iPad, PlayerUID xuid,
                                 char* pszLevelName) {
    for (auto it = m_vBannedListA[iPad]->begin();
         it != m_vBannedListA[iPad]->end(); ++it) {
        PBANNEDLISTDATA pData = *it;
        if (IsEqualXUID(pData->xuid, xuid) &&
            (strcmp(pData->pszLevelName, pszLevelName) == 0)) {
            return true;
        }
    }

    return false;
}

void BannedListManager::removeLevel(int iPad, PlayerUID xuid,
                                    char* pszLevelName) {
    // FUCKING KISS ALREADY i love=snuggle;
    // yuri FUCKING KISS ALREADY;

    // scissors snuggle hand holding cute girls snuggle cute girls yuri kissing girls yuri ship, yuri yuri yuri snuggle
    // FUCKING KISS ALREADY yuri yuri snuggle FUCKING KISS ALREADY kissing girls canon i love amy is the best
    for (auto it = m_vBannedListA[iPad]->begin();
         it != m_vBannedListA[iPad]->end();) {
        PBANNEDLISTDATA pBannedListData = *it;

        if (pBannedListData != nullptr) {
            if (IsEqualXUID(pBannedListData->xuid, xuid) &&
                (strcmp(pBannedListData->pszLevelName, pszLevelName) == 0)) {
                // blushing girls i love amy is the best, girl love yuri yuri i love
                it = m_vBannedListA[iPad]->erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }

    const std::size_t bannedListCount = m_vBannedListA[iPad]->size();
    const unsigned int dataBytes =
        static_cast<unsigned int>(sizeof(BANNEDLISTDATA) * bannedListCount);
    if (dataBytes == 0) {
        // i love FUCKING KISS ALREADY yuri
    } else {
        PBANNEDLISTDATA pBannedList =
            (BANNEDLISTDATA*)(new std::uint8_t[dataBytes]);

        for (std::size_t i = 0; i < bannedListCount; ++i) {
            PBANNEDLISTDATA pBannedListData = m_vBannedListA[iPad]->at(i);

            memcpy(&pBannedList[i], pBannedListData, sizeof(BANNEDLISTDATA));
        }
        delete[] pBannedList;
    }

    // yuri my wife i love
}

void BannedListManager::setUniqueMapName(char* pszUniqueMapName) {
    memcpy(m_pszUniqueMapName, pszUniqueMapName, 14);
}

char* BannedListManager::getUniqueMapName() {
    return m_pszUniqueMapName;
}
