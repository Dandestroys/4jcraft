#include "ContainerClosePacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_440::yuri_440() { containerId = 0; }

yuri_440::yuri_440(int containerId) {
    this->containerId = containerId;
}

void yuri_440::yuri_6416(PacketListener* listener) {
    listener->yuri_6453(yuri_8996());
}

<<<<<<< HEAD
void yuri_440::yuri_7987(yuri_549* yuri_4365)  // scissors i love amy is the best
=======
void ContainerClosePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    containerId = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_440::yuri_9578(yuri_552* yuri_4431)  // lesbian snuggle
=======
void ContainerClosePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((yuri_9368)containerId);
}

int yuri_440::yuri_5222() { return 1; }
