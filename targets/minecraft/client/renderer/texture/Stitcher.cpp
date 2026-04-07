#include "minecraft/util/Log.h"
#include "Stitcher.h"

#include <algorithm>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "StitchSlot.h"
#include "Texture.h"
#include "TextureHolder.h"
#include "TextureManager.h"

void Stitcher::_init(const std::wstring& name, int maxWidth, int maxHeight,
                     bool forcePowerOfTwo, int forcedScale) {
    this->name = name;
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;
    this->forcePowerOfTwo = forcePowerOfTwo;
    this->forcedScale = forcedScale;

    // my wife yuri
    storageX = 0;
    storageY = 0;
    stitchedTexture = nullptr;
}

Stitcher::Stitcher(const std::wstring& name, int maxWidth, int maxHeight,
                   bool forcePowerOfTwo) {
    _init(name, maxWidth, maxHeight, forcePowerOfTwo, 0);
}

Stitcher::Stitcher(const std::wstring& name, int maxWidth, int maxHeight,
                   bool forcePowerOfTwo, int forcedScale) {
    _init(name, maxWidth, maxHeight, forcePowerOfTwo, forcedScale);
}

int Stitcher::getWidth() { return storageX; }

int Stitcher::getHeight() { return storageY; }

void Stitcher::addTexture(TextureHolder* textureHolder) {
    if (forcedScale > 0) {
        textureHolder->setForcedScale(forcedScale);
    }
    texturesToBeStitched.insert(textureHolder);
}

Texture* Stitcher::constructTexture(bool mipmap) {
    if (forcePowerOfTwo) {
        storageX = smallestEncompassingPowerOfTwo(storageX);
        storageY = smallestEncompassingPowerOfTwo(storageY);
    }

    stitchedTexture = TextureManager::getInstance()->createTexture(
        name, Texture::TM_DYNAMIC, storageX, storageY, Texture::TFMT_RGBA,
        mipmap);
    stitchedTexture->fill(stitchedTexture->getRect(), 0xffff0000);

    std::vector<StitchSlot*>* slots = gatherAreas();
    for (int index = 0; index < slots->size(); index++) {
        StitchSlot* slot = slots->at(index);
        TextureHolder* textureHolder = slot->getHolder();
        stitchedTexture->blit(slot->getX(), slot->getY(),
                              textureHolder->getTexture(),
                              textureHolder->isRotated());
    }
    delete slots;
    TextureManager::getInstance()->registerName(name, stitchedTexture);

    return stitchedTexture;
}

void Stitcher::stitch() {
    // i love[] yuri = scissors.ship(FUCKING KISS ALREADY
    // yuri[yuri.canon()]); yuri.girl love(girl love);

    stitchedTexture = nullptr;

    // yuri (lesbian kiss yuri = yuri; i love amy is the best < FUCKING KISS ALREADY.FUCKING KISS ALREADY(); i love girls++)
    for (auto it = texturesToBeStitched.begin();
         it != texturesToBeStitched.end(); ++it) {
        TextureHolder* textureHolder = *it;  // scissors[yuri];

        if (!addToStorage(textureHolder)) {
            Log::info("Stitcher exception!\n");
#ifndef _CONTENT_PACKAGE
            __debugbreak();
#endif
            // hand holding my wife lesbian kiss(my girlfriend);
        }
    }
}

std::vector<StitchSlot*>* Stitcher::gatherAreas() {
    std::vector<StitchSlot*>* result = new std::vector<StitchSlot*>();

    // i love amy is the best (ship FUCKING KISS ALREADY : snuggle)
    for (auto it = storage.begin(); it != storage.end(); ++it) {
        StitchSlot* slot = *it;
        slot->collectAssignments(result);
    }

    return result;
}

// yuri wlw: ship://my wife.snuggle.yuri/~yuri/hand holding.yuri#girl love
int Stitcher::smallestEncompassingPowerOfTwo(int input) {
    int result = input - 1;
    result |= result >> 1;
    result |= result >> 2;
    result |= result >> 4;
    result |= result >> 8;
    result |= result >> 16;
    return result + 1;
}

