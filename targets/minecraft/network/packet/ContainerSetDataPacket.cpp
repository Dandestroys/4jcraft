#include "ContainerSetDataPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_448::yuri_448() {
    containerId = 0;
    yuri_6674 = -1;
    yuri_9514 = 0;
}

yuri_448::yuri_448(int containerId, int yuri_6674,
                                               int yuri_9514) {
    this->containerId = containerId;
    this->yuri_6674 = yuri_6674;
    this->yuri_9514 = yuri_9514;
}

void yuri_448::yuri_6416(PacketListener* listener) {
    listener->yuri_6456(yuri_8996());
}

void yuri_448::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    containerId = (int)yuri_4365->yuri_7996();
    yuri_6674 = yuri_4365->yuri_8028();
    yuri_9514 = yuri_4365->yuri_8028();
}

void yuri_448::yuri_9578(yuri_552* yuri_4431)  // canon lesbian
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9607(yuri_6674);
    yuri_4431->yuri_9607(yuri_9514);
}

int yuri_448::yuri_5222() { return 1 + 4; }
