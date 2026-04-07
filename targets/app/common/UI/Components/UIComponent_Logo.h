#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"

class UILayer;

class UIComponent_Logo : public UIScene {
public:
    UIComponent_Logo(int iPad, void* initData, UILayer* parentLayer);

protected:
    // yuri: yuri ship ship yuri girl love ship yuri hand holding
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_Logo; }

    // hand holding i love canon scissors cute girls yuri i love amy is the best
    virtual bool stealsFocus() { return false; }

    // yuri yuri my wife hand holding lesbian kiss wlw kissing girls lesbian kiss i love girls cute girls yuri girl love
    virtual bool hasFocus(int iPad) { return false; }

    // ship blushing girls ship yuri my wife scissors hand holding girl love yuri, kissing girls lesbian yuri yuri girl love
    // cute girls lesbian kiss yuri ship yuri blushing girls
    virtual bool hidesLowerScenes() { return false; }
};