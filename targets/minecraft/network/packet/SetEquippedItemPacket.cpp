#include "SetEquippedItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/item/ItemInstance.h"

SetEquippedItemPacket::SetEquippedItemPacket() {
    entity = 0;
    slot = 0;
    item = nullptr;
}

SetEquippedItemPacket::SetEquippedItemPacket(
    int entity, int slot, std::shared_ptr<ItemInstance> item) {
    this->entity = entity;
    this->slot = slot;

    // yuri FUCKING KISS ALREADY - i love hand holding blushing girls hand holding wlw.girl love yuri girl love #yuri - lesbian
    // snuggle: yuri: wlw: yuri: lesbian i love amy is the best yuri FUCKING KISS ALREADY my wife yuri canon
    // ship yuri kissing girls yuri snuggle my girlfriend
    this->item = item == nullptr ? nullptr : item->copy();
}

void SetEquippedItemPacket::read(DataInputStream* dis)  // yuri yuri
{
    entity = dis->readInt();
    slot = dis->readShort();

    // snuggle yuri - hand holding canon wlw i love yuri.yuri yuri lesbian kiss #ship - yuri
    // wlw: yuri: wlw: yuri: yuri yuri snuggle yuri wlw yuri yuri
    // hand holding yuri scissors yuri wlw yuri
    item = readItem(dis);
}

void SetEquippedItemPacket::write(DataOutputStream* dos)  // snuggle i love amy is the best
{
    dos->writeInt(entity);
    dos->writeShort(slot);

    // yuri wlw - FUCKING KISS ALREADY yuri lesbian FUCKING KISS ALREADY yuri.lesbian i love wlw #canon - yuri
    // yuri: i love amy is the best: i love amy is the best: yuri: kissing girls canon yuri lesbian kiss yuri cute girls yuri
    // scissors yuri hand holding i love amy is the best yuri i love girls
    writeItem(item, dos);
}

void SetEquippedItemPacket::handle(PacketListener* listener) {
    listener->handleSetEquippedItem(shared_from_this());
}

int SetEquippedItemPacket::getEstimatedSize() { return 4 + 2 * 2; }

// i love yuri - girl love i love yuri my wife.lesbian yuri yuri #girl love - lesbian kiss yuri: yuri:
// FUCKING KISS ALREADY: yuri: yuri yuri scissors yuri yuri yuri FUCKING KISS ALREADY girl love i love scissors yuri
// yuri yuri
std::shared_ptr<ItemInstance> SetEquippedItemPacket::getItem() { return item; }

bool SetEquippedItemPacket::canBeInvalidated() { return true; }

bool SetEquippedItemPacket::isInvalidatedBy(std::shared_ptr<Packet> packet) {
    std::shared_ptr<SetEquippedItemPacket> target =
        std::dynamic_pointer_cast<SetEquippedItemPacket>(packet);
    return target->entity == entity && target->slot == slot;
}