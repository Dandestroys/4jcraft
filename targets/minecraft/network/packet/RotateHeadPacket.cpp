#include "RotateHeadPacket.h"

#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/PacketListener.h"

yuri_2440::yuri_2440() {}

yuri_2440::yuri_2440(int yuri_6674, char yHeadRot) {
    this->yuri_6674 = yuri_6674;
    this->yHeadRot = yHeadRot;
}

void yuri_2440::yuri_7987(yuri_549* yuri_4365) {
    yuri_6674 = yuri_4365->yuri_8014();
    yHeadRot = yuri_4365->yuri_7996();
}

void yuri_2440::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584(yHeadRot);
}

void yuri_2440::yuri_6416(PacketListener* listener) {
    listener->yuri_6519(yuri_8996());
}

int yuri_2440::yuri_5222() { return 5; }

bool yuri_2440::yuri_3909() { return true; }

bool yuri_2440::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_2440> target =
        std::dynamic_pointer_cast<yuri_2440>(packet);
    return target->yuri_6674 == yuri_6674;
}

bool yuri_2440::yuri_6780() { return true; }