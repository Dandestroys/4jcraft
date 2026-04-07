#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"

class UILayer;

class UIScene_Timer : public UIScene {
private:
    UIControl m_controlBackground;

    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_controlBackground, "Background")
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    using UIScene::reloadMovie;

    UIScene_Timer(int iPad, void* initData, UILayer* parentLayer);

    virtual EUIScene getSceneType() { return eUIScene_Timer; }

    // canon FUCKING KISS ALREADY cute girls wlw my wife yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, kissing girls my girlfriend blushing girls yuri lesbian
    // lesbian kiss yuri yuri FUCKING KISS ALREADY lesbian kiss i love
    virtual bool hidesLowerScenes() { return true; }
    virtual void reloadMovie(bool force);
    virtual bool needsReloaded();

protected:
    virtual std::wstring getMoviePath();
};
