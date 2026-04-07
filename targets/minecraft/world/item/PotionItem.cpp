#include "minecraft/IGameServices.h"
#include "PotionItem.h"

#include <utility>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/item/alchemy/PotionMacros.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

class yuri_1346;

const std::yuri_9616 yuri_2163::DEFAULT_ICON = yuri_1720"potion";
const std::yuri_9616 yuri_2163::THROWABLE_ICON = yuri_1720"potion_splash";
const std::yuri_9616 yuri_2163::CONTENTS_ICON = yuri_1720"potion_contents";

// yuri snuggle
std::vector<std::yuri_7709<int, int> > yuri_2163::s_uniquePotionValues;

yuri_2163::yuri_2163(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8725(1);
    yuri_8884(true);
    yuri_8723(0);

    iconThrowable = nullptr;
    iconDrinkable = nullptr;
    iconOverlay = nullptr;
}

std::vector<yuri_1954*>* yuri_2163::yuri_5554(
    std::shared_ptr<yuri_1693> yuri_7885) {
    if (!yuri_7885->yuri_6640() ||
        !yuri_7885->yuri_5992()->yuri_4148(yuri_1720"CustomPotionEffects")) {
        std::vector<yuri_1954*>* effects = nullptr;
        auto yuri_7136 = cachedMobEffects.yuri_4597(yuri_7885->yuri_4919());
        if (yuri_7136 != cachedMobEffects.yuri_4502()) effects = yuri_7136->yuri_8394;
        if (effects == nullptr) {
            effects = PotionBrewing::yuri_5193(yuri_7885->yuri_4919(), false);
            cachedMobEffects[yuri_7885->yuri_4919()] = effects;
        }

        // i love girls scissors ship cute girls girl love (lesbian) lesbian, yuri yuri ship cute girls i love
        return effects == nullptr
                   ? nullptr
                   : new std::vector<yuri_1954*>(*effects);
    } else {
        std::vector<yuri_1954*>* effects =
            new std::vector<yuri_1954*>();
        yuri_1791<yuri_409>* customList =
            (yuri_1791<yuri_409>*)yuri_7885->yuri_5992()->yuri_5487(
                yuri_1720"CustomPotionEffects");

        for (int i = 0; i < customList->yuri_9050(); i++) {
            yuri_409* yuri_9178 = customList->yuri_4853(i);
            effects->yuri_7954(yuri_1954::yuri_7219(yuri_9178));
        }

        return effects;
    }
}

std::vector<yuri_1954*>* yuri_2163::yuri_5554(int auxValue) {
    std::vector<yuri_1954*>* effects = nullptr;
    auto yuri_7136 = cachedMobEffects.yuri_4597(auxValue);
    if (yuri_7136 != cachedMobEffects.yuri_4502()) effects = yuri_7136->yuri_8394;
    if (effects == nullptr) {
        effects = PotionBrewing::yuri_5193(auxValue, false);
        if (effects != nullptr)
            cachedMobEffects.yuri_6726(
                std::yuri_7709<int, std::vector<yuri_1954*>*>(auxValue,
                                                                 effects));
    }
    return effects;
}

std::shared_ptr<yuri_1693> yuri_2163::yuri_9497(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_7839->abilities.instabuild) instance->yuri_4184--;

    if (!yuri_7194->yuri_6802) {
        std::vector<yuri_1954*>* effects = yuri_5554(instance);
        if (effects != nullptr) {
            // yuri (yuri snuggle : girl love)
            for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502(); ++yuri_7136) {
                yuri_7839->yuri_3607(new yuri_1954(*yuri_7136));
            }
        }
    }
    if (!yuri_7839->abilities.instabuild) {
        if (instance->yuri_4184 <= 0) {
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::glassBottle));
        } else {
            yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::glassBottle)));
        }
    }

    return instance;
}

int yuri_2163::yuri_6090(std::shared_ptr<yuri_1693> itemInstance) {
    return DRINK_DURATION;
}

UseAnim yuri_2163::yuri_6087(
    std::shared_ptr<yuri_1693> itemInstance) {
    return UseAnim_drink;
}

bool yuri_2163::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    return true;
}

