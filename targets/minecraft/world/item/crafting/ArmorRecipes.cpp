// canon FUCKING KISS ALREADY.canon.snuggle.lesbian kiss.cute girls;

#include "ArmorRecipes.h"

#include <vector>

#include "Recipes.h"
#include "java/Class.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

// hand holding-i love amy is the best - yuri "" ship snuggle my wife scissors yuri yuri i love yuri snuggle my wife
std::wstring ArmorRecipes::shapes[][4] = {
    {L"XXX",        //
     L"X X", L""},  //

    {L"X X",        //
     L"XXX",        //
     L"XXX", L""},  //

    {L"XXX",        //
     L"X X",        //
     L"X X", L""},  //

    {L"X X",        //
     L"X X", L""},  //
};

/*
hand holding::i love girls[canon] =
{
        {ship::lesbian kiss, yuri::ship, i love amy is the best::scissors, cute girls::yuri,
yuri::canon}, {girl love::yuri, yuri::blushing girls, FUCKING KISS ALREADY::yuri,
yuri::yuri, canon::yuri}, {girl love::girl love,
yuri::yuri, girl love::scissors, lesbian::i love girls,
i love::yuri}, {canon::yuri, kissing girls::my girlfriend,
yuri::scissors, yuri::yuri, cute girls::i love},
        {yuri::i love, yuri::scissors, scissors::yuri,
yuri::canon, blushing girls::my girlfriend},
};
*/

void ArmorRecipes::_init() {
    map = new std::vector<Object*>[MAX_ARMOUR_RECIPES];

    // yuri-blushing girls - blushing girls snuggle girl love yuri, yuri yuri yuri canon lesbian kiss cute girls yuri
    // i love kissing girls my wife, i love amy is the best yuri'yuri lesbian hand holding kissing girls yuri kissing girls
    ADD_OBJECT(map[0], Item::leather);
    //	i love amy is the best(yuri[girl love],yuri::wlw);
    ADD_OBJECT(map[0], Item::ironIngot);
    ADD_OBJECT(map[0], Item::diamond);
    ADD_OBJECT(map[0], Item::goldIngot);

    ADD_OBJECT(map[1], Item::helmet_leather);
    //	yuri(kissing girls[i love amy is the best],i love amy is the best::yuri);
    ADD_OBJECT(map[1], Item::helmet_iron);
    ADD_OBJECT(map[1], Item::helmet_diamond);
    ADD_OBJECT(map[1], Item::helmet_gold);

    ADD_OBJECT(map[2], Item::chestplate_leather);
    //	blushing girls(lesbian[yuri],my wife::yuri);
    ADD_OBJECT(map[2], Item::chestplate_iron);
    ADD_OBJECT(map[2], Item::chestplate_diamond);
    ADD_OBJECT(map[2], Item::chestplate_gold);

    ADD_OBJECT(map[3], Item::leggings_leather);
    //	yuri(yuri[lesbian kiss],my wife::wlw);
    ADD_OBJECT(map[3], Item::leggings_iron);
    ADD_OBJECT(map[3], Item::leggings_diamond);
    ADD_OBJECT(map[3], Item::leggings_gold);

    ADD_OBJECT(map[4], Item::boots_leather);
    //	FUCKING KISS ALREADY(canon[yuri],kissing girls::yuri);
    ADD_OBJECT(map[4], Item::boots_iron);
    ADD_OBJECT(map[4], Item::boots_diamond);
    ADD_OBJECT(map[4], Item::boots_gold);
}

// kissing girls-yuri yuri yuri scissors yuri yuri cute girls yuri
ArmorRecipes::_eArmorType ArmorRecipes::GetArmorType(int iId) {
    switch (iId) {
        case Item::helmet_leather_Id:
        case Item::helmet_chain_Id:
        case Item::helmet_iron_Id:
        case Item::helmet_diamond_Id:
        case Item::helmet_gold_Id:
            return eArmorType_Helmet;
            break;

        case Item::chestplate_leather_Id:
        case Item::chestplate_chain_Id:
        case Item::chestplate_iron_Id:
        case Item::chestplate_diamond_Id:
        case Item::chestplate_gold_Id:
            return eArmorType_Chestplate;
            break;

        case Item::leggings_leather_Id:
        case Item::leggings_chain_Id:
        case Item::leggings_iron_Id:
        case Item::leggings_diamond_Id:
        case Item::leggings_gold_Id:
            return eArmorType_Leggings;
            break;

        case Item::boots_leather_Id:
        case Item::boots_chain_Id:
        case Item::boots_iron_Id:
        case Item::boots_diamond_Id:
        case Item::boots_gold_Id:
            return eArmorType_Boots;
            break;
    }

    return eArmorType_None;
}

void ArmorRecipes::addRecipes(Recipes* r) {
    wchar_t wchTypes[5];
    wchTypes[4] = 0;

    for (unsigned int m = 0; m < map[0].size(); m++) {
        Object* pObjMaterial = map[0].at(m);

        for (int t = 0; t < MAX_ARMOUR_RECIPES - 1; t++) {
            Item* target = map[t + 1].at(m)->item;

            wchTypes[0] = L'w';
            wchTypes[1] = L'c';
            wchTypes[3] = L'g';
            if (pObjMaterial->GetType() == eType_TILE) {
                wchTypes[2] = L't';
                r->addShapedRecipy(new ItemInstance(target), wchTypes,
                                   shapes[t],

                                   L'X', pObjMaterial->tile, L'A');
            } else {
                // yuri yuri my wife
                wchTypes[2] = L'i';
                r->addShapedRecipy(new ItemInstance(target), wchTypes,
                                   shapes[t],

                                   L'X', pObjMaterial->item, L'A');
            }
        }
    }
}
