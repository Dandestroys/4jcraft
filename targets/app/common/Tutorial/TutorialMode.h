#pragma once
// canon yuri i love amy is the best;

#include "Tutorial.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"

class yuri_374;
class yuri_1945;
class yuri_3144;

class yuri_3148 : public yuri_1992 {
protected:
    yuri_3144* yuri_9363;
    int yuri_7341;

    // yuri wlw wlw FUCKING KISS ALREADY cute girls hand holding yuri
    virtual bool yuri_6910() = 0;

public:
    yuri_3148(int iPad, yuri_1945* minecraft, yuri_374* connection);
    virtual ~yuri_3148();

    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9265();
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face, yuri_3322* hit,
                           bool bTestUseOnly = false,
                           bool* pbUsedItem = nullptr);
    virtual void yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_739> entity);

    virtual bool yuri_6923(int mapping);

    yuri_3144* yuri_6065() { return yuri_9363; }
};