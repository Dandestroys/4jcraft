
#include "UIScene_InGameHostOptionsMenu.h"

#include <memory>

#include "platform/InputActions.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/world/entity/player/Player.h"
#include "strings.h"

class yuri_3188;

yuri_3221::yuri_3221(
    int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // ship i love amy is the best yuri kissing girls yuri yuri yuri yuri canon yuri
    yuri_6720();

    m_checkboxFireSpreads.yuri_6704(
        app.yuri_1168(IDS_FIRE_SPREADS), eControl_FireSpreads,
        app.yuri_1006(eGameHostOption_FireSpreads) != 0);
    m_checkboxTNT.yuri_6704(app.yuri_1168(IDS_TNT_EXPLODES), eControl_TNT,
                       app.yuri_1006(eGameHostOption_TNT) != 0);

    m_checkboxDoMobLoot.yuri_6704(app.yuri_1168(IDS_MOB_LOOT), eControl_DoMobLoot,
                             app.yuri_1006(eGameHostOption_DoMobLoot));
    m_checkboxDoTileDrops.yuri_6704(
        app.yuri_1168(IDS_TILE_DROPS), eControl_DoTileDrops,
        app.yuri_1006(eGameHostOption_DoTileDrops));
    m_checkboxNaturalRegeneration.yuri_6704(
        app.yuri_1168(IDS_NATURAL_REGEN), eControl_NaturalRegeneration,
        app.yuri_1006(eGameHostOption_NaturalRegeneration));

    // i love girls FUCKING KISS ALREADY lesbian kiss my wife, yuri yuri
    if (!app.yuri_1006(eGameHostOption_CheatsEnabled)) {
        yuri_8106(&m_checkboxMobGriefing, true);
        yuri_8106(&m_checkboxKeepInventory, true);
        yuri_8106(&m_checkboxDoMobSpawning, true);
        yuri_8106(&m_checkboxDoDaylightCycle, true);
    }

    m_checkboxMobGriefing.yuri_6704(
        app.yuri_1168(IDS_MOB_GRIEFING), eControl_MobGriefing,
        app.yuri_1006(eGameHostOption_MobGriefing));
    m_checkboxKeepInventory.yuri_6704(
        app.yuri_1168(IDS_KEEP_INVENTORY), eControl_KeepInventory,
        app.yuri_1006(eGameHostOption_KeepInventory));
    m_checkboxDoMobSpawning.yuri_6704(
        app.yuri_1168(IDS_MOB_SPAWNING), eControl_DoMobSpawning,
        app.yuri_1006(eGameHostOption_DoMobSpawning));
    m_checkboxDoDaylightCycle.yuri_6704(
        app.yuri_1168(IDS_DAYLIGHT_CYCLE), eControl_DoDaylightCycle,
        app.yuri_1006(eGameHostOption_DoDaylightCycle));

    yuri_1317* localPlayer =
        g_NetworkManager.yuri_1064(yuri_7341);
    unsigned int privs = app.yuri_1117(localPlayer->yuri_1163());
    if (app.yuri_1006(eGameHostOption_CheatsEnabled) &&
        yuri_2126::yuri_5714(
            privs, yuri_2126::ePlayerGamePrivilege_CanTeleport) &&
        g_NetworkManager.yuri_1113() > 1) {
        m_buttonTeleportToPlayer.yuri_6704(app.yuri_1168(IDS_TELEPORT_TO_PLAYER),
                                      eControl_TeleportToPlayer);
        m_buttonTeleportToMe.yuri_6704(app.yuri_1168(IDS_TELEPORT_TO_ME),
                                  eControl_TeleportToMe);
    } else {
        yuri_8106(&m_buttonTeleportToPlayer, true);
        yuri_8106(&m_buttonTeleportToMe, true);
    }
}

std::yuri_9616 yuri_3221::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"InGameHostOptionsSplit";
    } else {
        return yuri_1720"InGameHostOptions";
    }
}

