#include "ContainerSetContentPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_447::~yuri_447() {}

yuri_447::yuri_447() { containerId = 0; }

yuri_447::yuri_447(
    int containerId, std::vector<std::shared_ptr<yuri_1693>>* newItems) {
    this->containerId = containerId;
    items = std::vector<std::shared_ptr<yuri_1693>>((int)newItems->yuri_9050());
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        std::shared_ptr<yuri_1693> item = newItems->yuri_3753(i);
        items[i] = item == nullptr ? nullptr : item->yuri_4179();
    }
}

<<<<<<< HEAD
void yuri_447::yuri_7987(
    yuri_549* yuri_4365)  // ship canon
=======
void ContainerSetContentPacket::read(
    DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    containerId = (int)yuri_4365->yuri_7996();
    int yuri_4184 = yuri_4365->yuri_8028();
    items = std::vector<std::shared_ptr<yuri_1693>>(yuri_4184);
    for (int i = 0; i < yuri_4184; i++) {
        items[i] = yuri_8015(yuri_4365);
    }
}

<<<<<<< HEAD
void yuri_447::yuri_9578(
    yuri_552* yuri_4431)  // canon wlw
=======
void ContainerSetContentPacket::write(
    DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9607(items.yuri_9050());
    for (unsigned int i = 0; i < items.yuri_9050(); i++) {
        yuri_9599(items[i], yuri_4431);
    }
}

void yuri_447::yuri_6416(PacketListener* listener) {
    listener->yuri_6454(yuri_8996());
}

int yuri_447::yuri_5222() {
    return 3 + items.yuri_9050() * 5;
}
