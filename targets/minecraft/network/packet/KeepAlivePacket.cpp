#include "KeepAlivePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_1713::yuri_1713() { yuri_6674 = 0; }

yuri_1713::yuri_1713(int yuri_6674) { this->yuri_6674 = yuri_6674; }

void yuri_1713::yuri_6416(PacketListener* listener) {
    listener->yuri_6486(yuri_8996());
}

<<<<<<< HEAD
void yuri_1713::yuri_7987(yuri_549* yuri_4365)  // yuri FUCKING KISS ALREADY
=======
void KeepAlivePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_1713::yuri_9578(yuri_552* yuri_4431)  // girl love canon
=======
void KeepAlivePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_6674);
}

int yuri_1713::yuri_5222() { return 4; }

bool yuri_1713::yuri_3909() { return true; }

bool yuri_1713::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}

bool yuri_1713::yuri_6780() { return true; }