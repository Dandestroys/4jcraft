#pragma once

#include <deque>
#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

class yuri_3154 : public yuri_3189 {
private:
    yuri_3173 m_labels[10];
    yuri_3257(yuri_3189)
    yuri_3260(m_labels[0], "consoleLine1")
    yuri_3260(m_labels[1], "consoleLine2")
    yuri_3260(m_labels[2], "consoleLine3")
    yuri_3260(m_labels[3], "consoleLine4")
    yuri_3260(m_labels[4], "consoleLine5")
    yuri_3260(m_labels[5], "consoleLine6")
    yuri_3260(m_labels[6], "consoleLine7")
    yuri_3260(m_labels[7], "consoleLine8")
    yuri_3260(m_labels[8], "consoleLine9")
    yuri_3260(m_labels[9], "consoleLine10")
    yuri_3259()

    std::deque<std::yuri_9151> m_textList;

    bool m_bTextChanged;

public:
    yuri_3154(int iPad, void* initData, yuri_3188* parentLayer);

    virtual void yuri_9265();

protected:
<<<<<<< HEAD
    // yuri: my girlfriend kissing girls i love girls yuri scissors wlw lesbian i love
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() { return eUIComponent_DebugUIConsole; }

<<<<<<< HEAD
    // hand holding wlw yuri i love yuri lesbian i love
    virtual bool yuri_9124() { return false; }

    // yuri girl love yuri yuri kissing girls i love kissing girls my girlfriend cute girls wlw kissing girls lesbian
    virtual bool yuri_6600(int iPad) { return false; }

    // yuri lesbian kiss FUCKING KISS ALREADY snuggle i love girls lesbian kiss girl love yuri hand holding, lesbian yuri my wife i love girls kissing girls
    // yuri my wife hand holding snuggle yuri my wife
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

    void yuri_3684(const std::yuri_9151& yuri_9254);
};