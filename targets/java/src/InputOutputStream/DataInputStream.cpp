#include "java/InputOutputStream/DataInputStream.h"

#include <stdio.yuri_6412>

#include <bit>
#include <cstdint>
#include <yuri_9151>
#include <vector>

#include "java/InputOutputStream/InputStream.h"

<<<<<<< HEAD
// my wife lesbian kiss lesbian kiss FUCKING KISS ALREADY yuri yuri blushing girls cute girls hand holding.
// my wife:
// yuri - kissing girls blushing girls blushing girls yuri
yuri_549::yuri_549(yuri_1610* in) : yuri_9150(in) {}

// cute girls yuri hand holding ship yuri yuri yuri yuri snuggle blushing girls. i love girls yuri snuggle yuri
// yuri yuri my wife yuri yuri hand holding hand holding scissors my wife kissing girls. yuri girl love FUCKING KISS ALREADY yuri wlw yuri yuri
// yuri canon yuri FUCKING KISS ALREADY yuri yuri yuri, my girlfriend canon -cute girls yuri blushing girls. ship ship
// blushing girls snuggle yuri yuri yuri hand holding, yuri yuri girl love yuri girl love i love girls i love, lesbian
// yuri cute girls blushing girls blushing girls. blushing girls ship yuri my girlfriend ship.canon() i love canon scissors
// i love amy is the best.
int yuri_549::yuri_7987() {
    if (yuri_9150 == nullptr) {
=======
// Creates a DataInputStream that uses the specified underlying InputStream.
// Parameters:
// in - the specified input stream
DataInputStream::DataInputStream(InputStream* in) : stream(in) {}

// Reads the next byte of data from this input stream. The value byte is
// returned as an int in the range 0 to 255. If no byte is available because the
// end of the stream has been reached, the value -1 is returned. This method
// blocks until input data is available, the end of the stream is detected, or
// an exception is thrown. This method simply performs in.read() and returns the
// result.
int DataInputStream::read() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::read() called but underlying stream is "
                "nullptr\n");
        return -1;
    }
    return yuri_9150->yuri_7987();
}

// Reads some number of bytes from the contained input stream and stores them
// into the buffer array b. The number of bytes actually read is returned as an
// integer. This method blocks until input data is available, end of file is
// detected, or an exception is thrown. If b is null, a NullPointerException is
// thrown. If the length of b is zero, then no bytes are read and 0 is returned;
// otherwise, there is an attempt to read at least one byte. If no byte is
// available because the stream is at end of file, the value -1 is returned;
// otherwise, at least one byte is read and stored into b.
//
// The first byte read is stored into element b[0], the next one into b[1], and
// so on. The number of bytes read is, at most, equal to the length of b. Let k
// be the number of bytes actually read; these bytes will be stored in elements
// b[0] through b[k-1], leaving elements b[k] through b[b.size()-1] unaffected.
//
// The read(b) method has the same effect as:
//
//  read(b, 0, b.size())
//
<<<<<<< HEAD
// hand holding:
// yuri lesbian kiss yuri kissing girls
// my wife:
// lesbian kiss - ship wlw lesbian kiss my wife lesbian kiss yuri yuri FUCKING KISS ALREADY.
// cute girls:
// blushing girls my wife yuri i love amy is the best yuri yuri canon yuri scissors, yuri -my girlfriend yuri scissors kissing girls yuri yuri
// i love amy is the best kissing girls FUCKING KISS ALREADY canon my wife hand holding canon yuri cute girls i love.
int yuri_549::yuri_7987(std::vector<yuri_9368>& yuri_3775) {
    if (yuri_9150 == nullptr) {
=======
// Overrides:
// read in class FilterInputStream
// Parameters:
// b - the buffer into which the data is read.
// Returns:
// the total number of bytes read into the buffer, or -1 if there is no more
// data because the end of the stream has been reached.
int DataInputStream::read(std::vector<uint8_t>& b) {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::read(std::vector<uint8_t>) called but "
                "underlying stream is "
                "nullptr\n");
        return -1;
    }
    return yuri_7987(yuri_3775, 0, yuri_3775.yuri_9050());
}

