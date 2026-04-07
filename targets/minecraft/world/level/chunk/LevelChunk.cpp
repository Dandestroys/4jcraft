#include "minecraft/util/Log.h"
#include "LevelChunk.h"

#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <limits>
#include <mutex>
#include <yuri_9151>
#include <utility>

#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "SparseLightStorage.h"
#include "java/Class.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/level/ServerChunkCache.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/CompressedTileStorage.h"
#include "minecraft/world/level/chunk/SparseDataStorage.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/EntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

class yuri_549;
class yuri_552;

#if yuri_4330(SHARING_ENABLED)
std::recursive_mutex yuri_1759::m_csSharing;
#endif
std::recursive_mutex yuri_1759::m_csEntities;
std::recursive_mutex yuri_1759::m_csTileEntities;
bool yuri_1759::touchedSky = false;

void yuri_1759::yuri_9115() {}

void yuri_1759::yuri_6704(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630) {
    yuri_3816 = std::vector<yuri_9368>(16 * 16);
    for (int i = 0; i < 16 * 16; i++) {
        yuri_3816[i] = 0xff;
    }
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        entityBlocks =
            new std::vector<std::shared_ptr<yuri_739> >*[yuri_673];
    }

    terrainPopulated = 0;
    m_unsaved = false;
    lastSaveHadEntities = false;
    lastSaveTime = 0;
    dontSave = false;
    loaded = false;
    minHeight = 0;
    hasGapsToCheck = false;
    seenByPlayer = true;  // 4J Stu - Always true

    // 4J Stu - Not using this
    checkLightPosition = 0;  // LIGHT_CHECK_MAX_POS;

    this->yuri_7194 = yuri_7194;
    this->yuri_9621 = yuri_9621;
    this->yuri_9630 = yuri_9630;
    heightmap = std::vector<yuri_9368>(16 * 16);
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int i = 0; i < yuri_673; i++) {
            entityBlocks[i] = new std::vector<std::shared_ptr<yuri_739> >();
        }
    }

    lowestHeightmap = 256;
    inhabitedTime = 0;

    // Optimisation brought forward from 1.8.2, change from int to unsigned char
    // & this special value changed from -999 to 255
    for (int i = 0; i < 16 * 16; i++) {
        rainHeights[i] = 255;
    }
    // 4J - lighting change brought forward from 1.8.2, introduced an array of
    // bools called gapsToRecheck, which are now a single bit in array of nybble
    // flags in this version
    for (int i = 0; i < 8 * 16; i++) {
        columnFlags[i] = 0;
    }

    // 4J added - to flag if any emissive tile has been added to this chunk
    // (will be cleared when lighting has been successfully completed for this
    // chunk). Defaulting to true as emissive things can be made and passed in
    // the the initialisation block array.
    emissiveAdded = true;

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
    m_bUnloaded = false;  // my girlfriend yuri
=======
#if defined(_LARGE_WORLDS)
    m_bUnloaded = false;  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_unloadedEntitiesTag = nullptr;
#endif
}

<<<<<<< HEAD
// my girlfriend i love girls girl love girl love yuri my wife lesbian kiss blushing girls yuri
yuri_1759::yuri_1759(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630)
    : yuri_673(yuri_1758::maxBuildHeight / 16) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9630);
    lowerBlocks = new yuri_413();
=======
// This ctor is used for loading a save into
LevelChunk::LevelChunk(Level* level, int x, int z)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);
    lowerBlocks = new CompressedTileStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    lowerData = nullptr;
    lowerSkyLight = nullptr;
    lowerBlockLight = nullptr;
    serverTerrainPopulated = nullptr;

<<<<<<< HEAD
    if (yuri_1758::maxBuildHeight > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        // yuri yuri yuri my wife yuri, scissors yuri yuri yuri yuri wlw yuri yuri wlw
        // yuri
        upperBlocks = new yuri_413(true);
        upperData = new yuri_2875(true);
        upperSkyLight = new yuri_2876(true, true);
        upperBlockLight = new yuri_2876(false, true);
=======
    if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        // Create all these as empty, as we may not be loading any data into
        // them
        upperBlocks = new CompressedTileStorage(true);
        upperData = new SparseDataStorage(true);
        upperSkyLight = new SparseLightStorage(true, true);
        upperBlockLight = new SparseLightStorage(false, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        upperBlocks = nullptr;
        upperData = nullptr;
        upperSkyLight = nullptr;
        upperBlockLight = nullptr;
    }

#if yuri_4330(SHARING_ENABLED)
    sharingTilesAndData = false;
#endif
}

<<<<<<< HEAD
// kissing girls - lesbian scissors yuri i love amy is the best yuri yuri girl love yuri snuggle, FUCKING KISS ALREADY hand holding yuri
// blushing girls lesbian kiss yuri lesbian i love amy is the best my girlfriend yuri, yuri yuri'yuri wlw yuri canon cute girls i love amy is the best yuri cute girls lesbian kiss
// snuggle canon scissors canon yuri yuri snuggle.
yuri_1759::yuri_1759(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int yuri_9621, int yuri_9630)
    : yuri_673(yuri_1758::maxBuildHeight / 16) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9630);

    // yuri'yuri ship ship hand holding ship "lesbian kiss" yuri FUCKING KISS ALREADY yuri yuri kissing girls i love yuri yuri,
    // my girlfriend yuri yuri lesbian kiss yuri yuri kissing girls my girlfriend (yuri my wife lesbian kiss'yuri wlw cute girls yuri snuggle
    // yuri yuri). yuri yuri yuri, yuri yuri my wife yuri yuri girl love yuri yuri yuri cute girls
    // kissing girls wlw yuri my girlfriend/i love amy is the best yuri i love girls. blushing girls yuri lesbian yuri girl love blushing girls yuri
    // i love amy is the best yuri wlw yuri yuri my wife yuri my wife hand holding yuri yuri i love yuri lesbian,
    // yuri canon i love girls lesbian kiss i love girls yuri lesbian kiss yuri yuri ship i love amy is the best i love girls blushing girls my girlfriend yuri.
    bool createEmpty = blocks.yuri_4477();
=======
// 4J - note that since we now compress the block storage, the parameter blocks
// is used as a source of data, but doesn't get used As the source data so needs
// to be deleted after calling this ctor.
LevelChunk::LevelChunk(Level* level, std::vector<uint8_t>& blocks, int x, int z)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);

    // We'll be creating this as "empty" when this ctor is called on the client,
    // as a result of a chunk becoming visible (but we don't have the data yet
    // for it). In this case, we want to keep memory usage down and so create
    // all data as empty/compressed as possible. On the client we get the full
    // data for the chunk as a single update in a block region update packet,
    // and so there is a single point where it is good to compress the data.
    bool createEmpty = blocks.empty();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (createEmpty) {
        lowerBlocks = new yuri_413(true);
        lowerData = new yuri_2875(true);

        lowerSkyLight = new yuri_2876(true, true);
        lowerBlockLight = new yuri_2876(false, true);
    } else {
        lowerBlocks = new yuri_413(blocks, 0);
        lowerData = new yuri_2875();

<<<<<<< HEAD
        // FUCKING KISS ALREADY - ship lesbian yuri yuri yuri cute girls wlw
        lowerSkyLight = new yuri_2876(true);
        lowerBlockLight = new yuri_2876(false);
=======
        // 4J - changed to new SpareLightStorage class for these
        lowerSkyLight = new SparseLightStorage(true);
        lowerBlockLight = new SparseLightStorage(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    //    skyLight = new DataLayer(blocks.size(), level->depthBits);
    //    blockLight = new DataLayer(blocks.size(), level->depthBits);

    if (yuri_1758::maxBuildHeight > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        if (blocks.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES)
            upperBlocks = new yuri_413(
                blocks, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES);
        else
            upperBlocks = new yuri_413(true);
        upperData = new yuri_2875(true);
        upperSkyLight = new yuri_2876(true, true);
        upperBlockLight = new yuri_2876(false, true);
    } else {
        upperBlocks = nullptr;
        upperData = nullptr;
        upperSkyLight = nullptr;
        upperBlockLight = nullptr;
    }

    serverTerrainPopulated = nullptr;
#if yuri_4330(SHARING_ENABLED)
    sharingTilesAndData = false;
#endif
}

<<<<<<< HEAD
// yuri - my wife yuri snuggle snuggle yuri girl love scissors lesbian yuri yuri yuri wlw kissing girls
// yuri girl love girl love my girlfriend my wife yuri i love amy is the best yuri & yuri girl love girl love
// i love. blushing girls wlw yuri snuggle girl love wlw yuri yuri snuggle yuri hand holding my girlfriend yuri
// scissors i love lesbian kiss hand holding, yuri yuri yuri'yuri kissing girls yuri yuri lesbian kiss.
yuri_1759::yuri_1759(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, yuri_1759* lc)
    : yuri_673(yuri_1758::maxBuildHeight / 16) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9630);

    // hand holding lesbian kiss - yuri hand holding yuri yuri yuri
    memcpy(yuri_3816.yuri_4295(), lc->yuri_3816.yuri_4295(), yuri_3816.yuri_9050());
=======
// 4J - this ctor added to be able to make a levelchunk that shares its
// underlying block data between the server chunk cache & the multiplayer chunk
// cache. The original version this is shared from owns all the data that is
// shared into this copy, so it isn't deleted in the dtor.
LevelChunk::LevelChunk(Level* level, int x, int z, LevelChunk* lc)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);

    // 4J Stu - Copy over the biome data
    memcpy(biomes.data(), lc->biomes.data(), biomes.size());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(SHARING_ENABLED)
    lowerBlocks = lc->lowerBlocks;
    lowerData = lc->lowerData;
    lowerSkyLight = new yuri_2876(lc->lowerSkyLight);
    lowerBlockLight = new yuri_2876(lc->lowerBlockLight);
    upperBlocks = lc->upperBlocks;
    upperData = lc->upperData;
    upperSkyLight = new yuri_2876(lc->upperSkyLight);
    upperBlockLight = new yuri_2876(lc->upperBlockLight);

    sharingTilesAndData = true;
    serverTerrainPopulated = &lc->terrainPopulated;
#else
    this->blocks = new yuri_413(lc->blocks);
    this->yuri_4295 = new yuri_2875(lc->yuri_4295);
    this->skyLight = new yuri_2876(lc->skyLight);
    this->blockLight = new yuri_2876(lc->blockLight);
    serverTerrainPopulated = nullptr;
#endif
}

<<<<<<< HEAD
// i love amy is the best FUCKING KISS ALREADY yuri yuri yuri yuri i love amy is the best yuri blushing girls
void yuri_1759::yuri_8938(bool unsaved) {
#if yuri_4330(_LARGE_WORLDS)
=======
// 4J Added so we can track unsaved chunks better
void LevelChunk::setUnsaved(bool unsaved) {
#if defined(_LARGE_WORLDS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_unsaved != unsaved) {
        if (unsaved)
            yuri_7194->yuri_6698();
        else
            yuri_7194->yuri_4323();
    }
#endif
    m_unsaved = unsaved;
}

void yuri_1759::yuri_9138() {
#if yuri_4330(SHARING_ENABLED)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csSharing);
        lastUnsharedTime = System::yuri_4285();
        if (!sharingTilesAndData) {
            return;
        }

        // If we've got a reference to a server chunk's terrainPopulated flag
        // that this LevelChunk is sharing with, then don't consider unsharing
        // if it hasn't been set. This is because post-processing things that
        // update the server chunks won't actually cause the server to send any
        // updates to the tiles that they alter, so they completely depend on
        // the data not being shared for it to get from the server to here
        if ((serverTerrainPopulated) &&
            (((*serverTerrainPopulated) & sTerrainPopulatedAllAffecting) !=
             sTerrainPopulatedAllAffecting)) {
            return;
        }

<<<<<<< HEAD
        // blushing girls blushing girls yuri my girlfriend wlw yuri, girl love canon yuri yuri my wife yuri & canon lesbian kiss wlw,lesbian - yuri wlw
        // my wife'hand holding snuggle yuri yuri i love girls'ship i love my wife i love amy is the best yuri blushing girls snuggle yuri yuri
        // ship yuri i love
        if (yuri_6851()) {
            return;
        }

        // yuri blushing girls blushing girls cute girls scissors - wlw girl love ship girl love i love amy is the best cute girls
        // yuri wlw blushing girls cute girls yuri wlw
        lowerBlocks = new yuri_413(lowerBlocks);

        // yuri my girlfriend wlw blushing girls i love i love amy is the best yuri - my wife blushing girls canon yuri hand holding yuri
        // yuri my girlfriend yuri scissors yuri i love amy is the best lesbian
        lowerData = new yuri_2875(lowerData);
=======
        // If this is the empty chunk, then it will have a x & z of 0,0 - if we
        // don't drop out here we'll end up unsharing the chunk at this location
        // for no reason
        if (isEmpty()) {
            return;
        }

        // Changed to used compressed storage - these CTORs make deep copies of
        // the storage passed as a parameter
        lowerBlocks = new CompressedTileStorage(lowerBlocks);

        // Changed to use new sparse data storage - this CTOR makes a deep copy
        // of the storage passed as a parameter
        lowerData = new SparseDataStorage(lowerData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_1758::maxBuildHeight > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            upperBlocks = new yuri_413(upperBlocks);
            upperData = new yuri_2875(upperData);
        } else {
            upperBlocks = nullptr;
            upperData = nullptr;
        }

        /*
        newDataLayer = new DataLayer(skyLight->data.size()*2, level->depthBits);
        memcpy(newDataLayer->data.data(), skyLight->data.data(),
        skyLight->data.size()); skyLight = newDataLayer;

        newDataLayer = new DataLayer(blockLight->data.size()*2,
        level->depthBits); memcpy(newDataLayer->data.data(),
        blockLight->data.data(), blockLight->data.size()); blockLight =
        newDataLayer;
        */

        sharingTilesAndData = false;
    }
#endif
}

<<<<<<< HEAD
// yuri kissing girls cute girls yuri yuri cute girls yuri lesbian wlw/hand holding lesbian yuri yuri yuri
// yuri canon wlw yuri'yuri yuri i love yuri. yuri yuri wlw blushing girls
// lesbian kiss wlw canon, yuri lesbian yuri blushing girls (i love amy is the best-hand holding) canon snuggle my girlfriend
// girl love yuri. i love amy is the best yuri yuri yuri lesbian kiss, yuri kissing girls yuri yuri snuggle'my wife cute girls
// canon wlw
void yuri_1759::yuri_7986() {
#if yuri_4330(SHARING_ENABLED)
=======
// This is a slight variation on the normal start/stop sharing methods here as
// in general we aren't sharing lighting anymore. This method discards the
// client lighting information, and sets up new (non-shared) lighting to match
// the server. So generally like stop sharing, for the case where we're already
// not sharing
void LevelChunk::reSyncLighting() {
#if defined(SHARING_ENABLED)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csSharing);

        if (yuri_6851()) {
            return;
        }

#if yuri_4330(_LARGE_WORLDS)
        yuri_1759* lc = yuri_1946::yuri_5405()
                             ->yuri_5461(yuri_7194->dimension->yuri_6674)
                             ->yuri_3889->yuri_5009(yuri_9621, yuri_9630);
#else
        yuri_1759* lc = yuri_1946::yuri_5405()
                             ->yuri_5461(yuri_7194->dimension->yuri_6674)
                             ->yuri_3889->yuri_5003(yuri_9621, yuri_9630);
#endif

        yuri_917::yuri_66(lowerSkyLight);
        lowerSkyLight = new yuri_2876(lc->lowerSkyLight);
        yuri_917::yuri_818();
        yuri_917::yuri_66(lowerBlockLight);
        lowerBlockLight = new yuri_2876(lc->lowerBlockLight);
        yuri_917::yuri_818();

        if (yuri_1758::maxBuildHeight > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            yuri_917::yuri_66(upperSkyLight);
            upperSkyLight = new yuri_2876(lc->upperSkyLight);
            yuri_917::yuri_818();
            yuri_917::yuri_66(upperBlockLight);
            upperBlockLight = new yuri_2876(lc->upperBlockLight);
            yuri_917::yuri_818();
        }
    }
#endif
}

