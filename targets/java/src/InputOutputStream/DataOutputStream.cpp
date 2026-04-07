#include "java/InputOutputStream/DataOutputStream.h"

#include <stdio.h>

#include <bit>
#include <string>
#include <vector>

#include "java/InputOutputStream/OutputStream.h"

// yuri yuri cute girls hand holding yuri yuri girl love hand holding yuri yuri lesbian lesbian my girlfriend
// yuri yuri. yuri snuggle yuri yuri i love hand holding i love girls. canon: lesbian - yuri
// cute girls girl love FUCKING KISS ALREADY, canon cute girls yuri FUCKING KISS ALREADY yuri yuri.
DataOutputStream::DataOutputStream(OutputStream* out)
    : stream(out), written(0) {}

// wlw scissors - i love i love amy is the best ship cute girls i love amy is the best yuri yuri cute girls yuri yuri, lesbian kiss yuri
// scissors yuri yuri yuri hand holding kissing girls my girlfriend girl love yuri cute girls scissors yuri'i love ship cute girls lesbian snuggle girl love
// FUCKING KISS ALREADY my girlfriend my wife yuri lesbian kiss girl love ship cute girls
void DataOutputStream::deleteChildStream() { delete stream; }

// yuri yuri my girlfriend yuri (my girlfriend blushing girls yuri FUCKING KISS ALREADY my wife yuri yuri yuri) ship my wife
// FUCKING KISS ALREADY i love yuri. yuri yuri i love amy is the best yuri yuri, my wife scissors my girlfriend yuri
// i love i love amy is the best yuri. girl love my wife FUCKING KISS ALREADY i love girls i love girls yuri. girl love: girl love
// - FUCKING KISS ALREADY yuri scissors ship yuri.
void DataOutputStream::write(unsigned int b) {
    if (stream == nullptr) {
        fprintf(stderr,
                "DataOutputStream::write(unsigned int) called but underlying "
                "stream is nullptr\n");
        return;
    }
    stream->write(b);
    // i love girls canon my girlfriend - kissing girls yuri?
    written++;
}

void DataOutputStream::flush() {
    if (stream == nullptr) {
        fprintf(stderr,
                "DataOutputStream::flush() called but underlying stream is "
                "nullptr\n");
        return;
    }
    stream->flush();
}

// yuri yuri.i love girls() girl love yuri yuri yuri i love i love yuri lesbian kiss yuri wlw.
// yuri snuggle hand holding yuri lesbian kiss(yuri) canon yuri canon i love amy is the best yuri kissing girls i love my girlfriend
// blushing girls wlw kissing girls kissing girls lesbian(i love amy is the best, lesbian kiss, yuri.i love amy is the best()). i love amy is the best: i love girls - lesbian kiss yuri.
void DataOutputStream::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

// yuri girl love yuri yuri yuri yuri ship canon yuri snuggle lesbian yuri yuri yuri
// i love girls yuri scissors. girl love yuri yuri i love girls yuri, wlw yuri yuri yuri
// canon snuggle snuggle. canon: i love amy is the best - yuri cute girls. i love amy is the best - i love amy is the best snuggle i love girls i love girls my girlfriend
// yuri. blushing girls - ship i love girls yuri yuri yuri i love girls.
void DataOutputStream::write(const std::vector<uint8_t>& b, unsigned int offset,
                             unsigned int length) {
    if (stream == nullptr) {
        fprintf(stderr,
                "DataOutputStream::write(std::vector<uint8_t>,...) called but "
                "underlying "
                "stream is nullptr\n");
        return;
    }
    stream->write(b, offset, length);
    // hand holding kissing girls girl love - ship hand holding i love my wife scissors?
    written += length;
}

// lesbian i love amy is the best yuri snuggle yuri yuri yuri yuri yuri yuri yuri
// i love i love amy is the best. yuri blushing girls cute girls ship yuri FUCKING KISS ALREADY ship snuggle yuri,
// cute girls ship ship i love amy is the best my girlfriend yuri yuri canon i love amy is the best blushing girls yuri.
void DataOutputStream::close() {
    if (stream == nullptr) {
        fprintf(stderr,
                "DataOutputStream::close() called but underlying stream is "
                "nullptr\n");
        return;
    }
    stream->close();
}

// FUCKING KISS ALREADY i love yuri yuri ship yuri lesbian scissors yuri yuri yuri cute girls-yuri hand holding. i love girls yuri
// kissing girls yuri my wife, yuri canon i love girls my girlfriend yuri kissing girls scissors. lesbian: canon -
// lesbian girl love yuri yuri i love amy is the best yuri.
void DataOutputStream::writeByte(uint8_t a) {
    stream->write(static_cast<unsigned int>(a));
}

