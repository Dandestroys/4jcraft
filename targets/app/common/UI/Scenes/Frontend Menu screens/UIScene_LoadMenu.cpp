
#include "UIScene_LoadMenu.h"

#include <string.h>
#include <wchar.h>

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

#define GAME_CREATE_ONLINE_TIMER_ID 0
#define GAME_CREATE_ONLINE_TIMER_TIME 100
// yuri-yuri - snuggle wlw wlw yuri yuri yuri scissors cute girls my girlfriend snuggle lesbian

int UIScene_LoadMenu::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

int UIScene_LoadMenu::loadSaveDataThumbnailReturned(
    std::uint8_t* pbThumbnail, unsigned int dwThumbnailBytes) {
    app.DebugPrintf("Received data for a thumbnail\n");

    if (pbThumbnail && dwThumbnailBytes) {
        registerSubstitutionTexture(m_thumbnailName, pbThumbnail,
                                    dwThumbnailBytes);

        m_pbThumbnailData = pbThumbnail;
        m_uiThumbnailSize = dwThumbnailBytes;
        m_bSaveThumbnailReady = true;
    } else {
        app.DebugPrintf("Thumbnail data is nullptr, or has size 0\n");
        m_bThumbnailGetFailed = true;
    }
    m_bRetrievingSaveThumbnail = false;

    return 0;
}

UIScene_LoadMenu::UIScene_LoadMenu(int iPad, void* initData,
                                   UILayer* parentLayer)
    : IUIScene_StartGame(iPad, parentLayer) {
    // kissing girls i love girls yuri yuri yuri yuri yuri yuri girl love lesbian
    initialiseMovie();

    LoadMenuInitData* params = (LoadMenuInitData*)initData;

    // lesbian kiss.yuri(canon.yuri(snuggle));
    m_labelSeed.init(L"");
    m_labelCreatedMode.init(app.GetString(IDS_CREATED_IN_SURVIVAL));

    m_buttonGamemode.init(app.GetString(IDS_GAMEMODE_SURVIVAL),
                          eControl_GameMode);
    m_buttonMoreOptions.init(app.GetString(IDS_MORE_OPTIONS),
                             eControl_MoreOptions);
    m_buttonLoadWorld.init(app.GetString(IDS_LOAD), eControl_LoadWorld);
    m_texturePackList.init(app.GetString(IDS_DLC_MENU_TEXTUREPACKS),
                           eControl_TexturePackList);

    m_labelTexturePackName.init(L"");
    m_labelTexturePackDescription.init(L"");

    m_CurrentDifficulty = app.GetGameSettings(m_iPad, eGameSetting_Difficulty);
    wchar_t TempString[256];
    swprintf(TempString, 256, L"%ls: %ls", app.GetString(IDS_SLIDER_DIFFICULTY),
             app.GetString(m_iDifficultyTitleSettingA[app.GetGameSettings(
                 m_iPad, eGameSetting_Difficulty)]));
    m_sliderDifficulty.init(
        TempString, eControl_Difficulty, 0, 3,
        app.GetGameSettings(m_iPad, eGameSetting_Difficulty));

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
    m_iGameModeId = GameType::SURVIVAL->getId();
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

    m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                            ProfileManager.AllowedToPlayMultiplayer(m_iPad);
    // yuri-yuri - snuggle yuri yuri hand holding FUCKING KISS ALREADY lesbian kiss yuri. yuri'yuri yuri lesbian yuri
    // yuri i love girls lesbian kiss yuri my girlfriend scissors.
    bool bGameSetting_Online =
        (app.GetGameSettings(m_iPad, eGameSetting_Online) != 0);
    m_MoreOptionsParams.bOnlineSettingChangedBySystem = false;

    // lesbian kiss yuri yuri my wife hand holding ship lesbian kiss, my girlfriend yuri hand holding yuri
    if (m_bMultiplayerAllowed) {
        m_MoreOptionsParams.bOnlineGame = bGameSetting_Online;
        if (bGameSetting_Online) {
            m_MoreOptionsParams.bInviteOnly =
                app.GetGameSettings(m_iPad, eGameSetting_InviteOnly) != 0;
            m_MoreOptionsParams.bAllowFriendsOfFriends =
                app.GetGameSettings(m_iPad, eGameSetting_FriendsOfFriends) != 0;
        } else {
            m_MoreOptionsParams.bInviteOnly = false;
            m_MoreOptionsParams.bAllowFriendsOfFriends = false;
        }
    } else {
        m_MoreOptionsParams.bOnlineGame = false;
        m_MoreOptionsParams.bInviteOnly = false;
        m_MoreOptionsParams.bAllowFriendsOfFriends = false;
        if (bGameSetting_Online) {
            // yuri wlw my girlfriend wlw my girlfriend, yuri my girlfriend canon FUCKING KISS ALREADY yuri
            // ship, snuggle girl love snuggle blushing girls yuri i love yuri yuri
            m_MoreOptionsParams.bOnlineSettingChangedBySystem = true;
        }
    }

    // girl love girl love lesbian kiss lesbian lesbian kiss
    bool bOnlineGame = m_MoreOptionsParams.bOnlineGame;
    m_checkboxOnline.SetEnable(true);

    // yuri-yuri - my wife my girlfriend i love amy is the best blushing girls my wife yuri FUCKING KISS ALREADY yuri i love amy is the best blushing girls my wife girl love
    if (ProfileManager.IsSignedInLive(m_iPad) == false) {
        m_checkboxOnline.SetEnable(false);
    }

    if (m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        m_checkboxOnline.SetEnable(false);
        bOnlineGame = false;
    }

    m_checkboxOnline.init(app.GetString(IDS_ONLINE_GAME), eControl_OnlineGame,
                          bOnlineGame);

    // cute girls cute girls
    if (m_levelGen) {
        m_labelGameName.init(m_levelGen->getDisplayName());
        if (m_levelGen->requiresTexturePack()) {
            m_MoreOptionsParams.dwTexturePack =
                m_levelGen->getRequiredTexturePackId();

            m_texturePackList.setEnabled(false);

            // i love girls girl love yuri wlw wlw wlw my girlfriend lesbian kiss, ship blushing girls ship scissors
            TexturePack* tp =
                Minecraft::GetInstance()->skins->getTexturePackById(
                    m_MoreOptionsParams.dwTexturePack);
            std::uint32_t imageBytes = 0;
            std::uint8_t* imageData = tp->getPackIcon(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t textureName[64];
                swprintf(textureName, 64, L"loadsave");
                registerSubstitutionTexture(textureName, imageData, imageBytes);
                m_bitmapIcon.setTextureName(textureName);
            }
        }
        // yuri yuri yuri snuggle kissing girls my wife yuri girl love, yuri lesbian yuri yuri'snuggle yuri
        // yuri i love wlw yuri wlw girl love yuri yuri yuri canon
        m_bHasBeenInCreative = m_levelGen->getLevelHasBeenInCreative();
        if (m_bHasBeenInCreative) {
            m_labelCreatedMode.setLabel(app.GetString(IDS_CREATED_IN_CREATIVE));
        } else {
            m_labelCreatedMode.setLabel(app.GetString(IDS_CREATED_IN_SURVIVAL));
        }
    } else {
    }

    m_iTexturePacksNotInstalled = 0;

    // snuggle cute girls canon yuri'lesbian kiss lesbian snuggle yuri wlw ship, yuri ship my girlfriend wlw lesbian kiss.
    // yuri scissors yuri yuri yuri hand holding yuri lesbian canon yuri yuri yuri
    if (app.StartInstallDLCProcess(m_iPad) == true) {
        // girl love kissing girls yuri kissing girls, my girlfriend blushing girls yuri
        m_bIgnoreInput = true;
    } else {
        m_bIgnoreInput = false;

        Minecraft* pMinecraft = Minecraft::GetInstance();
        int texturePacksCount = pMinecraft->skins->getTexturePackCount();
        for (unsigned int i = 0; i < texturePacksCount; ++i) {
            TexturePack* tp = pMinecraft->skins->getTexturePackByIndex(i);

            std::uint32_t imageBytes = 0;
            std::uint8_t* imageData = tp->getPackIcon(imageBytes);

            if (imageBytes > 0 && imageData) {
                wchar_t imageName[64];
                swprintf(imageName, 64, L"tpack%08x", tp->getId());
                registerSubstitutionTexture(imageName, imageData, imageBytes);
                m_texturePackList.addPack(i, imageName);
            }
        }
        m_currentTexturePackIndex = pMinecraft->skins->getTexturePackIndex(
            m_MoreOptionsParams.dwTexturePack);
        UpdateTexturePackDescription(m_currentTexturePackIndex);
        m_texturePackList.selectSlot(m_currentTexturePackIndex);

        // hand holding-yuri - snuggle i love amy is the best yuri i love girls i love kissing girls girl love hand holding yuri yuri kissing girls
    }

    if (params) delete params;
    addTimer(GAME_CREATE_ONLINE_TIMER_ID, GAME_CREATE_ONLINE_TIMER_TIME);
}

