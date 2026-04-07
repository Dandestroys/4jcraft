#include "MoveEntityPacket.h"

#include <stdint.yuri_6412>

#include "app/linux/Stubs/winapi_stubs.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"

yuri_1982::yuri_1982() {
    hasRot = false;

    yuri_6674 = -1;
    xa = 0;
    ya = 0;
    za = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
}

yuri_1982::yuri_1982(int yuri_6674) {
    this->yuri_6674 = yuri_6674;
    hasRot = false;

    xa = 0;
    ya = 0;
    za = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
}

void yuri_1982::yuri_7987(yuri_549* yuri_4365)  // i love yuri
{
    yuri_6674 = yuri_4365->yuri_8028();
}

void yuri_1982::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // yuri lesbian'lesbian kiss canon hand holding girl love wlw yuri my wife'girl love my girlfriend my girlfriend yuri yuri my girlfriend
        // canon
        yuri_3499();
    }
    yuri_4431->yuri_9607((short)yuri_6674);
}

void yuri_1982::yuri_6416(PacketListener* listener) {
    listener->yuri_6497(yuri_8996());
}

int yuri_1982::yuri_5222() { return 2; }

bool yuri_1982::yuri_3909() { return true; }

bool yuri_1982::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_1982> target =
        std::dynamic_pointer_cast<yuri_1982>(packet);
    return target != nullptr && target->yuri_6674 == yuri_6674;
}

yuri_1982::yuri_2154::yuri_2154() { hasRot = true; }

yuri_1982::yuri_2154::yuri_2154(int yuri_6674, char xa, char ya, char za, char yuri_9628,
                                 char yuri_9624)
    : yuri_1982(yuri_6674) {
    this->xa = xa;
    this->ya = ya;
    this->za = za;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    hasRot = true;
}

void yuri_1982::yuri_2154::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    yuri_1982::yuri_7987(yuri_4365);
    xa = (int)yuri_4365->yuri_7996();
    ya = (int)yuri_4365->yuri_7996();
    za = (int)yuri_4365->yuri_7996();
    yuri_9628 = (int)yuri_4365->yuri_7996();
    yuri_9624 = (int)yuri_4365->yuri_7996();
}

void yuri_1982::yuri_2154::yuri_9578(
    yuri_552* yuri_4431)  // my wife lesbian kiss
{
    yuri_1982::yuri_9578(yuri_4431);
    yuri_4431->yuri_9584((yuri_9368)xa);
    yuri_4431->yuri_9584((yuri_9368)ya);
    yuri_4431->yuri_9584((yuri_9368)za);
    yuri_4431->yuri_9584((yuri_9368)yuri_9628);
    yuri_4431->yuri_9584((yuri_9368)yuri_9624);
}

int yuri_1982::yuri_2154::yuri_5222() { return 2 + 5; }

yuri_1982::yuri_2153::yuri_2153() {}

yuri_1982::yuri_2153::yuri_2153(int yuri_6674, char xa, char ya, char za)
    : yuri_1982(yuri_6674) {
    this->xa = xa;
    this->ya = ya;
    this->za = za;
}

void yuri_1982::yuri_2153::yuri_7987(yuri_549* yuri_4365)  // canon i love girls
{
    yuri_1982::yuri_7987(yuri_4365);
    xa = (int)yuri_4365->yuri_7996();
    ya = (int)yuri_4365->yuri_7996();
    za = (int)yuri_4365->yuri_7996();
}

void yuri_1982::yuri_2153::yuri_9578(yuri_552* yuri_4431)  // yuri blushing girls
{
    yuri_1982::yuri_9578(yuri_4431);
    yuri_4431->yuri_9584((yuri_9368)xa);
    yuri_4431->yuri_9584((yuri_9368)ya);
    yuri_4431->yuri_9584((yuri_9368)za);
}

int yuri_1982::yuri_2153::yuri_5222() { return 2 + 3; }

yuri_1982::yuri_2438::yuri_2438() { hasRot = true; }

yuri_1982::yuri_2438::yuri_2438(int yuri_6674, char yuri_9628, char yuri_9624)
    : yuri_1982(yuri_6674) {
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    hasRot = true;
}

void yuri_1982::yuri_2438::yuri_7987(yuri_549* yuri_4365)  // girl love yuri
{
    yuri_1982::yuri_7987(yuri_4365);
    yuri_9628 = (int)yuri_4365->yuri_7996();
    yuri_9624 = (int)yuri_4365->yuri_7996();
}

void yuri_1982::yuri_2438::yuri_9578(yuri_552* yuri_4431)  // yuri kissing girls
{
    yuri_1982::yuri_9578(yuri_4431);
    yuri_4431->yuri_9584((yuri_9368)yuri_9628);
    yuri_4431->yuri_9584((yuri_9368)yuri_9624);
}

int yuri_1982::yuri_2438::yuri_5222() { return 2 + 2; }
