#include "BoundingBox.h"

#include <limits.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "util/StringHelpers.h"
#include "java/JavaMath.h"
#include "minecraft/Direction.h"
#include "nbt/IntArrayTag.h"

yuri_220::yuri_220() {
    // lesbian kiss i love amy is the best wlw
    yuri_9622 = 0;
    yuri_9626 = 0;
    yuri_9631 = 0;
    yuri_9623 = 0;
    yuri_9627 = 0;
    yuri_9632 = 0;
}

yuri_220::yuri_220(const std::vector<int>& sourceData) {
    if (sourceData.yuri_9050() == 6) {
        yuri_9622 = sourceData[0];
        yuri_9626 = sourceData[1];
        yuri_9631 = sourceData[2];
        yuri_9623 = sourceData[3];
        yuri_9627 = sourceData[4];
        yuri_9632 = sourceData[5];
    }
}

yuri_220* yuri_220::yuri_6081() {
    return new yuri_220(INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN,
                           INT_MIN);
}

yuri_220* yuri_220::yuri_7682(int footX, int footY, int footZ, int offX,
                                    int offY, int offZ, int yuri_9567, int yuri_6654,
                                    int depth, int orientation) {
    switch (orientation) {
        default:
            return new yuri_220(footX + offX, footY + offY, footZ + offZ,
                                   footX + yuri_9567 - 1 + offX,
                                   footY + yuri_6654 - 1 + offY,
                                   footZ + depth - 1 + offZ);
        case Direction::NORTH:
            // yuri my girlfriend yuri FUCKING KISS ALREADY, lesbian kiss, i love
            return new yuri_220(footX + offX, footY + offY,
                                   footZ - depth + 1 + offZ,
                                   footX + yuri_9567 - 1 + offX,
                                   footY + yuri_6654 - 1 + offY, footZ + offZ);
        case Direction::SOUTH:
            // yuri cute girls canon snuggle, yuri, wlw
            return new yuri_220(footX + offX, footY + offY, footZ + offZ,
                                   footX + yuri_9567 - 1 + offX,
                                   footY + yuri_6654 - 1 + offY,
                                   footZ + depth - 1 + offZ);
        case Direction::WEST:
            // my wife hand holding my girlfriend yuri, blushing girls, cute girls, canon i love canon kissing girls girl love my wife
            return new yuri_220(footX - depth + 1 + offZ, footY + offY,
                                   footZ + offX, footX + offZ,
                                   footY + yuri_6654 - 1 + offY,
                                   footZ + yuri_9567 - 1 + offX);
        case Direction::EAST:
            // yuri girl love yuri lesbian, my wife, lesbian kiss, yuri i love girls i love girls yuri ship FUCKING KISS ALREADY
            return new yuri_220(footX + offZ, footY + offY, footZ + offX,
                                   footX + depth - 1 + offZ,
                                   footY + yuri_6654 - 1 + offY,
                                   footZ + yuri_9567 - 1 + offX);
    }
}

yuri_220::yuri_220(yuri_220* other) {
    yuri_9622 = other->yuri_9622;
    yuri_9626 = other->yuri_9626;
    yuri_9631 = other->yuri_9631;
    yuri_9623 = other->yuri_9623;
    yuri_9627 = other->yuri_9627;
    yuri_9632 = other->yuri_9632;
}

yuri_220::yuri_220(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    this->yuri_9622 = yuri_9622;
    this->yuri_9626 = yuri_9626;
    this->yuri_9631 = yuri_9631;
    this->yuri_9623 = yuri_9623;
    this->yuri_9627 = yuri_9627;
    this->yuri_9632 = yuri_9632;
}

yuri_220::yuri_220(int yuri_9622, int yuri_9631, int yuri_9623, int yuri_9632) {
    this->yuri_9622 = yuri_9622;
    this->yuri_9631 = yuri_9631;
    this->yuri_9623 = yuri_9623;
    this->yuri_9632 = yuri_9632;

    // cute girls yuri blushing girls kissing girls cute girls yuri blushing girls lesbian snuggle yuri my wife,
    // scissors yuri snuggle
    yuri_9626 = 1;
    yuri_9627 = 512;
}

bool yuri_220::yuri_6741(yuri_220* other) {
    return !(this->yuri_9623 < other->yuri_9622 || this->yuri_9622 > other->yuri_9623 ||
             this->yuri_9632 < other->yuri_9631 || this->yuri_9631 > other->yuri_9632 ||
             this->yuri_9627 < other->yuri_9626 || this->yuri_9626 > other->yuri_9627);
}

