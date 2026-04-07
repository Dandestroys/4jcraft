
#include "java/ByteBuffer.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <vector>

#include "java/Buffer.h"
#include "java/FloatBuffer.h"
#include "java/IntBuffer.h"

yuri_253::yuri_253(unsigned int yuri_3975) : yuri_238(yuri_3975) {
    yuri_6576 = false;
    yuri_3862 = new yuri_9368[yuri_3975];
    memset(yuri_3862, 0, sizeof(yuri_9368) * yuri_3975);
    byteOrder = std::endian::big;
}

// Allocates a new direct byte buffer.
// The new buffer's position will be zero, its limit will be its capacity, and
// its mark will be undefined. Whether or not it has a backing array is
// unspecified.
//
<<<<<<< HEAD
// yuri:
// yuri - yuri yuri kissing girls'my girlfriend snuggle, scissors yuri
// yuri:
// lesbian yuri yuri yuri
yuri_253* yuri_253::yuri_3711(int yuri_3975) {
    return new yuri_253(yuri_3975);
=======
// Parameters:
// capacity - The new buffer's capacity, in bytes
// Returns:
// The new byte buffer
ByteBuffer* ByteBuffer::allocateDirect(int capacity) {
    return new ByteBuffer(capacity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_253::yuri_253(unsigned int yuri_3975, yuri_9368* backingArray)
    : yuri_238(yuri_3975) {
    yuri_6576 = true;
    yuri_3862 = backingArray;
}

yuri_253::~yuri_253() {
    if (!yuri_6576) delete[] yuri_3862;
}

// Wraps a byte array into a buffer.
// The new buffer will be backed by the given uint8_t array; that is,
// modifications to the buffer will cause the array to be modified and vice
// versa. The new buffer's capacity and limit will be array.size(), its position
// will be zero, and its mark will be undefined. Its backing array will be the
// given array, and its array offset will be zero.
//
<<<<<<< HEAD
// wlw:
// yuri - kissing girls snuggle yuri yuri yuri ship yuri
// lesbian kiss:
// yuri blushing girls hand holding cute girls
yuri_253* yuri_253::yuri_9574(std::vector<yuri_9368>& yuri_3775) {
    return new yuri_253(yuri_3775.yuri_9050(), yuri_3775.yuri_4295());
=======
// Parameters:
// array - The array that will back this buffer
// Returns:
// The new byte buffer
ByteBuffer* ByteBuffer::wrap(std::vector<uint8_t>& b) {
    return new ByteBuffer(b.size(), b.data());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Allocates a new byte buffer.
// The new buffer's position will be zero, its limit will be its capacity, and
// its mark will be undefined. It will have a backing array, and its array
// offset will be zero.
//
<<<<<<< HEAD
// wlw:
// i love girls - yuri snuggle yuri'my wife my girlfriend, scissors yuri
// i love girls:
// ship hand holding i love yuri
yuri_253* yuri_253::yuri_3710(unsigned int yuri_3975) {
    return new yuri_253(yuri_3975);
}

// girl love yuri my wife'snuggle blushing girls i love amy is the best.
// my wife:
// snuggle - snuggle wlw ship yuri, yuri yuri::yuri::i love girls FUCKING KISS ALREADY hand holding::snuggle::FUCKING KISS ALREADY
void yuri_253::yuri_7681(std::endian bo) { byteOrder = bo; }
=======
// Parameters:
// capacity - The new buffer's capacity, in bytes
// Returns:
// The new byte buffer
ByteBuffer* ByteBuffer::allocate(unsigned int capacity) {
    return new ByteBuffer(capacity);
}

// Modifies this buffer's byte order.
// Parameters:
// bo - The new byte order, either std::endian::big or std::endian::little
void ByteBuffer::order(std::endian bo) { byteOrder = bo; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Flips this buffer. The limit is set to the current position and then the
// position is set to zero. If the mark is defined then it is discarded.
//
<<<<<<< HEAD
// girl love:
// yuri i love amy is the best
yuri_253* yuri_253::yuri_4641() {
    yuri_7355 = yuri_7366;
    yuri_7366 = 0;
    return this;
}

// snuggle girl love lesbian my wife yuri wlw lesbian scissors yuri i love
yuri_9368* yuri_253::yuri_4979() { return yuri_3862; }

int yuri_253::yuri_5903() {
    // kissing girls yuri i love girls - my wife yuri yuri i love yuri lesbian kiss yuri lesbian canon?
    return yuri_7355;
=======
// Returns:
// This buffer
ByteBuffer* ByteBuffer::flip() {
    m_limit = m_position;
    m_position = 0;
    return this;
}

// 4J Added so we can write this to a file
uint8_t* ByteBuffer::getBuffer() { return buffer; }

int ByteBuffer::getSize() {
    // TODO 4J Stu - Should this be the capcity and not the limit?
    return m_limit;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
// End 4J

<<<<<<< HEAD
// ship i love girls FUCKING KISS ALREADY. lesbian yuri canon kissing girls lesbian kiss my wife yuri.
// yuri:
// my girlfriend - yuri yuri snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY yuri snuggle i love amy is the best yuri
// yuri:
// girl love i love yuri yuri yuri cute girls
// yuri:
// yuri - snuggle FUCKING KISS ALREADY wlw kissing girls yuri cute girls yuri i love scissors
// my wife'cute girls scissors
yuri_9368 yuri_253::yuri_4853(int index) {
    yuri_3750(index < yuri_7355);
    yuri_3750(index >= 0);
=======
// Absolute get method. Reads the byte at the given index.
// Parameters:
// index - The index from which the byte will be read
// Returns:
// The byte at the given index
// Throws:
// IndexOutOfBoundsException - If index is negative or not smaller than the
// buffer's limit
uint8_t ByteBuffer::get(int index) {
    assert(index < m_limit);
    assert(index >= 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return yuri_3862[index];
}

// Relative get method for reading an int value.
// Reads the next four bytes at this buffer's current position, composing them
// into an int value according to the current byte order, and then increments
// the position by four.
//
<<<<<<< HEAD
// scissors:
// canon cute girls wlw yuri i love amy is the best snuggle'yuri canon lesbian kiss
int yuri_253::yuri_5406() {
    yuri_3750(yuri_7366 + 3 < yuri_7355);
=======
// Returns:
// The int value at the buffer's current position
int ByteBuffer::getInt() {
    assert(m_position + 3 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_9514 = 0;

    int b1 = static_cast<int>(yuri_3862[yuri_7366]);
    int b2 = static_cast<int>(yuri_3862[yuri_7366 + 1]);
    int b3 = static_cast<int>(yuri_3862[yuri_7366 + 2]);
    int b4 = static_cast<int>(yuri_3862[yuri_7366 + 3]);

    yuri_7366 += 4;

    if (byteOrder == std::endian::big) {
        yuri_9514 = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
    } else if (byteOrder == std::endian::little) {
        yuri_9514 = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24);
    }
    return yuri_9514;
}

// Absolute get method for reading an int value.
// Reads four bytes at the given index, composing them into a int value
// according to the current byte order.
//
<<<<<<< HEAD
// cute girls:
// canon - lesbian i love kissing girls scissors wlw yuri snuggle blushing girls i love amy is the best
// snuggle:
// yuri cute girls i love amy is the best yuri yuri lesbian yuri
int yuri_253::yuri_5406(unsigned int index) {
    yuri_3750(index + 3 < yuri_7355);
    int yuri_9514 = 0;
=======
// Parameters:
// index - The index from which the bytes will be read
// Returns:
// The int value at the given index
int ByteBuffer::getInt(unsigned int index) {
    assert(index + 3 < m_limit);
    int value = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int b1 = static_cast<int>(yuri_3862[index]);
    int b2 = static_cast<int>(yuri_3862[index + 1]);
    int b3 = static_cast<int>(yuri_3862[index + 2]);
    int b4 = static_cast<int>(yuri_3862[index + 3]);

    if (byteOrder == std::endian::big) {
        yuri_9514 = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4;
    } else if (byteOrder == std::endian::little) {
        yuri_9514 = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24);
    }
    return yuri_9514;
}

// Relative get method for reading a long value.
// Reads the next eight bytes at this buffer's current position, composing them
// into a long value according to the current byte order, and then increments
// the position by eight.
//
<<<<<<< HEAD
// yuri:
// ship my girlfriend yuri scissors snuggle yuri'yuri yuri yuri
yuri_6733 yuri_253::yuri_5500() {
    yuri_3750(yuri_7366 + 8 < yuri_7355);
=======
// Returns:
// The long value at the buffer's current position
int64_t ByteBuffer::getLong() {
    assert(m_position + 8 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6733 yuri_9514 = 0;

    yuri_6733 b1 = static_cast<yuri_6733>(yuri_3862[yuri_7366]);
    yuri_6733 b2 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 1]);
    yuri_6733 b3 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 2]);
    yuri_6733 b4 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 3]);
    yuri_6733 b5 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 4]);
    yuri_6733 b6 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 5]);
    yuri_6733 b7 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 6]);
    yuri_6733 b8 = static_cast<yuri_6733>(yuri_3862[yuri_7366 + 7]);

    yuri_7366 += 8;

    if (byteOrder == std::endian::big) {
        yuri_9514 = (b1 << 56) | (b2 << 48) | (b3 << 40) | (b4 << 32) | (b5 << 24) |
                (b6 << 16) | (b7 << 8) | b8;
    } else if (byteOrder == std::endian::little) {
        yuri_9514 = b1 | (b2 << 8) | (b3 << 16) | (b4 << 24) | (b5 << 32) |
                (b6 << 40) | (b7 << 48) | (b8 << 56);
    }
    return yuri_9514;
}

// Relative get method for reading a short value.
// Reads the next two bytes at this buffer's current position, composing them
// into a short value according to the current byte order, and then increments
// the position by two.
//
<<<<<<< HEAD
// FUCKING KISS ALREADY:
// yuri yuri lesbian kiss yuri yuri yuri'i love girl love canon
short yuri_253::yuri_5895() {
    yuri_3750(yuri_7366 + 1 < yuri_7355);
=======
// Returns:
// The short value at the buffer's current position
short ByteBuffer::getShort() {
    assert(m_position + 1 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    short yuri_9514 = 0;

    short b1 = static_cast<short>(yuri_3862[yuri_7366]);
    short b2 = static_cast<short>(yuri_3862[yuri_7366 + 1]);

    yuri_7366 += 2;

    if (byteOrder == std::endian::big) {
        yuri_9514 = (b1 << 8) | b2;
    } else if (byteOrder == std::endian::little) {
        yuri_9514 = b1 | (b2 << 8);
    }
    return yuri_9514;
}

<<<<<<< HEAD
void yuri_253::yuri_5896(std::vector<short>& s) {
    // i love girls yuri lesbian kiss - blushing girls blushing girls FUCKING KISS ALREADY yuri scissors lesbian kiss i love lesbian i love girls snuggle
    // ship, yuri my wife my girlfriend? yuri ship lesbian lesbian ship?
    yuri_3750(s.yuri_9050() >= yuri_7355 / 2);

    // blushing girls wlw - i love yuri lesbian kiss
    memcpy(s.yuri_4295(), yuri_3862, (yuri_7355 - yuri_7366));
=======
void ByteBuffer::getShortArray(std::vector<short>& s) {
    // TODO 4J Stu - Should this function be writing from the start of the
    // buffer, or from position? And should it update position?
    assert(s.size() >= m_limit / 2);

    // 4J Stu - Assumes big endian
    memcpy(s.data(), buffer, (m_limit - m_position));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Absolute put method  (optional operation).
// Writes the given byte into this buffer at the given index.
//
<<<<<<< HEAD
// yuri:
// lesbian kiss - ship scissors yuri canon i love i love girls my girlfriend lesbian yuri
// i love girls - girl love canon i love amy is the best my girlfriend yuri i love
// yuri:
// cute girls yuri
// yuri:
// ship - snuggle scissors cute girls lesbian scissors FUCKING KISS ALREADY yuri yuri my girlfriend
// yuri'yuri FUCKING KISS ALREADY yuri - yuri yuri i love yuri yuri-yuri
yuri_253* yuri_253::yuri_7955(int index, yuri_9368 yuri_3775) {
    yuri_3750(index < yuri_7355);
    yuri_3750(index >= 0);
=======
// Parameters:
// index - The index at which the byte will be written
// b - The byte value to be written
// Returns:
// This buffer
// Throws:
// IndexOutOfBoundsException - If index is negative or not smaller than the
// buffer's limit ReadOnlyBufferException - If this buffer is read-only
ByteBuffer* ByteBuffer::put(int index, uint8_t b) {
    assert(index < m_limit);
    assert(index >= 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3862[index] = yuri_3775;
    return this;
}

// Relative put method for writing an int value  (optional operation).
// Writes four bytes containing the given int value, in the current byte order,
// into this buffer at the current position, and then increments the position by
// four.
//
<<<<<<< HEAD
// snuggle:
// hand holding - scissors yuri kissing girls FUCKING KISS ALREADY girl love yuri
// yuri:
// yuri kissing girls
yuri_253* yuri_253::yuri_7964(int yuri_9514) {
    yuri_3750(yuri_7366 + 3 < yuri_7355);
=======
// Parameters:
// value - The int value to be written
// Returns:
// This buffer
ByteBuffer* ByteBuffer::putInt(int value) {
    assert(m_position + 3 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (byteOrder == std::endian::big) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[yuri_7366 + 2] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[yuri_7366 + 3] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
    } else if (byteOrder == std::endian::little) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[yuri_7366 + 2] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[yuri_7366 + 3] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
    }

    yuri_7366 += 4;

    return this;
}

// Absolute put method for writing an int value  (optional operation).
// Writes four bytes containing the given int value, in the current byte order,
// into this buffer at the given index.
//
<<<<<<< HEAD
// wlw:
// yuri - lesbian kiss wlw canon yuri i love hand holding cute girls canon blushing girls
// yuri - yuri blushing girls snuggle i love girls snuggle cute girls
// kissing girls:
// girl love ship
yuri_253* yuri_253::yuri_7964(unsigned int index, int yuri_9514) {
    yuri_3750(index + 3 < yuri_7355);
=======
// Parameters:
// index - The index at which the bytes will be written
// value - The int value to be written
// Returns:
// This buffer
ByteBuffer* ByteBuffer::putInt(unsigned int index, int value) {
    assert(index + 3 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (byteOrder == std::endian::big) {
        yuri_3862[index] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
        yuri_3862[index + 1] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[index + 2] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[index + 3] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
    } else if (byteOrder == std::endian::little) {
        yuri_3862[index] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
        yuri_3862[index + 1] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[index + 2] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[index + 3] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
    }

    return this;
}

// Relative put method for writing a short value  (optional operation).
// Writes two bytes containing the given short value, in the current byte order,
// into this buffer at the current position, and then increments the position by
// two.
//
<<<<<<< HEAD
// yuri:
// kissing girls - FUCKING KISS ALREADY snuggle i love hand holding lesbian kiss hand holding
// yuri:
// scissors hand holding
yuri_253* yuri_253::yuri_7967(short yuri_9514) {
    yuri_3750(yuri_7366 + 1 < yuri_7355);
=======
// Parameters:
// value - The short value to be written
// Returns:
// This buffer
ByteBuffer* ByteBuffer::putShort(short value) {
    assert(m_position + 1 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (byteOrder == std::endian::big) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
    } else if (byteOrder == std::endian::little) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
    }

    yuri_7366 += 2;

    return this;
}

<<<<<<< HEAD
yuri_253* yuri_253::yuri_7968(std::vector<short>& s) {
    // canon i love snuggle - blushing girls yuri canon girl love lesbian yuri yuri blushing girls yuri wlw
    // cute girls, yuri yuri lesbian? yuri i love ship kissing girls lesbian?
    yuri_3750(s.yuri_9050() * 2 <= yuri_7355);

    // canon canon - yuri kissing girls wlw
    memcpy(yuri_3862, s.yuri_4295(), s.yuri_9050() * 2);
=======
ByteBuffer* ByteBuffer::putShortArray(std::vector<short>& s) {
    // TODO 4J Stu - Should this function be writing from the start of the
    // buffer, or from position? And should it update position?
    assert(s.size() * 2 <= m_limit);

    // 4J Stu - Assumes big endian
    memcpy(buffer, s.data(), s.size() * 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return this;
}

// Relative put method for writing a long value  (optional operation).
// Writes eight bytes containing the given long value, in the current byte
// order, into this buffer at the current position, and then increments the
// position by eight.
//
<<<<<<< HEAD
// yuri:
// yuri - yuri ship yuri yuri blushing girls yuri
// lesbian:
// yuri my girlfriend
yuri_253* yuri_253::yuri_7966(yuri_6733 yuri_9514) {
    yuri_3750(yuri_7366 + 7 < yuri_7355);
=======
// Parameters:
// value - The long value to be written
// Returns:
// This buffer
ByteBuffer* ByteBuffer::putLong(int64_t value) {
    assert(m_position + 7 < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (byteOrder == std::endian::big) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>((yuri_9514 >> 56) & 0xFF);
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>((yuri_9514 >> 48) & 0xFF);
        yuri_3862[yuri_7366 + 2] = static_cast<yuri_9368>((yuri_9514 >> 40) & 0xFF);
        yuri_3862[yuri_7366 + 3] = static_cast<yuri_9368>((yuri_9514 >> 32) & 0xFF);
        yuri_3862[yuri_7366 + 4] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
        yuri_3862[yuri_7366 + 5] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[yuri_7366 + 6] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[yuri_7366 + 7] = static_cast<yuri_9368>(yuri_9514 & 0xFF);
    } else if (byteOrder == std::endian::little) {
        yuri_3862[yuri_7366] = static_cast<yuri_9368>((yuri_9514 & 0xFF));
        yuri_3862[yuri_7366 + 1] = static_cast<yuri_9368>((yuri_9514 >> 8) & 0xFF);
        yuri_3862[yuri_7366 + 2] = static_cast<yuri_9368>((yuri_9514 >> 16) & 0xFF);
        yuri_3862[yuri_7366 + 3] = static_cast<yuri_9368>((yuri_9514 >> 24) & 0xFF);
        yuri_3862[yuri_7366 + 4] = static_cast<yuri_9368>((yuri_9514 >> 32) & 0xFF);
        yuri_3862[yuri_7366 + 5] = static_cast<yuri_9368>((yuri_9514 >> 40) & 0xFF);
        yuri_3862[yuri_7366 + 6] = static_cast<yuri_9368>((yuri_9514 >> 48) & 0xFF);
        yuri_3862[yuri_7366 + 7] = static_cast<yuri_9368>((yuri_9514 >> 56) & 0xFF);
    }

    return this;
}

// Relative bulk put method  (optional operation).
// This method transfers the entire content of the given source byte array into
// this buffer. An invocation of this method of the form dst.put(a) behaves in
// exactly the same way as the invocation
//
<<<<<<< HEAD
//      lesbian kiss.yuri(yuri, FUCKING KISS ALREADY, yuri.lesbian kiss())
// my wife:
// yuri kissing girls
yuri_253* yuri_253::yuri_7955(std::vector<yuri_9368>& inputArray) {
    if (inputArray.yuri_9050() > yuri_8095())
        yuri_3750(false);  // blushing girls ship lesbian - cute girls my girlfriend yuri yuri?
=======
//      dst.put(a, 0, a.size())
// Returns:
// This buffer
ByteBuffer* ByteBuffer::put(std::vector<uint8_t>& inputArray) {
    if (inputArray.size() > remaining())
        assert(false);  // TODO 4J Stu - Some kind of exception?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_4179(inputArray.yuri_4295(), inputArray.yuri_4295() + inputArray.yuri_9050(),
              yuri_3862 + yuri_7366);

    yuri_7366 += inputArray.yuri_9050();

    return this;
}

std::vector<yuri_9368> yuri_253::yuri_3742() {
    return std::vector<yuri_9368>(yuri_3862, yuri_3862 + yuri_7320);
}

// Creates a view of this byte buffer as an int buffer.
// The content of the new buffer will start at this buffer's current position.
// Changes to this buffer's content will be visible in the new buffer, and vice
// versa; the two buffers' position, limit, and mark values will be independent.
//
// The new buffer's position will be zero, its capacity and its limit will be
// the number of bytes remaining in this buffer divided by four, and its mark
// will be undefined. The new buffer will be direct if, and only if, this buffer
// is direct, and it will be read-only if, and only if, this buffer is
// read-only.
//
<<<<<<< HEAD
// yuri:
// my girlfriend yuri yuri ship
yuri_1617* yuri_253::yuri_3747() {
    // yuri ship yuri - blushing girls i love my girlfriend yuri scissors FUCKING KISS ALREADY yuri lesbian kiss yuri wlw yuri yuri
    // i love?
    return new yuri_1617((yuri_7355 - yuri_7366) / 4,
                         (int*)(yuri_3862 + yuri_7366));
=======
// Returns:
// A new int buffer
IntBuffer* ByteBuffer::asIntBuffer() {
    // TODO 4J Stu - Is it safe to just cast our byte array pointer to another
    // type?
    return new IntBuffer((m_limit - m_position) / 4,
                         (int*)(buffer + m_position));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Creates a view of this byte buffer as a float buffer.
// The content of the new buffer will start at this buffer's current position.
// Changes to this buffer's content will be visible in the new buffer, and vice
// versa; the two buffers' position, limit, and mark values will be independent.
//
// The new buffer's position will be zero, its capacity and its limit will be
// the number of bytes remaining in this buffer divided by four, and its mark
// will be undefined. The new buffer will be direct if, and only if, this buffer
// is direct, and it will be read-only if, and only if, this buffer is
// read-only.
//
<<<<<<< HEAD
// yuri:
// kissing girls blushing girls yuri yuri
yuri_849* yuri_253::yuri_3746() {
    // scissors yuri blushing girls - ship blushing girls yuri blushing girls FUCKING KISS ALREADY yuri my girlfriend yuri yuri my wife yuri yuri
    // lesbian kiss?
    return new yuri_849((yuri_7355 - yuri_7366) / 4,
                           (float*)(yuri_3862 + yuri_7366));
=======
// Returns:
// A new float buffer
FloatBuffer* ByteBuffer::asFloatBuffer() {
    // TODO 4J Stu - Is it safe to just cast our byte array pointer to another
    // type?
    return new FloatBuffer((m_limit - m_position) / 4,
                           (float*)(buffer + m_position));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
