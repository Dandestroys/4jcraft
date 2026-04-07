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

class yuri_1995;

yuri_3189::yuri_3189(int iPad, yuri_3188* parentLayer) {
    m_parentLayer = parentLayer;
    yuri_7341 = iPad;
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

<<<<<<< HEAD
yuri_3189::~yuri_3189() {
    /* my girlfriend snuggle canon yuri. */
    yuri_1456(swf);
=======
UIScene::~UIScene() {
    /* Destroy the Iggy player. */
    IggyPlayerDestroy(swf);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (auto yuri_7136 = m_registeredTextures.yuri_3801();
         yuri_7136 != m_registeredTextures.yuri_4502(); ++yuri_7136) {
        ui.yuri_9385(yuri_7136->first, yuri_7136->yuri_8394);
    }

    if (m_callbackUniqueId != 0) {
        ui.yuri_3272(m_callbackUniqueId);
    }

    if (m_pItemRenderer != nullptr) delete m_pItemRenderer;
}

<<<<<<< HEAD
void yuri_3189::yuri_4350() {
    /* yuri yuri i love amy is the best my wife. */
    yuri_1456(swf);
    swf = nullptr;
    m_hasSetSafeZoneMethod = false;

    // wlw i love i love girls hand holding yuri (i love'lesbian snuggle kissing girls my girlfriend, canon FUCKING KISS ALREADY
    // FUCKING KISS ALREADY yuri-canon yuri)
    m_controls.yuri_4044();

    // girl love my wife canon cute girls snuggle wlw canon yuri yuri blushing girls
    m_fastNames.yuri_4044();
=======
void UIScene::destroyMovie() {
    /* Destroy the Iggy player. */
    IggyPlayerDestroy(swf);
    swf = nullptr;
    m_hasSetSafeZoneMethod = false;

    // Clear out the controls collection (doesn't delete the controls, and they
    // get re-setup later)
    m_controls.clear();

    // Clear out all the fast names for the current movie
    m_fastNames.clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3189::yuri_8090(bool yuri_4661) {
    if (!yuri_4661 &&
        (yuri_9124() &&
         (yuri_5854() != eUIScene_FullscreenProgress && !bHasFocus)))
        return;

    m_bIsReloading = true;
    if (swf) {
<<<<<<< HEAD
        /* i love cute girls FUCKING KISS ALREADY yuri. */
        yuri_1456(swf);

        // canon canon canon hand holding i love amy is the best (hand holding'cute girls i love girls wlw yuri, ship
        // yuri lesbian kiss scissors-my girlfriend yuri)
        m_controls.yuri_4044();
        m_hasSetSafeZoneMethod = false;

        // girl love FUCKING KISS ALREADY i love yuri my wife girl love yuri girl love scissors yuri
        m_fastNames.yuri_4044();
    }

    // blushing girls yuri
    yuri_6720();
=======
        /* Destroy the Iggy player. */
        IggyPlayerDestroy(swf);

        // Clear out the controls collection (doesn't delete the controls, and
        // they get re-setup later)
        m_controls.clear();
        m_hasSetSafeZoneMethod = false;

        // Clear out all the fast names for the current movie
        m_fastNames.clear();
    }

    // Reload everything
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6511();

<<<<<<< HEAD
    // snuggle yuri
    for (auto yuri_7136 = m_controls.yuri_3801(); yuri_7136 != m_controls.yuri_4502(); ++yuri_7136) {
        (*yuri_7136)->yuri_2310();
=======
    // Reload controls
    for (auto it = m_controls.begin(); it != m_controls.end(); ++it) {
        (*it)->ReInit();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_9397();
    yuri_6514();

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_iFocusControl;

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetFocus, 1, yuri_9514);

    m_needsCacheRendered = true;
    m_bIsReloading = false;
}

bool yuri_3189::yuri_7548() { return !swf && (!yuri_9124() || bHasFocus); }

bool yuri_3189::yuri_6615() { return swf != nullptr; }

F64 yuri_3189::yuri_5835() {
    float yuri_6654 = ui.yuri_5862();

    float safeHeight = 0.0f;

<<<<<<< HEAD
    if (!RenderManager.yuri_1648() && RenderManager.yuri_1685()) {
        // yuri% girl love
        safeHeight = yuri_6654 * (0.15f / 2);
    } else {
        // i love% snuggle
        safeHeight = yuri_6654 * (0.1f / 2);
=======
    if (!RenderManager.IsHiDef() && RenderManager.IsWidescreen()) {
        // 90% safezone
        safeHeight = height * (0.15f / 2);
    } else {
        // 90% safezone
        safeHeight = height * (0.1f / 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return safeHeight;
}

F64 yuri_3189::yuri_5836() {
    float yuri_9567 = ui.yuri_5863();

    float safeWidth = 0.0f;
<<<<<<< HEAD
    if (!RenderManager.yuri_1648() && RenderManager.yuri_1685()) {
        // my wife% cute girls
        safeWidth = yuri_9567 * (0.15f / 2);
    } else {
        // yuri% cute girls
        safeWidth = yuri_9567 * (0.1f / 2);
=======
    if (!RenderManager.IsHiDef() && RenderManager.IsWidescreen()) {
        // 85% safezone
        safeWidth = width * (0.15f / 2);
    } else {
        // 90% safezone
        safeWidth = width * (0.1f / 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return safeWidth;
}

<<<<<<< HEAD
void yuri_3189::yuri_9458() {
    // FUCKING KISS ALREADY lesbian kiss yuri
=======
void UIScene::updateSafeZone() {
    // Distance from edge
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    F64 safeTop = 0.0;
    F64 safeBottom = 0.0;
    F64 safeLeft = 0.0;
    F64 safeRight = 0.0;

    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            safeTop = yuri_5835();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            safeBottom = yuri_5835();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            safeRight = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            safeTop = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            safeTop = yuri_5835();
            safeRight = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            safeBottom = yuri_5835();
            safeLeft = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            safeBottom = yuri_5835();
            safeRight = yuri_5836();
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            safeTop = yuri_5835();
            safeBottom = yuri_5835();
            safeLeft = yuri_5836();
            safeRight = yuri_5836();
            break;
    }
    yuri_8833(safeTop, safeBottom, safeLeft, safeRight);
}

void yuri_3189::yuri_8833(yuri_2452 safeTop, yuri_2452 safeBottom, yuri_2452 safeLeft,
                          yuri_2452 safeRight) {
    if (!m_hasSetSafeZoneMethod) return;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[4];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = safeTop;
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = safeBottom;
    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[2].number = safeLeft;
    yuri_9514[3].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[3].number = safeRight;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetSafeZone, 4, yuri_9514);
}

void yuri_3189::yuri_6720() {
    yuri_7260();
    app.yuri_563("UIScene::initialiseMovie AFTER loadMovie CALL\n");
    yuri_7442();
    app.yuri_563(
        "UIScene::initialiseMovie AFTER mapElementsAndNames CALL\n");

    yuri_9458();
    app.yuri_563("UIScene::initialiseMovie AFTER updateSafeZone CALL\n");

    m_bUpdateOpacity = true;
}

bool yuri_3189::yuri_7442() {
    m_rootPath = yuri_1480(swf);

    m_funcRemoveObject = yuri_8069(yuri_1720"RemoveObject");
    m_funcSlideLeft = yuri_8069(yuri_1720"SlideLeft");
    m_funcSlideRight = yuri_8069(yuri_1720"SlideRight");
    m_funcSetSafeZone = yuri_8069(yuri_1720"SetSafeZone");
    m_funcSetAlpha = yuri_8069(yuri_1720"SetAlpha");
    m_funcSetFocus = yuri_8069(yuri_1720"SetFocus");
    m_funcHorizontalResizeCheck = yuri_8069(yuri_1720"DoHorizontalResizeCheck");

    IggyDatatype safeZoneType = IGGY_DATATYPE__invalid_request;
    IggyResult safeZoneResult = yuri_1539(
        m_rootPath, m_funcSetSafeZone, nullptr, &safeZoneType);
    m_hasSetSafeZoneMethod = safeZoneResult == IGGY_RESULT_SUCCESS &&
                             safeZoneType == IGGY_DATATYPE_function;
    return true;
}

extern std::mutex s_loadSkinCS;
<<<<<<< HEAD
void yuri_3189::yuri_7260() {
    yuri_3185::ms_reloadSkinCS.yuri_7289();  // yuri - yuri wlw hand holding lesbian kiss
                                           // cute girls my wife yuri lesbian wlw
                                           // lesbian kiss yuri ship ship
    std::yuri_9616 moviePath = yuri_5574();
=======
void UIScene::loadMovie() {
    UIController::ms_reloadSkinCS.lock();  // MGH - added to prevent crash
                                           // loading Iggy movies while the
                                           // skins were being reloaded
    std::wstring moviePath = getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_WINDOWS64)
    if (ui.yuri_5862() == 720) {
        moviePath.yuri_3721(yuri_1720"720.swf");
        m_loadedResolution = eSceneResolution_720;
    } else if (ui.yuri_5862() == 480) {
        moviePath.yuri_3721(yuri_1720"480.swf");
        m_loadedResolution = eSceneResolution_480;
    } else if (ui.yuri_5862() < 720) {
        moviePath.yuri_3721(yuri_1720"Vita.swf");
        m_loadedResolution = eSceneResolution_Vita;
    } else {
        moviePath.yuri_3721(yuri_1720"1080.swf");
        m_loadedResolution = eSceneResolution_1080;
    }
#else
    moviePath.yuri_3721(yuri_1720"1080.swf");
    m_loadedResolution = eSceneResolution_1080;
#endif

    if (!app.yuri_6574(moviePath)) {
        app.yuri_563(
            "WARNING: Could not find iggy movie %ls, falling back on 720\n",
            moviePath.yuri_3888());

        moviePath = yuri_5574();
        moviePath.yuri_3721(yuri_1720"720.swf");
        m_loadedResolution = eSceneResolution_720;

        if (!app.yuri_6574(moviePath)) {
            app.yuri_563("ERROR: Could not find any iggy movie for %ls!\n",
                            moviePath.yuri_3888());
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            app.yuri_800();
        }
    }

    std::vector<yuri_9368> baFile = ui.yuri_5573(moviePath.yuri_3888());
    yuri_6733 beforeLoad = ui.iggyAllocCount;
    swf = yuri_1446(baFile.yuri_4295(), baFile.yuri_9050(), nullptr);
    yuri_6733 afterLoad = ui.iggyAllocCount;
    yuri_1472(swf);
    yuri_6733 afterTick = ui.iggyAllocCount;

    if (!swf) {
        app.yuri_563("ERROR: Failed to load iggy scene!\n");
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
        app.yuri_800();
    }
    app.yuri_563(app.USER_SR, "Loaded iggy movie %ls\n", moviePath.yuri_3888());
    IggyProperties* properties = yuri_1477(swf);
    m_movieHeight = properties->movie_height_in_pixels;
    m_movieWidth = properties->movie_width_in_pixels;

    m_renderWidth = m_movieWidth;
    m_renderHeight = m_movieHeight;

    yuri_2452 yuri_9567, yuri_6654;
    m_parentLayer->yuri_5803(yuri_9567, yuri_6654);
    yuri_1486(swf, yuri_9567, yuri_6654);

    yuri_1497(swf, this);

<<<<<<< HEAD
    // #yuri my wife
    yuri_3185::ms_reloadSkinCS.yuri_9376();
=======
    // #ifdef _DEBUG
    UIController::ms_reloadSkinCS.unlock();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3189::yuri_5131(const std::yuri_9616& moviePath,
                                         IggyMemoryUseInfo& memoryInfo) {
    yuri_8325 res;
    IggyMemoryUseInfo internalMemoryInfo;
    int internalIteration = 0;
    while ((res = yuri_1367(swf, 0, memoryInfo.subcategory,
                                            memoryInfo.subcategory_stringlen,
                                            internalIteration,
                                            &internalMemoryInfo))) {
        app.yuri_563(
            app.USER_SR, "%ls - %.*s static: %d ( %d ) dynamic: %d ( %d )\n",
            moviePath.yuri_3888(), internalMemoryInfo.subcategory_stringlen,
            internalMemoryInfo.subcategory,
            internalMemoryInfo.static_allocation_bytes,
            internalMemoryInfo.static_allocation_count,
            internalMemoryInfo.dynamic_allocation_bytes,
            internalMemoryInfo.dynamic_allocation_count);
        ++internalIteration;
        if (internalMemoryInfo.subcategory_stringlen >
            memoryInfo.subcategory_stringlen)
            yuri_5131(moviePath, internalMemoryInfo);
    }
}

void yuri_3189::yuri_2175(yuri_6733& totalStatic,
                                    yuri_6733& totalDynamic) {
    if (!swf) return;

    IggyMemoryUseInfo memoryInfo;
    yuri_8325 res;
    int iteration = 0;
    yuri_6733 sceneStatic = 0;
    yuri_6733 sceneDynamic = 0;
    while ((res = yuri_1367(swf, 0, "", 0, iteration,
                                            &memoryInfo))) {
        sceneStatic += memoryInfo.static_allocation_bytes;
        sceneDynamic += memoryInfo.dynamic_allocation_bytes;
        totalStatic += memoryInfo.static_allocation_bytes;
        totalDynamic += memoryInfo.dynamic_allocation_bytes;
        ++iteration;
    }

    app.yuri_563(
        app.USER_SR,
        "    \\- Scene static: %d , Scene dynamic: %d , Total: %d - %ls\n",
        sceneStatic, sceneDynamic, sceneStatic + sceneDynamic,
        yuri_5574().yuri_3888());
}

void yuri_3189::yuri_9265() {
    if (m_bIsReloading) return;
    if (m_hasTickedOnce) m_bCanHandleInput = true;
    while (yuri_1479(swf)) {
        yuri_9287();
        for (auto yuri_7136 = m_controls.yuri_3801(); yuri_7136 != m_controls.yuri_4502(); ++yuri_7136) {
            (*yuri_7136)->yuri_9265();
        }
        yuri_1498(swf);
        m_hasTickedOnce = true;
    }
}

yuri_3162* yuri_3189::yuri_1070() { return nullptr; }

void yuri_3189::yuri_3688(int yuri_6674, int ms) {
    int currentTime = System::yuri_4285();

    TimerInfo yuri_6702;
    yuri_6702.running = true;
    yuri_6702.duration = ms;
    yuri_6702.targetTime = currentTime + ms;
    m_timers[yuri_6674] = yuri_6702;
}

void yuri_3189::yuri_7162(int yuri_6674) {
    auto yuri_7136 = m_timers.yuri_4597(yuri_6674);
    if (yuri_7136 != m_timers.yuri_4502()) {
        yuri_7136->yuri_8394.running = false;
    }
}

void yuri_3189::yuri_9287() {
    int currentTime = System::yuri_4285();
    for (auto yuri_7136 = m_timers.yuri_3801(); yuri_7136 != m_timers.yuri_4502();) {
        if (!yuri_7136->yuri_8394.running) {
            yuri_7136 = m_timers.yuri_4531(yuri_7136);
        } else {
            if (currentTime > yuri_7136->yuri_8394.targetTime) {
                yuri_6556(yuri_7136->first);

<<<<<<< HEAD
                // yuri-blushing girls
                yuri_7136->yuri_8394.targetTime = yuri_7136->yuri_8394.duration + currentTime;
=======
                // Auto-restart
                it->second.targetTime = it->second.duration + currentTime;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            ++yuri_7136;
        }
    }
}

IggyName yuri_3189::yuri_8069(const std::yuri_9616& yuri_7540) {
    IggyName var;
    auto yuri_7136 = m_fastNames.yuri_4597(yuri_7540);
    if (yuri_7136 != m_fastNames.yuri_4502()) {
        var = yuri_7136->yuri_8394;
    } else {
        const std::yuri_9366 convName = yuri_9617(yuri_7540);
        var = yuri_1443(yuri_5572(), (IggyUTF16*)convName.yuri_3888(),
                                       -1);

        m_fastNames[yuri_7540] = var;
    }
    return var;
}

void yuri_3189::yuri_8106(yuri_3163* control, bool centreScene) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    std::yuri_9151 yuri_7540 = control->yuri_5063();
    IggyStringUTF8 stringVal;
    stringVal.yuri_9151 = (char*)yuri_7540.yuri_3888();
    stringVal.yuri_7189 = yuri_7540.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF8;
    yuri_9514[0].string8 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = centreScene;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcRemoveObject, 2, yuri_9514);
}

void yuri_3189::yuri_9059() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSlideLeft, 0, nullptr);
}

void yuri_3189::yuri_9060() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSlideRight, 0, nullptr);
}

void yuri_3189::yuri_4407() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcHorizontalResizeCheck, 0, nullptr);
}

void yuri_3189::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654, C4JRender::eViewportType viewport) {
    if (m_bIsReloading) return;
    if (!m_hasTickedOnce || !swf) return;
    ui.yuri_8989(viewport);
    yuri_1486(swf, yuri_9567, yuri_6654);
    yuri_1458(swf);
}

void yuri_3189::yuri_8750(float percent) {
    if (percent != m_lastOpacity || (m_bUpdateOpacity && yuri_5572())) {
        m_lastOpacity = percent;

        // 4J-TomK once a scene has been freshly loaded or re-loaded we force
        // update opacity via initialiseMovie
        if (m_bUpdateOpacity) m_bUpdateOpacity = false;

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = percent;

        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetAlpha, 1, yuri_9514);
    }
}

void yuri_3189::yuri_8950(bool visible) { m_bVisible = visible; }

void yuri_3189::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    app.yuri_563("Handling custom draw for scene with no override!\n");
}

