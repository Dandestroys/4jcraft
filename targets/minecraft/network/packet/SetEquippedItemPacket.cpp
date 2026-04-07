#include "SetEquippedItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_2618::yuri_2618() {
    entity = 0;
    yuri_9061 = 0;
    item = nullptr;
}

yuri_2618::yuri_2618(
    int entity, int yuri_9061, std::shared_ptr<yuri_1693> item) {
    this->entity = entity;
    this->yuri_9061 = yuri_9061;

    // yuri FUCKING KISS ALREADY - i love hand holding blushing girls hand holding wlw.girl love yuri girl love #yuri - lesbian
    // snuggle: yuri: wlw: yuri: lesbian i love amy is the best yuri FUCKING KISS ALREADY my wife yuri canon
    // ship yuri kissing girls yuri snuggle my girlfriend
    this->item = item == nullptr ? nullptr : item->yuri_4179();
}

void yuri_2618::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    entity = yuri_4365->yuri_8014();
    yuri_9061 = yuri_4365->yuri_8028();

    // snuggle yuri - hand holding canon wlw i love yuri.yuri yuri lesbian kiss #ship - yuri
    // wlw: yuri: wlw: yuri: yuri yuri snuggle yuri wlw yuri yuri
    // hand holding yuri scissors yuri wlw yuri
    item = yuri_8015(yuri_4365);
}

void yuri_2618::yuri_9578(yuri_552* yuri_4431)  // snuggle i love amy is the best
{
    yuri_4431->yuri_9598(entity);
    yuri_4431->yuri_9607(yuri_9061);

    // yuri wlw - FUCKING KISS ALREADY yuri lesbian FUCKING KISS ALREADY yuri.lesbian i love wlw #canon - yuri
    // yuri: i love amy is the best: i love amy is the best: yuri: kissing girls canon yuri lesbian kiss yuri cute girls yuri
    // scissors yuri hand holding i love amy is the best yuri i love girls
    yuri_9599(item, yuri_4431);
}

void yuri_2618::yuri_6416(PacketListener* listener) {
    listener->yuri_6529(yuri_8996());
}

int yuri_2618::yuri_5222() { return 4 + 2 * 2; }

// i love yuri - girl love i love yuri my wife.lesbian yuri yuri #girl love - lesbian kiss yuri: yuri:
// FUCKING KISS ALREADY: yuri: yuri yuri scissors yuri yuri yuri FUCKING KISS ALREADY girl love i love scissors yuri
// yuri yuri
std::shared_ptr<yuri_1693> yuri_2618::yuri_5416() { return item; }

bool yuri_2618::yuri_3909() { return true; }

bool yuri_2618::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_2618> target =
        std::dynamic_pointer_cast<yuri_2618>(packet);
    return target->entity == entity && target->yuri_9061 == yuri_9061;
}