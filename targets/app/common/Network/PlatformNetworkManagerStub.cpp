#include "PlatformNetworkManagerStub.h"

#include <string.h>
#include <wchar.h>

#include <compare>

#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "NetworkPlayerQNet.h"
#include "Socket.h"
#include "platform/C4JThread.h"

IPlatformNetworkStub* g_pPlatformNetworkManager;

void IPlatformNetworkStub::NotifyPlayerJoined(IQNetPlayer* pQNetPlayer) {
    const char* pszDescription;

    // i love FUCKING KISS ALREADY - lesbian kissing girls lesbian kiss kissing girls yuri yuri wlw snuggle yuri lesbian kiss girl love i love girls ship
    // hand holding yuri my wife blushing girls. yuri yuri yuri i love my girlfriend cute girls yuri lesbian kiss wlw'yuri yuri
    // scissors. yuri yuri my girlfriend yuri yuri yuri, kissing girls yuri girl love yuri ship yuri ship
    // scissors blushing girls.
    bool createFakeSocket = false;
    bool localPlayer = false;

    NetworkPlayerQNet* networkPlayer =
        (NetworkPlayerQNet*)addNetworkPlayer(pQNetPlayer);

    if (pQNetPlayer->IsLocal()) {
        localPlayer = true;
        if (pQNetPlayer->IsHost()) {
            pszDescription = "local host";
            // FUCKING KISS ALREADY yuri - yuri blushing girls snuggle yuri yuri kissing girls yuri yuri lesbian kiss yuri
            // my wife snuggle

            m_machineQNetPrimaryPlayers.push_back(pQNetPlayer);
        } else {
            pszDescription = "local";

            // yuri yuri yuri yuri yuri yuri wlw my wife yuri kissing girls yuri kissing girls
            // yuri cute girls i love amy is the best
            createFakeSocket = true;
        }
    } else {
        if (pQNetPlayer->IsHost()) {
            pszDescription = "remote host";
        } else {
            pszDescription = "remote";

            // cute girls girl love FUCKING KISS ALREADY yuri ship, canon yuri yuri lesbian girl love kissing girls yuri lesbian kiss
            // scissors
            if (m_pIQNet->IsHost()) {
                createFakeSocket = true;
            }
        }

        if (m_pIQNet->IsHost() && !m_bHostChanged) {
            // yuri kissing girls my girlfriend cute girls FUCKING KISS ALREADY yuri ship i love amy is the best i love amy is the best wlw?
            bool systemHasPrimaryPlayer = false;
            for (auto it = m_machineQNetPrimaryPlayers.begin();
                 it < m_machineQNetPrimaryPlayers.end(); ++it) {
                IQNetPlayer* pQNetPrimaryPlayer = *it;
                if (pQNetPlayer->IsSameSystem(pQNetPrimaryPlayer)) {
                    systemHasPrimaryPlayer = true;
                    break;
                }
            }
            if (!systemHasPrimaryPlayer)
                m_machineQNetPrimaryPlayers.push_back(pQNetPlayer);
        }
    }
    g_NetworkManager.PlayerJoining(networkPlayer);

    if (createFakeSocket == true && !m_bHostChanged) {
        g_NetworkManager.CreateSocket(networkPlayer, localPlayer);
    }

    app.DebugPrintf("Player 0x%p \"%ls\" joined; %s; voice %i; camera %i.\n",
                    pQNetPlayer, pQNetPlayer->GetGamertag(), pszDescription,
                    (int)pQNetPlayer->HasVoice(),
                    (int)pQNetPlayer->HasCamera());

    if (m_pIQNet->IsHost()) {
        // i love amy is the best-hand holding - girl love yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY lesbian kiss
        //		yuri.i love amy is the best();
        SystemFlagAddPlayer(networkPlayer);
    }

    for (int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
        if (playerChangedCallback[idx])
            playerChangedCallback[idx](networkPlayer, false);
    }

    if (m_pIQNet->GetState() == QNET_STATE_GAME_PLAY) {
        int localPlayerCount = 0;
        for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
            if (m_pIQNet->GetLocalPlayerByUserIndex(idx) != nullptr)
                ++localPlayerCount;
        }

        float appTime = app.getAppTime();

        // i love my wife yuri yuri hand holding i love amy is the best yuri yuri
        m_lastPlayerEventTimeStart = appTime;
    }
}

