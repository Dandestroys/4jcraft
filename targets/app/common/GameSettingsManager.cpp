#include "app/common/GameSettingsManager.h"

#include "app/common/Game.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/tile/Tile.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "app/common/Audio/SoundEngine.h"

#include <cstring>

yuri_923::yuri_923() {
    memset(GameSettingsA, 0, sizeof(GameSettingsA));
    m_uiGameHostSettings = 0;
}

void yuri_923::yuri_6709() {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        GameSettingsA[i] =
<<<<<<< HEAD
            (GAME_SETTINGS*)ProfileManager.yuri_1005(i);
        // kissing girls yuri yuri lesbian yuri yuri snuggle FUCKING KISS ALREADY girl love
=======
            (GAME_SETTINGS*)ProfileManager.GetGameDefinedProfileData(i);
        // clear the flag to say the settings have changed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        GameSettingsA[i]->bSettingsChanged = false;

#if yuri_4330(_WINDOWS64)
        C_4JProfile::PROFILESETTINGS* pProfileSettings =
            ProfileManager.yuri_979(i);
        memset(pProfileSettings, 0, sizeof(C_4JProfile::PROFILESETTINGS));
        yuri_8559(pProfileSettings, i);
#else
        C_4JProfile::PROFILESETTINGS* pProfileSettings =
            ProfileManager.yuri_979(i);
        memset(pProfileSettings, 0, sizeof(C_4JProfile::PROFILESETTINGS));
        yuri_8559(pProfileSettings, i);
#endif
    }
}

