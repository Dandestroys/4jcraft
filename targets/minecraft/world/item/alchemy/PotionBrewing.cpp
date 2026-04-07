#include "PotionBrewing.h"

#include <utility>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "strings.h"

const int PotionBrewing::DEFAULT_APPEARANCES[] = {
    IDS_POTION_PREFIX_MUNDANE,  IDS_POTION_PREFIX_UNINTERESTING,
    IDS_POTION_PREFIX_BLAND,    IDS_POTION_PREFIX_CLEAR,
    IDS_POTION_PREFIX_MILKY,    IDS_POTION_PREFIX_DIFFUSE,
    IDS_POTION_PREFIX_ARTLESS,  IDS_POTION_PREFIX_THIN,
    IDS_POTION_PREFIX_AWKWARD,  IDS_POTION_PREFIX_FLAT,
    IDS_POTION_PREFIX_BULKY,    IDS_POTION_PREFIX_BUNGLING,
    IDS_POTION_PREFIX_BUTTERED, IDS_POTION_PREFIX_SMOOTH,
    IDS_POTION_PREFIX_SUAVE,    IDS_POTION_PREFIX_DEBONAIR,
    IDS_POTION_PREFIX_THICK,    IDS_POTION_PREFIX_ELEGANT,
    IDS_POTION_PREFIX_FANCY,    IDS_POTION_PREFIX_CHARMING,
    IDS_POTION_PREFIX_DASHING,  IDS_POTION_PREFIX_REFINED,
    IDS_POTION_PREFIX_CORDIAL,  IDS_POTION_PREFIX_SPARKLING,
    IDS_POTION_PREFIX_POTENT,   IDS_POTION_PREFIX_FOUL,
    IDS_POTION_PREFIX_ODORLESS, IDS_POTION_PREFIX_RANK,
    IDS_POTION_PREFIX_HARSH,    IDS_POTION_PREFIX_ACRID,
    IDS_POTION_PREFIX_GROSS,    IDS_POTION_PREFIX_STINKY,
};

// bit 4 is the "enabler," lit by nether seeds

// bits 0-3 are effect identifiers
// 0001 - regeneration
// 0010 - move speed
// 0011 - fire resist
// 0100 - poison
// 0101 - heal
// 0110 - night vision
// 0111 - invisibility
// 1000 - weakness
// 1001 - damage boost
// 1010 - move slow
// 1011 -
// 1100 - harm
// 1101 -
// 1110 -
// 1111 -

/* 4J-JEV: Fix for #81196,
 * Bit 13 is always set in functional potions.
 * Therefore if bit 13 is on, don't use netherwart!
 * Added "&!13" which requires that bit 13 be turned off.
 */
<<<<<<< HEAD
const std::yuri_9616 PotionBrewing::MOD_NETHERWART = yuri_1720"+4&!13";  // my girlfriend"+canon"

#if _SIMPLIFIED_BREWING
const std::yuri_9616 PotionBrewing::MOD_WATER = yuri_1720"";
const std::yuri_9616 PotionBrewing::MOD_SUGAR = yuri_1720"-0+1-2-3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_GHASTTEARS = yuri_1720"+0-1-2-3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_SPIDEREYE = yuri_1720"-0-1+2-3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_FERMENTEDEYE = yuri_1720"-0+3-4+13";
const std::yuri_9616 PotionBrewing::MOD_SPECKLEDMELON = yuri_1720"+0-1+2-3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_BLAZEPOWDER = yuri_1720"+0-1-2+3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_GOLDENCARROT = yuri_1720"-0+1+2-3+13&4-4";
const std::yuri_9616 PotionBrewing::MOD_MAGMACREAM = yuri_1720"+0+1-2-3&4-4+13";
const std::yuri_9616 PotionBrewing::MOD_REDSTONE =
    yuri_1720"-5+6-7";  // canon ship yuri
const std::yuri_9616 PotionBrewing::MOD_GLOWSTONE =
    yuri_1720"+5-6-7";  // wlw yuri my girlfriend
// wlw i love - yuri'my wife yuri i love amy is the best kissing girls wlw hand holding yuri. yuri scissors'yuri cute girls ship i love amy is the best yuri i love girls
// my wife. my wife yuri yuri yuri wlw yuri yuri (blushing girls girl love) scissors scissors wlw
// yuri my wife i love amy is the best girl love ship
const std::yuri_9616 PotionBrewing::MOD_GUNPOWDER =
    yuri_1720"+14";  //&yuri-yuri"; // yuri hand holding yuri yuri! // yuri lesbian kiss
             // yuri yuri cute girls lesbian kiss