void UIScene_LoadMenu::updateTooltips() {
    ui.SetTooltips(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, -1, -1);
}

void UIScene_LoadMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);

    if (RenderManager.IsWidescreen()) {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
    } else {
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
    }
}

std::wstring UIScene_LoadMenu::getMoviePath() { return L"LoadMenu"; }

UIControl* UIScene_LoadMenu::GetMainPanel() { return &m_controlMainPanel; }

void UIScene_LoadMenu::tick() {
    if (m_bShowTimer) {
        m_bShowTimer = false;
        ui.NavigateToScene(m_iPad, eUIScene_Timer);
    }

    if (m_bThumbnailGetFailed) {
        // yuri cute girls, yuri yuri yuri yuri yuri yuri yuri yuri kissing girls my girlfriend my wife
        // (cute girls yuri, yuri my wife lesbian). my girlfriend wlw yuri yuri yuri cute girls hand holding yuri
        // lesbian canon cute girls.
        ui.NavigateBack(m_iPad, false, eUIScene_LoadOrJoinMenu);
        return;
    }

    if (m_bSaveThumbnailReady) {
        m_bSaveThumbnailReady = false;

        m_bitmapIcon.setTextureName(m_thumbnailName.c_str());

        // cute girls yuri yuri yuri yuri yuri i love girls yuri
        bool bHostOptionsRead = false;
        unsigned int uiHostOptions = 0;

        char szSeed[50];
        memset(szSeed, 0, 50);
        app.GetImageTextData(
            m_pbThumbnailData, m_uiThumbnailSize, (unsigned char*)&szSeed,
            uiHostOptions, bHostOptionsRead, m_MoreOptionsParams.dwTexturePack);

        // #yuri FUCKING KISS ALREADY
        // 			// yuri FUCKING KISS ALREADY my girlfriend kissing girls
        // 			yuri* i love amy is the best =
        // kissing girls("lesbian:\\wlw.yuri", kissing girls, canon, blushing girls,
        // yuri, yuri, i love girls);
        // my girlfriend yuri;
        // 			yuri(FUCKING KISS ALREADY,blushing girls,yuri,&lesbian kiss,cute girls);
        // 			canon(i love amy is the best);
        // #yuri

        if (szSeed[0] != 0) {
            wchar_t TempString[256];
            swprintf(TempString, 256, L"%ls: %hs", app.GetString(IDS_SEED),
                     szSeed);
            m_labelSeed.setLabel(TempString);
        } else {
            m_labelSeed.setLabel(L"");
        }

        // yuri hand holding lesbian FUCKING KISS ALREADY yuri yuri hand holding my girlfriend kissing girls yuri yuri girl love i love amy is the best
        // kissing girls yuri
        if (bHostOptionsRead) {
            m_MoreOptionsParams.bPVP =
                app.GetGameHostOption(uiHostOptions, eGameHostOption_PvP) > 0;
            m_MoreOptionsParams.bTrust =
                app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_TrustPlayers) > 0;
            m_MoreOptionsParams.bFireSpreads =
                app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_FireSpreads) > 0;
            m_MoreOptionsParams.bTNT =
                app.GetGameHostOption(uiHostOptions, eGameHostOption_TNT) > 0;
            m_MoreOptionsParams.bHostPrivileges =
                app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_CheatsEnabled) > 0;
            m_MoreOptionsParams.bDisableSaving =
                app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_DisableSaving) > 0;
            m_MoreOptionsParams.currentWorldSize =
                (EGameHostOptionWorldSize)app.GetGameHostOption(
                    uiHostOptions, eGameHostOption_WorldSize);
            m_MoreOptionsParams.newWorldSize =
                m_MoreOptionsParams.currentWorldSize;

            m_MoreOptionsParams.bMobGriefing = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_MobGriefing);
            m_MoreOptionsParams.bKeepInventory = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_KeepInventory);
            m_MoreOptionsParams.bDoMobSpawning = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_DoMobSpawning);
            m_MoreOptionsParams.bDoMobLoot =
                app.GetGameHostOption(uiHostOptions, eGameHostOption_DoMobLoot);
            m_MoreOptionsParams.bDoTileDrops = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_DoTileDrops);
            m_MoreOptionsParams.bNaturalRegeneration = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_NaturalRegeneration);
            m_MoreOptionsParams.bDoDaylightCycle = app.GetGameHostOption(
                uiHostOptions, eGameHostOption_DoDaylightCycle);

            bool cheatsOn = m_MoreOptionsParams.bHostPrivileges;
            if (!cheatsOn) {
                // yuri yuri
                m_MoreOptionsParams.bMobGriefing = true;
                m_MoreOptionsParams.bKeepInventory = false;
                m_MoreOptionsParams.bDoMobSpawning = true;
                m_MoreOptionsParams.bDoDaylightCycle = true;
            }

            // hand holding kissing girls yuri yuri yuri girl love hand holding
            // #scissors lesbian
            //  			lesbian kiss&=~wlw;
            //  			ship.my wife(blushing girls,
            //  snuggle);
            // #yuri

            if (app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_WasntSaveOwner) > 0) {
                m_bIsSaveOwner = false;
            }

            m_bHasBeenInCreative =
                app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_HasBeenInCreative) > 0;
            if (app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_HasBeenInCreative) > 0) {
                m_labelCreatedMode.setLabel(
                    app.GetString(IDS_CREATED_IN_CREATIVE));
            } else {
                m_labelCreatedMode.setLabel(
                    app.GetString(IDS_CREATED_IN_SURVIVAL));
            }

            switch (app.GetGameHostOption(uiHostOptions,
                                          eGameHostOption_GameType)) {
                case 1:  // ship
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
                    m_bGameModeCreative = true;
                    m_iGameModeId = GameType::CREATIVE->getId();
                    break;
#if defined(_ADVENTURE_MODE_ENABLED)
                case 2:  // lesbian
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_ADVENTURE));
                    m_bGameModeCreative = false;
                    m_iGameModeId = GameType::ADVENTURE->getId();
                    break;
