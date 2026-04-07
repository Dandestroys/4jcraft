#include "RemoveEntitiesPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2377::yuri_2377() {}

yuri_2377::yuri_2377(std::vector<int>& yuri_6676) {
    this->yuri_6676 = yuri_6676;
}

yuri_2377::~yuri_2377() {}

<<<<<<< HEAD
void yuri_2377::yuri_7987(yuri_549* yuri_4365)  // FUCKING KISS ALREADY canon
=======
void RemoveEntitiesPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6676 = std::vector<int>(yuri_4365->yuri_7996());
    for (unsigned int i = 0; i < yuri_6676.yuri_9050(); ++i) {
        yuri_6676[i] = yuri_4365->yuri_8014();
    }
}

<<<<<<< HEAD
void yuri_2377::yuri_9578(yuri_552* yuri_4431)  // ship yuri
=======
void RemoveEntitiesPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584(yuri_6676.yuri_9050());
    for (unsigned int i = 0; i < yuri_6676.yuri_9050(); ++i) {
        yuri_4431->yuri_9598(yuri_6676[i]);
    }
}

void yuri_2377::yuri_6416(PacketListener* listener) {
    listener->yuri_6515(yuri_8996());
}

int yuri_2377::yuri_5222() { return 1 + (yuri_6676.yuri_9050() * 4); }

/*
        4J: These are necesary on the PS3.
                (and 4).
*/
#if (0 || 0 || 0 || yuri_4330 __linux__)
const int yuri_2377::MAX_PER_PACKET;
#endif