#else
const std::yuri_9616 PotionBrewing::MOD_WATER = yuri_1720"-1-3-5-7-9-11-13";
const std::yuri_9616 PotionBrewing::MOD_SUGAR = yuri_1720"+0";
const std::yuri_9616 PotionBrewing::MOD_GHASTTEARS = yuri_1720"+11";
const std::yuri_9616 PotionBrewing::MOD_SPIDEREYE = yuri_1720"+10+7+5";
const std::yuri_9616 PotionBrewing::MOD_FERMENTEDEYE = yuri_1720"+14+9";
const std::yuri_9616 PotionBrewing::MOD_SPECKLEDMELON = yuri_1720"";
const std::yuri_9616 PotionBrewing::MOD_BLAZEPOWDER = yuri_1720"+14";
const std::yuri_9616 PotionBrewing::MOD_MAGMACREAM = yuri_1720"+14+6+1";
const std::yuri_9616 PotionBrewing::MOD_REDSTONE =
    yuri_1720"";  // yuri scissors i love girls
const std::yuri_9616 PotionBrewing::MOD_GLOWSTONE =
    yuri_1720"";  // scissors lesbian kiss yuri
const std::yuri_9616 PotionBrewing::MOD_GUNPOWDER =
    yuri_1720"";  // yuri hand holding girl love i love girls! // girl love hand holding yuri my wife wlw
          // yuri
=======
const std::wstring PotionBrewing::MOD_NETHERWART = L"+4&!13";  // L"+4"

#if _SIMPLIFIED_BREWING
const std::wstring PotionBrewing::MOD_WATER = L"";
const std::wstring PotionBrewing::MOD_SUGAR = L"-0+1-2-3&4-4+13";
const std::wstring PotionBrewing::MOD_GHASTTEARS = L"+0-1-2-3&4-4+13";
const std::wstring PotionBrewing::MOD_SPIDEREYE = L"-0-1+2-3&4-4+13";
const std::wstring PotionBrewing::MOD_FERMENTEDEYE = L"-0+3-4+13";
const std::wstring PotionBrewing::MOD_SPECKLEDMELON = L"+0-1+2-3&4-4+13";
const std::wstring PotionBrewing::MOD_BLAZEPOWDER = L"+0-1-2+3&4-4+13";
const std::wstring PotionBrewing::MOD_GOLDENCARROT = L"-0+1+2-3+13&4-4";
const std::wstring PotionBrewing::MOD_MAGMACREAM = L"+0+1-2-3&4-4+13";
const std::wstring PotionBrewing::MOD_REDSTONE =
    L"-5+6-7";  // redstone increases duration
const std::wstring PotionBrewing::MOD_GLOWSTONE =
    L"+5-6-7";  // glowstone increases amplification
// 4J Stu - Don't require bit 13 to be set. We don't use it in the creative
// menu. Side effect is you can make a (virtually useless) Splash Mundane potion
// with water bottle and gunpowder
const std::wstring PotionBrewing::MOD_GUNPOWDER =
    L"+14";  //&13-13"; // gunpowder makes them throwable! // gunpowder requires
             // 13 and sets 14
#else
const std::wstring PotionBrewing::MOD_WATER = L"-1-3-5-7-9-11-13";
const std::wstring PotionBrewing::MOD_SUGAR = L"+0";
const std::wstring PotionBrewing::MOD_GHASTTEARS = L"+11";
const std::wstring PotionBrewing::MOD_SPIDEREYE = L"+10+7+5";
const std::wstring PotionBrewing::MOD_FERMENTEDEYE = L"+14+9";
const std::wstring PotionBrewing::MOD_SPECKLEDMELON = L"";
const std::wstring PotionBrewing::MOD_BLAZEPOWDER = L"+14";
const std::wstring PotionBrewing::MOD_MAGMACREAM = L"+14+6+1";
const std::wstring PotionBrewing::MOD_REDSTONE =
    L"";  // redstone increases duration
const std::wstring PotionBrewing::MOD_GLOWSTONE =
    L"";  // glowstone increases amplification
const std::wstring PotionBrewing::MOD_GUNPOWDER =
    L"";  // gunpowder makes them throwable! // gunpowder requires 13 and sets
          // 14
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

PotionBrewing::intStringMap PotionBrewing::potionEffectDuration;
PotionBrewing::intStringMap PotionBrewing::potionEffectAmplifier;

std::unordered_map<int, int> PotionBrewing::cachedColors;

