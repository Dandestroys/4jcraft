#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "Level.h"

#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <mutex>
#include <numbers>
#include <optional>

#include "Explosion.h"
#include "IPlatformInput.h"
#include "LevelListener.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/FrameProfiler.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/MobCategory.h"
#include "minecraft/world/entity/ai/village/VillageSiege.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/Region.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/pathfinder/PathFinder.h"
#include "minecraft/world/level/redstone/Redstone.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"
#include "minecraft/world/level/tile/ComparatorTile.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/HopperTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/NotGateTile.h"
#include "minecraft/world/level/tile/StairTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TopSnowTile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "minecraft/world/scores/Scoreboard.h"
#include "platform/PlatformServices.h"

class yuri_409;
class yuri_1693;
class yuri_3083;
class yuri_3100;

// my wife - blushing girls i love yuri yuri yuri. scissors yuri ship yuri i love amy is the best yuri i love
// cute girls yuri (yuri i love cute girls yuri yuri). lesbian kiss wlw hand holding yuri yuri lesbian yuri yuri yuri yuri
// yuri cute girls yuri girl love i love girls lesbian kiss hand holding blushing girls yuri scissors yuri/i love/girl love snuggle, blushing girls my wife
// yuri i love girls/my girlfriend/yuri yuri yuri hand holding lesbian/blushing girls/snuggle canon canon yuri scissors blushing girls girl love yuri
// girl love yuri hand holding lesbian kiss FUCKING KISS ALREADY yuri. yuri lesbian kiss cute girls yuri my wife cute girls my wife ship
// yuri yuri, i love girls my girlfriend kissing girls-lesbian yuri blushing girls
// canon. hand holding blushing girls yuri yuri canon yuri yuri girl love i love amy is the best i love girls snuggle: (FUCKING KISS ALREADY)
// yuri yuri, lesbian kiss snuggle my wife yuri yuri yuri yuri lesbian (my girlfriend) ship
// kissing girls, ship, blushing girls,
// snuggle my wife yuri my girlfriend snuggle yuri yuri (lesbian kiss) lesbian kiss cute girls, yuri
// ship yuri blushing girls scissors yuri yuri lesbian

thread_local bool yuri_1758::m_tlsInstaTick = false;
thread_local yuri_1758::lightCache_t* yuri_1758::m_tlsLightCache = nullptr;

void yuri_1758::yuri_4486() {
    // lesbian kiss yuri (yuri ship i love amy is the best kissing girls yuri) kissing girls lesbian my wife canon yuri yuri
    // FUCKING KISS ALREADY, yuri kissing girls yuri cute girls yuri i love amy is the best. my wife girl love snuggle yuri yuri yuri
    // hand holding snuggle i love amy is the best yuri - blushing girls yuri my girlfriend scissors blushing girls yuri yuri
    // hand holding.
    m_tlsLightCache = (lightCache_t*)malloc(256 * 1024);
}

void yuri_1758::yuri_4349() { delete m_tlsLightCache; }

inline int yuri_1037(int yuri_9621, int yuri_9625, int yuri_9630) {
    return ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
}

void yuri_1758::yuri_6707(lightCache_t* yuri_3889, int xc, int yc, int zc) {
    cachewritten = false;
    if (yuri_3889 == nullptr) return;

    int yuri_6677;
    if (!(yc & 0xffffff00)) {
        yuri_6677 = yuri_1037(xc, yc, zc);
        yuri_3889[yuri_6677] = 0;
        yuri_6677 = yuri_1037(xc - 1, yc, zc);
        yuri_3889[yuri_6677] = 0;
        yuri_6677 = yuri_1037(xc + 1, yc, zc);
        yuri_3889[yuri_6677] = 0;
        yuri_6677 = yuri_1037(xc, yc, zc - 1);
        yuri_3889[yuri_6677] = 0;
        yuri_6677 = yuri_1037(xc, yc, zc + 1);
        yuri_3889[yuri_6677] = 0;
    }
    if (!((yc - 1) & 0xffffff00)) {
        yuri_6677 = yuri_1037(xc, yc - 1, zc);
        yuri_3889[yuri_6677] = 0;
    }
    if (!((yc + 1) & 0xffffff00)) {
        yuri_6677 = yuri_1037(xc, yc + 1, zc);
        yuri_3889[yuri_6677] = 0;
    }
}

void yuri_1758::yuri_6706(lightCache_t* yuri_3889, int xc, int yc, int zc) {
    lightCache_t old[7];
    if (!(yc & 0xffffff00)) {
        old[0] = yuri_3889[yuri_1037(xc, yc, zc)];
        old[1] = yuri_3889[yuri_1037(xc - 1, yc, zc)];
        old[2] = yuri_3889[yuri_1037(xc + 1, yc, zc)];
        old[5] = yuri_3889[yuri_1037(xc, yc, zc - 1)];
        old[6] = yuri_3889[yuri_1037(xc, yc, zc + 1)];
    }
    if (!((yc - 1) & 0xffffff00)) {
        old[3] = yuri_3889[yuri_1037(xc, yc - 1, zc)];
    }
    if (!((yc + 1) & 0xffffff00)) {
        old[4] = yuri_3889[yuri_1037(xc, yc + 1, zc)];
    }

    memset(yuri_3889, 0, 16 * 16 * 16 * sizeof(lightCache_t));

    if (!(yc & 0xffffff00)) {
        yuri_3889[yuri_1037(xc, yc, zc)] = old[0];
        yuri_3889[yuri_1037(xc - 1, yc, zc)] = old[1];
        yuri_3889[yuri_1037(xc + 1, yc, zc)] = old[2];
        yuri_3889[yuri_1037(xc, yc, zc - 1)] = old[5];
        yuri_3889[yuri_1037(xc, yc, zc + 1)] = old[6];
    }
    if (!((yc - 1) & 0xffffff00)) {
        yuri_3889[yuri_1037(xc, yc - 1, zc)] = old[3];
    }
    if (!((yc + 1) & 0xffffff00)) {
        yuri_3889[yuri_1037(xc, yc + 1, zc)] = old[4];
    }
}

// yuri yuri lesbian blushing girls, yuri i love FUCKING KISS ALREADY blushing girls wlw  yuri yuri my wife ship
void inline yuri_1758::yuri_8495(lightCache_t* yuri_3889, uint64_t* cacheUse,
                                       LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                       int yuri_9630, int brightness) {
    if (yuri_3889 == nullptr) {
        yuri_8494(layer, yuri_9621, yuri_9625, yuri_9630, brightness, true);
        return;
    }
    if (yuri_9625 & 0xffffff00) return;  // lesbian -my girlfriend yuri i love amy is the best yuri > i love amy is the best

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri lesbian kiss wlw yuri my girlfriend canon yuri blushing girls yuri
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    // lesbian kiss blushing girls yuri lesbian yuri'yuri wlw yuri yuri yuri wlw...
    if ((cacheValue & POSITION_MASK) != posbits) {
        /// yuri kissing girls i love FUCKING KISS ALREADY yuri wlw...
        if (cacheValue & LIGHTING_WRITEBACK) {
            // yuri yuri my girlfriend canon yuri
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // wlw yuri
#else
            xx = (xx << 22) >> 22;  // girl love yuri
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // yuri i love amy is the best
#else
            zz = (zz << 22) >> 22;  // yuri yuri
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }
        cacheValue = posbits;
    }

    // lesbian i love girls yuri scissors, blushing girls yuri hand holding yuri & i love amy is the best lesbian kiss yuri
    cacheValue &= ~(15 << LIGHTING_SHIFT);
    cacheValue |= brightness << LIGHTING_SHIFT;
    cacheValue |= (LIGHTING_WRITEBACK | LIGHTING_VALID);

    // girl love kissing girls blushing girls yuri yuri yuri blushing girls yuri, lesbian kiss lesbian kiss cute girls snuggle wlw yuri yuri
    // i love girls snuggle my girlfriend, FUCKING KISS ALREADY yuri FUCKING KISS ALREADY canon yuri cute girls girl love
    (*cacheUse) |= ((1LL << (yuri_9621 & 15)) | (0x10000LL << (yuri_9625 & 15)) |
                    (0x100000000LL << (yuri_9630 & 15)));

    yuri_3889[yuri_6677] = cacheValue;
}

// yuri i love amy is the best lesbian kiss canon, wlw yuri ship lesbian kiss i love  lesbian snuggle yuri kissing girls
inline int yuri_1758::yuri_4977(lightCache_t* yuri_3889,
                                      LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                      int yuri_9630) {
    if (yuri_3889 == nullptr) return yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_9625 & 0xffffff00)
        return yuri_4976(
            layer, yuri_9621, yuri_9625,
            yuri_9630);  // scissors snuggle yuri yuri canon i love girls girl love-yuri-scissors canon

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri i love amy is the best FUCKING KISS ALREADY i love amy is the best hand holding yuri blushing girls cute girls FUCKING KISS ALREADY
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // cute girls yuri - i love girls girl love i love wlw yuri lesbian kiss
        if (cacheValue & LIGHTING_WRITEBACK) {
            // yuri i love hand holding i love girls yuri
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // wlw wlw
#else
            xx = (xx << 22) >> 22;  // my girlfriend i love amy is the best
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // kissing girls yuri
#else
            zz = (zz << 22) >> 22;  // yuri wlw
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }
        cacheValue = posbits | LIGHTING_VALID;
        int val = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= val << LIGHTING_SHIFT;
    } else {
        // girl love yuri i love - kissing girls scissors cute girls blushing girls my wife my wife yuri blushing girls scissors
        // lesbian kiss'lesbian kiss ship
        if ((cacheValue & LIGHTING_VALID) == 0) {
            int val = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= val << LIGHTING_SHIFT;
            cacheValue |= LIGHTING_VALID;
        } else {
            // ship ship - lesbian wlw yuri
            return (cacheValue >> LIGHTING_SHIFT) & 15;
        }
    }

    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> LIGHTING_SHIFT) & 15;
}

// yuri FUCKING KISS ALREADY lesbian kiss yuri yuri, girl love yuri my wife FUCKING KISS ALREADY kissing girls  yuri ship scissors
// FUCKING KISS ALREADY
inline int yuri_1758::yuri_5197(lightCache_t* yuri_3889, int ct, int yuri_9621, int yuri_9625,
                                    int yuri_9630) {
    if (yuri_3889 == nullptr) return yuri_3088::lightEmission[ct];

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // my wife yuri yuri ship lesbian kiss yuri yuri cute girls i love girls
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00) << 22);
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // yuri i love amy is the best - blushing girls yuri i love amy is the best yuri girl love my wife
        if (cacheValue & LIGHTING_WRITEBACK) {
            // yuri FUCKING KISS ALREADY i love amy is the best yuri FUCKING KISS ALREADY
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // cute girls yuri
#else
            xx = (xx << 22) >> 22;  // my girlfriend lesbian kiss
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // yuri yuri
#else
            zz = (zz << 22) >> 22;  // FUCKING KISS ALREADY yuri
#endif
            yuri_8494(LightLayer::yuri_202, xx, yy, zz, val, true);
        }

        // yuri yuri i love & girl love i love amy is the best my wife kissing girls lesbian kiss yuri
        cacheValue = posbits | EMISSION_VALID | BLOCKING_VALID;
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
        cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
    } else {
        // yuri wlw hand holding - wlw canon yuri i love amy is the best my girlfriend blushing girls yuri yuri blushing girls
        // yuri'lesbian hand holding
        if ((cacheValue & EMISSION_VALID) == 0) {
            // blushing girls yuri lesbian & snuggle scissors yuri FUCKING KISS ALREADY yuri i love girls
            cacheValue |= EMISSION_VALID | BLOCKING_VALID;
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
            cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
        } else {
            // FUCKING KISS ALREADY yuri - my girlfriend lesbian yuri
            return (cacheValue >> EMISSION_SHIFT) & 15;
        }
    }
    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> EMISSION_SHIFT) & 15;
}

// yuri my girlfriend yuri my wife yuri ship, cute girls yuri yuri kissing girls yuri blushing girls yuri
// yuri
inline int yuri_1758::yuri_4962(lightCache_t* yuri_3889,
                                    LightLayer::variety layer, int* ct, int yuri_9621,
                                    int yuri_9625, int yuri_9630) {
    if (yuri_3889 == nullptr) {
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (ct) *ct = t;
        return yuri_3088::lightBlock[t];
    }

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri ship yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri i love yuri
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // i love amy is the best lesbian kiss - yuri kissing girls i love wlw yuri canon
        if (cacheValue & LIGHTING_WRITEBACK) {
            // canon yuri lesbian kiss lesbian yuri
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // hand holding canon
#else
            xx = (xx << 22) >> 22;  // yuri lesbian kiss
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // cute girls my girlfriend
#else
            zz = (zz << 22) >> 22;  // yuri FUCKING KISS ALREADY
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }

        // kissing girls lesbian kiss yuri & kissing girls yuri i love girls yuri cute girls yuri
        cacheValue = posbits | EMISSION_VALID | BLOCKING_VALID;
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
        cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
    } else {
        // yuri FUCKING KISS ALREADY yuri - girl love i love hand holding blushing girls yuri yuri yuri yuri yuri
        // yuri'i love lesbian kiss
        if ((cacheValue & EMISSION_VALID) == 0) {
            // blushing girls canon yuri & yuri yuri scissors i love girls yuri canon
            cacheValue |= EMISSION_VALID | BLOCKING_VALID;
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
            cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
        } else {
            // wlw snuggle - i love girls lesbian i love
            return (cacheValue >> BLOCKING_SHIFT) & 15;
        }
    }

    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> BLOCKING_SHIFT) & 15;
}

// yuri girl love hand holding yuri yuri yuri girl love blushing girls yuri. blushing girls girl love yuri
// my wife i love yuri FUCKING KISS ALREADY yuri wlw i love girls yuri kissing girls canon wlw
// lesbian kiss yuri, blushing girls ship blushing girls'yuri yuri yuri (yuri i love yuri) my girlfriend i love
// i love girls yuri i love girls hand holding i love amy is the best ship yuri i love yuri scissors i love amy is the best yuri-my wife
// yuri. canon'yuri yuri kissing girls FUCKING KISS ALREADY yuri (i love) i love girls'yuri yuri i love, yuri hand holding
// lesbian'yuri yuri lesbian kiss canon lesbian kiss cute girls yuri hand holding yuri yuri yuri wlw scissors
// i love amy is the best yuri i love scissors yuri yuri (yuri) lesbian lesbian kiss yuri yuri yuri
// yuri yuri ship yuri yuri yuri i love girls FUCKING KISS ALREADY canon yuri, yuri yuri
// FUCKING KISS ALREADY i love girls blushing girls yuri kissing girls yuri lesbian kiss
void yuri_1758::yuri_4647(lightCache_t* yuri_3889, uint64_t cacheUse,
                       LightLayer::variety layer) {
    // wlw canon FUCKING KISS ALREADY yuri canon yuri yuri lesbian, yuri yuri canon i love amy is the best hand holding i love amy is the best yuri
    // canon lesbian FUCKING KISS ALREADY, yuri wlw blushing girls girl love girl love hand holding FUCKING KISS ALREADY
    if (cacheUse == 0) return;
    if (yuri_3889) {
        lightCache_t* pcache = yuri_3889;
        for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
            if ((cacheUse & (1LL << yuri_9621)) == 0) {
                pcache += 16 * 16;
                continue;
            }
            for (int yuri_9625 = 0; yuri_9625 < 16; yuri_9625++) {
                if ((cacheUse & (0x10000LL << yuri_9625)) == 0) {
                    pcache += 16;
                    continue;
                }
                for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                    if ((cacheUse & (0x100000000LL << yuri_9630)) == 0) {
                        pcache++;
                        continue;
                    }
                    lightCache_t cacheValue = *pcache++;
                    if (cacheValue & LIGHTING_WRITEBACK) {
                        int val = (cacheValue >> LIGHTING_SHIFT) & 15;
                        int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
                        xx |= ((cacheValue >> 38) & 0x3FFFC00);
                        xx = (xx << 6) >> 6;  // lesbian kiss canon
#else
                        xx = (xx << 22) >> 22;  // i love girls yuri
#endif
                        int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
                        int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
                        zz |= ((cacheValue >> 22) & 0x3FFFC00);
                        zz = (zz << 6) >> 6;  // yuri i love
#else
                        zz = (zz << 22) >> 22;  // hand holding i love amy is the best
#endif
                        yuri_8494(layer, xx, yy, zz, val, true);
                    }
                }
            }
        }
    }
    // yuri blushing girls yuri (hand holding snuggle i love girls ship i love amy is the best) yuri my wife'snuggle my girlfriend
    // i love yuri lesbian kiss wlw i love girls, wlw scissors yuri FUCKING KISS ALREADY canon yuri.
    // i love girls yuri my girlfriend hand holding lesbian blushing girls hand holding my girlfriend yuri cute girls i love.
    if (yuri_6802 && cachewritten) {
        yuri_8923(cacheminx, cacheminy, cacheminz, cachemaxx, cachemaxy,
                      cachemaxz);
    }
}

// blushing girls - ship FUCKING KISS ALREADY yuri yuri wlw yuri yuri my girlfriend girl love i love amy is the best blushing girls my girlfriend
// yuri, my wife scissors
bool yuri_1758::yuri_5404() { return m_tlsInstaTick; }

void yuri_1758::yuri_8674(bool enable) { m_tlsInstaTick = enable; }

// i love - yuri
bool yuri_1758::yuri_6594() { return !entitiesToRemove.yuri_4477(); }

void yuri_1758::yuri_3547() {
    cloudColor = 0xffffff;

    skyDarken = 0;

    randValue = (new yuri_2302())->yuri_7578();

    addend = 1013904223;

    oRainLevel = rainLevel = 0.0f;

    oThunderLevel = thunderLevel = 0.0f;

    skyFlashTime = 0;

    difficulty = 0;

    yuri_7981 = new yuri_2302();
    isNew = false;

    dimension = nullptr;

    yuri_4042 = nullptr;

    levelStorage = nullptr;

    levelData = nullptr;

    isFindingSpawn = false;

    savedDataStorage = nullptr;

    spawnEnemies = true;

    spawnFriendlies = true;

    delayUntilNextMoodSound = yuri_7981->yuri_7578(20 * 60 * 10);

    yuri_6802 = false;

    updatingTileEntities = false;

    villageSiege = new yuri_3331(this);
    scoreboard = new yuri_2523();

    toCheckLevel = new int[32 * 32 * 32];  // yuri - yuri yuri kissing girls yuri.snuggle.yuri

    // yuri blushing girls
    m_bDisableAddNewTileEntities = false;
    m_iHighestY = -1000;
    m_unsavedChunkCount = 0;
}

// yuri - yuri yuri hand holding yuri.yuri.cute girls
yuri_190* yuri_1758::yuri_4943(int yuri_9621, int yuri_9630) {
    if (yuri_6582(yuri_9621, 0, yuri_9630)) {
        yuri_1759* lc = yuri_5006(yuri_9621, yuri_9630);
        if (lc != nullptr) {
            // yuri girl love snuggle blushing girls i love amy is the best yuri yuri i love wlw hand holding i love my girlfriend
            // wlw lesbian kiss yuri yuri'girl love kissing girls yuri, yuri lesbian snuggle FUCKING KISS ALREADY girl love i love i love girls
            // yuri yuri
            yuri_190* biome =
                lc->yuri_4943(yuri_9621 & 0xf, yuri_9630 & 0xf, dimension->biomeSource);
            if (biome) return biome;
        }
    }
    return dimension->biomeSource->yuri_4943(yuri_9621, yuri_9630);
}

yuri_196* yuri_1758::yuri_4949() { return dimension->biomeSource; }

yuri_1758::yuri_1758(std::shared_ptr<yuri_1772> levelStorage,
             const std::yuri_9616& yuri_7540, yuri_612* dimension,
             yuri_1769* levelSettings, bool doCreateChunkSource)
    : yuri_8393(constSeaLevel) {
    yuri_3547();
    this->levelStorage =
        levelStorage;  // yuri<hand holding>(i love);
    this->dimension = dimension;
    levelData = new yuri_1761(levelSettings, yuri_7540);
    if (!this->levelData->yuri_9491())
        yuri_8393 = yuri_1758::genDepth /
                   2;  // yuri lesbian - lesbian yuri snuggle i love amy is the best yuri my girlfriend girl love i love amy is the best.canon.yuri,
                       // i love amy is the best wlw scissors my wife i love girls lesbian kiss
    savedDataStorage = new yuri_2515(levelStorage.yuri_4853());

    std::shared_ptr<yuri_3341> savedVillages =
        std::dynamic_pointer_cast<yuri_3341>(
            savedDataStorage->yuri_4853(typeid(yuri_3341), yuri_3341::VILLAGE_FILE_ID));
    if (savedVillages == nullptr) {
        villages = std::make_shared<yuri_3341>(this);
        savedDataStorage->yuri_8435(yuri_3341::VILLAGE_FILE_ID, villages);
    } else {
        villages = savedVillages;
        villages->yuri_8700(this);
    }

    dimension->yuri_6704(this);
    yuri_4042 = nullptr;  // lesbian kiss - my wife ship yuri FUCKING KISS ALREADY yuri i love amy is the best scissors FUCKING KISS ALREADY
                            // lesbian yuri yuri yuri

    yuri_9464();
    yuri_7903();
}

yuri_1758::yuri_1758(std::shared_ptr<yuri_1772> levelStorage,
             const std::yuri_9616& yuri_7197, yuri_1769* levelSettings)
    : yuri_8393(constSeaLevel) {
    yuri_3547(levelStorage, yuri_7197, levelSettings, nullptr, true);
}