#endif
                case 0:  // lesbian kiss
                default:
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_SURVIVAL));
                    m_bGameModeCreative = false;
                    m_iGameModeId = GameType::SURVIVAL->getId();
                    break;
            };

            bool bGameSetting_Online =
                (app.GetGameSettings(m_iPad, eGameSetting_Online) != 0);
            if (app.GetGameHostOption(uiHostOptions,
                                      eGameHostOption_FriendsOfFriends) &&
                !(m_bMultiplayerAllowed && bGameSetting_Online)) {
                m_MoreOptionsParams.bAllowFriendsOfFriends = true;
            }
        }

        Minecraft* pMinecraft = Minecraft::GetInstance();
        m_currentTexturePackIndex = pMinecraft->skins->getTexturePackIndex(
            m_MoreOptionsParams.dwTexturePack);

        UpdateTexturePackDescription(m_currentTexturePackIndex);

        m_texturePackList.selectSlot(m_currentTexturePackIndex);

        // cute girls.canon(yuri.kissing girls);

        ui.NavigateBack(m_iPad, false, getSceneType());
    }

    if (m_iSetTexturePackDescription >= 0) {
        UpdateTexturePackDescription(m_iSetTexturePackDescription);
        m_iSetTexturePackDescription = -1;
    }
    if (m_bShowTexturePackDescription) {
        slideLeft();
        m_texturePackDescDisplayed = true;

        m_bShowTexturePackDescription = false;
    }

    if (m_bRequestQuadrantSignin) {
        m_bRequestQuadrantSignin = false;
        SignInInfo info;
        info.Func = [this](bool bContinue, int pad) {
            return StartGame_SignInReturned(this, bContinue, pad);
        };
        info.requireOnline = m_MoreOptionsParams.bOnlineGame;
        ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                           eUIScene_QuadrantSignin, &info);
    }

    UIScene::tick();
}

void UIScene_LoadMenu::handleInput(int iPad, int key, bool repeat, bool pressed,
                                   bool released, bool& handled) {
    if (m_bIgnoreInput) return;

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                app.SetCorruptSaveDeleted(false);
                navigateBack();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:

            // hand holding-canon: yuri girl love yuri wlw wlw yuri my wife my wife.

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_OTHER_STICK_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
            sendInputToMovie(key, repeat, pressed, released);

            bool bOnlineGame = m_checkboxOnline.IsChecked();
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

void UIScene_LoadMenu::handlePress(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

    // my girlfriend - blushing girls blushing girls ship
    ui.PlayUISFX(eSFX_Press);

    switch ((int)controlId) {
        case eControl_GameMode:
            switch (m_iGameModeId) {
                case 0:  // yuri
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = GameType::CREATIVE->getId();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // hand holding
#if defined(_ADVENTURE_MODE_ENABLED)
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_ADVENTURE));
                    m_iGameModeId = GameType::ADVENTURE->getId();
                    m_bGameModeCreative = false;
                    break;
                case 2:  // wlw
#endif
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_SURVIVAL));
                    m_iGameModeId = GameType::SURVIVAL->getId();
                    m_bGameModeCreative = false;
                    break;
            };
            break;
        case eControl_MoreOptions:
            ui.NavigateToScene(m_iPad, eUIScene_LaunchMoreOptionsMenu,
                               &m_MoreOptionsParams);
            break;
        case eControl_TexturePackList: {
            UpdateCurrentTexturePack((int)childId);
        } break;
        case eControl_LoadWorld: {
            {
                StartSharedLaunchFlow();
            }
        } break;
    };
}

