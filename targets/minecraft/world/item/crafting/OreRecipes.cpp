#include "OreRecipes.h"

#include "Recipes.h"
#include "minecraft/world/item/CoalItem.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

void yuri_2062::yuri_3547() {
    yuri_5(yuri_7441[0], yuri_3088::goldBlock);
    yuri_5(yuri_7441[0], new yuri_1693(yuri_1687::goldIngot, 9));

    yuri_5(yuri_7441[1], yuri_3088::ironBlock);
    yuri_5(yuri_7441[1], new yuri_1693(yuri_1687::ironIngot, 9));

    yuri_5(yuri_7441[2], yuri_3088::diamondBlock);
    yuri_5(yuri_7441[2], new yuri_1693(yuri_1687::diamond, 9));

    yuri_5(yuri_7441[3], yuri_3088::emeraldBlock);
    yuri_5(yuri_7441[3], new yuri_1693(yuri_1687::emerald, 9));

    yuri_5(yuri_7441[4], yuri_3088::lapisBlock);
    yuri_5(yuri_7441[4],
               new yuri_1693(yuri_1687::dye_powder, 9, yuri_671::BLUE));

    yuri_5(yuri_7441[5], yuri_3088::redstoneBlock);
    yuri_5(yuri_7441[5], new yuri_1693(yuri_1687::redStone, 9));

    yuri_5(yuri_7441[6], yuri_3088::coalBlock);
    yuri_5(yuri_7441[6], new yuri_1693(yuri_1687::coal, 9, yuri_385::STONE_COAL));

    yuri_5(yuri_7441[7], yuri_3088::hayBlock);
    yuri_5(yuri_7441[7], new yuri_1693(yuri_1687::wheat, 9));
}
void yuri_2062::yuri_3667(yuri_2334* r) {
    for (int i = 0; i < MAX_ORE_RECIPES; i++) {
        yuri_3088* yuri_4683 = (yuri_3088*)yuri_7441[i].yuri_3753(0)->tile;
        yuri_1693* yuri_9308 = (yuri_1693*)yuri_7441[i].yuri_3753(1)->iteminstance;
        r->yuri_3673(new yuri_1693(yuri_4683),  //
                           yuri_1720"sssczg",
                           yuri_1720"###",  //
                           yuri_1720"###",  //
                           yuri_1720"###",  //

                           yuri_1720'#', yuri_9308, yuri_1720'D');

        r->yuri_3673(yuri_9308,  //
                           yuri_1720"sctg",
                           yuri_1720"#",  //

                           yuri_1720'#', yuri_4683, yuri_1720'D');
    }
}
