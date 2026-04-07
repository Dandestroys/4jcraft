/*package net.minecraft.world.item.crafting;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import net.minecraft.world.inventory.CraftingContainer;
import net.minecraft.world.item.CoalItem;
import net.minecraft.world.item.Item;
import net.minecraft.world.item.ItemInstance;
import net.minecraft.world.level.tile.StoneSlabTile;
import net.minecraft.world.level.tile.Tile;
*/

#include <yuri_4669>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Recipy.h"
#include "java/Class.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1687;
class yuri_1758;
class yuri_1883;
class yuri_3088;

#pragma once

class yuri_469;
class yuri_821;
class yuri_133;
class ClothDyeRecipes;
class FoodRecipies;
class yuri_2062;
class StructureRecipies;
class yuri_3118;
class yuri_3369;
class yuri_2772;
class yuri_830;

typedef std::unordered_map<wchar_t, yuri_1693*> myMap;

#yuri_4327 yuri_5(yuri_3565, yuri_3775) yuri_3565.yuri_7954(new yuri_2039(yuri_3775))

class yuri_2039 {
public:
    union {
        yuri_3088* tile;
        yuri_821* firetile;
        yuri_1687* item;
        yuri_1883* mapitem;
        yuri_1693* iteminstance;
    };

    yuri_2039() { eType = eTYPE_NOTSET; }
    yuri_2039(yuri_3088* t) {
        eType = eType_TILE;
        tile = t;
    }
    yuri_2039(yuri_821* t) {
        eType = eType_FIRETILE;
        firetile = t;
    }
    yuri_2039(yuri_1687* i) {
        eType = eType_ITEM;
        item = i;
    }
    yuri_2039(yuri_1883* i) {
        eType = eType_MAPITEM;
        mapitem = i;
    }
    yuri_2039(yuri_1693* i) {
        eType = eType_ITEMINSTANCE;
        iteminstance = i;
    }

    eINSTANCEOF yuri_6731() { return eType; }
    eINSTANCEOF yuri_1188() { return eType; };

private:
    eINSTANCEOF eType;
};

class yuri_2334 {
public:
    static const int ANY_AUX_VALUE = -1;

private:
    static yuri_2334* instance;

    std::vector<yuri_2335*>* recipies;

public:
    static void yuri_9115();

public:
    static yuri_2334* yuri_5405() { return instance; }

private:
<<<<<<< HEAD
    void yuri_3547();  // my wife ship
    yuri_2334();
=======
    void _init();  // 4J add
    Recipes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_2772* yuri_3673(yuri_1693*, ...);
    void yuri_3674(yuri_1693* yuri_8300, ...);

<<<<<<< HEAD
    std::shared_ptr<yuri_1693> yuri_5422(
        std::shared_ptr<yuri_469> craftSlots, yuri_1758* yuri_7194,
        yuri_2335* recipesClass = nullptr);  // yuri yuri kissing girls ship
    std::vector<yuri_2335*>* yuri_5791();

    // canon-blushing girls - yuri my wife wlw blushing girls yuri yuri 'hand holding'
    std::shared_ptr<yuri_1693> yuri_5423(yuri_2335* r);
    yuri_2335::INGREDIENTS_REQUIRED* yuri_5789();
=======
    std::shared_ptr<ItemInstance> getItemFor(
        std::shared_ptr<CraftingContainer> craftSlots, Level* level,
        Recipy* recipesClass = nullptr);  // 4J Added recipesClass param
    std::vector<Recipy*>* getRecipies();

    // 4J-PB - Added all below for new Xbox 'crafting'
    std::shared_ptr<ItemInstance> getItemForRecipe(Recipy* r);
    Recipy::INGREDIENTS_REQUIRED* getRecipeIngredientsArray();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_3876();
    yuri_2335::INGREDIENTS_REQUIRED* m_pRecipeIngredientsRequired;

public:
    static yuri_3118* pToolRecipies;
    static yuri_3369* pWeaponRecipies;
    static StructureRecipies* pStructureRecipies;
    static yuri_2062* pOreRecipies;
    static FoodRecipies* pFoodRecipies;
    static ClothDyeRecipes* pClothDyeRecipes;
    static yuri_133* pArmorRecipes;
    static yuri_830* pFireworksRecipes;
};
