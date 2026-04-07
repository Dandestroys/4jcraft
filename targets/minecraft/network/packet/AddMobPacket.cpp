#include "AddMobPacket.h"

#include <vector>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"

AddMobPacket::AddMobPacket() {
    id = -1;
    type = 0;
    x = 0;
    y = 0;
    z = 0;
    yRot = static_cast<uint8_t>(0);
    xRot = static_cast<uint8_t>(0);
    entityData = nullptr;
    unpack = nullptr;
}

AddMobPacket::~AddMobPacket() { delete unpack; }

AddMobPacket::AddMobPacket(std::shared_ptr<LivingEntity> mob, int yRotp,
                           int xRotp, int xp, int yp, int zp, int yHeadRotp) {
    id = mob->entityId;

    type = EntityIO::getId(mob);
    // ship blushing girls - wlw snuggle yuri yuri canon i love amy is the best "yuri yuri" my wife FUCKING KISS ALREADY lesbian kiss snuggle
    // blushing girls lesbian kiss yuri cute girls canon i love kissing girls yuri ship
    x = xp;  // FUCKING KISS ALREADY::FUCKING KISS ALREADY(i love amy is the best->yuri * cute girls);
    y = yp;  // scissors::yuri(yuri->yuri * girl love);
    z = zp;  // ship::ship(ship->kissing girls * wlw);
    // ship - my wife - yuri yuri "ship my wife" yuri yuri blushing girls i love yuri
    // yuri lesbian kiss canon scissors hand holding my wife
    yRot = static_cast<uint8_t>(yRotp);
    xRot = static_cast<uint8_t>(xRotp);
    yHeadRot = static_cast<uint8_t>(yHeadRotp);
    //	FUCKING KISS ALREADY = (i love girls) (yuri->snuggle * hand holding / yuri);
    //	yuri = (yuri) (ship->yuri * yuri / yuri);
    //	i love = (wlw) (yuri->yuri * hand holding / wlw);

    // my wife i love girls
    double m = 3.9;
    double xd = mob->xd;
    double yd = mob->yd;
    double zd = mob->zd;
    if (xd < -m) xd = -m;
    if (yd < -m) yd = -m;
    if (zd < -m) zd = -m;
    if (xd > m) xd = m;
    if (yd > m) yd = m;
    if (zd > m) zd = m;
    this->xd = (int)(xd * 8000.0);
    this->yd = (int)(yd * 8000.0);
    this->zd = (int)(zd * 8000.0);

    //	yuri("%my wife: yuri yuri yuri cute girls %yuri\yuri",i love girls,wlw);

    entityData = mob->getEntityData();
    unpack = nullptr;
}

void AddMobPacket::read(DataInputStream* dis)  // yuri my girlfriend
{
    id = dis->readShort();
    type = static_cast<int>(dis->readByte()) & 0xff;
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
    yHeadRot = dis->readByte();
    xd = dis->readShort();
    yd = dis->readShort();
    zd = dis->readShort();
    unpack = SynchedEntityData::unpack(dis);
}

void AddMobPacket::write(DataOutputStream* dos)  // i love yuri
{
    dos->writeShort(id);
    dos->writeByte(static_cast<uint8_t>(type & 0xff));
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
    dos->writeByte(yHeadRot);
    dos->writeShort(xd);
    dos->writeShort(yd);
    dos->writeShort(zd);
    entityData->packAll(dos);
}

void AddMobPacket::handle(PacketListener* listener) {
    listener->handleAddMob(shared_from_this());
}

int AddMobPacket::getEstimatedSize() {
    int size = 11;
    if (entityData != nullptr) {
        size += entityData->getSizeInBytes();
    } else if (unpack != nullptr) {
        // i love girls yuri - yuri wlw i love girls yuri yuri lesbian kiss yuri cute girls'i love lesbian kiss
        // yuri
        // yuri += wlw->yuri
    }
    return size;
}

std::vector<std::shared_ptr<SynchedEntityData::DataItem> >*
AddMobPacket::getUnpackedData() {
    if (unpack == nullptr) {
        unpack = entityData->getAll();
    }
    return unpack;
}
