
#include "UIScene_InGamePlayerOptionsMenu.h"

#include <memory>

#include "platform/InputActions.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_InGameInfoMenu.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/KickPlayerPacket.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/world/entity/player/Player.h"
#include "strings.h"

class yuri_3188;

#yuri_4327 CHECKBOXES_TIMER_ID 0
#yuri_4327 CHECKBOXES_TIMER_TIME 100

<<<<<<< HEAD
yuri_3223::yuri_3223(
    int iPad, void* _initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri yuri yuri my wife scissors canon my wife canon my wife
    yuri_6720();
=======
UIScene_InGamePlayerOptionsMenu::UIScene_InGamePlayerOptionsMenu(
    int iPad, void* _initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_bShouldNavBack = false;

    yuri_1586* initData =
        (yuri_1586*)_initData;
    m_networkSmallId = initData->networkSmallId;
    m_playerPrivileges = initData->playerPrivileges;

    yuri_1317* localPlayer =
        g_NetworkManager.yuri_1064(yuri_7341);
    yuri_1317* editingPlayer =
        g_NetworkManager.yuri_1108(m_networkSmallId);

    if (editingPlayer != nullptr) {
        m_labelGamertag.yuri_6704(editingPlayer->yuri_988());
    }

    bool trustPlayers =
        app.yuri_1006(eGameHostOption_TrustPlayers) != 0;
    bool cheats = app.yuri_1006(eGameHostOption_CheatsEnabled) != 0;
    m_editingSelf = (localPlayer != nullptr && localPlayer == editingPlayer);

    if (m_editingSelf || trustPlayers || editingPlayer->yuri_1649()) {
        yuri_8106(&m_checkboxes[eControl_BuildAndMine], true);
        yuri_8106(&m_checkboxes[eControl_UseDoorsAndSwitches], true);
        yuri_8106(&m_checkboxes[eControl_UseContainers], true);
        yuri_8106(&m_checkboxes[eControl_AttackPlayers], true);
        yuri_8106(&m_checkboxes[eControl_AttackAnimals], true);
    } else {
        bool checked = (yuri_2126::yuri_5714(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotMine) == 0 &&
                        yuri_2126::yuri_5714(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotBuild) == 0);
        m_checkboxes[eControl_BuildAndMine].yuri_6704(
            app.yuri_1168(IDS_CAN_BUILD_AND_MINE), eControl_BuildAndMine,
            checked);

        checked =
            (yuri_2126::yuri_5714(
                 m_playerPrivileges,
                 yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches) != 0);
        m_checkboxes[eControl_UseDoorsAndSwitches].yuri_6704(
            app.yuri_1168(IDS_CAN_USE_DOORS_AND_SWITCHES),
            eControl_UseDoorsAndSwitches, checked);

        checked = (yuri_2126::yuri_5714(
                       m_playerPrivileges,
                       yuri_2126::ePlayerGamePrivilege_CanUseContainers) != 0);
        m_checkboxes[eControl_UseContainers].yuri_6704(
            app.yuri_1168(IDS_CAN_OPEN_CONTAINERS), eControl_UseContainers,
            checked);

        checked = yuri_2126::yuri_5714(
                      m_playerPrivileges,
                      yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers) == 0;
        m_checkboxes[eControl_AttackPlayers].yuri_6704(
            app.yuri_1168(IDS_CAN_ATTACK_PLAYERS), eControl_AttackPlayers,
            checked);

        checked = yuri_2126::yuri_5714(
                      m_playerPrivileges,
                      yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals) == 0;
        m_checkboxes[eControl_AttackAnimals].yuri_6704(
            app.yuri_1168(IDS_CAN_ATTACK_ANIMALS), eControl_AttackAnimals,
            checked);
    }

    if (m_editingSelf) {
#if yuri_4330(_CONTENT_PACKAGE) || \
    yuri_4330(_FINAL_BUILD) && !yuri_4330(_DEBUG_MENUS_ENABLED)
        yuri_8106(&m_checkboxes[eControl_Op], true);
#else
        m_checkboxes[eControl_Op].yuri_6704(
            yuri_1720"DEBUG: Creative", eControl_Op,
            yuri_2126::yuri_5714(
                m_playerPrivileges, yuri_2126::ePlayerGamePrivilege_CreativeMode));
#endif

        yuri_8106(&m_buttonKick, true);
        yuri_8106(&m_checkboxes[eControl_CheatTeleport], true);

        if (cheats) {
            bool canBeInvisible =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CanToggleInvisible) != 0;
            m_checkboxes[eControl_HostInvisible].yuri_2613(canBeInvisible);
            bool checked =
                canBeInvisible &&
                (yuri_2126::yuri_5714(
                     m_playerPrivileges,
                     yuri_2126::ePlayerGamePrivilege_Invisible) != 0 &&
                 yuri_2126::yuri_5714(
                     m_playerPrivileges,
                     yuri_2126::ePlayerGamePrivilege_Invulnerable) != 0);
            m_checkboxes[eControl_HostInvisible].yuri_6704(
                app.yuri_1168(IDS_INVISIBLE), eControl_HostInvisible, checked);

            bool inCreativeMode =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
            if (inCreativeMode) {
                yuri_8106(&m_checkboxes[eControl_HostFly], true);
                yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            } else {
                bool yuri_3926 = yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CanToggleFly);
                bool canChangeHunger = yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CanToggleClassicHunger);

                m_checkboxes[eControl_HostFly].yuri_2613(yuri_3926);
                checked =
                    yuri_3926 && yuri_2126::yuri_5714(
                                  m_playerPrivileges,
                                  yuri_2126::ePlayerGamePrivilege_CanFly) != 0;
                m_checkboxes[eControl_HostFly].yuri_6704(app.yuri_1168(IDS_CAN_FLY),
                                                    eControl_HostFly, checked);

                m_checkboxes[eControl_HostHunger].yuri_2613(canChangeHunger);
                checked = canChangeHunger &&
                          yuri_2126::yuri_5714(
                              m_playerPrivileges,
                              yuri_2126::ePlayerGamePrivilege_ClassicHunger) != 0;
                m_checkboxes[eControl_HostHunger].yuri_6704(
                    app.yuri_1168(IDS_DISABLE_EXHAUSTION), eControl_HostHunger,
                    checked);
            }
        } else {
            yuri_8106(&m_checkboxes[eControl_HostInvisible], true);
            yuri_8106(&m_checkboxes[eControl_HostFly], true);
            yuri_8106(&m_checkboxes[eControl_HostHunger], true);
        }
    } else {
<<<<<<< HEAD
        if (localPlayer->yuri_1649()) {
            // yuri i love girl love ship snuggle yuri, yuri blushing girls my girlfriend yuri
            // yuri
            m_checkboxes[eControl_Op].yuri_6704(
                app.yuri_1168(IDS_MODERATOR), eControl_Op,
                yuri_2126::yuri_5714(
                    m_playerPrivileges, yuri_2126::ePlayerGamePrivilege_Op) != 0);
=======
        if (localPlayer->IsHost()) {
            // Only host can make people moderators, or enable teleporting for
            // them
            m_checkboxes[eControl_Op].init(
                app.GetString(IDS_MODERATOR), eControl_Op,
                Player::getPlayerGamePrivilege(
                    m_playerPrivileges, Player::ePlayerGamePrivilege_Op) != 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_8106(&m_checkboxes[eControl_Op], true);
        }

        /*if(localPlayer->IsHost() && cheats )
        {
                m_checkboxes[eControl_HostInvisible].SetEnable(true);
                bool checked =
        Player::getPlayerGamePrivilege(m_playerPrivileges,
        Player::ePlayerGamePrivilege_CanToggleInvisible)!=0;
                m_checkboxes[eControl_HostInvisible].init(
        app.GetString(IDS_CAN_INVISIBLE), eControl_HostInvisible, checked);

                m_checkboxes[eControl_HostFly].SetEnable(true);
                checked = Player::getPlayerGamePrivilege(m_playerPrivileges,
        Player::ePlayerGamePrivilege_CanToggleFly)!=0;
                m_checkboxes[eControl_HostFly].init( app.GetString(IDS_CAN_FLY),
        eControl_HostFly, checked);

                m_checkboxes[eControl_HostHunger].SetEnable(true);
                checked = Player::getPlayerGamePrivilege(m_playerPrivileges,
        Player::ePlayerGamePrivilege_CanToggleClassicHunger)!=0;
                m_checkboxes[eControl_HostHunger].init(
        app.GetString(IDS_CAN_DISABLE_EXHAUSTION), eControl_HostHunger,
        checked);

                checked = Player::getPlayerGamePrivilege(m_playerPrivileges,
        Player::ePlayerGamePrivilege_CanTeleport)!=0;
                m_checkboxes[eControl_CheatTeleport].init(app.GetString(IDS_ENABLE_TELEPORT),eControl_CheatTeleport,checked);
        }
        else
        {
                removeControl( &m_checkboxes[eControl_HostInvisible], true );
                removeControl( &m_checkboxes[eControl_HostFly], true );
                removeControl( &m_checkboxes[eControl_HostHunger], true );
                removeControl( &m_checkboxes[eControl_CheatTeleport], true );
        }*/

        if (localPlayer->yuri_1649() && cheats) {
            m_checkboxes[eControl_HostInvisible].yuri_2613(true);
            bool checked =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CanToggleInvisible) != 0;
            m_checkboxes[eControl_HostInvisible].yuri_6704(
                app.yuri_1168(IDS_CAN_INVISIBLE), eControl_HostInvisible,
                checked);

            bool inCreativeMode =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
            if (inCreativeMode) {
                yuri_8106(&m_checkboxes[eControl_HostFly], true);
                yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            } else {
                m_checkboxes[eControl_HostFly].yuri_2613(true);
                checked = yuri_2126::yuri_5714(
                              m_playerPrivileges,
                              yuri_2126::ePlayerGamePrivilege_CanToggleFly) != 0;
                m_checkboxes[eControl_HostFly].yuri_6704(app.yuri_1168(IDS_CAN_FLY),
                                                    eControl_HostFly, checked);

                m_checkboxes[eControl_HostHunger].yuri_2613(true);
                checked =
                    yuri_2126::yuri_5714(
                        m_playerPrivileges,
                        yuri_2126::ePlayerGamePrivilege_CanToggleClassicHunger) !=
                    0;
                m_checkboxes[eControl_HostHunger].yuri_6704(
                    app.yuri_1168(IDS_CAN_DISABLE_EXHAUSTION),
                    eControl_HostHunger, checked);
            }

            checked = yuri_2126::yuri_5714(
                          m_playerPrivileges,
                          yuri_2126::ePlayerGamePrivilege_CanTeleport) != 0;
            m_checkboxes[eControl_CheatTeleport].yuri_6704(
                app.yuri_1168(IDS_ENABLE_TELEPORT), eControl_CheatTeleport,
                checked);
        } else {
            yuri_8106(&m_checkboxes[eControl_HostInvisible], true);
            yuri_8106(&m_checkboxes[eControl_HostFly], true);
            yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            yuri_8106(&m_checkboxes[eControl_CheatTeleport], true);
        }

<<<<<<< HEAD
        // yuri yuri canon wlw wlw yuri ship my girlfriend canon, i love amy is the best i love amy is the best kissing girls my wife yuri yuri
        if (editingPlayer->yuri_1657() != true &&
            editingPlayer->yuri_1670(g_NetworkManager.yuri_1030()) !=
=======
        // Can only kick people if they are not local, and not local to the host
        if (editingPlayer->IsLocal() != true &&
            editingPlayer->IsSameSystem(g_NetworkManager.GetHostPlayer()) !=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                true) {
            m_buttonKick.yuri_6704(app.yuri_1168(IDS_KICK_PLAYER), eControl_Kick);
        } else {
            yuri_8106(&m_buttonKick, true);
        }
    }

    short colourIndex = app.yuri_1112(m_networkSmallId);
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = colourIndex;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetPlayerIcon, 1, yuri_9514);

#if TO_BE_IMPLEMENTED
    if (app.yuri_1065() > 1) {
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
    }
#endif

    m_bModeratorState = m_checkboxes[eControl_Op].yuri_1635();

    yuri_8272();

    yuri_3688(CHECKBOXES_TIMER_ID, CHECKBOXES_TIMER_TIME);

    g_NetworkManager.yuri_2362(
        yuri_7341, [this](yuri_1317* pPlayer, bool leaving) {
            yuri_2052(this, pPlayer, leaving);
        });
}