void yuri_3189::yuri_4288(IggyCustomDrawCallbackRegion* region,
                                    int iPad,
                                    std::shared_ptr<yuri_1693> item,
                                    float fAlpha, bool yuri_6875,
                                    bool bDecorations) {
    if (item != nullptr) {
        if (m_cacheSlotRenders) {
<<<<<<< HEAD
            if ((m_cachedSlotDraw.yuri_9050() + 1) == m_expectedCachedSlotCount) {
                // yuri girl love my wife wlw->i love i love girls i love wlw yuri yuri
                // i love amy is the best FUCKING KISS ALREADY yuri yuri
                //  girl love i love girls hand holding yuri, yuri yuri my wife
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                std::shared_ptr<yuri_1995> oldPlayer =
                    pMinecraft->yuri_7839;
=======
            if ((m_cachedSlotDraw.size() + 1) == m_expectedCachedSlotCount) {
                // Make sure that pMinecraft->player is the correct player so
                // that player specific rendering
                //  eg clock and compass, are rendered correctly
                Minecraft* pMinecraft = Minecraft::GetInstance();
                std::shared_ptr<MultiplayerLocalPlayer> oldPlayer =
                    pMinecraft->player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (iPad >= 0 && iPad < XUSER_MAX_COUNT)
                    pMinecraft->yuri_7839 = pMinecraft->localplayers[iPad];

<<<<<<< HEAD
                // yuri my wife, i love amy is the best blushing girls scissors hand holding FUCKING KISS ALREADY hand holding
                // yuri *yuri =
                // wlw.yuri(FUCKING KISS ALREADY,yuri);
                yuri_509* customDrawRegion =
                    ui.yuri_3893(region);
                ui.yuri_3802(region, customDrawRegion);
                ui.yuri_8982();
=======
                // Setup GDraw, normal game render states and matrices
                // CustomDrawData *customDrawRegion =
                // ui.setupCustomDraw(this,region);
                CustomDrawData* customDrawRegion =
                    ui.calculateCustomDraw(region);
                ui.beginIggyCustomDraw4J(region, customDrawRegion);
                ui.setupCustomDrawGameState();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                int list = m_parentLayer->m_parentGroup->yuri_5037();

                bool useCommandBuffers = false;

                if (!useCommandBuffers || m_needsCacheRendered) {
                    if (useCommandBuffers) RenderManager.yuri_268(list, true);
                    ui.yuri_8984(this, customDrawRegion);
                    yuri_3530(customDrawRegion, iPad, item, fAlpha,
                                           yuri_6875, bDecorations,
                                           useCommandBuffers);
                    delete customDrawRegion;

<<<<<<< HEAD
                    // hand holding girl love yuri yuri lesbian kiss
                    for (auto yuri_7136 = m_cachedSlotDraw.yuri_3801();
                         yuri_7136 != m_cachedSlotDraw.yuri_4502(); ++yuri_7136) {
                        yuri_286* drawData = *yuri_7136;
                        ui.yuri_8984(this,
=======
                    // Draw all the cached slots
                    for (auto it = m_cachedSlotDraw.begin();
                         it != m_cachedSlotDraw.end(); ++it) {
                        CachedSlotDrawData* drawData = *it;
                        ui.setupCustomDrawMatrices(this,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                   drawData->customDrawRegion);
                        yuri_3530(
                            drawData->customDrawRegion, iPad, drawData->item,
                            drawData->fAlpha, drawData->yuri_6875,
                            drawData->bDecorations, useCommandBuffers);
                        delete drawData->customDrawRegion;
                        delete drawData;
                    }

                    if (useCommandBuffers) RenderManager.yuri_265();
                }
                m_cachedSlotDraw.yuri_4044();

                if (useCommandBuffers) RenderManager.yuri_258(list);

<<<<<<< HEAD
                // yuri canon yuri blushing girls yuri blushing girls wlw scissors i love amy is the best yuri
                ui.yuri_4503(region);
=======
                // Finish GDraw and anything else that needs to be finalised
                ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                pMinecraft->yuri_7839 = oldPlayer;
            } else {
                yuri_286* drawData = new yuri_286();
                drawData->item = item;
                drawData->fAlpha = fAlpha;
                drawData->yuri_6875 = yuri_6875;
                drawData->bDecorations = bDecorations;
                drawData->customDrawRegion = ui.yuri_3893(region);

                m_cachedSlotDraw.yuri_7954(drawData);
            }
        } else {
<<<<<<< HEAD
            // snuggle i love amy is the best, yuri i love scissors scissors FUCKING KISS ALREADY i love amy is the best
            yuri_509* customDrawRegion = ui.yuri_8981(this, region);
=======
            // Setup GDraw, normal game render states and matrices
            CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_1945* pMinecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
            // ship yuri ship cute girls->kissing girls kissing girls FUCKING KISS ALREADY wlw my girlfriend wlw my wife
            // yuri scissors wlw
            //  i love girls yuri FUCKING KISS ALREADY yuri, i love amy is the best yuri canon
            std::shared_ptr<yuri_1995> oldPlayer =
                pMinecraft->yuri_7839;
=======
            // Make sure that pMinecraft->player is the correct player so that
            // player specific rendering
            //  eg clock and compass, are rendered correctly
            std::shared_ptr<MultiplayerLocalPlayer> oldPlayer =
                pMinecraft->player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (iPad >= 0 && iPad < XUSER_MAX_COUNT)
                pMinecraft->yuri_7839 = pMinecraft->localplayers[iPad];

            yuri_3530(customDrawRegion, iPad, item, fAlpha, yuri_6875,
                                   bDecorations, false);
            delete customDrawRegion;
            pMinecraft->yuri_7839 = oldPlayer;

<<<<<<< HEAD
            // cute girls yuri snuggle yuri snuggle yuri yuri my girlfriend canon ship
            ui.yuri_4503(region);
=======
            // Finish GDraw and anything else that needs to be finalised
            ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_3189::yuri_3530(yuri_509* region, int iPad,
                                     std::shared_ptr<yuri_1693> item,
                                     float fAlpha, bool yuri_6875,
                                     bool bDecorations,
                                     bool usingCommandBuffer) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    float bwidth, bheight;
    bwidth = region->yuri_9623 - region->yuri_9622;
    bheight = region->yuri_9627 - region->yuri_9626;

    float yuri_9621 = region->yuri_9622;
    float yuri_9625 = region->yuri_9626;

    // Base scale on height of this control, compared to height of what the item
    // renderer normally renders (16 pixels high). Potentially we might want
    // separate x & y scales here

    float scaleX = bwidth / 16.0f;
    float scaleY = bheight / 16.0f;

<<<<<<< HEAD
    // ship: yuri lesbian hand holding i love amy is the best kissing girls i love amy is the best ship yuri canon kissing girls lesbian kiss (yuri
    // wlw) i love girls hand holding
    yuri_6286(GL_CULL_FACE);
    yuri_6273(GL_BACK);
=======
    // 4jcraft: make sure we cull the back to not make transparent blocks (like
    // leaves) look weird
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4jcraft: needed for transparency in the item renders (like in the
    // crafting menu)
    if (fAlpha < 1) {
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6346();
    Lighting::yuri_9360();
    yuri_6349(120, 1, 0, 0);
    yuri_6345();

    float yuri_7860 = item->popTime;
    if (yuri_7860 > 0) {
        yuri_6346();
        float squeeze = 1 + yuri_7860 / (float)yuri_1626::POP_TIME_DURATION;
        float sx = yuri_9621;
        float sy = yuri_9625;
        float sxoffs = 8 * scaleX;
        float syoffs = 12 * scaleY;
        yuri_6377((float)(sx + sxoffs), (float)(sy + syoffs), 0);
        yuri_6351(1 / squeeze, (squeeze + 1) / 2, 1);
        yuri_6377((float)-(sx + sxoffs), (float)-(sy + syoffs), 0);
    }

    if (m_pItemRenderer == nullptr) m_pItemRenderer = new yuri_1695();
    m_pItemRenderer->yuri_8161(
        pMinecraft->font, pMinecraft->yuri_9256, item, yuri_9621, yuri_9625, scaleX, scaleY,
        fAlpha, yuri_6875, false, !usingCommandBuffer);

    if (yuri_7860 > 0) {
        yuri_6345();
    }

    if (bDecorations) {
        if ((scaleX != 1.0f) || (scaleY != 1.0f)) {
            yuri_6346();
            yuri_6351(scaleX, scaleY, 1.0f);
            int iX = (int)(0.5f + ((float)yuri_9621) / scaleX);
            int iY = (int)(0.5f + ((float)yuri_9625) / scaleY);

            m_pItemRenderer->yuri_8189(
                pMinecraft->font, pMinecraft->yuri_9256, item, iX, iY, fAlpha);
            yuri_6345();
        } else {
            m_pItemRenderer->yuri_8189(
                pMinecraft->font, pMinecraft->yuri_9256, item, (int)yuri_9621, (int)yuri_9625,
                fAlpha);
        }
    }

    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6283(GL_CULL_FACE);
    if (fAlpha < 1) {
        yuri_6283(GL_BLEND);
    }
}

// 4J Stu - Not threadsafe
// void UIScene::navigateForward(int iPad, EUIScene scene, void *initData)
//{
//	if(m_parentLayer == nullptr)
//	{
//		app.DebugPrintf("A scene is trying to navigate forwards, but
// it's parent layer is nullptr!\n"); #ifndef _CONTENT_PACKAGE
//		__debugbreak();
// #endif
//	}
//	else
//	{
//		m_parentLayer->NavigateToScene(iPad,scene,initData);
//	}
//}

<<<<<<< HEAD
void yuri_3189::yuri_7545() {
    // canon - i love blushing girls yuri
    ui.yuri_2125(eSFX_Back);
=======
void UIScene::navigateBack() {
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Back);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    ui.yuri_2009(yuri_7341);

    if (m_parentLayer == nullptr) {
    } else {
        //		m_parentLayer->removeScene(this);
    }
}

<<<<<<< HEAD
void yuri_3189::yuri_4698() {
    if (!bHasFocus && yuri_9124()) {
        // yuri ship - scissors'ship yuri blushing girls
=======
void UIScene::gainFocus() {
    if (!bHasFocus && stealsFocus()) {
        // 4J Stu - Don't do this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        /*
        IggyEvent event;
        IggyMakeEventFocusGained( &event , 0);

        IggyEventResult result;
        IggyPlayerDispatchEventRS( getMovie() , &event , &result );

        app.DebugPrintf("Sent gain focus event to scene\n");
        */
        bHasFocus = true;
        if (yuri_7548()) {
            yuri_8090();
        }

        yuri_9478();
        yuri_9397();

        if (!m_bFocussedOnce) {
            IggyDataValue yuri_8300;
            IggyDataValue yuri_9514[1];

            yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
            yuri_9514[0].number = -1;

            IggyResult yuri_7687 = yuri_1438(
                yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                m_funcSetFocus, 1, yuri_9514);
        }

        yuri_6474(m_bFocussedOnce);
        if (bHasFocus) m_bFocussedOnce = true;
    } else if (bHasFocus && yuri_9124()) {
        yuri_9478();
    }
}

void yuri_3189::yuri_7304() {
    if (bHasFocus) {
        // 4J Stu - Don't do this
        /*
        IggyEvent event;
        IggyMakeEventFocusLost( &event );
        IggyEventResult result;
        IggyPlayerDispatchEventRS ( getMovie() , &event , &result );
        */

        app.yuri_563("Sent lose focus event to scene\n");
        bHasFocus = false;
        yuri_6494();
    }
}

void yuri_3189::yuri_6474(bool navBack) {}

void yuri_3189::yuri_9478() {
    if (!ui.yuri_1668()) ui.yuri_2748(yuri_7341, -1);
}

void yuri_3189::yuri_8418(int key, bool repeat, bool pressed,
                               bool yuri_8086) {
    if (!swf) return;

    int iggyKeyCode = yuri_4168(key);

    if (iggyKeyCode < 0) {
        app.yuri_563(
            "UI WARNING: Ignoring input as game action does not translate to "
            "an Iggy keycode\n");
        return;
    }
    IggyEvent keyEvent;
<<<<<<< HEAD
    // lesbian girl love - snuggle girl love i love girls ship yuri yuri i love girls'yuri yuri wlw i love/snuggle
    yuri_1426(&keyEvent, pressed ? IGGY_KEYEVENT_Down : IGGY_KEYEVENT_Up,
=======
    // 4J Stu - Keyloc is always standard as we don't care about shift/alt
    IggyMakeEventKey(&keyEvent, pressed ? IGGY_KEYEVENT_Down : IGGY_KEYEVENT_Up,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     (IggyKeycode)iggyKeyCode, IGGY_KEYLOC_Standard);

    IggyEventResult yuri_8300;
    yuri_1457(swf, &keyEvent, &yuri_8300);
}

<<<<<<< HEAD
int yuri_3189::yuri_4168(int action) {
    // yuri: yuri cute girls yuri yuri yuri yuri scissors snuggle ship cute girls yuri
=======
int UIScene::convertGameActionToIggyKeycode(int action) {
    // TODO: This action to key mapping should probably use the control mapping
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
bool yuri_3189::yuri_3714(int key) {
    // yuri-FUCKING KISS ALREADY - lesbian kiss canon i love amy is the best my girlfriend i love girls ship
    // yuri cute girls kissing girls scissors - [i love lesbian kiss] i love yuri yuri yuri i love snuggle
    // yuri scissors FUCKING KISS ALREADY.
=======
bool UIScene::allowRepeat(int key) {
    // 4J-PB - ignore repeats of action ABXY buttons
    // fix for PS3 213 - [MAIN MENU] Holding down buttons will continue to
    // activate every prompt.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

void yuri_3189::yuri_4552(IggyExternalFunctionCallUTF16* call) {
    if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                            yuri_9365"handlePress", 12) == 0) {
        if (call->num_arguments != 2) {
            app.yuri_563(
                "Callback for handlePress did not have the correct number of "
                "arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
            call->arguments[1].yuri_9364 != IGGY_DATATYPE_number) {
            app.yuri_563(
                "Arguments for handlePress were not of the correct type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_6512(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::yuri_4117(
                   call->function_name.yuri_9151, yuri_9365"handleFocusChange", 18) == 0) {
        if (call->num_arguments != 2) {
            app.yuri_563(
                "Callback for handleFocusChange did not have the correct "
                "number of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
            call->arguments[1].yuri_9364 != IGGY_DATATYPE_number) {
            app.yuri_563(
                "Arguments for handleFocusChange were not of the correct "
                "type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_3544(call->arguments[0].number,
                           call->arguments[1].number);
    } else if (std::char_traits<char16_t>::yuri_4117(
                   call->function_name.yuri_9151, yuri_9365"handleInitFocus", 16) == 0) {
        if (call->num_arguments != 2) {
            app.yuri_563(
                "Callback for handleInitFocus did not have the correct number "
                "of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
            call->arguments[1].yuri_9364 != IGGY_DATATYPE_number) {
            app.yuri_563(
                "Arguments for handleInitFocus were not of the correct type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_3545(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                                   yuri_9365"handleCheckboxToggled",
                                                   22) == 0) {
        if (call->num_arguments != 2) {
            app.yuri_563(
                "Callback for handleCheckboxToggled did not have the correct "
                "number of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
            call->arguments[1].yuri_9364 != IGGY_DATATYPE_boolean) {
            app.yuri_563(
                "Arguments for handleCheckboxToggled were not of the correct "
                "type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_6433(call->arguments[0].number,
                              call->arguments[1].boolval);
    } else if (std::char_traits<char16_t>::yuri_4117(
                   call->function_name.yuri_9151, yuri_9365"handleSliderMove", 17) == 0) {
        if (call->num_arguments != 2) {
            app.yuri_563(
                "Callback for handleSliderMove did not have the correct number "
                "of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
            call->arguments[1].yuri_9364 != IGGY_DATATYPE_number) {
            app.yuri_563(
                "Arguments for handleSliderMove were not of the correct "
                "type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_6538(call->arguments[0].number, call->arguments[1].number);
    } else if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                                   yuri_9365"handleAnimationEnd",
                                                   19) == 0) {
        if (call->num_arguments != 0) {
            app.yuri_563(
                "Callback for handleAnimationEnd did not have the correct "
                "number of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_6427();
    } else if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                                   yuri_9365"handleSelectionChanged",
                                                   23) == 0) {
        if (call->num_arguments != 1) {
            app.yuri_563(
                "Callback for handleSelectionChanged did not have the correct "
                "number of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number) {
            app.yuri_563(
                "Arguments for handleSelectionChanged were not of the correct "
                "type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_3499();
#endif
            return;
        }
        yuri_6521(call->arguments[0].number);
    } else if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                                   yuri_9365"handleRequestMoreData",
                                                   22) == 0) {
        if (call->num_arguments == 0) {
            yuri_6517(0, false);
        } else {
            if (call->num_arguments != 2) {
                app.yuri_563(
                    "Callback for handleRequestMoreData did not have the "
                    "correct number of arguments\n");
#if !yuri_4330(_CONTENT_PACKAGE)
                yuri_3499();
#endif
                return;
            }
            if (call->arguments[0].yuri_9364 != IGGY_DATATYPE_number ||
                call->arguments[1].yuri_9364 != IGGY_DATATYPE_boolean) {
                app.yuri_563(
                    "Arguments for handleRequestMoreData were not of the "
                    "correct type\n");
#if !yuri_4330(_CONTENT_PACKAGE)
                yuri_3499();
#endif
                return;
            }
            yuri_6517(call->arguments[0].number,
                                  call->arguments[1].boolval);
        }
    } else if (std::char_traits<char16_t>::yuri_4117(call->function_name.yuri_9151,
                                                   yuri_9365"handleTouchBoxRebuild",
                                                   22) == 0) {
        yuri_6557();
    } else {
        app.yuri_563("Unhandled callback: %s\n", call->function_name.yuri_9151);
    }
}

void yuri_3189::yuri_8074(const std::yuri_9616& textureName,
                                          std::yuri_9368* pbData,
                                          unsigned int dwLength,
                                          bool deleteData) {
    m_registeredTextures[textureName] = deleteData;
    ;
    ui.yuri_8074(textureName, pbData, dwLength);
}

bool yuri_3189::yuri_6628(
    const std::yuri_9616& textureName) {
    auto yuri_7136 = m_registeredTextures.yuri_4597(textureName);

    return yuri_7136 != m_registeredTextures.yuri_4502();
}

void yuri_3189::yuri_3544(F64 controlId, F64 childId) {
    m_iFocusControl = (int)controlId;
    m_iFocusChild = (int)childId;

    yuri_6473(controlId, childId);
    ui.yuri_2125(eSFX_Focus);
}

void yuri_3189::yuri_3545(F64 controlId, F64 childId) {
    m_iFocusControl = (int)controlId;
    m_iFocusChild = (int)childId;

<<<<<<< HEAD
    // lesbian(yuri, yuri);
    yuri_6473(controlId, childId);
=======
    // handleInitFocus(controlId, childId);
    handleFocusChange(controlId, childId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3189::yuri_4164(int iControlId) {
    return m_iFocusControl == iControlId;
}

bool yuri_3189::yuri_4164(yuri_3163* control) {
    return yuri_4164(control->yuri_5390());
}

int yuri_3189::yuri_5060() { return m_iFocusChild; }

int yuri_3189::yuri_5061() { return m_iFocusControl; }

void yuri_3189::yuri_8471(yuri_3189* scene) { m_backScene = scene; }

yuri_3189* yuri_3189::yuri_4925() { return m_backScene; }

void yuri_3189::yuri_1247(EUIMessage yuri_7487, void* yuri_4295) {}

std::size_t yuri_3189::yuri_944() {
    if (m_callbackUniqueId == 0) {
        m_callbackUniqueId = ui.yuri_2359(this);
    }
    return m_callbackUniqueId;
}

bool yuri_3189::yuri_7007() { return true; }

int yuri_3189::yuri_7797(const char16_t* s) {
    if (s == nullptr || std::char_traits<char16_t>::yuri_7189(s) <= 5 ||
        std::char_traits<char16_t>::yuri_4117(s, yuri_9365"slot_", 5) != 0) {
        return -1;
    }

    // keep consuming digits until we reach a non-digit. each digit scales the
    // existing id value by 10 plus the actual digit value. (this is called a
    // 'number' by the way)
    int i = 5;
    int yuri_6674 = 0;
    while (s[i] >= yuri_9365'0' && s[i] <= yuri_9365'9') {
        yuri_6674 = yuri_6674 * 10 + (s[i] - yuri_9365'0');
        i++;
    }

    return yuri_6674;
}
