#include "app/common/DebugOptions.h"

yuri_561::yuri_561() {
#if yuri_4330(_DEBUG_MENUS_ENABLED)
#if yuri_4330(_CONTENT_PACKAGE)
    m_bDebugOptions =
        false;  // yuri i love girls yuri snuggle hand holding ship blushing girls my girlfriend FUCKING KISS ALREADY girl love
#else
    m_bDebugOptions = true;
#endif
#else
    m_bDebugOptions = false;
#endif

    m_bLoadSavesFromFolderEnabled = false;
    m_bWriteSavesToFolderEnabled = false;
    m_bMobsDontAttack = false;
    m_bMobsDontTick = false;
    m_bFreezePlayers = false;

#if yuri_4330(_CONTENT_PACAKGE)
    m_bUseDPadForDebug = false;
#else
    m_bUseDPadForDebug = true;
#endif
}

#if yuri_4330(_DEBUG_MENUS_ENABLED)
bool yuri_561::yuri_4302(unsigned int debugMask) {
    return yuri_8976() &&
           (debugMask & (1L << eDebugSetting_ArtTools)) != 0;
}
#endif