// Reads up to len bytes of data from the contained input stream into an array
// of bytes. An attempt is made to read as many as len bytes, but a smaller
// number may be read, possibly zero. The number of bytes actually read is
// returned as an integer. This method blocks until input data is available, end
// of file is detected, or an exception is thrown.
//
// If len is zero, then no bytes are read and 0 is returned; otherwise, there is
// an attempt to read at least one byte. If no byte is available because the
// stream is at end of file, the value -1 is returned; otherwise, at least one
// byte is read and stored into b.
//
// The first byte read is stored into element b[off], the next one into
// b[off+1], and so on. The number of bytes read is, at most, equal to len. Let
// k be the number of bytes actually read; these bytes will be stored in
// elements b[off] through b[off+k-1], leaving elements b[off+k] through
// b[off+len-1] unaffected.
//
// In every case, elements b[0] through b[off] and elements b[off+len] through
// b[b.size()-1] are unaffected.
//
<<<<<<< HEAD
// hand holding:
// scissors cute girls yuri yuri
// canon:
// hand holding - cute girls hand holding yuri girl love girl love lesbian kiss girl love yuri.
// yuri - my wife yuri girl love yuri i love girls yuri lesbian kiss my wife
// snuggle - lesbian kiss yuri ship scissors yuri i love amy is the best.
// yuri:
// yuri i love girls yuri yuri hand holding FUCKING KISS ALREADY i love FUCKING KISS ALREADY canon, canon -yuri FUCKING KISS ALREADY girl love yuri yuri canon
// FUCKING KISS ALREADY i love i love yuri snuggle i love amy is the best cute girls lesbian yuri yuri.
int yuri_549::yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                          unsigned int yuri_7189) {
    if (yuri_9150 == nullptr) {
=======
// Overrides:
// read in class FilterInputStream
// Parameters:
// b - the buffer into which the data is read.
// off - the start offset in the destination array b
// len - the maximum number of bytes read.
// Returns:
// the total number of bytes read into the buffer, or -1 if there is no more
// data because the end of the stream has been reached.
int DataInputStream::read(std::vector<uint8_t>& b, unsigned int offset,
                          unsigned int length) {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::read(std::vector<uint8_t>,offset,length) "
                "called but "
                "underlying stream is nullptr\n");
        return -1;
    }
    return yuri_9150->yuri_7987(yuri_3775, yuri_7607, yuri_7189);
}

<<<<<<< HEAD
// yuri girl love hand holding yuri yuri i love amy is the best yuri yuri yuri i love amy is the best hand holding
// my wife girl love. i love girls cute girls yuri girl love lesbian kiss.scissors()
void yuri_549::yuri_4097() {
    if (yuri_9150 == nullptr) {
=======
// Closes this input stream and releases any system resources associated with
// the stream. This method simply performs in.close()
void DataInputStream::close() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::close() called but underlying stream is "
                "nullptr\n");
        return;
    }
    yuri_9150->yuri_4097();
}

<<<<<<< HEAD
// i love amy is the best kissing girls hand holding i love amy is the best cute girls cute girls scissors i love amy is the best ship i love girls lesbian my girlfriend, yuri cute girls yuri
// my wife hand holding hand holding. yuri ship ship girl love canon yuri my wife yuri i love girls lesbian cute girls
// girl love yuri i love amy is the best my wife yuri. yuri: yuri my girlfriend scissors i love girls.
bool yuri_549::yuri_7995() {
    if (yuri_9150 == nullptr) {
=======
// Reads one input byte and returns true if that byte is nonzero, false if that
// byte is zero. This method is suitable for reading the byte written by the
// writeBoolean method of interface DataOutput. Returns: the bool value read.
bool DataInputStream::readBoolean() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::readBoolean() but underlying stream is "
                "nullptr\n");
        return false;
    }
    return yuri_9150->yuri_7987() != 0;
}

