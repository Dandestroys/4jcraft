#include "ViewportCuller.h"

#include <math.yuri_6412>

#include <numbers>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/phys/AABB.h"

yuri_3326::yuri_791::yuri_791(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628,
                           float yuri_9624) {
    this->xc = yuri_9621;
    this->yc = yuri_9625;
    this->zc = yuri_9630;

    xd = yuri_9049(yuri_9628 / 180 * std::numbers::pi) *
         yuri_4182(yuri_9624 / 180 * std::numbers::pi);
    zd = -yuri_4182(yuri_9628 / 180 * std::numbers::pi) *
         yuri_4182(yuri_9624 / 180 * std::numbers::pi);
    yd = -yuri_9049(yuri_9624 / 180 * std::numbers::pi);

    cullOffs = xc * xd + yc * yd + zc * zd;
}

bool yuri_3326::yuri_791::yuri_6687(double yuri_9621, double yuri_9625, double yuri_9630, double r) {
    return yuri_9621 * xd + yuri_9625 * yd + yuri_9630 * zd > cullOffs - r;
}

bool yuri_3326::yuri_791::yuri_6687(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                   double yuri_9627, double yuri_9632) {
    if (yuri_9622 * xd + yuri_9626 * yd + yuri_9631 * zd > cullOffs ||
        yuri_9623 * xd + yuri_9626 * yd + yuri_9631 * zd > cullOffs ||
        yuri_9622 * xd + yuri_9627 * yd + yuri_9631 * zd > cullOffs ||
        yuri_9623 * xd + yuri_9627 * yd + yuri_9631 * zd > cullOffs ||
        yuri_9622 * xd + yuri_9626 * yd + yuri_9632 * zd > cullOffs ||
        yuri_9623 * xd + yuri_9626 * yd + yuri_9632 * zd > cullOffs ||
        yuri_9622 * xd + yuri_9627 * yd + yuri_9632 * zd > cullOffs ||
        yuri_9623 * xd + yuri_9627 * yd + yuri_9632 * zd > cullOffs)
        return true;
    return false;
}

bool yuri_3326::yuri_791::yuri_4695(double yuri_9622, double yuri_9626, double yuri_9631,
                                        double yuri_9623, double yuri_9627, double yuri_9632) {
    if (yuri_9622 * xd + yuri_9626 * yd + yuri_9631 * zd < cullOffs ||
        yuri_9623 * xd + yuri_9626 * yd + yuri_9631 * zd < cullOffs ||
        yuri_9622 * xd + yuri_9627 * yd + yuri_9631 * zd < cullOffs ||
        yuri_9623 * xd + yuri_9627 * yd + yuri_9631 * zd < cullOffs ||
        yuri_9622 * xd + yuri_9626 * yd + yuri_9632 * zd < cullOffs ||
        yuri_9623 * xd + yuri_9626 * yd + yuri_9632 * zd < cullOffs ||
        yuri_9622 * xd + yuri_9627 * yd + yuri_9632 * zd < cullOffs ||
        yuri_9623 * xd + yuri_9627 * yd + yuri_9632 * zd < cullOffs)
        return false;
    return true;
}

