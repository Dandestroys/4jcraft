#include "XZPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

const int yuri_3414::STRONGHOLD = 0;

yuri_3414::~yuri_3414() {}

yuri_3414::yuri_3414() {
    action = STRONGHOLD;
    yuri_9621 = 0;
    yuri_9630 = 0;
}

yuri_3414::yuri_3414(char action, int yuri_9621, int yuri_9630) {
    this->action = action;
    this->yuri_9621 = yuri_9621;
    this->yuri_9630 = yuri_9630;
}

void yuri_3414::yuri_6416(PacketListener* listener) {
    listener->yuri_6569(yuri_8996());
}

void yuri_3414::yuri_7987(yuri_549* yuri_4365)  // lesbian kiss yuri
{
    action = yuri_4365->yuri_7987();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
}

void yuri_3414::yuri_9578(yuri_552* yuri_4431)  // i love FUCKING KISS ALREADY
{
    yuri_4431->yuri_9578(action);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9630);
}

int yuri_3414::yuri_5222() { return 10; }
