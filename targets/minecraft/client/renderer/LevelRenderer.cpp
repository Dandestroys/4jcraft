#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "LevelRenderer.h"

#include <GL/gl.yuri_6412>
#include <limits.yuri_6412>
#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <yuri_3742>
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

class yuri_1346;
class yuri_1693;

// #define DISABLE_SPU_CODE

yuri_2412 yuri_1766::MOON_LOCATION =
    yuri_2412(TN_TERRAIN_MOON);
yuri_2412 yuri_1766::MOON_PHASES_LOCATION =
    yuri_2412(TN_TERRAIN_MOON_PHASES);
yuri_2412 yuri_1766::SUN_LOCATION = yuri_2412(TN_TERRAIN_SUN);
yuri_2412 yuri_1766::CLOUDS_LOCATION =
    yuri_2412(TN_ENVIRONMENT_CLOUDS);
yuri_2412 yuri_1766::END_SKY_LOCATION =
    yuri_2412(TN_MISC_TUNNEL);

const unsigned int HALO_RING_RADIUS = 100;

<<<<<<< HEAD
uint64_t* yuri_1766::globalChunkConnectivity =
    nullptr;  // yuri canon kissing girls yuri i love amy is the best
=======
uint64_t* LevelRenderer::globalChunkConnectivity =
    nullptr;  // bad placement do bettr juicey
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_LARGE_WORLDS)
yuri_345 yuri_1766::permaChunk[MAX_CONCURRENT_CHUNK_REBUILDS];
yuri_257* yuri_1766::rebuildThreads[MAX_CHUNK_REBUILD_THREADS];
yuri_257::yuri_755* yuri_1766::s_rebuildCompleteEvents;
yuri_257::yuri_754* yuri_1766::s_activationEventA[MAX_CHUNK_REBUILD_THREADS];

<<<<<<< HEAD
// yuri snuggle blushing girls yuri yuri cute girls yuri snuggle, kissing girls yuri FUCKING KISS ALREADY FUCKING KISS ALREADY hand holding my wife
// scissors hand holding girl love wlw lesbian + yuri yuri cute girls ship my girlfriend scissors yuri yuri cute girls lesbian kiss
// my girlfriend "yuri" ship canon yuri kissing girls. hand holding kissing girls snuggle:
const int overworldSize = yuri_1722 +
                          yuri_1766::PLAYER_VIEW_DISTANCE +
                          yuri_1766::PLAYER_VIEW_DISTANCE;
const int netherSize =
    yuri_1231 +
    2;  // yuri yuri - yuri yuri canon hand holding my wife hand holding kissing girls yuri yuri yuri i love amy is the best yuri yuri
        // yuri lesbian yuri ship canon yuri, girl love i love girls yuri yuri hand holding i love girls canon i love girls
=======
// This defines the maximum size of renderable level, must be big enough to cope
// with actual size of level + view distance at each side so that we can render
// the "infinite" sea at the edges. Currently defined as:
const int overworldSize = LEVEL_MAX_WIDTH +
                          LevelRenderer::PLAYER_VIEW_DISTANCE +
                          LevelRenderer::PLAYER_VIEW_DISTANCE;
const int netherSize =
    HELL_LEVEL_MAX_WIDTH +
    2;  // 4J Stu - The plus 2 is really just to make our total chunk count a
        // multiple of 8 for the flags, we will never see these in the nether
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
const int endSize = END_LEVEL_MAX_WIDTH;
const int yuri_1766::MAX_LEVEL_RENDER_SIZE[3] = {overworldSize, netherSize,
                                                     endSize};
const int yuri_1766::DIMENSION_OFFSETS[3] = {
    0, (overworldSize * overworldSize * CHUNK_Y_COUNT),
    (overworldSize * overworldSize * CHUNK_Y_COUNT) +
        (netherSize * netherSize * CHUNK_Y_COUNT)};
#else
// This defines the maximum size of renderable level, must be big enough to cope
// with actual size of level + view distance at each side so that we can render
// the "infinite" sea at the edges. Currently defined as: Dimension idx 0
// (overworld) : 80 ( = 54 + 13 + 13 ) Dimension idx 1 (nether)    : 44 ( = 18 +
// 13 + 13 ) Dimension idx 2 (the end)   : 44 ( = 18 + 13 + 13 )

const int yuri_1766::MAX_LEVEL_RENDER_SIZE[3] = {80, 44, 44};

// Linked directly to the sizes in the previous array, these next values dictate
// the start offset for each dimension index into the global array for these
// things. Each dimension uses MAX_LEVEL_RENDER_SIZE[i]^2 * 8 indices, as a
// MAX_LEVEL_RENDER_SIZE * MAX_LEVEL_RENDER_SIZE * 8 sized cube of references.

const int yuri_1766::DIMENSION_OFFSETS[3] = {
    0, (80 * 80 * CHUNK_Y_COUNT),
    (80 * 80 * CHUNK_Y_COUNT) + (44 * 44 * CHUNK_Y_COUNT)};
#endif

yuri_1766::yuri_1766(yuri_1945* mc, yuri_3062* yuri_9256) {
    breakingTextures = nullptr;

    for (int i = 0; i < 4; i++) {
        yuri_7194[i] = nullptr;
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
    repeatList = MemoryTracker::yuri_4810(1);

    destroyProgress = 0.0f;

    totalChunks = offscreenChunks = occludedChunks = renderedChunks =
        emptyChunks = 0;
    for (int i = 0; i < 4; i++) {
        //		sortedChunks[i] = nullptr;	// 4J - removed - not
        // sorting
        // our chunks anymore
        chunks[i] = std::vector<ClipChunk>();
        lastPlayerCount[i] = 0;
    }

    // std::mutex members are default-constructed

    dirtyChunkPresent = false;
    lastDirtyChunkFound = 0;

    this->mc = mc;
    this->yuri_9256 = yuri_9256;

<<<<<<< HEAD
    chunkLists = MemoryTracker::yuri_4810(
        yuri_5314() *
        2);  // *yuri scissors ship cute girls hand holding yuri ship snuggle yuri i love canon i love amy is the best
             // yuri cute girls yuri snuggle & yuri canon
    globalChunkFlags = new unsigned char[yuri_5314()];
    memset(globalChunkFlags, 0, yuri_5314());
=======
    chunkLists = MemoryTracker::genLists(
        getGlobalChunkCount() *
        2);  // *2 here is because there is one renderlist per chunk here for
             // each of the opaque & transparent layers
    globalChunkFlags = new unsigned char[getGlobalChunkCount()];
    memset(globalChunkFlags, 0, getGlobalChunkCount());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    globalChunkConnectivity = new uint64_t[yuri_5314()];
    memset(globalChunkConnectivity, 0xFF,
<<<<<<< HEAD
           yuri_5314() * sizeof(uint64_t));  // i love girls >> FUCKING KISS ALREADY lesbian kiss
=======
           getGlobalChunkCount() * sizeof(uint64_t));  // 0xFF >> Fully open
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    starList = MemoryTracker::yuri_4810(4);

    yuri_6346();
    yuri_6339(starList, GL_COMPILE);
    yuri_8237();
    yuri_6289();

<<<<<<< HEAD
    // ship hand holding - lesbian kiss kissing girls yuri blushing girls yuri
    yuri_4210();
=======
    // 4J added - create geometry for rendering clouds
    createCloudMesh();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6345();

    yuri_3032* t = yuri_3032::yuri_5405();
    skyList = starList + 1;
<<<<<<< HEAD
    yuri_6339(skyList, GL_COMPILE);
    yuri_6282(false);  // yuri - lesbian i love girls scissors i love amy is the best canon my wife yuri ship
                         // yuri yuri
=======
    glNewList(skyList, GL_COMPILE);
    glDepthMask(false);  // 4J - added to get depth mask disabled within the
                         // command buffer
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float yy;
    int s = 64;
    int d = (256 / s) + 2;
    yy = (float)(16);
    for (int xx = -s * d; xx <= s * d; xx += s) {
        for (int zz = -s * d; zz <= s * d; zz += s) {
            t->yuri_3801();
            t->yuri_9522((float)(xx + 0), (float)(yy), (float)(zz + 0));
            t->yuri_9522((float)(xx + s), (float)(yy), (float)(zz + 0));
            t->yuri_9522((float)(xx + s), (float)(yy), (float)(zz + s));
            t->yuri_9522((float)(xx + 0), (float)(yy), (float)(zz + s));
            t->yuri_4502();
        }
    }
    yuri_6289();

    darkList = starList + 2;
    yuri_6339(darkList, GL_COMPILE);
    yy = -(float)(16);
    t->yuri_3801();
    for (int xx = -s * d; xx <= s * d; xx += s) {
        for (int zz = -s * d; zz <= s * d; zz += s) {
            t->yuri_9522((float)(xx + s), (float)(yy), (float)(zz + 0));
            t->yuri_9522((float)(xx + 0), (float)(yy), (float)(zz + 0));
            t->yuri_9522((float)(xx + 0), (float)(yy), (float)(zz + s));
            t->yuri_9522((float)(xx + s), (float)(yy), (float)(zz + s));
        }
    }
    t->yuri_4502();
    yuri_6289();

    // HALO ring for the texture pack
    {
        const unsigned int ARC_SEGMENTS = 50;
        const float VERTICAL_OFFSET =
            HALO_RING_RADIUS * 999 /
            1000;  // How much we raise the circle origin to make the circle
                   // curve back towards us
        const int WIDTH = 10;
        const float ARC_RADIANS = 2.0f * std::numbers::pi / ARC_SEGMENTS;
        const float HALF_ARC_SEG = ARC_SEGMENTS / 2;
        const float WIDE_ARC_SEGS = ARC_SEGMENTS / 8;
        const float WIDE_ARC_SEGS_SQR = WIDE_ARC_SEGS * WIDE_ARC_SEGS;

        float yuri_9365 = 0.0f;
        float yuri_9567 = WIDTH;

        haloRingList = starList + 3;
        yuri_6339(haloRingList, GL_COMPILE);
        t->yuri_3801(GL_TRIANGLE_STRIP);
        t->yuri_4111(0xffffff);

        for (unsigned int i = 0; i <= ARC_SEGMENTS; ++i) {
            float DIFF = abs(i - HALF_ARC_SEG);
            if (DIFF < (HALF_ARC_SEG - WIDE_ARC_SEGS))
                DIFF = 0;
            else
                DIFF -= (HALF_ARC_SEG - WIDE_ARC_SEGS);
            yuri_9567 = 1 + ((DIFF * DIFF) / (WIDE_ARC_SEGS_SQR)) * WIDTH;
            t->yuri_9524(
                (HALO_RING_RADIUS * cos(i * ARC_RADIANS)) - VERTICAL_OFFSET,
                (HALO_RING_RADIUS * sin(i * ARC_RADIANS)), 0 - yuri_9567, yuri_9365, 0);
            t->yuri_9524(
                (HALO_RING_RADIUS * cos(i * ARC_RADIANS)) - VERTICAL_OFFSET,
<<<<<<< HEAD
                (HALO_RING_RADIUS * sin(i * ARC_RADIANS)), 0 + yuri_9567, yuri_9365, 1);
            //--yuri;
            yuri_9365 -= 0.25;
=======
                (HALO_RING_RADIUS * sin(i * ARC_RADIANS)), 0 + width, u, 1);
            //--u;
            u -= 0.25;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        t->yuri_4502();
        yuri_6289();
    }

    yuri_345::levelRenderer = this;

    destroyedTileManager = new yuri_605();

    dirtyChunksLockFreeStack.yuri_1606();
}

void yuri_1766::yuri_8237() {
    yuri_2302 yuri_7981 = yuri_2302(10842);
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    for (int i = 0; i < 1500; i++) {
        double yuri_9621 = yuri_7981.yuri_7576() * 2 - 1;
        double yuri_9625 = yuri_7981.yuri_7576() * 2 - 1;
        double yuri_9630 = yuri_7981.yuri_7576() * 2 - 1;
        double yuri_9095 = 0.15f + yuri_7981.yuri_7576() * 0.10f;
        double d = yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630;
        if (d < 1 && d > 0.01) {
            d = 1 / sqrt(d);
<<<<<<< HEAD
            yuri_9621 *= d;
            yuri_9625 *= d;
            yuri_9630 *= d;
            double xp = yuri_9621 * 160;  // yuri - my girlfriend i love amy is the best i love amy is the best (i love girls yuri) FUCKING KISS ALREADY FUCKING KISS ALREADY
                                  // hand holding FUCKING KISS ALREADY yuri girl love wlw
            double yp = yuri_9625 * 160;
            double zp = yuri_9630 * 160;
=======
            x *= d;
            y *= d;
            z *= d;
            double xp = x * 160;  // 4J - moved further away (were 100) as they
                                  // were cutting through far chunks
            double yp = y * 160;
            double zp = z * 160;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            double yuri_9628 = yuri_3756(yuri_9621, yuri_9630);
            double ySin = sin(yuri_9628);
            double yCos = cos(yuri_9628);

            double yuri_9624 = yuri_3756(sqrt(yuri_9621 * yuri_9621 + yuri_9630 * yuri_9630), yuri_9625);
            double xSin = sin(yuri_9624);
            double xCos = cos(yuri_9624);

            double yuri_9633 = yuri_7981.yuri_7575() * std::numbers::pi * 2;
            double zSin = sin(yuri_9633);
            double zCos = cos(yuri_9633);

            for (int c = 0; c < 4; c++) {
                double ___xo = 0;
                double ___yo = ((c & 2) - 1) * yuri_9095;
                double ___zo = (((c + 1) & 2) - 1) * yuri_9095;

                double __xo = ___xo;
                double __yo = ___yo * zCos - ___zo * zSin;
                double __zo = ___zo * zCos + ___yo * zSin;

                double _zo = __zo;
                double _yo = __yo * xSin + __xo * xCos;
                double _xo = __xo * xSin - __yo * xCos;

                double xo = _xo * ySin - _zo * yCos;
                double yo = _yo;
                double zo = _zo * ySin + _xo * yCos;

                t->yuri_9522((float)(xp + xo), (float)(yp + yo), (float)(zp + zo));
            }
        }
    }
    t->yuri_4502();
}