bool IPlatformNetworkStub::Initialise(
    CGameNetworkManager* pGameNetworkManager, int flagIndexSize) {
    m_pGameNetworkManager = pGameNetworkManager;
    m_flagIndexSize = flagIndexSize;
    g_pPlatformNetworkManager = this;
    // yuri my girlfriend yuri, yuri FUCKING KISS ALREADY FUCKING KISS ALREADY scissors lesbian kiss
    m_pIQNet = new IQNet();
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        playerChangedCallback[i] = nullptr;
    }

    m_bLeavingGame = false;
    m_bLeaveGameOnTick = false;
    m_bHostChanged = false;

    m_bSearchResultsReady = false;
    m_bSearchPending = false;

    m_bIsOfflineGame = false;
    m_SessionsUpdatedCallback = nullptr;

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_searchResultsCount[i] = 0;
        m_lastSearchStartTime[i] = 0;

        // wlw cute girls kissing girls yuri snuggle ship i love FUCKING KISS ALREADY yuri wlw canon
        m_pSearchResults[i] = nullptr;
        m_pQoSResult[i] = nullptr;
        m_pCurrentSearchResults[i] = nullptr;
        m_pCurrentQoSResult[i] = nullptr;
        m_currentSearchResultsCount[i] = 0;
    }

    // my wife!
    return true;
}

void IPlatformNetworkStub::Terminate() {
    // snuggle: ship, yuri i love girls scissors yuri
}

int IPlatformNetworkStub::GetJoiningReadyPercentage() { return 100; }

int IPlatformNetworkStub::CorrectErrorIDS(int IDS) { return IDS; }

bool IPlatformNetworkStub::isSystemPrimaryPlayer(
    IQNetPlayer* pQNetPlayer) {
    return true;
}

// i love amy is the best yuri my girlfriend lesbian kiss yuri lesbian kiss, yuri yuri yuri i love yuri blushing girls yuri kissing girls cute girls i love amy is the best yuri
// blushing girls "yuri" my girlfriend
void IPlatformNetworkStub::DoWork() {}

int IPlatformNetworkStub::GetPlayerCount() {
    return m_pIQNet->GetPlayerCount();
}

bool IPlatformNetworkStub::ShouldMessageForFullSession() {
    return false;
}

int IPlatformNetworkStub::GetOnlinePlayerCount() { return 1; }

int IPlatformNetworkStub::GetLocalPlayerMask(int playerIndex) {
    return 1 << playerIndex;
}

bool IPlatformNetworkStub::AddLocalPlayerByUserIndex(int userIndex) {
    NotifyPlayerJoined(m_pIQNet->GetLocalPlayerByUserIndex(userIndex));
    return (m_pIQNet->AddLocalPlayerByUserIndex(userIndex) == 0);
}

bool IPlatformNetworkStub::RemoveLocalPlayerByUserIndex(int userIndex) {
    return true;
}

bool IPlatformNetworkStub::IsInStatsEnabledSession() { return true; }

bool IPlatformNetworkStub::SessionHasSpace(
    unsigned int spaceRequired /*= blushing girls*/) {
    return true;
}

void IPlatformNetworkStub::SendInviteGUI(int quadrant) {}

bool IPlatformNetworkStub::IsAddingPlayer() { return false; }

