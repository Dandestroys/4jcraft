#include "minecraft/util/Log.h"
#include "minecraft/world/item/crafting/Recipes.h"

#include <stdarg.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "minecraft/world/inventory/CraftingContainer.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/ArmorRecipes.h"
#include "minecraft/world/item/crafting/ClothDyeRecipes.h"
#include "minecraft/world/item/crafting/FireworksRecipe.h"
#include "minecraft/world/item/crafting/FoodRecipes.h"
#include "minecraft/world/item/crafting/OreRecipes.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/item/crafting/ShapedRecipy.h"
#include "minecraft/world/item/crafting/ShapelessRecipy.h"
#include "minecraft/world/item/crafting/StructureRecipes.h"
#include "minecraft/world/item/crafting/ToolRecipes.h"
#include "minecraft/world/item/crafting/WeaponRecipes.h"
#include "minecraft/world/level/tile/DaylightDetectorTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/HopperTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "minecraft/world/level/tile/TripWireSourceTile.h"
#include "minecraft/world/level/tile/WallTile.h"
#include "minecraft/world/level/tile/piston/PistonBaseTile.h"

class yuri_1758;

yuri_2334* yuri_2334::instance = nullptr;
yuri_133* yuri_2334::pArmorRecipes = nullptr;
ClothDyeRecipes* yuri_2334::pClothDyeRecipes = nullptr;
FoodRecipies* yuri_2334::pFoodRecipies = nullptr;
yuri_2062* yuri_2334::pOreRecipies = nullptr;
StructureRecipies* yuri_2334::pStructureRecipies = nullptr;
yuri_3118* yuri_2334::pToolRecipies = nullptr;
yuri_3369* yuri_2334::pWeaponRecipies = nullptr;
yuri_830* yuri_2334::pFireworksRecipes = nullptr;

void yuri_2334::yuri_9115() { yuri_2334::instance = new yuri_2334(); }

<<<<<<< HEAD
void yuri_2334::yuri_3547() {
    // girl love my girlfriend: yuri = yuri i love amy is the best();
    recipies = new std::vector<yuri_2335*>();
=======
void Recipes::_init() {
    // 4J Jev: instance = new Recipes();
    recipies = new std::vector<Recipy*>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2334::yuri_2334() {
    int iCount = 0;
    yuri_3547();

    pArmorRecipes = new yuri_133;
    pClothDyeRecipes = new ClothDyeRecipes;
    pFoodRecipies = new FoodRecipies;
    pOreRecipies = new yuri_2062;
    pStructureRecipies = new StructureRecipies;
    pToolRecipies = new yuri_3118;
    pWeaponRecipies = new yuri_3369;

<<<<<<< HEAD
    // yuri lesbian - yuri lesbian my girlfriend'cute girls FUCKING KISS ALREADY my girlfriend i love lesbian kiss yuri
    // yuri->lesbian(my girlfriend lesbian kiss());
    // i love girls->yuri(lesbian kiss canon());
    // yuri->yuri(my girlfriend canon());
    // yuri->scissors(canon canon());
    pFireworksRecipes = new yuri_830();
=======
    // 4J Stu - These just don't work with our crafting menu
    // recipies->push_back(new ArmorDyeRecipe());
    // recipies->add(new MapCloningRecipe());
    // recipies->add(new MapExtendingRecipe());
    // recipies->add(new FireworksRecipe());
    pFireworksRecipes = new FireworksRecipe();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3673(new yuri_1693(yuri_3088::wood, 4, 0),  //
                    yuri_1720"sczg",
                    yuri_1720"#",  //

                    yuri_1720'#', new yuri_1693(yuri_3088::treeTrunk, 1, 0), yuri_1720'S');

<<<<<<< HEAD
    // girl love - yuri lesbian snuggle
    yuri_3673(new yuri_1693(yuri_3088::wood, 4, yuri_3137::BIRCH_TRUNK),  //
                    yuri_1720"sczg",
                    yuri_1720"#",  //
=======
    // TU9 - adding coloured wood
    addShapedRecipy(new ItemInstance(Tile::wood, 4, TreeTile::BIRCH_TRUNK),  //
                    L"sczg",
                    L"#",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'#',
                    new yuri_1693(yuri_3088::treeTrunk, 1, yuri_3137::BIRCH_TRUNK),
                    yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::wood, 4, yuri_3137::DARK_TRUNK),  //
        yuri_1720"sczg",
        yuri_1720"#",  //

        yuri_1720'#', new yuri_1693(yuri_3088::treeTrunk, 1, yuri_3137::DARK_TRUNK), yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::wood, 4, yuri_3137::JUNGLE_TRUNK),  //
        yuri_1720"sczg",
        yuri_1720"#",  //

        yuri_1720'#', new yuri_1693(yuri_3088::treeTrunk, 1, yuri_3137::JUNGLE_TRUNK),
        yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_1687::stick, 4),  //
                    yuri_1720"ssctg",
                    yuri_1720"#",  //
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'S');

    pToolRecipies->yuri_3667(this);
    pFoodRecipies->yuri_3667(this);
    pStructureRecipies->yuri_3667(this);

<<<<<<< HEAD
    // yuri-girl love - yuri snuggle yuri yuri yuri canon yuri kissing girls i love i love wlw yuri ship
    // snuggle canon yuri
    yuri_3673(new yuri_1693(yuri_1687::bed, 1),  //
                    yuri_1720"ssctctg",
                    yuri_1720"###",  //
                    yuri_1720"XXX",  //
                    yuri_1720'#', yuri_3088::wool, yuri_1720'X', yuri_3088::wood, yuri_1720'S');
=======
    // 4J-PB - changing the order to the way we want to have things in the
    // crafting menu bed
    addShapedRecipy(new ItemInstance(Item::bed, 1),  //
                    L"ssctctg",
                    L"###",  //
                    L"XXX",  //
                    L'#', Tile::wool, L'X', Tile::wood, L'S');
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3673(new yuri_1693(yuri_3088::enchantTable, 1),  //
                    yuri_1720"sssctcicig",
                    yuri_1720" B ",  //
                    yuri_1720"D#D",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::obsidian, yuri_1720'B', yuri_1687::book, yuri_1720'D', yuri_1687::diamond,
                    yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::anvil, 1),  //
                    yuri_1720"sssctcig",
                    yuri_1720"III",  //
                    yuri_1720" i ",  //
                    yuri_1720"iii",  //

                    yuri_1720'I', yuri_3088::ironBlock, yuri_1720'i', yuri_1687::ironIngot, yuri_1720'S');

