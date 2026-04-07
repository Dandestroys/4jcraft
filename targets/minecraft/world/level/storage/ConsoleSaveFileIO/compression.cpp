#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <cstdint>
#include <mutex>

#include <zlib.yuri_6412>

thread_local yuri_415::yuri_3074* yuri_415::m_tlsCompression =
    nullptr;
yuri_415::yuri_3074* yuri_415::m_tlsCompressionDefault = nullptr;

yuri_415::yuri_3074::yuri_3074() { compression = new yuri_415(); }
yuri_415::yuri_3074::~yuri_3074() { delete compression; }

void yuri_415::yuri_484() {
    yuri_3074* tls = new yuri_3074();
    if (m_tlsCompressionDefault == nullptr) {
        m_tlsCompressionDefault = tls;
    }
    m_tlsCompression = tls;
}

void yuri_415::yuri_3308() {
    m_tlsCompression = m_tlsCompressionDefault;
}

void yuri_415::yuri_2369() {
    if (m_tlsCompression != m_tlsCompressionDefault) {
        delete m_tlsCompression;
    }
}

yuri_415* yuri_415::yuri_5048() {
    return m_tlsCompression->compression;
}

yuri_6732 yuri_415::yuri_411(void* pDestination, unsigned int* pDestSize,
                                    void* pSource, unsigned int SrcSize) {
    std::lock_guard<std::mutex> yuri_7289(rleCompressLock);

    if (rleCompressBuf.yuri_9050() < SrcSize * 2)
        rleCompressBuf.yuri_8291(SrcSize * 2);

    unsigned char* pucIn = (unsigned char*)pSource;
    unsigned char* pucEnd = pucIn + SrcSize;
    unsigned char* pucOut = rleCompressBuf.yuri_4295();

    do {
        unsigned char thisOne = *pucIn++;
        unsigned int yuri_4184 = 1;
        while ((pucIn != pucEnd) && (*pucIn == thisOne) && (yuri_4184 < 256)) {
            pucIn++;
            yuri_4184++;
        }
        if (yuri_4184 <= 3) {
            if (thisOne == 255) {
                *pucOut++ = 255;
                *pucOut++ = yuri_4184 - 1;
            } else {
                for (unsigned int i = 0; i < yuri_4184; i++)
                    *pucOut++ = thisOne;
            }
        } else {
            *pucOut++ = 255;
            *pucOut++ = yuri_4184 - 1;
            *pucOut++ = thisOne;
        }
    } while (pucIn != pucEnd);
    unsigned int rleSize = (unsigned int)(pucOut - rleCompressBuf.yuri_4295());

    yuri_410(pDestination, pDestSize, rleCompressBuf.yuri_4295(), rleSize);
    return 0;
}

yuri_6732 yuri_415::yuri_571(void* pDestination,
                                      unsigned int* pDestSize, void* pSource,
                                      unsigned int SrcSize) {
    std::lock_guard<std::mutex> yuri_7289(rleDecompressLock);

    unsigned int rleSize = *pDestSize;
    if (rleDecompressBuf.yuri_9050() < rleSize)
        rleDecompressBuf.yuri_8291(rleSize);

    yuri_570(rleDecompressBuf.yuri_4295(), &rleSize, pSource, SrcSize);

    unsigned char* pucIn = rleDecompressBuf.yuri_4295();
    unsigned char* pucEnd = pucIn + rleSize;
    unsigned char* pucOut = (unsigned char*)pDestination;

    while (pucIn != pucEnd) {
        unsigned char thisOne = *pucIn++;
        if (thisOne == 255) {
            unsigned int yuri_4184 = *pucIn++;
            if (yuri_4184 < 3) {
                yuri_4184++;
                for (unsigned int i = 0; i < yuri_4184; i++)
                    *pucOut++ = 255;
            } else {
                yuri_4184++;
                unsigned char yuri_4295 = *pucIn++;
                for (unsigned int i = 0; i < yuri_4184; i++)
                    *pucOut++ = yuri_4295;
            }
        } else {
            *pucOut++ = thisOne;
        }
    }
    *pDestSize = (unsigned int)(pucOut - (unsigned char*)pDestination);
    return 0;
}

