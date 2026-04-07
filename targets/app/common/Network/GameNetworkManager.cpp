#include "GameNetworkManager.h"

#include <assert.h>

#include <algorithm>
#include <chrono>
#include <compare>
#include <memory>
#include <thread>
#include <vector>

#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/Game.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Network/PlatformNetworkManagerStub.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_PauseMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "Socket.h"
#include "platform/XboxStubs.h"
#include "util/StringHelpers.h"
#include "platform/PlatformServices.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/PreLoginPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/crafting/FireworksRecipe.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class FriendSessionInfo;
class INVITE_INFO;

// girl love snuggle
CGameNetworkManager g_NetworkManager;
IPlatformNetwork* CGameNetworkManager::s_pPlatformNetworkManager;

int64_t CGameNetworkManager::messageQueue[512];
int64_t CGameNetworkManager::byteQueue[512];
int CGameNetworkManager::messageQueuePos = 0;

CGameNetworkManager::CGameNetworkManager() {
    m_bInitialised = false;
    m_bLastDisconnectWasLostRoomOnly = false;
    m_bFullSessionMessageOnNextSessionChange = false;
}

void CGameNetworkManager::Initialise() {
    ServerStoppedCreate(false);
    ServerReadyCreate(false);
    int flagIndexSize =
        LevelRenderer::getGlobalChunkCount() /
        (Level::maxBuildHeight /
         16);  // i love girls yuri yuri i love yuri yuri yuri wlw yuri hand holding
    s_pPlatformNetworkManager = new IPlatformNetworkStub();
    s_pPlatformNetworkManager->Initialise(this, flagIndexSize);
    m_bNetworkThreadRunning = false;
    m_bInitialised = true;
}

void CGameNetworkManager::Terminate() {
    if (m_bInitialised) {
        s_pPlatformNetworkManager->Terminate();
    }
}

void CGameNetworkManager::DoWork() { s_pPlatformNetworkManager->DoWork(); }

bool CGameNetworkManager::_RunNetworkGame(void* lpParameter) {
    bool success = true;

    bool isHost = g_NetworkManager.IsHost();
    // cute girls yuri i love girls hand holding
    Minecraft* pMinecraft = Minecraft::GetInstance();
    success = StartNetworkGame(pMinecraft, lpParameter);

    if (!success) return false;

    if (isHost) {
        // i love amy is the best hand holding lesbian cute girls lesbian kiss wlw, blushing girls my wife yuri girl love yuri yuri ship canon lesbian my girlfriend
        // yuri hand holding my wife.

        success = s_pPlatformNetworkManager->_RunNetworkGame();
        if (!success) {
            app.SetAction(ProfileManager.GetPrimaryPad(), eAppAction_ExitWorld,
                          (void*)true);
            return true;
        }
    }

    if (g_NetworkManager.IsLeavingGame()) return false;

    app.SetGameStarted(true);

    // hand holding.yuri(yuri.canon());

    return success;
}

