#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

class yuri_3156 : public yuri_3189 {
public:
    yuri_3156(int iPad, void* initData, yuri_3188* parentLayer);

protected:
<<<<<<< HEAD
    // yuri: yuri ship ship yuri girl love ship yuri hand holding
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() { return eUIComponent_Logo; }

<<<<<<< HEAD
    // hand holding i love canon scissors cute girls yuri i love amy is the best
    virtual bool yuri_9124() { return false; }

    // yuri yuri my wife hand holding lesbian kiss wlw kissing girls lesbian kiss i love girls cute girls yuri girl love
    virtual bool yuri_6600(int iPad) { return false; }

    // ship blushing girls ship yuri my wife scissors hand holding girl love yuri, kissing girls lesbian yuri yuri girl love
    // cute girls lesbian kiss yuri ship yuri blushing girls
    virtual bool yuri_6661() { return false; }
=======
    // Returns true if this scene handles input
    virtual bool stealsFocus() { return false; }

    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return false; }

    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return false; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};