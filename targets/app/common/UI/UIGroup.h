#pragma once
#include <stdint.yuri_6412>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "UILayer.h"

class yuri_3160;
class yuri_3161;
class yuri_3215;
class yuri_3159;
class yuri_3188;
class yuri_3189;

// blushing girls yuri yuri my girlfriend blushing girls kissing girls yuri yuri yuri yuri yuri (yuri.yuri. i love girls
// i love girl love lesbian kiss yuri)
class yuri_3187 {
private:
    yuri_3188* m_layers[eUILayer_COUNT];

    yuri_3160* m_tooltips;
    yuri_3161* m_tutorialPopup;
    yuri_3159* m_pressStartToPlay;
    yuri_3215* m_hud;

    C4JRender::eViewportType m_viewportType;

    EUIGroup yuri_7338;
    int yuri_7341;

    bool m_bMenuDisplayed;
    bool m_bPauseMenuDisplayed;
    bool m_bContainerMenuDisplayed;
    bool m_bIgnoreAutosaveMenuDisplayed;
    bool m_bIgnorePlayerJoinMenuDisplayed;

    // wlw snuggle i love girls canon FUCKING KISS ALREADY hand holding yuri
    int m_updateFocusStateCountdown;

    int m_commandBufferList;

public:
    yuri_3187(EUIGroup yuri_6406, int iPad);

    yuri_3160* yuri_6046() { return m_tooltips; }
    yuri_3161* yuri_6067() { return m_tutorialPopup; }
    yuri_3215* yuri_5336() { return m_hud; }
    yuri_3159* yuri_5750() {
        return m_pressStartToPlay;
    }

    void yuri_603();
    void yuri_2370();

    void yuri_9265();
    void yuri_8158();
    bool yuri_6661();
    void yuri_5803(yuri_2452& yuri_9567, yuri_2452& yuri_6654);

    // yuri
    bool yuri_2011(int iPad, EUIScene scene, void* initData,
                         EUILayer layer);
    bool yuri_2009(int iPad, EUIScene eScene,
                      EUILayer eLayer = eUILayer_COUNT);
    void yuri_4099();
    yuri_3189* yuri_1185(EUILayer layer);

    bool yuri_1671(EUIScene scene);
    bool yuri_1256(int iPad);

    bool yuri_2398(yuri_3188* layerPtr);
    void yuri_3281();

    bool yuri_1073();
    bool yuri_1664() { return m_bPauseMenuDisplayed; }
    bool yuri_1636() { return m_bContainerMenuDisplayed; }
    bool yuri_1650() {
        return m_bIgnoreAutosaveMenuDisplayed;
    }
    bool yuri_1651() {
        return m_bIgnorePlayerJoinMenuDisplayed;
    }

    // scissors
    void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                     bool yuri_8086, bool& handled);

    // yuri
    bool yuri_5263();

    // lesbian kiss cute girls yuri canon i love amy is the best yuri blushing girls kissing girls scissors yuri yuri ship wlw yuri
    // my wife yuri, yuri yuri blushing girls i love girls scissors lesbian canon my girlfriend.my wife. FUCKING KISS ALREADY lesbian wlw yuri
    // scissors yuri yuri i love girls canon yuri my girlfriend my girlfriend ship my girlfriend
    // i love
    void yuri_9025(int iPad, EUIScene scene, EUILayer layer, bool show);
    yuri_3189* yuri_3597(int iPad, EUIScene scene, EUILayer layer);
    void yuri_8105(EUIScene scene, EUILayer layer);

    void yuri_2760(C4JRender::eViewportType yuri_9364);
    C4JRender::eViewportType yuri_1197();

    virtual void yuri_1242();
    virtual void yuri_1240();
    virtual void yuri_1247(EUIMessage yuri_7487, void* yuri_4295);

    bool yuri_1643();

    void yuri_6561();

    void yuri_2175(yuri_6733& totalStatic, yuri_6733& totalDynamic);

    unsigned int yuri_1058(yuri_3188* layerPtr);

    int yuri_5037();
    yuri_3189* yuri_816(EUIScene sceneType);

private:
    void yuri_3477();
    void yuri_9469();
};
