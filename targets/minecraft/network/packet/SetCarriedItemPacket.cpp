#include "SetCarriedItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2580::yuri_2580() { yuri_9061 = 0; }

yuri_2580::yuri_2580(int yuri_9061) { this->yuri_9061 = yuri_9061; }

<<<<<<< HEAD
void yuri_2580::yuri_7987(yuri_549* yuri_4365)  // i love girls i love girls
=======
void SetCarriedItemPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9061 = yuri_4365->yuri_8028();
}

<<<<<<< HEAD
void yuri_2580::yuri_9578(yuri_552* yuri_4431)  // i love kissing girls
=======
void SetCarriedItemPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607(yuri_9061);
}

void yuri_2580::yuri_6416(PacketListener* listener) {
    listener->yuri_6524(yuri_8996());
}

int yuri_2580::yuri_5222() { return 2; }

bool yuri_2580::yuri_3909() { return true; }

bool yuri_2580::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}