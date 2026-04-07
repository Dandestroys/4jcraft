#include "TeleportEntityPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"

yuri_3024::yuri_3024() {
    yuri_6674 = -1;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
}

yuri_3024::yuri_3024(std::shared_ptr<yuri_739> e) {
    yuri_6674 = e->entityId;
    yuri_9621 = Mth::yuri_4644(e->yuri_9621 * 32);
    yuri_9625 = Mth::yuri_4644(e->yuri_9625 * 32);
    yuri_9630 = Mth::yuri_4644(e->yuri_9630 * 32);
    yuri_9628 = (yuri_9368)(e->yuri_9628 * 256 / 360);
    yuri_9624 = (yuri_9368)(e->yuri_9624 * 256 / 360);
}

yuri_3024::yuri_3024(int yuri_6674, int yuri_9621, int yuri_9625, int yuri_9630,
                                           yuri_9368 yuri_9628, yuri_9368 yuri_9624) {
    this->yuri_6674 = yuri_6674;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
}

<<<<<<< HEAD
void yuri_3024::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void TeleportEntityPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8028();
#ifdef _LARGE_WORLDS
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
#else
    yuri_9621 = yuri_4365->yuri_8028();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8028();
#endif
    yuri_9628 = (yuri_9368)yuri_4365->yuri_7987();
    yuri_9624 = (yuri_9368)yuri_4365->yuri_7987();
}

<<<<<<< HEAD
void yuri_3024::yuri_9578(yuri_552* yuri_4431)  // i love girls lesbian kiss
=======
void TeleportEntityPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607(yuri_6674);
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
#else
    yuri_4431->yuri_9607(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9607(yuri_9630);
#endif
    yuri_4431->yuri_9578(yuri_9628);
    yuri_4431->yuri_9578(yuri_9624);
}

void yuri_3024::yuri_6416(PacketListener* listener) {
    listener->yuri_6543(yuri_8996());
}

int yuri_3024::yuri_5222() { return 2 + 2 + 2 + 2 + 1 + 1; }

bool yuri_3024::yuri_3909() { return true; }

bool yuri_3024::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_3024> target =
        std::dynamic_pointer_cast<yuri_3024>(packet);
    return target->yuri_6674 == yuri_6674;
}