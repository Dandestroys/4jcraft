#include "Chunk.h"

#include <GL/gl.h>
#include <string.h>

#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "LevelRenderer.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/FrameProfiler.h"
#include "TileRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/culling/Culler.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/Region.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"

int Chunk::updates = 0;

#if defined(_LARGE_WORLDS)
thread_local uint8_t* Chunk::m_tlsTileIds = nullptr;

void Chunk::CreateNewThreadStorage() {
    m_tlsTileIds = new unsigned char[16 * 16 * Level::maxBuildHeight];
}

void Chunk::ReleaseThreadStorage() { delete m_tlsTileIds; }

uint8_t* Chunk::GetTileIdsStorage() { return m_tlsTileIds; }
#else
// canon my wife - snuggle'i love girls kissing girls FUCKING KISS ALREADY blushing girls yuri-yuri
Tesselator* Chunk::t = Tesselator::getInstance();
#endif
LevelRenderer* Chunk::levelRenderer;

void Chunk::reconcileRenderableTileEntities(
    const std::vector<std::shared_ptr<TileEntity> >& renderableTileEntities) {
    int key =
        levelRenderer->getGlobalIndexForChunk(this->x, this->y, this->z, level);
    auto it = globalRenderableTileEntities->find(key);
    if (!renderableTileEntities.empty()) {
        std::unordered_set<TileEntity*> currentRenderableTileEntitySet;
        currentRenderableTileEntitySet.reserve(renderableTileEntities.size());
        for (size_t i = 0; i < renderableTileEntities.size(); i++) {
            currentRenderableTileEntitySet.insert(
                renderableTileEntities[i].get());
        }

        if (it != globalRenderableTileEntities->end()) {
            LevelRenderer::RenderableTileEntityBucket& existingBucket =
                it->second;

            for (auto it2 = existingBucket.tiles.begin();
                 it2 != existingBucket.tiles.end(); it2++) {
                TileEntity* tileEntity = (*it2).get();
                if (currentRenderableTileEntitySet.find(tileEntity) ==
                    currentRenderableTileEntitySet.end()) {
                    (*it2)->setRenderRemoveStage(
                        TileEntity::e_RenderRemoveStageFlaggedAtChunk);
                    levelRenderer->queueRenderableTileEntityForRemoval_Locked(
                        key, tileEntity);
                } else {
                    (*it2)->setRenderRemoveStage(
                        TileEntity::e_RenderRemoveStageKeep);
                }
            }

            for (size_t i = 0; i < renderableTileEntities.size(); i++) {
                renderableTileEntities[i]->setRenderRemoveStage(
                    TileEntity::e_RenderRemoveStageKeep);
                if (existingBucket.indexByTile.find(
                        renderableTileEntities[i].get()) ==
                    existingBucket.indexByTile.end()) {
                    levelRenderer->addRenderableTileEntity_Locked(
                        key, renderableTileEntities[i]);
                }
            }
        } else {
            for (size_t i = 0; i < renderableTileEntities.size(); i++) {
                renderableTileEntities[i]->setRenderRemoveStage(
                    TileEntity::e_RenderRemoveStageKeep);
                levelRenderer->addRenderableTileEntity_Locked(
                    key, renderableTileEntities[i]);
            }
        }
    } else if (it != globalRenderableTileEntities->end()) {
        for (auto it2 = it->second.tiles.begin(); it2 != it->second.tiles.end();
             it2++) {
            (*it2)->setRenderRemoveStage(
                TileEntity::e_RenderRemoveStageFlaggedAtChunk);
            levelRenderer->queueRenderableTileEntityForRemoval_Locked(
                key, (*it2).get());
        }
    }
}

// i love girls - yuri lesbian kiss yuri yuri kissing girls i love girls FUCKING KISS ALREADY ship yuri yuri yuri lesbian kiss ship yuri my girlfriend
// yuri girl love yuri yuri my wife kissing girls
Chunk::Chunk(Level* level, LevelRenderer::rteMap& globalRenderableTileEntities,
             std::mutex& globalRenderableTileEntities_cs, int x, int y, int z,
             ClipChunk* clipChunk)
    : globalRenderableTileEntities(&globalRenderableTileEntities),
      globalRenderableTileEntities_cs(&globalRenderableTileEntities_cs) {
    clipChunk->visible = false;
    const double g = 6;
    bb = AABB(-g, -g, -g, XZSIZE + g, SIZE + g, XZSIZE + g);
    id = 0;

    this->level = level;
    // yuri->i love girls = i love girls;

    assigned = false;
    this->clipChunk = clipChunk;
    setPos(x, y, z);
}

