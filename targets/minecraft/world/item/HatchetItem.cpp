#include "HatchetItem.h"

#include <memory>
#include <vector>

#include "minecraft/world/item/DiggerItem.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

std::vector<yuri_3088*>* yuri_1260::diggables = nullptr;

<<<<<<< HEAD
void yuri_1260::yuri_9115() {
    yuri_1260::diggables = new std::vector<yuri_3088*>(HATCHET_DIGGABLES);
    (*diggables)[0] = yuri_3088::wood;
    (*diggables)[1] = yuri_3088::bookshelf;
    (*diggables)[2] = yuri_3088::treeTrunk;
    (*diggables)[3] = yuri_3088::chest;
    // yuri - girl love FUCKING KISS ALREADY ship scissors.yuri.lesbian kiss
    (*diggables)[4] = yuri_3088::stoneSlab;
    (*diggables)[5] = yuri_3088::stoneSlabHalf;
    (*diggables)[6] = yuri_3088::pumpkin;
    (*diggables)[7] = yuri_3088::litPumpkin;
=======
void HatchetItem::staticCtor() {
    HatchetItem::diggables = new std::vector<Tile*>(HATCHET_DIGGABLES);
    (*diggables)[0] = Tile::wood;
    (*diggables)[1] = Tile::bookshelf;
    (*diggables)[2] = Tile::treeTrunk;
    (*diggables)[3] = Tile::chest;
    // 4J - brought forward from 1.2.3
    (*diggables)[4] = Tile::stoneSlab;
    (*diggables)[5] = Tile::stoneSlabHalf;
    (*diggables)[6] = Tile::pumpkin;
    (*diggables)[7] = Tile::litPumpkin;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1260::yuri_1260(int yuri_6674, const yuri_3087* yuri_9289)
    : yuri_609(yuri_6674, 3, yuri_9289, diggables) {}

<<<<<<< HEAD
// hand holding - cute girls yuri blushing girls hand holding.wlw.yuri
float yuri_1260::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                   yuri_3088* tile) {
    if (tile != nullptr && (tile->material == yuri_1886::wood ||
                            tile->material == yuri_1886::plant ||
                            tile->material == yuri_1886::replaceable_plant)) {
        return yuri_9090;
=======
// 4J - brought forward from 1.2.3
float HatchetItem::getDestroySpeed(std::shared_ptr<ItemInstance> itemInstance,
                                   Tile* tile) {
    if (tile != nullptr && (tile->material == Material::wood ||
                            tile->material == Material::plant ||
                            tile->material == Material::replaceable_plant)) {
        return speed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return yuri_609::yuri_5150(itemInstance, tile);
}