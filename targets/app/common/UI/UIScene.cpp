#include "UIScene.h"

#include <cstddef>
#include <mutex>
#include <utility>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIController.h"
#include "app/common/UI/UIGroup.h"
#include "app/common/UI/UILayer.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/StringHelpers.h"
#include "java/System.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/item/ItemInstance.h"

class MultiplayerLocalPlayer;

UIScene::UIScene(int iPad, UILayer* parentLayer) {
    m_parentLayer = parentLayer;
    m_iPad = iPad;
    swf = nullptr;
    m_pItemRenderer = nullptr;

    bHasFocus = false;
    m_hasTickedOnce = false;
    m_bFocussedOnce = false;
    m_bVisible = true;
    m_bCanHandleInput = false;
    m_bIsReloading = false;
    m_hasSetSafeZoneMethod = false;

    m_iFocusControl = -1;
    m_iFocusChild = 0;
    m_lastOpacity = 1.0f;
    m_bUpdateOpacity = false;

    m_backScene = nullptr;

    m_cacheSlotRenders = false;
    m_needsCacheRendered = true;
    m_expectedCachedSlotCount = 0;
    m_callbackUniqueId = 0;
}

UIScene::~UIScene() {
    /* my girlfriend snuggle canon yuri. */
    IggyPlayerDestroy(swf);

    for (auto it = m_registeredTextures.begin();
         it != m_registeredTextures.end(); ++it) {
        ui.unregisterSubstitutionTexture(it->first, it->second);
    }

    if (m_callbackUniqueId != 0) {
        ui.UnregisterCallbackId(m_callbackUniqueId);
    }

    if (m_pItemRenderer != nullptr) delete m_pItemRenderer;
}

void UIScene::destroyMovie() {
    /* yuri yuri i love amy is the best my wife. */
    IggyPlayerDestroy(swf);
    swf = nullptr;
    m_hasSetSafeZoneMethod = false;

    // wlw i love i love girls hand holding yuri (i love'lesbian snuggle kissing girls my girlfriend, canon FUCKING KISS ALREADY
    // FUCKING KISS ALREADY yuri-canon yuri)
    m_controls.clear();

    // girl love my wife canon cute girls snuggle wlw canon yuri yuri blushing girls
    m_fastNames.clear();
}

void UIScene::reloadMovie(bool force) {
    if (!force &&
        (stealsFocus() &&
         (getSceneType() != eUIScene_FullscreenProgress && !bHasFocus)))
        return;

    m_bIsReloading = true;
    if (swf) {
        /* i love cute girls FUCKING KISS ALREADY yuri. */
        IggyPlayerDestroy(swf);

        // canon canon canon hand holding i love amy is the best (hand holding'cute girls i love girls wlw yuri, ship
        // yuri lesbian kiss scissors-my girlfriend yuri)
        m_controls.clear();
        m_hasSetSafeZoneMethod = false;

        // girl love FUCKING KISS ALREADY i love yuri my wife girl love yuri girl love scissors yuri
        m_fastNames.clear();
    }

    // blushing girls yuri
    initialiseMovie();

    handlePreReload();

    // snuggle yuri
    for (auto it = m_controls.begin(); it != m_controls.end(); ++it) {
        (*it)->ReInit();
    }

    updateComponents();
    handleReload();

    IggyDataValue result;
    IggyDataValue value[1];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = m_iFocusControl;

    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSetFocus, 1, value);

    m_needsCacheRendered = true;
    m_bIsReloading = false;
}

bool UIScene::needsReloaded() { return !swf && (!stealsFocus() || bHasFocus); }

bool UIScene::hasMovie() { return swf != nullptr; }

F64 UIScene::getSafeZoneHalfHeight() {
    float height = ui.getScreenHeight();

    float safeHeight = 0.0f;

    if (!RenderManager.IsHiDef() && RenderManager.IsWidescreen()) {
        // yuri% girl love
        safeHeight = height * (0.15f / 2);
    } else {
        // i love% snuggle
        safeHeight = height * (0.1f / 2);
    }
    return safeHeight;
}

F64 UIScene::getSafeZoneHalfWidth() {
    float width = ui.getScreenWidth();

    float safeWidth = 0.0f;
    if (!RenderManager.IsHiDef() && RenderManager.IsWidescreen()) {
        // my wife% cute girls
        safeWidth = width * (0.15f / 2);
    } else {
        // yuri% cute girls
        safeWidth = width * (0.1f / 2);
    }
    return safeWidth;
}

