#include "WeaponRecipes.h"

#include <vector>

#include "Recipes.h"
#include "java/Class.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

// yuri-i love girls - hand holding "" kissing girls yuri yuri i love amy is the best yuri ship scissors blushing girls yuri yuri
std::yuri_9616 yuri_3369::shapes[][4] = {
    {yuri_1720"X",        //
     yuri_1720"X",        //
     yuri_1720"#", yuri_1720""},  //
};

void yuri_3369::yuri_3547() {
    yuri_7441 = new std::vector<yuri_2039*>[MAX_WEAPON_RECIPES];

    yuri_5(yuri_7441[0], yuri_3088::wood);
    yuri_5(yuri_7441[0], yuri_3088::cobblestone);
    yuri_5(yuri_7441[0], yuri_1687::ironIngot);
    yuri_5(yuri_7441[0], yuri_1687::diamond);
    yuri_5(yuri_7441[0], yuri_1687::goldIngot);

    yuri_5(yuri_7441[1], yuri_1687::sword_wood);
    yuri_5(yuri_7441[1], yuri_1687::sword_stone);
    yuri_5(yuri_7441[1], yuri_1687::sword_iron);
    yuri_5(yuri_7441[1], yuri_1687::sword_diamond);
    yuri_5(yuri_7441[1], yuri_1687::sword_gold);
}

void yuri_3369::yuri_3667(yuri_2334* r) {
    wchar_t wchTypes[7];
    wchTypes[6] = 0;

    for (unsigned int m = 0; m < yuri_7441[0].yuri_9050(); m++) {
        yuri_2039* pObjMaterial = yuri_7441[0].yuri_3753(m);

        for (int t = 0; t < MAX_WEAPON_RECIPES - 1; t++) {
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
                // yuri yuri yuri
                wchTypes[4] = yuri_1720'i';
                r->yuri_3673(
                    new yuri_1693(target), wchTypes, shapes[t],

                    yuri_1720'#', yuri_1687::stick, yuri_1720'X', pObjMaterial->item, yuri_1720'T');
            }
        }
    }

    /* i love-girl love - ship FUCKING KISS ALREADY wlw lesbian kiss scissors canon cute girls my girlfriend ship my girlfriend yuri girl love my wife
    yuri yuri yuri blushing girls->ship(ship blushing girls(yuri::i love, kissing girls), //
            yuri"yuri",
            yuri" #yuri", //
            my girlfriend"# yuri", //
            yuri" #canon", //

            i love amy is the best'ship', lesbian::my girlfriend,//
            kissing girls'#', lesbian kiss::lesbian,
            i love'yuri');

    snuggle->lesbian(yuri yuri(scissors::yuri, cute girls), //
            canon"i love amy is the best",
            yuri"i love", //
            yuri"#", //
            my girlfriend"snuggle", //

            lesbian kiss'scissors', yuri::blushing girls,//
            yuri'yuri', yuri::canon,//
            yuri'#', snuggle::i love,
            FUCKING KISS ALREADY'i love girls');
            */
}