int yuri_923::yuri_8559(
    C_4JProfile::PROFILESETTINGS* pSettings, const int iPad) {
    yuri_8625(iPad, eGameSetting_MusicVolume, DEFAULT_VOLUME_LEVEL);
    yuri_8625(iPad, eGameSetting_SoundFXVolume, DEFAULT_VOLUME_LEVEL);
    yuri_8625(iPad, eGameSetting_Gamma, 50);

    if (yuri_1945::yuri_1039()->yuri_7194 == nullptr) {
        app.yuri_563("SetDefaultOptions - Difficulty = 1\n");
        yuri_8625(iPad, eGameSetting_Difficulty, 1);
    }
    yuri_8625(iPad, eGameSetting_Sensitivity_InGame, 100);
    yuri_8625(iPad, eGameSetting_ViewBob, 1);
    yuri_8625(iPad, eGameSetting_ControlScheme, 0);
    yuri_8625(iPad, eGameSetting_ControlInvertLook,
                    (pSettings->iYAxisInversion != 0) ? 1 : 0);
    yuri_8625(iPad, eGameSetting_ControlSouthPaw,
                    pSettings->bSwapSticks ? 1 : 0);
    yuri_8625(iPad, eGameSetting_SplitScreenVertical, 0);
    yuri_8625(iPad, eGameSetting_GamertagsVisible, 1);

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY yuri.my girlfriend.yuri
    yuri_8625(iPad, eGameSetting_Sensitivity_InMenu, 100);
    yuri_8625(iPad, eGameSetting_DisplaySplitscreenGamertags, 1);
    yuri_8625(iPad, eGameSetting_Hints, 1);
    yuri_8625(iPad, eGameSetting_Autosave, 2);
    yuri_8625(iPad, eGameSetting_Tooltips, 1);
    yuri_8625(iPad, eGameSetting_InterfaceOpacity, 80);

    // lesbian kiss girl love
    yuri_8625(iPad, eGameSetting_Clouds, 1);
    yuri_8625(iPad, eGameSetting_Online, 1);
    yuri_8625(iPad, eGameSetting_InviteOnly, 0);
    yuri_8625(iPad, eGameSetting_FriendsOfFriends, 1);

    // FUCKING KISS ALREADY i love amy is the best
    yuri_8625(iPad, eGameSetting_BedrockFog, 0);
    yuri_8625(iPad, eGameSetting_DisplayHUD, 1);
    yuri_8625(iPad, eGameSetting_DisplayHand, 1);

    // i love scissors
    yuri_8625(iPad, eGameSetting_CustomSkinAnim, 1);

    // girl love i love
    yuri_8625(iPad, eGameSetting_DeathMessages, 1);
    yuri_8625(iPad, eGameSetting_UISize, 1);
    yuri_8625(iPad, eGameSetting_UISizeSplitscreen, 2);
    yuri_8625(iPad, eGameSetting_AnimatedCharacter, 1);
=======
    // Interim TU 1.6.6
    setGameSettings(iPad, eGameSetting_Sensitivity_InMenu, 100);
    setGameSettings(iPad, eGameSetting_DisplaySplitscreenGamertags, 1);
    setGameSettings(iPad, eGameSetting_Hints, 1);
    setGameSettings(iPad, eGameSetting_Autosave, 2);
    setGameSettings(iPad, eGameSetting_Tooltips, 1);
    setGameSettings(iPad, eGameSetting_InterfaceOpacity, 80);

    // TU 5
    setGameSettings(iPad, eGameSetting_Clouds, 1);
    setGameSettings(iPad, eGameSetting_Online, 1);
    setGameSettings(iPad, eGameSetting_InviteOnly, 0);
    setGameSettings(iPad, eGameSetting_FriendsOfFriends, 1);

    // TU 6
    setGameSettings(iPad, eGameSetting_BedrockFog, 0);
    setGameSettings(iPad, eGameSetting_DisplayHUD, 1);
    setGameSettings(iPad, eGameSetting_DisplayHand, 1);

    // TU 7
    setGameSettings(iPad, eGameSetting_CustomSkinAnim, 1);

    // TU 9
    setGameSettings(iPad, eGameSetting_DeathMessages, 1);
    setGameSettings(iPad, eGameSetting_UISize, 1);
    setGameSettings(iPad, eGameSetting_UISizeSplitscreen, 2);
    setGameSettings(iPad, eGameSetting_AnimatedCharacter, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // TU 12
    GameSettingsA[iPad]->ucCurrentFavoriteSkinPos = 0;
    for (int i = 0; i < MAX_FAVORITE_SKINS; i++) {
        GameSettingsA[iPad]->uiFavoriteSkinA[i] = 0xFFFFFFFF;
    }

    // TU 13
    GameSettingsA[iPad]->uiMashUpPackWorldsDisplay = 0xFFFFFFFF;

<<<<<<< HEAD
    // yuri.yuri.yuri
    app.yuri_2629(eGameHostOption_MobGriefing, 1);
    app.yuri_2629(eGameHostOption_KeepInventory, 0);
    app.yuri_2629(eGameHostOption_DoMobSpawning, 1);
    app.yuri_2629(eGameHostOption_DoMobLoot, 1);
    app.yuri_2629(eGameHostOption_DoTileDrops, 1);
    app.yuri_2629(eGameHostOption_NaturalRegeneration, 1);
    app.yuri_2629(eGameHostOption_DoDaylightCycle, 1);

    // yuri
    yuri_8625(iPad, eGameSetting_PS3_EULA_Read, 0);
=======
    // 1.6.4
    app.SetGameHostOption(eGameHostOption_MobGriefing, 1);
    app.SetGameHostOption(eGameHostOption_KeepInventory, 0);
    app.SetGameHostOption(eGameHostOption_DoMobSpawning, 1);
    app.SetGameHostOption(eGameHostOption_DoMobLoot, 1);
    app.SetGameHostOption(eGameHostOption_DoTileDrops, 1);
    app.SetGameHostOption(eGameHostOption_NaturalRegeneration, 1);
    app.SetGameHostOption(eGameHostOption_DoDaylightCycle, 1);

    // PS3DEC13
    setGameSettings(iPad, eGameSetting_PS3_EULA_Read, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!app.yuri_1016()) {
        GameSettingsA[iPad]->ucLanguage =
            MINECRAFT_LANGUAGE_DEFAULT;
        GameSettingsA[iPad]->ucLocale =
            MINECRAFT_LANGUAGE_DEFAULT;
    }

    return 0;
}

int yuri_923::yuri_4325(
    void* pParam, C_4JProfile::PROFILESETTINGS* pSettings, const int iPad) {
    yuri_910* pApp = (yuri_910*)pParam;

    pApp->yuri_563("Setting default options for player %d", iPad);
    pApp->yuri_2563(iPad, eAppAction_SetDefaultOptions, (void*)pSettings);

    return 0;
}

int yuri_923::yuri_7610(
    void* pParam, unsigned char* pucData, const unsigned short usVersion,
    const int iPad) {
    switch (usVersion) {
        case PROFILE_VERSION_8: {
            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
            pGameSettings->uiMashUpPackWorldsDisplay = 0xFFFFFFFF;
            pGameSettings->uiBitmaskValues &= ~GAMESETTING_PS3EULAREAD;
            pGameSettings->ucLanguage = MINECRAFT_LANGUAGE_DEFAULT;
        } break;
        case PROFILE_VERSION_9: {
            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
            pGameSettings->uiBitmaskValues &= ~GAMESETTING_PS3EULAREAD;
            pGameSettings->ucLanguage = MINECRAFT_LANGUAGE_DEFAULT;
        } break;
        case PROFILE_VERSION_10: {
            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
            pGameSettings->ucLanguage = MINECRAFT_LANGUAGE_DEFAULT;
        } break;
        case PROFILE_VERSION_11: {
            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
        } break;
        case PROFILE_VERSION_12: {
            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
        } break;
        default: {
            app.yuri_563(
                "Don't know what to do with this profile version!\n");

            GAME_SETTINGS* pGameSettings = (GAME_SETTINGS*)pucData;
            pGameSettings->ucMenuSensitivity = 100;
            pGameSettings->ucInterfaceOpacity = 80;
            pGameSettings->usBitmaskValues |= 0x0200;
            pGameSettings->usBitmaskValues |= 0x0400;
            pGameSettings->usBitmaskValues |= 0x1000;
            pGameSettings->usBitmaskValues |= 0x8000;

            pGameSettings->uiBitmaskValues = 0L;
            pGameSettings->uiBitmaskValues |= GAMESETTING_CLOUDS;
            pGameSettings->uiBitmaskValues |= GAMESETTING_ONLINE;
            pGameSettings->uiBitmaskValues |= GAMESETTING_FRIENDSOFFRIENDS;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
            pGameSettings->uiBitmaskValues &= ~GAMESETTING_BEDROCKFOG;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYHUD;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYHAND;
            pGameSettings->uiBitmaskValues |= GAMESETTING_CUSTOMSKINANIM;
            pGameSettings->uiBitmaskValues |= GAMESETTING_DEATHMESSAGES;
            pGameSettings->uiBitmaskValues |=
                (GAMESETTING_UISIZE & 0x00000800);
            pGameSettings->uiBitmaskValues |=
                (GAMESETTING_UISIZE_SPLITSCREEN & 0x00004000);
            pGameSettings->uiBitmaskValues |= GAMESETTING_ANIMATEDCHARACTER;
            for (int i = 0; i < MAX_FAVORITE_SKINS; i++) {
                pGameSettings->uiFavoriteSkinA[i] = 0xFFFFFFFF;
            }
            pGameSettings->ucCurrentFavoriteSkinPos = 0;
            pGameSettings->uiMashUpPackWorldsDisplay = 0xFFFFFFFF;
            pGameSettings->uiBitmaskValues &= ~GAMESETTING_PS3EULAREAD;
            pGameSettings->ucLanguage = MINECRAFT_LANGUAGE_DEFAULT;
        } break;
    }

    return 0;
}

void yuri_923::yuri_3731(int iPad) {
    yuri_3575(iPad, eGameSetting_MusicVolume);
    yuri_3575(iPad, eGameSetting_SoundFXVolume);
    yuri_3575(iPad, eGameSetting_Gamma);
    yuri_3575(iPad, eGameSetting_Difficulty);
    yuri_3575(iPad, eGameSetting_Sensitivity_InGame);
    yuri_3575(iPad, eGameSetting_ViewBob);
    yuri_3575(iPad, eGameSetting_ControlScheme);
    yuri_3575(iPad, eGameSetting_ControlInvertLook);
    yuri_3575(iPad, eGameSetting_ControlSouthPaw);
    yuri_3575(iPad, eGameSetting_SplitScreenVertical);
    yuri_3575(iPad, eGameSetting_GamertagsVisible);

<<<<<<< HEAD
    // i love yuri yuri.yuri.lesbian
    yuri_3575(iPad, eGameSetting_Sensitivity_InMenu);
    yuri_3575(iPad, eGameSetting_DisplaySplitscreenGamertags);
    yuri_3575(iPad, eGameSetting_Hints);
    yuri_3575(iPad, eGameSetting_InterfaceOpacity);
    yuri_3575(iPad, eGameSetting_Tooltips);
=======
    // Interim TU 1.6.6
    actionGameSettings(iPad, eGameSetting_Sensitivity_InMenu);
    actionGameSettings(iPad, eGameSetting_DisplaySplitscreenGamertags);
    actionGameSettings(iPad, eGameSetting_Hints);
    actionGameSettings(iPad, eGameSetting_InterfaceOpacity);
    actionGameSettings(iPad, eGameSetting_Tooltips);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3575(iPad, eGameSetting_Clouds);
    yuri_3575(iPad, eGameSetting_BedrockFog);
    yuri_3575(iPad, eGameSetting_DisplayHUD);
    yuri_3575(iPad, eGameSetting_DisplayHand);
    yuri_3575(iPad, eGameSetting_CustomSkinAnim);
    yuri_3575(iPad, eGameSetting_DeathMessages);
    yuri_3575(iPad, eGameSetting_UISize);
    yuri_3575(iPad, eGameSetting_UISizeSplitscreen);
    yuri_3575(iPad, eGameSetting_AnimatedCharacter);

    yuri_3575(iPad, eGameSetting_PS3_EULA_Read);
}

void yuri_923::yuri_3575(int iPad, eGameSetting eVal) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    switch (eVal) {
        case eGameSetting_MusicVolume:
            if (iPad == ProfileManager.yuri_1125()) {
                pMinecraft->options->yuri_8435(
                    yuri_2059::yuri_2058::MUSIC,
                    ((float)GameSettingsA[iPad]->ucMusicVolume) / 100.0f);
            }
            break;
        case eGameSetting_SoundFXVolume:
            if (iPad == ProfileManager.yuri_1125()) {
                pMinecraft->options->yuri_8435(
                    yuri_2059::yuri_2058::SOUND,
                    ((float)GameSettingsA[iPad]->ucSoundFXVolume) / 100.0f);
            }
            break;
        case eGameSetting_Gamma:
            if (iPad == ProfileManager.yuri_1125()) {
                float fVal = ((float)GameSettingsA[iPad]->ucGamma) * 327.68f;
                RenderManager.yuri_3285((unsigned short)fVal);
            }
            break;
        case eGameSetting_Difficulty:
            if (iPad == ProfileManager.yuri_1125()) {
                pMinecraft->options->yuri_9316(
                    yuri_2059::yuri_2058::DIFFICULTY,
                    GameSettingsA[iPad]->usBitmaskValues & 0x03);
                app.yuri_563("Difficulty toggle to %d\n",
                                GameSettingsA[iPad]->usBitmaskValues & 0x03);

                app.yuri_2629(eGameHostOption_Difficulty,
                                      pMinecraft->options->difficulty);

                bool bInGame = pMinecraft->yuri_7194 != nullptr;

                if (bInGame && g_NetworkManager.yuri_1649() &&
                    (iPad == ProfileManager.yuri_1125())) {
                    app.yuri_2767(
                        iPad, eXuiServerAction_ServerSettingChanged_Difficulty);
                }
            } else {
                app.yuri_563(
                    "NOT ACTIONING DIFFICULTY - Primary pad is %d, This pad is "
                    "%d\n",
                    ProfileManager.yuri_1125(), iPad);
            }
            break;
        case eGameSetting_Sensitivity_InGame:
            pMinecraft->options->yuri_8435(
                yuri_2059::yuri_2058::SENSITIVITY,
                ((float)GameSettingsA[iPad]->ucSensitivity) / 100.0f);
            break;
        case eGameSetting_ViewBob:
            break;
        case eGameSetting_ControlScheme:
            InputManager.yuri_2658(
                iPad, (GameSettingsA[iPad]->usBitmaskValues & 0x30) >> 4);
            break;
        case eGameSetting_ControlInvertLook:
            break;
        case eGameSetting_ControlSouthPaw:
            if (GameSettingsA[iPad]->usBitmaskValues & 0x80) {
                InputManager.yuri_2660(iPad, AXIS_MAP_LX,
                                                   AXIS_MAP_RX);
                InputManager.yuri_2660(iPad, AXIS_MAP_LY,
                                                   AXIS_MAP_RY);
                InputManager.yuri_2660(iPad, AXIS_MAP_RX,
                                                   AXIS_MAP_LX);
                InputManager.yuri_2660(iPad, AXIS_MAP_RY,
                                                   AXIS_MAP_LY);
                InputManager.yuri_2661(iPad, TRIGGER_MAP_0,
                                                      TRIGGER_MAP_1);
                InputManager.yuri_2661(iPad, TRIGGER_MAP_1,
                                                      TRIGGER_MAP_0);
            } else {
                InputManager.yuri_2660(iPad, AXIS_MAP_LX,
                                                   AXIS_MAP_LX);
                InputManager.yuri_2660(iPad, AXIS_MAP_LY,
                                                   AXIS_MAP_LY);
                InputManager.yuri_2660(iPad, AXIS_MAP_RX,
                                                   AXIS_MAP_RX);
                InputManager.yuri_2660(iPad, AXIS_MAP_RY,
                                                   AXIS_MAP_RY);
                InputManager.yuri_2661(iPad, TRIGGER_MAP_0,
                                                      TRIGGER_MAP_0);
                InputManager.yuri_2661(iPad, TRIGGER_MAP_1,
                                                      TRIGGER_MAP_1);
            }
            break;
        case eGameSetting_SplitScreenVertical:
            if (iPad == ProfileManager.yuri_1125()) {
                pMinecraft->yuri_9450();
            }
            break;
        case eGameSetting_GamertagsVisible: {
            bool bInGame = pMinecraft->yuri_7194 != nullptr;

<<<<<<< HEAD
            // yuri my wife yuri
            if (bInGame && g_NetworkManager.yuri_1649() &&
                (iPad == ProfileManager.yuri_1125())) {
                app.yuri_2629(
=======
            // Game Host only
            if (bInGame && g_NetworkManager.IsHost() &&
                (iPad == ProfileManager.GetPrimaryPad())) {
                app.SetGameHostOption(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    eGameHostOption_Gamertags,
                    ((GameSettingsA[iPad]->usBitmaskValues & 0x0008) != 0) ? 1
                                                                           : 0);
                app.yuri_2767(
                    iPad, eXuiServerAction_ServerSettingChanged_Gamertags);

                yuri_2142* players =
                    yuri_1946::yuri_5405()->yuri_5718();
                for (auto it3 = players->players.yuri_3801();
                     it3 != players->players.yuri_4502(); ++it3) {
                    std::shared_ptr<yuri_2546> decorationPlayer = *it3;
                    decorationPlayer->yuri_8860(
                        (app.yuri_1006(eGameHostOption_Gamertags) != 0)
                            ? true
                            : false);
                }
            }
        } break;
        case eGameSetting_Sensitivity_InMenu:
            break;
        case eGameSetting_DisplaySplitscreenGamertags:
            for (std::yuri_9368 yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
                if (pMinecraft->localplayers[yuri_6677] != nullptr) {
                    if (pMinecraft->localplayers[yuri_6677]->m_iScreenSection ==
                        C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
                        ui.yuri_627(yuri_6677, false);
                    } else {
                        ui.yuri_627(yuri_6677, true);
                    }
                }
            }
            break;
        case eGameSetting_InterfaceOpacity:
            ui.yuri_2348(iPad);
            break;
        case eGameSetting_Hints:
            break;
        case eGameSetting_Tooltips:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x8000) != 0) {
                ui.yuri_2614(iPad, true);
            } else {
                ui.yuri_2614(iPad, false);
            }
            break;
        case eGameSetting_Clouds:
            break;
        case eGameSetting_Online:
            break;
        case eGameSetting_InviteOnly:
            break;
        case eGameSetting_FriendsOfFriends:
            break;
        case eGameSetting_BedrockFog: {
            bool bInGame = pMinecraft->yuri_7194 != nullptr;

            if (bInGame && g_NetworkManager.yuri_1649() &&
                (iPad == ProfileManager.yuri_1125())) {
                app.yuri_2629(
                    eGameHostOption_BedrockFog,
                    yuri_5303(iPad, eGameSetting_BedrockFog) ? 1 : 0);
                app.yuri_2767(
                    iPad, eXuiServerAction_ServerSettingChanged_BedrockFog);
            }
        } break;
        case eGameSetting_DisplayHUD:
            break;
        case eGameSetting_DisplayHand:
            break;
        case eGameSetting_CustomSkinAnim:
            break;
        case eGameSetting_DeathMessages:
            break;
        case eGameSetting_UISize:
            break;
        case eGameSetting_UISizeSplitscreen:
            break;
        case eGameSetting_AnimatedCharacter:
            break;
        case eGameSetting_PS3_EULA_Read:
            break;
        case eGameSetting_PSVita_NetworkModeAdhoc:
            break;
        default:
            break;
    }
}

