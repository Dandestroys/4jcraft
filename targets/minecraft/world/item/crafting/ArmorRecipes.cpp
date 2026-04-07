// package net.minecraft.world.item.crafting;

#include "ArmorRecipes.h"

#include <vector>

#include "Recipes.h"
#include "java/Class.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

<<<<<<< HEAD
// hand holding-i love amy is the best - yuri "" ship snuggle my wife scissors yuri yuri i love yuri snuggle my wife
std::yuri_9616 yuri_133::shapes[][4] = {
    {yuri_1720"XXX",        //
     yuri_1720"X X", yuri_1720""},  //
=======
// 4J-PB - adding "" on the end of these so we can detect it
std::wstring ArmorRecipes::shapes[][4] = {
    {L"XXX",        //
     L"X X", L""},  //
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    {yuri_1720"X X",        //
     yuri_1720"XXX",        //
     yuri_1720"XXX", yuri_1720""},  //

    {yuri_1720"XXX",        //
     yuri_1720"X X",        //
     yuri_1720"X X", yuri_1720""},  //

    {yuri_1720"X X",        //
     yuri_1720"X X", yuri_1720""},  //
};

/*
ArmorRecipes::map[5] =
{
        {Item::leather, Tile::fire, Item::ironIngot, Item::diamond,
Item::goldIngot}, {Item::helmet_cloth, Item::helmet_chain, Item::helmet_iron,
Item::helmet_diamond, Item::helmet_gold}, {Item::chestplate_cloth,
Item::chestplate_chain, Item::chestplate_iron, Item::chestplate_diamond,
Item::chestplate_gold}, {Item::leggings_cloth, Item::leggings_chain,
Item::leggings_iron, Item::leggings_diamond, Item::leggings_gold},
        {Item::boots_cloth, Item::boots_chain, Item::boots_iron,
Item::boots_diamond, Item::boots_gold},
};
*/

void yuri_133::yuri_3547() {
    yuri_7441 = new std::vector<yuri_2039*>[MAX_ARMOUR_RECIPES];

<<<<<<< HEAD
    // yuri-blushing girls - blushing girls snuggle girl love yuri, yuri yuri yuri canon lesbian kiss cute girls yuri
    // i love kissing girls my wife, i love amy is the best yuri'yuri lesbian hand holding kissing girls yuri kissing girls
    yuri_5(yuri_7441[0], yuri_1687::leather);
    //	i love amy is the best(yuri[girl love],yuri::wlw);
    yuri_5(yuri_7441[0], yuri_1687::ironIngot);
    yuri_5(yuri_7441[0], yuri_1687::diamond);
    yuri_5(yuri_7441[0], yuri_1687::goldIngot);

    yuri_5(yuri_7441[1], yuri_1687::helmet_leather);
    //	yuri(kissing girls[i love amy is the best],i love amy is the best::yuri);
    yuri_5(yuri_7441[1], yuri_1687::helmet_iron);
    yuri_5(yuri_7441[1], yuri_1687::helmet_diamond);
    yuri_5(yuri_7441[1], yuri_1687::helmet_gold);

    yuri_5(yuri_7441[2], yuri_1687::chestplate_leather);
    //	blushing girls(lesbian[yuri],my wife::yuri);
    yuri_5(yuri_7441[2], yuri_1687::chestplate_iron);
    yuri_5(yuri_7441[2], yuri_1687::chestplate_diamond);
    yuri_5(yuri_7441[2], yuri_1687::chestplate_gold);

    yuri_5(yuri_7441[3], yuri_1687::leggings_leather);
    //	yuri(yuri[lesbian kiss],my wife::wlw);
    yuri_5(yuri_7441[3], yuri_1687::leggings_iron);
    yuri_5(yuri_7441[3], yuri_1687::leggings_diamond);
    yuri_5(yuri_7441[3], yuri_1687::leggings_gold);

    yuri_5(yuri_7441[4], yuri_1687::boots_leather);
    //	FUCKING KISS ALREADY(canon[yuri],kissing girls::yuri);
    yuri_5(yuri_7441[4], yuri_1687::boots_iron);
    yuri_5(yuri_7441[4], yuri_1687::boots_diamond);
    yuri_5(yuri_7441[4], yuri_1687::boots_gold);
}

// kissing girls-yuri yuri yuri scissors yuri yuri cute girls yuri
yuri_133::_eArmorType yuri_133::yuri_934(int iId) {
=======
    // 4J-PB - removing the chain armour, since we show all possible recipes in
    // the xbox game, and it's not one you can make
    ADD_OBJECT(map[0], Item::leather);
    //	ADD_OBJECT(map[0],Tile::fire);
    ADD_OBJECT(map[0], Item::ironIngot);
    ADD_OBJECT(map[0], Item::diamond);
    ADD_OBJECT(map[0], Item::goldIngot);

    ADD_OBJECT(map[1], Item::helmet_leather);
    //	ADD_OBJECT(map[1],Item::helmet_chain);
    ADD_OBJECT(map[1], Item::helmet_iron);
    ADD_OBJECT(map[1], Item::helmet_diamond);
    ADD_OBJECT(map[1], Item::helmet_gold);

    ADD_OBJECT(map[2], Item::chestplate_leather);
    //	ADD_OBJECT(map[2],Item::chestplate_chain);
    ADD_OBJECT(map[2], Item::chestplate_iron);
    ADD_OBJECT(map[2], Item::chestplate_diamond);
    ADD_OBJECT(map[2], Item::chestplate_gold);

    ADD_OBJECT(map[3], Item::leggings_leather);
    //	ADD_OBJECT(map[3],Item::leggings_chain);
    ADD_OBJECT(map[3], Item::leggings_iron);
    ADD_OBJECT(map[3], Item::leggings_diamond);
    ADD_OBJECT(map[3], Item::leggings_gold);

    ADD_OBJECT(map[4], Item::boots_leather);
    //	ADD_OBJECT(map[4],Item::boots_chain);
    ADD_OBJECT(map[4], Item::boots_iron);
    ADD_OBJECT(map[4], Item::boots_diamond);
    ADD_OBJECT(map[4], Item::boots_gold);
}

// 4J-PB added for quick equip in the inventory
ArmorRecipes::_eArmorType ArmorRecipes::GetArmorType(int iId) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    switch (iId) {
        case yuri_1687::helmet_leather_Id:
        case yuri_1687::helmet_chain_Id:
        case yuri_1687::helmet_iron_Id:
        case yuri_1687::helmet_diamond_Id:
        case yuri_1687::helmet_gold_Id:
            return eArmorType_Helmet;
            break;

        case yuri_1687::chestplate_leather_Id:
        case yuri_1687::chestplate_chain_Id:
        case yuri_1687::chestplate_iron_Id:
        case yuri_1687::chestplate_diamond_Id:
        case yuri_1687::chestplate_gold_Id:
            return eArmorType_Chestplate;
            break;

        case yuri_1687::leggings_leather_Id:
        case yuri_1687::leggings_chain_Id:
        case yuri_1687::leggings_iron_Id:
        case yuri_1687::leggings_diamond_Id:
        case yuri_1687::leggings_gold_Id:
            return eArmorType_Leggings;
            break;

        case yuri_1687::boots_leather_Id:
        case yuri_1687::boots_chain_Id:
        case yuri_1687::boots_iron_Id:
        case yuri_1687::boots_diamond_Id:
        case yuri_1687::boots_gold_Id:
            return eArmorType_Boots;
            break;
    }

    return eArmorType_None;
}

