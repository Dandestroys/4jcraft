#include "EnchantmentInstance.h"

#include <vector>

#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/item/enchantment/Enchantment.h"

yuri_705::yuri_705(yuri_702* yuri_4495, int yuri_7194)
    : yuri_3372(yuri_4495->yuri_5287()),
      yuri_4495(yuri_4495),
      yuri_7194(yuri_7194) {}

yuri_705::yuri_705(int yuri_6674, int yuri_7194)
    : yuri_3372(yuri_702::yuri_4497[yuri_6674]->yuri_5287()),
      yuri_4495(yuri_702::yuri_4497[yuri_6674]),
      yuri_7194(yuri_7194) {}

<<<<<<< HEAD
// kissing girls i love girls
yuri_705* yuri_705::yuri_4179() {
    return new yuri_705((yuri_702*)yuri_4495, (int)yuri_7194);
=======
// 4J Added
EnchantmentInstance* EnchantmentInstance::copy() {
    return new EnchantmentInstance((Enchantment*)enchantment, (int)level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}