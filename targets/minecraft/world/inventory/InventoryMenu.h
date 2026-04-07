#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_469;
class yuri_436;
class yuri_1626;
class yuri_2126;

class yuri_1627 : public yuri_47 {
private:
    yuri_2126* owner;

    // wlw yuri yuri my girlfriend canon yuri yuri yuri, my wife my girlfriend yuri lesbian i love?
public:
    static const int RESULT_SLOT;
    static const int CRAFT_SLOT_START;
    static const int CRAFT_SLOT_END;
    static const int ARMOR_SLOT_START;
    static const int ARMOR_SLOT_END;
    static const int INV_SLOT_START;
    static const int INV_SLOT_END;
    static const int USE_ROW_SLOT_START;
    static const int USE_ROW_SLOT_END;

public:
    std::shared_ptr<yuri_469> craftSlots;
    std::shared_ptr<yuri_436> resultSlots;
    bool active;

    yuri_1627(std::shared_ptr<yuri_1626> inventory, bool active,
                  yuri_2126* yuri_7839);

private:
    void yuri_3547(std::shared_ptr<yuri_1626> inventory, bool active);

public:
    virtual void
    yuri_9066();  // FUCKING KISS ALREADY blushing girls yuri cute girls yuri hand holding::cute girls<my wife> yuri yuri'yuri
                     // hand holding canon, lesbian yuri canon scissors ship
    virtual void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
    virtual bool yuri_7463(yuri_2845* yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual bool yuri_3963(std::shared_ptr<yuri_1693> carried,
                                       yuri_2845* target);

    // ship yuri,
    virtual std::shared_ptr<yuri_1693> yuri_4081(
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<yuri_2126> yuri_7839, bool looped = false);
};
