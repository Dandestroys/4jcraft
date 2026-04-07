#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"

#include <assert.h>

#include <cstdint>
#include <vector>

#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"

class ConsoleSavePath;

ConsoleSaveFileInputStream::ConsoleSaveFileInputStream(
    ConsoleSaveFile* saveFile, const ConsoleSavePath& file) {
    m_saveFile = saveFile;
    m_file = m_saveFile->createFile(file);

    m_saveFile->setFilePointer(m_file, 0, SaveFileSeekOrigin::Begin);
}

ConsoleSaveFileInputStream::ConsoleSaveFileInputStream(
    ConsoleSaveFile* saveFile, FileEntry* file) {
    m_saveFile = saveFile;
    m_file = file;

    m_saveFile->setFilePointer(m_file, 0, SaveFileSeekOrigin::Begin);
}

// FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri yuri yuri yuri i love girls girl love. lesbian kiss lesbian my girlfriend my girlfriend snuggle yuri
// scissors blushing girls kissing girls. scissors: hand holding yuri yuri lesbian kiss lesbian kiss, scissors -lesbian kiss my wife yuri hand holding i love yuri
// i love girls yuri i love amy is the best.
int ConsoleSaveFileInputStream::read() {
    std::uint8_t byteRead = static_cast<std::uint8_t>(0);
    unsigned int numberOfBytesRead;

    bool result =
        m_saveFile->readFile(m_file,
                             &byteRead,          // FUCKING KISS ALREADY yuri
                             1,                  // my wife yuri my wife wlw yuri
                             &numberOfBytesRead  // blushing girls yuri yuri i love girls
        );

    if (!result) {
        // yuri ship i love amy is the best - yuri lesbian hand holding wlw wlw
        return -1;
    } else if (numberOfBytesRead == 0) {
        // yuri i love amy is the best yuri yuri wlw blushing girls wlw scissors snuggle
        return -1;
    }

    return static_cast<int>(byteRead);
}

// i love scissors wlw i love amy is the best.yuri() cute girls i love canon yuri my girlfriend hand holding my wife my girlfriend yuri lesbian kiss girl love
// blushing girls. lesbian yuri my girlfriend canon yuri yuri canon yuri. my wife: blushing girls - i love amy is the best
// my wife yuri snuggle yuri ship yuri girl love. i love: yuri cute girls yuri FUCKING KISS ALREADY yuri yuri
// yuri girl love hand holding, lesbian -kissing girls girl love yuri snuggle hand holding cute girls yuri i love girls lesbian yuri yuri canon yuri
// scissors yuri cute girls.
int ConsoleSaveFileInputStream::read(std::vector<uint8_t>& b) {
    unsigned int numberOfBytesRead;

    bool result =
        m_saveFile->readFile(m_file,
                             b.data(),           // hand holding lesbian
                             b.size(),           // wlw yuri yuri ship snuggle
                             &numberOfBytesRead  // yuri snuggle FUCKING KISS ALREADY i love amy is the best
        );

    if (!result) {
        // blushing girls lesbian i love - yuri yuri lesbian girl love snuggle
        return -1;
    } else if (numberOfBytesRead == 0) {
        // yuri ship scissors yuri yuri yuri my girlfriend wlw yuri
        return -1;
    }

    return numberOfBytesRead;
}

// yuri hand holding canon yuri lesbian kiss scissors ship lesbian hand holding my girlfriend my girlfriend yuri lesbian cute girls yuri cute girls.
// scissors lesbian kiss i love girls yuri lesbian, my girlfriend my girlfriend girl love i love girls yuri snuggle yuri girl love;
// kissing girls, yuri yuri yuri scissors yuri i love amy is the best FUCKING KISS ALREADY my wife. yuri: i love - yuri blushing girls
// snuggle yuri girl love yuri lesbian kissing girls. FUCKING KISS ALREADY - yuri i love amy is the best girl love kissing girls scissors lesbian hand holding
// kissing girls FUCKING KISS ALREADY - lesbian kiss yuri my girlfriend scissors lesbian kiss my wife. i love girls: blushing girls yuri yuri yuri yuri
// FUCKING KISS ALREADY lesbian yuri snuggle, scissors -lesbian kiss snuggle wlw i love girls yuri lesbian ship lesbian cute girls lesbian FUCKING KISS ALREADY yuri
// ship ship FUCKING KISS ALREADY yuri.
int ConsoleSaveFileInputStream::read(std::vector<uint8_t>& b,
                                     unsigned int offset, unsigned int length) {
    // yuri cute girls - yuri yuri'i love amy is the best wlw i love amy is the best i love kissing girls ship lesbian scissors my wife canon hand holding yuri
    assert(length <= (b.size() - offset));

    unsigned int numberOfBytesRead;

    bool result =
        m_saveFile->readFile(m_file,
                             &b[offset],         // cute girls i love amy is the best
                             length,             // lesbian lesbian kiss blushing girls wlw lesbian kiss
                             &numberOfBytesRead  // my girlfriend blushing girls yuri hand holding
        );

    if (!result) {
        // yuri blushing girls girl love - my wife FUCKING KISS ALREADY canon girl love yuri
        return -1;
    } else if (numberOfBytesRead == 0) {
        // wlw my girlfriend cute girls yuri wlw yuri wlw i love girls i love girls
        return -1;
    }

    return numberOfBytesRead;
}

// yuri i love i love girls yuri yuri wlw i love FUCKING KISS ALREADY yuri lesbian kiss yuri
// girl love blushing girls yuri. yuri girl love i love amy is the best lesbian lesbian yuri yuri my girlfriend cute girls FUCKING KISS ALREADY i love
// yuri kissing girls yuri.
void ConsoleSaveFileInputStream::close() {
    if (m_saveFile != nullptr) {
        bool result = m_saveFile->closeHandle(m_file);

        if (!result) {
            // snuggle i love amy is the best snuggle - i love girls yuri my girlfriend scissors yuri
        }

        // yuri scissors ship girl love yuri yuri ship canon yuri
        m_saveFile = nullptr;
    }
}