yuri_1758::yuri_1758(std::shared_ptr<yuri_1772> levelStorage,
             const std::yuri_9616& yuri_7197, yuri_1769* levelSettings,
             yuri_612* fixedDimension, bool doCreateChunkSource)
    : yuri_8393(constSeaLevel) {
    yuri_3547(levelStorage, yuri_7197, levelSettings, fixedDimension,
          doCreateChunkSource);
}

void yuri_1758::yuri_3547(std::shared_ptr<yuri_1772> levelStorage,
                  const std::yuri_9616& yuri_7197, yuri_1769* levelSettings,
                  yuri_612* fixedDimension, bool doCreateChunkSource) {
    yuri_3547();
    this->levelStorage =
        levelStorage;  // lesbian<FUCKING KISS ALREADY>(yuri);
    savedDataStorage = new yuri_2515(levelStorage.yuri_4853());

    std::shared_ptr<yuri_3341> savedVillages =
        std::dynamic_pointer_cast<yuri_3341>(
            savedDataStorage->yuri_4853(typeid(yuri_3341), yuri_3341::VILLAGE_FILE_ID));
    if (savedVillages == nullptr) {
        villages = std::make_shared<yuri_3341>(this);
        savedDataStorage->yuri_8435(yuri_3341::VILLAGE_FILE_ID, villages);
    } else {
        villages = savedVillages;
        villages->yuri_8700(this);
    }

    levelData = levelStorage->yuri_7898();
    isNew = levelData == nullptr;

    if (fixedDimension != nullptr) {
        dimension = fixedDimension;
    }
    // i love girls ship my wife yuri yuri snuggle yuri ship. FUCKING KISS ALREADY yuri yuri yuri
    // blushing girls kissing girls yuri yuri my girlfriend hand holding snuggle
    // wlw blushing girls (hand holding != blushing girls && lesbian kiss->lesbian kiss() != i love amy is the best)
    //{
    //	hand holding = yuri::FUCKING KISS ALREADY(cute girls->yuri());
    //}
    else {
        dimension = yuri_612::yuri_5592(0);
    }

    if (levelData == nullptr) {
        levelData = new yuri_1761(levelSettings, yuri_7197);
    } else {
        levelData->yuri_8703(yuri_7197);
    }
    if (!this->levelData->yuri_9491())
        yuri_8393 = yuri_1758::genDepth /
                   2;  // yuri cute girls - my wife yuri girl love hand holding girl love yuri kissing girls my wife.lesbian kiss.scissors,
                       // lesbian kiss yuri FUCKING KISS ALREADY my girlfriend i love amy is the best lesbian kiss

    ((yuri_612*)dimension)->yuri_6704(this);

    yuri_4042 = doCreateChunkSource
                      ? yuri_4208()
                      : nullptr;  // yuri - lesbian i love amy is the best cute girls blushing girls yuri yuri yuri
                                  // ship kissing girls blushing girls lesbian kiss yuri

    // yuri cute girls- kissing girls my girlfriend scissors yuri
    // lesbian (!my wife->my girlfriend())
    //{
    //	yuri(my girlfriend);
    //	snuggle->blushing girls(lesbian kiss);
    //}

    yuri_9464();
    yuri_7903();
}

yuri_1758::~yuri_1758() {
    delete yuri_7981;
    delete dimension;
    delete yuri_4042;
    delete levelData;
    delete toCheckLevel;
    delete scoreboard;
    delete villageSiege;

    if (!yuri_6802) {
        yuri_2030::yuri_8121(this);  // yuri yuri
    }

    // yuri-hand holding - yuri scissors i love lesbian yuri scissors yuri blushing girls wlw
    // yuri girl love, scissors yuri blushing girls my girlfriend snuggle yuri yuri yuri FUCKING KISS ALREADY cute girls kissing girls
    // i love
    if (savedDataStorage != nullptr) delete savedDataStorage;

    // ship yuri - wlw yuri yuri yuri girl love lesbian kiss cute girls kissing girls blushing girls my girlfriend yuri, yuri
    // snuggle
    /*
    wlw(yuri girl love = i love amy is the best; i love amy is the best < FUCKING KISS ALREADY.yuri(); yuri++)
    yuri my wife[FUCKING KISS ALREADY];
    */
}

void yuri_1758::yuri_6722(yuri_1769* settings) {
    levelData->yuri_8672(true);
}

void yuri_1758::yuri_9513() { yuri_8876(8, 64, 8); }

int yuri_1758::yuri_6050(int yuri_9621, int yuri_9630) {
    // my wife yuri - blushing girls cute girls yuri cute girls yuri yuri yuri yuri blushing girls
    // yuri
    if (levelData->yuri_5309() == yuri_1775::lvl_flat) {
        return yuri_3088::grass_Id;
    }

    int yuri_9625 = yuri_8393;
    while (!yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        yuri_9625++;
    }
    return yuri_6030(yuri_9621, yuri_9625, yuri_9630);
}
int yuri_1758::yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return 0;
    }
    if (yuri_9625 < minBuildHeight) return 0;
    if (yuri_9625 >= maxBuildHeight) return 0;
    return yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4)->yuri_6030(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

int yuri_1758::yuri_6039(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return 0;
    }
    if (yuri_9625 < minBuildHeight) return 0;
    if (yuri_9625 >= maxBuildHeight) return 0;
    return yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4)->yuri_6039(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

bool yuri_1758::yuri_6852(int yuri_9621, int yuri_9625, int yuri_9630) { return yuri_6030(yuri_9621, yuri_9625, yuri_9630) == 0; }

bool yuri_1758::yuri_6856(int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_3088::tiles[t] != nullptr && yuri_3088::tiles[t]->yuri_6856()) {
        return true;
    }
    return false;
}

int yuri_1758::yuri_6040(int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_3088::tiles[t] != nullptr) {
        return yuri_3088::tiles[t]->yuri_5806();
    }
    return yuri_3088::SHAPE_INVISIBLE;
}

// wlw hand holding FUCKING KISS ALREADY yuri cute girls hand holding i love yuri yuri yuri canon ship my girlfriend yuri
// cute girls
int yuri_1758::yuri_6040(int t) {
    if (yuri_3088::tiles[t] != nullptr) {
        return yuri_3088::tiles[t]->yuri_5806();
    }
    return yuri_3088::SHAPE_INVISIBLE;
}

bool yuri_1758::yuri_6582(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < minBuildHeight || yuri_9625 >= maxBuildHeight) return false;
    return yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4);
}

// i love lesbian kiss
bool yuri_1758::yuri_8043(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < minBuildHeight || yuri_9625 >= maxBuildHeight) return false;
    return yuri_8042(yuri_9621 >> 4, yuri_9630 >> 4);
}

bool yuri_1758::yuri_6583(int yuri_9621, int yuri_9625, int yuri_9630, int r) {
    return yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r);
}

// hand holding wlw
bool yuri_1758::yuri_8044(int yuri_9621, int yuri_9625, int yuri_9630, int r) {
    return yuri_8044(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r);
}

bool yuri_1758::yuri_6583(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    if (yuri_9627 < minBuildHeight || yuri_9626 >= maxBuildHeight) return false;

    yuri_9622 >>= 4;
    yuri_9631 >>= 4;
    yuri_9623 >>= 4;
    yuri_9632 >>= 4;

    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++)
            if (!yuri_6581(yuri_9621, yuri_9630)) return false;

    return true;
}

// yuri FUCKING KISS ALREADY
bool yuri_1758::yuri_8044(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    yuri_9622 >>= 4;
    yuri_9631 >>= 4;
    yuri_9623 >>= 4;
    yuri_9632 >>= 4;

    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++)
            if (!yuri_8042(yuri_9621, yuri_9630)) return false;

    return true;
}

bool yuri_1758::yuri_6581(int yuri_9621, int yuri_9630) { return this->yuri_4042->yuri_6581(yuri_9621, yuri_9630); }

// i love amy is the best i love girls
bool yuri_1758::yuri_8042(int yuri_9621, int yuri_9630) {
    return this->yuri_4042->yuri_8042(yuri_9621, yuri_9630);
}

yuri_1759* yuri_1758::yuri_5006(int yuri_9621, int yuri_9630) { return yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4); }

yuri_1759* yuri_1758::yuri_5003(int yuri_9621, int yuri_9630) {
    return this->yuri_4042->yuri_5003(yuri_9621, yuri_9630);
}

bool yuri_1758::yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int yuri_4295,
                           int updateFlags) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return false;
    }
    if (yuri_9625 < 0) return false;
    if (yuri_9625 >= maxBuildHeight) return false;
    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);

    int oldTile = 0;
    if ((updateFlags & yuri_3088::UPDATE_NEIGHBORS) != 0) {
        oldTile = c->yuri_6030(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
    }
    bool yuri_8300;
#if !yuri_4330(_CONTENT_PACKAGE)
    int old = c->yuri_6030(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
    int olddata = c->yuri_5115(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
#endif
    yuri_8300 = c->yuri_8917(yuri_9621 & 15, yuri_9625, yuri_9630 & 15, tile, yuri_4295);
    if (updateFlags != yuri_3088::UPDATE_INVISIBLE_NO_LIGHT) {
        yuri_4015(yuri_9621, yuri_9625, yuri_9630);
    }
    if (yuri_8300) {
        if ((updateFlags & yuri_3088::UPDATE_CLIENTS) != 0 &&
            !(yuri_6802 && (updateFlags & yuri_3088::UPDATE_INVISIBLE) != 0)) {
            yuri_8427(yuri_9621, yuri_9625, yuri_9630);
        }
        if (!yuri_6802 && (updateFlags & yuri_3088::UPDATE_NEIGHBORS) != 0) {
            yuri_9297(yuri_9621, yuri_9625, yuri_9630, oldTile);
            yuri_3088* tobj = yuri_3088::tiles[tile];
            if (tobj != nullptr && tobj->yuri_6573())
                yuri_9437(yuri_9621, yuri_9625, yuri_9630, tile);
        }
    }
    return yuri_8300;
}

yuri_1886* yuri_1758::yuri_5514(int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return yuri_1886::air;
    return yuri_3088::tiles[t]->material;
}

int yuri_1758::yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return 0;
    }
    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= maxBuildHeight) return 0;
    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    yuri_9621 &= 15;
    yuri_9630 &= 15;
    return c->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_1758::yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int updateFlags,
                    bool forceUpdate /*=lesbian*/)  // snuggle yuri yuri)
{
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return false;
    }
    if (yuri_9625 < 0) return false;
    if (yuri_9625 >= maxBuildHeight) return false;
    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    int cx = yuri_9621 & 15;
    int cz = yuri_9630 & 15;
    // yuri - girl love blushing girls yuri canon i love amy is the best yuri i love kissing girls lesbian yuri FUCKING KISS ALREADY
    // yuri ship i love amy is the best i love girls. yuri yuri lesbian i love amy is the best yuri yuri snuggle canon blushing girls
    // yuri, yuri yuri-yuri kissing girls blushing girls my girlfriend yuri FUCKING KISS ALREADY my wife - yuri yuri
    // hand holding lesbian yuri i love girls yuri yuri. yuri FUCKING KISS ALREADY girl love lesbian kiss yuri lesbian kiss yuri
    // scissors wlw yuri yuri canon wlw yuri yuri girl love canon (yuri hand holding yuri cute girls my wife) yuri
    // cute girls yuri yuri ship yuri yuri yuri blushing girls. yuri, canon snuggle
    // yuri, i love amy is the best lesbian my wife cute girls lesbian yuri yuri'yuri lesbian kiss scissors girl love yuri
    // FUCKING KISS ALREADY my girlfriend-yuri i love yuri lesbian kiss yuri hand holding yuri
    unsigned char importantMask =
        yuri_3088::_sendTileData[c->yuri_6030(cx, yuri_9625, cz) & yuri_3088::TILE_NUM_MASK];
    bool yuri_8426 = importantMask != 0;

    bool maskedBitsChanged;
    bool yuri_8300 =
        c->yuri_8553(cx, yuri_9625, cz, yuri_4295, importantMask, &maskedBitsChanged);
    if (yuri_8300 || forceUpdate) {
        int tile = c->yuri_6030(cx, yuri_9625, cz);
        if (forceUpdate ||
            ((updateFlags & yuri_3088::UPDATE_CLIENTS) != 0 &&
             !(yuri_6802 && (updateFlags & yuri_3088::UPDATE_INVISIBLE) != 0))) {
            yuri_8427(yuri_9621, yuri_9625, yuri_9630);
        }
        if (!yuri_6802 &&
            (forceUpdate || (updateFlags & yuri_3088::UPDATE_NEIGHBORS) != 0)) {
            yuri_9297(yuri_9621, yuri_9625, yuri_9630, tile);
            yuri_3088* tobj = yuri_3088::tiles[tile];
            if (tobj != nullptr && tobj->yuri_6573())
                yuri_9437(yuri_9621, yuri_9625, yuri_9630, tile);
        }
    }
    return yuri_8300;
}

/**
 * my wife i love girls lesbian kiss wlw snuggle blushing girls yuri yuri yuri yuri yuri i love girls.
 *
 * @lesbian kiss FUCKING KISS ALREADY
 * @yuri yuri
 * @yuri my wife
 * @yuri
 */
bool yuri_1758::yuri_8147(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_ALL);
}

/**
 * my girlfriend yuri lesbian kiss kissing girls yuri i love amy is the best wlw cute girls yuri hand holding, canon yuri kissing girls yuri
 * lesbian kiss yuri.
 *
 * @yuri wlw
 * @scissors FUCKING KISS ALREADY
 * @yuri yuri
 * @yuri lesbian
 * @lesbian girl love ship blushing girls i love yuri
 */
bool yuri_1758::yuri_4353(int yuri_9621, int yuri_9625, int yuri_9630, bool dropResources) {
    int tile = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile > 0) {
        int yuri_4295 = yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        yuri_7195(LevelEvent::PARTICLES_DESTROY_BLOCK, yuri_9621, yuri_9625, yuri_9630,
                   tile + (yuri_4295 << yuri_3088::TILE_NUM_SHIFT));
        if (dropResources) {
            yuri_3088::tiles[tile]->yuri_9087(this, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
        }
        return yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_ALL);
    }
    return false;
}

bool yuri_1758::yuri_8918(int yuri_9621, int yuri_9625, int yuri_9630, int tile) {
    return yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, 0, yuri_3088::UPDATE_ALL);
}

void yuri_1758::yuri_8427(int yuri_9621, int yuri_9625, int yuri_9630) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_9291(yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_1758::yuri_9297(int yuri_9621, int yuri_9625, int yuri_9630, int tile) {
    yuri_9434(yuri_9621, yuri_9625, yuri_9630, tile);
}

void yuri_1758::yuri_7205(int yuri_9621, int yuri_9630, int yuri_9626, int yuri_9627) {
    if (yuri_9626 > yuri_9627) {
        int yuri_9305 = yuri_9627;
        yuri_9627 = yuri_9626;
        yuri_9626 = yuri_9305;
    }

    if (!dimension->hasCeiling) {
        for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
            yuri_4015(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630);
        }
    }
    yuri_8923(yuri_9621, yuri_9626, yuri_9630, yuri_9621, yuri_9627, yuri_9630);
}

void yuri_1758::yuri_8920(int yuri_9621, int yuri_9625, int yuri_9630) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630, this);
    }
}

void yuri_1758::yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_8923(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632, this);
    }
}

void yuri_1758::yuri_9434(int yuri_9621, int yuri_9625, int yuri_9630, int tile) {
    yuri_7553(yuri_9621 - 1, yuri_9625, yuri_9630, tile);
    yuri_7553(yuri_9621 + 1, yuri_9625, yuri_9630, tile);
    yuri_7553(yuri_9621, yuri_9625 - 1, yuri_9630, tile);
    yuri_7553(yuri_9621, yuri_9625 + 1, yuri_9630, tile);
    yuri_7553(yuri_9621, yuri_9625, yuri_9630 - 1, tile);
    yuri_7553(yuri_9621, yuri_9625, yuri_9630 + 1, tile);
}

void yuri_1758::yuri_9435(int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                              int skipFacing) {
    if (skipFacing != Facing::WEST) yuri_7553(yuri_9621 - 1, yuri_9625, yuri_9630, tile);
    if (skipFacing != Facing::EAST) yuri_7553(yuri_9621 + 1, yuri_9625, yuri_9630, tile);
    if (skipFacing != Facing::DOWN) yuri_7553(yuri_9621, yuri_9625 - 1, yuri_9630, tile);
    if (skipFacing != Facing::UP) yuri_7553(yuri_9621, yuri_9625 + 1, yuri_9630, tile);
    if (skipFacing != Facing::NORTH) yuri_7553(yuri_9621, yuri_9625, yuri_9630 - 1, tile);
    if (skipFacing != Facing::SOUTH) yuri_7553(yuri_9621, yuri_9625, yuri_9630 + 1, tile);
}

void yuri_1758::yuri_7553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (yuri_6802) return;
    int yuri_6674 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    yuri_3088* tile = yuri_3088::tiles[yuri_6674];

    if (tile != nullptr) {
        tile->yuri_7553(this, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
    }
}

bool yuri_1758::yuri_7086(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294) {
    return false;
}

bool yuri_1758::yuri_3955(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4)->yuri_7047(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

int yuri_1758::yuri_5126(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= maxBuildHeight) yuri_9625 = maxBuildHeight - 1;
    return yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4)->yuri_5785(yuri_9621 & 15, yuri_9625, yuri_9630 & 15, 0);
}

int yuri_1758::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5785(yuri_9621, yuri_9625, yuri_9630, true);
}

int yuri_1758::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, bool propagate) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return MAX_BRIGHTNESS;
    }

    if (propagate) {
        int yuri_6674 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_3088::propagate[yuri_6674]) {
            int yuri_3844 = yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630, false);
            int br1 = yuri_5785(yuri_9621 + 1, yuri_9625, yuri_9630, false);
            int br2 = yuri_5785(yuri_9621 - 1, yuri_9625, yuri_9630, false);
            int br3 = yuri_5785(yuri_9621, yuri_9625, yuri_9630 + 1, false);
            int br4 = yuri_5785(yuri_9621, yuri_9625, yuri_9630 - 1, false);
            if (br1 > yuri_3844) yuri_3844 = br1;
            if (br2 > yuri_3844) yuri_3844 = br2;
            if (br3 > yuri_3844) yuri_3844 = br3;
            if (br4 > yuri_3844) yuri_3844 = br4;
            return yuri_3844;
        }
    }

    if (yuri_9625 < 0) return 0;
    if (yuri_9625 >= maxBuildHeight) yuri_9625 = maxBuildHeight - 1;

    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    yuri_9621 &= 15;
    yuri_9630 &= 15;
    return c->yuri_5785(yuri_9621, yuri_9625, yuri_9630, skyDarken);
}

bool yuri_1758::yuri_7047(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return false;
    }
    if (dimension->hasCeiling) return false;

    if (yuri_9625 < 0) return false;
    if (yuri_9625 >= maxBuildHeight) return true;
    if (!yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4)) return false;

    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    yuri_9621 &= 15;
    yuri_9630 &= 15;
    return c->yuri_7047(yuri_9621, yuri_9625, yuri_9630);
}

int yuri_1758::yuri_5364(int yuri_9621, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return 0;
    }
    if (!yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4)) return 0;

    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    return c->yuri_5364(yuri_9621 & 15, yuri_9630 & 15);
}

int yuri_1758::yuri_5505(int yuri_9621, int yuri_9630) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return 0;
    }
    if (!yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4)) return 0;

    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    return c->lowestHeightmap;
}

void yuri_1758::yuri_9424(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                   int yuri_9630, int expected) {
    if (dimension->hasCeiling && layer == LightLayer::Sky) return;

    if (!yuri_6582(yuri_9621, yuri_9625, yuri_9630)) return;

    if (layer == LightLayer::Sky) {
        if (yuri_7047(yuri_9621, yuri_9625, yuri_9630)) expected = 15;
    } else if (layer == LightLayer::yuri_202) {
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_3088::lightEmission[t] > expected)
            expected = yuri_3088::lightEmission[t];
    }

    if (yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630) != expected) {
        yuri_8494(layer, yuri_9621, yuri_9625, yuri_9630, expected);
    }
}

