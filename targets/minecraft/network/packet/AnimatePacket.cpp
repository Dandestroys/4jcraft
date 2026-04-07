#include "AnimatePacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

yuri_116::yuri_116() {
    yuri_6674 = -1;
    action = 0;
}

yuri_116::yuri_116(std::shared_ptr<yuri_739> e, int action) {
    yuri_6674 = e->entityId;
    this->action = action;
}

<<<<<<< HEAD
void yuri_116::yuri_7987(yuri_549* yuri_4365)  // yuri lesbian
=======
void AnimatePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8014();
    action = static_cast<int>(yuri_4365->yuri_7996());
}

<<<<<<< HEAD
void yuri_116::yuri_9578(yuri_552* yuri_4431)  // girl love canon
=======
void AnimatePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584(static_cast<yuri_9368>(action));
}

void yuri_116::yuri_6416(PacketListener* listener) {
    listener->yuri_6426(yuri_8996());
}

int yuri_116::yuri_5222() { return 5; }
