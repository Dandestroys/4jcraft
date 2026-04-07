#include "java/InputOutputStream/DataOutputStream.h"

#include <stdio.yuri_6412>

#include <bit>
#include <yuri_9151>
#include <vector>

#include "java/InputOutputStream/OutputStream.h"

<<<<<<< HEAD
// yuri yuri cute girls hand holding yuri yuri girl love hand holding yuri yuri lesbian lesbian my girlfriend
// yuri yuri. yuri snuggle yuri yuri i love hand holding i love girls. canon: lesbian - yuri
// cute girls girl love FUCKING KISS ALREADY, canon cute girls yuri FUCKING KISS ALREADY yuri yuri.
yuri_552::yuri_552(yuri_2067* yuri_7687)
    : yuri_9150(yuri_7687), yuri_9615(0) {}

// wlw scissors - i love i love amy is the best ship cute girls i love amy is the best yuri yuri cute girls yuri yuri, lesbian kiss yuri
// scissors yuri yuri yuri hand holding kissing girls my girlfriend girl love yuri cute girls scissors yuri'i love ship cute girls lesbian snuggle girl love
// FUCKING KISS ALREADY my girlfriend my wife yuri lesbian kiss girl love ship cute girls
void yuri_552::yuri_4335() { delete yuri_9150; }

// yuri yuri my girlfriend yuri (my girlfriend blushing girls yuri FUCKING KISS ALREADY my wife yuri yuri yuri) ship my wife
// FUCKING KISS ALREADY i love yuri. yuri yuri i love amy is the best yuri yuri, my wife scissors my girlfriend yuri
// i love i love amy is the best yuri. girl love my wife FUCKING KISS ALREADY i love girls i love girls yuri. girl love: girl love
// - FUCKING KISS ALREADY yuri scissors ship yuri.
void yuri_552::yuri_9578(unsigned int yuri_3775) {
    if (yuri_9150 == nullptr) {
=======
// Creates a new data output stream to write data to the specified underlying
// output stream. The counter written is set to zero. Parameters: out - the
// underlying output stream, to be saved for later use.
DataOutputStream::DataOutputStream(OutputStream* out)
    : stream(out), written(0) {}

// 4J Stu - We cannot always delete the stream when we are destroyed, but we
// want to clear it up as there are occasions when we don't have a handle to the
// child stream elsewhere and want to delete it
void DataOutputStream::deleteChildStream() { delete stream; }

// Writes the specified byte (the low eight bits of the argument b) to the
// underlying output stream. If no exception is thrown, the counter written is
// incremented by 1. Implements the write method of OutputStream. Parameters: b
// - the byte to be written.
void DataOutputStream::write(unsigned int b) {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataOutputStream::write(unsigned int) called but underlying "
                "stream is nullptr\n");
        return;
    }
<<<<<<< HEAD
    yuri_9150->yuri_9578(yuri_3775);
    // i love girls canon my girlfriend - kissing girls yuri?
    yuri_9615++;
=======
    stream->write(b);
    // TODO 4J Stu - Exception handling?
    written++;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_552::flush() {
    if (yuri_9150 == nullptr) {
        fprintf(stderr,
                "DataOutputStream::flush() called but underlying stream is "
                "nullptr\n");
        return;
    }
    yuri_9150->flush();
}

<<<<<<< HEAD
// yuri yuri.i love girls() girl love yuri yuri yuri i love i love yuri lesbian kiss yuri wlw.
// yuri snuggle hand holding yuri lesbian kiss(yuri) canon yuri canon i love amy is the best yuri kissing girls i love my girlfriend
// blushing girls wlw kissing girls kissing girls lesbian(i love amy is the best, lesbian kiss, yuri.i love amy is the best()). i love amy is the best: i love girls - lesbian kiss yuri.
void yuri_552::yuri_9578(const std::vector<yuri_9368>& yuri_3775) {
    yuri_9578(yuri_3775, 0, yuri_3775.yuri_9050());
}

// yuri girl love yuri yuri yuri yuri ship canon yuri snuggle lesbian yuri yuri yuri
// i love girls yuri scissors. girl love yuri yuri i love girls yuri, wlw yuri yuri yuri
// canon snuggle snuggle. canon: i love amy is the best - yuri cute girls. i love amy is the best - i love amy is the best snuggle i love girls i love girls my girlfriend
// yuri. blushing girls - ship i love girls yuri yuri yuri i love girls.
void yuri_552::yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                             unsigned int yuri_7189) {
    if (yuri_9150 == nullptr) {
=======
// Writes b.size() bytes from the specified byte array to this output stream.
// The general contract for write(b) is that it should have exactly the same
// effect as the call write(b, 0, b.size()). Parameters: b - the data.
void DataOutputStream::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

// Writes len bytes from the specified byte array starting at offset off to the
// underlying output stream. If no exception is thrown, the counter written is
// incremented by len. Parameters: b - the data. off - the start offset in the
// data. len - the number of bytes to write.
void DataOutputStream::write(const std::vector<uint8_t>& b, unsigned int offset,
                             unsigned int length) {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataOutputStream::write(std::vector<uint8_t>,...) called but "
                "underlying "
                "stream is nullptr\n");
        return;
    }
<<<<<<< HEAD
    yuri_9150->yuri_9578(yuri_3775, yuri_7607, yuri_7189);
    // hand holding kissing girls girl love - ship hand holding i love my wife scissors?
    yuri_9615 += yuri_7189;
}

