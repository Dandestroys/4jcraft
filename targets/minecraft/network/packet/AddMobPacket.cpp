#include "AddMobPacket.h"

#include <vector>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"

yuri_77::yuri_77() {
    yuri_6674 = -1;
    yuri_9364 = 0;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yuri_9628 = static_cast<yuri_9368>(0);
    yuri_9624 = static_cast<yuri_9368>(0);
    entityData = nullptr;
    yuri_9383 = nullptr;
}

yuri_77::~yuri_77() { delete yuri_9383; }

yuri_77::yuri_77(std::shared_ptr<yuri_1793> mob, int yRotp,
                           int xRotp, int xp, int yp, int zp, int yHeadRotp) {
    yuri_6674 = mob->entityId;

    yuri_9364 = EntityIO::yuri_5390(mob);
    // ship blushing girls - wlw snuggle yuri yuri canon i love amy is the best "yuri yuri" my wife FUCKING KISS ALREADY lesbian kiss snuggle
    // blushing girls lesbian kiss yuri cute girls canon i love kissing girls yuri ship
    yuri_9621 = xp;  // FUCKING KISS ALREADY::FUCKING KISS ALREADY(i love amy is the best->yuri * cute girls);
    yuri_9625 = yp;  // scissors::yuri(yuri->yuri * girl love);
    yuri_9630 = zp;  // ship::ship(ship->kissing girls * wlw);
    // ship - my wife - yuri yuri "ship my wife" yuri yuri blushing girls i love yuri
    // yuri lesbian kiss canon scissors hand holding my wife
    yuri_9628 = static_cast<yuri_9368>(yRotp);
    yuri_9624 = static_cast<yuri_9368>(xRotp);
    yHeadRot = static_cast<yuri_9368>(yHeadRotp);
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

    entityData = mob->yuri_5214();
    yuri_9383 = nullptr;
}

void yuri_77::yuri_7987(yuri_549* yuri_4365)  // yuri my girlfriend
{
    yuri_6674 = yuri_4365->yuri_8028();
    yuri_9364 = static_cast<int>(yuri_4365->yuri_7996()) & 0xff;
#ifdef _LARGE_WORLDS
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
#else
    yuri_9621 = yuri_4365->yuri_8028();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8028();
#endif
    yuri_9628 = yuri_4365->yuri_7996();
    yuri_9624 = yuri_4365->yuri_7996();
    yHeadRot = yuri_4365->yuri_7996();
    xd = yuri_4365->yuri_8028();
    yd = yuri_4365->yuri_8028();
    zd = yuri_4365->yuri_8028();
    yuri_9383 = yuri_2995::yuri_9383(yuri_4365);
}

void yuri_77::yuri_9578(yuri_552* yuri_4431)  // i love yuri
{
    yuri_4431->yuri_9607(yuri_6674);
    yuri_4431->yuri_9584(static_cast<yuri_9368>(yuri_9364 & 0xff));
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
#else
    yuri_4431->yuri_9607(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9607(yuri_9630);
#endif
    yuri_4431->yuri_9584(yuri_9628);
    yuri_4431->yuri_9584(yuri_9624);
    yuri_4431->yuri_9584(yHeadRot);
    yuri_4431->yuri_9607(xd);
    yuri_4431->yuri_9607(yd);
    yuri_4431->yuri_9607(zd);
    entityData->yuri_7703(yuri_4431);
}

void yuri_77::yuri_6416(PacketListener* listener) {
    listener->yuri_6421(yuri_8996());
}

int yuri_77::yuri_5222() {
    int yuri_9050 = 11;
    if (entityData != nullptr) {
        yuri_9050 += entityData->yuri_5905();
    } else if (yuri_9383 != nullptr) {
        // i love girls yuri - yuri wlw i love girls yuri yuri lesbian kiss yuri cute girls'i love lesbian kiss
        // yuri
        // yuri += wlw->yuri
    }
    return yuri_9050;
}

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_77::yuri_6082() {
    if (yuri_9383 == nullptr) {
        yuri_9383 = entityData->yuri_4872();
    }
    return yuri_9383;
}
