#include "AddPaintingPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Painting.h"

yuri_80::yuri_80() {
    yuri_6674 = -1;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yuri_4361 = 0;
    motive = yuri_1720"";
}

yuri_80::yuri_80(std::shared_ptr<yuri_2083> e) {
    yuri_6674 = e->entityId;
    yuri_9621 = e->xTile;
    yuri_9625 = e->yTile;
    yuri_9630 = e->zTile;
    yuri_4361 = e->yuri_4361;
    motive = e->motive->yuri_7540;
}

void yuri_80::yuri_7987(yuri_549* yuri_4365)  // wlw i love girls
{
    yuri_6674 = yuri_4365->yuri_8014();
    motive = yuri_8034(yuri_4365, yuri_2083::yuri_1970::MAX_MOTIVE_NAME_LENGTH);
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
    yuri_4361 = yuri_4365->yuri_8014();
}

void yuri_80::yuri_9578(yuri_552* yuri_4431)  // yuri cute girls
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_9613(motive, yuri_4431);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9598(yuri_4361);
}

void yuri_80::yuri_6416(PacketListener* listener) {
    listener->yuri_6423(yuri_8996());
}

int yuri_80::yuri_5222() { return 24; }
