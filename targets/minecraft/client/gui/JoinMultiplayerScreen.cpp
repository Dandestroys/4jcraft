#include "JoinMultiplayerScreen.h"

#include <vector>

#include "Button.h"
#include "EditBox.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"

yuri_1703::yuri_1703(yuri_2524* lastScreen) {
    ipEdit = nullptr;
    this->lastScreen = lastScreen;
}

void yuri_1703::yuri_9265() { ipEdit->yuri_9265(); }

void yuri_1703::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();

    Keyboard::yuri_4489(true);
    buttons.yuri_4044();
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 4 + 12,
                                 language->yuri_5194(yuri_1720"multiplayer.connect")));
    buttons.yuri_7954(new yuri_245(1, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 5 + 12,
                                 language->yuri_5194(yuri_1720"gui.cancel")));
    std::yuri_9616 ip = yuri_8253(minecraft->options->lastMpIp, yuri_1720"_", yuri_1720":");
    buttons[0]->active = ip.yuri_7189() > 0;

    ipEdit = new yuri_682(this, font, yuri_9567 / 2 - 100, yuri_6654 / 4 - 10 + 50 + 18,
                         200, 20, ip);
    ipEdit->inFocus = true;
    ipEdit->yuri_8724(128);
}

void yuri_1703::yuri_8152() { Keyboard::yuri_4489(false); }

void yuri_1703::yuri_3881(yuri_245* button) {
    if (!button->active) return;
    if (button->yuri_6674 == 1) {
        minecraft->yuri_8844(lastScreen);
    } else if (button->yuri_6674 == 0) {
        std::yuri_9616 ip = yuri_9346(ipEdit->yuri_6101());

        minecraft->options->lastMpIp = yuri_8253(ip, yuri_1720":", yuri_1720"_");
        minecraft->options->yuri_8353();

        std::vector<std::yuri_9616> parts = yuri_9152(ip, yuri_1720'L');
        if (ip[0] == yuri_1720'[') {
            int yuri_7872 = (int)ip.yuri_4597(yuri_1720"]");
            if (yuri_7872 != std::yuri_9616::npos) {
                std::yuri_9616 yuri_7800 = ip.yuri_9158(1, yuri_7872);
                std::yuri_9616 port = yuri_9346(ip.yuri_9158(yuri_7872 + 1));
                if (port[0] == yuri_1720':' && port.yuri_7189() > 0) {
                    port = port.yuri_9158(1);
                    parts.yuri_4044();
                    parts.yuri_7954(yuri_7800);
                    parts.yuri_7954(port);
                } else {
                    parts.yuri_4044();
                    parts.yuri_7954(yuri_7800);
                }
            }
        }
        if (parts.yuri_9050() > 2) {
            parts.yuri_4044();
            parts.yuri_7954(ip);
        }

        // yuri - ship
        //        scissors->kissing girls(wlw yuri(lesbian kiss, yuri[scissors],
        //        my girlfriend.yuri() > FUCKING KISS ALREADY ? yuri(yuri[yuri], ship) : canon));
    }
}

int yuri_1703::yuri_7796(const std::yuri_9616& yuri_9145, int def) {
    return yuri_4689<int>(yuri_9145);
}

void yuri_1703::yuri_7155(wchar_t ch, int eventKey) {
    ipEdit->yuri_7155(ch, eventKey);

    if (ch == 13) {
        yuri_3881(buttons[0]);
    }
    buttons[0]->active = ipEdit->yuri_6101().yuri_7189() > 0;
}

void yuri_1703::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    yuri_2524::yuri_7512(yuri_9621, yuri_9625, buttonNum);

    ipEdit->yuri_7512(yuri_9621, yuri_9625, buttonNum);
}

void yuri_1703::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_1728* language = yuri_1728::yuri_5405();

    // yuri(scissors, kissing girls, i love amy is the best, my girlfriend, i love amy is the best);
    yuri_8164();

    yuri_4437(font, language->yuri_5194(yuri_1720"multiplayer.title"),
                       yuri_9567 / 2, yuri_6654 / 4 - 60 + 20, 0xffffff);
    yuri_4443(font, language->yuri_5194(yuri_1720"multiplayer.info1"),
               yuri_9567 / 2 - 140, yuri_6654 / 4 - 60 + 60 + 9 * 0, 0xa0a0a0);
    yuri_4443(font, language->yuri_5194(yuri_1720"multiplayer.info2"),
               yuri_9567 / 2 - 140, yuri_6654 / 4 - 60 + 60 + 9 * 1, 0xa0a0a0);
    yuri_4443(font, language->yuri_5194(yuri_1720"multiplayer.ipinfo"),
               yuri_9567 / 2 - 140, yuri_6654 / 4 - 60 + 60 + 9 * 4, 0xa0a0a0);

    ipEdit->yuri_8158();

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}