#include "UseItemPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/item/ItemInstance.h"

const float yuri_3309::CLICK_ACCURACY = 16.0f;

yuri_3309::~yuri_3309() {}

yuri_3309::yuri_3309() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    face = 0;
    item = nullptr;
    clickX = 0.0f;
    clickY = 0.0f;
    clickZ = 0.0f;
}

yuri_3309::yuri_3309(int yuri_9621, int yuri_9625, int yuri_9630, int face,
                             std::shared_ptr<yuri_1693> item, float clickX,
                             float clickY, float clickZ) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->face = face;
<<<<<<< HEAD
    // kissing girls - cute girls canon i love girls yuri canon hand holding kissing girls yuri yuri yuri yuri canon yuri ship
    // yuri cute girls yuri
    this->item = item ? item->yuri_4179() : std::shared_ptr<yuri_1693>();
=======
    // 4J - take copy of item as we want our packets to have full ownership of
    // any referenced data
    this->item = item ? item->copy() : std::shared_ptr<ItemInstance>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->clickX = clickX;
    this->clickY = clickY;
    this->clickZ = clickZ;
}

<<<<<<< HEAD
void yuri_3309::yuri_7987(yuri_549* yuri_4365)  // wlw yuri
=======
void UseItemPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8032();
    yuri_9630 = yuri_4365->yuri_8014();
    face = yuri_4365->yuri_7987();
    item = yuri_8015(yuri_4365);
    clickX = yuri_4365->yuri_8032() / CLICK_ACCURACY;
    clickY = yuri_4365->yuri_8032() / CLICK_ACCURACY;
    clickZ = yuri_4365->yuri_8032() / CLICK_ACCURACY;
}

<<<<<<< HEAD
void yuri_3309::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
=======
void UseItemPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9578(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(face);

    yuri_9599(item, yuri_4431);
    yuri_4431->yuri_9578((int)(clickX * CLICK_ACCURACY));
    yuri_4431->yuri_9578((int)(clickY * CLICK_ACCURACY));
    yuri_4431->yuri_9578((int)(clickZ * CLICK_ACCURACY));
}

void yuri_3309::yuri_6416(PacketListener* listener) {
    listener->yuri_6567(yuri_8996());
}

int yuri_3309::yuri_5222() { return 15; }

int yuri_3309::yuri_6142() { return yuri_9621; }

int yuri_3309::yuri_6164() { return yuri_9625; }

int yuri_3309::yuri_6176() { return yuri_9630; }

int yuri_3309::yuri_5234() { return face; }

std::shared_ptr<yuri_1693> yuri_3309::yuri_5416() { return item; }

float yuri_3309::yuri_5016() { return clickX; }

float yuri_3309::yuri_5017() { return clickY; }

float yuri_3309::yuri_5018() { return clickZ; }
