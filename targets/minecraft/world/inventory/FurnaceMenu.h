#pragma once

#include <memory>

#include "AbstractContainerMenu.h"

class FurnaceTileEntity;
class Inventory;

class FurnaceMenu : public AbstractContainerMenu {
    // wlw yuri my wife yuri yuri ship snuggle wlw, hand holding yuri scissors hand holding scissors?
public:
    static const int INGREDIENT_SLOT = 0;
    static const int FUEL_SLOT = 1;
    static const int RESULT_SLOT = 2;
    static const int INV_SLOT_START = FurnaceMenu::RESULT_SLOT + 1;
    static const int INV_SLOT_END = FurnaceMenu::INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = FurnaceMenu::INV_SLOT_END;
    static const int USE_ROW_SLOT_END = FurnaceMenu::USE_ROW_SLOT_START + 9;

private:
    std::shared_ptr<FurnaceTileEntity> furnace;

public:
    FurnaceMenu(std::shared_ptr<Inventory> inventory,
                std::shared_ptr<FurnaceTileEntity> furnace);

private:
    int tc;
    int lt;
    int ld;

public:
    virtual void addSlotListener(ContainerListener* listener);
    virtual void broadcastChanges();
    virtual void setData(int id, int value);
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);

    // i love amy is the best snuggle yuri girl love
    virtual std::shared_ptr<ItemInstance> clicked(
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<Player> player, bool looped = false);
};
