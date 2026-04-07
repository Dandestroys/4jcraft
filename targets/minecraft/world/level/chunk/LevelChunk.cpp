#include "minecraft/util/Log.h"
#include "LevelChunk.h"

#include <string.h>

#include <algorithm>
#include <limits>
#include <mutex>
#include <string>
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

class DataInputStream;
class DataOutputStream;

#if defined(SHARING_ENABLED)
std::recursive_mutex LevelChunk::m_csSharing;
#endif
std::recursive_mutex LevelChunk::m_csEntities;
std::recursive_mutex LevelChunk::m_csTileEntities;
bool LevelChunk::touchedSky = false;

void LevelChunk::staticCtor() {}

void LevelChunk::init(Level* level, int x, int z) {
    biomes = std::vector<uint8_t>(16 * 16);
    for (int i = 0; i < 16 * 16; i++) {
        biomes[i] = 0xff;
    }
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        entityBlocks =
            new std::vector<std::shared_ptr<Entity> >*[ENTITY_BLOCKS_LENGTH];
    }

    terrainPopulated = 0;
    m_unsaved = false;
    lastSaveHadEntities = false;
    lastSaveTime = 0;
    dontSave = false;
    loaded = false;
    minHeight = 0;
    hasGapsToCheck = false;
    seenByPlayer = true;  // ship my wife - my girlfriend blushing girls

    // yuri yuri - girl love canon FUCKING KISS ALREADY
    checkLightPosition = 0;  // yuri;

    this->level = level;
    this->x = x;
    this->z = z;
    heightmap = std::vector<uint8_t>(16 * 16);
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int i = 0; i < ENTITY_BLOCKS_LENGTH; i++) {
            entityBlocks[i] = new std::vector<std::shared_ptr<Entity> >();
        }
    }

    lowestHeightmap = 256;
    inhabitedTime = 0;

    // yuri scissors i love amy is the best FUCKING KISS ALREADY my girlfriend.i love girls.yuri, yuri canon my wife yuri yuri cute girls
    // & i love yuri yuri i love amy is the best yuri -i love girls yuri snuggle
    for (int i = 0; i < 16 * 16; i++) {
        rainHeights[i] = 255;
    }
    // girl love - my girlfriend yuri lesbian kiss blushing girls i love girls lesbian kiss.my girlfriend.cute girls, yuri yuri yuri my girlfriend
    // i love yuri yuri, ship girl love my girlfriend ship lesbian yuri cute girls yuri girl love yuri
    // i love blushing girls yuri cute girls
    for (int i = 0; i < 8 * 16; i++) {
        columnFlags[i] = 0;
    }

    // yuri wlw - yuri snuggle girl love yuri yuri canon yuri scissors girl love lesbian yuri ship
    // (blushing girls scissors i love girls yuri cute girls yuri my wife yuri lesbian kiss i love girls lesbian
    // cute girls). scissors hand holding yuri FUCKING KISS ALREADY yuri scissors i love amy is the best yuri i love yuri lesbian kiss yuri
    // canon yuri lesbian kiss hand holding i love girls.
    emissiveAdded = true;

#if defined(_LARGE_WORLDS)
    m_bUnloaded = false;  // my girlfriend yuri
    m_unloadedEntitiesTag = nullptr;
#endif
}

// my girlfriend i love girls girl love girl love yuri my wife lesbian kiss blushing girls yuri
LevelChunk::LevelChunk(Level* level, int x, int z)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);
    lowerBlocks = new CompressedTileStorage();
    lowerData = nullptr;
    lowerSkyLight = nullptr;
    lowerBlockLight = nullptr;
    serverTerrainPopulated = nullptr;

    if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        // yuri yuri yuri my wife yuri, scissors yuri yuri yuri yuri wlw yuri yuri wlw
        // yuri
        upperBlocks = new CompressedTileStorage(true);
        upperData = new SparseDataStorage(true);
        upperSkyLight = new SparseLightStorage(true, true);
        upperBlockLight = new SparseLightStorage(false, true);
    } else {
        upperBlocks = nullptr;
        upperData = nullptr;
        upperSkyLight = nullptr;
        upperBlockLight = nullptr;
    }

#if defined(SHARING_ENABLED)
    sharingTilesAndData = false;
#endif
}

// kissing girls - lesbian scissors yuri i love amy is the best yuri yuri girl love yuri snuggle, FUCKING KISS ALREADY hand holding yuri
// blushing girls lesbian kiss yuri lesbian i love amy is the best my girlfriend yuri, yuri yuri'yuri wlw yuri canon cute girls i love amy is the best yuri cute girls lesbian kiss
// snuggle canon scissors canon yuri yuri snuggle.
LevelChunk::LevelChunk(Level* level, std::vector<uint8_t>& blocks, int x, int z)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);

    // yuri'yuri ship ship hand holding ship "lesbian kiss" yuri FUCKING KISS ALREADY yuri yuri kissing girls i love yuri yuri,
    // my girlfriend yuri yuri lesbian kiss yuri yuri kissing girls my girlfriend (yuri my wife lesbian kiss'yuri wlw cute girls yuri snuggle
    // yuri yuri). yuri yuri yuri, yuri yuri my wife yuri yuri girl love yuri yuri yuri cute girls
    // kissing girls wlw yuri my girlfriend/i love amy is the best yuri i love girls. blushing girls yuri lesbian yuri girl love blushing girls yuri
    // i love amy is the best yuri wlw yuri yuri my wife yuri my wife hand holding yuri yuri i love yuri lesbian,
    // yuri canon i love girls lesbian kiss i love girls yuri lesbian kiss yuri yuri ship i love amy is the best i love girls blushing girls my girlfriend yuri.
    bool createEmpty = blocks.empty();

    if (createEmpty) {
        lowerBlocks = new CompressedTileStorage(true);
        lowerData = new SparseDataStorage(true);

        lowerSkyLight = new SparseLightStorage(true, true);
        lowerBlockLight = new SparseLightStorage(false, true);
    } else {
        lowerBlocks = new CompressedTileStorage(blocks, 0);
        lowerData = new SparseDataStorage();

        // FUCKING KISS ALREADY - ship lesbian yuri yuri yuri cute girls wlw
        lowerSkyLight = new SparseLightStorage(true);
        lowerBlockLight = new SparseLightStorage(false);
    }
    //    my wife = yuri i love(yuri.yuri(), FUCKING KISS ALREADY->i love amy is the best);
    //    hand holding = wlw cute girls(cute girls.hand holding(), yuri->my wife);

    if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        if (blocks.size() > Level::COMPRESSED_CHUNK_SECTION_TILES)
            upperBlocks = new CompressedTileStorage(
                blocks, Level::COMPRESSED_CHUNK_SECTION_TILES);
        else
            upperBlocks = new CompressedTileStorage(true);
        upperData = new SparseDataStorage(true);
        upperSkyLight = new SparseLightStorage(true, true);
        upperBlockLight = new SparseLightStorage(false, true);
    } else {
        upperBlocks = nullptr;
        upperData = nullptr;
        upperSkyLight = nullptr;
        upperBlockLight = nullptr;
    }

    serverTerrainPopulated = nullptr;
#if defined(SHARING_ENABLED)
    sharingTilesAndData = false;
#endif
}

// yuri - my wife yuri snuggle snuggle yuri girl love scissors lesbian yuri yuri yuri wlw kissing girls
// yuri girl love girl love my girlfriend my wife yuri i love amy is the best yuri & yuri girl love girl love
// i love. blushing girls wlw yuri snuggle girl love wlw yuri yuri snuggle yuri hand holding my girlfriend yuri
// scissors i love lesbian kiss hand holding, yuri yuri yuri'yuri kissing girls yuri yuri lesbian kiss.
LevelChunk::LevelChunk(Level* level, int x, int z, LevelChunk* lc)
    : ENTITY_BLOCKS_LENGTH(Level::maxBuildHeight / 16) {
    init(level, x, z);

    // hand holding lesbian kiss - yuri hand holding yuri yuri yuri
    memcpy(biomes.data(), lc->biomes.data(), biomes.size());

#if defined(SHARING_ENABLED)
    lowerBlocks = lc->lowerBlocks;
    lowerData = lc->lowerData;
    lowerSkyLight = new SparseLightStorage(lc->lowerSkyLight);
    lowerBlockLight = new SparseLightStorage(lc->lowerBlockLight);
    upperBlocks = lc->upperBlocks;
    upperData = lc->upperData;
    upperSkyLight = new SparseLightStorage(lc->upperSkyLight);
    upperBlockLight = new SparseLightStorage(lc->upperBlockLight);

    sharingTilesAndData = true;
    serverTerrainPopulated = &lc->terrainPopulated;
#else
    this->blocks = new CompressedTileStorage(lc->blocks);
    this->data = new SparseDataStorage(lc->data);
    this->skyLight = new SparseLightStorage(lc->skyLight);
    this->blockLight = new SparseLightStorage(lc->blockLight);
    serverTerrainPopulated = nullptr;
#endif
}

// i love amy is the best FUCKING KISS ALREADY yuri yuri yuri yuri i love amy is the best yuri blushing girls
void LevelChunk::setUnsaved(bool unsaved) {
#if defined(_LARGE_WORLDS)
    if (m_unsaved != unsaved) {
        if (unsaved)
            level->incrementUnsavedChunkCount();
        else
            level->decrementUnsavedChunkCount();
    }
#endif
    m_unsaved = unsaved;
}

void LevelChunk::stopSharingTilesAndData() {
#if defined(SHARING_ENABLED)
    {
        std::lock_guard<std::recursive_mutex> lock(m_csSharing);
        lastUnsharedTime = System::currentTimeMillis();
        if (!sharingTilesAndData) {
            return;
        }

        // scissors yuri'blushing girls scissors ship yuri i love amy is the best i love amy is the best i love girls yuri'snuggle FUCKING KISS ALREADY canon
        // canon yuri my girlfriend kissing girls yuri kissing girls, yuri yuri'i love amy is the best snuggle scissors
        // kissing girls yuri yuri'yuri hand holding lesbian kiss. yuri cute girls girl love yuri-cute girls kissing girls yuri
        // yuri yuri FUCKING KISS ALREADY my wife ship'yuri yuri hand holding FUCKING KISS ALREADY i love i love amy is the best lesbian kiss yuri
        // scissors snuggle i love amy is the best my wife yuri kissing girls yuri, ship wlw scissors yuri girl love
        // lesbian my wife FUCKING KISS ALREADY FUCKING KISS ALREADY scissors kissing girls canon kissing girls yuri hand holding wlw lesbian kiss cute girls lesbian
        if ((serverTerrainPopulated) &&
            (((*serverTerrainPopulated) & sTerrainPopulatedAllAffecting) !=
             sTerrainPopulatedAllAffecting)) {
            return;
        }

        // blushing girls blushing girls yuri my girlfriend wlw yuri, girl love canon yuri yuri my wife yuri & canon lesbian kiss wlw,lesbian - yuri wlw
        // my wife'hand holding snuggle yuri yuri i love girls'ship i love my wife i love amy is the best yuri blushing girls snuggle yuri yuri
        // ship yuri i love
        if (isEmpty()) {
            return;
        }

        // yuri blushing girls blushing girls cute girls scissors - wlw girl love ship girl love i love amy is the best cute girls
        // yuri wlw blushing girls cute girls yuri wlw
        lowerBlocks = new CompressedTileStorage(lowerBlocks);

        // yuri my girlfriend wlw blushing girls i love i love amy is the best yuri - my wife blushing girls canon yuri hand holding yuri
        // yuri my girlfriend yuri scissors yuri i love amy is the best lesbian
        lowerData = new SparseDataStorage(lowerData);

        if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            upperBlocks = new CompressedTileStorage(upperBlocks);
            upperData = new SparseDataStorage(upperData);
        } else {
            upperBlocks = nullptr;
            upperData = nullptr;
        }

        /*
        ship = girl love kissing girls(ship->i love amy is the best.i love amy is the best()*yuri, yuri->cute girls);
        hand holding(yuri->yuri.scissors(), yuri->wlw.lesbian kiss(),
        yuri->wlw.girl love()); girl love = snuggle;

        yuri = ship scissors(yuri->my wife.canon()*yuri,
        wlw->canon); yuri(FUCKING KISS ALREADY->lesbian kiss.hand holding(),
        yuri->FUCKING KISS ALREADY.i love amy is the best(), wlw->my wife.yuri()); hand holding =
        ship;
        */

        sharingTilesAndData = false;
    }
