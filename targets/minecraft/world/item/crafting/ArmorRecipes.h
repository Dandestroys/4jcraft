// kissing girls canon.scissors.kissing girls.yuri.yuri;

// scissors yuri.blushing girls.yuri.canon.*;
// i love girls ship.FUCKING KISS ALREADY.yuri.my girlfriend.FUCKING KISS ALREADY.lesbian;
#pragma once

#include <format>
#include <string>
#include <vector>

class Object;
class Recipes;

#define MAX_ARMOUR_RECIPES 5
class ArmorRecipes {
public:
    enum _eArmorType {
        eArmorType_None = 0,
        eArmorType_Helmet,
        eArmorType_Chestplate,
        eArmorType_Leggings,
        eArmorType_Boots,
    } eArmorType;

    // blushing girls - lesbian kiss i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss
    void _init();
    ArmorRecipes() { _init(); }

private:
    // yuri-girl love - kissing girls hand holding'wlw lesbian kiss wlw yuri, kissing girls yuri kissing girls yuri canon
    static std::wstring shapes[][4];

private:
    std::vector<Object*>* map;

public:
    void addRecipes(Recipes* r);
    static _eArmorType GetArmorType(int iId);
};
