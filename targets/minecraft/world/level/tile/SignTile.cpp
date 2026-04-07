#include "SignTile.h"

#include <optional>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/phys/AABB.h"

yuri_2816::yuri_2816(int yuri_6674, eINSTANCEOF clas, bool onGround)
    : yuri_163(yuri_6674, yuri_1886::wood, false) {
    this->onGround = onGround;
    this->clas = clas;
    yuri_9402();
}

yuri_1346* yuri_2816::yuri_6007(int face, int yuri_4295) {
    return yuri_3088::wood->yuri_6007(face);
}

void yuri_2816::yuri_9402() {
    float r = 4 / 16.0f;
    float yuri_6412 = 16 / 16.0f;
    this->yuri_8855(0.5f - r, 0, 0.5f - r, 0.5f + r, yuri_6412, 0.5f + r);
}

std::optional<yuri_0> yuri_2816::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

yuri_0 yuri_2816::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_163::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_2816::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri my girlfriend yuri, yuri i love amy is the best
=======
void SignTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (onGround) return;

    int face = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    float h0 = (4 + 0.5f) / 16.0f;
    float h1 = (12 + 0.5f) / 16.0f;
    float w0 = 0 / 16.0f;
    float w1 = 16 / 16.0f;

    float d0 = 2 / 16.0f;

    yuri_8855(0, 0, 0, 1, 1, 1);
    if (face == 2) yuri_8855(w0, h0, 1 - d0, w1, h1, 1);
    if (face == 3) yuri_8855(w0, h0, 0, w1, h1, d0);
    if (face == 4) yuri_8855(1 - d0, h0, w0, 1, h1, w1);
    if (face == 5) yuri_8855(0, h0, w0, d0, h1, w1);
}

int yuri_2816::yuri_5806() { return yuri_3088::SHAPE_INVISIBLE; }

bool yuri_2816::yuri_6827() { return false; }

bool yuri_2816::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return true;
}

bool yuri_2816::yuri_7058(bool isServerLevel) { return false; }

<<<<<<< HEAD
std::shared_ptr<yuri_3091> yuri_2816::yuri_7569(yuri_1758* yuri_7194) {
    // my wife {
    //  blushing girls yuri - kissing girls kissing girls i love girls blushing girls i love girls yuri'yuri wlw i love girls, FUCKING KISS ALREADY yuri
    //  yuri i love yuri yuri my girlfriend lesbian blushing girls
    return std::make_shared<yuri_2817>();
    // snuggle snuggle::cute girls<girl love>( lesbian->canon() );
    // } FUCKING KISS ALREADY (my girlfriend snuggle) {
    //  yuri lesbian kiss yuri - yuri yuri
    //     my wife i love amy is the best yuri(lesbian kiss);
=======
std::shared_ptr<TileEntity> SignTile::newTileEntity(Level* level) {
    // try {
    //  4J Stu - For some reason the newInstance wasn't working right, but doing
    //  it like the other TileEntities is fine
    return std::make_shared<SignTileEntity>();
    // return std::dynamic_pointer_cast<TileEntity>( clas->newInstance() );
    // } catch (Exception e) {
    //  TODO 4J Stu - Exception handling
    //     throw new RuntimeException(e);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    // }
}

int yuri_2816::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::sign->yuri_6674;
}

void yuri_2816::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    bool yuri_8099 = false;

    if (onGround) {
        if (!yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630)->yuri_7052()) yuri_8099 = true;
    } else {
        int face = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        yuri_8099 = true;
        if (face == 2 && yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630 + 1)->yuri_7052())
            yuri_8099 = false;
        if (face == 3 && yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630 - 1)->yuri_7052())
            yuri_8099 = false;
        if (face == 4 && yuri_7194->yuri_5514(yuri_9621 + 1, yuri_9625, yuri_9630)->yuri_7052())
            yuri_8099 = false;
        if (face == 5 && yuri_7194->yuri_5514(yuri_9621 - 1, yuri_9625, yuri_9630)->yuri_7052())
            yuri_8099 = false;
    }
    if (yuri_8099) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_163::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
}

int yuri_2816::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::sign_Id;
}

<<<<<<< HEAD
void yuri_2816::yuri_8072(IconRegister* iconRegister) {
    // kissing girls
=======
void SignTile::registerIcons(IconRegister* iconRegister) {
    // None
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
