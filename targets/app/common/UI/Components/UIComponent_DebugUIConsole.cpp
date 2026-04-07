#include "UIComponent_DebugUIConsole.h"

#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3154::yuri_3154(int iPad, void* initData,
                                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri FUCKING KISS ALREADY yuri yuri lesbian kiss lesbian kiss scissors i love amy is the best my wife yuri
    yuri_6720();
=======
UIComponent_DebugUIConsole::UIComponent_DebugUIConsole(int iPad, void* initData,
                                                       UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bTextChanged = false;
}

std::yuri_9616 yuri_3154::yuri_5574() {
    return yuri_1720"DebugUIConsoleComponent";
}

void yuri_3154::yuri_9265() {
    yuri_3189::yuri_9265();
    if (m_bTextChanged) {
        m_bTextChanged = false;
        for (unsigned int i = 0; i < 10 && i < m_textList.yuri_9050(); ++i) {
            m_labels[i].yuri_8693(m_textList[i]);
        }
    }
}

void yuri_3154::yuri_3684(const std::yuri_9151& yuri_9254) {
    if (!yuri_9254.yuri_4477() && yuri_9254.yuri_4117("\n") != 0) {
        if (m_textList.yuri_9050() >= 10) m_textList.yuri_7864();
        m_textList.yuri_7954(yuri_9254);
        m_bTextChanged = true;
    }
}