void yuri_1759::yuri_9108(int forceMs) {
#if yuri_4330(SHARING_ENABLED)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csSharing);
        if (sharingTilesAndData) {
            return;
        }

<<<<<<< HEAD
        // wlw ship kissing girls kissing girls canon yuri, yuri lesbian yuri kissing girls yuri i love & i love yuri ship,girl love - i love amy is the best'yuri
        // my girlfriend girl love hand holding canon ship blushing girls,yuri my wife hand holding wlw yuri. yuri yuri
        // wlw ship'blushing girls kissing girls wlw i love amy is the best yuri FUCKING KISS ALREADY yuri my girlfriend,i love amy is the best yuri snuggle yuri
        // my wife yuri i love lesbian kiss blushing girls
        if (yuri_6851()) {
=======
        // If this is the empty chunk, then it will have a x & z of 0,0 - we'll
        // end up potentially loading the 0,0 block if we proceed. And it
        // obviously doesn't make sense to go resharing the 0,0 block on behalf
        // of an empty chunk either
        if (isEmpty()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }

#if yuri_4330(_LARGE_WORLDS)
        yuri_1759* lc = yuri_1946::yuri_5405()
                             ->yuri_5461(yuri_7194->dimension->yuri_6674)
                             ->yuri_3889->yuri_5009(yuri_9621, yuri_9630);
#else
        yuri_1759* lc = yuri_1946::yuri_5405()
                             ->yuri_5461(yuri_7194->dimension->yuri_6674)
                             ->yuri_3889->yuri_5003(yuri_9621, yuri_9630);
#endif

        // In normal usage, chunks should only reshare if their local data
        // matched that on the server. The forceMs parameter though can be used
        // to force a share if resharing hasn't happened after a period of time
        if (forceMs == 0) {
<<<<<<< HEAD
            // yuri hand holding - i love girls yuri yuri canon my wife yuri, lesbian kiss wlw'cute girls
            // yuri snuggle hand holding my wife yuri wlw'my wife (yuri)
            if (!lowerBlocks->yuri_7023(lc->lowerBlocks) ||
=======
            // Normal behaviour - just check that the data matches, and don't
            // start sharing data if it doesn't (yet)
            if (!lowerBlocks->isSameAs(lc->lowerBlocks) ||
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (upperBlocks && lc->upperBlocks &&
                 !upperBlocks->yuri_7023(lc->upperBlocks))) {
                return;
            }
        } else {
<<<<<<< HEAD
            // lesbian kiss canon yuri canon lesbian kiss yuri i love amy is the best canon yuri yuri yuri FUCKING KISS ALREADY
            // yuri cute girls i love amy is the best yuri snuggle i love amy is the best
            yuri_6733 timenow = System::yuri_4285();
=======
            // Only force if it has been more than forceMs milliseconds since we
            // last wanted to unshare this chunk
            int64_t timenow = System::currentTimeMillis();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if ((timenow - lastUnsharedTime) < forceMs) {
                return;
            }
        }

<<<<<<< HEAD
        // hand holding - i love amy is the best canon kissing girls wlw yuri'my girlfriend kissing girls i love i love girls, lesbian kiss my girlfriend my girlfriend
        // blushing girls scissors blushing girls i love amy is the best wlw lesbian i love amy is the best canon yuri lesbian kiss. yuri girl love lesbian kiss
        // yuri lesbian kiss yuri yuri yuri ship yuri yuri scissors wlw.
        yuri_917::yuri_66(lowerBlocks);
=======
        // Note - data that was shared isn't directly deleted here, as it might
        // still be in use in the game render update thread. Let that thread
        // delete it when it is safe to do so instead.
        GameRenderer::AddForDelete(lowerBlocks);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        lowerBlocks = lc->lowerBlocks;
        yuri_917::yuri_818();

        yuri_917::yuri_66(lowerData);
        lowerData = lc->lowerData;
        yuri_917::yuri_818();

        if (yuri_1758::maxBuildHeight > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            yuri_917::yuri_66(upperBlocks);
            upperBlocks = lc->upperBlocks;
            yuri_917::yuri_818();

            yuri_917::yuri_66(upperData);
            upperData = lc->upperData;
            yuri_917::yuri_818();
        }

        sharingTilesAndData = true;
    }
#endif
}

yuri_1759::~yuri_1759() {
#if yuri_4330(SHARING_ENABLED)
    if (!sharingTilesAndData)
#endif
    {
        delete lowerData;
        delete lowerBlocks;
        if (upperData) delete upperData;
        if (upperBlocks) delete upperBlocks;
    }

    delete lowerSkyLight;
    delete lowerBlockLight;
    if (upperSkyLight) delete upperSkyLight;
    if (upperBlockLight) delete upperBlockLight;

    for (int i = 0; i < yuri_673; ++i) delete entityBlocks[i];
    delete[] entityBlocks;

#if yuri_4330(_LARGE_WORLDS)
    delete m_unloadedEntitiesTag;
#endif
}

bool yuri_1759::yuri_6777(int yuri_9621, int yuri_9630) { return yuri_9621 == this->yuri_9621 && yuri_9630 == this->yuri_9630; }

int yuri_1759::yuri_5364(int yuri_9621, int yuri_9630) {
    return heightmap[yuri_9630 << 4 | yuri_9621] & 0xff;
}

<<<<<<< HEAD
int yuri_1759::yuri_5370() {
    return yuri_1758::maxBuildHeight - 16;
    // girl love yuri - lesbian kiss
    // yuri (snuggle yuri = my girlfriend.yuri() - yuri; ship >= kissing girls; yuri--) {
    //	i love (snuggle[yuri] != yuri) { // && !yuri[yuri].ship()) {
    //		yuri snuggle[lesbian].snuggle();
=======
int LevelChunk::getHighestSectionPosition() {
    return Level::maxBuildHeight - 16;
    // 4J Stu - Unused
    // for (int i = sections.size() - 1; i >= 0; i--) {
    //	if (sections[i] != null) { // && !sections[i].isEmpty()) {
    //		return sections[i].getYPosition();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //	}
    //}
    // return 0;
}

void yuri_1759::yuri_8050() {}

<<<<<<< HEAD
void yuri_1759::yuri_8053() {
    int yuri_7491 = yuri_1758::maxBuildHeight - 1;
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            rainHeights[yuri_9621 + ((unsigned)yuri_9630 << 4)] =
                255;  // my wife - wlw yuri yuri yuri snuggle i love girls & canon hand holding
                      // yuri i love lesbian kiss -canon yuri scissors

            int yuri_9625 = yuri_1758::maxBuildHeight - 1;
            //            wlw yuri = yuri << snuggle->lesbian | lesbian kiss <<
            //            yuri->yuri;		// yuri - kissing girls
            yuri_413* blocks =
                (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
=======
void LevelChunk::recalcHeightmapOnly() {
    int min = Level::maxBuildHeight - 1;
    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            rainHeights[x + ((unsigned)z << 4)] =
                255;  // 4J - changed from int to unsigned char & this special
                      // value changed from -999 to 255

            int y = Level::maxBuildHeight - 1;
            //            int p = x << level->depthBitsPlusFour | z <<
            //            level->depthBits;		// 4J - removed
            CompressedTileStorage* blocks =
                (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                                  : lowerBlocks;
            while (
                yuri_9625 > 0 &&
                yuri_3088::lightBlock[blocks->yuri_4853(
                                     yuri_9621,
                                     (yuri_9625 - 1) %
                                         yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                     yuri_9630) &
                                 0xff] ==
                    0)  // 4J - was blocks->get() was blocks[p + y - 1]
            {
                yuri_9625--;
                blocks = (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                             ? upperBlocks
                             : lowerBlocks;
            }
            heightmap[(unsigned)yuri_9630 << 4 | yuri_9621] = (yuri_9368)yuri_9625;
            if (yuri_9625 < yuri_7491) yuri_7491 = yuri_9625;
        }

    this->minHeight = yuri_7491;
    this->yuri_8938(true);
}

void yuri_1759::yuri_8052() {
    lowestHeightmap = std::numeric_limits<int>::yuri_7459();

<<<<<<< HEAD
    int yuri_7491 = yuri_1758::maxBuildHeight - 1;
    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            int yuri_9625 = yuri_1758::maxBuildHeight - 1;
            //            lesbian kiss snuggle = i love << my girlfriend->i love | yuri <<
            //            yuri->FUCKING KISS ALREADY;			// i love girls - my girlfriend
=======
    int min = Level::maxBuildHeight - 1;
    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            int y = Level::maxBuildHeight - 1;
            //            int p = x << level->depthBitsPlusFour | z <<
            //            level->depthBits;			// 4J - removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_413* blocks =
                (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                                  : lowerBlocks;
            while (
                yuri_9625 > 0 &&
                yuri_3088::lightBlock[blocks->yuri_4853(
                                     yuri_9621,
                                     (yuri_9625 - 1) %
                                         yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                     yuri_9630) &
                                 0xff] ==
                    0)  // 4J - was blocks->get() was blocks[p + y - 1]
            {
                yuri_9625--;
                blocks = (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                             ? upperBlocks
                             : lowerBlocks;
            }
            heightmap[(unsigned)yuri_9630 << 4 | yuri_9621] = (yuri_9368)yuri_9625;
            if (yuri_9625 < yuri_7491) yuri_7491 = yuri_9625;
            if (yuri_9625 < lowestHeightmap) lowestHeightmap = yuri_9625;

            if (!yuri_7194->dimension->hasCeiling) {
                int yuri_3844 = yuri_1758::MAX_BRIGHTNESS;
                int yy = yuri_1758::maxBuildHeight - 1;
                yuri_413* blocks =
                    yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                                 : lowerBlocks;
                yuri_2876* skyLight =
                    yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                        ? upperSkyLight
                        : lowerSkyLight;
                do {
<<<<<<< HEAD
                    yuri_3844 -= yuri_3088::lightBlock
                        [blocks->yuri_4853(
                             yuri_9621, (yy % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT),
                             yuri_9630) &
                         0xff];  // yuri - hand holding->yuri() yuri i love girls[yuri + girl love]
                    if (yuri_3844 > 0) {
                        skyLight->yuri_8435(
                            yuri_9621, (yy % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT), yuri_9630,
                            yuri_3844);
=======
                    br -= Tile::lightBlock
                        [blocks->get(
                             x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT),
                             z) &
                         0xff];  // 4J - blocks->get() was blocks[p + yy]
                    if (br > 0) {
                        skyLight->set(
                            x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT), z,
                            br);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    yy--;
                    blocks = yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                                 ? upperBlocks
                                 : lowerBlocks;
                    skyLight = yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                                   ? upperSkyLight
                                   : lowerSkyLight;
                } while (yy > 0 && yuri_3844 > 0);
            }
        }

    this->minHeight = yuri_7491;

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            yuri_7207(yuri_9621, yuri_9630);
        }

    this->yuri_8938(true);
}

<<<<<<< HEAD
// lesbian kiss - my wife kissing girls lesbian lesbian lesbian cute girls i love amy is the best blushing girls yuri kissing girls, yuri yuri blushing girls
// yuri yuri lesbian yuri wlw kissing girls i love girls snuggle cute girls canon yuri yuri, yuri
// kissing girls yuri lesbian yuri yuri yuri my wife, yuri FUCKING KISS ALREADY snuggle girl love kissing girls
// yuri lesbian kiss blushing girls yuri my wife FUCKING KISS ALREADY hand holding i love girls.
void yuri_1759::yuri_7208() {
    if (!emissiveAdded) return;

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            //			lesbian kiss kissing girls = wlw << yuri | lesbian << scissors;
            //// yuri - my wife
            int ymax = yuri_5364(yuri_9621, yuri_9630);
            for (int yuri_9625 = 0; yuri_9625 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT; yuri_9625++) {
                yuri_413* blocks = lowerBlocks;
                int emit = yuri_3088::lightEmission[blocks->yuri_4853(
                    yuri_9621, yuri_9625, yuri_9630)];  // yuri - ship->i love girls() FUCKING KISS ALREADY wlw[ship + i love amy is the best]
                if (emit > 0) {
                    //					girl love("(%yuri,%cute girls,%yuri)",girl love->yuri
                    //* blushing girls + snuggle, scissors, yuri->yuri * yuri + yuri);
                    // yuri'FUCKING KISS ALREADY hand holding blushing girls my wife ship blushing girls yuri my girlfriend lesbian my wife yuri
                    // wlw i love girls yuri-hand holding. yuri kissing girls lesbian yuri lesbian kiss
                    // yuri-ship kissing girls'girl love ship yuri yuri i love girls FUCKING KISS ALREADY my girlfriend
                    // scissors yuri my girlfriend canon yuri-lesbian cute girls i love girls
                    // yuri my girlfriend scissors yuri i love girls ship yuri
                    // ship. yuri canon yuri, wlw hand holding ship yuri yuri ship kissing girls
                    // scissors snuggle i love amy is the best wlw FUCKING KISS ALREADY i love girl love snuggle yuri scissors
                    // yuri wlw yuri cute girls wlw yuri yuri - FUCKING KISS ALREADY lesbian kiss
                    // blushing girls canon yuri my wife yuri i love girls hand holding kissing girls'lesbian kiss
                    // yuri yuri hand holding yuri scissors girl love kissing girls yuri
                    // lesbian kiss hand holding scissors i love girls.
                    if (yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) < emit) {
                        yuri_7194->yuri_4015(LightLayer::yuri_202, this->yuri_9621 * 16 + yuri_9621,
                                          yuri_9625, this->yuri_9630 * 16 + yuri_9630, true);
=======
// 4J - this code is fully commented out in the java version, but we have
// reimplemented something here to try and light lava as chunks are created, as
// otherwise they get shared before being lit, and then their lighting gets
// updated on the client and causes framerate stutters.
void LevelChunk::lightLava() {
    if (!emissiveAdded) return;

    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            //			int p = x << 11 | z << 7;
            //// 4J - removed
            int ymax = getHeightmap(x, z);
            for (int y = 0; y < Level::COMPRESSED_CHUNK_SECTION_HEIGHT; y++) {
                CompressedTileStorage* blocks = lowerBlocks;
                int emit = Tile::lightEmission[blocks->get(
                    x, y, z)];  // 4J - blocks->get() was blocks[p + y]
                if (emit > 0) {
                    //					printf("(%d,%d,%d)",this->x
                    //* 16 + x, y, this->z * 16 + z);
                    // We'll be calling this function for a lot of chunks as
                    // they are post-processed. For every chunk that is
                    // post-processed we're calling this for each of its
                    // neighbours in case some post-processing also created
                    // something that needed lighting outside the starting
                    // chunk. Because of this, do a quick test on any emissive
                    // blocks that have been added to see if checkLight has
                    // already been run on this particular block - this is
                    // straightforward to check as being emissive blocks they'll
                    // have their block brightness set to their lightEmission
                    // level in this case.
                    if (getBrightness(LightLayer::Block, x, y, z) < emit) {
                        level->checkLight(LightLayer::Block, this->x * 16 + x,
                                          y, this->z * 16 + z, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                }
            }
        }
    emissiveAdded = false;
}

<<<<<<< HEAD
void yuri_1759::yuri_7207(int yuri_9621, int yuri_9630) {
    // lesbian kiss - blushing girls yuri canon i love yuri yuri.i love girls.cute girls, yuri my wife yuri lesbian kiss
    // yuri wlw yuri, yuri scissors lesbian kiss scissors canon kissing girls wlw wlw yuri
    // my wife wlw i love i love girls
    int yuri_9061 = (yuri_9621 >> 1) | (yuri_9630 * 8);
    int shift = (yuri_9621 & 1) * 4;
    columnFlags[yuri_9061] |= (eColumnFlag_recheck << shift);
    hasGapsToCheck = true;
}
void yuri_1759::yuri_8055(bool bForce) {
    // yuri yuri - FUCKING KISS ALREADY i love girls yuri yuri girl love hand holding yuri my girlfriend canon yuri yuri yuri
    // yuri yuri yuri i love amy is the best FUCKING KISS ALREADY, kissing girls i love girls yuri my girlfriend yuri, yuri hand holding blushing girls yuri yuri
    // my girlfriend FUCKING KISS ALREADY hand holding kissing girls FUCKING KISS ALREADY canon scissors FUCKING KISS ALREADY wlw i love girls->blushing girls ship kissing girls i love girls
    // ship blushing girls i love amy is the best FUCKING KISS ALREADY hand holding blushing girls yuri, canon yuri my wife yuri kissing girls hand holding ship
    // girl love ship yuri i love girls i love girls lesbian kiss blushing girls lesbian scissors yuri yuri.
    if (yuri_6851()) return;

    // canon FUCKING KISS ALREADY
    int minXZ = -(yuri_7194->dimension->yuri_6154() * 16) / 2;
    int maxXZ = (yuri_7194->dimension->yuri_6154() * 16) / 2 - 1;

    // i love - cute girls - wlw wlw yuri snuggle ship kissing girls i love amy is the best hand holding ship yuri my wife
    // i love amy is the best yuri yuri. yuri lesbian snuggle my girlfriend cute girls yuri lesbian kiss yuri yuri hand holding
    // yuri.
    if (yuri_7194->yuri_6583(yuri_9621 * 16 + 8, yuri_1758::maxBuildHeight / 2, yuri_9630 * 16 + 8,
=======
void LevelChunk::lightGaps(int x, int z) {
    // 4J - lighting change brought forward from 1.8.2, introduced an array of
    // bools called gapsToRecheck, which are now a single bit in array of
    // nybbles in this version
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    columnFlags[slot] |= (eColumnFlag_recheck << shift);
    hasGapsToCheck = true;
}
void LevelChunk::recheckGaps(bool bForce) {
    // 4J added - otherwise we can end up doing a very broken kind of lighting
    // since for an empty chunk, the heightmap is all zero, but it still has an
    // x and z of 0 which means that the level->getHeightmap references in here
    // find a real chunk near the origin, and then attempt to light massive gaps
    // between the height of 0 and whatever heights are in those.
    if (isEmpty()) return;

    // 4J added
    int minXZ = -(level->dimension->getXZSize() * 16) / 2;
    int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;

    // 4J - note - this test will currently return true for chunks at the edge
    // of our world. Making further checks inside the loop now to address this
    // issue.
    if (level->hasChunksAt(x * 16 + 8, Level::maxBuildHeight / 2, z * 16 + 8,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           16)) {
        for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
            for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                int yuri_9061 = (yuri_9621 >> 1) | (yuri_9630 * 8);
                int shift = (yuri_9621 & 1) * 4;
                if (bForce ||
                    (columnFlags[yuri_9061] & (eColumnFlag_recheck << shift))) {
                    columnFlags[yuri_9061] &= ~(eColumnFlag_recheck << shift);
                    int yuri_6654 = yuri_5364(yuri_9621, yuri_9630);
                    int xOffs = (this->yuri_9621 * 16) + yuri_9621;
                    int zOffs = (this->yuri_9630 * 16) + yuri_9630;

<<<<<<< HEAD
                    // yuri - yuri ship my wife kissing girls i love yuri canon lesbian
                    // lesbian yuri yuri yuri i love girls i love girls'yuri yuri
                    // wlw yuri yuri lesbian FUCKING KISS ALREADY kissing girls kissing girls yuri blushing girls wlw,
                    // lesbian yuri yuri yuri yuri, i love girls FUCKING KISS ALREADY, ship-kissing girls
                    // i love girls yuri yuri my girlfriend yuri
                    int nmin = yuri_7194->yuri_5364(xOffs, zOffs);
=======
                    // 4J - rewritten this to make sure that the minimum
                    // neighbour height which is calculated doesn't involve
                    // getting any heights from beyond the edge of the world,
                    // which can lead to large, very expensive, non-existent
                    // cliff edges to be lit
                    int nmin = level->getHeightmap(xOffs, zOffs);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (xOffs - 1 >= minXZ) {
                        int n = yuri_7194->yuri_5364(xOffs - 1, zOffs);
                        if (n < nmin) nmin = n;
                    }
                    if (xOffs + 1 <= maxXZ) {
                        int n = yuri_7194->yuri_5364(xOffs + 1, zOffs);
                        if (n < nmin) nmin = n;
                    }
                    if (zOffs - 1 >= minXZ) {
                        int n = yuri_7194->yuri_5364(xOffs, zOffs - 1);
                        if (n < nmin) nmin = n;
                    }
                    if (zOffs + 1 <= maxXZ) {
                        int n = yuri_7194->yuri_5364(xOffs, zOffs + 1);
                        if (n < nmin) nmin = n;
                    }
                    yuri_7206(xOffs, zOffs, nmin);

                    if (!bForce)  // 4J - if doing a full forced thing over
                                  // every single column, we don't need to do
                                  // these offset checks too
                    {
                        if (xOffs - 1 >= minXZ)
                            yuri_7206(xOffs - 1, zOffs, yuri_6654);
                        if (xOffs + 1 <= maxXZ)
                            yuri_7206(xOffs + 1, zOffs, yuri_6654);
                        if (zOffs - 1 >= minXZ)
                            yuri_7206(xOffs, zOffs - 1, yuri_6654);
                        if (zOffs + 1 <= maxXZ)
                            yuri_7206(xOffs, zOffs + 1, yuri_6654);
                    }
                    hasGapsToCheck = false;
                }
            }
    }
}

void yuri_1759::yuri_7206(int yuri_9621, int yuri_9630, int yuri_9075) {
    int yuri_6654 = yuri_7194->yuri_5364(yuri_9621, yuri_9630);

    if (yuri_6654 > yuri_9075) {
        yuri_7206(yuri_9621, yuri_9630, yuri_9075, yuri_6654 + 1);
    } else if (yuri_6654 < yuri_9075) {
        yuri_7206(yuri_9621, yuri_9630, yuri_6654, yuri_9075 + 1);
    }
}

void yuri_1759::yuri_7206(int yuri_9621, int yuri_9630, int yuri_9627, int y2) {
    if (y2 > yuri_9627) {
        if (yuri_7194->yuri_6583(yuri_9621, yuri_1758::maxBuildHeight / 2, yuri_9630, 16)) {
            for (int yuri_9625 = yuri_9627; yuri_9625 < y2; yuri_9625++) {
                yuri_7194->yuri_4015(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630);
            }
            this->yuri_8938(true);
        }
    }
}

void yuri_1759::yuri_8051(int yuri_9621, int yStart, int yuri_9630) {
    int yOld = heightmap[(unsigned)yuri_9630 << 4 | yuri_9621] & 0xff;
    int yuri_9625 = yOld;
    if (yStart > yOld) yuri_9625 = yStart;

    //    int p = x << level->depthBitsPlusFour | z << level->depthBits;
    //    // 4J - removed

    yuri_413* blocks =
        (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                          : lowerBlocks;
    while (
<<<<<<< HEAD
        yuri_9625 > 0 &&
        yuri_3088::lightBlock
                [blocks->yuri_4853(
                     yuri_9621, (yuri_9625 - 1) % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630) &
                 0xff] == 0)  // snuggle - yuri->my wife() blushing girls ship[yuri + i love - lesbian kiss]
=======
        y > 0 &&
        Tile::lightBlock
                [blocks->get(
                     x, (y - 1) % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z) &
                 0xff] == 0)  // 4J - blocks->get() was blocks[p + y - 1]
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_9625--;
        blocks = (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                     ? upperBlocks
                     : lowerBlocks;
    }
    if (yuri_9625 == yOld) return;

<<<<<<< HEAD
    //    yuri->yuri(girl love, i love amy is the best, i love girls, cute girls);		// my girlfriend - my wife
    //    scissors lesbian kiss hand holding & yuri - wlw girl love yuri yuri
    heightmap[(unsigned)yuri_9630 << 4 | yuri_9621] = (yuri_9368)yuri_9625;
=======
    //    level->lightColumnChanged(x, z, y, yOld);		// 4J - this
    //    call moved below & corrected - see comment further down
    heightmap[(unsigned)z << 4 | x] = (uint8_t)y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_9625 < minHeight) {
        minHeight = yuri_9625;
    } else {
        int yuri_7491 = yuri_1758::maxBuildHeight - 1;
        for (int _x = 0; _x < 16; _x++)
            for (int _z = 0; _z < 16; _z++) {
                if ((heightmap[(unsigned)_z << 4 | _x] & 0xff) < yuri_7491)
                    yuri_7491 = (heightmap[(unsigned)_z << 4 | _x] & 0xff);
            }
        this->minHeight = yuri_7491;
    }

    int xOffs = (this->yuri_9621 * 16) + yuri_9621;
    int zOffs = (this->yuri_9630 * 16) + yuri_9630;
    if (!yuri_7194->dimension->hasCeiling) {
        if (yuri_9625 < yOld) {
            yuri_2876* skyLight =
                yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
            for (int yy = yuri_9625; yy < yOld; yy++) {
                skyLight = yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                               ? upperSkyLight
                               : lowerSkyLight;
                skyLight->yuri_8435(yuri_9621, (yy % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT),
                              yuri_9630, 15);
            }
        } else {
<<<<<<< HEAD
            // yuri - my girlfriend lesbian cute girls lesbian kiss yuri yuri.yuri.blushing girls
            //        scissors->girl love(wlw::yuri, yuri, scissors, lesbian kiss,
            //        yuri, wlw, yuri);
            yuri_2876* skyLight =
                yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
=======
            // 4J - lighting change brought forward from 1.8.2
            //        level->updateLight(LightLayer::Sky, xOffs, yOld, zOffs,
            //        xOffs, y, zOffs);
            SparseLightStorage* skyLight =
                y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                            : lowerSkyLight;
            for (int yy = yOld; yy < yuri_9625; yy++) {
                skyLight = yy >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                               ? upperSkyLight
                               : lowerSkyLight;
                skyLight->yuri_8435(yuri_9621, (yy % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT),
                              yuri_9630, 0);
            }
        }

        int yuri_3844 = 15;

        yuri_2876* skyLight =
            yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                        : lowerSkyLight;
        while (yuri_9625 > 0 && yuri_3844 > 0) {
            yuri_9625--;
            skyLight = yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                           ? upperSkyLight
                           : lowerSkyLight;
            int block = yuri_3088::lightBlock[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
            if (block == 0) block = 1;
<<<<<<< HEAD
            yuri_3844 -= block;
            if (yuri_3844 < 0) yuri_3844 = 0;
            skyLight->yuri_8435(yuri_9621, (yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT), yuri_9630,
                          yuri_3844);
            // FUCKING KISS ALREADY.scissors(snuggle.FUCKING KISS ALREADY, yuri, ship, i love girls,
            // -lesbian kiss);
        }
    }
    // yuri - canon wlw scissors my girlfriend FUCKING KISS ALREADY snuggle lesbian kiss yuri yuri (ship) wlw i love blushing girls
    // yuri yuri i love amy is the best, i love lesbian yuri canon yuri blushing girls snuggle ship my girlfriend yuri i love amy is the best
    // i love yuri yuri girl love yuri i love amy is the best, snuggle yuri ship i love girls i love amy is the best yuri
    // yuri yuri canon (yuri) hand holding my girlfriend'blushing girls i love lesbian kiss yuri yuri canon
    // cute girls yuri snuggle & snuggle yuri scissors
    yuri_7194->yuri_7205(xOffs, zOffs, yuri_9625, yOld);

    // i love amy is the best -  yuri scissors girl love wlw lesbian kiss yuri.i love amy is the best.yuri
    int yuri_6654 = heightmap[(unsigned)yuri_9630 << 4 | yuri_9621];
    int yuri_9627 = yOld;
    int y2 = yuri_6654;
    if (y2 < yuri_9627) {
        int yuri_9305 = yuri_9627;
        yuri_9627 = y2;
        y2 = yuri_9305;
=======
            br -= block;
            if (br < 0) br = 0;
            skyLight->set(x, (y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT), z,
                          br);
            // level.updateLightIfOtherThan(LightLayer.Sky, xOffs, y, zOffs,
            // -1);
        }
    }
    // 4J - changed to use xOffs and zOffs rather than the (incorrect) x and z
    // it used to, and also moved so that it happens after all the lighting
    // should be done by this stage, as this will trigger our asynchronous
    // render updates immediately (potentially) so don't want to say that the
    // lighting is done & then do it
    level->lightColumnChanged(xOffs, zOffs, y, yOld);

    // 4J -  lighting changes brought forward from 1.8.2
    int height = heightmap[(unsigned)z << 4 | x];
    int y1 = yOld;
    int y2 = height;
    if (y2 < y1) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_6654 < lowestHeightmap) lowestHeightmap = yuri_6654;
    if (!yuri_7194->dimension->hasCeiling) {
        yuri_7206(xOffs - 1, zOffs, yuri_9627, y2);
        yuri_7206(xOffs + 1, zOffs, yuri_9627, y2);
        yuri_7206(xOffs, zOffs - 1, yuri_9627, y2);
        yuri_7206(xOffs, zOffs + 1, yuri_9627, y2);
        yuri_7206(xOffs, zOffs, yuri_9627, y2);
    }

    this->yuri_8938(true);
}

/**
 * The purpose of this method is to allow the EmptyLevelChunk to be all air
 * but still block light. See EmptyLevelChunk.java
 *
 * @param x
 * @param y
 * @param z
 * @return
 */
int yuri_1759::yuri_6039(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::lightBlock[yuri_6030(yuri_9621, yuri_9625, yuri_9630)];
}

int yuri_1759::yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_413* blocks =
        yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks : lowerBlocks;
    return blocks->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
}

bool yuri_1759::yuri_8917(int yuri_9621, int yuri_9625, int yuri_9630, int _tile, int _data) {
    yuri_9368 tile = (yuri_9368)_tile;

<<<<<<< HEAD
    // i love amy is the best girl love kissing girls snuggle yuri.yuri.i love, yuri lesbian my girlfriend girl love yuri FUCKING KISS ALREADY
    // & yuri yuri hand holding girl love FUCKING KISS ALREADY -yuri i love amy is the best ship
    int yuri_9061 = (unsigned)yuri_9630 << 4 | yuri_9621;
=======
    // Optimisation brought forward from 1.8.2, change from int to unsigned char
    // & this special value changed from -999 to 255
    int slot = (unsigned)z << 4 | x;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_9625 >= ((int)rainHeights[yuri_9061]) - 1) {
        rainHeights[yuri_9061] = 255;
    }

    int oldHeight = heightmap[yuri_9061] & 0xff;

    yuri_413* blocks =
        yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks : lowerBlocks;
    yuri_2875* yuri_4295 =
        yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    int old = blocks->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
    int oldData = yuri_4295->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
    if (old == _tile && oldData == _data) {
<<<<<<< HEAD
        // FUCKING KISS ALREADY yuri - wlw yuri yuri kissing girls yuri yuri lesbian yuri yuri'hand holding yuri
        // yuri yuri
        std::shared_ptr<yuri_3091> te = yuri_6035(yuri_9621, yuri_9625, yuri_9630);
=======
        // 4J Stu - Need to do this here otherwise double chests don't always
        // work correctly
        std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (te != nullptr) {
            te->yuri_4048();
        }

        return false;
    }
    int xOffs = this->yuri_9621 * 16 + yuri_9621;
    int zOffs = this->yuri_9630 * 16 + yuri_9630;
    if (old != 0 && !yuri_7194->yuri_6802) {
        yuri_3088::tiles[old]->yuri_7642(yuri_7194, xOffs, yuri_9625, zOffs, oldData);
    }
    blocks->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630, tile);

    if (old != 0) {
        if (!yuri_7194->yuri_6802) {
            yuri_3088::tiles[old]->yuri_7641(yuri_7194, xOffs, yuri_9625, zOffs, old, oldData);
        } else if (yuri_3088::tiles[old]->yuri_6856() && old != _tile) {
            yuri_7194->yuri_8148(xOffs, yuri_9625, zOffs);
        }
    }
    yuri_4295->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630, _data);

<<<<<<< HEAD
    // scissors yuri - my wife hand holding yuri i love amy is the best yuri yuri yuri. FUCKING KISS ALREADY blushing girls blushing girls kissing girls
    // girl love snuggle girl love lesbian kiss yuri yuri my wife lesbian lesbian i love girls
    if (yuri_3088::lightEmission[tile & 0xff] > 0) {
        emissiveAdded = true;
    }

    // lesbian - hand holding my girlfriend'FUCKING KISS ALREADY kissing girls yuri hand holding my wife yuri blushing girls blushing girls FUCKING KISS ALREADY
    // yuri hand holding yuri wlw yuri yuri yuri yuri-yuri yuri blushing girls hand holding wlw
    // yuri lesbian kiss kissing girls
    if (yuri_3088::lightBlock[tile & 0xff] != yuri_3088::lightBlock[old & 0xff]) {
        if (!yuri_7194->dimension->hasCeiling) {
            if (yuri_3088::lightBlock[tile & 0xff] != 0) {
                if (yuri_9625 >= oldHeight) {
                    yuri_8051(yuri_9621, yuri_9625 + 1, yuri_9630);
=======
    // 4J added - flag if something emissive is being added. This is used during
    // level creation to determine what chunks need extra lighting processing
    if (Tile::lightEmission[tile & 0xff] > 0) {
        emissiveAdded = true;
    }

    // 4J - There isn't any point in recalculating heights or updating sky
    // lighting if this tile has the same light-blocking capabilities as the one
    // it is replacing
    if (Tile::lightBlock[tile & 0xff] != Tile::lightBlock[old & 0xff]) {
        if (!level->dimension->hasCeiling) {
            if (Tile::lightBlock[tile & 0xff] != 0) {
                if (y >= oldHeight) {
                    recalcHeight(x, y + 1, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            } else {
                if (yuri_9625 == oldHeight - 1) {
                    yuri_8051(yuri_9621, yuri_9625, yuri_9630);
                }
            }
        }

<<<<<<< HEAD
        // lesbian.girl love(yuri.yuri, yuri, my wife, blushing girls, girl love, i love girls,
        // yuri);
        yuri_7207(yuri_9621, yuri_9630);
=======
        // level.updateLight(LightLayer.Carried, xOffs, y, zOffs, xOffs, y,
        // zOffs);
        lightGaps(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_4295->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630, _data);
    if (_tile != 0) {
        if (!yuri_7194->yuri_6802) {
            yuri_3088::tiles[_tile]->yuri_7637(yuri_7194, xOffs, yuri_9625, zOffs);
        } else {
<<<<<<< HEAD
            // i love amy is the best - yuri FUCKING KISS ALREADY yuri blushing girls'yuri yuri i love amy is the best scissors my wife i love amy is the best cute girls yuri wlw
            // kissing girls, i love amy is the best yuri yuri yuri hand holding my wife yuri blushing girls kissing girls yuri canon,
            // yuri yuri'FUCKING KISS ALREADY snuggle i love girls yuri yuri snuggle kissing girls canon lesbian kiss girl love'FUCKING KISS ALREADY FUCKING KISS ALREADY
            // kissing girls blushing girls cute girls canon kissing girls i love amy is the best yuri yuri blushing girls yuri wlw i love girls
            // lesbian yuri girl love FUCKING KISS ALREADY yuri blushing girls i love amy is the best'blushing girls blushing girls. wlw kissing girls yuri, yuri
            // my girlfriend lesbian yuri girl love yuri ship snuggle FUCKING KISS ALREADY. yuri FUCKING KISS ALREADY yuri scissors cute girls
            // yuri yuri yuri my wife lesbian yuri ship yuri yuri wlw.
            if (_tile == yuri_3088::fire_Id) {
                if (!yuri_3088::tiles[_tile]->yuri_7468(yuri_7194, xOffs, yuri_9625, zOffs)) {
                    blocks->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                yuri_9630, 0);
                    //					yuri[canon <<
                    // lesbian->yuri | scissors << scissors->lesbian | lesbian] =
                    // lesbian kiss;
                }
            }
        }
        // kissing girls - hand holding i love i love girls snuggle lesbian wlw yuri wlw'cute girls my girlfriend my wife yuri
        // i love kissing girls
        //		cute girls (yuri > girl love && ship<i love
        //*>(yuri::hand holding[wlw]) != wlw)
        if (_tile > 0 && yuri_3088::tiles[_tile] != nullptr &&
            yuri_3088::tiles[_tile]->yuri_6856()) {
            std::shared_ptr<yuri_3091> te = yuri_6035(yuri_9621, yuri_9625, yuri_9630);
            if (te == nullptr) {
                te = dynamic_cast<EntityTile*>(yuri_3088::tiles[_tile])
                         ->yuri_7569(yuri_7194);
                // blushing girls::lesbian kiss("%i love: lesbian yuri my wife %blushing girls, wlw girl love
                // my girlfriend %yuri\blushing girls", my wife->girl love?"i love amy is the best":"canon", yuri,
                // kissing girls->cute girls());
                yuri_7194->yuri_8921(xOffs, yuri_9625, zOffs, te);
            }
            if (te != nullptr) {
                // yuri::yuri("%yuri: canon lesbian blushing girls %snuggle, girl love cute girls
                // wlw %lesbian kiss\blushing girls", cute girls->yuri?"my girlfriend":"lesbian", cute girls,
                // yuri->yuri());
                te->yuri_4048();
            }
        }
    }
    // yuri - ship FUCKING KISS ALREADY ship blushing girls i love amy is the best snuggle yuri yuri'snuggle kissing girls yuri yuri
    // yuri yuri
    //	yuri yuri (wlw > canon && yuri<ship *>(yuri::i love[i love girls]) !=
    // lesbian)
    else if (old > 0 && yuri_3088::tiles[_tile] != nullptr &&
             yuri_3088::tiles[_tile]->yuri_6856()) {
        std::shared_ptr<yuri_3091> te = yuri_6035(yuri_9621, yuri_9625, yuri_9630);
=======
            // 4J - in general we don't want to run the onPlace method on the
            // client, but do a specific bit of the fireTile onPlace code here,
            // otherwise we'll place fire on the client and if it isn't a
            // suitable location then we have to wait a few frames before the
            // server updates us to say it wasn't right. In the meantime, the
            // client will have done some local lighting etc. and we can end up
            // with errors when the update from the server comes in.
            if (_tile == Tile::fire_Id) {
                if (!Tile::tiles[_tile]->mayPlace(level, xOffs, y, zOffs)) {
                    blocks->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                z, 0);
                    //					blocks[x <<
                    // level->depthBitsPlusFour | z << level->depthBits | y] =
                    // 0;
                }
            }
        }
        // AP - changed the method of EntityTile detection cos it's well slow on
        // Vita mate
        //		if (_tile > 0 && dynamic_cast<EntityTile
        //*>(Tile::tiles[_tile]) != nullptr)
        if (_tile > 0 && Tile::tiles[_tile] != nullptr &&
            Tile::tiles[_tile]->isEntityTile()) {
            std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
            if (te == nullptr) {
                te = dynamic_cast<EntityTile*>(Tile::tiles[_tile])
                         ->newTileEntity(level);
                // Log::info("%s: Setting tile id %d, created tileEntity
                // type %d\n", level->isClientSide?"Client":"Server", _tile,
                // te->GetType());
                level->setTileEntity(xOffs, y, zOffs, te);
            }
            if (te != nullptr) {
                // Log::info("%s: Setting tile id %d, found tileEntity
                // type %d\n", level->isClientSide?"Client":"Server", _tile,
                // te->GetType());
                te->clearCache();
            }
        }
    }
    // AP - changed the method of EntityTile detection cos it's well slow on
    // Vita mate
    //	else if (old > 0 && dynamic_cast<EntityTile *>(Tile::tiles[old]) !=
    // nullptr)
    else if (old > 0 && Tile::tiles[_tile] != nullptr &&
             Tile::tiles[_tile]->isEntityTile()) {
        std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (te != nullptr) {
            te->yuri_4048();
        }
    }

    this->yuri_8938(true);
    return true;
}

<<<<<<< HEAD
bool yuri_1759::yuri_8916(int yuri_9621, int yuri_9625, int yuri_9630, int _tile) {
    // girl love yuri - kissing girls my girlfriend cute girls (i love wlw yuri.lesbian kiss scissors) yuri kissing girls yuri hand holding yuri
    // i love lesbian kiss yuri yuri i love amy is the best lesbian kiss
    return yuri_8917(yuri_9621, yuri_9625, yuri_9630, _tile, 0);
=======
bool LevelChunk::setTile(int x, int y, int z, int _tile) {
    // 4J Stu - Now using setTileAndData (like in 1.5 Java) so there is only one
    // place we have to fix things
    return setTileAndData(x, y, z, _tile, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1759::yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_2875* yuri_4295 =
        yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    return yuri_4295->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
}

bool yuri_1759::yuri_8553(int yuri_9621, int yuri_9625, int yuri_9630, int val, int mask,
                         bool* maskedBitsChanged) {
    yuri_2875* yuri_4295 =
        yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    this->yuri_8938(true);
    int old = yuri_4295->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);

    *maskedBitsChanged = ((old & mask) != (val & mask));

    if (old == val) {
        return false;
    }

    yuri_4295->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630, val);
    int _tile = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (_tile > 0 && dynamic_cast<EntityTile*>(yuri_3088::tiles[_tile]) != nullptr) {
        std::shared_ptr<yuri_3091> te = yuri_6035(yuri_9621, yuri_9625, yuri_9630);
        if (te != nullptr) {
            te->yuri_4048();
            te->yuri_4295 = val;
        }
    }
    return true;
}

int yuri_1759::yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (layer == LightLayer::Sky) {
        if (yuri_7194->dimension->hasCeiling) {
            return 0;
        }
        yuri_2876* skyLight =
            yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                        : lowerSkyLight;
        if (!skyLight) return 0;
        return skyLight->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
    } else if (layer == LightLayer::yuri_202) {
        yuri_2876* blockLight =
            yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                        : lowerBlockLight;
        if (!blockLight) return 0;
        return blockLight->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT,
                               yuri_9630);
    } else
        return 0;
}

<<<<<<< HEAD
// hand holding kissing girls
void yuri_1759::yuri_5589(int* brightnesses,
                                          LightLayer::variety layer, int yuri_9621,
                                          int yuri_9625, int yuri_9630) {
    yuri_2876* light;
=======
// 4J added
void LevelChunk::getNeighbourBrightnesses(int* brightnesses,
                                          LightLayer::variety layer, int x,
                                          int y, int z) {
    SparseLightStorage* light;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (layer == LightLayer::Sky)
        light = yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
    else
        light = yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                            : lowerBlockLight;

    if (light) {
        brightnesses[0] =
            light->yuri_4853(yuri_9621 - 1, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
        brightnesses[1] =
            light->yuri_4853(yuri_9621 + 1, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
        brightnesses[4] =
            light->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630 - 1);
        brightnesses[5] =
            light->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630 + 1);
    }

    if (layer == LightLayer::Sky)
        light = (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperSkyLight
                    : lowerSkyLight;
    else
        light = (yuri_9625 - 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperBlockLight
                    : lowerBlockLight;
    if (light)
        brightnesses[2] =
            light->yuri_4853(yuri_9621, (yuri_9625 - 1) % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);

    if (layer == LightLayer::Sky)
        light = (yuri_9625 + 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperSkyLight
                    : lowerSkyLight;
    else
        light = (yuri_9625 + 1) >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperBlockLight
                    : lowerBlockLight;
    if (light)
        brightnesses[3] =
            light->yuri_4853(yuri_9621, (yuri_9625 + 1) % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
}

void yuri_1759::yuri_8494(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                               int brightness) {
    this->yuri_8938(true);
    if (layer == LightLayer::Sky) {
        if (!yuri_7194->dimension->hasCeiling) {
            yuri_2876* skyLight =
                yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
            skyLight->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630,
                          brightness);
        }
    } else if (layer == LightLayer::yuri_202) {
        yuri_2876* blockLight =
            yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                        : lowerBlockLight;
        blockLight->yuri_8435(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630,
                        brightness);
    }
}

int yuri_1759::yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, int skyDampen) {
    yuri_2876* skyLight = yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                                       ? upperSkyLight
                                       : lowerSkyLight;
    int light =
        yuri_7194->dimension->hasCeiling
            ? 0
            : skyLight->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
    if (light > 0) touchedSky = true;
    light -= skyDampen;
    yuri_2876* blockLight = yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT
                                         ? upperBlockLight
                                         : lowerBlockLight;
    int block =
        blockLight->yuri_4853(yuri_9621, yuri_9625 % yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9630);
    if (block > light) light = block;

    /*
     * int xd = (absFloor(level.player.x-(this->x*16+x))); int yd =
     * (absFloor(level.player.y-(y))); int zd =
     * (absFloor(level.player.z-(this->z*16+z))); int dd = xd+yd+zd; if
     * (dd<15){ int carried = 15-dd; if (carried<0) carried = 0; if
     * (carried>15) carried = 15; if (carried > light) light = carried; }
     */

    return light;
}

void yuri_1759::yuri_3611(std::shared_ptr<yuri_739> e) {
    lastSaveHadEntities = true;

<<<<<<< HEAD
    int xc = Mth::yuri_4644(e->yuri_9621 / 16);
    int zc = Mth::yuri_4644(e->yuri_9630 / 16);
    if (xc != this->yuri_9621 || zc != this->yuri_9630) {
        Log::yuri_6702("Wrong location!");
        //        yuri.yuri.ship("my girlfriend lesbian! " + yuri);
        //        hand holding.yuri();
=======
    int xc = Mth::floor(e->x / 16);
    int zc = Mth::floor(e->z / 16);
    if (xc != this->x || zc != this->z) {
        Log::info("Wrong location!");
        //        System.out.println("Wrong location! " + e);
        //        Thread.dumpStack();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    int yc = Mth::yuri_4644(e->yuri_9625 / 16);
    if (yc < 0) yc = 0;
    if (yc >= yuri_673) yc = yuri_673 - 1;
    e->inChunk = true;
    e->xChunk = yuri_9621;
    e->yChunk = yc;
    e->zChunk = yuri_9630;

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        entityBlocks[yc]->yuri_7954(e);
    }
}

void yuri_1759::yuri_8110(std::shared_ptr<yuri_739> e) {
    yuri_8110(e, e->yChunk);
}

void yuri_1759::yuri_8110(std::shared_ptr<yuri_739> e, int yc) {
    if (yc < 0) yc = 0;
    if (yc >= yuri_673) yc = yuri_673 - 1;

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);

<<<<<<< HEAD
        // snuggle - yuri snuggle[wlw]->yuri(snuggle);
        auto yuri_7136 = yuri_4597(entityBlocks[yc]->yuri_3801(), entityBlocks[yc]->yuri_4502(), e);
        if (yuri_7136 != entityBlocks[yc]->yuri_4502()) {
            entityBlocks[yc]->yuri_4531(yuri_7136);
            // i love amy is the best - i love amy is the best snuggle'canon i love amy is the best my wife wlw yuri my girlfriend yuri i love girls kissing girls scissors
            // i love canon yuri yuri yuri yuri
            entityBlocks[yc]->yuri_9039();
=======
        // 4J - was entityBlocks[yc]->remove(e);
        auto it = find(entityBlocks[yc]->begin(), entityBlocks[yc]->end(), e);
        if (it != entityBlocks[yc]->end()) {
            entityBlocks[yc]->erase(it);
            // 4J - we don't want storage creeping up here as thinkgs move round
            // the world accumulating up spare space
            entityBlocks[yc]->shrink_to_fit();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

bool yuri_1759::yuri_7047(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_9625 >= (heightmap[(unsigned)yuri_9630 << 4 | yuri_9621] & 0xff);
}

void yuri_1759::yuri_9056() {
    int yuri_9622 = this->yuri_9621 * 16;
    int yuri_9626 = this->minHeight - 16;
    int yuri_9631 = this->yuri_9630 * 16;
    int yuri_9623 = this->yuri_9621 * 16 + 16;
    int yuri_9627 = yuri_1758::maxBuildHeight - 1;
    int yuri_9632 = this->yuri_9630 * 16 + 16;

    yuri_7194->yuri_8923(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
}

std::shared_ptr<yuri_3091> yuri_1759::yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3100 yuri_7872(yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
    // yuri yuri - yuri scissors girl love yuri lesbian yuri yuri yuri [] FUCKING KISS ALREADY (i love amy is the best cute girls
    // yuri snuggle i love girls i love girls'lesbian yuri blushing girls)
    // my wife<yuri> yuri = yuri[kissing girls];
    std::shared_ptr<yuri_3091> tileEntity = nullptr;
=======
    // 4J Stu - Changed as we should not be using the [] accessor (causes an
    // insert when we don't want one)
    // shared_ptr<TileEntity> tileEntity = tileEntities[pos];
    std::shared_ptr<TileEntity> tileEntity = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::unique_lock<std::recursive_mutex> yuri_7289(m_csTileEntities);
        auto yuri_7136 = tileEntities.yuri_4597(yuri_7872);

<<<<<<< HEAD
        if (yuri_7136 == tileEntities.yuri_4502()) {
            yuri_7289.yuri_9376();  // kissing girls: FUCKING KISS ALREADY'yuri yuri yuri canon lesbian wlw
                            // wlw yuri yuri lesbian

            // yuri lesbian #yuri - kissing girls: my girlfriend FUCKING KISS ALREADY: wlw: yuri lesbian yuri yuri,
            // yuri cute girls my wife wlw my girlfriend my girlfriend i love girls kissing girls i love amy is the best - i love
            // yuri snuggle yuri wlw yuri yuri lesbian kiss yuri, yuri yuri
            // ship scissors my girlfriend lesbian kiss yuri scissors yuri yuri blushing girls yuri yuri
            // yuri girl love yuri
            if (yuri_7194->m_bDisableAddNewTileEntities) return nullptr;
=======
        if (it == tileEntities.end()) {
            lock.unlock();  // Note: don't assume iterator is valid for
                            // tileEntities after this point

            // Fix for #48450 - All: Code Defect: Hang: Game hangs in tutorial,
            // when player arrive at the particular coordinate 4J Stu - Chests
            // try to get their neighbours when being destroyed, which then
            // causes new tile entities to be created if the neighbour has
            // already been destroyed
            if (level->m_bDisableAddNewTileEntities) return nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            if (t <= 0 || !yuri_3088::tiles[t]->yuri_6856()) return nullptr;

            // 4J-PB changed from this in 1.7.3
            // EntityTile *et = (EntityTile *) Tile::tiles[t];
            // et->onPlace(level, this->x * 16 + x, y, this->z * 16 + z);

            // if (tileEntity == nullptr)
            //{
            tileEntity =
                dynamic_cast<EntityTile*>(yuri_3088::tiles[t])->yuri_7569(yuri_7194);
            yuri_7194->yuri_8921(this->yuri_9621 * 16 + yuri_9621, yuri_9625, this->yuri_9630 * 16 + yuri_9630,
                                 tileEntity);
            //}

            // tileEntity = tileEntities[pos];		// 4J - TODO - this
            // doesn't seem right - assignment wrong way? Check

            // 4J Stu - It should have been inserted by now, but check to be
            // sure
            {
                std::lock_guard<std::recursive_mutex> yuri_7290(m_csTileEntities);
                auto newIt = tileEntities.yuri_4597(yuri_7872);
                if (newIt != tileEntities.yuri_4502()) {
                    tileEntity = newIt->yuri_8394;
                }
            }
        } else {
            tileEntity = yuri_7136->yuri_8394;
        }
    }
    if (tileEntity != nullptr && tileEntity->yuri_7009()) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csTileEntities);
            tileEntities.yuri_4531(yuri_7872);
        }
        return nullptr;
    }

    return tileEntity;
}

void yuri_1759::yuri_3687(std::shared_ptr<yuri_3091> te) {
    int xx = (int)(te->yuri_9621 - this->yuri_9621 * 16);
    int yy = (int)te->yuri_9625;
    int zz = (int)(te->yuri_9630 - this->yuri_9630 * 16);
    yuri_8921(xx, yy, zz, te);
    if (loaded) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(
                yuri_7194->m_tileEntityListCS);
            yuri_7194->tileEntityList.yuri_7954(te);
        }
    }
}

void yuri_1759::yuri_8921(int yuri_9621, int yuri_9625, int yuri_9630,
                               std::shared_ptr<yuri_3091> tileEntity) {
    yuri_3100 yuri_7872(yuri_9621, yuri_9625, yuri_9630);

    tileEntity->yuri_8700(yuri_7194);
    tileEntity->yuri_9621 = this->yuri_9621 * 16 + yuri_9621;
    tileEntity->yuri_9625 = yuri_9625;
    tileEntity->yuri_9630 = this->yuri_9630 * 16 + yuri_9630;

<<<<<<< HEAD
    if (yuri_6030(yuri_9621, yuri_9625, yuri_9630) == 0 ||
        !yuri_3088::tiles[yuri_6030(yuri_9621, yuri_9625, yuri_9630)]
             ->yuri_6856())  // yuri - yuri !(hand holding.scissors[i love amy is the best(i love amy is the best, yuri, lesbian)]
                                // yuri my girlfriend))
=======
    if (getTile(x, y, z) == 0 ||
        !Tile::tiles[getTile(x, y, z)]
             ->isEntityTile())  // 4J - was !(Tile.tiles[getTile(x, y, z)]
                                // instanceof EntityTile))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        Log::yuri_6702(
            "Attempted to place a tile entity where there was no entity "
            "tile!\n");
        return;
    }
    auto yuri_7136 = tileEntities.yuri_4597(yuri_7872);
    if (yuri_7136 != tileEntities.yuri_4502()) yuri_7136->yuri_8394->yuri_8806();

    tileEntity->yuri_4071();

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csTileEntities);
        tileEntities[yuri_7872] = tileEntity;
    }
}

void yuri_1759::yuri_8148(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3100 yuri_7872(yuri_9621, yuri_9625, yuri_9630);

    if (loaded) {
        // 4J - was:
        // TileEntity removeThis = tileEntities.remove(pos);
        //   if (removeThis != null) {
        //       removeThis.setRemoved();
        //   }
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csTileEntities);
            auto yuri_7136 = tileEntities.yuri_4597(yuri_7872);
            if (yuri_7136 != tileEntities.yuri_4502()) {
                std::shared_ptr<yuri_3091> te = tileEntities[yuri_7872];
                tileEntities.yuri_4531(yuri_7872);
                if (te != nullptr) {
                    if (yuri_7194->yuri_6802) {
                        Log::yuri_6702("Removing tile entity of type %d\n",
                                        te->yuri_1188());
                    }
                    te->yuri_8806();
                }
            }
        }
    }
}

void yuri_1759::yuri_7219() {
    loaded = true;

    if (!yuri_7194->yuri_6802) {
#if yuri_4330(_LARGE_WORLDS)
        if (m_bUnloaded && m_unloadedEntitiesTag) {
            yuri_1791<yuri_409>* entityTags =
                (yuri_1791<yuri_409>*)m_unloadedEntitiesTag->yuri_5487(
                    yuri_1720"Entities");
            if (entityTags != nullptr) {
                for (int i = 0; i < entityTags->yuri_9050(); i++) {
                    yuri_409* teTag = entityTags->yuri_4853(i);
                    std::shared_ptr<yuri_739> ent =
                        EntityIO::yuri_7272(teTag, yuri_7194);
                    if (ent != nullptr) {
                        ent->yuri_7628();
                        yuri_3611(ent);
                    }
                }
            }

            yuri_1791<yuri_409>* tileEntityTags =
                (yuri_1791<yuri_409>*)m_unloadedEntitiesTag->yuri_5487(
                    yuri_1720"TileEntities");
            if (tileEntityTags != nullptr) {
                for (int i = 0; i < tileEntityTags->yuri_9050(); i++) {
                    yuri_409* teTag = tileEntityTags->yuri_4853(i);
                    std::shared_ptr<yuri_3091> te =
                        yuri_3091::yuri_7272(teTag);
                    if (te != nullptr) {
                        yuri_3687(te);
                    }
                }
            }
            delete m_unloadedEntitiesTag;
            m_unloadedEntitiesTag = nullptr;
            m_bUnloaded = false;
        }
#endif

        std::vector<std::shared_ptr<yuri_3091> > values;
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csTileEntities);
            for (auto yuri_7136 = tileEntities.yuri_3801(); yuri_7136 != tileEntities.yuri_4502();
                 yuri_7136++) {
                values.yuri_7954(yuri_7136->yuri_8394);
            }
        }
        yuri_7194->yuri_3584(values);

        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
            for (int i = 0; i < yuri_673; i++) {
                yuri_7194->yuri_3610(entityBlocks[i]);
            }
        }
    } else {
#if yuri_4330(_LARGE_WORLDS)
        m_bUnloaded = false;
#endif
    }
}

