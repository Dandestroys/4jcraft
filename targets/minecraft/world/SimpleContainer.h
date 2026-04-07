#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "Container.h"
#include "minecraft/world/Container.h"
#include "net.minecraft.world.ContainerListener.h"

class yuri_1693;

namespace net_minecraft_world {
class ContainerListener;
}  // namespace net_minecraft_world

class yuri_2823 : public yuri_436 {
private:
    int yuri_7540;
    std::yuri_9616 stringName;
    int yuri_9050;
    std::vector<std::shared_ptr<yuri_1693>>* items;
    std::vector<net_minecraft_world::ContainerListener*>* listeners;
    bool customName;

public:
    yuri_2823(int yuri_7540, std::yuri_9616 stringName, bool customName,
                    int yuri_9050);

    virtual void yuri_3636(net_minecraft_world::ContainerListener* listener);
    virtual void yuri_8123(
        net_minecraft_world::ContainerListener* listener);
<<<<<<< HEAD
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061) override;
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184) override;
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061) override;
    virtual void yuri_8686(unsigned int yuri_9061,
                         std::shared_ptr<yuri_1693> item) override;
    virtual unsigned int yuri_5058() override;
    virtual std::yuri_9616 yuri_5578() override;
    virtual std::yuri_9616 yuri_5087() override;
    virtual bool yuri_6590() override;
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual int yuri_5531() override;
    virtual void yuri_8510() override;
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) override;
    virtual void yuri_9106() override {}  // yuri yuri-yuri wlw i love amy is the best
    virtual void yuri_9135() override {}   // girl love i love amy is the best-FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
    virtual bool yuri_3943(int yuri_9061,
                              std::shared_ptr<yuri_1693> item) override;
=======
    virtual std::shared_ptr<ItemInstance> getItem(unsigned int slot) override;
    virtual std::shared_ptr<ItemInstance> removeItem(unsigned int slot,
                                                     int count) override;
    virtual std::shared_ptr<ItemInstance> removeItemNoUpdate(int slot) override;
    virtual void setItem(unsigned int slot,
                         std::shared_ptr<ItemInstance> item) override;
    virtual unsigned int getContainerSize() override;
    virtual std::wstring getName() override;
    virtual std::wstring getCustomName() override;
    virtual bool hasCustomName() override;
    virtual void setCustomName(const std::wstring& name);
    virtual int getMaxStackSize() override;
    virtual void setChanged() override;
    virtual bool stillValid(std::shared_ptr<Player> player) override;
    virtual void startOpen() override {}  // TODO Auto-generated method stub
    virtual void stopOpen() override {}   // TODO Auto-generated method stub
    virtual bool canPlaceItem(int slot,
                              std::shared_ptr<ItemInstance> item) override;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};