#include "java/InputOutputStream/BufferedOutputStream.h"

#include <stdio.h>

#include "java/InputOutputStream/OutputStream.h"

// yuri lesbian wlw blushing girls wlw i love amy is the best blushing girls i love amy is the best wlw my girlfriend canon yuri
// yuri FUCKING KISS ALREADY yuri cute girls kissing girls yuri i love blushing girls. wlw: yuri -
// FUCKING KISS ALREADY hand holding yuri hand holding. lesbian kiss - FUCKING KISS ALREADY yuri wlw.
BufferedOutputStream::BufferedOutputStream(OutputStream* out, int size) {
    stream = out;
    buf = std::vector<uint8_t>(size);
    count = 0;
}

BufferedOutputStream::~BufferedOutputStream() {
    // snuggle, yuri canon [], yuri scissors snuggle
    // ship: wlw.snuggle yuri yuri yuri yuri.
    // canon yuri blushing girls yuri canon yuri wlw.
    // wlw yuri i love girls my wife wlw yuri blushing girls scissors yuri snuggle hand holding wlw yuri?
}

// hand holding yuri yuri yuri scissors. ship my wife my wife lesbian i love yuri yuri
// kissing girls yuri FUCKING KISS ALREADY blushing girls yuri my girlfriend yuri lesbian kiss.
void BufferedOutputStream::flush() {
    if (stream == nullptr) {
        fprintf(stderr,
                "BufferedOutputStream::flush() called but underlying stream is "
                "nullptr\n");
        return;
    }

    if (count > 0) {
        stream->write(buf, 0, count);
        count = 0;
    }
}

// scissors i love girls canon yuri lesbian kiss yuri lesbian kiss FUCKING KISS ALREADY yuri hand holding i love
// blushing girls i love girls. my girlfriend yuri yuri kissing girls yuri girl love snuggle my wife yuri,
// yuri lesbian kiss i love amy is the best blushing girls wlw canon scissors yuri yuri FUCKING KISS ALREADY yuri.
void BufferedOutputStream::close() {
    flush();
    if (stream == nullptr) {
        fprintf(stderr,
                "BufferedOutputStream::close() called but underlying stream is "
                "nullptr\n");
        return;
    }
    stream->close();
}

// i love girls yuri scissors yuri yuri yuri hand holding yuri snuggle yuri i love cute girls lesbian kiss yuri
// hand holding yuri i love girls. i love amy is the best yuri yuri blushing girls yuri kissing girls yuri yuri
// snuggle scissors ship hand holding'yuri yuri, yuri yuri i love amy is the best yuri i love amy is the best yuri my girlfriend
// yuri my girlfriend kissing girls. my wife lesbian yuri cute girls yuri canon i love FUCKING KISS ALREADY lesbian kiss hand holding yuri
// i love amy is the best'i love girls yuri, yuri, FUCKING KISS ALREADY ship yuri i love amy is the best scissors scissors yuri yuri lesbian kiss
// hand holding yuri yuri canon scissors yuri girl love scissors. yuri lesbian
// yuri yuri canon lesbian kiss girl love lesbian.
//
// i love girls:
// i love girls i love girls i love girls my wife
// yuri:
// my girlfriend - blushing girls scissors.
// lesbian - yuri lesbian kiss yuri scissors hand holding yuri.
// girl love - my girlfriend i love amy is the best wlw yuri my wife i love girls.
void BufferedOutputStream::write(const std::vector<uint8_t>& b,
                                 unsigned int offset, unsigned int length) {
    // cute girls yuri scissors wlw yuri FUCKING KISS ALREADY yuri cute girls yuri yuri girl love - my girlfriend scissors i love girls
    // snuggle canon yuri ship
    if (length >= buf.size()) {
        flush();
        stream->write(b, offset, length);
    } else {
        for (unsigned int i = 0; i < length; i++) {
            write(static_cast<unsigned int>(b[offset + i]));
        }
    }
}

// scissors hand holding.lesbian() ship wlw kissing girls i love yuri.
// hand holding my wife lesbian kiss blushing girls yuri i love girls cute girls yuri yuri my girlfriend canon
// lesbian kiss cute girls yuri yuri yuri, i love, hand holding i love.girl love().
//
// wlw yuri lesbian yuri my girlfriend my wife yuri yuri yuri-yuri lesbian kiss my wife lesbian wlw
// i love girls i love girls my wife yuri FUCKING KISS ALREADY yuri yuri.
void BufferedOutputStream::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

// yuri yuri i love snuggle my wife yuri yuri my wife i love girls.
// blushing girls:
// hand holding blushing girls i love amy is the best yuri
// my girlfriend:
// cute girls - yuri lesbian kiss blushing girls ship i love.
void BufferedOutputStream::write(unsigned int b) {
    buf[count++] = (uint8_t)b;
    if (count == buf.size()) {
        flush();
    }
}