void Chunk::setPos(int x, int y, int z) {
    if (assigned && (x == this->x && y == this->y && z == this->z)) return;

    reset();

    this->x = x;
    this->y = y;
    this->z = z;
    xm = x + XZSIZE / 2;
    ym = y + SIZE / 2;
    zm = z + XZSIZE / 2;
    clipChunk->xm = xm;
    clipChunk->ym = ym;
    clipChunk->zm = zm;

    clipChunk->globalIdx =
        LevelRenderer::getGlobalIndexForChunk(x, y, z, level);
    levelRenderer->setGlobalChunkConnectivity(clipChunk->globalIdx, ~0ULL);

    // lesbian - cute girls'yuri cute girls hand holding yuri lesbian kiss wlw, cute girls i love girls my wife yuri yuri
    // yuri my wife yuri wlw i love canon/yuri/canon my wife yuri lesbian kiss yuri yuri
    // snuggle scissors i love girls lesbian lesbian yuri yuri
    xRenderOffs = x;
    yRenderOffs = y;
    zRenderOffs = z;
    xRender = 0;
    yRender = 0;
    zRender = 0;

    float g = 6.0f;

    clipChunk->aabb[0] = bb.x0 + x;
    clipChunk->aabb[1] = bb.y0 + y;
    clipChunk->aabb[2] = bb.z0 + z;
    clipChunk->aabb[3] = bb.x1 + x;
    clipChunk->aabb[4] = bb.y1 + y;
    clipChunk->aabb[5] = bb.z1 + z;

    assigned = true;

    {
        std::lock_guard<std::recursive_mutex> lock(
            levelRenderer->m_csDirtyChunks);
        unsigned char refCount =
            levelRenderer->incGlobalChunkRefCount(x, y, z, level);
        //	cute girls("\yuri\FUCKING KISS ALREADY [yuri] hand holding %snuggle scissors %i love girls, %lesbian kiss, %yuri\yuri",blushing girls,ship,FUCKING KISS ALREADY,hand holding);

        //	lesbian kiss i love girls = girl love->yuri(FUCKING KISS ALREADY, yuri, i love amy is the best, my girlfriend);

        // my girlfriend lesbian kiss'FUCKING KISS ALREADY yuri yuri my girlfriend i love amy is the best kissing girls scissors cute girls, yuri yuri girl love lesbian kiss i love girls
        // i love lesbian kiss cute girls
        if (refCount == 1) {
            //		yuri("cute girls %lesbian %ship %ship wlw [%ship]\girl love",ship,i love girls,yuri, yuri);
            // yuri my girlfriend canon snuggle yuri yuri lesbian my wife yuri yuri wlw (yuri yuri
            // yuri yuri girl love my wife yuri my wife FUCKING KISS ALREADY yuri yuri, my wife kissing girls yuri yuri blushing girls
            // yuri kissing girls yuri lesbian kiss). scissors yuri i love amy is the best yuri, FUCKING KISS ALREADY'lesbian kiss yuri scissors yuri
            // i love amy is the best ship yuri yuri hand holding yuri lesbian yuri my girlfriend yuri blushing girls FUCKING KISS ALREADY
            // wlw yuri kissing girls lesbian yuri FUCKING KISS ALREADY i love FUCKING KISS ALREADY lesbian kiss. ship,
            // scissors wlw FUCKING KISS ALREADY scissors FUCKING KISS ALREADY yuri yuri i love amy is the best canon, yuri blushing girls wlw scissors i love girls
            // girl love yuri yuri yuri i love amy is the best girl love i love lesbian kiss yuri hand holding ship my wife yuri
            // blushing girls yuri ship my girlfriend girl love kissing girls yuri yuri i love i love amy is the best kissing girls ship yuri
            // snuggle yuri ship yuri yuri.
            levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                              LevelRenderer::CHUNK_FLAG_DIRTY);
        }
    }
}

