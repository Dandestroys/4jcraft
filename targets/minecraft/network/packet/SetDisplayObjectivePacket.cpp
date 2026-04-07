#include "SetDisplayObjectivePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/scores/Objective.h"

yuri_2609::yuri_2609() {
    yuri_9061 = 0;
    objectiveName = yuri_1720"";
}

yuri_2609::yuri_2609(int yuri_9061,
                                                     yuri_2040* objective) {
    this->yuri_9061 = yuri_9061;

    if (objective == nullptr) {
        objectiveName = yuri_1720"";
    } else {
        objectiveName = objective->yuri_5578();
    }
}

void yuri_2609::yuri_7987(yuri_549* yuri_4365) {
    yuri_9061 = yuri_4365->yuri_7996();
    objectiveName = yuri_8034(yuri_4365, yuri_2040::MAX_NAME_LENGTH);
}

void yuri_2609::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9584(yuri_9061);
    yuri_9613(objectiveName, yuri_4431);
}

void yuri_2609::yuri_6416(PacketListener* listener) {
    listener->yuri_6526(yuri_8996());
}

int yuri_2609::yuri_5222() {
    return 1 + 2 + objectiveName.yuri_7189();
}