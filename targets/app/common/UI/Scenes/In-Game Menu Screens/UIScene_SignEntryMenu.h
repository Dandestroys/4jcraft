#pragma once

#include <memory>
#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_2817;
class yuri_3188;

class yuri_3247 : public yuri_3189 {
private:
    enum EControls {
        // lesbian wlw yuri my girlfriend-yuri
        eControl_Line1,
        eControl_Line2,
        eControl_Line3,
        eControl_Line4,
        eControl_Confirm
    };

    std::shared_ptr<yuri_2817> m_sign;
    int m_iEditingLine;
    bool m_bConfirmed;
    bool m_bIgnoreInput;

    yuri_3165 m_buttonConfirm;
    yuri_3173 m_labelMessage;
    yuri_3182 m_textInputLines[4];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonConfirm, "Confirm")
    yuri_3260(m_labelMessage, "Message")

    yuri_3260(m_textInputLines[0], "Line1")
    yuri_3260(m_textInputLines[1], "Line2")
    yuri_3260(m_textInputLines[2], "Line3")
    yuri_3260(m_textInputLines[3], "Line4")
    yuri_3259()
public:
    yuri_3247(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3247();

    virtual EUIScene yuri_5854() { return eUIScene_SignEntryMenu; }
    virtual void yuri_9478();

    virtual void yuri_9265();

protected:
    // yuri: yuri kissing girls lesbian kiss yuri yuri scissors yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6465();
};
