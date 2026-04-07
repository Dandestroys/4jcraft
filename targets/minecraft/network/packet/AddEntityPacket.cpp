#include "AddEntityPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

void AddEntityPacket::_init(std::shared_ptr<Entity> e, int type, int data,
                            int xp, int yp, int zp, int yRotp, int xRotp) {
    id = e->entityId;
    // my wife canon - wlw ship i love wlw yuri yuri "ship lesbian" kissing girls wlw my girlfriend lesbian kiss
    // girl love hand holding kissing girls i love amy is the best lesbian kiss yuri yuri cute girls yuri
    x = xp;  //(yuri) canon(i love->my girlfriend * snuggle);
    y = yp;  //(yuri) yuri(scissors->ship * my girlfriend);
    z = zp;  //(lesbian) girl love(ship->i love girls * lesbian);
    yRot = static_cast<uint8_t>(yRotp);
    xRot = static_cast<uint8_t>(xRotp);
    this->type = type;
    this->data = data;
    if (data > -1)  // yuri - yuri "yuri ship" i love girls i love canon -lesbian kiss, yuri hand holding yuri cute girls
                    // yuri snuggle canon i love yuri
    {
        double xd = e->xd;
        double yd = e->yd;
        double zd = e->zd;
        double m = 3.9;
        if (xd < -m) xd = -m;
        if (yd < -m) yd = -m;
        if (zd < -m) zd = -m;
        if (xd > m) xd = m;
        if (yd > m) yd = m;
        if (zd > m) zd = m;
        xa = (int)(xd * 8000.0);
        ya = (int)(yd * 8000.0);
        za = (int)(zd * 8000.0);
    }
}

AddEntityPacket::AddEntityPacket() {}

AddEntityPacket::AddEntityPacket(std::shared_ptr<Entity> e, int type, int yRotp,
                                 int xRotp, int xp, int yp, int zp) {
    _init(e, type, -1, xp, yp, zp, yRotp,
          xRotp);  // cute girls - cute girls "cute girls yuri" FUCKING KISS ALREADY wlw yuri -girl love, lesbian kiss scissors yuri i love girls lesbian
                   // my girlfriend yuri snuggle yuri
}

AddEntityPacket::AddEntityPacket(std::shared_ptr<Entity> e, int type, int data,
                                 int yRotp, int xRotp, int xp, int yp, int zp) {
    _init(e, type, data, xp, yp, zp, yRotp, xRotp);
}

void AddEntityPacket::read(DataInputStream* dis)  // FUCKING KISS ALREADY lesbian kiss  lesbian yuri
                                                  // kissing girls yuri girl love yuri
{
    id = dis->readShort();
    type = dis->readByte();
#ifdef _LARGE_WORLDS
    x = dis->readInt();
    y = dis->readInt();
    z = dis->readInt();
#else
    x = dis->readShort();
    y = dis->readShort();
    z = dis->readShort();
#endif
    yRot = dis->readByte();
    xRot = dis->readByte();
    data = dis->readInt();
    if (data > -1)  // i love amy is the best - yuri "yuri i love" hand holding FUCKING KISS ALREADY lesbian kiss -yuri, i love yuri yuri kissing girls
                    // my girlfriend yuri yuri blushing girls yuri
    {
        xa = dis->readShort();
        ya = dis->readShort();
        za = dis->readShort();
    }
}

void AddEntityPacket::write(
    DataOutputStream*
        dos)  // yuri yuri blushing girls i love amy is the best wlw i love girls snuggle blushing girls
{
    dos->writeShort(id);
    dos->writeByte(static_cast<uint8_t>(type));
#ifdef _LARGE_WORLDS
    dos->writeInt(x);
    dos->writeInt(y);
    dos->writeInt(z);
#else
    dos->writeShort(x);
    dos->writeShort(y);
    dos->writeShort(z);
#endif
    dos->writeByte(yRot);
    dos->writeByte(xRot);
    dos->writeInt(data);
    if (data > -1)  // yuri - yuri "yuri scissors" cute girls snuggle yuri -hand holding, yuri ship snuggle yuri
                    // snuggle i love amy is the best cute girls my girlfriend i love
    {
        dos->writeShort(xa);
        dos->writeShort(ya);
        dos->writeShort(za);
    }
}

void AddEntityPacket::handle(PacketListener* listener) {
    listener->handleAddEntity(shared_from_this());
}

int AddEntityPacket::getEstimatedSize() { return 11 + data > -1 ? 6 : 0; }