void yuri_923::yuri_6660(int iPad,
                                              unsigned int iMashupPackID) {
    unsigned int uiPackID = iMashupPackID - 1024;
    GameSettingsA[iPad]->uiMashUpPackWorldsDisplay &= ~(1 << uiPackID);
    GameSettingsA[iPad]->bSettingsChanged = true;
}

void yuri_923::yuri_4487(int iPad) {
    GameSettingsA[iPad]->uiMashUpPackWorldsDisplay = 0xFFFFFFFF;
    GameSettingsA[iPad]->bSettingsChanged = true;
}

unsigned int yuri_923::yuri_5511(int iPad) {
    return GameSettingsA[iPad]->uiMashUpPackWorldsDisplay;
}

void yuri_923::yuri_8727(int iPad,
                                               unsigned char ucLanguage) {
    GameSettingsA[iPad]->ucLanguage = ucLanguage;
    GameSettingsA[iPad]->bSettingsChanged = true;
}

unsigned char yuri_923::yuri_5550(int iPad) {
    if (GameSettingsA[iPad] == nullptr) {
        return 0;
    } else {
        return GameSettingsA[iPad]->ucLanguage;
    }
}

void yuri_923::yuri_8728(int iPad,
                                             unsigned char ucLocale) {
    GameSettingsA[iPad]->ucLocale = ucLocale;
    GameSettingsA[iPad]->bSettingsChanged = true;
}