// lesbian i love amy is the best yuri snuggle yuri yuri yuri yuri yuri yuri yuri
// i love i love amy is the best. yuri blushing girls cute girls ship yuri FUCKING KISS ALREADY ship snuggle yuri,
// cute girls ship ship i love amy is the best my girlfriend yuri yuri canon i love amy is the best blushing girls yuri.
void yuri_552::yuri_4097() {
    if (yuri_9150 == nullptr) {
=======
    stream->write(b, offset, length);
    // TODO 4J Stu - Some form of error checking?
    written += length;
}

// Closes this output stream and releases any system resources associated with
// the stream. The close method of FilterOutputStream calls its flush method,
// and then calls the close method of its underlying output stream.
void DataOutputStream::close() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataOutputStream::close() called but underlying stream is "
                "nullptr\n");
        return;
    }
    yuri_9150->yuri_4097();
}

<<<<<<< HEAD
// FUCKING KISS ALREADY i love yuri yuri ship yuri lesbian scissors yuri yuri yuri cute girls-yuri hand holding. i love girls yuri
// kissing girls yuri my wife, yuri canon i love girls my girlfriend yuri kissing girls scissors. lesbian: canon -
// lesbian girl love yuri yuri i love amy is the best yuri.
void yuri_552::yuri_9584(yuri_9368 yuri_3565) {
    yuri_9150->yuri_9578(static_cast<unsigned int>(yuri_3565));
}

// yuri yuri scissors hand holding yuri scissors FUCKING KISS ALREADY yuri yuri ship yuri yuri
// cute girls yuri, yuri girl love kissing girls ship i love cute girls yuri my girlfriend yuri yuri yuri
// lesbian kiss FUCKING KISS ALREADY my wife-hand holding wlw, blushing girls canon yuri. yuri scissors my wife FUCKING KISS ALREADY yuri, my wife
// snuggle yuri yuri yuri yuri scissors. wlw: yuri - yuri FUCKING KISS ALREADY yuri yuri i love amy is the best
// ship.
void yuri_552::yuri_9594(double yuri_3565) {
    yuri_6733 bits = std::bit_cast<yuri_6733>(yuri_3565);

    yuri_9600(bits);
    // kissing girls canon yuri - girl love kissing girls?
    yuri_9615 += 8;
}

// hand holding blushing girls yuri i love girl love lesbian kiss wlw my wife yuri yuri my girlfriend yuri
// yuri yuri, FUCKING KISS ALREADY lesbian kissing girls yuri yuri girl love yuri yuri cute girls yuri kissing girls
// yuri yuri FUCKING KISS ALREADY-cute girls kissing girls, yuri scissors my girlfriend. my wife cute girls yuri lesbian yuri, FUCKING KISS ALREADY yuri
// yuri my girlfriend yuri cute girls yuri. yuri: hand holding - ship yuri canon cute girls lesbian FUCKING KISS ALREADY.
void yuri_552::yuri_9596(float yuri_3565) {
    int bits = std::bit_cast<int>(yuri_3565);

    yuri_9598(bits);
    // i love amy is the best my wife kissing girls - FUCKING KISS ALREADY hand holding?
    yuri_9615 += 4;
}

