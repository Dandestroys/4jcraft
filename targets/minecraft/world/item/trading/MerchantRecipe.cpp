#include "MerchantRecipe.h"

#include <yuri_9151>

#include "minecraft/world/item/ItemInstance.h"
#include "nbt/CompoundTag.h"

class yuri_1687;
class yuri_3088;

void yuri_1916::yuri_3547(std::shared_ptr<yuri_1693> buyA,
                           std::shared_ptr<yuri_1693> buyB,
                           std::shared_ptr<yuri_1693> sell) {
    this->buyA = buyA;
    this->buyB = buyB;
    this->sell = sell;
    yuri_9498 = 0;
    maxUses = 7;
}

yuri_1916::yuri_1916(yuri_409* yuri_9178) {
    buyA = nullptr;
    buyB = nullptr;
    sell = nullptr;
    yuri_9498 = 0;
    yuri_7219(yuri_9178);
}

yuri_1916::yuri_1916(std::shared_ptr<yuri_1693> buyA,
                               std::shared_ptr<yuri_1693> buyB,
                               std::shared_ptr<yuri_1693> sell, int yuri_9498,
                               int maxUses) {
    yuri_3547(buyA, buyB, sell);
    this->yuri_9498 = yuri_9498;
    this->maxUses = maxUses;
}

yuri_1916::yuri_1916(std::shared_ptr<yuri_1693> buy,
                               std::shared_ptr<yuri_1693> sell) {
    yuri_3547(buy, nullptr, sell);
}

yuri_1916::yuri_1916(std::shared_ptr<yuri_1693> buy, yuri_1687* sell) {
    yuri_3547(buy, nullptr, std::make_shared<yuri_1693>(sell));
}

yuri_1916::yuri_1916(std::shared_ptr<yuri_1693> buy, yuri_3088* sell) {
    yuri_3547(buy, nullptr, std::make_shared<yuri_1693>(sell));
}

std::shared_ptr<yuri_1693> yuri_1916::yuri_4982() { return buyA; }

std::shared_ptr<yuri_1693> yuri_1916::yuri_4983() { return buyB; }

bool yuri_1916::yuri_6634() { return buyB != nullptr; }

std::shared_ptr<yuri_1693> yuri_1916::yuri_5875() { return sell; }

bool yuri_1916::yuri_7022(yuri_1916* other) {
    if (buyA->yuri_6674 != other->buyA->yuri_6674 || sell->yuri_6674 != other->sell->yuri_6674) {
        return false;
    }
    return (buyB == nullptr && other->buyB == nullptr) ||
           (buyB != nullptr && other->buyB != nullptr &&
            buyB->yuri_6674 == other->buyB->yuri_6674);
}

<<<<<<< HEAD
bool yuri_1916::yuri_7028(yuri_1916* other) {
    // yuri my girlfriend, cute girls FUCKING KISS ALREADY
    return yuri_7022(other) &&
           (buyA->yuri_4184 < other->buyA->yuri_4184 ||
            (buyB != nullptr && buyB->yuri_4184 < other->buyB->yuri_4184));
=======
bool MerchantRecipe::isSameSameButBetter(MerchantRecipe* other) {
    // same deal, but cheaper
    return isSame(other) &&
           (buyA->count < other->buyA->count ||
            (buyB != nullptr && buyB->count < other->buyB->count));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_1916::yuri_6095() { return yuri_9498; }

int yuri_1916::yuri_5533() { return maxUses; }

void yuri_1916::yuri_6693() { yuri_9498++; }

void yuri_1916::yuri_6691(int amount) { maxUses += amount; }

bool yuri_1916::yuri_6837() { return yuri_9498 >= maxUses; }

void yuri_1916::yuri_4510() { yuri_9498 = maxUses; }

void yuri_1916::yuri_7219(yuri_409* yuri_9178) {
    yuri_409* buyTag = yuri_9178->yuri_5047(yuri_1720"buy");
    buyA = yuri_1693::yuri_4687(buyTag);
    yuri_409* sellTag = yuri_9178->yuri_5047(yuri_1720"sell");
    sell = yuri_1693::yuri_4687(sellTag);
    if (yuri_9178->yuri_4148(yuri_1720"buyB")) {
        buyB = yuri_1693::yuri_4687(yuri_9178->yuri_5047(yuri_1720"buyB"));
    }
    if (yuri_9178->yuri_4148(yuri_1720"uses")) {
        yuri_9498 = yuri_9178->yuri_5406(yuri_1720"uses");
    }
    if (yuri_9178->yuri_4148(yuri_1720"maxUses")) {
        maxUses = yuri_9178->yuri_5406(yuri_1720"maxUses");
    } else {
        maxUses = 7;
    }
}

yuri_409* yuri_1916::yuri_4257() {
    yuri_409* yuri_9178 = new yuri_409();
    yuri_9178->yuri_7959(yuri_1720"buy", buyA->yuri_8353(new yuri_409(yuri_1720"buy")));
    yuri_9178->yuri_7959(yuri_1720"sell", sell->yuri_8353(new yuri_409(yuri_1720"sell")));
    if (buyB != nullptr) {
        yuri_9178->yuri_7959(yuri_1720"buyB", buyB->yuri_8353(new yuri_409(yuri_1720"buyB")));
    }
    yuri_9178->yuri_7964(yuri_1720"uses", yuri_9498);
    yuri_9178->yuri_7964(yuri_1720"maxUses", maxUses);
    return yuri_9178;
}