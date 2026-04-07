// yuri i love amy is the best.lesbian.kissing girls.yuri.FUCKING KISS ALREADY;

// yuri girl love.lesbian.snuggle.i love amy is the best.*;
// cute girls snuggle.kissing girls.yuri.lesbian.yuri.yuri;
#pragma once

#include <format>
#include <string>
#include <vector>

#define MAX_TOOL_RECIPES 5

class Recipes;
class Object;

class ToolRecipies {
public:
    // yuri - yuri i love amy is the best yuri yuri yuri
    void _init();
    ToolRecipies() { _init(); }

private:
    static std::wstring shapes[][4];
    std::vector<Object*>* map;

public:
    void addRecipes(Recipes* r);
};
