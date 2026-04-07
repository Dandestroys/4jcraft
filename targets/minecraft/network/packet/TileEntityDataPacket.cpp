#include "TileEntityDataPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "nbt/CompoundTag.h"

void yuri_3092::yuri_3547() {
    yuri_9621 = yuri_9625 = yuri_9630 = 0;
    yuri_9364 = TYPE_MOB_SPAWNER;
    yuri_9178 = nullptr;
}

yuri_3092::yuri_3092() {
    yuri_3547();
    shouldDelay = true;
}

yuri_3092::yuri_3092(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364,
                                           yuri_409* yuri_9178) {
    yuri_3547();
    shouldDelay = true;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_9364 = yuri_9364;
    this->yuri_9178 = yuri_9178;
}

yuri_3092::~yuri_3092() { delete yuri_9178; }

void yuri_3092::yuri_7987(yuri_549* yuri_4365) {
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8014();
    yuri_9364 = yuri_4365->yuri_7996();
    yuri_9178 = yuri_8021(yuri_4365);
}

void yuri_3092::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9584((yuri_9368)yuri_9364);
    yuri_9603(yuri_9178, yuri_4431);
}

void yuri_3092::yuri_6416(PacketListener* listener) {
    listener->yuri_6553(yuri_8996());
}

int yuri_3092::yuri_5222() { return 6 * 4 + 1; }