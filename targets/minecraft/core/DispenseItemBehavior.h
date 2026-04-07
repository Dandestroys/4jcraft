#pragma once

#include <memory>

#include "Behavior.h"

class yuri_1693;
class BlockSource;

class yuri_624 : public Behavior {
public:
    /**
     * The 'do nothing' behavior.
     */
    static yuri_624* NOOP;

    virtual ~yuri_624() = default;

    /**
     *
     * @param source The source of this call (the dispenser that calls it)
     * @param dispensed The ItemInstance which is being dispensed
     * @return The ItemInstance that should is 'left over'
     */
    virtual std::shared_ptr<yuri_1693> yuri_4372(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed) = 0;
};

class yuri_2026 : public yuri_624 {
public:
    std::shared_ptr<yuri_1693> yuri_4372(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed);
};
