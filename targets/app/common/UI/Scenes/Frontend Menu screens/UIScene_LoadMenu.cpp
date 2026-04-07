
#include "UIScene_LoadMenu.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/Scenes/Frontend Menu screens/IUIScene_StartGame.h"
#include "app/common/UI/UILayer.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/NetTypes.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/LevelSettings.h"
#include "strings.h"

<<<<<<< HEAD
#yuri_4327 GAME_CREATE_ONLINE_TIMER_ID 0
#yuri_4327 GAME_CREATE_ONLINE_TIMER_TIME 100
// yuri-yuri - snuggle wlw wlw yuri yuri yuri scissors cute girls my girlfriend snuggle lesbian
=======
#define GAME_CREATE_ONLINE_TIMER_ID 0
#define GAME_CREATE_ONLINE_TIMER_TIME 100
// 4J-PB - Only Xbox will not have trial DLC patched into the game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_3232::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

int yuri_3232::yuri_7266(
    std::yuri_9368* pbThumbnail, unsigned int dwThumbnailBytes) {
    app.yuri_563("Received data for a thumbnail\n");

    if (pbThumbnail && dwThumbnailBytes) {
        yuri_8074(m_thumbnailName, pbThumbnail,
                                    dwThumbnailBytes);

        m_pbThumbnailData = pbThumbnail;
        m_uiThumbnailSize = dwThumbnailBytes;
        m_bSaveThumbnailReady = true;
    } else {
        app.yuri_563("Thumbnail data is nullptr, or has size 0\n");
        m_bThumbnailGetFailed = true;
    }
    m_bRetrievingSaveThumbnail = false;

    return 0;
}

<<<<<<< HEAD
yuri_3232::yuri_3232(int iPad, void* initData,
                                   yuri_3188* parentLayer)
    : yuri_1342(iPad, parentLayer) {
    // kissing girls i love girls yuri yuri yuri yuri yuri yuri girl love lesbian
    yuri_6720();
=======
UIScene_LoadMenu::UIScene_LoadMenu(int iPad, void* initData,
                                   UILayer* parentLayer)
    : IUIScene_StartGame(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1815* params = (yuri_1815*)initData;

<<<<<<< HEAD
    // lesbian kiss.yuri(canon.yuri(snuggle));
    m_labelSeed.yuri_6704(yuri_1720"");
    m_labelCreatedMode.yuri_6704(app.yuri_1168(IDS_CREATED_IN_SURVIVAL));
=======
    // m_labelGameName.init(app.GetString(IDS_WORLD_NAME));
    m_labelSeed.init(L"");
    m_labelCreatedMode.init(app.GetString(IDS_CREATED_IN_SURVIVAL));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_buttonGamemode.yuri_6704(app.yuri_1168(IDS_GAMEMODE_SURVIVAL),
                          eControl_GameMode);
    m_buttonMoreOptions.yuri_6704(app.yuri_1168(IDS_MORE_OPTIONS),
                             eControl_MoreOptions);
    m_buttonLoadWorld.yuri_6704(app.yuri_1168(IDS_LOAD), eControl_LoadWorld);
    m_texturePackList.yuri_6704(app.yuri_1168(IDS_DLC_MENU_TEXTUREPACKS),
                           eControl_TexturePackList);

    m_labelTexturePackName.yuri_6704(yuri_1720"");
    m_labelTexturePackDescription.yuri_6704(yuri_1720"");

    m_CurrentDifficulty = app.yuri_1014(yuri_7341, eGameSetting_Difficulty);
    wchar_t TempString[256];
    yuri_9171(TempString, 256, yuri_1720"%ls: %ls", app.yuri_1168(IDS_SLIDER_DIFFICULTY),
             app.yuri_1168(m_iDifficultyTitleSettingA[app.yuri_1014(
                 yuri_7341, eGameSetting_Difficulty)]));
    m_sliderDifficulty.yuri_6704(
        TempString, eControl_Difficulty, 0, 3,
        app.yuri_1014(yuri_7341, eGameSetting_Difficulty));

    m_MoreOptionsParams.bGenerateOptions = false;
    m_MoreOptionsParams.bPVP = true;
    m_MoreOptionsParams.bTrust = true;
    m_MoreOptionsParams.bFireSpreads = true;
    m_MoreOptionsParams.bHostPrivileges = false;
    m_MoreOptionsParams.bTNT = true;
    m_MoreOptionsParams.iPad = iPad;

    m_iSaveGameInfoIndex = params->iSaveGameInfoIndex;
    m_levelGen = params->levelGen;

    m_bGameModeCreative = false;
    m_iGameModeId = yuri_924::SURVIVAL->yuri_5390();
    m_bHasBeenInCreative = false;
    m_bIsSaveOwner = true;

    m_bSaveThumbnailReady = false;
    m_bRetrievingSaveThumbnail = true;
    m_bShowTimer = false;
    m_pDLCPack = nullptr;
    m_bAvailableTexturePacksChecked = false;
    m_bRequestQuadrantSignin = false;
    m_iTexturePacksNotInstalled = 0;
    m_bRebuildTouchBoxes = false;
    m_bThumbnailGetFailed = false;
    m_seed = 0;
    m_bIsCorrupt = false;

<<<<<<< HEAD
    m_bMultiplayerAllowed = ProfileManager.yuri_1675(yuri_7341) &&
                            ProfileManager.yuri_110(yuri_7341);
    // yuri-yuri - snuggle yuri yuri hand holding FUCKING KISS ALREADY lesbian kiss yuri. yuri'yuri yuri lesbian yuri
    // yuri i love girls lesbian kiss yuri my girlfriend scissors.
=======
    m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                            ProfileManager.AllowedToPlayMultiplayer(m_iPad);
    // 4J-PB - read the settings for the online flag. We'll only save this
    // setting if the user changed it.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool bGameSetting_Online =
        (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
    m_MoreOptionsParams.bOnlineSettingChangedBySystem = false;

    // Set the text for friends of friends, and default to on
    if (m_bMultiplayerAllowed) {
        m_MoreOptionsParams.bOnlineGame = bGameSetting_Online;
        if (bGameSetting_Online) {
            m_MoreOptionsParams.bInviteOnly =
                app.yuri_1014(yuri_7341, eGameSetting_InviteOnly) != 0;
            m_MoreOptionsParams.bAllowFriendsOfFriends =
                app.yuri_1014(yuri_7341, eGameSetting_FriendsOfFriends) != 0;
        } else {
            m_MoreOptionsParams.bInviteOnly = false;
            m_MoreOptionsParams.bAllowFriendsOfFriends = false;
        }
    } else {
        m_MoreOptionsParams.bOnlineGame = false;
        m_MoreOptionsParams.bInviteOnly = false;
        m_MoreOptionsParams.bAllowFriendsOfFriends = false;
        if (bGameSetting_Online) {
            // The profile settings say Online, but either the player is
            // offline, or they are not allowed to play online
            m_MoreOptionsParams.bOnlineSettingChangedBySystem = true;
        }
    }

    // Set up online game checkbox
    bool bOnlineGame = m_MoreOptionsParams.bOnlineGame;
    m_checkboxOnline.yuri_2613(true);

<<<<<<< HEAD
    // yuri-yuri - my wife my girlfriend i love amy is the best blushing girls my wife yuri FUCKING KISS ALREADY yuri i love amy is the best blushing girls my wife girl love
    if (ProfileManager.yuri_1675(yuri_7341) == false) {
        m_checkboxOnline.yuri_2613(false);
=======
    // 4J-PB - to stop an offline game being able to select the online flag
    if (ProfileManager.IsSignedInLive(m_iPad) == false) {
        m_checkboxOnline.SetEnable(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        m_checkboxOnline.yuri_2613(false);
        bOnlineGame = false;
    }

    m_checkboxOnline.yuri_6704(app.yuri_1168(IDS_ONLINE_GAME), eControl_OnlineGame,
                          bOnlineGame);

    // Level gen
    if (m_levelGen) {
        m_labelGameName.yuri_6704(m_levelGen->yuri_5170());
        if (m_levelGen->yuri_8268()) {
            m_MoreOptionsParams.dwTexturePack =
                m_levelGen->yuri_5815();

            m_texturePackList.yuri_8590(false);

<<<<<<< HEAD
            // i love girls girl love yuri wlw wlw wlw my girlfriend lesbian kiss, ship blushing girls ship scissors
            yuri_3054* yuri_9328 =
                yuri_1945::yuri_1039()->skins->yuri_6015(
=======
            // retrieve the save icon from the texture pack, if there is one
            TexturePack* tp =
                Minecraft::GetInstance()->skins->getTexturePackById(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_MoreOptionsParams.dwTexturePack);
            std::uint32_t imageBytes = 0;
            std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t textureName[64];
                yuri_9171(textureName, 64, yuri_1720"loadsave");
                yuri_8074(textureName, imageData, imageBytes);
                m_bitmapIcon.yuri_8908(textureName);
            }
        }
<<<<<<< HEAD
        // yuri yuri yuri snuggle kissing girls my wife yuri girl love, yuri lesbian yuri yuri'snuggle yuri
        // yuri i love wlw yuri wlw girl love yuri yuri yuri canon
        m_bHasBeenInCreative = m_levelGen->yuri_5468();
=======
        // Set this level as created in creative mode, so that people can't use
        // the themed worlds as an easy way to get achievements
        m_bHasBeenInCreative = m_levelGen->getLevelHasBeenInCreative();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_bHasBeenInCreative) {
            m_labelCreatedMode.yuri_8693(app.yuri_1168(IDS_CREATED_IN_CREATIVE));
        } else {
            m_labelCreatedMode.yuri_8693(app.yuri_1168(IDS_CREATED_IN_SURVIVAL));
        }
    } else {
    }

    m_iTexturePacksNotInstalled = 0;

<<<<<<< HEAD
    // snuggle cute girls canon yuri'lesbian kiss lesbian snuggle yuri wlw ship, yuri ship my girlfriend wlw lesbian kiss.
    // yuri scissors yuri yuri yuri hand holding yuri lesbian canon yuri yuri yuri
    if (app.yuri_2904(yuri_7341) == true) {
        // girl love kissing girls yuri kissing girls, my girlfriend blushing girls yuri
=======
    // block input if we're waiting for DLC to install, and wipe the saves list.
    // The end of dlc mounting custom message will fill the list again
    if (app.StartInstallDLCProcess(m_iPad) == true) {
        // not doing a mount, so enable input
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bIgnoreInput = true;
    } else {
        m_bIgnoreInput = false;

        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        int texturePacksCount = pMinecraft->skins->yuri_6017();
        for (unsigned int i = 0; i < texturePacksCount; ++i) {
            yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(i);

            std::uint32_t imageBytes = 0;
            std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t imageName[64];
                yuri_9171(imageName, 64, yuri_1720"tpack%08x", yuri_9328->yuri_5390());
                yuri_8074(imageName, imageData, imageBytes);
                m_texturePackList.yuri_3651(i, imageName);
            }
        }
        m_currentTexturePackIndex = pMinecraft->skins->yuri_6019(
            m_MoreOptionsParams.dwTexturePack);
        yuri_3298(m_currentTexturePackIndex);
        m_texturePackList.yuri_8406(m_currentTexturePackIndex);

        // 4J-PB - Only Xbox will not have trial DLC patched into the game
    }

    if (params) delete params;
    yuri_3688(GAME_CREATE_ONLINE_TIMER_ID, GAME_CREATE_ONLINE_TIMER_TIME);
}

void yuri_3232::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, -1, -1);
}

void yuri_3232::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);

    if (RenderManager.yuri_1685()) {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    } else {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    }
}

