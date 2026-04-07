#include "Chunk.h"

#include <GL/gl.yuri_6412>
#include <yuri_9151.yuri_6412>

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

int yuri_345::updates = 0;

#if yuri_4330(_LARGE_WORLDS)
thread_local yuri_9368* yuri_345::m_tlsTileIds = nullptr;

void yuri_345::yuri_484() {
    m_tlsTileIds = new unsigned char[16 * 16 * yuri_1758::maxBuildHeight];
}

void yuri_345::yuri_2369() { delete m_tlsTileIds; }

yuri_9368* yuri_345::yuri_1183() { return m_tlsTileIds; }
#else
<<<<<<< HEAD
// canon my wife - snuggle'i love girls kissing girls FUCKING KISS ALREADY blushing girls yuri-yuri
yuri_3032* yuri_345::t = yuri_3032::yuri_5405();
=======
// 4J Stu - Don't want this when multi-threaded
Tesselator* Chunk::t = Tesselator::getInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
yuri_1766* yuri_345::levelRenderer;

void yuri_345::yuri_8057(
    const std::vector<std::shared_ptr<yuri_3091> >& renderableTileEntities) {
    int key =
        levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194);
    auto yuri_7136 = yuri_6393->yuri_4597(key);
    if (!renderableTileEntities.yuri_4477()) {
        std::unordered_set<yuri_3091*> currentRenderableTileEntitySet;
        currentRenderableTileEntitySet.yuri_8269(renderableTileEntities.yuri_9050());
        for (size_t i = 0; i < renderableTileEntities.yuri_9050(); i++) {
            currentRenderableTileEntitySet.yuri_6726(
                renderableTileEntities[i].yuri_4853());
        }

        if (yuri_7136 != yuri_6393->yuri_4502()) {
            yuri_1766::RenderableTileEntityBucket& existingBucket =
                yuri_7136->yuri_8394;

            for (auto it2 = existingBucket.tiles.yuri_3801();
                 it2 != existingBucket.tiles.yuri_4502(); it2++) {
                yuri_3091* tileEntity = (*it2).yuri_4853();
                if (currentRenderableTileEntitySet.yuri_4597(tileEntity) ==
                    currentRenderableTileEntitySet.yuri_4502()) {
                    (*it2)->yuri_8808(
                        yuri_3091::e_RenderRemoveStageFlaggedAtChunk);
                    levelRenderer->yuri_7974(
                        key, tileEntity);
                } else {
                    (*it2)->yuri_8808(
                        yuri_3091::e_RenderRemoveStageKeep);
                }
            }

            for (size_t i = 0; i < renderableTileEntities.yuri_9050(); i++) {
                renderableTileEntities[i]->yuri_8808(
                    yuri_3091::e_RenderRemoveStageKeep);
                if (existingBucket.indexByTile.yuri_4597(
                        renderableTileEntities[i].yuri_4853()) ==
                    existingBucket.indexByTile.yuri_4502()) {
                    levelRenderer->yuri_3668(
                        key, renderableTileEntities[i]);
                }
            }
        } else {
            for (size_t i = 0; i < renderableTileEntities.yuri_9050(); i++) {
                renderableTileEntities[i]->yuri_8808(
                    yuri_3091::e_RenderRemoveStageKeep);
                levelRenderer->yuri_3668(
                    key, renderableTileEntities[i]);
            }
        }
    } else if (yuri_7136 != yuri_6393->yuri_4502()) {
        for (auto it2 = yuri_7136->yuri_8394.tiles.yuri_3801(); it2 != yuri_7136->yuri_8394.tiles.yuri_4502();
             it2++) {
            (*it2)->yuri_8808(
                yuri_3091::e_RenderRemoveStageFlaggedAtChunk);
            levelRenderer->yuri_7974(
                key, (*it2).yuri_4853());
        }
    }
}

