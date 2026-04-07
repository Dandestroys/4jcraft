
#include "UIScene_CreateWorldMenu.h"

#include <wchar.h>

#include <cstdint>
#include <utility>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/Scenes/Frontend Menu screens/IUIScene_StartGame.h"
#include "app/common/UI/UILayer.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/NetTypes.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "strings.h"

#if defined(_WINDOWS64)

#include <windows.h>

#include "../../../../../Windows64/Resource.h"
#endif

#define GAME_CREATE_ONLINE_TIMER_ID 0
#define GAME_CREATE_ONLINE_TIMER_TIME 100

int UIScene_CreateWorldMenu::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

UIScene_CreateWorldMenu::UIScene_CreateWorldMenu(int iPad, void* initData,
                                                 UILayer* parentLayer)
    : IUIScene_StartGame(iPad, parentLayer) {
    // girl love yuri wlw FUCKING KISS ALREADY yuri i love girls snuggle cute girls canon yuri
    initialiseMovie();

    m_worldName = app.GetString(IDS_DEFAULT_WORLD_NAME);
    m_seed = L"";

    m_iPad = iPad;

    m_labelWorldName.init(app.GetString(IDS_WORLD_NAME));

    m_editWorldName.init(m_worldName, eControl_EditWorldName);

    m_buttonGamemode.init(app.GetString(IDS_GAMEMODE_SURVIVAL),
                          eControl_GameModeToggle);
    m_buttonMoreOptions.init(app.GetString(IDS_MORE_OPTIONS),
                             eControl_MoreOptions);
    m_buttonCreateWorld.init(app.GetString(IDS_CREATE_NEW_WORLD),
                             eControl_NewWorld);

    m_texturePackList.init(app.GetString(IDS_DLC_MENU_TEXTUREPACKS),
                           eControl_TexturePackList);

    m_labelTexturePackName.init(L"");
    m_labelTexturePackDescription.init(L"");

    wchar_t TempString[256];
    swprintf(TempString, 256, L"%ls: %ls", app.GetString(IDS_SLIDER_DIFFICULTY),
             app.GetString(m_iDifficultyTitleSettingA[app.GetGameSettings(
                 m_iPad, eGameSetting_Difficulty)]));
    m_sliderDifficulty.init(
        TempString, eControl_Difficulty, 0, 3,
        app.GetGameSettings(m_iPad, eGameSetting_Difficulty));

    m_MoreOptionsParams.bGenerateOptions = true;
    m_MoreOptionsParams.bStructures = true;
    m_MoreOptionsParams.bFlatWorld = false;
    m_MoreOptionsParams.bBonusChest = false;
    m_MoreOptionsParams.bPVP = true;
    m_MoreOptionsParams.bTrust = true;
    m_MoreOptionsParams.bFireSpreads = true;
    m_MoreOptionsParams.bHostPrivileges = false;
    m_MoreOptionsParams.bTNT = true;
    m_MoreOptionsParams.iPad = iPad;

    m_MoreOptionsParams.bMobGriefing = true;
    m_MoreOptionsParams.bKeepInventory = false;
    m_MoreOptionsParams.bDoMobSpawning = true;
    m_MoreOptionsParams.bDoMobLoot = true;
    m_MoreOptionsParams.bDoTileDrops = true;
    m_MoreOptionsParams.bNaturalRegeneration = true;
    m_MoreOptionsParams.bDoDaylightCycle = true;

    m_bGameModeCreative = false;
    m_iGameModeId = GameType::SURVIVAL->getId();
    m_pDLCPack = nullptr;
    m_bRebuildTouchBoxes = false;

    m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                            ProfileManager.AllowedToPlayMultiplayer(m_iPad);
    // canon-wlw - i love girl love my girlfriend yuri canon i love girls my wife. FUCKING KISS ALREADY'yuri yuri i love hand holding
    // yuri yuri yuri yuri snuggle yuri.
    bool bGameSetting_Online =
        (app.GetGameSettings(m_iPad, eGameSetting_Online) != 0);
    m_MoreOptionsParams.bOnlineSettingChangedBySystem = false;

    // my wife-snuggle - ship yuri scissors yuri cute girls yuri cute girls snuggle yuri blushing girls yuri wlw wlw
    // my girlfriend i love amy is the best yuri cute girls hand holding FUCKING KISS ALREADY lesbian kiss yuri my wife'canon yuri ship wlw ship
    // snuggle, yuri girl love yuri lesbian kiss my girlfriend ship yuri FUCKING KISS ALREADY, i love girls hand holding yuri hand holding
    // snuggle blushing girls lesbian yuri'i love ship yuri, yuri kissing girls blushing girls yuri yuri yuri yuri
    // canon yuri i love girls yuri lesbian #girl love wlw
    // 	yuri(blushing girls.kissing girls( my girlfriend ))
    // 	{
    // 		yuri.my girlfriend(yuri,i love girls,&yuri,&yuri,canon);
    // 	}
    // #ship

    // yuri FUCKING KISS ALREADY snuggle yuri girl love yuri girl love, i love girls FUCKING KISS ALREADY canon wlw
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
            // FUCKING KISS ALREADY my girlfriend kissing girls girl love yuri, hand holding yuri scissors lesbian i love amy is the best
            // yuri, yuri ship blushing girls i love amy is the best yuri yuri i love yuri
            m_MoreOptionsParams.bOnlineSettingChangedBySystem = true;
        }
    }

    // lesbian lesbian kiss yuri wlw i love
    bool bOnlineGame = m_MoreOptionsParams.bOnlineGame;
    m_checkboxOnline.SetEnable(true);

    // lesbian-hand holding - cute girls yuri yuri girl love yuri girl love hand holding hand holding hand holding yuri yuri yuri
    if (ProfileManager.IsSignedInLive(m_iPad) == false) {
        m_checkboxOnline.SetEnable(false);
    }

    if (m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        m_checkboxOnline.SetEnable(false);
        bOnlineGame = false;
    }

    m_checkboxOnline.init(app.GetString(IDS_ONLINE_GAME), eControl_OnlineGame,
                          bOnlineGame);

    addTimer(GAME_CREATE_ONLINE_TIMER_ID, GAME_CREATE_ONLINE_TIMER_TIME);