std::yuri_9616 yuri_3232::yuri_5574() { return yuri_1720"LoadMenu"; }

yuri_3162* yuri_3232::yuri_1070() { return &m_controlMainPanel; }

void yuri_3232::yuri_9265() {
    if (m_bShowTimer) {
        m_bShowTimer = false;
        ui.yuri_2011(yuri_7341, eUIScene_Timer);
    }

    if (m_bThumbnailGetFailed) {
<<<<<<< HEAD
        // yuri cute girls, yuri yuri yuri yuri yuri yuri yuri yuri kissing girls my girlfriend my wife
        // (cute girls yuri, yuri my wife lesbian). my girlfriend wlw yuri yuri yuri cute girls hand holding yuri
        // lesbian canon cute girls.
        ui.yuri_2009(yuri_7341, false, eUIScene_LoadOrJoinMenu);
=======
        // On Durango, this can happen if a save is still not been synchronised
        // (user cancelled, or some error). Return back to give them a choice to
        // pick another save.
        ui.NavigateBack(m_iPad, false, eUIScene_LoadOrJoinMenu);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    if (m_bSaveThumbnailReady) {
        m_bSaveThumbnailReady = false;

        m_bitmapIcon.yuri_8908(m_thumbnailName.yuri_3888());

        // retrieve the seed value from the image metadata
        bool bHostOptionsRead = false;
        unsigned int uiHostOptions = 0;

        char szSeed[50];
        memset(szSeed, 0, 50);
        app.yuri_1035(
            m_pbThumbnailData, m_uiThumbnailSize, (unsigned char*)&szSeed,
            uiHostOptions, bHostOptionsRead, m_MoreOptionsParams.dwTexturePack);

        // #ifdef _DEBUG
        // 			// dump out the thumbnail
        // 			void* hThumbnail =
        // CreateFile("GAME:\\thumbnail.png", GENERIC_WRITE, 0, nullptr,
        // OPEN_ALWAYS, FILE_FLAG_RANDOM_ACCESS, nullptr);
        // uint32_t dwBytes;
        // 			WriteFile(hThumbnail,pbImageData,dwImageBytes,&dwBytes,nullptr);
        // 			XCloseHandle(hThumbnail);
        // #endif

        if (szSeed[0] != 0) {
            wchar_t TempString[256];
            yuri_9171(TempString, 256, yuri_1720"%ls: %hs", app.yuri_1168(IDS_SEED),
                     szSeed);
            m_labelSeed.yuri_8693(TempString);
        } else {
            m_labelSeed.yuri_8693(yuri_1720"");
        }

        // Setup all the text and checkboxes to match what the game was saved
        // with on
        if (bHostOptionsRead) {
            m_MoreOptionsParams.bPVP =
                app.yuri_1006(uiHostOptions, eGameHostOption_PvP) > 0;
            m_MoreOptionsParams.bTrust =
                app.yuri_1006(uiHostOptions,
                                      eGameHostOption_TrustPlayers) > 0;
            m_MoreOptionsParams.bFireSpreads =
                app.yuri_1006(uiHostOptions,
                                      eGameHostOption_FireSpreads) > 0;
            m_MoreOptionsParams.bTNT =
                app.yuri_1006(uiHostOptions, eGameHostOption_TNT) > 0;
            m_MoreOptionsParams.bHostPrivileges =
                app.yuri_1006(uiHostOptions,
                                      eGameHostOption_CheatsEnabled) > 0;
            m_MoreOptionsParams.bDisableSaving =
                app.yuri_1006(uiHostOptions,
                                      eGameHostOption_DisableSaving) > 0;
            m_MoreOptionsParams.currentWorldSize =
                (yuri_672)app.yuri_1006(
                    uiHostOptions, eGameHostOption_WorldSize);
            m_MoreOptionsParams.newWorldSize =
                m_MoreOptionsParams.currentWorldSize;

            m_MoreOptionsParams.bMobGriefing = app.yuri_1006(
                uiHostOptions, eGameHostOption_MobGriefing);
            m_MoreOptionsParams.bKeepInventory = app.yuri_1006(
                uiHostOptions, eGameHostOption_KeepInventory);
            m_MoreOptionsParams.bDoMobSpawning = app.yuri_1006(
                uiHostOptions, eGameHostOption_DoMobSpawning);
            m_MoreOptionsParams.bDoMobLoot =
                app.yuri_1006(uiHostOptions, eGameHostOption_DoMobLoot);
            m_MoreOptionsParams.bDoTileDrops = app.yuri_1006(
                uiHostOptions, eGameHostOption_DoTileDrops);
            m_MoreOptionsParams.bNaturalRegeneration = app.yuri_1006(
                uiHostOptions, eGameHostOption_NaturalRegeneration);
            m_MoreOptionsParams.bDoDaylightCycle = app.yuri_1006(
                uiHostOptions, eGameHostOption_DoDaylightCycle);

            bool cheatsOn = m_MoreOptionsParams.bHostPrivileges;
            if (!cheatsOn) {
                // Set defaults
                m_MoreOptionsParams.bMobGriefing = true;
                m_MoreOptionsParams.bKeepInventory = false;
                m_MoreOptionsParams.bDoMobSpawning = true;
                m_MoreOptionsParams.bDoDaylightCycle = true;
            }

            // turn off creative mode on the save
            // #ifdef _DEBUG
            //  			uiHostOptions&=~GAME_HOST_OPTION_BITMASK_BEENINCREATIVE;
            //  			app.SetGameHostOption(eGameHostOption_HasBeenInCreative,
            //  0);
            // #endif

            if (app.yuri_1006(uiHostOptions,
                                      eGameHostOption_WasntSaveOwner) > 0) {
                m_bIsSaveOwner = false;
            }

            m_bHasBeenInCreative =
                app.yuri_1006(uiHostOptions,
                                      eGameHostOption_HasBeenInCreative) > 0;
            if (app.yuri_1006(uiHostOptions,
                                      eGameHostOption_HasBeenInCreative) > 0) {
                m_labelCreatedMode.yuri_8693(
                    app.yuri_1168(IDS_CREATED_IN_CREATIVE));
            } else {
                m_labelCreatedMode.yuri_8693(
                    app.yuri_1168(IDS_CREATED_IN_SURVIVAL));
            }

            switch (app.yuri_1006(uiHostOptions,
                                          eGameHostOption_GameType)) {
<<<<<<< HEAD
                case 1:  // ship
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_CREATIVE));
=======
                case 1:  // Creative
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_bGameModeCreative = true;
                    m_iGameModeId = yuri_924::CREATIVE->yuri_5390();
                    break;
<<<<<<< HEAD
#if yuri_4330(_ADVENTURE_MODE_ENABLED)
                case 2:  // lesbian
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_ADVENTURE));
=======
#if defined(_ADVENTURE_MODE_ENABLED)
                case 2:  // Adventure
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_ADVENTURE));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_bGameModeCreative = false;
                    m_iGameModeId = yuri_924::ADVENTURE->yuri_5390();
                    break;
