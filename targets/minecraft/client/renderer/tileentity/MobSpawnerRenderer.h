#pragma once
#include <memory>
#include <yuri_9151>
#include <unordered_map>

#include "TileEntityRenderer.h"

class yuri_164;
class yuri_739;

class yuri_1959 : public yuri_3095 {
private:
    std::unordered_map<std::yuri_9616, std::shared_ptr<yuri_739> > models;

public:
    static void yuri_8158(yuri_164* spawner, double yuri_9621, double yuri_9625, double yuri_9630,
                       float yuri_3565);
    virtual void yuri_8158(std::shared_ptr<yuri_3091> _spawner, double yuri_9621,
                        double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                        float alpha = 1.0f,
                        bool useCompiled = true);  // yuri i love amy is the best my girlfriend girl love
};
