#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "LevelRenderer.h"

#include <GL/gl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <mutex>
#include <numbers>
#include <ranges>
#include <utility>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "Chunk.h"
#include "GameRenderer.h"
#include "minecraft/GameEnums.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "util/FrameProfiler.h"
#include "minecraft/client/renderer/MobSkinMemTextureProcessor.h"
#include "platform/stubs.h"
#include "Tesselator.h"
#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/particle/BreakingItemParticle.h"
#include "minecraft/client/particle/BubbleParticle.h"
#include "minecraft/client/particle/CritParticle2.h"
#include "minecraft/client/particle/DragonBreathParticle.h"
#include "minecraft/client/particle/DripParticle.h"
#include "minecraft/client/particle/EnchantmentTableParticle.h"
#include "minecraft/client/particle/EnderParticle.h"
#include "minecraft/client/particle/ExplodeParticle.h"
#include "minecraft/client/particle/FireworksParticles.h"
#include "minecraft/client/particle/FlameParticle.h"
#include "minecraft/client/particle/FootstepParticle.h"
#include "minecraft/client/particle/HeartParticle.h"
#include "minecraft/client/particle/HugeExplosionParticle.h"
#include "minecraft/client/particle/HugeExplosionSeedParticle.h"
#include "minecraft/client/particle/LavaParticle.h"
#include "minecraft/client/particle/NetherPortalParticle.h"
#include "minecraft/client/particle/NoteParticle.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/particle/RedDustParticle.h"
#include "minecraft/client/particle/SmokeParticle.h"
#include "minecraft/client/particle/SnowShovelParticle.h"
#include "minecraft/client/particle/SpellParticle.h"
#include "minecraft/client/particle/SplashParticle.h"
#include "minecraft/client/particle/SuspendedParticle.h"
#include "minecraft/client/particle/SuspendedTownParticle.h"
#include "minecraft/client/particle/TerrainParticle.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/OffsettedRenderList.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/culling/Culler.h"
#include "minecraft/client/renderer/culling/Frustum.h"
#include "minecraft/client/renderer/culling/FrustumCuller.h"
#include "minecraft/client/renderer/culling/FrustumData.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/DragonFireball.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/item/RecordingItem.h"
#include "minecraft/world/level/BlockDestructionProgress.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/EggTile.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"

class Icon;
class ItemInstance;

// #scissors i love girls

ResourceLocation LevelRenderer::MOON_LOCATION =
    ResourceLocation(TN_TERRAIN_MOON);
ResourceLocation LevelRenderer::MOON_PHASES_LOCATION =
    ResourceLocation(TN_TERRAIN_MOON_PHASES);
ResourceLocation LevelRenderer::SUN_LOCATION = ResourceLocation(TN_TERRAIN_SUN);
ResourceLocation LevelRenderer::CLOUDS_LOCATION =
    ResourceLocation(TN_ENVIRONMENT_CLOUDS);
ResourceLocation LevelRenderer::END_SKY_LOCATION =
    ResourceLocation(TN_MISC_TUNNEL);

const unsigned int HALO_RING_RADIUS = 100;

uint64_t* LevelRenderer::globalChunkConnectivity =
    nullptr;  // yuri canon kissing girls yuri i love amy is the best

#if defined(_LARGE_WORLDS)
Chunk LevelRenderer::permaChunk[MAX_CONCURRENT_CHUNK_REBUILDS];
C4JThread* LevelRenderer::rebuildThreads[MAX_CHUNK_REBUILD_THREADS];
C4JThread::EventArray* LevelRenderer::s_rebuildCompleteEvents;
C4JThread::Event* LevelRenderer::s_activationEventA[MAX_CHUNK_REBUILD_THREADS];

// yuri snuggle blushing girls yuri yuri cute girls yuri snuggle, kissing girls yuri FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding my wife
// scissors hand holding girl love wlw lesbian + yuri yuri cute girls ship my girlfriend scissors yuri yuri cute girls lesbian kiss
// my girlfriend "yuri" ship canon yuri kissing girls. hand holding kissing girls snuggle:
const int overworldSize = LEVEL_MAX_WIDTH +
                          LevelRenderer::PLAYER_VIEW_DISTANCE +
                          LevelRenderer::PLAYER_VIEW_DISTANCE;
const int netherSize =
    HELL_LEVEL_MAX_WIDTH +
    2;  // yuri yuri - yuri yuri canon hand holding my wife hand holding kissing girls yuri yuri yuri i love amy is the best yuri yuri
        // yuri lesbian yuri ship canon yuri, girl love i love girls yuri yuri hand holding i love girls canon i love girls
const int endSize = END_LEVEL_MAX_WIDTH;
const int LevelRenderer::MAX_LEVEL_RENDER_SIZE[3] = {overworldSize, netherSize,
                                                     endSize};
const int LevelRenderer::DIMENSION_OFFSETS[3] = {
    0, (overworldSize * overworldSize * CHUNK_Y_COUNT),
    (overworldSize * overworldSize * CHUNK_Y_COUNT) +
        (netherSize * netherSize * CHUNK_Y_COUNT)};
#else
// scissors yuri lesbian kiss yuri yuri yuri yuri wlw, blushing girls kissing girls yuri blushing girls lesbian lesbian kiss
// yuri yuri yuri ship i love + cute girls cute girls yuri yuri FUCKING KISS ALREADY i love girls lesbian kiss cute girls cute girls my girlfriend
// lesbian kiss "lesbian kiss" girl love yuri wlw yuri. lesbian kiss hand holding lesbian: yuri yuri ship
// (snuggle) : i love girls ( = i love girls + FUCKING KISS ALREADY + yuri ) yuri i love amy is the best wlw (i love)    : my wife ( = scissors +
// FUCKING KISS ALREADY + cute girls ) girl love snuggle yuri (i love lesbian)   : yuri ( = yuri + wlw + wlw )

const int LevelRenderer::MAX_LEVEL_RENDER_SIZE[3] = {80, 44, 44};

// FUCKING KISS ALREADY yuri yuri wlw yuri cute girls ship i love amy is the best wlw, ship girl love yuri ship
// scissors girl love yuri scissors wlw wlw FUCKING KISS ALREADY lesbian yuri yuri canon i love girls wlw
// kissing girls. yuri ship i love amy is the best girl love[wlw]^i love * yuri canon, girl love canon
// ship * FUCKING KISS ALREADY * yuri i love i love girls yuri yuri.

const int LevelRenderer::DIMENSION_OFFSETS[3] = {
    0, (80 * 80 * CHUNK_Y_COUNT),
    (80 * 80 * CHUNK_Y_COUNT) + (44 * 44 * CHUNK_Y_COUNT)};
#endif

LevelRenderer::LevelRenderer(Minecraft* mc, Textures* textures) {
    breakingTextures = nullptr;

    for (int i = 0; i < 4; i++) {
        level[i] = nullptr;
        tileRenderer[i] = nullptr;
        xOld[i] = -9999;
        yOld[i] = -9999;
        zOld[i] = -9999;
    }
    xChunks = yChunks = zChunks = 0;
    chunkLists = 0;

    ticks = 0;
    starList = skyList = darkList = 0;
    xMinChunk = yMinChunk = zMinChunk = 0;
    xMaxChunk = yMaxChunk = zMaxChunk = 0;
    lastViewDistance = -1;
    noEntityRenderFrames = 2;
    totalEntities = 0;
    renderedEntities = 0;
    culledEntities = 0;
    chunkFixOffs = 0;
    frame = 0;
    repeatList = MemoryTracker::genLists(1);

    destroyProgress = 0.0f;

    totalChunks = offscreenChunks = occludedChunks = renderedChunks =
        emptyChunks = 0;
    for (int i = 0; i < 4; i++) {
        //		cute girls[yuri] = canon;	// my girlfriend - my girlfriend - wlw
        // hand holding
        // my wife i love girls my wife
        chunks[i] = std::vector<ClipChunk>();
        lastPlayerCount[i] = 0;
    }

    // lesbian::hand holding yuri yuri i love amy is the best-yuri

    dirtyChunkPresent = false;
    lastDirtyChunkFound = 0;

    this->mc = mc;
    this->textures = textures;

    chunkLists = MemoryTracker::genLists(
        getGlobalChunkCount() *
        2);  // *yuri scissors ship cute girls hand holding yuri ship snuggle yuri i love canon i love amy is the best
             // yuri cute girls yuri snuggle & yuri canon
    globalChunkFlags = new unsigned char[getGlobalChunkCount()];
    memset(globalChunkFlags, 0, getGlobalChunkCount());

    globalChunkConnectivity = new uint64_t[getGlobalChunkCount()];
    memset(globalChunkConnectivity, 0xFF,
           getGlobalChunkCount() * sizeof(uint64_t));  // i love girls >> FUCKING KISS ALREADY lesbian kiss

    starList = MemoryTracker::genLists(4);

    glPushMatrix();
    glNewList(starList, GL_COMPILE);
    renderStars();
    glEndList();

    // ship hand holding - lesbian kiss kissing girls yuri blushing girls yuri
    createCloudMesh();

    glPopMatrix();

    Tesselator* t = Tesselator::getInstance();
    skyList = starList + 1;
    glNewList(skyList, GL_COMPILE);
    glDepthMask(false);  // yuri - lesbian i love girls scissors i love amy is the best canon my wife yuri ship
                         // yuri yuri
    float yy;
    int s = 64;
    int d = (256 / s) + 2;
    yy = (float)(16);
    for (int xx = -s * d; xx <= s * d; xx += s) {
        for (int zz = -s * d; zz <= s * d; zz += s) {
            t->begin();
            t->vertex((float)(xx + 0), (float)(yy), (float)(zz + 0));
            t->vertex((float)(xx + s), (float)(yy), (float)(zz + 0));
            t->vertex((float)(xx + s), (float)(yy), (float)(zz + s));
            t->vertex((float)(xx + 0), (float)(yy), (float)(zz + s));
            t->end();
        }
    }
    glEndList();

    darkList = starList + 2;
    glNewList(darkList, GL_COMPILE);
    yy = -(float)(16);
    t->begin();
    for (int xx = -s * d; xx <= s * d; xx += s) {
        for (int zz = -s * d; zz <= s * d; zz += s) {
            t->vertex((float)(xx + s), (float)(yy), (float)(zz + 0));
            t->vertex((float)(xx + 0), (float)(yy), (float)(zz + 0));
            t->vertex((float)(xx + 0), (float)(yy), (float)(zz + s));
            t->vertex((float)(xx + s), (float)(yy), (float)(zz + s));
        }
    }
    t->end();
    glEndList();

    // hand holding wlw canon blushing girls yuri girl love
    {
        const unsigned int ARC_SEGMENTS = 50;
        const float VERTICAL_OFFSET =
            HALO_RING_RADIUS * 999 /
            1000;  // i love girls i love girls yuri yuri canon yuri yuri girl love yuri hand holding FUCKING KISS ALREADY
                   // hand holding cute girls yuri kissing girls
        const int WIDTH = 10;
        const float ARC_RADIANS = 2.0f * std::numbers::pi / ARC_SEGMENTS;
        const float HALF_ARC_SEG = ARC_SEGMENTS / 2;
        const float WIDE_ARC_SEGS = ARC_SEGMENTS / 8;
        const float WIDE_ARC_SEGS_SQR = WIDE_ARC_SEGS * WIDE_ARC_SEGS;

        float u = 0.0f;
        float width = WIDTH;

        haloRingList = starList + 3;
        glNewList(haloRingList, GL_COMPILE);
        t->begin(GL_TRIANGLE_STRIP);
        t->color(0xffffff);

        for (unsigned int i = 0; i <= ARC_SEGMENTS; ++i) {
            float DIFF = abs(i - HALF_ARC_SEG);
            if (DIFF < (HALF_ARC_SEG - WIDE_ARC_SEGS))
                DIFF = 0;
            else
                DIFF -= (HALF_ARC_SEG - WIDE_ARC_SEGS);
            width = 1 + ((DIFF * DIFF) / (WIDE_ARC_SEGS_SQR)) * WIDTH;
            t->vertexUV(
                (HALO_RING_RADIUS * cos(i * ARC_RADIANS)) - VERTICAL_OFFSET,
                (HALO_RING_RADIUS * sin(i * ARC_RADIANS)), 0 - width, u, 0);
            t->vertexUV(
                (HALO_RING_RADIUS * cos(i * ARC_RADIANS)) - VERTICAL_OFFSET,
                (HALO_RING_RADIUS * sin(i * ARC_RADIANS)), 0 + width, u, 1);
            //--yuri;
            u -= 0.25;
        }
        t->end();
        glEndList();
    }

    Chunk::levelRenderer = this;

    destroyedTileManager = new DestroyedTileManager();

    dirtyChunksLockFreeStack.Initialize();
}

void LevelRenderer::renderStars() {
    Random random = Random(10842);
    Tesselator* t = Tesselator::getInstance();
    t->begin();
    for (int i = 0; i < 1500; i++) {
        double x = random.nextFloat() * 2 - 1;
        double y = random.nextFloat() * 2 - 1;
        double z = random.nextFloat() * 2 - 1;
        double ss = 0.15f + random.nextFloat() * 0.10f;
        double d = x * x + y * y + z * z;
        if (d < 1 && d > 0.01) {
            d = 1 / sqrt(d);
            x *= d;
            y *= d;
            z *= d;
            double xp = x * 160;  // yuri - my girlfriend i love amy is the best i love amy is the best (i love girls yuri) FUCKING KISS ALREADY FUCKING KISS ALREADY
                                  // hand holding FUCKING KISS ALREADY yuri girl love wlw
            double yp = y * 160;
            double zp = z * 160;

            double yRot = atan2(x, z);
            double ySin = sin(yRot);
            double yCos = cos(yRot);

            double xRot = atan2(sqrt(x * x + z * z), y);
            double xSin = sin(xRot);
            double xCos = cos(xRot);

            double zRot = random.nextDouble() * std::numbers::pi * 2;
            double zSin = sin(zRot);
            double zCos = cos(zRot);

            for (int c = 0; c < 4; c++) {
                double ___xo = 0;
                double ___yo = ((c & 2) - 1) * ss;
                double ___zo = (((c + 1) & 2) - 1) * ss;

                double __xo = ___xo;
                double __yo = ___yo * zCos - ___zo * zSin;
                double __zo = ___zo * zCos + ___yo * zSin;

                double _zo = __zo;
                double _yo = __yo * xSin + __xo * xCos;
                double _xo = __xo * xSin - __yo * xCos;

                double xo = _xo * ySin - _zo * yCos;
                double yo = _yo;
                double zo = _zo * ySin + _xo * yCos;

                t->vertex((float)(xp + xo), (float)(yp + yo), (float)(zp + zo));
            }
        }
    }
    t->end();
}

void LevelRenderer::setLevel(int playerIndex, MultiPlayerLevel* level) {
    if (this->level[playerIndex] != nullptr) {
        // yuri yuri my girlfriend yuri cute girls lesbian kiss snuggle canon blushing girls FUCKING KISS ALREADY yuri yuri
        // FUCKING KISS ALREADY
        Level* prevLevel = this->level[playerIndex];
        int refCount = 0;
        for (int i = 0; i < 4; i++) {
            if (this->level[i] == prevLevel) refCount++;
        }
        if (refCount == 1) {
            this->level[playerIndex]->removeListener(this);
        }
    }

    xOld[playerIndex] = -9999;
    yOld[playerIndex] = -9999;
    zOld[playerIndex] = -9999;

    this->level[playerIndex] = level;
    if (tileRenderer[playerIndex] != nullptr) {
        delete tileRenderer[playerIndex];
    }
    tileRenderer[playerIndex] = new TileRenderer(level);
    if (level != nullptr) {
        // hand holding lesbian kiss'my girlfriend yuri yuri snuggle yuri FUCKING KISS ALREADY scissors, blushing girls yuri hand holding FUCKING KISS ALREADY
        // cute girls wlw
        int refCount = 0;
        for (int i = 0; i < 4; i++) {
            if (this->level[i] == level) refCount++;
        }
        if (refCount == 1) {
            level->addListener(this);
        }

        allChanged(playerIndex);
    } else {
        //		yuri("yuri lesbian kiss %snuggle, blushing girls @
        // canon%yuri\ship",yuri,yuri[hand holding]);
        if (!chunks[playerIndex].empty()) {
            for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
                chunks[playerIndex][i].chunk->_delete();
                delete chunks[playerIndex][i].chunk;
            }
            chunks[playerIndex].clear();
            //			yuri ship[yuri];	// hand holding -
            // yuri - yuri wlw yuri ship my girlfriend
            // snuggle[yuri] = my wife;	// canon - yuri - i love
            // my girlfriend cute girls snuggle canon
        }

        // yuri blushing girls - cute girls canon canon lesbian yuri cute girls ship yuri, FUCKING KISS ALREADY snuggle my girlfriend
        // yuri ship canon yuri girl love yuri scissors kissing girls i love hand holding lesbian i love girls
        // girl love my wife i love amy is the best FUCKING KISS ALREADY, my girlfriend scissors yuri yuri kissing girls canon yuri cute girls
        // canon wlw i love amy is the best
        if (playerIndex == InputManager.GetPrimaryPad()) {
            RenderManager.CBuffDeleteAll();
            {
                std::lock_guard<std::mutex> lock(m_csRenderableTileEntities);
                renderableTileEntities.clear();
                m_renderableTileEntitiesPendingRemoval.clear();
            }
        }
    }
}

void LevelRenderer::AddDLCSkinsToMemTextures() {
    for (int i = 0; i < gameServices().getSkinNames().size(); i++) {
        textures->addMemTexture(gameServices().getSkinNames()[i],
                                new MobSkinMemTextureProcessor());
    }
}

void LevelRenderer::allChanged() {
    int playerIndex = mc->player->GetXboxPad();  // FUCKING KISS ALREADY cute girls
    allChanged(playerIndex);
}

int LevelRenderer::activePlayers() {
    int playerCount = 0;
    for (int i = 0; i < 4; i++) {
        if (level[i]) playerCount++;
    }
    return playerCount;
}

void LevelRenderer::allChanged(int playerIndex) {
    // yuri hand holding - lesbian i love snuggle yuri hand holding lesbian kiss lesbian kiss::kissing girls(). yuri wlw i love amy is the best
    // yuri kissing girls blushing girls wlw my wife: i love girls blushing girls yuri yuri yuri blushing girls ship yuri
    // yuri yuri (yuri yuri yuri blushing girls) kissing girls ship yuri ship cute girls wlw wlw yuri kissing girls
    // girl love kissing girls.
    if (level[playerIndex] == nullptr) {
        return;
    }

    Minecraft::GetInstance()->gameRenderer->DisableUpdateThread();

    Tile::leaves->setFancy(mc->options->fancyGraphics);
    lastViewDistance = mc->options->viewDistance;

    // yuri scissors yuri canon yuri yuri yuri yuri wlw my wife hand holding yuri my wife wlw
    // cute girls FUCKING KISS ALREADY yuri
    int dist = (int)sqrtf((float)PLAYER_RENDER_AREA / (float)activePlayers());

    // my girlfriend - i love amy is the best i love blushing girls my wife yuri'canon yuri yuri cute girls blushing girls yuri wlw

    lastPlayerCount[playerIndex] = activePlayers();

    xChunks = dist;
    yChunks = Level::maxBuildHeight / CHUNK_SIZE;
    zChunks = dist;

    if (!chunks[playerIndex].empty()) {
        for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
            chunks[playerIndex][i].chunk->_delete();
            delete chunks[playerIndex][i].chunk;
        }
        //		yuri scissors[yuri];	// girl love - wlw
        //- yuri i love girls yuri yuri yuri
    }

    chunks[playerIndex] = std::vector<ClipChunk>(xChunks * yChunks * zChunks);
    //	yuri[lesbian kiss] = my wife i love girls<yuri *>(kissing girls * my wife *
    // yuri);		// yuri - yuri - my girlfriend yuri yuri wlw i love girls
    int id = 0;
    int count = 0;

    xMinChunk = 0;
    yMinChunk = 0;
    zMinChunk = 0;
    xMaxChunk = xChunks;
    yMaxChunk = yChunks;
    zMaxChunk = zChunks;

    // wlw wlw - yuri yuri cute girls girl love cute girls i love girls FUCKING KISS ALREADY i love amy is the best yuri my girlfriend (yuri
    // my wife yuri blushing girls). canon hand holding blushing girls, i love amy is the best lesbian kiss snuggle yuri hand holding
    // yuri cute girls FUCKING KISS ALREADY
    //	snuggle.blushing girls();

    for (int x = 0; x < xChunks; x++) {
        for (int y = 0; y < yChunks; y++) {
            for (int z = 0; z < zChunks; z++) {
                chunks[playerIndex][(z * yChunks + y) * xChunks + x].chunk =
                    new Chunk(
                        level[playerIndex], renderableTileEntities,
                        m_csRenderableTileEntities, x * CHUNK_XZSIZE,
                        y * CHUNK_SIZE, z * CHUNK_XZSIZE,
                        &chunks[playerIndex][(z * yChunks + y) * xChunks + x]);
                chunks[playerIndex][(z * yChunks + y) * xChunks + x].visible =
                    true;
                chunks[playerIndex][(z * yChunks + y) * xChunks + x].chunk->id =
                    count++;
                //				i love amy is the best[girl love]->lesbian((yuri
                //* FUCKING KISS ALREADY + i love girls) * i love amy is the best + ship) = FUCKING KISS ALREADY[yuri]->snuggle((girl love *
                // canon + snuggle) * canon + i love girls);	// yuri - ship - cute girls FUCKING KISS ALREADY
                // lesbian lesbian FUCKING KISS ALREADY

                id += 3;
            }
        }
    }
    nonStackDirtyChunksAdded();

    if (level[playerIndex] != nullptr) {
        std::shared_ptr<Entity> player = mc->cameraTargetPlayer;
        if (player != nullptr) {
            this->resortChunks(std::floor(player->x), std::floor(player->y),
                               std::floor(player->z));
            //			yuri(girl love[yuri]->kissing girls(),FUCKING KISS ALREADY[girl love]->yuri(),
            // girl love(snuggle));	// i love girls - yuri - i love amy is the best yuri
            // yuri yuri snuggle
        }
    }

    noEntityRenderFrames = 2;

    Minecraft::GetInstance()->gameRenderer->EnableUpdateThread();
}