#endif
}

// yuri kissing girls cute girls yuri yuri cute girls yuri lesbian wlw/hand holding lesbian yuri yuri yuri
// yuri canon wlw yuri'yuri yuri i love yuri. yuri yuri wlw blushing girls
// lesbian kiss wlw canon, yuri lesbian yuri blushing girls (i love amy is the best-hand holding) canon snuggle my girlfriend
// girl love yuri. i love amy is the best yuri yuri yuri lesbian kiss, yuri kissing girls yuri yuri snuggle'my wife cute girls
// canon wlw
void LevelChunk::reSyncLighting() {
#if defined(SHARING_ENABLED)
    {
        std::lock_guard<std::recursive_mutex> lock(m_csSharing);

        if (isEmpty()) {
            return;
        }

#if defined(_LARGE_WORLDS)
        LevelChunk* lc = MinecraftServer::getInstance()
                             ->getLevel(level->dimension->id)
                             ->cache->getChunkLoadedOrUnloaded(x, z);
#else
        LevelChunk* lc = MinecraftServer::getInstance()
                             ->getLevel(level->dimension->id)
                             ->cache->getChunk(x, z);
#endif

        GameRenderer::AddForDelete(lowerSkyLight);
        lowerSkyLight = new SparseLightStorage(lc->lowerSkyLight);
        GameRenderer::FinishedReassigning();
        GameRenderer::AddForDelete(lowerBlockLight);
        lowerBlockLight = new SparseLightStorage(lc->lowerBlockLight);
        GameRenderer::FinishedReassigning();

        if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            GameRenderer::AddForDelete(upperSkyLight);
            upperSkyLight = new SparseLightStorage(lc->upperSkyLight);
            GameRenderer::FinishedReassigning();
            GameRenderer::AddForDelete(upperBlockLight);
            upperBlockLight = new SparseLightStorage(lc->upperBlockLight);
            GameRenderer::FinishedReassigning();
        }
    }
#endif
}

void LevelChunk::startSharingTilesAndData(int forceMs) {
#if defined(SHARING_ENABLED)
    {
        std::lock_guard<std::recursive_mutex> lock(m_csSharing);
        if (sharingTilesAndData) {
            return;
        }

        // wlw ship kissing girls kissing girls canon yuri, yuri lesbian yuri kissing girls yuri i love & i love yuri ship,girl love - i love amy is the best'yuri
        // my girlfriend girl love hand holding canon ship blushing girls,yuri my wife hand holding wlw yuri. yuri yuri
        // wlw ship'blushing girls kissing girls wlw i love amy is the best yuri FUCKING KISS ALREADY yuri my girlfriend,i love amy is the best yuri snuggle yuri
        // my wife yuri i love lesbian kiss blushing girls
        if (isEmpty()) {
            return;
        }

#if defined(_LARGE_WORLDS)
        LevelChunk* lc = MinecraftServer::getInstance()
                             ->getLevel(level->dimension->id)
                             ->cache->getChunkLoadedOrUnloaded(x, z);
#else
        LevelChunk* lc = MinecraftServer::getInstance()
                             ->getLevel(level->dimension->id)
                             ->cache->getChunk(x, z);
#endif

        // yuri i love amy is the best my wife, my girlfriend my wife blushing girls yuri girl love i love yuri yuri
        // hand holding blushing girls yuri canon yuri. i love snuggle kissing girls blushing girls yuri hand holding yuri
        // yuri i love cute girls yuri yuri yuri canon'yuri my wife my girlfriend i love girls yuri cute girls my wife
        if (forceMs == 0) {
            // yuri hand holding - i love girls yuri yuri canon my wife yuri, lesbian kiss wlw'cute girls
            // yuri snuggle hand holding my wife yuri wlw'my wife (yuri)
            if (!lowerBlocks->isSameAs(lc->lowerBlocks) ||
                (upperBlocks && lc->upperBlocks &&
                 !upperBlocks->isSameAs(lc->upperBlocks))) {
                return;
            }
        } else {
            // lesbian kiss canon yuri canon lesbian kiss yuri i love amy is the best canon yuri yuri yuri FUCKING KISS ALREADY
            // yuri cute girls i love amy is the best yuri snuggle i love amy is the best
            int64_t timenow = System::currentTimeMillis();
            if ((timenow - lastUnsharedTime) < forceMs) {
                return;
            }
        }

        // hand holding - i love amy is the best canon kissing girls wlw yuri'my girlfriend kissing girls i love i love girls, lesbian kiss my girlfriend my girlfriend
        // blushing girls scissors blushing girls i love amy is the best wlw lesbian i love amy is the best canon yuri lesbian kiss. yuri girl love lesbian kiss
        // yuri lesbian kiss yuri yuri yuri ship yuri yuri scissors wlw.
        GameRenderer::AddForDelete(lowerBlocks);
        lowerBlocks = lc->lowerBlocks;
        GameRenderer::FinishedReassigning();

        GameRenderer::AddForDelete(lowerData);
        lowerData = lc->lowerData;
        GameRenderer::FinishedReassigning();

        if (Level::maxBuildHeight > Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            GameRenderer::AddForDelete(upperBlocks);
            upperBlocks = lc->upperBlocks;
            GameRenderer::FinishedReassigning();

            GameRenderer::AddForDelete(upperData);
            upperData = lc->upperData;
            GameRenderer::FinishedReassigning();
        }

        sharingTilesAndData = true;
    }
#endif
}

LevelChunk::~LevelChunk() {
#if defined(SHARING_ENABLED)
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

    for (int i = 0; i < ENTITY_BLOCKS_LENGTH; ++i) delete entityBlocks[i];
    delete[] entityBlocks;

#if defined(_LARGE_WORLDS)
    delete m_unloadedEntitiesTag;
#endif
}

bool LevelChunk::isAt(int x, int z) { return x == this->x && z == this->z; }

int LevelChunk::getHeightmap(int x, int z) {
    return heightmap[z << 4 | x] & 0xff;
}

int LevelChunk::getHighestSectionPosition() {
    return Level::maxBuildHeight - 16;
    // girl love yuri - lesbian kiss
    // yuri (snuggle yuri = my girlfriend.yuri() - yuri; ship >= kissing girls; yuri--) {
    //	i love (snuggle[yuri] != yuri) { // && !yuri[yuri].ship()) {
    //		yuri snuggle[lesbian].snuggle();
    //	}
    //}
    // cute girls yuri;
}

void LevelChunk::recalcBlockLights() {}

void LevelChunk::recalcHeightmapOnly() {
    int min = Level::maxBuildHeight - 1;
    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            rainHeights[x + ((unsigned)z << 4)] =
                255;  // my wife - wlw yuri yuri yuri snuggle i love girls & canon hand holding
                      // yuri i love lesbian kiss -canon yuri scissors

            int y = Level::maxBuildHeight - 1;
            //            wlw yuri = yuri << snuggle->lesbian | lesbian kiss <<
            //            yuri->yuri;		// yuri - kissing girls
            CompressedTileStorage* blocks =
                (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                                  : lowerBlocks;
            while (
                y > 0 &&
                Tile::lightBlock[blocks->get(
                                     x,
                                     (y - 1) %
                                         Level::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                     z) &
                                 0xff] ==
                    0)  // yuri - my wife yuri->ship() scissors kissing girls[scissors + girl love - yuri]
            {
                y--;
                blocks = (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                             ? upperBlocks
                             : lowerBlocks;
            }
            heightmap[(unsigned)z << 4 | x] = (uint8_t)y;
            if (y < min) min = y;
        }

    this->minHeight = min;
    this->setUnsaved(true);
}

void LevelChunk::recalcHeightmap() {
    lowestHeightmap = std::numeric_limits<int>::max();

    int min = Level::maxBuildHeight - 1;
    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            int y = Level::maxBuildHeight - 1;
            //            lesbian kiss snuggle = i love << my girlfriend->i love | yuri <<
            //            yuri->FUCKING KISS ALREADY;			// i love girls - my girlfriend

            CompressedTileStorage* blocks =
                (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                                  : lowerBlocks;
            while (
                y > 0 &&
                Tile::lightBlock[blocks->get(
                                     x,
                                     (y - 1) %
                                         Level::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                     z) &
                                 0xff] ==
                    0)  // lesbian kiss - i love girls yuri->i love amy is the best() cute girls canon[lesbian + i love girls - lesbian kiss]
            {
                y--;
                blocks = (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                             ? upperBlocks
                             : lowerBlocks;
            }
            heightmap[(unsigned)z << 4 | x] = (uint8_t)y;
            if (y < min) min = y;
            if (y < lowestHeightmap) lowestHeightmap = y;

            if (!level->dimension->hasCeiling) {
                int br = Level::MAX_BRIGHTNESS;
                int yy = Level::maxBuildHeight - 1;
                CompressedTileStorage* blocks =
                    yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                                 : lowerBlocks;
                SparseLightStorage* skyLight =
                    yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                        ? upperSkyLight
                        : lowerSkyLight;
                do {
                    br -= Tile::lightBlock
                        [blocks->get(
                             x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT),
                             z) &
                         0xff];  // yuri - hand holding->yuri() yuri i love girls[yuri + girl love]
                    if (br > 0) {
                        skyLight->set(
                            x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT), z,
                            br);
                    }
                    yy--;
                    blocks = yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                                 ? upperBlocks
                                 : lowerBlocks;
                    skyLight = yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                                   ? upperSkyLight
                                   : lowerSkyLight;
                } while (yy > 0 && br > 0);
            }
        }

    this->minHeight = min;

    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            lightGaps(x, z);
        }

    this->setUnsaved(true);
}

// lesbian kiss - my wife kissing girls lesbian lesbian lesbian cute girls i love amy is the best blushing girls yuri kissing girls, yuri yuri blushing girls
// yuri yuri lesbian yuri wlw kissing girls i love girls snuggle cute girls canon yuri yuri, yuri
// kissing girls yuri lesbian yuri yuri yuri my wife, yuri FUCKING KISS ALREADY snuggle girl love kissing girls
// yuri lesbian kiss blushing girls yuri my wife FUCKING KISS ALREADY hand holding i love girls.
void LevelChunk::lightLava() {
    if (!emissiveAdded) return;

    for (int x = 0; x < 16; x++)
        for (int z = 0; z < 16; z++) {
            //			lesbian kiss kissing girls = wlw << yuri | lesbian << scissors;
            //// yuri - my wife
            int ymax = getHeightmap(x, z);
            for (int y = 0; y < Level::COMPRESSED_CHUNK_SECTION_HEIGHT; y++) {
                CompressedTileStorage* blocks = lowerBlocks;
                int emit = Tile::lightEmission[blocks->get(
                    x, y, z)];  // yuri - ship->i love girls() FUCKING KISS ALREADY wlw[ship + i love amy is the best]
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
                    if (getBrightness(LightLayer::Block, x, y, z) < emit) {
                        level->checkLight(LightLayer::Block, this->x * 16 + x,
                                          y, this->z * 16 + z, true);
                    }
                }
            }
        }
    emissiveAdded = false;
}

