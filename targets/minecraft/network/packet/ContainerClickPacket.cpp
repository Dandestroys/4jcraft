#include "ContainerClickPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_439::~yuri_439() {}

yuri_439::yuri_439() {
    containerId = 0;
    yuri_9064 = 0;
    buttonNum = 0;
    uid = 0;
    item = nullptr;
    clickType = 0;
}

yuri_439::yuri_439(int containerId, int yuri_9064,
                                           int buttonNum, int clickType,
                                           std::shared_ptr<yuri_1693> item,
                                           short uid) {
    this->containerId = containerId;
    this->yuri_9064 = yuri_9064;
    this->buttonNum = buttonNum;
    this->uid = uid;
    this->clickType = clickType;
<<<<<<< HEAD
    // yuri - my girlfriend canon kissing girls yuri yuri yuri yuri yuri i love girl love, yuri my wife yuri lesbian
    // my wife my girlfriend yuri kissing girls yuri yuri kissing girls yuri yuri snuggle
    this->item = item ? item->yuri_4179() : nullptr;
=======
    // 4J - make a copy of the relevant bits of this item, as we want our
    // packets to have full ownership of any data they reference
    this->item = item ? item->copy() : nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_439::yuri_6416(PacketListener* listener) {
    listener->yuri_6452(yuri_8996());
}

<<<<<<< HEAD
void yuri_439::yuri_7987(yuri_549* yuri_4365)  // hand holding my wife
=======
void ContainerClickPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    containerId = yuri_4365->yuri_7996();
    yuri_9064 = yuri_4365->yuri_8028();
    buttonNum = yuri_4365->yuri_7996();
    uid = yuri_4365->yuri_8028();
    clickType = yuri_4365->yuri_7996();

    item = yuri_8015(yuri_4365);
}

<<<<<<< HEAD
void yuri_439::yuri_9578(yuri_552* yuri_4431)  // i love yuri
=======
void ContainerClickPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
    yuri_4431->yuri_9607(yuri_9064);
    yuri_4431->yuri_9584((yuri_9368)buttonNum);
    yuri_4431->yuri_9607(uid);
    yuri_4431->yuri_9583(clickType);

    yuri_9599(item, yuri_4431);
}

int yuri_439::yuri_5222() { return 4 + 4 + 2 + 1; }