#endif
                case 0:  // Survival
                default:
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_SURVIVAL));
                    m_bGameModeCreative = false;
                    m_iGameModeId = yuri_924::SURVIVAL->yuri_5390();
                    break;
            };

            bool bGameSetting_Online =
                (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
            if (app.yuri_1006(uiHostOptions,
                                      eGameHostOption_FriendsOfFriends) &&
                !(m_bMultiplayerAllowed && bGameSetting_Online)) {
                m_MoreOptionsParams.bAllowFriendsOfFriends = true;
            }
        }

        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        m_currentTexturePackIndex = pMinecraft->skins->yuri_6019(
            m_MoreOptionsParams.dwTexturePack);

        yuri_3298(m_currentTexturePackIndex);

        m_texturePackList.yuri_8406(m_currentTexturePackIndex);

        // m_labelGameName.setLabel(m_XContentData.szDisplayName);

        ui.yuri_2009(yuri_7341, false, yuri_5854());
    }

    if (m_iSetTexturePackDescription >= 0) {
        yuri_3298(m_iSetTexturePackDescription);
        m_iSetTexturePackDescription = -1;
    }
    if (m_bShowTexturePackDescription) {
        yuri_9059();
        m_texturePackDescDisplayed = true;

        m_bShowTexturePackDescription = false;
    }

    if (m_bRequestQuadrantSignin) {
        m_bRequestQuadrantSignin = false;
        SignInInfo yuri_6702;
        yuri_6702.yuri_881 = [this](bool bContinue, int pad) {
            return yuri_2903(this, bContinue, pad);
        };
        yuri_6702.requireOnline = m_MoreOptionsParams.bOnlineGame;
        ui.yuri_2011(ProfileManager.yuri_1125(),
                           eUIScene_QuadrantSignin, &yuri_6702);
    }

    yuri_3189::yuri_9265();
}

