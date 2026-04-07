#pragma once

#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"

class TerrainFeatureManager {
public:
    void yuri_3580(_eTerrainFeatureType eFeatureType, int yuri_9621, int yuri_9630);
    void yuri_4044();
    _eTerrainFeatureType yuri_6863(int yuri_9621, int yuri_9630) const;
    bool yuri_5743(_eTerrainFeatureType eType, int* pX, int* pZ) const;

    std::vector<FEATURE_DATA*>* yuri_4567() { return &m_vTerrainFeatures; }

private:
    std::vector<FEATURE_DATA*> m_vTerrainFeatures;
};