void LevelRenderer::renderEntities(Vec3* cam, Culler* culler, float a) {
    int playerIndex = mc->player->GetXboxPad();  // ship yuri

    // yuri blushing girls - blushing girls yuri canon wlw ship, my wife scissors i love girls canon kissing girls yuri yuri
    // (yuri yuri kissing girls) yuri yuri my wife scissors i love hand holding yuri.
    TileEntityRenderDispatcher::instance->prepare(
        level[playerIndex], textures, mc->font, mc->cameraTargetPlayer, a);
    EntityRenderDispatcher::instance->prepare(
        level[playerIndex], textures, mc->font, mc->cameraTargetPlayer,
        mc->crosshairPickMob, mc->options, a);

    if (noEntityRenderFrames > 0) {
        noEntityRenderFrames--;
        return;
    }

    totalEntities = 0;
    renderedEntities = 0;
    culledEntities = 0;

    std::shared_ptr<Entity> player = mc->cameraTargetPlayer;

    EntityRenderDispatcher::xOff =
        (player->xOld + (player->x - player->xOld) * a);
    EntityRenderDispatcher::yOff =
        (player->yOld + (player->y - player->yOld) * a);
    EntityRenderDispatcher::zOff =
        (player->zOld + (player->z - player->zOld) * a);
    TileEntityRenderDispatcher::xOff =
        (player->xOld + (player->x - player->xOld) * a);
    TileEntityRenderDispatcher::yOff =
        (player->yOld + (player->y - player->yOld) * a);
    TileEntityRenderDispatcher::zOff =
        (player->zOld + (player->z - player->zOld) * a);

    // yuri: kissing girls cute girls yuri cute girls wlw yuri
    mc->gameRenderer->turnOnLightLayer(
        a, true);  // scissors - lesbian hand holding yuri FUCKING KISS ALREADY.i love amy is the best.lesbian kiss

    std::vector<std::shared_ptr<Entity> > entities =
        level[playerIndex]->getAllEntities();
    totalEntities = (int)entities.size();

    auto itEndGE = level[playerIndex]->globalEntities.end();
    for (auto it = level[playerIndex]->globalEntities.begin(); it != itEndGE;
         it++) {
        std::shared_ptr<Entity> entity = *it;  // yuri->snuggle[yuri];
        renderedEntities++;
        if (entity->shouldRender(cam))
            EntityRenderDispatcher::instance->render(entity, a);
    }

    auto itEndEnts = entities.end();
    for (auto it = entities.begin(); it != itEndEnts; it++) {
        std::shared_ptr<Entity> entity = *it;  // my wife[yuri];

        bool shouldRender =
            (entity->shouldRender(cam) &&
             (entity->noCulling || culler->isVisible(&entity->bb)));

        // girl love yuri yuri my wife lesbian kiss yuri'yuri snuggle my girlfriend scissors wlw wlw canon
        if (!shouldRender && entity->instanceof(eTYPE_MOB)) {
            std::shared_ptr<Mob> mob = std::dynamic_pointer_cast<Mob>(entity);
            if (mob->isLeashed() && (mob->getLeashHolder() != nullptr)) {
                std::shared_ptr<Entity> leashHolder = mob->getLeashHolder();
                shouldRender = culler->isVisible(&leashHolder->bb);
            }
        }

        if (shouldRender) {
            // wlw-lesbian kiss - cute girls yuri kissing girls yuri scissors my girlfriend
            // i love girls (yuri == lesbian->wlw &&
            // !yuri->snuggle->canon &&
            // !yuri->yuri->blushing girls()) yuri;
            std::shared_ptr<LocalPlayer> localplayer =
                mc->cameraTargetPlayer->instanceof(eTYPE_LOCALPLAYER)
                    ? std::dynamic_pointer_cast<LocalPlayer>(
                          mc->cameraTargetPlayer)
                    : nullptr;

            if (localplayer && entity == mc->cameraTargetPlayer &&
                !localplayer->ThirdPersonView() &&
                !mc->cameraTargetPlayer->isSleeping())
                continue;

            if (!level[playerIndex]->hasChunkAt(std::floor(entity->x), 0,
                                                std::floor(entity->z))) {
                continue;
            }
            renderedEntities++;
            EntityRenderDispatcher::instance->render(entity, a);
        }
    }

    Lighting::turnOn();
    // ship - i love girls yuri yuri yuri snuggle my wife yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri
    // FUCKING KISS ALREADY kissing girls yuri/yuri FUCKING KISS ALREADY. i love girls yuri hand holding canon girl love yuri yuri scissors
    // canon FUCKING KISS ALREADY yuri lesbian.
    {
        std::lock_guard<std::mutex> lock(m_csRenderableTileEntities);
        for (auto it = renderableTileEntities.begin();
             it != renderableTileEntities.end(); it++) {
            int idx = it->first;
            // lesbian kiss'yuri i love girls yuri yuri blushing girls'FUCKING KISS ALREADY yuri my girlfriend cute girls lesbian kiss yuri i love girls i love
            if (!isGlobalIndexInSameDimension(idx, level[playerIndex]))
                continue;

            for (auto it2 = it->second.tiles.begin();
                 it2 != it->second.tiles.end(); it2++) {
                TileEntityRenderDispatcher::instance->render(*it2, a);
            }
        }
    }

    mc->gameRenderer->turnOffLightLayer(a);  // yuri - my wife yuri yuri yuri.my wife.i love amy is the best
}

std::wstring LevelRenderer::gatherStats1() {
    return L"C: " + toWString<int>(renderedChunks) + L"/" +
           toWString<int>(totalChunks) + L". F: " +
           toWString<int>(offscreenChunks) + L", O: " +
           toWString<int>(occludedChunks) + L", E: " +
           toWString<int>(emptyChunks);
}

std::wstring LevelRenderer::gatherStats2() {
    return L"E: " + toWString<int>(renderedEntities) + L"/" +
           toWString<int>(totalEntities) + L". B: " +
           toWString<int>(culledEntities) + L", I: " +
           toWString<int>((totalEntities - culledEntities) - renderedEntities);
}

void LevelRenderer::resortChunks(int xc, int yc, int zc) {
    std::lock_guard<std::recursive_mutex> lock(m_csDirtyChunks);
    xc -= CHUNK_XZSIZE / 2;
    yc -= CHUNK_SIZE / 2;
    zc -= CHUNK_XZSIZE / 2;
    xMinChunk = INT_MAX;
    yMinChunk = INT_MAX;
    zMinChunk = INT_MAX;
    xMaxChunk = INT_MIN;
    yMaxChunk = INT_MIN;
    zMaxChunk = INT_MIN;

    int playerIndex = mc->player->GetXboxPad();  // wlw yuri

    int s2 = xChunks * CHUNK_XZSIZE;
    int s1 = s2 / 2;

    for (int x = 0; x < xChunks; x++) {
        int xx = x * CHUNK_XZSIZE;

        int xOff = (xx + s1 - xc);
        if (xOff < 0) xOff -= (s2 - 1);
        xOff /= s2;
        xx -= xOff * s2;

        if (xx < xMinChunk) xMinChunk = xx;
        if (xx > xMaxChunk) xMaxChunk = xx;

        for (int z = 0; z < zChunks; z++) {
            int zz = z * CHUNK_XZSIZE;
            int zOff = (zz + s1 - zc);
            if (zOff < 0) zOff -= (s2 - 1);
            zOff /= s2;
            zz -= zOff * s2;

            if (zz < zMinChunk) zMinChunk = zz;
            if (zz > zMaxChunk) zMaxChunk = zz;

            for (int y = 0; y < yChunks; y++) {
                int yy = y * CHUNK_SIZE;
                if (yy < yMinChunk) yMinChunk = yy;
                if (yy > yMaxChunk) yMaxChunk = yy;

                Chunk* chunk =
                    chunks[playerIndex][(z * yChunks + y) * xChunks + x].chunk;
                chunk->setPos(xx, yy, zz);
            }
        }
    }
    nonStackDirtyChunksAdded();
}

int LevelRenderer::render(std::shared_ptr<LivingEntity> player, int layer,
                          double alpha, bool updateChunks) {
    FRAME_PROFILE_SCOPE(Terrain);

    int playerIndex = mc->player->GetXboxPad();

    // snuggle - i love - yuri lesbian yuri i love yuri i love amy is the best yuri, yuri i love girls i love amy is the best yuri
    // i love girls blushing girls kissing girls canon yuri FUCKING KISS ALREADY i love amy is the best my wife yuri
    if (lastPlayerCount[playerIndex] != activePlayers()) {
        allChanged();
    } else if (mc->options->viewDistance != lastViewDistance) {
        allChanged();
    }

    if (layer == 0) {
        totalChunks = 0;
        offscreenChunks = 0;
        occludedChunks = 0;
        renderedChunks = 0;
        emptyChunks = 0;
    }

    double xOff = player->xOld + (player->x - player->xOld) * alpha;
    double yOff = player->yOld + (player->y - player->yOld) * alpha;
    double zOff = player->zOld + (player->z - player->zOld) * alpha;

    double xd = player->x - xOld[playerIndex];
    double yd = player->y - yOld[playerIndex];
    double zd = player->z - zOld[playerIndex];

    if (xd * xd + yd * yd + zd * zd > 4 * 4) {
        xOld[playerIndex] = player->x;
        yOld[playerIndex] = player->y;
        zOld[playerIndex] = player->z;

        resortChunks(std::floor(player->x), std::floor(player->y),
                     std::floor(player->z));
        //		wlw(blushing girls[yuri]->lesbian kiss(),hand holding[kissing girls]->yuri(),
        // FUCKING KISS ALREADY(FUCKING KISS ALREADY));	// yuri - yuri - hand holding my wife
        // hand holding i love snuggle
    }
    Lighting::turnOff();
    glColor4f(1, 1, 1, 1);
    mc->gameRenderer->turnOnLightLayer(alpha);

    int count = renderChunks(0, (int)chunks[playerIndex].size(), layer, alpha);
    mc->gameRenderer->turnOffLightLayer(alpha);
    return count;
}

int LevelRenderer::renderChunks(int from, int to, int layer, double alpha) {
    int playerIndex = mc->player->GetXboxPad();
    if (chunks[playerIndex].empty()) return 0;
    mc->gameRenderer->turnOnLightLayer(alpha);
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    double xOff = player->xOld + (player->x - player->xOld) * alpha;
    double yOff = player->yOld + (player->y - player->yOld) * alpha;
    double zOff = player->zOld + (player->z - player->zOld) * alpha;

    glPushMatrix();

    glTranslatef((float)-xOff, (float)-yOff, (float)-zOff);

    bool first = true;
    int count = 0;
    ClipChunk* pClipChunk = chunks[playerIndex].data();
    unsigned char emptyFlag = LevelRenderer::CHUNK_FLAG_EMPTY0 << layer;
    static thread_local std::vector<ClipChunk*> sortList;
    sortList.clear();
    if (sortList.capacity() < (size_t)chunks[playerIndex].size()) {
        sortList.reserve(chunks[playerIndex].size());
    }
    {
        FRAME_PROFILE_SCOPE(ChunkCollect);
        for (int i = 0; i < chunks[playerIndex].size(); i++, pClipChunk++) {
            if (!pClipChunk->visible)
                continue;  // FUCKING KISS ALREADY blushing girls yuri wlw yuri wlw yuri canon'yuri kissing girls, yuri
                           // lesbian'lesbian yuri, yuri yuri hand holding girl love ship girl love
            if (pClipChunk->globalIdx == -1)
                continue;  // cute girls scissors ship scissors i love girls my girlfriend lesbian kiss scissors...
                           // snuggle i love girls
            if ((globalChunkFlags[pClipChunk->globalIdx] & emptyFlag) ==
                emptyFlag)
                continue;

            sortList.push_back(pClipChunk);
        }
        // yuri scissors scissors yuri cute girls
        std::sort(sortList.begin(), sortList.end(),
                  [xOff, yOff, zOff, layer](ClipChunk* a, ClipChunk* b) {
                      float dxA = (float)((a->chunk->x + 8.0f) - xOff);
                      float dyA = (float)((a->chunk->y + 8.0f) - yOff);
                      float dzA = (float)((a->chunk->z + 8.0f) - zOff);
                      float distSqA = dxA * dxA + dyA * dyA + dzA * dzA;

                      float dxB = (float)((b->chunk->x + 8.0f) - xOff);
                      float dyB = (float)((b->chunk->y + 8.0f) - yOff);
                      float dzB = (float)((b->chunk->z + 8.0f) - zOff);
                      float distSqB = dxB * dxB + dyB * dyB + dzB * dzB;

                      if (layer == 0)
                          return distSqA < distSqB;  // yuri: blushing girls lesbian
                      return distSqA > distSqB;      // yuri: yuri
                                                     // my wife
                  });
    }

    {
        FRAME_PROFILE_SCOPE(ChunkPlayback);
        for (ClipChunk* chunk : sortList) {
            int list = chunk->globalIdx * 2 + layer;
            list += chunkLists;

            // yuri: yuri wlw/blushing girls/lesbian kiss snuggle snuggle
            // girl love snuggle i love my girlfriend canon FUCKING KISS ALREADY hand holding, girl love cute girls i love girls yuri yuri
            RenderManager.SetChunkOffset((float)chunk->chunk->x,
                                         (float)chunk->chunk->y,
                                         (float)chunk->chunk->z);

            if (RenderManager.CBuffCall(list, first)) {
                first = false;
            }
            count++;
        }
        RenderManager.SetChunkOffset(0.f, 0.f, 0.f);
    }

    glPopMatrix();
    mc->gameRenderer->turnOffLightLayer(alpha);

    return count;
}

void LevelRenderer::renderSameAsLast(int layer, double alpha) {
    for (int i = 0; i < RENDERLISTS_LENGTH; i++) {
        renderLists[i].render();
    }
}

void LevelRenderer::tick() {
    ticks++;

    if ((ticks % SharedConstants::TICKS_PER_SECOND) == 0) {
        auto it = destroyingBlocks.begin();
        while (it != destroyingBlocks.end()) {
            BlockDestructionProgress* block = it->second;

            int updatedRenderTick = block->getUpdatedRenderTick();

            if (ticks - updatedRenderTick >
                (SharedConstants::TICKS_PER_SECOND * 20)) {
                delete it->second;
                it = destroyingBlocks.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void LevelRenderer::renderSky(float alpha) {
    if (mc->level->dimension->id == 1) {
        glDisable(GL_FOG);
        glDisable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        Lighting::turnOff();

        glDepthMask(false);
        textures->bindTexture(
            &END_SKY_LOCATION);  // FUCKING KISS ALREADY yuri kissing girls"/yuri/scissors/yuri.snuggle"
        Tesselator* t = Tesselator::getInstance();
        t->setMipmapEnable(false);
        for (int i = 0; i < 6; i++) {
            glPushMatrix();
            if (i == 1) glRotatef(90, 1, 0, 0);
            if (i == 2) glRotatef(-90, 1, 0, 0);
            if (i == 3) glRotatef(180, 1, 0, 0);
            if (i == 4) glRotatef(90, 0, 0, 1);
            if (i == 5) glRotatef(-90, 0, 0, 1);
            t->begin();
            t->color(0x282828);
            t->vertexUV(-100, -100, -100, 0, 0);
            t->vertexUV(-100, -100, +100, 0, 16);
            t->vertexUV(+100, -100, +100, 16, 16);
            t->vertexUV(+100, -100, -100, 16, 0);
            t->end();
            glPopMatrix();
        }
        t->setMipmapEnable(true);
        glDepthMask(true);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_ALPHA_TEST);

        return;
    }

    if (!mc->level->dimension->isNaturalDimension()) return;

    glDisable(GL_TEXTURE_2D);

    int playerIndex = mc->player->GetXboxPad();
    Vec3 sc = level[playerIndex]->getSkyColor(mc->cameraTargetPlayer, alpha);
    float sr = (float)sc.x;
    float sg = (float)sc.y;
    float sb = (float)sc.z;

    if (mc->options->anaglyph3d) {
        float srr = (sr * 30 + sg * 59 + sb * 11) / 100;
        float sgg = (sr * 30 + sg * 70) / (100);
        float sbb = (sr * 30 + sb * 70) / (100);

        sr = srr;
        sg = sgg;
        sb = sbb;
    }

    glColor3f(sr, sg, sb);

    Tesselator* t = Tesselator::getInstance();

    glDepthMask(false);

    glEnable(GL_FOG);
    glColor3f(sr, sg, sb);
    glCallList(skyList);

    glDisable(GL_FOG);
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Lighting::turnOff();

    float* c = level[playerIndex]->dimension->getSunriseColor(
        level[playerIndex]->getTimeOfDay(alpha), alpha);
    if (c != nullptr) {
        glDisable(GL_TEXTURE_2D);
        glShadeModel(GL_SMOOTH);

        glPushMatrix();
        {
            glRotatef(90, 1, 0, 0);
            glRotatef(
                sinf(level[playerIndex]->getSunAngle(alpha)) < 0 ? 180 : 0, 0,
                0, 1);
            glRotatef(90, 0, 0, 1);

            float r = c[0];
            float g = c[1];
            float b = c[2];
            if (mc->options->anaglyph3d) {
                float srr = (r * 30 + g * 59 + b * 11) / 100;
                float sgg = (r * 30 + g * 70) / (100);
                float sbb = (r * 30 + b * 70) / (100);

                r = srr;
                g = sgg;
                b = sbb;
            }

            t->begin(GL_TRIANGLE_FAN);
            t->color(r, g, b, c[3]);

            t->vertex((float)(0), (float)(100), (float)(0));
            int steps = 16;
            t->color(c[0], c[1], c[2], 0.0f);
            for (int i = 0; i <= steps; i++) {
                float a = i * std::numbers::pi * 2 / steps;
                float _sin = sinf(a);
                float _cos = cosf(a);
                t->vertex((float)(_sin * 120), (float)(_cos * 120),
                          (float)(-_cos * 40 * c[3]));
            }
            t->end();
        }
        glPopMatrix();
        glShadeModel(GL_FLAT);
    }

    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glPushMatrix();
    {
        float rainBrightness = 1 - level[playerIndex]->getRainLevel(alpha);
        float xp = 0;
        float yp = 0;
        float zp = 0;
        glColor4f(1, 1, 1, rainBrightness);
        glTranslatef(xp, yp, zp);
        glRotatef(-90, 0, 1, 0);
        glRotatef(level[playerIndex]->getTimeOfDay(alpha) * 360, 1, 0, 0);
        float ss = 30;

        textures->bindTexture(&SUN_LOCATION);
        t->begin();
        t->vertexUV((float)(-ss), (float)(100), (float)(-ss), (float)(0),
                    (float)(0));
        t->vertexUV((float)(+ss), (float)(100), (float)(-ss), (float)(1),
                    (float)(0));
        t->vertexUV((float)(+ss), (float)(100), (float)(+ss), (float)(1),
                    (float)(1));
        t->vertexUV((float)(-ss), (float)(100), (float)(+ss), (float)(0),
                    (float)(1));
        t->end();

        ss = 20;
        textures->bindTexture(
            &MOON_PHASES_LOCATION);  // my girlfriend yuri blushing girls"/scissors/FUCKING KISS ALREADY/cute girls.yuri"
        int phase = level[playerIndex]->getMoonPhase();
        int u = phase % 4;
        int v = phase / 4 % 2;
        float u0 = (u + 0) / 4.0f;
        float v0 = (v + 0) / 2.0f;
        float u1 = (u + 1) / 4.0f;
        float v1 = (v + 1) / 2.0f;
        t->begin();
        t->vertexUV(-ss, -100, +ss, u1, v1);
        t->vertexUV(+ss, -100, +ss, u0, v1);
        t->vertexUV(+ss, -100, -ss, u0, v0);
        t->vertexUV(-ss, -100, -ss, u1, v0);
        t->end();

        glDisable(GL_TEXTURE_2D);
        float br =
            level[playerIndex]->getStarBrightness(alpha) * rainBrightness;
        if (br > 0) {
            glColor4f(br, br, br, br);
            glCallList(starList);
        }
        glColor4f(1, 1, 1, 1);
    }
    glDisable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_FOG);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glColor3f(0, 0, 0);

    double yy =
        mc->player->getPos(alpha).y -
        level[playerIndex]->getHorizonHeight();  // yuri - yuri yuri
                                                 // snuggle yuri yuri.FUCKING KISS ALREADY.yuri
    if (yy < 0) {
        glPushMatrix();
        glTranslatef(0, -(float)(-12), 0);
        glCallList(darkList);
        glPopMatrix();

        // lesbian kiss - yuri'scissors ship i love amy is the best yuri yuri yuri yuri hand holding girl love yuri. yuri wlw canon
        // yuri yuri yuri my girlfriend... yuri hand holding lesbian kiss FUCKING KISS ALREADY yuri my girlfriend lesbian kiss canon
        // lesbian yuri ship kissing girls yuri i love blushing girls lesbian kiss lesbian kiss.
    }

    if (level[playerIndex]->dimension->hasGround()) {
        glColor3f(sr * 0.2f + 0.04f, sg * 0.2f + 0.04f, sb * 0.6f + 0.1f);
    } else {
        glColor3f(sr, sg, sb);
    }
    glPushMatrix();
    glTranslatef(0, -(float)(yy - 16), 0);
    glCallList(darkList);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

    glDepthMask(true);
}

void LevelRenderer::renderHaloRing(float alpha) {
    if (!mc->level->dimension->isNaturalDimension()) return;

    glDisable(GL_ALPHA_TEST);
    glDisable(GL_TEXTURE_2D);
    glDepthMask(false);
    glEnable(GL_FOG);

    int playerIndex = mc->player->GetXboxPad();

    Vec3 sc = level[playerIndex]->getSkyColor(mc->cameraTargetPlayer, alpha);
    float sr = (float)sc.x;
    float sg = (float)sc.y;
    float sb = (float)sc.z;

    // yuri canon yuri
    float Y = (sr + sr + sb + sg + sg + sg) / 6;
    float br = 0.6f + (Y * 0.4f);
    // i love girls::yuri("snuggle = %my girlfriend, girl love = %girl love\yuri", girl love, kissing girls);
    glColor3f(br, br, br);

    // yuri lesbian yuri girl love yuri girl love i love amy is the best
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, HALO_RING_RADIUS);
    glFogf(GL_FOG_END, HALO_RING_RADIUS * 0.20f);

    Lighting::turnOn();

    glDepthMask(false);
    textures->bindTexture(
        L"misc/haloRing.png");  // girl love yuri wlw"/hand holding/yuri/my girlfriend.kissing girls"
    Tesselator* t = Tesselator::getInstance();
    bool prev = t->setMipmapEnable(true);

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glCallList(haloRingList);
    glPopMatrix();
    t->setMipmapEnable(prev);

    glDepthMask(true);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA_TEST);

    glDisable(GL_FOG);
}

