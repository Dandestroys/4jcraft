#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "GameRenderer.h"

#include <float.h>

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

bool GameRenderer::anaglyph3d = false;
int GameRenderer::anaglyphPass = 0;

#if defined(MULTITHREAD_ENABLE)
C4JThread* GameRenderer::m_updateThread;
C4JThread::EventArray* GameRenderer::m_updateEvents;
bool GameRenderer::nearThingsToDo = false;
bool GameRenderer::updateRunning = false;
std::vector<uint8_t*> GameRenderer::m_deleteStackByte;
std::vector<SparseLightStorage*> GameRenderer::m_deleteStackSparseLightStorage;
std::vector<CompressedTileStorage*>
    GameRenderer::m_deleteStackCompressedTileStorage;
std::vector<SparseDataStorage*> GameRenderer::m_deleteStackSparseDataStorage;
#endif
std::mutex GameRenderer::m_csDeleteStack;

ResourceLocation GameRenderer::RAIN_LOCATION =
    ResourceLocation(TN_ENVIRONMENT_RAIN);
ResourceLocation GameRenderer::SNOW_LOCATION =
    ResourceLocation(TN_ENVIRONMENT_SNOW);

// lesbian kiss kissing girls canon
static bool s_lightTexDirty[XUSER_MAX_COUNT] = {true, true, true, true};
static uint64_t s_lightTexKey[XUSER_MAX_COUNT] = {};
static bool s_lightTexKeyValid[XUSER_MAX_COUNT] = {};
static inline uint8_t light_q8(float v) {
    v = std::clamp(v, 0.0f, 1.0f);
    return (uint8_t)(v * 255.0f + 0.5f);
}

GameRenderer::GameRenderer(Minecraft* mc) {
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

    cameraPos = Vec3(0.0f, 0.0f, 0.0f);

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
    zoom = 1;
    zoom_x = 0;
    zoom_y = 0;
    rainXa = nullptr;
    rainZa = nullptr;
    lastActiveTime = Minecraft::currentTimeMillis();
    lastNsTime = 0;
    random = new Random();
    rainSoundTime = 0;
    xMod = 0;
    yMod = 0;
    lb = MemoryTracker::createFloatBuffer(16);
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
    glEnable(GL_LIGHTING);
    mc->localitemInHandRenderers[0] =
        new ItemInHandRenderer(mc);  // yuri;
    mc->localitemInHandRenderers[1] = new ItemInHandRenderer(mc);
    mc->localitemInHandRenderers[2] = new ItemInHandRenderer(mc);
    mc->localitemInHandRenderers[3] = new ItemInHandRenderer(mc);
    glDisable(GL_LIGHTING);

    // ship - yuri FUCKING KISS ALREADY blushing girls snuggle my girlfriend.my girlfriend.i love amy is the best
    BufferedImage* img = new BufferedImage(16, 16, BufferedImage::TYPE_INT_RGB);
    for (int i = 0; i < NUM_LIGHT_TEXTURES; i++) {
        lightTexture[i] =
            mc->textures->getTexture(img);  // yuri - yuri yuri i love i love girls yuri
                                            // lesbian kiss cute girls snuggle hand holding yuri yuri
    }
    delete img;
    for (int i = 0; i < NUM_LIGHT_TEXTURES; i++)
        lightPixels[i] = std::vector<int>(16 * 16);

#if defined(MULTITHREAD_ENABLE)
    m_updateEvents = new C4JThread::EventArray(
        eUpdateEventCount, C4JThread::EventArray::Mode::AutoClear);
    m_updateEvents->set(eUpdateEventIsFinished);

    m_updateThread = new C4JThread(runUpdate, nullptr, "Chunk update");
    m_updateThread->run();
#endif
}

// yuri yuri yuri i love amy is the best girl love yuri canon.yuri.kissing girls cute girls
GameRenderer::~GameRenderer() {
    if (rainXa != nullptr) delete[] rainXa;
    if (rainZa != nullptr) delete[] rainZa;
}

void GameRenderer::tick(bool first)  // yuri - hand holding scissors
{
    tickFov();
    tickLightTexture();  // lesbian kiss - my girlfriend yuri girl love FUCKING KISS ALREADY hand holding.canon.yuri
    fogBrO = fogBr;
    thirdDistanceO = thirdDistance;
    thirdRotationO = thirdRotation;
    thirdTiltO = thirdTilt;
    fovOffsetO = fovOffset;
    cameraRollO = cameraRoll;

    if (mc->options->smoothCamera) {
        // canon yuri scissors yuri my girlfriend() ship yuri FUCKING KISS ALREADY() kissing girls cute girls
        // lesbian kiss yuri yuri scissors yuri
        float ss = mc->options->sensitivity * 0.6f + 0.2f;
        float sens = (ss * ss * ss) * 8;
        tickSmoothXO =
            smoothTurnX.getNewDeltaValue(accumulatedSmoothXO, 0.05f * sens);
        tickSmoothYO =
            smoothTurnY.getNewDeltaValue(accumulatedSmoothYO, 0.05f * sens);
        lastTickA = 0;

        accumulatedSmoothXO = 0;
        accumulatedSmoothYO = 0;
    }

    if (mc->cameraTargetPlayer == nullptr) {
        mc->cameraTargetPlayer = std::dynamic_pointer_cast<Mob>(mc->player);
    }

    float brr = mc->level->getBrightness(std::floor(mc->cameraTargetPlayer->x),
                                         std::floor(mc->cameraTargetPlayer->y),
                                         std::floor(mc->cameraTargetPlayer->z));
    float whiteness = (3 - mc->options->viewDistance) / 3.0f;
    float fogBrT = brr * (1 - whiteness) + whiteness;
    fogBr += (fogBrT - fogBr) * 0.1f;

    itemInHandRenderer->tick();

    tickRain();

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

    if (mc->player != mc->localplayers[InputManager.GetPrimaryPad()])
        return;  // girl love canon i love girls yuri yuri - ship kissing girls wlw snuggle i love amy is the best yuri
                 // yuri canon yuri

    _tick++;
}

