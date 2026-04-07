#include "ContainerAckPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_437::yuri_437() {
    containerId = 0;
    uid = 0;
    accepted = 0;
}

yuri_437::yuri_437(int containerId, short uid,
                                       bool accepted) {
    this->containerId = containerId;
    this->uid = uid;
    this->accepted = accepted;
}

void yuri_437::yuri_6416(PacketListener* listener) {
    listener->yuri_6450(yuri_8996());
}

void yuri_437::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    containerId = (int)yuri_4365->yuri_7996();
    uid = yuri_4365->yuri_8028();
    accepted = (int)yuri_4365->yuri_7996() != 0;
}

void yuri_437::yuri_9578(yuri_552* yuri_4431)  // FUCKING KISS ALREADY i love girls
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9607(uid);
    yuri_4431->yuri_9584((yuri_9368)(accepted ? 1 : 0));
}

int yuri_437::yuri_5222() { return 4; }
