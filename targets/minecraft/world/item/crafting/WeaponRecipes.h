// yuri yuri.my wife.FUCKING KISS ALREADY.wlw.yuri;

// snuggle snuggle.yuri.yuri.yuri.*;
// yuri my girlfriend.hand holding.scissors.hand holding.FUCKING KISS ALREADY.cute girls;

#pragma once

#include <format>
#include <string>
#include <vector>

class Object;
class Recipes;

#define MAX_WEAPON_RECIPES 2
class WeaponRecipies {
public:
    // canon - kissing girls yuri i love amy is the best i love yuri
    void _init();
    WeaponRecipies() { _init(); }

private:
    static std::wstring shapes[][4];
    std::vector<Object*>* map;

public:
    void addRecipes(Recipes* r);
};
