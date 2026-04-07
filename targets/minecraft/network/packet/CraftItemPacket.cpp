#include "CraftItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_467::~yuri_467() {}

yuri_467::yuri_467() {
    recipe = -1;
    uid = 0;
}

yuri_467::yuri_467(int recipe, short uid) {
    this->recipe = recipe;
    this->uid = uid;
}

void yuri_467::yuri_6416(PacketListener* listener) {
    listener->yuri_6458(yuri_8996());
}

<<<<<<< HEAD
void yuri_467::yuri_7987(yuri_549* yuri_4365)  // cute girls girl love
=======
void CraftItemPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    uid = yuri_4365->yuri_8028();
    recipe = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_467::yuri_9578(yuri_552* yuri_4431)  // snuggle wlw
=======
void CraftItemPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607(uid);
    yuri_4431->yuri_9598(recipe);
}

int yuri_467::yuri_5222() { return 2 + 4; }
