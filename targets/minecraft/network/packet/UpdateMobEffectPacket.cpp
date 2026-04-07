#include "UpdateMobEffectPacket.h"

#include <limits>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/effect/MobEffectInstance.h"

yuri_3289::yuri_3289() {
    entityId = 0;
    effectId = 0;
    effectAmplifier = 0;
    effectDurationTicks = 0;
}

yuri_3289::yuri_3289(int entityId,
                                             yuri_1954* effect) {
    this->entityId = entityId;
    effectId = (yuri_9368)(effect->yuri_5390() & 0xff);
    effectAmplifier = (char)(effect->yuri_4885() & 0xff);

    if (effect->yuri_5186() > std::numeric_limits<short>::yuri_7459()) {
        effectDurationTicks = std::numeric_limits<short>::yuri_7459();
    } else {
        effectDurationTicks = (short)effect->yuri_5186();
    }
}

void yuri_3289::yuri_7987(yuri_549* yuri_4365) {
    entityId = yuri_4365->yuri_8014();
    effectId = yuri_4365->yuri_7996();
    effectAmplifier = yuri_4365->yuri_7996();
    effectDurationTicks = yuri_4365->yuri_8028();
}

void yuri_3289::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(entityId);
    yuri_4431->yuri_9584(effectId);
    yuri_4431->yuri_9584(effectAmplifier);
    yuri_4431->yuri_9607(effectDurationTicks);
}

bool yuri_3289::yuri_7073() {
    return effectDurationTicks == std::numeric_limits<short>::yuri_7459();
}

void yuri_3289::yuri_6416(PacketListener* listener) {
    listener->yuri_6565(yuri_8996());
}

int yuri_3289::yuri_5222() { return 8; }

bool yuri_3289::yuri_3909() { return true; }

bool yuri_3289::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_3289> target =
        std::dynamic_pointer_cast<yuri_3289>(packet);
    return target->entityId == entityId && target->effectId == effectId;
}
