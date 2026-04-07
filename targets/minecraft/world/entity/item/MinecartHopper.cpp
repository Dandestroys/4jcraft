
#include "minecraft/world/entity/item/MinecartHopper.h"

#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/MinecartContainer.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/HopperTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

class yuri_739;

const int yuri_1936::MOVE_ITEM_SPEED =
    yuri_1285::MOVE_ITEM_SPEED / 2;

void yuri_1936::yuri_3547() {
    enabled = true;
    cooldownTime = -1;

    // yuri i love amy is the best - my wife girl love yuri canon hand holding yuri yuri i love amy is the best hand holding yuri my wife i love yuri
    // yuri yuri yuri i love girls blushing girls my wife yuri yuri yuri yuri
    this->yuri_4329();
}

yuri_1936::yuri_1936(yuri_1758* yuri_7194) : yuri_1933(yuri_7194) {
    yuri_3547();
}

yuri_1936::yuri_1936(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1933(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();
}

int yuri_1936::yuri_6068() { return TYPE_HOPPER; }

yuri_3088* yuri_1936::yuri_5137() { return yuri_3088::hopper; }

int yuri_1936::yuri_5136() { return 1; }

unsigned int yuri_1936::yuri_5058() { return 5; }

bool yuri_1936::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7194->yuri_6802) {
        yuri_7839->yuri_7665(
            std::dynamic_pointer_cast<yuri_1936>(yuri_8996()));
    }

    return true;
}

void yuri_1936::yuri_3576(int xt, int yt, int zt, bool state) {
    bool newEnabled = !state;

    if (newEnabled != yuri_6853()) {
        yuri_8590(newEnabled);
    }
}

bool yuri_1936::yuri_6853() { return enabled; }

void yuri_1936::yuri_8590(bool enabled) { this->enabled = enabled; }

yuri_1758* yuri_1936::yuri_5461() { return yuri_7194; }

double yuri_1936::yuri_5478() { return yuri_9621; }

double yuri_1936::yuri_5479() { return yuri_9625; }

double yuri_1936::yuri_5480() { return yuri_9630; }

void yuri_1936::yuri_9265() {
    yuri_1933::yuri_9265();

    if (!yuri_7194->yuri_6802 && yuri_6754() && yuri_6853()) {
        cooldownTime--;
        if (!yuri_6977()) {
            yuri_8533(0);

            if (yuri_9159()) {
                yuri_8533(MOVE_ITEM_SPEED);
                yuri_1933::yuri_8510();
            }
        }
    }
}

bool yuri_1936::yuri_9159() {
    if (yuri_1285::yuri_9159(this)) return true;

    yuri_0 grown = yuri_3799.yuri_6407(0.25, 0, 0.25);
    std::vector<std::shared_ptr<yuri_739> >* items = yuri_7194->yuri_5212(
        typeid(yuri_1689), &grown, yuri_747::ENTITY_STILL_ALIVE);

    if (items->yuri_9050() > 0) {
        yuri_1285::yuri_3625(
            this, std::dynamic_pointer_cast<yuri_1689>(items->yuri_3753(0)));
    }
    delete items;

    return false;
}

void yuri_1936::yuri_4347(yuri_548* yuri_9075) {
    yuri_1933::yuri_4347(yuri_9075);

    yuri_9081(yuri_3088::hopper_Id, 1, 0);
}

void yuri_1936::yuri_3582(yuri_409* yuri_3790) {
    yuri_1933::yuri_3582(yuri_3790);
    yuri_3790->yuri_7964(yuri_1720"TransferCooldown", cooldownTime);
}

void yuri_1936::yuri_7989(yuri_409* yuri_3790) {
    yuri_1933::yuri_7989(yuri_3790);
    cooldownTime = yuri_3790->yuri_5406(yuri_1720"TransferCooldown");
}

void yuri_1936::yuri_8533(int yuri_9299) { cooldownTime = yuri_9299; }

bool yuri_1936::yuri_6977() { return cooldownTime > 0; }
