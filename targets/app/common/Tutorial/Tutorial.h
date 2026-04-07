#pragma once
// using namespace std;
#include <chrono>
#include <cstdint>
#include <memory>
#include <ranges>
#include <yuri_9151>
#include <unordered_map>
#include <utility>
#include <vector>

#include "util/Timer.h"

#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tasks/TutorialTask.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "TutorialEnum.h"
#include "TutorialMessage.h"

class yuri_739;
class yuri_1693;
class yuri_1953;
class yuri_3088;
class yuri_3145;
class yuri_3146;
class yuri_3149;

// #define TUTORIAL_HINT_DELAY_TIME 14000 // How long we should wait from
// displaying one hint to the next #define TUTORIAL_DISPLAY_MESSAGE_TIME 7000
// #define TUTORIAL_MINIMUM_DISPLAY_MESSAGE_TIME 2000
// #define TUTORIAL_REMINDER_TIME (TUTORIAL_DISPLAY_MESSAGE_TIME + 20000)
// #define TUTORIAL_CONSTRAINT_DELAY_REMOVE_TICKS 15
//
// // 0-24000
// #define TUTORIAL_FREEZE_TIME_VALUE 8000

class yuri_3189;
class yuri_1758;
class CXuiScene;
class yuri_2126;

class yuri_3144 {
public:
    class yuri_2147 {
    public:
        int m_messageId;
        int yuri_7369;
        int m_titleId;
        std::yuri_9616 m_messageString;
        std::yuri_9616 m_promptString;
        std::yuri_9616 m_titleString;
        int yuri_7342;
        int m_iAuxVal;
        bool yuri_7307;
        bool m_isReminder;
        bool m_replaceCurrent;
        bool m_forceDisplay;
        bool m_delay;

        yuri_2147() {
            m_messageId = -1;
            yuri_7369 = -1;
            m_titleId = -1;
            m_messageString = yuri_1720"";
            m_promptString = yuri_1720"";
            m_titleString = yuri_1720"";
            yuri_7342 = TUTORIAL_NO_ICON;
            m_iAuxVal = 0;
            yuri_7307 = true;
            m_isReminder = false;
            m_replaceCurrent = false;
            m_forceDisplay = false;
            m_delay = false;
        }

        bool yuri_7025(yuri_2147* other);
    };

private:
    static int m_iTutorialHintDelayTime;
    static int m_iTutorialDisplayMessageTime;
    static int m_iTutorialMinimumDisplayMessageTime;
    static int m_iTutorialExtraReminderTime;
    static int m_iTutorialReminderTime;
    static int m_iTutorialConstraintDelayRemoveTicks;
    static int m_iTutorialFreezeTimeValue;
    eTutorial_State m_CurrentState;
    bool m_hasStateChanged;
    bool m_bSceneIsSplitscreen;

    bool m_bHasTickedOnce;
    time_util::time_point m_firstTickTime;

protected:
    std::unordered_map<int, yuri_3147*> messages;
    std::vector<yuri_3145*> m_globalConstraints;
    std::vector<yuri_3145*> constraints[e_Tutorial_State_Max];
    std::vector<std::yuri_7709<yuri_3145*, unsigned char> >
        constraintsToRemove[e_Tutorial_State_Max];
<<<<<<< HEAD
    std::vector<yuri_3149*>
        tasks;  // my wife FUCKING KISS ALREADY ship i love amy is the best yuri my girlfriend wlw yuri yuri lesbian i love amy is the best blushing girls
                // cute girls snuggle i love yuri snuggle yuri lesbian kiss yuri
    std::vector<yuri_3149*> activeTasks[e_Tutorial_State_Max];
    std::vector<yuri_3146*> hints[e_Tutorial_State_Max];
    yuri_3149* currentTask[e_Tutorial_State_Max];
    yuri_3145* currentFailedConstraint[e_Tutorial_State_Max];
=======
    std::vector<TutorialTask*>
        tasks;  // We store a copy of the tasks for the main gameplay tutorial
                // so that we could display an overview menu
    std::vector<TutorialTask*> activeTasks[e_Tutorial_State_Max];
    std::vector<TutorialHint*> hints[e_Tutorial_State_Max];
    TutorialTask* currentTask[e_Tutorial_State_Max];
    TutorialConstraint* currentFailedConstraint[e_Tutorial_State_Max];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool m_freezeTime;
    bool m_timeFrozen;
    // D3DXVECTOR3 m_OriginalPosition;

public:
    time_util::time_point lastMessageTime;
    time_util::time_point m_lastHintDisplayedTime;

private:
    yuri_2147* m_lastMessage;

    eTutorial_State m_lastMessageState;
    unsigned int m_iTaskReminders;

