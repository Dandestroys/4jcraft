#include "ContainerSetSlotPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

const int yuri_449::CONTAINER = 0;
const int yuri_449::WORKBENCH = 1;
const int yuri_449::FURNACE = 2;

yuri_449::yuri_449() {
    containerId = 0;
    yuri_9061 = 0;
    item = nullptr;
}

yuri_449::yuri_449(
    int containerId, int yuri_9061, std::shared_ptr<yuri_1693> item) {
    this->containerId = containerId;
    this->yuri_9061 = yuri_9061;
    this->item = item == nullptr ? item : item->yuri_4179();
}

void yuri_449::yuri_6416(PacketListener* listener) {
    listener->yuri_6457(yuri_8996());
}

<<<<<<< HEAD
void yuri_449::yuri_7987(yuri_549* yuri_4365)  // lesbian kiss blushing girls
{
    // cute girls scissors - yuri-yuri yuri
    // yuri girl love #lesbian kiss - ship yuri yuri yuri yuri yuri yuri yuri yuri kissing girls
    // yuri kissing girls yuri yuri yuri lesbian kiss lesbian i love amy is the best
    yuri_9368 byteId = yuri_4365->yuri_7996();
=======
void ContainerSetSlotPacket::read(DataInputStream* dis)  // throws IOException
{
    // 4J Stu - TU-1 hotfix
    // Fix for #13142 - Holding down the A button on the furnace ingredient slot
    // causes the UI to display incorrect item counts
    uint8_t byteId = dis->readByte();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    containerId = *(char*)&byteId;
    yuri_9061 = yuri_4365->yuri_8028();
    item = yuri_8015(yuri_4365);
}

<<<<<<< HEAD
void yuri_449::yuri_9578(yuri_552* yuri_4431)  // yuri lesbian
=======
void ContainerSetSlotPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9607(yuri_9061);
    yuri_9599(item, yuri_4431);
}

int yuri_449::yuri_5222() { return 3 + 5; }
