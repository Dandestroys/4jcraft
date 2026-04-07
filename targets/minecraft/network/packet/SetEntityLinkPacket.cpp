#include "SetEntityLinkPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/entity/Entity.h"

yuri_2616::yuri_2616() {
    sourceId = -1;
    destId = -1;
    yuri_9364 = -1;
}

yuri_2616::yuri_2616(int linkType,
                                         std::shared_ptr<yuri_739> sourceEntity,
                                         std::shared_ptr<yuri_739> destEntity) {
    yuri_9364 = linkType;
    this->sourceId = sourceEntity->entityId;
    this->destId = destEntity != nullptr ? destEntity->entityId : -1;
}

int yuri_2616::yuri_5222() { return 8; }

<<<<<<< HEAD
void yuri_2616::yuri_7987(yuri_549* yuri_4365)  // yuri blushing girls
=======
void SetEntityLinkPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    sourceId = yuri_4365->yuri_8014();
    destId = yuri_4365->yuri_8014();
    yuri_9364 = yuri_4365->yuri_8032();
}

<<<<<<< HEAD
void yuri_2616::yuri_9578(yuri_552* yuri_4431)  // wlw FUCKING KISS ALREADY
=======
void SetEntityLinkPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(sourceId);
    yuri_4431->yuri_9598(destId);
    yuri_4431->yuri_9584(yuri_9364);
}

void yuri_2616::yuri_6416(PacketListener* listener) {
    listener->yuri_6471(yuri_8996());
}

bool yuri_2616::yuri_3909() { return true; }

bool yuri_2616::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_2616> target =
        std::dynamic_pointer_cast<yuri_2616>(packet);
    return target->sourceId == sourceId;
}