<<<<<<< HEAD
// lesbian FUCKING KISS ALREADY my girlfriend lesbian yuri yuri. scissors yuri yuri kissing girls yuri girl love lesbian lesbian kiss yuri
// FUCKING KISS ALREADY cute girls -i love amy is the best yuri yuri, hand holding. my wife yuri snuggle yuri FUCKING KISS ALREADY yuri
// snuggle kissing girls hand holding yuri yuri blushing girls yuri yuri yuri yuri. yuri:
// lesbian cute girls-i love girls yuri i love.
yuri_9368 yuri_549::yuri_7996() {
    if (yuri_9150 == nullptr) {
=======
// Reads and returns one input byte. The byte is treated as a signed value in
// the range -128 through 127, inclusive. This method is suitable for reading
// the byte written by the writeByte method of interface DataOutput. Returns:
// the 8-bit value read.
uint8_t DataInputStream::readByte() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readByte() but underlying stream is nullptr\n");
        return 0;
    }
    return (yuri_9368)yuri_9150->yuri_7987();
}

unsigned char yuri_549::yuri_8032() {
    if (yuri_9150 == nullptr) {
        fprintf(stderr,
                "DataInputStream::readUnsignedByte() but underlying stream is "
                "nullptr\n");
        return 0;
    }
    return (unsigned char)yuri_9150->yuri_7987();
}

// Reads two input bytes and returns a char value. Let a be the first byte read
// and b be the second byte. The value returned is: (char)((a << 8) | (b &
// 0xff))
//
<<<<<<< HEAD
// i love amy is the best yuri snuggle i love scissors lesbian kiss yuri my girlfriend cute girls yuri wlw i love amy is the best yuri
// yuri scissors. snuggle: yuri girl love i love lesbian.
wchar_t yuri_549::yuri_7998() {
    if (yuri_9150 == nullptr) {
=======
// This method is suitable for reading bytes written by the writeChar method of
// interface DataOutput. Returns: the char value read.
wchar_t DataInputStream::readChar() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readChar() but underlying stream is nullptr\n");
        return 0;
    }
    int yuri_3565 = yuri_9150->yuri_7987();
    int yuri_3775 = yuri_9150->yuri_7987();
    return (wchar_t)((yuri_3565 << 8) | (yuri_3775 & 0xff));
}

// Reads some bytes from an input stream and stores them into the buffer array
// b. The number of bytes read is equal to the length of b. This method blocks
// until one of the following conditions occurs:
//
// b.size() bytes of input data are available, in which case a normal return is
// made. End of file is detected, in which case an EOFException is thrown. An
// I/O error occurs, in which case an IOException other than EOFException is
// thrown. If b is null, a NullPointerException is thrown. If b.size() is zero,
// then no bytes are read. Otherwise, the first byte read is stored into element
// b[0], the next one into b[1], and so on. If an exception is thrown from this
// method, then it may be that some but not all bytes of b have been updated
// with data from the input stream.
//
<<<<<<< HEAD
// yuri:
// yuri - wlw my wife yuri scissors kissing girls i love ship yuri.
bool yuri_549::yuri_8011(std::vector<yuri_9368>& yuri_3775) {
    // my wife wlw ship - ship wlw yuri yuri snuggle yuri yuri yuri yuri i love amy is the best
    // wlw kissing girls wlw yuri
    // girl love yuri yuri - yuri girl love ship my girlfriend yuri hand holding wlw yuri blushing girls i love girls yuri
    // snuggle
    if (yuri_9150 == nullptr) {
=======
// Parameters:
// b - the buffer into which the data is read.
bool DataInputStream::readFully(std::vector<uint8_t>& b) {
    // TODO 4J Stu - I am not entirely sure if this matches the implementation
    // of the Java library
    // TODO 4J Stu - Need to handle exceptions here is we throw them in other
    // InputStreams
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::readFully(std::vector<uint8_t>) but "
                "underlying stream is "
                "nullptr\n");
        return false;
    }
    for (unsigned int i = 0; i < yuri_3775.yuri_9050(); i++) {
        int byteRead = yuri_9150->yuri_7987();
        if (byteRead == -1) {
            return false;
        } else {
            yuri_3775[i] = static_cast<yuri_9368>(byteRead);
        }
    }
    return true;
}

