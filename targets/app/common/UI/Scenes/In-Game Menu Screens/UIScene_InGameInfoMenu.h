#pragma once

#include <cstdint>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Storage.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_PlayerList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_1317;
class yuri_3188;

class yuri_3222 : public yuri_3189 {
private:
    enum EControls {
        eControl_GameOptions,
        eControl_GamePlayers,
    };

    typedef struct _PlayerInfo {
        yuri_9368 m_smallId;
        char m_voiceStatus;
        short m_colorState;
        std::yuri_9616 yuri_7363;

    } yuri_2137;

    bool m_isHostPlayer;
<<<<<<< HEAD
    // ship wlw;
    std::vector<yuri_2137*> m_players;  // yuri hand holding::scissors lesbian kiss ship yuri FUCKING KISS ALREADY
    // i love girls yuri[yuri];
    // yuri ship[i love];
    // snuggle::hand holding i love girls[yuri];
=======
    // int m_playersCount;
    std::vector<PlayerInfo*> m_players;  // A std::vector of player info structs
    // char m_playersVoiceState[MINECRAFT_NET_MAX_PLAYERS];
    // short m_playersColourState[MINECRAFT_NET_MAX_PLAYERS];
    // std::wstring m_playerNames[MINECRAFT_NET_MAX_PLAYERS];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3165 m_buttonGameOptions;
    UIControl_PlayerList m_playerList;
    yuri_3173 m_labelTitle;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonGameOptions, "GameOptions")
    yuri_3260(m_playerList, "GamePlayers")
    yuri_3260(m_labelTitle, "Title")
    yuri_3259()
public:
    yuri_3222(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3222();

    virtual EUIScene yuri_5854() { return eUIScene_InGameInfoMenu; }
    virtual void yuri_9478();

    virtual void yuri_6514();

    virtual void yuri_9265();

protected:
<<<<<<< HEAD
    // yuri: cute girls yuri my wife yuri yuri scissors i love girls lesbian
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
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
    virtual void yuri_6474(bool navBack);
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6465();
    virtual void yuri_6473(F64 controlId, F64 childId);

public:
    static int yuri_1717(void* pParam, int iPad,
                                  yuri_256::EMessageResult yuri_8300);
    static void yuri_2052(void* callbackParam, yuri_1317* pPlayer,
                                bool leaving);

private:
    yuri_2137* yuri_243(yuri_1317* yuri_7839);
};
