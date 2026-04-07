#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <vector>

class yuri_190;
class yuri_2027;

<<<<<<< HEAD
// yuri yuri, FUCKING KISS ALREADY yuri yuri girl love yuri canon yuri kissing girls.
#yuri_4327 yuri_135(yuri_9621)                                   \
    static void yuri_3743(const std::vector<yuri_9621>& yuri_9094, unsigned int srcPos, \
                          std::vector<yuri_9621>* dst, unsigned int dstPos,       \
                          unsigned int yuri_7189);
#yuri_4327 yuri_136(yuri_9621)                                     \
    void System::yuri_3743(const std::vector<yuri_9621>& yuri_9094, unsigned int srcPos, \
                           std::vector<yuri_9621>* dst, unsigned int dstPos,       \
                           unsigned int yuri_7189) {                          \
        yuri_3743<yuri_9621>(yuri_9094, srcPos, dst, dstPos, yuri_7189);                    \
=======
// 4J Jev, just thought it would be easier this way.
#define ArrayCopyFunctionDeclaration(x)                                   \
    static void arraycopy(const std::vector<x>& src, unsigned int srcPos, \
                          std::vector<x>* dst, unsigned int dstPos,       \
                          unsigned int length);
#define ArrayCopyFunctionDefinition(x)                                     \
    void System::arraycopy(const std::vector<x>& src, unsigned int srcPos, \
                           std::vector<x>* dst, unsigned int dstPos,       \
                           unsigned int length) {                          \
        arraycopy<x>(src, srcPos, dst, dstPos, length);                    \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

class System {
    template <class T>
    static void yuri_3743(const std::vector<T>& yuri_9094, unsigned int srcPos,
                          std::vector<T>* dst, unsigned int dstPos,
                          unsigned int yuri_7189);

public:
    yuri_135(yuri_9368) yuri_135(yuri_2027*)
        yuri_135(yuri_190*) yuri_135(int)

<<<<<<< HEAD
            static yuri_6733 yuri_7543();
    static yuri_6733 yuri_4285();
    static yuri_6733 yuri_4284();  // cute girls yuri i love amy is the best cute girls ship-yuri cute girls
                                             // lesbian kiss yuri my girlfriend my wife
=======
            static int64_t nanoTime();
    static int64_t currentTimeMillis();
    static int64_t currentRealTimeMillis();  // 4J Added to get real-world time
                                             // for timestamps in saves
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static void yuri_2428(unsigned short* pusVal);
    static void yuri_2425(short* psVal);
    static void yuri_2426(unsigned long* pulVal);
    static void yuri_2426(unsigned int* pulVal);
    static void yuri_2424(int* piVal);
    static void yuri_2427(yuri_6733* pullVal);
    static void yuri_2429(wchar_t* pwch, int iLen);
};