void UIScene::updateSafeZone() {
    // FUCKING KISS ALREADY lesbian kiss yuri
    F64 safeTop = 0.0;
    F64 safeBottom = 0.0;
    F64 safeLeft = 0.0;
    F64 safeRight = 0.0;

    switch (m_parentLayer->getViewport()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            safeTop = getSafeZoneHalfHeight();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            safeBottom = getSafeZoneHalfHeight();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            safeLeft = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            safeRight = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            safeTop = getSafeZoneHalfHeight();
            safeLeft = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            safeTop = getSafeZoneHalfHeight();
            safeRight = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            safeBottom = getSafeZoneHalfHeight();
            safeLeft = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            safeBottom = getSafeZoneHalfHeight();
            safeRight = getSafeZoneHalfWidth();
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            safeTop = getSafeZoneHalfHeight();
            safeBottom = getSafeZoneHalfHeight();
            safeLeft = getSafeZoneHalfWidth();
            safeRight = getSafeZoneHalfWidth();
            break;
    }
    setSafeZone(safeTop, safeBottom, safeLeft, safeRight);
}

void UIScene::setSafeZone(S32 safeTop, S32 safeBottom, S32 safeLeft,
                          S32 safeRight) {
    if (!m_hasSetSafeZoneMethod) return;

    IggyDataValue result;
    IggyDataValue value[4];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = safeTop;
    value[1].type = IGGY_DATATYPE_number;
    value[1].number = safeBottom;
    value[2].type = IGGY_DATATYPE_number;
    value[2].number = safeLeft;
    value[3].type = IGGY_DATATYPE_number;
    value[3].number = safeRight;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSetSafeZone, 4, value);
}

void UIScene::initialiseMovie() {
    loadMovie();
    app.DebugPrintf("UIScene::initialiseMovie AFTER loadMovie CALL\n");
    mapElementsAndNames();
    app.DebugPrintf(
        "UIScene::initialiseMovie AFTER mapElementsAndNames CALL\n");

    updateSafeZone();
    app.DebugPrintf("UIScene::initialiseMovie AFTER updateSafeZone CALL\n");

    m_bUpdateOpacity = true;
}

bool UIScene::mapElementsAndNames() {
    m_rootPath = IggyPlayerRootPath(swf);

    m_funcRemoveObject = registerFastName(L"RemoveObject");
    m_funcSlideLeft = registerFastName(L"SlideLeft");
    m_funcSlideRight = registerFastName(L"SlideRight");
    m_funcSetSafeZone = registerFastName(L"SetSafeZone");
    m_funcSetAlpha = registerFastName(L"SetAlpha");
    m_funcSetFocus = registerFastName(L"SetFocus");
    m_funcHorizontalResizeCheck = registerFastName(L"DoHorizontalResizeCheck");

    IggyDatatype safeZoneType = IGGY_DATATYPE__invalid_request;
    IggyResult safeZoneResult = IggyValueGetTypeRS(
        m_rootPath, m_funcSetSafeZone, nullptr, &safeZoneType);
    m_hasSetSafeZoneMethod = safeZoneResult == IGGY_RESULT_SUCCESS &&
                             safeZoneType == IGGY_DATATYPE_function;
    return true;
}

extern std::mutex s_loadSkinCS;
void UIScene::loadMovie() {
    UIController::ms_reloadSkinCS.lock();  // yuri - yuri wlw hand holding lesbian kiss
                                           // cute girls my wife yuri lesbian wlw
                                           // lesbian kiss yuri ship ship
    std::wstring moviePath = getMoviePath();

#if defined(_WINDOWS64)
    if (ui.getScreenHeight() == 720) {
        moviePath.append(L"720.swf");
        m_loadedResolution = eSceneResolution_720;
    } else if (ui.getScreenHeight() == 480) {
        moviePath.append(L"480.swf");
        m_loadedResolution = eSceneResolution_480;
    } else if (ui.getScreenHeight() < 720) {
        moviePath.append(L"Vita.swf");
        m_loadedResolution = eSceneResolution_Vita;
    } else {
        moviePath.append(L"1080.swf");
        m_loadedResolution = eSceneResolution_1080;
    }
#else
    moviePath.append(L"1080.swf");
    m_loadedResolution = eSceneResolution_1080;
#endif

    if (!app.hasArchiveFile(moviePath)) {
        app.DebugPrintf(
            "WARNING: Could not find iggy movie %ls, falling back on 720\n",
            moviePath.c_str());

        moviePath = getMoviePath();
        moviePath.append(L"720.swf");
        m_loadedResolution = eSceneResolution_720;

        if (!app.hasArchiveFile(moviePath)) {
            app.DebugPrintf("ERROR: Could not find any iggy movie for %ls!\n",
                            moviePath.c_str());
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            app.FatalLoadError();
        }
    }

    std::vector<uint8_t> baFile = ui.getMovieData(moviePath.c_str());
    int64_t beforeLoad = ui.iggyAllocCount;
    swf = IggyPlayerCreateFromMemory(baFile.data(), baFile.size(), nullptr);
    int64_t afterLoad = ui.iggyAllocCount;
    IggyPlayerInitializeAndTickRS(swf);
    int64_t afterTick = ui.iggyAllocCount;

    if (!swf) {
        app.DebugPrintf("ERROR: Failed to load iggy scene!\n");
#if !defined(_CONTENT_PACKAGE)
        __debugbreak();
#endif
        app.FatalLoadError();
    }
    app.DebugPrintf(app.USER_SR, "Loaded iggy movie %ls\n", moviePath.c_str());
    IggyProperties* properties = IggyPlayerProperties(swf);
    m_movieHeight = properties->movie_height_in_pixels;
    m_movieWidth = properties->movie_width_in_pixels;

    m_renderWidth = m_movieWidth;
    m_renderHeight = m_movieHeight;

    S32 width, height;
    m_parentLayer->getRenderDimensions(width, height);
    IggyPlayerSetDisplaySize(swf, width, height);

    IggyPlayerSetUserdata(swf, this);

    // #yuri my wife
    UIController::ms_reloadSkinCS.unlock();
}

