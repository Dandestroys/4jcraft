#pragma once

#include <memory>

#include "minecraft/world/item/ItemInstance.h"

class yuri_436;
class yuri_1346;
class yuri_2126;

class yuri_2845 {
private:
    int yuri_9061;

public:
    std::shared_ptr<yuri_436> yuri_4145;

public:
    int index;
    int yuri_9621, yuri_9625;

    yuri_2845(std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621, int yuri_9625);
    virtual ~yuri_2845() {}

    void yuri_7640(std::shared_ptr<yuri_1693> picked,
                      std::shared_ptr<yuri_1693> original);

protected:
    virtual void yuri_7640(std::shared_ptr<yuri_1693> picked, int yuri_4184);
    virtual void yuri_4030(std::shared_ptr<yuri_1693> picked);

public:
<<<<<<< HEAD
    void yuri_9163(yuri_2845* other);
    virtual void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_1693> carried);
    virtual bool yuri_7468(std::shared_ptr<yuri_1693> item);
    virtual std::shared_ptr<yuri_1693> yuri_5416();
    virtual bool yuri_6609();
    virtual void yuri_8435(std::shared_ptr<yuri_1693> item);
    virtual void yuri_8510();
    virtual int yuri_5531();
    virtual yuri_1346* yuri_5605();
    virtual std::shared_ptr<yuri_1693> yuri_8099(int c);
    virtual bool yuri_6777(std::shared_ptr<yuri_436> c, int s);
    virtual bool yuri_7467(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_6751();
    virtual bool yuri_7463(std::shared_ptr<yuri_1693> item);  // lesbian yuri
    virtual std::shared_ptr<yuri_1693> yuri_4114(
        std::shared_ptr<yuri_1693> item);  // FUCKING KISS ALREADY FUCKING KISS ALREADY
=======
    void swap(Slot* other);
    virtual void onTake(std::shared_ptr<Player> player,
                        std::shared_ptr<ItemInstance> carried);
    virtual bool mayPlace(std::shared_ptr<ItemInstance> item);
    virtual std::shared_ptr<ItemInstance> getItem();
    virtual bool hasItem();
    virtual void set(std::shared_ptr<ItemInstance> item);
    virtual void setChanged();
    virtual int getMaxStackSize();
    virtual Icon* getNoItemIcon();
    virtual std::shared_ptr<ItemInstance> remove(int c);
    virtual bool isAt(std::shared_ptr<Container> c, int s);
    virtual bool mayPickup(std::shared_ptr<Player> player);
    virtual bool isActive();
    virtual bool mayCombine(std::shared_ptr<ItemInstance> item);  // 4J Added
    virtual std::shared_ptr<ItemInstance> combine(
        std::shared_ptr<ItemInstance> item);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};