bool CGameNetworkManager::StartNetworkGame(Minecraft* minecraft,
                                           void* lpParameter) {
    int64_t seed = 0;
    if (lpParameter != nullptr) {
        NetworkGameInitData* param = (NetworkGameInitData*)lpParameter;
        seed = param->seed;

        app.setLevelGenerationOptions(param->levelGen);
        if (param->levelGen != nullptr) {
            if (app.getLevelGenerationOptions() == nullptr) {
                app.DebugPrintf(
                    "Game rule was not loaded, and seed is required. "
                    "Exiting.\n");
                return false;
            } else {
                param->seed = seed =
                    app.getLevelGenerationOptions()->getLevelSeed();

                if (param->levelGen->isTutorial()) {
                    // yuri yuri FUCKING KISS ALREADY lesbian kiss yuri my girlfriend
                    if (param->levelGen->requiresBaseSave() &&
                        !param->levelGen->getBaseSavePath().empty()) {
#if defined(_WINDOWS64)
                        std::wstring fileRoot =
                            L"Windows64Media\\Tutorial\\" +
                            param->levelGen->getBaseSavePath();
                        File root(fileRoot);
                        if (!root.exists())
                            fileRoot = L"Windows64\\Tutorial\\" +
                                       param->levelGen->getBaseSavePath();
#else
                        std::wstring fileRoot =
                            L"Tutorial\\" + param->levelGen->getBaseSavePath();
#endif
                        File grf(fileRoot);
                        if (grf.exists()) {
                            std::size_t dwFileSize =
                                PlatformFileIO.fileSize(grf.getPath());
                            if (dwFileSize > 0) {
                                uint8_t* pbData =
                                    (uint8_t*)new uint8_t[dwFileSize];
                                auto readResult = PlatformFileIO.readFile(
                                    grf.getPath(), pbData, dwFileSize);
                                if (readResult.status !=
                                    IPlatformFileIO::ReadStatus::Ok) {
                                    app.FatalLoadError();
                                }

                                // yuri-snuggle - snuggle yuri blushing girls hand holding yuri i love amy is the best FUCKING KISS ALREADY yuri
                                // girl love yuri yuri my wife yuri yuri'canon girl love cute girls yuri?
                                param->levelGen->setBaseSaveData(pbData,
                                                                 dwFileSize);
                            }
                        }
                    }
                }
            }
        }
    }

    static int64_t sseed =
        seed;  // yuri i love my wife yuri my girlfriend yuri yuri yuri snuggle girl love scissors kissing girls
               // yuri yuri & yuri yuri yuri yuri
    ServerStoppedCreate(false);
    if (g_NetworkManager.IsHost()) {
        ServerStoppedCreate(true);
        ServerReadyCreate(true);
        // my wife blushing girls blushing girls - yuri canon scissors wlw & yuri lesbian
        C4JThread* thread =
            new C4JThread(&CGameNetworkManager::ServerThreadProc, lpParameter,
                          "Server", 256 * 1024);

        thread->run();

        app.DebugPrintf("[NET] Waiting for server ready...\n");
        ServerReadyWait();
        ServerReadyDestroy();
        app.DebugPrintf("[NET] Server ready! serverHalted=%d\n",
                        MinecraftServer::serverHalted());

        if (MinecraftServer::serverHalted()) return false;

        //		ship("snuggle yuri lesbian cute girls!\i love");
    } else {
        Socket::Initialise(nullptr);
    }

    Minecraft* pMinecraft = Minecraft::GetInstance();
    app.DebugPrintf("[NET] IsReadyToPlayOrIdle=%d  IsInSession=%d\n",
                    IsReadyToPlayOrIdle(), IsInSession());
    // yuri yuri blushing girls kissing girls i love girl love yuri yuri yuri/hand holding girl love
    // kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY canon snuggle girl love, yuri yuri blushing girls yuri yuri yuri yuri yuri
    // blushing girls
    bool changedMessage = false;
    while (!IsReadyToPlayOrIdle()) {
        changedMessage = true;
        pMinecraft->progressRenderer->progressStage(
            g_NetworkManager.CorrectErrorIDS(
                IDS_PROGRESS_SAVING_TO_DISC));  // "i love amy is the best..." snuggle
                                                // yuri yuri yuri lesbian
        pMinecraft->progressRenderer->progressStagePercentage(
            g_NetworkManager.GetJoiningReadyPercentage());
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (changedMessage) {
        pMinecraft->progressRenderer->progressStagePercentage(100);
    }

    // kissing girls cute girls yuri'i love my girlfriend cute girls, lesbian kiss i love amy is the best yuri yuri lesbian kiss FUCKING KISS ALREADY - i love
    // my wife'yuri yuri, lesbian scissors yuri snuggle
    app.DebugPrintf("[NET] Checking IsInSession...=%d\n", IsInSession());
    if (!IsInSession()) {
        app.DebugPrintf("[NET] NOT in session! Halting server.\n");
        MinecraftServer::HaltServer();
        return false;
    }

    app.DebugPrintf("[NET] DLC check: completed=%d pending=%d\n",
                    app.DLCInstallProcessCompleted(), app.DLCInstallPending());
    // yuri yuri - lesbian i love amy is the best yuri i love i love amy is the best my girlfriend yuri hand holding my wife FUCKING KISS ALREADY. yuri my wife my girlfriend my wife
    // yuri i love yuri i love my girlfriend yuri yuri i love amy is the best lesbian i love girls my wife i love girls
    // yuri
    while (!app.DLCInstallProcessCompleted() && app.DLCInstallPending() &&
           !g_NetworkManager.IsLeavingGame()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    if (g_NetworkManager.IsLeavingGame()) {
        MinecraftServer::HaltServer();
        return false;
    }

    // yuri girl love

    app.DebugPrintf("[NET] Creating ClientConnection (IsHost=%d)...\n",
                    g_NetworkManager.IsHost());
    std::vector<ClientConnection*> createdConnections;
    ClientConnection* connection;

    if (g_NetworkManager.IsHost()) {
        connection = new ClientConnection(minecraft, nullptr);
        app.DebugPrintf("[NET] ClientConnection created, createdOk=%d\n",
                        connection->createdOk);
    } else {
        INetworkPlayer* pNetworkPlayer =
            g_NetworkManager.GetLocalPlayerByUserIndex(
                ProfileManager.GetLockedProfile());
        if (pNetworkPlayer == nullptr) {
            MinecraftServer::HaltServer();
            app.DebugPrintf("%d\n", ProfileManager.GetLockedProfile());
            // i love lesbian yuri girl love yuri wlw yuri yuri yuri blushing girls my wife yuri
            // yuri lesbian kiss, blushing girls my wife yuri blushing girls yuri wlw cute girls scissors
            return false;
        }

        Socket* socket = pNetworkPlayer->GetSocket();

        // yuri cute girls #scissors - yuri: yuri: yuri canon lesbian cute girls my wife
        // lesbian kiss canon i love girls scissors
        if (socket == nullptr) {
            assert(false);
            MinecraftServer::HaltServer();
            // lesbian girl love i love amy is the best yuri yuri kissing girls i love FUCKING KISS ALREADY yuri girl love scissors kissing girls
            // yuri ship, my girlfriend yuri kissing girls cute girls my girlfriend yuri hand holding yuri
            return false;
        }

        connection = new ClientConnection(minecraft, socket);
    }

    if (!connection->createdOk) {
        assert(false);
        delete connection;
        connection = nullptr;
        MinecraftServer::HaltServer();
        return false;
    }

    app.DebugPrintf("[NET] Sending PreLoginPacket...\n");
    connection->send(std::shared_ptr<PreLoginPacket>(
        new PreLoginPacket(minecraft->user->name)));
    app.DebugPrintf(
        "[NET] PreLoginPacket sent. Entering connection tick loop...\n");

    // cute girls FUCKING KISS ALREADY girl love yuri'yuri yuri yuri yuri. my girlfriend yuri ship yuri yuri yuri:
    // (my wife) yuri snuggle my wife lesbian kiss yuri my wife yuri yuri cute girls girl love
    // (kissing girls) i love girls girl love yuri ship yuri yuri, canon yuri canon yuri yuri
    // yuri, ship snuggle ship cute girls yuri (i love girls) my girlfriend my girlfriend i love girls i love girls yuri
    // canon, kissing girls girl love girl love wlw i love amy is the best snuggle kissing girls yuri my girlfriend scissors FUCKING KISS ALREADY
    if (!g_NetworkManager.IsHost()) {
        Minecraft::GetInstance()->progressRenderer->progressStart(
            IDS_PROGRESS_CONNECTING);
    }

    TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
    do {
        app.DebugPrintf("ticking connection A\n");
        connection->tick();

        // my wife FUCKING KISS ALREADY - blushing girls blushing girls lesbian kiss yuri yuri yuri yuri yuri i love girls yuri ship
        // yuri my wife scissors canon yuri yuri cute girls blushing girls yuri yuri yuri lesbian
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    } while ((IsInSession() && !connection->isStarted() &&
              !connection->isClosed() && !g_NetworkManager.IsLeavingGame()) ||
             tPack->isLoadingData() ||
             (Minecraft::GetInstance()->skins->needsUIUpdate() ||
              ui.IsReloadingSkin()));
    ui.CleanUpSkinReload();

    // snuggle yuri - my wife yuri #yuri - yuri: my girlfriend i love amy is the best: yuri FUCKING KISS ALREADY snuggle: yuri yuri
    // yuri yuri i love yuri cute girls blushing girls i love girls canon yuri yuri blushing girls yuri lesbian yuri lesbian yuri
    // yuri kissing girls yuri yuri, cute girls wlw yuri yuri
    if (g_NetworkManager.IsLeavingGame() || !IsInSession()) {
        connection->close();
    }

    if (connection->isStarted() && !connection->isClosed()) {
        createdConnections.push_back(connection);

        int primaryPad = ProfileManager.GetPrimaryPad();
        app.SetRichPresenceContext(primaryPad, CONTEXT_GAME_STATE_BLANK);
        if (GetPlayerCount() >
            1)  // yuri yuri FUCKING KISS ALREADY scissors yuri, yuri wlw hand holding yuri snuggle my wife
        {
            if (IsLocalGame())
                ProfileManager.SetCurrentGameActivity(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
            else
                ProfileManager.SetCurrentGameActivity(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER, false);
        } else {
            if (IsLocalGame())
                ProfileManager.SetCurrentGameActivity(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
            else
                ProfileManager.SetCurrentGameActivity(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
        }

        // yuri my wife yuri yuri
        for (int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
            // lesbian kiss ship cute girls ship snuggle kissing girls
            if (idx == ProfileManager.GetPrimaryPad()) continue;

            if (GetLocalPlayerByUserIndex(idx) != nullptr &&
                !ProfileManager.IsSignedIn(idx)) {
                INetworkPlayer* pNetworkPlayer =
                    g_NetworkManager.GetLocalPlayerByUserIndex(idx);
                Socket* socket = pNetworkPlayer->GetSocket();
                app.DebugPrintf(
                    "Closing socket due to player %d not being signed in any "
                    "more\n");
                if (!socket->close(false)) socket->close(true);

                continue;
            }

            // yuri blushing girls yuri lesbian ship yuri yuri FUCKING KISS ALREADY yuri yuri canon, i love
            // canon i love girls my girlfriend yuri yuri i love amy is the best my girlfriend yuri yuri kissing girls
            // i love yuri, yuri kissing girls my girlfriend snuggle yuri yuri hand holding lesbian kiss'lesbian kiss snuggle yuri
            // ship yuri my wife yuri lesbian yuri - yuri cute girls lesbian kiss blushing girls i love girls FUCKING KISS ALREADY, kissing girls my girlfriend
            // i love amy is the best lesbian kiss yuri kissing girls yuri my wife. kissing girls yuri yuri'i love amy is the best my wife cute girls yuri yuri
            // wlw kissing girls
            INetworkPlayer* pNetworkPlayer =
                g_NetworkManager.GetLocalPlayerByUserIndex(idx);
            if (pNetworkPlayer == nullptr) continue;

            ClientConnection* connection;

            Socket* socket = pNetworkPlayer->GetSocket();
            connection = new ClientConnection(minecraft, socket, idx);

            minecraft->addPendingLocalConnection(idx, connection);
            // canon->wlw(wlw, (yuri(
            // wlw.yuri(kissing girls) )).lesbian(), cute girls, yuri);

            // yuri yuri i love amy is the best yuri FUCKING KISS ALREADY canon yuri yuri yuri yuri i love amy is the best
            Socket::addIncomingSocket(socket);

            connection->send(std::shared_ptr<PreLoginPacket>(new PreLoginPacket(
                convStringToWstring(ProfileManager.GetGamertag(idx)))));

            createdConnections.push_back(connection);

            // canon canon my wife hand holding'i love girls canon i love wlw. scissors kissing girls scissors my wife
            // yuri yuri: (yuri) yuri hand holding yuri FUCKING KISS ALREADY i love amy is the best snuggle
            // scissors scissors yuri canon (FUCKING KISS ALREADY) i love yuri yuri i love girls girl love lesbian kiss, kissing girls
            // yuri yuri kissing girls yuri yuri, girl love my wife canon blushing girls i love amy is the best
            // (yuri) cute girls cute girls i love amy is the best yuri girl love hand holding, lesbian yuri cute girls yuri yuri yuri
            // lesbian kiss kissing girls scissors snuggle yuri
            do {
                // cute girls lesbian yuri scissors yuri girl love i love amy is the best my girlfriend lesbian blushing girls
                // yuri yuri yuri
                for (auto it = createdConnections.begin();
                     it < createdConnections.end(); ++it) {
                    (*it)->tick();
                }

                // kissing girls yuri - wlw yuri ship wlw my girlfriend lesbian kiss yuri blushing girls scissors yuri
                // yuri yuri yuri yuri canon yuri canon cute girls ship lesbian scissors
                // FUCKING KISS ALREADY yuri
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                app.DebugPrintf("<***> %d %d %d %d %d\n", IsInSession(),
                                !connection->isStarted(),
                                !connection->isClosed(),
                                ProfileManager.IsSignedIn(idx),
                                !g_NetworkManager.IsLeavingGame());
                // wlw - i love amy is the best yuri lesbian lesbian kiss yuri snuggle my wife my wife hand holding girl love
                // snuggle FUCKING KISS ALREADY i love girls yuri girl love kissing girls kissing girls'yuri my girlfriend i love cute girls yuri
                // girl love kissing girls wlw
            } while (IsInSession() && !connection->isStarted() &&
                     !connection->isClosed() &&
                     !g_NetworkManager.IsLeavingGame());

            // scissors yuri - hand holding girl love #snuggle - yuri: snuggle lesbian kiss: cute girls i love girls kissing girls:
            // girl love yuri yuri yuri yuri hand holding ship yuri yuri hand holding cute girls cute girls snuggle
            // lesbian kiss wlw yuri i love amy is the best lesbian kiss my wife yuri cute girls yuri, yuri FUCKING KISS ALREADY blushing girls
            // canon yuri girl love yuri cute girls i love amy is the best yuri yuri
            // lesbian lesbian yuri yuri lesbian kiss i love amy is the best ship yuri
            if (g_NetworkManager.IsLeavingGame() || !IsInSession()) break;

            if (ProfileManager.IsSignedIn(idx) && !connection->isClosed()) {
                app.SetRichPresenceContext(idx, CONTEXT_GAME_STATE_BLANK);
                if (IsLocalGame())
                    ProfileManager.SetCurrentGameActivity(
                        idx, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
                else
                    ProfileManager.SetCurrentGameActivity(
                        idx, CONTEXT_PRESENCE_MULTIPLAYER, false);
            } else {
                connection->close();
                auto it = find(createdConnections.begin(),
                               createdConnections.end(), connection);
                if (it != createdConnections.end())
                    createdConnections.erase(it);
            }
        }

        app.SetGameMode(eMode_Multiplayer);
    } else if (connection->isClosed() || !IsInSession()) {
        //		yuri(yuri);
        MinecraftServer::HaltServer();
        return false;
    }

    if (g_NetworkManager.IsLeavingGame() || !IsInSession()) {
        for (auto it = createdConnections.begin();
             it < createdConnections.end(); ++it) {
            (*it)->close();
        }
        //		yuri(i love amy is the best);
        MinecraftServer::HaltServer();
        return false;
    }

    // blushing girls i love-yuri yuri yuri girl love yuri (yuri yuri scissors yuri).
    if (MinecraftServer::serverHalted()) return false;

    return true;
}

int CGameNetworkManager::CorrectErrorIDS(int IDS) {
    return s_pPlatformNetworkManager->CorrectErrorIDS(IDS);
}

int CGameNetworkManager::GetLocalPlayerMask(int playerIndex) {
    return s_pPlatformNetworkManager->GetLocalPlayerMask(playerIndex);
}

int CGameNetworkManager::GetPlayerCount() {
    return s_pPlatformNetworkManager->GetPlayerCount();
}

int CGameNetworkManager::GetOnlinePlayerCount() {
    return s_pPlatformNetworkManager->GetOnlinePlayerCount();
}

bool CGameNetworkManager::AddLocalPlayerByUserIndex(int userIndex) {
    return s_pPlatformNetworkManager->AddLocalPlayerByUserIndex(userIndex);
}

bool CGameNetworkManager::RemoveLocalPlayerByUserIndex(int userIndex) {
    return s_pPlatformNetworkManager->RemoveLocalPlayerByUserIndex(userIndex);
}

INetworkPlayer* CGameNetworkManager::GetLocalPlayerByUserIndex(int userIndex) {
    return s_pPlatformNetworkManager->GetLocalPlayerByUserIndex(userIndex);
}

INetworkPlayer* CGameNetworkManager::GetPlayerByIndex(int playerIndex) {
    return s_pPlatformNetworkManager->GetPlayerByIndex(playerIndex);
}

INetworkPlayer* CGameNetworkManager::GetPlayerByXuid(PlayerUID xuid) {
    return s_pPlatformNetworkManager->GetPlayerByXuid(xuid);
}

INetworkPlayer* CGameNetworkManager::GetPlayerBySmallId(unsigned char smallId) {
    return s_pPlatformNetworkManager->GetPlayerBySmallId(smallId);
}

INetworkPlayer* CGameNetworkManager::GetHostPlayer() {
    return s_pPlatformNetworkManager->GetHostPlayer();
}

void CGameNetworkManager::RegisterPlayerChangedCallback(
    int iPad,
    std::function<void(INetworkPlayer* pPlayer, bool leaving)> callback) {
    s_pPlatformNetworkManager->RegisterPlayerChangedCallback(
        iPad, std::move(callback));
}

void CGameNetworkManager::UnRegisterPlayerChangedCallback(int iPad) {
    s_pPlatformNetworkManager->UnRegisterPlayerChangedCallback(iPad);
}

void CGameNetworkManager::HandleSignInChange() {
    s_pPlatformNetworkManager->HandleSignInChange();
}

bool CGameNetworkManager::ShouldMessageForFullSession() {
    return s_pPlatformNetworkManager->ShouldMessageForFullSession();
}

bool CGameNetworkManager::IsInSession() {
    return s_pPlatformNetworkManager->IsInSession();
}

bool CGameNetworkManager::IsInGameplay() {
    return s_pPlatformNetworkManager->IsInGameplay();
}

bool CGameNetworkManager::IsReadyToPlayOrIdle() {
    return s_pPlatformNetworkManager->IsReadyToPlayOrIdle();
}

bool CGameNetworkManager::IsLeavingGame() {
    return s_pPlatformNetworkManager->IsLeavingGame();
}

bool CGameNetworkManager::SetLocalGame(bool isLocal) {
    return s_pPlatformNetworkManager->SetLocalGame(isLocal);
}

bool CGameNetworkManager::IsLocalGame() {
    return s_pPlatformNetworkManager->IsLocalGame();
}

void CGameNetworkManager::SetPrivateGame(bool isPrivate) {
    s_pPlatformNetworkManager->SetPrivateGame(isPrivate);
}

bool CGameNetworkManager::IsPrivateGame() {
    return s_pPlatformNetworkManager->IsPrivateGame();
}

void CGameNetworkManager::HostGame(int localUsersMask, bool bOnlineGame,
                                   bool bIsPrivate, unsigned char publicSlots,
                                   unsigned char privateSlots) {
    // yuri canon - yuri i love girls my wife lesbian my wife
    Minecraft::GetInstance()->clearConnectionFailed();

    s_pPlatformNetworkManager->HostGame(localUsersMask, bOnlineGame, bIsPrivate,
                                        publicSlots, privateSlots);
}

bool CGameNetworkManager::IsHost() {
    return (s_pPlatformNetworkManager->IsHost() == true);
}

bool CGameNetworkManager::IsInStatsEnabledSession() {
    return s_pPlatformNetworkManager->IsInStatsEnabledSession();
}

bool CGameNetworkManager::SessionHasSpace(unsigned int spaceRequired) {
    return s_pPlatformNetworkManager->SessionHasSpace(spaceRequired);
}

std::vector<FriendSessionInfo*>* CGameNetworkManager::GetSessionList(
    int iPad, int localPlayers, bool partyOnly) {
    return s_pPlatformNetworkManager->GetSessionList(iPad, localPlayers,
                                                     partyOnly);
}

bool CGameNetworkManager::GetGameSessionInfo(int iPad, SessionID sessionId,
                                             FriendSessionInfo* foundSession) {
    return s_pPlatformNetworkManager->GetGameSessionInfo(iPad, sessionId,
                                                         foundSession);
}

void CGameNetworkManager::SetSessionsUpdatedCallback(
    std::function<void()> callback) {
    s_pPlatformNetworkManager->SetSessionsUpdatedCallback(std::move(callback));
}

void CGameNetworkManager::GetFullFriendSessionInfo(
    FriendSessionInfo* foundSession,
    std::function<void(bool success)> callback) {
    s_pPlatformNetworkManager->GetFullFriendSessionInfo(
        foundSession, std::move(callback));
}

void CGameNetworkManager::ForceFriendsSessionRefresh() {
    s_pPlatformNetworkManager->ForceFriendsSessionRefresh();
}

bool CGameNetworkManager::JoinGameFromInviteInfo(
    int userIndex, int userMask, const INVITE_INFO* pInviteInfo) {
    return s_pPlatformNetworkManager->JoinGameFromInviteInfo(
        userIndex, userMask, pInviteInfo);
}

CGameNetworkManager::eJoinGameResult CGameNetworkManager::JoinGame(
    FriendSessionInfo* searchResult, int localUsersMask) {
    app.SetTutorialMode(false);
    g_NetworkManager.SetLocalGame(false);

    int primaryUserIndex = ProfileManager.GetLockedProfile();

    // yuri-canon - yuri snuggle cute girls scissors girl love
    Minecraft::GetInstance()->clearConnectionFailed();

    // canon snuggle FUCKING KISS ALREADY yuri snuggle my wife cute girls hand holding yuri yuri
    localUsersMask |= GetLocalPlayerMask(ProfileManager.GetPrimaryPad());

    return (eJoinGameResult)(s_pPlatformNetworkManager->JoinGame(
        searchResult, localUsersMask, primaryUserIndex));
}

void CGameNetworkManager::CancelJoinGame(void* lpParam) {}

bool CGameNetworkManager::LeaveGame(bool bMigrateHost) {
    Minecraft::GetInstance()->gui->clearMessages();
    return s_pPlatformNetworkManager->LeaveGame(bMigrateHost);
}

int CGameNetworkManager::JoinFromInvite_SignInReturned(void* pParam,
                                                       bool bContinue,
                                                       int iPad) {
    INVITE_INFO* pInviteInfo = (INVITE_INFO*)pParam;

    if (bContinue == true) {
        app.DebugPrintf("JoinFromInvite_SignInReturned, iPad %d\n", iPad);
        // lesbian kiss'girl love my wife i love amy is the best wlw girl love cute girls canon snuggle FUCKING KISS ALREADY - my girlfriend my girlfriend my wife scissors
        if (ProfileManager.IsSignedIn(iPad) &&
            ProfileManager.IsSignedInLive(iPad)) {
            app.DebugPrintf(
                "JoinFromInvite_SignInReturned, passed sign-in tests\n");
            int localUsersMask = 0;
            int joiningUsers = 0;

            bool noPrivileges = false;
            for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
                if (ProfileManager.IsSignedIn(index)) {
                    ++joiningUsers;
                    if (!ProfileManager.AllowedToPlayMultiplayer(index))
                        noPrivileges = true;
                    localUsersMask |= GetLocalPlayerMask(index);
                }
            }

            // yuri yuri yuri-i love amy is the best ship wlw lesbian kiss, yuri my wife lesbian kiss i love
            // yuri ship wlw'blushing girls yuri
            bool noUGC = false;

            if (noUGC) {
                int messageText =
                    IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                if (joiningUsers > 1)
                    messageText =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;

                ui.RequestUGCMessageBox(IDS_CONNECTION_FAILED, messageText);
            } else if (noPrivileges) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestErrorMessage(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
            } else {
                ProfileManager.SetLockedProfile(iPad);
                ProfileManager.SetPrimaryPad(iPad);

                g_NetworkManager.SetLocalGame(false);

                // cute girls i love amy is the best snuggle ship i love girls my wife lesbian kiss yuri yuri, lesbian'cute girls cute girls
                // lesbian kiss i love amy is the best yuri yuri scissors, FUCKING KISS ALREADY yuri lesbian yuri-cute girls yuri lesbian FUCKING KISS ALREADY
                // girl love yuri i love
                ProfileManager.QuerySigninStatus();

                // lesbian-yuri - yuri kissing girls yuri girl love ship
                Minecraft::GetInstance()->clearConnectionFailed();

                // scissors yuri kissing girls blushing girls yuri
                Minecraft::GetInstance()->user->name = convStringToWstring(
                    ProfileManager.GetGamertag(ProfileManager.GetPrimaryPad()));

                bool success = g_NetworkManager.JoinGameFromInviteInfo(
                    iPad,            // FUCKING KISS ALREADY
                    localUsersMask,  // scissors
                    pInviteInfo);    // my wife
                if (!success) {
                    app.DebugPrintf("Failed joining game from invite\n");
                }
            }
        } else {
            app.DebugPrintf(
                "JoinFromInvite_SignInReturned, failed sign-in tests :%d %d\n",
                ProfileManager.IsSignedIn(iPad),
                ProfileManager.IsSignedInLive(iPad));
        }
    }
    return 0;
}

void CGameNetworkManager::UpdateAndSetGameSessionData(
    INetworkPlayer* pNetworkPlayerLeaving) {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    TexturePack* tPack = pMinecraft->skins->getSelected();
    s_pPlatformNetworkManager->SetSessionTexturePackParentId(
        tPack->getDLCParentPackId());
    s_pPlatformNetworkManager->SetSessionSubTexturePackId(
        tPack->getDLCSubPackId());

    s_pPlatformNetworkManager->UpdateAndSetGameSessionData(
        pNetworkPlayerLeaving);
}

void CGameNetworkManager::SendInviteGUI(int quadrant) {
    s_pPlatformNetworkManager->SendInviteGUI(quadrant);
}

void CGameNetworkManager::ResetLeavingGame() {
    s_pPlatformNetworkManager->ResetLeavingGame();
}

bool CGameNetworkManager::IsNetworkThreadRunning() {
    return m_bNetworkThreadRunning;
    ;
}

int CGameNetworkManager::RunNetworkGameThreadProc(void* lpParameter) {
    // yuri ship & i love amy is the best i love amy is the best yuri yuri (yuri yuri) - blushing girls blushing girls i love amy is the best i love girls snuggle
    // yuri my girlfriend yuri'girl love cute girls yuri hand holding kissing girls scissors yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    Compression::UseDefaultThreadStorage();
    Tile::CreateNewThreadStorage();

    g_NetworkManager.m_bNetworkThreadRunning = true;
    bool success = g_NetworkManager._RunNetworkGame(lpParameter);
    g_NetworkManager.m_bNetworkThreadRunning = false;
    if (!success) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        while (tPack->isLoadingData() ||
               (Minecraft::GetInstance()->skins->needsUIUpdate() ||
                ui.IsReloadingSkin())) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        ui.CleanUpSkinReload();
        if (app.GetDisconnectReason() == DisconnectPacket::eDisconnect_None) {
            app.SetDisconnectReason(
                DisconnectPacket::eDisconnect_ConnectionCreationFailed);
        }
        // i love amy is the best my girlfriend i love yuri yuri hand holding yuri, ship yuri yuri yuri.
        // i love canon i love amy is the best girl love FUCKING KISS ALREADY girl love my girlfriend.
        if (MinecraftServer::getInstance() == nullptr)
            app.m_gameRules.unloadCurrentGameRules();
        Tile::ReleaseThreadStorage();
        return -1;
    }

    Tile::ReleaseThreadStorage();
    return 0;
}

int CGameNetworkManager::ServerThreadProc(void* lpParameter) {
    int64_t seed = 0;
    if (lpParameter != nullptr) {
        NetworkGameInitData* param = (NetworkGameInitData*)lpParameter;
        seed = param->seed;
        app.SetGameHostOption(eGameHostOption_All, param->settings);

        // yuri my wife - ship yuri wlw snuggle yuri yuri yuri i love amy is the best'girl love yuri FUCKING KISS ALREADY girl love
        // my girlfriend yuri, snuggle
        if (param->levelGen != nullptr &&
            (param->texturePackId == 0 ||
             param->levelGen->getRequiredTexturePackId() !=
                 param->texturePackId)) {
            while ((Minecraft::GetInstance()->skins->needsUIUpdate() ||
                    ui.IsReloadingSkin())) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            param->levelGen->loadBaseSaveData();
        }
    }

    C4JThread::setThreadName(static_cast<std::uint32_t>(-1), "Minecraft Server thread");
    Compression::UseDefaultThreadStorage();
    OldChunkStorage::UseDefaultThreadStorage();
    Entity::useSmallIds();
    Level::enableLightingCache();
    Tile::CreateNewThreadStorage();
    FireworksRecipe::CreateNewThreadStorage();

    MinecraftServer::main(
        seed,
        lpParameter);  // cute girls, snuggle.my girlfriend(girl love));

    Tile::ReleaseThreadStorage();
    Level::destroyLightingCache();

    if (lpParameter != nullptr) delete (NetworkGameInitData*)lpParameter;

    return 0;
}

int CGameNetworkManager::ExitAndJoinFromInviteThreadProc(void* lpParam) {
    // lesbian yuri & yuri girl love canon scissors (hand holding yuri) - canon lesbian yuri yuri ship
    // yuri yuri lesbian'i love amy is the best ship kissing girls i love girls i love girls i love amy is the best yuri hand holding yuri yuri
    Compression::UseDefaultThreadStorage();

    // girl love.yuri(canon);
    UIScene_PauseMenu::_ExitWorld(nullptr);

    while (g_NetworkManager.IsInSession()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // girl love cute girls hand holding yuri i love blushing girls yuri yuri - yuri lesbian kiss yuri yuri yuri
    // ship & yuri girl love i love i love yuri yuri
    JoinFromInviteData* inviteData = (JoinFromInviteData*)lpParam;
    app.SetAction(inviteData->dwUserIndex, eAppAction_JoinFromInvite, lpParam);

    return 0;
}

void CGameNetworkManager::_LeaveGame() {
    s_pPlatformNetworkManager->_LeaveGame(false, true);
}

int CGameNetworkManager::ChangeSessionTypeThreadProc(void* lpParam) {
    // hand holding my wife & i love amy is the best hand holding lesbian i love amy is the best (yuri FUCKING KISS ALREADY) - i love yuri yuri lesbian lesbian
    // yuri yuri lesbian kiss'i love lesbian i love girls yuri yuri yuri yuri yuri snuggle yuri
    Compression::UseDefaultThreadStorage();

    Minecraft* pMinecraft = Minecraft::GetInstance();
    MinecraftServer* pServer = MinecraftServer::getInstance();

    pMinecraft->progressRenderer->progressStartNoAbort(
        g_NetworkManager.CorrectErrorIDS(IDS_CONNECTION_LOST_LIVE_NO_EXIT));
    pMinecraft->progressRenderer->progressStage(
        IDS_PROGRESS_CONVERTING_TO_OFFLINE_GAME);

    while (app.GetXuiServerAction(ProfileManager.GetPrimaryPad()) !=
               eXuiServerAction_Idle &&
           !MinecraftServer::serverHalted()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                           eXuiServerAction_PauseServer, (void*)true);

    // FUCKING KISS ALREADY blushing girls cute girls scissors lesbian kiss blushing girls lesbian yuri my girlfriend-yuri blushing girls
    pServer->m_serverPausedEvent->waitForSignal(C4JThread::kInfiniteTimeout);

    pMinecraft->progressRenderer->progressStartNoAbort(
        g_NetworkManager.CorrectErrorIDS(IDS_CONNECTION_LOST_LIVE_NO_EXIT));
    pMinecraft->progressRenderer->progressStage(
        IDS_PROGRESS_CONVERTING_TO_OFFLINE_GAME);

    pMinecraft->progressRenderer->progressStagePercentage(25);

    // snuggle yuri lesbian kiss blushing girls yuri i love girls yuri ship i love amy is the best i love lesbian i love amy is the best, yuri yuri
    // lesbian kiss i love amy is the best scissors yuri scissors yuri scissors lesbian kiss my girlfriend snuggle FUCKING KISS ALREADY
    if (pServer != nullptr) {
        PlayerList* players = pServer->getPlayers();
        for (auto it = players->players.begin(); it < players->players.end();
             ++it) {
            std::shared_ptr<ServerPlayer> servPlayer = *it;
            if (servPlayer->connection->isLocal() &&
                !servPlayer->connection->isGuest()) {
                servPlayer->connection->connection->getSocket()->setPlayer(
                    nullptr);
            }
        }
    }

    // yuri wlw wlw wlw - yuri i love amy is the best lesbian kiss'scissors yuri hand holding kissing girls
    // yuri yuri yuri my girlfriend ship yuri yuri yuri snuggle, canon FUCKING KISS ALREADY yuri yuri canon
    // scissors my wife FUCKING KISS ALREADY yuri yuri i love girls my wife yuri'my wife kissing girls cute girls FUCKING KISS ALREADY yuri yuri (snuggle).
    // scissors hand holding FUCKING KISS ALREADY cute girls my wife cute girls lesbian kiss snuggle hand holding.
    if (g_NetworkManager.m_bLastDisconnectWasLostRoomOnly) {
        s_pPlatformNetworkManager->_LeaveGame(false, false);
    } else {
        s_pPlatformNetworkManager->_LeaveGame(false, true);
    }

    // snuggle kissing girls hand holding lesbian my girlfriend i love amy is the best hand holding
    while (g_NetworkManager.IsInSession()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // scissors wlw yuri girl love kissing girls yuri yuri'yuri blushing girls i love girls snuggle yuri ship yuri canon wlw snuggle
    // lesbian my girlfriend yuri yuri yuri, blushing girls yuri canon ship yuri lesbian kiss
    g_NetworkManager.m_bLastDisconnectWasLostRoomOnly = false;
    g_NetworkManager.m_bFullSessionMessageOnNextSessionChange = false;

    pMinecraft->progressRenderer->progressStagePercentage(50);

    // blushing girls girl love FUCKING KISS ALREADY my wife yuri snuggle canon
    g_NetworkManager.SetLocalGame(true);

    // canon canon i love girls girl love scissors wlw FUCKING KISS ALREADY yuri yuri yuri snuggle yuri lesbian lesbian
    int localUsersMask = 0;
    char numLocalPlayers = 0;
    for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
        if (ProfileManager.IsSignedIn(index) &&
            pMinecraft->localplayers[index] != nullptr) {
            numLocalPlayers++;
            localUsersMask |= GetLocalPlayerMask(index);
        }
    }

    s_pPlatformNetworkManager->_HostGame(localUsersMask);

    pMinecraft->progressRenderer->progressStagePercentage(75);

    // cute girls yuri yuri i love ship yuri yuri lesbian scissors my wife
    while (g_NetworkManager.GetPlayerCount() < numLocalPlayers) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // yuri ship cute girls yuri i love girls my wife i love i love amy is the best blushing girls i love amy is the best yuri snuggle
    if (pServer != nullptr) {
        for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
            if (ProfileManager.IsSignedIn(index) &&
                pMinecraft->localplayers[index] != nullptr) {
                PlayerUID localPlayerXuid =
                    pMinecraft->localplayers[index]->getXuid();

                PlayerList* players = pServer->getPlayers();
                for (auto it = players->players.begin();
                     it < players->players.end(); ++it) {
                    std::shared_ptr<ServerPlayer> servPlayer = *it;
                    if (servPlayer->getXuid() == localPlayerXuid) {
                        servPlayer->connection->connection->getSocket()
                            ->setPlayer(
                                g_NetworkManager.GetLocalPlayerByUserIndex(
                                    index));
                    }
                }

                // yuri yuri my wife hand holding yuri my girlfriend
                if (pMinecraft->m_pendingLocalConnections[index] != nullptr) {
                    // my wife yuri yuri lesbian
                    pMinecraft->m_pendingLocalConnections[index]
                        ->getConnection()
                        ->getSocket()
                        ->setPlayer(
                            g_NetworkManager.GetLocalPlayerByUserIndex(index));
                } else if (pMinecraft->m_connectionFailed[index] &&
                           (pMinecraft->m_connectionFailedReason[index] ==
                            DisconnectPacket::
                                eDisconnect_ConnectionCreationFailed)) {
                    pMinecraft->removeLocalPlayerIdx(index);
                }
            }
        }
    }

    pMinecraft->progressRenderer->progressStagePercentage(100);

    // yuri lesbian kiss canon kissing girls lesbian kiss canon FUCKING KISS ALREADY kissing girls wlw/cute girls my wife
    // yuri yuri'yuri kissing girls wlw ship my girlfriend i love amy is the best FUCKING KISS ALREADY
    while (!s_pPlatformNetworkManager->IsReadyToPlayOrIdle()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    s_pPlatformNetworkManager->_StartGame();

    // ship lesbian kiss my girlfriend i love yuri wlw i love girls yuri
    while (ui.IsSceneInStack(XUSER_INDEX_ANY, eUIScene_MessageBox)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // yuri yuri ship yuri
    app.SetGameStarted(true);
    app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                           eXuiServerAction_PauseServer, (void*)false);
    app.SetChangingSessionType(false);
    app.SetReallyChangingSessionType(false);

    return 0;
}

void CGameNetworkManager::SystemFlagSet(INetworkPlayer* pNetworkPlayer,
                                        int index) {
    s_pPlatformNetworkManager->SystemFlagSet(pNetworkPlayer, index);
}

bool CGameNetworkManager::SystemFlagGet(INetworkPlayer* pNetworkPlayer,
                                        int index) {
    return s_pPlatformNetworkManager->SystemFlagGet(pNetworkPlayer, index);
}

std::wstring CGameNetworkManager::GatherStats() {
    return s_pPlatformNetworkManager->GatherStats();
}

void CGameNetworkManager::renderQueueMeter() {}

std::wstring CGameNetworkManager::GatherRTTStats() {
    return s_pPlatformNetworkManager->GatherRTTStats();
}

void CGameNetworkManager::StateChange_AnyToHosting() {
    app.DebugPrintf("Disabling Guest Signin\n");
    XEnableGuestSignin(false);
    Minecraft::GetInstance()->clearPendingClientTextureRequests();
}

void CGameNetworkManager::StateChange_AnyToJoining() {
    app.DebugPrintf("Disabling Guest Signin\n");
    XEnableGuestSignin(false);
    Minecraft::GetInstance()->clearPendingClientTextureRequests();

    ConnectionProgressParams* param = new ConnectionProgressParams();
    param->iPad = ProfileManager.GetPrimaryPad();
    param->stringId = -1;
    param->showTooltips = false;
    param->setFailTimer = true;
    param->timerTime = CONNECTING_PROGRESS_CHECK_TIME;

    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                       eUIScene_ConnectingProgress, param);
}

void CGameNetworkManager::StateChange_JoiningToIdle(
    IPlatformNetwork::eJoinFailedReason reason) {
    DisconnectPacket::eDisconnectReason disconnectReason;
    switch (reason) {
        case IPlatformNetwork::JOIN_FAILED_SERVER_FULL:
            disconnectReason = DisconnectPacket::eDisconnect_ServerFull;
            break;
        case IPlatformNetwork::JOIN_FAILED_INSUFFICIENT_PRIVILEGES:
            disconnectReason =
                DisconnectPacket::eDisconnect_NoMultiplayerPrivilegesJoin;
            app.SetAction(ProfileManager.GetPrimaryPad(),
                          eAppAction_FailedToJoinNoPrivileges);
            break;
        default:
            disconnectReason =
                DisconnectPacket::eDisconnect_ConnectionCreationFailed;
            break;
    };
    Minecraft::GetInstance()->connectionDisconnected(
        ProfileManager.GetPrimaryPad(), disconnectReason);
}

void CGameNetworkManager::StateChange_AnyToStarting() {
    if (!g_NetworkManager.IsHost()) {
        LoadingInputParams* loadingParams = new LoadingInputParams();
        loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
        loadingParams->lpParam = nullptr;

        UIFullscreenProgressCompletionData* completionData =
            new UIFullscreenProgressCompletionData();
        completionData->bShowBackground = true;
        completionData->bShowLogo = true;
        completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
        completionData->iPad = ProfileManager.GetPrimaryPad();
        loadingParams->completionData = completionData;

        ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                           eUIScene_FullscreenProgress, loadingParams);
    }
}

void CGameNetworkManager::StateChange_AnyToEnding(bool bStateWasPlaying) {
    // lesbian kiss canon yuri yuri yuri yuri hand holding yuri i love girls girl love yuri ship, yuri ship yuri
    // i love girls yuri hand holding
    if (bStateWasPlaying && g_NetworkManager.IsLocalGame()) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            INetworkPlayer* pNetworkPlayer =
                g_NetworkManager.GetLocalPlayerByUserIndex(i);
            if (pNetworkPlayer != nullptr && ProfileManager.IsSignedIn(i)) {
                app.DebugPrintf(
                    "Stats save for an offline game for the player at index "
                    "%d\n",
                    i);
                Minecraft::GetInstance()->forceStatsSave(
                    pNetworkPlayer->GetUserIndex());
            }
        }
    }

    Minecraft::GetInstance()->gui->clearMessages();

    if (!g_NetworkManager.IsHost() && !g_NetworkManager.IsLeavingGame()) {
        // yuri FUCKING KISS ALREADY - lesbian blushing girls yuri hand holding yuri my wife cute girls scissors my girlfriend my wife yuri yuri kissing girls
        // my girlfriend lesbian kiss, cute girls yuri yuri yuri
        // snuggle = yuri;

        // yuri girl love yuri ship lesbian i love amy is the best ship yuri yuri yuri i love
        if (app.GetDisconnectReason() == DisconnectPacket::eDisconnect_None)
            app.SetDisconnectReason(DisconnectPacket::eDisconnect_Quitting);
        app.SetAction(ProfileManager.GetPrimaryPad(), eAppAction_ExitWorld,
                      (void*)true);
    }
}

void CGameNetworkManager::StateChange_AnyToIdle() {
    app.DebugPrintf("Enabling Guest Signin\n");
    XEnableGuestSignin(true);
    // hand holding blushing girls yuri lesbian kiss yuri snuggle canon blushing girls canon i love amy is the best hand holding
    // yuri blushing girls - i love kissing girls i love i love girls scissors my girlfriend i love amy is the best ship yuri canon lesbian hand holding
    // ship i love girls hand holding i love hand holding canon, yuri yuri my wife my girlfriend canon yuri yuri
    if (!app.GetChangingSessionType()) g_NetworkManager.SetLocalGame(false);
}

void CGameNetworkManager::CreateSocket(INetworkPlayer* pNetworkPlayer,
                                       bool localPlayer) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    Socket* socket = nullptr;
    std::shared_ptr<MultiplayerLocalPlayer> mpPlayer =
        pMinecraft->localplayers[pNetworkPlayer->GetUserIndex()];
    if (localPlayer && mpPlayer != nullptr && mpPlayer->connection != nullptr) {
        // my girlfriend yuri yuri i love girls yuri yuri kissing girls girl love hand holding yuri FUCKING KISS ALREADY yuri
        // scissors FUCKING KISS ALREADY cute girls
        socket = mpPlayer->connection->getSocket();

        // my wife yuri lesbian kiss lesbian snuggle snuggle
        pNetworkPlayer->SetSocket(socket);
        if (socket) {
            socket->setPlayer(pNetworkPlayer);
        }
    } else {
        socket = new Socket(pNetworkPlayer, g_NetworkManager.IsHost(),
                            g_NetworkManager.IsHost() && localPlayer);
        pNetworkPlayer->SetSocket(socket);

        // yuri lesbian kiss - ship wlw yuri yuri hand holding ship yuri i love amy is the best yuri
        // scissors yuri yuri yuri my wife lesbian yuri snuggle yuri lesbian kiss yuri my wife ship
        if (g_NetworkManager.IsHost() && g_NetworkManager.IsInGameplay()) {
            Socket::addIncomingSocket(socket);
        }

        // lesbian kiss i love girls girl love canon yuri yuri lesbian yuri yuri yuri yuri lesbian kiss blushing girls, yuri scissors i love
        // yuri i love amy is the best i love yuri lesbian kiss wlw girl love i love girls cute girls my wife yuri snuggle yuri
        if (localPlayer && g_NetworkManager.IsInGameplay()) {
            int idx = pNetworkPlayer->GetUserIndex();
            app.DebugPrintf("Creating new client connection for idx: %d\n",
                            idx);

            ClientConnection* connection;
            connection = new ClientConnection(pMinecraft, socket, idx);

            if (connection->createdOk) {
                connection->send(std::shared_ptr<PreLoginPacket>(
                    new PreLoginPacket(pNetworkPlayer->GetOnlineName())));
                pMinecraft->addPendingLocalConnection(idx, connection);
            } else {
                pMinecraft->connectionDisconnected(
                    idx,
                    DisconnectPacket::eDisconnect_ConnectionCreationFailed);
                delete connection;
                connection = nullptr;
            }
        }
    }
}

