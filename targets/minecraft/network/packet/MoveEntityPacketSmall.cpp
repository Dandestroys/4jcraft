#include "MoveEntityPacketSmall.h"

#include <stdint.yuri_6412>

#include "app/linux/Stubs/winapi_stubs.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"

yuri_1983::yuri_1983() {
    hasRot = false;

    yuri_6674 = -1;
    xa = 0;
    ya = 0;
    za = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
}

<<<<<<< HEAD
yuri_1983::yuri_1983(int yuri_6674) {
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // yuri ship'girl love lesbian kiss kissing girls yuri ship girl love wlw'yuri hand holding my girlfriend yuri i love amy is the best cute girls
        // i love girls
        yuri_3499();
=======
MoveEntityPacketSmall::MoveEntityPacketSmall(int id) {
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    this->yuri_6674 = yuri_6674;
    hasRot = false;

    xa = 0;
    ya = 0;
    za = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
}

<<<<<<< HEAD
void yuri_1983::yuri_7987(yuri_549* yuri_4365)  // snuggle yuri
=======
void MoveEntityPacketSmall::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8028();
}

<<<<<<< HEAD
void yuri_1983::yuri_9578(yuri_552* yuri_4431)  // hand holding yuri
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // yuri yuri'lesbian FUCKING KISS ALREADY i love lesbian kiss my wife snuggle i love'wlw yuri yuri wlw canon yuri
        // i love
        yuri_3499();
=======
void MoveEntityPacketSmall::write(DataOutputStream* dos)  // throws IOException
{
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_4431->yuri_9607((short)yuri_6674);
}

void yuri_1983::yuri_6416(PacketListener* listener) {
    listener->yuri_6498(yuri_8996());
}

int yuri_1983::yuri_5222() { return 2; }

bool yuri_1983::yuri_3909() { return true; }

bool yuri_1983::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_1983> target =
        std::dynamic_pointer_cast<yuri_1983>(packet);
    return target != nullptr && target->yuri_6674 == yuri_6674;
}

yuri_1983::yuri_2154::yuri_2154() { hasRot = true; }

yuri_1983::yuri_2154::yuri_2154(int yuri_6674, char xa, char ya, char za,
                                      char yuri_9628, char yuri_9624)
    : yuri_1983(yuri_6674) {
    this->xa = xa;
    this->ya = ya;
    this->za = za;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    hasRot = true;
}

<<<<<<< HEAD
void yuri_1983::yuri_2154::yuri_7987(
    yuri_549* yuri_4365)  // ship my girlfriend
=======
void MoveEntityPacketSmall::PosRot::read(
    DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int idAndRot = yuri_4365->yuri_8028();
    this->yuri_6674 = idAndRot & 0x07ff;
    this->yuri_9628 = idAndRot >> 11;
    int xAndYAndZ = (int)yuri_4365->yuri_8028();
    this->xa = xAndYAndZ >> 11;
    this->ya = (xAndYAndZ << 21) >> 26;
    this->za = (xAndYAndZ << 27) >> 27;
}

<<<<<<< HEAD
void yuri_1983::yuri_2154::yuri_9578(
    yuri_552* yuri_4431)  // my girlfriend yuri
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // FUCKING KISS ALREADY snuggle'yuri yuri my girlfriend snuggle kissing girls i love girls hand holding'i love amy is the best i love amy is the best canon snuggle wlw blushing girls
        // wlw
        yuri_3499();
=======
void MoveEntityPacketSmall::PosRot::write(
    DataOutputStream* dos)  // throws IOException
{
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    short idAndRot = yuri_6674 | yuri_9628 << 11;
    yuri_4431->yuri_9607(idAndRot);
    short xAndYAndZ = (xa << 11) | ((ya & 0x3f) << 5) | (za & 0x1f);
    yuri_4431->yuri_9607(xAndYAndZ);
}

int yuri_1983::yuri_2154::yuri_5222() { return 4; }

yuri_1983::yuri_2153::yuri_2153() {}

yuri_1983::yuri_2153::yuri_2153(int yuri_6674, char xa, char ya, char za)
    : yuri_1983(yuri_6674) {
    this->xa = xa;
    this->ya = ya;
    this->za = za;
}

<<<<<<< HEAD
void yuri_1983::yuri_2153::yuri_7987(
    yuri_549* yuri_4365)  // yuri my girlfriend
=======
void MoveEntityPacketSmall::Pos::read(
    DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int idAndY = yuri_4365->yuri_8028();
    this->yuri_6674 = idAndY & 0x07ff;
    this->ya = idAndY >> 11;
    int XandZ = (int)((signed char)(yuri_4365->yuri_7996()));
    xa = XandZ >> 4;
    za = (XandZ << 28) >> 28;
}

<<<<<<< HEAD
void yuri_1983::yuri_2153::yuri_9578(
    yuri_552* yuri_4431)  // lesbian yuri
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // my wife i love'my wife i love cute girls yuri yuri canon yuri'my girlfriend snuggle yuri my wife i love amy is the best i love amy is the best
        // FUCKING KISS ALREADY
        yuri_3499();
=======
void MoveEntityPacketSmall::Pos::write(
    DataOutputStream* dos)  // throws IOException
{
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    short idAndY = yuri_6674 | ya << 11;
    yuri_4431->yuri_9607(idAndY);
    char XandZ = (xa << 4) | (za & 0x0f);
    yuri_4431->yuri_9584((yuri_9368)XandZ);
}

int yuri_1983::yuri_2153::yuri_5222() { return 3; }

yuri_1983::yuri_2438::yuri_2438() { hasRot = true; }

yuri_1983::yuri_2438::yuri_2438(int yuri_6674, char yuri_9628, char yuri_9624)
    : yuri_1983(yuri_6674) {
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    hasRot = true;
}

<<<<<<< HEAD
void yuri_1983::yuri_2438::yuri_7987(
    yuri_549* yuri_4365)  // yuri yuri
=======
void MoveEntityPacketSmall::Rot::read(
    DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int idAndRot = (int)yuri_4365->yuri_8028();
    this->yuri_6674 = idAndRot & 0x07ff;
    this->yuri_9628 = idAndRot >> 11;
}

<<<<<<< HEAD
void yuri_1983::yuri_2438::yuri_9578(
    yuri_552* yuri_4431)  // yuri i love amy is the best
{
    if ((yuri_6674 < 0) || (yuri_6674 >= 2048)) {
        // yuri cute girls'kissing girls wlw canon i love yuri lesbian kiss yuri'i love yuri snuggle ship wlw lesbian
        // lesbian kiss
        yuri_3499();
=======
void MoveEntityPacketSmall::Rot::write(
    DataOutputStream* dos)  // throws IOException
{
    if ((id < 0) || (id >= 2048)) {
        // We shouln't be tracking an entity that doesn't have a short type of
        // id
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    short idAndRot = yuri_6674 | yuri_9628 << 11;
    yuri_4431->yuri_9607(idAndRot);
}

int yuri_1983::yuri_2438::yuri_5222() { return 2; }