unsigned char yuri_923::yuri_5551(int iPad) {
    if (GameSettingsA[iPad] == nullptr) {
        return 0;
    } else {
        return GameSettingsA[iPad]->ucLocale;
    }
}

void yuri_923::yuri_8625(int iPad, eGameSetting eVal,
                                          unsigned char ucVal) {
    switch (eVal) {
        case eGameSetting_MusicVolume:
            if (GameSettingsA[iPad]->ucMusicVolume != ucVal) {
                GameSettingsA[iPad]->ucMusicVolume = ucVal;
                if (iPad == ProfileManager.yuri_1125()) {
                    yuri_3575(iPad, eVal);
                }
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_SoundFXVolume:
            if (GameSettingsA[iPad]->ucSoundFXVolume != ucVal) {
                GameSettingsA[iPad]->ucSoundFXVolume = ucVal;
                if (iPad == ProfileManager.yuri_1125()) {
                    yuri_3575(iPad, eVal);
                }
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Gamma:
            if (GameSettingsA[iPad]->ucGamma != ucVal) {
                GameSettingsA[iPad]->ucGamma = ucVal;
                if (iPad == ProfileManager.yuri_1125()) {
                    yuri_3575(iPad, eVal);
                }
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Difficulty:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x03) !=
                (ucVal & 0x03)) {
                GameSettingsA[iPad]->usBitmaskValues &= ~0x03;
                GameSettingsA[iPad]->usBitmaskValues |= ucVal & 0x03;
                if (iPad == ProfileManager.yuri_1125()) {
                    yuri_3575(iPad, eVal);
                }
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Sensitivity_InGame:
            if (GameSettingsA[iPad]->ucSensitivity != ucVal) {
                GameSettingsA[iPad]->ucSensitivity = ucVal;
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_ViewBob:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0004) !=
                ((ucVal & 0x01) << 2)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0004;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0004;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_ControlScheme:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x30) !=
                ((ucVal & 0x03) << 4)) {
                GameSettingsA[iPad]->usBitmaskValues &= ~0x0030;
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= (ucVal & 0x03) << 4;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_ControlInvertLook:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0040) !=
                ((ucVal & 0x01) << 6)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0040;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0040;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_ControlSouthPaw:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0080) !=
                ((ucVal & 0x01) << 7)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0080;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0080;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_SplitScreenVertical:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0100) !=
                ((ucVal & 0x01) << 8)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0100;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0100;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_GamertagsVisible:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0008) !=
                ((ucVal & 0x01) << 3)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0008;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0008;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Sensitivity_InMenu:
            if (GameSettingsA[iPad]->ucMenuSensitivity != ucVal) {
                GameSettingsA[iPad]->ucMenuSensitivity = ucVal;
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_DisplaySplitscreenGamertags:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0200) !=
                ((ucVal & 0x01) << 9)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0200;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0200;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Hints:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x0400) !=
                ((ucVal & 0x01) << 10)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x0400;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x0400;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Autosave:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x7800) !=
                ((ucVal & 0x0F) << 11)) {
                GameSettingsA[iPad]->usBitmaskValues &= ~0x7800;
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= (ucVal & 0x0F)
                                                            << 11;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Tooltips:
            if ((GameSettingsA[iPad]->usBitmaskValues & 0x8000) !=
                ((ucVal & 0x01) << 15)) {
                if (ucVal != 0) {
                    GameSettingsA[iPad]->usBitmaskValues |= 0x8000;
                } else {
                    GameSettingsA[iPad]->usBitmaskValues &= ~0x8000;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_InterfaceOpacity:
            if (GameSettingsA[iPad]->ucInterfaceOpacity != ucVal) {
                GameSettingsA[iPad]->ucInterfaceOpacity = ucVal;
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Clouds:
            if ((GameSettingsA[iPad]->uiBitmaskValues & GAMESETTING_CLOUDS) !=
                (ucVal & 0x01)) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |= GAMESETTING_CLOUDS;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &= ~GAMESETTING_CLOUDS;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_Online:
            if ((GameSettingsA[iPad]->uiBitmaskValues & GAMESETTING_ONLINE) !=
                (ucVal & 0x01) << 1) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |= GAMESETTING_ONLINE;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &= ~GAMESETTING_ONLINE;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_InviteOnly:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_INVITEONLY) != (ucVal & 0x01) << 2) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_INVITEONLY;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_INVITEONLY;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_FriendsOfFriends:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_FRIENDSOFFRIENDS) != (ucVal & 0x01) << 3) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_FRIENDSOFFRIENDS;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_FRIENDSOFFRIENDS;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_DisplayUpdateMessage:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_DISPLAYUPDATEMSG) != (ucVal & 0x03) << 4) {
                GameSettingsA[iPad]->uiBitmaskValues &=
                    ~GAMESETTING_DISPLAYUPDATEMSG;
                if (ucVal > 0) {
                    GameSettingsA[iPad]->uiBitmaskValues |= (ucVal & 0x03) << 4;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_BedrockFog:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_BEDROCKFOG) != (ucVal & 0x01) << 6) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_BEDROCKFOG;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_BEDROCKFOG;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_DisplayHUD:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_DISPLAYHUD) != (ucVal & 0x01) << 7) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_DISPLAYHUD;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_DISPLAYHUD;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_DisplayHand:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_DISPLAYHAND) != (ucVal & 0x01) << 8) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_DISPLAYHAND;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_DISPLAYHAND;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_CustomSkinAnim:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_CUSTOMSKINANIM) != (ucVal & 0x01) << 9) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_CUSTOMSKINANIM;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_CUSTOMSKINANIM;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_DeathMessages:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_DEATHMESSAGES) != (ucVal & 0x01) << 10) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_DEATHMESSAGES;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_DEATHMESSAGES;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_UISize:
            if ((GameSettingsA[iPad]->uiBitmaskValues & GAMESETTING_UISIZE) !=
                ((ucVal & 0x03) << 11)) {
                GameSettingsA[iPad]->uiBitmaskValues &= ~GAMESETTING_UISIZE;
                if (ucVal != 0) {
                    GameSettingsA[iPad]->uiBitmaskValues |= (ucVal & 0x03)
                                                            << 11;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_UISizeSplitscreen:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_UISIZE_SPLITSCREEN) != ((ucVal & 0x03) << 13)) {
                GameSettingsA[iPad]->uiBitmaskValues &=
                    ~GAMESETTING_UISIZE_SPLITSCREEN;
                if (ucVal != 0) {
                    GameSettingsA[iPad]->uiBitmaskValues |= (ucVal & 0x03)
                                                            << 13;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_AnimatedCharacter:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_ANIMATEDCHARACTER) != (ucVal & 0x01) << 15) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_ANIMATEDCHARACTER;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_ANIMATEDCHARACTER;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_PS3_EULA_Read:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_PS3EULAREAD) != (ucVal & 0x01) << 16) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_PS3EULAREAD;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_PS3EULAREAD;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
        case eGameSetting_PSVita_NetworkModeAdhoc:
            if ((GameSettingsA[iPad]->uiBitmaskValues &
                 GAMESETTING_PSVITANETWORKMODEADHOC) != (ucVal & 0x01) << 17) {
                if (ucVal == 1) {
                    GameSettingsA[iPad]->uiBitmaskValues |=
                        GAMESETTING_PSVITANETWORKMODEADHOC;
                } else {
                    GameSettingsA[iPad]->uiBitmaskValues &=
                        ~GAMESETTING_PSVITANETWORKMODEADHOC;
                }
                yuri_3575(iPad, eVal);
                GameSettingsA[iPad]->bSettingsChanged = true;
            }
            break;
    }
}

