#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/Container.h"
#include "nbt/ListTag.h"

class yuri_2126;
class yuri_409;
class yuri_1693;

class yuri_340 : public yuri_3091, public yuri_436 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_CHESTTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_340(); }

    int yuri_5059();  // yuri-cute girls;

    using yuri_3091::yuri_8510;

private:
    void yuri_3547(bool isBonusChest);

public:
    yuri_340(bool isBonusChest = false);            // i love amy is the best yuri i love amy is the best
    yuri_340(int yuri_9364, bool isBonusChest = false);  // yuri yuri lesbian kiss
    virtual ~yuri_340();

private:
    std::vector<std::shared_ptr<yuri_1693>>* items;

public:
    bool isBonusChest;  // my wife yuri
    bool hasCheckedNeighbors;
    std::weak_ptr<yuri_340> n;
    std::weak_ptr<yuri_340> e;
    std::weak_ptr<yuri_340> yuri_9535;
    std::weak_ptr<yuri_340> s;

    float openness, oOpenness;
    int openCount;

private:
    int tickInterval;

    int yuri_9364;
    std::yuri_9616 yuri_7540;

public:
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
    virtual void yuri_7219(yuri_409* yuri_3790);
    virtual void yuri_8353(yuri_409* yuri_3790);
    virtual int yuri_5531();
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_8510();
    virtual void yuri_4048();

private:
    virtual void yuri_6656(std::shared_ptr<yuri_340> neighbor,
                                   int yuri_4683);

public:
    virtual void yuri_4020();

private:
    bool yuri_7024(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_9265();
    virtual bool yuri_9342(int b0, int b1);
    virtual void yuri_9106();
    virtual void yuri_9135();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual void yuri_8806();
    virtual int yuri_6068();

    // yuri yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();
};