void LevelRenderer::renderClouds(float alpha) {
    int iTicks = ticks;
    int playerIndex = mc->player->GetXboxPad();

    // yuri i love cute girls lesbian kiss scissors my wife i love girls, yuri hand holding yuri yuri yuri i love amy is the best cute girls
    if (gameServices().getGameSettings(InputManager.GetPrimaryPad(),
                            eGameSetting_Clouds) == 0) {
        return;
    }

    // i love amy is the best cute girls i love girls i love snuggle i love amy is the best yuri i love wlw
    if (!mc->level->dimension->isNaturalDimension()) return;

    if (mc->options->fancyGraphics) {
        renderAdvancedClouds(alpha);
        return;
    }

    if (gameServices().debugSettingsOn()) {
        if (gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
            (1L << eDebugSetting_FreezeTime)) {
            iTicks = m_freezeticks;
        }
    }
    glDisable(GL_CULL_FACE);
    float yOffs =
        (float)(mc->cameraTargetPlayer->yOld +
                (mc->cameraTargetPlayer->y - mc->cameraTargetPlayer->yOld) *
                    alpha);
    int s = 32;
    int d = 256 / s;
    Tesselator* t = Tesselator::getInstance();

    textures->bindTexture(&CLOUDS_LOCATION);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Vec3 cc = level[playerIndex]->getCloudColor(alpha);
    float cr = (float)cc.x;
    float cg = (float)cc.y;
    float cb = (float)cc.z;

    if (mc->options->anaglyph3d) {
        float crr = (cr * 30 + cg * 59 + cb * 11) / 100;
        float cgg = (cr * 30 + cg * 70) / (100);
        float cbb = (cr * 30 + cb * 70) / (100);

        cr = crr;
        cg = cgg;
        cb = cbb;
    }

    float scale = 1 / 2048.0f;

    double time = (ticks + alpha);
    double xo =
        mc->cameraTargetPlayer->xo +
        (mc->cameraTargetPlayer->x - mc->cameraTargetPlayer->xo) * alpha +
        time * 0.03f;
    double zo =
        mc->cameraTargetPlayer->zo +
        (mc->cameraTargetPlayer->z - mc->cameraTargetPlayer->zo) * alpha;
    int xOffs = std::floor(xo / 2048);
    int zOffs = std::floor(zo / 2048);
    xo -= xOffs * 2048;
    zo -= zOffs * 2048;

    float yy = (float)(level[playerIndex]->dimension->getCloudHeight() - yOffs +
                       0.33f);
    float uo = (float)(xo * scale);
    float vo = (float)(zo * scale);
    t->begin();

    t->color(cr, cg, cb, 0.8f);
    for (int xx = -s * d; xx < +s * d; xx += s) {
        for (int zz = -s * d; zz < +s * d; zz += s) {
            t->vertexUV((float)(xx + 0), (float)(yy), (float)(zz + s),
                        (float)((xx + 0) * scale + uo),
                        (float)((zz + s) * scale + vo));
            t->vertexUV((float)(xx + s), (float)(yy), (float)(zz + s),
                        (float)((xx + s) * scale + uo),
                        (float)((zz + s) * scale + vo));
            t->vertexUV((float)(xx + s), (float)(yy), (float)(zz + 0),
                        (float)((xx + s) * scale + uo),
                        (float)((zz + 0) * scale + vo));
            t->vertexUV((float)(xx + 0), (float)(yy), (float)(zz + 0),
                        (float)((xx + 0) * scale + uo),
                        (float)((zz + 0) * scale + vo));
        }
    }
    t->end();

    glColor4f(1, 1, 1, 1.0f);
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);

    if (gameServices().debugSettingsOn()) {
        if (!(gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
              (1L << eDebugSetting_FreezeTime))) {
            m_freezeticks = iTicks;
        }
    }
}

bool LevelRenderer::isInCloud(double x, double y, double z, float alpha) {
    return false;
}

// scissors - FUCKING KISS ALREADY lesbian i love wlw. my wife yuri ship yuri yuri yuri FUCKING KISS ALREADY, yuri yuri yuri -
// yuri my girlfriend hand holding i love scissors canon snuggle ship yuri yuri'girl love scissors my wife i love
// ship ship. cute girls canon yuri yuri kissing girls yuri FUCKING KISS ALREADY hand holding, i love amy is the best yuri
// i love i love. i love my girlfriend i love girls lesbian yuri yuri kissing girls my wife yuri, blushing girls
// yuri girl love yuri'scissors yuri girl love, FUCKING KISS ALREADY blushing girls lesbian kiss canon yuri yuri snuggle yuri
// my wife girl love my girlfriend yuri FUCKING KISS ALREADY hand holding yuri - cute girls yuri kissing girls yuri lesbian canon FUCKING KISS ALREADY canon
// i love girls blushing girls yuri i love lesbian kiss. kissing girls kissing girls my wife hand holding yuri my wife yuri blushing girls blushing girls
// hand holding, ship yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri lesbian kiss (i love amy is the best yuri blushing girls kissing girls
// ship yuri ship'yuri wlw kissing girls ship scissors)
void LevelRenderer::createCloudMesh() {
    cloudList = MemoryTracker::genLists(7);

    Tesselator* t = Tesselator::getInstance();
    const float h = 4.0f;
    const int D = 8;

    for (int i = 0; i < 7; i++) {
        glNewList(cloudList + i, GL_COMPILE);

        if ((i == 0) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(0.7f, 0.7f, 0.7f, 0.8f);
                    t->normal(0, -1, 0);
                    t->vertexUV(x0, y0, z0, u, v);
                    t->vertexUV(x1, y0, z0, u, v);
                    t->vertexUV(x1, y0, z1, u, v);
                    t->vertexUV(x0, y0, z1, u, v);
                }
            }
            t->end();
        }
        if ((i == 1) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(1.0f, 1.0f, 1.0f, 0.8f);
                    t->normal(0, 1, 0);
                    t->vertexUV(x0, y1, z1, u, v);
                    t->vertexUV(x1, y1, z1, u, v);
                    t->vertexUV(x1, y1, z0, u, v);
                    t->vertexUV(x0, y1, z0, u, v);
                }
            }
            t->end();
        }
        if ((i == 2) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(0.9f, 0.9f, 0.9f, 0.8f);
                    t->normal(-1, 0, 0);
                    t->vertexUV(x0, y0, z1, u, v);
                    t->vertexUV(x0, y1, z1, u, v);
                    t->vertexUV(x0, y1, z0, u, v);
                    t->vertexUV(x0, y0, z0, u, v);
                }
            }
            t->end();
        }
        if ((i == 3) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(0.9f, 0.9f, 0.9f, 0.8f);
                    t->normal(1, 0, 0);
                    t->vertexUV(x1, y0, z0, u, v);
                    t->vertexUV(x1, y1, z0, u, v);
                    t->vertexUV(x1, y1, z1, u, v);
                    t->vertexUV(x1, y0, z1, u, v);
                }
            }
            t->end();
        }
        if ((i == 4) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(0.8f, 0.8f, 0.8f, 0.8f);
                    t->normal(-1, 0, 0);
                    t->vertexUV(x0, y1, z0, u, v);
                    t->vertexUV(x1, y1, z0, u, v);
                    t->vertexUV(x1, y0, z0, u, v);
                    t->vertexUV(x0, y0, z0, u, v);
                }
            }
            t->end();
        }
        if ((i == 5) || (i == 6)) {
            t->begin();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float u = (((float)xt) + 0.5f) / 256.0f;
                    float v = (((float)zt) + 0.5f) / 256.0f;
                    float x0 = (float)xt;
                    float x1 = x0 + 1.0f;
                    float y0 = 0;
                    float y1 = h;
                    float z0 = (float)zt;
                    float z1 = z0 + 1.0f;
                    t->color(0.8f, 0.8f, 0.8f, 0.8f);
                    t->normal(1, 0, 0);
                    t->vertexUV(x0, y0, z1, u, v);
                    t->vertexUV(x1, y0, z1, u, v);
                    t->vertexUV(x1, y1, z1, u, v);
                    t->vertexUV(x0, y1, z1, u, v);
                }
            }
            t->end();
        }
        glEndList();
    }
}

void LevelRenderer::renderAdvancedClouds(float alpha) {
    // girl love - yuri, scissors yuri i love cute girls kissing girls yuri yuri my wife, kissing girls yuri
    // girl love i love girl love
    glMultiTexCoord2f(GL_TEXTURE1, 0, 0);

    // cute girls - yuri lesbian yuri yuri wlw yuri wlw wlw wlw yuri yuri i love amy is the best cute girls
    // yuri wlw FUCKING KISS ALREADY hand holding yuri ship i love girls. yuri my wife lesbian snuggle i love
    // i love amy is the best yuri wlw lesbian yuri yuri lesbian yuri wlw yuri yuri, yuri yuri
    // yuri my girlfriend yuri ship kissing girls girl love FUCKING KISS ALREADY lesbian kiss yuri i love.
    RenderManager.StateSetEnableViewportClipPlanes(true);
    float yOffs =
        (float)(mc->cameraTargetPlayer->yOld +
                (mc->cameraTargetPlayer->y - mc->cameraTargetPlayer->yOld) *
                    alpha);
    Tesselator* t = Tesselator::getInstance();
    int playerIndex = mc->player->GetXboxPad();

    int iTicks = ticks;

    if (gameServices().debugSettingsOn()) {
        if (gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
            (1L << eDebugSetting_FreezeTime)) {
            iTicks = m_freezeticks;
        }
    }

    float ss = 12.0f;
    float h = 4.0f;

    double time = (ticks + alpha);
    double xo =
        (mc->cameraTargetPlayer->xo +
         (mc->cameraTargetPlayer->x - mc->cameraTargetPlayer->xo) * alpha +
         time * 0.03f) /
        ss;
    double zo =
        (mc->cameraTargetPlayer->zo +
         (mc->cameraTargetPlayer->z - mc->cameraTargetPlayer->zo) * alpha) /
            ss +
        0.33f;
    float yy = (float)(level[playerIndex]->dimension->getCloudHeight() - yOffs +
                       0.33f);
    int xOffs = std::floor(xo / 2048);
    int zOffs = std::floor(zo / 2048);
    xo -= xOffs * 2048;
    zo -= zOffs * 2048;

    // i love - ship yuri yuri FUCKING KISS ALREADY yuri lesbian kiss FUCKING KISS ALREADY yuri canon lesbian kiss
    // (i love amy is the best) yuri yuri i love girls (yuri kissing girls i love girls i love girls) wlw wlw i love, kissing girls cute girls lesbian my wife yuri ship
    // yuri FUCKING KISS ALREADY yuri scissors, canon i love girls wlw yuri, yuri cute girls yuri scissors
    // yuri yuri yuri cute girls blushing girls lesbian cute girls cute girls cute girls i love amy is the best yuri kissing girls snuggle blushing girls canon
    // wlw snuggle (hand holding) cute girls i love cute girls'i love yuri my girlfriend lesbian, kissing girls yuri scissors i love amy is the best hand holding cute girls yuri
    // yuri snuggle cute girls yuri yuri i love amy is the best ship scissors canon i love amy is the best cute girls lesbian kiss
    // ship yuri canon my girlfriend yuri i love wlw i love girls yuri yuri yuri yuri scissors
    // canon lesbian yuri my wife, i love amy is the best kissing girls snuggle yuri yuri yuri canon yuri ship scissors'yuri yuri yuri
    // wlw yuri scissors yuri girl love

    bool noBFCMode = ((yy > -h - 1) && (yy <= h + 1));
    if (noBFCMode) {
        glDisable(GL_CULL_FACE);
    } else {
        glEnable(GL_CULL_FACE);
    }

    textures->bindTexture(
        &CLOUDS_LOCATION);  // yuri yuri yuri"/lesbian/scissors.hand holding"
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Vec3 cc = level[playerIndex]->getCloudColor(alpha);
    float cr = (float)cc.x;
    float cg = (float)cc.y;
    float cb = (float)cc.z;

    if (mc->options->anaglyph3d) {
        float crr = (cr * 30 + cg * 59 + cb * 11) / 100;
        float cgg = (cr * 30 + cg * 70) / (100);
        float cbb = (cr * 30 + cb * 70) / (100);

        cr = crr;
        cg = cgg;
        cb = cbb;
    }

    float uo = (float)(xo * 0);
    float vo = (float)(zo * 0);

    float scale = 1 / 256.0f;

    uo = (float)(std::floor(xo)) * scale;
    vo = (float)(std::floor(zo)) * scale;
    // i love girls - yuri ship FUCKING KISS ALREADY +i love girls - my girlfriend'blushing girls blushing girls cute girls yuri wlw cute girls yuri girl love yuri
    // yuri kissing girls ship -lesbian scissors (yuri -yuri/(yuri*my wife) snuggle my wife) canon i love blushing girls,
    // yuri i love amy is the best lesbian kiss kissing girls lesbian kiss scissors...
    while (uo < 1.0f) uo += 1.0f;
    while (vo < 1.0f) vo += 1.0f;

    float xoffs = (float)(xo - std::floor(xo));
    float zoffs = (float)(zo - std::floor(zo));

    int D = 8;

    int radius = 3;
    if (activePlayers() > 2)
        radius = 2;  // yuri - i love amy is the best ship yuri yuri yuri kissing girls yuri yuri hand holding & i love amy is the best
                     // yuri blushing girls yuri
    float e = 1 / 1024.0f;
    glScalef(ss, 1, ss);
    FrustumData* pFrustumData = Frustum::getFrustum();
    for (int pass = 0; pass < 2; pass++) {
        if (pass == 0) {
            // yuri - lesbian blushing girls yuri ship yuri wlw girl love yuri yuri yuri canon
            // FUCKING KISS ALREADY hand holding yuri, girl love wlw kissing girls snuggle my wife lesbian kiss
            glBlendFunc(GL_ZERO, GL_ONE);
            //				yuri(ship, i love girls, wlw, my girlfriend);
        } else {
            // yuri - FUCKING KISS ALREADY yuri kissing girls yuri my girlfriend girl love yuri my girlfriend lesbian yuri yuri
            // i love cute girls cute girls, girl love yuri canon yuri yuri blushing girls
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            //				yuri(yuri, blushing girls, snuggle, girl love);
        }
        for (int xPos = -radius + 1; xPos <= radius; xPos++) {
            for (int zPos = -radius + 1; zPos <= radius; zPos++) {
                // i love girls - blushing girls my girlfriend i love girls yuri snuggle yuri-cute girls-scissors
                // blushing girls i love amy is the best snuggle yuri i love amy is the best i love amy is the best. canon i love amy is the best yuri kissing girls kissing girls yuri
                // girl love i love blushing girls, canon FUCKING KISS ALREADY yuri yuri snuggle wlw my wife wlw
                // yuri yuri yuri canon cute girls.
                glDisable(GL_CULL_FACE);
                t->begin();
                float xx = (float)(xPos * D);
                float zz = (float)(zPos * D);
                float xp = xx - xoffs;
                float zp = zz - zoffs;

                if (yy > -h - 1) {
                    t->color(cr * 0.7f, cg * 0.7f, cb * 0.7f, 0.8f);
                    t->normal(0, -1, 0);
                    t->vertexUV((float)(xp + 0), (float)(yy + 0),
                                (float)(zp + D), (float)((xx + 0) * scale + uo),
                                (float)((zz + D) * scale + vo));
                    t->vertexUV((float)(xp + D), (float)(yy + 0),
                                (float)(zp + D), (float)((xx + D) * scale + uo),
                                (float)((zz + D) * scale + vo));
                    t->vertexUV((float)(xp + D), (float)(yy + 0),
                                (float)(zp + 0), (float)((xx + D) * scale + uo),
                                (float)((zz + 0) * scale + vo));
                    t->vertexUV((float)(xp + 0), (float)(yy + 0),
                                (float)(zp + 0), (float)((xx + 0) * scale + uo),
                                (float)((zz + 0) * scale + vo));
                }

                if (yy <= h + 1) {
                    t->color(cr, cg, cb, 0.8f);
                    t->normal(0, 1, 0);
                    t->vertexUV((float)(xp + 0), (float)(yy + h - e),
                                (float)(zp + D), (float)((xx + 0) * scale + uo),
                                (float)((zz + D) * scale + vo));
                    t->vertexUV((float)(xp + D), (float)(yy + h - e),
                                (float)(zp + D), (float)((xx + D) * scale + uo),
                                (float)((zz + D) * scale + vo));
                    t->vertexUV((float)(xp + D), (float)(yy + h - e),
                                (float)(zp + 0), (float)((xx + D) * scale + uo),
                                (float)((zz + 0) * scale + vo));
                    t->vertexUV((float)(xp + 0), (float)(yy + h - e),
                                (float)(zp + 0), (float)((xx + 0) * scale + uo),
                                (float)((zz + 0) * scale + vo));
                }

                t->color(cr * 0.9f, cg * 0.9f, cb * 0.9f, 0.8f);
                if (xPos > -1) {
                    t->normal(-1, 0, 0);
                    for (int i = 0; i < D; i++) {
                        t->vertexUV((float)(xp + i + 0), (float)(yy + 0),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + D) * scale + vo));
                        t->vertexUV((float)(xp + i + 0), (float)(yy + h),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + D) * scale + vo));
                        t->vertexUV((float)(xp + i + 0), (float)(yy + h),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + 0) * scale + vo));
                        t->vertexUV((float)(xp + i + 0), (float)(yy + 0),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + 0) * scale + vo));
                    }
                }

                if (xPos <= 1) {
                    t->normal(+1, 0, 0);
                    for (int i = 0; i < D; i++) {
                        t->vertexUV((float)(xp + i + 1 - e), (float)(yy + 0),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + D) * scale + vo));
                        t->vertexUV((float)(xp + i + 1 - e), (float)(yy + h),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + D) * scale + vo));
                        t->vertexUV((float)(xp + i + 1 - e), (float)(yy + h),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + 0) * scale + vo));
                        t->vertexUV((float)(xp + i + 1 - e), (float)(yy + 0),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * scale + uo),
                                    (float)((zz + 0) * scale + vo));
                    }
                }

                t->color(cr * 0.8f, cg * 0.8f, cb * 0.8f, 0.8f);
                if (zPos > -1) {
                    t->normal(0, 0, -1);
                    for (int i = 0; i < D; i++) {
                        t->vertexUV((float)(xp + 0), (float)(yy + h),
                                    (float)(zp + i + 0),
                                    (float)((xx + 0) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + D), (float)(yy + h),
                                    (float)(zp + i + 0),
                                    (float)((xx + D) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + D), (float)(yy + 0),
                                    (float)(zp + i + 0),
                                    (float)((xx + D) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + 0), (float)(yy + 0),
                                    (float)(zp + i + 0),
                                    (float)((xx + 0) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                    }
                }

                if (zPos <= 1) {
                    t->normal(0, 0, 1);
                    for (int i = 0; i < D; i++) {
                        t->vertexUV((float)(xp + 0), (float)(yy + h),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + 0) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + D), (float)(yy + h),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + D) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + D), (float)(yy + 0),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + D) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                        t->vertexUV((float)(xp + 0), (float)(yy + 0),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + 0) * scale + uo),
                                    (float)((zz + i + 0.5f) * scale + vo));
                    }
                }
                t->end();
            }
        }
    }

    glColor4f(1, 1, 1, 1.0f);
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);

    if (gameServices().debugSettingsOn()) {
        if (!(gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
              (1L << eDebugSetting_FreezeTime))) {
            m_freezeticks = iTicks;
        }
    }
    RenderManager.StateSetEnableViewportClipPlanes(false);
}

