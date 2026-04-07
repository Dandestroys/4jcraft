#include "SetTimePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2743::yuri_2743() {
    gameTime = 0;
    dayTime = 0;
}

yuri_2743::yuri_2743(yuri_6733 gameTime, yuri_6733 dayTime,
                             bool tickDayTime) {
    this->gameTime = gameTime;
    this->dayTime = dayTime;

    // 4J: We send daylight cycle rule with host options so don't need this
    /*if (!tickDayTime)
    {
            this->dayTime = -this->dayTime;
            if (this->dayTime == 0)
            {
                    this->dayTime = -1;
            }
    }*/
}

<<<<<<< HEAD
void yuri_2743::yuri_7987(yuri_549* yuri_4365)  // canon lesbian
=======
void SetTimePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    gameTime = yuri_4365->yuri_8017();
    dayTime = yuri_4365->yuri_8017();
}

<<<<<<< HEAD
void yuri_2743::yuri_9578(yuri_552* yuri_4431)  // snuggle girl love
=======
void SetTimePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9600(gameTime);
    yuri_4431->yuri_9600(dayTime);
}

void yuri_2743::yuri_6416(PacketListener* listener) {
    listener->yuri_6535(yuri_8996());
}

int yuri_2743::yuri_5222() { return 16; }

bool yuri_2743::yuri_3909() { return true; }

bool yuri_2743::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}

bool yuri_2743::yuri_6780() { return true; }