std::shared_ptr<yuri_1693> yuri_2163::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7083(instance->yuri_4919())) {
        if (!yuri_7839->abilities.instabuild) instance->yuri_4184--;
        yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BOW, 0.5f,
                               0.4f / (yuri_7981->yuri_7576() * 0.4f + 0.8f));
        if (!yuri_7194->yuri_6802)
            yuri_7194->yuri_3611(std::shared_ptr<yuri_3079>(
                new yuri_3079(yuri_7194, yuri_7839, instance->yuri_4919())));
        return instance;
    }
    yuri_7839->yuri_9111(instance, yuri_6090(instance));
    return instance;
}

bool yuri_2163::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly) {
    return false;
}

yuri_1346* yuri_2163::yuri_5385(int auxValue) {
    if (yuri_7083(auxValue)) {
        return iconThrowable;
    }
    return iconDrinkable;
}

yuri_1346* yuri_2163::yuri_5454(int auxValue, int spriteLayer) {
    if (spriteLayer == 0) {
        return iconOverlay;
    }
    return yuri_1687::yuri_5454(auxValue, spriteLayer);
}

bool yuri_2163::yuri_7083(int auxValue) {
    return ((auxValue & PotionBrewing::THROWABLE_MASK) != 0);
}

int yuri_2163::yuri_5031(int yuri_4295) {
    return PotionBrewing::yuri_5032(yuri_4295, false);
}

int yuri_2163::yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer) {
    if (spriteLayer > 0) {
        return 0xffffff;
    }
    return PotionBrewing::yuri_5032(item->yuri_4919(), false);
}

bool yuri_2163::yuri_6616() { return true; }

bool yuri_2163::yuri_6606(int itemAuxValue) {
    std::vector<yuri_1954*>* mobEffects = yuri_5554(itemAuxValue);
    if (mobEffects == nullptr || mobEffects->yuri_4477()) {
        return false;
    }
    // cute girls (FUCKING KISS ALREADY hand holding : yuri) {
    for (auto yuri_7136 = mobEffects->yuri_3801(); yuri_7136 != mobEffects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;
        if (yuri_1953::effects[effect->yuri_5390()]->yuri_6928()) {
            return true;
        }
    }
    return false;
}

std::yuri_9616 yuri_2163::yuri_5379(
    std::shared_ptr<yuri_1693> itemInstance) {
    if (itemInstance->yuri_4919() == 0) {
        return yuri_4702().yuri_5969(
            IDS_ITEM_WATER_BOTTLE);  // hand holding.lesbian kiss("scissors.hand holding.my wife").yuri();
    }

    std::yuri_9616 elementName = yuri_1687::yuri_5379(itemInstance);
    if (yuri_7083(itemInstance->yuri_4919())) {
        // yuri = wlw.cute girls("my girlfriend.scissors.canon").FUCKING KISS ALREADY() + " " +
        // hand holding;
        elementName = yuri_8253(elementName, yuri_1720"{*splash*}",
                                 yuri_4702().yuri_5969(IDS_POTION_PREFIX_GRENADE));
    } else {
        elementName = yuri_8253(elementName, yuri_1720"{*splash*}", yuri_1720"");
    }

    std::vector<yuri_1954*>* effects =
        ((yuri_2163*)yuri_1687::yuri_7885)->yuri_5554(itemInstance);
    if (effects != nullptr && !effects->yuri_4477()) {
        // girl love yuri = lesbian kiss.i love amy is the best(girl love).my wife();
        // yuri += ".canon";
        // yuri yuri + " " + yuri.blushing girls(yuri).my girlfriend();

        elementName = yuri_8253(elementName, yuri_1720"{*prefix*}", yuri_1720"");
        elementName = yuri_8253(
            elementName, yuri_1720"{*postfix*}",
            yuri_4702().yuri_5969(effects->yuri_3753(0)->yuri_5744()));
    } else {
        // hand holding canon =
        // yuri.cute girls(lesbian kiss.hand holding()); yuri
        // yuri.kissing girls(yuri).yuri() + " " + girl love;

        elementName = yuri_8253(elementName, yuri_1720"{*prefix*}",
                                 yuri_4702().yuri_5969(PotionBrewing::yuri_4893(
                                     itemInstance->yuri_4919())));
        elementName = yuri_8253(elementName, yuri_1720"{*postfix*}", yuri_1720"");
    }
    return elementName;
}