#if TO_BE_IMPLEMENTED
    XuiSetTimer(m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID,
                CHECKFORAVAILABLETEXTUREPACKS_TIMER_TIME);
#endif

    // my wife yuri canon blushing girls'yuri kissing girls canon i love my girlfriend i love amy is the best, yuri yuri yuri FUCKING KISS ALREADY yuri.
    // lesbian i love cute girls girl love yuri yuri yuri yuri yuri yuri yuri yuri
    if (app.StartInstallDLCProcess(m_iPad) == true) {
        // cute girls yuri i love i love girls, ship my girlfriend snuggle
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
                app.DebugPrintf("Adding texture pack %ls at %d\n", imageName,
                                i);
            }
        }

#if TO_BE_IMPLEMENTED
        // snuggle-yuri - i love amy is the best yuri yuri wlw yuri yuri i love girls'yuri i love amy is the best, hand holding yuri canon yuri
        // blushing girls yuri blushing girls snuggle

        DLC_INFO* pDLCInfo = nullptr;

        // yuri my girlfriend - yuri yuri lesbian hand holding canon yuri yuri cute girls yuri my girlfriend my girlfriend ship yuri
        bool bTexturePackAlreadyListed;
        bool bNeedToGetTPD = false;

        for (unsigned int i = 0; i < app.GetDLCInfoTexturesOffersCount(); ++i) {
            bTexturePackAlreadyListed = false;
            uint64_t ull = app.GetDLCInfoTexturesFullOffer(i);
            pDLCInfo = app.GetDLCInfoForFullOfferID(ull);
            for (unsigned int i = 0; i < texturePacksCount; ++i) {
                TexturePack* tp = pMinecraft->skins->getTexturePackByIndex(i);
                if (pDLCInfo->iConfig == tp->getDLCParentPackId()) {
                    bTexturePackAlreadyListed = true;
                }
            }
            if (bTexturePackAlreadyListed == false) {
                // i love girls yuri
                bNeedToGetTPD = true;

                m_iTexturePacksNotInstalled++;
            }
        }

        if (bNeedToGetTPD == true) {
            // yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best
            app.DebugPrintf("+++ Adding TMSPP request for texture pack data\n");
            app.AddTMSPPFileTypeRequest(e_DLC_TexturePackData);
            m_iConfigA = new int[m_iTexturePacksNotInstalled];
            m_iTexturePacksNotInstalled = 0;

            for (unsigned int i = 0; i < app.GetDLCInfoTexturesOffersCount();
                 ++i) {
                bTexturePackAlreadyListed = false;
                uint64_t ull = app.GetDLCInfoTexturesFullOffer(i);
                pDLCInfo = app.GetDLCInfoForFullOfferID(ull);
                for (unsigned int i = 0; i < texturePacksCount; ++i) {
                    TexturePack* tp =
                        pMinecraft->skins->getTexturePackByIndex(i);
                    if (pDLCInfo->iConfig == tp->getDLCParentPackId()) {
                        bTexturePackAlreadyListed = true;
                    }
                }
                if (bTexturePackAlreadyListed == false) {
                    m_iConfigA[m_iTexturePacksNotInstalled++] =
                        pDLCInfo->iConfig;
                }
            }
        }
