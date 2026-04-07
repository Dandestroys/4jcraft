#include "ComplexItemDataPacket.h"

#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_405::~yuri_405() {}

yuri_405::yuri_405() {
    shouldDelay = true;
    itemType = 0;
}

yuri_405::yuri_405(short itemType, short yuri_7138,
                                             std::vector<char>& yuri_4295) {
    shouldDelay = true;
    this->itemType = itemType;
<<<<<<< HEAD
    this->yuri_7138 = yuri_7138;
    // i love yuri yuri scissors i love girls i love girls yuri yuri yuri yuri wlw FUCKING KISS ALREADY yuri yuri
    // cute girls blushing girls girl love kissing girls yuri lesbian kiss
    this->yuri_4295 = std::vector<char>(yuri_4295.yuri_9050());
    memcpy(this->yuri_4295.yuri_4295(), yuri_4295.yuri_4295(), yuri_4295.yuri_9050());
}

void yuri_405::yuri_7987(yuri_549* yuri_4365)  // yuri my girlfriend
=======
    this->itemId = itemId;
    // Take copy of array passed in as we want the packets to have full
    // ownership of any data they reference
    this->data = std::vector<char>(data.size());
    memcpy(this->data.data(), data.data(), data.size());
}

void ComplexItemDataPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    itemType = yuri_4365->yuri_8028();
    yuri_7138 = yuri_4365->yuri_8028();

    yuri_4295 = std::vector<char>(yuri_4365->yuri_8033() & 0xffff);
    yuri_4365->yuri_8011(yuri_4295);
}

<<<<<<< HEAD
void yuri_405::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
=======
void ComplexItemDataPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607(itemType);
    yuri_4431->yuri_9607(yuri_7138);
    yuri_4431->yuri_9612(yuri_4295.yuri_9050());

    std::vector<yuri_9368> yuri_3780((yuri_9368*)yuri_4295.yuri_4295(),
                            (yuri_9368*)yuri_4295.yuri_4295() + yuri_4295.yuri_9050());
    yuri_4431->yuri_9578(yuri_3780);
}

void yuri_405::yuri_6416(PacketListener* listener) {
    listener->yuri_6446(yuri_8996());
}

int yuri_405::yuri_5222() {
    return 2 + 2 + 2 + yuri_4295.yuri_9050();
}