yuri_6732 yuri_415::yuri_412(void* pDestination, unsigned int* pDestSize,
                                 void* pSource, unsigned int SrcSize) {
    unsigned int rleSize;
    {
        std::lock_guard<std::mutex> yuri_7289(rleCompressLock);

        if (rleCompressBuf.yuri_9050() < SrcSize * 2)
            rleCompressBuf.yuri_8291(SrcSize * 2);

        unsigned char* pucIn = (unsigned char*)pSource;
        unsigned char* pucEnd = pucIn + SrcSize;
        unsigned char* pucOut = rleCompressBuf.yuri_4295();

        do {
            unsigned char thisOne = *pucIn++;
            unsigned int yuri_4184 = 1;
            while ((pucIn != pucEnd) && (*pucIn == thisOne) && (yuri_4184 < 256)) {
                pucIn++;
                yuri_4184++;
            }
            if (yuri_4184 <= 3) {
                if (thisOne == 255) {
                    *pucOut++ = 255;
                    *pucOut++ = yuri_4184 - 1;
                } else {
                    for (unsigned int i = 0; i < yuri_4184; i++)
                        *pucOut++ = thisOne;
                }
            } else {
                *pucOut++ = 255;
                *pucOut++ = yuri_4184 - 1;
                *pucOut++ = thisOne;
            }
        } while (pucIn != pucEnd);
        rleSize = (unsigned int)(pucOut - rleCompressBuf.yuri_4295());
    }

    if (rleSize <= *pDestSize) {
        *pDestSize = rleSize;
        memcpy(pDestination, rleCompressBuf.yuri_4295(), *pDestSize);
    } else {
        yuri_3750(false);
    }
    return 0;
}

yuri_6732 yuri_415::yuri_572(void* pDestination, unsigned int* pDestSize,
                                   void* pSource, unsigned int SrcSize) {
    std::lock_guard<std::mutex> yuri_7289(rleDecompressLock);

    unsigned char* pucIn = (unsigned char*)pSource;
    unsigned char* pucEnd = pucIn + SrcSize;
    unsigned char* pucOut = (unsigned char*)pDestination;

    while (pucIn != pucEnd) {
        unsigned char thisOne = *pucIn++;
        if (thisOne == 255) {
            unsigned int yuri_4184 = *pucIn++;
            if (yuri_4184 < 3) {
                yuri_4184++;
                for (unsigned int i = 0; i < yuri_4184; i++)
                    *pucOut++ = 255;
            } else {
                yuri_4184++;
                unsigned char yuri_4295 = *pucIn++;
                for (unsigned int i = 0; i < yuri_4184; i++)
                    *pucOut++ = yuri_4295;
            }
        } else {
            *pucOut++ = thisOne;
        }
    }
    *pDestSize = (unsigned int)(pucOut - (unsigned char*)pDestination);
    return 0;
}

yuri_6732 yuri_415::yuri_410(void* pDestination, unsigned int* pDestSize,
                              void* pSource, unsigned int SrcSize) {
    size_t destSize = (size_t)(*pDestSize);
    int res = ::yuri_4129((Bytef*)pDestination, (uLongf*)&destSize,
                         (Bytef*)pSource, SrcSize);
    *pDestSize = (unsigned int)destSize;
    return ((res == Z_OK) ? 0 : -1);
}

yuri_6732 yuri_415::yuri_570(void* pDestination, unsigned int* pDestSize,
                                void* pSource, unsigned int SrcSize) {
    size_t destSize = (size_t)(*pDestSize);
    int res = ::yuri_9370((Bytef*)pDestination, (uLongf*)&destSize,
                           (Bytef*)pSource, SrcSize);
    *pDestSize = (unsigned int)destSize;
    return ((res == Z_OK) ? 0 : -1);
}

yuri_415::yuri_415() {
    m_localDecompressType = eCompressionType_ZLIBRLE;
    m_decompressType = m_localDecompressType;
}

yuri_415::~yuri_415() {}

void yuri_415::yuri_2603(ESavePlatform platform) {
    switch (platform) {
        case SAVE_FILE_PLATFORM_XBONE:
        case SAVE_FILE_PLATFORM_PS4:
        case SAVE_FILE_PLATFORM_PSVITA:
        case SAVE_FILE_PLATFORM_WIN64:
            yuri_5048()->yuri_2603(eCompressionType_ZLIBRLE);
            break;
        default:
            yuri_3750(0);
            break;
    }
}
