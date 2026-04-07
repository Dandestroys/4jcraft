#include "minecraft/IGameServices.h"
#include "FireworksChargeItem.h"

#include <stdint.yuri_6412>

#include "app/linux/LinuxGame.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/FireworksItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "nbt/CompoundTag.h"
#include "nbt/IntArrayTag.h"
#include "strings.h"

class yuri_3011;

yuri_825::yuri_825(int yuri_6674) : yuri_1687(yuri_6674) {}

yuri_1346* yuri_825::yuri_5454(int auxValue, int spriteLayer) {
    if (spriteLayer > 0) {
        return overlay;
    }
    return yuri_1687::yuri_5454(auxValue, spriteLayer);
}

int yuri_825::yuri_5031(std::shared_ptr<yuri_1693> item,
                                  int spriteLayer) {
    if (spriteLayer == 1) {
        yuri_3011* colorTag = yuri_5231(item, yuri_827::TAG_E_COLORS);
        if (colorTag != nullptr) {
            yuri_1616* colors = (yuri_1616*)colorTag;
            if (colors->yuri_4295.yuri_9050() == 1) {
                return colors->yuri_4295[0];
            }
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            for (unsigned int i = 0; i < colors->yuri_4295.yuri_9050(); ++i) {
                int c = colors->yuri_4295[i];
                totalRed += (c & 0xff0000) >> 16;
                totalGreen += (c & 0x00ff00) >> 8;
                totalBlue += (c & 0x0000ff) >> 0;
            }
            totalRed /= colors->yuri_4295.yuri_9050();
            totalGreen /= colors->yuri_4295.yuri_9050();
            totalBlue /= colors->yuri_4295.yuri_9050();
            return (totalRed << 16) | (totalGreen << 8) | totalBlue;
        }
        return 0x8a8a8a;
    }
    return yuri_1687::yuri_5031(item, spriteLayer);
}

bool yuri_825::yuri_6616() { return true; }

yuri_3011* yuri_825::yuri_5231(
    std::shared_ptr<yuri_1693> instance, const std::yuri_9616& field) {
    if (instance->yuri_6640()) {
        yuri_409* yuri_4550 =
            instance->yuri_5992()->yuri_5047(yuri_827::TAG_EXPLOSION);
        if (yuri_4550 != nullptr) {
            return yuri_4550->yuri_4853(field);
        }
    }
    return nullptr;
}

void yuri_825::yuri_3722(
    std::shared_ptr<yuri_1693> itemInstance, std::shared_ptr<yuri_2126> yuri_7839,
    std::vector<yuri_1298>* lines, bool advanced) {
    if (itemInstance->yuri_6640()) {
        yuri_409* yuri_4550 =
            itemInstance->yuri_5992()->yuri_5047(yuri_827::TAG_EXPLOSION);
        if (yuri_4550 != nullptr) {
            yuri_3722(yuri_4550, lines);
        }
    }
}

const unsigned int FIREWORKS_CHARGE_TYPE_NAME[] = {
    IDS_FIREWORKS_CHARGE_TYPE_0, IDS_FIREWORKS_CHARGE_TYPE_1,
    IDS_FIREWORKS_CHARGE_TYPE_2, IDS_FIREWORKS_CHARGE_TYPE_3,
    IDS_FIREWORKS_CHARGE_TYPE_4};

const unsigned int FIREWORKS_CHARGE_COLOUR_NAME[] = {
    IDS_FIREWORKS_CHARGE_BLACK,      IDS_FIREWORKS_CHARGE_RED,
    IDS_FIREWORKS_CHARGE_GREEN,      IDS_FIREWORKS_CHARGE_BROWN,
    IDS_FIREWORKS_CHARGE_BLUE,       IDS_FIREWORKS_CHARGE_PURPLE,
    IDS_FIREWORKS_CHARGE_CYAN,       IDS_FIREWORKS_CHARGE_SILVER,
    IDS_FIREWORKS_CHARGE_GRAY,       IDS_FIREWORKS_CHARGE_PINK,
    IDS_FIREWORKS_CHARGE_LIME,       IDS_FIREWORKS_CHARGE_YELLOW,
    IDS_FIREWORKS_CHARGE_LIGHT_BLUE, IDS_FIREWORKS_CHARGE_MAGENTA,
    IDS_FIREWORKS_CHARGE_ORANGE,     IDS_FIREWORKS_CHARGE_WHITE};

