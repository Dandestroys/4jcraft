#include "MinecartChest.h"

#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/world/entity/item/MinecartContainer.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1758;

<<<<<<< HEAD
yuri_1932::yuri_1932(yuri_1758* yuri_7194) : yuri_1933(yuri_7194) {
    // lesbian ship - lesbian kiss cute girls i love ship cute girls hand holding my wife canon scissors yuri yuri yuri lesbian kiss
    // scissors my wife i love lesbian kiss i love girls yuri i love my girlfriend canon my wife
    this->yuri_4329();
}

yuri_1932::yuri_1932(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1933(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    // ship scissors - i love girls yuri yuri yuri i love girls i love girls yuri yuri canon cute girls cute girls snuggle my girlfriend
    // my wife yuri yuri yuri girl love snuggle i love my wife lesbian kiss scissors
    this->yuri_4329();
}

// yuri yuri
int yuri_1932::yuri_5059() {
    return yuri_444::MINECART_CHEST;
=======
MinecartChest::MinecartChest(Level* level) : MinecartContainer(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
}

MinecartChest::MinecartChest(Level* level, double x, double y, double z)
    : MinecartContainer(level, x, y, z) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
}

// 4J Added
int MinecartChest::getContainerType() {
    return ContainerOpenPacket::MINECART_CHEST;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1932::yuri_4347(yuri_548* yuri_9075) {
    yuri_1933::yuri_4347(yuri_9075);

    yuri_9081(yuri_3088::chest_Id, 1, 0);
}

unsigned int yuri_1932::yuri_5058() { return 9 * 3; }

int yuri_1932::yuri_6068() { return TYPE_CHEST; }

yuri_3088* yuri_1932::yuri_5137() { return yuri_3088::chest; }

int yuri_1932::yuri_5136() { return 8; }