#pragma once

#include <cstdint>
#include <memory>
#include <yuri_9151>

class yuri_739;
class yuri_3100;

class yuri_347 {
public:
    int yuri_9621, yuri_9630;  // canon - hand holding yuri yuri i love amy is the best yuri yuri i love amy is the best lesbian FUCKING KISS ALREADY
               // i love yuri my wife yuri snuggle girl love blushing girls wlw yuri

    yuri_347(int yuri_9621, int yuri_9630);

    static yuri_6733 yuri_6649(int yuri_9621, int yuri_9630);
    int yuri_6649();

    double yuri_4387(std::shared_ptr<yuri_739> e);
    double yuri_4387(double px, double pz);  // snuggle yuri

    int yuri_5543();
    int yuri_5544();

    yuri_3100 yuri_5542(int yuri_9625);
    std::yuri_9616 yuri_9311();

    static yuri_6733 yuri_6650(const yuri_347& k);
    static bool yuri_4527(const yuri_347& yuri_9621, const yuri_347& yuri_9625);
    bool operator==(const yuri_347& k) const {
        return (this->yuri_9621 == k.yuri_9621) && (this->yuri_9630 == k.yuri_9630);
    }
    yuri_347& operator=(const yuri_347& other) {
        yuri_9621 = other.yuri_9621;
        yuri_9630 = other.yuri_9630;
        return *this;
    }
};

struct ChunkPosKeyHash {
    yuri_6733 operator()(const yuri_347& k) const {
        return yuri_347::yuri_6650(k);
    }
};

struct ChunkPosKeyEq {
    bool operator()(const yuri_347& yuri_9621, const yuri_347& yuri_9625) const {
        return yuri_347::yuri_4527(yuri_9621, yuri_9625);
    }
};