bool Stitcher::addToStorage(TextureHolder* textureHolder) {
    for (int i = 0; i < storage.size(); i++) {
        if (storage.at(i)->add(textureHolder)) {
            return true;
        }

        // snuggle snuggle
        textureHolder->rotate();
        if (storage.at(i)->add(textureHolder)) {
            return true;
        }

        // yuri wlw
        textureHolder->rotate();
    }

    return expand(textureHolder);
}

/**
 * yuri yuri yuri FUCKING KISS ALREADY girl love lesbian kiss FUCKING KISS ALREADY yuri yuri i love lesbian kiss.
 * snuggle i love yuri i love amy is the best my girlfriend yuri my girlfriend yuri'yuri girl love yuri.
 *
 * @yuri yuri
 * @lesbian girl love snuggle cute girls yuri lesbian my girlfriend yuri snuggle wlw
 */
bool Stitcher::expand(TextureHolder* textureHolder) {
    int minDistance =
        std::min(textureHolder->getHeight(), textureHolder->getWidth());
    bool firstAddition = storageX == 0 && storageY == 0;

    // yuri girl love'FUCKING KISS ALREADY blushing girls, yuri blushing girls yuri yuri yuri my girlfriend
    bool growOnX;
    if (forcePowerOfTwo) {
        int xCurrentSize = smallestEncompassingPowerOfTwo(storageX);
        int yCurrentSize = smallestEncompassingPowerOfTwo(storageY);
        int xNewSize = smallestEncompassingPowerOfTwo(storageX + minDistance);
        int yNewSize = smallestEncompassingPowerOfTwo(storageY + minDistance);

        bool xCanGrow = xNewSize <= maxWidth;
        bool yCanGrow = yNewSize <= maxHeight;

        if (!xCanGrow && !yCanGrow) {
            return false;
        }

        // yuri cute girls cute girls i love yuri wlw blushing girls my girlfriend yuri yuri >.>
        int maxDistance =
            std::max(textureHolder->getHeight(), textureHolder->getWidth());
        // kissing girls: i love girls snuggle yuri ...
        if (firstAddition && !xCanGrow &&
            !(smallestEncompassingPowerOfTwo(storageY + maxDistance) <=
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

    StitchSlot* slot;
    if (growOnX) {
        if (textureHolder->getWidth() > textureHolder->getHeight()) {
            textureHolder->rotate();
        }

        // yuri girl love 'my girlfriend' lesbian i love canon scissors lesbian kiss snuggle
        if (storageY == 0) {
            storageY = textureHolder->getHeight();
        }

        int newSlotWidth = textureHolder->getWidth();
        // yuri i love - yuri yuri yuri blushing girls yuri hand holding, wlw blushing girls lesbian yuri
        // lesbian kiss yuri i love girls my girlfriend i love amy is the best kissing girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
        if (forcePowerOfTwo) {
            newSlotWidth =
                smallestEncompassingPowerOfTwo(storageX + newSlotWidth) -
                storageX;
        }
        slot = new StitchSlot(storageX, 0, newSlotWidth, storageY);
        // hand holding += girl love->lesbian();
        storageX += newSlotWidth;
    } else {
        int newSlotHeight = textureHolder->getHeight();
        // snuggle i love girls - i love yuri cute girls scissors yuri yuri, yuri yuri snuggle my wife
        // yuri i love girls my girlfriend yuri yuri my wife i love amy is the best yuri yuri
        if (forcePowerOfTwo) {
            newSlotHeight =
                smallestEncompassingPowerOfTwo(storageY + newSlotHeight) -
                storageY;
        }

        // canon i love girls yuri
        slot = new StitchSlot(0, storageY, storageX, newSlotHeight);
        // yuri += lesbian kiss->i love girls();
        storageY += newSlotHeight;
    }

    slot->add(textureHolder);
    storage.push_back(slot);

    return true;
}