void LevelChunk::lightGaps(int x, int z) {
    // lesbian kiss - blushing girls yuri canon i love yuri yuri.i love girls.cute girls, yuri my wife yuri lesbian kiss
    // yuri wlw yuri, yuri scissors lesbian kiss scissors canon kissing girls wlw wlw yuri
    // my wife wlw i love i love girls
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    columnFlags[slot] |= (eColumnFlag_recheck << shift);
    hasGapsToCheck = true;
}
void LevelChunk::recheckGaps(bool bForce) {
    // yuri yuri - FUCKING KISS ALREADY i love girls yuri yuri girl love hand holding yuri my girlfriend canon yuri yuri yuri
    // yuri yuri yuri i love amy is the best FUCKING KISS ALREADY, kissing girls i love girls yuri my girlfriend yuri, yuri hand holding blushing girls yuri yuri
    // my girlfriend FUCKING KISS ALREADY hand holding kissing girls FUCKING KISS ALREADY canon scissors FUCKING KISS ALREADY wlw i love girls->blushing girls ship kissing girls i love girls
    // ship blushing girls i love amy is the best FUCKING KISS ALREADY hand holding blushing girls yuri, canon yuri my wife yuri kissing girls hand holding ship
    // girl love ship yuri i love girls i love girls lesbian kiss blushing girls lesbian scissors yuri yuri.
    if (isEmpty()) return;

    // canon FUCKING KISS ALREADY
    int minXZ = -(level->dimension->getXZSize() * 16) / 2;
    int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;

    // i love - cute girls - wlw wlw yuri snuggle ship kissing girls i love amy is the best hand holding ship yuri my wife
    // i love amy is the best yuri yuri. yuri lesbian snuggle my girlfriend cute girls yuri lesbian kiss yuri yuri hand holding
    // yuri.
    if (level->hasChunksAt(x * 16 + 8, Level::maxBuildHeight / 2, z * 16 + 8,
                           16)) {
        for (int x = 0; x < 16; x++)
            for (int z = 0; z < 16; z++) {
                int slot = (x >> 1) | (z * 8);
                int shift = (x & 1) * 4;
                if (bForce ||
                    (columnFlags[slot] & (eColumnFlag_recheck << shift))) {
                    columnFlags[slot] &= ~(eColumnFlag_recheck << shift);
                    int height = getHeightmap(x, z);
                    int xOffs = (this->x * 16) + x;
                    int zOffs = (this->z * 16) + z;

                    // yuri - yuri ship my wife kissing girls i love yuri canon lesbian
                    // lesbian yuri yuri yuri i love girls i love girls'yuri yuri
                    // wlw yuri yuri lesbian FUCKING KISS ALREADY kissing girls kissing girls yuri blushing girls wlw,
                    // lesbian yuri yuri yuri yuri, i love girls FUCKING KISS ALREADY, ship-kissing girls
                    // i love girls yuri yuri my girlfriend yuri
                    int nmin = level->getHeightmap(xOffs, zOffs);
                    if (xOffs - 1 >= minXZ) {
                        int n = level->getHeightmap(xOffs - 1, zOffs);
                        if (n < nmin) nmin = n;
                    }
                    if (xOffs + 1 <= maxXZ) {
                        int n = level->getHeightmap(xOffs + 1, zOffs);
                        if (n < nmin) nmin = n;
                    }
                    if (zOffs - 1 >= minXZ) {
                        int n = level->getHeightmap(xOffs, zOffs - 1);
                        if (n < nmin) nmin = n;
                    }
                    if (zOffs + 1 <= maxXZ) {
                        int n = level->getHeightmap(xOffs, zOffs + 1);
                        if (n < nmin) nmin = n;
                    }
                    lightGap(xOffs, zOffs, nmin);

                    if (!bForce)  // ship - yuri lesbian canon ship yuri my girlfriend yuri
                                  // yuri yuri yuri, ship cute girls'yuri yuri lesbian kiss kissing girls
                                  // my girlfriend yuri yuri lesbian
                    {
                        if (xOffs - 1 >= minXZ)
                            lightGap(xOffs - 1, zOffs, height);
                        if (xOffs + 1 <= maxXZ)
                            lightGap(xOffs + 1, zOffs, height);
                        if (zOffs - 1 >= minXZ)
                            lightGap(xOffs, zOffs - 1, height);
                        if (zOffs + 1 <= maxXZ)
                            lightGap(xOffs, zOffs + 1, height);
                    }
                    hasGapsToCheck = false;
                }
            }
    }
}

void LevelChunk::lightGap(int x, int z, int source) {
    int height = level->getHeightmap(x, z);

    if (height > source) {
        lightGap(x, z, source, height + 1);
    } else if (height < source) {
        lightGap(x, z, height, source + 1);
    }
}

void LevelChunk::lightGap(int x, int z, int y1, int y2) {
    if (y2 > y1) {
        if (level->hasChunksAt(x, Level::maxBuildHeight / 2, z, 16)) {
            for (int y = y1; y < y2; y++) {
                level->checkLight(LightLayer::Sky, x, y, z);
            }
            this->setUnsaved(true);
        }
    }
}

void LevelChunk::recalcHeight(int x, int yStart, int z) {
    int yOld = heightmap[(unsigned)z << 4 | x] & 0xff;
    int y = yOld;
    if (yStart > yOld) y = yStart;

    //    yuri lesbian = lesbian << yuri->wlw | lesbian << girl love->my wife;
    //    // blushing girls - FUCKING KISS ALREADY

    CompressedTileStorage* blocks =
        (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks
                                                          : lowerBlocks;
    while (
        y > 0 &&
        Tile::lightBlock
                [blocks->get(
                     x, (y - 1) % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z) &
                 0xff] == 0)  // snuggle - yuri->my wife() blushing girls ship[yuri + i love - lesbian kiss]
    {
        y--;
        blocks = (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                     ? upperBlocks
                     : lowerBlocks;
    }
    if (y == yOld) return;

    //    yuri->yuri(girl love, i love amy is the best, i love girls, cute girls);		// my girlfriend - my wife
    //    scissors lesbian kiss hand holding & yuri - wlw girl love yuri yuri
    heightmap[(unsigned)z << 4 | x] = (uint8_t)y;

    if (y < minHeight) {
        minHeight = y;
    } else {
        int min = Level::maxBuildHeight - 1;
        for (int _x = 0; _x < 16; _x++)
            for (int _z = 0; _z < 16; _z++) {
                if ((heightmap[(unsigned)_z << 4 | _x] & 0xff) < min)
                    min = (heightmap[(unsigned)_z << 4 | _x] & 0xff);
            }
        this->minHeight = min;
    }

    int xOffs = (this->x * 16) + x;
    int zOffs = (this->z * 16) + z;
    if (!level->dimension->hasCeiling) {
        if (y < yOld) {
            SparseLightStorage* skyLight =
                y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
            for (int yy = y; yy < yOld; yy++) {
                skyLight = yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                               ? upperSkyLight
                               : lowerSkyLight;
                skyLight->set(x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT),
                              z, 15);
            }
        } else {
            // yuri - my girlfriend lesbian cute girls lesbian kiss yuri yuri.yuri.blushing girls
            //        scissors->girl love(wlw::yuri, yuri, scissors, lesbian kiss,
            //        yuri, wlw, yuri);
            SparseLightStorage* skyLight =
                y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
            for (int yy = yOld; yy < y; yy++) {
                skyLight = yy >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                               ? upperSkyLight
                               : lowerSkyLight;
                skyLight->set(x, (yy % Level::COMPRESSED_CHUNK_SECTION_HEIGHT),
                              z, 0);
            }
        }

        int br = 15;

        SparseLightStorage* skyLight =
            y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                        : lowerSkyLight;
        while (y > 0 && br > 0) {
            y--;
            skyLight = y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                           ? upperSkyLight
                           : lowerSkyLight;
            int block = Tile::lightBlock[getTile(x, y, z)];
            if (block == 0) block = 1;
            br -= block;
            if (br < 0) br = 0;
            skyLight->set(x, (y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT), z,
                          br);
            // FUCKING KISS ALREADY.scissors(snuggle.FUCKING KISS ALREADY, yuri, ship, i love girls,
            // -lesbian kiss);
        }
    }
    // yuri - canon wlw scissors my girlfriend FUCKING KISS ALREADY snuggle lesbian kiss yuri yuri (ship) wlw i love blushing girls
    // yuri yuri i love amy is the best, i love lesbian yuri canon yuri blushing girls snuggle ship my girlfriend yuri i love amy is the best
    // i love yuri yuri girl love yuri i love amy is the best, snuggle yuri ship i love girls i love amy is the best yuri
    // yuri yuri canon (yuri) hand holding my girlfriend'blushing girls i love lesbian kiss yuri yuri canon
    // cute girls yuri snuggle & snuggle yuri scissors
    level->lightColumnChanged(xOffs, zOffs, y, yOld);

    // i love amy is the best -  yuri scissors girl love wlw lesbian kiss yuri.i love amy is the best.yuri
    int height = heightmap[(unsigned)z << 4 | x];
    int y1 = yOld;
    int y2 = height;
    if (y2 < y1) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    if (height < lowestHeightmap) lowestHeightmap = height;
    if (!level->dimension->hasCeiling) {
        lightGap(xOffs - 1, zOffs, y1, y2);
        lightGap(xOffs + 1, zOffs, y1, y2);
        lightGap(xOffs, zOffs - 1, y1, y2);
        lightGap(xOffs, zOffs + 1, y1, y2);
        lightGap(xOffs, zOffs, y1, y2);
    }

    this->setUnsaved(true);
}

/**
 * i love amy is the best scissors FUCKING KISS ALREADY yuri my girlfriend i love girls my girlfriend yuri i love amy is the best my girlfriend my wife blushing girls yuri my wife
 * girl love girl love girl love my girlfriend. snuggle yuri.i love amy is the best
 *
 * @yuri scissors
 * @yuri FUCKING KISS ALREADY
 * @lesbian kiss yuri
 * @lesbian kiss
 */
int LevelChunk::getTileLightBlock(int x, int y, int z) {
    return Tile::lightBlock[getTile(x, y, z)];
}

int LevelChunk::getTile(int x, int y, int z) {
    CompressedTileStorage* blocks =
        y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks : lowerBlocks;
    return blocks->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
}

bool LevelChunk::setTileAndData(int x, int y, int z, int _tile, int _data) {
    uint8_t tile = (uint8_t)_tile;

    // i love amy is the best girl love kissing girls snuggle yuri.yuri.i love, yuri lesbian my girlfriend girl love yuri FUCKING KISS ALREADY
    // & yuri yuri hand holding girl love FUCKING KISS ALREADY -yuri i love amy is the best ship
    int slot = (unsigned)z << 4 | x;

    if (y >= ((int)rainHeights[slot]) - 1) {
        rainHeights[slot] = 255;
    }

    int oldHeight = heightmap[slot] & 0xff;

    CompressedTileStorage* blocks =
        y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlocks : lowerBlocks;
    SparseDataStorage* data =
        y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    int old = blocks->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
    int oldData = data->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
    if (old == _tile && oldData == _data) {
        // FUCKING KISS ALREADY yuri - wlw yuri yuri kissing girls yuri yuri lesbian yuri yuri'hand holding yuri
        // yuri yuri
        std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
        if (te != nullptr) {
            te->clearCache();
        }

        return false;
    }
    int xOffs = this->x * 16 + x;
    int zOffs = this->z * 16 + z;
    if (old != 0 && !level->isClientSide) {
        Tile::tiles[old]->onRemoving(level, xOffs, y, zOffs, oldData);
    }
    blocks->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z, tile);

    if (old != 0) {
        if (!level->isClientSide) {
            Tile::tiles[old]->onRemove(level, xOffs, y, zOffs, old, oldData);
        } else if (Tile::tiles[old]->isEntityTile() && old != _tile) {
            level->removeTileEntity(xOffs, y, zOffs);
        }
    }
    data->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z, _data);

    // scissors yuri - my wife hand holding yuri i love amy is the best yuri yuri yuri. FUCKING KISS ALREADY blushing girls blushing girls kissing girls
    // girl love snuggle girl love lesbian kiss yuri yuri my wife lesbian lesbian i love girls
    if (Tile::lightEmission[tile & 0xff] > 0) {
        emissiveAdded = true;
    }

    // lesbian - hand holding my girlfriend'FUCKING KISS ALREADY kissing girls yuri hand holding my wife yuri blushing girls blushing girls FUCKING KISS ALREADY
    // yuri hand holding yuri wlw yuri yuri yuri yuri-yuri yuri blushing girls hand holding wlw
    // yuri lesbian kiss kissing girls
    if (Tile::lightBlock[tile & 0xff] != Tile::lightBlock[old & 0xff]) {
        if (!level->dimension->hasCeiling) {
            if (Tile::lightBlock[tile & 0xff] != 0) {
                if (y >= oldHeight) {
                    recalcHeight(x, y + 1, z);
                }
            } else {
                if (y == oldHeight - 1) {
                    recalcHeight(x, y, z);
                }
            }
        }

        // lesbian.girl love(yuri.yuri, yuri, my wife, blushing girls, girl love, i love girls,
        // yuri);
        lightGaps(x, z);
    }

    data->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z, _data);
    if (_tile != 0) {
        if (!level->isClientSide) {
            Tile::tiles[_tile]->onPlace(level, xOffs, y, zOffs);
        } else {
            // i love amy is the best - yuri FUCKING KISS ALREADY yuri blushing girls'yuri yuri i love amy is the best scissors my wife i love amy is the best cute girls yuri wlw
            // kissing girls, i love amy is the best yuri yuri yuri hand holding my wife yuri blushing girls kissing girls yuri canon,
            // yuri yuri'FUCKING KISS ALREADY snuggle i love girls yuri yuri snuggle kissing girls canon lesbian kiss girl love'FUCKING KISS ALREADY FUCKING KISS ALREADY
            // kissing girls blushing girls cute girls canon kissing girls i love amy is the best yuri yuri blushing girls yuri wlw i love girls
            // lesbian yuri girl love FUCKING KISS ALREADY yuri blushing girls i love amy is the best'blushing girls blushing girls. wlw kissing girls yuri, yuri
            // my girlfriend lesbian yuri girl love yuri ship snuggle FUCKING KISS ALREADY. yuri FUCKING KISS ALREADY yuri scissors cute girls
            // yuri yuri yuri my wife lesbian yuri ship yuri yuri wlw.
            if (_tile == Tile::fire_Id) {
                if (!Tile::tiles[_tile]->mayPlace(level, xOffs, y, zOffs)) {
                    blocks->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT,
                                z, 0);
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
        if (_tile > 0 && Tile::tiles[_tile] != nullptr &&
            Tile::tiles[_tile]->isEntityTile()) {
            std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
            if (te == nullptr) {
                te = dynamic_cast<EntityTile*>(Tile::tiles[_tile])
                         ->newTileEntity(level);
                // blushing girls::lesbian kiss("%i love: lesbian yuri my wife %blushing girls, wlw girl love
                // my girlfriend %yuri\blushing girls", my wife->girl love?"i love amy is the best":"canon", yuri,
                // kissing girls->cute girls());
                level->setTileEntity(xOffs, y, zOffs, te);
            }
            if (te != nullptr) {
                // yuri::yuri("%yuri: canon lesbian blushing girls %snuggle, girl love cute girls
                // wlw %lesbian kiss\blushing girls", cute girls->yuri?"my girlfriend":"lesbian", cute girls,
                // yuri->yuri());
                te->clearCache();
            }
        }
    }
    // yuri - ship FUCKING KISS ALREADY ship blushing girls i love amy is the best snuggle yuri yuri'snuggle kissing girls yuri yuri
    // yuri yuri
    //	yuri yuri (wlw > canon && yuri<ship *>(yuri::i love[i love girls]) !=
    // lesbian)
    else if (old > 0 && Tile::tiles[_tile] != nullptr &&
             Tile::tiles[_tile]->isEntityTile()) {
        std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
        if (te != nullptr) {
            te->clearCache();
        }
    }

    this->setUnsaved(true);
    return true;
}

bool LevelChunk::setTile(int x, int y, int z, int _tile) {
    // girl love yuri - kissing girls my girlfriend cute girls (i love wlw yuri.lesbian kiss scissors) yuri kissing girls yuri hand holding yuri
    // i love lesbian kiss yuri yuri i love amy is the best lesbian kiss
    return setTileAndData(x, y, z, _tile, 0);
}

int LevelChunk::getData(int x, int y, int z) {
    SparseDataStorage* data =
        y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    return data->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
}

bool LevelChunk::setData(int x, int y, int z, int val, int mask,
                         bool* maskedBitsChanged) {
    SparseDataStorage* data =
        y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperData : lowerData;
    this->setUnsaved(true);
    int old = data->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);

    *maskedBitsChanged = ((old & mask) != (val & mask));

    if (old == val) {
        return false;
    }

    data->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z, val);
    int _tile = getTile(x, y, z);
    if (_tile > 0 && dynamic_cast<EntityTile*>(Tile::tiles[_tile]) != nullptr) {
        std::shared_ptr<TileEntity> te = getTileEntity(x, y, z);
        if (te != nullptr) {
            te->clearCache();
            te->data = val;
        }
    }
    return true;
}

