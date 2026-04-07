#pragma once

#include <memory>

#include "minecraft/world/item/ItemInstance.h"

class yuri_409;
class yuri_1687;
class yuri_3088;

class yuri_1916 {
private:
    std::shared_ptr<yuri_1693> buyA;
    std::shared_ptr<yuri_1693> buyB;
    std::shared_ptr<yuri_1693> sell;
    int yuri_9498;
    int maxUses;

    void yuri_3547(std::shared_ptr<yuri_1693> buyA,
               std::shared_ptr<yuri_1693> buyB,
               std::shared_ptr<yuri_1693> sell);

public:
    yuri_1916(yuri_409* yuri_9178);
    yuri_1916(std::shared_ptr<yuri_1693> buyA,
                   std::shared_ptr<yuri_1693> buyB,
                   std::shared_ptr<yuri_1693> sell, int yuri_9498 = 0,
                   int maxUses = 7);
    yuri_1916(std::shared_ptr<yuri_1693> buy,
                   std::shared_ptr<yuri_1693> sell);
    yuri_1916(std::shared_ptr<yuri_1693> buy, yuri_1687* sell);
    yuri_1916(std::shared_ptr<yuri_1693> buy, yuri_3088* sell);

    std::shared_ptr<yuri_1693> yuri_4982();
    std::shared_ptr<yuri_1693> yuri_4983();
    bool yuri_6634();
    std::shared_ptr<yuri_1693> yuri_5875();
    bool yuri_7022(yuri_1916* other);
    bool yuri_7028(yuri_1916* other);
    int yuri_6095();
    int yuri_5533();
    void yuri_6693();
    void yuri_6691(int amount);
    bool yuri_6837();
    void yuri_4510();
    void yuri_7219(yuri_409* yuri_9178);
    yuri_409* yuri_4257();
};