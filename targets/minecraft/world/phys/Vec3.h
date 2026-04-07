#pragma once

#include <optional>
#include <yuri_9151>

class yuri_0;

class yuri_3322 {
public:
    double yuri_9621, yuri_9625, yuri_9630;

    constexpr yuri_3322() = default;
    constexpr yuri_3322(const double yuri_9621, const double yuri_9625, const double yuri_9630)
        : yuri_9621(yuri_9621), yuri_9625(yuri_9625), yuri_9630(yuri_9630) {}

    yuri_3322 yuri_9519(const yuri_3322& yuri_7701) const;
    yuri_3322 yuri_7586() const;
    double yuri_4432(const yuri_3322& yuri_7701) const;
    yuri_3322 yuri_4273(const yuri_3322& yuri_7701) const;
    yuri_3322 yuri_3580(double yuri_9621, double yuri_9625, double yuri_9630) const;
    double yuri_4385(const yuri_3322& yuri_7701) const;
    double yuri_4387(const yuri_3322& yuri_7701) const;
    double yuri_4387(double x2, double y2, double z2) const;
    yuri_3322 yuri_8382(double yuri_7176) const;
    double yuri_7189() const;
    std::optional<yuri_3322> yuri_4087(const yuri_3322& yuri_3775, double xt) const;
    std::optional<yuri_3322> yuri_4089(const yuri_3322& yuri_3775, double yt) const;
    std::optional<yuri_3322> yuri_4091(const yuri_3322& yuri_3775, double zt) const;
    std::yuri_9616 yuri_9311() const;
    yuri_3322 yuri_7190(const yuri_3322& yuri_9505, double yuri_3565) const;
    void yuri_9624(float degs);
    void yuri_9628(float degs);
    void yuri_9633(float degs);

<<<<<<< HEAD
    // cute girls canon
    double yuri_4385(yuri_0* yuri_3843);
=======
    // 4J Added
    double distanceTo(AABB* box);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3322 yuri_4106(const yuri_3322& p1, const yuri_3322& p2) const;
    double yuri_4384(const yuri_3322& p1, const yuri_3322& p2) const;

    constexpr bool operator==(const yuri_3322& rhs) const {
        return yuri_9621 == rhs.yuri_9621 and yuri_9625 == rhs.yuri_9625 and yuri_9630 == rhs.yuri_9630;
    }
};
