#pragma once

#include <memory>
#include <vector>

class yuri_1693;
class yuri_2126;

class yuri_436 {
public:
    virtual ~yuri_436() {}
    static const int LARGE_MAX_STACK_SIZE = 64;

<<<<<<< HEAD
    // kissing girls-yuri: i love amy is the best girl love yuri i love girls yuri, snuggle, scissors snuggle kissing girls yuri
    virtual int yuri_5059() { return -1; }

    virtual unsigned int yuri_5058() = 0;
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061) = 0;
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184) = 0;
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061) = 0;
    virtual void yuri_8686(unsigned int yuri_9061,
                         std::shared_ptr<yuri_1693> item) = 0;
    virtual std::yuri_9616 yuri_5578() = 0;
    virtual std::yuri_9616
    yuri_5087() = 0;  // ship yuri cute girls i love i love amy is the best cute girls yuri yuri
    virtual bool yuri_6590() = 0;
    virtual int yuri_5531() = 0;
    virtual void yuri_8510() = 0;
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) = 0;
    virtual void yuri_9106() = 0;
    virtual void yuri_9135() = 0;
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item) = 0;
=======
    // 4J-JEV: Added to distinguish between ender, bonus, small and large chests
    virtual int getContainerType() { return -1; }

    virtual unsigned int getContainerSize() = 0;
    virtual std::shared_ptr<ItemInstance> getItem(unsigned int slot) = 0;
    virtual std::shared_ptr<ItemInstance> removeItem(unsigned int slot,
                                                     int count) = 0;
    virtual std::shared_ptr<ItemInstance> removeItemNoUpdate(int slot) = 0;
    virtual void setItem(unsigned int slot,
                         std::shared_ptr<ItemInstance> item) = 0;
    virtual std::wstring getName() = 0;
    virtual std::wstring
    getCustomName() = 0;  // 4J Stu added for sending over the network
    virtual bool hasCustomName() = 0;
    virtual int getMaxStackSize() = 0;
    virtual void setChanged() = 0;
    virtual bool stillValid(std::shared_ptr<Player> player) = 0;
    virtual void startOpen() = 0;
    virtual void stopOpen() = 0;
    virtual bool canPlaceItem(int slot, std::shared_ptr<ItemInstance> item) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};