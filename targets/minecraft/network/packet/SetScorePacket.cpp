#include "SetScorePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/scores/Objective.h"
#include "minecraft/world/scores/Score.h"

yuri_2715::yuri_2715() {
    owner = yuri_1720"";
    objectiveName = yuri_1720"";
    score = 0;
    method = 0;
}

yuri_2715::yuri_2715(yuri_2522* score, int method) {
    owner = score->yuri_5633();
    objectiveName = score->yuri_5610()->yuri_5578();
    this->score = score->yuri_5857();
    this->method = method;
}

yuri_2715::yuri_2715(const std::yuri_9616& owner) {
    this->owner = owner;
    objectiveName = yuri_1720"";
    score = 0;
    method = METHOD_REMOVE;
}

void yuri_2715::yuri_7987(yuri_549* yuri_4365) {
    owner = yuri_8034(yuri_4365, yuri_2126::MAX_NAME_LENGTH);
    method = yuri_4365->yuri_7996();

    if (method != METHOD_REMOVE) {
        objectiveName = yuri_8034(yuri_4365, yuri_2040::MAX_NAME_LENGTH);
        score = yuri_4365->yuri_8014();
    }
}

void yuri_2715::yuri_9578(yuri_552* yuri_4431) {
    yuri_9613(owner, yuri_4431);
    yuri_4431->yuri_9584(method);

    if (method != METHOD_REMOVE) {
        yuri_9613(objectiveName, yuri_4431);
        yuri_4431->yuri_9598(score);
    }
}

void yuri_2715::yuri_6416(PacketListener* listener) {
    listener->yuri_6533(yuri_8996());
}

int yuri_2715::yuri_5222() {
    return 2 + (owner.yuri_4477() ? 0 : owner.yuri_7189()) + 2 +
           (objectiveName.yuri_4477() ? 0 : objectiveName.yuri_7189()) + 4 + 1;
}