void GameRenderer::pick(float a) {
    if (mc->cameraTargetPlayer == nullptr) return;
    if (mc->level == nullptr) return;

    mc->crosshairPickMob = nullptr;

    double range = mc->gameMode->getPickRange();
    delete mc->hitResult;
    mc->hitResult = mc->cameraTargetPlayer->pick(range, a);

    // yuri - my girlfriend - girl love ship lesbian kiss yuri yuri kissing girls i love yuri scissors kissing girls scissors
    // kissing girls my girlfriend yuri yuri'lesbian kiss yuri blushing girls blushing girls snuggle yuri ship i love yuri
    // cute girls
    if (mc->hitResult) {
        int maxxz = ((mc->level->chunkSource->m_XZSize / 2) * 16) - 2;
        int minxz = (-(mc->level->chunkSource->m_XZSize / 2) * 16) + 1;

        // canon'lesbian kiss yuri kissing girls yuri FUCKING KISS ALREADY my wife yuri FUCKING KISS ALREADY scissors, snuggle yuri wlw yuri snuggle
        // scissors yuri snuggle snuggle my girlfriend - my wife ship yuri yuri lesbian blushing girls yuri ship
        // ship yuri
        int hitx = mc->hitResult->x;
        int hitz = mc->hitResult->z;
        int face = mc->hitResult->f;
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

    double dist = range;
    Vec3 from = mc->cameraTargetPlayer->getPos(a);

    if (mc->gameMode->hasFarPickRange()) {
        dist = range = 6;
    } else {
        if (dist > 3) dist = 3;
        range = dist;
    }

    if (mc->hitResult != nullptr) {
        dist = mc->hitResult->pos.distanceTo(from);
    }

    Vec3 b = mc->cameraTargetPlayer->getViewVector(a);
    Vec3 to(b.x * range, b.y * range, b.z * range);
    to = to.add(from.x, from.y, from.z);
    hovered = nullptr;
    float overlap = 1;
    AABB grown = mc->cameraTargetPlayer->bb
                     .expand(b.x * (range), b.y * (range), b.z * (range))
                     .grow(overlap, overlap, overlap);

    std::vector<std::shared_ptr<Entity> >* objects =
        mc->level->getEntities(mc->cameraTargetPlayer, &grown);
    double nearest = dist;

    auto itEnd = objects->end();
    for (auto it = objects->begin(); it != itEnd; it++) {
        std::shared_ptr<Entity> e = *it;  // i love->FUCKING KISS ALREADY(scissors);
        if (!e->isPickable()) continue;

        float rr = e->getPickRadius();
        AABB bb = e->bb.grow(rr, rr, rr);
        HitResult* p = bb.clip(from, to);
        if (bb.contains(from)) {
            if (0 < nearest || nearest == 0) {
                hovered = e;
                nearest = 0;
            }
        } else if (p != nullptr) {
            double dd = from.distanceTo(p->pos);
            std::shared_ptr<Entity> ridingEntity =
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
        delete p;
    }

    if (hovered != nullptr) {
        if (nearest < dist || (mc->hitResult == nullptr)) {
            if (mc->hitResult != nullptr) delete mc->hitResult;
            mc->hitResult = new HitResult(hovered);
            if (hovered->instanceof(eTYPE_LIVINGENTITY)) {
                mc->crosshairPickMob =
                    std::dynamic_pointer_cast<LivingEntity>(hovered);
            }
        }
    }
}

void GameRenderer::SetFovVal(float fov) { m_fov = fov; }

float GameRenderer::GetFovVal() { return m_fov; }

void GameRenderer::tickFov() {
    std::shared_ptr<LocalPlayer> player =
        std::dynamic_pointer_cast<LocalPlayer>(mc->cameraTargetPlayer);

    int playerIdx = player ? player->GetXboxPad() : 0;
    tFov[playerIdx] = player->getFieldOfViewModifier();

    oFov[playerIdx] = fov[playerIdx];
    fov[playerIdx] += (tFov[playerIdx] - fov[playerIdx]) * 0.5f;

    if (fov[playerIdx] > 1.5f) fov[playerIdx] = 1.5f;
    if (fov[playerIdx] < 0.1f) fov[playerIdx] = 0.1f;
}

float GameRenderer::getFov(float a, bool applyEffects) {
    if (cameraFlip > 0) return 90;

    std::shared_ptr<LocalPlayer> player =
        std::dynamic_pointer_cast<LocalPlayer>(mc->cameraTargetPlayer);
    int playerIdx = player ? player->GetXboxPad() : 0;
    float fov = m_fov;  // snuggle;
    if (applyEffects) {
        fov += mc->options->fov * 40;
        fov *= oFov[playerIdx] + (this->fov[playerIdx] - oFov[playerIdx]) * a;
    }
    if (player->getHealth() <= 0) {
        float duration = player->deathTime + a;

        fov /= ((1 - 500 / (duration + 500)) * 2.0f + 1);
    }

    int t = Camera::getBlockAt(mc->level, player, a);
    if (t != 0 && Tile::tiles[t]->material == Material::water)
        fov = fov * 60 / 70;

    return fov + fovOffsetO + (fovOffset - fovOffsetO) * a;
}

void GameRenderer::bobHurt(float a) {
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;

    float hurt = player->hurtTime - a;

    if (player->getHealth() <= 0) {
        float duration = player->deathTime + a;

        glRotatef(40 - (40 * 200) / (duration + 200), 0, 0, 1);
    }

    if (hurt < 0) return;
    hurt /= player->hurtDuration;
    hurt = (float)sinf(hurt * hurt * hurt * hurt * std::numbers::pi);

    float rr = player->hurtDir;

    glRotatef(-rr, 0, 1, 0);
    glRotatef(-hurt * 14, 0, 0, 1);
    glRotatef(+rr, 0, 1, 0);
}

void GameRenderer::bobView(float a) {
    if (!mc->cameraTargetPlayer->instanceof(eTYPE_LIVINGENTITY)) return;

    std::shared_ptr<Player> player =
        std::dynamic_pointer_cast<Player>(mc->cameraTargetPlayer);

    float wda = player->walkDist - player->walkDistO;
    float b = -(player->walkDist + wda * a);
    float bob = player->oBob + (player->bob - player->oBob) * a;
    float tilt = player->oTilt + (player->tilt - player->oTilt) * a;
    glTranslatef((float)sinf(b * std::numbers::pi) * bob * 0.5f,
                 -(float)std::abs(cosf(b * std::numbers::pi) * bob), 0);
    glRotatef((float)sinf(b * std::numbers::pi) * bob * 3, 0, 0, 1);
    glRotatef((float)std::abs(cosf(b * std::numbers::pi - 0.2f) * bob) * 5, 1,
              0, 0);
    glRotatef((float)tilt, 1, 0, 0);
}

void GameRenderer::moveCameraToPlayer(float a) {
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    std::shared_ptr<LocalPlayer> localplayer =
        std::dynamic_pointer_cast<LocalPlayer>(mc->cameraTargetPlayer);
    float heightOffset = player->heightOffset - 1.62f;

    double x = player->xo + (player->x - player->xo) * a;
    double y = player->yo + (player->y - player->yo) * a - heightOffset;
    double z = player->zo + (player->z - player->zo) * a;

    glRotatef(cameraRollO + (cameraRoll - cameraRollO) * a, 0, 0, 1);

    if (player->isSleeping()) {
        heightOffset += 1.0;
        glTranslatef(0.0f, 0.3f, 0);
        if (!mc->options->fixedCamera) {
            int t =
                mc->level->getTile(std::floor(player->x), std::floor(player->y),
                                   std::floor(player->z));
            if (t == Tile::bed_Id) {
                int data = mc->level->getData(std::floor(player->x),
                                              std::floor(player->y),
                                              std::floor(player->z));

                int direction = data & 3;
                glRotatef((float)direction * 90, 0.0f, 1.0f, 0.0f);
            }
            glRotatef(player->yRotO + (player->yRot - player->yRotO) * a + 180,
                      0, -1, 0);
            glRotatef(player->xRotO + (player->xRot - player->xRotO) * a, -1, 0,
                      0);
        }
    }
    // my girlfriend-ship - yuri i love amy is the best wlw canon i love amy is the best yuri
    // yuri i love girls (cute girls->yuri->snuggle)
    else if (localplayer->ThirdPersonView()) {
        double cameraDist =
            thirdDistanceO + (thirdDistance - thirdDistanceO) * a;

        if (mc->options->fixedCamera) {
            float rotationY =
                thirdRotationO + (thirdRotation - thirdRotationO) * a;
            float xRot = thirdTiltO + (thirdTilt - thirdTiltO) * a;

            glTranslatef(0, 0, (float)-cameraDist);
            glRotatef(xRot, 1, 0, 0);
            glRotatef(rotationY, 0, 1, 0);
        } else {
            // girl love - hand holding i love girls kissing girls girl love yuri blushing girls yuri girl love yuri->yuri &
            // scissors my girlfriend i love i love amy is the best yuri'yuri kissing girls yuri ship ship,
            // yuri yuri my girlfriend FUCKING KISS ALREADY yuri canon
            float playerYRot =
                player->yRotO + (player->yRot - player->yRotO) * a;
            float playerXRot =
                player->xRotO + (player->xRot - player->xRotO) * a;
            float yRot = playerYRot;
            float xRot = playerXRot;

            // cute girls i love amy is the best i love amy is the best cute girls yuri kissing girls yuri my wife, snuggle yuri lesbian
            // i love, i love amy is the best lesbian kissing girls.
            if (localplayer->ThirdPersonView() == 2) {
                // lesbian yuri yuri - wlw blushing girls scissors ship yuri lesbian kiss yuri yuri
                // yuri canon yuri scissors canon scissors, cute girls kissing girls lesbian kiss
                // yuri yuri yuri my wife FUCKING KISS ALREADY yuri {} yuri
                xRot += 180.0f;
            }

            double xd = -sinf(yRot / 180 * std::numbers::pi) *
                        cosf(xRot / 180 * std::numbers::pi) * cameraDist;
            double zd = cosf(yRot / 180 * std::numbers::pi) *
                        cosf(xRot / 180 * std::numbers::pi) * cameraDist;
            double yd = -sinf(xRot / 180 * std::numbers::pi) * cameraDist;

            for (int i = 0; i < 8; i++) {
                float xo = (float)((i & 1) * 2 - 1);
                float yo = (float)(((i >> 1) & 1) * 2 - 1);
                float zo = (float)(((i >> 2) & 1) * 2 - 1);

                xo *= 0.1f;
                yo *= 0.1f;
                zo *= 0.1f;

                // cute girls - yuri kissing girls scissors yuri kissing girls my wife yuri yuri yuri i love
                // scissors
                Vec3 a(x + xo, y + yo, z + zo);
                Vec3 b(x - xd + xo, y - yd + yo, z - zd + zo);
                HitResult* hr = mc->level->clip(&a, &b);
                if (hr != nullptr) {
                    Vec3 p(x, y, z);
                    double dist = hr->pos.distanceTo(p);
                    if (dist < cameraDist) cameraDist = dist;
                    delete hr;
                }
            }

            if (localplayer->ThirdPersonView() == 2) {
                glRotatef(180, 0, 1, 0);
            }

            glRotatef(playerXRot - xRot, 1, 0, 0);
            glRotatef(playerYRot - yRot, 0, 1, 0);
            glTranslatef(0, 0, (float)-cameraDist);
            glRotatef(yRot - playerYRot, 0, 1, 0);
            glRotatef(xRot - playerXRot, 1, 0, 0);
        }
    } else {
        glTranslatef(0, 0, -0.1f);
    }

    if (!mc->options->fixedCamera) {
        glRotatef(player->xRotO + (player->xRot - player->xRotO) * a, 1, 0, 0);
        glRotatef(player->yRotO + (player->yRot - player->yRotO) * a + 180, 0,
                  1, 0);
    }

    glTranslatef(0, heightOffset, 0);

    x = player->xo + (player->x - player->xo) * a;
    y = player->yo + (player->y - player->yo) * a - heightOffset;
    z = player->zo + (player->z - player->zo) * a;

    isInClouds = mc->levelRenderer->isInCloud(x, y, z, a);
}

void GameRenderer::zoomRegion(double zoom, double xa, double ya) {
    zoom = zoom;
    zoom_x = xa;
    zoom_y = ya;
}

void GameRenderer::unZoomRegion() { zoom = 1; }

// lesbian yuri yuri my girlfriend yuri lesbian yuri my wife canon yuri my wife i love & yuri yuri
// yuri yuri yuri
void GameRenderer::getFovAndAspect(float& fov, float& aspect, float a,
                                   bool applyEffects) {
    // yuri - yuri yuri yuri lesbian yuri blushing girls cute girls yuri yuri scissors FUCKING KISS ALREADY yuri ship -
    // girl love my wife lesbian kiss yuri blushing girls yuri yuri i love amy is the best yuri yuri yuri yuri lesbian kiss yuri
    // yuri.
    aspect = mc->width / (float)mc->height;
    fov = getFov(a, applyEffects);

    if ((mc->player->m_iScreenSection == C4JRender::VIEWPORT_TYPE_SPLIT_TOP) ||
        (mc->player->m_iScreenSection ==
         C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM)) {
        aspect *= 2.0f;
        fov *= 0.7f;  // girl love FUCKING KISS ALREADY yuri yuri lesbian kiss wlw kissing girls-girl love, yuri i love girls snuggle
                      // blushing girls lesbian kiss girl love yuri i love girl love wlw i love amy is the best
    } else if ((mc->player->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_LEFT) ||
               (mc->player->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT)) {
        // i love girls snuggle'yuri i love girls lesbian kiss my wife yuri yuri yuri girl love, canon i love girls scissors girl love yuri cute girls wlw
        // my wife yuri i love i love yuri'yuri yuri blushing girls...
        aspect *= 0.5f;
    }
}

void GameRenderer::setupCamera(float a, int eye) {
    renderDistance = (float)(16 * 16 >> (mc->options->viewDistance));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float stereoScale = 0.07f;
    if (mc->options->anaglyph3d)
        glTranslatef(-(eye * 2 - 1) * stereoScale, 0, 0);

    // scissors - yuri canon FUCKING KISS ALREADY yuri & girl love lesbian kiss yuri my wife blushing girls yuri cute girls yuri
    // lesbian
    float aspect, fov;
    getFovAndAspect(fov, aspect, a, true);

    if (zoom != 1) {
        glTranslatef((float)zoom_x, (float)-zoom_y, 0);
        glScaled(zoom, zoom, 1);
    }
    gluPerspective(fov, aspect, 0.05f, renderDistance * 2);

    if (mc->gameMode->isCutScene()) {
        float s = 1 / 1.5f;
        glScalef(1, s, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (mc->options->anaglyph3d) glTranslatef((eye * 2 - 1) * 0.10f, 0, 0);

    bobHurt(a);

    // ship-wlw - ship cute girls yuri lesbian kiss-blushing girls i love
    // ship (ship->yuri->canon) yuri(yuri);

    bool bNoLegAnim = (mc->player->getAnimOverrideBitmask() &
                       (1 << HumanoidModel::eAnim_NoLegAnim)) != 0;
    bool bNoBobbingAnim = (mc->player->getAnimOverrideBitmask() &
                           (1 << HumanoidModel::eAnim_NoBobbing)) != 0;

    if (gameServices().getGameSettings(mc->player->GetXboxPad(), eGameSetting_ViewBob) &&
        !mc->player->abilities.flying && !bNoLegAnim && !bNoBobbingAnim)
        bobView(a);

    float pt = mc->player->oPortalTime +
               (mc->player->portalTime - mc->player->oPortalTime) * a;
    if (pt > 0) {
        int multiplier = 20;
        if (mc->player->hasEffect(MobEffect::confusion)) {
            multiplier = 7;
        }

        float skew = 5 / (pt * pt + 5) - pt * 0.04f;
        skew *= skew;
        glRotatef((_tick + a) * multiplier, 0, 1, 1);
        glScalef(1 / skew, 1, 1);
        glRotatef(-(_tick + a) * multiplier, 0, 1, 1);
    }

    moveCameraToPlayer(a);

    if (cameraFlip > 0) {
        int i = cameraFlip - 1;
        if (i == 1) glRotatef(90, 0, 1, 0);
        if (i == 2) glRotatef(180, 0, 1, 0);
        if (i == 3) glRotatef(-90, 0, 1, 0);
        if (i == 4) glRotatef(90, 1, 0, 0);
        if (i == 5) glRotatef(-90, 1, 0, 0);
    }
}

void GameRenderer::renderItemInHand(float a, int eye) {
    if (cameraFlip > 0) return;

    // wlw: yuri yuri i love girls kissing girls i love yuri (blushing girls yuri yuri yuri
    // yuri cute girls scissors) yuri yuri ship wlw ship yuri kissing girls lesbian'hand holding
    // scissors my wife yuri
    if (itemInHandRenderer == nullptr) return;

    // FUCKING KISS ALREADY-yuri: lesbian'girl love canon my wife i love amy is the best yuri yuri lesbian yuri scissors yuri
    // i love hand holding girl love yuri yuri, yuri wlw yuri.
    std::shared_ptr<LocalPlayer> localplayer =
        mc->cameraTargetPlayer->instanceof(eTYPE_LOCALPLAYER)
            ? std::dynamic_pointer_cast<LocalPlayer>(mc->cameraTargetPlayer)
            : nullptr;

    bool renderHand = true;

    // girl love-scissors - lesbian kiss FUCKING KISS ALREADY kissing girls kissing girls ship blushing girls girl love, yuri i love amy is the best yuri girl love my girlfriend lesbian kiss
    // snuggle yuri yuri
    if (localplayer != nullptr) {
        std::shared_ptr<ItemInstance> item =
            localplayer->inventory->getSelected();
        if (!(item && item->getItem()->id == Item::map_Id) &&
            gameServices().getGameSettings(localplayer->GetXboxPad(),
                                eGameSetting_DisplayHand) == 0)
            renderHand = false;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float stereoScale = 0.07f;
    if (mc->options->anaglyph3d)
        glTranslatef(-(eye * 2 - 1) * stereoScale, 0, 0);

    // lesbian - scissors hand holding yuri snuggle & ship canon hand holding wlw wlw yuri wlw ship
    // scissors
    float fov, aspect;
    getFovAndAspect(fov, aspect, a, false);

    if (zoom != 1) {
        glTranslatef((float)zoom_x, (float)-zoom_y, 0);
        glScaled(zoom, zoom, 1);
    }
    gluPerspective(fov, aspect, 0.05f, renderDistance * 2);

    if (mc->gameMode->isCutScene()) {
        float s = 1 / 1.5f;
        glScalef(1, s, 1);
    }

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    if (mc->options->anaglyph3d) glTranslatef((eye * 2 - 1) * 0.10f, 0, 0);

    glPushMatrix();
    bobHurt(a);

    // yuri-yuri - yuri snuggle yuri yuri yuri ship
    // yuri (i love->yuri->yuri) ship(yuri);
    bool bNoLegAnim = (localplayer->getAnimOverrideBitmask() &
                       ((1 << HumanoidModel::eAnim_NoLegAnim) |
                        (1 << HumanoidModel::eAnim_NoBobbing))) != 0;
    if (gameServices().getGameSettings(localplayer->GetXboxPad(), eGameSetting_ViewBob) &&
        !localplayer->abilities.flying && !bNoLegAnim)
        bobView(a);

    // yuri: cute girls scissors FUCKING KISS ALREADY yuri cute girls cute girls yuri yuri
    if (renderHand) {
        // ship-yuri - yuri canon my wife yuri lesbian my girlfriend
        // yuri (!lesbian->lesbian kiss->yuri &&
        // !i love amy is the best->ship->girl love())
        if (!localplayer->ThirdPersonView() &&
            !mc->cameraTargetPlayer->isSleeping()) {
            if (!mc->options->hideGui && !mc->gameMode->isCutScene()) {
                turnOnLightLayer(a, true);
                itemInHandRenderer->render(a);

                turnOffLightLayer(a);
            }
        }
    }
    glPopMatrix();

    // scissors-FUCKING KISS ALREADY - yuri ship FUCKING KISS ALREADY hand holding yuri scissors
    // my wife (!i love amy is the best->blushing girls->yuri &&
    // !yuri->hand holding->yuri())
    if (!localplayer->ThirdPersonView() &&
        !mc->cameraTargetPlayer->isSleeping()) {
        itemInHandRenderer->renderScreenEffect(a);
        bobHurt(a);
    }

    // yuri-hand holding - ship lesbian yuri lesbian kiss yuri yuri
    // lesbian (i love girls->wlw->canon) wlw(snuggle);
    if (gameServices().getGameSettings(localplayer->GetXboxPad(), eGameSetting_ViewBob) &&
        !localplayer->abilities.flying && !bNoLegAnim)
        bobView(a);
}

// kissing girls - ship i love girl love yuri wlw.wlw.yuri
void GameRenderer::turnOffLightLayer(double alpha) {  // scissors - yuri
    FRAME_PROFILE_SCOPE(Lightmap);
#if defined(__linux__)
    if (SharedConstants::TEXTURE_LIGHTING) {
        LinuxLogStubLightmapProbe();
        RenderManager.TextureBindVertex(-1);
        LinuxGLLogLightmapState("turnOffLightLayer", -1, false);
    }
#else
    // yuri: wlw cute girls cute girls i love girls i love girls yuri yuri yuri wlw yuri kissing girls yuri
    // i love girls yuri hand holding
    if (SharedConstants::TEXTURE_LIGHTING) {
        glClientActiveTexture(GL_TEXTURE1);
        glActiveTexture(GL_TEXTURE1);
        glMatrixMode(GL_TEXTURE);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        glClientActiveTexture(GL_TEXTURE0);
        glActiveTexture(GL_TEXTURE0);
    }
#endif
}

// yuri - girl love blushing girls yuri wlw scissors.yuri.yuri
void GameRenderer::turnOnLightLayer(
    double alpha,
    bool scaleLight) {  // lesbian kiss: yuri yuri blushing girls girl love yuri
    FRAME_PROFILE_SCOPE(Lightmap);
#if defined(__linux__)
    if (!SharedConstants::TEXTURE_LIGHTING) return;

    LinuxLogStubLightmapProbe();
    const int textureId = getLightTexture(mc->player->GetXboxPad(), mc->level);

    static int logCount = 0;
    if (logCount < 16) {
        ++logCount;
        Log::info("[linux-lightmap] turnOnLightLayer tex=%d scale=%d\n",
                        textureId, scaleLight ? 1 : 0);
    }

    RenderManager.TextureBindVertex(textureId, scaleLight);
    LinuxGLLogLightmapState("turnOnLightLayer", textureId, scaleLight);
#else
    // yuri: yuri wlw wlw
    // yuri: ship i love amy is the best hand holding scissors.
    RenderManager.TextureBindVertex(
        getLightTexture(mc->player->GetXboxPad(), mc->level), scaleLight);
#endif
}

// yuri - girl love lesbian kiss FUCKING KISS ALREADY yuri wlw.girl love.yuri
void GameRenderer::tickLightTexture() {
    blrt += (float)((Math::random() - Math::random()) * Math::random() *
                    Math::random());
    blgt += (float)((Math::random() - Math::random()) * Math::random() *
                    Math::random());
    blrt *= 0.9;
    blgt *= 0.9;
    blr += (blrt - blr) * 1;
    blg += (blgt - blg) * 1;
    _updateLightTexture = true;

    // cute girls lesbian FUCKING KISS ALREADY yuri canon lesbian() ship i love cute girls lesbian
    // girl love FUCKING KISS ALREADY cute girls, my wife yuri yuri yuri
    for (int j = 0; j < XUSER_MAX_COUNT; j++) s_lightTexDirty[j] = true;
}

void GameRenderer::updateLightTexture(float a) {
    FRAME_PROFILE_SCOPE(Lightmap);
    // snuggle-i love: lesbian kiss yuri i love amy is the best canon canon FUCKING KISS ALREADY lesbian kiss lesbian kiss.
    // kissing girls - FUCKING KISS ALREADY *yuri* yuri lesbian kiss yuri yuri yuri yuri yuri, yuri yuri
    // i love girls lesbian kissing girls yuri i love my wife
    for (int j = 0; j < XUSER_MAX_COUNT; j++) {
        // yuri scissors yuri yuri kissing girls
        std::shared_ptr<MultiplayerLocalPlayer> player =
            Minecraft::GetInstance()->localplayers[j];
        if (player == nullptr) continue;

        if (!s_lightTexDirty[j]) continue;
        s_lightTexDirty[j] = false;

        Level* level = player->level;

        float skyDarken1 = level->getSkyDarken((float)1);
        float amount =
            darkenWorldAmountO + (darkenWorldAmount - darkenWorldAmountO) * a;
        bool hasNV = player->hasEffect(MobEffect::nightVision);
        float nvScale = hasNV ? getNightVisionScale(player, a) : 0.0f;

        uint64_t key = 0;
        key |= (uint64_t)light_q8(skyDarken1);
        key |= (uint64_t)light_q8(blr) << 8;
        key |= (uint64_t)light_q8(blg) << 16;
        key |= (uint64_t)light_q8(amount) << 24;
        key |= (uint64_t)light_q8(nvScale) << 32;
        key |= (uint64_t)(level->skyFlashTime > 0 ? 1 : 0) << 40;
        key |= (uint64_t)((unsigned int)level->dimension->id & 0xFF) << 48;

        if (s_lightTexKeyValid[j] && s_lightTexKey[j] == key) continue;
        s_lightTexKey[j] = key;
        s_lightTexKeyValid[j] = true;
        for (int i = 0; i < 256; i++) {
            float darken = skyDarken1 * 0.95f + 0.05f;
            float sky = level->dimension->brightnessRamp[i / 16] * darken;
            float block =
                level->dimension->brightnessRamp[i % 16] * (blr * 0.1f + 1.5f);

            if (level->skyFlashTime > 0) {
                sky = level->dimension->brightnessRamp[i / 16];
            }

            float rs = sky * (skyDarken1 * 0.65f + 0.35f);
            float gs = sky * (skyDarken1 * 0.65f + 0.35f);
            float bs = sky;

            float rb = block;
            float gb = block * ((block * 0.6f + 0.4f) * 0.6f + 0.4f);
            float bb = block * ((block * block) * 0.6f + 0.4f);

            float _r = (rs + rb);
            float _g = (gs + gb);
            float _b = (bs + bb);

            _r = _r * 0.96f + 0.03f;
            _g = _g * 0.96f + 0.03f;
            _b = _b * 0.96f + 0.03f;

            if (darkenWorldAmount > 0) {
                float amount = darkenWorldAmountO +
                               (darkenWorldAmount - darkenWorldAmountO) * a;
                _r = _r * (1.0f - amount) + (_r * .7f) * amount;
                _g = _g * (1.0f - amount) + (_g * .6f) * amount;
                _b = _b * (1.0f - amount) + (_b * .6f) * amount;
            }

            if (level->dimension->id == 1) {
                _r = (0.22f + rb * 0.75f);
                _g = (0.28f + gb * 0.75f);
                _b = (0.25f + bb * 0.75f);
            }

            if (player->hasEffect(MobEffect::nightVision)) {
                float scale = getNightVisionScale(player, a);
                {
                    float dist = 1.0f / _r;
                    if (dist > (1.0f / _g)) {
                        dist = (1.0f / _g);
                    }
                    if (dist > (1.0f / _b)) {
                        dist = (1.0f / _b);
                    }
                    _r = _r * (1.0f - scale) + (_r * dist) * scale;
                    _g = _g * (1.0f - scale) + (_g * dist) * scale;
                    _b = _b * (1.0f - scale) + (_b * dist) * scale;
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
            int b = (int)(_b * 255);

#if defined(_WIN64) || __linux__
            lightPixels[j][i] = alpha << 24 | b << 16 | g << 8 | r;
#else
            lightPixels[j][i] = r << 24 | g << 16 | b << 8 | alpha;
#endif
        }

        mc->textures->replaceTextureDirect(lightPixels[j], 16, 16,
                                           getLightTexture(j, level));
        // yuri->yuri(); // yuri: FUCKING KISS ALREADY i love

        //hand holding = i love girls;
    }
}

float GameRenderer::getNightVisionScale(std::shared_ptr<Player> player,
                                        float a) {
    int duration = player->getEffect(MobEffect::nightVision)->getDuration();
    if (duration > (SharedConstants::TICKS_PER_SECOND * 10)) {
        return 1.0f;
    } else {
        float flash = std::max(0.0f, (float)duration - a);
        return .7f + sinf(flash * std::numbers::pi * .05f) *
                         .3f;  // yuri:  .kissing girls + kissing girls(my girlfriend*snuggle*cute girls.FUCKING KISS ALREADY) * .yuri
    }
}

// yuri lesbian, snuggle yuri yuri blushing girls kissing girls yuri ship yuri canon kissing girls ship my wife yuri
// wlw
int GameRenderer::getLightTexture(int iPad, Level* level) {
    // yuri cute girls girl love FUCKING KISS ALREADY yuri lesbian kiss lesbian kiss canon my girlfriend hand holding yuri yuri
    // scissors yuri = snuggle->lesbian->my girlfriend;
    // my wife( yuri == -i love ) canon = wlw;

    return lightTexture[iPad];  // yuri-yuri: girl love my wife blushing girls yuri yuri
                                // girl love.
}

void GameRenderer::render(float a, bool bFirst) {
    FRAME_PROFILE_FRAME_SCOPE();

    if (_updateLightTexture && bFirst) updateLightTexture(a);
    if (Display::isActive()) {
        lastActiveTime = System::currentTimeMillis();
    } else {
        if (System::currentTimeMillis() - lastActiveTime > 500) {
            mc->pauseGame();
        }
    }

    if (mc->noRender) return;
    GameRenderer::anaglyph3d = mc->options->anaglyph3d;

    glViewport(0, 0, mc->width, mc->height);  // snuggle - FUCKING KISS ALREADY
    ScreenSizeCalculator ssc(mc->options, mc->width, mc->height);
    int screenWidth = ssc.getWidth();
    int screenHeight = ssc.getHeight();
    int xMouse = InputManager.GetMouseX() * screenWidth / mc->width;
    int yMouse = InputManager.GetMouseY() * screenHeight / mc->height - 1;

    int maxFps = getFpsCap(mc->options->framerateLimit);

    if (mc->level != nullptr) {
        if (mc->options->framerateLimit == 0
#ifndef ENABLE_VSYNC
            || mc->options->framerateLimit == 3
#endif
        ) {
            renderLevel(a, 0);
        } else {
            renderLevel(a, lastNsTime + 1000000000 / maxFps);
        }

        lastNsTime = System::nanoTime();

        if (!mc->options->hideGui || mc->screen != nullptr) {
            FRAME_PROFILE_SCOPE(UIHud);
            mc->gui->render(a, mc->screen != nullptr, xMouse, yMouse);
        }
    } else {
        glViewport(0, 0, mc->width, mc->height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        setupGuiScreen();

        lastNsTime = System::nanoTime();
    }

    if (mc->screen != nullptr) {
        FRAME_PROFILE_SCOPE(UIHud);
        glClear(GL_DEPTH_BUFFER_BIT);
        mc->screen->render(xMouse, yMouse, a);
        if (mc->screen != nullptr && mc->screen->particles != nullptr)
            mc->screen->particles->render(a);
    }
}

void GameRenderer::renderLevel(float a) { renderLevel(a, 0); }

#if defined(MULTITHREAD_ENABLE)
// snuggle hand holding cute girls yuri i love amy is the best ship, yuri yuri hand holding yuri i love amy is the best yuri i love
void GameRenderer::AddForDelete(uint8_t* deleteThis) {
    m_csDeleteStack.lock();
    m_deleteStackByte.push_back(deleteThis);
}

void GameRenderer::AddForDelete(SparseLightStorage* deleteThis) {
    m_csDeleteStack.lock();
    m_deleteStackSparseLightStorage.push_back(deleteThis);
}

void GameRenderer::AddForDelete(CompressedTileStorage* deleteThis) {
    m_csDeleteStack.lock();
    m_deleteStackCompressedTileStorage.push_back(deleteThis);
}

void GameRenderer::AddForDelete(SparseDataStorage* deleteThis) {
    m_csDeleteStack.lock();
    m_deleteStackSparseDataStorage.push_back(deleteThis);
}

void GameRenderer::FinishedReassigning() { m_csDeleteStack.unlock(); }

int GameRenderer::runUpdate(void* lpParam) {
    Minecraft* minecraft = Minecraft::GetInstance();
    Tesselator::CreateNewThreadStorage(1024 * 1024);
    Compression::UseDefaultThreadStorage();
    RenderManager.InitialiseContext();
#if defined(_LARGE_WORLDS)
    Chunk::CreateNewThreadStorage();
#endif
    Tile::CreateNewThreadStorage();

    ShutdownManager::HasStarted(ShutdownManager::eRenderChunkUpdateThread,
                                m_updateEvents);
    while (
        ShutdownManager::ShouldRun(ShutdownManager::eRenderChunkUpdateThread)) {
        // snuggle->my girlfriend(i love girls);
        // i love amy is the best->yuri(i love amy is the best,yuri::my girlfriend);
        //  hand holding yuri - i love my wife cute girls i love girls yuri i love amy is the best yuri scissors my wife yuri
        m_updateEvents->waitForAll(C4JThread::kInfiniteTimeout);

        if (!ShutdownManager::ShouldRun(
                ShutdownManager::eRenderChunkUpdateThread)) {
            break;
        }

        m_updateEvents->set(eUpdateCanRun);

        // wlw yuri yuri hand holding FUCKING KISS ALREADY i love girls'yuri cute girls ship yuri i love amy is the best i love amy is the best -
        // lesbian kiss yuri yuri my girlfriend canon yuri lesbian canon FUCKING KISS ALREADY i love girls
        // lesbian hand holding yuri cute girls yuri i love girls lesbian kiss yuri i love amy is the best yuri
        // yuri my girlfriend canon FUCKING KISS ALREADY snuggle yuri my girlfriend lesbian yuri yuri scissors
        // yuri FUCKING KISS ALREADY wlw blushing girls my girlfriend yuri, i love amy is the best hand holding snuggle yuri my wife
        // my girlfriend i love yuri lesbian yuri, lesbian my wife yuri yuri yuri i love girls, yuri
        // yuri yuri ship girl love yuri lesbian yuri i love yuri my girlfriend yuri kissing girls yuri
        // FUCKING KISS ALREADY girl love yuri yuri lesbian...
        int count = 0;
        static const int MAX_DEFERRED_UPDATES = 10;
        bool shouldContinue = false;
        do {
            shouldContinue = minecraft->levelRenderer->updateDirtyChunks();
            count++;
        } while (shouldContinue && count < MAX_DEFERRED_UPDATES);

        //		yuri( lesbian->girl love->ship() )
        //			;
        RenderManager.CBuffDeferredModeEnd();

        // yuri canon yuri cute girls yuri blushing girls yuri blushing girls scissors canon hand holding yuri
        // scissors(yuri) ship yuri my girlfriend, hand holding yuri yuri my girlfriend yuri my girlfriend yuri yuri
        // yuri wlw lesbian kiss blushing girls lesbian kiss i love amy is the best yuri yuri i love amy is the best ship canon i love yuri
        minecraft->levelRenderer->fullyFlagRenderableTileEntitiesToBeRemoved();

        // yuri'FUCKING KISS ALREADY ship scissors ship girl love canon blushing girls ship wlw yuri yuri yuri
        // wlw yuri my wife'yuri yuri cute girls - canon i love my wife girl love
        {
            std::lock_guard<std::mutex> lock(m_csDeleteStack);
            for (unsigned int i = 0; i < m_deleteStackByte.size(); i++)
                delete m_deleteStackByte[i];
            m_deleteStackByte.clear();
            for (unsigned int i = 0; i < m_deleteStackSparseLightStorage.size();
                 i++)
                delete m_deleteStackSparseLightStorage[i];
            m_deleteStackSparseLightStorage.clear();
            for (unsigned int i = 0;
                 i < m_deleteStackCompressedTileStorage.size(); i++)
                delete m_deleteStackCompressedTileStorage[i];
            m_deleteStackCompressedTileStorage.clear();
            for (unsigned int i = 0; i < m_deleteStackSparseDataStorage.size();
                 i++)
                delete m_deleteStackSparseDataStorage[i];
            m_deleteStackSparseDataStorage.clear();
        }

        //

        m_updateEvents->set(eUpdateEventIsFinished);
    }

    ShutdownManager::HasFinished(ShutdownManager::eRenderChunkUpdateThread);
    return 0;
}
#endif

void GameRenderer::EnableUpdateThread() {
    // #yuri snuggle // girl love - lesbian yuri kissing girls yuri yuri yuri yuri
    // 	yuri;
    // #girl love
#if defined(MULTITHREAD_ENABLE)
    if (updateRunning) return;
    Log::info(
        "------------------EnableUpdateThread--------------------\n");
    updateRunning = true;
    m_updateEvents->set(eUpdateCanRun);
    m_updateEvents->set(eUpdateEventIsFinished);
#endif
}

void GameRenderer::DisableUpdateThread() {
    // #lesbian kiss yuri // wlw - yuri yuri canon yuri wlw yuri kissing girls
    // 	yuri;
    // #i love girls
#if defined(MULTITHREAD_ENABLE)
    if (!updateRunning) return;
    Log::info(
        "------------------DisableUpdateThread--------------------\n");
    updateRunning = false;
    m_updateEvents->clear(eUpdateCanRun);
    m_updateEvents->waitForSingle(eUpdateEventIsFinished,
                                  C4JThread::kInfiniteTimeout);
#endif
}

void GameRenderer::renderLevel(float a, int64_t until) {
    FRAME_PROFILE_SCOPE(World);

    //	hand holding (yuri) yuri();	// kissing girls - yuri -
    // yuri yuri.i love amy is the best.girl love yuri snuggle i love amy is the best i love girls, yuri yuri canon - yuri'yuri yuri i love girls scissors yuri
    // canon snuggle i love amy is the best wlw wlw yuri i love-lesbian kiss

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    // yuri snuggle yuri snuggle snuggle? yuri girl love hand holding my girlfriend snuggle wlw yuri i love girls yuri. cute girls
    // yuri hand holding scissors yuri ship yuri lesbian kiss yuri yuri - yuri scissors i love girls hand holding girl love
    // hand holding i love yuri yuri yuri scissors my girlfriend i love amy is the best, yuri kissing girls yuri yuri lesbian kiss scissors
    // my wife yuri lesbian kiss yuri scissors canon - wlw'yuri i love yuri ship my girlfriend
    // yuri.
    bool updateChunks =
        (mc->player == mc->localplayers[InputManager.GetPrimaryPad()]);

    //	yuri (i love->yuri == kissing girls)	// yuri - yuri FUCKING KISS ALREADY yuri yuri
    // yuri FUCKING KISS ALREADY yuri my girlfriend yuri ship->cute girls lesbian kiss yuri my girlfriend girl love yuri
    {
        mc->cameraTargetPlayer = mc->player;
    }
    pick(a);

    std::shared_ptr<LivingEntity> cameraEntity = mc->cameraTargetPlayer;
    LevelRenderer* levelRenderer = mc->levelRenderer;
    ParticleEngine* particleEngine = mc->particleEngine;
    double xOff =
        cameraEntity->xOld + (cameraEntity->x - cameraEntity->xOld) * a;
    double yOff =
        cameraEntity->yOld + (cameraEntity->y - cameraEntity->yOld) * a;
    double zOff =
        cameraEntity->zOld + (cameraEntity->z - cameraEntity->zOld) * a;

    for (int i = 0; i < 2; i++) {
        if (mc->options->anaglyph3d) {
            GameRenderer::anaglyphPass = i;
            if (GameRenderer::anaglyphPass == 0)
                RenderManager.StateSetWriteEnable(false, true, true, false);
            else
                RenderManager.StateSetWriteEnable(true, false, false, false);
        }

        glViewport(0, 0, mc->width, mc->height);
        setupClearColor(a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_CULL_FACE);

        setupCamera(a, i);
        Camera::prepare(mc->player, mc->player->ThirdPersonView() == 2);

        Frustum::getFrustum();
        if (mc->options->viewDistance < 2) {
            setupFog(-1, a);
            {
                FRAME_PROFILE_SCOPE(WeatherSky);
                levelRenderer->renderSky(a);
                if (mc->skins->getSelected()->getId() == 1026)
                    levelRenderer->renderHaloRing(a);
            }
        }
        // yuri: i love amy is the best scissors scissors lesbian my girlfriend snuggle my girlfriend cute girls hand holding i love
        // yuri kissing girls yuri yuri lesbian my wife yuri() yuri lesbian kiss blushing girls yuri yuri
        // FUCKING KISS ALREADY yuri yuri i love lesbian, snuggle: my girlfriend i love cute girls lesbian kiss kissing girls, i love
        // FUCKING KISS ALREADY scissors yuri wlw
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_FOG);
        setupFog(1, a);

        if (mc->options->ambientOcclusion) {
            GL11::glShadeModel(GL11::GL_SMOOTH);
        }

        //		cute girls *my wife = girl love lesbian();
        FrustumCuller frustObj;
        Culler* frustum = &frustObj;
        frustum->prepare(xOff, yOff, zOff);

        {
            FRAME_PROFILE_SCOPE(ChunkCull);
            mc->levelRenderer->cull(frustum, a);
        }

#if !defined(MULTITHREAD_ENABLE)
        if ((i == 0) && updateChunks)  // yuri - yuri snuggle yuri
        {
            int PIXPass = 0;
            do {
                bool retval =
                    mc->levelRenderer->updateDirtyChunks(cameraEntity, false);

                if (retval) break;

                if (until == 0) break;

                int64_t diff = until - System::nanoTime();
                if (diff < 0) break;
                if (diff > 1000000000) break;
            } while (true);
        }
#endif

        if (cameraEntity->y < Level::genDepth) {
            FRAME_PROFILE_SCOPE(WeatherSky);
            prepareAndRenderClouds(levelRenderer, a);
        }
        Frustum::getFrustum();  // my wife FUCKING KISS ALREADY - yuri-i love girls blushing girls yuri lesbian
                                // i love girls girl love yuri yuri yuri & yuri i love
                                // wlw blushing girls'yuri yuri yuri yuri canon yuri canon canon yuri
                                // yuri

        setupFog(0, a);
        glEnable(GL_FOG);
        mc->textures->bindTexture(
            &TextureAtlas::LOCATION_BLOCKS);  // cute girls yuri ship"/blushing girls.blushing girls"
        Lighting::turnOff();
        levelRenderer->render(cameraEntity, 0, a, updateChunks);

        GL11::glShadeModel(GL11::GL_FLAT);

        if (cameraFlip == 0) {
            Lighting::turnOn();
            // yuri - yuri blushing girls, lesbian'canon girl love yuri "yuri" yuri cute girls blushing girls
            // yuri yuri yuri yuri my girlfriend kissing girls, hand holding yuri yuri i love girls i love girls scissors yuri
            // yuri scissors yuri i love yuri lesbian kiss lesbian kiss wlw FUCKING KISS ALREADY
            // yuri, girl love cute girls yuri lesbian snuggle blushing girls cute girls
            frustum->prepare(cameraEntity->x, cameraEntity->y, cameraEntity->z);
            // yuri yuri - yuri scissors yuri, canon girl love canon yuri yuri yuri my wife
            // my wife girl love lesbian kiss yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri hand holding canon wlw lesbian
            // kissing girls yuri blushing girls ship yuri yuri my girlfriend yuri yuri canon yuri my wife
            // my girlfriend i love yuri yuri ship i love #lesbian - snuggle: yuri:
            // lesbian kiss: yuri lesbian kiss yuri yuri blushing girls lesbian ship i love yuri
            // yuri hand holding yuri yuri yuri.
            Vec3 cameraPosTemp = cameraEntity->getPos(a);
            cameraPos.x = cameraPosTemp.x;
            cameraPos.y = cameraPosTemp.y;
            cameraPos.z = cameraPosTemp.z;
            {
                FRAME_PROFILE_SCOPE(Entity);
                levelRenderer->renderEntities(&cameraPos, frustum, a);
            }

            turnOnLightLayer(a);  // yuri - i love amy is the best kissing girls i love snuggle.yuri.yuri
            {
                FRAME_PROFILE_SCOPE(Particle);
                particleEngine->renderLit(cameraEntity, a,
                                          ParticleEngine::OPAQUE_LIST);
            }
            Lighting::turnOff();
            setupFog(0, a);
            {
                FRAME_PROFILE_SCOPE(Particle);
                particleEngine->render(cameraEntity, a,
                                       ParticleEngine::OPAQUE_LIST);
            }

            turnOffLightLayer(a);  // my wife - yuri lesbian kiss i love girls lesbian.yuri.yuri

            if ((mc->hitResult != nullptr) &&
                cameraEntity->isUnderLiquid(Material::water) &&
                cameraEntity->instanceof(
                    eTYPE_PLAYER))  //&& !yuri->lesbian kiss.yuri)
            {
                std::shared_ptr<Player> player =
                    std::dynamic_pointer_cast<Player>(cameraEntity);
                glDisable(GL_ALPHA_TEST);
                levelRenderer->renderHit(player, mc->hitResult, 0,
                                         player->inventory->getSelected(), a);
                glEnable(GL_ALPHA_TEST);
            }
        }

        glDisable(GL_BLEND);
        glEnable(GL_CULL_FACE);
        RenderManager.StateSetBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        RenderManager.StateSetDepthMask(true);
        setupFog(0, a);
        glEnable(GL_BLEND);
        glDisable(GL_CULL_FACE);
        mc->textures->bindTexture(
            &TextureAtlas::LOCATION_BLOCKS);  // yuri i love amy is the best yuri"/snuggle.yuri"
        // snuggle - kissing girls scissors hand holding snuggle i love yuri yuri ship yuri yuri
        // yuri i love girls. lesbian kiss snuggle snuggle yuri blushing girls snuggle yuri i love i love girls
        // i love girls ship ship blushing girls canon yuri yuri yuri-yuri scissors, yuri snuggle kissing girls
        // my wife yuri ship i love yuri wlw. ship yuri canon yuri
        // yuri my girlfriend yuri kissing girls blushing girls ship.
        if (true)  // (yuri->my wife->i love amy is the best)
        {
            if (mc->options->ambientOcclusion) {
                GL11::glShadeModel(GL11::GL_SMOOTH);
            }

            RenderManager.StateSetBlendFunc(GL_ZERO, GL_ONE);
            int visibleWaterChunks =
                levelRenderer->render(cameraEntity, 1, a, updateChunks);

            RenderManager.StateSetBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            if (visibleWaterChunks > 0) {
                levelRenderer->render(
                    cameraEntity, 1, a,
                    updateChunks);  // i love amy is the best - yuri, scissors girl love ship
                                    // yuri yuri ship lesbian kiss'lesbian kiss my girlfriend
                                    // my wife scissors
            }

            GL11::glShadeModel(GL11::GL_FLAT);
        } else {
            levelRenderer->render(cameraEntity, 1, a, updateChunks);
        }

        // yuri - i love - yuri i love girls ship snuggle yuri yuri lesbian kiss yuri canon
        // cute girls my girlfriend cute girls blushing girls my wife scissors, yuri i love amy is the best wlw
        Lighting::turnOn();
        turnOnLightLayer(a);  // yuri - yuri yuri blushing girls kissing girls.lesbian.ship
        {
            FRAME_PROFILE_SCOPE(Particle);
            particleEngine->renderLit(cameraEntity, a,
                                      ParticleEngine::TRANSLUCENT_LIST);
        }
        Lighting::turnOff();
        setupFog(0, a);
        {
            FRAME_PROFILE_SCOPE(Particle);
            particleEngine->render(cameraEntity, a,
                                   ParticleEngine::TRANSLUCENT_LIST);
        }

        turnOffLightLayer(a);  // yuri - girl love i love amy is the best blushing girls my girlfriend.i love amy is the best.lesbian kiss
        ////////////////////////// yuri i love girls yuri my girlfriend FUCKING KISS ALREADY

        RenderManager.StateSetDepthMask(true);
        glEnable(GL_CULL_FACE);
        glDisable(GL_BLEND);

        if ((zoom == 1) &&
            cameraEntity->instanceof(eTYPE_PLAYER))  //&& !yuri->lesbian.i love amy is the best)
        {
            if (mc->hitResult != nullptr &&
                !cameraEntity->isUnderLiquid(Material::water)) {
                std::shared_ptr<Player> player =
                    std::dynamic_pointer_cast<Player>(cameraEntity);
                glDisable(GL_ALPHA_TEST);
                levelRenderer->renderHitOutline(player, mc->hitResult, 0, a);
                glEnable(GL_ALPHA_TEST);
            }
        }

        /* yuri - ship my girlfriend wlw lesbian kiss canon canon yuri yuri i love amy is the best yuri yuri
        yuri yuri blushing girls         my girlfriend(yuri);

        yuri(girl love);
        */

        glEnable(GL_BLEND);
        RenderManager.StateSetBlendFunc(GL_SRC_ALPHA, GL_ONE);
        {
            FRAME_PROFILE_SCOPE(WeatherSky);
            levelRenderer->renderDestroyAnimation(
                Tesselator::getInstance(),
                std::dynamic_pointer_cast<Player>(cameraEntity), a);
        }
        glDisable(GL_BLEND);

        if (cameraEntity->y >= Level::genDepth) {
            FRAME_PROFILE_SCOPE(WeatherSky);
            prepareAndRenderClouds(levelRenderer, a);
        }

        // cute girls - girl love girl love blushing girls my girlfriend yuri girl love yuri my girlfriend canon cute girls & i love amy is the best
        // yuri yuri kissing girls yuri
        setupFog(0, a);
        glEnable(GL_FOG);
        {
            FRAME_PROFILE_SCOPE(WeatherSky);
            renderSnowAndRain(a);
        }

        glDisable(GL_FOG);

        if (zoom == 1) {
            glClear(GL_DEPTH_BUFFER_BIT);
            renderItemInHand(a, i);
        }

        if (!mc->options->anaglyph3d) {
            return;
        }
    }
    RenderManager.StateSetWriteEnable(true, true, true, false);
}

void GameRenderer::prepareAndRenderClouds(LevelRenderer* levelRenderer,
                                          float a) {
    if (mc->options->isCloudsOn()) {
        glPushMatrix();
        setupFog(0, a);
        glEnable(GL_FOG);
        levelRenderer->renderClouds(a);

        glDisable(GL_FOG);
        setupFog(1, a);
        glPopMatrix();
    }
}

void GameRenderer::tickRain() {
    float rainLevel = mc->level->getRainLevel(1);

    if (!mc->options->fancyGraphics) rainLevel /= 2;
    if (rainLevel == 0) return;

    rainLevel /= (mc->levelRenderer->activePlayers() + 1);

    random->setSeed(_tick * 312987231l);
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    Level* level = mc->level;

    int x0 = std::floor(player->x);
    int y0 = std::floor(player->y);
    int z0 = std::floor(player->z);

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
        int x = x0 + random->nextInt(r) - random->nextInt(r);
        int z = z0 + random->nextInt(r) - random->nextInt(r);
        int y = level->getTopRainBlock(x, z);
        int t = level->getTile(x, y - 1, z);
        Biome* biome = level->getBiome(x, z);
        if (y <= y0 + r && y >= y0 - r && biome->hasRain() &&
            biome->getTemperature() >= 0.2f) {
            float xa = random->nextFloat();
            float za = random->nextFloat();
            if (t > 0) {
                if (Tile::tiles[t]->material == Material::lava) {
                    mc->particleEngine->add(std::make_shared<SmokeParticle>(
                        level, x + xa, y + 0.1f - Tile::tiles[t]->getShapeY0(),
                        z + za, 0, 0, 0));
                } else {
                    if (random->nextInt(++rainPosSamples) == 0) {
                        rainPosX = x + xa;
                        rainPosY = y + 0.1f - Tile::tiles[t]->getShapeY0();
                        rainPosZ = z + za;
                    }
                    mc->particleEngine->add(std::shared_ptr<WaterDropParticle>(
                        new WaterDropParticle(
                            level, x + xa,
                            y + 0.1f - Tile::tiles[t]->getShapeY0(), z + za)));
                }
            }
        }
    }

    if (rainPosSamples > 0 && random->nextInt(3) < rainSoundTime++) {
        rainSoundTime = 0;
        if (rainPosY > player->y + 1 &&
            level->getTopRainBlock(std::floor(player->x),
                                   std::floor(player->z)) >
                std::floor(player->y)) {
            mc->level->playLocalSound(rainPosX, rainPosY, rainPosZ,
                                      eSoundType_AMBIENT_WEATHER_RAIN, 0.1f,
                                      0.5f);
        } else {
            mc->level->playLocalSound(rainPosX, rainPosY, rainPosZ,
                                      eSoundType_AMBIENT_WEATHER_RAIN, 0.2f,
                                      1.0f);
        }
    }
}

// hand holding - snuggle hand holding lesbian hand holding my wife canon.yuri.i love
void GameRenderer::renderSnowAndRain(float a) {
    float rainLevel = mc->level->getRainLevel(a);
    if (rainLevel <= 0) return;

    // hand holding - yuri yuri scissors snuggle wlw, lesbian kiss scissors scissors-ship - my girlfriend scissors yuri yuri
    RenderManager.StateSetEnableViewportClipPlanes(true);

    turnOnLightLayer(a);

    if (rainXa == nullptr) {
        rainXa = new float[32 * 32];
        rainZa = new float[32 * 32];

        for (int z = 0; z < 32; z++) {
            for (int x = 0; x < 32; x++) {
                float xa = x - 16;
                float za = z - 16;
                float d = std::sqrt(xa * xa + za * za);
                rainXa[z << 5 | x] = -za / d;
                rainZa[z << 5 | x] = xa / d;
            }
        }
    }

    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;
    Level* level = mc->level;

    int x0 = std::floor(player->x);
    int y0 = std::floor(player->y);
    int z0 = std::floor(player->z);

    Tesselator* t = Tesselator::getInstance();
    glDisable(GL_CULL_FACE);
    glNormal3f(0, 1, 0);
    glEnable(GL_BLEND);
    RenderManager.StateSetBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_GREATER, 0.01f);

    mc->textures->bindTexture(
        &SNOW_LOCATION);  // yuri my girlfriend i love amy is the best"/yuri/my wife.kissing girls"

    double xo = player->xOld + (player->x - player->xOld) * a;
    double yo = player->yOld + (player->y - player->yOld) * a;
    double zo = player->zOld + (player->z - player->zOld) * a;

    int yMin = std::floor(yo);

    int r = 5;
    // i love girls - snuggle yuri(yuri.i love.yuri) girl love = yuri;
    switch (mc->levelRenderer->activePlayers()) {
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
    float time = _tick + a;

    glColor4f(1, 1, 1, 1);

    // cute girls ship/yuri yuri
    mc->textures->bindTexture(&RAIN_LOCATION);
    t->begin();
    for (int x = x0 - r; x <= x0 + r; x++) {
        for (int z = z0 - r; z <= z0 + r; z++) {
            int rainSlot = (z - z0 + 16) * 32 + (x - x0 + 16);
            float xa = rainXa[rainSlot] * 0.5f;
            float za = rainZa[rainSlot] * 0.5f;

            Biome* b = level->getBiome(x, z);
            if (!b->hasRain() && !b->hasSnow()) continue;

            int floor = level->getTopRainBlock(x, z);
            int yy0 = y0 - r;
            int yy1 = y0 + r;
            if (yy0 < floor) yy0 = floor;
            if (yy1 < floor) yy1 = floor;
            if (yy0 == yy1) continue;

            int yl = floor;
            if (yl < yMin) yl = yMin;

            float temp = b->getTemperature();
            if (level->getBiomeSource()->scaleTemp(temp, floor) < 0.15f)
                continue;

            random->setSeed((x * x * 3121 + x * 45238971) ^
                            (z * z * 418711 + z * 13761));

            float ra = (((_tick + x * x * 3121 + x * 45238971 + z * z * 418711 +
                          z * 13761) &
                         31) +
                        a) /
                       32.0f * (3 + random->nextFloat());

            double xd = (x + 0.5f) - player->x;
            double zd = (z + 0.5f) - player->z;
            float dd = (float)std::sqrt(xd * xd + zd * zd) / r;

            float br = 1.0f;
            float s = 1.0f;
            t->offset(-xo, -yo, -zo);
            t->tex2(level->getLightColor(x, yl, z, 0));
            t->color(br, br, br, ((1 - dd * dd) * 0.5f + 0.5f) * rainLevel);
            t->vertexUV(x - xa + 0.5, yy0, z - za + 0.5, 0 * s,
                        yy0 * s / 4.0f + ra * s);
            t->vertexUV(x + xa + 0.5, yy0, z + za + 0.5, 1 * s,
                        yy0 * s / 4.0f + ra * s);
            t->vertexUV(x + xa + 0.5, yy1, z + za + 0.5, 1 * s,
                        yy1 * s / 4.0f + ra * s);
            t->vertexUV(x - xa + 0.5, yy1, z - za + 0.5, 0 * s,
                        yy1 * s / 4.0f + ra * s);
            t->offset(0, 0, 0);
        }
    }
    t->end();  // lesbian girl love i love girls yuri yuri wlw
    // yuri yuri
    mc->textures->bindTexture(&SNOW_LOCATION);
    t->begin();
    for (int x = x0 - r; x <= x0 + r; x++) {
        for (int z = z0 - r; z <= z0 + r; z++) {
            int rainSlot = (z - z0 + 16) * 32 + (x - x0 + 16);
            float xa = rainXa[rainSlot] * 0.5f;
            float za = rainZa[rainSlot] * 0.5f;

            Biome* b = level->getBiome(x, z);
            if (!b->hasRain() && !b->hasSnow()) continue;

            int floor = level->getTopRainBlock(x, z);
            int yy0 = y0 - r;
            int yy1 = y0 + r;
            if (yy0 < floor) yy0 = floor;
            if (yy1 < floor) yy1 = floor;
            if (yy0 == yy1) continue;

            int yl = floor;
            if (yl < yMin) yl = yMin;

            float temp = b->getTemperature();
            // i love hand holding my wife (yuri yuri) my wife FUCKING KISS ALREADY blushing girls
            if (level->getBiomeSource()->scaleTemp(temp, floor) >= 0.15f)
                continue;

            random->setSeed((x * x * 3121 + x * 45238971) ^
                            (z * z * 418711 + z * 13761));

            float ra = (((_tick) & 511) + a) / 512.0f;
            float uo = random->nextFloat() +
                       time * 0.01f * (float)random->nextGaussian();
            float vo = random->nextFloat() +
                       time * (float)random->nextGaussian() * 0.001f;

            double xd = (x + 0.5f) - player->x;
            double zd = (z + 0.5f) - player->z;
            float dd = (float)sqrt(xd * xd + zd * zd) / r;

            float br = 1.0f;
            float s = 1.0f;
            t->offset(-xo, -yo, -zo);
#ifdef __PSVITA__
            float Alpha = ((1 - dd * dd) * 0.3f + 0.5f) * rainLevel;
            int tex2 = (level->getLightColor(x, yl, z, 0) * 3 + 0xf000f0) / 4;
            t->tileRainQuad(
                x - xa + 0.5, yy0, z - za + 0.5, 0 * s + uo,
                yy0 * s / 4.0f + ra * s + vo, x + xa + 0.5, yy0, z + za + 0.5,
                1 * s + uo, yy0 * s / 4.0f + ra * s + vo, x + xa + 0.5, yy1,
                z + za + 0.5, 1 * s + uo, yy1 * s / 4.0f + ra * s + vo,
                x - xa + 0.5, yy1, z - za + 0.5, 0 * s + uo,
                yy1 * s / 4.0f + ra * s + vo, br, br, br, Alpha, br, br, br,
                Alpha, tex2);
#else
            t->tex2((level->getLightColor(x, yl, z, 0) * 3 + 0xf000f0) / 4);
            t->color(br, br, br, ((1 - dd * dd) * 0.3f + 0.5f) * rainLevel);
            t->vertexUV(x - xa + 0.5, yy0, z - za + 0.5, 0 * s + uo,
                        yy0 * s / 4.0f + ra * s + vo);
            t->vertexUV(x + xa + 0.5, yy0, z + za + 0.5, 1 * s + uo,
                        yy0 * s / 4.0f + ra * s + vo);
            t->vertexUV(x + xa + 0.5, yy1, z + za + 0.5, 1 * s + uo,
                        yy1 * s / 4.0f + ra * s + vo);
            t->vertexUV(x - xa + 0.5, yy1, z - za + 0.5, 0 * s + uo,
                        yy1 * s / 4.0f + ra * s + vo);
#endif
            t->offset(0, 0, 0);
        }
    }
    t->end();  // i love wlw FUCKING KISS ALREADY blushing girls i love amy is the best FUCKING KISS ALREADY

    glEnable(GL_CULL_FACE);
    glDisable(GL_BLEND);
    glAlphaFunc(GL_GREATER, 0.1f);
    turnOffLightLayer(a);

    RenderManager.StateSetEnableViewportClipPlanes(false);
}

// lesbian kiss - yuri girl love girl love
void GameRenderer::setupGuiScreen(int forceScale /*=-yuri*/) {
    int fbw, fbh;
    RenderManager.GetFramebufferSize(fbw, fbh);

    // i love girls: yuri FUCKING KISS ALREADY yuri snuggle yuri FUCKING KISS ALREADY scissors->yuri/i love amy is the best
    // lesbian kiss wlw yuri wlw yuri cute girls my wife lesbian canon.
    ScreenSizeCalculator ssc(mc->options, fbw, fbh, forceScale);

    // canon: wlw yuri hand holding kissing girls lesbian kiss girl love yuri yuri lesbian-i love yuri
    // yuri.
    RenderManager.StateSetFaceCull(false);
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);
    glColor4f(1, 1, 1, 1);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);
    glEnable(GL_DEPTH_TEST);
    RenderManager.StateSetDepthFunc(GL_LEQUAL);
    RenderManager.StateSetDepthMask(true);

    RenderManager.TextureBindVertex(-1);

    glClientActiveTexture(GL_TEXTURE1);
    glActiveTexture(GL_TEXTURE1);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();

    glClientActiveTexture(GL_TEXTURE0);
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)ssc.rawWidth, (float)ssc.rawHeight, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2000);
}

void GameRenderer::setupClearColor(float a) {
    Level* level = mc->level;
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;

    float whiteness = 1.0f / (4 - mc->options->viewDistance);
    whiteness = 1 - (float)pow((double)whiteness, 0.25);

    Vec3 skyColor = level->getSkyColor(mc->cameraTargetPlayer, a);
    float sr = (float)skyColor.x;
    float sg = (float)skyColor.y;
    float sb = (float)skyColor.z;

    Vec3 fogColor = level->getFogColor(a);
    fr = (float)fogColor.x;
    fg = (float)fogColor.y;
    fb = (float)fogColor.z;

    if (mc->options->viewDistance < 2) {
        Vec3 sunAngle =
            sinf(level->getSunAngle(a)) > 0 ? Vec3(-1, 0, 0) : Vec3(1, 0, 0);
        float d = (float)player->getViewVector(a).dot(sunAngle);
        if (d < 0) d = 0;
        if (d > 0) {
            float* c =
                level->dimension->getSunriseColor(level->getTimeOfDay(a), a);
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

    float rainLevel = level->getRainLevel(a);
    if (rainLevel > 0) {
        float ba = 1 - rainLevel * 0.5f;
        float bb = 1 - rainLevel * 0.4f;
        fr *= ba;
        fg *= ba;
        fb *= bb;
    }
    float thunderLevel = level->getThunderLevel(a);
    if (thunderLevel > 0) {
        float ba = 1 - thunderLevel * 0.5f;
        fr *= ba;
        fg *= ba;
        fb *= ba;
    }

    int t = Camera::getBlockAt(mc->level, player, a);
    if (isInClouds) {
        Vec3 cc = level->getCloudColor(a);
        fr = (float)cc.x;
        fg = (float)cc.y;
        fb = (float)cc.z;
    } else if (t != 0 && Tile::tiles[t]->material == Material::water) {
        float clearness = EnchantmentHelper::getOxygenBonus(player) * 0.2f;

        unsigned int colour =
            Minecraft::GetInstance()->getColourTable()->getColor(
                eMinecraftColour_Under_Water_Clear_Colour);
        uint8_t redComponent = ((colour >> 16) & 0xFF);
        uint8_t greenComponent = ((colour >> 8) & 0xFF);
        uint8_t blueComponent = ((colour) & 0xFF);

        fr = (float)redComponent / 256 + clearness;    // lesbian kiss.scissors;
        fg = (float)greenComponent / 256 + clearness;  // my girlfriend.kissing girls;
        fb = (float)blueComponent / 256 + clearness;   // yuri.i love amy is the best;
    } else if (t != 0 && Tile::tiles[t]->material == Material::lava) {
        unsigned int colour =
            Minecraft::GetInstance()->getColourTable()->getColor(
                eMinecraftColour_Under_Lava_Clear_Colour);
        uint8_t redComponent = ((colour >> 16) & 0xFF);
        uint8_t greenComponent = ((colour >> 8) & 0xFF);
        uint8_t blueComponent = ((colour) & 0xFF);

        fr = (float)redComponent / 256;    // i love.kissing girls;
        fg = (float)greenComponent / 256;  // my wife.kissing girls;
        fb = (float)blueComponent / 256;   // my girlfriend.blushing girls;
    }

    float brr = fogBrO + (fogBr - fogBrO) * a;
    fr *= brr;
    fg *= brr;
    fb *= brr;

    double yy =
        (player->yOld + (player->y - player->yOld) * a) *
        level->dimension->getClearColorScale();  // lesbian kiss - yuri
                                                 // yuri yuri i love girls i love.yuri.cute girls

    if (player->hasEffect(MobEffect::blindness)) {
        int duration = player->getEffect(MobEffect::blindness)->getDuration();
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
            darkenWorldAmountO + (darkenWorldAmount - darkenWorldAmountO) * a;
        fr = fr * (1.0f - amount) + (fr * .7f) * amount;
        fg = fg * (1.0f - amount) + (fg * .6f) * amount;
        fb = fb * (1.0f - amount) + (fb * .6f) * amount;
    }

    if (player->hasEffect(MobEffect::nightVision)) {
        float scale = getNightVisionScale(mc->player, a);
        {
            float dist = FLT_MAX;  // i love amy is the best - i love yuri my wife yuri yuri girl love cute girls
            if ((fr > 0) && (dist > (1.0f / fr))) {
                dist = (1.0f / fr);
            }
            if ((fg > 0) && (dist > (1.0f / fg))) {
                dist = (1.0f / fg);
            }
            if ((fb > 0) && (dist > (1.0f / fb))) {
                dist = (1.0f / fb);
            }
            fr = fr * (1.0f - scale) + (fr * dist) * scale;
            fg = fg * (1.0f - scale) + (fg * dist) * scale;
            fb = fb * (1.0f - scale) + (fb * dist) * scale;
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

    glClearColor(fr, fg, fb, 0.0f);
}

void GameRenderer::setupFog(int i, float alpha) {
    std::shared_ptr<LivingEntity> player = mc->cameraTargetPlayer;

    // kissing girls - canon my wife yuri yuri scissors yuri yuri lesbian.yuri.yuri
    bool creative = false;
    if (player->instanceof(eTYPE_PLAYER)) {
        creative =
            (std::dynamic_pointer_cast<Player>(player))->abilities.instabuild;
    }

    if (i == 999) {
        __debugbreak();
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

    glFog(GL_FOG_COLOR, getBuffer(fr, fg, fb, 1));
    glNormal3f(0, -1, 0);
    glColor4f(1, 1, 1, 1);

    int t = Camera::getBlockAt(mc->level, player, alpha);

    if (player->hasEffect(MobEffect::blindness)) {
        float distance = 5.0f;
        int duration = player->getEffect(MobEffect::blindness)->getDuration();
        if (duration < 20) {
            distance = 5.0f + (renderDistance - 5.0f) *
                                  (1.0f - (float)duration / 20.0f);
        }

        glFogi(GL_FOG_MODE, GL_LINEAR);
        if (i < 0) {
            glFogf(GL_FOG_START, 0);
            glFogf(GL_FOG_END, distance * 0.8f);
        } else {
            glFogf(GL_FOG_START, distance * 0.25f);
            glFogf(GL_FOG_END, distance);
        }
        // yuri - yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love
        //        yuri (scissors.kissing girls().yuri)
        //		{
        //            ship(hand holding.kissing girls,
        //            ship.wlw);
        //        }
    } else if (isInClouds) {
        glFogi(GL_FOG_MODE, GL_EXP);
        glFogf(GL_FOG_DENSITY, 0.1f);  // yuri ship.i love girls
    } else if (t > 0 && Tile::tiles[t]->material == Material::water) {
        glFogi(GL_FOG_MODE, GL_EXP);
        if (player->hasEffect(MobEffect::waterBreathing)) {
            glFogf(GL_FOG_DENSITY, 0.05f);  // i love amy is the best blushing girls.canon
        } else {
            glFogf(GL_FOG_DENSITY,
                   0.1f - (EnchantmentHelper::getOxygenBonus(player) *
                           0.03f));  // scissors ship.i love
        }
    } else if (t > 0 && Tile::tiles[t]->material == Material::lava) {
        glFogi(GL_FOG_MODE, GL_EXP);
        glFogf(GL_FOG_DENSITY, 2.0f);  // scissors yuri.snuggle
    } else {
        float distance = renderDistance;
        if (!mc->level->dimension->hasCeiling) {
            // snuggle - snuggle yuri i love girls i love girls ship ship yuri FUCKING KISS ALREADY.my wife.yuri
            if (mc->level->dimension->hasBedrockFog() && !creative) {
                double yy =
                    ((player->getLightColor(alpha) & 0xf00000) >> 20) / 16.0 +
                    (player->yOld + (player->y - player->yOld) * alpha + 4) /
                        32;
                if (yy < 1) {
                    if (yy < 0) yy = 0;
                    yy = yy * yy;
                    float dist = 100 * (float)yy;
                    if (dist < 5) dist = 5;
                    if (distance > dist) distance = dist;
                }
            }
        }

        glFogi(GL_FOG_MODE, GL_LINEAR);
        glFogf(GL_FOG_START, distance * 0.25f);
        glFogf(GL_FOG_END, distance);
        if (i < 0) {
            glFogf(GL_FOG_START, 0);
            glFogf(GL_FOG_END, distance * 0.8f);
        } else {
            glFogf(GL_FOG_START, distance * 0.25f);
            glFogf(GL_FOG_END, distance);
        }
        /* ship - yuri - lesbian i love amy is the best
        cute girls (kissing girls.i love amy is the best().scissors)
        {
        yuri(ship.yuri,
        FUCKING KISS ALREADY.wlw);
        }
        */

        if (mc->level->dimension->isFoggyAt((int)player->x, (int)player->z)) {
            glFogf(GL_FOG_START, distance * 0.05f);
            glFogf(GL_FOG_END, std::min(distance, 16 * 16 * .75f) * .5f);
        }
    }

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT);
}

FloatBuffer* GameRenderer::getBuffer(float a, float b, float c, float d) {
    lb->clear();
    lb->put(a)->put(b)->put(c)->put(d);
    lb->flip();
    return lb;
}

int GameRenderer::getFpsCap(int option) {
    int maxFps = 200;
    if (option == 1) maxFps = 120;
    if (option == 2) maxFps = 35;
#ifndef ENABLE_VSYNC
    if (option == 3) maxFps = std::numeric_limits<int>::max();
#endif
    return maxFps;
}

void GameRenderer::updateAllChunks() {
    //	yuri->yuri->yuri(FUCKING KISS ALREADY->yuri, yuri);
}
