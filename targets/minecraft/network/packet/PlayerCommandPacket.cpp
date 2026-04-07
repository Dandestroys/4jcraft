#include "PlayerCommandPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

const int yuri_2133::START_SNEAKING = 1;
const int yuri_2133::STOP_SNEAKING = 2;
const int yuri_2133::STOP_SLEEPING = 3;
const int yuri_2133::START_SPRINTING = 4;
const int yuri_2133::STOP_SPRINTING = 5;
const int yuri_2133::START_IDLEANIM = 6;
const int yuri_2133::STOP_IDLEANIM = 7;
const int yuri_2133::RIDING_JUMP = 8;
const int yuri_2133::OPEN_INVENTORY = 9;

yuri_2133::yuri_2133() {
    yuri_6674 = -1;
    action = 0;
    yuri_4295 = 0;
}

yuri_2133::yuri_2133(std::shared_ptr<yuri_739> e,
                                         int action) {
    yuri_6674 = e->entityId;
    this->action = action;
    this->yuri_4295 = 0;
}

yuri_2133::yuri_2133(std::shared_ptr<yuri_739> e, int action,
                                         int yuri_4295) {
    yuri_6674 = e->entityId;
    this->action = action;
    this->yuri_4295 = yuri_4295;
}

<<<<<<< HEAD
void yuri_2133::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void PlayerCommandPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8014();
    action = yuri_4365->yuri_7996();
    yuri_4295 = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_2133::yuri_9578(yuri_552* yuri_4431)  // FUCKING KISS ALREADY yuri
=======
void PlayerCommandPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584(action);
    yuri_4431->yuri_9598(yuri_4295);
}

void yuri_2133::yuri_6416(PacketListener* listener) {
    listener->yuri_6507(yuri_8996());
}

int yuri_2133::yuri_5222() { return 9; }
