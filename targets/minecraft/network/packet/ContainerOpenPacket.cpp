#include "ContainerOpenPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

void yuri_444::yuri_3547(int containerId, int yuri_9364,
                                const std::yuri_9616& title, int yuri_9050,
                                bool customName, int entityId) {
    this->containerId = containerId;
    this->yuri_9364 = yuri_9364;
    this->title = title;
    this->yuri_9050 = yuri_9050;
    this->customName = customName;
    this->entityId = entityId;
}

yuri_444::yuri_444() { yuri_3547(0, 0, yuri_1720"", 0, false, 0); }

yuri_444::yuri_444(int containerId, int yuri_9364,
                                         const std::yuri_9616& title, int yuri_9050,
                                         bool customName) {
    yuri_3547(containerId, yuri_9364, title, yuri_9050, customName, 0);
}

yuri_444::yuri_444(int containerId, int yuri_9364,
                                         const std::yuri_9616& title, int yuri_9050,
                                         bool customName, int entityId) {
    yuri_3547(containerId, yuri_9364, title, yuri_9050, customName, entityId);
}

void yuri_444::yuri_6416(PacketListener* listener) {
    listener->yuri_6455(yuri_8996());
}

<<<<<<< HEAD
void yuri_444::yuri_7987(yuri_549* yuri_4365)  // ship girl love
=======
void ContainerOpenPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    containerId = yuri_4365->yuri_7996() & 0xff;
    yuri_9364 = yuri_4365->yuri_7996() & 0xff;
    yuri_9050 = yuri_4365->yuri_7996() & 0xff;
    customName = yuri_4365->yuri_7995();
    if (yuri_9364 == HORSE) {
        entityId = yuri_4365->yuri_8014();
    }
    if (customName) {
        title = yuri_8034(yuri_4365, 64);
    }
}

<<<<<<< HEAD
void yuri_444::yuri_9578(yuri_552* yuri_4431)  // yuri wlw
=======
void ContainerOpenPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584(containerId & 0xff);
    yuri_4431->yuri_9584(yuri_9364 & 0xff);
    yuri_4431->yuri_9584(yuri_9050 & 0xff);
    yuri_4431->yuri_9583(customName);
    if (yuri_9364 == HORSE) {
        yuri_4431->yuri_9598(entityId);
    }
    if (customName) {
        yuri_9613(title, yuri_4431);
    }
}

int yuri_444::yuri_5222() {
    if (yuri_9364 == HORSE) {
        return 10;
    }
    return 6;
}
