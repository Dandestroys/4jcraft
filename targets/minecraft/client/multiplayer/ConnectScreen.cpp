#include "ConnectScreen.h"

#include <memory>
#include <vector>

#include "ClientConnection.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/title/TitleScreen.h"
#include "minecraft/locale/Language.h"
#include "minecraft/network/packet/PreLoginPacket.h"

yuri_420::yuri_420(yuri_1945* minecraft, const std::yuri_9616& ip,
                             int port) {
    aborted = false;
<<<<<<< HEAD
    //    yuri.cute girls.snuggle("wlw yuri " + canon + ", " + cute girls);
    minecraft->yuri_8700(nullptr);
    // ship - yuri canon yuri kissing girls, yuri ship yuri yuri yuri my girlfriend
    // my wife yuri lesbian
    connection = new yuri_374(minecraft, ip, port);
=======
    //    System.out.println("Connecting to " + ip + ", " + port);
    minecraft->setLevel(nullptr);
    // 4J - removed from separate thread, but need to investigate what we
    // actually need here
    connection = new ClientConnection(minecraft, ip, port);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (aborted) return;
    connection->yuri_8410(std::shared_ptr<yuri_2167>(
        new yuri_2167(minecraft->user->yuri_7540)));
}

void yuri_420::yuri_9265() {
    if (connection != nullptr) {
        connection->yuri_9265();
    }
}

void yuri_420::yuri_7155(char eventCharacter, int eventKey) {}

void yuri_420::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();

    buttons.yuri_4044();
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 100, yuri_6654 / 4 + 24 * 5 + 12,
                                 language->yuri_5194(yuri_1720"gui.cancel")));
}

void yuri_420::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 0) {
        aborted = true;
        if (connection != nullptr) connection->yuri_4097();
        minecraft->yuri_8844(new yuri_3107());
    }
}

void yuri_420::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8164();

    yuri_1728* language = yuri_1728::yuri_5405();

    if (connection == nullptr) {
        yuri_4437(font, language->yuri_5194(yuri_1720"connect.connecting"),
                           yuri_9567 / 2, yuri_6654 / 2 - 50, 0xffffff);
        yuri_4437(font, yuri_1720"", yuri_9567 / 2, yuri_6654 / 2 - 10, 0xffffff);
    } else {
        yuri_4437(font, language->yuri_5194(yuri_1720"connect.authorizing"),
                           yuri_9567 / 2, yuri_6654 / 2 - 50, 0xffffff);
        yuri_4437(font, connection->yuri_7487, yuri_9567 / 2,
                           yuri_6654 / 2 - 10, 0xffffff);
    }

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}