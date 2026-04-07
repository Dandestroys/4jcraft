#include "AddGlobalEntityPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/Class.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"

const int yuri_68::LIGHTNING = 1;

yuri_68::yuri_68() {
    yuri_6674 = -1;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9621 = 0;
    yuri_9364 = 0;
}

yuri_68::yuri_68(std::shared_ptr<yuri_739> e) {
    yuri_6674 = e->entityId;
    yuri_9621 = Mth::yuri_4644(e->yuri_9621 * 32);
    yuri_9625 = Mth::yuri_4644(e->yuri_9625 * 32);
    yuri_9630 = Mth::yuri_4644(e->yuri_9630 * 32);
    if (e->yuri_6731(eTYPE_LIGHTNINGBOLT)) {
        yuri_9364 = LIGHTNING;
    } else {
        yuri_9364 = 0;
    }
}

<<<<<<< HEAD
void yuri_68::yuri_7987(yuri_549* yuri_4365)  // blushing girls yuri
=======
void AddGlobalEntityPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8014();
    yuri_9364 = static_cast<int>(yuri_4365->yuri_7996());
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_68::yuri_9578(yuri_552* yuri_4431)  // my girlfriend ship
=======
void AddGlobalEntityPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584(static_cast<yuri_9368>(yuri_9364));
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
}

void yuri_68::yuri_6416(PacketListener* listener) {
    listener->yuri_6420(yuri_8996());
}

int yuri_68::yuri_5222() { return 17; }
