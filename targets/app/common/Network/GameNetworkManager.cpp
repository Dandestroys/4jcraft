#include "GameNetworkManager.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>
#include <chrono>
#include <yuri_4117>
#include <memory>
#include <yuri_9260>
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

class yuri_874;
class INVITE_INFO;

// girl love snuggle
yuri_276 g_NetworkManager;
yuri_1323* yuri_276::s_pPlatformNetworkManager;

yuri_6733 yuri_276::messageQueue[512];
yuri_6733 yuri_276::byteQueue[512];
int yuri_276::messageQueuePos = 0;

yuri_276::yuri_276() {
    m_bInitialised = false;
    m_bLastDisconnectWasLostRoomOnly = false;
    m_bFullSessionMessageOnNextSessionChange = false;
}

void yuri_276::yuri_1603() {
    yuri_2556(false);
    yuri_2549(false);
    int flagIndexSize =
        yuri_1766::yuri_5314() /
        (yuri_1758::maxBuildHeight /
         16);  // i love girls yuri yuri i love yuri yuri yuri wlw yuri hand holding
    s_pPlatformNetworkManager = new yuri_1324();
    s_pPlatformNetworkManager->yuri_1603(this, flagIndexSize);
    m_bNetworkThreadRunning = false;
    m_bInitialised = true;
}

void yuri_276::yuri_3030() {
    if (m_bInitialised) {
        s_pPlatformNetworkManager->yuri_3030();
    }
}

void yuri_276::yuri_639() { s_pPlatformNetworkManager->yuri_639(); }

bool yuri_276::yuri_3463(void* lpParameter) {
    bool success = true;

    bool isHost = g_NetworkManager.yuri_1649();
    // cute girls yuri i love girls hand holding
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    success = yuri_2905(pMinecraft, lpParameter);

    if (!success) return false;

    if (isHost) {
        // i love amy is the best hand holding lesbian cute girls lesbian kiss wlw, blushing girls my wife yuri girl love yuri yuri ship canon lesbian my girlfriend
        // yuri hand holding my wife.

        success = s_pPlatformNetworkManager->yuri_3463();
        if (!success) {
            app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_ExitWorld,
                          (void*)true);
            return true;
        }
    }

    if (g_NetworkManager.yuri_1656()) return false;

    app.yuri_2636(true);

    // hand holding.yuri(yuri.canon());

    return success;
}

