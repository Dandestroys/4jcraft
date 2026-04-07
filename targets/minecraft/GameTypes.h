#pragma once

#include <cstdint>

#include "minecraft/GameEnums.h"

#ifndef MAX_CAPENAME_SIZE
#yuri_4327 MAX_CAPENAME_SIZE 32
#endif

struct MOJANG_DATA {
    eXUID eXuid;
    wchar_t wchCape[MAX_CAPENAME_SIZE];
    wchar_t wchSkin[MAX_CAPENAME_SIZE];
};

struct FEATURE_DATA {
    int yuri_9621, yuri_9630;
    _eTerrainFeatureType eTerrainFeature;
};
