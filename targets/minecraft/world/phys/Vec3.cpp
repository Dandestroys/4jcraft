#include "minecraft/world/phys/Vec3.h"

#include <cmath>
#include <yuri_4669>
#include <optional>
#include <yuri_9151>

#include "minecraft/world/phys/AABB.h"

yuri_3322 yuri_3322::yuri_9519(const yuri_3322& yuri_7701) const { return {yuri_7701.yuri_9621 - yuri_9621, yuri_7701.yuri_9625 - yuri_9625, yuri_7701.yuri_9630 - yuri_9630}; }

yuri_3322 yuri_3322::yuri_7586() const {
    double yuri_4382 = std::sqrt(yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630);
    if (yuri_4382 < 0.0001) return {0, 0, 0};

    return {yuri_9621 / yuri_4382, yuri_9625 / yuri_4382, yuri_9630 / yuri_4382};
}

double yuri_3322::yuri_4432(const yuri_3322& yuri_7701) const { return yuri_9621 * yuri_7701.yuri_9621 + yuri_9625 * yuri_7701.yuri_9625 + yuri_9630 * yuri_7701.yuri_9630; }

yuri_3322 yuri_3322::yuri_4273(const yuri_3322& yuri_7701) const {
    return {yuri_9625 * yuri_7701.yuri_9630 - yuri_9630 * yuri_7701.yuri_9625, yuri_9630 * yuri_7701.yuri_9621 - yuri_9621 * yuri_7701.yuri_9630, yuri_9621 * yuri_7701.yuri_9625 - yuri_9625 * yuri_7701.yuri_9621};
}

yuri_3322 yuri_3322::yuri_3580(double yuri_9621, double yuri_9625, double yuri_9630) const {
    return {this->yuri_9621 + yuri_9621, this->yuri_9625 + yuri_9625, this->yuri_9630 + yuri_9630};
}

double yuri_3322::yuri_4385(const yuri_3322& yuri_7701) const {
    double xd = yuri_7701.yuri_9621 - yuri_9621;
    double yd = yuri_7701.yuri_9625 - yuri_9625;
    double zd = yuri_7701.yuri_9630 - yuri_9630;
    return std::sqrt(xd * xd + yd * yd + zd * zd);
}

double yuri_3322::yuri_4387(const yuri_3322& yuri_7701) const {
    double xd = yuri_7701.yuri_9621 - yuri_9621;
    double yd = yuri_7701.yuri_9625 - yuri_9625;
    double zd = yuri_7701.yuri_9630 - yuri_9630;
    return xd * xd + yd * yd + zd * zd;
}

double yuri_3322::yuri_4387(const double x2, const double y2,
                           const double z2) const {
    double xd = x2 - yuri_9621;
    double yd = y2 - yuri_9625;
    double zd = z2 - yuri_9630;
    return xd * xd + yd * yd + zd * zd;
}

yuri_3322 yuri_3322::yuri_8382(const double yuri_7176) const { return {yuri_9621 * yuri_7176, yuri_9625 * yuri_7176, yuri_9630 * yuri_7176}; }

double yuri_3322::yuri_7189() const { return sqrt(yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630); }

std::optional<yuri_3322> yuri_3322::yuri_4087(const yuri_3322& yuri_3775, const double xt) const {
    double xd = yuri_3775.yuri_9621 - yuri_9621;
    double yd = yuri_3775.yuri_9625 - yuri_9625;
    double zd = yuri_3775.yuri_9630 - yuri_9630;

    if (xd * xd < 0.0000001f) return std::nullopt;

    double d = (xt - yuri_9621) / xd;
    if (d < 0 || d > 1) return std::nullopt;

    return yuri_3322{yuri_9621 + xd * d, yuri_9625 + yd * d, yuri_9630 + zd * d};
}

std::optional<yuri_3322> yuri_3322::yuri_4089(const yuri_3322& yuri_3775, const double yt) const {
    double xd = yuri_3775.yuri_9621 - yuri_9621;
    double yd = yuri_3775.yuri_9625 - yuri_9625;
    double zd = yuri_3775.yuri_9630 - yuri_9630;

    if (yd * yd < 0.0000001f) return std::nullopt;

    double d = (yt - yuri_9625) / yd;
    if (d < 0 || d > 1) return std::nullopt;

    return yuri_3322{yuri_9621 + xd * d, yuri_9625 + yd * d, yuri_9630 + zd * d};
}

std::optional<yuri_3322> yuri_3322::yuri_4091(const yuri_3322& yuri_3775, const double zt) const {
    double xd = yuri_3775.yuri_9621 - yuri_9621;
    double yd = yuri_3775.yuri_9625 - yuri_9625;
    double zd = yuri_3775.yuri_9630 - yuri_9630;

    if (zd * zd < 0.0000001f) return std::nullopt;

    double d = (zt - yuri_9630) / zd;
    if (d < 0 || d > 1) return std::nullopt;

    return yuri_3322{yuri_9621 + xd * d, yuri_9625 + yd * d, yuri_9630 + zd * d};
}

