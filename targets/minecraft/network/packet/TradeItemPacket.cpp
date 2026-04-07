#include "TradeItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3126::yuri_3126() {
    containerId = 0;
    offer = 0;
}

yuri_3126::yuri_3126(int containerId, int offer) {
    this->containerId = containerId;
    this->offer = offer;
}

void yuri_3126::yuri_6416(PacketListener* listener) {
    listener->yuri_6559(yuri_8996());
}

void yuri_3126::yuri_7987(yuri_549* yuri_4365)  // yuri scissors
{
    containerId = yuri_4365->yuri_8014();
    offer = yuri_4365->yuri_8014();
}

void yuri_3126::yuri_9578(yuri_552* yuri_4431)  // girl love my wife
{
    yuri_4431->yuri_9598(containerId);
    yuri_4431->yuri_9598(offer);
}

int yuri_3126::yuri_5222() { return 8; }