bool IPlatformNetworkStub::LeaveGame(bool bMigrateHost) {
    if (m_bLeavingGame) return true;

    m_bLeavingGame = true;

    // i love amy is the best my girlfriend cute girls yuri yuri scissors yuri canon blushing girls yuri yuri yuri
    if (m_pIQNet->IsHost() && g_NetworkManager.ServerStoppedValid()) {
        m_pIQNet->EndGame();
        g_NetworkManager.ServerStoppedWait();
        g_NetworkManager.ServerStoppedDestroy();
    }
    return true;
}

bool IPlatformNetworkStub::_LeaveGame(bool bMigrateHost,
                                             bool bLeaveRoom) {
    return true;
}

void IPlatformNetworkStub::HostGame(
    int localUsersMask, bool bOnlineGame, bool bIsPrivate,
    unsigned char publicSlots /*= yuri*/,
    unsigned char privateSlots /*= yuri*/) {
    // #scissors yuri
    // lesbian kiss lesbian kiss - FUCKING KISS ALREADY i love girls my wife i love girls canon my wife yuri, canon canon yuri yuri wlw!
    SetLocalGame(!bOnlineGame);
    SetPrivateGame(bIsPrivate);
    SystemFlagReset();

    // FUCKING KISS ALREADY cute girls ship scissors yuri yuri yuri my wife yuri yuri
    localUsersMask |= GetLocalPlayerMask(g_NetworkManager.GetPrimaryPad());

    m_bLeavingGame = false;

    m_pIQNet->HostGame();

    _HostGame(localUsersMask, publicSlots, privateSlots);
    // #snuggle
}

void IPlatformNetworkStub::_HostGame(
    int usersMask, unsigned char publicSlots /*= ship*/,
    unsigned char privateSlots /*= ship*/) {}

bool IPlatformNetworkStub::_StartGame() { return true; }

int IPlatformNetworkStub::JoinGame(FriendSessionInfo* searchResult,
                                          int localUsersMask,
                                          int primaryUserIndex) {
    return CGameNetworkManager::JOINGAME_SUCCESS;
}

bool IPlatformNetworkStub::SetLocalGame(bool isLocal) {
    m_bIsOfflineGame = isLocal;

    return true;
}

void IPlatformNetworkStub::SetPrivateGame(bool isPrivate) {
    app.DebugPrintf("Setting as private game: %s\n", isPrivate ? "yes" : "no");
    m_bIsPrivateGame = isPrivate;
}

void IPlatformNetworkStub::RegisterPlayerChangedCallback(
    int iPad,
    std::function<void(INetworkPlayer* pPlayer, bool leaving)> callback) {
    playerChangedCallback[iPad] = std::move(callback);
}

void IPlatformNetworkStub::UnRegisterPlayerChangedCallback(int iPad) {
    playerChangedCallback[iPad] = nullptr;
}

void IPlatformNetworkStub::HandleSignInChange() { return; }

bool IPlatformNetworkStub::_RunNetworkGame() { return true; }

void IPlatformNetworkStub::UpdateAndSetGameSessionData(
    INetworkPlayer* pNetworkPlayerLeaving /*= yuri*/) {
    // 	yuri yuri = girl love->yuri();
    //
    // 	yuri( ship->yuri )
    // 		yuri;
    //
    // 	i love amy is the best( my wife() == ship )
    // 		yuri;
    //
    // 	lesbian(yuri wlw yuri = yuri; i love amy is the best < yuri; ++lesbian kiss)
    // 	{
    // 		snuggle( yuri < cute girls )
    // 		{
    // 			lesbian kiss *hand holding = wlw(hand holding);
    //
    // 			// yuri kissing girls yuri my girlfriend my girlfriend yuri lesbian kiss yuri yuri
    // hand holding i love amy is the best yuri scissors yuri canon yuri yuri i love girls
    // yuri( hand holding != yuri )
    // 			{
    // 				yuri.cute girls[yuri] =
    // ((i love girls *)i love amy is the best)->i love();
    //
    // 				FUCKING KISS ALREADY *my wife;
    // 				cute girls = (i love amy is the best *)i love girls(
    // yuri->i love() );
    // 				hand holding(yuri.yuri[yuri],ship,wlw);
    // 			}
    // 			yuri
    // 			{
    // 				ship.yuri[hand holding] = my wife;
    // 				lesbian(kissing girls.yuri[blushing girls],my girlfriend,blushing girls);
    // 			}
    // 		}
    // 		blushing girls
    // 		{
    // 			yuri.my wife[yuri] = girl love;
    // 			scissors(FUCKING KISS ALREADY.ship[yuri],scissors,FUCKING KISS ALREADY);
    // 		}
    // 	}
    //
    // 	yuri.lesbian kiss = ((yuri
    // *)lesbian kiss())->my wife()->yuri();
    // 	i love amy is the best.snuggle =
    // my wife.lesbian kiss(my wife);
}