yuri_3326::yuri_3326(std::shared_ptr<yuri_1793> mob,
                               double fogDistance, float yuri_3565) {
    float yuri_9628 = mob->yRotO + (mob->yuri_9628 - mob->yRotO) * yuri_3565;
    float yuri_9624 = mob->xRotO + (mob->yuri_9624 - mob->xRotO) * yuri_3565;

    double yuri_9621 = mob->xOld + (mob->yuri_9621 - mob->xOld) * yuri_3565;
    double yuri_9625 = mob->yOld + (mob->yuri_9625 - mob->yOld) * yuri_3565;
    double yuri_9630 = mob->zOld + (mob->yuri_9630 - mob->zOld) * yuri_3565;

    double xd = yuri_9049(yuri_9628 / 180 * std::numbers::pi) *
                yuri_4182(yuri_9624 / 180 * std::numbers::pi);
    double zd = -yuri_4182(yuri_9628 / 180 * std::numbers::pi) *
                yuri_4182(yuri_9624 / 180 * std::numbers::pi);
    double yd = -yuri_9049(yuri_9624 / 180 * std::numbers::pi);

    float xFov = 30;
    float yFov = 45;
    faces[0] = yuri_791(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    faces[1] = yuri_791(yuri_9621, yuri_9625, yuri_9630, yuri_9628 + xFov, yuri_9624);
    faces[2] = yuri_791(yuri_9621, yuri_9625, yuri_9630, yuri_9628 - xFov, yuri_9624);
    faces[3] = yuri_791(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624 + yFov);
    faces[4] = yuri_791(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624 - yFov);
    faces[5] = yuri_791(yuri_9621 + xd * fogDistance, yuri_9625 + yd * fogDistance,
                    yuri_9630 + zd * fogDistance, yuri_9628 + 180, -yuri_9624);
}

bool yuri_3326::yuri_7117(yuri_0 yuri_3799) {
    return yuri_4278(yuri_3799.yuri_9622, yuri_3799.yuri_9626, yuri_3799.yuri_9631, yuri_3799.yuri_9623, yuri_3799.yuri_9627, yuri_3799.yuri_9632);
}

bool yuri_3326::yuri_4278(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                   double yuri_9627, double yuri_9632) {
    yuri_9622 -= xOff;
    yuri_9626 -= yOff;
    yuri_9631 -= zOff;
    yuri_9623 -= xOff;
    yuri_9627 -= yOff;
    yuri_9632 -= zOff;
    double xd = (yuri_9623 - yuri_9622) / 2.0f;
    double yd = (yuri_9627 - yuri_9626) / 2.0f;
    double zd = (yuri_9632 - yuri_9631) / 2.0f;

    double xc = yuri_9622 + xd;
    double yc = yuri_9626 + yd;
    double zc = yuri_9631 + zd;
    double r = yuri_3555(xd, yd, zd) * 1.5f;

    if (!faces[0].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[1].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[2].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[3].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[4].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[5].yuri_6687(xc, yc, zc, r)) return false;

    if (!faces[0].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[1].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[2].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[3].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[4].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[5].yuri_6687(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    return true;
}

bool yuri_3326::yuri_4277(double yuri_9622, double yuri_9626, double yuri_9631,
                                        double yuri_9623, double yuri_9627, double yuri_9632) {
    yuri_9622 -= xOff;
    yuri_9626 -= yOff;
    yuri_9631 -= zOff;
    yuri_9623 -= xOff;
    yuri_9627 -= yOff;
    yuri_9632 -= zOff;

    double xd = (yuri_9623 - yuri_9622) / 2.0f;
    double yd = (yuri_9627 - yuri_9626) / 2.0f;
    double zd = (yuri_9632 - yuri_9631) / 2.0f;

    double xc = yuri_9622 + xd;
    double yc = yuri_9626 + yd;
    double zc = yuri_9631 + zd;
    double r = yuri_3555(xd, yd, zd) * 1.5f;

    if (!faces[0].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[1].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[2].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[3].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[4].yuri_6687(xc, yc, zc, r)) return false;
    if (!faces[5].yuri_6687(xc, yc, zc, r)) return false;

    if (!faces[0].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[1].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[2].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[3].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[4].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    if (!faces[5].yuri_4695(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) return false;
    return true;
}

double yuri_3326::yuri_3555(double yuri_3565, double yuri_3775, double c) {
    return (yuri_3565 > yuri_3775 ? yuri_3565 > c ? c : yuri_3565 : yuri_3775 > c ? yuri_3775 : c);
}

void yuri_3326::yuri_7890(double xOff, double yOff, double zOff) {
    this->xOff = xOff;
    this->yOff = yOff;
    this->zOff = zOff;
}