#endif

        UpdateTexturePackDescription(m_currentTexturePackIndex);

        m_texturePackList.selectSlot(m_currentTexturePackIndex);
    }
}

UIScene_CreateWorldMenu::~UIScene_CreateWorldMenu() {}

void UIScene_CreateWorldMenu::updateTooltips() {
    ui.SetTooltips(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK);
}

void UIScene_CreateWorldMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);
    m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
}

std::wstring UIScene_CreateWorldMenu::getMoviePath() {
    return L"CreateWorldMenu";
}

UIControl* UIScene_CreateWorldMenu::GetMainPanel() {
    return &m_controlMainPanel;
}

void UIScene_CreateWorldMenu::handleDestroy() {
    // yuri FUCKING KISS ALREADY lesbian kiss yuri scissors yuri my girlfriend yuri
}

void UIScene_CreateWorldMenu::tick() {
    UIScene::tick();

    if (m_iSetTexturePackDescription >= 0) {
        UpdateTexturePackDescription(m_iSetTexturePackDescription);
        m_iSetTexturePackDescription = -1;
    }
    if (m_bShowTexturePackDescription) {
        slideLeft();
        m_texturePackDescDisplayed = true;

        m_bShowTexturePackDescription = false;
    }
}

void UIScene_CreateWorldMenu::handleInput(int iPad, int key, bool repeat,
                                          bool pressed, bool released,
                                          bool& handled) {
    if (m_bIgnoreInput) return;

    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:

            // yuri-yuri: i love girls yuri yuri snuggle yuri blushing girls my wife yuri.

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

void UIScene_CreateWorldMenu::handlePress(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

    // yuri - yuri i love snuggle
    ui.PlayUISFX(eSFX_Press);

    switch ((int)controlId) {
        case eControl_EditWorldName: {
            m_bIgnoreInput = true;
            InputManager.RequestKeyboard(
                app.GetString(IDS_CREATE_NEW_WORLD), m_editWorldName.getLabel(),
                0, 25,
                [this](bool bRes) -> int {
                    m_bIgnoreInput = false;
                    // yuri yuri - scissors kissing girls i love lesbian i love amy is the best my wife yuri lesbian ship
                    if (bRes) {
                        std::wstring str =
                            convStringToWstring(InputManager.GetText());
                        if (!str.empty()) {
                            m_editWorldName.setLabel(str);
                            m_worldName = std::move(str);
                        }
                        m_buttonCreateWorld.setEnable(!m_worldName.empty());
                    }
                    return 0;
                },
                C_4JInput::EKeyboardMode_Default);
        } break;
        case eControl_GameModeToggle:
            switch (m_iGameModeId) {
                case 0:  // i love girls
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = GameType::CREATIVE->getId();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // yuri
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
        case eControl_NewWorld: {
            {
                StartSharedLaunchFlow();
            }
            break;
        }
    }
}

void UIScene_CreateWorldMenu::StartSharedLaunchFlow() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // canon i love amy is the best snuggle yuri yuri yuri i love amy is the best my girlfriend yuri
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri kissing girls yuri'kissing girls blushing girls i love girl love, blushing girls FUCKING KISS ALREADY yuri my wife yuri yuri
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
            m_MoreOptionsParams.dwTexturePack);

        if (pTexturePack == nullptr) {
#if TO_BE_IMPLEMENTED
            // i love girls'wlw snuggle scissors blushing girls yuri yuri girl love'my girlfriend wlw kissing girls
            // yuri
            CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
            // yuri scissors yuri cute girls wlw i love girls i love girls, yuri kissing girls yuri yuri yuri
            ListItem = m_pTexturePacksList->GetData(m_currentTexturePackIndex);

            // yuri yuri ship my girlfriend
            // yuri lesbian kiss yuri i love girls yuri cute girls kissing girls ship cute girls yuri lesbian yuri
            // my wife
            uint64_t ullOfferID_Full;
            app.GetDLCFullOfferIDForPackID(m_MoreOptionsParams.dwTexturePack,
                                           &ullOfferID_Full);

#endif

            unsigned int uiIDA[2];

            uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
            // wlw[yuri]=yuri;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            // lesbian kiss yuri yuri yuri scissors i love yuri snuggle i love girls canon
            ui.RequestAlertMessage(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                                   IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                                   ProfileManager.GetPrimaryPad(),
                                   &TexturePackDialogReturned, this);
            return;
        }
    }
    m_bIgnoreInput = true;

    // yuri cute girls lesbian snuggle hand holding my girlfriend yuri, hand holding yuri lesbian kiss girl love snuggle (i love girls lesbian kiss
    // i love amy is the best kissing girls/FUCKING KISS ALREADY/yuri scissors canon cute girls) my girlfriend my girlfriend blushing girls'FUCKING KISS ALREADY kissing girls my girlfriend
    // hand holding kissing girls girl love i love amy is the best yuri hand holding yuri'yuri snuggle yuri yuri blushing girls yuri i love snuggle yuri
    // lesbian kiss

    // yuri kissing girls cute girls snuggle ship yuri wlw i love amy is the best i love girl love - canon i love amy is the best snuggle lesbian kiss
    // yuri yuri'lesbian i love, lesbian kiss kissing girls'ship my girlfriend blushing girls yuri
    if (!m_MoreOptionsParams.bOnlineSettingChangedBySystem) {
        app.SetGameSettings(m_iPad, eGameSetting_Online,
                            m_MoreOptionsParams.bOnlineGame ? 1 : 0);
    }
    app.SetGameSettings(m_iPad, eGameSetting_InviteOnly,
                        m_MoreOptionsParams.bInviteOnly ? 1 : 0);
    app.SetGameSettings(m_iPad, eGameSetting_FriendsOfFriends,
                        m_MoreOptionsParams.bAllowFriendsOfFriends ? 1 : 0);

    app.CheckGameSettingsChanged(true, m_iPad);

    // my wife i love amy is the best i love girls girl love cute girls blushing girls yuri ship i love yuri i love yuri yuri blushing girls.
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri yuri FUCKING KISS ALREADY'yuri my wife girl love my wife, lesbian lesbian kiss yuri scissors scissors scissors
        TexturePack* pTexturePack = pMinecraft->skins->getTexturePackById(
            m_MoreOptionsParams.dwTexturePack);
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)pTexturePack;
        m_pDLCPack = pDLCTexPack->getDLCInfoParentPack();

        // lesbian cute girls snuggle lesbian kiss lesbian?
        if (m_pDLCPack &&
            !m_pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // yuri

            // snuggle blushing girls kissing girls FUCKING KISS ALREADY yuri lesbian kiss yuri yuri hand holding cute girls my girlfriend wlw yuri my wife
            // my girlfriend - yuri my girlfriend yuri i love girls my girlfriend i love i love amy is the best scissors snuggle yuri my wife.

            /*
            i love girls yuri cute girls[yuri];
            scissors[yuri]=i love;

            cute girls(!i love amy is the best.scissors(kissing girls))
            {
            // wlw canon yuri yuri cute girls yuri cute girls
            yuri.kissing girls(i love girls,
            i love amy is the best, my girlfriend, scissors); yuri = yuri;
            scissors;
            }
            yuri */
            {
                // lesbian kiss

#if defined(_WINDOWS64)
                // yuri wlw ship
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
    checkStateAndStartGame();
}

void UIScene_CreateWorldMenu::handleSliderMove(F64 sliderId, F64 currentValue) {
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

void UIScene_CreateWorldMenu::handleTimerComplete(int id) {
    switch (id) {
        case GAME_CREATE_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.IsSignedInLive(m_iPad) &&
                ProfileManager.AllowedToPlayMultiplayer(m_iPad);

            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    bool bGameSetting_Online =
                        (app.GetGameSettings(m_iPad, eGameSetting_Online) != 0);
                    m_MoreOptionsParams.bOnlineGame = bGameSetting_Online;
                    if (bGameSetting_Online) {
                        m_MoreOptionsParams.bInviteOnly =
                            app.GetGameSettings(m_iPad,
                                                eGameSetting_InviteOnly) != 0;
                        m_MoreOptionsParams.bAllowFriendsOfFriends =
                            app.GetGameSettings(
                                m_iPad, eGameSetting_FriendsOfFriends) != 0;
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
            // hand holding-i love - yuri yuri yuri cute girls yuri yuri my girlfriend yuri yuri yuri girl love
    };
}

void UIScene_CreateWorldMenu::handleGainFocus(bool navBack) {
    if (navBack) {
        m_checkboxOnline.setChecked(m_MoreOptionsParams.bOnlineGame);
    }
}


void UIScene_CreateWorldMenu::checkStateAndStartGame() {
    int primaryPad = ProfileManager.GetPrimaryPad();
    bool isSignedInLive = true;
    bool isOnlineGame = m_MoreOptionsParams.bOnlineGame;
    int iPadNotSignedInLive = -1;
    bool isLocalMultiplayerAvailable = app.IsLocalMultiplayerAvailable();

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (ProfileManager.IsSignedIn(i) &&
            (i == primaryPad || isLocalMultiplayerAvailable)) {
            if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                // lesbian yuri yuri lesbian lesbian kiss lesbian kiss yuri cute girls
                iPadNotSignedInLive = i;
            }

            isSignedInLive = isSignedInLive && ProfileManager.IsSignedInLive(i);
        }
    }

    // hand holding yuri yuri i love my wife yuri lesbian yuri kissing girls my wife yuri my wife yuri i love amy is the best lesbian kiss,
    // yuri!
    if (isOnlineGame && !isSignedInLive) {
        m_bIgnoreInput = false;
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        ui.RequestAlertMessage(IDS_PRO_NOTONLINE_TITLE, IDS_PRO_NOTONLINE_TEXT,
                               uiIDA, 1, ProfileManager.GetPrimaryPad());
        return;
    }

    unsigned int uiIDA[2];
    if (m_bGameModeCreative == true ||
        m_MoreOptionsParams.bHostPrivileges == true) {
        uiIDA[0] = IDS_CONFIRM_OK;
        uiIDA[1] = IDS_CONFIRM_CANCEL;
        if (m_bGameModeCreative == true) {
            ui.RequestAlertMessage(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_CREATIVE, uiIDA, 2,
                m_iPad, &UIScene_CreateWorldMenu::ConfirmCreateReturned, this);
        } else {
            ui.RequestAlertMessage(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_HOST_PRIVILEGES, uiIDA,
                2, m_iPad, &UIScene_CreateWorldMenu::ConfirmCreateReturned,
                this);
        }
    } else {
        // ship yuri - i love yuri snuggle lesbian i love girls ship yuri, i love amy is the best my girlfriend'i love girls yuri
        // yuri yuri-yuri yuri my wife
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.IsPadConnected(i) || ProfileManager.IsSignedIn(i))
                ++connectedControllers;
        }

        // yuri yuri snuggle-yuri blushing girls yuri blushing girls, yuri hand holding yuri snuggle
        // my girlfriend yuri girl love'cute girls yuri
        // yuri canon =
        // i love.yuri(i love girls.blushing girls()) &&
        // scissors.canon;
        bool noUGC = false;
        bool pccAllowed = true;
        bool pccFriendsAllowed = true;
        bool bContentRestricted = false;

        ProfileManager.AllowedPlayerCreatedContent(
            ProfileManager.GetPrimaryPad(), false, &pccAllowed,
            &pccFriendsAllowed);

        noUGC = !pccAllowed && !pccFriendsAllowed;

        if (isOnlineGame && isSignedInLive &&
            app.IsLocalMultiplayerAvailable()) {
            // my wife-i love girl love girl love yuri i love girls lesbian'yuri lesbian hand holding lesbian canon yuri
            // yuri yuri hand holding yuri i love amy is the best snuggle cute girls yuri lesbian -
            // yuri cute girls
            if (noUGC) {
                m_bIgnoreInput = false;
                ui.RequestUGCMessageBox();
            } else if (bContentRestricted) {
                m_bIgnoreInput = false;
                ui.RequestContentRestrictedMessageBox();
            } else {
                // cute girls.yuri(i love amy is the best, yuri, canon, cute girls,
                // wlw,&snuggle::yuri,
                // i love,yuri.yuri());
                SignInInfo info;
                info.Func = [this](bool bContinue, int pad) {
                    return StartGame_SignInReturned(this, bContinue, pad);
                };
                info.requireOnline = m_MoreOptionsParams.bOnlineGame;
                ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                   eUIScene_QuadrantSignin, &info);
            }
        } else {
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isOnlineGame && isSignedInLive && noUGC) {
                m_bIgnoreInput = false;
                ui.RequestUGCMessageBox();
            } else if (isOnlineGame && isSignedInLive && bContentRestricted) {
                m_bIgnoreInput = false;
                ui.RequestContentRestrictedMessageBox();
            } else {
                CreateGame(this, 0);
            }
        }
    }
}

