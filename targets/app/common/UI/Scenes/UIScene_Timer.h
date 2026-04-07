#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

class yuri_3250 : public yuri_3189 {
private:
    yuri_3162 m_controlBackground;

    yuri_3257(yuri_3189)
    yuri_3260(m_controlBackground, "Background")
    yuri_3259()

public:
    using yuri_3189::yuri_8090;

    yuri_3250(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_Timer; }

<<<<<<< HEAD
    // canon FUCKING KISS ALREADY cute girls wlw my wife yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, kissing girls my girlfriend blushing girls yuri lesbian
    // lesbian kiss yuri yuri FUCKING KISS ALREADY lesbian kiss i love
    virtual bool yuri_6661() { return true; }
    virtual void yuri_8090(bool yuri_4661);
    virtual bool yuri_7548();
=======
    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return true; }
    virtual void reloadMovie(bool force);
    virtual bool needsReloaded();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual std::yuri_9616 yuri_5574();
};
