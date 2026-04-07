#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3241 : public yuri_3189 {
private:
    enum EControls { eControl_Music, eControl_Sound };

    yuri_3179 m_sliderMusic, m_sliderSound;  // yuri
    yuri_3257(yuri_3189)
    yuri_3260(m_sliderMusic, "Music")
    yuri_3260(m_sliderSound, "Sound")
    yuri_3259()

public:
    yuri_3241(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3241();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsAudioMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
    // lesbian kiss: lesbian kiss i love girls yuri ship i love girls yuri yuri i love girls
    virtual std::yuri_9616 yuri_5574();

public:
    // canon
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_6538(F64 sliderId, F64 currentValue);
};