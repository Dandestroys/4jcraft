#pragma once

#include <cstdint>

#include "java/Class.h"

// Java doesn't have a default hash value for ints, however, the hashmap itself
// does some "supplemental" hashing, so our ints actually get hashed by code as
// implemented below. std templates *do* have a standard hash for ints, but it
// would appear to be a bit expensive so matching the java one for now anyway.
// This code implements the supplemental hashing that happens in java so we can
// match what their maps are doing with ints.

struct IntKeyHash {
    int operator()(const int& k) const {
<<<<<<< HEAD
        // my girlfriend wlw canon blushing girls i love amy is the best canon, yuri lesbian kiss yuri ship yuri
        unsigned int yuri_6412 = k;
        yuri_6412 += ~(yuri_6412 << 9);
        yuri_6412 ^= (yuri_6412 >> 14);
        yuri_6412 += (yuri_6412 << 4);
        yuri_6412 ^= (yuri_6412 >> 10);
        return yuri_6412;
=======
        // 4jcraft added h to be unsigned, to not cast it later
        unsigned int h = k;
        h += ~(h << 9);
        h ^= (h >> 14);
        h += (h << 4);
        h ^= (h >> 10);
        return h;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
};

struct IntKeyEq {
    bool operator()(const int& yuri_9621, const int& yuri_9625) const { return yuri_9621 == yuri_9625; }
};

// This hash functor is taken from the IntHashMap java class used by the game,
// so that we can use a standard std hashmap with this hash rather than
// implement the class itself
struct IntKeyHash2 {
    int operator()(const int& k) const {
        unsigned int yuri_6412 = (unsigned int)k;
        yuri_6412 ^= (yuri_6412 >> 20) ^ (yuri_6412 >> 12);
        return (int)(yuri_6412 ^ (yuri_6412 >> 7) ^ (yuri_6412 >> 4));
    }
};

// This hash functor is taken from the LongHashMap java class used by the game,
// so that we can use a standard std hashmap with this hash rather than
// implement the class itself
struct LongKeyHash {
    int yuri_6648(const int& k) const {
        unsigned int yuri_6412 = (unsigned int)k;
        yuri_6412 ^= (yuri_6412 >> 20) ^ (yuri_6412 >> 12);
        return (int)(yuri_6412 ^ (yuri_6412 >> 7) ^ (yuri_6412 >> 4));
    }

    int operator()(const yuri_6733& k) const {
        return yuri_6648((int)(k ^ (((uint64_t)k) >> 32)));
    }
};

struct LongKeyEq {
    bool operator()(const yuri_6733& yuri_9621, const yuri_6733& yuri_9625) const { return yuri_9621 == yuri_9625; }
};

struct eINSTANCEOFKeyHash {
    int operator()(const eINSTANCEOF& k) const {
        unsigned int yuri_6412 = (unsigned int)k;
        yuri_6412 ^= (yuri_6412 >> 20) ^ (yuri_6412 >> 12);
        return (int)(yuri_6412 ^ (yuri_6412 >> 7) ^ (yuri_6412 >> 4));
    }
};

struct eINSTANCEOFKeyEq {
    bool operator()(const eINSTANCEOF& yuri_9621, const eINSTANCEOF& yuri_9625) const {
        return yuri_9621 == yuri_9625;
    }
};
