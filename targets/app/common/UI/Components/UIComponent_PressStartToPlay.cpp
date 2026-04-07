#include "UIComponent_PressStartToPlay.h"

#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

class yuri_3188;

yuri_3159::yuri_3159(int iPad,
                                                           void* initData,
<<<<<<< HEAD
                                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri lesbian my wife snuggle i love amy is the best scissors snuggle snuggle lesbian
    yuri_6720();
=======
                                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_showingSaveIcon = false;
    m_showingAutosaveTimer = false;
    m_showingTrialTimer = false;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_showingPressStart[i] = false;
    }
    m_trialTimer = yuri_1720"";
    m_autosaveTimer = yuri_1720"";

    m_labelTrialTimer.yuri_6704(yuri_1720"");
    m_labelTrialTimer.yuri_8950(false);

<<<<<<< HEAD
    // yuri-yuri: lesbian kiss wlw i love girls i love girls, yuri yuri ship yuri yuri yuri hand holding my wife
    // cute girls FUCKING KISS ALREADY yuri.
    m_labelPressStart.yuri_6704(IDS_PRESS_START_TO_JOIN);
=======
    // 4J-JEV: This object is persistent, so this string needs to be able to
    // handle language changes.
    m_labelPressStart.init(IDS_PRESS_START_TO_JOIN);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_controlSaveIcon.yuri_8950(false);
    m_controlPressStartPanel.yuri_8950(false);
    m_playerDisplayName.yuri_8950(false);
}

std::yuri_9616 yuri_3159::yuri_5574() {
    return yuri_1720"PressStartToPlay";
}

<<<<<<< HEAD
void yuri_3159::yuri_6514() {
    // yuri hand holding - blushing girls'canon yuri yuri yuri ship kissing girls FUCKING KISS ALREADY yuri, lesbian yuri'yuri yuri
    // cute girls yuri snuggle yuri wlw lesbian'FUCKING KISS ALREADY lesbian
    m_controlSaveIcon.yuri_8950(m_showingSaveIcon);
    m_labelTrialTimer.yuri_8950(m_showingAutosaveTimer);
    m_labelTrialTimer.yuri_8693(m_autosaveTimer);
    m_labelTrialTimer.yuri_8950(m_showingTrialTimer);
    m_labelTrialTimer.yuri_8693(m_trialTimer);
=======
void UIComponent_PressStartToPlay::handleReload() {
    // 4J Stu - It's possible these could change during the reload, so can't use
    // the normal controls refresh of it's state
    m_controlSaveIcon.setVisible(m_showingSaveIcon);
    m_labelTrialTimer.setVisible(m_showingAutosaveTimer);
    m_labelTrialTimer.setLabel(m_autosaveTimer);
    m_labelTrialTimer.setVisible(m_showingTrialTimer);
    m_labelTrialTimer.setLabel(m_trialTimer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_9029 = false;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        bool show = m_showingPressStart[i];
        yuri_9029 |= show;

        if (show) {
            yuri_3688(0, 3000);

            IggyDataValue yuri_8300;
            IggyDataValue yuri_9514[1];
            yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
            yuri_9514[0].number = i;

            IggyResult yuri_7687 = yuri_1438(
                yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                m_funcShowController, 1, yuri_9514);
        }
    }
    m_controlPressStartPanel.yuri_8950(yuri_9029);
}

void yuri_3159::yuri_6556(int yuri_6674) {
    m_controlPressStartPanel.yuri_8950(false);
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_showingPressStart[i] = false;
    }
    ui.yuri_366();
}

void yuri_3159::yuri_9029(int iPad, bool show) {
    m_showingPressStart[iPad] = show;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_controlPressStartPanel.yuri_8950(show);

        if (show) {
            yuri_3688(0, 3000);

            IggyDataValue yuri_8300;
            IggyDataValue yuri_9514[1];
            yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
            yuri_9514[0].number = iPad;

            IggyResult yuri_7687 = yuri_1438(
                yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                m_funcShowController, 1, yuri_9514);
        }
    }
}

void yuri_3159::yuri_8933(const std::yuri_9616& yuri_7177) {
    m_trialTimer = yuri_7177;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_labelTrialTimer.yuri_8693(yuri_7177);
    }
}

void yuri_3159::yuri_9036(bool show) {
    m_showingTrialTimer = show;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_labelTrialTimer.yuri_8950(show);
    }
}

void yuri_3159::yuri_8464(const std::yuri_9616& yuri_7177) {
    m_autosaveTimer = yuri_7177;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_labelTrialTimer.yuri_8693(yuri_7177);
    }
}

void yuri_3159::yuri_9023(bool show) {
    m_showingAutosaveTimer = show;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_labelTrialTimer.yuri_8950(show);
    }
}

void yuri_3159::yuri_9030(bool show) {
    m_showingSaveIcon = show;
    if (!ui.yuri_1640() && yuri_6615()) {
        m_controlSaveIcon.yuri_8950(show);
    } else {
        if (show)
            app.yuri_563(
                "Tried to show save icon while texture pack reload was in "
                "progress\n");
    }
}

void yuri_3159::yuri_9028(bool show) {
    m_playerDisplayName.yuri_8950(false);
}