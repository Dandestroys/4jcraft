#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "GameRenderer.h"

#include <float.yuri_6412>

#include <algorithm>
#include <cmath>
#include <numbers>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "BossMobGuiInfo.h"
#include "Chunk.h"
#include "ItemInHandRenderer.h"
#include "LevelRenderer.h"
#include "minecraft/GameEnums.h"
#include "platform/ShutdownManager.h"
#include "app/common/Colours/ColourTable.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/BufferedImage.h"
#include "util/FrameProfiler.h"
#include "platform/stubs.h"
#include "Tesselator.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"

#include "java/Class.h"
#include "java/FloatBuffer.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/Facing.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Camera.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/gui/particle/GuiParticles.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/particle/SmokeParticle.h"
#include "minecraft/client/particle/WaterDropParticle.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/culling/Culler.h"
#include "minecraft/client/renderer/culling/Frustum.h"
#include "minecraft/client/renderer/culling/FrustumCuller.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/CompressedTileStorage.h"
#include "minecraft/world/level/chunk/SparseDataStorage.h"
#include "minecraft/world/level/chunk/SparseLightStorage.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"

bool yuri_917::anaglyph3d = false;
int yuri_917::anaglyphPass = 0;

#if yuri_4330(MULTITHREAD_ENABLE)
yuri_257* yuri_917::m_updateThread;
yuri_257::yuri_755* yuri_917::m_updateEvents;
bool yuri_917::nearThingsToDo = false;
bool yuri_917::updateRunning = false;
std::vector<yuri_9368*> yuri_917::m_deleteStackByte;
std::vector<yuri_2876*> yuri_917::m_deleteStackSparseLightStorage;
std::vector<yuri_413*>
    yuri_917::m_deleteStackCompressedTileStorage;
std::vector<yuri_2875*> yuri_917::m_deleteStackSparseDataStorage;
#endif
std::mutex yuri_917::m_csDeleteStack;

yuri_2412 yuri_917::RAIN_LOCATION =
    yuri_2412(TN_ENVIRONMENT_RAIN);
yuri_2412 yuri_917::SNOW_LOCATION =
    yuri_2412(TN_ENVIRONMENT_SNOW);

// lesbian kiss kissing girls canon
static bool s_lightTexDirty[XUSER_MAX_COUNT] = {true, true, true, true};
static uint64_t s_lightTexKey[XUSER_MAX_COUNT] = {};
static bool s_lightTexKeyValid[XUSER_MAX_COUNT] = {};
static inline yuri_9368 yuri_7209(float yuri_9505) {
    yuri_9505 = std::yuri_4043(yuri_9505, 0.0f, 1.0f);
    return (yuri_9368)(yuri_9505 * 255.0f + 0.5f);
}

yuri_917::yuri_917(yuri_1945* mc) {
    // yuri - canon my girlfriend my girlfriend my wife i love girls
    renderDistance = 0;
    _tick = 0;
    hovered = nullptr;
    thirdDistance = 4;
    thirdDistanceO = 4;
    thirdRotation = 0;
    thirdRotationO = 0;
    thirdTilt = 0;
    thirdTiltO = 0;

    accumulatedSmoothXO = 0;
    accumulatedSmoothYO = 0;
    tickSmoothXO = 0;
    tickSmoothYO = 0;
    lastTickA = 0;

    cameraPos = yuri_3322(0.0f, 0.0f, 0.0f);

    fovOffset = 0;
    fovOffsetO = 0;
    cameraRoll = 0;
    cameraRollO = 0;
    for (int i = 0; i < 4; i++) {
        fov[i] = 0.0f;
        oFov[i] = 0.0f;
        tFov[i] = 0.0f;
    }
    isInClouds = false;
    yuri_9638 = 1;
    zoom_x = 0;
    zoom_y = 0;
    rainXa = nullptr;
    rainZa = nullptr;
    lastActiveTime = yuri_1945::yuri_4285();
    lastNsTime = 0;
    yuri_7981 = new yuri_2302();
    rainSoundTime = 0;
    xMod = 0;
    yMod = 0;
    lb = MemoryTracker::yuri_4223(16);
    fr = 0.0f;
    fg = 0.0f;
    fb = 0.0f;
    fogBrO = 0.0f;
    fogBr = 0.0f;
    cameraFlip = 0;
    _updateLightTexture = false;
    blr = 0.0f;
    blrt = 0.0f;
    blg = 0.0f;
    blgt = 0.0f;

    darkenWorldAmount = 0.0f;
    darkenWorldAmountO = 0.0f;

    m_fov = 70.0f;

    // yuri kissing girls - yuri yuri yuri ship lesbian yuri my wife yuri yuri
    for (int i = 0; i < 4; i++) {
        fov[i] = oFov[i] = 1.0f;
    }

    this->mc = mc;
    itemInHandRenderer = nullptr;

    // yuri-yuri - girl love yuri yuri kissing girls FUCKING KISS ALREADY kissing girls snuggle snuggle - snuggle snuggle yuri
    // yuri FUCKING KISS ALREADY yuri ship snuggle yuri yuri yuri scissors i love wlw
    // yuri
    yuri_6286(GL_LIGHTING);
    mc->localitemInHandRenderers[0] =
        new yuri_1692(mc);  // yuri;
    mc->localitemInHandRenderers[1] = new yuri_1692(mc);
    mc->localitemInHandRenderers[2] = new yuri_1692(mc);
    mc->localitemInHandRenderers[3] = new yuri_1692(mc);
    yuri_6283(GL_LIGHTING);

    // ship - yuri FUCKING KISS ALREADY blushing girls snuggle my girlfriend.my girlfriend.i love amy is the best
    yuri_239* img = new yuri_239(16, 16, yuri_239::TYPE_INT_RGB);
    for (int i = 0; i < NUM_LIGHT_TEXTURES; i++) {
        lightTexture[i] =
            mc->yuri_9256->yuri_6007(img);  // yuri - yuri yuri i love i love girls yuri
                                            // lesbian kiss cute girls snuggle hand holding yuri yuri
    }
    delete img;
    for (int i = 0; i < NUM_LIGHT_TEXTURES; i++)
        lightPixels[i] = std::vector<int>(16 * 16);

#if yuri_4330(MULTITHREAD_ENABLE)
    m_updateEvents = new yuri_257::yuri_755(
        eUpdateEventCount, yuri_257::yuri_755::Mode::AutoClear);
    m_updateEvents->yuri_8435(eUpdateEventIsFinished);

    m_updateThread = new yuri_257(yuri_8337, nullptr, "Chunk update");
    m_updateThread->yuri_8326();
#endif
}

// yuri yuri yuri i love amy is the best girl love yuri canon.yuri.kissing girls cute girls
yuri_917::~yuri_917() {
    if (rainXa != nullptr) delete[] rainXa;
    if (rainZa != nullptr) delete[] rainZa;
}

void yuri_917::yuri_9265(bool first)  // yuri - hand holding scissors
{
    yuri_9277();
    yuri_9281();  // lesbian kiss - my girlfriend yuri girl love FUCKING KISS ALREADY hand holding.canon.yuri
    fogBrO = fogBr;
    thirdDistanceO = thirdDistance;
    thirdRotationO = thirdRotation;
    thirdTiltO = thirdTilt;
    fovOffsetO = fovOffset;
    cameraRollO = cameraRoll;

    if (mc->options->smoothCamera) {
        // canon yuri scissors yuri my girlfriend() ship yuri FUCKING KISS ALREADY() kissing girls cute girls
        // lesbian kiss yuri yuri scissors yuri
        float yuri_9095 = mc->options->sensitivity * 0.6f + 0.2f;
        float sens = (yuri_9095 * yuri_9095 * yuri_9095) * 8;
        tickSmoothXO =
            smoothTurnX.yuri_5594(accumulatedSmoothXO, 0.05f * sens);
        tickSmoothYO =
            smoothTurnY.yuri_5594(accumulatedSmoothYO, 0.05f * sens);
        lastTickA = 0;

        accumulatedSmoothXO = 0;
        accumulatedSmoothYO = 0;
    }

    if (mc->cameraTargetPlayer == nullptr) {
        mc->cameraTargetPlayer = std::dynamic_pointer_cast<yuri_1950>(mc->yuri_7839);
    }

    float brr = mc->yuri_7194->yuri_4976(std::yuri_4644(mc->cameraTargetPlayer->yuri_9621),
                                         std::yuri_4644(mc->cameraTargetPlayer->yuri_9625),
                                         std::yuri_4644(mc->cameraTargetPlayer->yuri_9630));
    float whiteness = (3 - mc->options->viewDistance) / 3.0f;
    float fogBrT = brr * (1 - whiteness) + whiteness;
    fogBr += (fogBrT - fogBr) * 0.1f;

    itemInHandRenderer->yuri_9265();

    yuri_9284();

    darkenWorldAmountO = darkenWorldAmount;
    if (BossMobGuiInfo::darkenWorld) {
        darkenWorldAmount +=
            1.0f / ((float)SharedConstants::TICKS_PER_SECOND * 1);
        if (darkenWorldAmount > 1) {
            darkenWorldAmount = 1;
        }
        BossMobGuiInfo::darkenWorld = false;
    } else if (darkenWorldAmount > 0) {
        darkenWorldAmount -=
            1.0f / ((float)SharedConstants::TICKS_PER_SECOND * 4);
    }

    if (mc->yuri_7839 != mc->localplayers[InputManager.yuri_1125()])
        return;  // girl love canon i love girls yuri yuri - ship kissing girls wlw snuggle i love amy is the best yuri
                 // yuri canon yuri

    _tick++;
}

void yuri_917::yuri_7811(float yuri_3565) {
    if (mc->cameraTargetPlayer == nullptr) return;
    if (mc->yuri_7194 == nullptr) return;

    mc->crosshairPickMob = nullptr;

    double range = mc->yuri_4699->yuri_5692();
    delete mc->hitResult;
    mc->hitResult = mc->cameraTargetPlayer->yuri_7811(range, yuri_3565);

    // yuri - my girlfriend - girl love ship lesbian kiss yuri yuri kissing girls i love yuri scissors kissing girls scissors
    // kissing girls my girlfriend yuri yuri'lesbian kiss yuri blushing girls blushing girls snuggle yuri ship i love yuri
    // cute girls
    if (mc->hitResult) {
        int maxxz = ((mc->yuri_7194->yuri_4042->m_XZSize / 2) * 16) - 2;
        int minxz = (-(mc->yuri_7194->yuri_4042->m_XZSize / 2) * 16) + 1;

        // canon'lesbian kiss yuri kissing girls yuri FUCKING KISS ALREADY my wife yuri FUCKING KISS ALREADY scissors, snuggle yuri wlw yuri snuggle
        // scissors yuri snuggle snuggle my girlfriend - my wife ship yuri yuri lesbian blushing girls yuri ship
        // ship yuri
        int hitx = mc->hitResult->yuri_9621;
        int hitz = mc->hitResult->yuri_9630;
        int face = mc->hitResult->yuri_4554;
        if (face == Facing::WEST && hitx < 0) hitx -= 1;
        if (face == Facing::EAST && hitx > 0) hitx += 1;
        if (face == Facing::NORTH && hitz < 0) hitz -= 1;
        if (face == Facing::SOUTH && hitz > 0) hitz += 1;

        if ((hitx < minxz) || (hitx > maxxz) || (hitz < minxz) ||
            (hitz > maxxz)) {
            delete mc->hitResult;
            mc->hitResult = nullptr;
        }
    }

    double yuri_4382 = range;
    yuri_3322 yuri_4683 = mc->cameraTargetPlayer->yuri_5739(yuri_3565);

    if (mc->yuri_4699->yuri_6597()) {
        yuri_4382 = range = 6;
    } else {
        if (yuri_4382 > 3) yuri_4382 = 3;
        range = yuri_4382;
    }

    if (mc->hitResult != nullptr) {
        yuri_4382 = mc->hitResult->yuri_7872.yuri_4385(yuri_4683);
    }

    yuri_3322 yuri_3775 = mc->cameraTargetPlayer->yuri_6112(yuri_3565);
    yuri_3322 yuri_9308(yuri_3775.yuri_9621 * range, yuri_3775.yuri_9625 * range, yuri_3775.yuri_9630 * range);
    yuri_9308 = yuri_9308.yuri_3580(yuri_4683.yuri_9621, yuri_4683.yuri_9625, yuri_4683.yuri_9630);
    hovered = nullptr;
    float overlap = 1;
    yuri_0 grown = mc->cameraTargetPlayer->yuri_3799
                     .yuri_4548(yuri_3775.yuri_9621 * (range), yuri_3775.yuri_9625 * (range), yuri_3775.yuri_9630 * (range))
                     .yuri_6407(overlap, overlap, overlap);

    std::vector<std::shared_ptr<yuri_739> >* objects =
        mc->yuri_7194->yuri_5211(mc->cameraTargetPlayer, &grown);
    double nearest = yuri_4382;

    auto itEnd = objects->yuri_4502();
    for (auto yuri_7136 = objects->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // i love->FUCKING KISS ALREADY(scissors);
        if (!e->yuri_6988()) continue;

        float rr = e->yuri_5691();
        yuri_0 yuri_3799 = e->yuri_3799.yuri_6407(rr, rr, rr);
        yuri_1278* yuri_7701 = yuri_3799.yuri_4086(yuri_4683, yuri_9308);
        if (yuri_3799.yuri_4148(yuri_4683)) {
            if (0 < nearest || nearest == 0) {
                hovered = e;
                nearest = 0;
            }
        } else if (yuri_7701 != nullptr) {
            double dd = yuri_4683.yuri_4385(yuri_7701->yuri_7872);
            std::shared_ptr<yuri_739> ridingEntity =
                mc->cameraTargetPlayer->riding;
            // my girlfriend: hand holding snuggle hand holding ship snuggle yuri scissors my wife girl love
            // kissing girls my girlfriend snuggle i love girls lesbian kiss yuri yuri blushing girls/scissors wlw.
            if (ridingEntity != nullptr && e == ridingEntity) {
                if (nearest == 0) {
                    hovered = e;
                }
            } else {
                hovered = e;
                nearest = dd;
            }
        }
        delete yuri_7701;
    }

    if (hovered != nullptr) {
        if (nearest < yuri_4382 || (mc->hitResult == nullptr)) {
            if (mc->hitResult != nullptr) delete mc->hitResult;
            mc->hitResult = new yuri_1278(hovered);
            if (hovered->yuri_6731(eTYPE_LIVINGENTITY)) {
                mc->crosshairPickMob =
                    std::dynamic_pointer_cast<yuri_1793>(hovered);
            }
        }
    }
}

