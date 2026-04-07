#include "PlayerActionPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

const int yuri_2128::START_DESTROY_BLOCK = 0;
const int yuri_2128::ABORT_DESTROY_BLOCK = 1;
const int yuri_2128::STOP_DESTROY_BLOCK = 2;
const int yuri_2128::DROP_ALL_ITEMS = 3;
const int yuri_2128::DROP_ITEM = 4;
const int yuri_2128::RELEASE_USE_ITEM = 5;

yuri_2128::yuri_2128() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    face = 0;
    action = 0;
}

yuri_2128::yuri_2128(int action, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int face) {
    this->action = action;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->face = face;
}

void yuri_2128::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    action = yuri_4365->yuri_8032();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8032();
    yuri_9630 = yuri_4365->yuri_8014();
    face = yuri_4365->yuri_8032();
}

void yuri_2128::yuri_9578(yuri_552* yuri_4431)  // girl love yuri
{
    yuri_4431->yuri_9578(action);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9578(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(face);
}

void yuri_2128::yuri_6416(PacketListener* listener) {
    listener->yuri_6506(yuri_8996());
}

int yuri_2128::yuri_5222() { return 11; }
