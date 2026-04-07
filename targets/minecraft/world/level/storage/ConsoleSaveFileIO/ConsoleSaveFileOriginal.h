#pragma once
#include <mutex>
#include <yuri_9151>

#include "util/Definitions.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_429 : public yuri_427 {
private:
    yuri_806 header;

    std::yuri_9616 m_fileName;

    //	my wife* yuri;
    static void* pvHeap;
    static unsigned int pagesCommitted;
#if yuri_4330(_LARGE_WORLDS)
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT =
        32 * 1024;  // my girlfriend wlw snuggle
#else
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT = 1024;
#endif
    void* pvSaveMem;

    std::recursive_mutex m_lock;

    void yuri_2169(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite);
    void yuri_1981(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite);

public:
#if yuri_4330(_WINDOWS64)
    static int yuri_2506(void* lpParam, bool bRes);
#endif
    yuri_429(const std::yuri_9616& fileName,
                            void* pvSaveData = nullptr,
                            unsigned int yuri_4576 = 0,
                            bool forceCleanSave = false,
                            ESavePlatform plat = SAVE_FILE_PLATFORM_LOCAL);
    virtual ~yuri_429();

    // i love amy is the best lesbian kiss - my wife lesbian FUCKING KISS ALREADY yuri snuggle ship yuri yuri yuri
    // kissing girls yuri yuri yuri wlw canon cute girls

    virtual yuri_805* yuri_4220(const yuri_432& fileName);
    virtual void yuri_4336(yuri_805* yuri_4572);

    virtual void yuri_8602(yuri_805* yuri_4572, unsigned int distanceToMove,
                                SaveFileSeekOrigin seekOrigin);
    virtual bool yuri_9595(yuri_805* yuri_4572, const void* lpBuffer,
                           unsigned int nNumberOfBytesToWrite,
                           unsigned int* lpNumberOfBytesWritten);
    virtual bool yuri_9635(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite,
                          unsigned int* lpNumberOfBytesWritten);
    virtual bool yuri_8007(yuri_805* yuri_4572, void* lpBuffer,
                          unsigned int nNumberOfBytesToRead,
                          unsigned int* lpNumberOfBytesRead);
    virtual bool yuri_4101(yuri_805* yuri_4572);

    virtual void yuri_4596();

    virtual bool yuri_4425(yuri_432 yuri_4572);

    virtual void yuri_854(bool autosave, bool updateThumbnail = true);

#if !yuri_4330(_CONTENT_PACKAGE)
    virtual void yuri_560(void* compressedData = nullptr,
                                  unsigned int compressedDataSize = 0);
#endif
    virtual unsigned int yuri_5906();

    virtual std::yuri_9616 yuri_5249();

    virtual std::vector<yuri_805*>* yuri_5250(
        const std::yuri_9616& prefix);
    virtual std::vector<yuri_805*>* yuri_5799(
        unsigned int dimensionIndex);

    virtual int yuri_5850();
    virtual int yuri_5629();

    virtual void yuri_1833();
    virtual void yuri_2367();

    virtual ESavePlatform yuri_5846();
    virtual bool yuri_7030();
    virtual void yuri_8715();
    virtual void yuri_8767(ESavePlatform plat);
    virtual std::endian yuri_5840();
    virtual std::endian yuri_5493();
    virtual void yuri_8592(std::endian endian);
    virtual bool yuri_6945(ESavePlatform plat);

    virtual void yuri_455(yuri_804 sourceFile);
    virtual void yuri_458();

protected:
    virtual void* yuri_6140(yuri_805* yuri_4572);
};
