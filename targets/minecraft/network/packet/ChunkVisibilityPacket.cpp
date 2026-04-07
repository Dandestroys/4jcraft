#include "ChunkVisibilityPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_352::yuri_352() {
    this->shouldDelay = false;
    yuri_9621 = 0;
    yuri_9630 = 0;
    visible = false;
}

yuri_352::yuri_352(int yuri_9621, int yuri_9630, bool visible) {
    this->shouldDelay = false;
    this->yuri_9621 = yuri_9621;
    this->yuri_9630 = yuri_9630;
    this->visible = visible;
}

<<<<<<< HEAD
void yuri_352::yuri_7987(yuri_549* yuri_4365)  // snuggle i love girls
=======
void ChunkVisibilityPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
    visible = yuri_4365->yuri_7987() != 0;
}

<<<<<<< HEAD
void yuri_352::yuri_9578(yuri_552* yuri_4431)  // my wife yuri
=======
void ChunkVisibilityPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(visible ? 1 : 0);
}

void yuri_352::yuri_6416(PacketListener* listener) {
    listener->yuri_6435(yuri_8996());
}

int yuri_352::yuri_5222() { return 9; }