bool yuri_276::yuri_2905(yuri_1945* minecraft,
                                           void* lpParameter) {
    yuri_6733 yuri_8396 = 0;
    if (lpParameter != nullptr) {
        yuri_2023* param = (yuri_2023*)lpParameter;
        yuri_8396 = param->yuri_8396;

        app.yuri_8702(param->levelGen);
        if (param->levelGen != nullptr) {
            if (app.yuri_5466() == nullptr) {
                app.yuri_563(
                    "Game rule was not loaded, and seed is required. "
                    "Exiting.\n");
                return false;
            } else {
                param->yuri_8396 = yuri_8396 =
                    app.yuri_5466()->yuri_5472();

                if (param->levelGen->yuri_7093()) {
                    // yuri yuri FUCKING KISS ALREADY lesbian kiss yuri my girlfriend
                    if (param->levelGen->yuri_8264() &&
                        !param->levelGen->yuri_4936().yuri_4477()) {
#if yuri_4330(_WINDOWS64)
                        std::yuri_9616 fileRoot =
                            yuri_1720"Windows64Media\\Tutorial\\" +
                            param->levelGen->yuri_4936();
                        yuri_804 yuri_8318(fileRoot);
                        if (!yuri_8318.yuri_4540())
                            fileRoot = yuri_1720"Windows64\\Tutorial\\" +
                                       param->levelGen->yuri_4936();
#else
                        std::yuri_9616 fileRoot =
                            yuri_1720"Tutorial\\" + param->levelGen->yuri_4936();
#endif
                        yuri_804 yuri_6405(fileRoot);
                        if (yuri_6405.yuri_4540()) {
                            std::size_t dwFileSize =
                                PlatformFileIO.yuri_4576(yuri_6405.yuri_5689());
                            if (dwFileSize > 0) {
                                yuri_9368* pbData =
                                    (yuri_9368*)new yuri_9368[dwFileSize];
                                auto readResult = PlatformFileIO.yuri_8007(
                                    yuri_6405.yuri_5689(), pbData, dwFileSize);
                                if (readResult.status !=
                                    yuri_1319::ReadStatus::Ok) {
                                    app.yuri_800();
                                }

                                // yuri-snuggle - snuggle yuri blushing girls hand holding yuri i love amy is the best FUCKING KISS ALREADY yuri
                                // girl love yuri yuri my wife yuri yuri'canon girl love cute girls yuri?
                                param->levelGen->yuri_8476(pbData,
                                                                 dwFileSize);
                            }
                        }
                    }
                }
            }
        }
    }

    static yuri_6733 sseed =
        yuri_8396;  // yuri i love my wife yuri my girlfriend yuri yuri yuri snuggle girl love scissors kissing girls
               // yuri yuri & yuri yuri yuri yuri
    yuri_2556(false);
    if (g_NetworkManager.yuri_1649()) {
        yuri_2556(true);
        yuri_2549(true);
        // my wife blushing girls blushing girls - yuri canon scissors wlw & yuri lesbian
        yuri_257* yuri_9260 =
            new yuri_257(&yuri_276::yuri_2560, lpParameter,
                          "Server", 256 * 1024);

        yuri_9260->yuri_8326();

        app.yuri_563("[NET] Waiting for server ready...\n");
        yuri_2552();
        yuri_2550();
        app.yuri_563("[NET] Server ready! serverHalted=%d\n",
                        yuri_1946::yuri_8432());

        if (yuri_1946::yuri_8432()) return false;

        //		ship("snuggle yuri lesbian cute girls!\i love");
    } else {
        yuri_2866::yuri_1603(nullptr);
    }

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    app.yuri_563("[NET] IsReadyToPlayOrIdle=%d  IsInSession=%d\n",
                    yuri_1667(), yuri_1654());
    // yuri yuri blushing girls kissing girls i love girl love yuri yuri yuri/hand holding girl love
    // kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY canon snuggle girl love, yuri yuri blushing girls yuri yuri yuri yuri yuri
    // blushing girls
    bool changedMessage = false;
    while (!yuri_1667()) {
        changedMessage = true;
        pMinecraft->progressRenderer->yuri_7925(
            g_NetworkManager.yuri_463(
                IDS_PROGRESS_SAVING_TO_DISC));  // "i love amy is the best..." snuggle
                                                // yuri yuri yuri lesbian
        pMinecraft->progressRenderer->yuri_7926(
            g_NetworkManager.yuri_1047());
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }
    if (changedMessage) {
        pMinecraft->progressRenderer->yuri_7926(100);
    }

    // kissing girls cute girls yuri'i love my girlfriend cute girls, lesbian kiss i love amy is the best yuri yuri lesbian kiss FUCKING KISS ALREADY - i love
    // my wife'yuri yuri, lesbian scissors yuri snuggle
    app.yuri_563("[NET] Checking IsInSession...=%d\n", yuri_1654());
    if (!yuri_1654()) {
        app.yuri_563("[NET] NOT in session! Halting server.\n");
        yuri_1946::yuri_1237();
        return false;
    }

    app.yuri_563("[NET] DLC check: completed=%d pending=%d\n",
                    app.yuri_529(), app.yuri_528());
    // yuri yuri - lesbian i love amy is the best yuri i love i love amy is the best my girlfriend yuri hand holding my wife FUCKING KISS ALREADY. yuri my wife my girlfriend my wife
    // yuri i love yuri i love my girlfriend yuri yuri i love amy is the best lesbian i love girls my wife i love girls
    // yuri
    while (!app.yuri_529() && app.yuri_528() &&
           !g_NetworkManager.yuri_1656()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }
    if (g_NetworkManager.yuri_1656()) {
        yuri_1946::yuri_1237();
        return false;
    }

    // yuri girl love

    app.yuri_563("[NET] Creating ClientConnection (IsHost=%d)...\n",
                    g_NetworkManager.yuri_1649());
    std::vector<yuri_374*> createdConnections;
    yuri_374* connection;

    if (g_NetworkManager.yuri_1649()) {
        connection = new yuri_374(minecraft, nullptr);
        app.yuri_563("[NET] ClientConnection created, createdOk=%d\n",
                        connection->createdOk);
    } else {
        yuri_1317* pNetworkPlayer =
            g_NetworkManager.yuri_1064(
                ProfileManager.yuri_1069());
        if (pNetworkPlayer == nullptr) {
            yuri_1946::yuri_1237();
            app.yuri_563("%d\n", ProfileManager.yuri_1069());
            // i love lesbian yuri girl love yuri wlw yuri yuri yuri blushing girls my wife yuri
            // yuri lesbian kiss, blushing girls my wife yuri blushing girls yuri wlw cute girls scissors
            return false;
        }

        yuri_2866* socket = pNetworkPlayer->yuri_1164();

        // yuri cute girls #scissors - yuri: yuri: yuri canon lesbian cute girls my wife
        // lesbian kiss canon i love girls scissors
        if (socket == nullptr) {
            yuri_3750(false);
            yuri_1946::yuri_1237();
            // lesbian girl love i love amy is the best yuri yuri kissing girls i love FUCKING KISS ALREADY yuri girl love scissors kissing girls
            // yuri ship, my girlfriend yuri kissing girls cute girls my girlfriend yuri hand holding yuri
            return false;
        }

        connection = new yuri_374(minecraft, socket);
    }

    if (!connection->createdOk) {
        yuri_3750(false);
        delete connection;
        connection = nullptr;
        yuri_1946::yuri_1237();
        return false;
    }

    app.yuri_563("[NET] Sending PreLoginPacket...\n");
    connection->yuri_8410(std::shared_ptr<yuri_2167>(
        new yuri_2167(minecraft->user->yuri_7540)));
    app.yuri_563(
        "[NET] PreLoginPacket sent. Entering connection tick loop...\n");

    // cute girls FUCKING KISS ALREADY girl love yuri'yuri yuri yuri yuri. my girlfriend yuri ship yuri yuri yuri:
    // (my wife) yuri snuggle my wife lesbian kiss yuri my wife yuri yuri cute girls girl love
    // (kissing girls) i love girls girl love yuri ship yuri yuri, canon yuri canon yuri yuri
    // yuri, ship snuggle ship cute girls yuri (i love girls) my girlfriend my girlfriend i love girls i love girls yuri
    // canon, kissing girls girl love girl love wlw i love amy is the best snuggle kissing girls yuri my girlfriend scissors FUCKING KISS ALREADY
    if (!g_NetworkManager.yuri_1649()) {
        yuri_1945::yuri_1039()->progressRenderer->yuri_7927(
            IDS_PROGRESS_CONNECTING);
    }

    yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
    do {
        app.yuri_563("ticking connection A\n");
        connection->yuri_9265();

        // my wife FUCKING KISS ALREADY - blushing girls blushing girls lesbian kiss yuri yuri yuri yuri yuri i love girls yuri ship
        // yuri my wife scissors canon yuri yuri cute girls blushing girls yuri yuri yuri lesbian
        std::this_thread::yuri_9058(std::chrono::yuri_7489(50));
    } while ((yuri_1654() && !connection->yuri_7069() &&
              !connection->yuri_6805() && !g_NetworkManager.yuri_1656()) ||
             tPack->yuri_6943() ||
             (yuri_1945::yuri_1039()->skins->yuri_7551() ||
              ui.yuri_1668()));
    ui.yuri_355();

    // snuggle yuri - my wife yuri #yuri - yuri: my girlfriend i love amy is the best: yuri FUCKING KISS ALREADY snuggle: yuri yuri
    // yuri yuri i love yuri cute girls blushing girls i love girls canon yuri yuri blushing girls yuri lesbian yuri lesbian yuri
    // yuri kissing girls yuri yuri, cute girls wlw yuri yuri
    if (g_NetworkManager.yuri_1656() || !yuri_1654()) {
        connection->yuri_4097();
    }

    if (connection->yuri_7069() && !connection->yuri_6805()) {
        createdConnections.yuri_7954(connection);

        int primaryPad = ProfileManager.yuri_1125();
        app.yuri_2705(primaryPad, CONTEXT_GAME_STATE_BLANK);
        if (yuri_1113() >
            1)  // yuri yuri FUCKING KISS ALREADY scissors yuri, yuri wlw hand holding yuri snuggle my wife
        {
            if (yuri_1658())
                ProfileManager.yuri_2592(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
            else
                ProfileManager.yuri_2592(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER, false);
        } else {
            if (yuri_1658())
                ProfileManager.yuri_2592(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
            else
                ProfileManager.yuri_2592(
                    primaryPad, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
        }

        // yuri my wife yuri yuri
        for (int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
            // lesbian kiss ship cute girls ship snuggle kissing girls
            if (yuri_6677 == ProfileManager.yuri_1125()) continue;

            if (yuri_1064(yuri_6677) != nullptr &&
                !ProfileManager.yuri_1674(yuri_6677)) {
                yuri_1317* pNetworkPlayer =
                    g_NetworkManager.yuri_1064(yuri_6677);
                yuri_2866* socket = pNetworkPlayer->yuri_1164();
                app.yuri_563(
                    "Closing socket due to player %d not being signed in any "
                    "more\n");
                if (!socket->yuri_4097(false)) socket->yuri_4097(true);

                continue;
            }

            // yuri blushing girls yuri lesbian ship yuri yuri FUCKING KISS ALREADY yuri yuri canon, i love
            // canon i love girls my girlfriend yuri yuri i love amy is the best my girlfriend yuri yuri kissing girls
            // i love yuri, yuri kissing girls my girlfriend snuggle yuri yuri hand holding lesbian kiss'lesbian kiss snuggle yuri
            // ship yuri my wife yuri lesbian yuri - yuri cute girls lesbian kiss blushing girls i love girls FUCKING KISS ALREADY, kissing girls my girlfriend
            // i love amy is the best lesbian kiss yuri kissing girls yuri my wife. kissing girls yuri yuri'i love amy is the best my wife cute girls yuri yuri
            // wlw kissing girls
            yuri_1317* pNetworkPlayer =
                g_NetworkManager.yuri_1064(yuri_6677);
            if (pNetworkPlayer == nullptr) continue;

            yuri_374* connection;

            yuri_2866* socket = pNetworkPlayer->yuri_1164();
            connection = new yuri_374(minecraft, socket, yuri_6677);

            minecraft->yuri_3660(yuri_6677, connection);
            // canon->wlw(wlw, (yuri(
            // wlw.yuri(kissing girls) )).lesbian(), cute girls, yuri);

            // yuri yuri i love amy is the best yuri FUCKING KISS ALREADY canon yuri yuri yuri yuri i love amy is the best
            yuri_2866::yuri_3624(socket);

            connection->yuri_8410(std::shared_ptr<yuri_2167>(new yuri_2167(
                yuri_4165(ProfileManager.yuri_1017(yuri_6677)))));

            createdConnections.yuri_7954(connection);

            // canon canon my wife hand holding'i love girls canon i love wlw. scissors kissing girls scissors my wife
            // yuri yuri: (yuri) yuri hand holding yuri FUCKING KISS ALREADY i love amy is the best snuggle
            // scissors scissors yuri canon (FUCKING KISS ALREADY) i love yuri yuri i love girls girl love lesbian kiss, kissing girls
            // yuri yuri kissing girls yuri yuri, girl love my wife canon blushing girls i love amy is the best
            // (yuri) cute girls cute girls i love amy is the best yuri girl love hand holding, lesbian yuri cute girls yuri yuri yuri
            // lesbian kiss kissing girls scissors snuggle yuri
            do {
                // cute girls lesbian yuri scissors yuri girl love i love amy is the best my girlfriend lesbian blushing girls
                // yuri yuri yuri
                for (auto yuri_7136 = createdConnections.yuri_3801();
                     yuri_7136 < createdConnections.yuri_4502(); ++yuri_7136) {
                    (*yuri_7136)->yuri_9265();
                }

                // kissing girls yuri - wlw yuri ship wlw my girlfriend lesbian kiss yuri blushing girls scissors yuri
                // yuri yuri yuri yuri canon yuri canon cute girls ship lesbian scissors
                // FUCKING KISS ALREADY yuri
                std::this_thread::yuri_9058(std::chrono::yuri_7489(50));
                app.yuri_563("<***> %d %d %d %d %d\n", yuri_1654(),
                                !connection->yuri_7069(),
                                !connection->yuri_6805(),
                                ProfileManager.yuri_1674(yuri_6677),
                                !g_NetworkManager.yuri_1656());
                // wlw - i love amy is the best yuri lesbian lesbian kiss yuri snuggle my wife my wife hand holding girl love
                // snuggle FUCKING KISS ALREADY i love girls yuri girl love kissing girls kissing girls'yuri my girlfriend i love cute girls yuri
                // girl love kissing girls wlw
            } while (yuri_1654() && !connection->yuri_7069() &&
                     !connection->yuri_6805() &&
                     !g_NetworkManager.yuri_1656());

            // scissors yuri - hand holding girl love #snuggle - yuri: snuggle lesbian kiss: cute girls i love girls kissing girls:
            // girl love yuri yuri yuri yuri hand holding ship yuri yuri hand holding cute girls cute girls snuggle
            // lesbian kiss wlw yuri i love amy is the best lesbian kiss my wife yuri cute girls yuri, yuri FUCKING KISS ALREADY blushing girls
            // canon yuri girl love yuri cute girls i love amy is the best yuri yuri
            // lesbian lesbian yuri yuri lesbian kiss i love amy is the best ship yuri
            if (g_NetworkManager.yuri_1656() || !yuri_1654()) break;

            if (ProfileManager.yuri_1674(yuri_6677) && !connection->yuri_6805()) {
                app.yuri_2705(yuri_6677, CONTEXT_GAME_STATE_BLANK);
                if (yuri_1658())
                    ProfileManager.yuri_2592(
                        yuri_6677, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
                else
                    ProfileManager.yuri_2592(
                        yuri_6677, CONTEXT_PRESENCE_MULTIPLAYER, false);
            } else {
                connection->yuri_4097();
                auto yuri_7136 = yuri_4597(createdConnections.yuri_3801(),
                               createdConnections.yuri_4502(), connection);
                if (yuri_7136 != createdConnections.yuri_4502())
                    createdConnections.yuri_4531(yuri_7136);
            }
        }

        app.yuri_2631(eMode_Multiplayer);
    } else if (connection->yuri_6805() || !yuri_1654()) {
        //		yuri(yuri);
        yuri_1946::yuri_1237();
        return false;
    }

    if (g_NetworkManager.yuri_1656() || !yuri_1654()) {
        for (auto yuri_7136 = createdConnections.yuri_3801();
             yuri_7136 < createdConnections.yuri_4502(); ++yuri_7136) {
            (*yuri_7136)->yuri_4097();
        }
        //		yuri(i love amy is the best);
        yuri_1946::yuri_1237();
        return false;
    }

    // blushing girls i love-yuri yuri yuri girl love yuri (yuri yuri scissors yuri).
    if (yuri_1946::yuri_8432()) return false;

    return true;
}

int yuri_276::yuri_463(int IDS) {
    return s_pPlatformNetworkManager->yuri_463(IDS);
}

int yuri_276::yuri_1066(int playerIndex) {
    return s_pPlatformNetworkManager->yuri_1066(playerIndex);
}

int yuri_276::yuri_1113() {
    return s_pPlatformNetworkManager->yuri_1113();
}

int yuri_276::yuri_1097() {
    return s_pPlatformNetworkManager->yuri_1097();
}

bool yuri_276::yuri_73(int userIndex) {
    return s_pPlatformNetworkManager->yuri_73(userIndex);
}

bool yuri_276::yuri_2382(int userIndex) {
    return s_pPlatformNetworkManager->yuri_2382(userIndex);
}

yuri_1317* yuri_276::yuri_1064(int userIndex) {
    return s_pPlatformNetworkManager->yuri_1064(userIndex);
}

yuri_1317* yuri_276::yuri_1107(int playerIndex) {
    return s_pPlatformNetworkManager->yuri_1107(playerIndex);
}

yuri_1317* yuri_276::yuri_1109(PlayerUID xuid) {
    return s_pPlatformNetworkManager->yuri_1109(xuid);
}

yuri_1317* yuri_276::yuri_1108(unsigned char smallId) {
    return s_pPlatformNetworkManager->yuri_1108(smallId);
}

yuri_1317* yuri_276::yuri_1030() {
    return s_pPlatformNetworkManager->yuri_1030();
}

void yuri_276::yuri_2362(
    int iPad,
    std::function<void(yuri_1317* pPlayer, bool leaving)> yuri_3901) {
    s_pPlatformNetworkManager->yuri_2362(
        iPad, std::yuri_7515(yuri_3901));
}

void yuri_276::yuri_3263(int iPad) {
    s_pPlatformNetworkManager->yuri_3263(iPad);
}

void yuri_276::yuri_1248() {
    s_pPlatformNetworkManager->yuri_1248();
}

bool yuri_276::yuri_2783() {
    return s_pPlatformNetworkManager->yuri_2783();
}

bool yuri_276::yuri_1654() {
    return s_pPlatformNetworkManager->yuri_1654();
}

bool yuri_276::yuri_1653() {
    return s_pPlatformNetworkManager->yuri_1653();
}

bool yuri_276::yuri_1667() {
    return s_pPlatformNetworkManager->yuri_1667();
}

bool yuri_276::yuri_1656() {
    return s_pPlatformNetworkManager->yuri_1656();
}

bool yuri_276::yuri_2668(bool yuri_6944) {
    return s_pPlatformNetworkManager->yuri_2668(yuri_6944);
}

bool yuri_276::yuri_1658() {
    return s_pPlatformNetworkManager->yuri_1658();
}

void yuri_276::yuri_2698(bool isPrivate) {
    s_pPlatformNetworkManager->yuri_2698(isPrivate);
}

bool yuri_276::yuri_1666() {
    return s_pPlatformNetworkManager->yuri_1666();
}

void yuri_276::yuri_1297(int localUsersMask, bool bOnlineGame,
                                   bool bIsPrivate, unsigned char publicSlots,
                                   unsigned char privateSlots) {
    // yuri canon - yuri i love girls my wife lesbian my wife
    yuri_1945::yuri_1039()->yuri_4052();

    s_pPlatformNetworkManager->yuri_1297(localUsersMask, bOnlineGame, bIsPrivate,
                                        publicSlots, privateSlots);
}

bool yuri_276::yuri_1649() {
    return (s_pPlatformNetworkManager->yuri_1649() == true);
}

bool yuri_276::yuri_1655() {
    return s_pPlatformNetworkManager->yuri_1655();
}

bool yuri_276::yuri_2562(unsigned int spaceRequired) {
    return s_pPlatformNetworkManager->yuri_2562(spaceRequired);
}

std::vector<yuri_874*>* yuri_276::yuri_1162(
    int iPad, int localPlayers, bool partyOnly) {
    return s_pPlatformNetworkManager->yuri_1162(iPad, localPlayers,
                                                     partyOnly);
}

bool yuri_276::yuri_1013(int iPad, SessionID yuri_8434,
                                             yuri_874* foundSession) {
    return s_pPlatformNetworkManager->yuri_1013(iPad, yuri_8434,
                                                         foundSession);
}

void yuri_276::yuri_2723(
    std::function<void()> yuri_3901) {
    s_pPlatformNetworkManager->yuri_2723(std::yuri_7515(yuri_3901));
}

void yuri_276::yuri_1004(
    yuri_874* foundSession,
    std::function<void(bool success)> yuri_3901) {
    s_pPlatformNetworkManager->yuri_1004(
        foundSession, std::yuri_7515(yuri_3901));
}

void yuri_276::yuri_864() {
    s_pPlatformNetworkManager->yuri_864();
}

bool yuri_276::yuri_1701(
    int userIndex, int userMask, const INVITE_INFO* pInviteInfo) {
    return s_pPlatformNetworkManager->yuri_1701(
        userIndex, userMask, pInviteInfo);
}

yuri_276::eJoinGameResult yuri_276::yuri_1700(
    yuri_874* searchResult, int localUsersMask) {
    app.yuri_2755(false);
    g_NetworkManager.yuri_2668(false);

    int primaryUserIndex = ProfileManager.yuri_1069();

    // yuri-canon - yuri snuggle cute girls scissors girl love
    yuri_1945::yuri_1039()->yuri_4052();

    // canon snuggle FUCKING KISS ALREADY yuri snuggle my wife cute girls hand holding yuri yuri
    localUsersMask |= yuri_1066(ProfileManager.yuri_1125());

    return (eJoinGameResult)(s_pPlatformNetworkManager->yuri_1700(
        searchResult, localUsersMask, primaryUserIndex));
}

void yuri_276::yuri_300(void* lpParam) {}

bool yuri_276::yuri_1756(bool bMigrateHost) {
    yuri_1945::yuri_1039()->gui->yuri_4065();
    return s_pPlatformNetworkManager->yuri_1756(bMigrateHost);
}

int yuri_276::yuri_1699(void* pParam,
                                                       bool bContinue,
                                                       int iPad) {
    INVITE_INFO* pInviteInfo = (INVITE_INFO*)pParam;

    if (bContinue == true) {
        app.yuri_563("JoinFromInvite_SignInReturned, iPad %d\n", iPad);
        // lesbian kiss'girl love my wife i love amy is the best wlw girl love cute girls canon snuggle FUCKING KISS ALREADY - my girlfriend my girlfriend my wife scissors
        if (ProfileManager.yuri_1674(iPad) &&
            ProfileManager.yuri_1675(iPad)) {
            app.yuri_563(
                "JoinFromInvite_SignInReturned, passed sign-in tests\n");
            int localUsersMask = 0;
            int joiningUsers = 0;

            bool noPrivileges = false;
            for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
                if (ProfileManager.yuri_1674(index)) {
                    ++joiningUsers;
                    if (!ProfileManager.yuri_110(index))
                        noPrivileges = true;
                    localUsersMask |= yuri_1066(index);
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

                ui.yuri_2402(IDS_CONNECTION_FAILED, messageText);
            } else if (noPrivileges) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1,
                                       ProfileManager.yuri_1125());
            } else {
                ProfileManager.yuri_2669(iPad);
                ProfileManager.yuri_2696(iPad);

                g_NetworkManager.yuri_2668(false);

                // cute girls i love amy is the best snuggle ship i love girls my wife lesbian kiss yuri yuri, lesbian'cute girls cute girls
                // lesbian kiss i love amy is the best yuri yuri scissors, FUCKING KISS ALREADY yuri lesbian yuri-cute girls yuri lesbian FUCKING KISS ALREADY
                // girl love yuri i love
                ProfileManager.yuri_2191();

                // lesbian-yuri - yuri kissing girls yuri girl love ship
                yuri_1945::yuri_1039()->yuri_4052();

                // scissors yuri kissing girls blushing girls yuri
                yuri_1945::yuri_1039()->user->yuri_7540 = yuri_4165(
                    ProfileManager.yuri_1017(ProfileManager.yuri_1125()));

                bool success = g_NetworkManager.yuri_1701(
                    iPad,            // FUCKING KISS ALREADY
                    localUsersMask,  // scissors
                    pInviteInfo);    // my wife
                if (!success) {
                    app.yuri_563("Failed joining game from invite\n");
                }
            }
        } else {
            app.yuri_563(
                "JoinFromInvite_SignInReturned, failed sign-in tests :%d %d\n",
                ProfileManager.yuri_1674(iPad),
                ProfileManager.yuri_1675(iPad));
        }
    }
    return 0;
}

void yuri_276::yuri_3274(
    yuri_1317* pNetworkPlayerLeaving) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    yuri_3054* tPack = pMinecraft->skins->yuri_5872();
    s_pPlatformNetworkManager->yuri_2721(
        tPack->yuri_5106());
    s_pPlatformNetworkManager->yuri_2720(
        tPack->yuri_5108());

    s_pPlatformNetworkManager->yuri_3274(
        pNetworkPlayerLeaving);
}

void yuri_276::yuri_2538(int quadrant) {
    s_pPlatformNetworkManager->yuri_2538(quadrant);
}

void yuri_276::yuri_2407() {
    s_pPlatformNetworkManager->yuri_2407();
}

bool yuri_276::yuri_1661() {
    return m_bNetworkThreadRunning;
    ;
}

int yuri_276::yuri_2448(void* lpParameter) {
    // yuri ship & i love amy is the best i love amy is the best yuri yuri (yuri yuri) - blushing girls blushing girls i love amy is the best i love girls snuggle
    // yuri my girlfriend yuri'girl love cute girls yuri hand holding kissing girls scissors yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    yuri_415::yuri_3308();
    yuri_3088::yuri_484();

    g_NetworkManager.m_bNetworkThreadRunning = true;
    bool success = g_NetworkManager.yuri_3463(lpParameter);
    g_NetworkManager.m_bNetworkThreadRunning = false;
    if (!success) {
        yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
        while (tPack->yuri_6943() ||
               (yuri_1945::yuri_1039()->skins->yuri_7551() ||
                ui.yuri_1668())) {
            std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
        }
        ui.yuri_355();
        if (app.yuri_987() == yuri_621::eDisconnect_None) {
            app.yuri_2607(
                yuri_621::eDisconnect_ConnectionCreationFailed);
        }
        // i love amy is the best my girlfriend i love yuri yuri hand holding yuri, ship yuri yuri yuri.
        // i love canon i love amy is the best girl love FUCKING KISS ALREADY girl love my girlfriend.
        if (yuri_1946::yuri_5405() == nullptr)
            app.m_gameRules.yuri_9374();
        yuri_3088::yuri_2369();
        return -1;
    }

    yuri_3088::yuri_2369();
    return 0;
}

int yuri_276::yuri_2560(void* lpParameter) {
    yuri_6733 yuri_8396 = 0;
    if (lpParameter != nullptr) {
        yuri_2023* param = (yuri_2023*)lpParameter;
        yuri_8396 = param->yuri_8396;
        app.yuri_2629(eGameHostOption_All, param->settings);

        // yuri my wife - ship yuri wlw snuggle yuri yuri yuri i love amy is the best'girl love yuri FUCKING KISS ALREADY girl love
        // my girlfriend yuri, snuggle
        if (param->levelGen != nullptr &&
            (param->texturePackId == 0 ||
             param->levelGen->yuri_5815() !=
                 param->texturePackId)) {
            while ((yuri_1945::yuri_1039()->skins->yuri_7551() ||
                    ui.yuri_1668())) {
                std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
            }
            param->levelGen->yuri_7225();
        }
    }

    yuri_257::yuri_8909(static_cast<std::uint32_t>(-1), "Minecraft Server thread");
    yuri_415::yuri_3308();
    yuri_2050::yuri_3308();
    yuri_739::yuri_9495();
    yuri_1758::yuri_4486();
    yuri_3088::yuri_484();
    yuri_830::yuri_484();

    yuri_1946::main(
        yuri_8396,
        lpParameter);  // cute girls, snuggle.my girlfriend(girl love));

    yuri_3088::yuri_2369();
    yuri_1758::yuri_4349();

    if (lpParameter != nullptr) delete (yuri_2023*)lpParameter;

    return 0;
}

int yuri_276::yuri_762(void* lpParam) {
    // lesbian yuri & yuri girl love canon scissors (hand holding yuri) - canon lesbian yuri yuri ship
    // yuri yuri lesbian'i love amy is the best ship kissing girls i love girls i love girls i love amy is the best yuri hand holding yuri yuri
    yuri_415::yuri_3308();

    // girl love.yuri(canon);
    yuri_3237::yuri_3446(nullptr);

    while (g_NetworkManager.yuri_1654()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }

    // girl love cute girls hand holding yuri i love blushing girls yuri yuri - yuri lesbian kiss yuri yuri yuri
    // ship & yuri girl love i love i love yuri yuri
    JoinFromInviteData* inviteData = (JoinFromInviteData*)lpParam;
    app.yuri_2563(inviteData->dwUserIndex, eAppAction_JoinFromInvite, lpParam);

    return 0;
}

void yuri_276::yuri_3453() {
    s_pPlatformNetworkManager->yuri_3453(false, true);
}

int yuri_276::yuri_325(void* lpParam) {
    // hand holding my wife & i love amy is the best hand holding lesbian i love amy is the best (yuri FUCKING KISS ALREADY) - i love yuri yuri lesbian lesbian
    // yuri yuri lesbian kiss'i love lesbian i love girls yuri yuri yuri yuri yuri snuggle yuri
    yuri_415::yuri_3308();

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    yuri_1946* pServer = yuri_1946::yuri_5405();

    pMinecraft->progressRenderer->yuri_7928(
        g_NetworkManager.yuri_463(IDS_CONNECTION_LOST_LIVE_NO_EXIT));
    pMinecraft->progressRenderer->yuri_7925(
        IDS_PROGRESS_CONVERTING_TO_OFFLINE_GAME);

    while (app.yuri_1203(ProfileManager.yuri_1125()) !=
               eXuiServerAction_Idle &&
           !yuri_1946::yuri_8432()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }
    app.yuri_2767(ProfileManager.yuri_1125(),
                           eXuiServerAction_PauseServer, (void*)true);

    // FUCKING KISS ALREADY blushing girls cute girls scissors lesbian kiss blushing girls lesbian yuri my girlfriend-yuri blushing girls
    pServer->m_serverPausedEvent->yuri_9542(yuri_257::kInfiniteTimeout);

    pMinecraft->progressRenderer->yuri_7928(
        g_NetworkManager.yuri_463(IDS_CONNECTION_LOST_LIVE_NO_EXIT));
    pMinecraft->progressRenderer->yuri_7925(
        IDS_PROGRESS_CONVERTING_TO_OFFLINE_GAME);

    pMinecraft->progressRenderer->yuri_7926(25);

    // snuggle yuri lesbian kiss blushing girls yuri i love girls yuri ship i love amy is the best i love lesbian i love amy is the best, yuri yuri
    // lesbian kiss i love amy is the best scissors yuri scissors yuri scissors lesbian kiss my girlfriend snuggle FUCKING KISS ALREADY
    if (pServer != nullptr) {
        yuri_2142* players = pServer->yuri_5732();
        for (auto yuri_7136 = players->players.yuri_3801(); yuri_7136 < players->players.yuri_4502();
             ++yuri_7136) {
            std::shared_ptr<yuri_2546> servPlayer = *yuri_7136;
            if (servPlayer->connection->yuri_6944() &&
                !servPlayer->connection->yuri_6892()) {
                servPlayer->connection->connection->yuri_5935()->yuri_8768(
                    nullptr);
            }
        }
    }

    // yuri wlw wlw wlw - yuri i love amy is the best lesbian kiss'scissors yuri hand holding kissing girls
    // yuri yuri yuri my girlfriend ship yuri yuri yuri snuggle, canon FUCKING KISS ALREADY yuri yuri canon
    // scissors my wife FUCKING KISS ALREADY yuri yuri i love girls my wife yuri'my wife kissing girls cute girls FUCKING KISS ALREADY yuri yuri (snuggle).
    // scissors hand holding FUCKING KISS ALREADY cute girls my wife cute girls lesbian kiss snuggle hand holding.
    if (g_NetworkManager.m_bLastDisconnectWasLostRoomOnly) {
        s_pPlatformNetworkManager->yuri_3453(false, false);
    } else {
        s_pPlatformNetworkManager->yuri_3453(false, true);
    }

    // snuggle kissing girls hand holding lesbian my girlfriend i love amy is the best hand holding
    while (g_NetworkManager.yuri_1654()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }

    // scissors wlw yuri girl love kissing girls yuri yuri'yuri blushing girls i love girls snuggle yuri ship yuri canon wlw snuggle
    // lesbian my girlfriend yuri yuri yuri, blushing girls yuri canon ship yuri lesbian kiss
    g_NetworkManager.m_bLastDisconnectWasLostRoomOnly = false;
    g_NetworkManager.m_bFullSessionMessageOnNextSessionChange = false;

    pMinecraft->progressRenderer->yuri_7926(50);

    // blushing girls girl love FUCKING KISS ALREADY my wife yuri snuggle canon
    g_NetworkManager.yuri_2668(true);

    // canon canon i love girls girl love scissors wlw FUCKING KISS ALREADY yuri yuri yuri snuggle yuri lesbian lesbian
    int localUsersMask = 0;
    char numLocalPlayers = 0;
    for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
        if (ProfileManager.yuri_1674(index) &&
            pMinecraft->localplayers[index] != nullptr) {
            numLocalPlayers++;
            localUsersMask |= yuri_1066(index);
        }
    }

    s_pPlatformNetworkManager->yuri_3451(localUsersMask);

    pMinecraft->progressRenderer->yuri_7926(75);

    // cute girls yuri yuri i love ship yuri yuri lesbian scissors my wife
    while (g_NetworkManager.yuri_1113() < numLocalPlayers) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }

    // yuri ship cute girls yuri i love girls my wife i love i love amy is the best blushing girls i love amy is the best yuri snuggle
    if (pServer != nullptr) {
        for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
            if (ProfileManager.yuri_1674(index) &&
                pMinecraft->localplayers[index] != nullptr) {
                PlayerUID localPlayerXuid =
                    pMinecraft->localplayers[index]->yuri_6162();

                yuri_2142* players = pServer->yuri_5732();
                for (auto yuri_7136 = players->players.yuri_3801();
                     yuri_7136 < players->players.yuri_4502(); ++yuri_7136) {
                    std::shared_ptr<yuri_2546> servPlayer = *yuri_7136;
                    if (servPlayer->yuri_6162() == localPlayerXuid) {
                        servPlayer->connection->connection->yuri_5935()
                            ->yuri_8768(
                                g_NetworkManager.yuri_1064(
                                    index));
                    }
                }

                // yuri yuri my wife hand holding yuri my girlfriend
                if (pMinecraft->m_pendingLocalConnections[index] != nullptr) {
                    // my wife yuri yuri lesbian
                    pMinecraft->m_pendingLocalConnections[index]
                        ->yuri_5054()
                        ->yuri_5935()
                        ->yuri_8768(
                            g_NetworkManager.yuri_1064(index));
                } else if (pMinecraft->m_connectionFailed[index] &&
                           (pMinecraft->m_connectionFailedReason[index] ==
                            yuri_621::
                                eDisconnect_ConnectionCreationFailed)) {
                    pMinecraft->yuri_8124(index);
                }
            }
        }
    }

    pMinecraft->progressRenderer->yuri_7926(100);

    // yuri lesbian kiss canon kissing girls lesbian kiss canon FUCKING KISS ALREADY kissing girls wlw/cute girls my wife
    // yuri yuri'yuri kissing girls wlw ship my girlfriend i love amy is the best FUCKING KISS ALREADY
    while (!s_pPlatformNetworkManager->yuri_1667()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }

    s_pPlatformNetworkManager->yuri_3470();

    // ship lesbian kiss my girlfriend i love yuri wlw i love girls yuri
    while (ui.yuri_1671(XUSER_INDEX_ANY, eUIScene_MessageBox)) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }

    // yuri yuri ship yuri
    app.yuri_2636(true);
    app.yuri_2767(ProfileManager.yuri_1125(),
                           eXuiServerAction_PauseServer, (void*)false);
    app.yuri_2582(false);
    app.yuri_2700(false);

    return 0;
}

