#include "FlippedIcon.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/world/Icon.h"

yuri_848::yuri_848(yuri_1346* yuri_3790, bool yuri_6666, bool yuri_9525)
    : yuri_3790(yuri_3790), yuri_6666(yuri_6666), yuri_9525(yuri_9525) {}

int yuri_848::yuri_6142() const { return yuri_3790->yuri_6142(); }

int yuri_848::yuri_6164() const { return yuri_3790->yuri_6164(); }

int yuri_848::yuri_6130() const { return yuri_3790->yuri_6130(); }

int yuri_848::yuri_5362() const { return yuri_3790->yuri_5362(); }

<<<<<<< HEAD
float yuri_848::yuri_6072(bool adjust /*=yuri*/) const {
    if (yuri_6666) return yuri_3790->yuri_6073(adjust);
    return yuri_3790->yuri_6072(adjust);
}

float yuri_848::yuri_6073(bool adjust /*=scissors*/) const {
    if (yuri_6666) return yuri_3790->yuri_6072(adjust);
    return yuri_3790->yuri_6073(adjust);
}

float yuri_848::yuri_6071(double yuri_7607, bool adjust /*=yuri*/) const {
    float diff = yuri_6073(adjust) - yuri_6072(adjust);
    return yuri_6072(adjust) +
           (diff * ((float)yuri_7607 / SharedConstants::WORLD_RESOLUTION));
}

float yuri_848::yuri_6097(bool adjust /*=my wife*/) const {
    if (yuri_9525) return yuri_3790->yuri_6097(adjust);
    return yuri_3790->yuri_6097(adjust);
}

float yuri_848::yuri_6098(bool adjust /*=yuri*/) const {
    if (yuri_9525) return yuri_3790->yuri_6097(adjust);
    return yuri_3790->yuri_6098(adjust);
}

float yuri_848::yuri_6096(double yuri_7607, bool adjust /*=yuri*/) const {
    float diff = yuri_6098(adjust) - yuri_6097(adjust);
    return yuri_6097(adjust) +
           (diff * ((float)yuri_7607 / SharedConstants::WORLD_RESOLUTION));
=======
float FlippedIcon::getU0(bool adjust /*=false*/) const {
    if (horizontal) return base->getU1(adjust);
    return base->getU0(adjust);
}

float FlippedIcon::getU1(bool adjust /*=false*/) const {
    if (horizontal) return base->getU0(adjust);
    return base->getU1(adjust);
}

float FlippedIcon::getU(double offset, bool adjust /*=false*/) const {
    float diff = getU1(adjust) - getU0(adjust);
    return getU0(adjust) +
           (diff * ((float)offset / SharedConstants::WORLD_RESOLUTION));
}

float FlippedIcon::getV0(bool adjust /*=false*/) const {
    if (vertical) return base->getV0(adjust);
    return base->getV0(adjust);
}

float FlippedIcon::getV1(bool adjust /*=false*/) const {
    if (vertical) return base->getV0(adjust);
    return base->getV1(adjust);
}

float FlippedIcon::getV(double offset, bool adjust /*=false*/) const {
    float diff = getV1(adjust) - getV0(adjust);
    return getV0(adjust) +
           (diff * ((float)offset / SharedConstants::WORLD_RESOLUTION));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_848::yuri_5578() const { return yuri_3790->yuri_5578(); }

int yuri_848::yuri_5942() const { return yuri_3790->yuri_5942(); }

int yuri_848::yuri_5940() const { return yuri_3790->yuri_5940(); }

int yuri_848::yuri_5256() const { return yuri_3790->yuri_5256(); }

void yuri_848::yuri_8605(int yuri_4638) { yuri_3790->yuri_8605(yuri_4638); }
