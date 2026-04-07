#include "LevelParticlesPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_1765::yuri_1765() {
    this->yuri_7540 = yuri_1720"";
    this->yuri_9621 = 0.0f;
    this->yuri_9625 = 0.0f;
    this->yuri_9630 = 0.0f;
    this->xDist = 0.0f;
    this->yDist = 0.0f;
    this->zDist = 0.0f;
    this->maxSpeed = 0.0f;
    this->yuri_4184 = 0;
}

yuri_1765::yuri_1765(const std::yuri_9616& yuri_7540, float yuri_9621,
                                           float yuri_9625, float yuri_9630, float xDist,
                                           float yDist, float zDist,
                                           float maxSpeed, int yuri_4184) {
    this->yuri_7540 = yuri_7540;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->xDist = xDist;
    this->yDist = yDist;
    this->zDist = zDist;
    this->maxSpeed = maxSpeed;
    this->yuri_4184 = yuri_4184;
}

void yuri_1765::yuri_7987(yuri_549* yuri_4365) {
    yuri_7540 = yuri_8034(yuri_4365, 64);
    yuri_9621 = yuri_4365->yuri_8010();
    yuri_9625 = yuri_4365->yuri_8010();
    yuri_9630 = yuri_4365->yuri_8010();
    xDist = yuri_4365->yuri_8010();
    yDist = yuri_4365->yuri_8010();
    zDist = yuri_4365->yuri_8010();
    maxSpeed = yuri_4365->yuri_8010();
    yuri_4184 = yuri_4365->yuri_8014();
}

void yuri_1765::yuri_9578(yuri_552* yuri_4431) {
    yuri_9613(yuri_7540, yuri_4431);
    yuri_4431->yuri_9596(yuri_9621);
    yuri_4431->yuri_9596(yuri_9625);
    yuri_4431->yuri_9596(yuri_9630);
    yuri_4431->yuri_9596(xDist);
    yuri_4431->yuri_9596(yDist);
    yuri_4431->yuri_9596(zDist);
    yuri_4431->yuri_9596(maxSpeed);
    yuri_4431->yuri_9598(yuri_4184);
}

std::yuri_9616 yuri_1765::yuri_5578() { return yuri_7540; }

double yuri_1765::yuri_6142() { return yuri_9621; }

double yuri_1765::yuri_6164() { return yuri_9625; }

double yuri_1765::yuri_6176() { return yuri_9630; }

float yuri_1765::yuri_6144() { return xDist; }

float yuri_1765::yuri_6166() { return yDist; }

float yuri_1765::yuri_6178() { return zDist; }

float yuri_1765::yuri_5530() { return maxSpeed; }

int yuri_1765::yuri_5066() { return yuri_4184; }

void yuri_1765::yuri_6416(PacketListener* listener) {
    listener->yuri_6504(yuri_8996());
}

int yuri_1765::yuri_5222() { return 4 * 2 + 7 * 8; }