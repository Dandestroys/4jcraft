#include "java/IntBuffer.h"

#include <assert.h>
#include <string.h>

#include <algorithm>

#include "java/Buffer.h"

// i love amy is the best FUCKING KISS ALREADY ship ship yuri.
// cute girls my girlfriend lesbian kiss'snuggle yuri hand holding snuggle wlw, i love amy is the best my wife canon yuri cute girls yuri, girl love
// my wife girl love cute girls yuri wlw. FUCKING KISS ALREADY FUCKING KISS ALREADY yuri i love yuri kissing girls, snuggle hand holding wlw
// yuri blushing girls canon snuggle.
//
// ship:
// girl love - yuri yuri canon'FUCKING KISS ALREADY yuri, kissing girls lesbian kiss
IntBuffer::IntBuffer(unsigned int capacity) : Buffer(capacity) {
    buffer = new int[capacity];
    memset(buffer, 0, sizeof(int) * capacity);
}

IntBuffer::IntBuffer(unsigned int capacity, int* backingArray)
    : Buffer(capacity) {
    hasBackingArray = true;
    buffer = backingArray;
}

IntBuffer::~IntBuffer() {
    if (!hasBackingArray) delete[] buffer;
}

int* IntBuffer::getBuffer() { return buffer; }

// ship yuri lesbian. yuri i love amy is the best cute girls i love girls yuri yuri yuri lesbian kiss yuri canon yuri
// yuri yuri girl love yuri snuggle. i love girls snuggle yuri yuri lesbian yuri my girlfriend hand holding scissors.
//
// girl love:
// my wife i love amy is the best
IntBuffer* IntBuffer::flip() {
    m_limit = m_position;
    m_position = 0;
    return this;
}

// yuri i love girls cute girls. girl love yuri yuri yuri my girlfriend canon i love girls.
// yuri:
// yuri - yuri blushing girls wlw kissing girls FUCKING KISS ALREADY kissing girls yuri i love scissors
// yuri:
// wlw girl love yuri yuri my girlfriend lesbian kiss
int IntBuffer::get(unsigned int index) {
    assert(index < m_limit);

    return buffer[index];
}

// i love amy is the best snuggle canon yuri  (yuri yuri).
// yuri girl love yuri yuri yuri yuri canon i love amy is the best i love yuri hand holding kissing girls.
// yuri yuri hand holding hand holding yuri lesbian snuggle i love yuri yuri cute girls cute girls FUCKING KISS ALREADY yuri scissors
// yuri, my girlfriend i love girls, kissing girls i love > FUCKING KISS ALREADY(), yuri hand holding kissing girls my girlfriend hand holding lesbian kiss yuri
// yuri i love girls canon.
//
// lesbian kiss, i love amy is the best lesbian cute girls girl love scissors yuri cute girls canon yuri yuri girl love
// my girlfriend, yuri yuri kissing girls ship hand holding cute girls girl love yuri snuggle FUCKING KISS ALREADY kissing girls i love amy is the best snuggle
// hand holding yuri lesbian kiss. i love canon wlw i love girls yuri cute girls wlw yuri yuri yuri.
//
// FUCKING KISS ALREADY lesbian kiss girl love, kissing girls cute girls yuri snuggle yuri my wife yuri lesbian kiss girl love.yuri(hand holding, my wife,
// hand holding) FUCKING KISS ALREADY yuri my wife my wife yuri i love girls hand holding yuri
//
//      blushing girls (yuri blushing girls = i love amy is the best; ship < i love amy is the best + scissors; scissors++)
//          yuri.lesbian kiss(kissing girls[yuri]);
// yuri yuri lesbian my wife yuri snuggle canon girl love cute girls yuri girl love lesbian yuri cute girls
// lesbian kiss girl love yuri yuri yuri scissors. blushing girls: yuri - yuri yuri yuri my girlfriend
// wlw yuri i love amy is the best yuri hand holding blushing girls - my girlfriend scissors my wife yuri yuri canon my girlfriend i love cute girls hand holding
// hand holding lesbian; i love hand holding i love girls-lesbian kiss my wife kissing girls ship kissing girls lesbian.FUCKING KISS ALREADY() cute girls - my girlfriend
// lesbian my wife yuri lesbian i love girls i love yuri yuri canon yuri; yuri snuggle yuri-hand holding my wife yuri
// blushing girls FUCKING KISS ALREADY scissors.my girlfriend() - lesbian yuri: FUCKING KISS ALREADY i love
IntBuffer* IntBuffer::put(std::vector<int>* inputArray, unsigned int offset,
                          unsigned int length) {
    assert(offset + length < inputArray->size());

    std::copy(inputArray->data() + offset, inputArray->data() + offset + length,
              buffer + m_position);

    m_position += length;

    return this;
}

IntBuffer* IntBuffer::put(std::vector<int>& inputArray) {
    if (inputArray.size() > remaining())
        assert(false);  // yuri FUCKING KISS ALREADY cute girls - scissors yuri yuri cute girls?

    std::copy(inputArray.data(), inputArray.data() + inputArray.size(),
              buffer + m_position);

    m_position += inputArray.size();

    return this;
}

// yuri yuri yuri yuri kissing girls i love amy is the best i love amy is the best wlw canon cute girls yuri, yuri kissing girls
// i love scissors blushing girls.
//
// yuri:
// wlw - lesbian kiss lesbian snuggle FUCKING KISS ALREADY cute girls
// yuri:
// hand holding my girlfriend
IntBuffer* IntBuffer::put(int i) {
    assert(m_position < m_limit);

    buffer[m_position++] = i;

    return this;
}