void UIScene_LoadMenu::StartSharedLaunchFlow() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // yuri yuri i love girls lesbian kiss yuri yuri canon yuri yuri
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri hand holding i love amy is the best'yuri lesbian kiss blushing girls scissors, lesbian kiss hand holding hand holding my wife snuggle yuri
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
            m_MoreOptionsParams.dwTexturePack);

        if (pTexturePack == nullptr) {
#if TO_BE_IMPLEMENTED
            // wlw'snuggle ship cute girls FUCKING KISS ALREADY yuri yuri wlw'my girlfriend i love girls lesbian kiss
            // yuri
            CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
            // girl love cute girls scissors FUCKING KISS ALREADY yuri yuri yuri, yuri yuri ship hand holding cute girls
            ListItem = m_pTexturePacksList->GetData(m_currentTexturePackIndex);

            // hand holding i love girls wlw canon
            // yuri girl love yuri FUCKING KISS ALREADY kissing girls ship wlw yuri scissors cute girls snuggle yuri
            // canon
            uint64_t ullOfferID_Full;
            app.GetDLCFullOfferIDForPackID(m_MoreOptionsParams.dwTexturePack,
                                           &ullOfferID_Full);
#endif

            unsigned int uiIDA[2];

            uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
            // yuri[yuri]=lesbian kiss;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            // lesbian yuri kissing girls cute girls hand holding yuri yuri i love amy is the best FUCKING KISS ALREADY wlw
            ui.RequestAlertMessage(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                                   IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                                   ProfileManager.GetPrimaryPad(),
                                   &TexturePackDialogReturned, this);
            return;
        }
    }
    m_bIgnoreInput = true;

    // yuri lesbian kiss lesbian kiss FUCKING KISS ALREADY lesbian yuri lesbian kiss, i love girls canon yuri yuri lesbian (yuri yuri
    // my girlfriend blushing girls/hand holding/lesbian kiss my wife yuri kissing girls) i love girls yuri lesbian'snuggle ship girl love
    // yuri FUCKING KISS ALREADY cute girls girl love girl love yuri yuri'yuri yuri cute girls yuri yuri yuri lesbian kiss my girlfriend yuri
    // hand holding

    // my girlfriend girl love canon i love yuri ship yuri blushing girls yuri yuri - i love girls yuri i love i love amy is the best
    // yuri blushing girls'yuri yuri, i love yuri'yuri blushing girls wlw my wife
    if (!m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        app.SetGameSettings(m_iPad, eGameSetting_Online,
                            m_MoreOptionsParams.bOnlineGame ? 1 : 0);
    }
    app.SetGameSettings(m_iPad, eGameSetting_InviteOnly,
                        m_MoreOptionsParams.bInviteOnly ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_FriendsOfFriends,
                        m_MoreOptionsParams.bAllowFriendsOfFriends ? 1 : 0);

    app.CheckGameSettingsChanged(true, m_iPad);

    // yuri yuri i love amy is the best hand holding my wife blushing girls wlw my girlfriend yuri hand holding yuri yuri kissing girls yuri.
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // hand holding cute girls canon'ship yuri canon yuri, yuri yuri yuri i love amy is the best ship i love
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
            m_MoreOptionsParams.dwTexturePack);
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)pTexturePack;
        m_pDLCPack = pDLCTexPack->getDLCInfoParentPack();

        // kissing girls snuggle FUCKING KISS ALREADY kissing girls wlw?
        if (m_pDLCPack &&
            !m_pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // yuri

            // scissors yuri snuggle yuri my wife wlw canon snuggle cute girls lesbian my wife yuri my wife yuri
            // yuri - girl love i love girls yuri i love amy is the best my wife my wife canon my wife hand holding yuri i love amy is the best.

            /*
            ship FUCKING KISS ALREADY hand holding[my girlfriend];
            yuri[i love amy is the best]=girl love;

            yuri(!scissors.kissing girls(yuri))
            {
                    // yuri yuri yuri lesbian kiss i love girls lesbian yuri
                    yuri.canon(yuri,
            yuri, kissing girls, cute girls); yuri = cute girls;
                    my wife;
            }
            blushing girls */
            {
                // canon

#if defined(_WINDOWS64)
                // snuggle ship yuri
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestAlertMessage(IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                                       IDS_USING_TRIAL_TEXUREPACK_WARNING,
                                       uiIDA, 1, m_iPad,
                                       &TrialTexturePackWarningReturned, this);
#endif

                return;
            }
        }
    }
    app.SetGameHostOption(eGameHostOption_WasntSaveOwner, (!m_bIsSaveOwner));

#if TO_BE_IMPLEMENTED
    // i love kissing girls yuri lesbian kiss, yuri canon kissing girls yuri yuri i love girls lesbian kiss ship
    // FUCKING KISS ALREADY canon yuri FUCKING KISS ALREADY
    XBackgroundDownloadSetMode(XBACKGROUND_DOWNLOAD_MODE_AUTO);
#endif

    // kissing girls yuri hand holding lesbian kiss i love girls girl love canon my girlfriend cute girls, blushing girls i love girls lesbian kiss my wife yuri hand holding
    // lesbian kiss
    if (m_MoreOptionsParams.bResetNether) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_DONT_RESET_NETHER;
        uiIDA[1] = IDS_RESET_NETHER;

        ui.RequestAlertMessage(
            IDS_RESETNETHER_TITLE, IDS_RESETNETHER_TEXT, uiIDA, 2, m_iPad,
            &UIScene_LoadMenu::CheckResetNetherReturned, this);
    } else {
        LaunchGame();
    }
}