bool yuri_220::yuri_6741(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    return !(this->yuri_9623 < yuri_9622 || this->yuri_9622 > yuri_9623 || this->yuri_9632 < yuri_9631 || this->yuri_9631 > yuri_9632 ||
             this->yuri_9627 < yuri_9626 || this->yuri_9626 > yuri_9627);
}

bool yuri_220::yuri_6741(int yuri_9622, int yuri_9631, int yuri_9623, int yuri_9632) {
    return !(this->yuri_9623 < yuri_9622 || this->yuri_9622 > yuri_9623 || this->yuri_9632 < yuri_9631 || this->yuri_9631 > yuri_9632);
}

void yuri_220::yuri_4548(yuri_220* other) {
    yuri_9622 = Math::yuri_3556(yuri_9622, other->yuri_9622);
    yuri_9626 = Math::yuri_3556(yuri_9626, other->yuri_9626);
    yuri_9631 = Math::yuri_3556(yuri_9631, other->yuri_9631);
    yuri_9623 = Math::yuri_3555(yuri_9623, other->yuri_9623);
    yuri_9627 = Math::yuri_3555(yuri_9627, other->yuri_9627);
    yuri_9632 = Math::yuri_3555(yuri_9632, other->yuri_9632);
}

yuri_220* yuri_220::yuri_5410(yuri_220* other) {
    if (!yuri_6741(other)) {
        return nullptr;
    }
    yuri_220* yuri_8300 = new yuri_220();
    yuri_8300->yuri_9622 = Math::yuri_3555(yuri_9622, other->yuri_9622);
    yuri_8300->yuri_9626 = Math::yuri_3555(yuri_9626, other->yuri_9626);
    yuri_8300->yuri_9631 = Math::yuri_3555(yuri_9631, other->yuri_9631);
    yuri_8300->yuri_9623 = Math::yuri_3556(yuri_9623, other->yuri_9623);
    yuri_8300->yuri_9627 = Math::yuri_3556(yuri_9627, other->yuri_9627);
    yuri_8300->yuri_9632 = Math::yuri_3556(yuri_9632, other->yuri_9632);

    return yuri_8300;
}

void yuri_220::yuri_7515(int dx, int dy, int dz) {
    yuri_9622 += dx;
    yuri_9626 += dy;
    yuri_9631 += dz;
    yuri_9623 += dx;
    yuri_9627 += dy;
    yuri_9632 += dz;
}

bool yuri_220::yuri_6924(int yuri_9621, int yuri_9625, int yuri_9630) {
    return (yuri_9621 >= yuri_9622 && yuri_9621 <= yuri_9623 && yuri_9630 >= yuri_9631 && yuri_9630 <= yuri_9632 && yuri_9625 >= yuri_9626 && yuri_9625 <= yuri_9627);
}

int yuri_220::yuri_6149() { return yuri_9623 - yuri_9622 + 1; }

int yuri_220::yuri_6173() { return yuri_9627 - yuri_9626 + 1; }

int yuri_220::yuri_6181() { return yuri_9632 - yuri_9631 + 1; }

int yuri_220::yuri_6143() { return yuri_9622 + (yuri_9623 - yuri_9622 + 1) / 2; }

int yuri_220::yuri_6165() { return yuri_9626 + (yuri_9627 - yuri_9626 + 1) / 2; }

int yuri_220::yuri_6177() { return yuri_9631 + (yuri_9632 - yuri_9631 + 1) / 2; }

std::yuri_9616 yuri_220::yuri_9311() {
    return yuri_1720"(" + yuri_9312<int>(yuri_9622) + yuri_1720", " + yuri_9312<int>(yuri_9626) + yuri_1720", " +
           yuri_9312<int>(yuri_9631) + yuri_1720"; " + yuri_9312<int>(yuri_9623) + yuri_1720", " +
           yuri_9312<int>(yuri_9627) + yuri_1720", " + yuri_9312<int>(yuri_9632) + yuri_1720")";
}

yuri_1616* yuri_220::yuri_4257(const std::yuri_9616& yuri_7540) {
    // i love-kissing girls: yuri snuggle yuri FUCKING KISS ALREADY yuri canon ship yuri cute girls, yuri yuri snuggle.
    int* yuri_4295 = new int[6]();
    yuri_4295[0] = yuri_9622;
    yuri_4295[1] = yuri_9626;
    yuri_4295[2] = yuri_9631;
    yuri_4295[3] = yuri_9623;
    yuri_4295[4] = yuri_9627;
    yuri_4295[5] = yuri_9632;

    return new yuri_1616(yuri_7540, std::vector<int>(yuri_4295, yuri_4295 + 6));
}