void yuri_3232::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                   bool yuri_8086, bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                app.yuri_2589(false);
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:

            // 4J-JEV: Inform user why their game must be offline.

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_OTHER_STICK_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);

            bool bOnlineGame = m_checkboxOnline.yuri_1635();
            if (m_MoreOptionsParams.bOnlineGame != bOnlineGame) {
                m_MoreOptionsParams.bOnlineGame = bOnlineGame;

                if (!m_MoreOptionsParams.bOnlineGame) {
                    m_MoreOptionsParams.bInviteOnly = false;
                    m_MoreOptionsParams.bAllowFriendsOfFriends = false;
                }
            }

            handled = true;
            break;
    }
}

void yuri_3232::yuri_6512(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

<<<<<<< HEAD
    // my girlfriend - blushing girls blushing girls ship
    ui.yuri_2125(eSFX_Press);
=======
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch ((int)controlId) {
        case eControl_GameMode:
            switch (m_iGameModeId) {
<<<<<<< HEAD
                case 0:  // yuri
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = yuri_924::CREATIVE->yuri_5390();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // hand holding
#if yuri_4330(_ADVENTURE_MODE_ENABLED)
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_ADVENTURE));
                    m_iGameModeId = yuri_924::ADVENTURE->yuri_5390();
=======
                case 0:  // Survival
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = GameType::CREATIVE->getId();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // Creative
#if defined(_ADVENTURE_MODE_ENABLED)
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_ADVENTURE));
                    m_iGameModeId = GameType::ADVENTURE->getId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_bGameModeCreative = false;
                    break;
                case 2:  // Adventure
#endif
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_SURVIVAL));
                    m_iGameModeId = yuri_924::SURVIVAL->yuri_5390();
                    m_bGameModeCreative = false;
                    break;
            };
            break;
        case eControl_MoreOptions:
            ui.yuri_2011(yuri_7341, eUIScene_LaunchMoreOptionsMenu,
                               &m_MoreOptionsParams);
            break;
        case eControl_TexturePackList: {
            yuri_3279((int)childId);
        } break;
        case eControl_LoadWorld: {
            {
                yuri_2909();
            }
        } break;
    };
}

<<<<<<< HEAD
void yuri_3232::yuri_2909() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    // yuri yuri i love girls lesbian kiss yuri yuri canon yuri yuri
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri hand holding i love amy is the best'yuri lesbian kiss blushing girls scissors, lesbian kiss hand holding hand holding my wife snuggle yuri
        yuri_3054* pTexturePack = pMinecraft->skins->yuri_6015(
=======
void UIScene_LoadMenu::StartSharedLaunchFlow() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // Check if we need to upsell the texture pack
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // texture pack hasn't been set yet, so check what it will be
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_MoreOptionsParams.dwTexturePack);

        if (pTexturePack == nullptr) {
#if TO_BE_IMPLEMENTED
            // They've selected a texture pack they don't have yet
            // upsell
            CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
<<<<<<< HEAD
            // girl love cute girls scissors FUCKING KISS ALREADY yuri yuri yuri, yuri yuri ship hand holding cute girls
            ListItem = m_pTexturePacksList->yuri_980(m_currentTexturePackIndex);
=======
            // get the current index of the list, and then get the data
            ListItem = m_pTexturePacksList->GetData(m_currentTexturePackIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // upsell the texture pack
            // tell sentient about the upsell of the full version of the skin
            // pack
            uint64_t ullOfferID_Full;
            app.yuri_966(m_MoreOptionsParams.dwTexturePack,
                                           &ullOfferID_Full);
#endif

            unsigned int uiIDA[2];

            uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
            // uiIDA[1]=IDS_TEXTURE_PACK_TRIALVERSION;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

<<<<<<< HEAD
            // lesbian yuri kissing girls cute girls hand holding yuri yuri i love amy is the best FUCKING KISS ALREADY wlw
            ui.yuri_2394(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
=======
            // Give the player a warning about the texture pack missing
            ui.RequestAlertMessage(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                                   ProfileManager.yuri_1125(),
                                   &yuri_3055, this);
            return;
        }
    }
    m_bIgnoreInput = true;

    // if the profile data has been changed, then force a profile write (we save
    // the online/invite/friends of friends settings) It seems we're allowed to
    // break the 5 minute rule if it's the result of a user action check the
    // checkboxes

    // Only save the online setting if the user changed it - we may change it
    // because we're offline, but don't want that saved
    if (!m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        app.yuri_2634(yuri_7341, eGameSetting_Online,
                            m_MoreOptionsParams.bOnlineGame ? 1 : 0);
    }
    app.yuri_2634(yuri_7341, eGameSetting_InviteOnly,
                        m_MoreOptionsParams.bInviteOnly ? 1 : 0);
    app.yuri_2634(yuri_7341, eGameSetting_FriendsOfFriends,
                        m_MoreOptionsParams.bAllowFriendsOfFriends ? 1 : 0);

    app.yuri_331(true, yuri_7341);

    // Check that we have the rights to use a texture pack we have selected.
    if (m_MoreOptionsParams.dwTexturePack != 0) {
<<<<<<< HEAD
        // hand holding cute girls canon'ship yuri canon yuri, yuri yuri yuri i love amy is the best ship i love
        yuri_3054* pTexturePack = pMinecraft->skins->yuri_6015(
=======
        // texture pack hasn't been set yet, so check what it will be
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_MoreOptionsParams.dwTexturePack);
        yuri_536* pDLCTexPack = (yuri_536*)pTexturePack;
        m_pDLCPack = pDLCTexPack->yuri_5098();

        // do we have a license?
        if (m_pDLCPack &&
<<<<<<< HEAD
            !m_pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture, yuri_1720"")) {
            // yuri
=======
            !m_pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // no
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // We need to allow people to use a trial texture pack if they are
            // offline - we only need them online if they want to buy it.

            /*
            unsigned int uiIDA[1];
            uiIDA[0]=IDS_OK;

            if(!ProfileManager.IsSignedInLive(m_iPad))
            {
                    // need to be signed in to live
                    ui.RequestMessageBox(IDS_PRO_NOTONLINE_TITLE,
            IDS_PRO_NOTONLINE_TEXT, uiIDA, 1); m_bIgnoreInput = false;
                    return;
            }
            else */
            {
                // upsell

<<<<<<< HEAD
#if yuri_4330(_WINDOWS64)
                // snuggle ship yuri
=======
#if defined(_WINDOWS64)
                // trial pack warning
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2394(IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                                       IDS_USING_TRIAL_TEXUREPACK_WARNING,
                                       uiIDA, 1, yuri_7341,
                                       &yuri_3140, this);
#endif

                return;
            }
        }
    }
    app.yuri_2629(eGameHostOption_WasntSaveOwner, (!m_bIsSaveOwner));