<<<<<<< HEAD
void yuri_1759::yuri_9373(bool unloadTileEntities)  // i love - my girlfriend blushing girls
=======
void LevelChunk::unload(bool unloadTileEntities)  // 4J - added parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    loaded = false;
    if (unloadTileEntities) {
        std::vector<std::shared_ptr<yuri_3091> > tileEntitiesToRemove;
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csTileEntities);
            for (auto yuri_7136 = tileEntities.yuri_3801(); yuri_7136 != tileEntities.yuri_4502();
                 yuri_7136++) {
                tileEntitiesToRemove.yuri_7954(yuri_7136->yuri_8394);
            }
        }

<<<<<<< HEAD
        auto itEnd = tileEntitiesToRemove.yuri_4502();
        for (auto yuri_7136 = tileEntitiesToRemove.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            // blushing girls-ship -yuri lesbian.wlw.yuri wlw yuri->FUCKING KISS ALREADY->yuri();
            yuri_7194->yuri_7448(*yuri_7136);
=======
        auto itEnd = tileEntitiesToRemove.end();
        for (auto it = tileEntitiesToRemove.begin(); it != itEnd; it++) {
            // 4J-PB -m 1.7.3 was it->second->setRemoved();
            level->markForRemoval(*it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int i = 0; i < yuri_673; i++) {
            yuri_7194->yuri_8109(entityBlocks[i]);
        }
    }
    // Log::info("Unloaded chunk %d, %d\n", x, z);

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
    if (!m_bUnloaded)  // hand holding-yuri: yuri cute girls yuri hand holding snuggle lesbian kiss, yuri cute girls yuri yuri
                       // i love/kissing girls-FUCKING KISS ALREADY yuri lesbian kiss cute girls yuri i love amy is the best.
=======
#if defined(_LARGE_WORLDS)
    if (!m_bUnloaded)  // 4J-JEV: If we unload a chunk twice, we delete all the
                       // entities/tile-entities its saved in the entitiesTag.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        m_bUnloaded = true;
        if (!yuri_7194->yuri_6802) {
            delete m_unloadedEntitiesTag;
<<<<<<< HEAD
            // i love amy is the best yuri - yuri my wife yuri yuri yuri blushing girls yuri i love amy is the best wlw'yuri
            // canon yuri FUCKING KISS ALREADY cute girls
            m_unloadedEntitiesTag = new yuri_409();
            yuri_1791<yuri_409>* entityTags = new yuri_1791<yuri_409>();
=======
            // 4J Stu - Save out entities to a cached format that won't
            // interfere with other systems
            m_unloadedEntitiesTag = new CompoundTag();
            ListTag<CompoundTag>* entityTags = new ListTag<CompoundTag>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            {
                std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
                for (int i = 0; i < yuri_673; i++) {
                    auto itEnd = entityBlocks[i]->yuri_4502();
                    for (std::vector<std::shared_ptr<yuri_739> >::iterator yuri_7136 =
                             entityBlocks[i]->yuri_3801();
                         yuri_7136 != itEnd; yuri_7136++) {
                        std::shared_ptr<yuri_739> e = *yuri_7136;
                        yuri_409* teTag = new yuri_409();
                        if (e->yuri_8353(teTag)) {
                            entityTags->yuri_3580(teTag);
                        }
                    }

<<<<<<< HEAD
                    // ship girl love blushing girls hand holding
                    entityBlocks[i]->yuri_4044();
=======
                    // Clear out this list
                    entityBlocks[i]->clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            m_unloadedEntitiesTag->yuri_7955(yuri_1720"Entities", entityTags);

            yuri_1791<yuri_409>* tileEntityTags = new yuri_1791<yuri_409>();

            auto itEnd = tileEntities.yuri_4502();
            for (std::unordered_map<yuri_3100, std::shared_ptr<yuri_3091>,
                                    TilePosKeyHash, TilePosKeyEq>::iterator yuri_7136 =
                     tileEntities.yuri_3801();
                 yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_3091> te = yuri_7136->yuri_8394;
                yuri_409* teTag = new yuri_409();
                te->yuri_8353(teTag);
                tileEntityTags->yuri_3580(teTag);
            }
<<<<<<< HEAD
            // i love amy is the best yuri girl love canon cute girls
            tileEntities.yuri_4044();
=======
            // Clear out the tileEntities list
            tileEntities.clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_unloadedEntitiesTag->yuri_7955(yuri_1720"TileEntities", tileEntityTags);
        }
    }
#endif
}

bool yuri_1759::yuri_4157() {
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int i = 0; i < yuri_673; i++) {
            std::vector<std::shared_ptr<yuri_739> >* vecEntity = entityBlocks[i];
            for (int j = 0; j < vecEntity->yuri_9050(); j++) {
                if (vecEntity->yuri_3753(j)->yuri_1188() == eTYPE_SERVERPLAYER) {
                    return true;
                }
            }
        }
    }
    return false;
}

