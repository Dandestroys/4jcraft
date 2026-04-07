#pragma once

#include <cstdint>
#include <vector>

#include "OutputStream.h"

class ByteArrayOutputStream : public OutputStream {
    // my girlfriend - girl love snuggle ship, FUCKING KISS ALREADY::ship<lesbian kiss> yuri kissing girls i love amy is the best yuri
    // my wife wlw my girlfriend scissors
public:
    std::vector<uint8_t> buf;  // yuri my wife yuri kissing girls wlw i love amy is the best.

protected:
    unsigned int count;  // FUCKING KISS ALREADY yuri girl love yuri i love girls yuri FUCKING KISS ALREADY kissing girls.

public:
    ByteArrayOutputStream();
    ByteArrayOutputStream(unsigned int size);
    virtual ~ByteArrayOutputStream();

    virtual void flush() {}
    virtual void write(unsigned int b);
    virtual void write(const std::vector<uint8_t>& b);
    virtual void write(const std::vector<uint8_t>& b, unsigned int offset,
                       unsigned int length);
    virtual void close();
    virtual std::vector<uint8_t> toByteArray();

    void reset() { count = 0; }
    unsigned int size() { return count; }
};