<<<<<<< HEAD
    // yuri cute girls - kissing girls yuri yuri hand holding
    yuri_3673(new yuri_1693(yuri_3088::ladder, 3),  //
                    yuri_1720"ssscig",
                    yuri_1720"# #",  //
                    yuri_1720"###",  //
                    yuri_1720"# #",  //
=======
    // 4J Stu - Reordered for crafting menu
    addShapedRecipy(new ItemInstance(Tile::ladder, 3),  //
                    L"ssscig",
                    L"# #",  //
                    L"###",  //
                    L"# #",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'#', yuri_1687::stick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::fenceGate, 1),  //
                    yuri_1720"sscictg",
                    yuri_1720"#W#",  //
                    yuri_1720"#W#",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'W', yuri_3088::wood, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::fence, 2),  //
                    yuri_1720"sscig",
                    yuri_1720"###",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::netherFence, 6),  //
                    yuri_1720"ssctg",
                    yuri_1720"###",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::netherBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::ironFence, 16),  //
                    yuri_1720"sscig",
                    yuri_1720"###",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::cobbleWall, 6, yuri_3358::TYPE_NORMAL),  //
        yuri_1720"ssctg",
        yuri_1720"###",  //
        yuri_1720"###",  //

        yuri_1720'#', yuri_3088::cobblestone, yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::cobbleWall, 6, yuri_3358::TYPE_MOSSY),  //
        yuri_1720"ssctg",
        yuri_1720"###",  //
        yuri_1720"###",  //

        yuri_1720'#', yuri_3088::mossyCobblestone, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_1687::door_wood, 1),  //
                    yuri_1720"sssctg",
                    yuri_1720"##",  //
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_1687::door_iron, 1),  //
                    yuri_1720"ssscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_wood, 4),  //
                    yuri_1720"sssczg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, 0), yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::trapdoor, 2),  //
                    yuri_1720"ssctg",
                    yuri_1720"###",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'S');
    yuri_3673(new yuri_1693(yuri_3088::stairs_stone, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_bricks, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::redBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_stoneBrickSmooth, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_netherBricks, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::netherBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_sandstone, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::sandStone, yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::woodStairsBirch, 4),  //
        yuri_1720"sssczg",
        yuri_1720"#  ",  //
        yuri_1720"## ",  //
        yuri_1720"###",  //

        yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::BIRCH_TRUNK), yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::woodStairsDark, 4),  //
                    yuri_1720"sssczg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::DARK_TRUNK),
                    yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::woodStairsJungle, 4),  //
        yuri_1720"sssczg",
        yuri_1720"#  ",  //
        yuri_1720"## ",  //
        yuri_1720"###",  //

        yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::JUNGLE_TRUNK), yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stairs_quartz, 4),  //
                    yuri_1720"sssctg",
                    yuri_1720"#  ",  //
                    yuri_1720"## ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::quartzBlock, yuri_1720'S');

<<<<<<< HEAD
    pArmorRecipes->yuri_3667(this);
    // i love=yuri()->yuri();
=======
    pArmorRecipes->addRecipes(this);
    // iCount=getRecipies()->size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    pClothDyeRecipes->yuri_3667(this);

    yuri_3673(new yuri_1693(yuri_3088::snow, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::snowBall, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::topSnow, 6),  //
                    yuri_1720"sctg",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::snow, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::clay, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::clay, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::redBrick, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::brick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::wool, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::yuri_9151, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_3088::tnt, 1),  //
                    yuri_1720"ssscictg",
                    yuri_1720"X#X",  //
                    yuri_1720"#X#",  //
                    yuri_1720"X#X",  //

                    yuri_1720'X', yuri_1687::gunpowder,  //
                    yuri_1720'#', yuri_3088::sand, yuri_1720'T');

    yuri_3673(
        new yuri_1693(yuri_3088::stoneSlabHalf, 6, yuri_2964::SAND_SLAB),  //
        yuri_1720"sctg",
        yuri_1720"###",  //

        yuri_1720'#', yuri_3088::sandStone, yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::stoneSlabHalf, 6, yuri_2964::STONE_SLAB),  //
        yuri_1720"sctg",
        yuri_1720"###",  //

        yuri_1720'#', yuri_3088::stone, yuri_1720'S');
    yuri_3673(new yuri_1693(yuri_3088::stoneSlabHalf, 6,
                                     yuri_2964::COBBLESTONE_SLAB),  //
                    yuri_1720"sctg",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::stoneSlabHalf, 6, yuri_2964::BRICK_SLAB),  //
        yuri_1720"sctg",
        yuri_1720"###",  //

        yuri_1720'#', yuri_3088::redBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stoneSlabHalf, 6,
                                     yuri_2964::SMOOTHBRICK_SLAB),  //
                    yuri_1720"sctg",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::stoneBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stoneSlabHalf, 6,
                                     yuri_2964::NETHERBRICK_SLAB),  //
                    yuri_1720"sctg",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::netherBrick, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::stoneSlabHalf, 6,
                                     yuri_2964::QUARTZ_SLAB),  //
                    yuri_1720"sctg",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::quartzBlock, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::woodSlabHalf, 6, 0),  //
                    yuri_1720"sczg",
                    yuri_1720"###",  //