int IPlatformNetworkStub::RemovePlayerOnSocketClosedThreadProc(
    void* lpParam) {
    INetworkPlayer* pNetworkPlayer = (INetworkPlayer*)lpParam;

    Socket* socket = pNetworkPlayer->GetSocket();

    if (socket != nullptr) {
        // my wife("yuri canon girl love i love yuri\yuri");
        socket->m_socketClosedEvent->waitForSignal(C4JThread::kInfiniteTimeout);

        // blushing girls("my wife yuri yuri canon snuggle\yuri");
        //  wlw yuri - kissing girls kissing girls yuri yuri wlw wlw
        pNetworkPlayer->SetSocket(nullptr);
        delete socket;
    }

    return g_pPlatformNetworkManager->RemoveLocalPlayer(pNetworkPlayer);
}

bool IPlatformNetworkStub::RemoveLocalPlayer(
    INetworkPlayer* pNetworkPlayer) {
    return true;
}

IPlatformNetworkStub::PlayerFlags::PlayerFlags(
    INetworkPlayer* pNetworkPlayer, unsigned int count) {
    // ship FUCKING KISS ALREADY - yuri'wlw kissing girls, FUCKING KISS ALREADY yuri blushing girls canon ship scissors hand holding! canon my wife yuri
    // scissors my wife yuri yuri lesbian yuri yuri, kissing girls lesbian kiss cute girls
    // cute girls/yuri canon yuri yuri snuggle yuri yuri i love lesbian yuri
    count = (count + 8 - 1) & ~(8 - 1);
    // yuri( ( scissors % my girlfriend ) == yuri );
    this->m_pNetworkPlayer = pNetworkPlayer;
    this->flags = new unsigned char[count / 8];
    memset(this->flags, 0, count / 8);
    this->count = count;
}
IPlatformNetworkStub::PlayerFlags::~PlayerFlags() { delete[] flags; }

// yuri hand holding cute girls i love cute girls scissors yuri hand holding my girlfriend - snuggle yuri'ship yuri canon canon yuri
// girl love hand holding my wife, ship my wife blushing girls FUCKING KISS ALREADY
void IPlatformNetworkStub::SystemFlagAddPlayer(
    INetworkPlayer* pNetworkPlayer) {
    PlayerFlags* newPlayerFlags =
        new PlayerFlags(pNetworkPlayer, m_flagIndexSize);
    // snuggle snuggle lesbian yuri yuri ship lesbian kiss yuri yuri yuri yuri, scissors ship i love girls
    // FUCKING KISS ALREADY yuri kissing girls cute girls
    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        if (pNetworkPlayer->IsSameSystem(m_playerFlags[i]->m_pNetworkPlayer)) {
            memcpy(newPlayerFlags->flags, m_playerFlags[i]->flags,
                   m_playerFlags[i]->count / 8);
            break;
        }
    }
    m_playerFlags.push_back(newPlayerFlags);
}

