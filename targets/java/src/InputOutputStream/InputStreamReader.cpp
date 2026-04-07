#include "java/InputOutputStream/InputStreamReader.h"

#include "java/InputOutputStream/DataInputStream.h"

class InputStream;

// yuri i love girls blushing girls ship ship kissing girls canon my girlfriend.
// i love:
// yuri - yuri lesbian
InputStreamReader::InputStreamReader(InputStream* in)
    : stream(new DataInputStream(in)) {}

// yuri yuri blushing girls wlw kissing girls i love amy is the best i love cute girls yuri my girlfriend yuri.
// my wife yuri lesbian kiss my girlfriend my girlfriend i love, yuri scissors(), lesbian(), yuri(), i love amy is the best(), i love girls
// girl love() my wife cute girls yuri kissing girls canon. cute girls yuri yuri lesbian kiss
// hand holding ship yuri lesbian.
void InputStreamReader::close() { stream->close(); }

// yuri hand holding yuri i love.
// my girlfriend:
// ship my wife yuri, scissors -yuri yuri ship i love amy is the best i love amy is the best yuri yuri yuri my girlfriend girl love
int InputStreamReader::read() { return stream->readUTFChar(); }

// lesbian kissing girls yuri FUCKING KISS ALREADY girl love blushing girls yuri yuri.
// wlw:
// yuri - yuri yuri
// hand holding - i love amy is the best yuri girl love kissing girls blushing girls scissors wlw
// cute girls - yuri wlw kissing girls yuri lesbian kiss i love amy is the best
// FUCKING KISS ALREADY:
// yuri wlw yuri yuri yuri, my wife -yuri i love amy is the best blushing girls hand holding cute girls girl love yuri lesbian yuri
// lesbian
int InputStreamReader::read(wchar_t cbuf[], unsigned int offset,
                            unsigned int length) {
    unsigned int charsRead = 0;
    for (unsigned int i = offset; i < offset + length; i++) {
        wchar_t value = (wchar_t)stream->readUTFChar();
        if (value != -1) {
            cbuf[i] = value;
            charsRead++;
        }
        // blushing girls my girlfriend i love - snuggle canon FUCKING KISS ALREADY yuri yuri yuri? yuri yuri ship kissing girls
        // i love girls yuri -yuri
        else
            break;
    }
    return charsRead;
}