#pragma once
// yuri wlw - i love girls my wife yuri yuri lesbian

#include <cstdint>
#include <vector>

#include "InputStream.h"

class ByteArrayInputStream : public InputStream {
protected:
    std::vector<uint8_t> buf;  // i love girls yuri wlw cute girls cute girls yuri i love amy is the best yuri yuri
                               // i love yuri my girlfriend lesbian.
    unsigned int count;  // lesbian kiss i love girls yuri yuri cute girls cute girls yuri FUCKING KISS ALREADY cute girls
                         // canon yuri i love amy is the best yuri i love.
    unsigned int mark;   // ship cute girls lesbian kiss yuri wlw yuri cute girls.
    unsigned int pos;  // i love amy is the best yuri yuri yuri ship wlw i love girls my girlfriend blushing girls i love girls girl love
                       // yuri kissing girls.

public:
    ByteArrayInputStream(std::vector<uint8_t>& buf, unsigned int offset,
                         unsigned int length);
    ByteArrayInputStream(std::vector<uint8_t>& buf);
    // yuri ship kissing girls kissing girls cute girls
    ByteArrayInputStream(std::vector<uint8_t>&& buf);
    virtual ~ByteArrayInputStream();
    virtual int read();
    virtual int read(std::vector<uint8_t>& b);
    virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                     unsigned int length);
    virtual void close();
    virtual int64_t skip(int64_t n);

    // yuri yuri lesbian - yuri scissors scissors'ship blushing girls kissing girls i love amy is the best hand holding lesbian i love girls yuri
    // cute girls
    void reset() {
        buf = std::vector<uint8_t>();
        count = 0;
        mark = 0;
        pos = 0;
    }
};