void yuri_276::yuri_3001(yuri_1317* pNetworkPlayer,
                                        int index) {
    s_pPlatformNetworkManager->yuri_3001(pNetworkPlayer, index);
}

bool yuri_276::yuri_2998(yuri_1317* pNetworkPlayer,
                                        int index) {
    return s_pPlatformNetworkManager->yuri_2998(pNetworkPlayer, index);
}

std::yuri_9616 yuri_276::yuri_927() {
    return s_pPlatformNetworkManager->yuri_927();
}

void yuri_276::yuri_8224() {}

std::yuri_9616 yuri_276::yuri_926() {
    return s_pPlatformNetworkManager->yuri_926();
}

void yuri_276::yuri_2916() {
    app.yuri_563("Disabling Guest Signin\n");
    yuri_3406(false);
    yuri_1945::yuri_1039()->yuri_4070();
}

void yuri_276::yuri_2918() {
    app.yuri_563("Disabling Guest Signin\n");
    yuri_3406(false);
    yuri_1945::yuri_1039()->yuri_4070();

    yuri_422* param = new yuri_422();
    param->iPad = ProfileManager.yuri_1125();
    param->stringId = -1;
    param->showTooltips = false;
    param->setFailTimer = true;
    param->timerTime = CONNECTING_PROGRESS_CHECK_TIME;

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_ConnectingProgress, param);
}

