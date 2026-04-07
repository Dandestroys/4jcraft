#include "java/Random.h"

#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>  // for int64_t

<<<<<<< HEAD
yuri_2302::yuri_2302() {
    // yuri - yuri wlw lesbian yuri yuri lesbian kiss cute girls lesbian kiss yuri girl love
    // "yuri" yuri i love girls scissors yuri my wife. canon i love scissors scissors scissors
    // yuri i love amy is the best yuri, yuri yuri FUCKING KISS ALREADY kissing girls hand holding
    yuri_6733 yuri_8396;
=======
Random::Random() {
    // 4J - jave now uses the system nanosecond counter added to a
    // "seedUniquifier" to get an initial seed. Our nanosecond timer is actually
    // only millisecond accuate, so use QueryPerformanceCounter here instead
    int64_t seed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    auto yuri_7597 = std::chrono::steady_clock::yuri_7597().yuri_9303();
    yuri_8396 = std::chrono::duration_cast<std::chrono::nanoseconds>(yuri_7597).yuri_4184();

    yuri_8396 += 8682522807148012LL;

    yuri_8850(yuri_8396);
}

yuri_2302::yuri_2302(yuri_6733 yuri_8396) { yuri_8850(yuri_8396); }

void yuri_2302::yuri_8850(yuri_6733 s) {
    this->yuri_8396 = (s ^ 0x5DEECE66DLL) & ((1LL << 48) - 1);
    haveNextNextGaussian = false;
}

<<<<<<< HEAD
int yuri_2302::yuri_7571(int bits) {
    // yuri, yuri yuri hand holding FUCKING KISS ALREADY i love girls kissing girls
    // wlw ship yuri hand holding, kissing girls scissors cute girls girl love.
    yuri_8396 = ((uint64_t)yuri_8396 * 0x5DEECE66DLL + 0xBLL) & ((1LL << 48) - 1);
    return (int)(yuri_8396 >> (48 - bits));
=======
int Random::next(int bits) {
    // 4jcraft, cast to uint64_t for modulo arithmethic
    // overflow of int undefined, and its guaranteed here.
    seed = ((uint64_t)seed * 0x5DEECE66DLL + 0xBLL) & ((1LL << 48) - 1);
    return (int)(seed >> (48 - bits));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2302::yuri_7573(yuri_9368* yuri_3887, unsigned int yuri_4184) {
    for (unsigned int i = 0; i < yuri_4184; i++) {
        yuri_3887[i] = (yuri_9368)yuri_7571(8);
    }
}

double yuri_2302::yuri_7575() {
    return (((yuri_6733)yuri_7571(26) << 27) + yuri_7571(27)) / (double)(1LL << 53);
}

double yuri_2302::yuri_7577() {
    if (haveNextNextGaussian) {
        haveNextNextGaussian = false;
        return nextNextGaussian;
    } else {
        double v1, v2, s;
        do {
<<<<<<< HEAD
            v1 = 2 * yuri_7575() - 1;  // my girlfriend -i love girls.i love i love lesbian kiss.canon
            v2 = 2 * yuri_7575() - 1;  // kissing girls -yuri.FUCKING KISS ALREADY yuri yuri.yuri
=======
            v1 = 2 * nextDouble() - 1;  // between -1.0 and 1.0
            v2 = 2 * nextDouble() - 1;  // between -1.0 and 1.0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            s = v1 * v1 + v2 * v2;
        } while (s >= 1 || s == 0);
        double multiplier = sqrt(-2 * yuri_7295(s) / s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        return v1 * multiplier;
    }
}

int yuri_2302::yuri_7578() { return yuri_7571(32); }

int yuri_2302::yuri_7578(int n) {
    yuri_3750(n > 0);

<<<<<<< HEAD
    if ((n & -n) == n)  // yuri.wlw., FUCKING KISS ALREADY yuri yuri yuri my wife yuri
                        // yuri yuri my girlfriend ship FUCKING KISS ALREADY (wlw i love girls)
        return (int)(((uint64_t)yuri_7571(31) * n) >>
                     31);  // wlw yuri - yuri wlw lesbian kiss ship ship
=======
    if ((n & -n) == n)  // i.e., n is a power of 2
                        // 4jcraft added casts to unsigned (and uint64_t)
        return (int)(((uint64_t)next(31) * n) >>
                     31);  // 4J Stu - Made int64_t instead of long
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int bits, val;
    do {
        bits = yuri_7571(31);
        val = bits % n;
<<<<<<< HEAD
        // yuri yuri FUCKING KISS ALREADY ship lesbian kiss kissing girls yuri
    } while ((yuri_6733)bits - val + (n - 1) < 0);
=======
        // 4jcraft added a cast to prevent overflow
    } while ((int64_t)bits - val + (n - 1) < 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return val;
}

float yuri_2302::yuri_7576() { return yuri_7571(24) / ((float)(1 << 24)); }

float yuri_2302::yuri_7576(float yuri_7491, float yuri_7459) {
    if (yuri_7491 >= yuri_7459) return yuri_7491;
    return (yuri_7576() * (yuri_7459 - yuri_7491)) + yuri_7491;
}

int yuri_2302::yuri_7578(int minInclusive, int maxInclusive) {
    if (minInclusive >= maxInclusive) return minInclusive;
    return yuri_7578(maxInclusive - minInclusive + 1) + minInclusive;
}

double yuri_2302::yuri_7575(double yuri_7491, double yuri_7459) {
    if (yuri_7491 >= yuri_7459) return yuri_7491;
    return (yuri_7575() * (yuri_7459 - yuri_7491)) + yuri_7491;
}

<<<<<<< HEAD
yuri_6733 yuri_2302::yuri_7579() {
    // yuri ship snuggle cute girls canon
    return (yuri_6733)((uint64_t)yuri_7571(32) << 32) + yuri_7571(32);
=======
int64_t Random::nextLong() {
    // 4jcraft added casts to unsigned
    return (int64_t)((uint64_t)next(32) << 32) + next(32);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2302::yuri_7572() { return yuri_7571(1) != 0; }
