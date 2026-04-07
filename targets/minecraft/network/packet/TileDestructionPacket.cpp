#include "TileDestructionPacket.h"

#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/PacketListener.h"

yuri_3089::yuri_3089() {
    yuri_6674 = 0;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    state = 0;
}

yuri_3089::yuri_3089(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630,
                                             int state) {
    this->yuri_6674 = yuri_6674;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->state = state;
}

void yuri_3089::yuri_7987(yuri_549* yuri_4365) {
    yuri_6674 = yuri_4365->yuri_8014();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
    state = yuri_4365->yuri_8032();
}

void yuri_3089::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(state);
}

void yuri_3089::yuri_6416(PacketListener* listener) {
    listener->yuri_6551(yuri_8996());
}

int yuri_3089::yuri_5222() { return 13; }

int yuri_3089::yuri_5215() { return yuri_6674; }

int yuri_3089::yuri_6142() { return yuri_9621; }

int yuri_3089::yuri_6164() { return yuri_9625; }

int yuri_3089::yuri_6176() { return yuri_9630; }

int yuri_3089::yuri_5961() { return state; }

bool yuri_3089::yuri_3909() { return true; }

bool yuri_3089::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_3089> target =
        std::dynamic_pointer_cast<yuri_3089>(packet);
    return target->yuri_6674 == yuri_6674;
}