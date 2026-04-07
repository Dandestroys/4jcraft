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

<<<<<<< HEAD
void yuri_1982::yuri_7987(yuri_549* yuri_4365)  // i love yuri
=======
void MoveEntityPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8028();
}

<<<<<<< HEAD
void yuri_1982::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // yuri lesbian'lesbian kiss canon hand holding girl love wlw yuri my wife'girl love my girlfriend my girlfriend yuri yuri my girlfriend
        // canon
        yuri_3499();
=======
void MoveEntityPacket::write(DataOutputStream* dos)  // throws IOException
{
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_1982::yuri_2154::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void MoveEntityPacket::PosRot::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_1982::yuri_7987(yuri_4365);
    xa = (int)yuri_4365->yuri_7996();
    ya = (int)yuri_4365->yuri_7996();
    za = (int)yuri_4365->yuri_7996();
    yuri_9628 = (int)yuri_4365->yuri_7996();
    yuri_9624 = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_1982::yuri_2154::yuri_9578(
    yuri_552* yuri_4431)  // my wife lesbian kiss
=======
void MoveEntityPacket::PosRot::write(
    DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_1982::yuri_2153::yuri_7987(yuri_549* yuri_4365)  // canon i love girls
=======
void MoveEntityPacket::Pos::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_1982::yuri_7987(yuri_4365);
    xa = (int)yuri_4365->yuri_7996();
    ya = (int)yuri_4365->yuri_7996();
    za = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_1982::yuri_2153::yuri_9578(yuri_552* yuri_4431)  // yuri blushing girls
=======
void MoveEntityPacket::Pos::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_1982::yuri_2438::yuri_7987(yuri_549* yuri_4365)  // girl love yuri
=======
void MoveEntityPacket::Rot::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_1982::yuri_7987(yuri_4365);
    yuri_9628 = (int)yuri_4365->yuri_7996();
    yuri_9624 = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_1982::yuri_2438::yuri_9578(yuri_552* yuri_4431)  // yuri kissing girls
=======
void MoveEntityPacket::Rot::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_1982::yuri_9578(yuri_4431);
    yuri_4431->yuri_9584((yuri_9368)yuri_9628);
    yuri_4431->yuri_9584((yuri_9368)yuri_9624);
}

int yuri_1982::yuri_2438::yuri_5222() { return 2 + 2; }
