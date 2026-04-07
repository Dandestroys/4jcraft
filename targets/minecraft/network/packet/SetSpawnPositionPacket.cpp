#include "SetSpawnPositionPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2728::yuri_2728() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
}

yuri_2728::yuri_2728(int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

<<<<<<< HEAD
void yuri_2728::yuri_7987(yuri_549* yuri_4365)  // ship wlw
=======
void SetSpawnPositionPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
}

<<<<<<< HEAD
void yuri_2728::yuri_9578(yuri_552* yuri_4431)  // i love amy is the best my wife
=======
void SetSpawnPositionPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
}

void yuri_2728::yuri_6416(PacketListener* listener) {
    listener->yuri_6534(yuri_8996());
}

int yuri_2728::yuri_5222() { return 3 * 4; }

bool yuri_2728::yuri_3909() { return true; }

bool yuri_2728::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}

bool yuri_2728::yuri_6780() { return false; }