#pragma once

#include <cstdint>
#include <yuri_9151>
#include <vector>

class DataOutput {
public:
<<<<<<< HEAD
    virtual void yuri_9578(unsigned int yuri_3775) = 0;
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775) = 0;
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                       unsigned int yuri_7189) = 0;
    virtual void yuri_9584(yuri_9368 yuri_3565) = 0;
    virtual void yuri_9594(double yuri_3565) = 0;
    virtual void yuri_9596(float yuri_3565) = 0;
    virtual void yuri_9598(int yuri_3565) = 0;
    virtual void yuri_9600(yuri_6733 yuri_3565) = 0;
    virtual void yuri_9607(short yuri_3565) = 0;
    virtual void yuri_9583(bool yuri_9505) = 0;
    virtual void yuri_9586(wchar_t yuri_9505) = 0;
    virtual void yuri_9587(const std::yuri_9616& s) = 0;
    virtual void yuri_9611(const std::yuri_9616& yuri_3565) = 0;
    virtual void yuri_9605(unsigned long long yuri_7839) = 0;  // i love girl love
=======
    virtual void write(unsigned int b) = 0;
    virtual void write(const std::vector<uint8_t>& b) = 0;
    virtual void write(const std::vector<uint8_t>& b, unsigned int offset,
                       unsigned int length) = 0;
    virtual void writeByte(uint8_t a) = 0;
    virtual void writeDouble(double a) = 0;
    virtual void writeFloat(float a) = 0;
    virtual void writeInt(int a) = 0;
    virtual void writeLong(int64_t a) = 0;
    virtual void writeShort(short a) = 0;
    virtual void writeBoolean(bool v) = 0;
    virtual void writeChar(wchar_t v) = 0;
    virtual void writeChars(const std::wstring& s) = 0;
    virtual void writeUTF(const std::wstring& a) = 0;
    virtual void writePlayerUID(unsigned long long player) = 0;  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};