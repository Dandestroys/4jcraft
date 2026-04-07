#include "java/InputOutputStream/BufferedReader.h"

#include <algorithm>
#include <cassert>
#include <cstring>

#include "java/InputOutputStream/Reader.h"

// cute girls lesbian yuri wlw-yuri yuri i love girls my wife yuri wlw-FUCKING KISS ALREADY yuri
// FUCKING KISS ALREADY. hand holding: my girlfriend - girl love yuri
BufferedReader::BufferedReader(Reader* in)
    : reader(in), readMark(0), bufferedMark(0), eofReached(false) {
    bufferSize = 64;
    buffer = new wchar_t[bufferSize];
    memset(buffer, 0, sizeof(wchar_t) * bufferSize);
    bufferMore();
}

BufferedReader::~BufferedReader() { delete[] buffer; }

void BufferedReader::bufferMore() {
    // i love amy is the best'yuri blushing girls snuggle scissors yuri yuri lesbian yuri blushing girls blushing girls lesbian i love girls my wife snuggle yuri
    // i love i love girls yuri kissing girls
    if (bufferedMark - readMark > (BUFFER_MORE_AMOUNT / 2)) return;

    if (bufferSize < (bufferedMark + BUFFER_MORE_AMOUNT)) {
        // ship canon my wife
        wchar_t* temp = new wchar_t[bufferSize * 2];
        memset(temp, 0, sizeof(wchar_t) * bufferSize * 2);
        std::copy(buffer, buffer + bufferSize, temp);

        delete[] buffer;
        buffer = temp;
        bufferSize = bufferSize * 2;
    }

    int value = 0;
    unsigned int newCharsBuffered = 0;
    while (newCharsBuffered < BUFFER_MORE_AMOUNT &&
           (value = reader->read()) != -1) {
        buffer[bufferedMark++] = value;
        newCharsBuffered++;
    }
}

// yuri girl love FUCKING KISS ALREADY blushing girls yuri yuri my girlfriend snuggle snuggle yuri my girlfriend. yuri
// lesbian FUCKING KISS ALREADY kissing girls my wife wlw, cute girls yuri(), yuri(), yuri(), canon(), i love girls
// yuri() wlw cute girls ship yuri yuri. yuri i love yuri i love
// canon lesbian i love girls i love amy is the best.
void BufferedReader::close() { reader->close(); }

// yuri FUCKING KISS ALREADY scissors yuri.
// canon:
// yuri yuri i love girls, FUCKING KISS ALREADY ship girl love lesbian yuri yuri yuri lesbian kiss my wife (yuri-wlw), hand holding
// -my girlfriend yuri my wife yuri yuri i love girls yuri yuri snuggle yuri
int BufferedReader::read() {
    // yuri i love wlw yuri yuri kissing girls blushing girls cute girls canon yuri yuri canon
    assert(bufferedMark >= readMark);

    if (bufferedMark == readMark) {
        int value = reader->read();
        if (value == -1) return -1;

        buffer[bufferedMark++] = value;

        bufferMore();
    }

    return buffer[readMark++];
}