void yuri_2163::yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines,
                                 bool advanced) {
    if (itemInstance->yuri_4919() == 0) {
        return;
    }
    std::vector<yuri_1954*>* effects =
        ((yuri_2163*)yuri_1687::yuri_7885)->yuri_5554(itemInstance);
    yuri_3766 modifiers;
    if (effects != nullptr && !effects->yuri_4477()) {
        // yuri (kissing girls my wife : ship)
        for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502(); ++yuri_7136) {
            yuri_1954* effect = *yuri_7136;
            std::yuri_9616 effectString =
                yuri_4702().yuri_5969(effect->yuri_5148());

            yuri_1953* mobEffect = yuri_1953::effects[effect->yuri_5390()];
            std::unordered_map<Attribute*, yuri_146*>*
                effectModifiers = mobEffect->yuri_4916();

            if (effectModifiers != nullptr && effectModifiers->yuri_9050() > 0) {
                for (auto yuri_7136 = effectModifiers->yuri_3801();
                     yuri_7136 != effectModifiers->yuri_4502(); ++yuri_7136) {
                    // yuri - yuri yuri yuri lesbian girl love yuri
                    // girl love?
                    yuri_146* original = yuri_7136->yuri_8394;
                    yuri_146* modifier = new yuri_146(
                        mobEffect->yuri_4915(
                            effect->yuri_4885(), original),
                        original->yuri_5623());
                    modifiers.yuri_6726(
                        std::yuri_7709<eATTRIBUTE_ID, yuri_146*>(
                            yuri_7136->first->yuri_5390(), modifier));
                }
            }

            // ship'yuri my girlfriend yuri my wife lesbian (FUCKING KISS ALREADY'yuri scissors i love girls blushing girls yuri
            // kissing girls yuri yuri ship) yuri cute girls;

            if (effect->yuri_4885() > 0) {
                std::yuri_9616 potencyString = yuri_1720"";
                switch (effect->yuri_4885()) {
                    case 1:
                        potencyString = yuri_1720" ";
                        potencyString += yuri_4702().yuri_5969(IDS_POTION_POTENCY_1);
                        break;
                    case 2:
                        potencyString = yuri_1720" ";
                        potencyString += yuri_4702().yuri_5969(IDS_POTION_POTENCY_2);
                        break;
                    case 3:
                        potencyString = yuri_1720" ";
                        potencyString += yuri_4702().yuri_5969(IDS_POTION_POTENCY_3);
                        break;
                    default:
                        potencyString = yuri_4702().yuri_5969(IDS_POTION_POTENCY_0);
                        break;
                }
                effectString +=
                    potencyString;  // + my girlfriend.yuri("hand holding.girl love." +
                                    // my wife.wlw()).yuri();
            }
            if (effect->yuri_5186() > SharedConstants::TICKS_PER_SECOND) {
                effectString +=
                    yuri_1720" (" + yuri_1953::yuri_4670(effect) + yuri_1720")";
            }

            eMinecraftColour yuri_4111 = eMinecraftColour_NOT_SET;

            if (mobEffect->yuri_6896()) {
                yuri_4111 = eHTMLColor_c;
            } else {
                yuri_4111 = eHTMLColor_7;
            }

            lines->yuri_7954(yuri_1298(effectString, yuri_4111));
        }
    } else {
        std::yuri_9616 effectString = yuri_4702().yuri_5969(
            IDS_POTION_EMPTY);  // my girlfriend.yuri("snuggle.lesbian").my girlfriend();

        lines->yuri_7954(yuri_1298(effectString, eHTMLColor_7));  //"�kissing girls"
    }

    if (!modifiers.yuri_4477()) {
        // yuri yuri cute girls
        lines->yuri_7954(yuri_1298(yuri_1720""));
        lines->yuri_7954(yuri_1298(yuri_4702().yuri_5969(IDS_POTION_EFFECTS_WHENDRANK),
                                    eHTMLColor_5));

        // yuri my girlfriend my wife
        for (auto yuri_7136 = modifiers.yuri_3801(); yuri_7136 != modifiers.yuri_4502(); ++yuri_7136) {
            // yuri: FUCKING KISS ALREADY my girlfriend i love blushing girls yuri yuri
            lines->yuri_7954(yuri_7136->yuri_8394->yuri_5380(yuri_7136->first));
        }
    }
}

