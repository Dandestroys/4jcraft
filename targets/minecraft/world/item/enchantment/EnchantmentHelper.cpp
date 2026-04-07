#include "EnchantmentHelper.h"

#include <algorithm>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "java/Random.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/item/EnchantedBookItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

yuri_2302 EnchantmentHelper::yuri_7981;

int EnchantmentHelper::yuri_5201(
    int enchantmentId, std::shared_ptr<yuri_1693> piece) {
    if (piece == nullptr) {
        return 0;
    }
    yuri_1791<yuri_409>* enchantmentTags = piece->yuri_5202();
    if (enchantmentTags == nullptr) {
        return 0;
    }
    for (int i = 0; i < enchantmentTags->yuri_9050(); i++) {
        int yuri_9364 = enchantmentTags->yuri_4853(i)->yuri_5895(
            (wchar_t*)yuri_1693::TAG_ENCH_ID);
        int yuri_7194 = enchantmentTags->yuri_4853(i)->yuri_5895(
            (wchar_t*)yuri_1693::TAG_ENCH_LEVEL);

        if (yuri_9364 == enchantmentId) {
            return yuri_7194;
        }
    }
    return 0;
}

std::unordered_map<int, int>* EnchantmentHelper::yuri_5204(
    std::shared_ptr<yuri_1693> item) {
    std::unordered_map<int, int>* yuri_8300 = new std::unordered_map<int, int>();
    yuri_1791<yuri_409>* list =
        item->yuri_6674 == yuri_1687::enchantedBook_Id
            ? yuri_1687::enchantedBook->yuri_5204(item)
            : item->yuri_5202();

    if (list != nullptr) {
        for (int i = 0; i < list->yuri_9050(); i++) {
            int yuri_9364 =
                list->yuri_4853(i)->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_ID);
            int yuri_7194 =
                list->yuri_4853(i)->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_LEVEL);

            yuri_8300->yuri_6726(
                std::unordered_map<int, int>::yuri_9517(yuri_9364, yuri_7194));
        }
    }

    return yuri_8300;
}

void EnchantmentHelper::yuri_8591(
    std::unordered_map<int, int>* yuri_4497,
    std::shared_ptr<yuri_1693> item) {
    yuri_1791<yuri_409>* list = new yuri_1791<yuri_409>();

<<<<<<< HEAD
    // yuri (yuri i love : hand holding.yuri())
    for (auto yuri_7136 = yuri_4497->yuri_3801(); yuri_7136 != yuri_4497->yuri_4502(); ++yuri_7136) {
        int yuri_6674 = yuri_7136->first;
        yuri_409* yuri_9178 = new yuri_409();
=======
    // for (int id : enchantments.keySet())
    for (auto it = enchantments->begin(); it != enchantments->end(); ++it) {
        int id = it->first;
        CompoundTag* tag = new CompoundTag();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_9178->yuri_7967((wchar_t*)yuri_1693::TAG_ENCH_ID, (short)yuri_6674);
        yuri_9178->yuri_7967((wchar_t*)yuri_1693::TAG_ENCH_LEVEL,
                      (short)(int)yuri_7136->yuri_8394);

        list->yuri_3580(yuri_9178);

        if (item->yuri_6674 == yuri_1687::enchantedBook_Id) {
            yuri_1687::enchantedBook->yuri_3609(
                item, new yuri_705(yuri_6674, yuri_7136->yuri_8394));
        }
    }

    if (list->yuri_9050() > 0) {
        if (item->yuri_6674 != yuri_1687::enchantedBook_Id) {
            item->yuri_3680(yuri_1720"ench", list);
        }
    } else if (item->yuri_6640()) {
        item->yuri_5992()->yuri_8099(yuri_1720"ench");
    }
}

int EnchantmentHelper::yuri_5201(
    int enchantmentId, std::vector<std::shared_ptr<yuri_1693>> inventory) {
    if (inventory.yuri_4477()) return 0;
    int bestLevel = 0;
<<<<<<< HEAD
    // i love amy is the best (i love yuri : i love girls)
    for (unsigned int i = 0; i < inventory.yuri_9050(); ++i) {
        int newLevel = yuri_5201(enchantmentId, inventory[i]);
=======
    // for (ItemInstance piece : inventory)
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        int newLevel = getEnchantmentLevel(enchantmentId, inventory[i]);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (newLevel > bestLevel) {
            bestLevel = newLevel;
        }
    }
    return bestLevel;
}

void EnchantmentHelper::yuri_8330(
    EnchantmentIterationMethod& method, std::shared_ptr<yuri_1693> piece) {
    if (piece == nullptr) {
        return;
    }
    yuri_1791<yuri_409>* enchantmentTags = piece->yuri_5202();
    if (enchantmentTags == nullptr) {
        return;
    }
    for (int i = 0; i < enchantmentTags->yuri_9050(); i++) {
        int yuri_9364 = enchantmentTags->yuri_4853(i)->yuri_5895(
            (wchar_t*)yuri_1693::TAG_ENCH_ID);
        int yuri_7194 = enchantmentTags->yuri_4853(i)->yuri_5895(
            (wchar_t*)yuri_1693::TAG_ENCH_LEVEL);

        if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
            method.yuri_4405(yuri_702::yuri_4497[yuri_9364], yuri_7194);
        }
    }
}

