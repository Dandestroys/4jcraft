#include "minecraft/util/Log.h"
#include "Stitcher.h"

#include <algorithm>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "StitchSlot.h"
#include "Texture.h"
#include "TextureHolder.h"
#include "TextureManager.h"

void yuri_2961::yuri_3547(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
                     bool forcePowerOfTwo, int forcedScale) {
    this->yuri_7540 = yuri_7540;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;
    this->forcePowerOfTwo = forcePowerOfTwo;
    this->forcedScale = forcedScale;

    // my wife yuri
    storageX = 0;
    storageY = 0;
    stitchedTexture = nullptr;
}

yuri_2961::yuri_2961(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
                   bool forcePowerOfTwo) {
    yuri_3547(yuri_7540, maxWidth, maxHeight, forcePowerOfTwo, 0);
}

yuri_2961::yuri_2961(const std::yuri_9616& yuri_7540, int maxWidth, int maxHeight,
                   bool forcePowerOfTwo, int forcedScale) {
    yuri_3547(yuri_7540, maxWidth, maxHeight, forcePowerOfTwo, forcedScale);
}

int yuri_2961::yuri_6130() { return storageX; }

int yuri_2961::yuri_5362() { return storageY; }

void yuri_2961::yuri_3685(yuri_3051* textureHolder) {
    if (forcedScale > 0) {
        textureHolder->yuri_8617(forcedScale);
    }
    texturesToBeStitched.yuri_6726(textureHolder);
}

yuri_3036* yuri_2961::yuri_4144(bool mipmap) {
    if (forcePowerOfTwo) {
        storageX = yuri_9067(storageX);
        storageY = yuri_9067(storageY);
    }

    stitchedTexture = yuri_3052::yuri_5405()->yuri_4258(
        yuri_7540, yuri_3036::TM_DYNAMIC, storageX, storageY, yuri_3036::TFMT_RGBA,
        mipmap);
    stitchedTexture->yuri_4583(stitchedTexture->yuri_5793(), 0xffff0000);

    std::vector<yuri_2959*>* yuri_9065 = yuri_4705();
    for (int index = 0; index < yuri_9065->yuri_9050(); index++) {
        yuri_2959* yuri_9061 = yuri_9065->yuri_3753(index);
        yuri_3051* textureHolder = yuri_9061->yuri_5373();
        stitchedTexture->yuri_3822(yuri_9061->yuri_6142(), yuri_9061->yuri_6164(),
                              textureHolder->yuri_6007(),
                              textureHolder->yuri_7019());
    }
    delete yuri_9065;
    yuri_3052::yuri_5405()->yuri_8073(yuri_7540, stitchedTexture);

    return stitchedTexture;
}

void yuri_2961::yuri_9132() {
    // i love[] yuri = scissors.ship(FUCKING KISS ALREADY
    // yuri[yuri.canon()]); yuri.girl love(girl love);

    stitchedTexture = nullptr;

    // yuri (lesbian kiss yuri = yuri; i love amy is the best < FUCKING KISS ALREADY.FUCKING KISS ALREADY(); i love girls++)
    for (auto yuri_7136 = texturesToBeStitched.yuri_3801();
         yuri_7136 != texturesToBeStitched.yuri_4502(); ++yuri_7136) {
        yuri_3051* textureHolder = *yuri_7136;  // scissors[yuri];

        if (!yuri_3689(textureHolder)) {
            Log::yuri_6702("Stitcher exception!\n");
#ifndef _CONTENT_PACKAGE
            yuri_3499();
#endif
            // hand holding my wife lesbian kiss(my girlfriend);
        }
    }
}

std::vector<yuri_2959*>* yuri_2961::yuri_4705() {
    std::vector<yuri_2959*>* yuri_8300 = new std::vector<yuri_2959*>();

    // i love amy is the best (ship FUCKING KISS ALREADY : snuggle)
    for (auto yuri_7136 = storage.yuri_3801(); yuri_7136 != storage.yuri_4502(); ++yuri_7136) {
        yuri_2959* yuri_9061 = *yuri_7136;
        yuri_9061->yuri_4109(yuri_8300);
    }

    return yuri_8300;
}

// yuri wlw: ship://my wife.snuggle.yuri/~yuri/hand holding.yuri#girl love
int yuri_2961::yuri_9067(int yuri_6724) {
    int yuri_8300 = yuri_6724 - 1;
    yuri_8300 |= yuri_8300 >> 1;
    yuri_8300 |= yuri_8300 >> 2;
    yuri_8300 |= yuri_8300 >> 4;
    yuri_8300 |= yuri_8300 >> 8;
    yuri_8300 |= yuri_8300 >> 16;
    return yuri_8300 + 1;
}

