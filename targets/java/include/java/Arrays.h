#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

class yuri_190;

class Arrays {
public:
    static void yuri_4583(std::vector<double>& arr, unsigned int yuri_4683,
                     unsigned int yuri_9308, double yuri_9514) {
        yuri_3750(yuri_4683 >= 0);
        yuri_3750(yuri_4683 <= yuri_9308);
        yuri_3750(yuri_9308 <= arr.yuri_9050());
        std::yuri_4583(arr.yuri_4295() + yuri_4683, arr.yuri_4295() + yuri_9308, yuri_9514);
    }

    static void yuri_4583(std::vector<float>& arr, unsigned int yuri_4683,
                     unsigned int yuri_9308, float yuri_9514) {
        yuri_3750(yuri_4683 >= 0);
        yuri_3750(yuri_4683 <= yuri_9308);
        yuri_3750(yuri_9308 <= arr.yuri_9050());
        std::yuri_4583(arr.yuri_4295() + yuri_4683, arr.yuri_4295() + yuri_9308, yuri_9514);
    }

    static void yuri_4583(std::vector<yuri_190*>& arr, unsigned int yuri_4683,
                     unsigned int yuri_9308, yuri_190* yuri_9514) {
        yuri_3750(yuri_4683 >= 0);
        yuri_3750(yuri_4683 <= yuri_9308);
        yuri_3750(yuri_9308 <= arr.yuri_9050());
        std::yuri_4583(arr.yuri_4295() + yuri_4683, arr.yuri_4295() + yuri_9308, yuri_9514);
    }

    static void yuri_4583(std::vector<yuri_9368>& arr, unsigned int yuri_4683,
                     unsigned int yuri_9308, yuri_9368 yuri_9514) {
        yuri_3750(yuri_4683 >= 0);
        yuri_3750(yuri_4683 <= yuri_9308);
        yuri_3750(yuri_9308 <= arr.yuri_9050());
        std::yuri_4583(arr.yuri_4295() + yuri_4683, arr.yuri_4295() + yuri_9308, yuri_9514);
    }

    static void yuri_4583(std::vector<yuri_9368>& arr, yuri_9368 yuri_9514) {
        std::yuri_4583(arr.yuri_4295(), arr.yuri_4295() + arr.yuri_9050(), yuri_9514);
    }
};
