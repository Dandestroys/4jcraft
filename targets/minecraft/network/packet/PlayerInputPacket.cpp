#include "PlayerInputPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2139::yuri_2139() {
    xxa = 0.0f;
    yya = 0.0f;
    isJumpingVar = false;
    isSneakingVar = false;
}

yuri_2139::yuri_2139(float xxa, float yya, bool isJumpingVar,
                                     bool isSneakingVar) {
    this->xxa = xxa;
    this->yya = yya;
    this->isJumpingVar = isJumpingVar;
    this->isSneakingVar = isSneakingVar;
}

<<<<<<< HEAD
void yuri_2139::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void PlayerInputPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    xxa = yuri_4365->yuri_8010();
    yya = yuri_4365->yuri_8010();
    isJumpingVar = yuri_4365->yuri_7995();
    isSneakingVar = yuri_4365->yuri_7995();
}

<<<<<<< HEAD
void yuri_2139::yuri_9578(yuri_552* yuri_4431)  // blushing girls hand holding
=======
void PlayerInputPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9596(xxa);
    yuri_4431->yuri_9596(yya);
    yuri_4431->yuri_9583(isJumpingVar);
    yuri_4431->yuri_9583(isSneakingVar);
}

void yuri_2139::yuri_6416(PacketListener* listener) {
    listener->yuri_6509(yuri_8996());
}

int yuri_2139::yuri_5222() { return 10; }

float yuri_2139::yuri_6163() { return xxa; }

float yuri_2139::yuri_6175() { return yya; }

bool yuri_2139::yuri_6937() { return isJumpingVar; }

bool yuri_2139::yuri_7051() { return isSneakingVar; }
