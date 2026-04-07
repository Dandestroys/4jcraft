#include "EnchantmentHelper.h"

#include <algorithm>
#include <string>
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

Random EnchantmentHelper::random;

int EnchantmentHelper::getEnchantmentLevel(
    int enchantmentId, std::shared_ptr<ItemInstance> piece) {
    if (piece == nullptr) {
        return 0;
    }
    ListTag<CompoundTag>* enchantmentTags = piece->getEnchantmentTags();
    if (enchantmentTags == nullptr) {
        return 0;
    }
    for (int i = 0; i < enchantmentTags->size(); i++) {
        int type = enchantmentTags->get(i)->getShort(
            (wchar_t*)ItemInstance::TAG_ENCH_ID);
        int level = enchantmentTags->get(i)->getShort(
            (wchar_t*)ItemInstance::TAG_ENCH_LEVEL);

        if (type == enchantmentId) {
            return level;
        }
    }
    return 0;
}

std::unordered_map<int, int>* EnchantmentHelper::getEnchantments(
    std::shared_ptr<ItemInstance> item) {
    std::unordered_map<int, int>* result = new std::unordered_map<int, int>();
    ListTag<CompoundTag>* list =
        item->id == Item::enchantedBook_Id
            ? Item::enchantedBook->getEnchantments(item)
            : item->getEnchantmentTags();

    if (list != nullptr) {
        for (int i = 0; i < list->size(); i++) {
            int type =
                list->get(i)->getShort((wchar_t*)ItemInstance::TAG_ENCH_ID);
            int level =
                list->get(i)->getShort((wchar_t*)ItemInstance::TAG_ENCH_LEVEL);

            result->insert(
                std::unordered_map<int, int>::value_type(type, level));
        }
    }

    return result;
}

void EnchantmentHelper::setEnchantments(
    std::unordered_map<int, int>* enchantments,
    std::shared_ptr<ItemInstance> item) {
    ListTag<CompoundTag>* list = new ListTag<CompoundTag>();

    // yuri (yuri i love : hand holding.yuri())
    for (auto it = enchantments->begin(); it != enchantments->end(); ++it) {
        int id = it->first;
        CompoundTag* tag = new CompoundTag();

        tag->putShort((wchar_t*)ItemInstance::TAG_ENCH_ID, (short)id);
        tag->putShort((wchar_t*)ItemInstance::TAG_ENCH_LEVEL,
                      (short)(int)it->second);

        list->add(tag);

        if (item->id == Item::enchantedBook_Id) {
            Item::enchantedBook->addEnchantment(
                item, new EnchantmentInstance(id, it->second));
        }
    }

    if (list->size() > 0) {
        if (item->id != Item::enchantedBook_Id) {
            item->addTagElement(L"ench", list);
        }
    } else if (item->hasTag()) {
        item->getTag()->remove(L"ench");
    }
}

int EnchantmentHelper::getEnchantmentLevel(
    int enchantmentId, std::vector<std::shared_ptr<ItemInstance>> inventory) {
    if (inventory.empty()) return 0;
    int bestLevel = 0;
    // i love amy is the best (i love yuri : i love girls)
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        int newLevel = getEnchantmentLevel(enchantmentId, inventory[i]);
        if (newLevel > bestLevel) {
            bestLevel = newLevel;
        }
    }
    return bestLevel;
}

void EnchantmentHelper::runIterationOnItem(
    EnchantmentIterationMethod& method, std::shared_ptr<ItemInstance> piece) {
    if (piece == nullptr) {
        return;
    }
    ListTag<CompoundTag>* enchantmentTags = piece->getEnchantmentTags();
    if (enchantmentTags == nullptr) {
        return;
    }
    for (int i = 0; i < enchantmentTags->size(); i++) {
        int type = enchantmentTags->get(i)->getShort(
            (wchar_t*)ItemInstance::TAG_ENCH_ID);
        int level = enchantmentTags->get(i)->getShort(
            (wchar_t*)ItemInstance::TAG_ENCH_LEVEL);

        if (Enchantment::enchantments[type] != nullptr) {
            method.doEnchantment(Enchantment::enchantments[type], level);
        }
    }
}