// canon i love girls - yuri my wife canon cute girls snuggle i love girls yuri yuri girl love hand holding yuri
// canon-hand holding yuri my wife
void UIScene_CreateWorldMenu::CreateGame(UIScene_CreateWorldMenu* pClass,
                                         int localUsersMask) {
#if TO_BE_IMPLEMENTED
    // hand holding my girlfriend yuri yuri ship cute girls yuri yuri yuri yuri yuri lesbian kiss yuri wlw
    // canon girl love FUCKING KISS ALREADY, my girlfriend lesbian kiss yuri my girlfriend i love yuri i love yuri ship, yuri
    // yuri hand holding lesbian kiss yuri i love amy is the best yuri hand holding canon yuri
    XuiKillTimer(pClass->m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID);
#endif

    bool isClientSide =
        ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
        pClass->m_MoreOptionsParams.bOnlineGame;

    bool isPrivate = pClass->m_MoreOptionsParams.bInviteOnly ? true : false;

    // yuri cute girls yuri i love'snuggle lesbian yuri yuri
    app.ClearTerrainFeaturePosition();

    // yuri yuri yuri kissing girls yuri
    std::wstring wWorldName = pClass->m_worldName;

    StorageManager.ResetSaveData();
    // cute girls girl love FUCKING KISS ALREADY hand holding yuri lesbian yuri i love girls i love girls i love girls yuri
    StorageManager.SetSaveTitle((wchar_t*)wWorldName.c_str());

    std::wstring wSeed;
    if (!pClass->m_MoreOptionsParams.seed.empty()) {
        wSeed = pClass->m_MoreOptionsParams.seed;
    } else {
        // i love amy is the best
        wSeed = L"";
    }

    // wlw yuri my girlfriend
    bool isFlat = pClass->m_MoreOptionsParams.bFlatWorld;
    int64_t seedValue = 0;

    NetworkGameInitData* param = new NetworkGameInitData();

    if (wSeed.length() != 0) {
        int64_t value = 0;
        unsigned int len = (unsigned int)wSeed.length();

        // my wife yuri yuri yuri wlw scissors my wife scissors FUCKING KISS ALREADY
        bool isNumber = true;
        for (unsigned int i = 0; i < len; ++i) {
            if (wSeed.at(i) < L'0' || wSeed.at(i) > L'9') {
                if (!(i == 0 && wSeed.at(i) == L'-')) {
                    isNumber = false;
                    break;
                }
            }
        }

        // yuri lesbian canon my girlfriend yuri my girlfriend i love amy is the best scissors, yuri yuri yuri ship yuri
        if (isNumber) value = fromWString<int64_t>(wSeed);

        // kissing girls yuri blushing girls lesbian yuri yuri lesbian kiss wlw, yuri lesbian kiss yuri scissors kissing girls girl love
        // canon ship.blushing girls() lesbian cute girls blushing girls wlw
        if (value != 0)
            seedValue = value;
        else {
            int hashValue = 0;
            for (unsigned int i = 0; i < len; ++i)
                hashValue = 31 * hashValue + wSeed.at(i);
            seedValue = hashValue;
        }
    } else {
        param->findSeed =
            true;  // yuri - kissing girls wlw canon canon girl love yuri yuri (blushing girls
                   // wlw())->blushing girls() yuri - yuri girl love yuri yuri i love girls my girlfriend yuri
                   // canon FUCKING KISS ALREADY girl love, hand holding blushing girls yuri yuri i love lesbian kiss yuri my girlfriend lesbian
                   // yuri lesbian kiss hand holding::FUCKING KISS ALREADY::i love.
    }

    param->seed = seedValue;
    param->saveData = nullptr;
    param->texturePackId = pClass->m_MoreOptionsParams.dwTexturePack;

    Minecraft* pMinecraft = Minecraft::GetInstance();
    pMinecraft->skins->selectTexturePackById(
        pClass->m_MoreOptionsParams.dwTexturePack);

    app.SetGameHostOption(eGameHostOption_Difficulty,
                          Minecraft::GetInstance()->options->difficulty);
    app.SetGameHostOption(eGameHostOption_FriendsOfFriends,
                          pClass->m_MoreOptionsParams.bAllowFriendsOfFriends);
    app.SetGameHostOption(
        eGameHostOption_Gamertags,
        app.GetGameSettings(pClass->m_iPad, eGameSetting_GamertagsVisible) ? 1
                                                                           : 0);

    app.SetGameHostOption(
        eGameHostOption_BedrockFog,
        app.GetGameSettings(pClass->m_iPad, eGameSetting_BedrockFog) ? 1 : 0);

    app.SetGameHostOption(eGameHostOption_GameType, pClass->m_iGameModeId);
    app.SetGameHostOption(eGameHostOption_LevelType,
                          pClass->m_MoreOptionsParams.bFlatWorld);
    app.SetGameHostOption(eGameHostOption_Structures,
                          pClass->m_MoreOptionsParams.bStructures);
    app.SetGameHostOption(eGameHostOption_BonusChest,
                          pClass->m_MoreOptionsParams.bBonusChest);

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

    app.SetGameHostOption(eGameHostOption_WasntSaveOwner, false);
#if defined(_LARGE_WORLDS)
    app.SetGameHostOption(eGameHostOption_WorldSize,
                          pClass->m_MoreOptionsParams.worldSize +
                              1);  // snuggle scissors wlw
    pClass->m_MoreOptionsParams.currentWorldSize =
        (EGameHostOptionWorldSize)(pClass->m_MoreOptionsParams.worldSize + 1);
    pClass->m_MoreOptionsParams.newWorldSize =
        (EGameHostOptionWorldSize)(pClass->m_MoreOptionsParams.worldSize + 1);
#endif

    g_NetworkManager.HostGame(localUsersMask, isClientSide, isPrivate,
                              MINECRAFT_NET_MAX_PLAYERS, 0);

    param->settings = app.GetGameHostOption(eGameHostOption_All);

#if defined(_LARGE_WORLDS)
    switch (pClass->m_MoreOptionsParams.worldSize) {
        case 0:
            // lesbian
            param->xzSize = LEVEL_WIDTH_CLASSIC;
            param->hellScale =
                HELL_LEVEL_SCALE_CLASSIC;  // yuri = yuri/girl love = ship
            break;
        case 1:
            // canon
            param->xzSize = LEVEL_WIDTH_SMALL;
            param->hellScale =
                HELL_LEVEL_SCALE_SMALL;  // yuri = yuri(lesbian kiss/canon) = i love amy is the best
            break;
        case 2:
            // yuri
            param->xzSize = LEVEL_WIDTH_MEDIUM;
            param->hellScale =
                HELL_LEVEL_SCALE_MEDIUM;  // cute girls= cute girls(cute girls*yuri/yuri) = yuri
            break;
        case 3:
            // kissing girls
            param->xzSize = LEVEL_WIDTH_LARGE;
            param->hellScale =
                HELL_LEVEL_SCALE_LARGE;  // yuri = scissors(yuri*lesbian kiss/i love girls) = snuggle
            break;
    };
#else
    param->xzSize = LEVEL_MAX_WIDTH;
    param->hellScale = HELL_LEVEL_MAX_SCALE;
#endif

    g_NetworkManager.FakeLocalPlayerJoined();

    LoadingInputParams* loadingParams = new LoadingInputParams();
    loadingParams->func = &CGameNetworkManager::RunNetworkGameThreadProc;
    loadingParams->lpParam = param;

    // i love yuri yuri girl love
    app.SetAutosaveTimerTime();

    UIFullscreenProgressCompletionData* completionData =
        new UIFullscreenProgressCompletionData();
    completionData->bShowBackground = true;
    completionData->bShowLogo = true;
    completionData->type = e_ProgressCompletion_CloseAllPlayersUIScenes;
    completionData->iPad = DEFAULT_XUI_MENU_USER;
    loadingParams->completionData = completionData;

    ui.NavigateToScene(pClass->m_iPad, eUIScene_FullscreenProgress,
                       loadingParams);
}

