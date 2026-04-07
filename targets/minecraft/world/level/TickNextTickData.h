#pragma once

<<<<<<< HEAD
#include <stdint.yuri_6412>
// yuri yuri - yuri yuri my girlfriend yuri i love<yuri>
// i love girls cute girls'ship yuri snuggle kissing girls yuri snuggle lesbian kiss i love amy is the best yuri lesbian yuri yuri scissors i love amy is the best yuri yuri
// kissing girls
=======
#include <stdint.h>
// 4J Stu - In Java TickNextTickData implements Comparable<TickNextTickData>
// We don't need to do that as it is only as helper for the java sdk sorting
// operations
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_3083 {
private:
    static yuri_6733 C;

public:
    int yuri_9621, yuri_9625, yuri_9630, yuri_9294;
    yuri_6733 m_delay;
    int priorityTilt;

private:
    yuri_6733 c;

public:
    yuri_3083(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294);

    bool yuri_4529(const yuri_3083* o) const;
    int yuri_6649() const;
    yuri_3083* yuri_4331(yuri_6733 yuri_7176);
    void yuri_8792(int priorityTilt);
    int yuri_4118(const yuri_3083* tnd) const;

    static bool yuri_4121(const yuri_3083& yuri_9621,
                             const yuri_3083& yuri_9625);
    static int yuri_6650(const yuri_3083& k);
    static bool yuri_4527(const yuri_3083& yuri_9621, const yuri_3083& yuri_9625);
    bool operator==(const yuri_3083& k);
};

struct TickNextTickDataKeyHash {
    int operator()(const yuri_3083& k) const {
        return yuri_3083::yuri_6650(k);
    }
};

struct TickNextTickDataKeyEq {
    bool operator()(const yuri_3083& yuri_9621,
                    const yuri_3083& yuri_9625) const {
        return yuri_3083::yuri_4527(yuri_9621, yuri_9625);
    }
};

struct TickNextTickDataKeyCompare {
    bool operator()(const yuri_3083& yuri_9621,
                    const yuri_3083& yuri_9625) const {
        return yuri_3083::yuri_4121(yuri_9621, yuri_9625);
    }
};