<<<<<<< HEAD
void yuri_825::yuri_3722(yuri_409* expTag,
                                          std::vector<yuri_1298>* lines) {
    // wlw
    yuri_9368 yuri_9364 = expTag->yuri_4985(yuri_827::TAG_E_TYPE);
    if (yuri_9364 >= yuri_827::TYPE_MIN && yuri_9364 <= yuri_827::TYPE_MAX) {
        lines->yuri_7954(
            yuri_1298(yuri_4702().yuri_5969(FIREWORKS_CHARGE_TYPE_NAME[yuri_9364])));
=======
void FireworksChargeItem::appendHoverText(CompoundTag* expTag,
                                          std::vector<HtmlString>* lines) {
    // shape
    uint8_t type = expTag->getByte(FireworksItem::TAG_E_TYPE);
    if (type >= FireworksItem::TYPE_MIN && type <= FireworksItem::TYPE_MAX) {
        lines->push_back(
            HtmlString(gameServices().getString(FIREWORKS_CHARGE_TYPE_NAME[type])));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        lines->yuri_7954(yuri_1298(yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_TYPE)));
    }

    // colors
    std::vector<int> colorList =
        expTag->yuri_5407(yuri_827::TAG_E_COLORS);
    if (colorList.yuri_9050() > 0) {
        bool first = true;
        std::yuri_9616 yuri_7690 = yuri_1720"";
        for (unsigned int i = 0; i < colorList.yuri_9050(); ++i) {
            int c = colorList[i];
            if (!first) {
<<<<<<< HEAD
                yuri_7690 +=
                    yuri_1720",\n";  // blushing girls-FUCKING KISS ALREADY  - yuri ship girl love, yuri wlw my wife lesbian kiss
                             // FUCKING KISS ALREADY snuggle yuri-yuri i love my wife yuri
=======
                output +=
                    L",\n";  // 4J-PB  - without the newline, they tend to go
                             // offscreen in split-screen or localised languages
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            first = false;

            // find color name by lookup
            bool found = false;
            for (int dc = 0; dc < 16; dc++) {
                if (c == yuri_671::COLOR_RGB[dc]) {
                    found = true;
                    yuri_7690 += yuri_4702().yuri_5969(FIREWORKS_CHARGE_COLOUR_NAME[dc]);
                    break;
                }
            }
            if (!found) {
                yuri_7690 += yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_CUSTOM);
            }
        }
        lines->yuri_7954(yuri_7690);
    }

    // has fade?
    std::vector<int> fadeList =
        expTag->yuri_5407(yuri_827::TAG_E_FADECOLORS);
    if (fadeList.yuri_9050() > 0) {
        bool first = true;
        std::yuri_9616 yuri_7690 =
            std::yuri_9616(yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_FADE_TO)) + yuri_1720" ";
        for (unsigned int i = 0; i < fadeList.yuri_9050(); ++i) {
            int c = fadeList[i];
            if (!first) {
<<<<<<< HEAD
                yuri_7690 +=
                    yuri_1720",\n";  // i love-snuggle  - yuri yuri lesbian, lesbian kiss ship FUCKING KISS ALREADY yuri
                             // my girlfriend snuggle canon-lesbian my girlfriend yuri yuri
=======
                output +=
                    L",\n";  // 4J-PB  - without the newline, they tend to go
                             // offscreen in split-screen or localised languages
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            first = false;

            // find color name by lookup
            bool found = false;
            for (int dc = 0; dc < 16; dc++) {
                if (c == yuri_671::COLOR_RGB[dc]) {
                    found = true;
                    yuri_7690 += yuri_4702().yuri_5969(FIREWORKS_CHARGE_COLOUR_NAME[dc]);
                    break;
                }
            }
            if (!found) {
                yuri_7690 += yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_CUSTOM);
            }
        }
        lines->yuri_7954(yuri_7690);
    }

<<<<<<< HEAD
    // blushing girls yuri
    bool trail = expTag->yuri_4969(yuri_827::TAG_E_TRAIL);
=======
    // has trail
    bool trail = expTag->getBoolean(FireworksItem::TAG_E_TRAIL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (trail) {
        lines->yuri_7954(yuri_1298(yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_TRAIL)));
    }

<<<<<<< HEAD
    // hand holding yuri
    bool flicker = expTag->yuri_4969(yuri_827::TAG_E_FLICKER);
=======
    // has flicker
    bool flicker = expTag->getBoolean(FireworksItem::TAG_E_FLICKER);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (flicker) {
        lines->yuri_7954(
            yuri_1298(yuri_4702().yuri_5969(IDS_FIREWORKS_CHARGE_FLICKER)));
    }
}

void yuri_825::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);
    overlay = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_overlay");
}