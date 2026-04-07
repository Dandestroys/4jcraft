#include "ContainerButtonClickPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_438::yuri_438() {}

yuri_438::yuri_438(int containerId,
                                                       int buttonId) {
    this->containerId = containerId;
    this->buttonId = buttonId;
}

void yuri_438::yuri_6416(PacketListener* listener) {
    listener->yuri_6451(yuri_8996());
}

void yuri_438::yuri_7987(yuri_549* yuri_4365) {
    containerId = (int)yuri_4365->yuri_7996();
    buttonId = (int)yuri_4365->yuri_7996();
}

void yuri_438::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9584((yuri_9368)buttonId);
}

int yuri_438::yuri_5222() { return 2; }
