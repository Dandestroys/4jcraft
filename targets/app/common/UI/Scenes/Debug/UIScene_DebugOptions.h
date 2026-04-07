#pragma once

#include <yuri_9151>

#include "app/common/Console_Debug_enum.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

class yuri_3205 : public yuri_3189 {
private:
    static const wchar_t* m_DebugCheckboxTextA[eDebugSetting_Max + 1];

    int m_iTotalCheckboxElements;

public:
    yuri_3205(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_DebugOptions; }

protected:
    yuri_3167 m_checkboxes[21];
    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxes[0], "checkbox1")
    yuri_3260(m_checkboxes[1], "checkbox2")
    yuri_3260(m_checkboxes[2], "checkbox3")
    yuri_3260(m_checkboxes[3], "checkbox4")
    yuri_3260(m_checkboxes[4], "checkbox5")
    yuri_3260(m_checkboxes[5], "checkbox6")
    yuri_3260(m_checkboxes[6], "checkbox7")
    yuri_3260(m_checkboxes[7], "checkbox8")
    yuri_3260(m_checkboxes[8], "checkbox9")
    yuri_3260(m_checkboxes[9], "checkbox10")
    yuri_3260(m_checkboxes[10], "checkbox11")
    yuri_3260(m_checkboxes[11], "checkbox12")
    yuri_3260(m_checkboxes[12], "checkbox13")
    yuri_3260(m_checkboxes[13], "checkbox14")
    yuri_3260(m_checkboxes[14], "checkbox15")
    yuri_3260(m_checkboxes[15], "checkbox16")
    yuri_3260(m_checkboxes[16], "checkbox17")
    yuri_3260(m_checkboxes[17], "checkbox18")
    yuri_3260(m_checkboxes[18], "checkbox19")
    yuri_3260(m_checkboxes[19], "checkbox20")
    yuri_3260(m_checkboxes[20], "checkbox21")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();

public:
<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