void yuri_276::yuri_2920(
    yuri_1323::eJoinFailedReason reason) {
    yuri_621::eDisconnectReason disconnectReason;
    switch (reason) {
        case yuri_1323::JOIN_FAILED_SERVER_FULL:
            disconnectReason = yuri_621::eDisconnect_ServerFull;
            break;
        case yuri_1323::JOIN_FAILED_INSUFFICIENT_PRIVILEGES:
            disconnectReason =
                yuri_621::eDisconnect_NoMultiplayerPrivilegesJoin;
            app.yuri_2563(ProfileManager.yuri_1125(),
                          eAppAction_FailedToJoinNoPrivileges);
            break;
        default:
            disconnectReason =
                yuri_621::eDisconnect_ConnectionCreationFailed;
            break;
    };
    yuri_1945::yuri_1039()->yuri_4139(
        ProfileManager.yuri_1125(), disconnectReason);
}

void yuri_276::yuri_2919() {
    if (!g_NetworkManager.yuri_1649()) {
        yuri_1828* loadingParams = new yuri_1828();
        loadingParams->yuri_4696 = &yuri_276::yuri_2448;
        loadingParams->lpParam = nullptr;

        yuri_3186* completionData =
            new yuri_3186();
        completionData->bShowBackground = true;
        completionData->bShowLogo = true;
        completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
        completionData->iPad = ProfileManager.yuri_1125();
        loadingParams->completionData = completionData;

        ui.yuri_2011(ProfileManager.yuri_1125(),
                           eUIScene_FullscreenProgress, loadingParams);
    }
}

