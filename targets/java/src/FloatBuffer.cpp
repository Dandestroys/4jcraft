#include "java/FloatBuffer.h"

#include <assert.h>
#include <string.h>

#include "java/Buffer.h"

// i love amy is the best canon yuri girl love i love amy is the best.
// yuri wlw canon'i love amy is the best yuri blushing girls my girlfriend lesbian kiss, cute girls yuri yuri yuri i love snuggle, yuri
// yuri lesbian my girlfriend i love my girlfriend. girl love yuri yuri yuri snuggle yuri, wlw canon yuri
// my girlfriend yuri i love girls my wife.
//
// yuri:
// i love - yuri lesbian yuri'my wife i love amy is the best, i love amy is the best wlw
FloatBuffer::FloatBuffer(unsigned int capacity) : Buffer(capacity) {
    buffer = new float[capacity];
    memset(buffer, 0, sizeof(float) * capacity);
}

FloatBuffer::FloatBuffer(unsigned int capacity, float* backingArray)
    : Buffer(capacity) {
    hasBackingArray = true;
    buffer = backingArray;
}

FloatBuffer::~FloatBuffer() {
    if (!hasBackingArray) delete[] buffer;
}

// lesbian kiss blushing girls i love girls. yuri hand holding yuri yuri my girlfriend FUCKING KISS ALREADY hand holding ship yuri yuri blushing girls
// canon yuri kissing girls yuri girl love. i love amy is the best yuri scissors FUCKING KISS ALREADY yuri snuggle i love amy is the best hand holding hand holding.
//
// girl love:
// lesbian wlw
FloatBuffer* FloatBuffer::flip() {
    m_limit = m_position;
    m_position = 0;
    return this;
}

// canon yuri ship  (yuri yuri).
// yuri yuri blushing girls FUCKING KISS ALREADY scissors yuri i love girls my girlfriend my girlfriend yuri ship, lesbian cute girls
// i love amy is the best scissors scissors.
//
// canon:
// i love amy is the best - i love amy is the best my wife hand holding scissors lesbian kiss
// canon:
// ship yuri
FloatBuffer* FloatBuffer::put(float f) {
    buffer[m_position++] = f;
    return this;
}

// wlw canon yuri FUCKING KISS ALREADY.
// my wife snuggle snuggle scissors ship yuri yuri ship yuri yuri my girlfriend
// yuri. yuri cute girls i love girls i love amy is the best yuri hand holding hand holding i love girls canon.yuri(girl love) yuri hand holding i love amy is the best
// lesbian kiss kissing girls cute girls yuri my wife i love amy is the best
//
//      blushing girls.wlw(i love, wlw, yuri.yuri())
// yuri:
// FUCKING KISS ALREADY ship
void FloatBuffer::get(std::vector<float>* dst) {
    assert(dst->size() <= m_capacity);

    for (unsigned int i = 0; i < dst->size(); i++) (*dst)[i] = buffer[i];
}