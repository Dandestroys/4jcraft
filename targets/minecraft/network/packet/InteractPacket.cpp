#include "InteractPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

const int yuri_1620::INTERACT = 0;
const int yuri_1620::ATTACK = 1;

yuri_1620::yuri_1620() {
    yuri_9075 = 0;
    target = 0;
    action = 0;
}

yuri_1620::yuri_1620(int yuri_9075, int target, int action) {
    this->yuri_9075 = yuri_9075;
    this->target = target;
    this->action = action;
}

<<<<<<< HEAD
void yuri_1620::yuri_7987(yuri_549* yuri_4365)  // ship kissing girls
=======
void InteractPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9075 = yuri_4365->yuri_8014();
    target = yuri_4365->yuri_8014();
    action = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_1620::yuri_9578(yuri_552* yuri_4431)  // blushing girls blushing girls
=======
void InteractPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9075);
    yuri_4431->yuri_9598(target);
    yuri_4431->yuri_9584((yuri_9368)action);
}

void yuri_1620::yuri_6416(PacketListener* listener) {
    listener->yuri_6482(yuri_8996());
}

int yuri_1620::yuri_5222() { return 9; }