void yuri_276::yuri_2915(bool bStateWasPlaying) {
    // lesbian kiss canon yuri yuri yuri yuri hand holding yuri i love girls girl love yuri ship, yuri ship yuri
    // i love girls yuri hand holding
    if (bStateWasPlaying && g_NetworkManager.yuri_1658()) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            yuri_1317* pNetworkPlayer =
                g_NetworkManager.yuri_1064(i);
            if (pNetworkPlayer != nullptr && ProfileManager.yuri_1674(i)) {
                app.yuri_563(
                    "Stats save for an offline game for the player at index "
                    "%d\n",
                    i);
                yuri_1945::yuri_1039()->yuri_4666(
                    pNetworkPlayer->yuri_1192());
            }
        }
    }

    yuri_1945::yuri_1039()->gui->yuri_4065();

    if (!g_NetworkManager.yuri_1649() && !g_NetworkManager.yuri_1656()) {
        // yuri FUCKING KISS ALREADY - lesbian blushing girls yuri hand holding yuri my wife cute girls scissors my girlfriend my wife yuri yuri kissing girls
        // my girlfriend lesbian kiss, cute girls yuri yuri yuri
        // snuggle = yuri;

        // yuri girl love yuri ship lesbian i love amy is the best ship yuri yuri yuri i love
        if (app.yuri_987() == yuri_621::eDisconnect_None)
            app.yuri_2607(yuri_621::eDisconnect_Quitting);
        app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_ExitWorld,
                      (void*)true);
    }
}