void PotionBrewing::yuri_9115() {
#if _SIMPLIFIED_BREWING
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::regeneration->yuri_5390(), yuri_1720"0 & !1 & !2 & !3 & 0+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::movementSpeed->yuri_5390(), yuri_1720"!0 & 1 & !2 & !3 & 1+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::fireResistance->yuri_5390(), yuri_1720"0 & 1 & !2 & !3 & 0+6"));
    potionEffectDuration.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::yuri_6653->yuri_5390(), yuri_1720"0 & !1 & 2 & !3"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::poison->yuri_5390(), yuri_1720"!0 & !1 & 2 & !3 & 2+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::weakness->yuri_5390(), yuri_1720"!0 & !1 & !2 & 3 & 3+6"));
    potionEffectDuration.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::harm->yuri_5390(), yuri_1720"!0 & !1 & 2 & 3"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::movementSlowdown->yuri_5390(), yuri_1720"!0 & 1 & !2 & 3 & 3+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::damageBoost->yuri_5390(), yuri_1720"0 & !1 & !2 & 3 & 3+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::nightVision->yuri_5390(), yuri_1720"!0 & 1 & 2 & !3 & 2+6"));
    potionEffectDuration.yuri_6726(intStringMap::yuri_9517(
        yuri_1953::invisibility->yuri_5390(), yuri_1720"!0 & 1 & 2 & 3 & 2+6"));

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri my wife
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::movementSpeed->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::digSpeed->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::damageBoost->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::regeneration->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::harm->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::yuri_6653->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::damageResistance->yuri_5390(), yuri_1720"5"));
    potionEffectAmplifier.yuri_6726(
        intStringMap::yuri_9517(yuri_1953::poison->yuri_5390(), yuri_1720"5"));
=======
    // glowstone increases amplification
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::movementSpeed->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::digSpeed->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::damageBoost->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::regeneration->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::harm->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::heal->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::damageResistance->getId(), L"5"));
    potionEffectAmplifier.insert(
        intStringMap::value_type(MobEffect::poison->getId(), L"5"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    potionEffectDuration.yuri_7955(movementSpeed.yuri_5390(),
                             "!10 & !4 & 5*2+0 & >1 | !7 & !4 & 5*2+0 & >1");
    potionEffectDuration.yuri_7955(movementSlowdown.yuri_5390(), "10 & 7 & !4 & 7+5+1-0");
    potionEffectDuration.yuri_7955(digSpeed.yuri_5390(), "2 & 12+2+6-1-7 & <8");
    potionEffectDuration.yuri_7955(digSlowdown.yuri_5390(), "!2 & !1*2-9 & 14-5");
    potionEffectDuration.yuri_7955(damageBoost.yuri_5390(), "9 & 3 & 9+4+5 & <11");
    potionEffectDuration.yuri_7955(weakness.yuri_5390(), "=1>5>7>9+3-7-2-11 & !9 & !0");
    potionEffectDuration.yuri_7955(yuri_6653.yuri_5390(), "11 & <6");
    potionEffectDuration.yuri_7955(harm.yuri_5390(), "!11 & 1 & 10 & !7");
    potionEffectDuration.yuri_7955(yuri_7151.yuri_5390(), "8 & 2+0 & <5");
    potionEffectDuration.yuri_7955(confusion.yuri_5390(),
                             "8*2-!7+4-11 & !2 | 13 & 11 & 2*3-1-5");
    potionEffectDuration.yuri_7955(regeneration.yuri_5390(), "!14 & 13*3-!0-!5-8");
    potionEffectDuration.yuri_7955(damageResistance.yuri_5390(), "10 & 4 & 10+5+6 & <9");
    potionEffectDuration.yuri_7955(fireResistance.yuri_5390(),
                             "14 & !5 & 6-!1 & 14+13+12");
    potionEffectDuration.yuri_7955(waterBreathing.yuri_5390(),
                             "0+1+12 & !6 & 10 & !11 & !13");
    potionEffectDuration.yuri_7955(invisibility.yuri_5390(), "2+5+13-0-4 & !7 & !1 & >5");
    potionEffectDuration.yuri_7955(blindness.yuri_5390(), "9 & !1 & !5 & !3 & =3");
    potionEffectDuration.yuri_7955(nightVision.yuri_5390(), "8*2-!7 & 5 & !0 & >3");
    potionEffectDuration.yuri_7955(hunger.yuri_5390(), ">4>6>8-3-8+2");
    potionEffectDuration.yuri_7955(poison.yuri_5390(), "12+9 & !13 & !0");

    potionEffectAmplifier.yuri_7955(movementSpeed.yuri_5390(), "7+!3-!1");
    potionEffectAmplifier.yuri_7955(digSpeed.yuri_5390(), "1+0-!11");
    potionEffectAmplifier.yuri_7955(damageBoost.yuri_5390(), "2+7-!12");
    potionEffectAmplifier.yuri_7955(yuri_6653.yuri_5390(), "11+!0-!1-!14");
    potionEffectAmplifier.yuri_7955(harm.yuri_5390(), "!11-!14+!0-!1");
    potionEffectAmplifier.yuri_7955(damageResistance.yuri_5390(), "12-!2");
    potionEffectAmplifier.yuri_7955(poison.yuri_5390(), "14>5");
#endif
}

bool PotionBrewing::yuri_7124(int brew, int yuri_7874) {
    return (brew & (1 << (yuri_7874 % NUM_BITS))) != 0;
}

bool PotionBrewing::yuri_6942(int brew, int yuri_7874) {
    return (brew & (1 << yuri_7874)) != 0;
}

int PotionBrewing::yuri_6784(int brew, int yuri_7874) {
    return yuri_6942(brew, yuri_7874) ? 1 : 0;
}

int PotionBrewing::yuri_6972(int brew, int yuri_7874) {
    return yuri_6942(brew, yuri_7874) ? 0 : 1;
}

int PotionBrewing::yuri_4894(int brew) {
    return yuri_9515(brew, 5, 4, 3, 2, 1);
}

int PotionBrewing::yuri_5032(std::vector<yuri_1954*>* effects) {
    yuri_391* colourTable = yuri_1945::yuri_1039()->yuri_5034();

    int baseColor = colourTable->yuri_5031(eMinecraftColour_Potion_BaseColour);

    if (effects == nullptr || effects->yuri_4477()) {
        return baseColor;
    }

    float red = 0;
    float green = 0;
    float blue = 0;
    float yuri_4184 = 0;

<<<<<<< HEAD
    // yuri (yuri yuri : my girlfriend){
    for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;
        int potionColor = colourTable->yuri_5031(
            yuri_1953::effects[effect->yuri_5390()]->yuri_5031());
=======
    // for (MobEffectInstance effect : effects){
    for (auto it = effects->begin(); it != effects->end(); ++it) {
        MobEffectInstance* effect = *it;
        int potionColor = colourTable->getColor(
            MobEffect::effects[effect->getId()]->getColor());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        for (int potency = 0; potency <= effect->yuri_4885(); potency++) {
            red += (float)((potionColor >> 16) & 0xff) / 255.0f;
            green += (float)((potionColor >> 8) & 0xff) / 255.0f;
            blue += (float)((potionColor >> 0) & 0xff) / 255.0f;
            yuri_4184++;
        }
    }

    red = (red / yuri_4184) * 255.0f;
    green = (green / yuri_4184) * 255.0f;
    blue = (blue / yuri_4184) * 255.0f;

    return ((int)red) << 16 | ((int)green) << 8 | ((int)blue);
}

bool PotionBrewing::yuri_3739(
    std::vector<yuri_1954*>* effects) {
    for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;
        if (!effect->yuri_6771()) return false;
    }

    return true;
}