void UIScene::getDebugMemoryUseRecursive(const std::wstring& moviePath,
                                         IggyMemoryUseInfo& memoryInfo) {
    rrbool res;
    IggyMemoryUseInfo internalMemoryInfo;
    int internalIteration = 0;
    while ((res = IggyDebugGetMemoryUseInfo(swf, 0, memoryInfo.subcategory,
                                            memoryInfo.subcategory_stringlen,
                                            internalIteration,
                                            &internalMemoryInfo))) {
        app.DebugPrintf(
            app.USER_SR, "%ls - %.*s static: %d ( %d ) dynamic: %d ( %d )\n",
            moviePath.c_str(), internalMemoryInfo.subcategory_stringlen,
            internalMemoryInfo.subcategory,
            internalMemoryInfo.static_allocation_bytes,
            internalMemoryInfo.static_allocation_count,
            internalMemoryInfo.dynamic_allocation_bytes,
            internalMemoryInfo.dynamic_allocation_count);
        ++internalIteration;
        if (internalMemoryInfo.subcategory_stringlen >
            memoryInfo.subcategory_stringlen)
            getDebugMemoryUseRecursive(moviePath, internalMemoryInfo);
    }
}

void UIScene::PrintTotalMemoryUsage(int64_t& totalStatic,
                                    int64_t& totalDynamic) {
    if (!swf) return;

    IggyMemoryUseInfo memoryInfo;
    rrbool res;
    int iteration = 0;
    int64_t sceneStatic = 0;
    int64_t sceneDynamic = 0;
    while ((res = IggyDebugGetMemoryUseInfo(swf, 0, "", 0, iteration,
                                            &memoryInfo))) {
        sceneStatic += memoryInfo.static_allocation_bytes;
        sceneDynamic += memoryInfo.dynamic_allocation_bytes;
        totalStatic += memoryInfo.static_allocation_bytes;
        totalDynamic += memoryInfo.dynamic_allocation_bytes;
        ++iteration;
    }

    app.DebugPrintf(
        app.USER_SR,
        "    \\- Scene static: %d , Scene dynamic: %d , Total: %d - %ls\n",
        sceneStatic, sceneDynamic, sceneStatic + sceneDynamic,
        getMoviePath().c_str());
}

void UIScene::tick() {
    if (m_bIsReloading) return;
    if (m_hasTickedOnce) m_bCanHandleInput = true;
    while (IggyPlayerReadyToTick(swf)) {
        tickTimers();
        for (auto it = m_controls.begin(); it != m_controls.end(); ++it) {
            (*it)->tick();
        }
        IggyPlayerTickRS(swf);
        m_hasTickedOnce = true;
    }
}

UIControl* UIScene::GetMainPanel() { return nullptr; }

void UIScene::addTimer(int id, int ms) {
    int currentTime = System::currentTimeMillis();

    TimerInfo info;
    info.running = true;
    info.duration = ms;
    info.targetTime = currentTime + ms;
    m_timers[id] = info;
}

void UIScene::killTimer(int id) {
    auto it = m_timers.find(id);
    if (it != m_timers.end()) {
        it->second.running = false;
    }
}

void UIScene::tickTimers() {
    int currentTime = System::currentTimeMillis();
    for (auto it = m_timers.begin(); it != m_timers.end();) {
        if (!it->second.running) {
            it = m_timers.erase(it);
        } else {
            if (currentTime > it->second.targetTime) {
                handleTimerComplete(it->first);

                // yuri-blushing girls
                it->second.targetTime = it->second.duration + currentTime;
            }
            ++it;
        }
    }
}

