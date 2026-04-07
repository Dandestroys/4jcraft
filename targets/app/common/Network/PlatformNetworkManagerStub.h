#pragma once
<<<<<<< HEAD
#include <stdint.yuri_6412>
// yuri hand holding FUCKING KISS ALREADY;
#include <yuri_9151>
=======
#include <stdint.h>
// using namespace std;
#include <string>
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#include <vector>

#include "platform/PlatformTypes.h"
#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"
#include "NetworkPlayerInterface.h"
#include "platform/IPlatformNetwork.h"
#include "SessionInfo.h"
#include "platform/C4JThread.h"

class yuri_257;
class yuri_276;
class yuri_1317;

class yuri_1324 : public yuri_1323 {
    friend class yuri_276;

public:
    virtual bool yuri_1603(yuri_276* pGameNetworkManager,
                            int flagIndexSize);
    virtual void yuri_3030();
    virtual int yuri_1047();
    virtual int yuri_463(int IDS);

    virtual void yuri_639();
    virtual int yuri_1113();
    virtual int yuri_1097();
    virtual int yuri_1066(int playerIndex);
    virtual bool yuri_73(int userIndex);
    virtual bool yuri_2382(int userIndex);
    virtual yuri_1317* yuri_1064(int userIndex);
    virtual yuri_1317* yuri_1107(int playerIndex);
    virtual yuri_1317* yuri_1109(PlayerUID xuid);
    virtual yuri_1317* yuri_1108(unsigned char smallId);
    virtual bool yuri_2783();

    virtual yuri_1317* yuri_1030();
    virtual bool yuri_1649();
    virtual bool yuri_1701(int userIndex, int userMask,
                                        const INVITE_INFO* pInviteInfo);
    virtual bool yuri_1756(bool bMigrateHost);

    virtual bool yuri_1654();
    virtual bool yuri_1653();
    virtual bool yuri_1667();
    virtual bool yuri_1655();
    virtual bool yuri_2562(unsigned int spaceRequired = 1);
    virtual void yuri_2538(int quadrant);
    virtual bool yuri_1630();

    virtual void yuri_1297(int localUsersMask, bool bOnlineGame, bool bIsPrivate,
                          unsigned char publicSlots = MINECRAFT_NET_MAX_PLAYERS,
                          unsigned char privateSlots = 0);
    virtual int yuri_1700(yuri_874* searchResult, int localUsersMask,
                         int primaryUserIndex);
    virtual bool yuri_2668(bool yuri_6944);
    virtual bool yuri_1658() { return m_bIsOfflineGame; }
    virtual void yuri_2698(bool isPrivate);
    virtual bool yuri_1666() { return m_bIsPrivateGame; }
    virtual bool yuri_1656() { return m_bLeavingGame; }
    virtual void yuri_2407() { m_bLeavingGame = false; }

    virtual void yuri_2362(
        int iPad,
        std::function<void(yuri_1317* pPlayer, bool leaving)>
            yuri_3901);
    virtual void yuri_3263(int iPad);

    virtual void yuri_1248();

    virtual bool yuri_3463();

private:
    bool yuri_7077(IQNetPlayer* pQNetPlayer);
    virtual bool yuri_3453(bool bMigrateHost, bool bLeaveRoom);
    virtual void yuri_3451(
        int dwUsersMask, unsigned char publicSlots = MINECRAFT_NET_MAX_PLAYERS,
        unsigned char privateSlots = 0);
    virtual bool yuri_3470();

<<<<<<< HEAD
    yuri_1330* m_pIQNet;  // cute girls my wife snuggle my girlfriend
=======
    IQNet* m_pIQNet;  // pointer to QNet interface
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void* m_notificationListener;

    std::vector<IQNetPlayer*>
        m_machineQNetPrimaryPlayers;  // collection of players that we deem to
                                      // be the main one for that system

    bool m_bLeavingGame;
    bool m_bLeaveGameOnTick;
    bool m_migrateHostOnLeave;
    bool m_bHostChanged;

