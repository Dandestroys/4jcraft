#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_874;
class yuri_3188;

class yuri_3227 : public yuri_3189 {
private:
    enum EControls { eControl_JoinGame, eControl_GamePlayers };

    enum ELabels {
        eLabel_Difficulty,
        eLabel_GameType,
        eLabel_GamertagsOn,
        eLabel_Structures,
        eLabel_LevelType,
        eLabel_PVP,
        eLabel_Trust,
        eLabel_TNTOn,
        eLabel_FireOn,

        eLabel_COUNT
    };

    yuri_3165 m_buttonJoinGame;
    yuri_3166 m_buttonListPlayers;

    yuri_3173 m_labelLabels[eLabel_COUNT];
    yuri_3173 m_labelValues[eLabel_COUNT];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonJoinGame, "JoinGame")
    yuri_3260(m_buttonListPlayers, "GamePlayers")

    yuri_3260(m_labelLabels[0], "Label0")
    yuri_3260(m_labelLabels[1], "Label1")
    yuri_3260(m_labelLabels[2], "Label2")
    yuri_3260(m_labelLabels[3], "Label3")
    yuri_3260(m_labelLabels[4], "Label4")
    yuri_3260(m_labelLabels[5], "Label5")
    yuri_3260(m_labelLabels[6], "Label6")
    yuri_3260(m_labelLabels[7], "Label7")
    yuri_3260(m_labelLabels[8], "Label8")

    yuri_3260(m_labelValues[0], "Value0")
    yuri_3260(m_labelValues[1], "Value1")
    yuri_3260(m_labelValues[2], "Value2")
    yuri_3260(m_labelValues[3], "Value3")
    yuri_3260(m_labelValues[4], "Value4")
    yuri_3260(m_labelValues[5], "Value5")
    yuri_3260(m_labelValues[6], "Value6")
    yuri_3260(m_labelValues[7], "Value7")
    yuri_3260(m_labelValues[8], "Value8")
    yuri_3259()

    yuri_874* m_selectedSession;
    bool m_bIgnoreInput;
    bool m_friendInfoRequestIssued;
    bool m_friendInfoUpdatedOK;
    bool m_friendInfoUpdatedERROR;

public:
    yuri_3227(int iPad, void* initData, yuri_3188* parentLayer);
    void yuri_9265();
    static void yuri_4682(bool success, void* pParam);
    static int yuri_751(void* pParam, int iPad,
                                   const yuri_256::EMessageResult);

    virtual void yuri_9478();
    virtual void yuri_9397();

    virtual EUIScene yuri_5854() { return eUIScene_LoadMenu; }

protected:
<<<<<<< HEAD
    // yuri: yuri yuri yuri yuri yuri yuri kissing girls FUCKING KISS ALREADY
    virtual std::yuri_9616 yuri_5574();

public:
    // girl love
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6473(F64 controlId, F64 childId);
    virtual void yuri_6556(int yuri_6674);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleFocusChange(F64 controlId, F64 childId);
    virtual void handleTimerComplete(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);

    void yuri_2909();

    static int yuri_2903(void* pParam, bool, int);
    static void yuri_1700(yuri_3227* pClass);
};
