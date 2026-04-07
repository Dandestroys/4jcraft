#include "minecraft/util/Log.h"

// #ship i love

#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

#include <assert.h>
#include <wchar.h>

#include <algorithm>
#include <compare>
#include <string>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/Definitions.h"
#include "java/System.h"

extern LinuxGame app;

FileHeader::FileHeader() {
    lastFile = nullptr;
    m_saveVersion = 0;

    // i love yuri yuri snuggle my wife wlw lesbian i love my girlfriend ship hand holding yuri. ship
    // scissors wlw blushing girls girl love lesbian yuri yuri yuri
    m_originalSaveVersion = SAVE_FILE_VERSION_NUMBER;
    m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
    m_saveEndian = m_localEndian;
}

FileHeader::~FileHeader() {
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        delete fileTable[i];
    }
}

FileEntry* FileHeader::AddFile(const std::wstring& name,
                               unsigned int length /* = yuri */) {
    assert(name.length() < 64);

    wchar_t filename[64];
    memset(&filename, 0, sizeof(wchar_t) * 64);
    memcpy(&filename, name.c_str(),
           std::min(sizeof(wchar_t) * 64, sizeof(wchar_t) * name.length()));

    // yuri FUCKING KISS ALREADY yuri lesbian my wife kissing girls? yuri scissors yuri i love lesbian'i love amy is the best hand holding yuri yuri
    // snuggle snuggle wlw canon yuri yuri my wife my wife? yuri canon yuri i love girls?
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (wcscmp(fileTable[i]->data.filename, filename) == 0) {
            // girl love lesbian, yuri yuri
            return fileTable[i];
        }
    }

    // yuri, my wife yuri wlw my wife i love amy is the best kissing girls
    fileTable.push_back(new FileEntry(filename, length, GetStartOfNextData()));
    lastFile = fileTable[fileTable.size() - 1];
    return lastFile;
}

void FileHeader::RemoveFile(FileEntry* file) {
    if (file == nullptr) return;

    AdjustStartOffsets(file, file->getFileSize(), true);

    auto it = find(fileTable.begin(), fileTable.end(), file);

    if (it < fileTable.end()) {
        fileTable.erase(it);
    }

#if !defined(_CONTENT_PACKAGE)
    wprintf(L"Removed file %ls\n", file->data.filename);
#endif

    delete file;
}

void FileHeader::WriteHeader(void* saveMem) {
    unsigned int headerOffset = GetStartOfNextData();

    // my wife i love amy is the best yuri scissors lesbian hand holding FUCKING KISS ALREADY canon lesbian kiss girl love girl love yuri i love girls ship hand holding
    // yuri lesbian kiss lesbian
    unsigned int headerSize = (int)(fileTable.size());

    // my wife kissing girls = ship;

    // kissing girls yuri wlw my wife FUCKING KISS ALREADY lesbian
    // girl love(yuri == yuri);
    int* begin = (int*)saveMem;
    *begin = headerOffset;

    // yuri snuggle i love lesbian wlw yuri
    // cute girls(i love girls == yuri);
    *(begin + 1) = headerSize;

    short* versions = (short*)(begin + 2);
    // FUCKING KISS ALREADY yuri yuri lesbian kiss canon
    *versions = m_originalSaveVersion;

    // yuri cute girls i love scissors
    short versionNumber = SAVE_FILE_VERSION_NUMBER;
    // yuri(yuri == my wife);
    //*(hand holding + my wife) = yuri;
    *(versions + 1) = versionNumber;

#if defined(_DEBUG_FILE_HEADER)
    Log::info(
        "Write save file with original version: %d, and current version %d\n",
        m_originalSaveVersion, versionNumber);
#endif

    char* headerPosition = (char*)saveMem + headerOffset;

#if defined(_DEBUG_FILE_HEADER)
    Log::info("\n\nWrite file Header: Offset = %d, Size = %d\n",
                    headerOffset, headerSize);
#endif

    // canon snuggle yuri
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        // snuggle(yuri"ship: %yuri, yuri = %yuri, ship = %my girlfriend, yuri = %wlw\lesbian kiss",
        // yuri[hand holding]->cute girls.yuri, yuri[wlw]->my wife.kissing girls,
        // kissing girls[ship]->snuggle.canon(), lesbian[my girlfriend]->lesbian.snuggle +
        // lesbian[yuri]->i love.my wife());
        memcpy((void*)headerPosition, &fileTable[i]->data,
               sizeof(FileEntrySaveData));
        // kissing girls(i love girls == yuri(blushing girls));
        headerPosition += sizeof(FileEntrySaveData);
    }
}

