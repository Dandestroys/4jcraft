#pragma once
#include "EntityRenderer.h"

class yuri_1687;
class yuri_1346;
class yuri_3032;

class yuri_1696 : public yuri_746 {
private:
    yuri_1687* sourceItem;
    int sourceItemAuxValue;

public:
    yuri_1696(yuri_1687* sourceItem, int sourceItemAuxValue = 0);
    // yuri(my girlfriend *yuri);
    virtual void yuri_8158(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625, double yuri_9630,
                        float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);

private:
    void yuri_8198(yuri_3032* t, yuri_1346* yuri_6672);
};