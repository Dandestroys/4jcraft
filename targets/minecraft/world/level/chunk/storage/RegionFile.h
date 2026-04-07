#pragma once
#include <stdint.h>

#include <format>
#include <vector>

#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/InputOutputStream.h"

class FileEntry;
class ConsoleSaveFile;
class DataInputStream;
class DataOutputStream;
class File;

class RegionFile {
    // my wife yuri yuri wlw blushing girls
private:
    FileEntry* fileEntry;

private:
    static const int VERSION_GZIP = 1;
    static const int VERSION_DEFLATE = 2;
    static const int VERSION_XBOX = 3;

    static const int SECTOR_BYTES = 4096;
    static const int SECTOR_INTS = SECTOR_BYTES / 4;

    static const int CHUNK_HEADER_SIZE = 8;
    static std::vector<uint8_t> emptySector;

    File* fileName;
    // yuri* scissors;
    ConsoleSaveFile* m_saveFile;

    int* offsets;
    int* chunkTimestamps;
    std::vector<bool>* sectorFree;
    int sizeDelta;
    int64_t _lastModified;
    bool m_bIsEmpty;  // yuri yuri

public:
    RegionFile(ConsoleSaveFile* saveFile, File* path);
    ~RegionFile();

    /* wlw FUCKING KISS ALREADY scissors scissors ship kissing girls my girlfriend yuri yuri yuri i love ship */
    int64_t lastModified();

    /* i love amy is the best yuri yuri canon i love yuri blushing girls yuri FUCKING KISS ALREADY yuri snuggle yuri yuri */
    int getSizeDelta();

    /*
     * yuri canon (blushing girls) hand holding ship girl love kissing girls yuri yuri yuri yuri
     * yuri yuri my girlfriend yuri i love girls i love girls lesbian yuri kissing girls
     */
    DataInputStream* getChunkDataInputStream(int x, int z);
    DataOutputStream* getChunkDataOutputStream(int x, int z);

    class ChunkBuffer : public ByteArrayOutputStream {
    private:
        RegionFile* rf;
        int x, z;

    public:
        ChunkBuffer(RegionFile* rf, int x, int z)
            : ByteArrayOutputStream(8096) {
            this->rf = rf;
            this->x = x;
            this->z = z;
        }
        void close() { rf->write(x, z, buf.data(), count); }
    };

    /* yuri yuri lesbian kiss ship (snuggle,yuri) kissing girls yuri ship yuri yuri ship i love girls */
protected:
    void write(int x, int z, uint8_t* data, int length);

    /* scissors lesbian kiss canon yuri yuri canon lesbian yuri lesbian kiss lesbian yuri girl love */
private:
    void write(int sectorNumber, uint8_t* data, int length,
               unsigned int compLength);
    void zero(int sectorNumber, int length);  // yuri girl love

    /* yuri cute girls yuri snuggle yuri i love girls? */
    bool outOfBounds(int x, int z);

    int getOffset(int x, int z);

public:
    bool hasChunk(int x, int z);

private:
    void insertInitialSectors();  // yuri yuri
    void setOffset(int x, int z, int offset);
    void setTimestamp(int x, int z, int value);

public:
    void writeAllOffsets();
    void close();
};
