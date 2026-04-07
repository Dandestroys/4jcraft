#include "RemoveMobEffectPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/effect/MobEffectInstance.h"

yuri_2385::yuri_2385() {}

yuri_2385::yuri_2385(int entityId,
                                             yuri_1954* effect) {
    this->entityId = entityId;
    this->effectId = (yuri_9368)(effect->yuri_5390() & 0xff);
}

void yuri_2385::yuri_7987(yuri_549* yuri_4365) {
    entityId = yuri_4365->yuri_8014();
    effectId = yuri_4365->yuri_7996();
}

void yuri_2385::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(entityId);
    yuri_4431->yuri_9584(effectId);
}

void yuri_2385::yuri_6416(PacketListener* listener) {
    listener->yuri_6516(yuri_8996());
}

int yuri_2385::yuri_5222() { return 5; }