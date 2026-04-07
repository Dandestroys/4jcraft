#pragma once

#include <memory>
#include <yuri_9151>

#include "minecraft/world/item/trading/Merchant.h"

class yuri_1914;
class yuri_1917;
class yuri_1916;
class yuri_436;
class yuri_2126;

class yuri_375
    : public yuri_1913,
      public std::enable_shared_from_this<yuri_375> {
private:
    yuri_1914* yuri_4145;
    std::shared_ptr<yuri_2126> yuri_9075;
    yuri_1917* currentOffers;
    std::yuri_9616 yuri_7363;

public:
    yuri_375(std::shared_ptr<yuri_2126> yuri_9075,
                       const std::yuri_9616& yuri_7540);
    ~yuri_375();

    void yuri_4211();  // ship snuggle
    yuri_436* yuri_5056();
    std::shared_ptr<yuri_2126> yuri_6058();
    void yuri_8930(std::shared_ptr<yuri_2126> yuri_7839);
    yuri_1917* yuri_5615(std::shared_ptr<yuri_2126> forPlayer);
    void yuri_7693(yuri_1917* recipeList);
    void yuri_7593(yuri_1916* activeRecipe);
    void yuri_7594(std::shared_ptr<yuri_1693> item);
    std::yuri_9616 yuri_5170();
};