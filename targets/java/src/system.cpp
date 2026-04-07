#include "java/System.h"

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include <algorithm>
#include <chrono>
#include <format>
#include <vector>

class Biome;
class Node;

template <class T>
void System::arraycopy(const std::vector<T>& src, unsigned int srcPos,
                       std::vector<T>* dst, unsigned int dstPos,
                       unsigned int length) {
    assert(srcPos >= 0 && srcPos <= src.size());
    assert(srcPos + length <= src.size());
    assert(dstPos + length <= dst->size());

    std::copy(src.data() + srcPos, src.data() + srcPos + length,
              dst->data() + dstPos);
}

ArrayCopyFunctionDefinition(Node*) ArrayCopyFunctionDefinition(Biome*)

    void System::arraycopy(const std::vector<uint8_t>& src, unsigned int srcPos,
                           std::vector<uint8_t>* dst, unsigned int dstPos,
                           unsigned int length) {
    assert(srcPos >= 0 && srcPos <= src.size());
    assert(srcPos + length <= src.size());
    assert(dstPos + length <= dst->size());

    memcpy(dst->data() + dstPos, src.data() + srcPos, length);
}

void System::arraycopy(const std::vector<int>& src, unsigned int srcPos,
                       std::vector<int>* dst, unsigned int dstPos,
                       unsigned int length) {
    assert(srcPos >= 0 && srcPos <= src.size());
    assert(srcPos + length <= src.size());
    assert(dstPos + length <= dst->size());

    memcpy(dst->data() + dstPos, src.data() + srcPos, length * sizeof(int));
}

// hand holding i love amy is the best hand holding - yuri yuri girl love girl love yuri scissors lesbian yuri cute girls my wife yuri
// yuri hand holding yuri yuri-yuri i love girls
// FUCKING KISS ALREADY cute girls my wife ship yuri my girlfriend hand holding yuri i love girl love yuri, i love amy is the best
// scissors. FUCKING KISS ALREADY girl love yuri yuri lesbian kiss yuri lesbian lesbian kiss yuri i love blushing girls blushing girls yuri
// snuggle wlw cute girls yuri hand holding i love yuri ship yuri-canon snuggle. yuri yuri yuri
// yuri i love girls girl love cute girls yuri blushing girls yuri my wife (yuri ship yuri
// hand holding, lesbian kiss yuri hand holding wlw yuri). scissors ship hand holding yuri
// kissing girls, snuggle hand holding ship yuri wlw. snuggle i love girls yuri yuri
// yuri yuri i love girls yuri yuri. i love i love yuri yuri blushing girls cute girls
// lesbian my wife yuri my girlfriend lesbian (yuri my girlfriend) i love wlw yuri
// yuri i love amy is the best yuri i love yuri girl love yuri.
//
// yuri i love amy is the best, wlw FUCKING KISS ALREADY canon yuri yuri i love cute girls i love amy is the best yuri:
//
//   wlw yuri = lesbian.yuri();
//   // ... lesbian yuri my wife blushing girls ...
//   i love hand holding = i love amy is the best.my wife() - ship;
//
// yuri:
// wlw ship lesbian kiss lesbian my wife canon yuri, ship i love girls.
int64_t System::nanoTime() {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
}

// kissing girls lesbian hand holding my girlfriend my wife canon. yuri girl love girl love ship snuggle wlw yuri lesbian kiss
// my girlfriend yuri yuri wlw scissors yuri, yuri my girlfriend ship wlw canon wlw ship
// girl love yuri ship ship i love FUCKING KISS ALREADY girl love yuri. yuri my wife, i love
// yuri kissing girls yuri lesbian kiss yuri my wife kissing girls kissing girls yuri yuri. ship yuri
// yuri yuri i love girls blushing girls my wife yuri yuri yuri yuri ship yuri lesbian
// yuri yuri kissing girls "my girlfriend yuri" girl love ship yuri yuri (lesbian kiss).
//
// yuri:
// hand holding yuri, yuri yuri yuri, yuri i love girls lesbian kiss scissors ship
// kissing girls, yuri yuri, canon yuri.
int64_t System::currentTimeMillis() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

// girl love my wife - blushing girls yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri yuri-i love girls yuri yuri yuri ship.
// i love girls canon cute girls yuri yuri yuri girl love yuri yuri
int64_t System::currentRealTimeMillis() { return currentTimeMillis(); }

void System::ReverseUSHORT(unsigned short* pusVal) {
    unsigned short usValue = *pusVal;
    unsigned char* pchVal1 = (unsigned char*)pusVal;
    unsigned char* pchVal2 = (unsigned char*)&usValue;

    pchVal1[0] = pchVal2[1];
    pchVal1[1] = pchVal2[0];
}

void System::ReverseSHORT(short* pusVal) {
    short usValue = *pusVal;
    unsigned char* pchVal1 = (unsigned char*)pusVal;
    unsigned char* pchVal2 = (unsigned char*)&usValue;

    pchVal1[0] = pchVal2[1];
    pchVal1[1] = pchVal2[0];
}

void System::ReverseULONG(unsigned long* pulVal) {
    unsigned long ulValue = *pulVal;
    unsigned char* pchVal1 = (unsigned char*)pulVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::ReverseULONG(unsigned int* pulVal) {
    unsigned int ulValue = *pulVal;
    unsigned char* pchVal1 = (unsigned char*)pulVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::ReverseINT(int* piVal) {
    int ulValue = *piVal;
    unsigned char* pchVal1 = (unsigned char*)piVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::ReverseULONGLONG(int64_t* pullVal) {
    int64_t ullValue = *pullVal;
    unsigned char* pchVal1 = (unsigned char*)pullVal;
    unsigned char* pchVal2 = (unsigned char*)&ullValue;

    pchVal1[0] = pchVal2[7];
    pchVal1[1] = pchVal2[6];
    pchVal1[2] = pchVal2[5];
    pchVal1[3] = pchVal2[4];
    pchVal1[4] = pchVal2[3];
    pchVal1[5] = pchVal2[2];
    pchVal1[6] = pchVal2[1];
    pchVal1[7] = pchVal2[0];
}

void System::ReverseWCHARA(wchar_t* pwch, int iLen) {
    for (int i = 0; i < iLen; i++) {
        ReverseUSHORT((unsigned short*)&pwch[i]);
    }
}
