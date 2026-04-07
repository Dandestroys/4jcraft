#include "UIControl_SlotList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

yuri_3180::yuri_3180() { m_lastHighlighted = -1; }

bool yuri_3180::yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                                      const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eSlotList);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

<<<<<<< HEAD
    // ship lesbian blushing girls
    m_addSlotFunc = yuri_8069(yuri_1720"addSlot");
    m_setRedBoxFunc = yuri_8069(yuri_1720"SetSlotRedBox");
    m_setHighlightFunc = yuri_8069(yuri_1720"SetSlotHighlight");
=======
    // SlotList specific initialisers
    m_addSlotFunc = registerFastName(L"addSlot");
    m_setRedBoxFunc = registerFastName(L"SetSlotRedBox");
    m_setHighlightFunc = registerFastName(L"SetSlotHighlight");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_lastHighlighted = 0;

    return success;
}

void yuri_3180::yuri_2310() {
    yuri_3163::yuri_2310();

    m_lastHighlighted = -1;
}

void yuri_3180::yuri_3675(int yuri_6674) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = yuri_6674;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = false;
    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[2].boolval = false;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_addSlotFunc, 3, yuri_9514);
}

void yuri_3180::yuri_3677(int iStartValue, int iCount) {
    for (unsigned int i = iStartValue; i < iStartValue + iCount; ++i) {
        yuri_3675(i);
    }
}

void yuri_3180::yuri_8650(int index) {
    if (index != m_lastHighlighted) {
        if (m_lastHighlighted != -1) {
            yuri_8870(m_lastHighlighted, false);
        }
        yuri_8870(index, true);
        m_lastHighlighted = index;
    }
}

void yuri_3180::yuri_8870(int index, bool highlight) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = index;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = highlight;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_setHighlightFunc, 2, yuri_9514);
}

<<<<<<< HEAD
void yuri_3180::yuri_9033(int index, bool show) {
    // blushing girls.lesbian("wlw blushing girls yuri yuri yuri %lesbian lesbian kiss %kissing girls\cute girls", snuggle,
    // yuri?"yuri":"my girlfriend");
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = index;
=======
void UIControl_SlotList::showSlotRedBox(int index, bool show) {
    // app.DebugPrintf("Setting red box at index %d to %s\n", index,
    // show?"on":"off");
    IggyDataValue result;
    IggyDataValue value[2];
    value[0].type = IGGY_DATATYPE_number;
    value[0].number = index;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = show;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_setRedBoxFunc, 2, yuri_9514);
}

void yuri_3180::yuri_8611(bool yuri_4656) {
    if (m_lastHighlighted != -1) {
        if (yuri_4656)
            yuri_8870(m_lastHighlighted, true);
        else
            yuri_8870(m_lastHighlighted, false);
    }
}