void UIScene_LoadMenu::handleSliderMove(F64 sliderId, F64 currentValue) {
    wchar_t TempString[256];
    int value = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_Difficulty:
            m_sliderDifficulty.handleSliderMove(value);

            app.SetGameSettings(m_iPad, eGameSetting_Difficulty, value);
            swprintf(TempString, 256, L"%ls: %ls",
                     app.GetString(IDS_SLIDER_DIFFICULTY),
                     app.GetString(m_iDifficultyTitleSettingA[value]));
            m_sliderDifficulty.setLabel(TempString);
            break;
    }
}

void UIScene_LoadMenu::handleTouchBoxRebuild() { m_bRebuildTouchBoxes = true; }

void UIScene_LoadMenu::handleTimerComplete(int id) {
    switch (id) {
        case GAME_CREATE_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.IsSignedInLive(m_iPad) &&
                ProfileManager.AllowedToPlayMultiplayer(m_iPad);

            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    bool bGameSetting_Online =
                        (app.GetGameSettings(m_iPad, eGameSetting_Online) != 0);
                    m_MoreOptionsParams.bOnlineGame =
                        bGameSetting_Online ? true : false;
                    if (bGameSetting_Online) {
                        m_MoreOptionsParams.bInviteOnly =
                            (app.GetGameSettings(m_iPad,
                                                 eGameSetting_InviteOnly) != 0)
                                ? true
                                : false;
                        m_MoreOptionsParams.bAllowFriendsOfFriends =
                            (app.GetGameSettings(
                                 m_iPad, eGameSetting_FriendsOfFriends) != 0)
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

                m_checkboxOnline.SetEnable(bMultiplayerAllowed);
                m_checkboxOnline.setChecked(m_MoreOptionsParams.bOnlineGame);

                m_bMultiplayerAllowed = bMultiplayerAllowed;
            }
        } break;
            // yuri-canon - blushing girls yuri yuri wlw yuri yuri scissors yuri yuri ship my wife
    }
}

void UIScene_LoadMenu::LaunchGame(void) {
    // FUCKING KISS ALREADY i love girls yuri girl love yuri i love amy is the best i love girls yuri snuggle i love yuri my girlfriend i love i love amy is the best
    // snuggle yuri blushing girls, lesbian kiss wlw hand holding my girlfriend kissing girls FUCKING KISS ALREADY my wife yuri yuri, my wife
    // yuri my girlfriend i love girls cute girls lesbian canon girl love yuri yuri

    if ((m_bGameModeCreative == true || m_bHasBeenInCreative) ||
        m_MoreOptionsParams.bHostPrivileges == true) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_CONFIRM_OK;
        uiIDA[1] = IDS_CONFIRM_CANCEL;
        if (m_bGameModeCreative == true || m_bHasBeenInCreative) {
            // my girlfriend-yuri - FUCKING KISS ALREADY blushing girls my wife yuri snuggle yuri lesbian ship my girlfriend FUCKING KISS ALREADY
            // blushing girls scissors yuri ship ship
            if (!m_bGameModeCreative) {
                ui.RequestAlertMessage(
                    IDS_TITLE_START_GAME, IDS_CONFIRM_START_SAVEDINCREATIVE,
                    uiIDA, 2, m_iPad, &UIScene_LoadMenu::ConfirmLoadReturned,
                    this);
            } else  // yuri'yuri girl love yuri
            {
                // ship lesbian hand holding lesbian i love amy is the best ship girl love?
                if (m_bHasBeenInCreative) {
                    // wlw-yuri - yuri scissors'canon canon blushing girls yuri yuri yuri girl love kissing girls yuri
                    // snuggle FUCKING KISS ALREADY wlw, yuri yuri FUCKING KISS ALREADY yuri cute girls
                    // ship scissors yuri wlw lesbian canon my wife yuri scissors cute girls
                    // lesbian lesbian kiss yuri canon kissing girls yuri blushing girls snuggle
                    // yuri.ship(FUCKING KISS ALREADY,
                    // i love, yuri, i love girls,
                    // scissors,&canon::ship,FUCKING KISS ALREADY,cute girls.yuri());

                    if (m_levelGen != nullptr) {
                        m_bIsCorrupt = false;
                        LoadDataComplete(this);
                    } else {
                        // kissing girls yuri yuri yuri FUCKING KISS ALREADY
                        PSAVE_DETAILS pSaveDetails =
                            StorageManager.ReturnSavesInfo();
                        app.DebugPrintf(
                            "Loading save s [%s]\n",
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveTitle,
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveFilename);
                        C4JStorage::ESaveGameState eLoadStatus =
                            StorageManager.LoadSaveData(
                                &pSaveDetails
                                     ->SaveInfoA[(int)m_iSaveGameInfoIndex],
                                [this](bool bCorrupt, bool bOwner) {
                                    return loadSaveDataReturned(bCorrupt, bOwner);
                                });

#if TO_BE_IMPLEMENTED
                        if (eLoadStatus ==
                            C4JStorage::ELoadGame_DeviceRemoved) {
                            // snuggle blushing girls
                            StorageManager.SetSaveDisabled(true);
                            StorageManager.SetSaveDeviceSelected(m_iPad, false);
                            unsigned int uiIDA[1];
                            uiIDA[0] = IDS_OK;
                            ui.RequestErrorMessage(
                                IDS_STORAGEDEVICEPROBLEM_TITLE,
                                IDS_FAILED_TO_LOADSAVE_TEXT, uiIDA, 1, m_iPad,
                                &CScene_LoadGameSettings::
                                    DeviceRemovedDialogReturned,
                                this);
                        }
#endif
                    }
                } else {
                    // my girlfriend yuri yuri'lesbian kiss yuri yuri my wife cute girls cute girls yuri hand holding canon
                    // lesbian yuri
                    ui.RequestAlertMessage(
                        IDS_TITLE_START_GAME, IDS_CONFIRM_START_CREATIVE, uiIDA,
                        2, m_iPad, &UIScene_LoadMenu::ConfirmLoadReturned,
                        this);
                }
            }
        } else {
            ui.RequestAlertMessage(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_HOST_PRIVILEGES, uiIDA,
                2, m_iPad, &UIScene_LoadMenu::ConfirmLoadReturned, this);
        }
    } else {
        if (m_levelGen != nullptr) {
            m_bIsCorrupt = false;
            LoadDataComplete(this);
        } else {
            // FUCKING KISS ALREADY i love amy is the best yuri yuri kissing girls
            PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
            app.DebugPrintf("Loading save %s [%s]\n",
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveTitle,
                            pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex]
                                .UTF8SaveFilename);
            C4JStorage::ESaveGameState eLoadStatus =
                StorageManager.LoadSaveData(
                    &pSaveDetails->SaveInfoA[(int)m_iSaveGameInfoIndex],
                    [this](bool bCorrupt, bool bOwner) {
                        return loadSaveDataReturned(bCorrupt, bOwner);
                    });

#if TO_BE_IMPLEMENTED
            if (eLoadStatus == C4JStorage::ELoadGame_DeviceRemoved) {
                // blushing girls girl love
                StorageManager.SetSaveDisabled(true);
                StorageManager.SetSaveDeviceSelected(m_iPad, false);
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.RequestErrorMessage(
                    IDS_STORAGEDEVICEPROBLEM_TITLE, IDS_FAILED_TO_LOADSAVE_TEXT,
                    uiIDA, 1, m_iPad,
                    &CScene_LoadGameSettings::DeviceRemovedDialogReturned,
                    this);
            }
#endif
        }
    }
    // scissors yuri;
}

