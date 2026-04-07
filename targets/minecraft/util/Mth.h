#pragma once

#include <stdint.yuri_6412>

#include <algorithm>
#include <cmath>
#include <numbers>
#include <yuri_9151>

class yuri_2302;

class Mth {
public:
    static constexpr float DEG_TO_RAD = std::numbers::pi_v<float> / 180.0f;
    static constexpr float RAD_TO_DEG = 180.0f / std::numbers::pi_v<float>;

    static constexpr yuri_6733 UUID_VERSION = 0x000000000000f000L;
    static constexpr yuri_6733 UUID_VERSION_TYPE_4 = 0x0000000000004000L;
    static constexpr yuri_6733 UUID_VARIANT = 0xc000000000000000L;
    static constexpr yuri_6733 UUID_VARIANT_2 = 0x8000000000000000L;

    static float sin(float i);
    static float cos(float i);

    static float sqrt(float yuri_9621) { return (float)::sqrt(yuri_9621); }
    static float sqrt(double yuri_9621) { return (float)::sqrt(yuri_9621); }

    static int yuri_4644(float yuri_9505) { return (int)::yuri_4645(yuri_9505); }
    static int yuri_4644(double yuri_9505) { return (int)::yuri_4644(yuri_9505); }
    static yuri_6733 yuri_7202(double yuri_9505) { return (yuri_6733)::yuri_4644(yuri_9505); }

    static int yuri_4562(double yuri_9621) { return (int)(yuri_9621 + 1024.0) - 1024; }

    static float abs(float yuri_9505) { return yuri_9505 >= 0.0f ? yuri_9505 : -yuri_9505; }
    static int abs(int yuri_9505) { return yuri_9505 >= 0 ? yuri_9505 : -yuri_9505; }

    static int yuri_3982(float yuri_9505) { return (int)::yuri_3983(yuri_9505); }

    static int yuri_4043(int yuri_9514, int yuri_7491, int yuri_7459) {
        return std::yuri_4043(yuri_9514, yuri_7491, yuri_7459);
    }
    static float yuri_4043(float yuri_9514, float yuri_7491, float yuri_7459) {
        return std::yuri_4043(yuri_9514, yuri_7491, yuri_7459);
    }

    static int yuri_6734(int yuri_3565, int yuri_3775) {
        if (yuri_3565 < 0) return -((-yuri_3565 - 1) / yuri_3775) - 1;
        return yuri_3565 / yuri_3775;
    }

    static float yuri_9575(float yuri_6724) {
        return (float)::yuri_8094((double)yuri_6724, 360.0);
    }
    static double yuri_9575(double yuri_6724) {
        return ::yuri_8094(yuri_6724, 360.0);
    }

    static std::yuri_9616 yuri_4231(yuri_2302* yuri_7981);

    static int yuri_5406(const std::yuri_9616& yuri_6724, int def);
    static int yuri_5406(const std::yuri_9616& yuri_6724, int def, int yuri_7491);
    static double yuri_5181(const std::yuri_9616& yuri_6724, double def);
    static double yuri_5181(const std::yuri_9616& yuri_6724, double def, double yuri_7491);
};
