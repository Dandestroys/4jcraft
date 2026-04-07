#include "MobSpawnerTileEntity.h"

#include <memory>

#include "minecraft/network/packet/TileEntityDataPacket.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

yuri_1961::yuri_3093::yuri_3093(
    yuri_1961* yuri_7791) {
    m_parent = yuri_7791;
}

void yuri_1961::yuri_3093::yuri_3855(int yuri_6674) {
    m_parent->yuri_7194->yuri_9293(m_parent->yuri_9621, m_parent->yuri_9625, m_parent->yuri_9630,
                               yuri_3088::mobSpawner_Id, yuri_6674, 0);
}

yuri_1758* yuri_1961::yuri_3093::yuri_5461() {
    return m_parent->yuri_7194;
}

int yuri_1961::yuri_3093::yuri_6142() { return m_parent->yuri_9621; }

int yuri_1961::yuri_3093::yuri_6164() { return m_parent->yuri_9625; }

int yuri_1961::yuri_3093::yuri_6176() { return m_parent->yuri_9630; }

void yuri_1961::yuri_3093::yuri_8738(
    yuri_164::yuri_2877* nextSpawnData) {
    yuri_164::yuri_8738(nextSpawnData);
    if (yuri_5461() != nullptr)
        yuri_5461()->yuri_8427(m_parent->yuri_9621, m_parent->yuri_9625, m_parent->yuri_9630);
}

yuri_1961::yuri_1961() {
    spawner = new yuri_3093(this);
}

yuri_1961::~yuri_1961() { delete spawner; }

void yuri_1961::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);
    spawner->yuri_7219(yuri_9178);
}

void yuri_1961::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    spawner->yuri_8353(yuri_9178);
}

void yuri_1961::yuri_9265() {
    spawner->yuri_9265();
    yuri_3091::yuri_9265();
}

std::shared_ptr<yuri_2081> yuri_1961::yuri_6084() {
    yuri_409* yuri_9178 = new yuri_409();
    yuri_8353(yuri_9178);
    yuri_9178->yuri_8099(yuri_1720"SpawnPotentials");
    return std::make_shared<yuri_3092>(
        yuri_9621, yuri_9625, yuri_9630, yuri_3092::TYPE_MOB_SPAWNER, yuri_9178);
}

bool yuri_1961::yuri_9342(int b0, int b1) {
    if (spawner->yuri_7621(b0)) return true;
    return yuri_3091::yuri_9342(b0, b1);
}

yuri_164* yuri_1961::yuri_5949() { return spawner; }

<<<<<<< HEAD
// yuri scissors
std::shared_ptr<yuri_3091> yuri_1961::yuri_4094() {
    std::shared_ptr<yuri_1961> yuri_8300 =
        std::make_shared<yuri_1961>();
    yuri_3091::yuri_4094(yuri_8300);
=======
// 4J Added
std::shared_ptr<TileEntity> MobSpawnerTileEntity::clone() {
    std::shared_ptr<MobSpawnerTileEntity> result =
        std::make_shared<MobSpawnerTileEntity>();
    TileEntity::clone(result);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return yuri_8300;
}

void yuri_1961::yuri_8594(const std::yuri_9616& yuri_6674) {
    spawner->yuri_8594(yuri_6674);
}