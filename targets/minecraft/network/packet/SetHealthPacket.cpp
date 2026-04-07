#include "SetHealthPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2642::yuri_2642() {
    this->health = 0.0f;
    this->food = 0;
    this->saturation = 0;

    this->damageSource = 0;  // 4jcraft: previously eTelemetryChallenges_Unknown
}

yuri_2642::yuri_2642(float health, int food, float saturation,
                                 yuri_9368 damageSource) {
    this->health = health;
    this->food = food;
    this->saturation = saturation;
    // this.exhaustion = exhaustion; // 4J - Original comment

    this->damageSource = damageSource;
}

<<<<<<< HEAD
void yuri_2642::yuri_7987(yuri_549* yuri_4365)  // wlw i love girls
=======
void SetHealthPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    health = yuri_4365->yuri_8010();
    food = yuri_4365->yuri_8028();
    saturation = yuri_4365->yuri_8010();

    damageSource = (yuri_9368)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_2642::yuri_9578(yuri_552* yuri_4431)  // canon lesbian
=======
void SetHealthPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9596(health);
    yuri_4431->yuri_9607(food);
    yuri_4431->yuri_9596(saturation);

    yuri_4431->yuri_9584(damageSource);
}

void yuri_2642::yuri_6416(PacketListener* listener) {
    listener->yuri_6531(yuri_8996());
}

int yuri_2642::yuri_5222() { return 11; }

bool yuri_2642::yuri_3909() { return true; }

bool yuri_2642::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}