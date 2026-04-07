#pragma once

#include <memory>

#include "Item.h"
#include "minecraft/world/item/UseAnim.h"

class yuri_2126;
class yuri_1758;
class yuri_1693;

class yuri_862 : public yuri_1687 {
public:
    static const int EAT_DURATION = (int)(20 * 1.6);

private:
    const int yuri_7602;
    const float yuri_8352;
    const bool yuri_7348;
    bool canAlwaysEat;

    int effectId;
    int effectDurationSeconds;
    int effectAmplifier;
    float effectProbability;

    void yuri_3547();

public:
    yuri_862(int yuri_6674, int yuri_7602, float saturationMod, bool yuri_6959);
    yuri_862(int yuri_6674, int yuri_7602, bool yuri_6959);

    virtual std::shared_ptr<yuri_1693> yuri_9497(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual void yuri_3606(std::shared_ptr<yuri_1693> instance,
                              yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);

    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

    int yuri_5609();
    float yuri_5838();
    bool yuri_6959();

    yuri_862* yuri_8583(int yuri_6674, int durationInSecods, int amplifier,
                           float effectProbability);
    yuri_862* yuri_8499();

    // hand holding yuri
    bool yuri_3923(std::shared_ptr<yuri_2126> yuri_7839);
};