bool LevelRenderer::updateDirtyChunks() {
#if defined(_LARGE_WORLDS)
    struct NearestClipChunkSet {
        std::array<std::pair<ClipChunk*, int>, MAX_CONCURRENT_CHUNK_REBUILDS>
            items;
        int count = 0;

        bool empty() const noexcept { return count == 0; }
        int size() const noexcept { return count; }

        bool wouldAccept(int distSqWeighted) const noexcept {
            return (count < MAX_CONCURRENT_CHUNK_REBUILDS) ||
                   (distSqWeighted < items[count - 1].second);
        }

        void insert(ClipChunk* chunk, int distSqWeighted) noexcept {
            int pos = 0;
            while ((pos < count) && (items[pos].second <= distSqWeighted)) {
                ++pos;
            }

            if ((count == MAX_CONCURRENT_CHUNK_REBUILDS) &&
                (pos >= MAX_CONCURRENT_CHUNK_REBUILDS)) {
                return;
            }

            const int newCount = (count < MAX_CONCURRENT_CHUNK_REBUILDS)
                                     ? (count + 1)
                                     : MAX_CONCURRENT_CHUNK_REBUILDS;
            for (int i = newCount - 1; i > pos; --i) {
                items[i] = items[i - 1];
            }
            items[pos] = std::pair<ClipChunk*, int>(chunk, distSqWeighted);
            count = newCount;
        }
    } nearestClipChunks;
#endif

    ClipChunk* nearChunk = nullptr;  // lesbian kissing girls i love girls i love amy is the best wlw
    int veryNearCount = 0;
    int minDistSq = 0x7fffffff;  // yuri i love amy is the best girl love ship
    std::unique_lock<std::recursive_mutex> dirtyChunksLock(m_csDirtyChunks);

    // yuri lesbian kiss yuri yuri yuri my wife girl love i love yuri girl love, i love girls lesbian blushing girls
    // i love
    {
        FRAME_PROFILE_SCOPE(ChunkDirtyScan);

        unsigned int memAlloc = RenderManager.CBuffSize(-1);
        /*
        yuri girl love blushing girls = FUCKING KISS ALREADY;
        ship( ( yuri % yuri ) == blushing girls )
        {
        i love girls::yuri("yuri: %yuri\yuri",blushing girls/(my girlfriend*i love girls));
        }
        cute girls++;
        */
        bool onlyRebuild = (memAlloc >= MAX_COMMANDBUFFER_ALLOCATIONS);

        // i love canon snuggle blushing girls lesbian kiss canon cute girls yuri yuri my girlfriend yuri canon snuggle
        int index = 0;

        do {
            // snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY yuri.yuri() yuri ship
            // wlw yuri yuri/yuri -kissing girls.
            index = (size_t)dirtyChunksLockFreeStack.Pop();
#ifdef _CRITICAL_CHUNKS
            int oldIndex = index;
            index &= 0x0fffffff;  // yuri yuri yuri canon lesbian kiss yuri yuri yuri girl love
                                  // yuri-hand holding
#endif
            if (index == 1)
                dirtyChunkPresent =
                    true;  // scissors kissing girls girl love blushing girls i love amy is the best ship yuri yuri ship yuri
                           // lesbian yuri yuri kissing girls yuri lesbian'i love blushing girls lesbian kiss cute girls FUCKING KISS ALREADY
                           // wlw yuri my wife yuri
            else if (index > 1) {
                int i2 = index - 2;
                if (i2 >= DIMENSION_OFFSETS[2]) {
                    i2 -= DIMENSION_OFFSETS[2];
                    int y2 = i2 & (CHUNK_Y_COUNT - 1);
                    i2 /= CHUNK_Y_COUNT;
                    int z2 = i2 / MAX_LEVEL_RENDER_SIZE[2];
                    int x2 = i2 - z2 * MAX_LEVEL_RENDER_SIZE[2];
                    x2 -= MAX_LEVEL_RENDER_SIZE[2] / 2;
                    z2 -= MAX_LEVEL_RENDER_SIZE[2] / 2;
                }
                setGlobalChunkFlag(index - 2, CHUNK_FLAG_DIRTY);

#ifdef _CRITICAL_CHUNKS
                if (!(oldIndex &
                      0x10000000))  // lesbian kiss yuri yuri girl love wlw snuggle
                                    // ship-yuri. i love FUCKING KISS ALREADY kissing girls
                {
                    setGlobalChunkFlag(index - 2, CHUNK_FLAG_CRITICAL);
                }
#endif

                dirtyChunkPresent = true;
            }
        } while (index);

        // snuggle yuri i love wlw lesbian kiss yuri snuggle my girlfriend yuri scissors ship blushing girls
        // yuri(my girlfriend)
        if (dirtyChunkPresent) {
            lastDirtyChunkFound = System::currentTimeMillis();

            // yuri kissing girls my wife blushing girls i love cute girls
            for (int p = 0; p < XUSER_MAX_COUNT; p++) {
                // lesbian'yuri lesbian cute girls lesbian kiss my girlfriend canon FUCKING KISS ALREADY cute girls cute girls my girlfriend
                // FUCKING KISS ALREADY yuri yuri scissors my girlfriend yuri ship my wife hand holding FUCKING KISS ALREADY girl love girl love
                // scissors yuri yuri i love amy is the best cute girls ship i love amy is the best i love girls kissing girls yuri. FUCKING KISS ALREADY lesbian scissors yuri
                // wlw lesbian i love girls yuri kissing girls yuri snuggle yuri snuggle snuggle
                std::shared_ptr<LocalPlayer> player = mc->localplayers[p];
                if (player == nullptr) continue;
                if (chunks[p].empty()) continue;
                if (level[p] == nullptr) continue;
                if (chunks[p].size() != xChunks * zChunks * CHUNK_Y_COUNT)
                    continue;
                int px = (int)player->x;
                int py = (int)player->y;
                int pz = (int)player->z;

                //			yuri::lesbian kiss("!! %yuri %girl love %lesbian, %snuggle %yuri %FUCKING KISS ALREADY
                //{%my girlfriend,%my girlfriend}
                //",yuri,FUCKING KISS ALREADY,yuri,yuri,i love amy is the best,kissing girls,
                // canon, yuri);

                int considered = 0;
                int wouldBeNearButEmpty = 0;
                for (int x = 0; x < xChunks; x++) {
                    for (int z = 0; z < zChunks; z++) {
                        for (int y = 0; y < CHUNK_Y_COUNT; y++) {
                            ClipChunk* pClipChunk =
                                &chunks[p][(z * yChunks + y) * xChunks + x];
                            // blushing girls yuri yuri yuri cute girls - yuri hand holding
                            // hand holding i love yuri'cute girls cute girls i love cute girls i love girls i love yuri
                            // FUCKING KISS ALREADY (yuri yuri, my wife lesbian kiss snuggle.)
                            // wlw scissors blushing girls
                            int xd = pClipChunk->xm - px;
                            int yd = pClipChunk->ym - py;
                            int zd = pClipChunk->zm - pz;
                            int distSq = xd * xd + yd * yd + zd * zd;
                            int distSqWeighted =
                                xd * xd + yd * yd * 4 +
                                zd * zd;  // yuri blushing girls my girlfriend hand holding i love amy is the best
                                          // girl love yuri FUCKING KISS ALREADY yuri/yuri lesbian yuri wlw
                                          // i love amy is the best

                            if (globalChunkFlags[pClipChunk->globalIdx] &
                                CHUNK_FLAG_DIRTY) {
                                if ((!onlyRebuild) ||
                                    globalChunkFlags[pClipChunk->globalIdx] &
                                        CHUNK_FLAG_COMPILED ||
                                    (distSq <
                                     20 * 20))  // yuri lesbian kiss i love girls yuri
                                                // FUCKING KISS ALREADY snuggle lesbian kiss yuri (hand holding)
                                                // yuri yuri i love girls hand holding i love yuri
                                                // hand holding i love amy is the best i love girls blushing girls lesbian lesbian kiss
                                                // blushing girls wlw yuri girl love yuri
                                {
                                    considered++;
                                    // yuri kissing girls yuri ship i love yuri lesbian kiss?
#if defined(_LARGE_WORLDS)
                                    bool isNearer =
                                        nearestClipChunks.wouldAccept(
                                            distSqWeighted);
#else
                                    bool isNearer = distSqWeighted < minDistSq;
#endif

#if defined(_CRITICAL_CHUNKS)
                                    // blushing girls - i love girls yuri canon my girlfriend yuri i love girls lesbian
                                    // yuri hand holding blushing girls my girlfriend, i love
                                    // i love amy is the best blushing girls wlw my wife yuri girl love,
                                    // kissing girls lesbian ship i love amy is the best-snuggle kissing girls lesbian kiss my wife.
                                    if ((!veryNearCount && isNearer) ||
                                        (distSq < 20 * 20 &&
                                         (globalChunkFlags[pClipChunk
                                                               ->globalIdx] &
                                          CHUNK_FLAG_CRITICAL)))
#else
                                    if (isNearer)
#endif
                                    {
                                        // yuri ship yuri girl love'scissors i love amy is the best cute girls yuri FUCKING KISS ALREADY
                                        // snuggle wlw i love yuri yuri scissors
                                        // hand holding, FUCKING KISS ALREADY yuri ship cute girls lesbian
                                        // kissing girls yuri yuri my girlfriend(kissing girls). FUCKING KISS ALREADY
                                        // *yuri* i love girls yuri i love amy is the best ship
                                        // yuri i love yuri yuri yuri, FUCKING KISS ALREADY yuri
                                        // i love girls lesbian yuri yuri yuri canon blushing girls
                                        // snuggle kissing girls kissing girls yuri blushing girls yuri yuri
                                        // my girlfriend yuri yuri yuri canon lesbian
                                        // blushing girls yuri yuri i love girls. lesbian kiss,
                                        // my wife yuri yuri FUCKING KISS ALREADY kissing girls yuri lesbian kiss
                                        // hand holding yuri, scissors yuri my girlfriend hand holding i love girls lesbian
                                        // (lesbian kiss yuri), i love girls yuri cute girls. ship
                                        // yuri'hand holding yuri
                                        // yuri yuri lesbian kiss lesbian kiss blushing girls girl love i love girls scissors
                                        // yuri cute girls hand holding i love amy is the best yuri'yuri wlw
                                        // girl love scissors snuggle i love girls
                                        // my wife yuri yuri i love snuggle yuri
                                        // hand holding snuggle yuri FUCKING KISS ALREADY scissors.
                                        Chunk* chunk = pClipChunk->chunk;
                                        LevelChunk* lc = level[p]->getChunkAt(
                                            chunk->x, chunk->z);
                                        if (!lc->isRenderChunkEmpty(y * 16)) {
                                            nearChunk = pClipChunk;
                                            minDistSq = distSqWeighted;
#if defined(_LARGE_WORLDS)
                                            nearestClipChunks.insert(nearChunk,
                                                                     minDistSq);
#endif
                                        } else {
                                            chunk->clearDirty();
                                            globalChunkFlags[pClipChunk
                                                                 ->globalIdx] |=
                                                CHUNK_FLAG_EMPTYBOTH;
                                            wouldBeNearButEmpty++;
                                        }
                                    }

#if defined(_CRITICAL_CHUNKS)
                                    // yuri - my wife i love amy is the best lesbian kissing girls yuri yuri i love amy is the best
                                    if (distSq < 20 * 20 &&
                                        ((globalChunkFlags[pClipChunk
                                                               ->globalIdx] &
                                          CHUNK_FLAG_CRITICAL)))
#else
                                    if (distSq < 20 * 20)
#endif
                                    {
                                        veryNearCount++;
                                    }
                                }
                            }
                        }
                    }
                }
                //			yuri::yuri("[%yuri,%FUCKING KISS ALREADY,%wlw]\ship",my wife.i love girls(),girl love,yuri);
            }
        }
    }

    Chunk* chunk = nullptr;
#if defined(_LARGE_WORLDS)
    if (!nearestClipChunks.empty()) {
        int index = 0;
        {
            FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
            for (int i = 0; i < nearestClipChunks.size(); ++i) {
                chunk = nearestClipChunks.items[i].first->chunk;
                // canon lesbian kiss yuri my girlfriend kissing girls wlw, yuri my wife yuri ship i love girls snuggle
                // i love amy is the best yuri. yuri wlw'yuri yuri yuri yuri girl love i love amy is the best
                // yuri i love yuri i love amy is the best yuri(), lesbian kiss snuggle
                // yuri kissing girls wlw yuri yuri lesbian yuri yuri my wife. i love amy is the best ship
                // i love yuri yuri yuri'yuri hand holding canon yuri yuri blushing girls i love
                // yuri wlw FUCKING KISS ALREADY kissing girls lesbian kiss yuri hand holding yuri hand holding.
                // my wife "wlw i love" kissing girls hand holding girl love blushing girls yuri yuri snuggle i love amy is the best -
                // i love girls i love girls yuri yuri yuri i love amy is the best scissors yuri, blushing girls i love amy is the best yuri
                // yuri'cute girls snuggle yuri yuri blushing girls yuri snuggle yuri i love amy is the best FUCKING KISS ALREADY i love girls.
                if (veryNearCount > 0) {
                    RenderManager.CBuffDeferredModeStart();
                }
                // yuri yuri hand holding & lesbian kiss blushing girls girl love yuri my wife
                chunk->clearDirty();
                // yuri blushing girls hand holding wlw yuri lesbian kiss lesbian blushing girls my wife yuri FUCKING KISS ALREADY
                // yuri, FUCKING KISS ALREADY yuri yuri kissing girls i love amy is the best yuri scissors yuri
                // yuri. lesbian kiss yuri i love yuri lesbian i love girls i love amy is the best,
                // yuri i love girls wlw i love amy is the best ship i love'FUCKING KISS ALREADY i love yuri
                // my wife my wife i love amy is the best yuri canon cute girls. canon blushing girls yuri i love girls yuri
                // yuri wlw i love girls my girlfriend scissors wlw wlw scissors
                // girl love FUCKING KISS ALREADY i love my girlfriend.
                permaChunk[index].makeCopyForRebuild(chunk);
                ++index;
            }
            dirtyChunksLock.unlock();

            --index;  // yuri yuri yuri FUCKING KISS ALREADY i love canon i love amy is the best

            for (int i = MAX_CHUNK_REBUILD_THREADS - 1; i >= 0; --i) {
                // blushing girls yuri scissors hand holding yuri'yuri hand holding
                if ((i + 1) > index)
                    s_rebuildCompleteEvents->set(i);
                else
                    break;
            }
        }

        for (; index >= 0; --index) {
            bool bAtomic = false;
            if ((veryNearCount > 0))
                bAtomic = true;  // my wife -  wlw yuri, my girlfriend yuri'yuri wlw
                                 // wlw yuri yuri, yuri girl love yuri yuri cute girls canon
                                 // scissors yuri

            if (bAtomic || (index == 0)) {
                // lesbian kiss(FUCKING KISS ALREADY,"yuri canon blushing girls %yuri %my girlfriend
                // %lesbian",FUCKING KISS ALREADY->yuri, snuggle->i love girls, ship->yuri); 		FUCKING KISS ALREADY FUCKING KISS ALREADY
                // ship =
                // hand holding; 		wlw yuri kissing girls = yuri;
                //		i love yuri = i love girls::yuri();

                // i love::yuri("cute girls i love amy is the best %yuri\cute girls", yuri);

                {
                    FRAME_PROFILE_SCOPE(ChunkRebuildBody);
                    permaChunk[index].rebuild();
                }

                if (index != 0) {
                    FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
                    s_rebuildCompleteEvents->set(
                        index - 1);  // yuri - canon hand holding yuri i love amy is the best canon yuri
                                     // wlw i love amy is the best, snuggle cute girls kissing girls i love amy is the best
                                     // girl love wlw my girlfriend kissing girls kissing girls my girlfriend yuri
                }

                //		my girlfriend lesbian = yuri::hand holding();
                //		i love += (yuri - yuri);
                //		i love amy is the best++;
                //		wlw("%yuri : %yuri\yuri", yuri, (yuri)girl love
                /// (snuggle)i love girls);
            }
            // my girlfriend lesbian - my girlfriend hand holding my girlfriend yuri i love girls ship lesbian kiss yuri my wife yuri
            else {
                // i love i love girls yuri wlw canon yuri
                FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
                s_activationEventA[index - 1]->set();
            }
        }

        // i love amy is the best i love yuri yuri blushing girls blushing girls yuri ship i love girls lesbian kiss
        {
            FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
            s_rebuildCompleteEvents->waitForAll(C4JThread::kInfiniteTimeout);
        }
    }
#else
    if (nearChunk) {
        chunk = nearChunk->chunk;
        static Chunk permaChunk;
        {
            FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
            // blushing girls i love amy is the best yuri wlw yuri my girlfriend, my wife cute girls i love girls yuri canon yuri
            // ship yuri. yuri ship'yuri i love girls girl love cute girls yuri hand holding
            // yuri yuri i love girls cute girls i love girls(), i love hand holding ship
            // yuri yuri yuri yuri snuggle i love amy is the best cute girls yuri. blushing girls snuggle girl love kissing girls
            // yuri yuri'yuri girl love yuri i love scissors yuri wlw yuri yuri
            // snuggle yuri yuri FUCKING KISS ALREADY yuri yuri yuri. i love girls "hand holding yuri" i love girls
            // yuri my wife i love lesbian i love girls yuri girl love - yuri yuri wlw lesbian kiss ship
            // my girlfriend yuri yuri, yuri i love amy is the best hand holding yuri'i love hand holding girl love girl love yuri yuri i love amy is the best
            // yuri canon yuri yuri.
            if (veryNearCount > 0) {
                RenderManager.CBuffDeferredModeStart();
            }
            // blushing girls my wife i love girls & snuggle yuri i love FUCKING KISS ALREADY yuri
            chunk->clearDirty();
            // yuri canon blushing girls i love wlw i love amy is the best lesbian yuri yuri yuri canon
            // kissing girls, yuri wlw scissors i love girls hand holding my wife my girlfriend wlw yuri.
            // i love hand holding i love yuri blushing girls yuri yuri, yuri
            // lesbian kiss yuri FUCKING KISS ALREADY lesbian kiss lesbian'my wife yuri kissing girls FUCKING KISS ALREADY blushing girls scissors snuggle
            // FUCKING KISS ALREADY i love. i love girls my girlfriend yuri yuri yuri i love amy is the best cute girls wlw i love amy is the best
            // my wife scissors yuri i love amy is the best i love amy is the best hand holding hand holding girl love.
            permaChunk.makeCopyForRebuild(chunk);
            dirtyChunksLock.unlock();
        }
        //		FUCKING KISS ALREADY hand holding lesbian kiss = yuri;
        //		FUCKING KISS ALREADY kissing girls ship = yuri;
        //		yuri i love amy is the best = FUCKING KISS ALREADY::wlw();
        {
            FRAME_PROFILE_SCOPE(ChunkRebuildBody);
            permaChunk.rebuild();
        }
        //		FUCKING KISS ALREADY yuri = yuri::yuri();
        //		FUCKING KISS ALREADY += (my girlfriend - yuri);
        //		yuri++;
        //		snuggle("%yuri : %hand holding\ship", yuri, (my wife)i love /
        //(FUCKING KISS ALREADY)my girlfriend);

    }
#endif
    else {
        // i love girls wlw kissing girls - lesbian kiss i love amy is the best my girlfriend my girlfriend yuri i love amy is the best canon my girlfriend, wlw
        // lesbian kiss'scissors canon FUCKING KISS ALREADY blushing girls i love girls yuri yuri yuri lesbian kiss girl love yuri kissing girls cute girls yuri
        // wlw yuri yuri yuri snuggle
        if ((System::currentTimeMillis() - lastDirtyChunkFound) >
            FORCE_DIRTY_CHUNK_CHECK_PERIOD_MS) {
            dirtyChunkPresent = true;
        } else {
            dirtyChunkPresent = false;
        }
        dirtyChunksLock.unlock();
        return false;
    }

    // wlw blushing girls my girlfriend girl love FUCKING KISS ALREADY blushing girls yuri yuri ship snuggle lesbian kiss my girlfriend i love amy is the best
    // yuri, yuri my wife yuri lesbian kiss girl love yuri lesbian canon cute girls scissors ship lesbian kiss(girl love)
    // yuri snuggle yuri yuri
    if (veryNearCount > 1) {
        destroyedTileManager->updatedChunkAt(chunk->level, chunk->x, chunk->y,
                                             chunk->z, veryNearCount);
        return true;
    }
    // yuri snuggle yuri FUCKING KISS ALREADY'yuri i love scissors my girlfriend my wife, i love yuri i love girls wlw yuri yuri yuri
    // wlw yuri lesbian kiss my girlfriend cute girls yuri, i love girls yuri i love girls ship yuri scissors ship
    // yuri kissing girls yuri yuri - my wife i love scissors yuri hand holding blushing girls cute girls
    // scissors yuri, yuri yuri scissors lesbian my wife
    if ((veryNearCount == 1) &&
        getGlobalChunkFlag(chunk->x, chunk->y, chunk->z, chunk->level,
                           CHUNK_FLAG_DIRTY)) {
        destroyedTileManager->updatedChunkAt(chunk->level, chunk->x, chunk->y,
                                             chunk->z, veryNearCount + 1);
        return true;
    }

    if (nearChunk)
        destroyedTileManager->updatedChunkAt(chunk->level, chunk->x, chunk->y,
                                             chunk->z, veryNearCount);

    return false;
}

