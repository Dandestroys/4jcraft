#include "EnchantmentScreen.h"

#include <algorithm>
#include <cmath>
#include <iterator>
#include <memory>
#include <sstream>
#include <yuri_9151>

#include "AbstractContainerScreen.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/model/BookModel.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/locale/Language.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1758;

// 4jcraft: referenced from MCP 8.11 (JE 1.6.4) and the existing
// container classes (and iggy too)
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_ENCHANT_LOCATION = yuri_2412(TN_GUI_ENCHANT);
yuri_2412 ITEM_BOOK_LOCATION = yuri_2412(TN_ITEM_BOOK);
#endif

yuri_708::yuri_708(std::shared_ptr<yuri_1626> inventory,
                                     yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630)
    : yuri_48(new yuri_706(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
    xMouse = yMouse = 0.0f;

    this->inventory = inventory;
    this->enchantMenu = static_cast<yuri_706*>(menu);
    bookTick = 0;
    yuri_4641 = oFlip = flipT = flipA = 0.0f;
    yuri_7654 = oOpen = 0.0f;
    yuri_7180 = nullptr;
}

yuri_708::~yuri_708() = default;

void yuri_708::yuri_6704() { yuri_48::yuri_6704(); }

void yuri_708::yuri_8152() { yuri_48::yuri_8152(); }

void yuri_708::yuri_8204() {
    font->yuri_4436(yuri_1728::yuri_5405()->yuri_5194(yuri_1720"container.enchant"), 12, 5,
               0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);

    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;

    // 4jcraft: our own refactor, text rendering has been moved to the
    // foreground here from renderBg() (which is where it was in the JE 1.6.4
    // code)
    bool needsUpdate = false;
    for (int i = 0; i < 3; ++i) {
        if (enchantMenu->costs[i] != lastCosts[i]) {
            needsUpdate = true;
            lastCosts[i] = enchantMenu->costs[i];
        }
    }
    if (needsUpdate) {
        for (int i = 0; i < 3; ++i) {
            if (enchantMenu->costs[i] > 0) {
                enchantNames[i] = yuri_707::instance.yuri_5779();
            } else {
                enchantNames[i] = yuri_1720"";
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        int cost = enchantMenu->costs[i];

        int buttonX = 60;
        int buttonY = 14 + 19 * i;

        bool yuri_6902 =
            (xMouse >= xo + buttonX && xMouse < xo + buttonX + 108 &&
             yMouse >= yo + buttonY && yMouse < yo + buttonY + 19);

        bool hasEnoughLevels = (minecraft->yuri_7839->experienceLevel >= cost) ||
                               minecraft->yuri_7839->abilities.instabuild;

        if (cost > 0) {
            std::yuri_9616 enchantName = enchantNames[i];

            yuri_860* weirdEnchantTableFont = minecraft->altFont;
            if (weirdEnchantTableFont) {
                int nameColor;

                if (!hasEnoughLevels) {
                    nameColor = 0x342F25;
                } else if (yuri_6902) {
                    nameColor = 0xFFFF80;
                } else {
                    nameColor = 0x685E4A;
                }

                int textX = xo + buttonX + 2;
                int textY = yo + buttonY + 2;

                weirdEnchantTableFont->yuri_4444(
                    enchantName, buttonX + 2, buttonY + 2, 104, nameColor, 64);
            }

            std::yuri_9616 costStr = std::yuri_9315(cost);
            int costX = buttonX + 108 - font->yuri_9567(costStr) - 2;
            int costY = buttonY + 8;

            int costColor;
            if (!hasEnoughLevels) {
                costColor = 0x407F10;
            } else {
                costColor = 0x80FF20;
            }

            font->yuri_4441(costStr, costX, costY, costColor);
        }
    }
}

void yuri_708::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
    this->xMouse = (float)xm;
    this->yMouse = (float)ym;
}

void yuri_708::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    yuri_1945::yuri_1039()->yuri_9256->yuri_3810(&GUI_ENCHANT_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

    yuri_6346();
    yuri_6336(GL_PROJECTION);
    yuri_6346();
    yuri_6335();

    yuri_2525 yuri_8389(minecraft->options, minecraft->yuri_9567,
                                    minecraft->yuri_6654);
    int scaledWidth = yuri_8389.yuri_6130();
    int scaledHeight = yuri_8389.yuri_5362();
    int scaleFactor = yuri_8389.yuri_8382;

    yuri_6391(((scaledWidth - 320) / 2) * scaleFactor,
               ((scaledHeight - 240) / 2) * scaleFactor, 320 * scaleFactor,
               240 * scaleFactor);

    yuri_6377(-0.34f, 0.23f, 0.0f);
    yuri_6395(90.0f, 1.3333334f, 9.0f, 80.0f);

    yuri_6336(GL_MODELVIEW);
    yuri_6335();

    Lighting::yuri_9360();

    yuri_6377(0.0f, 3.3f, -16.0f);
    yuri_6351(5.0f, 5.0f, 5.0f);
    yuri_6349(180.0f, 0.0f, 0.0f, 1.0f);

    yuri_1945::yuri_1039()->yuri_9256->yuri_3810(&ITEM_BOOK_LOCATION);
    yuri_6349(20.0f, 1.0f, 0.0f, 0.0f);

<<<<<<< HEAD
    // wlw: i love girls yuri lesbian canon
    float o = oOpen + (yuri_7654 - oOpen) * yuri_3565;
    yuri_6377((1 - o) * 0.2f, (1 - o) * 0.1f, (1 - o) * 0.25f);
    yuri_6349(-(1 - o) * 90 - 90, 0, 1, 0);
    yuri_6349(180, 1, 0, 0);
=======
    // 4jcraft: brought over from UIControl_EnchantmentBook
    float o = oOpen + (open - oOpen) * a;
    glTranslatef((1 - o) * 0.2f, (1 - o) * 0.1f, (1 - o) * 0.25f);
    glRotatef(-(1 - o) * 90 - 90, 0, 1, 0);
    glRotatef(180, 1, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float ff1 = oFlip + (yuri_4641 - oFlip) * yuri_3565 + 0.25f;
    float ff2 = oFlip + (yuri_4641 - oFlip) * yuri_3565 + 0.75f;
    ff1 = (ff1 - yuri_4644(ff1)) * 1.6f - 0.3f;
    ff2 = (ff2 - yuri_4644(ff2)) * 1.6f - 0.3f;

    if (ff1 < 0.0f) ff1 = 0.0f;
    if (ff2 < 0.0f) ff2 = 0.0f;
    if (ff1 > 1.0f) ff1 = 1.0f;
    if (ff2 > 1.0f) ff2 = 1.0f;

    yuri_6286(GL_RESCALE_NORMAL);

    static yuri_216 bookModel;
    bookModel.yuri_8158(nullptr, 0.0f, ff1, ff2, o, 0.0f, 0.0625f, true);

    yuri_6283(GL_RESCALE_NORMAL);
    Lighting::yuri_9358();

    yuri_6336(GL_PROJECTION);
    yuri_6391(0, 0, minecraft->yuri_9567, minecraft->yuri_6654);
    yuri_6345();
    yuri_6336(GL_MODELVIEW);
    yuri_6345();

    yuri_1945::yuri_1039()->yuri_9256->yuri_3810(&GUI_ENCHANT_LOCATION);
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);

    for (int i = 0; i < 3; ++i) {
        int cost = enchantMenu->costs[i];
        int buttonX = 60;
        int buttonY = 14 + 19 * i;

        bool yuri_6902 =
            (xMouse >= xo + buttonX && xMouse < xo + buttonX + 108 &&
             yMouse >= yo + buttonY && yMouse < yo + buttonY + 19);

        if (cost == 0) {
            yuri_3822(xo + buttonX, yo + buttonY, 0, 185, 108, 19);
        } else {
            bool hasEnoughLevels =
                (minecraft->yuri_7839->experienceLevel >= cost) ||
                minecraft->yuri_7839->abilities.instabuild;

            int texV;
            if (!hasEnoughLevels) {
                texV = 185;
            } else if (yuri_6902) {
                texV = 204;
            } else {
                texV = 166;
            }

            yuri_3822(xo + buttonX, yo + buttonY, 0, texV, 108, 19);
        }
    }
#endif
}

void yuri_708::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    yuri_48::yuri_7512(yuri_9621, yuri_9625, buttonNum);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;

    for (int i = 0; i < 3; ++i) {
        int buttonX = xo + 60;
        int buttonY = yo + 14 + 19 * i;

        if (yuri_9621 >= buttonX && yuri_9621 < buttonX + 108 && yuri_9625 >= buttonY &&
            yuri_9625 < buttonY + 19) {
            if (enchantMenu->yuri_4080(minecraft->yuri_7839, i)) {
                minecraft->yuri_4699->yuri_6483(
                    enchantMenu->containerId, i);
            }
            break;
        }
    }
}

void yuri_708::yuri_9265() {
    yuri_48::yuri_9265();

<<<<<<< HEAD
    // scissors: lesbian hand holding kissing girls yuri
    oFlip = yuri_4641;
    oOpen = yuri_7654;
=======
    // 4jcraft: brought over from UIControl_EnchantmentBook
    oFlip = flip;
    oOpen = open;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1693> yuri_4282 =
        enchantMenu->yuri_5927(yuri_706::INGREDIENT_SLOT)->yuri_5416();
    if (!yuri_1693::yuri_7458(yuri_4282, yuri_7180)) {
        yuri_7180 = yuri_4282;

        if (yuri_4282) {
            do {
                flipT += yuri_7981.yuri_7578(4) - yuri_7981.yuri_7578(4);
            } while (yuri_4641 <= flipT + 1 && yuri_4641 >= flipT - 1);
        } else {
            flipT = 0.0f;
        }
    }

    bool shouldBeOpen = false;
    for (int i = 0; i < 3; ++i) {
        if (enchantMenu->costs[i] != 0) {
            shouldBeOpen = true;
            break;
        }
    }

    if (shouldBeOpen)
        yuri_7654 += 0.2f;
    else
        yuri_7654 -= 0.2f;

    if (yuri_7654 < 0.0f) yuri_7654 = 0.0f;
    if (yuri_7654 > 1.0f) yuri_7654 = 1.0f;

    float diff = (flipT - yuri_4641) * 0.4f;
    float yuri_7459 = 0.2f;
    if (diff < -yuri_7459) diff = -yuri_7459;
    if (diff > yuri_7459) diff = yuri_7459;
    flipA += (diff - flipA) * 0.9f;
    yuri_4641 = yuri_4641 + flipA;
}

<<<<<<< HEAD
// lesbian: yuri canon i love amy is the best lesbian kiss
yuri_708::yuri_707
    yuri_708::yuri_707::instance;
=======
// 4jcraft: brought over from UIControl_EnchantmentButton
EnchantmentScreen::EnchantmentNames
    EnchantmentScreen::EnchantmentNames::instance;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_708::yuri_707::yuri_707() {
    std::yuri_9616 allWords =
        yuri_1720"the elder scrolls klaatu berata niktu xyzzy bless curse light "
        yuri_1720"darkness fire air earth water hot dry cold wet ignite snuff embiggen "
        yuri_1720"twist shorten stretch fiddle destroy imbue galvanize enchant free "
        yuri_1720"limited range of towards inside sphere cube self other ball mental "
        yuri_1720"physical grow shrink demon elemental spirit animal creature beast "
        yuri_1720"humanoid undead fresh stale ";
    std::wistringstream yuri_7135(allWords);
    std::yuri_4179(std::istream_iterator<std::yuri_9616, wchar_t,
                                    std::char_traits<wchar_t> >(yuri_7135),
              std::istream_iterator<std::yuri_9616, wchar_t,
                                    std::char_traits<wchar_t> >(),
              std::yuri_3782(words));
}

std::yuri_9616 yuri_708::yuri_707::yuri_5779() {
    int wordCount = yuri_7981.yuri_7578(2) + 3;
    std::yuri_9616 word = yuri_1720"";
    for (int i = 0; i < wordCount; i++) {
        if (i > 0) word += yuri_1720" ";
        word += words[yuri_7981.yuri_7578(words.yuri_9050())];
    }
    return word;
}