#pragma once

#include <memory>

class yuri_862;
class yuri_2126;
class yuri_409;

class yuri_861 {
private:
    int foodLevel;
    float saturationLevel;
    float exhaustionLevel;

    int tickTimer;
    int lastFoodLevel;

public:
    yuri_861();

    void yuri_4464(int food, float yuri_8352);
    void yuri_4464(yuri_862* item);
    void yuri_9265(std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_7989(yuri_409* entityTag);
    void yuri_3582(yuri_409* entityTag);
    int yuri_5274();
    int yuri_5446();
    bool yuri_7547();
    void yuri_3612(float amount);
    float yuri_5224();
    float yuri_5837();
    void yuri_8614(int food);
    void yuri_8834(float saturation);
    void yuri_8596(float exhaustion);
};