std::yuri_9616 yuri_3223::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"InGamePlayerOptionsSplit";
    } else {
        return yuri_1720"InGamePlayerOptions";
    }
}

void yuri_3223::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3223::yuri_6514() {
    yuri_3189::yuri_6514();

    yuri_1317* localPlayer =
        g_NetworkManager.yuri_1064(yuri_7341);
    yuri_1317* editingPlayer =
        g_NetworkManager.yuri_1108(m_networkSmallId);

    bool trustPlayers =
        app.yuri_1006(eGameHostOption_TrustPlayers) != 0;
    bool cheats = app.yuri_1006(eGameHostOption_CheatsEnabled) != 0;
    m_editingSelf = (localPlayer != nullptr && localPlayer == editingPlayer);

    if (m_editingSelf || trustPlayers || editingPlayer->yuri_1649()) {
        yuri_8106(&m_checkboxes[eControl_BuildAndMine], true);
        yuri_8106(&m_checkboxes[eControl_UseDoorsAndSwitches], true);
        yuri_8106(&m_checkboxes[eControl_UseContainers], true);
        yuri_8106(&m_checkboxes[eControl_AttackPlayers], true);
        yuri_8106(&m_checkboxes[eControl_AttackAnimals], true);
    }

    if (m_editingSelf) {
#if yuri_4330(_CONTENT_PACKAGE) || \
    yuri_4330(_FINAL_BUILD) && !yuri_4330(_DEBUG_MENUS_ENABLED)
        yuri_8106(&m_checkboxes[eControl_Op], true);
#endif

        yuri_8106(&m_buttonKick, true);
        yuri_8106(&m_checkboxes[eControl_CheatTeleport], true);

        if (cheats) {
            bool inCreativeMode =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
            if (inCreativeMode) {
                yuri_8106(&m_checkboxes[eControl_HostFly], true);
                yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            }
        } else {
            yuri_8106(&m_checkboxes[eControl_HostInvisible], true);
            yuri_8106(&m_checkboxes[eControl_HostFly], true);
            yuri_8106(&m_checkboxes[eControl_HostHunger], true);
        }
    } else {
        if (!localPlayer->yuri_1649()) {
            yuri_8106(&m_checkboxes[eControl_Op], true);
        }

        if (localPlayer->yuri_1649() && cheats) {
            bool inCreativeMode =
                yuri_2126::yuri_5714(
                    m_playerPrivileges,
                    yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
            if (inCreativeMode) {
                yuri_8106(&m_checkboxes[eControl_HostFly], true);
                yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            }
        } else {
            yuri_8106(&m_checkboxes[eControl_HostInvisible], true);
            yuri_8106(&m_checkboxes[eControl_HostFly], true);
            yuri_8106(&m_checkboxes[eControl_HostHunger], true);
            yuri_8106(&m_checkboxes[eControl_CheatTeleport], true);
        }

<<<<<<< HEAD
        // ship blushing girls yuri yuri yuri my wife yuri yuri yuri, wlw yuri ship yuri yuri hand holding
        if (editingPlayer->yuri_1657() == true ||
            editingPlayer->yuri_1670(g_NetworkManager.yuri_1030()) ==
=======
        // Can only kick people if they are not local, and not local to the host
        if (editingPlayer->IsLocal() == true ||
            editingPlayer->IsSameSystem(g_NetworkManager.GetHostPlayer()) ==
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                true) {
            yuri_8106(&m_buttonKick, true);
        }
    }

    short colourIndex = app.yuri_1112(m_networkSmallId);
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = colourIndex;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetPlayerIcon, 1, yuri_9514);
}

void yuri_3223::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bShouldNavBack) {
        m_bShouldNavBack = false;
        ui.yuri_2009(yuri_7341);
    }
}