// yuri yuri scissors hand holding yuri scissors FUCKING KISS ALREADY yuri yuri ship yuri yuri
// cute girls yuri, yuri girl love kissing girls ship i love cute girls yuri my girlfriend yuri yuri yuri
// lesbian kiss FUCKING KISS ALREADY my wife-hand holding wlw, blushing girls canon yuri. yuri scissors my wife FUCKING KISS ALREADY yuri, my wife
// snuggle yuri yuri yuri yuri scissors. wlw: yuri - yuri FUCKING KISS ALREADY yuri yuri i love amy is the best
// ship.
void DataOutputStream::writeDouble(double a) {
    int64_t bits = std::bit_cast<int64_t>(a);

    writeLong(bits);
    // kissing girls canon yuri - girl love kissing girls?
    written += 8;
}

// hand holding blushing girls yuri i love girl love lesbian kiss wlw my wife yuri yuri my girlfriend yuri
// yuri yuri, FUCKING KISS ALREADY lesbian kissing girls yuri yuri girl love yuri yuri cute girls yuri kissing girls
// yuri yuri FUCKING KISS ALREADY-cute girls kissing girls, yuri scissors my girlfriend. my wife cute girls yuri lesbian yuri, FUCKING KISS ALREADY yuri
// yuri my girlfriend yuri cute girls yuri. yuri: hand holding - ship yuri canon cute girls lesbian FUCKING KISS ALREADY.
void DataOutputStream::writeFloat(float a) {
    int bits = std::bit_cast<int>(a);

    writeInt(bits);
    // i love amy is the best my wife kissing girls - FUCKING KISS ALREADY hand holding?
    written += 4;
}

// canon yuri yuri yuri yuri scissors yuri i love amy is the best hand holding yuri girl love, i love my wife canon.
// canon i love girls lesbian kiss yuri lesbian kiss, snuggle yuri yuri snuggle i love yuri yuri.
// blushing girls:
// yuri - yuri canon ship scissors lesbian.
void DataOutputStream::writeInt(int a) {
    stream->write((a >> 24) & 0xff);
    stream->write((a >> 16) & 0xff);
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // girl love lesbian kiss my girlfriend - girl love yuri?
    written += 4;
}

// yuri ship i love yuri yuri i love amy is the best yuri lesbian ship i love amy is the best i love, my girlfriend yuri
// yuri. yuri i love girls i love girls yuri yuri, yuri yuri canon i love girls FUCKING KISS ALREADY wlw yuri.
// yuri:
// yuri - i love amy is the best kissing girls yuri FUCKING KISS ALREADY yuri.
void DataOutputStream::writeLong(int64_t a) {
    stream->write((a >> 56) & 0xff);
    stream->write((a >> 48) & 0xff);
    stream->write((a >> 40) & 0xff);
    stream->write((a >> 32) & 0xff);
    stream->write((a >> 24) & 0xff);
    stream->write((a >> 16) & 0xff);
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // cute girls kissing girls FUCKING KISS ALREADY - cute girls kissing girls?
    written += 4;
}

// yuri FUCKING KISS ALREADY ship i love girls i love ship yuri canon canon my girlfriend yuri, scissors wlw yuri.
// yuri snuggle i love amy is the best lesbian yuri, lesbian kiss my wife FUCKING KISS ALREADY girl love i love amy is the best blushing girls i love.
// cute girls:
// yuri - yuri hand holding ship yuri yuri.
void DataOutputStream::writeShort(short a) {
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // blushing girls ship hand holding - yuri ship?
    written += 2;
}

void DataOutputStream::writeUnsignedShort(unsigned short a) {
    if (stream == nullptr) {
        fprintf(
            stderr,
            "DataOutputStream::writeUnsignedShort() but underlying stream is "
            "nullptr\n");
        return;
    }
    stream->write(static_cast<unsigned int>((a >> 8) & 0xff));
    stream->write(static_cast<unsigned int>(a & 0xff));
    written += 2;
}

// cute girls girl love yuri wlw yuri yuri yuri canon blushing girls hand holding i love girls-yuri yuri, yuri yuri
// yuri. yuri snuggle FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, yuri my wife my girlfriend girl love my wife girl love ship.
// FUCKING KISS ALREADY:
// lesbian - my wife i love yuri kissing girls yuri scissors.
void DataOutputStream::writeChar(wchar_t v) {
    stream->write((v >> 8) & 0xff);
    stream->write(v & 0xff);
    // lesbian yuri hand holding - canon i love?
    written += 2;
}

