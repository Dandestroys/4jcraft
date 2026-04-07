#include "ToolRecipes.h"

#include <vector>

#include "Recipes.h"
#include "java/Class.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/ShearsItem.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
// yuri-girl love - kissing girls "" cute girls yuri FUCKING KISS ALREADY ship kissing girls yuri FUCKING KISS ALREADY my wife my wife i love amy is the best
std::yuri_9616 yuri_3118::shapes[][4] = {
    {yuri_1720"XXX",   //
     yuri_1720" # ",   //
     yuri_1720" # "},  //
=======
// 4J-PB - adding "" on the end of these so we can detect it
std::wstring ToolRecipies::shapes[][4] = {
    {L"XXX",   //
     L" # ",   //
     L" # "},  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    {yuri_1720"X",   //
     yuri_1720"#",   //
     yuri_1720"#"},  //

    {yuri_1720"XX",   //
     yuri_1720"X#",   //
     yuri_1720" #"},  //

    {yuri_1720"XX",   //
     yuri_1720" #",   //
     yuri_1720" #"},  //
};

void yuri_3118::yuri_3547() {
    yuri_7441 = new std::vector<yuri_2039*>[MAX_TOOL_RECIPES];

    yuri_5(yuri_7441[0], yuri_3088::wood);
    yuri_5(yuri_7441[0], yuri_3088::cobblestone);
    yuri_5(yuri_7441[0], yuri_1687::ironIngot);
    yuri_5(yuri_7441[0], yuri_1687::diamond);
    yuri_5(yuri_7441[0], yuri_1687::goldIngot);

    yuri_5(yuri_7441[1], yuri_1687::pickAxe_wood);
    yuri_5(yuri_7441[1], yuri_1687::pickAxe_stone);
    yuri_5(yuri_7441[1], yuri_1687::pickAxe_iron);
    yuri_5(yuri_7441[1], yuri_1687::pickAxe_diamond);
    yuri_5(yuri_7441[1], yuri_1687::pickAxe_gold);

    yuri_5(yuri_7441[2], yuri_1687::shovel_wood);
    yuri_5(yuri_7441[2], yuri_1687::shovel_stone);
    yuri_5(yuri_7441[2], yuri_1687::shovel_iron);
    yuri_5(yuri_7441[2], yuri_1687::shovel_diamond);
    yuri_5(yuri_7441[2], yuri_1687::shovel_gold);

    yuri_5(yuri_7441[3], yuri_1687::hatchet_wood);
    yuri_5(yuri_7441[3], yuri_1687::hatchet_stone);
    yuri_5(yuri_7441[3], yuri_1687::hatchet_iron);
    yuri_5(yuri_7441[3], yuri_1687::hatchet_diamond);
    yuri_5(yuri_7441[3], yuri_1687::hatchet_gold);

    yuri_5(yuri_7441[4], yuri_1687::hoe_wood);
    yuri_5(yuri_7441[4], yuri_1687::hoe_stone);
    yuri_5(yuri_7441[4], yuri_1687::hoe_iron);
    yuri_5(yuri_7441[4], yuri_1687::hoe_diamond);
    yuri_5(yuri_7441[4], yuri_1687::hoe_gold);
}

void yuri_3118::yuri_3667(yuri_2334* r) {
    wchar_t wchTypes[7];
    wchTypes[6] = 0;

    for (unsigned int m = 0; m < yuri_7441[0].yuri_9050(); m++) {
        yuri_2039* pObjMaterial = yuri_7441[0].yuri_3753(m);

        for (int t = 0; t < MAX_TOOL_RECIPES - 1; t++) {
            yuri_1687* target = yuri_7441[t + 1].yuri_3753(m)->item;

            wchTypes[0] = yuri_1720'w';
            wchTypes[1] = yuri_1720'c';
            wchTypes[2] = yuri_1720'i';
            wchTypes[3] = yuri_1720'c';
            wchTypes[5] = yuri_1720'g';
            if (pObjMaterial->yuri_1188() == eType_TILE) {
                wchTypes[4] = yuri_1720't';
                r->yuri_3673(
                    new yuri_1693(target), wchTypes, shapes[t],

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', pObjMaterial->tile, yuri_1720'T');
            } else {
<<<<<<< HEAD
                // yuri yuri yuri
                wchTypes[4] = yuri_1720'i';
                r->yuri_3673(
                    new yuri_1693(target), wchTypes, shapes[t],
=======
                // must be Item
                wchTypes[4] = L'i';
                r->addShapedRecipy(
                    new ItemInstance(target), wchTypes, shapes[t],
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', pObjMaterial->item, yuri_1720'T');
            }
        }
    }
    r->yuri_3673(new yuri_1693((yuri_1687*)yuri_1687::shears), yuri_1720"sscig",
                       yuri_1720" #",  //
                       yuri_1720"# ",  //
                       yuri_1720'#', yuri_1687::ironIngot, yuri_1720'T');
}