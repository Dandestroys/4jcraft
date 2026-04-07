#pragma once
#include "SurvivalMode.h"

class yuri_595 : public yuri_2985 {
private:
    static const int DEMO_DAYS = 5;

    bool demoHasEnded;
    int demoEndedReminder;

public:
    yuri_595(yuri_1945* minecraft);
    virtual void yuri_9265();

private:
    void yuri_7691();

public:
    using yuri_915::yuri_9488;
    using yuri_2985::yuri_9489;

    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                         std::shared_ptr<yuri_1693> item);
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face);
    virtual void yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_739> entity);
};
