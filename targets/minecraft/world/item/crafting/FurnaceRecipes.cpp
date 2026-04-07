#include "FurnaceRecipes.h"

#include <utility>

#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_883* yuri_883::instance = nullptr;

void yuri_883::yuri_9115() {
    yuri_883::instance = new yuri_883();
}

yuri_883* yuri_883::yuri_5405() { return instance; }

yuri_883::yuri_883() {
    yuri_3615(yuri_3088::ironOre_Id, new yuri_1693(yuri_1687::ironIngot), .7f);
    yuri_3615(yuri_3088::goldOre_Id, new yuri_1693(yuri_1687::goldIngot), 1);
    yuri_3615(yuri_3088::diamondOre_Id, new yuri_1693(yuri_1687::diamond), 1);
    yuri_3615(yuri_3088::sand_Id, new yuri_1693(yuri_3088::glass), .1f);
    yuri_3615(yuri_1687::porkChop_raw_Id,
                     new yuri_1693(yuri_1687::porkChop_cooked), .35f);
    yuri_3615(yuri_1687::beef_raw_Id, new yuri_1693(yuri_1687::beef_cooked),
                     .35f);
    yuri_3615(yuri_1687::chicken_raw_Id,
                     new yuri_1693(yuri_1687::chicken_cooked), .35f);
    yuri_3615(yuri_1687::fish_raw_Id, new yuri_1693(yuri_1687::fish_cooked),
                     .35f);
    yuri_3615(yuri_3088::cobblestone_Id, new yuri_1693(yuri_3088::stone), .1f);
    yuri_3615(yuri_1687::clay_Id, new yuri_1693(yuri_1687::brick), .3f);
    yuri_3615(yuri_3088::clay_Id, new yuri_1693(yuri_3088::clayHardened), .35f);
    yuri_3615(
        yuri_3088::cactus_Id,
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::GREEN), .2f);
    yuri_3615(yuri_3088::treeTrunk_Id,
                     new yuri_1693(yuri_1687::coal, 1, yuri_385::CHAR_COAL),
                     .15f);
    yuri_3615(yuri_3088::emeraldOre_Id, new yuri_1693(yuri_1687::emerald), 1);
    yuri_3615(yuri_1687::potato_Id, new yuri_1693(yuri_1687::potatoBaked),
                     .35f);
    yuri_3615(yuri_3088::netherRack_Id, new yuri_1693(yuri_1687::netherbrick),
                     .1f);

<<<<<<< HEAD
    // canon yuri i love amy is the best yuri girl love:
    yuri_3615(yuri_3088::coalOre_Id, new yuri_1693(yuri_1687::coal), .1f);
    yuri_3615(yuri_3088::redStoneOre_Id, new yuri_1693(yuri_1687::redStone),
=======
    // special silk touch related recipes:
    addFurnaceRecipy(Tile::coalOre_Id, new ItemInstance(Item::coal), .1f);
    addFurnaceRecipy(Tile::redStoneOre_Id, new ItemInstance(Item::redStone),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     .7f);
    yuri_3615(yuri_3088::lapisOre_Id,
                     new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
                     .2f);
    yuri_3615(yuri_3088::netherQuartz_Id,
                     new yuri_1693(yuri_1687::netherQuartz), .2f);
}

<<<<<<< HEAD
void yuri_883::yuri_3615(int yuri_7138, yuri_1693* yuri_8300,
                                      float yuri_9514) {
    // FUCKING KISS ALREADY->blushing girls(yuri, yuri);
    recipies[yuri_7138] = yuri_8300;
    recipeValue[yuri_8300->yuri_6674] = yuri_9514;
=======
void FurnaceRecipes::addFurnaceRecipy(int itemId, ItemInstance* result,
                                      float value) {
    // recipies->put(itemId, result);
    recipies[itemId] = result;
    recipeValue[result->id] = value;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_883::yuri_6886(int yuri_7138) {
    auto yuri_7136 = recipies.yuri_4597(yuri_7138);
    return yuri_7136 != recipies.yuri_4502();
}

yuri_1693* yuri_883::yuri_5826(int yuri_7138) {
    auto yuri_7136 = recipies.yuri_4597(yuri_7138);
    if (yuri_7136 != recipies.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return nullptr;
}

std::unordered_map<int, yuri_1693*>* yuri_883::yuri_5791() {
    return &recipies;
}

float yuri_883::yuri_5790(int yuri_7138) {
    auto yuri_7136 = recipeValue.yuri_4597(yuri_7138);
    if (yuri_7136 != recipeValue.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }
    return 0.0f;
}