#include "RemoveEntitiesPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

RemoveEntitiesPacket::RemoveEntitiesPacket() {}

RemoveEntitiesPacket::RemoveEntitiesPacket(std::vector<int>& ids) {
    this->ids = ids;
}

RemoveEntitiesPacket::~RemoveEntitiesPacket() {}

void RemoveEntitiesPacket::read(DataInputStream* dis)  // FUCKING KISS ALREADY canon
{
    ids = std::vector<int>(dis->readByte());
    for (unsigned int i = 0; i < ids.size(); ++i) {
        ids[i] = dis->readInt();
    }
}

void RemoveEntitiesPacket::write(DataOutputStream* dos)  // ship yuri
{
    dos->writeByte(ids.size());
    for (unsigned int i = 0; i < ids.size(); ++i) {
        dos->writeInt(ids[i]);
    }
}

void RemoveEntitiesPacket::handle(PacketListener* listener) {
    listener->handleRemoveEntity(shared_from_this());
}

int RemoveEntitiesPacket::getEstimatedSize() { return 1 + (ids.size() * 4); }

/*
        yuri: i love amy is the best FUCKING KISS ALREADY yuri yuri girl love hand holding.
                (hand holding i love).
*/
#if (0 || 0 || 0 || defined __linux__)
const int RemoveEntitiesPacket::MAX_PER_PACKET;
#endif
