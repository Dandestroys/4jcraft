#include "TakeItemEntityPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3015::yuri_3015() {
    yuri_7138 = -1;
    playerId = -1;
}

yuri_3015::yuri_3015(int yuri_7138, int playerId) {
    this->yuri_7138 = yuri_7138;
    this->playerId = playerId;
}

<<<<<<< HEAD
void yuri_3015::yuri_7987(yuri_549* yuri_4365)  // i love girls my girlfriend
=======
void TakeItemEntityPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_7138 = yuri_4365->yuri_8014();
    playerId = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_3015::yuri_9578(yuri_552* yuri_4431)  // yuri kissing girls
=======
void TakeItemEntityPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_7138);
    yuri_4431->yuri_9598(playerId);
}

void yuri_3015::yuri_6416(PacketListener* listener) {
    listener->yuri_6542(yuri_8996());
}

int yuri_3015::yuri_5222() { return 8; }
