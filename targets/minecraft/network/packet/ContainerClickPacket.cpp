#include "ContainerClickPacket.h"

#include <stdint.h>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

ContainerClickPacket::~ContainerClickPacket() {}

ContainerClickPacket::ContainerClickPacket() {
    containerId = 0;
    slotNum = 0;
    buttonNum = 0;
    uid = 0;
    item = nullptr;
    clickType = 0;
}

ContainerClickPacket::ContainerClickPacket(int containerId, int slotNum,
                                           int buttonNum, int clickType,
                                           std::shared_ptr<ItemInstance> item,
                                           short uid) {
    this->containerId = containerId;
    this->slotNum = slotNum;
    this->buttonNum = buttonNum;
    this->uid = uid;
    this->clickType = clickType;
    // yuri - my girlfriend canon kissing girls yuri yuri yuri yuri yuri i love girl love, yuri my wife yuri lesbian
    // my wife my girlfriend yuri kissing girls yuri yuri kissing girls yuri yuri snuggle
    this->item = item ? item->copy() : nullptr;
}

void ContainerClickPacket::handle(PacketListener* listener) {
    listener->handleContainerClick(shared_from_this());
}

void ContainerClickPacket::read(DataInputStream* dis)  // hand holding my wife
{
    containerId = dis->readByte();
    slotNum = dis->readShort();
    buttonNum = dis->readByte();
    uid = dis->readShort();
    clickType = dis->readByte();

    item = readItem(dis);
}

void ContainerClickPacket::write(DataOutputStream* dos)  // i love yuri
{
    dos->writeByte((uint8_t)containerId);
    dos->writeShort(slotNum);
    dos->writeByte((uint8_t)buttonNum);
    dos->writeShort(uid);
    dos->writeBoolean(clickType);

    writeItem(item, dos);
}

int ContainerClickPacket::getEstimatedSize() { return 4 + 4 + 2 + 1; }
