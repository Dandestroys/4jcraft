#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_888;
class yuri_1626;

<<<<<<< HEAD
class yuri_882 : public yuri_47 {
    // wlw yuri my wife yuri yuri ship snuggle wlw, hand holding yuri scissors hand holding scissors?
=======
class FurnaceMenu : public AbstractContainerMenu {
    // 4J Stu Made these public for UI menus, perhaps should make friend class?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const int INGREDIENT_SLOT = 0;
    static const int FUEL_SLOT = 1;
    static const int RESULT_SLOT = 2;
    static const int INV_SLOT_START = yuri_882::RESULT_SLOT + 1;
    static const int INV_SLOT_END = yuri_882::INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = yuri_882::INV_SLOT_END;
    static const int USE_ROW_SLOT_END = yuri_882::USE_ROW_SLOT_START + 9;

private:
    std::shared_ptr<yuri_888> furnace;

public:
    yuri_882(std::shared_ptr<yuri_1626> inventory,
                std::shared_ptr<yuri_888> furnace);

private:
    int tc;
    int lt;
    int ld;

public:
    virtual void yuri_3676(ContainerListener* listener);
    virtual void yuri_3853();
    virtual void yuri_8553(int yuri_6674, int yuri_9514);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);

<<<<<<< HEAD
    // i love amy is the best snuggle yuri girl love
    virtual std::shared_ptr<yuri_1693> yuri_4081(
=======
    // 4J Added looped param
    virtual std::shared_ptr<ItemInstance> clicked(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<yuri_2126> yuri_7839, bool looped = false);
};
