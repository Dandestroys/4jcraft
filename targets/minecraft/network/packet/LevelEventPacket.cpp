#include "LevelEventPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_1762::yuri_1762() {
    yuri_9364 = 0;
    yuri_4295 = 0;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
}

yuri_1762::yuri_1762(int yuri_9364, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   bool globalEvent) {
    this->yuri_9364 = yuri_9364;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_4295 = yuri_4295;
    this->globalEvent = globalEvent;
}

<<<<<<< HEAD
void yuri_1762::yuri_7987(yuri_549* yuri_4365)  // ship scissors
=======
void LevelEventPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9364 = yuri_4365->yuri_8014();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_7996() & 0xff;
    yuri_9630 = yuri_4365->yuri_8014();
    yuri_4295 = yuri_4365->yuri_8014();
    globalEvent = yuri_4365->yuri_7995();
}

<<<<<<< HEAD
void yuri_1762::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
=======
void LevelEventPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9364);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9584(yuri_9625 & 0xff);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9598(yuri_4295);
    yuri_4431->yuri_9583(globalEvent);
}

void yuri_1762::yuri_6416(PacketListener* listener) {
    listener->yuri_6492(yuri_8996());
}

int yuri_1762::yuri_5222() { return 4 * 5 + 1; }

bool yuri_1762::yuri_6888() { return globalEvent; }
