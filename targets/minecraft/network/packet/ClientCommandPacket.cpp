#include "ClientCommandPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_373::yuri_373() { action = 0; }

yuri_373::yuri_373(int action) { this->action = action; }

void yuri_373::yuri_7987(yuri_549* yuri_4365) {
    action = (int)yuri_4365->yuri_7996();
}

void yuri_373::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9584((yuri_9368)action & (yuri_9368)0xff);
}

void yuri_373::yuri_6416(PacketListener* listener) {
    listener->yuri_6437(
        std::dynamic_pointer_cast<yuri_373>(yuri_8996()));
}

int yuri_373::yuri_5222() { return 1; }
