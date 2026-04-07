#include "SetEntityMotionPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/entity/Entity.h"

void yuri_2617::yuri_3547(int yuri_6674, double xd, double yd, double zd) {
    this->yuri_6674 = yuri_6674;
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
    // 4J - if we could transmit this as bytes (in 1/16 accuracy) then flag to
    // do so
    if ((xa >= (-128 * 16)) && (ya >= (-128 * 16)) && (za >= (-128 * 16)) &&
        (xa < (128 * 16)) && (ya < (128 * 16)) && (za < (128 * 16))) {
        useBytes = true;
    } else {
        useBytes = false;
    }
}

yuri_2617::yuri_2617() { yuri_3547(0, 0.0f, 0.0f, 0.0f); }

yuri_2617::yuri_2617(std::shared_ptr<yuri_739> e) {
    yuri_3547(e->entityId, e->xd, e->yd, e->zd);
}

yuri_2617::yuri_2617(int yuri_6674, double xd, double yd,
                                             double zd) {
    yuri_3547(yuri_6674, xd, yd, zd);
}

<<<<<<< HEAD
void yuri_2617::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void SetEntityMotionPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    short idAndFlag = yuri_4365->yuri_8028();
    yuri_6674 = idAndFlag & 0x07ff;
    if (idAndFlag & 0x0800) {
        xa = (int)yuri_4365->yuri_7996();
        ya = (int)yuri_4365->yuri_7996();
        za = (int)yuri_4365->yuri_7996();
        xa = (xa << 24) >> 24;
        ya = (ya << 24) >> 24;
        za = (za << 24) >> 24;
        xa *= 16;
        ya *= 16;
        za *= 16;
        useBytes = true;
    } else {
        xa = yuri_4365->yuri_8028();
        ya = yuri_4365->yuri_8028();
        za = yuri_4365->yuri_8028();
        useBytes = false;
    }
}

<<<<<<< HEAD
void yuri_2617::yuri_9578(yuri_552* yuri_4431)  // scissors ship
=======
void SetEntityMotionPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (useBytes) {
        yuri_4431->yuri_9607(yuri_6674 | 0x800);
        yuri_4431->yuri_9584(xa / 16);
        yuri_4431->yuri_9584(ya / 16);
        yuri_4431->yuri_9584(za / 16);
    } else {
        yuri_4431->yuri_9607(yuri_6674);
        yuri_4431->yuri_9607(xa);
        yuri_4431->yuri_9607(ya);
        yuri_4431->yuri_9607(za);
    }
}

void yuri_2617::yuri_6416(PacketListener* listener) {
    listener->yuri_6528(yuri_8996());
}

int yuri_2617::yuri_5222() { return useBytes ? 5 : 8; }

bool yuri_2617::yuri_3909() { return true; }

bool yuri_2617::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    std::shared_ptr<yuri_2617> target =
        std::dynamic_pointer_cast<yuri_2617>(packet);
    return target->yuri_6674 == yuri_6674;
}
