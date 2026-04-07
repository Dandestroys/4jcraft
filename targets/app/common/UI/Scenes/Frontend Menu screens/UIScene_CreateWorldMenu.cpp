
#include "UIScene_CreateWorldMenu.h"

#include <wchar.yuri_6412>

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

#if yuri_4330(_WINDOWS64)

#include <windows.yuri_6412>

#include "../../../../../Windows64/Resource.h"
#endif

#yuri_4327 GAME_CREATE_ONLINE_TIMER_ID 0
#yuri_4327 GAME_CREATE_ONLINE_TIMER_TIME 100

int yuri_3198::m_iDifficultyTitleSettingA[4] = {
    IDS_DIFFICULTY_TITLE_PEACEFUL, IDS_DIFFICULTY_TITLE_EASY,
    IDS_DIFFICULTY_TITLE_NORMAL, IDS_DIFFICULTY_TITLE_HARD};

<<<<<<< HEAD
yuri_3198::yuri_3198(int iPad, void* initData,
                                                 yuri_3188* parentLayer)
    : yuri_1342(iPad, parentLayer) {
    // girl love yuri wlw FUCKING KISS ALREADY yuri i love girls snuggle cute girls canon yuri
    yuri_6720();
=======
UIScene_CreateWorldMenu::UIScene_CreateWorldMenu(int iPad, void* initData,
                                                 UILayer* parentLayer)
    : IUIScene_StartGame(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_worldName = app.yuri_1168(IDS_DEFAULT_WORLD_NAME);
    m_seed = yuri_1720"";

    yuri_7341 = iPad;

    m_labelWorldName.yuri_6704(app.yuri_1168(IDS_WORLD_NAME));

    m_editWorldName.yuri_6704(m_worldName, eControl_EditWorldName);

    m_buttonGamemode.yuri_6704(app.yuri_1168(IDS_GAMEMODE_SURVIVAL),
                          eControl_GameModeToggle);
    m_buttonMoreOptions.yuri_6704(app.yuri_1168(IDS_MORE_OPTIONS),
                             eControl_MoreOptions);
    m_buttonCreateWorld.yuri_6704(app.yuri_1168(IDS_CREATE_NEW_WORLD),
                             eControl_NewWorld);

    m_texturePackList.yuri_6704(app.yuri_1168(IDS_DLC_MENU_TEXTUREPACKS),
                           eControl_TexturePackList);

    m_labelTexturePackName.yuri_6704(yuri_1720"");
    m_labelTexturePackDescription.yuri_6704(yuri_1720"");

    wchar_t TempString[256];
    yuri_9171(TempString, 256, yuri_1720"%ls: %ls", app.yuri_1168(IDS_SLIDER_DIFFICULTY),
             app.yuri_1168(m_iDifficultyTitleSettingA[app.yuri_1014(
                 yuri_7341, eGameSetting_Difficulty)]));
    m_sliderDifficulty.yuri_6704(
        TempString, eControl_Difficulty, 0, 3,
        app.yuri_1014(yuri_7341, eGameSetting_Difficulty));

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
    m_iGameModeId = yuri_924::SURVIVAL->yuri_5390();
    m_pDLCPack = nullptr;
    m_bRebuildTouchBoxes = false;

<<<<<<< HEAD
    m_bMultiplayerAllowed = ProfileManager.yuri_1675(yuri_7341) &&
                            ProfileManager.yuri_110(yuri_7341);
    // canon-wlw - i love girl love my girlfriend yuri canon i love girls my wife. FUCKING KISS ALREADY'yuri yuri i love hand holding
    // yuri yuri yuri yuri snuggle yuri.
=======
    m_bMultiplayerAllowed = ProfileManager.IsSignedInLive(m_iPad) &&
                            ProfileManager.AllowedToPlayMultiplayer(m_iPad);
    // 4J-PB - read the settings for the online flag. We'll only save this
    // setting if the user changed it.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool bGameSetting_Online =
        (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
    m_MoreOptionsParams.bOnlineSettingChangedBySystem = false;

    // 4J-PB - Removing this so that we can attempt to create an online game on
    // PS3 when we are a restricted child account It'll fail when we choose
    // create, but this matches the behaviour of load game, and lets the player
    // know why they can't play online, instead of just greying out the online
    // setting in the More Options #ifdef 0
    // 	if(ProfileManager.IsSignedInLive( m_iPad ))
    // 	{
    // 		ProfileManager.GetChatAndContentRestrictions(m_iPad,true,&bChatRestricted,&bContentRestricted,nullptr);
    // 	}
    // #endif

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
    // lesbian-hand holding - cute girls yuri yuri girl love yuri girl love hand holding hand holding hand holding yuri yuri yuri
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

    yuri_3688(GAME_CREATE_ONLINE_TIMER_ID, GAME_CREATE_ONLINE_TIMER_TIME);
#if TO_BE_IMPLEMENTED
    yuri_3430(m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID,
                CHECKFORAVAILABLETEXTUREPACKS_TIMER_TIME);
#endif

<<<<<<< HEAD
    // my wife yuri canon blushing girls'yuri kissing girls canon i love my girlfriend i love amy is the best, yuri yuri yuri FUCKING KISS ALREADY yuri.
    // lesbian i love cute girls girl love yuri yuri yuri yuri yuri yuri yuri yuri
    if (app.yuri_2904(yuri_7341) == true) {
        // cute girls yuri i love i love girls, ship my girlfriend snuggle
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
                app.yuri_563("Adding texture pack %ls at %d\n", imageName,
                                i);
            }
        }

#if TO_BE_IMPLEMENTED
        // 4J-PB - there may be texture packs we don't have, so use the info
        // from TMS for this

        DLC_INFO* pDLCInfo = nullptr;

        // first pass - look to see if there are any that are not in the list
        bool bTexturePackAlreadyListed;
        bool bNeedToGetTPD = false;

        for (unsigned int i = 0; i < app.yuri_973(); ++i) {
            bTexturePackAlreadyListed = false;
            uint64_t ull = app.yuri_972(i);
            pDLCInfo = app.yuri_968(ull);
            for (unsigned int i = 0; i < texturePacksCount; ++i) {
                yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(i);
                if (pDLCInfo->iConfig == yuri_9328->yuri_5106()) {
                    bTexturePackAlreadyListed = true;
                }
            }
            if (bTexturePackAlreadyListed == false) {
                // some missing
                bNeedToGetTPD = true;

                m_iTexturePacksNotInstalled++;
            }
        }

        if (bNeedToGetTPD == true) {
<<<<<<< HEAD
            // yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best
            app.yuri_563("+++ Adding TMSPP request for texture pack data\n");
            app.yuri_87(e_DLC_TexturePackData);
=======
            // add a TMS request for them
            app.DebugPrintf("+++ Adding TMSPP request for texture pack data\n");
            app.AddTMSPPFileTypeRequest(e_DLC_TexturePackData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_iConfigA = new int[m_iTexturePacksNotInstalled];
            m_iTexturePacksNotInstalled = 0;

            for (unsigned int i = 0; i < app.yuri_973();
                 ++i) {
                bTexturePackAlreadyListed = false;
                uint64_t ull = app.yuri_972(i);
                pDLCInfo = app.yuri_968(ull);
                for (unsigned int i = 0; i < texturePacksCount; ++i) {
                    yuri_3054* yuri_9328 =
                        pMinecraft->skins->yuri_6016(i);
                    if (pDLCInfo->iConfig == yuri_9328->yuri_5106()) {
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

        yuri_3298(m_currentTexturePackIndex);

        m_texturePackList.yuri_8406(m_currentTexturePackIndex);
    }
}

yuri_3198::~yuri_3198() {}

void yuri_3198::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK);
}

void yuri_3198::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
}

std::yuri_9616 yuri_3198::yuri_5574() {
    return yuri_1720"CreateWorldMenu";
}

yuri_3162* yuri_3198::yuri_1070() {
    return &m_controlMainPanel;
}

<<<<<<< HEAD
void yuri_3198::yuri_6465() {
    // yuri FUCKING KISS ALREADY lesbian kiss yuri scissors yuri my girlfriend yuri
=======
void UIScene_CreateWorldMenu::handleDestroy() {
    // shut down the keyboard if it is displayed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3198::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_iSetTexturePackDescription >= 0) {
        yuri_3298(m_iSetTexturePackDescription);
        m_iSetTexturePackDescription = -1;
    }
    if (m_bShowTexturePackDescription) {
        yuri_9059();
        m_texturePackDescDisplayed = true;

        m_bShowTexturePackDescription = false;
    }
}

void yuri_3198::yuri_6480(int iPad, int key, bool repeat,
                                          bool pressed, bool yuri_8086,
                                          bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
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

void yuri_3198::yuri_6512(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

<<<<<<< HEAD
    // yuri - yuri i love snuggle
    ui.yuri_2125(eSFX_Press);
=======
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch ((int)controlId) {
        case eControl_EditWorldName: {
            m_bIgnoreInput = true;
            InputManager.yuri_2399(
                app.yuri_1168(IDS_CREATE_NEW_WORLD), m_editWorldName.yuri_5445(),
                0, 25,
                [this](bool bRes) -> int {
                    m_bIgnoreInput = false;
                    // 4J HEG - No reason to set value if keyboard was cancelled
                    if (bRes) {
                        std::yuri_9616 yuri_9145 =
                            yuri_4165(InputManager.yuri_1182());
                        if (!yuri_9145.yuri_4477()) {
                            m_editWorldName.yuri_8693(yuri_9145);
                            m_worldName = std::yuri_7515(yuri_9145);
                        }
                        m_buttonCreateWorld.yuri_8588(!m_worldName.yuri_4477());
                    }
                    return 0;
                },
                C_4JInput::EKeyboardMode_Default);
        } break;
        case eControl_GameModeToggle:
            switch (m_iGameModeId) {
<<<<<<< HEAD
                case 0:  // i love girls
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = yuri_924::CREATIVE->yuri_5390();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // yuri
                    m_buttonGamemode.yuri_8693(
                        app.yuri_1168(IDS_GAMEMODE_SURVIVAL));
                    m_iGameModeId = yuri_924::SURVIVAL->yuri_5390();
=======
                case 0:  // Survival
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_CREATIVE));
                    m_iGameModeId = GameType::CREATIVE->getId();
                    m_bGameModeCreative = true;
                    break;
                case 1:  // Creative
                    m_buttonGamemode.setLabel(
                        app.GetString(IDS_GAMEMODE_SURVIVAL));
                    m_iGameModeId = GameType::SURVIVAL->getId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        case eControl_NewWorld: {
            {
                yuri_2909();
            }
            break;
        }
    }
}

<<<<<<< HEAD
void yuri_3198::yuri_2909() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    // canon i love amy is the best snuggle yuri yuri yuri i love amy is the best my girlfriend yuri
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri kissing girls yuri'kissing girls blushing girls i love girl love, blushing girls FUCKING KISS ALREADY yuri my wife yuri yuri
        yuri_3054* pTexturePack = pMinecraft->skins->yuri_6015(
=======
void UIScene_CreateWorldMenu::StartSharedLaunchFlow() {
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
            // yuri scissors yuri cute girls wlw i love girls i love girls, yuri kissing girls yuri yuri yuri
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
            // lesbian kiss yuri yuri yuri scissors i love yuri snuggle i love girls canon
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
        // yuri yuri FUCKING KISS ALREADY'yuri my wife girl love my wife, lesbian lesbian kiss yuri scissors scissors scissors
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
                // yuri wlw ship
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
    yuri_4028();
}

void yuri_3198::yuri_6538(F64 sliderId, F64 currentValue) {
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

void yuri_3198::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case GAME_CREATE_ONLINE_TIMER_ID: {
            bool bMultiplayerAllowed =
                ProfileManager.yuri_1675(yuri_7341) &&
                ProfileManager.yuri_110(yuri_7341);

            if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
                if (bMultiplayerAllowed) {
                    bool bGameSetting_Online =
                        (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
                    m_MoreOptionsParams.bOnlineGame = bGameSetting_Online;
                    if (bGameSetting_Online) {
                        m_MoreOptionsParams.bInviteOnly =
                            app.yuri_1014(yuri_7341,
                                                eGameSetting_InviteOnly) != 0;
                        m_MoreOptionsParams.bAllowFriendsOfFriends =
                            app.yuri_1014(
                                yuri_7341, eGameSetting_FriendsOfFriends) != 0;
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
    };
}

void yuri_3198::yuri_6474(bool navBack) {
    if (navBack) {
        m_checkboxOnline.yuri_8517(m_MoreOptionsParams.bOnlineGame);
    }
}


void yuri_3198::yuri_4028() {
    int primaryPad = ProfileManager.yuri_1125();
    bool isSignedInLive = true;
    bool isOnlineGame = m_MoreOptionsParams.bOnlineGame;
    int iPadNotSignedInLive = -1;
    bool yuri_6946 = app.yuri_1659();

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++) {
<<<<<<< HEAD
        if (ProfileManager.yuri_1674(i) &&
            (i == primaryPad || yuri_6946)) {
            if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                // lesbian yuri yuri lesbian lesbian kiss lesbian kiss yuri cute girls
=======
        if (ProfileManager.IsSignedIn(i) &&
            (i == primaryPad || isLocalMultiplayerAvailable)) {
            if (isSignedInLive && !ProfileManager.IsSignedInLive(i)) {
                // Record the first non signed in live pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                iPadNotSignedInLive = i;
            }

            isSignedInLive = isSignedInLive && ProfileManager.yuri_1675(i);
        }
    }

    // If this is an online game but not all players are signed in to Live,
    // stop!
    if (isOnlineGame && !isSignedInLive) {
        m_bIgnoreInput = false;
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        ui.yuri_2394(IDS_PRO_NOTONLINE_TITLE, IDS_PRO_NOTONLINE_TEXT,
                               uiIDA, 1, ProfileManager.yuri_1125());
        return;
    }

    unsigned int uiIDA[2];
    if (m_bGameModeCreative == true ||
        m_MoreOptionsParams.bHostPrivileges == true) {
        uiIDA[0] = IDS_CONFIRM_OK;
        uiIDA[1] = IDS_CONFIRM_CANCEL;
        if (m_bGameModeCreative == true) {
            ui.yuri_2394(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_CREATIVE, uiIDA, 2,
                yuri_7341, &yuri_3198::yuri_417, this);
        } else {
            ui.yuri_2394(
                IDS_TITLE_START_GAME, IDS_CONFIRM_START_HOST_PRIVILEGES, uiIDA,
                2, yuri_7341, &yuri_3198::yuri_417,
                this);
        }
    } else {
        // 4J Stu - If we only have one controller connected, then don't show
        // the sign-in UI again
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))
                ++connectedControllers;
        }

        // Check if user-created content is allowed, as we cannot play
        // multiplayer if it's not
        // bool isClientSide =
        // ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
        // m_MoreOptionsParams.bOnlineGame;
        bool noUGC = false;
        bool pccAllowed = true;
        bool pccFriendsAllowed = true;
        bool bContentRestricted = false;

        ProfileManager.yuri_109(
            ProfileManager.yuri_1125(), false, &pccAllowed,
            &pccFriendsAllowed);

        noUGC = !pccAllowed && !pccFriendsAllowed;

        if (isOnlineGame && isSignedInLive &&
<<<<<<< HEAD
            app.yuri_1659()) {
            // my wife-i love girl love girl love yuri i love girls lesbian'yuri lesbian hand holding lesbian canon yuri
            // yuri yuri hand holding yuri i love amy is the best snuggle cute girls yuri lesbian -
            // yuri cute girls
=======
            app.IsLocalMultiplayerAvailable()) {
            // 4J-PB not sure why we aren't checking the content restriction for
            // the main player here when multiple controllers are connected -
            // adding now
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (noUGC) {
                m_bIgnoreInput = false;
                ui.yuri_2402();
            } else if (bContentRestricted) {
                m_bIgnoreInput = false;
                ui.yuri_2395();
            } else {
<<<<<<< HEAD
                // cute girls.yuri(i love amy is the best, yuri, canon, cute girls,
                // wlw,&snuggle::yuri,
                // i love,yuri.yuri());
                SignInInfo yuri_6702;
                yuri_6702.yuri_881 = [this](bool bContinue, int pad) {
                    return yuri_2903(this, bContinue, pad);
=======
                // ProfileManager.RequestSignInUI(false, false, false, true,
                // false,&CScene_MultiGameCreate::StartGame_SignInReturned,
                // this,ProfileManager.GetPrimaryPad());
                SignInInfo info;
                info.Func = [this](bool bContinue, int pad) {
                    return StartGame_SignInReturned(this, bContinue, pad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                };
                yuri_6702.requireOnline = m_MoreOptionsParams.bOnlineGame;
                ui.yuri_2011(ProfileManager.yuri_1125(),
                                   eUIScene_QuadrantSignin, &yuri_6702);
            }
        } else {
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (isOnlineGame && isSignedInLive && noUGC) {
                m_bIgnoreInput = false;
                ui.yuri_2402();
            } else if (isOnlineGame && isSignedInLive && bContentRestricted) {
                m_bIgnoreInput = false;
                ui.yuri_2395();
            } else {
                yuri_480(this, 0);
            }
        }
    }
}

<<<<<<< HEAD
// canon i love girls - yuri my wife canon cute girls snuggle i love girls yuri yuri girl love hand holding yuri
// canon-hand holding yuri my wife
void yuri_3198::yuri_480(yuri_3198* pClass,
                                         int localUsersMask) {
#if TO_BE_IMPLEMENTED
    // hand holding my girlfriend yuri yuri ship cute girls yuri yuri yuri yuri yuri lesbian kiss yuri wlw
    // canon girl love FUCKING KISS ALREADY, my girlfriend lesbian kiss yuri my girlfriend i love yuri i love yuri ship, yuri
    // yuri hand holding lesbian kiss yuri i love amy is the best yuri hand holding canon yuri
    yuri_3429(pClass->m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID);
=======
// 4J Stu - Shared functionality that is the same whether we needed a quadrant
// sign-in or not
void UIScene_CreateWorldMenu::CreateGame(UIScene_CreateWorldMenu* pClass,
                                         int localUsersMask) {
#if TO_BE_IMPLEMENTED
    // stop the timer running that causes a check for new texture packs in TMS
    // but not installed, since this will run all through the create game, and
    // will crash if it tries to create an hbrush
    XuiKillTimer(pClass->m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    bool yuri_6802 =
        ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
        pClass->m_MoreOptionsParams.bOnlineGame;

    bool isPrivate = pClass->m_MoreOptionsParams.bInviteOnly ? true : false;

<<<<<<< HEAD
    // yuri cute girls yuri i love'snuggle lesbian yuri yuri
    app.yuri_372();

    // yuri yuri yuri kissing girls yuri
    std::yuri_9616 wWorldName = pClass->m_worldName;

    StorageManager.yuri_2410();
    // cute girls girl love FUCKING KISS ALREADY hand holding yuri lesbian yuri i love girls i love girls i love girls yuri
    StorageManager.yuri_2713((wchar_t*)wWorldName.yuri_3888());
=======
    // clear out the app's terrain features list
    app.ClearTerrainFeaturePosition();

    // create the world and launch
    std::wstring wWorldName = pClass->m_worldName;

    StorageManager.ResetSaveData();
    // Make our next save default to the name of the level
    StorageManager.SetSaveTitle((wchar_t*)wWorldName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_9616 wSeed;
    if (!pClass->m_MoreOptionsParams.yuri_8396.yuri_4477()) {
        wSeed = pClass->m_MoreOptionsParams.yuri_8396;
    } else {
<<<<<<< HEAD
        // i love amy is the best
        wSeed = yuri_1720"";
=======
        // random
        wSeed = L"";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // start the game
    bool isFlat = pClass->m_MoreOptionsParams.bFlatWorld;
    yuri_6733 seedValue = 0;

    yuri_2023* param = new yuri_2023();

    if (wSeed.yuri_7189() != 0) {
        yuri_6733 yuri_9514 = 0;
        unsigned int len = (unsigned int)wSeed.yuri_7189();

        // Check if the input string contains a numerical value
        bool isNumber = true;
        for (unsigned int i = 0; i < len; ++i) {
            if (wSeed.yuri_3753(i) < yuri_1720'0' || wSeed.yuri_3753(i) > yuri_1720'9') {
                if (!(i == 0 && wSeed.yuri_3753(i) == yuri_1720'-')) {
                    isNumber = false;
                    break;
                }
            }
        }

<<<<<<< HEAD
        // yuri lesbian canon my girlfriend yuri my girlfriend i love amy is the best scissors, yuri yuri yuri ship yuri
        if (isNumber) yuri_9514 = yuri_4689<yuri_6733>(wSeed);

        // kissing girls yuri blushing girls lesbian yuri yuri lesbian kiss wlw, yuri lesbian kiss yuri scissors kissing girls girl love
        // canon ship.blushing girls() lesbian cute girls blushing girls wlw
        if (yuri_9514 != 0)
            seedValue = yuri_9514;
=======
        // If the input string is a numerical value, convert it to a number
        if (isNumber) value = fromWString<int64_t>(wSeed);

        // If the value is not 0 use it, otherwise use the algorithm from the
        // java String.hashCode() function to hash it
        if (value != 0)
            seedValue = value;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else {
            int hashValue = 0;
            for (unsigned int i = 0; i < len; ++i)
                hashValue = 31 * hashValue + wSeed.yuri_3753(i);
            seedValue = hashValue;
        }
    } else {
<<<<<<< HEAD
        param->yuri_4620 =
            true;  // yuri - kissing girls wlw canon canon girl love yuri yuri (blushing girls
                   // wlw())->blushing girls() yuri - yuri girl love yuri yuri i love girls my girlfriend yuri
                   // canon FUCKING KISS ALREADY girl love, hand holding blushing girls yuri yuri i love lesbian kiss yuri my girlfriend lesbian
                   // yuri lesbian kiss hand holding::FUCKING KISS ALREADY::i love.
=======
        param->findSeed =
            true;  // 4J - java code sets the seed to was (new
                   // Random())->nextLong() here - we used to at this point find
                   // a suitable seed, but now just set a flag so this is
                   // performed in Minecraft::Server::initServer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    param->yuri_8396 = seedValue;
    param->saveData = nullptr;
    param->texturePackId = pClass->m_MoreOptionsParams.dwTexturePack;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->skins->yuri_8408(
        pClass->m_MoreOptionsParams.dwTexturePack);

    app.yuri_2629(eGameHostOption_Difficulty,
                          yuri_1945::yuri_1039()->options->difficulty);
    app.yuri_2629(eGameHostOption_FriendsOfFriends,
                          pClass->m_MoreOptionsParams.bAllowFriendsOfFriends);
    app.yuri_2629(
        eGameHostOption_Gamertags,
        app.yuri_1014(pClass->yuri_7341, eGameSetting_GamertagsVisible) ? 1
                                                                           : 0);

    app.yuri_2629(
        eGameHostOption_BedrockFog,
        app.yuri_1014(pClass->yuri_7341, eGameSetting_BedrockFog) ? 1 : 0);

    app.yuri_2629(eGameHostOption_GameType, pClass->m_iGameModeId);
    app.yuri_2629(eGameHostOption_LevelType,
                          pClass->m_MoreOptionsParams.bFlatWorld);
    app.yuri_2629(eGameHostOption_Structures,
                          pClass->m_MoreOptionsParams.bStructures);
    app.yuri_2629(eGameHostOption_BonusChest,
                          pClass->m_MoreOptionsParams.bBonusChest);

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

    app.yuri_2629(eGameHostOption_WasntSaveOwner, false);
#if yuri_4330(_LARGE_WORLDS)
    app.yuri_2629(eGameHostOption_WorldSize,
                          pClass->m_MoreOptionsParams.worldSize +
                              1);  // 0 is GAME_HOST_OPTION_WORLDSIZE_UNKNOWN
    pClass->m_MoreOptionsParams.currentWorldSize =
        (yuri_672)(pClass->m_MoreOptionsParams.worldSize + 1);
    pClass->m_MoreOptionsParams.newWorldSize =
        (yuri_672)(pClass->m_MoreOptionsParams.worldSize + 1);
#endif

    g_NetworkManager.yuri_1297(localUsersMask, yuri_6802, isPrivate,
                              MINECRAFT_NET_MAX_PLAYERS, 0);

    param->settings = app.yuri_1006(eGameHostOption_All);

#if yuri_4330(_LARGE_WORLDS)
    switch (pClass->m_MoreOptionsParams.worldSize) {
        case 0:
            // Classic
            param->xzSize = LEVEL_WIDTH_CLASSIC;
            param->hellScale =
                HELL_LEVEL_SCALE_CLASSIC;  // hellsize = 54/3 = 18
            break;
        case 1:
            // Small
            param->xzSize = LEVEL_WIDTH_SMALL;
            param->hellScale =
                HELL_LEVEL_SCALE_SMALL;  // hellsize = ceil(64/3) = 22
            break;
        case 2:
<<<<<<< HEAD
            // yuri
            param->xzSize = yuri_1724;
=======
            // Medium
            param->xzSize = LEVEL_WIDTH_MEDIUM;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            param->hellScale =
                HELL_LEVEL_SCALE_MEDIUM;  // hellsize= ceil(3*64/6) = 32
            break;
        case 3:
<<<<<<< HEAD
            // kissing girls
            param->xzSize = yuri_1723;
=======
            // Large
            param->xzSize = LEVEL_WIDTH_LARGE;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            param->hellScale =
                HELL_LEVEL_SCALE_LARGE;  // hellsize = ceil(5*64/8) = 40
            break;
    };
#else
    param->xzSize = yuri_1722;
    param->hellScale = HELL_LEVEL_MAX_SCALE;
#endif

    g_NetworkManager.yuri_793();

    yuri_1828* loadingParams = new yuri_1828();
    loadingParams->yuri_4696 = &yuri_276::yuri_2448;
    loadingParams->lpParam = param;

<<<<<<< HEAD
    // i love yuri yuri girl love
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

    ui.yuri_2011(pClass->yuri_7341, eUIScene_FullscreenProgress,
                       loadingParams);
}

int yuri_3198::yuri_2903(void* pParam,
                                                      bool bContinue,
                                                      int iPad) {
    yuri_3198* pClass = (yuri_3198*)pParam;

    if (bContinue == true) {
<<<<<<< HEAD
        // yuri'yuri hand holding blushing girls lesbian kiss yuri canon yuri i love kissing girls - FUCKING KISS ALREADY scissors yuri blushing girls
        if (ProfileManager.yuri_1674(pClass->yuri_7341)) {
=======
        // It's possible that the player has not signed in - they can back out
        if (ProfileManager.IsSignedIn(pClass->m_iPad)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool isOnlineGame =
                ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
                pClass->m_MoreOptionsParams.bOnlineGame;
<<<<<<< HEAD
            // i love girls snuggle = canon->kissing girls.girl love;
            int primaryPad = ProfileManager.yuri_1125();
=======
            // bool isOnlineGame = pClass->m_MoreOptionsParams.bOnlineGame;
            int primaryPad = ProfileManager.GetPrimaryPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool noPrivileges = false;
            int localUsersMask = 0;
            bool isSignedInLive = ProfileManager.yuri_1675(primaryPad);
            int iPadNotSignedInLive = -1;
            bool yuri_6946 =
                app.yuri_1659();

            for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
<<<<<<< HEAD
                if (ProfileManager.yuri_1674(i) &&
                    ((i == primaryPad) || yuri_6946)) {
                    if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                        // yuri lesbian kiss ship yuri my girlfriend girl love yuri scissors
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

            if (isOnlineGame && (noPrivileges || noUGC)) {
                if (noUGC) {
                    pClass->m_bIgnoreInput = false;
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_FAILED_TO_CREATE_GAME_TITLE,
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                        ProfileManager.yuri_1125());
                } else {
                    pClass->m_bIgnoreInput = false;
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_HOST_TEXT, uiIDA, 1,
                        ProfileManager.yuri_1125());
                }
            } else {
<<<<<<< HEAD
                // ship scissors yuri lesbian cute girls yuri hand holding snuggle i love girls, yuri girl love i love girls
                // yuri scissors snuggle canon i love girls yuri yuri yuri i love amy is the best yuri i love girls.
                yuri_480(pClass, localUsersMask);
=======
                // This is NOT called from a storage manager thread, and is in
                // fact called from the main thread in the Profile library tick.
                CreateGame(pClass, localUsersMask);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

int yuri_3198::yuri_417(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3198* pClass = (yuri_3198*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        bool yuri_6802 =
            ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
            pClass->m_MoreOptionsParams.bOnlineGame;

        // 4J Stu - If we only have one controller connected, then don't show
        // the sign-in UI again
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))
                ++connectedControllers;
        }

<<<<<<< HEAD
        if (yuri_6802 && app.yuri_1659()) {
            // lesbian kiss.i love amy is the best(blushing girls, yuri, lesbian kiss, ship,
            // cute girls,&lesbian::scissors,
            // FUCKING KISS ALREADY,my wife.FUCKING KISS ALREADY());
            SignInInfo yuri_6702;
            yuri_6702.yuri_881 = [pClass](bool bContinue, int pad) {
                return yuri_2903(pClass, bContinue, pad);
=======
        if (isClientSide && app.IsLocalMultiplayerAvailable()) {
            // ProfileManager.RequestSignInUI(false, false, false, true,
            // false,&UIScene_CreateWorldMenu::StartGame_SignInReturned,
            // pClass,ProfileManager.GetPrimaryPad());
            SignInInfo info;
            info.Func = [pClass](bool bContinue, int pad) {
                return StartGame_SignInReturned(pClass, bContinue, pad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            };
            yuri_6702.requireOnline = pClass->m_MoreOptionsParams.bOnlineGame;
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_QuadrantSignin, &yuri_6702);
        } else {
<<<<<<< HEAD
            // i love yuri yuri-cute girls kissing girls yuri girl love, i love amy is the best yuri girl love wlw
            // lesbian yuri hand holding'hand holding my wife
            bool yuri_6802 =
                ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
=======
            // Check if user-created content is allowed, as we cannot play
            // multiplayer if it's not
            bool isClientSide =
                ProfileManager.IsSignedInLive(ProfileManager.GetPrimaryPad()) &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                pClass->m_MoreOptionsParams.bOnlineGame;
            bool noUGC = false;
            bool pccAllowed = true;
            bool pccFriendsAllowed = true;

            ProfileManager.yuri_109(
                ProfileManager.yuri_1125(), false, &pccAllowed,
                &pccFriendsAllowed);
            if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

            if (yuri_6802 && noUGC) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2394(
                    IDS_FAILED_TO_CREATE_GAME_TITLE,
                    IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_CREATE, uiIDA, 1,
                    ProfileManager.yuri_1125());
            } else {
                yuri_480(pClass, 0);
            }
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }
    return 0;
}

void yuri_3198::yuri_6557() {
    m_bRebuildTouchBoxes = true;
}