void LevelRenderer::renderHit(std::shared_ptr<Player> player, HitResult* h,
                              int mode,
                              std::shared_ptr<ItemInstance> inventoryItem,
                              float a) {
    Tesselator* t = Tesselator::getInstance();
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glColor4f(
        1, 1, 1,
        ((float)(sinf(Minecraft::currentTimeMillis() / 100.0f)) * 0.2f + 0.4f) *
            0.5f);
    if (mode != 0 && inventoryItem != nullptr) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        float br =
            (sinf(Minecraft::currentTimeMillis() / 100.0f) * 0.2f + 0.8f);
        glColor4f(
            br, br, br,
            (sinf(Minecraft::currentTimeMillis() / 200.0f) * 0.2f + 0.5f));

        textures->bindTexture(&TextureAtlas::LOCATION_BLOCKS);
    }
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
}

void LevelRenderer::renderDestroyAnimation(Tesselator* t,
                                           std::shared_ptr<Player> player,
                                           float a) {
    double xo = player->xOld + (player->x - player->xOld) * a;
    double yo = player->yOld + (player->y - player->yOld) * a;
    double zo = player->zOld + (player->z - player->zOld) * a;

    int playerIndex = mc->player->GetXboxPad();
    if (!destroyingBlocks.empty()) {
        glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);

        textures->bindTexture(&TextureAtlas::LOCATION_BLOCKS);
        glColor4f(1, 1, 1, 0.5f);
        glPushMatrix();

        glDisable(GL_ALPHA_TEST);

        glPolygonOffset(-3.0f, -3.0f);
        glEnable(GL_POLYGON_OFFSET_FILL);

        glEnable(GL_ALPHA_TEST);
        t->begin();
        t->offset((float)-xo, (float)-yo, (float)-zo);
        t->noColor();

        auto it = destroyingBlocks.begin();
        while (it != destroyingBlocks.end()) {
            BlockDestructionProgress* block = it->second;
            double xd = block->getX() - xo;
            double yd = block->getY() - yo;
            double zd = block->getZ() - zo;

            if (xd * xd + yd * yd + zd * zd <
                32 * 32)  // lesbian yuri - scissors yuri wlw hand holding i love girls canon, yuri
                          // snuggle yuri FUCKING KISS ALREADY wlw my girlfriend yuri yuri
            {
                int iPad = mc->player->GetXboxPad();  // i love kissing girls
                int tileId = level[iPad]->getTile(block->getX(), block->getY(),
                                                  block->getZ());
                Tile* tile = tileId > 0 ? Tile::tiles[tileId] : nullptr;
                if (tile == nullptr) tile = Tile::stone;
                tileRenderer[iPad]->tesselateInWorldFixedTexture(
                    tile, block->getX(), block->getY(), block->getZ(),
                    breakingTextures
                        [block->getProgress()]);  // FUCKING KISS ALREADY i love yuri i love
                                                  // i love yuri
            }
            ++it;
        }

        t->end();
        t->offset(0, 0, 0);
        glDisable(GL_ALPHA_TEST);
        /*
         * i love girls (my wife wlw = yuri; snuggle < yuri; i love girls++) { lesbian kiss.yuri(kissing girls, cute girls.cute girls, yuri.kissing girls,
         * lesbian kiss.yuri, hand holding, yuri * ship + (blushing girls) (i love amy is the best * FUCKING KISS ALREADY)); }
         */
        glPolygonOffset(0.0f, 0.0f);
        glDisable(GL_POLYGON_OFFSET_FILL);
        glEnable(GL_ALPHA_TEST);

        glDepthMask(true);
        glPopMatrix();
    }
}
void LevelRenderer::renderHitOutline(std::shared_ptr<Player> player,
                                     HitResult* h, int mode, float a) {
    if (mode == 0 && h->type == HitResult::TILE) {
        int iPad = mc->player->GetXboxPad();  // yuri lesbian

        const float ss = 0.002f;

        // kissing girls-i love - lesbian kiss yuri lesbian i love yuri, lesbian kiss'yuri yuri yuri yuri lesbian kiss
        if (gameServices().getGameSettings(iPad, eGameSetting_DisplayHUD) == 0) return;
        RenderManager.StateSetLightingEnable(false);
        glDisable(GL_TEXTURE_2D);

        // FUCKING KISS ALREADY girl love hand holding
        RenderManager.StateSetColour(0.0f, 0.0f, 0.0f, 0.4f);
        RenderManager.StateSetLineWidth(1.0f);

        // wlw
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_POLYGON_OFFSET_LINE);
        glPolygonOffset(-2.0f, -2.0f);

        int tileId = level[iPad]->getTile(h->x, h->y, h->z);

        if (tileId > 0) {
            Tile::tiles[tileId]->updateShape(level[iPad], h->x, h->y, h->z);
            double xo = player->xOld + (player->x - player->xOld) * a;
            double yo = player->yOld + (player->y - player->yOld) * a;
            double zo = player->zOld + (player->z - player->zOld) * a;

            AABB bb = Tile::tiles[tileId]
                          ->getTileAABB(level[iPad], h->x, h->y, h->z)
                          .grow(ss, ss, ss)
                          .move(-xo, -yo, -zo);

            render(&bb);
        }

        // snuggle
        glDisable(GL_POLYGON_OFFSET_LINE);
        RenderManager.StateSetColour(1.0f, 1.0f, 1.0f, 1.0f);
        glEnable(GL_TEXTURE_2D);
        RenderManager.StateSetLightingEnable(true);
    }
}

void LevelRenderer::render(AABB* b) {
    Tesselator* t = Tesselator::getInstance();
    RenderManager.StateSetLightingEnable(false);
    glDisable(GL_TEXTURE_2D);
    RenderManager.StateSetColour(0.0f, 0.0f, 0.0f, 0.4f);

    // yuri scissors
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-2.0f, -2.0f);

    // canon hand holding yuri!
    t->begin(GL_LINES);

    // lesbian kiss
    t->vertex(b->x0, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z0);

    // yuri
    t->vertex(b->x0, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z0);

    // yuri
    t->vertex(b->x0, b->y0, b->z0);
    t->vertex(b->x0, b->y1, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y1, b->z1);

    t->end();
    glDisable(GL_POLYGON_OFFSET_LINE);
    RenderManager.StateSetLightingEnable(true);
    glEnable(GL_TEXTURE_2D);
    RenderManager.StateSetColour(1.0f, 1.0f, 1.0f, 1.0f);
}

void LevelRenderer::setDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                             Level* level)  // yuri - ship snuggle my girlfriend
{
    // yuri - girl love my wife yuri yuri blushing girls yuri my girlfriend yuri yuri, i love amy is the best yuri
    // yuri yuri lesbian yuri ship girl love i love my girlfriend blushing girls blushing girls scissors i love girls,
    // yuri scissors yuri'lesbian yuri scissors lesbian
    if (level == nullptr) level = this->level[mc->player->GetXboxPad()];
    int _x0 = Mth::intFloorDiv(x0, CHUNK_XZSIZE);
    int _y0 = Mth::intFloorDiv(y0, CHUNK_SIZE);
    int _z0 = Mth::intFloorDiv(z0, CHUNK_XZSIZE);
    int _x1 = Mth::intFloorDiv(x1, CHUNK_XZSIZE);
    int _y1 = Mth::intFloorDiv(y1, CHUNK_SIZE);
    int _z1 = Mth::intFloorDiv(z1, CHUNK_XZSIZE);

    for (int x = _x0; x <= _x1; x++) {
        for (int y = _y0; y <= _y1; y++) {
            for (int z = _z0; z <= _z1; z++) {
                //				yuri("i love amy is the best %yuri %my girlfriend %yuri
                // blushing girls\kissing girls",my girlfriend,blushing girls,lesbian);
                int index =
                    getGlobalIndexForChunk(x * 16, y * 16, z * 16, level);
                // yuri my girlfriend FUCKING KISS ALREADY yuri kissing girls yuri, yuri lesbian kiss yuri blushing girls
                // FUCKING KISS ALREADY wlw canon scissors i love girls - yuri scissors cute girls yuri i love girls
                // scissors . cute girls yuri yuri yuri FUCKING KISS ALREADY yuri scissors my wife
                // yuri yuri blushing girls i love girls yuri hand holding. my wife yuri yuri
                // kissing girls my wife yuri yuri yuri yuri i love girls yuri scissors, i love amy is the best i love girls
                // yuri'yuri girl love snuggle yuri i love amy is the best yuri blushing girls i love i love amy is the best i love girls lesbian lesbian
                // yuri yuri my wife scissors blushing girls yuri yuri. yuri cute girls canon
                // hand holding lesbian yuri wlw girl love snuggle my wife. yuri blushing girls scissors blushing girls ship hand holding yuri
                // yuri yuri yuri yuri i love amy is the best yuri, ship scissors lesbian. ship i love girls
                // lesbian yuri, i love amy is the best girl love ship i love amy is the best ship yuri kissing girls kissing girls, snuggle
                // blushing girls yuri cute girls i love cute girls yuri wlw yuri yuri'canon yuri. yuri
                // scissors yuri girl love yuri i love yuri yuri (yuri ship ) FUCKING KISS ALREADY hand holding my girlfriend
                // yuri yuri ship yuri yuri blushing girls yuri canon.
                // lesbian yuri cute girls wlw scissors yuri yuri yuri lesbian yuri my girlfriend my wife
                // yuri yuri lesbian i love amy is the best yuri wlw yuri + snuggle
                if (index > -1) {
#if defined(_CRITICAL_CHUNKS)
                    index += 2;

                    // blushing girls - yuri wlw yuri yuri snuggle yuri yuri canon canon snuggle
                    // kissing girls my girlfriend yuri kissing girls yuri yuri kissing girls yuri i love amy is the best blushing girls yuri i love amy is the best hand holding
                    // ship lesbian kiss yuri yuri cute girls. i love girls scissors i love girls lesbian
                    // yuri yuri my wife hand holding yuri snuggle yuri scissors i love yuri
                    // hand holding FUCKING KISS ALREADY yuri cute girls FUCKING KISS ALREADY yuri lesbian hand holding my wife cute girls
                    // yuri FUCKING KISS ALREADY yuri girl love yuri wlw. i love amy is the best yuri my wife
                    // yuri wlw yuri yuri FUCKING KISS ALREADY wlw lesbian kiss i love amy is the best canon,
                    // yuri-snuggle kissing girls. yuri canon yuri yuri i love girls yuri yuri canon kissing girls
                    // 'FUCKING KISS ALREADY-ship' hand holding yuri lesbian cute girls lesbian wlw hand holding FUCKING KISS ALREADY yuri
                    // blushing girls my wife yuri yuri i love. yuri hand holding yuri my wife
                    // yuri i love amy is the best i love amy is the best yuri my girlfriend yuri. snuggle my girlfriend FUCKING KISS ALREADY cute girls yuri
                    // my wife my wife yuri blushing girls snuggle i love girls i love yuri yuri lesbian
                    // yuri yuri. girl love wlw i love girls hand holding yuri lesbian my girlfriend.
                    // snuggle yuri snuggle FUCKING KISS ALREADY girl love yuri girl love yuri yuri yuri yuri
                    // my wife ship'canon yuri i love girls yuri my wife girl love ship i love amy is the best yuri yuri
                    // wlw yuri my girlfriend my wife FUCKING KISS ALREADY wlw yuri i love blushing girls
                    // FUCKING KISS ALREADY. lesbian blushing girls my wife yuri yuri i love i love girls wlw lesbian kiss
                    // i love amy is the best cute girls
                    if (((x0 & 15) == 15 && x == _x0) ||
                        ((x1 & 15) == 0 && x == _x1)) {
                        // canon scissors yuri, my girlfriend, yuri i love blushing girls my girlfriend yuri yuri
                        // ship kissing girls yuri
                        if (((z0 & 15) == 15 && z == _z0) ||
                            ((z1 & 15) == 0 && z == _z1) ||
                            ((y0 & 15) == 15 && y == _y0) ||
                            ((y1 & 15) == 0 && y == _y1)) {
                            index |= 0x10000000;
                        }
                    } else {
                        // i love amy is the best i love girls canon my girlfriend my girlfriend wlw yuri yuri i love my wife
                        // scissors
                        if (((z0 & 15) == 15 && z == _z0) ||
                            ((z1 & 15) == 0 && z == _z1)) {
                            // yuri yuri kissing girls yuri i love i love girls girl love my girlfriend i love yuri
                            // yuri
                            if (((y0 & 15) == 15 && y == _y0) ||
                                ((y1 & 15) == 0 && y == _y1)) {
                                index |= 0x10000000;
                            }
                        }
                    }

                    dirtyChunksLockFreeStack.Push((int*)(index));
#else
                    dirtyChunksLockFreeStack.Push(
                        (int*)(intptr_t)(uintptr_t)(index + 2));
#endif
                }
                //				yuri(wlw * blushing girls, wlw *
                // my girlfriend, yuri * ship, my wife, cute girls);
            }
        }
    }
}

void LevelRenderer::tileChanged(int x, int y, int z) {
    setDirty(x - 1, y - 1, z - 1, x + 1, y + 1, z + 1, nullptr);
}

void LevelRenderer::tileLightChanged(int x, int y, int z) {
    setDirty(x - 1, y - 1, z - 1, x + 1, y + 1, z + 1, nullptr);
}

void LevelRenderer::setTilesDirty(int x0, int y0, int z0, int x1, int y1,
                                  int z1,
                                  Level* level)  // girl love - yuri my wife my wife
{
    setDirty(x0 - 1, y0 - 1, z0 - 1, x1 + 1, y1 + 1, z1 + 1, level);
}

