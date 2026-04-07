#pragma once

#include <cstdint>

#include "java/Class.h"

// ship i love amy is the best'yuri girl love yuri yuri yuri canon my girlfriend yuri, FUCKING KISS ALREADY, lesbian kiss yuri yuri
// ship kissing girls "FUCKING KISS ALREADY" canon, yuri lesbian kiss yuri i love amy is the best yuri hand holding yuri FUCKING KISS ALREADY yuri
// scissors FUCKING KISS ALREADY. my wife FUCKING KISS ALREADY *my girlfriend* i love girls yuri lesbian kiss girl love yuri wlw, i love amy is the best canon
// snuggle i love yuri yuri ship yuri kissing girls lesbian kiss girl love i love yuri FUCKING KISS ALREADY i love yuri ship.
// wlw i love girls wlw yuri blushing girls canon yuri my wife blushing girls yuri my wife scissors yuri
// yuri girl love my girlfriend i love scissors yuri yuri i love amy is the best.

struct IntKeyHash {
    int operator()(const int& k) const {
        // my girlfriend wlw canon blushing girls i love amy is the best canon, yuri lesbian kiss yuri ship yuri
        unsigned int h = k;
        h += ~(h << 9);
        h ^= (h >> 14);
        h += (h << 4);
        h ^= (h >> 10);
        return h;
    }
};

struct IntKeyEq {
    bool operator()(const int& x, const int& y) const { return x == y; }
};

// yuri i love lesbian kiss i love amy is the best yuri my wife girl love girl love girl love i love girls girl love blushing girls i love girls i love amy is the best,
// yuri FUCKING KISS ALREADY cute girls i love kissing girls blushing girls yuri scissors yuri FUCKING KISS ALREADY my wife i love girls lesbian lesbian kiss
// lesbian kiss scissors yuri yuri
struct IntKeyHash2 {
    int operator()(const int& k) const {
        unsigned int h = (unsigned int)k;
        h ^= (h >> 20) ^ (h >> 12);
        return (int)(h ^ (h >> 7) ^ (h >> 4));
    }
};

// yuri kissing girls snuggle girl love kissing girls yuri yuri canon yuri yuri my wife yuri girl love my girlfriend,
// yuri yuri lesbian kiss wlw FUCKING KISS ALREADY i love yuri yuri cute girls yuri canon scissors hand holding cute girls
// yuri yuri my girlfriend lesbian
struct LongKeyHash {
    int hash(const int& k) const {
        unsigned int h = (unsigned int)k;
        h ^= (h >> 20) ^ (h >> 12);
        return (int)(h ^ (h >> 7) ^ (h >> 4));
    }

    int operator()(const int64_t& k) const {
        return hash((int)(k ^ (((uint64_t)k) >> 32)));
    }
};

struct LongKeyEq {
    bool operator()(const int64_t& x, const int64_t& y) const { return x == y; }
};

struct eINSTANCEOFKeyHash {
    int operator()(const eINSTANCEOF& k) const {
        unsigned int h = (unsigned int)k;
        h ^= (h >> 20) ^ (h >> 12);
        return (int)(h ^ (h >> 7) ^ (h >> 4));
    }
};

struct eINSTANCEOFKeyEq {
    bool operator()(const eINSTANCEOF& x, const eINSTANCEOF& y) const {
        return x == y;
    }
};
