#include "java/IntBuffer.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>

#include "java/Buffer.h"

// Allocates a new int buffer.
// The new buffer's position will be zero, its limit will be its capacity, and
// its mark will be undefined. It will have a backing array, and its array
// offset will be zero.
//
<<<<<<< HEAD
// ship:
// girl love - yuri yuri canon'FUCKING KISS ALREADY yuri, kissing girls lesbian kiss
yuri_1617::yuri_1617(unsigned int yuri_3975) : yuri_238(yuri_3975) {
    yuri_3862 = new int[yuri_3975];
    memset(yuri_3862, 0, sizeof(int) * yuri_3975);
=======
// Parameters:
// capacity - The new buffer's capacity, in ints
IntBuffer::IntBuffer(unsigned int capacity) : Buffer(capacity) {
    buffer = new int[capacity];
    memset(buffer, 0, sizeof(int) * capacity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1617::yuri_1617(unsigned int yuri_3975, int* backingArray)
    : yuri_238(yuri_3975) {
    yuri_6576 = true;
    yuri_3862 = backingArray;
}

yuri_1617::~yuri_1617() {
    if (!yuri_6576) delete[] yuri_3862;
}

int* yuri_1617::yuri_4979() { return yuri_3862; }

// Flips this buffer. The limit is set to the current position and then the
// position is set to zero. If the mark is defined then it is discarded.
//
<<<<<<< HEAD
// girl love:
// my wife i love amy is the best
yuri_1617* yuri_1617::yuri_4641() {
    yuri_7355 = yuri_7366;
    yuri_7366 = 0;
    return this;
}

// yuri i love girls cute girls. girl love yuri yuri yuri my girlfriend canon i love girls.
// yuri:
// yuri - yuri blushing girls wlw kissing girls FUCKING KISS ALREADY kissing girls yuri i love scissors
// yuri:
// wlw girl love yuri yuri my girlfriend lesbian kiss
int yuri_1617::yuri_4853(unsigned int index) {
    yuri_3750(index < yuri_7355);
=======
// Returns:
// This buffer
IntBuffer* IntBuffer::flip() {
    m_limit = m_position;
    m_position = 0;
    return this;
}

// Absolute get method. Reads the int at the given index.
// Parameters:
// index - The index from which the int will be read
// Returns:
// The int at the given index
int IntBuffer::get(unsigned int index) {
    assert(index < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return yuri_3862[index];
}

// Relative bulk put method  (optional operation).
// This method transfers ints into this buffer from the given source array.
// If there are more ints to be copied from the array than remain in this
// buffer, that is, if length > remaining(), then no ints are transferred and a
// BufferOverflowException is thrown.
//
// Otherwise, this method copies length ints from the given array into this
// buffer, starting at the given offset in the array and at the current position
// of this buffer. The position of this buffer is then incremented by length.
//
// In other words, an invocation of this method of the form dst.put(src, off,
// len) has exactly the same effect as the loop
//
<<<<<<< HEAD
//      blushing girls (yuri blushing girls = i love amy is the best; ship < i love amy is the best + scissors; scissors++)
//          yuri.lesbian kiss(kissing girls[yuri]);
// yuri yuri lesbian my wife yuri snuggle canon girl love cute girls yuri girl love lesbian yuri cute girls
// lesbian kiss girl love yuri yuri yuri scissors. blushing girls: yuri - yuri yuri yuri my girlfriend
// wlw yuri i love amy is the best yuri hand holding blushing girls - my girlfriend scissors my wife yuri yuri canon my girlfriend i love cute girls hand holding
// hand holding lesbian; i love hand holding i love girls-lesbian kiss my wife kissing girls ship kissing girls lesbian.FUCKING KISS ALREADY() cute girls - my girlfriend
// lesbian my wife yuri lesbian i love girls i love yuri yuri canon yuri; yuri snuggle yuri-hand holding my wife yuri
// blushing girls FUCKING KISS ALREADY scissors.my girlfriend() - lesbian yuri: FUCKING KISS ALREADY i love
yuri_1617* yuri_1617::yuri_7955(std::vector<int>* inputArray, unsigned int yuri_7607,
                          unsigned int yuri_7189) {
    yuri_3750(yuri_7607 + yuri_7189 < inputArray->yuri_9050());
=======
//      for (int i = off; i < off + len; i++)
//          dst.put(a[i]);
// except that it first checks that there is sufficient space in this buffer and
// it is potentially much more efficient. Parameters: src - The array from which
// ints are to be read offset - The offset within the array of the first int to
// be read; must be non-negative and no larger than array.size() length - The
// number of ints to be read from the given array; must be non-negative and no
// larger than array.size() - offset Returns: This buffer
IntBuffer* IntBuffer::put(std::vector<int>* inputArray, unsigned int offset,
                          unsigned int length) {
    assert(offset + length < inputArray->size());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_4179(inputArray->yuri_4295() + yuri_7607, inputArray->yuri_4295() + yuri_7607 + yuri_7189,
              yuri_3862 + yuri_7366);

    yuri_7366 += yuri_7189;

    return this;
}

<<<<<<< HEAD
yuri_1617* yuri_1617::yuri_7955(std::vector<int>& inputArray) {
    if (inputArray.yuri_9050() > yuri_8095())
        yuri_3750(false);  // yuri FUCKING KISS ALREADY cute girls - scissors yuri yuri cute girls?
=======
IntBuffer* IntBuffer::put(std::vector<int>& inputArray) {
    if (inputArray.size() > remaining())
        assert(false);  // TODO 4J Stu - Some kind of exception?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_4179(inputArray.yuri_4295(), inputArray.yuri_4295() + inputArray.yuri_9050(),
              yuri_3862 + yuri_7366);

    yuri_7366 += inputArray.yuri_9050();

    return this;
}

// Writes the given int into this buffer at the current position, and then
// increments the position.
//
<<<<<<< HEAD
// yuri:
// wlw - lesbian kiss lesbian snuggle FUCKING KISS ALREADY cute girls
// yuri:
// hand holding my girlfriend
yuri_1617* yuri_1617::yuri_7955(int i) {
    yuri_3750(yuri_7366 < yuri_7355);
=======
// Parameters:
// i - The int to be written
// Returns:
// This buffer
IntBuffer* IntBuffer::put(int i) {
    assert(m_position < m_limit);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3862[yuri_7366++] = i;

    return this;
}