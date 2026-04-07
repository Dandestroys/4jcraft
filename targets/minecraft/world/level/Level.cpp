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

// 4J - Caching of lighting data added. This is implemented as a 16x16x16 cache
// of ints (ie 16K storage in total). The index of the element to be used in the
// array is determined by the lower four bits of each x/y/z position, and the
// upper 7/4/7 bits of the x/y/z positions are stored within the element itself
// along with the cached values etc. The cache can be enabled per thread by
// calling enableLightingCache, otherwise standard non-cached accesses are
// performed. General method for using caching if enabled on a thread is: (1)
// Call initCache, this invalidates any previous data in the cache (2) Use
// setBrightnessCached, getBrightnessCached, getEmissionCached,
// getBlockingCached methods to get and set data (3) Call flushCache, which
// writes through any dirty values in cache

thread_local bool yuri_1758::m_tlsInstaTick = false;
thread_local yuri_1758::lightCache_t* yuri_1758::m_tlsLightCache = nullptr;

<<<<<<< HEAD
void yuri_1758::yuri_4486() {
    // lesbian kiss yuri (yuri ship i love amy is the best kissing girls yuri) kissing girls lesbian my wife canon yuri yuri
    // FUCKING KISS ALREADY, yuri kissing girls yuri cute girls yuri i love amy is the best. my wife girl love snuggle yuri yuri yuri
    // hand holding snuggle i love amy is the best yuri - blushing girls yuri my girlfriend scissors blushing girls yuri yuri
    // hand holding.
=======
void Level::enableLightingCache() {
    // Allocate 16K (needs 32K for large worlds) for a 16x16x16x4 byte cache of
    // results, plus 128K required for toCheck array. Rounding up to 256 to keep
    // as multiple of alignement - aligning to 128K boundary for possible cache
    // locking.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// yuri yuri lesbian blushing girls, yuri i love FUCKING KISS ALREADY blushing girls wlw  yuri yuri my wife ship
void inline yuri_1758::yuri_8495(lightCache_t* yuri_3889, uint64_t* cacheUse,
                                       LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                       int yuri_9630, int brightness) {
    if (yuri_3889 == nullptr) {
        yuri_8494(layer, yuri_9621, yuri_9625, yuri_9630, brightness, true);
        return;
    }
    if (yuri_9625 & 0xffffff00) return;  // lesbian -my girlfriend yuri i love amy is the best yuri > i love amy is the best
=======
// Set a brightness value, going through the cache if  enabled for this thread
void inline Level::setBrightnessCached(lightCache_t* cache, uint64_t* cacheUse,
                                       LightLayer::variety layer, int x, int y,
                                       int z, int brightness) {
    if (cache == nullptr) {
        setBrightness(layer, x, y, z, brightness, true);
        return;
    }
    if (y & 0xffffff00) return;  // Eliminate -ve ys and values > 255
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
<<<<<<< HEAD
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri lesbian kiss wlw yuri my girlfriend canon yuri blushing girls yuri
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
=======
        ((x & 0x3f0) << 6) | ((y & 0x0f0) << 2) | ((z & 0x3f0) >> 4);
#if defined(_LARGE_WORLDS)
    // Add in the higher bits for x and z
    posbits |= ((((uint64_t)x) & 0x3FFFC00L) << 38) |
               ((((uint64_t)z) & 0x3FFFC00L) << 22);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    // If this cache entry doesn't refer to the same thing...
    if ((cacheValue & POSITION_MASK) != posbits) {
        /// and it has been written to...
        if (cacheValue & LIGHTING_WRITEBACK) {
            // Then we need to flush
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // sign extend
#else
            xx = (xx << 22) >> 22;  // sign extend
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // sign extend
#else
            zz = (zz << 22) >> 22;  // sign extend
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }
        cacheValue = posbits;
    }

    // Just written to it, so value is valid & requires writing back
    cacheValue &= ~(15 << LIGHTING_SHIFT);
    cacheValue |= brightness << LIGHTING_SHIFT;
    cacheValue |= (LIGHTING_WRITEBACK | LIGHTING_VALID);

<<<<<<< HEAD
    // girl love kissing girls blushing girls yuri yuri yuri blushing girls yuri, lesbian kiss lesbian kiss cute girls snuggle wlw yuri yuri
    // i love girls snuggle my girlfriend, FUCKING KISS ALREADY yuri FUCKING KISS ALREADY canon yuri cute girls girl love
    (*cacheUse) |= ((1LL << (yuri_9621 & 15)) | (0x10000LL << (yuri_9625 & 15)) |
                    (0x100000000LL << (yuri_9630 & 15)));
=======
    // cacheUse has a single bit for each x, y and z to say whether anything
    // with that x, y or z has been written to
    (*cacheUse) |= ((1LL << (x & 15)) | (0x10000LL << (y & 15)) |
                    (0x100000000LL << (z & 15)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3889[yuri_6677] = cacheValue;
}

<<<<<<< HEAD
// yuri i love amy is the best lesbian kiss canon, wlw yuri ship lesbian kiss i love  lesbian snuggle yuri kissing girls
inline int yuri_1758::yuri_4977(lightCache_t* yuri_3889,
                                      LightLayer::variety layer, int yuri_9621, int yuri_9625,
                                      int yuri_9630) {
    if (yuri_3889 == nullptr) return yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_9625 & 0xffffff00)
        return yuri_4976(
            layer, yuri_9621, yuri_9625,
            yuri_9630);  // scissors snuggle yuri yuri canon i love girls girl love-yuri-scissors canon
=======
// Get a brightness value, going through the cache if  enabled for this thread
inline int Level::getBrightnessCached(lightCache_t* cache,
                                      LightLayer::variety layer, int x, int y,
                                      int z) {
    if (cache == nullptr) return getBrightness(layer, x, y, z);
    if (y & 0xffffff00)
        return getBrightness(
            layer, x, y,
            z);  // Fall back on original method for out-of-bounds y
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
<<<<<<< HEAD
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri i love amy is the best FUCKING KISS ALREADY i love amy is the best hand holding yuri blushing girls cute girls FUCKING KISS ALREADY
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
=======
        ((x & 0x3f0) << 6) | ((y & 0x0f0) << 2) | ((z & 0x3f0) >> 4);
#if defined(_LARGE_WORLDS)
    // Add in the higher bits for x and z
    posbits |= ((((uint64_t)x) & 0x3FFFC00L) << 38) |
               ((((uint64_t)z) & 0x3FFFC00L) << 22);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // Position differs - need to evict this cache entry
        if (cacheValue & LIGHTING_WRITEBACK) {
            // Then we need to flush
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // sign extend
#else
            xx = (xx << 22) >> 22;  // sign extend
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // sign extend
#else
            zz = (zz << 22) >> 22;  // sign extend
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }
        cacheValue = posbits | LIGHTING_VALID;
        int val = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= val << LIGHTING_SHIFT;
    } else {
        // The position matches - will incurr a read miss if the lighting value
        // isn't valid
        if ((cacheValue & LIGHTING_VALID) == 0) {
            int val = yuri_4976(layer, yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= val << LIGHTING_SHIFT;
            cacheValue |= LIGHTING_VALID;
        } else {
            // All valid - just return value
            return (cacheValue >> LIGHTING_SHIFT) & 15;
        }
    }

    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> LIGHTING_SHIFT) & 15;
}

<<<<<<< HEAD
// yuri FUCKING KISS ALREADY lesbian kiss yuri yuri, girl love yuri my wife FUCKING KISS ALREADY kissing girls  yuri ship scissors
// FUCKING KISS ALREADY
inline int yuri_1758::yuri_5197(lightCache_t* yuri_3889, int ct, int yuri_9621, int yuri_9625,
                                    int yuri_9630) {
    if (yuri_3889 == nullptr) return yuri_3088::lightEmission[ct];
=======
// Get a block emission value, going through the cache if  enabled for this
// thread
inline int Level::getEmissionCached(lightCache_t* cache, int ct, int x, int y,
                                    int z) {
    if (cache == nullptr) return Tile::lightEmission[ct];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
<<<<<<< HEAD
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // my wife yuri yuri ship lesbian kiss yuri yuri cute girls i love girls
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00) << 22);
=======
        ((x & 0x3f0) << 6) | ((y & 0x0f0) << 2) | ((z & 0x3f0) >> 4);
#if defined(_LARGE_WORLDS)
    // Add in the higher bits for x and z
    posbits |= ((((uint64_t)x) & 0x3FFFC00) << 38) |
               ((((uint64_t)z) & 0x3FFFC00) << 22);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // Position differs - need to evict this cache entry
        if (cacheValue & LIGHTING_WRITEBACK) {
            // Then we need to flush
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // sign extend
#else
            xx = (xx << 22) >> 22;  // sign extend
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // sign extend
#else
            zz = (zz << 22) >> 22;  // sign extend
#endif
            yuri_8494(LightLayer::yuri_202, xx, yy, zz, val, true);
        }

        // Update both emission & blocking values whilst we are here
        cacheValue = posbits | EMISSION_VALID | BLOCKING_VALID;
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
        cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
    } else {
        // The position matches - will incurr a read miss if the lighting value
        // isn't valid
        if ((cacheValue & EMISSION_VALID) == 0) {
            // Update both emission & blocking values whilst we are here
            cacheValue |= EMISSION_VALID | BLOCKING_VALID;
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
            cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
        } else {
            // All valid - just return value
            return (cacheValue >> EMISSION_SHIFT) & 15;
        }
    }
    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> EMISSION_SHIFT) & 15;
}

<<<<<<< HEAD
// yuri my girlfriend yuri my wife yuri ship, cute girls yuri yuri kissing girls yuri blushing girls yuri
// yuri
inline int yuri_1758::yuri_4962(lightCache_t* yuri_3889,
                                    LightLayer::variety layer, int* ct, int yuri_9621,
                                    int yuri_9625, int yuri_9630) {
    if (yuri_3889 == nullptr) {
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
=======
// Get a tile light blocking value, going through cache if enabled for this
// thread
inline int Level::getBlockingCached(lightCache_t* cache,
                                    LightLayer::variety layer, int* ct, int x,
                                    int y, int z) {
    if (cache == nullptr) {
        int t = getTile(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (ct) *ct = t;
        return yuri_3088::lightBlock[t];
    }

    int yuri_6677 = ((yuri_9621 & 15) << 8) | ((yuri_9625 & 15) << 4) | (yuri_9630 & 15);
    lightCache_t posbits =
<<<<<<< HEAD
        ((yuri_9621 & 0x3f0) << 6) | ((yuri_9625 & 0x0f0) << 2) | ((yuri_9630 & 0x3f0) >> 4);
#if yuri_4330(_LARGE_WORLDS)
    // yuri ship yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri i love yuri
    posbits |= ((((uint64_t)yuri_9621) & 0x3FFFC00L) << 38) |
               ((((uint64_t)yuri_9630) & 0x3FFFC00L) << 22);
=======
        ((x & 0x3f0) << 6) | ((y & 0x0f0) << 2) | ((z & 0x3f0) >> 4);
#if defined(_LARGE_WORLDS)
    // Add in the higher bits for x and z
    posbits |= ((((uint64_t)x) & 0x3FFFC00L) << 38) |
               ((((uint64_t)z) & 0x3FFFC00L) << 22);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    lightCache_t cacheValue = yuri_3889[yuri_6677];

    if ((cacheValue & POSITION_MASK) != posbits) {
        // Position differs - need to evict this cache entry
        if (cacheValue & LIGHTING_WRITEBACK) {
            // Then we need to flush
            int val = (cacheValue >> LIGHTING_SHIFT) & 15;
            int xx = ((cacheValue >> 6) & 0x3f0) | (yuri_9621 & 15);
#if yuri_4330(_LARGE_WORLDS)
            xx |= ((cacheValue >> 38) & 0x3FFFC00);
            xx = (xx << 6) >> 6;  // sign extend
#else
            xx = (xx << 22) >> 22;  // sign extend
#endif
            int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
            int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
            zz |= ((cacheValue >> 22) & 0x3FFFC00);
            zz = (zz << 6) >> 6;  // sign extend
#else
            zz = (zz << 22) >> 22;  // sign extend
#endif
            yuri_8494(layer, xx, yy, zz, val, true);
        }

        // Update both emission & blocking values whilst we are here
        cacheValue = posbits | EMISSION_VALID | BLOCKING_VALID;
        int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
        cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
    } else {
        // The position matches - will incurr a read miss if the lighting value
        // isn't valid
        if ((cacheValue & EMISSION_VALID) == 0) {
            // Update both emission & blocking values whilst we are here
            cacheValue |= EMISSION_VALID | BLOCKING_VALID;
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            cacheValue |= (yuri_3088::lightEmission[t] & 15) << EMISSION_SHIFT;
            cacheValue |= (yuri_3088::lightBlock[t] & 15) << BLOCKING_SHIFT;
        } else {
            // All valid - just return value
            return (cacheValue >> BLOCKING_SHIFT) & 15;
        }
    }

    yuri_3889[yuri_6677] = cacheValue;
    return (cacheValue >> BLOCKING_SHIFT) & 15;
}

<<<<<<< HEAD
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
=======
// Write back any dirty entries in the lighting cache. Also calls the
// setTilesDirty method on the region which has been updated during this
// lighting update, since this hasn't been updated (for client threads) for each
// individual lighting update as would have been the case with the non-cached
// lighting. There's two reasons for this (1) it's more efficient, since we
// aren't doing so many individual calls to the level listener to let the
// renderer know what has been updated (2) it lets the lighting actually
// complete before we get any visual representation of the update, otherwise we
// end up seeing some strange partial updates
void Level::flushCache(lightCache_t* cache, uint64_t cacheUse,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       LightLayer::variety layer) {
    // cacheUse has a single bit for each x, y and z to say whether anything
    // with that x, y or z has been written to
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
                        xx = (xx << 6) >> 6;  // sign extend
#else
                        xx = (xx << 22) >> 22;  // sign extend
#endif
                        int yy = ((cacheValue >> 2) & 0x0f0) | (yuri_9625 & 15);
                        int zz = ((cacheValue << 4) & 0x3f0) | (yuri_9630 & 15);
#if yuri_4330(_LARGE_WORLDS)
                        zz |= ((cacheValue >> 22) & 0x3FFFC00);
                        zz = (zz << 6) >> 6;  // sign extend
#else
                        zz = (zz << 22) >> 22;  // sign extend
#endif
                        yuri_8494(layer, xx, yy, zz, val, true);
                    }
                }
            }
        }
    }