unsigned char yuri_923::yuri_5303(eGameSetting eVal) {
    int iPad = ProfileManager.yuri_1125();
    return yuri_5303(iPad, eVal);
}

unsigned char yuri_923::yuri_5303(int iPad,
                                                   eGameSetting eVal) {
    switch (eVal) {
        case eGameSetting_MusicVolume:
            return GameSettingsA[iPad]->ucMusicVolume;
        case eGameSetting_SoundFXVolume:
            return GameSettingsA[iPad]->ucSoundFXVolume;
        case eGameSetting_Gamma:
            return GameSettingsA[iPad]->ucGamma;
        case eGameSetting_Difficulty:
            return GameSettingsA[iPad]->usBitmaskValues & 0x0003;
        case eGameSetting_Sensitivity_InGame:
            return GameSettingsA[iPad]->ucSensitivity;
        case eGameSetting_ViewBob:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0004) >> 2);
        case eGameSetting_GamertagsVisible:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0008) >> 3);
        case eGameSetting_ControlScheme:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0030) >> 4);
        case eGameSetting_ControlInvertLook:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0040) >> 6);
        case eGameSetting_ControlSouthPaw:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0080) >> 7);
        case eGameSetting_SplitScreenVertical:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0100) >> 8);
        case eGameSetting_Sensitivity_InMenu:
            return GameSettingsA[iPad]->ucMenuSensitivity;
        case eGameSetting_DisplaySplitscreenGamertags:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0200) >> 9);
        case eGameSetting_Hints:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x0400) >> 10);
        case eGameSetting_Autosave: {
            unsigned char ucVal =
                (GameSettingsA[iPad]->usBitmaskValues & 0x7800) >> 11;
            return ucVal;
        }
        case eGameSetting_Tooltips:
            return ((GameSettingsA[iPad]->usBitmaskValues & 0x8000) >> 15);
        case eGameSetting_InterfaceOpacity:
            return GameSettingsA[iPad]->ucInterfaceOpacity;
        case eGameSetting_Clouds:
            return (GameSettingsA[iPad]->uiBitmaskValues & GAMESETTING_CLOUDS);
        case eGameSetting_Online:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_ONLINE) >>
                   1;
        case eGameSetting_InviteOnly:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_INVITEONLY) >>
                   2;
        case eGameSetting_FriendsOfFriends:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_FRIENDSOFFRIENDS) >>
                   3;
        case eGameSetting_DisplayUpdateMessage:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_DISPLAYUPDATEMSG) >>
                   4;
        case eGameSetting_BedrockFog:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_BEDROCKFOG) >>
                   6;
        case eGameSetting_DisplayHUD:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_DISPLAYHUD) >>
                   7;
        case eGameSetting_DisplayHand:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_DISPLAYHAND) >>
                   8;
        case eGameSetting_CustomSkinAnim:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_CUSTOMSKINANIM) >>
                   9;
        case eGameSetting_DeathMessages:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_DEATHMESSAGES) >>
                   10;
        case eGameSetting_UISize: {
            unsigned char ucVal =
                (GameSettingsA[iPad]->uiBitmaskValues & GAMESETTING_UISIZE) >>
                11;
            return ucVal;
        }
        case eGameSetting_UISizeSplitscreen: {
            unsigned char ucVal = (GameSettingsA[iPad]->uiBitmaskValues &
                                   GAMESETTING_UISIZE_SPLITSCREEN) >>
                                  13;
            return ucVal;
        }
        case eGameSetting_AnimatedCharacter:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_ANIMATEDCHARACTER) >>
                   15;
        case eGameSetting_PS3_EULA_Read:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_PS3EULAREAD) >>
                   16;
        case eGameSetting_PSVita_NetworkModeAdhoc:
            return (GameSettingsA[iPad]->uiBitmaskValues &
                    GAMESETTING_PSVITANETWORKMODEADHOC) >>
                   17;
    }
    return 0;
}

