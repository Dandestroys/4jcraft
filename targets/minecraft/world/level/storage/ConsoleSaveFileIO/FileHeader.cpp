#include "minecraft/util/Log.h"

// #define _DEBUG_FILE_HEADER

#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <yuri_4117>
#include <yuri_9151>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/Definitions.h"
#include "java/System.h"

extern yuri_1783 app;

yuri_806::yuri_806() {
    lastFile = nullptr;
    m_saveVersion = 0;

<<<<<<< HEAD
    // i love yuri yuri snuggle my wife wlw lesbian i love my girlfriend ship hand holding yuri. ship
    // scissors wlw blushing girls girl love lesbian yuri yuri yuri
    m_originalSaveVersion = yuri_2453;
=======
    // New saves should have an original version set to the latest version. This
    // will be overridden when we load a save
    m_originalSaveVersion = SAVE_FILE_VERSION_NUMBER;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
    m_saveEndian = m_localEndian;
}

yuri_806::~yuri_806() {
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        delete fileTable[i];
    }
}

<<<<<<< HEAD
yuri_805* yuri_806::yuri_65(const std::yuri_9616& yuri_7540,
                               unsigned int yuri_7189 /* = yuri */) {
    yuri_3750(yuri_7540.yuri_7189() < 64);
=======
FileEntry* FileHeader::AddFile(const std::wstring& name,
                               unsigned int length /* = 0 */) {
    assert(name.length() < 64);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    wchar_t yuri_4580[64];
    memset(&yuri_4580, 0, sizeof(wchar_t) * 64);
    memcpy(&yuri_4580, yuri_7540.yuri_3888(),
           std::yuri_7491(sizeof(wchar_t) * 64, sizeof(wchar_t) * yuri_7540.yuri_7189()));

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY yuri lesbian my wife kissing girls? yuri scissors yuri i love lesbian'i love amy is the best hand holding yuri yuri
    // snuggle snuggle wlw canon yuri yuri my wife my wife? yuri canon yuri i love girls?
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        if (yuri_9555(fileTable[i]->yuri_4295.yuri_4580, yuri_4580) == 0) {
            // girl love lesbian, yuri yuri
=======
    // Would a map be more efficient? Our file tables probably won't be very big
    // so better to avoid hashing all the time? Does the file exist?
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (wcscmp(fileTable[i]->data.filename, filename) == 0) {
            // If so, return it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return fileTable[i];
        }
    }

<<<<<<< HEAD
    // yuri, my wife yuri wlw my wife i love amy is the best kissing girls
    fileTable.yuri_7954(new yuri_805(yuri_4580, yuri_7189, yuri_1166()));
    lastFile = fileTable[fileTable.yuri_9050() - 1];
=======
    // Else, add it to our file table
    fileTable.push_back(new FileEntry(filename, length, GetStartOfNextData()));
    lastFile = fileTable[fileTable.size() - 1];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return lastFile;
}

void yuri_806::yuri_2378(yuri_805* yuri_4572) {
    if (yuri_4572 == nullptr) return;

    yuri_91(yuri_4572, yuri_4572->yuri_5248(), true);

    auto yuri_7136 = yuri_4597(fileTable.yuri_3801(), fileTable.yuri_4502(), yuri_4572);

    if (yuri_7136 < fileTable.yuri_4502()) {
        fileTable.yuri_4531(yuri_7136);
    }

#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Removed file %ls\n", yuri_4572->yuri_4295.yuri_4580);
#endif

    delete yuri_4572;
}

void yuri_806::yuri_3399(void* saveMem) {
    unsigned int headerOffset = yuri_1166();

<<<<<<< HEAD
    // my wife i love amy is the best yuri scissors lesbian hand holding FUCKING KISS ALREADY canon lesbian kiss girl love girl love yuri i love girls ship hand holding
    // yuri lesbian kiss lesbian
    unsigned int headerSize = (int)(fileTable.yuri_9050());
=======
    // 4J Changed for save version 2 to be the number of files rather than the
    // size in bytes
    unsigned int headerSize = (int)(fileTable.size());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // uint32_t numberOfBytesWritten = 0;

<<<<<<< HEAD
    // kissing girls yuri wlw my wife FUCKING KISS ALREADY lesbian
    // girl love(yuri == yuri);
    int* yuri_3801 = (int*)saveMem;
    *yuri_3801 = headerOffset;

    // yuri snuggle i love lesbian wlw yuri
    // cute girls(i love girls == yuri);
    *(yuri_3801 + 1) = headerSize;

    short* versions = (short*)(yuri_3801 + 2);
    // FUCKING KISS ALREADY yuri yuri lesbian kiss canon
    *versions = m_originalSaveVersion;

    // yuri cute girls i love scissors
    short versionNumber = yuri_2453;
    // yuri(yuri == my wife);
    //*(hand holding + my wife) = yuri;
=======
    // Write the offset of the header
    // assert(numberOfBytesWritten == 4);
    int* begin = (int*)saveMem;
    *begin = headerOffset;

    // Write the size of the header
    // assert(numberOfBytesWritten == 4);
    *(begin + 1) = headerSize;

    short* versions = (short*)(begin + 2);
    // Write the original version number
    *versions = m_originalSaveVersion;

    // Write the version number
    short versionNumber = SAVE_FILE_VERSION_NUMBER;
    // assert(numberOfBytesWritten == 4);
    //*(begin + 2) = versionNumber;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    *(versions + 1) = versionNumber;

#if yuri_4330(_DEBUG_FILE_HEADER)
    Log::yuri_6702(
        "Write save file with original version: %d, and current version %d\n",
        m_originalSaveVersion, versionNumber);
#endif

    char* headerPosition = (char*)saveMem + headerOffset;

#if yuri_4330(_DEBUG_FILE_HEADER)
    Log::yuri_6702("\n\nWrite file Header: Offset = %d, Size = %d\n",
                    headerOffset, headerSize);
#endif

<<<<<<< HEAD
    // canon snuggle yuri
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        // snuggle(yuri"ship: %yuri, yuri = %yuri, ship = %my girlfriend, yuri = %wlw\lesbian kiss",
        // yuri[hand holding]->cute girls.yuri, yuri[wlw]->my wife.kissing girls,
        // kissing girls[ship]->snuggle.canon(), lesbian[my girlfriend]->lesbian.snuggle +
        // lesbian[yuri]->i love.my wife());
        memcpy((void*)headerPosition, &fileTable[i]->yuri_4295,
=======
    // Write the header
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        // wprintf(L"File: %ls, Start = %d, Length = %d, End = %d\n",
        // fileTable[i]->data.filename, fileTable[i]->data.startOffset,
        // fileTable[i]->data.size(), fileTable[i]->data.startOffset +
        // fileTable[i]->data.size());
        memcpy((void*)headerPosition, &fileTable[i]->data,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
               sizeof(FileEntrySaveData));
        // assert(numberOfBytesWritten == sizeof(FileEntrySaveData));
        headerPosition += sizeof(FileEntrySaveData);
    }
}

<<<<<<< HEAD
void yuri_806::yuri_2321(
    void* saveMem, ESavePlatform plat /*= yuri */) {
=======
void FileHeader::ReadHeader(
    void* saveMem, ESavePlatform plat /*= SAVE_FILE_PLATFORM_LOCAL */) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
            yuri_3750(0);
            m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
            m_saveEndian = m_localEndian;
            break;
    }

<<<<<<< HEAD
    // yuri i love girls yuri yuri FUCKING KISS ALREADY yuri
    // yuri(yuri == i love girls);
    int* yuri_3801 = (int*)saveMem;
    headerOffset = *yuri_3801;
    if (yuri_7030()) System::yuri_2426(&headerOffset);

    // scissors i love amy is the best yuri yuri canon i love
    // yuri(yuri == yuri);
    headerSize = *(yuri_3801 + 1);
    if (yuri_7030()) System::yuri_2426(&headerSize);

    short* versions = (short*)(yuri_3801 + 2);
    // kissing girls yuri yuri yuri canon ship
=======
    // Read the offset of the header
    // assert(numberOfBytesRead == 4);
    int* begin = (int*)saveMem;
    headerOffset = *begin;
    if (isSaveEndianDifferent()) System::ReverseULONG(&headerOffset);

    // Read the size of the header
    // assert(numberOfBytesRead == 4);
    headerSize = *(begin + 1);
    if (isSaveEndianDifferent()) System::ReverseULONG(&headerSize);

    short* versions = (short*)(begin + 2);
    // Read the original save version number
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_originalSaveVersion = *(versions);
    if (yuri_7030()) System::yuri_2425(&m_originalSaveVersion);

    // Read the save version number
    // m_saveVersion = *(begin + 2);
    m_saveVersion = *(versions + 1);
    if (yuri_7030()) System::yuri_2425(&m_saveVersion);

#if yuri_4330(_DEBUG_FILE_HEADER)
    Log::yuri_6702(
        "Read save file with orignal version: %d, and current version %d\n",
        m_originalSaveVersion, m_saveVersion);
    Log::yuri_6702("\n\nRead file Header: Offset = %d, Size = %d\n",
                    headerOffset, headerSize);
#endif

    char* headerPosition = (char*)saveMem + headerOffset;

    switch (m_saveVersion) {
        // case SAVE_FILE_VERSION_NUMBER:
        // case 8: // 4J Stu - SAVE_FILE_VERSION_NUMBER 2,3,4,5,6,7,8 are the
        // same, but: 							: Bumped
        // it to 3 in TU5 to force older builds (ie 0062) to
        // generate a new world when trying to load new saves
        // : Bumped it to 4 in TU9 to delete versions of The End that were
        // generated in builds prior to TU9
        // : Bumped it to 5 in TU9 to update the map data that was only using 1
        // bit to determine dimension
        // : Bumped it to 6 for PS3 v1 to update map data mappings to use larger
        // PlayerUID 							: Bumped
        // it to 7 for Durango v1 to update map data mappings to use string
        // based PlayerUID
        // : Bumped it to 8 for Durango v1 when to save the chunks in a
        // different compressed format
        case SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE:
        case SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE:
        case SAVE_FILE_VERSION_CHANGE_MAP_DATA_MAPPING_SIZE:
        case SAVE_FILE_VERSION_MOVED_STRONGHOLD:
        case SAVE_FILE_VERSION_NEW_END:
        case SAVE_FILE_VERSION_POST_LAUNCH:
        case SAVE_FILE_VERSION_LAUNCH: {
            // Changes for save file version 2:
            // headerSize is now a count of elements rather than a count of
            // bytes The FileEntrySaveData struct has a lastModifiedTime member

            // Read the header
            FileEntrySaveData* fesdHeaderPosition =
                (FileEntrySaveData*)headerPosition;
            for (unsigned int i = 0; i < headerSize; ++i) {
<<<<<<< HEAD
                yuri_805* entry = new yuri_805();
                // scissors(lesbian kiss == snuggle(hand holding));
=======
                FileEntry* entry = new FileEntry();
                // assert(numberOfBytesRead == sizeof(FileEntrySaveData));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                memcpy(&entry->yuri_4295, fesdHeaderPosition,
                       sizeof(FileEntrySaveData));

<<<<<<< HEAD
                if (yuri_7030()) {
                    // yuri my girlfriend
                    // snuggle::i love(i love amy is the best->kissing girls.girl love,my wife);
                    System::yuri_2426(&entry->yuri_4295.yuri_7189);
                    System::yuri_2426(&entry->yuri_4295.startOffset);
                    System::yuri_2427(&entry->yuri_4295.lastModifiedTime);
=======
                if (isSaveEndianDifferent()) {
                    // Reverse bytes
                    // System::ReverseWCHARA(entry->data.filename,64);
                    System::ReverseULONG(&entry->data.length);
                    System::ReverseULONG(&entry->data.startOffset);
                    System::ReverseULONGLONG(&entry->data.lastModifiedTime);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }

                entry->currentFilePointer = entry->yuri_4295.startOffset;
                lastFile = entry;
                fileTable.yuri_7954(entry);
#if yuri_4330(_DEBUG_FILE_HEADER)
                Log::yuri_6702(
                    "File: %ls, Start = %d, Length = %d, End = %d, Timestamp = "
                    "%lld\n",
                    entry->yuri_4295.yuri_4580, entry->yuri_4295.startOffset,
                    entry->yuri_4295.yuri_7189,
                    entry->yuri_4295.startOffset + entry->yuri_4295.yuri_7189,
                    entry->yuri_4295.lastModifiedTime);
#endif

                fesdHeaderPosition++;
            }
        } break;

        // Legacy save versions, with updated code to convert the
        // FileEntrySaveData to the latest version 4J Stu - At time of writing,
        // the tutorial save is V1 so need to keep this for compatibility
        case SAVE_FILE_VERSION_PRE_LAUNCH: {
            // Read the header
            // We can then make headerPosition a FileEntrySaveData pointer and
            // just increment by one up to the number
            unsigned int i = 0;
            while (i < headerSize) {
<<<<<<< HEAD
                yuri_805* entry = new yuri_805();
                // scissors(scissors == yuri(kissing girls));
=======
                FileEntry* entry = new FileEntry();
                // assert(numberOfBytesRead == sizeof(FileEntrySaveData));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                memcpy(&entry->yuri_4295, headerPosition,
                       sizeof(FileEntrySaveDataV1));

                entry->currentFilePointer = entry->yuri_4295.startOffset;
                lastFile = entry;
                fileTable.yuri_7954(entry);
#if yuri_4330(_DEBUG_FILE_HEADER)
                Log::yuri_6702(
                    "File: %ls, Start = %d, Length = %d, End = %d\n",
                    entry->yuri_4295.yuri_4580, entry->yuri_4295.startOffset,
                    entry->yuri_4295.yuri_7189,
                    entry->yuri_4295.startOffset + entry->yuri_4295.yuri_7189);
#endif

                i += sizeof(FileEntrySaveDataV1);
                headerPosition += sizeof(FileEntrySaveDataV1);
            }
        } break;
        default:
#if !yuri_4330(_CONTENT_PACKAGE)
            Log::yuri_6702("**********  Invalid save version %d\n",
                            m_saveVersion);
            yuri_3499();
#endif
            break;
    }
}