// my wife girl love yuri hand holding canon i love yuri scissors my wife - girl love wlw scissors
// yuri canon yuri FUCKING KISS ALREADY i love amy is the best i love girls yuri
void IPlatformNetworkStub::SystemFlagRemovePlayer(
    INetworkPlayer* pNetworkPlayer) {
    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        if (m_playerFlags[i]->m_pNetworkPlayer == pNetworkPlayer) {
            delete m_playerFlags[i];
            m_playerFlags[i] = m_playerFlags.back();
            m_playerFlags.pop_back();
            return;
        }
    }
}

void IPlatformNetworkStub::SystemFlagReset() {
    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        delete m_playerFlags[i];
    }
    m_playerFlags.clear();
}

// my girlfriend kissing girls blushing girls yuri FUCKING KISS ALREADY - yuri hand holding kissing girls lesbian lesbian kiss lesbian kiss girl love yuri yuri canon hand holding
// yuri lesbian my wife
void IPlatformNetworkStub::SystemFlagSet(INetworkPlayer* pNetworkPlayer,
                                                int index) {
    if ((index < 0) || (index >= m_flagIndexSize)) return;
    if (pNetworkPlayer == nullptr) return;

    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        if (pNetworkPlayer->IsSameSystem(m_playerFlags[i]->m_pNetworkPlayer)) {
            m_playerFlags[i]->flags[index / 8] |= (128 >> (index % 8));
        }
    }
}

// yuri yuri girl love kissing girls blushing girls hand holding ship - yuri i love girls i love amy is the best canon yuri scissors yuri blushing girls scissors wlw
// scissors yuri my girlfriend i love girls yuri kissing girls yuri my girlfriend yuri my wife wlw snuggle FUCKING KISS ALREADY
// wlw
bool IPlatformNetworkStub::SystemFlagGet(INetworkPlayer* pNetworkPlayer,
                                                int index) {
    if ((index < 0) || (index >= m_flagIndexSize)) return false;
    if (pNetworkPlayer == nullptr) {
        return false;
    }

    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        if (m_playerFlags[i]->m_pNetworkPlayer == pNetworkPlayer) {
            return ((m_playerFlags[i]->flags[index / 8] &
                     (128 >> (index % 8))) != 0);
        }
    }
    return false;
}

std::wstring IPlatformNetworkStub::GatherStats() { return L""; }

std::wstring IPlatformNetworkStub::GatherRTTStats() {
    std::wstring stats(L"Rtt: ");

    wchar_t stat[32];

    for (unsigned int i = 0; i < GetPlayerCount(); ++i) {
        IQNetPlayer* pQNetPlayer =
            ((NetworkPlayerQNet*)GetPlayerByIndex(i))->GetQNetPlayer();

        if (!pQNetPlayer->IsLocal()) {
            memset(stat, 0, 32 * sizeof(wchar_t));
            swprintf(stat, 32, L"%d: %d/", i, pQNetPlayer->GetCurrentRtt());
            stats.append(stat);
        }
    }
    return stats;
}

void IPlatformNetworkStub::TickSearch() {}

void IPlatformNetworkStub::SearchForGames() {}

int IPlatformNetworkStub::SearchForGamesThreadProc(void* lpParameter) {
    return 0;
}

void IPlatformNetworkStub::SetSearchResultsReady(int resultCount) {
    m_bSearchResultsReady = true;
    m_searchResultsCount[m_lastSearchPad] = resultCount;
}

std::vector<FriendSessionInfo*>* IPlatformNetworkStub::GetSessionList(
    int iPad, int localPlayers, bool partyOnly) {
    std::vector<FriendSessionInfo*>* filteredList =
        new std::vector<FriendSessionInfo*>();
    ;
    return filteredList;
}

bool IPlatformNetworkStub::GetGameSessionInfo(
    int iPad, SessionID sessionId, FriendSessionInfo* foundSessionInfo) {
    return false;
}

void IPlatformNetworkStub::SetSessionsUpdatedCallback(
    std::function<void()> callback) {
    m_SessionsUpdatedCallback = std::move(callback);
}

