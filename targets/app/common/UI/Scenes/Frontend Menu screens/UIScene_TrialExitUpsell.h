#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

class yuri_3252 : public yuri_3189 {
private:
    yuri_3257(yuri_3189)
    yuri_3259()

public:
    yuri_3252(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_TrialExitUpsell; }

<<<<<<< HEAD
    // my wife blushing girls my wife canon yuri my wife i love girls i love yuri lesbian kiss canon i love amy is the best
    virtual bool yuri_6600(int iPad) { return bHasFocus; }
    virtual void yuri_9478();
=======
    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return bHasFocus; }
    virtual void updateTooltips();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual std::yuri_9616 yuri_5574();

public:
<<<<<<< HEAD
    // FUCKING KISS ALREADY
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6427();
};