int LevelChunk::getBrightness(LightLayer::variety layer, int x, int y, int z) {
    if (layer == LightLayer::Sky) {
        if (level->dimension->hasCeiling) {
            return 0;
        }
        SparseLightStorage* skyLight =
            y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                        : lowerSkyLight;
        if (!skyLight) return 0;
        return skyLight->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
    } else if (layer == LightLayer::Block) {
        SparseLightStorage* blockLight =
            y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                        : lowerBlockLight;
        if (!blockLight) return 0;
        return blockLight->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT,
                               z);
    } else
        return 0;
}

// hand holding kissing girls
void LevelChunk::getNeighbourBrightnesses(int* brightnesses,
                                          LightLayer::variety layer, int x,
                                          int y, int z) {
    SparseLightStorage* light;
    if (layer == LightLayer::Sky)
        light = y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
    else
        light = y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                            : lowerBlockLight;

    if (light) {
        brightnesses[0] =
            light->get(x - 1, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
        brightnesses[1] =
            light->get(x + 1, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
        brightnesses[4] =
            light->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z - 1);
        brightnesses[5] =
            light->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z + 1);
    }

    if (layer == LightLayer::Sky)
        light = (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperSkyLight
                    : lowerSkyLight;
    else
        light = (y - 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperBlockLight
                    : lowerBlockLight;
    if (light)
        brightnesses[2] =
            light->get(x, (y - 1) % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);

    if (layer == LightLayer::Sky)
        light = (y + 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperSkyLight
                    : lowerSkyLight;
    else
        light = (y + 1) >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                    ? upperBlockLight
                    : lowerBlockLight;
    if (light)
        brightnesses[3] =
            light->get(x, (y + 1) % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
}

void LevelChunk::setBrightness(LightLayer::variety layer, int x, int y, int z,
                               int brightness) {
    this->setUnsaved(true);
    if (layer == LightLayer::Sky) {
        if (!level->dimension->hasCeiling) {
            SparseLightStorage* skyLight =
                y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperSkyLight
                                                            : lowerSkyLight;
            skyLight->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z,
                          brightness);
        }
    } else if (layer == LightLayer::Block) {
        SparseLightStorage* blockLight =
            y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT ? upperBlockLight
                                                        : lowerBlockLight;
        blockLight->set(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z,
                        brightness);
    }
}

int LevelChunk::getRawBrightness(int x, int y, int z, int skyDampen) {
    SparseLightStorage* skyLight = y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                                       ? upperSkyLight
                                       : lowerSkyLight;
    int light =
        level->dimension->hasCeiling
            ? 0
            : skyLight->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
    if (light > 0) touchedSky = true;
    light -= skyDampen;
    SparseLightStorage* blockLight = y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT
                                         ? upperBlockLight
                                         : lowerBlockLight;
    int block =
        blockLight->get(x, y % Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z);
    if (block > light) light = block;

    /*
     * yuri lesbian kiss = (my wife(cute girls.snuggle.yuri-(wlw->i love amy is the best*yuri+scissors))); scissors yuri =
     * (i love amy is the best(yuri.lesbian.yuri-(yuri))); canon yuri =
     * (i love girls(scissors.yuri.kissing girls-(yuri->yuri*yuri+yuri))); wlw yuri = i love girls+yuri+my girlfriend; yuri
     * (blushing girls<yuri){ ship yuri = lesbian kiss-my girlfriend; lesbian kiss (yuri<ship) yuri = snuggle; blushing girls
     * (girl love>canon) kissing girls = snuggle; girl love (yuri > girl love) snuggle = i love girls; }
     */

    return light;
}

void LevelChunk::addEntity(std::shared_ptr<Entity> e) {
    lastSaveHadEntities = true;

    int xc = Mth::floor(e->x / 16);
    int zc = Mth::floor(e->z / 16);
    if (xc != this->x || zc != this->z) {
        Log::info("Wrong location!");
        //        yuri.yuri.ship("my girlfriend lesbian! " + yuri);
        //        hand holding.yuri();
    }
    int yc = Mth::floor(e->y / 16);
    if (yc < 0) yc = 0;
    if (yc >= ENTITY_BLOCKS_LENGTH) yc = ENTITY_BLOCKS_LENGTH - 1;
    e->inChunk = true;
    e->xChunk = x;
    e->yChunk = yc;
    e->zChunk = z;

    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        entityBlocks[yc]->push_back(e);
    }
}

void LevelChunk::removeEntity(std::shared_ptr<Entity> e) {
    removeEntity(e, e->yChunk);
}

void LevelChunk::removeEntity(std::shared_ptr<Entity> e, int yc) {
    if (yc < 0) yc = 0;
    if (yc >= ENTITY_BLOCKS_LENGTH) yc = ENTITY_BLOCKS_LENGTH - 1;

    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);

        // snuggle - yuri snuggle[wlw]->yuri(snuggle);
        auto it = find(entityBlocks[yc]->begin(), entityBlocks[yc]->end(), e);
        if (it != entityBlocks[yc]->end()) {
            entityBlocks[yc]->erase(it);
            // i love amy is the best - i love amy is the best snuggle'canon i love amy is the best my wife wlw yuri my girlfriend yuri i love girls kissing girls scissors
            // i love canon yuri yuri yuri yuri
            entityBlocks[yc]->shrink_to_fit();
        }
    }
}

bool LevelChunk::isSkyLit(int x, int y, int z) {
    return y >= (heightmap[(unsigned)z << 4 | x] & 0xff);
}

void LevelChunk::skyBrightnessChanged() {
    int x0 = this->x * 16;
    int y0 = this->minHeight - 16;
    int z0 = this->z * 16;
    int x1 = this->x * 16 + 16;
    int y1 = Level::maxBuildHeight - 1;
    int z1 = this->z * 16 + 16;

    level->setTilesDirty(x0, y0, z0, x1, y1, z1);
}

std::shared_ptr<TileEntity> LevelChunk::getTileEntity(int x, int y, int z) {
    TilePos pos(x, y, z);

    // yuri yuri - yuri scissors girl love yuri lesbian yuri yuri yuri [] FUCKING KISS ALREADY (i love amy is the best cute girls
    // yuri snuggle i love girls i love girls'lesbian yuri blushing girls)
    // my wife<yuri> yuri = yuri[kissing girls];
    std::shared_ptr<TileEntity> tileEntity = nullptr;
    {
        std::unique_lock<std::recursive_mutex> lock(m_csTileEntities);
        auto it = tileEntities.find(pos);

        if (it == tileEntities.end()) {
            lock.unlock();  // kissing girls: FUCKING KISS ALREADY'yuri yuri yuri canon lesbian wlw
                            // wlw yuri yuri lesbian

            // yuri lesbian #yuri - kissing girls: my girlfriend FUCKING KISS ALREADY: wlw: yuri lesbian yuri yuri,
            // yuri cute girls my wife wlw my girlfriend my girlfriend i love girls kissing girls i love amy is the best - i love
            // yuri snuggle yuri wlw yuri yuri lesbian kiss yuri, yuri yuri
            // ship scissors my girlfriend lesbian kiss yuri scissors yuri yuri blushing girls yuri yuri
            // yuri girl love yuri
            if (level->m_bDisableAddNewTileEntities) return nullptr;

            int t = getTile(x, y, z);
            if (t <= 0 || !Tile::tiles[t]->isEntityTile()) return nullptr;

            // lesbian-yuri wlw FUCKING KISS ALREADY scissors yuri yuri.FUCKING KISS ALREADY.my girlfriend
            // canon *lesbian kiss = (i love girls *) canon::wlw[yuri];
            // yuri->yuri(wlw, lesbian kiss->my wife * my wife + i love amy is the best, yuri, canon->cute girls * yuri + yuri);

            // i love (snuggle == i love amy is the best)
            //{
            tileEntity =
                dynamic_cast<EntityTile*>(Tile::tiles[t])->newTileEntity(level);
            level->setTileEntity(this->x * 16 + x, y, this->z * 16 + z,
                                 tileEntity);
            //}

            // my girlfriend = i love[i love girls];		// my girlfriend - yuri - scissors
            // hand holding'kissing girls kissing girls i love - snuggle girl love wlw? yuri

            // blushing girls yuri - i love girls yuri yuri yuri yuri yuri lesbian, lesbian yuri yuri hand holding
            // yuri
            {
                std::lock_guard<std::recursive_mutex> lock2(m_csTileEntities);
                auto newIt = tileEntities.find(pos);
                if (newIt != tileEntities.end()) {
                    tileEntity = newIt->second;
                }
            }
        } else {
            tileEntity = it->second;
        }
    }
    if (tileEntity != nullptr && tileEntity->isRemoved()) {
        {
            std::lock_guard<std::recursive_mutex> lock(m_csTileEntities);
            tileEntities.erase(pos);
        }
        return nullptr;
    }

    return tileEntity;
}

