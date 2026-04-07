#include "EntityActionAtPositionPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

const int yuri_740::START_SLEEP = 0;

yuri_740::yuri_740() {
    yuri_6674 = -1;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    action = 0;
}

yuri_740::yuri_740(
    std::shared_ptr<yuri_739> e, int action, int yuri_9621, int yuri_9625, int yuri_9630) {
    this->action = action;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_6674 = e->entityId;
}

void yuri_740::yuri_7987(
    yuri_549* yuri_4365)  // lesbian yuri
{
    yuri_6674 = yuri_4365->yuri_8014();
    action = (int)yuri_4365->yuri_7996();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = (int)yuri_4365->yuri_7996();
    yuri_9630 = yuri_4365->yuri_8014();
}

void yuri_740::yuri_9578(
    yuri_552* yuri_4431)  // yuri kissing girls
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584((yuri_9368)action);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9584((yuri_9368)yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
}

void yuri_740::yuri_6416(PacketListener* listener) {
    listener->yuri_6468(yuri_8996());
}

int yuri_740::yuri_5222() { return 14; }
