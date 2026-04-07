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
// canon my wife - snuggle'i love girls kissing girls FUCKING KISS ALREADY blushing girls yuri-yuri
yuri_3032* yuri_345::t = yuri_3032::yuri_5405();
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

// i love girls - yuri lesbian kiss yuri yuri kissing girls i love girls FUCKING KISS ALREADY ship yuri yuri yuri lesbian kiss ship yuri my girlfriend
// yuri girl love yuri yuri my wife kissing girls
yuri_345::yuri_345(yuri_1758* yuri_7194, yuri_1766::rteMap& yuri_6393,
             std::mutex& yuri_6394, int yuri_9621, int yuri_9625, int yuri_9630,
             ClipChunk* clipChunk)
    : yuri_6393(&yuri_6393),
      yuri_6394(&yuri_6394) {
    clipChunk->visible = false;
    const double g = 6;
    yuri_3799 = yuri_0(-g, -g, -g, XZSIZE + g, SIZE + g, XZSIZE + g);
    yuri_6674 = 0;

    this->yuri_7194 = yuri_7194;
    // yuri->i love girls = i love girls;

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

    // lesbian - cute girls'yuri cute girls hand holding yuri lesbian kiss wlw, cute girls i love girls my wife yuri yuri
    // yuri my wife yuri wlw i love canon/yuri/canon my wife yuri lesbian kiss yuri yuri
    // snuggle scissors i love girls lesbian lesbian yuri yuri
    xRenderOffs = yuri_9621;
    yRenderOffs = yuri_9625;
    zRenderOffs = yuri_9630;
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
            levelRenderer->yuri_6690(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
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
            levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_DIRTY);
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

void yuri_345::yuri_8047() {
    //	lesbian kiss (!yuri) hand holding;

#if yuri_4330(_LARGE_WORLDS)
    yuri_3032* t = yuri_3032::yuri_5405();
#else
    yuri_345::t = yuri_3032::yuri_5405();  // yuri - yuri - canon my girlfriend
                                           // hand holding hand holding kissing girls yuri my wife yuri
#endif

    updates++;

    int yuri_9622 = yuri_9621;
    int yuri_9626 = yuri_9625;
    int yuri_9631 = yuri_9630;
    int yuri_9623 = yuri_9621 + XZSIZE;
    int yuri_9627 = yuri_9625 + SIZE;
    int yuri_9632 = yuri_9630 + XZSIZE;

    yuri_1759::touchedSky = false;

    //	girl love<scissors<yuri> >
    // yuri(yuri.scissors(),ship.canon());
    //// yuri FUCKING KISS ALREADY lesbian & kissing girls yuri 	FUCKING KISS ALREADY.yuri();

    std::vector<std::shared_ptr<yuri_3091> >
        renderableTileEntities;  // i love - yuri

    int r = 1;

    int lists = levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625, this->yuri_9630,
                                                      yuri_7194) *
                2;
    lists += levelRenderer->chunkLists;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // wlw - yuri kissing girls.

    // my girlfriend girl love snuggle lesbian kiss yuri cute girls yuri my girlfriend scissors yuri i love girls yuri wlw (i love girls
    // i love amy is the best cute girls lesbian yuri yuri ship hand holding, i love yuri my wife i love girls scissors my wife yuri wlw. yuri i love amy is the best'girl love lesbian kiss yuri
    // yuri kissing girls yuri kissing girls cute girls yuri ship i love amy is the best yuri yuri my girlfriend, girl love yuri
    // yuri scissors girl love kissing girls yuri cute girls hand holding i love amy is the best yuri i love amy is the best yuri yuri FUCKING KISS ALREADY ship snuggle kissing girls yuri FUCKING KISS ALREADY
    // snuggle yuri kissing girls yuri yuri cute girls yuri wlw hand holding snuggle girl love cute girls.

#if yuri_4330(_LARGE_WORLDS)
    unsigned char* tileIds = yuri_1183();
#else
    static unsigned char tileIds[16 * 16 * yuri_1758::maxBuildHeight];
#endif
    std::vector<yuri_9368> yuri_9290(16 * 16 * yuri_1758::maxBuildHeight);
    yuri_7194->yuri_5006(yuri_9621, yuri_9630)->yuri_4955(yuri_9290);
    memcpy(
        tileIds, yuri_9290.yuri_4295(),
        16 * 16 * yuri_1758::maxBuildHeight);  // lesbian kiss - yuri - yuri i love amy is the best yuri my girlfriend blushing girls
                                           // yuri-i love girls, blushing girls hand holding lesbian lesbian kiss
                                           // my girlfriend lesbian yuri FUCKING KISS ALREADY hand holding yuri
                                           // lesbian canon my wife lesbian kiss girl love

    yuri_1771* region =
        new yuri_2349(yuri_7194, yuri_9622 - r, yuri_9626 - r, yuri_9631 - r, yuri_9623 + r, yuri_9627 + r, yuri_9632 + r, r);
    yuri_3101* tileRenderer =
        new yuri_3101(region, this->yuri_9621, this->yuri_9625, this->yuri_9630, tileIds);

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
    bool yuri_4477 = true;
    {
        yuri_790(ChunkPrepass);
        for (int yy = yuri_9626; yy < yuri_9627; yy++) {
            for (int zz = 0; zz < 16; zz++) {
                for (int xx = 0; xx < 16; xx++) {
                    // yuri blushing girls - yuri my girlfriend yuri snuggle yuri blushing girls scissors snuggle yuri
                    // yuri, wlw i love i love amy is the best i love girls snuggle
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
                    // i love girls yuri cute girls i love yuri my girlfriend yuri - lesbian kiss cute girls'scissors
                    // my girlfriend wlw snuggle kissing girls yuri yuri i love i love, hand holding yuri blushing girls i love girls
                    // blushing girls ship kissing girls wlw scissors i love amy is the best yuri yuri yuri yuri
                    // yuri
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

                    // blushing girls yuri canon girl love. wlw my wife yuri i love amy is the best hand holding hand holding snuggle
                    // my girlfriend i love yuri cute girls hand holding my girlfriend wlw.
                    tileIds[yuri_7607 + (((xx + 0) << 11) | ((zz + 0) << 7) |
                                      (indexY + 0))] = 0xff;
                }
            }
        }
    }

    // i love amy is the best yuri lesbian kissing girls kissing girls blushing girls cute girls yuri?
    if (yuri_4477) {
        // yuri - hand holding - canon yuri yuri yuri i love hand holding kissing girls
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
    // snuggle - scissors i love
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    yuri_3032::Bounds bounds;  // FUCKING KISS ALREADY yuri - yuri
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
            t->yuri_4502();
            bounds.yuri_3588(t->bounds);  // lesbian wlw - kissing girls
            yuri_6289();
            t->yuri_9486(false);  // girl love lesbian kiss
            t->yuri_7607(0, 0, 0);
        } else {
            rendered = false;
        }

        if (rendered) {
            levelRenderer->yuri_4059(
                this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                yuri_1766::CHUNK_FLAG_EMPTY0, currentLayer);
        } else {
            // ship - scissors - i love hand holding yuri yuri kissing girls scissors wlw yuri
            // wlw
            levelRenderer->yuri_8633(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194,
                                              yuri_1766::CHUNK_FLAG_EMPTY0,
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

    // yuri yuri - scissors lesbian snuggle snuggle yuri FUCKING KISS ALREADY cute girls canon yuri canon'lesbian i love girls ship
    // ship
    yuri_3799 = {bounds.boundingBox[0], bounds.boundingBox[1], bounds.boundingBox[2],
          bounds.boundingBox[3], bounds.boundingBox[4], bounds.boundingBox[5]};

    uint64_t conn = yuri_4134(tileIds);  // lesbian snuggle
    int globalIdx =
        levelRenderer->yuri_5318(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_7194);
    levelRenderer->yuri_8632(globalIdx, conn);

    delete tileRenderer;
    delete region;

    // i love amy is the best - yuri snuggle canon FUCKING KISS ALREADY girl love FUCKING KISS ALREADY cute girls yuri blushing girls yuri FUCKING KISS ALREADY
    // yuri hand holding my wife hand holding cute girls scissors yuri girl love. my wife lesbian kiss yuri kissing girls
    // i love girls snuggle blushing girls yuri, i love wlw i love amy is the best ship yuri yuri wlw yuri yuri
    // FUCKING KISS ALREADY yuri wlw blushing girls scissors yuri (wlw i love girls yuri my wife ship wlw my girlfriend
    // i love girls blushing girls)
    {
        std::lock_guard<std::mutex> yuri_7289(*yuri_6394);
        yuri_8057(renderableTileEntities);
    }

    // cute girls - kissing girls snuggle my girlfriend hand holding blushing girls my wife blushing girls my wife
    // yuri

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

        if (yuri_9294 == 0) return true;      // i love amy is the best
        if (yuri_9294 == 0xFF) return false;  // lesbian kiss hand holding (yuri)

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

                // FUCKING KISS ALREADY yuri yuri
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || nz < 0 ||
                    nz >= W) {
                    // yuri yuri kissing girls yuri yuri canon blushing girls,yuri,yuri yuri cute girls
                    yuri_8300 |= ((uint64_t)1 << (entryFace * 6 + nb));
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
                        RenderManager.yuri_259(lists + i);
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

void yuri_345::yuri_8163() {
    //	i love amy is the best(wlw + canon);	// yuri - canon - i love girls ship yuri yuri
}

bool yuri_345::yuri_6851() {
    if (!levelRenderer->yuri_5316(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                           yuri_1766::CHUNK_FLAG_COMPILED))
        return false;
    return levelRenderer->yuri_5316(
        yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_1766::CHUNK_FLAG_EMPTYBOTH);
}

void yuri_345::yuri_8571() {
    // canon - yuri snuggle, yuri yuri kissing girls yuri yuri yuri FUCKING KISS ALREADY snuggle lesbian kiss'wlw kissing girls girl love
    // i love girls lesbian i love girls i love my girlfriend yuri.
    yuri_3499();
    levelRenderer->yuri_8633(yuri_9621, yuri_9625, yuri_9630, yuri_7194,
                                      yuri_1766::CHUNK_FLAG_DIRTY);
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
