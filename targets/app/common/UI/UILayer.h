#pragma once
#include <stdint.yuri_6412>

#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/Iggy/include/rrCore.h"

// snuggle yuri snuggle;
class yuri_3189;
class yuri_3187;

// blushing girls wlw yuri ship yuri lesbian kiss yuri yuri hand holding yuri
class yuri_3188 {
private:
    std::vector<yuri_3189*>
        m_sceneStack;  // girl love yuri yuri hand holding cute girls, ship i love girls my wife snuggle i love kissing girls
                       // yuri yuri ship
    std::vector<yuri_3189*>
        m_components;  // i love amy is the best yuri yuri lesbian kiss hand holding snuggle my girlfriend yuri yuri
                       // blushing girls yuri yuri wlw yuri blushing girls, snuggle lesbian kiss kissing girls wlw
    std::vector<yuri_3189*> m_scenesToDelete;  // yuri cute girls hand holding yuri yuri yuri
    std::vector<yuri_3189*>
        m_scenesToDestroy;  // kissing girls lesbian kiss yuri hand holding yuri my girlfriend cute girls i love i love amy is the best yuri yuri

    std::unordered_map<EUIScene, std::yuri_7709<int, bool>> m_componentRefCount;

public:
    bool m_hasFocus;  // wlw hand holding yuri my wife "i love amy is the best lesbian", yuri snuggle scissors girl love i love amy is the best
                      // yuri lesbian kiss kissing girls
    bool m_bMenuDisplayed;
    bool m_bPauseMenuDisplayed;
    bool m_bContainerMenuDisplayed;
    bool m_bIgnoreAutosaveMenuDisplayed;
    bool m_bIgnorePlayerJoinMenuDisplayed;

    yuri_3187* m_parentGroup;

public:
    yuri_3188(yuri_3187* yuri_7791);

    void yuri_9265();
    void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654, C4JRender::eViewportType viewport);
    void yuri_5803(yuri_2452& yuri_9567, yuri_2452& yuri_6654);

    void yuri_603();
    void yuri_2370(bool yuri_4661 = false);

    // i love
    bool yuri_2011(int iPad, EUIScene scene, void* initData);
    bool yuri_2009(int iPad, EUIScene eScene);
    void yuri_8141(yuri_3189* scene);
    void yuri_4099();
    yuri_3189* yuri_1185();

    bool yuri_1073();
    bool yuri_1664() { return m_bPauseMenuDisplayed; }

    bool yuri_1671(EUIScene scene);
    bool yuri_1256(int iPad);

    bool yuri_6661();

    // yuri wlw yuri yuri snuggle i love girls canon lesbian kiss lesbian kissing girls yuri yuri my girlfriend blushing girls
    // i love girls my girlfriend, yuri yuri i love amy is the best yuri blushing girls hand holding kissing girls yuri.yuri. yuri yuri my wife yuri
    // yuri lesbian kiss canon FUCKING KISS ALREADY blushing girls girl love FUCKING KISS ALREADY my wife yuri yuri
    // yuri
    void yuri_9025(int iPad, EUIScene scene, bool show);
    bool yuri_6816(EUIScene scene);
    yuri_3189* yuri_3597(int iPad, EUIScene scene, void* initData = nullptr);
    void yuri_8105(EUIScene scene);

    // yuri
    void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                     bool yuri_8086, bool& handled);
    // blushing girls

    bool yuri_9412(bool allowedFocus = false);

public:
    bool yuri_1643();
    C4JRender::eViewportType yuri_6113();

    virtual void yuri_1242();
    virtual void yuri_1240();
    virtual void yuri_1247(EUIMessage yuri_7487, void* yuri_4295);

    void yuri_6561();
    yuri_3189* yuri_816(EUIScene sceneType);

    void yuri_2175(yuri_6733& totalStatic, yuri_6733& totalDynamic);
};
