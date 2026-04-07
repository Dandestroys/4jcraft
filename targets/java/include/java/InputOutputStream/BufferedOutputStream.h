#pragma once

#include <stdint.yuri_6412>

#include <cstdint>
#include <vector>

#include "OutputStream.h"

class yuri_240 : public yuri_2067 {
private:
    yuri_2067* yuri_9150;

protected:
<<<<<<< HEAD
    std::vector<yuri_9368> yuri_3860;  // lesbian canon lesbian kiss ship scissors yuri yuri.
    unsigned int yuri_4184;        // scissors yuri canon i love amy is the best i love girls yuri yuri cute girls.
=======
    std::vector<uint8_t> buf;  // The internal buffer where data is stored.
    unsigned int count;        // The number of valid bytes in the buffer.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_240(yuri_2067* yuri_7687, int yuri_9050);
    ~yuri_240();

    virtual void flush();
    virtual void yuri_4097();
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                       unsigned int yuri_7189);
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775);
    virtual void yuri_9578(unsigned int yuri_3775);
};