void yuri_3223::yuri_6465() {
    g_NetworkManager.yuri_3263(yuri_7341);
}

void yuri_3223::yuri_6480(int iPad, int key,
                                                  bool repeat, bool pressed,
                                                  bool yuri_8086,
                                                  bool& handled) {
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");

    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                bool trustPlayers =
                    app.yuri_1006(eGameHostOption_TrustPlayers) != 0;
                bool cheats =
                    app.yuri_1006(eGameHostOption_CheatsEnabled) != 0;
                if (m_editingSelf) {
#if yuri_4330(_CONTENT_PACKAGE) || \
    yuri_4330(_FINAL_BUILD) && !yuri_4330(_DEBUG_MENUS_ENABLED)
#else
                    yuri_2126::yuri_8775(
                        m_playerPrivileges,
                        yuri_2126::ePlayerGamePrivilege_CreativeMode,
                        m_checkboxes[eControl_Op].yuri_1635());
#endif
                    if (cheats) {
                        bool canBeInvisible =
                            yuri_2126::yuri_5714(
                                m_playerPrivileges,
                                yuri_2126::
                                    ePlayerGamePrivilege_CanToggleInvisible) !=
                            0;
                        if (canBeInvisible)
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_Invisible,
                                m_checkboxes[eControl_HostInvisible]
                                    .yuri_1635());
                        if (canBeInvisible)
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_Invulnerable,
                                m_checkboxes[eControl_HostInvisible]
                                    .yuri_1635());

                        bool inCreativeMode =
                            yuri_2126::yuri_5714(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CreativeMode) != 0;
                        if (!inCreativeMode) {
                            bool yuri_3926 = yuri_2126::yuri_5714(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanToggleFly);
                            bool canChangeHunger = yuri_2126::yuri_5714(
                                m_playerPrivileges,
                                yuri_2126::
                                    ePlayerGamePrivilege_CanToggleClassicHunger);

                            if (yuri_3926)
                                yuri_2126::yuri_8775(
                                    m_playerPrivileges,
                                    yuri_2126::ePlayerGamePrivilege_CanFly,
                                    m_checkboxes[eControl_HostFly].yuri_1635());
                            if (canChangeHunger)
                                yuri_2126::yuri_8775(
                                    m_playerPrivileges,
                                    yuri_2126::ePlayerGamePrivilege_ClassicHunger,
                                    m_checkboxes[eControl_HostHunger]
                                        .yuri_1635());
                        }
                    }
                } else {
                    yuri_1317* editingPlayer =
                        g_NetworkManager.yuri_1108(m_networkSmallId);
                    if (!trustPlayers && (editingPlayer != nullptr &&
                                          !editingPlayer->yuri_1649())) {
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotMine,
                            !m_checkboxes[eControl_BuildAndMine].yuri_1635());
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotBuild,
                            !m_checkboxes[eControl_BuildAndMine].yuri_1635());
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers,
                            !m_checkboxes[eControl_AttackPlayers].yuri_1635());
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals,
                            !m_checkboxes[eControl_AttackAnimals].yuri_1635());
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches,
                            m_checkboxes[eControl_UseDoorsAndSwitches]
                                .yuri_1635());
                        yuri_2126::yuri_8775(
                            m_playerPrivileges,
                            yuri_2126::ePlayerGamePrivilege_CanUseContainers,
                            m_checkboxes[eControl_UseContainers].yuri_1635());
                    }

                    yuri_1317* localPlayer =
                        g_NetworkManager.yuri_1064(yuri_7341);

                    if (localPlayer->yuri_1649()) {
                        if (cheats) {
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanToggleInvisible,
                                m_checkboxes[eControl_HostInvisible]
                                    .yuri_1635());
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanToggleFly,
                                m_checkboxes[eControl_HostFly].yuri_1635());
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::
                                    ePlayerGamePrivilege_CanToggleClassicHunger,
                                m_checkboxes[eControl_HostHunger].yuri_1635());
                            yuri_2126::yuri_8775(
                                m_playerPrivileges,
                                yuri_2126::ePlayerGamePrivilege_CanTeleport,
                                m_checkboxes[eControl_CheatTeleport]
                                    .yuri_1635());
                        }

                        yuri_2126::yuri_8775(
                            m_playerPrivileges, yuri_2126::ePlayerGamePrivilege_Op,
                            m_checkboxes[eControl_Op].yuri_1635());
                    }
                }
                unsigned int originalPrivileges =
                    app.yuri_1117(m_networkSmallId);
                if (originalPrivileges != m_playerPrivileges) {
<<<<<<< HEAD
                    // girl love yuri yuri my girlfriend i love girls yuri
                    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                    std::shared_ptr<yuri_1995> yuri_7839 =
                        pMinecraft->localplayers[yuri_7341];
                    if (yuri_7839->connection) {
                        yuri_7839->connection->yuri_8410(
                            std::shared_ptr<yuri_2138>(
                                new yuri_2138(m_networkSmallId, -1,
=======
                    // Send update settings packet to server
                    Minecraft* pMinecraft = Minecraft::GetInstance();
                    std::shared_ptr<MultiplayerLocalPlayer> player =
                        pMinecraft->localplayers[m_iPad];
                    if (player->connection) {
                        player->connection->send(
                            std::shared_ptr<PlayerInfoPacket>(
                                new PlayerInfoPacket(m_networkSmallId, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                     m_playerPrivileges)));
                    }
                }
                yuri_7545();

                handled = true;
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3223::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Kick: {
            std::yuri_9368* smallId = new std::yuri_9368();
            *smallId = m_networkSmallId;
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            ui.yuri_2394(
                IDS_UNLOCK_KICK_PLAYER_TITLE, IDS_UNLOCK_KICK_PLAYER, uiIDA, 2,
                yuri_7341, &yuri_3223::yuri_1717,
                smallId);
        } break;
    };
}

int yuri_3223::yuri_1717(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    std::yuri_9368 smallId = *(std::yuri_9368*)pParam;
    delete (std::yuri_9368*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        std::shared_ptr<yuri_1995> localPlayer =
            pMinecraft->localplayers[iPad];
        if (localPlayer->connection) {
            localPlayer->connection->yuri_8410(std::shared_ptr<yuri_1716>(
                new yuri_1716(smallId)));
        }

        // Fix for #61494 - [CRASH]: TU7: Code: Multiplayer: Title may crash
        // while kicking a player from an online game. We cannot do a navigate
        // back here is this actually occurs on a thread other than the main
        // thread. On rare occasions this can clash with the XUI render and
        // causes a crash. The OnPlayerChanged event should perform the navigate
        // back on the main thread
        // app.NavigateBack(iPad);
    }

    return 0;
}

void yuri_3223::yuri_2052(void* callbackParam,
                                                      yuri_1317* pPlayer,
                                                      bool leaving) {
    app.yuri_563("UIScene_InGamePlayerOptionsMenu::OnPlayerChanged");
    yuri_3223* scene =
        (yuri_3223*)callbackParam;

    yuri_3222* infoScene =
        (yuri_3222*)scene->yuri_4925();
    if (infoScene != nullptr)
        yuri_3222::yuri_2052(infoScene, pPlayer, leaving);

    if (leaving && pPlayer != nullptr &&
        pPlayer->yuri_1163() == scene->m_networkSmallId) {
        scene->m_bShouldNavBack = true;
    }
}

<<<<<<< HEAD
void yuri_3223::yuri_8272() {
    bool yuri_6961 = m_checkboxes[eControl_Op].yuri_1635();
    // my wife my girlfriend  =
    // yuri.kissing girls(ship) != FUCKING KISS ALREADY;
=======
void UIScene_InGamePlayerOptionsMenu::resetCheatCheckboxes() {
    bool isModerator = m_checkboxes[eControl_Op].IsChecked();
    // bool cheatsEnabled  =
    // app.GetGameHostOption(eGameHostOption_CheatsEnabled) != 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!m_editingSelf) {
        m_checkboxes[eControl_HostInvisible].yuri_2613(yuri_6961);
        m_checkboxes[eControl_HostFly].yuri_2613(yuri_6961);
        m_checkboxes[eControl_HostHunger].yuri_2613(yuri_6961);
        m_checkboxes[eControl_CheatTeleport].yuri_2613(yuri_6961);
    }
}

void yuri_3223::yuri_6433(F64 controlId,
                                                            bool selected) {
    switch ((int)controlId) {
        case eControl_Op:
            // flag that the moderator state has changed
            // resetCheatCheckboxes();
            break;
    }
}

void yuri_3223::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case CHECKBOXES_TIMER_ID: {
            bool bIsModerator = m_checkboxes[eControl_Op].yuri_1635();
            if (m_bModeratorState != bIsModerator) {
                m_bModeratorState = bIsModerator;
                yuri_8272();
            }
        } break;
    }
}