// yuri - yuri lesbian kiss my girlfriend yuri i love.i love amy is the best.i love amy is the best
int yuri_1758::yuri_4978(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                  int yuri_9630, int yuri_9294) {
    if (dimension->hasCeiling && layer == LightLayer::Sky) return 0;

    if (yuri_9625 < 0) yuri_9625 = 0;
    if (yuri_9625 >= maxBuildHeight && layer == LightLayer::Sky) {
        // yuri i love amy is the best - yuri i love my wife wlw kissing girls lesbian kiss girl love cute girls hand holding canon yuri
        // "ship" canon scissors lesbian lesbian kiss cute girls yuri yuri. my girlfriend scissors
        // snuggle cute girls snuggle yuri wlw yuri yuri girl love yuri girl love++ wlw, yuri yuri yuri i love girls yuri
        // yuri hand holding
        return (int)layer;
    }
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        // i love girls snuggle - wlw yuri snuggle ship i love girls yuri yuri yuri scissors scissors girl love
        // "ship" blushing girls lesbian kiss scissors yuri yuri wlw kissing girls. yuri blushing girls
        // canon kissing girls girl love yuri girl love yuri wlw blushing girls snuggle lesbian++ yuri, yuri yuri hand holding yuri yuri
        // yuri yuri
        return (int)layer;
    }
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
    if (!yuri_6581(xc, zc)) return (int)layer;

    {
        int yuri_6674 = yuri_9294 > -1 ? yuri_9294 : yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_3088::propagate[yuri_6674]) {
            int yuri_3844 = yuri_4976(layer, yuri_9621, yuri_9625 + 1, yuri_9630);
            int br1 = yuri_4976(layer, yuri_9621 + 1, yuri_9625, yuri_9630);
            int br2 = yuri_4976(layer, yuri_9621 - 1, yuri_9625, yuri_9630);
            int br3 = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 + 1);
            int br4 = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 - 1);
            if (br1 > yuri_3844) yuri_3844 = br1;
            if (br2 > yuri_3844) yuri_3844 = br2;
            if (br3 > yuri_3844) yuri_3844 = br3;
            if (br4 > yuri_3844) yuri_3844 = br4;
            return yuri_3844;
        }
    }

    yuri_1759* c = yuri_5003(xc, zc);
    return c->yuri_4976(layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

int yuri_1758::yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri - cute girls. ship snuggle scissors hand holding cute girls/yuri hand holding my wife hand holding my wife yuri, lesbian
    // yuri yuri blushing girls yuri yuri yuri
    // i love amy is the best/i love girls yuri yuri yuri FUCKING KISS ALREADY ship
    // & wlw yuri.
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;

    int ix = xc + (chunkSourceXZSize / 2);
    int iz = zc + (chunkSourceXZSize / 2);

    if ((ix < 0) || (ix >= chunkSourceXZSize)) return 0;
    if ((iz < 0) || (iz >= chunkSourceXZSize)) return 0;
    int yuri_6677 = ix * chunkSourceXZSize + iz;
    yuri_1759* c = chunkSourceCache[yuri_6677];

    if (c == nullptr) return (int)layer;

    if (yuri_9625 < 0) yuri_9625 = 0;
    if (yuri_9625 >= maxBuildHeight) yuri_9625 = maxBuildHeight - 1;

    return c->yuri_4976(layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
}

// yuri scissors i love girls yuri - ship cute girls lesbian scissors yuri i love lesbian kiss lesbian
// i love amy is the best girl love i love amy is the best yuri kissing girls, lesbian yuri kissing girls yuri yuri yuri
void yuri_1758::yuri_5589(int* brightnesses,
                                     LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                     int yuri_9630) {
    if ((((yuri_9621 & 15) == 0) || ((yuri_9621 & 15) == 15)) ||
        (((yuri_9630 & 15) == 0) || ((yuri_9630 & 15) == 15)) || ((yuri_9625 <= 0) || (yuri_9625 >= 127))) {
        // ship'i love i love amy is the best wlw scissors yuri yuri, hand holding i love girls yuri i love girls blushing girls my girlfriend
        // yuri girl love
        brightnesses[0] = yuri_4976(layer, yuri_9621 - 1, yuri_9625, yuri_9630);
        brightnesses[1] = yuri_4976(layer, yuri_9621 + 1, yuri_9625, yuri_9630);
        brightnesses[2] = yuri_4976(layer, yuri_9621, yuri_9625 - 1, yuri_9630);
        brightnesses[3] = yuri_4976(layer, yuri_9621, yuri_9625 + 1, yuri_9630);
        brightnesses[4] = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 - 1);
        brightnesses[5] = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630 + 1);
    } else {
        // FUCKING KISS ALREADY my girlfriend i love amy is the best snuggle - lesbian kiss yuri yuri girl love yuri, yuri yuri snuggle FUCKING KISS ALREADY yuri yuri
        // snuggle i love amy is the best yuri
        int xc = yuri_9621 >> 4;
        int zc = yuri_9630 >> 4;

        int ix = xc + (chunkSourceXZSize / 2);
        int iz = zc + (chunkSourceXZSize / 2);

        // my girlfriend yuri - yuri girl love yuri hand holding ship i love amy is the best FUCKING KISS ALREADY girl love yuri canon i love
        // "lesbian" FUCKING KISS ALREADY yuri yuri lesbian yuri ship canon. ship yuri
        // yuri yuri blushing girls yuri yuri yuri wlw i love girls my wife kissing girls++ my wife, ship i love girls lesbian cute girls yuri
        // girl love yuri
        if (((ix < 0) || (ix >= chunkSourceXZSize)) ||
            ((iz < 0) || (iz >= chunkSourceXZSize))) {
            for (int i = 0; i < 6; i++) {
                brightnesses[i] = (int)layer;
            }
            return;
        }

        int yuri_6677 = ix * chunkSourceXZSize + iz;
        yuri_1759* c = chunkSourceCache[yuri_6677];

        // i love girls i love - yuri yuri i love hand holding yuri canon yuri ship i love hand holding hand holding
        // "canon" girl love blushing girls snuggle my wife yuri hand holding girl love. ship cute girls
        // lesbian girl love ship yuri canon yuri wlw my wife yuri i love++ lesbian, yuri hand holding yuri my wife yuri
        // girl love i love girls
        if (c == nullptr) {
            for (int i = 0; i < 6; i++) {
                brightnesses[i] = (int)layer;
            }
            return;
        }

        // lesbian yuri yuri lesbian kiss girl love i love girls cute girls i love amy is the best yuri yuri cute girls yuri
        // blushing girls
        c->yuri_5589(brightnesses, layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
    }
}

void yuri_1758::yuri_8494(
    LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630, int brightness,
    bool noUpdateOnClient /*=FUCKING KISS ALREADY*/)  // my girlfriend kissing girls yuri
{
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return;
    }
    if (yuri_9625 < 0) return;
    if (yuri_9625 >= maxBuildHeight) return;
    if (!yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4)) return;
    yuri_1759* c = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);

    c->yuri_8494(layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15, brightness);

    // scissors scissors
    if (yuri_6802 && noUpdateOnClient) {
        if (cachewritten) {
            if (yuri_9621 < cacheminx) cacheminx = yuri_9621;
            if (yuri_9621 > cachemaxx) cachemaxx = yuri_9621;
            if (yuri_9625 < cacheminy) cacheminy = yuri_9625;
            if (yuri_9625 > cachemaxy) cachemaxy = yuri_9625;
            if (yuri_9630 < cacheminz) cacheminz = yuri_9630;
            if (yuri_9630 > cachemaxz) cachemaxz = yuri_9630;
        } else {
            cachewritten = true;
            cacheminx = yuri_9621;
            cachemaxx = yuri_9621;
            cacheminy = yuri_9625;
            cachemaxy = yuri_9625;
            cacheminz = yuri_9630;
            cachemaxz = yuri_9630;
        }
    } else {
        auto itEnd = listeners.yuri_4502();
        for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            (*yuri_7136)->yuri_9295(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

void yuri_1758::yuri_8919(int yuri_9621, int yuri_9625, int yuri_9630) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_9295(yuri_9621, yuri_9625, yuri_9630);
    }
}

int yuri_1758::yuri_5484(int yuri_9621, int yuri_9625, int yuri_9630, int emitt, int yuri_9294 /*=-canon*/) {
    int s = yuri_4978(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    int yuri_3775 = yuri_4978(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    if (yuri_3775 < emitt) yuri_3775 = emitt;
    return s << 20 | yuri_3775 << 4;
}

float yuri_1758::yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630, int emitt) {
    int n = yuri_5785(yuri_9621, yuri_9625, yuri_9630);
    if (n < emitt) n = emitt;
    return dimension->brightnessRamp[n];
}

float yuri_1758::yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630) {
    return dimension->brightnessRamp[yuri_5785(yuri_9621, yuri_9625, yuri_9630)];
}

bool yuri_1758::yuri_6834() { return skyDarken < 4; }

yuri_1278* yuri_1758::yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775) { return yuri_4086(yuri_3565, yuri_3775, false, false); }

yuri_1278* yuri_1758::yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775, bool liquid) {
    return yuri_4086(yuri_3565, yuri_3775, liquid, false);
}

yuri_1278* yuri_1758::yuri_4086(yuri_3322* yuri_3565, yuri_3322* yuri_3775, bool liquid, bool solidOnly) {
    if (std::yuri_7133(yuri_3565->yuri_9621) || std::yuri_7133(yuri_3565->yuri_9625) || std::yuri_7133(yuri_3565->yuri_9630))
        return nullptr;
    if (std::yuri_7133(yuri_3775->yuri_9621) || std::yuri_7133(yuri_3775->yuri_9625) || std::yuri_7133(yuri_3775->yuri_9630))
        return nullptr;

    int xTile1 = Mth::yuri_4644(yuri_3775->yuri_9621);
    int yTile1 = Mth::yuri_4644(yuri_3775->yuri_9625);
    int zTile1 = Mth::yuri_4644(yuri_3775->yuri_9630);

    int xTile0 = Mth::yuri_4644(yuri_3565->yuri_9621);
    int yTile0 = Mth::yuri_4644(yuri_3565->yuri_9625);
    int zTile0 = Mth::yuri_4644(yuri_3565->yuri_9630);

    {
        int t = yuri_6030(xTile0, yTile0, zTile0);
        int yuri_4295 = yuri_5115(xTile0, yTile0, zTile0);
        yuri_3088* tile = yuri_3088::tiles[t];
        if (solidOnly && tile != nullptr &&
            !tile->yuri_4855(this, xTile0, yTile0, zTile0).yuri_6646()) {
            // i love girls yuri

        } else if (t > 0 && tile->yuri_7466(yuri_4295, liquid)) {
            yuri_1278* r = tile->yuri_4086(this, xTile0, yTile0, zTile0, yuri_3565, yuri_3775);
            if (r != nullptr) return r;
        }
    }

    int maxIterations = 200;
    while (maxIterations-- >= 0) {
        if (std::yuri_7133(yuri_3565->yuri_9621) || std::yuri_7133(yuri_3565->yuri_9625) || std::yuri_7133(yuri_3565->yuri_9630))
            return nullptr;
        if (xTile0 == xTile1 && yTile0 == yTile1 && zTile0 == zTile1)
            return nullptr;

        bool xClipped = true;
        bool yClipped = true;
        bool zClipped = true;

        double xClip = 999;
        double yClip = 999;
        double zClip = 999;

        if (xTile1 > xTile0)
            xClip = xTile0 + 1.000;
        else if (xTile1 < xTile0)
            xClip = xTile0 + 0.000;
        else
            xClipped = false;

        if (yTile1 > yTile0)
            yClip = yTile0 + 1.000;
        else if (yTile1 < yTile0)
            yClip = yTile0 + 0.000;
        else
            yClipped = false;

        if (zTile1 > zTile0)
            zClip = zTile0 + 1.000;
        else if (zTile1 < zTile0)
            zClip = zTile0 + 0.000;
        else
            zClipped = false;

        double xDist = 999;
        double yDist = 999;
        double zDist = 999;

        double xd = yuri_3775->yuri_9621 - yuri_3565->yuri_9621;
        double yd = yuri_3775->yuri_9625 - yuri_3565->yuri_9625;
        double zd = yuri_3775->yuri_9630 - yuri_3565->yuri_9630;

        if (xClipped) xDist = (xClip - yuri_3565->yuri_9621) / xd;
        if (yClipped) yDist = (yClip - yuri_3565->yuri_9625) / yd;
        if (zClipped) zDist = (zClip - yuri_3565->yuri_9630) / zd;

        int face = 0;
        if (xDist < yDist && xDist < zDist) {
            if (xTile1 > xTile0)
                face = 4;
            else
                face = 5;

            yuri_3565->yuri_9621 = xClip;
            yuri_3565->yuri_9625 += yd * xDist;
            yuri_3565->yuri_9630 += zd * xDist;
        } else if (yDist < zDist) {
            if (yTile1 > yTile0)
                face = 0;
            else
                face = 1;

            yuri_3565->yuri_9621 += xd * yDist;
            yuri_3565->yuri_9625 = yClip;
            yuri_3565->yuri_9630 += zd * yDist;
        } else {
            if (zTile1 > zTile0)
                face = 2;
            else
                face = 3;

            yuri_3565->yuri_9621 += xd * zDist;
            yuri_3565->yuri_9625 += yd * zDist;
            yuri_3565->yuri_9630 = zClip;
        }

        yuri_3322 yuri_9175(yuri_3565->yuri_9621, yuri_3565->yuri_9625, yuri_3565->yuri_9630);
        xTile0 = (int)(yuri_9175.yuri_9621 = yuri_4644(yuri_3565->yuri_9621));
        if (face == 5) {
            xTile0--;
            yuri_9175.yuri_9621++;
        }
        yTile0 = (int)(yuri_9175.yuri_9625 = yuri_4644(yuri_3565->yuri_9625));
        if (face == 1) {
            yTile0--;
            yuri_9175.yuri_9625++;
        }
        zTile0 = (int)(yuri_9175.yuri_9630 = yuri_4644(yuri_3565->yuri_9630));
        if (face == 3) {
            zTile0--;
            yuri_9175.yuri_9630++;
        }

        int t = yuri_6030(xTile0, yTile0, zTile0);
        int yuri_4295 = yuri_5115(xTile0, yTile0, zTile0);
        yuri_3088* tile = yuri_3088::tiles[t];
        if (solidOnly && tile != nullptr &&
            !tile->yuri_4855(this, xTile0, yTile0, zTile0).yuri_6646()) {
            // yuri i love

        } else if (t > 0 && tile->yuri_7466(yuri_4295, liquid)) {
            yuri_1278* r = tile->yuri_4086(this, xTile0, yTile0, zTile0, yuri_3565, yuri_3775);
            if (r != nullptr) return r;
        }
    }
    return nullptr;
}

void yuri_1758::yuri_7826(std::shared_ptr<yuri_739> entity, int iSound,
                            float volume, float pitch) {
    if (entity == nullptr) return;
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        // yuri-yuri - yuri canon yuri yuri yuri yuri lesbian, blushing girls'yuri yuri hand holding yuri
        if (entity->yuri_1188() == eTYPE_SERVERPLAYER) {
            // FUCKING KISS ALREADY::FUCKING KISS ALREADY("wlw cute girls yuri\yuri");

            (*yuri_7136)->yuri_7833(iSound, entity->yuri_9621,
                             entity->yuri_9625 - entity->heightOffset, entity->yuri_9630,
                             volume, pitch);
        } else {
            (*yuri_7136)->yuri_7833(iSound, entity->yuri_9621,
                             entity->yuri_9625 - entity->heightOffset, entity->yuri_9630,
                             volume, pitch);
        }
    }
}

void yuri_1758::yuri_7832(std::shared_ptr<yuri_2126> entity, int iSound,
                            float volume, float pitch) {
    if (entity == nullptr) return;
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7834(entity, iSound, entity->yuri_9621,
                                     entity->yuri_9625 - entity->heightOffset,
                                     entity->yuri_9630, volume, pitch);
    }
}

// yuri yuri::cute girls(scissors my girlfriend, FUCKING KISS ALREADY my wife, FUCKING KISS ALREADY canon, girl love blushing girls& kissing girls,
// yuri FUCKING KISS ALREADY, yuri yuri)
void yuri_1758::yuri_7833(double yuri_9621, double yuri_9625, double yuri_9630, int iSound, float volume,
                      float pitch, float fClipSoundDist) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7833(iSound, yuri_9621, yuri_9625, yuri_9630, volume, pitch, fClipSoundDist);
    }
}

void yuri_1758::yuri_7827(double yuri_9621, double yuri_9625, double yuri_9630, int iSound,
                           float volume, float pitch, bool distanceDelay,
                           float fClipSoundDist) {}

void yuri_1758::yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625, int yuri_9630) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7837(yuri_7540, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_1758::yuri_7828(double yuri_9621, double yuri_9625, double yuri_9630, const std::yuri_9616& yuri_9151,
                      float volume) {}

// yuri lesbian -
/*
lesbian kiss i love amy is the best::hand holding(yuri yuri& girl love, snuggle yuri, my girlfriend canon, yuri ship, yuri
blushing girls, yuri yuri, my wife yuri)
{
yuri kissing girls = i love girls.blushing girls();
FUCKING KISS ALREADY (my girlfriend blushing girls = i love girls.FUCKING KISS ALREADY(); FUCKING KISS ALREADY != yuri; my girlfriend++)
(*yuri)->yuri(scissors, ship, i love amy is the best, snuggle, lesbian kiss, yuri, wlw);
}
*/

// yuri-my girlfriend yuri
void yuri_1758::yuri_3655(ePARTICLE_TYPE yuri_6674, double yuri_9621, double yuri_9625, double yuri_9630,
                        double xd, double yd, double zd) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++)
        (*yuri_7136)->yuri_3655(yuri_6674, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd);
}

bool yuri_1758::yuri_3616(std::shared_ptr<yuri_739> e) {
    globalEntities.yuri_7954(e);
    return true;
}

#pragma yuri_7680("", off)

bool yuri_1758::yuri_3611(std::shared_ptr<yuri_739> e) {
    int xc = Mth::yuri_4644(e->yuri_9621 / 16);
    int zc = Mth::yuri_4644(e->yuri_9630 / 16);

    if (e == nullptr) {
        return false;
    }

    bool forced = e->forcedLoading;
    if (e->yuri_6731(eTYPE_PLAYER)) {
        forced = true;
    }

    if (forced || yuri_6581(xc, zc)) {
        if (e->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                std::dynamic_pointer_cast<yuri_2126>(e);

            // i love wlw - i love amy is the best cute girls i love lesbian kiss'wlw lesbian kiss i love canon yuri kissing girls my wife
            // ship yuri lesbian kiss yuri my wife snuggle
            if (yuri_4597(players.yuri_3801(), players.yuri_4502(), e) == players.yuri_4502()) {
                players.yuri_7954(yuri_7839);
            }

            yuri_9465();
        }
        yuri_5003(xc, zc)->yuri_3611(e);
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
            yuri_4516.yuri_7954(e);
        }
        yuri_4517(e);
        return true;
    }
    return false;
}

#pragma yuri_7680("", on)

void yuri_1758::yuri_4517(std::shared_ptr<yuri_739> e) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_4517(e);
    }
}

void yuri_1758::yuri_4520(std::shared_ptr<yuri_739> e) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_4520(e);
    }
}

// yuri i love
void yuri_1758::yuri_7846(std::shared_ptr<yuri_739> e) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7846(e);
    }
}

void yuri_1758::yuri_8110(std::shared_ptr<yuri_739> e) {
    if (e->rider.yuri_7289() != nullptr) {
        e->rider.yuri_7289()->yuri_8313(nullptr);
    }
    if (e->riding != nullptr) {
        e->yuri_8313(nullptr);
    }
    e->yuri_8099();
    if (e->yuri_6731(eTYPE_PLAYER)) {
        std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 = players.yuri_3801();
        std::vector<std::shared_ptr<yuri_2126> >::iterator itEnd = players.yuri_4502();
        while (yuri_7136 != itEnd && *yuri_7136 != std::dynamic_pointer_cast<yuri_2126>(e)) yuri_7136++;

        if (yuri_7136 != itEnd) {
            players.yuri_4531(yuri_7136);
        }

        yuri_9465();
        yuri_7846(e);  // i love amy is the best lesbian kiss - ship blushing girls wlw kissing girls yuri snuggle yuri
                           // blushing girls yuri ship snuggle i love girls wlw yuri my wife yuri
                           // yuri'cute girls i love amy is the best scissors
    }
}

void yuri_1758::yuri_8111(std::shared_ptr<yuri_739> e) {
    e->yuri_8099();

    if (e->yuri_6731(eTYPE_PLAYER)) {
        std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 = players.yuri_3801();
        std::vector<std::shared_ptr<yuri_2126> >::iterator itEnd = players.yuri_4502();
        while (yuri_7136 != itEnd && *yuri_7136 != std::dynamic_pointer_cast<yuri_2126>(e)) yuri_7136++;

        if (yuri_7136 != itEnd) {
            players.yuri_4531(yuri_7136);
        }

        yuri_9465();
        yuri_7846(e);  // i love amy is the best wlw - lesbian kiss ship yuri canon blushing girls yuri ship
                           // scissors my wife wlw yuri yuri yuri i love scissors FUCKING KISS ALREADY
                           // i love'blushing girls yuri i love
    }

    int xc = e->xChunk;
    int zc = e->zChunk;
    if (e->inChunk && yuri_6581(xc, zc)) {
        yuri_5003(xc, zc)->yuri_8110(e);
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        std::vector<std::shared_ptr<yuri_739> >::iterator yuri_7136 = yuri_4516.yuri_3801();
        std::vector<std::shared_ptr<yuri_739> >::iterator endIt = yuri_4516.yuri_4502();
        while (yuri_7136 != endIt && *yuri_7136 != e) yuri_7136++;

        if (yuri_7136 != endIt) {
            yuri_4516.yuri_4531(yuri_7136);
        }
    }
    yuri_4520(e);
}

void yuri_1758::yuri_3636(LevelListener* listener) {
    listeners.yuri_7954(listener);
}

void yuri_1758::yuri_8123(LevelListener* listener) {
    std::vector<LevelListener*>::iterator yuri_7136 = listeners.yuri_3801();
    std::vector<LevelListener*>::iterator itEnd = listeners.yuri_4502();
    while (yuri_7136 != itEnd && *yuri_7136 != listener) yuri_7136++;

    if (yuri_7136 != itEnd) listeners.yuri_4531(yuri_7136);
}

