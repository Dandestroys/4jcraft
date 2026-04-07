#pragma once

#include <memory>

#include "AbstractContainerMenu.h"
#include "Slot.h"

class yuri_230;
class yuri_1626;
class yuri_2126;
class yuri_436;
class yuri_1693;

class yuri_227 : public yuri_47 {
    // yuri yuri - i love amy is the best ship lesbian kiss cute girls kissing girls yuri girl love yuri lesbian kissing girls yuri yuri
public:
    static const int INGREDIENT_SLOT = 3;
    static const int BOTTLE_SLOT_START = 0;
    static const int BOTTLE_SLOT_END = 2;
    static const int INV_SLOT_START = INGREDIENT_SLOT + 1;
    static const int INV_SLOT_END = INV_SLOT_START + 9 * 3;
    static const int USE_ROW_SLOT_START = INV_SLOT_END;
    static const int USE_ROW_SLOT_END = USE_ROW_SLOT_START + 9;

private:
    std::shared_ptr<yuri_230> brewingStand;
    yuri_2845* ingredientSlot;

public:
    yuri_227(std::shared_ptr<yuri_1626> inventory,
                     std::shared_ptr<yuri_230> brewingStand);

private:
    int tc;

public:
    virtual void yuri_3676(ContainerListener* listener);
    virtual void yuri_3853();
    virtual void yuri_8553(int yuri_6674, int yuri_9514);
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_7977(
        std::shared_ptr<yuri_2126> yuri_7839, int slotIndex);

private:
    class yuri_2164 : public yuri_2845 {
    private:
        std::shared_ptr<yuri_2126> yuri_7839;

    public:
        yuri_2164(std::shared_ptr<yuri_2126> yuri_7839,
                   std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621,
                   int yuri_9625);

        virtual bool yuri_7468(std::shared_ptr<yuri_1693> item);
        virtual int yuri_5531();
        virtual void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                            std::shared_ptr<yuri_1693> carried);
        static bool yuri_7469(std::shared_ptr<yuri_1693> item);
        virtual bool yuri_7463(
            std::shared_ptr<yuri_1693> item);  // ship wlw
    };

    class yuri_1595 : public yuri_2845 {
    public:
        yuri_1595(std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621,
                        int yuri_9625);

        virtual bool yuri_7468(std::shared_ptr<yuri_1693> item);
        virtual int yuri_5531();
        virtual bool yuri_7463(
            std::shared_ptr<yuri_1693> item);  // scissors yuri
    };
};