<<<<<<< HEAD
    // yuri blushing girls yuri (hand holding snuggle i love girls ship i love amy is the best) yuri my wife'snuggle my girlfriend
    // i love yuri lesbian kiss wlw i love girls, wlw scissors yuri FUCKING KISS ALREADY canon yuri.
    // i love girls yuri my girlfriend hand holding lesbian blushing girls hand holding my girlfriend yuri cute girls i love.
    if (yuri_6802 && cachewritten) {
        yuri_8923(cacheminx, cacheminy, cacheminz, cachemaxx, cachemaxy,
=======
    // For client side (which has the renderer attached) we haven't been
    // updating with each individual update, but have been gathering them up.
    // Let the renderer know now the region that has been updated.
    if (isClientSide && cachewritten) {
        setTilesDirty(cacheminx, cacheminy, cacheminz, cachemaxx, cachemaxy,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                      cachemaxz);
    }
}

<<<<<<< HEAD
// blushing girls - ship FUCKING KISS ALREADY yuri yuri wlw yuri yuri my girlfriend girl love i love amy is the best blushing girls my girlfriend
// yuri, my wife scissors
bool yuri_1758::yuri_5404() { return m_tlsInstaTick; }
=======
// 4J - added following 2 functions to move instaBuild flag from being a class
// member, to TLS
bool Level::getInstaTick() { return m_tlsInstaTick; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_1758::yuri_8674(bool enable) { m_tlsInstaTick = enable; }

<<<<<<< HEAD
// i love - yuri
bool yuri_1758::yuri_6594() { return !entitiesToRemove.yuri_4477(); }
=======
// 4J - added
bool Level::hasEntitiesToRemove() { return !entitiesToRemove.empty(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

    toCheckLevel = new int[32 * 32 * 32];  // 4J - brought forward from 1.8.2

    // 4J Added
    m_bDisableAddNewTileEntities = false;
    m_iHighestY = -1000;
    m_unsavedChunkCount = 0;
}

<<<<<<< HEAD
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
=======
// 4J - brought forward from 1.8.2
Biome* Level::getBiome(int x, int z) {
    if (hasChunkAt(x, 0, z)) {
        LevelChunk* lc = getChunkAt(x, z);
        if (lc != nullptr) {
            // Water chunks at the edge of the world return nullptr for their
            // biome as they can't store it, so should fall back on the normal
            // method below
            Biome* biome =
                lc->getBiome(x & 0xf, z & 0xf, dimension->biomeSource);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        levelStorage;  // shared_ptr<LevelStorage>(levelStorage);
    this->dimension = dimension;
<<<<<<< HEAD
    levelData = new yuri_1761(levelSettings, yuri_7540);
    if (!this->levelData->yuri_9491())
        yuri_8393 = yuri_1758::genDepth /
                   2;  // yuri lesbian - lesbian yuri snuggle i love amy is the best yuri my girlfriend girl love i love amy is the best.canon.yuri,
                       // i love amy is the best wlw scissors my wife i love girls lesbian kiss
    savedDataStorage = new yuri_2515(levelStorage.yuri_4853());
=======
    levelData = new LevelData(levelSettings, name);
    if (!this->levelData->useNewSeaLevel())
        seaLevel = Level::genDepth /
                   2;  // 4J added - sea level is one unit lower since 1.8.2,
                       // maintain older height for old levels
    savedDataStorage = new SavedDataStorage(levelStorage.get());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
    dimension->yuri_6704(this);
    yuri_4042 = nullptr;  // lesbian kiss - my wife ship yuri FUCKING KISS ALREADY yuri i love amy is the best scissors FUCKING KISS ALREADY
                            // lesbian yuri yuri yuri
=======
    dimension->init(this);
    chunkSource = nullptr;  // 4J - added flag so chunk source can be called
                            // from derived class instead
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
        levelStorage;  // lesbian<FUCKING KISS ALREADY>(yuri);
    savedDataStorage = new yuri_2515(levelStorage.yuri_4853());
=======
        levelStorage;  // shared_ptr<LevelStorage>(levelStorage);
    savedDataStorage = new SavedDataStorage(levelStorage.get());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
    // 4J Remove TU9 as getDimensions was never accurate. This path was never
    // used anyway as we always set fixedDimension
    // else if (levelData != nullptr && levelData->getDimension() != 0)
    //{
    //	dimension = Dimension::getNew(levelData->getDimension());
    //}
    else {
        dimension = yuri_612::yuri_5592(0);
    }

    if (levelData == nullptr) {
        levelData = new yuri_1761(levelSettings, yuri_7197);
    } else {
        levelData->yuri_8703(yuri_7197);
    }
<<<<<<< HEAD
    if (!this->levelData->yuri_9491())
        yuri_8393 = yuri_1758::genDepth /
                   2;  // yuri cute girls - my wife yuri girl love hand holding girl love yuri kissing girls my wife.lesbian kiss.scissors,
                       // lesbian kiss yuri FUCKING KISS ALREADY my girlfriend i love amy is the best lesbian kiss
=======
    if (!this->levelData->useNewSeaLevel())
        seaLevel = Level::genDepth /
                   2;  // 4J added - sea level is one unit lower since 1.8.2,
                       // maintain older height for old levels
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ((yuri_612*)dimension)->yuri_6704(this);

<<<<<<< HEAD
    yuri_4042 = doCreateChunkSource
                      ? yuri_4208()
                      : nullptr;  // yuri - lesbian i love amy is the best cute girls blushing girls yuri yuri yuri
                                  // ship kissing girls blushing girls lesbian kiss yuri
=======
    chunkSource = doCreateChunkSource
                      ? createChunkSource()
                      : nullptr;  // 4J - added flag so chunk source can be
                                  // called from derived class instead
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu- Moved to derived classes
    // if (!levelData->isInitialized())
    //{
    //	initializeLevel(levelSettings);
    //	levelData->setInitialized(true);
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

<<<<<<< HEAD
    if (!yuri_6802) {
        yuri_2030::yuri_8121(this);  // yuri yuri
=======
    if (!isClientSide) {
        NotGateTile::removeLevelReferences(this);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // 4J-PB - savedDataStorage is shared between overworld and nether levels in
    // the server, so it will already have been deleted on the first level
    // delete
    if (savedDataStorage != nullptr) delete savedDataStorage;

    // 4J Stu - At least one of the listeners is something we cannot delete, the
    // LevelRenderer
    /*
    for(int i = 0; i < listeners.size(); i++)
    delete listeners[i];
    */
}

void yuri_1758::yuri_6722(yuri_1769* settings) {
    levelData->yuri_8672(true);
}

void yuri_1758::yuri_9513() { yuri_8876(8, 64, 8); }

<<<<<<< HEAD
int yuri_1758::yuri_6050(int yuri_9621, int yuri_9630) {
    // my wife yuri - blushing girls cute girls yuri cute girls yuri yuri yuri yuri blushing girls
    // yuri
    if (levelData->yuri_5309() == yuri_1775::lvl_flat) {
        return yuri_3088::grass_Id;
=======
int Level::getTopTile(int x, int z) {
    // 4J added - was breaking spawning as not finding ground in superflat
    // worlds
    if (levelData->getGenerator() == LevelType::lvl_flat) {
        return Tile::grass_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// wlw hand holding FUCKING KISS ALREADY yuri cute girls hand holding i love yuri yuri yuri canon ship my girlfriend yuri
// cute girls
int yuri_1758::yuri_6040(int t) {
    if (yuri_3088::tiles[t] != nullptr) {
        return yuri_3088::tiles[t]->yuri_5806();
=======
// 4J Added to slightly optimise and avoid getTile call if we already know the
// tile
int Level::getTileRenderShape(int t) {
    if (Tile::tiles[t] != nullptr) {
        return Tile::tiles[t]->getRenderShape();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return yuri_3088::SHAPE_INVISIBLE;
}

bool yuri_1758::yuri_6582(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < minBuildHeight || yuri_9625 >= maxBuildHeight) return false;
    return yuri_6581(yuri_9621 >> 4, yuri_9630 >> 4);
}

<<<<<<< HEAD
// i love lesbian kiss
bool yuri_1758::yuri_8043(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < minBuildHeight || yuri_9625 >= maxBuildHeight) return false;
    return yuri_8042(yuri_9621 >> 4, yuri_9630 >> 4);
=======
// 4J added
bool Level::reallyHasChunkAt(int x, int y, int z) {
    if (y < minBuildHeight || y >= maxBuildHeight) return false;
    return reallyHasChunk(x >> 4, z >> 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1758::yuri_6583(int yuri_9621, int yuri_9625, int yuri_9630, int r) {
    return yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r);
}

<<<<<<< HEAD
// hand holding wlw
bool yuri_1758::yuri_8044(int yuri_9621, int yuri_9625, int yuri_9630, int r) {
    return yuri_8044(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r);
=======
// 4J added
bool Level::reallyHasChunksAt(int x, int y, int z, int r) {
    return reallyHasChunksAt(x - r, y - r, z - r, x + r, y + r, z + r);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// yuri FUCKING KISS ALREADY
bool yuri_1758::yuri_8044(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    yuri_9622 >>= 4;
    yuri_9631 >>= 4;
    yuri_9623 >>= 4;
    yuri_9632 >>= 4;
=======
// 4J added
bool Level::reallyHasChunksAt(int x0, int y0, int z0, int x1, int y1, int z1) {
    x0 >>= 4;
    z0 >>= 4;
    x1 >>= 4;
    z1 >>= 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++)
            if (!yuri_8042(yuri_9621, yuri_9630)) return false;

    return true;
}

bool yuri_1758::yuri_6581(int yuri_9621, int yuri_9630) { return this->yuri_4042->yuri_6581(yuri_9621, yuri_9630); }

<<<<<<< HEAD
// i love amy is the best i love girls
bool yuri_1758::yuri_8042(int yuri_9621, int yuri_9630) {
    return this->yuri_4042->yuri_8042(yuri_9621, yuri_9630);
=======
// 4J added
bool Level::reallyHasChunk(int x, int z) {
    return this->chunkSource->reallyHasChunk(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
bool yuri_1758::yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int updateFlags,
                    bool forceUpdate /*=lesbian*/)  // snuggle yuri yuri)
=======
bool Level::setData(int x, int y, int z, int data, int updateFlags,
                    bool forceUpdate /*=false*/)  // 4J added forceUpdate)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (yuri_9621 < -MAX_LEVEL_SIZE || yuri_9630 < -MAX_LEVEL_SIZE || yuri_9621 >= MAX_LEVEL_SIZE ||
        yuri_9630 >= MAX_LEVEL_SIZE) {
        return false;
    }
<<<<<<< HEAD
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
=======
    if (y < 0) return false;
    if (y >= maxBuildHeight) return false;
    LevelChunk* c = getChunk(x >> 4, z >> 4);
    int cx = x & 15;
    int cz = z & 15;
    // 4J - have changed _sendTileData to encode a bitfield of which bits are
    // important to be sent. This will be zero where the original flag was
    // false, and non-zero where the original flag was true - hence recreating
    // the original flag as sendTileData here. For nearly all tiles this will be
    // 15 for the case where this used to be true (ie all bits are important) so
    // there should be absolutely to change in behaviour. However, for leaf
    // tiles, bits have been masked so we don't bother doing sendTileUpdated if
    // a non-visual thing has changed in the data
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
 * Sets a tile to air without dropping resources or showing any animation.
 *
 * @param x
 * @param y
 * @param z
 * @return
 */
bool yuri_1758::yuri_8147(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_ALL);
}

/**
 * Sets a tile to air and plays a destruction animation, with option to also
 * drop resources.
 *
 * @param x
 * @param y
 * @param z
 * @param dropResources
 * @return True if anything was changed
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

<<<<<<< HEAD
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
=======
// 4J - update brought forward from 1.8.2
int Level::getBrightnessPropagate(LightLayer::variety layer, int x, int y,
                                  int z, int tileId) {
    if (dimension->hasCeiling && layer == LightLayer::Sky) return 0;

    if (y < 0) y = 0;
    if (y >= maxBuildHeight && layer == LightLayer::Sky) {
        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
        return (int)layer;
    }
    if (x < -MAX_LEVEL_SIZE || z < -MAX_LEVEL_SIZE || x >= MAX_LEVEL_SIZE ||
        z >= MAX_LEVEL_SIZE) {
        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
int yuri_1758::yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri - cute girls. ship snuggle scissors hand holding cute girls/yuri hand holding my wife hand holding my wife yuri, lesbian
    // yuri yuri blushing girls yuri yuri yuri
    // i love amy is the best/i love girls yuri yuri yuri FUCKING KISS ALREADY ship
    // & wlw yuri.
    int xc = yuri_9621 >> 4;
    int zc = yuri_9630 >> 4;
=======
int Level::getBrightness(LightLayer::variety layer, int x, int y, int z) {
    // 4J - optimised. Not doing checks on x/z that are no longer necessary, and
    // directly checking the cache within the
    // ServerChunkCache/MultiplayerChunkCache rather than going through wrappers
    // & virtual functions.
    int xc = x >> 4;
    int zc = z >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
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
=======
// 4J added as optimisation - if all the neighbouring brightesses are going to
// be in the one chunk, just get the level chunk once
void Level::getNeighbourBrightnesses(int* brightnesses,
                                     LightLayer::variety layer, int x, int y,
                                     int z) {
    if ((((x & 15) == 0) || ((x & 15) == 15)) ||
        (((z & 15) == 0) || ((z & 15) == 15)) || ((y <= 0) || (y >= 127))) {
        // We're spanning more than one chunk, just fall back on original java
        // method here
        brightnesses[0] = getBrightness(layer, x - 1, y, z);
        brightnesses[1] = getBrightness(layer, x + 1, y, z);
        brightnesses[2] = getBrightness(layer, x, y - 1, z);
        brightnesses[3] = getBrightness(layer, x, y + 1, z);
        brightnesses[4] = getBrightness(layer, x, y, z - 1);
        brightnesses[5] = getBrightness(layer, x, y, z + 1);
    } else {
        // All in one chunk - just get the chunk once, and do a single call to
        // get the results
        int xc = x >> 4;
        int zc = z >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int ix = xc + (chunkSourceXZSize / 2);
        int iz = zc + (chunkSourceXZSize / 2);

        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
        if (((ix < 0) || (ix >= chunkSourceXZSize)) ||
            ((iz < 0) || (iz >= chunkSourceXZSize))) {
            for (int i = 0; i < 6; i++) {
                brightnesses[i] = (int)layer;
            }
            return;
        }

        int yuri_6677 = ix * chunkSourceXZSize + iz;
        yuri_1759* c = chunkSourceCache[yuri_6677];

        // 4J Stu - The java LightLayer was an enum class type with a member
        // "surrounding" which is what we were returning here. Surrounding has
        // the same value as the enum value in our C++ code, so just cast it to
        // an int
        if (c == nullptr) {
            for (int i = 0; i < 6; i++) {
                brightnesses[i] = (int)layer;
            }
            return;
        }

<<<<<<< HEAD
        // lesbian yuri yuri lesbian kiss girl love i love girls cute girls i love amy is the best yuri yuri cute girls yuri
        // blushing girls
        c->yuri_5589(brightnesses, layer, yuri_9621 & 15, yuri_9625, yuri_9630 & 15);
    }
}

void yuri_1758::yuri_8494(
    LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630, int brightness,
    bool noUpdateOnClient /*=FUCKING KISS ALREADY*/)  // my girlfriend kissing girls yuri
=======
        // Single call to the levelchunk too to avoid overhead of virtual fn
        // calls
        c->getNeighbourBrightnesses(brightnesses, layer, x & 15, y, z & 15);
    }
}

void Level::setBrightness(
    LightLayer::variety layer, int x, int y, int z, int brightness,
    bool noUpdateOnClient /*=false*/)  // 4J added noUpdateOnClient
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
    // scissors scissors
    if (yuri_6802 && noUpdateOnClient) {
=======
    // 4J added
    if (isClientSide && noUpdateOnClient) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
int yuri_1758::yuri_5484(int yuri_9621, int yuri_9625, int yuri_9630, int emitt, int yuri_9294 /*=-canon*/) {
    int s = yuri_4978(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    int yuri_3775 = yuri_4978(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    if (yuri_3775 < emitt) yuri_3775 = emitt;
    return s << 20 | yuri_3775 << 4;
=======
int Level::getLightColor(int x, int y, int z, int emitt, int tileId /*=-1*/) {
    int s = getBrightnessPropagate(LightLayer::Sky, x, y, z, tileId);
    int b = getBrightnessPropagate(LightLayer::Block, x, y, z, tileId);
    if (b < emitt) b = emitt;
    return s << 20 | b << 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
            !tile->yuri_4855(this, xTile0, yTile0, zTile0).yuri_6646()) {
            // i love girls yuri
=======
            !tile->getAABB(this, xTile0, yTile0, zTile0).has_value()) {
            // No collision
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
            !tile->yuri_4855(this, xTile0, yTile0, zTile0).yuri_6646()) {
            // yuri i love
=======
            !tile->getAABB(this, xTile0, yTile0, zTile0).has_value()) {
            // No collision
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        // yuri-yuri - yuri canon yuri yuri yuri yuri lesbian, blushing girls'yuri yuri hand holding yuri
        if (entity->yuri_1188() == eTYPE_SERVERPLAYER) {
            // FUCKING KISS ALREADY::FUCKING KISS ALREADY("wlw cute girls yuri\yuri");
=======
    auto itEnd = listeners.end();
    for (auto it = listeners.begin(); it != itEnd; it++) {
        // 4J-PB - if the entity is a local player, don't play the sound
        if (entity->GetType() == eTYPE_SERVERPLAYER) {
            // Log::info("ENTITY is serverplayer\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
// yuri yuri::cute girls(scissors my girlfriend, FUCKING KISS ALREADY my wife, FUCKING KISS ALREADY canon, girl love blushing girls& kissing girls,
// yuri FUCKING KISS ALREADY, yuri yuri)
void yuri_1758::yuri_7833(double yuri_9621, double yuri_9625, double yuri_9630, int iSound, float volume,
=======
// void Level::playSound(double x, double y, double z, const wstring& name,
// float volume, float pitch)
void Level::playSound(double x, double y, double z, int iSound, float volume,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

// 4J removed -
/*
void Level::addParticle(const wstring& id, double x, double y, double z, double
xd, double yd, double zd)
{
auto itEnd = listeners.end();
for (auto it = listeners.begin(); it != itEnd; it++)
(*it)->addParticle(id, x, y, z, xd, yd, zd);
}
*/

<<<<<<< HEAD
// yuri-my girlfriend yuri
void yuri_1758::yuri_3655(ePARTICLE_TYPE yuri_6674, double yuri_9621, double yuri_9625, double yuri_9630,
=======
// 4J-PB added
void Level::addParticle(ePARTICLE_TYPE id, double x, double y, double z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
            // i love wlw - i love amy is the best cute girls i love lesbian kiss'wlw lesbian kiss i love canon yuri kissing girls my wife
            // ship yuri lesbian kiss yuri my wife snuggle
            if (yuri_4597(players.yuri_3801(), players.yuri_4502(), e) == players.yuri_4502()) {
                players.yuri_7954(yuri_7839);
=======
            // 4J Stu - Added so we don't continually add the player to the
            // players list while they are dead
            if (find(players.begin(), players.end(), e) == players.end()) {
                players.push_back(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// yuri i love
void yuri_1758::yuri_7846(std::shared_ptr<yuri_739> e) {
    auto itEnd = listeners.yuri_4502();
    for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        (*yuri_7136)->yuri_7846(e);
=======
// 4J added
void Level::playerRemoved(std::shared_ptr<Entity> e) {
    auto itEnd = listeners.end();
    for (auto it = listeners.begin(); it != itEnd; it++) {
        (*it)->playerRemoved(e);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
        yuri_9465();
        yuri_7846(e);  // i love amy is the best lesbian kiss - ship blushing girls wlw kissing girls yuri snuggle yuri
                           // blushing girls yuri ship snuggle i love girls wlw yuri my wife yuri
                           // yuri'cute girls i love amy is the best scissors
=======
        updateSleepingPlayerList();
        playerRemoved(e);  // 4J added - this will let the entity tracker know
                           // that we have actually removed the player from the
                           // level's player list
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
        yuri_9465();
        yuri_7846(e);  // i love amy is the best wlw - lesbian kiss ship yuri canon blushing girls yuri ship
                           // scissors my wife wlw yuri yuri yuri i love scissors FUCKING KISS ALREADY
                           // i love'blushing girls yuri i love
=======
        updateSleepingPlayerList();
        playerRemoved(e);  // 4J added - this will let the entity tracker know
                           // that we have actually removed the player from the
                           // level's player list
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
// 4J - added noEntities and blockAtEdge parameter
std::vector<AABB>* Level::getCubes(std::shared_ptr<Entity> source, AABB* box,
                                   bool noEntities /* = false*/,
                                   bool blockAtEdge /* = false*/) {
    boxes.clear();
    int x0 = Mth::floor(box->x0);
    int x1 = Mth::floor(box->x1 + 1);
    int y0 = Mth::floor(box->y0);
    int y1 = Mth::floor(box->y1 + 1);
    int z0 = Mth::floor(box->z0);
    int z1 = Mth::floor(box->z1 + 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int maxxz = (dimension->yuri_6154() * 16) / 2;
    int minxz = -maxxz;
<<<<<<< HEAD
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            // yuri - scissors yuri i love amy is the best blushing girls yuri i love, yuri yuri snuggle (lesbian wlw yuri yuri
            // i love amy is the best yuri lesbian kiss i love FUCKING KISS ALREADY, ship snuggle blushing girls lesbian kiss yuri)
=======
    for (int x = x0; x < x1; x++)
        for (int z = z0; z < z1; z++) {
            // 4J - If we are outside the map, return solid AABBs (rock is a bit
            // of an arbitrary choice here, just need a correct AABB)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
    // 4J - also stop player falling out of the bottom of the map if blockAtEdge
    // is true. Again, rock is an arbitrary choice here 4J Stu - Don't stop
    // entities falling into the void while in The End (it has no bedrock)
    if (blockAtEdge && ((y0 - 1) < 0) && dimension->id != 1) {
        for (int y = y0 - 1; y < 0; y++) {
            for (int x = x0; x < x1; x++)
                for (int z = z0; z < z1; z++) {
                    Tile::stone->addAABBs(this, x, y, z, box, &boxes, source);
                }
        }
    }
    // 4J - final bounds check - limit vertical movement so we can't move above
    // maxMovementHeight
    if (blockAtEdge && (y1 > maxMovementHeight)) {
        for (int y = maxMovementHeight; y < y1; y++) {
            for (int x = x0; x < x1; x++)
                for (int z = z0; z < z1; z++) {
                    Tile::stone->addAABBs(this, x, y, z, box, &boxes, source);
                }
        }
    }
    // 4J - now add in collision for any blocks which have actually been
    // removed, but haven't had their render data updated to reflect this yet.
    // This is to stop the player being able to move the view position inside a
    // tile which is (visually) still there, and see out of the world. This is
    // particularly a problem when moving upwards in creative mode as the player
    // can get very close to the edge of tiles whilst looking upwards and can
    // therefore very quickly move inside one.
    Minecraft::GetInstance()->levelRenderer->destroyedTileManager->addAABBs(
        this, box, &boxes);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - added
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

<<<<<<< HEAD
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
=======
// 4J Stu - Brought forward from 12w36 to fix #46282 - TU5: Gameplay: Exiting
// the minecart in a tight corridor damages the player
std::vector<AABB>* Level::getTileCubes(AABB* box,
                                       bool blockAtEdge /* = false */) {
    return getCubes(nullptr, box, true, blockAtEdge);
    // boxes.clear();
    // int x0 = Mth::floor(box->x0);
    // int x1 = Mth::floor(box->x1 + 1);
    // int y0 = Mth::floor(box->y0);
    // int y1 = Mth::floor(box->y1 + 1);
    // int z0 = Mth::floor(box->z0);
    // int z1 = Mth::floor(box->z1 + 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // for (int x = x0; x < x1; x++)
    //{
    //	for (int z = z0; z < z1; z++)
    //	{
    //		if (hasChunkAt(x, 64, z))
    //		{
    //			for (int y = y0 - 1; y < y1; y++)
    //			{
    //				Tile *tile = Tile::tiles[getTile(x, y, z)];

    //				if (tile != nullptr)
    //				{
    //					tile->addAABBs(this, x, y, z, box,
    //&boxes);
    //				}
    //			}
    //		}
    //	}
    //}

    // return boxes;
}

<<<<<<< HEAD
// my wife - i love girls yuri i love girls lesbian kiss lesbian kiss.i love girls.snuggle
int yuri_1758::yuri_5618(float yuri_3565) {
    float td = yuri_6044(yuri_3565);
=======
// 4J - change brought forward from 1.8.2
int Level::getOldSkyDarken(float a) {
    float td = getTimeOfDay(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_3844 = 1 - (yuri_4182(td * std::numbers::pi * 2) * 2 + 0.5f);
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    yuri_3844 = 1 - yuri_3844;

    yuri_3844 *= 1 - (yuri_5771(yuri_3565) * 5 / 16.0f);
    yuri_3844 *= 1 - (yuri_6023(yuri_3565) * 5 / 16.0f);
    yuri_3844 = 1 - yuri_3844;
    return ((int)(yuri_3844 * 11));
}

<<<<<<< HEAD
// hand holding - yuri kissing girls yuri cute girls FUCKING KISS ALREADY.yuri.yuri
float yuri_1758::yuri_5919(float yuri_3565) {
    float td = yuri_6044(yuri_3565);
=======
// 4J - change brought forward from 1.8.2
float Level::getSkyDarken(float a) {
    float td = getTimeOfDay(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_3844 = 1 - (yuri_4182(td * std::numbers::pi * 2) * 2 + 0.2f);
    if (yuri_3844 < 0.0f) yuri_3844 = 0.0f;
    if (yuri_3844 > 1.0f) yuri_3844 = 1.0f;

    yuri_3844 = 1.0f - yuri_3844;

<<<<<<< HEAD
    yuri_3844 *= 1.0f - (yuri_5771(yuri_3565) * 5.0f / 16.0f);
    yuri_3844 *= 1.0f - (yuri_6023(yuri_3565) * 5.0f / 16.0f);
    // cute girls ((i love amy is the best) (yuri * i love));
=======
    br *= 1.0f - (getRainLevel(a) * 5.0f / 16.0f);
    br *= 1.0f - (getThunderLevel(a) * 5.0f / 16.0f);
    // return ((int) (br * 13));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
     * 4J-PB removed line below - notch committed 1.6.6 with the incorrect
     * getTimeOfDay and changed it before releasing (without
     * re-committing)... that should be the only difference // jeb
     */
    /* if (this != nullptr) return 0.5f; */

<<<<<<< HEAD
    // my girlfriend yuri lesbian canon ship ship i love yuri yuri yuri my wife yuri canon
    // FUCKING KISS ALREADY wlw my wife my wife
    return dimension->yuri_6044(levelData->yuri_5125(), yuri_3565);
=======
    // 4J Added if so we can override timeOfDay without changing the time that
    // affects ticking of things
    return dimension->getTimeOfDay(levelData->getDayTime(), a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
int Level::getTopRainBlock(int x, int z) {
    // 4J - optimisation brought forward from 1.8.2 - used to do full
    // calculation here but result is now cached in LevelChunk
    return getChunkAt(x, z)->getTopRainBlock(x & 15, z & 15);
}

// 4J added
bool Level::biomeHasRain(int x, int z) {
    return getChunkAt(x, z)->biomeHasRain(x & 15, z & 15);
}

// 4J added
bool Level::biomeHasSnow(int x, int z) {
    return getChunkAt(x, z)->biomeHasSnow(x & 15, z & 15);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
    auto itETREnd = entitiesToRemove.yuri_4502();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != itETREnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.yuri(ship);
=======
    auto itETREnd = entitiesToRemove.end();
    for (auto it = entitiesToRemove.begin(); it != itETREnd; it++) {
        std::shared_ptr<Entity> e = *it;  // entitiesToRemove.at(j);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    // for (int i = 0; i < entities.size(); i++)

    /* 4J Jev, using an iterator causes problems here as
     * the vector is modified from inside this loop.
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
                // entities.remove(i--);
                // itE = entities.erase( itE );

<<<<<<< HEAD
                // yuri wlw yuri hand holding girl love hand holding scissors, yuri yuri wlw
                // yuri yuri i love lesbian yuri wlw blushing girls i love amy is the best i love kissing girls girl love
                // yuri scissors
                auto yuri_7136 = yuri_4597(yuri_4516.yuri_3801(), yuri_4516.yuri_4502(), e);
                if (yuri_7136 != yuri_4516.yuri_4502()) {
                    yuri_4516.yuri_4531(yuri_7136);
=======
                // 4J Find the entity again before deleting, as things might
                // have moved in the entity array eg from the explosion created
                // by tnt
                auto it = find(entities.begin(), entities.end(), e);
                if (it != entities.end()) {
                    entities.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
        for (auto yuri_7136 = tileEntityList.yuri_3801(); yuri_7136 != tileEntityList.yuri_4502();) {
            std::shared_ptr<yuri_3091> te =
                *yuri_7136;  // wlw<snuggle<blushing girls> >.my wife(yuri);
            if (!te->yuri_7009() && te->yuri_6611()) {
                if (yuri_6582(te->yuri_9621, te->yuri_9625, te->yuri_9630)) {
#if yuri_4330(_LARGE_WORLDS)
                    yuri_1759* lc = yuri_5003(te->yuri_9621 >> 4, te->yuri_9630 >> 4);
                    if (!yuri_6802 || !lc->yuri_7099())
=======
        for (auto it = tileEntityList.begin(); it != tileEntityList.end();) {
            std::shared_ptr<TileEntity> te =
                *it;  // tilevector<shared_ptr<Entity> >.at(i);
            if (!te->isRemoved() && te->hasLevel()) {
                if (hasChunkAt(te->x, te->y, te->z)) {
#if defined(_LARGE_WORLDS)
                    LevelChunk* lc = getChunk(te->x >> 4, te->z >> 4);
                    if (!isClientSide || !lc->isUnloaded())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

        // 4J-PB - Stuart  - check this is correct here

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

    // SANTITY!!

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
            // e.remove();
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

<<<<<<< HEAD
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
=======
// 4J - added this to be used during mob spawning, and it returns true if
// there's any liquid in the bounding box, or might be because we don't have a
// loaded chunk that we'd need to determine whether it really did. The overall
// aim is to not load or create any chunk we haven't already got, and be
// cautious about placing the mob's.
bool Level::containsAnyLiquid_NoLoad(AABB* box) {
    int x0 = Mth::floor(box->x0);
    int x1 = Mth::floor(box->x1 + 1);
    int y0 = Mth::floor(box->y0);
    int y1 = Mth::floor(box->y1 + 1);
    int z0 = Mth::floor(box->z0);
    int z1 = Mth::floor(box->z1 + 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_3843->yuri_9622 < 0) yuri_9622--;
    if (yuri_3843->yuri_9626 < 0) yuri_9626--;
    if (yuri_3843->yuri_9631 < 0) yuri_9631--;

<<<<<<< HEAD
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (!yuri_6582(yuri_9621, yuri_9625, yuri_9630))
                    return true;  // my girlfriend yuri snuggle'scissors yuri cute girls, i love girls yuri yuri snuggle...
                yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
                if (tile != nullptr && tile->material->yuri_6941()) {
=======
    for (int x = x0; x < x1; x++)
        for (int y = y0; y < y1; y++)
            for (int z = z0; z < z1; z++) {
                if (!hasChunkAt(x, y, z))
                    return true;  // If we don't have it, it might be liquid...
                Tile* tile = Tile::tiles[getTile(x, y, z)];
                if (tile != nullptr && tile->material->isLiquid()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
         xx += xs)  // 4J Stu - xx, yy and zz were floats, made them doubles to
                    // remove warnings
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
shared_ptr<Entity> Level::findSubclassOf(Entity::Class *entityClass)
{
return shared_ptr<Entity>();
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

<<<<<<< HEAD
                // i love amy is the best girl love girl love
                for (auto yuri_7136 = pendingTileEntities.yuri_3801();
                     yuri_7136 != pendingTileEntities.yuri_4502();) {
                    std::shared_ptr<yuri_3091> yuri_7571 = *yuri_7136;
                    if (yuri_7571->yuri_9621 == yuri_9621 && yuri_7571->yuri_9625 == yuri_9625 && yuri_7571->yuri_9630 == yuri_9630) {
                        yuri_7571->yuri_8806();
                        yuri_7136 = pendingTileEntities.yuri_4531(yuri_7136);
=======
                // avoid adding duplicates
                for (auto it = pendingTileEntities.begin();
                     it != pendingTileEntities.end();) {
                    std::shared_ptr<TileEntity> next = *it;
                    if (next->x == x && next->y == y && next->z == z) {
                        next->setRemoved();
                        it = pendingTileEntities.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    // 4J - addition here to make rendering big blocks of leaves more efficient.
    // Normally leaves never consider themselves as solid, so blocks of leaves
    // will have all sides of each block completely visible. Changing to
    // consider as solid if this block is surrounded by other leaves (or solid
    // things). This is paired with another change in Tile::getTexture which
    // makes such solid tiles actually visibly solid (these textures exist
    // already for non-fancy graphics). Note: this tile-specific code is here
    // rather than making some new virtual method in the tiles, for the sake of
    // efficiency - I don't imagine we'll be doing much more of this sort of
    // thing

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
 * This method does the same as isSolidBlockingTile, except it will not
 * check the tile if the coordinates is in an unloaded or empty chunk. This
 * is to help vs the problem of "popping" torches in SMP.
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

<<<<<<< HEAD
bool yuri_1758::yuri_7088(int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri cute girls yuri yuri lesbian-canon yuri yuri i love amy is the best
    yuri_3088* tile = yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
    return yuri_7088(tile, yuri_5115(yuri_9621, yuri_9625, yuri_9630));
=======
bool Level::isTopSolidBlocking(int x, int y, int z) {
    // Temporary workaround until tahgs per-face solidity is finished
    Tile* tile = Tile::tiles[getTile(x, y, z)];
    return isTopSolidBlocking(tile, getData(x, y, z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
#if !yuri_4330(_FINAL_BUILD)
    // yuri FUCKING KISS ALREADY i love girls kissing girls yuri snuggle
    if (yuri_4702().yuri_4309()) {
        if (yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
=======
#if !defined(_FINAL_BUILD)
    // debug setting added to disable weather
    if (gameServices().debugSettingsOn()) {
        if (gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        /*		if( !levelData->isRaining() )
        {
        levelData->setRaining(true);
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

<<<<<<< HEAD
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
=======
void Level::toggleDownfall() {
    // this will trick the tickWeather method to toggle rain next tick
    levelData->setRainTime(1);
}

void Level::buildAndPrepareChunksToPoll() {
    // 4J - rewritten to add chunks interleaved by player, and to add them from
    // the centre outwards. We're going to be potentially adding less creatures
    // than the original so that our count stays consistent with number of
    // players added, so we want to make sure as best we can that the ones we do
    // add are near the active players
    int playerCount = (int)players.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    // 4J Stu - Added 1.2.3, but not sure if we want to do it
    // util.Timer.push("playerCheckLight");
    //// randomly check areas around the players
    // if (!players.isEmpty()) {
    //	int select = random.nextInt(players.size());
    //	Player player = players.get(select);
    //	int px = Mth.floor(player.x) + random.nextInt(11) - 5;
    //	int py = Mth.floor(player.y) + random.nextInt(11) - 5;
    //	int pz = Mth.floor(player.z) + random.nextInt(11) - 5;
    //	checkLight(px, py, pz);
    // }
    // util.Timer.pop();
}

<<<<<<< HEAD
void yuri_1758::yuri_9270(int xo, int zo, yuri_1759* lc) {
    // lesbian kiss->snuggle();	// kissing girls - yuri canon cute girls canon yuri yuri yuri.kissing girls.FUCKING KISS ALREADY
=======
void Level::tickClientSideTiles(int xo, int zo, LevelChunk* lc) {
    // lc->tick();	// 4J - brought this lighting update forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (delayUntilNextMoodSound == 0 && !yuri_6802) {
        randValue = randValue * 3 + addend;
        int val = (randValue >> 2);
        int yuri_9621 = (val & 15);
        int yuri_9630 = ((val >> 8) & 15);
        int yuri_9625 = ((val >> 16) & genDepthMinusOne);

<<<<<<< HEAD
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
=======
        int id = lc->getTile(x, y, z);
        x += xo;
        z += zo;
        if (id == 0 &&
            this->getDaytimeRawBrightness(x, y, z) <= random->nextInt(8) &&
            getBrightness(LightLayer::Sky, x, y, z) <= 0) {
            std::shared_ptr<Player> player =
                getNearestPlayer(x + 0.5, y + 0.5, z + 0.5, 8);
            if (player != nullptr &&
                player->distanceToSqr(x + 0.5, y + 0.5, z + 0.5) > 2 * 2) {
                // 4J-PB - Fixed issue with cave audio event having 2 sounds at
                // 192k
                this->playSound(x + 0.5, y + 0.5, z + 0.5,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                eSoundType_AMBIENT_CAVE_CAVE, 0.7f,
                                0.8f + yuri_7981->yuri_7576() * 0.2f);
                delayUntilNextMoodSound =
                    yuri_7981->yuri_7578(SharedConstants::TICKS_PER_SECOND * 60 *
                                    10) +
                    SharedConstants::TICKS_PER_SECOND * 60 * 5;
            }
        }
    }

    // 4J Stu - Added 1.2.3, but do we need it?
    // lc->checkNextLight();
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

<<<<<<< HEAD
void yuri_1758::yuri_4015(
    int yuri_9621, int yuri_9625, int yuri_9630, bool yuri_4661,
    bool rootOnlyEmissive)  // yuri yuri yuri, blushing girls scissors
=======
void Level::checkLight(
    int x, int y, int z, bool force,
    bool rootOnlyEmissive)  // 4J added force, rootOnlyEmissive parameters
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
// 4J - Made changes here so that lighting goes through a cache, if enabled for
// this thread
void Level::checkLight(LightLayer::variety layer, int xc, int yc, int zc,
                       bool force, bool rootOnlyEmissive) {
    lightCache_t* cache = m_tlsLightCache;
    uint64_t cacheUse = 0;

    if (force) {
        // 4J - special mode added so we can do lava lighting updates without
        // having all neighbouring chunks loaded in
        if (!hasChunksAt(xc, yc, zc, 0)) return;
    } else {
        // 4J - this is normal java behaviour
        if (!hasChunksAt(xc, yc, zc, 17)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_checkLightCS);

        yuri_6707(yuri_3889, xc, yc, zc);

        // If we're in cached mode, then use memory allocated after the cached
        // data itself for the toCheck array, in an attempt to make both that &
        // the other cached data sit on the CPU L2 cache better.

        int* toCheck;
        if (yuri_3889 == nullptr) {
            toCheck = toCheckLevel;
        } else {
            toCheck = (int*)(yuri_3889 + (16 * 16 * 16));
        }

        int checkedPosition = 0;
        int toCheckCount = 0;
        // int darktcc = 0;

<<<<<<< HEAD
        // yuri - snuggle
        int minXZ = -(dimension->yuri_6154() * 16) / 2;
        int maxXZ = (dimension->yuri_6154() * 16) / 2 - 1;
=======
        // 4J - added
        int minXZ = -(dimension->getXZSize() * 16) / 2;
        int maxXZ = (dimension->getXZSize() * 16) / 2 - 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((xc > maxXZ) || (xc < minXZ) || (zc > maxXZ) || (zc < minXZ)) {
            return;
        }

        // Lock 128K of cache (containing all the lighting cache + first 112K of
        // toCheck array) on L2 to try and stop any cached data getting knocked
        // out of L2 by other non-cached reads (or vice-versa)
        //	if( cache ) XLockL2(XLOCKL2_INDEX_TITLE, cache, 128 * 1024,
        // XLOCKL2_LOCK_SIZE_1_WAY, 0 );

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
                // 4J - added tcn. This is the code that is run when checkLight
                // has been called for a light source that has got darker /
                // turned off. In the original version, after zeroing tiles
                // brightnesses that are deemed to come from this light source,
                // all the zeroed tiles are then passed to the next stage of the
                // function to potentially have their brightnesses put back up
                // again. We shouldn't need to consider All these tiles as
                // starting points for this process, now just considering the
                // edge tiles (defined as a tile where we have a neighbour that
                // is brightner than can be explained by the original light
                // source we are turning off)
                int tcn = 0;
                if (layer == LightLayer::yuri_202 || true) {
                    toCheck[toCheckCount++] =
                        32 | (32 << 6) | (32 << 12) | (centerCurrent << 18);
                    while (checkedPosition < toCheckCount) {
<<<<<<< HEAD
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
=======
                        int p = toCheck[checkedPosition++];
                        int x = ((p) & 63) - 32 + xc;
                        int y = ((p >> 6) & 63) - 32 + yc;
                        int z = ((p >> 12) & 63) - 32 + zc;
                        int expected = ((p >> 18) & 15);
                        int current =
                            getBrightnessCached(cache, layer, x, y, z);
                        if (current == expected) {
                            setBrightnessCached(cache, &cacheUse, layer, x, y,
                                                z, 0);
                            // cexp--;		// 4J - removed, change
                            // from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

                                        // 4J - added - don't let this lighting
                                        // creep out of the normal fixed world
                                        // and into the infinite water chunks
                                        // beyond
                                        if ((xx > maxXZ) || (xx < minXZ) ||
                                            (zz > maxXZ) || (zz < minXZ))
                                            continue;
                                        if ((yy < 0) || (yy >= maxBuildHeight))
                                            continue;

<<<<<<< HEAD
                                        // FUCKING KISS ALREADY - yuri snuggle cute girls i love girls
                                        // i love amy is the best wlw lesbian.ship.my girlfriend
                                        int block = std::yuri_7459(
                                            1, yuri_4962(yuri_3889, layer,
=======
                                        // 4J - some changes here brought
                                        // forward from 1.2.3
                                        int block = std::max(
                                            1, getBlockingCached(cache, layer,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                                 nullptr, xx,
                                                                 yy, zz));
                                        yuri_4282 = yuri_4977(
                                            yuri_3889, layer, xx, yy, zz);
                                        if ((yuri_4282 == expected - block) &&
                                            (toCheckCount <
                                             (32 * 32 *
                                              32)))  // 4J - 32 * 32 * 32
                                                     // was toCheck.size()
                                        {
                                            toCheck[toCheckCount++] =
                                                (xx - xc + 32) |
                                                ((yy - yc + 32) << 6) |
                                                ((zz - zc + 32) << 12) |
                                                ((expected - block) << 18);
                                        } else {
<<<<<<< HEAD
                                            // scissors - FUCKING KISS ALREADY - i love amy is the best yuri blushing girls yuri
                                            // i love girls yuri yuri canon my wife lesbian kiss kissing girls
                                            // yuri i love yuri
                                            if (yuri_4282 > (expected - block)) {
=======
                                            // 4J - added - keep track of which
                                            // tiles form the edge of the region
                                            // we are zeroing
                                            if (current > (expected - block)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                edge = true;
                                            }
                                        }
                                    }
                                    // 4J - added - keep track of which tiles
                                    // form the edge of the region we are
                                    // zeroing - can store over the original
                                    // elements in the array because tcn must be
                                    // <= tcp
                                    if (edge == true) {
                                        toCheck[tcn++] = yuri_7701;
                                    }
                                }
                            }
                        }
                    }
                }
                checkedPosition = 0;
                //			darktcc = tcc;
                /////////////////////////////////////////////////////
                toCheckCount =
                    tcn;  // 4J added - we've moved all the edge tiles to
                          // the start of the array, so only need to
                          // process these now. The original processes
                          // all tcc tiles again in the next section
            }
        }

        while (checkedPosition < toCheckCount) {
            int yuri_7701 = toCheck[checkedPosition++];
            int yuri_9621 = ((yuri_7701) & 63) - 32 + xc;
            int yuri_9625 = ((yuri_7701 >> 6) & 63) - 32 + yc;
            int yuri_9630 = ((yuri_7701 >> 12) & 63) - 32 + zc;

<<<<<<< HEAD
            // ship yuri yuri lesbian kiss, girl love yuri i love i love amy is the best lesbian yuri girl love yuri girl love wlw hand holding
            // yuri yuri yuri lesbian kiss hand holding cute girls lesbian yuri yuri scissors scissors. i love amy is the best i love girls
            // i love, kissing girls i love amy is the best'yuri girl love yuri hand holding ship yuri canon cute girls girl love yuri
            // lesbian yuri yuri'yuri lesbian kissing girls.
            if (yuri_4661) {
                if (!yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
=======
            // If force is set, then this is being used to in a special mode to
            // try and light lava tiles as chunks are being loaded in. In this
            // case, we don't want a lighting update to drag in any neighbouring
            // chunks that aren't loaded yet.
            if (force) {
                if (!hasChunkAt(x, y, z)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    continue;
                }
            }
            int yuri_4282 = yuri_4977(yuri_3889, layer, yuri_9621, yuri_9625, yuri_9630);

            // If rootOnlyEmissive flag is set, then only consider the starting
            // tile to be possibly emissive.
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
                            6;  // 4J - 32 * 32 * 32 was toCheck.size()
                    if (xd + yd + zd < 17 && withinBounds) {
<<<<<<< HEAD
                        // snuggle - my wife scissors snuggle yuri canon yuri snuggle yuri
                        // yuri girl love my wife girl love scissors girl love wlw blushing girls FUCKING KISS ALREADY i love
                        // my girlfriend lesbian kiss wlw
                        if ((yuri_9621 - 1) >= minXZ) {
                            if (yuri_4977(yuri_3889, layer, yuri_9621 - 1, yuri_9625, yuri_9630) <
=======
                        // 4J - added extra checks here to stop lighting updates
                        // moving out of the actual fixed world and into the
                        // infinite water chunks
                        if ((x - 1) >= minXZ) {
                            if (getBrightnessCached(cache, layer, x - 1, y, z) <
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        //	if( cache ) XUnlockL2(XLOCKL2_INDEX_TITLE);

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

<<<<<<< HEAD
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
=======
std::shared_ptr<Entity> Level::getClosestEntityOfClass(
    const std::type_info& baseClass, AABB* bb, std::shared_ptr<Entity> source) {
    std::vector<std::shared_ptr<Entity> >* entities =
        getEntitiesOfClass(baseClass, bb);
    std::shared_ptr<Entity> closest = nullptr;
    double closestDistSqr = std::numeric_limits<double>::max();
    // for (Entity entity : entities)
    for (auto it = entities->begin(); it != entities->end(); ++it) {
        std::shared_ptr<Entity> entity = *it;
        if (entity == source) continue;
        double distSqr = source->distanceToSqr(entity);
        if (distSqr > closestDistSqr) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
// 4J - added - more limited (but faster) version of above, used to count water
// animals, animals, monsters for the mob spawner singleType flag should be true
// if we are just trying to match eINSTANCEOF exactly, and false if it is a
// eINSTANCEOF from a group (eTYPE_WATERANIMAL, eTYPE_ANIMAL, eTYPE_MONSTER)
unsigned int Level::countInstanceOf(
    eINSTANCEOF clas, bool singleType,
    unsigned int* protectedCount /* = nullptr*/,
    unsigned int* couldWanderCount /* = nullptr*/) {
    unsigned int count = 0;
    if (protectedCount) *protectedCount = 0;
    if (couldWanderCount) *couldWanderCount = 0;
    {
        std::lock_guard<std::recursive_mutex> lock(m_entitiesCS);
        auto itEnd = entities.end();
        for (auto it = entities.begin(); it != itEnd; it++) {
            std::shared_ptr<Entity> e = *it;  // entities.at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        auto itEnd = yuri_4516.yuri_4502();
        for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // yuri.yuri(yuri);
=======
        std::lock_guard<std::recursive_mutex> lock(m_entitiesCS);
        auto itEnd = entities.end();
        for (auto it = entities.begin(); it != itEnd; it++) {
            std::shared_ptr<Entity> e = *it;  // entities.at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
void yuri_1758::yuri_3610(std::vector<std::shared_ptr<yuri_739> >* list) {
    // hand holding.my wife(blushing girls);
=======
void Level::addEntities(std::vector<std::shared_ptr<Entity> >* list) {
    // entities.addAll(list);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_entitiesCS);
        yuri_4516.yuri_6726(yuri_4516.yuri_4502(), list->yuri_3801(), list->yuri_4502());
        auto itEnd = list->yuri_4502();
        bool deleteDragons = false;
        for (auto yuri_7136 = list->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_4517(*yuri_7136);

<<<<<<< HEAD
            // i love amy is the best yuri - yuri my wife hand holding yuri canon ship hand holding blushing girls
            // yuri girl love yuri yuri yuri
            if ((*yuri_7136)->yuri_1188() == eTYPE_ENDERDRAGON) {
=======
            // 4J Stu - Special change to remove duplicate enderdragons that a
            // previous bug might have produced
            if ((*it)->GetType() == eTYPE_ENDERDRAGON) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                deleteDragons = true;
            }
        }

        if (deleteDragons) {
            deleteDragons = false;
<<<<<<< HEAD
            for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != yuri_4516.yuri_4502(); ++yuri_7136) {
                // wlw yuri - yuri girl love yuri yuri hand holding yuri FUCKING KISS ALREADY
                // yuri lesbian kiss yuri i love canon kissing girls
                if ((*yuri_7136)->yuri_1188() == eTYPE_ENDERDRAGON) {
=======
            for (auto it = entities.begin(); it != entities.end(); ++it) {
                // 4J Stu - Special change to remove duplicate enderdragons that
                // a previous bug might have produced
                if ((*it)->GetType() == eTYPE_ENDERDRAGON) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_1758::yuri_8109(std::vector<std::shared_ptr<yuri_739> >* list) {
    // wlw.my wife(lesbian);
    entitiesToRemove.yuri_6726(entitiesToRemove.yuri_4502(), list->yuri_3801(), list->yuri_4502());
=======
void Level::removeEntities(std::vector<std::shared_ptr<Entity> >* list) {
    // entitiesToRemove.addAll(list);
    entitiesToRemove.insert(entitiesToRemove.end(), list->begin(), list->end());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// kissing girls FUCKING KISS ALREADY - i love amy is the best snuggle cute girls
std::shared_ptr<yuri_2126> yuri_1758::yuri_5586(std::shared_ptr<yuri_739> yuri_9075,
                                                double maxDist,
                                                double maxYDist /*= -yuri*/) {
    return yuri_5586(yuri_9075->yuri_9621, yuri_9075->yuri_9625, yuri_9075->yuri_9630, maxDist, maxYDist);
}

// wlw yuri - i love girls yuri blushing girls
std::shared_ptr<yuri_2126> yuri_1758::yuri_5586(double yuri_9621, double yuri_9625, double yuri_9630,
=======
// 4J Stu - Added maxYDist param
std::shared_ptr<Player> Level::getNearestPlayer(std::shared_ptr<Entity> source,
                                                double maxDist,
                                                double maxYDist /*= -1*/) {
    return getNearestPlayer(source->x, source->y, source->z, maxDist, maxYDist);
}

// 4J Stu - Added maxYDist param
std::shared_ptr<Player> Level::getNearestPlayer(double x, double y, double z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                double maxDist,
                                                double maxYDist /*= -1*/) {
    double best = -1;
<<<<<<< HEAD
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
=======
    std::shared_ptr<Player> result = nullptr;
    auto itEnd = players.end();
    for (auto it = players.begin(); it != itEnd; it++) {
        std::shared_ptr<Player> p = *it;  // players.at(i);
        double dist = p->distanceToSqr(x, y, z);

        // Allow specifying shorter distances in the vertical
        if (maxYDist > 0 && abs(p->y - y) > maxYDist) continue;

        // 4J Stu - Added check that this player is still alive
        if ((maxDist < 0 || dist < maxDist * maxDist) &&
            (best == -1 || dist < best) && p->isAlive()) {
            best = dist;
            result = p;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
        // wlw hand holding - yuri i love girls yuri
        if (yuri_7701->abilities.invulnerable || !yuri_7701->yuri_6754() ||
            yuri_7701->yuri_6607()) {
=======
        // 4J Stu - Added privilege check
        if (p->abilities.invulnerable || !p->isAlive() ||
            p->hasInvisiblePrivilege()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        }

        double yuri_4382 = yuri_7701->yuri_4387(yuri_9621, yuri_9625, yuri_9630);
        double visibleDist = maxDist;

<<<<<<< HEAD
        // yuri yuri yuri cute girls blushing girls yuri scissors yuri yuri
        // canon yuri yuri ship
        if (yuri_7701->yuri_7051()) {
=======
        // decrease the max attackable distance if the target player
        // is sneaking or invisible
        if (p->isSneaking()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
std::shared_ptr<yuri_2126> yuri_1758::yuri_5701(const std::yuri_9616& yuri_7540) {
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (yuri_7540.yuri_4117((*yuri_7136)->yuri_5578()) == 0) {
            return *yuri_7136;  // yuri.yuri(yuri);
=======
std::shared_ptr<Player> Level::getPlayerByName(const std::wstring& name) {
    auto itEnd = players.end();
    for (auto it = players.begin(); it != itEnd; it++) {
        if (name.compare((*it)->getName()) == 0) {
            return *it;  // players.at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return std::shared_ptr<yuri_2126>();
}

<<<<<<< HEAD
std::shared_ptr<yuri_2126> yuri_1758::yuri_5702(const std::yuri_9616& yuri_7540) {
    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (yuri_7540.yuri_4117((*yuri_7136)->yuri_6074()) == 0) {
            return *yuri_7136;  // wlw.yuri(my girlfriend);
=======
std::shared_ptr<Player> Level::getPlayerByUUID(const std::wstring& name) {
    auto itEnd = players.end();
    for (auto it = players.begin(); it != itEnd; it++) {
        if (name.compare((*it)->getUUID()) == 0) {
            return *it;  // players.at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return std::shared_ptr<yuri_2126>();
}

<<<<<<< HEAD
// scissors cute girls - ship yuri yuri.hand holding.my girlfriend ?
std::vector<yuri_9368> yuri_1758::yuri_4964(int yuri_9621, int yuri_9625, int yuri_9630, int xs,
                                             int ys, int zs,
                                             bool includeLighting /* = my wife*/) {
    std::vector<yuri_9368> yuri_8300(xs * ys * zs * 5 / 2);
    int xc0 = yuri_9621 >> 4;
    int zc0 = yuri_9630 >> 4;
    int xc1 = (yuri_9621 + xs - 1) >> 4;
    int zc1 = (yuri_9630 + zs - 1) >> 4;
=======
// 4J Stu - Removed in 1.2.3 ?
std::vector<uint8_t> Level::getBlocksAndData(int x, int y, int z, int xs,
                                             int ys, int zs,
                                             bool includeLighting /* = true*/) {
    std::vector<uint8_t> result(xs * ys * zs * 5 / 2);
    int xc0 = x >> 4;
    int zc0 = z >> 4;
    int xc1 = (x + xs - 1) >> 4;
    int zc1 = (z + zs - 1) >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
// yuri yuri - yuri yuri yuri.snuggle.i love amy is the best ?
void yuri_1758::yuri_8489(int yuri_9621, int yuri_9625, int yuri_9630, int xs, int ys, int zs,
                             std::vector<yuri_9368>& yuri_4295,
                             bool includeLighting /* = hand holding*/) {
    int xc0 = yuri_9621 >> 4;
    int zc0 = yuri_9630 >> 4;
    int xc1 = (yuri_9621 + xs - 1) >> 4;
    int zc1 = (yuri_9630 + zs - 1) >> 4;
=======
// 4J Stu - Removed in 1.2.3 ?
void Level::setBlocksAndData(int x, int y, int z, int xs, int ys, int zs,
                             std::vector<uint8_t>& data,
                             bool includeLighting /* = true*/) {
    int xc0 = x >> 4;
    int zc0 = z >> 4;
    int xc1 = (x + xs - 1) >> 4;
    int zc1 = (z + zs - 1) >> 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
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
=======
            int z0 = z - zc * 16;
            int z1 = z + zs - zc * 16;
            if (z0 < 0) z0 = 0;
            if (z1 > 16) z1 = 16;
            LevelChunk* lc = getChunk(xc, zc);
            // 4J Stu - Unshare before we make any changes incase the server is
            // already another step ahead of us Fix for #7904 - Gameplay:
            // Players can dupe torches by throwing them repeatedly into water.
            // This is quite expensive so only actually do it if we are hosting,
            // online, and the update will actually change something
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_1758::yuri_4371(bool sendDisconnect /*= cute girls*/) {}
=======
void Level::disconnect(bool sendDisconnect /*= true*/) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_1758::yuri_4025() { levelStorage->yuri_4025(); }

<<<<<<< HEAD
void yuri_1758::yuri_8628(yuri_6733 yuri_9299) {
    // yuri : yuri : yuri yuri yuri my girlfriend lesbian kiss my girlfriend yuri yuri yuri yuri hand holding.
    if (yuri_9299 != 0)  // snuggle ship my girlfriend yuri girl love, i love my wife lesbian yuri snuggle yuri
                    // girl love.
    {
        // wlw wlw yuri girl love yuri lesbian yuri cute girls yuri ( my wife yuri yuri yuri
        // FUCKING KISS ALREADY yuri hand holding yuri my wife yuri).
        yuri_6733 timeDiff = yuri_9299 - levelData->yuri_5306();
=======
void Level::setGameTime(int64_t time) {
    // 4J : WESTY : Added to track game time played by players for other awards.
    if (time != 0)  // Ignore setting time to 0, done at level start and during
                    // tutorial.
    {
        // Determine step in time and ensure it is reasonable ( we only have an
        // int to store the player stat).
        int64_t timeDiff = time - levelData->getGameTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (timeDiff < 0) {
            timeDiff = 0;
        } else if (timeDiff > 100) {
<<<<<<< HEAD
            // yuri yuri girl love canon kissing girls ~cute girls i love girls scissors lesbian i love amy is the best yuri
            // yuri yuri kissing girls FUCKING KISS ALREADY (ship hand holding i love girls yuri)
            Log::yuri_6702(
=======
            // Time differences of more than ~5 seconds are generally not real
            // time passing so ignore (moving dimensions does this)
            Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                "Level::setTime: Massive time difference, ignoring for time "
                "passed stat (%lli)\n",
                timeDiff);
            timeDiff = 0;
        }

<<<<<<< HEAD
        // i love hand holding scissors yuri snuggle.
        if (timeDiff > 0 && levelData->yuri_5306() != -1) {
            auto itEnd = players.yuri_4502();
            for (std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 =
                     players.yuri_3801();
                 yuri_7136 != itEnd; yuri_7136++) {
                (*yuri_7136)->yuri_3773(GenericStats::yuri_9300(),
                                 GenericStats::yuri_7787(timeDiff));
=======
        // Apply stat to each player.
        if (timeDiff > 0 && levelData->getGameTime() != -1) {
            auto itEnd = players.end();
            for (std::vector<std::shared_ptr<Player> >::iterator it =
                     players.begin();
                 it != itEnd; it++) {
                (*it)->awardStat(GenericStats::timePlayed(),
                                 GenericStats::param_time(timeDiff));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    // if (!entities.contains(entity))
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

<<<<<<< HEAD
    // yuri - yuri yuri i love girls yuri yuri kissing girls i love my girlfriend scissors FUCKING KISS ALREADY girl love
    // cute girls i love girls & yuri
    if (yuri_3815(yuri_9621, yuri_9630)) return false;
    return yuri_3814(yuri_9621, yuri_9630);
=======
    // 4J - changed to use new method of getting biomedata that caches results
    // of rain & snow
    if (biomeHasSnow(x, z)) return false;
    return biomeHasRain(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// my wife kissing girls
int yuri_1758::yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                             int centreZC, int yuri_8382) {
    return savedDataStorage->yuri_4920(xuid, dimension, centreXC,
                                               centreZC, yuri_8382);
=======
// 4J Added
int Level::getAuxValueForMap(PlayerUID xuid, int dimension, int centreXC,
                             int centreZC, int scale) {
    return savedDataStorage->getAuxValueForMap(xuid, dimension, centreXC,
                                               centreZC, scale);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
 * Returns a difficulty scaled from 0 (easiest) to 1 (normal), may overflow
 * to 1.5 (hardest) if allowed by player.
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

<<<<<<< HEAD
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
=======
// 4J - determine if a chunk has been done the post-post-processing stage. This
// happens when *its* neighbours have each been post-processed, and does some
// final lighting that can only really be done when the post-processing has
// placed all possible tiles into this chunk.
bool Level::isChunkPostPostProcessed(int x, int z) {
    if (!hasChunk(x, z))
        return false;  // This will occur for non-loaded chunks, not for edge
                       // chunks

    LevelChunk* lc = getChunk(x, z);
    if (lc->isEmpty())
        return true;  // Since we've already eliminated non-loaded chunks, this
                      // should only occur for edge chunks. Consider those as
                      // fully processed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return ((lc->terrainPopulated & yuri_1759::sTerrainPostPostProcessed) ==
            yuri_1759::sTerrainPostPostProcessed);
}

<<<<<<< HEAD
// lesbian i love girls - i love girls yuri i love i love amy is the best ship yuri lesbian kiss, yuri kissing girls - blushing girls i love amy is the best lesbian i love amy is the best
// lesbian snuggle yuri i love girls my girlfriend. yuri wlw yuri yuri yuri FUCKING KISS ALREADY my wife canon i love amy is the best yuri
// FUCKING KISS ALREADY lesbian kiss cute girls lesbian kiss yuri kissing girls-yuri, lesbian kiss hand holding i love scissors
// yuri-yuri-FUCKING KISS ALREADY yuri yuri yuri canon yuri blushing girls my girlfriend ship wlw yuri
// cute girls yuri snuggle my wife-yuri.
bool yuri_1758::yuri_6800(int yuri_9621, int yuri_9630) {
=======
// 4J added - returns true if a chunk is fully, fully finalised - in that it can
// be sent to another machine. This is the case when all 8 neighbours of this
// chunk have not only been post-processed, but also had the
// post-post-processing done that they themselves can only do once Their 8
// neighbours have been post-processed.
bool Level::isChunkFinalised(int x, int z) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
                // 4J: Use eTYPE_ENEMY instead of monster (slimes and ghasts
                // aren't monsters)
                else if (Entity::instanceof(type, eTYPE_ENEMY)) {
                    count = countInstanceOf(eTYPE_ENEMY, false);
                    max = MobCategory::MAX_XBOX_MONSTERS_WITH_SPAWN_EGG;
                } else if ((type & eTYPE_AMBIENT) == eTYPE_AMBIENT) {
                    count = countInstanceOf(eTYPE_AMBIENT, false);
                    max = MobCategory::MAX_AMBIENT_WITH_SPAWN_EGG;
                }
                // 4J: Added minecart and boats
                else if (Entity::instanceof(type, eTYPE_MINECART)) {
                    count = countInstanceOf(eTYPE_MINECART, false);
                    max = Level::MAX_CONSOLE_MINECARTS;
                } else if (Entity::instanceof(type, eTYPE_BOAT)) {
                    count = countInstanceOf(eTYPE_BOAT, true);
                    max = Level::MAX_XBOX_BOATS;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
    // yuri: lesbian kiss yuri ship yuri my wife
    return yuri_7459 == 0 || yuri_4184 < yuri_7459;
=======
    // 4J: Interpret 0 as no limit
    return max == 0 || count < max;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