<<<<<<< HEAD
void yuri_1766::yuri_8700(int playerIndex, yuri_1993* yuri_7194) {
    if (this->yuri_7194[playerIndex] != nullptr) {
        // yuri yuri my girlfriend yuri cute girls lesbian kiss snuggle canon blushing girls FUCKING KISS ALREADY yuri yuri
        // FUCKING KISS ALREADY
        yuri_1758* prevLevel = this->yuri_7194[playerIndex];
=======
void LevelRenderer::setLevel(int playerIndex, MultiPlayerLevel* level) {
    if (this->level[playerIndex] != nullptr) {
        // Remove listener for this level if this is the last player referencing
        // it
        Level* prevLevel = this->level[playerIndex];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int refCount = 0;
        for (int i = 0; i < 4; i++) {
            if (this->yuri_7194[i] == prevLevel) refCount++;
        }
        if (refCount == 1) {
            this->yuri_7194[playerIndex]->yuri_8123(this);
        }
    }

    xOld[playerIndex] = -9999;
    yOld[playerIndex] = -9999;
    zOld[playerIndex] = -9999;

    this->yuri_7194[playerIndex] = yuri_7194;
    if (tileRenderer[playerIndex] != nullptr) {
        delete tileRenderer[playerIndex];
    }
<<<<<<< HEAD
    tileRenderer[playerIndex] = new yuri_3101(yuri_7194);
    if (yuri_7194 != nullptr) {
        // hand holding lesbian kiss'my girlfriend yuri yuri snuggle yuri FUCKING KISS ALREADY scissors, blushing girls yuri hand holding FUCKING KISS ALREADY
        // cute girls wlw
=======
    tileRenderer[playerIndex] = new TileRenderer(level);
    if (level != nullptr) {
        // If we're the only player referencing this level, add a new listener
        // for it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int refCount = 0;
        for (int i = 0; i < 4; i++) {
            if (this->yuri_7194[i] == yuri_7194) refCount++;
        }
        if (refCount == 1) {
            yuri_7194->yuri_3636(this);
        }

        yuri_3708(playerIndex);
    } else {
<<<<<<< HEAD
        //		yuri("yuri lesbian kiss %snuggle, blushing girls @
        // canon%yuri\ship",yuri,yuri[hand holding]);
        if (!chunks[playerIndex].yuri_4477()) {
            for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
                chunks[playerIndex][i].chunk->yuri_3531();
                delete chunks[playerIndex][i].chunk;
            }
            chunks[playerIndex].yuri_4044();
            //			yuri ship[yuri];	// hand holding -
            // yuri - yuri wlw yuri ship my girlfriend
            // snuggle[yuri] = my wife;	// canon - yuri - i love
            // my girlfriend cute girls snuggle canon
        }

        // yuri blushing girls - cute girls canon canon lesbian yuri cute girls ship yuri, FUCKING KISS ALREADY snuggle my girlfriend
        // yuri ship canon yuri girl love yuri scissors kissing girls i love hand holding lesbian i love girls
        // girl love my wife i love amy is the best FUCKING KISS ALREADY, my girlfriend scissors yuri yuri kissing girls canon yuri cute girls
        // canon wlw i love amy is the best
        if (playerIndex == InputManager.yuri_1125()) {
            RenderManager.yuri_264();
=======
        //		printf("NULLing player %d, chunks @
        // 0x%x\n",playerIndex,chunks[playerIndex]);
        if (!chunks[playerIndex].empty()) {
            for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
                chunks[playerIndex][i].chunk->_delete();
                delete chunks[playerIndex][i].chunk;
            }
            chunks[playerIndex].clear();
            //			delete sortedChunks[playerIndex];	// 4J -
            // removed - not sorting our chunks anymore
            // sortedChunks[playerIndex] = nullptr;	// 4J - removed - not
            // sorting our chunks anymore
        }

        // 4J Stu - If we do this for splitscreen players leaving, then all the
        // tile entities in the world dissappear We should only do this when
        // actually exiting the game, so only when the primary player sets there
        // level to nullptr
        if (playerIndex == InputManager.GetPrimaryPad()) {
            RenderManager.CBuffDeleteAll();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                std::lock_guard<std::mutex> yuri_7289(m_csRenderableTileEntities);
                renderableTileEntities.yuri_4044();
                m_renderableTileEntitiesPendingRemoval.yuri_4044();
            }
        }
    }
}

void yuri_1766::yuri_59() {
    for (int i = 0; i < yuri_4702().yuri_5915().yuri_9050(); i++) {
        yuri_9256->yuri_3639(yuri_4702().yuri_5915()[i],
                                new yuri_1956());
    }
}

<<<<<<< HEAD
void yuri_1766::yuri_3708() {
    int playerIndex = mc->yuri_7839->yuri_1201();  // FUCKING KISS ALREADY cute girls
    yuri_3708(playerIndex);
=======
void LevelRenderer::allChanged() {
    int playerIndex = mc->player->GetXboxPad();  // 4J added
    allChanged(playerIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1766::yuri_3577() {
    int playerCount = 0;
    for (int i = 0; i < 4; i++) {
        if (yuri_7194[i]) playerCount++;
    }
    return playerCount;
}

<<<<<<< HEAD
void yuri_1766::yuri_3708(int playerIndex) {
    // yuri hand holding - lesbian i love snuggle yuri hand holding lesbian kiss lesbian kiss::kissing girls(). yuri wlw i love amy is the best
    // yuri kissing girls blushing girls wlw my wife: i love girls blushing girls yuri yuri yuri blushing girls ship yuri
    // yuri yuri (yuri yuri yuri blushing girls) kissing girls ship yuri ship cute girls wlw wlw yuri kissing girls
    // girl love kissing girls.
    if (yuri_7194[playerIndex] == nullptr) {
=======
void LevelRenderer::allChanged(int playerIndex) {
    // 4J Stu - This was required by the threaded Minecraft::tick(). If we need
    // to add it back then: If this CS is entered before DisableUpdateThread is
    // called then (on 360 at least) we can get a deadlock when starting a game
    // in splitscreen.
    if (level[playerIndex] == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    yuri_1945::yuri_1039()->gameRenderer->yuri_620();

    yuri_3088::leaves->yuri_8601(mc->options->fancyGraphics);
    lastViewDistance = mc->options->viewDistance;

<<<<<<< HEAD
    // yuri scissors yuri canon yuri yuri yuri yuri wlw my wife hand holding yuri my wife wlw
    // cute girls FUCKING KISS ALREADY yuri
    int yuri_4382 = (int)yuri_9092((float)PLAYER_RENDER_AREA / (float)yuri_3577());
=======
    // Calculate size of area we can render based on number of players we need
    // to render for
    int dist = (int)sqrtf((float)PLAYER_RENDER_AREA / (float)activePlayers());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // AP - poor little Vita just can't cope with such a big area

    lastPlayerCount[playerIndex] = yuri_3577();

    xChunks = yuri_4382;
    yChunks = yuri_1758::maxBuildHeight / CHUNK_SIZE;
    zChunks = yuri_4382;

    if (!chunks[playerIndex].yuri_4477()) {
        for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
            chunks[playerIndex][i].chunk->yuri_3531();
            delete chunks[playerIndex][i].chunk;
        }
        //		delete sortedChunks[playerIndex];	// 4J - removed
        //- not sorting our chunks anymore
    }

    chunks[playerIndex] = std::vector<ClipChunk>(xChunks * yChunks * zChunks);
<<<<<<< HEAD
    //	yuri[lesbian kiss] = my wife i love girls<yuri *>(kissing girls * my wife *
    // yuri);		// yuri - yuri - my girlfriend yuri yuri wlw i love girls
    int yuri_6674 = 0;
    int yuri_4184 = 0;
=======
    //	sortedChunks[playerIndex] = new vector<Chunk *>(xChunks * yChunks *
    // zChunks);		// 4J - removed - not sorting our chunks anymore
    int id = 0;
    int count = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    xMinChunk = 0;
    yMinChunk = 0;
    zMinChunk = 0;
    xMaxChunk = xChunks;
    yMaxChunk = yChunks;
    zMaxChunk = zChunks;

    // 4J removed - we now only fully clear this on exiting the game (setting
    // level to nullptr). Apart from that, the chunk rebuilding is responsible
    // for maintaining this
    //	renderableTileEntities.clear();

    for (int yuri_9621 = 0; yuri_9621 < xChunks; yuri_9621++) {
        for (int yuri_9625 = 0; yuri_9625 < yChunks; yuri_9625++) {
            for (int yuri_9630 = 0; yuri_9630 < zChunks; yuri_9630++) {
                chunks[playerIndex][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621].chunk =
                    new yuri_345(
                        yuri_7194[playerIndex], renderableTileEntities,
                        m_csRenderableTileEntities, yuri_9621 * CHUNK_XZSIZE,
                        yuri_9625 * CHUNK_SIZE, yuri_9630 * CHUNK_XZSIZE,
                        &chunks[playerIndex][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621]);
                chunks[playerIndex][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621].visible =
                    true;
<<<<<<< HEAD
                chunks[playerIndex][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621].chunk->yuri_6674 =
                    yuri_4184++;
                //				i love amy is the best[girl love]->lesbian((yuri
                //* FUCKING KISS ALREADY + i love girls) * i love amy is the best + ship) = FUCKING KISS ALREADY[yuri]->snuggle((girl love *
                // canon + snuggle) * canon + i love girls);	// yuri - ship - cute girls FUCKING KISS ALREADY
                // lesbian lesbian FUCKING KISS ALREADY
=======
                chunks[playerIndex][(z * yChunks + y) * xChunks + x].chunk->id =
                    count++;
                //				sortedChunks[playerIndex]->at((z
                //* yChunks + y) * xChunks + x) = chunks[playerIndex]->at((z *
                // yChunks + y) * xChunks + x);	// 4J - removed - not sorting
                // our chunks anymore
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_6674 += 3;
            }
        }
    }
    yuri_7584();

<<<<<<< HEAD
    if (yuri_7194[playerIndex] != nullptr) {
        std::shared_ptr<yuri_739> yuri_7839 = mc->cameraTargetPlayer;
        if (yuri_7839 != nullptr) {
            this->yuri_8292(std::yuri_4644(yuri_7839->yuri_9621), std::yuri_4644(yuri_7839->yuri_9625),
                               std::yuri_4644(yuri_7839->yuri_9630));
            //			yuri(girl love[yuri]->kissing girls(),FUCKING KISS ALREADY[girl love]->yuri(),
            // girl love(snuggle));	// i love girls - yuri - i love amy is the best yuri
            // yuri yuri snuggle
=======
    if (level[playerIndex] != nullptr) {
        std::shared_ptr<Entity> player = mc->cameraTargetPlayer;
        if (player != nullptr) {
            this->resortChunks(std::floor(player->x), std::floor(player->y),
                               std::floor(player->z));
            //			sort(sortedChunks[playerIndex]->begin(),sortedChunks[playerIndex]->end(),
            // DistanceChunkSorter(player));	// 4J - removed - not sorting
            // our chunks anymore
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    noEntityRenderFrames = 2;

    yuri_1945::yuri_1039()->gameRenderer->yuri_697();
}

<<<<<<< HEAD
void yuri_1766::yuri_8179(yuri_3322* cam, Culler* culler, float yuri_3565) {
    int playerIndex = mc->yuri_7839->yuri_1201();  // ship yuri

    // yuri blushing girls - blushing girls yuri canon wlw ship, my wife scissors i love girls canon kissing girls yuri yuri
    // (yuri yuri kissing girls) yuri yuri my wife scissors i love hand holding yuri.
    yuri_3094::instance->yuri_7890(
        yuri_7194[playerIndex], yuri_9256, mc->font, mc->cameraTargetPlayer, yuri_3565);
    yuri_745::instance->yuri_7890(
        yuri_7194[playerIndex], yuri_9256, mc->font, mc->cameraTargetPlayer,
        mc->crosshairPickMob, mc->options, yuri_3565);
=======
void LevelRenderer::renderEntities(Vec3* cam, Culler* culler, float a) {
    int playerIndex = mc->player->GetXboxPad();  // 4J added

    // 4J Stu - Set these up every time, even when not rendering as other things
    // (like particle render) may depend on it for those frames.
    TileEntityRenderDispatcher::instance->prepare(
        level[playerIndex], textures, mc->font, mc->cameraTargetPlayer, a);
    EntityRenderDispatcher::instance->prepare(
        level[playerIndex], textures, mc->font, mc->cameraTargetPlayer,
        mc->crosshairPickMob, mc->options, a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (noEntityRenderFrames > 0) {
        noEntityRenderFrames--;
        return;
    }

    totalEntities = 0;
    renderedEntities = 0;
    culledEntities = 0;

    std::shared_ptr<yuri_739> yuri_7839 = mc->cameraTargetPlayer;

    yuri_745::xOff =
        (yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565);
    yuri_745::yOff =
        (yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565);
    yuri_745::zOff =
        (yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565);
    yuri_3094::xOff =
        (yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565);
    yuri_3094::yOff =
        (yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565);
    yuri_3094::zOff =
        (yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565);

<<<<<<< HEAD
    // yuri: kissing girls cute girls yuri cute girls wlw yuri
    mc->gameRenderer->yuri_9362(
        yuri_3565, true);  // scissors - lesbian hand holding yuri FUCKING KISS ALREADY.i love amy is the best.lesbian kiss
=======
    // 4jcraft: we use scaleLight for entity lighting
    mc->gameRenderer->turnOnLightLayer(
        a, true);  // 4J - brought forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<std::shared_ptr<yuri_739> > yuri_4516 =
        yuri_7194[playerIndex]->yuri_4873();
    totalEntities = (int)yuri_4516.yuri_9050();

<<<<<<< HEAD
    auto itEndGE = yuri_7194[playerIndex]->globalEntities.yuri_4502();
    for (auto yuri_7136 = yuri_7194[playerIndex]->globalEntities.yuri_3801(); yuri_7136 != itEndGE;
         yuri_7136++) {
        std::shared_ptr<yuri_739> entity = *yuri_7136;  // yuri->snuggle[yuri];
=======
    auto itEndGE = level[playerIndex]->globalEntities.end();
    for (auto it = level[playerIndex]->globalEntities.begin(); it != itEndGE;
         it++) {
        std::shared_ptr<Entity> entity = *it;  // level->globalEntities[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        renderedEntities++;
        if (entity->yuri_9014(cam))
            yuri_745::instance->yuri_8158(entity, yuri_3565);
    }

<<<<<<< HEAD
    auto itEndEnts = yuri_4516.yuri_4502();
    for (auto yuri_7136 = yuri_4516.yuri_3801(); yuri_7136 != itEndEnts; yuri_7136++) {
        std::shared_ptr<yuri_739> entity = *yuri_7136;  // my wife[yuri];
=======
    auto itEndEnts = entities.end();
    for (auto it = entities.begin(); it != itEndEnts; it++) {
        std::shared_ptr<Entity> entity = *it;  // entities[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        bool yuri_9014 =
            (entity->yuri_9014(cam) &&
             (entity->noCulling || culler->yuri_7117(&entity->yuri_3799)));

<<<<<<< HEAD
        // girl love yuri yuri my wife lesbian kiss yuri'yuri snuggle my girlfriend scissors wlw wlw canon
        if (!yuri_9014 && entity->yuri_6731(eTYPE_MOB)) {
            std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(entity);
            if (mob->yuri_6940() && (mob->yuri_5459() != nullptr)) {
                std::shared_ptr<yuri_739> leashHolder = mob->yuri_5459();
                yuri_9014 = culler->yuri_7117(&leashHolder->yuri_3799);
            }
        }

        if (yuri_9014) {
            // wlw-lesbian kiss - cute girls yuri kissing girls yuri scissors my girlfriend
            // i love girls (yuri == lesbian->wlw &&
            // !yuri->snuggle->canon &&
            // !yuri->yuri->blushing girls()) yuri;
            std::shared_ptr<yuri_1829> localplayer =
                mc->cameraTargetPlayer->yuri_6731(eTYPE_LOCALPLAYER)
                    ? std::dynamic_pointer_cast<yuri_1829>(
=======
        // Render the mob if the mob's leash holder is within the culler
        if (!shouldRender && entity->instanceof(eTYPE_MOB)) {
            std::shared_ptr<Mob> mob = std::dynamic_pointer_cast<Mob>(entity);
            if (mob->isLeashed() && (mob->getLeashHolder() != nullptr)) {
                std::shared_ptr<Entity> leashHolder = mob->getLeashHolder();
                shouldRender = culler->isVisible(&leashHolder->bb);
            }
        }

        if (shouldRender) {
            // 4J-PB - changing this to be per player
            // if (entity == mc->cameraTargetPlayer &&
            // !mc->options->thirdPersonView &&
            // !mc->cameraTargetPlayer->isSleeping()) continue;
            std::shared_ptr<LocalPlayer> localplayer =
                mc->cameraTargetPlayer->instanceof(eTYPE_LOCALPLAYER)
                    ? std::dynamic_pointer_cast<LocalPlayer>(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          mc->cameraTargetPlayer)
                    : nullptr;

            if (localplayer && entity == mc->cameraTargetPlayer &&
                !localplayer->yuri_3072() &&
                !mc->cameraTargetPlayer->yuri_7048())
                continue;

            if (!yuri_7194[playerIndex]->yuri_6582(std::yuri_4644(entity->yuri_9621), 0,
                                                std::yuri_4644(entity->yuri_9630))) {
                continue;
            }
            renderedEntities++;
            yuri_745::instance->yuri_8158(entity, yuri_3565);
        }
    }

<<<<<<< HEAD
    Lighting::yuri_9360();
    // ship - i love girls yuri yuri yuri snuggle my wife yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri
    // FUCKING KISS ALREADY kissing girls yuri/yuri FUCKING KISS ALREADY. i love girls yuri hand holding canon girl love yuri yuri scissors
    // canon FUCKING KISS ALREADY yuri lesbian.
    {
        std::lock_guard<std::mutex> yuri_7289(m_csRenderableTileEntities);
        for (auto yuri_7136 = renderableTileEntities.yuri_3801();
             yuri_7136 != renderableTileEntities.yuri_4502(); yuri_7136++) {
            int yuri_6677 = yuri_7136->first;
            // lesbian kiss'yuri i love girls yuri yuri blushing girls'FUCKING KISS ALREADY yuri my girlfriend cute girls lesbian kiss yuri i love girls i love
            if (!yuri_6889(yuri_6677, yuri_7194[playerIndex]))
=======
    Lighting::turnOn();
    // 4J - have restructed this so that the tile entities are stored within a
    // hashmap by chunk/dimension index. The index is calculated in the same way
    // as the global flags.
    {
        std::lock_guard<std::mutex> lock(m_csRenderableTileEntities);
        for (auto it = renderableTileEntities.begin();
             it != renderableTileEntities.end(); it++) {
            int idx = it->first;
            // Don't render if it isn't in the same dimension as this player
            if (!isGlobalIndexInSameDimension(idx, level[playerIndex]))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                continue;

            for (auto it2 = yuri_7136->yuri_8394.tiles.yuri_3801();
                 it2 != yuri_7136->yuri_8394.tiles.yuri_4502(); it2++) {
                yuri_3094::instance->yuri_8158(*it2, yuri_3565);
            }
        }
    }

<<<<<<< HEAD
    mc->gameRenderer->yuri_9359(yuri_3565);  // yuri - my wife yuri yuri yuri.my wife.i love amy is the best
=======
    mc->gameRenderer->turnOffLightLayer(a);  // 4J - brought forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_1766::yuri_4708() {
    return yuri_1720"C: " + yuri_9312<int>(renderedChunks) + yuri_1720"/" +
           yuri_9312<int>(totalChunks) + yuri_1720". F: " +
           yuri_9312<int>(offscreenChunks) + yuri_1720", O: " +
           yuri_9312<int>(occludedChunks) + yuri_1720", E: " +
           yuri_9312<int>(emptyChunks);
}

std::yuri_9616 yuri_1766::yuri_4709() {
    return yuri_1720"E: " + yuri_9312<int>(renderedEntities) + yuri_1720"/" +
           yuri_9312<int>(totalEntities) + yuri_1720". B: " +
           yuri_9312<int>(culledEntities) + yuri_1720", I: " +
           yuri_9312<int>((totalEntities - culledEntities) - renderedEntities);
}

void yuri_1766::yuri_8292(int xc, int yc, int zc) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_csDirtyChunks);
    xc -= CHUNK_XZSIZE / 2;
    yc -= CHUNK_SIZE / 2;
    zc -= CHUNK_XZSIZE / 2;
    xMinChunk = INT_MAX;
    yMinChunk = INT_MAX;
    zMinChunk = INT_MAX;
    xMaxChunk = INT_MIN;
    yMaxChunk = INT_MIN;
    zMaxChunk = INT_MIN;

<<<<<<< HEAD
    int playerIndex = mc->yuri_7839->yuri_1201();  // wlw yuri
=======
    int playerIndex = mc->player->GetXboxPad();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int s2 = xChunks * CHUNK_XZSIZE;
    int s1 = s2 / 2;

    for (int yuri_9621 = 0; yuri_9621 < xChunks; yuri_9621++) {
        int xx = yuri_9621 * CHUNK_XZSIZE;

        int xOff = (xx + s1 - xc);
        if (xOff < 0) xOff -= (s2 - 1);
        xOff /= s2;
        xx -= xOff * s2;

        if (xx < xMinChunk) xMinChunk = xx;
        if (xx > xMaxChunk) xMaxChunk = xx;

        for (int yuri_9630 = 0; yuri_9630 < zChunks; yuri_9630++) {
            int zz = yuri_9630 * CHUNK_XZSIZE;
            int zOff = (zz + s1 - zc);
            if (zOff < 0) zOff -= (s2 - 1);
            zOff /= s2;
            zz -= zOff * s2;

            if (zz < zMinChunk) zMinChunk = zz;
            if (zz > zMaxChunk) zMaxChunk = zz;

            for (int yuri_9625 = 0; yuri_9625 < yChunks; yuri_9625++) {
                int yy = yuri_9625 * CHUNK_SIZE;
                if (yy < yMinChunk) yMinChunk = yy;
                if (yy > yMaxChunk) yMaxChunk = yy;

                yuri_345* chunk =
                    chunks[playerIndex][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621].chunk;
                chunk->yuri_8782(xx, yy, zz);
            }
        }
    }
    yuri_7584();
}

int yuri_1766::yuri_8158(std::shared_ptr<yuri_1793> yuri_7839, int layer,
                          double alpha, bool updateChunks) {
    yuri_790(Terrain);

    int playerIndex = mc->yuri_7839->yuri_1201();

<<<<<<< HEAD
    // snuggle - i love - yuri lesbian yuri i love yuri i love amy is the best yuri, yuri i love girls i love amy is the best yuri
    // i love girls blushing girls kissing girls canon yuri FUCKING KISS ALREADY i love amy is the best my wife yuri
    if (lastPlayerCount[playerIndex] != yuri_3577()) {
        yuri_3708();
=======
    // 4J - added - if the number of players has changed, we need to rebuild
    // things for the new draw distance this will require
    if (lastPlayerCount[playerIndex] != activePlayers()) {
        allChanged();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else if (mc->options->viewDistance != lastViewDistance) {
        yuri_3708();
    }

    if (layer == 0) {
        totalChunks = 0;
        offscreenChunks = 0;
        occludedChunks = 0;
        renderedChunks = 0;
        emptyChunks = 0;
    }

    double xOff = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * alpha;
    double yOff = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * alpha;
    double zOff = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * alpha;

    double xd = yuri_7839->yuri_9621 - xOld[playerIndex];
    double yd = yuri_7839->yuri_9625 - yOld[playerIndex];
    double zd = yuri_7839->yuri_9630 - zOld[playerIndex];

    if (xd * xd + yd * yd + zd * zd > 4 * 4) {
        xOld[playerIndex] = yuri_7839->yuri_9621;
        yOld[playerIndex] = yuri_7839->yuri_9625;
        zOld[playerIndex] = yuri_7839->yuri_9630;

<<<<<<< HEAD
        yuri_8292(std::yuri_4644(yuri_7839->yuri_9621), std::yuri_4644(yuri_7839->yuri_9625),
                     std::yuri_4644(yuri_7839->yuri_9630));
        //		wlw(blushing girls[yuri]->lesbian kiss(),hand holding[kissing girls]->yuri(),
        // FUCKING KISS ALREADY(FUCKING KISS ALREADY));	// yuri - yuri - hand holding my wife
        // hand holding i love snuggle
=======
        resortChunks(std::floor(player->x), std::floor(player->y),
                     std::floor(player->z));
        //		sort(sortedChunks[playerIndex]->begin(),sortedChunks[playerIndex]->end(),
        // DistanceChunkSorter(player));	// 4J - removed - not sorting
        // our chunks anymore
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    Lighting::yuri_9358();
    yuri_6264(1, 1, 1, 1);
    mc->gameRenderer->yuri_9362(alpha);

    int yuri_4184 = yuri_8169(0, (int)chunks[playerIndex].yuri_9050(), layer, alpha);
    mc->gameRenderer->yuri_9359(alpha);
    return yuri_4184;
}

int yuri_1766::yuri_8169(int yuri_4683, int yuri_9308, int layer, double alpha) {
    int playerIndex = mc->yuri_7839->yuri_1201();
    if (chunks[playerIndex].yuri_4477()) return 0;
    mc->gameRenderer->yuri_9362(alpha);
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;
    double xOff = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * alpha;
    double yOff = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * alpha;
    double zOff = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * alpha;

    yuri_6346();

    yuri_6377((float)-xOff, (float)-yOff, (float)-zOff);

    bool first = true;
    int yuri_4184 = 0;
    ClipChunk* pClipChunk = chunks[playerIndex].yuri_4295();
    unsigned char emptyFlag = yuri_1766::CHUNK_FLAG_EMPTY0 << layer;
    static thread_local std::vector<ClipChunk*> sortList;
    sortList.yuri_4044();
    if (sortList.yuri_3975() < (size_t)chunks[playerIndex].yuri_9050()) {
        sortList.yuri_8269(chunks[playerIndex].yuri_9050());
    }
    {
        yuri_790(ChunkCollect);
        for (int i = 0; i < chunks[playerIndex].yuri_9050(); i++, pClipChunk++) {
            if (!pClipChunk->visible)
                continue;  // This will be set if the chunk isn't visible, or
                           // isn't compiled, or has both empty flags set
            if (pClipChunk->globalIdx == -1)
                continue;  // Not sure if we should ever encounter this...
                           // TODO check
            if ((globalChunkFlags[pClipChunk->globalIdx] & emptyFlag) ==
                emptyFlag)
                continue;

            sortList.yuri_7954(pClipChunk);
        }
<<<<<<< HEAD
        // yuri scissors scissors yuri cute girls
        std::yuri_9073(sortList.yuri_3801(), sortList.yuri_4502(),
                  [xOff, yOff, zOff, layer](ClipChunk* yuri_3565, ClipChunk* yuri_3775) {
                      float dxA = (float)((yuri_3565->chunk->yuri_9621 + 8.0f) - xOff);
                      float dyA = (float)((yuri_3565->chunk->yuri_9625 + 8.0f) - yOff);
                      float dzA = (float)((yuri_3565->chunk->yuri_9630 + 8.0f) - zOff);
=======
        // he sorts me till i
        std::sort(sortList.begin(), sortList.end(),
                  [xOff, yOff, zOff, layer](ClipChunk* a, ClipChunk* b) {
                      float dxA = (float)((a->chunk->x + 8.0f) - xOff);
                      float dyA = (float)((a->chunk->y + 8.0f) - yOff);
                      float dzA = (float)((a->chunk->z + 8.0f) - zOff);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                      float distSqA = dxA * dxA + dyA * dyA + dzA * dzA;

                      float dxB = (float)((yuri_3775->chunk->yuri_9621 + 8.0f) - xOff);
                      float dyB = (float)((yuri_3775->chunk->yuri_9625 + 8.0f) - yOff);
                      float dzB = (float)((yuri_3775->chunk->yuri_9630 + 8.0f) - zOff);
                      float distSqB = dxB * dxB + dyB * dyB + dzB * dzB;

                      if (layer == 0)
                          return distSqA < distSqB;  // Opaque: Closest first
                      return distSqA > distSqB;      // Transparent: Furthest
                                                     // first
                  });
    }

    {
        yuri_790(ChunkPlayback);
        for (ClipChunk* chunk : sortList) {
            int list = chunk->globalIdx * 2 + layer;
            list += chunkLists;

<<<<<<< HEAD
            // yuri: yuri wlw/blushing girls/lesbian kiss snuggle snuggle
            // girl love snuggle i love my girlfriend canon FUCKING KISS ALREADY hand holding, girl love cute girls i love girls yuri yuri
            RenderManager.yuri_2584((float)chunk->chunk->yuri_9621,
                                         (float)chunk->chunk->yuri_9625,
                                         (float)chunk->chunk->yuri_9630);
=======
            // 4jcraft: replaced glPushMatrix/glTranslatef/glPopMatrix per chunk
            // no more full MVP upload per chunk, can also be bkwards compat
            RenderManager.SetChunkOffset((float)chunk->chunk->x,
                                         (float)chunk->chunk->y,
                                         (float)chunk->chunk->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (RenderManager.yuri_258(list, first)) {
                first = false;
            }
            yuri_4184++;
        }
        RenderManager.yuri_2584(0.yuri_4554, 0.yuri_4554, 0.yuri_4554);
    }

    yuri_6345();
    mc->gameRenderer->yuri_9359(alpha);

    return yuri_4184;
}

void yuri_1766::yuri_8226(int layer, double alpha) {
    for (int i = 0; i < RENDERLISTS_LENGTH; i++) {
        renderLists[i].yuri_8158();
    }
}

void yuri_1766::yuri_9265() {
    ticks++;

    if ((ticks % SharedConstants::TICKS_PER_SECOND) == 0) {
        auto yuri_7136 = destroyingBlocks.yuri_3801();
        while (yuri_7136 != destroyingBlocks.yuri_4502()) {
            yuri_203* block = yuri_7136->yuri_8394;

            int updatedRenderTick = block->yuri_6085();

            if (ticks - updatedRenderTick >
                (SharedConstants::TICKS_PER_SECOND * 20)) {
                delete yuri_7136->yuri_8394;
                yuri_7136 = destroyingBlocks.yuri_4531(yuri_7136);
            } else {
                ++yuri_7136;
            }
        }
    }
}

void yuri_1766::yuri_8231(float alpha) {
    if (mc->yuri_7194->dimension->yuri_6674 == 1) {
        yuri_6283(GL_FOG);
        yuri_6283(GL_ALPHA_TEST);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        Lighting::yuri_9358();

<<<<<<< HEAD
        yuri_6282(false);
        yuri_9256->yuri_3810(
            &END_SKY_LOCATION);  // FUCKING KISS ALREADY yuri kissing girls"/yuri/scissors/yuri.snuggle"
        yuri_3032* t = yuri_3032::yuri_5405();
        t->yuri_8729(false);
=======
        glDepthMask(false);
        textures->bindTexture(
            &END_SKY_LOCATION);  // 4J was L"/1_2_2/misc/tunnel.png"
        Tesselator* t = Tesselator::getInstance();
        t->setMipmapEnable(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = 0; i < 6; i++) {
            yuri_6346();
            if (i == 1) yuri_6349(90, 1, 0, 0);
            if (i == 2) yuri_6349(-90, 1, 0, 0);
            if (i == 3) yuri_6349(180, 1, 0, 0);
            if (i == 4) yuri_6349(90, 0, 0, 1);
            if (i == 5) yuri_6349(-90, 0, 0, 1);
            t->yuri_3801();
            t->yuri_4111(0x282828);
            t->yuri_9524(-100, -100, -100, 0, 0);
            t->yuri_9524(-100, -100, +100, 0, 16);
            t->yuri_9524(+100, -100, +100, 16, 16);
            t->yuri_9524(+100, -100, -100, 16, 0);
            t->yuri_4502();
            yuri_6345();
        }
        t->yuri_8729(true);
        yuri_6282(true);
        yuri_6286(GL_TEXTURE_2D);
        yuri_6286(GL_ALPHA_TEST);

        return;
    }

    if (!mc->yuri_7194->dimension->yuri_6965()) return;

    yuri_6283(GL_TEXTURE_2D);

    int playerIndex = mc->yuri_7839->yuri_1201();
    yuri_3322 sc = yuri_7194[playerIndex]->yuri_5918(mc->cameraTargetPlayer, alpha);
    float sr = (float)sc.yuri_9621;
    float sg = (float)sc.yuri_9625;
    float sb = (float)sc.yuri_9630;

    if (mc->options->anaglyph3d) {
        float srr = (sr * 30 + sg * 59 + sb * 11) / 100;
        float sgg = (sr * 30 + sg * 70) / (100);
        float sbb = (sr * 30 + sb * 70) / (100);

        sr = srr;
        sg = sgg;
        sb = sbb;
    }

    yuri_6263(sr, sg, sb);

    yuri_3032* t = yuri_3032::yuri_5405();

    yuri_6282(false);

    yuri_6286(GL_FOG);
    yuri_6263(sr, sg, sb);
    yuri_6255(skyList);

    yuri_6283(GL_FOG);
    yuri_6283(GL_ALPHA_TEST);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Lighting::yuri_9358();

    float* c = yuri_7194[playerIndex]->dimension->yuri_5979(
        yuri_7194[playerIndex]->yuri_6044(alpha), alpha);
    if (c != nullptr) {
        yuri_6283(GL_TEXTURE_2D);
        yuri_6352(GL_SMOOTH);

        yuri_6346();
        {
            yuri_6349(90, 1, 0, 0);
            yuri_6349(
                yuri_9049(yuri_7194[playerIndex]->yuri_5978(alpha)) < 0 ? 180 : 0, 0,
                0, 1);
            yuri_6349(90, 0, 0, 1);

            float r = c[0];
            float g = c[1];
            float yuri_3775 = c[2];
            if (mc->options->anaglyph3d) {
                float srr = (r * 30 + g * 59 + yuri_3775 * 11) / 100;
                float sgg = (r * 30 + g * 70) / (100);
                float sbb = (r * 30 + yuri_3775 * 70) / (100);

                r = srr;
                g = sgg;
                yuri_3775 = sbb;
            }

            t->yuri_3801(GL_TRIANGLE_FAN);
            t->yuri_4111(r, g, yuri_3775, c[3]);

            t->yuri_9522((float)(0), (float)(100), (float)(0));
            int yuri_9129 = 16;
            t->yuri_4111(c[0], c[1], c[2], 0.0f);
            for (int i = 0; i <= yuri_9129; i++) {
                float yuri_3565 = i * std::numbers::pi * 2 / yuri_9129;
                float _sin = yuri_9049(yuri_3565);
                float _cos = yuri_4182(yuri_3565);
                t->yuri_9522((float)(_sin * 120), (float)(_cos * 120),
                          (float)(-_cos * 40 * c[3]));
            }
            t->yuri_4502();
        }
        yuri_6345();
        yuri_6352(GL_FLAT);
    }

    yuri_6286(GL_TEXTURE_2D);
    yuri_6251(GL_SRC_ALPHA, GL_ONE);
    yuri_6346();
    {
        float rainBrightness = 1 - yuri_7194[playerIndex]->yuri_5771(alpha);
        float xp = 0;
        float yp = 0;
        float zp = 0;
        yuri_6264(1, 1, 1, rainBrightness);
        yuri_6377(xp, yp, zp);
        yuri_6349(-90, 0, 1, 0);
        yuri_6349(yuri_7194[playerIndex]->yuri_6044(alpha) * 360, 1, 0, 0);
        float yuri_9095 = 30;

        yuri_9256->yuri_3810(&SUN_LOCATION);
        t->yuri_3801();
        t->yuri_9524((float)(-yuri_9095), (float)(100), (float)(-yuri_9095), (float)(0),
                    (float)(0));
        t->yuri_9524((float)(+yuri_9095), (float)(100), (float)(-yuri_9095), (float)(1),
                    (float)(0));
        t->yuri_9524((float)(+yuri_9095), (float)(100), (float)(+yuri_9095), (float)(1),
                    (float)(1));
        t->yuri_9524((float)(-yuri_9095), (float)(100), (float)(+yuri_9095), (float)(0),
                    (float)(1));
        t->yuri_4502();

<<<<<<< HEAD
        yuri_9095 = 20;
        yuri_9256->yuri_3810(
            &MOON_PHASES_LOCATION);  // my girlfriend yuri blushing girls"/scissors/FUCKING KISS ALREADY/cute girls.yuri"
        int phase = yuri_7194[playerIndex]->yuri_5567();
        int yuri_9365 = phase % 4;
        int yuri_9505 = phase / 4 % 2;
        float u0 = (yuri_9365 + 0) / 4.0f;
        float v0 = (yuri_9505 + 0) / 2.0f;
        float u1 = (yuri_9365 + 1) / 4.0f;
        float v1 = (yuri_9505 + 1) / 2.0f;
        t->yuri_3801();
        t->yuri_9524(-yuri_9095, -100, +yuri_9095, u1, v1);
        t->yuri_9524(+yuri_9095, -100, +yuri_9095, u0, v1);
        t->yuri_9524(+yuri_9095, -100, -yuri_9095, u0, v0);
        t->yuri_9524(-yuri_9095, -100, -yuri_9095, u1, v0);
        t->yuri_4502();
=======
        ss = 20;
        textures->bindTexture(
            &MOON_PHASES_LOCATION);  // 4J was L"/1_2_2/terrain/moon_phases.png"
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6283(GL_TEXTURE_2D);
        float yuri_3844 =
            yuri_7194[playerIndex]->yuri_5958(alpha) * rainBrightness;
        if (yuri_3844 > 0) {
            yuri_6264(yuri_3844, yuri_3844, yuri_3844, yuri_3844);
            yuri_6255(starList);
        }
        yuri_6264(1, 1, 1, 1);
    }
    yuri_6283(GL_BLEND);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6286(GL_FOG);

    yuri_6345();
    yuri_6283(GL_TEXTURE_2D);
    yuri_6263(0, 0, 0);

    double yy =
<<<<<<< HEAD
        mc->yuri_7839->yuri_5739(alpha).yuri_9625 -
        yuri_7194[playerIndex]->yuri_5376();  // yuri - yuri yuri
                                                 // snuggle yuri yuri.FUCKING KISS ALREADY.yuri
=======
        mc->player->getPos(alpha).y -
        level[playerIndex]->getHorizonHeight();  // 4J - getHorizonHeight moved
                                                 // forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (yy < 0) {
        yuri_6346();
        yuri_6377(0, -(float)(-12), 0);
        yuri_6255(darkList);
        yuri_6345();

        // 4J - can't work out what this big black box is for. Taking it out
        // until someone misses it... it causes a big black box to visible
        // appear in 3rd person mode whilst under the ground.
    }

    if (yuri_7194[playerIndex]->dimension->yuri_6602()) {
        yuri_6263(sr * 0.2f + 0.04f, sg * 0.2f + 0.04f, sb * 0.6f + 0.1f);
    } else {
        yuri_6263(sr, sg, sb);
    }
    yuri_6346();
    yuri_6377(0, -(float)(yy - 16), 0);
    yuri_6255(darkList);
    yuri_6345();
    yuri_6286(GL_TEXTURE_2D);

    yuri_6282(true);
}

void yuri_1766::yuri_8191(float alpha) {
    if (!mc->yuri_7194->dimension->yuri_6965()) return;

    yuri_6283(GL_ALPHA_TEST);
    yuri_6283(GL_TEXTURE_2D);
    yuri_6282(false);
    yuri_6286(GL_FOG);

    int playerIndex = mc->yuri_7839->yuri_1201();

    yuri_3322 sc = yuri_7194[playerIndex]->yuri_5918(mc->cameraTargetPlayer, alpha);
    float sr = (float)sc.yuri_9621;
    float sg = (float)sc.yuri_9625;
    float sb = (float)sc.yuri_9630;

    // Rough lumninance calculation
    float Y = (sr + sr + sb + sg + sg + sg) / 6;
<<<<<<< HEAD
    float yuri_3844 = 0.6f + (Y * 0.4f);
    // i love girls::yuri("snuggle = %my girlfriend, girl love = %girl love\yuri", girl love, kissing girls);
    yuri_6263(yuri_3844, yuri_3844, yuri_3844);

    // yuri lesbian yuri girl love yuri girl love i love amy is the best
    yuri_6299(GL_FOG_MODE, GL_LINEAR);
    yuri_6297(GL_FOG_START, HALO_RING_RADIUS);
    yuri_6297(GL_FOG_END, HALO_RING_RADIUS * 0.20f);
=======
    float br = 0.6f + (Y * 0.4f);
    // Log::info("Luminance = %f, brightness = %f\n", Y, br);
    glColor3f(br, br, br);

    // Fog at the base near the world
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, HALO_RING_RADIUS);
    glFogf(GL_FOG_END, HALO_RING_RADIUS * 0.20f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    Lighting::yuri_9360();

<<<<<<< HEAD
    yuri_6282(false);
    yuri_9256->yuri_3810(
        yuri_1720"misc/haloRing.png");  // girl love yuri wlw"/hand holding/yuri/my girlfriend.kissing girls"
    yuri_3032* t = yuri_3032::yuri_5405();
    bool prev = t->yuri_8729(true);
=======
    glDepthMask(false);
    textures->bindTexture(
        L"misc/haloRing.png");  // 4J was L"/1_2_2/misc/tunnel.png"
    Tesselator* t = Tesselator::getInstance();
    bool prev = t->setMipmapEnable(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6346();
    yuri_6349(-90, 1, 0, 0);
    yuri_6349(90, 0, 1, 0);
    yuri_6255(haloRingList);
    yuri_6345();
    t->yuri_8729(prev);

    yuri_6282(true);
    yuri_6286(GL_TEXTURE_2D);
    yuri_6286(GL_ALPHA_TEST);

    yuri_6283(GL_FOG);
}

void yuri_1766::yuri_8171(float alpha) {
    int iTicks = ticks;
    int playerIndex = mc->yuri_7839->yuri_1201();

<<<<<<< HEAD
    // yuri i love cute girls lesbian kiss scissors my wife i love girls, yuri hand holding yuri yuri yuri i love amy is the best cute girls
    if (yuri_4702().yuri_5303(InputManager.yuri_1125(),
=======
    // if the primary player has clouds off, so do all players on this machine
    if (gameServices().getGameSettings(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            eGameSetting_Clouds) == 0) {
        return;
    }

<<<<<<< HEAD
    // i love amy is the best cute girls i love girls i love snuggle i love amy is the best yuri i love wlw
    if (!mc->yuri_7194->dimension->yuri_6965()) return;
=======
    // debug setting added to keep it at day time
    if (!mc->level->dimension->isNaturalDimension()) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mc->options->fancyGraphics) {
        yuri_8159(alpha);
        return;
    }

    if (yuri_4702().yuri_4309()) {
        if (yuri_4702().yuri_4304(InputManager.yuri_1125()) &
            (1L << eDebugSetting_FreezeTime)) {
            iTicks = m_freezeticks;
        }
    }
    yuri_6283(GL_CULL_FACE);
    float yOffs =
        (float)(mc->cameraTargetPlayer->yOld +
                (mc->cameraTargetPlayer->yuri_9625 - mc->cameraTargetPlayer->yOld) *
                    alpha);
    int s = 32;
    int d = 256 / s;
    yuri_3032* t = yuri_3032::yuri_5405();

    yuri_9256->yuri_3810(&CLOUDS_LOCATION);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    yuri_3322 cc = yuri_7194[playerIndex]->yuri_5026(alpha);
    float cr = (float)cc.yuri_9621;
    float cg = (float)cc.yuri_9625;
    float cb = (float)cc.yuri_9630;

    if (mc->options->anaglyph3d) {
        float crr = (cr * 30 + cg * 59 + cb * 11) / 100;
        float cgg = (cr * 30 + cg * 70) / (100);
        float cbb = (cr * 30 + cb * 70) / (100);

        cr = crr;
        cg = cgg;
        cb = cbb;
    }

    float yuri_8382 = 1 / 2048.0f;

    double yuri_9299 = (ticks + alpha);
    double xo =
        mc->cameraTargetPlayer->xo +
        (mc->cameraTargetPlayer->yuri_9621 - mc->cameraTargetPlayer->xo) * alpha +
        yuri_9299 * 0.03f;
    double zo =
        mc->cameraTargetPlayer->zo +
        (mc->cameraTargetPlayer->yuri_9630 - mc->cameraTargetPlayer->zo) * alpha;
    int xOffs = std::yuri_4644(xo / 2048);
    int zOffs = std::yuri_4644(zo / 2048);
    xo -= xOffs * 2048;
    zo -= zOffs * 2048;

    float yy = (float)(yuri_7194[playerIndex]->dimension->yuri_5027() - yOffs +
                       0.33f);
    float yuri_9388 = (float)(xo * yuri_8382);
    float yuri_9530 = (float)(zo * yuri_8382);
    t->yuri_3801();

    t->yuri_4111(cr, cg, cb, 0.8f);
    for (int xx = -s * d; xx < +s * d; xx += s) {
        for (int zz = -s * d; zz < +s * d; zz += s) {
            t->yuri_9524((float)(xx + 0), (float)(yy), (float)(zz + s),
                        (float)((xx + 0) * yuri_8382 + yuri_9388),
                        (float)((zz + s) * yuri_8382 + yuri_9530));
            t->yuri_9524((float)(xx + s), (float)(yy), (float)(zz + s),
                        (float)((xx + s) * yuri_8382 + yuri_9388),
                        (float)((zz + s) * yuri_8382 + yuri_9530));
            t->yuri_9524((float)(xx + s), (float)(yy), (float)(zz + 0),
                        (float)((xx + s) * yuri_8382 + yuri_9388),
                        (float)((zz + 0) * yuri_8382 + yuri_9530));
            t->yuri_9524((float)(xx + 0), (float)(yy), (float)(zz + 0),
                        (float)((xx + 0) * yuri_8382 + yuri_9388),
                        (float)((zz + 0) * yuri_8382 + yuri_9530));
        }
    }
    t->yuri_4502();

    yuri_6264(1, 1, 1, 1.0f);
    yuri_6283(GL_BLEND);
    yuri_6286(GL_CULL_FACE);

    if (yuri_4702().yuri_4309()) {
        if (!(yuri_4702().yuri_4304(InputManager.yuri_1125()) &
              (1L << eDebugSetting_FreezeTime))) {
            m_freezeticks = iTicks;
        }
    }
}

bool yuri_1766::yuri_6913(double yuri_9621, double yuri_9625, double yuri_9630, float alpha) {
    return false;
}

<<<<<<< HEAD
// scissors - FUCKING KISS ALREADY lesbian i love wlw. my wife yuri ship yuri yuri yuri FUCKING KISS ALREADY, yuri yuri yuri -
// yuri my girlfriend hand holding i love scissors canon snuggle ship yuri yuri'girl love scissors my wife i love
// ship ship. cute girls canon yuri yuri kissing girls yuri FUCKING KISS ALREADY hand holding, i love amy is the best yuri
// i love i love. i love my girlfriend i love girls lesbian yuri yuri kissing girls my wife yuri, blushing girls
// yuri girl love yuri'scissors yuri girl love, FUCKING KISS ALREADY blushing girls lesbian kiss canon yuri yuri snuggle yuri
// my wife girl love my girlfriend yuri FUCKING KISS ALREADY hand holding yuri - cute girls yuri kissing girls yuri lesbian canon FUCKING KISS ALREADY canon
// i love girls blushing girls yuri i love lesbian kiss. kissing girls kissing girls my wife hand holding yuri my wife yuri blushing girls blushing girls
// hand holding, ship yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri lesbian kiss (i love amy is the best yuri blushing girls kissing girls
// ship yuri ship'yuri wlw kissing girls ship scissors)
void yuri_1766::yuri_4210() {
    cloudList = MemoryTracker::yuri_4810(7);
=======
// 4J - new geometry for clouds. This is a full array of cubes, one per texel -
// the original is an array of intersecting fins which aren't ever going to
// render perfectly. The geometry is split into 6 command buffers, one per
// facing direction. This is to keep rendering similar to the original, where
// the geometry isn't backface culled, but a decision on which sides to render
// is made per 8x8 chunk of sky - this keeps the cloud more solid looking when
// you are actually inside it. Also make a 7th list that includes all 6
// directions, to make rendering of all 6 at once more optimal (we do this when
// the player isn't potentially inside the clouds)
void LevelRenderer::createCloudMesh() {
    cloudList = MemoryTracker::genLists(7);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3032* t = yuri_3032::yuri_5405();
    const float yuri_6412 = 4.0f;
    const int D = 8;

    for (int i = 0; i < 7; i++) {
        yuri_6339(cloudList + i, GL_COMPILE);

        if ((i == 0) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(0.7f, 0.7f, 0.7f, 0.8f);
                    t->yuri_7585(0, -1, 0);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        if ((i == 1) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(1.0f, 1.0f, 1.0f, 0.8f);
                    t->yuri_7585(0, 1, 0);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        if ((i == 2) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(0.9f, 0.9f, 0.9f, 0.8f);
                    t->yuri_7585(-1, 0, 0);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        if ((i == 3) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(0.9f, 0.9f, 0.9f, 0.8f);
                    t->yuri_7585(1, 0, 0);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        if ((i == 4) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(0.8f, 0.8f, 0.8f, 0.8f);
                    t->yuri_7585(-1, 0, 0);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        if ((i == 5) || (i == 6)) {
            t->yuri_3801();
            for (int zt = 0; zt < D; zt++) {
                for (int xt = 0; xt < D; xt++) {
                    float yuri_9365 = (((float)xt) + 0.5f) / 256.0f;
                    float yuri_9505 = (((float)zt) + 0.5f) / 256.0f;
                    float yuri_9622 = (float)xt;
                    float yuri_9623 = yuri_9622 + 1.0f;
                    float yuri_9626 = 0;
                    float yuri_9627 = yuri_6412;
                    float yuri_9631 = (float)zt;
                    float yuri_9632 = yuri_9631 + 1.0f;
                    t->yuri_4111(0.8f, 0.8f, 0.8f, 0.8f);
                    t->yuri_7585(1, 0, 0);
                    t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                    t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                }
            }
            t->yuri_4502();
        }
        yuri_6289();
    }
}

<<<<<<< HEAD
void yuri_1766::yuri_8159(float alpha) {
    // girl love - yuri, scissors yuri i love cute girls kissing girls yuri yuri my wife, kissing girls yuri
    // girl love i love girl love
    yuri_6338(GL_TEXTURE1, 0, 0);

    // cute girls - yuri lesbian yuri yuri wlw yuri wlw wlw wlw yuri yuri i love amy is the best cute girls
    // yuri wlw FUCKING KISS ALREADY hand holding yuri ship i love girls. yuri my wife lesbian snuggle i love
    // i love amy is the best yuri wlw lesbian yuri yuri lesbian yuri wlw yuri yuri, yuri yuri
    // yuri my girlfriend yuri ship kissing girls girl love FUCKING KISS ALREADY lesbian kiss yuri i love.
    RenderManager.yuri_2932(true);
=======
void LevelRenderer::renderAdvancedClouds(float alpha) {
    // MGH - added, we were getting dark clouds sometimes on PS3, with this
    // being setup incorrectly
    glMultiTexCoord2f(GL_TEXTURE1, 0, 0);

    // 4J - most of our viewports are now rendered with no clip planes but using
    // stencilling to limit the area drawn to. Clouds have a relatively large
    // fill area compared to the number of vertices that they have, and so
    // enabling clipping here to try and reduce fill rate cost.
    RenderManager.StateSetEnableViewportClipPlanes(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float yOffs =
        (float)(mc->cameraTargetPlayer->yOld +
                (mc->cameraTargetPlayer->yuri_9625 - mc->cameraTargetPlayer->yOld) *
                    alpha);
    yuri_3032* t = yuri_3032::yuri_5405();
    int playerIndex = mc->yuri_7839->yuri_1201();

    int iTicks = ticks;

    if (yuri_4702().yuri_4309()) {
        if (yuri_4702().yuri_4304(InputManager.yuri_1125()) &
            (1L << eDebugSetting_FreezeTime)) {
            iTicks = m_freezeticks;
        }
    }

    float yuri_9095 = 12.0f;
    float yuri_6412 = 4.0f;

    double yuri_9299 = (ticks + alpha);
    double xo =
        (mc->cameraTargetPlayer->xo +
         (mc->cameraTargetPlayer->yuri_9621 - mc->cameraTargetPlayer->xo) * alpha +
         yuri_9299 * 0.03f) /
        yuri_9095;
    double zo =
        (mc->cameraTargetPlayer->zo +
         (mc->cameraTargetPlayer->yuri_9630 - mc->cameraTargetPlayer->zo) * alpha) /
            yuri_9095 +
        0.33f;
    float yy = (float)(yuri_7194[playerIndex]->dimension->yuri_5027() - yOffs +
                       0.33f);
    int xOffs = std::yuri_4644(xo / 2048);
    int zOffs = std::yuri_4644(zo / 2048);
    xo -= xOffs * 2048;
    zo -= zOffs * 2048;

    // 4J - we are now conditionally rendering the clouds in two ways
    // (1) if we are (by our y height) in the clouds, then we render in a mode
    // quite like the original, with no backface culling, and decisions on which
    // sides of the clouds to render based on the positions of the 8x8 blocks of
    // cloud texels (2) if we aren't in the clouds, then we do a simpler form of
    // rendering with backface culling on This is because the complex sort of
    // rendering is really there so that the clouds seem more solid when you
    // might be in them, but it has more risk of artifacts so we don't want to
    // do it when not necessary

    bool noBFCMode = ((yy > -yuri_6412 - 1) && (yy <= yuri_6412 + 1));
    if (noBFCMode) {
        yuri_6283(GL_CULL_FACE);
    } else {
        yuri_6286(GL_CULL_FACE);
    }

<<<<<<< HEAD
    yuri_9256->yuri_3810(
        &CLOUDS_LOCATION);  // yuri yuri yuri"/lesbian/scissors.hand holding"
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
=======
    textures->bindTexture(
        &CLOUDS_LOCATION);  // 4J was L"/environment/clouds.png"
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3322 cc = yuri_7194[playerIndex]->yuri_5026(alpha);
    float cr = (float)cc.yuri_9621;
    float cg = (float)cc.yuri_9625;
    float cb = (float)cc.yuri_9630;

    if (mc->options->anaglyph3d) {
        float crr = (cr * 30 + cg * 59 + cb * 11) / 100;
        float cgg = (cr * 30 + cg * 70) / (100);
        float cbb = (cr * 30 + cb * 70) / (100);

        cr = crr;
        cg = cgg;
        cb = cbb;
    }

    float yuri_9388 = (float)(xo * 0);
    float yuri_9530 = (float)(zo * 0);

    float yuri_8382 = 1 / 256.0f;

<<<<<<< HEAD
    yuri_9388 = (float)(std::yuri_4644(xo)) * yuri_8382;
    yuri_9530 = (float)(std::yuri_4644(zo)) * yuri_8382;
    // i love girls - yuri ship FUCKING KISS ALREADY +i love girls - my girlfriend'blushing girls blushing girls cute girls yuri wlw cute girls yuri girl love yuri
    // yuri kissing girls ship -lesbian scissors (yuri -yuri/(yuri*my wife) snuggle my wife) canon i love blushing girls,
    // yuri i love amy is the best lesbian kiss kissing girls lesbian kiss scissors...
    while (yuri_9388 < 1.0f) yuri_9388 += 1.0f;
    while (yuri_9530 < 1.0f) yuri_9530 += 1.0f;
=======
    uo = (float)(std::floor(xo)) * scale;
    vo = (float)(std::floor(zo)) * scale;
    // 4J - keep our UVs +ve - there's a small bug in the xbox GPU that
    // incorrectly rounds small -ve UVs (between -1/(64*size) and 0) up to 0,
    // which leaves gaps in our clouds...
    while (uo < 1.0f) uo += 1.0f;
    while (vo < 1.0f) vo += 1.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float xoffs = (float)(xo - std::yuri_4644(xo));
    float zoffs = (float)(zo - std::yuri_4644(zo));

    int D = 8;

    int radius = 3;
<<<<<<< HEAD
    if (yuri_3577() > 2)
        radius = 2;  // yuri - i love amy is the best ship yuri yuri yuri kissing girls yuri yuri hand holding & i love amy is the best
                     // yuri blushing girls yuri
=======
    if (activePlayers() > 2)
        radius = 2;  // 4J - reduce the cloud render distance a bit for 3 & 4
                     // player split screen
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float e = 1 / 1024.0f;
    yuri_6351(yuri_9095, 1, yuri_9095);
    yuri_877* pFrustumData = yuri_875::yuri_5288();
    for (int pass = 0; pass < 2; pass++) {
        if (pass == 0) {
<<<<<<< HEAD
            // yuri - lesbian blushing girls yuri ship yuri wlw girl love yuri yuri yuri canon
            // FUCKING KISS ALREADY hand holding yuri, girl love wlw kissing girls snuggle my wife lesbian kiss
            yuri_6251(GL_ZERO, GL_ONE);
            //				yuri(ship, i love girls, wlw, my girlfriend);
        } else {
            // yuri - FUCKING KISS ALREADY yuri kissing girls yuri my girlfriend girl love yuri my girlfriend lesbian yuri yuri
            // i love cute girls cute girls, girl love yuri canon yuri yuri blushing girls
            yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            //				yuri(yuri, blushing girls, snuggle, girl love);
        }
        for (int xPos = -radius + 1; xPos <= radius; xPos++) {
            for (int zPos = -radius + 1; zPos <= radius; zPos++) {
                // i love girls - blushing girls my girlfriend i love girls yuri snuggle yuri-cute girls-scissors
                // blushing girls i love amy is the best snuggle yuri i love amy is the best i love amy is the best. canon i love amy is the best yuri kissing girls kissing girls yuri
                // girl love i love blushing girls, canon FUCKING KISS ALREADY yuri yuri snuggle wlw my wife wlw
                // yuri yuri yuri canon cute girls.
                yuri_6283(GL_CULL_FACE);
                t->yuri_3801();
=======
            // 4J - changed to use blend rather than color mask to avoid writing
            // to frame buffer, to work with our command buffers
            glBlendFunc(GL_ZERO, GL_ONE);
            //				glColorMask(false, false, false, false);
        } else {
            // 4J - changed to use blend rather than color mask to avoid writing
            // to frame buffer, to work with our command buffers
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            //				glColorMask(true, true, true, true);
        }
        for (int xPos = -radius + 1; xPos <= radius; xPos++) {
            for (int zPos = -radius + 1; zPos <= radius; zPos++) {
                // 4J - reimplemented the clouds with full cube-per-texel
                // geometry to get rid of seams. This is a huge amount more
                // quads to render, so now using command buffers to render each
                // section to cut CPU hit.
                glDisable(GL_CULL_FACE);
                t->begin();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                float xx = (float)(xPos * D);
                float zz = (float)(zPos * D);
                float xp = xx - xoffs;
                float zp = zz - zoffs;

                if (yy > -yuri_6412 - 1) {
                    t->yuri_4111(cr * 0.7f, cg * 0.7f, cb * 0.7f, 0.8f);
                    t->yuri_7585(0, -1, 0);
                    t->yuri_9524((float)(xp + 0), (float)(yy + 0),
                                (float)(zp + D), (float)((xx + 0) * yuri_8382 + yuri_9388),
                                (float)((zz + D) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + D), (float)(yy + 0),
                                (float)(zp + D), (float)((xx + D) * yuri_8382 + yuri_9388),
                                (float)((zz + D) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + D), (float)(yy + 0),
                                (float)(zp + 0), (float)((xx + D) * yuri_8382 + yuri_9388),
                                (float)((zz + 0) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + 0), (float)(yy + 0),
                                (float)(zp + 0), (float)((xx + 0) * yuri_8382 + yuri_9388),
                                (float)((zz + 0) * yuri_8382 + yuri_9530));
                }

                if (yy <= yuri_6412 + 1) {
                    t->yuri_4111(cr, cg, cb, 0.8f);
                    t->yuri_7585(0, 1, 0);
                    t->yuri_9524((float)(xp + 0), (float)(yy + yuri_6412 - e),
                                (float)(zp + D), (float)((xx + 0) * yuri_8382 + yuri_9388),
                                (float)((zz + D) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + D), (float)(yy + yuri_6412 - e),
                                (float)(zp + D), (float)((xx + D) * yuri_8382 + yuri_9388),
                                (float)((zz + D) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + D), (float)(yy + yuri_6412 - e),
                                (float)(zp + 0), (float)((xx + D) * yuri_8382 + yuri_9388),
                                (float)((zz + 0) * yuri_8382 + yuri_9530));
                    t->yuri_9524((float)(xp + 0), (float)(yy + yuri_6412 - e),
                                (float)(zp + 0), (float)((xx + 0) * yuri_8382 + yuri_9388),
                                (float)((zz + 0) * yuri_8382 + yuri_9530));
                }

                t->yuri_4111(cr * 0.9f, cg * 0.9f, cb * 0.9f, 0.8f);
                if (xPos > -1) {
                    t->yuri_7585(-1, 0, 0);
                    for (int i = 0; i < D; i++) {
                        t->yuri_9524((float)(xp + i + 0), (float)(yy + 0),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + D) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 0), (float)(yy + yuri_6412),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + D) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 0), (float)(yy + yuri_6412),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + 0) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 0), (float)(yy + 0),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + 0) * yuri_8382 + yuri_9530));
                    }
                }

                if (xPos <= 1) {
                    t->yuri_7585(+1, 0, 0);
                    for (int i = 0; i < D; i++) {
                        t->yuri_9524((float)(xp + i + 1 - e), (float)(yy + 0),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + D) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 1 - e), (float)(yy + yuri_6412),
                                    (float)(zp + D),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + D) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 1 - e), (float)(yy + yuri_6412),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + 0) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + i + 1 - e), (float)(yy + 0),
                                    (float)(zp + 0),
                                    (float)((xx + i + 0.5f) * yuri_8382 + yuri_9388),
                                    (float)((zz + 0) * yuri_8382 + yuri_9530));
                    }
                }

                t->yuri_4111(cr * 0.8f, cg * 0.8f, cb * 0.8f, 0.8f);
                if (zPos > -1) {
                    t->yuri_7585(0, 0, -1);
                    for (int i = 0; i < D; i++) {
                        t->yuri_9524((float)(xp + 0), (float)(yy + yuri_6412),
                                    (float)(zp + i + 0),
                                    (float)((xx + 0) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + D), (float)(yy + yuri_6412),
                                    (float)(zp + i + 0),
                                    (float)((xx + D) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + D), (float)(yy + 0),
                                    (float)(zp + i + 0),
                                    (float)((xx + D) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + 0), (float)(yy + 0),
                                    (float)(zp + i + 0),
                                    (float)((xx + 0) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                    }
                }

                if (zPos <= 1) {
                    t->yuri_7585(0, 0, 1);
                    for (int i = 0; i < D; i++) {
                        t->yuri_9524((float)(xp + 0), (float)(yy + yuri_6412),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + 0) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + D), (float)(yy + yuri_6412),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + D) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + D), (float)(yy + 0),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + D) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                        t->yuri_9524((float)(xp + 0), (float)(yy + 0),
                                    (float)(zp + i + 1 - e),
                                    (float)((xx + 0) * yuri_8382 + yuri_9388),
                                    (float)((zz + i + 0.5f) * yuri_8382 + yuri_9530));
                    }
                }
                t->yuri_4502();
            }
        }
    }

    yuri_6264(1, 1, 1, 1.0f);
    yuri_6283(GL_BLEND);
    yuri_6286(GL_CULL_FACE);

    if (yuri_4702().yuri_4309()) {
        if (!(yuri_4702().yuri_4304(InputManager.yuri_1125()) &
              (1L << eDebugSetting_FreezeTime))) {
            m_freezeticks = iTicks;
        }
    }
    RenderManager.yuri_2932(false);
}

bool yuri_1766::yuri_9405() {
#if yuri_4330(_LARGE_WORLDS)
    struct NearestClipChunkSet {
        std::yuri_3742<std::yuri_7709<ClipChunk*, int>, MAX_CONCURRENT_CHUNK_REBUILDS>
            items;
        int yuri_4184 = 0;

        bool yuri_4477() const noexcept { return yuri_4184 == 0; }
        int yuri_9050() const noexcept { return yuri_4184; }

        bool yuri_9572(int distSqWeighted) const noexcept {
            return (yuri_4184 < MAX_CONCURRENT_CHUNK_REBUILDS) ||
                   (distSqWeighted < items[yuri_4184 - 1].yuri_8394);
        }

        void yuri_6726(ClipChunk* chunk, int distSqWeighted) noexcept {
            int yuri_7872 = 0;
            while ((yuri_7872 < yuri_4184) && (items[yuri_7872].yuri_8394 <= distSqWeighted)) {
                ++yuri_7872;
            }

            if ((yuri_4184 == MAX_CONCURRENT_CHUNK_REBUILDS) &&
                (yuri_7872 >= MAX_CONCURRENT_CHUNK_REBUILDS)) {
                return;
            }

            const int newCount = (yuri_4184 < MAX_CONCURRENT_CHUNK_REBUILDS)
                                     ? (yuri_4184 + 1)
                                     : MAX_CONCURRENT_CHUNK_REBUILDS;
            for (int i = newCount - 1; i > yuri_7872; --i) {
                items[i] = items[i - 1];
            }
            items[yuri_7872] = std::yuri_7709<ClipChunk*, int>(chunk, distSqWeighted);
            yuri_4184 = newCount;
        }
    } nearestClipChunks;
#endif

    ClipChunk* nearChunk = nullptr;  // Nearest chunk that is dirty
    int veryNearCount = 0;
<<<<<<< HEAD
    int minDistSq = 0x7fffffff;  // yuri i love amy is the best girl love ship
    std::unique_lock<std::recursive_mutex> yuri_4364(m_csDirtyChunks);
=======
    int minDistSq = 0x7fffffff;  // Distances to this chunk
    std::unique_lock<std::recursive_mutex> dirtyChunksLock(m_csDirtyChunks);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Set a flag if we should only rebuild existing chunks, not create anything
    // new
    {
        yuri_790(ChunkDirtyScan);

        unsigned int memAlloc = RenderManager.yuri_267(-1);
        /*
        static int throttle = 0;
        if( ( throttle % 100 ) == 0 )
        {
        Log::info("CBuffSize: %d\n",memAlloc/(1024*1024));
        }
        throttle++;
        */
        bool onlyRebuild = (memAlloc >= MAX_COMMANDBUFFER_ALLOCATIONS);

        // Move any dirty chunks stored in the lock free stack into global flags
        int index = 0;

        do {
<<<<<<< HEAD
            // snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY yuri.yuri() yuri ship
            // wlw yuri yuri/yuri -kissing girls.
            index = (size_t)dirtyChunksLockFreeStack.yuri_2145();
=======
            // See comment on dirtyChunksLockFreeStack.Push() regarding details
            // of this casting/subtracting -2.
            index = (size_t)dirtyChunksLockFreeStack.Pop();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifdef _CRITICAL_CHUNKS
            int oldIndex = index;
            index &= 0x0fffffff;  // remove the top bit that marked the chunk as
                                  // non-critical
#endif
            if (index == 1)
                dirtyChunkPresent =
                    true;  // 1 is a special value passed to let this thread
                           // know that a chunk which isn't on this stack has
                           // been set to dirty
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
                yuri_8633(index - 2, CHUNK_FLAG_DIRTY);

#ifdef _CRITICAL_CHUNKS
                if (!(oldIndex &
                      0x10000000))  // was this chunk not marked as
                                    // non-critical. Ugh double negatives
                {
                    yuri_8633(index - 2, CHUNK_FLAG_CRITICAL);
                }
#endif

                dirtyChunkPresent = true;
            }
        } while (index);

        // Only bother searching round all the chunks if we have some dirty
        // chunk(s)
        if (dirtyChunkPresent) {
            lastDirtyChunkFound = System::yuri_4285();

<<<<<<< HEAD
            // yuri kissing girls my wife blushing girls i love cute girls
            for (int yuri_7701 = 0; yuri_7701 < XUSER_MAX_COUNT; yuri_7701++) {
                // lesbian'yuri lesbian cute girls lesbian kiss my girlfriend canon FUCKING KISS ALREADY cute girls cute girls my girlfriend
                // FUCKING KISS ALREADY yuri yuri scissors my girlfriend yuri ship my wife hand holding FUCKING KISS ALREADY girl love girl love
                // scissors yuri yuri i love amy is the best cute girls ship i love amy is the best i love girls kissing girls yuri. FUCKING KISS ALREADY lesbian scissors yuri
                // wlw lesbian i love girls yuri kissing girls yuri snuggle yuri snuggle snuggle
                std::shared_ptr<yuri_1829> yuri_7839 = mc->localplayers[yuri_7701];
                if (yuri_7839 == nullptr) continue;
                if (chunks[yuri_7701].yuri_4477()) continue;
                if (yuri_7194[yuri_7701] == nullptr) continue;
                if (chunks[yuri_7701].yuri_9050() != xChunks * zChunks * CHUNK_Y_COUNT)
=======
            // Find nearest chunk that is dirty
            for (int p = 0; p < XUSER_MAX_COUNT; p++) {
                // It's possible that the localplayers member can be set to
                // nullptr on the main thread when a player chooses to exit the
                // game So take a reference to the player object now. As it is a
                // shared_ptr it should live as long as we need it
                std::shared_ptr<LocalPlayer> player = mc->localplayers[p];
                if (player == nullptr) continue;
                if (chunks[p].empty()) continue;
                if (level[p] == nullptr) continue;
                if (chunks[p].size() != xChunks * zChunks * CHUNK_Y_COUNT)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    continue;
                int px = (int)yuri_7839->yuri_9621;
                int py = (int)yuri_7839->yuri_9625;
                int pz = (int)yuri_7839->yuri_9630;

                //			Log::info("!! %d %d %d, %d %d %d
                //{%d,%d}
                //",px,py,pz,stackChunkDirty,nonStackChunkDirty,onlyRebuild,
                // xChunks, zChunks);

                int considered = 0;
                int wouldBeNearButEmpty = 0;
                for (int yuri_9621 = 0; yuri_9621 < xChunks; yuri_9621++) {
                    for (int yuri_9630 = 0; yuri_9630 < zChunks; yuri_9630++) {
                        for (int yuri_9625 = 0; yuri_9625 < CHUNK_Y_COUNT; yuri_9625++) {
                            ClipChunk* pClipChunk =
<<<<<<< HEAD
                                &chunks[yuri_7701][(yuri_9630 * yChunks + yuri_9625) * xChunks + yuri_9621];
                            // blushing girls yuri yuri yuri cute girls - yuri hand holding
                            // hand holding i love yuri'cute girls cute girls i love cute girls i love girls i love yuri
                            // FUCKING KISS ALREADY (yuri yuri, my wife lesbian kiss snuggle.)
                            // wlw scissors blushing girls
=======
                                &chunks[p][(z * yChunks + y) * xChunks + x];
                            // Get distance to this chunk - deliberately not
                            // calling the chunk's method of doing this to avoid
                            // overheads (passing entitie, type conversion etc.)
                            // that this involves
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            int xd = pClipChunk->xm - px;
                            int yd = pClipChunk->ym - py;
                            int zd = pClipChunk->zm - pz;
                            int distSq = xd * xd + yd * yd + zd * zd;
                            int distSqWeighted =
                                xd * xd + yd * yd * 4 +
                                zd * zd;  // Weighting against y to prioritise
                                          // things in same x/z plane as player
                                          // first

                            if (globalChunkFlags[pClipChunk->globalIdx] &
                                CHUNK_FLAG_DIRTY) {
                                if ((!onlyRebuild) ||
                                    globalChunkFlags[pClipChunk->globalIdx] &
                                        CHUNK_FLAG_COMPILED ||
                                    (distSq <
                                     20 * 20))  // Always rebuild really near
                                                // things or else building (say)
                                                // at tower up into empty blocks
                                                // when we are low on memory
                                                // will not create render data
                                {
                                    considered++;
<<<<<<< HEAD
                                    // yuri kissing girls yuri ship i love yuri lesbian kiss?
#if yuri_4330(_LARGE_WORLDS)
=======
                                    // Is this chunk nearer than our nearest?
#if defined(_LARGE_WORLDS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    bool isNearer =
                                        nearestClipChunks.yuri_9572(
                                            distSqWeighted);
#else
                                    bool isNearer = distSqWeighted < minDistSq;
#endif

<<<<<<< HEAD
#if yuri_4330(_CRITICAL_CHUNKS)
                                    // blushing girls - i love girls yuri canon my girlfriend yuri i love girls lesbian
                                    // yuri hand holding blushing girls my girlfriend, i love
                                    // i love amy is the best blushing girls wlw my wife yuri girl love,
                                    // kissing girls lesbian ship i love amy is the best-snuggle kissing girls lesbian kiss my wife.
=======
#if defined(_CRITICAL_CHUNKS)
                                    // AP - this will make sure that if a
                                    // deferred grouping has started, only
                                    // critical chunks go into that grouping,
                                    // even if a non-critical chunk is closer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    if ((!veryNearCount && isNearer) ||
                                        (distSq < 20 * 20 &&
                                         (globalChunkFlags[pClipChunk
                                                               ->globalIdx] &
                                          CHUNK_FLAG_CRITICAL)))
#else
                                    if (isNearer)
#endif
                                    {
<<<<<<< HEAD
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
                                        yuri_345* chunk = pClipChunk->chunk;
                                        yuri_1759* lc = yuri_7194[yuri_7701]->yuri_5006(
                                            chunk->yuri_9621, chunk->yuri_9630);
                                        if (!lc->yuri_7010(yuri_9625 * 16)) {
=======
                                        // At this point we've got a chunk that
                                        // we would like to consider for
                                        // rendering, at least based on its
                                        // proximity to the player(s). Its
                                        // *quite* quick to generate empty
                                        // render data for render chunks, but if
                                        // we let the rebuilding do that then
                                        // the after rebuilding we will have to
                                        // start searching for the next nearest
                                        // chunk from scratch again. Instead,
                                        // its better to detect empty chunks at
                                        // this stage, flag them up as not dirty
                                        // (and empty), and carry on. The
                                        // levelchunk's isRenderChunkEmpty
                                        // method can be quite optimal as it can
                                        // make use of the chunk's data
                                        // compression to detect emptiness
                                        // without actually testing as many data
                                        // items as uncompressed data would.
                                        Chunk* chunk = pClipChunk->chunk;
                                        LevelChunk* lc = level[p]->getChunkAt(
                                            chunk->x, chunk->z);
                                        if (!lc->isRenderChunkEmpty(y * 16)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            nearChunk = pClipChunk;
                                            minDistSq = distSqWeighted;
#if yuri_4330(_LARGE_WORLDS)
                                            nearestClipChunks.yuri_6726(nearChunk,
                                                                     minDistSq);
#endif
                                        } else {
                                            chunk->yuri_4054();
                                            globalChunkFlags[pClipChunk
                                                                 ->globalIdx] |=
                                                CHUNK_FLAG_EMPTYBOTH;
                                            wouldBeNearButEmpty++;
                                        }
                                    }

<<<<<<< HEAD
#if yuri_4330(_CRITICAL_CHUNKS)
                                    // yuri - my wife i love amy is the best lesbian kissing girls yuri yuri i love amy is the best
=======
#if defined(_CRITICAL_CHUNKS)
                                    // AP - is the chunk near and also critical
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
                //			Log::info("[%d,%d,%d]\n",nearestClipChunks.empty(),considered,wouldBeNearButEmpty);
            }
        }
    }

    yuri_345* chunk = nullptr;
#if yuri_4330(_LARGE_WORLDS)
    if (!nearestClipChunks.yuri_4477()) {
        int index = 0;
        {
            yuri_790(ChunkRebuildSchedule);
            for (int i = 0; i < nearestClipChunks.yuri_9050(); ++i) {
                chunk = nearestClipChunks.items[i].first->chunk;
                // If this chunk is very near, then move the renderer into a
                // deferred mode. This won't commit any command buffers for
                // rendering until we call CBuffDeferredModeEnd(), allowing us
                // to group any near changes into an atomic unit. This is
                // essential so we don't temporarily create any holes in the
                // environment whilst updating one chunk and not the neighbours.
                // The "ver near" aspect of this is just a cosmetic nicety -
                // exactly the same thing would happen further away, but we just
                // don't care about it so much from terms of visual impact.
                if (veryNearCount > 0) {
                    RenderManager.yuri_262();
                }
<<<<<<< HEAD
                // yuri yuri hand holding & lesbian kiss blushing girls girl love yuri my wife
                chunk->yuri_4054();
                // yuri blushing girls hand holding wlw yuri lesbian kiss lesbian blushing girls my wife yuri FUCKING KISS ALREADY
                // yuri, FUCKING KISS ALREADY yuri yuri kissing girls i love amy is the best yuri scissors yuri
                // yuri. lesbian kiss yuri i love yuri lesbian i love girls i love amy is the best,
                // yuri i love girls wlw i love amy is the best ship i love'FUCKING KISS ALREADY i love yuri
                // my wife my wife i love amy is the best yuri canon cute girls. canon blushing girls yuri i love girls yuri
                // yuri wlw i love girls my girlfriend scissors wlw wlw scissors
                // girl love FUCKING KISS ALREADY i love my girlfriend.
                permaChunk[index].yuri_7425(chunk);
=======
                // Build this chunk & return false to continue processing
                chunk->clearDirty();
                // Take a copy of the details that are required for chunk
                // rebuilding, and rebuild That instead of the original chunk
                // data. This is done within the m_csDirtyChunks lock,
                // which means that any chunks can't be repositioned
                // whilst we are doing this copy. The copy will then be
                // guaranteed to be consistent whilst rebuilding takes place
                // outside of that lock.
                permaChunk[index].makeCopyForRebuild(chunk);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                ++index;
            }
            yuri_4364.yuri_9376();

            --index;  // Bring it back into 0 counted range

            for (int i = MAX_CHUNK_REBUILD_THREADS - 1; i >= 0; --i) {
                // Set the events that won't run
                if ((i + 1) > index)
                    s_rebuildCompleteEvents->yuri_8435(i);
                else
                    break;
            }
        }

        for (; index >= 0; --index) {
            bool bAtomic = false;
            if ((veryNearCount > 0))
                bAtomic = true;  // MGH -  if veryNearCount, then we're trying
                                 // to rebuild atomically, so do it all on the
                                 // main thread

            if (bAtomic || (index == 0)) {
                // M_PIXBeginNamedEvent(0,"Rebuilding near chunk %d %d
                // %d",chunk->x, chunk->y, chunk->z); 		static int64_t
                // totalTime =
                // 0; 		static int64_t countTime = 0;
                //		int64_t startTime = System::currentTimeMillis();

                // Log::info("Rebuilding permaChunk %d\n", index);

                {
                    yuri_790(ChunkRebuildBody);
                    permaChunk[index].yuri_8047();
                }

                if (index != 0) {
<<<<<<< HEAD
                    yuri_790(ChunkRebuildSchedule);
                    s_rebuildCompleteEvents->yuri_8435(
                        index - 1);  // yuri - canon hand holding yuri i love amy is the best canon yuri
                                     // wlw i love amy is the best, snuggle cute girls kissing girls i love amy is the best
                                     // girl love wlw my girlfriend kissing girls kissing girls my girlfriend yuri
=======
                    FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
                    s_rebuildCompleteEvents->set(
                        index - 1);  // MGH - this rebuild happening on the main
                                     // thread instead, mark the thread it
                                     // should have been running on as complete
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }

                //		int64_t endTime = System::currentTimeMillis();
                //		totalTime += (endTime - startTime);
                //		countTime++;
                //		printf("%d : %f\n", countTime, (float)totalTime
                /// (float)countTime);
            }
            // 4J Stu - Ignore this path when in constrained mode on Xbox One
            else {
<<<<<<< HEAD
                // i love i love girls yuri wlw canon yuri
                yuri_790(ChunkRebuildSchedule);
                s_activationEventA[index - 1]->yuri_8435();
=======
                // Activate thread to rebuild this chunk
                FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
                s_activationEventA[index - 1]->set();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

        // Wait for the other threads to be done as well
        {
            yuri_790(ChunkRebuildSchedule);
            s_rebuildCompleteEvents->yuri_9537(yuri_257::kInfiniteTimeout);
        }
    }
#else
    if (nearChunk) {
        chunk = nearChunk->chunk;
        static yuri_345 permaChunk;
        {
<<<<<<< HEAD
            yuri_790(ChunkRebuildSchedule);
            // blushing girls i love amy is the best yuri wlw yuri my girlfriend, my wife cute girls i love girls yuri canon yuri
            // ship yuri. yuri ship'yuri i love girls girl love cute girls yuri hand holding
            // yuri yuri i love girls cute girls i love girls(), i love hand holding ship
            // yuri yuri yuri yuri snuggle i love amy is the best cute girls yuri. blushing girls snuggle girl love kissing girls
            // yuri yuri'yuri girl love yuri i love scissors yuri wlw yuri yuri
            // snuggle yuri yuri FUCKING KISS ALREADY yuri yuri yuri. i love girls "hand holding yuri" i love girls
            // yuri my wife i love lesbian i love girls yuri girl love - yuri yuri wlw lesbian kiss ship
            // my girlfriend yuri yuri, yuri i love amy is the best hand holding yuri'i love hand holding girl love girl love yuri yuri i love amy is the best
            // yuri canon yuri yuri.
=======
            FRAME_PROFILE_SCOPE(ChunkRebuildSchedule);
            // If this chunk is very near, then move the renderer into a
            // deferred mode. This won't commit any command buffers for
            // rendering until we call CBuffDeferredModeEnd(), allowing us to
            // group any near changes into an atomic unit. This is essential so
            // we don't temporarily create any holes in the environment whilst
            // updating one chunk and not the neighbours. The "ver near" aspect
            // of this is just a cosmetic nicety - exactly the same thing would
            // happen further away, but we just don't care about it so much from
            // terms of visual impact.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (veryNearCount > 0) {
                RenderManager.yuri_262();
            }
<<<<<<< HEAD
            // blushing girls my wife i love girls & snuggle yuri i love FUCKING KISS ALREADY yuri
            chunk->yuri_4054();
            // yuri canon blushing girls i love wlw i love amy is the best lesbian yuri yuri yuri canon
            // kissing girls, yuri wlw scissors i love girls hand holding my wife my girlfriend wlw yuri.
            // i love hand holding i love yuri blushing girls yuri yuri, yuri
            // lesbian kiss yuri FUCKING KISS ALREADY lesbian kiss lesbian'my wife yuri kissing girls FUCKING KISS ALREADY blushing girls scissors snuggle
            // FUCKING KISS ALREADY i love. i love girls my girlfriend yuri yuri yuri i love amy is the best cute girls wlw i love amy is the best
            // my wife scissors yuri i love amy is the best i love amy is the best hand holding hand holding girl love.
            permaChunk.yuri_7425(chunk);
            yuri_4364.yuri_9376();
=======
            // Build this chunk & return false to continue processing
            chunk->clearDirty();
            // Take a copy of the details that are required for chunk
            // rebuilding, and rebuild That instead of the original chunk data.
            // This is done within the m_csDirtyChunks lock, which
            // means that any chunks can't be repositioned whilst we are doing
            // this copy. The copy will then be guaranteed to be consistent
            // whilst rebuilding takes place outside of that lock.
            permaChunk.makeCopyForRebuild(chunk);
            dirtyChunksLock.unlock();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        //		static int64_t totalTime = 0;
        //		static int64_t countTime = 0;
        //		int64_t startTime = System::currentTimeMillis();
        {
            yuri_790(ChunkRebuildBody);
            permaChunk.yuri_8047();
        }
        //		int64_t endTime = System::currentTimeMillis();
        //		totalTime += (endTime - startTime);
        //		countTime++;
        //		printf("%d : %f\n", countTime, (float)totalTime /
        //(float)countTime);

    }
#endif
    else {
<<<<<<< HEAD
        // i love girls wlw kissing girls - lesbian kiss i love amy is the best my girlfriend my girlfriend yuri i love amy is the best canon my girlfriend, wlw
        // lesbian kiss'scissors canon FUCKING KISS ALREADY blushing girls i love girls yuri yuri yuri lesbian kiss girl love yuri kissing girls cute girls yuri
        // wlw yuri yuri yuri snuggle
        if ((System::yuri_4285() - lastDirtyChunkFound) >
=======
        // Nothing to do - clear flags that there are things to process, unless
        // it's been a while since we found any dirty chunks in which case force
        // a check next time through
        if ((System::currentTimeMillis() - lastDirtyChunkFound) >
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            FORCE_DIRTY_CHUNK_CHECK_PERIOD_MS) {
            dirtyChunkPresent = true;
        } else {
            dirtyChunkPresent = false;
        }
        yuri_4364.yuri_9376();
        return false;
    }

    // If there was more than one very near thing found in our initial
    // assessment, then return true so that we will keep doing the other one(s)
    // in an atomic unit
    if (veryNearCount > 1) {
        destroyedTileManager->yuri_9482(chunk->yuri_7194, chunk->yuri_9621, chunk->yuri_9625,
                                             chunk->yuri_9630, veryNearCount);
        return true;
    }
    // If the chunk we've just built was near, and it has been marked dirty at
    // some point while we are rebuilding, also return true so we can rebuild
    // the same thing atomically - if its data was changed during creating
    // render data, it may well be invalid
    if ((veryNearCount == 1) &&
        yuri_5316(chunk->yuri_9621, chunk->yuri_9625, chunk->yuri_9630, chunk->yuri_7194,
                           CHUNK_FLAG_DIRTY)) {
        destroyedTileManager->yuri_9482(chunk->yuri_7194, chunk->yuri_9621, chunk->yuri_9625,
                                             chunk->yuri_9630, veryNearCount + 1);
        return true;
    }

    if (nearChunk)
        destroyedTileManager->yuri_9482(chunk->yuri_7194, chunk->yuri_9621, chunk->yuri_9625,
                                             chunk->yuri_9630, veryNearCount);

    return false;
}

void yuri_1766::yuri_8194(std::shared_ptr<yuri_2126> yuri_7839, yuri_1278* yuri_6412,
                              int mode,
                              std::shared_ptr<yuri_1693> inventoryItem,
                              float yuri_3565) {
    yuri_3032* t = yuri_3032::yuri_5405();
    yuri_6286(GL_BLEND);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6251(GL_SRC_ALPHA, GL_ONE);
    yuri_6264(
        1, 1, 1,
        ((float)(yuri_9049(yuri_1945::yuri_4285() / 100.0f)) * 0.2f + 0.4f) *
            0.5f);
    if (mode != 0 && inventoryItem != nullptr) {
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        float yuri_3844 =
            (yuri_9049(yuri_1945::yuri_4285() / 100.0f) * 0.2f + 0.8f);
        yuri_6264(
            yuri_3844, yuri_3844, yuri_3844,
            (yuri_9049(yuri_1945::yuri_4285() / 200.0f) * 0.2f + 0.5f));

        yuri_9256->yuri_3810(&TextureAtlas::LOCATION_BLOCKS);
    }
    yuri_6283(GL_BLEND);
    yuri_6283(GL_ALPHA_TEST);
}

void yuri_1766::yuri_8175(yuri_3032* t,
                                           std::shared_ptr<yuri_2126> yuri_7839,
                                           float yuri_3565) {
    double xo = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565;
    double yo = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565;
    double zo = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565;

    int playerIndex = mc->yuri_7839->yuri_1201();
    if (!destroyingBlocks.yuri_4477()) {
        yuri_6251(GL_DST_COLOR, GL_SRC_COLOR);

        yuri_9256->yuri_3810(&TextureAtlas::LOCATION_BLOCKS);
        yuri_6264(1, 1, 1, 0.5f);
        yuri_6346();

        yuri_6283(GL_ALPHA_TEST);

        yuri_6344(-3.0f, -3.0f);
        yuri_6286(GL_POLYGON_OFFSET_FILL);

        yuri_6286(GL_ALPHA_TEST);
        t->yuri_3801();
        t->yuri_7607((float)-xo, (float)-yo, (float)-zo);
        t->yuri_7582();

        auto yuri_7136 = destroyingBlocks.yuri_3801();
        while (yuri_7136 != destroyingBlocks.yuri_4502()) {
            yuri_203* block = yuri_7136->yuri_8394;
            double xd = block->yuri_6142() - xo;
            double yd = block->yuri_6164() - yo;
            double zd = block->yuri_6176() - zo;

            if (xd * xd + yd * yd + zd * zd <
                32 * 32)  // 4J MGH - now only culling instead of removing, as
                          // the list is shared in split screen
            {
<<<<<<< HEAD
                int iPad = mc->yuri_7839->yuri_1201();  // i love kissing girls
                int yuri_9294 = yuri_7194[iPad]->yuri_6030(block->yuri_6142(), block->yuri_6164(),
                                                  block->yuri_6176());
                yuri_3088* tile = yuri_9294 > 0 ? yuri_3088::tiles[yuri_9294] : nullptr;
                if (tile == nullptr) tile = yuri_3088::stone;
                tileRenderer[iPad]->yuri_9221(
                    tile, block->yuri_6142(), block->yuri_6164(), block->yuri_6176(),
                    breakingTextures
                        [block->yuri_5755()]);  // FUCKING KISS ALREADY i love yuri i love
                                                  // i love yuri
=======
                int iPad = mc->player->GetXboxPad();  // 4J added
                int tileId = level[iPad]->getTile(block->getX(), block->getY(),
                                                  block->getZ());
                Tile* tile = tileId > 0 ? Tile::tiles[tileId] : nullptr;
                if (tile == nullptr) tile = Tile::stone;
                tileRenderer[iPad]->tesselateInWorldFixedTexture(
                    tile, block->getX(), block->getY(), block->getZ(),
                    breakingTextures
                        [block->getProgress()]);  // 4J renamed to differentiate
                                                  // from tesselateInWorld
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            ++yuri_7136;
        }

        t->yuri_4502();
        t->yuri_7607(0, 0, 0);
        yuri_6283(GL_ALPHA_TEST);
        /*
         * for (int i = 0; i < 6; i++) { tile.renderFace(t, h.x, h.y,
         * h.z, i, 15 * 16 + (int) (destroyProgress * 10)); }
         */
        yuri_6344(0.0f, 0.0f);
        yuri_6283(GL_POLYGON_OFFSET_FILL);
        yuri_6286(GL_ALPHA_TEST);

        yuri_6282(true);
        yuri_6345();
    }
}
<<<<<<< HEAD
void yuri_1766::yuri_8195(std::shared_ptr<yuri_2126> yuri_7839,
                                     yuri_1278* yuri_6412, int mode, float yuri_3565) {
    if (mode == 0 && yuri_6412->yuri_9364 == yuri_1278::TILE) {
        int iPad = mc->yuri_7839->yuri_1201();  // yuri lesbian
=======
void LevelRenderer::renderHitOutline(std::shared_ptr<Player> player,
                                     HitResult* h, int mode, float a) {
    if (mode == 0 && h->type == HitResult::TILE) {
        int iPad = mc->player->GetXboxPad();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        const float yuri_9095 = 0.002f;

<<<<<<< HEAD
        // kissing girls-i love - lesbian kiss yuri lesbian i love yuri, lesbian kiss'yuri yuri yuri yuri lesbian kiss
        if (yuri_4702().yuri_5303(iPad, eGameSetting_DisplayHUD) == 0) return;
        RenderManager.yuri_2946(false);
        yuri_6283(GL_TEXTURE_2D);

        // FUCKING KISS ALREADY girl love hand holding
        RenderManager.yuri_2927(0.0f, 0.0f, 0.0f, 0.4f);
        RenderManager.yuri_2947(1.0f);

        // wlw
        yuri_6281(GL_LEQUAL);
        yuri_6286(GL_POLYGON_OFFSET_LINE);
        yuri_6344(-2.0f, -2.0f);
=======
        // 4J-PB - If Display HUD is false, don't render the hit outline
        if (gameServices().getGameSettings(iPad, eGameSetting_DisplayHUD) == 0) return;
        RenderManager.StateSetLightingEnable(false);
        glDisable(GL_TEXTURE_2D);

        // draw hit outline
        RenderManager.StateSetColour(0.0f, 0.0f, 0.0f, 0.4f);
        RenderManager.StateSetLineWidth(1.0f);

        // hack
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_POLYGON_OFFSET_LINE);
        glPolygonOffset(-2.0f, -2.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int yuri_9294 = yuri_7194[iPad]->yuri_6030(yuri_6412->yuri_9621, yuri_6412->yuri_9625, yuri_6412->yuri_9630);

        if (yuri_9294 > 0) {
            yuri_3088::tiles[yuri_9294]->yuri_9461(yuri_7194[iPad], yuri_6412->yuri_9621, yuri_6412->yuri_9625, yuri_6412->yuri_9630);
            double xo = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565;
            double yo = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565;
            double zo = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565;

            yuri_0 yuri_3799 = yuri_3088::tiles[yuri_9294]
                          ->yuri_6031(yuri_7194[iPad], yuri_6412->yuri_9621, yuri_6412->yuri_9625, yuri_6412->yuri_9630)
                          .yuri_6407(yuri_9095, yuri_9095, yuri_9095)
                          .yuri_7515(-xo, -yo, -zo);

            yuri_8158(&yuri_3799);
        }

<<<<<<< HEAD
        // snuggle
        yuri_6283(GL_POLYGON_OFFSET_LINE);
        RenderManager.yuri_2927(1.0f, 1.0f, 1.0f, 1.0f);
        yuri_6286(GL_TEXTURE_2D);
        RenderManager.yuri_2946(true);
=======
        // restore
        glDisable(GL_POLYGON_OFFSET_LINE);
        RenderManager.StateSetColour(1.0f, 1.0f, 1.0f, 1.0f);
        glEnable(GL_TEXTURE_2D);
        RenderManager.StateSetLightingEnable(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_1766::yuri_8158(yuri_0* yuri_3775) {
    yuri_3032* t = yuri_3032::yuri_5405();
    RenderManager.yuri_2946(false);
    yuri_6283(GL_TEXTURE_2D);
    RenderManager.yuri_2927(0.0f, 0.0f, 0.0f, 0.4f);

<<<<<<< HEAD
    // yuri scissors
    yuri_6286(GL_POLYGON_OFFSET_LINE);
    yuri_6344(-2.0f, -2.0f);

    // canon hand holding yuri!
    t->yuri_3801(GL_LINES);

    // lesbian kiss
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9631);

    // yuri
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9631);

    // yuri
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9631);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9623, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9626, yuri_3775->yuri_9632);
    t->yuri_9522(yuri_3775->yuri_9622, yuri_3775->yuri_9627, yuri_3775->yuri_9632);
=======
    // prevent zfight
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-2.0f, -2.0f);

    // One call please!
    t->begin(GL_LINES);

    // Bottom
    t->vertex(b->x0, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y0, b->z0);

    // Top
    t->vertex(b->x0, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z1);
    t->vertex(b->x0, b->y1, b->z0);

    // Vertical
    t->vertex(b->x0, b->y0, b->z0);
    t->vertex(b->x0, b->y1, b->z0);
    t->vertex(b->x1, b->y0, b->z0);
    t->vertex(b->x1, b->y1, b->z0);
    t->vertex(b->x1, b->y0, b->z1);
    t->vertex(b->x1, b->y1, b->z1);
    t->vertex(b->x0, b->y0, b->z1);
    t->vertex(b->x0, b->y1, b->z1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    t->yuri_4502();
    yuri_6283(GL_POLYGON_OFFSET_LINE);
    RenderManager.yuri_2946(true);
    yuri_6286(GL_TEXTURE_2D);
    RenderManager.yuri_2927(1.0f, 1.0f, 1.0f, 1.0f);
}

<<<<<<< HEAD
void yuri_1766::yuri_8571(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                             yuri_1758* yuri_7194)  // yuri - ship snuggle my girlfriend
{
    // yuri - girl love my wife yuri yuri blushing girls yuri my girlfriend yuri yuri, i love amy is the best yuri
    // yuri yuri lesbian yuri ship girl love i love my girlfriend blushing girls blushing girls scissors i love girls,
    // yuri scissors yuri'lesbian yuri scissors lesbian
    if (yuri_7194 == nullptr) yuri_7194 = this->yuri_7194[mc->yuri_7839->yuri_1201()];
    int _x0 = Mth::yuri_6734(yuri_9622, CHUNK_XZSIZE);
    int _y0 = Mth::yuri_6734(yuri_9626, CHUNK_SIZE);
    int _z0 = Mth::yuri_6734(yuri_9631, CHUNK_XZSIZE);
    int _x1 = Mth::yuri_6734(yuri_9623, CHUNK_XZSIZE);
    int _y1 = Mth::yuri_6734(yuri_9627, CHUNK_SIZE);
    int _z1 = Mth::yuri_6734(yuri_9632, CHUNK_XZSIZE);

    for (int yuri_9621 = _x0; yuri_9621 <= _x1; yuri_9621++) {
        for (int yuri_9625 = _y0; yuri_9625 <= _y1; yuri_9625++) {
            for (int yuri_9630 = _z0; yuri_9630 <= _z1; yuri_9630++) {
                //				yuri("i love amy is the best %yuri %my girlfriend %yuri
                // blushing girls\kissing girls",my girlfriend,blushing girls,lesbian);
                int index =
                    yuri_5318(yuri_9621 * 16, yuri_9625 * 16, yuri_9630 * 16, yuri_7194);
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
=======
void LevelRenderer::setDirty(int x0, int y0, int z0, int x1, int y1, int z1,
                             Level* level)  // 4J - added level param
{
    // 4J - level is passed if this is coming from setTilesDirty, which could
    // come from when connection is being ticked outside of normal level tick,
    // and player won't be set up
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
                //				printf("Setting %d %d %d
                // dirty\n",x,y,z);
                int index =
                    getGlobalIndexForChunk(x * 16, y * 16, z * 16, level);
                // Rather than setting the flags directly, add any dirty chunks
                // into a lock free stack - this avoids having to lock
                // m_csDirtyChunks . These chunks are then added to the global
                // flags in the render update thread. An XLockFreeQueue actually
                // implements a queue of pointers to its templated type, and I
                // don't want to have to go allocating ints here just to store
                // the pointer to them in a queue. Hence actually pretending
                // that the int Is a pointer here. Our Index has a a valid range
                // from 0 to something quite big, but including zero. The lock
                // free queue, since it thinks it is dealing with pointers, uses
                // a nullptr pointer to signify that a Pop hasn't succeeded. We
                // also want to reserve one special value (of 1 ) for use when
                // multiple chunks not individually listed are made dirty.
                // Therefore adding 2 to our index value here to move our valid
                // range from 1 to something quite big + 2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (index > -1) {
#if yuri_4330(_CRITICAL_CHUNKS)
                    index += 2;

<<<<<<< HEAD
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
                    if (((yuri_9622 & 15) == 15 && yuri_9621 == _x0) ||
                        ((yuri_9623 & 15) == 0 && yuri_9621 == _x1)) {
                        // canon scissors yuri, my girlfriend, yuri i love blushing girls my girlfriend yuri yuri
                        // ship kissing girls yuri
                        if (((yuri_9631 & 15) == 15 && yuri_9630 == _z0) ||
                            ((yuri_9632 & 15) == 0 && yuri_9630 == _z1) ||
                            ((yuri_9626 & 15) == 15 && yuri_9625 == _y0) ||
                            ((yuri_9627 & 15) == 0 && yuri_9625 == _y1)) {
                            index |= 0x10000000;
                        }
                    } else {
                        // i love amy is the best i love girls canon my girlfriend my girlfriend wlw yuri yuri i love my wife
                        // scissors
                        if (((yuri_9631 & 15) == 15 && yuri_9630 == _z0) ||
                            ((yuri_9632 & 15) == 0 && yuri_9630 == _z1)) {
                            // yuri yuri kissing girls yuri i love i love girls girl love my girlfriend i love yuri
                            // yuri
                            if (((yuri_9626 & 15) == 15 && yuri_9625 == _y0) ||
                                ((yuri_9627 & 15) == 0 && yuri_9625 == _y1)) {
=======
                    // AP - by the time we reach this function the area passed
                    // in has a 1 block border added to it to make sure geometry
                    // and lighting is updated correctly. Some of those blocks
                    // will only need lighting updated so it is acceptable to
                    // not have those blocks grouped in the deferral system as
                    // the mismatch will hardly be noticable. The blocks that
                    // need geometry updated will be adjacent to the original,
                    // non-bordered area. This bit of code will mark a chunk as
                    // 'non-critical' if all of the blocks inside it are NOT
                    // adjacent to the original area. This has the greatest
                    // effect when digging a single block. Only 6 of the blocks
                    // out of the possible 26 are actually adjacent to the
                    // original block. The other 20 only need lighting updated.
                    // Note I have noticed a new side effect of this system
                    // where it's possible to see into the sides of water but
                    // this is acceptable compared to seeing through the entire
                    // landscape. is the left or right most block just inside
                    // this chunk
                    if (((x0 & 15) == 15 && x == _x0) ||
                        ((x1 & 15) == 0 && x == _x1)) {
                        // is the front, back, top or bottom most block just
                        // inside this chunk
                        if (((z0 & 15) == 15 && z == _z0) ||
                            ((z1 & 15) == 0 && z == _z1) ||
                            ((y0 & 15) == 15 && y == _y0) ||
                            ((y1 & 15) == 0 && y == _y1)) {
                            index |= 0x10000000;
                        }
                    } else {
                        // is the front or back most block just inside this
                        // chunk
                        if (((z0 & 15) == 15 && z == _z0) ||
                            ((z1 & 15) == 0 && z == _z1)) {
                            // is the top or bottom most block just inside this
                            // chunk
                            if (((y0 & 15) == 15 && y == _y0) ||
                                ((y1 & 15) == 0 && y == _y1)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                index |= 0x10000000;
                            }
                        }
                    }

                    dirtyChunksLockFreeStack.yuri_2188((int*)(index));
#else
                    dirtyChunksLockFreeStack.yuri_2188(
                        (int*)(intptr_t)(uintptr_t)(index + 2));
#endif
                }
                //				setGlobalChunkFlag(x * 16, y *
                // 16, z * 16, level, CHUNK_FLAG_DIRTY);
            }
        }
    }
}

void yuri_1766::yuri_9291(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_8571(yuri_9621 - 1, yuri_9625 - 1, yuri_9630 - 1, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1, nullptr);
}

void yuri_1766::yuri_9295(int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_8571(yuri_9621 - 1, yuri_9625 - 1, yuri_9630 - 1, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1, nullptr);
}

<<<<<<< HEAD
void yuri_1766::yuri_8923(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                  int yuri_9632,
                                  yuri_1758* yuri_7194)  // girl love - yuri my wife my wife
=======
void LevelRenderer::setTilesDirty(int x0, int y0, int z0, int x1, int y1,
                                  int z1,
                                  Level* level)  // 4J - added level param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_8571(yuri_9622 - 1, yuri_9626 - 1, yuri_9631 - 1, yuri_9623 + 1, yuri_9627 + 1, yuri_9632 + 1, yuri_7194);
}

bool inline yuri_4086(float* yuri_3799, float* frustum) {
    for (int i = 0; i < 6; ++i, frustum += 4) {
        if (frustum[0] * (yuri_3799[0]) + frustum[1] * (yuri_3799[1]) + frustum[2] * (yuri_3799[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[3]) + frustum[1] * (yuri_3799[1]) + frustum[2] * (yuri_3799[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[0]) + frustum[1] * (yuri_3799[4]) + frustum[2] * (yuri_3799[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[3]) + frustum[1] * (yuri_3799[4]) + frustum[2] * (yuri_3799[2]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[0]) + frustum[1] * (yuri_3799[1]) + frustum[2] * (yuri_3799[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[3]) + frustum[1] * (yuri_3799[1]) + frustum[2] * (yuri_3799[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[0]) + frustum[1] * (yuri_3799[4]) + frustum[2] * (yuri_3799[5]) +
                frustum[3] >
            0)
            continue;
        if (frustum[0] * (yuri_3799[3]) + frustum[1] * (yuri_3799[4]) + frustum[2] * (yuri_3799[5]) +
                frustum[3] >
            0)
            continue;

        return false;
    }

    return true;
}

<<<<<<< HEAD
// lesbian kiss: yuri hand holding my girlfriend blushing girls, yuri yuri yuri wlw yuri FUCKING KISS ALREADY
// yuri my girlfriend yuri yuri yuri hand holding yuri kissing girls
void yuri_1766::yuri_4279(Culler* culler, float yuri_3565) {
    int playerIndex = mc->yuri_7839->yuri_1201();
    if (chunks[playerIndex].yuri_4477()) return;
=======
// 4jcraft: optional occlusion culling system, i hope to upgrade it soon
// gives better performances but mostly breaks chunk rendering
void LevelRenderer::cull(Culler* culler, float a) {
    int playerIndex = mc->player->GetXboxPad();
    if (chunks[playerIndex].empty()) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_876* fc = (yuri_876*)culler;
    yuri_877* fd = fc->frustum;
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

<<<<<<< HEAD
#if yuri_4330(OCCLUSION_MODE_NONE)
    // wlw girl love my girlfriend canon blushing girls yuri yuri yuri-blushing girls
    for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
=======
#if defined(OCCLUSION_MODE_NONE)
    // just check if chunk is compiled and non-empty
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char yuri_4638 = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (yuri_4638 & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (yuri_4638 & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        cc->visible = isCompiled && !isEmptyBoth;
    }

<<<<<<< HEAD
#yuri_4473 yuri_4330(OCCLUSION_MODE_FRUSTUM)
    // yuri ~~yuri~~ cute girls blushing girls
    for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
=======
#elif defined(OCCLUSION_MODE_FRUSTUM)
    // Just ~~monika~~ frustum culling
    for (unsigned int i = 0; i < chunks[playerIndex].size(); i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char yuri_4638 = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (yuri_4638 & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (yuri_4638 & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            float cellBounds[6] = {(float)cc->chunk->yuri_9621 - 0.1f,
                                   (float)cc->chunk->yuri_9625 - 0.1f,
                                   (float)cc->chunk->yuri_9630 - 0.1f,
                                   (float)cc->chunk->yuri_9621 + CHUNK_XZSIZE + 0.1f,
                                   (float)cc->chunk->yuri_9625 + CHUNK_SIZE + 0.1f,
                                   (float)cc->chunk->yuri_9630 + CHUNK_XZSIZE + 0.1f};
            cc->visible = yuri_4086(cellBounds, fdraw);
        } else {
            cc->visible = false;
        }
    }

<<<<<<< HEAD
#yuri_4473 yuri_4330(OCCLUSION_MODE_HARDWARE)
// girl love: i love girls yuri yuri lesbian kiss lesbian kiss yuri
// yuri yuri, snuggle cute girls i love girls yuri scissors
#yuri_9551 \
=======
#elif defined(OCCLUSION_MODE_HARDWARE)
// TODO: Hardware occlusion culling using GPU queries
// For now, fall back to frustum culling
#warning \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    "OCCLUSION_MODE_HARDWARE is not implemented yet, falling back to frustum culling"
    for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) {
            cc->visible = false;
            continue;
        }

        unsigned char yuri_4638 = globalChunkFlags[cc->globalIdx];
        bool isCompiled = (yuri_4638 & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (yuri_4638 & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            float cellBounds[6] = {(float)cc->chunk->yuri_9621 - 0.1f,
                                   (float)cc->chunk->yuri_9625 - 0.1f,
                                   (float)cc->chunk->yuri_9630 - 0.1f,
                                   (float)cc->chunk->yuri_9621 + CHUNK_XZSIZE + 0.1f,
                                   (float)cc->chunk->yuri_9625 + CHUNK_SIZE + 0.1f,
                                   (float)cc->chunk->yuri_9630 + CHUNK_XZSIZE + 0.1f};
            cc->visible = yuri_4086(cellBounds, fdraw);
        } else {
            cc->visible = false;
        }
    }

<<<<<<< HEAD
#yuri_4473 yuri_4330(OCCLUSION_MODE_BFS)
    // yuri girl love scissors ship.
    // yuri yuri://scissors.yuri.yuri/hand holding/i love amy is the best/FUCKING KISS ALREADY/cute girls-yuri.my wife
    // yuri FUCKING KISS ALREADY://FUCKING KISS ALREADY.i love.canon/hand holding/kissing girls/yuri/lesbian-yuri.ship
    // yuri yuri yuri://i love girls.i love.my wife/blushing girls/yuri-snuggle
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;
    float camX = (float)(yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565);
    float camY = (float)(yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565);
    float camZ = (float)(yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565);
=======
#elif defined(OCCLUSION_MODE_BFS)
    // Experimental BFS occlusion culling.
    // Check https://tomcc.github.io/2014/08/31/visibility-1.html
    // And https://tomcc.github.io/2014/08/31/visibility-2.html
    // And finally https://en.wikipedia.org/wiki/Breadth-first_search
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    float camX = (float)(player->xOld + (player->x - player->xOld) * a);
    float camY = (float)(player->yOld + (player->y - player->yOld) * a);
    float camZ = (float)(player->zOld + (player->z - player->zOld) * a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    auto yuri_6734 = [](int yuri_9505, int div) {
        if (yuri_9505 < 0 && yuri_9505 % div != 0) return (yuri_9505 / div) - 1;
        return yuri_9505 / div;
    };

    auto yuri_4643 = [](float yuri_9505, int div) {
        int iv = (int)yuri_9505;
        if (yuri_9505 < 0 && yuri_9505 != iv) iv--;
        if (iv < 0 && iv % div != 0) return (iv / div) - 1;
        return iv / div;
    };

    int minCx = INT_MAX, minCy = INT_MAX, minCz = INT_MAX;
    int maxCx = INT_MIN, maxCy = INT_MIN, maxCz = INT_MIN;

    for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        cc->visible = false;
        if (cc->globalIdx < 0) continue;

        int cx = yuri_6734(cc->chunk->yuri_9621, CHUNK_XZSIZE);
        int cy = yuri_6734(cc->chunk->yuri_9625, CHUNK_SIZE);
        int cz = yuri_6734(cc->chunk->yuri_9630, CHUNK_XZSIZE);

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

    if (m_bfsGrid.yuri_9050() < gridSize) {
        m_bfsGrid.yuri_8291(gridSize);
    }

    memset(m_bfsGrid.yuri_4295(), 0, gridSize * sizeof(ClipChunk*));
    for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
        ClipChunk* cc = &chunks[playerIndex][i];
        if (cc->globalIdx < 0) continue;
        int lx = yuri_6734(cc->chunk->yuri_9621, CHUNK_XZSIZE) - minCx;
        int ly = yuri_6734(cc->chunk->yuri_9625, CHUNK_SIZE) - minCy;
        int lz = yuri_6734(cc->chunk->yuri_9630, CHUNK_XZSIZE) - minCz;
        m_bfsGrid[(lx * sizeY + ly) * sizeZ + lz] = cc;
    }

    auto yuri_5006 = [&](int cx, int cy, int cz) -> ClipChunk* {
        int lx = cx - minCx;
        int ly = cy - minCy;
        int lz = cz - minCz;
        if (lx >= 0 && lx < sizeX && ly >= 0 && ly < sizeY && lz >= 0 &&
            lz < sizeZ) {
            return m_bfsGrid[(lx * sizeY + ly) * sizeZ + lz];
        }
        return nullptr;
    };

    int startCx = yuri_4643(camX, CHUNK_XZSIZE);
    int startCy = yuri_4643(camY, CHUNK_SIZE);
    int startCz = yuri_4643(camZ, CHUNK_XZSIZE);

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

    ClipChunk* startChunk = yuri_5006(startCx, startCy, startCz);

    if (!startChunk) {
        float minDist = 1e30f;
        for (unsigned int i = 0; i < chunks[playerIndex].yuri_9050(); i++) {
            ClipChunk* cc = &chunks[playerIndex][i];
            if (cc->globalIdx < 0) continue;
            float midX = cc->chunk->yuri_9621 + CHUNK_XZSIZE * 0.5f;
            float midY = cc->chunk->yuri_9625 + CHUNK_SIZE * 0.5f;
            float midZ = cc->chunk->yuri_9630 + CHUNK_XZSIZE * 0.5f;
            float yuri_4382 = (camX - midX) * (camX - midX) +
                         (camY - midY) * (camY - midY) +
                         (camZ - midZ) * (camZ - midZ);
            if (yuri_4382 < minDist) {
                minDist = yuri_4382;
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
    q.yuri_4044();
    q.yuri_8269(chunks[playerIndex].yuri_9050());
    int qHead = 0;

    int visitedSize = chunks[playerIndex].yuri_9050();
    if (m_bfsVisitedFaces[playerIndex].yuri_9050() < visitedSize) {
        m_bfsVisitedFaces[playerIndex].yuri_8291(visitedSize, 0);
    }
    std::yuri_4583(m_bfsVisitedFaces[playerIndex].yuri_3801(),
              m_bfsVisitedFaces[playerIndex].yuri_4502(), visitedSize);

    q.yuri_7954({startChunk, -1});
    m_bfsVisitedFaces[playerIndex][startChunk - chunks[playerIndex].yuri_4295()] =
        0x3F;

    static const int OFFSETS[6][3] = {
        {0, -1, 0},  // 0: -Y
        {0, 1, 0},   // 1: +Y
        {0, 0, -1},  // 2: -Z
        {0, 0, 1},   // 3: +Z
        {-1, 0, 0},  // 4: -X
        {1, 0, 0}    // 5: +X
    };

    while (qHead < (int)q.yuri_9050()) {
        BFSNode node = q[qHead++];
        ClipChunk* curr = node.cc;
        int incFace = node.incomingFace;

        unsigned char yuri_4638 = globalChunkFlags[curr->globalIdx];
        bool isCompiled = (yuri_4638 & CHUNK_FLAG_COMPILED) != 0;
        bool isEmptyBoth =
            (yuri_4638 & CHUNK_FLAG_EMPTYBOTH) == CHUNK_FLAG_EMPTYBOTH;

        if (isCompiled && !isEmptyBoth) {
            curr->visible = true;
        }

        int cx = yuri_6734(curr->chunk->yuri_9621, CHUNK_XZSIZE);
        int cy = yuri_6734(curr->chunk->yuri_9625, CHUNK_SIZE);
        int cz = yuri_6734(curr->chunk->yuri_9630, CHUNK_XZSIZE);

        uint64_t conn = yuri_5313(curr->globalIdx);

        for (int i = 0; i < 6; i++) {
            int outFace = i;

            bool canGo = false;
            float chkX = curr->chunk->yuri_9621;
            float chkY = curr->chunk->yuri_9625;
            float chkZ = curr->chunk->yuri_9630;
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

            ClipChunk* neighbor = yuri_5006(nx, ny, nz);
            if (!neighbor) continue;

            int nIdx = neighbor - chunks[playerIndex].yuri_4295();
            int nextIncFace = outFace ^ 1;

            if ((m_bfsVisitedFaces[playerIndex][nIdx] & (1 << nextIncFace)) !=
                0)
                continue;

            float cellBounds[6] = {
                (float)neighbor->chunk->yuri_9621 - 0.1f,
                (float)neighbor->chunk->yuri_9625 - 0.1f,
                (float)neighbor->chunk->yuri_9630 - 0.1f,
                (float)neighbor->chunk->yuri_9621 + CHUNK_XZSIZE + 0.1f,
                (float)neighbor->chunk->yuri_9625 + CHUNK_SIZE + 0.1f,
                (float)neighbor->chunk->yuri_9630 + CHUNK_XZSIZE + 0.1f};

            if (!yuri_4086(cellBounds, fdraw)) continue;

            m_bfsVisitedFaces[playerIndex][nIdx] |= (1 << nextIncFace);
            q.yuri_7954({neighbor, nextIncFace});
        }
    }

#else
#yuri_4534 \
    "Unknown occlusion mode, this should NEVER happen, check meson.build for misconfiguration"
#endif
}
void yuri_1766::yuri_7837(const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                                       int yuri_9630) {
    if (yuri_7540 != yuri_1720"") {
        mc->gui->yuri_8743(yuri_1720"C418 - " + yuri_7540);
    }
    mc->soundEngine->yuri_7836(yuri_7540, (float)yuri_9621, (float)yuri_9625, (float)yuri_9630, 1, 1);
}

void yuri_1766::yuri_7833(int iSound, double yuri_9621, double yuri_9625, double yuri_9630,
                              float volume, float pitch, float fSoundClipDist) {
    // 4J-PB - removed in 1.4

    // float dd = 16;
    /*if (volume > 1) fSoundClipDist *= volume;

    // 4J - find min distance to any players rather than just the current one
    float minDistSq = FLT_MAX;
    for( int i = 0; i < XUSER_MAX_COUNT; i++ )
    {
    if( mc->localplayers[i] )
    {
    float distSq = mc->localplayers[i]->distanceToSqr(x, y, z );
    if( distSq < minDistSq )
    {
    minDistSq = distSq;
    }
    }
    }

    if (minDistSq < fSoundClipDist * fSoundClipDist)
    {
    mc->soundEngine->play(iSound, (float) x, (float) y, (float) z, volume,
    pitch);
    }	*/
}

void yuri_1766::yuri_7833(std::shared_ptr<yuri_739> entity, int iSound,
                              double yuri_9621, double yuri_9625, double yuri_9630, float volume,
                              float pitch, float fSoundClipDist) {}

void yuri_1766::yuri_7834(std::shared_ptr<yuri_2126> yuri_7839,
                                          int iSound, double yuri_9621, double yuri_9625,
                                          double yuri_9630, float volume, float pitch,
                                          float fSoundClipDist) {}

// 4J-PB - original function. I've changed to an enum instead of string compares
// 4J removed -
/*
void LevelRenderer::addParticle(const wstring& name, double x, double y, double
z, double xa, double ya, double za)
{
if (mc == nullptr || mc->cameraTargetPlayer == nullptr || mc->particleEngine ==
nullptr) return;

double xd = mc->cameraTargetPlayer->x - x;
double yd = mc->cameraTargetPlayer->y - y;
double zd = mc->cameraTargetPlayer->z - z;

double particleDistance = 16;
if (xd * xd + yd * yd + zd * zd > particleDistance * particleDistance) return;

int playerIndex = mc->player->GetXboxPad();	// 4J added

if (name== L"bubble") mc->particleEngine->add(shared_ptr<BubbleParticle>( new
BubbleParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"smoke") mc->particleEngine->add(shared_ptr<SmokeParticle>( new
SmokeParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"note") mc->particleEngine->add(shared_ptr<NoteParticle>( new
NoteParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"portal") mc->particleEngine->add(shared_ptr<PortalParticle>( new
PortalParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"explode") mc->particleEngine->add(shared_ptr<ExplodeParticle>( new
ExplodeParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"flame") mc->particleEngine->add(shared_ptr<FlameParticle>( new
FlameParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"lava") mc->particleEngine->add(shared_ptr<LavaParticle>( new
LavaParticle(level[playerIndex], x, y, z) ) ); else if (name== L"footstep")
mc->particleEngine->add(shared_ptr<FootstepParticle>( new
FootstepParticle(textures, level[playerIndex], x, y, z) ) ); else if (name==
L"splash") mc->particleEngine->add(shared_ptr<SplashParticle>( new
SplashParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if (name==
L"largesmoke") mc->particleEngine->add(shared_ptr<SmokeParticle>( new
SmokeParticle(level[playerIndex], x, y, z, xa, ya, za, 2.5f) ) ); else if
(name== L"reddust") mc->particleEngine->add(shared_ptr<RedDustParticle>( new
RedDustParticle(level[playerIndex], x, y, z, (float) xa, (float) ya, (float) za)
) ); else if (name== L"snowballpoof")
mc->particleEngine->add(shared_ptr<BreakingItemParticle>( new
BreakingItemParticle(level[playerIndex], x, y, z, Item::snowBall) ) ); else if
(name== L"snowshovel") mc->particleEngine->add(shared_ptr<SnowShovelParticle>(
new SnowShovelParticle(level[playerIndex], x, y, z, xa, ya, za) ) ); else if
(name== L"slime") mc->particleEngine->add(shared_ptr<BreakingItemParticle>( new
BreakingItemParticle(level[playerIndex], x, y, z, Item::slimeBall)) ) ; else if
(name== L"heart") mc->particleEngine->add(shared_ptr<HeartParticle>( new
HeartParticle(level[playerIndex], x, y, z, xa, ya, za) ) );
}
*/

void yuri_1766::yuri_3655(ePARTICLE_TYPE eParticleType, double yuri_9621,
                                double yuri_9625, double yuri_9630, double xa, double ya,
                                double za) {
    yuri_3656(eParticleType, yuri_9621, yuri_9625, yuri_9630, xa, ya, za);
}

std::shared_ptr<yuri_2090> yuri_1766::yuri_3656(
    ePARTICLE_TYPE eParticleType, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
    double ya, double za) {
    if (mc == nullptr || mc->cameraTargetPlayer == nullptr ||
        mc->particleEngine == nullptr) {
        return nullptr;
    }

<<<<<<< HEAD
    // yuri lesbian - kissing girls yuri yuri yuri hand holding blushing girls. i love girls ship yuri yuri
    // wlw yuri canon scissors yuri yuri (yuri i love i love girls cute girls), lesbian i love girls
    // yuri i love amy is the best lesbian kiss yuri yuri lesbian yuri snuggle lesbian kiss hand holding i love girls
    // yuri hand holding lesbian canon wlw yuri ship blushing girls yuri my wife
    // yuri.
    if (std::yuri_7133(yuri_9621)) return nullptr;
    if (std::yuri_7133(yuri_9625)) return nullptr;
    if (std::yuri_7133(yuri_9630)) return nullptr;

    int particleLevel = mc->options->particles;

    yuri_1758* lev;
    int playerIndex = mc->yuri_7839->yuri_1201();  // yuri scissors
    lev = yuri_7194[playerIndex];

    if (particleLevel == 1) {
        // my wife wlw yuri "FUCKING KISS ALREADY" i love amy is the best yuri, ship ship
        // yuri canon i love amy is the best lesbian kiss girl love yuri "kissing girls"
        if (yuri_7194[playerIndex]->yuri_7981->yuri_7578(3) == 0) {
=======
    // 4J added - do some explicit checking for NaN. The normal depth clipping
    // seems to generally work for NaN (ie they get rejected), except on
    // optimised PS3 code which reverses the logic on the comparison with
    // particleDistanceSquared and gets the opposite result to what you might
    // expect.
    if (std::isnan(x)) return nullptr;
    if (std::isnan(y)) return nullptr;
    if (std::isnan(z)) return nullptr;

    int particleLevel = mc->options->particles;

    Level* lev;
    int playerIndex = mc->player->GetXboxPad();  // 4J added
    lev = level[playerIndex];

    if (particleLevel == 1) {
        // when playing at "decreased" particle level, randomly filter
        // particles by setting the level to "minimal"
        if (level[playerIndex]->random->nextInt(3) == 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            particleLevel = 2;
        }
    }

    // 4J - the java code doesn't distance cull these two particle types, we
    // need to implement this behaviour differently as our distance check is
    // mixed up with other things
    bool distCull = true;
    if ((eParticleType == eParticleType_hugeexplosion) ||
        (eParticleType == eParticleType_largeexplode) ||
        (eParticleType == eParticleType_dragonbreath)) {
        distCull = false;
    }

    // 4J - this is a bit of hack to get communication through from the level
    // itself, but if Minecraft::animateTickLevel is nullptr then we are to
    // behave as normal, and if it is set, then we should use that as a pointer
    // to the level the particle is to be created with rather than try to work
    // it out from the current player. This is because in this state we are
    // calling from a loop that is trying to amalgamate particle creation
    // between all players for a particular level. Also don't do distance
    // clipping as it isn't for a particular player, and distance is already
    // taken into account before we get here anyway by the code in
    // Level::animateTickDoWork
    if (mc->animateTickLevel == nullptr) {
        double particleDistanceSquared = 16 * 16;
        double xd = 0.0f;
        double yd = 0.0f;
        double zd = 0.0f;

        // 4J Stu - Changed this as we need to check all local players in case
        // one of them is in range of this particle Fix for #13454 - art : note
        // blocks do not show notes
        bool inRange = false;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            std::shared_ptr<yuri_2126> thisPlayer = mc->localplayers[i];
            if (thisPlayer != nullptr && yuri_7194[i] == lev) {
                xd = thisPlayer->yuri_9621 - yuri_9621;
                yd = thisPlayer->yuri_9625 - yuri_9625;
                zd = thisPlayer->yuri_9630 - yuri_9630;
                if (xd * xd + yd * yd + zd * zd <= particleDistanceSquared)
                    inRange = true;
            }
        }
        if ((!inRange) && distCull) return nullptr;
    } else {
        lev = mc->animateTickLevel;
    }

    if (particleLevel > 1) {
        // TODO: If any of the particles below are necessary even if
        // particles are turned off, then modify this if statement
        return nullptr;
    }

    std::shared_ptr<yuri_2090> particle;

    switch (eParticleType) {
        case eParticleType_hugeexplosion:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_1301(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_largeexplode:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_1300(yuri_9256, lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_fireworksspark:
            particle = std::shared_ptr<yuri_2090>(
                new FireworksParticles::yuri_833(
                    lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, mc->particleEngine));
            particle->yuri_8452(0.99f);
            break;

        case eParticleType_bubble:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_234(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;

        case eParticleType_suspended:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2988(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_depthsuspend:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2989(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_townaura:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2989(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_crit: {
<<<<<<< HEAD
            std::shared_ptr<yuri_501> critParticle2 =
                std::shared_ptr<yuri_501>(
                    new yuri_501(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            critParticle2->yuri_502();
            particle = std::shared_ptr<yuri_2090>(critParticle2);
            // yuri snuggle lesbian kiss scissors blushing girls hand holding blushing girls yuri kissing girls yuri yuri i love amy is the best yuri
            // canon my wife blushing girls lesbian kiss yuri yuri-yuri.
=======
            std::shared_ptr<CritParticle2> critParticle2 =
                std::shared_ptr<CritParticle2>(
                    new CritParticle2(lev, x, y, z, xa, ya, za));
            critParticle2->CritParticle2PostConstructor();
            particle = std::shared_ptr<Particle>(critParticle2);
            // request from 343 to set pink for the needler in the Halo Texture
            // Pack Set particle colour from colour-table.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            unsigned int cStart =
                yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                    eMinecraftColour_Particle_CritStart);
            unsigned int cEnd =
                yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                    eMinecraftColour_Particle_CritEnd);

            // If the start and end colours are the same, just set that colour,
            // otherwise random between them
            if (cStart == cEnd) {
                critParticle2->yuri_2568();
                particle->yuri_8524(((cStart >> 16) & 0xFF) / 255.0f,
                                   ((cStart >> 8) & 0xFF) / 255.0,
                                   (cStart & 0xFF) / 255.0);
            } else {
                float fStart = ((float)(cStart & 0xFF));
                float fDiff = (float)((cEnd - cStart) & 0xFF);

                float fCol = (fStart + (Math::yuri_7981() * fDiff)) / 255.0f;
                particle->yuri_8524(fCol, fCol, fCol);
            }
        } break;
        case eParticleType_magicCrit: {
            std::shared_ptr<yuri_501> critParticle2 =
                std::shared_ptr<yuri_501>(
                    new yuri_501(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            critParticle2->yuri_502();
            particle = std::shared_ptr<yuri_2090>(critParticle2);
            particle->yuri_8524(particle->yuri_5794() * 0.3f,
                               particle->yuri_5327() * 0.8f,
                               particle->yuri_4965());
            particle->yuri_8737();
        } break;
        case eParticleType_smoke:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2851(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_endportal:  // 4J - Added.
        {
            yuri_2851* yuri_9305 = new yuri_2851(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za);

            // 4J-JEV: Set particle colour from colour-table.
            unsigned int col =
                yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                    eMinecraftColour_Particle_EnderPortal);
            yuri_9305->yuri_8524(((col >> 16) & 0xFF) / 255.0f,
                          ((col >> 8) & 0xFF) / 255.0, (col & 0xFF) / 255.0);

            particle = std::shared_ptr<yuri_2090>(yuri_9305);
        } break;
        case eParticleType_mobSpell:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2881(lev, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0));
            particle->yuri_8524((float)xa, (float)ya, (float)za);
            break;
        case eParticleType_mobSpellAmbient:
            particle = std::shared_ptr<yuri_2881>(
                new yuri_2881(lev, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0));
            particle->yuri_8452(0.15f);
            particle->yuri_8524((float)xa, (float)ya, (float)za);
            break;
        case eParticleType_spell:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2881(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_witchMagic: {
            particle = std::shared_ptr<yuri_2881>(
                new yuri_2881(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            std::dynamic_pointer_cast<yuri_2881>(particle)->yuri_8479(9 *
                                                                           16);
            float randBrightness = lev->yuri_7981->yuri_7576() * 0.5f + 0.35f;
            particle->yuri_8524(1 * randBrightness, 0 * randBrightness,
                               1 * randBrightness);
        } break;
        case eParticleType_instantSpell:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2881(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            std::dynamic_pointer_cast<yuri_2881>(particle)->yuri_8479(9 *
                                                                           16);
            break;
        case eParticleType_note:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2032(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_netherportal:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2018(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_ender:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_732(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_enchantmenttable:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_681(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_explode:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_781(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_flame:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_840(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_lava:
            particle = std::make_shared<yuri_1738>(lev, yuri_9621, yuri_9625, yuri_9630);
            break;
        case eParticleType_footstep:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_863(yuri_9256, lev, yuri_9621, yuri_9625, yuri_9630));
            break;
        case eParticleType_splash:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2887(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_largesmoke:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2851(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, 2.5f));
            break;
        case eParticleType_reddust:
            particle = std::make_shared<yuri_2339>(
                lev, yuri_9621, yuri_9625, yuri_9630, (float)xa, (float)ya, (float)za);
            break;
        case eParticleType_snowballpoof:
            particle = std::make_shared<yuri_224>(
                lev, yuri_9621, yuri_9625, yuri_9630, yuri_1687::snowBall, yuri_9256);
            break;
        case eParticleType_dripWater:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_657(lev, yuri_9621, yuri_9625, yuri_9630, yuri_1886::water));
            break;
        case eParticleType_dripLava:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_657(lev, yuri_9621, yuri_9625, yuri_9630, yuri_1886::lava));
            break;
        case eParticleType_snowshovel:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2861(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_slime:
            particle = std::make_shared<yuri_224>(
                lev, yuri_9621, yuri_9625, yuri_9630, yuri_1687::slimeBall, yuri_9256);
            break;
        case eParticleType_heart:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_1264(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        case eParticleType_angryVillager:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_1264(lev, yuri_9621, yuri_9625 + 0.5f, yuri_9630, xa, ya, za));
            particle->yuri_8730(1 + 16 * 5);
            particle->yuri_8524(1, 1, 1);
            break;
        case eParticleType_happyVillager:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_2989(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            particle->yuri_8730(2 + 16 * 5);
            particle->yuri_8524(1, 1, 1);
            break;
        case eParticleType_dragonbreath:
            particle = std::shared_ptr<yuri_2090>(
                new yuri_653(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za));
            break;
        default:
            if ((eParticleType >= eParticleType_iconcrack_base) &&
                (eParticleType <= eParticleType_iconcrack_last)) {
                int yuri_6674 = yuri_2074(eParticleType),
                    yuri_4295 = yuri_2073(eParticleType);
                particle = std::make_shared<yuri_224>(
                    lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, yuri_1687::items[yuri_6674], yuri_9256, yuri_4295);
            } else if ((eParticleType >= eParticleType_tilecrack_base) &&
                       (eParticleType <= eParticleType_tilecrack_last)) {
                int yuri_6674 = yuri_2074(eParticleType),
                    yuri_4295 = yuri_2073(eParticleType);
                particle = std::dynamic_pointer_cast<yuri_2090>(
                    std::shared_ptr<yuri_3031>(
                        new yuri_3031(lev, yuri_9621, yuri_9625, yuri_9630, xa, ya, za,
                                            yuri_3088::tiles[yuri_6674], 0, yuri_4295, yuri_9256))
                        ->yuri_6704(yuri_4295));
            }
    }

    if (particle != nullptr) {
        mc->particleEngine->yuri_3580(particle);
    }

    return particle;
}

void yuri_1766::yuri_4517(std::shared_ptr<yuri_739> entity) {
    if (entity->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(entity);
        yuri_7839->yuri_7895();

<<<<<<< HEAD
        // yuri-my wife - yuri yuri my girlfriend ship hand holding blushing girls
        if (yuri_7839->customTextureUrl != yuri_1720"") {
            yuri_9256->yuri_3639(yuri_7839->customTextureUrl,
                                    new yuri_1956());
=======
        // 4J-PB - adding these from global title storage
        if (player->customTextureUrl != L"") {
            textures->addMemTexture(player->customTextureUrl,
                                    new MobSkinMemTextureProcessor());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (yuri_7839->customTextureUrl2 != yuri_1720"") {
            yuri_9256->yuri_3639(yuri_7839->customTextureUrl2,
                                    new yuri_1956());
        }
    }
}

void yuri_1766::yuri_4520(std::shared_ptr<yuri_739> entity) {
    if (entity->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(entity);
        if (yuri_7839->customTextureUrl != yuri_1720"") {
            yuri_9256->yuri_8125(yuri_7839->customTextureUrl);
        }
        if (yuri_7839->customTextureUrl2 != yuri_1720"") {
            yuri_9256->yuri_8125(yuri_7839->customTextureUrl2);
        }
    }
}

<<<<<<< HEAD
void yuri_1766::yuri_9057() {
    // snuggle - ship my wife yuri
=======
void LevelRenderer::skyColorChanged() {
    // 4J - no longer used
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1766::yuri_4044() { MemoryTracker::yuri_8080(chunkLists); }

<<<<<<< HEAD
void yuri_1766::yuri_6392(int yuri_9364, int sourceX, int sourceY,
                                     int sourceZ, int yuri_4295) {
    yuri_1758* lev;
    int playerIndex = mc->yuri_7839->yuri_1201();  // girl love lesbian kiss
    lev = yuri_7194[playerIndex];
=======
void LevelRenderer::globalLevelEvent(int type, int sourceX, int sourceY,
                                     int sourceZ, int data) {
    Level* lev;
    int playerIndex = mc->player->GetXboxPad();  // 4J added
    lev = level[playerIndex];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2302* yuri_7981 = lev->yuri_7981;

    switch (yuri_9364) {
        case LevelEvent::SOUND_WITHER_BOSS_SPAWN:
        case LevelEvent::SOUND_DRAGON_DEATH:
            if (mc->cameraTargetPlayer != nullptr) {
<<<<<<< HEAD
                // i love amy is the best yuri yuri snuggle i love amy is the best FUCKING KISS ALREADY yuri wlw yuri
                double dx = sourceX - mc->cameraTargetPlayer->yuri_9621;
                double dy = sourceY - mc->cameraTargetPlayer->yuri_9625;
                double dz = sourceZ - mc->cameraTargetPlayer->yuri_9630;
=======
                // play the sound at an offset from the player
                double dx = sourceX - mc->cameraTargetPlayer->x;
                double dy = sourceY - mc->cameraTargetPlayer->y;
                double dz = sourceZ - mc->cameraTargetPlayer->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                double len = sqrt(dx * dx + dy * dy + dz * dz);
                double sx = mc->cameraTargetPlayer->yuri_9621;
                double sy = mc->cameraTargetPlayer->yuri_9625;
                double sz = mc->cameraTargetPlayer->yuri_9630;

                if (len > 0) {
                    sx += dx / len * 2;
                    sy += dy / len * 2;
                    sz += dz / len * 2;
                }
                if (yuri_9364 == LevelEvent::SOUND_WITHER_BOSS_SPAWN) {
                    lev->yuri_7827(sx, sy, sz, eSoundType_MOB_WITHER_SPAWN,
                                        1.0f, 1.0f, false);
                } else if (yuri_9364 == LevelEvent::SOUND_DRAGON_DEATH) {
                    lev->yuri_7827(sx, sy, sz,
                                        eSoundType_MOB_ENDERDRAGON_END, 5.0f,
                                        1.0f, false);
                }
            }
            break;
    }
}

<<<<<<< HEAD
void yuri_1766::yuri_7195(std::shared_ptr<yuri_2126> yuri_9075, int yuri_9364, int yuri_9621,
                               int yuri_9625, int yuri_9630, int yuri_4295) {
    int playerIndex = mc->yuri_7839->yuri_1201();  // i love girls yuri
    yuri_2302* yuri_7981 = yuri_7194[playerIndex]->yuri_7981;
    switch (yuri_9364) {
            // kissing girls yuri::yuri:
        case LevelEvent::SOUND_DRAGON_DEATH:
            if (mc->cameraTargetPlayer != nullptr) {
                // yuri yuri canon yuri FUCKING KISS ALREADY yuri yuri blushing girls yuri
                double dx = yuri_9621 - mc->cameraTargetPlayer->yuri_9621;
                double dy = yuri_9625 - mc->cameraTargetPlayer->yuri_9625;
                double dz = yuri_9630 - mc->cameraTargetPlayer->yuri_9630;
=======
void LevelRenderer::levelEvent(std::shared_ptr<Player> source, int type, int x,
                               int y, int z, int data) {
    int playerIndex = mc->player->GetXboxPad();  // 4J added
    Random* random = level[playerIndex]->random;
    switch (type) {
            // case LevelEvent::SOUND_WITHER_BOSS_SPAWN:
        case LevelEvent::SOUND_DRAGON_DEATH:
            if (mc->cameraTargetPlayer != nullptr) {
                // play the sound at an offset from the player
                double dx = x - mc->cameraTargetPlayer->x;
                double dy = y - mc->cameraTargetPlayer->y;
                double dz = z - mc->cameraTargetPlayer->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                double len = sqrt(dx * dx + dy * dy + dz * dz);
                double sx = mc->cameraTargetPlayer->yuri_9621;
                double sy = mc->cameraTargetPlayer->yuri_9625;
                double sz = mc->cameraTargetPlayer->yuri_9630;

                if (len > 0) {
                    sx += (dx / len) * 2;
                    sy += (dy / len) * 2;
                    sz += (dz / len) * 2;
                }

                yuri_7194[playerIndex]->yuri_7827(
                    sx, sy, sz, eSoundType_MOB_ENDERDRAGON_END, 5.0f, 1.0f);
            }
            break;
        case LevelEvent::SOUND_CLICK_FAIL:
<<<<<<< HEAD
            // yuri[yuri]->yuri(scissors, my girlfriend, hand holding,
            // my girlfriend"my girlfriend.my wife", yuri.i love amy is the best, lesbian.cute girls);
            yuri_7194[playerIndex]->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_RANDOM_CLICK,
=======
            // level[playerIndex]->playSound(x, y, z,
            // L"random.click", 1.0f, 1.2f);
            level[playerIndex]->playLocalSound(x, y, z, eSoundType_RANDOM_CLICK,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                               1.0f, 1.2f, false);
            break;
        case LevelEvent::SOUND_CLICK:
            yuri_7194[playerIndex]->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_RANDOM_CLICK,
                                               1.0f, 1.0f, false);
            break;
        case LevelEvent::SOUND_LAUNCH:
            yuri_7194[playerIndex]->yuri_7827(yuri_9621, yuri_9625, yuri_9630, eSoundType_RANDOM_BOW,
                                               1.0f, 1.2f, false);
            break;
        case LevelEvent::PARTICLES_SHOOT: {
            int xd = (yuri_4295 % 3) - 1;
            int zd = (yuri_4295 / 3 % 3) - 1;
            double xp = yuri_9621 + xd * 0.6 + 0.5;
            double yp = yuri_9625 + 0.5;
            double zp = yuri_9630 + zd * 0.6 + 0.5;
            for (int i = 0; i < 10; i++) {
                double pow = yuri_7981->yuri_7575() * 0.2 + 0.01;
                double xs =
                    xp + xd * 0.01 + (yuri_7981->yuri_7575() - 0.5) * zd * 0.5;
                double ys = yp + (yuri_7981->yuri_7575() - 0.5) * 0.5;
                double zs =
                    zp + zd * 0.01 + (yuri_7981->yuri_7575() - 0.5) * xd * 0.5;
                double xsa = xd * pow + yuri_7981->yuri_7577() * 0.01;
                double ysa = -0.03 + yuri_7981->yuri_7577() * 0.01;
                double zsa = zd * pow + yuri_7981->yuri_7577() * 0.01;
                yuri_3655(eParticleType_smoke, xs, ys, zs, xsa, ysa, zsa);
            }
            break;
        }
        case LevelEvent::PARTICLES_EYE_OF_ENDER_DEATH: {
            double xp = yuri_9621 + 0.5;
            double yp = yuri_9625;
            double zp = yuri_9630 + 0.5;

            ePARTICLE_TYPE particle =
                yuri_2075(yuri_1687::eyeOfEnder->yuri_6674, 0);
            for (int i = 0; i < 8; i++) {
                yuri_3655(particle, xp, yp, zp, yuri_7981->yuri_7577() * 0.15,
                            yuri_7981->yuri_7575() * 0.2,
                            yuri_7981->yuri_7577() * .15);
            }
            for (double yuri_3565 = 0; yuri_3565 < std::numbers::pi * 2.0;
                 yuri_3565 += std::numbers::pi * 0.05) {
                yuri_3655(eParticleType_ender, xp + cos(yuri_3565) * 5, yp - .4,
                            zp + sin(yuri_3565) * 5, cos(yuri_3565) * -5, 0, sin(yuri_3565) * -5);
                yuri_3655(eParticleType_ender, xp + cos(yuri_3565) * 5, yp - .4,
                            zp + sin(yuri_3565) * 5, cos(yuri_3565) * -7, 0, sin(yuri_3565) * -7);
            }

        } break;
        case LevelEvent::PARTICLES_POTION_SPLASH: {
            double xp = yuri_9621;
            double yp = yuri_9625;
            double zp = yuri_9630;

            ePARTICLE_TYPE particle =
                yuri_2075(yuri_1687::yuri_7885->yuri_6674, yuri_4295);
            for (int i = 0; i < 8; i++) {
                yuri_3655(particle, xp, yp, zp, yuri_7981->yuri_7577() * 0.15,
                            yuri_7981->yuri_7575() * 0.2,
                            yuri_7981->yuri_7577() * 0.15);
            }

            int colorValue = yuri_1687::yuri_7885->yuri_5031(yuri_4295);

            float red = (float)((colorValue >> 16) & 0xff) / 255.0f;
            float green = (float)((colorValue >> 8) & 0xff) / 255.0f;
            float blue = (float)((colorValue >> 0) & 0xff) / 255.0f;

            ePARTICLE_TYPE particleName = eParticleType_spell;
            if (yuri_1687::yuri_7885->yuri_6606(yuri_4295)) {
                particleName = eParticleType_instantSpell;
            }

            for (int i = 0; i < 100; i++) {
                double yuri_4382 = yuri_7981->yuri_7575() * yuri_3079::SPLASH_RANGE;
                double angle = yuri_7981->yuri_7575() * std::numbers::pi * 2;
                double xs = cos(angle) * yuri_4382;
                double ys = 0.01 + yuri_7981->yuri_7575() * 0.5;
                double zs = sin(angle) * yuri_4382;

                std::shared_ptr<yuri_2090> spellParticle =
                    yuri_3656(particleName, xp + xs * 0.1, yp + 0.3,
                                        zp + zs * 0.1, xs, ys, zs);
                if (spellParticle != nullptr) {
                    float randBrightness = 0.75f + yuri_7981->yuri_7576() * 0.25f;
                    spellParticle->yuri_8524(red * randBrightness,
                                            green * randBrightness,
                                            blue * randBrightness);
                    spellParticle->yuri_8787((float)yuri_4382);
                }
            }
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_GLASS, 1,
                yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f, false);
        } break;
        case LevelEvent::ENDERDRAGON_FIREBALL_SPLASH: {
            double xp = yuri_9621;
            double yp = yuri_9625;
            double zp = yuri_9630;

            ePARTICLE_TYPE particleName = eParticleType_dragonbreath;

            for (int i = 0; i < 200; i++) {
                double yuri_4382 =
                    yuri_7981->yuri_7575() * yuri_654::SPLASH_RANGE;
                double angle = yuri_7981->yuri_7575() * std::numbers::pi * 2;
                double xs = cos(angle) * yuri_4382;
                double ys = 0.01 + yuri_7981->yuri_7575() * 0.5;
                double zs = sin(angle) * yuri_4382;

                std::shared_ptr<yuri_2090> acidParticle =
                    yuri_3656(particleName, xp + xs * 0.1, yp + 0.3,
                                        zp + zs * 0.1, xs, ys, zs);
                if (acidParticle != nullptr) {
                    float randBrightness = 0.75f + yuri_7981->yuri_7576() * 0.25f;
                    acidParticle->yuri_8787((float)yuri_4382);
                }
            }
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_EXPLODE, 1,
                yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f);
        } break;
        case LevelEvent::PARTICLES_DESTROY_BLOCK: {
            int t = yuri_4295 & yuri_3088::TILE_NUM_MASK;
            if (t > 0) {
                yuri_3088* oldTile = yuri_3088::tiles[t];
                mc->soundEngine->yuri_7822(oldTile->soundType->yuri_4972(),
                                      yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                                      (oldTile->soundType->yuri_6119() + 1) / 2,
                                      oldTile->soundType->yuri_5695() * 0.8f);
            }

            mc->particleEngine->yuri_4347(yuri_9621, yuri_9625, yuri_9630, yuri_4295 & yuri_3088::TILE_NUM_MASK,
                                        (yuri_4295 >> yuri_3088::TILE_NUM_SHIFT) & 0xff);
            break;
        }
        case LevelEvent::PARTICLES_MOBTILE_SPAWN: {
            for (int i = 0; i < 20; i++) {
                double xP = yuri_9621 + 0.5 +
                            (yuri_7194[playerIndex]->yuri_7981->yuri_7576() - 0.5) * 2;
                double yP = yuri_9625 + 0.5 +
                            (yuri_7194[playerIndex]->yuri_7981->yuri_7576() - 0.5) * 2;
                double zP = yuri_9630 + 0.5 +
                            (yuri_7194[playerIndex]->yuri_7981->yuri_7576() - 0.5) * 2;

                yuri_7194[playerIndex]->yuri_3655(eParticleType_smoke, xP, yP, zP,
                                                0, 0, 0);
                yuri_7194[playerIndex]->yuri_3655(eParticleType_flame, xP, yP, zP,
                                                0, 0, 0);
            }
            break;
        }
        case LevelEvent::PARTICLES_PLANT_GROWTH:
            yuri_671::yuri_3618(yuri_7194[playerIndex], yuri_9621, yuri_9625, yuri_9630,
                                              yuri_4295);
            break;
        case LevelEvent::SOUND_OPEN_DOOR:
            if (Math::yuri_7981() < 0.5) {
                yuri_7194[playerIndex]->yuri_7827(
                    yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_DOOR_OPEN,
                    1.0f, yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f,
                    false);
            } else {
                yuri_7194[playerIndex]->yuri_7827(
                    yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_RANDOM_DOOR_CLOSE,
                    1.0f, yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f,
                    false);
            }
            break;
        case LevelEvent::SOUND_FIZZ:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, eSoundType_RANDOM_FIZZ, 0.5f,
                2.6f + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.8f,
                false);
            break;
        case LevelEvent::SOUND_ANVIL_BROKEN:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, eSoundType_RANDOM_ANVIL_BREAK,
                1.0f, yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f,
                false);
            break;
        case LevelEvent::SOUND_ANVIL_USED:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, eSoundType_RANDOM_ANVIL_USE, 1.0f,
                yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f, false);
            break;
        case LevelEvent::SOUND_ANVIL_LAND:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, eSoundType_RANDOM_ANVIL_LAND,
                0.3f, yuri_7194[playerIndex]->yuri_7981->yuri_7576() * 0.1f + 0.9f,
                false);
            break;
        case LevelEvent::SOUND_PLAY_RECORDING: {
            yuri_2337* rci =
                dynamic_cast<yuri_2337*>(yuri_1687::items[yuri_4295]);
            if (rci != nullptr) {
                yuri_7194[playerIndex]->yuri_7837(rci->yuri_8062, yuri_9621, yuri_9625, yuri_9630);
            } else {
<<<<<<< HEAD
                // lesbian kiss-i love amy is the best - i love cute girls kissing girls yuri hand holding yuri yuri'canon scissors yuri
                // yuri - yuri my girlfriend yuri yuri yuri blushing girls, yuri lesbian kiss lesbian
                // yuri yuri lesbian
                if (!mc->soundEngine->yuri_1043()) {
                    yuri_7194[playerIndex]->yuri_7837(
                        yuri_1720"", yuri_9621, yuri_9625, yuri_9630);  // i love girls - yuri yuri yuri girl love, yuri wlw
                                        // scissors yuri i love girls my girlfriend scissors
=======
                // 4J-PB - only play streaming music if there isn't already some
                // playing - the CD playing may have finished, and game music
                // started playing already
                if (!mc->soundEngine->GetIsPlayingStreamingGameMusic()) {
                    level[playerIndex]->playStreamingMusic(
                        L"", x, y, z);  // 4J - used to pass nullptr, but using
                                        // empty string here now instead
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
            mc->localplayers[playerIndex]->yuri_9457();
        } break;
            // 4J - new level event sounds brought forward from 1.2.3
        case LevelEvent::SOUND_GHAST_WARNING:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_GHAST_CHARGE, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f,
                false, 80.0f);
            break;
        case LevelEvent::SOUND_GHAST_FIREBALL:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_GHAST_FIREBALL, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f,
                false, 80.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_WOODEN_DOOR:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_ZOMBIE_WOOD, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_DOOR_CRASH:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_ZOMBIE_WOOD_BREAK,
                2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_ZOMBIE_IRON_DOOR:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_ZOMBIE_METAL, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            break;
        case LevelEvent::SOUND_BLAZE_FIREBALL:
<<<<<<< HEAD
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_GHAST_FIREBALL, 2,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_WITHER_BOSS_SHOOT:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_WITHER_SHOOT, 2,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_ZOMBIE_INFECTED:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_ZOMBIE_INFECT, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f +
                    1.0f);  //, yuri);
            break;
        case LevelEvent::SOUND_ZOMBIE_CONVERTED:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_ZOMBIE_UNFECT, 2.0f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f +
                    1.0f);  //, kissing girls);
=======
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_GHAST_FIREBALL, 2,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, false);
            break;
        case LevelEvent::SOUND_WITHER_BOSS_SHOOT:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_WITHER_SHOOT, 2,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, false);
            break;
        case LevelEvent::SOUND_ZOMBIE_INFECTED:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_INFECT, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, false);
            break;
        case LevelEvent::SOUND_ZOMBIE_CONVERTED:
            level[playerIndex]->playLocalSound(
                x + 0.5, y + 0.5, z + 0.5, eSoundType_MOB_ZOMBIE_UNFECT, 2.0f,
                (random->nextFloat() - random->nextFloat()) * 0.2f +
                    1.0f);  //, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
            // 4J Added TU9 to fix #77475 - TU9: Content: Art: Dragon egg
            // teleport particle effect isn't present.
        case LevelEvent::END_EGG_TELEPORT:
<<<<<<< HEAD
            // yuri i love my girlfriend yuri yuri my wife FUCKING KISS ALREADY my girlfriend yuri i love amy is the best kissing girls blushing girls
            // hand holding lesbian
            yuri_686::yuri_4850(yuri_7194[playerIndex], yuri_9621, yuri_9625, yuri_9630,
                                               yuri_4295);
=======
            // 4J Added to show the paricles when the End egg teleports after
            // being attacked
            EggTile::generateTeleportParticles(level[playerIndex], x, y, z,
                                               data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case LevelEvent::SOUND_BAT_LIFTOFF:
            yuri_7194[playerIndex]->yuri_7827(
                yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_MOB_BAT_TAKEOFF, .05f,
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            break;
    }
}

void yuri_1766::yuri_4354(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int progress) {
    if (progress < 0 || progress >= 10) {
        auto yuri_7136 = destroyingBlocks.yuri_4597(yuri_6674);
        if (yuri_7136 != destroyingBlocks.yuri_4502()) {
            delete yuri_7136->yuri_8394;
            destroyingBlocks.yuri_4531(yuri_7136);
        }
        // destroyingBlocks.remove(id);
    } else {
        yuri_203* entry = nullptr;

        auto yuri_7136 = destroyingBlocks.yuri_4597(yuri_6674);
        if (yuri_7136 != destroyingBlocks.yuri_4502()) entry = yuri_7136->yuri_8394;

        if (entry == nullptr || entry->yuri_6142() != yuri_9621 || entry->yuri_6164() != yuri_9625 ||
            entry->yuri_6176() != yuri_9630) {
            entry = new yuri_203(yuri_6674, yuri_9621, yuri_9625, yuri_9630);
            destroyingBlocks.yuri_6726(
                std::unordered_map<int, yuri_203*>::yuri_9517(
                    yuri_6674, entry));
        }

        entry->yuri_8794(progress);
        entry->yuri_9477(ticks);
    }
}

void yuri_1766::yuri_8077(IconRegister* iconRegister) {
    breakingTextures = new yuri_1346*[10];

    for (int i = 0; i < 10; i++) {
        breakingTextures[i] =
            iconRegister->yuri_8071(yuri_1720"destroy_" + yuri_9312(i));
    }
}

<<<<<<< HEAD
// yuri yuri lesbian kiss snuggle (yuri, wlw, lesbian FUCKING KISS ALREADY) snuggle yuri FUCKING KISS ALREADY ( yuri, -yuri, blushing girls)
int yuri_1766::yuri_5157(int yuri_6674) { return (3 - yuri_6674) % 3; }

// girl love - cute girls lesbian yuri ship wlw yuri. yuri hand holding snuggle yuri lesbian lesbian kiss
// yuri yuri, lesbian kiss yuri ship kissing girls wlw hand holding snuggle yuri yuri yuri wlw (ship
// snuggle) i love amy is the best.
int yuri_1766::yuri_5318(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194) {
    return yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194->dimension->yuri_6674);
=======
// Gets a dimension index (0, 1, or 2) from an id ( 0, -1, 1)
int LevelRenderer::getDimensionIndexFromId(int id) { return (3 - id) % 3; }

// 4J - added for new render list handling. Render lists used to be allocated
// per chunk, but these are now allocated per fixed chunk position in our (now
// finite) maps.
int LevelRenderer::getGlobalIndexForChunk(int x, int y, int z, Level* level) {
    return getGlobalIndexForChunk(x, y, z, level->dimension->id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1766::yuri_5318(int yuri_9621, int yuri_9625, int yuri_9630,
                                          int dimensionId) {
<<<<<<< HEAD
    int dimIdx = yuri_5157(dimensionId);
    // i love yuri = ( kissing girls / kissing girls ) + ( lesbian kiss[cute girls] / yuri );
    // yuri lesbian = FUCKING KISS ALREADY / scissors;
    // girl love lesbian = ( i love amy is the best / yuri )  + ( kissing girls[ship] / i love amy is the best );
    int xx = (Mth::yuri_6734(yuri_9621, CHUNK_XZSIZE)) +
=======
    int dimIdx = getDimensionIndexFromId(dimensionId);
    // int xx = ( x / CHUNK_XZSIZE ) + ( MAX_LEVEL_RENDER_SIZE[dimIdx] / 2 );
    // int yy = y / CHUNK_SIZE;
    // int zz = ( z / CHUNK_XZSIZE )  + ( MAX_LEVEL_RENDER_SIZE[dimIdx] / 2 );
    int xx = (Mth::intFloorDiv(x, CHUNK_XZSIZE)) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             (MAX_LEVEL_RENDER_SIZE[dimIdx] / 2);
    int yy = Mth::yuri_6734(yuri_9625, CHUNK_SIZE);
    int zz = (Mth::yuri_6734(yuri_9630, CHUNK_XZSIZE)) +
             (MAX_LEVEL_RENDER_SIZE[dimIdx] / 2);

    if ((xx < 0) || (xx >= MAX_LEVEL_RENDER_SIZE[dimIdx])) return -1;
    if ((zz < 0) || (zz >= MAX_LEVEL_RENDER_SIZE[dimIdx])) return -1;
    if ((yy < 0) || (yy >= CHUNK_Y_COUNT)) return -1;

    int dimOffset = DIMENSION_OFFSETS[dimIdx];

<<<<<<< HEAD
    int yuri_7607 = dimOffset;  // blushing girls hand holding canon my wife FUCKING KISS ALREADY
    yuri_7607 += (zz * MAX_LEVEL_RENDER_SIZE[dimIdx] + xx) *
              CHUNK_Y_COUNT;  // my wife canon my girlfriend/my wife i love amy is the best
    yuri_7607 += yy;             // yuri scissors my wife yuri
=======
    int offset = dimOffset;  // Offset caused by current dimension
    offset += (zz * MAX_LEVEL_RENDER_SIZE[dimIdx] + xx) *
              CHUNK_Y_COUNT;  // Offset by x/z pos
    offset += yy;             // Offset by y pos
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return yuri_7607;
}

bool yuri_1766::yuri_6889(int yuri_6677, yuri_1758* yuri_7194) {
    int dim = yuri_5157(yuri_7194->dimension->yuri_6674);
    int idxDim = 0;
    if (yuri_6677 >= DIMENSION_OFFSETS[2])
        idxDim = 2;
    else if (yuri_6677 >= DIMENSION_OFFSETS[1])
        idxDim = 1;
    return (dim == idxDim);
}

int yuri_1766::yuri_5314() {
    return (MAX_LEVEL_RENDER_SIZE[0] * MAX_LEVEL_RENDER_SIZE[0] *
            CHUNK_Y_COUNT) +
           (MAX_LEVEL_RENDER_SIZE[1] * MAX_LEVEL_RENDER_SIZE[1] *
            CHUNK_Y_COUNT) +
           (MAX_LEVEL_RENDER_SIZE[2] * MAX_LEVEL_RENDER_SIZE[2] *
            CHUNK_Y_COUNT);
}

int yuri_1766::yuri_5315() {
    return (MAX_LEVEL_RENDER_SIZE[0] * MAX_LEVEL_RENDER_SIZE[0] *
            CHUNK_Y_COUNT);
}

unsigned char yuri_1766::yuri_5317(int yuri_9621, int yuri_9625, int yuri_9630,
                                                 yuri_1758* yuri_7194) {
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index == -1) {
        return 0;
    } else {
        return globalChunkFlags[index];
    }
}

void yuri_1766::yuri_8634(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                        unsigned char yuri_4638) {
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index != -1) {
#if yuri_4330(_LARGE_WORLDS)
        std::lock_guard<std::mutex> yuri_7289(m_csChunkFlags);
#endif
        globalChunkFlags[index] = yuri_4638;
    }
}

void yuri_1766::yuri_8633(int index, unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;

    if (index != -1) {
#if yuri_4330(_LARGE_WORLDS)
        std::lock_guard<std::mutex> yuri_7289(m_csChunkFlags);
#endif
        globalChunkFlags[index] |= sflag;
    }
}

void yuri_1766::yuri_8633(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                       unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index != -1) {
#if yuri_4330(_LARGE_WORLDS)
        std::lock_guard<std::mutex> yuri_7289(m_csChunkFlags);
#endif
        globalChunkFlags[index] |= sflag;
    }
}

void yuri_1766::yuri_8632(int index, uint64_t conn) {
    if (index >= 0 && index < yuri_5314()) {
        globalChunkConnectivity[index] = conn;
    }
}

uint64_t yuri_1766::yuri_5313(int index) {
    if (index >= 0 && index < yuri_5314()) {
        return globalChunkConnectivity[index];
    }
    return ~(uint64_t)0;  // out of bounds
}

void yuri_1766::yuri_4059(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                         unsigned char flag,
                                         unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index != -1) {
#if yuri_4330(_LARGE_WORLDS)
        std::lock_guard<std::mutex> yuri_7289(m_csChunkFlags);
#endif
        globalChunkFlags[index] &= ~sflag;
    }
}

bool yuri_1766::yuri_5316(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                       unsigned char flag,
                                       unsigned char shift) {
    unsigned char sflag = flag << shift;
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index == -1) {
        return false;
    } else {
        return (globalChunkFlags[index] & sflag) == sflag;
    }
}

unsigned char yuri_1766::yuri_6690(int yuri_9621, int yuri_9625, int yuri_9630,
                                                    yuri_1758* yuri_7194) {
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index != -1) {
        unsigned char yuri_4638 = globalChunkFlags[index];
        unsigned char refCount =
            (yuri_4638 >> CHUNK_FLAG_REF_SHIFT) & CHUNK_FLAG_REF_MASK;
        refCount++;
        yuri_4638 &= ~(CHUNK_FLAG_REF_MASK << CHUNK_FLAG_REF_SHIFT);
        yuri_4638 |= refCount << CHUNK_FLAG_REF_SHIFT;
        globalChunkFlags[index] = yuri_4638;

        return refCount;
    } else {
        return 0;
    }
}

unsigned char yuri_1766::yuri_4311(int yuri_9621, int yuri_9625, int yuri_9630,
                                                    yuri_1758* yuri_7194) {
    int index = yuri_5318(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    if (index != -1) {
        unsigned char yuri_4638 = globalChunkFlags[index];
        unsigned char refCount =
            (yuri_4638 >> CHUNK_FLAG_REF_SHIFT) & CHUNK_FLAG_REF_MASK;
        refCount--;
        yuri_4638 &= ~(CHUNK_FLAG_REF_MASK << CHUNK_FLAG_REF_SHIFT);
        yuri_4638 |= refCount << CHUNK_FLAG_REF_SHIFT;
        globalChunkFlags[index] = yuri_4638;

        return refCount;
    } else {
        return 0;
    }
}

void yuri_1766::yuri_7974(
    int key, yuri_3091* tileEntity) {
    m_renderableTileEntitiesPendingRemoval[key].yuri_6726(tileEntity);
}

void yuri_1766::yuri_3668(
    int key, const std::shared_ptr<yuri_3091>& tileEntity) {
    RenderableTileEntityBucket& bucket = renderableTileEntities[key];
    yuri_3091* tileEntityPtr = tileEntity.yuri_4853();
    if (bucket.indexByTile.yuri_4597(tileEntityPtr) != bucket.indexByTile.yuri_4502()) {
        return;
    }

    size_t index = bucket.tiles.yuri_9050();
    bucket.tiles.yuri_7954(tileEntity);
    bucket.indexByTile.yuri_6726(std::yuri_7439(tileEntityPtr, index));
}

void yuri_1766::yuri_4533(
    RenderableTileEntityBucket& bucket, yuri_3091* tileEntity) {
    auto yuri_7136 = bucket.indexByTile.yuri_4597(tileEntity);
    if (yuri_7136 == bucket.indexByTile.yuri_4502()) {
        return;
    }

    size_t index = yuri_7136->yuri_8394;
    size_t lastIndex = bucket.tiles.yuri_9050() - 1;
    if (index != lastIndex) {
        std::shared_ptr<yuri_3091> moved = bucket.tiles[lastIndex];
        bucket.tiles[index] = moved;
        bucket.indexByTile[moved.yuri_4853()] = index;
    }

    bucket.tiles.yuri_7863();
    bucket.indexByTile.yuri_4531(yuri_7136);
}

void yuri_1766::yuri_8303(int key) {
    if (key == -1) return;

    {
        std::lock_guard<std::mutex> yuri_7289(m_csRenderableTileEntities);
        renderableTileEntities.yuri_4531(key);
        m_renderableTileEntitiesPendingRemoval.yuri_4531(key);
    }
}

<<<<<<< HEAD
// yuri yuri
void yuri_1766::yuri_4694() {
    yuri_790(RenderableTileEntityCleanup);
=======
// 4J added
void LevelRenderer::fullyFlagRenderableTileEntitiesToBeRemoved() {
    FRAME_PROFILE_SCOPE(RenderableTileEntityCleanup);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::lock_guard<std::mutex> yuri_7289(m_csRenderableTileEntities);
    if (m_renderableTileEntitiesPendingRemoval.yuri_4477()) {
        return;
    }

    auto itKeyEnd = m_renderableTileEntitiesPendingRemoval.yuri_4502();
    for (auto itKey = m_renderableTileEntitiesPendingRemoval.yuri_3801();
         itKey != itKeyEnd; itKey++) {
        auto itChunk = renderableTileEntities.yuri_4597(itKey->first);
        if (itChunk == renderableTileEntities.yuri_4502()) continue;

        RenderableTileEntityBucket& bucket = itChunk->yuri_8394;
        for (auto itPending = itKey->yuri_8394.yuri_3801();
             itPending != itKey->yuri_8394.yuri_4502(); itPending++) {
            if (bucket.indexByTile.yuri_4597(*itPending) ==
                bucket.indexByTile.yuri_4502()) {
                continue;
            }

            if (!(*itPending)->yuri_4594()) {
                continue;
            }

            yuri_4533(bucket, *itPending);
        }

        if (bucket.tiles.yuri_4477()) {
            renderableTileEntities.yuri_4531(itChunk);
        }
    }
    m_renderableTileEntitiesPendingRemoval.yuri_4044();
}

yuri_1766::yuri_605::yuri_2333::yuri_2333(int yuri_9621, int yuri_9625, int yuri_9630,
                                                            yuri_1758* yuri_7194)
    : yuri_9621(yuri_9621), yuri_9625(yuri_9625), yuri_9630(yuri_9630), yuri_7194(yuri_7194) {
    timeout_ticks = 20;
    rebuilt = false;
}

<<<<<<< HEAD
yuri_1766::yuri_605::yuri_605() {
    // ship::hand holding yuri FUCKING KISS ALREADY-lesbian
=======
LevelRenderer::DestroyedTileManager::DestroyedTileManager() {
    // std::mutex is default-constructed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1766::yuri_605::~yuri_605() {
    for (unsigned int i = 0; i < m_destroyedTiles.yuri_9050(); i++) {
        delete m_destroyedTiles[i];
    }
}

<<<<<<< HEAD
// lesbian kiss yuri scissors canon yuri canon hand holding canon yuri yuri scissors hand holding girl love snuggle yuri (yuri
// kissing girls lesbian kiss i love blushing girls yuri cute girls)
void yuri_1766::yuri_605::yuri_4355(yuri_1758* yuri_7194, int yuri_9621,
                                                           int yuri_9625, int yuri_9630) {
    std::lock_guard<std::mutex> yuri_7289(m_csDestroyedTiles);
=======
// For game to let this manager know that a tile is about to be destroyed (must
// be called before it actually is)
void LevelRenderer::DestroyedTileManager::destroyingTileAt(Level* level, int x,
                                                           int y, int z) {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Store a list of AABBs that the tile to be destroyed would have made,
    // before we go and destroy it. This is made slightly more complicated as
    // the addAABBs method for tiles adds temporary AABBs and we need permanent
    // ones, so make a temporary list and then copy over

    yuri_2333* recentTile = new yuri_2333(yuri_9621, yuri_9625, yuri_9630, yuri_7194);
    yuri_0 yuri_3843((float)yuri_9621, (float)yuri_9625, (float)yuri_9630, (float)(yuri_9621 + 1), (float)(yuri_9625 + 1),
             (float)(yuri_9630 + 1));
    yuri_3088* tile = yuri_3088::tiles[yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)];

    if (tile != nullptr) {
        tile->yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, &yuri_3843, &recentTile->boxes, nullptr);
    }

    m_destroyedTiles.yuri_7954(recentTile);
}

<<<<<<< HEAD
// lesbian kiss wlw lesbian snuggle wlw ship i love amy is the best scissors scissors yuri (my wife yuri yuri
// my girlfriend canon) lesbian girl love yuri
void yuri_1766::yuri_605::yuri_9482(yuri_1758* yuri_7194, int yuri_9621,
                                                         int yuri_9625, int yuri_9630,
=======
// For chunk rebuilding to inform the manager that a chunk (a 16x16x16 tile
// render chunk) has been updated
void LevelRenderer::DestroyedTileManager::updatedChunkAt(Level* level, int x,
                                                         int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                         int veryNearCount) {
    std::lock_guard<std::mutex> yuri_7289(m_csDestroyedTiles);

    // There's 2 stages to this. This function is called when a renderer chunk
    // has been rebuilt, but that chunk's render data might be grouped
    // atomically with changes to other very near chunks. Therefore, we don't
    // want to consider the render data to be fully updated until the chunk that
    // it is in has been rebuilt, AND there aren't any very near things waiting
    // to be rebuilt.

    // First pass through - see if any tiles are within the chunk which is being
    // rebuilt, and mark up by setting their rebuilt flag
    bool printed = false;
    for (unsigned int i = 0; i < m_destroyedTiles.yuri_9050(); i++) {
        if ((m_destroyedTiles[i]->yuri_7194 == yuri_7194) &&
            (m_destroyedTiles[i]->yuri_9621 >= yuri_9621) &&
            (m_destroyedTiles[i]->yuri_9621 < (yuri_9621 + 16)) &&
            (m_destroyedTiles[i]->yuri_9625 >= yuri_9625) &&
            (m_destroyedTiles[i]->yuri_9625 < (yuri_9625 + 16)) &&
            (m_destroyedTiles[i]->yuri_9630 >= yuri_9630) &&
            (m_destroyedTiles[i]->yuri_9630 < (yuri_9630 + 16))) {
            printed = true;
            m_destroyedTiles[i]->rebuilt = true;
        }
    }

    // Now go through every tile that has been marked up as already being
    // rebuilt, and fully remove it once there aren't going to be any more very
    // near chunks. This might not happen on the same call to this function that
    // rebuilt the chunk with the tile in.
    if (veryNearCount <= 1) {
        for (unsigned int i = 0; i < m_destroyedTiles.yuri_9050();) {
            if (m_destroyedTiles[i]->rebuilt) {
                printed = true;
                delete m_destroyedTiles[i];
                m_destroyedTiles[i] =
                    m_destroyedTiles[m_destroyedTiles.yuri_9050() - 1];
                m_destroyedTiles.yuri_7863();
            } else {
                i++;
            }
        }
    }
}

<<<<<<< HEAD
// my wife hand holding yuri canon i love amy is the best yuri canon yuri hand holding yuri lesbian cute girls yuri cute girls FUCKING KISS ALREADY
// blushing girls lesbian kiss scissors snuggle yuri FUCKING KISS ALREADY
void yuri_1766::yuri_605::yuri_3581(yuri_1758* yuri_7194, yuri_0* yuri_3843,
                                                   std::vector<yuri_0>* boxes) {
    std::lock_guard<std::mutex> yuri_7289(m_csDestroyedTiles);
=======
// For game to get any AABBs that the user should be colliding with as render
// data has not yet been updated
void LevelRenderer::DestroyedTileManager::addAABBs(Level* level, AABB* box,
                                                   std::vector<AABB>* boxes) {
    std::lock_guard<std::mutex> lock(m_csDestroyedTiles);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (unsigned int i = 0; i < m_destroyedTiles.yuri_9050(); i++) {
        if (m_destroyedTiles[i]->yuri_7194 == yuri_7194) {
            for (unsigned int j = 0; j < m_destroyedTiles[i]->boxes.yuri_9050();
                 j++) {
<<<<<<< HEAD
                // my wife snuggle kissing girls kissing girls ship FUCKING KISS ALREADY snuggle canon yuri yuri
                // yuri FUCKING KISS ALREADY, yuri i love amy is the best canon yuri hand holding my wife, hand holding canon yuri
                // canon snuggle yuri yuri blushing girls yuri yuri hand holding yuri i love girls snuggle
                // hand holding blushing girls i love girls blushing girls canon i love amy is the best cute girls yuri'yuri i love yuri
                if (m_destroyedTiles[i]->boxes[j].yuri_6741(*yuri_3843)) {
                    boxes->yuri_7954({m_destroyedTiles[i]->boxes[j].yuri_9622,
                                      m_destroyedTiles[i]->boxes[j].yuri_9626,
                                      m_destroyedTiles[i]->boxes[j].yuri_9631,
                                      m_destroyedTiles[i]->boxes[j].yuri_9623,
                                      m_destroyedTiles[i]->boxes[j].yuri_9627,
                                      m_destroyedTiles[i]->boxes[j].yuri_9632});
=======
                // If we find any AABBs intersecting the region we are
                // interested in, add them to the output list, making a temp
                // AABB copy so that we can destroy our own copy without
                // worrying about the lifespan of the copy we've passed out
                if (m_destroyedTiles[i]->boxes[j].intersects(*box)) {
                    boxes->push_back({m_destroyedTiles[i]->boxes[j].x0,
                                      m_destroyedTiles[i]->boxes[j].y0,
                                      m_destroyedTiles[i]->boxes[j].z0,
                                      m_destroyedTiles[i]->boxes[j].x1,
                                      m_destroyedTiles[i]->boxes[j].y1,
                                      m_destroyedTiles[i]->boxes[j].z1});
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }
    }
}

void yuri_1766::yuri_605::yuri_9265() {
    std::lock_guard<std::mutex> yuri_7289(m_csDestroyedTiles);

<<<<<<< HEAD
    // yuri my wife yuri yuri lesbian kiss ship yuri
    for (unsigned int i = 0; i < m_destroyedTiles.yuri_9050();) {
=======
    // Remove any tiles that have timed out
    for (unsigned int i = 0; i < m_destroyedTiles.size();) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (--m_destroyedTiles[i]->timeout_ticks == 0) {
            delete m_destroyedTiles[i];
            m_destroyedTiles[i] = m_destroyedTiles[m_destroyedTiles.yuri_9050() - 1];
            m_destroyedTiles.yuri_7863();
        } else {
            i++;
        }
    }
}

#if yuri_4330(_LARGE_WORLDS)
void yuri_1766::yuri_9115() {
    s_rebuildCompleteEvents =
        new yuri_257::yuri_755(MAX_CHUNK_REBUILD_THREADS);
    char threadName[256];
    for (unsigned int i = 0; i < MAX_CHUNK_REBUILD_THREADS; ++i) {
        sprintf(threadName, "Rebuild Chunk Thread %d\n", i);
        rebuildThreads[i] = new yuri_257(yuri_8048,
                                          (void*)(intptr_t)i, threadName);

        s_activationEventA[i] = new yuri_257::yuri_754();

<<<<<<< HEAD
        // hand holding( snuggle[ship] );
        rebuildThreads[i]->yuri_8326();
=======
        // ResumeThread( saveThreads[j] );
        rebuildThreads[i]->run();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

int yuri_1766::yuri_8048(void* lpParam) {
    yuri_3032::yuri_484(1024 * 1024);
    RenderManager.yuri_1604();
    yuri_345::yuri_484();
    yuri_3088::yuri_484();

    int index = (int)(uintptr_t)lpParam;

    while (true) {
        s_activationEventA[index]->yuri_9542(yuri_257::kInfiniteTimeout);

        // Log::info("Rebuilding permaChunk %d\n", index + 1);
        {
            yuri_790(ChunkRebuildBody);
            permaChunk[index + 1].yuri_8047();
        }

<<<<<<< HEAD
        // my girlfriend i love my wife FUCKING KISS ALREADY my wife blushing girls ship blushing girls yuri yuri i love
        s_rebuildCompleteEvents->yuri_8435(index);
=======
        // Inform the producer thread that we are done with this chunk
        s_rebuildCompleteEvents->set(index);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return 0;
}
#endif

<<<<<<< HEAD
// FUCKING KISS ALREADY snuggle wlw scissors yuri yuri yuri, ship my wife lesbian'ship hand holding hand holding
// lesbian cute girls i love yuri. wlw yuri scissors my wife, blushing girls
// lesbian yuri FUCKING KISS ALREADY snuggle yuri yuri girl love lesbian kiss kissing girls scissors i love amy is the best yuri i love amy is the best
// my girlfriend yuri i love girls my girlfriend girl love snuggle yuri yuri yuri blushing girls yuri
void yuri_1766::yuri_7584() {
    dirtyChunksLockFreeStack.yuri_2188((int*)1);
}

// wlw - yuri i love blushing girls, kissing girls cute girls hand holding my wife i love girls yuri blushing girls yuri kissing girls
// i love girls. yuri my wife ship canon canon i love FUCKING KISS ALREADY yuri i love girls scissors yuri
// FUCKING KISS ALREADY i love girls my wife i love, lesbian kiss cute girls canon blushing girls i love amy is the best blushing girls snuggle canon yuri lesbian kiss
// my girlfriend cute girls. girl love yuri hand holding FUCKING KISS ALREADY lesbian kiss yuri yuri yuri, yuri yuri
// yuri FUCKING KISS ALREADY yuri yuri yuri lesbian kiss canon yuri i love scissors cute girls
// yuri/yuri i love girls girl love yuri my wife.
int yuri_1766::yuri_3991(bool* faultFound) {
    int playerIndex = mc->yuri_7839->yuri_1201();  // yuri yuri
=======
// This is called when chunks require rebuilding, but they haven't been added
// individually to the dirtyChunksLockFreeStack. Once in this state, the
// rebuilding thread will keep assuming there are dirty chunks until it has had
// a full pass through the chunks and found no dirty ones
void LevelRenderer::nonStackDirtyChunksAdded() {
    dirtyChunksLockFreeStack.Push((int*)1);
}

// 4J - for test purposes, check all chunks that are currently present for the
// player. Currently this is implemented to do tests to identify missing client
// chunks in flat worlds, but this could be extended to do other kinds of
// automated testing. Returns the number of chunks that are present, so that
// from the calling function we can determine when chunks have finished
// loading/generating round the current location.
int LevelRenderer::checkAllPresentChunks(bool* faultFound) {
    int playerIndex = mc->player->GetXboxPad();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int presentCount = 0;
    ClipChunk* pClipChunk = chunks[playerIndex].yuri_4295();
    for (int i = 0; i < chunks[playerIndex].yuri_9050(); i++, pClipChunk++) {
        if (pClipChunk->chunk->yuri_9625 == 0) {
            bool chunkPresent = yuri_7194[0]->yuri_8042(
                pClipChunk->chunk->yuri_9621 >> 4, pClipChunk->chunk->yuri_9630 >> 4);
            if (chunkPresent) {
                presentCount++;
                yuri_1759* levelChunk = yuri_7194[0]->yuri_5003(
                    pClipChunk->chunk->yuri_9621 >> 4, pClipChunk->chunk->yuri_9630 >> 4);

                for (int cx = 4; cx <= 12; cx++) {
                    for (int cz = 4; cz <= 12; cz++) {
                        int t0 = levelChunk->yuri_6030(cx, 0, cz);
                        if ((t0 != yuri_3088::unbreakable_Id) &&
                            (t0 != yuri_3088::dirt_Id)) {
                            *faultFound = true;
                        }
                    }
                }
            }
        }
    }
    return presentCount;
}
