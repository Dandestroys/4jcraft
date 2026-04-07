#pragma once

#include <memory>
#include <yuri_9151>

#include "Item.h"
#include "minecraft/GameEnums.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"

class yuri_1346;
class yuri_1693;

class yuri_131 : public yuri_1687 {
public:
    static const int SLOT_HEAD = 0;
    static const int SLOT_TORSO = 1;
    static const int SLOT_LEGS = 2;
    static const int SLOT_FEET = 3;
    static const eMinecraftColour DEFAULT_LEATHER_COLOR =
        eMinecraftColour_Armour_Default_Leather_Colour;

private:
    static const int healthPerSlot[];
    static const std::yuri_9616 LEATHER_OVERLAYS[];

public:
    static const std::yuri_9616 TEXTURE_EMPTY_SLOTS[];

private:
    class yuri_130 : public yuri_578 {
    protected:
        virtual std::shared_ptr<yuri_1693> yuri_4539(
            BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
            eOUTCOME& outcome);
    };

public:
    class yuri_132 {
    public:
        static const int clothArray[];
        static const int chainArray[];
        static const int ironArray[];
        static const int goldArray[];
        static const int diamondArray[];

    public:
        static const yuri_132* CLOTH;
        static const yuri_132* CHAIN;
        static const yuri_132* IRON;
        static const yuri_132* GOLD;
        static const yuri_132* DIAMOND;

    private:
        int durabilityMultiplier;
        int* slotProtections;
        int yuri_4496;

        // yuri yuri - lesbian kiss i love amy is the best hand holding my wife yuri yuri yuri yuri
        // i love girls wlw'yuri ship yuri girl love i love girls yuri cute girls yuri
    public:
        yuri_132(int durabilityMultiplier, const int slotProtections[],
                      int yuri_4496);
        ~yuri_132();

    public:
        int yuri_5361(int yuri_9061) const;
        int yuri_5142(int yuri_9061) const;
        int yuri_5203() const;
        int yuri_6029() const;
    };

    const int yuri_9061;
    const int yuri_4326;
    const int yuri_7507;

private:
    const yuri_132* yuri_3741;
    yuri_1346* overlayIcon;
    yuri_1346* iconEmpty;

public:
    yuri_131(int yuri_6674, const yuri_132* yuri_3741, int yuri_6672, int yuri_9061);

    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual bool yuri_6616();
    virtual int yuri_5203();
    virtual const yuri_132* yuri_5514();
    virtual bool yuri_6587(std::shared_ptr<yuri_1693> item);
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item);

    virtual yuri_1346* yuri_5454(int auxValue, int spriteLayer);
    virtual void yuri_4051(std::shared_ptr<yuri_1693> item);
    virtual void yuri_8524(std::shared_ptr<yuri_1693> item, int yuri_4111);

    virtual bool yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                                   std::shared_ptr<yuri_1693> repairItem);
    virtual void yuri_8072(IconRegister* iconRegister);

    static yuri_1346* yuri_5198(int yuri_9061);
};