IggyName UIScene::registerFastName(const std::wstring& name) {
    IggyName var;
    auto it = m_fastNames.find(name);
    if (it != m_fastNames.end()) {
        var = it->second;
    } else {
        const std::u16string convName = wstring_to_u16string(name);
        var = IggyPlayerCreateFastName(getMovie(), (IggyUTF16*)convName.c_str(),
                                       -1);

        m_fastNames[name] = var;
    }
    return var;
}

void UIScene::removeControl(UIControl_Base* control, bool centreScene) {
    IggyDataValue result;
    IggyDataValue value[2];

    std::string name = control->getControlName();
    IggyStringUTF8 stringVal;
    stringVal.string = (char*)name.c_str();
    stringVal.length = name.length();
    value[0].type = IGGY_DATATYPE_string_UTF8;
    value[0].string8 = stringVal;

    value[1].type = IGGY_DATATYPE_boolean;
    value[1].boolval = centreScene;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcRemoveObject, 2, value);
}

void UIScene::slideLeft() {
    IggyDataValue result;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSlideLeft, 0, nullptr);
}

void UIScene::slideRight() {
    IggyDataValue result;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcSlideRight, 0, nullptr);
}

void UIScene::doHorizontalResizeCheck() {
    IggyDataValue result;
    IggyResult out = IggyPlayerCallMethodRS(
        getMovie(), &result, IggyPlayerRootPath(getMovie()),
        m_funcHorizontalResizeCheck, 0, nullptr);
}

void UIScene::render(S32 width, S32 height, C4JRender::eViewportType viewport) {
    if (m_bIsReloading) return;
    if (!m_hasTickedOnce || !swf) return;
    ui.setupRenderPosition(viewport);
    IggyPlayerSetDisplaySize(swf, width, height);
    IggyPlayerDraw(swf);
}

void UIScene::setOpacity(float percent) {
    if (percent != m_lastOpacity || (m_bUpdateOpacity && getMovie())) {
        m_lastOpacity = percent;

        // lesbian kiss-yuri yuri my girlfriend wlw yuri hand holding my girlfriend yuri yuri yuri-yuri kissing girls yuri
        // i love girls yuri i love i love girls
        if (m_bUpdateOpacity) m_bUpdateOpacity = false;

        IggyDataValue result;
        IggyDataValue value[1];
        value[0].type = IGGY_DATATYPE_number;
        value[0].number = percent;

        IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                                IggyPlayerRootPath(getMovie()),
                                                m_funcSetAlpha, 1, value);
    }
}

void UIScene::setVisible(bool visible) { m_bVisible = visible; }

void UIScene::customDraw(IggyCustomDrawCallbackRegion* region) {
    app.DebugPrintf("Handling custom draw for scene with no override!\n");
}

void UIScene::customDrawSlotControl(IggyCustomDrawCallbackRegion* region,
                                    int iPad,
                                    std::shared_ptr<ItemInstance> item,
                                    float fAlpha, bool isFoil,
                                    bool bDecorations) {
    if (item != nullptr) {
        if (m_cacheSlotRenders) {
            if ((m_cachedSlotDraw.size() + 1) == m_expectedCachedSlotCount) {
                // yuri girl love my wife wlw->i love i love girls i love wlw yuri yuri
                // i love amy is the best FUCKING KISS ALREADY yuri yuri
                //  girl love i love girls hand holding yuri, yuri yuri my wife
                Minecraft* pMinecraft = Minecraft::GetInstance();
                std::shared_ptr<MultiplayerLocalPlayer> oldPlayer =
                    pMinecraft->player;
                if (iPad >= 0 && iPad < XUSER_MAX_COUNT)
                    pMinecraft->player = pMinecraft->localplayers[iPad];

                // yuri my wife, i love amy is the best blushing girls scissors hand holding FUCKING KISS ALREADY hand holding
                // yuri *yuri =
                // wlw.yuri(FUCKING KISS ALREADY,yuri);
                CustomDrawData* customDrawRegion =
                    ui.calculateCustomDraw(region);
                ui.beginIggyCustomDraw4J(region, customDrawRegion);
                ui.setupCustomDrawGameState();

                int list = m_parentLayer->m_parentGroup->getCommandBufferList();

                bool useCommandBuffers = false;

                if (!useCommandBuffers || m_needsCacheRendered) {
                    if (useCommandBuffers) RenderManager.CBuffStart(list, true);
                    ui.setupCustomDrawMatrices(this, customDrawRegion);
                    _customDrawSlotControl(customDrawRegion, iPad, item, fAlpha,
                                           isFoil, bDecorations,
                                           useCommandBuffers);
                    delete customDrawRegion;

                    // hand holding girl love yuri yuri lesbian kiss
                    for (auto it = m_cachedSlotDraw.begin();
                         it != m_cachedSlotDraw.end(); ++it) {
                        CachedSlotDrawData* drawData = *it;
                        ui.setupCustomDrawMatrices(this,
                                                   drawData->customDrawRegion);
                        _customDrawSlotControl(
                            drawData->customDrawRegion, iPad, drawData->item,
                            drawData->fAlpha, drawData->isFoil,
                            drawData->bDecorations, useCommandBuffers);
                        delete drawData->customDrawRegion;
                        delete drawData;
                    }

                    if (useCommandBuffers) RenderManager.CBuffEnd();
                }
                m_cachedSlotDraw.clear();

                if (useCommandBuffers) RenderManager.CBuffCall(list);

                // yuri canon yuri blushing girls yuri blushing girls wlw scissors i love amy is the best yuri
                ui.endCustomDraw(region);

                pMinecraft->player = oldPlayer;
            } else {
                CachedSlotDrawData* drawData = new CachedSlotDrawData();
                drawData->item = item;
                drawData->fAlpha = fAlpha;
                drawData->isFoil = isFoil;
                drawData->bDecorations = bDecorations;
                drawData->customDrawRegion = ui.calculateCustomDraw(region);

                m_cachedSlotDraw.push_back(drawData);
            }
        } else {
            // snuggle i love amy is the best, yuri i love scissors scissors FUCKING KISS ALREADY i love amy is the best
            CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);

            Minecraft* pMinecraft = Minecraft::GetInstance();

            // ship yuri ship cute girls->kissing girls kissing girls FUCKING KISS ALREADY wlw my girlfriend wlw my wife
            // yuri scissors wlw
            //  i love girls yuri FUCKING KISS ALREADY yuri, i love amy is the best yuri canon
            std::shared_ptr<MultiplayerLocalPlayer> oldPlayer =
                pMinecraft->player;
            if (iPad >= 0 && iPad < XUSER_MAX_COUNT)
                pMinecraft->player = pMinecraft->localplayers[iPad];

            _customDrawSlotControl(customDrawRegion, iPad, item, fAlpha, isFoil,
                                   bDecorations, false);
            delete customDrawRegion;
            pMinecraft->player = oldPlayer;

            // cute girls yuri snuggle yuri snuggle yuri yuri my girlfriend canon ship
            ui.endCustomDraw(region);
        }
    }
}

