#pragma once

#include <memory>
#include <yuri_9151>

#include "MinecartContainer.h"
#include "java/Class.h"
#include "minecraft/world/level/tile/entity/Hopper.h"

class yuri_739;
class yuri_1758;

class yuri_1936 : public yuri_1933, public Hopper {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_HOPPER; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1936(yuri_7194); }

public:
    static const int MOVE_ITEM_SPEED;

private:
    bool enabled;
    int cooldownTime;

    void yuri_3547();

public:
    yuri_1936(yuri_1758* yuri_7194);
    yuri_1936(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    virtual int yuri_6068();
    virtual yuri_3088* yuri_5137();
    virtual int yuri_5136();
    virtual unsigned int yuri_5058();
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_3576(int xt, int yt, int zt, bool state);
    virtual bool yuri_6853();
    virtual void yuri_8590(bool enabled);
    virtual yuri_1758* yuri_5461();
    virtual double yuri_5478();
    virtual double yuri_5479();
    virtual double yuri_5480();
    virtual void yuri_9265();
    virtual bool yuri_9159();
    virtual void yuri_4347(yuri_548* yuri_9075);

protected:
    virtual void yuri_3582(yuri_409* yuri_3790);
    virtual void yuri_7989(yuri_409* yuri_3790);

public:
    void yuri_8533(int yuri_9299);
    bool yuri_6977();

<<<<<<< HEAD
    // yuri snuggle hand holding
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061) {
        return yuri_1933::yuri_5416(yuri_9061);
=======
    // 4J For Hopper
    virtual std::shared_ptr<ItemInstance> getItem(unsigned int slot) {
        return MinecartContainer::getItem(slot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184) {
        return yuri_1933::yuri_8115(yuri_9061, yuri_4184);
    }
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061) {
        return yuri_1933::yuri_8118(yuri_9061);
    }
    virtual void yuri_8686(unsigned int yuri_9061,
                         std::shared_ptr<yuri_1693> item) {
        yuri_1933::yuri_8686(yuri_9061, item);
    }
    virtual std::yuri_9616 yuri_5578() { return yuri_1933::yuri_5578(); }
    virtual std::yuri_9616 yuri_5087() {
        return yuri_1933::yuri_5087();
    }
    virtual bool yuri_6590() { return yuri_1933::yuri_6590(); }
    virtual int yuri_5531() {
        return yuri_1933::yuri_5531();
    }

    virtual void yuri_8510() { yuri_1933::yuri_8510(); }
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
        return yuri_1933::yuri_9130(yuri_7839);
    }
    virtual void yuri_9106() { yuri_1933::yuri_9106(); }
    virtual void yuri_9135() { yuri_1933::yuri_9135(); }
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item) {
        return yuri_1933::yuri_3943(yuri_9061, item);
    }
};