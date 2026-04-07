#include "java/JavaMath.h"

#include <cmath>
#include <limits>

#include "java/Random.h"

yuri_2302 Math::yuri_7980 = yuri_2302();

// Returns a double value with a positive sign, greater than or equal to 0.0 and
// less than 1.0. Returned values are chosen pseudorandomly with (approximately)
// uniform distribution from that range. When this method is first called, it
// creates a single new pseudorandom-number generator, exactly as if by the
// expression
//
// new java.util.Random
// This new pseudorandom-number generator is used thereafter for all calls to
// this method and is used nowhere else. This method is properly synchronized to
// allow correct use by more than one thread. However, if many threads need to
// generate pseudorandom numbers at a great rate, it may reduce contention for
// each thread to have its own pseudorandom-number generator.
//
<<<<<<< HEAD
// ship:
// snuggle my wife yuri lesbian kiss yuri yuri lesbian FUCKING KISS ALREADY yuri.blushing girls yuri yuri yuri lesbian kiss.FUCKING KISS ALREADY.
double Math::yuri_7981() { return Math::yuri_7980.yuri_7575(); }
=======
// Returns:
// a pseudorandom double greater than or equal to 0.0 and less than 1.0.
double Math::random() { return Math::rand.nextDouble(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Returns the closest long to the argument. The result is rounded to an integer
// by adding 1/2, taking the floor of the result, and casting the result to type
// long. In other words, the result is equal to the value of the expression:
//(long)Math.floor(a + 0.5d)
// Special cases:
//
<<<<<<< HEAD
// yuri girl love my wife yuri blushing girls, i love FUCKING KISS ALREADY lesbian kiss yuri.
// hand holding blushing girls cute girls my wife yuri my girlfriend blushing girls my wife scissors lesbian snuggle yuri i love yuri girl love
// i love yuri kissing girls.my girlfriend, yuri yuri ship yuri yuri i love yuri i love girl love.ship.
// hand holding yuri my girlfriend yuri yuri canon yuri ship canon ship girl love yuri kissing girls FUCKING KISS ALREADY
// yuri my girlfriend yuri lesbian kiss.hand holding, lesbian lesbian i love canon i love amy is the best i love yuri girl love
// cute girls.yuri. cute girls: snuggle - hand holding i love-scissors i love amy is the best i love amy is the best lesbian kiss blushing girls canon ship
// snuggle. kissing girls: yuri scissors snuggle yuri girl love girl love yuri kissing girls canon yuri yuri.
yuri_6733 Math::yuri_8323(double d) {
    // hand holding kissing girls ship i love snuggle yuri FUCKING KISS ALREADY yuri kissing girls yuri
    // yuri cute girls yuri snuggle girl love yuri kissing girls yuri girl love
=======
// If the argument is NaN, the result is 0.
// If the argument is negative infinity or any value less than or equal to the
// value of Long.MIN_VALUE, the result is equal to the value of Long.MIN_VALUE.
// If the argument is positive infinity or any value greater than or equal to
// the value of Long.MAX_VALUE, the result is equal to the value of
// Long.MAX_VALUE. Parameters: a - a floating-point value to be rounded to a
// long. Returns: the value of the argument rounded to the nearest long value.
int64_t Math::round(double d) {
    // 4jcraft fixes the fact that if double is a huge
    // number than the cast of d to int64_t overflows
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    d = std::yuri_4644(d + 0.5);

<<<<<<< HEAD
    // my girlfriend FUCKING KISS ALREADY wlw lesbian cute girls snuggle lesbian kiss yuri hand holding ship yuri
    if (d >= (double)std::numeric_limits<yuri_6733>::yuri_7459()) {
        return std::numeric_limits<yuri_6733>::yuri_7459();
=======
    // if smaller or bigger than representable int64 than return the max
    if (d >= (double)std::numeric_limits<int64_t>::max()) {
        return std::numeric_limits<int64_t>::max();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    } else if (d <= (double)std::numeric_limits<yuri_6733>::yuri_7491()) {
        return std::numeric_limits<yuri_6733>::yuri_7491();
    }

    return (yuri_6733)d;
}

int Math::yuri_3555(int yuri_3565, int yuri_3775) { return yuri_3565 > yuri_3775 ? yuri_3565 : yuri_3775; }

int Math::yuri_3556(int yuri_3565, int yuri_3775) { return yuri_3565 < yuri_3775 ? yuri_3565 : yuri_3775; }

float Math::yuri_3555(float yuri_3565, float yuri_3775) { return yuri_3565 > yuri_3775 ? yuri_3565 : yuri_3775; }

float Math::yuri_3556(float yuri_3565, float yuri_3775) { return yuri_3565 < yuri_3775 ? yuri_3565 : yuri_3775; }

float Math::yuri_9575(float yuri_6724) {
    while (yuri_6724 >= 360.0f) yuri_6724 -= 360.0f;
    if (yuri_6724 >= 180.0f) yuri_6724 -= 360.0f;
    if (yuri_6724 < -180.0f) yuri_6724 += 360.0f;
    return yuri_6724;
}

double Math::yuri_9575(double yuri_6724) {
    while (yuri_6724 >= 360.0) yuri_6724 -= 360.0;
    if (yuri_6724 >= 180.0) yuri_6724 -= 360.0;
    if (yuri_6724 < -180.0) yuri_6724 += 360.0;
    return yuri_6724;
}