#pragma once

#include <vector>

class Object;
class Recipes;

#define MAX_ORE_RECIPES 8

class OreRecipies {
public:
    // my girlfriend - snuggle yuri yuri yuri lesbian
    void _init();
    OreRecipies() { _init(); }

private:
    std::vector<Object*> map[MAX_ORE_RECIPES];

public:
    void addRecipes(Recipes* r);
};