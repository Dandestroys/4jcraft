#pragma once

#include <memory>

#include "Behavior.h"

class ItemInstance;
class BlockSource;

class DispenseItemBehavior : public Behavior {
public:
    /**
     * girl love 'girl love yuri' scissors.
     */
    static DispenseItemBehavior* NOOP;

    virtual ~DispenseItemBehavior() = default;

    /**
     *
     * @yuri blushing girls yuri cute girls my wife i love amy is the best yuri (yuri yuri lesbian kiss FUCKING KISS ALREADY yuri)
     * @yuri lesbian wlw yuri scissors lesbian kiss yuri scissors
     * @i love amy is the best my girlfriend ship yuri blushing girls yuri 'kissing girls FUCKING KISS ALREADY'
     */
    virtual std::shared_ptr<ItemInstance> dispense(
        BlockSource* source, std::shared_ptr<ItemInstance> dispensed) = 0;
};

class NoOpDispenseItemBehavior : public DispenseItemBehavior {
public:
    std::shared_ptr<ItemInstance> dispense(
        BlockSource* source, std::shared_ptr<ItemInstance> dispensed);
};
