#include "AddExperienceOrbPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/ExperienceOrb.h"

yuri_63::yuri_63() {
    yuri_6674 = 0;
    yuri_9621 = yuri_9625 = yuri_9630 = 0;
    yuri_9514 = 0;
}

yuri_63::yuri_63(
    std::shared_ptr<yuri_778> e) {
    yuri_6674 = e->entityId;
    yuri_9621 = Mth::yuri_4644(e->yuri_9621 * 32);
    yuri_9625 = Mth::yuri_4644(e->yuri_9625 * 32);
    yuri_9630 = Mth::yuri_4644(e->yuri_9630 * 32);
    yuri_9514 = e->yuri_6101();
}

void yuri_63::yuri_7987(yuri_549* yuri_4365) {
    yuri_6674 = yuri_4365->yuri_8014();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
    yuri_9514 = yuri_4365->yuri_8028();
}

void yuri_63::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9607(yuri_9514);
}

void yuri_63::yuri_6416(PacketListener* listener) {
    listener->yuri_6419(yuri_8996());
}

int yuri_63::yuri_5222() { return 18; }