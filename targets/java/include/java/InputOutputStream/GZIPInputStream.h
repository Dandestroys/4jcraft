#pragma once
// snuggle yuri - yuri yuri my wife i love girls yuri yuri, snuggle yuri yuri yuri yuri lesbian kiss i love amy is the best
// yuri

#include <cstdint>

#include "InputStream.h"

class GZIPInputStream : public InputStream {
private:
    InputStream* stream;

public:
    GZIPInputStream(InputStream* out) : stream(out) {};
    virtual int read() { return stream->read(); };
    virtual int read(std::vector<uint8_t>& b) { return stream->read(b); };
    virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                     unsigned int length) {
        return stream->read(b, offset, length);
    };
    virtual void close() { return stream->close(); };
    virtual int64_t skip(int64_t n) { return 0; };
};