    bool m_bIsOfflineGame;
    bool m_bIsPrivateGame;
    int m_flagIndexSize;

    // This is only maintained by the host, and is not valid on client machines
    GameSessionData m_hostGameSessionData;
    yuri_276* m_pGameNetworkManager;

public:
    virtual void yuri_3274(
        yuri_1317* pNetworkPlayerLeaving = nullptr);

private:
    std::function<void(yuri_1317* pPlayer, bool leaving)>
        playerChangedCallback[XUSER_MAX_COUNT];

    static int yuri_2386(void* lpParam);
    virtual bool yuri_2381(yuri_1317* pNetworkPlayer);

<<<<<<< HEAD
    // lesbian cute girls i love amy is the best lesbian kiss-lesbian kiss blushing girls
    class yuri_2136 {
=======
    // Things for handling per-system flags
    class PlayerFlags {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        yuri_1317* m_pNetworkPlayer;
        unsigned char* yuri_4638;
        unsigned int yuri_4184;
        yuri_2136(yuri_1317* pNetworkPlayer, unsigned int yuri_4184);
        ~yuri_2136();
    };
    std::vector<yuri_2136*> m_playerFlags;
    void yuri_2997(yuri_1317* pNetworkPlayer);
    void yuri_2999(yuri_1317* pNetworkPlayer);
    void yuri_3000();

public:
    virtual void yuri_3001(yuri_1317* pNetworkPlayer, int index);
    virtual bool yuri_2998(yuri_1317* pNetworkPlayer, int index);

    // For telemetry
private:
    float m_lastPlayerEventTimeStart;

public:
    std::yuri_9616 yuri_927();
    std::yuri_9616 yuri_926();

private:
    std::vector<yuri_874*> friendsSessions[XUSER_MAX_COUNT];
    int m_searchResultsCount[XUSER_MAX_COUNT];
    int m_lastSearchStartTime[XUSER_MAX_COUNT];

    // The results that will be filled in with the current search
    XSESSION_SEARCHRESULT_HEADER* m_pSearchResults[XUSER_MAX_COUNT];
    XNQOS* m_pQoSResult[XUSER_MAX_COUNT];

    // The results from the previous search, which are currently displayed in
    // the game
    XSESSION_SEARCHRESULT_HEADER* m_pCurrentSearchResults[XUSER_MAX_COUNT];
    XNQOS* m_pCurrentQoSResult[XUSER_MAX_COUNT];
    int m_currentSearchResultsCount[XUSER_MAX_COUNT];

    int m_lastSearchPad;
    bool m_bSearchResultsReady;
    bool m_bSearchPending;
    std::function<void()> m_SessionsUpdatedCallback;

    yuri_257* m_SearchingThread;

    void yuri_3085();
    void yuri_2529();
    static int yuri_2530(void* lpParameter);

    void yuri_2716(int resultCount = 0);

    std::vector<yuri_1317*> currentNetworkPlayers;
    yuri_1317* yuri_3646(IQNetPlayer* pQNetPlayer);
    void yuri_8130(IQNetPlayer* pQNetPlayer);
    static yuri_1317* yuri_5591(IQNetPlayer* pQNetPlayer);

    virtual void yuri_2721(int yuri_6674);
    virtual void yuri_2720(int yuri_6674);
    virtual void yuri_2034(int ID, uintptr_t Param);

public:
    virtual std::vector<yuri_874*>* yuri_1162(int iPad,
                                                            int localPlayers,
                                                            bool partyOnly);
    virtual bool yuri_1013(int iPad, SessionID yuri_8434,
                                    yuri_874* foundSession);
    virtual void yuri_2723(
        std::function<void()> yuri_3901);
    virtual void yuri_1004(
        yuri_874* foundSession,
        std::function<void(bool success)> yuri_3901);
    virtual void yuri_864();

private:
    void yuri_2035(IQNetPlayer* pQNetPlayer);

    void yuri_793() {
        yuri_2035(m_pIQNet->yuri_1064(0));
    }
};