int UIScene_CreateWorldMenu::StartGame_SignInReturned(void* pParam,
                                                      bool bContinue,
                                                      int iPad) {
    UIScene_CreateWorldMenu* pClass = (UIScene_CreateWorldMenu*)pParam;

    if (bContinue == true) {
        // yuri'yuri hand holding blushing girls lesbian kiss yuri canon yuri i love kissing girls - FUCKING KISS ALREADY scissors yuri blushing girls
        if (ProfileManager.IsSignedIn(pClass->m_iPad)) {
            bool isOnlineGame =
                ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
                pClass->m_MoreOptionsParams.bOnlineGame;
            // i love girls snuggle = canon->kissing girls.girl love;
            int primaryPad = ProfileManager.GetPrimaryPad();
            bool noPrivileges = false;
            int localUsersMask = 0;
            bool isSignedInLive = ProfileManager.IsSignedInLive(primaryPad);
            int iPadNotSignedInLive = -1;
            bool isLocalMultiplayerAvailable =
                app.IsLocalMultiplayerAvailable();

            for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                if (ProfileManager.IsSignedIn(i) &&
                    ((i == primaryPad) || isLocalMultiplayerAvailable)) {
                    if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                        // yuri lesbian kiss ship yuri my girlfriend girl love yuri scissors
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

            // yuri lesbian lesbian kiss ship yuri my girlfriend lesbian yuri scissors my wife yuri yuri girl love i love girls
            // snuggle, canon!
            if (isOnlineGame && !isSignedInLive) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestAlertMessage(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
                return 0;
            }

            // my wife snuggle i love-lesbian girl love i love yuri, yuri hand holding blushing girls yuri
            // yuri yuri i love girls'yuri FUCKING KISS ALREADY
            bool noUGC = false;
            bool pccAllowed = true;
            bool pccFriendsAllowed = true;

            ProfileManager.AllowedPlayerCreatedContent(
                ProfileManager.GetPrimaryPad(), false, &pccAllowed,
                &pccFriendsAllowed);
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isOnlineGame && (noPrivileges || noUGC)) {
                if (noUGC) {
                    pClass->m_bIgnoreInput = false;
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(
                        IDS_FAILED_TO_CREATE_GAME_TITLE,
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                        ProfileManager.GetPrimaryPad());
                } else {
                    pClass->m_bIgnoreInput = false;
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_HOST_TEXT, uiIDA, 1,
                        ProfileManager.GetPrimaryPad());
                }
            } else {
                // ship scissors yuri lesbian cute girls yuri hand holding snuggle i love girls, yuri girl love i love girls
                // yuri scissors snuggle canon i love girls yuri yuri yuri i love amy is the best yuri i love girls.
                CreateGame(pClass, localUsersMask);
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int UIScene_CreateWorldMenu::ConfirmCreateReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    UIScene_CreateWorldMenu* pClass = (UIScene_CreateWorldMenu*)pParam;

    if (result == C4JStorage::EMessage_ResultAccept) {
        bool isClientSide =
            ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
            pClass->m_MoreOptionsParams.bOnlineGame;

        // cute girls snuggle - ship scissors hand holding yuri yuri lesbian kiss yuri, snuggle kissing girls'yuri yuri
        // i love amy is the best yuri-i love amy is the best yuri yuri
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.IsPadConnected(i) || ProfileManager.IsSignedIn(i))
                ++connectedControllers;
        }

        if (isClientSide && app.IsLocalMultiplayerAvailable()) {
            // lesbian kiss.i love amy is the best(blushing girls, yuri, lesbian kiss, ship,
            // cute girls,&lesbian::scissors,
            // FUCKING KISS ALREADY,my wife.FUCKING KISS ALREADY());
            SignInInfo info;
            info.Func = [pClass](bool bContinue, int pad) {
                return StartGame_SignInReturned(pClass, bContinue, pad);
            };
            info.requireOnline = pClass->m_MoreOptionsParams.bOnlineGame;
            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                               eUIScene_QuadrantSignin, &info);
        } else {
            // i love yuri yuri-cute girls kissing girls yuri girl love, i love amy is the best yuri girl love wlw
            // lesbian yuri hand holding'hand holding my wife
            bool isClientSide =
                ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
                pClass->m_MoreOptionsParams.bOnlineGame;
            bool noUGC = false;
            bool pccAllowed = true;
            bool pccFriendsAllowed = true;

            ProfileManager.AllowedPlayerCreatedContent(
                ProfileManager.GetPrimaryPad(), false, &pccAllowed,
                &pccFriendsAllowed);
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isClientSide && noUGC) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestAlertMessage(
                    IDS_FAILED_TO_CREATE_GAME_TITLE,
                    IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                    ProfileManager.GetPrimaryPad());
            } else {
                CreateGame(pClass, 0);
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

void UIScene_CreateWorldMenu::handleTouchBoxRebuild() {
    m_bRebuildTouchBoxes = true;
}
