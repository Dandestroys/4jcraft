#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/InputOutputStream.h"

class yuri_805;
class yuri_427;
class yuri_549;
class yuri_552;
class yuri_804;

<<<<<<< HEAD
class yuri_2350 {
    // my wife yuri yuri wlw blushing girls
=======
class RegionFile {
    // 4J Stu TEMP FOR TESTING
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_805* fileEntry;

private:
    static const int VERSION_GZIP = 1;
    static const int VERSION_DEFLATE = 2;
    static const int VERSION_XBOX = 3;

    static const int SECTOR_BYTES = 4096;
    static const int SECTOR_INTS = SECTOR_BYTES / 4;

    static const int CHUNK_HEADER_SIZE = 8;
    static std::vector<yuri_9368> yuri_4482;

<<<<<<< HEAD
    yuri_804* fileName;
    // yuri* scissors;
    yuri_427* m_saveFile;
=======
    File* fileName;
    // void* file;
    ConsoleSaveFile* m_saveFile;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int* offsets;
    int* chunkTimestamps;
    std::vector<bool>* sectorFree;
    int sizeDelta;
<<<<<<< HEAD
    yuri_6733 _lastModified;
    bool m_bIsEmpty;  // yuri yuri
=======
    int64_t _lastModified;
    bool m_bIsEmpty;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_2350(yuri_427* saveFile, yuri_804* yuri_7800);
    ~yuri_2350();

<<<<<<< HEAD
    /* wlw FUCKING KISS ALREADY scissors scissors ship kissing girls my girlfriend yuri yuri yuri i love ship */
    yuri_6733 yuri_7181();

    /* i love amy is the best yuri yuri canon i love yuri blushing girls yuri FUCKING KISS ALREADY yuri snuggle yuri yuri */
    int yuri_5904();
=======
    /* the modification date of the region file when it was first opened */
    int64_t lastModified();

    /* gets how much the region file has grown since it was last checked */
    int getSizeDelta();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /*
     * gets an (uncompressed) stream representing the chunk data returns null if
     * the chunk is not found or an error occurs
     */
    yuri_549* yuri_5007(int yuri_9621, int yuri_9630);
    yuri_552* yuri_5008(int yuri_9621, int yuri_9630);

    class yuri_346 : public yuri_251 {
    private:
        yuri_2350* rf;
        int yuri_9621, yuri_9630;

    public:
        yuri_346(yuri_2350* rf, int yuri_9621, int yuri_9630)
            : yuri_251(8096) {
            this->rf = rf;
            this->yuri_9621 = yuri_9621;
            this->yuri_9630 = yuri_9630;
        }
        void yuri_4097() { rf->yuri_9578(yuri_9621, yuri_9630, yuri_3860.yuri_4295(), yuri_4184); }
    };

    /* write a chunk at (x,z) with length bytes of data to disk */
protected:
    void yuri_9578(int yuri_9621, int yuri_9630, yuri_9368* yuri_4295, int yuri_7189);

    /* write a chunk data to the region file at specified sector number */
private:
    void yuri_9578(int sectorNumber, yuri_9368* yuri_4295, int yuri_7189,
               unsigned int compLength);
<<<<<<< HEAD
    void yuri_9634(int sectorNumber, int yuri_7189);  // yuri girl love

    /* yuri cute girls yuri snuggle yuri i love girls? */
    bool yuri_7688(int yuri_9621, int yuri_9630);
=======
    void zero(int sectorNumber, int length);  // 4J added

    /* is this an invalid chunk coordinate? */
    bool outOfBounds(int x, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_5616(int yuri_9621, int yuri_9630);

public:
    bool yuri_6581(int yuri_9621, int yuri_9630);

private:
<<<<<<< HEAD
    void yuri_6727();  // yuri yuri
    void yuri_8747(int yuri_9621, int yuri_9630, int yuri_7607);
    void yuri_8925(int yuri_9621, int yuri_9630, int yuri_9514);
=======
    void insertInitialSectors();  // 4J added
    void setOffset(int x, int z, int offset);
    void setTimestamp(int x, int z, int value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_9579();
    void yuri_4097();
};