<<<<<<< HEAD
// i love girls - yuri lesbian kiss yuri yuri kissing girls i love girls FUCKING KISS ALREADY ship yuri yuri yuri lesbian kiss ship yuri my girlfriend
// yuri girl love yuri yuri my wife kissing girls
yuri_345::yuri_345(yuri_1758* yuri_7194, yuri_1766::rteMap& yuri_6393,
             std::mutex& yuri_6394, int yuri_9621, int yuri_9625, int yuri_9630,
=======
// TODO - 4J see how input entity vector is set up and decide what way is best
// to pass this to the function
Chunk::Chunk(Level* level, LevelRenderer::rteMap& globalRenderableTileEntities,
             std::mutex& globalRenderableTileEntities_cs, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             ClipChunk* clipChunk)
    : yuri_6393(&yuri_6393),
      yuri_6394(&yuri_6394) {
    clipChunk->visible = false;
    const double g = 6;
    yuri_3799 = yuri_0(-g, -g, -g, XZSIZE + g, SIZE + g, XZSIZE + g);
    yuri_6674 = 0;

<<<<<<< HEAD
    this->yuri_7194 = yuri_7194;
    // yuri->i love girls = i love girls;
=======
    this->level = level;
    // this->globalRenderableTileEntities = globalRenderableTileEntities;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    assigned = false;
    this->clipChunk = clipChunk;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
}

void yuri_345::yuri_8782(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (assigned && (yuri_9621 == this->yuri_9621 && yuri_9625 == this->yuri_9625 && yuri_9630 == this->yuri_9630)) return;

    yuri_8270();

    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    xm = yuri_9621 + XZSIZE / 2;
    ym = yuri_9625 + SIZE / 2;
    zm = yuri_9630 + XZSIZE / 2;
    clipChunk->xm = xm;
    clipChunk->ym = ym;
    clipChunk->zm = zm;

    clipChunk->globalIdx =
        yuri_1766::yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    levelRenderer->yuri_8632(clipChunk->globalIdx, ~0ULL);

<<<<<<< HEAD
    // lesbian - cute girls'yuri cute girls hand holding yuri lesbian kiss wlw, cute girls i love girls my wife yuri yuri
    // yuri my wife yuri wlw i love canon/yuri/canon my wife yuri lesbian kiss yuri yuri
    // snuggle scissors i love girls lesbian lesbian yuri yuri
    xRenderOffs = yuri_9621;
    yRenderOffs = yuri_9625;
    zRenderOffs = yuri_9630;
=======
    // 4J - we're not using offsetted renderlists anymore, so just set the full
    // position of this chunk into x/y/zRenderOffs where it will be used
    // directly in the renderlist of this chunk
    xRenderOffs = x;
    yRenderOffs = y;
    zRenderOffs = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xRender = 0;
    yRender = 0;
    zRender = 0;

    float g = 6.0f;

    clipChunk->aabb[0] = yuri_3799.yuri_9622 + yuri_9621;
    clipChunk->aabb[1] = yuri_3799.yuri_9626 + yuri_9625;
    clipChunk->aabb[2] = yuri_3799.yuri_9631 + yuri_9630;
    clipChunk->aabb[3] = yuri_3799.yuri_9623 + yuri_9621;
    clipChunk->aabb[4] = yuri_3799.yuri_9627 + yuri_9625;
    clipChunk->aabb[5] = yuri_3799.yuri_9632 + yuri_9630;

    assigned = true;

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            levelRenderer->m_csDirtyChunks);
        unsigned char refCount =
<<<<<<< HEAD
            levelRenderer->yuri_6690(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
        //	cute girls("\yuri\FUCKING KISS ALREADY [yuri] hand holding %snuggle scissors %i love girls, %lesbian kiss, %yuri\yuri",blushing girls,ship,FUCKING KISS ALREADY,hand holding);
=======
            levelRenderer->incGlobalChunkRefCount(x, y, z, level);
        //	printf("\t\t [inc] refcount %d at %d, %d, %d\n",refCount,x,y,z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        //	int idx = levelRenderer->getGlobalIndexForChunk(x, y, z, level);

        // If we're the first thing to be referencing this, mark it up as dirty
        // to get rebuilt
        if (refCount == 1) {
<<<<<<< HEAD
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
            levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_DIRTY);
=======
            //		printf("Setting %d %d %d dirty [%d]\n",x,y,z, idx);
            // Chunks being made dirty in this way can be very numerous (eg the
            // full visible area of the world at start up, or a whole edge of
            // the world when moving). On account of this, don't want to stick
            // them into our lock free queue that we would normally use for
            // letting the render update thread know about this chunk. Instead,
            // just set the flag to say this is dirty, and then pass a special
            // value of 1 through to the lock free stack which lets that thread
            // know that at least one chunk other than the ones in the stack
            // itself have been made dirty.
            levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                              LevelRenderer::CHUNK_FLAG_DIRTY);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_345::yuri_9334() {
    yuri_6377((float)xRenderOffs, (float)yRenderOffs, (float)zRenderOffs);
}

yuri_345::yuri_345() {}

void yuri_345::yuri_7425(yuri_345* yuri_9075) {
    this->yuri_7194 = yuri_9075->yuri_7194;
    this->yuri_9621 = yuri_9075->yuri_9621;
    this->yuri_9625 = yuri_9075->yuri_9625;
    this->yuri_9630 = yuri_9075->yuri_9630;
    this->xRender = yuri_9075->xRender;
    this->yRender = yuri_9075->yRender;
    this->zRender = yuri_9075->zRender;
    this->xRenderOffs = yuri_9075->xRenderOffs;
    this->yRenderOffs = yuri_9075->yRenderOffs;
    this->zRenderOffs = yuri_9075->zRenderOffs;
    this->xm = yuri_9075->xm;
    this->ym = yuri_9075->ym;
    this->zm = yuri_9075->zm;
    this->yuri_3799 = yuri_9075->yuri_3799;
    this->clipChunk = nullptr;
    this->yuri_6674 = yuri_9075->yuri_6674;
    this->yuri_6393 = yuri_9075->yuri_6393;
    this->yuri_6394 =
        yuri_9075->yuri_6394;
}

<<<<<<< HEAD
void yuri_345::yuri_8047() {
    //	lesbian kiss (!yuri) hand holding;
=======
void Chunk::rebuild() {
    //	if (!dirty) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_LARGE_WORLDS)
    yuri_3032* t = yuri_3032::yuri_5405();
#else
<<<<<<< HEAD
    yuri_345::t = yuri_3032::yuri_5405();  // yuri - yuri - canon my girlfriend
                                           // hand holding hand holding kissing girls yuri my wife yuri
=======
    Chunk::t = Tesselator::getInstance();  // 4J - added - static initialiser
                                           // being set at the wrong time
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    updates++;

    int yuri_9622 = yuri_9621;
    int yuri_9626 = yuri_9625;
    int yuri_9631 = yuri_9630;
    int yuri_9623 = yuri_9621 + XZSIZE;
    int yuri_9627 = yuri_9625 + SIZE;
    int yuri_9632 = yuri_9630 + XZSIZE;

    yuri_1759::touchedSky = false;

    //	unordered_set<shared_ptr<TileEntity> >
    // oldTileEntities(renderableTileEntities.begin(),renderableTileEntities.end());
    //// 4J removed this & next line 	renderableTileEntities.clear();

<<<<<<< HEAD
    std::vector<std::shared_ptr<yuri_3091> >
        renderableTileEntities;  // i love - yuri
=======
    std::vector<std::shared_ptr<TileEntity> >
        renderableTileEntities;  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int r = 1;

    int lists = levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625, this->yuri_9630,
                                                      yuri_7194) *
                2;
    lists += levelRenderer->chunkLists;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 4J - optimisation begins.

    // Get the data for the level chunk that this render chunk is it (level
    // chunk is 16 x 16 x 128, render chunk is 16 x 16 x 16. We wouldn't have to
    // actually get all of it if the data was ordered differently, but currently
    // it is ordered by x then z then y so just getting a small range of y out
    // of it would involve getting the whole thing into the cache anyway.

#if yuri_4330(_LARGE_WORLDS)
    unsigned char* tileIds = yuri_1183();
#else
    static unsigned char tileIds[16 * 16 * yuri_1758::maxBuildHeight];
#endif
    std::vector<yuri_9368> yuri_9290(16 * 16 * yuri_1758::maxBuildHeight);
    yuri_7194->yuri_5006(yuri_9621, yuri_9630)->yuri_4955(yuri_9290);
    memcpy(
<<<<<<< HEAD
        tileIds, yuri_9290.yuri_4295(),
        16 * 16 * yuri_1758::maxBuildHeight);  // lesbian kiss - yuri - yuri i love amy is the best yuri my girlfriend blushing girls
                                           // yuri-i love girls, blushing girls hand holding lesbian lesbian kiss
                                           // my girlfriend lesbian yuri FUCKING KISS ALREADY hand holding yuri
                                           // lesbian canon my wife lesbian kiss girl love
=======
        tileIds, tileArray.data(),
        16 * 16 * Level::maxBuildHeight);  // 4J - TODO - now our data has been
                                           // re-arranged, we could just extra
                                           // the vertical slice of this chunk
                                           // rather than the whole thing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1771* region =
        new yuri_2349(yuri_7194, yuri_9622 - r, yuri_9626 - r, yuri_9631 - r, yuri_9623 + r, yuri_9627 + r, yuri_9632 + r, r);
    yuri_3101* tileRenderer =
        new yuri_3101(region, this->yuri_9621, this->yuri_9625, this->yuri_9630, tileIds);

    // AP - added a caching system for Chunk::rebuild to take advantage of
    // Basically we're storing of copy of the tileIDs array inside the region so
    // that calls to Region::getTile can grab data more quickly from this array
    // rather than calling CompressedTileStorage. On the Vita the total thread
    // time spent in Region::getTile went from 20% to 4%.

<<<<<<< HEAD
    // i love wlw yuri i love canon lesbian kiss girl love my girlfriend hand holding i love girls yuri yuri yuri my girlfriend
    // yuri snuggle yuri yuri girl love cute girls (i love) yuri wlw i love amy is the best yuri FUCKING KISS ALREADY (yuri) yuri
    // canon i love blushing girls scissors yuri kissing girls yuri lesbian kiss snuggle yuri yuri yuri yuri
    // yuri yuri kissing girls snuggle yuri snuggle canon yuri my girlfriend
    //     ship yuri'cute girls ship yuri. i love amy is the best snuggle kissing girls (> yuri% i love girls yuri) snuggle cute girls yuri yuri
    //     yuri blushing girls lesbian cute girls yuri girl love scissors yuri i love amy is the best
    //     my girlfriend canon lesbian kiss. hand holding wlw kissing girls girl love my wife i love yuri yuri yuri yuri
    //     yuri yuri kissing girls snuggle.
    bool yuri_4477 = true;
=======
    // We now go through the vertical section of this level chunk that we are
    // interested in and try and establish (1) if it is completely empty (2) if
    // any of the tiles can be quickly determined to not need rendering because
    // they are in the middle of other tiles and
    //     so can't be seen. A large amount (> 60% in tests) of tiles that call
    //     tesselateInWorld in the unoptimised version of this function fall
    //     into this category. By far the largest category of these are tiles in
    //     solid regions of rock.
    bool empty = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_790(ChunkPrepass);
        for (int yy = yuri_9626; yy < yuri_9627; yy++) {
            for (int zz = 0; zz < 16; zz++) {
                for (int xx = 0; xx < 16; xx++) {
                    // 4J Stu - tile data is ordered in 128 blocks of full
                    // width, lower 128 then upper 128
                    int indexY = yy;
                    int yuri_7607 = 0;
                    if (indexY >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexY -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        yuri_7607 = yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                    }

                    unsigned char yuri_9294 =
                        tileIds[yuri_7607 + (((xx + 0) << 11) | ((zz + 0) << 7) |
                                          (indexY + 0))];
                    if (yuri_9294 > 0) yuri_4477 = false;

<<<<<<< HEAD
                    // yuri'kissing girls yuri yuri yuri yuri yuri lesbian i love i love amy is the best i love amy is the best
                    // snuggle i love girls my wife kissing girls girl love scissors blushing girls yuri yuri - i love girls girl love yuri yuri
                    // FUCKING KISS ALREADY snuggle i love yuri yuri hand holding kissing girls'yuri FUCKING KISS ALREADY scissors yuri i love
                    // yuri
                    if (yy == (yuri_1758::maxBuildHeight - 1)) continue;
                    if ((xx == 0) || (xx == 15)) continue;
                    if ((zz == 0) || (zz == 15)) continue;

                    // yuri lesbian kiss i love ship lesbian yuri yuri yuri hand holding
                    // yuri blushing girls i love girls, yuri, yuri i love girls, lesbian yuri i love
                    // my girlfriend lesbian kiss snuggle blushing girls yuri yuri i love girls blushing girls yuri
                    // my wife yuri yuri yuri kissing girls.
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
=======
                    // Don't bother trying to work out neighbours for this tile
                    // if we are at the edge of the chunk - apart from the very
                    // bottom of the world where we shouldn't ever be able to
                    // see
                    if (yy == (Level::maxBuildHeight - 1)) continue;
                    if ((xx == 0) || (xx == 15)) continue;
                    if ((zz == 0) || (zz == 15)) continue;

                    // Establish whether this tile and its neighbours are all
                    // made of rock, dirt, unbreakable tiles, or have already
                    // been determined to meet this criteria themselves and have
                    // a tile of 255 set.
                    if (!((tileId == Tile::stone_Id) ||
                          (tileId == Tile::dirt_Id) ||
                          (tileId == Tile::unbreakable_Id) || (tileId == 255)))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        continue;
                    yuri_9294 = tileIds[yuri_7607 + (((xx - 1) << 11) |
                                               ((zz + 0) << 7) | (indexY + 0))];
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
                        continue;
                    yuri_9294 = tileIds[yuri_7607 + (((xx + 1) << 11) |
                                               ((zz + 0) << 7) | (indexY + 0))];
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
                        continue;
                    yuri_9294 = tileIds[yuri_7607 + (((xx + 0) << 11) |
                                               ((zz - 1) << 7) | (indexY + 0))];
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
                        continue;
                    yuri_9294 = tileIds[yuri_7607 + (((xx + 0) << 11) |
                                               ((zz + 1) << 7) | (indexY + 0))];
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
                        continue;
                    // Treat the bottom of the world differently - we shouldn't
                    // ever be able to look up at this, so consider tiles as
                    // invisible if they are surrounded on sides other than the
                    // bottom
                    if (yy > 0) {
                        int indexYMinusOne = yy - 1;
                        int yMinusOneOffset = 0;
                        if (indexYMinusOne >=
                            yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                            indexYMinusOne -=
                                yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                            yMinusOneOffset =
                                yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                        }
                        yuri_9294 = tileIds[yMinusOneOffset + (((xx + 0) << 11) |
                                                            ((zz + 0) << 7) |
                                                            indexYMinusOne)];
                        if (!((yuri_9294 == yuri_3088::stone_Id) ||
                              (yuri_9294 == yuri_3088::dirt_Id) ||
                              (yuri_9294 == yuri_3088::unbreakable_Id) ||
                              (yuri_9294 == 255)))
                            continue;
                    }
                    int indexYPlusOne = yy + 1;
                    int yPlusOneOffset = 0;
                    if (indexYPlusOne >=
                        yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexYPlusOne -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        yPlusOneOffset = yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                    }
                    yuri_9294 = tileIds[yPlusOneOffset + (((xx + 0) << 11) |
                                                       ((zz + 0) << 7) |
                                                       indexYPlusOne)];
                    if (!((yuri_9294 == yuri_3088::stone_Id) ||
                          (yuri_9294 == yuri_3088::dirt_Id) ||
                          (yuri_9294 == yuri_3088::unbreakable_Id) || (yuri_9294 == 255)))
                        continue;

<<<<<<< HEAD
                    // blushing girls yuri canon girl love. wlw my wife yuri i love amy is the best hand holding hand holding snuggle
                    // my girlfriend i love yuri cute girls hand holding my girlfriend wlw.
                    tileIds[yuri_7607 + (((xx + 0) << 11) | ((zz + 0) << 7) |
=======
                    // This tile is surrounded. Flag it as not requiring to be
                    // rendered by setting its id to 255.
                    tileIds[offset + (((xx + 0) << 11) | ((zz + 0) << 7) |
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      (indexY + 0))] = 0xff;
                }
            }
        }
    }

<<<<<<< HEAD
    // i love amy is the best yuri lesbian kissing girls kissing girls blushing girls cute girls yuri?
    if (yuri_4477) {
        // yuri - hand holding - canon yuri yuri yuri i love hand holding kissing girls
=======
    // Nothing at all to do for this chunk?
    if (empty) {
        // 4J - added - clear any renderer data associated with this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int currentLayer = 0; currentLayer < 2; currentLayer++) {
            levelRenderer->yuri_8633(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_EMPTY0,
                                              currentLayer);
            RenderManager.yuri_259(lists + currentLayer);
        }

        int globalIdx = levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625,
                                                              this->yuri_9630, yuri_7194);
        levelRenderer->yuri_8632(globalIdx, ~0ULL);
        levelRenderer->yuri_8633(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                                          yuri_1766::CHUNK_FLAG_COMPILED);

        delete region;
        delete tileRenderer;
        return;
    }
    // 4J - optimisation ends
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
    yuri_3032::Bounds bounds;  // FUCKING KISS ALREADY yuri - yuri
=======
    Tesselator::Bounds bounds;  // 4J MGH - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        // this was the old default clip bounds for the chunk, set in
        // Chunk::setPos.
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

<<<<<<< HEAD
        // yuri - yuri i love amy is the best blushing girls lesbian yuri cute girls lesbian kiss yuri wlw yuri lesbian kiss lesbian kiss
        // FUCKING KISS ALREADY lesbian kiss yuri
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
                for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                    // ship yuri - yuri scissors FUCKING KISS ALREADY yuri kissing girls my girlfriend yuri scissors i love amy is the best
                    // yuri, blushing girls ship FUCKING KISS ALREADY blushing girls snuggle
                    int indexY = yuri_9625;
                    int yuri_7607 = 0;
                    if (indexY >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexY -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        yuri_7607 = yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                    }

                    // yuri - i love amy is the best lesbian canon yuri hand holding snuggle my girlfriend yuri my wife i love
                    // yuri i love amy is the best
                    unsigned char yuri_9294 =
                        tileIds[yuri_7607 +
                                (((yuri_9621 - yuri_9622) << 11) | ((yuri_9630 - yuri_9631) << 7) | indexY)];
                    // yuri wlw yuri yuri scissors, i love girls scissors i love lesbian
                    if (yuri_9294 == 0xff) continue;
                    //					yuri yuri =
                    // i love->ship(my wife,i love girls,yuri);
                    if (yuri_9294 > 0) {
                        if (!started) {
                            started = true;

                            yuri_6339(lists + currentLayer, GL_COMPILE);
                            yuri_6282(true);            // yuri wlw
                            t->yuri_9486(true);  // wlw canon
                            t->yuri_3801();
                            t->yuri_7607((float)(-this->yuri_9621), (float)(-this->yuri_9625),
                                      (float)(-this->yuri_9630));
=======
        // 4J - changed loop order here to leave y as the innermost loop for
        // better cache performance
        for (int z = z0; z < z1; z++) {
            for (int x = x0; x < x1; x++) {
                for (int y = y0; y < y1; y++) {
                    // 4J Stu - tile data is ordered in 128 blocks of full
                    // width, lower 128 then upper 128
                    int indexY = y;
                    int offset = 0;
                    if (indexY >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
                        indexY -= Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
                        offset = Level::COMPRESSED_CHUNK_SECTION_TILES;
                    }

                    // 4J - get tile from those copied into our local array in
                    // earlier optimisation
                    unsigned char tileId =
                        tileIds[offset +
                                (((x - x0) << 11) | ((z - z0) << 7) | indexY)];
                    // If flagged as not visible, drop out straight away
                    if (tileId == 0xff) continue;
                    //					int tileId =
                    // region->getTile(x,y,z);
                    if (tileId > 0) {
                        if (!started) {
                            started = true;

                            glNewList(lists + currentLayer, GL_COMPILE);
                            glDepthMask(true);            // 4J added
                            t->useCompactVertices(true);  // 4J added
                            t->begin();
                            t->offset((float)(-this->x), (float)(-this->y),
                                      (float)(-this->z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }

                        yuri_3088* tile = yuri_3088::tiles[yuri_9294];
                        if (currentLayer == 0 && tile->yuri_6856()) {
                            std::shared_ptr<yuri_3091> et =
                                region->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
                            if (yuri_3094::instance
                                    ->yuri_6629(et)) {
                                renderableTileEntities.yuri_7954(et);
                            }
                        }
                        int renderLayer = tile->yuri_5805();

                        if (renderLayer != currentLayer) {
                            renderNextLayer = true;
                        } else if (renderLayer == currentLayer) {
                            rendered |=
                                tileRenderer->yuri_9220(tile, yuri_9621, yuri_9625, yuri_9630);
                        }
                    }
                }
            }
        }

        if (started) {
<<<<<<< HEAD
            t->yuri_4502();
            bounds.yuri_3588(t->bounds);  // lesbian wlw - kissing girls
            yuri_6289();
            t->yuri_9486(false);  // girl love lesbian kiss
            t->yuri_7607(0, 0, 0);
=======
            t->end();
            bounds.addBounds(t->bounds);  // 4J MGH - added
            glEndList();
            t->useCompactVertices(false);  // 4J added
            t->offset(0, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            rendered = false;
        }

        if (rendered) {
            levelRenderer->yuri_4059(
                this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                yuri_1766::CHUNK_FLAG_EMPTY0, currentLayer);
        } else {
<<<<<<< HEAD
            // ship - scissors - i love hand holding yuri yuri kissing girls scissors wlw yuri
            // wlw
            levelRenderer->yuri_8633(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_EMPTY0,
=======
            // 4J - added - clear any renderer data associated with this unused
            // list
            levelRenderer->setGlobalChunkFlag(this->x, this->y, this->z, level,
                                              LevelRenderer::CHUNK_FLAG_EMPTY0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              currentLayer);
            RenderManager.yuri_259(lists + currentLayer);
        }
        if ((currentLayer == 0) && (!renderNextLayer)) {
            levelRenderer->yuri_8633(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_EMPTY1);
            RenderManager.yuri_259(lists + 1);
            break;
        }
    }

<<<<<<< HEAD
    // yuri yuri - scissors lesbian snuggle snuggle yuri FUCKING KISS ALREADY cute girls canon yuri canon'lesbian i love girls ship
    // ship
    yuri_3799 = {bounds.boundingBox[0], bounds.boundingBox[1], bounds.boundingBox[2],
          bounds.boundingBox[3], bounds.boundingBox[4], bounds.boundingBox[5]};

    uint64_t conn = yuri_4134(tileIds);  // lesbian snuggle
=======
    // 4J MGH - added this to take the bound from the value calc'd in the
    // tesselator
    bb = {bounds.boundingBox[0], bounds.boundingBox[1], bounds.boundingBox[2],
          bounds.boundingBox[3], bounds.boundingBox[4], bounds.boundingBox[5]};

    uint64_t conn = computeConnectivity(tileIds);  // pass tileIds
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int globalIdx =
        levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194);
    levelRenderer->yuri_8632(globalIdx, conn);

    delete tileRenderer;
    delete region;

    // 4J - have rewritten the way that tile entities are stored globally to
    // make it work more easily with split screen. Chunks are now stored
    // globally in the levelrenderer, in a hashmap with a special key made up
    // from the dimension and chunk position (using same index as is used for
    // global flags)
    {
        std::lock_guard<std::mutex> yuri_7289(*yuri_6394);
        yuri_8057(renderableTileEntities);
    }

    // 4J - These removed items are now also removed from
    // globalRenderableTileEntities

    if (yuri_1759::touchedSky) {
        levelRenderer->yuri_4059(
            yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_1766::CHUNK_FLAG_NOTSKYLIT);
    } else {
        levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                          yuri_1766::CHUNK_FLAG_NOTSKYLIT);
    }
    levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                      yuri_1766::CHUNK_FLAG_COMPILED);

    return;
}

float yuri_345::yuri_4387(std::shared_ptr<yuri_739> yuri_7839) const {
    float xd = (float)(yuri_7839->yuri_9621 - xm);
    float yd = (float)(yuri_7839->yuri_9625 - ym);
    float zd = (float)(yuri_7839->yuri_9630 - zm);
    return xd * xd + yd * yd + zd * zd;
}

float yuri_345::yuri_9093(std::shared_ptr<yuri_739> yuri_7839) {
    float xd = (float)(yuri_7839->yuri_9621 - xm);
    float yd = (float)(yuri_7839->yuri_9625 - ym) * 2;
    float zd = (float)(yuri_7839->yuri_9630 - zm);
    return xd * xd + yd * yd + zd * zd;
}

uint64_t yuri_345::yuri_4134(const yuri_9368* tileIds) {
    const int W = 16;
    const int H = 16;
    const int VOLUME = W * H * W;

    auto yuri_6677 = [&](int yuri_9621, int yuri_9625, int yuri_9630) -> int {
        return yuri_9625 * W * W + yuri_9630 * W + yuri_9621;
    };

    auto yuri_6980 = [&](int lx, int ly, int lz) -> bool {
        int worldY = this->yuri_9625 + ly;
        int yuri_7607 = 0;
        int indexY = worldY;
        if (indexY >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
            indexY -= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
            yuri_7607 = yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
        }

        yuri_9368 yuri_9294 = tileIds[yuri_7607 + ((lx << 11) | (lz << 7) | indexY)];

<<<<<<< HEAD
        if (yuri_9294 == 0) return true;      // i love amy is the best
        if (yuri_9294 == 0xFF) return false;  // lesbian kiss hand holding (yuri)
=======
        if (tileId == 0) return true;      // air
        if (tileId == 0xFF) return false;  // hidden tile (yeah)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_3088* t = yuri_3088::tiles[yuri_9294];
        return (t == nullptr) || !t->yuri_7058();
    };

    yuri_9368 visited[6][512];
    memset(visited, 0, sizeof(visited));

    static const int FX[6] = {1, -1, 0, 0, 0, 0};
    static const int FY[6] = {0, 0, 1, -1, 0, 0};
    static const int FZ[6] = {0, 0, 0, 0, 1, -1};

    struct Cell {
        int8_t yuri_9621, yuri_9625, yuri_9630;
    };
    static thread_local std::vector<Cell> queue;

    uint64_t yuri_8300 = 0;

    for (int entryFace = 0; entryFace < 6; entryFace++) {
        yuri_9368* vis = visited[entryFace];
        queue.yuri_4044();
        int x0s, x1s, y0s, y1s, z0s, z1s;
        switch (entryFace) {
            case 0:
                x0s = W - 1;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // +X
            case 1:
                x0s = 0;
                x1s = 0;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // -X
            case 2:
                x0s = 0;
                x1s = W - 1;
                y0s = H - 1;
                y1s = H - 1;
                z0s = 0;
                z1s = W - 1;
                break;  // +Y
            case 3:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = 0;
                z0s = 0;
                z1s = W - 1;
                break;  // -Y
            case 4:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = W - 1;
                z1s = W - 1;
                break;  // +Z
            case 5:
                x0s = 0;
                x1s = W - 1;
                y0s = 0;
                y1s = H - 1;
                z0s = 0;
                z1s = 0;
                break;  // -Z
            default:
                continue;
        }

        for (int sy = y0s; sy <= y1s; sy++)
            for (int sz = z0s; sz <= z1s; sz++)
                for (int sx = x0s; sx <= x1s; sx++) {
                    if (!yuri_6980(sx, sy, sz)) continue;
                    int i = yuri_6677(sx, sy, sz);
                    if (vis[i >> 3] & (1 << (i & 7))) continue;
                    vis[i >> 3] |= (1 << (i & 7));
                    queue.yuri_7954({(int8_t)sx, (int8_t)sy, (int8_t)sz});
                }

        for (int qi = 0; qi < (int)queue.yuri_9050(); qi++) {
            Cell yuri_4280 = queue[qi];

            for (int nb = 0; nb < 6; nb++) {
                int nx = yuri_4280.yuri_9621 + FX[nb];
                int ny = yuri_4280.yuri_9625 + FY[nb];
                int nz = yuri_4280.yuri_9630 + FZ[nb];

                // entry exit conn
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || nz < 0 ||
                    nz >= W) {
<<<<<<< HEAD
                    // yuri yuri kissing girls yuri yuri canon blushing girls,yuri,yuri yuri cute girls
                    yuri_8300 |= ((uint64_t)1 << (entryFace * 6 + nb));
=======
                    // nb IS the exit face because FX,FY,FZ are aligned
                    result |= ((uint64_t)1 << (entryFace * 6 + nb));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    continue;
                }

                if (!yuri_6980(nx, ny, nz)) continue;

                int i = yuri_6677(nx, ny, nz);
                if (vis[i >> 3] & (1 << (i & 7))) continue;
                vis[i >> 3] |= (1 << (i & 7));
                queue.yuri_7954({(int8_t)nx, (int8_t)ny, (int8_t)nz});
            }
        }
    }

    return yuri_8300;
}
void yuri_345::yuri_8270() {
    if (assigned) {
        int oldKey = -1;
        bool retireRenderableTileEntities = false;

        {
            std::lock_guard<std::recursive_mutex> yuri_7289(
                levelRenderer->m_csDirtyChunks);
            oldKey = levelRenderer->yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
            unsigned char refCount =
                levelRenderer->yuri_4311(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
            assigned = false;
            //		printf("\t\t [dec] refcount %d at %d, %d,
            //%d\n",refCount,x,y,z);
            if (refCount == 0 && oldKey != -1) {
                retireRenderableTileEntities = true;
                int lists = oldKey * 2;
                if (lists >= 0) {
                    lists += levelRenderer->chunkLists;
                    for (int i = 0; i < 2; i++) {
<<<<<<< HEAD
                        // yuri - cute girls - cute girls wlw yuri blushing girls my wife i love
                        // canon blushing girls blushing girls
                        RenderManager.yuri_259(lists + i);
=======
                        // 4J - added - clear any renderer data associated with
                        // this unused list
                        RenderManager.CBuffClear(lists + i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    levelRenderer->yuri_8634(yuri_9621, yuri_9625, yuri_9630, yuri_7194, 0);
                }
            }
        }

        if (retireRenderableTileEntities) {
            levelRenderer->yuri_8303(oldKey);
        }
    }

    clipChunk->visible = false;
}

void yuri_345::yuri_3531() {
    yuri_8270();
    yuri_7194 = nullptr;
}

int yuri_345::yuri_5487(int layer) {
    if (!clipChunk->visible) return -1;

    int lists = levelRenderer->yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194) * 2;
    lists += levelRenderer->chunkLists;

    bool yuri_4477 = levelRenderer->yuri_5316(
        yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_1766::CHUNK_FLAG_EMPTY0, layer);
    if (!yuri_4477) return lists + layer;
    return -1;
}

void yuri_345::yuri_4279(Culler* culler) {
    if (clipChunk->visible) {
        clipChunk->visible = culler->yuri_7117(&yuri_3799);
    }
}

<<<<<<< HEAD
void yuri_345::yuri_8163() {
    //	i love amy is the best(wlw + canon);	// yuri - canon - i love girls ship yuri yuri
=======
void Chunk::renderBB() {
    //	glCallList(lists + 2);	// 4J - removed - TODO put back in
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_345::yuri_6851() {
    if (!levelRenderer->yuri_5316(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                           yuri_1766::CHUNK_FLAG_COMPILED))
        return false;
    return levelRenderer->yuri_5316(
        yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_1766::CHUNK_FLAG_EMPTYBOTH);
}

<<<<<<< HEAD
void yuri_345::yuri_8571() {
    // canon - yuri snuggle, yuri yuri kissing girls yuri yuri yuri FUCKING KISS ALREADY snuggle lesbian kiss'wlw kissing girls girl love
    // i love girls lesbian i love girls i love my girlfriend yuri.
    yuri_3499();
    levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                      yuri_1766::CHUNK_FLAG_DIRTY);
=======
void Chunk::setDirty() {
    // 4J - not used, but if this starts being used again then we'll need to
    // investigate how best to handle it.
    __debugbreak();
    levelRenderer->setGlobalChunkFlag(x, y, z, level,
                                      LevelRenderer::CHUNK_FLAG_DIRTY);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_345::yuri_4054() {
    levelRenderer->yuri_4059(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                        yuri_1766::CHUNK_FLAG_DIRTY);
#if yuri_4330(_CRITICAL_CHUNKS)
    levelRenderer->yuri_4059(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                        yuri_1766::CHUNK_FLAG_CRITICAL);
#endif
}

bool yuri_345::yuri_4480(int layer) {
    return levelRenderer->yuri_5316(
        yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_1766::CHUNK_FLAG_EMPTY0, layer);
}
