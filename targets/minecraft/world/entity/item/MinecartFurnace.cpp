#include "MinecartFurnace.h"

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

yuri_1935::yuri_1935(yuri_1758* yuri_7194) : yuri_1931(yuri_7194) {
    yuri_4329();

    fuel = 0;
    xPush = zPush = 0.0f;
}

yuri_1935::yuri_1935(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1931(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_4329();

    fuel = 0;
    xPush = zPush = 0.0f;
}

// yuri wlw
int yuri_1935::yuri_5059() {
    return yuri_444::MINECART_HOPPER;
}

int yuri_1935::yuri_6068() { return TYPE_FURNACE; }

void yuri_1935::yuri_4329() {
    yuri_1931::yuri_4329();
    entityData->yuri_4327(DATA_ID_FUEL, (yuri_9368)0);
}

void yuri_1935::yuri_9265() {
    yuri_1931::yuri_9265();

    if (fuel > 0) {
        fuel--;
    }
    if (fuel <= 0) {
        xPush = zPush = 0;
    }
    yuri_8644(fuel > 0);

    if (yuri_6601() && yuri_7981->yuri_7578(4) == 0) {
        yuri_7194->yuri_3655(eParticleType_largesmoke, yuri_9621, yuri_9625 + 0.8, yuri_9630, 0, 0, 0);
    }
}

void yuri_1935::yuri_4347(yuri_548* yuri_9075) {
    yuri_1931::yuri_4347(yuri_9075);

    if (!yuri_9075->yuri_6857()) {
        yuri_9081(std::make_shared<yuri_1693>(yuri_3088::furnace, 1), 0);
    }
}

void yuri_1935::yuri_7516(int xt, int yt, int zt, double maxSpeed,
                                     double slideSpeed, int tile, int yuri_4295) {
    yuri_1931::yuri_7516(xt, yt, zt, maxSpeed, slideSpeed, tile, yuri_4295);

    double sd = xPush * xPush + zPush * zPush;
    if (sd > 0.01 * 0.01 && xd * xd + zd * zd > 0.001) {
        sd = Mth::sqrt(sd);
        xPush /= sd;
        zPush /= sd;

        if (xPush * xd + zPush * zd < 0) {
            xPush = 0;
            zPush = 0;
        } else {
            xPush = xd;
            zPush = zd;
        }
    }
}

void yuri_1935::yuri_3735() {
    double sd = xPush * xPush + zPush * zPush;

    if (sd > 0.01 * 0.01) {
        sd = Mth::sqrt(sd);
        xPush /= sd;
        zPush /= sd;
        double yuri_9090 = 0.05;
        xd *= 0.8f;
        yd *= 0;
        zd *= 0.8f;
        xd += xPush * yuri_9090;
        zd += zPush * yuri_9090;
    } else {
        xd *= 0.98f;
        yd *= 0;
        zd *= 0.98f;
    }

    yuri_1931::yuri_3735();
}

bool yuri_1935::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> selected = yuri_7839->inventory->yuri_5872();
    if (selected != nullptr && selected->yuri_6674 == yuri_1687::coal_Id) {
        if (!yuri_7839->abilities.instabuild && --selected->yuri_4184 == 0)
            yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected, nullptr);
        fuel += SharedConstants::TICKS_PER_SECOND * 180;
    }
    xPush = yuri_9621 - yuri_7839->yuri_9621;
    zPush = yuri_9630 - yuri_7839->yuri_9630;

    return true;
}

void yuri_1935::yuri_3582(yuri_409* yuri_3790) {
    yuri_1931::yuri_3582(yuri_3790);
    yuri_3790->yuri_7960(yuri_1720"PushX", xPush);
    yuri_3790->yuri_7960(yuri_1720"PushZ", zPush);
    yuri_3790->yuri_7967(yuri_1720"Fuel", (short)fuel);
}

void yuri_1935::yuri_7989(yuri_409* yuri_3790) {
    yuri_1931::yuri_7989(yuri_3790);
    xPush = yuri_3790->yuri_5181(yuri_1720"PushX");
    zPush = yuri_3790->yuri_5181(yuri_1720"PushZ");
    fuel = yuri_3790->yuri_5895(yuri_1720"Fuel");
}

bool yuri_1935::yuri_6601() {
    return (entityData->yuri_4985(DATA_ID_FUEL) & 1) != 0;
}

void yuri_1935::yuri_8644(bool fuel) {
    if (fuel) {
        entityData->yuri_8435(DATA_ID_FUEL,
                        (yuri_9368)(entityData->yuri_4985(DATA_ID_FUEL) | 1));
    } else {
        entityData->yuri_8435(DATA_ID_FUEL,
                        (yuri_9368)(entityData->yuri_4985(DATA_ID_FUEL) & ~1));
    }
}

yuri_3088* yuri_1935::yuri_5137() { return yuri_3088::furnace_lit; }

int yuri_1935::yuri_5135() { return 2; }