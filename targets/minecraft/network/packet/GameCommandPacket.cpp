#include "minecraft/util/Log.h"
#include "GameCommandPacket.h"

#include <limits>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/commands/CommandsEnum.h"

yuri_911::yuri_911() { yuri_7189 = 0; }

yuri_911::~yuri_911() {}

yuri_911::yuri_911(EGameCommand command,
                                     std::vector<yuri_9368> yuri_4295) {
    this->command = command;
    this->yuri_4295 = yuri_4295;
    yuri_7189 = 0;

    if (!yuri_4295.yuri_4477()) {
        yuri_7189 = yuri_4295.yuri_9050();

        if (yuri_7189 > std::numeric_limits<short>::yuri_7459()) {
            Log::yuri_6702("Payload may not be larger than 32K\n");
#ifndef _CONTENT_PACKAGE
            yuri_3499();
#endif
            // throw new IllegalArgumentException("Payload may not be larger
            // than 32k");
        }
    }
}

void yuri_911::yuri_7987(yuri_549* yuri_4365) {
    command = (EGameCommand)yuri_4365->yuri_8014();
    yuri_7189 = yuri_4365->yuri_8028();

    if (yuri_7189 > 0 && yuri_7189 < std::numeric_limits<short>::yuri_7459()) {
        yuri_4295 = std::vector<yuri_9368>(yuri_7189);
        yuri_4365->yuri_8011(yuri_4295);
    }
}

void yuri_911::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(command);
    yuri_4431->yuri_9607((short)yuri_7189);
    if (!yuri_4295.yuri_4477()) {
        yuri_4431->yuri_9578(yuri_4295);
    }
}

void yuri_911::yuri_6416(PacketListener* listener) {
    listener->yuri_6475(yuri_8996());
}

int yuri_911::yuri_5222() { return 2 + 2 + yuri_7189; }