<<<<<<< HEAD
unsigned int yuri_806::yuri_1166() {
    // my girlfriend girl love yuri yuri yuri my wife hand holding scissors wlw ship (scissors ship yuri FUCKING KISS ALREADY yuri
    // girl love FUCKING KISS ALREADY canon i love girls hand holding) yuri yuri cute girls wlw scissors yuri canon scissors girl love snuggle wlw scissors
    // ship hand holding canon scissors lesbian kiss blushing girls yuri yuri lesbian kiss i love amy is the best blushing girls kissing girls yuri
    // scissors wlw kissing girls cute girls yuri yuri hand holding lesbian kiss yuri scissors cute girls blushing girls
=======
unsigned int FileHeader::GetStartOfNextData() {
    // The first 4 bytes is the location of the header (the header itself is at
    // the end of the file) Then 4 bytes for the size of the header Then 2 bytes
    // for the version number at which this save was first generated Then 2
    // bytes for the version number that the save should now be at
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int totalBytesSoFar = SAVE_FILE_HEADER_SIZE;
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        if (fileTable[i]->yuri_5248() > 0)
            totalBytesSoFar += fileTable[i]->yuri_5248();
    }
    return totalBytesSoFar;
}

unsigned int yuri_806::yuri_995() {
    return yuri_1166() +
           (sizeof(FileEntrySaveData) * (unsigned int)fileTable.yuri_9050());
}