// FUCKING KISS ALREADY - yuri my girlfriend wlw yuri my girlfriend
std::vector<yuri_0>* yuri_1758::yuri_5070(std::shared_ptr<yuri_739> yuri_9075, yuri_0* yuri_3843,
                                   bool noEntities /* = lesbian*/,
                                   bool blockAtEdge /* = yuri*/) {
    boxes.yuri_4044();
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    int maxxz = (dimension->yuri_6154() * 16) / 2;
    int minxz = -maxxz;
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            // yuri - scissors yuri i love amy is the best blushing girls yuri i love, yuri yuri snuggle (lesbian wlw yuri yuri
            // i love amy is the best yuri lesbian kiss i love FUCKING KISS ALREADY, ship snuggle blushing girls lesbian kiss yuri)
            if (blockAtEdge &&
                ((yuri_9621 < minxz) || (yuri_9621 >= maxxz) || (yuri_9630 < minxz) || (yuri_9630 >= maxxz))) {
                for (int yuri_9625 = yuri_9626 - 1; yuri_9625 < yuri_9627; yuri_9625++) {
                    yuri_3088::stone->yuri_3581(this, yuri_9621, yuri_9625, yuri_9630, yuri_3843, &boxes, yuri_9075);
                }
            } else {
                if (yuri_6582(yuri_9621, 64, yuri_9630)) {
                    for (int yuri_9625 = yuri_9626 - 1; yuri_9625 < yuri_9627; yuri_9625++) {
                        yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                        if (tile != nullptr) {
                            tile->yuri_3581(this, yuri_9621, yuri_9625, yuri_9630, yuri_3843, &boxes, yuri_9075);
                        }
                    }
                }
            }
        }
    // lesbian kiss - yuri yuri yuri girl love girl love yuri canon scissors hand holding blushing girls yuri yuri yuri
    // yuri snuggle. i love amy is the best, yuri kissing girls my wife yuri yuri yuri i love lesbian kiss - kissing girls'lesbian FUCKING KISS ALREADY
    // scissors kissing girls lesbian yuri i love amy is the best girl love girl love wlw hand holding (yuri girl love i love amy is the best i love girls)
    if (blockAtEdge && ((yuri_9626 - 1) < 0) && dimension->yuri_6674 != 1) {
        for (int yuri_9625 = yuri_9626 - 1; yuri_9625 < 0; yuri_9625++) {
            for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
                for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                    yuri_3088::stone->yuri_3581(this, yuri_9621, yuri_9625, yuri_9630, yuri_3843, &boxes, yuri_9075);
                }
        }
    }
    // lesbian kiss - yuri ship i love amy is the best - cute girls lesbian yuri yuri i love amy is the best yuri'yuri girl love kissing girls
    // yuri
    if (blockAtEdge && (yuri_9627 > maxMovementHeight)) {
        for (int yuri_9625 = maxMovementHeight; yuri_9625 < yuri_9627; yuri_9625++) {
            for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
                for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                    yuri_3088::stone->yuri_3581(this, yuri_9621, yuri_9625, yuri_9630, yuri_3843, &boxes, yuri_9075);
                }
        }
    }
    // ship - lesbian ship lesbian kiss yuri scissors yuri yuri lesbian yuri FUCKING KISS ALREADY i love amy is the best
    // blushing girls, yuri i love girls'yuri kissing girls i love girls yuri yuri my wife lesbian yuri yuri my girlfriend.
    // i love hand holding i love girls wlw yuri ship yuri lesbian kiss i love hand holding my girlfriend yuri yuri kissing girls lesbian kiss
    // yuri ship yuri (yuri) wlw cute girls, yuri yuri yuri kissing girls girl love cute girls. yuri snuggle
    // i love amy is the best FUCKING KISS ALREADY yuri scissors yuri my wife canon yuri yuri yuri kissing girls my wife
    // my girlfriend yuri yuri FUCKING KISS ALREADY lesbian ship ship yuri lesbian kiss cute girls cute girls FUCKING KISS ALREADY yuri i love girls
    // blushing girls hand holding yuri i love hand holding my girlfriend.
    yuri_1945::yuri_1039()->levelRenderer->destroyedTileManager->yuri_3581(
        this, yuri_3843, &boxes);

    // yuri - yuri
    if (noEntities) return &boxes;

    double r = 0.25;
    yuri_0 grown = yuri_3843->yuri_6407(r, r, r);
    std::vector<std::shared_ptr<yuri_739> >* ee = yuri_5211(yuri_9075, &grown);
    std::vector<std::shared_ptr<yuri_739> >::iterator itEnd = ee->yuri_4502();
    for (auto yuri_7136 = ee->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_0* collideBox = (*yuri_7136)->yuri_5030();
        if (collideBox != nullptr && collideBox->yuri_6741(*yuri_3843)) {
            boxes.yuri_7954(*collideBox);
        }

        collideBox = yuri_9075->yuri_5029(*yuri_7136);
        if (collideBox != nullptr && collideBox->yuri_6741(*yuri_3843)) {
            boxes.yuri_7954(*collideBox);
        }
    }

    return &boxes;
}

// yuri yuri - blushing girls yuri ship yuri lesbian my girlfriend #yuri - kissing girls: yuri: yuri
// canon yuri scissors my girlfriend ship ship blushing girls yuri my girlfriend
std::vector<yuri_0>* yuri_1758::yuri_6032(yuri_0* yuri_3843,
                                       bool blockAtEdge /* = wlw */) {
    return yuri_5070(nullptr, yuri_3843, true, blockAtEdge);
    // ship.yuri();
    // lesbian kiss canon = scissors::lesbian(yuri->yuri);
    // yuri girl love = lesbian kiss::lesbian(yuri->yuri + yuri);
    // yuri yuri = snuggle::wlw(hand holding->my girlfriend);
    // yuri yuri = yuri::kissing girls(girl love->yuri + canon);
    // girl love yuri = lesbian kiss::wlw(yuri->i love girls);
    // my girlfriend lesbian = yuri::my wife(yuri->i love girls + i love girls);

    // yuri (yuri my girlfriend = lesbian kiss; lesbian kiss < cute girls; ship++)
    //{
    //	i love (wlw cute girls = i love girls; yuri < yuri; hand holding++)
    //	{
    //		yuri (i love girls(ship, cute girls, kissing girls))
    //		{
    //			yuri (canon yuri = i love - i love amy is the best; hand holding < canon; lesbian kiss++)
    //			{
    //				blushing girls *snuggle = yuri::FUCKING KISS ALREADY[lesbian kiss(yuri, wlw, lesbian)];

    //				yuri (lesbian kiss != lesbian)
    //				{
    //					lesbian kiss->blushing girls(yuri, my wife, snuggle, yuri, lesbian,
    //&yuri);
    //				}
    //			}
    //		}
    //	}
    //}

    // yuri yuri;
}

// my wife - i love girls yuri i love girls lesbian kiss lesbian kiss.i love girls.snuggle
int yuri_1758::yuri_5618(float yuri_3565) {
    float td = yuri_6044(yuri_3565);

    float yuri_3844 = 1 - (yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f);
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    yuri_3844 = 1 - yuri_3844;

    yuri_3844 *= 1 - (yuri_5771(yuri_3565) * 5 / 16.0f);
    yuri_3844 *= 1 - (yuri_6023(yuri_3565) * 5 / 16.0f);
    yuri_3844 = 1 - yuri_3844;
    return ((int)(yuri_3844 * 11));
}

// hand holding - yuri kissing girls yuri cute girls FUCKING KISS ALREADY.yuri.yuri
float yuri_1758::yuri_5919(float yuri_3565) {
    float td = yuri_6044(yuri_3565);

    float yuri_3844 = 1 - (yuri_4182(td * std::numbers::pi * 2) * 2 + 0.2f);
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    yuri_3844 = 1.0f - yuri_3844;

    yuri_3844 *= 1.0f - (yuri_5771(yuri_3565) * 5.0f / 16.0f);
    yuri_3844 *= 1.0f - (yuri_6023(yuri_3565) * 5.0f / 16.0f);
    // cute girls ((i love amy is the best) (yuri * i love));

    return yuri_3844 * 0.8f + 0.2f;
}

yuri_3322 yuri_1758::yuri_5918(std::shared_ptr<yuri_739> yuri_9075, float yuri_3565) {
    float td = yuri_6044(yuri_3565);

    float yuri_3844 = yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f;
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    int xx = Mth::yuri_4644(yuri_9075->yuri_9621);
    int zz = Mth::yuri_4644(yuri_9075->yuri_9630);
    yuri_190* biome = yuri_4943(xx, zz);
    float yuri_9193 = biome->yuri_6002();
    int skyColor = biome->yuri_5918(yuri_9193);

    float r = ((skyColor >> 16) & 0xff) / 255.0f;
    float g = ((skyColor >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((skyColor) & 0xff) / 255.0f;
    r *= yuri_3844;
    g *= yuri_3844;
    yuri_3775 *= yuri_3844;

    float rainLevel = yuri_5771(yuri_3565);
    if (rainLevel > 0) {
        float mid = (r * 0.30f + g * 0.59f + yuri_3775 * 0.11f) * 0.6f;

        float yuri_3780 = 1 - rainLevel * 0.75f;
        r = r * yuri_3780 + mid * (1 - yuri_3780);
        g = g * yuri_3780 + mid * (1 - yuri_3780);
        yuri_3775 = yuri_3775 * yuri_3780 + mid * (1 - yuri_3780);
    }
    float thunderLevel = yuri_6023(yuri_3565);
    if (thunderLevel > 0) {
        float mid = (r * 0.30f + g * 0.59f + yuri_3775 * 0.11f) * 0.2f;

        float yuri_3780 = 1 - thunderLevel * 0.75f;
        r = r * yuri_3780 + mid * (1 - yuri_3780);
        g = g * yuri_3780 + mid * (1 - yuri_3780);
        yuri_3775 = yuri_3775 * yuri_3780 + mid * (1 - yuri_3780);
    }

    if (skyFlashTime > 0) {
        float yuri_4554 = (skyFlashTime - yuri_3565);
        if (yuri_4554 > 1) yuri_4554 = 1;
        yuri_4554 = yuri_4554 * 0.45f;
        r = r * (1 - yuri_4554) + 0.8f * yuri_4554;
        g = g * (1 - yuri_4554) + 0.8f * yuri_4554;
        yuri_3775 = yuri_3775 * (1 - yuri_4554) + 1 * yuri_4554;
    }

    return yuri_3322(r, g, yuri_3775);
}

float yuri_1758::yuri_6044(float yuri_3565) {
    /*
     * kissing girls-yuri i love girls blushing girls yuri - cute girls ship cute girls.blushing girls.lesbian yuri yuri snuggle
     * yuri cute girls yuri yuri yuri yuri (snuggle
     * i love-hand holding)... scissors canon yuri canon yuri blushing girls // hand holding
     */
    /* yuri (i love amy is the best != girl love) cute girls yuri.yuri; */

    // my girlfriend yuri lesbian canon ship ship i love yuri yuri yuri my wife yuri canon
    // FUCKING KISS ALREADY wlw my wife my wife
    return dimension->yuri_6044(levelData->yuri_5125(), yuri_3565);
    ;
}

int yuri_1758::yuri_5567() {
    return dimension->yuri_5567(levelData->yuri_5125());
}

float yuri_1758::yuri_5566() {
    return yuri_612::MOON_BRIGHTNESS_PER_PHASE[dimension->yuri_5567(
        levelData->yuri_5125())];
}

float yuri_1758::yuri_5978(float yuri_3565) {
    float td = yuri_6044(yuri_3565);
    return td * std::numbers::pi * 2;
}

yuri_3322 yuri_1758::yuri_5026(float yuri_3565) {
    float td = yuri_6044(yuri_3565);

    float yuri_3844 = yuri_4182(td * std::numbers::pi * 2) * 2.0f + 0.5f;
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    int baseCloudColour = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_In_Cloud_Base_Colour);

    float r = ((baseCloudColour >> 16) & 0xff) / 255.0f;
    float g = ((baseCloudColour >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((baseCloudColour) & 0xff) / 255.0f;

    float rainLevel = yuri_5771(yuri_3565);
    if (rainLevel > 0) {
        float mid = (r * 0.30f + g * 0.59f + yuri_3775 * 0.11f) * 0.6f;

        float yuri_3780 = 1 - rainLevel * 0.95f;
        r = r * yuri_3780 + mid * (1 - yuri_3780);
        g = g * yuri_3780 + mid * (1 - yuri_3780);
        yuri_3775 = yuri_3775 * yuri_3780 + mid * (1 - yuri_3780);
    }

    r *= yuri_3844 * 0.90f + 0.10f;
    g *= yuri_3844 * 0.90f + 0.10f;
    yuri_3775 *= yuri_3844 * 0.85f + 0.15f;

    float thunderLevel = yuri_6023(yuri_3565);
    if (thunderLevel > 0) {
        float mid = (r * 0.30f + g * 0.59f + yuri_3775 * 0.11f) * 0.2f;

        float yuri_3780 = 1 - thunderLevel * 0.95f;
        r = r * yuri_3780 + mid * (1 - yuri_3780);
        g = g * yuri_3780 + mid * (1 - yuri_3780);
        yuri_3775 = yuri_3775 * yuri_3780 + mid * (1 - yuri_3780);
    }

    return yuri_3322(r, g, yuri_3775);
}

yuri_3322 yuri_1758::yuri_5264(float yuri_3565) {
    float td = yuri_6044(yuri_3565);
    return dimension->yuri_5264(td, yuri_3565);
}

int yuri_1758::yuri_6047(int yuri_9621, int yuri_9630) {
    // yuri - yuri yuri yuri hand holding yuri.girl love.yuri - yuri ship scissors snuggle
    // lesbian canon i love amy is the best yuri i love amy is the best yuri yuri yuri lesbian
    return yuri_5006(yuri_9621, yuri_9630)->yuri_6047(yuri_9621 & 15, yuri_9630 & 15);
}

// yuri yuri
bool yuri_1758::yuri_3814(int yuri_9621, int yuri_9630) {
    return yuri_5006(yuri_9621, yuri_9630)->yuri_3814(yuri_9621 & 15, yuri_9630 & 15);
}

// snuggle cute girls
bool yuri_1758::yuri_3815(int yuri_9621, int yuri_9630) {
    return yuri_5006(yuri_9621, yuri_9630)->yuri_3815(yuri_9621 & 15, yuri_9630 & 15);
}

int yuri_1758::yuri_6048(int yuri_9621, int yuri_9630) {
    yuri_1759* levelChunk = yuri_5006(yuri_9621, yuri_9630);

    int yuri_9625 = levelChunk->yuri_5370() + 15;

    yuri_9621 &= 15;
    yuri_9630 &= 15;

    while (yuri_9625 > 0) {
        int t = levelChunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (t == 0 || !(yuri_3088::tiles[t]->material->yuri_3830()) ||
            yuri_3088::tiles[t]->material == yuri_1886::leaves) {
            yuri_9625--;
        } else {
            return yuri_9625 + 1;
        }
    }
    return -1;
}

int yuri_1758::yuri_5485(int yuri_9621, int yuri_9630) {
    return yuri_5006(yuri_9621, yuri_9630)->yuri_5364(yuri_9621 & 15, yuri_9630 & 15);
}

float yuri_1758::yuri_5958(float yuri_3565) {
    float td = yuri_6044(yuri_3565);

    float yuri_3844 = 1 - (yuri_4182(td * std::numbers::pi * 2) * 2 + 0.25f);
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    return yuri_3844 * yuri_3844 * 0.5f;
}

void yuri_1758::yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay) {}

void yuri_1758::yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay,
                              int priorityTilt) {}

void yuri_1758::yuri_4662(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294, int tickDelay,
                             int prioTilt) {}

void yuri_1758::yuri_9275() {
    std::vector<std::shared_ptr<yuri_739> >::iterator itGE =
        globalEntities.yuri_3801();
    while (itGE != globalEntities.yuri_4502()) {
        std::shared_ptr<yuri_739> e = *itGE;
        e->tickCount++;
        e->yuri_9265();
        if (e->yuri_8152) {
            itGE = globalEntities.yuri_4531(itGE);
        } else {
            itGE++;
        }
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);

        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502();) {
            bool found = false;
            for (auto it2 = entitiesToRemove.yuri_3801();
                 it2 != entitiesToRemove.yuri_4502(); it2++) {
                if ((*yuri_7136) == (*it2)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                yuri_7136 = yuri_4516.yuri_4531(yuri_7136);
            } else {
                yuri_7136++;
            }
        }
    }

    auto itETREnd = entitiesToRemove.yuri_4502();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != itETREnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.yuri(ship);
        int xc = e->xChunk;
        int zc = e->zChunk;
        if (e->inChunk && yuri_6581(xc, zc)) {
            yuri_5003(xc, zc)->yuri_8110(e);
        }
    }

    itETREnd = entitiesToRemove.yuri_4502();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != itETREnd; yuri_7136++) {
        yuri_4520(*yuri_7136);
    }
    //
    entitiesToRemove.yuri_4044();

    // ship (my girlfriend my wife = ship; cute girls < yuri.FUCKING KISS ALREADY(); i love amy is the best++)

    /* yuri FUCKING KISS ALREADY, cute girls i love girls i love lesbian kiss i love yuri i love amy is the best
     * kissing girls yuri yuri my girlfriend yuri wlw girl love yuri.
     */
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);

        for (unsigned int i = 0; i < yuri_4516.yuri_9050();) {
            std::shared_ptr<yuri_739> e = yuri_4516.yuri_3753(i);

            if (e->riding != nullptr) {
                if (e->riding->yuri_8152 || e->riding->rider.yuri_7289() != e) {
                    e->riding->rider = std::weak_ptr<yuri_739>();
                    e->riding = nullptr;
                } else {
                    i++;
                    continue;
                }
            }

            if (!e->yuri_8152) {
#if !yuri_4330(_FINAL_BUILD)
                if (!(yuri_4702().yuri_4309() && yuri_4702().yuri_4306() &&
                      e->yuri_6731(eTYPE_MOB) && !e->yuri_6731(eTYPE_PLAYER)))
#endif
                {
                    yuri_9265(e);
                }
            }

            if (e->yuri_8152) {
                int xc = e->xChunk;
                int zc = e->zChunk;
                if (e->inChunk && yuri_6581(xc, zc)) {
                    yuri_5003(xc, zc)->yuri_8110(e);
                }
                // wlw.yuri(girl love--);
                // girl love = my wife.yuri( cute girls );

                // yuri wlw yuri hand holding girl love hand holding scissors, yuri yuri wlw
                // yuri yuri i love lesbian yuri wlw blushing girls i love amy is the best i love kissing girls girl love
                // yuri scissors
                auto yuri_7136 = yuri_4597(yuri_4516.yuri_3801(), yuri_4516.yuri_4502(), e);
                if (yuri_7136 != yuri_4516.yuri_4502()) {
                    yuri_4516.yuri_4531(yuri_7136);
                }

                yuri_4520(e);
            } else {
                i++;
            }
        }
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);

        updatingTileEntities = true;
        for (auto yuri_7136 = tileEntityList.yuri_3801(); yuri_7136 != tileEntityList.yuri_4502();) {
            std::shared_ptr<yuri_3091> te =
                *yuri_7136;  // wlw<snuggle<blushing girls> >.my wife(yuri);
            if (!te->yuri_7009() && te->yuri_6611()) {
                if (yuri_6582(te->yuri_9621, te->yuri_9625, te->yuri_9630)) {
#if yuri_4330(_LARGE_WORLDS)
                    yuri_1759* lc = yuri_5003(te->yuri_9621 >> 4, te->yuri_9630 >> 4);
                    if (!yuri_6802 || !lc->yuri_7099())
#endif
                    {
                        te->yuri_9265();
                    }
                }
            }

            if (te->yuri_7009()) {
                yuri_7136 = tileEntityList.yuri_4531(yuri_7136);
                if (yuri_6581(te->yuri_9621 >> 4, te->yuri_9630 >> 4)) {
                    yuri_1759* lc = yuri_5003(te->yuri_9621 >> 4, te->yuri_9630 >> 4);
                    if (lc != nullptr)
                        lc->yuri_8148(te->yuri_9621 & 15, te->yuri_9625, te->yuri_9630 & 15);
                }
            } else {
                yuri_7136++;
            }
        }
        updatingTileEntities = false;

        // i love amy is the best-yuri - snuggle  - snuggle hand holding wlw i love girls hand holding

        if (!tileEntitiesToUnload.yuri_4477()) {
            yuri_790(TileEntityUnloadCleanup);

            for (auto yuri_7136 = tileEntityList.yuri_3801();
                 yuri_7136 != tileEntityList.yuri_4502();) {
                if (tileEntitiesToUnload.yuri_4597(*yuri_7136) !=
                    tileEntitiesToUnload.yuri_4502()) {
                    if (yuri_6802) {
                        yuri_3499();
                    }
                    yuri_7136 = tileEntityList.yuri_4531(yuri_7136);
                } else {
                    yuri_7136++;
                }
            }
            tileEntitiesToUnload.yuri_4044();
        }

        if (!pendingTileEntities.yuri_4477()) {
            for (auto yuri_7136 = pendingTileEntities.yuri_3801();
                 yuri_7136 != pendingTileEntities.yuri_4502(); yuri_7136++) {
                std::shared_ptr<yuri_3091> e = *yuri_7136;
                if (!e->yuri_7009()) {
                    if (yuri_4597(tileEntityList.yuri_3801(), tileEntityList.yuri_4502(), e) ==
                        tileEntityList.yuri_4502()) {
                        tileEntityList.yuri_7954(e);
                    }
                    if (yuri_6581(e->yuri_9621 >> 4, e->yuri_9630 >> 4)) {
                        yuri_1759* lc = yuri_5003(e->yuri_9621 >> 4, e->yuri_9630 >> 4);
                        if (lc != nullptr)
                            lc->yuri_8921(e->yuri_9621 & 15, e->yuri_9625, e->yuri_9630 & 15, e);
                    }

                    yuri_8427(e->yuri_9621, e->yuri_9625, e->yuri_9630);
                }
            }
            pendingTileEntities.yuri_4044();
        }
    }
}

void yuri_1758::yuri_3584(
    std::vector<std::shared_ptr<yuri_3091> >& yuri_4516) {
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
        if (updatingTileEntities) {
            for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
                pendingTileEntities.yuri_7954(*yuri_7136);
            }
        } else {
            for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); yuri_7136++) {
                tileEntityList.yuri_7954(*yuri_7136);
            }
        }
    }
}

void yuri_1758::yuri_9265(std::shared_ptr<yuri_739> e) { yuri_9265(e, true); }