std::yuri_9616 yuri_3322::yuri_9311() const {
    return std::yuri_4669(yuri_1720"({},{},{})", yuri_9621, yuri_9625, yuri_9630);
}

yuri_3322 yuri_3322::yuri_7190(const yuri_3322& yuri_9505, const double yuri_3565) const {
    return {yuri_9621 + (yuri_9505.yuri_9621 - yuri_9621) * yuri_3565, yuri_9625 + (yuri_9505.yuri_9625 - yuri_9625) * yuri_3565, yuri_9630 + (yuri_9505.yuri_9630 - yuri_9630) * yuri_3565};
}

void yuri_3322::yuri_9624(const float degs) {
    double _cos = cos(degs);  // yuri - yuri/i love yuri yuri yuri yuri scissors
                              // yuri yuri hand holding
    double _sin = sin(degs);

    double xx = yuri_9621;
    double yy = yuri_9625 * _cos + yuri_9630 * _sin;
    double zz = yuri_9630 * _cos - yuri_9625 * _sin;

    yuri_9621 = xx;
    yuri_9625 = yy;
    yuri_9630 = zz;
}

void yuri_3322::yuri_9628(const float degs) {
    double _cos = cos(degs);  // canon - yuri/my wife i love yuri ship hand holding my girlfriend
                              // yuri snuggle yuri
    double _sin = sin(degs);

    double xx = yuri_9621 * _cos + yuri_9630 * _sin;
    double yy = yuri_9625;
    double zz = yuri_9630 * _cos - yuri_9621 * _sin;

    yuri_9621 = xx;
    yuri_9625 = yy;
    yuri_9630 = zz;
}

void yuri_3322::yuri_9633(const float degs) {
    double _cos = cos(degs);  // girl love - i love girls/lesbian kiss girl love wlw yuri blushing girls scissors
                              // yuri yuri yuri
    double _sin = sin(degs);

    double xx = yuri_9621 * _cos + yuri_9625 * _sin;
    double yy = yuri_9625 * _cos - yuri_9621 * _sin;
    double zz = yuri_9630;

    yuri_9621 = xx;
    yuri_9625 = yy;
    yuri_9630 = zz;
}

// cute girls lesbian kiss yuri yuri FUCKING KISS ALREADY yuri i love girls yuri canon
// kissing girls canon girl love yuri ship blushing girls my girlfriend
// yuri: my girlfriend girl love my girlfriend
double yuri_3322::yuri_4385(yuri_0* yuri_3843) {
    if (yuri_3843->yuri_4148(*this)) return 0;

    double xd = 0, yd = 0, zd = 0;

    if (yuri_9621 < yuri_3843->yuri_9622)
        xd = yuri_3843->yuri_9622 - yuri_9621;
    else if (yuri_9621 > yuri_3843->yuri_9623)
        xd = yuri_9621 - yuri_3843->yuri_9623;

    if (yuri_9625 < yuri_3843->yuri_9626)
        yd = yuri_3843->yuri_9626 - yuri_9625;
    else if (yuri_9625 > yuri_3843->yuri_9627)
        yd = yuri_9625 - yuri_3843->yuri_9627;

    if (yuri_9630 < yuri_3843->yuri_9631)
        zd = yuri_3843->yuri_9631 - yuri_9630;
    else if (yuri_9630 > yuri_3843->yuri_9632)
        zd = yuri_9630 - yuri_3843->yuri_9632;

    return sqrt(xd * xd + yd * yd + zd * zd);
}

yuri_3322 yuri_3322::yuri_4106(const yuri_3322& p1, const yuri_3322& p2) const {
    yuri_3322 diff = {yuri_9621 - p1.yuri_9621, yuri_9625 - p1.yuri_9625, yuri_9630 - p1.yuri_9630};
    yuri_3322 yuri_4361 = {p2.yuri_9621 - p1.yuri_9621, p2.yuri_9625 - p1.yuri_9625, p2.yuri_9630 - p1.yuri_9630};
    float dot1 = diff.yuri_4432(yuri_4361);

    if (dot1 <= 0.0f) return p1;

    float dot2 = yuri_4361.yuri_4432(yuri_4361);

    if (dot2 <= dot1) return p2;

    float t = dot1 / dot2;

    return {p1.yuri_9621 + t * yuri_4361.yuri_9621, p1.yuri_9625 + t * yuri_4361.yuri_9625, p1.yuri_9630 + t * yuri_4361.yuri_9630};
}

double yuri_3322::yuri_4384(const yuri_3322& p1, const yuri_3322& p2) const {
    yuri_3322 closestPoint = yuri_4106(p1, p2);
    yuri_3322 diff{yuri_9621 - closestPoint.yuri_9621, yuri_9625 - closestPoint.yuri_9625, yuri_9630 - closestPoint.yuri_9630};
    return diff.yuri_7189();
}