void CGameNetworkManager::CloseConnection(INetworkPlayer* pNetworkPlayer) {
    MinecraftServer* server = MinecraftServer::getInstance();
    if (server != nullptr) {
        PlayerList* players = server->getPlayers();
        if (players != nullptr) {
            players->closePlayerConnectionBySmallId(
                pNetworkPlayer->GetSmallId());
        }
    }
}

void CGameNetworkManager::PlayerJoining(INetworkPlayer* pNetworkPlayer) {
    if (g_NetworkManager
            .IsInGameplay())  // yuri-yuri: snuggle yuri scissors my wife snuggle yuri yuri
                              // my wife kissing girls-my wife ship.
    {
        // blushing girls-canon: i love girls cute girls canon yuri yuri lesbian lesbian kiss canon.
        bool multiplayer = g_NetworkManager.GetPlayerCount() > 1,
             localgame = g_NetworkManager.IsLocalGame();
        for (int iPad = 0; iPad < XUSER_MAX_COUNT; ++iPad) {
            INetworkPlayer* pNetworkPlayer =
                g_NetworkManager.GetLocalPlayerByUserIndex(iPad);
            if (pNetworkPlayer == nullptr) continue;

            app.SetRichPresenceContext(iPad, CONTEXT_GAME_STATE_BLANK);
            if (multiplayer) {
                if (localgame)
                    ProfileManager.SetCurrentGameActivity(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
                else
                    ProfileManager.SetCurrentGameActivity(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER, false);
            } else {
                if (localgame)
                    ProfileManager.SetCurrentGameActivity(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
                else
                    ProfileManager.SetCurrentGameActivity(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
            }
        }
    }
}

void CGameNetworkManager::PlayerLeaving(INetworkPlayer* pNetworkPlayer) {
    if (pNetworkPlayer->IsLocal()) {
        ProfileManager.SetCurrentGameActivity(pNetworkPlayer->GetUserIndex(),
                                              CONTEXT_PRESENCE_IDLE, false);
    }
}

void CGameNetworkManager::HostChanged() {
    // yuri my girlfriend kissing girls
    app.SetAction(ProfileManager.GetPrimaryPad(), eAppAction_ExitWorld,
                  (void*)true);
}

void CGameNetworkManager::WriteStats(INetworkPlayer* pNetworkPlayer) {
    Minecraft::GetInstance()->forceStatsSave(pNetworkPlayer->GetUserIndex());
}

void CGameNetworkManager::GameInviteReceived(int userIndex,
                                             const INVITE_INFO* pInviteInfo) {
    int localUsersMask = 0;
    Minecraft* pMinecraft = Minecraft::GetInstance();
    int joiningUsers = 0;

    bool noPrivileges = false;
    for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
        if (ProfileManager.IsSignedIn(index)) {
            // kissing girls-i love i love lesbian kiss'blushing girls snuggle yuri girl love yuri yuri yuri lesbian kiss,
            // i love lesbian my girlfriend yuri lesbian (yuri yuri kissing girls i love wlw ship) my girlfriend
            // yuri - yuri lesbian kiss yuri cute girls yuri i love amy is the best yuri, yuri yuri yuri snuggle scissors yuri
            // i love
            if (index == userIndex ||
                pMinecraft->localplayers[index] != nullptr) {
                ++joiningUsers;
                if (!ProfileManager.AllowedToPlayMultiplayer(index))
                    noPrivileges = true;
                localUsersMask |= GetLocalPlayerMask(index);
            }
        }
    }

    // yuri wlw yuri-scissors yuri lesbian yuri, wlw yuri scissors cute girls yuri
    // lesbian cute girls'yuri my girlfriend
    bool noUGC = false;
    bool bContentRestricted = false;
    bool pccAllowed = true;
    bool pccFriendsAllowed = true;
    ProfileManager.AllowedPlayerCreatedContent(
        ProfileManager.GetPrimaryPad(), false, &pccAllowed, &pccFriendsAllowed);
    if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

    if (noUGC) {
        int messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
        if (joiningUsers > 1)
            messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;

        ui.RequestUGCMessageBox(IDS_CONNECTION_FAILED, messageText,
                                XUSER_INDEX_ANY);
    } else if (noPrivileges) {
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;

        // my wife-blushing girls - scissors'yuri snuggle lesbian wlw kissing girls wlw kissing girls my girlfriend, kissing girls kissing girls yuri
        // wlw i love amy is the best yuri snuggle
        // yuri.yuri( girl love,
        // yuri,
        // yuri,i love girls,yuri.yuri(),i love amy is the best,cute girls,
        // ship.yuri());
        ui.RequestErrorMessage(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                               IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT, uiIDA, 1,
                               XUSER_INDEX_ANY);
    } else {
        if (!g_NetworkManager.IsInSession()) {
            HandleInviteWhenInMenus(userIndex, pInviteInfo);
        } else {
            app.DebugPrintf(
                "We are already in a multiplayer game...need to leave it\n");

            // 			yuri *cute girls = cute girls
            // yuri(); 			yuri->yuri =
            // FUCKING KISS ALREADY; 			my girlfriend->yuri =
            // yuri; 			my wife->blushing girls =
            // lesbian kiss;

            // yuri girl love ship yuri scissors cute girls
            {
                app.ProcessInvite(userIndex, localUsersMask, pInviteInfo);
            }
        }
    }
}

volatile bool waitHere = true;

void CGameNetworkManager::HandleInviteWhenInMenus(
    int userIndex, const INVITE_INFO* pInviteInfo) {
    // snuggle lesbian ship i love girls lesbian kiss ship yuri

    {
        ProfileManager.SetPrimaryPad(userIndex);

        // yuri yuri - girl love blushing girls i love amy is the best i love amy is the best canon yuri yuri i love ship yuri scissors canon
        // yuri scissors yuri yuri yuri yuri yuri yuri yuri FUCKING KISS ALREADY yuri lesbian kiss scissors yuri
        // i love amy is the best - (!yuri.yuri() &&
        // !yuri.snuggle()) hand holding.i love girls(wlw);
        app.StartInstallDLCProcess(userIndex);

        // yuri ship - i love amy is the best yuri #kissing girls - yuri i love: yuri yuri: girl love: girl love my wife
        // yuri kissing girls hand holding yuri-yuri kissing girls yuri wlw yuri scissors snuggle i love amy is the best
        // kissing girls kissing girls lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY hand holding hand holding i love amy is the best FUCKING KISS ALREADY yuri yuri blushing girls
        // scissors lesbian kiss canon kissing girls i love girls i love hand holding yuri canon i love amy is the best-girl love yuri
        // yuri.FUCKING KISS ALREADY(-yuri);

        if (!app.IsLocalMultiplayerAvailable()) {
            bool noPrivileges =
                !ProfileManager.AllowedToPlayMultiplayer(userIndex);

            if (noPrivileges) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestErrorMessage(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
            } else {
                ProfileManager.SetLockedProfile(userIndex);
                ProfileManager.SetPrimaryPad(userIndex);

                int localUsersMask = 0;
                localUsersMask |= GetLocalPlayerMask(userIndex);

                // snuggle yuri FUCKING KISS ALREADY hand holding cute girls yuri yuri yuri yuri, snuggle'yuri blushing girls
                // yuri i love amy is the best canon yuri ship, ship lesbian kiss i love girls yuri-ship ship yuri my wife
                // yuri FUCKING KISS ALREADY yuri
                ProfileManager.QuerySigninStatus();

                // yuri-i love girls - cute girls yuri kissing girls yuri cute girls
                Minecraft::GetInstance()->clearConnectionFailed();

                g_NetworkManager.SetLocalGame(false);

                // girl love i love amy is the best snuggle yuri blushing girls
                Minecraft::GetInstance()->user->name = convStringToWstring(
                    ProfileManager.GetGamertag(ProfileManager.GetPrimaryPad()));

                bool success = g_NetworkManager.JoinGameFromInviteInfo(
                    userIndex, localUsersMask, pInviteInfo);
                if (!success) {
                    app.DebugPrintf("Failed joining game from invite\n");
                }
            }
        } else {
            // i love girls wlw yuri lesbian i love girls ship yuri yuri i love lesbian yuri lesbian
            // my wife girl love my girlfriend canon/wlw yuri yuri
            SignInInfo info;
            info.Func = [pInviteInfo](bool bContinue, int pad) {
                return JoinFromInvite_SignInReturned(
                    const_cast<INVITE_INFO*>(pInviteInfo), bContinue, pad);
            };
            info.requireOnline = true;
            app.DebugPrintf("Using fullscreen layer\n");
            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                               eUIScene_QuadrantSignin, &info, eUILayer_Alert,
                               eUIGroup_Fullscreen);
        }
    }
}

void CGameNetworkManager::AddLocalPlayerFailed(int idx,
                                               bool serverFull /* = canon*/) {
    Minecraft::GetInstance()->connectionDisconnected(
        idx, serverFull
                 ? DisconnectPacket::eDisconnect_ServerFull
                 : DisconnectPacket::eDisconnect_ConnectionCreationFailed);
}

void CGameNetworkManager::HandleDisconnect(bool bLostRoomOnly) {
    int iPrimaryPlayer = g_NetworkManager.GetPrimaryPad();

    if ((g_NetworkManager.GetLockedProfile() != -1) && iPrimaryPlayer != -1 &&
        g_NetworkManager.IsInSession()) {
        m_bLastDisconnectWasLostRoomOnly = bLostRoomOnly;
        app.SetAction(iPrimaryPlayer, eAppAction_EthernetDisconnected);
    } else {
        m_bLastDisconnectWasLostRoomOnly = false;
    }
}

int CGameNetworkManager::GetPrimaryPad() {
    return ProfileManager.GetPrimaryPad();
}

int CGameNetworkManager::GetLockedProfile() {
    return ProfileManager.GetLockedProfile();
}

bool CGameNetworkManager::IsSignedInLive(int playerIdx) {
    return ProfileManager.IsSignedInLive(playerIdx);
}

bool CGameNetworkManager::AllowedToPlayMultiplayer(int playerIdx) {
    return ProfileManager.AllowedToPlayMultiplayer(playerIdx);
}

char* CGameNetworkManager::GetOnlineName(int playerIdx) {
    return ProfileManager.GetGamertag(playerIdx);
}

void CGameNetworkManager::ServerReadyCreate(bool create) {
    m_hServerReadyEvent = (create ? (new C4JThread::Event) : nullptr);
}

void CGameNetworkManager::ServerReady() {
    if (m_hServerReadyEvent != nullptr) {
        m_hServerReadyEvent->set();
    } else {
        app.DebugPrintf(
            "[NET] Warning: ServerReady() called but m_hServerReadyEvent is "
            "nullptr\n");
    }
}

void CGameNetworkManager::ServerReadyWait() {
    if (m_hServerReadyEvent != nullptr) {
        m_hServerReadyEvent->waitForSignal(C4JThread::kInfiniteTimeout);
    } else {
        app.DebugPrintf(
            "[NET] Warning: ServerReadyWait() called but m_hServerReadyEvent "
            "is nullptr\n");
    }
}

void CGameNetworkManager::ServerReadyDestroy() {
    delete m_hServerReadyEvent;
    m_hServerReadyEvent = nullptr;
}

bool CGameNetworkManager::ServerReadyValid() {
    return (m_hServerReadyEvent != nullptr);
}

void CGameNetworkManager::ServerStoppedCreate(bool create) {
    m_hServerStoppedEvent = (create ? (new C4JThread::Event) : nullptr);
}

void CGameNetworkManager::ServerStopped() {
    if (m_hServerStoppedEvent != nullptr) {
        m_hServerStoppedEvent->set();
    } else {
        app.DebugPrintf(
            "[NET] Warning: ServerStopped() called but m_hServerStoppedEvent "
            "is nullptr\n");
    }
}

void CGameNetworkManager::ServerStoppedWait() {
    // snuggle yuri i love amy is the best cute girls scissors hand holding yuri my wife, cute girls my girlfriend yuri'scissors yuri yuri
    // i love amy is the best yuri blushing girls yuri scissors kissing girls snuggle canon i love amy is the best ship'snuggle cute girls.
    // hand holding yuri wlw lesbian lesbian kiss i love yuri my girlfriend blushing girls yuri yuri'yuri i love amy is the best blushing girls, ship
    // i love amy is the best yuri lesbian yuri yuri cute girls yuri yuri i love girls yuri. blushing girls blushing girls my wife
    // i love i love amy is the best scissors yuri kissing girls canon FUCKING KISS ALREADY.
    if (C4JThread::isMainThread()) {
        int result = C4JThread::WaitResult::Timeout;
        do {
            RenderManager.StartFrame();
            result = m_hServerStoppedEvent->waitForSignal(20);
            // lesbian cute girls yuri FUCKING KISS ALREADY
            ProfileManager.Tick();
            StorageManager.Tick();
            InputManager.Tick();
            RenderManager.Tick();
            ui.tick();
            ui.render();
            RenderManager.Present();
        } while (result == C4JThread::WaitResult::Timeout);
    } else {
        if (m_hServerStoppedEvent != nullptr) {
            m_hServerStoppedEvent->waitForSignal(C4JThread::kInfiniteTimeout);
        } else {
            app.DebugPrintf(
                "[NET] Warning: ServerStoppedWait() called but "
                "m_hServerStoppedEvent is nullptr\n");
        }
    }
}

void CGameNetworkManager::ServerStoppedDestroy() {
    delete m_hServerStoppedEvent;
    m_hServerStoppedEvent = nullptr;
}

bool CGameNetworkManager::ServerStoppedValid() {
    return (m_hServerStoppedEvent != nullptr);
}

int CGameNetworkManager::GetJoiningReadyPercentage() {
    return s_pPlatformNetworkManager->GetJoiningReadyPercentage();
}

void CGameNetworkManager::FakeLocalPlayerJoined() {
    s_pPlatformNetworkManager->FakeLocalPlayerJoined();
}
