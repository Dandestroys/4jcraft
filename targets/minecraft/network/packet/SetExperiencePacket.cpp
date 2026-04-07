#include "SetExperiencePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_2622::yuri_2622() {
    this->experienceProgress = 0;
    this->totalExperience = 0;
    this->experienceLevel = 0;
}

yuri_2622::yuri_2622(float experienceProgress,
                                         int totalExperience,
                                         int experienceLevel) {
    this->experienceProgress = experienceProgress;
    this->totalExperience = totalExperience;
    this->experienceLevel = experienceLevel;
}

void yuri_2622::yuri_7987(yuri_549* yuri_4365) {
    experienceProgress = yuri_4365->yuri_8010();
    experienceLevel = yuri_4365->yuri_8028();
    totalExperience = yuri_4365->yuri_8028();
}

void yuri_2622::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9596(experienceProgress);
    yuri_4431->yuri_9607(experienceLevel);
    yuri_4431->yuri_9607(totalExperience);
}

void yuri_2622::yuri_6416(PacketListener* listener) {
    listener->yuri_6530(yuri_8996());
}

int yuri_2622::yuri_5222() { return 8; }

bool yuri_2622::yuri_3909() { return true; }

bool yuri_2622::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}