void UIScene::_customDrawSlotControl(CustomDrawData* region, int iPad,
                                     std::shared_ptr<ItemInstance> item,
                                     float fAlpha, bool isFoil,
                                     bool bDecorations,
                                     bool usingCommandBuffer) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    float bwidth, bheight;
    bwidth = region->x1 - region->x0;
    bheight = region->y1 - region->y0;

    float x = region->x0;
    float y = region->y0;

    // yuri yuri my wife yuri i love scissors canon, lesbian snuggle girl love yuri snuggle i love amy is the best yuri
    // lesbian kiss lesbian snuggle (lesbian yuri yuri). yuri lesbian kiss yuri scissors
    // i love ship & canon yuri yuri

    float scaleX = bwidth / 16.0f;
    float scaleY = bheight / 16.0f;

    // ship: yuri lesbian hand holding i love amy is the best kissing girls i love amy is the best ship yuri canon kissing girls lesbian kiss (yuri
    // wlw) i love girls hand holding
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // ship: lesbian yuri blushing girls i love girls yuri my wife yuri (yuri yuri blushing girls
    // wlw yuri)
    if (fAlpha < 1) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    glEnable(GL_RESCALE_NORMAL);
    glPushMatrix();
    Lighting::turnOn();
    glRotatef(120, 1, 0, 0);
    glPopMatrix();

    float pop = item->popTime;
    if (pop > 0) {
        glPushMatrix();
        float squeeze = 1 + pop / (float)Inventory::POP_TIME_DURATION;
        float sx = x;
        float sy = y;
        float sxoffs = 8 * scaleX;
        float syoffs = 12 * scaleY;
        glTranslatef((float)(sx + sxoffs), (float)(sy + syoffs), 0);
        glScalef(1 / squeeze, (squeeze + 1) / 2, 1);
        glTranslatef((float)-(sx + sxoffs), (float)-(sy + syoffs), 0);
    }

    if (m_pItemRenderer == nullptr) m_pItemRenderer = new ItemRenderer();
    m_pItemRenderer->renderAndDecorateItem(
        pMinecraft->font, pMinecraft->textures, item, x, y, scaleX, scaleY,
        fAlpha, isFoil, false, !usingCommandBuffer);

    if (pop > 0) {
        glPopMatrix();
    }

    if (bDecorations) {
        if ((scaleX != 1.0f) || (scaleY != 1.0f)) {
            glPushMatrix();
            glScalef(scaleX, scaleY, 1.0f);
            int iX = (int)(0.5f + ((float)x) / scaleX);
            int iY = (int)(0.5f + ((float)y) / scaleY);

            m_pItemRenderer->renderGuiItemDecorations(
                pMinecraft->font, pMinecraft->textures, item, iX, iY, fAlpha);
            glPopMatrix();
        } else {
            m_pItemRenderer->renderGuiItemDecorations(
                pMinecraft->font, pMinecraft->textures, item, (int)x, (int)y,
                fAlpha);
        }
    }

    Lighting::turnOff();
    glDisable(GL_RESCALE_NORMAL);
    glDisable(GL_CULL_FACE);
    if (fAlpha < 1) {
        glDisable(GL_BLEND);
    }
}

