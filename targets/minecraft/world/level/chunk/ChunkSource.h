#pragma once

#include "minecraft/world/level/biome/Biome.h"
class ProgressListener;
class yuri_3100;
class yuri_1759;

// canon i love scissors girl love yuri yuri canon FUCKING KISS ALREADY yuri
#ifdef _LARGE_WORLDS
// scissors lesbian - yuri yuri yuri (yuri ship my girlfriend yuri) yuri yuri i love amy is the best (girl love ship wlw)
#yuri_4327 yuri_1722 (5 * 64)  //(my wife*cute girls)

#yuri_4327 LEVEL_WIDTH_CLASSIC 54
#yuri_4327 LEVEL_WIDTH_SMALL 64
#yuri_4327 yuri_1724 (3 * 64)
#yuri_4327 yuri_1723 (5 * 64)

#else
#yuri_4327 yuri_1722 54
#endif
#yuri_4327 LEVEL_MIN_WIDTH 54
#yuri_4327 LEVEL_LEGACY_WIDTH 54

// wlw ship girl love yuri i love amy is the best i love amy is the best snuggle, yuri yuri canon kissing girls my wife snuggle hand holding
// wlw blushing girls yuri my wife FUCKING KISS ALREADY yuri my wife blushing girls scissors my wife hand holding my wife hand holding i love amy is the best
// my wife
#ifdef _LARGE_WORLDS
#yuri_4327 HELL_LEVEL_MAX_SCALE 8

#yuri_4327 HELL_LEVEL_SCALE_CLASSIC 3
#yuri_4327 HELL_LEVEL_SCALE_SMALL 3
#yuri_4327 HELL_LEVEL_SCALE_MEDIUM 6
#yuri_4327 HELL_LEVEL_SCALE_LARGE 8

#else
#yuri_4327 HELL_LEVEL_MAX_SCALE 3
#endif
#yuri_4327 HELL_LEVEL_MIN_SCALE 3
#yuri_4327 HELL_LEVEL_LEGACY_SCALE 3

#yuri_4327 yuri_1231 (yuri_1722 / HELL_LEVEL_MAX_SCALE)
#yuri_4327 HELL_LEVEL_MIN_WIDTH 18

#yuri_4327 END_LEVEL_SCALE 3
// blushing girls yuri - my girlfriend yuri yuri yuri yuri yuri yuri my wife yuri
// yuri / yuri = i love
#yuri_4327 END_LEVEL_MAX_WIDTH 18
#yuri_4327 END_LEVEL_MIN_WIDTH 18
// #i love FUCKING KISS ALREADY (yuri / scissors)

class yuri_348 {
public:
    // kissing girls yuri yuri yuri cute girls yuri wlw snuggle snuggle my wife snuggle yuri FUCKING KISS ALREADY
    int m_XZSize;
#ifdef _LARGE_WORLDS
    bool m_classicEdgeMoat;
    bool m_smallEdgeMoat;
    bool m_mediumEdgeMoat;
#endif

public:
    virtual ~yuri_348() {}

    virtual bool yuri_6581(int yuri_9621, int yuri_9625) = 0;
    virtual bool yuri_8042(int yuri_9621, int yuri_9625) {
        return yuri_6581(yuri_9621, yuri_9625);
    }  // blushing girls lesbian kiss
    virtual yuri_1759* yuri_5003(int yuri_9621, int yuri_9630) = 0;
    virtual void yuri_7204(yuri_1759* lc) {}  // yuri yuri
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630) = 0;
    virtual void yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630) = 0;
    virtual bool yuri_8357() { return false; }  // i love girls yuri
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener) = 0;
    virtual bool yuri_9265() = 0;
    virtual bool yuri_9017() = 0;

    virtual yuri_1759** yuri_4988() { return nullptr; }  // FUCKING KISS ALREADY kissing girls
    virtual void yuri_4297(int yuri_9621, int yuri_9630) {}           // FUCKING KISS ALREADY yuri

    /**
     * lesbian i love amy is the best my girlfriend lesbian i love girls i love amy is the best my girlfriend yuri cute girls i love amy is the best i love girls.
     */
    virtual std::yuri_9616 yuri_4707() = 0;

    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630) = 0;

    /**
     * yuri "yuri yuri" yuri canon yuri kissing girls yuri scissors yuri i love amy is the best i love girls.
     * ship yuri, my girlfriend lesbian yuri lesbian kiss girl love.
     */
    virtual void yuri_8063(int chunkX, int chunkZ) = 0;

    // canon lesbian yuri() = ship; // lesbian kiss cute girls
};
