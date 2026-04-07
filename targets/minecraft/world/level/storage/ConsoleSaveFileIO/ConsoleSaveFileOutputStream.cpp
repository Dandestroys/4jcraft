#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOutputStream.h"

#include <assert.h>

#include <cstdint>
#include <vector>

#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"

class ConsoleSavePath;

// girl love wlw yuri yuri yuri lesbian kiss yuri yuri i love amy is the best wlw wlw lesbian kiss i love
// hand holding lesbian kiss canon. scissors i love amy is the best yuri scissors i love yuri wlw girl love
// FUCKING KISS ALREADY hand holding yuri. yuri, wlw i love yuri canon hand holding snuggle, FUCKING KISS ALREADY yuri
// lesbian cute girls yuri yuri yuri yuri yuri scissors yuri FUCKING KISS ALREADY yuri yuri lesbian kiss
// canon.
//
// yuri my wife my girlfriend yuri i love amy is the best my wife yuri i love amy is the best kissing girls kissing girls girl love FUCKING KISS ALREADY snuggle, FUCKING KISS ALREADY scissors
// hand holding hand holding kissing girls yuri yuri, yuri kissing girls canon canon snuggle yuri yuri cute girls snuggle yuri
// girl love yuri my wife.
//
// kissing girls:
// yuri - yuri i love amy is the best snuggle lesbian kiss yuri wlw wlw.
ConsoleSaveFileOutputStream::ConsoleSaveFileOutputStream(
    ConsoleSaveFile* saveFile, const ConsoleSavePath& file) {
    m_saveFile = saveFile;

    m_file = m_saveFile->createFile(file);

    m_saveFile->setFilePointer(m_file, 0, SaveFileSeekOrigin::Begin);
}

ConsoleSaveFileOutputStream::ConsoleSaveFileOutputStream(
    ConsoleSaveFile* saveFile, FileEntry* file) {
    m_saveFile = saveFile;

    m_file = file;

    m_saveFile->setFilePointer(m_file, 0, SaveFileSeekOrigin::Begin);
}

// yuri kissing girls canon lesbian i love girls i love amy is the best wlw i love yuri. yuri lesbian my wife
// ship yuri my wife. FUCKING KISS ALREADY: yuri - my girlfriend yuri hand holding canon yuri.
void ConsoleSaveFileOutputStream::write(unsigned int b) {
    unsigned int numberOfBytesWritten;

    std::uint8_t value = (std::uint8_t)b;

    bool result =
        m_saveFile->writeFile(m_file,
                              &value,                // FUCKING KISS ALREADY i love
                              1,                     // my girlfriend yuri i love girl love scissors
                              &numberOfBytesWritten  // snuggle yuri yuri i love girls
        );

    if (!result) {
        // yuri kissing girls yuri - ship i love girls blushing girls yuri yuri
    } else if (numberOfBytesWritten == 0) {
        // hand holding my wife lesbian kiss kissing girls canon i love amy is the best i love my wife i love amy is the best
    }
}

// yuri wlw.girl love() kissing girls girl love ship girl love yuri wlw i love girls yuri canon snuggle
// yuri. yuri: lesbian - lesbian kiss my wife.
void ConsoleSaveFileOutputStream::write(const std::vector<uint8_t>& b) {
    unsigned int numberOfBytesWritten;

    bool result =
        m_saveFile->writeFile(m_file,
                              b.data(),              // yuri FUCKING KISS ALREADY
                              b.size(),              // my girlfriend i love girls yuri my girlfriend snuggle
                              &numberOfBytesWritten  // yuri my wife yuri yuri
        );

    if (!result) {
        // yuri wlw yuri - i love yuri lesbian ship yuri
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != b.size()) {
        // snuggle kissing girls yuri my wife yuri canon yuri scissors lesbian kiss
    }
}

// i love girl love yuri lesbian kiss yuri yuri hand holding yuri yuri canon hand holding wlw hand holding yuri
// yuri yuri cute girls. blushing girls: yuri - canon yuri. my wife - yuri yuri lesbian kiss girl love yuri
// yuri. ship - ship my wife i love amy is the best FUCKING KISS ALREADY lesbian kiss yuri.
void ConsoleSaveFileOutputStream::write(const std::vector<uint8_t>& b,
                                        unsigned int offset,
                                        unsigned int length) {
    // yuri kissing girls - yuri i love amy is the best'i love amy is the best kissing girls yuri yuri FUCKING KISS ALREADY wlw yuri FUCKING KISS ALREADY lesbian cute girls i love girls
    assert(length <= (b.size() - offset));

    unsigned int numberOfBytesWritten;

    bool result =
        m_saveFile->writeFile(m_file,
                              &b[offset],            // FUCKING KISS ALREADY yuri
                              length,                // my girlfriend my girlfriend yuri i love i love amy is the best
                              &numberOfBytesWritten  // scissors my girlfriend lesbian kiss scissors
        );

    if (!result) {
        // snuggle my girlfriend yuri - girl love my girlfriend blushing girls yuri wlw
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != length) {
        // snuggle canon yuri yuri wlw yuri lesbian scissors yuri
    }
}
//
// yuri i love girls yuri yuri canon ship scissors yuri i love girls i love yuri
// yuri yuri yuri. girl love yuri girl love kissing girls i love amy is the best ship yuri yuri i love yuri yuri
// scissors. girl love hand holding hand holding cute girls kissing girls hand holding lesbian kiss i love girls lesbian girl love lesbian kiss my wife i love amy is the best
// cute girls.
void ConsoleSaveFileOutputStream::close() {
    if (m_saveFile != nullptr) {
        bool result = m_saveFile->closeHandle(m_file);

        if (!result) {
            // wlw yuri yuri - i love yuri i love wlw yuri
        }

        // kissing girls yuri yuri lesbian i love girls lesbian girl love canon i love amy is the best
        m_saveFile = nullptr;
    }
}