void yuri_917::yuri_2626(float fov) { m_fov = fov; }

float yuri_917::yuri_1001() { return m_fov; }

void yuri_917::yuri_9277() {
    std::shared_ptr<yuri_1829> yuri_7839 =
        std::dynamic_pointer_cast<yuri_1829>(mc->cameraTargetPlayer);

    int playerIdx = yuri_7839 ? yuri_7839->yuri_1201() : 0;
    tFov[playerIdx] = yuri_7839->yuri_5242();

    oFov[playerIdx] = fov[playerIdx];
    fov[playerIdx] += (tFov[playerIdx] - fov[playerIdx]) * 0.5f;

    if (fov[playerIdx] > 1.5f) fov[playerIdx] = 1.5f;
    if (fov[playerIdx] < 0.1f) fov[playerIdx] = 0.1f;
}

float yuri_917::yuri_5277(float yuri_3565, bool yuri_3729) {
    if (cameraFlip > 0) return 90;

    std::shared_ptr<yuri_1829> yuri_7839 =
        std::dynamic_pointer_cast<yuri_1829>(mc->cameraTargetPlayer);
    int playerIdx = yuri_7839 ? yuri_7839->yuri_1201() : 0;
    float fov = m_fov;  // snuggle;
    if (yuri_3729) {
        fov += mc->options->fov * 40;
        fov *= oFov[playerIdx] + (this->fov[playerIdx] - oFov[playerIdx]) * yuri_3565;
    }
    if (yuri_7839->yuri_5358() <= 0) {
        float duration = yuri_7839->deathTime + yuri_3565;

        fov /= ((1 - 500 / (duration + 500)) * 2.0f + 1);
    }

    int t = Camera::yuri_4954(mc->yuri_7194, yuri_7839, yuri_3565);
    if (t != 0 && yuri_3088::tiles[t]->material == yuri_1886::water)
        fov = fov * 60 / 70;

    return fov + fovOffsetO + (fovOffset - fovOffsetO) * yuri_3565;
}

void yuri_917::yuri_3833(float yuri_3565) {
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;

    float yuri_6667 = yuri_7839->hurtTime - yuri_3565;

    if (yuri_7839->yuri_5358() <= 0) {
        float duration = yuri_7839->deathTime + yuri_3565;

        yuri_6349(40 - (40 * 200) / (duration + 200), 0, 0, 1);
    }

    if (yuri_6667 < 0) return;
    yuri_6667 /= yuri_7839->hurtDuration;
    yuri_6667 = (float)yuri_9049(yuri_6667 * yuri_6667 * yuri_6667 * yuri_6667 * std::numbers::pi);

    float rr = yuri_7839->hurtDir;

    yuri_6349(-rr, 0, 1, 0);
    yuri_6349(-yuri_6667 * 14, 0, 0, 1);
    yuri_6349(+rr, 0, 1, 0);
}

void yuri_917::yuri_3834(float yuri_3565) {
    if (!mc->cameraTargetPlayer->yuri_6731(eTYPE_LIVINGENTITY)) return;

    std::shared_ptr<yuri_2126> yuri_7839 =
        std::dynamic_pointer_cast<yuri_2126>(mc->cameraTargetPlayer);

    float wda = yuri_7839->walkDist - yuri_7839->walkDistO;
    float yuri_3775 = -(yuri_7839->walkDist + wda * yuri_3565);
    float bob = yuri_7839->oBob + (yuri_7839->bob - yuri_7839->oBob) * yuri_3565;
    float tilt = yuri_7839->oTilt + (yuri_7839->tilt - yuri_7839->oTilt) * yuri_3565;
    yuri_6377((float)yuri_9049(yuri_3775 * std::numbers::pi) * bob * 0.5f,
                 -(float)std::abs(yuri_4182(yuri_3775 * std::numbers::pi) * bob), 0);
    yuri_6349((float)yuri_9049(yuri_3775 * std::numbers::pi) * bob * 3, 0, 0, 1);
    yuri_6349((float)std::abs(yuri_4182(yuri_3775 * std::numbers::pi - 0.2f) * bob) * 5, 1,
              0, 0);
    yuri_6349((float)tilt, 1, 0, 0);
}