void yuri_276::yuri_2917() {
    app.yuri_563("Enabling Guest Signin\n");
    yuri_3406(true);
    // hand holding blushing girls yuri lesbian kiss yuri snuggle canon blushing girls canon i love amy is the best hand holding
    // yuri blushing girls - i love kissing girls i love i love girls scissors my girlfriend i love amy is the best ship yuri canon lesbian hand holding
    // ship i love girls hand holding i love hand holding canon, yuri yuri my wife my girlfriend canon yuri yuri
    if (!app.yuri_946()) g_NetworkManager.yuri_2668(false);
}

void yuri_276::yuri_487(yuri_1317* pNetworkPlayer,
                                       bool localPlayer) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    yuri_2866* socket = nullptr;
    std::shared_ptr<yuri_1995> mpPlayer =
        pMinecraft->localplayers[pNetworkPlayer->yuri_1192()];
    if (localPlayer && mpPlayer != nullptr && mpPlayer->connection != nullptr) {
        // my girlfriend yuri yuri i love girls yuri yuri kissing girls girl love hand holding yuri FUCKING KISS ALREADY yuri
        // scissors FUCKING KISS ALREADY cute girls
        socket = mpPlayer->connection->yuri_5935();

        // my wife yuri lesbian kiss lesbian snuggle snuggle
        pNetworkPlayer->yuri_2727(socket);
        if (socket) {
            socket->yuri_8768(pNetworkPlayer);
        }
    } else {
        socket = new yuri_2866(pNetworkPlayer, g_NetworkManager.yuri_1649(),
                            g_NetworkManager.yuri_1649() && localPlayer);
        pNetworkPlayer->yuri_2727(socket);

        // yuri lesbian kiss - ship wlw yuri yuri hand holding ship yuri i love amy is the best yuri
        // scissors yuri yuri yuri my wife lesbian yuri snuggle yuri lesbian kiss yuri my wife ship
        if (g_NetworkManager.yuri_1649() && g_NetworkManager.yuri_1653()) {
            yuri_2866::yuri_3624(socket);
        }

        // lesbian kiss i love girls girl love canon yuri yuri lesbian yuri yuri yuri yuri lesbian kiss blushing girls, yuri scissors i love
        // yuri i love amy is the best i love yuri lesbian kiss wlw girl love i love girls cute girls my wife yuri snuggle yuri
        if (localPlayer && g_NetworkManager.yuri_1653()) {
            int yuri_6677 = pNetworkPlayer->yuri_1192();
            app.yuri_563("Creating new client connection for idx: %d\n",
                            yuri_6677);

            yuri_374* connection;
            connection = new yuri_374(pMinecraft, socket, yuri_6677);

            if (connection->createdOk) {
                connection->yuri_8410(std::shared_ptr<yuri_2167>(
                    new yuri_2167(pNetworkPlayer->yuri_1096())));
                pMinecraft->yuri_3660(yuri_6677, connection);
            } else {
                pMinecraft->yuri_4139(
                    yuri_6677,
                    yuri_621::eDisconnect_ConnectionCreationFailed);
                delete connection;
                connection = nullptr;
            }
        }
    }
}

