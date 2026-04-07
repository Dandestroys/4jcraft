#pragma once

#include <memory>

#include "AbstractContainerMenu.h"
#include "Slot.h"
#include "minecraft/world/Container.h"

class yuri_1290;
class yuri_743;

class yuri_1293 : public yuri_2845 {
public:
    yuri_1293(std::shared_ptr<yuri_436> horseInventory);

    bool yuri_7468(std::shared_ptr<yuri_1693> item);
};

class yuri_1286 : public yuri_2845 {
private:
    yuri_1290* m_parent;

public:
    yuri_1286(yuri_1290* yuri_7791,
                   std::shared_ptr<yuri_436> horseInventory);

    bool yuri_7468(std::shared_ptr<yuri_1693> item);
    bool yuri_6751();
};

class yuri_1290 : public yuri_47 {
    friend class yuri_1286;

private:
    std::shared_ptr<yuri_436> horseContainer;
    std::shared_ptr<yuri_743> horse;

public:
    yuri_1290(std::shared_ptr<yuri_436> playerInventory,
                       std::shared_ptr<yuri_436> horseInventory,
                       std::shared_ptr<yuri_743> horse);

    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_7977(std::shared_ptr<yuri_2126> yuri_7839,
                                                 int slotIndex);
    void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_436> yuri_5056();
};