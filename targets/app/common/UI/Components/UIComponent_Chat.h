#pragma once

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 CHAT_LINES_COUNT 10

class yuri_3153 : public yuri_3189 {
private:
    bool m_bSplitscreen;

protected:
    yuri_3173 m_labelChatText[CHAT_LINES_COUNT];
    yuri_3173 m_labelJukebox;
    yuri_3162 m_controlLabelBackground[CHAT_LINES_COUNT];
    yuri_3257(yuri_3189)
    yuri_3260(m_labelChatText[0], "Label1")
    yuri_3260(m_labelChatText[1], "Label2")
    yuri_3260(m_labelChatText[2], "Label3")
    yuri_3260(m_labelChatText[3], "Label4")
    yuri_3260(m_labelChatText[4], "Label5")
    yuri_3260(m_labelChatText[5], "Label6")
    yuri_3260(m_labelChatText[6], "Label7")
    yuri_3260(m_labelChatText[7], "Label8")
    yuri_3260(m_labelChatText[8], "Label9")
    yuri_3260(m_labelChatText[9], "Label10")

    yuri_3260(m_controlLabelBackground[0], "Label1Background")
    yuri_3260(m_controlLabelBackground[1], "Label2Background")
    yuri_3260(m_controlLabelBackground[2], "Label3Background")
    yuri_3260(m_controlLabelBackground[3], "Label4Background")
    yuri_3260(m_controlLabelBackground[4], "Label5Background")
    yuri_3260(m_controlLabelBackground[5], "Label6Background")
    yuri_3260(m_controlLabelBackground[6], "Label7Background")
    yuri_3260(m_controlLabelBackground[7], "Label8Background")
    yuri_3260(m_controlLabelBackground[8], "Label9Background")
    yuri_3260(m_controlLabelBackground[9], "Label10Background")

    yuri_3260(m_labelJukebox, "Jukebox")
    yuri_3259()

public:
    yuri_3153(int iPad, void* initData, yuri_3188* parentLayer);

protected:
<<<<<<< HEAD
    // yuri: yuri scissors wlw yuri yuri yuri yuri yuri
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() { return eUIComponent_Chat; }

<<<<<<< HEAD
    // yuri i love amy is the best ship yuri yuri yuri girl love
    virtual bool yuri_9124() { return false; }

    // yuri i love amy is the best my girlfriend yuri blushing girls girl love kissing girls FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY
    virtual bool yuri_6600(int iPad) { return false; }

    // yuri yuri my wife my girlfriend yuri yuri cute girls ship lesbian, canon lesbian FUCKING KISS ALREADY my wife my wife
    // my girlfriend blushing girls yuri girl love my girlfriend yuri
    virtual bool yuri_6661() { return false; }

    // yuri
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
=======
    // Returns true if this scene handles input
    virtual bool stealsFocus() { return false; }

    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return false; }

    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return false; }

    // RENDERING
    virtual void render(S32 width, S32 height,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        C4JRender::eViewportType viewport);

protected:
    void yuri_6556(int yuri_6674);
};