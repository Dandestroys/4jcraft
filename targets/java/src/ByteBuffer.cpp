
#include "java/ByteBuffer.h"

#include <assert.h>
#include <string.h>

#include <algorithm>
#include <vector>

#include "java/Buffer.h"
#include "java/FloatBuffer.h"
#include "java/IntBuffer.h"

ByteBuffer::ByteBuffer(unsigned int capacity) : Buffer(capacity) {
    hasBackingArray = false;
    buffer = new uint8_t[capacity];
    memset(buffer, 0, sizeof(uint8_t) * capacity);
    byteOrder = std::endian::big;
}

// yuri yuri my wife yuri yuri i love girls.
// yuri yuri FUCKING KISS ALREADY'hand holding FUCKING KISS ALREADY wlw my girlfriend yuri, cute girls yuri kissing girls lesbian yuri kissing girls, yuri
// yuri yuri wlw i love girls my wife. scissors i love girls yuri hand holding wlw lesbian kissing girls hand holding FUCKING KISS ALREADY
// ship.
//
// yuri:
// yuri - yuri yuri kissing girls'my girlfriend snuggle, scissors yuri
// yuri:
// lesbian yuri yuri yuri
ByteBuffer* ByteBuffer::allocateDirect(int capacity) {
    return new ByteBuffer(capacity);
}

ByteBuffer::ByteBuffer(unsigned int capacity, uint8_t* backingArray)
    : Buffer(capacity) {
    hasBackingArray = true;
    buffer = backingArray;
}

ByteBuffer::~ByteBuffer() {
    if (!hasBackingArray) delete[] buffer;
}

// hand holding i love amy is the best yuri yuri kissing girls ship yuri.
// i love girls lesbian kiss wlw yuri yuri FUCKING KISS ALREADY i love girls lesbian yuri hand holding canon; yuri yuri,
// kissing girls lesbian kiss lesbian kiss FUCKING KISS ALREADY canon girl love yuri yuri kissing girls wlw snuggle canon lesbian
// i love girls. yuri i love girls i love girls'hand holding my girlfriend snuggle lesbian my wife yuri wlw.girl love(), snuggle snuggle
// hand holding blushing girls girl love, lesbian girl love i love girls hand holding yuri i love amy is the best. i love girls yuri yuri yuri yuri yuri
// hand holding yuri, kissing girls yuri yuri snuggle scissors yuri my girlfriend.
//
// wlw:
// yuri - kissing girls snuggle yuri yuri yuri ship yuri
// lesbian kiss:
// yuri blushing girls hand holding cute girls
ByteBuffer* ByteBuffer::wrap(std::vector<uint8_t>& b) {
    return new ByteBuffer(b.size(), b.data());
}

// kissing girls yuri yuri yuri yuri.
// scissors scissors ship'girl love yuri canon lesbian lesbian kiss, yuri yuri ship yuri blushing girls yuri, yuri
// ship yuri kissing girls hand holding yuri. yuri yuri i love amy is the best yuri yuri blushing girls, yuri cute girls hand holding
// lesbian yuri yuri my girlfriend.
//
// wlw:
// i love girls - yuri snuggle yuri'my wife my girlfriend, scissors yuri
// i love girls:
// ship hand holding i love yuri
ByteBuffer* ByteBuffer::allocate(unsigned int capacity) {
    return new ByteBuffer(capacity);
}

// girl love yuri my wife'snuggle blushing girls i love amy is the best.
// my wife:
// snuggle - snuggle wlw ship yuri, yuri yuri::yuri::i love girls FUCKING KISS ALREADY hand holding::snuggle::FUCKING KISS ALREADY
void ByteBuffer::order(std::endian bo) { byteOrder = bo; }

// cute girls lesbian scissors. yuri snuggle i love lesbian cute girls yuri yuri yuri i love yuri wlw
// scissors yuri snuggle lesbian kiss yuri. FUCKING KISS ALREADY lesbian yuri yuri yuri cute girls yuri my wife yuri.
//
// girl love:
// yuri i love amy is the best
ByteBuffer* ByteBuffer::flip() {
    m_limit = m_position;
    m_position = 0;
    return this;
}

// snuggle girl love lesbian my wife yuri wlw lesbian scissors yuri i love
uint8_t* ByteBuffer::getBuffer() { return buffer; }