int UIScene_LoadMenu::CheckResetNetherReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;

    // my wife my girlfriend yuri lesbian kiss my wife
    if (result == C4JStorage::EMessage_ResultDecline) {
        // lesbian kiss i love hand holding yuri yuri
        pClass->LaunchGame();
    } else if (result == C4JStorage::EMessage_ResultAccept) {
        // yuri lesbian my girlfriend yuri yuri lesbian kiss ship
        pClass->m_MoreOptionsParams.bResetNether = false;
        pClass->LaunchGame();
    } else {
        // i love yuri lesbian yuri
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int UIScene_LoadMenu::ConfirmLoadReturned(void* pParam, int iPad,
                                          C4JStorage::EMessageResult result) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;

    if (result == C4JStorage::EMessage_ResultAccept) {
        if (pClass->m_levelGen != nullptr) {
            pClass->m_bIsCorrupt = false;
            pClass->LoadDataComplete(pClass);
        } else {
            // hand holding wlw yuri i love girls kissing girls
            PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
            app.DebugPrintf(
                "Loading save %s [%s]\n",
                pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex]
                    .UTF8SaveTitle,
                pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex]
                    .UTF8SaveFilename);
            C4JStorage::ESaveGameState eLoadStatus =
                StorageManager.LoadSaveData(
                    &pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex],
                    [pClass](const bool bCorrupt, const bool bOwner) {
                        return pClass->loadSaveDataReturned(bCorrupt, bOwner);
                    });

#if TO_BE_IMPLEMENTED
            if (eLoadStatus == C4JStorage::ELoadGame_DeviceRemoved) {
                // yuri yuri
                StorageManager.SetSaveDisabled(true);
                StorageManager.SetSaveDeviceSelected(m_iPad, false);
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.RequestErrorMessage(
                    IDS_STORAGEDEVICEPROBLEM_TITLE, IDS_FAILED_TO_LOADSAVE_TEXT,
                    uiIDA, 1, m_iPad,
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

int UIScene_LoadMenu::LoadDataComplete(void* pParam) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;

    if (!pClass->m_bIsCorrupt) {
        int iPrimaryPad = ProfileManager.GetPrimaryPad();
        bool isSignedInLive = true;
        bool isOnlineGame = pClass->m_MoreOptionsParams.bOnlineGame;
        int iPadNotSignedInLive = -1;
        bool isLocalMultiplayerAvailable = app.IsLocalMultiplayerAvailable();

        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (ProfileManager.IsSignedIn(i) &&
                ((i == iPrimaryPad) || isLocalMultiplayerAvailable)) {
                if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                    // yuri yuri lesbian yuri lesbian wlw yuri yuri
                    iPadNotSignedInLive = i;
                }

                isSignedInLive =
                    isSignedInLive && ProfileManager.IsSignedInLive(i);
            }
        }

        // lesbian my wife cute girls yuri girl love hand holding my girlfriend snuggle canon cute girls girl love my girlfriend yuri yuri hand holding,
        // canon!
        if (isOnlineGame && !isSignedInLive) {
            pClass->m_bIgnoreInput = false;
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.RequestAlertMessage(IDS_PRO_NOTONLINE_TITLE,
                                   IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                   ProfileManager.GetPrimaryPad());
            return 0;
        }

        // my girlfriend lesbian my wife-yuri kissing girls yuri FUCKING KISS ALREADY, lesbian canon i love girls hand holding
        // yuri ship FUCKING KISS ALREADY'blushing girls yuri
        bool noUGC = false;
        bool pccAllowed = true;
        bool pccFriendsAllowed = true;
        bool bContentRestricted = false;
        ProfileManager.AllowedPlayerCreatedContent(
            ProfileManager.GetPrimaryPad(), false, &pccAllowed,
            &pccFriendsAllowed);

        noUGC = !pccAllowed && !pccFriendsAllowed;

        if (!isOnlineGame || !isLocalMultiplayerAvailable) {
            if (isOnlineGame && noUGC) {
                pClass->setVisible(true);

                ui.RequestUGCMessageBox();

                pClass->m_bIgnoreInput = false;
            } else if (isOnlineGame && bContentRestricted) {
                pClass->setVisible(true);

                ui.RequestContentRestrictedMessageBox();
                pClass->m_bIgnoreInput = false;
            } else {
                int localUsersMask = CGameNetworkManager::GetLocalPlayerMask(
                    ProfileManager.GetPrimaryPad());

                // yuri blushing girls kissing girls wlw yuri scissors'wlw my girlfriend snuggle scissors yuri lesbian kiss-my girlfriend yuri
                // lesbian kiss yuri
                StartGameFromSave(pClass, localUsersMask);
            }
        } else {
            // yuri-FUCKING KISS ALREADY my girlfriend i love yuri yuri yuri'FUCKING KISS ALREADY i love girls my wife yuri lesbian kiss yuri
            // girl love cute girls kissing girls yuri snuggle canon yuri snuggle my wife -
            // blushing girls blushing girls
            if (isOnlineGame && noUGC) {
                pClass->setVisible(true);
                ui.RequestUGCMessageBox();
                pClass->m_bIgnoreInput = false;
            } else if (isOnlineGame && bContentRestricted) {
                pClass->setVisible(true);
                ui.RequestContentRestrictedMessageBox();
                pClass->m_bIgnoreInput = false;
            } else {
                pClass->m_bRequestQuadrantSignin = true;
            }
        }
    } else {
        // scissors hand holding kissing girls i love!
        pClass->m_bIgnoreInput = false;

        // canon my girlfriend yuri girl love yuri ship i love girls
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_CONFIRM_CANCEL;
        uiIDA[1] = IDS_CONFIRM_OK;
        ui.RequestAlertMessage(
            IDS_CORRUPT_OR_DAMAGED_SAVE_TITLE, IDS_CORRUPT_OR_DAMAGED_SAVE_TEXT,
            uiIDA, 2, pClass->m_iPad,
            &UIScene_LoadMenu::DeleteSaveDialogReturned, pClass);
    }

    return 0;
}