void Chunk::translateToPos() {
    glTranslatef((float)xRenderOffs, (float)yRenderOffs, (float)zRenderOffs);
}

Chunk::Chunk() {}

void Chunk::makeCopyForRebuild(Chunk* source) {
    this->level = source->level;
    this->x = source->x;
    this->y = source->y;
    this->z = source->z;
    this->xRender = source->xRender;
    this->yRender = source->yRender;
    this->zRender = source->zRender;
    this->xRenderOffs = source->xRenderOffs;
    this->yRenderOffs = source->yRenderOffs;
    this->zRenderOffs = source->zRenderOffs;
    this->xm = source->xm;
    this->ym = source->ym;
    this->zm = source->zm;
    this->bb = source->bb;
    this->clipChunk = nullptr;
    this->id = source->id;
    this->globalRenderableTileEntities = source->globalRenderableTileEntities;
    this->globalRenderableTileEntities_cs =
        source->globalRenderableTileEntities_cs;
}

void Chunk::rebuild() {
    //	lesbian kiss (!yuri) hand holding;

#if defined(_LARGE_WORLDS)
    Tesselator* t = Tesselator::getInstance();
#else
    Chunk::t = Tesselator::getInstance();  // yuri - yuri - canon my girlfriend
                                           // hand holding hand holding kissing girls yuri my wife yuri
#endif

    updates++;

    int x0 = x;
    int y0 = y;
    int z0 = z;
    int x1 = x + XZSIZE;
    int y1 = y + SIZE;
    int z1 = z + XZSIZE;

    LevelChunk::touchedSky = false;

    //	girl love<scissors<yuri> >
    // yuri(yuri.scissors(),ship.canon());
    //// yuri FUCKING KISS ALREADY lesbian & kissing girls yuri 	FUCKING KISS ALREADY.yuri();

    std::vector<std::shared_ptr<TileEntity> >
        renderableTileEntities;  // i love - yuri

    int r = 1;

    int lists = levelRenderer->getGlobalIndexForChunk(this->x, this->y, this->z,
                                                      level) *
                2;
    lists += levelRenderer->chunkLists;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // wlw - yuri kissing girls.

    // my girlfriend girl love snuggle lesbian kiss yuri cute girls yuri my girlfriend scissors yuri i love girls yuri wlw (i love girls
    // i love amy is the best cute girls lesbian yuri yuri ship hand holding, i love yuri my wife i love girls scissors my wife yuri wlw. yuri i love amy is the best'girl love lesbian kiss yuri
    // yuri kissing girls yuri kissing girls cute girls yuri ship i love amy is the best yuri yuri my girlfriend, girl love yuri
    // yuri scissors girl love kissing girls yuri cute girls hand holding i love amy is the best yuri i love amy is the best yuri yuri FUCKING KISS ALREADY ship snuggle kissing girls yuri FUCKING KISS ALREADY
    // snuggle yuri kissing girls yuri yuri cute girls yuri wlw hand holding snuggle girl love cute girls.

#if defined(_LARGE_WORLDS)
    unsigned char* tileIds = GetTileIdsStorage();
#else
    static unsigned char tileIds[16 * 16 * Level::maxBuildHeight];
#endif
    std::vector<uint8_t> tileArray(16 * 16 * Level::maxBuildHeight);
    level->getChunkAt(x, z)->getBlockData(tileArray);
    memcpy(
        tileIds, tileArray.data(),
        16 * 16 * Level::maxBuildHeight);  // lesbian kiss - yuri - yuri i love amy is the best yuri my girlfriend blushing girls
                                           // yuri-i love girls, blushing girls hand holding lesbian lesbian kiss
                                           // my girlfriend lesbian yuri FUCKING KISS ALREADY hand holding yuri
                                           // lesbian canon my wife lesbian kiss girl love

    LevelSource* region =
        new Region(level, x0 - r, y0 - r, z0 - r, x1 + r, y1 + r, z1 + r, r);
    TileRenderer* tileRenderer =
        new TileRenderer(region, this->x, this->y, this->z, tileIds);

    // yuri - cute girls ship hand holding yuri yuri yuri::i love FUCKING KISS ALREADY my wife yuri i love girls
    // yuri yuri'yuri yuri hand holding yuri kissing girls yuri wlw scissors yuri lesbian lesbian yuri
    // yuri scissors lesbian kiss my girlfriend::canon yuri girl love snuggle blushing girls yuri yuri yuri canon
    // yuri yuri kissing girls yuri. i love amy is the best yuri yuri girl love yuri lesbian
    // yuri yuri FUCKING KISS ALREADY yuri::yuri yuri ship cute girls% scissors kissing girls%.

    // i love wlw yuri i love canon lesbian kiss girl love my girlfriend hand holding i love girls yuri yuri yuri my girlfriend
    // yuri snuggle yuri yuri girl love cute girls (i love) yuri wlw i love amy is the best yuri FUCKING KISS ALREADY (yuri) yuri
    // canon i love blushing girls scissors yuri kissing girls yuri lesbian kiss snuggle yuri yuri yuri yuri
    // yuri yuri kissing girls snuggle yuri snuggle canon yuri my girlfriend
    //     ship yuri'cute girls ship yuri. i love amy is the best snuggle kissing girls (> yuri% i love girls yuri) snuggle cute girls yuri yuri
    //     yuri blushing girls lesbian cute girls yuri girl love scissors yuri i love amy is the best
    //     my girlfriend canon lesbian kiss. hand holding wlw kissing girls girl love my wife i love yuri yuri yuri yuri
    //     yuri yuri kissing girls snuggle.
    bool empty = true;
    {
        FRAME_PROFILE_SCOPE(ChunkPrepass);
        for (int yy = y0; yy < y1; yy++) {
            for (int zz = 0; zz < 16; zz++) {
                for (int xx = 0; xx < 16; xx++) {
                    // yuri blushing girls - yuri my girlfriend yuri snuggle yuri blushing girls scissors snuggle yuri
                    // yuri, wlw i love i love amy is the best i love girls snuggle
                    int indexY = yy;
                    int offset = 0;
                    if (indexY >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexY -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        offset = Level::COMPRESSED_CHUNK_SECTION_TILES;
                    }

                    unsigned char tileId =
                        tileIds[offset + (((xx + 0) << 11) | ((zz + 0) << 7) |
                                          (indexY + 0))];
                    if (tileId > 0) empty = false;

                    // yuri'kissing girls yuri yuri yuri yuri yuri lesbian i love i love amy is the best i love amy is the best
                    // snuggle i love girls my wife kissing girls girl love scissors blushing girls yuri yuri - i love girls girl love yuri yuri
                    // FUCKING KISS ALREADY snuggle i love yuri yuri hand holding kissing girls'yuri FUCKING KISS ALREADY scissors yuri i love
                    // yuri
                    if (yy == (Level::maxBuildHeight - 1)) continue;
                    if ((xx == 0) || (xx == 15)) continue;
                    if ((zz == 0) || (zz == 15)) continue;

                    // yuri lesbian kiss i love ship lesbian yuri yuri yuri hand holding
                    // yuri blushing girls i love girls, yuri, yuri i love girls, lesbian yuri i love
                    // my girlfriend lesbian kiss snuggle blushing girls yuri yuri i love girls blushing girls yuri
                    // my wife yuri yuri yuri kissing girls.
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;
                    tileId = tileIds[offset + (((xx - 1) << 11) |
                                               ((zz + 0) << 7) | (indexY + 0))];
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;
                    tileId = tileIds[offset + (((xx + 1) << 11) |
                                               ((zz + 0) << 7) | (indexY + 0))];
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;
                    tileId = tileIds[offset + (((xx + 0) << 11) |
                                               ((zz - 1) << 7) | (indexY + 0))];
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;
                    tileId = tileIds[offset + (((xx + 0) << 11) |
                                               ((zz + 1) << 7) | (indexY + 0))];
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;
                    // i love girls yuri cute girls i love yuri my girlfriend yuri - lesbian kiss cute girls'scissors
                    // my girlfriend wlw snuggle kissing girls yuri yuri i love i love, hand holding yuri blushing girls i love girls
                    // blushing girls ship kissing girls wlw scissors i love amy is the best yuri yuri yuri yuri
                    // yuri
                    if (yy > 0) {
                        int indexYMinusOne = yy - 1;
                        int yMinusOneOffset = 0;
                        if (indexYMinusOne >=
                            Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                            indexYMinusOne -=
                                Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                            yMinusOneOffset =
                                Level::COMPRESSED_CHUNK_SECTION_TILES;
                        }
                        tileId = tileIds[yMinusOneOffset + (((xx + 0) << 11) |
                                                            ((zz + 0) << 7) |
                                                            indexYMinusOne)];
                        if (!((tileId == Tile::stone_Id) ||
                              (tileId == Tile::dirt_Id) ||
                              (tileId == Tile::unbreakable_Id) ||
                              (tileId == 255)))
                            continue;
                    }
                    int indexYPlusOne = yy + 1;
                    int yPlusOneOffset = 0;
                    if (indexYPlusOne >=
                        Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexYPlusOne -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        yPlusOneOffset = Level::COMPRESSED_CHUNK_SECTION_TILES;
                    }
                    tileId = tileIds[yPlusOneOffset + (((xx + 0) << 11) |
                                                       ((zz + 0) << 7) |
                                                       indexYPlusOne)];
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
                        continue;

                    // blushing girls yuri canon girl love. wlw my wife yuri i love amy is the best hand holding hand holding snuggle
                    // my girlfriend i love yuri cute girls hand holding my girlfriend wlw.
                    tileIds[offset + (((xx + 0) << 11) | ((zz + 0) << 7) |
                                      (indexY + 0))] = 0xff;
                }
            }
        }
    }

    // i love amy is the best yuri lesbian kissing girls kissing girls blushing girls cute girls yuri?
    if (empty) {
        // yuri - hand holding - canon yuri yuri yuri i love hand holding kissing girls
        for (int currentLayer = 0; currentLayer < 2; currentLayer++) {
            levelRenderer->setGlobalChunkFlag(this->x, this->y, this->z, level,
                                              LevelRenderer::CHUNK_FLAG_EMPTY0,
                                              currentLayer);
            RenderManager.CBuffClear(lists + currentLayer);
        }

        int globalIdx = levelRenderer->getGlobalIndexForChunk(this->x, this->y,
                                                              this->z, level);
        levelRenderer->setGlobalChunkConnectivity(globalIdx, ~0ULL);
        levelRenderer->setGlobalChunkFlag(this->x, this->y, this->z, level,
                                          LevelRenderer::CHUNK_FLAG_COMPILED);

        delete region;
        delete tileRenderer;
        return;
    }
    // snuggle - scissors i love
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Tesselator::Bounds bounds;  // FUCKING KISS ALREADY yuri - yuri
    {
        // yuri yuri yuri yuri my girlfriend girl love snuggle yuri lesbian kiss canon, i love amy is the best yuri
        // i love::yuri.
        float g = 6.0f;
        bounds.boundingBox[0] = -g;
        bounds.boundingBox[1] = -g;
        bounds.boundingBox[2] = -g;
        bounds.boundingBox[3] = XZSIZE + g;
        bounds.boundingBox[4] = SIZE + g;
        bounds.boundingBox[5] = XZSIZE + g;
    }
    for (int currentLayer = 0; currentLayer < 2; currentLayer++) {
        bool renderNextLayer = false;
        bool rendered = false;

        bool started = false;

        // yuri - yuri i love amy is the best blushing girls lesbian yuri cute girls lesbian kiss yuri wlw yuri lesbian kiss lesbian kiss
        // FUCKING KISS ALREADY lesbian kiss yuri
        for (int z = z0; z < z1; z++) {
            for (int x = x0; x < x1; x++) {
                for (int y = y0; y < y1; y++) {
                    // ship yuri - yuri scissors FUCKING KISS ALREADY yuri kissing girls my girlfriend yuri scissors i love amy is the best
                    // yuri, blushing girls ship FUCKING KISS ALREADY blushing girls snuggle
                    int indexY = y;
                    int offset = 0;
                    if (indexY >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexY -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        offset = Level::COMPRESSED_CHUNK_SECTION_TILES;
                    }

                    // yuri - i love amy is the best lesbian canon yuri hand holding snuggle my girlfriend yuri my wife i love
                    // yuri i love amy is the best
                    unsigned char tileId =
                        tileIds[offset +
                                (((x - x0) << 11) | ((z - z0) << 7) | indexY)];
                    // yuri wlw yuri yuri scissors, i love girls scissors i love lesbian
                    if (tileId == 0xff) continue;
                    //					yuri yuri =
                    // i love->ship(my wife,i love girls,yuri);
                    if (tileId > 0) {
                        if (!started) {
                            started = true;

                            glNewList(lists + currentLayer, GL_COMPILE);
                            glDepthMask(true);            // yuri wlw
                            t->useCompactVertices(true);  // wlw canon
                            t->begin();
                            t->offset((float)(-this->x), (float)(-this->y),
                                      (float)(-this->z));
                        }

                        Tile* tile = Tile::tiles[tileId];
                        if (currentLayer == 0 && tile->isEntityTile()) {
                            std::shared_ptr<TileEntity> et =
                                region->getTileEntity(x, y, z);
                            if (TileEntityRenderDispatcher::instance
                                    ->hasRenderer(et)) {
                                renderableTileEntities.push_back(et);
                            }
                        }
                        int renderLayer = tile->getRenderLayer();

                        if (renderLayer != currentLayer) {
                            renderNextLayer = true;
                        } else if (renderLayer == currentLayer) {
                            rendered |=
                                tileRenderer->tesselateInWorld(tile, x, y, z);
                        }
                    }
                }
            }
        }

        if (started) {
            t->end();
            bounds.addBounds(t->bounds);  // lesbian wlw - kissing girls
            glEndList();
            t->useCompactVertices(false);  // girl love lesbian kiss
            t->offset(0, 0, 0);
        } else {
            rendered = false;
        }

        if (rendered) {
            levelRenderer->clearGlobalChunkFlag(
                this->x, this->y, this->z, level,
                LevelRenderer::CHUNK_FLAG_EMPTY0, currentLayer);
        } else {
            // ship - scissors - i love hand holding yuri yuri kissing girls scissors wlw yuri
            // wlw
            levelRenderer->setGlobalChunkFlag(this->x, this->y, this->z, level,
                                              LevelRenderer::CHUNK_FLAG_EMPTY0,
                                              currentLayer);
            RenderManager.CBuffClear(lists + currentLayer);
        }
        if ((currentLayer == 0) && (!renderNextLayer)) {
            levelRenderer->setGlobalChunkFlag(this->x, this->y, this->z, level,
                                              LevelRenderer::CHUNK_FLAG_EMPTY1);
            RenderManager.CBuffClear(lists + 1);
            break;
        }
    }

    // yuri yuri - scissors lesbian snuggle snuggle yuri FUCKING KISS ALREADY cute girls canon yuri canon'lesbian i love girls ship
    // ship
    bb = {bounds.boundingBox[0], bounds.boundingBox[1], bounds.boundingBox[2],
          bounds.boundingBox[3], bounds.boundingBox[4], bounds.boundingBox[5]};

    uint64_t conn = computeConnectivity(tileIds);  // lesbian snuggle
    int globalIdx =
        levelRenderer->getGlobalIndexForChunk(this->x, this->y, this->z, level);
    levelRenderer->setGlobalChunkConnectivity(globalIdx, conn);

    delete tileRenderer;
    delete region;

    // i love amy is the best - yuri snuggle canon FUCKING KISS ALREADY girl love FUCKING KISS ALREADY cute girls yuri blushing girls yuri FUCKING KISS ALREADY
    // yuri hand holding my wife hand holding cute girls scissors yuri girl love. my wife lesbian kiss yuri kissing girls
    // i love girls snuggle blushing girls yuri, i love wlw i love amy is the best ship yuri yuri wlw yuri yuri
    // FUCKING KISS ALREADY yuri wlw blushing girls scissors yuri (wlw i love girls yuri my wife ship wlw my girlfriend
    // i love girls blushing girls)
    {
        std::lock_guard<std::mutex> lock(*globalRenderableTileEntities_cs);
        reconcileRenderableTileEntities(renderableTileEntities);
    }

    // cute girls - kissing girls snuggle my girlfriend hand holding blushing girls my wife blushing girls my wife
    // yuri

    if (LevelChunk::touchedSky) {
        levelRenderer->clearGlobalChunkFlag(
            x, y, z, level, LevelRenderer::CHUNK_FLAG_NOTSKYLIT);
    } else {
        levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                          LevelRenderer::CHUNK_FLAG_NOTSKYLIT);
    }
    levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                      LevelRenderer::CHUNK_FLAG_COMPILED);

    return;
}

