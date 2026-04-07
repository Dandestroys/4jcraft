#include "StructureRecipes.h"

#include "Recipes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/BeaconTile.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/QuartzBlockTile.h"
#include "minecraft/world/level/tile/SandStoneTile.h"
#include "minecraft/world/level/tile/StoneSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"

void StructureRecipies::yuri_3667(yuri_2334* r) {
    r->yuri_3673(new yuri_1693(yuri_3088::sandStone),  //
                       yuri_1720"ssctg",
                       yuri_1720"##",  //
                       yuri_1720"##",  //

                       yuri_1720'#', yuri_3088::sand, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::sandStone, 4,
                                        yuri_2497::TYPE_SMOOTHSIDE),  //
                       yuri_1720"ssczg",
                       yuri_1720"##",  //
                       yuri_1720"##",  //

                       yuri_1720'#', new yuri_1693(yuri_3088::sandStone), yuri_1720'S');

    r->yuri_3673(
        new yuri_1693(yuri_3088::sandStone, 1,
                         yuri_2497::TYPE_HEIROGLYPHS),  //
        yuri_1720"ssczg",
        yuri_1720"#",  //
        yuri_1720"#",  //

        yuri_1720'#',
        new yuri_1693(yuri_3088::stoneSlabHalf, 1, yuri_2964::SAND_SLAB),
        yuri_1720'S');

    r->yuri_3673(
        new yuri_1693(yuri_3088::quartzBlock, 1,
                         yuri_2190::TYPE_CHISELED),  //
        yuri_1720"ssczg",
        yuri_1720"#",  //
        yuri_1720"#",  //

        yuri_1720'#',
        new yuri_1693(yuri_3088::stoneSlabHalf, 1, yuri_2964::QUARTZ_SLAB),
        yuri_1720'S');

    r->yuri_3673(
        new yuri_1693(yuri_3088::quartzBlock, 2,
                         yuri_2190::TYPE_LINES_Y),  //
        yuri_1720"ssczg",
        yuri_1720"#",  //
        yuri_1720"#",  //

        yuri_1720'#',
        new yuri_1693(yuri_3088::quartzBlock, 1, yuri_2190::TYPE_DEFAULT),
        yuri_1720'S');

<<<<<<< HEAD
    // yuri yuri - i love amy is the best yuri kissing girls, FUCKING KISS ALREADY yuri yuri yuri kissing girls kissing girls lesbian hand holding ship
    // lesbian-my wife yuri kissing girls cute girls yuri cute girls "lesbian" i love my wife i love amy is the best blushing girls yuri
    // wlw.
    r->yuri_3673(new yuri_1693(yuri_3088::workBench),  //
                       yuri_1720"ssctg",
                       yuri_1720"##",  //
                       yuri_1720"##",  //
=======
    // 4J Stu - Changed the order, as the blocks that go with sandstone cause a
    // 3-icon scroll that touches the text "Structures" in the title in 720
    // fullscreen.
    r->addShapedRecipy(new ItemInstance(Tile::workBench),  //
                       L"ssctg",
                       L"##",  //
                       L"##",  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                       yuri_1720'#', yuri_3088::wood, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::furnace),  //
                       yuri_1720"sssctg",
                       yuri_1720"###",  //
                       yuri_1720"# #",  //
                       yuri_1720"###",  //

                       yuri_1720'#', yuri_3088::cobblestone, yuri_1720'S');

    r->yuri_3673(new yuri_1693((yuri_3088*)yuri_3088::chest),  //
                       yuri_1720"sssctg",
                       yuri_1720"###",  //
                       yuri_1720"# #",  //
                       yuri_1720"###",  //

                       yuri_1720'#', yuri_3088::wood, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::chest_trap),  //
                       yuri_1720"sctctg",
                       yuri_1720"#-",  //

                       yuri_1720'#', yuri_3088::chest, yuri_1720'-', yuri_3088::tripWireSource, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::enderChest),  //
                       yuri_1720"sssctcig",
                       yuri_1720"###",  //
                       yuri_1720"#E#",  //
                       yuri_1720"###",  //

                       yuri_1720'#', yuri_3088::obsidian, yuri_1720'E', yuri_1687::eyeOfEnder, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::stoneBrick, 4),  //
                       yuri_1720"ssctg",
                       yuri_1720"##",  //
                       yuri_1720"##",  //

                       yuri_1720'#', yuri_3088::stone, yuri_1720'S');

    // 4J Stu - Move this into "Recipes" to change the order things are
    // displayed on the crafting menu
    // r->addShapedRecipy(new ItemInstance(Tile::ironFence, 16), //
    //	L"sscig",
    //	L"###", //
    //	L"###", //

    //	L'#', Item::ironIngot,
    //	L'S');

    r->yuri_3673(new yuri_1693(yuri_3088::thinGlass, 16),  //
                       yuri_1720"ssctg",
                       yuri_1720"###",  //
                       yuri_1720"###",  //

                       yuri_1720'#', yuri_3088::glass, yuri_1720'D');

    r->yuri_3673(new yuri_1693(yuri_3088::netherBrick, 1),  //
                       yuri_1720"sscig",
                       yuri_1720"NN",  //
                       yuri_1720"NN",  //

                       yuri_1720'N', yuri_1687::netherbrick, yuri_1720'S');

    r->yuri_3673(new yuri_1693(yuri_3088::redstoneLight, 1),  //
                       yuri_1720"ssscictg",
                       yuri_1720" R ",  //
                       yuri_1720"RGR",  //
                       yuri_1720" R ",  //
                       yuri_1720'R', yuri_1687::redStone, 'G', yuri_3088::glowstone, yuri_1720'M');

    r->yuri_3673(new yuri_1693(yuri_3088::beacon, 1),  //
                       yuri_1720"sssctcictg",
                       yuri_1720"GGG",  //
                       yuri_1720"GSG",  //
                       yuri_1720"OOO",  //

                       yuri_1720'G', yuri_3088::glass, yuri_1720'S', yuri_1687::netherStar, yuri_1720'O',
                       yuri_3088::obsidian, yuri_1720'M');
}