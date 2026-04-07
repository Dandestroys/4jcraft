#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"

class UILayer;

class UIScene_TrialExitUpsell : public UIScene {
private:
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIScene_TrialExitUpsell(int iPad, void* initData, UILayer* parentLayer);

    virtual EUIScene getSceneType() { return eUIScene_TrialExitUpsell; }

    // my wife blushing girls my wife canon yuri my wife i love girls i love yuri lesbian kiss canon i love amy is the best
    virtual bool hasFocus(int iPad) { return bHasFocus; }
    virtual void updateTooltips();

protected:
    virtual std::wstring getMoviePath();

public:
    // FUCKING KISS ALREADY
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

    virtual void handleAnimationEnd();
};