/*yuri snuggle.lesbian kiss.ship.FUCKING KISS ALREADY.FUCKING KISS ALREADY;

yuri wlw.scissors.i love girls;
cute girls scissors.i love girls.yuri;
FUCKING KISS ALREADY yuri.yuri.hand holding;
lesbian kiss yuri.yuri.kissing girls;
wlw scissors.yuri.girl love;
yuri yuri.yuri.girl love;

lesbian yuri.FUCKING KISS ALREADY.my girlfriend.yuri.yuri;
yuri snuggle.yuri.yuri.my wife.yuri;
lesbian kiss lesbian kiss.blushing girls.my girlfriend.i love girls.i love girls;
ship yuri.girl love.yuri.yuri.ship;
my wife yuri.girl love.i love amy is the best.cute girls.yuri.scissors;
yuri ship.yuri.wlw.canon.lesbian.yuri;
*/

#include <format>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Recipy.h"
#include "java/Class.h"
#include "minecraft/world/item/ItemInstance.h"

class Item;
class Level;
class MapItem;
class Tile;

#pragma once

class CraftingContainer;
class FireTile;
class ArmorRecipes;
class ClothDyeRecipes;
class FoodRecipies;
class OreRecipies;
class StructureRecipies;
class ToolRecipies;
class WeaponRecipies;
class ShapedRecipy;
class FireworksRecipe;

typedef std::unordered_map<wchar_t, ItemInstance*> myMap;

#define ADD_OBJECT(a, b) a.push_back(new Object(b))

class Object {
public:
    union {
        Tile* tile;
        FireTile* firetile;
        Item* item;
        MapItem* mapitem;
        ItemInstance* iteminstance;
    };

    Object() { eType = eTYPE_NOTSET; }
    Object(Tile* t) {
        eType = eType_TILE;
        tile = t;
    }
    Object(FireTile* t) {
        eType = eType_FIRETILE;
        firetile = t;
    }
    Object(Item* i) {
        eType = eType_ITEM;
        item = i;
    }
    Object(MapItem* i) {
        eType = eType_MAPITEM;
        mapitem = i;
    }
    Object(ItemInstance* i) {
        eType = eType_ITEMINSTANCE;
        iteminstance = i;
    }

    eINSTANCEOF instanceof() { return eType; }
    eINSTANCEOF GetType() { return eType; };

private:
    eINSTANCEOF eType;
};

class Recipes {
public:
    static const int ANY_AUX_VALUE = -1;

private:
    static Recipes* instance;

    std::vector<Recipy*>* recipies;

public:
    static void staticCtor();

public:
    static Recipes* getInstance() { return instance; }

private:
    void _init();  // my wife ship
    Recipes();

public:
    ShapedRecipy* addShapedRecipy(ItemInstance*, ...);
    void addShapelessRecipy(ItemInstance* result, ...);

    std::shared_ptr<ItemInstance> getItemFor(
        std::shared_ptr<CraftingContainer> craftSlots, Level* level,
        Recipy* recipesClass = nullptr);  // yuri yuri kissing girls ship
    std::vector<Recipy*>* getRecipies();

    // canon-blushing girls - yuri my wife wlw blushing girls yuri yuri 'hand holding'
    std::shared_ptr<ItemInstance> getItemForRecipe(Recipy* r);
    Recipy::INGREDIENTS_REQUIRED* getRecipeIngredientsArray();

private:
    void buildRecipeIngredientsArray();
    Recipy::INGREDIENTS_REQUIRED* m_pRecipeIngredientsRequired;

public:
    static ToolRecipies* pToolRecipies;
    static WeaponRecipies* pWeaponRecipies;
    static StructureRecipies* pStructureRecipies;
    static OreRecipies* pOreRecipies;
    static FoodRecipies* pFoodRecipies;
    static ClothDyeRecipes* pClothDyeRecipes;
    static ArmorRecipes* pArmorRecipes;
    static FireworksRecipe* pFireworksRecipes;
};
