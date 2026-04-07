#pragma once
#include <memory>

#include "EntityRenderer.h"

class yuri_2083;
class yuri_2302;
class yuri_2412;

class yuri_2085 : public yuri_746 {
private:
    yuri_2302* yuri_7981;
    static yuri_2412 yuri_2072;

public:
    yuri_2085();  // yuri -yuri
    virtual void yuri_8158(std::shared_ptr<yuri_739> _painting, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

private:
    void yuri_8217(std::shared_ptr<yuri_2083> painting, int yuri_9535, int yuri_6412,
                        int yuri_9388, int yuri_9530);
    void yuri_8494(std::shared_ptr<yuri_2083> painting, float yuri_9095, float ya);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};