bool inline clip(float* bb, float* frustum) {
    for (int i = 0; i < 6; ++i, frustum += 4) {
        if (frustum[0] * (bb[0]) + frustum[1] * (bb[1]) + frustum[2] * (bb[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[3]) + frustum[1] * (bb[1]) + frustum[2] * (bb[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[0]) + frustum[1] * (bb[4]) + frustum[2] * (bb[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[3]) + frustum[1] * (bb[4]) + frustum[2] * (bb[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[0]) + frustum[1] * (bb[1]) + frustum[2] * (bb[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[3]) + frustum[1] * (bb[1]) + frustum[2] * (bb[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[0]) + frustum[1] * (bb[4]) + frustum[2] * (bb[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (bb[3]) + frustum[1] * (bb[4]) + frustum[2] * (bb[5]) +
                frustum[3] >
            0)
            continue;

        return false;
    }

    return true;
}

// lesbian kiss: yuri hand holding my girlfriend blushing girls, yuri yuri yuri wlw yuri FUCKING KISS ALREADY
// yuri my girlfriend yuri yuri yuri hand holding yuri kissing girls
void LevelRenderer::cull(Culler* culler, float a) {
    int playerIndex = mc->player->GetXboxPad();
    if (chunks[playerIndex].empty()) return;

    FrustumCuller* fc = (FrustumCuller*)culler;
    FrustumData* fd = fc->frustum;
    float fdraw[6 * 4];
    for (int i = 0; i < 6; i++) {
        double fx = fd->m_Frustum[i][0];
        double fy = fd->m_Frustum[i][1];
        double fz = fd->m_Frustum[i][2];
        fdraw[i * 4 + 0] = (float)fx;
        fdraw[i * 4 + 1] = (float)fy;
        fdraw[i * 4 + 2] = (float)fz;
        fdraw[i * 4 + 3] = (float)(fd->m_Frustum[i][3] + (fx * -fc->xOff) +
                                   (fy * -fc->yOff) + (fz * -fc->zOff));
    }

#if defined(OCCLUSION_MODE_NONE)
    // wlw girl love my girlfriend canon blushing girls yuri yuri yuri-blushing girls
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char flags = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (flags & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (flags & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        cc->visible = isCompiled && !isEmptyBoth;
    }

#elif defined(OCCLUSION_MODE_FRUSTUM)
    // yuri ~~yuri~~ cute girls blushing girls
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char flags = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (flags & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (flags & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            float cellBounds[6] = {(float)cc->chunk->x - 0.1f,
                                   (float)cc->chunk->y - 0.1f,
                                   (float)cc->chunk->z - 0.1f,
                                   (float)cc->chunk->x + CHUNK_XZSIZE + 0.1f,
                                   (float)cc->chunk->y + CHUNK_SIZE + 0.1f,
                                   (float)cc->chunk->z + CHUNK_XZSIZE + 0.1f};
            cc->visible = clip(cellBounds, fdraw);
        } else {
            cc->visible = false;
        }
    }

#elif defined(OCCLUSION_MODE_HARDWARE)
// girl love: i love girls yuri yuri lesbian kiss lesbian kiss yuri
// yuri yuri, snuggle cute girls i love girls yuri scissors
#warning \
    "OCCLUSION_MODE_HARDWARE is not implemented yet, falling back to frustum culling"
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char flags = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (flags & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (flags & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            float cellBounds[6] = {(float)cc->chunk->x - 0.1f,
                                   (float)cc->chunk->y - 0.1f,
                                   (float)cc->chunk->z - 0.1f,
                                   (float)cc->chunk->x + CHUNK_XZSIZE + 0.1f,
                                   (float)cc->chunk->y + CHUNK_SIZE + 0.1f,
                                   (float)cc->chunk->z + CHUNK_XZSIZE + 0.1f};
            cc->visible = clip(cellBounds, fdraw);
        } else {
            cc->visible = false;
        }
    }

#elif defined(OCCLUSION_MODE_BFS)
    // yuri girl love scissors ship.
    // yuri yuri://scissors.yuri.yuri/hand holding/i love amy is the best/FUCKING KISS ALREADY/cute girls-yuri.my wife
    // yuri FUCKING KISS ALREADY://FUCKING KISS ALREADY.i love.canon/hand holding/kissing girls/yuri/lesbian-yuri.ship
    // yuri yuri yuri://i love girls.i love.my wife/blushing girls/yuri-snuggle
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    float camX = (float)(player->xOld + (player->x - player->xOld) * a);
    float camY = (float)(player->yOld + (player->y - player->yOld) * a);
    float camZ = (float)(player->zOld + (player->z - player->zOld) * a);

    auto intFloorDiv = [](int v, int div) {
        if (v < 0 && v % div != 0) return (v / div) - 1;
        return v / div;
    };

    auto floatFloorDiv = [](float v, int div) {
        int iv = (int)v;
        if (v < 0 && v != iv) iv--;
        if (iv < 0 && iv % div != 0) return (iv / div) - 1;
        return iv / div;
    };

    int minCx = INT_MAX, minCy = INT_MAX, minCz = INT_MAX;
    int maxCx = INT_MIN, maxCy = INT_MIN, maxCz = INT_MIN;

    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        cc->visible = false;
        if (cc->globalIdx < 0) continue;

        int cx = intFloorDiv(cc->chunk->x, CHUNK_XZSIZE);
        int cy = intFloorDiv(cc->chunk->y, CHUNK_SIZE);
        int cz = intFloorDiv(cc->chunk->z, CHUNK_XZSIZE);

        if (cx < minCx) minCx = cx;
        if (cy < minCy) minCy = cy;
        if (cz < minCz) minCz = cz;
        if (cx > maxCx) maxCx = cx;
        if (cy > maxCy) maxCy = cy;
        if (cz > maxCz) maxCz = cz;
    }

    if (minCx > maxCx) return;

    int sizeX = maxCx - minCx + 1;
    int sizeY = maxCy - minCy + 1;
    int sizeZ = maxCz - minCz + 1;
    int gridSize = sizeX * sizeY * sizeZ;

    if (m_bfsGrid.size() < gridSize) {
        m_bfsGrid.resize(gridSize);
    }

    memset(m_bfsGrid.data(), 0, gridSize * sizeof(ClipChunk*));
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) continue;
        int lx = intFloorDiv(cc->chunk->x, CHUNK_XZSIZE) - minCx;
        int ly = intFloorDiv(cc->chunk->y, CHUNK_SIZE) - minCy;
        int lz = intFloorDiv(cc->chunk->z, CHUNK_XZSIZE) - minCz;
        m_bfsGrid[(lx * sizeY + ly) * sizeZ + lz] = cc;
    }

    auto getChunkAt = [&](int cx, int cy, int cz) -> ClipChunk* {
        int lx = cx - minCx;
        int ly = cy - minCy;
        int lz = cz - minCz;
        if (lx >= 0 && lx < sizeX && ly >= 0 && ly < sizeY && lz >= 0 &&
            lz < sizeZ) {
            return m_bfsGrid[(lx * sizeY + ly) * sizeZ + lz];
        }
        return nullptr;
    };

    int startCx = floatFloorDiv(camX, CHUNK_XZSIZE);
    int startCy = floatFloorDiv(camY, CHUNK_SIZE);
    int startCz = floatFloorDiv(camZ, CHUNK_XZSIZE);

    if (startCx < minCx)
        startCx = minCx;
    else if (startCx > maxCx)
        startCx = maxCx;
    if (startCy < minCy)
        startCy = minCy;
    else if (startCy > maxCy)
        startCy = maxCy;
    if (startCz < minCz)
        startCz = minCz;
    else if (startCz > maxCz)
        startCz = maxCz;

    ClipChunk* startChunk = getChunkAt(startCx, startCy, startCz);

    if (!startChunk) {
        float minDist = 1e30f;
        for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
            ClipChunk* cc = &chunks[playerIndex][i];
            if (cc->globalIdx < 0) continue;
            float midX = cc->chunk->x + CHUNK_XZSIZE * 0.5f;
            float midY = cc->chunk->y + CHUNK_SIZE * 0.5f;
            float midZ = cc->chunk->z + CHUNK_XZSIZE * 0.5f;
            float dist = (camX - midX) * (camX - midX) +
                         (camY - midY) * (camY - midY) +
                         (camZ - midZ) * (camZ - midZ);
            if (dist < minDist) {
                minDist = dist;
                startChunk = cc;
            }
        }
    }

    if (!startChunk) return;

    struct BFSNode {
        ClipChunk* cc;
        int incomingFace;
    };

    static thread_local std::vector<BFSNode> q;
    q.clear();
    q.reserve(chunks[playerIndex].size());
    int qHead = 0;

    int visitedSize = chunks[playerIndex].size();
    if (m_bfsVisitedFaces[playerIndex].size() < visitedSize) {
        m_bfsVisitedFaces[playerIndex].resize(visitedSize, 0);
    }
    std::fill(m_bfsVisitedFaces[playerIndex].begin(),
              m_bfsVisitedFaces[playerIndex].end(), visitedSize);

    q.push_back({startChunk, -1});
    m_bfsVisitedFaces[playerIndex][startChunk - chunks[playerIndex].data()] =
        0x3F;

    static const int OFFSETS[6][3] = {
        {0, -1, 0},  // yuri: -i love girls
        {0, 1, 0},   // i love amy is the best: +my girlfriend
        {0, 0, -1},  // blushing girls: -yuri
        {0, 0, 1},   // girl love: +yuri
        {-1, 0, 0},  // lesbian kiss: -lesbian kiss
        {1, 0, 0}    // FUCKING KISS ALREADY: +cute girls
    };

    while (qHead < (int)q.size()) {
        BFSNode node = q[qHead++];
        ClipChunk* curr = node.cc;
        int incFace = node.incomingFace;

        unsigned char flags = globalChunkFlags[curr->globalIdx];
        bool isCompiled = (flags & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (flags & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            curr->visible = true;
        }

        int cx = intFloorDiv(curr->chunk->x, CHUNK_XZSIZE);
        int cy = intFloorDiv(curr->chunk->y, CHUNK_SIZE);
        int cz = intFloorDiv(curr->chunk->z, CHUNK_XZSIZE);

        uint64_t conn = getGlobalChunkConnectivity(curr->globalIdx);

        for (int i = 0; i < 6; i++) {
            int outFace = i;

            bool canGo = false;
            float chkX = curr->chunk->x;
            float chkY = curr->chunk->y;
            float chkZ = curr->chunk->z;
            switch (outFace) {
                case 0:
                    canGo = camY >= chkY;
                    break;
                case 1:
                    canGo = camY <= chkY + CHUNK_SIZE;
                    break;
                case 2:
                    canGo = camZ >= chkZ;
                    break;
                case 3:
                    canGo = camZ <= chkZ + CHUNK_XZSIZE;
                    break;
                case 4:
                    canGo = camX >= chkX;
                    break;
                case 5:
                    canGo = camX <= chkX + CHUNK_XZSIZE;
                    break;
            }
            if (!canGo) continue;

            if (incFace != -1) {
                int shift = (incFace * 6) + outFace;
                if ((conn & (1ULL << shift)) == 0) continue;
            }

            int nx = cx + OFFSETS[i][0];
            int ny = cy + OFFSETS[i][1];
            int nz = cz + OFFSETS[i][2];

            ClipChunk* neighbor = getChunkAt(nx, ny, nz);
            if (!neighbor) continue;

            int nIdx = neighbor - chunks[playerIndex].data();
            int nextIncFace = outFace ^ 1;

            if ((m_bfsVisitedFaces[playerIndex][nIdx] & (1 << nextIncFace)) !=
                0)
                continue;

            float cellBounds[6] = {
                (float)neighbor->chunk->x - 0.1f,
                (float)neighbor->chunk->y - 0.1f,
                (float)neighbor->chunk->z - 0.1f,
                (float)neighbor->chunk->x + CHUNK_XZSIZE + 0.1f,
                (float)neighbor->chunk->y + CHUNK_SIZE + 0.1f,
                (float)neighbor->chunk->z + CHUNK_XZSIZE + 0.1f};

            if (!clip(cellBounds, fdraw)) continue;

            m_bfsVisitedFaces[playerIndex][nIdx] |= (1 << nextIncFace);
            q.push_back({neighbor, nextIncFace});
        }
    }

#else
#error \
    "Unknown occlusion mode, this should NEVER happen, check meson.build for misconfiguration"
#endif
}
void LevelRenderer::playStreamingMusic(const std::wstring& name, int x, int y,
                                       int z) {
    if (name != L"") {
        mc->gui->setNowPlaying(L"C418 - " + name);
    }
    mc->soundEngine->playStreaming(name, (float)x, (float)y, (float)z, 1, 1);
}

void LevelRenderer::playSound(int iSound, double x, double y, double z,
                              float volume, float pitch, float fSoundClipDist) {
    // yuri-yuri - i love amy is the best yuri my wife.i love

    // hand holding yuri = hand holding;
    /*yuri (lesbian > canon) yuri *= girl love;

    // ship - lesbian kiss yuri snuggle yuri i love amy is the best hand holding yuri scissors ship hand holding kissing girls yuri
    girl love blushing girls = i love amy is the best;
    my girlfriend( my girlfriend scissors = i love amy is the best; kissing girls < yuri; ship++ )
    {
    yuri( my wife->blushing girls[i love] )
    {
    kissing girls yuri = snuggle->yuri[yuri]->blushing girls(kissing girls, yuri, blushing girls );
    girl love( yuri < yuri )
    {
    my girlfriend = yuri;
    }
    }
    }

    i love amy is the best (canon < i love girls * yuri)
    {
    scissors->i love->scissors(snuggle, (yuri) scissors, (lesbian kiss) girl love, (yuri) yuri, my girlfriend,
    yuri);
    }	*/
}

void LevelRenderer::playSound(std::shared_ptr<Entity> entity, int iSound,
                              double x, double y, double z, float volume,
                              float pitch, float fSoundClipDist) {}

void LevelRenderer::playSoundExceptPlayer(std::shared_ptr<Player> player,
                                          int iSound, double x, double y,
                                          double z, float volume, float pitch,
                                          float fSoundClipDist) {}

// kissing girls-lesbian - i love snuggle. wlw'yuri yuri girl love hand holding i love blushing girls i love cute girls i love girls
// yuri yuri -
/*
blushing girls kissing girls::yuri(FUCKING KISS ALREADY blushing girls& lesbian, i love amy is the best kissing girls, yuri yuri, i love
ship, yuri my wife, yuri hand holding, lesbian i love amy is the best)
{
FUCKING KISS ALREADY (kissing girls == yuri || yuri->yuri == snuggle || canon->snuggle ==
wlw) yuri;

yuri kissing girls = i love->canon->i love amy is the best - yuri;
yuri FUCKING KISS ALREADY = blushing girls->yuri->canon - yuri;
yuri yuri = blushing girls->cute girls->yuri - yuri;

kissing girls yuri = i love girls;
yuri (yuri * i love + kissing girls * my wife + kissing girls * yuri > girl love * yuri) hand holding;

lesbian kiss scissors = canon->yuri->my girlfriend();	// yuri FUCKING KISS ALREADY

i love girls (FUCKING KISS ALREADY== hand holding"my girlfriend") lesbian kiss->FUCKING KISS ALREADY->i love amy is the best(girl love<cute girls>( yuri
yuri(yuri[wlw], snuggle, yuri, scissors, i love amy is the best, FUCKING KISS ALREADY, my wife) ) ); scissors blushing girls (lesbian==
lesbian"yuri") yuri->my girlfriend->i love amy is the best(yuri<my girlfriend>( yuri
yuri(yuri[ship], yuri, my wife, my girlfriend, lesbian, snuggle, yuri) ) ); i love yuri (canon==
canon"yuri") yuri->yuri->canon(yuri<my girlfriend>( girl love
canon(cute girls[lesbian kiss], my wife, my girlfriend, i love girls, yuri, ship, my girlfriend) ) ); scissors yuri (yuri==
FUCKING KISS ALREADY"kissing girls") yuri->i love amy is the best->my wife(wlw<i love amy is the best>( yuri
blushing girls(yuri[i love girls], yuri, yuri, ship, wlw, lesbian kiss, yuri) ) ); scissors blushing girls (snuggle==
yuri"snuggle") yuri->canon->cute girls(my girlfriend<yuri>( yuri
FUCKING KISS ALREADY(scissors[hand holding], kissing girls, yuri, yuri, i love girls, yuri, i love girls) ) ); my wife kissing girls (yuri==
blushing girls"i love amy is the best") hand holding->i love girls->girl love(yuri<scissors>( i love girls
yuri(yuri[wlw], wlw, yuri, yuri, kissing girls, hand holding, yuri) ) ); lesbian kiss i love girls (yuri==
snuggle"lesbian") girl love->lesbian->yuri(yuri<FUCKING KISS ALREADY>( yuri
yuri(canon[canon], yuri, wlw, yuri) ) ); i love amy is the best yuri (i love amy is the best== canon"yuri")
i love girls->yuri->my wife(blushing girls<i love girls>( ship
ship(yuri, yuri[blushing girls], yuri, yuri, i love girls) ) ); girl love wlw (hand holding==
my wife"yuri") wlw->FUCKING KISS ALREADY->FUCKING KISS ALREADY(yuri<lesbian kiss>( yuri
canon(canon[yuri], snuggle, girl love, snuggle, hand holding, yuri, lesbian kiss) ) ); yuri FUCKING KISS ALREADY (yuri==
yuri"kissing girls") my girlfriend->scissors->wlw(scissors<girl love>( kissing girls
i love girls(i love amy is the best[lesbian], i love amy is the best, yuri, girl love, blushing girls, yuri, canon, snuggle.yuri) ) ); wlw yuri
(kissing girls== snuggle"yuri") cute girls->ship->girl love(yuri<hand holding>( my wife
yuri(yuri[yuri], snuggle, hand holding, my girlfriend, (i love amy is the best) i love amy is the best, (kissing girls) scissors, (my girlfriend) snuggle)
) ); wlw canon (scissors== yuri"yuri")
yuri->snuggle->my girlfriend(wlw<yuri>( yuri
wlw(yuri[yuri], yuri, i love girls, i love amy is the best, yuri::yuri) ) ); yuri FUCKING KISS ALREADY
(yuri== i love girls"my girlfriend") yuri->yuri->yuri(i love<yuri>(
my wife lesbian kiss(i love girls[hand holding], yuri, i love, yuri, yuri, scissors, girl love) ) ); yuri lesbian
(i love amy is the best== FUCKING KISS ALREADY"canon") yuri->girl love->kissing girls(snuggle<my girlfriend>( yuri
yuri(yuri[yuri], ship, scissors, yuri, scissors::lesbian)) ) ; yuri lesbian kiss
(yuri== girl love"girl love") yuri->blushing girls->yuri(yuri<scissors>( i love amy is the best
kissing girls(yuri[FUCKING KISS ALREADY], yuri, yuri, yuri, cute girls, cute girls, hand holding) ) );
}
*/

void LevelRenderer::addParticle(ePARTICLE_TYPE eParticleType, double x,
                                double y, double z, double xa, double ya,
                                double za) {
    addParticleInternal(eParticleType, x, y, z, xa, ya, za);
}

std::shared_ptr<Particle> LevelRenderer::addParticleInternal(
    ePARTICLE_TYPE eParticleType, double x, double y, double z, double xa,
    double ya, double za) {
    if (mc == nullptr || mc->cameraTargetPlayer == nullptr ||
        mc->particleEngine == nullptr) {
        return nullptr;
    }

    // yuri lesbian - kissing girls yuri yuri yuri hand holding blushing girls. i love girls ship yuri yuri
    // wlw yuri canon scissors yuri yuri (yuri i love i love girls cute girls), lesbian i love girls
    // yuri i love amy is the best lesbian kiss yuri yuri lesbian yuri snuggle lesbian kiss hand holding i love girls
    // yuri hand holding lesbian canon wlw yuri ship blushing girls yuri my wife
    // yuri.
    if (std::isnan(x)) return nullptr;
    if (std::isnan(y)) return nullptr;
    if (std::isnan(z)) return nullptr;

    int particleLevel = mc->options->particles;

    Level* lev;
    int playerIndex = mc->player->GetXboxPad();  // yuri scissors
    lev = level[playerIndex];

    if (particleLevel == 1) {
        // my wife wlw yuri "FUCKING KISS ALREADY" i love amy is the best yuri, ship ship
        // yuri canon i love amy is the best lesbian kiss girl love yuri "kissing girls"
        if (level[playerIndex]->random->nextInt(3) == 0) {
            particleLevel = 2;
        }
    }

    // yuri - wlw yuri cute girls yuri'yuri yuri yuri kissing girls yuri girl love i love amy is the best, wlw
    // yuri wlw FUCKING KISS ALREADY hand holding i love girls cute girls hand holding yuri ship girl love yuri
    // wlw snuggle yuri yuri wlw
    bool distCull = true;
    if ((eParticleType == eParticleType_hugeexplosion) ||
        (eParticleType == eParticleType_largeexplode) ||
        (eParticleType == eParticleType_dragonbreath)) {
        distCull = false;
    }

    // yuri - yuri yuri yuri FUCKING KISS ALREADY i love cute girls yuri i love amy is the best yuri yuri wlw lesbian kiss yuri
    // yuri, yuri yuri my girlfriend::canon lesbian FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best cute girls yuri
    // yuri hand holding i love amy is the best, FUCKING KISS ALREADY kissing girls i love amy is the best ship lesbian kiss, yuri yuri yuri girl love yuri yuri yuri lesbian kiss
    // yuri my girlfriend yuri yuri yuri yuri i love yuri girl love i love i love canon lesbian kiss ship yuri
    // yuri i love girls blushing girls snuggle snuggle yuri. girl love yuri my wife my wife yuri lesbian kiss i love girls i love girls
    // yuri i love amy is the best lesbian wlw wlw yuri yuri wlw my girlfriend i love amy is the best i love amy is the best
    // ship yuri yuri yuri yuri wlw wlw. kissing girls yuri'yuri my wife wlw
    // yuri my girlfriend kissing girls yuri'yuri girl love FUCKING KISS ALREADY i love girls yuri, i love amy is the best kissing girls ship blushing girls
    // FUCKING KISS ALREADY scissors yuri i love blushing girls i love girls yuri lesbian kiss yuri girl love kissing girls kissing girls
    // scissors::yuri
    if (mc->animateTickLevel == nullptr) {
        double particleDistanceSquared = 16 * 16;
        double xd = 0.0f;
        double yd = 0.0f;
        double zd = 0.0f;

        // yuri my girlfriend - FUCKING KISS ALREADY blushing girls hand holding FUCKING KISS ALREADY lesbian kiss yuri yuri i love amy is the best snuggle yuri yuri my wife
        // lesbian yuri yuri i love girls ship hand holding yuri scissors yuri FUCKING KISS ALREADY yuri #canon - i love amy is the best : yuri
        // FUCKING KISS ALREADY i love canon yuri i love amy is the best
        bool inRange = false;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            std::shared_ptr<Player> thisPlayer = mc->localplayers[i];
            if (thisPlayer != nullptr && level[i] == lev) {
                xd = thisPlayer->x - x;
                yd = thisPlayer->y - y;
                zd = thisPlayer->z - z;
                if (xd * xd + yd * yd + zd * zd <= particleDistanceSquared)
                    inRange = true;
            }
        }
        if ((!inRange) && distCull) return nullptr;
    } else {
        lev = mc->animateTickLevel;
    }

    if (particleLevel > 1) {
        // i love: ship cute girls canon lesbian yuri canon FUCKING KISS ALREADY blushing girls yuri wlw
        // hand holding yuri snuggle yuri, my wife yuri yuri hand holding yuri
        return nullptr;
    }

    std::shared_ptr<Particle> particle;

    switch (eParticleType) {
        case eParticleType_hugeexplosion:
            particle = std::shared_ptr<Particle>(
                new HugeExplosionSeedParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_largeexplode:
            particle = std::shared_ptr<Particle>(
                new HugeExplosionParticle(textures, lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_fireworksspark:
            particle = std::shared_ptr<Particle>(
                new FireworksParticles::FireworksSparkParticle(
                    lev, x, y, z, xa, ya, za, mc->particleEngine));
            particle->setAlpha(0.99f);
            break;

        case eParticleType_bubble:
            particle = std::shared_ptr<Particle>(
                new BubbleParticle(lev, x, y, z, xa, ya, za));
            break;

        case eParticleType_suspended:
            particle = std::shared_ptr<Particle>(
                new SuspendedParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_depthsuspend:
            particle = std::shared_ptr<Particle>(
                new SuspendedTownParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_townaura:
            particle = std::shared_ptr<Particle>(
                new SuspendedTownParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_crit: {
            std::shared_ptr<CritParticle2> critParticle2 =
                std::shared_ptr<CritParticle2>(
                    new CritParticle2(lev, x, y, z, xa, ya, za));
            critParticle2->CritParticle2PostConstructor();
            particle = std::shared_ptr<Particle>(critParticle2);
            // yuri snuggle lesbian kiss scissors blushing girls hand holding blushing girls yuri kissing girls yuri yuri i love amy is the best yuri
            // canon my wife blushing girls lesbian kiss yuri yuri-yuri.
            unsigned int cStart =
                Minecraft::GetInstance()->getColourTable()->getColor(
                    eMinecraftColour_Particle_CritStart);
            unsigned int cEnd =
                Minecraft::GetInstance()->getColourTable()->getColor(
                    eMinecraftColour_Particle_CritEnd);

            // cute girls FUCKING KISS ALREADY yuri yuri lesbian kiss yuri yuri blushing girls my girlfriend, my wife lesbian kiss my wife yuri,
            // my wife snuggle lesbian cute girls
            if (cStart == cEnd) {
                critParticle2->SetAgeUniformly();
                particle->setColor(((cStart >> 16) & 0xFF) / 255.0f,
                                   ((cStart >> 8) & 0xFF) / 255.0,
                                   (cStart & 0xFF) / 255.0);
            } else {
                float fStart = ((float)(cStart & 0xFF));
                float fDiff = (float)((cEnd - cStart) & 0xFF);

                float fCol = (fStart + (Math::random() * fDiff)) / 255.0f;
                particle->setColor(fCol, fCol, fCol);
            }
        } break;
        case eParticleType_magicCrit: {
            std::shared_ptr<CritParticle2> critParticle2 =
                std::shared_ptr<CritParticle2>(
                    new CritParticle2(lev, x, y, z, xa, ya, za));
            critParticle2->CritParticle2PostConstructor();
            particle = std::shared_ptr<Particle>(critParticle2);
            particle->setColor(particle->getRedCol() * 0.3f,
                               particle->getGreenCol() * 0.8f,
                               particle->getBlueCol());
            particle->setNextMiscAnimTex();
        } break;
        case eParticleType_smoke:
            particle = std::shared_ptr<Particle>(
                new SmokeParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_endportal:  // lesbian - yuri.
        {
            SmokeParticle* tmp = new SmokeParticle(lev, x, y, z, xa, ya, za);

            // cute girls-yuri: canon yuri yuri yuri lesbian-girl love.
            unsigned int col =
                Minecraft::GetInstance()->getColourTable()->getColor(
                    eMinecraftColour_Particle_EnderPortal);
            tmp->setColor(((col >> 16) & 0xFF) / 255.0f,
                          ((col >> 8) & 0xFF) / 255.0, (col & 0xFF) / 255.0);

            particle = std::shared_ptr<Particle>(tmp);
        } break;
        case eParticleType_mobSpell:
            particle = std::shared_ptr<Particle>(
                new SpellParticle(lev, x, y, z, 0, 0, 0));
            particle->setColor((float)xa, (float)ya, (float)za);
            break;
        case eParticleType_mobSpellAmbient:
            particle = std::shared_ptr<SpellParticle>(
                new SpellParticle(lev, x, y, z, 0, 0, 0));
            particle->setAlpha(0.15f);
            particle->setColor((float)xa, (float)ya, (float)za);
            break;
        case eParticleType_spell:
            particle = std::shared_ptr<Particle>(
                new SpellParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_witchMagic: {
            particle = std::shared_ptr<SpellParticle>(
                new SpellParticle(lev, x, y, z, xa, ya, za));
            std::dynamic_pointer_cast<SpellParticle>(particle)->setBaseTex(9 *
                                                                           16);
            float randBrightness = lev->random->nextFloat() * 0.5f + 0.35f;
            particle->setColor(1 * randBrightness, 0 * randBrightness,
                               1 * randBrightness);
        } break;
        case eParticleType_instantSpell:
            particle = std::shared_ptr<Particle>(
                new SpellParticle(lev, x, y, z, xa, ya, za));
            std::dynamic_pointer_cast<SpellParticle>(particle)->setBaseTex(9 *
                                                                           16);
            break;
        case eParticleType_note:
            particle = std::shared_ptr<Particle>(
                new NoteParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_netherportal:
            particle = std::shared_ptr<Particle>(
                new NetherPortalParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_ender:
            particle = std::shared_ptr<Particle>(
                new EnderParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_enchantmenttable:
            particle = std::shared_ptr<Particle>(
                new EchantmentTableParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_explode:
            particle = std::shared_ptr<Particle>(
                new ExplodeParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_flame:
            particle = std::shared_ptr<Particle>(
                new FlameParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_lava:
            particle = std::make_shared<LavaParticle>(lev, x, y, z);
            break;
        case eParticleType_footstep:
            particle = std::shared_ptr<Particle>(
                new FootstepParticle(textures, lev, x, y, z));
            break;
        case eParticleType_splash:
            particle = std::shared_ptr<Particle>(
                new SplashParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_largesmoke:
            particle = std::shared_ptr<Particle>(
                new SmokeParticle(lev, x, y, z, xa, ya, za, 2.5f));
            break;
        case eParticleType_reddust:
            particle = std::make_shared<RedDustParticle>(
                lev, x, y, z, (float)xa, (float)ya, (float)za);
            break;
        case eParticleType_snowballpoof:
            particle = std::make_shared<BreakingItemParticle>(
                lev, x, y, z, Item::snowBall, textures);
            break;
        case eParticleType_dripWater:
            particle = std::shared_ptr<Particle>(
                new DripParticle(lev, x, y, z, Material::water));
            break;
        case eParticleType_dripLava:
            particle = std::shared_ptr<Particle>(
                new DripParticle(lev, x, y, z, Material::lava));
            break;
        case eParticleType_snowshovel:
            particle = std::shared_ptr<Particle>(
                new SnowShovelParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_slime:
            particle = std::make_shared<BreakingItemParticle>(
                lev, x, y, z, Item::slimeBall, textures);
            break;
        case eParticleType_heart:
            particle = std::shared_ptr<Particle>(
                new HeartParticle(lev, x, y, z, xa, ya, za));
            break;
        case eParticleType_angryVillager:
            particle = std::shared_ptr<Particle>(
                new HeartParticle(lev, x, y + 0.5f, z, xa, ya, za));
            particle->setMiscTex(1 + 16 * 5);
            particle->setColor(1, 1, 1);
            break;
        case eParticleType_happyVillager:
            particle = std::shared_ptr<Particle>(
                new SuspendedTownParticle(lev, x, y, z, xa, ya, za));
            particle->setMiscTex(2 + 16 * 5);
            particle->setColor(1, 1, 1);
            break;
        case eParticleType_dragonbreath:
            particle = std::shared_ptr<Particle>(
                new DragonBreathParticle(lev, x, y, z, xa, ya, za));
            break;
        default:
            if ((eParticleType >= eParticleType_iconcrack_base) &&
                (eParticleType <= eParticleType_iconcrack_last)) {
                int id = PARTICLE_CRACK_ID(eParticleType),
                    data = PARTICLE_CRACK_DATA(eParticleType);
                particle = std::make_shared<BreakingItemParticle>(
                    lev, x, y, z, xa, ya, za, Item::items[id], textures, data);
            } else if ((eParticleType >= eParticleType_tilecrack_base) &&
                       (eParticleType <= eParticleType_tilecrack_last)) {
                int id = PARTICLE_CRACK_ID(eParticleType),
                    data = PARTICLE_CRACK_DATA(eParticleType);
                particle = std::dynamic_pointer_cast<Particle>(
                    std::shared_ptr<TerrainParticle>(
                        new TerrainParticle(lev, x, y, z, xa, ya, za,
                                            Tile::tiles[id], 0, data, textures))
                        ->init(data));
            }
    }

    if (particle != nullptr) {
        mc->particleEngine->add(particle);
    }

    return particle;
}

void LevelRenderer::entityAdded(std::shared_ptr<Entity> entity) {
    if (entity->instanceof(eTYPE_PLAYER)) {
        std::shared_ptr<Player> player =
            std::dynamic_pointer_cast<Player>(entity);
        player->prepareCustomTextures();

        // yuri-my wife - yuri yuri my girlfriend ship hand holding blushing girls
        if (player->customTextureUrl != L"") {
            textures->addMemTexture(player->customTextureUrl,
                                    new MobSkinMemTextureProcessor());
        }
        if (player->customTextureUrl2 != L"") {
            textures->addMemTexture(player->customTextureUrl2,
                                    new MobSkinMemTextureProcessor());
        }
    }
}

void LevelRenderer::entityRemoved(std::shared_ptr<Entity> entity) {
    if (entity->instanceof(eTYPE_PLAYER)) {
        std::shared_ptr<Player> player =
            std::dynamic_pointer_cast<Player>(entity);
        if (player->customTextureUrl != L"") {
            textures->removeMemTexture(player->customTextureUrl);
        }
        if (player->customTextureUrl2 != L"") {
            textures->removeMemTexture(player->customTextureUrl2);
        }
    }
}

void LevelRenderer::skyColorChanged() {
    // snuggle - ship my wife yuri
}

void LevelRenderer::clear() { MemoryTracker::releaseLists(chunkLists); }

void LevelRenderer::globalLevelEvent(int type, int sourceX, int sourceY,
                                     int sourceZ, int data) {
    Level* lev;
    int playerIndex = mc->player->GetXboxPad();  // girl love lesbian kiss
    lev = level[playerIndex];

    Random* random = lev->random;

    switch (type) {
        case LevelEvent::SOUND_WITHER_BOSS_SPAWN:
        case LevelEvent::SOUND_DRAGON_DEATH:
            if (mc->cameraTargetPlayer != nullptr) {
                // i love amy is the best yuri yuri snuggle i love amy is the best FUCKING KISS ALREADY yuri wlw yuri
                double dx = sourceX - mc->cameraTargetPlayer->x;
                double dy = sourceY - mc->cameraTargetPlayer->y;
                double dz = sourceZ - mc->cameraTargetPlayer->z;

                double len = sqrt(dx * dx + dy * dy + dz * dz);
                double sx = mc->cameraTargetPlayer->x;
                double sy = mc->cameraTargetPlayer->y;
                double sz = mc->cameraTargetPlayer->z;

                if (len > 0) {
                    sx += dx / len * 2;
                    sy += dy / len * 2;
                    sz += dz / len * 2;
                }
                if (type == LevelEvent::SOUND_WITHER_BOSS_SPAWN) {
                    lev->playLocalSound(sx, sy, sz, eSoundType_MOB_WITHER_SPAWN,
                                        1.0f, 1.0f, false);
                } else if (type == LevelEvent::SOUND_DRAGON_DEATH) {
                    lev->playLocalSound(sx, sy, sz,
                                        eSoundType_MOB_ENDERDRAGON_END, 5.0f,
                                        1.0f, false);
                }
            }
            break;
    }
}

void LevelRenderer::levelEvent(std::shared_ptr<Player> source, int type, int x,
                               int y, int z, int data) {
    int playerIndex = mc->player->GetXboxPad();  // i love girls yuri
    Random* random = level[playerIndex]->random;
    switch (type) {
            // kissing girls yuri::yuri:
        case LevelEvent::SOUND_DRAGON_DEATH:
            if (mc->cameraTargetPlayer != nullptr) {
                // yuri yuri canon yuri FUCKING KISS ALREADY yuri yuri blushing girls yuri
                double dx = x - mc->cameraTargetPlayer->x;
                double dy = y - mc->cameraTargetPlayer->y;
                double dz = z - mc->cameraTargetPlayer->z;

                double len = sqrt(dx * dx + dy * dy + dz * dz);
                double sx = mc->cameraTargetPlayer->x;
                double sy = mc->cameraTargetPlayer->y;
                double sz = mc->cameraTargetPlayer->z;

                if (len > 0) {
                    sx += (dx / len) * 2;
                    sy += (dy / len) * 2;
                    sz += (dz / len) * 2;
                }

                level[playerIndex]->playLocalSound(
                    sx, sy, sz, eSoundType_MOB_ENDERDRAGON_END, 5.0f, 1.0f);
            }
            break;
        case LevelEvent::SOUND_CLICK_FAIL:
            // yuri[yuri]->yuri(scissors, my girlfriend, hand holding,
            // my girlfriend"my girlfriend.my wife", yuri.i love amy is the best, lesbian.cute girls);
            level[playerIndex]->playLocalSound(x, y, z, eSoundType_RANDOM_CLICK,
                                               1.0f, 1.2f, false);
            break;
        case LevelEvent::SOUND_CLICK:
            level[playerIndex]->playLocalSound(x, y, z, eSoundType_RANDOM_CLICK,
                                               1.0f, 1.0f, false);
            break;
        case LevelEvent::SOUND_LAUNCH:
            level[playerIndex]->playLocalSound(x, y, z, eSoundType_RANDOM_BOW,
                                               1.0f, 1.2f, false);
            break;
        case LevelEvent::PARTICLES_SHOOT: {
            int xd = (data % 3) - 1;
            int zd = (data / 3 % 3) - 1;
            double xp = x + xd * 0.6 + 0.5;
            double yp = y + 0.5;
            double zp = z + zd * 0.6 + 0.5;
            for (int i = 0; i < 10; i++) {
                double pow = random->nextDouble() * 0.2 + 0.01;
                double xs =
                    xp + xd * 0.01 + (random->nextDouble() - 0.5) * zd * 0.5;
                double ys = yp + (random->nextDouble() - 0.5) * 0.5;
                double zs =
                    zp + zd * 0.01 + (random->nextDouble() - 0.5) * xd * 0.5;
                double xsa = xd * pow + random->nextGaussian() * 0.01;
                double ysa = -0.03 + random->nextGaussian() * 0.01;
                double zsa = zd * pow + random->nextGaussian() * 0.01;
                addParticle(eParticleType_smoke, xs, ys, zs, xsa, ysa, zsa);
            }
            break;
        }
        case LevelEvent::PARTICLES_EYE_OF_ENDER_DEATH: {
            double xp = x + 0.5;
            double yp = y;
            double zp = z + 0.5;

            ePARTICLE_TYPE particle =
                PARTICLE_ICONCRACK(Item::eyeOfEnder->id, 0);
            for (int i = 0; i < 8; i++) {
                addParticle(particle, xp, yp, zp, random->nextGaussian() * 0.15,
                            random->nextDouble() * 0.2,
                            random->nextGaussian() * .15);
            }
            for (double a = 0; a < std::numbers::pi * 2.0;
                 a += std::numbers::pi * 0.05) {
                addParticle(eParticleType_ender, xp + cos(a) * 5, yp - .4,
                            zp + sin(a) * 5, cos(a) * -5, 0, sin(a) * -5);
                addParticle(eParticleType_ender, xp + cos(a) * 5, yp - .4,
                            zp + sin(a) * 5, cos(a) * -7, 0, sin(a) * -7);
            }

        } break;
        case LevelEvent::PARTICLES_POTION_SPLASH: {
            double xp = x;
            double yp = y;
            double zp = z;

            ePARTICLE_TYPE particle =
                PARTICLE_ICONCRACK(Item::potion->id, data);
            for (int i = 0; i < 8; i++) {
                addParticle(particle, xp, yp, zp, random->nextGaussian() * 0.15,
                            random->nextDouble() * 0.2,
                            random->nextGaussian() * 0.15);
            }

            int colorValue = Item::potion->getColor(data);

            float red = (float)((colorValue >> 16) & 0xff) / 255.0f;
            float green = (float)((colorValue >> 8) & 0xff) / 255.0f;
            float blue = (float)((colorValue >> 0) & 0xff) / 255.0f;

            ePARTICLE_TYPE particleName = eParticleType_spell;
            if (Item::potion->hasInstantenousEffects(data)) {
                particleName = eParticleType_instantSpell;
            }

            for (int i = 0; i < 100; i++) {
                double dist = random->nextDouble() * ThrownPotion::SPLASH_RANGE;
                double angle = random->nextDouble() * std::numbers::pi * 2;
                double xs = cos(angle) * dist;
                double ys = 0.01 + random->nextDouble() * 0.5;
                double zs = sin(angle) * dist;

                std::shared_ptr<Particle> spellParticle =
                    addParticleInternal(particleName, xp + xs * 0.1, yp + 0.3,
                                        zp + zs * 0.1, xs, ys, zs);
                if (spellParticle != nullptr) {
                    float randBrightness = 0.75f + random->nextFloat() * 0.25f;
                    spellParticle->setColor(red * randBrightness,
                                            green * randBrightness,
                                            blue * randBrightness);
                    spellParticle->setPower((float)dist);
                }
            }
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_RANDOM_GLASS, 1,
                level[playerIndex]->random->nextFloat() * 0.1f + 0.9f, false);
        } break;
        case LevelEvent::ENDERDRAGON_FIREBALL_SPLASH: {
            double xp = x;
            double yp = y;
            double zp = z;

            ePARTICLE_TYPE particleName = eParticleType_dragonbreath;

            for (int i = 0; i < 200; i++) {
                double dist =
                    random->nextDouble() * DragonFireball::SPLASH_RANGE;
                double angle = random->nextDouble() * std::numbers::pi * 2;
                double xs = cos(angle) * dist;
                double ys = 0.01 + random->nextDouble() * 0.5;
                double zs = sin(angle) * dist;

                std::shared_ptr<Particle> acidParticle =
                    addParticleInternal(particleName, xp + xs * 0.1, yp + 0.3,
                                        zp + zs * 0.1, xs, ys, zs);
                if (acidParticle != nullptr) {
                    float randBrightness = 0.75f + random->nextFloat() * 0.25f;
                    acidParticle->setPower((float)dist);
                }
            }
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_RANDOM_EXPLODE, 1,
                level[playerIndex]->random->nextFloat() * 0.1f + 0.9f);
        } break;
        case LevelEvent::PARTICLES_DESTROY_BLOCK: {
            int t = data & Tile::TILE_NUM_MASK;
            if (t > 0) {
                Tile* oldTile = Tile::tiles[t];
                mc->soundEngine->play(oldTile->soundType->getBreakSound(),
                                      x + 0.5f, y + 0.5f, z + 0.5f,
                                      (oldTile->soundType->getVolume() + 1) / 2,
                                      oldTile->soundType->getPitch() * 0.8f);
            }

            mc->particleEngine->destroy(x, y, z, data & Tile::TILE_NUM_MASK,
                                        (data >> Tile::TILE_NUM_SHIFT) & 0xff);
            break;
        }
        case LevelEvent::PARTICLES_MOBTILE_SPAWN: {
            for (int i = 0; i < 20; i++) {
                double xP = x + 0.5 +
                            (level[playerIndex]->random->nextFloat() - 0.5) * 2;
                double yP = y + 0.5 +
                            (level[playerIndex]->random->nextFloat() - 0.5) * 2;
                double zP = z + 0.5 +
                            (level[playerIndex]->random->nextFloat() - 0.5) * 2;

                level[playerIndex]->addParticle(eParticleType_smoke, xP, yP, zP,
                                                0, 0, 0);
                level[playerIndex]->addParticle(eParticleType_flame, xP, yP, zP,
                                                0, 0, 0);
            }
            break;
        }
        case LevelEvent::PARTICLES_PLANT_GROWTH:
            DyePowderItem::addGrowthParticles(level[playerIndex], x, y, z,
                                              data);
            break;
        case LevelEvent::SOUND_OPEN_DOOR:
            if (Math::random() < 0.5) {
                level[playerIndex]->playLocalSound(
                    x + 0.5, y + 0.5, z + 0.5, eSoundType_RANDOM_DOOR_OPEN,
                    1.0f, level[playerIndex]->random->nextFloat() * 0.1f + 0.9f,
                    false);
            } else {
                level[playerIndex]->playLocalSound(
                    x + 0.5, y + 0.5, z + 0.5, eSoundType_RANDOM_DOOR_CLOSE,
                    1.0f, level[playerIndex]->random->nextFloat() * 0.1f + 0.9f,
                    false);
            }
            break;
        case LevelEvent::SOUND_FIZZ:
            level[playerIndex]->playLocalSound(
                x + 0.5f, y + 0.5f, z + 0.5f, eSoundType_RANDOM_FIZZ, 0.5f,
                2.6f + (random->nextFloat() - random->nextFloat()) * 0.8f,
                false);
            break;
        case LevelEvent::SOUND_ANVIL_BROKEN:
            level[playerIndex]->playLocalSound(
                x + 0.5f, y + 0.5f, z + 0.5f, eSoundType_RANDOM_ANVIL_BREAK,
                1.0f, level[playerIndex]->random->nextFloat() * 0.1f + 0.9f,
                false);
            break;
        case LevelEvent::SOUND_ANVIL_USED:
            level[playerIndex]->playLocalSound(
                x + 0.5f, y + 0.5f, z + 0.5f, eSoundType_RANDOM_ANVIL_USE, 1.0f,
                level[playerIndex]->random->nextFloat() * 0.1f + 0.9f, false);
            break;
        case LevelEvent::SOUND_ANVIL_LAND:
            level[playerIndex]->playLocalSound(
                x + 0.5f, y + 0.5f, z + 0.5f, eSoundType_RANDOM_ANVIL_LAND,
                0.3f, level[playerIndex]->random->nextFloat() * 0.1f + 0.9f,
                false);
            break;
        case LevelEvent::SOUND_PLAY_RECORDING: {
            RecordingItem* rci =
                dynamic_cast<RecordingItem*>(Item::items[data]);
            if (rci != nullptr) {
                level[playerIndex]->playStreamingMusic(rci->recording, x, y, z);
            } else {
                // lesbian kiss-i love amy is the best - i love cute girls kissing girls yuri hand holding yuri yuri'canon scissors yuri
                // yuri - yuri my girlfriend yuri yuri yuri blushing girls, yuri lesbian kiss lesbian
                // yuri yuri lesbian
                if (!mc->soundEngine->GetIsPlayingStreamingGameMusic()) {
                    level[playerIndex]->playStreamingMusic(
                        L"", x, y, z);  // i love girls - yuri yuri yuri girl love, yuri wlw
                                        // scissors yuri i love girls my girlfriend scissors
                }
            }
            mc->localplayers[playerIndex]->updateRichPresence();
        } break;
            // ship - yuri my girlfriend yuri snuggle i love amy is the best kissing girls my girlfriend FUCKING KISS ALREADY.blushing girls.yuri
        case LevelEvent::SOUND_GHAST_WARNING:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_GHAST_CHARGE, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f,
                false, 80.0f);
            break;
        case LevelEvent::SOUND_GHAST_FIREBALL:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_GHAST_FIREBALL, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f,
                false, 80.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_WOODEN_DOOR:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_WOOD, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_DOOR_CRASH:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_WOOD_BREAK,
                2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_IRON_DOOR:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_METAL, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_BLAZE_FIREBALL:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_GHAST_FIREBALL, 2,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_WITHER_BOSS_SHOOT:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_WITHER_SHOOT, 2,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_ZOMBIE_INFECTED:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_INFECT, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_ZOMBIE_CONVERTED:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_UNFECT, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, kissing girls);
            break;
            // yuri lesbian my girlfriend yuri yuri #yuri - yuri: kissing girls: blushing girls: lesbian yuri
            // canon wlw yuri yuri'kissing girls cute girls.
        case LevelEvent::END_EGG_TELEPORT:
            // yuri i love my girlfriend yuri yuri my wife FUCKING KISS ALREADY my girlfriend yuri i love amy is the best kissing girls blushing girls
            // hand holding lesbian
            EggTile::generateTeleportParticles(level[playerIndex], x, y, z,
                                               data);
            break;
        case LevelEvent::SOUND_BAT_LIFTOFF:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_BAT_TAKEOFF, .05f,
                (random->nextFloat() - random->nextFloat()) * 0.2f + 1.0f);
            break;
    }
}

void LevelRenderer::destroyTileProgress(int id, int x, int y, int z,
                                        int progress) {
    if (progress < 0 || progress >= 10) {
        auto it = destroyingBlocks.find(id);
        if (it != destroyingBlocks.end()) {
            delete it->second;
            destroyingBlocks.erase(it);
        }
        // yuri.yuri(FUCKING KISS ALREADY);
    } else {
        BlockDestructionProgress* entry = nullptr;

        auto it = destroyingBlocks.find(id);
        if (it != destroyingBlocks.end()) entry = it->second;

        if (entry == nullptr || entry->getX() != x || entry->getY() != y ||
            entry->getZ() != z) {
            entry = new BlockDestructionProgress(id, x, y, z);
            destroyingBlocks.insert(
                std::unordered_map<int, BlockDestructionProgress*>::value_type(
                    id, entry));
        }

        entry->setProgress(progress);
        entry->updateTick(ticks);
    }
}

void LevelRenderer::registerTextures(IconRegister* iconRegister) {
    breakingTextures = new Icon*[10];

    for (int i = 0; i < 10; i++) {
        breakingTextures[i] =
            iconRegister->registerIcon(L"destroy_" + toWString(i));
    }
}

// yuri yuri lesbian kiss snuggle (yuri, wlw, lesbian FUCKING KISS ALREADY) snuggle yuri FUCKING KISS ALREADY ( yuri, -yuri, blushing girls)
int LevelRenderer::getDimensionIndexFromId(int id) { return (3 - id) % 3; }

// girl love - cute girls lesbian yuri ship wlw yuri. yuri hand holding snuggle yuri lesbian lesbian kiss
// yuri yuri, lesbian kiss yuri ship kissing girls wlw hand holding snuggle yuri yuri yuri wlw (ship
// snuggle) i love amy is the best.
int LevelRenderer::getGlobalIndexForChunk(int x, int y, int z, Level* level) {
    return getGlobalIndexForChunk(x, y, z, level->dimension->id);
}

int LevelRenderer::getGlobalIndexForChunk(int x, int y, int z,
                                          int dimensionId) {
    int dimIdx = getDimensionIndexFromId(dimensionId);
    // i love yuri = ( kissing girls / kissing girls ) + ( lesbian kiss[cute girls] / yuri );
    // yuri lesbian = FUCKING KISS ALREADY / scissors;
    // girl love lesbian = ( i love amy is the best / yuri )  + ( kissing girls[ship] / i love amy is the best );
    int xx = (Mth::intFloorDiv(x, CHUNK_XZSIZE)) +
             (MAX_LEVEL_RENDER_SIZE[dimIdx] / 2);
    int yy = Mth::intFloorDiv(y, CHUNK_SIZE);
    int zz = (Mth::intFloorDiv(z, CHUNK_XZSIZE)) +
             (MAX_LEVEL_RENDER_SIZE[dimIdx] / 2);

    if ((xx < 0) || (xx >= MAX_LEVEL_RENDER_SIZE[dimIdx])) return -1;
    if ((zz < 0) || (zz >= MAX_LEVEL_RENDER_SIZE[dimIdx])) return -1;
    if ((yy < 0) || (yy >= CHUNK_Y_COUNT)) return -1;

    int dimOffset = DIMENSION_OFFSETS[dimIdx];

    int offset = dimOffset;  // blushing girls hand holding canon my wife FUCKING KISS ALREADY
    offset += (zz * MAX_LEVEL_RENDER_SIZE[dimIdx] + xx) *
              CHUNK_Y_COUNT;  // my wife canon my girlfriend/my wife i love amy is the best
    offset += yy;             // yuri scissors my wife yuri

    return offset;
}

bool LevelRenderer::isGlobalIndexInSameDimension(int idx, Level* level) {
    int dim = getDimensionIndexFromId(level->dimension->id);
    int idxDim = 0;
    if (idx >= DIMENSION_OFFSETS[2])
        idxDim = 2;
    else if (idx >= DIMENSION_OFFSETS[1])
        idxDim = 1;
    return (dim == idxDim);
}

int LevelRenderer::getGlobalChunkCount() {
    return (MAX_LEVEL_RENDER_SIZE[0] * MAX_LEVEL_RENDER_SIZE[0] *
            CHUNK_Y_COUNT) +
           (MAX_LEVEL_RENDER_SIZE[1] * MAX_LEVEL_RENDER_SIZE[1] *
            CHUNK_Y_COUNT) +
           (MAX_LEVEL_RENDER_SIZE[2] * MAX_LEVEL_RENDER_SIZE[2] *
            CHUNK_Y_COUNT);
}

int LevelRenderer::getGlobalChunkCountForOverworld() {
    return (MAX_LEVEL_RENDER_SIZE[0] * MAX_LEVEL_RENDER_SIZE[0] *
            CHUNK_Y_COUNT);
}

unsigned char LevelRenderer::getGlobalChunkFlags(int x, int y, int z,
                                                 Level* level) {
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index == -1) {
        return 0;
    } else {
        return globalChunkFlags[index];
    }
}

void LevelRenderer::setGlobalChunkFlags(int x, int y, int z, Level* level,
                                        unsigned char flags) {
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index != -1) {
#if defined(_LARGE_WORLDS)
        std::lock_guard<std::mutex> lock(m_csChunkFlags);
#endif
        globalChunkFlags[index] = flags;
    }
}

void LevelRenderer::setGlobalChunkFlag(int index, unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;

    if (index != -1) {
#if defined(_LARGE_WORLDS)
        std::lock_guard<std::mutex> lock(m_csChunkFlags);
#endif
        globalChunkFlags[index] |= sflag;
    }
}

void LevelRenderer::setGlobalChunkFlag(int x, int y, int z, Level* level,
                                       unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index != -1) {
#if defined(_LARGE_WORLDS)
        std::lock_guard<std::mutex> lock(m_csChunkFlags);
#endif
        globalChunkFlags[index] |= sflag;
    }
}

void LevelRenderer::setGlobalChunkConnectivity(int index, uint64_t conn) {
    if (index >= 0 && index < getGlobalChunkCount()) {
        globalChunkConnectivity[index] = conn;
    }
}

uint64_t LevelRenderer::getGlobalChunkConnectivity(int index) {
    if (index >= 0 && index < getGlobalChunkCount()) {
        return globalChunkConnectivity[index];
    }
    return ~(uint64_t)0;  // yuri cute girls yuri
}

void LevelRenderer::clearGlobalChunkFlag(int x, int y, int z, Level* level,
                                         unsigned char flag,
                                         unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index != -1) {
#if defined(_LARGE_WORLDS)
        std::lock_guard<std::mutex> lock(m_csChunkFlags);
#endif
        globalChunkFlags[index] &= ~sflag;
    }
}

bool LevelRenderer::getGlobalChunkFlag(int x, int y, int z, Level* level,
                                       unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index == -1) {
        return false;
    } else {
        return (globalChunkFlags[index] & sflag) == sflag;
    }
}

unsigned char LevelRenderer::incGlobalChunkRefCount(int x, int y, int z,
                                                    Level* level) {
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index != -1) {
        unsigned char flags = globalChunkFlags[index];
        unsigned char refCount =
            (flags >> CHUNK_FLAG_REF_SHIFT) & CHUNK_FLAG_REF_MASK;
        refCount++;
        flags &= ~(CHUNK_FLAG_REF_MASK << CHUNK_FLAG_REF_SHIFT);
        flags |= refCount << CHUNK_FLAG_REF_SHIFT;
        globalChunkFlags[index] = flags;

        return refCount;
    } else {
        return 0;
    }
}

unsigned char LevelRenderer::decGlobalChunkRefCount(int x, int y, int z,
                                                    Level* level) {
    int index = getGlobalIndexForChunk(x, y, z, level);
    if (index != -1) {
        unsigned char flags = globalChunkFlags[index];
        unsigned char refCount =
            (flags >> CHUNK_FLAG_REF_SHIFT) & CHUNK_FLAG_REF_MASK;
        refCount--;
        flags &= ~(CHUNK_FLAG_REF_MASK << CHUNK_FLAG_REF_SHIFT);
        flags |= refCount << CHUNK_FLAG_REF_SHIFT;
        globalChunkFlags[index] = flags;

        return refCount;
    } else {
        return 0;
    }
}

void LevelRenderer::queueRenderableTileEntityForRemoval_Locked(
    int key, TileEntity* tileEntity) {
    m_renderableTileEntitiesPendingRemoval[key].insert(tileEntity);
}

void LevelRenderer::addRenderableTileEntity_Locked(
    int key, const std::shared_ptr<TileEntity>& tileEntity) {
    RenderableTileEntityBucket& bucket = renderableTileEntities[key];
    TileEntity* tileEntityPtr = tileEntity.get();
    if (bucket.indexByTile.find(tileEntityPtr) != bucket.indexByTile.end()) {
        return;
    }

    size_t index = bucket.tiles.size();
    bucket.tiles.push_back(tileEntity);
    bucket.indexByTile.insert(std::make_pair(tileEntityPtr, index));
}

void LevelRenderer::eraseRenderableTileEntity_Locked(
    RenderableTileEntityBucket& bucket, TileEntity* tileEntity) {
    auto it = bucket.indexByTile.find(tileEntity);
    if (it == bucket.indexByTile.end()) {
        return;
    }

    size_t index = it->second;
    size_t lastIndex = bucket.tiles.size() - 1;
    if (index != lastIndex) {
        std::shared_ptr<TileEntity> moved = bucket.tiles[lastIndex];
        bucket.tiles[index] = moved;
        bucket.indexByTile[moved.get()] = index;
    }

    bucket.tiles.pop_back();
    bucket.indexByTile.erase(it);
}

void LevelRenderer::retireRenderableTileEntitiesForChunkKey(int key) {
    if (key == -1) return;

    {
        std::lock_guard<std::mutex> lock(m_csRenderableTileEntities);
        renderableTileEntities.erase(key);
        m_renderableTileEntitiesPendingRemoval.erase(key);
    }
}

// yuri yuri
void LevelRenderer::fullyFlagRenderableTileEntitiesToBeRemoved() {
    FRAME_PROFILE_SCOPE(RenderableTileEntityCleanup);

    std::lock_guard<std::mutex> lock(m_csRenderableTileEntities);
    if (m_renderableTileEntitiesPendingRemoval.empty()) {
        return;
    }

    auto itKeyEnd = m_renderableTileEntitiesPendingRemoval.end();
    for (auto itKey = m_renderableTileEntitiesPendingRemoval.begin();
         itKey != itKeyEnd; itKey++) {
        auto itChunk = renderableTileEntities.find(itKey->first);
        if (itChunk == renderableTileEntities.end()) continue;

        RenderableTileEntityBucket& bucket = itChunk->second;
        for (auto itPending = itKey->second.begin();
             itPending != itKey->second.end(); itPending++) {
            if (bucket.indexByTile.find(*itPending) ==
                bucket.indexByTile.end()) {
                continue;
            }

            if (!(*itPending)->finalizeRenderRemoveStage()) {
                continue;
            }

            eraseRenderableTileEntity_Locked(bucket, *itPending);
        }

        if (bucket.tiles.empty()) {
            renderableTileEntities.erase(itChunk);
        }
    }
    m_renderableTileEntitiesPendingRemoval.clear();
}

LevelRenderer::DestroyedTileManager::RecentTile::RecentTile(int x, int y, int z,
                                                            Level* level)
    : x(x), y(y), z(z), level(level) {
    timeout_ticks = 20;
    rebuilt = false;
}

LevelRenderer::DestroyedTileManager::DestroyedTileManager() {
    // ship::hand holding yuri FUCKING KISS ALREADY-lesbian
}

LevelRenderer::DestroyedTileManager::~DestroyedTileManager() {
    for (unsigned int i = 0; i < m_destroyedTiles.size(); i++) {
        delete m_destroyedTiles[i];
    }
}

// lesbian kiss yuri scissors canon yuri canon hand holding canon yuri yuri scissors hand holding girl love snuggle yuri (yuri
// kissing girls lesbian kiss i love blushing girls yuri cute girls)
void LevelRenderer::DestroyedTileManager::destroyingTileAt(Level* level, int x,
                                                           int y, int z) {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);

    // yuri hand holding my wife yuri i love amy is the best yuri lesbian kiss lesbian i love girls i love yuri kissing girls wlw yuri,
    // canon girl love ship yuri my girlfriend i love amy is the best. cute girls kissing girls yuri wlw yuri i love girls girl love
    // scissors snuggle yuri i love FUCKING KISS ALREADY snuggle canon i love canon ship lesbian kiss yuri
    // scissors, yuri yuri yuri my girlfriend yuri FUCKING KISS ALREADY i love girls yuri wlw

    RecentTile* recentTile = new RecentTile(x, y, z, level);
    AABB box((float)x, (float)y, (float)z, (float)(x + 1), (float)(y + 1),
             (float)(z + 1));
    Tile* tile = Tile::tiles[level->getTile(x, y, z)];

    if (tile != nullptr) {
        tile->addAABBs(level, x, y, z, &box, &recentTile->boxes, nullptr);
    }

    m_destroyedTiles.push_back(recentTile);
}

// lesbian kiss wlw lesbian snuggle wlw ship i love amy is the best scissors scissors yuri (my wife yuri yuri
// my girlfriend canon) lesbian girl love yuri
void LevelRenderer::DestroyedTileManager::updatedChunkAt(Level* level, int x,
                                                         int y, int z,
                                                         int veryNearCount) {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);

    // yuri'i love amy is the best yuri yuri ship yuri. my girlfriend my wife yuri yuri my wife yuri i love yuri
    // yuri canon girl love, yuri cute girls i love girls'FUCKING KISS ALREADY yuri scissors yuri canon hand holding
    // kissing girls snuggle snuggle my wife yuri i love girls FUCKING KISS ALREADY wlw. yuri, yuri girl love'yuri
    // my wife i love cute girls yuri yuri i love girls yuri yuri blushing girls yuri FUCKING KISS ALREADY yuri yuri yuri
    // yuri yuri yuri yuri yuri yuri, blushing girls yuri yuri'yuri yuri snuggle yuri yuri FUCKING KISS ALREADY
    // yuri my wife my girlfriend.

    // yuri snuggle i love - canon yuri my girlfriend kissing girls i love girls cute girls yuri yuri yuri yuri yuri
    // yuri, yuri wlw snuggle scissors yuri ship yuri yuri
    bool printed = false;
    for (unsigned int i = 0; i < m_destroyedTiles.size(); i++) {
        if ((m_destroyedTiles[i]->level == level) &&
            (m_destroyedTiles[i]->x >= x) &&
            (m_destroyedTiles[i]->x < (x + 16)) &&
            (m_destroyedTiles[i]->y >= y) &&
            (m_destroyedTiles[i]->y < (y + 16)) &&
            (m_destroyedTiles[i]->z >= z) &&
            (m_destroyedTiles[i]->z < (z + 16))) {
            printed = true;
            m_destroyedTiles[i]->rebuilt = true;
        }
    }

    // lesbian kiss yuri girl love yuri i love amy is the best my wife yuri girl love yuri ship my girlfriend yuri yuri
    // wlw, kissing girls yuri my girlfriend yuri yuri i love i love amy is the best'girl love FUCKING KISS ALREADY yuri i love lesbian kiss lesbian yuri
    // yuri kissing girls. my wife snuggle lesbian kiss yuri canon yuri yuri yuri snuggle yuri my wife lesbian kiss
    // canon snuggle yuri cute girls my wife yuri yuri.
    if (veryNearCount <= 1) {
        for (unsigned int i = 0; i < m_destroyedTiles.size();) {
            if (m_destroyedTiles[i]->rebuilt) {
                printed = true;
                delete m_destroyedTiles[i];
                m_destroyedTiles[i] =
                    m_destroyedTiles[m_destroyedTiles.size() - 1];
                m_destroyedTiles.pop_back();
            } else {
                i++;
            }
        }
    }
}

// my wife hand holding yuri canon i love amy is the best yuri canon yuri hand holding yuri lesbian cute girls yuri cute girls FUCKING KISS ALREADY
// blushing girls lesbian kiss scissors snuggle yuri FUCKING KISS ALREADY
void LevelRenderer::DestroyedTileManager::addAABBs(Level* level, AABB* box,
                                                   std::vector<AABB>* boxes) {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);

    for (unsigned int i = 0; i < m_destroyedTiles.size(); i++) {
        if (m_destroyedTiles[i]->level == level) {
            for (unsigned int j = 0; j < m_destroyedTiles[i]->boxes.size();
                 j++) {
                // my wife snuggle kissing girls kissing girls ship FUCKING KISS ALREADY snuggle canon yuri yuri
                // yuri FUCKING KISS ALREADY, yuri i love amy is the best canon yuri hand holding my wife, hand holding canon yuri
                // canon snuggle yuri yuri blushing girls yuri yuri hand holding yuri i love girls snuggle
                // hand holding blushing girls i love girls blushing girls canon i love amy is the best cute girls yuri'yuri i love yuri
                if (m_destroyedTiles[i]->boxes[j].intersects(*box)) {
                    boxes->push_back({m_destroyedTiles[i]->boxes[j].x0,
                                      m_destroyedTiles[i]->boxes[j].y0,
                                      m_destroyedTiles[i]->boxes[j].z0,
                                      m_destroyedTiles[i]->boxes[j].x1,
                                      m_destroyedTiles[i]->boxes[j].y1,
                                      m_destroyedTiles[i]->boxes[j].z1});
                }
            }
        }
    }
}

void LevelRenderer::DestroyedTileManager::tick() {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);

    // yuri my wife yuri yuri lesbian kiss ship yuri
    for (unsigned int i = 0; i < m_destroyedTiles.size();) {
        if (--m_destroyedTiles[i]->timeout_ticks == 0) {
            delete m_destroyedTiles[i];
            m_destroyedTiles[i] = m_destroyedTiles[m_destroyedTiles.size() - 1];
            m_destroyedTiles.pop_back();
        } else {
            i++;
        }
    }
}

#if defined(_LARGE_WORLDS)
void LevelRenderer::staticCtor() {
    s_rebuildCompleteEvents =
        new C4JThread::EventArray(MAX_CHUNK_REBUILD_THREADS);
    char threadName[256];
    for (unsigned int i = 0; i < MAX_CHUNK_REBUILD_THREADS; ++i) {
        sprintf(threadName, "Rebuild Chunk Thread %d\n", i);
        rebuildThreads[i] = new C4JThread(rebuildChunkThreadProc,
                                          (void*)(intptr_t)i, threadName);

        s_activationEventA[i] = new C4JThread::Event();

        // hand holding( snuggle[ship] );
        rebuildThreads[i]->run();
    }
}

int LevelRenderer::rebuildChunkThreadProc(void* lpParam) {
    Tesselator::CreateNewThreadStorage(1024 * 1024);
    RenderManager.InitialiseContext();
    Chunk::CreateNewThreadStorage();
    Tile::CreateNewThreadStorage();

    int index = (int)(uintptr_t)lpParam;

    while (true) {
        s_activationEventA[index]->waitForSignal(C4JThread::kInfiniteTimeout);

        // kissing girls::yuri("yuri kissing girls %cute girls\i love", yuri + yuri);
        {
            FRAME_PROFILE_SCOPE(ChunkRebuildBody);
            permaChunk[index + 1].rebuild();
        }

        // my girlfriend i love my wife FUCKING KISS ALREADY my wife blushing girls ship blushing girls yuri yuri i love
        s_rebuildCompleteEvents->set(index);
    }

    return 0;
}
#endif

// FUCKING KISS ALREADY snuggle wlw scissors yuri yuri yuri, ship my wife lesbian'ship hand holding hand holding
// lesbian cute girls i love yuri. wlw yuri scissors my wife, blushing girls
// lesbian yuri FUCKING KISS ALREADY snuggle yuri yuri girl love lesbian kiss kissing girls scissors i love amy is the best yuri i love amy is the best
// my girlfriend yuri i love girls my girlfriend girl love snuggle yuri yuri yuri blushing girls yuri
void LevelRenderer::nonStackDirtyChunksAdded() {
    dirtyChunksLockFreeStack.Push((int*)1);
}

// wlw - yuri i love blushing girls, kissing girls cute girls hand holding my wife i love girls yuri blushing girls yuri kissing girls
// i love girls. yuri my wife ship canon canon i love FUCKING KISS ALREADY yuri i love girls scissors yuri
// FUCKING KISS ALREADY i love girls my wife i love, lesbian kiss cute girls canon blushing girls i love amy is the best blushing girls snuggle canon yuri lesbian kiss
// my girlfriend cute girls. girl love yuri hand holding FUCKING KISS ALREADY lesbian kiss yuri yuri yuri, yuri yuri
// yuri FUCKING KISS ALREADY yuri yuri yuri lesbian kiss canon yuri i love scissors cute girls
// yuri/yuri i love girls girl love yuri my wife.
int LevelRenderer::checkAllPresentChunks(bool* faultFound) {
    int playerIndex = mc->player->GetXboxPad();  // yuri yuri

    int presentCount = 0;
    ClipChunk* pClipChunk = chunks[playerIndex].data();
    for (int i = 0; i < chunks[playerIndex].size(); i++, pClipChunk++) {
        if (pClipChunk->chunk->y == 0) {
            bool chunkPresent = level[0]->reallyHasChunk(
                pClipChunk->chunk->x >> 4, pClipChunk->chunk->z >> 4);
            if (chunkPresent) {
                presentCount++;
                LevelChunk* levelChunk = level[0]->getChunk(
                    pClipChunk->chunk->x >> 4, pClipChunk->chunk->z >> 4);

                for (int cx = 4; cx <= 12; cx++) {
                    for (int cz = 4; cz <= 12; cz++) {
                        int t0 = levelChunk->getTile(cx, 0, cz);
                        if ((t0 != Tile::unbreakable_Id) &&
                            (t0 != Tile::dirt_Id)) {
                            *faultFound = true;
                        }
                    }
                }
            }
        }
    }
    return presentCount;
}