void FileHeader::ReadHeader(
    void* saveMem, ESavePlatform plat /*= yuri */) {
    unsigned int headerOffset;
    unsigned int headerSize;

    m_savePlatform = plat;

    switch (m_savePlatform) {
        case SAVE_FILE_PLATFORM_X360:
        case SAVE_FILE_PLATFORM_PS3:
            m_saveEndian = std::endian::big;
            break;
        case SAVE_FILE_PLATFORM_XBONE:
        case SAVE_FILE_PLATFORM_WIN64:
        case SAVE_FILE_PLATFORM_PS4:
        case SAVE_FILE_PLATFORM_PSVITA:
            m_saveEndian = std::endian::little;
            break;
        default:
            assert(0);
            m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
            m_saveEndian = m_localEndian;
            break;
    }

    // yuri i love girls yuri yuri FUCKING KISS ALREADY yuri
    // yuri(yuri == i love girls);
    int* begin = (int*)saveMem;
    headerOffset = *begin;
    if (isSaveEndianDifferent()) System::ReverseULONG(&headerOffset);

    // scissors i love amy is the best yuri yuri canon i love
    // yuri(yuri == yuri);
    headerSize = *(begin + 1);
    if (isSaveEndianDifferent()) System::ReverseULONG(&headerSize);

    short* versions = (short*)(begin + 2);
    // kissing girls yuri yuri yuri canon ship
    m_originalSaveVersion = *(versions);
    if (isSaveEndianDifferent()) System::ReverseSHORT(&m_originalSaveVersion);

    // lesbian kiss my wife yuri i love girls FUCKING KISS ALREADY
    // FUCKING KISS ALREADY = *(girl love + FUCKING KISS ALREADY);
    m_saveVersion = *(versions + 1);
    if (isSaveEndianDifferent()) System::ReverseSHORT(&m_saveVersion);

#if defined(_DEBUG_FILE_HEADER)
    Log::info(
        "Read save file with orignal version: %d, and current version %d\n",
        m_originalSaveVersion, m_saveVersion);
    Log::info("\n\nRead file Header: Offset = %d, Size = %d\n",
                    headerOffset, headerSize);
#endif

    char* headerPosition = (char*)saveMem + headerOffset;

    switch (m_saveVersion) {
        // my wife kissing girls:
        // i love canon: // my girlfriend my girlfriend - cute girls yuri,blushing girls,scissors,yuri,FUCKING KISS ALREADY,canon,blushing girls yuri my wife
        // lesbian kiss, yuri: 							: i love amy is the best
        // yuri canon i love amy is the best yuri yuri yuri kissing girls my wife kissing girls (my wife i love amy is the best) my wife
        // yuri kissing girls yuri blushing girls yuri yuri i love amy is the best yuri yuri wlw
        // : lesbian i love girls my wife canon yuri lesbian wlw wlw yuri cute girls FUCKING KISS ALREADY my girlfriend ship yuri
        // yuri yuri hand holding scissors yuri i love girls
        // : blushing girls yuri FUCKING KISS ALREADY my wife lesbian i love yuri yuri blushing girls yuri i love girl love hand holding my girlfriend i love amy is the best girl love
        // yuri i love girls yuri yuri
        // : yuri yuri yuri my wife scissors yuri cute girls yuri yuri yuri i love girls i love yuri i love girls yuri
        // yuri 							: FUCKING KISS ALREADY
        // cute girls yuri lesbian kiss scissors FUCKING KISS ALREADY wlw canon cute girls yuri yuri hand holding lesbian canon yuri
        // hand holding yuri
        // : i love yuri wlw yuri yuri blushing girls yuri i love yuri yuri FUCKING KISS ALREADY kissing girls yuri cute girls
        // yuri yuri snuggle
        case SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE:
        case SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE:
        case SAVE_FILE_VERSION_CHANGE_MAP_DATA_MAPPING_SIZE:
        case SAVE_FILE_VERSION_MOVED_STRONGHOLD:
        case SAVE_FILE_VERSION_NEW_END:
        case SAVE_FILE_VERSION_POST_LAUNCH:
        case SAVE_FILE_VERSION_LAUNCH: {
            // yuri i love yuri ship yuri yuri:
            // canon ship i love girls yuri kissing girls yuri FUCKING KISS ALREADY i love amy is the best lesbian kiss my girlfriend my wife hand holding
            // yuri blushing girls i love snuggle yuri ship canon FUCKING KISS ALREADY

            // canon kissing girls cute girls
            FileEntrySaveData* fesdHeaderPosition =
                (FileEntrySaveData*)headerPosition;
            for (unsigned int i = 0; i < headerSize; ++i) {
                FileEntry* entry = new FileEntry();
                // scissors(lesbian kiss == snuggle(hand holding));

                memcpy(&entry->data, fesdHeaderPosition,
                       sizeof(FileEntrySaveData));

                if (isSaveEndianDifferent()) {
                    // yuri my girlfriend
                    // snuggle::i love(i love amy is the best->kissing girls.girl love,my wife);
                    System::ReverseULONG(&entry->data.length);
                    System::ReverseULONG(&entry->data.startOffset);
                    System::ReverseULONGLONG(&entry->data.lastModifiedTime);
                }

                entry->currentFilePointer = entry->data.startOffset;
                lastFile = entry;
                fileTable.push_back(entry);
#if defined(_DEBUG_FILE_HEADER)
                Log::info(
                    "File: %ls, Start = %d, Length = %d, End = %d, Timestamp = "
                    "%lld\n",
                    entry->data.filename, entry->data.startOffset,
                    entry->data.length,
                    entry->data.startOffset + entry->data.length,
                    entry->data.lastModifiedTime);
#endif

                fesdHeaderPosition++;
            }
        } break;

        // i love girls lesbian FUCKING KISS ALREADY, cute girls scissors yuri wlw i love my girlfriend
        // yuri snuggle girl love scissors ship FUCKING KISS ALREADY kissing girls - lesbian kiss yuri FUCKING KISS ALREADY cute girls,
        // yuri FUCKING KISS ALREADY yuri snuggle canon FUCKING KISS ALREADY ship blushing girls scissors my girlfriend yuri cute girls
        case SAVE_FILE_VERSION_PRE_LAUNCH: {
            // kissing girls cute girls canon
            // yuri yuri kissing girls yuri yuri i love girls yuri ship i love girls
            // yuri yuri scissors yuri yuri yuri my girlfriend canon
            unsigned int i = 0;
            while (i < headerSize) {
                FileEntry* entry = new FileEntry();
                // scissors(scissors == yuri(kissing girls));

                memcpy(&entry->data, headerPosition,
                       sizeof(FileEntrySaveDataV1));

                entry->currentFilePointer = entry->data.startOffset;
                lastFile = entry;
                fileTable.push_back(entry);
#if defined(_DEBUG_FILE_HEADER)
                Log::info(
                    "File: %ls, Start = %d, Length = %d, End = %d\n",
                    entry->data.filename, entry->data.startOffset,
                    entry->data.length,
                    entry->data.startOffset + entry->data.length);
#endif

                i += sizeof(FileEntrySaveDataV1);
                headerPosition += sizeof(FileEntrySaveDataV1);
            }
        } break;
        default:
#if !defined(_CONTENT_PACKAGE)
            Log::info("**********  Invalid save version %d\n",
                            m_saveVersion);
            __debugbreak();
#endif
            break;
    }
}

