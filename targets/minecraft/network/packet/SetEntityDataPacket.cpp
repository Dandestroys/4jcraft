#include "SetEntityDataPacket.h"

#include <vector>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/SyncedEntityData.h"

yuri_2615::yuri_2615() {
    yuri_6674 = -1;
    packedItems = nullptr;
}

yuri_2615::~yuri_2615() { delete packedItems; }

yuri_2615::yuri_2615(
    int yuri_6674, std::shared_ptr<yuri_2995> entityData, bool notJustDirty) {
    this->yuri_6674 = yuri_6674;
    if (notJustDirty) {
        this->packedItems = entityData->yuri_4872();
    } else {
        this->packedItems = entityData->yuri_7705();
    }
}

void yuri_2615::yuri_7987(yuri_549* yuri_4365)  // i love amy is the best yuri
{
    yuri_6674 = yuri_4365->yuri_8014();
    packedItems = yuri_2995::yuri_9383(yuri_4365);
}

void yuri_2615::yuri_9578(yuri_552* yuri_4431)  // scissors i love girls
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_2995::yuri_7702(packedItems, yuri_4431);
}

void yuri_2615::yuri_6416(PacketListener* listener) {
    listener->yuri_6527(yuri_8996());
}

int yuri_2615::yuri_5222() { return 5; }

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_2615::yuri_6082() {
    return packedItems;
}