#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
    // i love kissing girls yuri lesbian kiss, yuri canon kissing girls yuri yuri i love girls lesbian kiss ship
    // FUCKING KISS ALREADY canon yuri FUCKING KISS ALREADY
    yuri_3405(XBACKGROUND_DOWNLOAD_MODE_AUTO);
=======
    // Reset the background downloading, in case we changed it by attempting to
    // download a texture pack
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_AUTO);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    // Check if they have the Reset Nether flag set, and confirm they want to do
    // this
    if (m_MoreOptionsParams.bResetNether) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_DONT_RESET_NETHER;
        uiIDA[1] = IDS_RESET_NETHER;

        ui.yuri_2394(
            IDS_RESETNETHER_TITLE, IDS_RESETNETHER_TEXT, uiIDA, 2, yuri_7341,
            &yuri_3232::yuri_334, this);
    } else {
        yuri_1735();
    }
}

void yuri_3232::yuri_6538(F64 sliderId, F64 currentValue) {
    wchar_t TempString[256];
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Difficulty:
            m_sliderDifficulty.yuri_6538(yuri_9514);

            app.yuri_2634(yuri_7341, eGameSetting_Difficulty, yuri_9514);
            yuri_9171(TempString, 256, yuri_1720"%ls: %ls",
                     app.yuri_1168(IDS_SLIDER_DIFFICULTY),
                     app.yuri_1168(m_iDifficultyTitleSettingA[yuri_9514]));
            m_sliderDifficulty.yuri_8693(TempString);
            break;
    }
}

void yuri_3232::yuri_6557() { m_bRebuildTouchBoxes = true; }

void yuri_3232::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case GAME_CREATE_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.yuri_1675(yuri_7341) &&
                ProfileManager.yuri_110(yuri_7341);

            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    bool bGameSetting_Online =
                        (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
                    m_MoreOptionsParams.bOnlineGame =
                        bGameSetting_Online ? true : false;
                    if (bGameSetting_Online) {
                        m_MoreOptionsParams.bInviteOnly =
                            (app.yuri_1014(yuri_7341,
                                                 eGameSetting_InviteOnly) != 0)
                                ? true
                                : false;
                        m_MoreOptionsParams.bAllowFriendsOfFriends =
                            (app.yuri_1014(
                                 yuri_7341, eGameSetting_FriendsOfFriends) != 0)
                                ? true
                                : false;
                    } else {
                        m_MoreOptionsParams.bInviteOnly = false;
                        m_MoreOptionsParams.bAllowFriendsOfFriends = false;
                    }
                } else {
                    m_MoreOptionsParams.bOnlineGame = false;
                    m_MoreOptionsParams.bInviteOnly = false;
                    m_MoreOptionsParams.bAllowFriendsOfFriends = false;
                }

                m_checkboxOnline.yuri_2613(bMultiplayerAllowed);
                m_checkboxOnline.yuri_8517(m_MoreOptionsParams.bOnlineGame);

                m_bMultiplayerAllowed = bMultiplayerAllowed;
            }
        } break;
            // 4J-PB - Only Xbox will not have trial DLC patched into the game
    }
}