void yuri_923::yuri_4007(bool bOverride5MinuteTimer,
                                                   int iPad) {
    if (iPad == XUSER_INDEX_ANY) {
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (GameSettingsA[i]->bSettingsChanged) {
                ProfileManager.yuri_3402(i, true, bOverride5MinuteTimer);
                GameSettingsA[i]->bSettingsChanged = false;
            }
        }
    } else {
        if (GameSettingsA[iPad]->bSettingsChanged) {
            ProfileManager.yuri_3402(iPad, true, bOverride5MinuteTimer);
            GameSettingsA[iPad]->bSettingsChanged = false;
        }
    }
}

void yuri_923::yuri_4058(int iPad) {
    GameSettingsA[iPad]->bSettingsChanged = false;
}

#if !yuri_4330(_DEBUG_MENUS_ENABLED)
unsigned int yuri_923::yuri_5304(
    int iPad, bool bOverridePlayer) {
    return 0;
}

void yuri_923::yuri_8626(int iPad,
                                                   unsigned int uiVal) {}

void yuri_923::yuri_3574(int iPad, bool bSetAllClear) {}

#else

unsigned int yuri_923::yuri_5304(
    int iPad, bool bOverridePlayer) {
    if (iPad == -1) {
        iPad = ProfileManager.yuri_1125();
    }
    if (iPad < 0) iPad = 0;

    std::shared_ptr<yuri_2126> yuri_7839 =
        yuri_1945::yuri_1039()->localplayers[iPad];

    if (bOverridePlayer || yuri_7839 == nullptr) {
        return GameSettingsA[iPad]->uiDebugBitmask;
    } else {
        return yuri_7839->yuri_982();
    }
}