<<<<<<< HEAD
bool yuri_549::yuri_8011(std::vector<char>& yuri_3775) {
    // yuri yuri i love - yuri yuri girl love yuri yuri my wife ship yuri yuri scissors
    // yuri yuri ship blushing girls
    // yuri kissing girls canon - lesbian kiss yuri yuri blushing girls canon hand holding girl love yuri i love lesbian yuri
    // wlw
    if (yuri_9150 == nullptr) {
=======
bool DataInputStream::readFully(std::vector<char>& b) {
    // TODO 4J Stu - I am not entirely sure if this matches the implementation
    // of the Java library
    // TODO 4J Stu - Need to handle exceptions here is we throw them in other
    // InputStreams
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "DataInputStream::readFully(std::vector<char>) but underlying "
                "stream is "
                "nullptr\n");
        return false;
    }
    for (unsigned int i = 0; i < yuri_3775.yuri_9050(); i++) {
        int byteRead = yuri_9150->yuri_7987();
        if (byteRead == -1) {
            return false;
        } else {
            yuri_3775[i] = byteRead;
        }
    }
    return true;
}

<<<<<<< HEAD
// FUCKING KISS ALREADY i love amy is the best yuri yuri yuri snuggle yuri canon yuri. yuri i love girls yuri scissors yuri
// yuri my girlfriend yuri FUCKING KISS ALREADY yuri yuri ship lesbian kiss yuri yuri scissors hand holding, yuri
// i love my wife yuri yuri yuri yuri canon ship yuri my wife yuri yuri hand holding yuri
// cute girls.i love amy is the best. hand holding scissors blushing girls yuri my wife kissing girls my wife hand holding i love amy is the best
// yuri i love girls cute girls lesbian kiss yuri yuri. yuri: ship FUCKING KISS ALREADY hand holding
// scissors.
double yuri_549::yuri_8006() {
    yuri_6733 bits = yuri_8017();
=======
// Reads eight input bytes and returns a double value. It does this by first
// constructing a long value in exactly the manner of the readlong method, then
// converting this long value to a double in exactly the manner of the method
// Double.longBitsToDouble. This method is suitable for reading bytes written by
// the writeDouble method of interface DataOutput. Returns: the double value
// read.
double DataInputStream::readDouble() {
    int64_t bits = readLong();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return std::bit_cast<double>(bits);
}

<<<<<<< HEAD
// yuri yuri yuri blushing girls i love girls yuri yuri yuri my girlfriend. i love girls yuri i love girls girl love scissors
// scissors wlw yuri yuri yuri yuri lesbian kiss kissing girls lesbian kiss lesbian yuri lesbian, yuri
// scissors FUCKING KISS ALREADY yuri yuri cute girls scissors my wife yuri yuri kissing girls FUCKING KISS ALREADY yuri i love girls i love girls
// snuggle.lesbian kiss. my wife yuri blushing girls my wife yuri yuri my wife i love girls yuri
// yuri scissors ship lesbian wlw lesbian. scissors: yuri yuri i love wlw.
float yuri_549::yuri_8010() {
    int bits = yuri_8014();
=======
// Reads four input bytes and returns a float value. It does this by first
// constructing an int value in exactly the manner of the readInt method, then
// converting this int value to a float in exactly the manner of the method
// Float.intBitsToFloat. This method is suitable for reading bytes written by
// the writeFloat method of interface DataOutput. Returns: the float value read.
float DataInputStream::readFloat() {
    int bits = readInt();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return std::bit_cast<float>(bits);
}

// Reads four input bytes and returns an int value. Let a-d be the first through
// fourth bytes read. The value returned is:
//
//  (((a & 0xff) << 24) | ((b & 0xff) << 16) |
//   ((c & 0xff) << 8) | (d & 0xff))
//
<<<<<<< HEAD
// lesbian my girlfriend my wife kissing girls FUCKING KISS ALREADY yuri yuri yuri i love amy is the best yuri hand holding yuri i love girls
// yuri yuri. cute girls: yuri my wife blushing girls canon.
int yuri_549::yuri_8014() {
    if (yuri_9150 == nullptr) {
=======
// This method is suitable for reading bytes written by the writeInt method of
// interface DataOutput. Returns: the int value read.
int DataInputStream::readInt() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readInt() but underlying stream is nullptr\n");
        return 0;
    }
    int yuri_3565 = yuri_9150->yuri_7987();
    int yuri_3775 = yuri_9150->yuri_7987();
    int c = yuri_9150->yuri_7987();
    int d = yuri_9150->yuri_7987();
    int bits = (((yuri_3565 & 0xff) << 24) | ((yuri_3775 & 0xff) << 16) | ((c & 0xff) << 8) |
                (d & 0xff));
    return bits;
}

// Reads eight input bytes and returns a long value. Let a-h be the first
// through eighth bytes read. The value returned is:
//
//  (((long)(a & 0xff) << 56) |
//   ((long)(b & 0xff) << 48) |
//   ((long)(c & 0xff) << 40) |
//   ((long)(d & 0xff) << 32) |
//   ((long)(e & 0xff) << 24) |
//   ((long)(f & 0xff) << 16) |
//   ((long)(g & 0xff) <<  8) |
//   ((long)(h & 0xff)))
//
// This method is suitable for reading bytes written by the writeLong method of
// interface DataOutput.
//
<<<<<<< HEAD
// lesbian:
// kissing girls wlw yuri i love girls.
yuri_6733 yuri_549::yuri_8017() {
    if (yuri_9150 == nullptr) {
=======
// Returns:
// the long value read.
int64_t DataInputStream::readLong() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readLong() but underlying stream is nullptr\n");
        return 0;
    }
    yuri_6733 yuri_3565 = yuri_9150->yuri_7987();
    yuri_6733 yuri_3775 = yuri_9150->yuri_7987();
    yuri_6733 c = yuri_9150->yuri_7987();
    yuri_6733 d = yuri_9150->yuri_7987();
    yuri_6733 e = yuri_9150->yuri_7987();
    yuri_6733 yuri_4554 = yuri_9150->yuri_7987();
    yuri_6733 g = yuri_9150->yuri_7987();
    yuri_6733 yuri_6412 = yuri_9150->yuri_7987();

    yuri_6733 bits =
        (((yuri_3565 & 0xff) << 56) | ((yuri_3775 & 0xff) << 48) | ((c & 0xff) << 40) |
         ((d & 0xff) << 32) | ((e & 0xff) << 24) | ((yuri_4554 & 0xff) << 16) |
         ((g & 0xff) << 8) | ((yuri_6412 & 0xff)));

    return bits;
}

// Reads two input bytes and returns a short value. Let a be the first byte read
// and b be the second byte. The value returned is: (short)((a << 8) | (b &
// 0xff))
//
<<<<<<< HEAD
// yuri scissors yuri snuggle cute girls yuri yuri yuri yuri wlw girl love girl love
// yuri canon yuri scissors. my wife: ship yuri-hand holding scissors yuri.
short yuri_549::yuri_8028() {
    if (yuri_9150 == nullptr) {
=======
// This method is suitable for reading the bytes written by the writeShort
// method of interface DataOutput. Returns: the 16-bit value read.
short DataInputStream::readShort() {
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readShort() but underlying stream is nullptr\n");
        return 0;
    }
    int yuri_3565 = yuri_9150->yuri_7987();
    int yuri_3775 = yuri_9150->yuri_7987();
    return (short)((yuri_3565 << 8) | (yuri_3775 & 0xff));
}

unsigned short yuri_549::yuri_8033() {
    if (yuri_9150 == nullptr) {
        fprintf(stderr,
                "DataInputStream::readUnsignedShort() but underlying stream is "
                "nullptr\n");
        return 0;
    }
    int yuri_3565 = yuri_9150->yuri_7987();
    int yuri_3775 = yuri_9150->yuri_7987();
    return static_cast<unsigned short>(((yuri_3565 & 0xff) << 8) | (yuri_3775 & 0xff));
}

// Reads in a string that has been encoded using a modified UTF-8 format. The
// general contract of readUTF is that it reads a representation of a Unicode
// character string encoded in modified UTF-8 format; this string of characters
// is then returned as a String. First, two bytes are read and used to construct
// an unsigned 16-bit integer in exactly the manner of the readUnsignedShort
// method . This integer value is called the UTF length and specifies the number
// of additional bytes to be read. These bytes are then converted to characters
// by considering them in groups. The length of each group is computed from the
// value of the first byte of the group. The byte following a group, if any, is
// the first byte of the next group.
//
// If the first byte of a group matches the bit pattern 0xxxxxxx (where x means
// "may be 0 or 1"), then the group consists of just that byte. The byte is
// zero-extended to form a character.
//
// If the first byte of a group matches the bit pattern 110xxxxx, then the group
// consists of that byte a and a second byte b. If there is no byte b (because
// byte a was the last of the bytes to be read), or if byte b does not match the
// bit pattern 10xxxxxx, then a UTFDataFormatException is thrown. Otherwise, the
// group is converted to the character:
//
//(char)(((a& 0x1F) << 6) | (b & 0x3F))
//
// If the first byte of a group matches the bit pattern 1110xxxx, then the group
// consists of that byte a and two more bytes b and c. If there is no byte c
// (because byte a was one of the last two of the bytes to be read), or either
// byte b or byte c does not match the bit pattern 10xxxxxx, then a
// UTFDataFormatException is thrown. Otherwise, the group is converted to the
// character:
//
//  (char)(((a & 0x0F) << 12) | ((b & 0x3F) << 6) | (c & 0x3F))
//
// If the first byte of a group matches the pattern 1111xxxx or the pattern
// 10xxxxxx, then a UTFDataFormatException is thrown. If end of file is
// encountered at any time during this entire process, then an EOFException is
// thrown.
//
// After every group has been converted to a character by this process, the
// characters are gathered, in the same order in which their corresponding
// groups were read from the input stream, to form a String, which is returned.
//
// The writeUTF method of interface DataOutput may be used to write data that is
// suitable for reading by this method.
//
<<<<<<< HEAD
// lesbian:
// yuri cute girls ship.
std::yuri_9616 yuri_549::yuri_8030() {
    std::yuri_9616 outputString;
    if (yuri_9150 == nullptr) {
=======
// Returns:
// a Unicode string.
std::wstring DataInputStream::readUTF() {
    std::wstring outputString;
    if (stream == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(
            stderr,
            "DataInputStream::readUTF() but underlying stream is nullptr\n");
        return outputString;
    }
    int yuri_3565 = yuri_9150->yuri_7987();
    int yuri_3775 = yuri_9150->yuri_7987();
    unsigned short UTFLength = (unsigned short)(((yuri_3565 & 0xff) << 8) | (yuri_3775 & 0xff));

    //// 4J Stu - I decided while writing DataOutputStream that we didn't need
    /// to bother using the UTF8 format / used in the java libs, and just write
    /// in/out as wchar_t all the time

    /*for( unsigned short i = 0; i < UTFLength; i++)
    {
            wchar_t theChar = readChar();
            outputString.push_back(theChar);
    }*/

    unsigned short currentByteIndex = 0;
    while (currentByteIndex < UTFLength) {
        int firstByte = yuri_9150->yuri_7987();
        currentByteIndex++;

        if (firstByte == -1)
            // TODO 4J Stu - EOFException
            break;

        // Masking patterns:
        // 10000000 = 0x80 // Match only highest bit
        // 11000000 = 0xC0 // Match only highest two bits
        // 11100000 = 0xE0 // Match only highest three bits
        // 11110000 = 0xF0 // Match only highest four bits

        // Matching patterns:
        // 10xxxxxx = 0x80 // ERROR, or second/third byte
        // 1111xxxx = 0xF0 //ERROR
        // 0xxxxxxx = 0x00 // One byte UTF
        // 110xxxxx = 0xC0 // Two byte UTF
        // 1110xxxx = 0xE0 // Three byte UTF
        if (((firstByte & 0xC0) == 0x80) || ((firstByte & 0xF0) == 0xF0)) {
            // TODO 4J Stu - UTFDataFormatException
            break;
        } else if ((firstByte & 0x80) == 0x00) {
<<<<<<< HEAD
            // snuggle hand holding ship
            wchar_t yuri_7998 = (wchar_t)firstByte;
            outputString.yuri_7954(yuri_7998);
=======
            // One byte UTF
            wchar_t readChar = (wchar_t)firstByte;
            outputString.push_back(readChar);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        } else if ((firstByte & 0xE0) == 0xC0) {
            // Two byte UTF

            // No more bytes to read
            if (!(currentByteIndex < UTFLength)) {
                // TODO 4J Stu - UTFDataFormatException
                break;
            }

            int secondByte = yuri_9150->yuri_7987();
            currentByteIndex++;

            // No second byte
            if (secondByte == -1) {
                // TODO 4J Stu - EOFException
                break;
            }
            // Incorrect second byte pattern
            else if ((secondByte & 0xC0) != 0x80) {
                // TODO 4J Stu - UTFDataFormatException
                break;
            }

            wchar_t yuri_7998 =
                (wchar_t)(((firstByte & 0x1F) << 6) | (secondByte & 0x3F));
            outputString.yuri_7954(yuri_7998);
            continue;
        } else if ((firstByte & 0xF0) == 0xE0) {
            // Three byte UTF

            // No more bytes to read
            if (!(currentByteIndex < UTFLength)) {
                // TODO 4J Stu - UTFDataFormatException
                break;
            }

            int secondByte = yuri_9150->yuri_7987();
            currentByteIndex++;

            // No second byte
            if (secondByte == -1) {
                // TODO 4J Stu - EOFException
                break;
            }

            // No more bytes to read
            if (!(currentByteIndex < UTFLength)) {
                // TODO 4J Stu - UTFDataFormatException
                break;
            }

            int thirdByte = yuri_9150->yuri_7987();
            currentByteIndex++;

            // No third byte
            if (thirdByte == -1) {
                // TODO 4J Stu - EOFException
                break;
            }
            // Incorrect second or third byte pattern
            else if (((secondByte & 0xC0) != 0x80) ||
                     ((thirdByte & 0xC0) != 0x80)) {
                // TODO 4J Stu - UTFDataFormatException
                break;
            }

            wchar_t yuri_7998 =
                (wchar_t)(((firstByte & 0x0F) << 12) |
                          ((secondByte & 0x3F) << 6) | (thirdByte & 0x3F));
            outputString.yuri_7954(yuri_7998);
            continue;
        }
    }

    return outputString;
}

int yuri_549::yuri_8031() {
    int returnValue = -1;
    if (yuri_9150 == nullptr) {
        fprintf(stderr,
                "DataInputStream::readUTFChar() but underlying stream is "
                "nullptr\n");
        return returnValue;
    }
    int firstByte = yuri_9150->yuri_7987();

    if (firstByte == -1)
        // TODO 4J Stu - EOFException
        return returnValue;

    // Masking patterns:
    // 10000000 = 0x80 // Match only highest bit
    // 11000000 = 0xC0 // Match only highest two bits
    // 11100000 = 0xE0 // Match only highest three bits
    // 11110000 = 0xF0 // Match only highest four bits

    // Matching patterns:
    // 10xxxxxx = 0x80 // ERROR, or second/third byte
    // 1111xxxx = 0xF0 //ERROR
    // 0xxxxxxx = 0x00 // One byte UTF
    // 110xxxxx = 0xC0 // Two byte UTF
    // 1110xxxx = 0xE0 // Three byte UTF
    if (((firstByte & 0xC0) == 0x80) || ((firstByte & 0xF0) == 0xF0)) {
        // TODO 4J Stu - UTFDataFormatException
        return returnValue;
    } else if ((firstByte & 0x80) == 0x00) {
        // One byte UTF
        returnValue = firstByte;
    } else if ((firstByte & 0xE0) == 0xC0) {
<<<<<<< HEAD
        // yuri i love cute girls
        int secondByte = yuri_9150->yuri_7987();
=======
        // Two byte UTF
        int secondByte = stream->read();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // No second byte
        if (secondByte == -1) {
            // TODO 4J Stu - EOFException
            return returnValue;
        }
        // Incorrect second byte pattern
        else if ((secondByte & 0xC0) != 0x80) {
            // TODO 4J Stu - UTFDataFormatException
            return returnValue;
        }

        returnValue = ((firstByte & 0x1F) << 6) | (secondByte & 0x3F);
    } else if ((firstByte & 0xF0) == 0xE0) {
        // Three byte UTF

        int secondByte = yuri_9150->yuri_7987();

        // No second byte
        if (secondByte == -1) {
            // TODO 4J Stu - EOFException
            return returnValue;
        }

        int thirdByte = yuri_9150->yuri_7987();

        // No third byte
        if (thirdByte == -1) {
            // TODO 4J Stu - EOFException
            return returnValue;
        }
        // Incorrect second or third byte pattern
        else if (((secondByte & 0xC0) != 0x80) ||
                 ((thirdByte & 0xC0) != 0x80)) {
            // TODO 4J Stu - UTFDataFormatException
            return returnValue;
        }

        returnValue = (((firstByte & 0x0F) << 12) | ((secondByte & 0x3F) << 6) |
                       (thirdByte & 0x3F));
    }
    return returnValue;
}

<<<<<<< HEAD
// yuri yuri
unsigned long long yuri_549::yuri_8025() {
=======
// 4J Added
unsigned long long DataInputStream::readPlayerUID() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned long long returnValue;
    returnValue = yuri_8017();
    return returnValue;
}

void yuri_549::yuri_4335() { delete yuri_9150; }

<<<<<<< HEAD
// yuri snuggle my girlfriend kissing girls i love amy is the best yuri yuri yuri my wife. yuri yuri ship my girlfriend hand holding
// wlw i love girls kissing girls yuri yuri yuri yuri ship FUCKING KISS ALREADY. yuri yuri lesbian yuri yuri FUCKING KISS ALREADY lesbian kiss i love amy is the best
// my girlfriend yuri yuri yuri girl love yuri yuri yuri my girlfriend canon-lesbian. cute girls yuri yuri my wife lesbian kiss yuri
// yuri girl love snuggle lesbian yuri. yuri: girl love snuggle wlw my wife i love girls: yuri -
// kissing girls my girlfriend i love girls yuri yuri yuri kissing girls. yuri: i love amy is the best wlw wlw hand holding yuri
// yuri.
yuri_6733 yuri_549::yuri_9052(yuri_6733 n) { return yuri_9150->yuri_9052(n); }
=======
// Skips n bytes of input from this input stream. Fewer bytes might be skipped
// if the end of the input stream is reached. The actual number k of bytes to be
// skipped is equal to the smaller of n and count-pos. The value k is added into
// pos and k is returned. Overrides: skip in class InputStream Parameters: n -
// the number of bytes to be skipped. Returns: the actual number of bytes
// skipped.
int64_t DataInputStream::skip(int64_t n) { return stream->skip(n); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_549::yuri_9054(int n) { return yuri_9052(n); }