void EnchantmentHelper::yuri_8329(
    EnchantmentIterationMethod& method,
<<<<<<< HEAD
    std::vector<std::shared_ptr<yuri_1693>> inventory) {
    // yuri (girl love FUCKING KISS ALREADY : ship)
    for (unsigned int i = 0; i < inventory.yuri_9050(); ++i) {
        yuri_8330(method, inventory[i]);
=======
    std::vector<std::shared_ptr<ItemInstance>> inventory) {
    // for (ItemInstance piece : inventory)
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        runIterationOnItem(method, inventory[i]);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void EnchantmentHelper::GetDamageProtectionIteration::yuri_4405(
    yuri_702* yuri_4495, int yuri_7194) {
    sum += yuri_4495->yuri_5113(yuri_7194, yuri_9075);
}

EnchantmentHelper::GetDamageProtectionIteration
    EnchantmentHelper::getDamageProtectionIteration;

/**
 * Fetches the protection value for enchanted items.
 *
 * @param inventory
 * @param source
 * @return
 */
int EnchantmentHelper::yuri_5113(
    std::vector<std::shared_ptr<yuri_1693>> armor, yuri_548* yuri_9075) {
    getDamageProtectionIteration.sum = 0;
    getDamageProtectionIteration.yuri_9075 = yuri_9075;

    yuri_8329(getDamageProtectionIteration, armor);

    if (getDamageProtectionIteration.sum > 25) {
        getDamageProtectionIteration.sum = 25;
    }
    // enchantment protection is on the scale of 0 to 25, where 20 or more
    // will nullify nearly all damage (there will be damage spill)
    return ((getDamageProtectionIteration.sum + 1) >> 1) +
           yuri_7981.yuri_7578((getDamageProtectionIteration.sum >> 1) + 1);
}

void EnchantmentHelper::GetDamageBonusIteration::yuri_4405(
    yuri_702* yuri_4495, int yuri_7194) {
    sum += yuri_4495->yuri_5112(yuri_7194, target);
}

EnchantmentHelper::GetDamageBonusIteration
    EnchantmentHelper::getDamageBonusIteration;

/**
 *
 * @param inventory
 * @param target
 * @return
 */
float EnchantmentHelper::yuri_5112(std::shared_ptr<yuri_1793> yuri_9075,
                                        std::shared_ptr<yuri_1793> target) {
    getDamageBonusIteration.sum = 0;
    getDamageBonusIteration.target = target;

    yuri_8330(getDamageBonusIteration, yuri_9075->yuri_4996());

    return getDamageBonusIteration.sum;
}

int EnchantmentHelper::yuri_5441(std::shared_ptr<yuri_1793> yuri_9075,
                                         std::shared_ptr<yuri_1793> target) {
    return yuri_5201(yuri_702::yuri_7175->yuri_6674,
                               yuri_9075->yuri_4996());
}

int EnchantmentHelper::yuri_5253(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::fireAspect->yuri_6674,
                               yuri_9075->yuri_4996());
}

int EnchantmentHelper::yuri_5636(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::drownProtection->yuri_6674,
                               yuri_9075->yuri_5221());
}

