#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "Hopper.h"
#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1689;
class yuri_1758;

class yuri_1285 : public yuri_3091, public Hopper {
public:
<<<<<<< HEAD
    eINSTANCEOF yuri_1188() { return eTYPE_HOPPERTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_1285(); }
    // lesbian yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();
=======
    eINSTANCEOF GetType() { return eTYPE_HOPPERTILEENTITY; }
    static TileEntity* create() { return new HopperTileEntity(); }
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    static const int MOVE_ITEM_SPEED = 8;

private:
    std::vector<std::shared_ptr<yuri_1693>> items;
    std::yuri_9616 yuri_7540;
    int cooldownTime;

public:
    yuri_1285();
    ~yuri_1285();

    virtual void yuri_7219(yuri_409* yuri_3790);
    virtual void yuri_8353(yuri_409* yuri_3790);
    virtual void yuri_8510();
    virtual unsigned int yuri_5058();
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184);
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    virtual void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5087();
    virtual bool yuri_6590();
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual int yuri_5531();
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_9106();
    virtual void yuri_9135();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual void yuri_9265();
    virtual bool yuri_9350();

private:
    virtual bool yuri_4468();

public:
    static bool yuri_9159(Hopper* hopper);

private:
    static bool yuri_9354(Hopper* hopper, yuri_436* yuri_4145,
                                      int yuri_9061, int face);

public:
    static bool yuri_3625(yuri_436* yuri_4145, std::shared_ptr<yuri_1689> item);
    static std::shared_ptr<yuri_1693> yuri_3625(
        yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int face);

private:
    static bool yuri_3944(yuri_436* yuri_4145,
                                        std::shared_ptr<yuri_1693> item,
                                        int yuri_9061, int face);
    static bool yuri_3964(yuri_436* yuri_4145,
                                         std::shared_ptr<yuri_1693> item,
                                         int yuri_9061, int face);
    static std::shared_ptr<yuri_1693> yuri_9349(
        yuri_436* yuri_4145, std::shared_ptr<yuri_1693> item, int yuri_9061,
        int face);
    virtual std::shared_ptr<yuri_436> yuri_4906();

public:
    static std::shared_ptr<yuri_436> yuri_5939(Hopper* hopper);
    static std::shared_ptr<yuri_1689> yuri_5417(yuri_1758* yuri_7194, double xt,
                                                 double yt, double zt);
    static std::shared_ptr<yuri_436> yuri_5057(yuri_1758* yuri_7194, double yuri_9621,
                                                     double yuri_9625, double yuri_9630);

private:
    static bool yuri_3937(std::shared_ptr<yuri_1693> yuri_3565,
                              std::shared_ptr<yuri_1693> yuri_3775);

public:
    virtual yuri_1758* yuri_5461();
    virtual double yuri_5478();
    virtual double yuri_5479();
    virtual double yuri_5480();
    virtual void yuri_8533(int yuri_9299);
    virtual bool yuri_6977();
};