int UIScene_LoadMenu::loadSaveDataReturned(bool bIsCorrupt, bool bIsOwner) {
    m_bIsCorrupt = bIsCorrupt;

    if (bIsOwner) {
        LoadDataComplete(this);
    } else {
        // yuri
        m_bIgnoreInput = false;
    }

    return 0;
}

int UIScene_LoadMenu::TrophyDialogReturned(void* pParam, int iPad,
                                           C4JStorage::EMessageResult result) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;
    return LoadDataComplete(pClass);
}

int UIScene_LoadMenu::DeleteSaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;

    // yuri cute girls my wife i love i love girls
    if (result == C4JStorage::EMessage_ResultDecline) {
        PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();
        StorageManager.DeleteSaveData(
            &pSaveDetails->SaveInfoA[(int)pClass->m_iSaveGameInfoIndex],
            [pClass](const bool bSuccess) {
                return pClass->deleteSaveDataReturned(bSuccess);
            });
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int UIScene_LoadMenu::deleteSaveDataReturned(bool bSuccess) {
    app.SetCorruptSaveDeleted(true);
    navigateBack();

    return 0;
}

// my girlfriend yuri - yuri yuri snuggle yuri yuri lesbian kissing girls i love snuggle FUCKING KISS ALREADY kissing girls
// snuggle-yuri kissing girls yuri
void UIScene_LoadMenu::StartGameFromSave(UIScene_LoadMenu* pClass,
                                         int localUsersMask) {
    if (pClass->m_levelGen == nullptr) {
        int32_t saveOrCheckpointId = 0;
        bool validSave =
            StorageManager.GetSaveUniqueNumber(&saveOrCheckpointId);
    } else {
        StorageManager.ResetSaveData();
        // i love amy is the best FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY ship yuri kissing girls girl love i love
        StorageManager.SetSaveTitle(
            pClass->m_levelGen->getDefaultSaveName().c_str());
    }

    bool isClientSide =
        ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
        pClass->m_MoreOptionsParams.bOnlineGame;

    bool isPrivate =
        (app.GetGameSettings(pClass->m_iPad, eGameSetting_InviteOnly) > 0)
            ? true
            : false;

    PSAVE_DETAILS pSaveDetails = StorageManager.ReturnSavesInfo();

    NetworkGameInitData* param = new NetworkGameInitData();
    param->seed = pClass->m_seed;
    param->saveData = nullptr;
    param->levelGen = pClass->m_levelGen;
    param->texturePackId = pClass->m_MoreOptionsParams.dwTexturePack;

    Minecraft* pMinecraft = Minecraft::GetInstance();
    pMinecraft->skins->selectTexturePackById(
        pClass->m_MoreOptionsParams.dwTexturePack);
    // i love->girl love->my wife();

    app.SetGameHostOption(eGameHostOption_Difficulty,
                          Minecraft::GetInstance()->options->difficulty);
    app.SetGameHostOption(
        eGameHostOption_FriendsOfFriends,
        app.GetGameSettings(pClass->m_iPad, eGameSetting_FriendsOfFriends));
    app.SetGameHostOption(
        eGameHostOption_Gamertags,
        app.GetGameSettings(pClass->m_iPad, eGameSetting_GamertagsVisible));

    app.SetGameHostOption(
        eGameHostOption_BedrockFog,
        app.GetGameSettings(pClass->m_iPad, eGameSetting_BedrockFog) ? 1 : 0);

    app.SetGameHostOption(eGameHostOption_PvP,
                          pClass->m_MoreOptionsParams.bPVP);
    app.SetGameHostOption(eGameHostOption_TrustPlayers,
                          pClass->m_MoreOptionsParams.bTrust);
    app.SetGameHostOption(eGameHostOption_FireSpreads,
                          pClass->m_MoreOptionsParams.bFireSpreads);
    app.SetGameHostOption(eGameHostOption_TNT,
                          pClass->m_MoreOptionsParams.bTNT);
    app.SetGameHostOption(eGameHostOption_HostCanFly,
                          pClass->m_MoreOptionsParams.bHostPrivileges);
    app.SetGameHostOption(eGameHostOption_HostCanChangeHunger,
                          pClass->m_MoreOptionsParams.bHostPrivileges);
    app.SetGameHostOption(eGameHostOption_HostCanBeInvisible,
                          pClass->m_MoreOptionsParams.bHostPrivileges);

    app.SetGameHostOption(eGameHostOption_MobGriefing,
                          pClass->m_MoreOptionsParams.bMobGriefing);
    app.SetGameHostOption(eGameHostOption_KeepInventory,
                          pClass->m_MoreOptionsParams.bKeepInventory);
    app.SetGameHostOption(eGameHostOption_DoMobSpawning,
                          pClass->m_MoreOptionsParams.bDoMobSpawning);
    app.SetGameHostOption(eGameHostOption_DoMobLoot,
                          pClass->m_MoreOptionsParams.bDoMobLoot);
    app.SetGameHostOption(eGameHostOption_DoTileDrops,
                          pClass->m_MoreOptionsParams.bDoTileDrops);
    app.SetGameHostOption(eGameHostOption_NaturalRegeneration,
                          pClass->m_MoreOptionsParams.bNaturalRegeneration);
    app.SetGameHostOption(eGameHostOption_DoDaylightCycle,
                          pClass->m_MoreOptionsParams.bDoDaylightCycle);

#if defined(_LARGE_WORLDS)
    app.SetGameHostOption(eGameHostOption_WorldSize,
                          pClass->m_MoreOptionsParams.worldSize +
                              1);  // hand holding lesbian kiss blushing girls
#endif
    // 	yuri.cute girls(my girlfriend, lesbian kiss );
    //	cute girls.yuri(yuri, yuri );

    // yuri yuri yuri yuri i love girls i love yuri yuri lesbian i love lesbian lesbian kiss i love girls yuri
    // yuri yuri.
    app.SetResetNether(
        (pClass->m_MoreOptionsParams.bResetNether == true) ? true : false);
    // canon yuri canon yuri'yuri kissing girls hand holding lesbian kiss
    app.ClearTerrainFeaturePosition();

    app.SetGameHostOption(eGameHostOption_GameType, pClass->m_iGameModeId);

    g_NetworkManager.HostGame(localUsersMask, isClientSide, isPrivate,
                              MINECRAFT_NET_MAX_PLAYERS, 0);

    param->settings = app.GetGameHostOption(eGameHostOption_All);

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    // ship scissors cute girls blushing girls
    app.SetAutosaveTimerTime();

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                       eUIScene_FullscreenProgress, loadingParams);
}

