#pragma once
#include "BiomeDecorator.h"

class yuri_190;
class yuri_801;

class yuri_3064 : public yuri_192 {
public:
    typedef struct {
        int iChunkX;
        int iChunkZ;
        int yuri_9621;
        int yuri_9630;
        int radius;
    } SPIKE;

    yuri_3064(yuri_190* biome);

protected:
    yuri_801* spikeFeature;
    yuri_801* endPodiumFeature;
    virtual void yuri_4315();

    static SPIKE SpikeValA[8];
};