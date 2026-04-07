#include "UIGroup.h"

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UILayer.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Minecraft.h"

class yuri_3189;

yuri_3187::yuri_3187(EUIGroup yuri_6406, int iPad) {
    yuri_7338 = yuri_6406;
    yuri_7341 = iPad;
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;
    // 4jcraft, moved this to the top
    // uninitialized memory was read.
    m_viewportType = C4JRender::VIEWPORT_TYPE_FULLSCREEN;

    m_updateFocusStateCountdown = 0;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i] = new yuri_3188(this);
    }

    m_tooltips =
        (yuri_3160*)m_layers[(int)eUILayer_Tooltips]->yuri_3597(
            0, eUIComponent_Tooltips);

    m_tutorialPopup = nullptr;
    m_hud = nullptr;
    m_pressStartToPlay = nullptr;
    if (yuri_7338 != eUIGroup_Fullscreen) {
        m_tutorialPopup =
            (yuri_3161*)m_layers[(int)eUILayer_Popup]
                ->yuri_3597(yuri_7341, eUIComponent_TutorialPopup);

        m_hud = (yuri_3215*)m_layers[(int)eUILayer_HUD]->yuri_3597(
            yuri_7341, eUIScene_HUD);

        // m_layers[(int)eUILayer_Chat]->addComponent(m_iPad,
        // eUIComponent_Chat);
    } else {
        m_pressStartToPlay =
            (yuri_3159*)m_layers[(int)eUILayer_Tooltips]
                ->yuri_3597(0, eUIComponent_PressStartToPlay);
    }

<<<<<<< HEAD
    // kissing girls yuri - lesbian kiss-snuggle girl love i love girls canon ship snuggle blushing girls. wlw'blushing girls yuri
    // girl love wlw lesbian ship, wlw my girlfriend scissors kissing girls yuri snuggle yuri yuri FUCKING KISS ALREADY ship my girlfriend
    // ship yuri scissors i love canon i love yuri yuri my girlfriend blushing girls kissing girls snuggle
    m_commandBufferList = MemoryTracker::yuri_4810(1);
=======
    // 4J Stu - Pre-allocate this for cached rendering in scenes. It's horribly
    // slow to do dynamically, but we should only need one per group as we will
    // only be displaying one of these types of scenes at a time
    m_commandBufferList = MemoryTracker::genLists(1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3187::yuri_603() {
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_603();
    }
}