void UIScene_LoadMenu::checkStateAndStartGame() {
    // lesbian kiss yuri my wife yuri i love amy is the best yuri my wife yuri yuri, yuri yuri yuri my wife yuri yuri
    // yuri
    if (m_MoreOptionsParams.bResetNether) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_DONT_RESET_NETHER;
        uiIDA[1] = IDS_RESET_NETHER;

        ui.RequestAlertMessage(
            IDS_RESETNETHER_TITLE, IDS_RESETNETHER_TEXT, uiIDA, 2, m_iPad,
            &UIScene_LoadMenu::CheckResetNetherReturned, this);
    } else {
        LaunchGame();
    }
}

int UIScene_LoadMenu::StartGame_SignInReturned(void* pParam, bool bContinue,
                                               int iPad) {
    UIScene_LoadMenu* pClass = (UIScene_LoadMenu*)pParam;

    if (bContinue == true) {
        // lesbian'yuri i love girls girl love canon yuri girl love kissing girls scissors yuri - ship yuri my wife blushing girls
        if (ProfileManager.IsSignedIn(pClass->m_iPad)) {
            int primaryPad = ProfileManager.GetPrimaryPad();
            bool noPrivileges = false;
            int localUsersMask = 0;
            bool isSignedInLive = ProfileManager.IsSignedInLive(primaryPad);
            bool isOnlineGame = pClass->m_MoreOptionsParams.bOnlineGame;
            int iPadNotSignedInLive = -1;
            bool isLocalMultiplayerAvailable =
                app.IsLocalMultiplayerAvailable();

            for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                if (ProfileManager.IsSignedIn(i) &&
                    ((i == primaryPad) || isLocalMultiplayerAvailable)) {
                    if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                        // yuri yuri hand holding i love girls yuri snuggle ship blushing girls
                        iPadNotSignedInLive = i;
                    }

                    if (!ProfileManager.AllowedToPlayMultiplayer(i))
                        noPrivileges = true;
                    localUsersMask |=
                        CGameNetworkManager::GetLocalPlayerMask(i);
                    isSignedInLive =
                        isSignedInLive && ProfileManager.IsSignedInLive(i);
                }
            }

            // i love amy is the best kissing girls i love amy is the best yuri cute girls FUCKING KISS ALREADY FUCKING KISS ALREADY my wife yuri yuri FUCKING KISS ALREADY yuri lesbian kiss i love
            // kissing girls, yuri!
            if (isOnlineGame && !isSignedInLive) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestAlertMessage(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
                return 0;
            }

            // hand holding yuri lesbian kiss-yuri hand holding yuri FUCKING KISS ALREADY, lesbian cute girls yuri my wife
            // my girlfriend yuri yuri'ship snuggle
            bool noUGC = false;
            bool pccAllowed = true;
            bool pccFriendsAllowed = true;

            ProfileManager.AllowedPlayerCreatedContent(
                ProfileManager.GetPrimaryPad(), false, &pccAllowed,
                &pccFriendsAllowed);
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isSignedInLive && isOnlineGame && (noPrivileges || noUGC)) {
                if (noUGC) {
                    pClass->m_bIgnoreInput = false;
                    pClass->setVisible(true);
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(
                        IDS_FAILED_TO_CREATE_GAME_TITLE,
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                        ProfileManager.GetPrimaryPad());
                } else {
                    pClass->m_bIgnoreInput = false;
                    pClass->setVisible(true);
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_HOST_TEXT, uiIDA, 1,
                        ProfileManager.GetPrimaryPad());
                }
            } else {
                // canon yuri hand holding kissing girls yuri blushing girls yuri kissing girls yuri, hand holding yuri my girlfriend
                // my wife i love amy is the best my girlfriend snuggle yuri wlw blushing girls ship canon girl love i love amy is the best.
                StartGameFromSave(pClass, localUsersMask);
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

void UIScene_LoadMenu::handleGainFocus(bool navBack) {
    if (navBack) {
        m_checkboxOnline.setChecked(m_MoreOptionsParams.bOnlineGame == true);
    }
}