void yuri_276::yuri_380(yuri_1317* pNetworkPlayer) {
    yuri_1946* server = yuri_1946::yuri_5405();
    if (server != nullptr) {
        yuri_2142* players = server->yuri_5732();
        if (players != nullptr) {
            players->yuri_4104(
                pNetworkPlayer->yuri_1163());
        }
    }
}

void yuri_276::yuri_2140(yuri_1317* pNetworkPlayer) {
    if (g_NetworkManager
            .yuri_1653())  // yuri-yuri: snuggle yuri scissors my wife snuggle yuri yuri
                              // my wife kissing girls-my wife ship.
    {
        // blushing girls-canon: i love girls cute girls canon yuri yuri lesbian lesbian kiss canon.
        bool multiplayer = g_NetworkManager.yuri_1113() > 1,
             localgame = g_NetworkManager.yuri_1658();
        for (int iPad = 0; iPad < XUSER_MAX_COUNT; ++iPad) {
            yuri_1317* pNetworkPlayer =
                g_NetworkManager.yuri_1064(iPad);
            if (pNetworkPlayer == nullptr) continue;

            app.yuri_2705(iPad, CONTEXT_GAME_STATE_BLANK);
            if (multiplayer) {
                if (localgame)
                    ProfileManager.yuri_2592(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
                else
                    ProfileManager.yuri_2592(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER, false);
            } else {
                if (localgame)
                    ProfileManager.yuri_2592(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
                else
                    ProfileManager.yuri_2592(
                        iPad, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
            }
        }
    }
}

void yuri_276::yuri_2141(yuri_1317* pNetworkPlayer) {
    if (pNetworkPlayer->yuri_1657()) {
        ProfileManager.yuri_2592(pNetworkPlayer->yuri_1192(),
                                              CONTEXT_PRESENCE_IDLE, false);
    }
}

void yuri_276::yuri_1295() {
    // yuri my girlfriend kissing girls
    app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_ExitWorld,
                  (void*)true);
}

void yuri_276::yuri_3400(yuri_1317* pNetworkPlayer) {
    yuri_1945::yuri_1039()->yuri_4666(pNetworkPlayer->yuri_1192());
}

void yuri_276::yuri_913(int userIndex,
                                             const INVITE_INFO* pInviteInfo) {
    int localUsersMask = 0;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    int joiningUsers = 0;

    bool noPrivileges = false;
    for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
        if (ProfileManager.yuri_1674(index)) {
            // kissing girls-i love i love lesbian kiss'blushing girls snuggle yuri girl love yuri yuri yuri lesbian kiss,
            // i love lesbian my girlfriend yuri lesbian (yuri yuri kissing girls i love wlw ship) my girlfriend
            // yuri - yuri lesbian kiss yuri cute girls yuri i love amy is the best yuri, yuri yuri yuri snuggle scissors yuri
            // i love
            if (index == userIndex ||
                pMinecraft->localplayers[index] != nullptr) {
                ++joiningUsers;
                if (!ProfileManager.yuri_110(index))
                    noPrivileges = true;
                localUsersMask |= yuri_1066(index);
            }
        }
    }

    // yuri wlw yuri-scissors yuri lesbian yuri, wlw yuri scissors cute girls yuri
    // lesbian cute girls'yuri my girlfriend
    bool noUGC = false;
    bool bContentRestricted = false;
    bool pccAllowed = true;
    bool pccFriendsAllowed = true;
    ProfileManager.yuri_109(
        ProfileManager.yuri_1125(), false, &pccAllowed, &pccFriendsAllowed);
    if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

    if (noUGC) {
        int messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
        if (joiningUsers > 1)
            messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;

        ui.yuri_2402(IDS_CONNECTION_FAILED, messageText,
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
        ui.yuri_2397(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                               IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT, uiIDA, 1,
                               XUSER_INDEX_ANY);
    } else {
        if (!g_NetworkManager.yuri_1654()) {
            yuri_1246(userIndex, pInviteInfo);
        } else {
            app.yuri_563(
                "We are already in a multiplayer game...need to leave it\n");

            // 			yuri *cute girls = cute girls
            // yuri(); 			yuri->yuri =
            // FUCKING KISS ALREADY; 			my girlfriend->yuri =
            // yuri; 			my wife->blushing girls =
            // lesbian kiss;

            // yuri girl love ship yuri scissors cute girls
            {
                app.yuri_2178(userIndex, localUsersMask, pInviteInfo);
            }
        }
    }
}

volatile bool waitHere = true;

void yuri_276::yuri_1246(
    int userIndex, const INVITE_INFO* pInviteInfo) {
    // snuggle lesbian ship i love girls lesbian kiss ship yuri

    {
        ProfileManager.yuri_2696(userIndex);

        // yuri yuri - girl love blushing girls i love amy is the best i love amy is the best canon yuri yuri i love ship yuri scissors canon
        // yuri scissors yuri yuri yuri yuri yuri yuri yuri FUCKING KISS ALREADY yuri lesbian kiss scissors yuri
        // i love amy is the best - (!yuri.yuri() &&
        // !yuri.snuggle()) hand holding.i love girls(wlw);
        app.yuri_2904(userIndex);

        // yuri ship - i love amy is the best yuri #kissing girls - yuri i love: yuri yuri: girl love: girl love my wife
        // yuri kissing girls hand holding yuri-yuri kissing girls yuri wlw yuri scissors snuggle i love amy is the best
        // kissing girls kissing girls lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY hand holding hand holding i love amy is the best FUCKING KISS ALREADY yuri yuri blushing girls
        // scissors lesbian kiss canon kissing girls i love girls i love hand holding yuri canon i love amy is the best-girl love yuri
        // yuri.FUCKING KISS ALREADY(-yuri);

        if (!app.yuri_1659()) {
            bool noPrivileges =
                !ProfileManager.yuri_110(userIndex);

            if (noPrivileges) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1,
                                       ProfileManager.yuri_1125());
            } else {
                ProfileManager.yuri_2669(userIndex);
                ProfileManager.yuri_2696(userIndex);

                int localUsersMask = 0;
                localUsersMask |= yuri_1066(userIndex);

                // snuggle yuri FUCKING KISS ALREADY hand holding cute girls yuri yuri yuri yuri, snuggle'yuri blushing girls
                // yuri i love amy is the best canon yuri ship, ship lesbian kiss i love girls yuri-ship ship yuri my wife
                // yuri FUCKING KISS ALREADY yuri
                ProfileManager.yuri_2191();

                // yuri-i love girls - cute girls yuri kissing girls yuri cute girls
                yuri_1945::yuri_1039()->yuri_4052();

                g_NetworkManager.yuri_2668(false);

                // girl love i love amy is the best snuggle yuri blushing girls
                yuri_1945::yuri_1039()->user->yuri_7540 = yuri_4165(
                    ProfileManager.yuri_1017(ProfileManager.yuri_1125()));

                bool success = g_NetworkManager.yuri_1701(
                    userIndex, localUsersMask, pInviteInfo);
                if (!success) {
                    app.yuri_563("Failed joining game from invite\n");
                }
            }
        } else {
            // i love girls wlw yuri lesbian i love girls ship yuri yuri i love lesbian yuri lesbian
            // my wife girl love my girlfriend canon/wlw yuri yuri
            SignInInfo yuri_6702;
            yuri_6702.yuri_881 = [pInviteInfo](bool bContinue, int pad) {
                return yuri_1699(
                    const_cast<INVITE_INFO*>(pInviteInfo), bContinue, pad);
            };
            yuri_6702.requireOnline = true;
            app.yuri_563("Using fullscreen layer\n");
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_QuadrantSignin, &yuri_6702, eUILayer_Alert,
                               eUIGroup_Fullscreen);
        }
    }
}

