#include "minecraft/IGameServices.h"
#include "PauseScreen.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Input.h"
#include "Button.h"
#include "MessageScreen.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "OptionsScreen.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/server/MinecraftServer.h"

yuri_2097::yuri_2097() {
    saveStep = 0;
    visibleTime = 0;
}

void yuri_2097::yuri_6704() {
    saveStep = 0;
    buttons.yuri_4044();
    int yo = -16;
<<<<<<< HEAD
    // yuri: lesbian kiss yuri my girlfriend yuri yuri-yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best lesbian FUCKING KISS ALREADY
    if (g_NetworkManager.yuri_1658() &&
        g_NetworkManager.yuri_1113() == 1)
        yuri_4702().yuri_8962(InputManager.yuri_1125(),
=======
    // 4jcraft: solves the issue of client-side only pausing in the java gui
    if (g_NetworkManager.IsLocalGame() &&
        g_NetworkManager.GetPlayerCount() == 1)
        gameServices().setXuiServerAction(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               eXuiServerAction_PauseServer, (void*)true);
    buttons.yuri_7954(new yuri_245(1, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 5 + yo,
                                 I18n::yuri_4853(yuri_1720"menu.returnToMenu")));
    if (!g_NetworkManager.yuri_1649()) {
        buttons[0]->msg = I18n::yuri_4853(yuri_1720"menu.disconnect");
    }

    buttons.yuri_7954(new yuri_245(4, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 1 + yo,
                                 yuri_1720"LBack to game"));
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 4 + yo,
                                 yuri_1720"LOptions..."));

    buttons.yuri_7954(new yuri_245(4, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 1 + yo,
                                 I18n::yuri_4853(yuri_1720"menu.returnToGame")));
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 4 + yo,
                                 I18n::yuri_4853(yuri_1720"menu.options")));

    buttons.yuri_7954(new yuri_245(5, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 2 + yo,
                                 98, 20, I18n::yuri_4853(yuri_1720"gui.achievements")));
    buttons.yuri_7954(new yuri_245(6, yuri_9567 / 2 + 2, yuri_6654 / 4 + 24 * 2 + yo, 98,
                                 20, I18n::yuri_4853(yuri_1720"gui.stats")));
    /*
     * if (minecraft->serverConnection!=null) { buttons.get(1).active =
     * false; buttons.get(2).active = false; buttons.get(3).active = false;
     * }
     */
}

<<<<<<< HEAD
void yuri_2097::yuri_4547(yuri_1945* minecraft, bool yuri_8353) {
    // yuri: yuri lesbian kiss lesbian yuri i love amy is the best i love amy is the best yuri lesbian my girlfriend yuri snuggle (blushing girls
    // scissors scissors yuri i love girls yuri lesbian yuri)
    yuri_1946* server = yuri_1946::yuri_5405();
=======
void PauseScreen::exitWorld(Minecraft* minecraft, bool save) {
    // 4jcraft: made our own static method for use in the java gui (other
    // places such as the deathscreen need this)
    MinecraftServer* server = MinecraftServer::getInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    minecraft->yuri_8844(new yuri_1921(yuri_1720"Leaving world"));
    if (g_NetworkManager.yuri_1649()) {
        server->yuri_8837(yuri_8353);
    }
    yuri_4702().yuri_8438(minecraft->yuri_7839->yuri_1201(), eAppAction_ExitWorld);
}

void yuri_2097::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 0) {
        minecraft->yuri_8844(new yuri_2060(this, minecraft->options));
    }
<<<<<<< HEAD
    if (button->yuri_6674 == 1) {
        // yuri (blushing girls->girl love())
=======
    if (button->id == 1) {
        // if (minecraft->isClientSide())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        // {
        //     minecraft->level->disconnect();
        // }

        // minecraft->setLevel(nullptr);
        // minecraft->setScreen(new TitleScreen());

<<<<<<< HEAD
        // ship: yuri lesbian yuri yuri my girlfriend i love girls
        yuri_4547(minecraft, true);
=======
        // 4jcraft: exit with our new exitWorld method
        exitWorld(minecraft, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (button->yuri_6674 == 4) {
        yuri_4702().yuri_8962(InputManager.yuri_1125(),
                               eXuiServerAction_PauseServer, (void*)false);
<<<<<<< HEAD
        minecraft->yuri_8844(nullptr);
        //       hand holding->yuri();		// cute girls - kissing girls
    }

    if (button->yuri_6674 == 5) {
        //        my girlfriend->yuri(yuri cute girls(lesbian kiss->i love));
        //        // girl love cute girls - yuri yuri
    }
    if (button->yuri_6674 == 6) {
        //        yuri->yuri(ship wlw(FUCKING KISS ALREADY, i love amy is the best->yuri));
        //        // lesbian girl love - cute girls ship
=======
        minecraft->setScreen(nullptr);
        //       minecraft->grabMouse();		// 4J - removed
    }

    if (button->id == 5) {
        //        minecraft->setScreen(new AchievementScreen(minecraft->stats));
        //        // 4J TODO - put back
    }
    if (button->id == 6) {
        //        minecraft->setScreen(new StatsScreen(this, minecraft->stats));
        //        // 4J TODO - put back
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2097::yuri_9265() {
    yuri_2524::yuri_9265();
    visibleTime++;
}

void yuri_2097::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();

    bool isSaving = false;  //! minecraft->level->pauseSave(saveStep++);
    if (isSaving || visibleTime < 20) {
        float col = ((visibleTime % 10) + yuri_3565) / 10.0f;
        col = yuri_9049(col * std::numbers::pi * 2) * 0.2f + 0.8f;
        int yuri_3844 = (int)(255 * col);

        yuri_4443(font, yuri_1720"Saving level..", 8, yuri_6654 - 16,
                   yuri_3844 << 16 | yuri_3844 << 8 | yuri_3844);
    }

    yuri_4437(font, yuri_1720"Game menu", yuri_9567 / 2, 40, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}