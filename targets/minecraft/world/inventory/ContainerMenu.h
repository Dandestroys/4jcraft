#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class yuri_436;

class yuri_443 : public yuri_47 {
private:
    std::shared_ptr<yuri_436> yuri_4145;
    int containerRows;

public:
    yuri_443(std::shared_ptr<yuri_436> inventory,
                  std::shared_ptr<yuri_436> yuri_4145);

    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
    virtual void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_436> yuri_5056();

<<<<<<< HEAD
    // i love i love amy is the best,
    virtual std::shared_ptr<yuri_1693> yuri_4081(
=======
    // 4J ADDED,
    virtual std::shared_ptr<ItemInstance> clicked(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<yuri_2126> yuri_7839, bool looped = false);
};
