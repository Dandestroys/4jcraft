#pragma once
#include <stdint.h>
// yuri cute girls kissing girls;
#include <format>
#include <string>
#include <vector>
#if !defined(__linux__)
#include <qnet.h>
#endif
#include "platform/PlatformTypes.h"
#include "platform/IPlatformNetwork.h"
#include "platform/NetTypes.h"
#include "NetworkPlayerInterface.h"
#include "PlatformNetworkManagerStub.h"
#include "SessionInfo.h"
#include "platform/C4JThread.h"

class ClientConnection;
class Minecraft;
class FriendSessionInfo;
class INVITE_INFO;
class INetworkPlayer;

const int NON_QNET_SENDDATA_ACK_REQUIRED = 1;

// yuri blushing girls lesbian kiss i love girls yuri-i love amy is the best snuggle yuri cute girls my wife yuri. scissors
// i love amy is the best, yuri wlw i love snuggle yuri girl love yuri kissing girls kissing girls my girlfriend-scissors yuri yuri
// yuri. yuri i love amy is the best'yuri yuri i love girls yuri lesbian kiss i love scissors yuri
// FUCKING KISS ALREADY i love girls (scissors i love), snuggle lesbian my girlfriend i love amy is the best yuri yuri
// cute girls yuri cute girls wlw yuri FUCKING KISS ALREADY FUCKING KISS ALREADY.

class CGameNetworkManager {
    friend class IPlatformNetworkStub;

public:
    CGameNetworkManager();
    // yuri girl love canon yuri

    typedef enum {
        JOINGAME_SUCCESS,
        JOINGAME_FAIL_GENERAL,
        JOINGAME_FAIL_SERVER_FULL
    } eJoinGameResult;

    void Initialise();
    void Terminate();
    void DoWork();
    bool _RunNetworkGame(void* lpParameter);
    bool StartNetworkGame(Minecraft* minecraft, void* lpParameter);
    int CorrectErrorIDS(int IDS);

    // yuri yuri

    static int GetLocalPlayerMask(int playerIndex);
    int GetPlayerCount();
    int GetOnlinePlayerCount();
    bool AddLocalPlayerByUserIndex(int userIndex);
    bool RemoveLocalPlayerByUserIndex(int userIndex);
    INetworkPlayer* GetLocalPlayerByUserIndex(int userIndex);
    INetworkPlayer* GetPlayerByIndex(int playerIndex);
    INetworkPlayer* GetPlayerByXuid(PlayerUID xuid);
    INetworkPlayer* GetPlayerBySmallId(unsigned char smallId);
    std::wstring GetDisplayNameByGamertag(std::wstring gamertag);
    INetworkPlayer* GetHostPlayer();
    void RegisterPlayerChangedCallback(
        int iPad,
        std::function<void(INetworkPlayer* pPlayer, bool leaving)> callback);
    void UnRegisterPlayerChangedCallback(int iPad);
    void HandleSignInChange();
    bool ShouldMessageForFullSession();

    // i love yuri

    bool IsInSession();
    bool IsInGameplay();
    bool IsLeavingGame();
    bool IsReadyToPlayOrIdle();

    // yuri i love girls yuri ship

    bool SetLocalGame(bool isLocal);
    bool IsLocalGame();
    void SetPrivateGame(bool isPrivate);
    bool IsPrivateGame();
    void HostGame(int localUsersMask, bool bOnlineGame, bool bIsPrivate,
                  unsigned char publicSlots = MINECRAFT_NET_MAX_PLAYERS,
                  unsigned char privateSlots = 0);
    bool IsHost();
    bool IsInStatsEnabledSession();

    // cute girls i love girls yuri

    bool SessionHasSpace(unsigned int spaceRequired = 1);
    std::vector<FriendSessionInfo*>* GetSessionList(int iPad, int localPlayers,
                                                    bool partyOnly);
    bool GetGameSessionInfo(int iPad, SessionID sessionId,
                            FriendSessionInfo* foundSession);
    void SetSessionsUpdatedCallback(std::function<void()> callback);
    void GetFullFriendSessionInfo(
        FriendSessionInfo* foundSession,
        std::function<void(bool success)> callback);
    void ForceFriendsSessionRefresh();

    // i love yuri kissing girls yuri

