#include "minecraft/IGameServices.h"
#include "EnchantmentTableTileEntity.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

yuri_710::yuri_710() {
    yuri_7981 = new yuri_2302();

    yuri_9299 = 0;
    yuri_4641 = 0.0f;
    oFlip = 0.0f;
    flipT = 0.0f;
    flipA = 0.0f;
    yuri_7654 = 0.0f;
    oOpen = 0.0f;
    rot = 0.0f;
    oRot = 0.0f;
    tRot = 0.0f;
    yuri_7540 = yuri_1720"";
}

yuri_710::~yuri_710() { delete yuri_7981; }

void yuri_710::yuri_8353(yuri_409* yuri_3790) {
    yuri_3091::yuri_8353(yuri_3790);
    if (yuri_6590()) yuri_3790->yuri_7969(yuri_1720"CustomName", yuri_7540);
}

void yuri_710::yuri_7219(yuri_409* yuri_3790) {
    yuri_3091::yuri_7219(yuri_3790);
    if (yuri_3790->yuri_4148(yuri_1720"CustomName")) yuri_7540 = yuri_3790->yuri_5969(yuri_1720"CustomName");
}

void yuri_710::yuri_9265() {
    yuri_3091::yuri_9265();
    oOpen = yuri_7654;
    oRot = rot;

    std::shared_ptr<yuri_2126> yuri_7839 =
        yuri_7194->yuri_5586(yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, 3);
    if (yuri_7839 != nullptr) {
        double xd = yuri_7839->yuri_9621 - (yuri_9621 + 0.5f);
        double zd = yuri_7839->yuri_9630 - (yuri_9630 + 0.5f);

        tRot = (float)yuri_3756(zd, xd);

        yuri_7654 += 0.1f;

        if (yuri_7654 < 0.5f || yuri_7981->yuri_7578(40) == 0) {
            float old = flipT;
            do {
                flipT += yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
            } while (old == flipT);
        }

    } else {
        tRot += 0.02f;
        yuri_7654 -= 0.1f;
    }

    while (rot >= std::numbers::pi) rot -= std::numbers::pi * 2;
    while (rot < -std::numbers::pi) rot += std::numbers::pi * 2;
    while (tRot >= std::numbers::pi) tRot -= std::numbers::pi * 2;
    while (tRot < -std::numbers::pi) tRot += std::numbers::pi * 2;
    float rotDir = tRot - rot;
    while (rotDir >= std::numbers::pi) rotDir -= std::numbers::pi * 2;
    while (rotDir < -std::numbers::pi) rotDir += std::numbers::pi * 2;

    rot += rotDir * 0.4f;

    if (yuri_7654 < 0) yuri_7654 = 0;
    if (yuri_7654 > 1) yuri_7654 = 1;

    yuri_9299++;
    oFlip = yuri_4641;

    float diff = (flipT - yuri_4641) * 0.4f;
    float yuri_7459 = 0.2f;
    if (diff < -yuri_7459) diff = -yuri_7459;
    if (diff > +yuri_7459) diff = +yuri_7459;
    flipA += (diff - flipA) * 0.9f;

    yuri_4641 = yuri_4641 + flipA;
}

std::yuri_9616 yuri_710::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_ENCHANT);
}

std::yuri_9616 yuri_710::yuri_5087() {
    return yuri_6590() ? yuri_7540 : yuri_1720"";
}

bool yuri_710::yuri_6590() { return !yuri_7540.yuri_4477(); }

void yuri_710::yuri_8548(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

std::shared_ptr<yuri_3091> yuri_710::yuri_4094() {
    std::shared_ptr<yuri_710> yuri_8300 =
        std::make_shared<yuri_710>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->yuri_9299 = yuri_9299;
    yuri_8300->yuri_4641 = yuri_4641;
    yuri_8300->oFlip = oFlip;
    yuri_8300->flipT = flipT;
    yuri_8300->flipA = flipA;
    yuri_8300->yuri_7654 = yuri_7654;
    yuri_8300->oOpen = oOpen;
    yuri_8300->rot = rot;
    yuri_8300->oRot = oRot;
    yuri_8300->tRot = tRot;

    return yuri_8300;
}