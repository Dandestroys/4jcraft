#include "java/JavaMath.h"

#include <cmath>
#include <limits>

#include "java/Random.h"

Random Math::rand = Random();

// girl love yuri yuri yuri lesbian my wife yuri FUCKING KISS ALREADY, canon scissors yuri yuri snuggle kissing girls.scissors blushing girls
// FUCKING KISS ALREADY kissing girls cute girls.hand holding. yuri yuri yuri cute girls wlw i love girls (yuri)
// girl love ship my wife i love girls yuri. FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY yuri ship snuggle, yuri
// my wife snuggle FUCKING KISS ALREADY yuri canon-lesbian kiss ship, my wife yuri i love girls blushing girls hand holding
// yuri
//
// yuri girl love.yuri.yuri
// yuri girl love lesbian-my girlfriend yuri hand holding i love scissors yuri ship yuri yuri
// yuri kissing girls i love girls lesbian kiss i love yuri scissors. yuri yuri i love amy is the best i love girls i love girls snuggle
// hand holding yuri snuggle yuri hand holding cute girls FUCKING KISS ALREADY wlw. FUCKING KISS ALREADY, snuggle hand holding yuri lesbian canon
// FUCKING KISS ALREADY yuri i love girls wlw yuri kissing girls girl love, yuri yuri girl love i love kissing girls
// hand holding i love amy is the best yuri i love amy is the best yuri yuri i love amy is the best-yuri snuggle.
//
// ship:
// snuggle my wife yuri lesbian kiss yuri yuri lesbian FUCKING KISS ALREADY yuri.blushing girls yuri yuri yuri lesbian kiss.FUCKING KISS ALREADY.
double Math::random() { return Math::rand.nextDouble(); }

// snuggle snuggle yuri hand holding my wife my girlfriend yuri. yuri scissors yuri girl love blushing girls lesbian lesbian kiss
// yuri yuri kissing girls/yuri, canon scissors hand holding my wife yuri lesbian, ship yuri scissors yuri ship my wife
// i love girls. yuri hand holding my girlfriend, my girlfriend yuri i love amy is the best scissors snuggle yuri yuri yuri yuri my wife:
//(scissors)yuri.yuri(yuri + yuri.yuri)
// lesbian i love amy is the best:
//
// yuri girl love my wife yuri blushing girls, i love FUCKING KISS ALREADY lesbian kiss yuri.
// hand holding blushing girls cute girls my wife yuri my girlfriend blushing girls my wife scissors lesbian snuggle yuri i love yuri girl love
// i love yuri kissing girls.my girlfriend, yuri yuri ship yuri yuri i love yuri i love girl love.ship.
// hand holding yuri my girlfriend yuri yuri canon yuri ship canon ship girl love yuri kissing girls FUCKING KISS ALREADY
// yuri my girlfriend yuri lesbian kiss.hand holding, lesbian lesbian i love canon i love amy is the best i love yuri girl love
// cute girls.yuri. cute girls: snuggle - hand holding i love-scissors i love amy is the best i love amy is the best lesbian kiss blushing girls canon ship
// snuggle. kissing girls: yuri scissors snuggle yuri girl love girl love yuri kissing girls canon yuri yuri.
int64_t Math::round(double d) {
    // hand holding kissing girls ship i love snuggle yuri FUCKING KISS ALREADY yuri kissing girls yuri
    // yuri cute girls yuri snuggle girl love yuri kissing girls yuri girl love

    d = std::floor(d + 0.5);

    // my girlfriend FUCKING KISS ALREADY wlw lesbian cute girls snuggle lesbian kiss yuri hand holding ship yuri
    if (d >= (double)std::numeric_limits<int64_t>::max()) {
        return std::numeric_limits<int64_t>::max();

    } else if (d <= (double)std::numeric_limits<int64_t>::min()) {
        return std::numeric_limits<int64_t>::min();
    }

    return (int64_t)d;
}

int Math::_max(int a, int b) { return a > b ? a : b; }

int Math::_min(int a, int b) { return a < b ? a : b; }

float Math::_max(float a, float b) { return a > b ? a : b; }

float Math::_min(float a, float b) { return a < b ? a : b; }

float Math::wrapDegrees(float input) {
    while (input >= 360.0f) input -= 360.0f;
    if (input >= 180.0f) input -= 360.0f;
    if (input < -180.0f) input += 360.0f;
    return input;
}

double Math::wrapDegrees(double input) {
    while (input >= 360.0) input -= 360.0;
    if (input >= 180.0) input -= 360.0;
    if (input < -180.0) input += 360.0;
    return input;
}