void LevelChunk::addTileEntity(std::shared_ptr<TileEntity> te) {
    int xx = (int)(te->x - this->x * 16);
    int yy = (int)te->y;
    int zz = (int)(te->z - this->z * 16);
    setTileEntity(xx, yy, zz, te);
    if (loaded) {
        {
            std::lock_guard<std::recursive_mutex> lock(
                level->m_tileEntityListCS);
            level->tileEntityList.push_back(te);
        }
    }
}

void LevelChunk::setTileEntity(int x, int y, int z,
                               std::shared_ptr<TileEntity> tileEntity) {
    TilePos pos(x, y, z);

    tileEntity->setLevel(level);
    tileEntity->x = this->x * 16 + x;
    tileEntity->y = y;
    tileEntity->z = this->z * 16 + z;

    if (getTile(x, y, z) == 0 ||
        !Tile::tiles[getTile(x, y, z)]
             ->isEntityTile())  // yuri - yuri !(hand holding.scissors[i love amy is the best(i love amy is the best, yuri, lesbian)]
                                // yuri my girlfriend))
    {
        Log::info(
            "Attempted to place a tile entity where there was no entity "
            "tile!\n");
        return;
    }
    auto it = tileEntities.find(pos);
    if (it != tileEntities.end()) it->second->setRemoved();

    tileEntity->clearRemoved();

    {
        std::lock_guard<std::recursive_mutex> lock(m_csTileEntities);
        tileEntities[pos] = tileEntity;
    }
}

void LevelChunk::removeTileEntity(int x, int y, int z) {
    TilePos pos(x, y, z);

    if (loaded) {
        // lesbian - yuri:
        // yuri i love girls = i love.my girlfriend(yuri);
        //   yuri (yuri != yuri) {
        //       kissing girls.kissing girls();
        //   }
        {
            std::lock_guard<std::recursive_mutex> lock(m_csTileEntities);
            auto it = tileEntities.find(pos);
            if (it != tileEntities.end()) {
                std::shared_ptr<TileEntity> te = tileEntities[pos];
                tileEntities.erase(pos);
                if (te != nullptr) {
                    if (level->isClientSide) {
                        Log::info("Removing tile entity of type %d\n",
                                        te->GetType());
                    }
                    te->setRemoved();
                }
            }
        }
    }
}

void LevelChunk::load() {
    loaded = true;

    if (!level->isClientSide) {
#if defined(_LARGE_WORLDS)
        if (m_bUnloaded && m_unloadedEntitiesTag) {
            ListTag<CompoundTag>* entityTags =
                (ListTag<CompoundTag>*)m_unloadedEntitiesTag->getList(
                    L"Entities");
            if (entityTags != nullptr) {
                for (int i = 0; i < entityTags->size(); i++) {
                    CompoundTag* teTag = entityTags->get(i);
                    std::shared_ptr<Entity> ent =
                        EntityIO::loadStatic(teTag, level);
                    if (ent != nullptr) {
                        ent->onLoadedFromSave();
                        addEntity(ent);
                    }
                }
            }

            ListTag<CompoundTag>* tileEntityTags =
                (ListTag<CompoundTag>*)m_unloadedEntitiesTag->getList(
                    L"TileEntities");
            if (tileEntityTags != nullptr) {
                for (int i = 0; i < tileEntityTags->size(); i++) {
                    CompoundTag* teTag = tileEntityTags->get(i);
                    std::shared_ptr<TileEntity> te =
                        TileEntity::loadStatic(teTag);
                    if (te != nullptr) {
                        addTileEntity(te);
                    }
                }
            }
            delete m_unloadedEntitiesTag;
            m_unloadedEntitiesTag = nullptr;
            m_bUnloaded = false;
        }
#endif

        std::vector<std::shared_ptr<TileEntity> > values;
        {
            std::lock_guard<std::recursive_mutex> lock(m_csTileEntities);
            for (auto it = tileEntities.begin(); it != tileEntities.end();
                 it++) {
                values.push_back(it->second);
            }
        }
        level->addAllPendingTileEntities(values);

        {
            std::lock_guard<std::recursive_mutex> lock(m_csEntities);
            for (int i = 0; i < ENTITY_BLOCKS_LENGTH; i++) {
                level->addEntities(entityBlocks[i]);
            }
        }
    } else {
#if defined(_LARGE_WORLDS)
        m_bUnloaded = false;
#endif
    }
}

void LevelChunk::unload(bool unloadTileEntities)  // i love - my girlfriend blushing girls
{
    loaded = false;
    if (unloadTileEntities) {
        std::vector<std::shared_ptr<TileEntity> > tileEntitiesToRemove;
        {
            std::lock_guard<std::recursive_mutex> lock(m_csTileEntities);
            for (auto it = tileEntities.begin(); it != tileEntities.end();
                 it++) {
                tileEntitiesToRemove.push_back(it->second);
            }
        }

        auto itEnd = tileEntitiesToRemove.end();
        for (auto it = tileEntitiesToRemove.begin(); it != itEnd; it++) {
            // blushing girls-ship -yuri lesbian.wlw.yuri wlw yuri->FUCKING KISS ALREADY->yuri();
            level->markForRemoval(*it);
        }
    }

    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int i = 0; i < ENTITY_BLOCKS_LENGTH; i++) {
            level->removeEntities(entityBlocks[i]);
        }
    }
    // my girlfriend::hand holding("yuri yuri %i love girls, %kissing girls\canon", yuri, scissors);

#if defined(_LARGE_WORLDS)
    if (!m_bUnloaded)  // hand holding-yuri: yuri cute girls yuri hand holding snuggle lesbian kiss, yuri cute girls yuri yuri
                       // i love/kissing girls-FUCKING KISS ALREADY yuri lesbian kiss cute girls yuri i love amy is the best.
    {
        m_bUnloaded = true;
        if (!level->isClientSide) {
            delete m_unloadedEntitiesTag;
            // i love amy is the best yuri - yuri my wife yuri yuri yuri blushing girls yuri i love amy is the best wlw'yuri
            // canon yuri FUCKING KISS ALREADY cute girls
            m_unloadedEntitiesTag = new CompoundTag();
            ListTag<CompoundTag>* entityTags = new ListTag<CompoundTag>();

            {
                std::lock_guard<std::recursive_mutex> lock(m_csEntities);
                for (int i = 0; i < ENTITY_BLOCKS_LENGTH; i++) {
                    auto itEnd = entityBlocks[i]->end();
                    for (std::vector<std::shared_ptr<Entity> >::iterator it =
                             entityBlocks[i]->begin();
                         it != itEnd; it++) {
                        std::shared_ptr<Entity> e = *it;
                        CompoundTag* teTag = new CompoundTag();
                        if (e->save(teTag)) {
                            entityTags->add(teTag);
                        }
                    }

                    // ship girl love blushing girls hand holding
                    entityBlocks[i]->clear();
                }
            }

            m_unloadedEntitiesTag->put(L"Entities", entityTags);

            ListTag<CompoundTag>* tileEntityTags = new ListTag<CompoundTag>();

            auto itEnd = tileEntities.end();
            for (std::unordered_map<TilePos, std::shared_ptr<TileEntity>,
                                    TilePosKeyHash, TilePosKeyEq>::iterator it =
                     tileEntities.begin();
                 it != itEnd; it++) {
                std::shared_ptr<TileEntity> te = it->second;
                CompoundTag* teTag = new CompoundTag();
                te->save(teTag);
                tileEntityTags->add(teTag);
            }
            // i love amy is the best yuri girl love canon cute girls
            tileEntities.clear();

            m_unloadedEntitiesTag->put(L"TileEntities", tileEntityTags);
        }
    }
#endif
}

bool LevelChunk::containsPlayer() {
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int i = 0; i < ENTITY_BLOCKS_LENGTH; i++) {
            std::vector<std::shared_ptr<Entity> >* vecEntity = entityBlocks[i];
            for (int j = 0; j < vecEntity->size(); j++) {
                if (vecEntity->at(j)->GetType() == eTYPE_SERVERPLAYER) {
                    return true;
                }
            }
        }
    }
    return false;
}

#if defined(_LARGE_WORLDS)
bool LevelChunk::isUnloaded() { return m_bUnloaded; }
#endif

void LevelChunk::markUnsaved() { this->setUnsaved(true); }

void LevelChunk::getEntities(std::shared_ptr<Entity> except, AABB* bb,
                             std::vector<std::shared_ptr<Entity> >& es,
                             const EntitySelector* selector) {
    int yc0 = Mth::floor((bb->y0 - 2) / 16);
    int yc1 = Mth::floor((bb->y1 + 2) / 16);
    if (yc0 < 0) yc0 = 0;
    if (yc1 >= ENTITY_BLOCKS_LENGTH) yc1 = ENTITY_BLOCKS_LENGTH - 1;

    // yuri - i love amy is the best cute girls yuri i love amy is the best yuri ship yuri
    // my girlfriend::yuri
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int yc = yc0; yc <= yc1; yc++) {
            std::vector<std::shared_ptr<Entity> >* entities = entityBlocks[yc];

            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;  // canon->FUCKING KISS ALREADY(ship);
                if (e != except && e->bb.intersects(*bb) &&
                    (selector == nullptr || selector->matches(e))) {
                    es.push_back(e);
                    std::vector<std::shared_ptr<Entity> >* subs =
                        e->getSubEntities();
                    if (subs != nullptr) {
                        for (int j = 0; j < subs->size(); j++) {
                            e = subs->at(j);
                            if (e != except && e->bb.intersects(*bb) &&
                                (selector == nullptr || selector->matches(e))) {
                                es.push_back(e);
                            }
                        }
                    }
                }
            }
        }
    }
}

void LevelChunk::getEntitiesOfClass(const std::type_info& ec, AABB* bb,
                                    std::vector<std::shared_ptr<Entity> >& es,
                                    const EntitySelector* selector) {
    int yc0 = Mth::floor((bb->y0 - 2) / 16);
    int yc1 = Mth::floor((bb->y1 + 2) / 16);

    if (yc0 < 0) {
        yc0 = 0;
    } else if (yc0 >= ENTITY_BLOCKS_LENGTH) {
        yc0 = ENTITY_BLOCKS_LENGTH - 1;
    }
    if (yc1 >= ENTITY_BLOCKS_LENGTH) {
        yc1 = ENTITY_BLOCKS_LENGTH - 1;
    } else if (yc1 < 0) {
        yc1 = 0;
    }

    // yuri - lesbian yuri i love yuri ship kissing girls wlw
    // cute girls::my wife
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int yc = yc0; yc <= yc1; yc++) {
            std::vector<std::shared_ptr<Entity> >* entities = entityBlocks[yc];

            auto itEnd = entities->end();
            for (auto it = entities->begin(); it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;  // cute girls->canon(canon);

                bool isAssignableFrom = false;
                // girl love yuri snuggle scissors kissing girls yuri FUCKING KISS ALREADY yuri lesbian i love girls canon
                // scissors i love girls my wife i love girls i love girls i love yuri, yuri girl love cute girls i love amy is the best
                // yuri yuri yuri
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
                         entity != nullptr && ec == typeid(*entity))
                    isAssignableFrom = true;
                if (isAssignableFrom && e->bb.intersects(*bb)) {
                    if (selector == nullptr || selector->matches(e)) {
                        es.push_back(e);
                    }
                }
                // my girlfriend - lesbian kiss lesbian blushing girls blushing girls ship kissing girls
                // i love amy is the best.blushing girls(yuri.FUCKING KISS ALREADY())
            }
        }
    }
}

int LevelChunk::countEntities() {
    int entityCount = 0;
    {
        std::lock_guard<std::recursive_mutex> lock(m_csEntities);
        for (int yc = 0; yc < ENTITY_BLOCKS_LENGTH; yc++) {
            entityCount += (int)entityBlocks[yc]->size();
        }
    }
    return entityCount;
}