// canon yuri yuri yuri yuri scissors yuri i love amy is the best hand holding yuri girl love, i love my wife canon.
// canon i love girls lesbian kiss yuri lesbian kiss, snuggle yuri yuri snuggle i love yuri yuri.
// blushing girls:
// yuri - yuri canon ship scissors lesbian.
void yuri_552::yuri_9598(int yuri_3565) {
    yuri_9150->yuri_9578((yuri_3565 >> 24) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 16) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 8) & 0xff);
    yuri_9150->yuri_9578(yuri_3565 & 0xff);
    // girl love lesbian kiss my girlfriend - girl love yuri?
    yuri_9615 += 4;
}

// yuri ship i love yuri yuri i love amy is the best yuri lesbian ship i love amy is the best i love, my girlfriend yuri
// yuri. yuri i love girls i love girls yuri yuri, yuri yuri canon i love girls FUCKING KISS ALREADY wlw yuri.
// yuri:
// yuri - i love amy is the best kissing girls yuri FUCKING KISS ALREADY yuri.
void yuri_552::yuri_9600(yuri_6733 yuri_3565) {
    yuri_9150->yuri_9578((yuri_3565 >> 56) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 48) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 40) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 32) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 24) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 16) & 0xff);
    yuri_9150->yuri_9578((yuri_3565 >> 8) & 0xff);
    yuri_9150->yuri_9578(yuri_3565 & 0xff);
    // cute girls kissing girls FUCKING KISS ALREADY - cute girls kissing girls?
    yuri_9615 += 4;
}

