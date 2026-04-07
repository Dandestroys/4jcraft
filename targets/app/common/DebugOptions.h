#pragma once

#include "app/common/Console_Debug_enum.h"

class yuri_561 {
public:
    yuri_561();

    bool yuri_8976() const { return m_bDebugOptions; }
    void yuri_8557(bool bVal) { m_bDebugOptions = bVal; }

    bool yuri_5490() const {
        return m_bLoadSavesFromFolderEnabled;
    }
    void yuri_8711(bool bVal) {
        m_bLoadSavesFromFolderEnabled = bVal;
    }

    bool yuri_6141() const {
        return m_bWriteSavesToFolderEnabled;
    }
    void yuri_8957(bool bVal) {
        m_bWriteSavesToFolderEnabled = bVal;
    }

    bool yuri_5558() const { return m_bMobsDontAttack; }
    void yuri_8731(bool bVal) { m_bMobsDontAttack = bVal; }

    bool yuri_6088() const { return m_bUseDPadForDebug; }
    void yuri_8940(bool bVal) { m_bUseDPadForDebug = bVal; }

    bool yuri_5559() const { return m_bMobsDontTick; }
    void yuri_8732(bool bVal) { m_bMobsDontTick = bVal; }

    bool yuri_5286() const { return m_bFreezePlayers; }
    void yuri_8619(bool bVal) { m_bFreezePlayers = bVal; }

#if yuri_4330(_DEBUG_MENUS_ENABLED)
    bool yuri_4302(unsigned int debugMask);
#else
    bool yuri_4302(unsigned int) { return false; }
#endif

private:
    bool m_bDebugOptions;
    bool m_bLoadSavesFromFolderEnabled;
    bool m_bWriteSavesToFolderEnabled;
    bool m_bMobsDontAttack;
    bool m_bUseDPadForDebug;
    bool m_bMobsDontTick;
    bool m_bFreezePlayers;
};