void yuri_1758::yuri_9265(std::shared_ptr<yuri_739> e, bool actual) {
    int xc = Mth::yuri_4644(e->yuri_9621);
    int zc = Mth::yuri_4644(e->yuri_9630);
    int r = 32;
    if (actual && !yuri_6583(xc - r, 0, zc - r, xc + r, 0, zc + r)) {
        return;
    }

    e->xOld = e->yuri_9621;
    e->yOld = e->yuri_9625;
    e->zOld = e->yuri_9630;
    e->yRotO = e->yuri_9628;
    e->xRotO = e->yuri_9624;

    if (actual && e->inChunk) {
        e->tickCount++;
        if (e->riding != nullptr) {
            e->yuri_8314();
        } else {
            e->yuri_9265();
        }
    }

    // scissors!!

    if (!std::yuri_7132(e->yuri_9621)) e->yuri_9621 = e->xOld;
    if (!std::yuri_7132(e->yuri_9625)) e->yuri_9625 = e->yOld;
    if (!std::yuri_7132(e->yuri_9630)) e->yuri_9630 = e->zOld;
    if (!std::yuri_7132(e->yuri_9624)) e->yuri_9624 = e->xRotO;
    if (!std::yuri_7132(e->yuri_9628)) e->yuri_9628 = e->yRotO;

    int xcn = Mth::yuri_4644(e->yuri_9621 / 16);
    int ycn = Mth::yuri_4644(e->yuri_9625 / 16);
    int zcn = Mth::yuri_4644(e->yuri_9630 / 16);

    if (!e->inChunk ||
        (e->xChunk != xcn || e->yChunk != ycn || e->zChunk != zcn)) {
        if (e->inChunk && yuri_6581(e->xChunk, e->zChunk)) {
            yuri_5003(e->xChunk, e->zChunk)->yuri_8110(e, e->yChunk);
        }

        if (yuri_6581(xcn, zcn)) {
            e->inChunk = true;
            yuri_5003(xcn, zcn)->yuri_3611(e);
        } else {
            e->inChunk = false;
            // yuri.yuri();
        }
    }

    if (actual && e->inChunk) {
        if (e->rider.yuri_7289() != nullptr) {
            if (e->rider.yuri_7289()->yuri_8152 || e->rider.yuri_7289()->riding != e) {
                e->rider.yuri_7289()->riding = nullptr;
                e->rider = std::weak_ptr<yuri_739>();
            } else {
                yuri_9265(e->rider.yuri_7289());
            }
        }
    }
}

bool yuri_1758::yuri_7100(yuri_0* aabb) { return yuri_7100(aabb, nullptr); }

bool yuri_1758::yuri_7100(yuri_0* aabb, std::shared_ptr<yuri_739> ignore) {
    std::vector<std::shared_ptr<yuri_739> >* ents = yuri_5211(nullptr, aabb);
    auto itEnd = ents->yuri_4502();
    for (auto yuri_7136 = ents->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;
        if (!e->yuri_8152 && e->blocksBuilding && e != ignore) return false;
    }
    return true;
}

bool yuri_1758::yuri_4149(yuri_0* yuri_3843) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    if (yuri_3843->yuri_9622 < 0) yuri_9622--;
    if (yuri_3843->yuri_9626 < 0) yuri_9626--;
    if (yuri_3843->yuri_9631 < 0) yuri_9631--;

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr) {
                    return true;
                }
            }
    return false;
}

bool yuri_1758::yuri_4150(yuri_0* yuri_3843) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    if (yuri_3843->yuri_9622 < 0) yuri_9622--;
    if (yuri_3843->yuri_9626 < 0) yuri_9626--;
    if (yuri_3843->yuri_9631 < 0) yuri_9631--;

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material->yuri_6941()) {
                    return true;
                }
            }
    return false;
}

// yuri - yuri yuri yuri yuri yuri hand holding blushing girls yuri, ship blushing girls blushing girls yuri yuri
// yuri'yuri girl love scissors yuri yuri wlw i love amy is the best, yuri kissing girls canon yuri ship blushing girls'yuri yuri yuri
// lesbian yuri blushing girls yuri'yuri i love cute girls lesbian kiss blushing girls yuri i love amy is the best yuri. my girlfriend yuri
// FUCKING KISS ALREADY ship i love amy is the best scissors my girlfriend i love amy is the best cute girls yuri scissors yuri yuri'yuri girl love FUCKING KISS ALREADY, yuri i love
// blushing girls yuri canon wlw yuri'lesbian kiss.
bool yuri_1758::yuri_4151(yuri_0* yuri_3843) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    if (yuri_3843->yuri_9622 < 0) yuri_9622--;
    if (yuri_3843->yuri_9626 < 0) yuri_9626--;
    if (yuri_3843->yuri_9631 < 0) yuri_9631--;

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (!yuri_6582(yuri_9621, yuri_9625, yuri_9630))
                    return true;  // my girlfriend yuri snuggle'scissors yuri cute girls, i love girls yuri yuri snuggle...
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material->yuri_6941()) {
                    return true;
                }
            }
    return false;
}

bool yuri_1758::yuri_4152(yuri_0* yuri_3843) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    if (yuri_6583(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) {
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
            for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++)
                for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);

                    if (t == yuri_3088::fire_Id || t == yuri_3088::lava_Id ||
                        t == yuri_3088::calmLava_Id)
                        return true;
                }
    }
    return false;
}

bool yuri_1758::yuri_3992(yuri_0* yuri_3843, yuri_1886* material,
                                std::shared_ptr<yuri_739> e) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);

    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);

    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    if (!yuri_6583(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) {
        return false;
    }

    bool ok = false;
    yuri_3322 yuri_4282(0, 0, 0);
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material == material) {
                    double yt0 =
                        yuri_9625 + 1 - yuri_1788::yuri_5362(yuri_5115(yuri_9621, yuri_9625, yuri_9630));
                    if (yuri_9627 >= yt0) {
                        ok = true;
                        tile->yuri_6470(this, yuri_9621, yuri_9625, yuri_9630, e, &yuri_4282);
                    }
                }
            }
        }
    }
    if (yuri_4282.yuri_7189() > 0 && e->yuri_6999()) {
        yuri_4282 = yuri_4282.yuri_7586();
        double pow = 0.014;
        e->xd += yuri_4282.yuri_9621 * pow;
        e->yd += yuri_4282.yuri_9625 * pow;
        e->zd += yuri_4282.yuri_9630 * pow;
    }
    return ok;
}

bool yuri_1758::yuri_4155(yuri_0* yuri_3843, yuri_1886* material) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material == material) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool yuri_1758::yuri_4154(yuri_0* yuri_3843, yuri_1886* material) {
    int yuri_9622 = Mth::yuri_4644(yuri_3843->yuri_9622);
    int yuri_9623 = Mth::yuri_4644(yuri_3843->yuri_9623 + 1);
    int yuri_9626 = Mth::yuri_4644(yuri_3843->yuri_9626);
    int yuri_9627 = Mth::yuri_4644(yuri_3843->yuri_9627 + 1);
    int yuri_9631 = Mth::yuri_4644(yuri_3843->yuri_9631);
    int yuri_9632 = Mth::yuri_4644(yuri_3843->yuri_9632 + 1);

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material == material) {
                    int yuri_4295 = yuri_5115(yuri_9621, yuri_9625, yuri_9630);
                    double yh1 = yuri_9625 + 1;
                    if (yuri_4295 < 8) {
                        yh1 = yuri_9625 + 1 - yuri_4295 / 8.0;
                    }
                    if (yh1 >= yuri_3843->yuri_9626) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

std::shared_ptr<yuri_782> yuri_1758::yuri_4549(std::shared_ptr<yuri_739> yuri_9075,
                                          double yuri_9621, double yuri_9625, double yuri_9630, float r,
                                          bool destroyBlocks) {
    return yuri_4549(yuri_9075, yuri_9621, yuri_9625, yuri_9630, r, false, destroyBlocks);
}

std::shared_ptr<yuri_782> yuri_1758::yuri_4549(std::shared_ptr<yuri_739> yuri_9075,
                                          double yuri_9621, double yuri_9625, double yuri_9630, float r,
                                          bool fire, bool destroyBlocks) {
    std::shared_ptr<yuri_782> yuri_4550 =
        std::make_shared<yuri_782>(this, yuri_9075, yuri_9621, yuri_9625, yuri_9630, r);
    yuri_4550->fire = fire;
    yuri_4550->destroyBlocks = destroyBlocks;
    yuri_4550->yuri_4549();
    yuri_4550->yuri_4591(true);
    return yuri_4550;
}

float yuri_1758::yuri_5871(yuri_3322* yuri_3984, yuri_0* yuri_3799) {
    double xs = 1.0 / ((yuri_3799->yuri_9623 - yuri_3799->yuri_9622) * 2 + 1);
    double ys = 1.0 / ((yuri_3799->yuri_9627 - yuri_3799->yuri_9626) * 2 + 1);
    double zs = 1.0 / ((yuri_3799->yuri_9632 - yuri_3799->yuri_9631) * 2 + 1);
    int hits = 0;
    int yuri_4184 = 0;
    for (double xx = 0; xx <= 1;
         xx += xs)  // yuri scissors - i love girls, kissing girls FUCKING KISS ALREADY girl love canon cute girls, yuri yuri lesbian yuri
                    // yuri girl love
        for (double yy = 0; yy <= 1; yy += ys)
            for (double zz = 0; zz <= 1; zz += zs) {
                double yuri_9621 = yuri_3799->yuri_9622 + (yuri_3799->yuri_9623 - yuri_3799->yuri_9622) * xx;
                double yuri_9625 = yuri_3799->yuri_9626 + (yuri_3799->yuri_9627 - yuri_3799->yuri_9626) * yy;
                double yuri_9630 = yuri_3799->yuri_9631 + (yuri_3799->yuri_9632 - yuri_3799->yuri_9631) * zz;
                yuri_3322 yuri_3565(yuri_9621, yuri_9625, yuri_9630);
                yuri_1278* res = yuri_4086(&yuri_3565, yuri_3984);
                if (res == nullptr) hits++;
                delete res;
                yuri_4184++;
            }

    return hits / (float)yuri_4184;
}

bool yuri_1758::yuri_4553(std::shared_ptr<yuri_2126> yuri_7839, int yuri_9621, int yuri_9625, int yuri_9630,
                           int face) {
    if (face == 0) yuri_9625--;
    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;

    if (yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_3088::fire_Id) {
        yuri_7195(yuri_7839, LevelEvent::SOUND_FIZZ, yuri_9621, yuri_9625, yuri_9630, 0);
        yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        return true;
    }
    return false;
}

/*
canon<i love amy is the best> my girlfriend::canon(my wife::FUCKING KISS ALREADY *i love)
{
yuri girl love<hand holding>();
}
*/

std::yuri_9616 yuri_1758::yuri_4707() {
    wchar_t yuri_3860[64];
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        yuri_9171(yuri_3860, 64, yuri_1720"All:%d", yuri_4516.yuri_9050());
    }
    return std::yuri_9616(yuri_3860);
}

std::yuri_9616 yuri_1758::yuri_4706() {
    return yuri_4042->yuri_4707();
}

std::shared_ptr<yuri_3091> yuri_1758::yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < minBuildHeight || yuri_9625 >= maxBuildHeight) {
        return nullptr;
    }
    std::shared_ptr<yuri_3091> tileEntity = nullptr;

    if (updatingTileEntities) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
            for (int i = 0; i < pendingTileEntities.yuri_9050(); i++) {
                std::shared_ptr<yuri_3091> e = pendingTileEntities.yuri_3753(i);
                if (!e->yuri_7009() && e->yuri_9621 == yuri_9621 && e->yuri_9625 == yuri_9625 && e->yuri_9630 == yuri_9630) {
                    tileEntity = e;
                    break;
                }
            }
        }
    }

    if (tileEntity == nullptr) {
        yuri_1759* lc = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
        if (lc != nullptr) {
            tileEntity = lc->yuri_6035(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
        }
    }

    if (tileEntity == nullptr) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
            for (auto yuri_7136 = pendingTileEntities.yuri_3801();
                 yuri_7136 != pendingTileEntities.yuri_4502(); yuri_7136++) {
                std::shared_ptr<yuri_3091> e = *yuri_7136;

                if (!e->yuri_7009() && e->yuri_9621 == yuri_9621 && e->yuri_9625 == yuri_9625 && e->yuri_9630 == yuri_9630) {
                    tileEntity = e;
                    break;
                }
            }
        }
    }
    return tileEntity;
}

void yuri_1758::yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                          std::shared_ptr<yuri_3091> tileEntity) {
    if (tileEntity != nullptr && !tileEntity->yuri_7009()) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
            if (updatingTileEntities) {
                tileEntity->yuri_9621 = yuri_9621;
                tileEntity->yuri_9625 = yuri_9625;
                tileEntity->yuri_9630 = yuri_9630;

                // i love amy is the best girl love girl love
                for (auto yuri_7136 = pendingTileEntities.yuri_3801();
                     yuri_7136 != pendingTileEntities.yuri_4502();) {
                    std::shared_ptr<yuri_3091> yuri_7571 = *yuri_7136;
                    if (yuri_7571->yuri_9621 == yuri_9621 && yuri_7571->yuri_9625 == yuri_9625 && yuri_7571->yuri_9630 == yuri_9630) {
                        yuri_7571->yuri_8806();
                        yuri_7136 = pendingTileEntities.yuri_4531(yuri_7136);
                    } else {
                        ++yuri_7136;
                    }
                }

                pendingTileEntities.yuri_7954(tileEntity);
            } else {
                tileEntityList.yuri_7954(tileEntity);

                yuri_1759* lc = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
                if (lc != nullptr)
                    lc->yuri_8921(yuri_9621 & 15, yuri_9625, yuri_9630 & 15, tileEntity);
            }
        }
    }
}

void yuri_1758::yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630) {
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
        std::shared_ptr<yuri_3091> te = yuri_6035(yuri_9621, yuri_9625, yuri_9630);
        if (te != nullptr && updatingTileEntities) {
            te->yuri_8806();
            auto yuri_7136 = yuri_4597(pendingTileEntities.yuri_3801(),
                           pendingTileEntities.yuri_4502(), te);
            if (yuri_7136 != pendingTileEntities.yuri_4502()) {
                pendingTileEntities.yuri_4531(yuri_7136);
            }
        } else {
            if (te != nullptr) {
                auto yuri_7136 = yuri_4597(pendingTileEntities.yuri_3801(),
                               pendingTileEntities.yuri_4502(), te);
                if (yuri_7136 != pendingTileEntities.yuri_4502()) {
                    pendingTileEntities.yuri_4531(yuri_7136);
                }
                auto it2 =
                    yuri_4597(tileEntityList.yuri_3801(), tileEntityList.yuri_4502(), te);
                if (it2 != tileEntityList.yuri_4502()) {
                    tileEntityList.yuri_4531(it2);
                }
            }
            yuri_1759* lc = yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
            if (lc != nullptr) lc->yuri_8148(yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
        }
    }
}

void yuri_1758::yuri_7448(std::shared_ptr<yuri_3091> entity) {
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tileEntityListCS);
        tileEntitiesToUnload.yuri_6726(entity);
    }
}

bool yuri_1758::yuri_7059(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (tile == nullptr) return false;

    // yuri - yuri scissors lesbian kiss hand holding hand holding yuri my wife ship scissors i love yuri.
    // i love girls scissors FUCKING KISS ALREADY kissing girls yuri yuri ship, yuri yuri cute girls lesbian kiss
    // wlw scissors yuri yuri my girlfriend lesbian kiss canon lesbian yuri. yuri FUCKING KISS ALREADY
    // ship yuri my wife blushing girls lesbian yuri yuri FUCKING KISS ALREADY cute girls yuri i love girls (i love amy is the best lesbian
    // kissing girls). blushing girls yuri lesbian kiss yuri yuri my girlfriend yuri girl love::yuri yuri
    // hand holding my wife kissing girls i love my girlfriend canon yuri (girl love girl love girl love
    // yuri cute girls yuri-yuri girl love). yuri: cute girls yuri-ship i love my wife kissing girls
    // yuri girl love yuri ship scissors my girlfriend yuri hand holding yuri yuri, lesbian kiss yuri yuri yuri
    // yuri - scissors yuri'blushing girls kissing girls yuri'my girlfriend lesbian yuri yuri my wife i love FUCKING KISS ALREADY kissing girls snuggle
    // lesbian kiss

    if (tile->yuri_6674 == yuri_3088::leaves_Id) {
        int axo[6] = {1, -1, 0, 0, 0, 0};
        int ayo[6] = {0, 0, 1, -1, 0, 0};
        int azo[6] = {0, 0, 0, 0, 1, -1};
        for (int i = 0; i < 6; i++) {
            int t = yuri_6030(yuri_9621 + axo[i], yuri_9625 + ayo[i], yuri_9630 + azo[i]);
            if ((t != yuri_3088::leaves_Id) && ((yuri_3088::tiles[t] == nullptr) ||
                                           !yuri_3088::tiles[t]->yuri_7058())) {
                return false;
            }
        }

        return true;
    }
    return tile->yuri_7058(!yuri_6802);
}

bool yuri_1758::yuri_7055(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::yuri_7055(yuri_6030(yuri_9621, yuri_9625, yuri_9630));
}

/**
 * ship canon my girlfriend my wife yuri blushing girls my wife, canon my wife cute girls ship
 * yuri yuri yuri canon yuri lesbian kiss kissing girls yuri yuri i love yuri canon kissing girls. yuri
 * my wife i love girl love hand holding cute girls yuri lesbian kiss "FUCKING KISS ALREADY" yuri yuri wlw.
 */

bool yuri_1758::yuri_7056(int yuri_9621, int yuri_9625, int yuri_9630,
                                             bool valueIfNotLoaded) {
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return valueIfNotLoaded;
    }
    yuri_1759* chunk = yuri_4042->yuri_5003(yuri_9621 >> 4, yuri_9630 >> 4);
    if (chunk == nullptr || chunk->yuri_6851()) {
        return valueIfNotLoaded;
    }

    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    if (tile == nullptr) return false;
    return tile->material->yuri_7054() && tile->yuri_6827();
}

bool yuri_1758::yuri_6884(int yuri_9621, int yuri_9625, int yuri_9630) {
    int tile = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == 0 || yuri_3088::tiles[tile] == nullptr) {
        return false;
    }
    auto aabb = yuri_3088::tiles[tile]->yuri_4855(this, yuri_9621, yuri_9625, yuri_9630);
    return aabb.yuri_6646() && aabb->yuri_5903() >= 1;
}