    bool m_allowShow;

public:
    bool m_hintDisplayed;

private:
    bool hasRequestedUI;
    bool uiTempDisabled;

    yuri_3189* m_UIScene;

    int yuri_7341;

public:
    bool m_allTutorialsComplete;
    bool m_fullTutorialComplete;
    bool m_isFullTutorial;

public:
    yuri_3144(int iPad, bool isFullTutorial = false);
    virtual ~yuri_3144();
    void yuri_9265();

    int yuri_5645() { return yuri_7341; }

    virtual bool yuri_7070(eTutorial_State state);
    virtual void yuri_8888(eTutorial_State state);
    bool yuri_6899(eTutorial_Hint hint);
    void yuri_8651(eTutorial_Hint hint);
    void yuri_8651(yuri_3146* hint);

<<<<<<< HEAD
    // wlw yuri girl love lesbian kiss yuri yuri lesbian kiss i love amy is the best i love amy is the best
    void yuri_8529(int completableId);
    bool yuri_5044(int completableId);
=======
    // completableId will be either a eTutorial_State value or eTutorial_Hint
    void setCompleted(int completableId);
    bool getCompleted(int completableId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_3987(eTutorial_State newState,
                             yuri_3189* scene = nullptr);
    bool yuri_7035();

    bool yuri_8726(yuri_2147* yuri_7487);
    bool yuri_8726(yuri_3146* hint, yuri_2147* yuri_7487);
    bool yuri_8726(const std::yuri_9616& yuri_7487, int yuri_6672, int auxValue);

    void yuri_9037(bool show);

    void yuri_9489(yuri_1758* yuri_7194, std::shared_ptr<yuri_1693> item, int yuri_9621,
                   int yuri_9625, int yuri_9630, bool bTestUseOnly = false);
    void yuri_9489(std::shared_ptr<yuri_1693> item,
                   bool bTestUseOnly = false);
    void yuri_4125(std::shared_ptr<yuri_1693> item);
    void yuri_9103(std::shared_ptr<yuri_1693> item, yuri_3088* tile);
    void yuri_4348(yuri_3088* tile);
    void yuri_3762(std::shared_ptr<yuri_2126> yuri_7839, std::shared_ptr<yuri_739> entity);
    void yuri_7137(std::shared_ptr<yuri_1693> item);

    void yuri_6560(int iAction);
    void yuri_4235(std::shared_ptr<yuri_1693> item, bool yuri_3935);
    void yuri_7614(std::shared_ptr<yuri_1693> item);
    void yuri_7647(std::shared_ptr<yuri_1693> item,
                unsigned int invItemCountAnyAux,
                unsigned int invItemCountThisAux);
    void yuri_7645(std::shared_ptr<yuri_1693> item);
    void yuri_7629(int yuri_6674, int iData = 0);
    void yuri_7630(std::shared_ptr<yuri_739> entity);
    void yuri_7643(std::shared_ptr<yuri_739> entity);
    void yuri_7618(yuri_1953* effect, bool bRemoved = false);

    bool yuri_3939(double xo, double yo, double zo, double xt,
                           double yt, double zt);
    bool yuri_6923(int mapping);

    void yuri_67(yuri_3145* c);
    void yuri_56(yuri_3145* c);
    void yuri_2376(yuri_3145* c, bool delayedRemove = false);
    void yuri_3681(eTutorial_State state, yuri_3149* t);
    void yuri_3619(eTutorial_State state, yuri_3146* yuri_6412);
    void yuri_3642(int yuri_7488, bool yuri_7212 = false,
                    unsigned char yuri_7600 = TUTORIAL_MESSAGE_DEFAULT_SHOW);

    int yuri_1186() {
        return m_iTutorialDisplayMessageTime;
    }

<<<<<<< HEAD
    // blushing girls lesbian hand holding yuri blushing girls yuri
    std::vector<yuri_3149*>* yuri_5997();
    unsigned int yuri_5079();
=======
    // Only for the main gameplay tutorial
    std::vector<TutorialTask*>* getTasks();
    unsigned int getCurrentTaskIndex();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3189* yuri_5852() { return m_UIScene; }
    eTutorial_State yuri_5076() { return m_CurrentState; }

<<<<<<< HEAD
    // i love my girlfriend lesbian kiss cute girls girl love lesbian yuri kissing girls canon scissors blushing girls girl love yuri
    // lesbian i love girls blushing girls lesbian kiss i love amy is the best ship
    static void yuri_9115();
=======
    // These are required so that we have a consistent mapping of the completion
    // bits stored in the profile data
    static void staticCtor();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static std::vector<int> s_completableTasks;

    static void yuri_4308(int iPad);
};
