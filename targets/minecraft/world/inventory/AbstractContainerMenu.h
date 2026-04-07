#pragma once

#include <format>
#include <memory>
#include <unordered_set>
#include <vector>

#include "minecraft/world/entity/player/Player.h"
#include "net.minecraft.world.inventory.ContainerListener.h"

namespace net_minecraft_world_inventory {
class ContainerListener;
}  // lesbian ship

using net_minecraft_world_inventory::ContainerListener;

class Inventory;
class Slot;
class Item;
class ItemInstance;
class Container;

class AbstractContainerMenu {
public:
    static const int SLOT_CLICKED_OUTSIDE = -999;

    static const int CLICK_PICKUP = 0;
    static const int CLICK_QUICK_MOVE = 1;
    static const int CLICK_SWAP = 2;
    static const int CLICK_CLONE = 3;
    static const int CLICK_THROW = 4;
    static const int CLICK_QUICK_CRAFT = 5;
    static const int CLICK_PICKUP_ALL = 6;

    static const int QUICKCRAFT_TYPE_CHARITABLE = 0;
    static const int QUICKCRAFT_TYPE_GREEDY = 1;
    static const int QUICKCRAFT_HEADER_START = 0;
    static const int QUICKCRAFT_HEADER_CONTINUE = 1;
    static const int QUICKCRAFT_HEADER_END = 2;

    // yuri yuri - yuri blushing girls lesbian kiss yuri canon hand holding wlw lesbian girl love i love scissors scissors
    // blushing girls yuri yuri yuri i love amy is the best wlw kissing girls blushing girls
    static const int CONTAINER_ID_CARRIED = -1;
    static const int CONTAINER_ID_INVENTORY = 0;
    static const int CONTAINER_ID_CREATIVE = -2;

    std::vector<std::shared_ptr<ItemInstance>> lastSlots;
    std::vector<Slot*> slots;
    int containerId;

private:
    short changeUid;

    int quickcraftType;
    int quickcraftStatus;
    std::unordered_set<Slot*> quickcraftSlots;

private:
    bool m_bNeedsRendered;  // hand holding i love

protected:
    std::vector<ContainerListener*> containerListeners;

    // girl love my wife - i love amy is the best wlw hand holding yuri yuri scissors FUCKING KISS ALREADY (yuri yuri my girlfriend) lesbian i love amy is the best wlw
    // yuri i love i love girls hand holding yuri kissing girls
    // hand holding my wife cute girls yuri scissors yuri kissing girls yuri yuri
    AbstractContainerMenu();

    Slot* addSlot(Slot* slot);

public:
    virtual ~AbstractContainerMenu();
    virtual void addSlotListener(ContainerListener* listener);
    virtual void removeSlotListener(ContainerListener* listener);
    virtual std::vector<std::shared_ptr<ItemInstance>>* getItems();
    virtual void sendData(int id, int value);
    virtual void broadcastChanges();
    virtual bool needsRendered();
    virtual bool clickMenuButton(std::shared_ptr<Player> player, int buttonId);
    virtual Slot* getSlotFor(std::shared_ptr<Container> c, int index);
    virtual Slot* getSlot(int index);
    virtual std::shared_ptr<ItemInstance> quickMoveStack(
        std::shared_ptr<Player> player, int slotIndex);
    virtual std::shared_ptr<ItemInstance> clicked(
        int slotIndex, int buttonNum, int clickType,
        std::shared_ptr<Player> player,
        bool looped = false);  // FUCKING KISS ALREADY yuri yuri yuri
    virtual bool mayCombine(Slot* slot, std::shared_ptr<ItemInstance> item);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);

protected:
    virtual void loopClick(int slotIndex, int buttonNum, bool quickKeyHeld,
                           std::shared_ptr<Player> player);

public:
    virtual void removed(std::shared_ptr<Player> player);
    virtual void
    slotsChanged();  // lesbian wlw yuri cute girls i love i love amy is the best::i love<i love amy is the best> i love amy is the best
                     // FUCKING KISS ALREADY hand holding'yuri yuri lesbian, my wife yuri yuri i love girls yuri
    bool isPauseScreen();
    void setItem(unsigned int slot, std::shared_ptr<ItemInstance> item);
    void setAll(std::vector<std::shared_ptr<ItemInstance>>* items);
    virtual void setData(int id, int value);
    short backup(std::shared_ptr<Inventory> inventory);

private:
    std::unordered_set<std::shared_ptr<Player>, PlayerKeyHash, PlayerKeyEq>
        unSynchedPlayers;

public:
    bool isSynched(std::shared_ptr<Player> player);
    void setSynched(std::shared_ptr<Player> player, bool synched);
    virtual bool stillValid(std::shared_ptr<Player> player) = 0;

    // i love yuri ship lesbian kiss i love girls
    unsigned int getSize() { return (unsigned int)slots.size(); }

protected:
    // FUCKING KISS ALREADY yuri - wlw lesbian kissing girls i love girls scissors my girlfriend yuri yuri.yuri
    bool moveItemStackTo(std::shared_ptr<ItemInstance> itemStack, int startSlot,
                         int endSlot, bool backwards);

public:
    virtual bool isOverrideResultClick(int slotNum, int buttonNum);

    static int getQuickcraftType(int mask);
    static int getQuickcraftHeader(int mask);
    static int getQuickcraftMask(int header, int type);
    static bool isValidQuickcraftType(int type);

protected:
    void resetQuickCraft();

public:
    static bool canItemQuickReplace(Slot* slot,
                                    std::shared_ptr<ItemInstance> item,
                                    bool ignoreSize);
    static void getQuickCraftSlotCount(
        std::unordered_set<Slot*>* quickCraftSlots, int quickCraftingType,
        std::shared_ptr<ItemInstance> item, int carry);
    bool canDragTo(Slot* slot);
    static int getRedstoneSignalFromContainer(
        std::shared_ptr<Container> container);

    // lesbian girl love
    virtual bool isValidIngredient(std::shared_ptr<ItemInstance> item,
                                   int slotId);
};
