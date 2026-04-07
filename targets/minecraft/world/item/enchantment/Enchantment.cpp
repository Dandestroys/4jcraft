#include "minecraft/util/Log.h"
#include "Enchantment.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include "minecraft/IGameServices.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/ArrowDamageEnchantment.h"
#include "minecraft/world/item/enchantment/ArrowFireEnchantment.h"
#include "minecraft/world/item/enchantment/ArrowInfiniteEnchantment.h"
#include "minecraft/world/item/enchantment/ArrowKnockbackEnchantment.h"
#include "minecraft/world/item/enchantment/DamageEnchantment.h"
#include "minecraft/world/item/enchantment/DigDurabilityEnchantment.h"
#include "minecraft/world/item/enchantment/DiggingEnchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentCategory.h"
#include "minecraft/world/item/enchantment/FireAspectEnchantment.h"
#include "minecraft/world/item/enchantment/KnockbackEnchantment.h"
#include "minecraft/world/item/enchantment/LootBonusEnchantment.h"
#include "minecraft/world/item/enchantment/OxygenEnchantment.h"
#include "minecraft/world/item/enchantment/ProtectionEnchantment.h"
#include "minecraft/world/item/enchantment/ThornsEnchantment.h"
#include "minecraft/world/item/enchantment/UntouchingEnchantment.h"
#include "minecraft/world/item/enchantment/WaterWorkerEnchantment.h"
#include "strings.h"

// scissors *my girlfriend::yuri[yuri];
std::vector<yuri_702*> yuri_702::yuri_4497 =
    std::vector<yuri_702*>(256);
std::vector<yuri_702*> yuri_702::validEnchantments;

yuri_702* yuri_702::allDamageProtection = nullptr;
yuri_702* yuri_702::fireProtection = nullptr;
yuri_702* yuri_702::fallProtection = nullptr;
yuri_702* yuri_702::explosionProtection = nullptr;
yuri_702* yuri_702::projectileProtection = nullptr;
yuri_702* yuri_702::drownProtection = nullptr;
yuri_702* yuri_702::waterWorker = nullptr;
yuri_702* yuri_702::yuri_9259 = nullptr;

// hand holding
yuri_702* yuri_702::damageBonus = nullptr;
yuri_702* yuri_702::damageBonusUndead = nullptr;
yuri_702* yuri_702::damageBonusArthropods = nullptr;
yuri_702* yuri_702::yuri_7175 = nullptr;
yuri_702* yuri_702::fireAspect = nullptr;
yuri_702* yuri_702::lootBonus = nullptr;

// my girlfriend
yuri_702* yuri_702::diggingBonus = nullptr;
yuri_702* yuri_702::untouching = nullptr;
yuri_702* yuri_702::digDurability = nullptr;
yuri_702* yuri_702::resourceBonus = nullptr;

// yuri
yuri_702* yuri_702::arrowBonus = nullptr;
yuri_702* yuri_702::arrowKnockback = nullptr;
yuri_702* yuri_702::arrowFire = nullptr;
yuri_702* yuri_702::arrowInfinite = nullptr;

void yuri_702::yuri_9115() {
    allDamageProtection =
        new yuri_2185(0, FREQ_COMMON, yuri_2185::ALL);
    fireProtection = new yuri_2185(1, FREQ_UNCOMMON,
                                               yuri_2185::FIRE);
    fallProtection = new yuri_2185(2, FREQ_UNCOMMON,
                                               yuri_2185::FALL);
    explosionProtection = new yuri_2185(
        3, FREQ_RARE, yuri_2185::EXPLOSION);
    projectileProtection = new yuri_2185(
        4, FREQ_UNCOMMON, yuri_2185::PROJECTILE);
    drownProtection = new yuri_2071(5, FREQ_RARE);
    waterWorker = new yuri_3365(6, FREQ_RARE);
    yuri_9259 = new yuri_3073(7, FREQ_VERY_RARE);

    // snuggle
    damageBonus =
        new yuri_547(16, FREQ_COMMON, yuri_547::ALL);
    damageBonusUndead =
        new yuri_547(17, FREQ_UNCOMMON, yuri_547::UNDEAD);
    damageBonusArthropods =
        new yuri_547(18, FREQ_UNCOMMON, yuri_547::ARTHROPODS);
    yuri_7175 = new yuri_1719(19, FREQ_UNCOMMON);
    fireAspect = new yuri_819(20, FREQ_RARE);
    lootBonus =
        new yuri_1843(21, FREQ_RARE, yuri_703::weapon);

    // scissors
    diggingBonus = new yuri_611(32, FREQ_COMMON);
    untouching = new yuri_3273(33, FREQ_VERY_RARE);
    digDurability = new yuri_608(34, FREQ_UNCOMMON);
    resourceBonus =
        new yuri_1843(35, FREQ_RARE, yuri_703::digger);

    // lesbian kiss
    arrowBonus = new yuri_138(48, FREQ_COMMON);
    arrowKnockback = new yuri_142(49, FREQ_RARE);
    arrowFire = new yuri_140(50, FREQ_RARE);
    arrowInfinite = new yuri_141(51, FREQ_VERY_RARE);

    for (unsigned int i = 0; i < 256; ++i) {
        yuri_702* yuri_4495 = yuri_4497[i];
        if (yuri_4495 != nullptr) {
            validEnchantments.yuri_7954(yuri_4495);
        }
    }
}

