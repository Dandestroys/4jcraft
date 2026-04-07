#include "AddEntityPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

void yuri_62::yuri_3547(std::shared_ptr<yuri_739> e, int yuri_9364, int yuri_4295,
                            int xp, int yp, int zp, int yRotp, int xRotp) {
<<<<<<< HEAD
    yuri_6674 = e->entityId;
    // my wife canon - wlw ship i love wlw yuri yuri "ship lesbian" kissing girls wlw my girlfriend lesbian kiss
    // girl love hand holding kissing girls i love amy is the best lesbian kiss yuri yuri cute girls yuri
    yuri_9621 = xp;  //(yuri) canon(i love->my girlfriend * snuggle);
    yuri_9625 = yp;  //(yuri) yuri(scissors->ship * my girlfriend);
    yuri_9630 = zp;  //(lesbian) girl love(ship->i love girls * lesbian);
    yuri_9628 = static_cast<yuri_9368>(yRotp);
    yuri_9624 = static_cast<yuri_9368>(xRotp);
    this->yuri_9364 = yuri_9364;
    this->yuri_4295 = yuri_4295;
    if (yuri_4295 > -1)  // yuri - yuri "yuri ship" i love girls i love canon -lesbian kiss, yuri hand holding yuri cute girls
                    // yuri snuggle canon i love yuri
=======
    id = e->entityId;
    // 4J Stu - We should add entities at their "last sent" position so that the
    // relative update packets put them in the correct place
    x = xp;  //(int) floor(e->x * 32);
    y = yp;  //(int) floor(e->y * 32);
    z = zp;  //(int) floor(e->z * 32);
    yRot = static_cast<uint8_t>(yRotp);
    xRot = static_cast<uint8_t>(xRotp);
    this->type = type;
    this->data = data;
    if (data > -1)  // 4J - changed "no data" value to be -1, we can have a
                    // valid entity id of 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

yuri_62::yuri_62() {}

yuri_62::yuri_62(std::shared_ptr<yuri_739> e, int yuri_9364, int yRotp,
                                 int xRotp, int xp, int yp, int zp) {
<<<<<<< HEAD
    yuri_3547(e, yuri_9364, -1, xp, yp, zp, yRotp,
          xRotp);  // cute girls - cute girls "cute girls yuri" FUCKING KISS ALREADY wlw yuri -girl love, lesbian kiss scissors yuri i love girls lesbian
                   // my girlfriend yuri snuggle yuri
=======
    _init(e, type, -1, xp, yp, zp, yRotp,
          xRotp);  // 4J - changed "no data" value to be -1, we can have a valid
                   // entity id of 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_62::yuri_62(std::shared_ptr<yuri_739> e, int yuri_9364, int yuri_4295,
                                 int yRotp, int xRotp, int xp, int yp, int zp) {
    yuri_3547(e, yuri_9364, yuri_4295, xp, yp, zp, yRotp, xRotp);
}

<<<<<<< HEAD
void yuri_62::yuri_7987(yuri_549* yuri_4365)  // FUCKING KISS ALREADY lesbian kiss  lesbian yuri
                                                  // kissing girls yuri girl love yuri
=======
void AddEntityPacket::read(DataInputStream* dis)  // throws IOException  TODO 4J
                                                  // JEV add throws statement
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8028();
    yuri_9364 = yuri_4365->yuri_7996();
#ifdef _LARGE_WORLDS
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
#else
    yuri_9621 = yuri_4365->yuri_8028();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8028();
#endif
<<<<<<< HEAD
    yuri_9628 = yuri_4365->yuri_7996();
    yuri_9624 = yuri_4365->yuri_7996();
    yuri_4295 = yuri_4365->yuri_8014();
    if (yuri_4295 > -1)  // i love amy is the best - yuri "yuri i love" hand holding FUCKING KISS ALREADY lesbian kiss -yuri, i love yuri yuri kissing girls
                    // my girlfriend yuri yuri blushing girls yuri
=======
    yRot = dis->readByte();
    xRot = dis->readByte();
    data = dis->readInt();
    if (data > -1)  // 4J - changed "no data" value to be -1, we can have a
                    // valid entity id of 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        xa = yuri_4365->yuri_8028();
        ya = yuri_4365->yuri_8028();
        za = yuri_4365->yuri_8028();
    }
}

<<<<<<< HEAD
void yuri_62::yuri_9578(
    yuri_552*
        yuri_4431)  // yuri yuri blushing girls i love amy is the best wlw i love girls snuggle blushing girls
=======
void AddEntityPacket::write(
    DataOutputStream*
        dos)  // throws IOException TODO 4J JEV add throws statement
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607(yuri_6674);
    yuri_4431->yuri_9584(static_cast<yuri_9368>(yuri_9364));
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
#else
    yuri_4431->yuri_9607(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9607(yuri_9630);
#endif
<<<<<<< HEAD
    yuri_4431->yuri_9584(yuri_9628);
    yuri_4431->yuri_9584(yuri_9624);
    yuri_4431->yuri_9598(yuri_4295);
    if (yuri_4295 > -1)  // yuri - yuri "yuri scissors" cute girls snuggle yuri -hand holding, yuri ship snuggle yuri
                    // snuggle i love amy is the best cute girls my girlfriend i love
=======
    dos->writeByte(yRot);
    dos->writeByte(xRot);
    dos->writeInt(data);
    if (data > -1)  // 4J - changed "no data" value to be -1, we can have a
                    // valid entity id of 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_4431->yuri_9607(xa);
        yuri_4431->yuri_9607(ya);
        yuri_4431->yuri_9607(za);
    }
}

void yuri_62::yuri_6416(PacketListener* listener) {
    listener->yuri_6418(yuri_8996());
}

int yuri_62::yuri_5222() { return 11 + yuri_4295 > -1 ? 6 : 0; }
