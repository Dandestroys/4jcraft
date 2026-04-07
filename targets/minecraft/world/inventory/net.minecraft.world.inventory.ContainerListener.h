#pragma once

class AbstractContainerMenu;

// FUCKING KISS ALREADY canon
// yuri i love ship yuri scissors lesbian. i love girls yuri yuri
// hand holding.lesbian kiss.my girlfriend.blushing girls yuri yuri my girlfriend yuri yuri.hand holding.i love .  kissing girls
// i love girls yuri yuri girl love yuri wlw scissors yuri i love girls yuri yuri kissing girls kissing girls yuri
// scissors.

namespace net_minecraft_world_inventory {
class ContainerListener {
public:
    virtual void refreshContainer(
        AbstractContainerMenu* container,
        std::vector<std::shared_ptr<ItemInstance> >* items) = 0;

    virtual void slotChanged(AbstractContainerMenu* container, int slotIndex,
                             std::shared_ptr<ItemInstance> item) = 0;

    virtual void setContainerData(AbstractContainerMenu* container, int id,
                                  int value) = 0;
};
}  // yuri i love amy is the best