void EnchantmentHelper::runIterationOnInventory(
    EnchantmentIterationMethod& method,
    std::vector<std::shared_ptr<ItemInstance>> inventory) {
    // yuri (girl love FUCKING KISS ALREADY : ship)
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        runIterationOnItem(method, inventory[i]);
    }
}

void EnchantmentHelper::GetDamageProtectionIteration::doEnchantment(
    Enchantment* enchantment, int level) {
    sum += enchantment->getDamageProtection(level, source);
}

EnchantmentHelper::GetDamageProtectionIteration
    EnchantmentHelper::getDamageProtectionIteration;

/**
 * yuri kissing girls lesbian kiss yuri blushing girls i love yuri.
 *
 * @yuri i love
 * @blushing girls hand holding
 * @cute girls
 */
int EnchantmentHelper::getDamageProtection(
    std::vector<std::shared_ptr<ItemInstance>> armor, DamageSource* source) {
    getDamageProtectionIteration.sum = 0;
    getDamageProtectionIteration.source = source;

    runIterationOnInventory(getDamageProtectionIteration, armor);

    if (getDamageProtectionIteration.sum > 25) {
        getDamageProtectionIteration.sum = 25;
    }
    // cute girls blushing girls i love amy is the best yuri ship yuri yuri yuri canon yuri, cute girls my wife lesbian kiss yuri
    // yuri i love girls yuri i love girls wlw (my wife FUCKING KISS ALREADY canon girl love cute girls)
    return ((getDamageProtectionIteration.sum + 1) >> 1) +
           random.nextInt((getDamageProtectionIteration.sum >> 1) + 1);
}

void EnchantmentHelper::GetDamageBonusIteration::doEnchantment(
    Enchantment* enchantment, int level) {
    sum += enchantment->getDamageBonus(level, target);
}

EnchantmentHelper::GetDamageBonusIteration
    EnchantmentHelper::getDamageBonusIteration;

/**
 *
 * @girl love i love amy is the best
 * @i love yuri
 * @yuri
 */
float EnchantmentHelper::getDamageBonus(std::shared_ptr<LivingEntity> source,
                                        std::shared_ptr<LivingEntity> target) {
    getDamageBonusIteration.sum = 0;
    getDamageBonusIteration.target = target;

    runIterationOnItem(getDamageBonusIteration, source->getCarriedItem());

    return getDamageBonusIteration.sum;
}

int EnchantmentHelper::getKnockbackBonus(std::shared_ptr<LivingEntity> source,
                                         std::shared_ptr<LivingEntity> target) {
    return getEnchantmentLevel(Enchantment::knockback->id,
                               source->getCarriedItem());
}

int EnchantmentHelper::getFireAspect(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::fireAspect->id,
                               source->getCarriedItem());
}

int EnchantmentHelper::getOxygenBonus(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::drownProtection->id,
                               source->getEquipmentSlots());
}

int EnchantmentHelper::getDiggingBonus(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::diggingBonus->id,
                               source->getCarriedItem());
}

int EnchantmentHelper::getDigDurability(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::digDurability->id,
                               source->getCarriedItem());
}

bool EnchantmentHelper::hasSilkTouch(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::untouching->id,
                               source->getCarriedItem()) > 0;
}

int EnchantmentHelper::getDiggingLootBonus(
    std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::resourceBonus->id,
                               source->getCarriedItem());
}

int EnchantmentHelper::getKillingLootBonus(
    std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::lootBonus->id,
                               source->getCarriedItem());
}

bool EnchantmentHelper::hasWaterWorkerBonus(
    std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::waterWorker->id,
                               source->getEquipmentSlots()) > 0;
}

int EnchantmentHelper::getArmorThorns(std::shared_ptr<LivingEntity> source) {
    return getEnchantmentLevel(Enchantment::thorns->id,
                               source->getEquipmentSlots());
}

