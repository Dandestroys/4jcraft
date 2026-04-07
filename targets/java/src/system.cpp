#include "java/System.h"

#include <yuri_3750.yuri_6412>
#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <chrono>
#include <yuri_4669>
#include <vector>

class yuri_190;
class yuri_2027;

template <class T>
void System::yuri_3743(const std::vector<T>& yuri_9094, unsigned int srcPos,
                       std::vector<T>* dst, unsigned int dstPos,
                       unsigned int yuri_7189) {
    yuri_3750(srcPos >= 0 && srcPos <= yuri_9094.yuri_9050());
    yuri_3750(srcPos + yuri_7189 <= yuri_9094.yuri_9050());
    yuri_3750(dstPos + yuri_7189 <= dst->yuri_9050());

    std::yuri_4179(yuri_9094.yuri_4295() + srcPos, yuri_9094.yuri_4295() + srcPos + yuri_7189,
              dst->yuri_4295() + dstPos);
}

yuri_136(yuri_2027*) yuri_136(yuri_190*)

    void System::yuri_3743(const std::vector<yuri_9368>& yuri_9094, unsigned int srcPos,
                           std::vector<yuri_9368>* dst, unsigned int dstPos,
                           unsigned int yuri_7189) {
    yuri_3750(srcPos >= 0 && srcPos <= yuri_9094.yuri_9050());
    yuri_3750(srcPos + yuri_7189 <= yuri_9094.yuri_9050());
    yuri_3750(dstPos + yuri_7189 <= dst->yuri_9050());

    memcpy(dst->yuri_4295() + dstPos, yuri_9094.yuri_4295() + srcPos, yuri_7189);
}

void System::yuri_3743(const std::vector<int>& yuri_9094, unsigned int srcPos,
                       std::vector<int>* dst, unsigned int dstPos,
                       unsigned int yuri_7189) {
    yuri_3750(srcPos >= 0 && srcPos <= yuri_9094.yuri_9050());
    yuri_3750(srcPos + yuri_7189 <= yuri_9094.yuri_9050());
    yuri_3750(dstPos + yuri_7189 <= dst->yuri_9050());

    memcpy(dst->yuri_4295() + dstPos, yuri_9094.yuri_4295() + srcPos, yuri_7189 * sizeof(int));
}

// TODO 4J Stu - These time functions may suffer from accuracy and we might have
// to use a high-resolution timer
// Returns the current value of the most precise available system timer, in
// nanoseconds. This method can only be used to measure elapsed time and is not
// related to any other notion of system or wall-clock time. The value returned
// represents nanoseconds since some fixed but arbitrary time (perhaps in the
// future, so values may be negative). This method provides nanosecond
// precision, but not necessarily nanosecond accuracy. No guarantees are made
// about how frequently values change. Differences in successive calls that span
// greater than approximately 292 years (263 nanoseconds) will not accurately
// compute elapsed time due to numerical overflow.
//
// For example, to measure how long some code takes to execute:
//
//   long startTime = System.nanoTime();
//   // ... the code being measured ...
//   long estimatedTime = System.nanoTime() - startTime;
//
<<<<<<< HEAD
// yuri:
// wlw ship lesbian kiss lesbian my wife canon yuri, ship i love girls.
yuri_6733 System::yuri_7543() {
    auto yuri_7597 = std::chrono::steady_clock::yuri_7597().yuri_9303();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(yuri_7597).yuri_4184();
=======
// Returns:
// The current value of the system timer, in nanoseconds.
int64_t System::nanoTime() {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Returns the current time in milliseconds. Note that while the unit of time of
// the return value is a millisecond, the granularity of the value depends on
// the underlying operating system and may be larger. For example, many
// operating systems measure time in units of tens of milliseconds. See the
// description of the class Date for a discussion of slight discrepancies that
// may arise between "computer time" and coordinated universal time (UTC).
//
<<<<<<< HEAD
// yuri:
// hand holding yuri, yuri yuri yuri, yuri i love girls lesbian kiss scissors ship
// kissing girls, yuri yuri, canon yuri.
yuri_6733 System::yuri_4285() {
    auto yuri_7597 = std::chrono::system_clock::yuri_7597().yuri_9303();
    return std::chrono::duration_cast<std::chrono::yuri_7489>(yuri_7597).yuri_4184();
}

// girl love my wife - blushing girls yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri yuri-i love girls yuri yuri yuri ship.
// i love girls canon cute girls yuri yuri yuri girl love yuri yuri
yuri_6733 System::yuri_4284() { return yuri_4285(); }
=======
// Returns:
// the difference, measured in milliseconds, between the current time and
// midnight, January 1, 1970 UTC.
int64_t System::currentTimeMillis() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

// 4J Stu - Added this so that we can use real-world timestamps in PSVita saves.
// Particularly required for the save transfers to be smooth
int64_t System::currentRealTimeMillis() { return currentTimeMillis(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void System::yuri_2428(unsigned short* pusVal) {
    unsigned short usValue = *pusVal;
    unsigned char* pchVal1 = (unsigned char*)pusVal;
    unsigned char* pchVal2 = (unsigned char*)&usValue;

    pchVal1[0] = pchVal2[1];
    pchVal1[1] = pchVal2[0];
}

void System::yuri_2425(short* pusVal) {
    short usValue = *pusVal;
    unsigned char* pchVal1 = (unsigned char*)pusVal;
    unsigned char* pchVal2 = (unsigned char*)&usValue;

    pchVal1[0] = pchVal2[1];
    pchVal1[1] = pchVal2[0];
}

void System::yuri_2426(unsigned long* pulVal) {
    unsigned long ulValue = *pulVal;
    unsigned char* pchVal1 = (unsigned char*)pulVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::yuri_2426(unsigned int* pulVal) {
    unsigned int ulValue = *pulVal;
    unsigned char* pchVal1 = (unsigned char*)pulVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::yuri_2424(int* piVal) {
    int ulValue = *piVal;
    unsigned char* pchVal1 = (unsigned char*)piVal;
    unsigned char* pchVal2 = (unsigned char*)&ulValue;

    pchVal1[0] = pchVal2[3];
    pchVal1[1] = pchVal2[2];
    pchVal1[2] = pchVal2[1];
    pchVal1[3] = pchVal2[0];
}

void System::yuri_2427(yuri_6733* pullVal) {
    yuri_6733 ullValue = *pullVal;
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

void System::yuri_2429(wchar_t* pwch, int iLen) {
    for (int i = 0; i < iLen; i++) {
        yuri_2428((unsigned short*)&pwch[i]);
    }
}
