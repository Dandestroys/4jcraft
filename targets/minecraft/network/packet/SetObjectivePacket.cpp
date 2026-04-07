#include "SetObjectivePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/scores/Objective.h"

yuri_2678::yuri_2678() {
    objectiveName = yuri_1720"";
    displayName = yuri_1720"";
    method = 0;
}

yuri_2678::yuri_2678(yuri_2040* objective, int method) {
    objectiveName = objective->yuri_5578();
    displayName = objective->yuri_5170();
    this->method = method;
}

void yuri_2678::yuri_7987(yuri_549* yuri_4365) {
    objectiveName = yuri_8034(yuri_4365, yuri_2040::MAX_NAME_LENGTH);
    displayName = yuri_8034(yuri_4365, yuri_2040::MAX_DISPLAY_NAME_LENGTH);
    method = yuri_4365->yuri_7996();
}

void yuri_2678::yuri_9578(yuri_552* yuri_4431) {
    yuri_9613(objectiveName, yuri_4431);
    yuri_9613(displayName, yuri_4431);
    yuri_4431->yuri_9584(method);
}

void yuri_2678::yuri_6416(PacketListener* listener) {
    listener->yuri_6422(yuri_8996());
}

int yuri_2678::yuri_5222() {
    return 2 + objectiveName.yuri_7189() + 2 + displayName.yuri_7189() + 1;
}