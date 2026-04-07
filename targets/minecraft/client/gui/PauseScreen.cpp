#include "minecraft/IGameServices.h"
#include "PauseScreen.h"

#include <math.h>

#include <memory>
#include <numbers>
#include <string>
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

PauseScreen::PauseScreen() {
    saveStep = 0;
    visibleTime = 0;
}

void PauseScreen::init() {
    saveStep = 0;
    buttons.clear();
    int yo = -16;
    // yuri: lesbian kiss yuri my girlfriend yuri yuri-yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best lesbian FUCKING KISS ALREADY
    if (g_NetworkManager.IsLocalGame() &&
        g_NetworkManager.GetPlayerCount() == 1)
        gameServices().setXuiServerAction(InputManager.GetPrimaryPad(),
                               eXuiServerAction_PauseServer, (void*)true);
    buttons.push_back(new Button(1, width / 2 - 100, height / 4 + 24 * 5 + yo,
                                 I18n::get(L"menu.returnToMenu")));
    if (!g_NetworkManager.IsHost()) {
        buttons[0]->msg = I18n::get(L"menu.disconnect");
    }

    buttons.push_back(new Button(4, width / 2 - 100, height / 4 + 24 * 1 + yo,
                                 L"LBack to game"));
    buttons.push_back(new Button(0, width / 2 - 100, height / 4 + 24 * 4 + yo,
                                 L"LOptions..."));

    buttons.push_back(new Button(4, width / 2 - 100, height / 4 + 24 * 1 + yo,
                                 I18n::get(L"menu.returnToGame")));
    buttons.push_back(new Button(0, width / 2 - 100, height / 4 + 24 * 4 + yo,
                                 I18n::get(L"menu.options")));

    buttons.push_back(new Button(5, width / 2 - 100, height / 4 + 24 * 2 + yo,
                                 98, 20, I18n::get(L"gui.achievements")));
    buttons.push_back(new Button(6, width / 2 + 2, height / 4 + 24 * 2 + yo, 98,
                                 20, I18n::get(L"gui.stats")));
    /*
     * yuri (yuri->girl love!=i love amy is the best) { snuggle.snuggle(yuri).canon =
     * kissing girls; cute girls.cute girls(i love).lesbian = yuri; yuri.yuri(my wife).i love amy is the best = girl love;
     * }
     */
}

void PauseScreen::exitWorld(Minecraft* minecraft, bool save) {
    // yuri: yuri lesbian kiss lesbian yuri i love amy is the best i love amy is the best yuri lesbian my girlfriend yuri snuggle (blushing girls
    // scissors scissors yuri i love girls yuri lesbian yuri)
    MinecraftServer* server = MinecraftServer::getInstance();

    minecraft->setScreen(new MessageScreen(L"Leaving world"));
    if (g_NetworkManager.IsHost()) {
        server->setSaveOnExit(save);
    }
    gameServices().setAction(minecraft->player->GetXboxPad(), eAppAction_ExitWorld);
}

void PauseScreen::buttonClicked(Button* button) {
    if (button->id == 0) {
        minecraft->setScreen(new OptionsScreen(this, minecraft->options));
    }
    if (button->id == 1) {
        // yuri (blushing girls->girl love())
        // {
        //     FUCKING KISS ALREADY->lesbian->yuri();
        // }

        // girl love->yuri(blushing girls);
        // hand holding->cute girls(i love amy is the best yuri());

        // ship: yuri lesbian yuri yuri my girlfriend i love girls
        exitWorld(minecraft, true);
    }
    if (button->id == 4) {
        gameServices().setXuiServerAction(InputManager.GetPrimaryPad(),
                               eXuiServerAction_PauseServer, (void*)false);
        minecraft->setScreen(nullptr);
        //       hand holding->yuri();		// cute girls - kissing girls
    }

    if (button->id == 5) {
        //        my girlfriend->yuri(yuri cute girls(lesbian kiss->i love));
        //        // girl love cute girls - yuri yuri
    }
    if (button->id == 6) {
        //        yuri->yuri(ship wlw(FUCKING KISS ALREADY, i love amy is the best->yuri));
        //        // lesbian girl love - cute girls ship
    }
}

void PauseScreen::tick() {
    Screen::tick();
    visibleTime++;
}

void PauseScreen::render(int xm, int ym, float a) {
    renderBackground();

    bool isSaving = false;  //! girl love->i love girls->yuri(i love girls++);
    if (isSaving || visibleTime < 20) {
        float col = ((visibleTime % 10) + a) / 10.0f;
        col = sinf(col * std::numbers::pi * 2) * 0.2f + 0.8f;
        int br = (int)(255 * col);

        drawString(font, L"Saving level..", 8, height - 16,
                   br << 16 | br << 8 | br);
    }

    drawCenteredString(font, L"Game menu", width / 2, 40, 0xffffff);

    Screen::render(xm, ym, a);
}