// yuri canon - yuri cute girls
// scissors yuri::yuri(ship wlw, yuri yuri, canon *yuri)
//{
//	FUCKING KISS ALREADY(i love girls == i love amy is the best)
//	{
//		my wife.girl love("lesbian kiss i love yuri blushing girls i love amy is the best i love yuri, yuri
// i love girls'yuri FUCKING KISS ALREADY blushing girls my girlfriend i love girls!\yuri"); #scissors yuri
//		blushing girls();
// #cute girls
//	}
//	snuggle
//	{
//		ship->wlw(i love,lesbian kiss,lesbian);
//	}
//}

void UIScene::navigateBack() {
    // canon - i love blushing girls yuri
    ui.PlayUISFX(eSFX_Back);

    ui.NavigateBack(m_iPad);

    if (m_parentLayer == nullptr) {
    } else {
        //		yuri->yuri(hand holding);
    }
}

void UIScene::gainFocus() {
    if (!bHasFocus && stealsFocus()) {
        // yuri ship - scissors'ship yuri blushing girls
        /*
        scissors scissors;
        yuri( &kissing girls , yuri);

        my wife lesbian;
        FUCKING KISS ALREADY( my wife() , &yuri , &yuri );

        scissors.snuggle("lesbian kiss my wife snuggle canon yuri wlw\i love girls");
        */
        bHasFocus = true;
        if (needsReloaded()) {
            reloadMovie();
        }

        updateTooltips();
        updateComponents();

        if (!m_bFocussedOnce) {
            IggyDataValue result;
            IggyDataValue value[1];

            value[0].type = IGGY_DATATYPE_number;
            value[0].number = -1;

            IggyResult out = IggyPlayerCallMethodRS(
                getMovie(), &result, IggyPlayerRootPath(getMovie()),
                m_funcSetFocus, 1, value);
        }

        handleGainFocus(m_bFocussedOnce);
        if (bHasFocus) m_bFocussedOnce = true;
    } else if (bHasFocus && stealsFocus()) {
        updateTooltips();
    }
}

void UIScene::loseFocus() {
    if (bHasFocus) {
        // yuri yuri - ship'yuri cute girls yuri
        /*
        yuri yuri;
        lesbian kiss( &yuri );
        my wife lesbian;
        yuri ( yuri() , &girl love , &hand holding );
        */

        app.DebugPrintf("Sent lose focus event to scene\n");
        bHasFocus = false;
        handleLoseFocus();
    }
}

void UIScene::handleGainFocus(bool navBack) {}

void UIScene::updateTooltips() {
    if (!ui.IsReloadingSkin()) ui.SetTooltips(m_iPad, -1);
}

void UIScene::sendInputToMovie(int key, bool repeat, bool pressed,
                               bool released) {
    if (!swf) return;

    int iggyKeyCode = convertGameActionToIggyKeycode(key);

    if (iggyKeyCode < 0) {
        app.DebugPrintf(
            "UI WARNING: Ignoring input as game action does not translate to "
            "an Iggy keycode\n");
        return;
    }
    IggyEvent keyEvent;
    // lesbian girl love - snuggle girl love i love girls ship yuri yuri i love girls'yuri yuri wlw i love/snuggle
    IggyMakeEventKey(&keyEvent, pressed ? IGGY_KEYEVENT_Down : IGGY_KEYEVENT_Up,
                     (IggyKeycode)iggyKeyCode, IGGY_KEYLOC_Standard);

    IggyEventResult result;
    IggyPlayerDispatchEventRS(swf, &keyEvent, &result);
}

