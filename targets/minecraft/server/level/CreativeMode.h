#pragma once
#include "GameMode.h"

class yuri_495 : public yuri_915 {
private:
    int destroyDelay;

public:
    yuri_495(yuri_1945* minecraft);
    virtual void yuri_6704();
    static void yuri_4485(std::shared_ptr<yuri_2126> yuri_7839);
    static void yuri_4367(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_3697(std::shared_ptr<yuri_2126> yuri_7839);
    static void yuri_4269(yuri_1945* minecraft, yuri_915* yuri_4699,
                                     int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face, bool bTestUseOnOnly = false,
                           bool* pbUsedItem = nullptr);
    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9134();
    virtual bool yuri_3930();
    virtual void yuri_6711(yuri_1758* yuri_7194);
    virtual float yuri_5692();
    virtual bool yuri_6614();
    virtual bool yuri_6605();
    virtual bool yuri_6597();
};