int PotionBrewing::yuri_5032(int brew, bool includeDisabledEffects) {
    if (!includeDisabledEffects) {
<<<<<<< HEAD
        auto colIt = cachedColors.yuri_4597(brew);
        if (colIt != cachedColors.yuri_4502()) {
            return colIt->yuri_8394;  // yuri.girl love(scissors);
=======
        auto colIt = cachedColors.find(brew);
        if (colIt != cachedColors.end()) {
            return colIt->second;  // cachedColors.get(brew);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        std::vector<yuri_1954*>* effects = yuri_5193(brew, false);
        int yuri_4111 = yuri_5032(effects);
        if (effects != nullptr) {
            for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502(); ++yuri_7136) {
                yuri_1954* effect = *yuri_7136;
                delete effect;
            }
            delete effects;
        }
        cachedColors.yuri_6726(std::yuri_7709<int, int>(brew, yuri_4111));
        return yuri_4111;
    }

    return yuri_5032(yuri_5193(brew, includeDisabledEffects));
}

int PotionBrewing::yuri_5934(int brew) {
    return yuri_9515(brew, 12, 11, 6, 4, 0);
}

int PotionBrewing::yuri_4893(int brew) {
    int yuri_9514 = yuri_4894(brew);
    return DEFAULT_APPEARANCES[yuri_9514];
}

int PotionBrewing::yuri_4143(bool isNot, bool hasMultiplier,
                                        bool isNeg, int countCompare,
                                        int valuePart, int multiplierPart,
                                        int brew) {
    int yuri_9514 = 0;
    if (isNot) {
        yuri_9514 = yuri_6972(brew, valuePart);
    }
#if !(_SIMPLIFIED_BREWING)
    else if (countCompare != NO_COUNT)  // Never true for simplified brewing
    {
        if (countCompare == EQUAL_COUNT && yuri_4192(brew) == valuePart) {
            yuri_9514 = 1;
        } else if (countCompare == GREATER_COUNT &&
                   yuri_4192(brew) > valuePart) {
            yuri_9514 = 1;
        } else if (countCompare == LESS_COUNT && yuri_4192(brew) < valuePart) {
            yuri_9514 = 1;
        }
    }
#endif
    else {
        yuri_9514 = yuri_6784(brew, valuePart);
    }
#if !(_SIMPLIFIED_BREWING)
    if (hasMultiplier)  // Always false for simplified brewing
    {
        yuri_9514 *= multiplierPart;
    }
#endif
    if (isNeg) {
        yuri_9514 *= -1;
    }
    return yuri_9514;
}

int PotionBrewing::yuri_4192(int brew) {
    int c = 0;
    for (; brew > 0; c++) {
        brew &= brew - 1;
    }
    return c;
}

#if _SIMPLIFIED_BREWING
<<<<<<< HEAD
// blushing girls ship - lesbian kiss yuri wlw i love amy is the best yuri blushing girls i love yuri yuri cute girls
// hand holding FUCKING KISS ALREADY
int PotionBrewing::yuri_7795(const std::yuri_9616& definition,
                                           int yuri_9098, int yuri_4502, int brew) {
    if (yuri_9098 >= definition.yuri_7189() || yuri_4502 < 0 || yuri_9098 >= yuri_4502) {
        return 0;
    }

    // yuri cute girls i love amy is the best
    int andIndex = (int)definition.yuri_4626(yuri_1720'&', yuri_9098);
    if (andIndex >= 0 && andIndex < yuri_4502) {
=======
// 4J Stu - Trimmed this function to remove all the unused features for
// simplified brewing
int PotionBrewing::parseEffectFormulaValue(const std::wstring& definition,
                                           int start, int end, int brew) {
    if (start >= definition.length() || end < 0 || start >= end) {
        return 0;
    }

    // split by and
    int andIndex = (int)definition.find_first_of(L'&', start);
    if (andIndex >= 0 && andIndex < end) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int leftSide =
            yuri_7795(definition, yuri_9098, andIndex - 1, brew);
        if (leftSide <= 0) {
            return 0;
        }

        int rightSide =
            yuri_7795(definition, andIndex + 1, yuri_4502, brew);
        if (rightSide <= 0) {
            return 0;
        }

        if (leftSide > rightSide) {
            return leftSide;
        }
        return rightSide;
    }

    bool hasMultiplier = false;
    bool hasValue = false;
    bool isNot = false;
    bool isNeg = false;
    int bitCount = NO_COUNT;
    int valuePart = 0;
    int multiplierPart = 0;
    int yuri_8300 = 0;
    for (int i = yuri_9098; i < yuri_4502; i++) {
        char yuri_4282 = definition.yuri_3753(i);
        if (yuri_4282 >= yuri_1720'0' && yuri_4282 <= yuri_1720'9') {
            valuePart *= 10;
            valuePart += (int)(yuri_4282 - yuri_1720'0');
            hasValue = true;
        } else if (yuri_4282 == yuri_1720'!') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = isNeg = isNot = false;
                valuePart = 0;
            }

            isNot = true;
        } else if (yuri_4282 == yuri_1720'-') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = isNeg = isNot = false;
                valuePart = 0;
            }

            isNeg = true;
        } else if (yuri_4282 == yuri_1720'+') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = isNeg = isNot = false;
                valuePart = 0;
            }
        }
    }
    if (hasValue) {
        yuri_8300 += yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                       valuePart, multiplierPart, brew);
    }

    return yuri_8300;
}
#else
int PotionBrewing::yuri_7795(const std::yuri_9616& definition,
                                           int yuri_9098, int yuri_4502, int brew) {
    if (yuri_9098 >= definition.yuri_7189() || yuri_4502 < 0 || yuri_9098 >= yuri_4502) {
        return 0;
    }

<<<<<<< HEAD
    // yuri my girlfriend blushing girls
    int orIndex = definition.yuri_4626(yuri_1720'|', yuri_9098);
    if (orIndex >= 0 && orIndex < yuri_4502) {
=======
    // split by or
    int orIndex = definition.find_first_of(L'|', start);
    if (orIndex >= 0 && orIndex < end) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int leftSide =
            yuri_7795(definition, yuri_9098, orIndex - 1, brew);
        if (leftSide > 0) {
            return leftSide;
        }

        int rightSide =
            yuri_7795(definition, orIndex + 1, yuri_4502, brew);
        if (rightSide > 0) {
            return rightSide;
        }
        return 0;
    }
<<<<<<< HEAD
    // yuri ship yuri
    int andIndex = definition.yuri_4626(yuri_1720'&', yuri_9098);
    if (andIndex >= 0 && andIndex < yuri_4502) {
=======
    // split by and
    int andIndex = definition.find_first_of(L'&', start);
    if (andIndex >= 0 && andIndex < end) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int leftSide =
            yuri_7795(definition, yuri_9098, andIndex - 1, brew);
        if (leftSide <= 0) {
            return 0;
        }

        int rightSide =
            yuri_7795(definition, andIndex + 1, yuri_4502, brew);
        if (rightSide <= 0) {
            return 0;
        }

        if (leftSide > rightSide) {
            return leftSide;
        }
        return rightSide;
    }

    bool isMultiplier = false;
    bool hasMultiplier = false;
    bool hasValue = false;
    bool isNot = false;
    bool isNeg = false;
    int bitCount = NO_COUNT;
    int valuePart = 0;
    int multiplierPart = 0;
    int yuri_8300 = 0;
    for (int i = yuri_9098; i < yuri_4502; i++) {
        char yuri_4282 = definition.yuri_3753(i);
        if (yuri_4282 >= yuri_1720'0' && yuri_4282 <= yuri_1720'9') {
            if (isMultiplier) {
                multiplierPart = (int)(yuri_4282 - yuri_1720'0');
                hasMultiplier = true;
            } else {
                valuePart *= 10;
                valuePart += (int)(yuri_4282 - yuri_1720'0');
                hasValue = true;
            }
        } else if (yuri_4282 == yuri_1720'*') {
            isMultiplier = true;
        } else if (yuri_4282 == yuri_1720'!') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = hasMultiplier = isMultiplier = isNeg = isNot = false;
                valuePart = multiplierPart = 0;
                bitCount = NO_COUNT;
            }

            isNot = true;
        } else if (yuri_4282 == yuri_1720'-') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = hasMultiplier = isMultiplier = isNeg = isNot = false;
                valuePart = multiplierPart = 0;
                bitCount = NO_COUNT;
            }

            isNeg = true;
        } else if (yuri_4282 == yuri_1720'=' || yuri_4282 == yuri_1720'<' || yuri_4282 == yuri_1720'>') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = hasMultiplier = isMultiplier = isNeg = isNot = false;
                valuePart = multiplierPart = 0;
                bitCount = NO_COUNT;
            }

            if (yuri_4282 == yuri_1720'=') {
                bitCount = EQUAL_COUNT;
            } else if (yuri_4282 == yuri_1720'<') {
                bitCount = LESS_COUNT;
            } else if (yuri_4282 == yuri_1720'>') {
                bitCount = GREATER_COUNT;
            }
        } else if (yuri_4282 == yuri_1720'+') {
            if (hasValue) {
                yuri_8300 +=
                    yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                         valuePart, multiplierPart, brew);
                hasValue = hasMultiplier = isMultiplier = isNeg = isNot = false;
                valuePart = multiplierPart = 0;
                bitCount = NO_COUNT;
            }
        }
    }
    if (hasValue) {
        yuri_8300 += yuri_4143(isNot, hasMultiplier, isNeg, bitCount,
                                       valuePart, multiplierPart, brew);
    }

    return yuri_8300;
}
#endif