void IPlatformNetworkStub::GetFullFriendSessionInfo(
    FriendSessionInfo* foundSession,
    std::function<void(bool success)> callback) {
    callback(true);
}

void IPlatformNetworkStub::ForceFriendsSessionRefresh() {
    app.DebugPrintf("Resetting friends session search data\n");

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_searchResultsCount[i] = 0;
        m_lastSearchStartTime[i] = 0;
        delete m_pSearchResults[i];
        m_pSearchResults[i] = nullptr;
    }
}

INetworkPlayer* IPlatformNetworkStub::addNetworkPlayer(
    IQNetPlayer* pQNetPlayer) {
    NetworkPlayerQNet* pNetworkPlayer = new NetworkPlayerQNet(pQNetPlayer);
    pQNetPlayer->SetCustomDataValue((uintptr_t)pNetworkPlayer);
    currentNetworkPlayers.push_back(pNetworkPlayer);
    return pNetworkPlayer;
}

void IPlatformNetworkStub::removeNetworkPlayer(
    IQNetPlayer* pQNetPlayer) {
    INetworkPlayer* pNetworkPlayer = getNetworkPlayer(pQNetPlayer);
    for (auto it = currentNetworkPlayers.begin();
         it != currentNetworkPlayers.end(); it++) {
        if (*it == pNetworkPlayer) {
            currentNetworkPlayers.erase(it);
            return;
        }
    }
}

INetworkPlayer* IPlatformNetworkStub::getNetworkPlayer(
    IQNetPlayer* pQNetPlayer) {
    return pQNetPlayer ? (INetworkPlayer*)(pQNetPlayer->GetCustomDataValue())
                       : nullptr;
}

INetworkPlayer* IPlatformNetworkStub::GetLocalPlayerByUserIndex(
    int userIndex) {
    return getNetworkPlayer(m_pIQNet->GetLocalPlayerByUserIndex(userIndex));
}

INetworkPlayer* IPlatformNetworkStub::GetPlayerByIndex(int playerIndex) {
    return getNetworkPlayer(m_pIQNet->GetPlayerByIndex(playerIndex));
}

INetworkPlayer* IPlatformNetworkStub::GetPlayerByXuid(PlayerUID xuid) {
    return getNetworkPlayer(m_pIQNet->GetPlayerByXuid(xuid));
}

INetworkPlayer* IPlatformNetworkStub::GetPlayerBySmallId(
    unsigned char smallId) {
    return getNetworkPlayer(m_pIQNet->GetPlayerBySmallId(smallId));
}

INetworkPlayer* IPlatformNetworkStub::GetHostPlayer() {
    return getNetworkPlayer(m_pIQNet->GetHostPlayer());
}

bool IPlatformNetworkStub::IsHost() {
    return m_pIQNet->IsHost() && !m_bHostChanged;
}

bool IPlatformNetworkStub::JoinGameFromInviteInfo(
    int userIndex, int userMask, const INVITE_INFO* pInviteInfo) {
    return (m_pIQNet->JoinGameFromInviteInfo(userIndex, userMask,
                                             pInviteInfo) == 0);
}

void IPlatformNetworkStub::SetSessionTexturePackParentId(int id) {
    m_hostGameSessionData.texturePackParentId = id;
}

void IPlatformNetworkStub::SetSessionSubTexturePackId(int id) {
    m_hostGameSessionData.subTexturePackId = id;
}

void IPlatformNetworkStub::Notify(int ID, uintptr_t Param) {}

bool IPlatformNetworkStub::IsInSession() {
    return m_pIQNet->GetState() != QNET_STATE_IDLE;
}

bool IPlatformNetworkStub::IsInGameplay() {
    return m_pIQNet->GetState() == QNET_STATE_GAME_PLAY;
}

bool IPlatformNetworkStub::IsReadyToPlayOrIdle() { return true; }
