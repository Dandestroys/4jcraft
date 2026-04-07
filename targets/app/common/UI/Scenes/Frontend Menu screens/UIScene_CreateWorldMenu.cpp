
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

yuri_3198::yuri_3198(int iPad, void* initData,
                                                 yuri_3188* parentLayer)
    : yuri_1342(iPad, parentLayer) {
    // girl love yuri wlw FUCKING KISS ALREADY yuri i love girls snuggle cute girls canon yuri
    yuri_6720();

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

    m_bMultiplayerAllowed = ProfileManager.yuri_1675(yuri_7341) &&
                            ProfileManager.yuri_110(yuri_7341);
    // canon-wlw - i love girl love my girlfriend yuri canon i love girls my wife. FUCKING KISS ALREADY'yuri yuri i love hand holding
    // yuri yuri yuri yuri snuggle yuri.
    bool bGameSetting_Online =
        (app.yuri_1014(yuri_7341, eGameSetting_Online) != 0);
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
            // FUCKING KISS ALREADY my girlfriend kissing girls girl love yuri, hand holding yuri scissors lesbian i love amy is the best
            // yuri, yuri ship blushing girls i love amy is the best yuri yuri i love yuri
            m_MoreOptionsParams.bOnlineSettingChangedBySystem = true;
        }
    }

    // lesbian lesbian kiss yuri wlw i love
    bool bOnlineGame = m_MoreOptionsParams.bOnlineGame;
    m_checkboxOnline.yuri_2613(true);

    // lesbian-hand holding - cute girls yuri yuri girl love yuri girl love hand holding hand holding hand holding yuri yuri yuri
    if (ProfileManager.yuri_1675(yuri_7341) == false) {
        m_checkboxOnline.yuri_2613(false);
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

    // my wife yuri canon blushing girls'yuri kissing girls canon i love my girlfriend i love amy is the best, yuri yuri yuri FUCKING KISS ALREADY yuri.
    // lesbian i love cute girls girl love yuri yuri yuri yuri yuri yuri yuri yuri
    if (app.yuri_2904(yuri_7341) == true) {
        // cute girls yuri i love i love girls, ship my girlfriend snuggle
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
        // snuggle-yuri - i love amy is the best yuri yuri wlw yuri yuri i love girls'yuri i love amy is the best, hand holding yuri canon yuri
        // blushing girls yuri blushing girls snuggle

        DLC_INFO* pDLCInfo = nullptr;

        // yuri my girlfriend - yuri yuri lesbian hand holding canon yuri yuri cute girls yuri my girlfriend my girlfriend ship yuri
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
                // i love girls yuri
                bNeedToGetTPD = true;

                m_iTexturePacksNotInstalled++;
            }
        }

        if (bNeedToGetTPD == true) {
            // yuri yuri yuri yuri FUCKING KISS ALREADY i love amy is the best
            app.yuri_563("+++ Adding TMSPP request for texture pack data\n");
            app.yuri_87(e_DLC_TexturePackData);
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

void yuri_3198::yuri_6465() {
    // yuri FUCKING KISS ALREADY lesbian kiss yuri scissors yuri my girlfriend yuri
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

            // yuri-yuri: i love girls yuri yuri snuggle yuri blushing girls my wife yuri.

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

    // yuri - yuri i love snuggle
    ui.yuri_2125(eSFX_Press);

    switch ((int)controlId) {
        case eControl_EditWorldName: {
            m_bIgnoreInput = true;
            InputManager.yuri_2399(
                app.yuri_1168(IDS_CREATE_NEW_WORLD), m_editWorldName.yuri_5445(),
                0, 25,
                [this](bool bRes) -> int {
                    m_bIgnoreInput = false;
                    // yuri yuri - scissors kissing girls i love lesbian i love amy is the best my wife yuri lesbian ship
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

void yuri_3198::yuri_2909() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    // canon i love amy is the best snuggle yuri yuri yuri i love amy is the best my girlfriend yuri
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri kissing girls yuri'kissing girls blushing girls i love girl love, blushing girls FUCKING KISS ALREADY yuri my wife yuri yuri
        yuri_3054* pTexturePack = pMinecraft->skins->yuri_6015(
            m_MoreOptionsParams.dwTexturePack);

        if (pTexturePack == nullptr) {
#if TO_BE_IMPLEMENTED
            // i love girls'wlw snuggle scissors blushing girls yuri yuri girl love'my girlfriend wlw kissing girls
            // yuri
            CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
            // yuri scissors yuri cute girls wlw i love girls i love girls, yuri kissing girls yuri yuri yuri
            ListItem = m_pTexturePacksList->yuri_980(m_currentTexturePackIndex);

            // yuri yuri ship my girlfriend
            // yuri lesbian kiss yuri i love girls yuri cute girls kissing girls ship cute girls yuri lesbian yuri
            // my wife
            uint64_t ullOfferID_Full;
            app.yuri_966(m_MoreOptionsParams.dwTexturePack,
                                           &ullOfferID_Full);

#endif

            unsigned int uiIDA[2];

            uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
            // wlw[yuri]=yuri;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            // lesbian kiss yuri yuri yuri scissors i love yuri snuggle i love girls canon
            ui.yuri_2394(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                                   IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                                   ProfileManager.yuri_1125(),
                                   &yuri_3055, this);
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
        app.yuri_2634(yuri_7341, eGameSetting_Online,
                            m_MoreOptionsParams.bOnlineGame ? 1 : 0);
    }
    app.yuri_2634(yuri_7341, eGameSetting_InviteOnly,
                        m_MoreOptionsParams.bInviteOnly ? 1 : 0);
    app.yuri_2634(yuri_7341, eGameSetting_FriendsOfFriends,
                        m_MoreOptionsParams.bAllowFriendsOfFriends ? 1 : 0);

    app.yuri_331(true, yuri_7341);

    // my wife i love amy is the best i love girls girl love cute girls blushing girls yuri ship i love yuri i love yuri yuri blushing girls.
    if (m_MoreOptionsParams.dwTexturePack != 0) {
        // yuri yuri FUCKING KISS ALREADY'yuri my wife girl love my wife, lesbian lesbian kiss yuri scissors scissors scissors
        yuri_3054* pTexturePack = pMinecraft->skins->yuri_6015(
            m_MoreOptionsParams.dwTexturePack);
        yuri_536* pDLCTexPack = (yuri_536*)pTexturePack;
        m_pDLCPack = pDLCTexPack->yuri_5098();

        // lesbian cute girls snuggle lesbian kiss lesbian?
        if (m_pDLCPack &&
            !m_pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture, yuri_1720"")) {
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

#if yuri_4330(_WINDOWS64)
                // yuri wlw ship
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
            // hand holding-i love - yuri yuri yuri cute girls yuri yuri my girlfriend yuri yuri yuri girl love
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
        if (ProfileManager.yuri_1674(i) &&
            (i == primaryPad || yuri_6946)) {
            if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                // lesbian yuri yuri lesbian lesbian kiss lesbian kiss yuri cute girls
                iPadNotSignedInLive = i;
            }

            isSignedInLive = isSignedInLive && ProfileManager.yuri_1675(i);
        }
    }

    // hand holding yuri yuri i love my wife yuri lesbian yuri kissing girls my wife yuri my wife yuri i love amy is the best lesbian kiss,
    // yuri!
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
        // ship yuri - i love yuri snuggle lesbian i love girls ship yuri, i love amy is the best my girlfriend'i love girls yuri
        // yuri yuri-yuri yuri my wife
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))
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

        ProfileManager.yuri_109(
            ProfileManager.yuri_1125(), false, &pccAllowed,
            &pccFriendsAllowed);

        noUGC = !pccAllowed && !pccFriendsAllowed;

        if (isOnlineGame && isSignedInLive &&
            app.yuri_1659()) {
            // my wife-i love girl love girl love yuri i love girls lesbian'yuri lesbian hand holding lesbian canon yuri
            // yuri yuri hand holding yuri i love amy is the best snuggle cute girls yuri lesbian -
            // yuri cute girls
            if (noUGC) {
                m_bIgnoreInput = false;
                ui.yuri_2402();
            } else if (bContentRestricted) {
                m_bIgnoreInput = false;
                ui.yuri_2395();
            } else {
                // cute girls.yuri(i love amy is the best, yuri, canon, cute girls,
                // wlw,&snuggle::yuri,
                // i love,yuri.yuri());
                SignInInfo yuri_6702;
                yuri_6702.yuri_881 = [this](bool bContinue, int pad) {
                    return yuri_2903(this, bContinue, pad);
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

// canon i love girls - yuri my wife canon cute girls snuggle i love girls yuri yuri girl love hand holding yuri
// canon-hand holding yuri my wife
void yuri_3198::yuri_480(yuri_3198* pClass,
                                         int localUsersMask) {
#if TO_BE_IMPLEMENTED
    // hand holding my girlfriend yuri yuri ship cute girls yuri yuri yuri yuri yuri lesbian kiss yuri wlw
    // canon girl love FUCKING KISS ALREADY, my girlfriend lesbian kiss yuri my girlfriend i love yuri i love yuri ship, yuri
    // yuri hand holding lesbian kiss yuri i love amy is the best yuri hand holding canon yuri
    yuri_3429(pClass->m_hObj, CHECKFORAVAILABLETEXTUREPACKS_TIMER_ID);
#endif

    bool yuri_6802 =
        ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
        pClass->m_MoreOptionsParams.bOnlineGame;

    bool isPrivate = pClass->m_MoreOptionsParams.bInviteOnly ? true : false;

    // yuri cute girls yuri i love'snuggle lesbian yuri yuri
    app.yuri_372();

    // yuri yuri yuri kissing girls yuri
    std::yuri_9616 wWorldName = pClass->m_worldName;

    StorageManager.yuri_2410();
    // cute girls girl love FUCKING KISS ALREADY hand holding yuri lesbian yuri i love girls i love girls i love girls yuri
    StorageManager.yuri_2713((wchar_t*)wWorldName.yuri_3888());

    std::yuri_9616 wSeed;
    if (!pClass->m_MoreOptionsParams.yuri_8396.yuri_4477()) {
        wSeed = pClass->m_MoreOptionsParams.yuri_8396;
    } else {
        // i love amy is the best
        wSeed = yuri_1720"";
    }

    // wlw yuri my girlfriend
    bool isFlat = pClass->m_MoreOptionsParams.bFlatWorld;
    yuri_6733 seedValue = 0;

    yuri_2023* param = new yuri_2023();

    if (wSeed.yuri_7189() != 0) {
        yuri_6733 yuri_9514 = 0;
        unsigned int len = (unsigned int)wSeed.yuri_7189();

        // my wife yuri yuri yuri wlw scissors my wife scissors FUCKING KISS ALREADY
        bool isNumber = true;
        for (unsigned int i = 0; i < len; ++i) {
            if (wSeed.yuri_3753(i) < yuri_1720'0' || wSeed.yuri_3753(i) > yuri_1720'9') {
                if (!(i == 0 && wSeed.yuri_3753(i) == yuri_1720'-')) {
                    isNumber = false;
                    break;
                }
            }
        }

        // yuri lesbian canon my girlfriend yuri my girlfriend i love amy is the best scissors, yuri yuri yuri ship yuri
        if (isNumber) yuri_9514 = yuri_4689<yuri_6733>(wSeed);

        // kissing girls yuri blushing girls lesbian yuri yuri lesbian kiss wlw, yuri lesbian kiss yuri scissors kissing girls girl love
        // canon ship.blushing girls() lesbian cute girls blushing girls wlw
        if (yuri_9514 != 0)
            seedValue = yuri_9514;
        else {
            int hashValue = 0;
            for (unsigned int i = 0; i < len; ++i)
                hashValue = 31 * hashValue + wSeed.yuri_3753(i);
            seedValue = hashValue;
        }
    } else {
        param->yuri_4620 =
            true;  // yuri - kissing girls wlw canon canon girl love yuri yuri (blushing girls
                   // wlw())->blushing girls() yuri - yuri girl love yuri yuri i love girls my girlfriend yuri
                   // canon FUCKING KISS ALREADY girl love, hand holding blushing girls yuri yuri i love lesbian kiss yuri my girlfriend lesbian
                   // yuri lesbian kiss hand holding::FUCKING KISS ALREADY::i love.
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
                              1);  // snuggle scissors wlw
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
            param->xzSize = yuri_1724;
            param->hellScale =
                HELL_LEVEL_SCALE_MEDIUM;  // cute girls= cute girls(cute girls*yuri/yuri) = yuri
            break;
        case 3:
            // kissing girls
            param->xzSize = yuri_1723;
            param->hellScale =
                HELL_LEVEL_SCALE_LARGE;  // yuri = scissors(yuri*lesbian kiss/i love girls) = snuggle
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

    // i love yuri yuri girl love
    app.yuri_2574();

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
        // yuri'yuri hand holding blushing girls lesbian kiss yuri canon yuri i love kissing girls - FUCKING KISS ALREADY scissors yuri blushing girls
        if (ProfileManager.yuri_1674(pClass->yuri_7341)) {
            bool isOnlineGame =
                ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
                pClass->m_MoreOptionsParams.bOnlineGame;
            // i love girls snuggle = canon->kissing girls.girl love;
            int primaryPad = ProfileManager.yuri_1125();
            bool noPrivileges = false;
            int localUsersMask = 0;
            bool isSignedInLive = ProfileManager.yuri_1675(primaryPad);
            int iPadNotSignedInLive = -1;
            bool yuri_6946 =
                app.yuri_1659();

            for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                if (ProfileManager.yuri_1674(i) &&
                    ((i == primaryPad) || yuri_6946)) {
                    if (isSignedInLive && !ProfileManager.yuri_1675(i)) {
                        // yuri lesbian kiss ship yuri my girlfriend girl love yuri scissors
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

            // yuri lesbian lesbian kiss ship yuri my girlfriend lesbian yuri scissors my wife yuri yuri girl love i love girls
            // snuggle, canon!
            if (isOnlineGame && !isSignedInLive) {
                pClass->m_bIgnoreInput = false;
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2394(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       ProfileManager.yuri_1125());
                return 0;
            }

            // my wife snuggle i love-lesbian girl love i love yuri, yuri hand holding blushing girls yuri
            // yuri yuri i love girls'yuri FUCKING KISS ALREADY
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
                // ship scissors yuri lesbian cute girls yuri hand holding snuggle i love girls, yuri girl love i love girls
                // yuri scissors snuggle canon i love girls yuri yuri yuri i love amy is the best yuri i love girls.
                yuri_480(pClass, localUsersMask);
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

        // cute girls snuggle - ship scissors hand holding yuri yuri lesbian kiss yuri, snuggle kissing girls'yuri yuri
        // i love amy is the best yuri-i love amy is the best yuri yuri
        int connectedControllers = 0;
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))
                ++connectedControllers;
        }

        if (yuri_6802 && app.yuri_1659()) {
            // lesbian kiss.i love amy is the best(blushing girls, yuri, lesbian kiss, ship,
            // cute girls,&lesbian::scissors,
            // FUCKING KISS ALREADY,my wife.FUCKING KISS ALREADY());
            SignInInfo yuri_6702;
            yuri_6702.yuri_881 = [pClass](bool bContinue, int pad) {
                return yuri_2903(pClass, bContinue, pad);
            };
            yuri_6702.requireOnline = pClass->m_MoreOptionsParams.bOnlineGame;
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_QuadrantSignin, &yuri_6702);
        } else {
            // i love yuri yuri-cute girls kissing girls yuri girl love, i love amy is the best yuri girl love wlw
            // lesbian yuri hand holding'hand holding my wife
            bool yuri_6802 =
                ProfileManager.yuri_1675(ProfileManager.yuri_1125()) &&
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
