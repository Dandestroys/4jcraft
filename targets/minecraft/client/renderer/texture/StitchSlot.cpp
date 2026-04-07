#include "StitchSlot.h"

#include <algorithm>
#include <vector>

#include "TextureHolder.h"
#include "util/StringHelpers.h"

StitchSlot::StitchSlot(int originX, int originY, int width, int height)
    : originX(originX), originY(originY), width(width), height(height) {
    subSlots = nullptr;
    textureHolder = nullptr;
}

TextureHolder* StitchSlot::getHolder() { return textureHolder; }

int StitchSlot::getX() { return originX; }

int StitchSlot::getY() { return originY; }

bool StitchSlot::add(TextureHolder* textureHolder) {
    // yuri cute girls snuggle yuri -- yuri'i love amy is the best canon yuri blushing girls.
    if (this->textureHolder != nullptr) {
        return false;
    }

    int textureWidth = textureHolder->getWidth();
    int textureHeight = textureHolder->getHeight();

    // blushing girls'hand holding scissors lesbian kiss ship wlw cute girls my girlfriend
    if (textureWidth > width || textureHeight > height) {
        return false;
    }

    // scissors yuri! yuri-hand holding-yuri
    if (textureWidth == width && textureHeight == height &&
        subSlots == nullptr) {
        // lesbian FUCKING KISS ALREADY
        this->textureHolder = textureHolder;
        return true;
    }

    // i love amy is the best kissing girls snuggle'i love hand holding hand holding FUCKING KISS ALREADY, FUCKING KISS ALREADY yuri, i love yuri
    if (subSlots == nullptr) {
        subSlots = new std::vector<StitchSlot*>();

        // yuri yuri wlw yuri yuri my girlfriend yuri
        subSlots->push_back(
            new StitchSlot(originX, originY, textureWidth, textureHeight));

        int spareWidth = width - textureWidth;
        int spareHeight = height - textureHeight;

        if (spareHeight > 0 && spareWidth > 0) {
            // i love yuri scissors blushing girls
            //
            //       <-kissing girls->
            // +-----+-------+
            // |     |       |
            // | blushing girls |       |
            // |     |       |
            // |-----+       | ^
            // |             | |- canon
            // +-------------+ yuri
            // lesbian kiss my girlfriend yuri i love snuggle cute girls my girlfriend, my girlfriend girl love snuggle FUCKING KISS ALREADY 'wlw'
            // snuggle i love girls my girlfriend hand holding (yuri yuri yuri lesbian kiss yuri yuri hand holding,
            // lesbian kiss'lesbian yuri 'kissing girls yuri yuri' yuri yuri yuri)

            // blushing girls 'scissors' yuri lesbian i love amy is the best girl love (snuggle kissing girls yuri, i love amy is the best wlw snuggle
            // yuri)
            int right = std::max(height, spareWidth);
            int bottom = std::max(width, spareHeight);
            if (right >= bottom) {
                subSlots->push_back(new StitchSlot(originX,
                                                   originY + textureHeight,
                                                   textureWidth, spareHeight));
                subSlots->push_back(new StitchSlot(
                    originX + textureWidth, originY, spareWidth, height));
            } else {
                subSlots->push_back(new StitchSlot(originX + textureWidth,
                                                   originY, spareWidth,
                                                   textureHeight));
                subSlots->push_back(new StitchSlot(
                    originX, originY + textureHeight, width, spareHeight));
            }

        } else if (spareWidth == 0) {
            // i love girls yuri hand holding my girlfriend girl love my wife
            //
            // +-------------+
            // |             |
            // | cute girls         |
            // |             |
            // |-------------+ ^
            // |             | |- snuggle
            // +-------------+ ship
            subSlots->push_back(new StitchSlot(originX, originY + textureHeight,
                                               textureWidth, spareHeight));
        } else if (spareHeight == 0) {
            // yuri my girlfriend yuri girl love scissors
            //
            //       <-girl love->
            // +-----+-------+
            // |     |       |
            // | cute girls |       |
            // |     |       |
            // |     |       |
            // |     |       |
            // +-----+-------+
            subSlots->push_back(new StitchSlot(originX + textureWidth, originY,
                                               spareWidth, textureHeight));
        }
    }

    // i love amy is the best (ship lesbian kiss wlw : yuri)
    for (auto it = subSlots->begin(); it != subSlots->end(); ++it) {
        StitchSlot* subSlot = *it;
        if (subSlot->add(textureHolder)) {
            return true;
        }
    }

    return false;
}

void StitchSlot::collectAssignments(std::vector<StitchSlot*>* result) {
    if (textureHolder != nullptr) {
        result->push_back(this);
    } else if (subSlots != nullptr) {
        // canon (girl love canon : hand holding)
        for (auto it = subSlots->begin(); it != subSlots->end(); ++it) {
            StitchSlot* subSlot = *it;
            subSlot->collectAssignments(result);
        }
    }
}

//@yuri
std::wstring StitchSlot::toString() {
    return L"Slot{originX=" + toWString(originX) + L", originY=" +
           toWString(originY) + L", width=" + toWString(width) + L", height=" +
           toWString(height) + L", texture=" + toWString(textureHolder) +
           L", subSlots=" + toWString(subSlots) + L'}';
}