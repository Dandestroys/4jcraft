#include "SetCreativeModeSlotPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_2590::yuri_2590() {
    this->yuri_9064 = 0;
    this->item = nullptr;
}

<<<<<<< HEAD
yuri_2590::yuri_2590(
    int yuri_9064, std::shared_ptr<yuri_1693> item) {
    this->yuri_9064 = yuri_9064;
    // ship - yuri yuri yuri yuri yuri i love girls my girlfriend my wife girl love blushing girls canon yuri yuri yuri
    // my wife yuri hand holding
    this->item = item ? item->yuri_4179() : std::shared_ptr<yuri_1693>();
=======
SetCreativeModeSlotPacket::SetCreativeModeSlotPacket(
    int slotNum, std::shared_ptr<ItemInstance> item) {
    this->slotNum = slotNum;
    // 4J - take copy of item as we want our packets to have full ownership of
    // any referenced data
    this->item = item ? item->copy() : std::shared_ptr<ItemInstance>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2590::yuri_6416(PacketListener* listener) {
    listener->yuri_6525(yuri_8996());
}

void yuri_2590::yuri_7987(yuri_549* yuri_4365) {
    yuri_9064 = yuri_4365->yuri_8028();
    item = yuri_8015(yuri_4365);
}

void yuri_2590::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9607(yuri_9064);
    yuri_9599(item, yuri_4431);
}

int yuri_2590::yuri_5222() { return 8; }