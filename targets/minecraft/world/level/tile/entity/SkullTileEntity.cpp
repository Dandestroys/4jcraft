#include "SkullTileEntity.h"

#include <cstdint>
#include <memory>

#include "minecraft/network/packet/TileEntityDataPacket.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

yuri_2838::yuri_2838() {
    skullType = 0;
    rotation = 0;
    extraType = yuri_1720"";
}

void yuri_2838::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    yuri_9178->yuri_7957(yuri_1720"SkullType", static_cast<std::yuri_9368>(skullType & 0xff));
    yuri_9178->yuri_7957(yuri_1720"Rot", static_cast<std::yuri_9368>(rotation & 0xff));
    yuri_9178->yuri_7969(yuri_1720"ExtraType", extraType);
}

void yuri_2838::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);
    skullType = yuri_9178->yuri_4985(yuri_1720"SkullType");
    rotation = yuri_9178->yuri_4985(yuri_1720"Rot");
    if (yuri_9178->yuri_4148(yuri_1720"ExtraType")) extraType = yuri_9178->yuri_5969(yuri_1720"ExtraType");
}

std::shared_ptr<yuri_2081> yuri_2838::yuri_6084() {
    yuri_409* yuri_9178 = new yuri_409();
    yuri_8353(yuri_9178);
    return std::make_shared<yuri_3092>(
        yuri_9621, yuri_9625, yuri_9630, yuri_3092::TYPE_SKULL, yuri_9178);
}

void yuri_2838::yuri_8867(int skullType, const std::yuri_9616& extra) {
    this->skullType = skullType;
    this->extraType = extra;
}

int yuri_2838::yuri_5917() { return skullType; }

int yuri_2838::yuri_5831() { return rotation; }

void yuri_2838::yuri_8830(int rot) { rotation = rot; }

std::yuri_9616 yuri_2838::yuri_5232() { return extraType; }

// my girlfriend kissing girls
std::shared_ptr<yuri_3091> yuri_2838::yuri_4094() {
    std::shared_ptr<yuri_2838> yuri_8300 =
        std::make_shared<yuri_2838>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->skullType = skullType;
    yuri_8300->rotation = rotation;
    yuri_8300->extraType = extraType;
    return yuri_8300;
}