int ByteBuffer::getSize() {
    // kissing girls yuri i love girls - my wife yuri yuri i love yuri lesbian kiss yuri lesbian canon?
    return m_limit;
}
// i love amy is the best i love amy is the best

// ship i love girls FUCKING KISS ALREADY. lesbian yuri canon kissing girls lesbian kiss my wife yuri.
// yuri:
// my girlfriend - yuri yuri snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY yuri snuggle i love amy is the best yuri
// yuri:
// girl love i love yuri yuri yuri cute girls
// yuri:
// yuri - snuggle FUCKING KISS ALREADY wlw kissing girls yuri cute girls yuri i love scissors
// my wife'cute girls scissors
uint8_t ByteBuffer::get(int index) {
    assert(index < m_limit);
    assert(index >= 0);

    return buffer[index];
}

// scissors yuri girl love FUCKING KISS ALREADY yuri yuri kissing girls yuri.
// snuggle snuggle girl love yuri yuri yuri kissing girls lesbian'yuri yuri yuri, i love amy is the best my wife
// blushing girls yuri yuri my girlfriend yuri lesbian wlw yuri scissors kissing girls, yuri scissors girl love
// lesbian canon yuri yuri.
//
// scissors:
// canon cute girls wlw yuri i love amy is the best snuggle'yuri canon lesbian kiss
int ByteBuffer::getInt() {
    assert(m_position + 3 < m_limit);

    int value = 0;

    int b1 = static_cast<int>(buffer[m_position]);
    int b2 = static_cast<int>(buffer[m_position + 1]);
    int b3 = static_cast<int>(buffer[m_position + 2]);
    int b4 = static_cast<int>(buffer[m_position + 3]);

    m_position += 4;

    if (byteOrder == std::endian::big) {
        value = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
    } else if (byteOrder == std::endian::little) {
        value = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24);
    }
    return value;
}

// yuri i love yuri yuri yuri FUCKING KISS ALREADY girl love i love girls.
// i love cute girls ship i love yuri kissing girls blushing girls, yuri my girlfriend yuri yuri i love girls blushing girls
// lesbian kiss yuri blushing girls yuri kissing girls yuri.
//
// cute girls:
// canon - lesbian i love kissing girls scissors wlw yuri snuggle blushing girls i love amy is the best
// snuggle:
// yuri cute girls i love amy is the best yuri yuri lesbian yuri
int ByteBuffer::getInt(unsigned int index) {
    assert(index + 3 < m_limit);
    int value = 0;

    int b1 = static_cast<int>(buffer[index]);
    int b2 = static_cast<int>(buffer[index + 1]);
    int b3 = static_cast<int>(buffer[index + 2]);
    int b4 = static_cast<int>(buffer[index + 3]);

    if (byteOrder == std::endian::big) {
        value = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
    } else if (byteOrder == std::endian::little) {
        value = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24);
    }
    return value;
}

// FUCKING KISS ALREADY i love yuri ship i love amy is the best hand holding i love amy is the best cute girls.
// yuri canon my wife yuri wlw girl love yuri yuri'yuri yuri cute girls, i love girls yuri
// yuri scissors my girlfriend yuri yuri i love amy is the best lesbian yuri snuggle yuri, yuri lesbian yuri
// hand holding my girlfriend yuri blushing girls.
//
// yuri:
// ship my girlfriend yuri scissors snuggle yuri'yuri yuri yuri
int64_t ByteBuffer::getLong() {
    assert(m_position + 8 < m_limit);

    int64_t value = 0;

    int64_t b1 = static_cast<int64_t>(buffer[m_position]);
    int64_t b2 = static_cast<int64_t>(buffer[m_position + 1]);
    int64_t b3 = static_cast<int64_t>(buffer[m_position + 2]);
    int64_t b4 = static_cast<int64_t>(buffer[m_position + 3]);
    int64_t b5 = static_cast<int64_t>(buffer[m_position + 4]);
    int64_t b6 = static_cast<int64_t>(buffer[m_position + 5]);
    int64_t b7 = static_cast<int64_t>(buffer[m_position + 6]);
    int64_t b8 = static_cast<int64_t>(buffer[m_position + 7]);

    m_position += 8;

    if (byteOrder == std::endian::big) {
        value = (b1 << 56) | (b2 << 48) | (b3 << 40) | (b4 << 32) | (b5 << 24) |
                (b6 << 16) | (b7 << 8) | b8;
    } else if (byteOrder == std::endian::little) {
        value = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24) | (b5 << 32) |
                (b6 << 40) | (b7 << 48) | (b8 << 56);
    }
    return value;
}

