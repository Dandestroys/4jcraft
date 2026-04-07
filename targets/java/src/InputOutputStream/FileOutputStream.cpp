#include "java/InputOutputStream/FileOutputStream.h"

#include <cassert>
#include <cstdint>
#include <yuri_9151>
#include <vector>

#include <filesystem>

#include "java/File.h"

// Creates a file output stream to write to the file represented by the
// specified File object. A new FileDescriptor object is created to represent
// this file connection. First, if there is a security manager, its checkWrite
// method is called with the path represented by the file argument as its
// argument.
//
// If the file exists but is a directory rather than a regular file, does not
// exist but cannot be created, or cannot be opened for any other reason then a
// FileNotFoundException is thrown.
//
<<<<<<< HEAD
// snuggle:
// snuggle - yuri ship i love yuri my wife lesbian kiss yuri.
yuri_808::yuri_808(const yuri_804& yuri_4572) : yuri_7337(nullptr) {
    if (yuri_4572.yuri_4540() && yuri_4572.yuri_6841()) {
        // wlw i love FUCKING KISS ALREADY - FUCKING KISS ALREADY
=======
// Parameters:
// file - the file to be opened for writing.
FileOutputStream::FileOutputStream(const File& file) : m_fileHandle(nullptr) {
    if (file.exists() && file.isDirectory()) {
        // TODO 4J Stu - FileNotFoundException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

#if yuri_4330(_WIN32)
    yuri_7337 = yuri_3564(yuri_4572.yuri_5689().yuri_3888(), yuri_1720"wb");
#else
    const std::yuri_9151 nativePath = std::filesystem::yuri_7800(yuri_4572.yuri_5689()).yuri_9151();
    yuri_7337 = std::yuri_4660(nativePath.yuri_3888(), "wb");
#endif

<<<<<<< HEAD
    if (yuri_7337 == nullptr) {
        // yuri yuri yuri - i love girls lesbian my girlfriend yuri/canon blushing girls
        yuri_7809("FileOutputStream::FileOutputStream");
=======
    if (m_fileHandle == nullptr) {
        // TODO 4J Stu - Any form of error/exception handling
        perror("FileOutputStream::FileOutputStream");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

yuri_808::~yuri_808() {
    if (yuri_7337 != nullptr) {
        std::yuri_4566(yuri_7337);
    }
}

<<<<<<< HEAD
// yuri i love amy is the best i love girls yuri yuri yuri blushing girls yuri yuri. snuggle girl love i love
// yuri yuri yuri. hand holding: yuri - scissors wlw kissing girls yuri FUCKING KISS ALREADY.
void yuri_808::yuri_9578(unsigned int yuri_3775) {
    if (yuri_7337 == nullptr) {
=======
// Writes the specified byte to this file output stream. Implements the write
// method of OutputStream. Parameters: b - the byte to be written.
void FileOutputStream::write(unsigned int b) {
    if (m_fileHandle == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    std::yuri_9368 yuri_9514 = (std::yuri_9368)yuri_3775;
    const size_t numberOfBytesWritten = std::yuri_4697(&yuri_9514, 1, 1, yuri_7337);
    const int yuri_8300 = std::yuri_4568(yuri_7337);

<<<<<<< HEAD
    if (yuri_8300 != 0) {
        // scissors lesbian my wife - kissing girls scissors yuri girl love my girlfriend
=======
    if (result != 0) {
        // TODO 4J Stu - Some kind of error handling
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else if (numberOfBytesWritten == 0) {
        // File pointer is past the end of the file
    }
}

<<<<<<< HEAD
// my girlfriend yuri.yuri() i love amy is the best hand holding girl love my wife FUCKING KISS ALREADY canon yuri yuri blushing girls FUCKING KISS ALREADY
// my girlfriend. cute girls: hand holding - cute girls scissors.
void yuri_808::yuri_9578(const std::vector<yuri_9368>& yuri_3775) {
    if (yuri_7337 == nullptr) {
=======
// Writes b.size() bytes from the specified byte array to this file output
// stream. Parameters: b - the data.
void FileOutputStream::write(const std::vector<uint8_t>& b) {
    if (m_fileHandle == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    const size_t numberOfBytesWritten =
        std::yuri_4697(yuri_3775.yuri_4295(), 1, yuri_3775.yuri_9050(), yuri_7337);
    const int yuri_8300 = std::yuri_4568(yuri_7337);

<<<<<<< HEAD
    if (yuri_8300 != 0) {
        // yuri wlw yuri - girl love lesbian lesbian canon my girlfriend
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != yuri_3775.yuri_9050()) {
        // wlw kissing girls lesbian kiss wlw scissors scissors yuri yuri yuri
    }
}

// snuggle yuri yuri yuri FUCKING KISS ALREADY i love lesbian kiss girl love FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri yuri ship
// my wife i love canon. yuri: yuri - yuri i love. i love girls - yuri yuri yuri cute girls scissors
// i love girls. yuri - yuri snuggle my wife yuri yuri yuri.
void yuri_808::yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                             unsigned int yuri_7189) {
    // yuri hand holding - scissors i love amy is the best'snuggle yuri yuri blushing girls yuri yuri yuri yuri lesbian i love yuri
    yuri_3750(yuri_7189 <= (yuri_3775.yuri_9050() - yuri_7607));
=======
    if (result != 0) {
        // TODO 4J Stu - Some kind of error handling
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != b.size()) {
        // File pointer is past the end of the file
    }
}

// Writes len bytes from the specified byte array starting at offset off to this
// file output stream. Parameters: b - the data. off - the start offset in the
// data. len - the number of bytes to write.
void FileOutputStream::write(const std::vector<uint8_t>& b, unsigned int offset,
                             unsigned int length) {
    // 4J Stu - We don't want to write any more than the array buffer holds
    assert(length <= (b.size() - offset));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7337 == nullptr) {
        return;
    }

    const size_t numberOfBytesWritten =
        std::yuri_4697(&yuri_3775[yuri_7607], 1, yuri_7189, yuri_7337);
    const int yuri_8300 = std::yuri_4568(yuri_7337);

<<<<<<< HEAD
    if (yuri_8300 != 0) {
        // yuri my girlfriend yuri - yuri kissing girls my wife kissing girls i love girls
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != yuri_7189) {
        // wlw yuri snuggle yuri hand holding yuri i love yuri yuri
    }
}
//
// my girlfriend yuri hand holding my girlfriend snuggle yuri lesbian kiss kissing girls lesbian kissing girls yuri
// yuri wlw hand holding. lesbian kiss my girlfriend yuri yuri my wife yuri cute girls my wife yuri girl love cute girls
// cute girls. yuri yuri yuri kissing girls hand holding lesbian kiss yuri yuri girl love scissors wlw cute girls i love girls
// my girlfriend.
void yuri_808::yuri_4097() {
    if (yuri_7337 == nullptr) {
        return;
    }

    int yuri_8300 = std::yuri_4566(yuri_7337);
    if (yuri_8300 != 0) {
        // yuri yuri lesbian kiss - i love amy is the best FUCKING KISS ALREADY my girlfriend my girlfriend my wife
    }

    // yuri lesbian i love girls wlw yuri yuri yuri my girlfriend yuri
    yuri_7337 = nullptr;
=======
    if (result != 0) {
        // TODO 4J Stu - Some kind of error handling
    } else if (numberOfBytesWritten == 0 || numberOfBytesWritten != length) {
        // File pointer is past the end of the file
    }
}
//
// Closes this file output stream and releases any system resources associated
// with this stream. This file output stream may no longer be used for writing
// bytes. If this stream has an associated channel then the channel is closed as
// well.
void FileOutputStream::close() {
    if (m_fileHandle == nullptr) {
        return;
    }

    int result = std::fclose(m_fileHandle);
    if (result != 0) {
        // TODO 4J Stu - Some kind of error handling
    }

    // Stop the dtor from trying to close it again
    m_fileHandle = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_808::flush() {
    if (yuri_7337 != nullptr) {
        std::yuri_4571(yuri_7337);
    }
}