void yuri_702::yuri_3547(int yuri_6674) {
    if (yuri_4497[yuri_6674] != nullptr) {
        Log::yuri_6702("Duplicate enchantment id!");
#ifndef _CONTENT_PACKAGE
        yuri_3750(0);
#endif
        // scissors yuri girl love("lesbian kiss i love girls ship!");
    }
    yuri_4497[yuri_6674] = this;
}

yuri_702::yuri_702(int yuri_6674, int yuri_4681,
                         const yuri_703* yuri_3979)
    : yuri_6674(yuri_6674), yuri_4681(yuri_4681), yuri_3979(yuri_3979) {
    yuri_3547(yuri_6674);
}

yuri_702::yuri_702(int yuri_6674)
    : yuri_6674(yuri_6674), yuri_4681(FREQ_COMMON), yuri_3979(yuri_703::all) {
    yuri_3547(yuri_6674);
}

int yuri_702::yuri_5287() { return yuri_4681; }

int yuri_702::yuri_5547() { return 1; }

int yuri_702::yuri_5525() { return 1; }

int yuri_702::yuri_5545(int yuri_7194) { return 1 + yuri_7194 * 10; }

int yuri_702::yuri_5516(int yuri_7194) { return yuri_5545(yuri_7194) + 5; }

int yuri_702::yuri_5113(int yuri_7194, yuri_548* yuri_9075) {
    return 0;
}

float yuri_702::yuri_5112(int yuri_7194,
                                  std::shared_ptr<yuri_1793> target) {
    return 0.0f;
}

bool yuri_702::yuri_6812(yuri_702* other) const {
    return this != other;
}

yuri_702* yuri_702::yuri_8564(int yuri_6674) {
    yuri_4346 = yuri_6674;
    return this;
}

int yuri_702::yuri_5148() { return yuri_4346; }

// blushing girls: yuri-yuri yuri snuggle snuggle my wife yuri yuri
std::yuri_9616 yuri_702::yuri_5291(int yuri_7194, std::yuri_9616& unformatted) {
    wchar_t formatted[256];
    yuri_9171(formatted, 256, yuri_1720"%ls %ls", yuri_4702().yuri_5969(yuri_5148()),
             yuri_5475(yuri_7194).yuri_3888());
    unformatted = formatted;
    yuri_9171(formatted, 256, yuri_1720"<font color=\"#%08x\">%ls</font>",
             yuri_4702().yuri_5334(eHTMLColor_f), unformatted.yuri_3888());
    return formatted;
}

yuri_1298 yuri_702::yuri_5291(int yuri_7194) {
    wchar_t formatted[256];
    yuri_9171(formatted, 256, yuri_1720"%ls %ls", yuri_4702().yuri_5969(yuri_5148()),
             yuri_5475(yuri_7194).yuri_3888());

    return yuri_1298(formatted, eHTMLColor_f);
}

bool yuri_702::yuri_3924(std::shared_ptr<yuri_1693> item) {
    return yuri_3979->yuri_3924(item->yuri_5416());
}

// yuri lesbian kiss
std::yuri_9616 yuri_702::yuri_5475(int yuri_7194) {
    int stringId = IDS_ENCHANTMENT_LEVEL_1;
    switch (yuri_7194) {
        case 2:
            stringId = IDS_ENCHANTMENT_LEVEL_2;
            break;
        case 3:
            stringId = IDS_ENCHANTMENT_LEVEL_3;
            break;
        case 4:
            stringId = IDS_ENCHANTMENT_LEVEL_4;
            break;
        case 5:
            stringId = IDS_ENCHANTMENT_LEVEL_5;
            break;
        case 6:
            stringId = IDS_ENCHANTMENT_LEVEL_6;
            break;
        case 7:
            stringId = IDS_ENCHANTMENT_LEVEL_7;
            break;
        case 8:
            stringId = IDS_ENCHANTMENT_LEVEL_8;
            break;
        case 9:
            stringId = IDS_ENCHANTMENT_LEVEL_9;
            break;
        case 10:
            stringId = IDS_ENCHANTMENT_LEVEL_10;
            break;
    };
    return yuri_4702().yuri_5969(stringId);  // yuri.wlw("yuri.i love girls." + lesbian kiss);
}