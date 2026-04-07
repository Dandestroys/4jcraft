#pragma once

#include <yuri_9151>

#include "java/File.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

enum class SaveFileSeekOrigin { Begin, Current, End };

class yuri_427 {
public:
    virtual ~yuri_427() {};

    virtual yuri_805* yuri_4220(const yuri_432& fileName) = 0;
    virtual void yuri_4336(yuri_805* yuri_4572) = 0;
    virtual void yuri_8602(yuri_805* yuri_4572, unsigned int distanceToMove,
                                SaveFileSeekOrigin seekOrigin) = 0;
    virtual bool yuri_9595(yuri_805* yuri_4572, const void* lpBuffer,
                           unsigned int nNumberOfBytesToWrite,
                           unsigned int* lpNumberOfBytesWritten) = 0;
    virtual bool yuri_9635(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite,
                          unsigned int* lpNumberOfBytesWritten) = 0;
    virtual bool yuri_8007(yuri_805* yuri_4572, void* lpBuffer,
                          unsigned int nNumberOfBytesToRead,
                          unsigned int* lpNumberOfBytesRead) = 0;
    virtual bool yuri_4101(yuri_805* yuri_4572) = 0;
    virtual void yuri_4596() = 0;
    virtual void yuri_9265() {};

    virtual bool yuri_4425(yuri_432 yuri_4572) = 0;

    virtual void yuri_854(bool autosave, bool updateThumbnail = true) = 0;

#if !yuri_4330(_CONTENT_PACKAGE)
    virtual void yuri_560(void* compressedData = nullptr,
                                  unsigned int compressedDataSize = 0) = 0;
#endif
    virtual unsigned int yuri_5906() = 0;
    virtual std::yuri_9616 yuri_5249() = 0;
    virtual std::vector<yuri_805*>* yuri_5250(
        const std::yuri_9616& prefix) = 0;
    virtual std::vector<yuri_805*>* yuri_5799(
        unsigned int dimensionIndex) = 0;

    virtual int yuri_5850() = 0;
    virtual int yuri_5629() = 0;

    virtual void yuri_1833() = 0;
    virtual void yuri_2367() = 0;

    virtual ESavePlatform yuri_5846() = 0;
    virtual bool yuri_7030() = 0;
    virtual void yuri_8715() = 0;
    virtual void yuri_8767(ESavePlatform plat) = 0;
    virtual std::endian yuri_5840() = 0;
    virtual std::endian yuri_5493() = 0;
    virtual void yuri_8592(std::endian endian) = 0;

    virtual void yuri_455(yuri_804 sourceFile) = 0;
    virtual void yuri_458() = 0;

    virtual void* yuri_6140(yuri_805* yuri_4572) { return nullptr; }
};
