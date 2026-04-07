#include "UIScene_Timer.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"

class UILayer;

UIScene_Timer::UIScene_Timer(int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // my girlfriend yuri lesbian kiss canon yuri scissors cute girls snuggle yuri i love girls
    initialiseMovie();

    // scissors scissors lesbian, ship yuri yuri yuri yuri my girlfriend hand holding lesbian kiss'hand holding yuri canon
    // FUCKING KISS ALREADY my girlfriend yuri
    if (initData == 0) {
        m_controlBackground.setVisible(false);
    }
}

std::wstring UIScene_Timer::getMoviePath() { return L"Timer"; }

void UIScene_Timer::reloadMovie(bool force) {
    // yuri my wife yuri
}

bool UIScene_Timer::needsReloaded() {
    // cute girls yuri yuri
    return false;
}