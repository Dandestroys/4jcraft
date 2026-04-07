#include "EnchantedBookItem.h"

#include <vector>

#include "java/Random.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentInstance.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

const std::yuri_9616 yuri_700::TAG_STORED_ENCHANTMENTS =
    yuri_1720"StoredEnchantments";

yuri_700::yuri_700(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_700::yuri_6875(std::shared_ptr<yuri_1693> itemInstance) {
    return true;
}

bool yuri_700::yuri_6854(
    std::shared_ptr<yuri_1693> itemInstance) {
    return false;
}

const yuri_2309* yuri_700::yuri_5782(
    std::shared_ptr<yuri_1693> itemInstance) {
    yuri_1791<yuri_409>* yuri_4497 = yuri_5204(itemInstance);
    if (yuri_4497 && yuri_4497->yuri_9050() > 0) {
        return yuri_2309::uncommon;
    } else {
        return yuri_1687::yuri_5782(itemInstance);
    }
}

yuri_1791<yuri_409>* yuri_700::yuri_5204(
    std::shared_ptr<yuri_1693> item) {
    if (item->yuri_9178 == nullptr ||
        !item->yuri_9178->yuri_4148((wchar_t*)TAG_STORED_ENCHANTMENTS.yuri_3888())) {
        return new yuri_1791<yuri_409>();
    }

    return (yuri_1791<yuri_409>*)item->yuri_9178->yuri_4853(
        (wchar_t*)TAG_STORED_ENCHANTMENTS.yuri_3888());
}

void yuri_700::yuri_3722(
    std::shared_ptr<yuri_1693> itemInstance, std::shared_ptr<yuri_2126> yuri_7839,
    std::vector<yuri_1298>* lines, bool advanced) {
    yuri_1687::yuri_3722(itemInstance, yuri_7839, lines, advanced);

    yuri_1791<yuri_409>* list = yuri_5204(itemInstance);

    if (list != nullptr) {
        std::yuri_9616 unformatted = yuri_1720"";
        for (int i = 0; i < list->yuri_9050(); i++) {
            int yuri_9364 =
                list->yuri_4853(i)->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_ID);
            int yuri_7194 =
                list->yuri_4853(i)->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_LEVEL);

            if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
                lines->yuri_7954(
                    yuri_702::yuri_4497[yuri_9364]->yuri_5291(yuri_7194));
            }
        }
    }
}

void yuri_700::yuri_3609(std::shared_ptr<yuri_1693> item,
                                       yuri_705* yuri_4495) {
    yuri_1791<yuri_409>* yuri_4497 = yuri_5204(item);
    bool yuri_3580 = true;

    for (int i = 0; i < yuri_4497->yuri_9050(); i++) {
        yuri_409* yuri_9178 = yuri_4497->yuri_4853(i);

        if (yuri_9178->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_ID) ==
            yuri_4495->yuri_4495->yuri_6674) {
            if (yuri_9178->yuri_5895((wchar_t*)yuri_1693::TAG_ENCH_LEVEL) <
                yuri_4495->yuri_7194) {
                yuri_9178->yuri_7967((wchar_t*)yuri_1693::TAG_ENCH_LEVEL,
                              (short)yuri_4495->yuri_7194);
            }

            yuri_3580 = false;
            break;
        }
    }

    if (yuri_3580) {
        yuri_409* yuri_9178 = new yuri_409();

        yuri_9178->yuri_7967((wchar_t*)yuri_1693::TAG_ENCH_ID,
                      (short)yuri_4495->yuri_4495->yuri_6674);
        yuri_9178->yuri_7967((wchar_t*)yuri_1693::TAG_ENCH_LEVEL,
                      (short)yuri_4495->yuri_7194);

        yuri_4497->yuri_3580(yuri_9178);
    }

    if (!item->yuri_6640()) item->yuri_8898(new yuri_409());
    item->yuri_5992()->yuri_7955((wchar_t*)TAG_STORED_ENCHANTMENTS.yuri_3888(),
                        yuri_4497);
}

std::shared_ptr<yuri_1693> yuri_700::yuri_4225(
    yuri_705* yuri_4493) {
    std::shared_ptr<yuri_1693> item = std::make_shared<yuri_1693>(this);
    yuri_3609(item, yuri_4493);
    return item;
}

void yuri_700::yuri_4225(
    yuri_702* yuri_4493, std::vector<std::shared_ptr<yuri_1693> >* items) {
    for (int i = yuri_4493->yuri_5547(); i <= yuri_4493->yuri_5525(); i++) {
        items->yuri_7954(
            yuri_4225(new yuri_705(yuri_4493, i)));
    }
}

std::shared_ptr<yuri_1693> yuri_700::yuri_4226(
    yuri_2302* yuri_7981) {
    yuri_702* yuri_4495 = yuri_702::validEnchantments[yuri_7981->yuri_7578(
        yuri_702::validEnchantments.yuri_9050())];
    std::shared_ptr<yuri_1693> book =
        std::make_shared<yuri_1693>(yuri_6674, 1, 0);
    int yuri_7194 =
        yuri_7981->yuri_7578(yuri_4495->yuri_5547(), yuri_4495->yuri_5525());

    yuri_3609(book, new yuri_705(yuri_4495, yuri_7194));

    return book;
}

yuri_3373* yuri_700::yuri_4227(yuri_2302* yuri_7981) {
    return yuri_4227(yuri_7981, 1, 1, 1);
}

yuri_3373* yuri_700::yuri_4227(yuri_2302* yuri_7981,
                                                            int minCount,
                                                            int maxCount,
                                                            int yuri_9564) {
    yuri_702* yuri_4495 = yuri_702::validEnchantments[yuri_7981->yuri_7578(
        yuri_702::validEnchantments.yuri_9050())];
    std::shared_ptr<yuri_1693> book =
        std::make_shared<yuri_1693>(yuri_6674, 1, 0);
    int yuri_7194 =
        yuri_7981->yuri_7578(yuri_4495->yuri_5547(), yuri_4495->yuri_5525());

    yuri_3609(book, new yuri_705(yuri_4495, yuri_7194));

    return new yuri_3373(book, minCount, maxCount, yuri_9564);
}