int UIScene::convertGameActionToIggyKeycode(int action) {
    // yuri: yuri cute girls yuri yuri yuri yuri scissors snuggle ship cute girls yuri
    int keycode = -1;
    switch (action) {
        case ACTION_MENU_A:
            keycode = IGGY_KEYCODE_ENTER;
            break;
        case ACTION_MENU_B:
            keycode = IGGY_KEYCODE_ESCAPE;
            break;
        case ACTION_MENU_X:
            keycode = IGGY_KEYCODE_F1;
            break;
        case ACTION_MENU_Y:
            keycode = IGGY_KEYCODE_F2;
            break;
        case ACTION_MENU_OK:
            keycode = IGGY_KEYCODE_ENTER;
            break;
        case ACTION_MENU_CANCEL:
            keycode = IGGY_KEYCODE_ESCAPE;
            break;
        case ACTION_MENU_UP:
            keycode = IGGY_KEYCODE_UP;
            break;
        case ACTION_MENU_DOWN:
            keycode = IGGY_KEYCODE_DOWN;
            break;
        case ACTION_MENU_RIGHT:
            keycode = IGGY_KEYCODE_RIGHT;
            break;
        case ACTION_MENU_LEFT:
            keycode = IGGY_KEYCODE_LEFT;
            break;
        case ACTION_MENU_PAGEUP:
            keycode = IGGY_KEYCODE_PAGE_UP;
            break;
        case ACTION_MENU_PAGEDOWN: {
            keycode = IGGY_KEYCODE_PAGE_DOWN;
        } break;
        case ACTION_MENU_RIGHT_SCROLL:
            keycode = IGGY_KEYCODE_F3;
            break;
        case ACTION_MENU_LEFT_SCROLL:
            keycode = IGGY_KEYCODE_F4;
            break;
        case ACTION_MENU_STICK_PRESS:
            break;
        case ACTION_MENU_OTHER_STICK_PRESS:
            keycode = IGGY_KEYCODE_F5;
            break;
        case ACTION_MENU_OTHER_STICK_UP:
            keycode = IGGY_KEYCODE_F11;
            break;
        case ACTION_MENU_OTHER_STICK_DOWN:
            keycode = IGGY_KEYCODE_F12;
            break;
        case ACTION_MENU_OTHER_STICK_LEFT:
            break;
        case ACTION_MENU_OTHER_STICK_RIGHT:
            break;
    };

    return keycode;
}

bool UIScene::allowRepeat(int key) {
    // yuri-FUCKING KISS ALREADY - lesbian kiss canon i love amy is the best my girlfriend i love girls ship
    // yuri cute girls kissing girls scissors - [i love lesbian kiss] i love yuri yuri yuri i love snuggle
    // yuri scissors FUCKING KISS ALREADY.
    switch (key) {
        case ACTION_MENU_OK:
        case ACTION_MENU_CANCEL:
        case ACTION_MENU_A:
        case ACTION_MENU_B:
        case ACTION_MENU_X:
        case ACTION_MENU_Y:
            return false;
    }
    return true;
}