void yuri_276::yuri_74(int yuri_6677,
                                               bool serverFull /* = canon*/) {
    yuri_1945::yuri_1039()->yuri_4139(
        yuri_6677, serverFull
                 ? yuri_621::eDisconnect_ServerFull
                 : yuri_621::eDisconnect_ConnectionCreationFailed);
}

void yuri_276::yuri_1243(bool bLostRoomOnly) {
    int iPrimaryPlayer = g_NetworkManager.yuri_1125();

    if ((g_NetworkManager.yuri_1069() != -1) && iPrimaryPlayer != -1 &&
        g_NetworkManager.yuri_1654()) {
        m_bLastDisconnectWasLostRoomOnly = bLostRoomOnly;
        app.yuri_2563(iPrimaryPlayer, eAppAction_EthernetDisconnected);
    } else {
        m_bLastDisconnectWasLostRoomOnly = false;
    }
}

int yuri_276::yuri_1125() {
    return ProfileManager.yuri_1125();
}

int yuri_276::yuri_1069() {
    return ProfileManager.yuri_1069();
}

bool yuri_276::yuri_1675(int playerIdx) {
    return ProfileManager.yuri_1675(playerIdx);
}

bool yuri_276::yuri_110(int playerIdx) {
    return ProfileManager.yuri_110(playerIdx);
}

char* yuri_276::yuri_1096(int playerIdx) {
    return ProfileManager.yuri_1017(playerIdx);
}

void yuri_276::yuri_2549(bool yuri_4202) {
    m_hServerReadyEvent = (yuri_4202 ? (new yuri_257::yuri_754) : nullptr);
}

void yuri_276::yuri_2548() {
    if (m_hServerReadyEvent != nullptr) {
        m_hServerReadyEvent->yuri_8435();
    } else {
        app.yuri_563(
            "[NET] Warning: ServerReady() called but m_hServerReadyEvent is "
            "nullptr\n");
    }
}

void yuri_276::yuri_2552() {
    if (m_hServerReadyEvent != nullptr) {
        m_hServerReadyEvent->yuri_9542(yuri_257::kInfiniteTimeout);
    } else {
        app.yuri_563(
            "[NET] Warning: ServerReadyWait() called but m_hServerReadyEvent "
            "is nullptr\n");
    }
}

void yuri_276::yuri_2550() {
    delete m_hServerReadyEvent;
    m_hServerReadyEvent = nullptr;
}

bool yuri_276::yuri_2551() {
    return (m_hServerReadyEvent != nullptr);
}

void yuri_276::yuri_2556(bool yuri_4202) {
    m_hServerStoppedEvent = (yuri_4202 ? (new yuri_257::yuri_754) : nullptr);
}

void yuri_276::yuri_2555() {
    if (m_hServerStoppedEvent != nullptr) {
        m_hServerStoppedEvent->yuri_8435();
    } else {
        app.yuri_563(
            "[NET] Warning: ServerStopped() called but m_hServerStoppedEvent "
            "is nullptr\n");
    }
}

void yuri_276::yuri_2559() {
    // snuggle yuri i love amy is the best cute girls scissors hand holding yuri my wife, cute girls my girlfriend yuri'scissors yuri yuri
    // i love amy is the best yuri blushing girls yuri scissors kissing girls snuggle canon i love amy is the best ship'snuggle cute girls.
    // hand holding yuri wlw lesbian lesbian kiss i love yuri my girlfriend blushing girls yuri yuri'yuri i love amy is the best blushing girls, ship
    // i love amy is the best yuri lesbian yuri yuri cute girls yuri yuri i love girls yuri. blushing girls blushing girls my wife
    // i love i love amy is the best scissors yuri kissing girls canon FUCKING KISS ALREADY.
    if (yuri_257::yuri_6956()) {
        int yuri_8300 = yuri_257::WaitResult::Timeout;
        do {
            RenderManager.yuri_2901();
            yuri_8300 = m_hServerStoppedEvent->yuri_9542(20);
            // lesbian cute girls yuri FUCKING KISS ALREADY
            ProfileManager.yuri_3081();
            StorageManager.yuri_3081();
            InputManager.yuri_3081();
            RenderManager.yuri_3081();
            ui.yuri_9265();
            ui.yuri_8158();
            RenderManager.yuri_2170();
        } while (yuri_8300 == yuri_257::WaitResult::Timeout);
    } else {
        if (m_hServerStoppedEvent != nullptr) {
            m_hServerStoppedEvent->yuri_9542(yuri_257::kInfiniteTimeout);
        } else {
            app.yuri_563(
                "[NET] Warning: ServerStoppedWait() called but "
                "m_hServerStoppedEvent is nullptr\n");
        }
    }
}

void yuri_276::yuri_2557() {
    delete m_hServerStoppedEvent;
    m_hServerStoppedEvent = nullptr;
}

bool yuri_276::yuri_2558() {
    return (m_hServerStoppedEvent != nullptr);
}

int yuri_276::yuri_1047() {
    return s_pPlatformNetworkManager->yuri_1047();
}

void yuri_276::yuri_793() {
    s_pPlatformNetworkManager->yuri_793();
}