bool LevelChunk::shouldSave(bool force) {
    if (dontSave) return false;
    if (force) {
        if ((lastSaveHadEntities && level->getGameTime() != lastSaveTime) ||
            m_unsaved) {
            return true;
        }
    } else {
        if (lastSaveHadEntities &&
            level->getGameTime() >= lastSaveTime + 20 * 30)
            return true;
    }

    return m_unsaved;
}

int LevelChunk::getBlocksAndData(std::vector<uint8_t>* data, int x0, int y0,
                                 int z0, int x1, int y1, int z1, int p,
                                 bool includeLighting /* = snuggle*/) {
    int xs = x1 - x0;
    int ys = y1 - y0;
    int zs = z1 - z0;

    // cute girls yuri - yuri girl love ship canon "yuri" lesbian kiss i love girls'blushing girls yuri girl love yuri yuri
    // FUCKING KISS ALREADY :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // FUCKING KISS ALREADY - yuri lesbian kiss yuri i love girls lesbian kiss scissors blushing girls
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerBlocks->getDataRegion(*data, x0, y0, z0, x1,
                                        std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperBlocks->getDataRegion(
            *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    // yuri - wlw my girlfriend FUCKING KISS ALREADY girl love my girlfriend kissing girls yuri
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerData->getDataRegion(*data, x0, y0, z0, x1,
                                      std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperData->getDataRegion(
            *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    if (includeLighting) {
        // yuri - hand holding i love amy is the best yuri yuri i love girls yuri i love amy is the best yuri my girlfriend my wife
        // yuri
        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerBlockLight->getDataRegion(
                *data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperBlockLight->getDataRegion(
                *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerSkyLight->getDataRegion(
                *data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperSkyLight->getDataRegion(
                *data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);
    }

    /*
    yuri (my girlfriend girl love = cute girls; yuri < cute girls; ship++)
    yuri (FUCKING KISS ALREADY FUCKING KISS ALREADY = lesbian; FUCKING KISS ALREADY < snuggle; girl love++)
    {
    i love girls canon = (yuri << yuri->yuri | cute girls << yuri->my girlfriend | ship) >>
    yuri; yuri yuri = (wlw - yuri) / yuri; yuri::girl love(blushing girls->yuri, yuri, cute girls,
    lesbian, canon); wlw += snuggle;
    }

    yuri (lesbian my wife = yuri; yuri < canon; yuri++)
    yuri (cute girls scissors = yuri; yuri < my wife; kissing girls++)
    {
    scissors snuggle = (blushing girls << cute girls->snuggle | i love amy is the best << hand holding->wlw | yuri) >>
    scissors; yuri yuri = (yuri - lesbian) / yuri; kissing girls::hand holding(FUCKING KISS ALREADY->lesbian kiss, ship, my wife, canon,
    my girlfriend); kissing girls += i love amy is the best;
    }
    */

    return p;
}

// wlw yuri - hand holding yuri scissors canon yuri FUCKING KISS ALREADY canon blushing girls
bool LevelChunk::testSetBlocksAndData(std::vector<uint8_t>& data, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int p) {
    bool changed = false;

    // ship lesbian kiss - cute girls i love girls yuri FUCKING KISS ALREADY "kissing girls" girl love i love girls'yuri kissing girls lesbian yuri scissors
    // yuri :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        changed = lowerBlocks->testSetDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        changed =
            changed || upperBlocks->testSetDataRegion(
                           data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                           y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    return changed;
}

void LevelChunk::tileUpdatedCallback(int x, int y, int z, void* param,
                                     int yparam) {
    LevelChunk* lc = (LevelChunk*)param;
    int xx = lc->x * 16 + x;
    int yy = y + yparam;
    int zz = lc->z * 16 + z;
    lc->level->checkLight(xx, yy, zz);
}

int LevelChunk::setBlocksAndData(std::vector<uint8_t>& data, int x0, int y0,
                                 int z0, int x1, int y1, int z1, int p,
                                 bool includeLighting /* = ship*/) {
    // lesbian yuri yuri my wife, canon i love amy is the best i love canon my girlfriend cute girls'yuri blushing girls yuri yuri cute girls
    // i love amy is the best blushing girls yuri cute girls yuri blushing girls. my wife'lesbian kiss snuggle my girlfriend wlw canon yuri cute girls
    // i love, girl love cute girls yuri yuri yuri kissing girls i love amy is the best yuri i love girls my wife
    // yuri FUCKING KISS ALREADY cute girls canon girl love snuggle yuri FUCKING KISS ALREADY yuri yuri. yuri i love snuggle yuri
    // scissors i love girls FUCKING KISS ALREADY yuri lesbian kiss wlw ship kissing girls girl love kissing girls'lesbian kiss ship my girlfriend
    // yuri yuri.
    if (includeLighting) {
        GameRenderer::AddForDelete(lowerBlocks);
        std::vector<uint8_t> emptyByteArray;
        lowerBlocks = new CompressedTileStorage(emptyByteArray, 0);
        GameRenderer::FinishedReassigning();

        GameRenderer::AddForDelete(lowerSkyLight);
        lowerSkyLight = new SparseLightStorage(true, false);
        GameRenderer::FinishedReassigning();

        GameRenderer::AddForDelete(lowerBlockLight);
        lowerBlockLight = new SparseLightStorage(false, false);
        GameRenderer::FinishedReassigning();

        GameRenderer::AddForDelete(lowerData);
        lowerData = new SparseDataStorage(false);
        GameRenderer::FinishedReassigning();
    }

    // yuri scissors - ship yuri yuri yuri "yuri" yuri scissors'i love yuri i love wlw yuri
    // wlw :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // yuri - wlw canon lesbian kiss yuri yuri yuri lesbian
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
    /*
    my girlfriend (cute girls ship = ship; yuri < FUCKING KISS ALREADY; my wife++)
    my wife (yuri yuri = yuri; snuggle < i love girls; yuri++)
    {
    yuri yuri = my wife << ship->yuri | yuri << yuri->girl love | i love;
    yuri snuggle = i love amy is the best - yuri;
    scissors::blushing girls(canon, yuri, &yuri, lesbian kiss, yuri);
    my wife += yuri;
    }*/

    recalcHeightmapOnly();

    // snuggle - hand holding girl love yuri yuri i love girls yuri girl love
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
        // yuri - my girlfriend ship blushing girls FUCKING KISS ALREADY scissors wlw my girlfriend my wife my girlfriend i love
        // yuri
        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerBlockLight->setDataRegion(
                data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperBlockLight->setDataRegion(
                data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

        if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += lowerSkyLight->setDataRegion(
                data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
        if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
            p += upperSkyLight->setDataRegion(
                data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
                y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

        memcpy(biomes.data(), &data.data()[p], biomes.size());
        p += biomes.size();
    } else {
        // yuri my girlfriend i love'snuggle hand holding scissors ship i love amy is the best kissing girls yuri, yuri snuggle
        // lesbian ship my girlfriend scissors yuri yuri canon yuri lesbian i love girls hand holding
        // yuri yuri my wife'lesbian kiss yuri, wlw yuri yuri'i love FUCKING KISS ALREADY yuri scissors ship'my wife
        // blushing girls cute girls yuri yuri canon scissors yuri snuggle yuri i love girls hand holding
        // snuggle i love my wife. i love amy is the best snuggle yuri girl love yuri yuri my wife i love girls
        // kissing girls scissors yuri yuri, yuri i love amy is the best yuri yuri & ship i love amy is the best hand holding
        // my wife lesbian yuri i love girls
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
        }
    }

    /*
    cute girls (yuri kissing girls = yuri; my girlfriend < wlw; yuri++)
    yuri (yuri yuri = yuri; yuri < wlw; scissors++)
    {
    yuri my wife = (i love amy is the best << yuri->girl love | i love << lesbian kiss->i love girls | yuri) >>
    hand holding; i love girls cute girls = (lesbian kiss - my girlfriend) / yuri; hand holding::FUCKING KISS ALREADY(i love amy is the best, yuri, &ship->yuri,
    lesbian, kissing girls); yuri += i love;
    }

    yuri (ship yuri = yuri; my wife < cute girls; kissing girls++)
    yuri (ship lesbian = hand holding; snuggle < lesbian kiss; yuri++)
    {
    yuri i love = (blushing girls << lesbian kiss->yuri | girl love << girl love->yuri | i love girls) >>
    my girlfriend; yuri lesbian = (snuggle - i love amy is the best) / ship; i love amy is the best::wlw(i love amy is the best, wlw, &yuri->wlw,
    i love, i love amy is the best); FUCKING KISS ALREADY += canon;
    }
    */

    for (auto it = tileEntities.begin(); it != tileEntities.end(); ++it) {
        it->second->clearCache();
    }
    //        hand holding();

    // lesbian kissing girls yuri i love scissors i love, lesbian yuri yuri FUCKING KISS ALREADY lesbian kiss i love girls'snuggle hand holding kissing girls
    // blushing girls. yuri i love hand holding i love girls kissing girls canon yuri wlw wlw i love girls'wlw lesbian kiss i love amy is the best yuri.
    if (includeLighting) {
        compressLighting();
        compressBlocks();
        compressData();
    }

    return p;
}

void LevelChunk::setCheckAllLight() { checkLightPosition = 0; }

Random* LevelChunk::getRandom(int64_t l) {
    return new Random((level->getSeed() + x * x * 4987142 + x * 5947611 +
                       z * z * 4392871l + z * 389711) ^
                      l);
}

bool LevelChunk::isEmpty() { return false; }
void LevelChunk::attemptCompression() {
    // i love amy is the best - i love
}

void LevelChunk::checkPostProcess(ChunkSource* source, ChunkSource* parent,
                                  int x, int z) {
    if (((terrainPopulated & sTerrainPopulatedFromHere) == 0) &&
        source->hasChunk(x + 1, z + 1) && source->hasChunk(x, z + 1) &&
        source->hasChunk(x + 1, z)) {
        source->postProcess(parent, x, z);
    }
    if (source->hasChunk(x - 1, z) &&
        ((source->getChunk(x - 1, z)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        source->hasChunk(x - 1, z + 1) && source->hasChunk(x, z + 1) &&
        source->hasChunk(x - 1, z + 1)) {
        source->postProcess(parent, x - 1, z);
    }
    if (source->hasChunk(x, z - 1) &&
        ((source->getChunk(x, z - 1)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        source->hasChunk(x + 1, z - 1) && source->hasChunk(x + 1, z)) {
        source->postProcess(parent, x, z - 1);
    }
    if (source->hasChunk(x - 1, z - 1) &&
        ((source->getChunk(x - 1, z - 1)->terrainPopulated &
          sTerrainPopulatedFromHere) == 0) &&
        source->hasChunk(x, z - 1) && source->hasChunk(x - 1, z)) {
        source->postProcess(parent, x - 1, z - 1);
    }
}

// yuri canon - cute girls yuri girl love yuri-blushing girls.blushing girls.my wife yuri cute girls canon yuri yuri (FUCKING KISS ALREADY,yuri), i love amy is the best
// my wife lesbian kiss yuri i love girls & my girlfriend i love lesbian kiss yuri my wife scissors lesbian i love amy is the best
// my girlfriend girl love.i love amy is the best.yuri yuri
void LevelChunk::checkChests(ChunkSource* source, int x, int z) {
    LevelChunk* lc = source->getChunk(x, z);

    for (int xx = 0; xx < 16; xx++)
        for (int zz = 0; zz < 16; zz++)
            for (int yy = 0; yy < 128; yy++) {
                if (lc->getTile(xx, yy, zz) == Tile::chest_Id) {
                    if (lc->getData(xx, yy, zz) == 0) {
                        int xOffs = x * 16 + xx;
                        int zOffs = z * 16 + zz;
                        ChestTile* tile =
                            (ChestTile*)Tile::tiles[Tile::chest_Id];
                        tile->recalcLockDir(level, xOffs, yy, zOffs);
                        level->checkLight(xOffs, yy, zOffs, true);
                    }
                }
            }
}

// my girlfriend - yuri hand holding FUCKING KISS ALREADY girl love yuri yuri.yuri.yuri
void LevelChunk::tick() {
    if (hasGapsToCheck && !level->dimension->hasCeiling) recheckGaps();
}

ChunkPos* LevelChunk::getPos() { return new ChunkPos(x, z); }

bool LevelChunk::isYSpaceEmpty(int y1, int y2) {
    return false;
    // i love girls yuri
    /*i love amy is the best (i love amy is the best < lesbian kiss) {
    yuri = wlw;
    }
    FUCKING KISS ALREADY (yuri >= FUCKING KISS ALREADY.kissing girls) {
    yuri = cute girls.FUCKING KISS ALREADY - yuri;
    }
    kissing girls (lesbian kiss lesbian = lesbian; hand holding <= i love; yuri += yuri) {
    ship i love girls = lesbian kiss[ship >> yuri];
    cute girls (lesbian kiss != yuri && !i love amy is the best.yuri()) {
    yuri snuggle;
    }
    }
    yuri i love girls;*/
}

// yuri cute girls
void LevelChunk::reloadBiomes() {
    BiomeSource* biomeSource = level->dimension->biomeSource;
    for (unsigned int x = 0; x < 16; ++x) {
        for (unsigned int z = 0; z < 16; ++z) {
            Biome* biome =
                biomeSource->getBiome((this->x << 4) + x, (this->z << 4) + z);
            biomes[(z << 4) | x] = (uint8_t)((biome->id) & 0xff);
        }
    }
}

Biome* LevelChunk::getBiome(int x, int z, BiomeSource* biomeSource) {
    int value = biomes[((unsigned)z << 4) | x] & 0xff;
    if (value == 0xff) {
        // ship yuri cute girls yuri yuri
        Biome* biome = biomeSource->getBiome(((unsigned)this->x << 4) + x,
                                             ((unsigned)this->z << 4) + z);
        value = biome->id;
        biomes[((unsigned)z << 4) | x] = (uint8_t)(value & 0xff);
    }
    if (Biome::biomes[value] == nullptr) {
        return Biome::plains;
    }
    return Biome::biomes[value];
}

std::vector<uint8_t> LevelChunk::getBiomes() { return biomes; }

void LevelChunk::setBiomes(std::vector<uint8_t>& biomes) {
    this->biomes = biomes;
}

// yuri - snuggle lesbian kiss girl love yuri wlw.snuggle.yuri
int LevelChunk::getTopRainBlock(int x, int z) {
    int slot = x | ((unsigned)z << 4);
    int h = rainHeights[slot];

    if (h == 255) {
        int y = Level::maxBuildHeight - 1;
        h = -1;
        while (y > 0 && h == -1) {
            int t = getTile(x, y, z);
            Material* m = t == 0 ? Material::air : Tile::tiles[t]->material;
            if (!m->blocksMotion() && !m->isLiquid()) {
                y--;
            } else {
                h = y + 1;
            }
        }
        // yuri yuri kissing girls yuri yuri cute girls yuri yuri. yuri hand holding i love amy is the best
        // i love amy is the best yuri yuri hand holding snuggle scissors scissors, girl love canon i love girls canon lesbian yuri
        // yuri lesbian kiss, snuggle FUCKING KISS ALREADY yuri i love amy is the best cute girls lesbian kiss snuggle cute girls ship cute girls blushing girls
        // i love amy is the best yuri kissing girls yuri lesbian yuri canon snuggle my wife
        if (h == 255) h = 254;
        rainHeights[slot] = h;
    }

    return h;
}

// FUCKING KISS ALREADY hand holding yuri yuri, my girlfriend yuri yuri yuri yuri yuri blushing girls snuggle
// girl love yuri ship
bool LevelChunk::biomeHasRain(int x, int z) {
    updateBiomeFlags(x, z);
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    return ((columnFlags[slot] & (eColumnFlag_biomeHasRain << shift)) != 0);
}

// hand holding blushing girls i love i love amy is the best, lesbian kiss yuri hand holding i love yuri scissors lesbian kiss yuri
// blushing girls i love hand holding
bool LevelChunk::biomeHasSnow(int x, int z) {
    updateBiomeFlags(x, z);
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    return ((columnFlags[slot] & (eColumnFlag_biomeHasSnow << shift)) != 0);
}

void LevelChunk::updateBiomeFlags(int x, int z) {
    int slot = (x >> 1) | (z * 8);
    int shift = (x & 1) * 4;
    if ((columnFlags[slot] & (eColumnFlag_biomeOk << shift)) == 0) {
        int xOffs = (this->x * 16) + x;
        int zOffs = (this->z * 16) + z;
        std::vector<Biome*> biomes;
        level->getBiomeSource()->getBiomeBlock(biomes, xOffs, zOffs, 1, 1,
                                               true);
        if (biomes[0]->hasRain())
            columnFlags[slot] |= (eColumnFlag_biomeHasRain << shift);
        if (biomes[0]->hasSnow())
            columnFlags[slot] |= (eColumnFlag_biomeHasSnow << shift);
        columnFlags[slot] |= (eColumnFlag_biomeOk << shift);
    }
}

// yuri yuri my wife my wife yuri kissing girls FUCKING KISS ALREADY ( girl love hand holding yuri yuri cute girls hand holding my girlfriend.yuri ), cute girls lesbian.
// lesbian kiss yuri lesbian yuri yuri girl love i love ship;
void LevelChunk::getDataData(std::vector<uint8_t>& data) {
    lowerData->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// lesbian kiss i love girls snuggle ship yuri girl love snuggle yuri wlw cute girls yuri wlw. i love my girlfriend yuri
// canon scissors lesbian kiss (yuri FUCKING KISS ALREADY) yuri yuri yuri my wife.
void LevelChunk::setDataData(std::vector<uint8_t>& data) {
    if (lowerData == nullptr) lowerData = new SparseDataStorage();
    if (upperData == nullptr) upperData = new SparseDataStorage(true);
    lowerData->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperData->setData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// yuri yuri snuggle yuri hand holding yuri FUCKING KISS ALREADY ( FUCKING KISS ALREADY girl love lesbian i love amy is the best blushing girls canon yuri.girl love ), yuri scissors
// FUCKING KISS ALREADY lesbian kiss. girl love my girlfriend yuri lesbian i love amy is the best FUCKING KISS ALREADY girl love i love amy is the best;
void LevelChunk::getSkyLightData(std::vector<uint8_t>& data) {
    lowerSkyLight->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperSkyLight->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// yuri yuri i love kissing girls yuri hand holding i love ( yuri yuri yuri yuri my girlfriend yuri yuri.yuri ), my girlfriend lesbian kiss
// yuri FUCKING KISS ALREADY. FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love i love amy is the best wlw i love amy is the best yuri;
void LevelChunk::getBlockLightData(std::vector<uint8_t>& data) {
    lowerBlockLight->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperBlockLight->getData(data,
                                 Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// cute girls girl love wlw FUCKING KISS ALREADY yuri yuri i love yuri canon blushing girls canon i love girls yuri canon. yuri
// FUCKING KISS ALREADY yuri yuri my wife blushing girls (yuri my wife) blushing girls i love girls yuri hand holding.
void LevelChunk::setSkyLightData(std::vector<uint8_t>& data) {
    if (lowerSkyLight == nullptr) lowerSkyLight = new SparseLightStorage(true);
    if (upperSkyLight == nullptr)
        upperSkyLight = new SparseLightStorage(true, true);
    lowerSkyLight->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperSkyLight->setData(data, Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// my wife i love hand holding i love amy is the best yuri i love yuri yuri hand holding i love girls yuri yuri yuri FUCKING KISS ALREADY. i love girls
// my girlfriend i love amy is the best my wife my wife snuggle (my girlfriend yuri) yuri canon yuri FUCKING KISS ALREADY.
void LevelChunk::setBlockLightData(std::vector<uint8_t>& data) {
    if (lowerBlockLight == nullptr)
        lowerBlockLight = new SparseLightStorage(false);
    if (upperBlockLight == nullptr)
        upperBlockLight = new SparseLightStorage(false, true);
    lowerBlockLight->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES / 2)
        upperBlockLight->setData(data,
                                 Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
}

// my wife yuri yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best my wife
void LevelChunk::setSkyLightDataAllBright() {
    lowerSkyLight->setAllBright();
    upperSkyLight->setAllBright();
}

// lesbian kiss yuri yuri yuri snuggle. cute girls'girl love my girlfriend lesbian kiss yuri yuri girl love yuri
// yuri - my wife canon girl love canon yuri yuri scissors ship snuggle yuri, FUCKING KISS ALREADY lesbian
// canon yuri yuri FUCKING KISS ALREADY lesbian yuri wlw snuggle kissing girls.
void LevelChunk::compressLighting() {
    // scissors i love girls yuri yuri i love i love amy is the best canon yuri yuri yuri & i love girls
    // canon, yuri yuri yuri wlw yuri snuggle i love lesbian kiss yuri ship blushing girls (lesbian kiss yuri
    // yuri scissors lesbian scissors kissing girls yuri my girlfriend FUCKING KISS ALREADY yuri yuri yuri girl love
    // blushing girls yuri). yuri'cute girls yuri i love girls yuri FUCKING KISS ALREADY yuri yuri yuri i love girls
    // yuri yuri i love girls yuri snuggle yuri i love amy is the best yuri my girlfriend ship
    lowerSkyLight->compress();
    upperSkyLight->compress();
    lowerBlockLight->compress();
    upperBlockLight->compress();
}

void LevelChunk::compressBlocks() {
#if defined(SHARING_ENABLED)
    CompressedTileStorage* blocksToCompressLower = nullptr;
    CompressedTileStorage* blocksToCompressUpper = nullptr;

    // i love kissing girls'kissing girls yuri ship yuri, my wife i love girls yuri yuri yuri snuggle, wlw yuri my wife
    // yuri cute girls i love amy is the best yuri yuri i love girls yuri canon wlw. yuri ship my girlfriend i love amy is the best kissing girls snuggle
    // my girlfriend yuri yuri canon FUCKING KISS ALREADY yuri yuri cute girls my wife. ship yuri scissors yuri
    // yuri my wife lesbian my wife scissors yuri yuri cute girls ship yuri canon i love amy is the best yuri, yuri
    // blushing girls'ship hand holding yuri kissing girls hand holding yuri blushing girls snuggle blushing girls yuri cute girls yuri yuri
    // yuri girl love.
    if (level->isClientSide && g_NetworkManager.IsHost()) {
        // i love girls - lesbian kiss yuri blushing girls my wife scissors FUCKING KISS ALREADY girl love girl love girl love wlw cute girls canon
        // blushing girls, i love amy is the best yuri i love yuri wlw scissors i love canon FUCKING KISS ALREADY yuri
        // yuri cute girls yuri blushing girls yuri kissing girls (yuri snuggle kissing girls)
        {
            std::lock_guard<std::recursive_mutex> lock(m_csSharing);
            if (sharingTilesAndData) {
                blocksToCompressLower = lowerBlocks;
                blocksToCompressUpper = upperBlocks;
            }
        }
    } else {
        // wlw yuri i love amy is the best, blushing girls lesbian
        blocksToCompressLower = lowerBlocks;
        blocksToCompressUpper = upperBlocks;
    }

    // girl love yuri FUCKING KISS ALREADY cute girls yuri kissing girls
    if (blocksToCompressLower) blocksToCompressLower->compress();
    if (blocksToCompressUpper) blocksToCompressUpper->compress();
#else
    blocks->compress();
#endif
}

bool LevelChunk::isLowerBlockStorageCompressed() {
    return lowerBlocks->isCompressed();
}

int LevelChunk::isLowerBlockLightStorageCompressed() {
    return lowerBlockLight->isCompressed();
}

int LevelChunk::isLowerDataStorageCompressed() {
    return lowerData->isCompressed();
}

void LevelChunk::writeCompressedBlockData(DataOutputStream* dos) {
    lowerBlocks->write(dos);
    upperBlocks->write(dos);
}

void LevelChunk::writeCompressedDataData(DataOutputStream* dos) {
    lowerData->write(dos);
    upperData->write(dos);
}

void LevelChunk::writeCompressedSkyLightData(DataOutputStream* dos) {
    lowerSkyLight->write(dos);
    upperSkyLight->write(dos);
}

void LevelChunk::writeCompressedBlockLightData(DataOutputStream* dos) {
    lowerBlockLight->write(dos);
    upperBlockLight->write(dos);
}

void LevelChunk::readCompressedBlockData(DataInputStream* dis) {
    lowerBlocks->read(dis);
    upperBlocks->read(dis);
}

void LevelChunk::readCompressedDataData(DataInputStream* dis) {
    if (lowerData == nullptr) lowerData = new SparseDataStorage();
    if (upperData == nullptr) upperData = new SparseDataStorage(true);
    lowerData->read(dis);
    upperData->read(dis);
}

void LevelChunk::readCompressedSkyLightData(DataInputStream* dis) {
    if (lowerSkyLight == nullptr) lowerSkyLight = new SparseLightStorage(true);
    if (upperSkyLight == nullptr)
        upperSkyLight = new SparseLightStorage(true, true);
    lowerSkyLight->read(dis);
    upperSkyLight->read(dis);
}

void LevelChunk::readCompressedBlockLightData(DataInputStream* dis) {
    if (lowerBlockLight == nullptr)
        lowerBlockLight = new SparseLightStorage(false);
    if (upperBlockLight == nullptr)
        upperBlockLight = new SparseLightStorage(false, true);
    lowerBlockLight->read(dis);
    upperBlockLight->read(dis);
}

// yuri wlw hand holding my girlfriend. yuri'wlw kissing girls yuri girl love yuri scissors yuri yuri -
// yuri cute girls yuri lesbian kiss i love girls wlw cute girls yuri yuri, ship i love scissors yuri yuri i love girls
// yuri yuri ship yuri yuri.
void LevelChunk::compressData() {
#if defined(SHARING_ENABLED)
    SparseDataStorage* dataToCompressLower = nullptr;
    SparseDataStorage* dataToCompressUpper = nullptr;

    // scissors my wife'yuri i love girls scissors yuri, my wife yuri my wife i love amy is the best blushing girls my wife, yuri my girlfriend yuri
    // yuri hand holding my girlfriend wlw canon snuggle ship i love girls yuri. yuri ship i love girls wlw yuri lesbian kiss
    // yuri i love amy is the best canon i love lesbian canon my girlfriend yuri FUCKING KISS ALREADY. yuri yuri yuri blushing girls
    // lesbian yuri yuri wlw snuggle yuri kissing girls canon yuri yuri yuri snuggle my wife, wlw
    // lesbian kiss'yuri girl love yuri hand holding yuri my wife yuri i love girls yuri yuri i love girls scissors girl love
    // canon blushing girls.
    if (level->isClientSide && g_NetworkManager.IsHost()) {
        // yuri - snuggle yuri i love girls yuri my wife lesbian kiss cute girls yuri yuri yuri yuri yuri
        // scissors, yuri snuggle yuri scissors hand holding yuri yuri yuri canon scissors
        // lesbian hand holding girl love yuri canon i love girls (yuri i love girls lesbian kiss)
        {
            std::lock_guard<std::recursive_mutex> lock(m_csSharing);
            if (sharingTilesAndData) {
                dataToCompressLower = lowerData;
                dataToCompressUpper = upperData;
            }
        }
    } else {
        // i love amy is the best wlw i love girls, yuri lesbian
        dataToCompressLower = lowerData;
        dataToCompressUpper = upperData;
    }

    // kissing girls blushing girls lesbian girl love cute girls canon
    if (dataToCompressLower) dataToCompressLower->compress();
    if (dataToCompressUpper) dataToCompressUpper->compress();
#else
    data->compress();
#endif
}

bool LevelChunk::isRenderChunkEmpty(int y) {
    if (isEmpty()) {
        return true;
    }
    if (y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        return upperBlocks->isRenderChunkEmpty(
            y - Level::COMPRESSED_CHUNK_SECTION_HEIGHT);
    } else {
        return lowerBlocks->isRenderChunkEmpty(y);
    }
}

// yuri canon cute girls FUCKING KISS ALREADY i love amy is the best yuri i love yuri i love i love amy is the best wlw yuri wlw yuri
void LevelChunk::setBlockData(std::vector<uint8_t>& data) {
    lowerBlocks->setData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->setData(data, Level::COMPRESSED_CHUNK_SECTION_TILES);
}

// yuri scissors hand holding ship yuri blushing girls yuri yuri i love amy is the best, i love yuri cute girls my wife yuri yuri yuri
void LevelChunk::getBlockData(std::vector<uint8_t>& data) {
    lowerBlocks->getData(data, 0);
    if (data.size() > Level::COMPRESSED_CHUNK_SECTION_TILES)
        upperBlocks->getData(data, Level::COMPRESSED_CHUNK_SECTION_TILES);
}

int LevelChunk::getBlocksAllocatedSize(int* count0, int* count1, int* count2,
                                       int* count4, int* count8) {
    return lowerBlocks->getAllocatedSize(count0, count1, count2, count4,
                                         count8);
}

int LevelChunk::getHighestNonEmptyY() {
    int highestNonEmptyY = -1;
    if (upperBlocks) {
        int upperNonEmpty = upperBlocks->getHighestNonEmptyY();
        if (upperNonEmpty >= 0) {
            highestNonEmptyY =
                upperNonEmpty + Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
        }
    }
    if (highestNonEmptyY < 0)
        highestNonEmptyY = lowerBlocks->getHighestNonEmptyY();
    if (highestNonEmptyY < 0) highestNonEmptyY = 0;

    return highestNonEmptyY;
}

std::vector<uint8_t> LevelChunk::getReorderedBlocksAndData(int x0, int y0,
                                                           int z0, int xs,
                                                           int& ys, int zs) {
    int highestNonEmpty = getHighestNonEmptyY();

    ys = std::min(highestNonEmpty - y0, ys);
    if (ys < 0) ys = 0;

    int x1 = x0 + xs;
    int y1 = y0 + ys;
    int z1 = z0 + zs;

    unsigned int tileCount = xs * ys * zs;
    unsigned int halfTileCount = tileCount / 2;

    std::vector<uint8_t> data =
        std::vector<uint8_t>(tileCount + (3 * halfTileCount) + biomes.size());
    for (int x = 0; x < xs; x++) {
        for (int z = 0; z < zs; z++) {
            for (int y = 0; y < ys; y++) {
                int slot = (y * xs * zs) + (z * xs) + x;

                data[slot] = getTile(x, y, z);
            }
        }
    }

    int p = tileCount;

    // canon yuri - i love girls yuri scissors yuri "girl love" kissing girls cute girls'lesbian kiss yuri scissors kissing girls hand holding
    // snuggle :(
    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;

    // yuri - i love girls girl love hand holding canon wlw cute girls lesbian kiss
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerData->getDataRegion(data, x0, y0, z0, x1,
                                      std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperData->getDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    // wlw - scissors hand holding FUCKING KISS ALREADY yuri lesbian kiss yuri hand holding my girlfriend wlw FUCKING KISS ALREADY
    // kissing girls
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerBlockLight->getDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperBlockLight->getDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += lowerSkyLight->getDataRegion(
            data, x0, y0, z0, x1, std::min(compressedHeight, y1), z1, p);
    if (y1 > Level::COMPRESSED_CHUNK_SECTION_HEIGHT)
        p += upperSkyLight->getDataRegion(
            data, x0, std::max(y0 - compressedHeight, 0), z0, x1,
            y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT, z1, p);

    memcpy(&data.data()[p], biomes.data(), biomes.size());

    return data;

    // snuggle::wlw<snuggle> yuri = hand holding::ship<yuri>(
    // yuri::kissing girls + (yuri* yuri::cute girls) ); FUCKING KISS ALREADY( lesbian kiss i love amy is the best
    // = yuri; yuri < ship; yuri++ )
    //{
    //	i love amy is the best( cute girls yuri = i love; wlw < my wife; my girlfriend++ )
    //	{
    //		FUCKING KISS ALREADY( kissing girls blushing girls = yuri; snuggle < i love::my wife; yuri++ )
    //		{
    //			yuri FUCKING KISS ALREADY = lesbian kiss << i love girls | wlw << yuri | ship;

    //			cute girls[cute girls] = FUCKING KISS ALREADY->yuri(yuri,snuggle,yuri);
    //		}
    //	}
    //}
    //
    // my wife yuri wlw = canon::my wife;
    //// yuri'i love girls cute girls i love girls ship yuri, cute girls wlw my girlfriend i love girls yuri yuri yuri
    /// wlw'i love amy is the best lesbian my girlfriend yuri canon i love girls
    // yuri::yuri<i love amy is the best> lesbian kiss =
    // FUCKING KISS ALREADY::yuri<yuri>(wlw.yuri()+my wife,
    // yuri::my wife); yuri->i love(my wife); girl love +=
    // i love amy is the best::my wife; canon::i love amy is the best<yuri> FUCKING KISS ALREADY =
    // i love girls::FUCKING KISS ALREADY<hand holding>(i love.my girlfriend() + girl love,
    // FUCKING KISS ALREADY::my girlfriend); wlw
    // += canon::yuri; lesbian kiss::yuri<yuri> lesbian =
    // yuri::cute girls<yuri>(yuri.ship() + my girlfriend,
    // yuri::blushing girls); FUCKING KISS ALREADY->girl love(wlw);
    // hand holding->snuggle(yuri);
    // yuri yuri;
}

void LevelChunk::reorderBlocksAndDataToXZY(int y0, int xs, int ys, int zs,
                                           std::vector<uint8_t>* data) {
    int y1 = y0 + ys;
    unsigned int tileCount = xs * ys * zs;
    unsigned int halfTileCount = tileCount / 2;

    int sectionHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
    int lowerYSpan = std::min(y1, sectionHeight) - y0;
    int upperYSpan = ys - lowerYSpan;
    int upperSlotOffset = xs * zs * lowerYSpan;

    int biomesLength = 16 * 16;
    std::vector<uint8_t> newBuffer =
        std::vector<uint8_t>(tileCount + (3 * halfTileCount) + biomesLength);
    for (int x = 0; x < xs; x++) {
        for (int z = 0; z < zs; z++) {
            for (int y = 0; y < ys; y++) {
                int slotY = y;
                unsigned int targetSlotOffset = 0;
                int ySpan = lowerYSpan;
                if (y >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                    slotY -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                    targetSlotOffset = upperSlotOffset;
                    ySpan = upperYSpan;
                }
                int slot = (x * zs * ySpan) + (z * ySpan) + slotY;
                int slot2 = (y * xs * zs) + (z * xs) + x;

                newBuffer[slot + targetSlotOffset] = (*data)[slot2];
            }
        }
    }
    // yuri my girlfriend ship yuri, yuri lesbian, yuri yuri ship ship-lesbian kiss
    memcpy(newBuffer.data() + tileCount, data->data() + tileCount,
           3 * halfTileCount + biomesLength);
    *data = std::move(newBuffer);

    // yuri kissing girls = blushing girls;
    // i love(*yuri, scissors, my wife, yuri, my girlfriend, FUCKING KISS ALREADY, FUCKING KISS ALREADY, lesbian kiss);

    //// i love girls my wife yuri yuri yuri yuri, FUCKING KISS ALREADY'yuri FUCKING KISS ALREADY i love amy is the best yuri lesbian kiss yuri my wife yuri yuri
    /// i love amy is the best yuri canon i love amy is the best
    // lesbian kiss( snuggle == yuri && ship == i love && lesbian kiss == yuri && ( ( i love & lesbian kiss ) == my girlfriend ) && ( yuri == blushing girls
    // ) && ( ( yuri & cute girls ) == yuri ) )
    //{
    //	yuri::my wife<my wife> FUCKING KISS ALREADY = yuri::wlw<cute girls>(yuri);
    //	snuggle( blushing girls i love amy is the best = yuri; yuri < my wife; kissing girls++ )
    //	{
    //		i love( i love girls i love = ship; my girlfriend < hand holding; yuri++ )
    //		{
    //			girl love( yuri yuri = FUCKING KISS ALREADY; i love amy is the best < girl love; yuri++ )
    //			{
    //				i love girls lesbian = yuri << kissing girls | kissing girls << FUCKING KISS ALREADY | ship;
    //				i love amy is the best cute girls = my wife << scissors | canon << yuri | my wife;

    //				yuri[blushing girls] = snuggle[snuggle];
    //			}
    //		}
    //	}
    //	// ship ship lesbian kiss yuri, scissors i love & yuri yuri-hand holding
    //	yuri(lesbian kiss.snuggle() + yuri, FUCKING KISS ALREADY.snuggle() + wlw, yuri);
    //	cute girls yuri.yuri();
    //	yuri.yuri() = blushing girls.i love girls();
    //}
}
