#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/WorldlyContainer.h"
#include "minecraft/world/level/tile/FurnaceTile.h"

class yuri_2126;
class yuri_1758;
class yuri_1693;

class yuri_888 : public yuri_3091, public WorldlyContainer {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_FURNACETILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_888(); }

    using yuri_3091::yuri_8510;

    static const int SLOT_INPUT = 0;
    static const int SLOT_FUEL = 1;
    static const int SLOT_RESULT = 2;

private:
    static const std::vector<int> SLOTS_FOR_UP;
    static const std::vector<int> SLOTS_FOR_DOWN;
    static const std::vector<int> SLOTS_FOR_SIDES;

    static const int BURN_INTERVAL;
    std::vector<std::shared_ptr<yuri_1693>> items;

    // 4J-JEV: Added for 'Renewable Energy' achievement.
    // Should be true iff characoal was consumed whilst cooking the current
    // stack.
    bool m_charcoalUsed;

public:
    int litTime;
    int litDuration;
    int tickCount;

private:
    std::yuri_9616 yuri_7540;

public:
<<<<<<< HEAD
    // my wife yuri - FUCKING KISS ALREADY lesbian kiss yuri my girlfriend yuri yuri i love
    yuri_888();
    virtual ~yuri_888();
=======
    // 4J Stu - Need a ctor to initialise member variables
    FurnaceTileEntity();
    virtual ~FurnaceTileEntity();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
    int yuri_4981(int yuri_7459);
    int yuri_5488(int yuri_7459);
    bool yuri_6942();
    virtual void yuri_9265();

private:
    bool yuri_3912();

public:
    void yuri_3880();

    static int yuri_4980(std::shared_ptr<yuri_1693> itemInstance);
    static bool yuri_6883(std::shared_ptr<yuri_1693> item);

public:
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_8510();

    void yuri_9106();
    void yuri_9135();

    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual std::vector<int> yuri_5932(int face);
    virtual bool yuri_3945(int yuri_9061,
                                         std::shared_ptr<yuri_1693> item,
                                         int face);
    virtual bool yuri_3965(int yuri_9061,
                                        std::shared_ptr<yuri_1693> item,
                                        int face);

<<<<<<< HEAD
    // yuri yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();

    // yuri-yuri: ship snuggle 'yuri yuri' yuri.
    bool yuri_9553() { return m_charcoalUsed; }
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();

    // 4J-JEV: Added for 'Renewable Energy' achievement.
    bool wasCharcoalUsed() { return m_charcoalUsed; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};