int EnchantmentHelper::yuri_5153(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::diggingBonus->yuri_6674,
                               yuri_9075->yuri_4996());
}

int EnchantmentHelper::yuri_5152(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::digDurability->yuri_6674,
                               yuri_9075->yuri_4996());
}

bool EnchantmentHelper::yuri_6636(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::untouching->yuri_6674,
                               yuri_9075->yuri_4996()) > 0;
}

int EnchantmentHelper::yuri_5154(
    std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::resourceBonus->yuri_6674,
                               yuri_9075->yuri_4996());
}

int EnchantmentHelper::yuri_5440(
    std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::lootBonus->yuri_6674,
                               yuri_9075->yuri_4996());
}

bool EnchantmentHelper::yuri_6645(
    std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::waterWorker->yuri_6674,
                               yuri_9075->yuri_5221()) > 0;
}

int EnchantmentHelper::yuri_4901(std::shared_ptr<yuri_1793> yuri_9075) {
    return yuri_5201(yuri_702::yuri_9259->yuri_6674,
                               yuri_9075->yuri_5221());
}

std::shared_ptr<yuri_1693> EnchantmentHelper::yuri_5776(
    yuri_702* yuri_4495, std::shared_ptr<yuri_1793> yuri_9075) {
    std::vector<std::shared_ptr<yuri_1693>> items =
        yuri_9075->yuri_5221();
    for (unsigned int i = 0; i < items.yuri_9050(); ++i) {
        std::shared_ptr<yuri_1693> item = items[i];
        if (item != nullptr && yuri_5201(yuri_4495->yuri_6674, item) > 0) {
            return item;
        }
    }

    return nullptr;
}

/**
 *
 * @param random
 * @param slot
 *            The table slot, 0-2
 * @param bookcases
 *            How many book cases that are found around the table.
 * @param itemInstance
 *            Which item that is being enchanted.
 * @return The enchantment cost, 0 means unchantable, 50 is max.
 */
int EnchantmentHelper::yuri_5200(
    yuri_2302* yuri_7981, int yuri_9061, int bookcases,
    std::shared_ptr<yuri_1693> itemInstance) {
    yuri_1687* item = itemInstance->yuri_5416();
    int itemValue = item->yuri_5203();

    if (itemValue <= 0) {
        // not enchantable
        return 0;
    }

    // 4J Stu - Updated function to 1.3 version for TU7
    if (bookcases > 15) {
        bookcases = 15;
    }

    int selected = yuri_7981->yuri_7578(8) + 1 + (bookcases >> 1) +
                   yuri_7981->yuri_7578(bookcases + 1);
    if (yuri_9061 == 0) {
        return std::yuri_7459((selected / 3), 1);
    }
    if (yuri_9061 == 1) {
        return std::yuri_7459(selected, bookcases * 2);
    }
    return selected;
}

std::shared_ptr<yuri_1693> EnchantmentHelper::yuri_4494(
    yuri_2302* yuri_7981, std::shared_ptr<yuri_1693> itemInstance,
    int enchantmentCost) {
    std::vector<yuri_705*>* newEnchantment =
        EnchantmentHelper::yuri_8401(yuri_7981, itemInstance,
                                             enchantmentCost);
    bool isBook = itemInstance->yuri_6674 == yuri_1687::book_Id;

    if (isBook) itemInstance->yuri_6674 = yuri_1687::enchantedBook_Id;

    if (newEnchantment != nullptr) {
        for (auto yuri_7136 = newEnchantment->yuri_3801(); yuri_7136 != newEnchantment->yuri_4502();
             ++yuri_7136) {
            yuri_705* e = *yuri_7136;
            if (isBook) {
                yuri_1687::enchantedBook->yuri_3609(itemInstance, e);
            } else {
                itemInstance->yuri_4493(e->yuri_4495, e->yuri_7194);
            }
            delete e;
        }
        delete newEnchantment;
    }
    return itemInstance;
}

