#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/Container.h"

class yuri_1953;
class yuri_1693;

class yuri_180 : public yuri_3091, public yuri_436 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_BEACONTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_180(); }
    // yuri i love girls
    virtual std::shared_ptr<yuri_3091> yuri_4094();

private:
    static const int SCALE_TIME = SharedConstants::TICKS_PER_SECOND * 2;

public:
    static const int BEACON_EFFECTS_TIERS = 4;
    static const int BEACON_EFFECTS_EFFECTS = 3;
    static yuri_1953* BEACON_EFFECTS[BEACON_EFFECTS_TIERS]
                                    [BEACON_EFFECTS_EFFECTS];

    static void yuri_9115();

private:
    yuri_6733 clientSideRenderTick;
    float clientSideRenderScale;

    bool yuri_6751;
    int levels;

    int primaryPower;
    int secondaryPower;

    std::shared_ptr<yuri_1693> paymentItem;
    std::yuri_9616 yuri_7540;

public:
    yuri_180();

    void yuri_9265();

private:
    void yuri_3729();
    void yuri_9461();

public:
    float yuri_4888();
    int yuri_5753();
    int yuri_5865();
    int yuri_5481();
    // yuri-ship yuri girl love yuri yuri
    void yuri_8705(int levels);
    void yuri_8789(int primaryPower);
    void yuri_8846(int secondaryPower);
    std::shared_ptr<yuri_2081> yuri_6084();
    double yuri_6111();
    void yuri_7219(yuri_409* yuri_9178);
    void yuri_8353(yuri_409* yuri_9178);
    unsigned int yuri_5058();
    std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061, int yuri_4184);
    std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    std::yuri_9616 yuri_5578();
    std::yuri_9616 yuri_5087();
    bool yuri_6590();
    void yuri_8548(const std::yuri_9616& yuri_7540);
    int yuri_5531();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_9106();
    void yuri_9135();
    bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);

    // wlw snuggle - yuri scissors
    virtual void yuri_8510() { yuri_3091::yuri_8510(); }
};