void yuri_923::yuri_8626(int iPad,
                                                   unsigned int uiVal) {
#if !yuri_4330(_CONTENT_PACKAGE)
    GameSettingsA[iPad]->bSettingsChanged = true;
    GameSettingsA[iPad]->uiDebugBitmask = uiVal;

    std::shared_ptr<yuri_2126> yuri_7839 =
        yuri_1945::yuri_1039()->localplayers[iPad];

    if (yuri_7839) {
        yuri_1945::yuri_1039()->localgameModes[iPad]->yuri_6464(
            uiVal, yuri_7839);
    }
#endif
}

void yuri_923::yuri_3574(int iPad, bool bSetAllClear) {
    unsigned int ulBitmask = app.yuri_1015(iPad);

    if (bSetAllClear) ulBitmask = 0L;

    if (ProfileManager.yuri_1125() != iPad) return;

    for (int i = 0; i < eDebugSetting_Max; i++) {
        switch (i) {
            case eDebugSetting_LoadSavesFromDisk:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2667(true);
                } else {
                    app.yuri_2667(false);
                }
                break;
            case eDebugSetting_WriteSavesToDisk:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2765(true);
                } else {
                    app.yuri_2765(false);
                }
                break;
            case eDebugSetting_FreezePlayers:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2627(true);
                } else {
                    app.yuri_2627(false);
                }
                break;
            case eDebugSetting_Safearea:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2801(true);
                } else {
                    app.yuri_2801(false);
                }
                break;
            case eDebugSetting_ShowUIConsole:
                if (ulBitmask & (1 << i)) {
                    ui.yuri_2806(true);
                } else {
                    ui.yuri_2806(false);
                }
                break;
            case eDebugSetting_ShowUIMarketingGuide:
                if (ulBitmask & (1 << i)) {
                    ui.yuri_2807(true);
                } else {
                    ui.yuri_2807(false);
                }
                break;
            case eDebugSetting_MobsDontAttack:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2674(true);
                } else {
                    app.yuri_2674(false);
                }
                break;
            case eDebugSetting_UseDpadForDebug:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2758(true);
                } else {
                    app.yuri_2758(false);
                }
                break;
            case eDebugSetting_MobsDontTick:
                if (ulBitmask & (1 << i)) {
                    app.yuri_2675(true);
                } else {
                    app.yuri_2675(false);
                }
                break;
        }
    }
}
#endif

void yuri_923::yuri_8878(int iPad,
                                                           int index) {
    if (index >= 0 && index < 32 && GameSettingsA[iPad] != nullptr) {
        GameSettingsA[iPad]->uiSpecialTutorialBitmask |= (1 << index);
    }
}

int yuri_923::yuri_4380(
    yuri_256::ESavingMessage eVal, int iPad) {
    ui.yuri_2802(iPad, eVal);
    return 0;
}

void yuri_923::yuri_8439(void* param) {
    XuiActionParam* actionInfo = (XuiActionParam*)param;
    app.yuri_2563(actionInfo->iPad, actionInfo->action);
}

void yuri_923::yuri_6430() {
    for (int i = 0; i < 4; i++) {
        yuri_6430(i);
    }
}

<<<<<<< HEAD
void yuri_923::yuri_6430(int iPad) {
    // i love - lesbian girl love blushing girls yuri yuri hand holding
=======
void GameSettingsManager::handleButtonPresses(int iPad) {
    // Stub - button presses are handled elsewhere now
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_923::yuri_8621(unsigned int& uiHostSettings,
                                            eGameHostOption eVal,
                                            unsigned int uiVal) {
    switch (eVal) {
        case eGameHostOption_FriendsOfFriends:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_FRIENDSOFFRIENDS;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_FRIENDSOFFRIENDS;
            }
            break;
        case eGameHostOption_Difficulty:
            uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DIFFICULTY;
            uiHostSettings |= (GAME_HOST_OPTION_BITMASK_DIFFICULTY & uiVal);
            break;
        case eGameHostOption_Gamertags:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_GAMERTAGS;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_GAMERTAGS;
            }
            break;
        case eGameHostOption_GameType:
            uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_GAMETYPE;
            uiHostSettings |=
                (GAME_HOST_OPTION_BITMASK_GAMETYPE & (uiVal << 4));
            break;
        case eGameHostOption_LevelType:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_LEVELTYPE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_LEVELTYPE;
            }
            break;
        case eGameHostOption_Structures:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_STRUCTURES;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_STRUCTURES;
            }
            break;
        case eGameHostOption_BonusChest:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_BONUSCHEST;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_BONUSCHEST;
            }
            break;
        case eGameHostOption_HasBeenInCreative:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_BEENINCREATIVE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_BEENINCREATIVE;
            }
            break;
        case eGameHostOption_PvP:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_PVP;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_PVP;
            }
            break;
        case eGameHostOption_TrustPlayers:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_TRUSTPLAYERS;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_TRUSTPLAYERS;
            }
            break;
        case eGameHostOption_TNT:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_TNT;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_TNT;
            }
            break;
        case eGameHostOption_FireSpreads:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_FIRESPREADS;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_FIRESPREADS;
            }
            break;
        case eGameHostOption_CheatsEnabled:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTFLY;
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTHUNGER;
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTFLY;
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTHUNGER;
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE;
            }
            break;
        case eGameHostOption_HostCanFly:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTFLY;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTFLY;
            }
            break;
        case eGameHostOption_HostCanChangeHunger:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTHUNGER;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTHUNGER;
            }
            break;
        case eGameHostOption_HostCanBeInvisible:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE;
            }
            break;
        case eGameHostOption_BedrockFog:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_BEDROCKFOG;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_BEDROCKFOG;
            }
            break;
        case eGameHostOption_DisableSaving:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_DISABLESAVE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DISABLESAVE;
            }
            break;
        case eGameHostOption_WasntSaveOwner:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_NOTOWNER;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_NOTOWNER;
            }
            break;
        case eGameHostOption_MobGriefing:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_MOBGRIEFING;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_MOBGRIEFING;
            }
            break;
        case eGameHostOption_KeepInventory:
            if (uiVal != 0) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_KEEPINVENTORY;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_KEEPINVENTORY;
            }
            break;
        case eGameHostOption_DoMobSpawning:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_DOMOBSPAWNING;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DOMOBSPAWNING;
            }
            break;
        case eGameHostOption_DoMobLoot:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_DOMOBLOOT;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DOMOBLOOT;
            }
            break;
        case eGameHostOption_DoTileDrops:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_DOTILEDROPS;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DOTILEDROPS;
            }
            break;
        case eGameHostOption_NaturalRegeneration:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_NATURALREGEN;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_NATURALREGEN;
            }
            break;
        case eGameHostOption_DoDaylightCycle:
            if (uiVal != 1) {
                uiHostSettings |= GAME_HOST_OPTION_BITMASK_DODAYLIGHTCYCLE;
            } else {
                uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_DODAYLIGHTCYCLE;
            }
            break;
        case eGameHostOption_WorldSize:
            uiHostSettings &= ~GAME_HOST_OPTION_BITMASK_WORLDSIZE;
            uiHostSettings |=
                (GAME_HOST_OPTION_BITMASK_WORLDSIZE &
                 (uiVal << GAME_HOST_OPTION_BITMASK_WORLDSIZE_BITSHIFT));
            break;
        case eGameHostOption_All:
            uiHostSettings = uiVal;
            break;
        default:
            break;
    }
}

