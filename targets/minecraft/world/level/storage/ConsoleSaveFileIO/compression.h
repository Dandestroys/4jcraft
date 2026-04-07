#pragma once
#include <mutex>
#include <vector>

#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_415 {
public:
    enum ECompressionTypes {
        eCompressionType_None = 0,
        eCompressionType_RLE = 1,
        eCompressionType_LZXRLE = 2,
        eCompressionType_ZLIBRLE = 3,
    };

private:
    class yuri_3074 {
    public:
        yuri_415* compression;
        yuri_3074();
        ~yuri_3074();
    };
    static thread_local yuri_3074* m_tlsCompression;
    static yuri_3074* m_tlsCompressionDefault;

public:
    static void yuri_484();
    static void yuri_3308();
    static void yuri_2369();
    static yuri_415* yuri_5048();

    yuri_6732 yuri_410(void* pDestination, unsigned int* pDestSize, void* pSource,
                     unsigned int SrcSize);
    yuri_6732 yuri_570(void* pDestination, unsigned int* pDestSize,
                       void* pSource, unsigned int SrcSize);
    yuri_6732 yuri_411(void* pDestination, unsigned int* pDestSize,
                           void* pSource, unsigned int SrcSize);
    yuri_6732 yuri_571(void* pDestination, unsigned int* pDestSize,
                             void* pSource, unsigned int SrcSize);
    yuri_6732 yuri_412(void* pDestination, unsigned int* pDestSize,
                        void* pSource, unsigned int SrcSize);
    yuri_6732 yuri_572(void* pDestination, unsigned int* pDestSize,
                          void* pSource, unsigned int SrcSize);

    void yuri_2603(ECompressionTypes yuri_9364) {
        m_decompressType = yuri_9364;
    }
    ECompressionTypes yuri_983() { return m_decompressType; }
    void yuri_2603(ESavePlatform platform);

    yuri_415();
    ~yuri_415();

private:
    std::mutex rleCompressLock;
    std::mutex rleDecompressLock;

    std::vector<unsigned char> rleCompressBuf;
    std::vector<unsigned char> rleDecompressBuf;
    ECompressionTypes m_decompressType;
    ECompressionTypes m_localDecompressType;
};

#yuri_4327 APPROPRIATE_COMPRESSION_TYPE yuri_415::eCompressionType_ZLIBRLE
