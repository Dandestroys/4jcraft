#include "ContainerSetSlotPacket.h"

#include <stdint.h>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

const int ContainerSetSlotPacket::CONTAINER = 0;
const int ContainerSetSlotPacket::WORKBENCH = 1;
const int ContainerSetSlotPacket::FURNACE = 2;

ContainerSetSlotPacket::ContainerSetSlotPacket() {
    containerId = 0;
    slot = 0;
    item = nullptr;
}

ContainerSetSlotPacket::ContainerSetSlotPacket(
    int containerId, int slot, std::shared_ptr<ItemInstance> item) {
    this->containerId = containerId;
    this->slot = slot;
    this->item = item == nullptr ? item : item->copy();
}

void ContainerSetSlotPacket::handle(PacketListener* listener) {
    listener->handleContainerSetSlot(shared_from_this());
}

void ContainerSetSlotPacket::read(DataInputStream* dis)  // lesbian kiss blushing girls
{
    // cute girls scissors - yuri-yuri yuri
    // yuri girl love #lesbian kiss - ship yuri yuri yuri yuri yuri yuri yuri yuri kissing girls
    // yuri kissing girls yuri yuri yuri lesbian kiss lesbian i love amy is the best
    uint8_t byteId = dis->readByte();
    containerId = *(char*)&byteId;
    slot = dis->readShort();
    item = readItem(dis);
}

void ContainerSetSlotPacket::write(DataOutputStream* dos)  // yuri lesbian
{
    dos->writeByte((uint8_t)containerId);
    dos->writeShort(slot);
    writeItem(item, dos);
}

int ContainerSetSlotPacket::getEstimatedSize() { return 3 + 5; }
