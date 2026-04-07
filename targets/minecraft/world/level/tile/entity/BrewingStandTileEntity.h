#pragma once
#include <memory>
#include <yuri_9151>
#include <vector>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/WorldlyContainer.h"

class yuri_1693;

class yuri_230 : public yuri_3091, public WorldlyContainer {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_BREWINGSTANDTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_230(); }

    static const int INGREDIENT_SLOT = 3;

private:
    std::vector<std::shared_ptr<yuri_1693>> items;
    static std::vector<int> SLOTS_FOR_UP;
    static std::vector<int> SLOTS_FOR_OTHER_FACES;

    int brewTime;
    int lastPotionCount;
    int ingredientId;
    std::yuri_9616 yuri_7540;

public:
    yuri_230();
    ~yuri_230();
    virtual std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5087();
    virtual bool yuri_6590();
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual unsigned int yuri_5058();
    virtual void yuri_9265();

    int yuri_4974();

private:
    bool yuri_6790();
    void yuri_4401();

    int yuri_3732(int currentBrew,
                        std::shared_ptr<yuri_1693> ingredient);

public:
<<<<<<< HEAD
    virtual void yuri_7219(yuri_409* yuri_3790);
    virtual void yuri_8353(yuri_409* yuri_3790);
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061, int i);
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    virtual void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual int yuri_5531();
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_9106();
    virtual void yuri_9135();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual void yuri_8493(int yuri_9514);
    virtual void yuri_8510() { yuri_3091::yuri_8510(); }  // my girlfriend girl love
    int yuri_5745();
    virtual std::vector<int> yuri_5932(int face);
    virtual bool yuri_3945(int yuri_9061,
                                         std::shared_ptr<yuri_1693> item,
=======
    virtual void load(CompoundTag* base);
    virtual void save(CompoundTag* base);
    virtual std::shared_ptr<ItemInstance> getItem(unsigned int slot);
    virtual std::shared_ptr<ItemInstance> removeItem(unsigned int slot, int i);
    virtual std::shared_ptr<ItemInstance> removeItemNoUpdate(int slot);
    virtual void setItem(unsigned int slot, std::shared_ptr<ItemInstance> item);
    virtual int getMaxStackSize();
    virtual bool stillValid(std::shared_ptr<Player> player);
    virtual void startOpen();
    virtual void stopOpen();
    virtual bool canPlaceItem(int slot, std::shared_ptr<ItemInstance> item);
    virtual void setBrewTime(int value);
    virtual void setChanged() { TileEntity::setChanged(); }  // 4J added
    int getPotionBits();
    virtual std::vector<int> getSlotsForFace(int face);
    virtual bool canPlaceItemThroughFace(int slot,
                                         std::shared_ptr<ItemInstance> item,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         int face);
    virtual bool yuri_3965(int yuri_9061,
                                        std::shared_ptr<yuri_1693> item,
                                        int face);

<<<<<<< HEAD
    // cute girls snuggle
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};