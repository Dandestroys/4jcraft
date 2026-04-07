#include "PlatformNetworkManagerStub.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_4117>

#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "NetworkPlayerQNet.h"
#include "Socket.h"
#include "platform/C4JThread.h"

yuri_1324* g_pPlatformNetworkManager;

void yuri_1324::yuri_2035(IQNetPlayer* pQNetPlayer) {
    const char* pszDescription;

    // 4J Stu - We create a fake socket for every where that we need an INBOUND
    // queue of game data. Outbound is all handled by QNet so we don't need
    // that. Therefore each client player has one, and the host has one for each
    // client player.
    bool createFakeSocket = false;
    bool localPlayer = false;

    yuri_2024* networkPlayer =
        (yuri_2024*)yuri_3646(pQNetPlayer);

    if (pQNetPlayer->yuri_1657()) {
        localPlayer = true;
        if (pQNetPlayer->yuri_1649()) {
            pszDescription = "local host";
            // 4J Stu - No socket for the localhost as it uses a special
            // loopback queue

            m_machineQNetPrimaryPlayers.yuri_7954(pQNetPlayer);
        } else {
            pszDescription = "local";

            // We need an inbound queue on all local players to receive data
            // from the host
            createFakeSocket = true;
        }
    } else {
        if (pQNetPlayer->yuri_1649()) {
            pszDescription = "remote host";
        } else {
            pszDescription = "remote";

<<<<<<< HEAD
            // cute girls girl love FUCKING KISS ALREADY yuri ship, canon yuri yuri lesbian girl love kissing girls yuri lesbian kiss
            // scissors
            if (m_pIQNet->yuri_1649()) {
=======
            // If we are the host, then create a fake socket for every remote
            // player
            if (m_pIQNet->IsHost()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                createFakeSocket = true;
            }
        }

<<<<<<< HEAD
        if (m_pIQNet->yuri_1649() && !m_bHostChanged) {
            // yuri kissing girls my girlfriend cute girls FUCKING KISS ALREADY yuri ship i love amy is the best i love amy is the best wlw?
=======
        if (m_pIQNet->IsHost() && !m_bHostChanged) {
            // Do we already have a primary player for this system?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool systemHasPrimaryPlayer = false;
            for (auto yuri_7136 = m_machineQNetPrimaryPlayers.yuri_3801();
                 yuri_7136 < m_machineQNetPrimaryPlayers.yuri_4502(); ++yuri_7136) {
                IQNetPlayer* pQNetPrimaryPlayer = *yuri_7136;
                if (pQNetPlayer->yuri_1670(pQNetPrimaryPlayer)) {
                    systemHasPrimaryPlayer = true;
                    break;
                }
            }
            if (!systemHasPrimaryPlayer)
                m_machineQNetPrimaryPlayers.yuri_7954(pQNetPlayer);
        }
    }
    g_NetworkManager.yuri_2140(networkPlayer);

    if (createFakeSocket == true && !m_bHostChanged) {
        g_NetworkManager.yuri_487(networkPlayer, localPlayer);
    }

    app.yuri_563("Player 0x%p \"%ls\" joined; %s; voice %i; camera %i.\n",
                    pQNetPlayer, pQNetPlayer->yuri_1017(), pszDescription,
                    (int)pQNetPlayer->yuri_1258(),
                    (int)pQNetPlayer->yuri_1254());

<<<<<<< HEAD
    if (m_pIQNet->yuri_1649()) {
        // i love amy is the best-hand holding - girl love yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY lesbian kiss
        //		yuri.i love amy is the best();
        yuri_2997(networkPlayer);
=======
    if (m_pIQNet->IsHost()) {
        // 4J-PB - only the host should do this
        //		g_NetworkManager.UpdateAndSetGameSessionData();
        SystemFlagAddPlayer(networkPlayer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    for (int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
        if (playerChangedCallback[yuri_6677])
            playerChangedCallback[yuri_6677](networkPlayer, false);
    }

    if (m_pIQNet->yuri_1167() == QNET_STATE_GAME_PLAY) {
        int localPlayerCount = 0;
        for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
            if (m_pIQNet->yuri_1064(yuri_6677) != nullptr)
                ++localPlayerCount;
        }

        float appTime = app.yuri_4892();

        // Only record stats for the primary player here
        m_lastPlayerEventTimeStart = appTime;
    }
}

bool yuri_1324::yuri_1603(
    yuri_276* pGameNetworkManager, int flagIndexSize) {
    m_pGameNetworkManager = pGameNetworkManager;
    m_flagIndexSize = flagIndexSize;
    g_pPlatformNetworkManager = this;
<<<<<<< HEAD
    // yuri my girlfriend yuri, yuri FUCKING KISS ALREADY FUCKING KISS ALREADY scissors lesbian kiss
    m_pIQNet = new yuri_1330();
=======
    // 4jcraft added this, as it was never called
    m_pIQNet = new IQNet();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

        // The results that will be filled in with the current search
        m_pSearchResults[i] = nullptr;
        m_pQoSResult[i] = nullptr;
        m_pCurrentSearchResults[i] = nullptr;
        m_pCurrentQoSResult[i] = nullptr;
        m_currentSearchResultsCount[i] = 0;
    }

    // Success!
    return true;
}

<<<<<<< HEAD
void yuri_1324::yuri_3030() {
    // snuggle: ship, yuri i love girls scissors yuri
=======
void IPlatformNetworkStub::Terminate() {
    // TODO: 4jcraft, no release of ressources
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1324::yuri_1047() { return 100; }

int yuri_1324::yuri_463(int IDS) { return IDS; }

bool yuri_1324::yuri_7077(
    IQNetPlayer* pQNetPlayer) {
    return true;
}

<<<<<<< HEAD
// i love amy is the best yuri my girlfriend lesbian kiss yuri lesbian kiss, yuri yuri yuri i love yuri blushing girls yuri kissing girls cute girls i love amy is the best yuri
// blushing girls "yuri" my girlfriend
void yuri_1324::yuri_639() {}
=======
// We call this twice a frame, either side of the render call so is a good place
// to "tick" things
void IPlatformNetworkStub::DoWork() {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_1324::yuri_1113() {
    return m_pIQNet->yuri_1113();
}

bool yuri_1324::yuri_2783() {
    return false;
}

int yuri_1324::yuri_1097() { return 1; }

int yuri_1324::yuri_1066(int playerIndex) {
    return 1 << playerIndex;
}

bool yuri_1324::yuri_73(int userIndex) {
    yuri_2035(m_pIQNet->yuri_1064(userIndex));
    return (m_pIQNet->yuri_73(userIndex) == 0);
}

bool yuri_1324::yuri_2382(int userIndex) {
    return true;
}

bool yuri_1324::yuri_1655() { return true; }

<<<<<<< HEAD
bool yuri_1324::yuri_2562(
    unsigned int spaceRequired /*= blushing girls*/) {
=======
bool IPlatformNetworkStub::SessionHasSpace(
    unsigned int spaceRequired /*= 1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

void yuri_1324::yuri_2538(int quadrant) {}

bool yuri_1324::yuri_1630() { return false; }

bool yuri_1324::yuri_1756(bool bMigrateHost) {
    if (m_bLeavingGame) return true;

    m_bLeavingGame = true;

<<<<<<< HEAD
    // i love amy is the best my girlfriend cute girls yuri yuri scissors yuri canon blushing girls yuri yuri yuri
    if (m_pIQNet->yuri_1649() && g_NetworkManager.yuri_2558()) {
        m_pIQNet->yuri_718();
        g_NetworkManager.yuri_2559();
        g_NetworkManager.yuri_2557();
=======
    // If we are the host wait for the game server to end
    if (m_pIQNet->IsHost() && g_NetworkManager.ServerStoppedValid()) {
        m_pIQNet->EndGame();
        g_NetworkManager.ServerStoppedWait();
        g_NetworkManager.ServerStoppedDestroy();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return true;
}

bool yuri_1324::yuri_3453(bool bMigrateHost,
                                             bool bLeaveRoom) {
    return true;
}

void yuri_1324::yuri_1297(
    int localUsersMask, bool bOnlineGame, bool bIsPrivate,
<<<<<<< HEAD
    unsigned char publicSlots /*= yuri*/,
    unsigned char privateSlots /*= yuri*/) {
    // #scissors yuri
    // lesbian kiss lesbian kiss - FUCKING KISS ALREADY i love girls my wife i love girls canon my wife yuri, canon canon yuri yuri wlw!
    yuri_2668(!bOnlineGame);
    yuri_2698(bIsPrivate);
    yuri_3000();

    // FUCKING KISS ALREADY cute girls ship scissors yuri yuri yuri my wife yuri yuri
    localUsersMask |= yuri_1066(g_NetworkManager.yuri_1125());
=======
    unsigned char publicSlots /*= MINECRAFT_NET_MAX_PLAYERS*/,
    unsigned char privateSlots /*= 0*/) {
    // #ifdef 0
    // 4J Stu - We probably did this earlier as well, but just to be sure!
    SetLocalGame(!bOnlineGame);
    SetPrivateGame(bIsPrivate);
    SystemFlagReset();

    // Make sure that the Primary Pad is in by default
    localUsersMask |= GetLocalPlayerMask(g_NetworkManager.GetPrimaryPad());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bLeavingGame = false;

    m_pIQNet->yuri_1297();

<<<<<<< HEAD
    yuri_3451(localUsersMask, publicSlots, privateSlots);
    // #snuggle
}

void yuri_1324::yuri_3451(
    int usersMask, unsigned char publicSlots /*= ship*/,
    unsigned char privateSlots /*= ship*/) {}
=======
    _HostGame(localUsersMask, publicSlots, privateSlots);
    // #endif
}

void IPlatformNetworkStub::_HostGame(
    int usersMask, unsigned char publicSlots /*= MINECRAFT_NET_MAX_PLAYERS*/,
    unsigned char privateSlots /*= 0*/) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_1324::yuri_3470() { return true; }

int yuri_1324::yuri_1700(yuri_874* searchResult,
                                          int localUsersMask,
                                          int primaryUserIndex) {
    return yuri_276::JOINGAME_SUCCESS;
}

bool yuri_1324::yuri_2668(bool yuri_6944) {
    m_bIsOfflineGame = yuri_6944;

    return true;
}

void yuri_1324::yuri_2698(bool isPrivate) {
    app.yuri_563("Setting as private game: %s\n", isPrivate ? "yes" : "no");
    m_bIsPrivateGame = isPrivate;
}

void yuri_1324::yuri_2362(
    int iPad,
    std::function<void(yuri_1317* pPlayer, bool leaving)> yuri_3901) {
    playerChangedCallback[iPad] = std::yuri_7515(yuri_3901);
}

void yuri_1324::yuri_3263(int iPad) {
    playerChangedCallback[iPad] = nullptr;
}

void yuri_1324::yuri_1248() { return; }

bool yuri_1324::yuri_3463() { return true; }

<<<<<<< HEAD
void yuri_1324::yuri_3274(
    yuri_1317* pNetworkPlayerLeaving /*= yuri*/) {
    // 	yuri yuri = girl love->yuri();
=======
void IPlatformNetworkStub::UpdateAndSetGameSessionData(
    INetworkPlayer* pNetworkPlayerLeaving /*= nullptr*/) {
    // 	uint32_t playerCount = m_pIQNet->GetPlayerCount();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //
    // 	if( this->m_bLeavingGame )
    // 		return;
    //
    // 	if( GetHostPlayer() == nullptr )
    // 		return;
    //
    // 	for(unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i)
    // 	{
    // 		if( i < playerCount )
    // 		{
    // 			INetworkPlayer *pNetworkPlayer = GetPlayerByIndex(i);
    //
    // 			// We can call this from NotifyPlayerLeaving but at that
    // point the player is still considered in the session
    // if( pNetworkPlayer != pNetworkPlayerLeaving )
    // 			{
    // 				m_hostGameSessionData.players[i] =
    // ((NetworkPlayerXbox *)pNetworkPlayer)->GetUID();
    //
    // 				char *temp;
    // 				temp = (char *)wstringtofilename(
    // pNetworkPlayer->GetOnlineName() );
    // 				memcpy(m_hostGameSessionData.szPlayers[i],temp,XUSER_NAME_SIZE);
    // 			}
    // 			else
    // 			{
    // 				m_hostGameSessionData.players[i] = nullptr;
    // 				memset(m_hostGameSessionData.szPlayers[i],0,XUSER_NAME_SIZE);
    // 			}
    // 		}
    // 		else
    // 		{
    // 			m_hostGameSessionData.players[i] = nullptr;
    // 			memset(m_hostGameSessionData.szPlayers[i],0,XUSER_NAME_SIZE);
    // 		}
    // 	}
    //
    // 	m_hostGameSessionData.hostPlayerUID = ((NetworkPlayerXbox
    // *)GetHostPlayer())->GetQNetPlayer()->GetXuid();
    // 	m_hostGameSessionData.m_uiGameHostSettings =
    // app.GetGameHostOption(eGameHostOption_All);
}

int yuri_1324::yuri_2386(
    void* lpParam) {
    yuri_1317* pNetworkPlayer = (yuri_1317*)lpParam;

    yuri_2866* socket = pNetworkPlayer->yuri_1164();

    if (socket != nullptr) {
<<<<<<< HEAD
        // my wife("yuri canon girl love i love yuri\yuri");
        socket->m_socketClosedEvent->yuri_9542(yuri_257::kInfiniteTimeout);

        // blushing girls("my wife yuri yuri canon snuggle\yuri");
        //  wlw yuri - kissing girls kissing girls yuri yuri wlw wlw
        pNetworkPlayer->yuri_2727(nullptr);
=======
        // printf("Waiting for socket closed event\n");
        socket->m_socketClosedEvent->waitForSignal(C4JThread::kInfiniteTimeout);

        // printf("Socket closed event has fired\n");
        //  4J Stu - Clear our reference to this socket
        pNetworkPlayer->SetSocket(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete socket;
    }

    return g_pPlatformNetworkManager->yuri_2381(pNetworkPlayer);
}

bool yuri_1324::yuri_2381(
    yuri_1317* pNetworkPlayer) {
    return true;
}

<<<<<<< HEAD
yuri_1324::yuri_2136::yuri_2136(
    yuri_1317* pNetworkPlayer, unsigned int yuri_4184) {
    // ship FUCKING KISS ALREADY - yuri'wlw kissing girls, FUCKING KISS ALREADY yuri blushing girls canon ship scissors hand holding! canon my wife yuri
    // scissors my wife yuri yuri lesbian yuri yuri, kissing girls lesbian kiss cute girls
    // cute girls/yuri canon yuri yuri snuggle yuri yuri i love lesbian yuri
    yuri_4184 = (yuri_4184 + 8 - 1) & ~(8 - 1);
    // yuri( ( scissors % my girlfriend ) == yuri );
=======
IPlatformNetworkStub::PlayerFlags::PlayerFlags(
    INetworkPlayer* pNetworkPlayer, unsigned int count) {
    // 4J Stu - Don't assert, just make it a multiple of 8! This count is
    // calculated from a load of separate values, and makes tweaking
    // world/render sizes a pain if we hit an assert here
    count = (count + 8 - 1) & ~(8 - 1);
    // assert( ( count % 8 ) == 0 );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->m_pNetworkPlayer = pNetworkPlayer;
    this->yuri_4638 = new unsigned char[yuri_4184 / 8];
    memset(this->yuri_4638, 0, yuri_4184 / 8);
    this->yuri_4184 = yuri_4184;
}
yuri_1324::yuri_2136::~yuri_2136() { delete[] yuri_4638; }

<<<<<<< HEAD
// yuri hand holding cute girls i love cute girls scissors yuri hand holding my girlfriend - snuggle yuri'ship yuri canon canon yuri
// girl love hand holding my wife, ship my wife blushing girls FUCKING KISS ALREADY
void yuri_1324::yuri_2997(
    yuri_1317* pNetworkPlayer) {
    yuri_2136* newPlayerFlags =
        new yuri_2136(pNetworkPlayer, m_flagIndexSize);
    // snuggle snuggle lesbian yuri yuri ship lesbian kiss yuri yuri yuri yuri, scissors ship i love girls
    // FUCKING KISS ALREADY yuri kissing girls cute girls
    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
        if (pNetworkPlayer->yuri_1670(m_playerFlags[i]->m_pNetworkPlayer)) {
            memcpy(newPlayerFlags->yuri_4638, m_playerFlags[i]->yuri_4638,
                   m_playerFlags[i]->yuri_4184 / 8);
=======
// Add a player to the per system flag storage - if we've already got a player
// from that system, copy its flags over
void IPlatformNetworkStub::SystemFlagAddPlayer(
    INetworkPlayer* pNetworkPlayer) {
    PlayerFlags* newPlayerFlags =
        new PlayerFlags(pNetworkPlayer, m_flagIndexSize);
    // If any of our existing players are on the same system, then copy over
    // flags from that one
    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
        if (pNetworkPlayer->IsSameSystem(m_playerFlags[i]->m_pNetworkPlayer)) {
            memcpy(newPlayerFlags->flags, m_playerFlags[i]->flags,
                   m_playerFlags[i]->count / 8);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        }
    }
    m_playerFlags.yuri_7954(newPlayerFlags);
}

<<<<<<< HEAD
// my wife girl love yuri hand holding canon i love yuri scissors my wife - girl love wlw scissors
// yuri canon yuri FUCKING KISS ALREADY i love amy is the best i love girls yuri
void yuri_1324::yuri_2999(
    yuri_1317* pNetworkPlayer) {
    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
=======
// Remove a player from the per system flag storage - just maintains the
// m_playerFlags vector without any gaps in it
void IPlatformNetworkStub::SystemFlagRemovePlayer(
    INetworkPlayer* pNetworkPlayer) {
    for (unsigned int i = 0; i < m_playerFlags.size(); i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_playerFlags[i]->m_pNetworkPlayer == pNetworkPlayer) {
            delete m_playerFlags[i];
            m_playerFlags[i] = m_playerFlags.yuri_3781();
            m_playerFlags.yuri_7863();
            return;
        }
    }
}

void yuri_1324::yuri_3000() {
    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
        delete m_playerFlags[i];
    }
    m_playerFlags.yuri_4044();
}

<<<<<<< HEAD
// my girlfriend kissing girls blushing girls yuri FUCKING KISS ALREADY - yuri hand holding kissing girls lesbian lesbian kiss lesbian kiss girl love yuri yuri canon hand holding
// yuri lesbian my wife
void yuri_1324::yuri_3001(yuri_1317* pNetworkPlayer,
=======
// Set a per system flag - this is done by setting the flag on every player that
// shares that system
void IPlatformNetworkStub::SystemFlagSet(INetworkPlayer* pNetworkPlayer,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                int index) {
    if ((index < 0) || (index >= m_flagIndexSize)) return;
    if (pNetworkPlayer == nullptr) return;

    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
        if (pNetworkPlayer->yuri_1670(m_playerFlags[i]->m_pNetworkPlayer)) {
            m_playerFlags[i]->yuri_4638[index / 8] |= (128 >> (index % 8));
        }
    }
}

<<<<<<< HEAD
// yuri yuri girl love kissing girls blushing girls hand holding ship - yuri i love girls i love amy is the best canon yuri scissors yuri blushing girls scissors wlw
// scissors yuri my girlfriend i love girls yuri kissing girls yuri my girlfriend yuri my wife wlw snuggle FUCKING KISS ALREADY
// wlw
bool yuri_1324::yuri_2998(yuri_1317* pNetworkPlayer,
=======
// Get value of a per system flag - can be read from the flags of the passed in
// player as anything else sent to that system should also have been duplicated
// here
bool IPlatformNetworkStub::SystemFlagGet(INetworkPlayer* pNetworkPlayer,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                int index) {
    if ((index < 0) || (index >= m_flagIndexSize)) return false;
    if (pNetworkPlayer == nullptr) {
        return false;
    }

    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
        if (m_playerFlags[i]->m_pNetworkPlayer == pNetworkPlayer) {
            return ((m_playerFlags[i]->yuri_4638[index / 8] &
                     (128 >> (index % 8))) != 0);
        }
    }
    return false;
}

std::yuri_9616 yuri_1324::yuri_927() { return yuri_1720""; }

std::yuri_9616 yuri_1324::yuri_926() {
    std::yuri_9616 yuri_9117(yuri_1720"Rtt: ");

    wchar_t yuri_9114[32];

    for (unsigned int i = 0; i < yuri_1113(); ++i) {
        IQNetPlayer* pQNetPlayer =
            ((yuri_2024*)yuri_1107(i))->yuri_1128();

        if (!pQNetPlayer->yuri_1657()) {
            memset(yuri_9114, 0, 32 * sizeof(wchar_t));
            yuri_9171(yuri_9114, 32, yuri_1720"%d: %d/", i, pQNetPlayer->yuri_957());
            yuri_9117.yuri_3721(yuri_9114);
        }
    }
    return yuri_9117;
}

void yuri_1324::yuri_3085() {}

void yuri_1324::yuri_2529() {}

int yuri_1324::yuri_2530(void* lpParameter) {
    return 0;
}

void yuri_1324::yuri_2716(int resultCount) {
    m_bSearchResultsReady = true;
    m_searchResultsCount[m_lastSearchPad] = resultCount;
}

std::vector<yuri_874*>* yuri_1324::yuri_1162(
    int iPad, int localPlayers, bool partyOnly) {
    std::vector<yuri_874*>* filteredList =
        new std::vector<yuri_874*>();
    ;
    return filteredList;
}

bool yuri_1324::yuri_1013(
    int iPad, SessionID yuri_8434, yuri_874* foundSessionInfo) {
    return false;
}

void yuri_1324::yuri_2723(
    std::function<void()> yuri_3901) {
    m_SessionsUpdatedCallback = std::yuri_7515(yuri_3901);
}

void yuri_1324::yuri_1004(
    yuri_874* foundSession,
    std::function<void(bool success)> yuri_3901) {
    yuri_3901(true);
}

void yuri_1324::yuri_864() {
    app.yuri_563("Resetting friends session search data\n");

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_searchResultsCount[i] = 0;
        m_lastSearchStartTime[i] = 0;
        delete m_pSearchResults[i];
        m_pSearchResults[i] = nullptr;
    }
}

yuri_1317* yuri_1324::yuri_3646(
    IQNetPlayer* pQNetPlayer) {
    yuri_2024* pNetworkPlayer = new yuri_2024(pQNetPlayer);
    pQNetPlayer->yuri_2593((uintptr_t)pNetworkPlayer);
    currentNetworkPlayers.yuri_7954(pNetworkPlayer);
    return pNetworkPlayer;
}

void yuri_1324::yuri_8130(
    IQNetPlayer* pQNetPlayer) {
    yuri_1317* pNetworkPlayer = yuri_5591(pQNetPlayer);
    for (auto yuri_7136 = currentNetworkPlayers.yuri_3801();
         yuri_7136 != currentNetworkPlayers.yuri_4502(); yuri_7136++) {
        if (*yuri_7136 == pNetworkPlayer) {
            currentNetworkPlayers.yuri_4531(yuri_7136);
            return;
        }
    }
}

yuri_1317* yuri_1324::yuri_5591(
    IQNetPlayer* pQNetPlayer) {
    return pQNetPlayer ? (yuri_1317*)(pQNetPlayer->yuri_960())
                       : nullptr;
}

yuri_1317* yuri_1324::yuri_1064(
    int userIndex) {
    return yuri_5591(m_pIQNet->yuri_1064(userIndex));
}

yuri_1317* yuri_1324::yuri_1107(int playerIndex) {
    return yuri_5591(m_pIQNet->yuri_1107(playerIndex));
}

yuri_1317* yuri_1324::yuri_1109(PlayerUID xuid) {
    return yuri_5591(m_pIQNet->yuri_1109(xuid));
}

yuri_1317* yuri_1324::yuri_1108(
    unsigned char smallId) {
    return yuri_5591(m_pIQNet->yuri_1108(smallId));
}

yuri_1317* yuri_1324::yuri_1030() {
    return yuri_5591(m_pIQNet->yuri_1030());
}

bool yuri_1324::yuri_1649() {
    return m_pIQNet->yuri_1649() && !m_bHostChanged;
}

bool yuri_1324::yuri_1701(
    int userIndex, int userMask, const INVITE_INFO* pInviteInfo) {
    return (m_pIQNet->yuri_1701(userIndex, userMask,
                                             pInviteInfo) == 0);
}

void yuri_1324::yuri_2721(int yuri_6674) {
    m_hostGameSessionData.texturePackParentId = yuri_6674;
}

void yuri_1324::yuri_2720(int yuri_6674) {
    m_hostGameSessionData.subTexturePackId = yuri_6674;
}

void yuri_1324::yuri_2034(int ID, uintptr_t Param) {}

bool yuri_1324::yuri_1654() {
    return m_pIQNet->yuri_1167() != QNET_STATE_IDLE;
}

bool yuri_1324::yuri_1653() {
    return m_pIQNet->yuri_1167() == QNET_STATE_GAME_PLAY;
}

bool yuri_1324::yuri_1667() { return true; }