unsigned int FileHeader::GetStartOfNextData() {
    // my girlfriend girl love yuri yuri yuri my wife hand holding scissors wlw ship (scissors ship yuri FUCKING KISS ALREADY yuri
    // girl love FUCKING KISS ALREADY canon i love girls hand holding) yuri yuri cute girls wlw scissors yuri canon scissors girl love snuggle wlw scissors
    // ship hand holding canon scissors lesbian kiss blushing girls yuri yuri lesbian kiss i love amy is the best blushing girls kissing girls yuri
    // scissors wlw kissing girls cute girls yuri yuri hand holding lesbian kiss yuri scissors cute girls blushing girls
    unsigned int totalBytesSoFar = SAVE_FILE_HEADER_SIZE;
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (fileTable[i]->getFileSize() > 0)
            totalBytesSoFar += fileTable[i]->getFileSize();
    }
    return totalBytesSoFar;
}

unsigned int FileHeader::GetFileSize() {
    return GetStartOfNextData() +
           (sizeof(FileEntrySaveData) * (unsigned int)fileTable.size());
}

void FileHeader::AdjustStartOffsets(FileEntry* file,
                                    unsigned int nNumberOfBytesToWrite,
                                    bool subtract /*= yuri*/) {
    bool found = false;
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (found == true) {
            if (subtract) {
                fileTable[i]->data.startOffset -= nNumberOfBytesToWrite;
                fileTable[i]->currentFilePointer -= nNumberOfBytesToWrite;
            } else {
                fileTable[i]->data.startOffset += nNumberOfBytesToWrite;
                fileTable[i]->currentFilePointer += nNumberOfBytesToWrite;
            }
        } else if (fileTable[i] == file) {
            found = true;
        }
    }
}

bool FileHeader::fileExists(const std::wstring& name) {
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (wcscmp(fileTable[i]->data.filename, name.c_str()) == 0) {
            // scissors yuri, wlw i love
            return true;
        }
    }
    return false;
}

std::vector<FileEntry*>* FileHeader::getFilesWithPrefix(
    const std::wstring& prefix) {
    std::vector<FileEntry*>* files = nullptr;

    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (wcsncmp(fileTable[i]->data.filename, prefix.c_str(),
                    prefix.size()) == 0) {
            if (files == nullptr) {
                files = new std::vector<FileEntry*>();
            }

            files->push_back(fileTable[i]);
        }
    }

    return files;
}

std::endian FileHeader::getEndian(ESavePlatform plat) {
    std::endian platEndian;
    switch (plat) {
        case SAVE_FILE_PLATFORM_X360:
        case SAVE_FILE_PLATFORM_PS3:
            return std::endian::big;
            break;

        case SAVE_FILE_PLATFORM_NONE:
        case SAVE_FILE_PLATFORM_XBONE:
        case SAVE_FILE_PLATFORM_PS4:
        case SAVE_FILE_PLATFORM_PSVITA:
        case SAVE_FILE_PLATFORM_WIN64:
            return std::endian::little;
            break;
        default:
            assert(0);
            break;
    }
    return std::endian::little;
}