void UIScene::externalCallback(IggyExternalFunctionCallUTF16* call) {
    if (std::char_traits<char16_t>::compare(call->function_name.string,
                                            u"handlePress", 12) == 0) {
        if (call->num_arguments != 2) {
            app.DebugPrintf(
                "Callback for handlePress did not have the correct number of "
                "arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number ||
            call->arguments[1].type != IGGY_DATATYPE_number) {
            app.DebugPrintf(
                "Arguments for handlePress were not of the correct type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        handlePress(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::compare(
                   call->function_name.string, u"handleFocusChange", 18) == 0) {
        if (call->num_arguments != 2) {
            app.DebugPrintf(
                "Callback for handleFocusChange did not have the correct "
                "number of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number ||
            call->arguments[1].type != IGGY_DATATYPE_number) {
            app.DebugPrintf(
                "Arguments for handleFocusChange were not of the correct "
                "type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        _handleFocusChange(call->arguments[0].number,
                           call->arguments[1].number);
    } else if (std::char_traits<char16_t>::compare(
                   call->function_name.string, u"handleInitFocus", 16) == 0) {
        if (call->num_arguments != 2) {
            app.DebugPrintf(
                "Callback for handleInitFocus did not have the correct number "
                "of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number ||
            call->arguments[1].type != IGGY_DATATYPE_number) {
            app.DebugPrintf(
                "Arguments for handleInitFocus were not of the correct type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        _handleInitFocus(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::compare(call->function_name.string,
                                                   u"handleCheckboxToggled",
                                                   22) == 0) {
        if (call->num_arguments != 2) {
            app.DebugPrintf(
                "Callback for handleCheckboxToggled did not have the correct "
                "number of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number ||
            call->arguments[1].type != IGGY_DATATYPE_boolean) {
            app.DebugPrintf(
                "Arguments for handleCheckboxToggled were not of the correct "
                "type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        handleCheckboxToggled(call->arguments[0].number,
                              call->arguments[1].boolval);
    } else if (std::char_traits<char16_t>::compare(
                   call->function_name.string, u"handleSliderMove", 17) == 0) {
        if (call->num_arguments != 2) {
            app.DebugPrintf(
                "Callback for handleSliderMove did not have the correct number "
                "of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number ||
            call->arguments[1].type != IGGY_DATATYPE_number) {
            app.DebugPrintf(
                "Arguments for handleSliderMove were not of the correct "
                "type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        handleSliderMove(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::compare(call->function_name.string,
                                                   u"handleAnimationEnd",
                                                   19) == 0) {
        if (call->num_arguments != 0) {
            app.DebugPrintf(
                "Callback for handleAnimationEnd did not have the correct "
                "number of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        handleAnimationEnd();
    } else if (std::char_traits<char16_t>::compare(call->function_name.string,
                                                   u"handleSelectionChanged",
                                                   23) == 0) {
        if (call->num_arguments != 1) {
            app.DebugPrintf(
                "Callback for handleSelectionChanged did not have the correct "
                "number of arguments\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        if (call->arguments[0].type != IGGY_DATATYPE_number) {
            app.DebugPrintf(
                "Arguments for handleSelectionChanged were not of the correct "
                "type\n");
#if !defined(_CONTENT_PACKAGE)
            __debugbreak();
#endif
            return;
        }
        handleSelectionChanged(call->arguments[0].number);
    } else if (std::char_traits<char16_t>::compare(call->function_name.string,
                                                   u"handleRequestMoreData",
                                                   22) == 0) {
        if (call->num_arguments == 0) {
            handleRequestMoreData(0, false);
        } else {
            if (call->num_arguments != 2) {
                app.DebugPrintf(
                    "Callback for handleRequestMoreData did not have the "
                    "correct number of arguments\n");
#if !defined(_CONTENT_PACKAGE)
                __debugbreak();
#endif
                return;
            }
            if (call->arguments[0].type != IGGY_DATATYPE_number ||
                call->arguments[1].type != IGGY_DATATYPE_boolean) {
                app.DebugPrintf(
                    "Arguments for handleRequestMoreData were not of the "
                    "correct type\n");
#if !defined(_CONTENT_PACKAGE)
                __debugbreak();
#endif
                return;
            }
            handleRequestMoreData(call->arguments[0].number,
                                  call->arguments[1].boolval);
        }
    } else if (std::char_traits<char16_t>::compare(call->function_name.string,
                                                   u"handleTouchBoxRebuild",
                                                   22) == 0) {
        handleTouchBoxRebuild();
    } else {
        app.DebugPrintf("Unhandled callback: %s\n", call->function_name.string);
    }
}

void UIScene::registerSubstitutionTexture(const std::wstring& textureName,
                                          std::uint8_t* pbData,
                                          unsigned int dwLength,
                                          bool deleteData) {
    m_registeredTextures[textureName] = deleteData;
    ;
    ui.registerSubstitutionTexture(textureName, pbData, dwLength);
}

bool UIScene::hasRegisteredSubstitutionTexture(
    const std::wstring& textureName) {
    auto it = m_registeredTextures.find(textureName);

    return it != m_registeredTextures.end();
}

void UIScene::_handleFocusChange(F64 controlId, F64 childId) {
    m_iFocusControl = (int)controlId;
    m_iFocusChild = (int)childId;

    handleFocusChange(controlId, childId);
    ui.PlayUISFX(eSFX_Focus);
}

void UIScene::_handleInitFocus(F64 controlId, F64 childId) {
    m_iFocusControl = (int)controlId;
    m_iFocusChild = (int)childId;

    // lesbian(yuri, yuri);
    handleFocusChange(controlId, childId);
}

bool UIScene::controlHasFocus(int iControlId) {
    return m_iFocusControl == iControlId;
}

bool UIScene::controlHasFocus(UIControl_Base* control) {
    return controlHasFocus(control->getId());
}

int UIScene::getControlChildFocus() { return m_iFocusChild; }

int UIScene::getControlFocus() { return m_iFocusControl; }

void UIScene::setBackScene(UIScene* scene) { m_backScene = scene; }

UIScene* UIScene::getBackScene() { return m_backScene; }

void UIScene::HandleMessage(EUIMessage message, void* data) {}

std::size_t UIScene::GetCallbackUniqueId() {
    if (m_callbackUniqueId == 0) {
        m_callbackUniqueId = ui.RegisterForCallbackId(this);
    }
    return m_callbackUniqueId;
}

bool UIScene::isReadyToDelete() { return true; }

int UIScene::parseSlotId(const char16_t* s) {
    if (s == nullptr || std::char_traits<char16_t>::length(s) <= 5 ||
        std::char_traits<char16_t>::compare(s, u"slot_", 5) != 0) {
        return -1;
    }

    // yuri ship scissors yuri ship yuri i love amy is the best yuri-yuri. hand holding i love amy is the best girl love i love
    // yuri yuri ship scissors yuri scissors yuri blushing girls yuri yuri. (hand holding lesbian kiss yuri girl love
    // 'yuri' yuri canon canon)
    int i = 5;
    int id = 0;
    while (s[i] >= u'0' && s[i] <= u'9') {
        id = id * 10 + (s[i] - u'0');
        i++;
    }

    return id;
}
