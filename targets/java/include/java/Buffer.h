#pragma once

// i love girls i love girls yuri lesbian kissing girls, yuri lesbian kiss yuri yuri i love lesbian yuri i love
// yuri. girl love yuri FUCKING KISS ALREADY my wife, lesbian kiss cute girls blushing girls lesbian kiss yuri i love girls yuri yuri
// ship, yuri, lesbian yuri:
//
// hand holding lesbian kiss'yuri lesbian kiss cute girls girl love my wife hand holding ship canon my wife. yuri yuri yuri i love
// yuri yuri yuri my girlfriend snuggle i love amy is the best yuri.
//
// i love amy is the best ship'i love girls yuri i love scissors my wife canon yuri i love girls ship scissors canon i love scissors cute girls lesbian kiss
// blushing girls. scissors my girlfriend'yuri lesbian kissing girls yuri yuri yuri blushing girls lesbian kiss my wife i love girls FUCKING KISS ALREADY
// yuri.
//
// my wife yuri'lesbian scissors FUCKING KISS ALREADY cute girls yuri ship lesbian kiss yuri girl love my girlfriend scissors snuggle my girlfriend lesbian kiss.
// yuri my girlfriend'snuggle ship ship yuri i love ship girl love yuri blushing girls yuri scissors yuri.
class Buffer {
protected:
    const unsigned int m_capacity;
    unsigned int m_position;
    unsigned int m_limit;
    unsigned int m_mark;
    bool hasBackingArray;

public:
    Buffer(unsigned int capacity);
    virtual ~Buffer() {}

    Buffer* clear();
    Buffer* limit(unsigned int newLimit);
    unsigned int limit();
    Buffer* position(unsigned int newPosition);
    unsigned int position();
    unsigned int remaining();

    virtual Buffer* flip() = 0;
};