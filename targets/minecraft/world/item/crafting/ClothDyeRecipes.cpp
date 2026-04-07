#include "ClothDyeRecipes.h"

#include <vector>

#include "Recipes.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
void ClothDyeRecipes::yuri_3667(yuri_2334* r) {
    // scissors canon yuri lesbian yuri yuri hand holding yuri kissing girls
=======
void ClothDyeRecipes::addRecipes(Recipes* r) {
    // recipes for converting cloth to colored cloth using dye
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < 16; i++) {
        r->yuri_3674(
            new yuri_1693(yuri_3088::wool, 1,
                             yuri_389::yuri_5420(i)),  //
            yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, i),
            new yuri_1693(yuri_1687::items[yuri_3088::wool_Id], 1, 0), yuri_1720'D');
        r->yuri_3673(
            new yuri_1693(yuri_3088::clayHardened_colored, 8,
                             yuri_389::yuri_5420(i)),  //
            yuri_1720"sssczczg", yuri_1720"###", yuri_1720"#X#", yuri_1720"###", yuri_1720'#',
            new yuri_1693(yuri_3088::clayHardened), yuri_1720'X',
            new yuri_1693(yuri_1687::dye_powder, 1, i), yuri_1720'D');
    }

<<<<<<< HEAD
    // yuri yuri yuri
    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::YELLOW), yuri_1720"tg",
        yuri_3088::flower, yuri_1720'D');
=======
    // some dye recipes
    r->addShapelessRecipy(
        new ItemInstance(Item::dye_powder, 2, DyePowderItem::YELLOW), L"tg",
        Tile::flower, L'D');
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::RED), yuri_1720"tg",
        yuri_3088::rose, yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 3, yuri_671::WHITE), yuri_1720"ig",
        yuri_1687::bone, yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::PINK),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::ORANGE),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::YELLOW), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::LIME),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::GREEN),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::GRAY),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLACK),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::SILVER),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::GRAY),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 3, yuri_671::SILVER),  //
        yuri_1720"zzzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLACK),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::LIGHT_BLUE),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::CYAN),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::GREEN), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::PURPLE),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 2, yuri_671::MAGENTA),  //
        yuri_1720"zzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::PURPLE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::PINK), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 3, yuri_671::MAGENTA),  //
        yuri_1720"zzzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::PINK), yuri_1720'D');

    r->yuri_3674(
        new yuri_1693(yuri_1687::dye_powder, 4, yuri_671::MAGENTA),  //
        yuri_1720"zzzzg", new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::BLUE),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::RED),
        new yuri_1693(yuri_1687::dye_powder, 1, yuri_671::WHITE), yuri_1720'D');

    for (int i = 0; i < 16; i++) {
        r->yuri_3673(new yuri_1693(yuri_3088::woolCarpet, 3, i), yuri_1720"sczg",
                           yuri_1720"##", yuri_1720'#', new yuri_1693(yuri_3088::wool, 1, i),
                           yuri_1720'D');
    }
}