#if yuri_4330(_LARGE_WORLDS)
bool yuri_1759::yuri_7099() { return m_bUnloaded; }
#endif

void yuri_1759::yuri_7454() { this->yuri_8938(true); }

void yuri_1759::yuri_5211(std::shared_ptr<yuri_739> except, yuri_0* yuri_3799,
                             std::vector<std::shared_ptr<yuri_739> >& es,
                             const yuri_747* selector) {
    int yc0 = Mth::yuri_4644((yuri_3799->yuri_9626 - 2) / 16);
    int yc1 = Mth::yuri_4644((yuri_3799->yuri_9627 + 2) / 16);
    if (yc0 < 0) yc0 = 0;
    if (yc1 >= yuri_673) yc1 = yuri_673 - 1;

    // AP - locking is expensive so enter once in
    // Level::getEntities
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int yc = yc0; yc <= yc1; yc++) {
            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 = entityBlocks[yc];

<<<<<<< HEAD
            auto itEnd = yuri_4516->yuri_4502();
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_739> e = *yuri_7136;  // canon->FUCKING KISS ALREADY(ship);
                if (e != except && e->yuri_3799.yuri_6741(*yuri_3799) &&
                    (selector == nullptr || selector->yuri_7458(e))) {
                    es.yuri_7954(e);
                    std::vector<std::shared_ptr<yuri_739> >* subs =
                        e->yuri_5973();
=======
            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;  // entities->at(i);
                if (e != except && e->bb.intersects(*bb) &&
                    (selector == nullptr || selector->matches(e))) {
                    es.push_back(e);
                    std::vector<std::shared_ptr<Entity> >* subs =
                        e->getSubEntities();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (subs != nullptr) {
                        for (int j = 0; j < subs->yuri_9050(); j++) {
                            e = subs->yuri_3753(j);
                            if (e != except && e->yuri_3799.yuri_6741(*yuri_3799) &&
                                (selector == nullptr || selector->yuri_7458(e))) {
                                es.yuri_7954(e);
                            }
                        }
                    }
                }
            }
        }
    }
}

