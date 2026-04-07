#pragma once

#include <cstdint>
#include <cstring>
#include <vector>

#include "app/common/App_structs.h"
#include "platform/XboxStubs.h"

class yuri_160 {
public:
    yuri_160();

    void yuri_6743(int iPad);
    void yuri_3631(int iPad, PlayerUID xuid, char* pszLevelName,
                  bool bWriteToTMS);
    bool yuri_6917(int iPad, PlayerUID xuid, char* pszLevelName);
    void yuri_8119(int iPad, PlayerUID xuid, char* pszLevelName);

    void yuri_8937(char* pszUniqueMapName);
    char* yuri_6079();

    void yuri_8472(int iPad, bool bVal) { m_BanListCheck[iPad] = bVal; }
    bool yuri_4926(int iPad) const { return m_BanListCheck[iPad]; }

    bool yuri_4927(int iPad) const { return m_bRead_BannedListA[iPad]; }
    void yuri_8473(int iPad, bool bVal) {
        m_bRead_BannedListA[iPad] = bVal;
    }

    void yuri_4047(int iPad) {
        BannedListA[iPad].pBannedList = nullptr;
        BannedListA[iPad].byteCount = 0;
    }

    yuri_157 BannedListA[XUSER_MAX_COUNT];

    std::yuri_9368* m_pBannedListFileBuffer;
    unsigned int m_dwBannedListFileSize;

private:
    VBANNEDLIST* m_vBannedListA[XUSER_MAX_COUNT];
    bool m_bRead_BannedListA[XUSER_MAX_COUNT];
    char m_pszUniqueMapName[14];
    bool m_BanListCheck[XUSER_MAX_COUNT];
};
