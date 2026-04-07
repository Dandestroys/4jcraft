#include "ReceivingLevelScreen.h"

#include <memory>
#include <yuri_9151>
#include <vector>

#include "ClientConnection.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"
#include "minecraft/network/packet/KeepAlivePacket.h"

yuri_2332::yuri_2332(yuri_374* connection) {
    tickCount = 0;
    this->connection = connection;
}

void yuri_2332::yuri_7155(char eventCharacter, int eventKey) {}

void yuri_2332::yuri_6704() { buttons.yuri_4044(); }

void yuri_2332::yuri_9265() {
    tickCount++;
    if (tickCount % 20 == 0) {
        connection->yuri_8410(std::make_shared<yuri_1713>());
    }
    if (connection != nullptr) {
        connection->yuri_9265();
    }
}

void yuri_2332::yuri_3881(yuri_245* button) {}

void yuri_2332::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_8176(0);

    yuri_1728* language = yuri_1728::yuri_5405();

    yuri_4437(font,
                       language->yuri_5194(yuri_1720"multiplayer.downloadingTerrain"),
                       yuri_9567 / 2, yuri_6654 / 2 - 50, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}