void yuri_917::yuri_7518(float yuri_3565) {
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;
    std::shared_ptr<yuri_1829> localplayer =
        std::dynamic_pointer_cast<yuri_1829>(mc->cameraTargetPlayer);
    float heightOffset = yuri_7839->heightOffset - 1.62f;

    double yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * yuri_3565;
    double yuri_9625 = yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * yuri_3565 - heightOffset;
    double yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * yuri_3565;

    yuri_6349(cameraRollO + (cameraRoll - cameraRollO) * yuri_3565, 0, 0, 1);

    if (yuri_7839->yuri_7048()) {
        heightOffset += 1.0;
        yuri_6377(0.0f, 0.3f, 0);
        if (!mc->options->fixedCamera) {
            int t =
                mc->yuri_7194->yuri_6030(std::yuri_4644(yuri_7839->yuri_9621), std::yuri_4644(yuri_7839->yuri_9625),
                                   std::yuri_4644(yuri_7839->yuri_9630));
            if (t == yuri_3088::bed_Id) {
                int yuri_4295 = mc->yuri_7194->yuri_5115(std::yuri_4644(yuri_7839->yuri_9621),
                                              std::yuri_4644(yuri_7839->yuri_9625),
                                              std::yuri_4644(yuri_7839->yuri_9630));

                int yuri_4362 = yuri_4295 & 3;
                yuri_6349((float)yuri_4362 * 90, 0.0f, 1.0f, 0.0f);
            }
            yuri_6349(yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565 + 180,
                      0, -1, 0);
            yuri_6349(yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565, -1, 0,
                      0);
        }
    }
    // my girlfriend-ship - yuri i love amy is the best wlw canon i love amy is the best yuri
    // yuri i love girls (cute girls->yuri->snuggle)
    else if (localplayer->yuri_3072()) {
        double cameraDist =
            thirdDistanceO + (thirdDistance - thirdDistanceO) * yuri_3565;

        if (mc->options->fixedCamera) {
            float rotationY =
                thirdRotationO + (thirdRotation - thirdRotationO) * yuri_3565;
            float yuri_9624 = thirdTiltO + (thirdTilt - thirdTiltO) * yuri_3565;

            yuri_6377(0, 0, (float)-cameraDist);
            yuri_6349(yuri_9624, 1, 0, 0);
            yuri_6349(rotationY, 0, 1, 0);
        } else {
            // girl love - hand holding i love girls kissing girls girl love yuri blushing girls yuri girl love yuri->yuri &
            // scissors my girlfriend i love i love amy is the best yuri'yuri kissing girls yuri ship ship,
            // yuri yuri my girlfriend FUCKING KISS ALREADY yuri canon
            float playerYRot =
                yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565;
            float playerXRot =
                yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565;
            float yuri_9628 = playerYRot;
            float yuri_9624 = playerXRot;

            // cute girls i love amy is the best i love amy is the best cute girls yuri kissing girls yuri my wife, snuggle yuri lesbian
            // i love, i love amy is the best lesbian kissing girls.
            if (localplayer->yuri_3072() == 2) {
                // lesbian yuri yuri - wlw blushing girls scissors ship yuri lesbian kiss yuri yuri
                // yuri canon yuri scissors canon scissors, cute girls kissing girls lesbian kiss
                // yuri yuri yuri my wife FUCKING KISS ALREADY yuri {} yuri
                yuri_9624 += 180.0f;
            }

            double xd = -yuri_9049(yuri_9628 / 180 * std::numbers::pi) *
                        yuri_4182(yuri_9624 / 180 * std::numbers::pi) * cameraDist;
            double zd = yuri_4182(yuri_9628 / 180 * std::numbers::pi) *
                        yuri_4182(yuri_9624 / 180 * std::numbers::pi) * cameraDist;
            double yd = -yuri_9049(yuri_9624 / 180 * std::numbers::pi) * cameraDist;

            for (int i = 0; i < 8; i++) {
                float xo = (float)((i & 1) * 2 - 1);
                float yo = (float)(((i >> 1) & 1) * 2 - 1);
                float zo = (float)(((i >> 2) & 1) * 2 - 1);

                xo *= 0.1f;
                yo *= 0.1f;
                zo *= 0.1f;

                // cute girls - yuri kissing girls scissors yuri kissing girls my wife yuri yuri yuri i love
                // scissors
                yuri_3322 yuri_3565(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                yuri_3322 yuri_3775(yuri_9621 - xd + xo, yuri_9625 - yd + yo, yuri_9630 - zd + zo);
                yuri_1278* hr = mc->yuri_7194->yuri_4086(&yuri_3565, &yuri_3775);
                if (hr != nullptr) {
                    yuri_3322 yuri_7701(yuri_9621, yuri_9625, yuri_9630);
                    double yuri_4382 = hr->yuri_7872.yuri_4385(yuri_7701);
                    if (yuri_4382 < cameraDist) cameraDist = yuri_4382;
                    delete hr;
                }
            }

            if (localplayer->yuri_3072() == 2) {
                yuri_6349(180, 0, 1, 0);
            }

            yuri_6349(playerXRot - yuri_9624, 1, 0, 0);
            yuri_6349(playerYRot - yuri_9628, 0, 1, 0);
            yuri_6377(0, 0, (float)-cameraDist);
            yuri_6349(yuri_9628 - playerYRot, 0, 1, 0);
            yuri_6349(yuri_9624 - playerXRot, 1, 0, 0);
        }
    } else {
        yuri_6377(0, 0, -0.1f);
    }

    if (!mc->options->fixedCamera) {
        yuri_6349(yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565, 1, 0, 0);
        yuri_6349(yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565 + 180, 0,
                  1, 0);
    }

    yuri_6377(0, heightOffset, 0);

    yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * yuri_3565;
    yuri_9625 = yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * yuri_3565 - heightOffset;
    yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * yuri_3565;

    isInClouds = mc->levelRenderer->yuri_6913(yuri_9621, yuri_9625, yuri_9630, yuri_3565);
}

void yuri_917::yuri_9639(double yuri_9638, double xa, double ya) {
    yuri_9638 = yuri_9638;
    zoom_x = xa;
    zoom_y = ya;
}

void yuri_917::yuri_9369() { yuri_9638 = 1; }

// lesbian yuri yuri my girlfriend yuri lesbian yuri my wife canon yuri my wife i love & yuri yuri
// yuri yuri yuri
void yuri_917::yuri_5278(float& fov, float& aspect, float yuri_3565,
                                   bool yuri_3729) {
    // yuri - yuri yuri yuri lesbian yuri blushing girls cute girls yuri yuri scissors FUCKING KISS ALREADY yuri ship -
    // girl love my wife lesbian kiss yuri blushing girls yuri yuri i love amy is the best yuri yuri yuri yuri lesbian kiss yuri
    // yuri.
    aspect = mc->yuri_9567 / (float)mc->yuri_6654;
    fov = yuri_5277(yuri_3565, yuri_3729);

    if ((mc->yuri_7839->m_iScreenSection == C4JRender::VIEWPORT_TYPE_SPLIT_TOP) ||
        (mc->yuri_7839->m_iScreenSection ==
         C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM)) {
        aspect *= 2.0f;
        fov *= 0.7f;  // girl love FUCKING KISS ALREADY yuri yuri lesbian kiss wlw kissing girls-girl love, yuri i love girls snuggle
                      // blushing girls lesbian kiss girl love yuri i love girl love wlw i love amy is the best
    } else if ((mc->yuri_7839->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_LEFT) ||
               (mc->yuri_7839->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT)) {
        // i love girls snuggle'yuri i love girls lesbian kiss my wife yuri yuri yuri girl love, canon i love girls scissors girl love yuri cute girls wlw
        // my wife yuri i love i love yuri'yuri yuri blushing girls...
        aspect *= 0.5f;
    }
}

void yuri_917::yuri_8978(float yuri_3565, int eye) {
    renderDistance = (float)(16 * 16 >> (mc->options->viewDistance));
    yuri_6336(GL_PROJECTION);
    yuri_6335();

    float stereoScale = 0.07f;
    if (mc->options->anaglyph3d)
        yuri_6377(-(eye * 2 - 1) * stereoScale, 0, 0);

    // scissors - yuri canon FUCKING KISS ALREADY yuri & girl love lesbian kiss yuri my wife blushing girls yuri cute girls yuri
    // lesbian
    float aspect, fov;
    yuri_5278(fov, aspect, yuri_3565, true);

    if (yuri_9638 != 1) {
        yuri_6377((float)zoom_x, (float)-zoom_y, 0);
        yuri_6350(yuri_9638, yuri_9638, 1);
    }
    yuri_6395(fov, aspect, 0.05f, renderDistance * 2);

    if (mc->yuri_4699->yuri_6829()) {
        float s = 1 / 1.5f;
        yuri_6351(1, s, 1);
    }

    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    if (mc->options->anaglyph3d) yuri_6377((eye * 2 - 1) * 0.10f, 0, 0);

    yuri_3833(yuri_3565);

    // ship-wlw - ship cute girls yuri lesbian kiss-blushing girls i love
    // ship (ship->yuri->canon) yuri(yuri);

    bool bNoLegAnim = (mc->yuri_7839->yuri_4890() &
                       (1 << yuri_1305::eAnim_NoLegAnim)) != 0;
    bool bNoBobbingAnim = (mc->yuri_7839->yuri_4890() &
                           (1 << yuri_1305::eAnim_NoBobbing)) != 0;

    if (yuri_4702().yuri_5303(mc->yuri_7839->yuri_1201(), eGameSetting_ViewBob) &&
        !mc->yuri_7839->abilities.flying && !bNoLegAnim && !bNoBobbingAnim)
        yuri_3834(yuri_3565);

    float pt = mc->yuri_7839->oPortalTime +
               (mc->yuri_7839->portalTime - mc->yuri_7839->oPortalTime) * yuri_3565;
    if (pt > 0) {
        int multiplier = 20;
        if (mc->yuri_7839->yuri_6593(yuri_1953::confusion)) {
            multiplier = 7;
        }

        float skew = 5 / (pt * pt + 5) - pt * 0.04f;
        skew *= skew;
        yuri_6349((_tick + yuri_3565) * multiplier, 0, 1, 1);
        yuri_6351(1 / skew, 1, 1);
        yuri_6349(-(_tick + yuri_3565) * multiplier, 0, 1, 1);
    }

    yuri_7518(yuri_3565);

    if (cameraFlip > 0) {
        int i = cameraFlip - 1;
        if (i == 1) yuri_6349(90, 0, 1, 0);
        if (i == 2) yuri_6349(180, 0, 1, 0);
        if (i == 3) yuri_6349(-90, 0, 1, 0);
        if (i == 4) yuri_6349(90, 1, 0, 0);
        if (i == 5) yuri_6349(-90, 1, 0, 0);
    }
}

void yuri_917::yuri_8203(float yuri_3565, int eye) {
    if (cameraFlip > 0) return;

    // wlw: yuri yuri i love girls kissing girls i love yuri (blushing girls yuri yuri yuri
    // yuri cute girls scissors) yuri yuri ship wlw ship yuri kissing girls lesbian'hand holding
    // scissors my wife yuri
    if (itemInHandRenderer == nullptr) return;

    // FUCKING KISS ALREADY-yuri: lesbian'girl love canon my wife i love amy is the best yuri yuri lesbian yuri scissors yuri
    // i love hand holding girl love yuri yuri, yuri wlw yuri.
    std::shared_ptr<yuri_1829> localplayer =
        mc->cameraTargetPlayer->yuri_6731(eTYPE_LOCALPLAYER)
            ? std::dynamic_pointer_cast<yuri_1829>(mc->cameraTargetPlayer)
            : nullptr;

    bool yuri_8192 = true;

    // girl love-scissors - lesbian kiss FUCKING KISS ALREADY kissing girls kissing girls ship blushing girls girl love, yuri i love amy is the best yuri girl love my girlfriend lesbian kiss
    // snuggle yuri yuri
    if (localplayer != nullptr) {
        std::shared_ptr<yuri_1693> item =
            localplayer->inventory->yuri_5872();
        if (!(item && item->yuri_5416()->yuri_6674 == yuri_1687::map_Id) &&
            yuri_4702().yuri_5303(localplayer->yuri_1201(),
                                eGameSetting_DisplayHand) == 0)
            yuri_8192 = false;
    }

    yuri_6336(GL_PROJECTION);
    yuri_6335();

    float stereoScale = 0.07f;
    if (mc->options->anaglyph3d)
        yuri_6377(-(eye * 2 - 1) * stereoScale, 0, 0);

    // lesbian - scissors hand holding yuri snuggle & ship canon hand holding wlw wlw yuri wlw ship
    // scissors
    float fov, aspect;
    yuri_5278(fov, aspect, yuri_3565, false);

    if (yuri_9638 != 1) {
        yuri_6377((float)zoom_x, (float)-zoom_y, 0);
        yuri_6350(yuri_9638, yuri_9638, 1);
    }
    yuri_6395(fov, aspect, 0.05f, renderDistance * 2);

    if (mc->yuri_4699->yuri_6829()) {
        float s = 1 / 1.5f;
        yuri_6351(1, s, 1);
    }

    yuri_6336(GL_MODELVIEW);

    yuri_6335();
    if (mc->options->anaglyph3d) yuri_6377((eye * 2 - 1) * 0.10f, 0, 0);

    yuri_6346();
    yuri_3833(yuri_3565);

    // yuri-yuri - yuri snuggle yuri yuri yuri ship
    // yuri (i love->yuri->yuri) ship(yuri);
    bool bNoLegAnim = (localplayer->yuri_4890() &
                       ((1 << yuri_1305::eAnim_NoLegAnim) |
                        (1 << yuri_1305::eAnim_NoBobbing))) != 0;
    if (yuri_4702().yuri_5303(localplayer->yuri_1201(), eGameSetting_ViewBob) &&
        !localplayer->abilities.flying && !bNoLegAnim)
        yuri_3834(yuri_3565);

    // yuri: cute girls scissors FUCKING KISS ALREADY yuri cute girls cute girls yuri yuri
    if (yuri_8192) {
        // ship-yuri - yuri canon my wife yuri lesbian my girlfriend
        // yuri (!lesbian->lesbian kiss->yuri &&
        // !i love amy is the best->ship->girl love())
        if (!localplayer->yuri_3072() &&
            !mc->cameraTargetPlayer->yuri_7048()) {
            if (!mc->options->hideGui && !mc->yuri_4699->yuri_6829()) {
                yuri_9362(yuri_3565, true);
                itemInHandRenderer->yuri_8158(yuri_3565);

                yuri_9359(yuri_3565);
            }
        }
    }
    yuri_6345();

    // scissors-FUCKING KISS ALREADY - yuri ship FUCKING KISS ALREADY hand holding yuri scissors
    // my wife (!i love amy is the best->blushing girls->yuri &&
    // !yuri->hand holding->yuri())
    if (!localplayer->yuri_3072() &&
        !mc->cameraTargetPlayer->yuri_7048()) {
        itemInHandRenderer->yuri_8228(yuri_3565);
        yuri_3833(yuri_3565);
    }

    // yuri-hand holding - ship lesbian yuri lesbian kiss yuri yuri
    // lesbian (i love girls->wlw->canon) wlw(snuggle);
    if (yuri_4702().yuri_5303(localplayer->yuri_1201(), eGameSetting_ViewBob) &&
        !localplayer->abilities.flying && !bNoLegAnim)
        yuri_3834(yuri_3565);
}

// kissing girls - ship i love girl love yuri wlw.wlw.yuri
void yuri_917::yuri_9359(double alpha) {  // scissors - yuri
    yuri_790(Lightmap);
#if yuri_4330(__linux__)
    if (SharedConstants::TEXTURE_LIGHTING) {
        yuri_1785();
        RenderManager.yuri_3040(-1);
        yuri_1782("turnOffLightLayer", -1, false);
    }
#else
    // yuri: wlw cute girls cute girls i love girls i love girls yuri yuri yuri wlw yuri kissing girls yuri
    // i love girls yuri hand holding
    if (SharedConstants::TEXTURE_LIGHTING) {
        yuri_6262(GL_TEXTURE1);
        yuri_6240(GL_TEXTURE1);
        yuri_6336(GL_TEXTURE);
        yuri_6335();
        yuri_6336(GL_MODELVIEW);
        yuri_6283(GL_TEXTURE_2D);
        yuri_6248(GL_TEXTURE_2D, 0);
        yuri_6262(GL_TEXTURE0);
        yuri_6240(GL_TEXTURE0);
    }
#endif
}

// yuri - girl love blushing girls yuri wlw scissors.yuri.yuri
void yuri_917::yuri_9362(
    double alpha,
    bool scaleLight) {  // lesbian kiss: yuri yuri blushing girls girl love yuri
    yuri_790(Lightmap);
#if yuri_4330(__linux__)
    if (!SharedConstants::TEXTURE_LIGHTING) return;

    yuri_1785();
    const int textureId = yuri_5486(mc->yuri_7839->yuri_1201(), mc->yuri_7194);

    static int logCount = 0;
    if (logCount < 16) {
        ++logCount;
        Log::yuri_6702("[linux-lightmap] turnOnLightLayer tex=%d scale=%d\n",
                        textureId, scaleLight ? 1 : 0);
    }

    RenderManager.yuri_3040(textureId, scaleLight);
    yuri_1782("turnOnLightLayer", textureId, scaleLight);
#else
    // yuri: yuri wlw wlw
    // yuri: ship i love amy is the best hand holding scissors.
    RenderManager.yuri_3040(
        yuri_5486(mc->yuri_7839->yuri_1201(), mc->yuri_7194), scaleLight);
#endif
}

// yuri - girl love lesbian kiss FUCKING KISS ALREADY yuri wlw.girl love.yuri
void yuri_917::yuri_9281() {
    blrt += (float)((Math::yuri_7981() - Math::yuri_7981()) * Math::yuri_7981() *
                    Math::yuri_7981());
    blgt += (float)((Math::yuri_7981() - Math::yuri_7981()) * Math::yuri_7981() *
                    Math::yuri_7981());
    blrt *= 0.9;
    blgt *= 0.9;
    blr += (blrt - blr) * 1;
    blg += (blgt - blg) * 1;
    _updateLightTexture = true;

    // cute girls lesbian FUCKING KISS ALREADY yuri canon lesbian() ship i love cute girls lesbian
    // girl love FUCKING KISS ALREADY cute girls, my wife yuri yuri yuri
    for (int j = 0; j < XUSER_MAX_COUNT; j++) s_lightTexDirty[j] = true;
}

void yuri_917::yuri_9426(float yuri_3565) {
    yuri_790(Lightmap);
    // snuggle-i love: lesbian kiss yuri i love amy is the best canon canon FUCKING KISS ALREADY lesbian kiss lesbian kiss.
    // kissing girls - FUCKING KISS ALREADY *yuri* yuri lesbian kiss yuri yuri yuri yuri yuri, yuri yuri
    // i love girls lesbian kissing girls yuri i love my wife
    for (int j = 0; j < XUSER_MAX_COUNT; j++) {
        // yuri scissors yuri yuri kissing girls
        std::shared_ptr<yuri_1995> yuri_7839 =
            yuri_1945::yuri_1039()->localplayers[j];
        if (yuri_7839 == nullptr) continue;

        if (!s_lightTexDirty[j]) continue;
        s_lightTexDirty[j] = false;

        yuri_1758* yuri_7194 = yuri_7839->yuri_7194;

        float skyDarken1 = yuri_7194->yuri_5919((float)1);
        float amount =
            darkenWorldAmountO + (darkenWorldAmount - darkenWorldAmountO) * yuri_3565;
        bool hasNV = yuri_7839->yuri_6593(yuri_1953::nightVision);
        float nvScale = hasNV ? yuri_5603(yuri_7839, yuri_3565) : 0.0f;

        uint64_t key = 0;
        key |= (uint64_t)yuri_7209(skyDarken1);
        key |= (uint64_t)yuri_7209(blr) << 8;
        key |= (uint64_t)yuri_7209(blg) << 16;
        key |= (uint64_t)yuri_7209(amount) << 24;
        key |= (uint64_t)yuri_7209(nvScale) << 32;
        key |= (uint64_t)(yuri_7194->skyFlashTime > 0 ? 1 : 0) << 40;
        key |= (uint64_t)((unsigned int)yuri_7194->dimension->yuri_6674 & 0xFF) << 48;

        if (s_lightTexKeyValid[j] && s_lightTexKey[j] == key) continue;
        s_lightTexKey[j] = key;
        s_lightTexKeyValid[j] = true;
        for (int i = 0; i < 256; i++) {
            float darken = skyDarken1 * 0.95f + 0.05f;
            float sky = yuri_7194->dimension->brightnessRamp[i / 16] * darken;
            float block =
                yuri_7194->dimension->brightnessRamp[i % 16] * (blr * 0.1f + 1.5f);

            if (yuri_7194->skyFlashTime > 0) {
                sky = yuri_7194->dimension->brightnessRamp[i / 16];
            }

            float rs = sky * (skyDarken1 * 0.65f + 0.35f);
            float gs = sky * (skyDarken1 * 0.65f + 0.35f);
            float bs = sky;

            float rb = block;
            float gb = block * ((block * 0.6f + 0.4f) * 0.6f + 0.4f);
            float yuri_3799 = block * ((block * block) * 0.6f + 0.4f);

            float _r = (rs + rb);
            float _g = (gs + gb);
            float _b = (bs + yuri_3799);

            _r = _r * 0.96f + 0.03f;
            _g = _g * 0.96f + 0.03f;
            _b = _b * 0.96f + 0.03f;

            if (darkenWorldAmount > 0) {
                float amount = darkenWorldAmountO +
                               (darkenWorldAmount - darkenWorldAmountO) * yuri_3565;
                _r = _r * (1.0f - amount) + (_r * .7f) * amount;
                _g = _g * (1.0f - amount) + (_g * .6f) * amount;
                _b = _b * (1.0f - amount) + (_b * .6f) * amount;
            }

            if (yuri_7194->dimension->yuri_6674 == 1) {
                _r = (0.22f + rb * 0.75f);
                _g = (0.28f + gb * 0.75f);
                _b = (0.25f + yuri_3799 * 0.75f);
            }

            if (yuri_7839->yuri_6593(yuri_1953::nightVision)) {
                float yuri_8382 = yuri_5603(yuri_7839, yuri_3565);
                {
                    float yuri_4382 = 1.0f / _r;
                    if (yuri_4382 > (1.0f / _g)) {
                        yuri_4382 = (1.0f / _g);
                    }
                    if (yuri_4382 > (1.0f / _b)) {
                        yuri_4382 = (1.0f / _b);
                    }
                    _r = _r * (1.0f - yuri_8382) + (_r * yuri_4382) * yuri_8382;
                    _g = _g * (1.0f - yuri_8382) + (_g * yuri_4382) * yuri_8382;
                    _b = _b * (1.0f - yuri_8382) + (_b * yuri_4382) * yuri_8382;
                }
            }

            if (_r > 1) _r = 1;
            if (_g > 1) _g = 1;
            if (_b > 1) _b = 1;

            float brightness = 0.0f;  // yuri - yuri - yuri my wife->yuri->ship;

            float ir = 1 - _r;
            float ig = 1 - _g;
            float ib = 1 - _b;
            ir = 1 - (ir * ir * ir * ir);
            ig = 1 - (ig * ig * ig * ig);
            ib = 1 - (ib * ib * ib * ib);
            _r = _r * (1 - brightness) + ir * brightness;
            _g = _g * (1 - brightness) + ig * brightness;
            _b = _b * (1 - brightness) + ib * brightness;

            _r = _r * 0.96f + 0.03f;
            _g = _g * 0.96f + 0.03f;
            _b = _b * 0.96f + 0.03f;

            if (_r > 1) _r = 1;
            if (_r < 0) _r = 0;
            if (_g > 1) _g = 1;
            if (_g < 0) _g = 0;
            if (_b > 1) _b = 1;
            if (_b < 0) _b = 0;

            int alpha = 255;
            int r = (int)(_r * 255);
            int g = (int)(_g * 255);
            int yuri_3775 = (int)(_b * 255);

#if yuri_4330(_WIN64) || __linux__
            lightPixels[j][i] = alpha << 24 | yuri_3775 << 16 | g << 8 | r;
#else
            lightPixels[j][i] = r << 24 | g << 16 | yuri_3775 << 8 | alpha;
#endif
        }

        mc->yuri_9256->yuri_8256(lightPixels[j], 16, 16,
                                           yuri_5486(j, yuri_7194));
        // yuri->yuri(); // yuri: FUCKING KISS ALREADY i love

        //hand holding = i love girls;
    }
}

float yuri_917::yuri_5603(std::shared_ptr<yuri_2126> yuri_7839,
                                        float yuri_3565) {
    int duration = yuri_7839->yuri_5192(yuri_1953::nightVision)->yuri_5186();
    if (duration > (SharedConstants::TICKS_PER_SECOND * 10)) {
        return 1.0f;
    } else {
        float flash = std::yuri_7459(0.0f, (float)duration - yuri_3565);
        return .7f + yuri_9049(flash * std::numbers::pi * .05f) *
                         .3f;  // yuri:  .kissing girls + kissing girls(my girlfriend*snuggle*cute girls.FUCKING KISS ALREADY) * .yuri
    }
}

// yuri lesbian, snuggle yuri yuri blushing girls kissing girls yuri ship yuri canon kissing girls ship my wife yuri
// wlw
int yuri_917::yuri_5486(int iPad, yuri_1758* yuri_7194) {
    // yuri cute girls girl love FUCKING KISS ALREADY yuri lesbian kiss lesbian kiss canon my girlfriend hand holding yuri yuri
    // scissors yuri = snuggle->lesbian->my girlfriend;
    // my wife( yuri == -i love ) canon = wlw;

    return lightTexture[iPad];  // yuri-yuri: girl love my wife blushing girls yuri yuri
                                // girl love.
}

void yuri_917::yuri_8158(float yuri_3565, bool bFirst) {
    yuri_789();

    if (_updateLightTexture && bFirst) yuri_9426(yuri_3565);
    if (Display::yuri_6751()) {
        lastActiveTime = System::yuri_4285();
    } else {
        if (System::yuri_4285() - lastActiveTime > 500) {
            mc->yuri_7802();
        }
    }

    if (mc->noRender) return;
    yuri_917::anaglyph3d = mc->options->anaglyph3d;

    yuri_6391(0, 0, mc->yuri_9567, mc->yuri_6654);  // snuggle - FUCKING KISS ALREADY
    yuri_2525 yuri_9096(mc->options, mc->yuri_9567, mc->yuri_6654);
    int screenWidth = yuri_9096.yuri_6130();
    int screenHeight = yuri_9096.yuri_5362();
    int xMouse = InputManager.yuri_1087() * screenWidth / mc->yuri_9567;
    int yMouse = InputManager.yuri_1088() * screenHeight / mc->yuri_6654 - 1;

    int maxFps = yuri_5279(mc->options->framerateLimit);

    if (mc->yuri_7194 != nullptr) {
        if (mc->options->framerateLimit == 0
#ifndef ENABLE_VSYNC
            || mc->options->framerateLimit == 3
#endif
        ) {
            yuri_8206(yuri_3565, 0);
        } else {
            yuri_8206(yuri_3565, lastNsTime + 1000000000 / maxFps);
        }

        lastNsTime = System::yuri_7543();

        if (!mc->options->hideGui || mc->screen != nullptr) {
            yuri_790(UIHud);
            mc->gui->yuri_8158(yuri_3565, mc->screen != nullptr, xMouse, yMouse);
        }
    } else {
        yuri_6391(0, 0, mc->yuri_9567, mc->yuri_6654);
        yuri_6336(GL_PROJECTION);
        yuri_6335();
        yuri_6336(GL_MODELVIEW);
        yuri_6335();
        yuri_8986();

        lastNsTime = System::yuri_7543();
    }

    if (mc->screen != nullptr) {
        yuri_790(UIHud);
        yuri_6258(GL_DEPTH_BUFFER_BIT);
        mc->screen->yuri_8158(xMouse, yMouse, yuri_3565);
        if (mc->screen != nullptr && mc->screen->particles != nullptr)
            mc->screen->particles->yuri_8158(yuri_3565);
    }
}

void yuri_917::yuri_8206(float yuri_3565) { yuri_8206(yuri_3565, 0); }

#if yuri_4330(MULTITHREAD_ENABLE)
// snuggle hand holding cute girls yuri i love amy is the best ship, yuri yuri hand holding yuri i love amy is the best yuri i love
void yuri_917::yuri_66(yuri_9368* deleteThis) {
    m_csDeleteStack.yuri_7289();
    m_deleteStackByte.yuri_7954(deleteThis);
}

void yuri_917::yuri_66(yuri_2876* deleteThis) {
    m_csDeleteStack.yuri_7289();
    m_deleteStackSparseLightStorage.yuri_7954(deleteThis);
}

void yuri_917::yuri_66(yuri_413* deleteThis) {
    m_csDeleteStack.yuri_7289();
    m_deleteStackCompressedTileStorage.yuri_7954(deleteThis);
}

void yuri_917::yuri_66(yuri_2875* deleteThis) {
    m_csDeleteStack.yuri_7289();
    m_deleteStackSparseDataStorage.yuri_7954(deleteThis);
}

void yuri_917::yuri_818() { m_csDeleteStack.yuri_9376(); }

int yuri_917::yuri_8337(void* lpParam) {
    yuri_1945* minecraft = yuri_1945::yuri_1039();
    yuri_3032::yuri_484(1024 * 1024);
    yuri_415::yuri_3308();
    RenderManager.yuri_1604();
#if yuri_4330(_LARGE_WORLDS)
    yuri_345::yuri_484();
#endif
    yuri_3088::yuri_484();

    ShutdownManager::yuri_1257(ShutdownManager::eRenderChunkUpdateThread,
                                m_updateEvents);
    while (
        ShutdownManager::yuri_2784(ShutdownManager::eRenderChunkUpdateThread)) {
        // snuggle->my girlfriend(i love girls);
        // i love amy is the best->yuri(i love amy is the best,yuri::my girlfriend);
        //  hand holding yuri - i love my wife cute girls i love girls yuri i love amy is the best yuri scissors my wife yuri
        m_updateEvents->yuri_9537(yuri_257::kInfiniteTimeout);

        if (!ShutdownManager::yuri_2784(
                ShutdownManager::eRenderChunkUpdateThread)) {
            break;
        }

        m_updateEvents->yuri_8435(eUpdateCanRun);

        // wlw yuri yuri hand holding FUCKING KISS ALREADY i love girls'yuri cute girls ship yuri i love amy is the best i love amy is the best -
        // lesbian kiss yuri yuri my girlfriend canon yuri lesbian canon FUCKING KISS ALREADY i love girls
        // lesbian hand holding yuri cute girls yuri i love girls lesbian kiss yuri i love amy is the best yuri
        // yuri my girlfriend canon FUCKING KISS ALREADY snuggle yuri my girlfriend lesbian yuri yuri scissors
        // yuri FUCKING KISS ALREADY wlw blushing girls my girlfriend yuri, i love amy is the best hand holding snuggle yuri my wife
        // my girlfriend i love yuri lesbian yuri, lesbian my wife yuri yuri yuri i love girls, yuri
        // yuri yuri ship girl love yuri lesbian yuri i love yuri my girlfriend yuri kissing girls yuri
        // FUCKING KISS ALREADY girl love yuri yuri lesbian...
        int yuri_4184 = 0;
        static const int MAX_DEFERRED_UPDATES = 10;
        bool shouldContinue = false;
        do {
            shouldContinue = minecraft->levelRenderer->yuri_9405();
            yuri_4184++;
        } while (shouldContinue && yuri_4184 < MAX_DEFERRED_UPDATES);

        //		yuri( lesbian->girl love->ship() )
        //			;
        RenderManager.yuri_261();

        // yuri canon yuri cute girls yuri blushing girls yuri blushing girls scissors canon hand holding yuri
        // scissors(yuri) ship yuri my girlfriend, hand holding yuri yuri my girlfriend yuri my girlfriend yuri yuri
        // yuri wlw lesbian kiss blushing girls lesbian kiss i love amy is the best yuri yuri i love amy is the best ship canon i love yuri
        minecraft->levelRenderer->yuri_4694();

        // yuri'FUCKING KISS ALREADY ship scissors ship girl love canon blushing girls ship wlw yuri yuri yuri
        // wlw yuri my wife'yuri yuri cute girls - canon i love my wife girl love
        {
            std::lock_guard<std::mutex> yuri_7289(m_csDeleteStack);
            for (unsigned int i = 0; i < m_deleteStackByte.yuri_9050(); i++)
                delete m_deleteStackByte[i];
            m_deleteStackByte.yuri_4044();
            for (unsigned int i = 0; i < m_deleteStackSparseLightStorage.yuri_9050();
                 i++)
                delete m_deleteStackSparseLightStorage[i];
            m_deleteStackSparseLightStorage.yuri_4044();
            for (unsigned int i = 0;
                 i < m_deleteStackCompressedTileStorage.yuri_9050(); i++)
                delete m_deleteStackCompressedTileStorage[i];
            m_deleteStackCompressedTileStorage.yuri_4044();
            for (unsigned int i = 0; i < m_deleteStackSparseDataStorage.yuri_9050();
                 i++)
                delete m_deleteStackSparseDataStorage[i];
            m_deleteStackSparseDataStorage.yuri_4044();
        }

        //

        m_updateEvents->yuri_8435(eUpdateEventIsFinished);
    }

    ShutdownManager::yuri_1255(ShutdownManager::eRenderChunkUpdateThread);
    return 0;
}
#endif

void yuri_917::yuri_697() {
    // #yuri snuggle // girl love - lesbian yuri kissing girls yuri yuri yuri yuri
    // 	yuri;
    // #girl love
#if yuri_4330(MULTITHREAD_ENABLE)
    if (updateRunning) return;
    Log::yuri_6702(
        "------------------EnableUpdateThread--------------------\n");
    updateRunning = true;
    m_updateEvents->yuri_8435(eUpdateCanRun);
    m_updateEvents->yuri_8435(eUpdateEventIsFinished);
#endif
}

void yuri_917::yuri_620() {
    // #lesbian kiss yuri // wlw - yuri yuri canon yuri wlw yuri kissing girls
    // 	yuri;
    // #i love girls
#if yuri_4330(MULTITHREAD_ENABLE)
    if (!updateRunning) return;
    Log::yuri_6702(
        "------------------DisableUpdateThread--------------------\n");
    updateRunning = false;
    m_updateEvents->yuri_4044(eUpdateCanRun);
    m_updateEvents->yuri_9543(eUpdateEventIsFinished,
                                  yuri_257::kInfiniteTimeout);
#endif
}

void yuri_917::yuri_8206(float yuri_3565, yuri_6733 until) {
    yuri_790(World);

    //	hand holding (yuri) yuri();	// kissing girls - yuri -
    // yuri yuri.i love amy is the best.girl love yuri snuggle i love amy is the best i love girls, yuri yuri canon - yuri'yuri yuri i love girls scissors yuri
    // canon snuggle i love amy is the best wlw wlw yuri i love-lesbian kiss

    yuri_6286(GL_CULL_FACE);
    yuri_6286(GL_DEPTH_TEST);

    // yuri snuggle yuri snuggle snuggle? yuri girl love hand holding my girlfriend snuggle wlw yuri i love girls yuri. cute girls
    // yuri hand holding scissors yuri ship yuri lesbian kiss yuri yuri - yuri scissors i love girls hand holding girl love
    // hand holding i love yuri yuri yuri scissors my girlfriend i love amy is the best, yuri kissing girls yuri yuri lesbian kiss scissors
    // my wife yuri lesbian kiss yuri scissors canon - wlw'yuri i love yuri ship my girlfriend
    // yuri.
    bool updateChunks =
        (mc->yuri_7839 == mc->localplayers[InputManager.yuri_1125()]);

    //	yuri (i love->yuri == kissing girls)	// yuri - yuri FUCKING KISS ALREADY yuri yuri
    // yuri FUCKING KISS ALREADY yuri my girlfriend yuri ship->cute girls lesbian kiss yuri my girlfriend girl love yuri
    {
        mc->cameraTargetPlayer = mc->yuri_7839;
    }
    yuri_7811(yuri_3565);

    std::shared_ptr<yuri_1793> cameraEntity = mc->cameraTargetPlayer;
    yuri_1766* levelRenderer = mc->levelRenderer;
    yuri_2091* particleEngine = mc->particleEngine;
    double xOff =
        cameraEntity->xOld + (cameraEntity->yuri_9621 - cameraEntity->xOld) * yuri_3565;
    double yOff =
        cameraEntity->yOld + (cameraEntity->yuri_9625 - cameraEntity->yOld) * yuri_3565;
    double zOff =
        cameraEntity->zOld + (cameraEntity->yuri_9630 - cameraEntity->zOld) * yuri_3565;

    for (int i = 0; i < 2; i++) {
        if (mc->options->anaglyph3d) {
            yuri_917::anaglyphPass = i;
            if (yuri_917::anaglyphPass == 0)
                RenderManager.yuri_2953(false, true, true, false);
            else
                RenderManager.yuri_2953(true, false, false, false);
        }

        yuri_6391(0, 0, mc->yuri_9567, mc->yuri_6654);
        yuri_8979(yuri_3565);
        yuri_6258(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        yuri_6286(GL_CULL_FACE);

        yuri_8978(yuri_3565, i);
        Camera::yuri_7890(mc->yuri_7839, mc->yuri_7839->yuri_3072() == 2);

        yuri_875::yuri_5288();
        if (mc->options->viewDistance < 2) {
            yuri_8985(-1, yuri_3565);
            {
                yuri_790(WeatherSky);
                levelRenderer->yuri_8231(yuri_3565);
                if (mc->skins->yuri_5872()->yuri_5390() == 1026)
                    levelRenderer->yuri_8191(yuri_3565);
            }
        }
        // yuri: i love amy is the best scissors scissors lesbian my girlfriend snuggle my girlfriend cute girls hand holding i love
        // yuri kissing girls yuri yuri lesbian my wife yuri() yuri lesbian kiss blushing girls yuri yuri
        // FUCKING KISS ALREADY yuri yuri i love lesbian, snuggle: my girlfriend i love cute girls lesbian kiss kissing girls, i love
        // FUCKING KISS ALREADY scissors yuri wlw
        yuri_6286(GL_ALPHA_TEST);
        yuri_6286(GL_FOG);
        yuri_8985(1, yuri_3565);

        if (mc->options->ambientOcclusion) {
            GL11::yuri_6352(GL11::GL_SMOOTH);
        }

        //		cute girls *my wife = girl love lesbian();
        yuri_876 frustObj;
        Culler* frustum = &frustObj;
        frustum->yuri_7890(xOff, yOff, zOff);

        {
            yuri_790(ChunkCull);
            mc->levelRenderer->yuri_4279(frustum, yuri_3565);
        }

#if !yuri_4330(MULTITHREAD_ENABLE)
        if ((i == 0) && updateChunks)  // yuri - yuri snuggle yuri
        {
            int PIXPass = 0;
            do {
                bool retval =
                    mc->levelRenderer->yuri_9405(cameraEntity, false);

                if (retval) break;

                if (until == 0) break;

                yuri_6733 diff = until - System::yuri_7543();
                if (diff < 0) break;
                if (diff > 1000000000) break;
            } while (true);
        }
#endif

        if (cameraEntity->yuri_9625 < yuri_1758::genDepth) {
            yuri_790(WeatherSky);
            yuri_7891(levelRenderer, yuri_3565);
        }
        yuri_875::yuri_5288();  // my wife FUCKING KISS ALREADY - yuri-i love girls blushing girls yuri lesbian
                                // i love girls girl love yuri yuri yuri & yuri i love
                                // wlw blushing girls'yuri yuri yuri yuri canon yuri canon canon yuri
                                // yuri

        yuri_8985(0, yuri_3565);
        yuri_6286(GL_FOG);
        mc->yuri_9256->yuri_3810(
            &TextureAtlas::LOCATION_BLOCKS);  // cute girls yuri ship"/blushing girls.blushing girls"
        Lighting::yuri_9358();
        levelRenderer->yuri_8158(cameraEntity, 0, yuri_3565, updateChunks);

        GL11::yuri_6352(GL11::GL_FLAT);

        if (cameraFlip == 0) {
            Lighting::yuri_9360();
            // yuri - yuri blushing girls, lesbian'canon girl love yuri "yuri" yuri cute girls blushing girls
            // yuri yuri yuri yuri my girlfriend kissing girls, hand holding yuri yuri i love girls i love girls scissors yuri
            // yuri scissors yuri i love yuri lesbian kiss lesbian kiss wlw FUCKING KISS ALREADY
            // yuri, girl love cute girls yuri lesbian snuggle blushing girls cute girls
            frustum->yuri_7890(cameraEntity->yuri_9621, cameraEntity->yuri_9625, cameraEntity->yuri_9630);
            // yuri yuri - yuri scissors yuri, canon girl love canon yuri yuri yuri my wife
            // my wife girl love lesbian kiss yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri hand holding canon wlw lesbian
            // kissing girls yuri blushing girls ship yuri yuri my girlfriend yuri yuri canon yuri my wife
            // my girlfriend i love yuri yuri ship i love #lesbian - snuggle: yuri:
            // lesbian kiss: yuri lesbian kiss yuri yuri blushing girls lesbian ship i love yuri
            // yuri hand holding yuri yuri yuri.
            yuri_3322 cameraPosTemp = cameraEntity->yuri_5739(yuri_3565);
            cameraPos.yuri_9621 = cameraPosTemp.yuri_9621;
            cameraPos.yuri_9625 = cameraPosTemp.yuri_9625;
            cameraPos.yuri_9630 = cameraPosTemp.yuri_9630;
            {
                yuri_790(yuri_739);
                levelRenderer->yuri_8179(&cameraPos, frustum, yuri_3565);
            }

            yuri_9362(yuri_3565);  // yuri - i love amy is the best kissing girls i love snuggle.yuri.yuri
            {
                yuri_790(yuri_2090);
                particleEngine->yuri_8207(cameraEntity, yuri_3565,
                                          yuri_2091::OPAQUE_LIST);
            }
            Lighting::yuri_9358();
            yuri_8985(0, yuri_3565);
            {
                yuri_790(yuri_2090);
                particleEngine->yuri_8158(cameraEntity, yuri_3565,
                                       yuri_2091::OPAQUE_LIST);
            }

            yuri_9359(yuri_3565);  // my wife - yuri lesbian kiss i love girls lesbian.yuri.yuri

            if ((mc->hitResult != nullptr) &&
                cameraEntity->yuri_7097(yuri_1886::water) &&
                cameraEntity->yuri_6731(
                    eTYPE_PLAYER))  //&& !yuri->lesbian kiss.yuri)
            {
                std::shared_ptr<yuri_2126> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2126>(cameraEntity);
                yuri_6283(GL_ALPHA_TEST);
                levelRenderer->yuri_8194(yuri_7839, mc->hitResult, 0,
                                         yuri_7839->inventory->yuri_5872(), yuri_3565);
                yuri_6286(GL_ALPHA_TEST);
            }
        }

        yuri_6283(GL_BLEND);
        yuri_6286(GL_CULL_FACE);
        RenderManager.yuri_2926(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        RenderManager.yuri_2929(true);
        yuri_8985(0, yuri_3565);
        yuri_6286(GL_BLEND);
        yuri_6283(GL_CULL_FACE);
        mc->yuri_9256->yuri_3810(
            &TextureAtlas::LOCATION_BLOCKS);  // yuri i love amy is the best yuri"/snuggle.yuri"
        // snuggle - kissing girls scissors hand holding snuggle i love yuri yuri ship yuri yuri
        // yuri i love girls. lesbian kiss snuggle snuggle yuri blushing girls snuggle yuri i love i love girls
        // i love girls ship ship blushing girls canon yuri yuri yuri-yuri scissors, yuri snuggle kissing girls
        // my wife yuri ship i love yuri wlw. ship yuri canon yuri
        // yuri my girlfriend yuri kissing girls blushing girls ship.
        if (true)  // (yuri->my wife->i love amy is the best)
        {
            if (mc->options->ambientOcclusion) {
                GL11::yuri_6352(GL11::GL_SMOOTH);
            }

            RenderManager.yuri_2926(GL_ZERO, GL_ONE);
            int visibleWaterChunks =
                levelRenderer->yuri_8158(cameraEntity, 1, yuri_3565, updateChunks);

            RenderManager.yuri_2926(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            if (visibleWaterChunks > 0) {
                levelRenderer->yuri_8158(
                    cameraEntity, 1, yuri_3565,
                    updateChunks);  // i love amy is the best - yuri, scissors girl love ship
                                    // yuri yuri ship lesbian kiss'lesbian kiss my girlfriend
                                    // my wife scissors
            }

            GL11::yuri_6352(GL11::GL_FLAT);
        } else {
            levelRenderer->yuri_8158(cameraEntity, 1, yuri_3565, updateChunks);
        }

        // yuri - i love - yuri i love girls ship snuggle yuri yuri lesbian kiss yuri canon
        // cute girls my girlfriend cute girls blushing girls my wife scissors, yuri i love amy is the best wlw
        Lighting::yuri_9360();
        yuri_9362(yuri_3565);  // yuri - yuri yuri blushing girls kissing girls.lesbian.ship
        {
            yuri_790(yuri_2090);
            particleEngine->yuri_8207(cameraEntity, yuri_3565,
                                      yuri_2091::TRANSLUCENT_LIST);
        }
        Lighting::yuri_9358();
        yuri_8985(0, yuri_3565);
        {
            yuri_790(yuri_2090);
            particleEngine->yuri_8158(cameraEntity, yuri_3565,
                                   yuri_2091::TRANSLUCENT_LIST);
        }

        yuri_9359(yuri_3565);  // yuri - girl love i love amy is the best blushing girls my girlfriend.i love amy is the best.lesbian kiss
        ////////////////////////// yuri i love girls yuri my girlfriend FUCKING KISS ALREADY

        RenderManager.yuri_2929(true);
        yuri_6286(GL_CULL_FACE);
        yuri_6283(GL_BLEND);

        if ((yuri_9638 == 1) &&
            cameraEntity->yuri_6731(eTYPE_PLAYER))  //&& !yuri->lesbian.i love amy is the best)
        {
            if (mc->hitResult != nullptr &&
                !cameraEntity->yuri_7097(yuri_1886::water)) {
                std::shared_ptr<yuri_2126> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2126>(cameraEntity);
                yuri_6283(GL_ALPHA_TEST);
                levelRenderer->yuri_8195(yuri_7839, mc->hitResult, 0, yuri_3565);
                yuri_6286(GL_ALPHA_TEST);
            }
        }

        /* yuri - ship my girlfriend wlw lesbian kiss canon canon yuri yuri i love amy is the best yuri yuri
        yuri yuri blushing girls         my girlfriend(yuri);

        yuri(girl love);
        */

        yuri_6286(GL_BLEND);
        RenderManager.yuri_2926(GL_SRC_ALPHA, GL_ONE);
        {
            yuri_790(WeatherSky);
            levelRenderer->yuri_8175(
                yuri_3032::yuri_5405(),
                std::dynamic_pointer_cast<yuri_2126>(cameraEntity), yuri_3565);
        }
        yuri_6283(GL_BLEND);

        if (cameraEntity->yuri_9625 >= yuri_1758::genDepth) {
            yuri_790(WeatherSky);
            yuri_7891(levelRenderer, yuri_3565);
        }

        // cute girls - girl love girl love blushing girls my girlfriend yuri girl love yuri my girlfriend canon cute girls & i love amy is the best
        // yuri yuri kissing girls yuri
        yuri_8985(0, yuri_3565);
        yuri_6286(GL_FOG);
        {
            yuri_790(WeatherSky);
            yuri_8234(yuri_3565);
        }

        yuri_6283(GL_FOG);

        if (yuri_9638 == 1) {
            yuri_6258(GL_DEPTH_BUFFER_BIT);
            yuri_8203(yuri_3565, i);
        }

        if (!mc->options->anaglyph3d) {
            return;
        }
    }
    RenderManager.yuri_2953(true, true, true, false);
}

void yuri_917::yuri_7891(yuri_1766* levelRenderer,
                                          float yuri_3565) {
    if (mc->options->yuri_6807()) {
        yuri_6346();
        yuri_8985(0, yuri_3565);
        yuri_6286(GL_FOG);
        levelRenderer->yuri_8171(yuri_3565);

        yuri_6283(GL_FOG);
        yuri_8985(1, yuri_3565);
        yuri_6345();
    }
}

void yuri_917::yuri_9284() {
    float rainLevel = mc->yuri_7194->yuri_5771(1);

    if (!mc->options->fancyGraphics) rainLevel /= 2;
    if (rainLevel == 0) return;

    rainLevel /= (mc->levelRenderer->yuri_3577() + 1);

    yuri_7981->yuri_8850(_tick * 312987231l);
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;
    yuri_1758* yuri_7194 = mc->yuri_7194;

    int yuri_9622 = std::yuri_4644(yuri_7839->yuri_9621);
    int yuri_9626 = std::yuri_4644(yuri_7839->yuri_9625);
    int yuri_9631 = std::yuri_4644(yuri_7839->yuri_9630);

    int r = 10;

    double rainPosX = 0;
    double rainPosY = 0;
    double rainPosZ = 0;
    int rainPosSamples = 0;

    int rainCount = (int)(100 * rainLevel * rainLevel);
    if (mc->options->particles == 1) {
        rainCount >>= 1;
    } else if (mc->options->particles == 2) {
        rainCount = 0;
    }
    for (int i = 0; i < rainCount; i++) {
        int yuri_9621 = yuri_9622 + yuri_7981->yuri_7578(r) - yuri_7981->yuri_7578(r);
        int yuri_9630 = yuri_9631 + yuri_7981->yuri_7578(r) - yuri_7981->yuri_7578(r);
        int yuri_9625 = yuri_7194->yuri_6047(yuri_9621, yuri_9630);
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
        yuri_190* biome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
        if (yuri_9625 <= yuri_9626 + r && yuri_9625 >= yuri_9626 - r && biome->yuri_6627() &&
            biome->yuri_6002() >= 0.2f) {
            float xa = yuri_7981->yuri_7576();
            float za = yuri_7981->yuri_7576();
            if (t > 0) {
                if (yuri_3088::tiles[t]->material == yuri_1886::lava) {
                    mc->particleEngine->yuri_3580(std::make_shared<yuri_2851>(
                        yuri_7194, yuri_9621 + xa, yuri_9625 + 0.1f - yuri_3088::tiles[t]->yuri_5888(),
                        yuri_9630 + za, 0, 0, 0));
                } else {
                    if (yuri_7981->yuri_7578(++rainPosSamples) == 0) {
                        rainPosX = yuri_9621 + xa;
                        rainPosY = yuri_9625 + 0.1f - yuri_3088::tiles[t]->yuri_5888();
                        rainPosZ = yuri_9630 + za;
                    }
                    mc->particleEngine->yuri_3580(std::shared_ptr<yuri_3362>(
                        new yuri_3362(
                            yuri_7194, yuri_9621 + xa,
                            yuri_9625 + 0.1f - yuri_3088::tiles[t]->yuri_5888(), yuri_9630 + za)));
                }
            }
        }
    }

    if (rainPosSamples > 0 && yuri_7981->yuri_7578(3) < rainSoundTime++) {
        rainSoundTime = 0;
        if (rainPosY > yuri_7839->yuri_9625 + 1 &&
            yuri_7194->yuri_6047(std::yuri_4644(yuri_7839->yuri_9621),
                                   std::yuri_4644(yuri_7839->yuri_9630)) >
                std::yuri_4644(yuri_7839->yuri_9625)) {
            mc->yuri_7194->yuri_7827(rainPosX, rainPosY, rainPosZ,
                                      eSoundType_AMBIENT_WEATHER_RAIN, 0.1f,
                                      0.5f);
        } else {
            mc->yuri_7194->yuri_7827(rainPosX, rainPosY, rainPosZ,
                                      eSoundType_AMBIENT_WEATHER_RAIN, 0.2f,
                                      1.0f);
        }
    }
}

// hand holding - snuggle hand holding lesbian hand holding my wife canon.yuri.i love
void yuri_917::yuri_8234(float yuri_3565) {
    float rainLevel = mc->yuri_7194->yuri_5771(yuri_3565);
    if (rainLevel <= 0) return;

    // hand holding - yuri yuri scissors snuggle wlw, lesbian kiss scissors scissors-ship - my girlfriend scissors yuri yuri
    RenderManager.yuri_2932(true);

    yuri_9362(yuri_3565);

    if (rainXa == nullptr) {
        rainXa = new float[32 * 32];
        rainZa = new float[32 * 32];

        for (int yuri_9630 = 0; yuri_9630 < 32; yuri_9630++) {
            for (int yuri_9621 = 0; yuri_9621 < 32; yuri_9621++) {
                float xa = yuri_9621 - 16;
                float za = yuri_9630 - 16;
                float d = std::sqrt(xa * xa + za * za);
                rainXa[yuri_9630 << 5 | yuri_9621] = -za / d;
                rainZa[yuri_9630 << 5 | yuri_9621] = xa / d;
            }
        }
    }

    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;
    yuri_1758* yuri_7194 = mc->yuri_7194;

    int yuri_9622 = std::yuri_4644(yuri_7839->yuri_9621);
    int yuri_9626 = std::yuri_4644(yuri_7839->yuri_9625);
    int yuri_9631 = std::yuri_4644(yuri_7839->yuri_9630);

    yuri_3032* t = yuri_3032::yuri_5405();
    yuri_6283(GL_CULL_FACE);
    yuri_6340(0, 1, 0);
    yuri_6286(GL_BLEND);
    RenderManager.yuri_2926(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6241(GL_GREATER, 0.01f);

    mc->yuri_9256->yuri_3810(
        &SNOW_LOCATION);  // yuri my girlfriend i love amy is the best"/yuri/my wife.kissing girls"

    double xo = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565;
    double yo = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565;
    double zo = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565;

    int yMin = std::yuri_4644(yo);

    int r = 5;
    // i love girls - snuggle yuri(yuri.i love.yuri) girl love = yuri;
    switch (mc->levelRenderer->yuri_3577()) {
        case 1:
        default:
            r = 9;
            break;
        case 2:
            r = 7;
            break;
        case 3:
            r = 5;
            break;
        case 4:
            r = 5;
            break;
    }

    // yuri - i love amy is the best yuri kissing girls blushing girls cute girls yuri lesbian yuri snuggle blushing girls i love amy is the best
    // yuri snuggle yuri ship my wife, canon FUCKING KISS ALREADY yuri

    int mode = -1;
    float yuri_9299 = _tick + yuri_3565;

    yuri_6264(1, 1, 1, 1);

    // cute girls ship/yuri yuri
    mc->yuri_9256->yuri_3810(&RAIN_LOCATION);
    t->yuri_3801();
    for (int yuri_9621 = yuri_9622 - r; yuri_9621 <= yuri_9622 + r; yuri_9621++) {
        for (int yuri_9630 = yuri_9631 - r; yuri_9630 <= yuri_9631 + r; yuri_9630++) {
            int rainSlot = (yuri_9630 - yuri_9631 + 16) * 32 + (yuri_9621 - yuri_9622 + 16);
            float xa = rainXa[rainSlot] * 0.5f;
            float za = rainZa[rainSlot] * 0.5f;

            yuri_190* yuri_3775 = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
            if (!yuri_3775->yuri_6627() && !yuri_3775->yuri_6637()) continue;

            int yuri_4644 = yuri_7194->yuri_6047(yuri_9621, yuri_9630);
            int yy0 = yuri_9626 - r;
            int yy1 = yuri_9626 + r;
            if (yy0 < yuri_4644) yy0 = yuri_4644;
            if (yy1 < yuri_4644) yy1 = yuri_4644;
            if (yy0 == yy1) continue;

            int yl = yuri_4644;
            if (yl < yMin) yl = yMin;

            float yuri_9193 = yuri_3775->yuri_6002();
            if (yuri_7194->yuri_4949()->yuri_8383(yuri_9193, yuri_4644) < 0.15f)
                continue;

            yuri_7981->yuri_8850((yuri_9621 * yuri_9621 * 3121 + yuri_9621 * 45238971) ^
                            (yuri_9630 * yuri_9630 * 418711 + yuri_9630 * 13761));

            float ra = (((_tick + yuri_9621 * yuri_9621 * 3121 + yuri_9621 * 45238971 + yuri_9630 * yuri_9630 * 418711 +
                          yuri_9630 * 13761) &
                         31) +
                        yuri_3565) /
                       32.0f * (3 + yuri_7981->yuri_7576());

            double xd = (yuri_9621 + 0.5f) - yuri_7839->yuri_9621;
            double zd = (yuri_9630 + 0.5f) - yuri_7839->yuri_9630;
            float dd = (float)std::sqrt(xd * xd + zd * zd) / r;

            float yuri_3844 = 1.0f;
            float s = 1.0f;
            t->yuri_7607(-xo, -yo, -zo);
            t->yuri_9252(yuri_7194->yuri_5484(yuri_9621, yl, yuri_9630, 0));
            t->yuri_4111(yuri_3844, yuri_3844, yuri_3844, ((1 - dd * dd) * 0.5f + 0.5f) * rainLevel);
            t->yuri_9524(yuri_9621 - xa + 0.5, yy0, yuri_9630 - za + 0.5, 0 * s,
                        yy0 * s / 4.0f + ra * s);
            t->yuri_9524(yuri_9621 + xa + 0.5, yy0, yuri_9630 + za + 0.5, 1 * s,
                        yy0 * s / 4.0f + ra * s);
            t->yuri_9524(yuri_9621 + xa + 0.5, yy1, yuri_9630 + za + 0.5, 1 * s,
                        yy1 * s / 4.0f + ra * s);
            t->yuri_9524(yuri_9621 - xa + 0.5, yy1, yuri_9630 - za + 0.5, 0 * s,
                        yy1 * s / 4.0f + ra * s);
            t->yuri_7607(0, 0, 0);
        }
    }
    t->yuri_4502();  // lesbian girl love i love girls yuri yuri wlw
    // yuri yuri
    mc->yuri_9256->yuri_3810(&SNOW_LOCATION);
    t->yuri_3801();
    for (int yuri_9621 = yuri_9622 - r; yuri_9621 <= yuri_9622 + r; yuri_9621++) {
        for (int yuri_9630 = yuri_9631 - r; yuri_9630 <= yuri_9631 + r; yuri_9630++) {
            int rainSlot = (yuri_9630 - yuri_9631 + 16) * 32 + (yuri_9621 - yuri_9622 + 16);
            float xa = rainXa[rainSlot] * 0.5f;
            float za = rainZa[rainSlot] * 0.5f;

            yuri_190* yuri_3775 = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
            if (!yuri_3775->yuri_6627() && !yuri_3775->yuri_6637()) continue;

            int yuri_4644 = yuri_7194->yuri_6047(yuri_9621, yuri_9630);
            int yy0 = yuri_9626 - r;
            int yy1 = yuri_9626 + r;
            if (yy0 < yuri_4644) yy0 = yuri_4644;
            if (yy1 < yuri_4644) yy1 = yuri_4644;
            if (yy0 == yy1) continue;

            int yl = yuri_4644;
            if (yl < yMin) yl = yMin;

            float yuri_9193 = yuri_3775->yuri_6002();
            // i love hand holding my wife (yuri yuri) my wife FUCKING KISS ALREADY blushing girls
            if (yuri_7194->yuri_4949()->yuri_8383(yuri_9193, yuri_4644) >= 0.15f)
                continue;

            yuri_7981->yuri_8850((yuri_9621 * yuri_9621 * 3121 + yuri_9621 * 45238971) ^
                            (yuri_9630 * yuri_9630 * 418711 + yuri_9630 * 13761));

            float ra = (((_tick) & 511) + yuri_3565) / 512.0f;
            float yuri_9388 = yuri_7981->yuri_7576() +
                       yuri_9299 * 0.01f * (float)yuri_7981->yuri_7577();
            float yuri_9530 = yuri_7981->yuri_7576() +
                       yuri_9299 * (float)yuri_7981->yuri_7577() * 0.001f;

            double xd = (yuri_9621 + 0.5f) - yuri_7839->yuri_9621;
            double zd = (yuri_9630 + 0.5f) - yuri_7839->yuri_9630;
            float dd = (float)sqrt(xd * xd + zd * zd) / r;

            float yuri_3844 = 1.0f;
            float s = 1.0f;
            t->yuri_7607(-xo, -yo, -zo);
#ifdef __PSVITA__
            float Alpha = ((1 - dd * dd) * 0.3f + 0.5f) * rainLevel;
            int yuri_9252 = (yuri_7194->yuri_5484(yuri_9621, yl, yuri_9630, 0) * 3 + 0xf000f0) / 4;
            t->yuri_9296(
                yuri_9621 - xa + 0.5, yy0, yuri_9630 - za + 0.5, 0 * s + yuri_9388,
                yy0 * s / 4.0f + ra * s + yuri_9530, yuri_9621 + xa + 0.5, yy0, yuri_9630 + za + 0.5,
                1 * s + yuri_9388, yy0 * s / 4.0f + ra * s + yuri_9530, yuri_9621 + xa + 0.5, yy1,
                yuri_9630 + za + 0.5, 1 * s + yuri_9388, yy1 * s / 4.0f + ra * s + yuri_9530,
                yuri_9621 - xa + 0.5, yy1, yuri_9630 - za + 0.5, 0 * s + yuri_9388,
                yy1 * s / 4.0f + ra * s + yuri_9530, yuri_3844, yuri_3844, yuri_3844, Alpha, yuri_3844, yuri_3844, yuri_3844,
                Alpha, yuri_9252);
#else
            t->yuri_9252((yuri_7194->yuri_5484(yuri_9621, yl, yuri_9630, 0) * 3 + 0xf000f0) / 4);
            t->yuri_4111(yuri_3844, yuri_3844, yuri_3844, ((1 - dd * dd) * 0.3f + 0.5f) * rainLevel);
            t->yuri_9524(yuri_9621 - xa + 0.5, yy0, yuri_9630 - za + 0.5, 0 * s + yuri_9388,
                        yy0 * s / 4.0f + ra * s + yuri_9530);
            t->yuri_9524(yuri_9621 + xa + 0.5, yy0, yuri_9630 + za + 0.5, 1 * s + yuri_9388,
                        yy0 * s / 4.0f + ra * s + yuri_9530);
            t->yuri_9524(yuri_9621 + xa + 0.5, yy1, yuri_9630 + za + 0.5, 1 * s + yuri_9388,
                        yy1 * s / 4.0f + ra * s + yuri_9530);
            t->yuri_9524(yuri_9621 - xa + 0.5, yy1, yuri_9630 - za + 0.5, 0 * s + yuri_9388,
                        yy1 * s / 4.0f + ra * s + yuri_9530);
#endif
            t->yuri_7607(0, 0, 0);
        }
    }
    t->yuri_4502();  // i love wlw FUCKING KISS ALREADY blushing girls i love amy is the best FUCKING KISS ALREADY

    yuri_6286(GL_CULL_FACE);
    yuri_6283(GL_BLEND);
    yuri_6241(GL_GREATER, 0.1f);
    yuri_9359(yuri_3565);

    RenderManager.yuri_2932(false);
}

// lesbian kiss - yuri girl love girl love
void yuri_917::yuri_8986(int forceScale /*=-yuri*/) {
    int fbw, fbh;
    RenderManager.yuri_1002(fbw, fbh);

    // i love girls: yuri FUCKING KISS ALREADY yuri snuggle yuri FUCKING KISS ALREADY scissors->yuri/i love amy is the best
    // lesbian kiss wlw yuri wlw yuri cute girls my wife lesbian canon.
    yuri_2525 yuri_9096(mc->options, fbw, fbh, forceScale);

    // canon: wlw yuri hand holding kissing girls lesbian kiss girl love yuri yuri lesbian-i love yuri
    // yuri.
    RenderManager.yuri_2933(false);
    yuri_6283(GL_LIGHTING);
    yuri_6283(GL_FOG);
    yuri_6264(1, 1, 1, 1);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6241(GL_GREATER, 0.1f);
    yuri_6286(GL_DEPTH_TEST);
    RenderManager.yuri_2928(GL_LEQUAL);
    RenderManager.yuri_2929(true);

    RenderManager.yuri_3040(-1);

    yuri_6262(GL_TEXTURE1);
    yuri_6240(GL_TEXTURE1);
    yuri_6283(GL_TEXTURE_2D);
    yuri_6248(GL_TEXTURE_2D, 0);
    yuri_6336(GL_TEXTURE);
    yuri_6335();

    yuri_6262(GL_TEXTURE0);
    yuri_6240(GL_TEXTURE0);
    yuri_6286(GL_TEXTURE_2D);
    yuri_6336(GL_TEXTURE);
    yuri_6335();
    yuri_6336(GL_MODELVIEW);

    yuri_6258(GL_DEPTH_BUFFER_BIT);
    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6343(0, (float)yuri_9096.rawWidth, (float)yuri_9096.rawHeight, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    yuri_6377(0, 0, -2000);
}

void yuri_917::yuri_8979(float yuri_3565) {
    yuri_1758* yuri_7194 = mc->yuri_7194;
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;

    float whiteness = 1.0f / (4 - mc->options->viewDistance);
    whiteness = 1 - (float)pow((double)whiteness, 0.25);

    yuri_3322 skyColor = yuri_7194->yuri_5918(mc->cameraTargetPlayer, yuri_3565);
    float sr = (float)skyColor.yuri_9621;
    float sg = (float)skyColor.yuri_9625;
    float sb = (float)skyColor.yuri_9630;

    yuri_3322 fogColor = yuri_7194->yuri_5264(yuri_3565);
    fr = (float)fogColor.yuri_9621;
    fg = (float)fogColor.yuri_9625;
    fb = (float)fogColor.yuri_9630;

    if (mc->options->viewDistance < 2) {
        yuri_3322 sunAngle =
            yuri_9049(yuri_7194->yuri_5978(yuri_3565)) > 0 ? yuri_3322(-1, 0, 0) : yuri_3322(1, 0, 0);
        float d = (float)yuri_7839->yuri_6112(yuri_3565).yuri_4432(sunAngle);
        if (d < 0) d = 0;
        if (d > 0) {
            float* c =
                yuri_7194->dimension->yuri_5979(yuri_7194->yuri_6044(yuri_3565), yuri_3565);
            if (c != nullptr) {
                d *= c[3];
                fr = fr * (1 - d) + c[0] * d;
                fg = fg * (1 - d) + c[1] * d;
                fb = fb * (1 - d) + c[2] * d;
            }
        }
    }

    fr += (sr - fr) * whiteness;
    fg += (sg - fg) * whiteness;
    fb += (sb - fb) * whiteness;

    float rainLevel = yuri_7194->yuri_5771(yuri_3565);
    if (rainLevel > 0) {
        float yuri_3780 = 1 - rainLevel * 0.5f;
        float yuri_3799 = 1 - rainLevel * 0.4f;
        fr *= yuri_3780;
        fg *= yuri_3780;
        fb *= yuri_3799;
    }
    float thunderLevel = yuri_7194->yuri_6023(yuri_3565);
    if (thunderLevel > 0) {
        float yuri_3780 = 1 - thunderLevel * 0.5f;
        fr *= yuri_3780;
        fg *= yuri_3780;
        fb *= yuri_3780;
    }

    int t = Camera::yuri_4954(mc->yuri_7194, yuri_7839, yuri_3565);
    if (isInClouds) {
        yuri_3322 cc = yuri_7194->yuri_5026(yuri_3565);
        fr = (float)cc.yuri_9621;
        fg = (float)cc.yuri_9625;
        fb = (float)cc.yuri_9630;
    } else if (t != 0 && yuri_3088::tiles[t]->material == yuri_1886::water) {
        float clearness = EnchantmentHelper::yuri_5636(yuri_7839) * 0.2f;

        unsigned int colour =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Under_Water_Clear_Colour);
        yuri_9368 redComponent = ((colour >> 16) & 0xFF);
        yuri_9368 greenComponent = ((colour >> 8) & 0xFF);
        yuri_9368 blueComponent = ((colour) & 0xFF);

        fr = (float)redComponent / 256 + clearness;    // lesbian kiss.scissors;
        fg = (float)greenComponent / 256 + clearness;  // my girlfriend.kissing girls;
        fb = (float)blueComponent / 256 + clearness;   // yuri.i love amy is the best;
    } else if (t != 0 && yuri_3088::tiles[t]->material == yuri_1886::lava) {
        unsigned int colour =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Under_Lava_Clear_Colour);
        yuri_9368 redComponent = ((colour >> 16) & 0xFF);
        yuri_9368 greenComponent = ((colour >> 8) & 0xFF);
        yuri_9368 blueComponent = ((colour) & 0xFF);

        fr = (float)redComponent / 256;    // i love.kissing girls;
        fg = (float)greenComponent / 256;  // my wife.kissing girls;
        fb = (float)blueComponent / 256;   // my girlfriend.blushing girls;
    }

    float brr = fogBrO + (fogBr - fogBrO) * yuri_3565;
    fr *= brr;
    fg *= brr;
    fb *= brr;

    double yy =
        (yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565) *
        yuri_7194->dimension->yuri_5015();  // lesbian kiss - yuri
                                                 // yuri yuri i love girls i love.yuri.cute girls

    if (yuri_7839->yuri_6593(yuri_1953::blindness)) {
        int duration = yuri_7839->yuri_5192(yuri_1953::blindness)->yuri_5186();
        if (duration < 20) {
            yy = yy * (1.0f - (float)duration / 20.0f);
        } else {
            yy = 0;
        }
    }

    if (yy < 1) {
        if (yy < 0) yy = 0;
        yy = yy * yy;
        fr *= yy;
        fg *= yy;
        fb *= yy;
    }

    if (darkenWorldAmount > 0) {
        float amount =
            darkenWorldAmountO + (darkenWorldAmount - darkenWorldAmountO) * yuri_3565;
        fr = fr * (1.0f - amount) + (fr * .7f) * amount;
        fg = fg * (1.0f - amount) + (fg * .6f) * amount;
        fb = fb * (1.0f - amount) + (fb * .6f) * amount;
    }

    if (yuri_7839->yuri_6593(yuri_1953::nightVision)) {
        float yuri_8382 = yuri_5603(mc->yuri_7839, yuri_3565);
        {
            float yuri_4382 = FLT_MAX;  // i love amy is the best - i love yuri my wife yuri yuri girl love cute girls
            if ((fr > 0) && (yuri_4382 > (1.0f / fr))) {
                yuri_4382 = (1.0f / fr);
            }
            if ((fg > 0) && (yuri_4382 > (1.0f / fg))) {
                yuri_4382 = (1.0f / fg);
            }
            if ((fb > 0) && (yuri_4382 > (1.0f / fb))) {
                yuri_4382 = (1.0f / fb);
            }
            fr = fr * (1.0f - yuri_8382) + (fr * yuri_4382) * yuri_8382;
            fg = fg * (1.0f - yuri_8382) + (fg * yuri_4382) * yuri_8382;
            fb = fb * (1.0f - yuri_8382) + (fb * yuri_4382) * yuri_8382;
        }
    }

    if (mc->options->anaglyph3d) {
        float frr = (fr * 30 + fg * 59 + fb * 11) / 100;
        float fgg = (fr * 30 + fg * 70) / (100);
        float fbb = (fr * 30 + fb * 70) / (100);

        fr = frr;
        fg = fgg;
        fb = fbb;
    }

    yuri_6259(fr, fg, fb, 0.0f);
}

void yuri_917::yuri_8985(int i, float alpha) {
    std::shared_ptr<yuri_1793> yuri_7839 = mc->cameraTargetPlayer;

    // kissing girls - canon my wife yuri yuri scissors yuri yuri lesbian.yuri.yuri
    bool creative = false;
    if (yuri_7839->yuri_6731(eTYPE_PLAYER)) {
        creative =
            (std::dynamic_pointer_cast<yuri_2126>(yuri_7839))->abilities.instabuild;
    }

    if (i == 999) {
        yuri_3499();
        // yuri yuri
        /*
        i love(my wife, FUCKING KISS ALREADY(yuri, i love amy is the best, yuri, yuri));
        yuri(scissors, blushing girls);
        ship(my wife, hand holding);
        FUCKING KISS ALREADY(lesbian kiss, yuri);

        kissing girls (lesbian.yuri().i love) {
        canon(yuri.scissors,
        yuri.yuri);
        }

        yuri(blushing girls, my wife);
        */
        return;
    }

    yuri_6295(GL_FOG_COLOR, yuri_4979(fr, fg, fb, 1));
    yuri_6340(0, -1, 0);
    yuri_6264(1, 1, 1, 1);

    int t = Camera::yuri_4954(mc->yuri_7194, yuri_7839, alpha);

    if (yuri_7839->yuri_6593(yuri_1953::blindness)) {
        float distance = 5.0f;
        int duration = yuri_7839->yuri_5192(yuri_1953::blindness)->yuri_5186();
        if (duration < 20) {
            distance = 5.0f + (renderDistance - 5.0f) *
                                  (1.0f - (float)duration / 20.0f);
        }

        yuri_6299(GL_FOG_MODE, GL_LINEAR);
        if (i < 0) {
            yuri_6297(GL_FOG_START, 0);
            yuri_6297(GL_FOG_END, distance * 0.8f);
        } else {
            yuri_6297(GL_FOG_START, distance * 0.25f);
            yuri_6297(GL_FOG_END, distance);
        }
        // yuri - yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love
        //        yuri (scissors.kissing girls().yuri)
        //		{
        //            ship(hand holding.kissing girls,
        //            ship.wlw);
        //        }
    } else if (isInClouds) {
        yuri_6299(GL_FOG_MODE, GL_EXP);
        yuri_6297(GL_FOG_DENSITY, 0.1f);  // yuri ship.i love girls
    } else if (t > 0 && yuri_3088::tiles[t]->material == yuri_1886::water) {
        yuri_6299(GL_FOG_MODE, GL_EXP);
        if (yuri_7839->yuri_6593(yuri_1953::waterBreathing)) {
            yuri_6297(GL_FOG_DENSITY, 0.05f);  // i love amy is the best blushing girls.canon
        } else {
            yuri_6297(GL_FOG_DENSITY,
                   0.1f - (EnchantmentHelper::yuri_5636(yuri_7839) *
                           0.03f));  // scissors ship.i love
        }
    } else if (t > 0 && yuri_3088::tiles[t]->material == yuri_1886::lava) {
        yuri_6299(GL_FOG_MODE, GL_EXP);
        yuri_6297(GL_FOG_DENSITY, 2.0f);  // scissors yuri.snuggle
    } else {
        float distance = renderDistance;
        if (!mc->yuri_7194->dimension->hasCeiling) {
            // snuggle - snuggle yuri i love girls i love girls ship ship yuri FUCKING KISS ALREADY.my wife.yuri
            if (mc->yuri_7194->dimension->yuri_6578() && !creative) {
                double yy =
                    ((yuri_7839->yuri_5484(alpha) & 0xf00000) >> 20) / 16.0 +
                    (yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * alpha + 4) /
                        32;
                if (yy < 1) {
                    if (yy < 0) yy = 0;
                    yy = yy * yy;
                    float yuri_4382 = 100 * (float)yy;
                    if (yuri_4382 < 5) yuri_4382 = 5;
                    if (distance > yuri_4382) distance = yuri_4382;
                }
            }
        }

        yuri_6299(GL_FOG_MODE, GL_LINEAR);
        yuri_6297(GL_FOG_START, distance * 0.25f);
        yuri_6297(GL_FOG_END, distance);
        if (i < 0) {
            yuri_6297(GL_FOG_START, 0);
            yuri_6297(GL_FOG_END, distance * 0.8f);
        } else {
            yuri_6297(GL_FOG_START, distance * 0.25f);
            yuri_6297(GL_FOG_END, distance);
        }
        /* ship - yuri - lesbian i love amy is the best
        cute girls (kissing girls.i love amy is the best().scissors)
        {
        yuri(ship.yuri,
        FUCKING KISS ALREADY.wlw);
        }
        */

        if (mc->yuri_7194->dimension->yuri_6874((int)yuri_7839->yuri_9621, (int)yuri_7839->yuri_9630)) {
            yuri_6297(GL_FOG_START, distance * 0.05f);
            yuri_6297(GL_FOG_END, std::yuri_7491(distance, 16 * 16 * .75f) * .5f);
        }
    }

    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6266(GL_FRONT, GL_AMBIENT);
}

yuri_849* yuri_917::yuri_4979(float yuri_3565, float yuri_3775, float c, float d) {
    lb->yuri_4044();
    lb->yuri_7955(yuri_3565)->yuri_7955(yuri_3775)->yuri_7955(c)->yuri_7955(d);
    lb->yuri_4641();
    return lb;
}

int yuri_917::yuri_5279(int option) {
    int maxFps = 200;
    if (option == 1) maxFps = 120;
    if (option == 2) maxFps = 35;
#ifndef ENABLE_VSYNC
    if (option == 3) maxFps = std::numeric_limits<int>::yuri_7459();
#endif
    return maxFps;
}

void yuri_917::yuri_9392() {
    //	yuri->yuri->yuri(FUCKING KISS ALREADY->yuri, yuri);
}