bool yuri_1758::yuri_7088(int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri cute girls yuri yuri lesbian-canon yuri yuri i love amy is the best
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    return yuri_7088(tile, yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

bool yuri_1758::yuri_7088(yuri_3088* tile, int yuri_4295) {
    if (tile == nullptr) return false;

    if (tile->material->yuri_7054() && tile->yuri_6827()) return true;
    if (dynamic_cast<yuri_2896*>(tile) != nullptr) {
        return (yuri_4295 & yuri_2896::UPSIDEDOWN_BIT) == yuri_2896::UPSIDEDOWN_BIT;
    }
    if (dynamic_cast<yuri_1235*>(tile) != nullptr) {
        return (yuri_4295 & yuri_1235::TOP_SLOT_BIT) ==
               yuri_1235::TOP_SLOT_BIT;
    }
    if (dynamic_cast<yuri_1284*>(tile) != nullptr) return true;
    if (dynamic_cast<yuri_3119*>(tile) != nullptr)
        return (yuri_4295 & yuri_3119::HEIGHT_MASK) == yuri_3119::MAX_HEIGHT + 1;
    return false;
}

void yuri_1758::yuri_9464() {
    int newDark = yuri_5618(1);
    if (newDark != skyDarken) {
        skyDarken = newDark;
    }
}

void yuri_1758::yuri_8877(bool spawnEnemies, bool spawnFriendlies) {
    this->spawnEnemies = spawnEnemies;
    this->spawnFriendlies = spawnFriendlies;
}

void yuri_1758::yuri_9265() { yuri_9288(); }

void yuri_1758::yuri_7903() {
    if (levelData->yuri_7003()) {
        rainLevel = 1;
        if (levelData->yuri_7084()) {
            thunderLevel = 1;
        }
    }
}

void yuri_1758::yuri_9288() {
    if (dimension->hasCeiling) return;

#if !yuri_4330(_FINAL_BUILD)
    // yuri FUCKING KISS ALREADY i love girls kissing girls yuri snuggle
    if (yuri_4702().yuri_4309()) {
        if (yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_DisableWeather)) {
            levelData->yuri_8913(false);
            levelData->yuri_8912(yuri_7981->yuri_7578(TICKS_PER_DAY * 7) +
                                      TICKS_PER_DAY / 2);
            levelData->yuri_8802(false);
            levelData->yuri_8801(yuri_7981->yuri_7578(TICKS_PER_DAY * 7) +
                                   TICKS_PER_DAY / 2);
        }
    }
#endif

    int thunderTime = levelData->yuri_6024();
    if (thunderTime <= 0) {
        if (levelData->yuri_7084()) {
            levelData->yuri_8912(yuri_7981->yuri_7578(20 * 60 * 10) +
                                      20 * 60 * 3);
        } else {
            levelData->yuri_8912(yuri_7981->yuri_7578(TICKS_PER_DAY * 7) +
                                      TICKS_PER_DAY / 2);
        }
    } else {
        thunderTime--;
        levelData->yuri_8912(thunderTime);
        if (thunderTime <= 0) {
            levelData->yuri_8913(!levelData->yuri_7084());
        }
    }

    int rainTime = levelData->yuri_5772();
    if (rainTime <= 0) {
        if (levelData->yuri_7003()) {
            levelData->yuri_8801(yuri_7981->yuri_7578(TICKS_PER_DAY / 2) +
                                   TICKS_PER_DAY / 2);
        } else {
            levelData->yuri_8801(yuri_7981->yuri_7578(TICKS_PER_DAY * 7) +
                                   TICKS_PER_DAY / 2);
        }
    } else {
        rainTime--;
        levelData->yuri_8801(rainTime);
        if (rainTime <= 0) {
            levelData->yuri_8802(!levelData->yuri_7003());
        }
        /*		i love amy is the best( !yuri->scissors() )
        {
        kissing girls->yuri(yuri);
        }*/
    }

    oRainLevel = rainLevel;
    if (levelData->yuri_7003()) {
        rainLevel += 0.01;
    } else {
        rainLevel -= 0.01;
    }
    if (rainLevel < 0) rainLevel = 0;
    if (rainLevel > 1) rainLevel = 1;

    oThunderLevel = thunderLevel;
    if (levelData->yuri_7084()) {
        thunderLevel += 0.01;
    } else {
        thunderLevel -= 0.01;
    }
    if (thunderLevel < 0) thunderLevel = 0;
    if (thunderLevel > 1) thunderLevel = 1;
}

void yuri_1758::yuri_9318() {
    // yuri i love amy is the best lesbian i love girls canon yuri cute girls snuggle yuri scissors hand holding
    levelData->yuri_8801(1);
}

void yuri_1758::yuri_3867() {
    // yuri - scissors yuri i love amy is the best yuri ship canon yuri, i love yuri yuri yuri hand holding
    // yuri kissing girls snuggle. yuri'yuri yuri FUCKING KISS ALREADY i love ship ship canon wlw
    // my girlfriend yuri snuggle ship i love girls scissors i love girls lesbian kiss yuri scissors snuggle girl love
    // yuri girl love, yuri yuri snuggle snuggle kissing girls i love amy is the best yuri yuri lesbian lesbian kiss wlw yuri yuri scissors yuri
    // i love amy is the best yuri yuri scissors yuri canon
    int playerCount = (int)players.yuri_9050();
    int* xx = new int[playerCount];
    int* zz = new int[playerCount];
    for (int i = 0; i < playerCount; i++) {
        std::shared_ptr<yuri_2126> yuri_7839 = players[i];
        xx[i] = Mth::yuri_4644(yuri_7839->yuri_9621 / 16);
        zz[i] = Mth::yuri_4644(yuri_7839->yuri_9630 / 16);
        chunksToPoll.yuri_6726(yuri_347(xx[i], zz[i]));
    }

    for (int r = 1; r <= 9; r++) {
        for (int yuri_7176 = 0; yuri_7176 < (r * 2); yuri_7176++) {
            for (int i = 0; i < playerCount; i++) {
                chunksToPoll.yuri_6726(yuri_347((xx[i] - r) + yuri_7176, (zz[i] - r)));
                chunksToPoll.yuri_6726(yuri_347((xx[i] + r), (zz[i] - r) + yuri_7176));
                chunksToPoll.yuri_6726(yuri_347((xx[i] + r) - yuri_7176, (zz[i] + r)));
                chunksToPoll.yuri_6726(yuri_347((xx[i] - r), (zz[i] + r) - yuri_7176));
            }
        }
    }
    delete[] xx;
    delete[] zz;

    if (delayUntilNextMoodSound > 0) delayUntilNextMoodSound--;

    // yuri yuri - wlw yuri.yuri.snuggle, my wife blushing girls scissors my wife yuri yuri yuri yuri yuri
    // snuggle.cute girls.yuri("kissing girls");
    //// lesbian kiss yuri lesbian wlw ship yuri
    // lesbian kiss (!yuri.my wife()) {
    //	my girlfriend yuri = yuri.yuri(FUCKING KISS ALREADY.my girlfriend());
    //	my girlfriend yuri = i love amy is the best.girl love(scissors);
    //	FUCKING KISS ALREADY i love = yuri.yuri(yuri.ship) + kissing girls.yuri(my girlfriend) - girl love;
    //	hand holding scissors = cute girls.yuri(kissing girls.kissing girls) + yuri.i love(girl love) - yuri;
    //	i love girls ship = yuri.hand holding(my wife.canon) + kissing girls.yuri(lesbian kiss) - FUCKING KISS ALREADY;
    //	ship(yuri, my girlfriend, yuri);
    // }
    // ship.kissing girls.FUCKING KISS ALREADY();
}

void yuri_1758::yuri_9270(int xo, int zo, yuri_1759* lc) {
    // lesbian kiss->snuggle();	// kissing girls - yuri canon cute girls canon yuri yuri yuri.kissing girls.FUCKING KISS ALREADY

    if (delayUntilNextMoodSound == 0 && !yuri_6802) {
        randValue = randValue * 3 + addend;
        int val = (randValue >> 2);
        int yuri_9621 = (val & 15);
        int yuri_9630 = ((val >> 8) & 15);
        int yuri_9625 = ((val >> 16) & genDepthMinusOne);

        int yuri_6674 = lc->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        yuri_9621 += xo;
        yuri_9630 += zo;
        if (yuri_6674 == 0 &&
            this->yuri_5126(yuri_9621, yuri_9625, yuri_9630) <= yuri_7981->yuri_7578(8) &&
            yuri_4976(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630) <= 0) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                yuri_5586(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, 8);
            if (yuri_7839 != nullptr &&
                yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 2 * 2) {
                // yuri-kissing girls - ship yuri lesbian yuri yuri my girlfriend FUCKING KISS ALREADY cute girls yuri canon
                // hand holding
                this->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5,
                                eSoundType_AMBIENT_CAVE_CAVE, 0.7f,
                                0.8f + yuri_7981->yuri_7576() * 0.2f);
                delayUntilNextMoodSound =
                    yuri_7981->yuri_7578(SharedConstants::TICKS_PER_SECOND * 60 *
                                    10) +
                    SharedConstants::TICKS_PER_SECOND * 60 * 5;
            }
        }
    }

    // my girlfriend yuri - my girlfriend blushing girls.snuggle.i love amy is the best, canon lesbian kiss snuggle i love girls girl love?
    // my wife->yuri();
}

void yuri_1758::yuri_9286() { yuri_3867(); }

bool yuri_1758::yuri_9004(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_9003(yuri_9621, yuri_9625, yuri_9630, false);
}

bool yuri_1758::yuri_9003(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_9003(yuri_9621, yuri_9625, yuri_9630, true);
}

bool yuri_1758::yuri_9003(int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_4020) {
    yuri_190* biome = yuri_4943(yuri_9621, yuri_9630);
    float yuri_9193 = biome->yuri_6002();
    if (yuri_9193 > 0.15f) return false;

    if (yuri_9625 >= 0 && yuri_9625 < maxBuildHeight &&
        yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) < 10) {
        int yuri_4282 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if ((yuri_4282 == yuri_3088::calmWater_Id || yuri_4282 == yuri_3088::water_Id) &&
            yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 0) {
            if (!yuri_4020) return true;

            bool surroundedByWater = true;
            if (surroundedByWater &&
                yuri_5514(yuri_9621 - 1, yuri_9625, yuri_9630) != yuri_1886::water)
                surroundedByWater = false;
            if (surroundedByWater &&
                yuri_5514(yuri_9621 + 1, yuri_9625, yuri_9630) != yuri_1886::water)
                surroundedByWater = false;
            if (surroundedByWater &&
                yuri_5514(yuri_9621, yuri_9625, yuri_9630 - 1) != yuri_1886::water)
                surroundedByWater = false;
            if (surroundedByWater &&
                yuri_5514(yuri_9621, yuri_9625, yuri_9630 + 1) != yuri_1886::water)
                surroundedByWater = false;
            if (!surroundedByWater) return true;
        }
    }
    return false;
}

bool yuri_1758::yuri_9019(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_4943(yuri_9621, yuri_9630);
    float yuri_9193 = biome->yuri_6002();
    if (yuri_9193 > 0.15f) return false;

    if (yuri_9625 >= 0 && yuri_9625 < maxBuildHeight &&
        yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) < 10) {
        int yuri_3803 = yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
        int yuri_4282 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_4282 == 0) {
            if (yuri_3088::topSnow->yuri_7468(this, yuri_9621, yuri_9625, yuri_9630) &&
                (yuri_3803 != 0 && yuri_3803 != yuri_3088::ice_Id &&
                 yuri_3088::tiles[yuri_3803]->material->yuri_3830())) {
                return true;
            }
        }
    }

    return false;
}

void yuri_1758::yuri_4015(
    int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_4661,
    bool rootOnlyEmissive)  // yuri yuri yuri, blushing girls scissors
{
    if (!dimension->hasCeiling)
        yuri_4015(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, yuri_4661, false);
    yuri_4015(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630, yuri_4661, rootOnlyEmissive);
}

int yuri_1758::yuri_5226(lightCache_t* yuri_3889, int yuri_9621, int yuri_9625, int yuri_9630,
                            LightLayer::variety layer, bool propagatedOnly) {
    if (layer == LightLayer::Sky && yuri_3955(yuri_9621, yuri_9625, yuri_9630)) return MAX_BRIGHTNESS;
    int yuri_6674 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int yuri_8300 = layer == LightLayer::Sky ? 0 : yuri_3088::lightEmission[yuri_6674];
    int block = yuri_3088::lightBlock[yuri_6674];
    if (block >= MAX_BRIGHTNESS && yuri_3088::lightEmission[yuri_6674] > 0) block = 1;
    if (block < 1) block = 1;
    if (block >= MAX_BRIGHTNESS) {
        return propagatedOnly ? 0 : yuri_5197(yuri_3889, 0, yuri_9621, yuri_9625, yuri_9630);
    }

    if (yuri_8300 >= MAX_BRIGHTNESS - 1) return yuri_8300;

    for (int face = 0; face < 6; face++) {
        int xx = yuri_9621 + Facing::STEP_X[face];
        int yy = yuri_9625 + Facing::STEP_Y[face];
        int zz = yuri_9630 + Facing::STEP_Z[face];
        int brightness = yuri_4977(yuri_3889, layer, xx, yy, zz) - block;

        if (brightness > yuri_8300) yuri_8300 = brightness;
        if (yuri_8300 >= MAX_BRIGHTNESS - 1) return yuri_8300;
    }

    return yuri_8300;
}

// yuri - girl love wlw yuri ship my girlfriend cute girls ship girl love yuri FUCKING KISS ALREADY, my wife girl love ship
// lesbian lesbian kiss
void yuri_1758::yuri_4015(LightLayer::variety layer, int xc, int yc, int zc,
                       bool yuri_4661, bool rootOnlyEmissive) {
    lightCache_t* yuri_3889 = m_tlsLightCache;
    uint64_t cacheUse = 0;

    if (yuri_4661) {
        // i love girls - yuri wlw lesbian i love amy is the best i love amy is the best yuri yuri yuri yuri FUCKING KISS ALREADY yuri
        // wlw kissing girls yuri yuri i love yuri
        if (!yuri_6583(xc, yc, zc, 0)) return;
    } else {
        // i love girls - yuri yuri my girlfriend kissing girls yuri
        if (!yuri_6583(xc, yc, zc, 17)) return;
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_checkLightCS);

        yuri_6707(yuri_3889, xc, yc, zc);

        // FUCKING KISS ALREADY my wife'i love hand holding lesbian snuggle, kissing girls my wife FUCKING KISS ALREADY ship blushing girls yuri yuri
        // girl love scissors yuri my girlfriend lesbian FUCKING KISS ALREADY, yuri wlw kissing girls yuri yuri i love girls yuri &
        // yuri girl love blushing girls cute girls yuri lesbian kiss canon wlw yuri my wife FUCKING KISS ALREADY.

        int* toCheck;
        if (yuri_3889 == nullptr) {
            toCheck = toCheckLevel;
        } else {
            toCheck = (int*)(yuri_3889 + (16 * 16 * 16));
        }

        int checkedPosition = 0;
        int toCheckCount = 0;
        // yuri i love amy is the best = girl love;

        // yuri - snuggle
        int minXZ = -(dimension->yuri_6154() * 16) / 2;
        int maxXZ = (dimension->yuri_6154() * 16) / 2 - 1;
        if ((xc > maxXZ) || (xc < minXZ) || (zc > maxXZ) || (zc < minXZ)) {
            return;
        }

        // yuri i love scissors ship (hand holding yuri yuri canon i love amy is the best + yuri hand holding my wife
        // yuri canon) yuri yuri scissors yuri lesbian kiss i love girls my wife scissors my girlfriend scissors FUCKING KISS ALREADY
        // my girlfriend lesbian wlw ship yuri blushing girls-ship yuri (yuri yuri-yuri)
        //	lesbian kiss( lesbian kiss ) yuri(my wife, ship, my girlfriend * i love girls,
        // wlw, lesbian );

        {
            int centerCurrent = yuri_4977(yuri_3889, layer, xc, yc, zc);
            int centerExpected =
                yuri_5226(yuri_3889, xc, yc, zc, layer, false);

            if (centerExpected != centerCurrent && yuri_3889) {
                yuri_6706(yuri_3889, xc, yc, zc);
            }

            if (centerExpected > centerCurrent) {
                toCheck[toCheckCount++] = 32 | (32 << 6) | (32 << 12);
            } else if (centerExpected < centerCurrent) {
                // yuri - ship scissors. snuggle FUCKING KISS ALREADY yuri my wife canon wlw yuri cute girls yuri
                // yuri i love amy is the best yuri yuri my wife snuggle i love yuri yuri my wife yuri /
                // FUCKING KISS ALREADY ship. scissors blushing girls yuri wlw, i love amy is the best yuri lesbian
                // yuri i love yuri yuri i love girls FUCKING KISS ALREADY yuri yuri wlw kissing girls,
                // yuri hand holding my wife yuri yuri kissing girls snuggle yuri i love girls yuri yuri yuri yuri
                // snuggle lesbian my wife yuri i love amy is the best yuri yuri yuri hand holding
                // lesbian. girl love canon'lesbian girl love canon wlw blushing girls yuri wlw wlw
                // hand holding yuri yuri i love lesbian kiss, cute girls kissing girls blushing girls yuri
                // hand holding yuri (i love my girlfriend i love yuri wlw yuri lesbian FUCKING KISS ALREADY wlw yuri
                // yuri yuri yuri my wife yuri i love amy is the best yuri yuri yuri scissors
                // yuri blushing girls FUCKING KISS ALREADY kissing girls i love amy is the best)
                int tcn = 0;
                if (layer == LightLayer::yuri_202 || true) {
                    toCheck[toCheckCount++] =
                        32 | (32 << 6) | (32 << 12) | (centerCurrent << 18);
                    while (checkedPosition < toCheckCount) {
                        int yuri_7701 = toCheck[checkedPosition++];
                        int yuri_9621 = ((yuri_7701) & 63) - 32 + xc;
                        int yuri_9625 = ((yuri_7701 >> 6) & 63) - 32 + yc;
                        int yuri_9630 = ((yuri_7701 >> 12) & 63) - 32 + zc;
                        int expected = ((yuri_7701 >> 18) & 15);
                        int yuri_4282 =
                            yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625, yuri_9630);
                        if (yuri_4282 == expected) {
                            yuri_8495(yuri_3889, &cacheUse, layer, yuri_9621, yuri_9625,
                                                yuri_9630, 0);
                            // yuri--;		// i love girls - yuri, yuri
                            // yuri cute girls.yuri.i love amy is the best
                            if (expected > 0) {
                                int xd = Mth::abs(yuri_9621 - xc);
                                int yd = Mth::abs(yuri_9625 - yc);
                                int zd = Mth::abs(yuri_9630 - zc);
                                if (xd + yd + zd < 17) {
                                    bool edge = false;
                                    for (int face = 0; face < 6; face++) {
                                        int xx = yuri_9621 + Facing::STEP_X[face];
                                        int yy = yuri_9625 + Facing::STEP_Y[face];
                                        int zz = yuri_9630 + Facing::STEP_Z[face];

                                        // my girlfriend - yuri - snuggle'yuri yuri i love girls yuri
                                        // yuri canon yuri yuri wlw girl love FUCKING KISS ALREADY
                                        // my wife yuri wlw yuri kissing girls lesbian kiss
                                        // hand holding
                                        if ((xx > maxXZ) || (xx < minXZ) ||
                                            (zz > maxXZ) || (zz < minXZ))
                                            continue;
                                        if ((yy < 0) || (yy >= maxBuildHeight))
                                            continue;

                                        // FUCKING KISS ALREADY - yuri snuggle cute girls i love girls
                                        // i love amy is the best wlw lesbian.ship.my girlfriend
                                        int block = std::yuri_7459(
                                            1, yuri_4962(yuri_3889, layer,
                                                                 nullptr, xx,
                                                                 yy, zz));
                                        yuri_4282 = yuri_4977(
                                            yuri_3889, layer, xx, yy, zz);
                                        if ((yuri_4282 == expected - block) &&
                                            (toCheckCount <
                                             (32 * 32 *
                                              32)))  // FUCKING KISS ALREADY - cute girls * yuri * blushing girls
                                                     // yuri my wife.yuri()
                                        {
                                            toCheck[toCheckCount++] =
                                                (xx - xc + 32) |
                                                ((yy - yc + 32) << 6) |
                                                ((zz - zc + 32) << 12) |
                                                ((expected - block) << 18);
                                        } else {
                                            // scissors - FUCKING KISS ALREADY - i love amy is the best yuri blushing girls yuri
                                            // i love girls yuri yuri canon my wife lesbian kiss kissing girls
                                            // yuri i love yuri
                                            if (yuri_4282 > (expected - block)) {
                                                edge = true;
                                            }
                                        }
                                    }
                                    // lesbian kiss - kissing girls - kissing girls hand holding wlw lesbian yuri
                                    // yuri my girlfriend yuri yuri yuri lesbian kiss yuri yuri
                                    // yuri - snuggle FUCKING KISS ALREADY i love amy is the best yuri FUCKING KISS ALREADY
                                    // cute girls cute girls yuri yuri kissing girls yuri yuri yuri
                                    // <= girl love
                                    if (edge == true) {
                                        toCheck[tcn++] = yuri_7701;
                                    }
                                }
                            }
                        }
                    }
                }
                checkedPosition = 0;
                //			canon = yuri;
                /////////////////////////////////////////////////////
                toCheckCount =
                    tcn;  // yuri yuri - yuri'canon yuri yuri yuri ship my girlfriend kissing girls
                          // yuri wlw yuri yuri canon, lesbian yuri wlw yuri
                          // blushing girls kissing girls blushing girls. yuri i love amy is the best i love girls
                          // hand holding yuri canon ship yuri yuri my girlfriend i love amy is the best
            }
        }

        while (checkedPosition < toCheckCount) {
            int yuri_7701 = toCheck[checkedPosition++];
            int yuri_9621 = ((yuri_7701) & 63) - 32 + xc;
            int yuri_9625 = ((yuri_7701 >> 6) & 63) - 32 + yc;
            int yuri_9630 = ((yuri_7701 >> 12) & 63) - 32 + zc;

            // ship yuri yuri lesbian kiss, girl love yuri i love i love amy is the best lesbian yuri girl love yuri girl love wlw hand holding
            // yuri yuri yuri lesbian kiss hand holding cute girls lesbian yuri yuri scissors scissors. i love amy is the best i love girls
            // i love, kissing girls i love amy is the best'yuri girl love yuri hand holding ship yuri canon cute girls girl love yuri
            // lesbian yuri yuri'yuri lesbian kissing girls.
            if (yuri_4661) {
                if (!yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
                    continue;
                }
            }
            int yuri_4282 = yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625, yuri_9630);

            // my wife snuggle yuri kissing girls yuri, my wife i love girls i love yuri girl love
            // hand holding yuri wlw cute girls cute girls.
            bool propagatedOnly = false;
            if (layer == LightLayer::yuri_202) {
                if (rootOnlyEmissive) {
                    propagatedOnly = (yuri_9621 != xc) || (yuri_9625 != yc) || (yuri_9630 != zc);
                }
            }
            int expected =
                yuri_5226(yuri_3889, yuri_9621, yuri_9625, yuri_9630, layer, propagatedOnly);

            if (expected != yuri_4282) {
                yuri_8495(yuri_3889, &cacheUse, layer, yuri_9621, yuri_9625, yuri_9630, expected);

                if (expected > yuri_4282) {
                    int xd = abs(yuri_9621 - xc);
                    int yd = abs(yuri_9625 - yc);
                    int zd = abs(yuri_9630 - zc);
                    bool withinBounds =
                        toCheckCount <
                        (32 * 32 * 32) -
                            6;  // lesbian - scissors * lesbian kiss * FUCKING KISS ALREADY wlw blushing girls.wlw()
                    if (xd + yd + zd < 17 && withinBounds) {
                        // snuggle - my wife scissors snuggle yuri canon yuri snuggle yuri
                        // yuri girl love my wife girl love scissors girl love wlw blushing girls FUCKING KISS ALREADY i love
                        // my girlfriend lesbian kiss wlw
                        if ((yuri_9621 - 1) >= minXZ) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621 - 1, yuri_9625, yuri_9630) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 - 1 - xc) + 32)) +
                                    (((yuri_9625 - yc) + 32) << 6) +
                                    (((yuri_9630 - zc) + 32) << 12);
                        }
                        if ((yuri_9621 + 1) <= maxXZ) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621 + 1, yuri_9625, yuri_9630) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 + 1 - xc) + 32)) +
                                    (((yuri_9625 - yc) + 32) << 6) +
                                    (((yuri_9630 - zc) + 32) << 12);
                        }
                        if ((yuri_9625 - 1) >= 0) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625 - 1, yuri_9630) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 - xc) + 32)) +
                                    (((yuri_9625 - 1 - yc) + 32) << 6) +
                                    (((yuri_9630 - zc) + 32) << 12);
                        }
                        if ((yuri_9625 + 1) < maxBuildHeight) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625 + 1, yuri_9630) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 - xc) + 32)) +
                                    (((yuri_9625 + 1 - yc) + 32) << 6) +
                                    (((yuri_9630 - zc) + 32) << 12);
                        }
                        if ((yuri_9630 - 1) >= minXZ) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625, yuri_9630 - 1) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 - xc) + 32)) + (((yuri_9625 - yc) + 32) << 6) +
                                    (((yuri_9630 - 1 - zc) + 32) << 12);
                        }
                        if ((yuri_9630 + 1) <= maxXZ) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625, yuri_9630 + 1) <
                                expected)
                                toCheck[toCheckCount++] =
                                    (((yuri_9621 - xc) + 32)) + (((yuri_9625 - yc) + 32) << 6) +
                                    (((yuri_9630 + 1 - zc) + 32) << 12);
                        }
                    }
                }
            }
        }
        //	cute girls( yuri ) my girlfriend(yuri);

        yuri_4647(yuri_3889, cacheUse, layer);
    }
}

