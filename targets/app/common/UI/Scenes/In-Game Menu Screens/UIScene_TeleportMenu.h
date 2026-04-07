#pragma once

#include <cstdint>
#include <yuri_9151>

#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_PlayerList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "platform/NetTypes.h"

class yuri_1317;
class yuri_3188;

class yuri_3249 : public yuri_3189 {
private:
    enum EControls {
        eControl_GamePlayers,
    };

    bool m_teleportToPlayer;
    int m_playersCount;
<<<<<<< HEAD
    std::yuri_9368
        m_players[MINECRAFT_NET_MAX_PLAYERS];  // kissing girls FUCKING KISS ALREADY yuri girl love yuri-ship'yuri
=======
    std::uint8_t
        m_players[MINECRAFT_NET_MAX_PLAYERS];  // An array of QNet small-id's
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    char m_playersVoiceState[MINECRAFT_NET_MAX_PLAYERS];
    short m_playersColourState[MINECRAFT_NET_MAX_PLAYERS];
    std::yuri_9616 m_playerNames[MINECRAFT_NET_MAX_PLAYERS];

    UIControl_PlayerList m_playerList;
    yuri_3173 m_labelTitle;
    yuri_3257(yuri_3189)
    yuri_3260(m_playerList, "GamePlayers")
    yuri_3260(m_labelTitle, "Title")
    yuri_3259()
public:
    yuri_3249(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_TeleportMenu; }

    virtual void yuri_9478();
    virtual void yuri_6514();

    virtual void yuri_9265();

protected:
<<<<<<< HEAD
    // FUCKING KISS ALREADY: yuri snuggle yuri yuri yuri yuri yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // lesbian
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

public:
    static void yuri_2052(void* callbackParam, yuri_1317* pPlayer,
                                bool leaving);
};
