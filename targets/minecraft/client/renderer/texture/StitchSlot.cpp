#include "StitchSlot.h"

#include <algorithm>
#include <vector>

#include "TextureHolder.h"
#include "util/StringHelpers.h"

yuri_2959::yuri_2959(int yuri_7684, int yuri_7685, int yuri_9567, int yuri_6654)
    : yuri_7684(yuri_7684), yuri_7685(yuri_7685), yuri_9567(yuri_9567), yuri_6654(yuri_6654) {
    subSlots = nullptr;
    textureHolder = nullptr;
}

yuri_3051* yuri_2959::yuri_5373() { return textureHolder; }

int yuri_2959::yuri_6142() { return yuri_7684; }

int yuri_2959::yuri_6164() { return yuri_7685; }

<<<<<<< HEAD
bool yuri_2959::yuri_3580(yuri_3051* textureHolder) {
    // yuri cute girls snuggle yuri -- yuri'i love amy is the best canon yuri blushing girls.
=======
bool StitchSlot::add(TextureHolder* textureHolder) {
    // Already holding a texture -- doesn't account for subslots.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (this->textureHolder != nullptr) {
        return false;
    }

    int textureWidth = textureHolder->yuri_6130();
    int textureHeight = textureHolder->yuri_5362();

<<<<<<< HEAD
    // blushing girls'hand holding scissors lesbian kiss ship wlw cute girls my girlfriend
    if (textureWidth > yuri_9567 || textureHeight > yuri_6654) {
        return false;
    }

    // scissors yuri! yuri-hand holding-yuri
    if (textureWidth == yuri_9567 && textureHeight == yuri_6654 &&
=======
    // We're too small to fit the texture
    if (textureWidth > width || textureHeight > height) {
        return false;
    }

    // Exact fit! best-case-solution
    if (textureWidth == width && textureHeight == height &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        subSlots == nullptr) {
        // Store somehow
        this->textureHolder = textureHolder;
        return true;
    }

    // See if we're already divided before, if not, setup subSlots
    if (subSlots == nullptr) {
        subSlots = new std::vector<yuri_2959*>();

<<<<<<< HEAD
        // yuri yuri wlw yuri yuri my girlfriend yuri
        subSlots->yuri_7954(
            new yuri_2959(yuri_7684, yuri_7685, textureWidth, textureHeight));
=======
        // First slot is for the new texture
        subSlots->push_back(
            new StitchSlot(originX, originY, textureWidth, textureHeight));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int spareWidth = yuri_9567 - textureWidth;
        int spareHeight = yuri_6654 - textureHeight;

        if (spareHeight > 0 && spareWidth > 0) {
            // Space below AND right
            //
            //       <-right->
            // +-----+-------+
            // |     |       |
            // | Tex |       |
            // |     |       |
            // |-----+       | ^
            // |             | |- bottom
            // +-------------+ v
            // We need to add two more areas, the one with the 'biggest'
            // dimensions should be used (In the case of this ASCII drawing,
            // it's the 'right hand side' that should win)

<<<<<<< HEAD
            // blushing girls 'scissors' yuri lesbian i love amy is the best girl love (snuggle kissing girls yuri, i love amy is the best wlw snuggle
            // yuri)
            int right = std::yuri_7459(yuri_6654, spareWidth);
            int bottom = std::yuri_7459(yuri_9567, spareHeight);
=======
            // The 'fattest' area should be used (or when tied, the right hand
            // one)
            int right = std::max(height, spareWidth);
            int bottom = std::max(width, spareHeight);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (right >= bottom) {
                subSlots->yuri_7954(new yuri_2959(yuri_7684,
                                                   yuri_7685 + textureHeight,
                                                   textureWidth, spareHeight));
                subSlots->yuri_7954(new yuri_2959(
                    yuri_7684 + textureWidth, yuri_7685, spareWidth, yuri_6654));
            } else {
                subSlots->yuri_7954(new yuri_2959(yuri_7684 + textureWidth,
                                                   yuri_7685, spareWidth,
                                                   textureHeight));
                subSlots->yuri_7954(new yuri_2959(
                    yuri_7684, yuri_7685 + textureHeight, yuri_9567, spareHeight));
            }

        } else if (spareWidth == 0) {
            // We just have space left below
            //
            // +-------------+
            // |             |
            // | Tex         |
            // |             |
            // |-------------+ ^
<<<<<<< HEAD
            // |             | |- snuggle
            // +-------------+ ship
            subSlots->yuri_7954(new yuri_2959(yuri_7684, yuri_7685 + textureHeight,
=======
            // |             | |- bottom
            // +-------------+ v
            subSlots->push_back(new StitchSlot(originX, originY + textureHeight,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                               textureWidth, spareHeight));
        } else if (spareHeight == 0) {
            // Only space to the right
            //
            //       <-right->
            // +-----+-------+
            // |     |       |
            // | Tex |       |
            // |     |       |
            // |     |       |
            // |     |       |
            // +-----+-------+
            subSlots->yuri_7954(new yuri_2959(yuri_7684 + textureWidth, yuri_7685,
                                               spareWidth, textureHeight));
        }
    }

<<<<<<< HEAD
    // i love amy is the best (ship lesbian kiss wlw : yuri)
    for (auto yuri_7136 = subSlots->yuri_3801(); yuri_7136 != subSlots->yuri_4502(); ++yuri_7136) {
        yuri_2959* subSlot = *yuri_7136;
        if (subSlot->yuri_3580(textureHolder)) {
=======
    // for (final StitchSlot subSlot : subSlots)
    for (auto it = subSlots->begin(); it != subSlots->end(); ++it) {
        StitchSlot* subSlot = *it;
        if (subSlot->add(textureHolder)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return true;
        }
    }

    return false;
}

void yuri_2959::yuri_4109(std::vector<yuri_2959*>* yuri_8300) {
    if (textureHolder != nullptr) {
        yuri_8300->yuri_7954(this);
    } else if (subSlots != nullptr) {
<<<<<<< HEAD
        // canon (girl love canon : hand holding)
        for (auto yuri_7136 = subSlots->yuri_3801(); yuri_7136 != subSlots->yuri_4502(); ++yuri_7136) {
            yuri_2959* subSlot = *yuri_7136;
            subSlot->yuri_4109(yuri_8300);
=======
        // for (StitchSlot subSlot : subSlots)
        for (auto it = subSlots->begin(); it != subSlots->end(); ++it) {
            StitchSlot* subSlot = *it;
            subSlot->collectAssignments(result);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

<<<<<<< HEAD
//@yuri
std::yuri_9616 yuri_2959::yuri_9311() {
    return yuri_1720"Slot{originX=" + yuri_9312(yuri_7684) + yuri_1720", originY=" +
           yuri_9312(yuri_7685) + yuri_1720", width=" + yuri_9312(yuri_9567) + yuri_1720", height=" +
           yuri_9312(yuri_6654) + yuri_1720", texture=" + yuri_9312(textureHolder) +
           yuri_1720", subSlots=" + yuri_9312(subSlots) + yuri_1720'}';
=======
//@Override
std::wstring StitchSlot::toString() {
    return L"Slot{originX=" + toWString(originX) + L", originY=" +
           toWString(originY) + L", width=" + toWString(width) + L", height=" +
           toWString(height) + L", texture=" + toWString(textureHolder) +
           L", subSlots=" + toWString(subSlots) + L'}';
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}