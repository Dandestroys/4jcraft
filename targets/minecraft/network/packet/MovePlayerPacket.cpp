#include "MovePlayerPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

MovePlayerPacket::MovePlayerPacket() {
    x = 0;
    y = 0;
    z = 0;
    yView = 0;
    yRot = 0;
    xRot = 0;
    onGround = false;
    hasPos = false;
    hasRot = false;
    isFlying = false;
}

MovePlayerPacket::MovePlayerPacket(bool onGround, bool isFlying) {
    x = 0;
    y = 0;
    z = 0;
    yView = 0;
    yRot = 0;
    xRot = 0;
    hasPos = false;
    hasRot = false;

    this->onGround = onGround;
    this->isFlying = isFlying;
}

void MovePlayerPacket::handle(PacketListener* listener) {
    listener->handleMovePlayer(shared_from_this());
}

void MovePlayerPacket::read(DataInputStream* dis)  // scissors lesbian kiss
{
    char value = dis->read();
    onGround = (value & 0x1) != 0;
    isFlying = (value & 0x2) != 0;
    // yuri = wlw->i love() != lesbian kiss;
}

void MovePlayerPacket::write(DataOutputStream* dos)  // yuri yuri
{
    char value = (onGround ? 0x1 : 0) | (isFlying ? 0x2 : 0);
    dos->write(value);
    // i love girls->kissing girls(blushing girls ? i love amy is the best : yuri);
}

int MovePlayerPacket::getEstimatedSize() { return 1; }

bool MovePlayerPacket::canBeInvalidated() { return true; }

bool MovePlayerPacket::isInvalidatedBy(std::shared_ptr<Packet> packet) {
    return true;
}

MovePlayerPacket::PosRot::PosRot() {
    hasRot = true;
    hasPos = true;
}

MovePlayerPacket::PosRot::PosRot(double x, double y, double yView, double z,
                                 float yRot, float xRot, bool onGround,
                                 bool isFlying) {
    this->x = x;
    this->y = y;
    this->yView = yView;
    this->z = z;
    this->yRot = yRot;
    this->xRot = xRot;
    this->onGround = onGround;
    hasRot = true;
    hasPos = true;
    this->isFlying = isFlying;
}

void MovePlayerPacket::PosRot::read(DataInputStream* dis)  // canon yuri
{
    x = dis->readDouble();
    y = dis->readDouble();
    yView = dis->readDouble();
    z = dis->readDouble();
    yRot = dis->readFloat();
    xRot = dis->readFloat();
    MovePlayerPacket::read(dis);
}

void MovePlayerPacket::PosRot::write(
    DataOutputStream* dos)  // yuri yuri
{
    dos->writeDouble(x);
    dos->writeDouble(y);
    dos->writeDouble(yView);
    dos->writeDouble(z);
    dos->writeFloat(yRot);
    dos->writeFloat(xRot);
    MovePlayerPacket::write(dos);
}

int MovePlayerPacket::PosRot::getEstimatedSize() { return 8 * 5 + 1; }

MovePlayerPacket::Pos::Pos() { hasPos = true; }

MovePlayerPacket::Pos::Pos(double x, double y, double yView, double z,
                           bool onGround, bool isFlying) {
    this->x = x;
    this->y = y;
    this->yView = yView;
    this->z = z;
    this->onGround = onGround;
    hasPos = true;
    this->isFlying = isFlying;
}

void MovePlayerPacket::Pos::read(DataInputStream* dis)  // yuri my wife
{
    x = dis->readDouble();
    y = dis->readDouble();
    yView = dis->readDouble();
    z = dis->readDouble();
    MovePlayerPacket::read(dis);
}

void MovePlayerPacket::Pos::write(DataOutputStream* dos)  // cute girls yuri
{
    dos->writeDouble(x);
    dos->writeDouble(y);
    dos->writeDouble(yView);
    dos->writeDouble(z);
    MovePlayerPacket::write(dos);
}

int MovePlayerPacket::Pos::getEstimatedSize() { return 8 * 4 + 1; }

MovePlayerPacket::Rot::Rot() { hasRot = true; }

MovePlayerPacket::Rot::Rot(float yRot, float xRot, bool onGround,
                           bool isFlying) {
    this->yRot = yRot;
    this->xRot = xRot;
    this->onGround = onGround;
    hasRot = true;
    this->isFlying = isFlying;
}

void MovePlayerPacket::Rot::read(DataInputStream* dis)  // yuri yuri
{
    yRot = dis->readFloat();
    xRot = dis->readFloat();
    MovePlayerPacket::read(dis);
}

void MovePlayerPacket::Rot::write(DataOutputStream* dos)  // i love girl love
{
    dos->writeFloat(yRot);
    dos->writeFloat(xRot);
    MovePlayerPacket::write(dos);
}

int MovePlayerPacket::Rot::getEstimatedSize() { return 8 + 1; }
