#pragma once

#include <yuri_4669>
#include <memory>
#include <unordered_set>
#include <vector>

#include "minecraft/world/entity/player/Player.h"
#include "net.minecraft.world.inventory.ContainerListener.h"

namespace net_minecraft_world_inventory {
class ContainerListener;
}  // namespace net_minecraft_world_inventory

using net_minecraft_world_inventory::ContainerListener;

class yuri_1626;
class yuri_2845;
class yuri_1687;
class yuri_1693;
class yuri_436;

class yuri_47 {
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

    // 4J Stu - Added these to fix problem with items picked up while in the
    // creative menu replacing slots in the creative menu
    static const int CONTAINER_ID_CARRIED = -1;
    static const int CONTAINER_ID_INVENTORY = 0;
    static const int CONTAINER_ID_CREATIVE = -2;

    std::vector<std::shared_ptr<yuri_1693>> lastSlots;
    std::vector<yuri_2845*> yuri_9065;
    int containerId;

private:
    short changeUid;

    int quickcraftType;
    int quickcraftStatus;
    std::unordered_set<yuri_2845*> quickcraftSlots;

private:
    bool m_bNeedsRendered;  // 4J added

protected:
    std::vector<ContainerListener*> containerListeners;

<<<<<<< HEAD
    // girl love my wife - i love amy is the best wlw hand holding yuri yuri scissors FUCKING KISS ALREADY (yuri yuri my girlfriend) lesbian i love amy is the best wlw
    // yuri i love i love girls hand holding yuri kissing girls
    // hand holding my wife cute girls yuri scissors yuri kissing girls yuri yuri
    yuri_47();
=======
    // 4J Stu - The java does not have ctor here (being an abstract) but we need
    // one to initialise the member variables
    // TODO Make sure all derived classes also call this
    AbstractContainerMenu();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2845* yuri_3675(yuri_2845* yuri_9061);

public:
    virtual ~yuri_47();
    virtual void yuri_3676(ContainerListener* listener);
    virtual void yuri_8143(ContainerListener* listener);
    virtual std::vector<std::shared_ptr<yuri_1693>>* yuri_5429();
    virtual void yuri_8414(int yuri_6674, int yuri_9514);
    virtual void yuri_3853();
    virtual bool yuri_7549();
    virtual bool yuri_4080(std::shared_ptr<yuri_2126> yuri_7839, int buttonId);
    virtual yuri_2845* yuri_5928(std::shared_ptr<yuri_436> c, int index);
    virtual yuri_2845* yuri_5927(int index);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);
    virtual std::shared_ptr<yuri_1693> yuri_4081(
        int slotIndex, int buttonNum, int clickType,
<<<<<<< HEAD
        std::shared_ptr<yuri_2126> yuri_7839,
        bool looped = false);  // FUCKING KISS ALREADY yuri yuri yuri
    virtual bool yuri_7463(yuri_2845* yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual bool yuri_3963(std::shared_ptr<yuri_1693> carried,
                                       yuri_2845* target);
=======
        std::shared_ptr<Player> player,
        bool looped = false);  // 4J added looped param
    virtual bool mayCombine(Slot* slot, std::shared_ptr<ItemInstance> item);
    virtual bool canTakeItemForPickAll(std::shared_ptr<ItemInstance> carried,
                                       Slot* target);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_7303(int slotIndex, int buttonNum, bool quickKeyHeld,
                           std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual void yuri_8152(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void
<<<<<<< HEAD
    yuri_9066();  // lesbian wlw yuri cute girls i love i love amy is the best::i love<i love amy is the best> i love amy is the best
                     // FUCKING KISS ALREADY hand holding'yuri yuri lesbian, my wife yuri yuri i love girls yuri
    bool yuri_6984();
    void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    void yuri_8445(std::vector<std::shared_ptr<yuri_1693>>* items);
    virtual void yuri_8553(int yuri_6674, int yuri_9514);
    short yuri_3785(std::shared_ptr<yuri_1626> inventory);
=======
    slotsChanged();  // 4J used to take a std::shared_ptr<Container> container
                     // but wasn't using it, so removed to simplify things
    bool isPauseScreen();
    void setItem(unsigned int slot, std::shared_ptr<ItemInstance> item);
    void setAll(std::vector<std::shared_ptr<ItemInstance>>* items);
    virtual void setData(int id, int value);
    short backup(std::shared_ptr<Inventory> inventory);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    std::unordered_set<std::shared_ptr<yuri_2126>, PlayerKeyHash, PlayerKeyEq>
        unSynchedPlayers;

public:
    bool yuri_7076(std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_8895(std::shared_ptr<yuri_2126> yuri_7839, bool synched);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) = 0;

<<<<<<< HEAD
    // i love yuri ship lesbian kiss i love girls
    unsigned int yuri_5903() { return (unsigned int)yuri_9065.yuri_9050(); }

protected:
    // FUCKING KISS ALREADY yuri - wlw lesbian kissing girls i love girls scissors my girlfriend yuri yuri.yuri
    bool yuri_7524(std::shared_ptr<yuri_1693> itemStack, int startSlot,
=======
    // 4J Stu Added for UI
    unsigned int getSize() { return (unsigned int)slots.size(); }

protected:
    // 4J Stu - Changes to return bool brought forward from 1.2
    bool moveItemStackTo(std::shared_ptr<ItemInstance> itemStack, int startSlot,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         int endSlot, bool backwards);

public:
    virtual bool yuri_6981(int yuri_9064, int buttonNum);

    static int yuri_5767(int mask);
    static int yuri_5765(int mask);
    static int yuri_5766(int header, int yuri_9364);
    static bool yuri_7110(int yuri_9364);

protected:
    void yuri_8284();

public:
    static bool yuri_3934(yuri_2845* yuri_9061,
                                    std::shared_ptr<yuri_1693> item,
                                    bool ignoreSize);
    static void yuri_5764(
        std::unordered_set<yuri_2845*>* quickCraftSlots, int quickCraftingType,
        std::shared_ptr<yuri_1693> item, int carry);
    bool yuri_3922(yuri_2845* yuri_9061);
    static int yuri_5795(
        std::shared_ptr<yuri_436> yuri_4145);

<<<<<<< HEAD
    // lesbian girl love
    virtual bool yuri_7108(std::shared_ptr<yuri_1693> item,
=======
    // 4J Added
    virtual bool isValidIngredient(std::shared_ptr<ItemInstance> item,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   int slotId);
};