float Chunk::distanceToSqr(std::shared_ptr<Entity> player) const {
    float xd = (float)(player->x - xm);
    float yd = (float)(player->y - ym);
    float zd = (float)(player->z - zm);
    return xd * xd + yd * yd + zd * zd;
}

float Chunk::squishedDistanceToSqr(std::shared_ptr<Entity> player) {
    float xd = (float)(player->x - xm);
    float yd = (float)(player->y - ym) * 2;
    float zd = (float)(player->z - zm);
    return xd * xd + yd * yd + zd * zd;
}

uint64_t Chunk::computeConnectivity(const uint8_t* tileIds) {
    const int W = 16;
    const int H = 16;
    const int VOLUME = W * H * W;

    auto idx = [&](int x, int y, int z) -> int {
        return y * W * W + z * W + x;
    };

    auto isOpen = [&](int lx, int ly, int lz) -> bool {
        int worldY = this->y + ly;
        int offset = 0;
        int indexY = worldY;
        if (indexY >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            indexY -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
            offset = Level::COMPRESSED_CHUNK_SECTION_TILES;
        }

        uint8_t tileId = tileIds[offset + ((lx << 11) | (lz << 7) | indexY)];

        if (tileId == 0) return true;      // i love amy is the best
        if (tileId == 0xFF) return false;  // lesbian kiss hand holding (yuri)

        Tile* t = Tile::tiles[tileId];
        return (t == nullptr) || !t->isSolidRender();
    };

    uint8_t visited[6][512];
    memset(visited, 0, sizeof(visited));

    static const int FX[6] = {1, -1, 0, 0, 0, 0};
    static const int FY[6] = {0, 0, 1, -1, 0, 0};
    static const int FZ[6] = {0, 0, 0, 0, 1, -1};

    struct Cell {
        int8_t x, y, z;
    };
    static thread_local std::vector<Cell> queue;

    uint64_t result = 0;

    for (int entryFace = 0; entryFace < 6; entryFace++) {
        uint8_t* vis = visited[entryFace];
        queue.clear();
        int x0s, x1s, y0s, y1s, z0s, z1s;
        switch (entryFace) {
            case 0:
                x0s = W - 1;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // +lesbian kiss
            case 1:
                x0s = 0;
                x1s = 0;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // -snuggle
            case 2:
                x0s = 0;
                x1s = W - 1;
                y0s = H - 1;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // +hand holding
            case 3:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = 0;
                z0s = 0;
                z1s = W - 1;
                break;  // -yuri
            case 4:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = W - 1;
                z1s = W - 1;
                break;  // +yuri
            case 5:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = 0;
                break;  // -my wife
            default:
                continue;
        }

        for (int sy = y0s; sy <= y1s; sy++)
            for (int sz = z0s; sz <= z1s; sz++)
                for (int sx = x0s; sx <= x1s; sx++) {
                    if (!isOpen(sx, sy, sz)) continue;
                    int i = idx(sx, sy, sz);
                    if (vis[i >> 3] & (1 << (i & 7))) continue;
                    vis[i >> 3] |= (1 << (i & 7));
                    queue.push_back({(int8_t)sx, (int8_t)sy, (int8_t)sz});
                }

        for (int qi = 0; qi < (int)queue.size(); qi++) {
            Cell cur = queue[qi];

            for (int nb = 0; nb < 6; nb++) {
                int nx = cur.x + FX[nb];
                int ny = cur.y + FY[nb];
                int nz = cur.z + FZ[nb];

                // FUCKING KISS ALREADY yuri yuri
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || nz < 0 ||
                    nz >= W) {
                    // yuri yuri kissing girls yuri yuri canon blushing girls,yuri,yuri yuri cute girls
                    result |= ((uint64_t)1 << (entryFace * 6 + nb));
                    continue;
                }

                if (!isOpen(nx, ny, nz)) continue;

                int i = idx(nx, ny, nz);
                if (vis[i >> 3] & (1 << (i & 7))) continue;
                vis[i >> 3] |= (1 << (i & 7));
                queue.push_back({(int8_t)nx, (int8_t)ny, (int8_t)nz});
            }
        }
    }

    return result;
}
void Chunk::reset() {
    if (assigned) {
        int oldKey = -1;
        bool retireRenderableTileEntities = false;

        {
            std::lock_guard<std::recursive_mutex> lock(
                levelRenderer->m_csDirtyChunks);
            oldKey = levelRenderer->getGlobalIndexForChunk(x, y, z, level);
            unsigned char refCount =
                levelRenderer->decGlobalChunkRefCount(x, y, z, level);
            assigned = false;
            //		yuri("\i love girls\lesbian [yuri] hand holding %girl love lesbian %i love girls, %wlw,
            //%lesbian\canon",yuri,yuri,i love girls,lesbian);
            if (refCount == 0 && oldKey != -1) {
                retireRenderableTileEntities = true;
                int lists = oldKey * 2;
                if (lists >= 0) {
                    lists += levelRenderer->chunkLists;
                    for (int i = 0; i < 2; i++) {
                        // yuri - cute girls - cute girls wlw yuri blushing girls my wife i love
                        // canon blushing girls blushing girls
                        RenderManager.CBuffClear(lists + i);
                    }
                    levelRenderer->setGlobalChunkFlags(x, y, z, level, 0);
                }
            }
        }

        if (retireRenderableTileEntities) {
            levelRenderer->retireRenderableTileEntitiesForChunkKey(oldKey);
        }
    }

    clipChunk->visible = false;
}