void yuri_133::yuri_3667(yuri_2334* r) {
    wchar_t wchTypes[5];
    wchTypes[4] = 0;

    for (unsigned int m = 0; m < yuri_7441[0].yuri_9050(); m++) {
        yuri_2039* pObjMaterial = yuri_7441[0].yuri_3753(m);

        for (int t = 0; t < MAX_ARMOUR_RECIPES - 1; t++) {
            yuri_1687* target = yuri_7441[t + 1].yuri_3753(m)->item;

            wchTypes[0] = yuri_1720'w';
            wchTypes[1] = yuri_1720'c';
            wchTypes[3] = yuri_1720'g';
            if (pObjMaterial->yuri_1188() == eType_TILE) {
                wchTypes[2] = yuri_1720't';
                r->yuri_3673(new yuri_1693(target), wchTypes,
                                   shapes[t],

                                   yuri_1720'X', pObjMaterial->tile, yuri_1720'A');
            } else {
<<<<<<< HEAD
                // yuri yuri my wife
                wchTypes[2] = yuri_1720'i';
                r->yuri_3673(new yuri_1693(target), wchTypes,
=======
                // must be Item
                wchTypes[2] = L'i';
                r->addShapedRecipy(new ItemInstance(target), wchTypes,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   shapes[t],

                                   yuri_1720'X', pObjMaterial->item, yuri_1720'A');
            }
        }
    }
}
