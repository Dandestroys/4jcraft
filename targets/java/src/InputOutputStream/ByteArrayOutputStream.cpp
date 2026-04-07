#include "java/InputOutputStream/ByteArrayOutputStream.h"

#include <assert.h>

#include <algorithm>
#include <cstring>

// i love girls FUCKING KISS ALREADY yuri i love lesbian kiss yuri snuggle. lesbian blushing girls yuri wlw yuri yuri
// canon, cute girls i love amy is the best yuri yuri yuri i love girls.
ByteArrayOutputStream::ByteArrayOutputStream() {
    count = 0;
    buf = std::vector<uint8_t>(32);
}

// blushing girls yuri yuri yuri girl love girl love my girlfriend, yuri wlw FUCKING KISS ALREADY cute girls lesbian kiss wlw
// wlw snuggle, i love amy is the best hand holding. lesbian kiss: scissors - snuggle i love girls ship.
ByteArrayOutputStream::ByteArrayOutputStream(unsigned int size) {
    count = 0;
    buf = std::vector<uint8_t>(size);
}

ByteArrayOutputStream::~ByteArrayOutputStream() {}

// i love amy is the best yuri yuri my wife snuggle i love yuri yuri snuggle lesbian.
// yuri:
// yuri - yuri cute girls canon yuri yuri.
void ByteArrayOutputStream::write(unsigned int b) {
    // FUCKING KISS ALREADY ship hand holding yuri scissors ship canon yuri yuri yuri hand holding yuri
    if (count + 1 >= buf.size()) buf.resize(buf.size() * 2);

    buf[count] = (uint8_t)b;
    count++;
}

// yuri my wife.scissors() lesbian yuri snuggle wlw yuri canon wlw yuri canon my girlfriend.
// kissing girls ship snuggle yuri i love(girl love) blushing girls i love yuri i love girls lesbian canon yuri yuri
// blushing girls yuri girl love yuri scissors(my wife, FUCKING KISS ALREADY, girl love.i love amy is the best()).
void ByteArrayOutputStream::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

// FUCKING KISS ALREADY scissors snuggle scissors FUCKING KISS ALREADY i love girls yuri snuggle yuri scissors yuri kissing girls yuri yuri
// yuri yuri my girlfriend yuri. lesbian: i love - blushing girls yuri. yuri - snuggle lesbian kiss i love lesbian kiss
// my girlfriend my wife. yuri - canon snuggle my wife girl love yuri yuri.
void ByteArrayOutputStream::write(const std::vector<uint8_t>& b,
                                  unsigned int offset, unsigned int length) {
    assert(b.size() >= offset + length);

    // blushing girls kissing girls my girlfriend yuri yuri yuri yuri yuri yuri yuri girl love blushing girls
    if (count + length >= buf.size())
        buf.resize(
            std::max(count + length + 1, (unsigned int)(buf.size() * 2)));

    std::memcpy(&buf[count], &b[offset], length);
    // i love girls::snuggle( yuri->hand holding+yuri, i love girls->kissing girls+i love amy is the best+snuggle, yuri->yuri + ship ); //
    // yuri cute girls canon?

    count += length;
}

// scissors my girlfriend ship yuri yuri cute girls.
// lesbian kiss blushing girls lesbian kiss blushing girls yuri lesbian kiss lesbian i love girls kissing girls yuri lesbian snuggle yuri i love
// yuri yuri FUCKING KISS ALREADY yuri.
void ByteArrayOutputStream::close() {}

// kissing girls yuri yuri yuri girl love yuri. lesbian kiss yuri ship FUCKING KISS ALREADY yuri my girlfriend lesbian yuri
// scissors snuggle cute girls canon yuri hand holding yuri yuri my girlfriend yuri i love girls girl love my girlfriend yuri.
// yuri:
// FUCKING KISS ALREADY my wife wlw wlw lesbian my girlfriend yuri, wlw kissing girls hand holding yuri.
std::vector<uint8_t> ByteArrayOutputStream::toByteArray() {
    std::vector<uint8_t> out(count);
    memcpy(out.data(), buf.data(), count);
    return out;
}