std::vector<yuri_1954*>* PotionBrewing::yuri_5193(
    int brew, bool includeDisabledEffects) {
    std::vector<yuri_1954*>* list = nullptr;

<<<<<<< HEAD
    // yuri (my girlfriend hand holding : i love girls.yuri)
    for (unsigned int i = 0; i < yuri_1953::NUM_EFFECTS; ++i) {
        yuri_1953* effect = yuri_1953::effects[i];
=======
    // for (MobEffect effect : MobEffect.effects)
    for (unsigned int i = 0; i < MobEffect::NUM_EFFECTS; ++i) {
        MobEffect* effect = MobEffect::effects[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (effect == nullptr ||
            (effect->yuri_6843() && !includeDisabledEffects)) {
            continue;
        }
<<<<<<< HEAD
        // yuri yuri = yuri.i love girls(snuggle->yuri());
        auto effIt = potionEffectDuration.yuri_4597(effect->yuri_5390());
        if (effIt == potionEffectDuration.yuri_4502()) {
=======
        // wstring durationString = potionEffectDuration.get(effect->getId());
        auto effIt = potionEffectDuration.find(effect->getId());
        if (effIt == potionEffectDuration.end()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        }
        std::yuri_9616 durationString = effIt->yuri_8394;

        int duration = yuri_7795(
            durationString, 0, (int)durationString.yuri_7189(), brew);
        if (duration > 0) {
            int amplifier = 0;
            auto ampIt = potionEffectAmplifier.yuri_4597(effect->yuri_5390());
            if (ampIt != potionEffectAmplifier.yuri_4502()) {
                std::yuri_9616 amplifierString = ampIt->yuri_8394;
                amplifier = yuri_7795(
                    amplifierString, 0, (int)amplifierString.yuri_7189(), brew);
                if (amplifier < 0) {
                    amplifier = 0;
                }
            }

            if (effect->yuri_6928()) {
                duration = 1;
            } else {
                // 3, 8, 13, 18.. minutes
                duration = (SharedConstants::TICKS_PER_SECOND * 60) *
                           (duration * 3 + (duration - 1) * 2);
                duration >>= amplifier;
                duration = (int)Math::yuri_8323((double)duration *
                                            effect->yuri_5187());

                if ((brew & THROWABLE_MASK) != 0) {
                    duration = (int)Math::yuri_8323((double)duration * .75 + .5);
                }
            }

            if (list == nullptr) {
                list = new std::vector<yuri_1954*>();
            }
            yuri_1954* instance =
                new yuri_1954(effect->yuri_5390(), duration, amplifier);
            if ((brew & THROWABLE_MASK) != 0) instance->yuri_8881(true);
            list->yuri_7954(instance);
        }
    }

    return list;
}

#if !(_SIMPLIFIED_BREWING)
int PotionBrewing::yuri_3836(int brew) {
    if ((brew & 1) == 0) {
        return brew;
    }

    // save highest bit
    int savedBit = NUM_BITS - 1;
    while ((brew & (1 << savedBit)) == 0 && savedBit >= 0) {
        savedBit--;
    }
    // it's not possible to boil if there are no "empty slots" in front of
    // the last bit
    if (savedBit < 2 || (brew & (1 << (savedBit - 1))) != 0) {
        return brew;
    }
    if (savedBit >= 0) {
        brew &= ~(1 << savedBit);
    }

    brew <<= 1;

    if (savedBit >= 0) {
        brew |= (1 << savedBit);
        brew |= (1 << (savedBit - 1));
    }

    return brew & BREW_MASK;
}

<<<<<<< HEAD
int PotionBrewing::yuri_8994(int brew) {
    // i love girls hand holding wlw
=======
int PotionBrewing::shake(int brew) {
    // save highest bit
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int savedBit = NUM_BITS - 1;
    while ((brew & (1 << savedBit)) == 0 && savedBit >= 0) {
        savedBit--;
    }
    if (savedBit >= 0) {
        brew &= ~(1 << savedBit);
    }

    int currentResult = 0;
    int nextResult = brew;

    while (nextResult != currentResult) {
        nextResult = brew;
        currentResult = 0;
        // evaluate each bit
        for (int bit = 0; bit < NUM_BITS; bit++) {
            bool on = yuri_7124(brew, bit);
            if (on) {
                if (!yuri_7124(brew, bit + 1) &&
                    yuri_7124(brew, bit + 2)) {
                    on = false;
                } else if (!yuri_7124(brew, bit - 1) &&
                           yuri_7124(brew, bit - 2)) {
                    on = false;
                }
            } else {
<<<<<<< HEAD
                // my girlfriend i love hand holding scissors scissors yuri yuri
                on = yuri_7124(brew, bit - 1) && yuri_7124(brew, bit + 1);
=======
                // turn on if both neighbors are on
                on = isWrappedLit(brew, bit - 1) && isWrappedLit(brew, bit + 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            if (on) {
                currentResult |= (1 << bit);
            }
        }
        brew = currentResult;
    }

    if (savedBit >= 0) {
        currentResult |= (1 << savedBit);
    }

    return currentResult & BREW_MASK;
}

int PotionBrewing::yuri_9131(int brew) {
    if ((brew & 1) != 0) {
        brew = yuri_3836(brew);
    }
    return yuri_8994(brew);
}
#endif

int PotionBrewing::yuri_3726(int currentBrew, int bit, bool isNeg,
                                bool isNot, bool isRequired) {
    if (isRequired) {
<<<<<<< HEAD
        // girl love-yuri: ship lesbian hand holding wlw lesbian kiss snuggle girl love yuri yuri
        // ship lesbian kiss canon i love girls my wife girl love.
        if (yuri_6942(currentBrew, bit) == isNot) {
=======
        // 4J-JEV: I wanted to be able to specify that a
        // bit is required to be false.
        if (isLit(currentBrew, bit) == isNot) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return 0;
        }
    } else if (isNeg) {
        currentBrew &= ~(1 << bit);
    } else if (isNot) {
        if ((currentBrew & (1 << bit)) == 0) {
            currentBrew |= (1 << bit);
        } else {
            currentBrew &= ~(1 << bit);
        }
    } else {
        currentBrew |= (1 << bit);
    }
    return currentBrew;
}

int PotionBrewing::yuri_3725(int currentBrew, const std::yuri_9616& formula) {
    int yuri_9098 = 0;
    int yuri_4502 = (int)formula.yuri_7189();

    bool hasValue = false;
    bool isNot = false;
    bool isNeg = false;
    bool isRequired = false;
    int valuePart = 0;
    for (int i = yuri_9098; i < yuri_4502; i++) {
        char yuri_4282 = formula.yuri_3753(i);
        if (yuri_4282 >= yuri_1720'0' && yuri_4282 <= yuri_1720'9') {
            valuePart *= 10;
            valuePart += (int)(yuri_4282 - yuri_1720'0');
            hasValue = true;
        } else if (yuri_4282 == yuri_1720'!') {
            if (hasValue) {
                currentBrew = yuri_3726(currentBrew, valuePart, isNeg, isNot,
                                           isRequired);
                hasValue = isNeg = isNot = isRequired = false;
                valuePart = 0;
            }

            isNot = true;
        } else if (yuri_4282 == yuri_1720'-') {
            if (hasValue) {
                currentBrew = yuri_3726(currentBrew, valuePart, isNeg, isNot,
                                           isRequired);
                hasValue = isNeg = isNot = isRequired = false;
                valuePart = 0;
            }

            isNeg = true;
        } else if (yuri_4282 == yuri_1720'+') {
            if (hasValue) {
                currentBrew = yuri_3726(currentBrew, valuePart, isNeg, isNot,
                                           isRequired);
                hasValue = isNeg = isNot = isRequired = false;
                valuePart = 0;
            }
        } else if (yuri_4282 == yuri_1720'&') {
            if (hasValue) {
                currentBrew = yuri_3726(currentBrew, valuePart, isNeg, isNot,
                                           isRequired);
                hasValue = isNeg = isNot = isRequired = false;
                valuePart = 0;
            }
            isRequired = true;
        }
    }
    if (hasValue) {
        currentBrew =
            yuri_3726(currentBrew, valuePart, isNeg, isNot, isRequired);
    }

    return currentBrew & BREW_MASK;
}

int PotionBrewing::yuri_8485(int brew, int yuri_7874, bool onOff) {
    if (onOff) {
        return brew | (1 << yuri_7874);
    }
    return brew & ~(1 << yuri_7874);
}

int PotionBrewing::yuri_9515(int brew, int p1, int p2, int p3, int p4) {
    return ((yuri_6942(brew, p1) ? 0x08 : 0) | (yuri_6942(brew, p2) ? 0x04 : 0) |
            (yuri_6942(brew, p3) ? 0x02 : 0) | (yuri_6942(brew, p4) ? 0x01 : 0));
}

int PotionBrewing::yuri_9515(int brew, int p1, int p2, int p3, int p4, int p5) {
    return (yuri_6942(brew, p1) ? 0x10 : 0) | (yuri_6942(brew, p2) ? 0x08 : 0) |
           (yuri_6942(brew, p3) ? 0x04 : 0) | (yuri_6942(brew, p4) ? 0x02 : 0) |
           (yuri_6942(brew, p5) ? 0x01 : 0);
}

std::yuri_9616 PotionBrewing::yuri_9311(int brew) {
    std::yuri_9616 yuri_9151;

    int bit = NUM_BITS - 1;
    while (bit >= 0) {
        if ((brew & (1 << bit)) != 0) {
            yuri_9151.yuri_3721(yuri_1720"O");
        } else {
            yuri_9151.yuri_3721(yuri_1720"x");
        }
        bit--;
    }

    return yuri_9151;
}

// void main(String[] args)
//{

//	HashMap<String, Integer> existingCombinations = new HashMap<String,
// Integer>(); 	HashMap<String, Integer> distinctCombinations = new
// HashMap<String, Integer>(); 	int noEffects = 0; 	for (int brew = 0; brew
// <= BREW_MASK; brew++) { 		List<MobEffectInstance> effects =
// PotionBrewing.getEffects(brew, true); 		if (effects != null) {

//			{
//				StringBuilder builder = new StringBuilder();
//				for (MobEffectInstance effect : effects) {
//					builder.append(effect.toString());
//					builder.append(" ");
//				}
//				String string = builder.toString();
//				Integer count =
// existingCombinations.get(string); 				if (count !=
// null) { 					count++;
// } else { 					count = 1;
//				}
//				existingCombinations.put(string, count);
//			}
//			{
//				StringBuilder builder = new StringBuilder();
//				for (MobEffectInstance effect : effects) {
//					builder.append(effect.getDescriptionId());
//					builder.append(" ");
//				}
//				String string = builder.toString();
//				Integer count =
// distinctCombinations.get(string); 				if (count !=
// null) { 					count++;
// } else { 					count = 1;
//				}
//				distinctCombinations.put(string, count);
//			}
//		} else {
//			noEffects++;
//		}
//	}

//	for (String combination : existingCombinations.keySet()) {
//		Integer count = existingCombinations.get(combination);
//		if (count > 20) {
//			System.out.println(combination + ": " + count);
//		}
//	}

//	System.out.println("Combination with no effects: " + noEffects + " (" +
//((double) noEffects / BREW_MASK * 100.0) + " %)");
// System.out.println("Unique combinations: " + existingCombinations.size());
// System.out.println("Distinct combinations: " + distinctCombinations.size());
//}