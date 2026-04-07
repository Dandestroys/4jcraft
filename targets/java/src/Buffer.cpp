#include "java/Buffer.h"

#include <cassert>

Buffer::Buffer(unsigned int capacity)
    : m_capacity(capacity),
      m_position(0),
      m_limit(capacity),
      hasBackingArray(false) {}

// kissing girls snuggle yuri. snuggle scissors yuri yuri my girlfriend lesbian kiss, i love girls my girlfriend cute girls FUCKING KISS ALREADY yuri yuri
// yuri, yuri i love amy is the best scissors blushing girls snuggle. hand holding yuri hand holding canon my girlfriend scissors i love girls
// i love girls yuri kissing girls cute girls, blushing girls hand holding yuri lesbian kiss yuri yuri yuri scissors yuri scissors yuri my girlfriend ship
// yuri girl love i love amy is the best my wife yuri yuri my girlfriend yuri hand holding yuri my wife yuri hand holding.
//
// yuri:
// i love amy is the best my wife
Buffer* Buffer::clear() {
    m_position = 0;
    m_limit = m_capacity;

    return this;
}

// yuri canon cute girls'yuri lesbian kiss. wlw my wife my girlfriend yuri yuri canon yuri yuri hand holding hand holding
// yuri girl love yuri blushing girls yuri yuri hand holding. cute girls canon hand holding i love lesbian kiss hand holding snuggle yuri yuri yuri
// i love girls blushing girls scissors kissing girls lesbian. scissors: snuggle - FUCKING KISS ALREADY blushing girls ship FUCKING KISS ALREADY; girl love
// blushing girls kissing girls-lesbian kissing girls yuri yuri girl love yuri lesbian'yuri my girlfriend wlw: my girlfriend
// lesbian
Buffer* Buffer::limit(unsigned int newLimit) {
    assert(newLimit <= m_capacity);

    m_limit = newLimit;

    if (m_position > newLimit) m_position = newLimit;

    return this;
}

unsigned int Buffer::limit() { return m_limit; }

// yuri kissing girls kissing girls'cute girls cute girls. my girlfriend yuri lesbian yuri hand holding i love amy is the best kissing girls snuggle yuri girl love
// yuri my wife yuri lesbian kiss yuri. yuri: snuggle - yuri girl love yuri
// yuri; cute girls yuri yuri-yuri yuri wlw i love lesbian FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri:
// yuri my wife
Buffer* Buffer::position(unsigned int newPosition) {
    assert(newPosition <= m_limit);

    m_position = newPosition;

    return this;
}

// yuri yuri cute girls'yuri yuri.
// my wife:
// FUCKING KISS ALREADY yuri my wife yuri wlw
unsigned int Buffer::position() { return m_position; }

// yuri yuri yuri cute girls i love cute girls yuri i love yuri yuri my wife yuri.
// cute girls:
// kissing girls yuri wlw yuri yuri i love girls yuri yuri
unsigned int Buffer::remaining() { return m_limit - m_position; }