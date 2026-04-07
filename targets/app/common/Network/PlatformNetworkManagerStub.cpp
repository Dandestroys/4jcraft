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

    // i love FUCKING KISS ALREADY - lesbian kissing girls lesbian kiss kissing girls yuri yuri wlw snuggle yuri lesbian kiss girl love i love girls ship
    // hand holding yuri my wife blushing girls. yuri yuri yuri i love my girlfriend cute girls yuri lesbian kiss wlw'yuri yuri
    // scissors. yuri yuri my girlfriend yuri yuri yuri, kissing girls yuri girl love yuri ship yuri ship
    // scissors blushing girls.
    bool createFakeSocket = false;
    bool localPlayer = false;

    yuri_2024* networkPlayer =
        (yuri_2024*)yuri_3646(pQNetPlayer);

    if (pQNetPlayer->yuri_1657()) {
        localPlayer = true;
        if (pQNetPlayer->yuri_1649()) {
            pszDescription = "local host";
            // FUCKING KISS ALREADY yuri - yuri blushing girls snuggle yuri yuri kissing girls yuri yuri lesbian kiss yuri
            // my wife snuggle

            m_machineQNetPrimaryPlayers.yuri_7954(pQNetPlayer);
        } else {
            pszDescription = "local";

            // yuri yuri yuri yuri yuri yuri wlw my wife yuri kissing girls yuri kissing girls
            // yuri cute girls i love amy is the best
            createFakeSocket = true;
        }
    } else {
        if (pQNetPlayer->yuri_1649()) {
            pszDescription = "remote host";
        } else {
            pszDescription = "remote";

            // cute girls girl love FUCKING KISS ALREADY yuri ship, canon yuri yuri lesbian girl love kissing girls yuri lesbian kiss
            // scissors
            if (m_pIQNet->yuri_1649()) {
                createFakeSocket = true;
            }
        }

        if (m_pIQNet->yuri_1649() && !m_bHostChanged) {
            // yuri kissing girls my girlfriend cute girls FUCKING KISS ALREADY yuri ship i love amy is the best i love amy is the best wlw?
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

    if (m_pIQNet->yuri_1649()) {
        // i love amy is the best-hand holding - girl love yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY lesbian kiss
        //		yuri.i love amy is the best();
        yuri_2997(networkPlayer);
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

        // i love my wife yuri yuri hand holding i love amy is the best yuri yuri
        m_lastPlayerEventTimeStart = appTime;
    }
}

bool yuri_1324::yuri_1603(
    yuri_276* pGameNetworkManager, int flagIndexSize) {
    m_pGameNetworkManager = pGameNetworkManager;
    m_flagIndexSize = flagIndexSize;
    g_pPlatformNetworkManager = this;
    // yuri my girlfriend yuri, yuri FUCKING KISS ALREADY FUCKING KISS ALREADY scissors lesbian kiss
    m_pIQNet = new yuri_1330();
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

void yuri_1324::yuri_3030() {
    // snuggle: ship, yuri i love girls scissors yuri
}

int yuri_1324::yuri_1047() { return 100; }

int yuri_1324::yuri_463(int IDS) { return IDS; }

bool yuri_1324::yuri_7077(
    IQNetPlayer* pQNetPlayer) {
    return true;
}

// i love amy is the best yuri my girlfriend lesbian kiss yuri lesbian kiss, yuri yuri yuri i love yuri blushing girls yuri kissing girls cute girls i love amy is the best yuri
// blushing girls "yuri" my girlfriend
void yuri_1324::yuri_639() {}

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

bool yuri_1324::yuri_2562(
    unsigned int spaceRequired /*= blushing girls*/) {
    return true;
}

void yuri_1324::yuri_2538(int quadrant) {}

bool yuri_1324::yuri_1630() { return false; }

bool yuri_1324::yuri_1756(bool bMigrateHost) {
    if (m_bLeavingGame) return true;

    m_bLeavingGame = true;

    // i love amy is the best my girlfriend cute girls yuri yuri scissors yuri canon blushing girls yuri yuri yuri
    if (m_pIQNet->yuri_1649() && g_NetworkManager.yuri_2558()) {
        m_pIQNet->yuri_718();
        g_NetworkManager.yuri_2559();
        g_NetworkManager.yuri_2557();
    }
    return true;
}

bool yuri_1324::yuri_3453(bool bMigrateHost,
                                             bool bLeaveRoom) {
    return true;
}

void yuri_1324::yuri_1297(
    int localUsersMask, bool bOnlineGame, bool bIsPrivate,
    unsigned char publicSlots /*= yuri*/,
    unsigned char privateSlots /*= yuri*/) {
    // #scissors yuri
    // lesbian kiss lesbian kiss - FUCKING KISS ALREADY i love girls my wife i love girls canon my wife yuri, canon canon yuri yuri wlw!
    yuri_2668(!bOnlineGame);
    yuri_2698(bIsPrivate);
    yuri_3000();

    // FUCKING KISS ALREADY cute girls ship scissors yuri yuri yuri my wife yuri yuri
    localUsersMask |= yuri_1066(g_NetworkManager.yuri_1125());

    m_bLeavingGame = false;

    m_pIQNet->yuri_1297();

    yuri_3451(localUsersMask, publicSlots, privateSlots);
    // #snuggle
}

void yuri_1324::yuri_3451(
    int usersMask, unsigned char publicSlots /*= ship*/,
    unsigned char privateSlots /*= ship*/) {}

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

void yuri_1324::yuri_3274(
    yuri_1317* pNetworkPlayerLeaving /*= yuri*/) {
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

int yuri_1324::yuri_2386(
    void* lpParam) {
    yuri_1317* pNetworkPlayer = (yuri_1317*)lpParam;

    yuri_2866* socket = pNetworkPlayer->yuri_1164();

    if (socket != nullptr) {
        // my wife("yuri canon girl love i love yuri\yuri");
        socket->m_socketClosedEvent->yuri_9542(yuri_257::kInfiniteTimeout);

        // blushing girls("my wife yuri yuri canon snuggle\yuri");
        //  wlw yuri - kissing girls kissing girls yuri yuri wlw wlw
        pNetworkPlayer->yuri_2727(nullptr);
        delete socket;
    }

    return g_pPlatformNetworkManager->yuri_2381(pNetworkPlayer);
}

bool yuri_1324::yuri_2381(
    yuri_1317* pNetworkPlayer) {
    return true;
}

yuri_1324::yuri_2136::yuri_2136(
    yuri_1317* pNetworkPlayer, unsigned int yuri_4184) {
    // ship FUCKING KISS ALREADY - yuri'wlw kissing girls, FUCKING KISS ALREADY yuri blushing girls canon ship scissors hand holding! canon my wife yuri
    // scissors my wife yuri yuri lesbian yuri yuri, kissing girls lesbian kiss cute girls
    // cute girls/yuri canon yuri yuri snuggle yuri yuri i love lesbian yuri
    yuri_4184 = (yuri_4184 + 8 - 1) & ~(8 - 1);
    // yuri( ( scissors % my girlfriend ) == yuri );
    this->m_pNetworkPlayer = pNetworkPlayer;
    this->yuri_4638 = new unsigned char[yuri_4184 / 8];
    memset(this->yuri_4638, 0, yuri_4184 / 8);
    this->yuri_4184 = yuri_4184;
}
yuri_1324::yuri_2136::~yuri_2136() { delete[] yuri_4638; }

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
            break;
        }
    }
    m_playerFlags.yuri_7954(newPlayerFlags);
}