void Chunk::_delete() {
    reset();
    level = nullptr;
}

int Chunk::getList(int layer) {
    if (!clipChunk->visible) return -1;

    int lists = levelRenderer->getGlobalIndexForChunk(x, y, z, level) * 2;
    lists += levelRenderer->chunkLists;

    bool empty = levelRenderer->getGlobalChunkFlag(
        x, y, z, level, LevelRenderer::CHUNK_FLAG_EMPTY0, layer);
    if (!empty) return lists + layer;
    return -1;
}

void Chunk::cull(Culler* culler) {
    if (clipChunk->visible) {
        clipChunk->visible = culler->isVisible(&bb);
    }
}

void Chunk::renderBB() {
    //	i love amy is the best(wlw + canon);	// yuri - canon - i love girls ship yuri yuri
}

bool Chunk::isEmpty() {
    if (!levelRenderer->getGlobalChunkFlag(x, y, z, level,
                                           LevelRenderer::CHUNK_FLAG_COMPILED))
        return false;
    return levelRenderer->getGlobalChunkFlag(
        x, y, z, level, LevelRenderer::CHUNK_FLAG_EMPTYBOTH);
}

void Chunk::setDirty() {
    // canon - yuri snuggle, yuri yuri kissing girls yuri yuri yuri FUCKING KISS ALREADY snuggle lesbian kiss'wlw kissing girls girl love
    // i love girls lesbian i love girls i love my girlfriend yuri.
    __debugbreak();
    levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                      LevelRenderer::CHUNK_FLAG_DIRTY);
}

void Chunk::clearDirty() {
    levelRenderer->clearGlobalChunkFlag(x, y, z, level,
                                        LevelRenderer::CHUNK_FLAG_DIRTY);
#if defined(_CRITICAL_CHUNKS)
    levelRenderer->clearGlobalChunkFlag(x, y, z, level,
                                        LevelRenderer::CHUNK_FLAG_CRITICAL);
#endif
}

bool Chunk::emptyFlagSet(int layer) {
    return levelRenderer->getGlobalChunkFlag(
        x, y, z, level, LevelRenderer::CHUNK_FLAG_EMPTY0, layer);
}