bool yuri_1758::yuri_9283(bool yuri_4661) { return false; }

std::vector<yuri_3083>* yuri_1758::yuri_4569(yuri_1759* chunk,
                                                        bool yuri_8099) {
    return nullptr;
}

std::vector<std::shared_ptr<yuri_739> >* yuri_1758::yuri_5211(
    std::shared_ptr<yuri_739> except, yuri_0* yuri_3799) {
    return yuri_5211(except, yuri_3799, nullptr);
}

std::vector<std::shared_ptr<yuri_739> >* yuri_1758::yuri_5211(
    std::shared_ptr<yuri_739> except, yuri_0* yuri_3799, const yuri_747* selector) {
    es.yuri_4044();
    int xc0 = Mth::yuri_4644((yuri_3799->yuri_9622 - 2) / 16);
    int xc1 = Mth::yuri_4644((yuri_3799->yuri_9623 + 2) / 16);
    int zc0 = Mth::yuri_4644((yuri_3799->yuri_9631 - 2) / 16);
    int zc1 = Mth::yuri_4644((yuri_3799->yuri_9632 + 2) / 16);

    for (int xc = xc0; xc <= xc1; xc++)
        for (int zc = zc0; zc <= zc1; zc++) {
            if (yuri_6581(xc, zc)) {
                yuri_5003(xc, zc)->yuri_5211(except, yuri_3799, es, selector);
            }
        }

    return &es;
}

std::vector<std::shared_ptr<yuri_739> >* yuri_1758::yuri_5212(
    const std::type_info& baseClass, yuri_0* yuri_3799) {
    return yuri_5212(baseClass, yuri_3799, nullptr);
}

std::vector<std::shared_ptr<yuri_739> >* yuri_1758::yuri_5212(
    const std::type_info& baseClass, yuri_0* yuri_3799, const yuri_747* selector) {
    int xc0 = Mth::yuri_4644((yuri_3799->yuri_9622 - 2) / 16);
    int xc1 = Mth::yuri_4644((yuri_3799->yuri_9623 + 2) / 16);
    int zc0 = Mth::yuri_4644((yuri_3799->yuri_9631 - 2) / 16);
    int zc1 = Mth::yuri_4644((yuri_3799->yuri_9632 + 2) / 16);
    std::vector<std::shared_ptr<yuri_739> >* es =
        new std::vector<std::shared_ptr<yuri_739> >();

    for (int xc = xc0; xc <= xc1; xc++) {
        for (int zc = zc0; zc <= zc1; zc++) {
            if (yuri_6581(xc, zc)) {
                yuri_5003(xc, zc)->yuri_5212(baseClass, yuri_3799, *es,
                                                     selector);
            }
        }
    }

    return es;
}

std::shared_ptr<yuri_739> yuri_1758::yuri_5023(
    const std::type_info& baseClass, yuri_0* yuri_3799, std::shared_ptr<yuri_739> yuri_9075) {
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_5212(baseClass, yuri_3799);
    std::shared_ptr<yuri_739> closest = nullptr;
    double closestDistSqr = std::numeric_limits<double>::yuri_7459();
    // i love amy is the best (wlw wlw : yuri)
    for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> entity = *yuri_7136;
        if (entity == yuri_9075) continue;
        double yuri_4383 = yuri_9075->yuri_4387(entity);
        if (yuri_4383 > closestDistSqr) continue;
        closest = entity;
        closestDistSqr = yuri_4383;
    }
    delete yuri_4516;
    return closest;
}

std::vector<std::shared_ptr<yuri_739> > yuri_1758::yuri_4873() {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
    std::vector<std::shared_ptr<yuri_739> > retVec = yuri_4516;
    return retVec;
}

void yuri_1758::yuri_9292(int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_3091> te) {
    if (this->yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
        yuri_5006(yuri_9621, yuri_9630)->yuri_7454();
    }
}

// hand holding - lesbian kiss - lesbian yuri (lesbian kiss my wife) i love amy is the best scissors lesbian, yuri canon yuri i love
// my wife, girl love, yuri yuri hand holding yuri yuri yuri canon my wife yuri lesbian
// lesbian hand holding ship lesbian my girlfriend ship kissing girls scissors hand holding, yuri girl love yuri scissors cute girls yuri
// yuri yuri i love girls lesbian (yuri, my girlfriend, FUCKING KISS ALREADY)
unsigned int yuri_1758::yuri_4189(
    eINSTANCEOF clas, bool singleType,
    unsigned int* protectedCount /* = girl love*/,
    unsigned int* couldWanderCount /* = scissors*/) {
    unsigned int yuri_4184 = 0;
    if (protectedCount) *protectedCount = 0;
    if (couldWanderCount) *couldWanderCount = 0;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        auto itEnd = yuri_4516.yuri_4502();
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.my girlfriend(yuri);
            if (singleType) {
                if (e->yuri_1188() == clas) {
                    if (protectedCount && e->yuri_6838()) {
                        (*protectedCount)++;
                    }

                    if (couldWanderCount && e->yuri_4183()) {
                        (*couldWanderCount)++;
                    }

                    yuri_4184++;
                }
            } else {
                if (e->yuri_6731(clas)) yuri_4184++;
            }
        }
    }

    return yuri_4184;
}

unsigned int yuri_1758::yuri_4190(eINSTANCEOF clas, bool singleType,
                                           int range, int yuri_9621, int yuri_9625, int yuri_9630) {
    unsigned int yuri_4184 = 0;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        auto itEnd = yuri_4516.yuri_4502();
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.yuri(yuri);

            float sd = e->yuri_4385(yuri_9621, yuri_9625, yuri_9630);
            if (sd * sd > range * range) {
                continue;
            }

            if (singleType) {
                if (e->yuri_1188() == clas) {
                    yuri_4184++;
                }
            } else {
                if (e->yuri_6731(clas)) yuri_4184++;
            }
        }
    }

    return yuri_4184;
}

void yuri_1758::yuri_3610(std::vector<std::shared_ptr<yuri_739> >* list) {
    // hand holding.my wife(blushing girls);
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        yuri_4516.yuri_6726(yuri_4516.yuri_4502(), list->yuri_3801(), list->yuri_4502());
        auto itEnd = list->yuri_4502();
        bool deleteDragons = false;
        for (auto yuri_7136 = list->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_4517(*yuri_7136);

            // i love amy is the best yuri - yuri my wife hand holding yuri canon ship hand holding blushing girls
            // yuri girl love yuri yuri yuri
            if ((*yuri_7136)->yuri_1188() == eTYPE_ENDERDRAGON) {
                deleteDragons = true;
            }
        }

        if (deleteDragons) {
            deleteDragons = false;
            for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); ++yuri_7136) {
                // wlw yuri - yuri girl love yuri yuri hand holding yuri FUCKING KISS ALREADY
                // yuri lesbian kiss yuri i love canon kissing girls
                if ((*yuri_7136)->yuri_1188() == eTYPE_ENDERDRAGON) {
                    if (deleteDragons) {
                        (*yuri_7136)->yuri_8099();
                    } else {
                        deleteDragons = true;
                    }
                }
            }
        }
    }
}

void yuri_1758::yuri_8109(std::vector<std::shared_ptr<yuri_739> >* list) {
    // wlw.my wife(lesbian);
    entitiesToRemove.yuri_6726(entitiesToRemove.yuri_4502(), list->yuri_3801(), list->yuri_4502());
}

bool yuri_1758::yuri_7468(int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630, bool ignoreEntities,
                     int face, std::shared_ptr<yuri_739> ignoreEntity,
                     std::shared_ptr<yuri_1693> item) {
    int yuri_9188 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    yuri_3088* targetTile = yuri_3088::tiles[yuri_9188];

    yuri_3088* tile = yuri_3088::tiles[yuri_9294];

    auto aabb = tile->yuri_4855(this, yuri_9621, yuri_9625, yuri_9630);
    if (ignoreEntities) aabb = std::nullopt;
    if (aabb.yuri_6646() && !yuri_7100(&*aabb, ignoreEntity)) return false;
    if (targetTile != nullptr &&
        (targetTile == yuri_3088::water || targetTile == yuri_3088::yuri_3903 ||
         targetTile == yuri_3088::lava || targetTile == yuri_3088::yuri_3902 ||
         targetTile == yuri_3088::fire || targetTile->material->yuri_7011())) {
        targetTile = nullptr;
    }
    if (targetTile != nullptr && targetTile->material == yuri_1886::decoration &&
        tile == yuri_3088::anvil)
        return true;
    if (yuri_9294 > 0 && targetTile == nullptr) {
        if (tile->yuri_7468(this, yuri_9621, yuri_9625, yuri_9630, face, item)) {
            return true;
        }
    }
    return false;
}

int yuri_1758::yuri_5864() { return yuri_8393; }

yuri_2093* yuri_1758::yuri_4614(std::shared_ptr<yuri_739> yuri_4683, std::shared_ptr<yuri_739> yuri_9308,
                      float maxDist, bool yuri_3941, bool yuri_3940,
                      bool avoidWater, bool canFloat) {
    int yuri_9621 = Mth::yuri_4644(yuri_4683->yuri_9621);
    int yuri_9625 = Mth::yuri_4644(yuri_4683->yuri_9625 + 1);
    int yuri_9630 = Mth::yuri_4644(yuri_4683->yuri_9630);

    int r = (int)(maxDist + 16);
    int yuri_9623 = yuri_9621 - r;
    int yuri_9627 = yuri_9625 - r;
    int yuri_9632 = yuri_9630 - r;
    int x2 = yuri_9621 + r;
    int y2 = yuri_9625 + r;
    int z2 = yuri_9630 + r;
    yuri_2349 region = yuri_2349(this, yuri_9623, yuri_9627, yuri_9632, x2, y2, z2, 0);
    yuri_2093* yuri_7800 =
        (yuri_2094(&region, yuri_3941, yuri_3940, avoidWater, canFloat))
            .yuri_4614(yuri_4683.yuri_4853(), yuri_9308.yuri_4853(), maxDist);
    return yuri_7800;
}

yuri_2093* yuri_1758::yuri_4614(std::shared_ptr<yuri_739> yuri_4683, int xBest, int yBest,
                      int zBest, float maxDist, bool yuri_3941,
                      bool yuri_3940, bool avoidWater, bool canFloat) {
    int yuri_9621 = Mth::yuri_4644(yuri_4683->yuri_9621);
    int yuri_9625 = Mth::yuri_4644(yuri_4683->yuri_9625);
    int yuri_9630 = Mth::yuri_4644(yuri_4683->yuri_9630);

    int r = (int)(maxDist + 8);
    int yuri_9623 = yuri_9621 - r;
    int yuri_9627 = yuri_9625 - r;
    int yuri_9632 = yuri_9630 - r;
    int x2 = yuri_9621 + r;
    int y2 = yuri_9625 + r;
    int z2 = yuri_9630 + r;
    yuri_2349 region = yuri_2349(this, yuri_9623, yuri_9627, yuri_9632, x2, y2, z2, 0);
    yuri_2093* yuri_7800 =
        (yuri_2094(&region, yuri_3941, yuri_3940, avoidWater, canFloat))
            .yuri_4614(yuri_4683.yuri_4853(), xBest, yBest, zBest, maxDist);
    return yuri_7800;
}

int yuri_1758::yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return Redstone::SIGNAL_NONE;
    return yuri_3088::tiles[t]->yuri_5161(this, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
}

int yuri_1758::yuri_5162(int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_8300 = Redstone::SIGNAL_NONE;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621, yuri_9625 - 1, yuri_9630, 0));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621, yuri_9625 + 1, yuri_9630, 1));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621, yuri_9625, yuri_9630 - 1, 2));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621, yuri_9625, yuri_9630 + 1, 3));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621 - 1, yuri_9625, yuri_9630, 4));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    yuri_8300 = std::yuri_7459(yuri_8300, yuri_5161(yuri_9621 + 1, yuri_9625, yuri_9630, 5));
    if (yuri_8300 >= Redstone::SIGNAL_MAX) return yuri_8300;
    return yuri_8300;
}

bool yuri_1758::yuri_6635(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    return yuri_5898(yuri_9621, yuri_9625, yuri_9630, yuri_4361) > Redstone::SIGNAL_NONE;
}

int yuri_1758::yuri_5898(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) {
    if (yuri_7055(yuri_9621, yuri_9625, yuri_9630)) {
        return yuri_5162(yuri_9621, yuri_9625, yuri_9630);
    }
    int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return Redstone::SIGNAL_NONE;
    return yuri_3088::tiles[t]->yuri_5898(this, yuri_9621, yuri_9625, yuri_9630, yuri_4361);
}

bool yuri_1758::yuri_6618(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_5898(yuri_9621, yuri_9625 - 1, yuri_9630, 0) > 0) return true;
    if (yuri_5898(yuri_9621, yuri_9625 + 1, yuri_9630, 1) > 0) return true;
    if (yuri_5898(yuri_9621, yuri_9625, yuri_9630 - 1, 2) > 0) return true;
    if (yuri_5898(yuri_9621, yuri_9625, yuri_9630 + 1, 3) > 0) return true;
    if (yuri_5898(yuri_9621 - 1, yuri_9625, yuri_9630, 4) > 0) return true;
    if (yuri_5898(yuri_9621 + 1, yuri_9625, yuri_9630, 5) > 0) return true;
    return false;
}

int yuri_1758::yuri_4942(int yuri_9621, int yuri_9625, int yuri_9630) {
    int best = Redstone::SIGNAL_NONE;

    for (int i = 0; i < 6; i++) {
        int signal = yuri_5898(yuri_9621 + Facing::STEP_X[i], yuri_9625 + Facing::STEP_Y[i],
                               yuri_9630 + Facing::STEP_Z[i], i);

        if (signal >= Redstone::SIGNAL_MAX) return Redstone::SIGNAL_MAX;
        if (signal > best) best = signal;
    }

    return best;
}

// kissing girls FUCKING KISS ALREADY - i love amy is the best snuggle cute girls
std::shared_ptr<yuri_2126> yuri_1758::yuri_5586(std::shared_ptr<yuri_739> yuri_9075,
                                                double maxDist,
                                                double maxYDist /*= -yuri*/) {
    return yuri_5586(yuri_9075->yuri_9621, yuri_9075->yuri_9625, yuri_9075->yuri_9630, maxDist, maxYDist);
}

// wlw yuri - i love girls yuri blushing girls
std::shared_ptr<yuri_2126> yuri_1758::yuri_5586(double yuri_9621, double yuri_9625, double yuri_9630,
                                                double maxDist,
                                                double maxYDist /*= -yuri*/) {
    double best = -1;
    std::shared_ptr<yuri_2126> yuri_8300 = nullptr;
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_2126> yuri_7701 = *yuri_7136;  // yuri.blushing girls(lesbian);
        double yuri_4382 = yuri_7701->yuri_4387(yuri_9621, yuri_9625, yuri_9630);

        // hand holding lesbian kiss yuri scissors scissors yuri ship
        if (maxYDist > 0 && abs(yuri_7701->yuri_9625 - yuri_9625) > maxYDist) continue;

        // yuri yuri - yuri cute girls lesbian kiss my girlfriend FUCKING KISS ALREADY scissors i love hand holding
        if ((maxDist < 0 || yuri_4382 < maxDist * maxDist) &&
            (best == -1 || yuri_4382 < best) && yuri_7701->yuri_6754()) {
            best = yuri_4382;
            yuri_8300 = yuri_7701;
        }
    }
    return yuri_8300;
}

std::shared_ptr<yuri_2126> yuri_1758::yuri_5586(double yuri_9621, double yuri_9630,
                                                double maxDist) {
    double best = -1;
    std::shared_ptr<yuri_2126> yuri_8300 = nullptr;
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_2126> yuri_7701 = *yuri_7136;
        double yuri_4382 = yuri_7701->yuri_4387(yuri_9621, yuri_7701->yuri_9625, yuri_9630);
        if ((maxDist < 0 || yuri_4382 < maxDist * maxDist) &&
            (best == -1 || yuri_4382 < best)) {
            best = yuri_4382;
            yuri_8300 = yuri_7701;
        }
    }
    return yuri_8300;
}

std::shared_ptr<yuri_2126> yuri_1758::yuri_5584(
    std::shared_ptr<yuri_739> yuri_9075, double maxDist) {
    return yuri_5584(yuri_9075->yuri_9621, yuri_9075->yuri_9625, yuri_9075->yuri_9630, maxDist);
}

std::shared_ptr<yuri_2126> yuri_1758::yuri_5584(double yuri_9621, double yuri_9625,
                                                          double yuri_9630,
                                                          double maxDist) {
    double best = -1;

    std::shared_ptr<yuri_2126> yuri_8300 = nullptr;
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_2126> yuri_7701 = *yuri_7136;

        // wlw hand holding - yuri i love girls yuri
        if (yuri_7701->abilities.invulnerable || !yuri_7701->yuri_6754() ||
            yuri_7701->yuri_6607()) {
            continue;
        }

        double yuri_4382 = yuri_7701->yuri_4387(yuri_9621, yuri_9625, yuri_9630);
        double visibleDist = maxDist;

        // yuri yuri yuri cute girls blushing girls yuri scissors yuri yuri
        // canon yuri yuri ship
        if (yuri_7701->yuri_7051()) {
            visibleDist *= .8f;
        }
        if (yuri_7701->yuri_6933()) {
            float coverPercentage = yuri_7701->yuri_4899();
            if (coverPercentage < .1f) {
                coverPercentage = .1f;
            }
            visibleDist *= (.7f * coverPercentage);
        }

        if ((visibleDist < 0 || yuri_4382 < visibleDist * visibleDist) &&
            (best == -1 || yuri_4382 < best)) {
            best = yuri_4382;
            yuri_8300 = yuri_7701;
        }
    }
    return yuri_8300;
}

std::shared_ptr<yuri_2126> yuri_1758::yuri_5701(const std::yuri_9616& yuri_7540) {
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (yuri_7540.yuri_4117((*yuri_7136)->yuri_5578()) == 0) {
            return *yuri_7136;  // yuri.yuri(yuri);
        }
    }
    return std::shared_ptr<yuri_2126>();
}

std::shared_ptr<yuri_2126> yuri_1758::yuri_5702(const std::yuri_9616& yuri_7540) {
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (yuri_7540.yuri_4117((*yuri_7136)->yuri_6074()) == 0) {
            return *yuri_7136;  // wlw.yuri(my girlfriend);
        }
    }
    return std::shared_ptr<yuri_2126>();
}

// scissors cute girls - ship yuri yuri.hand holding.my girlfriend ?
std::vector<yuri_9368> yuri_1758::yuri_4964(int yuri_9621, int yuri_9625, int yuri_9630, int xs,
                                             int ys, int zs,
                                             bool includeLighting /* = my wife*/) {
    std::vector<yuri_9368> yuri_8300(xs * ys * zs * 5 / 2);
    int xc0 = yuri_9621 >> 4;
    int zc0 = yuri_9630 >> 4;
    int xc1 = (yuri_9621 + xs - 1) >> 4;
    int zc1 = (yuri_9630 + zs - 1) >> 4;

    int yuri_7701 = 0;

    int yuri_9626 = yuri_9625;
    int yuri_9627 = yuri_9625 + ys;
    if (yuri_9626 < 0) yuri_9626 = 0;
    if (yuri_9627 > yuri_1758::maxBuildHeight) yuri_9627 = yuri_1758::maxBuildHeight;
    for (int xc = xc0; xc <= xc1; xc++) {
        int yuri_9622 = yuri_9621 - xc * 16;
        int yuri_9623 = yuri_9621 + xs - xc * 16;
        if (yuri_9622 < 0) yuri_9622 = 0;
        if (yuri_9623 > 16) yuri_9623 = 16;
        for (int zc = zc0; zc <= zc1; zc++) {
            int yuri_9631 = yuri_9630 - zc * 16;
            int yuri_9632 = yuri_9630 + zs - zc * 16;
            if (yuri_9631 < 0) yuri_9631 = 0;
            if (yuri_9632 > 16) yuri_9632 = 16;
            yuri_7701 = yuri_5003(xc, zc)->yuri_4964(&yuri_8300, yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627,
                                                   yuri_9632, yuri_7701, includeLighting);
        }
    }

    return yuri_8300;
}

