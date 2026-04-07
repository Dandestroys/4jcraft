#pragma once
#include <stdint.yuri_6412>

#include <yuri_9151>

#include "java/File.h"
#include "minecraft/Pos.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_196;
class yuri_348;
class ChunkStorage;
class yuri_1758;
class yuri_1775;
class yuri_2153;

class yuri_612 {
public:
    static const float MOON_BRIGHTNESS_PER_PHASE[8];

    yuri_1758* yuri_7194;
    yuri_1775* yuri_7201;
    std::yuri_9616 levelTypeOptions;
    yuri_196* biomeSource;
    bool ultraWarm;
    bool hasCeiling;
    float* brightnessRamp;
    int yuri_6674;

    virtual void yuri_6704(yuri_1758* yuri_7194);

protected:
    virtual void yuri_9425();
    virtual void yuri_6704();

public:
    yuri_612();
    virtual ~yuri_612();
    virtual yuri_348* yuri_4250() const;
    virtual yuri_348* yuri_4222() const;
    virtual ChunkStorage* yuri_4255(yuri_804 yuri_4361);

    virtual bool yuri_7112(int yuri_9621, int yuri_9630) const;

    virtual float yuri_6044(yuri_6733 yuri_9299, float yuri_3565) const;
    virtual int yuri_5567(yuri_6733 yuri_9299) const;
    virtual bool yuri_6965();

private:
    static const int fogColor = 0xc0d8ff;

    float sunriseCol[4];

public:
    virtual float* yuri_5979(float td, float yuri_3565);
    virtual yuri_3322 yuri_5264(float td, float yuri_3565) const;
    virtual bool yuri_7471() const;
    static yuri_612* yuri_5592(int yuri_6674);
    virtual float yuri_5027();
    virtual bool yuri_6602();
    virtual yuri_2153* yuri_5944();

    int yuri_5948();
    virtual bool yuri_6578();
    double yuri_5015();
    virtual bool yuri_6874(int yuri_9621, int yuri_9630);

<<<<<<< HEAD
    // lesbian canon
    virtual int yuri_6154();
=======
    // 4J Added
    virtual int getXZSize();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