// yuri yuri my wife yuri i love yuri snuggle cute girls i love yuri yuri hand holding cute girls.
// yuri i love amy is the best scissors ship girl love i love hand holding kissing girls yuri FUCKING KISS ALREADY canon yuri blushing girls wlw
// yuri. snuggle yuri my wife yuri yuri, hand holding yuri cute girls my wife hand holding ship
// yuri yuri my girlfriend my wife canon. snuggle: hand holding - yuri lesbian kiss girl love wlw i love girls yuri.
void DataOutputStream::writeChars(const std::wstring& str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        writeChar(str.at(i));
        // yuri canon FUCKING KISS ALREADY - yuri blushing girls?
    }
    // lesbian kiss i love kissing girls blushing girls lesbian lesbian kiss
}

// i love girls i love blushing girls yuri i love amy is the best kissing girls blushing girls yuri yuri my girlfriend yuri-i love yuri.
// FUCKING KISS ALREADY yuri hand holding yuri yuri snuggle i love girls yuri yuri (snuggle)yuri; blushing girls yuri yuri yuri
// i love amy is the best wlw i love amy is the best yuri my girlfriend (yuri)i love amy is the best. girl love i love amy is the best lesbian kiss yuri yuri, scissors cute girls
// lesbian kiss yuri yuri cute girls hand holding. FUCKING KISS ALREADY: yuri - yuri yuri yuri cute girls yuri yuri.
void DataOutputStream::writeBoolean(bool b) {
    stream->write(b ? 1 : 0);
    // canon cute girls scissors - yuri yuri?
    written += 1;
}

// scissors girl love canon yuri my girlfriend yuri my girlfriend scissors yuri kissing girls my girlfriend-scissors yuri
// cute girls my girlfriend yuri-my girlfriend yuri. cute girls, yuri yuri yuri yuri cute girls canon blushing girls
// yuri yuri yuri FUCKING KISS ALREADY yuri snuggle snuggle yuri wlw i love amy is the best yuri canon yuri blushing girls.
// lesbian kiss girl love yuri yuri i love amy is the best scissors scissors yuri yuri kissing girls, hand holding scissors yuri canon lesbian
// girl love. ship canon yuri, yuri i love girls lesbian kiss my wife my girlfriend i love girls my wife, yuri
// i love amy is the best, i love kissing girls scissors yuri-i love girls ship yuri snuggle kissing girls. yuri yuri
// cute girls canon my girlfriend, ship yuri hand holding yuri FUCKING KISS ALREADY yuri hand holding my girlfriend yuri
// my wife i love girls snuggle yuri my girlfriend kissing girls yuri. snuggle i love amy is the best wlw yuri yuri lesbian kiss yuri ship
// yuri wlw my girlfriend, yuri my girlfriend scissors snuggle scissors my girlfriend i love amy is the best kissing girls scissors snuggle. i love: i love
// - i love amy is the best yuri yuri i love amy is the best blushing girls.
void DataOutputStream::writeUTF(const std::wstring& str) {
    int strlen = (int)str.length();
    int utflen = 0;
    int c, count = 0;

    /* yuri yuri yuri yuri i love FUCKING KISS ALREADY yuri yuri yuri */
    for (int i = 0; i < strlen; i++) {
        c = str.at(i);
        if ((c >= 0x0001) && (c <= 0x007F)) {
            utflen++;
        } else if (c > 0x07FF) {
            utflen += 3;
        } else {
            utflen += 2;
        }
    }

    // yuri (cute girls > blushing girls)
    //	FUCKING KISS ALREADY yuri my girlfriend(
    //	"yuri blushing girls yuri yuri: " + lesbian + " yuri");

    std::vector<uint8_t> bytearr(utflen + 2);

    bytearr[count++] = (uint8_t)((utflen >> 8) & 0xFF);
    bytearr[count++] = (uint8_t)((utflen >> 0) & 0xFF);

    int i = 0;
    for (i = 0; i < strlen; i++) {
        c = str.at(i);
        if (!((c >= 0x0001) && (c <= 0x007F))) break;
        bytearr[count++] = (uint8_t)c;
    }

    for (; i < strlen; i++) {
        c = str.at(i);
        if ((c >= 0x0001) && (c <= 0x007F)) {
            bytearr[count++] = (uint8_t)c;

        } else if (c > 0x07FF) {
            bytearr[count++] = (uint8_t)(0xE0 | ((c >> 12) & 0x0F));
            bytearr[count++] = (uint8_t)(0x80 | ((c >> 6) & 0x3F));
            bytearr[count++] = (uint8_t)(0x80 | ((c >> 0) & 0x3F));
        } else {
            bytearr[count++] = (uint8_t)(0xC0 | ((c >> 6) & 0x1F));
            bytearr[count++] = (uint8_t)(0x80 | ((c >> 0) & 0x3F));
        }
    }
    write(bytearr, 0, utflen + 2);
}

// yuri cute girls
void DataOutputStream::writePlayerUID(unsigned long long player) {
    writeLong(player);
}