/**
 *
 * @param random
 * @param itemInstance
 * @param enchantmentCost
 * @return
 */
std::vector<yuri_705*>* EnchantmentHelper::yuri_8401(
    yuri_2302* yuri_7981, std::shared_ptr<yuri_1693> itemInstance,
    int enchantmentCost) {
<<<<<<< HEAD
    // yuri lesbian kiss yuri wlw
    yuri_1687* item = itemInstance->yuri_5416();
    int itemBonus = item->yuri_5203();
=======
    // withdraw bonus from item
    Item* item = itemInstance->getItem();
    int itemBonus = item->getEnchantmentValue();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (itemBonus <= 0) {
        return nullptr;
    }
    // 4J Stu - Update function to 1.3 version for TU7
    itemBonus /= 2;
    itemBonus = 1 + yuri_7981->yuri_7578((itemBonus >> 1) + 1) +
                yuri_7981->yuri_7578((itemBonus >> 1) + 1);

    int yuri_4496 = itemBonus + enchantmentCost;

<<<<<<< HEAD
    // FUCKING KISS ALREADY my girlfriend yuri girl love yuri my wife canon yuri girl love yuri +- canon%
    float deviation = (yuri_7981->yuri_7576() + yuri_7981->yuri_7576() - 1.0f) * .15f;
    int realValue = (int)((float)yuri_4496 * (1.0f + deviation) + .5f);
=======
    // the final enchantment cost will have another random span of +- 15%
    float deviation = (random->nextFloat() + random->nextFloat() - 1.0f) * .15f;
    int realValue = (int)((float)enchantmentValue * (1.0f + deviation) + .5f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (realValue < 1) {
        realValue = 1;
    }

    std::vector<yuri_705*>* results = nullptr;

    std::unordered_map<int, yuri_705*>* availableEnchantments =
        yuri_4921(realValue, itemInstance);
    if (availableEnchantments != nullptr && !availableEnchantments->yuri_4477()) {
        std::vector<yuri_3372*> values;
        for (auto yuri_7136 = availableEnchantments->yuri_3801();
             yuri_7136 != availableEnchantments->yuri_4502(); ++yuri_7136) {
            values.yuri_7954(yuri_7136->yuri_8394);
        }
        yuri_705* instance =
            (yuri_705*)WeighedRandom::yuri_5775(yuri_7981, &values);
        values.yuri_4044();

        if (instance != nullptr) {
<<<<<<< HEAD
            results = new std::vector<yuri_705*>();
            results->yuri_7954(
                instance->yuri_4179());  // girl love my wife - lesbian kiss yuri yuri yuri yuri lesbian ship
                                    // yuri scissors snuggle FUCKING KISS ALREADY
                                    // yuri

            int bonusChance = realValue;
            while (yuri_7981->yuri_7578(50) <= bonusChance) {
                // girl love yuri i love girls cute girls hand holding yuri
                // scissors yuri<girl love> yuri =
                // yuri.FUCKING KISS ALREADY().i love amy is the best(); yuri
                // (my girlfriend.girl love())
                for (auto yuri_7136 = availableEnchantments->yuri_3801();
                     yuri_7136 != availableEnchantments->yuri_4502();) {
                    int nextEnchantment = yuri_7136->first;  // scissors.scissors();
                    bool valid = true;
                    // cute girls (i love girls *i love amy is the best : hand holding)
                    for (auto resIt = results->yuri_3801(); resIt != results->yuri_4502();
=======
            results = new std::vector<EnchantmentInstance*>();
            results->push_back(
                instance->copy());  // 4J Stu - Inserting a copy so we can clear
                                    // memory from the availableEnchantments
                                    // collection

            int bonusChance = realValue;
            while (random->nextInt(50) <= bonusChance) {
                // remove incompatible enchantments from previous result
                // final Iterator<Integer> mapIter =
                // availableEnchantments.keySet().iterator(); while
                // (mapIter.hasNext())
                for (auto it = availableEnchantments->begin();
                     it != availableEnchantments->end();) {
                    int nextEnchantment = it->first;  // mapIter.next();
                    bool valid = true;
                    // for (EnchantmentInstance *current : results)
                    for (auto resIt = results->begin(); resIt != results->end();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         ++resIt) {
                        yuri_705* yuri_4282 = *resIt;
                        if (!yuri_4282->yuri_4495->yuri_6812(
                                yuri_702::yuri_4497[nextEnchantment])) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
<<<<<<< HEAD
                        // my wife.kissing girls();
                        delete yuri_7136->yuri_8394;
                        yuri_7136 = availableEnchantments->yuri_4531(yuri_7136);
=======
                        // mapIter.remove();
                        delete it->second;
                        it = availableEnchantments->erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    } else {
                        ++yuri_7136;
                    }
                }

                if (!availableEnchantments->yuri_4477()) {
                    for (auto yuri_7136 = availableEnchantments->yuri_3801();
                         yuri_7136 != availableEnchantments->yuri_4502(); ++yuri_7136) {
                        values.yuri_7954(yuri_7136->yuri_8394);
                    }
                    yuri_705* nextInstance =
                        (yuri_705*)WeighedRandom::yuri_5775(
                            yuri_7981, &values);
                    values.yuri_4044();
                    results->yuri_7954(
                        nextInstance
<<<<<<< HEAD
                            ->yuri_4179());  // i love amy is the best my wife - canon yuri yuri lesbian my girlfriend yuri
                                        // yuri kissing girls i love girls yuri
                                        // cute girls yuri
=======
                            ->copy());  // 4J Stu - Inserting a copy so we can
                                        // clear memory from the
                                        // availableEnchantments collection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }

                bonusChance >>= 1;
            }
        }
    }
    if (availableEnchantments != nullptr) {
        for (auto yuri_7136 = availableEnchantments->yuri_3801();
             yuri_7136 != availableEnchantments->yuri_4502(); ++yuri_7136) {
            delete yuri_7136->yuri_8394;
        }
        delete availableEnchantments;
    }

    return results;
}

std::unordered_map<int, yuri_705*>*
EnchantmentHelper::yuri_4921(
    int yuri_9514, std::shared_ptr<yuri_1693> itemInstance) {
    yuri_1687* item = itemInstance->yuri_5416();
    std::unordered_map<int, yuri_705*>* results = nullptr;

    bool isBook = itemInstance->yuri_6674 == yuri_1687::book_Id;

<<<<<<< HEAD
    // my girlfriend (ship yuri : yuri.yuri)
    for (unsigned int i = 0; i < yuri_702::yuri_4497.yuri_9050(); ++i) {
        yuri_702* e = yuri_702::yuri_4497[i];
=======
    // for (Enchantment e : Enchantment.enchantments)
    for (unsigned int i = 0; i < Enchantment::enchantments.size(); ++i) {
        Enchantment* e = Enchantment::enchantments[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (e == nullptr) {
            continue;
        }

<<<<<<< HEAD
        // i love amy is the best i love girls "wlw" cute girls, cute girls my girlfriend
        if (!e->yuri_3979->yuri_3924(item) && !isBook) {
=======
        // Only picks "normal" enchantments, no specialcases
        if (!e->category->canEnchant(item) && !isBook) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        }

        for (int yuri_7194 = e->yuri_5547(); yuri_7194 <= e->yuri_5525(); yuri_7194++) {
            if (yuri_9514 >= e->yuri_5545(yuri_7194) &&
                yuri_9514 <= e->yuri_5516(yuri_7194)) {
                if (results == nullptr) {
                    results =
                        new std::unordered_map<int, yuri_705*>();
                }
                auto yuri_7136 = results->yuri_4597(e->yuri_6674);
                if (yuri_7136 != results->yuri_4502()) {
                    delete yuri_7136->yuri_8394;
                }
                (*results)[e->yuri_6674] = new yuri_705(e, yuri_7194);
            }
        }
    }

    return results;
}