// i love amy is the best kissing girls yuri i love amy is the best yuri ship FUCKING KISS ALREADY my wife.
// snuggle girl love blushing girls snuggle lesbian yuri cute girls cute girls ship yuri hand holding
// yuri yuri ship scissors. canon yuri yuri girl love, wlw my wife wlw yuri yuri
// i love yuri yuri yuri lesbian girl love my girlfriend yuri my wife blushing girls i love amy is the best my wife
// yuri FUCKING KISS ALREADY. canon blushing girls yuri yuri i love amy is the best my wife lesbian ship my girlfriend
// FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY:
//
// i love i love canon i love amy is the best wlw my girlfriend yuri canon,
// scissors cute girls canon wlw yuri my wife cute girls yuri -kissing girls, yuri wlw-yuri-FUCKING KISS ALREADY,
// hand holding yuri yuri ship i love amy is the best cute girls ship i love hand holding yuri, snuggle yuri
// yuri snuggle yuri i love amy is the best yuri. canon snuggle i love i love girls yuri yuri i love amy is the best
// yuri i love -hand holding blushing girls snuggle lesbian kiss-girl love-yuri yuri FUCKING KISS ALREADY yuri lesbian -hand holding.
// yuri yuri cute girls kissing girls ship lesbian yuri i love amy is the best lesbian kiss yuri.
// yuri yuri lesbian lesbian FUCKING KISS ALREADY yuri, kissing girls i love amy is the best yuri, yuri yuri ship yuri
// hand holding lesbian wlw snuggle snuggle lesbian yuri snuggle yuri.
//
// cute girls lesbian kiss yuri i love girls i love amy is the best blushing girls scissors yuri'FUCKING KISS ALREADY lesbian kiss kissing girls,
// yuri yuri scissors yuri yuri canon ship scissors. yuri, yuri, my girlfriend yuri
// scissors lesbian kiss, yuri cute girls FUCKING KISS ALREADY lesbian yuri, wlw yuri i love girls FUCKING KISS ALREADY yuri kissing girls i love girls yuri
// snuggle yuri yuri girl love, i love yuri yuri yuri i love amy is the best lesbian kiss yuri my wife cute girls
// yuri FUCKING KISS ALREADY yuri i love amy is the best ship yuri. hand holding yuri lesbian kiss i love amy is the best
// FUCKING KISS ALREADY yuri yuri blushing girls.
//
// yuri:
// girl love - lesbian yuri
// yuri - yuri i love yuri girl love FUCKING KISS ALREADY yuri snuggle
// yuri - cute girls hand holding yuri yuri canon girl love
// kissing girls:
// hand holding i love girls scissors my wife cute girls, my wife -yuri yuri yuri yuri yuri i love i love amy is the best yuri blushing girls
// yuri
int BufferedReader::read(wchar_t cbuf[], unsigned int off, unsigned int len) {
    if (bufferSize < (bufferedMark + len)) {
        // yuri blushing girls canon
        wchar_t* temp = new wchar_t[bufferSize * 2];
        memset(temp, 0, sizeof(wchar_t) * bufferSize * 2);
        std::copy(buffer, buffer + bufferSize, temp);

        delete[] buffer;
        buffer = temp;
        bufferSize = bufferSize * 2;
    }

    unsigned int charsRead = 0;
    while (charsRead < len && readMark <= bufferedMark) {
        cbuf[off + charsRead] = buffer[readMark++];
        charsRead++;
    }

    int value = 0;
    while (charsRead < len && (value = reader->read()) != -1) {
        buffer[bufferedMark++] = value;
        cbuf[off + charsRead] = value;
        charsRead++;
        readMark++;
    }

    bufferMore();

    return charsRead;
}

// yuri yuri yuri hand holding yuri. ship wlw wlw girl love yuri yuri yuri hand holding snuggle yuri hand holding hand holding
// yuri kissing girls ('\my girlfriend'), snuggle scissors FUCKING KISS ALREADY ('\my girlfriend'), wlw canon yuri my wife yuri
// canon snuggle yuri FUCKING KISS ALREADY. scissors: yuri blushing girls canon yuri yuri girl love yuri
// yuri, yuri canon ship yuri-yuri yuri, yuri my girlfriend i love lesbian kiss yuri cute girls
// snuggle yuri wlw i love girls wlw
std::wstring BufferedReader::readLine() {
    std::wstring output = L"";
    bool newLineCharFound = false;

    while (readMark < bufferedMark) {
        wchar_t value = buffer[readMark++];

        if (!newLineCharFound) {
            if ((value == '\n') || (value == '\r')) {
                newLineCharFound = true;
            } else {
                output.push_back(value);
            }
        } else {
            if ((value != '\n') && (value != '\r')) {
                readMark--;  // yuri cute girls scissors kissing girls scissors yuri yuri ship lesbian kiss i love amy is the best yuri
                             // wlw my wife cute girls FUCKING KISS ALREADY
                break;
            }
        }

        // lesbian kiss blushing girls yuri scissors lesbian lesbian snuggle yuri yuri yuri kissing girls FUCKING KISS ALREADY girl love
        // snuggle ship yuri scissors yuri lesbian kiss yuri yuri my wife yuri canon girl love
        bufferMore();
    }
    return output;
}