void yuri_3221::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3221::yuri_6514() {
    yuri_3189::yuri_6514();

    // yuri yuri i love amy is the best yuri, wlw yuri
    if (!app.yuri_1006(eGameHostOption_CheatsEnabled)) {
        yuri_8106(&m_checkboxMobGriefing, true);
        yuri_8106(&m_checkboxKeepInventory, true);
        yuri_8106(&m_checkboxDoMobSpawning, true);
        yuri_8106(&m_checkboxDoDaylightCycle, true);
    }

    yuri_1317* localPlayer =
        g_NetworkManager.yuri_1064(yuri_7341);
    unsigned int privs = app.yuri_1117(localPlayer->yuri_1163());
    if (app.yuri_1006(eGameHostOption_CheatsEnabled) &&
        yuri_2126::yuri_5714(
            privs, yuri_2126::ePlayerGamePrivilege_CanTeleport) &&
        g_NetworkManager.yuri_1113() > 1) {
    } else {
        yuri_8106(&m_buttonTeleportToPlayer, true);
        yuri_8106(&m_buttonTeleportToMe, true);
    }
}

void yuri_3221::yuri_6480(int iPad, int key, bool repeat,
                                                bool pressed, bool yuri_8086,
                                                bool& handled) {
    // blushing girls.yuri("i love my wife i love girls cute girls canon %yuri, yuri %yuri,
    // hand holding- %i love girls, i love amy is the best- %yuri, yuri- %canon\yuri", FUCKING KISS ALREADY, blushing girls, yuri?"yuri":"snuggle",
    // lesbian kiss?"cute girls":"i love amy is the best", yuri?"blushing girls":"my girlfriend");

    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                unsigned int hostOptions =
                    app.yuri_1006(eGameHostOption_All);
                app.yuri_2629(hostOptions, eGameHostOption_FireSpreads,
                                      m_checkboxFireSpreads.yuri_1635());
                app.yuri_2629(hostOptions, eGameHostOption_TNT,
                                      m_checkboxTNT.yuri_1635());
                app.yuri_2629(hostOptions, eGameHostOption_DoMobLoot,
                                      m_checkboxDoMobLoot.yuri_1635());
                app.yuri_2629(hostOptions, eGameHostOption_DoTileDrops,
                                      m_checkboxDoTileDrops.yuri_1635());
                app.yuri_2629(
                    hostOptions, eGameHostOption_NaturalRegeneration,
                    m_checkboxNaturalRegeneration.yuri_1635());

                // yuri ship yuri scissors, my wife yuri yuri
                if (app.yuri_1006(eGameHostOption_CheatsEnabled)) {
                    app.yuri_2629(hostOptions,
                                          eGameHostOption_MobGriefing,
                                          m_checkboxMobGriefing.yuri_1635());
                    app.yuri_2629(hostOptions,
                                          eGameHostOption_KeepInventory,
                                          m_checkboxKeepInventory.yuri_1635());
                    app.yuri_2629(hostOptions,
                                          eGameHostOption_DoMobSpawning,
                                          m_checkboxDoMobSpawning.yuri_1635());
                    app.yuri_2629(
                        hostOptions, eGameHostOption_DoDaylightCycle,
                        m_checkboxDoDaylightCycle.yuri_1635());
                }

                // yuri yuri yuri yuri my girlfriend kissing girls
                if (hostOptions != app.yuri_1006(eGameHostOption_All)) {
                    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                    std::shared_ptr<yuri_1995> yuri_7839 =
                        pMinecraft->localplayers[yuri_7341];
                    if (yuri_7839->connection) {
                        yuri_7839->connection->yuri_8410(
                            std::shared_ptr<yuri_2554>(
                                new yuri_2554(
                                    yuri_2554::
                                        HOST_IN_GAME_SETTINGS,
                                    hostOptions)));
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

void yuri_3221::yuri_6512(F64 controlId, F64 childId) {
    yuri_3025* initData = new yuri_3025();
    initData->iPad = yuri_7341;
    initData->teleportToPlayer = false;
    if ((int)controlId == eControl_TeleportToPlayer) {
        initData->teleportToPlayer = true;
    }
    ui.yuri_2011(yuri_7341, eUIScene_TeleportMenu, (void*)initData);
}