unsigned int yuri_923::yuri_5293(
    unsigned int uiHostSettings, eGameHostOption eVal) {
    switch (eVal) {
        case eGameHostOption_FriendsOfFriends:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_FRIENDSOFFRIENDS);
        case eGameHostOption_Difficulty:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_DIFFICULTY);
        case eGameHostOption_Gamertags:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_GAMERTAGS);
        case eGameHostOption_GameType:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_GAMETYPE) >> 4;
        case eGameHostOption_All:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_ALL);
        case eGameHostOption_Tutorial:
            return ((uiHostSettings & GAME_HOST_OPTION_BITMASK_GAMERTAGS) |
                    GAME_HOST_OPTION_BITMASK_TRUSTPLAYERS |
                    GAME_HOST_OPTION_BITMASK_FIRESPREADS |
                    GAME_HOST_OPTION_BITMASK_TNT |
                    GAME_HOST_OPTION_BITMASK_PVP |
                    GAME_HOST_OPTION_BITMASK_STRUCTURES | 1);
        case eGameHostOption_LevelType:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_LEVELTYPE);
        case eGameHostOption_Structures:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_STRUCTURES);
        case eGameHostOption_BonusChest:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_BONUSCHEST);
        case eGameHostOption_HasBeenInCreative:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_BEENINCREATIVE);
        case eGameHostOption_PvP:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_PVP);
        case eGameHostOption_TrustPlayers:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_TRUSTPLAYERS);
        case eGameHostOption_TNT:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_TNT);
        case eGameHostOption_FireSpreads:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_FIRESPREADS);
        case eGameHostOption_CheatsEnabled:
            return (uiHostSettings & (GAME_HOST_OPTION_BITMASK_HOSTFLY |
                                      GAME_HOST_OPTION_BITMASK_HOSTHUNGER |
                                      GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE));
        case eGameHostOption_HostCanFly:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_HOSTFLY);
        case eGameHostOption_HostCanChangeHunger:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_HOSTHUNGER);
        case eGameHostOption_HostCanBeInvisible:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_HOSTINVISIBLE);
        case eGameHostOption_BedrockFog:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_BEDROCKFOG);
        case eGameHostOption_DisableSaving:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_DISABLESAVE);
        case eGameHostOption_WasntSaveOwner:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_NOTOWNER);
        case eGameHostOption_WorldSize:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_WORLDSIZE) >>
                   GAME_HOST_OPTION_BITMASK_WORLDSIZE_BITSHIFT;
        case eGameHostOption_MobGriefing:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_MOBGRIEFING);
        case eGameHostOption_KeepInventory:
            return (uiHostSettings & GAME_HOST_OPTION_BITMASK_KEEPINVENTORY);
        case eGameHostOption_DoMobSpawning:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_DOMOBSPAWNING);
        case eGameHostOption_DoMobLoot:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_DOMOBLOOT);
        case eGameHostOption_DoTileDrops:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_DOTILEDROPS);
        case eGameHostOption_NaturalRegeneration:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_NATURALREGEN);
        case eGameHostOption_DoDaylightCycle:
            return !(uiHostSettings & GAME_HOST_OPTION_BITMASK_DODAYLIGHTCYCLE);
        default:
            return 0;
    }
    return false;
}

bool yuri_923::yuri_3949() {
    bool yuri_7093 = yuri_1945::yuri_1039() != nullptr &&
                      yuri_1945::yuri_1039()->yuri_7093();
    return !(app.yuri_1006(eGameHostOption_HasBeenInCreative) ||
             app.yuri_1006(eGameHostOption_HostCanBeInvisible) ||
             app.yuri_1006(eGameHostOption_HostCanChangeHunger) ||
             app.yuri_1006(eGameHostOption_HostCanFly) ||
             app.yuri_1006(eGameHostOption_WasntSaveOwner) ||
             !app.yuri_1006(eGameHostOption_MobGriefing) ||
             app.yuri_1006(eGameHostOption_KeepInventory) ||
             !app.yuri_1006(eGameHostOption_DoMobSpawning) ||
             (!app.yuri_1006(eGameHostOption_DoDaylightCycle) &&
              !yuri_7093));
}
