#pragma once
#include "GameMode.h"

class yuri_2985 : public yuri_915 {
private:
    int xDestroyBlock;
    int yDestroyBlock;
    int zDestroyBlock;
    float destroyProgress;
    float oDestroyProgress;
    int destroyTicks;  // 4J was float but doesn't seem to need to be
    int destroyDelay;

public:
    yuri_2985(yuri_1945* minecraft);
    yuri_2985(yuri_2985* yuri_4179);
    virtual void yuri_6713(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6704();
    virtual bool yuri_3930();
    virtual bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9134();
    virtual void yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_8158(float yuri_3565);
    virtual float yuri_5692();
    virtual void yuri_6711(yuri_1758* yuri_7194);
    virtual std::shared_ptr<yuri_2126> yuri_4246(yuri_1758* yuri_7194);
    virtual void yuri_9265();
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face, bool bTestUseOnOnly = false,
                           bool* pbUsedItem = nullptr);
    virtual bool yuri_6595();
};