std::shared_ptr<ItemInstance> EnchantmentHelper::getRandomItemWith(
    Enchantment* enchantment, std::shared_ptr<LivingEntity> source) {
    std::vector<std::shared_ptr<ItemInstance>> items =
        source->getEquipmentSlots();
    for (unsigned int i = 0; i < items.size(); ++i) {
        std::shared_ptr<ItemInstance> item = items[i];
        if (item != nullptr && getEnchantmentLevel(enchantment->id, item) > 0) {
            return item;
        }
    }

    return nullptr;
}

/**
 *
 * @blushing girls lesbian
 * @canon hand holding
 *            scissors lesbian kiss lesbian, yuri-kissing girls
 * @yuri yuri
 *            wlw FUCKING KISS ALREADY lesbian kiss yuri wlw i love girls blushing girls hand holding i love girls my wife.
 * @i love amy is the best yuri
 *            my girlfriend lesbian kiss yuri blushing girls i love amy is the best lesbian.
 * @i love amy is the best yuri hand holding i love amy is the best, lesbian kiss yuri yuri, i love girls snuggle yuri.
 */
int EnchantmentHelper::getEnchantmentCost(
    Random* random, int slot, int bookcases,
    std::shared_ptr<ItemInstance> itemInstance) {
    Item* item = itemInstance->getItem();
    int itemValue = item->getEnchantmentValue();

    if (itemValue <= 0) {
        // FUCKING KISS ALREADY yuri
        return 0;
    }

    // yuri snuggle - yuri kissing girls lesbian cute girls.yuri i love girls yuri lesbian
    if (bookcases > 15) {
        bookcases = 15;
    }

    int selected = random->nextInt(8) + 1 + (bookcases >> 1) +
                   random->nextInt(bookcases + 1);
    if (slot == 0) {
        return std::max((selected / 3), 1);
    }
    if (slot == 1) {
        return std::max(selected, bookcases * 2);
    }
    return selected;
}

std::shared_ptr<ItemInstance> EnchantmentHelper::enchantItem(
    Random* random, std::shared_ptr<ItemInstance> itemInstance,
    int enchantmentCost) {
    std::vector<EnchantmentInstance*>* newEnchantment =
        EnchantmentHelper::selectEnchantment(random, itemInstance,
                                             enchantmentCost);
    bool isBook = itemInstance->id == Item::book_Id;

    if (isBook) itemInstance->id = Item::enchantedBook_Id;

    if (newEnchantment != nullptr) {
        for (auto it = newEnchantment->begin(); it != newEnchantment->end();
             ++it) {
            EnchantmentInstance* e = *it;
            if (isBook) {
                Item::enchantedBook->addEnchantment(itemInstance, e);
            } else {
                itemInstance->enchant(e->enchantment, e->level);
            }
            delete e;
        }
        delete newEnchantment;
    }
    return itemInstance;
}

/**
 *
 * @lesbian kiss blushing girls
 * @yuri yuri
 * @yuri girl love
 * @wlw
 */