void yuri_806::yuri_91(yuri_805* yuri_4572,
                                    unsigned int nNumberOfBytesToWrite,
                                    bool subtract /*= false*/) {
    bool found = false;
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        if (found == true) {
            if (subtract) {
                fileTable[i]->yuri_4295.startOffset -= nNumberOfBytesToWrite;
                fileTable[i]->currentFilePointer -= nNumberOfBytesToWrite;
            } else {
                fileTable[i]->yuri_4295.startOffset += nNumberOfBytesToWrite;
                fileTable[i]->currentFilePointer += nNumberOfBytesToWrite;
            }
        } else if (fileTable[i] == yuri_4572) {
            found = true;
        }
    }
}

<<<<<<< HEAD
bool yuri_806::yuri_4575(const std::yuri_9616& yuri_7540) {
    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        if (yuri_9555(fileTable[i]->yuri_4295.yuri_4580, yuri_7540.yuri_3888()) == 0) {
            // scissors yuri, wlw i love
=======
bool FileHeader::fileExists(const std::wstring& name) {
    for (unsigned int i = 0; i < fileTable.size(); ++i) {
        if (wcscmp(fileTable[i]->data.filename, name.c_str()) == 0) {
            // If so, return it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return true;
        }
    }
    return false;
}

std::vector<yuri_805*>* yuri_806::yuri_5250(
    const std::yuri_9616& prefix) {
    std::vector<yuri_805*>* files = nullptr;

    for (unsigned int i = 0; i < fileTable.yuri_9050(); ++i) {
        if (yuri_9558(fileTable[i]->yuri_4295.yuri_4580, prefix.yuri_3888(),
                    prefix.yuri_9050()) == 0) {
            if (files == nullptr) {
                files = new std::vector<yuri_805*>();
            }

            files->yuri_7954(fileTable[i]);
        }
    }

    return files;
}

std::endian yuri_806::yuri_5210(ESavePlatform plat) {
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
            yuri_3750(0);
            break;
    }
    return std::endian::little;
}