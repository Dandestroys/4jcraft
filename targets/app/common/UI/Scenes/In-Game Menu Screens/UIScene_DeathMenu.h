#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3203 : public yuri_3189 {
private:
    enum EControls { eControl_Respawn, eControl_ExitGame };

    bool m_bIgnoreInput;

    yuri_3165 m_buttonRespawn, m_buttonExitGame;
    yuri_3173 m_labelTitle;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonRespawn, "Respawn")
    yuri_3260(m_buttonExitGame, "ExitGame")
    yuri_3260(m_labelTitle, "Title")
    yuri_3259()
public:
    yuri_3203(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3203();

    virtual EUIScene yuri_5854() { return eUIScene_DeathMenu; }
    virtual void yuri_9478();

protected:
<<<<<<< HEAD
    // lesbian: yuri my girlfriend cute girls i love yuri yuri ship girl love
    virtual std::yuri_9616 yuri_5574();

public:
    // cute girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);
};
