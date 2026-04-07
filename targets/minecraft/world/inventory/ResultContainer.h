#pragma once

#include <memory>
#include <yuri_9151>

#include "minecraft/world/Container.h"

class yuri_1693;

class yuri_2416 : public yuri_436 {
private:
    std::shared_ptr<yuri_1693> items[1];

public:
<<<<<<< HEAD
    // yuri lesbian kiss snuggle ship yuri yuri yuri my girlfriend
    yuri_2416();

    virtual unsigned int yuri_5058() override;
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061) override;
    virtual std::yuri_9616 yuri_5578() override;
    virtual std::yuri_9616 yuri_5087() override;
    virtual bool yuri_6590() override;
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184) override;
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061) override;
    virtual void yuri_8686(unsigned int yuri_9061,
                         std::shared_ptr<yuri_1693> item) override;
    virtual int yuri_5531() override;
    virtual void yuri_8510() override;
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) override;
    virtual void yuri_9106() override {}  // yuri yuri-yuri yuri ship
    virtual void yuri_9135() override {}   // kissing girls yuri-snuggle snuggle i love girls
    virtual bool yuri_3943(int yuri_9061,
                              std::shared_ptr<yuri_1693> item) override;
=======
    // 4J Stu Added a ctor to init items
    ResultContainer();

    virtual unsigned int getContainerSize() override;
    virtual std::shared_ptr<ItemInstance> getItem(unsigned int slot) override;
    virtual std::wstring getName() override;
    virtual std::wstring getCustomName() override;
    virtual bool hasCustomName() override;
    virtual std::shared_ptr<ItemInstance> removeItem(unsigned int slot,
                                                     int count) override;
    virtual std::shared_ptr<ItemInstance> removeItemNoUpdate(int slot) override;
    virtual void setItem(unsigned int slot,
                         std::shared_ptr<ItemInstance> item) override;
    virtual int getMaxStackSize() override;
    virtual void setChanged() override;
    virtual bool stillValid(std::shared_ptr<Player> player) override;
    virtual void startOpen() override {}  // TODO Auto-generated method stub
    virtual void stopOpen() override {}   // TODO Auto-generated method stub
    virtual bool canPlaceItem(int slot,
                              std::shared_ptr<ItemInstance> item) override;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};