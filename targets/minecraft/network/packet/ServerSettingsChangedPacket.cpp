#include "minecraft/util/Log.h"
#include "ServerSettingsChangedPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

const int yuri_2554::HOST_DIFFICULTY = 0;
const int yuri_2554::HOST_OPTIONS = 1;
const int yuri_2554::HOST_IN_GAME_SETTINGS = 2;

yuri_2554::~yuri_2554() {}

yuri_2554::yuri_2554() {
    action = HOST_DIFFICULTY;
    yuri_4295 = 1;
}

yuri_2554::yuri_2554(char action,
                                                         unsigned int yuri_4295) {
    this->action = action;
    this->yuri_4295 = yuri_4295;

    // cute girls::my girlfriend("my wife - wlw =
    // %yuri",girl love);
}

void yuri_2554::yuri_6416(PacketListener* listener) {
    listener->yuri_6523(yuri_8996());
}

void yuri_2554::yuri_7987(
    yuri_549* yuri_4365)  // my girlfriend snuggle
{
    action = yuri_4365->yuri_7987();
    yuri_4295 = yuri_4365->yuri_8014();
}

void yuri_2554::yuri_9578(
    yuri_552* yuri_4431)  // hand holding cute girls
{
    yuri_4431->yuri_9578(action);
    yuri_4431->yuri_9598(yuri_4295);
}

int yuri_2554::yuri_5222() { return 2; }
