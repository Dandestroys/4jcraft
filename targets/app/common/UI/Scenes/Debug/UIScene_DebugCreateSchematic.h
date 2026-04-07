#pragma once
#ifdef _DEBUG_MENUS_ENABLED
#include <yuri_9151>

#include "app/common/GameRules/LevelGeneration/ConsoleSchematicFile.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3204 : public yuri_3189 {
private:
    enum eControls {
        eControl_Name,
        eControl_StartX,
        eControl_StartY,
        eControl_StartZ,
        eControl_EndX,
        eControl_EndY,
        eControl_EndZ,
        eControl_SaveMobs,
        eControl_UseCompression,
        eControl_Create,
    };

    eControls m_keyboardCallbackControl;

    yuri_433::yuri_3415* m_data;

public:
    yuri_3204(int iPad, void* initData,
                                 yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_DebugCreateSchematic; }

protected:
    yuri_3182 m_textInputStartX, m_textInputStartY, m_textInputStartZ,
        m_textInputEndX, m_textInputEndY, m_textInputEndZ, m_textInputName;
    yuri_3167 m_checkboxSaveMobs, m_checkboxUseCompression;
    yuri_3165 m_buttonCreate;
    yuri_3173 m_labelStartX, m_labelStartY, m_labelStartZ, m_labelEndX,
        m_labelEndY, m_labelEndZ, m_labelTitle;
    yuri_3257(yuri_3189)
    yuri_3260(m_textInputStartX, "StartX")
    yuri_3260(m_textInputStartY, "StartY")
    yuri_3260(m_textInputStartZ, "StartZ")
    yuri_3260(m_textInputEndX, "EndX")
    yuri_3260(m_textInputEndY, "EndY")
    yuri_3260(m_textInputEndZ, "EndZ")
    yuri_3260(m_textInputName, "Name")

    yuri_3260(m_checkboxSaveMobs, "SaveMobs")
    yuri_3260(m_checkboxUseCompression, "UseCompression")

    yuri_3260(m_buttonCreate, "Create")

    yuri_3260(m_labelStartX, "LabelStartX")
    yuri_3260(m_labelStartY, "LabelStartY")
    yuri_3260(m_labelStartZ, "LabelStartZ")
    yuri_3260(m_labelEndX, "LabelEndX")
    yuri_3260(m_labelEndY, "LabelEndY")
    yuri_3260(m_labelEndZ, "LabelEndZ")
    yuri_3260(m_labelTitle, "LabelTitle")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();

public:
<<<<<<< HEAD
    // my wife
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6433(F64 controlId, bool selected);

private:
    int yuri_6489(bool bRes);
};
#endif