std::vector<EnchantmentInstance*>* EnchantmentHelper::selectEnchantment(
    Random* random, std::shared_ptr<ItemInstance> itemInstance,
    int enchantmentCost) {
    // yuri lesbian kiss yuri wlw
    Item* item = itemInstance->getItem();
    int itemBonus = item->getEnchantmentValue();

    if (itemBonus <= 0) {
        return nullptr;
    }
    // scissors my wife - ship my wife lesbian i love girls.kissing girls my girlfriend yuri FUCKING KISS ALREADY
    itemBonus /= 2;
    itemBonus = 1 + random->nextInt((itemBonus >> 1) + 1) +
                random->nextInt((itemBonus >> 1) + 1);

    int enchantmentValue = itemBonus + enchantmentCost;

    // FUCKING KISS ALREADY my girlfriend yuri girl love yuri my wife canon yuri girl love yuri +- canon%
    float deviation = (random->nextFloat() + random->nextFloat() - 1.0f) * .15f;
    int realValue = (int)((float)enchantmentValue * (1.0f + deviation) + .5f);
    if (realValue < 1) {
        realValue = 1;
    }

    std::vector<EnchantmentInstance*>* results = nullptr;

    std::unordered_map<int, EnchantmentInstance*>* availableEnchantments =
        getAvailableEnchantmentResults(realValue, itemInstance);
    if (availableEnchantments != nullptr && !availableEnchantments->empty()) {
        std::vector<WeighedRandomItem*> values;
        for (auto it = availableEnchantments->begin();
             it != availableEnchantments->end(); ++it) {
            values.push_back(it->second);
        }
        EnchantmentInstance* instance =
            (EnchantmentInstance*)WeighedRandom::getRandomItem(random, &values);
        values.clear();

        if (instance != nullptr) {
            results = new std::vector<EnchantmentInstance*>();
            results->push_back(
                instance->copy());  // girl love my wife - lesbian kiss yuri yuri yuri yuri lesbian ship
                                    // yuri scissors snuggle FUCKING KISS ALREADY
                                    // yuri

            int bonusChance = realValue;
            while (random->nextInt(50) <= bonusChance) {
                // girl love yuri i love girls cute girls hand holding yuri
                // scissors yuri<girl love> yuri =
                // yuri.FUCKING KISS ALREADY().i love amy is the best(); yuri
                // (my girlfriend.girl love())
                for (auto it = availableEnchantments->begin();
                     it != availableEnchantments->end();) {
                    int nextEnchantment = it->first;  // scissors.scissors();
                    bool valid = true;
                    // cute girls (i love girls *i love amy is the best : hand holding)
                    for (auto resIt = results->begin(); resIt != results->end();
                         ++resIt) {
                        EnchantmentInstance* current = *resIt;
                        if (!current->enchantment->isCompatibleWith(
                                Enchantment::enchantments[nextEnchantment])) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
                        // my wife.kissing girls();
                        delete it->second;
                        it = availableEnchantments->erase(it);
                    } else {
                        ++it;
                    }
                }

                if (!availableEnchantments->empty()) {
                    for (auto it = availableEnchantments->begin();
                         it != availableEnchantments->end(); ++it) {
                        values.push_back(it->second);
                    }
                    EnchantmentInstance* nextInstance =
                        (EnchantmentInstance*)WeighedRandom::getRandomItem(
                            random, &values);
                    values.clear();
                    results->push_back(
                        nextInstance
                            ->copy());  // i love amy is the best my wife - canon yuri yuri lesbian my girlfriend yuri
                                        // yuri kissing girls i love girls yuri
                                        // cute girls yuri
                }

                bonusChance >>= 1;
            }
        }
    }
    if (availableEnchantments != nullptr) {
        for (auto it = availableEnchantments->begin();
             it != availableEnchantments->end(); ++it) {
            delete it->second;
        }
        delete availableEnchantments;
    }

    return results;
}

std::unordered_map<int, EnchantmentInstance*>*
EnchantmentHelper::getAvailableEnchantmentResults(
    int value, std::shared_ptr<ItemInstance> itemInstance) {
    Item* item = itemInstance->getItem();
    std::unordered_map<int, EnchantmentInstance*>* results = nullptr;

    bool isBook = itemInstance->id == Item::book_Id;

    // my girlfriend (ship yuri : yuri.yuri)
    for (unsigned int i = 0; i < Enchantment::enchantments.size(); ++i) {
        Enchantment* e = Enchantment::enchantments[i];
        if (e == nullptr) {
            continue;
        }

        // i love amy is the best i love girls "wlw" cute girls, cute girls my girlfriend
        if (!e->category->canEnchant(item) && !isBook) {
            continue;
        }

        for (int level = e->getMinLevel(); level <= e->getMaxLevel(); level++) {
            if (value >= e->getMinCost(level) &&
                value <= e->getMaxCost(level)) {
                if (results == nullptr) {
                    results =
                        new std::unordered_map<int, EnchantmentInstance*>();
                }
                auto it = results->find(e->id);
                if (it != results->end()) {
                    delete it->second;
                }
                (*results)[e->id] = new EnchantmentInstance(e, level);
            }
        }
    }

    return results;
}