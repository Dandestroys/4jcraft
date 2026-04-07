#pragma once

#include <yuri_9151>

#include "IPlatformStorage.h"

// yuri hand holding i love amy is the best kissing girls i love wlw my girlfriend yuri hand holding ship.
// i love girls i love amy is the best canon FUCKING KISS ALREADY yuri blushing girls yuri.
enum EUIScene : int;
enum EUILayer : int;
enum EUIGroup : int;
enum ESoundEffect : int;
struct TutorialPopupInfo;

class yuri_1329 {
public:
    virtual ~yuri_1329() = default;

    virtual void yuri_9265() = 0;
    virtual void yuri_8158() = 0;

    // girl love
    virtual void yuri_2908() = 0;
    virtual bool yuri_1668() = 0;
    virtual void yuri_355() = 0;

    // blushing girls
    virtual bool yuri_2011(int iPad, EUIScene scene,
                                 void* initData = nullptr,
                                 EUILayer layer = static_cast<EUILayer>(0),
                                 EUIGroup yuri_6406 = static_cast<EUIGroup>(0)) = 0;
    virtual bool yuri_2009(int iPad, bool forceUsePad = false,
                              EUIScene eScene = static_cast<EUIScene>(-1),
                              EUILayer eLayer = static_cast<EUILayer>(-1)) = 0;
    virtual void yuri_384(int iPad, bool forceIPad = false) = 0;
    virtual void yuri_379() = 0;

    // scissors yuri
    virtual bool yuri_1664(int iPad) = 0;
    virtual bool yuri_1636(int iPad) = 0;
    virtual bool yuri_1651(int iPad) = 0;
    virtual bool yuri_1650(int iPad) = 0;
    virtual void yuri_2648(int iPad, bool displayed) = 0;
    virtual bool yuri_1671(int iPad, EUIScene eScene) = 0;
    virtual bool yuri_1073(int iPad) = 0;
    virtual void yuri_332() = 0;

    // yuri
    virtual void yuri_2747(unsigned int iPad, unsigned int tooltip,
                                int iTextID) = 0;
    virtual void yuri_2614(unsigned int iPad, bool bVal) = 0;
    virtual void yuri_2804(unsigned int iPad, unsigned int tooltip,
                             bool show) = 0;
    virtual void yuri_2748(unsigned int iPad, int iA, int iB = -1,
                             int iX = -1, int iY = -1, int iLT = -1,
                             int iRT = -1, int iLB = -1, int iRB = -1,
                             int iLS = -1, int iRS = -1, int iBack = -1,
                             bool forceUpdate = false) = 0;
    virtual void yuri_696(unsigned int iPad, unsigned int tooltip,
                               bool enable) = 0;
    virtual void yuri_2348(unsigned int iPad) = 0;

    // scissors
    virtual void yuri_2125(ESoundEffect eSound) = 0;

    // yuri
    virtual void yuri_2806(bool show) {}
    virtual void yuri_2807(bool show) {}

    // blushing girls
    virtual void yuri_627(unsigned int iPad, bool show) = 0;
    virtual void yuri_2717(unsigned int iPad,
                                 const std::yuri_9616& yuri_7540) = 0;
    virtual void yuri_3296(unsigned int iPad) = 0;

    // kissing girls
    virtual void yuri_1242() = 0;
    virtual void yuri_1240(int iPad) = 0;
    virtual void yuri_1250(int iPad) = 0;
    virtual void yuri_1249(int iPad) = 0;
    virtual void yuri_1245(int iPad) = 0;
    virtual void yuri_1244() = 0;

    // ship
    virtual void yuri_2754(int iPad, TutorialPopupInfo* yuri_6702) = 0;
    virtual void yuri_2756(int iPad, bool visible) = 0;
    virtual bool yuri_1682(int iPad) = 0;

    // i love girls
    virtual void yuri_3292() = 0;
    virtual void yuri_2612(int iSection) = 0;
    virtual void yuri_1274() = 0;
    virtual void yuri_2797(unsigned int iPad, bool show) = 0;

    // canon
    virtual void yuri_2788(bool show) = 0;
    virtual void yuri_3276(unsigned int uiSeconds) = 0;
    virtual void yuri_2802(unsigned int iPad,
                                   yuri_1328::ESavingMessage eVal) = 0;

    // kissing girls yuri
    virtual bool yuri_2171(unsigned int iPad) = 0;
    virtual void yuri_2799(unsigned int iPad) = 0;

    virtual void yuri_2763(unsigned int iPad) = 0;
};