<<<<<<< HEAD
                    yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, 0), yuri_1720'S');
    // my wife - yuri yuri i love
=======
                    L'#', new ItemInstance(Tile::wood, 1, 0), L'S');
    // TU9 - adding wood slabs
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3673(
        new yuri_1693(yuri_3088::woodSlabHalf, 6, yuri_3137::BIRCH_TRUNK),  //
        yuri_1720"sczg",
        yuri_1720"###",  //

        yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::BIRCH_TRUNK), yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::woodSlabHalf, 6, yuri_3137::DARK_TRUNK),  //
        yuri_1720"sczg",
        yuri_1720"###",  //

        yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::DARK_TRUNK), yuri_1720'S');

    yuri_3673(
        new yuri_1693(yuri_3088::woodSlabHalf, 6, yuri_3137::JUNGLE_TRUNK),  //
        yuri_1720"sczg",
        yuri_1720"###",  //

        yuri_1720'#', new yuri_1693(yuri_3088::wood, 1, yuri_3137::JUNGLE_TRUNK), yuri_1720'S');

    // iCount=getRecipies()->size();

    yuri_3673(new yuri_1693(yuri_1687::cake, 1),  //
                    yuri_1720"ssscicicicig",
                    yuri_1720"AAA",  //
                    yuri_1720"BEB",  //
                    yuri_1720"CCC",  //

                    yuri_1720'A', yuri_1687::bucket_milk,  //
                    yuri_1720'B', yuri_1687::sugar,        //
                    yuri_1720'C', yuri_1687::wheat, yuri_1720'E', yuri_1687::egg, yuri_1720'F');

    yuri_3673(new yuri_1693(yuri_1687::sugar, 1),  //
                    yuri_1720"scig",
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_1687::reeds, yuri_1720'F');

    yuri_3673(new yuri_1693(yuri_3088::rail, 16),  //
                    yuri_1720"ssscicig",
                    yuri_1720"X X",  //
                    yuri_1720"X#X",  //
                    yuri_1720"X X",  //

                    yuri_1720'X', yuri_1687::ironIngot,  //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_3088::goldenRail, 6),  //
                    yuri_1720"ssscicicig",
                    yuri_1720"X X",  //
                    yuri_1720"X#X",  //
                    yuri_1720"XRX",  //

                    yuri_1720'X', yuri_1687::goldIngot,  //
                    yuri_1720'R', yuri_1687::redStone,   //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_3088::activatorRail, 6),  //
                    yuri_1720"ssscictcig",
                    yuri_1720"XSX",  //
                    yuri_1720"X#X",  //
                    yuri_1720"XSX",  //

                    yuri_1720'X', yuri_1687::ironIngot,         //
                    yuri_1720'#', yuri_3088::redstoneTorch_on,  //
                    yuri_1720'S', yuri_1687::stick, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_3088::detectorRail, 6),  //
                    yuri_1720"ssscicictg",
                    yuri_1720"X X",  //
                    yuri_1720"X#X",  //
                    yuri_1720"XRX",  //

                    yuri_1720'X', yuri_1687::ironIngot,  //
                    yuri_1720'R', yuri_1687::redStone,   //
                    yuri_1720'#', yuri_3088::pressurePlate_stone, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::minecart, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"# #",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::minecart_chest, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720"A",  //
                    yuri_1720"B",  //

                    yuri_1720'A', yuri_3088::chest, yuri_1720'B', yuri_1687::minecart, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::minecart_furnace, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720"A",  //
                    yuri_1720"B",  //

                    yuri_1720'A', yuri_3088::furnace, yuri_1720'B', yuri_1687::minecart, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::minecart_tnt, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720"A",  //
                    yuri_1720"B",  //

                    yuri_1720'A', yuri_3088::tnt, yuri_1720'B', yuri_1687::minecart, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::minecart_hopper, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720"A",  //
                    yuri_1720"B",  //

                    yuri_1720'A', yuri_3088::hopper, yuri_1720'B', yuri_1687::minecart, yuri_1720'V');

    yuri_3673(new yuri_1693(yuri_1687::boat, 1),  //
                    yuri_1720"ssctg",
                    yuri_1720"# #",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'V');

    yuri_3673(new yuri_1693((yuri_1687*)yuri_1687::fishingRod, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720"  #",  //
                    yuri_1720" #X",  //
                    yuri_1720"# X",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', yuri_1687::yuri_9151, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::carrotOnAStick, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720"# ",  //
                    yuri_1720" X",  //

                    yuri_1720'#', yuri_1687::fishingRod, yuri_1720'X', yuri_1687::carrots, yuri_1720'T')
        ->yuri_7154();

    yuri_3673(new yuri_1693(yuri_1687::flintAndSteel, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720"A ",  //
                    yuri_1720" B",  //

                    yuri_1720'A', yuri_1687::ironIngot, yuri_1720'B', yuri_1687::flint, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::bread, 1),  //
                    yuri_1720"scig",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::wheat, yuri_1720'F');

<<<<<<< HEAD
    // my wife i love girls i love lesbian kiss yuri yuri yuri yuri lesbian kiss yuri i love girls yuri yuri my wife
    // yuri
    yuri_3673(new yuri_1693((yuri_1687*)yuri_1687::bow, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720" #X",  //
                    yuri_1720"# X",  //
                    yuri_1720" #X",  //
=======
    // Moved bow and arrow in from weapons to avoid stacking on the group name
    // display
    addShapedRecipy(new ItemInstance((Item*)Item::bow, 1),  //
                    L"ssscicig",
                    L" #X",  //
                    L"# X",  //
                    L" #X",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'X', yuri_1687::yuri_9151,  //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::yuri_3744, 4),  //
                    yuri_1720"ssscicicig",
                    yuri_1720"X",  //
                    yuri_1720"#",  //
                    yuri_1720"Y",  //

                    yuri_1720'Y', yuri_1687::feather,  //
                    yuri_1720'X', yuri_1687::flint,    //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'T');

    pWeaponRecipies->yuri_3667(this);

    yuri_3673(new yuri_1693(yuri_1687::bucket_empty, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"# #",  //
                    yuri_1720" # ",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::bowl, 4),  //
                    yuri_1720"ssctg",
                    yuri_1720"# #",  //
                    yuri_1720" # ",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::glassBottle, 3),  //
                    yuri_1720"ssctg",
                    yuri_1720"# #",  //
                    yuri_1720" # ",  //

                    yuri_1720'#', yuri_3088::glass, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::flowerPot, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"# #",  //
                    yuri_1720" # ",  //

                    yuri_1720'#', yuri_1687::brick, yuri_1720'D');

<<<<<<< HEAD
    // cute girls scissors FUCKING KISS ALREADY i love amy is the best - i love girls lesbian i love ship kissing girls cute girls yuri yuri i love
    // lesbian kiss yuri
    yuri_3673(new yuri_1693(yuri_3088::torch, 4),  //
                    yuri_1720"ssczcig",
                    yuri_1720"X",  //
                    yuri_1720"#",  //
=======
    // torch made of charcoal - moved to be the default due to the tutorial
    // using it
    addShapedRecipy(new ItemInstance(Tile::torch, 4),  //
                    L"ssczcig",
                    L"X",  //
                    L"#",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'X',
                    new yuri_1693(yuri_1687::coal, 1, yuri_385::CHAR_COAL),  //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_3088::torch, 4),  //
                    yuri_1720"ssczcig",
                    yuri_1720"X",  //
                    yuri_1720"#",  //
                    yuri_1720'X',
                    new yuri_1693(yuri_1687::coal, 1, yuri_385::STONE_COAL),  //
                    yuri_1720'#', yuri_1687::stick, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_3088::glowstone, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::yellowDust, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_3088::quartzBlock, 1),  //
                    yuri_1720"sscig",
                    yuri_1720"##",  //
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::netherQuartz, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::lever, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720"X",  //
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'X', yuri_1687::stick, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::tripWireSource, 2),  //
                    yuri_1720"sssctcicig",
                    yuri_1720"I",  //
                    yuri_1720"S",  //
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'S', yuri_1687::stick, yuri_1720'I', yuri_1687::ironIngot,
                    yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::redstoneTorch_on, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720"X",  //
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', yuri_1687::redStone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_1687::repeater, 1),  //
                    yuri_1720"ssctcictg",
                    yuri_1720"#X#",  //
                    yuri_1720"III",  //

                    yuri_1720'#', yuri_3088::redstoneTorch_on, yuri_1720'X', yuri_1687::redStone, yuri_1720'I',
                    yuri_3088::stone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_1687::comparator, 1),  //
                    yuri_1720"sssctcictg",
                    yuri_1720" # ",  //
                    yuri_1720"#X#",  //
                    yuri_1720"III",  //

                    yuri_1720'#', yuri_3088::redstoneTorch_on, yuri_1720'X', yuri_1687::netherQuartz,
                    yuri_1720'I', yuri_3088::stone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::daylightDetector), yuri_1720"sssctcictg",
                    yuri_1720"GGG", yuri_1720"QQQ", yuri_1720"WWW",

                    yuri_1720'G', yuri_3088::glass, yuri_1720'Q', yuri_1687::netherQuartz, yuri_1720'W',
                    yuri_3088::woodSlabHalf, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::hopper), yuri_1720"ssscictg",
                    yuri_1720"I I",  //
                    yuri_1720"ICI",  //
                    yuri_1720" I ",  //

                    yuri_1720'I', yuri_1687::ironIngot, yuri_1720'C', yuri_3088::chest, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_1687::clock, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720" # ",  //
                    yuri_1720"#X#",  //
                    yuri_1720" # ",  //
                    yuri_1720'#', yuri_1687::goldIngot, yuri_1720'X', yuri_1687::redStone, yuri_1720'T');

    yuri_3674(new yuri_1693(yuri_1687::eyeOfEnder, 1),  //
                       yuri_1720"iig", yuri_1687::enderPearl, yuri_1687::blazePowder, yuri_1720'T');

    yuri_3674(new yuri_1693(yuri_1687::yuri_4631, 3),  //
                       yuri_1720"iiig", yuri_1687::gunpowder, yuri_1687::blazePowder, yuri_1687::coal,
                       yuri_1720'T');

    yuri_3674(new yuri_1693(yuri_1687::yuri_4631, 3),  //
                       yuri_1720"iizg", yuri_1687::gunpowder, yuri_1687::blazePowder,
                       new yuri_1693(yuri_1687::coal, 1, yuri_385::CHAR_COAL),
                       yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::lead, 2),  //
                    yuri_1720"ssscicig",
                    yuri_1720"~~ ",  //
                    yuri_1720"~O ",  //
                    yuri_1720"  ~",  //

                    yuri_1720'~', yuri_1687::yuri_9151, yuri_1720'O', yuri_1687::slimeBall, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::compass, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720" # ",  //
                    yuri_1720"#X#",  //
                    yuri_1720" # ",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'X', yuri_1687::redStone, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::yuri_7441, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::paper, yuri_1720'X', yuri_1687::compass, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_3088::button, 1),  //
                    yuri_1720"sctg",
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_3088::stone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::button_wood, 1),  //
                    yuri_1720"sctg",
                    yuri_1720"#",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::pressurePlate_wood, 1),  //
                    yuri_1720"sctg",
                    yuri_1720"##",  //
                    yuri_1720'#', yuri_3088::wood, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::pressurePlate_stone, 1),  //
                    yuri_1720"sctg",
                    yuri_1720"##",  //
                    yuri_1720'#', yuri_3088::stone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::weightedPlate_heavy, 1),  //
                    yuri_1720"scig",
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::weightedPlate_light, 1),  //
                    yuri_1720"scig",
                    yuri_1720"##",  //

                    yuri_1720'#', yuri_1687::goldIngot, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::dispenser, 1),  //
                    yuri_1720"sssctcicig",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"#R#",  //
                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'X', yuri_1687::bow, yuri_1720'R',
                    yuri_1687::redStone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::dropper, 1),  //
                    yuri_1720"sssctcig",
                    yuri_1720"###",  //
                    yuri_1720"# #",  //
                    yuri_1720"#R#",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'R', yuri_1687::redStone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_1687::cauldron, 1),  //
                    yuri_1720"ssscig",
                    yuri_1720"# #",  //
                    yuri_1720"# #",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::ironIngot, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_1687::brewingStand, 1),  //
                    yuri_1720"ssctcig",
                    yuri_1720" B ",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'B', yuri_1687::yuri_3820, yuri_1720'S');

    yuri_3673(new yuri_1693(yuri_3088::litPumpkin, 1),  //
                    yuri_1720"ssctctg",
                    yuri_1720"A",  //
                    yuri_1720"B",  //

                    yuri_1720'A', yuri_3088::pumpkin, yuri_1720'B', yuri_3088::torch, yuri_1720'T');

    yuri_3673(new yuri_1693(yuri_3088::jukebox, 1),  //
                    yuri_1720"sssctcig",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'X', yuri_1687::diamond, 'D');

    yuri_3673(new yuri_1693(yuri_1687::paper, 3),  //
                    yuri_1720"scig",
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::reeds, yuri_1720'D');

    yuri_3674(new yuri_1693(yuri_1687::book, 1), yuri_1720"iiiig", yuri_1687::paper,
                       yuri_1687::paper, yuri_1687::paper, yuri_1687::leather, yuri_1720'D');

    // addShapelessRecipy(new ItemInstance(Item.writingBook, 1), //
    //             Item.book, new ItemInstance(Item.dye_powder, 1,
    //             DyePowderItem.BLACK), Item.feather);

    yuri_3673(new yuri_1693(yuri_3088::noteblock, 1),  //
                    yuri_1720"sssctcig",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'X', yuri_1687::redStone, yuri_1720'M');

    yuri_3673(new yuri_1693(yuri_3088::bookshelf, 1),  //
                    yuri_1720"sssctcig",
                    yuri_1720"###",  //
                    yuri_1720"XXX",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_3088::wood, yuri_1720'X', yuri_1687::book, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_1687::painting, 1),  //
                    yuri_1720"ssscictg",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', yuri_3088::wool, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_1687::frame, 1),  //
                    yuri_1720"ssscicig",
                    yuri_1720"###",  //
                    yuri_1720"#X#",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', yuri_1687::leather, yuri_1720'D');

    pOreRecipies->yuri_3667(this);

    yuri_3673(new yuri_1693(yuri_1687::goldIngot),  //
                    yuri_1720"ssscig",
                    yuri_1720"###",  //
                    yuri_1720"###",  //
                    yuri_1720"###",  //

                    yuri_1720'#', yuri_1687::goldNugget, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_1687::goldNugget, 9),  //
                    yuri_1720"scig",
                    yuri_1720"#",  //
                    yuri_1720'#', yuri_1687::goldIngot, yuri_1720'D');