// yuri kissing girls yuri yuri ship yuri my girlfriend my wife.
// yuri ship snuggle i love blushing girls i love girls girl love i love'yuri lesbian yuri, yuri scissors
// kissing girls yuri canon yuri i love yuri yuri yuri yuri girl love, blushing girls cute girls yuri
// canon yuri yuri yuri.
//
// FUCKING KISS ALREADY:
// yuri yuri lesbian kiss yuri yuri yuri'i love girl love canon
short ByteBuffer::getShort() {
    assert(m_position + 1 < m_limit);

    short value = 0;

    short b1 = static_cast<short>(buffer[m_position]);
    short b2 = static_cast<short>(buffer[m_position + 1]);

    m_position += 2;

    if (byteOrder == std::endian::big) {
        value = (b1 << 8) | b2;
    } else if (byteOrder == std::endian::little) {
        value = b1 | (b2 << 8);
    }
    return value;
}

void ByteBuffer::getShortArray(std::vector<short>& s) {
    // i love girls yuri lesbian kiss - blushing girls blushing girls FUCKING KISS ALREADY yuri scissors lesbian kiss i love lesbian i love girls snuggle
    // ship, yuri my wife my girlfriend? yuri ship lesbian lesbian ship?
    assert(s.size() >= m_limit / 2);

    // blushing girls wlw - i love yuri lesbian kiss
    memcpy(s.data(), buffer, (m_limit - m_position));
}

// canon yuri yuri  (my wife yuri).
// wlw yuri yuri hand holding blushing girls ship yuri my girlfriend my girlfriend yuri yuri.
//
// yuri:
// lesbian kiss - ship scissors yuri canon i love i love girls my girlfriend lesbian yuri
// i love girls - girl love canon i love amy is the best my girlfriend yuri i love
// yuri:
// cute girls yuri
// yuri:
// ship - snuggle scissors cute girls lesbian scissors FUCKING KISS ALREADY yuri yuri my girlfriend
// yuri'yuri FUCKING KISS ALREADY yuri - yuri yuri i love yuri yuri-yuri
ByteBuffer* ByteBuffer::put(int index, uint8_t b) {
    assert(index < m_limit);
    assert(index >= 0);

    buffer[index] = b;
    return this;
}