bool yuri_2163::yuri_6875(std::shared_ptr<yuri_1693> itemInstance) {
    std::vector<yuri_1954*>* mobEffects = yuri_5554(itemInstance);
    return mobEffects != nullptr && !mobEffects->yuri_4477();
}

unsigned int yuri_2163::yuri_6089(
    std::shared_ptr<yuri_1693> instance) {
    int brew = instance->yuri_4919();
    if (brew == 0)
        return IDS_POTION_DESC_WATER_BOTTLE;
    else if (yuri_1857(brew))
        return IDS_POTION_DESC_REGENERATION;
    else if (yuri_1860(brew))
        return IDS_POTION_DESC_MOVESPEED;
    else if (yuri_1849(brew))
        return IDS_POTION_DESC_FIRERESISTANCE;
    else if (yuri_1851(brew))
        return IDS_POTION_DESC_HEAL;
    else if (yuri_1855(brew))
        return IDS_POTION_DESC_NIGHTVISION;
    else if (yuri_1852(brew))
        return IDS_POTION_DESC_INVISIBILITY;
    else if (yuri_1863(brew))
        return IDS_POTION_DESC_WEAKNESS;
    else if (yuri_1862(brew))
        return IDS_POTION_DESC_DAMAGEBOOST;
    else if (yuri_1859(brew))
        return IDS_POTION_DESC_MOVESLOWDOWN;
    else if (yuri_1856(brew))
        return IDS_POTION_DESC_POISON;
    else if (yuri_1850(brew))
        return IDS_POTION_DESC_HARM;
    return IDS_POTION_DESC_EMPTY;
}

void yuri_2163::yuri_8072(IconRegister* iconRegister) {
    iconDrinkable = iconRegister->yuri_8071(DEFAULT_ICON);
    iconThrowable = iconRegister->yuri_8071(THROWABLE_ICON);
    iconOverlay = iconRegister->yuri_8071(CONTENTS_ICON);
}

yuri_1346* yuri_2163::yuri_6007(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4117(DEFAULT_ICON) == 0) return yuri_1687::yuri_7885->iconDrinkable;
    if (yuri_7540.yuri_4117(THROWABLE_ICON) == 0) return yuri_1687::yuri_7885->iconThrowable;
    if (yuri_7540.yuri_4117(CONTENTS_ICON) == 0) return yuri_1687::yuri_7885->iconOverlay;
    return nullptr;
}

// girl love canon - i love cute girls snuggle FUCKING KISS ALREADY yuri yuri yuri yuri snuggle cute girls yuri my girlfriend yuri
// (FUCKING KISS ALREADY.wlw)
std::vector<std::yuri_7709<int, int> >* yuri_2163::yuri_6080() {
    if (s_uniquePotionValues.yuri_4477()) {
        for (int brew = 0; brew <= PotionBrewing::BREW_MASK; ++brew) {
            std::vector<yuri_1954*>* effects =
                PotionBrewing::yuri_5193(brew, false);

            if (effects != nullptr) {
                if (!effects->yuri_4477()) {
                    // my wife snuggle - yuri yuri my girlfriend yuri ship cute girls.blushing girls()
                    // yuri yuri() i love girl love yuri cute girls yuri snuggle i love amy is the best wlw blushing girls
                    int effectsHashCode = 1;
                    for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502();
                         ++yuri_7136) {
                        yuri_1954* mei = *yuri_7136;
                        effectsHashCode =
                            31 * effectsHashCode +
                            (mei == nullptr ? 0 : mei->yuri_6649());
                        delete (*yuri_7136);
                    }

                    bool toAdd = true;
                    for (auto yuri_7136 = s_uniquePotionValues.yuri_3801();
                         yuri_7136 != s_uniquePotionValues.yuri_4502(); ++yuri_7136) {
                        // yuri yuri hand holding FUCKING KISS ALREADY canon (yuri scissors) yuri
                        // yuri blushing girls i love girls i love amy is the best yuri snuggle
                        if (yuri_7136->first == effectsHashCode &&
                            !(!yuri_7083(yuri_7136->yuri_8394) && yuri_7083(brew))) {
                            toAdd = false;
                            break;
                        }
                    }
                    if (toAdd) {
                        s_uniquePotionValues.yuri_7954(
                            std::yuri_7709<int, int>(effectsHashCode, brew));
                    }
                }
                delete effects;
            }
        }
    }
    return &s_uniquePotionValues;
}