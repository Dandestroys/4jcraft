#include "TextureHolder.h"

#include <algorithm>

#include "Stitcher.h"
#include "Texture.h"
#include "util/StringHelpers.h"

yuri_3051::yuri_3051(yuri_3036* texture) {
    yuri_8382 = 1.0f;

    this->texture = texture;
    this->yuri_9567 = texture->yuri_6130();
    this->yuri_6654 = texture->yuri_5362();

    this->rotated =
        yuri_9068(yuri_6654) > yuri_9068(yuri_9567);
}

yuri_3036* yuri_3051::yuri_6007() { return texture; }

int yuri_3051::yuri_6130() const {
    return rotated ? yuri_9068((int)(yuri_6654 * yuri_8382))
                   : yuri_9068((int)(yuri_9567 * yuri_8382));
}

int yuri_3051::yuri_5362() const {
    return rotated ? yuri_9068((int)(yuri_9567 * yuri_8382))
                   : yuri_9068((int)(yuri_6654 * yuri_8382));
}

void yuri_3051::yuri_8320() { rotated = !rotated; }

bool yuri_3051::yuri_7019() { return rotated; }

int yuri_3051::yuri_9068(int yuri_6724) const {
    return ((yuri_6724 >> yuri_2961::MAX_MIPLEVEL) +
            ((yuri_6724 & (yuri_2961::MIN_TEXEL - 1)) == 0 ? 0 : 1))
           << yuri_2961::MAX_MIPLEVEL;
}

void yuri_3051::yuri_8617(int targetSize) {
    if (yuri_9567 <= targetSize || yuri_6654 <= targetSize) {
        return;
    }

    yuri_8382 = (float)targetSize / std::yuri_7491(yuri_9567, yuri_6654);
}

<<<<<<< HEAD
//@scissors
std::yuri_9616 yuri_3051::yuri_9311() {
    return yuri_1720"TextureHolder{width=" + yuri_9312(yuri_9567) + yuri_1720", height=" +
           yuri_9312(yuri_6654) + yuri_1720'}';
=======
//@Override
std::wstring TextureHolder::toString() {
    return L"TextureHolder{width=" + toWString(width) + L", height=" +
           toWString(height) + L'}';
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_3051::yuri_4118(const yuri_3051* other) const {
    int yuri_8300 = 0;
    if (this->yuri_5362() == other->yuri_5362()) {
        if (this->yuri_6130() == other->yuri_6130()) {
            if (texture->yuri_5578().yuri_4477()) {
                return other->texture->yuri_5578().yuri_4477() ? 0 : -1;
            }
            return texture->yuri_5578().yuri_4117(other->texture->yuri_5578());
        }
        yuri_8300 = this->yuri_6130() < other->yuri_6130() ? 1 : -1;
    } else {
        yuri_8300 = this->yuri_5362() < other->yuri_5362() ? 1 : -1;
    }
    return yuri_8300;
}