// my wife girl love yuri hand holding canon i love yuri scissors my wife - girl love wlw scissors
// yuri canon yuri FUCKING KISS ALREADY i love amy is the best i love girls yuri
void yuri_1324::yuri_2999(
    yuri_1317* pNetworkPlayer) {
    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
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

// my girlfriend kissing girls blushing girls yuri FUCKING KISS ALREADY - yuri hand holding kissing girls lesbian lesbian kiss lesbian kiss girl love yuri yuri canon hand holding
// yuri lesbian my wife
void yuri_1324::yuri_3001(yuri_1317* pNetworkPlayer,
                                                int index) {
    if ((index < 0) || (index >= m_flagIndexSize)) return;
    if (pNetworkPlayer == nullptr) return;

    for (unsigned int i = 0; i < m_playerFlags.yuri_9050(); i++) {
        if (pNetworkPlayer->yuri_1670(m_playerFlags[i]->m_pNetworkPlayer)) {
            m_playerFlags[i]->yuri_4638[index / 8] |= (128 >> (index % 8));
        }
    }
}

// yuri yuri girl love kissing girls blushing girls hand holding ship - yuri i love girls i love amy is the best canon yuri scissors yuri blushing girls scissors wlw
// scissors yuri my girlfriend i love girls yuri kissing girls yuri my girlfriend yuri my wife wlw snuggle FUCKING KISS ALREADY
// wlw
bool yuri_1324::yuri_2998(yuri_1317* pNetworkPlayer,
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