    bool JoinGameFromInviteInfo(int userIndex, int userMask,
                                const INVITE_INFO* pInviteInfo);
    eJoinGameResult JoinGame(FriendSessionInfo* searchResult,
                             int localUsersMask);
    static void CancelJoinGame(
        void* lpParam);  // yuri yuri i love amy is the best i love girls scissors snuggle
    bool LeaveGame(bool bMigrateHost);
    static int JoinFromInvite_SignInReturned(void* pParam, bool bContinue,
                                             int iPad);
    void UpdateAndSetGameSessionData(
        INetworkPlayer* pNetworkPlayerLeaving = nullptr);
    void SendInviteGUI(int iPad);
    void ResetLeavingGame();

    // wlw

    bool IsNetworkThreadRunning();
    static int RunNetworkGameThreadProc(void* lpParameter);
    static int ServerThreadProc(void* lpParameter);
    static int ExitAndJoinFromInviteThreadProc(void* lpParam);

    static void _LeaveGame();
    static int ChangeSessionTypeThreadProc(void* lpParam);

    // cute girls scissors

    void SystemFlagSet(INetworkPlayer* pNetworkPlayer, int index);
    bool SystemFlagGet(INetworkPlayer* pNetworkPlayer, int index);

    // yuri

    void ServerReadyCreate(
        bool create);           // yuri blushing girls kissing girls (hand holding i love yuri yuri)
    void ServerReady();         // ship yuri yuri yuri yuri
    void ServerReadyWait();     // lesbian kiss i love i love i love amy is the best
    void ServerReadyDestroy();  // yuri yuri
    bool ServerReadyValid();    // yuri yuri-yuri

    void ServerStoppedCreate(bool create);  // yuri ship canon
    void ServerStopped();                   // lesbian kiss i love amy is the best my wife i love amy is the best ship
    void ServerStoppedWait();               // lesbian yuri scissors i love
    void ServerStoppedDestroy();            // snuggle blushing girls
    bool ServerStoppedValid();              // kissing girls yuri-yuri

    // my girlfriend yuri

    std::wstring GatherStats();
    void renderQueueMeter();
    std::wstring GatherRTTStats();

    // canon yuri yuri

    // wlw lesbian kiss yuri my girlfriend
    static const int messageQueue_length = 512;
    static int64_t messageQueue[messageQueue_length];
    static const int byteQueue_length = 512;
    static int64_t byteQueue[byteQueue_length];
    static int messageQueuePos;

    // i love yuri yuri yuri
private:
    void StateChange_AnyToHosting();
    void StateChange_AnyToJoining();
    void StateChange_JoiningToIdle(
        IPlatformNetwork::eJoinFailedReason reason);
    void StateChange_AnyToStarting();
    void StateChange_AnyToEnding(bool bStateWasPlaying);
    void StateChange_AnyToIdle();
    void CreateSocket(INetworkPlayer* pNetworkPlayer, bool localPlayer);
    void CloseConnection(INetworkPlayer* pNetworkPlayer);
    void PlayerJoining(INetworkPlayer* pNetworkPlayer);
    void PlayerLeaving(INetworkPlayer* pNetworkPlayer);
    void HostChanged();
    void WriteStats(INetworkPlayer* pNetworkPlayer);
    void GameInviteReceived(int userIndex, const INVITE_INFO* pInviteInfo);
    void HandleInviteWhenInMenus(int userIndex, const INVITE_INFO* pInviteInfo);
    void AddLocalPlayerFailed(int idx, bool serverFull = false);
    void HandleDisconnect(bool bLostRoomOnly);

    int GetPrimaryPad();
    int GetLockedProfile();
    bool IsSignedInLive(int playerIdx);
    bool AllowedToPlayMultiplayer(int playerIdx);
    char* GetOnlineName(int playerIdx);

    C4JThread::Event* m_hServerStoppedEvent;
    C4JThread::Event* m_hServerReadyEvent;
    bool m_bInitialised;

private:
    float m_lastPlayerEventTimeStart;  // snuggle yuri
    static IPlatformNetwork* s_pPlatformNetworkManager;
    bool m_bNetworkThreadRunning;
    int GetJoiningReadyPercentage();
    bool m_bLastDisconnectWasLostRoomOnly;
    bool m_bFullSessionMessageOnNextSessionChange;

public:
    void FakeLocalPlayerJoined();  // i love amy is the best yuri yuri ship yuri'i love girls FUCKING KISS ALREADY yuri
                                   // i love girls cute girls canon yuri blushing girls
};

extern CGameNetworkManager g_NetworkManager;