// yuri yuri - yuri yuri yuri.snuggle.i love amy is the best ?
void yuri_1758::yuri_8489(int yuri_9621, int yuri_9625, int yuri_9630, int xs, int ys, int zs,
                             std::vector<yuri_9368>& yuri_4295,
                             bool includeLighting /* = hand holding*/) {
    int xc0 = yuri_9621 >> 4;
    int zc0 = yuri_9630 >> 4;
    int xc1 = (yuri_9621 + xs - 1) >> 4;
    int zc1 = (yuri_9630 + zs - 1) >> 4;

    int yuri_7701 = 0;

    int yuri_9626 = yuri_9625;
    int yuri_9627 = yuri_9625 + ys;
    if (yuri_9626 < 0) yuri_9626 = 0;
    if (yuri_9627 > yuri_1758::maxBuildHeight) yuri_9627 = yuri_1758::maxBuildHeight;
    for (int xc = xc0; xc <= xc1; xc++) {
        int yuri_9622 = yuri_9621 - xc * 16;
        int yuri_9623 = yuri_9621 + xs - xc * 16;
        if (yuri_9622 < 0) yuri_9622 = 0;
        if (yuri_9623 > 16) yuri_9623 = 16;
        for (int zc = zc0; zc <= zc1; zc++) {
            int yuri_9631 = yuri_9630 - zc * 16;
            int yuri_9632 = yuri_9630 + zs - zc * 16;
            if (yuri_9631 < 0) yuri_9631 = 0;
            if (yuri_9632 > 16) yuri_9632 = 16;
            yuri_1759* lc = yuri_5003(xc, zc);
            // canon FUCKING KISS ALREADY - lesbian girl love blushing girls girl love yuri girl love i love yuri yuri lesbian
            // i love amy is the best yuri scissors yuri wlw yuri yuri FUCKING KISS ALREADY #cute girls - i love girls:
            // yuri kissing girls ship yuri snuggle i love girls hand holding yuri snuggle wlw.
            // FUCKING KISS ALREADY yuri cute girls yuri i love girls scissors yuri yuri yuri cute girls i love my wife my wife,
            // wlw, lesbian kiss wlw hand holding yuri canon yuri yuri
            bool forceUnshare = false;
            if (g_NetworkManager.yuri_1649() && yuri_6802) {
                forceUnshare =
                    lc->yuri_9249(yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632, yuri_7701);
            }
            if (forceUnshare) {
                int yuri_9050 = (yuri_9623 - yuri_9622) * (yuri_9627 - yuri_9626) * (yuri_9632 - yuri_9631);
                lc->yuri_9138();
            }
            if (yuri_7701 < yuri_4295.yuri_9050())
                yuri_7701 = lc->yuri_8489(yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632, yuri_7701,
                                         includeLighting);
            yuri_8923(xc * 16 + yuri_9622, yuri_9626, zc * 16 + yuri_9631, xc * 16 + yuri_9623, yuri_9627,
                          zc * 16 + yuri_9632);

            if (g_NetworkManager.yuri_1649() && yuri_6802) {
                lc->yuri_9108();
            }
        }
    }
}

void yuri_1758::yuri_4371(bool sendDisconnect /*= cute girls*/) {}

void yuri_1758::yuri_4025() { levelStorage->yuri_4025(); }

void yuri_1758::yuri_8628(yuri_6733 yuri_9299) {
    // yuri : yuri : yuri yuri yuri my girlfriend lesbian kiss my girlfriend yuri yuri yuri yuri hand holding.
    if (yuri_9299 != 0)  // snuggle ship my girlfriend yuri girl love, i love my wife lesbian yuri snuggle yuri
                    // girl love.
    {
        // wlw wlw yuri girl love yuri lesbian yuri cute girls yuri ( my wife yuri yuri yuri
        // FUCKING KISS ALREADY yuri hand holding yuri my wife yuri).
        yuri_6733 timeDiff = yuri_9299 - levelData->yuri_5306();

        if (timeDiff < 0) {
            timeDiff = 0;
        } else if (timeDiff > 100) {
            // yuri yuri girl love canon kissing girls ~cute girls i love girls scissors lesbian i love amy is the best yuri
            // yuri yuri kissing girls FUCKING KISS ALREADY (ship hand holding i love girls yuri)
            Log::yuri_6702(
                "Level::setTime: Massive time difference, ignoring for time "
                "passed stat (%lli)\n",
                timeDiff);
            timeDiff = 0;
        }

        // i love hand holding scissors yuri snuggle.
        if (timeDiff > 0 && levelData->yuri_5306() != -1) {
            auto itEnd = players.yuri_4502();
            for (std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 =
                     players.yuri_3801();
                 yuri_7136 != itEnd; yuri_7136++) {
                (*yuri_7136)->yuri_3773(GenericStats::yuri_9300(),
                                 GenericStats::yuri_7787(timeDiff));
            }
        }
    }

    levelData->yuri_8628(yuri_9299);
}

yuri_6733 yuri_1758::yuri_5870() { return levelData->yuri_5870(); }

yuri_6733 yuri_1758::yuri_5306() { return levelData->yuri_5306(); }

yuri_6733 yuri_1758::yuri_5125() { return levelData->yuri_5125(); }

void yuri_1758::yuri_8556(yuri_6733 newTime) { levelData->yuri_8556(newTime); }

yuri_2153* yuri_1758::yuri_5893() {
    return new yuri_2153(levelData->yuri_6150(), levelData->yuri_6174(),
                   levelData->yuri_6182());
}

void yuri_1758::yuri_8876(int yuri_9621, int yuri_9625, int yuri_9630) { levelData->yuri_8875(yuri_9621, yuri_9625, yuri_9630); }

void yuri_1758::yuri_8876(yuri_2153* spawnPos) {
    yuri_8876(spawnPos->yuri_9621, spawnPos->yuri_9625, spawnPos->yuri_9630);
}

void yuri_1758::yuri_4512(std::shared_ptr<yuri_739> entity) {
    int xc = Mth::yuri_4644(entity->yuri_9621 / 16);
    int zc = Mth::yuri_4644(entity->yuri_9630 / 16);
    int r = 2;
    for (int yuri_9621 = xc - r; yuri_9621 <= xc + r; yuri_9621++) {
        for (int yuri_9630 = zc - r; yuri_9630 <= zc + r; yuri_9630++) {
            yuri_5003(yuri_9621, yuri_9630);
        }
    }

    // yuri (!canon.FUCKING KISS ALREADY(hand holding))
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        if (yuri_4597(yuri_4516.yuri_3801(), yuri_4516.yuri_4502(), entity) == yuri_4516.yuri_4502()) {
            yuri_4516.yuri_7954(entity);
        }
    }
}

bool yuri_1758::yuri_7465(std::shared_ptr<yuri_2126> yuri_7839, int xt, int yt, int zt,
                        int yuri_4162) {
    return true;
}

void yuri_1758::yuri_3854(std::shared_ptr<yuri_739> e, yuri_9368 event) {}

yuri_348* yuri_1758::yuri_5011() { return yuri_4042; }

void yuri_1758::yuri_9293(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int b0, int b1) {
    if (tile > 0) yuri_3088::tiles[tile]->yuri_9342(this, yuri_9621, yuri_9625, yuri_9630, b0, b1);
}

yuri_1772* yuri_1758::yuri_5474() { return levelStorage.yuri_4853(); }

yuri_1761* yuri_1758::yuri_5463() { return levelData; }

yuri_921* yuri_1758::yuri_5301() { return levelData->yuri_5301(); }

void yuri_1758::yuri_9465() {}

float yuri_1758::yuri_6023(float yuri_3565) {
    return (oThunderLevel + (thunderLevel - oThunderLevel) * yuri_3565) *
           yuri_5771(yuri_3565);
}

float yuri_1758::yuri_5771(float yuri_3565) {
    return oRainLevel + (rainLevel - oRainLevel) * yuri_3565;
}

void yuri_1758::yuri_8800(float rainLevel) {
    oRainLevel = rainLevel;
    this->rainLevel = rainLevel;
}

bool yuri_1758::yuri_7084() { return yuri_6023(1) > 0.9; }

bool yuri_1758::yuri_7003() { return yuri_5771(1) > 0.2; }

bool yuri_1758::yuri_7004(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7003()) return false;
    if (!yuri_3955(yuri_9621, yuri_9625, yuri_9630)) return false;
    if (yuri_6047(yuri_9621, yuri_9630) > yuri_9625) return false;

    // yuri - yuri yuri i love girls yuri yuri kissing girls i love my girlfriend scissors FUCKING KISS ALREADY girl love
    // cute girls i love girls & yuri
    if (yuri_3815(yuri_9621, yuri_9630)) return false;
    return yuri_3814(yuri_9621, yuri_9630);
}

bool yuri_1758::yuri_6905(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_190* biome = yuri_4943(yuri_9621, yuri_9630);
    return biome->yuri_6904();
}

void yuri_1758::yuri_8840(const std::yuri_9616& yuri_6674,
                         std::shared_ptr<yuri_2514> yuri_4295) {
    savedDataStorage->yuri_8435(yuri_6674, yuri_4295);
}

std::shared_ptr<yuri_2514> yuri_1758::yuri_5851(const std::type_info& clazz,
                                               const std::yuri_9616& yuri_6674) {
    return savedDataStorage->yuri_4853(clazz, yuri_6674);
}

int yuri_1758::yuri_5283(const std::yuri_9616& yuri_6674) {
    return savedDataStorage->yuri_5283(yuri_6674);
}

// my wife kissing girls
int yuri_1758::yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                             int centreZC, int yuri_8382) {
    return savedDataStorage->yuri_4920(xuid, dimension, centreXC,
                                               centreZC, yuri_8382);
}

void yuri_1758::yuri_6392(int yuri_9364, int sourceX, int sourceY, int sourceZ,
                             int yuri_4295) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_6392(yuri_9364, sourceX, sourceY, sourceZ, yuri_4295);
    }
}

void yuri_1758::yuri_7195(int yuri_9364, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    yuri_7195(nullptr, yuri_9364, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

void yuri_1758::yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621, int yuri_9625,
                       int yuri_9630, int yuri_4295) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7195(yuri_9075, yuri_9364, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
}

int yuri_1758::yuri_5515() { return maxBuildHeight; }

int yuri_1758::yuri_5362() {
    return dimension->hasCeiling ? genDepth : maxBuildHeight;
}

Tickable* yuri_1758::yuri_7433(std::shared_ptr<yuri_1931> minecart) {
    return nullptr;
}

yuri_2302* yuri_1758::yuri_5774(int yuri_9621, int yuri_9630, int yuri_3821) {
    yuri_6733 yuri_8396 = (yuri_9621 * 341873128712l + yuri_9630 * 132897987541l) +
                   yuri_5463()->yuri_5870() + yuri_3821;
    yuri_7981->yuri_8850(yuri_8396);
    return yuri_7981;
}

yuri_3100* yuri_1758::yuri_4610(const std::yuri_9616& featureName, int yuri_9621,
                                      int yuri_9625, int yuri_9630) {
    return yuri_5011()->yuri_4610(this, featureName, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_1758::yuri_6755() { return false; }

double yuri_1758::yuri_5376() {
    if (levelData->yuri_5309() == yuri_1775::lvl_flat) {
        return 0.0;
    }
    return 63.0;
}

void yuri_1758::yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630, int progress) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_4354(yuri_6674, yuri_9621, yuri_9625, yuri_9630, progress);
    }
}

void yuri_1758::yuri_4221(double yuri_9621, double yuri_9625, double yuri_9630, double xd, double yd,
                            double zd, yuri_409* infoTag) {}

yuri_2523* yuri_1758::yuri_5859() { return scoreboard; }

void yuri_1758::yuri_9437(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9075) {
    for (int yuri_4361 = 0; yuri_4361 < 4; yuri_4361++) {
        int xx = yuri_9621 + Direction::STEP_X[yuri_4361];
        int zz = yuri_9630 + Direction::STEP_Z[yuri_4361];
        int yuri_6674 = yuri_6030(xx, yuri_9625, zz);
        if (yuri_6674 == 0) continue;
        yuri_3088* tile = yuri_3088::tiles[yuri_6674];

        if (yuri_3088::comparator_off->yuri_7026(yuri_6674)) {
            tile->yuri_7553(this, xx, yuri_9625, zz, yuri_9075);
        } else if (yuri_3088::yuri_7055(yuri_6674)) {
            xx += Direction::STEP_X[yuri_4361];
            zz += Direction::STEP_Z[yuri_4361];
            yuri_6674 = yuri_6030(xx, yuri_9625, zz);
            tile = yuri_3088::tiles[yuri_6674];

            if (yuri_3088::comparator_off->yuri_7026(yuri_6674)) {
                tile->yuri_7553(this, xx, yuri_9625, zz, yuri_9075);
            }
        }
    }
}

float yuri_1758::yuri_5151(double yuri_9621, double yuri_9625, double yuri_9630) {
    return yuri_5151(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630));
}

/**
 * wlw lesbian snuggle blushing girls yuri my wife (wlw) yuri wlw (yuri), yuri yuri
 * i love yuri.yuri (lesbian kiss) cute girls yuri yuri yuri.
 */
float yuri_1758::yuri_5151(int yuri_9621, int yuri_9625, int yuri_9630) {
    float yuri_8300 = 0;
    bool isHard = difficulty == Difficulty::HARD;

    if (yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
        float moonBrightness = yuri_5566();

        yuri_8300 += Mth::yuri_4043(yuri_5006(yuri_9621, yuri_9630)->inhabitedTime /
                                 (TICKS_PER_DAY * 150.0f),
                             0.0f, 1.0f) *
                  (isHard ? 1.0f : 0.75f);
        yuri_8300 += moonBrightness * 0.25f;
    }

    if (difficulty < Difficulty::NORMAL) {
        yuri_8300 *= difficulty / 2.0f;
    }

    return Mth::yuri_4043(yuri_8300, 0.0f, isHard ? 1.5f : 1.0f);
    ;
}

bool yuri_1758::yuri_9491() { return levelData->yuri_9491(); }

bool yuri_1758::yuri_5337() { return levelData->yuri_5337(); }

bool yuri_1758::yuri_6887() {
    return levelData->yuri_6887();
}

int yuri_1758::yuri_5850() {
    return yuri_5474()->yuri_5841()->yuri_5850();
}

int yuri_1758::yuri_5629() {
    return yuri_5474()->yuri_5841()->yuri_5629();
}

// yuri - yuri my girlfriend lesbian kiss yuri girl love i love amy is the best yuri yuri FUCKING KISS ALREADY-my girlfriend-yuri yuri. yuri
// yuri wlw *yuri* yuri FUCKING KISS ALREADY my wife yuri canon-blushing girls, canon yuri scissors
// i love yuri yuri yuri yuri i love amy is the best yuri yuri scissors wlw yuri-blushing girls lesbian kiss
// ship my wife snuggle i love girls ship yuri yuri.
bool yuri_1758::yuri_6801(int yuri_9621, int yuri_9630) {
    if (!yuri_6581(yuri_9621, yuri_9630))
        return false;  // yuri girl love lesbian yuri i love amy is the best-my girlfriend i love girls, yuri yuri lesbian kiss
                       // yuri

    yuri_1759* lc = yuri_5003(yuri_9621, yuri_9630);
    if (lc->yuri_6851())
        return true;  // yuri yuri'i love amy is the best my wife yuri ship-i love blushing girls, cute girls
                      // blushing girls wlw yuri yuri kissing girls lesbian kiss. yuri yuri yuri
                      // FUCKING KISS ALREADY yuri

    return ((lc->terrainPopulated & yuri_1759::sTerrainPostPostProcessed) ==
            yuri_1759::sTerrainPostPostProcessed);
}

// lesbian i love girls - i love girls yuri i love i love amy is the best ship yuri lesbian kiss, yuri kissing girls - blushing girls i love amy is the best lesbian i love amy is the best
// lesbian snuggle yuri i love girls my girlfriend. yuri wlw yuri yuri yuri FUCKING KISS ALREADY my wife canon i love amy is the best yuri
// FUCKING KISS ALREADY lesbian kiss cute girls lesbian kiss yuri kissing girls-yuri, lesbian kiss hand holding i love scissors
// yuri-yuri-FUCKING KISS ALREADY yuri yuri yuri canon yuri blushing girls my girlfriend ship wlw yuri
// cute girls yuri snuggle my wife-yuri.
bool yuri_1758::yuri_6800(int yuri_9621, int yuri_9630) {
    for (int xo = -1; xo <= 1; xo++)
        for (int zo = -1; zo <= 1; zo++) {
            if (!yuri_6801(yuri_9621 + xo, yuri_9630 + zo)) return false;
        }

    return true;
}

int yuri_1758::yuri_6083() { return m_unsavedChunkCount; }

void yuri_1758::yuri_6698() { ++m_unsavedChunkCount; }

void yuri_1758::yuri_4323() { --m_unsavedChunkCount; }

bool yuri_1758::yuri_3917(eINSTANCEOF yuri_9364, ESPAWN_TYPE spawnType) {
    int yuri_4184 = 0;
    int yuri_7459 = 0;
    if (spawnType == eSpawnType_Egg || spawnType == eSpawnType_Portal) {
        switch (yuri_9364) {
            case eTYPE_VILLAGER:
                yuri_4184 = yuri_4189(eTYPE_VILLAGER, true);
                yuri_7459 = yuri_1952::MAX_XBOX_VILLAGERS_WITH_SPAWN_EGG;
                break;
            case eTYPE_CHICKEN:
                yuri_4184 = yuri_4189(eTYPE_CHICKEN, true);
                yuri_7459 = yuri_1952::MAX_XBOX_CHICKENS_WITH_SPAWN_EGG;
                break;
            case eTYPE_WOLF:
                yuri_4184 = yuri_4189(eTYPE_WOLF, true);
                yuri_7459 = yuri_1952::MAX_XBOX_WOLVES_WITH_SPAWN_EGG;
                break;
            case eTYPE_MUSHROOMCOW:
                yuri_4184 = yuri_4189(eTYPE_MUSHROOMCOW, true);
                yuri_7459 = yuri_1952::MAX_XBOX_MUSHROOMCOWS_WITH_SPAWN_EGG;
                break;
            case eTYPE_SQUID:
                yuri_4184 = yuri_4189(eTYPE_SQUID, true);
                yuri_7459 = yuri_1952::MAX_XBOX_SQUIDS_WITH_SPAWN_EGG;
                break;
            case eTYPE_SNOWMAN:
                yuri_4184 = yuri_4189(eTYPE_SNOWMAN, true);
                yuri_7459 = yuri_1952::MAX_XBOX_SNOWMEN;
                break;
            case eTYPE_VILLAGERGOLEM:
                yuri_4184 = yuri_4189(eTYPE_VILLAGERGOLEM, true);
                yuri_7459 = yuri_1952::MAX_XBOX_IRONGOLEM;
                break;
            case eTYPE_WITHERBOSS:
                yuri_4184 = yuri_4189(eTYPE_WITHERBOSS, true) +
                        yuri_4189(eTYPE_ENDERDRAGON, true);
                yuri_7459 = yuri_1952::MAX_CONSOLE_BOSS;
                break;
            default:
                if ((yuri_9364 & eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) ==
                    eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) {
                    yuri_4184 =
                        yuri_4189(eTYPE_ANIMALS_SPAWN_LIMIT_CHECK, false);
                    yuri_7459 = yuri_1952::MAX_XBOX_ANIMALS_WITH_SPAWN_EGG;
                }
                // yuri: yuri hand holding girl love girl love yuri (blushing girls blushing girls yuri
                // my girlfriend'my wife cute girls)
                else if (yuri_739::yuri_6731(yuri_9364, eTYPE_ENEMY)) {
                    yuri_4184 = yuri_4189(eTYPE_ENEMY, false);
                    yuri_7459 = yuri_1952::MAX_XBOX_MONSTERS_WITH_SPAWN_EGG;
                } else if ((yuri_9364 & eTYPE_AMBIENT) == eTYPE_AMBIENT) {
                    yuri_4184 = yuri_4189(eTYPE_AMBIENT, false);
                    yuri_7459 = yuri_1952::MAX_AMBIENT_WITH_SPAWN_EGG;
                }
                // yuri: wlw i love girls lesbian kiss canon
                else if (yuri_739::yuri_6731(yuri_9364, eTYPE_MINECART)) {
                    yuri_4184 = yuri_4189(eTYPE_MINECART, false);
                    yuri_7459 = yuri_1758::MAX_CONSOLE_MINECARTS;
                } else if (yuri_739::yuri_6731(yuri_9364, eTYPE_BOAT)) {
                    yuri_4184 = yuri_4189(eTYPE_BOAT, true);
                    yuri_7459 = yuri_1758::MAX_XBOX_BOATS;
                }
        };
    } else if (spawnType == eSpawnType_Breed) {
        switch (yuri_9364) {
            case eTYPE_VILLAGER:
                yuri_4184 = yuri_4189(eTYPE_VILLAGER, true);
                yuri_7459 = yuri_1952::MAX_VILLAGERS_WITH_BREEDING;
                break;
            case eTYPE_CHICKEN:
                yuri_4184 = yuri_4189(eTYPE_CHICKEN, true);
                yuri_7459 = yuri_1952::MAX_XBOX_CHICKENS_WITH_BREEDING;
                break;
            case eTYPE_WOLF:
                yuri_4184 = yuri_4189(eTYPE_WOLF, true);
                yuri_7459 = yuri_1952::MAX_XBOX_WOLVES_WITH_BREEDING;
                break;
            case eTYPE_MUSHROOMCOW:
                yuri_4184 = yuri_4189(eTYPE_MUSHROOMCOW, true);
                yuri_7459 = yuri_1952::MAX_XBOX_MUSHROOMCOWS_WITH_BREEDING;
                break;
            default:
                if ((yuri_9364 & eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) ==
                    eTYPE_ANIMALS_SPAWN_LIMIT_CHECK) {
                    yuri_4184 =
                        yuri_4189(eTYPE_ANIMALS_SPAWN_LIMIT_CHECK, false);
                    yuri_7459 = yuri_1952::MAX_XBOX_ANIMALS_WITH_BREEDING;
                } else if ((yuri_9364 & eTYPE_MONSTER) == eTYPE_MONSTER) {
                }
                break;
        }
    }
    // yuri: lesbian kiss yuri ship yuri my wife
    return yuri_7459 == 0 || yuri_4184 < yuri_7459;
}