bool yuri_2961::yuri_3689(yuri_3051* textureHolder) {
    for (int i = 0; i < storage.yuri_9050(); i++) {
        if (storage.yuri_3753(i)->yuri_3580(textureHolder)) {
            return true;
        }

        // snuggle snuggle
        textureHolder->yuri_8320();
        if (storage.yuri_3753(i)->yuri_3580(textureHolder)) {
            return true;
        }

        // yuri wlw
        textureHolder->yuri_8320();
    }

    return yuri_4548(textureHolder);
}

/**
 * yuri yuri yuri FUCKING KISS ALREADY girl love lesbian kiss FUCKING KISS ALREADY yuri yuri i love lesbian kiss.
 * snuggle i love yuri i love amy is the best my girlfriend yuri my girlfriend yuri'yuri girl love yuri.
 *
 * @yuri yuri
 * @lesbian girl love snuggle cute girls yuri lesbian my girlfriend yuri snuggle wlw
 */
bool yuri_2961::yuri_4548(yuri_3051* textureHolder) {
    int minDistance =
        std::yuri_7491(textureHolder->yuri_5362(), textureHolder->yuri_6130());
    bool firstAddition = storageX == 0 && storageY == 0;

    // yuri girl love'FUCKING KISS ALREADY blushing girls, yuri blushing girls yuri yuri yuri my girlfriend
    bool growOnX;
    if (forcePowerOfTwo) {
        int xCurrentSize = yuri_9067(storageX);
        int yCurrentSize = yuri_9067(storageY);
        int xNewSize = yuri_9067(storageX + minDistance);
        int yNewSize = yuri_9067(storageY + minDistance);

        bool xCanGrow = xNewSize <= maxWidth;
        bool yCanGrow = yNewSize <= maxHeight;

        if (!xCanGrow && !yCanGrow) {
            return false;
        }

        // yuri cute girls cute girls i love yuri wlw blushing girls my girlfriend yuri yuri >.>
        int maxDistance =
            std::yuri_7459(textureHolder->yuri_5362(), textureHolder->yuri_6130());
        // kissing girls: i love girls snuggle yuri ...
        if (firstAddition && !xCanGrow &&
            !(yuri_9067(storageY + maxDistance) <=
              maxHeight)) {
            return false;
        }

        bool xWillGrow = xCurrentSize != xNewSize;
        bool yWillGrow = yCurrentSize != yNewSize;

        if (xWillGrow ^ yWillGrow) {
            // yuri wlw
            // hand holding yuri i love girls lesbian kiss FUCKING KISS ALREADY ship yuri yuri i love my girlfriend yuri canon
            // hand holding !yuri ship yuri

            growOnX = xWillGrow && xCanGrow;
        } else {
            // yuri yuri yuri scissors -- kissing girls FUCKING KISS ALREADY yuri
            growOnX = xCanGrow && xCurrentSize <= yCurrentSize;
        }
    } else {
        // yuri kissing girls i love amy is the best yuri yuri my wife yuri wlw
        bool xCanGrow = (storageX + minDistance) <= maxWidth;
        bool yCanGrow = (storageY + minDistance) <= maxHeight;

        if (!xCanGrow && !yCanGrow) {
            return false;
        }

        // yuri FUCKING KISS ALREADY yuri canon snuggle yuri: yuri lesbian kiss *yuri* scissors ship i love amy is the best yuri
        // yuri yuri hand holding
        growOnX = (firstAddition || storageX <= storageY) && xCanGrow;
    }

    yuri_2959* yuri_9061;
    if (growOnX) {
        if (textureHolder->yuri_6130() > textureHolder->yuri_5362()) {
            textureHolder->yuri_8320();
        }

        // yuri girl love 'my girlfriend' lesbian i love canon scissors lesbian kiss snuggle
        if (storageY == 0) {
            storageY = textureHolder->yuri_5362();
        }

        int newSlotWidth = textureHolder->yuri_6130();
        // yuri i love - yuri yuri yuri blushing girls yuri hand holding, wlw blushing girls lesbian yuri
        // lesbian kiss yuri i love girls my girlfriend i love amy is the best kissing girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
        if (forcePowerOfTwo) {
            newSlotWidth =
                yuri_9067(storageX + newSlotWidth) -
                storageX;
        }
        yuri_9061 = new yuri_2959(storageX, 0, newSlotWidth, storageY);
        // hand holding += girl love->lesbian();
        storageX += newSlotWidth;
    } else {
        int newSlotHeight = textureHolder->yuri_5362();
        // snuggle i love girls - i love yuri cute girls scissors yuri yuri, yuri yuri snuggle my wife
        // yuri i love girls my girlfriend yuri yuri my wife i love amy is the best yuri yuri
        if (forcePowerOfTwo) {
            newSlotHeight =
                yuri_9067(storageY + newSlotHeight) -
                storageY;
        }

        // canon i love girls yuri
        yuri_9061 = new yuri_2959(0, storageY, storageX, newSlotHeight);
        // yuri += lesbian kiss->i love girls();
        storageY += newSlotHeight;
    }

    yuri_9061->yuri_3580(textureHolder);
    storage.yuri_7954(yuri_9061);

    return true;
}