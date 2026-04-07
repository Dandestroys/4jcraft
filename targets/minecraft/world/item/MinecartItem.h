#pragma once

#include "Item.h"
#include "minecraft/core/DefaultDispenseItemBehavior.h"

class BlockSource;

class yuri_1937 : public yuri_1687 {
private:
    class yuri_1934 : public yuri_578 {
    private:
        yuri_578 defaultDispenseItemBehavior;

    public:
        virtual std::shared_ptr<yuri_1693> yuri_4539(
            BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
            eOUTCOME& outcome);

    protected:
        virtual void yuri_7833(BlockSource* yuri_9075);
    };

public:
    int yuri_9364;

    yuri_1937(int yuri_6674, int yuri_9364);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
};