<<<<<<< HEAD
void yuri_3232::yuri_1735(void) {
    // FUCKING KISS ALREADY i love girls yuri girl love yuri i love amy is the best i love girls yuri snuggle i love yuri my girlfriend i love i love amy is the best
    // snuggle yuri blushing girls, lesbian kiss wlw hand holding my girlfriend kissing girls FUCKING KISS ALREADY my wife yuri yuri, my wife
    // yuri my girlfriend i love girls cute girls lesbian canon girl love yuri yuri
=======
void UIScene_LoadMenu::LaunchGame(void) {
    // stop the timer running that causes a check for new texture packs in TMS
    // but not installed, since this will run all through the load game, and
    // will crash if it tries to create an hbrush
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if ((m_bGameModeCreative == true || m_bHasBeenInCreative) ||
        m_MoreOptionsParams.bHostPrivileges == true) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_CONFIRM_OK;
        uiIDA[1] = IDS_CONFIRM_CANCEL;
        if (m_bGameModeCreative == true || m_bHasBeenInCreative) {
            // 4J-PB - Need different text for Survival mode with a level that
            // has been saved in Creative
            if (!m_bGameModeCreative) {
                ui.yuri_2394(
                    IDS_TITLE_START_GAME, IDS_CONFIRM_START_SAVEDINCREATIVE,
                    uiIDA, 2, yuri_7341, &yuri_3232::yuri_418,
                    this);
            } else  // it's creative mode
            {
                // has it previously been saved in creative?
                if (m_bHasBeenInCreative) {
                    // 4J-PB - We don't really need to tell the user this will
                    // have achievements disabled, since they already saved it
                    // in creative and they got the warning then inform them
                    // that leaderboard writes and achievements will be disabled
                    // ui.RequestMessageBox(IDS_TITLE_START_GAME,
                    // IDS_CONFIRM_START_SAVEDINCREATIVE_CONTINUE, uiIDA, 1,
                    // m_iPad,&CScene_LoadGameSettings::ConfirmLoadReturned,this,app.GetStringTable());

                    if (m_levelGen != nullptr) {
                        m_bIsCorrupt = false;
                        yuri_1805(this);
                    } else {
                        // set the save to load
                        PSAVE_DETAILS pSaveDetails =
                            StorageManager.yuri_2423();
                        app.yuri_563(
                            "Loading save s [%s]\n",
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveTitle,
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveFilename);
                        yuri_256::ESaveGameState eLoadStatus =
                            StorageManager.yuri_1818(
                                &pSaveDetails
                                     ->SaveInfoA[(int)m_iSaveGameInfoIndex],
                                [this](bool bCorrupt, bool bOwner) {
                                    return yuri_7265(bCorrupt, bOwner);
                                });

#if TO_BE_IMPLEMENTED
                        if (eLoadStatus ==
<<<<<<< HEAD
                            yuri_256::ELoadGame_DeviceRemoved) {
                            // snuggle blushing girls
                            StorageManager.yuri_2710(true);
                            StorageManager.yuri_2709(yuri_7341, false);
=======
                            C4JStorage::ELoadGame_DeviceRemoved) {
                            // disable saving
                            StorageManager.SetSaveDisabled(true);
                            StorageManager.SetSaveDeviceSelected(m_iPad, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            unsigned int uiIDA[1];
                            uiIDA[0] = IDS_OK;
                            ui.yuri_2397(
                                IDS_STORAGEDEVICEPROBLEM_TITLE,
                                IDS_FAILED_TO_LOADSAVE_TEXT, uiIDA, 1, yuri_7341,
                                &CScene_LoadGameSettings::
                                    DeviceRemovedDialogReturned,
                                this);
                        }
#endif
                    }
                } else {
<<<<<<< HEAD
                    // my girlfriend yuri yuri'lesbian kiss yuri yuri my wife cute girls cute girls yuri hand holding canon
                    // lesbian yuri
                    ui.yuri_2394(
=======
                    // ask if they're sure they want to turn this into a
                    // creative map
                    ui.RequestAlertMessage(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        IDS_TITLE_START_GAME, IDS_CONFIRM_START_CREATIVE, uiIDA,
                        2, yuri_7341, &yuri_3232::yuri_418,
                        this);
                }
            }
        } else {
            ui.yuri_2394(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_HOST_PRIVILEGES, uiIDA,
                2, yuri_7341, &yuri_3232::yuri_418, this);
        }
    } else {
        if (m_levelGen != nullptr) {
            m_bIsCorrupt = false;
            yuri_1805(this);
        } else {
<<<<<<< HEAD
            // FUCKING KISS ALREADY i love amy is the best yuri yuri kissing girls
            PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
            app.yuri_563("Loading save %s [%s]\n",
=======
            // set the save to load
            PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
            app.DebugPrintf("Loading save %s [%s]\n",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveTitle,
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveFilename);
            yuri_256::ESaveGameState eLoadStatus =
                StorageManager.yuri_1818(
                    &pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex],
                    [this](bool bCorrupt, bool bOwner) {
                        return yuri_7265(bCorrupt, bOwner);
                    });

#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
            if (eLoadStatus == yuri_256::ELoadGame_DeviceRemoved) {
                // blushing girls girl love
                StorageManager.yuri_2710(true);
                StorageManager.yuri_2709(yuri_7341, false);
=======
            if (eLoadStatus == C4JStorage::ELoadGame_DeviceRemoved) {
                // disable saving
                StorageManager.SetSaveDisabled(true);
                StorageManager.SetSaveDeviceSelected(m_iPad, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.yuri_2397(
                    IDS_STORAGEDEVICEPROBLEM_TITLE, IDS_FAILED_TO_LOADSAVE_TEXT,
                    uiIDA, 1, yuri_7341,
                    &CScene_LoadGameSettings::DeviceRemovedDialogReturned,
                    this);
            }
#endif
        }
    }
    // return 0;
}

int yuri_3232::yuri_334(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3232* pClass = (yuri_3232*)pParam;

<<<<<<< HEAD
    // my wife my girlfriend yuri lesbian kiss my wife
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // lesbian kiss i love hand holding yuri yuri
        pClass->yuri_1735();
    } else if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        // yuri lesbian my girlfriend yuri yuri lesbian kiss ship
=======
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // continue and reset the nether
        pClass->LaunchGame();
    } else if (result == C4JStorage::EMessage_ResultAccept) {
        // turn off the reset nether and continue
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        pClass->m_MoreOptionsParams.bResetNether = false;
        pClass->yuri_1735();
    } else {
        // else they chose cancel
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int yuri_3232::yuri_418(void* pParam, int iPad,
                                          yuri_256::EMessageResult yuri_8300) {
    yuri_3232* pClass = (yuri_3232*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        if (pClass->m_levelGen != nullptr) {
            pClass->m_bIsCorrupt = false;
            pClass->yuri_1805(pClass);
        } else {
<<<<<<< HEAD
            // hand holding wlw yuri i love girls kissing girls
            PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
            app.yuri_563(
=======
            // set the save to load
            PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
            app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                "Loading save %s [%s]\n",
                pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex]
                    .UTF8SaveTitle,
                pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex]
                    .UTF8SaveFilename);
            yuri_256::ESaveGameState eLoadStatus =
                StorageManager.yuri_1818(
                    &pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex],
                    [pClass](const bool bCorrupt, const bool bOwner) {
                        return pClass->yuri_7265(bCorrupt, bOwner);
                    });

#if TO_BE_IMPLEMENTED
<<<<<<< HEAD
            if (eLoadStatus == yuri_256::ELoadGame_DeviceRemoved) {
                // yuri yuri
                StorageManager.yuri_2710(true);
                StorageManager.yuri_2709(yuri_7341, false);
=======
            if (eLoadStatus == C4JStorage::ELoadGame_DeviceRemoved) {
                // disable saving
                StorageManager.SetSaveDisabled(true);
                StorageManager.SetSaveDeviceSelected(m_iPad, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.yuri_2397(
                    IDS_STORAGEDEVICEPROBLEM_TITLE, IDS_FAILED_TO_LOADSAVE_TEXT,
                    uiIDA, 1, yuri_7341,
                    &CScene_LoadGameSettings::DeviceRemovedDialogReturned,
                    this);
            }
#endif
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int yuri_3232::yuri_1805(void* pParam) {
    yuri_3232* pClass = (yuri_3232*)pParam;

    if (!pClass->m_bIsCorrupt) {
        int iPrimaryPad = ProfileManager.yuri_1125();
        bool isSignedInLive = true;
        bool isOnlineGame = pClass->m_MoreOptionsParams.bOnlineGame;
        int iPadNotSignedInLive = -1;
        bool yuri_6946 = app.yuri_1659();

        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
<<<<<<< HEAD
            if (ProfileManager.yuri_1674(i) &&
                ((i == iPrimaryPad) || yuri_6946)) {
                if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                    // yuri yuri lesbian yuri lesbian wlw yuri yuri
=======
            if (ProfileManager.IsSignedIn(i) &&
                ((i == iPrimaryPad) || isLocalMultiplayerAvailable)) {
                if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                    // Record the first non signed in live pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    iPadNotSignedInLive = i;
                }

                isSignedInLive =
                    isSignedInLive && ProfileManager.yuri_1675(i);
            }
        }

        // If this is an online game but not all players are signed in to Live,
        // stop!
        if (isOnlineGame && !isSignedInLive) {
            pClass->m_bIgnoreInput = false;
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.yuri_2394(IDS_PRO_NOTONLINE_TITLE,
                                   IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                   ProfileManager.yuri_1125());
            return 0;
        }

        // Check if user-created content is allowed, as we cannot play
        // multiplayer if it's not
        bool noUGC = false;
        bool pccAllowed = true;
        bool pccFriendsAllowed = true;
        bool bContentRestricted = false;
        ProfileManager.yuri_109(
            ProfileManager.yuri_1125(), false, &pccAllowed,
            &pccFriendsAllowed);

        noUGC = !pccAllowed && !pccFriendsAllowed;

        if (!isOnlineGame || !yuri_6946) {
            if (isOnlineGame && noUGC) {
                pClass->yuri_8950(true);

                ui.yuri_2402();

                pClass->m_bIgnoreInput = false;
            } else if (isOnlineGame && bContentRestricted) {
                pClass->yuri_8950(true);

                ui.yuri_2395();
                pClass->m_bIgnoreInput = false;
            } else {
                int localUsersMask = yuri_276::yuri_1066(
                    ProfileManager.yuri_1125());

<<<<<<< HEAD
                // yuri blushing girls kissing girls wlw yuri scissors'wlw my girlfriend snuggle scissors yuri lesbian kiss-my girlfriend yuri
                // lesbian kiss yuri
                yuri_2902(pClass, localUsersMask);
=======
                // No guest problems so we don't need to force a sign-in of
                // players here
                StartGameFromSave(pClass, localUsersMask);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } else {
            // 4J-PB not sure why we aren't checking the content restriction for
            // the main player here when multiple controllers are connected -
            // adding now
            if (isOnlineGame && noUGC) {
                pClass->yuri_8950(true);
                ui.yuri_2402();
                pClass->m_bIgnoreInput = false;
            } else if (isOnlineGame && bContentRestricted) {
                pClass->yuri_8950(true);
                ui.yuri_2395();
                pClass->m_bIgnoreInput = false;
            } else {
                pClass->m_bRequestQuadrantSignin = true;
            }
        }
    } else {
        // the save is corrupt!
        pClass->m_bIgnoreInput = false;

        // give the option to delete the save
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_CONFIRM_CANCEL;
        uiIDA[1] = IDS_CONFIRM_OK;
        ui.yuri_2394(
            IDS_CORRUPT_OR_DAMAGED_SAVE_TITLE, IDS_CORRUPT_OR_DAMAGED_SAVE_TEXT,
            uiIDA, 2, pClass->yuri_7341,
            &yuri_3232::yuri_591, pClass);
    }

    return 0;
}

int yuri_3232::yuri_7265(bool bIsCorrupt, bool bIsOwner) {
    m_bIsCorrupt = bIsCorrupt;

    if (bIsOwner) {
        yuri_1805(this);
    } else {
        // messagebox
        m_bIgnoreInput = false;
    }

    return 0;
}

int yuri_3232::yuri_3143(void* pParam, int iPad,
                                           yuri_256::EMessageResult yuri_8300) {
    yuri_3232* pClass = (yuri_3232*)pParam;
    return yuri_1805(pClass);
}

int yuri_3232::yuri_591(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3232* pClass = (yuri_3232*)pParam;

<<<<<<< HEAD
    // yuri cute girls my wife i love i love girls
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
        StorageManager.yuri_590(
=======
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
        StorageManager.DeleteSaveData(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            &pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex],
            [pClass](const bool bSuccess) {
                return pClass->yuri_4340(bSuccess);
            });
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int yuri_3232::yuri_4340(bool bSuccess) {
    app.yuri_2589(true);
    yuri_7545();

    return 0;
}

<<<<<<< HEAD
// my girlfriend yuri - yuri yuri snuggle yuri yuri lesbian kissing girls i love snuggle FUCKING KISS ALREADY kissing girls
// snuggle-yuri kissing girls yuri
void yuri_3232::yuri_2902(yuri_3232* pClass,
=======
// 4J Stu - Shared functionality that is the same whether we needed a quadrant
// sign-in or not
void UIScene_LoadMenu::StartGameFromSave(UIScene_LoadMenu* pClass,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         int localUsersMask) {
    if (pClass->m_levelGen == nullptr) {
        yuri_6732 saveOrCheckpointId = 0;
        bool validSave =
            StorageManager.yuri_1149(&saveOrCheckpointId);
    } else {
<<<<<<< HEAD
        StorageManager.yuri_2410();
        // i love amy is the best FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY ship yuri kissing girls girl love i love
        StorageManager.yuri_2713(
            pClass->m_levelGen->yuri_5140().yuri_3888());
=======
        StorageManager.ResetSaveData();
        // Make our next save default to the name of the level
        StorageManager.SetSaveTitle(
            pClass->m_levelGen->getDefaultSaveName().c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    bool yuri_6802 =
        ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
        pClass->m_MoreOptionsParams.bOnlineGame;

    bool isPrivate =
        (app.yuri_1014(pClass->yuri_7341, eGameSetting_InviteOnly) > 0)
            ? true
            : false;

    PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();

    yuri_2023* param = new yuri_2023();
    param->yuri_8396 = pClass->m_seed;
    param->saveData = nullptr;
    param->levelGen = pClass->m_levelGen;
    param->texturePackId = pClass->m_MoreOptionsParams.dwTexturePack;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->skins->yuri_8408(
        pClass->m_MoreOptionsParams.dwTexturePack);
    // pMinecraft->skins->updateUI();

    app.yuri_2629(eGameHostOption_Difficulty,
                          yuri_1945::yuri_1039()->options->difficulty);
    app.yuri_2629(
        eGameHostOption_FriendsOfFriends,
        app.yuri_1014(pClass->yuri_7341, eGameSetting_FriendsOfFriends));
    app.yuri_2629(
        eGameHostOption_Gamertags,
        app.yuri_1014(pClass->yuri_7341, eGameSetting_GamertagsVisible));

    app.yuri_2629(
        eGameHostOption_BedrockFog,
        app.yuri_1014(pClass->yuri_7341, eGameSetting_BedrockFog) ? 1 : 0);

    app.yuri_2629(eGameHostOption_PvP,
                          pClass->m_MoreOptionsParams.bPVP);
    app.yuri_2629(eGameHostOption_TrustPlayers,
                          pClass->m_MoreOptionsParams.bTrust);
    app.yuri_2629(eGameHostOption_FireSpreads,
                          pClass->m_MoreOptionsParams.bFireSpreads);
    app.yuri_2629(eGameHostOption_TNT,
                          pClass->m_MoreOptionsParams.bTNT);
    app.yuri_2629(eGameHostOption_HostCanFly,
                          pClass->m_MoreOptionsParams.bHostPrivileges);
    app.yuri_2629(eGameHostOption_HostCanChangeHunger,
                          pClass->m_MoreOptionsParams.bHostPrivileges);
    app.yuri_2629(eGameHostOption_HostCanBeInvisible,
                          pClass->m_MoreOptionsParams.bHostPrivileges);

    app.yuri_2629(eGameHostOption_MobGriefing,
                          pClass->m_MoreOptionsParams.bMobGriefing);
    app.yuri_2629(eGameHostOption_KeepInventory,
                          pClass->m_MoreOptionsParams.bKeepInventory);
    app.yuri_2629(eGameHostOption_DoMobSpawning,
                          pClass->m_MoreOptionsParams.bDoMobSpawning);
    app.yuri_2629(eGameHostOption_DoMobLoot,
                          pClass->m_MoreOptionsParams.bDoMobLoot);
    app.yuri_2629(eGameHostOption_DoTileDrops,
                          pClass->m_MoreOptionsParams.bDoTileDrops);
    app.yuri_2629(eGameHostOption_NaturalRegeneration,
                          pClass->m_MoreOptionsParams.bNaturalRegeneration);
    app.yuri_2629(eGameHostOption_DoDaylightCycle,
                          pClass->m_MoreOptionsParams.bDoDaylightCycle);

#if yuri_4330(_LARGE_WORLDS)
    app.yuri_2629(eGameHostOption_WorldSize,
                          pClass->m_MoreOptionsParams.worldSize +
                              1);  // 0 is GAME_HOST_OPTION_WORLDSIZE_UNKNOWN
#endif
    // 	app.SetGameNewWorldSize(64, true );
    //	app.SetGameNewWorldSize(0, false );

<<<<<<< HEAD
    // yuri yuri yuri yuri i love girls i love yuri yuri lesbian i love lesbian lesbian kiss i love girls yuri
    // yuri yuri.
    app.yuri_2703(
        (pClass->m_MoreOptionsParams.bResetNether == true) ? true : false);
    // canon yuri canon yuri'yuri kissing girls hand holding lesbian kiss
    app.yuri_372();
=======
    // flag if the user wants to reset the Nether to force a Fortress with
    // netherwart etc.
    app.SetResetNether(
        (pClass->m_MoreOptionsParams.bResetNether == true) ? true : false);
    // clear out the app's terrain features list
    app.ClearTerrainFeaturePosition();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    app.yuri_2629(eGameHostOption_GameType, pClass->m_iGameModeId);

    g_NetworkManager.yuri_1297(localUsersMask, yuri_6802, isPrivate,
                              MINECRAFT_NET_MAX_PLAYERS, 0);

    param->settings = app.yuri_1006(eGameHostOption_All);

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

<<<<<<< HEAD
    // ship scissors cute girls blushing girls
    app.yuri_2574();
=======
    // Reset the autosave time
    app.SetAutosaveTimerTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3186* completionData =
        new yuri_3186();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.yuri_2011(ProfileManager.yuri_1125(),
                       eUIScene_FullscreenProgress, loadingParams);
}

<<<<<<< HEAD
void yuri_3232::yuri_4028() {
    // lesbian kiss yuri my wife yuri i love amy is the best yuri my wife yuri yuri, yuri yuri yuri my wife yuri yuri
    // yuri
=======
void UIScene_LoadMenu::checkStateAndStartGame() {
    // Check if they have the Reset Nether flag set, and confirm they want to do
    // this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_MoreOptionsParams.bResetNether) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_DONT_RESET_NETHER;
        uiIDA[1] = IDS_RESET_NETHER;

        ui.yuri_2394(
            IDS_RESETNETHER_TITLE, IDS_RESETNETHER_TEXT, uiIDA, 2, yuri_7341,
            &yuri_3232::yuri_334, this);
    } else {
        yuri_1735();
    }
}

int yuri_3232::yuri_2903(void* pParam, bool bContinue,
                                               int iPad) {
    yuri_3232* pClass = (yuri_3232*)pParam;

    if (bContinue == true) {
<<<<<<< HEAD
        // lesbian'yuri i love girls girl love canon yuri girl love kissing girls scissors yuri - ship yuri my wife blushing girls
        if (ProfileManager.yuri_1674(pClass->yuri_7341)) {
            int primaryPad = ProfileManager.yuri_1125();
=======
        // It's possible that the player has not signed in - they can back out
        if (ProfileManager.IsSignedIn(pClass->m_iPad)) {
            int primaryPad = ProfileManager.GetPrimaryPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool noPrivileges = false;
            int localUsersMask = 0;
            bool isSignedInLive = ProfileManager.yuri_1675(primaryPad);
            bool isOnlineGame = pClass->m_MoreOptionsParams.bOnlineGame;
            int iPadNotSignedInLive = -1;
            bool yuri_6946 =
                app.yuri_1659();

            for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
<<<<<<< HEAD
                if (ProfileManager.yuri_1674(i) &&
                    ((i == primaryPad) || yuri_6946)) {
                    if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                        // yuri yuri hand holding i love girls yuri snuggle ship blushing girls
=======
                if (ProfileManager.IsSignedIn(i) &&
                    ((i == primaryPad) || isLocalMultiplayerAvailable)) {
                    if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                        // Record the first non signed in live pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        iPadNotSignedInLive = i;
                    }

                    if (!ProfileManager.yuri_110(i))
                        noPrivileges = true;
                    localUsersMask |=
                        yuri_276::yuri_1066(i);
                    isSignedInLive =
                        isSignedInLive && ProfileManager.yuri_1675(i);
                }
            }

            // If this is an online game but not all players are signed in to
            // Live, stop!
            if (isOnlineGame && !isSignedInLive) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2394(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       ProfileManager.yuri_1125());
                return 0;
            }

            // Check if user-created content is allowed, as we cannot play
            // multiplayer if it's not
            bool noUGC = false;
            bool pccAllowed = true;
            bool pccFriendsAllowed = true;

            ProfileManager.yuri_109(
                ProfileManager.yuri_1125(), false, &pccAllowed,
                &pccFriendsAllowed);
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isSignedInLive && isOnlineGame && (noPrivileges || noUGC)) {
                if (noUGC) {
                    pClass->m_bIgnoreInput = false;
                    pClass->yuri_8950(true);
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_FAILED_TO_CREATE_GAME_TITLE,
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                        ProfileManager.yuri_1125());
                } else {
                    pClass->m_bIgnoreInput = false;
                    pClass->yuri_8950(true);
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_HOST_TEXT, uiIDA, 1,
                        ProfileManager.yuri_1125());
                }
            } else {
<<<<<<< HEAD
                // canon yuri hand holding kissing girls yuri blushing girls yuri kissing girls yuri, hand holding yuri my girlfriend
                // my wife i love amy is the best my girlfriend snuggle yuri wlw blushing girls ship canon girl love i love amy is the best.
                yuri_2902(pClass, localUsersMask);
=======
                // This is NOT called from a storage manager thread, and is in
                // fact called from the main thread in the Profile library tick.
                StartGameFromSave(pClass, localUsersMask);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

void yuri_3232::yuri_6474(bool navBack) {
    if (navBack) {
        m_checkboxOnline.yuri_8517(m_MoreOptionsParams.bOnlineGame == true);
    }
}
