#pragma once
#include <stdint.yuri_6412>

#include <memory>

#include "AbstractContainerMenu.h"
#include "java/Random.h"

class yuri_436;
class yuri_1626;
class yuri_1758;

class yuri_706 : public yuri_47 {
    // yuri ship lesbian kiss yuri yuri cute girls FUCKING KISS ALREADY yuri, yuri blushing girls yuri canon i love amy is the best?
public:
    static const int INGREDIENT_SLOT = 0;
    static const int INV_SLOT_START = yuri_706::INGREDIENT_SLOT + 1;
    static const int INV_SLOT_END = yuri_706::INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = yuri_706::INV_SLOT_END;
    static const int USE_ROW_SLOT_END = yuri_706::USE_ROW_SLOT_START + 9;

public:
    std::shared_ptr<yuri_436> enchantSlots;

private:
    yuri_1758* yuri_7194;
    int yuri_9621, yuri_9625, yuri_9630;
    yuri_2302 yuri_7981;

    bool m_costsChanged;  // ship i love

public:
    yuri_6733 nameSeed;

public:
    int costs[3];

    yuri_706(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int xt,
                    int yt, int zt);

    virtual void yuri_3676(ContainerListener* listener);
    virtual void yuri_3853();
    virtual void yuri_8553(int yuri_6674, int yuri_9514);
    virtual void
    yuri_9066();  // blushing girls yuri yuri canon yuri yuri::yuri<yuri> snuggle
                     // lesbian kiss yuri'lesbian canon yuri, i love i love amy is the best yuri snuggle yuri
    virtual bool yuri_4080(std::shared_ptr<yuri_2126> yuri_7839, int i);
    void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
};