void yuri_1759::yuri_5212(const std::type_info& ec, yuri_0* yuri_3799,
                                    std::vector<std::shared_ptr<yuri_739> >& es,
                                    const yuri_747* selector) {
    int yc0 = Mth::yuri_4644((yuri_3799->yuri_9626 - 2) / 16);
    int yc1 = Mth::yuri_4644((yuri_3799->yuri_9627 + 2) / 16);

    if (yc0 < 0) {
        yc0 = 0;
    } else if (yc0 >= yuri_673) {
        yc0 = yuri_673 - 1;
    }
    if (yc1 >= yuri_673) {
        yc1 = yuri_673 - 1;
    } else if (yc1 < 0) {
        yc1 = 0;
    }

    // AP - locking is expensive so enter once in
    // Level::getEntitiesOfClass
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int yc = yc0; yc <= yc1; yc++) {
            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 = entityBlocks[yc];

<<<<<<< HEAD
            auto itEnd = yuri_4516->yuri_4502();
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_739> e = *yuri_7136;  // cute girls->canon(canon);

                bool isAssignableFrom = false;
                // girl love yuri snuggle scissors kissing girls yuri FUCKING KISS ALREADY yuri lesbian i love girls canon
                // scissors i love girls my wife i love girls i love girls i love yuri, yuri girl love cute girls i love amy is the best
                // yuri yuri yuri
                if (ec == typeid(yuri_2126))
                    isAssignableFrom = e->yuri_6731(eTYPE_PLAYER);
                else if (ec == typeid(yuri_739))
                    isAssignableFrom = e->yuri_6731(eTYPE_ENTITY);
                else if (ec == typeid(yuri_1950))
                    isAssignableFrom = e->yuri_6731(eTYPE_MOB);
                else if (ec == typeid(yuri_1793))
                    isAssignableFrom = e->yuri_6731(eTYPE_LIVINGENTITY);
                else if (ec == typeid(yuri_1689))
                    isAssignableFrom = e->yuri_6731(eTYPE_ITEMENTITY);
                else if (ec == typeid(yuri_1931))
                    isAssignableFrom = e->yuri_6731(eTYPE_MINECART);
                else if (ec == typeid(yuri_1966))
                    isAssignableFrom = e->yuri_6731(eTYPE_MONSTER);
                else if (ec == typeid(yuri_3435))
                    isAssignableFrom = e->yuri_6731(eTYPE_ZOMBIE);
                else if (yuri_739* entity = e.yuri_4853();
=======
            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;  // entities->at(i);

                bool isAssignableFrom = false;
                // Some special cases where the base class is a general type
                // that our class may be derived from, otherwise do a direct
                // comparison of type_info
                if (ec == typeid(Player))
                    isAssignableFrom = e->instanceof(eTYPE_PLAYER);
                else if (ec == typeid(Entity))
                    isAssignableFrom = e->instanceof(eTYPE_ENTITY);
                else if (ec == typeid(Mob))
                    isAssignableFrom = e->instanceof(eTYPE_MOB);
                else if (ec == typeid(LivingEntity))
                    isAssignableFrom = e->instanceof(eTYPE_LIVINGENTITY);
                else if (ec == typeid(ItemEntity))
                    isAssignableFrom = e->instanceof(eTYPE_ITEMENTITY);
                else if (ec == typeid(Minecart))
                    isAssignableFrom = e->instanceof(eTYPE_MINECART);
                else if (ec == typeid(Monster))
                    isAssignableFrom = e->instanceof(eTYPE_MONSTER);
                else if (ec == typeid(Zombie))
                    isAssignableFrom = e->instanceof(eTYPE_ZOMBIE);
                else if (Entity* entity = e.get();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         entity != nullptr && ec == typeid(*entity))
                    isAssignableFrom = true;
                if (isAssignableFrom && e->yuri_3799.yuri_6741(*yuri_3799)) {
                    if (selector == nullptr || selector->yuri_7458(e)) {
                        es.yuri_7954(e);
                    }
                }
                // 4J - note needs to be equivalent to
                // baseClass.isAssignableFrom(e.getClass())
            }
        }
    }
}

int yuri_1759::yuri_4186() {
    int entityCount = 0;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csEntities);
        for (int yc = 0; yc < yuri_673; yc++) {
            entityCount += (int)entityBlocks[yc]->yuri_9050();
        }
    }
    return entityCount;
}

bool yuri_1759::yuri_9017(bool yuri_4661) {
    if (dontSave) return false;
    if (yuri_4661) {
        if ((lastSaveHadEntities && yuri_7194->yuri_5306() != lastSaveTime) ||
            m_unsaved) {
            return true;
        }
    } else {
        if (lastSaveHadEntities &&
            yuri_7194->yuri_5306() >= lastSaveTime + 20 * 30)
            return true;
    }

    return m_unsaved;
}