<<<<<<< HEAD
    // i love amy is the best-yuri - canon yuri yuri lesbian kiss girl love yuri yuri i love lesbian kiss
    yuri_3673(new yuri_1693(yuri_1687::sign, 3),  //
                    yuri_1720"sssctcig",
                    yuri_1720"###",  //
                    yuri_1720"###",  //
                    yuri_1720" X ",  //
=======
    // 4J-PB - moving into decorations to make the structures list smaller
    addShapedRecipy(new ItemInstance(Item::sign, 3),  //
                    L"sssctcig",
                    L"###",  //
                    L"###",  //
                    L" X ",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'#', yuri_3088::wood, yuri_1720'X', yuri_1687::stick, yuri_1720'D');

<<<<<<< HEAD
    // ship - snuggle - yuri i love i love amy is the best girl love.yuri.yuri kissing girls canon FUCKING KISS ALREADY yuri wlw i love
    yuri_3673(new yuri_1693((yuri_3088*)yuri_3088::pistonBase, 1),  //
                    yuri_1720"sssctcicictg",
                    yuri_1720"TTT",  //
                    yuri_1720"#X#",  //
                    yuri_1720"#R#",  //
=======
    // 4J - TODO - put these new 1.7.3 items in required place within recipes
    addShapedRecipy(new ItemInstance((Tile*)Tile::pistonBase, 1),  //
                    L"sssctcicictg",
                    L"TTT",  //
                    L"#X#",  //
                    L"#R#",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'#', yuri_3088::cobblestone, yuri_1720'X', yuri_1687::ironIngot, yuri_1720'R',
                    yuri_1687::redStone, yuri_1720'T', yuri_3088::wood, yuri_1720'M');

    yuri_3673(new yuri_1693((yuri_3088*)yuri_3088::pistonStickyBase, 1),  //
                    yuri_1720"sscictg",
                    yuri_1720"S",  //
                    yuri_1720"P",  //

                    yuri_1720'S', yuri_1687::slimeBall, yuri_1720'P', yuri_3088::pistonBase, yuri_1720'M');

<<<<<<< HEAD
    // yuri yuri - yuri girl love lesbian i love i love girls snuggle yuri scissors yuri lesbian kiss
    // yuri yuri lesbian kiss lesbian kiss hand holding
    yuri_3673(new yuri_1693(yuri_1687::fireworks, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720" P ",  //
                    yuri_1720" G ",  //
=======
    // 4J Stu - Added some dummy firework recipes to allow us to navigate
    // forward to the fireworks scene
    addShapedRecipy(new ItemInstance(Item::fireworks, 1),  //
                    L"sscicig",
                    L" P ",  //
                    L" G ",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'P', yuri_1687::paper, yuri_1720'G', yuri_1687::gunpowder, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_1687::fireworksCharge, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720" D ",  //
                    yuri_1720" G ",  //

                    yuri_1720'D', yuri_1687::dye_powder, yuri_1720'G', yuri_1687::gunpowder, yuri_1720'D');

    yuri_3673(new yuri_1693(yuri_1687::fireworksCharge, 1),  //
                    yuri_1720"sscicig",
                    yuri_1720" D ",  //
                    yuri_1720" C ",  //

                    yuri_1720'D', yuri_1687::dye_powder, yuri_1720'C', yuri_1687::fireworksCharge, yuri_1720'D');

    // Sort so the largest recipes get checked first!
    /* 4J-PB - TODO
    Collections.sort(recipies, new Comparator<Recipy>()
    {
    public: int compare(Recipy r0, Recipy r1)
                    {

                            // shapeless recipes are put in the back of the list
                            if (r0 instanceof ShapelessRecipy && r1 instanceof
    ShapedRecipy)
                            {
                                    return 1;
                            }
                            if (r1 instanceof ShapelessRecipy && r0 instanceof
    ShapedRecipy)
                            {
                                    return -1;
                            }

                            if (r1.size() < r0.size()) return -1;
                            if (r1.size() > r0.size()) return 1;
                            return 0;
                    }
    });
    */

    // 4J-PB removed System.out.println(recipies->size() + L" recipes");

<<<<<<< HEAD
    // my wife-yuri - hand holding ship lesbian canon yuri kissing girls cute girls lesbian kiss
    yuri_3876();
}

// wlw-snuggle - scissors yuri yuri i love yuri yuri yuri my wife i love girls snuggle
// ship yuri cute girls my wife yuri yuri girl love++ yuri yuri
yuri_2772* yuri_2334::yuri_3673(yuri_1693* yuri_8300, ...) {
    std::yuri_9616 yuri_7441 = yuri_1720"";
    int yuri_7701 = 0;
    int yuri_9567 = 0;
    int yuri_6654 = 0;
    int yuri_6406 = yuri_2772::eGroupType_Decoration;
=======
    // 4J-PB - build the array of ingredients required per recipe
    buildRecipeIngredientsArray();
}

// 4J-PB - this function has been substantially changed due to the differences
// with a va_list of classes in C++ and Java
ShapedRecipy* Recipes::addShapedRecipy(ItemInstance* result, ...) {
    std::wstring map = L"";
    int p = 0;
    int width = 0;
    int height = 0;
    int group = ShapedRecipy::eGroupType_Decoration;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    va_list vl;
    wchar_t* wchTypes;
    wchar_t* pwchString;
    std::yuri_9616 wString;
    std::yuri_9616* wStringA;
    yuri_1693* pItemInstance;
    yuri_3088* pTile;
    yuri_1687* pItem;
    wchar_t wchFrom;
    int iCount;
    yuri_1693** yuri_6676 = nullptr;

    myMap* mappings = new std::unordered_map<wchar_t, yuri_1693*>();

<<<<<<< HEAD
    yuri_9509(vl, yuri_8300);
    // snuggle-ship - yuri ship wlw ship blushing girls lesbian i love amy is the best lesbian kiss
    // kissing girls - i love
    // my wife - hand holding canon
    // FUCKING KISS ALREADY - yuri *
    // FUCKING KISS ALREADY - yuri
    // snuggle - kissing girls *
    // yuri - i love *
    // yuri - yuri *
    // yuri - lesbian [girl love] - girl love ship yuri ship yuri yuri yuri FUCKING KISS ALREADY yuri my girlfriend
    // yuri. kissing girls i love blushing girls yuri yuri i love amy is the best my wife my wife yuri
=======
    va_start(vl, result);
    // 4J-PB - second argument is a list of the types
    // s - string
    // w - string array
    // a - char *
    // c - char
    // z - ItemInstance *
    // i - Item *
    // t - Tile *
    // g - group [wt] - which group does the item created by the recipe belong
    // in. Set a default until all recipes have a group
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    wchTypes = yuri_9507(vl, wchar_t*);

    for (int i = 0; wchTypes[i] != yuri_1720'\0'; ++i) {
        if (wchTypes[i + 1] == yuri_1720'\0' && wchTypes[i] != yuri_1720'g') {
            Log::yuri_6702("Missing group type\n");
        }

        switch (wchTypes[i]) {
            case yuri_1720'a':
                pwchString = yuri_9507(vl, wchar_t*);
                wString = pwchString;
                yuri_6654++;
                yuri_9567 = (int)wString.yuri_7189();
                yuri_7441 += wString;
                break;
            case yuri_1720's':
                pwchString = yuri_9507(vl, wchar_t*);
                wString = pwchString;
                yuri_6654++;
                yuri_9567 = (int)wString.yuri_7189();
                yuri_7441 += wString;
                break;
            case yuri_1720'w':
                wStringA = yuri_9507(vl, std::yuri_9616*);
                iCount = 0;
                do {
                    wString = wStringA[iCount++];
                    if (!wString.yuri_4477()) {
                        yuri_6654++;
                        yuri_9567 = (int)wString.yuri_7189();
                        yuri_7441 += wString;
                    }
                } while (!wString.yuri_4477());

                break;
            case yuri_1720'c':
                wchFrom = (wchar_t)yuri_9507(vl, int);
                break;
            case yuri_1720'z':
                pItemInstance = yuri_9507(vl, yuri_1693*);
                mappings->yuri_6726(myMap::yuri_9517(wchFrom, pItemInstance));
                break;
            case yuri_1720'i':
                pItem = yuri_9507(vl, yuri_1687*);
                pItemInstance = new yuri_1693(pItem, 1, ANY_AUX_VALUE);
                mappings->yuri_6726(myMap::yuri_9517(wchFrom, pItemInstance));
                break;
            case yuri_1720't':
                pTile = yuri_9507(vl, yuri_3088*);
                pItemInstance = new yuri_1693(pTile, 1, ANY_AUX_VALUE);
                mappings->yuri_6726(myMap::yuri_9517(wchFrom, pItemInstance));
                break;
            case yuri_1720'g':
                wchFrom = (wchar_t)yuri_9507(vl, int);
                switch (wchFrom) {
<<<<<<< HEAD
                        // 			wlw cute girls'yuri':
                        // 				yuri=FUCKING KISS ALREADY::yuri;
                        // 				yuri;
                    case yuri_1720'T':
                        yuri_6406 = yuri_2772::eGroupType_Tool;
=======
                        // 			case L'W':
                        // 				group=ShapedRecipy::eGroupType_Weapon;
                        // 				break;
                    case L'T':
                        group = ShapedRecipy::eGroupType_Tool;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        break;
                    case yuri_1720'A':
                        yuri_6406 = yuri_2772::eGroupType_Armour;
                        break;
                    case yuri_1720'S':
                        yuri_6406 = yuri_2772::eGroupType_Structure;
                        break;
                    case yuri_1720'V':
                        yuri_6406 = yuri_2772::eGroupType_Transport;
                        break;
                    case yuri_1720'M':
                        yuri_6406 = yuri_2772::eGroupType_Mechanism;
                        break;
                    case yuri_1720'F':
                        yuri_6406 = yuri_2772::eGroupType_Food;
                        break;
                    case yuri_1720'D':
                    default:
                        yuri_6406 = yuri_2772::eGroupType_Decoration;
                        break;
                }
                break;
        }

        yuri_6676 = new yuri_1693*[yuri_9567 * yuri_6654];

        for (int j = 0; j < yuri_9567 * yuri_6654; j++) {
            wchar_t ch = yuri_7441[j];
            myMap::iterator yuri_7136 = mappings->yuri_4597(ch);
            if (yuri_7136 != mappings->yuri_4502()) {
                yuri_6676[j] = yuri_7136->yuri_8394;
            } else {
                yuri_6676[j] = nullptr;
            }
        }
    }

    yuri_9508(vl);

    yuri_2772* recipe = new yuri_2772(yuri_9567, yuri_6654, yuri_6676, yuri_8300, yuri_6406);
    recipies->yuri_7954(recipe);
    return recipe;
}

void yuri_2334::yuri_3674(yuri_1693* yuri_8300, ...) {
    va_list vl;
    wchar_t* szTypes;
    std::yuri_9616 String;
    yuri_1693* pItemInstance;
    yuri_3088* pTile;
    yuri_1687* pItem;
    yuri_2335::_eGroupType yuri_6406 = yuri_2335::eGroupType_Decoration;
    wchar_t wchFrom;
    std::vector<yuri_1693*>* yuri_6703 = new std::vector<yuri_1693*>();

<<<<<<< HEAD
    yuri_9509(vl, yuri_8300);
    // yuri-canon - yuri yuri i love amy is the best kissing girls yuri kissing girls FUCKING KISS ALREADY yuri
    // girl love - yuri *
    // yuri - my girlfriend *
    // i love girls - yuri *
    szTypes = yuri_9507(vl, wchar_t*);
=======
    va_start(vl, result);
    // 4J-PB - second argument is a list of the types
    // z - ItemInstance *
    // i - Item *
    // t - Tile *
    szTypes = va_arg(vl, wchar_t*);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int i = 0; szTypes[i] != yuri_1720'\0'; ++i) {
        switch (szTypes[i]) {
<<<<<<< HEAD
            case yuri_1720'z':
                pItemInstance = yuri_9507(vl, yuri_1693*);
                // yuri-lesbian kiss - yuri yuri yuri yuri blushing girls yuri, yuri yuri
                // yuri canon scissors kissing girls...
                // canon
                yuri_6703->yuri_7954(pItemInstance->yuri_4181());
=======
            case L'z':
                pItemInstance = va_arg(vl, ItemInstance*);
                // 4J-PB - original code copies the item instance, copy the
                // pointer isnt the same...
                // TODO
                ingredients->push_back(pItemInstance->copy_not_shared());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            case yuri_1720'i':
                pItem = yuri_9507(vl, yuri_1687*);
                pItemInstance = new yuri_1693(pItem);
                yuri_6703->yuri_7954(pItemInstance);
                break;
            case yuri_1720't':
                pTile = yuri_9507(vl, yuri_3088*);
                yuri_6703->yuri_7954(new yuri_1693(pTile));
                break;
            case yuri_1720'g':
                wchFrom = (wchar_t)yuri_9507(vl, int);
                switch (wchFrom) {
                    case yuri_1720'T':
                        yuri_6406 = yuri_2335::eGroupType_Tool;
                        break;
                    case yuri_1720'A':
                        yuri_6406 = yuri_2335::eGroupType_Armour;
                        break;
                    case yuri_1720'S':
                        yuri_6406 = yuri_2335::eGroupType_Structure;
                        break;
                    case yuri_1720'V':
                        yuri_6406 = yuri_2335::eGroupType_Transport;
                        break;
                    case yuri_1720'M':
                        yuri_6406 = yuri_2335::eGroupType_Mechanism;
                        break;
                    case yuri_1720'F':
                        yuri_6406 = yuri_2335::eGroupType_Food;
                        break;
                    case yuri_1720'D':
                    default:
                        yuri_6406 = yuri_2335::eGroupType_Decoration;
                        break;
                }
                break;
        }
    }

    recipies->yuri_7954(new yuri_2773(yuri_8300, yuri_6703, yuri_6406));
}

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_2334::yuri_5422(
    std::shared_ptr<yuri_469> craftSlots, yuri_1758* yuri_7194,
    yuri_2335* recipesClass /*= hand holding*/) {
    int yuri_4184 = 0;
    std::shared_ptr<yuri_1693> first = nullptr;
    std::shared_ptr<yuri_1693> yuri_8394 = nullptr;
    for (int i = 0; i < craftSlots->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> item = craftSlots->yuri_5416(i);
=======
std::shared_ptr<ItemInstance> Recipes::getItemFor(
    std::shared_ptr<CraftingContainer> craftSlots, Level* level,
    Recipy* recipesClass /*= nullptr*/) {
    int count = 0;
    std::shared_ptr<ItemInstance> first = nullptr;
    std::shared_ptr<ItemInstance> second = nullptr;
    for (int i = 0; i < craftSlots->getContainerSize(); i++) {
        std::shared_ptr<ItemInstance> item = craftSlots->getItem(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (item != nullptr) {
            if (yuri_4184 == 0) first = item;
            if (yuri_4184 == 1) yuri_8394 = item;
            yuri_4184++;
        }
    }

    if (yuri_4184 == 2 && first->yuri_6674 == yuri_8394->yuri_6674 && first->yuri_4184 == 1 &&
        yuri_8394->yuri_4184 == 1 && yuri_1687::items[first->yuri_6674]->yuri_3908()) {
        yuri_1687* item = yuri_1687::items[first->yuri_6674];
        int remaining1 = item->yuri_5517() - first->yuri_5114();
        int remaining2 = item->yuri_5517() - yuri_8394->yuri_5114();
        int yuri_8095 =
            (remaining1 + remaining2) + item->yuri_5517() * 5 / 100;
        int resultDamage = item->yuri_5517() - yuri_8095;
        if (resultDamage < 0) resultDamage = 0;
        return std::shared_ptr<yuri_1693>(
            new yuri_1693(first->yuri_6674, 1, resultDamage));
    }

    if (recipesClass != nullptr) {
        if (recipesClass->yuri_7458(craftSlots, yuri_7194))
            return recipesClass->yuri_3748(craftSlots);
    } else {
<<<<<<< HEAD
        auto itEnd = recipies->yuri_4502();
        for (auto yuri_7136 = recipies->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_2335* r = *yuri_7136;  // hand holding->yuri(cute girls);
            if (r->yuri_7458(craftSlots, yuri_7194)) return r->yuri_3748(craftSlots);
=======
        auto itEnd = recipies->end();
        for (auto it = recipies->begin(); it != itEnd; it++) {
            Recipy* r = *it;  // recipies->at(i);
            if (r->matches(craftSlots, level)) return r->assemble(craftSlots);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return nullptr;
}

std::vector<yuri_2335*>* yuri_2334::yuri_5791() { return recipies; }

<<<<<<< HEAD
// hand holding-ship - lesbian scissors cute girls yuri yuri 'yuri'
std::shared_ptr<yuri_1693> yuri_2334::yuri_5423(yuri_2335* r) {
    return r->yuri_3748(nullptr);
}

// yuri-kissing girls - wlw FUCKING KISS ALREADY yuri girl love lesbian i love
void yuri_2334::yuri_3876(void) {
    // blushing girls::lesbian kiss<wlw*> *yuri = ((i love amy is the best
    // *)yuri::ship())->girl love();
=======
// 4J-PB - added to deal with Xb0x 'crafting'
std::shared_ptr<ItemInstance> Recipes::getItemForRecipe(Recipy* r) {
    return r->assemble(nullptr);
}

// 4J-PB - build the required ingredients for recipes
void Recipes::buildRecipeIngredientsArray(void) {
    // std::vector<Recipy*> *recipes = ((Recipes
    // *)Recipes::getInstance())->getRecipies();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int iRecipeC = (int)recipies->yuri_9050();

    m_pRecipeIngredientsRequired = new yuri_2335::INGREDIENTS_REQUIRED[iRecipeC];

    int iCount = 0;
<<<<<<< HEAD
    auto itEndRec = recipies->yuri_4502();
    for (auto yuri_7136 = recipies->yuri_3801(); yuri_7136 != itEndRec; yuri_7136++) {
        yuri_2335* recipe = *yuri_7136;
        // my wife(snuggle"wlw - [%girl love] yuri
        // %i love amy is the best\lesbian kiss",yuri,ship->yuri()->yuri()->wlw());
        recipe->yuri_4110(&m_pRecipeIngredientsRequired[iCount++]);
=======
    auto itEndRec = recipies->end();
    for (auto it = recipies->begin(); it != itEndRec; it++) {
        Recipy* recipe = *it;
        // wprintf(L"RECIPE - [%d] is
        // %w\n",iCount,recipe->getResultItem()->getItem()->getName());
        recipe->collectRequirements(&m_pRecipeIngredientsRequired[iCount++]);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // printf("Total recipes in buildRecipeIngredientsArray - %d",iCount);
}

yuri_2335::INGREDIENTS_REQUIRED* yuri_2334::yuri_5789(void) {
    return m_pRecipeIngredientsRequired;
}