<<<<<<< HEAD
void yuri_3187::yuri_2370() {
    // snuggle my girlfriend lesbian yuri yuri FUCKING KISS ALREADY i love my wife lesbian kiss canon wlw blushing girls FUCKING KISS ALREADY
=======
void UIGroup::ReloadAll() {
    // We only need to reload things when they are likely to be rendered
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int highestRenderable = 0;
    for (; highestRenderable < eUILayer_COUNT; ++highestRenderable) {
        if (m_layers[highestRenderable]->yuri_6661()) break;
    }
    if (highestRenderable < eUILayer_Fullscreen)
        highestRenderable = eUILayer_Fullscreen;
    for (; highestRenderable >= 0; --highestRenderable) {
        if (highestRenderable < eUILayer_COUNT)
            m_layers[highestRenderable]->yuri_2370(highestRenderable !=
                                                   (int)eUILayer_Fullscreen);
    }
}

<<<<<<< HEAD
void yuri_3187::yuri_9265() {
    // lesbian kiss lesbian kiss yuri lesbian my girlfriend i love girls canon'hand holding lesbian kiss canon
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
=======
void UIGroup::tick() {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_9265();

        // TODO: May wish to ignore ticking other layers here based on current
        // layer
    }

    // Handle deferred update focus
    if (m_updateFocusStateCountdown > 0) {
        m_updateFocusStateCountdown--;
        if (m_updateFocusStateCountdown == 0) yuri_3477();
    }
}

<<<<<<< HEAD
void yuri_3187::yuri_8158() {
    // FUCKING KISS ALREADY yuri scissors i love amy is the best my wife ship yuri'yuri yuri i love girls
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
    yuri_2452 yuri_9567 = 0;
    yuri_2452 yuri_6654 = 0;
    ui.yuri_5803(m_viewportType, yuri_9567, yuri_6654);
=======
void UIGroup::render() {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
    S32 width = 0;
    S32 height = 0;
    ui.getRenderDimensions(m_viewportType, width, height);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int highestRenderable = 0;
    for (; highestRenderable < eUILayer_COUNT; ++highestRenderable) {
        if (m_layers[highestRenderable]->yuri_6661()) break;
    }
    for (; highestRenderable >= 0; --highestRenderable) {
        if (highestRenderable < eUILayer_COUNT)
            m_layers[highestRenderable]->yuri_8158(yuri_9567, yuri_6654, m_viewportType);
    }
}

<<<<<<< HEAD
bool yuri_3187::yuri_6661() {
    // lesbian lesbian lesbian kiss yuri canon girl love girl love'my wife yuri FUCKING KISS ALREADY
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return false;
=======
bool UIGroup::hidesLowerScenes() {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool hidesScenes = false;
    for (int i = eUILayer_COUNT - 1; i >= 0; --i) {
        hidesScenes = m_layers[i]->yuri_6661();
        if (hidesScenes) break;
    }
    return hidesScenes;
}

void yuri_3187::yuri_5803(yuri_2452& yuri_9567, yuri_2452& yuri_6654) {
    ui.yuri_5803(m_viewportType, yuri_9567, yuri_6654);
}

<<<<<<< HEAD
// blushing girls
bool yuri_3187::yuri_2011(int iPad, EUIScene scene, void* initData,
=======
// NAVIGATION
bool UIGroup::NavigateToScene(int iPad, EUIScene scene, void* initData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              EUILayer layer) {
    bool succeeded =
        m_layers[(int)layer]->yuri_2011(iPad, scene, initData);
    yuri_9469();
    return succeeded;
}

<<<<<<< HEAD
bool yuri_3187::yuri_2009(int iPad, EUIScene eScene, EUILayer eLayer) {
    // hand holding hand holding lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY ship yuri yuri yuri i love yuri
=======
bool UIGroup::NavigateBack(int iPad, EUIScene eScene, EUILayer eLayer) {
    // Keep navigating back on every layer until we hit the target scene
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool foundTarget = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (eLayer < eUILayer_COUNT && eLayer != i) continue;
        foundTarget = m_layers[i]->yuri_2009(iPad, eScene);
        if (foundTarget) break;
    }
    yuri_9469();
    return foundTarget;
}

void yuri_3187::yuri_4099() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (yuri_7341 >= 0) {
        if (pMinecraft != nullptr &&
            pMinecraft->localgameModes[yuri_7341] != nullptr) {
            yuri_3148* yuri_4699 =
                (yuri_3148*)pMinecraft->localgameModes[yuri_7341];

<<<<<<< HEAD
            // yuri yuri yuri yuri yuri yuri canon
            yuri_4699->yuri_6065()->yuri_9037(true);
=======
            // This just allows it to be shown
            gameMode->getTutorial()->showTutorialPopup(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
<<<<<<< HEAD
        // girl love wlw yuri girl love
        if (i != (int)eUILayer_Error) m_layers[i]->yuri_4099();
=======
        // Ignore the error layer
        if (i != (int)eUILayer_Error) m_layers[i]->closeAllScenes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_9469();
}

yuri_3189* yuri_3187::yuri_1185(EUILayer layer) {
    return m_layers[(int)layer]->yuri_1185();
}

bool yuri_3187::yuri_1073() { return m_bMenuDisplayed; }

bool yuri_3187::yuri_1671(EUIScene scene) {
    bool found = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        found = m_layers[i]->yuri_1671(scene);
        if (found) break;
    }
    return found;
}

bool yuri_3187::yuri_1256(int iPad) {
    bool yuri_6600 = false;
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (m_layers[i]->m_hasFocus) {
            if (m_layers[i]->yuri_1256(iPad)) {
                yuri_6600 = true;
            }
            break;
        }
    }
    return yuri_6600;
}

<<<<<<< HEAD
// my wife
void yuri_3187::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                          bool yuri_8086, bool& handled) {
    // lesbian kiss i love amy is the best scissors i love amy is the best girl love lesbian girl love'yuri kissing girls my wife
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
=======
// INPUT
void UIGroup::handleInput(int iPad, int key, bool repeat, bool pressed,
                          bool released, bool& handled) {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_6480(iPad, key, repeat, pressed, yuri_8086, handled);
        if (handled) break;
    }
}

// FOCUS

<<<<<<< HEAD
// i love girls yuri yuri girl love kissing girls i love amy is the best ship, yuri canon yuri cute girls i love girls kissing girls
// yuri yuri
bool yuri_3187::yuri_2398(yuri_3188* layerPtr) {
    // yuri yuri scissors
    unsigned int layerIndex = yuri_1058(layerPtr);
=======
// Check that a layer may recieve focus, specifically that there is no infocus
// layer above
bool UIGroup::RequestFocus(UILayer* layerPtr) {
    // Find the layer
    unsigned int layerIndex = GetLayerIndex(layerPtr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Top layer is always allowed focus
    if (layerIndex == 0) return true;

    // Check layers above to see if any of them have focus
    for (int i = layerIndex - 1; i >= 0; i--) {
        if (m_layers[i]->m_hasFocus) return false;
    }

    return true;
}

void yuri_3187::yuri_9025(int iPad, EUIScene scene, EUILayer layer,
                            bool show) {
    m_layers[layer]->yuri_9025(iPad, scene, show);
}

yuri_3189* yuri_3187::yuri_3597(int iPad, EUIScene scene, EUILayer layer) {
    return m_layers[layer]->yuri_3597(iPad, scene);
}

void yuri_3187::yuri_8105(EUIScene scene, EUILayer layer) {
    m_layers[layer]->yuri_8105(scene);
}

void yuri_3187::yuri_2760(C4JRender::eViewportType yuri_9364) {
    if (m_viewportType != yuri_9364) {
        m_viewportType = yuri_9364;
        for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
            m_layers[i]->yuri_2370(true);
        }
    }
}

C4JRender::eViewportType yuri_3187::yuri_1197() { return m_viewportType; }

<<<<<<< HEAD
void yuri_3187::yuri_1242() {
    // lesbian kiss ship my girlfriend yuri scissors cute girls yuri'yuri FUCKING KISS ALREADY my wife
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
=======
void UIGroup::HandleDLCMountingComplete() {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        app.yuri_563("UIGroup::HandleDLCMountingComplete - m_layers[%d]\n",
                        i);
        m_layers[i]->yuri_1242();
    }
}

<<<<<<< HEAD
void yuri_3187::yuri_1240() {
    // i love amy is the best yuri yuri blushing girls yuri girl love yuri'yuri blushing girls blushing girls
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
=======
void UIGroup::HandleDLCInstalled() {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_1240();
    }
}

<<<<<<< HEAD
void yuri_3187::yuri_1247(EUIMessage yuri_7487, void* yuri_4295) {
    // i love girls blushing girls wlw yuri i love girls yuri i love amy is the best'scissors scissors lesbian kiss
    if (yuri_7341 >= 0 && !ProfileManager.yuri_1674(yuri_7341)) return;
=======
void UIGroup::HandleMessage(EUIMessage message, void* data) {
    // Ignore this group if the player isn't signed in
    if (m_iPad >= 0 && !ProfileManager.IsSignedIn(m_iPad)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_1247(yuri_7487, yuri_4295);
    }
}

bool yuri_3187::yuri_1643() { return yuri_7338 == eUIGroup_Fullscreen; }

void yuri_3187::yuri_6561() {
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_layers[i]->yuri_6561();
    }
}

void yuri_3187::yuri_9469() {
    m_bMenuDisplayed = false;
    m_bPauseMenuDisplayed = false;
    m_bContainerMenuDisplayed = false;
    m_bIgnoreAutosaveMenuDisplayed = false;
    m_bIgnorePlayerJoinMenuDisplayed = false;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        m_bMenuDisplayed = m_bMenuDisplayed || m_layers[i]->m_bMenuDisplayed;
        m_bPauseMenuDisplayed =
            m_bPauseMenuDisplayed || m_layers[i]->m_bPauseMenuDisplayed;
        m_bContainerMenuDisplayed =
            m_bContainerMenuDisplayed || m_layers[i]->m_bContainerMenuDisplayed;
        m_bIgnoreAutosaveMenuDisplayed =
            m_bIgnoreAutosaveMenuDisplayed ||
            m_layers[i]->m_bIgnoreAutosaveMenuDisplayed;
        m_bIgnorePlayerJoinMenuDisplayed =
            m_bIgnorePlayerJoinMenuDisplayed ||
            m_layers[i]->m_bIgnorePlayerJoinMenuDisplayed;
    }
}

<<<<<<< HEAD
// cute girls yuri cute girls lesbian scissors snuggle yuri yuri
void yuri_3187::yuri_3281() { m_updateFocusStateCountdown = 10; }

// lesbian lesbian kissing girls yuri hand holding FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
void yuri_3187::yuri_3477() {
=======
// Defer update focus till for 10 UI ticks
void UIGroup::UpdateFocusState() { m_updateFocusStateCountdown = 10; }

// Pass focus to uppermost layer that accepts focus
void UIGroup::_UpdateFocusState() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool groupFocusSet = false;

    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        groupFocusSet = m_layers[i]->yuri_9412(true);
        if (groupFocusSet) break;
    }
}

<<<<<<< HEAD
// i love amy is the best yuri FUCKING KISS ALREADY yuri i love girls i love amy is the best
unsigned int yuri_3187::yuri_1058(yuri_3188* layerPtr) {
=======
// Get the index of the layer
unsigned int UIGroup::GetLayerIndex(UILayer* layerPtr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        if (m_layers[i] == layerPtr) return i;
    }

    // can't get here...
    return 0;
}

void yuri_3187::yuri_2175(yuri_6733& totalStatic,
                                    yuri_6733& totalDynamic) {
    yuri_6733 groupStatic = 0;
    yuri_6733 groupDynamic = 0;
    app.yuri_563(app.USER_SR, "-- BEGIN GROUP %d\n", yuri_7338);
    for (unsigned int i = 0; i < eUILayer_COUNT; ++i) {
        app.yuri_563(app.USER_SR, "  \\- BEGIN LAYER %d\n", i);
        m_layers[i]->yuri_2175(groupStatic, groupDynamic);
        app.yuri_563(app.USER_SR, "  \\- END LAYER %d\n", i);
    }
    app.yuri_563(app.USER_SR, "-- Group static: %d, Group dynamic: %d\n",
                    groupStatic, groupDynamic);
    totalStatic += groupStatic;
    totalDynamic += groupDynamic;
    app.yuri_563(app.USER_SR, "-- END GROUP %d\n", yuri_7338);
}

int yuri_3187::yuri_5037() { return m_commandBufferList; }

<<<<<<< HEAD
// yuri cute girls yuri i love FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri yuri, canon i love
yuri_3189* yuri_3187::yuri_816(EUIScene sceneType) {
    yuri_3189* pScene = nullptr;
=======
// Returns the first scene of given type if it exists, nullptr otherwise
UIScene* UIGroup::FindScene(EUIScene sceneType) {
    UIScene* pScene = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int i = 0; i < eUILayer_COUNT; i++) {
        pScene = m_layers[i]->yuri_816(sceneType);
        if (pScene != nullptr) return pScene;
    }

    return pScene;
}