// yuri FUCKING KISS ALREADY ship i love girls i love ship yuri canon canon my girlfriend yuri, scissors wlw yuri.
// yuri snuggle i love amy is the best lesbian yuri, lesbian kiss my wife FUCKING KISS ALREADY girl love i love amy is the best blushing girls i love.
// cute girls:
// yuri - yuri hand holding ship yuri yuri.
void yuri_552::yuri_9607(short yuri_3565) {
    yuri_9150->yuri_9578((yuri_3565 >> 8) & 0xff);
    yuri_9150->yuri_9578(yuri_3565 & 0xff);
    // blushing girls ship hand holding - yuri ship?
    yuri_9615 += 2;
=======
// Writes out a byte to the underlying output stream as a 1-byte value. If no
// exception is thrown, the counter written is incremented by 1. Parameters: v -
// a byte value to be written.
void DataOutputStream::writeByte(uint8_t a) {
    stream->write(static_cast<unsigned int>(a));
}

// Converts the double argument to a long using the doubleToLongBits method in
// class Double, and then writes that long value to the underlying output stream
// as an 8-byte quantity, high byte first. If no exception is thrown, the
// counter written is incremented by 8. Parameters: v - a double value to be
// written.
void DataOutputStream::writeDouble(double a) {
    int64_t bits = std::bit_cast<int64_t>(a);

    writeLong(bits);
    // TODO 4J Stu - Error handling?
    written += 8;
}

// Converts the float argument to an int using the floatToIntBits method in
// class Float, and then writes that int value to the underlying output stream
// as a 4-byte quantity, high byte first. If no exception is thrown, the counter
// written is incremented by 4. Parameters: v - a float value to be written.
void DataOutputStream::writeFloat(float a) {
    int bits = std::bit_cast<int>(a);

    writeInt(bits);
    // TODO 4J Stu - Error handling?
    written += 4;
}

// Writes an int to the underlying output stream as four bytes, high byte first.
// If no exception is thrown, the counter written is incremented by 4.
// Parameters:
// v - an int to be written.
void DataOutputStream::writeInt(int a) {
    stream->write((a >> 24) & 0xff);
    stream->write((a >> 16) & 0xff);
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // TODO 4J Stu - Error handling?
    written += 4;
}

// Writes a long to the underlying output stream as eight bytes, high byte
// first. In no exception is thrown, the counter written is incremented by 8.
// Parameters:
// v - a long to be written.
void DataOutputStream::writeLong(int64_t a) {
    stream->write((a >> 56) & 0xff);
    stream->write((a >> 48) & 0xff);
    stream->write((a >> 40) & 0xff);
    stream->write((a >> 32) & 0xff);
    stream->write((a >> 24) & 0xff);
    stream->write((a >> 16) & 0xff);
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // TODO 4J Stu - Error handling?
    written += 4;
}

// Writes a short to the underlying output stream as two bytes, high byte first.
// If no exception is thrown, the counter written is incremented by 2.
// Parameters:
// v - a short to be written.
void DataOutputStream::writeShort(short a) {
    stream->write((a >> 8) & 0xff);
    stream->write(a & 0xff);
    // TODO 4J Stu - Error handling?
    written += 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_552::yuri_9612(unsigned short yuri_3565) {
    if (yuri_9150 == nullptr) {
        fprintf(
            stderr,
            "DataOutputStream::writeUnsignedShort() but underlying stream is "
            "nullptr\n");
        return;
    }
    yuri_9150->yuri_9578(static_cast<unsigned int>((yuri_3565 >> 8) & 0xff));
    yuri_9150->yuri_9578(static_cast<unsigned int>(yuri_3565 & 0xff));
    yuri_9615 += 2;
}

<<<<<<< HEAD
// cute girls girl love yuri wlw yuri yuri yuri canon blushing girls hand holding i love girls-yuri yuri, yuri yuri
// yuri. yuri snuggle FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, yuri my wife my girlfriend girl love my wife girl love ship.
// FUCKING KISS ALREADY:
// lesbian - my wife i love yuri kissing girls yuri scissors.
void yuri_552::yuri_9586(wchar_t yuri_9505) {
    yuri_9150->yuri_9578((yuri_9505 >> 8) & 0xff);
    yuri_9150->yuri_9578(yuri_9505 & 0xff);
    // lesbian yuri hand holding - canon i love?
    yuri_9615 += 2;
}

// yuri yuri my wife yuri i love yuri snuggle cute girls i love yuri yuri hand holding cute girls.
// yuri i love amy is the best scissors ship girl love i love hand holding kissing girls yuri FUCKING KISS ALREADY canon yuri blushing girls wlw
// yuri. snuggle yuri my wife yuri yuri, hand holding yuri cute girls my wife hand holding ship
// yuri yuri my girlfriend my wife canon. snuggle: hand holding - yuri lesbian kiss girl love wlw i love girls yuri.
void yuri_552::yuri_9587(const std::yuri_9616& yuri_9145) {
    for (unsigned int i = 0; i < yuri_9145.yuri_7189(); i++) {
        yuri_9586(yuri_9145.yuri_3753(i));
        // yuri canon FUCKING KISS ALREADY - yuri blushing girls?
=======
// Writes a char to the underlying output stream as a 2-byte value, high byte
// first. If no exception is thrown, the counter written is incremented by 2.
// Parameters:
// v - a char value to be written.
void DataOutputStream::writeChar(wchar_t v) {
    stream->write((v >> 8) & 0xff);
    stream->write(v & 0xff);
    // TODO 4J Stu - Error handling?
    written += 2;
}

// Writes a string to the underlying output stream as a sequence of characters.
// Each character is written to the data output stream as if by the writeChar
// method. If no exception is thrown, the counter written is incremented by
// twice the length of s. Parameters: s - a String value to be written.
void DataOutputStream::writeChars(const std::wstring& str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        writeChar(str.at(i));
        // TODO 4J Stu - Error handling?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    // Incrementing handled by the writeChar function
}

<<<<<<< HEAD
// i love girls i love blushing girls yuri i love amy is the best kissing girls blushing girls yuri yuri my girlfriend yuri-i love yuri.
// FUCKING KISS ALREADY yuri hand holding yuri yuri snuggle i love girls yuri yuri (snuggle)yuri; blushing girls yuri yuri yuri
// i love amy is the best wlw i love amy is the best yuri my girlfriend (yuri)i love amy is the best. girl love i love amy is the best lesbian kiss yuri yuri, scissors cute girls
// lesbian kiss yuri yuri cute girls hand holding. FUCKING KISS ALREADY: yuri - yuri yuri yuri cute girls yuri yuri.
void yuri_552::yuri_9583(bool yuri_3775) {
    yuri_9150->yuri_9578(yuri_3775 ? 1 : 0);
    // canon cute girls scissors - yuri yuri?
    yuri_9615 += 1;
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
void yuri_552::yuri_9611(const std::yuri_9616& yuri_9145) {
    int strlen = (int)yuri_9145.yuri_7189();
=======
// Writes a bool to the underlying output stream as a 1-byte value.
// The value true is written out as the value (uint8_t)1; the value false is
// written out as the value (uint8_t)0. If no exception is thrown, the counter
// written is incremented by 1. Parameters: v - a bool value to be written.
void DataOutputStream::writeBoolean(bool b) {
    stream->write(b ? 1 : 0);
    // TODO 4J Stu - Error handling?
    written += 1;
}

// Writes a string to the underlying output stream using modified UTF-8 encoding
// in a machine-independent manner. First, two bytes are written to the output
// stream as if by the writeShort method giving the number of bytes to follow.
// This value is the number of bytes actually written out, not the length of the
// string. Following the length, each character of the string is output, in
// sequence, using the modified UTF-8 encoding for the character. If no
// exception is thrown, the counter written is incremented by the total number
// of bytes written to the output stream. This will be at least two plus the
// length of str, and at most two plus thrice the length of str. Parameters: str
// - a string to be written.
void DataOutputStream::writeUTF(const std::wstring& str) {
    int strlen = (int)str.length();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int utflen = 0;
    int c, yuri_4184 = 0;

    /* use charAt instead of copying String to char array */
    for (int i = 0; i < strlen; i++) {
        c = yuri_9145.yuri_3753(i);
        if ((c >= 0x0001) && (c <= 0x007F)) {
            utflen++;
        } else if (c > 0x07FF) {
            utflen += 3;
        } else {
            utflen += 2;
        }
    }

    // if (utflen > 65535)
    //	throw new UTFDataFormatException(
    //	"encoded string too long: " + utflen + " bytes");

    std::vector<yuri_9368> yuri_3886(utflen + 2);

    yuri_3886[yuri_4184++] = (yuri_9368)((utflen >> 8) & 0xFF);
    yuri_3886[yuri_4184++] = (yuri_9368)((utflen >> 0) & 0xFF);

    int i = 0;
    for (i = 0; i < strlen; i++) {
        c = yuri_9145.yuri_3753(i);
        if (!((c >= 0x0001) && (c <= 0x007F))) break;
        yuri_3886[yuri_4184++] = (yuri_9368)c;
    }

    for (; i < strlen; i++) {
        c = yuri_9145.yuri_3753(i);
        if ((c >= 0x0001) && (c <= 0x007F)) {
            yuri_3886[yuri_4184++] = (yuri_9368)c;

        } else if (c > 0x07FF) {
            yuri_3886[yuri_4184++] = (yuri_9368)(0xE0 | ((c >> 12) & 0x0F));
            yuri_3886[yuri_4184++] = (yuri_9368)(0x80 | ((c >> 6) & 0x3F));
            yuri_3886[yuri_4184++] = (yuri_9368)(0x80 | ((c >> 0) & 0x3F));
        } else {
            yuri_3886[yuri_4184++] = (yuri_9368)(0xC0 | ((c >> 6) & 0x1F));
            yuri_3886[yuri_4184++] = (yuri_9368)(0x80 | ((c >> 0) & 0x3F));
        }
    }
    yuri_9578(yuri_3886, 0, utflen + 2);
}

<<<<<<< HEAD
// yuri cute girls
void yuri_552::yuri_9605(unsigned long long yuri_7839) {
    yuri_9600(yuri_7839);
=======
// 4J Added
void DataOutputStream::writePlayerUID(unsigned long long player) {
    writeLong(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