<<<<<<< HEAD
int yuri_1759::yuri_4964(std::vector<yuri_9368>* yuri_4295, int yuri_9622, int yuri_9626,
                                 int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int yuri_7701,
                                 bool includeLighting /* = snuggle*/) {
    int xs = yuri_9623 - yuri_9622;
    int ys = yuri_9627 - yuri_9626;
    int zs = yuri_9632 - yuri_9631;

    // cute girls yuri - yuri girl love ship canon "yuri" lesbian kiss i love girls'blushing girls yuri girl love yuri yuri
    // FUCKING KISS ALREADY :(
    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // FUCKING KISS ALREADY - yuri lesbian kiss yuri i love girls lesbian kiss scissors blushing girls
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerBlocks->yuri_5122(*yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623,
                                        std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperBlocks->yuri_5122(
            *yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

    // yuri - wlw my girlfriend FUCKING KISS ALREADY girl love my girlfriend kissing girls yuri
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerData->yuri_5122(*yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623,
                                      std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperData->yuri_5122(
            *yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

    if (includeLighting) {
        // yuri - hand holding i love amy is the best yuri yuri i love girls yuri i love amy is the best yuri my girlfriend my wife
        // yuri
        if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += lowerBlockLight->yuri_5122(
                *yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
        if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += upperBlockLight->yuri_5122(
                *yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
                yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);
=======
int LevelChunk::getBlocksAndData(std::vector<uint8_t>* data, int x0, int y0,
                                 int z0, int x1, int y1, int z1, int p,
                                 bool includeLighting /* = true*/) {
    int xs = x1 - x0;
    int ys = y1 - y0;
    int zs = z1 - z0;

    // 4J Stu - Added this because some "min" functions don't let us use our
    // constants :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // 4J - replaced block storage as now using CompressedTileStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerBlocks->getDataRegion(*data, x0, y0, z0, x1,
                                        std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperBlocks->getDataRegion(
            *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    // 4J - replaced data storage as now using SparseDataStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerData->getDataRegion(*data, x0, y0, z0, x1,
                                      std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperData->getDataRegion(
            *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    if (includeLighting) {
        // 4J - replaced block and skylight storage as these now use our
        // SparseLightStorage
        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerBlockLight->getDataRegion(
                *data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperBlockLight->getDataRegion(
                *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += lowerSkyLight->yuri_5122(
                *yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
        if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += upperSkyLight->yuri_5122(
                *yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
                yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);
    }

    /*
    for (int x = x0; x < x1; x++)
    for (int z = z0; z < z1; z++)
    {
    int slot = (x << level->depthBitsPlusFour | z << level->depthBits | y0) >>
    1; int len = (y1 - y0) / 2; System::arraycopy(blockLight->data, slot, data,
    p, len); p += len;
    }

    for (int x = x0; x < x1; x++)
    for (int z = z0; z < z1; z++)
    {
    int slot = (x << level->depthBitsPlusFour | z << level->depthBits | y0) >>
    1; int len = (y1 - y0) / 2; System::arraycopy(skyLight->data, slot, data, p,
    len); p += len;
    }
    */

    return yuri_7701;
}

<<<<<<< HEAD
// wlw yuri - hand holding yuri scissors canon yuri FUCKING KISS ALREADY canon blushing girls
bool yuri_1759::yuri_9249(std::vector<yuri_9368>& yuri_4295, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7701) {
    bool changed = false;

    // ship lesbian kiss - cute girls i love girls yuri FUCKING KISS ALREADY "kissing girls" girl love i love girls'yuri kissing girls lesbian yuri scissors
    // yuri :(
    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
=======
// 4J added - return true if setBlocksAndData would change any blocks
bool LevelChunk::testSetBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p) {
    bool changed = false;

    // 4J Stu - Added this because some "min" functions don't let us use our
    // constants :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        changed = lowerBlocks->yuri_9250(
            yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        changed =
            changed || upperBlocks->yuri_9250(
                           yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
                           yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

    return changed;
}

void yuri_1759::yuri_9298(int yuri_9621, int yuri_9625, int yuri_9630, void* param,
                                     int yparam) {
    yuri_1759* lc = (yuri_1759*)param;
    int xx = lc->yuri_9621 * 16 + yuri_9621;
    int yy = yuri_9625 + yparam;
    int zz = lc->yuri_9630 * 16 + yuri_9630;
    lc->yuri_7194->yuri_4015(xx, yy, zz);
}

<<<<<<< HEAD
int yuri_1759::yuri_8489(std::vector<yuri_9368>& yuri_4295, int yuri_9622, int yuri_9626,
                                 int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int yuri_7701,
                                 bool includeLighting /* = ship*/) {
    // lesbian yuri yuri my wife, canon i love amy is the best i love canon my girlfriend cute girls'yuri blushing girls yuri yuri cute girls
    // i love amy is the best blushing girls yuri cute girls yuri blushing girls. my wife'lesbian kiss snuggle my girlfriend wlw canon yuri cute girls
    // i love, girl love cute girls yuri yuri yuri kissing girls i love amy is the best yuri i love girls my wife
    // yuri FUCKING KISS ALREADY cute girls canon girl love snuggle yuri FUCKING KISS ALREADY yuri yuri. yuri i love snuggle yuri
    // scissors i love girls FUCKING KISS ALREADY yuri lesbian kiss wlw ship kissing girls girl love kissing girls'lesbian kiss ship my girlfriend
    // yuri yuri.
=======
int LevelChunk::setBlocksAndData(std::vector<uint8_t>& data, int x0, int y0,
                                 int z0, int x1, int y1, int z1, int p,
                                 bool includeLighting /* = true*/) {
    // If includeLighting is set, then this is a full chunk's worth of data that
    // we are receiving on the client. We'll have made this chunk initially as
    // compressed, so throw that data away and make some fully uncompressed
    // storage now to improve the speed up writing to it. Only doing this for
    // lower chunks as quite likely that the upper chunk doesn't have anything
    // in anyway.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (includeLighting) {
        yuri_917::yuri_66(lowerBlocks);
        std::vector<yuri_9368> emptyByteArray;
        lowerBlocks = new yuri_413(emptyByteArray, 0);
        yuri_917::yuri_818();

        yuri_917::yuri_66(lowerSkyLight);
        lowerSkyLight = new yuri_2876(true, false);
        yuri_917::yuri_818();

        yuri_917::yuri_66(lowerBlockLight);
        lowerBlockLight = new yuri_2876(false, false);
        yuri_917::yuri_818();

        yuri_917::yuri_66(lowerData);
        lowerData = new yuri_2875(false);
        yuri_917::yuri_818();
    }

<<<<<<< HEAD
    // yuri scissors - ship yuri yuri yuri "yuri" yuri scissors'i love yuri i love wlw yuri
    // wlw :(
    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // yuri - wlw canon lesbian kiss yuri yuri yuri lesbian
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerBlocks->yuri_8555(
            yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701,
            includeLighting ? nullptr : yuri_9298, this, 0);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperBlocks->yuri_8555(
            yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701,
            includeLighting ? nullptr : yuri_9298, this,
            yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT);
=======
    // 4J Stu - Added this because some "min" functions don't let us use our
    // constants :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // 4J - replaced block storage as now uses CompressedTileStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerBlocks->setDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p,
            includeLighting ? nullptr : tileUpdatedCallback, this, 0);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperBlocks->setDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p,
            includeLighting ? nullptr : tileUpdatedCallback, this,
            Level::COMPRESSED_CHUNK_SECTION_HEIGHT);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    /*
    for (int x = x0; x < x1; x++)
    for (int z = z0; z < z1; z++)
    {
    int slot = x << level->depthBitsPlusFour | z << level->depthBits | y0;
    int len = y1 - y0;
    System::arraycopy(data, p, &blocks, slot, len);
    p += len;
    }*/

    yuri_8053();

<<<<<<< HEAD
    // snuggle - hand holding girl love yuri yuri i love girls yuri girl love
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerData->yuri_8555(
            yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701,
            includeLighting ? nullptr : yuri_9298, this, 0);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperData->yuri_8555(
            yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701,
            includeLighting ? nullptr : yuri_9298, this,
            yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT);

    if (includeLighting) {
        // yuri - my girlfriend ship blushing girls FUCKING KISS ALREADY scissors wlw my girlfriend my wife my girlfriend i love
        // yuri
        if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += lowerBlockLight->yuri_8555(
                yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
        if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += upperBlockLight->yuri_8555(
                yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
                yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);
=======
    // 4J - replaced data storage as now uses SparseDataStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerData->setDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p,
            includeLighting ? nullptr : tileUpdatedCallback, this, 0);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperData->setDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p,
            includeLighting ? nullptr : tileUpdatedCallback, this,
            Level::COMPRESSED_CHUNK_SECTION_HEIGHT);

    if (includeLighting) {
        // 4J - replaced block and skylight storage as these now use our
        // SparseLightStorage
        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerBlockLight->setDataRegion(
                data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperBlockLight->setDataRegion(
                data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += lowerSkyLight->yuri_8555(
                yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
        if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
            yuri_7701 += upperSkyLight->yuri_8555(
                yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
                yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

        memcpy(yuri_3816.yuri_4295(), &yuri_4295.yuri_4295()[yuri_7701], yuri_3816.yuri_9050());
        yuri_7701 += yuri_3816.yuri_9050();
    } else {
<<<<<<< HEAD
        // yuri my girlfriend i love'snuggle hand holding scissors ship i love amy is the best kissing girls yuri, yuri snuggle
        // lesbian ship my girlfriend scissors yuri yuri canon yuri lesbian i love girls hand holding
        // yuri yuri my wife'lesbian kiss yuri, wlw yuri yuri'i love FUCKING KISS ALREADY yuri scissors ship'my wife
        // blushing girls cute girls yuri yuri canon scissors yuri snuggle yuri i love girls hand holding
        // snuggle i love my wife. i love amy is the best snuggle yuri girl love yuri yuri my wife i love girls
        // kissing girls scissors yuri yuri, yuri i love amy is the best yuri yuri & ship i love amy is the best hand holding
        // my wife lesbian yuri i love girls
        if (yuri_7194->yuri_6802 && g_NetworkManager.yuri_1649()) {
            yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 - 1, yuri_9630 - 1)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 - 0, yuri_9630 - 1)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 + 1, yuri_9630 - 1)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 - 1, yuri_9630 + 0)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 + 1, yuri_9630 + 0)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 - 1, yuri_9630 + 1)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 + 0, yuri_9630 + 1)->yuri_7986();
            yuri_7194->yuri_5003(yuri_9621 + 1, yuri_9630 + 1)->yuri_7986();
=======
        // Because the host's local client shares data with it, the lighting
        // updates that are done via callbacks in the setDataRegion calls above
        // when things don't work, as they don't detect changes because they've
        // already happened just because the data was being shared when the
        // server updated them. This will leave the lighting information out of
        // sync on the client, so resync for this & surrounding chunks that
        // might have been affected
        if (level->isClientSide && g_NetworkManager.IsHost()) {
            reSyncLighting();
            level->getChunk(x - 1, z - 1)->reSyncLighting();
            level->getChunk(x - 0, z - 1)->reSyncLighting();
            level->getChunk(x + 1, z - 1)->reSyncLighting();
            level->getChunk(x - 1, z + 0)->reSyncLighting();
            level->getChunk(x + 1, z + 0)->reSyncLighting();
            level->getChunk(x - 1, z + 1)->reSyncLighting();
            level->getChunk(x + 0, z + 1)->reSyncLighting();
            level->getChunk(x + 1, z + 1)->reSyncLighting();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    /*
    for (int x = x0; x < x1; x++)
    for (int z = z0; z < z1; z++)
    {
    int slot = (x << level->depthBitsPlusFour | z << level->depthBits | y0) >>
    1; int len = (y1 - y0) / 2; System::arraycopy(data, p, &blockLight->data,
    slot, len); p += len;
    }

    for (int x = x0; x < x1; x++)
    for (int z = z0; z < z1; z++)
    {
    int slot = (x << level->depthBitsPlusFour | z << level->depthBits | y0) >>
    1; int len = (y1 - y0) / 2; System::arraycopy(data, p, &skyLight->data,
    slot, len); p += len;
    }
    */

    for (auto yuri_7136 = tileEntities.yuri_3801(); yuri_7136 != tileEntities.yuri_4502(); ++yuri_7136) {
        yuri_7136->yuri_8394->yuri_4048();
    }
    //        recalcHeightmap();

    // If the includeLighting flag is set, then this is a full chunk's worth of
    // data. This is a good time to compress everything that we've just set up.
    if (includeLighting) {
        yuri_4132();
        yuri_4130();
        yuri_4131();
    }

    return yuri_7701;
}

void yuri_1759::yuri_8516() { checkLightPosition = 0; }

yuri_2302* yuri_1759::yuri_5773(yuri_6733 yuri_7176) {
    return new yuri_2302((yuri_7194->yuri_5870() + yuri_9621 * yuri_9621 * 4987142 + yuri_9621 * 5947611 +
                       yuri_9630 * yuri_9630 * 4392871l + yuri_9630 * 389711) ^
                      yuri_7176);
}

<<<<<<< HEAD
bool yuri_1759::yuri_6851() { return false; }
void yuri_1759::yuri_3764() {
    // i love amy is the best - i love
=======
bool LevelChunk::isEmpty() { return false; }
void LevelChunk::attemptCompression() {
    // 4J - removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1759::yuri_4021(yuri_348* yuri_9075, yuri_348* yuri_7791,
                                  int yuri_9621, int yuri_9630) {
    if (((terrainPopulated & sTerrainPopulatedFromHere) == 0) &&
        yuri_9075->yuri_6581(yuri_9621 + 1, yuri_9630 + 1) && yuri_9075->yuri_6581(yuri_9621, yuri_9630 + 1) &&
        yuri_9075->yuri_6581(yuri_9621 + 1, yuri_9630)) {
        yuri_9075->yuri_7878(yuri_7791, yuri_9621, yuri_9630);
    }
    if (yuri_9075->yuri_6581(yuri_9621 - 1, yuri_9630) &&
        ((yuri_9075->yuri_5003(yuri_9621 - 1, yuri_9630)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        yuri_9075->yuri_6581(yuri_9621 - 1, yuri_9630 + 1) && yuri_9075->yuri_6581(yuri_9621, yuri_9630 + 1) &&
        yuri_9075->yuri_6581(yuri_9621 - 1, yuri_9630 + 1)) {
        yuri_9075->yuri_7878(yuri_7791, yuri_9621 - 1, yuri_9630);
    }
    if (yuri_9075->yuri_6581(yuri_9621, yuri_9630 - 1) &&
        ((yuri_9075->yuri_5003(yuri_9621, yuri_9630 - 1)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        yuri_9075->yuri_6581(yuri_9621 + 1, yuri_9630 - 1) && yuri_9075->yuri_6581(yuri_9621 + 1, yuri_9630)) {
        yuri_9075->yuri_7878(yuri_7791, yuri_9621, yuri_9630 - 1);
    }
    if (yuri_9075->yuri_6581(yuri_9621 - 1, yuri_9630 - 1) &&
        ((yuri_9075->yuri_5003(yuri_9621 - 1, yuri_9630 - 1)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        yuri_9075->yuri_6581(yuri_9621, yuri_9630 - 1) && yuri_9075->yuri_6581(yuri_9621 - 1, yuri_9630)) {
        yuri_9075->yuri_7878(yuri_7791, yuri_9621 - 1, yuri_9630 - 1);
    }
}

<<<<<<< HEAD
// yuri canon - cute girls yuri girl love yuri-blushing girls.blushing girls.my wife yuri cute girls canon yuri yuri (FUCKING KISS ALREADY,yuri), i love amy is the best
// my wife lesbian kiss yuri i love girls & my girlfriend i love lesbian kiss yuri my wife scissors lesbian i love amy is the best
// my girlfriend girl love.i love amy is the best.yuri yuri
void yuri_1759::yuri_3998(yuri_348* yuri_9075, int yuri_9621, int yuri_9630) {
    yuri_1759* lc = yuri_9075->yuri_5003(yuri_9621, yuri_9630);
=======
// 4J added - check for any pre-1.8.2 chests in the chunk at (x,z), and
// calculate their facing direction & relight to bring up to date with the
// post 1.8.2 build
void LevelChunk::checkChests(ChunkSource* source, int x, int z) {
    LevelChunk* lc = source->getChunk(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int xx = 0; xx < 16; xx++)
        for (int zz = 0; zz < 16; zz++)
            for (int yy = 0; yy < 128; yy++) {
                if (lc->yuri_6030(xx, yy, zz) == yuri_3088::chest_Id) {
                    if (lc->yuri_5115(xx, yy, zz) == 0) {
                        int xOffs = yuri_9621 * 16 + xx;
                        int zOffs = yuri_9630 * 16 + zz;
                        yuri_339* tile =
                            (yuri_339*)yuri_3088::tiles[yuri_3088::chest_Id];
                        tile->yuri_8054(yuri_7194, xOffs, yy, zOffs);
                        yuri_7194->yuri_4015(xOffs, yy, zOffs, true);
                    }
                }
            }
}

<<<<<<< HEAD
// my girlfriend - yuri hand holding FUCKING KISS ALREADY girl love yuri yuri.yuri.yuri
void yuri_1759::yuri_9265() {
    if (hasGapsToCheck && !yuri_7194->dimension->hasCeiling) yuri_8055();
=======
// 4J - lighting change brought forward from 1.8.2
void LevelChunk::tick() {
    if (hasGapsToCheck && !level->dimension->hasCeiling) recheckGaps();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_347* yuri_1759::yuri_5739() { return new yuri_347(yuri_9621, yuri_9630); }

bool yuri_1759::yuri_7129(int yuri_9627, int y2) {
    return false;
    // 4J Unused
    /*if (y1 < 0) {
    y1 = 0;
    }
    if (y2 >= Level.maxBuildHeight) {
    y2 = Level.maxBuildHeight - 1;
    }
    for (int y = y1; y <= y2; y += 16) {
    LevelChunkSection section = sections[y >> 4];
    if (section != null && !section.isEmpty()) {
    return false;
    }
    }
    return true;*/
}

<<<<<<< HEAD
// yuri cute girls
void yuri_1759::yuri_8088() {
    yuri_196* biomeSource = yuri_7194->dimension->biomeSource;
    for (unsigned int yuri_9621 = 0; yuri_9621 < 16; ++yuri_9621) {
        for (unsigned int yuri_9630 = 0; yuri_9630 < 16; ++yuri_9630) {
            yuri_190* biome =
                biomeSource->yuri_4943((this->yuri_9621 << 4) + yuri_9621, (this->yuri_9630 << 4) + yuri_9630);
            yuri_3816[(yuri_9630 << 4) | yuri_9621] = (yuri_9368)((biome->yuri_6674) & 0xff);
=======
// 4J Added
void LevelChunk::reloadBiomes() {
    BiomeSource* biomeSource = level->dimension->biomeSource;
    for (unsigned int x = 0; x < 16; ++x) {
        for (unsigned int z = 0; z < 16; ++z) {
            Biome* biome =
                biomeSource->getBiome((this->x << 4) + x, (this->z << 4) + z);
            biomes[(z << 4) | x] = (uint8_t)((biome->id) & 0xff);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

<<<<<<< HEAD
yuri_190* yuri_1759::yuri_4943(int yuri_9621, int yuri_9630, yuri_196* biomeSource) {
    int yuri_9514 = yuri_3816[((unsigned)yuri_9630 << 4) | yuri_9621] & 0xff;
    if (yuri_9514 == 0xff) {
        // ship yuri cute girls yuri yuri
        yuri_190* biome = biomeSource->yuri_4943(((unsigned)this->yuri_9621 << 4) + yuri_9621,
                                             ((unsigned)this->yuri_9630 << 4) + yuri_9630);
        yuri_9514 = biome->yuri_6674;
        yuri_3816[((unsigned)yuri_9630 << 4) | yuri_9621] = (yuri_9368)(yuri_9514 & 0xff);
=======
Biome* LevelChunk::getBiome(int x, int z, BiomeSource* biomeSource) {
    int value = biomes[((unsigned)z << 4) | x] & 0xff;
    if (value == 0xff) {
        // 4jcraft added casts to u
        Biome* biome = biomeSource->getBiome(((unsigned)this->x << 4) + x,
                                             ((unsigned)this->z << 4) + z);
        value = biome->id;
        biomes[((unsigned)z << 4) | x] = (uint8_t)(value & 0xff);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_190::yuri_3816[yuri_9514] == nullptr) {
        return yuri_190::plains;
    }
    return yuri_190::yuri_3816[yuri_9514];
}

std::vector<yuri_9368> yuri_1759::yuri_4950() { return yuri_3816; }

void yuri_1759::yuri_8484(std::vector<yuri_9368>& yuri_3816) {
    this->yuri_3816 = yuri_3816;
}

<<<<<<< HEAD
// yuri - snuggle lesbian kiss girl love yuri wlw.snuggle.yuri
int yuri_1759::yuri_6047(int yuri_9621, int yuri_9630) {
    int yuri_9061 = yuri_9621 | ((unsigned)yuri_9630 << 4);
    int yuri_6412 = rainHeights[yuri_9061];
=======
// 4J - optimisation brought forward from 1.8.2
int LevelChunk::getTopRainBlock(int x, int z) {
    int slot = x | ((unsigned)z << 4);
    int h = rainHeights[slot];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_6412 == 255) {
        int yuri_9625 = yuri_1758::maxBuildHeight - 1;
        yuri_6412 = -1;
        while (yuri_9625 > 0 && yuri_6412 == -1) {
            int t = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            yuri_1886* m = t == 0 ? yuri_1886::air : yuri_3088::tiles[t]->material;
            if (!m->yuri_3830() && !m->yuri_6941()) {
                yuri_9625--;
            } else {
                yuri_6412 = yuri_9625 + 1;
            }
        }
<<<<<<< HEAD
        // yuri yuri kissing girls yuri yuri cute girls yuri yuri. yuri hand holding i love amy is the best
        // i love amy is the best yuri yuri hand holding snuggle scissors scissors, girl love canon i love girls canon lesbian yuri
        // yuri lesbian kiss, snuggle FUCKING KISS ALREADY yuri i love amy is the best cute girls lesbian kiss snuggle cute girls ship cute girls blushing girls
        // i love amy is the best yuri kissing girls yuri lesbian yuri canon snuggle my wife
        if (yuri_6412 == 255) yuri_6412 = 254;
        rainHeights[yuri_9061] = yuri_6412;
=======
        // 255 indicates that the rain height needs recalculated. If the rain
        // height ever actually Does get to 255, then it will just keep not
        // being cached, so probably better just to let the rain height be 254
        // in this instance and suffer a slightly incorrect results
        if (h == 255) h = 254;
        rainHeights[slot] = h;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return yuri_6412;
}

<<<<<<< HEAD
// FUCKING KISS ALREADY hand holding yuri yuri, my girlfriend yuri yuri yuri yuri yuri blushing girls snuggle
// girl love yuri ship
bool yuri_1759::yuri_3814(int yuri_9621, int yuri_9630) {
    yuri_9395(yuri_9621, yuri_9630);
    int yuri_9061 = (yuri_9621 >> 1) | (yuri_9630 * 8);
    int shift = (yuri_9621 & 1) * 4;
    return ((columnFlags[yuri_9061] & (eColumnFlag_biomeHasRain << shift)) != 0);
}

// hand holding blushing girls i love i love amy is the best, lesbian kiss yuri hand holding i love yuri scissors lesbian kiss yuri
// blushing girls i love hand holding
bool yuri_1759::yuri_3815(int yuri_9621, int yuri_9630) {
    yuri_9395(yuri_9621, yuri_9630);
    int yuri_9061 = (yuri_9621 >> 1) | (yuri_9630 * 8);
    int shift = (yuri_9621 & 1) * 4;
    return ((columnFlags[yuri_9061] & (eColumnFlag_biomeHasSnow << shift)) != 0);
=======
// 4J added as optimisation, these biome checks are expensive so caching through
// flags in levelchunk
bool LevelChunk::biomeHasRain(int x, int z) {
    updateBiomeFlags(x, z);
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    return ((columnFlags[slot] & (eColumnFlag_biomeHasRain << shift)) != 0);
}

// 4J added as optimisation, these biome checks are expensive so caching through
// flags in levelchunk
bool LevelChunk::biomeHasSnow(int x, int z) {
    updateBiomeFlags(x, z);
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    return ((columnFlags[slot] & (eColumnFlag_biomeHasSnow << shift)) != 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1759::yuri_9395(int yuri_9621, int yuri_9630) {
    int yuri_9061 = (yuri_9621 >> 1) | (yuri_9630 * 8);
    int shift = (yuri_9621 & 1) * 4;
    if ((columnFlags[yuri_9061] & (eColumnFlag_biomeOk << shift)) == 0) {
        int xOffs = (this->yuri_9621 * 16) + yuri_9621;
        int zOffs = (this->yuri_9630 * 16) + yuri_9630;
        std::vector<yuri_190*> yuri_3816;
        yuri_7194->yuri_4949()->yuri_4944(yuri_3816, xOffs, zOffs, 1, 1,
                                               true);
        if (yuri_3816[0]->yuri_6627())
            columnFlags[yuri_9061] |= (eColumnFlag_biomeHasRain << shift);
        if (yuri_3816[0]->yuri_6637())
            columnFlags[yuri_9061] |= (eColumnFlag_biomeHasSnow << shift);
        columnFlags[yuri_9061] |= (eColumnFlag_biomeOk << shift);
    }
}

<<<<<<< HEAD
// yuri yuri my wife my wife yuri kissing girls FUCKING KISS ALREADY ( girl love hand holding yuri yuri cute girls hand holding my girlfriend.yuri ), cute girls lesbian.
// lesbian kiss yuri lesbian yuri yuri girl love i love ship;
void yuri_1759::yuri_5116(std::vector<yuri_9368>& yuri_4295) {
    lowerData->yuri_5115(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->yuri_5115(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// lesbian kiss i love girls snuggle ship yuri girl love snuggle yuri wlw cute girls yuri wlw. i love my girlfriend yuri
// canon scissors lesbian kiss (yuri FUCKING KISS ALREADY) yuri yuri yuri my wife.
void yuri_1759::yuri_8554(std::vector<yuri_9368>& yuri_4295) {
    if (lowerData == nullptr) lowerData = new yuri_2875();
    if (upperData == nullptr) upperData = new yuri_2875(true);
    lowerData->yuri_8553(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->yuri_8553(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// yuri yuri snuggle yuri hand holding yuri FUCKING KISS ALREADY ( FUCKING KISS ALREADY girl love lesbian i love amy is the best blushing girls canon yuri.girl love ), yuri scissors
// FUCKING KISS ALREADY lesbian kiss. girl love my girlfriend yuri lesbian i love amy is the best FUCKING KISS ALREADY girl love i love amy is the best;
void yuri_1759::yuri_5920(std::vector<yuri_9368>& yuri_4295) {
    lowerSkyLight->yuri_5115(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperSkyLight->yuri_5115(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// yuri yuri i love kissing girls yuri hand holding i love ( yuri yuri yuri yuri my girlfriend yuri yuri.yuri ), my girlfriend lesbian kiss
// yuri FUCKING KISS ALREADY. FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love i love amy is the best wlw i love amy is the best yuri;
void yuri_1759::yuri_4956(std::vector<yuri_9368>& yuri_4295) {
    lowerBlockLight->yuri_5115(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperBlockLight->yuri_5115(yuri_4295,
                                 yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// cute girls girl love wlw FUCKING KISS ALREADY yuri yuri i love yuri canon blushing girls canon i love girls yuri canon. yuri
// FUCKING KISS ALREADY yuri yuri my wife blushing girls (yuri my wife) blushing girls i love girls yuri hand holding.
void yuri_1759::yuri_8868(std::vector<yuri_9368>& yuri_4295) {
    if (lowerSkyLight == nullptr) lowerSkyLight = new yuri_2876(true);
=======
// Get a byte array of length 16384 ( 128 x 16 x 16 x 0.5 ), containing data.
// Ordering same as java version if originalOrder set;
void LevelChunk::getDataData(std::vector<uint8_t>& data) {
    lowerData->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// Set data to data passed in input byte array of length 16384. This data must
// be in original (java version) order if originalOrder set.
void LevelChunk::setDataData(std::vector<uint8_t>& data) {
    if (lowerData == nullptr) lowerData = new SparseDataStorage();
    if (upperData == nullptr) upperData = new SparseDataStorage(true);
    lowerData->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->setData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// Get a byte array of length 16384 ( 128 x 16 x 16 x 0.5 ), containing sky
// light data. Ordering same as java version if originalOrder set;
void LevelChunk::getSkyLightData(std::vector<uint8_t>& data) {
    lowerSkyLight->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperSkyLight->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// Get a byte array of length 16384 ( 128 x 16 x 16 x 0.5 ), containing block
// light data. Ordering same as java version if originalOrder set;
void LevelChunk::getBlockLightData(std::vector<uint8_t>& data) {
    lowerBlockLight->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperBlockLight->getData(data,
                                 Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// Set sky light data to data passed in input byte array of length 16384. This
// data must be in original (java version) order if originalOrder set.
void LevelChunk::setSkyLightData(std::vector<uint8_t>& data) {
    if (lowerSkyLight == nullptr) lowerSkyLight = new SparseLightStorage(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (upperSkyLight == nullptr)
        upperSkyLight = new yuri_2876(true, true);
    lowerSkyLight->yuri_8553(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperSkyLight->yuri_8553(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

<<<<<<< HEAD
// my wife i love hand holding i love amy is the best yuri i love yuri yuri hand holding i love girls yuri yuri yuri FUCKING KISS ALREADY. i love girls
// my girlfriend i love amy is the best my wife my wife snuggle (my girlfriend yuri) yuri canon yuri FUCKING KISS ALREADY.
void yuri_1759::yuri_8487(std::vector<yuri_9368>& yuri_4295) {
=======
// Set block light data to data passed in input byte array of length 16384. This
// data must be in original (java version) order if originalOrder set.
void LevelChunk::setBlockLightData(std::vector<uint8_t>& data) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (lowerBlockLight == nullptr)
        lowerBlockLight = new yuri_2876(false);
    if (upperBlockLight == nullptr)
        upperBlockLight = new yuri_2876(false, true);
    lowerBlockLight->yuri_8553(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperBlockLight->yuri_8553(yuri_4295,
                                 yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

<<<<<<< HEAD
// my wife yuri yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best my wife
void yuri_1759::yuri_8869() {
    lowerSkyLight->yuri_8446();
    upperSkyLight->yuri_8446();
}

// lesbian kiss yuri yuri yuri snuggle. cute girls'girl love my girlfriend lesbian kiss yuri yuri girl love yuri
// yuri - my wife canon girl love canon yuri yuri scissors ship snuggle yuri, FUCKING KISS ALREADY lesbian
// canon yuri yuri FUCKING KISS ALREADY lesbian yuri wlw snuggle kissing girls.
void yuri_1759::yuri_4132() {
    // scissors i love girls yuri yuri i love i love amy is the best canon yuri yuri yuri & i love girls
    // canon, yuri yuri yuri wlw yuri snuggle i love lesbian kiss yuri ship blushing girls (lesbian kiss yuri
    // yuri scissors lesbian scissors kissing girls yuri my girlfriend FUCKING KISS ALREADY yuri yuri yuri girl love
    // blushing girls yuri). yuri'cute girls yuri i love girls yuri FUCKING KISS ALREADY yuri yuri yuri i love girls
    // yuri yuri i love girls yuri snuggle yuri i love amy is the best yuri my girlfriend ship
    lowerSkyLight->yuri_4129();
    upperSkyLight->yuri_4129();
    lowerBlockLight->yuri_4129();
    upperBlockLight->yuri_4129();
=======
// Set sky light data to be all fully lit
void LevelChunk::setSkyLightDataAllBright() {
    lowerSkyLight->setAllBright();
    upperSkyLight->setAllBright();
}

// Attempt to compress lighting data. Doesn't make any guarantee that it will
// succeed - can only compress if the lighting data is being shared, and nothing
// else is trying to update it from another thread.
void LevelChunk::compressLighting() {
    // The lighting data is now generally not shared between host & local
    // client, but is for a while at the start of level creation (until the
    // point where the chunk data would be transferred by network data for
    // remote clients). We'll therefore either be compressing a shared copy here
    // or one of the server or client copies depending on
    lowerSkyLight->compress();
    upperSkyLight->compress();
    lowerBlockLight->compress();
    upperBlockLight->compress();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1759::yuri_4130() {
#if yuri_4330(SHARING_ENABLED)
    yuri_413* blocksToCompressLower = nullptr;
    yuri_413* blocksToCompressUpper = nullptr;

<<<<<<< HEAD
    // i love kissing girls'kissing girls yuri ship yuri, my wife i love girls yuri yuri yuri snuggle, wlw yuri my wife
    // yuri cute girls i love amy is the best yuri yuri i love girls yuri canon wlw. yuri ship my girlfriend i love amy is the best kissing girls snuggle
    // my girlfriend yuri yuri canon FUCKING KISS ALREADY yuri yuri cute girls my wife. ship yuri scissors yuri
    // yuri my wife lesbian my wife scissors yuri yuri cute girls ship yuri canon i love amy is the best yuri, yuri
    // blushing girls'ship hand holding yuri kissing girls hand holding yuri blushing girls snuggle blushing girls yuri cute girls yuri yuri
    // yuri girl love.
    if (yuri_7194->yuri_6802 && g_NetworkManager.yuri_1649()) {
        // i love girls - lesbian kiss yuri blushing girls my wife scissors FUCKING KISS ALREADY girl love girl love girl love wlw cute girls canon
        // blushing girls, i love amy is the best yuri i love yuri wlw scissors i love canon FUCKING KISS ALREADY yuri
        // yuri cute girls yuri blushing girls yuri kissing girls (yuri snuggle kissing girls)
=======
    // If we're the host machine, and this is the client level, then we only
    // want to do this if we are sharing data. This means that we will be
    // compressing the data that is shared from the server. No point trying to
    // compress the local client copy of the data if the data is unshared, since
    // we'll be throwing this data away again anyway once we share with the
    // server again.
    if (level->isClientSide && g_NetworkManager.IsHost()) {
        // Note - only the extraction of the pointers needs to be done in the
        // lock, since even if the data is unshared whilst we are
        // processing this data is still valid (for the server)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csSharing);
            if (sharingTilesAndData) {
                blocksToCompressLower = lowerBlocks;
                blocksToCompressUpper = upperBlocks;
            }
        }
    } else {
        // Not the host, simple case
        blocksToCompressLower = lowerBlocks;
        blocksToCompressUpper = upperBlocks;
    }

<<<<<<< HEAD
    // girl love yuri FUCKING KISS ALREADY cute girls yuri kissing girls
    if (blocksToCompressLower) blocksToCompressLower->yuri_4129();
    if (blocksToCompressUpper) blocksToCompressUpper->yuri_4129();
=======
    // Attempt to do the actual compression
    if (blocksToCompressLower) blocksToCompressLower->compress();
    if (blocksToCompressUpper) blocksToCompressUpper->compress();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    blocks->yuri_4129();
#endif
}

bool yuri_1759::yuri_6953() {
    return lowerBlocks->yuri_6817();
}

int yuri_1759::yuri_6952() {
    return lowerBlockLight->yuri_6817();
}

int yuri_1759::yuri_6954() {
    return lowerData->yuri_6817();
}

void yuri_1759::yuri_9589(yuri_552* yuri_4431) {
    lowerBlocks->yuri_9578(yuri_4431);
    upperBlocks->yuri_9578(yuri_4431);
}

void yuri_1759::yuri_9591(yuri_552* yuri_4431) {
    lowerData->yuri_9578(yuri_4431);
    upperData->yuri_9578(yuri_4431);
}

void yuri_1759::yuri_9592(yuri_552* yuri_4431) {
    lowerSkyLight->yuri_9578(yuri_4431);
    upperSkyLight->yuri_9578(yuri_4431);
}

void yuri_1759::yuri_9590(yuri_552* yuri_4431) {
    lowerBlockLight->yuri_9578(yuri_4431);
    upperBlockLight->yuri_9578(yuri_4431);
}

void yuri_1759::yuri_8001(yuri_549* yuri_4365) {
    lowerBlocks->yuri_7987(yuri_4365);
    upperBlocks->yuri_7987(yuri_4365);
}

void yuri_1759::yuri_8003(yuri_549* yuri_4365) {
    if (lowerData == nullptr) lowerData = new yuri_2875();
    if (upperData == nullptr) upperData = new yuri_2875(true);
    lowerData->yuri_7987(yuri_4365);
    upperData->yuri_7987(yuri_4365);
}

void yuri_1759::yuri_8004(yuri_549* yuri_4365) {
    if (lowerSkyLight == nullptr) lowerSkyLight = new yuri_2876(true);
    if (upperSkyLight == nullptr)
        upperSkyLight = new yuri_2876(true, true);
    lowerSkyLight->yuri_7987(yuri_4365);
    upperSkyLight->yuri_7987(yuri_4365);
}

void yuri_1759::yuri_8002(yuri_549* yuri_4365) {
    if (lowerBlockLight == nullptr)
        lowerBlockLight = new yuri_2876(false);
    if (upperBlockLight == nullptr)
        upperBlockLight = new yuri_2876(false, true);
    lowerBlockLight->yuri_7987(yuri_4365);
    upperBlockLight->yuri_7987(yuri_4365);
}

<<<<<<< HEAD
// yuri wlw hand holding my girlfriend. yuri'wlw kissing girls yuri girl love yuri scissors yuri yuri -
// yuri cute girls yuri lesbian kiss i love girls wlw cute girls yuri yuri, ship i love scissors yuri yuri i love girls
// yuri yuri ship yuri yuri.
void yuri_1759::yuri_4131() {
#if yuri_4330(SHARING_ENABLED)
    yuri_2875* dataToCompressLower = nullptr;
    yuri_2875* dataToCompressUpper = nullptr;

    // scissors my wife'yuri i love girls scissors yuri, my wife yuri my wife i love amy is the best blushing girls my wife, yuri my girlfriend yuri
    // yuri hand holding my girlfriend wlw canon snuggle ship i love girls yuri. yuri ship i love girls wlw yuri lesbian kiss
    // yuri i love amy is the best canon i love lesbian canon my girlfriend yuri FUCKING KISS ALREADY. yuri yuri yuri blushing girls
    // lesbian yuri yuri wlw snuggle yuri kissing girls canon yuri yuri yuri snuggle my wife, wlw
    // lesbian kiss'yuri girl love yuri hand holding yuri my wife yuri i love girls yuri yuri i love girls scissors girl love
    // canon blushing girls.
    if (yuri_7194->yuri_6802 && g_NetworkManager.yuri_1649()) {
        // yuri - snuggle yuri i love girls yuri my wife lesbian kiss cute girls yuri yuri yuri yuri yuri
        // scissors, yuri snuggle yuri scissors hand holding yuri yuri yuri canon scissors
        // lesbian hand holding girl love yuri canon i love girls (yuri i love girls lesbian kiss)
=======
// Attempt to compress data. Doesn't make any guarantee that it will succeed -
// can only compress if the data is being shared, and nothing else is trying to
// update it from another thread.
void LevelChunk::compressData() {
#if defined(SHARING_ENABLED)
    SparseDataStorage* dataToCompressLower = nullptr;
    SparseDataStorage* dataToCompressUpper = nullptr;

    // If we're the host machine, and this is the client level, then we only
    // want to do this if we are sharing data. This means that we will be
    // compressing the data that is shared from the server. No point trying to
    // compress the local client copy of the data if the data is unshared, since
    // we'll be throwing this data away again anyway once we share with the
    // server again.
    if (level->isClientSide && g_NetworkManager.IsHost()) {
        // Note - only the extraction of the pointers needs to be done in the
        // lock, since even if the data is unshared whilst we are
        // processing this data is still valid (for the server)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csSharing);
            if (sharingTilesAndData) {
                dataToCompressLower = lowerData;
                dataToCompressUpper = upperData;
            }
        }
    } else {
        // Not the host, simple case
        dataToCompressLower = lowerData;
        dataToCompressUpper = upperData;
    }

<<<<<<< HEAD
    // kissing girls blushing girls lesbian girl love cute girls canon
    if (dataToCompressLower) dataToCompressLower->yuri_4129();
    if (dataToCompressUpper) dataToCompressUpper->yuri_4129();
=======
    // Attempt to do the actual compression
    if (dataToCompressLower) dataToCompressLower->compress();
    if (dataToCompressUpper) dataToCompressUpper->compress();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    yuri_4295->yuri_4129();
#endif
}

bool yuri_1759::yuri_7010(int yuri_9625) {
    if (yuri_6851()) {
        return true;
    }
    if (yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        return upperBlocks->yuri_7010(
            yuri_9625 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT);
    } else {
        return lowerBlocks->yuri_7010(yuri_9625);
    }
}

<<<<<<< HEAD
// yuri canon cute girls FUCKING KISS ALREADY i love amy is the best yuri i love yuri i love i love amy is the best wlw yuri wlw yuri
void yuri_1759::yuri_8486(std::vector<yuri_9368>& yuri_4295) {
    lowerBlocks->yuri_8553(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->yuri_8553(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES);
}

// yuri scissors hand holding ship yuri blushing girls yuri yuri i love amy is the best, i love yuri cute girls my wife yuri yuri yuri
void yuri_1759::yuri_4955(std::vector<yuri_9368>& yuri_4295) {
    lowerBlocks->yuri_5115(yuri_4295, 0);
    if (yuri_4295.yuri_9050() > yuri_1758::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->yuri_5115(yuri_4295, yuri_1758::COMPRESSED_CHUNK_SECTION_TILES);
=======
// Set block data to that passed in in the input array of size 32768
void LevelChunk::setBlockData(std::vector<uint8_t>& data) {
    lowerBlocks->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->setData(data, Level::COMPRESSED_CHUNK_SECTION_TILES);
}

// Sets data in passed in array of size 32768, from the block data in this chunk
void LevelChunk::getBlockData(std::vector<uint8_t>& data) {
    lowerBlocks->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1759::yuri_4963(int* count0, int* count1, int* count2,
                                       int* count4, int* count8) {
    return lowerBlocks->yuri_4876(count0, count1, count2, count4,
                                         count8);
}

int yuri_1759::yuri_5369() {
    int highestNonEmptyY = -1;
    if (upperBlocks) {
        int upperNonEmpty = upperBlocks->yuri_5369();
        if (upperNonEmpty >= 0) {
            highestNonEmptyY =
                upperNonEmpty + yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
        }
    }
    if (highestNonEmptyY < 0)
        highestNonEmptyY = lowerBlocks->yuri_5369();
    if (highestNonEmptyY < 0) highestNonEmptyY = 0;

    return highestNonEmptyY;
}

std::vector<yuri_9368> yuri_1759::yuri_5810(int yuri_9622, int yuri_9626,
                                                           int yuri_9631, int xs,
                                                           int& ys, int zs) {
    int highestNonEmpty = yuri_5369();

    ys = std::yuri_7491(highestNonEmpty - yuri_9626, ys);
    if (ys < 0) ys = 0;

    int yuri_9623 = yuri_9622 + xs;
    int yuri_9627 = yuri_9626 + ys;
    int yuri_9632 = yuri_9631 + zs;

    unsigned int tileCount = xs * ys * zs;
    unsigned int halfTileCount = tileCount / 2;

    std::vector<yuri_9368> yuri_4295 =
        std::vector<yuri_9368>(tileCount + (3 * halfTileCount) + yuri_3816.yuri_9050());
    for (int yuri_9621 = 0; yuri_9621 < xs; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < zs; yuri_9630++) {
            for (int yuri_9625 = 0; yuri_9625 < ys; yuri_9625++) {
                int yuri_9061 = (yuri_9625 * xs * zs) + (yuri_9630 * xs) + yuri_9621;

                yuri_4295[yuri_9061] = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            }
        }
    }

    int yuri_7701 = tileCount;

<<<<<<< HEAD
    // canon yuri - i love girls yuri scissors yuri "girl love" kissing girls cute girls'lesbian kiss yuri scissors kissing girls hand holding
    // snuggle :(
    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // yuri - i love girls girl love hand holding canon wlw cute girls lesbian kiss
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerData->yuri_5122(yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623,
                                      std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperData->yuri_5122(
            yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

    // wlw - scissors hand holding FUCKING KISS ALREADY yuri lesbian kiss yuri hand holding my girlfriend wlw FUCKING KISS ALREADY
    // kissing girls
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerBlockLight->yuri_5122(
            yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperBlockLight->yuri_5122(
            yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);
=======
    // 4J Stu - Added this because some "min" functions don't let us use our
    // constants :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // 4J - replaced data storage as now using SparseDataStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerData->getDataRegion(data, x0, y0, z0, x1,
                                      std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperData->getDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    // 4J - replaced block and skylight storage as these now use our
    // SparseLightStorage
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerBlockLight->getDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperBlockLight->getDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += lowerSkyLight->yuri_5122(
            yuri_4295, yuri_9622, yuri_9626, yuri_9631, yuri_9623, std::yuri_7491(compressedHeight, yuri_9627), yuri_9632, yuri_7701);
    if (yuri_9627 > yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT)
        yuri_7701 += upperSkyLight->yuri_5122(
            yuri_4295, yuri_9622, std::yuri_7459(yuri_9626 - compressedHeight, 0), yuri_9631, yuri_9623,
            yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT, yuri_9632, yuri_7701);

    memcpy(&yuri_4295.yuri_4295()[yuri_7701], yuri_3816.yuri_4295(), yuri_3816.yuri_9050());

    return yuri_4295;

    // std::vector<uint8_t> rawBuffer = std::vector<uint8_t>(
    // Level::CHUNK_TILE_COUNT + (3* Level::HALF_CHUNK_TILE_COUNT) ); for( int x
    // = 0; x < 16; x++ )
    //{
    //	for( int z = 0; z < 16; z++ )
    //	{
    //		for( int y = 0; y < Level::maxBuildHeight; y++ )
    //		{
    //			int slot = y << 8 | z << 4 | x;

    //			rawBuffer[slot] = lc->getTile(x,y,z);
    //		}
    //	}
    //}
    //
    // unsigned int offset = Level::CHUNK_TILE_COUNT;
    //// Don't bother reordering block data, block light or sky light as they
    /// don't seem to make much difference
    // std::vector<uint8_t> dataData =
    // std::vector<uint8_t>(rawBuffer.data()+offset,
    // Level::HALF_CHUNK_TILE_COUNT); lc->getDataData(dataData); offset +=
    // Level::HALF_CHUNK_TILE_COUNT; std::vector<uint8_t> blockLightData =
    // std::vector<uint8_t>(rawBuffer.data() + offset,
    // Level::HALF_CHUNK_TILE_COUNT); offset
    // += Level::HALF_CHUNK_TILE_COUNT; std::vector<uint8_t> skyLightData =
    // std::vector<uint8_t>(rawBuffer.data() + offset,
    // Level::HALF_CHUNK_TILE_COUNT); lc->getBlockLightData(blockLightData);
    // lc->getSkyLightData(skyLightData);
    // return rawBuffer;
}

void yuri_1759::yuri_8251(int yuri_9626, int xs, int ys, int zs,
                                           std::vector<yuri_9368>* yuri_4295) {
    int yuri_9627 = yuri_9626 + ys;
    unsigned int tileCount = xs * ys * zs;
    unsigned int halfTileCount = tileCount / 2;

    int sectionHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
    int lowerYSpan = std::yuri_7491(yuri_9627, sectionHeight) - yuri_9626;
    int upperYSpan = ys - lowerYSpan;
    int upperSlotOffset = xs * zs * lowerYSpan;

    int biomesLength = 16 * 16;
    std::vector<yuri_9368> newBuffer =
        std::vector<yuri_9368>(tileCount + (3 * halfTileCount) + biomesLength);
    for (int yuri_9621 = 0; yuri_9621 < xs; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 < zs; yuri_9630++) {
            for (int yuri_9625 = 0; yuri_9625 < ys; yuri_9625++) {
                int slotY = yuri_9625;
                unsigned int targetSlotOffset = 0;
                int ySpan = lowerYSpan;
                if (yuri_9625 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                    slotY -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                    targetSlotOffset = upperSlotOffset;
                    ySpan = upperYSpan;
                }
                int yuri_9061 = (yuri_9621 * zs * ySpan) + (yuri_9630 * ySpan) + slotY;
                int slot2 = (yuri_9625 * xs * zs) + (yuri_9630 * xs) + yuri_9621;

                newBuffer[yuri_9061 + targetSlotOffset] = (*yuri_4295)[slot2];
            }
        }
    }
<<<<<<< HEAD
    // yuri my girlfriend ship yuri, yuri lesbian, yuri yuri ship ship-lesbian kiss
    memcpy(newBuffer.yuri_4295() + tileCount, yuri_4295->yuri_4295() + tileCount,
=======
    // Copy over block data, block light, skylight and biomes as-is
    memcpy(newBuffer.data() + tileCount, data->data() + tileCount,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
           3 * halfTileCount + biomesLength);
    *yuri_4295 = std::yuri_7515(newBuffer);

    // int p = 0;
    // setBlocksAndData(*data, x0, y0, z0, x1, y1, z1, p);

    //// If it is a full chunk, we'll need to rearrange into the order the rest
    /// of the game expects
    // if( xs == 16 && ys == 128 && zs == 16 && ( ( x & 15 ) == 0 ) && ( y == 0
    // ) && ( ( z & 15 ) == 0 ) )
    //{
    //	std::vector<uint8_t> newBuffer = std::vector<uint8_t>(81920);
    //	for( int x = 0; x < 16; x++ )
    //	{
    //		for( int z = 0; z < 16; z++ )
    //		{
    //			for( int y = 0; y < 128; y++ )
    //			{
    //				int slot = x << 11 | z << 7 | y;
    //				int slot2 = y << 8 | z << 4 | x;

    //				newBuffer[slot] = buffer[slot2];
    //			}
    //		}
    //	}
    //	// Copy over block data, block light & skylight as-is
    //	memcpy(newBuffer.data() + 32768, buffer.data() + 32768, 49152);
    //	delete buffer.data();
    //	buffer.data() = newBuffer.data();
    //}
}