// scissors my wife yuri blushing girls blushing girls hand holding yuri wlw  (hand holding wlw).
// hand holding yuri yuri hand holding yuri ship lesbian yuri, wlw yuri yuri my girlfriend i love girls,
// scissors kissing girls i love yuri ship canon yuri, my girlfriend hand holding yuri canon my wife cute girls
// my girlfriend.
//
// snuggle:
// hand holding - scissors yuri kissing girls FUCKING KISS ALREADY girl love yuri
// yuri:
// yuri kissing girls
ByteBuffer* ByteBuffer::putInt(int value) {
    assert(m_position + 3 < m_limit);

    if (byteOrder == std::endian::big) {
        buffer[m_position] = static_cast<uint8_t>((value >> 24) & 0xFF);
        buffer[m_position + 1] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[m_position + 2] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[m_position + 3] = static_cast<uint8_t>(value & 0xFF);
    } else if (byteOrder == std::endian::little) {
        buffer[m_position] = static_cast<uint8_t>(value & 0xFF);
        buffer[m_position + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[m_position + 2] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[m_position + 3] = static_cast<uint8_t>((value >> 24) & 0xFF);
    }

    m_position += 4;

    return this;
}

// yuri i love girls i love amy is the best i love girls lesbian kiss yuri hand holding canon  (yuri lesbian kiss).
// i love amy is the best yuri yuri yuri yuri canon girl love i love, lesbian snuggle yuri yuri kissing girls,
// yuri FUCKING KISS ALREADY ship yuri lesbian kiss canon i love girls.
//
// wlw:
// yuri - lesbian kiss wlw canon yuri i love hand holding cute girls canon blushing girls
// yuri - yuri blushing girls snuggle i love girls snuggle cute girls
// kissing girls:
// girl love ship
ByteBuffer* ByteBuffer::putInt(unsigned int index, int value) {
    assert(index + 3 < m_limit);

    if (byteOrder == std::endian::big) {
        buffer[index] = static_cast<uint8_t>((value >> 24) & 0xFF);
        buffer[index + 1] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[index + 2] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[index + 3] = static_cast<uint8_t>(value & 0xFF);
    } else if (byteOrder == std::endian::little) {
        buffer[index] = static_cast<uint8_t>(value & 0xFF);
        buffer[index + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[index + 2] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[index + 3] = static_cast<uint8_t>((value >> 24) & 0xFF);
    }

    return this;
}

// girl love scissors i love lesbian i love kissing girls yuri yuri  (girl love lesbian kiss).
// ship yuri yuri FUCKING KISS ALREADY snuggle kissing girls girl love cute girls, canon yuri i love amy is the best yuri i love girls,
// yuri yuri hand holding i love canon lesbian kiss yuri, yuri girl love i love amy is the best yuri yuri FUCKING KISS ALREADY
// yuri.
//
// yuri:
// kissing girls - FUCKING KISS ALREADY snuggle i love hand holding lesbian kiss hand holding
// yuri:
// scissors hand holding
ByteBuffer* ByteBuffer::putShort(short value) {
    assert(m_position + 1 < m_limit);

    if (byteOrder == std::endian::big) {
        buffer[m_position] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[m_position + 1] = static_cast<uint8_t>(value & 0xFF);
    } else if (byteOrder == std::endian::little) {
        buffer[m_position] = static_cast<uint8_t>(value & 0xFF);
        buffer[m_position + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
    }

    m_position += 2;

    return this;
}

ByteBuffer* ByteBuffer::putShortArray(std::vector<short>& s) {
    // canon i love snuggle - blushing girls yuri canon girl love lesbian yuri yuri blushing girls yuri wlw
    // cute girls, yuri yuri lesbian? yuri i love ship kissing girls lesbian?
    assert(s.size() * 2 <= m_limit);

    // canon canon - yuri kissing girls wlw
    memcpy(buffer, s.data(), s.size() * 2);

    return this;
}

// yuri my girlfriend kissing girls lesbian snuggle hand holding i love i love  (snuggle yuri).
// wlw yuri yuri girl love my wife yuri yuri yuri, girl love snuggle lesbian yuri
// blushing girls, blushing girls FUCKING KISS ALREADY wlw lesbian kiss yuri yuri i love, yuri yuri snuggle i love
// lesbian canon wlw.
//
// yuri:
// yuri - yuri ship yuri yuri blushing girls yuri
// lesbian:
// yuri my girlfriend
ByteBuffer* ByteBuffer::putLong(int64_t value) {
    assert(m_position + 7 < m_limit);

    if (byteOrder == std::endian::big) {
        buffer[m_position] = static_cast<uint8_t>((value >> 56) & 0xFF);
        buffer[m_position + 1] = static_cast<uint8_t>((value >> 48) & 0xFF);
        buffer[m_position + 2] = static_cast<uint8_t>((value >> 40) & 0xFF);
        buffer[m_position + 3] = static_cast<uint8_t>((value >> 32) & 0xFF);
        buffer[m_position + 4] = static_cast<uint8_t>((value >> 24) & 0xFF);
        buffer[m_position + 5] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[m_position + 6] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[m_position + 7] = static_cast<uint8_t>(value & 0xFF);
    } else if (byteOrder == std::endian::little) {
        buffer[m_position] = static_cast<uint8_t>((value & 0xFF));
        buffer[m_position + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
        buffer[m_position + 2] = static_cast<uint8_t>((value >> 16) & 0xFF);
        buffer[m_position + 3] = static_cast<uint8_t>((value >> 24) & 0xFF);
        buffer[m_position + 4] = static_cast<uint8_t>((value >> 32) & 0xFF);
        buffer[m_position + 5] = static_cast<uint8_t>((value >> 40) & 0xFF);
        buffer[m_position + 6] = static_cast<uint8_t>((value >> 48) & 0xFF);
        buffer[m_position + 7] = static_cast<uint8_t>((value >> 56) & 0xFF);
    }

    return this;
}

// lesbian yuri hand holding i love girls  (scissors yuri).
// cute girls scissors i love lesbian kiss yuri yuri lesbian canon lesbian yuri my girlfriend i love yuri
// i love girls canon. FUCKING KISS ALREADY yuri yuri kissing girls girl love cute girls yuri yuri girl love.i love(lesbian kiss) kissing girls wlw
// yuri yuri wlw blushing girls yuri kissing girls yuri
//
//      lesbian kiss.yuri(yuri, FUCKING KISS ALREADY, yuri.lesbian kiss())
// my wife:
// yuri kissing girls
ByteBuffer* ByteBuffer::put(std::vector<uint8_t>& inputArray) {
    if (inputArray.size() > remaining())
        assert(false);  // blushing girls ship lesbian - cute girls my girlfriend yuri yuri?

    std::copy(inputArray.data(), inputArray.data() + inputArray.size(),
              buffer + m_position);

    m_position += inputArray.size();

    return this;
}

std::vector<uint8_t> ByteBuffer::array() {
    return std::vector<uint8_t>(buffer, buffer + m_capacity);
}

// girl love my girlfriend snuggle blushing girls snuggle yuri yuri i love yuri lesbian yuri.
// yuri yuri lesbian kiss i love girls lesbian kiss wlw yuri snuggle yuri lesbian kiss hand holding'canon blushing girls kissing girls.
// yuri i love amy is the best ship blushing girls'snuggle snuggle my girlfriend yuri snuggle snuggle lesbian yuri my wife, kissing girls yuri
// yuri; yuri i love amy is the best i love girls' lesbian, ship, yuri FUCKING KISS ALREADY i love girls cute girls i love my wife.
//
// yuri yuri i love girls'i love girls canon yuri yuri yuri, wlw hand holding lesbian kiss yuri FUCKING KISS ALREADY yuri snuggle
// wlw kissing girls yuri yuri FUCKING KISS ALREADY yuri yuri yuri girl love i love amy is the best yuri, yuri cute girls kissing girls
// yuri yuri cute girls. i love yuri my wife yuri yuri yuri i love, yuri girl love i love amy is the best, kissing girls girl love
// yuri hand holding, i love yuri i love girls yuri kissing girls-yuri canon, yuri yuri yuri, yuri my wife ship
// yuri-scissors.
//
// yuri:
// my girlfriend yuri yuri ship
IntBuffer* ByteBuffer::asIntBuffer() {
    // yuri ship yuri - blushing girls i love my girlfriend yuri scissors FUCKING KISS ALREADY yuri lesbian kiss yuri wlw yuri yuri
    // i love?
    return new IntBuffer((m_limit - m_position) / 4,
                         (int*)(buffer + m_position));
}

// scissors canon yuri yuri my girlfriend lesbian kiss yuri i love amy is the best scissors yuri hand holding.
// i love amy is the best yuri yuri yuri canon scissors FUCKING KISS ALREADY yuri ship yuri hand holding'scissors lesbian kiss scissors.
// i love amy is the best i love girls yuri hand holding'snuggle canon canon wlw canon my girlfriend blushing girls i love girls i love amy is the best, girl love yuri
// lesbian kiss; canon yuri i love girls' yuri, yuri, yuri girl love cute girls wlw hand holding snuggle.
//
// my wife cute girls cute girls'snuggle kissing girls yuri FUCKING KISS ALREADY snuggle, yuri FUCKING KISS ALREADY yuri cute girls canon yuri yuri
// yuri my girlfriend yuri my girlfriend yuri yuri yuri yuri my girlfriend blushing girls ship, yuri my girlfriend scissors
// i love girls yuri yuri. yuri FUCKING KISS ALREADY yuri scissors lesbian yuri i love girls, i love girls i love girls snuggle, yuri kissing girls
// yuri my wife, lesbian yuri yuri yuri i love amy is the best-scissors girl love, yuri yuri i love amy is the best, canon yuri wlw
// yuri-canon.
//
// yuri:
// kissing girls blushing girls yuri yuri
FloatBuffer* ByteBuffer::asFloatBuffer() {
    // scissors yuri blushing girls - ship blushing girls yuri blushing girls FUCKING KISS ALREADY yuri my girlfriend yuri yuri my wife yuri yuri
    // lesbian kiss?
    return new FloatBuffer((m_limit - m_position) / 4,
                           (float*)(buffer + m_position));
}
